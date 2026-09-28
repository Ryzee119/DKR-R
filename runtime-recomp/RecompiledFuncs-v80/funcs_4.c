#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void hud_main_eggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A142C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A1434: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A1438: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A143C: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x800A1440: nop

    // 0x800A1444: lb          $t7, 0x1D8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A1448: nop

    // 0x800A144C: bne         $t7, $zero, L_800A14E4
    if (ctx->r15 != 0) {
        // 0x800A1450: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A14E4;
    }
    // 0x800A1450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1454: jal         0x80068508
    // 0x800A1458: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A1458: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A145C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A1460: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A1464: jal         0x800A3CE4
    // 0x800A1468: nop

    hud_race_start(rdram, ctx);
        goto after_1;
    // 0x800A1468: nop

    after_1:
    // 0x800A146C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1470: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A1474: jal         0x800A7520
    // 0x800A1478: nop

    hud_weapon(rdram, ctx);
        goto after_2;
    // 0x800A1478: nop

    after_2:
    // 0x800A147C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1480: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A1484: lw          $v1, 0x6CDC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CDC);
    // 0x800A1488: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x800A148C: lb          $a0, 0x67A($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X67A);
    // 0x800A1490: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800A1494: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800A1498: slt         $at, $t9, $a0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A149C: bne         $at, $zero, L_800A14B0
    if (ctx->r1 != 0) {
        // 0x800A14A0: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800A14B0;
    }
    // 0x800A14A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A14A4: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // 0x800A14A8: b           L_800A14BC
    // 0x800A14AC: sb          $t0, 0x67A($v1)
    MEM_B(0X67A, ctx->r3) = ctx->r8;
        goto L_800A14BC;
    // 0x800A14AC: sb          $t0, 0x67A($v1)
    MEM_B(0X67A, ctx->r3) = ctx->r8;
L_800A14B0:
    // 0x800A14B0: addu        $t1, $a0, $v0
    ctx->r9 = ADD32(ctx->r4, ctx->r2);
    // 0x800A14B4: addiu       $t2, $t1, -0xFF
    ctx->r10 = ADD32(ctx->r9, -0XFF);
    // 0x800A14B8: sb          $t2, 0x67A($v1)
    MEM_B(0X67A, ctx->r3) = ctx->r10;
L_800A14BC:
    // 0x800A14BC: lbu         $t3, 0x6D37($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X6D37);
    // 0x800A14C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A14C4: beq         $t3, $at, L_800A14D8
    if (ctx->r11 == ctx->r1) {
        // 0x800A14C8: nop
    
            goto L_800A14D8;
    }
    // 0x800A14C8: nop

    // 0x800A14CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A14D0: jal         0x800A14F0
    // 0x800A14D4: nop

    hud_draw_eggs(rdram, ctx);
        goto after_3;
    // 0x800A14D4: nop

    after_3:
L_800A14D8:
    // 0x800A14D8: jal         0x80068508
    // 0x800A14DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_4;
    // 0x800A14DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A14E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A14E4:
    // 0x800A14E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A14E8: jr          $ra
    // 0x800A14EC: nop

    return;
    // 0x800A14EC: nop

;}
RECOMP_FUNC void lensflare_remove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC880: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AC884: addiu       $v0, $v0, 0x2A80
    ctx->r2 = ADD32(ctx->r2, 0X2A80);
    // 0x800AC888: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AC88C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AC890: bne         $a0, $t6, L_800AC8A0
    if (ctx->r4 != ctx->r14) {
        // 0x800AC894: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AC8A0;
    }
    // 0x800AC894: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC898: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800AC89C: sw          $t7, 0x2A84($at)
    MEM_W(0X2A84, ctx->r1) = ctx->r15;
L_800AC8A0:
    // 0x800AC8A0: jr          $ra
    // 0x800AC8A4: nop

    return;
    // 0x800AC8A4: nop

;}
RECOMP_FUNC void play_taj_voice_clip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AC3C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8003AC40: addiu       $a3, $a3, -0x2B2C
    ctx->r7 = ADD32(ctx->r7, -0X2B2C);
    // 0x8003AC44: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8003AC48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003AC4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AC50: beq         $a2, $zero, L_8003AC7C
    if (ctx->r6 == 0) {
        // 0x8003AC54: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8003AC7C;
    }
    // 0x8003AC54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003AC58: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8003AC5C: beq         $t6, $zero, L_8003AC7C
    if (ctx->r14 == 0) {
        // 0x8003AC60: nop
    
            goto L_8003AC7C;
    }
    // 0x8003AC60: nop

    // 0x8003AC64: jal         0x8000488C
    // 0x8003AC68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8003AC68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8003AC6C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8003AC70: addiu       $a3, $a3, -0x2B2C
    ctx->r7 = ADD32(ctx->r7, -0X2B2C);
    // 0x8003AC74: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8003AC78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003AC7C:
    // 0x8003AC7C: bne         $a2, $zero, L_8003AC94
    if (ctx->r6 != 0) {
        // 0x8003AC80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003AC94;
    }
    // 0x8003AC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AC84: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x8003AC88: jal         0x80001D04
    // 0x8003AC8C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8003AC8C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x8003AC90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003AC94:
    // 0x8003AC94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003AC98: jr          $ra
    // 0x8003AC9C: nop

    return;
    // 0x8003AC9C: nop

;}
RECOMP_FUNC void camera_init_tracks_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066230: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80066234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066238: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006623C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80066240: jal         0x8006652C
    // 0x80066244: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_layout(rdram, ctx);
        goto after_0;
    // 0x80066244: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80066248: jal         0x800665E8
    // 0x8006624C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_active_camera(rdram, ctx);
        goto after_1;
    // 0x8006624C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80066250: jal         0x80069D20
    // 0x80066254: nop

    cam_get_active_camera(rdram, ctx);
        goto after_2;
    // 0x80066254: nop

    after_2:
    // 0x80066258: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8006625C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80066260: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    // 0x80066264: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80066268: addiu       $t0, $zero, -0x8000
    ctx->r8 = ADD32(0, -0X8000);
    // 0x8006626C: sh          $t7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r15;
    // 0x80066270: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80066274: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80066278: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
    // 0x8006627C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80066280: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80066284: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80066288: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8006628C: nop

    // 0x80066290: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80066294: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80066298: nop

    // 0x8006629C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800662A0: lh          $t9, 0x38($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X38);
    // 0x800662A4: nop

    // 0x800662A8: sh          $t9, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r25;
    // 0x800662AC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800662B0: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800662B4: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x800662B8: sh          $zero, 0x38($v0)
    MEM_H(0X38, ctx->r2) = 0;
    // 0x800662BC: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x800662C0: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x800662C4: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
    // 0x800662C8: jal         0x8001D5E0
    // 0x800662CC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    update_envmap_position(rdram, ctx);
        goto after_3;
    // 0x800662CC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x800662D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800662D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800662D8: jal         0x80066CDC
    // 0x800662DC: nop

    viewport_main(rdram, ctx);
        goto after_4;
    // 0x800662DC: nop

    after_4:
    // 0x800662E0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800662E4: lh          $t1, 0x24($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X24);
    // 0x800662E8: nop

    // 0x800662EC: sh          $t1, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r9;
    // 0x800662F0: lh          $t2, 0x2A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2A);
    // 0x800662F4: nop

    // 0x800662F8: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x800662FC: lh          $t3, 0x28($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X28);
    // 0x80066300: nop

    // 0x80066304: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
    // 0x80066308: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8006630C: nop

    // 0x80066310: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x80066314: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80066318: nop

    // 0x8006631C: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x80066320: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80066324: nop

    // 0x80066328: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x8006632C: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80066330: nop

    // 0x80066334: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x80066338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006633C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80066340: jr          $ra
    // 0x80066344: nop

    return;
    // 0x80066344: nop

;}
RECOMP_FUNC void divider_draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077050: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80077054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80077058: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007705C: jal         0x8007A520
    // 0x80077060: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80077060: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80077064: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80077068: srl         $t6, $a1, 8
    ctx->r14 = S32(U32(ctx->r5) >> 8);
    // 0x8007706C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80077070: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077074: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80077078: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007707C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80077080: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x80077084: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x80077088: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007708C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077090: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077094: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80077098: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8007709C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800770A0: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x800770A4: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x800770A8: srl         $a0, $v0, 16
    ctx->r4 = S32(U32(ctx->r2) >> 16);
    // 0x800770AC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800770B0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800770B4: srl         $t2, $a0, 7
    ctx->r10 = S32(U32(ctx->r4) >> 7);
    // 0x800770B8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800770BC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x800770C0: jal         0x80066210
    // 0x800770C4: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x800770C4: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x800770C8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800770CC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800770D0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800770D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800770D8: beq         $v0, $at, L_800770FC
    if (ctx->r2 == ctx->r1) {
        // 0x800770DC: srl         $t7, $t0, 1
        ctx->r15 = S32(U32(ctx->r8) >> 1);
            goto L_800770FC;
    }
    // 0x800770DC: srl         $t7, $t0, 1
    ctx->r15 = S32(U32(ctx->r8) >> 1);
    // 0x800770E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800770E4: beq         $v0, $at, L_80077140
    if (ctx->r2 == ctx->r1) {
        // 0x800770E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80077140;
    }
    // 0x800770E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800770EC: beq         $v0, $at, L_800771D0
    if (ctx->r2 == ctx->r1) {
        // 0x800770F0: nop
    
            goto L_800771D0;
    }
    // 0x800770F0: nop

    // 0x800770F4: b           L_8007725C
    // 0x800770F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007725C;
    // 0x800770F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800770FC:
    // 0x800770FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077100: subu        $v0, $t7, $t2
    ctx->r2 = SUB32(ctx->r15, ctx->r10);
    // 0x80077104: andi        $t8, $t1, 0x3FF
    ctx->r24 = ctx->r9 & 0X3FF;
    // 0x80077108: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8007710C: addu        $t4, $v0, $t2
    ctx->r12 = ADD32(ctx->r2, ctx->r10);
    // 0x80077110: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077114: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077118: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007711C: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x80077120: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x80077124: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80077128: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x8007712C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80077130: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80077134: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077138: b           L_80077258
    // 0x8007713C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80077258;
    // 0x8007713C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80077140:
    // 0x80077140: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80077144: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80077148: jal         0x8006BDB0
    // 0x8007714C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    level_header(rdram, ctx);
        goto after_2;
    // 0x8007714C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    after_2:
    // 0x80077150: jal         0x800A8458
    // 0x80077154: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    hud_setting(rdram, ctx);
        goto after_3;
    // 0x80077154: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x80077158: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8007715C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80077160: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80077164: bne         $v0, $zero, L_80077188
    if (ctx->r2 != 0) {
        // 0x80077168: andi        $t7, $t1, 0x3FF
        ctx->r15 = ctx->r9 & 0X3FF;
            goto L_80077188;
    }
    // 0x80077168: andi        $t7, $t1, 0x3FF
    ctx->r15 = ctx->r9 & 0X3FF;
    // 0x8007716C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80077170: nop

    // 0x80077174: lb          $t5, 0x4C($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X4C);
    // 0x80077178: nop

    // 0x8007717C: andi        $t3, $t5, 0x40
    ctx->r11 = ctx->r13 & 0X40;
    // 0x80077180: beq         $t3, $zero, L_800771D0
    if (ctx->r11 == 0) {
        // 0x80077184: nop
    
            goto L_800771D0;
    }
    // 0x80077184: nop

L_80077188:
    extern void dkr_three_player_panel_begin(uint8_t*, recomp_context*); dkr_three_player_panel_begin(rdram, ctx);
    // 0x80077188: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007718C: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80077190: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077194: andi        $t4, $t0, 0x3FF
    ctx->r12 = ctx->r8 & 0X3FF;
    // 0x80077198: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8007719C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800771A0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800771A4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800771A8: or          $t3, $t9, $t5
    ctx->r11 = ctx->r25 | ctx->r13;
    // 0x800771AC: srl         $t6, $t1, 1
    ctx->r14 = S32(U32(ctx->r9) >> 1);
    // 0x800771B0: srl         $t4, $t0, 1
    ctx->r12 = S32(U32(ctx->r8) >> 1);
    // 0x800771B4: andi        $t9, $t4, 0x3FF
    ctx->r25 = ctx->r12 & 0X3FF;
    // 0x800771B8: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800771BC: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x800771C0: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800771C4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800771C8: or          $t3, $t8, $t5
    ctx->r11 = ctx->r24 | ctx->r13;
    // 0x800771CC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_800771D0:
    extern void dkr_three_player_panel_end(uint8_t*, recomp_context*); dkr_three_player_panel_end(rdram, ctx);
    // 0x800771D0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800771D4: srl         $t7, $t0, 1
    ctx->r15 = S32(U32(ctx->r8) >> 1);
    // 0x800771D8: subu        $v0, $t7, $t2
    ctx->r2 = SUB32(ctx->r15, ctx->r10);
    // 0x800771DC: andi        $t4, $t1, 0x3FF
    ctx->r12 = ctx->r9 & 0X3FF;
    // 0x800771E0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800771E4: sll         $t9, $t4, 14
    ctx->r25 = S32(ctx->r12 << 14);
    // 0x800771E8: addu        $t5, $v0, $t2
    ctx->r13 = ADD32(ctx->r2, ctx->r10);
    // 0x800771EC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800771F0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800771F4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800771F8: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800771FC: andi        $t3, $t5, 0x3FF
    ctx->r11 = ctx->r13 & 0X3FF;
    // 0x80077200: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80077204: andi        $t4, $v0, 0x3FF
    ctx->r12 = ctx->r2 & 0X3FF;
    // 0x80077208: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8007720C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80077210: srl         $t3, $t1, 1
    ctx->r11 = S32(U32(ctx->r9) >> 1);
    // 0x80077214: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077218: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007721C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077220: subu        $a1, $t3, $a3
    ctx->r5 = SUB32(ctx->r11, ctx->r7);
    // 0x80077224: addu        $t8, $a1, $a3
    ctx->r24 = ADD32(ctx->r5, ctx->r7);
    // 0x80077228: andi        $t6, $t8, 0x3FF
    ctx->r14 = ctx->r24 & 0X3FF;
    // 0x8007722C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80077230: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80077234: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80077238: andi        $t9, $t0, 0x3FF
    ctx->r25 = ctx->r8 & 0X3FF;
    // 0x8007723C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80077240: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x80077244: andi        $t8, $a1, 0x3FF
    ctx->r24 = ctx->r5 & 0X3FF;
    // 0x80077248: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x8007724C: or          $t3, $t4, $t5
    ctx->r11 = ctx->r12 | ctx->r13;
    // 0x80077250: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80077254: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80077258:
    // 0x80077258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007725C:
    // 0x8007725C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80077260: jr          $ra
    // 0x80077264: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80077264: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void hud_main_boss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A258C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2590: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2594: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A2598: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A259C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A25A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A25A4: lw          $s1, 0x64($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X64);
    // 0x800A25A8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800A25AC: jal         0x80068508
    // 0x800A25B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A25B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A25B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A25B8: jal         0x800A5A64
    // 0x800A25BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_wrong_way(rdram, ctx);
        goto after_1;
    // 0x800A25BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800A25C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A25C4: jal         0x800A3CE4
    // 0x800A25C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_start(rdram, ctx);
        goto after_2;
    // 0x800A25C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800A25CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A25D0: jal         0x800A7B68
    // 0x800A25D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_time(rdram, ctx);
        goto after_3;
    // 0x800A25D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800A25D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A25DC: jal         0x800A7520
    // 0x800A25E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_weapon(rdram, ctx);
        goto after_4;
    // 0x800A25E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800A25E4: jal         0x8006BDB0
    // 0x800A25E8: nop

    level_header(rdram, ctx);
        goto after_5;
    // 0x800A25E8: nop

    after_5:
    // 0x800A25EC: lb          $t7, 0x4B($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X4B);
    // 0x800A25F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A25F4: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800A25F8: bne         $at, $zero, L_800A2608
    if (ctx->r1 != 0) {
        // 0x800A25FC: nop
    
            goto L_800A2608;
    }
    // 0x800A25FC: nop

    // 0x800A2600: jal         0x800A4F50
    // 0x800A2604: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_lap_count(rdram, ctx);
        goto after_6;
    // 0x800A2604: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
L_800A2608:
    // 0x800A2608: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A260C: jal         0x800A3884
    // 0x800A2610: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_speedometre(rdram, ctx);
        goto after_7;
    // 0x800A2610: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800A2614: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A2618: jal         0x800A4C44
    // 0x800A261C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_position(rdram, ctx);
        goto after_8;
    // 0x800A261C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800A2620: jal         0x80068508
    // 0x800A2624: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_9;
    // 0x800A2624: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x800A2628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A262C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A2630: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A2634: jr          $ra
    // 0x800A2638: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A2638: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001CD28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD28: addiu       $sp, $sp, -0x378
    ctx->r29 = ADD32(ctx->r29, -0X378);
    // 0x8001CD2C: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8001CD30: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8001CD34: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001CD38: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8001CD3C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8001CD40: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8001CD44: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8001CD48: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8001CD4C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8001CD50: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8001CD54: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8001CD58: sw          $a0, 0x378($sp)
    MEM_W(0X378, ctx->r29) = ctx->r4;
    // 0x8001CD5C: sw          $a2, 0x380($sp)
    MEM_W(0X380, ctx->r29) = ctx->r6;
    // 0x8001CD60: sw          $a3, 0x384($sp)
    MEM_W(0X384, ctx->r29) = ctx->r7;
    // 0x8001CD64: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001CD68: addiu       $t2, $sp, 0x154
    ctx->r10 = ADD32(ctx->r29, 0X154);
L_8001CD6C:
    // 0x8001CD6C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8001CD70: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001CD74: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x8001CD78: sra         $t5, $t8, 16
    ctx->r13 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001CD7C: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CD80: slti        $at, $t5, 0x80
    ctx->r1 = SIGNED(ctx->r13) < 0X80 ? 1 : 0;
    // 0x8001CD84: bne         $at, $zero, L_8001CD6C
    if (ctx->r1 != 0) {
        // 0x8001CD88: sw          $zero, 0x0($t7)
        MEM_W(0X0, ctx->r15) = 0;
            goto L_8001CD6C;
    }
    // 0x8001CD88: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8001CD8C: lw          $t6, 0x378($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X378);
    // 0x8001CD90: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001CD94: lw          $v1, -0x50FC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50FC);
    // 0x8001CD98: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001CD9C: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x8001CDA0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001CDA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001CDA8: lw          $s4, 0x64($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X64);
    // 0x8001CDAC: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8001CDB0: lw          $fp, 0x370($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X370);
    // 0x8001CDB4: lh          $a2, 0x36C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X36C);
    // 0x8001CDB8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8001CDBC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x8001CDC0: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8001CDC4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001CDC8: sb          $t8, 0x363($sp)
    MEM_B(0X363, ctx->r29) = ctx->r24;
    // 0x8001CDCC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8001CDD0: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x8001CDD4: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8001CDD8: addiu       $t3, $sp, 0x54
    ctx->r11 = ADD32(ctx->r29, 0X54);
    // 0x8001CDDC: addiu       $t0, $sp, 0xD4
    ctx->r8 = ADD32(ctx->r29, 0XD4);
    // 0x8001CDE0: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x8001CDE4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_8001CDE8:
    // 0x8001CDE8: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
L_8001CDEC:
    // 0x8001CDEC: addu        $t6, $s4, $t9
    ctx->r14 = ADD32(ctx->r20, ctx->r25);
    // 0x8001CDF0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001CDF4: lw          $t8, 0x378($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X378);
    // 0x8001CDF8: beq         $t7, $zero, L_8001D024
    if (ctx->r15 == 0) {
        // 0x8001CDFC: addu        $s0, $s1, $t5
        ctx->r16 = ADD32(ctx->r17, ctx->r13);
            goto L_8001D024;
    }
    // 0x8001CDFC: addu        $s0, $s1, $t5
    ctx->r16 = ADD32(ctx->r17, ctx->r13);
    // 0x8001CE00: lbu         $v1, 0x9($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X9);
    // 0x8001CE04: lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA);
    // 0x8001CE08: bne         $t8, $v1, L_8001CE20
    if (ctx->r24 != ctx->r3) {
        // 0x8001CE0C: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8001CE20;
    }
    // 0x8001CE0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001CE10: lw          $t9, 0x380($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X380);
    // 0x8001CE14: nop

    // 0x8001CE18: beq         $v0, $t9, L_8001CE38
    if (ctx->r2 == ctx->r25) {
        // 0x8001CE1C: nop
    
            goto L_8001CE38;
    }
    // 0x8001CE1C: nop

L_8001CE20:
    // 0x8001CE20: lw          $t6, 0x380($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X380);
    // 0x8001CE24: lw          $t7, 0x378($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X378);
    // 0x8001CE28: bne         $t6, $v1, L_8001CE50
    if (ctx->r14 != ctx->r3) {
        // 0x8001CE2C: nop
    
            goto L_8001CE50;
    }
    // 0x8001CE2C: nop

    // 0x8001CE30: bne         $v0, $t7, L_8001CE50
    if (ctx->r2 != ctx->r15) {
        // 0x8001CE34: nop
    
            goto L_8001CE50;
    }
    // 0x8001CE34: nop

L_8001CE38:
    // 0x8001CE38: beq         $s5, $zero, L_8001CE44
    if (ctx->r21 == 0) {
        // 0x8001CE3C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001CE44;
    }
    // 0x8001CE3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001CE40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8001CE44:
    // 0x8001CE44: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001CE48: sll         $t8, $s5, 24
    ctx->r24 = S32(ctx->r21 << 24);
    // 0x8001CE4C: sra         $s5, $t8, 24
    ctx->r21 = S32(SIGNED(ctx->r24) >> 24);
L_8001CE50:
    // 0x8001CE50: beq         $a3, $zero, L_8001CEDC
    if (ctx->r7 == 0) {
        // 0x8001CE54: addiu       $a0, $t1, -0x1
        ctx->r4 = ADD32(ctx->r9, -0X1);
            goto L_8001CEDC;
    }
    // 0x8001CE54: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    // 0x8001CE58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001CE5C: blez        $t1, L_8001CEA0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001CE60: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001CEA0;
    }
    // 0x8001CE60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001CE64: lb          $t6, 0xD4($sp)
    ctx->r14 = MEM_B(ctx->r29, 0XD4);
    // 0x8001CE68: nop

    // 0x8001CE6C: beq         $v0, $t6, L_8001CEA4
    if (ctx->r2 == ctx->r14) {
        // 0x8001CE70: sll         $t7, $t5, 1
        ctx->r15 = S32(ctx->r13 << 1);
            goto L_8001CEA4;
    }
    // 0x8001CE70: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
L_8001CE74:
    // 0x8001CE74: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001CE78: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8001CE7C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001CE80: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001CE84: beq         $at, $zero, L_8001CEA0
    if (ctx->r1 == 0) {
        // 0x8001CE88: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8001CEA0;
    }
    // 0x8001CE88: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8001CE8C: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8001CE90: lb          $t6, 0x0($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X0);
    // 0x8001CE94: nop

    // 0x8001CE98: bne         $v0, $t6, L_8001CE74
    if (ctx->r2 != ctx->r14) {
        // 0x8001CE9C: nop
    
            goto L_8001CE74;
    }
    // 0x8001CE9C: nop

L_8001CEA0:
    // 0x8001CEA0: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
L_8001CEA4:
    // 0x8001CEA4: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x8001CEA8: lh          $t9, 0x10($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X10);
    // 0x8001CEAC: bne         $a2, $t1, L_8001CEBC
    if (ctx->r6 != ctx->r9) {
        // 0x8001CEB0: addu        $fp, $t9, $ra
        ctx->r30 = ADD32(ctx->r25, ctx->r31);
            goto L_8001CEBC;
    }
    // 0x8001CEB0: addu        $fp, $t9, $ra
    ctx->r30 = ADD32(ctx->r25, ctx->r31);
    // 0x8001CEB4: b           L_8001CEDC
    // 0x8001CEB8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_8001CEDC;
    // 0x8001CEB8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8001CEBC:
    // 0x8001CEBC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001CEC0: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CEC4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001CEC8: nop

    // 0x8001CECC: slt         $at, $fp, $t8
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001CED0: beq         $at, $zero, L_8001CEDC
    if (ctx->r1 == 0) {
        // 0x8001CED4: nop
    
            goto L_8001CEDC;
    }
    // 0x8001CED4: nop

    // 0x8001CED8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8001CEDC:
    // 0x8001CEDC: beq         $a3, $zero, L_8001D024
    if (ctx->r7 == 0) {
        // 0x8001CEE0: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_8001D024;
    }
    // 0x8001CEE0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8001CEE4: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001CEE8: beq         $at, $zero, L_8001CF1C
    if (ctx->r1 == 0) {
        // 0x8001CEEC: addu        $t4, $t2, $t9
        ctx->r12 = ADD32(ctx->r10, ctx->r25);
            goto L_8001CF1C;
    }
    // 0x8001CEEC: addu        $t4, $t2, $t9
    ctx->r12 = ADD32(ctx->r10, ctx->r25);
L_8001CEF0:
    // 0x8001CEF0: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x8001CEF4: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
    // 0x8001CEF8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001CEFC: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8001CF00: lb          $t6, 0x1($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1);
    // 0x8001CF04: lb          $t7, 0x1($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1);
    // 0x8001CF08: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001CF0C: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001CF10: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8001CF14: bne         $at, $zero, L_8001CEF0
    if (ctx->r1 != 0) {
        // 0x8001CF18: sb          $t7, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r15;
            goto L_8001CEF0;
    }
    // 0x8001CF18: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_8001CF1C:
    // 0x8001CF1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001CF20: bne         $a3, $at, L_8001CF38
    if (ctx->r7 != ctx->r1) {
        // 0x8001CF24: nop
    
            goto L_8001CF38;
    }
    // 0x8001CF24: nop

    // 0x8001CF28: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001CF2C: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x8001CF30: sra         $t1, $t6, 16
    ctx->r9 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001CF34: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
L_8001CF38:
    // 0x8001CF38: sw          $fp, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r30;
    // 0x8001CF3C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8001CF40: lb          $t6, 0x363($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X363);
    // 0x8001CF44: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x8001CF48: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001CF4C: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001CF50: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8001CF54: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8001CF58: addu        $a1, $t3, $t9
    ctx->r5 = ADD32(ctx->r11, ctx->r25);
    // 0x8001CF5C: beq         $t6, $zero, L_8001CF70
    if (ctx->r14 == 0) {
        // 0x8001CF60: addu        $v1, $t0, $t9
        ctx->r3 = ADD32(ctx->r8, ctx->r25);
            goto L_8001CF70;
    }
    // 0x8001CF60: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x8001CF64: lbu         $t7, 0xA($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XA);
    // 0x8001CF68: b           L_8001CF74
    // 0x8001CF6C: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
        goto L_8001CF74;
    // 0x8001CF6C: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
L_8001CF70:
    // 0x8001CF70: sb          $s3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r19;
L_8001CF74:
    // 0x8001CF74: lbu         $t8, 0xA($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XA);
    // 0x8001CF78: blez        $v0, L_8001D024
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001CF7C: sb          $t8, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r24;
            goto L_8001D024;
    }
    // 0x8001CF7C: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8001CF80: lb          $t9, -0x1($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X1);
    // 0x8001CF84: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x8001CF88: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001CF8C: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x8001CF90: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CF94: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001CF98: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001CF9C: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CFA0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001CFA4: nop

    // 0x8001CFA8: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001CFAC: beq         $at, $zero, L_8001D024
    if (ctx->r1 == 0) {
        // 0x8001CFB0: nop
    
            goto L_8001D024;
    }
    // 0x8001CFB0: nop

    // 0x8001CFB4: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8001CFB8: lb          $a1, -0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, -0X1);
    // 0x8001CFBC: nop

    // 0x8001CFC0: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
L_8001CFC4:
    // 0x8001CFC4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001CFC8: lb          $a3, 0x0($v1)
    ctx->r7 = MEM_B(ctx->r3, 0X0);
    // 0x8001CFCC: lb          $t6, -0x1($v1)
    ctx->r14 = MEM_B(ctx->r3, -0X1);
    // 0x8001CFD0: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8001CFD4: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001CFD8: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x8001CFDC: sb          $a0, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r4;
    // 0x8001CFE0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8001CFE4: sb          $a3, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r7;
    // 0x8001CFE8: blez        $t9, L_8001D024
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001CFEC: sb          $t6, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r14;
            goto L_8001D024;
    }
    // 0x8001CFEC: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8001CFF0: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x8001CFF4: lb          $a1, -0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, -0X1);
    // 0x8001CFF8: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8001CFFC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8001D000: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001D004: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8001D008: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001D00C: addu        $t6, $t2, $t9
    ctx->r14 = ADD32(ctx->r10, ctx->r25);
    // 0x8001D010: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001D014: nop

    // 0x8001D018: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001D01C: bne         $at, $zero, L_8001CFC4
    if (ctx->r1 != 0) {
        // 0x8001D020: addu        $v1, $t3, $a2
        ctx->r3 = ADD32(ctx->r11, ctx->r6);
            goto L_8001CFC4;
    }
    // 0x8001D020: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
L_8001D024:
    // 0x8001D024: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001D028: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8001D02C: sra         $t5, $t9, 16
    ctx->r13 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001D030: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8001D034: bne         $at, $zero, L_8001CDEC
    if (ctx->r1 != 0) {
        // 0x8001D038: sll         $t9, $t5, 2
        ctx->r25 = S32(ctx->r13 << 2);
            goto L_8001CDEC;
    }
    // 0x8001D038: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8001D03C: blez        $t1, L_8001D0E8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001D040: nop
    
            goto L_8001D0E8;
    }
    // 0x8001D040: nop

    // 0x8001D044: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8001D048: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8001D04C: sra         $t1, $t8, 16
    ctx->r9 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001D050: addu        $t9, $t0, $t1
    ctx->r25 = ADD32(ctx->r8, ctx->r9);
    // 0x8001D054: lb          $v1, 0x0($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X0);
    // 0x8001D058: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8001D05C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8001D060: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8001D064: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8001D068: addu        $t9, $t3, $t1
    ctx->r25 = ADD32(ctx->r11, ctx->r9);
    // 0x8001D06C: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8001D070: lb          $s3, 0x0($t9)
    ctx->r19 = MEM_B(ctx->r25, 0X0);
    // 0x8001D074: lbu         $t6, 0x9($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X9);
    // 0x8001D078: andi        $t9, $s6, 0x100
    ctx->r25 = ctx->r22 & 0X100;
    // 0x8001D07C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001D080: addu        $t7, $t2, $t8
    ctx->r15 = ADD32(ctx->r10, ctx->r24);
    // 0x8001D084: lw          $ra, 0x0($t7)
    ctx->r31 = MEM_W(ctx->r15, 0X0);
    // 0x8001D088: lw          $s4, 0x64($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X64);
    // 0x8001D08C: beq         $t9, $zero, L_8001D0B0
    if (ctx->r25 == 0) {
        // 0x8001D090: sb          $zero, 0x363($sp)
        MEM_B(0X363, ctx->r29) = 0;
            goto L_8001D0B0;
    }
    // 0x8001D090: sb          $zero, 0x363($sp)
    MEM_B(0X363, ctx->r29) = 0;
    // 0x8001D094: andi        $t6, $s6, 0x7F
    ctx->r14 = ctx->r22 & 0X7F;
    // 0x8001D098: bne         $t6, $v1, L_8001D0CC
    if (ctx->r14 != ctx->r3) {
        // 0x8001D09C: nop
    
            goto L_8001D0CC;
    }
    // 0x8001D09C: nop

    // 0x8001D0A0: sll         $s2, $s3, 16
    ctx->r18 = S32(ctx->r19 << 16);
    // 0x8001D0A4: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D0A8: b           L_8001D0CC
    // 0x8001D0AC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
        goto L_8001D0CC;
    // 0x8001D0AC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_8001D0B0:
    // 0x8001D0B0: lbu         $t7, 0x8($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X8);
    // 0x8001D0B4: nop

    // 0x8001D0B8: bne         $s6, $t7, L_8001D0CC
    if (ctx->r22 != ctx->r15) {
        // 0x8001D0BC: nop
    
            goto L_8001D0CC;
    }
    // 0x8001D0BC: nop

    // 0x8001D0C0: sll         $s2, $s3, 16
    ctx->r18 = S32(ctx->r19 << 16);
    // 0x8001D0C4: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D0C8: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_8001D0CC:
    // 0x8001D0CC: bne         $t1, $zero, L_8001D0E8
    if (ctx->r9 != 0) {
        // 0x8001D0D0: nop
    
            goto L_8001D0E8;
    }
    // 0x8001D0D0: nop

    // 0x8001D0D4: bne         $s2, $s7, L_8001D0E8
    if (ctx->r18 != ctx->r23) {
        // 0x8001D0D8: nop
    
            goto L_8001D0E8;
    }
    // 0x8001D0D8: nop

    // 0x8001D0DC: sll         $s2, $s3, 16
    ctx->r18 = S32(ctx->r19 << 16);
    // 0x8001D0E0: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D0E4: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
L_8001D0E8:
    // 0x8001D0E8: bne         $s2, $s7, L_8001D100
    if (ctx->r18 != ctx->r23) {
        // 0x8001D0EC: nop
    
            goto L_8001D100;
    }
    // 0x8001D0EC: nop

    // 0x8001D0F0: bgtz        $t1, L_8001CDE8
    if (SIGNED(ctx->r9) > 0) {
        // 0x8001D0F4: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_8001CDE8;
    }
    // 0x8001D0F4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001D0F8: sw          $fp, 0x370($sp)
    MEM_W(0X370, ctx->r29) = ctx->r30;
    // 0x8001D0FC: sh          $a2, 0x36C($sp)
    MEM_H(0X36C, ctx->r29) = ctx->r6;
L_8001D100:
    // 0x8001D100: beq         $s2, $s7, L_8001D17C
    if (ctx->r18 == ctx->r23) {
        // 0x8001D104: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001D17C;
    }
    // 0x8001D104: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D108: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8001D10C: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001D110: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001D114: nop

    // 0x8001D118: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8001D11C: lw          $s4, 0x64($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X64);
    // 0x8001D120: lbu         $t7, 0xA($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XA);
    // 0x8001D124: nop

    // 0x8001D128: beq         $s2, $t7, L_8001D160
    if (ctx->r18 == ctx->r15) {
        // 0x8001D12C: slti        $at, $t5, 0x4
        ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
            goto L_8001D160;
    }
    // 0x8001D12C: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
L_8001D130:
    // 0x8001D130: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001D134: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8001D138: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001D13C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8001D140: beq         $at, $zero, L_8001D15C
    if (ctx->r1 == 0) {
        // 0x8001D144: or          $t5, $t6, $zero
        ctx->r13 = ctx->r14 | 0;
            goto L_8001D15C;
    }
    // 0x8001D144: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x8001D148: addu        $t8, $s1, $t6
    ctx->r24 = ADD32(ctx->r17, ctx->r14);
    // 0x8001D14C: lbu         $t7, 0xA($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XA);
    // 0x8001D150: nop

    // 0x8001D154: bne         $s2, $t7, L_8001D130
    if (ctx->r18 != ctx->r15) {
        // 0x8001D158: nop
    
            goto L_8001D130;
    }
    // 0x8001D158: nop

L_8001D15C:
    // 0x8001D15C: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
L_8001D160:
    // 0x8001D160: beq         $at, $zero, L_8001D17C
    if (ctx->r1 == 0) {
        // 0x8001D164: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001D17C;
    }
    // 0x8001D164: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D168: lw          $t9, 0x384($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X384);
    // 0x8001D16C: nop

    // 0x8001D170: addu        $t6, $s4, $t9
    ctx->r14 = ADD32(ctx->r20, ctx->r25);
    // 0x8001D174: sb          $t5, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r13;
    // 0x8001D178: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001D17C:
    // 0x8001D17C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8001D180: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8001D184: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8001D188: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8001D18C: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8001D190: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8001D194: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D198: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8001D19C: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8001D1A0: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8001D1A4: jr          $ra
    // 0x8001D1A8: addiu       $sp, $sp, 0x378
    ctx->r29 = ADD32(ctx->r29, 0X378);
    return;
    // 0x8001D1A8: addiu       $sp, $sp, 0x378
    ctx->r29 = ADD32(ctx->r29, 0X378);
;}
RECOMP_FUNC void resolve_collisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031600: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80031604: sb          $t0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r8;
    // 0x80031608: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8003160C: lw          $t0, -0x2C88($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2C88);
    // 0x80031610: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80031614: sb          $zero, 0x0($sp)
    MEM_B(0X0, ctx->r29) = 0;
    // 0x80031618: beq         $t0, $zero, L_80031B4C
    if (ctx->r8 == 0) {
        // 0x8003161C: sw          $zero, -0x4F10($at)
        MEM_W(-0X4F10, ctx->r1) = 0;
            goto L_80031B4C;
    }
    // 0x8003161C: sw          $zero, -0x4F10($at)
    MEM_W(-0X4F10, ctx->r1) = 0;
L_80031620:
    // 0x80031620: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
L_80031624:
    // 0x80031624: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80031628: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8003162C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80031630: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80031634: lw          $t5, -0x2C8C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2C8C);
    // 0x80031638: lw          $t1, -0x2C90($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2C90);
    // 0x8003163C: lw          $t0, -0x2C88($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2C88);
L_80031640:
    // 0x80031640: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80031644: blezl       $t2, L_80031660
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80031648: lhu         $v0, 0x0($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0X0);
            goto L_80031660;
    }
    goto skip_0;
    // 0x80031648: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    skip_0:
    // 0x8003164C: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80031650: or          $t3, $t3, $t2
    ctx->r11 = ctx->r11 | ctx->r10;
    // 0x80031654: j           L_80031944
    // 0x80031658: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
        goto L_80031944;
    // 0x80031658: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
    // 0x8003165C: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
L_80031660:
    // 0x80031660: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031664: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80031668: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8003166C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80031670: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80031674: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031678: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003167C: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80031680: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031684: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80031688: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8003168C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031690: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80031694: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80031698: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8003169C: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800316A0: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800316A4: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800316A8: lwc1        $f8, 0x5F60($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F60);
    // 0x800316AC: c.olt.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x800316B0: bc1fl       L_80031948
    if (!c1cs) {
        // 0x800316B4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031948;
    }
    goto skip_1;
    // 0x800316B4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_1:
    // 0x800316B8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800316BC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800316C0: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800316C4: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800316C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800316CC: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800316D0: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800316D4: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800316D8: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800316DC: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800316E0: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800316E4: sub.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800316E8: lwc1        $f8, 0x5F64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F64);
    // 0x800316EC: c.olt.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800316F0: bc1tl       L_80031948
    if (c1cs) {
        // 0x800316F4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031948;
    }
    goto skip_2;
    // 0x800316F4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_2:
    // 0x800316F8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800316FC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031700: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80031704: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031708: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8003170C: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80031710: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80031714: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031718: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8003171C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80031720: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80031724: c.ueq.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80031728: bc1t        L_80031734
    if (c1cs) {
        // 0x8003172C: nop
    
            goto L_80031734;
    }
    // 0x8003172C: nop

    // 0x80031730: div.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
L_80031734:
    // 0x80031734: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80031738: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003173C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80031740: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80031744: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80031748: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8003174C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031750: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80031754: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031758: add.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8003175C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80031760: add.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f4.fl;
L_80031764:
    // 0x80031764: lhu         $v1, 0x2($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X2);
    // 0x80031768: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8003176C: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x80031770: beql        $t9, $zero, L_80031784
    if (ctx->r25 == 0) {
        // 0x80031774: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_80031784;
    }
    goto skip_3;
    // 0x80031774: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    skip_3:
    // 0x80031778: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x8003177C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80031780: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
L_80031784:
    // 0x80031784: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80031788: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003178C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80031790: mul.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80031794: nop

    // 0x80031798: mul.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8003179C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800317A0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800317A4: mul.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800317A8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800317AC: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800317B0: beq         $t8, $zero, L_800317BC
    if (ctx->r24 == 0) {
        // 0x800317B4: add.s       $f6, $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_800317BC;
    }
    // 0x800317B4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800317B8: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
L_800317BC:
    // 0x800317BC: c.ole.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x800317C0: bc1fl       L_80031948
    if (!c1cs) {
        // 0x800317C4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031948;
    }
    goto skip_4;
    // 0x800317C4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_4:
    // 0x800317C8: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800317CC: bne         $t4, $zero, L_80031764
    if (ctx->r12 != 0) {
        // 0x800317D0: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_80031764;
    }
    // 0x800317D0: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x800317D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800317D8: lwc1        $f0, 0x5F68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F68);
    // 0x800317DC: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800317E0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800317E4: c.ult.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800317E8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800317EC: bc1t        L_80031848
    if (c1cs) {
        // 0x800317F0: nop
    
            goto L_80031848;
    }
    // 0x800317F0: nop

    // 0x800317F4: lb          $v1, 0x0($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X0);
    // 0x800317F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800317FC: beq         $v1, $at, L_80031848
    if (ctx->r3 == ctx->r1) {
        // 0x80031800: nop
    
            goto L_80031848;
    }
    // 0x80031800: nop

    // 0x80031804: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80031808: lw          $v1, -0x4F0C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4F0C);
    // 0x8003180C: bne         $v1, $zero, L_80031848
    if (ctx->r3 != 0) {
        // 0x80031810: nop
    
            goto L_80031848;
    }
    // 0x80031810: nop

    // 0x80031814: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031818: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003181C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031820: mul.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80031824: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80031828: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8003182C: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031830: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80031834: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031838: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8003183C: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80031840: j           L_800318C8
    // 0x80031844: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
        goto L_800318C8;
    // 0x80031844: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_80031848:
    // 0x80031848: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003184C: lwc1        $f10, 0x5F6C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F6C);
    // 0x80031850: c.olt.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80031854: bc1f        L_800318A0
    if (!c1cs) {
        // 0x80031858: nop
    
            goto L_800318A0;
    }
    // 0x80031858: nop

    // 0x8003185C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80031860: lw          $v1, -0x4F0C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4F0C);
    // 0x80031864: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80031868: beq         $v1, $at, L_800318A0
    if (ctx->r3 == ctx->r1) {
        // 0x8003186C: nop
    
            goto L_800318A0;
    }
    // 0x8003186C: nop

    // 0x80031870: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80031874: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80031878: sw          $v1, -0x4F10($at)
    MEM_W(-0X4F10, ctx->r1) = ctx->r3;
    // 0x8003187C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80031880: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80031884: swc1        $f6, -0x4F1C($at)
    MEM_W(-0X4F1C, ctx->r1) = ctx->f6.u32l;
    // 0x80031888: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8003188C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80031890: swc1        $f6, -0x4F18($at)
    MEM_W(-0X4F18, ctx->r1) = ctx->f6.u32l;
    // 0x80031894: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031898: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003189C: swc1        $f6, -0x4F14($at)
    MEM_W(-0X4F14, ctx->r1) = ctx->f6.u32l;
L_800318A0:
    // 0x800318A0: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800318A4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800318A8: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800318AC: nop

    // 0x800318B0: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800318B4: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800318B8: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800318BC: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800318C0: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800318C4: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
L_800318C8:
    // 0x800318C8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800318CC: lw          $v1, -0x4F10($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4F10);
    // 0x800318D0: bnel        $v1, $zero, L_80031900
    if (ctx->r3 != 0) {
        // 0x800318D4: lb          $t4, 0x0($t5)
        ctx->r12 = MEM_B(ctx->r13, 0X0);
            goto L_80031900;
    }
    goto skip_5;
    // 0x800318D4: lb          $t4, 0x0($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X0);
    skip_5:
    // 0x800318D8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800318DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318E0: swc1        $f6, -0x4F1C($at)
    MEM_W(-0X4F1C, ctx->r1) = ctx->f6.u32l;
    // 0x800318E4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800318E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318EC: swc1        $f6, -0x4F18($at)
    MEM_W(-0X4F18, ctx->r1) = ctx->f6.u32l;
    // 0x800318F0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800318F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318F8: swc1        $f6, -0x4F14($at)
    MEM_W(-0X4F14, ctx->r1) = ctx->f6.u32l;
    // 0x800318FC: lb          $t4, 0x0($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X0);
L_80031900:
    // 0x80031900: lb          $v0, 0x0($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X0);
    // 0x80031904: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80031908: beql        $at, $zero, L_80031918
    if (ctx->r1 == 0) {
        // 0x8003190C: addiu       $t6, $t6, 0x1
        ctx->r14 = ADD32(ctx->r14, 0X1);
            goto L_80031918;
    }
    goto skip_6;
    // 0x8003190C: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    skip_6:
    // 0x80031910: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x80031914: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
L_80031918:
    // 0x80031918: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x8003191C: bne         $at, $zero, L_80031934
    if (ctx->r1 != 0) {
        // 0x80031920: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80031934;
    }
    // 0x80031920: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80031924: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80031928: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003192C: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031930: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
L_80031934:
    // 0x80031934: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80031938: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x8003193C: j           L_80031954
    // 0x80031940: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
        goto L_80031954;
    // 0x80031940: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
L_80031944:
    // 0x80031944: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_80031948:
    // 0x80031948: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8003194C: bne         $t0, $zero, L_80031640
    if (ctx->r8 != 0) {
        // 0x80031950: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_80031640;
    }
    // 0x80031950: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_80031954:
    // 0x80031954: bne         $t7, $zero, L_80031624
    if (ctx->r15 != 0) {
        // 0x80031958: nop
    
            goto L_80031624;
    }
    // 0x80031958: nop

    // 0x8003195C: beq         $t6, $zero, L_80031980
    if (ctx->r14 == 0) {
        // 0x80031960: lbu         $t2, 0x1($sp)
        ctx->r10 = MEM_BU(ctx->r29, 0X1);
            goto L_80031980;
    }
    // 0x80031960: lbu         $t2, 0x1($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1);
    // 0x80031964: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80031968: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8003196C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80031970: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80031974: lbu         $t0, 0x0($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X0);
    // 0x80031978: or          $t0, $t0, $t2
    ctx->r8 = ctx->r8 | ctx->r10;
    // 0x8003197C: sb          $t0, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r8;
L_80031980:
    // 0x80031980: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80031984: sb          $t2, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r10;
    // 0x80031988: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
L_8003198C:
    // 0x8003198C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80031990: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80031994: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80031998: lw          $t1, -0x2C90($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2C90);
    // 0x8003199C: lw          $t0, -0x2C88($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2C88);
L_800319A0:
    // 0x800319A0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800319A4: blezl       $t2, L_800319C0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800319A8: lhu         $v0, 0x0($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0X0);
            goto L_800319C0;
    }
    goto skip_7;
    // 0x800319A8: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    skip_7:
    // 0x800319AC: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800319B0: or          $t3, $t3, $t2
    ctx->r11 = ctx->r11 | ctx->r10;
    // 0x800319B4: j           L_80031B18
    // 0x800319B8: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
        goto L_80031B18;
    // 0x800319B8: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
    // 0x800319BC: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
L_800319C0:
    // 0x800319C0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800319C4: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800319C8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800319CC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800319D0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800319D4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800319D8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800319DC: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800319E0: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800319E4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800319E8: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800319EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800319F0: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800319F4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800319F8: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800319FC: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80031A00: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031A04: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80031A08: lwc1        $f8, 0x5F70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F70);
    // 0x80031A0C: c.olt.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80031A10: bc1f        L_80031B18
    if (!c1cs) {
        // 0x80031A14: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80031B18;
    }
    // 0x80031A14: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80031A18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031A1C: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031A20: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80031A24: neg.s       $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = -ctx->f8.fl;
    // 0x80031A28: c.ole.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x80031A2C: bc1t        L_80031B18
    if (c1cs) {
        // 0x80031A30: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80031B18;
    }
    // 0x80031A30: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80031A34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031A38: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031A3C: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80031A40: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031A44: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_80031A48:
    // 0x80031A48: lhu         $v1, 0x2($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X2);
    // 0x80031A4C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80031A50: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x80031A54: beql        $t9, $zero, L_80031A68
    if (ctx->r25 == 0) {
        // 0x80031A58: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_80031A68;
    }
    goto skip_8;
    // 0x80031A58: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    skip_8:
    // 0x80031A5C: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x80031A60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80031A64: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
L_80031A68:
    // 0x80031A68: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80031A6C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80031A70: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80031A74: mul.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80031A78: nop

    // 0x80031A7C: mul.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80031A80: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80031A84: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80031A88: mul.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80031A8C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80031A90: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80031A94: beq         $t8, $zero, L_80031AA0
    if (ctx->r24 == 0) {
        // 0x80031A98: add.s       $f6, $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_80031AA0;
    }
    // 0x80031A98: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80031A9C: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
L_80031AA0:
    // 0x80031AA0: c.ole.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x80031AA4: bc1fl       L_80031B1C
    if (!c1cs) {
        // 0x80031AA8: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031B1C;
    }
    goto skip_9;
    // 0x80031AA8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_9:
    // 0x80031AAC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80031AB0: bne         $t4, $zero, L_80031A48
    if (ctx->r12 != 0) {
        // 0x80031AB4: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_80031A48;
    }
    // 0x80031AB4: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80031AB8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80031ABC: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031AC0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031AC4: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80031AC8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031ACC: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x80031AD0: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80031AD4: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80031AD8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80031ADC: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80031AE0: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80031AE4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80031AE8: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80031AEC: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031AF0: bne         $at, $zero, L_80031B08
    if (ctx->r1 != 0) {
        // 0x80031AF4: sub.s       $f4, $f6, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
            goto L_80031B08;
    }
    // 0x80031AF4: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80031AF8: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80031AFC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80031B00: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031B04: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
L_80031B08:
    // 0x80031B08: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80031B0C: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x80031B10: j           L_80031B24
    // 0x80031B14: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
        goto L_80031B24;
    // 0x80031B14: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
L_80031B18:
    // 0x80031B18: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_80031B1C:
    // 0x80031B1C: bne         $t0, $zero, L_800319A0
    if (ctx->r8 != 0) {
        // 0x80031B20: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_800319A0;
    }
    // 0x80031B20: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_80031B24:
    // 0x80031B24: bne         $t7, $zero, L_8003198C
    if (ctx->r15 != 0) {
        // 0x80031B28: nop
    
            goto L_8003198C;
    }
    // 0x80031B28: nop

    // 0x80031B2C: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x80031B30: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80031B34: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80031B38: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80031B3C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80031B40: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80031B44: bne         $t0, $zero, L_80031620
    if (ctx->r8 != 0) {
        // 0x80031B48: sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
            goto L_80031620;
    }
    // 0x80031B48: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_80031B4C:
    // 0x80031B4C: jr          $ra
    // 0x80031B50: lb          $v0, 0x0($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X0);
    return;
    // 0x80031B50: lb          $v0, 0x0($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X0);
;}
RECOMP_FUNC void spectate_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BD94: bltz        $a0, L_8001BDB0
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001BD98: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001BDB0;
    }
    // 0x8001BD98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BD9C: lw          $t6, -0x5120($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5120);
    // 0x8001BDA0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001BDA4: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001BDA8: bne         $at, $zero, L_8001BDB8
    if (ctx->r1 != 0) {
        // 0x8001BDAC: nop
    
            goto L_8001BDB8;
    }
    // 0x8001BDAC: nop

L_8001BDB0:
    // 0x8001BDB0: jr          $ra
    // 0x8001BDB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BDB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BDB8:
    // 0x8001BDB8: lw          $t7, -0x5124($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5124);
    // 0x8001BDBC: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8001BDC0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001BDC4: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8001BDC8: nop

    // 0x8001BDCC: jr          $ra
    // 0x8001BDD0: nop

    return;
    // 0x8001BDD0: nop

;}
RECOMP_FUNC void set_voice_limit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B010: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000B014: jr          $ra
    // 0x8000B018: sb          $a1, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r5;
    return;
    // 0x8000B018: sb          $a1, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void mtx_shear_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068FA8: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x80068FAC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80068FB0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80068FB4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80068FB8: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80068FBC: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x80068FC0: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80068FC4: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x80068FC8: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80068FCC: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x80068FD0: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80068FD4: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80068FD8: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80068FDC: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80068FE0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80068FE4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80068FE8: sw          $a0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r4;
    // 0x80068FEC: sw          $a1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r5;
    // 0x80068FF0: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x80068FF4: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80068FF8: jal         0x800707F8
    // 0x80068FFC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80068FFC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    after_0:
    // 0x80069000: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80069004: jal         0x800707C4
    // 0x80069008: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80069008: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    after_1:
    // 0x8006900C: swc1        $f0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f0.u32l;
    // 0x80069010: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80069014: jal         0x800707F8
    // 0x80069018: nop

    coss_f(rdram, ctx);
        goto after_2;
    // 0x80069018: nop

    after_2:
    // 0x8006901C: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80069020: jal         0x800707C4
    // 0x80069024: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80069024: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_3:
    // 0x80069028: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8006902C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80069030: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
    // 0x80069034: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80069038: nop

    // 0x8006903C: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80069040: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80069044: nop

    // 0x80069048: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x8006904C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x80069050: jal         0x800707F8
    // 0x80069054: nop

    coss_f(rdram, ctx);
        goto after_4;
    // 0x80069054: nop

    after_4:
    // 0x80069058: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x8006905C: jal         0x800707C4
    // 0x80069060: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_5;
    // 0x80069060: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x80069064: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80069068: jal         0x800707F8
    // 0x8006906C: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    coss_f(rdram, ctx);
        goto after_6;
    // 0x8006906C: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_6:
    // 0x80069070: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80069074: jal         0x800707C4
    // 0x80069078: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_7;
    // 0x80069078: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_7:
    // 0x8006907C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80069080: jal         0x800707F8
    // 0x80069084: swc1        $f0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_8;
    // 0x80069084: swc1        $f0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80069088: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8006908C: jal         0x800707C4
    // 0x80069090: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    sins_f(rdram, ctx);
        goto after_9;
    // 0x80069090: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80069094: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069098: lwc1        $f16, 0x138($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8006909C: swc1        $f6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f6.u32l;
    // 0x800690A0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800690A4: lwc1        $f14, 0x100($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800690A8: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x800690AC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800690B0: lwc1        $f12, 0xFC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800690B4: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    // 0x800690B8: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800690BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800690C0: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800690C4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800690C8: addiu       $s0, $s0, 0x10A0
    ctx->r16 = ADD32(ctx->r16, 0X10A0);
    // 0x800690CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800690D0: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800690D4: addiu       $a1, $a1, 0xF20
    ctx->r5 = ADD32(ctx->r5, 0XF20);
    // 0x800690D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800690DC: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x800690E0: mul.s       $f6, $f20, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x800690E4: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x800690E8: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800690EC: nop

    // 0x800690F0: mul.s       $f10, $f26, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x800690F4: neg.s       $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = -ctx->f24.fl;
    // 0x800690F8: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x800690FC: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80069100: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069104: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80069108: mul.s       $f6, $f28, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8006910C: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80069110: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x80069114: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80069118: nop

    // 0x8006911C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80069120: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80069124: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80069128: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006912C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80069130: nop

    // 0x80069134: mul.s       $f4, $f26, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x80069138: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x8006913C: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x80069140: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80069144: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x80069148: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8006914C: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80069150: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80069154: nop

    // 0x80069158: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8006915C: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80069160: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80069164: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80069168: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x8006916C: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80069170: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x80069174: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80069178: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x8006917C: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80069180: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80069184: nop

    // 0x80069188: mul.s       $f10, $f26, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f10.fl);
    // 0x8006918C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069190: mul.s       $f10, $f28, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f12.fl);
    // 0x80069194: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80069198: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8006919C: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800691A0: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x800691A4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800691A8: nop

    // 0x800691AC: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800691B0: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800691B4: nop

    // 0x800691B8: mul.s       $f10, $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800691BC: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800691C0: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800691C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800691C8: nop

    // 0x800691CC: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x800691D0: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x800691D4: neg.s       $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = -ctx->f26.fl;
    // 0x800691D8: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x800691DC: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800691E0: nop

    // 0x800691E4: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800691E8: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800691EC: nop

    // 0x800691F0: mul.s       $f10, $f20, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x800691F4: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800691F8: mul.s       $f10, $f24, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x800691FC: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80069200: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80069204: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80069208: mul.s       $f4, $f22, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8006920C: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80069210: lwc1        $f4, 0x118($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80069214: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80069218: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006921C: nop

    // 0x80069220: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80069224: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80069228: nop

    // 0x8006922C: mul.s       $f10, $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x80069230: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80069234: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80069238: nop

    // 0x8006923C: mul.s       $f12, $f20, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80069240: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x80069244: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80069248: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8006924C: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80069250: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80069254: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80069258: add.s       $f26, $f10, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8006925C: lwc1        $f6, 0x118($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80069260: mul.s       $f10, $f12, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f30.fl);
    // 0x80069264: nop

    // 0x80069268: mul.s       $f6, $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x8006926C: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80069270: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80069274: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80069278: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x8006927C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80069280: nop

    // 0x80069284: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80069288: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8006928C: nop

    // 0x80069290: mul.s       $f6, $f20, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80069294: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80069298: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006929C: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800692A0: mul.s       $f6, $f24, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f10.fl);
    // 0x800692A4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800692A8: lwc1        $f20, 0x6C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800692AC: mul.s       $f10, $f22, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x800692B0: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800692B4: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800692B8: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x800692BC: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800692C0: nop

    // 0x800692C4: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800692C8: nop

    // 0x800692CC: mul.s       $f6, $f14, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x800692D0: lwc1        $f14, 0x118($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800692D4: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800692D8: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800692DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800692E0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x800692E4: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x800692E8: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x800692EC: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800692F0: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800692F4: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800692F8: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800692FC: nop

    // 0x80069300: mul.s       $f10, $f30, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f10.fl);
    // 0x80069304: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069308: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8006930C: nop

    // 0x80069310: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80069314: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x80069318: mul.s       $f10, $f30, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f26.fl);
    // 0x8006931C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069320: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80069324: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    // 0x80069328: mul.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8006932C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80069330: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80069334: mul.s       $f10, $f30, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f10.fl);
    // 0x80069338: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8006933C: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80069340: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80069344: lwc1        $f2, 0xEC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80069348: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x8006934C: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x80069350: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80069354: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80069358: nop

    // 0x8006935C: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80069360: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80069364: nop

    // 0x80069368: mul.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8006936C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069370: lwc1        $f10, 0xEC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80069374: nop

    // 0x80069378: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8006937C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069380: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80069384: nop

    // 0x80069388: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8006938C: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80069390: swc1        $f10, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f10.u32l;
    // 0x80069394: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80069398: nop

    // 0x8006939C: mul.s       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800693A0: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800693A4: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800693A8: lwc1        $f4, 0xE4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800693AC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800693B0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800693B4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800693B8: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800693BC: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800693C0: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    // 0x800693C4: mul.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800693C8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800693CC: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800693D0: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800693D4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800693D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800693DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800693E0: swc1        $f10, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f10.u32l;
    // 0x800693E4: jal         0x8006F768
    // 0x800693E8: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    mtxf_mul(rdram, ctx);
        goto after_10;
    // 0x800693E8: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x800693EC: lw          $t3, 0x12C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X12C);
    // 0x800693F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800693F4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800693F8: jal         0x8006F870
    // 0x800693FC: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_11;
    // 0x800693FC: nop

    after_11:
    // 0x80069400: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x80069404: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x80069408: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006940C: lui         $t5, 0x140
    ctx->r13 = S32(0X140 << 16);
    // 0x80069410: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80069414: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x80069418: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8006941C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80069420: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80069424: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069428: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x8006942C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80069430: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80069434: nop

    // 0x80069438: addiu       $t9, $t8, 0x40
    ctx->r25 = ADD32(ctx->r24, 0X40);
    // 0x8006943C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80069440: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80069444: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80069448: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8006944C: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80069450: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80069454: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80069458: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8006945C: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80069460: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80069464: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80069468: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8006946C: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80069470: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80069474: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80069478: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8006947C: jr          $ra
    // 0x80069480: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x80069480: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void leveltable_vehicle_usable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; if (dkr_legacy_track_menu(rdram, ctx, 11U, dkr_legacy_fields, 0U)) return; }
    // 0x8006B0F8: blez        $a0, L_8006B140
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006B0FC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B140;
    }
    // 0x8006B0FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B100: lw          $t6, 0x1170($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1170);
    // 0x8006B104: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B108: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B10C: beq         $at, $zero, L_8006B140
    if (ctx->r1 == 0) {
        // 0x8006B110: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B140;
    }
    // 0x8006B110: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B114: lw          $t7, 0x117C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X117C);
    // 0x8006B118: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B11C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B120: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B124: lb          $v1, 0x2($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X2);
    // 0x8006B128: nop

    // 0x8006B12C: beq         $v1, $zero, L_8006B140
    if (ctx->r3 == 0) {
        // 0x8006B130: sra         $v0, $v1, 4
        ctx->r2 = S32(SIGNED(ctx->r3) >> 4);
            goto L_8006B140;
    }
    // 0x8006B130: sra         $v0, $v1, 4
    ctx->r2 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8006B134: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x8006B138: jr          $ra
    // 0x8006B13C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8006B13C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006B140:
    // 0x8006B140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B144: jr          $ra
    // 0x8006B148: nop

    return;
    // 0x8006B148: nop

;}
RECOMP_FUNC void menu_game_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C508: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C50C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008C510: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x8008C514: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C518: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008C51C: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x8008C520: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008C524: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C528: addiu       $s4, $s4, 0x63E0
    ctx->r20 = ADD32(ctx->r20, 0X63E0);
    // 0x8008C52C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008C530: sw          $zero, -0xBA0($at)
    MEM_W(-0XBA0, ctx->r1) = 0;
    // 0x8008C534: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8008C538: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C53C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008C540: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008C544: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008C548: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C54C: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8008C550: jal         0x800C01D8
    // 0x8008C554: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8008C554: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_0:
    // 0x8008C558: jal         0x8006EBA8
    // 0x8008C55C: nop

    mark_read_all_save_files(rdram, ctx);
        goto after_1;
    // 0x8008C55C: nop

    after_1:
    // 0x8008C560: jal         0x8001B790
    // 0x8008C564: nop

    set_ghost_none(rdram, ctx);
        goto after_2;
    // 0x8008C564: nop

    after_2:
    // 0x8008C568: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008C56C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C570: sw          $t7, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r15;
    // 0x8008C574: jal         0x8009C6D4
    // 0x8008C578: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    menu_asset_load(rdram, ctx);
        goto after_3;
    // 0x8008C578: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_3:
    // 0x8008C57C: jal         0x8007FFEC
    // 0x8008C580: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8007FFEC(rdram, ctx);
        goto after_4;
    // 0x8008C580: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x8008C584: jal         0x800C4170
    // 0x8008C588: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_5;
    // 0x8008C588: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8008C58C: jal         0x80000B34
    // 0x8008C590: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    music_play(rdram, ctx);
        goto after_6;
    // 0x8008C590: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_6:
    // 0x8008C594: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008C598: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008C59C: addiu       $s2, $s2, 0x63B4
    ctx->r18 = ADD32(ctx->r18, 0X63B4);
    // 0x8008C5A0: addiu       $s3, $s3, -0x24C
    ctx->r19 = ADD32(ctx->r19, -0X24C);
    // 0x8008C5A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8008C5A8:
    // 0x8008C5A8: lb          $t8, 0x0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X0);
    // 0x8008C5AC: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x8008C5B0: beq         $s0, $t8, L_8008C5D0
    if (ctx->r16 == ctx->r24) {
        // 0x8008C5B4: addu        $s1, $s3, $t9
        ctx->r17 = ADD32(ctx->r19, ctx->r25);
            goto L_8008C5D0;
    }
    // 0x8008C5B4: addu        $s1, $s3, $t9
    ctx->r17 = ADD32(ctx->r19, ctx->r25);
    // 0x8008C5B8: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8008C5BC: jal         0x80001114
    // 0x8008C5C0: nop

    music_channel_off(rdram, ctx);
        goto after_7;
    // 0x8008C5C0: nop

    after_7:
    // 0x8008C5C4: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8008C5C8: jal         0x80001114
    // 0x8008C5CC: nop

    music_channel_off(rdram, ctx);
        goto after_8;
    // 0x8008C5CC: nop

    after_8:
L_8008C5D0:
    // 0x8008C5D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008C5D4: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8008C5D8: bne         $at, $zero, L_8008C5A8
    if (ctx->r1 != 0) {
        // 0x8008C5DC: nop
    
            goto L_8008C5A8;
    }
    // 0x8008C5DC: nop

    // 0x8008C5E0: jal         0x80001114
    // 0x8008C5E4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_channel_off(rdram, ctx);
        goto after_9;
    // 0x8008C5E4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    extern void dkr_character_menu_music_mask(uint8_t*, recomp_context*); dkr_character_menu_music_mask(rdram, ctx);
    // 0x8008C5E8: jal         0x80000B18
    // 0x8008C5EC: nop

    music_change_off(rdram, ctx);
        goto after_10;
    // 0x8008C5EC: nop

    after_10:
    // 0x8008C5F0: jal         0x8009EC60
    // 0x8008C5F4: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_11;
    // 0x8008C5F4: nop

    after_11:
    // 0x8008C5F8: beq         $v0, $zero, L_8008C620
    if (ctx->r2 == 0) {
        // 0x8008C5FC: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8008C620;
    }
    // 0x8008C5FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C600: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C604: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008C608: addiu       $v1, $v1, 0x6460
    ctx->r3 = ADD32(ctx->r3, 0X6460);
    // 0x8008C60C: addiu       $t0, $t0, 0x278
    ctx->r8 = ADD32(ctx->r8, 0X278);
    // 0x8008C610: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8008C614: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8008C618: b           L_8008C638
    // 0x8008C61C: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
        goto L_8008C638;
    // 0x8008C61C: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
L_8008C620:
    // 0x8008C620: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008C624: addiu       $v1, $v1, 0x6460
    ctx->r3 = ADD32(ctx->r3, 0X6460);
    // 0x8008C628: addiu       $t2, $t2, 0x198
    ctx->r10 = ADD32(ctx->r10, 0X198);
    // 0x8008C62C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008C630: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8008C634: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
L_8008C638:
    // 0x8008C638: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8008C63C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008C640: bltz        $t4, L_8008C678
    if (SIGNED(ctx->r12) < 0) {
        // 0x8008C644: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8008C678;
    }
    // 0x8008C644: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008C648: addiu       $v0, $v0, 0x6550
    ctx->r2 = ADD32(ctx->r2, 0X6550);
L_8008C64C:
    // 0x8008C64C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008C650: or          $t7, $s0, $zero
    ctx->r15 = ctx->r16 | 0;
    // 0x8008C654: lw          $t5, 0x10C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10C);
    // 0x8008C658: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8008C65C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8008C660: sw          $t5, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->r13;
    // 0x8008C664: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x8008C668: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008C66C: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8008C670: beq         $at, $zero, L_8008C64C
    if (ctx->r1 == 0) {
        // 0x8008C674: nop
    
            goto L_8008C64C;
    }
    // 0x8008C674: nop

L_8008C678:
    // 0x8008C678: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008C67C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C680: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C684: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008C688: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008C68C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008C690: jr          $ra
    // 0x8008C694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008C694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void catmull_rom_interpolation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022540: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80022544: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80022548: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8002254C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80022550: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80022554: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80022558: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002255C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022560: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80022564: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80022568: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002256C: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x80022570: mul.d       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f14.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x80022574: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80022578: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8002257C: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x80022580: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80022584: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80022588: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002258C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80022590: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80022594: lui         $at, 0xBFF8
    ctx->r1 = S32(0XBFF8 << 16);
    // 0x80022598: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8002259C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800225A0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800225A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800225A8: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800225AC: add.d       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f14.d + ctx->f8.d;
    // 0x800225B0: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x800225B4: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x800225B8: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x800225BC: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x800225C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800225C4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800225C8: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800225CC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x800225D0: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800225D4: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x800225D8: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x800225DC: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x800225E0: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x800225E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800225E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800225EC: nop

    // 0x800225F0: mul.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800225F4: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x800225F8: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x800225FC: mul.d       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80022600: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80022604: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x80022608: add.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f8.d + ctx->f14.d;
    // 0x8002260C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80022610: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80022614: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x80022618: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002261C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80022620: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80022624: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80022628: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002262C: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80022630: add.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80022634: jr          $ra
    // 0x80022638: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80022638: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void alCSPSetTempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C79E4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800C79E8: and         $t9, $a1, $at
    ctx->r25 = ctx->r5 & ctx->r1;
    // 0x800C79EC: andi        $t2, $a1, 0xFF00
    ctx->r10 = ctx->r5 & 0XFF00;
    // 0x800C79F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C79F4: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x800C79F8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800C79FC: addiu       $t8, $zero, 0x51
    ctx->r24 = ADD32(0, 0X51);
    // 0x800C7A00: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800C7A04: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800C7A08: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
    // 0x800C7A0C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7A10: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x800C7A14: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x800C7A18: sb          $t1, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r9;
    // 0x800C7A1C: sb          $t3, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r11;
    // 0x800C7A20: sb          $t4, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r12;
    // 0x800C7A24: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7A28: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C7A2C: jal         0x800C91AC
    // 0x800C7A30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7A30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C7A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7A38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7A3C: jr          $ra
    // 0x800C7A40: nop

    return;
    // 0x800C7A40: nop

;}
RECOMP_FUNC void calc_dynamic_lighting_for_object_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024744: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80024748: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x8002474C: sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // 0x80024750: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x80024754: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x80024758: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x8002475C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80024760: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x80024764: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80024768: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8002476C: beq         $t9, $zero, L_800249BC
    if (ctx->r25 == 0) {
        // 0x80024770: or          $s3, $a3, $zero
        ctx->r19 = ctx->r7 | 0;
            goto L_800249BC;
    }
    // 0x80024770: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80024774: lh          $t0, 0x1C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X1C);
    // 0x80024778: lh          $t1, 0x1E($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X1E);
    // 0x8002477C: lh          $t2, 0x20($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X20);
    // 0x80024780: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80024784: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80024788: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002478C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80024790: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80024794: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80024798: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002479C: addiu       $t8, $sp, 0x10
    ctx->r24 = ADD32(ctx->r29, 0X10);
    // 0x800247A0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800247A4: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800247A8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800247AC: swc1        $f6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f6.u32l;
    // 0x800247B0: beq         $a2, $zero, L_800247D0
    if (ctx->r6 == 0) {
        // 0x800247B4: swc1        $f8, 0x8($t8)
        MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
            goto L_800247D0;
    }
    // 0x800247B4: swc1        $f8, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
    // 0x800247B8: jal         0x80069DA4
    // 0x800247BC: nop

    get_projection_matrix_f32(rdram, ctx);
        goto after_0;
    // 0x800247BC: nop

    after_0:
    // 0x800247C0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800247C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800247C8: jal         0x8006F6EC
    // 0x800247CC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_1;
    // 0x800247CC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_1:
L_800247D0:
    // 0x800247D0: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x800247D4: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x800247D8: addiu       $v1, $zero, 0x0
    ctx->r3 = ADD32(0, 0X0);
    // 0x800247DC: sub         $t0, $zero, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800247E0: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x800247E4: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x800247E8: lui         $v0, 0x3F80
    ctx->r2 = S32(0X3F80 << 16);
    // 0x800247EC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800247F0: sub         $t1, $zero, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x800247F4: sh          $t1, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r9;
    // 0x800247F8: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x800247FC: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
    // 0x80024800: sw          $v1, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r3;
    // 0x80024804: sub         $t2, $zero, $t2
    ctx->r10 = SUB32(0, ctx->r10);
    // 0x80024808: sh          $t2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r10;
    // 0x8002480C: sw          $v1, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r3;
    // 0x80024810: sw          $v1, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r3;
    // 0x80024814: jal         0x8006FE74
    // 0x80024818: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_2;
    // 0x80024818: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_2:
    // 0x8002481C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80024820: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80024824: jal         0x8006F6EC
    // 0x80024828: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_3;
    // 0x80024828: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_3:
    // 0x8002482C: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x80024830: mtc1        $s3, $f6
    ctx->f6.u32l = ctx->r19;
    // 0x80024834: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80024838: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8002483C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80024840: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x80024844: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80024848: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x8002484C: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x80024850: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80024854: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80024858: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8002485C: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x80024860: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x80024864: lh          $t0, 0x28($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X28);
    // 0x80024868: lw          $t5, 0x38($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X38);
    // 0x8002486C: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80024870: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80024874: lw          $s3, 0x44($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X44);
    // 0x80024878: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x8002487C: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80024880: nop

    // 0x80024884: mul.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80024888: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8002488C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80024890: nop

    // 0x80024894: ori         $v1, $v0, 0x3
    ctx->r3 = ctx->r2 | 0X3;
    // 0x80024898: xori        $v1, $v1, 0x2
    ctx->r3 = ctx->r3 ^ 0X2;
    // 0x8002489C: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x800248A0: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x800248A4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800248A8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800248AC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800248B0: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800248B4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800248B8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800248BC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800248C0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800248C4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800248C8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800248CC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800248D0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800248D4: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x800248D8: add         $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x800248DC: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800248E0: add         $s2, $s2, $t5
    ctx->r18 = ADD32(ctx->r18, ctx->r13);
    // 0x800248E4: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
L_800248E8:
    // 0x800248E8: lh          $v0, 0x2($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X2);
    // 0x800248EC: lh          $v1, 0xE($t5)
    ctx->r3 = MEM_H(ctx->r13, 0XE);
    // 0x800248F0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800248F4: bne         $t0, $at, L_80024928
    if (ctx->r8 != ctx->r1) {
        // 0x800248F8: sub         $t4, $v1, $v0
        ctx->r12 = SUB32(ctx->r3, ctx->r2);
            goto L_80024928;
    }
    // 0x800248F8: sub         $t4, $v1, $v0
    ctx->r12 = SUB32(ctx->r3, ctx->r2);
    // 0x800248FC: lw          $t1, 0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X8);
    // 0x80024900: sll         $v0, $t4, 3
    ctx->r2 = S32(ctx->r12 << 3);
    // 0x80024904: sll         $v1, $t4, 1
    ctx->r3 = S32(ctx->r12 << 1);
    // 0x80024908: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002490C: andi        $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 & 0X8000;
    // 0x80024910: beq         $t1, $zero, L_800249AC
    if (ctx->r9 == 0) {
        // 0x80024914: add         $s3, $s3, $v0
        ctx->r19 = ADD32(ctx->r19, ctx->r2);
            goto L_800249AC;
    }
    // 0x80024914: add         $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80024918: sll         $v0, $t4, 2
    ctx->r2 = S32(ctx->r12 << 2);
    // 0x8002491C: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024920: b           L_800249AC
    // 0x80024924: add         $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_800249AC;
    // 0x80024924: add         $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80024928:
    // 0x80024928: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8002492C: mult        $t0, $a2
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024930: mflo        $a1
    ctx->r5 = lo;
    // 0x80024934: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x80024938: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8002493C: mult        $t1, $a3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024940: mflo        $v0
    ctx->r2 = lo;
    // 0x80024944: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x80024948: add         $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8002494C: mult        $t2, $t6
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024950: mflo        $v0
    ctx->r2 = lo;
    // 0x80024954: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80024958: add         $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8002495C: sra         $a1, $a1, 7
    ctx->r5 = S32(SIGNED(ctx->r5) >> 7);
    // 0x80024960: bgtz        $a1, L_80024970
    if (SIGNED(ctx->r5) > 0) {
        // 0x80024964: nop
    
            goto L_80024970;
    }
    // 0x80024964: nop

    // 0x80024968: b           L_80024990
    // 0x8002496C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_80024990;
    // 0x8002496C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_80024970:
    // 0x80024970: mult        $a1, $t7
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024974: mflo        $a1
    ctx->r5 = lo;
    // 0x80024978: srl         $a1, $a1, 21
    ctx->r5 = S32(U32(ctx->r5) >> 21);
    // 0x8002497C: add         $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80024980: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80024984: bnel        $at, $zero, L_80024994
    if (ctx->r1 != 0) {
        // 0x80024988: sll         $v0, $a1, 8
        ctx->r2 = S32(ctx->r5 << 8);
            goto L_80024994;
    }
    goto skip_0;
    // 0x80024988: sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5 << 8);
    skip_0:
    // 0x8002498C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80024990:
    // 0x80024990: sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5 << 8);
L_80024994:
    // 0x80024994: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x80024998: sh          $a1, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r5;
    // 0x8002499C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800249A0: sh          $a1, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r5;
    // 0x800249A4: bne         $t4, $zero, L_80024928
    if (ctx->r12 != 0) {
        // 0x800249A8: addiu       $s3, $s3, 0xA
        ctx->r19 = ADD32(ctx->r19, 0XA);
            goto L_80024928;
    }
    // 0x800249A8: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
L_800249AC:
    // 0x800249AC: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800249B0: slt         $at, $t5, $s2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800249B4: bnel        $at, $zero, L_800248E8
    if (ctx->r1 != 0) {
        // 0x800249B8: lbu         $t0, 0x6($t5)
        ctx->r8 = MEM_BU(ctx->r13, 0X6);
            goto L_800248E8;
    }
    goto skip_1;
    // 0x800249B8: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
    skip_1:
L_800249BC:
    // 0x800249BC: lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X78);
    // 0x800249C0: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x800249C4: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x800249C8: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x800249CC: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x800249D0: jr          $ra
    // 0x800249D4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800249D4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x800249D8: nop

;}
RECOMP_FUNC void func_8002FA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FA64: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8002FA68: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002FA6C: lw          $v1, -0x3DD0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3DD0);
    // 0x8002FA70: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002FA74: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8002FA78: sw          $s7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r23;
    // 0x8002FA7C: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x8002FA80: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x8002FA84: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8002FA88: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x8002FA8C: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x8002FA90: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8002FA94: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8002FA98: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002FA9C: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x8002FAA0: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002FAA4: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8002FAA8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002FAAC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002FAB0: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002FAB4: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8002FAB8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002FABC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002FAC0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002FAC4: blez        $v1, L_8002FD08
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002FAC8: swc1        $f20, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
            goto L_8002FD08;
    }
    // 0x8002FAC8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002FACC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002FAD0: lw          $t6, -0x2F14($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2F14);
    // 0x8002FAD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002FAD8: beq         $t6, $zero, L_8002FB14
    if (ctx->r14 == 0) {
        // 0x8002FADC: nop
    
            goto L_8002FB14;
    }
    // 0x8002FADC: nop

    // 0x8002FAE0: lw          $v0, -0x2F18($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2F18);
    // 0x8002FAE4: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8002FAE8: blez        $v0, L_8002FCDC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002FAEC: addiu       $s6, $s6, -0x377C
        ctx->r22 = ADD32(ctx->r22, -0X377C);
            goto L_8002FCDC;
    }
    // 0x8002FAEC: addiu       $s6, $s6, -0x377C
    ctx->r22 = ADD32(ctx->r22, -0X377C);
    // 0x8002FAF0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8002FAF4: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x8002FAF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002FAFC: lwc1        $f6, -0x2F1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F1C);
    // 0x8002FB00: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002FB04: nop

    // 0x8002FB08: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002FB0C: b           L_8002FCDC
    // 0x8002FB10: nop

        goto L_8002FCDC;
    // 0x8002FB10: nop

L_8002FB14:
    // 0x8002FB14: blez        $v1, L_8002FCDC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002FB18: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8002FCDC;
    }
    // 0x8002FB18: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002FB1C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002FB20: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8002FB24: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002FB28: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002FB2C: addiu       $s4, $s4, -0x4CD0
    ctx->r20 = ADD32(ctx->r20, -0X4CD0);
    // 0x8002FB30: addiu       $s5, $s5, -0x4EE0
    ctx->r21 = ADD32(ctx->r21, -0X4EE0);
    // 0x8002FB34: addiu       $s6, $s6, -0x377C
    ctx->r22 = ADD32(ctx->r22, -0X377C);
    // 0x8002FB38: addiu       $s3, $s3, -0x3DC8
    ctx->r19 = ADD32(ctx->r19, -0X3DC8);
L_8002FB3C:
    // 0x8002FB3C: lh          $t9, 0xA($s3)
    ctx->r25 = MEM_H(ctx->r19, 0XA);
    // 0x8002FB40: nop

    // 0x8002FB44: blez        $t9, L_8002FCCC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002FB48: nop
    
            goto L_8002FCCC;
    }
    // 0x8002FB48: nop

    // 0x8002FB4C: lbu         $s1, 0x1($s3)
    ctx->r17 = MEM_BU(ctx->r19, 0X1);
    // 0x8002FB50: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x8002FB54: andi        $t0, $s1, 0x1
    ctx->r8 = ctx->r17 & 0X1;
    // 0x8002FB58: beq         $t0, $zero, L_8002FB80
    if (ctx->r8 == 0) {
        // 0x8002FB5C: nop
    
            goto L_8002FB80;
    }
    // 0x8002FB5C: nop

    // 0x8002FB60: lbu         $t1, 0x2($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X2);
    // 0x8002FB64: nop

    // 0x8002FB68: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8002FB6C: addu        $v0, $s4, $t2
    ctx->r2 = ADD32(ctx->r20, ctx->r10);
    // 0x8002FB70: lwc1        $f28, 0x0($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FB74: lwc1        $f30, 0x8($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FB78: b           L_8002FBA0
    // 0x8002FB7C: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
        goto L_8002FBA0;
    // 0x8002FB7C: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
L_8002FB80:
    // 0x8002FB80: lbu         $t3, 0x2($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X2);
    // 0x8002FB84: nop

    // 0x8002FB88: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8002FB8C: addu        $v0, $s5, $t4
    ctx->r2 = ADD32(ctx->r21, ctx->r12);
    // 0x8002FB90: lwc1        $f28, 0x0($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FB94: lwc1        $f30, 0x8($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FB98: nop

    // 0x8002FB9C: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
L_8002FBA0:
    // 0x8002FBA0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8002FBA4: beq         $t6, $zero, L_8002FBCC
    if (ctx->r14 == 0) {
        // 0x8002FBA8: or          $s1, $t5, $zero
        ctx->r17 = ctx->r13 | 0;
            goto L_8002FBCC;
    }
    // 0x8002FBA8: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x8002FBAC: lbu         $t7, 0x3($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X3);
    // 0x8002FBB0: nop

    // 0x8002FBB4: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8002FBB8: addu        $v0, $s4, $t8
    ctx->r2 = ADD32(ctx->r20, ctx->r24);
    // 0x8002FBBC: lwc1        $f24, 0x0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FBC0: lwc1        $f26, 0x8($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FBC4: b           L_8002FBEC
    // 0x8002FBC8: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
        goto L_8002FBEC;
    // 0x8002FBC8: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
L_8002FBCC:
    // 0x8002FBCC: lbu         $t9, 0x3($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X3);
    // 0x8002FBD0: nop

    // 0x8002FBD4: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8002FBD8: addu        $v0, $s5, $t0
    ctx->r2 = ADD32(ctx->r21, ctx->r8);
    // 0x8002FBDC: lwc1        $f24, 0x0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FBE0: lwc1        $f26, 0x8($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FBE4: nop

    // 0x8002FBE8: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
L_8002FBEC:
    // 0x8002FBEC: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8002FBF0: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8002FBF4: bne         $at, $zero, L_8002FCCC
    if (ctx->r1 != 0) {
        // 0x8002FBF8: or          $s1, $t1, $zero
        ctx->r17 = ctx->r9 | 0;
            goto L_8002FCCC;
    }
    // 0x8002FBF8: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8002FBFC: sll         $t3, $s7, 2
    ctx->r11 = S32(ctx->r23 << 2);
    // 0x8002FC00: subu        $t3, $t3, $s7
    ctx->r11 = SUB32(ctx->r11, ctx->r23);
    // 0x8002FC04: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002FC08: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002FC0C: addiu       $t5, $t5, -0x3DC8
    ctx->r13 = ADD32(ctx->r13, -0X3DC8);
    // 0x8002FC10: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8002FC14: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
L_8002FC18:
    // 0x8002FC18: andi        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 & 0X1;
    // 0x8002FC1C: beq         $t6, $zero, L_8002FC44
    if (ctx->r14 == 0) {
        // 0x8002FC20: nop
    
            goto L_8002FC44;
    }
    // 0x8002FC20: nop

    // 0x8002FC24: lbu         $t7, 0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2);
    // 0x8002FC28: nop

    // 0x8002FC2C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8002FC30: addu        $v0, $s4, $t8
    ctx->r2 = ADD32(ctx->r20, ctx->r24);
    // 0x8002FC34: lwc1        $f20, 0x0($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FC38: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FC3C: b           L_8002FC64
    // 0x8002FC40: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
        goto L_8002FC64;
    // 0x8002FC40: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
L_8002FC44:
    // 0x8002FC44: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x8002FC48: nop

    // 0x8002FC4C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8002FC50: addu        $v0, $s5, $t0
    ctx->r2 = ADD32(ctx->r21, ctx->r8);
    // 0x8002FC54: lwc1        $f20, 0x0($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FC58: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FC5C: nop

    // 0x8002FC60: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
L_8002FC64:
    // 0x8002FC64: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8002FC68: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8002FC6C: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8002FC70: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x8002FC74: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    // 0x8002FC78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8002FC7C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8002FC80: jal         0x80070A2C
    // 0x8002FC84: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    area_triangle_2d(rdram, ctx);
        goto after_0;
    // 0x8002FC84: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8002FC88: lh          $t2, 0xA($s3)
    ctx->r10 = MEM_H(ctx->r19, 0XA);
    // 0x8002FC8C: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x8002FC90: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8002FC94: addu        $t4, $s6, $t3
    ctx->r12 = ADD32(ctx->r22, ctx->r11);
    // 0x8002FC98: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8002FC9C: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002FCA0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8002FCA4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002FCA8: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002FCAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002FCB0: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x8002FCB4: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
    // 0x8002FCB8: bne         $at, $zero, L_8002FC18
    if (ctx->r1 != 0) {
        // 0x8002FCBC: add.s       $f2, $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
            goto L_8002FC18;
    }
    // 0x8002FCBC: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8002FCC0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002FCC4: lw          $v1, -0x3DD0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3DD0);
    // 0x8002FCC8: nop

L_8002FCCC:
    // 0x8002FCCC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002FCD0: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002FCD4: bne         $at, $zero, L_8002FB3C
    if (ctx->r1 != 0) {
        // 0x8002FCD8: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_8002FB3C;
    }
    // 0x8002FCD8: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_8002FCDC:
    // 0x8002FCDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002FCE0: lwc1        $f12, -0x2F1C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2F1C);
    // 0x8002FCE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002FCE8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8002FCEC: nop

    // 0x8002FCF0: bc1f        L_8002FD08
    if (!c1cs) {
        // 0x8002FCF4: nop
    
            goto L_8002FD08;
    }
    // 0x8002FCF4: nop

    // 0x8002FCF8: lwc1        $f16, 0x5F5C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5F5C);
    // 0x8002FCFC: nop

    // 0x8002FD00: mul.s       $f2, $f12, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8002FD04: nop

L_8002FD08:
    // 0x8002FD08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002FD0C: lwc1        $f12, -0x2F1C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2F1C);
    // 0x8002FD10: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8002FD14: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8002FD18: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002FD1C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002FD20: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002FD24: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002FD28: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002FD2C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002FD30: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002FD34: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002FD38: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002FD3C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002FD40: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002FD44: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002FD48: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8002FD4C: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8002FD50: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x8002FD54: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x8002FD58: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x8002FD5C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8002FD60: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x8002FD64: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x8002FD68: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8002FD6C: jr          $ra
    // 0x8002FD70: div.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    return;
    // 0x8002FD70: div.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
;}
RECOMP_FUNC void collision_get_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BAB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002BAB4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8002BAB8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8002BABC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8002BAC0: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8002BAC4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002BAC8: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x8002BACC: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8002BAD0: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8002BAD4: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8002BAD8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8002BADC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002BAE0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002BAE4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002BAE8: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002BAEC: bltz        $a0, L_8002BB14
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002BAF0: swc1        $f20, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
            goto L_8002BB14;
    }
    // 0x8002BAF0: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x8002BAF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002BAF8: lw          $v0, -0x36E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36E8);
    // 0x8002BAFC: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8002BB00: lh          $t6, 0x1A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1A);
    // 0x8002BB04: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8002BB08: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002BB0C: bne         $at, $zero, L_8002BB1C
    if (ctx->r1 != 0) {
        // 0x8002BB10: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8002BB1C;
    }
    // 0x8002BB10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
L_8002BB14:
    // 0x8002BB14: b           L_8002C08C
    // 0x8002BB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002C08C;
    // 0x8002BB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002BB1C:
    // 0x8002BB1C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002BB20: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8002BB24: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8002BB28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002BB2C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8002BB30: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x8002BB34: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002BB38: addu        $t4, $t7, $t8
    ctx->r12 = ADD32(ctx->r15, ctx->r24);
    // 0x8002BB3C: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x8002BB40: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x8002BB44: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002BB48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002BB4C: subu        $a2, $t7, $a3
    ctx->r6 = SUB32(ctx->r15, ctx->r7);
    // 0x8002BB50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002BB54: sra         $t8, $a2, 3
    ctx->r24 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002BB58: addiu       $a2, $t8, 0x1
    ctx->r6 = ADD32(ctx->r24, 0X1);
    // 0x8002BB5C: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x8002BB60: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x8002BB64: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BB68: addu        $t0, $a2, $a3
    ctx->r8 = ADD32(ctx->r6, ctx->r7);
    // 0x8002BB6C: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x8002BB70: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002BB74: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8002BB78: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002BB7C: mfc1        $s3, $f4
    ctx->r19 = (int32_t)ctx->f4.u32l;
    // 0x8002BB80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002BB84: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002BB88: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BB8C: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8002BB90: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8002BB94:
    // 0x8002BB94: slt         $at, $t0, $s3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8002BB98: bne         $at, $zero, L_8002BBB8
    if (ctx->r1 != 0) {
        // 0x8002BB9C: addu        $t0, $t0, $a2
        ctx->r8 = ADD32(ctx->r8, ctx->r6);
            goto L_8002BBB8;
    }
    // 0x8002BB9C: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BBA0: slt         $at, $s3, $t1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002BBA4: bne         $at, $zero, L_8002BBBC
    if (ctx->r1 != 0) {
        // 0x8002BBA8: sll         $t9, $t0, 16
        ctx->r25 = S32(ctx->r8 << 16);
            goto L_8002BBBC;
    }
    // 0x8002BBA8: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8002BBAC: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002BBB0: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8002BBB4: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
L_8002BBB8:
    // 0x8002BBB8: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
L_8002BBBC:
    // 0x8002BBBC: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BBC0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8002BBC4: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BBC8: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002BBCC: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8002BBD0: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x8002BBD4: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002BBD8: sra         $t1, $t7, 16
    ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BBDC: bne         $at, $zero, L_8002BB94
    if (ctx->r1 != 0) {
        // 0x8002BBE0: sra         $a1, $t6, 16
        ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8002BB94;
    }
    // 0x8002BBE0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BBE4: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x8002BBE8: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x8002BBEC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002BBF0: subu        $a2, $t8, $v0
    ctx->r6 = SUB32(ctx->r24, ctx->r2);
    // 0x8002BBF4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002BBF8: sra         $t9, $a2, 3
    ctx->r25 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002BBFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002BC00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002BC04: addiu       $a2, $t9, 0x1
    ctx->r6 = ADD32(ctx->r25, 0X1);
    // 0x8002BC08: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8002BC0C: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8002BC10: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BC14: addu        $t0, $a2, $v0
    ctx->r8 = ADD32(ctx->r6, ctx->r2);
    // 0x8002BC18: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x8002BC1C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002BC20: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x8002BC24: sra         $t6, $t1, 16
    ctx->r14 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002BC28: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x8002BC2C: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BC30: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8002BC34: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8002BC38: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8002BC3C:
    // 0x8002BC3C: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BC40: bne         $at, $zero, L_8002BC60
    if (ctx->r1 != 0) {
        // 0x8002BC44: addu        $t0, $t0, $a2
        ctx->r8 = ADD32(ctx->r8, ctx->r6);
            goto L_8002BC60;
    }
    // 0x8002BC44: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BC48: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002BC4C: bne         $at, $zero, L_8002BC64
    if (ctx->r1 != 0) {
        // 0x8002BC50: sll         $t6, $t0, 16
        ctx->r14 = S32(ctx->r8 << 16);
            goto L_8002BC64;
    }
    // 0x8002BC50: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x8002BC54: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002BC58: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x8002BC5C: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
L_8002BC60:
    // 0x8002BC60: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
L_8002BC64:
    // 0x8002BC64: sra         $t0, $t6, 16
    ctx->r8 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BC68: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BC6C: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8002BC70: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8002BC74: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BC78: sll         $t7, $t6, 17
    ctx->r15 = S32(ctx->r14 << 17);
    // 0x8002BC7C: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BC80: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BC84: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8002BC88: bne         $at, $zero, L_8002BCA8
    if (ctx->r1 != 0) {
        // 0x8002BC8C: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8002BCA8;
    }
    // 0x8002BC8C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8002BC90: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002BC94: bne         $at, $zero, L_8002BCA8
    if (ctx->r1 != 0) {
        // 0x8002BC98: nop
    
            goto L_8002BCA8;
    }
    // 0x8002BC98: nop

    // 0x8002BC9C: or          $s1, $s1, $t8
    ctx->r17 = ctx->r17 | ctx->r24;
    // 0x8002BCA0: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8002BCA4: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_8002BCA8:
    // 0x8002BCA8: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BCAC: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8002BCB0: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BCB4: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BCB8: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8002BCBC: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002BCC0: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002BCC4: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BCC8: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BCCC: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BCD0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8002BCD4: bne         $at, $zero, L_8002BCF4
    if (ctx->r1 != 0) {
        // 0x8002BCD8: or          $t1, $t6, $zero
        ctx->r9 = ctx->r14 | 0;
            goto L_8002BCF4;
    }
    // 0x8002BCD8: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8002BCDC: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002BCE0: bne         $at, $zero, L_8002BCF4
    if (ctx->r1 != 0) {
        // 0x8002BCE4: nop
    
            goto L_8002BCF4;
    }
    // 0x8002BCE4: nop

    // 0x8002BCE8: or          $s1, $s1, $t9
    ctx->r17 = ctx->r17 | ctx->r25;
    // 0x8002BCEC: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8002BCF0: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
L_8002BCF4:
    // 0x8002BCF4: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BCF8: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x8002BCFC: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BD00: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BD04: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x8002BD08: or          $t8, $a1, $zero
    ctx->r24 = ctx->r5 | 0;
    // 0x8002BD0C: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x8002BD10: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BD14: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BD18: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BD1C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8002BD20: bne         $at, $zero, L_8002BD40
    if (ctx->r1 != 0) {
        // 0x8002BD24: or          $t1, $t7, $zero
        ctx->r9 = ctx->r15 | 0;
            goto L_8002BD40;
    }
    // 0x8002BD24: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x8002BD28: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002BD2C: bne         $at, $zero, L_8002BD40
    if (ctx->r1 != 0) {
        // 0x8002BD30: nop
    
            goto L_8002BD40;
    }
    // 0x8002BD30: nop

    // 0x8002BD34: or          $s1, $s1, $t6
    ctx->r17 = ctx->r17 | ctx->r14;
    // 0x8002BD38: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8002BD3C: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
L_8002BD40:
    // 0x8002BD40: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BD44: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8002BD48: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BD4C: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002BD50: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BD54: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x8002BD58: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002BD5C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8002BD60: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BD64: bne         $t2, $v0, L_8002BC3C
    if (ctx->r10 != ctx->r2) {
        // 0x8002BD68: sra         $t1, $t7, 16
        ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
            goto L_8002BC3C;
    }
    // 0x8002BD68: sra         $t1, $t7, 16
    ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BD6C: lh          $v0, 0x20($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X20);
    // 0x8002BD70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002BD74: blez        $v0, L_8002BF68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002BD78: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8002BF68;
    }
    // 0x8002BD78: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8002BD7C: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x8002BD80: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002BD84: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8002BD88: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
L_8002BD8C:
    // 0x8002BD8C: lw          $t8, 0xC($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC);
    // 0x8002BD90: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8002BD94: addu        $a0, $t8, $s6
    ctx->r4 = ADD32(ctx->r24, ctx->r22);
    // 0x8002BD98: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x8002BD9C: lh          $t5, 0x10($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X10);
    // 0x8002BDA0: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x8002BDA4: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002BDA8: beq         $at, $zero, L_8002BF5C
    if (ctx->r1 == 0) {
        // 0x8002BDAC: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8002BF5C;
    }
    // 0x8002BDAC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8002BDB0: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
L_8002BDB4:
    // 0x8002BDB4: lw          $t9, 0x10($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X10);
    // 0x8002BDB8: nop

    // 0x8002BDBC: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8002BDC0: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8002BDC4: nop

    // 0x8002BDC8: and         $t8, $t7, $s1
    ctx->r24 = ctx->r15 & ctx->r17;
    // 0x8002BDCC: bne         $s1, $t8, L_8002BF44
    if (ctx->r17 != ctx->r24) {
        // 0x8002BDD0: nop
    
            goto L_8002BF44;
    }
    // 0x8002BDD0: nop

    // 0x8002BDD4: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8002BDD8: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x8002BDDC: addu        $fp, $t9, $t6
    ctx->r30 = ADD32(ctx->r25, ctx->r14);
    // 0x8002BDE0: lbu         $t7, 0x1($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1);
    // 0x8002BDE4: lbu         $t6, 0x2($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0X2);
    // 0x8002BDE8: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x8002BDEC: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BDF0: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x8002BDF4: lw          $ra, 0x0($t4)
    ctx->r31 = MEM_W(ctx->r12, 0X0);
    // 0x8002BDF8: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BDFC: addu        $s7, $t9, $ra
    ctx->r23 = ADD32(ctx->r25, ctx->r31);
    // 0x8002BE00: lbu         $t9, 0x3($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0X3);
    // 0x8002BE04: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE08: addu        $t6, $t9, $t1
    ctx->r14 = ADD32(ctx->r25, ctx->r9);
    // 0x8002BE0C: lh          $v0, 0x0($s7)
    ctx->r2 = MEM_H(ctx->r23, 0X0);
    // 0x8002BE10: lh          $v1, 0x4($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X4);
    // 0x8002BE14: nop

    // 0x8002BE18: subu        $fp, $s0, $v1
    ctx->r30 = SUB32(ctx->r16, ctx->r3);
    // 0x8002BE1C: mflo        $t8
    ctx->r24 = lo;
    // 0x8002BE20: addu        $s7, $t8, $ra
    ctx->r23 = ADD32(ctx->r24, ctx->r31);
    // 0x8002BE24: lh          $a0, 0x0($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X0);
    // 0x8002BE28: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE2C: lh          $a1, 0x4($s7)
    ctx->r5 = MEM_H(ctx->r23, 0X4);
    // 0x8002BE30: subu        $t6, $a0, $v0
    ctx->r14 = SUB32(ctx->r4, ctx->r2);
    // 0x8002BE34: subu        $t8, $a1, $v1
    ctx->r24 = SUB32(ctx->r5, ctx->r3);
    // 0x8002BE38: mflo        $t7
    ctx->r15 = lo;
    // 0x8002BE3C: addu        $s7, $t7, $ra
    ctx->r23 = ADD32(ctx->r15, ctx->r31);
    // 0x8002BE40: lh          $a3, 0x0($s7)
    ctx->r7 = MEM_H(ctx->r23, 0X0);
    // 0x8002BE44: lh          $t0, 0x4($s7)
    ctx->r8 = MEM_H(ctx->r23, 0X4);
    // 0x8002BE48: subu        $s7, $s3, $v0
    ctx->r23 = SUB32(ctx->r19, ctx->r2);
    // 0x8002BE4C: multu       $s7, $t8
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE50: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BE54: nop

    // 0x8002BE58: nop

    // 0x8002BE5C: multu       $t6, $fp
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE60: subu        $t6, $s3, $a0
    ctx->r14 = SUB32(ctx->r19, ctx->r4);
    // 0x8002BE64: mflo        $t7
    ctx->r15 = lo;
    // 0x8002BE68: subu        $ra, $t9, $t7
    ctx->r31 = SUB32(ctx->r25, ctx->r15);
    // 0x8002BE6C: subu        $t9, $t0, $a1
    ctx->r25 = SUB32(ctx->r8, ctx->r5);
    // 0x8002BE70: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE74: slti        $t8, $ra, 0x0
    ctx->r24 = SIGNED(ctx->r31) < 0X0 ? 1 : 0;
    // 0x8002BE78: xori        $ra, $t8, 0x1
    ctx->r31 = ctx->r24 ^ 0X1;
    // 0x8002BE7C: subu        $t6, $s0, $a1
    ctx->r14 = SUB32(ctx->r16, ctx->r5);
    // 0x8002BE80: subu        $t8, $a3, $a0
    ctx->r24 = SUB32(ctx->r7, ctx->r4);
    // 0x8002BE84: mflo        $t7
    ctx->r15 = lo;
    // 0x8002BE88: nop

    // 0x8002BE8C: nop

    // 0x8002BE90: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE94: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BE98: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x8002BE9C: slti        $t6, $t8, 0x0
    ctx->r14 = SIGNED(ctx->r24) < 0X0 ? 1 : 0;
    // 0x8002BEA0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8002BEA4: bne         $t6, $ra, L_8002BF44
    if (ctx->r14 != ctx->r31) {
        // 0x8002BEA8: subu        $t7, $t0, $v1
        ctx->r15 = SUB32(ctx->r8, ctx->r3);
            goto L_8002BF44;
    }
    // 0x8002BEA8: subu        $t7, $t0, $v1
    ctx->r15 = SUB32(ctx->r8, ctx->r3);
    // 0x8002BEAC: multu       $s7, $t7
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BEB0: subu        $t8, $a3, $v0
    ctx->r24 = SUB32(ctx->r7, ctx->r2);
    // 0x8002BEB4: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BEB8: nop

    // 0x8002BEBC: nop

    // 0x8002BEC0: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BEC4: mflo        $t6
    ctx->r14 = lo;
    // 0x8002BEC8: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8002BECC: slti        $t8, $t7, 0x0
    ctx->r24 = SIGNED(ctx->r15) < 0X0 ? 1 : 0;
    // 0x8002BED0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8002BED4: beq         $ra, $t8, L_8002BF44
    if (ctx->r31 == ctx->r24) {
        // 0x8002BED8: nop
    
            goto L_8002BF44;
    }
    // 0x8002BED8: nop

    // 0x8002BEDC: lw          $t9, 0x14($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X14);
    // 0x8002BEE0: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x8002BEE4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002BEE8: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x8002BEEC: lw          $t8, 0x18($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X18);
    // 0x8002BEF0: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8002BEF4: addu        $v1, $t8, $t6
    ctx->r3 = ADD32(ctx->r24, ctx->r14);
    // 0x8002BEF8: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002BEFC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002BF00: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8002BF04: c.eq.d      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.d == ctx->f8.d;
    // 0x8002BF08: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002BF0C: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002BF10: bc1t        L_8002BF44
    if (c1cs) {
        // 0x8002BF14: nop
    
            goto L_8002BF44;
    }
    // 0x8002BF14: nop

    // 0x8002BF18: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8002BF1C: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8002BF20: addu        $t9, $s4, $t7
    ctx->r25 = ADD32(ctx->r20, ctx->r15);
    // 0x8002BF24: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002BF28: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8002BF2C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8002BF30: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8002BF34: nop

    // 0x8002BF38: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8002BF3C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8002BF40: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
L_8002BF44:
    // 0x8002BF44: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002BF48: slt         $at, $a2, $t5
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002BF4C: bne         $at, $zero, L_8002BDB4
    if (ctx->r1 != 0) {
        // 0x8002BF50: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_8002BDB4;
    }
    // 0x8002BF50: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x8002BF54: lh          $v0, 0x20($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X20);
    // 0x8002BF58: nop

L_8002BF5C:
    // 0x8002BF5C: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002BF60: bne         $at, $zero, L_8002BD8C
    if (ctx->r1 != 0) {
        // 0x8002BF64: addiu       $s6, $s6, 0xC
        ctx->r22 = ADD32(ctx->r22, 0XC);
            goto L_8002BD8C;
    }
    // 0x8002BF64: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
L_8002BF68:
    // 0x8002BF68: addiu       $a0, $s2, -0x1
    ctx->r4 = ADD32(ctx->r18, -0X1);
    // 0x8002BF6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002BF70:
    // 0x8002BF70: blez        $a0, L_8002C080
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8002BF74: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002C080;
    }
    // 0x8002BF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002BF78: addiu       $a3, $s2, -0x1
    ctx->r7 = ADD32(ctx->r18, -0X1);
    // 0x8002BF7C: andi        $t8, $a3, 0x3
    ctx->r24 = ctx->r7 & 0X3;
    // 0x8002BF80: beq         $t8, $zero, L_8002BFC4
    if (ctx->r24 == 0) {
        // 0x8002BF84: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8002BFC4;
    }
    // 0x8002BF84: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8002BF88: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8002BF8C: addu        $a1, $s4, $t6
    ctx->r5 = ADD32(ctx->r20, ctx->r14);
L_8002BF90:
    // 0x8002BF90: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8002BF94: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002BF98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002BF9C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002BFA0: nop

    // 0x8002BFA4: bc1f        L_8002BFB8
    if (!c1cs) {
        // 0x8002BFA8: nop
    
            goto L_8002BFB8;
    }
    // 0x8002BFA8: nop

    // 0x8002BFAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002BFB0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8002BFB4: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
L_8002BFB8:
    // 0x8002BFB8: bne         $a2, $v0, L_8002BF90
    if (ctx->r6 != ctx->r2) {
        // 0x8002BFBC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8002BF90;
    }
    // 0x8002BFBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002BFC0: beq         $v0, $a0, L_8002C080
    if (ctx->r2 == ctx->r4) {
        // 0x8002BFC4: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8002C080;
    }
L_8002BFC4:
    // 0x8002BFC4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8002BFC8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8002BFCC: addu        $a2, $t9, $s4
    ctx->r6 = ADD32(ctx->r25, ctx->r20);
    // 0x8002BFD0: addu        $a1, $s4, $t7
    ctx->r5 = ADD32(ctx->r20, ctx->r15);
L_8002BFD4:
    // 0x8002BFD4: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8002BFD8: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002BFDC: nop

    // 0x8002BFE0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002BFE4: nop

    // 0x8002BFE8: bc1f        L_8002C000
    if (!c1cs) {
        // 0x8002BFEC: nop
    
            goto L_8002C000;
    }
    // 0x8002BFEC: nop

    // 0x8002BFF0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8002BFF4: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x8002BFF8: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8002BFFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002C000:
    // 0x8002C000: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8002C004: nop

    // 0x8002C008: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002C00C: nop

    // 0x8002C010: bc1f        L_8002C028
    if (!c1cs) {
        // 0x8002C014: nop
    
            goto L_8002C028;
    }
    // 0x8002C014: nop

    // 0x8002C018: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x8002C01C: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8002C020: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8002C024: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002C028:
    // 0x8002C028: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8002C02C: nop

    // 0x8002C030: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002C034: nop

    // 0x8002C038: bc1f        L_8002C050
    if (!c1cs) {
        // 0x8002C03C: nop
    
            goto L_8002C050;
    }
    // 0x8002C03C: nop

    // 0x8002C040: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8002C044: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x8002C048: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8002C04C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002C050:
    // 0x8002C050: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002C054: nop

    // 0x8002C058: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002C05C: nop

    // 0x8002C060: bc1f        L_8002C074
    if (!c1cs) {
        // 0x8002C064: nop
    
            goto L_8002C074;
    }
    // 0x8002C064: nop

    // 0x8002C068: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002C06C: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x8002C070: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
L_8002C074:
    // 0x8002C074: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8002C078: bne         $a1, $a2, L_8002BFD4
    if (ctx->r5 != ctx->r6) {
        // 0x8002C07C: nop
    
            goto L_8002BFD4;
    }
    // 0x8002C07C: nop

L_8002C080:
    // 0x8002C080: beq         $v1, $zero, L_8002BF70
    if (ctx->r3 == 0) {
        // 0x8002C084: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002BF70;
    }
    // 0x8002C084: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002C088: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8002C08C:
    // 0x8002C08C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002C090: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x8002C094: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8002C098: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002C09C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002C0A0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8002C0A4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C0A8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8002C0AC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8002C0B0: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8002C0B4: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C0B8: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x8002C0BC: jr          $ra
    // 0x8002C0C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002C0C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void is_in_time_trial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E4DC: lbu         $v0, -0x510B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X510B);
    // 0x8000E4E0: jr          $ra
    // 0x8000E4E4: nop

    return;
    // 0x8000E4E4: nop

;}
RECOMP_FUNC void obj_init_stopwatchman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036194: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80036198: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003619C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800361A0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800361A4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x800361A8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x800361AC: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x800361B0: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x800361B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800361B8: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x800361BC: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x800361C0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800361C4: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x800361C8: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800361CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800361D0: sb          $t2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r10;
    // 0x800361D4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800361D8: jr          $ra
    // 0x800361DC: sw          $zero, -0x2B28($at)
    MEM_W(-0X2B28, ctx->r1) = 0;
    return;
    // 0x800361DC: sw          $zero, -0x2B28($at)
    MEM_W(-0X2B28, ctx->r1) = 0;
;}
RECOMP_FUNC void tex_load_sprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C12C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007C130: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007C134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C138: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007C13C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007C140: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8007C144: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8007C148: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007C14C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007C150: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007C154: bltz        $a0, L_8007C174
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007C158: sw          $a1, 0x635C($at)
        MEM_W(0X635C, ctx->r1) = ctx->r5;
            goto L_8007C174;
    }
    // 0x8007C158: sw          $a1, 0x635C($at)
    MEM_W(0X635C, ctx->r1) = ctx->r5;
    // 0x8007C15C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C160: lw          $t6, 0x6354($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6354);
    // 0x8007C164: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007C168: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007C16C: bne         $at, $zero, L_8007C17C
    if (ctx->r1 != 0) {
        // 0x8007C170: addiu       $t2, $t2, 0x6358
        ctx->r10 = ADD32(ctx->r10, 0X6358);
            goto L_8007C17C;
    }
    // 0x8007C170: addiu       $t2, $t2, 0x6358
    ctx->r10 = ADD32(ctx->r10, 0X6358);
L_8007C174:
    // 0x8007C174: b           L_8007C508
    // 0x8007C178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C508;
    // 0x8007C178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C17C:
    // 0x8007C17C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8007C180: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007C184: blez        $a0, L_8007C1D8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007C188: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8007C1D8;
    }
    // 0x8007C188: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8007C18C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C190: lw          $v0, 0x634C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X634C);
    // 0x8007C194: nop

    // 0x8007C198: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
L_8007C19C:
    // 0x8007C19C: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x8007C1A0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8007C1A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C1A8: bne         $s1, $t9, L_8007C1CC
    if (ctx->r17 != ctx->r25) {
        // 0x8007C1AC: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007C1CC;
    }
    // 0x8007C1AC: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007C1B0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8007C1B4: nop

    // 0x8007C1B8: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x8007C1BC: nop

    // 0x8007C1C0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007C1C4: b           L_8007C508
    // 0x8007C1C8: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
        goto L_8007C508;
    // 0x8007C1C8: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
L_8007C1CC:
    // 0x8007C1CC: bne         $at, $zero, L_8007C19C
    if (ctx->r1 != 0) {
        // 0x8007C1D0: sll         $t8, $s0, 3
        ctx->r24 = S32(ctx->r16 << 3);
            goto L_8007C19C;
    }
    // 0x8007C1D0: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x8007C1D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007C1D8:
    // 0x8007C1D8: blez        $a0, L_8007C218
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007C1DC: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8007C218;
    }
    // 0x8007C1DC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8007C1E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C1E4: lw          $v0, 0x634C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X634C);
    // 0x8007C1E8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007C1EC: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
L_8007C1F0:
    // 0x8007C1F0: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8007C1F4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007C1F8: nop

    // 0x8007C1FC: bne         $v1, $t8, L_8007C208
    if (ctx->r3 != ctx->r24) {
        // 0x8007C200: nop
    
            goto L_8007C208;
    }
    // 0x8007C200: nop

    // 0x8007C204: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_8007C208:
    // 0x8007C208: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C20C: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007C210: bne         $at, $zero, L_8007C1F0
    if (ctx->r1 != 0) {
        // 0x8007C214: sll         $t6, $s0, 3
        ctx->r14 = S32(ctx->r16 << 3);
            goto L_8007C1F0;
    }
    // 0x8007C214: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
L_8007C218:
    // 0x8007C218: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007C21C: bne         $t0, $v1, L_8007C234
    if (ctx->r8 != ctx->r3) {
        // 0x8007C220: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8007C234;
    }
    // 0x8007C220: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007C224: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x8007C228: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007C22C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8007C230: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_8007C234:
    // 0x8007C234: lw          $t3, 0x6348($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6348);
    // 0x8007C238: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8007C23C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8007C240: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007C244: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8007C248: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8007C24C: lw          $s4, 0x6350($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X6350);
    // 0x8007C250: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8007C254: sb          $t1, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r9;
    // 0x8007C258: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8007C25C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007C260: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    // 0x8007C264: jal         0x80076E68
    // 0x8007C268: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007C268: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8007C26C: lh          $a1, 0x2($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X2);
    // 0x8007C270: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007C274: addu        $t6, $s4, $a1
    ctx->r14 = ADD32(ctx->r20, ctx->r5);
    // 0x8007C278: lbu         $s5, 0xC($t6)
    ctx->r21 = MEM_BU(ctx->r14, 0XC);
    // 0x8007C27C: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8007C280: sll         $v1, $s5, 2
    ctx->r3 = S32(ctx->r21 << 2);
    // 0x8007C284: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8007C288: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8007C28C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8007C290: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8007C294: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8007C298: addu        $s0, $t9, $t3
    ctx->r16 = ADD32(ctx->r25, ctx->r11);
    // 0x8007C29C: sll         $t5, $s5, 5
    ctx->r13 = S32(ctx->r21 << 5);
    // 0x8007C2A0: addu        $s0, $s0, $t5
    ctx->r16 = ADD32(ctx->r16, ctx->r13);
    // 0x8007C2A4: jal         0x80071850
    // 0x8007C2A8: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    align16(rdram, ctx);
        goto after_1;
    // 0x8007C2A8: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    after_1:
    // 0x8007C2AC: lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X2);
    // 0x8007C2B0: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8007C2B4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8007C2B8: jal         0x80071850
    // 0x8007C2BC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    align16(rdram, ctx);
        goto after_2;
    // 0x8007C2BC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
    // 0x8007C2C0: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007C2C4: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x8007C2C8: jal         0x80070D10
    // 0x8007C2CC: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc(rdram, ctx);
        goto after_3;
    // 0x8007C2CC: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_3:
    // 0x8007C2D0: bne         $v0, $zero, L_8007C300
    if (ctx->r2 != 0) {
        // 0x8007C2D4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007C300;
    }
    // 0x8007C2D4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007C2D8: lb          $t7, 0x32($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X32);
    // 0x8007C2DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C2E0: beq         $t7, $zero, L_8007C2F8
    if (ctx->r15 == 0) {
        // 0x8007C2E4: addiu       $v0, $v0, 0x6358
        ctx->r2 = ADD32(ctx->r2, 0X6358);
            goto L_8007C2F8;
    }
    // 0x8007C2E4: addiu       $v0, $v0, 0x6358
    ctx->r2 = ADD32(ctx->r2, 0X6358);
    // 0x8007C2E8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8007C2EC: nop

    // 0x8007C2F0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007C2F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007C2F8:
    // 0x8007C2F8: b           L_8007C508
    // 0x8007C2FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C508;
    // 0x8007C2FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C300:
    // 0x8007C300: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007C304: jal         0x80071850
    // 0x8007C308: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    align16(rdram, ctx);
        goto after_4;
    // 0x8007C308: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_4:
    // 0x8007C30C: lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X2);
    // 0x8007C310: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8007C314: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8007C318: jal         0x80071850
    // 0x8007C31C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    align16(rdram, ctx);
        goto after_5;
    // 0x8007C31C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_5:
    // 0x8007C320: addu        $t4, $v0, $s3
    ctx->r12 = ADD32(ctx->r2, ctx->r19);
    // 0x8007C324: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8007C328: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007C32C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007C330: sll         $a0, $s5, 5
    ctx->r4 = S32(ctx->r21 << 5);
    // 0x8007C334: addiu       $a3, $a3, 0x6364
    ctx->r7 = ADD32(ctx->r7, 0X6364);
    // 0x8007C338: addiu       $a1, $a1, 0x6368
    ctx->r5 = ADD32(ctx->r5, 0X6368);
    // 0x8007C33C: addu        $t7, $t5, $a0
    ctx->r15 = ADD32(ctx->r13, ctx->r4);
    // 0x8007C340: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8007C344: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8007C348: lh          $t3, 0x2($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X2);
    // 0x8007C34C: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x8007C350: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x8007C354: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8007C358: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007C35C: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8007C360: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x8007C364: addiu       $a2, $a2, 0x6360
    ctx->r6 = ADD32(ctx->r6, 0X6360);
    // 0x8007C368: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007C36C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8007C370: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8007C374: sw          $t8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r24;
    // 0x8007C378: blez        $s5, L_8007C3F4
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8007C37C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007C3F4;
    }
    // 0x8007C37C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007C380: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8007C384: addiu       $s2, $s2, -0x1840
    ctx->r18 = ADD32(ctx->r18, -0X1840);
    // 0x8007C388: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007C38C:
    // 0x8007C38C: lui         $t3, 0xFF
    ctx->r11 = S32(0XFF << 16);
    // 0x8007C390: ori         $t3, $t3, 0x163
    ctx->r11 = ctx->r11 | 0X163;
    // 0x8007C394: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8007C398: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x8007C39C: sb          $v1, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r3;
    // 0x8007C3A0: jal         0x8007AE74
    // 0x8007C3A4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    load_texture(rdram, ctx);
        goto after_6;
    // 0x8007C3A4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    after_6:
    // 0x8007C3A8: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x8007C3AC: lb          $v1, 0x33($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X33);
    // 0x8007C3B0: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8007C3B4: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8007C3B8: lw          $t6, 0x8($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X8);
    // 0x8007C3BC: lui         $t3, 0xFF00
    ctx->r11 = S32(0XFF00 << 16);
    // 0x8007C3C0: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8007C3C4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007C3C8: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x8007C3CC: bne         $t8, $zero, L_8007C3D8
    if (ctx->r24 != 0) {
        // 0x8007C3D0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8007C3D8;
    }
    // 0x8007C3D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007C3D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8007C3D8:
    // 0x8007C3D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C3DC: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8007C3E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C3E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8007C3E8: bne         $s0, $s5, L_8007C38C
    if (ctx->r16 != ctx->r21) {
        // 0x8007C3EC: sw          $t9, 0x6344($at)
        MEM_W(0X6344, ctx->r1) = ctx->r25;
            goto L_8007C38C;
    }
    // 0x8007C3EC: sw          $t9, 0x6344($at)
    MEM_W(0X6344, ctx->r1) = ctx->r25;
    // 0x8007C3F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007C3F4:
    // 0x8007C3F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C3F8: beq         $v1, $zero, L_8007C468
    if (ctx->r3 == 0) {
        // 0x8007C3FC: sw          $zero, 0x6344($at)
        MEM_W(0X6344, ctx->r1) = 0;
            goto L_8007C468;
    }
    // 0x8007C3FC: sw          $zero, 0x6344($at)
    MEM_W(0X6344, ctx->r1) = 0;
    // 0x8007C400: blez        $s5, L_8007C438
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8007C404: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8007C438;
    }
    // 0x8007C404: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007C408:
    // 0x8007C408: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x8007C40C: nop

    // 0x8007C410: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8007C414: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8007C418: nop

    // 0x8007C41C: beq         $a0, $zero, L_8007C42C
    if (ctx->r4 == 0) {
        // 0x8007C420: nop
    
            goto L_8007C42C;
    }
    // 0x8007C420: nop

    // 0x8007C424: jal         0x8007B2BC
    // 0x8007C428: nop

    tex_free(rdram, ctx);
        goto after_7;
    // 0x8007C428: nop

    after_7:
L_8007C42C:
    // 0x8007C42C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C430: bne         $s0, $s5, L_8007C408
    if (ctx->r16 != ctx->r21) {
        // 0x8007C434: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8007C408;
    }
    // 0x8007C434: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8007C438:
    // 0x8007C438: lb          $t6, 0x32($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X32);
    // 0x8007C43C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C440: beq         $t6, $zero, L_8007C458
    if (ctx->r14 == 0) {
        // 0x8007C444: addiu       $v0, $v0, 0x6358
        ctx->r2 = ADD32(ctx->r2, 0X6358);
            goto L_8007C458;
    }
    // 0x8007C444: addiu       $v0, $v0, 0x6358
    ctx->r2 = ADD32(ctx->r2, 0X6358);
    // 0x8007C448: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8007C44C: nop

    // 0x8007C450: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8007C454: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8007C458:
    // 0x8007C458: jal         0x80071140
    // 0x8007C45C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8007C45C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x8007C460: b           L_8007C508
    // 0x8007C464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C508;
    // 0x8007C464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C468:
    // 0x8007C468: sh          $s5, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r21;
    // 0x8007C46C: lh          $t3, 0x2($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X2);
    // 0x8007C470: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x8007C474: sh          $t3, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r11;
    // 0x8007C478: lh          $t9, 0x2($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X2);
    // 0x8007C47C: nop

    // 0x8007C480: blez        $t9, L_8007C4B8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007C484: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8007C4B8;
    }
L_8007C484:
    // 0x8007C484: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007C488: addiu       $a3, $a3, 0x6364
    ctx->r7 = ADD32(ctx->r7, 0X6364);
    // 0x8007C48C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x8007C490: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8007C494: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007C498: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8007C49C: jal         0x8007CDC0
    // 0x8007C4A0: sw          $t4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r12;
    sprite_init_frame(rdram, ctx);
        goto after_9;
    // 0x8007C4A0: sw          $t4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r12;
    after_9:
    // 0x8007C4A4: lh          $t5, 0x2($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X2);
    // 0x8007C4A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C4AC: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007C4B0: bne         $at, $zero, L_8007C484
    if (ctx->r1 != 0) {
        // 0x8007C4B4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8007C484;
    }
    // 0x8007C4B4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8007C4B8:
    // 0x8007C4B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C4BC: lw          $t6, 0x6358($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6358);
    // 0x8007C4C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007C4C4: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x8007C4C8: bne         $at, $zero, L_8007C4D8
    if (ctx->r1 != 0) {
        // 0x8007C4CC: addiu       $a0, $a0, 0x634C
        ctx->r4 = ADD32(ctx->r4, 0X634C);
            goto L_8007C4D8;
    }
    // 0x8007C4CC: addiu       $a0, $a0, 0x634C
    ctx->r4 = ADD32(ctx->r4, 0X634C);
    // 0x8007C4D0: b           L_8007C508
    // 0x8007C4D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C508;
    // 0x8007C4D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C4D8:
    // 0x8007C4D8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8007C4DC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8007C4E0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8007C4E4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8007C4E8: addu        $t4, $t9, $t8
    ctx->r12 = ADD32(ctx->r25, ctx->r24);
    // 0x8007C4EC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007C4F0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8007C4F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007C4F8: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x8007C4FC: sw          $s3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r19;
    // 0x8007C500: sh          $t7, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r15;
    // 0x8007C504: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_8007C508:
    // 0x8007C508: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C50C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007C510: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007C514: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C518: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007C51C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8007C520: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8007C524: jr          $ra
    // 0x8007C528: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007C528: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void get_object_property_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800235DC: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800235E0: sw          $a1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r5;
    // 0x800235E4: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x800235E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800235EC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800235F0: sltiu       $at, $t8, 0x77
    ctx->r1 = ctx->r24 < 0X77 ? 1 : 0;
    // 0x800235F4: beq         $at, $zero, L_800238A8
    if (ctx->r1 == 0) {
        // 0x800235F8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800238A8;
    }
    // 0x800235F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800235FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023600: addu        $at, $at, $t8
    gpr jr_addend_8002360C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80023604: lw          $t8, 0x5688($at)
    ctx->r24 = ADD32(ctx->r1, 0X5688);
    // 0x80023608: nop

    // 0x8002360C: jr          $t8
    // 0x80023610: nop

    switch (jr_addend_8002360C >> 2) {
        case 0: goto L_80023614; break;
        case 1: goto L_800238A8; break;
        case 2: goto L_80023808; break;
        case 3: goto L_80023650; break;
        case 4: goto L_800236DC; break;
        case 5: goto L_800238A8; break;
        case 6: goto L_8002363C; break;
        case 7: goto L_80023664; break;
        case 8: goto L_80023678; break;
        case 9: goto L_800238A8; break;
        case 10: goto L_800238A8; break;
        case 11: goto L_80023790; break;
        case 12: goto L_800238A8; break;
        case 13: goto L_80023628; break;
        case 14: goto L_800238A8; break;
        case 15: goto L_8002368C; break;
        case 16: goto L_800236F0; break;
        case 17: goto L_800236DC; break;
        case 18: goto L_80023678; break;
        case 19: goto L_800238A8; break;
        case 20: goto L_800238A8; break;
        case 21: goto L_800238A8; break;
        case 22: goto L_800238A8; break;
        case 23: goto L_800238A8; break;
        case 24: goto L_800238A8; break;
        case 25: goto L_800238A8; break;
        case 26: goto L_800236B4; break;
        case 27: goto L_800238A8; break;
        case 28: goto L_800236C8; break;
        case 29: goto L_800236A0; break;
        case 30: goto L_80023754; break;
        case 31: goto L_80023704; break;
        case 32: goto L_800238A8; break;
        case 33: goto L_800238A8; break;
        case 34: goto L_800238A8; break;
        case 35: goto L_800238A8; break;
        case 36: goto L_800238A8; break;
        case 37: goto L_80023718; break;
        case 38: goto L_800238A8; break;
        case 39: goto L_8002372C; break;
        case 40: goto L_800236A0; break;
        case 41: goto L_800238A8; break;
        case 42: goto L_800238A8; break;
        case 43: goto L_800238A8; break;
        case 44: goto L_80023740; break;
        case 45: goto L_800238A8; break;
        case 46: goto L_80023830; break;
        case 47: goto L_800238A8; break;
        case 48: goto L_800238A8; break;
        case 49: goto L_80023790; break;
        case 50: goto L_80023790; break;
        case 51: goto L_800238A8; break;
        case 52: goto L_80023790; break;
        case 53: goto L_80023790; break;
        case 54: goto L_800236A0; break;
        case 55: goto L_80023790; break;
        case 56: goto L_800238A8; break;
        case 57: goto L_800238A8; break;
        case 58: goto L_800238A8; break;
        case 59: goto L_800238A8; break;
        case 60: goto L_800237E0; break;
        case 61: goto L_80023754; break;
        case 62: goto L_800238A8; break;
        case 63: goto L_800238A8; break;
        case 64: goto L_800238A8; break;
        case 65: goto L_800238A8; break;
        case 66: goto L_800238A8; break;
        case 67: goto L_800238A8; break;
        case 68: goto L_800238A8; break;
        case 69: goto L_80023790; break;
        case 70: goto L_800237A4; break;
        case 71: goto L_80023790; break;
        case 72: goto L_800238A8; break;
        case 73: goto L_8002386C; break;
        case 74: goto L_800238A8; break;
        case 75: goto L_800238A8; break;
        case 76: goto L_80023754; break;
        case 77: goto L_800238A8; break;
        case 78: goto L_80023768; break;
        case 79: goto L_80023790; break;
        case 80: goto L_80023790; break;
        case 81: goto L_800238A8; break;
        case 82: goto L_8002377C; break;
        case 83: goto L_80023790; break;
        case 84: goto L_80023790; break;
        case 85: goto L_80023790; break;
        case 86: goto L_800238A8; break;
        case 87: goto L_800238A8; break;
        case 88: goto L_800238A8; break;
        case 89: goto L_800238A8; break;
        case 90: goto L_800238A8; break;
        case 91: goto L_800238A8; break;
        case 92: goto L_800238A8; break;
        case 93: goto L_80023858; break;
        case 94: goto L_800238A8; break;
        case 95: goto L_80023790; break;
        case 96: goto L_80023790; break;
        case 97: goto L_800238A8; break;
        case 98: goto L_800238A8; break;
        case 99: goto L_800238A8; break;
        case 100: goto L_80023790; break;
        case 101: goto L_80023790; break;
        case 102: goto L_80023790; break;
        case 103: goto L_80023790; break;
        case 104: goto L_800238A8; break;
        case 105: goto L_800238A8; break;
        case 106: goto L_800238A8; break;
        case 107: goto L_800238A8; break;
        case 108: goto L_80023880; break;
        case 109: goto L_800238A8; break;
        case 110: goto L_80023628; break;
        case 111: goto L_800237B8; break;
        case 112: goto L_80023790; break;
        case 113: goto L_800238A8; break;
        case 114: goto L_80023790; break;
        case 115: goto L_80023894; break;
        case 116: goto L_800238A8; break;
        case 117: goto L_800237CC; break;
        case 118: goto L_80023790; break;
        default: switch_error(__func__, 0x8002360C, 0x800E5688);
    }
    // 0x80023610: nop

L_80023614:
    // 0x80023614: addiu       $v1, $zero, 0x224
    ctx->r3 = ADD32(0, 0X224);
    // 0x80023618: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002361C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023620: jr          $ra
    // 0x80023624: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023624: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023628:
    // 0x80023628: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x8002362C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023630: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023634: jr          $ra
    // 0x80023638: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023638: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002363C:
    // 0x8002363C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x80023640: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023644: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023648: jr          $ra
    // 0x8002364C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002364C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023650:
    // 0x80023650: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80023654: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023658: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002365C: jr          $ra
    // 0x80023660: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023660: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023664:
    // 0x80023664: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80023668: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002366C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023670: jr          $ra
    // 0x80023674: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023674: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023678:
    // 0x80023678: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x8002367C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023680: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023684: jr          $ra
    // 0x80023688: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023688: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002368C:
    // 0x8002368C: addiu       $v1, $zero, 0x1C
    ctx->r3 = ADD32(0, 0X1C);
    // 0x80023690: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023694: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023698: jr          $ra
    // 0x8002369C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002369C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236A0:
    // 0x800236A0: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800236A4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236A8: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236AC: jr          $ra
    // 0x800236B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236B4:
    // 0x800236B4: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x800236B8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236BC: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236C0: jr          $ra
    // 0x800236C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236C8:
    // 0x800236C8: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x800236CC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236D0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236D4: jr          $ra
    // 0x800236D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236DC:
    // 0x800236DC: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800236E0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236E4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236E8: jr          $ra
    // 0x800236EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236F0:
    // 0x800236F0: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x800236F4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236F8: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236FC: jr          $ra
    // 0x80023700: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023700: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023704:
    // 0x80023704: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80023708: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002370C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023710: jr          $ra
    // 0x80023714: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023714: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023718:
    // 0x80023718: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x8002371C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023720: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023724: jr          $ra
    // 0x80023728: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023728: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002372C:
    // 0x8002372C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x80023730: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023734: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023738: jr          $ra
    // 0x8002373C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002373C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023740:
    // 0x80023740: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80023744: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023748: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002374C: jr          $ra
    // 0x80023750: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023750: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023754:
    // 0x80023754: addiu       $v1, $zero, 0x38
    ctx->r3 = ADD32(0, 0X38);
    // 0x80023758: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002375C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023760: jr          $ra
    // 0x80023764: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023764: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023768:
    // 0x80023768: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x8002376C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023770: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023774: jr          $ra
    // 0x80023778: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023778: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002377C:
    // 0x8002377C: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80023780: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023784: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023788: jr          $ra
    // 0x8002378C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002378C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023790:
    // 0x80023790: addiu       $v1, $zero, 0x48
    ctx->r3 = ADD32(0, 0X48);
    // 0x80023794: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023798: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002379C: jr          $ra
    // 0x800237A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237A4:
    // 0x800237A4: addiu       $v1, $zero, 0x44
    ctx->r3 = ADD32(0, 0X44);
    // 0x800237A8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237AC: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237B0: jr          $ra
    // 0x800237B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237B8:
    // 0x800237B8: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800237BC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237C0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237C4: jr          $ra
    // 0x800237C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237CC:
    // 0x800237CC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800237D0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237D4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237D8: jr          $ra
    // 0x800237DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237E0:
    // 0x800237E0: andi        $t9, $a1, 0xF
    ctx->r25 = ctx->r5 & 0XF;
    // 0x800237E4: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800237E8: subu        $v0, $t0, $t9
    ctx->r2 = SUB32(ctx->r8, ctx->r25);
    // 0x800237EC: addu        $t1, $a1, $v0
    ctx->r9 = ADD32(ctx->r5, ctx->r2);
    // 0x800237F0: addiu       $v1, $v0, 0x110
    ctx->r3 = ADD32(ctx->r2, 0X110);
    // 0x800237F4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237F8: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237FC: sw          $t1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r9;
    // 0x80023800: jr          $ra
    // 0x80023804: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023804: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023808:
    // 0x80023808: andi        $t2, $a1, 0xF
    ctx->r10 = ctx->r5 & 0XF;
    // 0x8002380C: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80023810: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x80023814: addu        $t4, $a1, $v0
    ctx->r12 = ADD32(ctx->r5, ctx->r2);
    // 0x80023818: addiu       $v1, $v0, 0x120
    ctx->r3 = ADD32(ctx->r2, 0X120);
    // 0x8002381C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023820: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023824: sw          $t4, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r12;
    // 0x80023828: jr          $ra
    // 0x8002382C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002382C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023830:
    // 0x80023830: andi        $t5, $a1, 0xF
    ctx->r13 = ctx->r5 & 0XF;
    // 0x80023834: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80023838: subu        $v0, $t6, $t5
    ctx->r2 = SUB32(ctx->r14, ctx->r13);
    // 0x8002383C: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x80023840: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x80023844: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023848: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002384C: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
    // 0x80023850: jr          $ra
    // 0x80023854: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023854: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023858:
    // 0x80023858: addiu       $v1, $zero, 0x60
    ctx->r3 = ADD32(0, 0X60);
    // 0x8002385C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023860: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023864: jr          $ra
    // 0x80023868: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023868: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002386C:
    // 0x8002386C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80023870: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023874: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023878: jr          $ra
    // 0x8002387C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002387C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023880:
    // 0x80023880: addiu       $v1, $zero, 0x34
    ctx->r3 = ADD32(0, 0X34);
    // 0x80023884: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023888: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002388C: jr          $ra
    // 0x80023890: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023890: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023894:
    // 0x80023894: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x80023898: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002389C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800238A0: jr          $ra
    // 0x800238A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800238A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800238A8:
    // 0x800238A8: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x800238AC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800238B0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800238B4: jr          $ra
    // 0x800238B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800238B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
;}
RECOMP_FUNC void mempool_locked_unset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071538: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007153C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071540: jal         0x8006F510
    // 0x80071544: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071544: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80071548: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007154C: jal         0x800715EC
    // 0x80071550: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    mempool_get_pool(rdram, ctx);
        goto after_1;
    // 0x80071550: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80071554: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80071558: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007155C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80071560: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80071564: lw          $a0, 0x3588($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3588);
    // 0x80071568: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007156C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80071570: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80071574:
    // 0x80071574: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071578: mflo        $t7
    ctx->r15 = lo;
    // 0x8007157C: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x80071580: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80071584: nop

    // 0x80071588: bne         $a3, $t8, L_800715BC
    if (ctx->r7 != ctx->r24) {
        // 0x8007158C: nop
    
            goto L_800715BC;
    }
    // 0x8007158C: nop

    // 0x80071590: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x80071594: nop

    // 0x80071598: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x8007159C: beq         $t9, $zero, L_800715BC
    if (ctx->r25 == 0) {
        // 0x800715A0: xori        $t0, $v1, 0x2
        ctx->r8 = ctx->r3 ^ 0X2;
            goto L_800715BC;
    }
    // 0x800715A0: xori        $t0, $v1, 0x2
    ctx->r8 = ctx->r3 ^ 0X2;
    // 0x800715A4: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    // 0x800715A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800715AC: jal         0x8006F53C
    // 0x800715B0: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x800715B0: nop

    after_2:
    // 0x800715B4: b           L_800715DC
    // 0x800715B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800715DC;
    // 0x800715B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800715BC:
    // 0x800715BC: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x800715C0: nop

    // 0x800715C4: bne         $v1, $a2, L_80071574
    if (ctx->r3 != ctx->r6) {
        // 0x800715C8: nop
    
            goto L_80071574;
    }
    // 0x800715C8: nop

    // 0x800715CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800715D0: jal         0x8006F53C
    // 0x800715D4: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x800715D4: nop

    after_3:
    // 0x800715D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800715DC:
    // 0x800715DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800715E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800715E4: jr          $ra
    // 0x800715E8: nop

    return;
    // 0x800715E8: nop

;}
RECOMP_FUNC void audspat_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_enter_nature_audio_scope(uint8_t*, recomp_context*); dkr_enter_nature_audio_scope(rdram, ctx);
    // 0x80008438: addiu       $sp, $sp, -0x268
    ctx->r29 = ADD32(ctx->r29, -0X268);
    // 0x8000843C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80008440: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80008444: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80008448: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8000844C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80008450: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80008454: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80008458: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8000845C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80008460: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80008464: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80008468: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x8000846C: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80008470: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80008474: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80008478: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x8000847C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80008480: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80008484: sw          $a0, 0x268($sp)
    MEM_W(0X268, ctx->r29) = ctx->r4;
    // 0x80008488: sw          $a1, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r5;
    // 0x8000848C: sw          $a2, 0x270($sp)
    MEM_W(0X270, ctx->r29) = ctx->r6;
    // 0x80008490: jal         0x80066210
    // 0x80008494: sw          $zero, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = 0;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x80008494: sw          $zero, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = 0;
    after_0:
    // 0x80008498: jal         0x8006652C
    // 0x8000849C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    cam_set_layout(rdram, ctx);
        goto after_1;
    // 0x8000849C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800084A0: jal         0x80069D7C
    // 0x800084A4: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    cam_get_cameras(rdram, ctx);
        goto after_2;
    // 0x800084A4: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    after_2:
    // 0x800084A8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800084AC: addiu       $s5, $s5, -0x3920
    ctx->r21 = ADD32(ctx->r21, -0X3920);
    // 0x800084B0: lhu         $t6, 0x0($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X0);
    // 0x800084B4: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x800084B8: blez        $t6, L_80008AD8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800084BC: sw          $zero, 0x260($sp)
        MEM_W(0X260, ctx->r29) = 0;
            goto L_80008AD8;
    }
    // 0x800084BC: sw          $zero, 0x260($sp)
    MEM_W(0X260, ctx->r29) = 0;
    // 0x800084C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800084C4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800084C8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800084CC: addiu       $s6, $s6, -0x63BC
    ctx->r22 = ADD32(ctx->r22, -0X63BC);
    // 0x800084D0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800084D4: addiu       $s7, $sp, 0xA8
    ctx->r23 = ADD32(ctx->r29, 0XA8);
    // 0x800084D8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800084DC:
    // 0x800084DC: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800084E0: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x800084E4: addu        $t8, $t7, $s4
    ctx->r24 = ADD32(ctx->r15, ctx->r20);
    // 0x800084E8: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x800084EC: sw          $zero, 0x254($sp)
    MEM_W(0X254, ctx->r29) = 0;
    // 0x800084F0: lbu         $t9, 0x11($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X11);
    // 0x800084F4: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800084F8: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x800084FC: beq         $t0, $zero, L_800086BC
    if (ctx->r8 == 0) {
        // 0x80008500: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800086BC;
    }
    // 0x80008500: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008504: bne         $t1, $at, L_80008ABC
    if (ctx->r9 != ctx->r1) {
        // 0x80008508: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008508: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x8000850C: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80008510: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80008514: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80008518: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8000851C: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80008520: lwc1        $f10, 0x10($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80008524: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80008528: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000852C: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80008530: lwc1        $f18, 0x14($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80008534: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80008538: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8000853C: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80008540: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80008544: jal         0x800C9AD0
    // 0x80008548: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80008548: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x8000854C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80008550: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80008554: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80008558: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000855C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008560: nop

    // 0x80008564: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80008568: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8000856C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80008570: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80008574: beq         $at, $zero, L_8000869C
    if (ctx->r1 == 0) {
        // 0x80008578: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8000869C;
    }
    // 0x80008578: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000857C: lbu         $t4, 0x12($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X12);
    // 0x80008580: nop

    // 0x80008584: bne         $t4, $zero, L_8000869C
    if (ctx->r12 != 0) {
        // 0x80008588: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8000869C;
    }
    // 0x80008588: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000858C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008590: nop

    // 0x80008594: bne         $a0, $zero, L_800085D4
    if (ctx->r4 != 0) {
        // 0x80008598: nop
    
            goto L_800085D4;
    }
    // 0x80008598: nop

    // 0x8000859C: lbu         $t5, 0x22($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X22);
    // 0x800085A0: nop

    // 0x800085A4: beq         $t5, $zero, L_800085C0
    if (ctx->r13 == 0) {
        // 0x800085A8: nop
    
            goto L_800085C0;
    }
    // 0x800085A8: nop

    // 0x800085AC: lbu         $t6, 0x11($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X11);
    // 0x800085B0: nop

    // 0x800085B4: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800085B8: bne         $t7, $zero, L_800085D4
    if (ctx->r15 != 0) {
        // 0x800085BC: nop
    
            goto L_800085D4;
    }
    // 0x800085BC: nop

L_800085C0:
    // 0x800085C0: lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XC);
    // 0x800085C4: jal         0x80001F14
    // 0x800085C8: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    sound_play_direct(rdram, ctx);
        goto after_4;
    // 0x800085C8: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    after_4:
    // 0x800085CC: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800085D0: sb          $s2, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r18;
L_800085D4:
    // 0x800085D4: beq         $a0, $zero, L_80008690
    if (ctx->r4 == 0) {
        // 0x800085D8: nop
    
            goto L_80008690;
    }
    // 0x800085D8: nop

    // 0x800085DC: lbu         $t8, 0xF($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XF);
    // 0x800085E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800085E4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800085E8: bgez        $t8, L_800085FC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800085EC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800085FC;
    }
    // 0x800085EC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800085F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800085F4: nop

    // 0x800085F8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800085FC:
    // 0x800085FC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80008600: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80008604: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80008608: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000860C: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x80008610: lbu         $a2, 0xE($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0XE);
    // 0x80008614: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008618: sll         $t9, $a2, 8
    ctx->r25 = S32(ctx->r6 << 8);
    // 0x8000861C: jal         0x800049F8
    // 0x80008620: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80008620: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_5:
    // 0x80008624: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008628: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x8000862C: jal         0x800049F8
    // 0x80008630: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_6;
    // 0x80008630: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_6:
    // 0x80008634: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x80008638: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000863C: lh          $a2, 0x0($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X0);
    // 0x80008640: jal         0x800090C0
    // 0x80008644: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_7;
    // 0x80008644: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_7:
    // 0x80008648: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8000864C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008650: beq         $t1, $at, L_8000865C
    if (ctx->r9 == ctx->r1) {
        // 0x80008654: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000865C;
    }
    // 0x80008654: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80008658: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
L_8000865C:
    // 0x8000865C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008660: jal         0x800049F8
    // 0x80008664: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_8;
    // 0x80008664: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80008668: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x8000866C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80008670: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80008674: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80008678: jal         0x80009B7C
    // 0x8000867C: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_9;
    // 0x8000867C: nop

    after_9:
    // 0x80008680: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008684: lbu         $a1, 0x21($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X21);
    // 0x80008688: jal         0x80004604
    // 0x8000868C: nop

    sndp_set_priority(rdram, ctx);
        goto after_10;
    // 0x8000868C: nop

    after_10:
L_80008690:
    // 0x80008690: b           L_80008AB8
    // 0x80008694: sb          $s2, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r18;
        goto L_80008AB8;
    // 0x80008694: sb          $s2, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r18;
    // 0x80008698: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_8000869C:
    // 0x8000869C: beq         $at, $zero, L_80008ABC
    if (ctx->r1 == 0) {
        // 0x800086A0: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x800086A0: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x800086A4: lbu         $t2, 0x12($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X12);
    // 0x800086A8: nop

    // 0x800086AC: beq         $t2, $zero, L_80008ABC
    if (ctx->r10 == 0) {
        // 0x800086B0: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x800086B0: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x800086B4: b           L_80008AB8
    // 0x800086B8: sb          $zero, 0x12($s1)
    MEM_B(0X12, ctx->r17) = 0;
        goto L_80008AB8;
    // 0x800086B8: sb          $zero, 0x12($s1)
    MEM_B(0X12, ctx->r17) = 0;
L_800086BC:
    // 0x800086BC: blez        $t3, L_8000884C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800086C0: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8000884C;
    }
    // 0x800086C0: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800086C4: lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XAC);
    // 0x800086C8: nop

L_800086CC:
    // 0x800086CC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800086D0: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800086D4: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800086D8: sub.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800086DC: lwc1        $f4, 0x10($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800086E0: mul.s       $f16, $f20, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800086E4: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800086E8: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800086EC: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800086F0: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800086F4: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800086F8: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800086FC: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80008700: jal         0x800C9AD0
    // 0x80008704: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x80008704: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_11:
    // 0x80008708: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8000870C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80008710: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80008714: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008718: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000871C: lw          $t1, 0x254($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X254);
    // 0x80008720: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80008724: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80008728: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8000872C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80008730: beq         $at, $zero, L_80008840
    if (ctx->r1 == 0) {
        // 0x80008734: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_80008840;
    }
    // 0x80008734: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80008738: lbu         $t5, 0x20($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X20);
    // 0x8000873C: subu        $t8, $a0, $v1
    ctx->r24 = SUB32(ctx->r4, ctx->r3);
    // 0x80008740: bne         $t5, $zero, L_800087B0
    if (ctx->r13 != 0) {
        // 0x80008744: nop
    
            goto L_800087B0;
    }
    // 0x80008744: nop

    // 0x80008748: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8000874C: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80008750: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80008754: lbu         $t6, 0xE($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XE);
    // 0x80008758: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000875C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80008760: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80008764: div.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80008768: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000876C: bgez        $t6, L_80008780
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80008770: sub.s       $f8, $f26, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f4.fl;
            goto L_80008780;
    }
    // 0x80008770: sub.s       $f8, $f26, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x80008774: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80008778: nop

    // 0x8000877C: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_80008780:
    // 0x80008780: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80008784: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80008788: nop

    // 0x8000878C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80008790: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008794: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008798: nop

    // 0x8000879C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800087A0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800087A4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800087A8: b           L_8000881C
    // 0x800087AC: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_8000881C;
    // 0x800087AC: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
L_800087B0:
    // 0x800087B0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800087B4: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800087B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800087BC: lbu         $t9, 0xE($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XE);
    // 0x800087C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800087C4: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800087C8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800087CC: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800087D0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800087D4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800087D8: bgez        $t9, L_800087EC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800087DC: nop
    
            goto L_800087EC;
    }
    // 0x800087DC: nop

    // 0x800087E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800087E4: nop

    // 0x800087E8: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_800087EC:
    // 0x800087EC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800087F0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800087F4: nop

    // 0x800087F8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800087FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008800: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008804: nop

    // 0x80008808: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000880C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80008810: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80008814: nop

    // 0x80008818: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
L_8000881C:
    // 0x8000881C: beq         $at, $zero, L_80008840
    if (ctx->r1 == 0) {
        // 0x80008820: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_80008840;
    }
    // 0x80008820: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80008824: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // 0x80008828: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    // 0x8000882C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80008830: jal         0x800090C0
    // 0x80008834: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_12;
    // 0x80008834: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_12:
    // 0x80008838: sw          $v0, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r2;
    // 0x8000883C: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
L_80008840:
    // 0x80008840: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80008844: bne         $fp, $t2, L_800086CC
    if (ctx->r30 != ctx->r10) {
        // 0x80008848: addiu       $s3, $s3, 0x44
        ctx->r19 = ADD32(ctx->r19, 0X44);
            goto L_800086CC;
    }
    // 0x80008848: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
L_8000884C:
    // 0x8000884C: lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X10);
    // 0x80008850: lw          $t3, 0x254($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X254);
    // 0x80008854: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008858: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000885C: beq         $at, $zero, L_8000892C
    if (ctx->r1 == 0) {
        // 0x80008860: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000892C;
    }
    // 0x80008860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008864: lwc1        $f24, 0x4F14($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X4F14);
    // 0x80008868: blez        $t4, L_80008928
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000886C: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80008928;
    }
    // 0x8000886C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80008870: lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XAC);
    // 0x80008874: nop

L_80008878:
    // 0x80008878: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8000887C: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80008880: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80008884: sub.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80008888: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8000888C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80008890: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80008894: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80008898: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8000889C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800088A0: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800088A4: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800088A8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800088AC: jal         0x800C9AD0
    // 0x800088B0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_13;
    // 0x800088B0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_13:
    // 0x800088B4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800088B8: nop

    // 0x800088BC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800088C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800088C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800088C8: nop

    // 0x800088CC: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800088D0: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    // 0x800088D4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800088D8: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x800088DC: nop

    // 0x800088E0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800088E4: c.lt.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl < ctx->f24.fl;
    // 0x800088E8: nop

    // 0x800088EC: bc1f        L_80008914
    if (!c1cs) {
        // 0x800088F0: lw          $t6, 0xB0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XB0);
            goto L_80008914;
    }
    // 0x800088F0: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800088F4: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    // 0x800088F8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800088FC: jal         0x800090C0
    // 0x80008900: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_14;
    // 0x80008900: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_14:
    // 0x80008904: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80008908: sw          $v0, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r2;
    // 0x8000890C: cvt.s.w     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80008910: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
L_80008914:
    // 0x80008914: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80008918: bne         $fp, $t6, L_80008878
    if (ctx->r30 != ctx->r14) {
        // 0x8000891C: addiu       $s3, $s3, 0x44
        ctx->r19 = ADD32(ctx->r19, 0X44);
            goto L_80008878;
    }
    // 0x8000891C: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
    // 0x80008920: lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X10);
    // 0x80008924: nop

L_80008928:
    // 0x80008928: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
L_8000892C:
    // 0x8000892C: lw          $t7, 0x254($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X254);
    // 0x80008930: nop

    // 0x80008934: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x80008938: bne         $at, $zero, L_80008A4C
    if (ctx->r1 != 0) {
        // 0x8000893C: nop
    
            goto L_80008A4C;
    }
    // 0x8000893C: nop

    // 0x80008940: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008944: nop

    // 0x80008948: bne         $a0, $zero, L_80008988
    if (ctx->r4 != 0) {
        // 0x8000894C: nop
    
            goto L_80008988;
    }
    // 0x8000894C: nop

    // 0x80008950: lbu         $t8, 0x22($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X22);
    // 0x80008954: nop

    // 0x80008958: beq         $t8, $zero, L_80008974
    if (ctx->r24 == 0) {
        // 0x8000895C: nop
    
            goto L_80008974;
    }
    // 0x8000895C: nop

    // 0x80008960: lbu         $t9, 0x11($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X11);
    // 0x80008964: nop

    // 0x80008968: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8000896C: bne         $t0, $zero, L_80008988
    if (ctx->r8 != 0) {
        // 0x80008970: nop
    
            goto L_80008988;
    }
    // 0x80008970: nop

L_80008974:
    // 0x80008974: lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XC);
    // 0x80008978: jal         0x80001F14
    // 0x8000897C: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    sound_play_direct(rdram, ctx);
        goto after_15;
    // 0x8000897C: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    after_15:
    // 0x80008980: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008984: sb          $s2, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r18;
L_80008988:
    // 0x80008988: beq         $a0, $zero, L_80008A38
    if (ctx->r4 == 0) {
        // 0x8000898C: nop
    
            goto L_80008A38;
    }
    // 0x8000898C: nop

    // 0x80008990: lbu         $t1, 0xF($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XF);
    // 0x80008994: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008998: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8000899C: bgez        $t1, L_800089B0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800089A0: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800089B0;
    }
    // 0x800089A0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800089A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800089A8: nop

    // 0x800089AC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800089B0:
    // 0x800089B0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800089B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800089B8: lw          $a2, 0x254($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X254);
    // 0x800089BC: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800089C0: sll         $t2, $a2, 8
    ctx->r10 = S32(ctx->r6 << 8);
    // 0x800089C4: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800089C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800089CC: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x800089D0: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800089D4: jal         0x800049F8
    // 0x800089D8: nop

    sndp_set_param(rdram, ctx);
        goto after_16;
    // 0x800089D8: nop

    after_16:
    // 0x800089DC: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800089E0: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x800089E4: jal         0x800049F8
    // 0x800089E8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_17;
    // 0x800089E8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_17:
    // 0x800089EC: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800089F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800089F4: beq         $t3, $at, L_80008A00
    if (ctx->r11 == ctx->r1) {
        // 0x800089F8: addiu       $t4, $zero, 0x40
        ctx->r12 = ADD32(0, 0X40);
            goto L_80008A00;
    }
    // 0x800089F8: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800089FC: sw          $t4, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r12;
L_80008A00:
    // 0x80008A00: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A04: lw          $a2, 0x250($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X250);
    // 0x80008A08: jal         0x800049F8
    // 0x80008A0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_18;
    // 0x80008A0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
    // 0x80008A10: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A14: lbu         $a1, 0x21($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X21);
    // 0x80008A18: jal         0x80004604
    // 0x80008A1C: nop

    sndp_set_priority(rdram, ctx);
        goto after_19;
    // 0x80008A1C: nop

    after_19:
    // 0x80008A20: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A24: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80008A28: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80008A2C: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80008A30: jal         0x80009B7C
    // 0x80008A34: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_20;
    // 0x80008A34: nop

    after_20:
L_80008A38:
    // 0x80008A38: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x80008A3C: nop

    // 0x80008A40: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x80008A44: b           L_80008A88
    // 0x80008A48: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80008A88;
    // 0x80008A48: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80008A4C:
    // 0x80008A4C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A50: nop

    // 0x80008A54: beq         $a0, $zero, L_80008A78
    if (ctx->r4 == 0) {
        // 0x80008A58: nop
    
            goto L_80008A78;
    }
    // 0x80008A58: nop

    // 0x80008A5C: jal         0x8000488C
    // 0x80008A60: nop

    sndp_stop(rdram, ctx);
        goto after_21;
    // 0x80008A60: nop

    after_21:
    // 0x80008A64: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x80008A68: nop

    // 0x80008A6C: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x80008A70: b           L_80008A88
    // 0x80008A74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80008A88;
    // 0x80008A74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80008A78:
    // 0x80008A78: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x80008A7C: sb          $s2, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r18;
    // 0x80008A80: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80008A84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80008A88:
    // 0x80008A88: beq         $v0, $zero, L_80008ABC
    if (ctx->r2 == 0) {
        // 0x80008A8C: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008A8C: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x80008A90: lbu         $t8, 0x22($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X22);
    // 0x80008A94: nop

    // 0x80008A98: beq         $t8, $zero, L_80008ABC
    if (ctx->r24 == 0) {
        // 0x80008A9C: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008A9C: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x80008AA0: lw          $t9, 0x18($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X18);
    // 0x80008AA4: lw          $a0, 0x260($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X260);
    // 0x80008AA8: bne         $t9, $zero, L_80008ABC
    if (ctx->r25 != 0) {
        // 0x80008AAC: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008AAC: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x80008AB0: jal         0x8000A2E8
    // 0x80008AB4: nop

    audspat_point_stop_by_index(rdram, ctx);
        goto after_22;
    // 0x80008AB4: nop

    after_22:
L_80008AB8:
    // 0x80008AB8: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
L_80008ABC:
    // 0x80008ABC: lhu         $t2, 0x0($s5)
    ctx->r10 = MEM_HU(ctx->r21, 0X0);
    // 0x80008AC0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80008AC4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80008AC8: sw          $t1, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r9;
    // 0x80008ACC: bne         $at, $zero, L_800084DC
    if (ctx->r1 != 0) {
        // 0x80008AD0: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_800084DC;
    }
    // 0x80008AD0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80008AD4: sw          $zero, 0x260($sp)
    MEM_W(0X260, ctx->r29) = 0;
L_80008AD8:
    // 0x80008AD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80008ADC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80008AE0: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80008AE4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80008AE8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80008AEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008AF0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80008AF4: addiu       $v0, $v0, -0x63A8
    ctx->r2 = ADD32(ctx->r2, -0X63A8);
L_80008AF8:
    // 0x80008AF8: lw          $t3, 0x16C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X16C);
    // 0x80008AFC: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80008B00: beq         $t3, $zero, L_80008FC4
    if (ctx->r11 == 0) {
        // 0x80008B04: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_80008FC4;
    }
    // 0x80008B04: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x80008B08: lbu         $a0, 0x263($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X263);
    // 0x80008B0C: jal         0x800099EC
    // 0x80008B10: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    audspat_line_validate(rdram, ctx);
        goto after_23;
    // 0x80008B10: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    after_23:
    // 0x80008B14: beq         $v0, $zero, L_80008FC8
    if (ctx->r2 == 0) {
        // 0x80008B18: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008B18: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008B1C: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008B20: sw          $zero, 0x254($sp)
    MEM_W(0X254, ctx->r29) = 0;
    // 0x80008B24: blez        $t4, L_80008E44
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80008B28: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80008E44;
    }
    // 0x80008B28: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80008B2C: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80008B30: nop

    // 0x80008B34: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x80008B38: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x80008B3C: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
L_80008B40:
    // 0x80008B40: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x80008B44: lw          $v1, 0x170($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X170);
    // 0x80008B48: lb          $t6, 0x17C($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X17C);
    // 0x80008B4C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80008B50: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80008B54: blez        $t6, L_80008C0C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80008B58: or          $s6, $v1, $zero
        ctx->r22 = ctx->r3 | 0;
            goto L_80008C0C;
    }
    // 0x80008B58: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x80008B5C: sll         $t8, $fp, 4
    ctx->r24 = S32(ctx->r30 << 4);
    // 0x80008B60: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80008B64: addu        $t8, $t8, $fp
    ctx->r24 = ADD32(ctx->r24, ctx->r30);
    // 0x80008B68: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80008B6C: addiu       $s0, $sp, 0x1A8
    ctx->r16 = ADD32(ctx->r29, 0X1A8);
    // 0x80008B70: addiu       $s1, $sp, 0x12C
    ctx->r17 = ADD32(ctx->r29, 0X12C);
    // 0x80008B74: addu        $s3, $t7, $t8
    ctx->r19 = ADD32(ctx->r15, ctx->r24);
L_80008B78:
    // 0x80008B78: lwc1        $f12, 0xC($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80008B7C: lwc1        $f14, 0x10($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X10);
    // 0x80008B80: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80008B84: addiu       $t9, $sp, 0x22C
    ctx->r25 = ADD32(ctx->r29, 0X22C);
    // 0x80008B88: addiu       $t0, $sp, 0x228
    ctx->r8 = ADD32(ctx->r29, 0X228);
    // 0x80008B8C: addiu       $t1, $sp, 0x224
    ctx->r9 = ADD32(ctx->r29, 0X224);
    // 0x80008B90: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80008B94: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80008B98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80008B9C: jal         0x800092A8
    // 0x80008BA0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    audspat_distance_to_segment(rdram, ctx);
        goto after_24;
    // 0x80008BA0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_24:
    // 0x80008BA4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80008BA8: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80008BAC: lwc1        $f16, 0x224($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X224);
    // 0x80008BB0: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80008BB4: lwc1        $f8, 0x22C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X22C);
    // 0x80008BB8: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    // 0x80008BBC: sub.s       $f14, $f16, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80008BC0: jal         0x800090C0
    // 0x80008BC4: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_25;
    // 0x80008BC4: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    after_25:
    // 0x80008BC8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80008BCC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80008BD0: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80008BD4: beq         $at, $zero, L_80008BE0
    if (ctx->r1 == 0) {
        // 0x80008BD8: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80008BE0;
    }
    // 0x80008BD8: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80008BDC: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
L_80008BE0:
    // 0x80008BE0: lb          $t2, 0x17C($s7)
    ctx->r10 = MEM_B(ctx->r23, 0X17C);
    // 0x80008BE4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80008BE8: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80008BEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80008BF0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80008BF4: bne         $at, $zero, L_80008B78
    if (ctx->r1 != 0) {
        // 0x80008BF8: addu        $s5, $s5, $v1
        ctx->r21 = ADD32(ctx->r21, ctx->r3);
            goto L_80008B78;
    }
    // 0x80008BF8: addu        $s5, $s5, $v1
    ctx->r21 = ADD32(ctx->r21, ctx->r3);
    // 0x80008BFC: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80008C00: nop

    // 0x80008C04: lw          $v1, 0x170($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X170);
    // 0x80008C08: nop

L_80008C0C:
    // 0x80008C0C: mtc1        $v1, $f24
    ctx->f24.u32l = ctx->r3;
    // 0x80008C10: lbu         $t4, 0x174($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X174);
    // 0x80008C14: cvt.s.w     $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = CVT_S_W(ctx->f24.u32l);
    // 0x80008C18: mtc1        $t4, $f24
    ctx->f24.u32l = ctx->r12;
    // 0x80008C1C: bgez        $t4, L_80008C34
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80008C20: cvt.s.w     $f12, $f24
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = CVT_S_W(ctx->f24.u32l);
            goto L_80008C34;
    }
    // 0x80008C20: cvt.s.w     $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = CVT_S_W(ctx->f24.u32l);
    // 0x80008C24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008C28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80008C2C: nop

    // 0x80008C30: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_80008C34:
    // 0x80008C34: lbu         $t5, 0x17D($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X17D);
    // 0x80008C38: lw          $t9, 0x254($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X254);
    // 0x80008C3C: bne         $t5, $zero, L_80008C8C
    if (ctx->r13 != 0) {
        // 0x80008C40: subu        $t7, $v1, $s6
        ctx->r15 = SUB32(ctx->r3, ctx->r22);
            goto L_80008C8C;
    }
    // 0x80008C40: subu        $t7, $v1, $s6
    ctx->r15 = SUB32(ctx->r3, ctx->r22);
    // 0x80008C44: mtc1        $s6, $f6
    ctx->f6.u32l = ctx->r22;
    // 0x80008C48: nop

    // 0x80008C4C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008C50: nop

    // 0x80008C54: div.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80008C58: sub.s       $f18, $f26, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x80008C5C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80008C60: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80008C64: nop

    // 0x80008C68: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80008C6C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008C70: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008C74: nop

    // 0x80008C78: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80008C7C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80008C80: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80008C84: b           L_80008CD8
    // 0x80008C88: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
        goto L_80008CD8;
    // 0x80008C88: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
L_80008C8C:
    // 0x80008C8C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80008C90: nop

    // 0x80008C94: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008C98: nop

    // 0x80008C9C: div.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80008CA0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80008CA4: nop

    // 0x80008CA8: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80008CAC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80008CB0: nop

    // 0x80008CB4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80008CB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008CBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008CC0: nop

    // 0x80008CC4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80008CC8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80008CCC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80008CD0: nop

    // 0x80008CD4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
L_80008CD8:
    // 0x80008CD8: bne         $at, $zero, L_80008E38
    if (ctx->r1 != 0) {
        // 0x80008CDC: lw          $t4, 0xB0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XB0);
            goto L_80008E38;
    }
    // 0x80008CDC: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008CE0: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80008CE4: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // 0x80008CE8: lb          $v1, 0x17C($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X17C);
    // 0x80008CEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008CF0: bne         $v1, $at, L_80008D04
    if (ctx->r3 != ctx->r1) {
        // 0x80008CF4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80008D04;
    }
    // 0x80008CF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008CF8: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x80008CFC: b           L_80008DD8
    // 0x80008D00: sw          $t1, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r9;
        goto L_80008DD8;
    // 0x80008D00: sw          $t1, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r9;
L_80008D04:
    // 0x80008D04: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80008D08: blez        $v1, L_80008D50
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80008D0C: sw          $zero, 0x250($sp)
        MEM_W(0X250, ctx->r29) = 0;
            goto L_80008D50;
    }
    // 0x80008D0C: sw          $zero, 0x250($sp)
    MEM_W(0X250, ctx->r29) = 0;
    // 0x80008D10: addiu       $s0, $sp, 0x1A8
    ctx->r16 = ADD32(ctx->r29, 0X1A8);
    // 0x80008D14: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
L_80008D18:
    // 0x80008D18: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80008D1C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80008D20: subu        $v1, $s5, $t2
    ctx->r3 = SUB32(ctx->r21, ctx->r10);
    // 0x80008D24: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80008D28: lb          $t3, 0x17C($s7)
    ctx->r11 = MEM_B(ctx->r23, 0X17C);
    // 0x80008D2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80008D30: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80008D34: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008D38: bne         $at, $zero, L_80008D18
    if (ctx->r1 != 0) {
        // 0x80008D3C: addu        $a0, $a0, $v1
        ctx->r4 = ADD32(ctx->r4, ctx->r3);
            goto L_80008D18;
    }
    // 0x80008D3C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80008D40: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80008D44: nop

    // 0x80008D48: lb          $v1, 0x17C($t4)
    ctx->r3 = MEM_B(ctx->r12, 0X17C);
    // 0x80008D4C: nop

L_80008D50:
    // 0x80008D50: blez        $v1, L_80008DD8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80008D54: addiu       $s1, $sp, 0x12C
        ctx->r17 = ADD32(ctx->r29, 0X12C);
            goto L_80008DD8;
    }
    // 0x80008D54: addiu       $s1, $sp, 0x12C
    ctx->r17 = ADD32(ctx->r29, 0X12C);
    // 0x80008D58: lb          $a1, 0x17C($s7)
    ctx->r5 = MEM_B(ctx->r23, 0X17C);
    // 0x80008D5C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80008D60: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
    // 0x80008D64: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80008D68: lw          $a0, 0x250($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X250);
    // 0x80008D6C: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x80008D70: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
L_80008D74:
    // 0x80008D74: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80008D78: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80008D7C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80008D80: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80008D84: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008D88: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x80008D8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008D90: div.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80008D94: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80008D98: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80008D9C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008DA0: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80008DA4: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80008DA8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80008DAC: nop

    // 0x80008DB0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80008DB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008DB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008DBC: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80008DC0: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80008DC4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80008DC8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80008DCC: bne         $at, $zero, L_80008D74
    if (ctx->r1 != 0) {
        // 0x80008DD0: nop
    
            goto L_80008D74;
    }
    // 0x80008DD0: nop

    // 0x80008DD4: sw          $a0, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r4;
L_80008DD8:
    // 0x80008DD8: slti        $at, $s6, 0x190
    ctx->r1 = SIGNED(ctx->r22) < 0X190 ? 1 : 0;
    // 0x80008DDC: beq         $at, $zero, L_80008E38
    if (ctx->r1 == 0) {
        // 0x80008DE0: lw          $t4, 0xB0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XB0);
            goto L_80008E38;
    }
    // 0x80008DE0: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008DE4: mtc1        $s6, $f16
    ctx->f16.u32l = ctx->r22;
    // 0x80008DE8: lw          $t0, 0x250($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X250);
    // 0x80008DEC: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80008DF0: addiu       $t1, $t0, -0x40
    ctx->r9 = ADD32(ctx->r8, -0X40);
    // 0x80008DF4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80008DF8: div.s       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80008DFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80008E00: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80008E04: add.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x80008E08: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80008E0C: nop

    // 0x80008E10: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80008E14: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008E18: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008E1C: nop

    // 0x80008E20: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80008E24: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80008E28: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80008E2C: sw          $t3, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r11;
    // 0x80008E30: nop

    // 0x80008E34: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
L_80008E38:
    // 0x80008E38: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80008E3C: bne         $fp, $t4, L_80008B40
    if (ctx->r30 != ctx->r12) {
        // 0x80008E40: lw          $v0, 0x88($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X88);
            goto L_80008B40;
    }
    // 0x80008E40: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
L_80008E44:
    // 0x80008E44: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80008E48: lw          $t5, 0x254($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X254);
    // 0x80008E4C: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x80008E50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008E54: bne         $v0, $zero, L_80008F88
    if (ctx->r2 != 0) {
        // 0x80008E58: nop
    
            goto L_80008F88;
    }
    // 0x80008E58: nop

    // 0x80008E5C: lbu         $v0, 0x175($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X175);
    // 0x80008E60: nop

    // 0x80008E64: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80008E68: beq         $at, $zero, L_80008E78
    if (ctx->r1 == 0) {
        // 0x80008E6C: lw          $t7, 0x254($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X254);
            goto L_80008E78;
    }
    // 0x80008E6C: lw          $t7, 0x254($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X254);
    // 0x80008E70: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // 0x80008E74: lw          $t7, 0x254($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X254);
L_80008E78:
    // 0x80008E78: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x80008E7C: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x80008E80: bne         $at, $zero, L_80008F64
    if (ctx->r1 != 0) {
        // 0x80008E84: lw          $t7, 0x88($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X88);
            goto L_80008F64;
    }
    // 0x80008E84: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x80008E88: lbu         $t9, 0x176($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X176);
    // 0x80008E8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008E90: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80008E94: bgez        $t9, L_80008EA8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80008E98: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80008EA8;
    }
    // 0x80008E98: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80008E9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80008EA0: nop

    // 0x80008EA4: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_80008EA8:
    // 0x80008EA8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80008EAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80008EB0: nop

    // 0x80008EB4: div.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80008EB8: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x80008EBC: lw          $a0, 0x178($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X178);
    // 0x80008EC0: nop

    // 0x80008EC4: bne         $a0, $zero, L_80008EE8
    if (ctx->r4 != 0) {
        // 0x80008EC8: nop
    
            goto L_80008EE8;
    }
    // 0x80008EC8: nop

    // 0x80008ECC: lhu         $a0, 0x16E($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X16E);
    // 0x80008ED0: jal         0x80001F14
    // 0x80008ED4: addiu       $a1, $t8, 0x178
    ctx->r5 = ADD32(ctx->r24, 0X178);
    sound_play_direct(rdram, ctx);
        goto after_26;
    // 0x80008ED4: addiu       $a1, $t8, 0x178
    ctx->r5 = ADD32(ctx->r24, 0X178);
    after_26:
    // 0x80008ED8: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80008EDC: nop

    // 0x80008EE0: lw          $a0, 0x178($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X178);
    // 0x80008EE4: nop

L_80008EE8:
    // 0x80008EE8: beq         $a0, $zero, L_80008FC8
    if (ctx->r4 == 0) {
        // 0x80008EEC: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008EEC: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008EF0: lw          $a2, 0x254($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X254);
    // 0x80008EF4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80008EF8: sll         $t1, $a2, 8
    ctx->r9 = S32(ctx->r6 << 8);
    // 0x80008EFC: jal         0x800049F8
    // 0x80008F00: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    sndp_set_param(rdram, ctx);
        goto after_27;
    // 0x80008F00: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_27:
    // 0x80008F04: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x80008F08: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80008F0C: lw          $a0, 0x178($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X178);
    // 0x80008F10: jal         0x800049F8
    // 0x80008F14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_28;
    // 0x80008F14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_28:
    // 0x80008F18: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80008F1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008F20: beq         $t3, $at, L_80008F2C
    if (ctx->r11 == ctx->r1) {
        // 0x80008F24: addiu       $t4, $zero, 0x40
        ctx->r12 = ADD32(0, 0X40);
            goto L_80008F2C;
    }
    // 0x80008F24: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80008F28: sw          $t4, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r12;
L_80008F2C:
    // 0x80008F2C: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80008F30: lw          $a2, 0x250($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X250);
    // 0x80008F34: lw          $a0, 0x178($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X178);
    // 0x80008F38: jal         0x800049F8
    // 0x80008F3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_29;
    // 0x80008F3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_29:
    // 0x80008F40: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x80008F44: nop

    // 0x80008F48: lw          $a0, 0x178($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X178);
    // 0x80008F4C: lbu         $a1, 0x17E($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X17E);
    // 0x80008F50: jal         0x80004604
    // 0x80008F54: nop

    sndp_set_priority(rdram, ctx);
        goto after_30;
    // 0x80008F54: nop

    after_30:
    // 0x80008F58: b           L_80008FC8
    // 0x80008F5C: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
        goto L_80008FC8;
    // 0x80008F5C: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008F60: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
L_80008F64:
    // 0x80008F64: nop

    // 0x80008F68: lw          $a0, 0x178($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X178);
    // 0x80008F6C: nop

    // 0x80008F70: beq         $a0, $zero, L_80008FC8
    if (ctx->r4 == 0) {
        // 0x80008F74: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008F74: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008F78: jal         0x8000488C
    // 0x80008F7C: nop

    sndp_stop(rdram, ctx);
        goto after_31;
    // 0x80008F7C: nop

    after_31:
    // 0x80008F80: b           L_80008FC8
    // 0x80008F84: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
        goto L_80008FC8;
    // 0x80008F84: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
L_80008F88:
    // 0x80008F88: bne         $v0, $at, L_80008FC8
    if (ctx->r2 != ctx->r1) {
        // 0x80008F8C: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008F8C: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008F90: lw          $t9, 0x24C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24C);
    // 0x80008F94: lw          $t8, 0x254($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X254);
    // 0x80008F98: nop

    // 0x80008F9C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80008FA0: beq         $at, $zero, L_80008FC8
    if (ctx->r1 == 0) {
        // 0x80008FA4: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008FA4: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008FA8: lw          $t0, 0x250($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X250);
    // 0x80008FAC: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80008FB0: sw          $t8, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = ctx->r24;
    // 0x80008FB4: sw          $t0, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r8;
    // 0x80008FB8: lw          $t2, 0x16C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X16C);
    // 0x80008FBC: nop

    // 0x80008FC0: sw          $t2, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r10;
L_80008FC4:
    // 0x80008FC4: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
L_80008FC8:
    // 0x80008FC8: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80008FCC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80008FD0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80008FD4: sw          $t4, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r12;
    // 0x80008FD8: bne         $t4, $at, L_80008AF8
    if (ctx->r12 != ctx->r1) {
        // 0x80008FDC: addiu       $v0, $v0, 0x180
        ctx->r2 = ADD32(ctx->r2, 0X180);
            goto L_80008AF8;
    }
    // 0x80008FDC: addiu       $v0, $v0, 0x180
    ctx->r2 = ADD32(ctx->r2, 0X180);
    // 0x80008FE0: lw          $t6, 0x24C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24C);
    // 0x80008FE4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80008FE8: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80008FEC: bne         $at, $zero, L_80009044
    if (ctx->r1 != 0) {
        // 0x80008FF0: nop
    
            goto L_80009044;
    }
    // 0x80008FF0: nop

    // 0x80008FF4: lbu         $t5, -0x53E8($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X53E8);
    // 0x80008FF8: nop

    // 0x80008FFC: bne         $t5, $zero, L_80009044
    if (ctx->r13 != 0) {
        // 0x80009000: nop
    
            goto L_80009044;
    }
    // 0x80009000: nop

    // 0x80009004: jal         0x80001980
    // 0x80009008: nop

    music_jingle_current(rdram, ctx);
        goto after_32;
    // 0x80009008: nop

    after_32:
    // 0x8000900C: lw          $t7, 0x244($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X244);
    // 0x80009010: lbu         $a0, 0x247($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X247);
    // 0x80009014: beq         $t7, $v0, L_80009024
    if (ctx->r15 == ctx->r2) {
        // 0x80009018: nop
    
            goto L_80009024;
    }
    // 0x80009018: nop

    // 0x8000901C: jal         0x80001784
    // 0x80009020: nop

    music_jingle_play_safe(rdram, ctx);
        goto after_33;
    // 0x80009020: nop

    after_33:
L_80009024:
    // 0x80009024: lbu         $a0, 0x24F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X24F);
    // 0x80009028: jal         0x80001B0C
    // 0x8000902C: nop

    music_jingle_volume_set(rdram, ctx);
        goto after_34;
    // 0x8000902C: nop

    after_34:
    // 0x80009030: lbu         $a0, 0x24B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X24B);
    // 0x80009034: jal         0x80001B58
    // 0x80009038: nop

    music_jingle_pan_set(rdram, ctx);
        goto after_35;
    // 0x80009038: nop

    after_35:
    // 0x8000903C: b           L_80009050
    // 0x80009040: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
        goto L_80009050;
    // 0x80009040: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
L_80009044:
    // 0x80009044: jal         0x800018E0
    // 0x80009048: nop

    music_jingle_stop(rdram, ctx);
        goto after_36;
    // 0x80009048: nop

    after_36:
    // 0x8000904C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
L_80009050:
    // 0x80009050: lw          $a0, 0x268($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X268);
    // 0x80009054: beq         $a1, $zero, L_80009074
    if (ctx->r5 == 0) {
        // 0x80009058: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80009074;
    }
    // 0x80009058: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8000905C: lw          $t9, 0x270($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X270);
    // 0x80009060: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x80009064: lbu         $a3, 0xB3($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XB3);
    // 0x80009068: jal         0x80006FC8
    // 0x8000906C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    racer_sound_update_all(rdram, ctx);
        goto after_37;
    // 0x8000906C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_37:
    // 0x80009070: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80009074:
    extern void dkr_leave_nature_audio_scope(uint8_t*, recomp_context*); dkr_leave_nature_audio_scope(rdram, ctx);
    // 0x80009074: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80009078: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000907C: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80009080: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80009084: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80009088: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000908C: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80009090: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80009094: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80009098: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8000909C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800090A0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800090A4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800090A8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800090AC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800090B0: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800090B4: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800090B8: jr          $ra
    // 0x800090BC: addiu       $sp, $sp, 0x268
    ctx->r29 = ADD32(ctx->r29, 0X268);
    return;
    // 0x800090BC: addiu       $sp, $sp, 0x268
    ctx->r29 = ADD32(ctx->r29, 0X268);
;}
RECOMP_FUNC void cam_get_active_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069D20: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069D24: lb          $t6, 0xD14($t6)
    ctx->r14 = MEM_B(ctx->r14, 0XD14);
    // 0x80069D28: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80069D2C: beq         $t6, $zero, L_80069D5C
    if (ctx->r14 == 0) {
        // 0x80069D30: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_80069D5C;
    }
    // 0x80069D30: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80069D34: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80069D38: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x80069D3C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80069D40: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80069D44: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80069D48: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80069D4C: addiu       $t9, $t8, 0x110
    ctx->r25 = ADD32(ctx->r24, 0X110);
    // 0x80069D50: addiu       $t0, $t0, 0xAC0
    ctx->r8 = ADD32(ctx->r8, 0XAC0);
    // 0x80069D54: jr          $ra
    // 0x80069D58: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    return;
    // 0x80069D58: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
L_80069D5C:
    // 0x80069D5C: lw          $t1, 0xCE4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XCE4);
    // 0x80069D60: addiu       $t3, $t3, 0xAC0
    ctx->r11 = ADD32(ctx->r11, 0XAC0);
    // 0x80069D64: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80069D68: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80069D6C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80069D70: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80069D74: jr          $ra
    // 0x80069D78: nop

    return;
    // 0x80069D78: nop

;}
RECOMP_FUNC void catmull_rom_derivative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002277C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022780: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80022784: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80022788: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002278C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80022790: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x80022794: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022798: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8002279C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800227A0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800227A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800227A8: cvt.d.s     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f12.d = CVT_D_S(ctx->f10.fl);
    // 0x800227AC: mul.d       $f14, $f6, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f14.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800227B0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800227B4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800227B8: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800227BC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800227C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800227C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800227C8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800227CC: mul.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800227D0: lui         $at, 0xBFF8
    ctx->r1 = S32(0XBFF8 << 16);
    // 0x800227D4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800227D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800227DC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800227E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800227E4: mul.d       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800227E8: add.d       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f14.d + ctx->f6.d;
    // 0x800227EC: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x800227F0: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x800227F4: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x800227F8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800227FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80022800: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80022804: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80022808: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8002280C: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80022810: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x80022814: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x80022818: add.d       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f12.d + ctx->f6.d;
    // 0x8002281C: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x80022820: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022824: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80022828: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8002282C: mul.d       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x80022830: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80022834: mul.d       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80022838: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8002283C: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x80022840: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022844: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80022848: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002284C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80022850: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80022854: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80022858: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002285C: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x80022860: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80022864: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022868: nop

    // 0x8002286C: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80022870: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80022874: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80022878: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8002287C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022880: jr          $ra
    // 0x80022884: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    return;
    // 0x80022884: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
;}
RECOMP_FUNC void mtx_to_mtxs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F57C: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
    // 0x8006F580: lui         $t7, 0xFFFF
    ctx->r15 = S32(0XFFFF << 16);
L_8006F584:
    // 0x8006F584: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8006F588: lw          $t2, 0x20($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X20);
    // 0x8006F58C: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8006F590: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x8006F594: sh          $t1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r9;
    // 0x8006F598: sh          $t2, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r10;
    // 0x8006F59C: sh          $t3, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r11;
    // 0x8006F5A0: sh          $t4, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r12;
    // 0x8006F5A4: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x8006F5A8: srl         $t2, $t2, 16
    ctx->r10 = S32(U32(ctx->r10) >> 16);
    // 0x8006F5AC: srl         $t3, $t3, 16
    ctx->r11 = S32(U32(ctx->r11) >> 16);
    // 0x8006F5B0: srl         $t4, $t4, 16
    ctx->r12 = S32(U32(ctx->r12) >> 16);
    // 0x8006F5B4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8006F5B8: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x8006F5BC: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
    // 0x8006F5C0: sh          $t3, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r11;
    // 0x8006F5C4: sh          $t4, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r12;
    // 0x8006F5C8: addi        $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8006F5CC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006F5D0: bnel        $t0, $zero, L_8006F584
    if (ctx->r8 != 0) {
        // 0x8006F5D4: nop
    
            goto L_8006F584;
    }
    goto skip_0;
    // 0x8006F5D4: nop

    skip_0:
    // 0x8006F5D8: jr          $ra
    // 0x8006F5DC: nop

    return;
    // 0x8006F5DC: nop

;}
RECOMP_FUNC void slowly_reset_head_angle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005234C: lh          $v0, 0x16C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X16C);
    // 0x80052350: nop

    // 0x80052354: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80052358: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8005235C: sh          $t7, 0x16C($a0)
    MEM_H(0X16C, ctx->r4) = ctx->r15;
    // 0x80052360: lh          $v0, 0x16C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X16C);
    // 0x80052364: nop

    // 0x80052368: slti        $at, $v0, -0x9
    ctx->r1 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x8005236C: bne         $at, $zero, L_80052380
    if (ctx->r1 != 0) {
        // 0x80052370: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_80052380;
    }
    // 0x80052370: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80052374: beq         $at, $zero, L_80052380
    if (ctx->r1 == 0) {
        // 0x80052378: nop
    
            goto L_80052380;
    }
    // 0x80052378: nop

    // 0x8005237C: sh          $zero, 0x16C($a0)
    MEM_H(0X16C, ctx->r4) = 0;
L_80052380:
    // 0x80052380: jr          $ra
    // 0x80052384: nop

    return;
    // 0x80052384: nop

;}
RECOMP_FUNC void charselect_assign_ai(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { extern int dkr_legacy_character_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*); static const uint32_t dkr_character_menu_fields[] = { 0x801263d4U, 0x801263dcU, 0x801263e8U, 0x801263f0U, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df480U, 0x800df4bcU, 0x800df47cU, 0x801263a0U, 0x801263ccU, 0x800e3690U, 0x800e36c8U, 0x80126808U, 0x801263c0U, 0x8011ae5cU, 0x8011aec8U }; dkr_legacy_character_menu(rdram, ctx, 4U, dkr_character_menu_fields); } extern void dkr_netplay_character_select_ai_seed(uint8_t*, recomp_context*); dkr_netplay_character_select_ai_seed(rdram, ctx); extern void dkr_legacy_character_event(uint8_t*, recomp_context*, unsigned, uint32_t); dkr_legacy_character_event(rdram, ctx, 1U, 0x801263f0U);
    // 0x8008BB3C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008BB40: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008BB44: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008BB48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008BB4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008BB50: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008BB54: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008BB58: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008BB5C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008BB60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008BB64: jal         0x8009ECD0
    // 0x8008BB68: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    is_drumstick_unlocked(rdram, ctx);
        goto after_0;
    // 0x8008BB68: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    after_0:
    // 0x8008BB6C: beq         $v0, $zero, L_8008BB78
    if (ctx->r2 == 0) {
        // 0x8008BB70: nop
    
            goto L_8008BB78;
    }
    // 0x8008BB70: nop

    // 0x8008BB74: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
L_8008BB78:
    // 0x8008BB78: jal         0x8009ECB8
    // 0x8008BB7C: nop

    is_tt_unlocked(rdram, ctx);
        goto after_1;
    // 0x8008BB7C: nop

    after_1:
    // 0x8008BB80: beq         $v0, $zero, L_8008BB8C
    if (ctx->r2 == 0) {
        // 0x8008BB84: slti        $at, $s0, 0x8
        ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
            goto L_8008BB8C;
    }
    // 0x8008BB84: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8008BB88: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_8008BB8C:
    // 0x8008BB8C: beq         $at, $zero, L_8008BBEC
    if (ctx->r1 == 0) {
        // 0x8008BB90: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8008BBEC;
    }
    // 0x8008BB90: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008BB94: blez        $s0, L_8008BBD4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008BB98: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8008BBD4;
    }
    // 0x8008BB98: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008BB9C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008BBA0: addiu       $t6, $t6, 0x63F0
    ctx->r14 = ADD32(ctx->r14, 0X63F0);
    // 0x8008BBA4: addu        $s3, $zero, $t6
    ctx->r19 = ADD32(0, ctx->r14);
    // 0x8008BBA8: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x8008BBAC: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_8008BBB0:
    // 0x8008BBB0: lb          $t7, 0x0($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X0);
    // 0x8008BBB4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008BBB8: bne         $v1, $t7, L_8008BBC4
    if (ctx->r3 != ctx->r15) {
        // 0x8008BBBC: sltu        $at, $s3, $v0
        ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
            goto L_8008BBC4;
    }
    // 0x8008BBBC: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x8008BBC0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008BBC4:
    // 0x8008BBC4: beq         $at, $zero, L_8008BBD4
    if (ctx->r1 == 0) {
        // 0x8008BBC8: nop
    
            goto L_8008BBD4;
    }
    // 0x8008BBC8: nop

    // 0x8008BBCC: beq         $s1, $zero, L_8008BBB0
    if (ctx->r17 == 0) {
        // 0x8008BBD0: nop
    
            goto L_8008BBB0;
    }
    // 0x8008BBD0: nop

L_8008BBD4:
    // 0x8008BBD4: bne         $s1, $zero, L_8008BBEC
    if (ctx->r17 != 0) {
        // 0x8008BBD8: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_8008BBEC;
    }
    // 0x8008BBD8: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x8008BBDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008BBE0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008BBE4: sb          $v1, 0x63F0($at)
    MEM_B(0X63F0, ctx->r1) = ctx->r3;
    // 0x8008BBE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8008BBEC:
    // 0x8008BBEC: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8008BBF0: beq         $at, $zero, L_8008BCFC
    if (ctx->r1 == 0) {
        // 0x8008BBF4: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_8008BCFC;
    }
    // 0x8008BBF4: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8008BBF8: addiu       $t8, $t8, 0x63F0
    ctx->r24 = ADD32(ctx->r24, 0X63F0);
    // 0x8008BBFC: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008BC00: addiu       $s4, $s4, 0x63CC
    ctx->r20 = ADD32(ctx->r20, 0X63CC);
    // 0x8008BC04: addu        $s3, $s0, $t8
    ctx->r19 = ADD32(ctx->r16, ctx->r24);
    // 0x8008BC08: addiu       $s5, $zero, 0xE
    ctx->r21 = ADD32(0, 0XE);
L_8008BC0C:
    // 0x8008BC0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008BC10:
    // 0x8008BC10: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8008BC14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008BC18: jal         0x8006F94C
    // 0x8008BC1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x8008BC1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x8008BC20: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BC24: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8008BC28: andi        $a1, $s2, 0x3
    ctx->r5 = ctx->r18 & 0X3;
    // 0x8008BC2C: mflo        $t0
    ctx->r8 = lo;
    // 0x8008BC30: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8008BC34: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x8008BC38: blez        $s2, L_8008BCE4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8008BC3C: sb          $t2, 0x0($s3)
        MEM_B(0X0, ctx->r19) = ctx->r10;
            goto L_8008BCE4;
    }
    // 0x8008BC3C: sb          $t2, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r10;
    // 0x8008BC40: beq         $a1, $zero, L_8008BC78
    if (ctx->r5 == 0) {
        // 0x8008BC44: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8008BC78;
    }
    // 0x8008BC44: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8008BC48: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008BC4C: addiu       $t3, $t3, 0x63F0
    ctx->r11 = ADD32(ctx->r11, 0X63F0);
    // 0x8008BC50: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x8008BC54: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
L_8008BC58:
    // 0x8008BC58: lb          $t4, 0x0($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X0);
    // 0x8008BC5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008BC60: bne         $t4, $v1, L_8008BC6C
    if (ctx->r12 != ctx->r3) {
        // 0x8008BC64: nop
    
            goto L_8008BC6C;
    }
    // 0x8008BC64: nop

    // 0x8008BC68: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008BC6C:
    // 0x8008BC6C: bne         $a0, $s0, L_8008BC58
    if (ctx->r4 != ctx->r16) {
        // 0x8008BC70: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008BC58;
    }
    // 0x8008BC70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008BC74: beq         $s0, $s2, L_8008BCE4
    if (ctx->r16 == ctx->r18) {
        // 0x8008BC78: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8008BCE4;
    }
L_8008BC78:
    // 0x8008BC78: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008BC7C: addiu       $t5, $t5, 0x63F0
    ctx->r13 = ADD32(ctx->r13, 0X63F0);
    // 0x8008BC80: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x8008BC84: addu        $v0, $s0, $t5
    ctx->r2 = ADD32(ctx->r16, ctx->r13);
    // 0x8008BC88: addu        $a0, $s2, $t5
    ctx->r4 = ADD32(ctx->r18, ctx->r13);
L_8008BC8C:
    // 0x8008BC8C: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8008BC90: nop

    // 0x8008BC94: bne         $t6, $v1, L_8008BCA0
    if (ctx->r14 != ctx->r3) {
        // 0x8008BC98: nop
    
            goto L_8008BCA0;
    }
    // 0x8008BC98: nop

    // 0x8008BC9C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008BCA0:
    // 0x8008BCA0: lb          $t7, 0x1($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1);
    // 0x8008BCA4: nop

    // 0x8008BCA8: bne         $t7, $v1, L_8008BCB4
    if (ctx->r15 != ctx->r3) {
        // 0x8008BCAC: nop
    
            goto L_8008BCB4;
    }
    // 0x8008BCAC: nop

    // 0x8008BCB0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008BCB4:
    // 0x8008BCB4: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x8008BCB8: nop

    // 0x8008BCBC: bne         $t8, $v1, L_8008BCC8
    if (ctx->r24 != ctx->r3) {
        // 0x8008BCC0: nop
    
            goto L_8008BCC8;
    }
    // 0x8008BCC0: nop

    // 0x8008BCC4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008BCC8:
    // 0x8008BCC8: lb          $t9, 0x3($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3);
    // 0x8008BCCC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008BCD0: bne         $t9, $v1, L_8008BCDC
    if (ctx->r25 != ctx->r3) {
        // 0x8008BCD4: nop
    
            goto L_8008BCDC;
    }
    // 0x8008BCD4: nop

    // 0x8008BCD8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008BCDC:
    // 0x8008BCDC: bne         $v0, $a0, L_8008BC8C
    if (ctx->r2 != ctx->r4) {
        // 0x8008BCE0: nop
    
            goto L_8008BC8C;
    }
    // 0x8008BCE0: nop

L_8008BCE4:
    // 0x8008BCE4: bne         $s1, $zero, L_8008BC10
    if (ctx->r17 != 0) {
        // 0x8008BCE8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008BC10;
    }
    // 0x8008BCE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008BCEC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008BCF0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8008BCF4: bne         $s2, $at, L_8008BC0C
    if (ctx->r18 != ctx->r1) {
        // 0x8008BCF8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8008BC0C;
    }
    // 0x8008BCF8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8008BCFC:
    // 0x8008BCFC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8008BD00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008BD04: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BD08: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008BD0C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008BD10: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008BD14: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008BD18: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008BD1C: jr          $ra
    // 0x8008BD20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8008BD20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void lights_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031B60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80031B64: lw          $a0, -0x36B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X36B0);
    // 0x80031B68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031B6C: beq         $a0, $zero, L_80031B9C
    if (ctx->r4 == 0) {
        // 0x80031B70: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80031B9C;
    }
    // 0x80031B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031B74: jal         0x80071140
    // 0x80031B78: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x80031B78: nop

    after_0:
    // 0x80031B7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031B80: sw          $zero, -0x36B0($at)
    MEM_W(-0X36B0, ctx->r1) = 0;
    // 0x80031B84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031B88: sw          $zero, -0x36AC($at)
    MEM_W(-0X36AC, ctx->r1) = 0;
    // 0x80031B8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031B90: sw          $zero, -0x36A0($at)
    MEM_W(-0X36A0, ctx->r1) = 0;
    // 0x80031B94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031B98: sw          $zero, -0x369C($at)
    MEM_W(-0X369C, ctx->r1) = 0;
L_80031B9C:
    // 0x80031B9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031BA4: sw          $zero, -0x36A4($at)
    MEM_W(-0X36A4, ctx->r1) = 0;
    // 0x80031BA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BAC: sw          $zero, -0x36A8($at)
    MEM_W(-0X36A8, ctx->r1) = 0;
    // 0x80031BB0: jr          $ra
    // 0x80031BB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80031BB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void obj_init_unknown96(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038214: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80038218: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003821C: addiu       $t6, $zero, 0x81
    ctx->r14 = ADD32(0, 0X81);
    // 0x80038220: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038224: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80038228: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8003822C: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80038230: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038234: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80038238: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x8003823C: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80038240: jr          $ra
    // 0x80038244: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x80038244: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void sndp_init_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800031C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800031C4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800031C8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800031CC: addiu       $s2, $s2, -0x3944
    ctx->r18 = ADD32(ctx->r18, -0X3944);
    // 0x800031D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800031D4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800031D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800031DC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800031E0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800031E4: ori         $t1, $zero, 0x80E8
    ctx->r9 = 0 | 0X80E8;
    // 0x800031E8: sw          $t6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r14;
    // 0x800031EC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800031F0: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800031F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800031F8: sw          $t8, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r24;
    // 0x800031FC: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80003200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80003204: sw          $zero, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = 0;
    // 0x80003208: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8000320C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003210: sw          $t1, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->r9;
    // 0x80003214: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80003218: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8000321C: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80003220: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80003224: jal         0x800C77F0
    // 0x80003228: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80003228: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8000322C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80003230: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80003234: sw          $v0, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r2;
    // 0x80003238: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8000323C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80003240: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80003244: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80003248: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000324C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80003250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003254: jal         0x800C77F0
    // 0x80003258: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80003258: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8000325C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80003260: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80003264: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80003268: jal         0x800C935C
    // 0x8000326C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqNew(rdram, ctx);
        goto after_2;
    // 0x8000326C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_2:
    // 0x80003270: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80003274: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80003278: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8000327C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80003280: sw          $t9, -0x3948($at)
    MEM_W(-0X3948, ctx->r1) = ctx->r25;
    // 0x80003284: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80003288: nop

    // 0x8000328C: sltiu       $at, $t0, 0x2
    ctx->r1 = ctx->r8 < 0X2 ? 1 : 0;
    // 0x80003290: bne         $at, $zero, L_800032C8
    if (ctx->r1 != 0) {
        // 0x80003294: nop
    
            goto L_800032C8;
    }
    // 0x80003294: nop

L_80003298:
    // 0x80003298: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8000329C: sll         $t2, $s0, 6
    ctx->r10 = S32(ctx->r16 << 6);
    // 0x800032A0: lw          $v0, 0x40($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X40);
    // 0x800032A4: nop

    // 0x800032A8: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    // 0x800032AC: jal         0x800C8790
    // 0x800032B0: addiu       $a1, $a0, -0x40
    ctx->r5 = ADD32(ctx->r4, -0X40);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800032B0: addiu       $a1, $a0, -0x40
    ctx->r5 = ADD32(ctx->r4, -0X40);
    after_3:
    // 0x800032B4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800032B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800032BC: sltu        $at, $s0, $t3
    ctx->r1 = ctx->r16 < ctx->r11 ? 1 : 0;
    // 0x800032C0: bne         $at, $zero, L_80003298
    if (ctx->r1 != 0) {
        // 0x800032C4: nop
    
            goto L_80003298;
    }
    // 0x800032C4: nop

L_800032C8:
    // 0x800032C8: lhu         $t4, 0x10($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X10);
    // 0x800032CC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x800032D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800032D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800032D8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800032DC: jal         0x800C77F0
    // 0x800032E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x800032E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_4:
    // 0x800032E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800032E8: addiu       $a0, $a0, -0x63D8
    ctx->r4 = ADD32(ctx->r4, -0X63D8);
    // 0x800032EC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800032F0: lhu         $t5, 0x10($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X10);
    // 0x800032F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800032F8: beq         $t5, $zero, L_8000332C
    if (ctx->r13 == 0) {
        // 0x800032FC: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8000332C;
    }
    // 0x800032FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80003300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003304: addiu       $v1, $zero, 0x7FFF
    ctx->r3 = ADD32(0, 0X7FFF);
L_80003308:
    // 0x80003308: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000330C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80003310: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80003314: sh          $v1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r3;
    // 0x80003318: lhu         $t8, 0x10($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X10);
    // 0x8000331C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80003320: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x80003324: bne         $at, $zero, L_80003308
    if (ctx->r1 != 0) {
        // 0x80003328: nop
    
            goto L_80003308;
    }
    // 0x80003328: nop

L_8000332C:
    // 0x8000332C: lw          $t9, 0x3780($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3780);
    // 0x80003330: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80003334: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80003338: sw          $t9, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r25;
    // 0x8000333C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80003340: addiu       $t2, $t2, 0x33C8
    ctx->r10 = ADD32(ctx->r10, 0X33C8);
    // 0x80003344: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80003348: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8000334C: nop

    // 0x80003350: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x80003354: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003358: nop

    // 0x8000335C: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x80003360: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003364: nop

    // 0x80003368: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8000336C: jal         0x800C93D0
    // 0x80003370: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynAddPlayer(rdram, ctx);
        goto after_5;
    // 0x80003370: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80003374: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003378: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x8000337C: sh          $t4, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r12;
    // 0x80003380: lw          $a2, 0x4C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4C);
    // 0x80003384: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80003388: jal         0x800C91AC
    // 0x8000338C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_6;
    // 0x8000338C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_6:
    // 0x80003390: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003394: nop

    // 0x80003398: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x8000339C: jal         0x800C92D0
    // 0x800033A0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    alEvtqNextEvent(rdram, ctx);
        goto after_7;
    // 0x800033A0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_7:
    // 0x800033A4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800033A8: nop

    // 0x800033AC: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x800033B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800033B4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800033B8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800033BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800033C0: jr          $ra
    // 0x800033C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800033C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ainode_find_nearest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C524: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8001C528: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8001C52C: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8001C530: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001C534: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8001C538: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8001C53C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001C540: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8001C544: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x8001C548: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x8001C54C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8001C550: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8001C554: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8001C558: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8001C55C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8001C560: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8001C564: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001C568: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001C56C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001C570: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001C574: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8001C578: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001C57C: beq         $a3, $zero, L_8001C590
    if (ctx->r7 == 0) {
        // 0x8001C580: swc1        $f20, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
            goto L_8001C590;
    }
    // 0x8001C580: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8001C584: jal         0x8001C418
    // 0x8001C588: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    obj_elevation(rdram, ctx);
        goto after_0;
    // 0x8001C588: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_0:
    // 0x8001C58C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
L_8001C590:
    // 0x8001C590: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C594: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8001C598: lw          $fp, 0x64($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X64);
    // 0x8001C59C: lwc1        $f20, 0x5644($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5644);
    // 0x8001C5A0: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8001C5A4: addiu       $s3, $s3, -0x50FC
    ctx->r19 = ADD32(ctx->r19, -0X50FC);
    // 0x8001C5A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001C5AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C5B0: addiu       $s6, $zero, 0x80
    ctx->r22 = ADD32(0, 0X80);
    // 0x8001C5B4: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8001C5B8: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_8001C5BC:
    // 0x8001C5BC: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8001C5C0: nop

    // 0x8001C5C4: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8001C5C8: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8001C5CC: nop

    // 0x8001C5D0: beq         $v0, $zero, L_8001C664
    if (ctx->r2 == 0) {
        // 0x8001C5D4: nop
    
            goto L_8001C664;
    }
    // 0x8001C5D4: nop

    // 0x8001C5D8: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x8001C5DC: beq         $s2, $zero, L_8001C5F8
    if (ctx->r18 == 0) {
        // 0x8001C5E0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8001C5F8;
    }
    // 0x8001C5E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001C5E4: lb          $t8, 0xE($v1)
    ctx->r24 = MEM_B(ctx->r3, 0XE);
    // 0x8001C5E8: nop

    // 0x8001C5EC: beq         $fp, $t8, L_8001C5F8
    if (ctx->r30 == ctx->r24) {
        // 0x8001C5F0: nop
    
            goto L_8001C5F8;
    }
    // 0x8001C5F0: nop

    // 0x8001C5F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001C5F8:
    // 0x8001C5F8: bne         $s2, $s4, L_8001C614
    if (ctx->r18 != ctx->r20) {
        // 0x8001C5FC: nop
    
            goto L_8001C614;
    }
    // 0x8001C5FC: nop

    // 0x8001C600: lbu         $t9, 0x8($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X8);
    // 0x8001C604: nop

    // 0x8001C608: beq         $s5, $t9, L_8001C614
    if (ctx->r21 == ctx->r25) {
        // 0x8001C60C: nop
    
            goto L_8001C614;
    }
    // 0x8001C60C: nop

    // 0x8001C610: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001C614:
    // 0x8001C614: beq         $a0, $zero, L_8001C664
    if (ctx->r4 == 0) {
        // 0x8001C618: nop
    
            goto L_8001C664;
    }
    // 0x8001C618: nop

    // 0x8001C61C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C620: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C624: sub.s       $f0, $f4, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x8001C628: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C62C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001C630: sub.s       $f2, $f6, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x8001C634: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001C638: sub.s       $f14, $f8, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x8001C63C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001C640: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8001C644: jal         0x800C9AD0
    // 0x8001C648: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001C648: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_1:
    // 0x8001C64C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8001C650: nop

    // 0x8001C654: bc1f        L_8001C664
    if (!c1cs) {
        // 0x8001C658: nop
    
            goto L_8001C664;
    }
    // 0x8001C658: nop

    // 0x8001C65C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001C660: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
L_8001C664:
    // 0x8001C664: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001C668: bne         $s0, $s6, L_8001C5BC
    if (ctx->r16 != ctx->r22) {
        // 0x8001C66C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8001C5BC;
    }
    // 0x8001C66C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8001C670: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8001C674: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x8001C678: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8001C67C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001C680: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001C684: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8001C688: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001C68C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8001C690: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001C694: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8001C698: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001C69C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8001C6A0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8001C6A4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8001C6A8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8001C6AC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8001C6B0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8001C6B4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8001C6B8: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8001C6BC: jr          $ra
    // 0x8001C6C0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8001C6C0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void tt_menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DB3C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009DB40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DB44: jal         0x8006EA90
    // 0x8009DB48: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009DB48: nop

    after_0:
    // 0x8009DB4C: jal         0x8009EC80
    // 0x8009DB50: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    is_in_two_player_adventure(rdram, ctx);
        goto after_1;
    // 0x8009DB50: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x8009DB54: beq         $v0, $zero, L_8009DB74
    if (ctx->r2 == 0) {
        // 0x8009DB58: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009DB74;
    }
    // 0x8009DB58: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009DB5C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8009DB60: nop

    // 0x8009DB64: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8009DB68: nop

    // 0x8009DB6C: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8009DB70: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
L_8009DB74:
    // 0x8009DB74: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8009DB78: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8009DB7C: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8009DB80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DB84: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8009DB88: bne         $t9, $zero, L_8009DB94
    if (ctx->r25 != 0) {
        // 0x8009DB8C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009DB94;
    }
    // 0x8009DB8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DB90: sb          $t1, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r9;
L_8009DB94:
    // 0x8009DB94: lb          $v1, 0x64E2($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X64E2);
    // 0x8009DB98: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009DB9C: beq         $v1, $at, L_8009DBE8
    if (ctx->r3 == ctx->r1) {
        // 0x8009DBA0: addiu       $a1, $zero, 0x18
        ctx->r5 = ADD32(0, 0X18);
            goto L_8009DBE8;
    }
    // 0x8009DBA0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009DBA4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009DBA8: beq         $v1, $at, L_8009DBE8
    if (ctx->r3 == ctx->r1) {
        // 0x8009DBAC: addiu       $t2, $zero, 0x78
        ctx->r10 = ADD32(0, 0X78);
            goto L_8009DBE8;
    }
    // 0x8009DBAC: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x8009DBB0: jal         0x8001B780
    // 0x8009DBB4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    has_ghost_to_save(rdram, ctx);
        goto after_2;
    // 0x8009DBB4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_2:
    // 0x8009DBB8: beq         $v0, $zero, L_8009DBC8
    if (ctx->r2 == 0) {
        // 0x8009DBBC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009DBC8;
    }
    // 0x8009DBBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DBC0: addiu       $t3, $zero, 0x88
    ctx->r11 = ADD32(0, 0X88);
    // 0x8009DBC4: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_8009DBC8:
    // 0x8009DBC8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8009DBCC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009DBD0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009DBD4: addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    // 0x8009DBD8: jal         0x800C4EDC
    // 0x8009DBDC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_3;
    // 0x8009DBDC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x8009DBE0: b           L_8009DC00
    // 0x8009DBE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8009DC00;
    // 0x8009DBE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8009DBE8:
    // 0x8009DBE8: addiu       $t5, $zero, 0xDC
    ctx->r13 = ADD32(0, 0XDC);
    // 0x8009DBEC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009DBF0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009DBF4: jal         0x800C4EDC
    // 0x8009DBF8: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_4;
    // 0x8009DBF8: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_4:
    // 0x8009DBFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8009DC00:
    // 0x8009DC00: jal         0x800C4F7C
    // 0x8009DC04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_5;
    // 0x8009DC04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8009DC08: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8009DC0C: jal         0x8006A554
    // 0x8009DC10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_6;
    // 0x8009DC10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8009DC14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DC18: sb          $zero, 0x6504($at)
    MEM_B(0X6504, ctx->r1) = 0;
    // 0x8009DC1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009DC20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DC24: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8009DC28: addiu       $t0, $t0, 0x64E2
    ctx->r8 = ADD32(ctx->r8, 0X64E2);
    // 0x8009DC2C: sb          $t6, 0x650E($at)
    MEM_B(0X650E, ctx->r1) = ctx->r14;
    // 0x8009DC30: lb          $v1, 0x0($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X0);
    // 0x8009DC34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009DC38: sltiu       $at, $v1, 0xB
    ctx->r1 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8009DC3C: beq         $at, $zero, L_8009E37C
    if (ctx->r1 == 0) {
        // 0x8009DC40: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_8009E37C;
    }
    // 0x8009DC40: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8009DC44: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8009DC48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009DC4C: addu        $at, $at, $t7
    gpr jr_addend_8009DC58 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8009DC50: lw          $t7, -0x7A20($at)
    ctx->r15 = ADD32(ctx->r1, -0X7A20);
    // 0x8009DC54: nop

    // 0x8009DC58: jr          $t7
    // 0x8009DC5C: nop

    switch (jr_addend_8009DC58 >> 2) {
        case 0: goto L_8009DC60; break;
        case 1: goto L_8009DEF0; break;
        case 2: goto L_8009E37C; break;
        case 3: goto L_8009E37C; break;
        case 4: goto L_8009DFB0; break;
        case 5: goto L_8009DFEC; break;
        case 6: goto L_8009E098; break;
        case 7: goto L_8009E194; break;
        case 8: goto L_8009E23C; break;
        case 9: goto L_8009E37C; break;
        case 10: goto L_8009DC60; break;
        default: switch_error(__func__, 0x8009DC58, 0x800E85E0);
    }
    // 0x8009DC5C: nop

L_8009DC60:
    // 0x8009DC60: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009DC64: lw          $t8, -0xB60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB60);
    // 0x8009DC68: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009DC6C: lw          $a3, 0x90($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X90);
    // 0x8009DC70: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8009DC74: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8009DC78: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009DC7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DC80: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DC84: jal         0x800C5168
    // 0x8009DC88: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_7;
    // 0x8009DC88: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_7:
    // 0x8009DC8C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009DC90: lw          $t2, -0xB60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB60);
    // 0x8009DC94: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DC98: lw          $a0, 0x11C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X11C);
    // 0x8009DC9C: jal         0x8009D1B8
    // 0x8009DCA0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    render_dialogue_option(rdram, ctx);
        goto after_8;
    // 0x8009DCA0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x8009DCA4: jal         0x8009EC80
    // 0x8009DCA8: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_9;
    // 0x8009DCA8: nop

    after_9:
    // 0x8009DCAC: bne         $v0, $zero, L_8009DD1C
    if (ctx->r2 != 0) {
        // 0x8009DCB0: nop
    
            goto L_8009DD1C;
    }
    // 0x8009DCB0: nop

    // 0x8009DCB4: jal         0x8000E4C8
    // 0x8009DCB8: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_10;
    // 0x8009DCB8: nop

    after_10:
    // 0x8009DCBC: beq         $v0, $zero, L_8009DCE4
    if (ctx->r2 == 0) {
        // 0x8009DCC0: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8009DCE4;
    }
    // 0x8009DCC0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009DCC4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009DCC8: lw          $t3, -0xB60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XB60);
    // 0x8009DCCC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DCD0: lw          $a0, 0x104($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X104);
    // 0x8009DCD4: jal         0x8009D1B8
    // 0x8009DCD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_11;
    // 0x8009DCD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8009DCDC: b           L_8009DCF8
    // 0x8009DCE0: nop

        goto L_8009DCF8;
    // 0x8009DCE0: nop

L_8009DCE4:
    // 0x8009DCE4: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x8009DCE8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DCEC: lw          $a0, 0x108($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X108);
    // 0x8009DCF0: jal         0x8009D1B8
    // 0x8009DCF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_12;
    // 0x8009DCF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
L_8009DCF8:
    // 0x8009DCF8: jal         0x8001B780
    // 0x8009DCFC: nop

    has_ghost_to_save(rdram, ctx);
        goto after_13;
    // 0x8009DCFC: nop

    after_13:
    // 0x8009DD00: beq         $v0, $zero, L_8009DD1C
    if (ctx->r2 == 0) {
        // 0x8009DD04: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8009DD1C;
    }
    // 0x8009DD04: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009DD08: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x8009DD0C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DD10: lw          $a0, 0x6C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X6C);
    // 0x8009DD14: jal         0x8009D1B8
    // 0x8009DD18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_14;
    // 0x8009DD18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
L_8009DD1C:
    // 0x8009DD1C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009DD20: lw          $t6, -0xB60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB60);
    // 0x8009DD24: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DD28: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x8009DD2C: jal         0x8009D1B8
    // 0x8009DD30: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_15;
    // 0x8009DD30: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_15:
    // 0x8009DD34: jal         0x8009D26C
    // 0x8009DD38: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_16;
    // 0x8009DD38: nop

    after_16:
    // 0x8009DD3C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009DD40: lb          $t7, 0x6516($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6516);
    // 0x8009DD44: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009DD48: bne         $t7, $zero, L_8009DDB8
    if (ctx->r15 != 0) {
        // 0x8009DD4C: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_8009DDB8;
    }
    // 0x8009DD4C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8009DD50: lb          $v0, 0x645C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X645C);
    // 0x8009DD54: nop

    // 0x8009DD58: blez        $v0, L_8009DD88
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009DD5C: nop
    
            goto L_8009DD88;
    }
    // 0x8009DD5C: nop

    // 0x8009DD60: jal         0x8000E4C8
    // 0x8009DD64: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_17;
    // 0x8009DD64: nop

    after_17:
    // 0x8009DD68: bne         $v0, $zero, L_8009DD78
    if (ctx->r2 != 0) {
        // 0x8009DD6C: addiu       $a0, $zero, 0x231
        ctx->r4 = ADD32(0, 0X231);
            goto L_8009DD78;
    }
    // 0x8009DD6C: addiu       $a0, $zero, 0x231
    ctx->r4 = ADD32(0, 0X231);
    // 0x8009DD70: jal         0x80036BCC
    // 0x8009DD74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_18;
    // 0x8009DD74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
L_8009DD78:
    // 0x8009DD78: jal         0x8000E4BC
    // 0x8009DD7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_time_trial_enabled(rdram, ctx);
        goto after_19;
    // 0x8009DD7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x8009DD80: b           L_8009DDB8
    // 0x8009DD84: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_8009DDB8;
    // 0x8009DD84: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8009DD88:
    // 0x8009DD88: bgez        $v0, L_8009DDB8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009DD8C: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_8009DDB8;
    }
    // 0x8009DD8C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8009DD90: jal         0x8000E4C8
    // 0x8009DD94: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_20;
    // 0x8009DD94: nop

    after_20:
    // 0x8009DD98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009DD9C: bne         $v0, $at, L_8009DDAC
    if (ctx->r2 != ctx->r1) {
        // 0x8009DDA0: addiu       $a0, $zero, 0x230
        ctx->r4 = ADD32(0, 0X230);
            goto L_8009DDAC;
    }
    // 0x8009DDA0: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    // 0x8009DDA4: jal         0x80036BCC
    // 0x8009DDA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_21;
    // 0x8009DDA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
L_8009DDAC:
    // 0x8009DDAC: jal         0x8000E4BC
    // 0x8009DDB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_time_trial_enabled(rdram, ctx);
        goto after_22;
    // 0x8009DDB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x8009DDB4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8009DDB8:
    // 0x8009DDB8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8009DDBC: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8009DDC0: beq         $t9, $zero, L_8009DE8C
    if (ctx->r25 == 0) {
        // 0x8009DDC4: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8009DE8C;
    }
    // 0x8009DDC4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009DDC8: lb          $t1, 0x64E2($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X64E2);
    // 0x8009DDCC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8009DDD0: beq         $t1, $at, L_8009DE8C
    if (ctx->r9 == ctx->r1) {
        // 0x8009DDD4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009DE8C;
    }
    // 0x8009DDD4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009DDD8: lb          $v1, 0x6516($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6516);
    // 0x8009DDDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009DDE0: beq         $v1, $at, L_8009DDFC
    if (ctx->r3 == ctx->r1) {
        // 0x8009DDE4: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009DDFC;
    }
    // 0x8009DDE4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009DDE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009DDEC: beq         $v1, $at, L_8009DE34
    if (ctx->r3 == ctx->r1) {
        // 0x8009DDF0: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009DE34;
    }
    // 0x8009DDF0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009DDF4: b           L_8009DE84
    // 0x8009DDF8: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
        goto L_8009DE84;
    // 0x8009DDF8: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
L_8009DDFC:
    // 0x8009DDFC: jal         0x80001D04
    // 0x8009DE00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x8009DE00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x8009DE04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009DE08: addiu       $a0, $a0, 0x6398
    ctx->r4 = ADD32(ctx->r4, 0X6398);
    // 0x8009DE0C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8009DE10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE14: sw          $zero, 0x639C($at)
    MEM_W(0X639C, ctx->r1) = 0;
    // 0x8009DE18: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009DE1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE20: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8009DE24: lb          $v1, 0x6516($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6516);
    // 0x8009DE28: b           L_8009DE80
    // 0x8009DE2C: sb          $t2, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r10;
        goto L_8009DE80;
    // 0x8009DE2C: sb          $t2, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r10;
    // 0x8009DE30: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
L_8009DE34:
    // 0x8009DE34: jal         0x80001D04
    // 0x8009DE38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_24;
    // 0x8009DE38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x8009DE3C: addiu       $a0, $zero, 0x22E
    ctx->r4 = ADD32(0, 0X22E);
    // 0x8009DE40: jal         0x80036BCC
    // 0x8009DE44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_25;
    // 0x8009DE44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x8009DE48: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009DE4C: jal         0x8009C674
    // 0x8009DE50: addiu       $a0, $a0, 0x1E2C
    ctx->r4 = ADD32(ctx->r4, 0X1E2C);
    menu_assetgroup_load(rdram, ctx);
        goto after_26;
    // 0x8009DE50: addiu       $a0, $a0, 0x1E2C
    ctx->r4 = ADD32(ctx->r4, 0X1E2C);
    after_26:
    // 0x8009DE54: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009DE58: jal         0x8009C8A4
    // 0x8009DE5C: addiu       $a0, $a0, 0x1E40
    ctx->r4 = ADD32(ctx->r4, 0X1E40);
    menu_imagegroup_load(rdram, ctx);
        goto after_27;
    // 0x8009DE5C: addiu       $a0, $a0, 0x1E40
    ctx->r4 = ADD32(ctx->r4, 0X1E40);
    after_27:
    // 0x8009DE60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8009DE64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DE68: sb          $t3, 0x1E28($at)
    MEM_B(0X1E28, ctx->r1) = ctx->r11;
    // 0x8009DE6C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009DE70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DE74: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8009DE78: lb          $v1, 0x6516($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6516);
    // 0x8009DE7C: sb          $t4, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r12;
L_8009DE80:
    // 0x8009DE80: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
L_8009DE84:
    // 0x8009DE84: b           L_8009DEA8
    // 0x8009DE88: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
        goto L_8009DEA8;
    // 0x8009DE88: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_8009DE8C:
    // 0x8009DE8C: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8009DE90: beq         $t7, $zero, L_8009DEA8
    if (ctx->r15 == 0) {
        // 0x8009DE94: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8009DEA8;
    }
    // 0x8009DE94: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009DE98: jal         0x80001D04
    // 0x8009DE9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_28;
    // 0x8009DE9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x8009DEA0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009DEA4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_8009DEA8:
    // 0x8009DEA8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009DEAC: lb          $v1, 0x64E2($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X64E2);
    // 0x8009DEB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009DEB4: bne         $v1, $at, L_8009DEC0
    if (ctx->r3 != ctx->r1) {
        // 0x8009DEB8: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_8009DEC0;
    }
    // 0x8009DEB8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8009DEBC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8009DEC0:
    // 0x8009DEC0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8009DEC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009DEC8: bne         $t9, $at, L_8009DEDC
    if (ctx->r25 != ctx->r1) {
        // 0x8009DECC: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8009DEDC;
    }
    // 0x8009DECC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8009DED0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DED4: sb          $t1, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r9;
    // 0x8009DED8: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_8009DEDC:
    // 0x8009DEDC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8009DEE0: bne         $v1, $at, L_8009E380
    if (ctx->r3 != ctx->r1) {
        // 0x8009DEE4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8009E380;
    }
    // 0x8009DEE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009DEE8: b           L_8009E37C
    // 0x8009DEEC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_8009E37C;
    // 0x8009DEEC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_8009DEF0:
    // 0x8009DEF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009DEF4: lw          $a0, 0x63A4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X63A4);
    // 0x8009DEF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009DEFC: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8009DF00: addiu       $t6, $zero, 0x3A
    ctx->r14 = ADD32(0, 0X3A);
    // 0x8009DF04: beq         $a1, $zero, L_8009DF1C
    if (ctx->r5 == 0) {
        // 0x8009DF08: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8009DF1C;
    }
    // 0x8009DF08: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8009DF0C:
    // 0x8009DF0C: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8009DF10: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009DF14: bne         $t3, $zero, L_8009DF0C
    if (ctx->r11 != 0) {
        // 0x8009DF18: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8009DF0C;
    }
    // 0x8009DF18: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8009DF1C:
    // 0x8009DF1C: blez        $v1, L_8009DF8C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009DF20: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8009DF8C;
    }
    // 0x8009DF20: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8009DF24: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8009DF28: beq         $a1, $zero, L_8009DF8C
    if (ctx->r5 == 0) {
        // 0x8009DF2C: subu        $a2, $t6, $t5
        ctx->r6 = SUB32(ctx->r14, ctx->r13);
            goto L_8009DF8C;
    }
    // 0x8009DF2C: subu        $a2, $t6, $t5
    ctx->r6 = SUB32(ctx->r14, ctx->r13);
    // 0x8009DF30: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8009DF34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009DF38: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_8009DF3C:
    // 0x8009DF3C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009DF40: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009DF44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009DF48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DF4C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DF50: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8009DF54: jal         0x800C5168
    // 0x8009DF58: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    render_dialogue_text(rdram, ctx);
        goto after_29;
    // 0x8009DF58: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_29:
    // 0x8009DF5C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009DF60: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009DF64: lw          $t9, 0x63A4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X63A4);
    // 0x8009DF68: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009DF6C: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x8009DF70: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8009DF74: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x8009DF78: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8009DF7C: bne         $a3, $zero, L_8009DF3C
    if (ctx->r7 != 0) {
        // 0x8009DF80: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8009DF3C;
    }
    // 0x8009DF80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009DF84: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009DF88: addiu       $t0, $t0, 0x64E2
    ctx->r8 = ADD32(ctx->r8, 0X64E2);
L_8009DF8C:
    // 0x8009DF8C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8009DF90: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009DF94: andi        $t3, $t2, 0xC000
    ctx->r11 = ctx->r10 & 0XC000;
    // 0x8009DF98: beq         $t3, $zero, L_8009DFA4
    if (ctx->r11 == 0) {
        // 0x8009DF9C: nop
    
            goto L_8009DFA4;
    }
    // 0x8009DF9C: nop

    // 0x8009DFA0: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_8009DFA4:
    // 0x8009DFA4: lb          $v1, 0x64E2($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X64E2);
    // 0x8009DFA8: b           L_8009E380
    // 0x8009DFAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E380;
    // 0x8009DFAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009DFB0:
    // 0x8009DFB0: andi        $t4, $a0, 0xC000
    ctx->r12 = ctx->r4 & 0XC000;
    // 0x8009DFB4: beq         $t4, $zero, L_8009E37C
    if (ctx->r12 == 0) {
        // 0x8009DFB8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8009E37C;
    }
    // 0x8009DFB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DFBC: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8009DFC0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009DFC4: sb          $zero, 0x1E28($at)
    MEM_B(0X1E28, ctx->r1) = 0;
    // 0x8009DFC8: jal         0x8009C4A8
    // 0x8009DFCC: addiu       $a0, $a0, 0x1E2C
    ctx->r4 = ADD32(ctx->r4, 0X1E2C);
    menu_assetgroup_free(rdram, ctx);
        goto after_30;
    // 0x8009DFCC: addiu       $a0, $a0, 0x1E2C
    ctx->r4 = ADD32(ctx->r4, 0X1E2C);
    after_30:
    // 0x8009DFD0: addiu       $a0, $zero, 0x22F
    ctx->r4 = ADD32(0, 0X22F);
    // 0x8009DFD4: jal         0x80036BCC
    // 0x8009DFD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_31;
    // 0x8009DFD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x8009DFDC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009DFE0: lb          $v1, 0x64E2($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X64E2);
    // 0x8009DFE4: b           L_8009E380
    // 0x8009DFE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E380;
    // 0x8009DFE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009DFEC:
    // 0x8009DFEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009DFF0: lw          $v0, -0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB60);
    // 0x8009DFF4: addiu       $v1, $zero, 0xD0
    ctx->r3 = ADD32(0, 0XD0);
    // 0x8009DFF8: lw          $t6, 0xD0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD0);
    // 0x8009DFFC: nop

    // 0x8009E000: beq         $t6, $zero, L_8009E068
    if (ctx->r14 == 0) {
        // 0x8009E004: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_8009E068;
    }
    // 0x8009E004: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8009E008: lw          $a3, 0xD0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XD0);
    // 0x8009E00C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8009E010: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8009E014:
    // 0x8009E014: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8009E018: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009E01C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009E020: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E024: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E028: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8009E02C: jal         0x800C5168
    // 0x8009E030: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    render_dialogue_text(rdram, ctx);
        goto after_32;
    // 0x8009E030: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_32:
    // 0x8009E034: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009E038: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009E03C: lw          $t8, -0xB60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB60);
    // 0x8009E040: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009E044: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009E048: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8009E04C: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8009E050: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8009E054: bne         $a3, $zero, L_8009E014
    if (ctx->r7 != 0) {
        // 0x8009E058: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8009E014;
    }
    // 0x8009E058: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009E05C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009E060: addiu       $t0, $t0, 0x64E2
    ctx->r8 = ADD32(ctx->r8, 0X64E2);
    // 0x8009E064: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
L_8009E068:
    // 0x8009E068: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8009E06C: andi        $t2, $t1, 0xC000
    ctx->r10 = ctx->r9 & 0XC000;
    // 0x8009E070: beq         $t2, $zero, L_8009E08C
    if (ctx->r10 == 0) {
        // 0x8009E074: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E08C;
    }
    // 0x8009E074: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E078: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8009E07C: nop

    // 0x8009E080: ori         $t6, $t4, 0x2
    ctx->r14 = ctx->r12 | 0X2;
    // 0x8009E084: sw          $t6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r14;
    // 0x8009E088: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_8009E08C:
    // 0x8009E08C: lb          $v1, 0x64E2($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X64E2);
    // 0x8009E090: b           L_8009E380
    // 0x8009E094: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E380;
    // 0x8009E094: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E098:
    // 0x8009E098: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E09C: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x8009E0A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009E0A4: lw          $a3, 0x27C($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X27C);
    // 0x8009E0A8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009E0AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009E0B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009E0B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E0B8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E0BC: jal         0x800C5168
    // 0x8009E0C0: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    render_dialogue_text(rdram, ctx);
        goto after_33;
    // 0x8009E0C0: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_33:
    // 0x8009E0C4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009E0C8: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x8009E0CC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009E0D0: lw          $a3, 0x280($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X280);
    // 0x8009E0D4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009E0D8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009E0DC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009E0E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E0E4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E0E8: jal         0x800C5168
    // 0x8009E0EC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_34;
    // 0x8009E0EC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_34:
    // 0x8009E0F0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009E0F4: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x8009E0F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009E0FC: lw          $a3, 0x288($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X288);
    // 0x8009E100: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8009E104: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8009E108: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009E10C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E110: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E114: jal         0x800C5168
    // 0x8009E118: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    render_dialogue_text(rdram, ctx);
        goto after_35;
    // 0x8009E118: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    after_35:
    // 0x8009E11C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8009E120: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009E124: andi        $t7, $t5, 0x9000
    ctx->r15 = ctx->r13 & 0X9000;
    // 0x8009E128: beq         $t7, $zero, L_8009E164
    if (ctx->r15 == 0) {
        // 0x8009E12C: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_8009E164;
    }
    // 0x8009E12C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8009E130: jal         0x80001D04
    // 0x8009E134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_36;
    // 0x8009E134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
    // 0x8009E138: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E13C: addiu       $a0, $a0, 0x6398
    ctx->r4 = ADD32(ctx->r4, 0X6398);
    // 0x8009E140: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8009E144: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8009E148: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E14C: sw          $t8, 0x639C($at)
    MEM_W(0X639C, ctx->r1) = ctx->r24;
    // 0x8009E150: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E154: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8009E158: b           L_8009E184
    // 0x8009E15C: sb          $t9, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r25;
        goto L_8009E184;
    // 0x8009E15C: sb          $t9, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r25;
    // 0x8009E160: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
L_8009E164:
    // 0x8009E164: nop

    // 0x8009E168: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8009E16C: beq         $t2, $zero, L_8009E184
    if (ctx->r10 == 0) {
        // 0x8009E170: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8009E184;
    }
    // 0x8009E170: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009E174: jal         0x80001D04
    // 0x8009E178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_37;
    // 0x8009E178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x8009E17C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E180: sb          $zero, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = 0;
L_8009E184:
    // 0x8009E184: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E188: lb          $v1, 0x64E2($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X64E2);
    // 0x8009E18C: b           L_8009E380
    // 0x8009E190: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E380;
    // 0x8009E190: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E194:
    // 0x8009E194: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009E198: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x8009E19C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009E1A0: lw          $a3, 0x27C($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X27C);
    // 0x8009E1A4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8009E1A8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8009E1AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009E1B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E1B4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E1B8: jal         0x800C5168
    // 0x8009E1BC: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    render_dialogue_text(rdram, ctx);
        goto after_38;
    // 0x8009E1BC: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_38:
    // 0x8009E1C0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E1C4: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x8009E1C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009E1CC: lw          $a3, 0x284($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X284);
    // 0x8009E1D0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009E1D4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009E1D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009E1DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E1E0: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E1E4: jal         0x800C5168
    // 0x8009E1E8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_39;
    // 0x8009E1E8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_39:
    // 0x8009E1EC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009E1F0: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x8009E1F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009E1F8: lw          $a3, 0x288($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X288);
    // 0x8009E1FC: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009E200: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009E204: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009E208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E20C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E210: jal         0x800C5168
    // 0x8009E214: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    render_dialogue_text(rdram, ctx);
        goto after_40;
    // 0x8009E214: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    after_40:
    // 0x8009E218: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8009E21C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E220: andi        $t6, $t4, 0xD000
    ctx->r14 = ctx->r12 & 0XD000;
    // 0x8009E224: beq         $t6, $zero, L_8009E230
    if (ctx->r14 == 0) {
        // 0x8009E228: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E230;
    }
    // 0x8009E228: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E22C: sb          $zero, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = 0;
L_8009E230:
    // 0x8009E230: lb          $v1, 0x64E2($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X64E2);
    // 0x8009E234: b           L_8009E380
    // 0x8009E238: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E380;
    // 0x8009E238: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E23C:
    // 0x8009E23C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009E240: lw          $t3, -0xB60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XB60);
    // 0x8009E244: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009E248: lw          $a3, 0x1F0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X1F0);
    // 0x8009E24C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8009E250: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009E254: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009E258: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E25C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E260: jal         0x800C5168
    // 0x8009E264: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_41;
    // 0x8009E264: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_41:
    // 0x8009E268: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E26C: addiu       $a0, $a0, 0x6398
    ctx->r4 = ADD32(ctx->r4, 0X6398);
    // 0x8009E270: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8009E274: nop

    // 0x8009E278: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8009E27C: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x8009E280: bne         $at, $zero, L_8009E370
    if (ctx->r1 != 0) {
        // 0x8009E284: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_8009E370;
    }
    // 0x8009E284: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009E288: jal         0x8001B738
    // 0x8009E28C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_save_player_ghost(rdram, ctx);
        goto after_42;
    // 0x8009E28C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_42:
    // 0x8009E290: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8009E294: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009E298: bne         $v1, $at, L_8009E2B0
    if (ctx->r3 != ctx->r1) {
        // 0x8009E29C: sltiu       $at, $v1, 0xA
        ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
            goto L_8009E2B0;
    }
    // 0x8009E29C: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    // 0x8009E2A0: jal         0x8001B738
    // 0x8009E2A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_save_player_ghost(rdram, ctx);
        goto after_43;
    // 0x8009E2A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_43:
    // 0x8009E2A8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8009E2AC: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
L_8009E2B0:
    // 0x8009E2B0: beq         $at, $zero, L_8009E354
    if (ctx->r1 == 0) {
        // 0x8009E2B4: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8009E354;
    }
    // 0x8009E2B4: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8009E2B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009E2BC: addu        $at, $at, $t2
    gpr jr_addend_8009E2C8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8009E2C0: lw          $t2, -0x79F4($at)
    ctx->r10 = ADD32(ctx->r1, -0X79F4);
    // 0x8009E2C4: nop

    // 0x8009E2C8: jr          $t2
    // 0x8009E2CC: nop

    switch (jr_addend_8009E2C8 >> 2) {
        case 0: goto L_8009E2D0; break;
        case 1: goto L_8009E2F4; break;
        case 2: goto L_8009E354; break;
        case 3: goto L_8009E354; break;
        case 4: goto L_8009E314; break;
        case 5: goto L_8009E354; break;
        case 6: goto L_8009E314; break;
        case 7: goto L_8009E2E4; break;
        case 8: goto L_8009E354; break;
        case 9: goto L_8009E334; break;
        default: switch_error(__func__, 0x8009E2C8, 0x800E860C);
    }
    // 0x8009E2CC: nop

L_8009E2D0:
    // 0x8009E2D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009E2D4: lw          $t4, 0x639C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X639C);
    // 0x8009E2D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E2DC: b           L_8009E370
    // 0x8009E2E0: sb          $t4, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r12;
        goto L_8009E370;
    // 0x8009E2E0: sb          $t4, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r12;
L_8009E2E4:
    // 0x8009E2E4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8009E2E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E2EC: b           L_8009E370
    // 0x8009E2F0: sb          $t6, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r14;
        goto L_8009E370;
    // 0x8009E2F0: sb          $t6, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r14;
L_8009E2F4:
    // 0x8009E2F4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009E2F8: addiu       $t3, $t3, 0x9D8
    ctx->r11 = ADD32(ctx->r11, 0X9D8);
    // 0x8009E2FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E300: sw          $t3, 0x63A4($at)
    MEM_W(0X63A4, ctx->r1) = ctx->r11;
    // 0x8009E304: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E308: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009E30C: b           L_8009E370
    // 0x8009E310: sb          $t5, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r13;
        goto L_8009E370;
    // 0x8009E310: sb          $t5, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r13;
L_8009E314:
    // 0x8009E314: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009E318: addiu       $t7, $t7, 0x9C4
    ctx->r15 = ADD32(ctx->r15, 0X9C4);
    // 0x8009E31C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E320: sw          $t7, 0x63A4($at)
    MEM_W(0X63A4, ctx->r1) = ctx->r15;
    // 0x8009E324: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E328: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009E32C: b           L_8009E370
    // 0x8009E330: sb          $t8, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r24;
        goto L_8009E370;
    // 0x8009E330: sb          $t8, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r24;
L_8009E334:
    // 0x8009E334: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009E338: addiu       $t9, $t9, 0x9EC
    ctx->r25 = ADD32(ctx->r25, 0X9EC);
    // 0x8009E33C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E340: sw          $t9, 0x63A4($at)
    MEM_W(0X63A4, ctx->r1) = ctx->r25;
    // 0x8009E344: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E348: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009E34C: b           L_8009E370
    // 0x8009E350: sb          $t1, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r9;
        goto L_8009E370;
    // 0x8009E350: sb          $t1, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r9;
L_8009E354:
    // 0x8009E354: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009E358: addiu       $t2, $t2, 0x9B0
    ctx->r10 = ADD32(ctx->r10, 0X9B0);
    // 0x8009E35C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E360: sw          $t2, 0x63A4($at)
    MEM_W(0X63A4, ctx->r1) = ctx->r10;
    // 0x8009E364: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E368: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009E36C: sb          $t4, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r12;
L_8009E370:
    // 0x8009E370: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E374: lb          $v1, 0x64E2($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X64E2);
    // 0x8009E378: nop

L_8009E37C:
    // 0x8009E37C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E380:
    // 0x8009E380: beq         $v1, $at, L_8009E398
    if (ctx->r3 == ctx->r1) {
        // 0x8009E384: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009E398;
    }
    // 0x8009E384: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E388: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009E38C: beq         $v1, $at, L_8009E398
    if (ctx->r3 == ctx->r1) {
        // 0x8009E390: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8009E398;
    }
    // 0x8009E390: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009E394: bne         $v1, $at, L_8009E3C0
    if (ctx->r3 != ctx->r1) {
        // 0x8009E398: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_8009E3C0;
    }
L_8009E398:
    // 0x8009E398: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009E39C: lw          $t6, -0xB60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB60);
    // 0x8009E3A0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8009E3A4: lw          $a3, 0x100($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X100);
    // 0x8009E3A8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8009E3AC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009E3B0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009E3B4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E3B8: jal         0x800C5168
    // 0x8009E3BC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_44;
    // 0x8009E3BC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_44:
L_8009E3C0:
    // 0x8009E3C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E3C4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8009E3C8: jr          $ra
    // 0x8009E3CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8009E3CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alLoadParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB544: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CB548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB54C: beq         $a1, $at, L_800CB6A4
    if (ctx->r5 == ctx->r1) {
        // 0x800CB550: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800CB6A4;
    }
    // 0x800CB550: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CB554: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800CB558: bnel        $a1, $at, L_800CB708
    if (ctx->r5 != ctx->r1) {
        // 0x800CB55C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CB708;
    }
    goto skip_0;
    // 0x800CB55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CB560: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x800CB564: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800CB568: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x800CB56C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CB570: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x800CB574: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x800CB578: beql        $v0, $zero, L_800CB598
    if (ctx->r2 == 0) {
        // 0x800CB57C: lw          $v0, 0x28($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X28);
            goto L_800CB598;
    }
    goto skip_1;
    // 0x800CB57C: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    skip_1:
    // 0x800CB580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CB584: beq         $v0, $a0, L_800CB658
    if (ctx->r2 == ctx->r4) {
        // 0x800CB588: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_800CB658;
    }
    // 0x800CB588: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CB58C: b           L_800CB708
    // 0x800CB590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CB708;
    // 0x800CB590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB594: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
L_800CB598:
    // 0x800CB598: addiu       $t7, $t7, -0x4414
    ctx->r15 = ADD32(ctx->r15, -0X4414);
    // 0x800CB59C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800CB5A0: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800CB5A4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CB5A8: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x800CB5AC: mflo        $t9
    ctx->r25 = lo;
    // 0x800CB5B0: bne         $a1, $zero, L_800CB5BC
    if (ctx->r5 != 0) {
        // 0x800CB5B4: nop
    
            goto L_800CB5BC;
    }
    // 0x800CB5B4: nop

    // 0x800CB5B8: break       7
    do_break(2148316600);
L_800CB5BC:
    // 0x800CB5BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CB5C0: bne         $a1, $at, L_800CB5D4
    if (ctx->r5 != ctx->r1) {
        // 0x800CB5C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CB5D4;
    }
    // 0x800CB5C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CB5C8: bne         $t8, $at, L_800CB5D4
    if (ctx->r24 != ctx->r1) {
        // 0x800CB5CC: nop
    
            goto L_800CB5D4;
    }
    // 0x800CB5CC: nop

    // 0x800CB5D0: break       6
    do_break(2148316624);
L_800CB5D4:
    // 0x800CB5D4: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CB5D8: mflo        $t0
    ctx->r8 = lo;
    // 0x800CB5DC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800CB5E0: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800CB5E4: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800CB5E8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800CB5EC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x800CB5F0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800CB5F4: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CB5F8: mflo        $t4
    ctx->r12 = lo;
    // 0x800CB5FC: sw          $t4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r12;
    // 0x800CB600: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CB604: beql        $v1, $zero, L_800CB64C
    if (ctx->r3 == 0) {
        // 0x800CB608: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800CB64C;
    }
    goto skip_2;
    // 0x800CB608: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_2:
    // 0x800CB60C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800CB610: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x800CB614: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800CB618: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
    // 0x800CB61C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800CB620: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800CB624: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x800CB628: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800CB62C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800CB630: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
    // 0x800CB634: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800CB638: jal         0x800D3820
    // 0x800CB63C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    alCopy(rdram, ctx);
        goto after_0;
    // 0x800CB63C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800CB640: b           L_800CB708
    // 0x800CB644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CB708;
    // 0x800CB644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB648: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800CB64C:
    // 0x800CB64C: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800CB650: b           L_800CB704
    // 0x800CB654: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800CB704;
    // 0x800CB654: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800CB658:
    // 0x800CB658: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800CB65C: addiu       $t0, $t0, -0x48EC
    ctx->r8 = ADD32(ctx->r8, -0X48EC);
    // 0x800CB660: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x800CB664: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CB668: beql        $v1, $zero, L_800CB698
    if (ctx->r3 == 0) {
        // 0x800CB66C: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800CB698;
    }
    goto skip_3;
    // 0x800CB66C: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_3:
    // 0x800CB670: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800CB674: sw          $t1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r9;
    // 0x800CB678: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800CB67C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800CB680: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x800CB684: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800CB688: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800CB68C: b           L_800CB704
    // 0x800CB690: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
        goto L_800CB704;
    // 0x800CB690: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
    // 0x800CB694: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800CB698:
    // 0x800CB698: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800CB69C: b           L_800CB704
    // 0x800CB6A0: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800CB704;
    // 0x800CB6A0: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800CB6A4:
    // 0x800CB6A4: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800CB6A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CB6AC: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x800CB6B0: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x800CB6B4: beq         $v0, $zero, L_800CB704
    if (ctx->r2 == 0) {
        // 0x800CB6B8: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_800CB704;
    }
    // 0x800CB6B8: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800CB6BC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800CB6C0: sw          $t6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r14;
    // 0x800CB6C4: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x800CB6C8: bne         $v1, $zero, L_800CB6E8
    if (ctx->r3 != 0) {
        // 0x800CB6CC: nop
    
            goto L_800CB6E8;
    }
    // 0x800CB6CC: nop

    // 0x800CB6D0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CB6D4: beql        $v1, $zero, L_800CB708
    if (ctx->r3 == 0) {
        // 0x800CB6D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CB708;
    }
    goto skip_4;
    // 0x800CB6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800CB6DC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800CB6E0: b           L_800CB704
    // 0x800CB6E4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
        goto L_800CB704;
    // 0x800CB6E4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
L_800CB6E8:
    // 0x800CB6E8: bnel        $a0, $v1, L_800CB708
    if (ctx->r4 != ctx->r3) {
        // 0x800CB6EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CB708;
    }
    goto skip_5;
    // 0x800CB6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800CB6F0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CB6F4: beql        $v1, $zero, L_800CB708
    if (ctx->r3 == 0) {
        // 0x800CB6F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CB708;
    }
    goto skip_6;
    // 0x800CB6F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x800CB6FC: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800CB700: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
L_800CB704:
    // 0x800CB704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CB708:
    // 0x800CB708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB70C: jr          $ra
    // 0x800CB710: nop

    return;
    // 0x800CB710: nop

;}
RECOMP_FUNC void transition_init_circle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C15D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C15D8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C15DC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C15E0: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800C15E4: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800C15E8: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800C15EC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800C15F0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800C15F4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C15F8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C15FC: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C1600: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C1604: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C1608: jal         0x80070C9C
    // 0x800C160C: addiu       $a0, $zero, 0xDA0
    ctx->r4 = ADD32(0, 0XDA0);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C160C: addiu       $a0, $zero, 0xDA0
    ctx->r4 = ADD32(0, 0XDA0);
    after_0:
    // 0x800C1610: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C1614: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C1618: addiu       $t7, $v0, 0x2D0
    ctx->r15 = ADD32(ctx->r2, 0X2D0);
    // 0x800C161C: addiu       $a1, $a1, 0x31C8
    ctx->r5 = ADD32(ctx->r5, 0X31C8);
    // 0x800C1620: addiu       $a0, $a0, 0x31C0
    ctx->r4 = ADD32(ctx->r4, 0X31C0);
    // 0x800C1624: addiu       $t9, $t7, 0x2D0
    ctx->r25 = ADD32(ctx->r15, 0X2D0);
    // 0x800C1628: addiu       $t5, $t9, 0x400
    ctx->r13 = ADD32(ctx->r25, 0X400);
    // 0x800C162C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C1630: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800C1634: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800C1638: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800C163C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C1640: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C1644: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1648: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C164C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C1650: addiu       $a2, $a2, -0x58CA
    ctx->r6 = ADD32(ctx->r6, -0X58CA);
    // 0x800C1654: addiu       $t2, $t2, 0x31C8
    ctx->r10 = ADD32(ctx->r10, 0X31C8);
    // 0x800C1658: addiu       $v1, $v1, 0x31C0
    ctx->r3 = ADD32(ctx->r3, 0X31C0);
    // 0x800C165C: addiu       $a0, $a0, -0x58CC
    ctx->r4 = ADD32(ctx->r4, -0X58CC);
    // 0x800C1660: addiu       $a1, $a1, -0x58CB
    ctx->r5 = ADD32(ctx->r5, -0X58CB);
    // 0x800C1664: addiu       $t1, $zero, 0x2D0
    ctx->r9 = ADD32(0, 0X2D0);
    // 0x800C1668: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800C166C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C1670:
    // 0x800C1670: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1674: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1678: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C167C: sb          $t6, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r14;
    // 0x800C1680: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1684: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1688: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C168C: sb          $t9, 0x7($t5)
    MEM_B(0X7, ctx->r13) = ctx->r25;
    // 0x800C1690: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1694: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1698: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800C169C: sb          $t7, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r15;
    // 0x800C16A0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C16A4: nop

    // 0x800C16A8: addu        $t9, $t4, $v0
    ctx->r25 = ADD32(ctx->r12, ctx->r2);
    // 0x800C16AC: sb          $t0, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r8;
    // 0x800C16B0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C16B4: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800C16B8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C16BC: sb          $t5, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r13;
    // 0x800C16C0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C16C4: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800C16C8: addu        $t9, $t4, $v0
    ctx->r25 = ADD32(ctx->r12, ctx->r2);
    // 0x800C16CC: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800C16D0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C16D4: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800C16D8: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800C16DC: sb          $t6, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r14;
    // 0x800C16E0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C16E4: nop

    // 0x800C16E8: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800C16EC: sb          $t0, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r8;
    // 0x800C16F0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C16F4: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800C16F8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C16FC: sb          $t9, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r25;
    // 0x800C1700: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1704: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1708: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800C170C: sb          $t7, 0x1B($t8)
    MEM_B(0X1B, ctx->r24) = ctx->r15;
    // 0x800C1710: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1714: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1718: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800C171C: sb          $t5, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r13;
    // 0x800C1720: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1724: nop

    // 0x800C1728: addu        $t7, $t4, $v0
    ctx->r15 = ADD32(ctx->r12, ctx->r2);
    // 0x800C172C: sb          $t0, 0x1D($t7)
    MEM_B(0X1D, ctx->r15) = ctx->r8;
    // 0x800C1730: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1734: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1738: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C173C: sb          $t8, 0x24($t5)
    MEM_B(0X24, ctx->r13) = ctx->r24;
    // 0x800C1740: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1744: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1748: addu        $t7, $t4, $v0
    ctx->r15 = ADD32(ctx->r12, ctx->r2);
    // 0x800C174C: sb          $t6, 0x25($t7)
    MEM_B(0X25, ctx->r15) = ctx->r14;
    // 0x800C1750: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C1754: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1758: addu        $t5, $t8, $v0
    ctx->r13 = ADD32(ctx->r24, ctx->r2);
    // 0x800C175C: sb          $t9, 0x26($t5)
    MEM_B(0X26, ctx->r13) = ctx->r25;
    // 0x800C1760: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1764: nop

    // 0x800C1768: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C176C: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800C1770: bne         $v0, $t1, L_800C1670
    if (ctx->r2 != ctx->r9) {
        // 0x800C1774: sb          $t0, 0x27($t6)
        MEM_B(0X27, ctx->r14) = ctx->r8;
            goto L_800C1670;
    }
    // 0x800C1774: sb          $t0, 0x27($t6)
    MEM_B(0X27, ctx->r14) = ctx->r8;
    // 0x800C1778: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C177C: sltu        $at, $v1, $t2
    ctx->r1 = ctx->r3 < ctx->r10 ? 1 : 0;
    // 0x800C1780: bne         $at, $zero, L_800C1670
    if (ctx->r1 != 0) {
        // 0x800C1784: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C1670;
    }
    // 0x800C1784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1788: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C178C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C1790: addiu       $t2, $t2, 0x31C8
    ctx->r10 = ADD32(ctx->r10, 0X31C8);
    // 0x800C1794: addiu       $v1, $v1, 0x31C0
    ctx->r3 = ADD32(ctx->r3, 0X31C0);
    // 0x800C1798: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x800C179C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_800C17A0:
    // 0x800C17A0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C17A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C17A8: sb          $zero, 0xC7($t7)
    MEM_B(0XC7, ctx->r15) = 0;
    // 0x800C17AC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C17B0: nop

    // 0x800C17B4: sb          $zero, 0x22F($t8)
    MEM_B(0X22F, ctx->r24) = 0;
L_800C17B8:
    // 0x800C17B8: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x800C17BC: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C17C0: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C17C4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C17C8: addiu       $t8, $a3, 0x2
    ctx->r24 = ADD32(ctx->r7, 0X2);
    // 0x800C17CC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C17D0: mflo        $v0
    ctx->r2 = lo;
    // 0x800C17D4: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x800C17D8: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C17DC: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C17E0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C17E4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C17E8: addiu       $t8, $a3, 0x3
    ctx->r24 = ADD32(ctx->r7, 0X3);
    // 0x800C17EC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C17F0: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C17F4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C17F8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800C17FC: mflo        $a0
    ctx->r4 = lo;
    // 0x800C1800: addu        $t4, $t5, $a0
    ctx->r12 = ADD32(ctx->r13, ctx->r4);
    // 0x800C1804: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C1808: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C180C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1810: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C1814: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800C1818: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C181C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1820: mflo        $a1
    ctx->r5 = lo;
    // 0x800C1824: addu        $t4, $t5, $a1
    ctx->r12 = ADD32(ctx->r13, ctx->r5);
    // 0x800C1828: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C182C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1830: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1834: nop

    // 0x800C1838: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C183C: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C1840: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1844: mflo        $a2
    ctx->r6 = lo;
    // 0x800C1848: addu        $t4, $t5, $a2
    ctx->r12 = ADD32(ctx->r13, ctx->r6);
    // 0x800C184C: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C1850: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1854: nop

    // 0x800C1858: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800C185C: bne         $a3, $t1, L_800C17B8
    if (ctx->r7 != ctx->r9) {
        // 0x800C1860: sb          $zero, 0x22F($t7)
        MEM_B(0X22F, ctx->r15) = 0;
            goto L_800C17B8;
    }
    // 0x800C1860: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C1864: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C1868: sltu        $at, $v1, $t2
    ctx->r1 = ctx->r3 < ctx->r10 ? 1 : 0;
    // 0x800C186C: bne         $at, $zero, L_800C17A0
    if (ctx->r1 != 0) {
        // 0x800C1870: nop
    
            goto L_800C17A0;
    }
    // 0x800C1870: nop

    // 0x800C1874: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800C1878: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800C187C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800C1880: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800C1884: addiu       $s2, $s2, 0x31C8
    ctx->r18 = ADD32(ctx->r18, 0X31C8);
    // 0x800C1888: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C188C: addiu       $s0, $zero, -0x10
    ctx->r16 = ADD32(0, -0X10);
L_800C1890:
    // 0x800C1890: sll         $s3, $s5, 16
    ctx->r19 = S32(ctx->r21 << 16);
    // 0x800C1894: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800C1898: sll         $a0, $t8, 16
    ctx->r4 = S32(ctx->r24 << 16);
    // 0x800C189C: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C18A0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800C18A4: jal         0x800707C4
    // 0x800C18A8: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x800C18A8: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    after_1:
    // 0x800C18AC: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800C18B0: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x800C18B4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C18B8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800C18BC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800C18C0: nop

    // 0x800C18C4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800C18C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C18CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C18D0: nop

    // 0x800C18D4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800C18D8: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x800C18DC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800C18E0: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x800C18E4: jal         0x800707F8
    // 0x800C18E8: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x800C18E8: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    after_2:
    // 0x800C18EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C18F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C18F4: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x800C18F8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C18FC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800C1900: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1904: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C1908: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C190C: addiu       $v0, $v0, 0x31C0
    ctx->r2 = ADD32(ctx->r2, 0X31C0);
    // 0x800C1910: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C1914: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1918: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C191C: sll         $v1, $t8, 1
    ctx->r3 = S32(ctx->r24 << 1);
    // 0x800C1920: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C1924: negu        $a1, $s1
    ctx->r5 = SUB32(0, ctx->r17);
    // 0x800C1928: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x800C192C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C1930: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800C1934: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
L_800C1938:
    // 0x800C1938: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C193C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C1940: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C1944: sh          $s1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r17;
    // 0x800C1948: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C194C: nop

    // 0x800C1950: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1954: sh          $a0, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r4;
    // 0x800C1958: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C195C: nop

    // 0x800C1960: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C1964: sh          $s0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r16;
    // 0x800C1968: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800C196C: nop

    // 0x800C1970: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C1974: sh          $s0, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r16;
    // 0x800C1978: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C197C: nop

    // 0x800C1980: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1984: sh          $s0, 0xB8($t9)
    MEM_H(0XB8, ctx->r25) = ctx->r16;
    // 0x800C1988: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C198C: nop

    // 0x800C1990: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C1994: sh          $s0, 0xC2($t4)
    MEM_H(0XC2, ctx->r12) = ctx->r16;
    // 0x800C1998: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800C199C: nop

    // 0x800C19A0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C19A4: sh          $a1, 0x168($t7)
    MEM_H(0X168, ctx->r15) = ctx->r5;
    // 0x800C19A8: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C19AC: nop

    // 0x800C19B0: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C19B4: sh          $a0, 0x16A($t9)
    MEM_H(0X16A, ctx->r25) = ctx->r4;
    // 0x800C19B8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C19BC: nop

    // 0x800C19C0: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C19C4: sh          $s0, 0x16C($t4)
    MEM_H(0X16C, ctx->r12) = ctx->r16;
    // 0x800C19C8: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800C19CC: nop

    // 0x800C19D0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C19D4: sh          $s0, 0x176($t7)
    MEM_H(0X176, ctx->r15) = ctx->r16;
    // 0x800C19D8: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C19DC: nop

    // 0x800C19E0: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C19E4: sh          $s0, 0x220($t9)
    MEM_H(0X220, ctx->r25) = ctx->r16;
    // 0x800C19E8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C19EC: nop

    // 0x800C19F0: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C19F4: bne         $v0, $s2, L_800C1938
    if (ctx->r2 != ctx->r18) {
        // 0x800C19F8: sh          $s0, 0x22A($t4)
        MEM_H(0X22A, ctx->r12) = ctx->r16;
            goto L_800C1938;
    }
    // 0x800C19F8: sh          $s0, 0x22A($t4)
    MEM_H(0X22A, ctx->r12) = ctx->r16;
    // 0x800C19FC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C1A00: slti        $at, $s4, 0x9
    ctx->r1 = SIGNED(ctx->r20) < 0X9 ? 1 : 0;
    // 0x800C1A04: bne         $at, $zero, L_800C1890
    if (ctx->r1 != 0) {
        // 0x800C1A08: addiu       $s5, $s5, 0x1000
        ctx->r21 = ADD32(ctx->r21, 0X1000);
            goto L_800C1890;
    }
    // 0x800C1A08: addiu       $s5, $s5, 0x1000
    ctx->r21 = ADD32(ctx->r21, 0X1000);
    // 0x800C1A0C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800C1A10: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1A14: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800C1A18: addiu       $v1, $v1, 0x31C8
    ctx->r3 = ADD32(ctx->r3, 0X31C8);
    // 0x800C1A1C: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x800C1A20: beq         $t8, $zero, L_800C1A98
    if (ctx->r24 == 0) {
        // 0x800C1A24: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_800C1A98;
    }
    // 0x800C1A24: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C1A28: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C1A2C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C1A30: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C1A34: lhu         $t9, 0x31B0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X31B0);
    // 0x800C1A38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C1A3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1A40: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800C1A44: swc1        $f2, -0x58A8($at)
    MEM_W(-0X58A8, ctx->r1) = ctx->f2.u32l;
    // 0x800C1A48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1A4C: swc1        $f2, -0x58A4($at)
    MEM_W(-0X58A4, ctx->r1) = ctx->f2.u32l;
    // 0x800C1A50: bgez        $t9, L_800C1A68
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C1A54: cvt.s.w     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800C1A68;
    }
    // 0x800C1A54: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C1A58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1A5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C1A60: nop

    // 0x800C1A64: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_800C1A68:
    // 0x800C1A68: nop

    // 0x800C1A6C: div.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800C1A70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1A74: div.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C1A78: swc1        $f6, -0x58A0($at)
    MEM_W(-0X58A0, ctx->r1) = ctx->f6.u32l;
    // 0x800C1A7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1A80: swc1        $f8, -0x589C($at)
    MEM_W(-0X589C, ctx->r1) = ctx->f8.u32l;
    // 0x800C1A84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1A88: swc1        $f20, -0x5898($at)
    MEM_W(-0X5898, ctx->r1) = ctx->f20.u32l;
    // 0x800C1A8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1A90: b           L_800C1B0C
    // 0x800C1A94: swc1        $f12, -0x5894($at)
    MEM_W(-0X5894, ctx->r1) = ctx->f12.u32l;
        goto L_800C1B0C;
    // 0x800C1A94: swc1        $f12, -0x5894($at)
    MEM_W(-0X5894, ctx->r1) = ctx->f12.u32l;
L_800C1A98:
    // 0x800C1A98: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C1A9C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C1AA0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C1AA4: lhu         $t5, 0x31B0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X31B0);
    // 0x800C1AA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1AAC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800C1AB0: swc1        $f20, -0x58A8($at)
    MEM_W(-0X58A8, ctx->r1) = ctx->f20.u32l;
    // 0x800C1AB4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C1AB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1ABC: swc1        $f12, -0x58A4($at)
    MEM_W(-0X58A4, ctx->r1) = ctx->f12.u32l;
    // 0x800C1AC0: bgez        $t5, L_800C1AD8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C1AC4: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800C1AD8;
    }
    // 0x800C1AC4: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C1AC8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1ACC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C1AD0: nop

    // 0x800C1AD4: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
L_800C1AD8:
    // 0x800C1AD8: neg.s       $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = -ctx->f20.fl;
    // 0x800C1ADC: nop

    // 0x800C1AE0: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800C1AE4: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x800C1AE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1AEC: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C1AF0: swc1        $f4, -0x58A0($at)
    MEM_W(-0X58A0, ctx->r1) = ctx->f4.u32l;
    // 0x800C1AF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1AF8: swc1        $f8, -0x589C($at)
    MEM_W(-0X589C, ctx->r1) = ctx->f8.u32l;
    // 0x800C1AFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1B00: swc1        $f2, -0x5898($at)
    MEM_W(-0X5898, ctx->r1) = ctx->f2.u32l;
    // 0x800C1B04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1B08: swc1        $f2, -0x5894($at)
    MEM_W(-0X5894, ctx->r1) = ctx->f2.u32l;
L_800C1B0C:
    // 0x800C1B0C: addiu       $a2, $a2, 0x31D0
    ctx->r6 = ADD32(ctx->r6, 0X31D0);
    // 0x800C1B10: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x800C1B14: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800C1B18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C1B1C:
    // 0x800C1B1C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1B20: nop

    // 0x800C1B24: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1B28: sb          $a0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r4;
    // 0x800C1B2C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1B30: nop

    // 0x800C1B34: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1B38: sh          $zero, 0x4($t8)
    MEM_H(0X4, ctx->r24) = 0;
    // 0x800C1B3C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1B40: nop

    // 0x800C1B44: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1B48: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800C1B4C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1B50: nop

    // 0x800C1B54: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1B58: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800C1B5C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1B60: nop

    // 0x800C1B64: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1B68: sh          $zero, 0xA($t8)
    MEM_H(0XA, ctx->r24) = 0;
    // 0x800C1B6C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1B70: nop

    // 0x800C1B74: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1B78: sh          $zero, 0xC($t5)
    MEM_H(0XC, ctx->r13) = 0;
    // 0x800C1B7C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1B80: nop

    // 0x800C1B84: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1B88: sh          $zero, 0xE($t6)
    MEM_H(0XE, ctx->r14) = 0;
    // 0x800C1B8C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1B90: nop

    // 0x800C1B94: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1B98: sb          $a0, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r4;
    // 0x800C1B9C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BA0: nop

    // 0x800C1BA4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1BA8: sh          $zero, 0x14($t5)
    MEM_H(0X14, ctx->r13) = 0;
    // 0x800C1BAC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BB0: nop

    // 0x800C1BB4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1BB8: sh          $zero, 0x16($t6)
    MEM_H(0X16, ctx->r14) = 0;
    // 0x800C1BBC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BC0: nop

    // 0x800C1BC4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1BC8: sh          $zero, 0x18($t8)
    MEM_H(0X18, ctx->r24) = 0;
    // 0x800C1BCC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BD0: nop

    // 0x800C1BD4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1BD8: sh          $zero, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = 0;
    // 0x800C1BDC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BE0: nop

    // 0x800C1BE4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1BE8: sh          $zero, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = 0;
    // 0x800C1BEC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BF0: nop

    // 0x800C1BF4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1BF8: sh          $zero, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = 0;
    // 0x800C1BFC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C00: nop

    // 0x800C1C04: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1C08: sb          $a0, 0x20($t5)
    MEM_B(0X20, ctx->r13) = ctx->r4;
    // 0x800C1C0C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C10: nop

    // 0x800C1C14: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C18: sh          $zero, 0x24($t6)
    MEM_H(0X24, ctx->r14) = 0;
    // 0x800C1C1C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C20: nop

    // 0x800C1C24: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1C28: sh          $zero, 0x26($t8)
    MEM_H(0X26, ctx->r24) = 0;
    // 0x800C1C2C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C30: nop

    // 0x800C1C34: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1C38: sh          $zero, 0x28($t5)
    MEM_H(0X28, ctx->r13) = 0;
    // 0x800C1C3C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C40: nop

    // 0x800C1C44: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C48: sh          $zero, 0x2A($t6)
    MEM_H(0X2A, ctx->r14) = 0;
    // 0x800C1C4C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C50: nop

    // 0x800C1C54: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1C58: sh          $zero, 0x2C($t8)
    MEM_H(0X2C, ctx->r24) = 0;
    // 0x800C1C5C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C60: nop

    // 0x800C1C64: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1C68: sh          $zero, 0x2E($t5)
    MEM_H(0X2E, ctx->r13) = 0;
    // 0x800C1C6C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C70: nop

    // 0x800C1C74: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C78: sb          $a0, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r4;
    // 0x800C1C7C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C80: nop

    // 0x800C1C84: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1C88: sh          $zero, 0x34($t8)
    MEM_H(0X34, ctx->r24) = 0;
    // 0x800C1C8C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C90: nop

    // 0x800C1C94: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1C98: sh          $zero, 0x36($t5)
    MEM_H(0X36, ctx->r13) = 0;
    // 0x800C1C9C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CA0: nop

    // 0x800C1CA4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1CA8: sh          $zero, 0x38($t6)
    MEM_H(0X38, ctx->r14) = 0;
    // 0x800C1CAC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CB0: nop

    // 0x800C1CB4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1CB8: sh          $zero, 0x3A($t8)
    MEM_H(0X3A, ctx->r24) = 0;
    // 0x800C1CBC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CC0: nop

    // 0x800C1CC4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1CC8: sh          $zero, 0x3C($t5)
    MEM_H(0X3C, ctx->r13) = 0;
    // 0x800C1CCC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CD0: nop

    // 0x800C1CD4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1CD8: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800C1CDC: bne         $v0, $a1, L_800C1B1C
    if (ctx->r2 != ctx->r5) {
        // 0x800C1CE0: sh          $zero, 0x3E($t6)
        MEM_H(0X3E, ctx->r14) = 0;
            goto L_800C1B1C;
    }
    // 0x800C1CE0: sh          $zero, 0x3E($t6)
    MEM_H(0X3E, ctx->r14) = 0;
    // 0x800C1CE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C1CE8: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x800C1CEC: bne         $at, $zero, L_800C1B1C
    if (ctx->r1 != 0) {
        // 0x800C1CF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C1B1C;
    }
    // 0x800C1CF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1CF4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C1CF8: addiu       $t2, $t2, 0x31D0
    ctx->r10 = ADD32(ctx->r10, 0X31D0);
    // 0x800C1CFC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C1D00: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800C1D04: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
L_800C1D08:
    // 0x800C1D08: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C1D0C: addiu       $v0, $v0, 0x31C8
    ctx->r2 = ADD32(ctx->r2, 0X31C8);
    // 0x800C1D10: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800C1D14: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
    // 0x800C1D18: addiu       $a1, $a0, 0x3
    ctx->r5 = ADD32(ctx->r4, 0X3);
    // 0x800C1D1C: addiu       $t0, $a0, 0x2
    ctx->r8 = ADD32(ctx->r4, 0X2);
L_800C1D20:
    // 0x800C1D20: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800C1D24: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C1D28: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C1D2C: sb          $a0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r4;
    // 0x800C1D30: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C1D34: nop

    // 0x800C1D38: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C1D3C: sb          $a2, 0x2($t5)
    MEM_B(0X2, ctx->r13) = ctx->r6;
    // 0x800C1D40: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C1D44: nop

    // 0x800C1D48: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C1D4C: sb          $a1, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r5;
    // 0x800C1D50: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C1D54: nop

    // 0x800C1D58: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C1D5C: sb          $a0, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r4;
    // 0x800C1D60: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C1D64: nop

    // 0x800C1D68: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C1D6C: sb          $a1, 0x12($t5)
    MEM_B(0X12, ctx->r13) = ctx->r5;
    // 0x800C1D70: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C1D74: nop

    // 0x800C1D78: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C1D7C: sb          $t0, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r8;
    // 0x800C1D80: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C1D84: nop

    // 0x800C1D88: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C1D8C: sb          $a0, 0x101($t8)
    MEM_B(0X101, ctx->r24) = ctx->r4;
    // 0x800C1D90: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C1D94: nop

    // 0x800C1D98: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C1D9C: sb          $a2, 0x102($t5)
    MEM_B(0X102, ctx->r13) = ctx->r6;
    // 0x800C1DA0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C1DA4: nop

    // 0x800C1DA8: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C1DAC: sb          $a1, 0x103($t6)
    MEM_B(0X103, ctx->r14) = ctx->r5;
    // 0x800C1DB0: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C1DB4: nop

    // 0x800C1DB8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C1DBC: sb          $a0, 0x111($t8)
    MEM_B(0X111, ctx->r24) = ctx->r4;
    // 0x800C1DC0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C1DC4: nop

    // 0x800C1DC8: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C1DCC: sb          $a1, 0x112($t5)
    MEM_B(0X112, ctx->r13) = ctx->r5;
    // 0x800C1DD0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C1DD4: nop

    // 0x800C1DD8: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C1DDC: sb          $t0, 0x113($t6)
    MEM_B(0X113, ctx->r14) = ctx->r8;
    // 0x800C1DE0: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C1DE4: nop

    // 0x800C1DE8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C1DEC: sb          $a0, 0x201($t8)
    MEM_B(0X201, ctx->r24) = ctx->r4;
    // 0x800C1DF0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C1DF4: nop

    // 0x800C1DF8: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C1DFC: sb          $a2, 0x202($t5)
    MEM_B(0X202, ctx->r13) = ctx->r6;
    // 0x800C1E00: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E04: nop

    // 0x800C1E08: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C1E0C: sb          $a1, 0x203($t6)
    MEM_B(0X203, ctx->r14) = ctx->r5;
    // 0x800C1E10: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E14: nop

    // 0x800C1E18: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C1E1C: sb          $a0, 0x211($t8)
    MEM_B(0X211, ctx->r24) = ctx->r4;
    // 0x800C1E20: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E24: nop

    // 0x800C1E28: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C1E2C: sb          $a1, 0x212($t5)
    MEM_B(0X212, ctx->r13) = ctx->r5;
    // 0x800C1E30: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E34: nop

    // 0x800C1E38: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C1E3C: sb          $t0, 0x213($t6)
    MEM_B(0X213, ctx->r14) = ctx->r8;
    // 0x800C1E40: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E44: nop

    // 0x800C1E48: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C1E4C: sb          $a0, 0x301($t8)
    MEM_B(0X301, ctx->r24) = ctx->r4;
    // 0x800C1E50: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E54: nop

    // 0x800C1E58: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C1E5C: sb          $a2, 0x302($t5)
    MEM_B(0X302, ctx->r13) = ctx->r6;
    // 0x800C1E60: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E64: nop

    // 0x800C1E68: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C1E6C: sb          $a1, 0x303($t6)
    MEM_B(0X303, ctx->r14) = ctx->r5;
    // 0x800C1E70: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E74: nop

    // 0x800C1E78: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C1E7C: sb          $a0, 0x311($t8)
    MEM_B(0X311, ctx->r24) = ctx->r4;
    // 0x800C1E80: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E84: nop

    // 0x800C1E88: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C1E8C: sb          $a1, 0x312($t5)
    MEM_B(0X312, ctx->r13) = ctx->r5;
    // 0x800C1E90: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E94: nop

    // 0x800C1E98: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C1E9C: bne         $v0, $t2, L_800C1D20
    if (ctx->r2 != ctx->r10) {
        // 0x800C1EA0: sb          $t0, 0x313($t6)
        MEM_B(0X313, ctx->r14) = ctx->r8;
            goto L_800C1D20;
    }
    // 0x800C1EA0: sb          $t0, 0x313($t6)
    MEM_B(0X313, ctx->r14) = ctx->r8;
    // 0x800C1EA4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C1EA8: bne         $s4, $t3, L_800C1D08
    if (ctx->r20 != ctx->r11) {
        // 0x800C1EAC: sll         $a0, $s4, 1
        ctx->r4 = S32(ctx->r20 << 1);
            goto L_800C1D08;
    }
    // 0x800C1EAC: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
    // 0x800C1EB0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C1EB4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C1EB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C1EBC: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C1EC0: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C1EC4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1EC8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C1ECC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800C1ED0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800C1ED4: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800C1ED8: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800C1EDC: sw          $t7, 0x31AC($at)
    MEM_W(0X31AC, ctx->r1) = ctx->r15;
    // 0x800C1EE0: jr          $ra
    // 0x800C1EE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C1EE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sins_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
RECOMP_FUNC void mark_to_write_flap_and_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EBFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EC00: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006EC04: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EC08: nop

    // 0x8006EC0C: ori         $t7, $t6, 0x30
    ctx->r15 = ctx->r14 | 0X30;
    // 0x8006EC10: jr          $ra
    // 0x8006EC14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EC14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_800575EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800575EC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800575F0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800575F4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800575F8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800575FC: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80057600: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80057604: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80057608: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005760C: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x80057610: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80057614: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80057618: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005761C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80057620: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80057624: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80057628: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005762C: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x80057630: swc1        $f20, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f20.u32l;
    // 0x80057634: swc1        $f20, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f20.u32l;
    // 0x80057638: swc1        $f20, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f20.u32l;
    // 0x8005763C: jal         0x8006FC30
    // 0x80057640: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x80057640: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_0:
    // 0x80057644: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80057648: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8005764C: addiu       $t8, $s0, 0x38
    ctx->r24 = ADD32(ctx->r16, 0X38);
    // 0x80057650: addiu       $t9, $s0, 0x3C
    ctx->r25 = ADD32(ctx->r16, 0X3C);
    // 0x80057654: addiu       $t0, $s0, 0x40
    ctx->r8 = ADD32(ctx->r16, 0X40);
    // 0x80057658: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8005765C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80057660: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80057664: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80057668: jal         0x8006F64C
    // 0x8005766C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x8005766C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80057670: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80057674: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80057678: addiu       $t1, $s0, 0x44
    ctx->r9 = ADD32(ctx->r16, 0X44);
    // 0x8005767C: addiu       $t2, $s0, 0x48
    ctx->r10 = ADD32(ctx->r16, 0X48);
    // 0x80057680: addiu       $t3, $s0, 0x4C
    ctx->r11 = ADD32(ctx->r16, 0X4C);
    // 0x80057684: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80057688: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8005768C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80057690: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80057694: jal         0x8006F64C
    // 0x80057698: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x80057698: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x8005769C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800576A0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800576A4: addiu       $t4, $s0, 0x50
    ctx->r12 = ADD32(ctx->r16, 0X50);
    // 0x800576A8: addiu       $t5, $s0, 0x54
    ctx->r13 = ADD32(ctx->r16, 0X54);
    // 0x800576AC: addiu       $t6, $s0, 0x58
    ctx->r14 = ADD32(ctx->r16, 0X58);
    // 0x800576B0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800576B4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800576B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800576BC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800576C0: jal         0x8006F64C
    // 0x800576C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x800576C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x800576C8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800576CC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800576D0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800576D4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800576D8: jr          $ra
    // 0x800576DC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800576DC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void object_do_player_tumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012E28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80012E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012E30: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80012E34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012E38: bne         $t6, $at, L_80012F20
    if (ctx->r14 != ctx->r1) {
        // 0x80012E3C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80012F20;
    }
    // 0x80012E3C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80012E40: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80012E44: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80012E48: lh          $t8, 0x160($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X160);
    // 0x80012E4C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x80012E50: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80012E54: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80012E58: lh          $t1, 0x162($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X162);
    // 0x80012E5C: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x80012E60: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80012E64: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
    // 0x80012E68: lh          $t4, 0x164($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X164);
    // 0x80012E6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80012E70: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80012E74: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x80012E78: lb          $t6, 0x1D7($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1D7);
    // 0x80012E7C: nop

    // 0x80012E80: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80012E84: beq         $at, $zero, L_80012F0C
    if (ctx->r1 == 0) {
        // 0x80012E88: nop
    
            goto L_80012F0C;
    }
    // 0x80012E88: nop

    // 0x80012E8C: lh          $a0, 0x164($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X164);
    // 0x80012E90: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80012E94: jal         0x800707F8
    // 0x80012E98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80012E98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x80012E9C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80012EA0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80012EA4: lh          $t8, 0x166($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X166);
    // 0x80012EA8: lh          $t7, 0x162($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X162);
    // 0x80012EAC: nop

    // 0x80012EB0: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x80012EB4: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80012EB8: jal         0x800707F8
    // 0x80012EBC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80012EBC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_1:
    // 0x80012EC0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80012EC4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80012EC8: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80012ECC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012ED0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80012ED4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80012ED8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80012EDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012EE0: bc1f        L_80012EF0
    if (!c1cs) {
        // 0x80012EE4: lui         $at, 0x41C0
        ctx->r1 = S32(0X41C0 << 16);
            goto L_80012EF0;
    }
    // 0x80012EE4: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80012EE8: b           L_80012EF8
    // 0x80012EEC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80012EF8;
    // 0x80012EEC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80012EF0:
    // 0x80012EF0: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80012EF4: nop

L_80012EF8:
    // 0x80012EF8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80012EFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80012F00: lwc1        $f18, 0xD0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x80012F04: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80012F08: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
L_80012F0C:
    // 0x80012F0C: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80012F10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012F14: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80012F18: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
    // 0x80012F1C: swc1        $f0, -0x5230($at)
    MEM_W(-0X5230, ctx->r1) = ctx->f0.u32l;
L_80012F20:
    // 0x80012F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012F24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80012F28: jr          $ra
    // 0x80012F2C: nop

    return;
    // 0x80012F2C: nop

;}
RECOMP_FUNC void obj_spawn_attachment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FD54: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000FD58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000FD5C: lw          $t6, -0x5298($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5298);
    // 0x8000FD60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000FD64: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000FD68: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000FD6C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000FD70: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000FD74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000FD78: bne         $at, $zero, L_8000FD84
    if (ctx->r1 != 0) {
        // 0x8000FD7C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8000FD84;
    }
    // 0x8000FD7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000FD80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000FD84:
    // 0x8000FD84: jal         0x8000C718
    // 0x8000FD88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    load_object_header(rdram, ctx);
        goto after_0;
    // 0x8000FD88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000FD8C: bne         $v0, $zero, L_8000FD9C
    if (ctx->r2 != 0) {
        // 0x8000FD90: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8000FD9C;
    }
    // 0x8000FD90: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8000FD94: b           L_8000FF98
    // 0x8000FD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF98;
    // 0x8000FD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FD9C:
    // 0x8000FD9C: lb          $s0, 0x55($s3)
    ctx->r16 = MEM_B(ctx->r19, 0X55);
    // 0x8000FDA0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8000FDA4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8000FDA8: addiu       $s0, $t7, 0x80
    ctx->r16 = ADD32(ctx->r15, 0X80);
    // 0x8000FDAC: jal         0x80070D10
    // 0x8000FDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x8000FDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000FDB4: bne         $v0, $zero, L_8000FDD0
    if (ctx->r2 != 0) {
        // 0x8000FDB8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000FDD0;
    }
    // 0x8000FDB8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000FDBC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8000FDC0: jal         0x8000C844
    // 0x8000FDC4: nop

    try_free_object_header(rdram, ctx);
        goto after_2;
    // 0x8000FDC4: nop

    after_2:
    // 0x8000FDC8: b           L_8000FF98
    // 0x8000FDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF98;
    // 0x8000FDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FDD0:
    // 0x8000FDD0: blez        $s0, L_8000FE20
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8000FDD4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000FE20;
    }
    // 0x8000FDD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000FDD8: andi        $a1, $s0, 0x3
    ctx->r5 = ctx->r16 & 0X3;
    // 0x8000FDDC: beq         $a1, $zero, L_8000FDFC
    if (ctx->r5 == 0) {
        // 0x8000FDE0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8000FDFC;
    }
    // 0x8000FDE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000FDE4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8000FDE8:
    // 0x8000FDE8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FDEC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000FDF0: bne         $a0, $s1, L_8000FDE8
    if (ctx->r4 != ctx->r17) {
        // 0x8000FDF4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000FDE8;
    }
    // 0x8000FDF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000FDF8: beq         $s1, $s0, L_8000FE1C
    if (ctx->r17 == ctx->r16) {
        // 0x8000FDFC: addu        $v1, $v0, $s1
        ctx->r3 = ADD32(ctx->r2, ctx->r17);
            goto L_8000FE1C;
    }
L_8000FDFC:
    // 0x8000FDFC: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
L_8000FE00:
    // 0x8000FE00: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000FE04: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000FE08: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8000FE0C: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x8000FE10: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8000FE14: bne         $s1, $s0, L_8000FE00
    if (ctx->r17 != ctx->r16) {
        // 0x8000FE18: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000FE00;
    }
    // 0x8000FE18: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000FE1C:
    // 0x8000FE1C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000FE20:
    // 0x8000FE20: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000FE24: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x8000FE28: sw          $s3, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r19;
    // 0x8000FE2C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8000FE30: nop

    // 0x8000FE34: sh          $t9, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r25;
    // 0x8000FE38: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8000FE3C: nop

    // 0x8000FE40: sh          $t0, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r8;
    // 0x8000FE44: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000FE48: nop

    // 0x8000FE4C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8000FE50: lhu         $t1, 0x30($s3)
    ctx->r9 = MEM_HU(ctx->r19, 0X30);
    // 0x8000FE54: nop

    // 0x8000FE58: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x8000FE5C: beq         $t2, $zero, L_8000FE74
    if (ctx->r10 == 0) {
        // 0x8000FE60: nop
    
            goto L_8000FE74;
    }
    // 0x8000FE60: nop

    // 0x8000FE64: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8000FE68: nop

    // 0x8000FE6C: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x8000FE70: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
L_8000FE74:
    // 0x8000FE74: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8000FE78: addiu       $t6, $v0, 0x80
    ctx->r14 = ADD32(ctx->r2, 0X80);
    // 0x8000FE7C: lb          $t5, 0x53($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X53);
    // 0x8000FE80: lb          $s4, 0x55($v1)
    ctx->r20 = MEM_B(ctx->r3, 0X55);
    // 0x8000FE84: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8000FE88: sw          $t6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r14;
    // 0x8000FE8C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8000FE90: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000FE94: bne         $t7, $zero, L_8000FF04
    if (ctx->r15 != 0) {
        // 0x8000FE98: nop
    
            goto L_8000FF04;
    }
    // 0x8000FE98: nop

    // 0x8000FE9C: blez        $s4, L_8000FF64
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8000FEA0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000FF64;
    }
    // 0x8000FEA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000FEA4:
    // 0x8000FEA4: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x8000FEA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000FEAC: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8000FEB0: nop

    // 0x8000FEB4: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000FEB8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8000FEBC: jal         0x8005F99C
    // 0x8000FEC0: nop

    object_model_init(rdram, ctx);
        goto after_3;
    // 0x8000FEC0: nop

    after_3:
    // 0x8000FEC4: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x8000FEC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FECC: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8000FED0: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8000FED4: lw          $t3, 0x68($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X68);
    // 0x8000FED8: nop

    // 0x8000FEDC: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8000FEE0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8000FEE4: nop

    // 0x8000FEE8: bne         $t5, $zero, L_8000FEF4
    if (ctx->r13 != 0) {
        // 0x8000FEEC: nop
    
            goto L_8000FEF4;
    }
    // 0x8000FEEC: nop

    // 0x8000FEF0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8000FEF4:
    // 0x8000FEF4: bne         $s1, $s4, L_8000FEA4
    if (ctx->r17 != ctx->r20) {
        // 0x8000FEF8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000FEA4;
    }
    // 0x8000FEF8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000FEFC: b           L_8000FF64
    // 0x8000FF00: nop

        goto L_8000FF64;
    // 0x8000FF00: nop

L_8000FF04:
    // 0x8000FF04: blez        $s4, L_8000FF64
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8000FF08: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000FF64;
    }
    // 0x8000FF08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000FF0C:
    // 0x8000FF0C: lw          $t6, 0x40($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X40);
    // 0x8000FF10: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8000FF14: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8000FF18: nop

    // 0x8000FF1C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8000FF20: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8000FF24: jal         0x8007C12C
    // 0x8000FF28: nop

    tex_load_sprite(rdram, ctx);
        goto after_4;
    // 0x8000FF28: nop

    after_4:
    // 0x8000FF2C: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000FF30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FF34: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000FF38: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8000FF3C: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x8000FF40: nop

    // 0x8000FF44: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8000FF48: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8000FF4C: nop

    // 0x8000FF50: bne         $t3, $zero, L_8000FF5C
    if (ctx->r11 != 0) {
        // 0x8000FF54: nop
    
            goto L_8000FF5C;
    }
    // 0x8000FF54: nop

    // 0x8000FF58: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8000FF5C:
    // 0x8000FF5C: bne         $s1, $s4, L_8000FF0C
    if (ctx->r17 != ctx->r20) {
        // 0x8000FF60: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000FF0C;
    }
    // 0x8000FF60: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000FF64:
    // 0x8000FF64: beq         $s3, $zero, L_8000FF98
    if (ctx->r19 == 0) {
        // 0x8000FF68: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_8000FF98;
    }
    // 0x8000FF68: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8000FF6C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8000FF70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000FF74: jal         0x8000F648
    // 0x8000FF78: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    objFreeAssets(rdram, ctx);
        goto after_5;
    // 0x8000FF78: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_5:
    // 0x8000FF7C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8000FF80: jal         0x8000C844
    // 0x8000FF84: nop

    try_free_object_header(rdram, ctx);
        goto after_6;
    // 0x8000FF84: nop

    after_6:
    // 0x8000FF88: jal         0x80071140
    // 0x8000FF8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8000FF8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x8000FF90: b           L_8000FF98
    // 0x8000FF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF98;
    // 0x8000FF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FF98:
    // 0x8000FF98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FF9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000FFA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FFA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000FFA8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000FFAC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000FFB0: jr          $ra
    // 0x8000FFB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000FFB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sound_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020E8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800020EC: lw          $t6, 0x5D14($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5D14);
    // 0x800020F0: nop

    // 0x800020F4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800020F8: nop

    // 0x800020FC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80002100: nop

    // 0x80002104: lhu         $v0, 0xE($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XE);
    // 0x80002108: jr          $ra
    // 0x8000210C: nop

    return;
    // 0x8000210C: nop

;}
RECOMP_FUNC void obj_loop_wballoonpop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E5BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003E5C0: jr          $ra
    // 0x8003E5C4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003E5C4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_bombexplosion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038BF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80038BF8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80038BFC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80038C00: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80038C04: lw          $t0, 0x7C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X7C);
    // 0x80038C08: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x80038C0C: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80038C10: sra         $v1, $t0, 8
    ctx->r3 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80038C14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80038C18: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x80038C1C: bne         $at, $zero, L_80038C68
    if (ctx->r1 != 0) {
        // 0x80038C20: andi        $t8, $v1, 0xFF
        ctx->r24 = ctx->r3 & 0XFF;
            goto L_80038C68;
    }
    // 0x80038C20: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x80038C24: beq         $t8, $zero, L_80038C68
    if (ctx->r24 == 0) {
        // 0x80038C28: sll         $t9, $t8, 8
        ctx->r25 = S32(ctx->r24 << 8);
            goto L_80038C68;
    }
    // 0x80038C28: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80038C2C: xor         $t1, $t0, $t9
    ctx->r9 = ctx->r8 ^ ctx->r25;
    // 0x80038C30: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80038C34: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80038C38: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x80038C3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80038C40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038C44: sw          $t1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r9;
    // 0x80038C48: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x80038C4C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80038C50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80038C54: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80038C58: jal         0x8003FC44
    // 0x80038C5C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_0;
    // 0x80038C5C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80038C60: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80038C64: nop

L_80038C68:
    // 0x80038C68: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80038C6C: beq         $at, $zero, L_80038CBC
    if (ctx->r1 == 0) {
        // 0x80038C70: slti        $at, $v0, 0x28
        ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
            goto L_80038CBC;
    }
    // 0x80038C70: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80038C74: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80038C78: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80038C7C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80038C80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038C84: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80038C88: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80038C8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038C90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80038C94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038C98: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
    // 0x80038C9C: nop

    // 0x80038CA0: ori         $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 | 0XFF;
    // 0x80038CA4: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x80038CA8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80038CAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80038CB0: b           L_80038D18
    // 0x80038CB4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_80038D18;
    // 0x80038CB4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80038CB8: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
L_80038CBC:
    // 0x80038CBC: beq         $at, $zero, L_80038D10
    if (ctx->r1 == 0) {
        // 0x80038CC0: addiu       $t5, $v0, -0x14
        ctx->r13 = ADD32(ctx->r2, -0X14);
            goto L_80038D10;
    }
    // 0x80038CC0: addiu       $t5, $v0, -0x14
    ctx->r13 = ADD32(ctx->r2, -0X14);
    // 0x80038CC4: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80038CC8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80038CCC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80038CD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038CD4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80038CD8: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80038CDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038CE0: lui         $at, 0x4128
    ctx->r1 = S32(0X4128 << 16);
    // 0x80038CE4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80038CE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038CEC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80038CF0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80038CF4: addiu       $t7, $zero, 0x1EF
    ctx->r15 = ADD32(0, 0X1EF);
    // 0x80038CF8: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80038CFC: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x80038D00: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80038D04: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80038D08: b           L_80038D18
    // 0x80038D0C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_80038D18;
    // 0x80038D0C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_80038D10:
    // 0x80038D10: jal         0x8000FFB8
    // 0x80038D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x80038D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80038D18:
    // 0x80038D18: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80038D1C: nop

    // 0x80038D20: beq         $t9, $zero, L_80038D4C
    if (ctx->r25 == 0) {
        // 0x80038D24: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80038D4C;
    }
    // 0x80038D24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80038D28: jal         0x8009C3C8
    // 0x80038D2C: nop

    get_number_of_active_players(rdram, ctx);
        goto after_2;
    // 0x80038D2C: nop

    after_2:
    // 0x80038D30: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80038D34: beq         $at, $zero, L_80038D48
    if (ctx->r1 == 0) {
        // 0x80038D38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80038D48;
    }
    // 0x80038D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038D3C: jal         0x800AFC3C
    // 0x80038D40: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    obj_spawn_particle(rdram, ctx);
        goto after_3;
    // 0x80038D40: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80038D44: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
L_80038D48:
    // 0x80038D48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80038D4C:
    // 0x80038D4C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80038D50: jr          $ra
    // 0x80038D54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80038D54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void results_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800976CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800976D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800976D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800976D8: jal         0x8009C4A8
    // 0x800976DC: addiu       $a0, $a0, 0xA24
    ctx->r4 = ADD32(ctx->r4, 0XA24);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x800976DC: addiu       $a0, $a0, 0xA24
    ctx->r4 = ADD32(ctx->r4, 0XA24);
    after_0:
    // 0x800976E0: jal         0x800C422C
    // 0x800976E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x800976E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x800976E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800976EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800976F0: jr          $ra
    // 0x800976F4: nop

    return;
    // 0x800976F4: nop

;}
RECOMP_FUNC void update_player_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057A40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80057A44: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80057A48: lw          $t6, -0x2AD4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AD4);
    // 0x80057A4C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80057A50: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80057A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057A58: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80057A5C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80057A60: beq         $t7, $zero, L_80057B40
    if (ctx->r15 == 0) {
        // 0x80057A64: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_80057B40;
    }
    // 0x80057A64: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80057A68: jal         0x800A0190
    // 0x80057A6C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    race_starting(rdram, ctx);
        goto after_0;
    // 0x80057A6C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80057A70: beq         $v0, $zero, L_80057B40
    if (ctx->r2 == 0) {
        // 0x80057A74: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80057B40;
    }
    // 0x80057A74: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057A78: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057A7C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057A80: nop

    // 0x80057A84: lbu         $t8, 0x3B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3B);
    // 0x80057A88: nop

    // 0x80057A8C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80057A90: sb          $t9, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = ctx->r25;
    // 0x80057A94: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057A98: nop

    // 0x80057A9C: lbu         $a1, 0x3B($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X3B);
    // 0x80057AA0: nop

    // 0x80057AA4: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80057AA8: bne         $at, $zero, L_80057AC8
    if (ctx->r1 != 0) {
        // 0x80057AAC: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_80057AC8;
    }
    // 0x80057AAC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80057AB0: sb          $zero, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = 0;
    // 0x80057AB4: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80057AB8: nop

    // 0x80057ABC: lbu         $a1, 0x3B($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X3B);
    // 0x80057AC0: nop

    // 0x80057AC4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_80057AC8:
    // 0x80057AC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057ACC: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80057AD0: nop

    // 0x80057AD4: beq         $a0, $at, L_80057AFC
    if (ctx->r4 == ctx->r1) {
        // 0x80057AD8: nop
    
            goto L_80057AFC;
    }
    // 0x80057AD8: nop

    // 0x80057ADC: jal         0x80066060
    // 0x80057AE0: nop

    cam_set_zoom(rdram, ctx);
        goto after_1;
    // 0x80057AE0: nop

    after_1:
    // 0x80057AE4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057AE8: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057AEC: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80057AF0: nop

    // 0x80057AF4: lbu         $a1, 0x3B($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X3B);
    // 0x80057AF8: nop

L_80057AFC:
    // 0x80057AFC: beq         $a1, $zero, L_80057B18
    if (ctx->r5 == 0) {
        // 0x80057B00: addiu       $a0, $zero, 0x68
        ctx->r4 = ADD32(0, 0X68);
            goto L_80057B18;
    }
    // 0x80057B00: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x80057B04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80057B08: beq         $a1, $at, L_80057B28
    if (ctx->r5 == ctx->r1) {
        // 0x80057B0C: addiu       $a0, $zero, 0x69
        ctx->r4 = ADD32(0, 0X69);
            goto L_80057B28;
    }
    // 0x80057B0C: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    // 0x80057B10: b           L_80057B38
    // 0x80057B14: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
        goto L_80057B38;
    // 0x80057B14: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
L_80057B18:
    // 0x80057B18: jal         0x80001D04
    // 0x80057B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80057B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80057B20: b           L_80057B44
    // 0x80057B24: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
        goto L_80057B44;
    // 0x80057B24: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_80057B28:
    // 0x80057B28: jal         0x80001D04
    // 0x80057B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x80057B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80057B30: b           L_80057B44
    // 0x80057B34: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
        goto L_80057B44;
    // 0x80057B34: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_80057B38:
    // 0x80057B38: jal         0x80001D04
    // 0x80057B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x80057B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80057B40:
    // 0x80057B40: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_80057B44:
    // 0x80057B44: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057B48: lb          $t3, 0x1D8($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X1D8);
    // 0x80057B4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80057B50: bne         $t3, $at, L_80057B74
    if (ctx->r11 != ctx->r1) {
        // 0x80057B54: addiu       $a3, $a3, -0x2AF8
        ctx->r7 = ADD32(ctx->r7, -0X2AF8);
            goto L_80057B74;
    }
    // 0x80057B54: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057B58: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057B5C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80057B60: lh          $t4, 0x36($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X36);
    // 0x80057B64: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80057B68: beq         $t4, $at, L_80057B74
    if (ctx->r12 == ctx->r1) {
        // 0x80057B6C: nop
    
            goto L_80057B74;
    }
    // 0x80057B6C: nop

    // 0x80057B70: sh          $t5, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r13;
L_80057B74:
    // 0x80057B74: lw          $t6, 0x108($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X108);
    // 0x80057B78: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057B7C: beq         $t6, $zero, L_80057B90
    if (ctx->r14 == 0) {
        // 0x80057B80: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80057B90;
    }
    // 0x80057B80: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80057B84: sh          $t7, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r15;
    // 0x80057B88: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057B8C: nop

L_80057B90:
    // 0x80057B90: lhu         $t8, 0x36($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X36);
    // 0x80057B94: nop

    // 0x80057B98: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80057B9C: beq         $at, $zero, L_80057CD0
    if (ctx->r1 == 0) {
        // 0x80057BA0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80057CD0;
    }
    // 0x80057BA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80057BA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057BA8: addu        $at, $at, $t8
    gpr jr_addend_80057BB4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80057BAC: lw          $t8, 0x68D0($at)
    ctx->r24 = ADD32(ctx->r1, 0X68D0);
    // 0x80057BB0: nop

    // 0x80057BB4: jr          $t8
    // 0x80057BB8: nop

    switch (jr_addend_80057BB4 >> 2) {
        case 0: goto L_80057BBC; break;
        case 1: goto L_80057BE4; break;
        case 2: goto L_80057CD0; break;
        case 3: goto L_80057C0C; break;
        case 4: goto L_80057C34; break;
        case 5: goto L_80057C5C; break;
        case 6: goto L_80057C84; break;
        case 7: goto L_80057CAC; break;
        default: switch_error(__func__, 0x80057BB4, 0x800E68D0);
    }
    // 0x80057BB8: nop

L_80057BBC:
    // 0x80057BBC: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057BC0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057BC4: jal         0x800581E8
    // 0x80057BC8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_car(rdram, ctx);
        goto after_5;
    // 0x80057BC8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_5:
    // 0x80057BCC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057BD0: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057BD4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057BD8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057BDC: b           L_80057CD0
    // 0x80057BE0: nop

        goto L_80057CD0;
    // 0x80057BE0: nop

L_80057BE4:
    // 0x80057BE4: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057BE8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057BEC: jal         0x8004C2B0
    // 0x80057BF0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_plane(rdram, ctx);
        goto after_6;
    // 0x80057BF0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_6:
    // 0x80057BF4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057BF8: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057BFC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057C00: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057C04: b           L_80057CD0
    // 0x80057C08: nop

        goto L_80057CD0;
    // 0x80057C08: nop

L_80057C0C:
    // 0x80057C0C: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057C10: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057C14: jal         0x80058F44
    // 0x80057C18: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_fixed(rdram, ctx);
        goto after_7;
    // 0x80057C18: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_7:
    // 0x80057C1C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057C20: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057C24: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057C28: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057C2C: b           L_80057CD0
    // 0x80057C30: nop

        goto L_80057CD0;
    // 0x80057C30: nop

L_80057C34:
    // 0x80057C34: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057C38: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057C3C: jal         0x80048E64
    // 0x80057C40: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_hovercraft(rdram, ctx);
        goto after_8;
    // 0x80057C40: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_8:
    // 0x80057C44: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057C48: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057C4C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057C50: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057C54: b           L_80057CD0
    // 0x80057C58: nop

        goto L_80057CD0;
    // 0x80057C58: nop

L_80057C5C:
    // 0x80057C5C: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057C60: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057C64: jal         0x80058B84
    // 0x80057C68: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_finish_challenge(rdram, ctx);
        goto after_9;
    // 0x80057C68: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_9:
    // 0x80057C6C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057C70: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057C74: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057C78: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057C7C: b           L_80057CD0
    // 0x80057C80: nop

        goto L_80057CD0;
    // 0x80057C80: nop

L_80057C84:
    // 0x80057C84: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057C88: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057C8C: jal         0x8004D590
    // 0x80057C90: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_loop(rdram, ctx);
        goto after_10;
    // 0x80057C90: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_10:
    // 0x80057C94: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057C98: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057C9C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057CA0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057CA4: b           L_80057CD0
    // 0x80057CA8: nop

        goto L_80057CD0;
    // 0x80057CA8: nop

L_80057CAC:
    // 0x80057CAC: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057CB0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057CB4: jal         0x80058D5C
    // 0x80057CB8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_finish_race(rdram, ctx);
        goto after_11;
    // 0x80057CB8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_11:
    // 0x80057CBC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057CC0: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057CC4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057CC8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057CCC: nop

L_80057CD0:
    // 0x80057CD0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80057CD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057CD8: addiu       $v1, $v1, -0x2A7A
    ctx->r3 = ADD32(ctx->r3, -0X2A7A);
    // 0x80057CDC: lwc1        $f1, 0x68F0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X68F0);
    // 0x80057CE0: lwc1        $f0, 0x68F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X68F4);
    // 0x80057CE4: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80057CE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057CEC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80057CF0: lwc1        $f13, 0x68F8($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X68F8);
    // 0x80057CF4: lwc1        $f12, 0x68FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X68FC);
    // 0x80057CF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80057CFC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80057D00: lui         $at, 0x4620
    ctx->r1 = S32(0X4620 << 16);
    // 0x80057D04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80057D08: lwc1        $f18, 0x38($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X38);
    // 0x80057D0C: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80057D10: div.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80057D14: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80057D18: mul.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80057D1C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80057D20: lwc1        $f10, 0x50($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X50);
    // 0x80057D24: nop

    // 0x80057D28: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80057D2C: mul.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f12.d, ctx->f18.d);
    // 0x80057D30: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x80057D34: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80057D38: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x80057D3C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80057D40: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x80057D44: cvt.d.s     $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
    // 0x80057D48: mul.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x80057D4C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80057D50: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x80057D54: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80057D58: lwc1        $f10, 0x40($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X40);
    // 0x80057D5C: lwc1        $f6, 0x14($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X14);
    // 0x80057D60: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80057D64: mul.d       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80057D68: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80057D6C: lwc1        $f6, 0x58($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X58);
    // 0x80057D70: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057D74: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80057D78: mul.d       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f12.d, ctx->f10.d);
    // 0x80057D7C: add.d       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f16.d + ctx->f8.d;
    // 0x80057D80: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80057D84: add.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f4.d + ctx->f18.d;
    // 0x80057D88: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80057D8C: sub.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f16.d - ctx->f6.d;
    // 0x80057D90: mul.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x80057D94: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x80057D98: swc1        $f18, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f18.u32l;
    // 0x80057D9C: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x80057DA0: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80057DA4: jal         0x8003ACAC
    // 0x80057DA8: swc1        $f3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(3 - 1) * 2];
    get_npc_pos_y(rdram, ctx);
        goto after_12;
    // 0x80057DA8: swc1        $f3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(3 - 1) * 2];
    after_12:
    // 0x80057DAC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057DB0: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80057DB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057DB8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057DBC: lwc1        $f17, 0x6900($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6900);
    // 0x80057DC0: lwc1        $f16, 0x6904($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6904);
    // 0x80057DC4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80057DC8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80057DCC: add.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f8.d + ctx->f16.d;
    // 0x80057DD0: lwc1        $f3, 0x18($sp)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80057DD4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80057DD8: sub.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f6.d - ctx->f4.d;
    // 0x80057DDC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80057DE0: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80057DE4: mul.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x80057DE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80057DEC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80057DF0: addiu       $v1, $v1, -0x2A7A
    ctx->r3 = ADD32(ctx->r3, -0X2A7A);
    // 0x80057DF4: addiu       $t8, $zero, 0x2800
    ctx->r24 = ADD32(0, 0X2800);
    // 0x80057DF8: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80057DFC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80057E00: swc1        $f16, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f16.u32l;
    // 0x80057E04: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057E08: nop

    // 0x80057E0C: lh          $t2, 0x2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2);
    // 0x80057E10: nop

    // 0x80057E14: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80057E18: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80057E1C: nop

    // 0x80057E20: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80057E24: mul.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80057E28: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80057E2C: nop

    // 0x80057E30: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80057E34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80057E38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80057E3C: nop

    // 0x80057E40: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80057E44: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80057E48: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80057E4C: sh          $t5, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r13;
    // 0x80057E50: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057E54: nop

    // 0x80057E58: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80057E5C: lwc1        $f16, 0x24($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80057E60: nop

    // 0x80057E64: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80057E68: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80057E6C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057E70: nop

    // 0x80057E74: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80057E78: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80057E7C: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80057E80: add.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80057E84: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80057E88: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x80057E8C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057E90: nop

    // 0x80057E94: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80057E98: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80057E9C: nop

    // 0x80057EA0: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80057EA4: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x80057EA8: lw          $t6, -0x2AC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AC0);
    // 0x80057EAC: nop

    // 0x80057EB0: bne         $t6, $zero, L_80057F28
    if (ctx->r14 != 0) {
        // 0x80057EB4: nop
    
            goto L_80057F28;
    }
    // 0x80057EB4: nop

    // 0x80057EB8: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80057EBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057EC0: bne         $t7, $zero, L_80057F28
    if (ctx->r15 != 0) {
        // 0x80057EC4: nop
    
            goto L_80057F28;
    }
    // 0x80057EC4: nop

    // 0x80057EC8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057ECC: lwc1        $f1, 0x6908($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6908);
    // 0x80057ED0: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80057ED4: lwc1        $f0, 0x690C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X690C);
    // 0x80057ED8: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80057EDC: mul.d       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80057EE0: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80057EE4: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x80057EE8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057EEC: nop

    // 0x80057EF0: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80057EF4: nop

    // 0x80057EF8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80057EFC: mul.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80057F00: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x80057F04: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x80057F08: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057F0C: nop

    // 0x80057F10: lwc1        $f16, 0x2C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80057F14: nop

    // 0x80057F18: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80057F1C: mul.d       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80057F20: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80057F24: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
L_80057F28:
    // 0x80057F28: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80057F2C: nop

    // 0x80057F30: slti        $at, $a0, 0x1401
    ctx->r1 = SIGNED(ctx->r4) < 0X1401 ? 1 : 0;
    // 0x80057F34: bne         $at, $zero, L_80057F40
    if (ctx->r1 != 0) {
        // 0x80057F38: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80057F40;
    }
    // 0x80057F38: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80057F3C: subu        $v0, $t8, $a0
    ctx->r2 = SUB32(ctx->r24, ctx->r4);
L_80057F40:
    // 0x80057F40: slti        $at, $v0, 0x601
    ctx->r1 = SIGNED(ctx->r2) < 0X601 ? 1 : 0;
    // 0x80057F44: bne         $at, $zero, L_80057F50
    if (ctx->r1 != 0) {
        // 0x80057F48: nop
    
            goto L_80057F50;
    }
    // 0x80057F48: nop

    // 0x80057F4C: addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
L_80057F50:
    // 0x80057F50: lb          $t0, -0x2A7D($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2A7D);
    // 0x80057F54: sra         $t9, $v0, 4
    ctx->r25 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80057F58: beq         $t0, $zero, L_80057FBC
    if (ctx->r8 == 0) {
        // 0x80057F5C: addiu       $v0, $t9, 0x4
        ctx->r2 = ADD32(ctx->r25, 0X4);
            goto L_80057FBC;
    }
    // 0x80057F5C: addiu       $v0, $t9, 0x4
    ctx->r2 = ADD32(ctx->r25, 0X4);
    // 0x80057F60: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80057F64: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057F68: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80057F6C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80057F70: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80057F74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80057F78: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80057F7C: addiu       $t4, $zero, 0x2800
    ctx->r12 = ADD32(0, 0X2800);
    // 0x80057F80: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80057F84: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80057F88: multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057F8C: mflo        $t2
    ctx->r10 = lo;
    // 0x80057F90: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80057F94: sh          $t3, -0x2A7A($at)
    MEM_H(-0X2A7A, ctx->r1) = ctx->r11;
    // 0x80057F98: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80057F9C: nop

    // 0x80057FA0: slti        $at, $a0, 0x2801
    ctx->r1 = SIGNED(ctx->r4) < 0X2801 ? 1 : 0;
    // 0x80057FA4: bne         $at, $zero, L_8005800C
    if (ctx->r1 != 0) {
        // 0x80057FA8: nop
    
            goto L_8005800C;
    }
    // 0x80057FA8: nop

    // 0x80057FAC: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x80057FB0: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80057FB4: b           L_80058010
    // 0x80057FB8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
        goto L_80058010;
    // 0x80057FB8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_80057FBC:
    // 0x80057FBC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80057FC0: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057FC4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80057FC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80057FCC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80057FD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80057FD4: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80057FD8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80057FDC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80057FE0: multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057FE4: mflo        $t6
    ctx->r14 = lo;
    // 0x80057FE8: subu        $t7, $a0, $t6
    ctx->r15 = SUB32(ctx->r4, ctx->r14);
    // 0x80057FEC: sh          $t7, -0x2A7A($at)
    MEM_H(-0X2A7A, ctx->r1) = ctx->r15;
    // 0x80057FF0: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80057FF4: nop

    // 0x80057FF8: bgez        $a0, L_8005800C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80057FFC: nop
    
            goto L_8005800C;
    }
    // 0x80057FFC: nop

    // 0x80058000: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80058004: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80058008: nop

L_8005800C:
    // 0x8005800C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_80058010:
    // 0x80058010: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80058014: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80058018: nop

    // 0x8005801C: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
    // 0x80058020: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80058024: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80058028: nop

    // 0x8005802C: lb          $t0, 0x3A($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X3A);
    // 0x80058030: nop

    // 0x80058034: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x80058038: sb          $t1, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r9;
    // 0x8005803C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80058040: nop

    // 0x80058044: lb          $v1, 0x3A($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3A);
    // 0x80058048: nop

    // 0x8005804C: bgez        $v1, L_800580A8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80058050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800580A8;
    }
    // 0x80058050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058054: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80058058: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005805C: nop

    // 0x80058060: addiu       $t2, $v1, 0x5
    ctx->r10 = ADD32(ctx->r3, 0X5);
L_80058064:
    // 0x80058064: sb          $t2, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r10;
    // 0x80058068: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8005806C: nop

    // 0x80058070: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80058074: nop

    // 0x80058078: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x8005807C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80058080: mul.d       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80058084: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80058088: swc1        $f16, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f16.u32l;
    // 0x8005808C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80058090: nop

    // 0x80058094: lb          $v1, 0x3A($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3A);
    // 0x80058098: nop

    // 0x8005809C: bltz        $v1, L_80058064
    if (SIGNED(ctx->r3) < 0) {
        // 0x800580A0: addiu       $t2, $v1, 0x5
        ctx->r10 = ADD32(ctx->r3, 0X5);
            goto L_80058064;
    }
    // 0x800580A0: addiu       $t2, $v1, 0x5
    ctx->r10 = ADD32(ctx->r3, 0X5);
    // 0x800580A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800580A8:
    // 0x800580A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800580AC: jr          $ra
    // 0x800580B0: nop

    return;
    // 0x800580B0: nop

;}
RECOMP_FUNC void get_racer_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BACC: lw          $v0, -0x5110($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5110);
    // 0x8001BAD0: nop

    // 0x8001BAD4: bne         $v0, $zero, L_8001BAE4
    if (ctx->r2 != 0) {
        // 0x8001BAD8: nop
    
            goto L_8001BAE4;
    }
    // 0x8001BAD8: nop

    // 0x8001BADC: jr          $ra
    // 0x8001BAE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BAE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BAE4:
    // 0x8001BAE4: bltz        $a0, L_8001BAF4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001BAE8: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001BAF4;
    }
    // 0x8001BAE8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BAEC: bne         $at, $zero, L_8001BAFC
    if (ctx->r1 != 0) {
        // 0x8001BAF0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001BAFC;
    }
    // 0x8001BAF0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8001BAF4:
    // 0x8001BAF4: jr          $ra
    // 0x8001BAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BAFC:
    // 0x8001BAFC: lw          $t6, -0x511C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X511C);
    // 0x8001BB00: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001BB04: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001BB08: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001BB0C: nop

    // 0x8001BB10: jr          $ra
    // 0x8001BB14: nop

    return;
    // 0x8001BB14: nop

;}
RECOMP_FUNC void audspat_line_add_vertex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800098A4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800098A8: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    // 0x800098AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800098B0: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800098B4: lbu         $a3, 0x3($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3);
    // 0x800098B8: slti        $at, $a2, 0x7
    ctx->r1 = SIGNED(ctx->r6) < 0X7 ? 1 : 0;
    // 0x800098BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800098C0: beq         $at, $zero, L_80009960
    if (ctx->r1 == 0) {
        // 0x800098C4: andi        $t6, $a1, 0xFFFF
        ctx->r14 = ctx->r5 & 0XFFFF;
            goto L_80009960;
    }
    // 0x800098C4: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x800098C8: lbu         $v0, 0x33($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X33);
    // 0x800098CC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800098D0: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x800098D4: beq         $at, $zero, L_80009960
    if (ctx->r1 == 0) {
        // 0x800098D8: subu        $t7, $t7, $a2
        ctx->r15 = SUB32(ctx->r15, ctx->r6);
            goto L_80009960;
    }
    // 0x800098D8: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800098DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800098E0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800098E4: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800098E8: addiu       $t8, $t8, -0x63A8
    ctx->r24 = ADD32(ctx->r24, -0X63A8);
    // 0x800098EC: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x800098F0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800098F4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800098F8: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800098FC: addu        $a0, $v1, $t0
    ctx->r4 = ADD32(ctx->r3, ctx->r8);
    // 0x80009900: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x80009904: swc1        $f14, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f14.u32l;
    // 0x80009908: bne         $v0, $zero, L_80009948
    if (ctx->r2 != 0) {
        // 0x8000990C: swc1        $f4, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
            goto L_80009948;
    }
    // 0x8000990C: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80009910: sw          $t6, 0x16C($v1)
    MEM_W(0X16C, ctx->r3) = ctx->r14;
    // 0x80009914: lhu         $t1, 0x26($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X26);
    // 0x80009918: lbu         $t2, 0x2B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2B);
    // 0x8000991C: lbu         $t3, 0x1B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1B);
    // 0x80009920: lbu         $t4, 0x17($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X17);
    // 0x80009924: lbu         $t5, 0x1F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X1F);
    // 0x80009928: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8000992C: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80009930: sw          $t1, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->r9;
    // 0x80009934: sb          $t2, 0x17D($v1)
    MEM_B(0X17D, ctx->r3) = ctx->r10;
    // 0x80009938: sb          $t3, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r11;
    // 0x8000993C: sb          $t4, 0x175($v1)
    MEM_B(0X175, ctx->r3) = ctx->r12;
    // 0x80009940: sb          $t5, 0x176($v1)
    MEM_B(0X176, ctx->r3) = ctx->r13;
    // 0x80009944: sb          $t6, 0x17E($v1)
    MEM_B(0X17E, ctx->r3) = ctx->r14;
L_80009948:
    // 0x80009948: lb          $t7, 0x17C($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X17C);
    // 0x8000994C: nop

    // 0x80009950: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009954: beq         $at, $zero, L_80009960
    if (ctx->r1 == 0) {
        // 0x80009958: nop
    
            goto L_80009960;
    }
    // 0x80009958: nop

    // 0x8000995C: sb          $v0, 0x17C($v1)
    MEM_B(0X17C, ctx->r3) = ctx->r2;
L_80009960:
    // 0x80009960: jr          $ra
    // 0x80009964: nop

    return;
    // 0x80009964: nop

;}
RECOMP_FUNC void menu_file_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CAFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008CB00: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008CB04: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008CB08: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008CB0C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008CB10: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008CB14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CB18: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8008CB1C: jal         0x8006B224
    // 0x8008CB20: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    level_count(rdram, ctx);
        goto after_0;
    // 0x8008CB20: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8008CB24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CB28: jal         0x8009C674
    // 0x8008CB2C: addiu       $a0, $a0, 0x398
    ctx->r4 = ADD32(ctx->r4, 0X398);
    menu_assetgroup_load(rdram, ctx);
        goto after_1;
    // 0x8008CB2C: addiu       $a0, $a0, 0x398
    ctx->r4 = ADD32(ctx->r4, 0X398);
    after_1:
    // 0x8008CB30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CB34: jal         0x8009C8A4
    // 0x8008CB38: addiu       $a0, $a0, 0x3A4
    ctx->r4 = ADD32(ctx->r4, 0X3A4);
    menu_imagegroup_load(rdram, ctx);
        goto after_2;
    // 0x8008CB38: addiu       $a0, $a0, 0x3A4
    ctx->r4 = ADD32(ctx->r4, 0X3A4);
    after_2:
    // 0x8008CB3C: jal         0x8007FFEC
    // 0x8008CB40: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8007FFEC(rdram, ctx);
        goto after_3;
    // 0x8008CB40: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_3:
    // 0x8008CB44: jal         0x8006EBA8
    // 0x8008CB48: nop

    mark_read_all_save_files(rdram, ctx);
        goto after_4;
    // 0x8008CB48: nop

    after_4:
    // 0x8008CB4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008CB50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CB54: sw          $t6, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r14;
    // 0x8008CB58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CB5C: sw          $zero, -0xB34($at)
    MEM_W(-0XB34, ctx->r1) = 0;
    // 0x8008CB60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CB64: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x8008CB68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CB6C: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x8008CB70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CB74: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x8008CB78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CB7C: sw          $zero, 0x6484($at)
    MEM_W(0X6484, ctx->r1) = 0;
    // 0x8008CB80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CB84: sw          $zero, 0x6488($at)
    MEM_W(0X6488, ctx->r1) = 0;
    // 0x8008CB88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CB8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CB90: sw          $zero, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = 0;
    // 0x8008CB94: jal         0x800C01D8
    // 0x8008CB98: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_5;
    // 0x8008CB98: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_5:
    // 0x8008CB9C: jal         0x800C4170
    // 0x8008CBA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_6;
    // 0x8008CBA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8008CBA4: jal         0x80000B34
    // 0x8008CBA8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    music_play(rdram, ctx);
        goto after_7;
    // 0x8008CBA8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_7:
    // 0x8008CBAC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008CBB0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008CBB4: addiu       $s2, $s2, 0x63B4
    ctx->r18 = ADD32(ctx->r18, 0X63B4);
    // 0x8008CBB8: addiu       $s3, $s3, -0x24C
    ctx->r19 = ADD32(ctx->r19, -0X24C);
    // 0x8008CBBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008CBC0: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_8008CBC4:
    // 0x8008CBC4: lb          $t7, 0x0($s2)
    ctx->r15 = MEM_B(ctx->r18, 0X0);
    // 0x8008CBC8: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x8008CBCC: beq         $s0, $t7, L_8008CBEC
    if (ctx->r16 == ctx->r15) {
        // 0x8008CBD0: addu        $s1, $s3, $t8
        ctx->r17 = ADD32(ctx->r19, ctx->r24);
            goto L_8008CBEC;
    }
    // 0x8008CBD0: addu        $s1, $s3, $t8
    ctx->r17 = ADD32(ctx->r19, ctx->r24);
    // 0x8008CBD4: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8008CBD8: jal         0x80001114
    // 0x8008CBDC: nop

    music_channel_off(rdram, ctx);
        goto after_8;
    // 0x8008CBDC: nop

    after_8:
    // 0x8008CBE0: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8008CBE4: jal         0x80001114
    // 0x8008CBE8: nop

    music_channel_off(rdram, ctx);
        goto after_9;
    // 0x8008CBE8: nop

    after_9:
L_8008CBEC:
    // 0x8008CBEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008CBF0: bne         $s0, $s4, L_8008CBC4
    if (ctx->r16 != ctx->r20) {
        // 0x8008CBF4: nop
    
            goto L_8008CBC4;
    }
    // 0x8008CBF4: nop

    // 0x8008CBF8: jal         0x80001114
    // 0x8008CBFC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_channel_off(rdram, ctx);
        goto after_10;
    // 0x8008CBFC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_10:
    extern void dkr_character_menu_music_mask(uint8_t*, recomp_context*); dkr_character_menu_music_mask(rdram, ctx);
    // 0x8008CC00: jal         0x80000B18
    // 0x8008CC04: nop

    music_change_off(rdram, ctx);
        goto after_11;
    // 0x8008CC04: nop

    after_11:
    // 0x8008CC08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008CC0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CC10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CC14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008CC18: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008CC1C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008CC20: jr          $ra
    // 0x8008CC24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008CC24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void draw_dialogue_text_pos_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4510: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4518: bltz        $a1, L_800C4594
    if (SIGNED(ctx->r5) < 0) {
        // 0x800C451C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800C4594;
    }
    // 0x800C451C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C4520: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800C4524: beq         $at, $zero, L_800C4594
    if (ctx->r1 == 0) {
        // 0x800C4528: addiu       $v0, $zero, -0x8000
        ctx->r2 = ADD32(0, -0X8000);
            goto L_800C4594;
    }
    // 0x800C4528: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800C452C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C4530: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C4534: lw          $t8, -0x5818($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5818);
    // 0x800C4538: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800C453C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C4540: bne         $a2, $v0, L_800C455C
    if (ctx->r6 != ctx->r2) {
        // 0x800C4544: addu        $a1, $t7, $t8
        ctx->r5 = ADD32(ctx->r15, ctx->r24);
            goto L_800C455C;
    }
    // 0x800C4544: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800C4548: lh          $t9, 0xC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XC);
    // 0x800C454C: nop

    // 0x800C4550: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800C4554: b           L_800C4560
    // 0x800C4558: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
        goto L_800C4560;
    // 0x800C4558: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_800C455C:
    // 0x800C455C: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
L_800C4560:
    // 0x800C4560: bne         $a3, $v0, L_800C457C
    if (ctx->r7 != ctx->r2) {
        // 0x800C4564: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800C457C;
    }
    // 0x800C4564: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4568: lh          $t1, 0xE($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XE);
    // 0x800C456C: nop

    // 0x800C4570: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800C4574: b           L_800C4580
    // 0x800C4578: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
        goto L_800C4580;
    // 0x800C4578: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
L_800C457C:
    // 0x800C457C: sh          $a3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r7;
L_800C4580:
    // 0x800C4580: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C4584: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800C4588: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800C458C: jal         0x800C45A4
    // 0x800C4590: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C4590: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
L_800C4594:
    // 0x800C4594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4598: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C459C: jr          $ra
    // 0x800C45A0: nop

    return;
    // 0x800C45A0: nop

;}
