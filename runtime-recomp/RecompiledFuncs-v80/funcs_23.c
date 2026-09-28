#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void menu_geometry_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080E6C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80080E70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080E74: addiu       $v0, $v0, 0x1DB4
    ctx->r2 = ADD32(ctx->r2, 0X1DB4);
    // 0x80080E78: sw          $zero, 0x1DB8($at)
    MEM_W(0X1DB8, ctx->r1) = 0;
    // 0x80080E7C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80080E80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80080E84: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80080E88: jr          $ra
    // 0x80080E8C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x80080E8C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void mempool_print_tags_screen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071B54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071B5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071B64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80071B68: jal         0x800B62B4
    // 0x80071B6C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_render_printf_background_colour(rdram, ctx);
        goto after_0;
    // 0x80071B6C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_0:
    // 0x80071B70: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071B74: jal         0x80071A24
    // 0x80071B78: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_1;
    // 0x80071B78: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x80071B7C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071B80: addiu       $a0, $a0, 0x7528
    ctx->r4 = ADD32(ctx->r4, 0X7528);
    // 0x80071B84: jal         0x800B5EDC
    // 0x80071B88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_2;
    // 0x80071B88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80071B8C: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071B90: jal         0x80071A24
    // 0x80071B94: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_3;
    // 0x80071B94: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_3:
    // 0x80071B98: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071B9C: addiu       $a0, $a0, 0x7530
    ctx->r4 = ADD32(ctx->r4, 0X7530);
    // 0x80071BA0: jal         0x800B5EDC
    // 0x80071BA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_4;
    // 0x80071BA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80071BA8: jal         0x80071A24
    // 0x80071BAC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_5;
    // 0x80071BAC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    after_5:
    // 0x80071BB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071BB4: addiu       $a0, $a0, 0x753C
    ctx->r4 = ADD32(ctx->r4, 0X753C);
    // 0x80071BB8: jal         0x800B5EDC
    // 0x80071BBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_6;
    // 0x80071BBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80071BC0: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x80071BC4: jal         0x80071A24
    // 0x80071BC8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_7;
    // 0x80071BC8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_7:
    // 0x80071BCC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071BD0: addiu       $a0, $a0, 0x7548
    ctx->r4 = ADD32(ctx->r4, 0X7548);
    // 0x80071BD4: jal         0x800B5EDC
    // 0x80071BD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_8;
    // 0x80071BD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x80071BDC: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071BE0: jal         0x80071A24
    // 0x80071BE4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_9;
    // 0x80071BE4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_9:
    // 0x80071BE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071BEC: addiu       $a0, $a0, 0x7554
    ctx->r4 = ADD32(ctx->r4, 0X7554);
    // 0x80071BF0: jal         0x800B5EDC
    // 0x80071BF4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_10;
    // 0x80071BF4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80071BF8: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071BFC: jal         0x80071A24
    // 0x80071C00: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_11;
    // 0x80071C00: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_11:
    // 0x80071C04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071C08: addiu       $a0, $a0, 0x7560
    ctx->r4 = ADD32(ctx->r4, 0X7560);
    // 0x80071C0C: jal         0x800B5EDC
    // 0x80071C10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_12;
    // 0x80071C10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x80071C14: jal         0x80071A24
    // 0x80071C18: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    get_memory_colour_tag_count(rdram, ctx);
        goto after_13;
    // 0x80071C18: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_13:
    // 0x80071C1C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071C20: addiu       $a0, $a0, 0x756C
    ctx->r4 = ADD32(ctx->r4, 0X756C);
    // 0x80071C24: jal         0x800B5EDC
    // 0x80071C28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_14;
    // 0x80071C28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x80071C2C: lui         $a0, 0x7F7F
    ctx->r4 = S32(0X7F7F << 16);
    // 0x80071C30: jal         0x80071A24
    // 0x80071C34: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_15;
    // 0x80071C34: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_15:
    // 0x80071C38: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071C3C: addiu       $a0, $a0, 0x7578
    ctx->r4 = ADD32(ctx->r4, 0X7578);
    // 0x80071C40: jal         0x800B5EDC
    // 0x80071C44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_16;
    // 0x80071C44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x80071C48: lui         $a0, 0xFF7F
    ctx->r4 = S32(0XFF7F << 16);
    // 0x80071C4C: jal         0x80071A24
    // 0x80071C50: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_17;
    // 0x80071C50: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_17:
    // 0x80071C54: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071C58: addiu       $a0, $a0, 0x7584
    ctx->r4 = ADD32(ctx->r4, 0X7584);
    // 0x80071C5C: jal         0x800B5EDC
    // 0x80071C60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_18;
    // 0x80071C60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_18:
    // 0x80071C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071C68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071C6C: jr          $ra
    // 0x80071C70: nop

    return;
    // 0x80071C70: nop

;}
RECOMP_FUNC void tex_disable_modes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AE0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007AE10: addiu       $v0, $v0, 0x6378
    ctx->r2 = ADD32(ctx->r2, 0X6378);
    // 0x8007AE14: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007AE18: nop

    // 0x8007AE1C: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x8007AE20: jr          $ra
    // 0x8007AE24: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8007AE24: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void light_setup_colour_change(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032248: blez        $a2, L_80032294
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8003224C: nop
    
            goto L_80032294;
    }
    // 0x8003224C: nop

    // 0x80032250: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x80032254: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80032258: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8003225C: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x80032260: sh          $a2, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r6;
    // 0x80032264: bne         $a2, $zero, L_80032270
    if (ctx->r6 != 0) {
        // 0x80032268: nop
    
            goto L_80032270;
    }
    // 0x80032268: nop

    // 0x8003226C: break       7
    do_break(2147689068);
L_80032270:
    // 0x80032270: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80032274: bne         $a2, $at, L_80032288
    if (ctx->r6 != ctx->r1) {
        // 0x80032278: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80032288;
    }
    // 0x80032278: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003227C: bne         $t8, $at, L_80032288
    if (ctx->r24 != ctx->r1) {
        // 0x80032280: nop
    
            goto L_80032288;
    }
    // 0x80032280: nop

    // 0x80032284: break       6
    do_break(2147689092);
L_80032288:
    // 0x80032288: mflo        $t9
    ctx->r25 = lo;
    // 0x8003228C: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x80032290: nop

L_80032294:
    // 0x80032294: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80032298: nop

    // 0x8003229C: blez        $v0, L_800322E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800322A0: nop
    
            goto L_800322E8;
    }
    // 0x800322A0: nop

    // 0x800322A4: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x800322A8: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x800322AC: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800322B0: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x800322B4: sh          $v0, 0x3E($a0)
    MEM_H(0X3E, ctx->r4) = ctx->r2;
    // 0x800322B8: bne         $v0, $zero, L_800322C4
    if (ctx->r2 != 0) {
        // 0x800322BC: nop
    
            goto L_800322C4;
    }
    // 0x800322BC: nop

    // 0x800322C0: break       7
    do_break(2147689152);
L_800322C4:
    // 0x800322C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800322C8: bne         $v0, $at, L_800322DC
    if (ctx->r2 != ctx->r1) {
        // 0x800322CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800322DC;
    }
    // 0x800322CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800322D0: bne         $t2, $at, L_800322DC
    if (ctx->r10 != ctx->r1) {
        // 0x800322D4: nop
    
            goto L_800322DC;
    }
    // 0x800322D4: nop

    // 0x800322D8: break       6
    do_break(2147689176);
L_800322DC:
    // 0x800322DC: mflo        $t3
    ctx->r11 = lo;
    // 0x800322E0: sw          $t3, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r11;
    // 0x800322E4: nop

L_800322E8:
    // 0x800322E8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800322EC: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x800322F0: blez        $v0, L_8003233C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800322F4: nop
    
            goto L_8003233C;
    }
    // 0x800322F4: nop

    // 0x800322F8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x800322FC: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80032300: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80032304: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x80032308: sh          $v0, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r2;
    // 0x8003230C: bne         $v0, $zero, L_80032318
    if (ctx->r2 != 0) {
        // 0x80032310: nop
    
            goto L_80032318;
    }
    // 0x80032310: nop

    // 0x80032314: break       7
    do_break(2147689236);
L_80032318:
    // 0x80032318: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003231C: bne         $v0, $at, L_80032330
    if (ctx->r2 != ctx->r1) {
        // 0x80032320: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80032330;
    }
    // 0x80032320: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80032324: bne         $t7, $at, L_80032330
    if (ctx->r15 != ctx->r1) {
        // 0x80032328: nop
    
            goto L_80032330;
    }
    // 0x80032328: nop

    // 0x8003232C: break       6
    do_break(2147689260);
L_80032330:
    // 0x80032330: mflo        $t8
    ctx->r24 = lo;
    // 0x80032334: sw          $t8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r24;
    // 0x80032338: nop

L_8003233C:
    // 0x8003233C: jr          $ra
    // 0x80032340: nop

    return;
    // 0x80032340: nop

;}
RECOMP_FUNC void load_tt_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059A68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059A6C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80059A70: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059A74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80059A78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059A7C: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80059A80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80059A84: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80059A88: jal         0x80070C9C
    // 0x80059A8C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80059A8C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_0:
    // 0x80059A90: beq         $v0, $zero, L_80059B38
    if (ctx->r2 == 0) {
        // 0x80059A94: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80059B38;
    }
    // 0x80059A94: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80059A98: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80059A9C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80059AA0: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x80059AA4: jal         0x80076E68
    // 0x80059AA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_1;
    // 0x80059AA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80059AAC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059AB0: addiu       $v1, $v1, -0x2A70
    ctx->r3 = ADD32(ctx->r3, -0X2A70);
    // 0x80059AB4: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80059AB8: nop

    // 0x80059ABC: beq         $a0, $zero, L_80059AD0
    if (ctx->r4 == 0) {
        // 0x80059AC0: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80059AD0;
    }
    // 0x80059AC0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80059AC4: jal         0x80071140
    // 0x80059AC8: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80059AC8: nop

    after_2:
    // 0x80059ACC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_80059AD0:
    // 0x80059AD0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80059AD4: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
    // 0x80059AD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80059ADC: jal         0x80070C9C
    // 0x80059AE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80059AE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80059AE4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059AE8: addiu       $v1, $v1, -0x2A70
    ctx->r3 = ADD32(ctx->r3, -0X2A70);
    // 0x80059AEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80059AF0: beq         $v0, $zero, L_80059B30
    if (ctx->r2 == 0) {
        // 0x80059AF4: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_80059B30;
    }
    // 0x80059AF4: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80059AF8: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x80059AFC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80059B00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059B04: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80059B08: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x80059B0C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80059B10: sh          $t9, -0x2A5C($at)
    MEM_H(-0X2A5C, ctx->r1) = ctx->r25;
    // 0x80059B14: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x80059B18: jal         0x800C9DA0
    // 0x80059B1C: nop

    _bcopy(rdram, ctx);
        goto after_4;
    // 0x80059B1C: nop

    after_4:
    // 0x80059B20: jal         0x80071140
    // 0x80059B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80059B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80059B28: b           L_80059B3C
    // 0x80059B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80059B3C;
    // 0x80059B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059B30:
    // 0x80059B30: jal         0x80071140
    // 0x80059B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x80059B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80059B38:
    // 0x80059B38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059B3C:
    // 0x80059B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059B40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80059B44: jr          $ra
    // 0x80059B48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80059B48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void get_previous_particle_behaviour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B461C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B4620: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B4624: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B4628: bgez        $v1, L_800B4650
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B462C: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_800B4650;
    }
    // 0x800B462C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B4630: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B4634: addiu       $v0, $v0, 0x2CF4
    ctx->r2 = ADD32(ctx->r2, 0X2CF4);
L_800B4638:
    // 0x800B4638: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B463C: nop

    // 0x800B4640: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800B4644: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B4648: bltz        $t9, L_800B4638
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B464C: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800B4638;
    }
    // 0x800B464C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800B4650:
    // 0x800B4650: lw          $t0, 0x2CFC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2CFC);
    // 0x800B4654: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800B4658: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B465C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800B4660: jr          $ra
    // 0x800B4664: nop

    return;
    // 0x800B4664: nop

;}
RECOMP_FUNC void model_init_collision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006017C: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80060180: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80060184: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80060188: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8006018C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80060190: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80060194: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80060198: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8006019C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800601A0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800601A4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800601A8: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800601AC: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x800601B0: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800601B4: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800601B8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800601BC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800601C0: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800601C4: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800601C8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800601CC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800601D0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800601D4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800601D8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800601DC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800601E0: bne         $t6, $zero, L_800608B0
    if (ctx->r14 != 0) {
        // 0x800601E4: lui         $s0, 0xFF00
        ctx->r16 = S32(0XFF00 << 16);
            goto L_800608B0;
    }
    // 0x800601E4: lui         $s0, 0xFF00
    ctx->r16 = S32(0XFF00 << 16);
    // 0x800601E8: lh          $a0, 0x28($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X28);
    // 0x800601EC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800601F0: blez        $a0, L_80060238
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800601F4: ori         $s0, $s0, 0xFF
        ctx->r16 = ctx->r16 | 0XFF;
            goto L_80060238;
    }
    // 0x800601F4: ori         $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 | 0XFF;
    // 0x800601F8: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x800601FC: subu        $a2, $a2, $a0
    ctx->r6 = SUB32(ctx->r6, ctx->r4);
    // 0x80060200: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x80060204: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80060208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8006020C:
    // 0x8006020C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80060210: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80060214: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
    // 0x80060218: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x8006021C: bne         $t8, $zero, L_8006022C
    if (ctx->r24 != 0) {
        // 0x80060220: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8006022C;
    }
    // 0x80060220: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80060224: addu        $t9, $s4, $a0
    ctx->r25 = ADD32(ctx->r20, ctx->r4);
    // 0x80060228: subu        $s4, $t9, $v1
    ctx->r20 = SUB32(ctx->r25, ctx->r3);
L_8006022C:
    // 0x8006022C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80060230: bne         $at, $zero, L_8006020C
    if (ctx->r1 != 0) {
        // 0x80060234: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_8006020C;
    }
    // 0x80060234: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80060238:
    // 0x80060238: sll         $a0, $s4, 3
    ctx->r4 = S32(ctx->r20 << 3);
    // 0x8006023C: jal         0x80070D10
    // 0x80060240: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x80060240: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80060244: beq         $v0, $zero, L_800608B0
    if (ctx->r2 == 0) {
        // 0x80060248: sw          $v0, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->r2;
            goto L_800608B0;
    }
    // 0x80060248: sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    // 0x8006024C: sll         $a0, $s4, 6
    ctx->r4 = S32(ctx->r20 << 6);
    // 0x80060250: jal         0x80070D10
    // 0x80060254: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x80060254: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80060258: bne         $v0, $zero, L_80060274
    if (ctx->r2 != 0) {
        // 0x8006025C: sw          $v0, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r2;
            goto L_80060274;
    }
    // 0x8006025C: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x80060260: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x80060264: jal         0x80071140
    // 0x80060268: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80060268: nop

    after_2:
    // 0x8006026C: b           L_800608B0
    // 0x80060270: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
        goto L_800608B0;
    // 0x80060270: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
L_80060274:
    // 0x80060274: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
    // 0x80060278: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x8006027C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80060280: blez        $a0, L_80060568
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80060284: addiu       $s7, $zero, 0xA
        ctx->r23 = ADD32(0, 0XA);
            goto L_80060568;
    }
    // 0x80060284: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x80060288: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_8006028C:
    // 0x8006028C: lw          $t3, 0x38($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X38);
    // 0x80060290: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80060294: sll         $s0, $s4, 3
    ctx->r16 = S32(ctx->r20 << 3);
    // 0x80060298: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8006029C: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x800602A0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800602A4: lh          $s5, 0x2($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X2);
    // 0x800602A8: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x800602AC: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800602B0: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x800602B4: andi        $t7, $t6, 0x200
    ctx->r15 = ctx->r14 & 0X200;
    // 0x800602B8: beq         $t7, $zero, L_800602C4
    if (ctx->r15 == 0) {
        // 0x800602BC: sll         $s1, $v1, 4
        ctx->r17 = S32(ctx->r3 << 4);
            goto L_800602C4;
    }
    // 0x800602BC: sll         $s1, $v1, 4
    ctx->r17 = S32(ctx->r3 << 4);
    // 0x800602C0: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
L_800602C4:
    // 0x800602C4: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x800602C8: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x800602CC: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800602D0: beq         $at, $zero, L_80060548
    if (ctx->r1 == 0) {
        // 0x800602D4: lw          $t5, 0xEC($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XEC);
            goto L_80060548;
    }
    // 0x800602D4: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
L_800602D8:
    // 0x800602D8: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x800602DC: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800602E0: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    // 0x800602E4: lbu         $t4, 0x1($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X1);
    // 0x800602E8: nop

    // 0x800602EC: addu        $t5, $t4, $s5
    ctx->r13 = ADD32(ctx->r12, ctx->r21);
    // 0x800602F0: multu       $t5, $s7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800602F4: mflo        $t6
    ctx->r14 = lo;
    // 0x800602F8: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800602FC: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80060300: nop

    // 0x80060304: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80060308: nop

    // 0x8006030C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060310: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x80060314: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80060318: lwc1        $f2, 0xCC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8006031C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80060320: nop

    // 0x80060324: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80060328: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x8006032C: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x80060330: lwc1        $f26, 0xC8($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80060334: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80060338: nop

    // 0x8006033C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060340: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    // 0x80060344: lbu         $t3, 0x2($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X2);
    // 0x80060348: lbu         $t9, 0x3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X3);
    // 0x8006034C: addu        $t4, $t3, $s5
    ctx->r12 = ADD32(ctx->r11, ctx->r21);
    // 0x80060350: multu       $t4, $s7
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060354: addu        $t3, $t9, $s5
    ctx->r11 = ADD32(ctx->r25, ctx->r21);
    // 0x80060358: lwc1        $f24, 0xC4($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8006035C: mflo        $t5
    ctx->r13 = lo;
    // 0x80060360: addu        $v0, $t5, $v1
    ctx->r2 = ADD32(ctx->r13, ctx->r3);
    // 0x80060364: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80060368: multu       $t3, $s7
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006036C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80060370: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80060374: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80060378: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8006037C: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80060380: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80060384: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80060388: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006038C: mflo        $t4
    ctx->r12 = lo;
    // 0x80060390: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x80060394: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80060398: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x8006039C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800603A0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800603A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800603A8: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x800603AC: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800603B0: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800603B4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800603B8: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800603BC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800603C0: sub.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800603C4: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800603C8: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800603CC: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800603D0: sub.s       $f10, $f24, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x800603D4: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800603D8: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800603DC: sub.s       $f4, $f14, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f22.fl;
    // 0x800603E0: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800603E4: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800603E8: swc1        $f20, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f20.u32l;
    // 0x800603EC: sub.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x800603F0: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800603F4: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800603F8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800603FC: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80060400: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80060404: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80060408: add.s       $f28, $f4, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006040C: swc1        $f28, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f28.u32l;
    // 0x80060410: sub.s       $f4, $f12, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f26.fl;
    // 0x80060414: mul.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80060418: sub.s       $f4, $f26, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f16.fl;
    // 0x8006041C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80060420: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80060424: nop

    // 0x80060428: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8006042C: add.s       $f30, $f8, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80060430: swc1        $f30, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f30.u32l;
    // 0x80060434: mul.s       $f4, $f28, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x80060438: nop

    // 0x8006043C: mul.s       $f6, $f30, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x80060440: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80060444: jal         0x800C9AD0
    // 0x80060448: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80060448: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_3:
    // 0x8006044C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80060450: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80060454: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80060458: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8006045C: lwc1        $f2, 0xCC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80060460: bc1f        L_80060488
    if (!c1cs) {
        // 0x80060464: sll         $v0, $s4, 4
        ctx->r2 = S32(ctx->r20 << 4);
            goto L_80060488;
    }
    // 0x80060464: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
    // 0x80060468: nop

    // 0x8006046C: div.s       $f16, $f20, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80060470: nop

    // 0x80060474: div.s       $f14, $f28, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f28.fl, ctx->f0.fl);
    // 0x80060478: swc1        $f16, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f16.u32l;
    // 0x8006047C: div.s       $f12, $f30, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80060480: swc1        $f14, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f14.u32l;
    // 0x80060484: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
L_80060488:
    // 0x80060488: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x8006048C: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80060490: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80060494: lwc1        $f14, 0xA4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80060498: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x8006049C: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x800604A0: lw          $t4, 0x10($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X10);
    // 0x800604A4: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800604A8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800604AC: swc1        $f14, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f14.u32l;
    // 0x800604B0: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x800604B4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800604B8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800604BC: swc1        $f12, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f12.u32l;
    // 0x800604C0: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800604C4: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x800604C8: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800604CC: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800604D0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800604D4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800604D8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800604DC: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800604E0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800604E4: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800604E8: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x800604EC: lw          $t3, 0xC($s2)
    ctx->r11 = MEM_W(ctx->r18, 0XC);
    // 0x800604F0: nop

    // 0x800604F4: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800604F8: sh          $s4, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r20;
    // 0x800604FC: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x80060500: nop

    // 0x80060504: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80060508: sh          $s4, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r20;
    // 0x8006050C: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x80060510: nop

    // 0x80060514: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80060518: sh          $s4, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r20;
    // 0x8006051C: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80060520: nop

    // 0x80060524: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x80060528: sh          $s4, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r20;
    // 0x8006052C: lw          $t4, 0xF4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF4);
    // 0x80060530: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060534: bne         $s6, $t4, L_800602D8
    if (ctx->r22 != ctx->r12) {
        // 0x80060538: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_800602D8;
    }
    // 0x80060538: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8006053C: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x80060540: nop

    // 0x80060544: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
L_80060548:
    // 0x80060548: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8006054C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80060550: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80060554: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x80060558: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x8006055C: bne         $at, $zero, L_8006028C
    if (ctx->r1 != 0) {
        // 0x80060560: sw          $t6, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r14;
            goto L_8006028C;
    }
    // 0x80060560: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x80060564: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
L_80060568:
    // 0x80060568: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x8006056C: sh          $s4, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r20;
    // 0x80060570: jal         0x80060910
    // 0x80060574: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80060910(rdram, ctx);
        goto after_4;
    // 0x80060574: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80060578: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x8006057C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80060580: blez        $a0, L_800608B0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80060584: addiu       $fp, $zero, 0x3
        ctx->r30 = ADD32(0, 0X3);
            goto L_800608B0;
    }
    // 0x80060584: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x80060588: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_8006058C:
    // 0x8006058C: lw          $t9, 0x38($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X38);
    // 0x80060590: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80060594: nop

    // 0x80060598: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
    // 0x8006059C: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x800605A0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800605A4: lh          $s5, 0x2($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X2);
    // 0x800605A8: lh          $a3, 0x10($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X10);
    // 0x800605AC: andi        $t5, $t4, 0x200
    ctx->r13 = ctx->r12 & 0X200;
    // 0x800605B0: beq         $t5, $zero, L_800605BC
    if (ctx->r13 == 0) {
        // 0x800605B4: sll         $v0, $s3, 3
        ctx->r2 = S32(ctx->r19 << 3);
            goto L_800605BC;
    }
    // 0x800605B4: sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19 << 3);
    // 0x800605B8: addiu       $a3, $v1, -0x1
    ctx->r7 = ADD32(ctx->r3, -0X1);
L_800605BC:
    // 0x800605BC: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800605C0: beq         $at, $zero, L_80060890
    if (ctx->r1 == 0) {
        // 0x800605C4: or          $s6, $v1, $zero
        ctx->r22 = ctx->r3 | 0;
            goto L_80060890;
    }
    // 0x800605C4: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x800605C8: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x800605CC: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
L_800605D0:
    // 0x800605D0: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x800605D4: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x800605D8: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x800605DC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800605E0: lhu         $t6, 0x0($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X0);
    // 0x800605E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800605E8: sll         $t3, $t6, 4
    ctx->r11 = S32(ctx->r14 << 4);
    // 0x800605EC: addu        $v1, $t9, $t3
    ctx->r3 = ADD32(ctx->r25, ctx->r11);
    // 0x800605F0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800605F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800605F8: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x800605FC: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80060600: nop

    // 0x80060604: swc1        $f8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
    // 0x80060608: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8006060C: nop

    // 0x80060610: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
L_80060614:
    // 0x80060614: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x80060618: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8006061C: lw          $a3, 0xC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC);
    // 0x80060620: lw          $t0, 0x10($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X10);
    // 0x80060624: bne         $at, $zero, L_80060630
    if (ctx->r1 != 0) {
        // 0x80060628: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80060630;
    }
    // 0x80060628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006062C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80060630:
    // 0x80060630: lw          $t4, 0x8($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X8);
    // 0x80060634: sll         $t5, $s6, 4
    ctx->r13 = S32(ctx->r22 << 4);
    // 0x80060638: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8006063C: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x80060640: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80060644: sll         $t3, $s3, 3
    ctx->r11 = S32(ctx->r19 << 3);
    // 0x80060648: addu        $t1, $t8, $s5
    ctx->r9 = ADD32(ctx->r24, ctx->r21);
    // 0x8006064C: multu       $t1, $s7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060650: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80060654: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80060658: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x8006065C: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x80060660: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80060664: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x80060668: lbu         $t9, 0x1($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1);
    // 0x8006066C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80060670: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80060674: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80060678: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8006067C: mflo        $t6
    ctx->r14 = lo;
    // 0x80060680: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80060684: addu        $t2, $t9, $s5
    ctx->r10 = ADD32(ctx->r25, ctx->r21);
    // 0x80060688: multu       $t2, $s7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006068C: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x80060690: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80060694: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x80060698: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8006069C: add.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800606A0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800606A4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800606A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800606AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800606B0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800606B4: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x800606B8: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x800606BC: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x800606C0: add.s       $f26, $f6, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800606C4: mflo        $t5
    ctx->r13 = lo;
    // 0x800606C8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800606CC: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x800606D0: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x800606D4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800606D8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800606DC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800606E0: mul.s       $f4, $f20, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x800606E4: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800606E8: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800606EC: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
    // 0x800606F0: cvt.s.w     $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800606F4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800606F8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800606FC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80060700: swc1        $f30, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f30.u32l;
    // 0x80060704: mul.s       $f10, $f24, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x80060708: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006070C: mul.s       $f6, $f26, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x80060710: add.s       $f2, $f10, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x80060714: swc1        $f2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f2.u32l;
    // 0x80060718: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006071C: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80060720: add.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80060724: add.s       $f22, $f4, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80060728: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    // 0x8006072C: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80060730: mul.s       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80060734: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80060738: lwc1        $f0, 0xC8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8006073C: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80060740: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80060744: sub.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80060748: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006074C: sub.s       $f10, $f14, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f22.fl;
    // 0x80060750: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80060754: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80060758: mov.s       $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = ctx->f8.fl;
    // 0x8006075C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80060760: sub.s       $f8, $f22, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x80060764: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80060768: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8006076C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80060770: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80060774: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80060778: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8006077C: nop

    // 0x80060780: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80060784: add.s       $f28, $f6, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80060788: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8006078C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80060790: mul.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80060794: sub.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80060798: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8006079C: mul.s       $f6, $f22, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x800607A0: mov.s       $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    ctx->f24.fl = ctx->f28.fl;
    // 0x800607A4: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800607A8: add.s       $f30, $f8, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800607AC: mul.s       $f10, $f28, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x800607B0: mov.s       $f26, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    ctx->f26.fl = ctx->f30.fl;
    // 0x800607B4: mul.s       $f6, $f30, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x800607B8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800607BC: jal         0x800C9AD0
    // 0x800607C0: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x800607C0: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_5:
    // 0x800607C4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800607C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800607CC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800607D0: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x800607D4: lwc1        $f2, 0xCC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800607D8: bc1f        L_800607F4
    if (!c1cs) {
        // 0x800607DC: nop
    
            goto L_800607F4;
    }
    // 0x800607DC: nop

    // 0x800607E0: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800607E4: nop

    // 0x800607E8: div.s       $f24, $f28, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f28.fl, ctx->f0.fl);
    // 0x800607EC: nop

    // 0x800607F0: div.s       $f26, $f30, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
L_800607F4:
    // 0x800607F4: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x800607F8: sll         $t3, $s3, 3
    ctx->r11 = S32(ctx->r19 << 3);
    // 0x800607FC: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80060800: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80060804: sh          $s4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r20;
    // 0x80060808: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x8006080C: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
    // 0x80060810: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80060814: swc1        $f20, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f20.u32l;
    // 0x80060818: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x8006081C: mul.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80060820: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80060824: swc1        $f24, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f24.u32l;
    // 0x80060828: lw          $t4, 0x10($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X10);
    // 0x8006082C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80060830: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80060834: swc1        $f26, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f26.u32l;
    // 0x80060838: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8006083C: lw          $t7, 0x10($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X10);
    // 0x80060840: mul.s       $f4, $f6, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80060844: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80060848: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8006084C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80060850: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80060854: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060858: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x8006085C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80060860: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80060864: bne         $s0, $fp, L_80060614
    if (ctx->r16 != ctx->r30) {
        // 0x80060868: swc1        $f6, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
            goto L_80060614;
    }
    // 0x80060868: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x8006086C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80060870: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x80060874: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80060878: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8006087C: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80060880: bne         $s6, $t3, L_800605D0
    if (ctx->r22 != ctx->r11) {
        // 0x80060884: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800605D0;
    }
    // 0x80060884: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80060888: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x8006088C: nop

L_80060890:
    // 0x80060890: lw          $t4, 0xEC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XEC);
    // 0x80060894: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80060898: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8006089C: slt         $at, $t5, $a0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800608A0: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x800608A4: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x800608A8: bne         $at, $zero, L_8006058C
    if (ctx->r1 != 0) {
        // 0x800608AC: sw          $t5, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r13;
            goto L_8006058C;
    }
    // 0x800608AC: sw          $t5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r13;
L_800608B0:
    // 0x800608B0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800608B4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800608B8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800608BC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800608C0: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800608C4: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800608C8: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800608CC: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800608D0: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800608D4: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800608D8: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800608DC: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x800608E0: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800608E4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800608E8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800608EC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800608F0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800608F4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800608F8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800608FC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80060900: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80060904: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80060908: jr          $ra
    // 0x8006090C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8006090C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void create_general_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1130: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B1134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B1138: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B113C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B1140: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B1144: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800B1148: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B114C: lw          $t6, 0x2CF0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2CF0);
    // 0x800B1150: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B1154: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B1158: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x800B115C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B1160: lbu         $a2, 0x0($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X0);
    // 0x800B1164: nop

    // 0x800B1168: beq         $a2, $at, L_800B1178
    if (ctx->r6 == ctx->r1) {
        // 0x800B116C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800B1178;
    }
    // 0x800B116C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B1170: bne         $a2, $at, L_800B1180
    if (ctx->r6 != ctx->r1) {
        // 0x800B1174: nop
    
            goto L_800B1180;
    }
    // 0x800B1174: nop

L_800B1178:
    // 0x800B1178: b           L_800B1CA4
    // 0x800B117C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B1CA4;
    // 0x800B117C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B1180:
    // 0x800B1180: lw          $s1, 0x0($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X0);
    // 0x800B1184: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B1188: lw          $t0, 0x9C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X9C);
    // 0x800B118C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1190: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B1194: jal         0x800B1CB8
    // 0x800B1198: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    particle_allocate(rdram, ctx);
        goto after_0;
    // 0x800B1198: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x800B119C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B11A0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B11A4: bne         $v0, $zero, L_800B11B4
    if (ctx->r2 != 0) {
        // 0x800B11A8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B11B4;
    }
    // 0x800B11A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B11AC: b           L_800B1CA4
    // 0x800B11B0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800B1CA4;
    // 0x800B11B0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800B11B4:
    // 0x800B11B4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B11B8: addiu       $t3, $zero, -0x8000
    ctx->r11 = ADD32(0, -0X8000);
    // 0x800B11BC: lh          $t2, 0x2E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2E);
    // 0x800B11C0: sh          $t3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r11;
    // 0x800B11C4: sh          $t2, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r10;
    // 0x800B11C8: lbu         $t4, 0x1($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X1);
    // 0x800B11CC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800B11D0: sb          $t4, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r12;
    // 0x800B11D4: lhu         $t5, 0x2($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X2);
    // 0x800B11D8: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x800B11DC: andi        $t6, $t5, 0x800
    ctx->r14 = ctx->r13 & 0X800;
    // 0x800B11E0: beq         $t6, $zero, L_800B1234
    if (ctx->r14 == 0) {
        // 0x800B11E4: sw          $t5, 0x40($v0)
        MEM_W(0X40, ctx->r2) = ctx->r13;
            goto L_800B1234;
    }
    // 0x800B11E4: sw          $t5, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r13;
    // 0x800B11E8: lw          $v1, 0x54($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X54);
    // 0x800B11EC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B11F0: beq         $v1, $zero, L_800B1234
    if (ctx->r3 == 0) {
        // 0x800B11F4: nop
    
            goto L_800B1234;
    }
    // 0x800B11F4: nop

    // 0x800B11F8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B11FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B1200: nop

    // 0x800B1204: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B1208: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B120C: nop

    // 0x800B1210: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B1214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B1218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B121C: nop

    // 0x800B1220: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B1224: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800B1228: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B122C: b           L_800B1238
    // 0x800B1230: sh          $t9, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r25;
        goto L_800B1238;
    // 0x800B1230: sh          $t9, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r25;
L_800B1234:
    // 0x800B1234: sh          $t2, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r10;
L_800B1238:
    // 0x800B1238: lw          $t3, 0x5C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X5C);
    // 0x800B123C: lwc1        $f16, 0x50($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X50);
    // 0x800B1240: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x800B1244: bgez        $t4, L_800B129C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B1248: nop
    
            goto L_800B129C;
    }
    // 0x800B1248: nop

    // 0x800B124C: lw          $a1, 0x8C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8C);
    // 0x800B1250: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800B1254: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B1258: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B125C: jal         0x8006F94C
    // 0x800B1260: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800B1260: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_1:
    // 0x800B1264: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800B1268: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B126C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B1270: lwc1        $f9, -0x7438($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X7438);
    // 0x800B1274: lwc1        $f8, -0x7434($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7434);
    // 0x800B1278: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B127C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800B1280: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B1284: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1288: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800B128C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B1290: add.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d + ctx->f10.d;
    // 0x800B1294: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B1298: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
L_800B129C:
    // 0x800B129C: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B12A0: nop

    // 0x800B12A4: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800B12A8: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800B12AC: lw          $t5, 0x5C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X5C);
    // 0x800B12B0: lwc1        $f16, 0x54($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800B12B4: sll         $t7, $t5, 13
    ctx->r15 = S32(ctx->r13 << 13);
    // 0x800B12B8: bgez        $t7, L_800B1310
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B12BC: nop
    
            goto L_800B1310;
    }
    // 0x800B12BC: nop

    // 0x800B12C0: lw          $a1, 0x90($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X90);
    // 0x800B12C4: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800B12C8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B12CC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B12D0: jal         0x8006F94C
    // 0x800B12D4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800B12D4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x800B12D8: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800B12DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B12E0: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B12E4: lwc1        $f7, -0x7430($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X7430);
    // 0x800B12E8: lwc1        $f6, -0x742C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X742C);
    // 0x800B12EC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800B12F0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800B12F4: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B12F8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B12FC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800B1300: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B1304: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x800B1308: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B130C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
L_800B1310:
    // 0x800B1310: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800B1314: nop

    // 0x800B1318: andi        $t8, $t6, 0x1000
    ctx->r24 = ctx->r14 & 0X1000;
    // 0x800B131C: beq         $t8, $zero, L_800B1378
    if (ctx->r24 == 0) {
        // 0x800B1320: nop
    
            goto L_800B1378;
    }
    // 0x800B1320: nop

    // 0x800B1324: lwc1        $f0, 0x1C($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800B1328: lwc1        $f2, 0x20($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800B132C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B1330: lwc1        $f14, 0x24($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X24);
    // 0x800B1334: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800B1338: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B133C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B1340: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1344: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B1348: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B134C: jal         0x800C9AD0
    // 0x800B1350: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B1350: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_3:
    // 0x800B1354: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B1358: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B135C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800B1360: lwc1        $f4, -0x7428($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7428);
    // 0x800B1364: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1368: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B136C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800B1370: b           L_800B1388
    // 0x800B1374: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_800B1388;
    // 0x800B1374: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_800B1378:
    // 0x800B1378: lwc1        $f18, 0x10($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B137C: nop

    // 0x800B1380: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B1384: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
L_800B1388:
    // 0x800B1388: lh          $a1, 0xA($a3)
    ctx->r5 = MEM_H(ctx->r7, 0XA);
    // 0x800B138C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B1390: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1394: jal         0x8006F94C
    // 0x800B1398: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800B1398: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_4:
    // 0x800B139C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B13A0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B13A4: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x800B13A8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B13AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B13B0: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x800B13B4: sh          $t2, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r10;
    // 0x800B13B8: sb          $zero, 0x38($s0)
    MEM_B(0X38, ctx->r16) = 0;
    // 0x800B13BC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B13C0: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x800B13C4: lw          $v1, 0x2D00($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2D00);
    // 0x800B13C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B13CC: beq         $v1, $zero, L_800B13DC
    if (ctx->r3 == 0) {
        // 0x800B13D0: nop
    
            goto L_800B13DC;
    }
    // 0x800B13D0: nop

    // 0x800B13D4: b           L_800B14B0
    // 0x800B13D8: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
        goto L_800B14B0;
    // 0x800B13D8: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
L_800B13DC:
    // 0x800B13DC: beq         $t0, $at, L_800B1480
    if (ctx->r8 == ctx->r1) {
        // 0x800B13E0: nop
    
            goto L_800B1480;
    }
    // 0x800B13E0: nop

    // 0x800B13E4: lh          $t3, 0x1E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X1E);
    // 0x800B13E8: nop

    // 0x800B13EC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B13F0: sh          $t4, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r12;
    // 0x800B13F4: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800B13F8: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B13FC: nop

    // 0x800B1400: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B1404: bne         $at, $zero, L_800B141C
    if (ctx->r1 != 0) {
        // 0x800B1408: sll         $t7, $v0, 3
        ctx->r15 = S32(ctx->r2 << 3);
            goto L_800B141C;
    }
    // 0x800B1408: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B140C: sh          $zero, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = 0;
    // 0x800B1410: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1414: nop

    // 0x800B1418: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
L_800B141C:
    // 0x800B141C: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x800B1420: lbu         $t8, 0x14($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X14);
    // 0x800B1424: nop

    // 0x800B1428: sb          $t8, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r24;
    // 0x800B142C: lh          $t9, 0x1E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1430: nop

    // 0x800B1434: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800B1438: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800B143C: lbu         $t4, 0x15($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X15);
    // 0x800B1440: nop

    // 0x800B1444: sb          $t4, 0x6D($s0)
    MEM_B(0X6D, ctx->r16) = ctx->r12;
    // 0x800B1448: lh          $t5, 0x1E($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X1E);
    // 0x800B144C: nop

    // 0x800B1450: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800B1454: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x800B1458: lbu         $t8, 0x16($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X16);
    // 0x800B145C: nop

    // 0x800B1460: sb          $t8, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r24;
    // 0x800B1464: lh          $t9, 0x1E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1468: nop

    // 0x800B146C: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800B1470: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800B1474: lbu         $t4, 0x17($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X17);
    // 0x800B1478: b           L_800B14B0
    // 0x800B147C: sb          $t4, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r12;
        goto L_800B14B0;
    // 0x800B147C: sb          $t4, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r12;
L_800B1480:
    // 0x800B1480: lbu         $t5, 0x14($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X14);
    // 0x800B1484: nop

    // 0x800B1488: sb          $t5, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r13;
    // 0x800B148C: lbu         $t7, 0x15($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X15);
    // 0x800B1490: nop

    // 0x800B1494: sb          $t7, 0x6D($s0)
    MEM_B(0X6D, ctx->r16) = ctx->r15;
    // 0x800B1498: lbu         $t6, 0x16($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X16);
    // 0x800B149C: nop

    // 0x800B14A0: sb          $t6, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r14;
    // 0x800B14A4: lbu         $t8, 0x17($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X17);
    // 0x800B14A8: nop

    // 0x800B14AC: sb          $t8, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r24;
L_800B14B0:
    // 0x800B14B0: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B14B4: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x800B14B8: and         $t9, $v1, $at
    ctx->r25 = ctx->r3 & ctx->r1;
    // 0x800B14BC: beq         $t9, $zero, L_800B159C
    if (ctx->r25 == 0) {
        // 0x800B14C0: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800B159C;
    }
    // 0x800B14C0: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800B14C4: sll         $t2, $t9, 11
    ctx->r10 = S32(ctx->r25 << 11);
    // 0x800B14C8: bgez        $t2, L_800B1500
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B14CC: sll         $t5, $v1, 10
        ctx->r13 = S32(ctx->r3 << 10);
            goto L_800B1500;
    }
    // 0x800B14CC: sll         $t5, $v1, 10
    ctx->r13 = S32(ctx->r3 << 10);
    // 0x800B14D0: lbu         $a1, 0x98($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X98);
    // 0x800B14D4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B14D8: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800B14DC: jal         0x8006F94C
    // 0x800B14E0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_5;
    // 0x800B14E0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_5:
    // 0x800B14E4: lbu         $t3, 0x6C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B14E8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B14EC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B14F0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B14F4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800B14F8: sb          $t4, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r12;
    // 0x800B14FC: sll         $t5, $v1, 10
    ctx->r13 = S32(ctx->r3 << 10);
L_800B1500:
    // 0x800B1500: bgez        $t5, L_800B1538
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B1504: sll         $t8, $v1, 9
        ctx->r24 = S32(ctx->r3 << 9);
            goto L_800B1538;
    }
    // 0x800B1504: sll         $t8, $v1, 9
    ctx->r24 = S32(ctx->r3 << 9);
    // 0x800B1508: lbu         $a1, 0x99($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X99);
    // 0x800B150C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1510: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B1514: jal         0x8006F94C
    // 0x800B1518: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_6;
    // 0x800B1518: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_6:
    // 0x800B151C: lbu         $t7, 0x6D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B1520: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1524: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1528: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B152C: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800B1530: sb          $t6, 0x6D($s0)
    MEM_B(0X6D, ctx->r16) = ctx->r14;
    // 0x800B1534: sll         $t8, $v1, 9
    ctx->r24 = S32(ctx->r3 << 9);
L_800B1538:
    // 0x800B1538: bgez        $t8, L_800B1570
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B153C: sll         $t3, $v1, 8
        ctx->r11 = S32(ctx->r3 << 8);
            goto L_800B1570;
    }
    // 0x800B153C: sll         $t3, $v1, 8
    ctx->r11 = S32(ctx->r3 << 8);
    // 0x800B1540: lbu         $a1, 0x9A($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X9A);
    // 0x800B1544: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1548: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B154C: jal         0x8006F94C
    // 0x800B1550: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800B1550: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_7:
    // 0x800B1554: lbu         $t9, 0x6E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B1558: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B155C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1560: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1564: addu        $t2, $t9, $v0
    ctx->r10 = ADD32(ctx->r25, ctx->r2);
    // 0x800B1568: sb          $t2, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r10;
    // 0x800B156C: sll         $t3, $v1, 8
    ctx->r11 = S32(ctx->r3 << 8);
L_800B1570:
    // 0x800B1570: bgez        $t3, L_800B159C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B1574: nop
    
            goto L_800B159C;
    }
    // 0x800B1574: nop

    // 0x800B1578: lbu         $a1, 0x9B($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X9B);
    // 0x800B157C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1580: jal         0x8006F94C
    // 0x800B1584: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_8;
    // 0x800B1584: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_8:
    // 0x800B1588: lbu         $t4, 0x6F($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6F);
    // 0x800B158C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1590: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1594: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800B1598: sb          $t5, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r13;
L_800B159C:
    // 0x800B159C: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
    // 0x800B15A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B15A4: sh          $t7, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r15;
    // 0x800B15A8: addiu       $a0, $a0, 0x2EEC
    ctx->r4 = ADD32(ctx->r4, 0X2EEC);
    // 0x800B15AC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B15B0: lbu         $t6, 0xC($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XC);
    // 0x800B15B4: nop

    // 0x800B15B8: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B15BC: mflo        $t9
    ctx->r25 = lo;
    // 0x800B15C0: sh          $t9, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r25;
    // 0x800B15C4: lbu         $t2, 0xC($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0XC);
    // 0x800B15C8: nop

    // 0x800B15CC: slti        $at, $t2, 0xFF
    ctx->r1 = SIGNED(ctx->r10) < 0XFF ? 1 : 0;
    // 0x800B15D0: beq         $at, $zero, L_800B1610
    if (ctx->r1 == 0) {
        // 0x800B15D4: nop
    
            goto L_800B1610;
    }
    // 0x800B15D4: nop

    // 0x800B15D8: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x800B15DC: nop

    // 0x800B15E0: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x800B15E4: beq         $t4, $zero, L_800B1600
    if (ctx->r12 == 0) {
        // 0x800B15E8: nop
    
            goto L_800B1600;
    }
    // 0x800B15E8: nop

    // 0x800B15EC: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800B15F0: nop

    // 0x800B15F4: ori         $t7, $t5, 0x100
    ctx->r15 = ctx->r13 | 0X100;
    // 0x800B15F8: b           L_800B1610
    // 0x800B15FC: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
        goto L_800B1610;
    // 0x800B15FC: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
L_800B1600:
    // 0x800B1600: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x800B1604: nop

    // 0x800B1608: ori         $t8, $t6, 0x80
    ctx->r24 = ctx->r14 | 0X80;
    // 0x800B160C: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_800B1610:
    // 0x800B1610: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x800B1614: lh          $v1, 0x3A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X3A);
    // 0x800B1618: nop

    // 0x800B161C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B1620: beq         $at, $zero, L_800B1684
    if (ctx->r1 == 0) {
        // 0x800B1624: nop
    
            goto L_800B1684;
    }
    // 0x800B1624: nop

    // 0x800B1628: lbu         $t9, 0xD($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XD);
    // 0x800B162C: lbu         $t2, 0xC($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0XC);
    // 0x800B1630: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800B1634: subu        $t3, $t9, $t2
    ctx->r11 = SUB32(ctx->r25, ctx->r10);
    // 0x800B1638: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B163C: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800B1640: mflo        $t5
    ctx->r13 = lo;
    // 0x800B1644: nop

    // 0x800B1648: nop

    // 0x800B164C: div         $zero, $t5, $t7
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r15)));
    // 0x800B1650: bne         $t7, $zero, L_800B165C
    if (ctx->r15 != 0) {
        // 0x800B1654: nop
    
            goto L_800B165C;
    }
    // 0x800B1654: nop

    // 0x800B1658: break       7
    do_break(2148210264);
L_800B165C:
    // 0x800B165C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1660: bne         $t7, $at, L_800B1674
    if (ctx->r15 != ctx->r1) {
        // 0x800B1664: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1674;
    }
    // 0x800B1664: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1668: bne         $t5, $at, L_800B1674
    if (ctx->r13 != ctx->r1) {
        // 0x800B166C: nop
    
            goto L_800B1674;
    }
    // 0x800B166C: nop

    // 0x800B1670: break       6
    do_break(2148210288);
L_800B1674:
    // 0x800B1674: mflo        $t6
    ctx->r14 = lo;
    // 0x800B1678: sh          $t6, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r14;
    // 0x800B167C: b           L_800B168C
    // 0x800B1680: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
        goto L_800B168C;
    // 0x800B1680: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
L_800B1684:
    // 0x800B1684: sh          $zero, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = 0;
    // 0x800B1688: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
L_800B168C:
    // 0x800B168C: lh          $t8, 0x6($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X6);
    // 0x800B1690: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B1694: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B1698: bne         $v0, $at, L_800B17B4
    if (ctx->r2 != ctx->r1) {
        // 0x800B169C: sh          $t8, 0x1A($s0)
        MEM_H(0X1A, ctx->r16) = ctx->r24;
            goto L_800B17B4;
    }
    // 0x800B169C: sh          $t8, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r24;
    // 0x800B16A0: lh          $a0, 0x4($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X4);
    // 0x800B16A4: jal         0x8007C12C
    // 0x800B16A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_9;
    // 0x800B16A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800B16AC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B16B0: beq         $v0, $zero, L_800B17A8
    if (ctx->r2 == 0) {
        // 0x800B16B4: sw          $v0, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r2;
            goto L_800B17A8;
    }
    // 0x800B16B4: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x800B16B8: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800B16BC: nop

    // 0x800B16C0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B16C4: nop

    // 0x800B16C8: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x800B16CC: nop

    // 0x800B16D0: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800B16D4: beq         $t5, $zero, L_800B1714
    if (ctx->r13 == 0) {
        // 0x800B16D8: nop
    
            goto L_800B1714;
    }
    // 0x800B16D8: nop

    // 0x800B16DC: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x800B16E0: nop

    // 0x800B16E4: andi        $t6, $t7, 0x1000
    ctx->r14 = ctx->r15 & 0X1000;
    // 0x800B16E8: beq         $t6, $zero, L_800B1704
    if (ctx->r14 == 0) {
        // 0x800B16EC: nop
    
            goto L_800B1704;
    }
    // 0x800B16EC: nop

    // 0x800B16F0: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800B16F4: nop

    // 0x800B16F8: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800B16FC: b           L_800B1714
    // 0x800B1700: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
        goto L_800B1714;
    // 0x800B1700: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
L_800B1704:
    // 0x800B1704: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x800B1708: nop

    // 0x800B170C: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x800B1710: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
L_800B1714:
    // 0x800B1714: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800B1718: nop

    // 0x800B171C: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800B1720: beq         $t5, $zero, L_800B176C
    if (ctx->r13 == 0) {
        // 0x800B1724: nop
    
            goto L_800B176C;
    }
    // 0x800B1724: nop

    // 0x800B1728: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x800B172C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1730: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x800B1734: jal         0x8006F94C
    // 0x800B1738: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_10;
    // 0x800B1738: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_10:
    // 0x800B173C: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x800B1740: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1744: sll         $t6, $v0, 8
    ctx->r14 = S32(ctx->r2 << 8);
    // 0x800B1748: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B174C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x800B1750: bne         $t9, $at, L_800B18E0
    if (ctx->r25 != ctx->r1) {
        // 0x800B1754: sh          $t6, 0x18($s0)
        MEM_H(0X18, ctx->r16) = ctx->r14;
            goto L_800B18E0;
    }
    // 0x800B1754: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
    // 0x800B1758: lh          $t2, 0x18($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X18);
    // 0x800B175C: nop

    // 0x800B1760: ori         $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 | 0XFF;
    // 0x800B1764: b           L_800B18E0
    // 0x800B1768: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
        goto L_800B18E0;
    // 0x800B1768: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
L_800B176C:
    // 0x800B176C: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x800B1770: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1774: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800B1778: bne         $t5, $at, L_800B17A0
    if (ctx->r13 != ctx->r1) {
        // 0x800B177C: nop
    
            goto L_800B17A0;
    }
    // 0x800B177C: nop

    // 0x800B1780: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x800B1784: nop

    // 0x800B1788: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x800B178C: nop

    // 0x800B1790: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800B1794: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B1798: b           L_800B18E0
    // 0x800B179C: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
        goto L_800B18E0;
    // 0x800B179C: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
L_800B17A0:
    // 0x800B17A0: b           L_800B18E0
    // 0x800B17A4: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
        goto L_800B18E0;
    // 0x800B17A4: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
L_800B17A8:
    // 0x800B17A8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B17AC: b           L_800B18E0
    // 0x800B17B0: sb          $t2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r10;
        goto L_800B18E0;
    // 0x800B17B0: sb          $t2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r10;
L_800B17B4:
    // 0x800B17B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B17B8: beq         $v0, $at, L_800B17C8
    if (ctx->r2 == ctx->r1) {
        // 0x800B17BC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800B17C8;
    }
    // 0x800B17BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B17C0: bne         $v0, $at, L_800B18E4
    if (ctx->r2 != ctx->r1) {
        // 0x800B17C4: lb          $t3, 0x23($sp)
        ctx->r11 = MEM_B(ctx->r29, 0X23);
            goto L_800B18E4;
    }
    // 0x800B17C4: lb          $t3, 0x23($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X23);
L_800B17C8:
    // 0x800B17C8: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x800B17CC: nop

    // 0x800B17D0: beq         $v1, $zero, L_800B18E4
    if (ctx->r3 == 0) {
        // 0x800B17D4: lb          $t3, 0x23($sp)
        ctx->r11 = MEM_B(ctx->r29, 0X23);
            goto L_800B18E4;
    }
    // 0x800B17D4: lb          $t3, 0x23($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X23);
    // 0x800B17D8: lh          $a0, 0x4($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X4);
    // 0x800B17DC: jal         0x8007AE74
    // 0x800B17E0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    load_texture(rdram, ctx);
        goto after_11;
    // 0x800B17E0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_11:
    // 0x800B17E4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B17E8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B17EC: beq         $v0, $zero, L_800B18D8
    if (ctx->r2 == 0) {
        // 0x800B17F0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800B18D8;
    }
    // 0x800B17F0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B17F4: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x800B17F8: nop

    // 0x800B17FC: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800B1800: beq         $t5, $zero, L_800B1840
    if (ctx->r13 == 0) {
        // 0x800B1804: nop
    
            goto L_800B1840;
    }
    // 0x800B1804: nop

    // 0x800B1808: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x800B180C: nop

    // 0x800B1810: andi        $t6, $t7, 0x1000
    ctx->r14 = ctx->r15 & 0X1000;
    // 0x800B1814: beq         $t6, $zero, L_800B1830
    if (ctx->r14 == 0) {
        // 0x800B1818: nop
    
            goto L_800B1830;
    }
    // 0x800B1818: nop

    // 0x800B181C: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800B1820: nop

    // 0x800B1824: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800B1828: b           L_800B1840
    // 0x800B182C: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
        goto L_800B1840;
    // 0x800B182C: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
L_800B1830:
    // 0x800B1830: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x800B1834: nop

    // 0x800B1838: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x800B183C: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
L_800B1840:
    // 0x800B1840: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800B1844: nop

    // 0x800B1848: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800B184C: beq         $t5, $zero, L_800B18A0
    if (ctx->r13 == 0) {
        // 0x800B1850: nop
    
            goto L_800B18A0;
    }
    // 0x800B1850: nop

    // 0x800B1854: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800B1858: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B185C: lhu         $a1, 0x12($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X12);
    // 0x800B1860: nop

    // 0x800B1864: sra         $t6, $a1, 8
    ctx->r14 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800B1868: jal         0x8006F94C
    // 0x800B186C: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    rand_range(rdram, ctx);
        goto after_12;
    // 0x800B186C: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    after_12:
    // 0x800B1870: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x800B1874: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1878: sll         $t8, $v0, 8
    ctx->r24 = S32(ctx->r2 << 8);
    // 0x800B187C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1880: andi        $t2, $t9, 0x3
    ctx->r10 = ctx->r25 & 0X3;
    // 0x800B1884: bne         $t2, $at, L_800B18E0
    if (ctx->r10 != ctx->r1) {
        // 0x800B1888: sh          $t8, 0x18($s0)
        MEM_H(0X18, ctx->r16) = ctx->r24;
            goto L_800B18E0;
    }
    // 0x800B1888: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x800B188C: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x800B1890: nop

    // 0x800B1894: ori         $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 | 0XFF;
    // 0x800B1898: b           L_800B18E0
    // 0x800B189C: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
        goto L_800B18E0;
    // 0x800B189C: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
L_800B18A0:
    // 0x800B18A0: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x800B18A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B18A8: andi        $t7, $t5, 0x3
    ctx->r15 = ctx->r13 & 0X3;
    // 0x800B18AC: bne         $t7, $at, L_800B18D0
    if (ctx->r15 != ctx->r1) {
        // 0x800B18B0: nop
    
            goto L_800B18D0;
    }
    // 0x800B18B0: nop

    // 0x800B18B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B18B8: nop

    // 0x800B18BC: lhu         $t8, 0x12($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X12);
    // 0x800B18C0: nop

    // 0x800B18C4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B18C8: b           L_800B18E0
    // 0x800B18CC: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
        goto L_800B18E0;
    // 0x800B18CC: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
L_800B18D0:
    // 0x800B18D0: b           L_800B18E0
    // 0x800B18D4: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
        goto L_800B18E0;
    // 0x800B18D4: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
L_800B18D8:
    // 0x800B18D8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B18DC: sb          $t2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r10;
L_800B18E0:
    // 0x800B18E0: lb          $t3, 0x23($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X23);
L_800B18E4:
    // 0x800B18E4: nop

    // 0x800B18E8: bne         $t3, $zero, L_800B1934
    if (ctx->r11 != 0) {
        // 0x800B18EC: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800B1934;
    }
    // 0x800B18EC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B18F0: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B18F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B18F8: bne         $v0, $at, L_800B1918
    if (ctx->r2 != ctx->r1) {
        // 0x800B18FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B1918;
    }
    // 0x800B18FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1900: jal         0x800AF0A4
    // 0x800B1904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_triangle_texture_coords(rdram, ctx);
        goto after_13;
    // 0x800B1904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800B1908: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B190C: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B1910: nop

    // 0x800B1914: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800B1918:
    // 0x800B1918: bne         $v0, $at, L_800B1934
    if (ctx->r2 != ctx->r1) {
        // 0x800B191C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800B1934;
    }
    // 0x800B191C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B1920: jal         0x800AF0F0
    // 0x800B1924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_rectangle_texture_coords(rdram, ctx);
        goto after_14;
    // 0x800B1924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800B1928: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B192C: nop

    // 0x800B1930: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_800B1934:
    // 0x800B1934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B1938: jal         0x800B03C0
    // 0x800B193C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    setup_particle_position(rdram, ctx);
        goto after_15;
    // 0x800B193C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_15:
    // 0x800B1940: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800B1944: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1948: andi        $t5, $t4, 0x80
    ctx->r13 = ctx->r12 & 0X80;
    // 0x800B194C: beq         $t5, $zero, L_800B197C
    if (ctx->r13 == 0) {
        // 0x800B1950: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_800B197C;
    }
    // 0x800B1950: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B1954: lh          $t7, 0x44($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X44);
    // 0x800B1958: nop

    // 0x800B195C: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x800B1960: lh          $t6, 0x46($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X46);
    // 0x800B1964: nop

    // 0x800B1968: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x800B196C: lh          $t8, 0x48($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X48);
    // 0x800B1970: b           L_800B19C0
    // 0x800B1974: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
        goto L_800B19C0;
    // 0x800B1974: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x800B1978: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_800B197C:
    // 0x800B197C: lh          $t3, 0x44($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X44);
    // 0x800B1980: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x800B1984: nop

    // 0x800B1988: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B198C: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x800B1990: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800B1994: lh          $t6, 0x46($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X46);
    // 0x800B1998: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x800B199C: nop

    // 0x800B19A0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B19A4: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800B19A8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B19AC: lh          $t3, 0x48($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X48);
    // 0x800B19B0: lh          $t2, 0x4($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4);
    // 0x800B19B4: nop

    // 0x800B19B8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B19BC: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
L_800B19C0:
    // 0x800B19C0: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B19C4: nop

    // 0x800B19C8: andi        $t5, $v1, 0x3800
    ctx->r13 = ctx->r3 & 0X3800;
    // 0x800B19CC: beq         $t5, $zero, L_800B1A5C
    if (ctx->r13 == 0) {
        // 0x800B19D0: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_800B1A5C;
    }
    // 0x800B19D0: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800B19D4: andi        $t7, $t5, 0x800
    ctx->r15 = ctx->r13 & 0X800;
    // 0x800B19D8: beq         $t7, $zero, L_800B1A08
    if (ctx->r15 == 0) {
        // 0x800B19DC: andi        $t9, $v1, 0x1000
        ctx->r25 = ctx->r3 & 0X1000;
            goto L_800B1A08;
    }
    // 0x800B19DC: andi        $t9, $v1, 0x1000
    ctx->r25 = ctx->r3 & 0X1000;
    // 0x800B19E0: lh          $a1, 0x80($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X80);
    // 0x800B19E4: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800B19E8: jal         0x8006F94C
    // 0x800B19EC: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_16;
    // 0x800B19EC: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_16:
    // 0x800B19F0: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800B19F4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B19F8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B19FC: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800B1A00: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x800B1A04: andi        $t9, $v1, 0x1000
    ctx->r25 = ctx->r3 & 0X1000;
L_800B1A08:
    // 0x800B1A08: beq         $t9, $zero, L_800B1A38
    if (ctx->r25 == 0) {
        // 0x800B1A0C: andi        $t4, $v1, 0x2000
        ctx->r12 = ctx->r3 & 0X2000;
            goto L_800B1A38;
    }
    // 0x800B1A0C: andi        $t4, $v1, 0x2000
    ctx->r12 = ctx->r3 & 0X2000;
    // 0x800B1A10: lh          $a1, 0x82($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X82);
    // 0x800B1A14: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B1A18: jal         0x8006F94C
    // 0x800B1A1C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_17;
    // 0x800B1A1C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_17:
    // 0x800B1A20: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x800B1A24: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1A28: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1A2C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800B1A30: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x800B1A34: andi        $t4, $v1, 0x2000
    ctx->r12 = ctx->r3 & 0X2000;
L_800B1A38:
    // 0x800B1A38: beq         $t4, $zero, L_800B1A5C
    if (ctx->r12 == 0) {
        // 0x800B1A3C: nop
    
            goto L_800B1A5C;
    }
    // 0x800B1A3C: nop

    // 0x800B1A40: lh          $a1, 0x84($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X84);
    // 0x800B1A44: jal         0x8006F94C
    // 0x800B1A48: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_18;
    // 0x800B1A48: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_18:
    // 0x800B1A4C: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    // 0x800B1A50: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1A54: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800B1A58: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
L_800B1A5C:
    // 0x800B1A5C: lh          $t6, 0x4A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4A);
    // 0x800B1A60: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B1A64: sh          $t6, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r14;
    // 0x800B1A68: lh          $t8, 0x4C($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4C);
    // 0x800B1A6C: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x800B1A70: sh          $t8, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r24;
    // 0x800B1A74: lh          $t9, 0x4E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4E);
    // 0x800B1A78: nop

    // 0x800B1A7C: sh          $t9, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r25;
    // 0x800B1A80: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B1A84: nop

    // 0x800B1A88: and         $t2, $v1, $at
    ctx->r10 = ctx->r3 & ctx->r1;
    // 0x800B1A8C: beq         $t2, $zero, L_800B1B1C
    if (ctx->r10 == 0) {
        // 0x800B1A90: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_800B1B1C;
    }
    // 0x800B1A90: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x800B1A94: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x800B1A98: beq         $t3, $zero, L_800B1AC8
    if (ctx->r11 == 0) {
        // 0x800B1A9C: andi        $t7, $v1, 0x8000
        ctx->r15 = ctx->r3 & 0X8000;
            goto L_800B1AC8;
    }
    // 0x800B1A9C: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x800B1AA0: lh          $a1, 0x86($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X86);
    // 0x800B1AA4: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800B1AA8: jal         0x8006F94C
    // 0x800B1AAC: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_19;
    // 0x800B1AAC: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_19:
    // 0x800B1AB0: lh          $t4, 0x62($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X62);
    // 0x800B1AB4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1AB8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1ABC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800B1AC0: sh          $t5, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r13;
    // 0x800B1AC4: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
L_800B1AC8:
    // 0x800B1AC8: beq         $t7, $zero, L_800B1AF8
    if (ctx->r15 == 0) {
        // 0x800B1ACC: sll         $t9, $v1, 15
        ctx->r25 = S32(ctx->r3 << 15);
            goto L_800B1AF8;
    }
    // 0x800B1ACC: sll         $t9, $v1, 15
    ctx->r25 = S32(ctx->r3 << 15);
    // 0x800B1AD0: lh          $a1, 0x88($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X88);
    // 0x800B1AD4: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B1AD8: jal         0x8006F94C
    // 0x800B1ADC: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_20;
    // 0x800B1ADC: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_20:
    // 0x800B1AE0: lh          $t6, 0x64($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X64);
    // 0x800B1AE4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1AE8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1AEC: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800B1AF0: sh          $t8, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r24;
    // 0x800B1AF4: sll         $t9, $v1, 15
    ctx->r25 = S32(ctx->r3 << 15);
L_800B1AF8:
    // 0x800B1AF8: bgez        $t9, L_800B1B20
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B1AFC: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800B1B20;
    }
    // 0x800B1AFC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B1B00: lh          $a1, 0x8A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X8A);
    // 0x800B1B04: jal         0x8006F94C
    // 0x800B1B08: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_21;
    // 0x800B1B08: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_21:
    // 0x800B1B0C: lh          $t2, 0x66($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X66);
    // 0x800B1B10: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1B14: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800B1B18: sh          $t3, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r11;
L_800B1B1C:
    // 0x800B1B1C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_800B1B20:
    // 0x800B1B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B1B24: jal         0x800B0010
    // 0x800B1B28: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    setup_particle_velocity(rdram, ctx);
        goto after_22;
    // 0x800B1B28: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_22:
    // 0x800B1B2C: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x800B1B30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B1B34: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x800B1B38: andi        $t7, $t5, 0x7
    ctx->r15 = ctx->r13 & 0X7;
    // 0x800B1B3C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800B1B40: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B1B44: lwc1        $f4, 0x2E2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2E2C);
    // 0x800B1B48: lbu         $t8, 0x39($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X39);
    // 0x800B1B4C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1B50: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B1B54: bne         $t8, $at, L_800B1B8C
    if (ctx->r24 != ctx->r1) {
        // 0x800B1B58: swc1        $f4, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
            goto L_800B1B8C;
    }
    // 0x800B1B58: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    // 0x800B1B5C: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B1B60: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B1B64: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B1B68: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B1B6C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B1B70: nop

    // 0x800B1B74: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B1B78: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800B1B7C: jal         0x800C9AD0
    // 0x800B1B80: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_23;
    // 0x800B1B80: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_23:
    // 0x800B1B84: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1B88: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_800B1B8C:
    // 0x800B1B8C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800B1B90: nop

    // 0x800B1B94: andi        $t2, $t9, 0x2
    ctx->r10 = ctx->r25 & 0X2;
    // 0x800B1B98: beq         $t2, $zero, L_800B1C08
    if (ctx->r10 == 0) {
        // 0x800B1B9C: nop
    
            goto L_800B1C08;
    }
    // 0x800B1B9C: nop

    // 0x800B1BA0: lbu         $t3, 0x6($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X6);
    // 0x800B1BA4: nop

    // 0x800B1BA8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B1BAC: sb          $t4, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r12;
    // 0x800B1BB0: lh          $t5, 0x1A($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1A);
    // 0x800B1BB4: andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // 0x800B1BB8: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B1BBC: bne         $at, $zero, L_800B1C08
    if (ctx->r1 != 0) {
        // 0x800B1BC0: nop
    
            goto L_800B1C08;
    }
    // 0x800B1BC0: nop

    // 0x800B1BC4: lh          $t7, 0xC($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XC);
    // 0x800B1BC8: lh          $t6, 0x1C($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1C);
    // 0x800B1BCC: lh          $t9, 0xE($a2)
    ctx->r25 = MEM_H(ctx->r6, 0XE);
    // 0x800B1BD0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B1BD4: sh          $t8, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r24;
    // 0x800B1BD8: lh          $t2, 0x1E($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1E);
    // 0x800B1BDC: lh          $t4, 0x10($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X10);
    // 0x800B1BE0: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800B1BE4: sh          $t3, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r11;
    // 0x800B1BE8: lh          $t5, 0x18($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X18);
    // 0x800B1BEC: nop

    // 0x800B1BF0: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800B1BF4: sh          $t7, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r15;
    // 0x800B1BF8: lh          $t6, 0x1A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1A);
    // 0x800B1BFC: nop

    // 0x800B1C00: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x800B1C04: sb          $t8, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r24;
L_800B1C08:
    // 0x800B1C08: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800B1C0C: nop

    // 0x800B1C10: andi        $t2, $t9, 0x8
    ctx->r10 = ctx->r25 & 0X8;
    // 0x800B1C14: beq         $t2, $zero, L_800B1C84
    if (ctx->r10 == 0) {
        // 0x800B1C18: nop
    
            goto L_800B1C84;
    }
    // 0x800B1C18: nop

    // 0x800B1C1C: lbu         $t3, 0x7($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X7);
    // 0x800B1C20: nop

    // 0x800B1C24: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B1C28: sb          $t4, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r12;
    // 0x800B1C2C: lh          $t5, 0x28($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X28);
    // 0x800B1C30: andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // 0x800B1C34: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B1C38: bne         $at, $zero, L_800B1C84
    if (ctx->r1 != 0) {
        // 0x800B1C3C: nop
    
            goto L_800B1C84;
    }
    // 0x800B1C3C: nop

    // 0x800B1C40: lh          $t7, 0x12($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X12);
    // 0x800B1C44: lh          $t6, 0x2A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2A);
    // 0x800B1C48: lh          $t9, 0x14($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X14);
    // 0x800B1C4C: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B1C50: sh          $t8, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r24;
    // 0x800B1C54: lh          $t2, 0x2C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2C);
    // 0x800B1C58: lh          $t4, 0x16($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X16);
    // 0x800B1C5C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800B1C60: sh          $t3, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r11;
    // 0x800B1C64: lh          $t5, 0x2E($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2E);
    // 0x800B1C68: nop

    // 0x800B1C6C: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800B1C70: sh          $t7, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r15;
    // 0x800B1C74: lh          $t6, 0x28($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X28);
    // 0x800B1C78: nop

    // 0x800B1C7C: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x800B1C80: sb          $t8, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r24;
L_800B1C84:
    // 0x800B1C84: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800B1C88: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B1C8C: bne         $t9, $zero, L_800B1CA4
    if (ctx->r25 != 0) {
        // 0x800B1C90: nop
    
            goto L_800B1CA4;
    }
    // 0x800B1C90: nop

    // 0x800B1C94: jal         0x800B2040
    // 0x800B1C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    particle_deallocate(rdram, ctx);
        goto after_24;
    // 0x800B1C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x800B1C9C: b           L_800B1CA4
    // 0x800B1CA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B1CA4;
    // 0x800B1CA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B1CA4:
    // 0x800B1CA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1CA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B1CAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B1CB0: jr          $ra
    // 0x800B1CB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B1CB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void racer_sound_car(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005254: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80005258: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000525C: lw          $t0, -0x63C4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63C4);
    // 0x80005260: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80005264: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80005268: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000526C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80005270: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80005274: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80005278: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8000527C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80005280: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80005284: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80005288: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8000528C: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x80005290: lb          $t6, 0x1FB($t0)
    ctx->r14 = MEM_B(ctx->r8, 0X1FB);
    // 0x80005294: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80005298: beq         $t6, $zero, L_800052B0
    if (ctx->r14 == 0) {
        // 0x8000529C: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800052B0;
    }
    // 0x8000529C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800052A0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800052A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800052A8: b           L_800052BC
    // 0x800052AC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
        goto L_800052BC;
    // 0x800052AC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_800052B0:
    // 0x800052B0: lwc1        $f0, 0x2C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x800052B4: nop

    // 0x800052B8: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_800052BC:
    // 0x800052BC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800052C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800052C4: bc1f        L_800052D0
    if (!c1cs) {
        // 0x800052C8: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800052D0;
    }
    // 0x800052C8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800052CC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800052D0:
    // 0x800052D0: nop

    // 0x800052D4: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800052D8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800052DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800052E0: lw          $s2, 0xA8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA8);
    // 0x800052E4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800052E8: andi        $t8, $s2, 0x8000
    ctx->r24 = ctx->r18 & 0X8000;
    // 0x800052EC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800052F0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800052F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800052F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800052FC: nop

    // 0x80005300: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80005304: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80005308: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000530C: nop

    // 0x80005310: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80005314: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80005318: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000531C: addiu       $s0, $v0, 0x5
    ctx->r16 = ADD32(ctx->r2, 0X5);
    // 0x80005320: slti        $at, $s0, 0x65
    ctx->r1 = SIGNED(ctx->r16) < 0X65 ? 1 : 0;
    // 0x80005324: bne         $at, $zero, L_80005330
    if (ctx->r1 != 0) {
        // 0x80005328: nop
    
            goto L_80005330;
    }
    // 0x80005328: nop

    // 0x8000532C: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
L_80005330:
    // 0x80005330: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005334: lwc1        $f21, 0x4BF8($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X4BF8);
    // 0x80005338: lwc1        $f20, 0x4BFC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X4BFC);
    // 0x8000533C: lw          $a3, -0x63C8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X63C8);
    // 0x80005340: addiu       $s1, $s1, -0x63C8
    ctx->r17 = ADD32(ctx->r17, -0X63C8);
L_80005344:
    // 0x80005344: addu        $t9, $a3, $t4
    ctx->r25 = ADD32(ctx->r7, ctx->r12);
    // 0x80005348: lhu         $t5, 0x0($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X0);
    // 0x8000534C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80005350: beq         $t5, $zero, L_80005A0C
    if (ctx->r13 == 0) {
        // 0x80005354: addu        $t6, $t6, $t1
        ctx->r14 = ADD32(ctx->r14, ctx->r9);
            goto L_80005A0C;
    }
    // 0x80005354: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x80005358: addu        $t0, $a3, $t6
    ctx->r8 = ADD32(ctx->r7, ctx->r14);
    // 0x8000535C: lbu         $t7, 0xE($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XE);
    // 0x80005360: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80005364: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80005368: bne         $at, $zero, L_8000538C
    if (ctx->r1 != 0) {
        // 0x8000536C: sll         $t2, $t1, 2
        ctx->r10 = S32(ctx->r9 << 2);
            goto L_8000538C;
    }
    // 0x8000536C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80005370: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80005374: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x80005378: addu        $a2, $a3, $t8
    ctx->r6 = ADD32(ctx->r7, ctx->r24);
    // 0x8000537C: lbu         $t9, 0xF($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XF);
    // 0x80005380: nop

    // 0x80005384: slt         $at, $t9, $s0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80005388: beq         $at, $zero, L_800053CC
    if (ctx->r1 == 0) {
        // 0x8000538C: sll         $t5, $t1, 2
        ctx->r13 = S32(ctx->r9 << 2);
            goto L_800053CC;
    }
L_8000538C:
    // 0x8000538C: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80005390: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80005394: addu        $a2, $a3, $t5
    ctx->r6 = ADD32(ctx->r7, ctx->r13);
    // 0x80005398: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
L_8000539C:
    // 0x8000539C: lbu         $t6, 0xF($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF);
    // 0x800053A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800053A4: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800053A8: bne         $at, $zero, L_800053C0
    if (ctx->r1 != 0) {
        // 0x800053AC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800053C0;
    }
    // 0x800053AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800053B0: lbu         $t7, 0xF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF);
    // 0x800053B4: nop

    // 0x800053B8: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800053BC: beq         $at, $zero, L_800053CC
    if (ctx->r1 == 0) {
        // 0x800053C0: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800053CC;
    }
L_800053C0:
    // 0x800053C0: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800053C4: bne         $at, $zero, L_8000539C
    if (ctx->r1 != 0) {
        // 0x800053C8: nop
    
            goto L_8000539C;
    }
    // 0x800053C8: nop

L_800053CC:
    // 0x800053CC: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x800053D0: lbu         $a0, 0xE($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XE);
    // 0x800053D4: lbu         $t9, 0xF($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XF);
    // 0x800053D8: subu        $t8, $s0, $a0
    ctx->r24 = SUB32(ctx->r16, ctx->r4);
    // 0x800053DC: subu        $t5, $t9, $a0
    ctx->r13 = SUB32(ctx->r25, ctx->r4);
    // 0x800053E0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800053E4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800053E8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800053EC: lbu         $a1, 0x2C($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X2C);
    // 0x800053F0: lbu         $t6, 0x2D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2D);
    // 0x800053F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800053F8: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x800053FC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80005400: div.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80005404: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005408: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8000540C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80005410: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005414: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80005418: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000541C: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80005420: bgez        $a1, L_80005434
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80005424: nop
    
            goto L_80005434;
    }
    // 0x80005424: nop

    // 0x80005428: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000542C: nop

    // 0x80005430: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80005434:
    // 0x80005434: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80005438: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000543C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80005440: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80005444: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80005448: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000544C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80005450: nop

    // 0x80005454: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80005458: beq         $t3, $zero, L_800054A4
    if (ctx->r11 == 0) {
        // 0x8000545C: nop
    
            goto L_800054A4;
    }
    // 0x8000545C: nop

    // 0x80005460: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80005464: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80005468: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000546C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80005470: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80005474: nop

    // 0x80005478: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000547C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80005480: nop

    // 0x80005484: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80005488: bne         $t3, $zero, L_8000549C
    if (ctx->r11 != 0) {
        // 0x8000548C: nop
    
            goto L_8000549C;
    }
    // 0x8000548C: nop

    // 0x80005490: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80005494: b           L_800054B4
    // 0x80005498: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800054B4;
    // 0x80005498: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_8000549C:
    // 0x8000549C: b           L_800054B4
    // 0x800054A0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800054B4;
    // 0x800054A0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800054A4:
    // 0x800054A4: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800054A8: nop

    // 0x800054AC: bltz        $t3, L_8000549C
    if (SIGNED(ctx->r11) < 0) {
        // 0x800054B0: nop
    
            goto L_8000549C;
    }
    // 0x800054B0: nop

L_800054B4:
    // 0x800054B4: lbu         $t5, 0x4($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X4);
    // 0x800054B8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800054BC: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800054C0: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800054C4: bne         $at, $zero, L_800054E0
    if (ctx->r1 != 0) {
        // 0x800054C8: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_800054E0;
    }
    // 0x800054C8: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x800054CC: lbu         $t6, 0x5($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X5);
    // 0x800054D0: nop

    // 0x800054D4: slt         $at, $t6, $s0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800054D8: beq         $at, $zero, L_80005510
    if (ctx->r1 == 0) {
        // 0x800054DC: nop
    
            goto L_80005510;
    }
    // 0x800054DC: nop

L_800054E0:
    // 0x800054E0: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    // 0x800054E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800054E8: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800054EC: bne         $at, $zero, L_80005504
    if (ctx->r1 != 0) {
        // 0x800054F0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80005504;
    }
    // 0x800054F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800054F4: lbu         $t8, 0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5);
    // 0x800054F8: nop

    // 0x800054FC: slt         $at, $t8, $s0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80005500: beq         $at, $zero, L_80005510
    if (ctx->r1 == 0) {
        // 0x80005504: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80005510;
    }
L_80005504:
    // 0x80005504: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80005508: bne         $at, $zero, L_800054E0
    if (ctx->r1 != 0) {
        // 0x8000550C: nop
    
            goto L_800054E0;
    }
    // 0x8000550C: nop

L_80005510:
    // 0x80005510: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80005514: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    // 0x80005518: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8000551C: lbu         $t5, 0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X5);
    // 0x80005520: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80005524: subu        $t9, $s0, $a0
    ctx->r25 = SUB32(ctx->r16, ctx->r4);
    // 0x80005528: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8000552C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80005530: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80005534: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x80005538: subu        $t6, $t5, $a0
    ctx->r14 = SUB32(ctx->r13, ctx->r4);
    // 0x8000553C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80005540: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80005544: lhu         $t5, 0x18($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X18);
    // 0x80005548: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000554C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80005550: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005554: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80005558: lwc1        $f0, 0x4C00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4C00);
    // 0x8000555C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005560: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80005564: bgez        $t5, L_80005578
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80005568: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80005578;
    }
    // 0x80005568: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000556C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005570: nop

    // 0x80005574: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80005578:
    // 0x80005578: lhu         $t6, 0x1A($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X1A);
    // 0x8000557C: div.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80005580: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80005584: bgez        $t6, L_8000559C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80005588: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8000559C;
    }
    // 0x80005588: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000558C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005590: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005594: nop

    // 0x80005598: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8000559C:
    // 0x8000559C: slti        $at, $s0, 0x33
    ctx->r1 = SIGNED(ctx->r16) < 0X33 ? 1 : 0;
    // 0x800055A0: bne         $at, $zero, L_8000567C
    if (ctx->r1 != 0) {
        // 0x800055A4: div.s       $f18, $f8, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
            goto L_8000567C;
    }
    // 0x800055A4: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800055A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800055AC: lw          $t0, -0x63C4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63C4);
    // 0x800055B0: nop

    // 0x800055B4: lb          $v0, 0x185($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X185);
    // 0x800055B8: nop

    // 0x800055BC: beq         $v0, $zero, L_8000567C
    if (ctx->r2 == 0) {
        // 0x800055C0: slti        $at, $v0, 0xB
        ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
            goto L_8000567C;
    }
    // 0x800055C0: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x800055C4: beq         $at, $zero, L_800055D4
    if (ctx->r1 == 0) {
        // 0x800055C8: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800055D4;
    }
    // 0x800055C8: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800055CC: b           L_800055D4
    // 0x800055D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800055D4;
    // 0x800055D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800055D4:
    // 0x800055D4: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800055D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800055DC: cvt.d.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
    // 0x800055E0: lwc1        $f5, 0x4C08($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X4C08);
    // 0x800055E4: lwc1        $f4, 0x4C0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4C0C);
    // 0x800055E8: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x800055EC: mul.d       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800055F0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800055F4: sll         $t7, $v1, 6
    ctx->r15 = S32(ctx->r3 << 6);
    // 0x800055F8: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x800055FC: nop

    // 0x80005600: bc1f        L_8000563C
    if (!c1cs) {
        // 0x80005604: nop
    
            goto L_8000563C;
    }
    // 0x80005604: nop

    // 0x80005608: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8000560C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80005610: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80005614: nop

    // 0x80005618: div.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x8000561C: add.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d + ctx->f4.d;
    // 0x80005620: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80005624: swc1        $f8, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f8.u32l;
    // 0x80005628: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000562C: lw          $t0, -0x63C4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63C4);
    // 0x80005630: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80005634: b           L_8000566C
    // 0x80005638: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
        goto L_8000566C;
    // 0x80005638: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
L_8000563C:
    // 0x8000563C: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80005640: nop

    // 0x80005644: bc1f        L_80005668
    if (!c1cs) {
        // 0x80005648: nop
    
            goto L_80005668;
    }
    // 0x80005648: nop

    // 0x8000564C: cvt.s.d     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f10.fl = CVT_S_D(ctx->f0.d);
    // 0x80005650: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80005654: swc1        $f10, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f10.u32l;
    // 0x80005658: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000565C: lw          $t0, -0x63C4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63C4);
    // 0x80005660: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80005664: nop

L_80005668:
    // 0x80005668: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
L_8000566C:
    // 0x8000566C: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80005670: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80005674: b           L_800056C0
    // 0x80005678: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
        goto L_800056C0;
    // 0x80005678: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
L_8000567C:
    // 0x8000567C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005680: lwc1        $f10, 0x3C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80005684: lwc1        $f7, 0x4C10($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X4C10);
    // 0x80005688: lwc1        $f6, 0x4C14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4C14);
    // 0x8000568C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80005690: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80005694: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80005698: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000569C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800056A0: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800056A4: swc1        $f10, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f10.u32l;
    // 0x800056A8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800056AC: lw          $t0, -0x63C4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63C4);
    // 0x800056B0: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800056B4: lwc1        $f10, 0x3C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x800056B8: nop

    // 0x800056BC: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
L_800056C0:
    // 0x800056C0: lb          $t8, 0x1E6($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X1E6);
    // 0x800056C4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800056C8: beq         $t8, $zero, L_8000570C
    if (ctx->r24 == 0) {
        // 0x800056CC: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8000570C;
    }
    // 0x800056CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800056D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800056D4: lwc1        $f7, 0x4C18($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X4C18);
    // 0x800056D8: lwc1        $f6, 0x4C1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4C1C);
    // 0x800056DC: lwc1        $f4, 0x40($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X40);
    // 0x800056E0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800056E4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800056E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800056EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800056F0: sub.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d - ctx->f0.d;
    // 0x800056F4: nop

    // 0x800056F8: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800056FC: add.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d + ctx->f4.d;
    // 0x80005700: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80005704: b           L_80005720
    // 0x80005708: swc1        $f8, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f8.u32l;
        goto L_80005720;
    // 0x80005708: swc1        $f8, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f8.u32l;
L_8000570C:
    // 0x8000570C: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x80005710: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80005714: nop

    // 0x80005718: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000571C: swc1        $f6, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f6.u32l;
L_80005720:
    // 0x80005720: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005724: lw          $t0, -0x63C4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63C4);
    // 0x80005728: lwc1        $f8, 0x40($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8000572C: lb          $t9, 0x1E2($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1E2);
    // 0x80005730: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x80005734: bne         $t9, $zero, L_80005760
    if (ctx->r25 != 0) {
        // 0x80005738: add.s       $f2, $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
            goto L_80005760;
    }
    // 0x80005738: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8000573C: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x80005740: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80005744: beq         $t5, $at, L_80005760
    if (ctx->r13 == ctx->r1) {
        // 0x80005748: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80005760;
    }
    // 0x80005748: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000574C: lwc1        $f5, 0x4C20($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X4C20);
    // 0x80005750: lwc1        $f4, 0x4C24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4C24);
    // 0x80005754: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80005758: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8000575C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
L_80005760:
    // 0x80005760: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80005764: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80005768: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000576C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80005770: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80005774: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005778: div.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000577C: bgez        $t3, L_80005790
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80005780: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80005790;
    }
    // 0x80005780: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005784: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80005788: nop

    // 0x8000578C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80005790:
    // 0x80005790: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80005794: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80005798: lwc1        $f4, 0x54($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8000579C: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800057A0: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800057A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800057A8: beq         $t6, $at, L_800058B4
    if (ctx->r14 == ctx->r1) {
        // 0x800057AC: div.s       $f14, $f6, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
            goto L_800058B4;
    }
    // 0x800057AC: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800057B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800057B4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800057B8: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800057BC: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800057C0: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x800057C4: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x800057C8: jal         0x8006F94C
    // 0x800057CC: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800057CC: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800057D0: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800057D4: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800057D8: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800057DC: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800057E0: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800057E4: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x800057E8: beq         $at, $zero, L_80005868
    if (ctx->r1 == 0) {
        // 0x800057EC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80005868;
    }
    // 0x800057EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800057F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800057F4: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800057F8: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800057FC: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x80005800: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x80005804: jal         0x8006F94C
    // 0x80005808: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    rand_range(rdram, ctx);
        goto after_1;
    // 0x80005808: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8000580C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005810: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80005814: lb          $t7, 0x90($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X90);
    // 0x80005818: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000581C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80005820: addiu       $t9, $t8, -0x5
    ctx->r25 = ADD32(ctx->r24, -0X5);
    // 0x80005824: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80005828: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000582C: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80005830: sb          $t9, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r25;
    // 0x80005834: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005838: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8000583C: lb          $v1, 0x90($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X90);
    // 0x80005840: nop

    // 0x80005844: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80005848: bne         $at, $zero, L_8000585C
    if (ctx->r1 != 0) {
        // 0x8000584C: slti        $at, $v1, -0x5
        ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
            goto L_8000585C;
    }
    // 0x8000584C: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
    // 0x80005850: b           L_80005868
    // 0x80005854: sb          $t5, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r13;
        goto L_80005868;
    // 0x80005854: sb          $t5, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r13;
    // 0x80005858: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
L_8000585C:
    // 0x8000585C: beq         $at, $zero, L_80005868
    if (ctx->r1 == 0) {
        // 0x80005860: addiu       $t6, $zero, -0x5
        ctx->r14 = ADD32(0, -0X5);
            goto L_80005868;
    }
    // 0x80005860: addiu       $t6, $zero, -0x5
    ctx->r14 = ADD32(0, -0X5);
    // 0x80005864: sb          $t6, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r14;
L_80005868:
    // 0x80005868: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000586C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80005870: lb          $t7, 0x90($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X90);
    // 0x80005874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005878: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8000587C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005880: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80005884: lwc1        $f11, 0x4C28($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X4C28);
    // 0x80005888: lwc1        $f10, 0x4C2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4C2C);
    // 0x8000588C: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80005890: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80005894: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80005898: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8000589C: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x800058A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800058A4: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x800058A8: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800058AC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x800058B0: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
L_800058B4:
    // 0x800058B4: beq         $s2, $zero, L_8000593C
    if (ctx->r18 == 0) {
        // 0x800058B8: nop
    
            goto L_8000593C;
    }
    // 0x800058B8: nop

    // 0x800058BC: lwc1        $f4, 0x94($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X94);
    // 0x800058C0: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800058C4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800058C8: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
    // 0x800058CC: nop

    // 0x800058D0: bc1f        L_8000593C
    if (!c1cs) {
        // 0x800058D4: nop
    
            goto L_8000593C;
    }
    // 0x800058D4: nop

    // 0x800058D8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800058DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800058E0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800058E4: lwc1        $f5, 0x4C30($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X4C30);
    // 0x800058E8: lwc1        $f4, 0x4C34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4C34);
    // 0x800058EC: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800058F0: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800058F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800058F8: add.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f0.d + ctx->f10.d;
    // 0x800058FC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80005900: swc1        $f6, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f6.u32l;
    // 0x80005904: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005908: nop

    // 0x8000590C: lwc1        $f4, 0x94($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80005910: nop

    // 0x80005914: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80005918: c.lt.d      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.d < ctx->f10.d;
    // 0x8000591C: nop

    // 0x80005920: bc1f        L_8000593C
    if (!c1cs) {
        // 0x80005924: nop
    
            goto L_8000593C;
    }
    // 0x80005924: nop

    // 0x80005928: lwc1        $f8, 0x4C38($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C38);
    // 0x8000592C: nop

    // 0x80005930: swc1        $f8, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f8.u32l;
    // 0x80005934: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005938: nop

L_8000593C:
    // 0x8000593C: bne         $s2, $zero, L_800059B8
    if (ctx->r18 != 0) {
        // 0x80005940: addu        $v0, $a3, $t2
        ctx->r2 = ADD32(ctx->r7, ctx->r10);
            goto L_800059B8;
    }
    // 0x80005940: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x80005944: lwc1        $f0, 0x94($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80005948: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x8000594C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80005950: nop

    // 0x80005954: bc1f        L_800059B8
    if (!c1cs) {
        // 0x80005958: addu        $v0, $a3, $t2
        ctx->r2 = ADD32(ctx->r7, ctx->r10);
            goto L_800059B8;
    }
    // 0x80005958: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x8000595C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80005960: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005964: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005968: lwc1        $f9, 0x4C40($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X4C40);
    // 0x8000596C: lwc1        $f8, 0x4C44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C44);
    // 0x80005970: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80005974: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80005978: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8000597C: sub.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d - ctx->f6.d;
    // 0x80005980: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80005984: swc1        $f8, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f8.u32l;
    // 0x80005988: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000598C: nop

    // 0x80005990: lwc1        $f4, 0x94($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80005994: nop

    // 0x80005998: c.lt.s      $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f4.fl < ctx->f22.fl;
    // 0x8000599C: nop

    // 0x800059A0: bc1f        L_800059B8
    if (!c1cs) {
        // 0x800059A4: addu        $v0, $a3, $t2
        ctx->r2 = ADD32(ctx->r7, ctx->r10);
            goto L_800059B8;
    }
    // 0x800059A4: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x800059A8: swc1        $f22, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f22.u32l;
    // 0x800059AC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800059B0: nop

    // 0x800059B4: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
L_800059B8:
    // 0x800059B8: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x800059BC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800059C0: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800059C4: beq         $s2, $zero, L_800059F4
    if (ctx->r18 == 0) {
        // 0x800059C8: swc1        $f10, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
            goto L_800059F4;
    }
    // 0x800059C8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x800059CC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800059D0: nop

    // 0x800059D4: addu        $v0, $t5, $t2
    ctx->r2 = ADD32(ctx->r13, ctx->r10);
    // 0x800059D8: lwc1        $f8, 0x54($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800059DC: nop

    // 0x800059E0: add.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800059E4: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
    // 0x800059E8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800059EC: b           L_80005A10
    // 0x800059F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
        goto L_80005A10;
    // 0x800059F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800059F4:
    // 0x800059F4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800059F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800059FC: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x80005A00: swc1        $f6, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->f6.u32l;
    // 0x80005A04: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005A08: nop

L_80005A0C:
    // 0x80005A0C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80005A10:
    // 0x80005A10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005A14: bne         $t1, $at, L_80005344
    if (ctx->r9 != ctx->r1) {
        // 0x80005A18: addiu       $t4, $t4, 0x2
        ctx->r12 = ADD32(ctx->r12, 0X2);
            goto L_80005344;
    }
    // 0x80005A18: addiu       $t4, $t4, 0x2
    ctx->r12 = ADD32(ctx->r12, 0X2);
    // 0x80005A1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80005A20: lw          $t0, -0x63C4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63C4);
    // 0x80005A24: nop

    // 0x80005A28: lw          $t8, 0x10($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X10);
    // 0x80005A2C: nop

    // 0x80005A30: bne         $t8, $zero, L_80005A80
    if (ctx->r24 != 0) {
        // 0x80005A34: nop
    
            goto L_80005A80;
    }
    // 0x80005A34: nop

    // 0x80005A38: lw          $t9, 0x14($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X14);
    // 0x80005A3C: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x80005A40: bne         $t9, $zero, L_80005A80
    if (ctx->r25 != 0) {
        // 0x80005A44: andi        $t6, $t5, 0x4000
        ctx->r14 = ctx->r13 & 0X4000;
            goto L_80005A80;
    }
    // 0x80005A44: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x80005A48: beq         $t6, $zero, L_80005A80
    if (ctx->r14 == 0) {
        // 0x80005A4C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80005A80;
    }
    // 0x80005A4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005A50: lwc1        $f8, 0x2C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80005A54: lwc1        $f11, 0x4C48($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X4C48);
    // 0x80005A58: lwc1        $f10, 0x4C4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4C4C);
    // 0x80005A5C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80005A60: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x80005A64: nop

    // 0x80005A68: bc1t        L_80005A80
    if (c1cs) {
        // 0x80005A6C: nop
    
            goto L_80005A80;
    }
    // 0x80005A6C: nop

    // 0x80005A70: lb          $t7, 0x1D6($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X1D6);
    // 0x80005A74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80005A78: bne         $t7, $at, L_80005ABC
    if (ctx->r15 != ctx->r1) {
        // 0x80005A7C: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_80005ABC;
    }
    // 0x80005A7C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80005A80:
    // 0x80005A80: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005A84: nop

    // 0x80005A88: beq         $a0, $zero, L_80005ABC
    if (ctx->r4 == 0) {
        // 0x80005A8C: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_80005ABC;
    }
    // 0x80005A8C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80005A90: jal         0x8000488C
    // 0x80005A94: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x80005A94: nop

    after_2:
    // 0x80005A98: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80005A9C: nop

    // 0x80005AA0: sw          $zero, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = 0;
    // 0x80005AA4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005AA8: nop

    // 0x80005AAC: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005AB0: b           L_80005BA0
    // 0x80005AB4: nop

        goto L_80005BA0;
    // 0x80005AB4: nop

    // 0x80005AB8: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80005ABC:
    // 0x80005ABC: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005AC0: andi        $t5, $t9, 0x4000
    ctx->r13 = ctx->r25 & 0X4000;
    // 0x80005AC4: beq         $t5, $zero, L_80005BA0
    if (ctx->r13 == 0) {
        // 0x80005AC8: nop
    
            goto L_80005BA0;
    }
    // 0x80005AC8: nop

    // 0x80005ACC: bne         $a0, $zero, L_80005BA0
    if (ctx->r4 != 0) {
        // 0x80005AD0: nop
    
            goto L_80005BA0;
    }
    // 0x80005AD0: nop

    // 0x80005AD4: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x80005AD8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80005ADC: bltz        $t6, L_80005BA0
    if (SIGNED(ctx->r14) < 0) {
        // 0x80005AE0: addiu       $a1, $a3, 0xA8
        ctx->r5 = ADD32(ctx->r7, 0XA8);
            goto L_80005BA0;
    }
    // 0x80005AE0: addiu       $a1, $a3, 0xA8
    ctx->r5 = ADD32(ctx->r7, 0XA8);
    // 0x80005AE4: lwc1        $f0, 0x2C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80005AE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005AEC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80005AF0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80005AF4: bc1f        L_80005B04
    if (!c1cs) {
        // 0x80005AF8: nop
    
            goto L_80005B04;
    }
    // 0x80005AF8: nop

    // 0x80005AFC: b           L_80005B08
    // 0x80005B00: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
        goto L_80005B08;
    // 0x80005B00: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_80005B04:
    // 0x80005B04: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80005B08:
    // 0x80005B08: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x80005B0C: nop

    // 0x80005B10: bc1f        L_80005B20
    if (!c1cs) {
        // 0x80005B14: nop
    
            goto L_80005B20;
    }
    // 0x80005B14: nop

    // 0x80005B18: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80005B1C: nop

L_80005B20:
    // 0x80005B20: jal         0x80001F14
    // 0x80005B24: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    sound_play_direct(rdram, ctx);
        goto after_3;
    // 0x80005B24: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_3:
    // 0x80005B28: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80005B2C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80005B30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80005B34: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x80005B38: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80005B3C: lui         $at, 0x4028
    ctx->r1 = S32(0X4028 << 16);
    // 0x80005B40: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80005B44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80005B48: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005B4C: div.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x80005B50: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x80005B54: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80005B58: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x80005B5C: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005B60: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80005B64: beq         $a0, $zero, L_80005B80
    if (ctx->r4 == 0) {
        // 0x80005B68: addiu       $t7, $zero, 0x6E
        ctx->r15 = ADD32(0, 0X6E);
            goto L_80005B80;
    }
    // 0x80005B68: addiu       $t7, $zero, 0x6E
    ctx->r15 = ADD32(0, 0X6E);
    // 0x80005B6C: jal         0x800049F8
    // 0x80005B70: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_4;
    // 0x80005B70: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x80005B74: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005B78: nop

    // 0x80005B7C: addiu       $t7, $zero, 0x6E
    ctx->r15 = ADD32(0, 0X6E);
L_80005B80:
    // 0x80005B80: sh          $t7, 0xAC($a3)
    MEM_H(0XAC, ctx->r7) = ctx->r15;
    // 0x80005B84: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80005B88: nop

    // 0x80005B8C: sb          $zero, 0xD0($t8)
    MEM_B(0XD0, ctx->r24) = 0;
    // 0x80005B90: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005B94: nop

    // 0x80005B98: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005B9C: nop

L_80005BA0:
    // 0x80005BA0: beq         $a0, $zero, L_80005C48
    if (ctx->r4 == 0) {
        // 0x80005BA4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80005C48;
    }
    // 0x80005BA4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80005BA8: lw          $t9, -0x63C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X63C4);
    // 0x80005BAC: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80005BB0: lb          $t5, 0x1E2($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X1E2);
    // 0x80005BB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80005BB8: bne         $t5, $zero, L_80005BD4
    if (ctx->r13 != 0) {
        // 0x80005BBC: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80005BD4;
    }
    // 0x80005BBC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80005BC0: lbu         $t6, 0xD0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD0);
    // 0x80005BC4: nop

    // 0x80005BC8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80005BCC: b           L_80005BD8
    // 0x80005BD0: sb          $t8, 0xD0($a3)
    MEM_B(0XD0, ctx->r7) = ctx->r24;
        goto L_80005BD8;
    // 0x80005BD0: sb          $t8, 0xD0($a3)
    MEM_B(0XD0, ctx->r7) = ctx->r24;
L_80005BD4:
    // 0x80005BD4: sb          $zero, 0xD0($a3)
    MEM_B(0XD0, ctx->r7) = 0;
L_80005BD8:
    // 0x80005BD8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005BDC: nop

    // 0x80005BE0: lbu         $t9, 0xD0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XD0);
    // 0x80005BE4: nop

    // 0x80005BE8: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x80005BEC: bne         $at, $zero, L_80005C0C
    if (ctx->r1 != 0) {
        // 0x80005BF0: nop
    
            goto L_80005C0C;
    }
    // 0x80005BF0: nop

    // 0x80005BF4: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005BF8: jal         0x800049F8
    // 0x80005BFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80005BFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x80005C00: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005C04: b           L_80005C48
    // 0x80005C08: nop

        goto L_80005C48;
    // 0x80005C08: nop

L_80005C0C:
    // 0x80005C0C: lhu         $a2, 0xAC($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0XAC);
    // 0x80005C10: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005C14: sll         $t5, $a2, 8
    ctx->r13 = S32(ctx->r6 << 8);
    // 0x80005C18: jal         0x800049F8
    // 0x80005C1C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    sndp_set_param(rdram, ctx);
        goto after_6;
    // 0x80005C1C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    after_6:
    // 0x80005C20: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80005C24: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80005C28: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    // 0x80005C2C: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x80005C30: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x80005C34: lw          $a0, 0xA8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XA8);
    // 0x80005C38: jal         0x80009B7C
    // 0x80005C3C: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_7;
    // 0x80005C3C: nop

    after_7:
    // 0x80005C40: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005C44: nop

L_80005C48:
    // 0x80005C48: beq         $s2, $zero, L_80005CE0
    if (ctx->r18 == 0) {
        // 0x80005C4C: sb          $s0, 0xA0($a3)
        MEM_B(0XA0, ctx->r7) = ctx->r16;
            goto L_80005CE0;
    }
    // 0x80005C4C: sb          $s0, 0xA0($a3)
    MEM_B(0XA0, ctx->r7) = ctx->r16;
    // 0x80005C50: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005C54: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80005C58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80005C5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80005C60: lwc1        $f4, 0x54($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X54);
    // 0x80005C64: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80005C68: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80005C6C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80005C70: nop

    // 0x80005C74: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80005C78: beq         $t9, $zero, L_80005CC4
    if (ctx->r25 == 0) {
        // 0x80005C7C: nop
    
            goto L_80005CC4;
    }
    // 0x80005C7C: nop

    // 0x80005C80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005C84: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80005C88: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005C8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80005C90: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80005C94: nop

    // 0x80005C98: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80005C9C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80005CA0: nop

    // 0x80005CA4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80005CA8: bne         $t9, $zero, L_80005CBC
    if (ctx->r25 != 0) {
        // 0x80005CAC: nop
    
            goto L_80005CBC;
    }
    // 0x80005CAC: nop

    // 0x80005CB0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80005CB4: b           L_80005CD4
    // 0x80005CB8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80005CD4;
    // 0x80005CB8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80005CBC:
    // 0x80005CBC: b           L_80005CD4
    // 0x80005CC0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80005CD4;
    // 0x80005CC0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80005CC4:
    // 0x80005CC4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80005CC8: nop

    // 0x80005CCC: bltz        $t9, L_80005CBC
    if (SIGNED(ctx->r25) < 0) {
        // 0x80005CD0: nop
    
            goto L_80005CBC;
    }
    // 0x80005CD0: nop

L_80005CD4:
    // 0x80005CD4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80005CD8: sb          $t9, 0x98($a3)
    MEM_B(0X98, ctx->r7) = ctx->r25;
    // 0x80005CDC: nop

L_80005CE0:
    // 0x80005CE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80005CE4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80005CE8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005CEC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80005CF0: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005CF4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80005CF8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80005CFC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80005D00: jr          $ra
    // 0x80005D04: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80005D04: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void delete_point_particle_from_sequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B263C: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x800B2640: nop

    // 0x800B2644: beq         $v0, $zero, L_800B26D8
    if (ctx->r2 == 0) {
        // 0x800B2648: nop
    
            goto L_800B26D8;
    }
    // 0x800B2648: nop

    // 0x800B264C: lbu         $v1, 0x6($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X6);
    // 0x800B2650: nop

    // 0x800B2654: beq         $v1, $zero, L_800B26D8
    if (ctx->r3 == 0) {
        // 0x800B2658: nop
    
            goto L_800B26D8;
    }
    // 0x800B2658: nop

    // 0x800B265C: lbu         $t7, 0x74($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X74);
    // 0x800B2660: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800B2664: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B2668: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B266C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B2670: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x800B2674: bne         $a0, $t0, L_800B26D8
    if (ctx->r4 != ctx->r8) {
        // 0x800B2678: nop
    
            goto L_800B26D8;
    }
    // 0x800B2678: nop

    // 0x800B267C: sb          $t1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r9;
    // 0x800B2680: lbu         $a1, 0x74($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X74);
    // 0x800B2684: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800B2688: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B268C: beq         $at, $zero, L_800B26D8
    if (ctx->r1 == 0) {
        // 0x800B2690: sll         $v1, $a1, 2
        ctx->r3 = S32(ctx->r5 << 2);
            goto L_800B26D8;
    }
    // 0x800B2690: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_800B2694:
    // 0x800B2694: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800B2698: nop

    // 0x800B269C: addu        $a2, $t3, $v1
    ctx->r6 = ADD32(ctx->r11, ctx->r3);
    // 0x800B26A0: lw          $t4, 0x4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4);
    // 0x800B26A4: nop

    // 0x800B26A8: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B26AC: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x800B26B0: nop

    // 0x800B26B4: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x800B26B8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800B26BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B26C0: sb          $a1, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r5;
    // 0x800B26C4: lbu         $t6, 0x6($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6);
    // 0x800B26C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B26CC: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B26D0: bne         $at, $zero, L_800B2694
    if (ctx->r1 != 0) {
        // 0x800B26D4: nop
    
            goto L_800B2694;
    }
    // 0x800B26D4: nop

L_800B26D8:
    // 0x800B26D8: jr          $ra
    // 0x800B26DC: nop

    return;
    // 0x800B26DC: nop

;}
RECOMP_FUNC void audspat_calculate_echo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009B7C: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80009B80: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80009B84: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80009B88: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80009B8C: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80009B90: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80009B94: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x80009B98: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80009B9C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80009BA0: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80009BA4: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80009BA8: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80009BAC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80009BB0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80009BB4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80009BB8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80009BBC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80009BC0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80009BC4: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80009BC8: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80009BCC: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80009BD0: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x80009BD4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80009BD8: jal         0x80029F18
    // 0x80009BDC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x80009BDC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x80009BE0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80009BE4: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // 0x80009BE8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80009BEC: addiu       $s6, $zero, 0x190
    ctx->r22 = ADD32(0, 0X190);
    // 0x80009BF0: addiu       $s7, $s7, -0x5928
    ctx->r23 = ADD32(ctx->r23, -0X5928);
    // 0x80009BF4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009BF8:
    // 0x80009BF8: lbu         $t6, 0x0($s7)
    ctx->r14 = MEM_BU(ctx->r23, 0X0);
    // 0x80009BFC: sw          $s7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r23;
    // 0x80009C00: beq         $t6, $zero, L_80009CF8
    if (ctx->r14 == 0) {
        // 0x80009C04: sw          $v1, 0xD4($sp)
        MEM_W(0XD4, ctx->r29) = ctx->r3;
            goto L_80009CF8;
    }
    // 0x80009C04: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    // 0x80009C08: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80009C0C: jal         0x80009AB4
    // 0x80009C10: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    audspat_reverb_validate(rdram, ctx);
        goto after_1;
    // 0x80009C10: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    after_1:
    // 0x80009C14: beq         $v0, $zero, L_80009CFC
    if (ctx->r2 == 0) {
        // 0x80009C18: lw          $v1, 0xD4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XD4);
            goto L_80009CFC;
    }
    // 0x80009C18: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    // 0x80009C1C: lb          $t7, 0xB8($s7)
    ctx->r15 = MEM_B(ctx->r23, 0XB8);
    // 0x80009C20: addiu       $fp, $s7, 0x4
    ctx->r30 = ADD32(ctx->r23, 0X4);
    // 0x80009C24: blez        $t7, L_80009CF8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80009C28: sw          $zero, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = 0;
            goto L_80009CF8;
    }
    // 0x80009C28: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
L_80009C2C:
    // 0x80009C2C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80009C30: addiu       $t8, $sp, 0xC4
    ctx->r24 = ADD32(ctx->r29, 0XC4);
    // 0x80009C34: addiu       $t9, $sp, 0xC0
    ctx->r25 = ADD32(ctx->r29, 0XC0);
    // 0x80009C38: addiu       $t0, $sp, 0xBC
    ctx->r8 = ADD32(ctx->r29, 0XBC);
    // 0x80009C3C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80009C40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80009C44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80009C48: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80009C4C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80009C50: jal         0x800092A8
    // 0x80009C54: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    audspat_distance_to_segment(rdram, ctx);
        goto after_2;
    // 0x80009C54: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_2:
    // 0x80009C58: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80009C5C: beq         $at, $zero, L_80009CD4
    if (ctx->r1 == 0) {
        // 0x80009C60: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80009CD4;
    }
    // 0x80009C60: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80009C64: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80009C68: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80009C6C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80009C70: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    // 0x80009C74: jal         0x8002BAB0
    // 0x80009C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    collision_get_y(rdram, ctx);
        goto after_3;
    // 0x80009C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    after_3:
    // 0x80009C7C: blez        $v0, L_80009CD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80009C80: addiu       $s0, $sp, 0x7C
        ctx->r16 = ADD32(ctx->r29, 0X7C);
            goto L_80009CD4;
    }
    // 0x80009C80: addiu       $s0, $sp, 0x7C
    ctx->r16 = ADD32(ctx->r29, 0X7C);
    // 0x80009C84: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80009C88: addu        $s4, $t2, $s0
    ctx->r20 = ADD32(ctx->r10, ctx->r16);
L_80009C8C:
    // 0x80009C8C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80009C90: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80009C94: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x80009C98: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x80009C9C: bc1f        L_80009CC4
    if (!c1cs) {
        // 0x80009CA0: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80009CC4;
    }
    // 0x80009CA0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80009CA4: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x80009CA8: or          $s6, $s3, $zero
    ctx->r22 = ctx->r19 | 0;
    // 0x80009CAC: jal         0x80009D6C
    // 0x80009CB0: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    audspat_reverb_get_strength_at_point(rdram, ctx);
        goto after_4;
    // 0x80009CB0: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    after_4:
    // 0x80009CB4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009CB8: beq         $at, $zero, L_80009CC4
    if (ctx->r1 == 0) {
        // 0x80009CBC: nop
    
            goto L_80009CC4;
    }
    // 0x80009CBC: nop

    // 0x80009CC0: andi        $s5, $v0, 0xFF
    ctx->r21 = ctx->r2 & 0XFF;
L_80009CC4:
    // 0x80009CC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80009CC8: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x80009CCC: bne         $at, $zero, L_80009C8C
    if (ctx->r1 != 0) {
        // 0x80009CD0: nop
    
            goto L_80009C8C;
    }
    // 0x80009CD0: nop

L_80009CD4:
    // 0x80009CD4: lw          $v0, 0xD0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD0);
    // 0x80009CD8: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x80009CDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80009CE0: sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // 0x80009CE4: lb          $t4, 0xB8($t3)
    ctx->r12 = MEM_B(ctx->r11, 0XB8);
    // 0x80009CE8: addiu       $fp, $fp, 0xC
    ctx->r30 = ADD32(ctx->r30, 0XC);
    // 0x80009CEC: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80009CF0: bne         $at, $zero, L_80009C2C
    if (ctx->r1 != 0) {
        // 0x80009CF4: nop
    
            goto L_80009C2C;
    }
    // 0x80009CF4: nop

L_80009CF8:
    // 0x80009CF8: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
L_80009CFC:
    // 0x80009CFC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80009D00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80009D04: bne         $v1, $at, L_80009BF8
    if (ctx->r3 != ctx->r1) {
        // 0x80009D08: addiu       $s7, $s7, 0xC0
        ctx->r23 = ADD32(ctx->r23, 0XC0);
            goto L_80009BF8;
    }
    // 0x80009D08: addiu       $s7, $s7, 0xC0
    ctx->r23 = ADD32(ctx->r23, 0XC0);
    // 0x80009D0C: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x80009D10: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x80009D14: beq         $a0, $zero, L_80009D28
    if (ctx->r4 == 0) {
        // 0x80009D18: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80009D28;
    }
    // 0x80009D18: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80009D1C: jal         0x800049F8
    // 0x80009D20: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80009D20: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x80009D24: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80009D28:
    // 0x80009D28: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80009D2C: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80009D30: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80009D34: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80009D38: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80009D3C: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80009D40: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80009D44: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80009D48: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80009D4C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80009D50: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80009D54: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80009D58: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80009D5C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80009D60: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80009D64: jr          $ra
    // 0x80009D68: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80009D68: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void music_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001AEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001AF0: lbu         $v0, -0x39C8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X39C8);
    // 0x80001AF4: jr          $ra
    // 0x80001AF8: nop

    return;
    // 0x80001AF8: nop

;}
RECOMP_FUNC void init_title_screen_variables(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FAC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80082FB0: lw          $t7, 0x644C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X644C);
    // 0x80082FB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80082FB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80082FBC: lw          $t6, 0x6448($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6448);
    // 0x80082FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082FC4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80082FC8: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x80082FCC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80082FD0: beq         $t9, $zero, L_80082FFC
    if (ctx->r25 == 0) {
        // 0x80082FD4: lw          $t3, 0x1C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X1C);
            goto L_80082FFC;
    }
    // 0x80082FD4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80082FD8: jal         0x8009C2E0
    // 0x80082FDC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_magic_code_flags(rdram, ctx);
        goto after_0;
    // 0x80082FDC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80082FE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80082FE4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80082FE8: lw          $t1, 0x644C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X644C);
    // 0x80082FEC: lw          $t0, 0x6448($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6448);
    // 0x80082FF0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80082FF4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80082FF8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80082FFC:
    // 0x80082FFC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80083000: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x80083004: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80083008: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8008300C: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x80083010: bne         $t5, $at, L_8008303C
    if (ctx->r13 != ctx->r1) {
        // 0x80083014: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_8008303C;
    }
    // 0x80083014: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80083018: jal         0x8009C2E0
    // 0x8008301C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_magic_code_flags(rdram, ctx);
        goto after_1;
    // 0x8008301C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80083020: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80083024: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80083028: lw          $t7, 0x644C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X644C);
    // 0x8008302C: lw          $t6, 0x6448($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6448);
    // 0x80083030: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80083034: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80083038: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_8008303C:
    // 0x8008303C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80083040: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x80083044: beq         $t1, $zero, L_80083058
    if (ctx->r9 == 0) {
        // 0x80083048: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80083058;
    }
    // 0x80083048: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008304C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083050: b           L_8008305C
    // 0x80083054: sw          $t2, -0xB6C($at)
    MEM_W(-0XB6C, ctx->r1) = ctx->r10;
        goto L_8008305C;
    // 0x80083054: sw          $t2, -0xB6C($at)
    MEM_W(-0XB6C, ctx->r1) = ctx->r10;
L_80083058:
    // 0x80083058: sw          $zero, -0xB6C($at)
    MEM_W(-0XB6C, ctx->r1) = 0;
L_8008305C:
    // 0x8008305C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80083060: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x80083064: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80083068: bne         $t7, $zero, L_80083078
    if (ctx->r15 != 0) {
        // 0x8008306C: nop
    
            goto L_80083078;
    }
    // 0x8008306C: nop

    // 0x80083070: jal         0x800C2AF4
    // 0x80083074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_subtitles(rdram, ctx);
        goto after_2;
    // 0x80083074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_80083078:
    // 0x80083078: jal         0x8009EB20
    // 0x8008307C: nop

    get_language(rdram, ctx);
        goto after_3;
    // 0x8008307C: nop

    after_3:
    // 0x80083080: jal         0x8007F900
    // 0x80083084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    load_menu_text(rdram, ctx);
        goto after_4;
    // 0x80083084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80083088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008308C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80083090: jr          $ra
    // 0x80083094: nop

    return;
    // 0x80083094: nop

;}
RECOMP_FUNC void func_800210CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800210CC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800210D0: addiu       $v1, $v1, -0x52C3
    ctx->r3 = ADD32(ctx->r3, -0X52C3);
    // 0x800210D4: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x800210D8: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800210DC: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800210E0: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800210E4: bne         $at, $zero, L_800210F8
    if (ctx->r1 != 0) {
        // 0x800210E8: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800210F8;
    }
    // 0x800210E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800210EC: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800210F0: jr          $ra
    // 0x800210F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800210F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800210F8:
    // 0x800210F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800210FC: jr          $ra
    // 0x80021100: nop

    return;
    // 0x80021100: nop

;}
RECOMP_FUNC void bgdraw_fillcolour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B5C: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x80077B60: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x80077B64: andi        $t9, $t8, 0x7C0
    ctx->r25 = ctx->r24 & 0X7C0;
    // 0x80077B68: andi        $t7, $t6, 0xF800
    ctx->r15 = ctx->r14 & 0XF800;
    // 0x80077B6C: sra         $t1, $a2, 2
    ctx->r9 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80077B70: andi        $t2, $t1, 0x3E
    ctx->r10 = ctx->r9 & 0X3E;
    // 0x80077B74: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80077B78: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80077B7C: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80077B80: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077B84: addiu       $v1, $v1, -0x1B44
    ctx->r3 = ADD32(ctx->r3, -0X1B44);
    // 0x80077B88: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80077B8C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80077B90: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80077B94: jr          $ra
    // 0x80077B98: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    return;
    // 0x80077B98: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void reset_character_id_slots(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C154: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009C158: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C15C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C160: sw          $t6, -0xB38($at)
    MEM_W(-0XB38, ctx->r1) = ctx->r14;
    // 0x8009C164: addiu       $v1, $v1, 0x63F0
    ctx->r3 = ADD32(ctx->r3, 0X63F0);
    // 0x8009C168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009C16C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8009C170:
    // 0x8009C170: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8009C174: addiu       $t8, $v0, 0x2
    ctx->r24 = ADD32(ctx->r2, 0X2);
    // 0x8009C178: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x8009C17C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8009C180: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8009C184: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
    // 0x8009C188: sb          $t8, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r24;
    // 0x8009C18C: sb          $t7, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r15;
    // 0x8009C190: bne         $v0, $a0, L_8009C170
    if (ctx->r2 != ctx->r4) {
        // 0x8009C194: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8009C170;
    }
    // 0x8009C194: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009C198: jr          $ra
    // 0x8009C19C: nop

    return;
    // 0x8009C19C: nop

;}
RECOMP_FUNC void get_ghost_data_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074B1C: addiu       $v1, $zero, 0x1100
    ctx->r3 = ADD32(0, 0X1100);
    // 0x80074B20: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80074B24: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80074B28: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80074B2C: jr          $ra
    // 0x80074B30: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    return;
    // 0x80074B30: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
;}
RECOMP_FUNC void menu_magic_codes_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CD8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80089CDC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80089CE0: addiu       $t3, $t3, 0x63D8
    ctx->r11 = ADD32(ctx->r11, 0X63D8);
    // 0x80089CE4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80089CE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80089CEC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80089CF0: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80089CF4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80089CF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80089CFC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80089D00: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80089D04: beq         $v0, $zero, L_80089D1C
    if (ctx->r2 == 0) {
        // 0x80089D08: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_80089D1C;
    }
    // 0x80089D08: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80089D0C: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x80089D10: bgez        $t6, L_80089D1C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80089D14: sw          $t6, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r14;
            goto L_80089D1C;
    }
    // 0x80089D14: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80089D18: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_80089D1C:
    // 0x80089D1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80089D20: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80089D24: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80089D28: beq         $v0, $zero, L_80089D68
    if (ctx->r2 == 0) {
        // 0x80089D2C: addiu       $v1, $v1, 0x63BC
        ctx->r3 = ADD32(ctx->r3, 0X63BC);
            goto L_80089D68;
    }
    // 0x80089D2C: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x80089D30: blez        $v0, L_80089D54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80089D34: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_80089D54;
    }
    // 0x80089D34: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x80089D38: addu        $t8, $v0, $a0
    ctx->r24 = ADD32(ctx->r2, ctx->r4);
    // 0x80089D3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089D40: sw          $t8, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r24;
    // 0x80089D44: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80089D48: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80089D4C: b           L_80089D6C
    // 0x80089D50: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
        goto L_80089D6C;
    // 0x80089D50: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80089D54:
    // 0x80089D54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089D58: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
    // 0x80089D5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80089D60: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80089D64: nop

L_80089D68:
    // 0x80089D68: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80089D6C:
    // 0x80089D6C: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x80089D70: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80089D74: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80089D78: bne         $at, $zero, L_80089DA0
    if (ctx->r1 != 0) {
        // 0x80089D7C: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80089DA0;
    }
    // 0x80089D7C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80089D80: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80089D84: beq         $at, $zero, L_80089DA0
    if (ctx->r1 == 0) {
        // 0x80089D88: nop
    
            goto L_80089DA0;
    }
    // 0x80089D88: nop

    // 0x80089D8C: jal         0x800896A4
    // 0x80089D90: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    cheatmenu_render(rdram, ctx);
        goto after_0;
    // 0x80089D90: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x80089D94: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80089D98: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80089D9C: addiu       $t3, $t3, 0x63D8
    ctx->r11 = ADD32(ctx->r11, 0X63D8);
L_80089DA0:
    // 0x80089DA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80089DA4: lw          $t9, 0x63C4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X63C4);
    // 0x80089DA8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80089DAC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80089DB0: bne         $t9, $zero, L_80089E48
    if (ctx->r25 != 0) {
        // 0x80089DB4: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80089E48;
    }
    // 0x80089DB4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80089DB8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80089DBC: lw          $t6, -0xB84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB84);
    // 0x80089DC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089DC4: bne         $t6, $zero, L_80089E48
    if (ctx->r14 != 0) {
        // 0x80089DC8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80089E48;
    }
    // 0x80089DC8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80089DCC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80089DD0: addiu       $a1, $a1, 0x6464
    ctx->r5 = ADD32(ctx->r5, 0X6464);
    // 0x80089DD4: addiu       $v1, $v1, 0x645C
    ctx->r3 = ADD32(ctx->r3, 0X645C);
L_80089DD8:
    // 0x80089DD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80089DDC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80089DE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80089DE4: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    // 0x80089DE8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80089DEC: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x80089DF0: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80089DF4: jal         0x8006A554
    // 0x80089DF8: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x80089DF8: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    after_1:
    // 0x80089DFC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80089E00: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80089E04: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80089E08: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80089E0C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80089E10: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80089E14: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x80089E18: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x80089E1C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089E20: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80089E24: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80089E28: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80089E2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80089E30: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x80089E34: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80089E38: bne         $a2, $at, L_80089DD8
    if (ctx->r6 != ctx->r1) {
        // 0x80089E3C: addu        $t1, $t1, $t8
        ctx->r9 = ADD32(ctx->r9, ctx->r24);
            goto L_80089DD8;
    }
    // 0x80089E3C: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80089E40: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80089E44: addiu       $t3, $t3, 0x63D8
    ctx->r11 = ADD32(ctx->r11, 0X63D8);
L_80089E48:
    // 0x80089E48: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80089E4C: addiu       $t5, $t5, 0x6C46
    ctx->r13 = ADD32(ctx->r13, 0X6C46);
    // 0x80089E50: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x80089E54: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089E58: bne         $v0, $at, L_80089E80
    if (ctx->r2 != ctx->r1) {
        // 0x80089E5C: addiu       $t4, $zero, 0x5
        ctx->r12 = ADD32(0, 0X5);
            goto L_80089E80;
    }
    // 0x80089E5C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80089E60: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80089E64: andi        $t6, $t2, 0x9000
    ctx->r14 = ctx->r10 & 0X9000;
    // 0x80089E68: beq         $t9, $zero, L_80089E78
    if (ctx->r25 == 0) {
        // 0x80089E6C: nop
    
            goto L_80089E78;
    }
    // 0x80089E6C: nop

    // 0x80089E70: beq         $t6, $zero, L_8008A3C8
    if (ctx->r14 == 0) {
        // 0x80089E74: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A3C8;
    }
    // 0x80089E74: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_80089E78:
    // 0x80089E78: b           L_8008A3C4
    // 0x80089E7C: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
        goto L_8008A3C4;
    // 0x80089E7C: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
L_80089E80:
    // 0x80089E80: bne         $t4, $v0, L_8008A1B8
    if (ctx->r12 != ctx->r2) {
        // 0x80089E84: addiu       $ra, $zero, 0x6
        ctx->r31 = ADD32(0, 0X6);
            goto L_8008A1B8;
    }
    // 0x80089E84: addiu       $ra, $zero, 0x6
    ctx->r31 = ADD32(0, 0X6);
    // 0x80089E88: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089E8C: addiu       $v0, $v0, 0x6C42
    ctx->r2 = ADD32(ctx->r2, 0X6C42);
    // 0x80089E90: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80089E94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80089E98: addiu       $a1, $a1, 0x6C40
    ctx->r5 = ADD32(ctx->r5, 0X6C40);
    // 0x80089E9C: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x80089EA0: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x80089EA4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80089EA8: bgez        $t0, L_80089ED4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80089EAC: or          $a2, $t8, $a0
        ctx->r6 = ctx->r24 | ctx->r4;
            goto L_80089ED4;
    }
    // 0x80089EAC: or          $a2, $t8, $a0
    ctx->r6 = ctx->r24 | ctx->r4;
    // 0x80089EB0: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80089EB4: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80089EB8: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80089EBC: addiu       $ra, $zero, 0x6
    ctx->r31 = ADD32(0, 0X6);
    // 0x80089EC0: bgez        $v1, L_80089ED4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80089EC4: nop
    
            goto L_80089ED4;
    }
    // 0x80089EC4: nop

    // 0x80089EC8: sh          $ra, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r31;
    // 0x80089ECC: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80089ED0: nop

L_80089ED4:
    // 0x80089ED4: blez        $t0, L_80089F04
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80089ED8: addiu       $ra, $zero, 0x6
        ctx->r31 = ADD32(0, 0X6);
            goto L_80089F04;
    }
    // 0x80089ED8: addiu       $ra, $zero, 0x6
    ctx->r31 = ADD32(0, 0X6);
    // 0x80089EDC: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80089EE0: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80089EE4: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80089EE8: nop

    // 0x80089EEC: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x80089EF0: bne         $at, $zero, L_80089F04
    if (ctx->r1 != 0) {
        // 0x80089EF4: nop
    
            goto L_80089F04;
    }
    // 0x80089EF4: nop

    // 0x80089EF8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80089EFC: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80089F00: nop

L_80089F04:
    // 0x80089F04: andi        $v0, $v1, 0xF
    ctx->r2 = ctx->r3 & 0XF;
    // 0x80089F08: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80089F0C: bgez        $t1, L_80089F3C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80089F10: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80089F3C;
    }
    // 0x80089F10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80089F14: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x80089F18: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80089F1C: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x80089F20: nop

    // 0x80089F24: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80089F28: bne         $at, $zero, L_80089F3C
    if (ctx->r1 != 0) {
        // 0x80089F2C: nop
    
            goto L_80089F3C;
    }
    // 0x80089F2C: nop

    // 0x80089F30: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80089F34: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x80089F38: nop

L_80089F3C:
    // 0x80089F3C: blez        $t1, L_80089F68
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80089F40: andi        $t8, $t2, 0x8000
        ctx->r24 = ctx->r10 & 0X8000;
            goto L_80089F68;
    }
    // 0x80089F40: andi        $t8, $t2, 0x8000
    ctx->r24 = ctx->r10 & 0X8000;
    // 0x80089F44: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x80089F48: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x80089F4C: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x80089F50: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80089F54: bgez        $a0, L_80089F6C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80089F58: or          $t6, $v0, $a0
        ctx->r14 = ctx->r2 | ctx->r4;
            goto L_80089F6C;
    }
    // 0x80089F58: or          $t6, $v0, $a0
    ctx->r14 = ctx->r2 | ctx->r4;
    // 0x80089F5C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x80089F60: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x80089F64: nop

L_80089F68:
    // 0x80089F68: or          $t6, $v0, $a0
    ctx->r14 = ctx->r2 | ctx->r4;
L_80089F6C:
    // 0x80089F6C: beq         $a2, $t6, L_80089F7C
    if (ctx->r6 == ctx->r14) {
        // 0x80089F70: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_80089F7C;
    }
    // 0x80089F70: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80089F74: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089F78: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80089F7C:
    // 0x80089F7C: beq         $t8, $zero, L_8008A000
    if (ctx->r24 == 0) {
        // 0x80089F80: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008A000;
    }
    // 0x80089F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089F84: bne         $t0, $a0, L_80089F9C
    if (ctx->r8 != ctx->r4) {
        // 0x80089F88: nop
    
            goto L_80089F9C;
    }
    // 0x80089F88: nop

    // 0x80089F8C: bne         $t4, $v1, L_80089F9C
    if (ctx->r12 != ctx->r3) {
        // 0x80089F90: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80089F9C;
    }
    // 0x80089F90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089F94: b           L_8008A000
    // 0x80089F98: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
        goto L_8008A000;
    // 0x80089F98: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_80089F9C:
    // 0x80089F9C: bne         $t0, $a0, L_80089FB4
    if (ctx->r8 != ctx->r4) {
        // 0x80089FA0: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_80089FB4;
    }
    // 0x80089FA0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80089FA4: bne         $ra, $v1, L_80089FB4
    if (ctx->r31 != ctx->r3) {
        // 0x80089FA8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80089FB4;
    }
    // 0x80089FA8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80089FAC: b           L_8008A000
    // 0x80089FB0: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
        goto L_8008A000;
    // 0x80089FB0: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
L_80089FB4:
    // 0x80089FB4: addiu       $a2, $a2, 0x6C44
    ctx->r6 = ADD32(ctx->r6, 0X6C44);
    // 0x80089FB8: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x80089FBC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089FC0: slti        $at, $v0, 0x13
    ctx->r1 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
    // 0x80089FC4: beq         $at, $zero, L_8008A000
    if (ctx->r1 == 0) {
        // 0x80089FC8: sll         $t8, $a0, 3
        ctx->r24 = S32(ctx->r4 << 3);
            goto L_8008A000;
    }
    // 0x80089FC8: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x80089FCC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80089FD0: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80089FD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089FD8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80089FDC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80089FE0: addiu       $t6, $t9, 0x41
    ctx->r14 = ADD32(ctx->r25, 0X41);
    // 0x80089FE4: sb          $t6, 0x6C58($at)
    MEM_B(0X6C58, ctx->r1) = ctx->r14;
    // 0x80089FE8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80089FEC: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x80089FF0: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x80089FF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089FF8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80089FFC: sb          $zero, 0x6C58($at)
    MEM_B(0X6C58, ctx->r1) = 0;
L_8008A000:
    // 0x8008A000: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A004: andi        $t9, $t2, 0x4000
    ctx->r25 = ctx->r10 & 0X4000;
    // 0x8008A008: beq         $t9, $zero, L_8008A02C
    if (ctx->r25 == 0) {
        // 0x8008A00C: addiu       $a2, $a2, 0x6C44
        ctx->r6 = ADD32(ctx->r6, 0X6C44);
            goto L_8008A02C;
    }
    // 0x8008A00C: addiu       $a2, $a2, 0x6C44
    ctx->r6 = ADD32(ctx->r6, 0X6C44);
    // 0x8008A010: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x8008A014: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A018: blez        $t6, L_8008A028
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8008A01C: nop
    
            goto L_8008A028;
    }
    // 0x8008A01C: nop

    // 0x8008A020: b           L_8008A02C
    // 0x8008A024: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
        goto L_8008A02C;
    // 0x8008A024: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_8008A028:
    // 0x8008A028: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
L_8008A02C:
    // 0x8008A02C: andi        $t8, $t2, 0x1000
    ctx->r24 = ctx->r10 & 0X1000;
    // 0x8008A030: beq         $t8, $zero, L_8008A03C
    if (ctx->r24 == 0) {
        // 0x8008A034: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008A03C;
    }
    // 0x8008A034: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A038: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
L_8008A03C:
    // 0x8008A03C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8008A040: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    // 0x8008A044: beq         $t6, $zero, L_8008A08C
    if (ctx->r14 == 0) {
        // 0x8008A048: lw          $t9, 0x48($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X48);
            goto L_8008A08C;
    }
    // 0x8008A048: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8008A04C: jal         0x80001D04
    // 0x8008A050: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008A050: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_2:
    // 0x8008A054: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A058: addiu       $a2, $a2, 0x6C44
    ctx->r6 = ADD32(ctx->r6, 0X6C44);
    // 0x8008A05C: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8008A060: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8008A064: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008A068: blez        $v0, L_8008A088
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A06C: addiu       $t5, $t5, 0x6C46
        ctx->r13 = ADD32(ctx->r13, 0X6C46);
            goto L_8008A088;
    }
    // 0x8008A06C: addiu       $t5, $t5, 0x6C46
    ctx->r13 = ADD32(ctx->r13, 0X6C46);
    // 0x8008A070: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8008A074: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x8008A078: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x8008A07C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A080: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008A084: sb          $zero, 0x6C58($at)
    MEM_B(0X6C58, ctx->r1) = 0;
L_8008A088:
    // 0x8008A088: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
L_8008A08C:
    // 0x8008A08C: nop

    // 0x8008A090: beq         $t9, $zero, L_8008A3C8
    if (ctx->r25 == 0) {
        // 0x8008A094: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A3C8;
    }
    // 0x8008A094: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A098: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x8008A09C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A0A0: bne         $t7, $zero, L_8008A0B0
    if (ctx->r15 != 0) {
        // 0x8008A0A4: sw          $t6, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r14;
            goto L_8008A0B0;
    }
    // 0x8008A0A4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8008A0A8: b           L_8008A3C4
    // 0x8008A0AC: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
        goto L_8008A3C4;
    // 0x8008A0AC: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
L_8008A0B0:
    // 0x8008A0B0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008A0B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008A0B8: lw          $t1, 0x6C30($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6C30);
    // 0x8008A0BC: addiu       $t3, $t3, 0x6C4C
    ctx->r11 = ADD32(ctx->r11, 0X6C4C);
    // 0x8008A0C0: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
    // 0x8008A0C4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008A0C8: lw          $t2, 0x6C38($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6C38);
    // 0x8008A0CC: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x8008A0D0: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x8008A0D4: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8008A0D8: or          $t2, $t8, $zero
    ctx->r10 = ctx->r24 | 0;
    // 0x8008A0DC: beq         $at, $zero, L_8008A15C
    if (ctx->r1 == 0) {
        // 0x8008A0E0: addiu       $t4, $t1, 0x2
        ctx->r12 = ADD32(ctx->r9, 0X2);
            goto L_8008A15C;
    }
    // 0x8008A0E0: addiu       $t4, $t1, 0x2
    ctx->r12 = ADD32(ctx->r9, 0X2);
    // 0x8008A0E4: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
L_8008A0E8:
    // 0x8008A0E8: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8008A0EC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008A0F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A0F4: addu        $v0, $t7, $t1
    ctx->r2 = ADD32(ctx->r15, ctx->r9);
    // 0x8008A0F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8008A0FC: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x8008A100: addiu       $a1, $a1, 0x6C57
    ctx->r5 = ADD32(ctx->r5, 0X6C57);
L_8008A104:
    // 0x8008A104: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8008A108: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x8008A10C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008A110: beq         $v0, $v1, L_8008A11C
    if (ctx->r2 == ctx->r3) {
        // 0x8008A114: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8008A11C;
    }
    // 0x8008A114: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008A118: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8008A11C:
    // 0x8008A11C: beq         $a3, $zero, L_8008A134
    if (ctx->r7 == 0) {
        // 0x8008A120: nop
    
            goto L_8008A134;
    }
    // 0x8008A120: nop

    // 0x8008A124: beq         $v0, $zero, L_8008A134
    if (ctx->r2 == 0) {
        // 0x8008A128: nop
    
            goto L_8008A134;
    }
    // 0x8008A128: nop

    // 0x8008A12C: bne         $v1, $zero, L_8008A104
    if (ctx->r3 != 0) {
        // 0x8008A130: nop
    
            goto L_8008A104;
    }
    // 0x8008A130: nop

L_8008A134:
    // 0x8008A134: bne         $a3, $zero, L_8008A148
    if (ctx->r7 != 0) {
        // 0x8008A138: addiu       $t8, $t0, 0x2
        ctx->r24 = ADD32(ctx->r8, 0X2);
            goto L_8008A148;
    }
    // 0x8008A138: addiu       $t8, $t0, 0x2
    ctx->r24 = ADD32(ctx->r8, 0X2);
    // 0x8008A13C: sh          $t8, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r24;
    // 0x8008A140: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x8008A144: nop

L_8008A148:
    // 0x8008A148: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008A14C: beq         $at, $zero, L_8008A15C
    if (ctx->r1 == 0) {
        // 0x8008A150: nop
    
            goto L_8008A15C;
    }
    // 0x8008A150: nop

    // 0x8008A154: beq         $a3, $zero, L_8008A0E8
    if (ctx->r7 == 0) {
        // 0x8008A158: sll         $t9, $t0, 1
        ctx->r25 = S32(ctx->r8 << 1);
            goto L_8008A0E8;
    }
    // 0x8008A158: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
L_8008A15C:
    // 0x8008A15C: bne         $a3, $zero, L_8008A16C
    if (ctx->r7 != 0) {
        // 0x8008A160: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_8008A16C;
    }
    // 0x8008A160: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008A164: b           L_8008A1A0
    // 0x8008A168: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
        goto L_8008A1A0;
    // 0x8008A168: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
L_8008A16C:
    // 0x8008A16C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008A170: addiu       $v1, $v1, -0x264
    ctx->r3 = ADD32(ctx->r3, -0X264);
    // 0x8008A174: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008A178: sra         $t6, $t0, 1
    ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8008A17C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A180: sllv        $v0, $t7, $t6
    ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8008A184: or          $t9, $t8, $v0
    ctx->r25 = ctx->r24 | ctx->r2;
    // 0x8008A188: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008A18C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008A190: lw          $t7, -0x268($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X268);
    // 0x8008A194: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A198: or          $t6, $t7, $v0
    ctx->r14 = ctx->r15 | ctx->r2;
    // 0x8008A19C: sw          $t6, -0x268($at)
    MEM_W(-0X268, ctx->r1) = ctx->r14;
L_8008A1A0:
    // 0x8008A1A0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8008A1A4: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
    // 0x8008A1A8: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x8008A1AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A1B0: b           L_8008A3C4
    // 0x8008A1B4: sw          $t9, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r25;
        goto L_8008A3C4;
    // 0x8008A1B4: sw          $t9, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r25;
L_8008A1B8:
    // 0x8008A1B8: bne         $ra, $v0, L_8008A1E0
    if (ctx->r31 != ctx->r2) {
        // 0x8008A1BC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8008A1E0;
    }
    // 0x8008A1BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008A1C0: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8008A1C4: andi        $t6, $t2, 0x9000
    ctx->r14 = ctx->r10 & 0X9000;
    // 0x8008A1C8: beq         $t7, $zero, L_8008A1D8
    if (ctx->r15 == 0) {
        // 0x8008A1CC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008A1D8;
    }
    // 0x8008A1CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A1D0: beq         $t6, $zero, L_8008A3C8
    if (ctx->r14 == 0) {
        // 0x8008A1D4: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A3C8;
    }
    // 0x8008A1D4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_8008A1D8:
    // 0x8008A1D8: b           L_8008A3C4
    // 0x8008A1DC: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
        goto L_8008A3C4;
    // 0x8008A1DC: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
L_8008A1E0:
    // 0x8008A1E0: addiu       $a0, $a0, 0x63E0
    ctx->r4 = ADD32(ctx->r4, 0X63E0);
    // 0x8008A1E4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008A1E8: andi        $t9, $t2, 0x9000
    ctx->r25 = ctx->r10 & 0X9000;
    // 0x8008A1EC: beq         $v1, $zero, L_8008A2A0
    if (ctx->r3 == 0) {
        // 0x8008A1F0: andi        $t8, $t2, 0x9000
        ctx->r24 = ctx->r10 & 0X9000;
            goto L_8008A2A0;
    }
    // 0x8008A1F0: andi        $t8, $t2, 0x9000
    ctx->r24 = ctx->r10 & 0X9000;
    // 0x8008A1F4: beq         $t9, $zero, L_8008A24C
    if (ctx->r25 == 0) {
        // 0x8008A1F8: andi        $t6, $t2, 0x4000
        ctx->r14 = ctx->r10 & 0X4000;
            goto L_8008A24C;
    }
    // 0x8008A1F8: andi        $t6, $t2, 0x4000
    ctx->r14 = ctx->r10 & 0X4000;
    // 0x8008A1FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A200: bne         $v1, $at, L_8008A23C
    if (ctx->r3 != ctx->r1) {
        // 0x8008A204: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8008A23C;
    }
    // 0x8008A204: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A208: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008A20C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A210: addiu       $v1, $v1, -0x264
    ctx->r3 = ADD32(ctx->r3, -0X264);
    // 0x8008A214: sw          $zero, -0x268($at)
    MEM_W(-0X268, ctx->r1) = 0;
    // 0x8008A218: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008A21C: sh          $ra, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r31;
    // 0x8008A220: andi        $t8, $t6, 0x3
    ctx->r24 = ctx->r14 & 0X3;
    // 0x8008A224: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008A228: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A22C: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x8008A230: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8008A234: b           L_8008A244
    // 0x8008A238: sw          $t9, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r25;
        goto L_8008A244;
    // 0x8008A238: sw          $t9, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r25;
L_8008A23C:
    // 0x8008A23C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A240: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
L_8008A244:
    // 0x8008A244: b           L_8008A3C4
    // 0x8008A248: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_8008A3C4;
    // 0x8008A248: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8008A24C:
    // 0x8008A24C: beq         $t6, $zero, L_8008A260
    if (ctx->r14 == 0) {
        // 0x8008A250: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008A260;
    }
    // 0x8008A250: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A254: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8008A258: b           L_8008A3C4
    // 0x8008A25C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_8008A3C4;
    // 0x8008A25C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8008A260:
    // 0x8008A260: bgez        $t1, L_8008A280
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8008A264: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008A280;
    }
    // 0x8008A264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A268: bne         $v1, $at, L_8008A280
    if (ctx->r3 != ctx->r1) {
        // 0x8008A26C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008A280;
    }
    // 0x8008A26C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A270: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8008A274: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8008A278: b           L_8008A3C4
    // 0x8008A27C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_8008A3C4;
    // 0x8008A27C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8008A280:
    // 0x8008A280: blez        $t1, L_8008A3C4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8008A284: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008A3C4;
    }
    // 0x8008A284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008A288: bne         $v1, $at, L_8008A3C4
    if (ctx->r3 != ctx->r1) {
        // 0x8008A28C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008A3C4;
    }
    // 0x8008A28C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A290: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A294: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8008A298: b           L_8008A3C4
    // 0x8008A29C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_8008A3C4;
    // 0x8008A29C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_8008A2A0:
    // 0x8008A2A0: bgez        $t1, L_8008A2D0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8008A2A4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8008A2D0;
    }
    // 0x8008A2A4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8008A2A8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8008A2AC: sh          $t9, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r25;
    // 0x8008A2B0: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x8008A2B4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8008A2B8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008A2BC: bne         $at, $zero, L_8008A2D0
    if (ctx->r1 != 0) {
        // 0x8008A2C0: nop
    
            goto L_8008A2D0;
    }
    // 0x8008A2C0: nop

    // 0x8008A2C4: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
    // 0x8008A2C8: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x8008A2CC: nop

L_8008A2D0:
    // 0x8008A2D0: blez        $t1, L_8008A2FC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8008A2D4: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_8008A2FC;
    }
    // 0x8008A2D4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8008A2D8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8008A2DC: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x8008A2E0: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x8008A2E4: nop

    // 0x8008A2E8: bgez        $v0, L_8008A2FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008A2EC: nop
    
            goto L_8008A2FC;
    }
    // 0x8008A2EC: nop

    // 0x8008A2F0: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
    // 0x8008A2F4: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x8008A2F8: nop

L_8008A2FC:
    // 0x8008A2FC: beq         $a2, $v0, L_8008A308
    if (ctx->r6 == ctx->r2) {
        // 0x8008A300: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008A308;
    }
    // 0x8008A300: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A304: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_8008A308:
    // 0x8008A308: beq         $t8, $zero, L_8008A380
    if (ctx->r24 == 0) {
        // 0x8008A30C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008A380;
    }
    // 0x8008A30C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A310: bne         $t0, $v0, L_8008A324
    if (ctx->r8 != ctx->r2) {
        // 0x8008A314: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_8008A324;
    }
    // 0x8008A314: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8008A318: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008A31C: b           L_8008A380
    // 0x8008A320: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
        goto L_8008A380;
    // 0x8008A320: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_8008A324:
    // 0x8008A324: bne         $v0, $zero, L_8008A35C
    if (ctx->r2 != 0) {
        // 0x8008A328: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8008A35C;
    }
    // 0x8008A328: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A32C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008A330: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A334: addiu       $a2, $a2, 0x6C44
    ctx->r6 = ADD32(ctx->r6, 0X6C44);
    // 0x8008A338: addiu       $v0, $v0, 0x6C42
    ctx->r2 = ADD32(ctx->r2, 0X6C42);
    // 0x8008A33C: addiu       $a1, $a1, 0x6C40
    ctx->r5 = ADD32(ctx->r5, 0X6C40);
    // 0x8008A340: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8008A344: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8008A348: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x8008A34C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A350: sb          $zero, 0x6C58($at)
    MEM_B(0X6C58, ctx->r1) = 0;
    // 0x8008A354: b           L_8008A380
    // 0x8008A358: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
        goto L_8008A380;
    // 0x8008A358: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
L_8008A35C:
    // 0x8008A35C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A360: bne         $v0, $at, L_8008A370
    if (ctx->r2 != ctx->r1) {
        // 0x8008A364: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_8008A370;
    }
    // 0x8008A364: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8008A368: b           L_8008A380
    // 0x8008A36C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
        goto L_8008A380;
    // 0x8008A36C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8008A370:
    // 0x8008A370: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008A374: bne         $v0, $at, L_8008A380
    if (ctx->r2 != ctx->r1) {
        // 0x8008A378: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008A380;
    }
    // 0x8008A378: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A37C: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
L_8008A380:
    // 0x8008A380: andi        $t9, $t2, 0x4000
    ctx->r25 = ctx->r10 & 0X4000;
    // 0x8008A384: beq         $t9, $zero, L_8008A390
    if (ctx->r25 == 0) {
        // 0x8008A388: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_8008A390;
    }
    // 0x8008A388: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008A38C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_8008A390:
    // 0x8008A390: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008A394: nop

    // 0x8008A398: beq         $t6, $zero, L_8008A3C8
    if (ctx->r14 == 0) {
        // 0x8008A39C: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A3C8;
    }
    // 0x8008A39C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A3A0: bgez        $t6, L_8008A3B0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008A3A4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8008A3B0;
    }
    // 0x8008A3A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A3A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A3AC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
L_8008A3B0:
    // 0x8008A3B0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008A3B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008A3B8: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    // 0x8008A3BC: jal         0x800C01D8
    // 0x8008A3C0: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8008A3C0: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
    after_3:
L_8008A3C4:
    // 0x8008A3C4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_8008A3C8:
    // 0x8008A3C8: nop

    // 0x8008A3CC: beq         $t7, $zero, L_8008A3E4
    if (ctx->r15 == 0) {
        // 0x8008A3D0: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008A3E4;
    }
    // 0x8008A3D0: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008A3D4: jal         0x80001D04
    // 0x8008A3D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008A3D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008A3DC: b           L_8008A414
    // 0x8008A3E0: nop

        goto L_8008A414;
    // 0x8008A3E0: nop

L_8008A3E4:
    // 0x8008A3E4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008A3E8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8008A3EC: beq         $t6, $zero, L_8008A404
    if (ctx->r14 == 0) {
        // 0x8008A3F0: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008A404;
    }
    // 0x8008A3F0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008A3F4: jal         0x80001D04
    // 0x8008A3F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8008A3F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8008A3FC: b           L_8008A414
    // 0x8008A400: nop

        goto L_8008A414;
    // 0x8008A400: nop

L_8008A404:
    // 0x8008A404: beq         $t8, $zero, L_8008A414
    if (ctx->r24 == 0) {
        // 0x8008A408: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008A414;
    }
    // 0x8008A408: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008A40C: jal         0x80001D04
    // 0x8008A410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008A410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_8008A414:
    // 0x8008A414: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A418: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8008A41C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A420: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
    // 0x8008A424: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x8008A428: bne         $at, $zero, L_8008A438
    if (ctx->r1 != 0) {
        // 0x8008A42C: slti        $at, $v0, 0x1F
        ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
            goto L_8008A438;
    }
    // 0x8008A42C: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8008A430: bne         $at, $zero, L_8008A4BC
    if (ctx->r1 != 0) {
        // 0x8008A434: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008A4BC;
    }
    // 0x8008A434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A438:
    // 0x8008A438: jal         0x8008A4C8
    // 0x8008A43C: nop

    cheatmenu_free(rdram, ctx);
        goto after_7;
    // 0x8008A43C: nop

    after_7:
    // 0x8008A440: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008A444: lw          $t9, -0xB84($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB84);
    // 0x8008A448: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008A44C: bgez        $t9, L_8008A4B0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8008A450: nop
    
            goto L_8008A4B0;
    }
    // 0x8008A450: nop

    // 0x8008A454: lw          $t7, -0x268($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X268);
    // 0x8008A458: nop

    // 0x8008A45C: andi        $t6, $t7, 0x400
    ctx->r14 = ctx->r15 & 0X400;
    // 0x8008A460: beq         $t6, $zero, L_8008A4A0
    if (ctx->r14 == 0) {
        // 0x8008A464: nop
    
            goto L_8008A4A0;
    }
    // 0x8008A464: nop

    // 0x8008A468: jal         0x80000B28
    // 0x8008A46C: nop

    music_change_on(rdram, ctx);
        goto after_8;
    // 0x8008A46C: nop

    after_8:
    // 0x8008A470: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A474: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A478: sw          $t8, 0x1B4C($at)
    MEM_W(0X1B4C, ctx->r1) = ctx->r24;
    // 0x8008A47C: jal         0x800813D0
    // 0x8008A480: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    menu_init(rdram, ctx);
        goto after_9;
    // 0x8008A480: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_9:
    extern void dkr_magic_code_credits_started(uint8_t*, recomp_context*); dkr_magic_code_credits_started(rdram, ctx);
    // 0x8008A484: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008A488: lw          $t9, -0x268($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X268);
    // 0x8008A48C: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x8008A490: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x8008A494: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A498: b           L_8008A4B8
    // 0x8008A49C: sw          $t7, -0x268($at)
    MEM_W(-0X268, ctx->r1) = ctx->r15;
        goto L_8008A4B8;
    // 0x8008A49C: sw          $t7, -0x268($at)
    MEM_W(-0X268, ctx->r1) = ctx->r15;
L_8008A4A0:
    // 0x8008A4A0: jal         0x800813D0
    // 0x8008A4A4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_10;
    // 0x8008A4A4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_10:
    // 0x8008A4A8: b           L_8008A4BC
    // 0x8008A4AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A4BC;
    // 0x8008A4AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A4B0:
    // 0x8008A4B0: jal         0x800813D0
    // 0x8008A4B4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    menu_init(rdram, ctx);
        goto after_11;
    // 0x8008A4B4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_11:
L_8008A4B8:
    // 0x8008A4B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A4BC:
    // 0x8008A4BC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8008A4C0: jr          $ra
    // 0x8008A4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8008A4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void weapon_trap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F2E8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003F2EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003F2F0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003F2F4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8003F2F8: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8003F2FC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003F300: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8003F304: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8003F308: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8003F30C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003F310: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x8003F314: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x8003F318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003F31C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003F320: bne         $t3, $zero, L_8003F340
    if (ctx->r11 != 0) {
        // 0x8003F324: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_8003F340;
    }
    // 0x8003F324: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x8003F328: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F32C: lwc1        $f9, 0x6200($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6200);
    // 0x8003F330: lwc1        $f8, 0x6204($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6204);
    // 0x8003F334: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003F338: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003F33C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8003F340:
    // 0x8003F340: addiu       $t0, $s0, 0x78
    ctx->r8 = ADD32(ctx->r16, 0X78);
    // 0x8003F344: lbu         $t4, 0x4($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F348: nop

    // 0x8003F34C: bne         $t4, $zero, L_8003F554
    if (ctx->r12 != 0) {
        // 0x8003F350: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_8003F554;
    }
    // 0x8003F350: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8003F354: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003F358: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003F35C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003F360: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8003F364: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8003F368: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003F36C: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8003F370: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8003F374: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8003F378: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003F37C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F380: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003F384: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003F388: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8003F38C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F390: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x8003F394: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003F398: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003F39C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003F3A0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8003F3A4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003F3A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003F3AC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8003F3B0: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x8003F3B4: jal         0x80031130
    // 0x8003F3B8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_0;
    // 0x8003F3B8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8003F3BC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8003F3C0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003F3C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003F3C8: addiu       $t7, $sp, 0x4C
    ctx->r15 = ADD32(ctx->r29, 0X4C);
    // 0x8003F3CC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8003F3D0: sb          $t5, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r13;
    // 0x8003F3D4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8003F3D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F3DC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8003F3E0: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8003F3E4: jal         0x80031600
    // 0x8003F3E8: addiu       $a3, $sp, 0x47
    ctx->r7 = ADD32(ctx->r29, 0X47);
    resolve_collisions(rdram, ctx);
        goto after_1;
    // 0x8003F3E8: addiu       $a3, $sp, 0x47
    ctx->r7 = ADD32(ctx->r29, 0X47);
    after_1:
    // 0x8003F3EC: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003F3F0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003F3F4: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003F3F8: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003F3FC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F400: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003F404: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F408: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003F40C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F410: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8003F414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003F418: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003F41C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8003F420: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003F424: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003F428: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8003F42C: nop

    // 0x8003F430: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003F434: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8003F438: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003F43C: nop

    // 0x8003F440: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8003F444: nop

    // 0x8003F448: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003F44C: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8003F450: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003F454: nop

    // 0x8003F458: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003F45C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003F460: nop

    // 0x8003F464: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8003F468: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003F46C: nop

    // 0x8003F470: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8003F474: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8003F478: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8003F47C: bne         $t8, $zero, L_8003F494
    if (ctx->r24 != 0) {
        // 0x8003F480: nop
    
            goto L_8003F494;
    }
    // 0x8003F480: nop

    // 0x8003F484: lb          $t2, 0x1D6($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X1D6);
    // 0x8003F488: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F48C: bne         $t2, $at, L_8003F4DC
    if (ctx->r10 != ctx->r1) {
        // 0x8003F490: nop
    
            goto L_8003F4DC;
    }
    // 0x8003F490: nop

L_8003F494:
    // 0x8003F494: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003F498: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003F49C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8003F4A0: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8003F4A4: sb          $t3, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r11;
    // 0x8003F4A8: sb          $zero, 0x5($t0)
    MEM_B(0X5, ctx->r8) = 0;
    // 0x8003F4AC: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x8003F4B0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8003F4B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003F4B8: lbu         $t5, 0x18($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X18);
    // 0x8003F4BC: nop

    // 0x8003F4C0: bne         $t5, $at, L_8003F4DC
    if (ctx->r13 != ctx->r1) {
        // 0x8003F4C4: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8003F4DC;
    }
    // 0x8003F4C4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003F4C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003F4CC: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F4D0: nop

    // 0x8003F4D4: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003F4D8: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_8003F4DC:
    // 0x8003F4DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F4E0: lwc1        $f4, 0x6208($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6208);
    // 0x8003F4E4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003F4E8: jal         0x8002B9BC
    // 0x8003F4EC: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    func_8002B9BC(rdram, ctx);
        goto after_2;
    // 0x8003F4EC: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8003F4F0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F4F4: beq         $v0, $zero, L_8003F554
    if (ctx->r2 == 0) {
        // 0x8003F4F8: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_8003F554;
    }
    // 0x8003F4F8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8003F4FC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F500: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8003F504: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003F508: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8003F50C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003F510: bc1f        L_8003F554
    if (!c1cs) {
        // 0x8003F514: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_8003F554;
    }
    // 0x8003F514: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8003F518: sb          $t6, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r14;
    // 0x8003F51C: sb          $t7, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r15;
    // 0x8003F520: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x8003F524: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8003F528: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003F52C: lbu         $t9, 0x18($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X18);
    // 0x8003F530: nop

    // 0x8003F534: bne         $t9, $at, L_8003F550
    if (ctx->r25 != ctx->r1) {
        // 0x8003F538: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8003F550;
    }
    // 0x8003F538: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003F53C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003F540: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F544: nop

    // 0x8003F548: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003F54C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_8003F550:
    // 0x8003F550: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
L_8003F554:
    // 0x8003F554: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003F558: lbu         $t3, 0x18($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X18);
    // 0x8003F55C: nop

    // 0x8003F560: bne         $t3, $at, L_8003F660
    if (ctx->r11 != ctx->r1) {
        // 0x8003F564: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8003F660;
    }
    // 0x8003F564: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003F568: lbu         $v0, 0x4($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F56C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003F570: beq         $v0, $zero, L_8003F660
    if (ctx->r2 == 0) {
        // 0x8003F574: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8003F660;
    }
    // 0x8003F574: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003F578: bne         $v0, $at, L_8003F5B0
    if (ctx->r2 != ctx->r1) {
        // 0x8003F57C: nop
    
            goto L_8003F5B0;
    }
    // 0x8003F57C: nop

    // 0x8003F580: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x8003F584: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003F588: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8003F58C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8003F590: sh          $t6, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r14;
    // 0x8003F594: lh          $t7, 0x6($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X6);
    // 0x8003F598: nop

    // 0x8003F59C: slti        $at, $t7, 0xD
    ctx->r1 = SIGNED(ctx->r15) < 0XD ? 1 : 0;
    // 0x8003F5A0: bne         $at, $zero, L_8003F5EC
    if (ctx->r1 != 0) {
        // 0x8003F5A4: lw          $t6, 0x64($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X64);
            goto L_8003F5EC;
    }
    // 0x8003F5A4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003F5A8: b           L_8003F5E8
    // 0x8003F5AC: sh          $t8, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r24;
        goto L_8003F5E8;
    // 0x8003F5AC: sh          $t8, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r24;
L_8003F5B0:
    // 0x8003F5B0: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x8003F5B4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003F5B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003F5BC: subu        $t3, $t9, $t2
    ctx->r11 = SUB32(ctx->r25, ctx->r10);
    // 0x8003F5C0: sh          $t3, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r11;
    // 0x8003F5C4: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x8003F5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F5CC: bgtz        $t4, L_8003F5EC
    if (SIGNED(ctx->r12) > 0) {
        // 0x8003F5D0: lw          $t6, 0x64($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X64);
            goto L_8003F5EC;
    }
    // 0x8003F5D0: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003F5D4: sh          $t5, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r13;
    // 0x8003F5D8: jal         0x8000FFB8
    // 0x8003F5DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    free_object(rdram, ctx);
        goto after_3;
    // 0x8003F5DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_3:
    // 0x8003F5E0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F5E4: nop

L_8003F5E8:
    // 0x8003F5E8: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
L_8003F5EC:
    // 0x8003F5EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F5F0: lb          $t7, 0x1D6($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X1D6);
    // 0x8003F5F4: nop

    // 0x8003F5F8: beq         $t7, $at, L_8003F660
    if (ctx->r15 == ctx->r1) {
        // 0x8003F5FC: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8003F660;
    }
    // 0x8003F5FC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003F600: lbu         $t8, 0x5($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X5);
    // 0x8003F604: lh          $v0, 0x6($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X6);
    // 0x8003F608: beq         $t8, $zero, L_8003F630
    if (ctx->r24 == 0) {
        // 0x8003F60C: nop
    
            goto L_8003F630;
    }
    // 0x8003F60C: nop

    // 0x8003F610: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003F614: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F618: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003F61C: lwc1        $f8, 0x620C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X620C);
    // 0x8003F620: lw          $t9, 0x58($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X58);
    // 0x8003F624: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8003F628: b           L_8003F64C
    // 0x8003F62C: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
        goto L_8003F64C;
    // 0x8003F62C: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
L_8003F630:
    // 0x8003F630: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8003F634: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F638: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003F63C: lwc1        $f4, 0x6210($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6210);
    // 0x8003F640: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x8003F644: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8003F648: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
L_8003F64C:
    // 0x8003F64C: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x8003F650: nop

    // 0x8003F654: ori         $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 | 0X1000;
    // 0x8003F658: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x8003F65C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_8003F660:
    // 0x8003F660: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003F664: lbu         $t6, 0x18($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X18);
    // 0x8003F668: nop

    // 0x8003F66C: bne         $t6, $at, L_8003F848
    if (ctx->r14 != ctx->r1) {
        // 0x8003F670: nop
    
            goto L_8003F848;
    }
    // 0x8003F670: nop

    // 0x8003F674: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8003F678: nop

    // 0x8003F67C: beq         $t7, $zero, L_8003F6CC
    if (ctx->r15 == 0) {
        // 0x8003F680: nop
    
            goto L_8003F6CC;
    }
    // 0x8003F680: nop

    // 0x8003F684: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003F688: nop

    // 0x8003F68C: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8003F690: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8003F694: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8003F698: jal         0x80011560
    // 0x8003F69C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    ignore_bounds_check(rdram, ctx);
        goto after_4;
    // 0x8003F69C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_4:
    // 0x8003F6A0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8003F6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F6A8: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8003F6AC: nop

    // 0x8003F6B0: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8003F6B4: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x8003F6B8: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    // 0x8003F6BC: jal         0x80011570
    // 0x8003F6C0: nop

    move_object(rdram, ctx);
        goto after_5;
    // 0x8003F6C0: nop

    after_5:
    // 0x8003F6C4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F6C8: nop

L_8003F6CC:
    // 0x8003F6CC: lbu         $v0, 0x4($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F6D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003F6D4: beq         $v0, $at, L_8003F6E4
    if (ctx->r2 == ctx->r1) {
        // 0x8003F6D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003F6E4;
    }
    // 0x8003F6D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F6DC: bne         $v0, $at, L_8003F710
    if (ctx->r2 != ctx->r1) {
        // 0x8003F6E0: nop
    
            goto L_8003F710;
    }
    // 0x8003F6E0: nop

L_8003F6E4:
    // 0x8003F6E4: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x8003F6E8: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003F6EC: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8003F6F0: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8003F6F4: sh          $t3, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r11;
    // 0x8003F6F8: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x8003F6FC: nop

    // 0x8003F700: slti        $at, $t4, 0x15
    ctx->r1 = SIGNED(ctx->r12) < 0X15 ? 1 : 0;
    // 0x8003F704: bne         $at, $zero, L_8003F710
    if (ctx->r1 != 0) {
        // 0x8003F708: nop
    
            goto L_8003F710;
    }
    // 0x8003F708: nop

    // 0x8003F70C: sh          $t6, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r14;
L_8003F710:
    // 0x8003F710: lbu         $t5, 0x4($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F714: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F718: bne         $t5, $at, L_8003F79C
    if (ctx->r13 != ctx->r1) {
        // 0x8003F71C: nop
    
            goto L_8003F79C;
    }
    // 0x8003F71C: nop

    // 0x8003F720: lbu         $t7, 0x5($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X5);
    // 0x8003F724: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8003F728: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8003F72C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003F730: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x8003F734: slti        $at, $t2, 0x79
    ctx->r1 = SIGNED(ctx->r10) < 0X79 ? 1 : 0;
    // 0x8003F738: bne         $at, $zero, L_8003F79C
    if (ctx->r1 != 0) {
        // 0x8003F73C: sb          $t9, 0x5($t0)
        MEM_B(0X5, ctx->r8) = ctx->r25;
            goto L_8003F79C;
    }
    // 0x8003F73C: sb          $t9, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r25;
    // 0x8003F740: sb          $t3, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r11;
    // 0x8003F744: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8003F748: nop

    // 0x8003F74C: lw          $a0, 0x1C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X1C);
    // 0x8003F750: nop

    // 0x8003F754: beq         $a0, $zero, L_8003F770
    if (ctx->r4 == 0) {
        // 0x8003F758: nop
    
            goto L_8003F770;
    }
    // 0x8003F758: nop

    // 0x8003F75C: jal         0x800096F8
    // 0x8003F760: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    audspat_point_stop(rdram, ctx);
        goto after_6;
    // 0x8003F760: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_6:
    // 0x8003F764: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8003F768: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F76C: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
L_8003F770:
    // 0x8003F770: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003F774: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003F778: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003F77C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8003F780: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003F784: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003F788: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003F78C: jal         0x80009558
    // 0x8003F790: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_7;
    // 0x8003F790: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_7:
    // 0x8003F794: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F798: nop

L_8003F79C:
    // 0x8003F79C: lbu         $t7, 0x4($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F7A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003F7A4: bne         $t7, $at, L_8003F808
    if (ctx->r15 != ctx->r1) {
        // 0x8003F7A8: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8003F808;
    }
    // 0x8003F7A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003F7AC: sw          $t8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r24;
    // 0x8003F7B0: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8003F7B4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003F7B8: jal         0x800AFC3C
    // 0x8003F7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_8;
    // 0x8003F7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8003F7C0: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x8003F7C4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F7C8: ori         $t2, $t9, 0x4000
    ctx->r10 = ctx->r25 | 0X4000;
    // 0x8003F7CC: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x8003F7D0: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8003F7D4: lh          $t3, 0x6($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X6);
    // 0x8003F7D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003F7DC: subu        $t6, $t3, $t4
    ctx->r14 = SUB32(ctx->r11, ctx->r12);
    // 0x8003F7E0: sh          $t6, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r14;
    // 0x8003F7E4: lh          $t5, 0x6($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X6);
    // 0x8003F7E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F7EC: bgtz        $t5, L_8003F808
    if (SIGNED(ctx->r13) > 0) {
        // 0x8003F7F0: nop
    
            goto L_8003F808;
    }
    // 0x8003F7F0: nop

    // 0x8003F7F4: sh          $t7, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r15;
    // 0x8003F7F8: jal         0x8000FFB8
    // 0x8003F7FC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    free_object(rdram, ctx);
        goto after_9;
    // 0x8003F7FC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_9:
    // 0x8003F800: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F804: nop

L_8003F808:
    // 0x8003F808: lbu         $t8, 0x4($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F80C: nop

    // 0x8003F810: beq         $t8, $zero, L_8003F838
    if (ctx->r24 == 0) {
        // 0x8003F814: lw          $t3, 0x74($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X74);
            goto L_8003F838;
    }
    // 0x8003F814: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8003F818: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x8003F81C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F820: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8003F824: lwc1        $f16, 0x6214($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6214);
    // 0x8003F828: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003F82C: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8003F830: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8003F834: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
L_8003F838:
    // 0x8003F838: lh          $t2, 0x18($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X18);
    // 0x8003F83C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8003F840: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x8003F844: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
L_8003F848:
    // 0x8003F848: lbu         $t5, 0x4($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F84C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8003F850: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x8003F854: beq         $at, $zero, L_8003FC38
    if (ctx->r1 == 0) {
        // 0x8003F858: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003FC38;
    }
    // 0x8003F858: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F85C: lb          $t8, 0x1D6($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X1D6);
    // 0x8003F860: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F864: beq         $t8, $at, L_8003F8BC
    if (ctx->r24 == ctx->r1) {
        // 0x8003F868: addiu       $a1, $zero, 0x3C
        ctx->r5 = ADD32(0, 0X3C);
            goto L_8003F8BC;
    }
    // 0x8003F868: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8003F86C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003F870: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003F874: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003F878: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003F87C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003F880: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003F884: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003F888: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003F88C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003F890: sub.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f10.d - ctx->f8.d;
    // 0x8003F894: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8003F898: div.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8003F89C: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8003F8A0: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x8003F8A4: div.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8003F8A8: sub.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8003F8AC: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x8003F8B0: sub.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8003F8B4: b           L_8003F8DC
    // 0x8003F8B8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
        goto L_8003F8DC;
    // 0x8003F8B8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_8003F8BC:
    // 0x8003F8BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003F8C0: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x8003F8C4: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x8003F8C8: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8003F8CC: nop

    // 0x8003F8D0: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x8003F8D4: addu        $t4, $t9, $t2
    ctx->r12 = ADD32(ctx->r25, ctx->r10);
    // 0x8003F8D8: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
L_8003F8DC:
    // 0x8003F8DC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8003F8E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003F8E4: lbu         $v0, 0x18($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X18);
    // 0x8003F8E8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8003F8EC: beq         $v0, $at, L_8003F900
    if (ctx->r2 == ctx->r1) {
        // 0x8003F8F0: sra         $t5, $a1, 1
        ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8003F900;
    }
    // 0x8003F8F0: sra         $t5, $a1, 1
    ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8003F8F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003F8F8: bne         $v0, $at, L_8003F904
    if (ctx->r2 != ctx->r1) {
        // 0x8003F8FC: nop
    
            goto L_8003F904;
    }
    // 0x8003F8FC: nop

L_8003F900:
    // 0x8003F900: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
L_8003F904:
    // 0x8003F904: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003F908: nop

    // 0x8003F90C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8003F910: nop

    // 0x8003F914: beq         $a0, $zero, L_8003FB68
    if (ctx->r4 == 0) {
        // 0x8003F918: nop
    
            goto L_8003FB68;
    }
    // 0x8003F918: nop

    // 0x8003F91C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8003F920: nop

    // 0x8003F924: bne         $a0, $t8, L_8003F95C
    if (ctx->r4 != ctx->r24) {
        // 0x8003F928: addiu       $a0, $zero, 0x1C2
        ctx->r4 = ADD32(0, 0X1C2);
            goto L_8003F95C;
    }
    // 0x8003F928: addiu       $a0, $zero, 0x1C2
    ctx->r4 = ADD32(0, 0X1C2);
    // 0x8003F92C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x8003F930: jal         0x8000C8B4
    // 0x8003F934: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    normalise_time(rdram, ctx);
        goto after_10;
    // 0x8003F934: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_10:
    // 0x8003F938: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F93C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8003F940: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8003F944: nop

    // 0x8003F948: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003F94C: beq         $at, $zero, L_8003FB68
    if (ctx->r1 == 0) {
        // 0x8003F950: nop
    
            goto L_8003FB68;
    }
    // 0x8003F950: nop

    // 0x8003F954: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003F958: nop

L_8003F95C:
    // 0x8003F95C: lbu         $t9, 0x13($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X13);
    // 0x8003F960: nop

    // 0x8003F964: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003F968: beq         $at, $zero, L_8003FB68
    if (ctx->r1 == 0) {
        // 0x8003F96C: nop
    
            goto L_8003FB68;
    }
    // 0x8003F96C: nop

    // 0x8003F970: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003F974: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003F978: lw          $t2, 0x40($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X40);
    // 0x8003F97C: nop

    // 0x8003F980: lb          $t4, 0x54($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X54);
    // 0x8003F984: nop

    // 0x8003F988: bne         $t4, $at, L_8003FB68
    if (ctx->r12 != ctx->r1) {
        // 0x8003F98C: nop
    
            goto L_8003FB68;
    }
    // 0x8003F98C: nop

    // 0x8003F990: lw          $t1, 0x64($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X64);
    // 0x8003F994: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003F998: sb          $t6, 0x187($t1)
    MEM_B(0X187, ctx->r9) = ctx->r14;
    // 0x8003F99C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003F9A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F9A4: lbu         $v0, 0x18($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X18);
    // 0x8003F9A8: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003F9AC: bne         $v0, $at, L_8003F9F4
    if (ctx->r2 != ctx->r1) {
        // 0x8003F9B0: addiu       $t7, $zero, 0x11
        ctx->r15 = ADD32(0, 0X11);
            goto L_8003F9F4;
    }
    // 0x8003F9B0: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x8003F9B4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003F9B8: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F9BC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003F9C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003F9C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003F9C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003F9CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8003F9D0: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8003F9D4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003F9D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003F9DC: jal         0x8003FC44
    // 0x8003F9E0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_11;
    // 0x8003F9E0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_11:
    // 0x8003F9E4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F9E8: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003F9EC: b           L_8003FAC4
    // 0x8003F9F0: lb          $t4, 0x1D8($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X1D8);
        goto L_8003FAC4;
    // 0x8003F9F0: lb          $t4, 0x1D8($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X1D8);
L_8003F9F4:
    // 0x8003F9F4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003F9F8: bne         $v0, $at, L_8003FAAC
    if (ctx->r2 != ctx->r1) {
        // 0x8003F9FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003FAAC;
    }
    // 0x8003F9FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003FA00: lh          $t3, 0x18E($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X18E);
    // 0x8003FA04: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8003FA08: blez        $t3, L_8003FA5C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8003FA0C: addiu       $a0, $zero, 0x152
        ctx->r4 = ADD32(0, 0X152);
            goto L_8003FA5C;
    }
    // 0x8003FA0C: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    // 0x8003FA10: lb          $t9, 0x189($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X189);
    // 0x8003FA14: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8003FA18: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8003FA1C: bne         $at, $zero, L_8003FA5C
    if (ctx->r1 != 0) {
        // 0x8003FA20: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8003FA5C;
    }
    // 0x8003FA20: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8003FA24: sb          $t2, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r10;
    // 0x8003FA28: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003FA2C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003FA30: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003FA34: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8003FA38: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003FA3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003FA40: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003FA44: jal         0x80009558
    // 0x8003FA48: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_12;
    // 0x8003FA48: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_12:
    // 0x8003FA4C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003FA50: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003FA54: b           L_8003FAC4
    // 0x8003FA58: lb          $t4, 0x1D8($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X1D8);
        goto L_8003FAC4;
    // 0x8003FA58: lb          $t4, 0x1D8($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X1D8);
L_8003FA5C:
    // 0x8003FA5C: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8003FA60: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x8003FA64: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x8003FA68: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8003FA6C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8003FA70: addiu       $t7, $t6, 0x1C
    ctx->r15 = ADD32(ctx->r14, 0X1C);
    // 0x8003FA74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8003FA78: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003FA7C: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8003FA80: jal         0x80009558
    // 0x8003FA84: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_13;
    // 0x8003FA84: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_13:
    // 0x8003FA88: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003FA8C: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003FA90: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8003FA94: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003FA98: sb          $t8, 0x187($t1)
    MEM_B(0X187, ctx->r9) = ctx->r24;
    // 0x8003FA9C: sb          $t3, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r11;
    // 0x8003FAA0: b           L_8003FAC0
    // 0x8003FAA4: sb          $zero, 0x5($t0)
    MEM_B(0X5, ctx->r8) = 0;
        goto L_8003FAC0;
    // 0x8003FAA4: sb          $zero, 0x5($t0)
    MEM_B(0X5, ctx->r8) = 0;
    // 0x8003FAA8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8003FAAC:
    // 0x8003FAAC: bne         $v0, $at, L_8003FAC0
    if (ctx->r2 != ctx->r1) {
        // 0x8003FAB0: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8003FAC0;
    }
    // 0x8003FAB0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8003FAB4: sb          $t9, 0x187($t1)
    MEM_B(0X187, ctx->r9) = ctx->r25;
    // 0x8003FAB8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8003FABC: sb          $t2, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r10;
L_8003FAC0:
    // 0x8003FAC0: lb          $t4, 0x1D8($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X1D8);
L_8003FAC4:
    // 0x8003FAC4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8003FAC8: bne         $t4, $zero, L_8003FAF0
    if (ctx->r12 != 0) {
        // 0x8003FACC: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8003FAF0;
    }
    // 0x8003FACC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003FAD0: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x8003FAD4: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8003FAD8: jal         0x80072348
    // 0x8003FADC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    rumble_set(rdram, ctx);
        goto after_14;
    // 0x8003FADC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_14:
    // 0x8003FAE0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003FAE4: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003FAE8: nop

    // 0x8003FAEC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_8003FAF0:
    // 0x8003FAF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8003FAF4: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8003FAF8: nop

    // 0x8003FAFC: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x8003FB00: nop

    // 0x8003FB04: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x8003FB08: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x8003FB0C: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8003FB10: bne         $v0, $t8, L_8003FB28
    if (ctx->r2 != ctx->r24) {
        // 0x8003FB14: nop
    
            goto L_8003FB28;
    }
    // 0x8003FB14: nop

    // 0x8003FB18: lh          $t3, 0x0($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X0);
    // 0x8003FB1C: nop

    // 0x8003FB20: beq         $v0, $t3, L_8003FB3C
    if (ctx->r2 == ctx->r11) {
        // 0x8003FB24: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8003FB3C;
    }
    // 0x8003FB24: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_8003FB28:
    // 0x8003FB28: lbu         $t2, 0x1EF($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X1EF);
    // 0x8003FB2C: nop

    // 0x8003FB30: ori         $t4, $t2, 0x2
    ctx->r12 = ctx->r10 | 0X2;
    // 0x8003FB34: sb          $t4, 0x1EF($t9)
    MEM_B(0X1EF, ctx->r25) = ctx->r12;
    // 0x8003FB38: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_8003FB3C:
    // 0x8003FB3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003FB40: lbu         $v0, 0x18($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X18);
    // 0x8003FB44: nop

    // 0x8003FB48: beq         $v0, $at, L_8003FB68
    if (ctx->r2 == ctx->r1) {
        // 0x8003FB4C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8003FB68;
    }
    // 0x8003FB4C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003FB50: beq         $v0, $at, L_8003FB68
    if (ctx->r2 == ctx->r1) {
        // 0x8003FB54: nop
    
            goto L_8003FB68;
    }
    // 0x8003FB54: nop

    // 0x8003FB58: jal         0x8000FFB8
    // 0x8003FB5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_15;
    // 0x8003FB5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8003FB60: b           L_8003FC38
    // 0x8003FB64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003FC38;
    // 0x8003FB64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FB68:
    // 0x8003FB68: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8003FB6C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8003FB70: lbu         $t3, 0x4($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X4);
    // 0x8003FB74: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x8003FB78: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8003FB7C: beq         $at, $zero, L_8003FC34
    if (ctx->r1 == 0) {
        // 0x8003FB80: sw          $t7, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r15;
            goto L_8003FC34;
    }
    // 0x8003FB80: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8003FB84: addiu       $a0, $zero, -0x528
    ctx->r4 = ADD32(0, -0X528);
    // 0x8003FB88: jal         0x8000C8B4
    // 0x8003FB8C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    normalise_time(rdram, ctx);
        goto after_16;
    // 0x8003FB8C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_16:
    // 0x8003FB90: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003FB94: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8003FB98: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8003FB9C: nop

    // 0x8003FBA0: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003FBA4: beq         $at, $zero, L_8003FC38
    if (ctx->r1 == 0) {
        // 0x8003FBA8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003FC38;
    }
    // 0x8003FBA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003FBAC: lbu         $v0, 0x18($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X18);
    // 0x8003FBB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003FBB4: bne         $v0, $at, L_8003FBC4
    if (ctx->r2 != ctx->r1) {
        // 0x8003FBB8: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8003FBC4;
    }
    // 0x8003FBB8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8003FBBC: b           L_8003FC34
    // 0x8003FBC0: sb          $t9, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r25;
        goto L_8003FC34;
    // 0x8003FBC0: sb          $t9, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r25;
L_8003FBC4:
    // 0x8003FBC4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003FBC8: bne         $v0, $at, L_8003FC00
    if (ctx->r2 != ctx->r1) {
        // 0x8003FBCC: addiu       $a3, $zero, 0x2C
        ctx->r7 = ADD32(0, 0X2C);
            goto L_8003FC00;
    }
    // 0x8003FBCC: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003FBD0: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8003FBD4: sb          $t5, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r13;
    // 0x8003FBD8: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003FBDC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003FBE0: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003FBE4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8003FBE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003FBEC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003FBF0: jal         0x80009558
    // 0x8003FBF4: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_17;
    // 0x8003FBF4: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_17:
    // 0x8003FBF8: b           L_8003FC38
    // 0x8003FBFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003FC38;
    // 0x8003FBFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FC00:
    // 0x8003FC00: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003FC04: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003FC08: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003FC0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003FC10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003FC14: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x8003FC18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003FC1C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8003FC20: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003FC24: jal         0x8003FC44
    // 0x8003FC28: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_18;
    // 0x8003FC28: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_18:
    // 0x8003FC2C: jal         0x8000FFB8
    // 0x8003FC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_19;
    // 0x8003FC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_8003FC34:
    // 0x8003FC34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FC38:
    // 0x8003FC38: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003FC3C: jr          $ra
    // 0x8003FC40: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003FC40: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800BBDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBDDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BBDE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BBDE4: jal         0x800BBE08
    // 0x800BBDE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800BBE08(rdram, ctx);
        goto after_0;
    // 0x800BBDE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BBDEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BBDF0: jal         0x800BBF78
    // 0x800BBDF4: nop

    func_800BBF78(rdram, ctx);
        goto after_1;
    // 0x800BBDF4: nop

    after_1:
    // 0x800BBDF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BBDFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BBE00: jr          $ra
    // 0x800BBE04: nop

    return;
    // 0x800BBE04: nop

;}
RECOMP_FUNC void ainode_tail_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001D1C0: addiu       $v1, $v1, -0x50F8
    ctx->r3 = ADD32(ctx->r3, -0X50F8);
    // 0x8001D1C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001D1C8: nop

    // 0x8001D1CC: beq         $a0, $v0, L_8001D1DC
    if (ctx->r4 == ctx->r2) {
        // 0x8001D1D0: nop
    
            goto L_8001D1DC;
    }
    // 0x8001D1D0: nop

    // 0x8001D1D4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8001D1D8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8001D1DC:
    // 0x8001D1DC: jr          $ra
    // 0x8001D1E0: nop

    return;
    // 0x8001D1E0: nop

;}
RECOMP_FUNC void fileselect_render_element(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CC28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008CC2C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008CC30: addiu       $t2, $t2, -0xB54
    ctx->r10 = ADD32(ctx->r10, -0XB54);
    // 0x8008CC34: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x8008CC38: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008CC3C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008CC40: addiu       $t3, $t3, -0x89C
    ctx->r11 = ADD32(ctx->r11, -0X89C);
    // 0x8008CC44: addiu       $t0, $t0, -0xB5C
    ctx->r8 = ADD32(ctx->r8, -0XB5C);
    // 0x8008CC48: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8008CC4C: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x8008CC50: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8008CC54: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008CC58: addiu       $t8, $a1, -0x9F
    ctx->r24 = ADD32(ctx->r5, -0X9F);
    // 0x8008CC5C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8008CC60: addiu       $t1, $t1, -0xB58
    ctx->r9 = ADD32(ctx->r9, -0XB58);
    // 0x8008CC64: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008CC68: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x8008CC6C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008CC70: addiu       $v1, $v1, -0x8A4
    ctx->r3 = ADD32(ctx->r3, -0X8A4);
    // 0x8008CC74: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8008CC78: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8008CC7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008CC80: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8008CC84: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008CC88: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008CC8C: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x8008CC90: sb          $t4, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r12;
    // 0x8008CC94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CC98: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8008CC9C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8008CCA0: sb          $a3, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r7;
    // 0x8008CCA4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8008CCA8: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x8008CCAC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8008CCB0: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x8008CCB4: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x8008CCB8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008CCBC: addiu       $t6, $zero, 0x77
    ctx->r14 = ADD32(0, 0X77);
    // 0x8008CCC0: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x8008CCC4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8008CCC8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008CCCC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008CCD0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008CCD4: swc1        $f10, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f10.u32l;
    // 0x8008CCD8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008CCDC: jal         0x8009CA60
    // 0x8008CCE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    menu_element_render(rdram, ctx);
        goto after_0;
    // 0x8008CCE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8008CCE4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8008CCE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CCEC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008CCF0: sb          $t4, -0xB5C($at)
    MEM_B(-0XB5C, ctx->r1) = ctx->r12;
    // 0x8008CCF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CCF8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8008CCFC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8008CD00: sb          $t6, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r14;
    // 0x8008CD04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CD08: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008CD0C: sb          $t5, -0xB54($at)
    MEM_B(-0XB54, ctx->r1) = ctx->r13;
    // 0x8008CD10: addiu       $t9, $t8, -0xA1
    ctx->r25 = ADD32(ctx->r24, -0XA1);
    // 0x8008CD14: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8008CD18: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008CD1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CD20: addiu       $v1, $v1, -0x8A4
    ctx->r3 = ADD32(ctx->r3, -0X8A4);
    // 0x8008CD24: sw          $t7, -0x89C($at)
    MEM_W(-0X89C, ctx->r1) = ctx->r15;
    // 0x8008CD28: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008CD2C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CD30: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008CD34: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008CD38: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x8008CD3C: swc1        $f18, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f18.u32l;
    // 0x8008CD40: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008CD44: addiu       $t7, $zero, 0x79
    ctx->r15 = ADD32(0, 0X79);
    // 0x8008CD48: subu        $t8, $t7, $t5
    ctx->r24 = SUB32(ctx->r15, ctx->r13);
    // 0x8008CD4C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8008CD50: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008CD54: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008CD58: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x8008CD5C: jal         0x8009CA60
    // 0x8008CD60: swc1        $f6, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f6.u32l;
    menu_element_render(rdram, ctx);
        goto after_1;
    // 0x8008CD60: swc1        $f6, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f6.u32l;
    after_1:
    // 0x8008CD64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CD68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008CD6C: jr          $ra
    // 0x8008CD70: nop

    return;
    // 0x8008CD70: nop

;}
RECOMP_FUNC void obj_init_lensflareswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004094C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040954: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80040958: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8004095C: jal         0x800ACF60
    // 0x80040960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    lensflare_override_add(rdram, ctx);
        goto after_0;
    // 0x80040960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80040964: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80040968: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004096C: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x80040970: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80040974: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80040978: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004097C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040980: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x80040984: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80040988: nop

    // 0x8004098C: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80040990: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x80040994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004099C: jr          $ra
    // 0x800409A0: nop

    return;
    // 0x800409A0: nop

;}
RECOMP_FUNC void render_bubble_trap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800138A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800138AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800138B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800138B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800138B8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800138BC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800138C0: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    // 0x800138C4: jal         0x80070320
    // 0x800138C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800138C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x800138CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800138D0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800138D4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800138D8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800138DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800138E0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800138E4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800138E8: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800138EC: nop

    // 0x800138F0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800138F4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800138F8: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800138FC: nop

    // 0x80013900: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80013904: jal         0x80069D20
    // 0x80013908: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    cam_get_active_camera(rdram, ctx);
        goto after_1;
    // 0x80013908: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x8001390C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80013910: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80013914: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80013918: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8001391C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80013920: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80013924: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80013928: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8001392C: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80013930: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80013934: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80013938: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x8001393C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80013940: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80013944: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80013948: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8001394C: jal         0x800C9AD0
    // 0x80013950: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80013950: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80013954: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80013958: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001395C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80013960: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80013964: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80013968: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001396C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80013970: bc1f        L_800139AC
    if (!c1cs) {
        // 0x80013974: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800139AC;
    }
    // 0x80013974: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80013978: lh          $t6, 0x1A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A);
    // 0x8001397C: nop

    // 0x80013980: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80013984: nop

    // 0x80013988: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001398C: nop

    // 0x80013990: div.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80013994: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80013998: nop

    // 0x8001399C: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800139A0: nop

    // 0x800139A4: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800139A8: nop

L_800139AC:
    // 0x800139AC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800139B0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800139B4: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800139B8: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800139BC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800139C0: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800139C4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800139C8: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800139CC: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800139D0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x800139D4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800139D8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800139DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800139E0: addiu       $a2, $a2, -0x516C
    ctx->r6 = ADD32(ctx->r6, -0X516C);
    // 0x800139E4: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x800139E8: addiu       $a0, $a0, -0x5174
    ctx->r4 = ADD32(ctx->r4, -0X5174);
    // 0x800139EC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800139F0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800139F4: jal         0x80068514
    // 0x800139F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    render_sprite_billboard(rdram, ctx);
        goto after_3;
    // 0x800139F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x800139FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013A00: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80013A04: jr          $ra
    // 0x80013A08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80013A08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sndp_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000410C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004114: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80004118: lbu         $t7, 0x3E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3E);
    // 0x8000411C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80004120: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x80004124: beq         $t8, $zero, L_80004158
    if (ctx->r24 == 0) {
        // 0x80004128: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_80004158;
    }
    // 0x80004128: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000412C: lw          $t9, -0x3944($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3944);
    // 0x80004130: addiu       $a1, $t6, 0xC
    ctx->r5 = ADD32(ctx->r14, 0XC);
    // 0x80004134: lw          $a0, 0x38($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X38);
    // 0x80004138: jal         0x800C98B0
    // 0x8000413C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    alSynStopVoice(rdram, ctx);
        goto after_0;
    // 0x8000413C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80004140: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80004144: lw          $t0, -0x3944($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3944);
    // 0x80004148: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000414C: lw          $a0, 0x38($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X38);
    // 0x80004150: jal         0x800C9930
    // 0x80004154: nop

    alSynFreeVoice(rdram, ctx);
        goto after_1;
    // 0x80004154: nop

    after_1:
L_80004158:
    // 0x80004158: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000415C: jal         0x80004520
    // 0x80004160: nop

    sndp_deallocate(rdram, ctx);
        goto after_2;
    // 0x80004160: nop

    after_2:
    // 0x80004164: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004168: lw          $a0, -0x3944($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3944);
    // 0x8000416C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80004170: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80004174: jal         0x800041FC
    // 0x80004178: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    static_3_800041FC(rdram, ctx);
        goto after_3;
    // 0x80004178: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_3:
    // 0x8000417C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004184: jr          $ra
    // 0x80004188: nop

    return;
    // 0x80004188: nop

;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6700: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800D6704: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D6708: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800D670C: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x800D6710: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D6714: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D6718: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800D671C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800D6720: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D6724: bne         $v1, $v0, L_800D6738
    if (ctx->r3 != ctx->r2) {
        // 0x800D6728: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_800D6738;
    }
    // 0x800D6728: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800D672C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800D6730: b           L_800D6740
    // 0x800D6734: addiu       $s3, $s3, 0x4934
    ctx->r19 = ADD32(ctx->r19, 0X4934);
        goto L_800D6740;
    // 0x800D6734: addiu       $s3, $s3, 0x4934
    ctx->r19 = ADD32(ctx->r19, 0X4934);
L_800D6738:
    // 0x800D6738: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800D673C: addiu       $s3, $s3, 0x4920
    ctx->r19 = ADD32(ctx->r19, 0X4920);
L_800D6740:
    // 0x800D6740: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x800D6744: bne         $v0, $at, L_800D6754
    if (ctx->r2 != ctx->r1) {
        // 0x800D6748: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_800D6754;
    }
    // 0x800D6748: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x800D674C: b           L_800D6774
    // 0x800D6750: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_800D6774;
    // 0x800D6750: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_800D6754:
    // 0x800D6754: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800D6758: beq         $v0, $at, L_800D6770
    if (ctx->r2 == ctx->r1) {
        // 0x800D675C: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_800D6770;
    }
    // 0x800D675C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800D6760: beq         $v1, $v0, L_800D6770
    if (ctx->r3 == ctx->r2) {
        // 0x800D6764: nop
    
            goto L_800D6770;
    }
    // 0x800D6764: nop

    // 0x800D6768: b           L_800D6770
    // 0x800D676C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_800D6770;
    // 0x800D676C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_800D6770:
    // 0x800D6770: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800D6774:
    // 0x800D6774: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800D6778: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800D677C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800D6780: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800D6784: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800D6788: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800D678C: beq         $v0, $at, L_800D67A0
    if (ctx->r2 == ctx->r1) {
        // 0x800D6790: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_800D67A0;
    }
    // 0x800D6790: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800D6794: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x800D6798: bnel        $v0, $at, L_800D67DC
    if (ctx->r2 != ctx->r1) {
        // 0x800D679C: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_800D67DC;
    }
    goto skip_0;
    // 0x800D679C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_800D67A0:
    // 0x800D67A0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800D67A4: bgtzl       $t4, L_800D67DC
    if (SIGNED(ctx->r12) > 0) {
        // 0x800D67A8: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_800D67DC;
    }
    goto skip_1;
    // 0x800D67A8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x800D67AC: bltz        $t4, L_800D67BC
    if (SIGNED(ctx->r12) < 0) {
        // 0x800D67B0: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_800D67BC;
    }
    // 0x800D67B0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800D67B4: b           L_800D67DC
    // 0x800D67B8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_800D67DC;
    // 0x800D67B8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_800D67BC:
    // 0x800D67BC: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800D67C0: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x800D67C4: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800D67C8: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x800D67CC: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800D67D0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800D67D4: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800D67D8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_800D67DC:
    // 0x800D67DC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800D67E0: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x800D67E4: bne         $t2, $zero, L_800D6800
    if (ctx->r10 != 0) {
        // 0x800D67E8: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_800D6800;
    }
    // 0x800D67E8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D67EC: bnel        $t3, $zero, L_800D6804
    if (ctx->r11 != 0) {
        // 0x800D67F0: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_800D6804;
    }
    goto skip_2;
    // 0x800D67F0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x800D67F4: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x800D67F8: beql        $t4, $zero, L_800D683C
    if (ctx->r12 == 0) {
        // 0x800D67FC: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_800D683C;
    }
    goto skip_3;
    // 0x800D67FC: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_800D6800:
    // 0x800D6800: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_800D6804:
    // 0x800D6804: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800D6808: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800D680C: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800D6810: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800D6814: jal         0x800CEA8C
    // 0x800D6818: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x800D6818: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x800D681C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800D6820: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x800D6824: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800D6828: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x800D682C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800D6830: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x800D6834: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800D6838: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_800D683C:
    // 0x800D683C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D6840: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800D6844: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800D6848: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800D684C: jal         0x800CEAC8
    // 0x800D6850: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800D6850: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x800D6854: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800D6858: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x800D685C: bltz        $v0, L_800D690C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D6860: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800D690C;
    }
    // 0x800D6860: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800D6864: bgtz        $v0, L_800D6874
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D6868: nop
    
            goto L_800D6874;
    }
    // 0x800D6868: nop

    // 0x800D686C: beql        $v1, $zero, L_800D6910
    if (ctx->r3 == 0) {
        // 0x800D6870: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_800D6910;
    }
    goto skip_4;
    // 0x800D6870: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_800D6874:
    // 0x800D6874: blez        $s0, L_800D690C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D6878: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_800D690C;
    }
    // 0x800D6878: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800D687C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800D6880: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x800D6884: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800D6888: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800D688C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800D6890: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800D6894: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_800D6898:
    // 0x800D6898: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800D689C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800D68A0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800D68A4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800D68A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D68AC: jal         0x800D7470
    // 0x800D68B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x800D68B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x800D68B4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800D68B8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800D68BC: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x800D68C0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D68C4: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x800D68C8: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800D68CC: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x800D68D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D68D4: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x800D68D8: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800D68DC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800D68E0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800D68E4: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800D68E8: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800D68EC: bltz        $t8, L_800D690C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800D68F0: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_800D690C;
    }
    // 0x800D68F0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800D68F4: bgtz        $t8, L_800D6904
    if (SIGNED(ctx->r24) > 0) {
        // 0x800D68F8: nop
    
            goto L_800D6904;
    }
    // 0x800D68F8: nop

    // 0x800D68FC: beql        $t9, $zero, L_800D6910
    if (ctx->r25 == 0) {
        // 0x800D6900: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_800D6910;
    }
    goto skip_5;
    // 0x800D6900: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_800D6904:
    // 0x800D6904: bgtzl       $s0, L_800D6898
    if (SIGNED(ctx->r16) > 0) {
        // 0x800D6908: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_800D6898;
    }
    goto skip_6;
    // 0x800D6908: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_800D690C:
    // 0x800D690C: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_800D6910:
    // 0x800D6910: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x800D6914: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x800D6918: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x800D691C: jal         0x800CE170
    // 0x800D6920: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800D6920: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x800D6924: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x800D6928: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x800D692C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D6930: beq         $at, $zero, L_800D693C
    if (ctx->r1 == 0) {
        // 0x800D6934: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_800D693C;
    }
    // 0x800D6934: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x800D6938: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_800D693C:
    // 0x800D693C: bgezl       $a0, L_800D6980
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800D6940: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800D6980;
    }
    goto skip_7;
    // 0x800D6940: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x800D6944: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x800D6948: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800D694C: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x800D6950: bnel        $t7, $at, L_800D6980
    if (ctx->r15 != ctx->r1) {
        // 0x800D6954: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800D6980;
    }
    goto skip_8;
    // 0x800D6954: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x800D6958: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x800D695C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x800D6960: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800D6964: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800D6968: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x800D696C: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x800D6970: blez        $s0, L_800D697C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D6974: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_800D697C;
    }
    // 0x800D6974: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x800D6978: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_800D697C:
    // 0x800D697C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800D6980:
    // 0x800D6980: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D6984: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D6988: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800D698C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800D6990: jr          $ra
    // 0x800D6994: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800D6994: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void obj_init_boost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004210C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80042118: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8004211C: jal         0x8001E29C
    // 0x80042120: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80042120: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80042124: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80042128: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8004212C: lb          $t7, 0x8($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X8);
    // 0x80042130: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x80042134: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x80042138: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8004213C: sw          $t9, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r25;
    // 0x80042140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042148: jr          $ra
    // 0x8004214C: nop

    return;
    // 0x8004214C: nop

;}
RECOMP_FUNC void unload_level_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_netplay_gameplay_level_end(uint8_t*, recomp_context*); dkr_netplay_gameplay_level_end(rdram, ctx);
    // 0x8006CC14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CC18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CC1C: jal         0x800710B0
    // 0x8006CC20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006CC20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006CC24: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006CC28: lb          $t6, -0x2C74($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2C74);
    // 0x8006CC2C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006CC30: bne         $t6, $zero, L_8006CC5C
    if (ctx->r14 != 0) {
        // 0x8006CC34: nop
    
            goto L_8006CC5C;
    }
    // 0x8006CC34: nop

    // 0x8006CC38: lb          $t7, -0x2C10($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2C10);
    // 0x8006CC3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CC40: beq         $t7, $at, L_8006CC54
    if (ctx->r15 == ctx->r1) {
        // 0x8006CC44: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8006CC54;
    }
    // 0x8006CC44: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006CC48: jal         0x80077A54
    // 0x8006CC4C: nop

    gfxtask_wait(rdram, ctx);
        goto after_1;
    // 0x8006CC4C: nop

    after_1:
    // 0x8006CC50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8006CC54:
    // 0x8006CC54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CC58: sb          $t8, -0x2C74($at)
    MEM_B(-0X2C74, ctx->r1) = ctx->r24;
L_8006CC5C:
    // 0x8006CC5C: jal         0x8006BEFC
    // 0x8006CC60: nop

    level_free(rdram, ctx);
        goto after_2;
    // 0x8006CC60: nop

    after_2:
    // 0x8006CC64: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CC68: jal         0x800C01D8
    // 0x8006CC6C: addiu       $a0, $a0, -0x2C0C
    ctx->r4 = ADD32(ctx->r4, -0X2C0C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8006CC6C: addiu       $a0, $a0, -0x2C0C
    ctx->r4 = ADD32(ctx->r4, -0X2C0C);
    after_3:
    // 0x8006CC70: jal         0x800AE270
    // 0x8006CC74: nop

    reset_particles(rdram, ctx);
        goto after_4;
    // 0x8006CC74: nop

    after_4:
    // 0x8006CC78: jal         0x800A003C
    // 0x8006CC7C: nop

    hud_free(rdram, ctx);
        goto after_5;
    // 0x8006CC7C: nop

    after_5:
    // 0x8006CC80: jal         0x800C30CC
    // 0x8006CC84: nop

    free_game_text_table(rdram, ctx);
        goto after_6;
    // 0x8006CC84: nop

    after_6:
    // 0x8006CC88: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006CC8C: lw          $t9, 0x34E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X34E8);
    // 0x8006CC90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006CC94: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006CC98: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8006CC9C: lw          $t1, 0x11F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F0);
    // 0x8006CCA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006CCA4: addiu       $v1, $v1, 0x11F8
    ctx->r3 = ADD32(ctx->r3, 0X11F8);
    // 0x8006CCA8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8006CCAC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8006CCB0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8006CCB4: lui         $t3, 0xE900
    ctx->r11 = S32(0XE900 << 16);
    // 0x8006CCB8: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8006CCBC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8006CCC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006CCC4: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006CCC8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8006CCCC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006CCD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006CCD4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006CCD8: jal         0x800710B0
    // 0x8006CCDC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    mempool_free_timer(rdram, ctx);
        goto after_7;
    // 0x8006CCDC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    after_7:
    // 0x8006CCE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CCE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CCE8: jr          $ra
    // 0x8006CCEC: nop

    return;
    // 0x8006CCEC: nop

;}
RECOMP_FUNC void light_add_from_level_object_entry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031CAC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80031CB0: addiu       $v1, $v1, -0x36A4
    ctx->r3 = ADD32(ctx->r3, -0X36A4);
    // 0x80031CB4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80031CB8: lw          $t6, -0x36A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36A8);
    // 0x80031CBC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031CC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031CC4: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80031CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031CCC: beq         $at, $zero, L_80031F78
    if (ctx->r1 == 0) {
        // 0x80031CD0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80031F78;
    }
    // 0x80031CD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80031CD4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80031CD8: lw          $t7, -0x36B0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X36B0);
    // 0x80031CDC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80031CE0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80031CE4: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x80031CE8: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80031CEC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80031CF0: lbu         $t2, 0x8($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X8);
    // 0x80031CF4: nop

    // 0x80031CF8: andi        $t3, $t2, 0xF0
    ctx->r11 = ctx->r10 & 0XF0;
    // 0x80031CFC: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80031D00: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
    // 0x80031D04: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x80031D08: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80031D0C: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x80031D10: sb          $t6, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r14;
    // 0x80031D14: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80031D18: nop

    // 0x80031D1C: andi        $t8, $t7, 0xE0
    ctx->r24 = ctx->r15 & 0XE0;
    // 0x80031D20: sra         $t9, $t8, 5
    ctx->r25 = S32(SIGNED(ctx->r24) >> 5);
    // 0x80031D24: sb          $t9, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r25;
    // 0x80031D28: lbu         $t1, 0x9($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X9);
    // 0x80031D2C: sb          $t3, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r11;
    // 0x80031D30: andi        $t2, $t1, 0x1F
    ctx->r10 = ctx->r9 & 0X1F;
    // 0x80031D34: sb          $t2, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r10;
    // 0x80031D38: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x80031D3C: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80031D40: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80031D44: beq         $a0, $zero, L_80031D70
    if (ctx->r4 == 0) {
        // 0x80031D48: sh          $zero, 0xA($a2)
        MEM_H(0XA, ctx->r6) = 0;
            goto L_80031D70;
    }
    // 0x80031D48: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
    // 0x80031D4C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80031D50: nop

    // 0x80031D54: swc1        $f4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f4.u32l;
    // 0x80031D58: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80031D5C: nop

    // 0x80031D60: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x80031D64: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80031D68: b           L_80031DB8
    // 0x80031D6C: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
        goto L_80031DB8;
    // 0x80031D6C: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_80031D70:
    // 0x80031D70: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x80031D74: nop

    // 0x80031D78: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80031D7C: nop

    // 0x80031D80: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80031D84: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
    // 0x80031D88: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x80031D8C: nop

    // 0x80031D90: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80031D94: nop

    // 0x80031D98: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80031D9C: swc1        $f4, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f4.u32l;
    // 0x80031DA0: lh          $t6, 0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X6);
    // 0x80031DA4: nop

    // 0x80031DA8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80031DAC: nop

    // 0x80031DB0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80031DB4: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_80031DB8:
    // 0x80031DB8: lbu         $t7, 0xA($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA);
    // 0x80031DBC: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
    // 0x80031DC0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80031DC4: sw          $t8, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r24;
    // 0x80031DC8: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x80031DCC: lbu         $t9, 0xB($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XB);
    // 0x80031DD0: sw          $zero, 0x30($a2)
    MEM_W(0X30, ctx->r6) = 0;
    // 0x80031DD4: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x80031DD8: sw          $t1, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r9;
    // 0x80031DDC: sh          $zero, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = 0;
    // 0x80031DE0: lbu         $t2, 0xC($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XC);
    // 0x80031DE4: sw          $zero, 0x34($a2)
    MEM_W(0X34, ctx->r6) = 0;
    // 0x80031DE8: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80031DEC: sw          $t3, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r11;
    // 0x80031DF0: sh          $zero, 0x40($a2)
    MEM_H(0X40, ctx->r6) = 0;
    // 0x80031DF4: lbu         $t4, 0xD($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XD);
    // 0x80031DF8: sw          $zero, 0x38($a2)
    MEM_W(0X38, ctx->r6) = 0;
    // 0x80031DFC: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80031E00: sw          $t5, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r13;
    // 0x80031E04: sh          $zero, 0x42($a2)
    MEM_H(0X42, ctx->r6) = 0;
    // 0x80031E08: sw          $zero, 0x44($a2)
    MEM_W(0X44, ctx->r6) = 0;
    // 0x80031E0C: lbu         $t6, 0x1C($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1C);
    // 0x80031E10: nop

    // 0x80031E14: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x80031E18: beq         $at, $zero, L_80031E9C
    if (ctx->r1 == 0) {
        // 0x80031E1C: nop
    
            goto L_80031E9C;
    }
    // 0x80031E1C: nop

    // 0x80031E20: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80031E24: jal         0x8006BDB0
    // 0x80031E28: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80031E28: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80031E2C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80031E30: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80031E34: lbu         $t7, 0x1C($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1C);
    // 0x80031E38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80031E3C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80031E40: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80031E44: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x80031E48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80031E4C: beq         $t0, $at, L_80031E9C
    if (ctx->r8 == ctx->r1) {
        // 0x80031E50: addiu       $t2, $t0, 0x14
        ctx->r10 = ADD32(ctx->r8, 0X14);
            goto L_80031E9C;
    }
    // 0x80031E50: addiu       $t2, $t0, 0x14
    ctx->r10 = ADD32(ctx->r8, 0X14);
    // 0x80031E54: sw          $t0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r8;
    // 0x80031E58: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80031E5C: sh          $zero, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = 0;
    // 0x80031E60: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x80031E64: sh          $zero, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = 0;
    // 0x80031E68: sh          $zero, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = 0;
    // 0x80031E6C: sw          $t2, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r10;
    // 0x80031E70: blez        $a0, L_80031E9C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80031E74: sh          $t1, 0x48($a2)
        MEM_H(0X48, ctx->r6) = ctx->r9;
            goto L_80031E9C;
    }
    // 0x80031E74: sh          $t1, 0x48($a2)
    MEM_H(0X48, ctx->r6) = ctx->r9;
    // 0x80031E78: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80031E7C:
    // 0x80031E7C: lhu         $t3, 0x4E($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X4E);
    // 0x80031E80: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80031E84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80031E88: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80031E8C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80031E90: sh          $t5, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r13;
    // 0x80031E94: bne         $at, $zero, L_80031E7C
    if (ctx->r1 != 0) {
        // 0x80031E98: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80031E7C;
    }
    // 0x80031E98: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80031E9C:
    // 0x80031E9C: lh          $t6, 0xE($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XE);
    // 0x80031EA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031EA4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80031EA8: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x80031EAC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80031EB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80031EB4: swc1        $f16, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f16.u32l;
    // 0x80031EB8: lh          $t7, 0x10($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X10);
    // 0x80031EBC: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x80031EC0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80031EC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80031EC8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80031ECC: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x80031ED0: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80031ED4: swc1        $f4, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f4.u32l;
    // 0x80031ED8: lh          $t8, 0x12($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X12);
    // 0x80031EDC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80031EE0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80031EE4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80031EE8: swc1        $f10, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f10.u32l;
    // 0x80031EEC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80031EF0: swc1        $f18, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f18.u32l;
    // 0x80031EF4: swc1        $f8, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f8.u32l;
    // 0x80031EF8: lh          $t9, 0x14($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X14);
    // 0x80031EFC: nop

    // 0x80031F00: sh          $t9, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r25;
    // 0x80031F04: lh          $t1, 0x18($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X18);
    // 0x80031F08: nop

    // 0x80031F0C: sh          $t1, 0x74($a2)
    MEM_H(0X74, ctx->r6) = ctx->r9;
    // 0x80031F10: lh          $t2, 0x18($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X18);
    // 0x80031F14: nop

    // 0x80031F18: beq         $t2, $zero, L_80031F28
    if (ctx->r10 == 0) {
        // 0x80031F1C: nop
    
            goto L_80031F28;
    }
    // 0x80031F1C: nop

    // 0x80031F20: b           L_80031F2C
    // 0x80031F24: sh          $t3, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r11;
        goto L_80031F2C;
    // 0x80031F24: sh          $t3, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r11;
L_80031F28:
    // 0x80031F28: sh          $zero, 0x78($a2)
    MEM_H(0X78, ctx->r6) = 0;
L_80031F2C:
    // 0x80031F2C: lh          $t4, 0x16($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X16);
    // 0x80031F30: nop

    // 0x80031F34: sh          $t4, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r12;
    // 0x80031F38: lh          $t5, 0x1A($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X1A);
    // 0x80031F3C: nop

    // 0x80031F40: sh          $t5, 0x76($a2)
    MEM_H(0X76, ctx->r6) = ctx->r13;
    // 0x80031F44: lh          $t6, 0x1A($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X1A);
    // 0x80031F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80031F4C: beq         $t6, $zero, L_80031F60
    if (ctx->r14 == 0) {
        // 0x80031F50: nop
    
            goto L_80031F60;
    }
    // 0x80031F50: nop

    // 0x80031F54: sh          $t7, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r15;
    // 0x80031F58: b           L_80031F64
    // 0x80031F5C: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
        goto L_80031F64;
    // 0x80031F5C: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
L_80031F60:
    // 0x80031F60: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
L_80031F64:
    // 0x80031F64: sb          $t8, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r24;
    // 0x80031F68: jal         0x80032424
    // 0x80031F6C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    light_update(rdram, ctx);
        goto after_1;
    // 0x80031F6C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80031F70: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80031F74: nop

L_80031F78:
    // 0x80031F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031F7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031F80: jr          $ra
    // 0x80031F84: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x80031F84: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}
RECOMP_FUNC void func_80087F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F14: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80087F18: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80087F1C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80087F20: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80087F24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80087F28: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80087F2C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80087F30: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80087F34: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80087F38: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80087F3C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80087F40: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80087F44: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80087F48: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80087F4C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80087F50: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80087F54: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80087F58: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80087F5C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80087F60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80087F64: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80087F68: addiu       $s4, $s4, 0x6A3C
    ctx->r20 = ADD32(ctx->r20, 0X6A3C);
    // 0x80087F6C: addiu       $s3, $s3, 0x6A38
    ctx->r19 = ADD32(ctx->r19, 0X6A38);
    // 0x80087F70: addiu       $s2, $s2, 0x6A34
    ctx->r18 = ADD32(ctx->r18, 0X6A34);
    // 0x80087F74: addiu       $s0, $s0, 0x6A30
    ctx->r16 = ADD32(ctx->r16, 0X6A30);
    // 0x80087F78: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80087F7C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80087F80:
    // 0x80087F80: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x80087F84: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x80087F88: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
    // 0x80087F8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80087F90: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80087F94: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x80087F98: jal         0x80076194
    // 0x80087F9C: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    get_free_space(rdram, ctx);
        goto after_0;
    // 0x80087F9C: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_0:
    // 0x80087FA0: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80087FA4: bne         $v0, $zero, L_80087FF0
    if (ctx->r2 != 0) {
        // 0x80087FA8: andi        $t2, $v0, 0xFF
        ctx->r10 = ctx->r2 & 0XFF;
            goto L_80087FF0;
    }
    // 0x80087FA8: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80087FAC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80087FB0: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
    // 0x80087FB4: beq         $t6, $zero, L_80087FCC
    if (ctx->r14 == 0) {
        // 0x80087FB8: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80087FCC;
    }
    // 0x80087FB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80087FBC: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80087FC0: nop

    // 0x80087FC4: bne         $t7, $zero, L_80087FE8
    if (ctx->r15 != 0) {
        // 0x80087FC8: nop
    
            goto L_80087FE8;
    }
    // 0x80087FC8: nop

L_80087FCC:
    // 0x80087FCC: sb          $s5, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r21;
    // 0x80087FD0: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80087FD4: lbu         $t8, 0x6A60($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X6A60);
    // 0x80087FD8: nop

    // 0x80087FDC: bne         $t8, $zero, L_80087FE8
    if (ctx->r24 != 0) {
        // 0x80087FE0: nop
    
            goto L_80087FE8;
    }
    // 0x80087FE0: nop

    // 0x80087FE4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80087FE8:
    // 0x80087FE8: b           L_8008803C
    // 0x80087FEC: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
        goto L_8008803C;
    // 0x80087FEC: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_80087FF0:
    // 0x80087FF0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80087FF4: bne         $t2, $at, L_80088004
    if (ctx->r10 != ctx->r1) {
        // 0x80087FF8: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_80088004;
    }
    // 0x80087FF8: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80087FFC: sb          $s5, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r21;
    // 0x80088000: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80088004:
    // 0x80088004: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80088008: bne         $t2, $at, L_80088028
    if (ctx->r10 != ctx->r1) {
        // 0x8008800C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80088028;
    }
    // 0x8008800C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80088010: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x80088014: jal         0x80075D38
    // 0x80088018: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    repair_controller_pak(rdram, ctx);
        goto after_1;
    // 0x80088018: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    after_1:
    // 0x8008801C: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80088020: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80088024: nop

L_80088028:
    // 0x80088028: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008802C: bne         $t2, $at, L_8008803C
    if (ctx->r10 != ctx->r1) {
        // 0x80088030: nop
    
            goto L_8008803C;
    }
    // 0x80088030: nop

    // 0x80088034: sb          $s5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r21;
    // 0x80088038: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_8008803C:
    // 0x8008803C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80088040: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80088044: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80088048: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8008804C: blez        $s1, L_80087F80
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80088050: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80087F80;
    }
    // 0x80088050: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80088054: beq         $fp, $zero, L_80088074
    if (ctx->r30 == 0) {
        // 0x80088058: nop
    
            goto L_80088074;
    }
    // 0x80088058: nop

    // 0x8008805C: bne         $s6, $zero, L_80088074
    if (ctx->r22 != 0) {
        // 0x80088060: nop
    
            goto L_80088074;
    }
    // 0x80088060: nop

    // 0x80088064: bne         $s7, $zero, L_80088074
    if (ctx->r23 != 0) {
        // 0x80088068: nop
    
            goto L_80088074;
    }
    // 0x80088068: nop

    // 0x8008806C: beq         $v1, $zero, L_8008807C
    if (ctx->r3 == 0) {
        // 0x80088070: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_8008807C;
    }
    // 0x80088070: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
L_80088074:
    // 0x80088074: b           L_800882FC
    // 0x80088078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800882FC;
    // 0x80088078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008807C:
    // 0x8008807C: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x80088080: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80088084: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80088088: addiu       $a2, $a2, 0x6AE0
    ctx->r6 = ADD32(ctx->r6, 0X6AE0);
    // 0x8008808C: bgez        $v0, L_800880CC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80088090: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800880CC;
    }
    // 0x80088090: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80088094: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80088098: addiu       $t6, $t6, 0x6A30
    ctx->r14 = ADD32(ctx->r14, 0X6A30);
    // 0x8008809C: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
L_800880A0:
    // 0x800880A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800880A4: blez        $s1, L_800880B4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800880A8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800880B4;
    }
    // 0x800880A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800880AC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800880B0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_800880B4:
    // 0x800880B4: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x800880B8: nop

    // 0x800880BC: beq         $t7, $zero, L_800880A0
    if (ctx->r15 == 0) {
        // 0x800880C0: nop
    
            goto L_800880A0;
    }
    // 0x800880C0: nop

    // 0x800880C4: b           L_80088158
    // 0x800880C8: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
        goto L_80088158;
    // 0x800880C8: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
L_800880CC:
    // 0x800880CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800880D0: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800880D4: lbu         $t8, 0x6A30($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X6A30);
    // 0x800880D8: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x800880DC: beq         $t8, $zero, L_800880E8
    if (ctx->r24 == 0) {
        // 0x800880E0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800880E8;
    }
    // 0x800880E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800880E4: blez        $t9, L_8008811C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800880E8: addiu       $t6, $t6, 0x6A30
        ctx->r14 = ADD32(ctx->r14, 0X6A30);
            goto L_8008811C;
    }
L_800880E8:
    // 0x800880E8: addiu       $t6, $t6, 0x6A30
    ctx->r14 = ADD32(ctx->r14, 0X6A30);
    // 0x800880EC: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
L_800880F0:
    // 0x800880F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800880F4: blez        $s1, L_80088104
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800880F8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80088104;
    }
    // 0x800880F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800880FC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80088100: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80088104:
    // 0x80088104: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80088108: nop

    // 0x8008810C: beq         $t7, $zero, L_800880F0
    if (ctx->r15 == 0) {
        // 0x80088110: nop
    
            goto L_800880F0;
    }
    // 0x80088110: nop

    // 0x80088114: b           L_80088158
    // 0x80088118: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
        goto L_80088158;
    // 0x80088118: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
L_8008811C:
    // 0x8008811C: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x80088120: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80088124: bgez        $t8, L_80088154
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80088128: addiu       $t9, $t9, 0x6A30
        ctx->r25 = ADD32(ctx->r25, 0X6A30);
            goto L_80088154;
    }
    // 0x80088128: addiu       $t9, $t9, 0x6A30
    ctx->r25 = ADD32(ctx->r25, 0X6A30);
    // 0x8008812C: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
L_80088130:
    // 0x80088130: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80088134: bgez        $s1, L_80088144
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80088138: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80088144;
    }
    // 0x80088138: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8008813C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80088140: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80088144:
    // 0x80088144: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80088148: nop

    // 0x8008814C: beq         $t6, $zero, L_80088130
    if (ctx->r14 == 0) {
        // 0x80088150: nop
    
            goto L_80088130;
    }
    // 0x80088150: nop

L_80088154:
    // 0x80088154: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
L_80088158:
    // 0x80088158: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008815C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80088160: addiu       $t9, $t9, 0x6B60
    ctx->r25 = ADD32(ctx->r25, 0X6B60);
    // 0x80088164: addiu       $t8, $t8, 0x6B70
    ctx->r24 = ADD32(ctx->r24, 0X6B70);
    // 0x80088168: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008816C: sw          $s1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r17;
    // 0x80088170: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80088174: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80088178: addiu       $a3, $a3, 0x6B20
    ctx->r7 = ADD32(ctx->r7, 0X6B20);
    // 0x8008817C: jal         0x80075E60
    // 0x80088180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    get_controller_pak_file_list(rdram, ctx);
        goto after_2;
    // 0x80088180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80088184: bne         $v0, $zero, L_800882F8
    if (ctx->r2 != 0) {
        // 0x80088188: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800882F8;
    }
    // 0x80088188: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8008818C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80088190: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80088194: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80088198: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8008819C: addiu       $ra, $ra, 0x6AE0
    ctx->r31 = ADD32(ctx->r31, 0X6AE0);
    // 0x800881A0: addiu       $a1, $a1, 0x6AA0
    ctx->r5 = ADD32(ctx->r5, 0X6AA0);
    // 0x800881A4: addiu       $t0, $t0, 0x6AE0
    ctx->r8 = ADD32(ctx->r8, 0X6AE0);
    // 0x800881A8: addiu       $t1, $t1, 0x6B70
    ctx->r9 = ADD32(ctx->r9, 0X6B70);
    // 0x800881AC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800881B0: addiu       $t5, $zero, 0x2D
    ctx->r13 = ADD32(0, 0X2D);
    // 0x800881B4: addiu       $t4, $zero, 0x2E
    ctx->r12 = ADD32(0, 0X2E);
L_800881B8:
    // 0x800881B8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800881BC: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800881C0: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x800881C4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800881C8: beq         $a3, $zero, L_8008828C
    if (ctx->r7 == 0) {
        // 0x800881CC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008828C;
    }
    // 0x800881CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800881D0: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x800881D4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800881D8: addiu       $t8, $t8, 0x6B20
    ctx->r24 = ADD32(ctx->r24, 0X6B20);
    // 0x800881DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800881E0: beq         $t9, $zero, L_80088218
    if (ctx->r25 == 0) {
        // 0x800881E4: addu        $a2, $t3, $t8
        ctx->r6 = ADD32(ctx->r11, ctx->r24);
            goto L_80088218;
    }
    // 0x800881E4: addu        $a2, $t3, $t8
    ctx->r6 = ADD32(ctx->r11, ctx->r24);
    // 0x800881E8: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
L_800881EC:
    // 0x800881EC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800881F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800881F4: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800881F8: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x800881FC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80088200: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80088204: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80088208: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x8008820C: nop

    // 0x80088210: bne         $v1, $zero, L_800881EC
    if (ctx->r3 != 0) {
        // 0x80088214: nop
    
            goto L_800881EC;
    }
    // 0x80088214: nop

L_80088218:
    // 0x80088218: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8008821C: nop

    // 0x80088220: beq         $a3, $zero, L_8008828C
    if (ctx->r7 == 0) {
        // 0x80088224: nop
    
            goto L_8008828C;
    }
    // 0x80088224: nop

    // 0x80088228: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x8008822C: nop

    // 0x80088230: beq         $t6, $zero, L_8008828C
    if (ctx->r14 == 0) {
        // 0x80088234: nop
    
            goto L_8008828C;
    }
    // 0x80088234: nop

    // 0x80088238: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8008823C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80088240: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80088244: sb          $t4, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r12;
    // 0x80088248: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8008824C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80088250: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x80088254: nop

    // 0x80088258: beq         $t9, $zero, L_8008828C
    if (ctx->r25 == 0) {
        // 0x8008825C: andi        $v1, $t9, 0xFF
        ctx->r3 = ctx->r25 & 0XFF;
            goto L_8008828C;
    }
    // 0x8008825C: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
L_80088260:
    // 0x80088260: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80088264: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80088268: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8008826C: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x80088270: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80088274: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80088278: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008827C: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x80088280: nop

    // 0x80088284: bne         $v1, $zero, L_80088260
    if (ctx->r3 != 0) {
        // 0x80088288: nop
    
            goto L_80088260;
    }
    // 0x80088288: nop

L_8008828C:
    // 0x8008828C: bne         $a0, $zero, L_800882A8
    if (ctx->r4 != 0) {
        // 0x80088290: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_800882A8;
    }
    // 0x80088290: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80088294: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80088298: nop

    // 0x8008829C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800882A0: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x800882A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800882A8:
    // 0x800882A8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800882AC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800882B0: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x800882B4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800882B8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800882BC: bne         $a1, $ra, L_800881B8
    if (ctx->r5 != ctx->r31) {
        // 0x800882C0: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_800881B8;
    }
    // 0x800882C0: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x800882C4: jal         0x80076164
    // 0x800882C8: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    cpak_free_files(rdram, ctx);
        goto after_3;
    // 0x800882C8: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    after_3:
    // 0x800882CC: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800882D0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800882D4: addiu       $s0, $s0, 0x6BB0
    ctx->r16 = ADD32(ctx->r16, 0X6BB0);
    // 0x800882D8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800882DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800882E0: jal         0x80076194
    // 0x800882E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_free_space(rdram, ctx);
        goto after_4;
    // 0x800882E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x800882E8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800882EC: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x800882F0: srl         $t8, $t7, 8
    ctx->r24 = S32(U32(ctx->r15) >> 8);
    // 0x800882F4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800882F8:
    // 0x800882F8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800882FC:
    // 0x800882FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80088300: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80088304: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80088308: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008830C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80088310: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80088314: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80088318: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008831C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80088320: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80088324: jr          $ra
    // 0x80088328: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80088328: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void _loadOutputBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064224: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80064228: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006422C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80064230: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80064234: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80064238: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8006423C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80064240: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x80064244: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80064248: beq         $t6, $zero, L_80064454
    if (ctx->r14 == 0) {
        // 0x8006424C: or          $s2, $a3, $zero
        ctx->r18 = ctx->r7 | 0;
            goto L_80064454;
    }
    // 0x8006424C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80064250: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80064254: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80064258: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8006425C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80064260: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80064264: jal         0x80064884
    // 0x80064268: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _doModFunc(rdram, ctx);
        goto after_0;
    // 0x80064268: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8006426C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80064270: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80064274: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80064278: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8006427C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80064280: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80064284: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80064288: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8006428C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80064290: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80064294: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x80064298: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8006429C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800642A0: nop

    // 0x800642A4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800642A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800642AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800642B0: nop

    // 0x800642B4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800642B8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800642BC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800642C0: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800642C4: nop

    // 0x800642C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800642CC: nop

    // 0x800642D0: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800642D4: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x800642D8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800642DC: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x800642E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800642E4: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x800642E8: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x800642EC: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800642F0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800642F4: nop

    // 0x800642F8: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800642FC: nop

    // 0x80064300: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80064304: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80064308: nop

    // 0x8006430C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80064310: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80064314: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80064318: nop

    // 0x8006431C: cvt.w.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80064320: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80064324: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80064328: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8006432C: nop

    // 0x80064330: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80064334: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80064338: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8006433C: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x80064340: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80064344: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x80064348: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8006434C: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80064350: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80064354: addu        $s1, $t3, $t2
    ctx->r17 = ADD32(ctx->r11, ctx->r10);
    // 0x80064358: andi        $v1, $s1, 0x7
    ctx->r3 = ctx->r17 & 0X7;
    // 0x8006435C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80064360: sra         $t4, $v1, 1
    ctx->r12 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80064364: sll         $t1, $t4, 1
    ctx->r9 = S32(ctx->r12 << 1);
    // 0x80064368: subu        $a1, $s1, $t1
    ctx->r5 = SUB32(ctx->r17, ctx->r9);
    // 0x8006436C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80064370: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80064374: addu        $a3, $t0, $t4
    ctx->r7 = ADD32(ctx->r8, ctx->r12);
    // 0x80064378: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8006437C: jal         0x800644A0
    // 0x80064380: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _loadBuffer(rdram, ctx);
        goto after_1;
    // 0x80064380: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
    // 0x80064384: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80064388: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8006438C: addiu       $t6, $t1, 0x280
    ctx->r14 = ADD32(ctx->r9, 0X280);
    // 0x80064390: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80064394: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80064398: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006439C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800643A0: sll         $t4, $s2, 1
    ctx->r12 = S32(ctx->r18 << 1);
    // 0x800643A4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800643A8: sll         $t2, $t3, 16
    ctx->r10 = S32(ctx->r11 << 16);
    // 0x800643AC: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x800643B0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800643B4: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800643B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800643BC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800643C0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800643C4: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800643C8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800643CC: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x800643D0: addiu       $s1, $v0, 0x10
    ctx->r17 = ADD32(ctx->r2, 0X10);
    // 0x800643D4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800643D8: lw          $t2, 0x24($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X24);
    // 0x800643DC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800643E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800643E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800643E8: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x800643EC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800643F0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800643F4: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800643F8: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800643FC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80064400: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80064404: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x80064408: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x8006440C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80064410: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80064414: nop

    // 0x80064418: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x8006441C: jal         0x800C8CF0
    // 0x80064420: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80064420: nop

    after_2:
    // 0x80064424: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80064428: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8006442C: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80064430: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80064434: nop

    // 0x80064438: sw          $zero, 0x24($t2)
    MEM_W(0X24, ctx->r10) = 0;
    // 0x8006443C: lw          $t5, 0x18($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X18);
    // 0x80064440: nop

    // 0x80064444: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x80064448: subu        $t7, $t6, $s2
    ctx->r15 = SUB32(ctx->r14, ctx->r18);
    // 0x8006444C: b           L_80064484
    // 0x80064450: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
        goto L_80064484;
    // 0x80064450: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
L_80064454:
    // 0x80064454: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80064458: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8006445C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80064460: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x80064464: negu        $t4, $t9
    ctx->r12 = SUB32(0, ctx->r25);
    // 0x80064468: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8006446C: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80064470: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80064474: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80064478: jal         0x800644A0
    // 0x8006447C: addu        $a1, $t8, $t2
    ctx->r5 = ADD32(ctx->r24, ctx->r10);
    _loadBuffer(rdram, ctx);
        goto after_3;
    // 0x8006447C: addu        $a1, $t8, $t2
    ctx->r5 = ADD32(ctx->r24, ctx->r10);
    after_3:
    // 0x80064480: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80064484:
    // 0x80064484: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80064488: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8006448C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80064490: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80064494: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80064498: jr          $ra
    // 0x8006449C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8006449C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void obj_init_animation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037A18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80037A1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80037A20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80037A24: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80037A28: lbu         $t7, 0xB($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XB);
    // 0x80037A2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80037A30: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80037A34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80037A38: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80037A3C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80037A40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037A44: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80037A48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037A4C: bc1f        L_80037A58
    if (!c1cs) {
        // 0x80037A50: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80037A58;
    }
    // 0x80037A50: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80037A54: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80037A58:
    // 0x80037A58: nop

    // 0x80037A5C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80037A60: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x80037A64: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80037A68: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80037A6C: nop

    // 0x80037A70: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80037A74: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80037A78: lbu         $t9, 0xA($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XA);
    // 0x80037A7C: nop

    // 0x80037A80: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80037A84: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x80037A88: lbu         $t1, 0x9($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X9);
    // 0x80037A8C: nop

    // 0x80037A90: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80037A94: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x80037A98: lbu         $t3, 0x8($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X8);
    // 0x80037A9C: nop

    // 0x80037AA0: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80037AA4: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x80037AA8: lb          $a0, 0x10($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X10);
    // 0x80037AAC: nop

    // 0x80037AB0: bne         $a0, $at, L_80037ACC
    if (ctx->r4 != ctx->r1) {
        // 0x80037AB4: nop
    
            goto L_80037ACC;
    }
    // 0x80037AB4: nop

    // 0x80037AB8: jal         0x8001F3B8
    // 0x80037ABC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F3B8(rdram, ctx);
        goto after_0;
    // 0x80037ABC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80037AC0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037AC4: b           L_80037AF8
    // 0x80037AC8: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
        goto L_80037AF8;
    // 0x80037AC8: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
L_80037ACC:
    // 0x80037ACC: bgez        $a0, L_80037AE8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80037AD0: slti        $at, $a0, -0x2
        ctx->r1 = SIGNED(ctx->r4) < -0X2 ? 1 : 0;
            goto L_80037AE8;
    }
    // 0x80037AD0: slti        $at, $a0, -0x2
    ctx->r1 = SIGNED(ctx->r4) < -0X2 ? 1 : 0;
    // 0x80037AD4: bne         $at, $zero, L_80037AE8
    if (ctx->r1 != 0) {
        // 0x80037AD8: nop
    
            goto L_80037AE8;
    }
    // 0x80037AD8: nop

    // 0x80037ADC: sb          $zero, 0x10($a3)
    MEM_B(0X10, ctx->r7) = 0;
    // 0x80037AE0: lb          $a0, 0x10($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X10);
    // 0x80037AE4: nop

L_80037AE8:
    // 0x80037AE8: jal         0x8001F3C8
    // 0x80037AEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F3C8(rdram, ctx);
        goto after_1;
    // 0x80037AEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80037AF0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037AF4: nop

L_80037AF8:
    // 0x80037AF8: lb          $v1, 0x21($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X21);
    // 0x80037AFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037B00: bne         $v1, $at, L_80037B28
    if (ctx->r3 != ctx->r1) {
        // 0x80037B04: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80037B28;
    }
    // 0x80037B04: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80037B08: jal         0x8001E440
    // 0x80037B0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    cutscene_id(rdram, ctx);
        goto after_2;
    // 0x80037B0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80037B10: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B14: nop

    // 0x80037B18: sb          $v0, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r2;
    // 0x80037B1C: lb          $v1, 0x21($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X21);
    // 0x80037B20: nop

    // 0x80037B24: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
L_80037B28:
    // 0x80037B28: bne         $v1, $at, L_80037B40
    if (ctx->r3 != ctx->r1) {
        // 0x80037B2C: nop
    
            goto L_80037B40;
    }
    // 0x80037B2C: nop

    // 0x80037B30: lb          $t5, 0x10($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X10);
    // 0x80037B34: nop

    // 0x80037B38: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80037B3C: sb          $t6, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r14;
L_80037B40:
    // 0x80037B40: lb          $a0, 0x10($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X10);
    // 0x80037B44: jal         0x8001F3EC
    // 0x80037B48: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F3EC(rdram, ctx);
        goto after_3;
    // 0x80037B48: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_3:
    // 0x80037B4C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B50: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80037B54: lb          $v1, 0x11($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X11);
    // 0x80037B58: nop

    // 0x80037B5C: bne         $v1, $at, L_80037B80
    if (ctx->r3 != ctx->r1) {
        // 0x80037B60: nop
    
            goto L_80037B80;
    }
    // 0x80037B60: nop

    // 0x80037B64: sb          $v0, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r2;
    // 0x80037B68: lb          $t7, 0x11($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X11);
    // 0x80037B6C: nop

    // 0x80037B70: bgez        $t7, L_80037BA8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80037B74: nop
    
            goto L_80037BA8;
    }
    // 0x80037B74: nop

    // 0x80037B78: b           L_80037BA8
    // 0x80037B7C: sb          $zero, 0x11($a3)
    MEM_B(0X11, ctx->r7) = 0;
        goto L_80037BA8;
    // 0x80037B7C: sb          $zero, 0x11($a3)
    MEM_B(0X11, ctx->r7) = 0;
L_80037B80:
    // 0x80037B80: bltz        $v0, L_80037B9C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80037B84: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80037B9C;
    }
    // 0x80037B84: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80037B88: bne         $at, $zero, L_80037B9C
    if (ctx->r1 != 0) {
        // 0x80037B8C: nop
    
            goto L_80037B9C;
    }
    // 0x80037B8C: nop

    // 0x80037B90: sb          $v0, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r2;
    // 0x80037B94: lb          $v1, 0x11($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X11);
    // 0x80037B98: nop

L_80037B9C:
    // 0x80037B9C: bgez        $v1, L_80037BA8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80037BA0: nop
    
            goto L_80037BA8;
    }
    // 0x80037BA0: nop

    // 0x80037BA4: sb          $zero, 0x11($a3)
    MEM_B(0X11, ctx->r7) = 0;
L_80037BA8:
    // 0x80037BA8: jal         0x80011390
    // 0x80037BAC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    path_enable(rdram, ctx);
        goto after_4;
    // 0x80037BAC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80037BB0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037BB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80037BB8: lb          $t8, 0x10($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X10);
    // 0x80037BBC: nop

    // 0x80037BC0: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x80037BC4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80037BC8: nop

    // 0x80037BCC: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
    // 0x80037BD0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80037BD4: nop

    // 0x80037BD8: beq         $t0, $zero, L_80037BFC
    if (ctx->r8 == 0) {
        // 0x80037BDC: nop
    
            goto L_80037BFC;
    }
    // 0x80037BDC: nop

    // 0x80037BE0: jal         0x8006A554
    // 0x80037BE4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    input_pressed(rdram, ctx);
        goto after_5;
    // 0x80037BE4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_5:
    // 0x80037BE8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037BEC: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80037BF0: beq         $t1, $zero, L_80037BFC
    if (ctx->r9 == 0) {
        // 0x80037BF4: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80037BFC;
    }
    // 0x80037BF4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80037BF8: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
L_80037BFC:
    // 0x80037BFC: jal         0x8001E440
    // 0x80037C00: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    cutscene_id(rdram, ctx);
        goto after_6;
    // 0x80037C00: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80037C04: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037C08: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80037C0C: lb          $v1, 0x21($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X21);
    // 0x80037C10: nop

    // 0x80037C14: beq         $v0, $v1, L_80037C24
    if (ctx->r2 == ctx->r3) {
        // 0x80037C18: nop
    
            goto L_80037C24;
    }
    // 0x80037C18: nop

    // 0x80037C1C: bne         $v1, $at, L_80037C68
    if (ctx->r3 != ctx->r1) {
        // 0x80037C20: nop
    
            goto L_80037C68;
    }
    // 0x80037C20: nop

L_80037C24:
    // 0x80037C24: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80037C28: nop

    // 0x80037C2C: bne         $t3, $zero, L_80037C68
    if (ctx->r11 != 0) {
        // 0x80037C30: nop
    
            goto L_80037C68;
    }
    // 0x80037C30: nop

    // 0x80037C34: lb          $t4, 0x11($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X11);
    // 0x80037C38: nop

    // 0x80037C3C: bne         $t4, $zero, L_80037C68
    if (ctx->r12 != 0) {
        // 0x80037C40: nop
    
            goto L_80037C68;
    }
    // 0x80037C40: nop

    // 0x80037C44: lh          $t5, 0xC($a3)
    ctx->r13 = MEM_H(ctx->r7, 0XC);
    // 0x80037C48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037C4C: beq         $t5, $at, L_80037C68
    if (ctx->r13 == ctx->r1) {
        // 0x80037C50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80037C68;
    }
    // 0x80037C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037C54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80037C58: jal         0x8001F23C
    // 0x80037C5C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F23C(rdram, ctx);
        goto after_7;
    // 0x80037C5C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_7:
    // 0x80037C60: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037C64: nop

L_80037C68:
    // 0x80037C68: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80037C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037C70: beq         $v0, $zero, L_80037CBC
    if (ctx->r2 == 0) {
        // 0x80037C74: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80037CBC;
    }
    // 0x80037C74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80037C78: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80037C7C: jal         0x8001EFA4
    // 0x80037C80: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    obj_init_animobject(rdram, ctx);
        goto after_8;
    // 0x80037C80: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_8:
    // 0x80037C84: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037C88: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80037C8C: lb          $t6, 0x11($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X11);
    // 0x80037C90: nop

    // 0x80037C94: bne         $t6, $zero, L_80037CB0
    if (ctx->r14 != 0) {
        // 0x80037C98: nop
    
            goto L_80037CB0;
    }
    // 0x80037C98: nop

    // 0x80037C9C: lh          $t7, 0xC($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XC);
    // 0x80037CA0: lh          $t8, 0x4A($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4A);
    // 0x80037CA4: nop

    // 0x80037CA8: beq         $t7, $t8, L_80037CBC
    if (ctx->r15 == ctx->r24) {
        // 0x80037CAC: nop
    
            goto L_80037CBC;
    }
    // 0x80037CAC: nop

L_80037CB0:
    // 0x80037CB0: jal         0x8000FFB8
    // 0x80037CB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    free_object(rdram, ctx);
        goto after_9;
    // 0x80037CB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_9:
    // 0x80037CB8: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
L_80037CBC:
    // 0x80037CBC: lw          $a0, 0x7C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7C);
    // 0x80037CC0: jal         0x80021600
    // 0x80037CC4: nop

    func_80021600(rdram, ctx);
        goto after_10;
    // 0x80037CC4: nop

    after_10:
    // 0x80037CC8: beq         $v0, $zero, L_80037CDC
    if (ctx->r2 == 0) {
        // 0x80037CCC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80037CDC;
    }
    // 0x80037CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80037CD0: jal         0x8001EE74
    // 0x80037CD4: nop

    func_8001EE74(rdram, ctx);
        goto after_11;
    // 0x80037CD4: nop

    after_11:
    // 0x80037CD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037CDC:
    // 0x80037CDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037CE0: jr          $ra
    // 0x80037CE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80037CE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void menu_number_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081C04: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80081C08: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80081C0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80081C10: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80081C14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80081C18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80081C1C: lui         $s0, 0x3B9A
    ctx->r16 = S32(0X3B9A << 16);
    // 0x80081C20: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80081C24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80081C28: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80081C2C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80081C30: ori         $s0, $s0, 0xCA00
    ctx->r16 = ctx->r16 | 0XCA00;
    // 0x80081C34: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80081C38: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80081C3C: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x80081C40: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
L_80081C44:
    // 0x80081C44: bne         $at, $zero, L_80081CA0
    if (ctx->r1 != 0) {
        // 0x80081C48: nop
    
            goto L_80081CA0;
    }
    // 0x80081C48: nop

    // 0x80081C4C: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x80081C50: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80081C54: bne         $s0, $zero, L_80081C60
    if (ctx->r16 != 0) {
        // 0x80081C58: nop
    
            goto L_80081C60;
    }
    // 0x80081C58: nop

    // 0x80081C5C: break       7
    do_break(2148015196);
L_80081C60:
    // 0x80081C60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081C64: bne         $s0, $at, L_80081C78
    if (ctx->r16 != ctx->r1) {
        // 0x80081C68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081C78;
    }
    // 0x80081C68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081C6C: bne         $s1, $at, L_80081C78
    if (ctx->r17 != ctx->r1) {
        // 0x80081C70: nop
    
            goto L_80081C78;
    }
    // 0x80081C70: nop

    // 0x80081C74: break       6
    do_break(2148015220);
L_80081C78:
    // 0x80081C78: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80081C7C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80081C80: mflo        $v0
    ctx->r2 = lo;
    // 0x80081C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80081C88: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // 0x80081C8C: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80081C90: mflo        $t6
    ctx->r14 = lo;
    // 0x80081C94: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x80081C98: b           L_80081CB4
    // 0x80081C9C: nop

        goto L_80081CB4;
    // 0x80081C9C: nop

L_80081CA0:
    // 0x80081CA0: beq         $t0, $zero, L_80081CB4
    if (ctx->r8 == 0) {
        // 0x80081CA4: nop
    
            goto L_80081CB4;
    }
    // 0x80081CA4: nop

    // 0x80081CA8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80081CAC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80081CB0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80081CB4:
    // 0x80081CB4: div         $zero, $s0, $a1
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r5)));
    // 0x80081CB8: bne         $a1, $zero, L_80081CC4
    if (ctx->r5 != 0) {
        // 0x80081CBC: nop
    
            goto L_80081CC4;
    }
    // 0x80081CBC: nop

    // 0x80081CC0: break       7
    do_break(2148015296);
L_80081CC4:
    // 0x80081CC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081CC8: bne         $a1, $at, L_80081CDC
    if (ctx->r5 != ctx->r1) {
        // 0x80081CCC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081CDC;
    }
    // 0x80081CCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081CD0: bne         $s0, $at, L_80081CDC
    if (ctx->r16 != ctx->r1) {
        // 0x80081CD4: nop
    
            goto L_80081CDC;
    }
    // 0x80081CD4: nop

    // 0x80081CD8: break       6
    do_break(2148015320);
L_80081CDC:
    // 0x80081CDC: mflo        $s0
    ctx->r16 = lo;
    // 0x80081CE0: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80081CE4: beq         $at, $zero, L_80081C44
    if (ctx->r1 == 0) {
        // 0x80081CE8: slt         $at, $s1, $s0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_80081C44;
    }
    // 0x80081CE8: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80081CEC: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x80081CF0: sb          $s1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r17;
    // 0x80081CF4: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80081CF8: beq         $t7, $zero, L_80081D18
    if (ctx->r15 == 0) {
        // 0x80081CFC: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80081D18;
    }
    // 0x80081CFC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80081D00: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80081D04: subu        $t8, $t8, $s3
    ctx->r24 = SUB32(ctx->r24, ctx->r19);
    // 0x80081D08: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80081D0C: subu        $s4, $s4, $t8
    ctx->r20 = SUB32(ctx->r20, ctx->r24);
    // 0x80081D10: b           L_80081D40
    // 0x80081D14: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
        goto L_80081D40;
    // 0x80081D14: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
L_80081D18:
    // 0x80081D18: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80081D1C: beq         $t9, $zero, L_80081D3C
    if (ctx->r25 == 0) {
        // 0x80081D20: sll         $t1, $s3, 2
        ctx->r9 = S32(ctx->r19 << 2);
            goto L_80081D3C;
    }
    // 0x80081D20: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80081D24: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x80081D28: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80081D2C: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x80081D30: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80081D34: b           L_80081D40
    // 0x80081D38: subu        $s4, $s4, $t2
    ctx->r20 = SUB32(ctx->r20, ctx->r10);
        goto L_80081D40;
    // 0x80081D38: subu        $s4, $s4, $t2
    ctx->r20 = SUB32(ctx->r20, ctx->r10);
L_80081D3C:
    // 0x80081D3C: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
L_80081D40:
    // 0x80081D40: andi        $t3, $v0, 0x8
    ctx->r11 = ctx->r2 & 0X8;
    // 0x80081D44: beq         $t3, $zero, L_80081D54
    if (ctx->r11 == 0) {
        // 0x80081D48: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80081D54;
    }
    // 0x80081D48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081D4C: b           L_80081D64
    // 0x80081D50: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
        goto L_80081D64;
    // 0x80081D50: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
L_80081D54:
    // 0x80081D54: andi        $t4, $v0, 0x10
    ctx->r12 = ctx->r2 & 0X10;
    // 0x80081D58: beq         $t4, $zero, L_80081D68
    if (ctx->r12 == 0) {
        // 0x80081D5C: lw          $t5, 0x70($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X70);
            goto L_80081D68;
    }
    // 0x80081D5C: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80081D60: addiu       $a2, $a2, -0x7
    ctx->r6 = ADD32(ctx->r6, -0X7);
L_80081D64:
    // 0x80081D64: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
L_80081D68:
    // 0x80081D68: sb          $a3, -0xB5C($at)
    MEM_B(-0XB5C, ctx->r1) = ctx->r7;
    // 0x80081D6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081D70: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80081D74: sb          $t5, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r13;
    // 0x80081D78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081D7C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80081D80: sb          $t6, -0xB54($at)
    MEM_B(-0XB54, ctx->r1) = ctx->r14;
    // 0x80081D84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081D88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80081D8C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80081D90: jal         0x8007BF1C
    // 0x80081D94: sw          $t7, -0x89C($at)
    MEM_W(-0X89C, ctx->r1) = ctx->r15;
    sprite_opaque(rdram, ctx);
        goto after_0;
    // 0x80081D94: sw          $t7, -0x89C($at)
    MEM_W(-0X89C, ctx->r1) = ctx->r15;
    after_0:
    // 0x80081D98: jal         0x80068508
    // 0x80081D9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x80081D9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80081DA0: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80081DA4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80081DA8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80081DAC: addiu       $s2, $s2, -0x8A4
    ctx->r18 = ADD32(ctx->r18, -0X8A4);
    // 0x80081DB0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081DB4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80081DB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80081DBC: blez        $s3, L_80081DFC
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80081DC0: swc1        $f6, 0x10($t8)
        MEM_W(0X10, ctx->r24) = ctx->f6.u32l;
            goto L_80081DFC;
    }
    // 0x80081DC0: swc1        $f6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f6.u32l;
    // 0x80081DC4: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
L_80081DC8:
    // 0x80081DC8: mtc1        $s4, $f8
    ctx->f8.u32l = ctx->r20;
    // 0x80081DCC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80081DD0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081DD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80081DD8: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
    // 0x80081DDC: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80081DE0: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x80081DE4: jal         0x8009CA60
    // 0x80081DE8: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    menu_element_render(rdram, ctx);
        goto after_2;
    // 0x80081DE8: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    after_2:
    // 0x80081DEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80081DF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80081DF4: bne         $s0, $s3, L_80081DC8
    if (ctx->r16 != ctx->r19) {
        // 0x80081DF8: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80081DC8;
    }
    // 0x80081DF8: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
L_80081DFC:
    // 0x80081DFC: jal         0x8007BF1C
    // 0x80081E00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_3;
    // 0x80081E00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80081E04: jal         0x80068508
    // 0x80081E08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_4;
    // 0x80081E08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80081E0C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80081E10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081E14: sb          $v0, -0xB5C($at)
    MEM_B(-0XB5C, ctx->r1) = ctx->r2;
    // 0x80081E18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081E1C: sb          $v0, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r2;
    // 0x80081E20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081E24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80081E28: sb          $v0, -0xB54($at)
    MEM_B(-0XB54, ctx->r1) = ctx->r2;
    // 0x80081E2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081E30: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80081E34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80081E38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80081E3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80081E40: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80081E44: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80081E48: sw          $t3, -0x89C($at)
    MEM_W(-0X89C, ctx->r1) = ctx->r11;
    // 0x80081E4C: jr          $ra
    // 0x80081E50: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80081E50: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void obj_loop_timetrialghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035E34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80035E38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80035E3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80035E40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80035E44: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80035E48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80035E4C: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80035E50: jal         0x8001139C
    // 0x80035E54: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x80035E54: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    after_0:
    // 0x80035E58: bne         $v0, $zero, L_80035E74
    if (ctx->r2 != 0) {
        // 0x80035E5C: nop
    
            goto L_80035E74;
    }
    // 0x80035E5C: nop

    // 0x80035E60: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80035E64: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80035E68: nop

    // 0x80035E6C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80035E70: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
L_80035E74:
    // 0x80035E74: jal         0x80059E40
    // 0x80035E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    timetrial_ghost_read(rdram, ctx);
        goto after_1;
    // 0x80035E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80035E7C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80035E80: jal         0x800AFC3C
    // 0x80035E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_2;
    // 0x80035E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80035E88: jal         0x8001BAC8
    // 0x80035E8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_3;
    // 0x80035E8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80035E90: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x80035E94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80035E98: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80035E9C: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x80035EA0: bne         $a1, $t0, L_80035EEC
    if (ctx->r5 != ctx->r8) {
        // 0x80035EA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035EEC;
    }
    // 0x80035EA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80035EA8: lb          $v0, 0x1D6($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1D6);
    // 0x80035EAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80035EB0: beq         $v0, $a1, L_80035EC0
    if (ctx->r2 == ctx->r5) {
        // 0x80035EB4: nop
    
            goto L_80035EC0;
    }
    // 0x80035EB4: nop

    // 0x80035EB8: bne         $v0, $at, L_80035EEC
    if (ctx->r2 != ctx->r1) {
        // 0x80035EBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035EEC;
    }
    // 0x80035EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80035EC0:
    // 0x80035EC0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80035EC4: addiu       $t1, $zero, 0x4000
    ctx->r9 = ADD32(0, 0X4000);
    // 0x80035EC8: lb          $t2, 0x3A($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X3A);
    // 0x80035ECC: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x80035ED0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80035ED4: sb          $t3, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r11;
    // 0x80035ED8: lb          $t4, 0x3A($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X3A);
    // 0x80035EDC: nop

    // 0x80035EE0: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80035EE4: sb          $t5, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r13;
    // 0x80035EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80035EEC:
    // 0x80035EEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80035EF0: jr          $ra
    // 0x80035EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80035EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bgdraw_texture_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078170: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80078174: sw          $a0, -0x1B3C($at)
    MEM_W(-0X1B3C, ctx->r1) = ctx->r4;
    // 0x80078178: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007817C: sw          $a1, -0x1B38($at)
    MEM_W(-0X1B38, ctx->r1) = ctx->r5;
    // 0x80078180: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80078184: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80078188: jr          $ra
    // 0x8007818C: sw          $t6, -0x1B40($at)
    MEM_W(-0X1B40, ctx->r1) = ctx->r14;
    return;
    // 0x8007818C: sw          $t6, -0x1B40($at)
    MEM_W(-0X1B40, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void decrease_rocket_sound_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F0DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003F0E0: addiu       $v0, $v0, -0x2B24
    ctx->r2 = ADD32(ctx->r2, -0X2B24);
    // 0x8003F0E4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8003F0E8: nop

    // 0x8003F0EC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8003F0F0: jr          $ra
    // 0x8003F0F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8003F0F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void savemenu_write(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80086B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086B04: jal         0x8006EA90
    // 0x80086B08: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80086B08: nop

    after_0:
    // 0x80086B0C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086B10: lw          $t7, 0x6BD4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BD4);
    // 0x80086B14: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086B18: lw          $t6, 0x6A0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A0C);
    // 0x80086B1C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80086B20: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x80086B24: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x80086B28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80086B2C: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80086B30: sltiu       $at, $t2, 0xA
    ctx->r1 = ctx->r10 < 0XA ? 1 : 0;
    // 0x80086B34: beq         $at, $zero, L_800871C4
    if (ctx->r1 == 0) {
        // 0x80086B38: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_800871C4;
    }
    // 0x80086B38: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80086B3C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80086B40: addu        $at, $at, $t2
    gpr jr_addend_80086B4C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80086B44: lw          $t2, -0x7BE8($at)
    ctx->r10 = ADD32(ctx->r1, -0X7BE8);
    // 0x80086B48: nop

    // 0x80086B4C: jr          $t2
    // 0x80086B50: nop

    switch (jr_addend_80086B4C >> 2) {
        case 0: goto L_80086B54; break;
        case 1: goto L_80086CDC; break;
        case 2: goto L_80086D54; break;
        case 3: goto L_80086F74; break;
        case 4: goto L_80087084; break;
        case 5: goto L_80087110; break;
        case 6: goto L_800871C4; break;
        case 7: goto L_800871C4; break;
        case 8: goto L_800871C4; break;
        case 9: goto L_80087158; break;
        default: switch_error(__func__, 0x80086B4C, 0x800E8418);
    }
    // 0x80086B50: nop

L_80086B54:
    // 0x80086B54: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086B58: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80086B5C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086B60: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80086B64: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80086B68: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80086B6C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80086B70: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x80086B74: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80086B78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80086B7C: beq         $v0, $at, L_80086B9C
    if (ctx->r2 == ctx->r1) {
        // 0x80086B80: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80086B9C;
    }
    // 0x80086B80: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086B84: beq         $v0, $at, L_80086C94
    if (ctx->r2 == ctx->r1) {
        // 0x80086B88: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80086C94;
    }
    // 0x80086B88: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80086B8C: beq         $v0, $at, L_80086C80
    if (ctx->r2 == ctx->r1) {
        // 0x80086B90: nop
    
            goto L_80086C80;
    }
    // 0x80086B90: nop

    // 0x80086B94: b           L_800871CC
    // 0x80086B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800871CC;
    // 0x80086B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80086B9C:
    // 0x80086B9C: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    // 0x80086BA0: jal         0x8006EC18
    // 0x80086BA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    force_mark_write_save_file(rdram, ctx);
        goto after_1;
    // 0x80086BA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x80086BA8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086BAC: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80086BB0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086BB4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80086BB8: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80086BBC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80086BC0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80086BC4: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x80086BC8: lbu         $t4, 0x6($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X6);
    // 0x80086BCC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80086BD0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80086BD4: addiu       $v1, $v1, 0x6530
    ctx->r3 = ADD32(ctx->r3, 0X6530);
    // 0x80086BD8: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80086BDC: addu        $t5, $v1, $t3
    ctx->r13 = ADD32(ctx->r3, ctx->r11);
    // 0x80086BE0: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80086BE4: lw          $t7, 0x10($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X10);
    // 0x80086BE8: nop

    // 0x80086BEC: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80086BF0: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80086BF4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80086BF8: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x80086BFC: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x80086C00: lbu         $t3, 0x6($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X6);
    // 0x80086C04: nop

    // 0x80086C08: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80086C0C: addu        $t7, $v1, $t5
    ctx->r15 = ADD32(ctx->r3, ctx->r13);
    // 0x80086C10: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80086C14: nop

    // 0x80086C18: sb          $zero, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = 0;
    // 0x80086C1C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80086C20: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80086C24: sll         $t3, $t4, 4
    ctx->r11 = S32(ctx->r12 << 4);
    // 0x80086C28: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80086C2C: lbu         $t7, 0x6($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X6);
    // 0x80086C30: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80086C34: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80086C38: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x80086C3C: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80086C40: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80086C44: nop

    // 0x80086C48: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x80086C4C: nop

    // 0x80086C50: sh          $t6, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r14;
    // 0x80086C54: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80086C58: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80086C5C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80086C60: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80086C64: lbu         $t4, 0x6($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X6);
    // 0x80086C68: lw          $t3, 0x50($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X50);
    // 0x80086C6C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80086C70: addu        $t2, $v1, $t6
    ctx->r10 = ADD32(ctx->r3, ctx->r14);
    // 0x80086C74: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x80086C78: b           L_800871C8
    // 0x80086C7C: sw          $t3, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r11;
        goto L_800871C8;
    // 0x80086C7C: sw          $t3, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r11;
L_80086C80:
    // 0x80086C80: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    // 0x80086C84: jal         0x80073F5C
    // 0x80086C88: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    write_game_data_to_controller_pak(rdram, ctx);
        goto after_2;
    // 0x80086C88: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x80086C8C: b           L_800871C8
    // 0x80086C90: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_800871C8;
    // 0x80086C90: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80086C94:
    // 0x80086C94: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80086C98: jal         0x8006ECAC
    // 0x80086C9C: nop

    mark_save_file_to_erase(rdram, ctx);
        goto after_3;
    // 0x80086C9C: nop

    after_3:
    // 0x80086CA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80086CA4: lw          $t9, 0x6BD4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6BD4);
    // 0x80086CA8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80086CAC: lw          $t8, 0x6A0C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A0C);
    // 0x80086CB0: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x80086CB4: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x80086CB8: lbu         $t2, 0x6($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X6);
    // 0x80086CBC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80086CC0: addiu       $v1, $v1, 0x6530
    ctx->r3 = ADD32(ctx->r3, 0X6530);
    // 0x80086CC4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80086CC8: addu        $t7, $v1, $t3
    ctx->r15 = ADD32(ctx->r3, ctx->r11);
    // 0x80086CCC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80086CD0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80086CD4: b           L_800871C8
    // 0x80086CD8: sb          $t5, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r13;
        goto L_800871C8;
    // 0x80086CD8: sb          $t5, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r13;
L_80086CDC:
    // 0x80086CDC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086CE0: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80086CE4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086CE8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80086CEC: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80086CF0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80086CF4: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80086CF8: addu        $v1, $t8, $t6
    ctx->r3 = ADD32(ctx->r24, ctx->r14);
    // 0x80086CFC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80086D00: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086D04: beq         $v0, $at, L_80086D2C
    if (ctx->r2 == ctx->r1) {
        // 0x80086D08: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80086D2C;
    }
    // 0x80086D08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80086D0C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80086D10: bne         $v0, $at, L_800871CC
    if (ctx->r2 != ctx->r1) {
        // 0x80086D14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800871CC;
    }
    // 0x80086D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086D18: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    // 0x80086D1C: jal         0x80074148
    // 0x80086D20: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    write_time_data_to_controller_pak(rdram, ctx);
        goto after_4;
    // 0x80086D20: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x80086D24: b           L_800871C8
    // 0x80086D28: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_800871C8;
    // 0x80086D28: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80086D2C:
    // 0x80086D2C: jal         0x8006E770
    // 0x80086D30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    clear_lap_records(rdram, ctx);
        goto after_5;
    // 0x80086D30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80086D34: jal         0x8006EBFC
    // 0x80086D38: nop

    mark_to_write_flap_and_course_times(rdram, ctx);
        goto after_6;
    // 0x80086D38: nop

    after_6:
    // 0x80086D3C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80086D40: ori         $a1, $a1, 0xFFF0
    ctx->r5 = ctx->r5 | 0XFFF0;
    // 0x80086D44: jal         0x8009EABC
    // 0x80086D48: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    unset_eeprom_settings_value(rdram, ctx);
        goto after_7;
    // 0x80086D48: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_7:
    // 0x80086D4C: b           L_800871CC
    // 0x80086D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800871CC;
    // 0x80086D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80086D54:
    // 0x80086D54: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086D58: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80086D5C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086D60: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80086D64: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80086D68: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80086D6C: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x80086D70: addu        $t5, $t2, $t7
    ctx->r13 = ADD32(ctx->r10, ctx->r15);
    // 0x80086D74: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x80086D78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80086D7C: beq         $v0, $at, L_80086D9C
    if (ctx->r2 == ctx->r1) {
        // 0x80086D80: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80086D9C;
    }
    // 0x80086D80: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086D84: beq         $v0, $at, L_80086F5C
    if (ctx->r2 == ctx->r1) {
        // 0x80086D88: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80086F5C;
    }
    // 0x80086D88: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80086D8C: beq         $v0, $at, L_80086EFC
    if (ctx->r2 == ctx->r1) {
        // 0x80086D90: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80086EFC;
    }
    // 0x80086D90: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80086D94: b           L_800871CC
    // 0x80086D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800871CC;
    // 0x80086D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80086D9C:
    // 0x80086D9C: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80086DA0: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x80086DA4: jal         0x80073E1C
    // 0x80086DA8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    read_game_data_from_controller_pak(rdram, ctx);
        goto after_8;
    // 0x80086DA8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_8:
    // 0x80086DAC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80086DB0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80086DB4: lw          $t9, 0x10($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X10);
    // 0x80086DB8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086DBC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086DC0: andi        $t4, $t9, 0x4
    ctx->r12 = ctx->r25 & 0X4;
    // 0x80086DC4: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80086DC8: beq         $t4, $zero, L_80086DF8
    if (ctx->r12 == 0) {
        // 0x80086DCC: addiu       $t0, $t0, 0x6A04
        ctx->r8 = ADD32(ctx->r8, 0X6A04);
            goto L_80086DF8;
    }
    // 0x80086DCC: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80086DD0: jal         0x8009EC60
    // 0x80086DD4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    is_adventure_two_unlocked(rdram, ctx);
        goto after_9;
    // 0x80086DD4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_9:
    // 0x80086DD8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80086DDC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086DE0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086DE4: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80086DE8: bne         $v0, $zero, L_80086DF8
    if (ctx->r2 != 0) {
        // 0x80086DEC: addiu       $t0, $t0, 0x6A04
        ctx->r8 = ADD32(ctx->r8, 0X6A04);
            goto L_80086DF8;
    }
    // 0x80086DEC: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80086DF0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80086DF4: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_80086DF8:
    // 0x80086DF8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80086DFC: nop

    // 0x80086E00: bne         $t6, $zero, L_800871CC
    if (ctx->r14 != 0) {
        // 0x80086E04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800871CC;
    }
    // 0x80086E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086E08: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80086E0C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80086E10: sll         $t7, $t2, 4
    ctx->r15 = S32(ctx->r10 << 4);
    // 0x80086E14: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x80086E18: lbu         $a0, 0x6($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X6);
    // 0x80086E1C: jal         0x8006EC18
    // 0x80086E20: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    force_mark_write_save_file(rdram, ctx);
        goto after_10;
    // 0x80086E20: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_10:
    // 0x80086E24: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086E28: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80086E2C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086E30: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80086E34: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80086E38: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80086E3C: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x80086E40: addu        $t2, $t4, $t6
    ctx->r10 = ADD32(ctx->r12, ctx->r14);
    // 0x80086E44: lbu         $t3, 0x6($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X6);
    // 0x80086E48: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80086E4C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80086E50: addiu       $v1, $v1, 0x6530
    ctx->r3 = ADD32(ctx->r3, 0X6530);
    // 0x80086E54: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80086E58: addu        $t5, $v1, $t7
    ctx->r13 = ADD32(ctx->r3, ctx->r15);
    // 0x80086E5C: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80086E60: lw          $t9, 0x10($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X10);
    // 0x80086E64: nop

    // 0x80086E68: sw          $t9, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r25;
    // 0x80086E6C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80086E70: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80086E74: sll         $t2, $t6, 4
    ctx->r10 = S32(ctx->r14 << 4);
    // 0x80086E78: addu        $t3, $t4, $t2
    ctx->r11 = ADD32(ctx->r12, ctx->r10);
    // 0x80086E7C: lbu         $t7, 0x6($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X6);
    // 0x80086E80: nop

    // 0x80086E84: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80086E88: addu        $t9, $v1, $t5
    ctx->r25 = ADD32(ctx->r3, ctx->r13);
    // 0x80086E8C: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80086E90: nop

    // 0x80086E94: sb          $zero, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = 0;
    // 0x80086E98: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80086E9C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80086EA0: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x80086EA4: addu        $t5, $t2, $t7
    ctx->r13 = ADD32(ctx->r10, ctx->r15);
    // 0x80086EA8: lbu         $t9, 0x6($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X6);
    // 0x80086EAC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80086EB0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80086EB4: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80086EB8: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x80086EBC: lw          $t3, 0x0($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X0);
    // 0x80086EC0: nop

    // 0x80086EC4: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x80086EC8: nop

    // 0x80086ECC: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x80086ED0: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80086ED4: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80086ED8: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x80086EDC: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x80086EE0: lbu         $t3, 0x6($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X6);
    // 0x80086EE4: lw          $t7, 0x50($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X50);
    // 0x80086EE8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80086EEC: addu        $t2, $v1, $t4
    ctx->r10 = ADD32(ctx->r3, ctx->r12);
    // 0x80086EF0: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80086EF4: b           L_800871C8
    // 0x80086EF8: sw          $t7, 0x50($t9)
    MEM_W(0X50, ctx->r25) = ctx->r15;
        goto L_800871C8;
    // 0x80086EF8: sw          $t7, 0x50($t9)
    MEM_W(0X50, ctx->r25) = ctx->r15;
L_80086EFC:
    // 0x80086EFC: addiu       $v1, $v1, 0x6530
    ctx->r3 = ADD32(ctx->r3, 0X6530);
    // 0x80086F00: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    // 0x80086F04: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80086F08: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x80086F0C: jal         0x80073E1C
    // 0x80086F10: nop

    read_game_data_from_controller_pak(rdram, ctx);
        goto after_11;
    // 0x80086F10: nop

    after_11:
    // 0x80086F14: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80086F18: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086F1C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086F20: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80086F24: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80086F28: addiu       $v1, $v1, 0x6530
    ctx->r3 = ADD32(ctx->r3, 0X6530);
    // 0x80086F2C: bne         $v0, $zero, L_800871C8
    if (ctx->r2 != 0) {
        // 0x80086F30: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_800871C8;
    }
    // 0x80086F30: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80086F34: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80086F38: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80086F3C: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x80086F40: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x80086F44: lbu         $a0, 0x6($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X6);
    // 0x80086F48: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x80086F4C: jal         0x80073F5C
    // 0x80086F50: nop

    write_game_data_to_controller_pak(rdram, ctx);
        goto after_12;
    // 0x80086F50: nop

    after_12:
    // 0x80086F54: b           L_800871C8
    // 0x80086F58: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_800871C8;
    // 0x80086F58: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80086F5C:
    // 0x80086F5C: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80086F60: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x80086F64: jal         0x800762C8
    // 0x80086F68: nop

    delete_file(rdram, ctx);
        goto after_13;
    // 0x80086F68: nop

    after_13:
    // 0x80086F6C: b           L_800871C8
    // 0x80086F70: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_800871C8;
    // 0x80086F70: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80086F74:
    // 0x80086F74: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x80086F78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086F7C: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x80086F80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80086F84: beq         $t4, $zero, L_80086FA0
    if (ctx->r12 == 0) {
        // 0x80086F88: addiu       $t0, $t0, 0x6A04
        ctx->r8 = ADD32(ctx->r8, 0X6A04);
            goto L_80086FA0;
    }
    // 0x80086F88: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80086F8C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80086F90:
    // 0x80086F90: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x80086F94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80086F98: bne         $t2, $zero, L_80086F90
    if (ctx->r10 != 0) {
        // 0x80086F9C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80086F90;
    }
    // 0x80086F9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80086FA0:
    // 0x80086FA0: blez        $v1, L_80086FB8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80086FA4: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80086FB8;
    }
    // 0x80086FA4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086FA8: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x80086FAC: lbu         $t9, -0x1($t7)
    ctx->r25 = MEM_BU(ctx->r15, -0X1);
    // 0x80086FB0: b           L_80086FC0
    // 0x80086FB4: sb          $t9, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r25;
        goto L_80086FC0;
    // 0x80086FB4: sb          $t9, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r25;
L_80086FB8:
    // 0x80086FB8: addiu       $t8, $zero, 0x41
    ctx->r24 = ADD32(0, 0X41);
    // 0x80086FBC: sb          $t8, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r24;
L_80086FC0:
    // 0x80086FC0: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80086FC4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80086FC8: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80086FCC: sll         $t3, $t6, 4
    ctx->r11 = S32(ctx->r14 << 4);
    // 0x80086FD0: sb          $zero, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = 0;
    // 0x80086FD4: addu        $t4, $t5, $t3
    ctx->r12 = ADD32(ctx->r13, ctx->r11);
    // 0x80086FD8: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x80086FDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80086FE0: beq         $v0, $at, L_80087000
    if (ctx->r2 == ctx->r1) {
        // 0x80086FE4: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087000;
    }
    // 0x80086FE4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086FE8: beq         $v0, $at, L_8008706C
    if (ctx->r2 == ctx->r1) {
        // 0x80086FEC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8008706C;
    }
    // 0x80086FEC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80086FF0: beq         $v0, $at, L_80087014
    if (ctx->r2 == ctx->r1) {
        // 0x80086FF4: addiu       $a1, $sp, 0x2C
        ctx->r5 = ADD32(ctx->r29, 0X2C);
            goto L_80087014;
    }
    // 0x80086FF4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80086FF8: b           L_800871CC
    // 0x80086FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800871CC;
    // 0x80086FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087000:
    // 0x80087000: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087004: jal         0x80074018
    // 0x80087008: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    read_time_data_from_controller_pak(rdram, ctx);
        goto after_14;
    // 0x80087008: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_14:
    // 0x8008700C: b           L_800871C8
    // 0x80087010: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_800871C8;
    // 0x80087010: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80087014:
    // 0x80087014: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087018: jal         0x80074018
    // 0x8008701C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    read_time_data_from_controller_pak(rdram, ctx);
        goto after_15;
    // 0x8008701C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_15:
    // 0x80087020: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80087024: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087028: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008702C: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80087030: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80087034: bne         $v0, $zero, L_8008705C
    if (ctx->r2 != 0) {
        // 0x80087038: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_8008705C;
    }
    // 0x80087038: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8008703C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80087040: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80087044: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80087048: addu        $t8, $t2, $t9
    ctx->r24 = ADD32(ctx->r10, ctx->r25);
    // 0x8008704C: lbu         $a0, 0x6($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X6);
    // 0x80087050: jal         0x80074148
    // 0x80087054: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    write_time_data_to_controller_pak(rdram, ctx);
        goto after_16;
    // 0x80087054: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_16:
    // 0x80087058: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_8008705C:
    // 0x8008705C: jal         0x8006EB5C
    // 0x80087060: nop

    mark_to_read_flap_and_course_times(rdram, ctx);
        goto after_17;
    // 0x80087060: nop

    after_17:
    // 0x80087064: b           L_800871CC
    // 0x80087068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800871CC;
    // 0x80087068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008706C:
    // 0x8008706C: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087070: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x80087074: jal         0x800762C8
    // 0x80087078: nop

    delete_file(rdram, ctx);
        goto after_18;
    // 0x80087078: nop

    after_18:
    // 0x8008707C: b           L_800871C8
    // 0x80087080: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_800871C8;
    // 0x80087080: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80087084:
    // 0x80087084: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087088: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x8008708C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087090: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80087094: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80087098: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8008709C: sll         $t3, $t5, 4
    ctx->r11 = S32(ctx->r13 << 4);
    // 0x800870A0: addu        $v1, $t6, $t3
    ctx->r3 = ADD32(ctx->r14, ctx->r11);
    // 0x800870A4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800870A8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800870AC: beq         $v0, $at, L_800870F8
    if (ctx->r2 == ctx->r1) {
        // 0x800870B0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800870F8;
    }
    // 0x800870B0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800870B4: beq         $v0, $at, L_800870DC
    if (ctx->r2 == ctx->r1) {
        // 0x800870B8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800870DC;
    }
    // 0x800870B8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800870BC: bne         $v0, $at, L_800871C8
    if (ctx->r2 != ctx->r1) {
        // 0x800870C0: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800871C8;
    }
    // 0x800870C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800870C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800870C8: sw          $t4, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r12;
    // 0x800870CC: lbu         $t7, 0x6($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X6);
    // 0x800870D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800870D4: b           L_800871C8
    // 0x800870D8: sw          $t7, 0x64D0($at)
    MEM_W(0X64D0, ctx->r1) = ctx->r15;
        goto L_800871C8;
    // 0x800870D8: sw          $t7, 0x64D0($at)
    MEM_W(0X64D0, ctx->r1) = ctx->r15;
L_800870DC:
    // 0x800870DC: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x800870E0: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x800870E4: lbu         $a2, 0x6($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X6);
    // 0x800870E8: jal         0x80076388
    // 0x800870EC: nop

    copy_controller_pak_data(rdram, ctx);
        goto after_19;
    // 0x800870EC: nop

    after_19:
    // 0x800870F0: b           L_800871C8
    // 0x800870F4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_800871C8;
    // 0x800870F4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800870F8:
    // 0x800870F8: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x800870FC: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x80087100: jal         0x800762C8
    // 0x80087104: nop

    delete_file(rdram, ctx);
        goto after_20;
    // 0x80087104: nop

    after_20:
    // 0x80087108: b           L_800871C8
    // 0x8008710C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_800871C8;
    // 0x8008710C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80087110:
    // 0x80087110: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087114: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80087118: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008711C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80087120: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x80087124: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80087128: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x8008712C: addu        $t5, $t2, $t8
    ctx->r13 = ADD32(ctx->r10, ctx->r24);
    // 0x80087130: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80087134: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087138: bne         $t6, $at, L_800871CC
    if (ctx->r14 != ctx->r1) {
        // 0x8008713C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800871CC;
    }
    // 0x8008713C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087140: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087144: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x80087148: jal         0x800762C8
    // 0x8008714C: nop

    delete_file(rdram, ctx);
        goto after_21;
    // 0x8008714C: nop

    after_21:
    // 0x80087150: b           L_800871C8
    // 0x80087154: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_800871C8;
    // 0x80087154: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80087158:
    // 0x80087158: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008715C: addiu       $t1, $t1, 0x6BE4
    ctx->r9 = ADD32(ctx->r9, 0X6BE4);
    // 0x80087160: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087164: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80087168: addiu       $t0, $t0, 0x6A04
    ctx->r8 = ADD32(ctx->r8, 0X6A04);
    // 0x8008716C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80087170: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x80087174: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x80087178: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x8008717C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087180: bne         $t2, $at, L_800871C8
    if (ctx->r10 != ctx->r1) {
        // 0x80087184: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_800871C8;
    }
    // 0x80087184: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80087188: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8008718C: jal         0x8009EABC
    // 0x80087190: ori         $a1, $a1, 0xFFF3
    ctx->r5 = ctx->r5 | 0XFFF3;
    unset_eeprom_settings_value(rdram, ctx);
        goto after_22;
    // 0x80087190: ori         $a1, $a1, 0xFFF3
    ctx->r5 = ctx->r5 | 0XFFF3;
    after_22:
    // 0x80087194: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80087198: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008719C: addiu       $a1, $a1, -0x264
    ctx->r5 = ADD32(ctx->r5, -0X264);
    // 0x800871A0: addiu       $v1, $v1, -0x268
    ctx->r3 = ADD32(ctx->r3, -0X268);
    // 0x800871A4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800871A8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800871AC: addiu       $a0, $zero, -0x4
    ctx->r4 = ADD32(0, -0X4);
    // 0x800871B0: and         $t5, $t8, $a0
    ctx->r13 = ctx->r24 & ctx->r4;
    // 0x800871B4: and         $t4, $t6, $a0
    ctx->r12 = ctx->r14 & ctx->r4;
    // 0x800871B8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800871BC: b           L_800871C8
    // 0x800871C0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
        goto L_800871C8;
    // 0x800871C0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
L_800871C4:
    // 0x800871C4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800871C8:
    // 0x800871C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800871CC:
    // 0x800871CC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800871D0: jr          $ra
    // 0x800871D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800871D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void __osPfsDeclearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D14C4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D14C8: lbu         $t6, 0x63($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X63);
    // 0x800D14CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D14D0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800D14D4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800D14D8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800D14DC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800D14E0: blez        $t6, L_800D14F4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D14E4: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_800D14F4;
    }
    // 0x800D14E4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800D14E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D14EC: b           L_800D1500
    // 0x800D14F0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
        goto L_800D1500;
    // 0x800D14F0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_800D14F4:
    // 0x800D14F4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800D14F8: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x800D14FC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800D1500:
    // 0x800D1500: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800D1504: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800D1508: beq         $at, $zero, L_800D1544
    if (ctx->r1 == 0) {
        // 0x800D150C: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_800D1544;
    }
    // 0x800D150C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_800D1510:
    // 0x800D1510: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1514: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800D1518: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D151C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800D1520: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800D1524: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800D1528: beq         $t5, $at, L_800D1544
    if (ctx->r13 == ctx->r1) {
        // 0x800D152C: nop
    
            goto L_800D1544;
    }
    // 0x800D152C: nop

    // 0x800D1530: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1534: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D1538: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800D153C: bne         $at, $zero, L_800D1510
    if (ctx->r1 != 0) {
        // 0x800D1540: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_800D1510;
    }
    // 0x800D1540: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_800D1544:
    // 0x800D1544: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1548: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800D154C: bne         $t8, $at, L_800D1568
    if (ctx->r24 != ctx->r1) {
        // 0x800D1550: nop
    
            goto L_800D1568;
    }
    // 0x800D1550: nop

    // 0x800D1554: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800D1558: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800D155C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800D1560: b           L_800D1718
    // 0x800D1564: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800D1718;
    // 0x800D1564: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800D1568:
    // 0x800D1568: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800D156C:
    // 0x800D156C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800D1570: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x800D1574: sb          $zero, 0x24($t1)
    MEM_B(0X24, ctx->r9) = 0;
    // 0x800D1578: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800D157C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800D1580: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x800D1584: bne         $at, $zero, L_800D156C
    if (ctx->r1 != 0) {
        // 0x800D1588: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_800D156C;
    }
    // 0x800D1588: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800D158C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1590: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800D1594: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D1598: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x800D159C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800D15A0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800D15A4: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800D15A8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800D15AC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D15B0: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800D15B4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800D15B8: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x800D15BC: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D15C0: beq         $at, $zero, L_800D1694
    if (ctx->r1 == 0) {
        // 0x800D15C4: slti        $at, $t9, 0x80
        ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
            goto L_800D1694;
    }
    // 0x800D15C4: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800D15C8: beq         $at, $zero, L_800D1694
    if (ctx->r1 == 0) {
        // 0x800D15CC: nop
    
            goto L_800D1694;
    }
    // 0x800D15CC: nop

L_800D15D0:
    // 0x800D15D0: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800D15D4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800D15D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D15DC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800D15E0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800D15E4: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800D15E8: bne         $t7, $at, L_800D1660
    if (ctx->r15 != ctx->r1) {
        // 0x800D15EC: nop
    
            goto L_800D1660;
    }
    // 0x800D15EC: nop

    // 0x800D15F0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800D15F4: lbu         $t8, 0x63($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X63);
    // 0x800D15F8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800D15FC: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x800D1600: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x800D1604: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x800D1608: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800D160C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800D1610: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1614: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800D1618: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800D161C: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x800D1620: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800D1624: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800D1628: jal         0x800D1728
    // 0x800D162C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    static_3_800D1728(rdram, ctx);
        goto after_0;
    // 0x800D162C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800D1630: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D1634: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1638: beq         $t2, $zero, L_800D1648
    if (ctx->r10 == 0) {
        // 0x800D163C: nop
    
            goto L_800D1648;
    }
    // 0x800D163C: nop

    // 0x800D1640: b           L_800D1718
    // 0x800D1644: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800D1718;
    // 0x800D1644: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800D1648:
    // 0x800D1648: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800D164C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800D1650: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800D1654: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800D1658: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800D165C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
L_800D1660:
    // 0x800D1660: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1664: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800D1668: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800D166C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800D1670: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800D1674: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800D1678: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D167C: beq         $at, $zero, L_800D1694
    if (ctx->r1 == 0) {
        // 0x800D1680: nop
    
            goto L_800D1694;
    }
    // 0x800D1680: nop

    // 0x800D1684: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1688: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x800D168C: bne         $at, $zero, L_800D15D0
    if (ctx->r1 != 0) {
        // 0x800D1690: nop
    
            goto L_800D15D0;
    }
    // 0x800D1690: nop

L_800D1694:
    // 0x800D1694: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800D1698: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800D169C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800D16A0: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800D16A4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800D16A8: bne         $t1, $at, L_800D16DC
    if (ctx->r9 != ctx->r1) {
        // 0x800D16AC: nop
    
            goto L_800D16DC;
    }
    // 0x800D16AC: nop

    // 0x800D16B0: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800D16B4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800D16B8: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x800D16BC: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D16C0: beq         $at, $zero, L_800D16DC
    if (ctx->r1 == 0) {
        // 0x800D16C4: nop
    
            goto L_800D16DC;
    }
    // 0x800D16C4: nop

    // 0x800D16C8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800D16CC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800D16D0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800D16D4: b           L_800D1718
    // 0x800D16D8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800D1718;
    // 0x800D16D8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800D16DC:
    // 0x800D16DC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800D16E0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800D16E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D16E8: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800D16EC: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800D16F0: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x800D16F4: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800D16F8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800D16FC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800D1700: jal         0x800D1728
    // 0x800D1704: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    static_3_800D1728(rdram, ctx);
        goto after_1;
    // 0x800D1704: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800D1708: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800D170C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D1710: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800D1714: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800D1718:
    // 0x800D1718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D171C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800D1720: jr          $ra
    // 0x800D1724: nop

    return;
    // 0x800D1724: nop

;}
RECOMP_FUNC void wavegen_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFC54: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BFC58: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BFC5C: beq         $a0, $zero, L_800BFE90
    if (ctx->r4 == 0) {
        // 0x800BFC60: sw          $a3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r7;
            goto L_800BFE90;
    }
    // 0x800BFC60: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800BFC64: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800BFC68: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800BFC6C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800BFC70: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800BFC74: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x800BFC78: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800BFC7C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800BFC80: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800BFC84: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800BFC88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BFC8C: bc1f        L_800BFCA8
    if (!c1cs) {
        // 0x800BFC90: nop
    
            goto L_800BFCA8;
    }
    // 0x800BFC90: nop

    // 0x800BFC94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BFC98: nop

    // 0x800BFC9C: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800BFCA0: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800BFCA4: nop

L_800BFCA8:
    // 0x800BFCA8: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800BFCAC: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800BFCB0: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800BFCB4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800BFCB8: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800BFCBC: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800BFCC0: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800BFCC4: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800BFCC8: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x800BFCCC: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800BFCD0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BFCD4: bne         $t6, $zero, L_800BFD84
    if (ctx->r14 != 0) {
        // 0x800BFCD8: nop
    
            goto L_800BFD84;
    }
    // 0x800BFCD8: nop

    // 0x800BFCDC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BFCE0: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800BFCE4: lwc1        $f5, -0x6D48($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X6D48);
    // 0x800BFCE8: lwc1        $f4, -0x6D44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D44);
    // 0x800BFCEC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800BFCF0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800BFCF4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BFCF8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800BFCFC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800BFD00: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BFD04: nop

    // 0x800BFD08: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800BFD0C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BFD10: nop

    // 0x800BFD14: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800BFD18: beq         $t8, $zero, L_800BFD68
    if (ctx->r24 == 0) {
        // 0x800BFD1C: nop
    
            goto L_800BFD68;
    }
    // 0x800BFD1C: nop

    // 0x800BFD20: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800BFD24: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BFD28: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BFD2C: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x800BFD30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BFD34: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BFD38: nop

    // 0x800BFD3C: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x800BFD40: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BFD44: nop

    // 0x800BFD48: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800BFD4C: bne         $t8, $zero, L_800BFD60
    if (ctx->r24 != 0) {
        // 0x800BFD50: nop
    
            goto L_800BFD60;
    }
    // 0x800BFD50: nop

    // 0x800BFD54: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800BFD58: b           L_800BFD78
    // 0x800BFD5C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800BFD78;
    // 0x800BFD5C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800BFD60:
    // 0x800BFD60: b           L_800BFD78
    // 0x800BFD64: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800BFD78;
    // 0x800BFD64: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800BFD68:
    // 0x800BFD68: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800BFD6C: nop

    // 0x800BFD70: bltz        $t8, L_800BFD60
    if (SIGNED(ctx->r24) < 0) {
        // 0x800BFD74: nop
    
            goto L_800BFD60;
    }
    // 0x800BFD74: nop

L_800BFD78:
    // 0x800BFD78: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800BFD7C: b           L_800BFE28
    // 0x800BFD80: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
        goto L_800BFE28;
    // 0x800BFD80: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
L_800BFD84:
    // 0x800BFD84: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800BFD88: lwc1        $f5, -0x6D40($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X6D40);
    // 0x800BFD8C: lwc1        $f4, -0x6D3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D3C);
    // 0x800BFD90: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800BFD94: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800BFD98: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800BFD9C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800BFDA0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BFDA4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800BFDA8: nop

    // 0x800BFDAC: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800BFDB0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800BFDB4: nop

    // 0x800BFDB8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800BFDBC: beq         $t0, $zero, L_800BFE0C
    if (ctx->r8 == 0) {
        // 0x800BFDC0: nop
    
            goto L_800BFE0C;
    }
    // 0x800BFDC0: nop

    // 0x800BFDC4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800BFDC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BFDCC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800BFDD0: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x800BFDD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BFDD8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800BFDDC: nop

    // 0x800BFDE0: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x800BFDE4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800BFDE8: nop

    // 0x800BFDEC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800BFDF0: bne         $t0, $zero, L_800BFE04
    if (ctx->r8 != 0) {
        // 0x800BFDF4: nop
    
            goto L_800BFE04;
    }
    // 0x800BFDF4: nop

    // 0x800BFDF8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800BFDFC: b           L_800BFE1C
    // 0x800BFE00: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800BFE1C;
    // 0x800BFE00: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800BFE04:
    // 0x800BFE04: b           L_800BFE1C
    // 0x800BFE08: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800BFE1C;
    // 0x800BFE08: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800BFE0C:
    // 0x800BFE0C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800BFE10: nop

    // 0x800BFE14: bltz        $t0, L_800BFE04
    if (SIGNED(ctx->r8) < 0) {
        // 0x800BFE18: nop
    
            goto L_800BFE04;
    }
    // 0x800BFE18: nop

L_800BFE1C:
    // 0x800BFE1C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BFE20: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x800BFE24: nop

L_800BFE28:
    // 0x800BFE28: lwc1        $f10, 0x2C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800BFE2C: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800BFE30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BFE34: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800BFE38: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x800BFE3C: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800BFE40: nop

    // 0x800BFE44: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800BFE48: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x800BFE4C: nop

    // 0x800BFE50: bc1f        L_800BFE6C
    if (!c1cs) {
        // 0x800BFE54: nop
    
            goto L_800BFE6C;
    }
    // 0x800BFE54: nop

    // 0x800BFE58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BFE5C: nop

    // 0x800BFE60: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
    // 0x800BFE64: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800BFE68: nop

L_800BFE6C:
    // 0x800BFE6C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800BFE70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BFE74: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800BFE78: div.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BFE7C: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x800BFE80: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800BFE84: nop

    // 0x800BFE88: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BFE8C: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_800BFE90:
    // 0x800BFE90: jr          $ra
    // 0x800BFE94: nop

    return;
    // 0x800BFE94: nop

;}
RECOMP_FUNC void obj_init_trigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C644: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003C648: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C64C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003C650: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003C654: lb          $a2, 0x9($a1)
    ctx->r6 = MEM_B(ctx->r5, 0X9);
    // 0x8003C658: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003C65C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003C660: bne         $a2, $at, L_8003C678
    if (ctx->r6 != ctx->r1) {
        // 0x8003C664: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_8003C678;
    }
    // 0x8003C664: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8003C668: jal         0x8000CC20
    // 0x8003C66C: nop

    func_8000CC20(rdram, ctx);
        goto after_0;
    // 0x8003C66C: nop

    after_0:
    // 0x8003C670: b           L_8003C684
    // 0x8003C674: sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
        goto L_8003C684;
    // 0x8003C674: sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
L_8003C678:
    // 0x8003C678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C67C: jal         0x8000CBF0
    // 0x8003C680: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8000CBF0(rdram, ctx);
        goto after_1;
    // 0x8003C680: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
L_8003C684:
    // 0x8003C684: lb          $t6, 0x9($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X9);
    // 0x8003C688: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003C68C: bne         $t6, $at, L_8003C69C
    if (ctx->r14 != ctx->r1) {
        // 0x8003C690: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8003C69C;
    }
    // 0x8003C690: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C694: jal         0x800C9D54
    // 0x8003C698: addiu       $a0, $a0, 0x5FC8
    ctx->r4 = ADD32(ctx->r4, 0X5FC8);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003C698: addiu       $a0, $a0, 0x5FC8
    ctx->r4 = ADD32(ctx->r4, 0X5FC8);
    after_2:
L_8003C69C:
    // 0x8003C69C: lbu         $t8, 0x8($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X8);
    // 0x8003C6A0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003C6A4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8003C6A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003C6AC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003C6B0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003C6B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003C6B8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003C6BC: nop

    // 0x8003C6C0: bc1f        L_8003C6D0
    if (!c1cs) {
        // 0x8003C6C4: nop
    
            goto L_8003C6D0;
    }
    // 0x8003C6C4: nop

    // 0x8003C6C8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003C6CC: nop

L_8003C6D0:
    // 0x8003C6D0: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003C6D4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8003C6D8: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8003C6DC: lbu         $t0, 0xA($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XA);
    // 0x8003C6E0: nop

    // 0x8003C6E4: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x8003C6E8: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8003C6EC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003C6F0: jal         0x800707C4
    // 0x8003C6F4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x8003C6F4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x8003C6F8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8003C6FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003C700: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8003C704: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003C708: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003C70C: jal         0x800707F8
    // 0x8003C710: nop

    coss_f(rdram, ctx);
        goto after_4;
    // 0x8003C710: nop

    after_4:
    // 0x8003C714: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8003C718: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8003C71C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8003C720: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C724: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003C728: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003C72C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003C730: nop

    // 0x8003C734: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003C738: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003C73C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003C740: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8003C744: lbu         $t2, 0x8($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X8);
    // 0x8003C748: nop

    // 0x8003C74C: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8003C750: lbu         $t3, 0xD($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XD);
    // 0x8003C754: nop

    // 0x8003C758: sb          $t3, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r11;
    // 0x8003C75C: lw          $t5, 0x4C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C760: nop

    // 0x8003C764: sh          $t4, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r12;
    // 0x8003C768: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C76C: nop

    // 0x8003C770: sb          $zero, 0x11($t6)
    MEM_B(0X11, ctx->r14) = 0;
    // 0x8003C774: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C778: lbu         $t7, 0x8($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X8);
    // 0x8003C77C: nop

    // 0x8003C780: sb          $t7, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r15;
    // 0x8003C784: lw          $t9, 0x4C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C788: nop

    // 0x8003C78C: sb          $zero, 0x12($t9)
    MEM_B(0X12, ctx->r25) = 0;
    // 0x8003C790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C794: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003C798: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003C79C: jr          $ra
    // 0x8003C7A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003C7A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void play_char_horn_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005693C: jal         0x8009C30C
    // 0x80056940: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80056940: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80056944: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80056948: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x8005694C: beq         $t6, $zero, L_80056968
    if (ctx->r14 == 0) {
        // 0x80056950: addiu       $a1, $zero, 0x162
        ctx->r5 = ADD32(0, 0X162);
            goto L_80056968;
    }
    // 0x80056950: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80056954: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80056958: jal         0x800570B8
    // 0x8005695C: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_1;
    // 0x8005695C: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_1:
    // 0x80056960: b           L_80056980
    // 0x80056964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80056980;
    // 0x80056964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80056968:
    // 0x80056968: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005696C: nop

    // 0x80056970: lb          $a1, 0x3($t7)
    ctx->r5 = MEM_B(ctx->r15, 0X3);
    // 0x80056974: jal         0x80057048
    // 0x80056978: addiu       $a1, $a1, 0x156
    ctx->r5 = ADD32(ctx->r5, 0X156);
    racer_play_sound(rdram, ctx);
        goto after_2;
    // 0x80056978: addiu       $a1, $a1, 0x156
    ctx->r5 = ADD32(ctx->r5, 0X156);
    after_2:
    // 0x8005697C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80056980:
    // 0x80056980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80056984: jr          $ra
    // 0x80056988: nop

    return;
    // 0x80056988: nop

;}
RECOMP_FUNC void vec3f_rotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070320: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070324: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070328: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007032C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80070330: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80070334: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80070338: jal         0x800707C4
    // 0x8007033C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8007033C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    after_0:
    // 0x80070340: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070344: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x80070348: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007034C: jal         0x800707F8
    // 0x80070350: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x80070350: nop

    after_1:
    // 0x80070354: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070358: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x8007035C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80070360: sub.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80070364: jal         0x800707C4
    // 0x80070368: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80070368: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    after_2:
    // 0x8007036C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80070370: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x80070374: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070378: jal         0x800707F8
    // 0x8007037C: nop

    coss_f(rdram, ctx);
        goto after_3;
    // 0x8007037C: nop

    after_3:
    // 0x80070380: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80070384: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80070388: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8007038C: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80070390: jal         0x800707C4
    // 0x80070394: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x80070394: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    after_4:
    // 0x80070398: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8007039C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x800703A0: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800703A4: jal         0x800707F8
    // 0x800703A8: nop

    coss_f(rdram, ctx);
        goto after_5;
    // 0x800703A8: nop

    after_5:
    // 0x800703AC: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800703B0: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800703B4: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800703B8: add.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800703BC: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800703C0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800703C4: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x800703C8: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x800703CC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800703D0: jr          $ra
    // 0x800703D4: nop

    return;
    // 0x800703D4: nop

;}
RECOMP_FUNC void is_game_paused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EAA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006EAA4: lb          $v0, 0x3515($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3515);
    // 0x8006EAA8: jr          $ra
    // 0x8006EAAC: nop

    return;
    // 0x8006EAAC: nop

;}
RECOMP_FUNC void apply_vehicle_rotation_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050850: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80050854: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80050858: lbu         $t4, 0x1F1($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X1F1);
    // 0x8005085C: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x80050860: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80050864: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80050868: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005086C: bne         $t4, $zero, L_80050A20
    if (ctx->r12 != 0) {
        // 0x80050870: or          $a3, $t9, $zero
        ctx->r7 = ctx->r25 | 0;
            goto L_80050A20;
    }
    // 0x80050870: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80050874: lh          $v1, 0x160($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X160);
    // 0x80050878: ori         $t0, $zero, 0x8001
    ctx->r8 = 0 | 0X8001;
    // 0x8005087C: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x80050880: subu        $v0, $t7, $t5
    ctx->r2 = SUB32(ctx->r15, ctx->r13);
    // 0x80050884: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80050888: bne         $at, $zero, L_8005089C
    if (ctx->r1 != 0) {
        // 0x8005088C: sh          $t9, 0x166($a0)
        MEM_H(0X166, ctx->r4) = ctx->r25;
            goto L_8005089C;
    }
    // 0x8005088C: sh          $t9, 0x166($a0)
    MEM_H(0X166, ctx->r4) = ctx->r25;
    // 0x80050890: lui         $t1, 0xFFFF
    ctx->r9 = S32(0XFFFF << 16);
    // 0x80050894: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x80050898: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
L_8005089C:
    // 0x8005089C: lui         $t1, 0xFFFF
    ctx->r9 = S32(0XFFFF << 16);
    // 0x800508A0: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x800508A4: beq         $at, $zero, L_800508B4
    if (ctx->r1 == 0) {
        // 0x800508A8: ori         $t1, $t1, 0x1
        ctx->r9 = ctx->r9 | 0X1;
            goto L_800508B4;
    }
    // 0x800508A8: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x800508AC: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800508B0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_800508B4:
    // 0x800508B4: blez        $v0, L_800508E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800508B8: ori         $t2, $zero, 0xFFFF
        ctx->r10 = 0 | 0XFFFF;
            goto L_800508E4;
    }
    // 0x800508B8: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800508BC: addiu       $t3, $zero, 0x600
    ctx->r11 = ADD32(0, 0X600);
    // 0x800508C0: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800508C4: mflo        $a2
    ctx->r6 = lo;
    // 0x800508C8: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800508CC: beq         $at, $zero, L_800508DC
    if (ctx->r1 == 0) {
        // 0x800508D0: addu        $t6, $v1, $v0
        ctx->r14 = ADD32(ctx->r3, ctx->r2);
            goto L_800508DC;
    }
    // 0x800508D0: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x800508D4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800508D8: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
L_800508DC:
    // 0x800508DC: b           L_80050910
    // 0x800508E0: sh          $t6, 0x160($a0)
    MEM_H(0X160, ctx->r4) = ctx->r14;
        goto L_80050910;
    // 0x800508E0: sh          $t6, 0x160($a0)
    MEM_H(0X160, ctx->r4) = ctx->r14;
L_800508E4:
    // 0x800508E4: bgez        $v0, L_80050910
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800508E8: addiu       $t3, $zero, 0x600
        ctx->r11 = ADD32(0, 0X600);
            goto L_80050910;
    }
    // 0x800508E8: addiu       $t3, $zero, 0x600
    ctx->r11 = ADD32(0, 0X600);
    // 0x800508EC: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800508F0: mflo        $a2
    ctx->r6 = lo;
    // 0x800508F4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800508F8: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800508FC: beq         $at, $zero, L_8005090C
    if (ctx->r1 == 0) {
        // 0x80050900: addu        $t7, $v1, $v0
        ctx->r15 = ADD32(ctx->r3, ctx->r2);
            goto L_8005090C;
    }
    // 0x80050900: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x80050904: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80050908: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
L_8005090C:
    // 0x8005090C: sh          $t7, 0x160($a0)
    MEM_H(0X160, ctx->r4) = ctx->r15;
L_80050910:
    // 0x80050910: lh          $v1, 0x162($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X162);
    // 0x80050914: addiu       $t3, $zero, 0x600
    ctx->r11 = ADD32(0, 0X600);
    // 0x80050918: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8005091C: subu        $v0, $a3, $t8
    ctx->r2 = SUB32(ctx->r7, ctx->r24);
    // 0x80050920: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80050924: bne         $at, $zero, L_80050934
    if (ctx->r1 != 0) {
        // 0x80050928: slti        $at, $v0, -0x8000
        ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
            goto L_80050934;
    }
    // 0x80050928: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8005092C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80050930: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
L_80050934:
    // 0x80050934: beq         $at, $zero, L_80050940
    if (ctx->r1 == 0) {
        // 0x80050938: nop
    
            goto L_80050940;
    }
    // 0x80050938: nop

    // 0x8005093C: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_80050940:
    // 0x80050940: blez        $v0, L_8005096C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80050944: nop
    
            goto L_8005096C;
    }
    // 0x80050944: nop

    // 0x80050948: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005094C: mflo        $a2
    ctx->r6 = lo;
    // 0x80050950: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80050954: beq         $at, $zero, L_80050964
    if (ctx->r1 == 0) {
        // 0x80050958: addu        $t9, $v1, $v0
        ctx->r25 = ADD32(ctx->r3, ctx->r2);
            goto L_80050964;
    }
    // 0x80050958: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x8005095C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80050960: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
L_80050964:
    // 0x80050964: b           L_80050998
    // 0x80050968: sh          $t9, 0x162($a0)
    MEM_H(0X162, ctx->r4) = ctx->r25;
        goto L_80050998;
    // 0x80050968: sh          $t9, 0x162($a0)
    MEM_H(0X162, ctx->r4) = ctx->r25;
L_8005096C:
    // 0x8005096C: bgez        $v0, L_80050998
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80050970: nop
    
            goto L_80050998;
    }
    // 0x80050970: nop

    // 0x80050974: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050978: mflo        $a2
    ctx->r6 = lo;
    // 0x8005097C: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80050980: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80050984: beq         $at, $zero, L_80050994
    if (ctx->r1 == 0) {
        // 0x80050988: addu        $t4, $v1, $v0
        ctx->r12 = ADD32(ctx->r3, ctx->r2);
            goto L_80050994;
    }
    // 0x80050988: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x8005098C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80050990: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
L_80050994:
    // 0x80050994: sh          $t4, 0x162($a0)
    MEM_H(0X162, ctx->r4) = ctx->r12;
L_80050998:
    // 0x80050998: lh          $v1, 0x164($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X164);
    // 0x8005099C: lh          $t5, 0x12($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X12);
    // 0x800509A0: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800509A4: subu        $v0, $t5, $t6
    ctx->r2 = SUB32(ctx->r13, ctx->r14);
    // 0x800509A8: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800509AC: bne         $at, $zero, L_800509BC
    if (ctx->r1 != 0) {
        // 0x800509B0: slti        $at, $v0, -0x8000
        ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
            goto L_800509BC;
    }
    // 0x800509B0: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x800509B4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800509B8: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
L_800509BC:
    // 0x800509BC: beq         $at, $zero, L_800509C8
    if (ctx->r1 == 0) {
        // 0x800509C0: nop
    
            goto L_800509C8;
    }
    // 0x800509C0: nop

    // 0x800509C4: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_800509C8:
    // 0x800509C8: blez        $v0, L_800509F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800509CC: nop
    
            goto L_800509F4;
    }
    // 0x800509CC: nop

    // 0x800509D0: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800509D4: mflo        $a2
    ctx->r6 = lo;
    // 0x800509D8: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800509DC: beq         $at, $zero, L_800509EC
    if (ctx->r1 == 0) {
        // 0x800509E0: addu        $t7, $v1, $v0
        ctx->r15 = ADD32(ctx->r3, ctx->r2);
            goto L_800509EC;
    }
    // 0x800509E0: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x800509E4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800509E8: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
L_800509EC:
    // 0x800509EC: jr          $ra
    // 0x800509F0: sh          $t7, 0x164($a0)
    MEM_H(0X164, ctx->r4) = ctx->r15;
    return;
    // 0x800509F0: sh          $t7, 0x164($a0)
    MEM_H(0X164, ctx->r4) = ctx->r15;
L_800509F4:
    // 0x800509F4: bgez        $v0, L_80050A20
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800509F8: nop
    
            goto L_80050A20;
    }
    // 0x800509F8: nop

    // 0x800509FC: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050A00: mflo        $a2
    ctx->r6 = lo;
    // 0x80050A04: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80050A08: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80050A0C: beq         $at, $zero, L_80050A1C
    if (ctx->r1 == 0) {
        // 0x80050A10: addu        $t8, $v1, $v0
        ctx->r24 = ADD32(ctx->r3, ctx->r2);
            goto L_80050A1C;
    }
    // 0x80050A10: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x80050A14: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80050A18: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
L_80050A1C:
    // 0x80050A1C: sh          $t8, 0x164($a0)
    MEM_H(0X164, ctx->r4) = ctx->r24;
L_80050A20:
    // 0x80050A20: jr          $ra
    // 0x80050A24: nop

    return;
    // 0x80050A24: nop

;}
RECOMP_FUNC void set_time_trial_enabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E4C0: jr          $ra
    // 0x8000E4C4: sb          $a0, -0x510C($at)
    MEM_B(-0X510C, ctx->r1) = ctx->r4;
    return;
    // 0x8000E4C4: sb          $a0, -0x510C($at)
    MEM_B(-0X510C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void hud_speedometre_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3870: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3874: lw          $t7, 0x6CDC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6CDC);
    // 0x800A3878: addiu       $t6, $zero, 0x6490
    ctx->r14 = ADD32(0, 0X6490);
    // 0x800A387C: jr          $ra
    // 0x800A3880: sh          $t6, 0x4C4($t7)
    MEM_H(0X4C4, ctx->r15) = ctx->r14;
    return;
    // 0x800A3880: sh          $t6, 0x4C4($t7)
    MEM_H(0X4C4, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void __osPfsReleasePages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0B50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D0B54: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D0B58: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x800D0B5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D0B60: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0B64: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800D0B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0B6C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D0B70: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D0B74: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800D0B78: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800D0B7C: lhu         $at, 0x0($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X0);
    // 0x800D0B80: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x800D0B84: sh          $at, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r1;
    // 0x800D0B88: lhu         $t4, 0x24($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X24);
    // 0x800D0B8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0B90: beq         $t4, $at, L_800D0BC0
    if (ctx->r12 == ctx->r1) {
        // 0x800D0B94: nop
    
            goto L_800D0BC0;
    }
    // 0x800D0B94: nop

    // 0x800D0B98: lbu         $t5, 0x24($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X24);
    // 0x800D0B9C: blez        $t5, L_800D0BB0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800D0BA0: nop
    
            goto L_800D0BB0;
    }
    // 0x800D0BA0: nop

    // 0x800D0BA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D0BA8: b           L_800D0BE4
    // 0x800D0BAC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_800D0BE4;
    // 0x800D0BAC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_800D0BB0:
    // 0x800D0BB0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D0BB4: lw          $t9, 0x60($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X60);
    // 0x800D0BB8: b           L_800D0BE4
    // 0x800D0BBC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_800D0BE4;
    // 0x800D0BBC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800D0BC0:
    // 0x800D0BC0: lbu         $t2, 0x3B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D0BC4: blez        $t2, L_800D0BD8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800D0BC8: nop
    
            goto L_800D0BD8;
    }
    // 0x800D0BC8: nop

    // 0x800D0BCC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D0BD0: b           L_800D0BE4
    // 0x800D0BD4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
        goto L_800D0BE4;
    // 0x800D0BD4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_800D0BD8:
    // 0x800D0BD8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D0BDC: lw          $t0, 0x60($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X60);
    // 0x800D0BE0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_800D0BE4:
    // 0x800D0BE4: lbu         $t3, 0x25($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X25);
    // 0x800D0BE8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800D0BEC: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800D0BF0: beq         $at, $zero, L_800D0C10
    if (ctx->r1 == 0) {
        // 0x800D0BF4: nop
    
            goto L_800D0C10;
    }
    // 0x800D0BF4: nop

    // 0x800D0BF8: lhu         $t5, 0x24($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X24);
    // 0x800D0BFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0C00: beq         $t5, $at, L_800D0C10
    if (ctx->r13 == ctx->r1) {
        // 0x800D0C04: nop
    
            goto L_800D0C10;
    }
    // 0x800D0C04: nop

    // 0x800D0C08: b           L_800D0D78
    // 0x800D0C0C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800D0D78;
    // 0x800D0C0C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800D0C10:
    // 0x800D0C10: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x800D0C14: lhu         $at, 0x0($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X0);
    // 0x800D0C18: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800D0C1C: sh          $at, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r1;
    // 0x800D0C20: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800D0C24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0C28: bne         $t1, $at, L_800D0C48
    if (ctx->r9 != ctx->r1) {
        // 0x800D0C2C: nop
    
            goto L_800D0C48;
    }
    // 0x800D0C2C: nop

    // 0x800D0C30: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x800D0C34: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0C38: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800D0C3C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800D0C40: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800D0C44: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_800D0C48:
    // 0x800D0C48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D0C4C: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    // 0x800D0C50: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800D0C54: jal         0x800D0D88
    // 0x800D0C58: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    __osBlockSum(rdram, ctx);
        goto after_0;
    // 0x800D0C58: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x800D0C5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D0C60: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0C64: beq         $t9, $zero, L_800D0C74
    if (ctx->r25 == 0) {
        // 0x800D0C68: nop
    
            goto L_800D0C74;
    }
    // 0x800D0C68: nop

    // 0x800D0C6C: b           L_800D0D78
    // 0x800D0C70: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800D0D78;
    // 0x800D0C70: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800D0C74:
    // 0x800D0C74: lhu         $t8, 0x24($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X24);
    // 0x800D0C78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0C7C: bne         $t8, $at, L_800D0C8C
    if (ctx->r24 != ctx->r1) {
        // 0x800D0C80: nop
    
            goto L_800D0C8C;
    }
    // 0x800D0C80: nop

    // 0x800D0C84: b           L_800D0D78
    // 0x800D0C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D0D78;
    // 0x800D0C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D0C8C:
    // 0x800D0C8C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800D0C90: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x800D0C94: lw          $t1, 0x60($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X60);
    // 0x800D0C98: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D0C9C: bne         $at, $zero, L_800D0D34
    if (ctx->r1 != 0) {
        // 0x800D0CA0: nop
    
            goto L_800D0D34;
    }
    // 0x800D0CA0: nop

L_800D0CA4:
    // 0x800D0CA4: lbu         $t6, 0x25($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X25);
    // 0x800D0CA8: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x800D0CAC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0CB0: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800D0CB4: sh          $t3, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r11;
    // 0x800D0CB8: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x800D0CBC: lhu         $at, 0x0($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X0);
    // 0x800D0CC0: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800D0CC4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800D0CC8: sh          $at, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r1;
    // 0x800D0CCC: lbu         $t3, 0x21($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X21);
    // 0x800D0CD0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0CD4: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800D0CD8: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x800D0CDC: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x800D0CE0: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D0CE4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800D0CE8: lbu         $a1, 0x21($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X21);
    // 0x800D0CEC: jal         0x800D0D88
    // 0x800D0CF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osBlockSum(rdram, ctx);
        goto after_1;
    // 0x800D0CF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800D0CF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D0CF8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0CFC: beq         $t5, $zero, L_800D0D0C
    if (ctx->r13 == 0) {
        // 0x800D0D00: nop
    
            goto L_800D0D0C;
    }
    // 0x800D0D00: nop

    // 0x800D0D04: b           L_800D0D78
    // 0x800D0D08: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800D0D78;
    // 0x800D0D08: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800D0D0C:
    // 0x800D0D0C: lbu         $t8, 0x24($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X24);
    // 0x800D0D10: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D0D14: bne         $t8, $t0, L_800D0D34
    if (ctx->r24 != ctx->r8) {
        // 0x800D0D18: nop
    
            goto L_800D0D34;
    }
    // 0x800D0D18: nop

    // 0x800D0D1C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800D0D20: lhu         $t9, 0x24($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X24);
    // 0x800D0D24: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x800D0D28: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800D0D2C: beq         $at, $zero, L_800D0CA4
    if (ctx->r1 == 0) {
        // 0x800D0D30: nop
    
            goto L_800D0CA4;
    }
    // 0x800D0D30: nop

L_800D0D34:
    // 0x800D0D34: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D0D38: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x800D0D3C: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x800D0D40: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D0D44: bne         $at, $zero, L_800D0D64
    if (ctx->r1 != 0) {
        // 0x800D0D48: nop
    
            goto L_800D0D64;
    }
    // 0x800D0D48: nop

    // 0x800D0D4C: lbu         $t8, 0x25($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X25);
    // 0x800D0D50: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0D54: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800D0D58: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800D0D5C: addu        $t2, $t5, $t0
    ctx->r10 = ADD32(ctx->r13, ctx->r8);
    // 0x800D0D60: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
L_800D0D64:
    // 0x800D0D64: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x800D0D68: lhu         $at, 0x0($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0X0);
    // 0x800D0D6C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800D0D70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D0D74: sh          $at, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r1;
L_800D0D78:
    // 0x800D0D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0D7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D0D80: jr          $ra
    // 0x800D0D84: nop

    return;
    // 0x800D0D84: nop

;}
RECOMP_FUNC void osScGetInterruptQ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007957C: jr          $ra
    // 0x80079580: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
    return;
    // 0x80079580: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
;}
RECOMP_FUNC void music_channel_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001170: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80001174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001178: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8000117C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001180: beq         $at, $zero, L_80001198
    if (ctx->r1 == 0) {
        // 0x80001184: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80001198;
    }
    // 0x80001184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001188: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000118C: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80001190: jal         0x80063B44
    // 0x80001194: nop

    alSeqChOn(rdram, ctx);
        goto after_0;
    // 0x80001194: nop

    after_0:
L_80001198:
    // 0x80001198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000119C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800011A0: jr          $ra
    // 0x800011A4: nop

    return;
    // 0x800011A4: nop

;}
RECOMP_FUNC void hud_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A003C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A0040: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0044: lw          $v0, 0x6CF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CF8);
    // 0x800A0048: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A004C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A0050: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A0054: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A0058: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A005C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A0060: blez        $v0, L_800A012C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A0064: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800A012C;
    }
    // 0x800A0064: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A0068: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A006C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A0070: addiu       $s2, $s2, 0x6CF4
    ctx->r18 = ADD32(ctx->r18, 0X6CF4);
    // 0x800A0074: addiu       $s4, $s4, 0x6CF0
    ctx->r20 = ADD32(ctx->r20, 0X6CF0);
    // 0x800A0078: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A007C: ori         $s3, $zero, 0xC000
    ctx->r19 = 0 | 0XC000;
L_800A0080:
    // 0x800A0080: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800A0084: nop

    // 0x800A0088: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800A008C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800A0090: nop

    // 0x800A0094: beq         $a0, $zero, L_800A011C
    if (ctx->r4 == 0) {
        // 0x800A0098: nop
    
            goto L_800A011C;
    }
    // 0x800A0098: nop

    // 0x800A009C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800A00A0: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x800A00A4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800A00A8: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800A00AC: nop

    // 0x800A00B0: andi        $t1, $v0, 0xC000
    ctx->r9 = ctx->r2 & 0XC000;
    // 0x800A00B4: bne         $s3, $t1, L_800A00CC
    if (ctx->r19 != ctx->r9) {
        // 0x800A00B8: andi        $t2, $v0, 0x8000
        ctx->r10 = ctx->r2 & 0X8000;
            goto L_800A00CC;
    }
    // 0x800A00B8: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x800A00BC: jal         0x8007B2BC
    // 0x800A00C0: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800A00C0: nop

    after_0:
    // 0x800A00C4: b           L_800A0108
    // 0x800A00C8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
        goto L_800A0108;
    // 0x800A00C8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A00CC:
    // 0x800A00CC: beq         $t2, $zero, L_800A00E4
    if (ctx->r10 == 0) {
        // 0x800A00D0: andi        $t3, $v0, 0x4000
        ctx->r11 = ctx->r2 & 0X4000;
            goto L_800A00E4;
    }
    // 0x800A00D0: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x800A00D4: jal         0x8007CCB0
    // 0x800A00D8: nop

    sprite_free(rdram, ctx);
        goto after_1;
    // 0x800A00D8: nop

    after_1:
    // 0x800A00DC: b           L_800A0108
    // 0x800A00E0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
        goto L_800A0108;
    // 0x800A00E0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A00E4:
    // 0x800A00E4: beq         $t3, $zero, L_800A00FC
    if (ctx->r11 == 0) {
        // 0x800A00E8: nop
    
            goto L_800A00FC;
    }
    // 0x800A00E8: nop

    // 0x800A00EC: jal         0x8000FFB8
    // 0x800A00F0: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x800A00F0: nop

    after_2:
    // 0x800A00F4: b           L_800A0108
    // 0x800A00F8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
        goto L_800A0108;
    // 0x800A00F8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A00FC:
    // 0x800A00FC: jal         0x8005FF40
    // 0x800A0100: nop

    free_3d_model(rdram, ctx);
        goto after_3;
    // 0x800A0100: nop

    after_3:
    // 0x800A0104: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A0108:
    // 0x800A0108: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A010C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x800A0110: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800A0114: lw          $v0, 0x6CF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CF8);
    // 0x800A0118: nop

L_800A011C:
    // 0x800A011C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A0120: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800A0124: bne         $at, $zero, L_800A0080
    if (ctx->r1 != 0) {
        // 0x800A0128: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800A0080;
    }
    // 0x800A0128: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800A012C:
    // 0x800A012C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0130: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A0134: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A0138: lw          $a0, 0x6CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6CE0);
    // 0x800A013C: addiu       $s4, $s4, 0x6CF0
    ctx->r20 = ADD32(ctx->r20, 0X6CF0);
    // 0x800A0140: jal         0x80071140
    // 0x800A0144: addiu       $s2, $s2, 0x6CF4
    ctx->r18 = ADD32(ctx->r18, 0X6CF4);
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800A0144: addiu       $s2, $s2, 0x6CF4
    ctx->r18 = ADD32(ctx->r18, 0X6CF4);
    after_4:
    // 0x800A0148: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800A014C: jal         0x80071140
    // 0x800A0150: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800A0150: nop

    after_5:
    // 0x800A0154: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0158: sw          $zero, 0x6CF8($at)
    MEM_W(0X6CF8, ctx->r1) = 0;
    // 0x800A015C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800A0160: jal         0x80071140
    // 0x800A0164: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800A0164: nop

    after_6:
    // 0x800A0168: jal         0x8001004C
    // 0x800A016C: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_7;
    // 0x800A016C: nop

    after_7:
    // 0x800A0170: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0174: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A0178: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A017C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A0180: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A0184: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A0188: jr          $ra
    // 0x800A018C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A018C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
