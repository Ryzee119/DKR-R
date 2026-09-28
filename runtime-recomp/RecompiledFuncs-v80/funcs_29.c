#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void gzip_inflate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6218: addiu       $t6, $a0, 0x5
    ctx->r14 = ADD32(ctx->r4, 0X5);
    // 0x800C621C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6220: sw          $t6, 0x3768($at)
    MEM_W(0X3768, ctx->r1) = ctx->r14;
    // 0x800C6224: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6228: sw          $a1, 0x376C($at)
    MEM_W(0X376C, ctx->r1) = ctx->r5;
    // 0x800C622C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6234: sw          $zero, -0x552C($at)
    MEM_W(-0X552C, ctx->r1) = 0;
    // 0x800C6238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C623C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6240: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C6244: jal         0x800C68C0
    // 0x800C6248: sw          $zero, -0x5530($at)
    MEM_W(-0X5530, ctx->r1) = 0;
    gzip_inflate_block(rdram, ctx);
        goto after_0;
    // 0x800C6248: sw          $zero, -0x5530($at)
    MEM_W(-0X5530, ctx->r1) = 0;
    after_0:
    // 0x800C624C: beq         $v0, $zero, L_800C6268
    if (ctx->r2 == 0) {
        // 0x800C6250: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C6268;
    }
    // 0x800C6250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C6254:
    // 0x800C6254: jal         0x800C68C0
    // 0x800C6258: nop

    gzip_inflate_block(rdram, ctx);
        goto after_1;
    // 0x800C6258: nop

    after_1:
    // 0x800C625C: bne         $v0, $zero, L_800C6254
    if (ctx->r2 != 0) {
        // 0x800C6260: nop
    
            goto L_800C6254;
    }
    // 0x800C6260: nop

    // 0x800C6264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C6268:
    // 0x800C6268: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800C626C: jr          $ra
    // 0x800C6270: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C6270: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void audioStopThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002A7C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002A80: jal         0x800C8AF0
    // 0x80002A84: addiu       $a0, $a0, 0x5FB0
    ctx->r4 = ADD32(ctx->r4, 0X5FB0);
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80002A84: addiu       $a0, $a0, 0x5FB0
    ctx->r4 = ADD32(ctx->r4, 0X5FB0);
    after_0:
    // 0x80002A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002A90: jr          $ra
    // 0x80002A94: nop

    return;
    // 0x80002A94: nop

;}
RECOMP_FUNC void get_player_selected_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C250: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C254: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C258: lb          $v0, 0x69C0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X69C0);
    // 0x8009C25C: jr          $ra
    // 0x8009C260: nop

    return;
    // 0x8009C260: nop

;}
RECOMP_FUNC void adventuretrack_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092E94: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80092E98: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80092E9C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80092EA0: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80092EA4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80092EA8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80092EAC: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80092EB0: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80092EB4: jal         0x8006EA90
    // 0x80092EB8: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80092EB8: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    after_0:
    // 0x80092EBC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80092EC0: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80092EC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80092EC8: bne         $t6, $zero, L_80092ED4
    if (ctx->r14 != 0) {
        // 0x80092ECC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80092ED4;
    }
    // 0x80092ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80092ED0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_80092ED4:
    // 0x80092ED4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80092ED8: lw          $t8, -0xB3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB3C);
    // 0x80092EDC: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80092EE0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80092EE4: addiu       $s2, $s2, 0x63A0
    ctx->r18 = ADD32(ctx->r18, 0X63A0);
    // 0x80092EE8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80092EEC: lb          $t0, 0x2($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X2);
    // 0x80092EF0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80092EF4: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80092EF8: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80092EFC: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x80092F00: lui         $t2, 0xB600
    ctx->r10 = S32(0XB600 << 16);
    // 0x80092F04: addiu       $t3, $zero, 0x1000
    ctx->r11 = ADD32(0, 0X1000);
    // 0x80092F08: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80092F0C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80092F10: sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    // 0x80092F14: jal         0x8009BD5C
    // 0x80092F18: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    menu_camera_centre(rdram, ctx);
        goto after_1;
    // 0x80092F18: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    after_1:
    // 0x80092F1C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80092F20: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x80092F24: jal         0x80067F2C
    // 0x80092F28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mtx_ortho(rdram, ctx);
        goto after_2;
    // 0x80092F28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80092F2C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80092F30: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80092F34: nop

    // 0x80092F38: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x80092F3C: bne         $at, $zero, L_800935E8
    if (ctx->r1 != 0) {
        // 0x80092F40: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_800935E8;
    }
    // 0x80092F40: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80092F44: beq         $at, $zero, L_800935EC
    if (ctx->r1 == 0) {
        // 0x80092F48: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800935EC;
    }
    // 0x80092F48: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80092F4C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80092F50: jal         0x8006B0F8
    // 0x80092F54: nop

    leveltable_vehicle_usable(rdram, ctx);
        goto after_3;
    // 0x80092F54: nop

    after_3:
    // 0x80092F58: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80092F5C: jal         0x8006BDDC
    // 0x80092F60: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    level_name(rdram, ctx);
        goto after_4;
    // 0x80092F60: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80092F64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80092F68: jal         0x800C42EC
    // 0x80092F6C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_5;
    // 0x80092F6C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80092F70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80092F74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80092F78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80092F7C: jal         0x800C43CC
    // 0x80092F80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_6;
    // 0x80092F80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80092F84: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80092F88: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80092F8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80092F90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80092F94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80092F98: jal         0x800C4384
    // 0x80092F9C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80092F9C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_7:
    // 0x80092FA0: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80092FA4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80092FA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80092FAC: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80092FB0: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // 0x80092FB4: jal         0x800C4440
    // 0x80092FB8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_8;
    // 0x80092FB8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_8:
    // 0x80092FBC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80092FC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80092FC4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80092FC8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80092FCC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80092FD0: jal         0x800C4384
    // 0x80092FD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_9;
    // 0x80092FD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80092FD8: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80092FDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80092FE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80092FE4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80092FE8: addiu       $a2, $zero, 0x2B
    ctx->r6 = ADD32(0, 0X2B);
    // 0x80092FEC: jal         0x800C4440
    // 0x80092FF0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_10;
    // 0x80092FF0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_10:
    // 0x80092FF4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80092FF8: jal         0x8006B14C
    // 0x80092FFC: nop

    leveltable_type(rdram, ctx);
        goto after_11;
    // 0x80092FFC: nop

    after_11:
    // 0x80093000: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x80093004: bne         $t8, $zero, L_800935EC
    if (ctx->r24 != 0) {
        // 0x80093008: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800935EC;
    }
    // 0x80093008: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8009300C: bne         $s1, $zero, L_80093514
    if (ctx->r17 != 0) {
        // 0x80093010: nop
    
            goto L_80093514;
    }
    // 0x80093010: nop

    // 0x80093014: jal         0x8000E4C8
    // 0x80093018: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_12;
    // 0x80093018: nop

    after_12:
    // 0x8009301C: beq         $v0, $zero, L_80093264
    if (ctx->r2 == 0) {
        // 0x80093020: nop
    
            goto L_80093264;
    }
    // 0x80093020: nop

    // 0x80093024: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80093028: jal         0x80092BE0
    // 0x8009302C: nop

    trackmenu_staff_beaten(rdram, ctx);
        goto after_13;
    // 0x8009302C: nop

    after_13:
    // 0x80093030: bltz        $v0, L_80093074
    if (SIGNED(ctx->r2) < 0) {
        // 0x80093034: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_80093074;
    }
    // 0x80093034: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80093038: lw          $t2, -0x89C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X89C);
    // 0x8009303C: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80093040: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80093044: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80093048: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8009304C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80093050: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80093054: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80093058: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009305C: addiu       $a1, $a1, 0x614
    ctx->r5 = ADD32(ctx->r5, 0X614);
    // 0x80093060: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093064: addiu       $a2, $zero, 0xCC
    ctx->r6 = ADD32(0, 0XCC);
    // 0x80093068: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8009306C: jal         0x80078AB8
    // 0x80093070: addiu       $a3, $a3, 0x7A
    ctx->r7 = ADD32(ctx->r7, 0X7A);
    texrect_draw(rdram, ctx);
        goto after_14;
    // 0x80093070: addiu       $a3, $a3, 0x7A
    ctx->r7 = ADD32(ctx->r7, 0X7A);
    after_14:
L_80093074:
    // 0x80093074: jal         0x800C42EC
    // 0x80093078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_15;
    // 0x80093078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x8009307C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80093080: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80093084: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80093088: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x8009308C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80093090: jal         0x800C4384
    // 0x80093094: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_text_colour(rdram, ctx);
        goto after_16;
    // 0x80093094: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_16:
    // 0x80093098: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009309C: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x800930A0: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800930A4: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800930A8: lw          $a3, 0x24($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X24);
    // 0x800930AC: addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
    // 0x800930B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800930B4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800930B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800930BC: jal         0x800C4440
    // 0x800930C0: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    draw_text(rdram, ctx);
        goto after_17;
    // 0x800930C0: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    after_17:
    // 0x800930C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800930C8: lw          $t6, -0xB60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB60);
    // 0x800930CC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800930D0: lw          $a3, 0x28($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X28);
    // 0x800930D4: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x800930D8: addiu       $a2, $a2, 0x5C
    ctx->r6 = ADD32(ctx->r6, 0X5C);
    // 0x800930DC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800930E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800930E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800930E8: jal         0x800C4440
    // 0x800930EC: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    draw_text(rdram, ctx);
        goto after_18;
    // 0x800930EC: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    after_18:
    // 0x800930F0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800930F4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800930F8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800930FC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80093100: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80093104: jal         0x800C4384
    // 0x80093108: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_text_colour(rdram, ctx);
        goto after_19;
    // 0x80093108: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_19:
    // 0x8009310C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80093110: lb          $t1, 0x69C0($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X69C0);
    // 0x80093114: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80093118: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8009311C: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x80093120: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80093124: lw          $t4, 0x30($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X30);
    // 0x80093128: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x8009312C: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x80093130: lhu         $a0, 0x0($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X0);
    // 0x80093134: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80093138: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8009313C: jal         0x800976F8
    // 0x80093140: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_20;
    // 0x80093140: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_20:
    // 0x80093144: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80093148: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009314C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093150: addiu       $a1, $zero, 0x102
    ctx->r5 = ADD32(0, 0X102);
    // 0x80093154: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80093158: jal         0x800C4440
    // 0x8009315C: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    draw_text(rdram, ctx);
        goto after_21;
    // 0x8009315C: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_21:
    // 0x80093160: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80093164: lb          $t8, 0x69C0($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X69C0);
    // 0x80093168: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8009316C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80093170: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x80093174: lw          $t0, 0x18($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X18);
    // 0x80093178: addiu       $s0, $sp, 0x54
    ctx->r16 = ADD32(ctx->r29, 0X54);
    // 0x8009317C: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x80093180: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x80093184: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80093188: jal         0x800976F8
    // 0x8009318C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_22;
    // 0x8009318C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_22:
    // 0x80093190: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80093194: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80093198: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009319C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800931A0: addiu       $a1, $zero, 0x102
    ctx->r5 = ADD32(0, 0X102);
    // 0x800931A4: jal         0x800C4440
    // 0x800931A8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_23;
    // 0x800931A8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_23:
    // 0x800931AC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x800931B0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800931B4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800931B8: lb          $t9, 0x69C0($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X69C0);
    // 0x800931BC: lw          $t5, -0xB3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB3C);
    // 0x800931C0: lw          $t4, 0x4C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4C);
    // 0x800931C4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800931C8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800931CC: lb          $t8, 0x2($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X2);
    // 0x800931D0: addu        $t0, $v0, $t1
    ctx->r8 = ADD32(ctx->r2, ctx->r9);
    // 0x800931D4: lw          $t2, 0x3C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X3C);
    // 0x800931D8: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800931DC: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x800931E0: lhu         $a0, 0x0($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X0);
    // 0x800931E4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800931E8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800931EC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800931F0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800931F4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800931F8: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x800931FC: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x80093200: jal         0x80081800
    // 0x80093204: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    menu_timestamp_render(rdram, ctx);
        goto after_24;
    // 0x80093204: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_24:
    // 0x80093208: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8009320C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80093210: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80093214: lw          $t7, -0xB3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB3C);
    // 0x80093218: lb          $t8, 0x69C0($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X69C0);
    // 0x8009321C: lw          $t2, 0x4C($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X4C);
    // 0x80093220: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80093224: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x80093228: lb          $t4, 0x2($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X2);
    // 0x8009322C: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x80093230: lw          $t0, 0x24($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X24);
    // 0x80093234: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80093238: addu        $t8, $t0, $t5
    ctx->r24 = ADD32(ctx->r8, ctx->r13);
    // 0x8009323C: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x80093240: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80093244: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x80093248: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009324C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80093250: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80093254: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80093258: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x8009325C: jal         0x80081800
    // 0x80093260: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    menu_timestamp_render(rdram, ctx);
        goto after_25;
    // 0x80093260: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_25:
L_80093264:
    // 0x80093264: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80093268: lw          $a2, 0x63BC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X63BC);
    // 0x8009326C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093270: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x80093274: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80093278: bne         $at, $zero, L_80093288
    if (ctx->r1 != 0) {
        // 0x8009327C: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80093288;
    }
    // 0x8009327C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80093280: addiu       $t2, $zero, 0x1FF
    ctx->r10 = ADD32(0, 0X1FF);
    // 0x80093284: subu        $a2, $t2, $t6
    ctx->r6 = SUB32(ctx->r10, ctx->r14);
L_80093288:
    // 0x80093288: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009328C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80093290: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80093294: jal         0x800C4FBC
    // 0x80093298: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_26;
    // 0x80093298: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_26:
    // 0x8009329C: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800932A0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800932A4: addiu       $t3, $v0, 0x89
    ctx->r11 = ADD32(ctx->r2, 0X89);
    // 0x800932A8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800932AC: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x800932B0: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    // 0x800932B4: jal         0x800C4EDC
    // 0x800932B8: addiu       $a2, $v0, 0x70
    ctx->r6 = ADD32(ctx->r2, 0X70);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_27;
    // 0x800932B8: addiu       $a2, $v0, 0x70
    ctx->r6 = ADD32(ctx->r2, 0X70);
    after_27:
    // 0x800932BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800932C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800932C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800932C8: jal         0x800C5B58
    // 0x800932CC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_28;
    // 0x800932CC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_28:
    // 0x800932D0: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800932D4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800932D8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800932DC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800932E0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800932E4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800932E8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800932EC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800932F0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800932F4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800932F8: addiu       $a1, $a1, 0x5B4
    ctx->r5 = ADD32(ctx->r5, 0X5B4);
    // 0x800932FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093300: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x80093304: jal         0x80078AB8
    // 0x80093308: addiu       $a3, $a3, 0x72
    ctx->r7 = ADD32(ctx->r7, 0X72);
    texrect_draw(rdram, ctx);
        goto after_29;
    // 0x80093308: addiu       $a3, $a3, 0x72
    ctx->r7 = ADD32(ctx->r7, 0X72);
    after_29:
    // 0x8009330C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80093310: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80093314: addiu       $s1, $t9, 0x8B
    ctx->r17 = ADD32(ctx->r25, 0X8B);
    // 0x80093318: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8009331C: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
L_80093320:
    // 0x80093320: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80093324: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80093328: beq         $at, $zero, L_8009334C
    if (ctx->r1 == 0) {
        // 0x8009332C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8009334C;
    }
    // 0x8009332C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80093330: jal         0x8006B0AC
    // 0x80093334: nop

    leveltable_vehicle_default(rdram, ctx);
        goto after_30;
    // 0x80093334: nop

    after_30:
    // 0x80093338: beq         $v0, $s0, L_8009334C
    if (ctx->r2 == ctx->r16) {
        // 0x8009333C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8009334C;
    }
    // 0x8009333C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80093340: b           L_8009334C
    // 0x80093344: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
        goto L_8009334C;
    // 0x80093344: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x80093348: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8009334C:
    // 0x8009334C: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80093350: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80093354: sllv        $t7, $t2, $s0
    ctx->r15 = S32(ctx->r10 << (ctx->r16 & 31));
    // 0x80093358: and         $t4, $t7, $t3
    ctx->r12 = ctx->r15 & ctx->r11;
    // 0x8009335C: beq         $t4, $zero, L_800933F4
    if (ctx->r12 == 0) {
        // 0x80093360: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_800933F4;
    }
    // 0x80093360: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80093364: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80093368: lb          $t9, 0x69C0($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X69C0);
    // 0x8009336C: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x80093370: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80093374: addiu       $t8, $t8, 0x624
    ctx->r24 = ADD32(ctx->r24, 0X624);
    // 0x80093378: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8009337C: bne         $s0, $t9, L_800933C0
    if (ctx->r16 != ctx->r25) {
        // 0x80093380: addu        $v1, $t5, $t8
        ctx->r3 = ADD32(ctx->r13, ctx->r24);
            goto L_800933C0;
    }
    // 0x80093380: addu        $v1, $t5, $t8
    ctx->r3 = ADD32(ctx->r13, ctx->r24);
    // 0x80093384: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x80093388: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009338C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80093390: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80093394: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80093398: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8009339C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800933A0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800933A4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800933A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800933AC: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    // 0x800933B0: jal         0x80078AB8
    // 0x800933B4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    texrect_draw(rdram, ctx);
        goto after_31;
    // 0x800933B4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_31:
    // 0x800933B8: b           L_800933F4
    // 0x800933BC: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
        goto L_800933F4;
    // 0x800933BC: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
L_800933C0:
    // 0x800933C0: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x800933C4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800933C8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800933CC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800933D0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800933D4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800933D8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800933DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800933E0: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    // 0x800933E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800933E8: jal         0x80078AB8
    // 0x800933EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    texrect_draw(rdram, ctx);
        goto after_32;
    // 0x800933EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_32:
    // 0x800933F0: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
L_800933F4:
    // 0x800933F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800933F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800933FC: bne         $s0, $at, L_80093320
    if (ctx->r16 != ctx->r1) {
        // 0x80093400: lw          $t6, 0x7C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X7C);
            goto L_80093320;
    }
    // 0x80093400: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80093404: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80093408: lb          $v0, 0x69C0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X69C0);
    // 0x8009340C: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80093410: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80093414: bne         $v0, $at, L_80093420
    if (ctx->r2 != ctx->r1) {
        // 0x80093418: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80093420;
    }
    // 0x80093418: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8009341C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_80093420:
    // 0x80093420: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80093424: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80093428: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8009342C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80093430: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80093434: lw          $a1, 0x624($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X624);
    // 0x80093438: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009343C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80093440: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80093444: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80093448: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8009344C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80093450: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80093454: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80093458: addiu       $a2, $zero, 0x95
    ctx->r6 = ADD32(0, 0X95);
    // 0x8009345C: jal         0x80078AB8
    // 0x80093460: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    texrect_draw(rdram, ctx);
        goto after_33;
    // 0x80093460: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_33:
    // 0x80093464: jal         0x8007B3D0
    // 0x80093468: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rendermode_reset(rdram, ctx);
        goto after_34;
    // 0x80093468: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_34:
    // 0x8009346C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80093470: addiu       $v0, $v0, -0x8A4
    ctx->r2 = ADD32(ctx->r2, -0X8A4);
    // 0x80093474: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x80093478: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009347C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80093480: lui         $at, 0xC250
    ctx->r1 = S32(0XC250 << 16);
    // 0x80093484: swc1        $f4, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f4.u32l;
    // 0x80093488: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8009348C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80093490: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093494: jal         0x8009CA60
    // 0x80093498: swc1        $f6, 0xF0($t3)
    MEM_W(0XF0, ctx->r11) = ctx->f6.u32l;
    menu_element_render(rdram, ctx);
        goto after_35;
    // 0x80093498: swc1        $f6, 0xF0($t3)
    MEM_W(0XF0, ctx->r11) = ctx->f6.u32l;
    after_35:
    // 0x8009349C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800934A0: lw          $t4, 0x63E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X63E0);
    // 0x800934A4: nop

    // 0x800934A8: beq         $t4, $zero, L_800935EC
    if (ctx->r12 == 0) {
        // 0x800934AC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800935EC;
    }
    // 0x800934AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800934B0: jal         0x800C42EC
    // 0x800934B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_36;
    // 0x800934B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_36:
    // 0x800934B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800934BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800934C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800934C4: jal         0x800C43CC
    // 0x800934C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_37;
    // 0x800934C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_37:
    // 0x800934CC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800934D0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800934D4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800934D8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800934DC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800934E0: jal         0x800C4384
    // 0x800934E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_38;
    // 0x800934E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_38:
    // 0x800934E8: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800934EC: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800934F0: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800934F4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800934F8: addiu       $a3, $a3, -0x7DC0
    ctx->r7 = ADD32(ctx->r7, -0X7DC0);
    // 0x800934FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80093500: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80093504: jal         0x800C4440
    // 0x80093508: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    draw_text(rdram, ctx);
        goto after_39;
    // 0x80093508: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    after_39:
    // 0x8009350C: b           L_800935EC
    // 0x80093510: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800935EC;
    // 0x80093510: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80093514:
    // 0x80093514: jal         0x800C42EC
    // 0x80093518: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_40;
    // 0x80093518: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_40:
    // 0x8009351C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80093520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80093528: jal         0x800C43CC
    // 0x8009352C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_41;
    // 0x8009352C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_41:
    // 0x80093530: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80093534: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80093538: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8009353C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80093540: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80093544: jal         0x800C4384
    // 0x80093548: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_42;
    // 0x80093548: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_42:
    // 0x8009354C: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80093550: nop

    // 0x80093554: addiu       $s0, $s0, 0xB0
    ctx->r16 = ADD32(ctx->r16, 0XB0);
    // 0x80093558: jal         0x8009EB20
    // 0x8009355C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    get_language(rdram, ctx);
        goto after_43;
    // 0x8009355C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    after_43:
    // 0x80093560: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80093564: bne         $v0, $at, L_80093590
    if (ctx->r2 != ctx->r1) {
        // 0x80093568: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80093590;
    }
    // 0x80093568: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8009356C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80093570: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x80093574: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80093578: lw          $a3, 0x34($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X34);
    // 0x8009357C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80093580: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80093584: jal         0x800C4440
    // 0x80093588: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_44;
    // 0x80093588: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_44:
    // 0x8009358C: addiu       $s1, $s0, 0x20
    ctx->r17 = ADD32(ctx->r16, 0X20);
L_80093590:
    // 0x80093590: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80093594: lw          $t6, -0xB60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB60);
    // 0x80093598: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8009359C: lw          $a3, 0x2C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X2C);
    // 0x800935A0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800935A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800935A8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x800935AC: jal         0x800C4440
    // 0x800935B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    draw_text(rdram, ctx);
        goto after_45;
    // 0x800935B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_45:
    // 0x800935B4: jal         0x8009EB20
    // 0x800935B8: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    get_language(rdram, ctx);
        goto after_46;
    // 0x800935B8: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    after_46:
    // 0x800935BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800935C0: beq         $v0, $at, L_800935E8
    if (ctx->r2 == ctx->r1) {
        // 0x800935C4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800935E8;
    }
    // 0x800935C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800935C8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800935CC: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x800935D0: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800935D4: lw          $a3, 0x34($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X34);
    // 0x800935D8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800935DC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x800935E0: jal         0x800C4440
    // 0x800935E4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    draw_text(rdram, ctx);
        goto after_47;
    // 0x800935E4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_47:
L_800935E8:
    // 0x800935E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800935EC:
    // 0x800935EC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800935F0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800935F4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800935F8: jr          $ra
    // 0x800935FC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800935FC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void light_add_from_object_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031F88: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80031F8C: addiu       $v1, $v1, -0x36A4
    ctx->r3 = ADD32(ctx->r3, -0X36A4);
    // 0x80031F90: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80031F94: lw          $t6, -0x36A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36A8);
    // 0x80031F98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031F9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031FA0: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80031FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031FA8: beq         $at, $zero, L_80032200
    if (ctx->r1 == 0) {
        // 0x80031FAC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80032200;
    }
    // 0x80031FAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80031FB0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80031FB4: lw          $t7, -0x36B0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X36B0);
    // 0x80031FB8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80031FBC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80031FC0: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x80031FC4: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80031FC8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80031FCC: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x80031FD0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80031FD4: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x80031FD8: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x80031FDC: lbu         $t3, 0x9($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X9);
    // 0x80031FE0: nop

    // 0x80031FE4: sb          $t3, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r11;
    // 0x80031FE8: lbu         $t4, 0xB($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XB);
    // 0x80031FEC: nop

    // 0x80031FF0: sb          $t4, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r12;
    // 0x80031FF4: lbu         $t5, 0xA($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XA);
    // 0x80031FF8: nop

    // 0x80031FFC: sb          $t5, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r13;
    // 0x80032000: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80032004: sw          $a0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r4;
    // 0x80032008: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8003200C: sb          $t7, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r15;
    // 0x80032010: lh          $t8, 0xC($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XC);
    // 0x80032014: nop

    // 0x80032018: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
    // 0x8003201C: lh          $t9, 0xE($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XE);
    // 0x80032020: lh          $t1, 0x6($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X6);
    // 0x80032024: sh          $t9, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r25;
    // 0x80032028: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x8003202C: lh          $t2, 0x8($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X8);
    // 0x80032030: sh          $t0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r8;
    // 0x80032034: lh          $t3, 0xA($a2)
    ctx->r11 = MEM_H(ctx->r6, 0XA);
    // 0x80032038: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8003203C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80032040: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80032044: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80032048: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003204C: swc1        $f6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
    // 0x80032050: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80032054: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    // 0x80032058: swc1        $f18, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f18.u32l;
    // 0x8003205C: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x80032060: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
    // 0x80032064: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80032068: sw          $t5, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r13;
    // 0x8003206C: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x80032070: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x80032074: sw          $zero, 0x30($a2)
    MEM_W(0X30, ctx->r6) = 0;
    // 0x80032078: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8003207C: sw          $t7, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r15;
    // 0x80032080: sh          $zero, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = 0;
    // 0x80032084: lbu         $t8, 0x4($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X4);
    // 0x80032088: sw          $zero, 0x34($a2)
    MEM_W(0X34, ctx->r6) = 0;
    // 0x8003208C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80032090: sw          $t9, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r25;
    // 0x80032094: sh          $zero, 0x40($a2)
    MEM_H(0X40, ctx->r6) = 0;
    // 0x80032098: lbu         $t0, 0x5($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X5);
    // 0x8003209C: sw          $zero, 0x38($a2)
    MEM_W(0X38, ctx->r6) = 0;
    // 0x800320A0: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800320A4: sw          $t1, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r9;
    // 0x800320A8: sh          $zero, 0x42($a2)
    MEM_H(0X42, ctx->r6) = 0;
    // 0x800320AC: lhu         $a0, 0x6($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6);
    // 0x800320B0: nop

    // 0x800320B4: beq         $a0, $at, L_80032128
    if (ctx->r4 == ctx->r1) {
        // 0x800320B8: nop
    
            goto L_80032128;
    }
    // 0x800320B8: nop

    // 0x800320BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800320C0: jal         0x8001E29C
    // 0x800320C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x800320C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800320C8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800320CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800320D0: sw          $v0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r2;
    // 0x800320D4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800320D8: addiu       $t3, $v0, 0x14
    ctx->r11 = ADD32(ctx->r2, 0X14);
    // 0x800320DC: andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
    // 0x800320E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800320E4: sh          $zero, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = 0;
    // 0x800320E8: sh          $zero, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = 0;
    // 0x800320EC: sh          $zero, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = 0;
    // 0x800320F0: sw          $t3, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r11;
    // 0x800320F4: blez        $a0, L_8003212C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800320F8: sh          $t2, 0x48($a2)
        MEM_H(0X48, ctx->r6) = ctx->r10;
            goto L_8003212C;
    }
    // 0x800320F8: sh          $t2, 0x48($a2)
    MEM_H(0X48, ctx->r6) = ctx->r10;
    // 0x800320FC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80032100:
    // 0x80032100: lhu         $t4, 0x4E($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X4E);
    // 0x80032104: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80032108: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003210C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80032110: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80032114: sh          $t6, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r14;
    // 0x80032118: bne         $at, $zero, L_80032100
    if (ctx->r1 != 0) {
        // 0x8003211C: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80032100;
    }
    // 0x8003211C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80032120: b           L_80032130
    // 0x80032124: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
        goto L_80032130;
    // 0x80032124: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
L_80032128:
    // 0x80032128: sw          $zero, 0x44($a2)
    MEM_W(0X44, ctx->r6) = 0;
L_8003212C:
    // 0x8003212C: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
L_80032130:
    // 0x80032130: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80032134: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80032138: bgez        $t7, L_8003214C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8003213C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8003214C;
    }
    // 0x8003213C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80032140: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80032144: nop

    // 0x80032148: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8003214C:
    // 0x8003214C: swc1        $f6, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f6.u32l;
    // 0x80032150: lhu         $t8, 0x14($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X14);
    // 0x80032154: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80032158: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8003215C: bgez        $t8, L_80032170
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80032160: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80032170;
    }
    // 0x80032160: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80032164: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80032168: nop

    // 0x8003216C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80032170:
    // 0x80032170: swc1        $f16, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f16.u32l;
    // 0x80032174: lhu         $t9, 0x16($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X16);
    // 0x80032178: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8003217C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80032180: bgez        $t9, L_80032194
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80032184: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80032194;
    }
    // 0x80032184: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80032188: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003218C: nop

    // 0x80032190: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_80032194:
    // 0x80032194: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80032198: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x8003219C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800321A0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800321A4: nop

    // 0x800321A8: div.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800321AC: swc1        $f8, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f8.u32l;
    // 0x800321B0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800321B4: swc1        $f10, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f10.u32l;
    // 0x800321B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800321BC: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x800321C0: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x800321C4: sh          $zero, 0x74($a2)
    MEM_H(0X74, ctx->r6) = 0;
    // 0x800321C8: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800321CC: sh          $t1, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r9;
    // 0x800321D0: sh          $zero, 0x78($a2)
    MEM_H(0X78, ctx->r6) = 0;
    // 0x800321D4: lbu         $t2, 0x1($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1);
    // 0x800321D8: sh          $zero, 0x76($a2)
    MEM_H(0X76, ctx->r6) = 0;
    // 0x800321DC: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800321E0: sh          $t3, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r11;
    // 0x800321E4: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
    // 0x800321E8: sb          $t4, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r12;
    // 0x800321EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800321F0: jal         0x80032424
    // 0x800321F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    light_update(rdram, ctx);
        goto after_1;
    // 0x800321F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800321F8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800321FC: nop

L_80032200:
    // 0x80032200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032204: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032208: jr          $ra
    // 0x8003220C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x8003220C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}
RECOMP_FUNC void shadow_generate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E234: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8002E238: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002E23C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002E240: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002E244: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8002E248: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002E24C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002E250: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002E254: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002E258: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002E25C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002E260: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E264: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E268: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002E26C: lh          $t7, 0x48($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X48);
    // 0x8002E270: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E274: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002E278: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8002E27C: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x8002E280: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002E284: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002E288: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8002E28C: bne         $s2, $t7, L_8002E2CC
    if (ctx->r18 != ctx->r15) {
        // 0x8002E290: or          $s6, $a1, $zero
        ctx->r22 = ctx->r5 | 0;
            goto L_8002E2CC;
    }
    // 0x8002E290: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8002E294: jal         0x8009C30C
    // 0x8002E298: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8002E298: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8002E29C: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002E2A0: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
    // 0x8002E2A4: beq         $t8, $zero, L_8002E2BC
    if (ctx->r24 == 0) {
        // 0x8002E2A8: andi        $t9, $v0, 0x20
        ctx->r25 = ctx->r2 & 0X20;
            goto L_8002E2BC;
    }
    // 0x8002E2A8: andi        $t9, $v0, 0x20
    ctx->r25 = ctx->r2 & 0X20;
    // 0x8002E2AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E2B0: lwc1        $f18, 0x5F48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5F48);
    // 0x8002E2B4: b           L_8002E2D0
    // 0x8002E2B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
        goto L_8002E2D0;
    // 0x8002E2B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8002E2BC:
    // 0x8002E2BC: beq         $t9, $zero, L_8002E2CC
    if (ctx->r25 == 0) {
        // 0x8002E2C0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8002E2CC;
    }
    // 0x8002E2C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E2C4: lwc1        $f18, 0x5F4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5F4C);
    // 0x8002E2C8: nop

L_8002E2CC:
    // 0x8002E2CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8002E2D0:
    // 0x8002E2D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E2D4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002E2D8: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002E2DC: addiu       $s3, $s3, -0x2F3C
    ctx->r19 = ADD32(ctx->r19, -0X2F3C);
    // 0x8002E2E0: addiu       $s1, $s1, -0x2F38
    ctx->r17 = ADD32(ctx->r17, -0X2F38);
    // 0x8002E2E4: sw          $s5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r21;
    // 0x8002E2E8: beq         $s6, $zero, L_8002E3F4
    if (ctx->r22 == 0) {
        // 0x8002E2EC: swc1        $f8, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
            goto L_8002E3F4;
    }
    // 0x8002E2EC: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x8002E2F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E2F4: sw          $zero, -0x2F48($at)
    MEM_W(-0X2F48, ctx->r1) = 0;
    // 0x8002E2F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002E2FC: lw          $t0, -0x2C9C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2C9C);
    // 0x8002E300: lw          $t1, 0x58($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X58);
    // 0x8002E304: nop

    // 0x8002E308: sh          $t0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r8;
    // 0x8002E30C: lw          $v0, 0x58($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X58);
    // 0x8002E310: nop

    // 0x8002E314: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x8002E318: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8002E31C: sll         $t2, $a1, 8
    ctx->r10 = S32(ctx->r5 << 8);
    // 0x8002E320: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8002E324: jal         0x8007B46C
    // 0x8002E328: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    set_animated_texture_header(rdram, ctx);
        goto after_1;
    // 0x8002E328: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8002E32C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E330: sw          $v0, -0x2F40($at)
    MEM_W(-0X2F40, ctx->r1) = ctx->r2;
    // 0x8002E334: lw          $t3, 0x40($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X40);
    // 0x8002E338: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002E33C: lh          $t4, 0x48($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X48);
    // 0x8002E340: addiu       $s4, $s4, -0x2F32
    ctx->r20 = ADD32(ctx->r20, -0X2F32);
    // 0x8002E344: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8002E348: sh          $t5, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r13;
    // 0x8002E34C: lw          $t6, 0x40($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X40);
    // 0x8002E350: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002E354: lh          $t7, 0x46($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X46);
    // 0x8002E358: lw          $t9, -0x2C7C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C7C);
    // 0x8002E35C: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002E360: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E364: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8002E368: beq         $t9, $zero, L_8002E384
    if (ctx->r25 == 0) {
        // 0x8002E36C: sh          $t8, -0x2F34($at)
        MEM_H(-0X2F34, ctx->r1) = ctx->r24;
            goto L_8002E384;
    }
    // 0x8002E36C: sh          $t8, -0x2F34($at)
    MEM_H(-0X2F34, ctx->r1) = ctx->r24;
    // 0x8002E370: jal         0x80066210
    // 0x8002E374: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x8002E374: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8002E378: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002E37C: bgtz        $v0, L_8002E390
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002E380: nop
    
            goto L_8002E390;
    }
    // 0x8002E380: nop

L_8002E384:
    // 0x8002E384: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002E388: nop

    // 0x8002E38C: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_8002E390:
    // 0x8002E390: lw          $t0, 0x58($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X58);
    // 0x8002E394: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002E398: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8002E39C: addiu       $v1, $v1, -0x2F28
    ctx->r3 = ADD32(ctx->r3, -0X2F28);
    // 0x8002E3A0: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8002E3A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002E3A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E3AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E3B0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8002E3B4: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002E3B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002E3BC: mul.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8002E3C0: addiu       $v0, $v0, -0x2F10
    ctx->r2 = ADD32(ctx->r2, -0X2F10);
    // 0x8002E3C4: swc1        $f0, -0x2F24($at)
    MEM_W(-0X2F24, ctx->r1) = ctx->f0.u32l;
    // 0x8002E3C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E3CC: swc1        $f0, -0x2F20($at)
    MEM_W(-0X2F20, ctx->r1) = ctx->f0.u32l;
    // 0x8002E3D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8002E3D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002E3D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E3DC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8002E3E0: lwc1        $f12, -0x2F24($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2F24);
    // 0x8002E3E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E3E8: lwc1        $f14, -0x2F20($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2F20);
    // 0x8002E3EC: b           L_8002E5C8
    // 0x8002E3F0: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
        goto L_8002E5C8;
    // 0x8002E3F0: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
L_8002E3F4:
    // 0x8002E3F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002E3F8: lw          $t1, -0x2C9C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2C9C);
    // 0x8002E3FC: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    // 0x8002E400: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E404: sh          $t1, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r9;
    // 0x8002E408: lw          $t3, 0x50($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X50);
    // 0x8002E40C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002E410: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8002E414: addiu       $s4, $s4, -0x2F32
    ctx->r20 = ADD32(ctx->r20, -0X2F32);
    // 0x8002E418: sw          $t4, -0x2F40($at)
    MEM_W(-0X2F40, ctx->r1) = ctx->r12;
    // 0x8002E41C: lw          $t5, 0x40($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X40);
    // 0x8002E420: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E424: lh          $t6, 0x44($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X44);
    // 0x8002E428: nop

    // 0x8002E42C: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8002E430: sh          $t7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r15;
    // 0x8002E434: lw          $t8, 0x40($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X40);
    // 0x8002E438: nop

    // 0x8002E43C: lh          $t9, 0x42($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X42);
    // 0x8002E440: nop

    // 0x8002E444: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8002E448: sh          $t0, -0x2F34($at)
    MEM_H(-0X2F34, ctx->r1) = ctx->r8;
    // 0x8002E44C: lh          $t1, 0x48($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X48);
    // 0x8002E450: nop

    // 0x8002E454: beq         $s2, $t1, L_8002E4EC
    if (ctx->r18 == ctx->r9) {
        // 0x8002E458: nop
    
            goto L_8002E4EC;
    }
    // 0x8002E458: nop

    // 0x8002E45C: lwc1        $f2, 0x30($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X30);
    // 0x8002E460: mtc1        $zero, $f13
    ctx->f_odd[(13 - 1) * 2] = 0;
    // 0x8002E464: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002E468: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8002E46C: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x8002E470: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002E474: bc1f        L_8002E484
    if (!c1cs) {
        // 0x8002E478: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8002E484;
    }
    // 0x8002E478: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002E47C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8002E480: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8002E484:
    // 0x8002E484: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002E488: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8002E48C: sub.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d - ctx->f4.d;
    // 0x8002E490: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002E494: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8002E498: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002E49C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8002E4A0: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x8002E4A4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8002E4A8: bc1f        L_8002E4BC
    if (!c1cs) {
        // 0x8002E4AC: nop
    
            goto L_8002E4BC;
    }
    // 0x8002E4AC: nop

    // 0x8002E4B0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002E4B4: nop

    // 0x8002E4B8: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8002E4BC:
    // 0x8002E4BC: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8002E4C0: nop

    // 0x8002E4C4: bc1f        L_8002E4D4
    if (!c1cs) {
        // 0x8002E4C8: nop
    
            goto L_8002E4D4;
    }
    // 0x8002E4C8: nop

    // 0x8002E4CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002E4D0: nop

L_8002E4D4:
    // 0x8002E4D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E4D8: lwc1        $f4, 0x5F50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5F50);
    // 0x8002E4DC: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002E4E0: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8002E4E4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002E4E8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
L_8002E4EC:
    // 0x8002E4EC: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    // 0x8002E4F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002E4F4: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8002E4F8: addiu       $v1, $v1, -0x2F28
    ctx->r3 = ADD32(ctx->r3, -0X2F28);
    // 0x8002E4FC: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8002E500: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002E504: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E50C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8002E510: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002E514: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002E518: mul.s       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8002E51C: addiu       $v0, $v0, -0x2F10
    ctx->r2 = ADD32(ctx->r2, -0X2F10);
    // 0x8002E520: swc1        $f0, -0x2F24($at)
    MEM_W(-0X2F24, ctx->r1) = ctx->f0.u32l;
    // 0x8002E524: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E528: swc1        $f0, -0x2F20($at)
    MEM_W(-0X2F20, ctx->r1) = ctx->f0.u32l;
    // 0x8002E52C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E530: lwc1        $f12, -0x2F24($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2F24);
    // 0x8002E534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E538: lwc1        $f14, -0x2F20($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2F20);
    // 0x8002E53C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002E540: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E544: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E548: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8002E54C: nop

    // 0x8002E550: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8002E554: swc1        $f10, -0x2F1C($at)
    MEM_W(-0X2F1C, ctx->r1) = ctx->f10.u32l;
    // 0x8002E558: lw          $t3, 0x40($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X40);
    // 0x8002E55C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8002E560: lh          $t4, 0x42($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X42);
    // 0x8002E564: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002E568: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002E56C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8002E570: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002E574: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002E578: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002E57C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002E580: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8002E584: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002E588: nop

    // 0x8002E58C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8002E590: nop

    // 0x8002E594: bc1f        L_8002E5AC
    if (!c1cs) {
        // 0x8002E598: nop
    
            goto L_8002E5AC;
    }
    // 0x8002E598: nop

    // 0x8002E59C: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8002E5A0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8002E5A4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002E5A8: nop

L_8002E5AC:
    // 0x8002E5AC: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002E5B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E5B4: addiu       $t5, $zero, -0x8000
    ctx->r13 = ADD32(0, -0X8000);
    // 0x8002E5B8: swc1        $f10, -0x2F0C($at)
    MEM_W(-0X2F0C, ctx->r1) = ctx->f10.u32l;
    // 0x8002E5BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E5C0: sh          $t5, -0x2F30($at)
    MEM_H(-0X2F30, ctx->r1) = ctx->r13;
    // 0x8002E5C4: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
L_8002E5C8:
    // 0x8002E5C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E5CC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8002E5D0: div.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8002E5D4: lh          $t4, 0x0($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X0);
    // 0x8002E5D8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8002E5DC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8002E5E0: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8002E5E4: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E5E8: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E5EC: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8002E5F0: lh          $a2, -0x2F34($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X2F34);
    // 0x8002E5F4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002E5F8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8002E5FC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002E600: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E604: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E608: nop

    // 0x8002E60C: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E610: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002E614: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002E618: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8002E61C: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8002E620: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002E624: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002E628: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002E62C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E630: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E634: nop

    // 0x8002E638: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E63C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002E640: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8002E644: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8002E648: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x8002E64C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002E650: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8002E654: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8002E658: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E65C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E660: nop

    // 0x8002E664: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E668: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002E66C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8002E670: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8002E674: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002E678: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002E67C: nop

    // 0x8002E680: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8002E684: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E688: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E68C: nop

    // 0x8002E690: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E694: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8002E698: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002E69C: jal         0x8002A134
    // 0x8002E6A0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    get_inside_segment_count_xyz(rdram, ctx);
        goto after_3;
    // 0x8002E6A0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_3:
    // 0x8002E6A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E6A8: sw          $zero, -0x3DD0($at)
    MEM_W(-0X3DD0, ctx->r1) = 0;
    // 0x8002E6AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E6B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002E6B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002E6B8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8002E6BC: sw          $zero, -0x4EE8($at)
    MEM_W(-0X4EE8, ctx->r1) = 0;
    // 0x8002E6C0: addiu       $a0, $a0, -0x4CD0
    ctx->r4 = ADD32(ctx->r4, -0X4CD0);
    // 0x8002E6C4: addiu       $v1, $v1, -0x4CE0
    ctx->r3 = ADD32(ctx->r3, -0X4CE0);
L_8002E6C8:
    // 0x8002E6C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002E6CC: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8002E6D0: bne         $at, $zero, L_8002E6C8
    if (ctx->r1 != 0) {
        // 0x8002E6D4: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_8002E6C8;
    }
    // 0x8002E6D4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8002E6D8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8002E6DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E6E0: sw          $v1, -0x2F18($at)
    MEM_W(-0X2F18, ctx->r1) = ctx->r3;
    // 0x8002E6E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E6E8: sw          $v1, -0x2F14($at)
    MEM_W(-0X2F14, ctx->r1) = ctx->r3;
    // 0x8002E6EC: blez        $v0, L_8002E860
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002E6F0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8002E860;
    }
    // 0x8002E6F0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002E6F4: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8002E6F8: addiu       $s3, $s3, -0x36E8
    ctx->r19 = ADD32(ctx->r19, -0X36E8);
    // 0x8002E6FC: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x8002E700: addiu       $s4, $zero, 0x44
    ctx->r20 = ADD32(0, 0X44);
L_8002E704:
    // 0x8002E704: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8002E708: nop

    // 0x8002E70C: bltz        $s0, L_8002E854
    if (SIGNED(ctx->r16) < 0) {
        // 0x8002E710: lw          $t5, 0x70($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X70);
            goto L_8002E854;
    }
    // 0x8002E710: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8002E714: beq         $s6, $zero, L_8002E764
    if (ctx->r22 == 0) {
        // 0x8002E718: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8002E764;
    }
    // 0x8002E718: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E71C: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E720: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8002E724: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8002E728: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002E72C: mflo        $t9
    ctx->r25 = lo;
    // 0x8002E730: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002E734: lb          $t1, 0x2B($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X2B);
    // 0x8002E738: nop

    // 0x8002E73C: beq         $t1, $zero, L_8002E764
    if (ctx->r9 == 0) {
        // 0x8002E740: nop
    
            goto L_8002E764;
    }
    // 0x8002E740: nop

    // 0x8002E744: lw          $t2, -0x2C7C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2C7C);
    // 0x8002E748: nop

    // 0x8002E74C: beq         $t2, $zero, L_8002E764
    if (ctx->r10 == 0) {
        // 0x8002E750: nop
    
            goto L_8002E764;
    }
    // 0x8002E750: nop

    // 0x8002E754: jal         0x8002EEEC
    // 0x8002E758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002EEEC(rdram, ctx);
        goto after_4;
    // 0x8002E758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8002E75C: b           L_8002E854
    // 0x8002E760: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
        goto L_8002E854;
    // 0x8002E760: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
L_8002E764:
    // 0x8002E764: lwc1        $f0, 0xC($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8002E768: lwc1        $f12, -0x2F24($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2F24);
    // 0x8002E76C: lwc1        $f2, 0x14($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8002E770: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8002E774: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8002E778: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002E77C: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8002E780: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002E784: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E788: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E78C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E790: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E794: lwc1        $f14, -0x2F20($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2F20);
    // 0x8002E798: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002E79C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002E7A0: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8002E7A4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8002E7A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002E7AC: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x8002E7B0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002E7B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E7B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E7BC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002E7C0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E7C4: addu        $a0, $t3, $t5
    ctx->r4 = ADD32(ctx->r11, ctx->r13);
    // 0x8002E7C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002E7CC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8002E7D0: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8002E7D4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002E7D8: nop

    // 0x8002E7DC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002E7E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E7E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E7E8: nop

    // 0x8002E7EC: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E7F0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002E7F4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8002E7F8: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8002E7FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002E800: nop

    // 0x8002E804: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002E808: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E80C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E810: nop

    // 0x8002E814: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002E818: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8002E81C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002E820: jal         0x800314DC
    // 0x8002E824: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    compute_grid_overlap_mask(rdram, ctx);
        goto after_5;
    // 0x8002E824: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_5:
    // 0x8002E828: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8002E82C: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8002E830: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E834: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8002E838: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002E83C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002E840: mflo        $t2
    ctx->r10 = lo;
    // 0x8002E844: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8002E848: jal         0x8002E904
    // 0x8002E84C: nop

    func_8002E904(rdram, ctx);
        goto after_6;
    // 0x8002E84C: nop

    after_6:
    // 0x8002E850: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
L_8002E854:
    // 0x8002E854: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002E858: bne         $s2, $t5, L_8002E704
    if (ctx->r18 != ctx->r13) {
        // 0x8002E85C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8002E704;
    }
    // 0x8002E85C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8002E860:
    // 0x8002E860: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002E864: lw          $t6, -0x3DD0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3DD0);
    // 0x8002E868: nop

    // 0x8002E86C: blez        $t6, L_8002E8B0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002E870: nop
    
            goto L_8002E8B0;
    }
    // 0x8002E870: nop

    // 0x8002E874: lw          $t7, 0x54($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X54);
    // 0x8002E878: nop

    // 0x8002E87C: beq         $t7, $zero, L_8002E8A0
    if (ctx->r15 == 0) {
        // 0x8002E880: nop
    
            goto L_8002E8A0;
    }
    // 0x8002E880: nop

    // 0x8002E884: bne         $s6, $zero, L_8002E8A0
    if (ctx->r22 != 0) {
        // 0x8002E888: nop
    
            goto L_8002E8A0;
    }
    // 0x8002E888: nop

    // 0x8002E88C: jal         0x8002FA64
    // 0x8002E890: nop

    func_8002FA64(rdram, ctx);
        goto after_7;
    // 0x8002E890: nop

    after_7:
    // 0x8002E894: lw          $t8, 0x54($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X54);
    // 0x8002E898: nop

    // 0x8002E89C: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
L_8002E8A0:
    // 0x8002E8A0: jal         0x8002F2AC
    // 0x8002E8A4: nop

    func_8002F2AC(rdram, ctx);
        goto after_8;
    // 0x8002E8A4: nop

    after_8:
    // 0x8002E8A8: jal         0x8002F440
    // 0x8002E8AC: nop

    func_8002F440(rdram, ctx);
        goto after_9;
    // 0x8002E8AC: nop

    after_9:
L_8002E8B0:
    // 0x8002E8B0: bne         $s6, $zero, L_8002E8CC
    if (ctx->r22 != 0) {
        // 0x8002E8B4: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8002E8CC;
    }
    // 0x8002E8B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002E8B8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002E8BC: lw          $t9, -0x2C9C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C9C);
    // 0x8002E8C0: lw          $t0, 0x50($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X50);
    // 0x8002E8C4: b           L_8002E8DC
    // 0x8002E8C8: sh          $t9, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r25;
        goto L_8002E8DC;
    // 0x8002E8C8: sh          $t9, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r25;
L_8002E8CC:
    // 0x8002E8CC: lw          $t1, -0x2C9C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2C9C);
    // 0x8002E8D0: lw          $t4, 0x58($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X58);
    // 0x8002E8D4: nop

    // 0x8002E8D8: sh          $t1, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r9;
L_8002E8DC:
    // 0x8002E8DC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002E8E0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002E8E4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002E8E8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002E8EC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002E8F0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002E8F4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8002E8F8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002E8FC: jr          $ra
    // 0x8002E900: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8002E900: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void postrace_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081F4C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80081F50: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80081F54: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80081F58: addiu       $s2, $s2, -0x86C
    ctx->r18 = ADD32(ctx->r18, -0X86C);
    // 0x80081F5C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80081F60: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80081F64: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80081F68: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80081F6C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x80081F70: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80081F74: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80081F78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081F7C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80081F80: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80081F84: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80081F88: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80081F8C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80081F90: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80081F94: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80081F98: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80081F9C: beq         $s6, $a3, L_800821B8
    if (ctx->r22 == ctx->r7) {
        // 0x80081FA0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800821B8;
    }
    // 0x80081FA0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80081FA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80081FA8: lw          $t7, 0x63C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63C4);
    // 0x80081FAC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80081FB0: bne         $t7, $zero, L_80081FF0
    if (ctx->r15 != 0) {
        // 0x80081FB4: nop
    
            goto L_80081FF0;
    }
    // 0x80081FB4: nop

    // 0x80081FB8: lw          $t8, -0xB44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB44);
    // 0x80081FBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80081FC0: blez        $t8, L_80081FF0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80081FC4: nop
    
            goto L_80081FF0;
    }
    // 0x80081FC4: nop

L_80081FC8:
    // 0x80081FC8: jal         0x8006A554
    // 0x80081FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x80081FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80081FD0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80081FD4: lw          $t9, -0xB44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB44);
    // 0x80081FD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80081FDC: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80081FE0: bne         $at, $zero, L_80081FC8
    if (ctx->r1 != 0) {
        // 0x80081FE4: or          $s1, $s1, $v0
        ctx->r17 = ctx->r17 | ctx->r2;
            goto L_80081FC8;
    }
    // 0x80081FE4: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    // 0x80081FE8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80081FEC: nop

L_80081FF0:
    // 0x80081FF0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80081FF4: addiu       $s0, $s0, 0x6854
    ctx->r16 = ADD32(ctx->r16, 0X6854);
    // 0x80081FF8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80081FFC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80082000: addu        $t1, $t0, $s3
    ctx->r9 = ADD32(ctx->r8, ctx->r19);
    // 0x80082004: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80082008: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008200C: addiu       $s5, $s5, 0x6860
    ctx->r21 = ADD32(ctx->r21, 0X6860);
    // 0x80082010: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_80082014:
    // 0x80082014: beq         $a3, $zero, L_80082034
    if (ctx->r7 == 0) {
        // 0x80082018: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80082034;
    }
    // 0x80082018: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8008201C: beq         $v0, $s3, L_80082094
    if (ctx->r2 == ctx->r19) {
        // 0x80082020: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80082094;
    }
    // 0x80082020: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80082024: beq         $v0, $s4, L_80082138
    if (ctx->r2 == ctx->r20) {
        // 0x80082028: andi        $t9, $s1, 0x9000
        ctx->r25 = ctx->r17 & 0X9000;
            goto L_80082138;
    }
    // 0x80082028: andi        $t9, $s1, 0x9000
    ctx->r25 = ctx->r17 & 0X9000;
    // 0x8008202C: b           L_80082180
    // 0x80082030: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_80082180;
    // 0x80082030: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80082034:
    // 0x80082034: andi        $t2, $s1, 0x9000
    ctx->r10 = ctx->r17 & 0X9000;
    // 0x80082038: beq         $t2, $zero, L_80082054
    if (ctx->r10 == 0) {
        // 0x8008203C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80082054;
    }
    // 0x8008203C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80082040: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80082044: sw          $s3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r19;
    // 0x80082048: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008204C: b           L_8008217C
    // 0x80082050: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
        goto L_8008217C;
    // 0x80082050: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
L_80082054:
    // 0x80082054: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80082058: lw          $v1, 0x6858($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6858);
    // 0x8008205C: nop

    // 0x80082060: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80082064: bne         $at, $zero, L_8008207C
    if (ctx->r1 != 0) {
        // 0x80082068: subu        $t3, $v0, $v1
        ctx->r11 = SUB32(ctx->r2, ctx->r3);
            goto L_8008207C;
    }
    // 0x80082068: subu        $t3, $v0, $v1
    ctx->r11 = SUB32(ctx->r2, ctx->r3);
    // 0x8008206C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80082070: sw          $s3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r19;
    // 0x80082074: b           L_8008217C
    // 0x80082078: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
        goto L_8008217C;
    // 0x80082078: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
L_8008207C:
    // 0x8008207C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80082080: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80082084: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082088: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008208C: b           L_8008217C
    // 0x80082090: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
        goto L_8008217C;
    // 0x80082090: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
L_80082094:
    // 0x80082094: lw          $v1, 0x685C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X685C);
    // 0x80082098: andi        $v0, $s1, 0x9000
    ctx->r2 = ctx->r17 & 0X9000;
    // 0x8008209C: bgez        $v1, L_800820A8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800820A0: nop
    
            goto L_800820A8;
    }
    // 0x800820A0: nop

    // 0x800820A4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800820A8:
    // 0x800820A8: beq         $v0, $zero, L_800820E0
    if (ctx->r2 == 0) {
        // 0x800820AC: nop
    
            goto L_800820E0;
    }
    // 0x800820AC: nop

    // 0x800820B0: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x800820B4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800820B8: slt         $at, $zero, $t5
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800820BC: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
    // 0x800820C0: beq         $at, $zero, L_800820D4
    if (ctx->r1 == 0) {
        // 0x800820C4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800820D4;
    }
    // 0x800820C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800820C8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800820CC: jal         0x80001D04
    // 0x800820D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800820D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_800820D4:
    // 0x800820D4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800820D8: b           L_80082180
    // 0x800820DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_80082180;
    // 0x800820DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_800820E0:
    // 0x800820E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800820E4: nop

    // 0x800820E8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800820EC: bne         $at, $zero, L_80082120
    if (ctx->r1 != 0) {
        // 0x800820F0: subu        $t6, $v0, $v1
        ctx->r14 = SUB32(ctx->r2, ctx->r3);
            goto L_80082120;
    }
    // 0x800820F0: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // 0x800820F4: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800820F8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800820FC: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80082100: beq         $at, $zero, L_80082114
    if (ctx->r1 == 0) {
        // 0x80082104: sw          $s4, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r20;
            goto L_80082114;
    }
    // 0x80082104: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
    // 0x80082108: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008210C: jal         0x80001D04
    // 0x80082110: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80082110: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_80082114:
    // 0x80082114: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80082118: b           L_80082180
    // 0x8008211C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_80082180;
    // 0x8008211C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80082120:
    // 0x80082120: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80082124: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80082128: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008212C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082130: b           L_8008217C
    // 0x80082134: div.s       $f20, $f18, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
        goto L_8008217C;
    // 0x80082134: div.s       $f20, $f18, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
L_80082138:
    // 0x80082138: bne         $t9, $zero, L_80082158
    if (ctx->r25 != 0) {
        // 0x8008213C: nop
    
            goto L_80082158;
    }
    // 0x8008213C: nop

    // 0x80082140: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80082144: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80082148: nop

    // 0x8008214C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80082150: bne         $at, $zero, L_80082164
    if (ctx->r1 != 0) {
        // 0x80082154: nop
    
            goto L_80082164;
    }
    // 0x80082154: nop

L_80082158:
    // 0x80082158: sw          $s6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r22;
    // 0x8008215C: b           L_8008217C
    // 0x80082160: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
        goto L_8008217C;
    // 0x80082160: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
L_80082164:
    // 0x80082164: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80082168: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8008216C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80082170: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80082174: nop

    // 0x80082178: div.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
L_8008217C:
    // 0x8008217C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80082180:
    // 0x80082180: nop

    // 0x80082184: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x80082188: nop

    // 0x8008218C: bc1f        L_8008219C
    if (!c1cs) {
        // 0x80082190: nop
    
            goto L_8008219C;
    }
    // 0x80082190: nop

    // 0x80082194: bne         $s6, $a3, L_80082014
    if (ctx->r22 != ctx->r7) {
        // 0x80082198: nop
    
            goto L_80082014;
    }
    // 0x80082198: nop

L_8008219C:
    // 0x8008219C: beq         $s6, $a3, L_800821B8
    if (ctx->r22 == ctx->r7) {
        // 0x800821A0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_800821B8;
    }
    // 0x800821A0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800821A4: lw          $a1, -0x868($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X868);
    // 0x800821A8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800821AC: jal         0x800821EC
    // 0x800821B0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    draw_menu_elements(rdram, ctx);
        goto after_3;
    // 0x800821B0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x800821B4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800821B8:
    // 0x800821B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800821BC: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800821C0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800821C4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800821C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800821CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800821D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800821D4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800821D8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800821DC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800821E0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800821E4: jr          $ra
    // 0x800821E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800821E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bgload_tick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C73F0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C73F4: lw          $t6, 0x3770($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3770);
    // 0x800C73F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C73FC: beq         $t6, $zero, L_800C7438
    if (ctx->r14 == 0) {
        // 0x800C7400: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C7438;
    }
    // 0x800C7400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7404: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C7408: addiu       $v1, $v1, 0x377C
    ctx->r3 = ADD32(ctx->r3, 0X377C);
    // 0x800C740C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C7410: nop

    // 0x800C7414: blez        $v0, L_800C7438
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C7418: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800C7438;
    }
    // 0x800C7418: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800C741C: bne         $t7, $zero, L_800C7438
    if (ctx->r15 != 0) {
        // 0x800C7420: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_800C7438;
    }
    // 0x800C7420: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C7424: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C7428: addiu       $a0, $a0, -0x5360
    ctx->r4 = ADD32(ctx->r4, -0X5360);
    // 0x800C742C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C7430: jal         0x800C8E30
    // 0x800C7434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7434: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_800C7438:
    // 0x800C7438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C743C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7440: jr          $ra
    // 0x800C7444: nop

    return;
    // 0x800C7444: nop

;}
RECOMP_FUNC void run_object_init_func(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800238BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800238C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800238C4: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800238C8: nop

    // 0x800238CC: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x800238D0: nop

    // 0x800238D4: sh          $t7, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r15;
    // 0x800238D8: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    // 0x800238DC: nop

    // 0x800238E0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800238E4: sltiu       $at, $t9, 0x76
    ctx->r1 = ctx->r25 < 0X76 ? 1 : 0;
    // 0x800238E8: beq         $at, $zero, L_80023E20
    if (ctx->r1 == 0) {
        // 0x800238EC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80023E20;
    }
    // 0x800238EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800238F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800238F4: addu        $at, $at, $t9
    gpr jr_addend_80023900 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800238F8: lw          $t9, 0x5864($at)
    ctx->r25 = ADD32(ctx->r1, 0X5864);
    // 0x800238FC: nop

    // 0x80023900: jr          $t9
    // 0x80023904: nop

    switch (jr_addend_80023900 >> 2) {
        case 0: goto L_80023908; break;
        case 1: goto L_80023918; break;
        case 2: goto L_80023928; break;
        case 3: goto L_80023938; break;
        case 4: goto L_80023A78; break;
        case 5: goto L_80023948; break;
        case 6: goto L_80023978; break;
        case 7: goto L_80023988; break;
        case 8: goto L_80023998; break;
        case 9: goto L_800239B8; break;
        case 10: goto L_800239C8; break;
        case 11: goto L_800239D8; break;
        case 12: goto L_800239E8; break;
        case 13: goto L_80023A18; break;
        case 14: goto L_80023A38; break;
        case 15: goto L_80023A48; break;
        case 16: goto L_80023A58; break;
        case 17: goto L_80023A78; break;
        case 18: goto L_80023998; break;
        case 19: goto L_80023E20; break;
        case 20: goto L_80023E20; break;
        case 21: goto L_80023968; break;
        case 22: goto L_80023A68; break;
        case 23: goto L_80023E20; break;
        case 24: goto L_80023958; break;
        case 25: goto L_80023A88; break;
        case 26: goto L_800239A8; break;
        case 27: goto L_80023A98; break;
        case 28: goto L_80023AA8; break;
        case 29: goto L_800239F8; break;
        case 30: goto L_80023AB8; break;
        case 31: goto L_80023AC8; break;
        case 32: goto L_80023AD8; break;
        case 33: goto L_80023E20; break;
        case 34: goto L_80023E20; break;
        case 35: goto L_80023AE8; break;
        case 36: goto L_80023B08; break;
        case 37: goto L_80023B18; break;
        case 38: goto L_80023B28; break;
        case 39: goto L_80023B38; break;
        case 40: goto L_80023A08; break;
        case 41: goto L_80023E20; break;
        case 42: goto L_80023B48; break;
        case 43: goto L_80023B58; break;
        case 44: goto L_80023B68; break;
        case 45: goto L_80023B78; break;
        case 46: goto L_80023B88; break;
        case 47: goto L_80023E20; break;
        case 48: goto L_80023B98; break;
        case 49: goto L_80023E20; break;
        case 50: goto L_80023E20; break;
        case 51: goto L_80023BA8; break;
        case 52: goto L_80023E20; break;
        case 53: goto L_80023E20; break;
        case 54: goto L_80023BB8; break;
        case 55: goto L_80023E20; break;
        case 56: goto L_80023BC8; break;
        case 57: goto L_80023BD8; break;
        case 58: goto L_80023BE8; break;
        case 59: goto L_80023E20; break;
        case 60: goto L_80023BF8; break;
        case 61: goto L_80023C08; break;
        case 62: goto L_80023E20; break;
        case 63: goto L_80023C18; break;
        case 64: goto L_80023C28; break;
        case 65: goto L_80023C38; break;
        case 66: goto L_80023AF8; break;
        case 67: goto L_80023C48; break;
        case 68: goto L_80023C58; break;
        case 69: goto L_80023C68; break;
        case 70: goto L_80023CA8; break;
        case 71: goto L_80023C78; break;
        case 72: goto L_80023CD8; break;
        case 73: goto L_80023CE8; break;
        case 74: goto L_80023CF8; break;
        case 75: goto L_80023D08; break;
        case 76: goto L_80023D18; break;
        case 77: goto L_80023D28; break;
        case 78: goto L_80023D38; break;
        case 79: goto L_80023E20; break;
        case 80: goto L_80023E20; break;
        case 81: goto L_80023D48; break;
        case 82: goto L_80023D58; break;
        case 83: goto L_80023D68; break;
        case 84: goto L_80023E20; break;
        case 85: goto L_80023E20; break;
        case 86: goto L_80023E20; break;
        case 87: goto L_80023D88; break;
        case 88: goto L_80023D78; break;
        case 89: goto L_80023D98; break;
        case 90: goto L_80023E20; break;
        case 91: goto L_80023E20; break;
        case 92: goto L_80023BC8; break;
        case 93: goto L_80023DA8; break;
        case 94: goto L_80023C78; break;
        case 95: goto L_80023C88; break;
        case 96: goto L_80023C98; break;
        case 97: goto L_80023DB8; break;
        case 98: goto L_80023DC8; break;
        case 99: goto L_80023DC8; break;
        case 100: goto L_80023C88; break;
        case 101: goto L_80023C98; break;
        case 102: goto L_80023C68; break;
        case 103: goto L_80023C78; break;
        case 104: goto L_80023DD8; break;
        case 105: goto L_80023E20; break;
        case 106: goto L_80023E20; break;
        case 107: goto L_80023DE8; break;
        case 108: goto L_80023DF8; break;
        case 109: goto L_80023E08; break;
        case 110: goto L_80023A28; break;
        case 111: goto L_80023CB8; break;
        case 112: goto L_80023E20; break;
        case 113: goto L_80023E20; break;
        case 114: goto L_80023E20; break;
        case 115: goto L_80023DE8; break;
        case 116: goto L_80023E18; break;
        case 117: goto L_80023CC8; break;
        default: switch_error(__func__, 0x80023900, 0x800E5864);
    }
    // 0x80023904: nop

L_80023908:
    // 0x80023908: jal         0x8004DAB0
    // 0x8002390C: nop

    obj_init_racer(rdram, ctx);
        goto after_0;
    // 0x8002390C: nop

    after_0:
    // 0x80023910: b           L_80023E24
    // 0x80023914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023918:
    // 0x80023918: jal         0x80033CC0
    // 0x8002391C: nop

    obj_init_scenery(rdram, ctx);
        goto after_1;
    // 0x8002391C: nop

    after_1:
    // 0x80023920: b           L_80023E24
    // 0x80023924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023928:
    // 0x80023928: jal         0x80036C30
    // 0x8002392C: nop

    obj_init_fish(rdram, ctx);
        goto after_2;
    // 0x8002392C: nop

    after_2:
    // 0x80023930: b           L_80023E24
    // 0x80023934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023938:
    // 0x80023938: jal         0x800376E0
    // 0x8002393C: nop

    obj_init_animator(rdram, ctx);
        goto after_3;
    // 0x8002393C: nop

    after_3:
    // 0x80023940: b           L_80023E24
    // 0x80023944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023948:
    // 0x80023948: jal         0x800389AC
    // 0x8002394C: nop

    obj_init_smoke(rdram, ctx);
        goto after_4;
    // 0x8002394C: nop

    after_4:
    // 0x80023950: b           L_80023E24
    // 0x80023954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023958:
    // 0x80023958: jal         0x80038A6C
    // 0x8002395C: nop

    obj_init_unknown25(rdram, ctx);
        goto after_5;
    // 0x8002395C: nop

    after_5:
    // 0x80023960: b           L_80023E24
    // 0x80023964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023968:
    // 0x80023968: jal         0x80038B74
    // 0x8002396C: nop

    obj_init_bombexplosion(rdram, ctx);
        goto after_6;
    // 0x8002396C: nop

    after_6:
    // 0x80023970: b           L_80023E24
    // 0x80023974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023978:
    // 0x80023978: jal         0x80038E3C
    // 0x8002397C: nop

    obj_init_exit(rdram, ctx);
        goto after_7;
    // 0x8002397C: nop

    after_7:
    // 0x80023980: b           L_80023E24
    // 0x80023984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023988:
    // 0x80023988: jal         0x8003FD68
    // 0x8002398C: nop

    obj_init_audio(rdram, ctx);
        goto after_8;
    // 0x8002398C: nop

    after_8:
    // 0x80023990: b           L_80023E24
    // 0x80023994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023998:
    // 0x80023998: jal         0x8003FEF4
    // 0x8002399C: nop

    obj_init_audioline(rdram, ctx);
        goto after_9;
    // 0x8002399C: nop

    after_9:
    // 0x800239A0: b           L_80023E24
    // 0x800239A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x800239A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239A8:
    // 0x800239A8: jal         0x8004001C
    // 0x800239AC: nop

    obj_init_audioreverb(rdram, ctx);
        goto after_10;
    // 0x800239AC: nop

    after_10:
    // 0x800239B0: b           L_80023E24
    // 0x800239B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x800239B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239B8:
    // 0x800239B8: jal         0x80039160
    // 0x800239BC: nop

    obj_init_cameracontrol(rdram, ctx);
        goto after_11;
    // 0x800239BC: nop

    after_11:
    // 0x800239C0: b           L_80023E24
    // 0x800239C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x800239C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239C8:
    // 0x800239C8: jal         0x80039190
    // 0x800239CC: nop

    obj_init_setuppoint(rdram, ctx);
        goto after_12;
    // 0x800239CC: nop

    after_12:
    // 0x800239D0: b           L_80023E24
    // 0x800239D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x800239D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239D8:
    // 0x800239D8: jal         0x800391C8
    // 0x800239DC: nop

    obj_init_dino_whale(rdram, ctx);
        goto after_13;
    // 0x800239DC: nop

    after_13:
    // 0x800239E0: b           L_80023E24
    // 0x800239E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x800239E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239E8:
    // 0x800239E8: jal         0x8003ACBC
    // 0x800239EC: nop

    obj_init_checkpoint(rdram, ctx);
        goto after_14;
    // 0x800239EC: nop

    after_14:
    // 0x800239F0: b           L_80023E24
    // 0x800239F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x800239F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800239F8:
    // 0x800239F8: jal         0x8003AD34
    // 0x800239FC: nop

    obj_init_modechange(rdram, ctx);
        goto after_15;
    // 0x800239FC: nop

    after_15:
    // 0x80023A00: b           L_80023E24
    // 0x80023A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A08:
    // 0x80023A08: jal         0x8003B058
    // 0x80023A0C: nop

    obj_init_bonus(rdram, ctx);
        goto after_16;
    // 0x80023A0C: nop

    after_16:
    // 0x80023A10: b           L_80023E24
    // 0x80023A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A18:
    // 0x80023A18: jal         0x8003B7CC
    // 0x80023A1C: nop

    obj_init_door(rdram, ctx);
        goto after_17;
    // 0x80023A1C: nop

    after_17:
    // 0x80023A20: b           L_80023E24
    // 0x80023A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A28:
    // 0x80023A28: jal         0x8003C1E0
    // 0x80023A2C: nop

    obj_init_ttdoor(rdram, ctx);
        goto after_18;
    // 0x80023A2C: nop

    after_18:
    // 0x80023A30: b           L_80023E24
    // 0x80023A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A38:
    // 0x80023A38: jal         0x8003CF18
    // 0x80023A3C: nop

    obj_init_fogchanger(rdram, ctx);
        goto after_19;
    // 0x80023A3C: nop

    after_19:
    // 0x80023A40: b           L_80023E24
    // 0x80023A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A48:
    // 0x80023A48: jal         0x8003CFE0
    // 0x80023A4C: nop

    obj_init_ainode(rdram, ctx);
        goto after_20;
    // 0x80023A4C: nop

    after_20:
    // 0x80023A50: b           L_80023E24
    // 0x80023A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A58:
    // 0x80023A58: jal         0x8003DFCC
    // 0x80023A5C: nop

    obj_init_weaponballoon(rdram, ctx);
        goto after_21;
    // 0x80023A5C: nop

    after_21:
    // 0x80023A60: b           L_80023E24
    // 0x80023A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A68:
    // 0x80023A68: jal         0x8003E5B0
    // 0x80023A6C: nop

    obj_init_wballoonpop(rdram, ctx);
        goto after_22;
    // 0x80023A6C: nop

    after_22:
    // 0x80023A70: b           L_80023E24
    // 0x80023A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A78:
    // 0x80023A78: jal         0x8003E5C8
    // 0x80023A7C: nop

    obj_init_weapon(rdram, ctx);
        goto after_23;
    // 0x80023A7C: nop

    after_23:
    // 0x80023A80: b           L_80023E24
    // 0x80023A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A88:
    // 0x80023A88: jal         0x8003CF58
    // 0x80023A8C: nop

    obj_init_skycontrol(rdram, ctx);
        goto after_24;
    // 0x80023A8C: nop

    after_24:
    // 0x80023A90: b           L_80023E24
    // 0x80023A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023A98:
    // 0x80023A98: jal         0x80034AF0
    // 0x80023A9C: nop

    obj_init_torch_mist(rdram, ctx);
        goto after_25;
    // 0x80023A9C: nop

    after_25:
    // 0x80023AA0: b           L_80023E24
    // 0x80023AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AA8:
    // 0x80023AA8: jal         0x800400A4
    // 0x80023AAC: nop

    obj_init_texscroll(rdram, ctx);
        goto after_26;
    // 0x80023AAC: nop

    after_26:
    // 0x80023AB0: b           L_80023E24
    // 0x80023AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AB8:
    // 0x80023AB8: jal         0x80036194
    // 0x80023ABC: nop

    obj_init_stopwatchman(rdram, ctx);
        goto after_27;
    // 0x80023ABC: nop

    after_27:
    // 0x80023AC0: b           L_80023E24
    // 0x80023AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AC8:
    // 0x80023AC8: jal         0x8003D534
    // 0x80023ACC: nop

    obj_init_banana(rdram, ctx);
        goto after_28;
    // 0x80023ACC: nop

    after_28:
    // 0x80023AD0: b           L_80023E24
    // 0x80023AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AD8:
    // 0x80023AD8: jal         0x800403A8
    // 0x80023ADC: nop

    obj_init_rgbalight(rdram, ctx);
        goto after_29;
    // 0x80023ADC: nop

    after_29:
    // 0x80023AE0: b           L_80023E24
    // 0x80023AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AE8:
    // 0x80023AE8: jal         0x800403D8
    // 0x80023AEC: nop

    obj_init_buoy_pirateship(rdram, ctx);
        goto after_30;
    // 0x80023AEC: nop

    after_30:
    // 0x80023AF0: b           L_80023E24
    // 0x80023AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023AF8:
    // 0x80023AF8: jal         0x8004049C
    // 0x80023AFC: nop

    obj_init_log(rdram, ctx);
        goto after_31;
    // 0x80023AFC: nop

    after_31:
    // 0x80023B00: b           L_80023E24
    // 0x80023B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B08:
    // 0x80023B08: jal         0x80040800
    // 0x80023B0C: nop

    obj_init_weather(rdram, ctx);
        goto after_32;
    // 0x80023B0C: nop

    after_32:
    // 0x80023B10: b           L_80023E24
    // 0x80023B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B18:
    // 0x80023B18: jal         0x8003C9EC
    // 0x80023B1C: nop

    obj_init_bridge_whaleramp(rdram, ctx);
        goto after_33;
    // 0x80023B1C: nop

    after_33:
    // 0x80023B20: b           L_80023E24
    // 0x80023B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B28:
    // 0x80023B28: jal         0x8003CE64
    // 0x80023B2C: nop

    obj_init_rampswitch(rdram, ctx);
        goto after_34;
    // 0x80023B2C: nop

    after_34:
    // 0x80023B30: b           L_80023E24
    // 0x80023B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B38:
    // 0x80023B38: jal         0x8003CF00
    // 0x80023B3C: nop

    obj_init_seamonster(rdram, ctx);
        goto after_35;
    // 0x80023B3C: nop

    after_35:
    // 0x80023B40: b           L_80023E24
    // 0x80023B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B48:
    // 0x80023B48: jal         0x8004092C
    // 0x80023B4C: nop

    obj_init_lensflare(rdram, ctx);
        goto after_36;
    // 0x80023B4C: nop

    after_36:
    // 0x80023B50: b           L_80023E24
    // 0x80023B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B58:
    // 0x80023B58: jal         0x8004094C
    // 0x80023B5C: nop

    obj_init_lensflareswitch(rdram, ctx);
        goto after_37;
    // 0x80023B5C: nop

    after_37:
    // 0x80023B60: b           L_80023E24
    // 0x80023B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B68:
    // 0x80023B68: jal         0x8003522C
    // 0x80023B6C: nop

    obj_init_collectegg(rdram, ctx);
        goto after_38;
    // 0x80023B6C: nop

    after_38:
    // 0x80023B70: b           L_80023E24
    // 0x80023B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B78:
    // 0x80023B78: jal         0x80035640
    // 0x80023B7C: nop

    obj_init_eggcreator(rdram, ctx);
        goto after_39;
    // 0x80023B7C: nop

    after_39:
    // 0x80023B80: b           L_80023E24
    // 0x80023B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B88:
    // 0x80023B88: jal         0x80035EF8
    // 0x80023B8C: nop

    obj_init_characterflag(rdram, ctx);
        goto after_40;
    // 0x80023B8C: nop

    after_40:
    // 0x80023B90: b           L_80023E24
    // 0x80023B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023B98:
    // 0x80023B98: jal         0x80037A18
    // 0x80023B9C: nop

    obj_init_animation(rdram, ctx);
        goto after_41;
    // 0x80023B9C: nop

    after_41:
    // 0x80023BA0: b           L_80023E24
    // 0x80023BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BA8:
    // 0x80023BA8: jal         0x80038854
    // 0x80023BAC: nop

    obj_init_infopoint(rdram, ctx);
        goto after_42;
    // 0x80023BAC: nop

    after_42:
    // 0x80023BB0: b           L_80023E24
    // 0x80023BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BB8:
    // 0x80023BB8: jal         0x8003C644
    // 0x80023BBC: nop

    obj_init_trigger(rdram, ctx);
        goto after_43;
    // 0x80023BBC: nop

    after_43:
    // 0x80023BC0: b           L_80023E24
    // 0x80023BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BC8:
    // 0x80023BC8: jal         0x8003588C
    // 0x80023BCC: nop

    obj_init_airzippers_waterzippers(rdram, ctx);
        goto after_44;
    // 0x80023BCC: nop

    after_44:
    // 0x80023BD0: b           L_80023E24
    // 0x80023BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BD8:
    // 0x80023BD8: jal         0x80035E20
    // 0x80023BDC: nop

    obj_init_timetrialghost(rdram, ctx);
        goto after_45;
    // 0x80023BDC: nop

    after_45:
    // 0x80023BE0: b           L_80023E24
    // 0x80023BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BE8:
    // 0x80023BE8: jal         0x800409A4
    // 0x80023BEC: nop

    obj_init_wavegenerator(rdram, ctx);
        goto after_46;
    // 0x80023BEC: nop

    after_46:
    // 0x80023BF0: b           L_80023E24
    // 0x80023BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023BF8:
    // 0x80023BF8: jal         0x800409C8
    // 0x80023BFC: nop

    obj_init_butterfly(rdram, ctx);
        goto after_47;
    // 0x80023BFC: nop

    after_47:
    // 0x80023C00: b           L_80023E24
    // 0x80023C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C08:
    // 0x80023C08: jal         0x800392B8
    // 0x80023C0C: nop

    obj_init_parkwarden(rdram, ctx);
        goto after_48;
    // 0x80023C0C: nop

    after_48:
    // 0x80023C10: b           L_80023E24
    // 0x80023C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C18:
    // 0x80023C18: jal         0x8003DE74
    // 0x80023C1C: nop

    obj_init_worldkey(rdram, ctx);
        goto after_49;
    // 0x80023C1C: nop

    after_49:
    // 0x80023C20: b           L_80023E24
    // 0x80023C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C28:
    // 0x80023C28: jal         0x8003D3EC
    // 0x80023C2C: nop

    obj_init_bananacreator(rdram, ctx);
        goto after_50;
    // 0x80023C2C: nop

    after_50:
    // 0x80023C30: b           L_80023E24
    // 0x80023C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C38:
    // 0x80023C38: jal         0x8003D038
    // 0x80023C3C: nop

    obj_init_treasuresucker(rdram, ctx);
        goto after_51;
    // 0x80023C3C: nop

    after_51:
    // 0x80023C40: b           L_80023E24
    // 0x80023C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C48:
    // 0x80023C48: jal         0x80037578
    // 0x80023C4C: nop

    obj_init_lavaspurt(rdram, ctx);
        goto after_52;
    // 0x80023C4C: nop

    after_52:
    // 0x80023C50: b           L_80023E24
    // 0x80023C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C58:
    // 0x80023C58: jal         0x80037624
    // 0x80023C5C: nop

    obj_init_posarrow(rdram, ctx);
        goto after_53;
    // 0x80023C5C: nop

    after_53:
    // 0x80023C60: b           L_80023E24
    // 0x80023C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C68:
    // 0x80023C68: jal         0x8003818C
    // 0x80023C6C: nop

    obj_init_hittester(rdram, ctx);
        goto after_54;
    // 0x80023C6C: nop

    after_54:
    // 0x80023C70: b           L_80023E24
    // 0x80023C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C78:
    // 0x80023C78: jal         0x800381E0
    // 0x80023C7C: nop

    obj_init_dynamic_lighting_object(rdram, ctx);
        goto after_55;
    // 0x80023C7C: nop

    after_55:
    // 0x80023C80: b           L_80023E24
    // 0x80023C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C88:
    // 0x80023C88: jal         0x80038214
    // 0x80023C8C: nop

    obj_init_unknown96(rdram, ctx);
        goto after_56;
    // 0x80023C8C: nop

    after_56:
    // 0x80023C90: b           L_80023E24
    // 0x80023C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023C98:
    // 0x80023C98: jal         0x80038248
    // 0x80023C9C: nop

    obj_init_snowball(rdram, ctx);
        goto after_57;
    // 0x80023C9C: nop

    after_57:
    // 0x80023CA0: b           L_80023E24
    // 0x80023CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CA8:
    // 0x80023CA8: jal         0x80041A90
    // 0x80023CAC: nop

    obj_init_midifade(rdram, ctx);
        goto after_58;
    // 0x80023CAC: nop

    after_58:
    // 0x80023CB0: b           L_80023E24
    // 0x80023CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CB8:
    // 0x80023CB8: jal         0x80041E80
    // 0x80023CBC: nop

    obj_init_midifadepoint(rdram, ctx);
        goto after_59;
    // 0x80023CBC: nop

    after_59:
    // 0x80023CC0: b           L_80023E24
    // 0x80023CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CC8:
    // 0x80023CC8: jal         0x80042014
    // 0x80023CCC: nop

    obj_init_midichset(rdram, ctx);
        goto after_60;
    // 0x80023CCC: nop

    after_60:
    // 0x80023CD0: b           L_80023E24
    // 0x80023CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CD8:
    // 0x80023CD8: jal         0x80034B68
    // 0x80023CDC: nop

    obj_init_effectbox(rdram, ctx);
        goto after_61;
    // 0x80023CDC: nop

    after_61:
    // 0x80023CE0: b           L_80023E24
    // 0x80023CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CE8:
    // 0x80023CE8: jal         0x80034E70
    // 0x80023CEC: nop

    obj_init_trophycab(rdram, ctx);
        goto after_62;
    // 0x80023CEC: nop

    after_62:
    // 0x80023CF0: b           L_80023E24
    // 0x80023CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023CF8:
    // 0x80023CF8: jal         0x8004203C
    // 0x80023CFC: nop

    obj_init_bubbler(rdram, ctx);
        goto after_63;
    // 0x80023CFC: nop

    after_63:
    // 0x80023D00: b           L_80023E24
    // 0x80023D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D08:
    // 0x80023D08: jal         0x8003D2AC
    // 0x80023D0C: nop

    obj_init_flycoin(rdram, ctx);
        goto after_64;
    // 0x80023D0C: nop

    after_64:
    // 0x80023D10: b           L_80023E24
    // 0x80023D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D18:
    // 0x80023D18: jal         0x8003B368
    // 0x80023D1C: nop

    obj_init_goldenballoon(rdram, ctx);
        goto after_65;
    // 0x80023D1C: nop

    after_65:
    // 0x80023D20: b           L_80023E24
    // 0x80023D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D28:
    // 0x80023D28: jal         0x80034844
    // 0x80023D2C: nop

    obj_init_laserbolt(rdram, ctx);
        goto after_66;
    // 0x80023D2C: nop

    after_66:
    // 0x80023D30: b           L_80023E24
    // 0x80023D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D38:
    // 0x80023D38: jal         0x80034530
    // 0x80023D3C: nop

    obj_init_lasergun(rdram, ctx);
        goto after_67;
    // 0x80023D3C: nop

    after_67:
    // 0x80023D40: b           L_80023E24
    // 0x80023D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D48:
    // 0x80023D48: jal         0x80035AE8
    // 0x80023D4C: nop

    obj_init_groundzipper(rdram, ctx);
        goto after_68;
    // 0x80023D4C: nop

    after_68:
    // 0x80023D50: b           L_80023E24
    // 0x80023D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D58:
    // 0x80023D58: jal         0x80037D54
    // 0x80023D5C: nop

    obj_init_overridepos(rdram, ctx);
        goto after_69;
    // 0x80023D5C: nop

    after_69:
    // 0x80023D60: b           L_80023E24
    // 0x80023D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D68:
    // 0x80023D68: jal         0x80037D6C
    // 0x80023D6C: nop

    obj_init_wizpigship(rdram, ctx);
        goto after_70;
    // 0x80023D6C: nop

    after_70:
    // 0x80023D70: b           L_80023E24
    // 0x80023D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D78:
    // 0x80023D78: jal         0x8004210C
    // 0x80023D7C: nop

    obj_init_boost(rdram, ctx);
        goto after_71;
    // 0x80023D7C: nop

    after_71:
    // 0x80023D80: b           L_80023E24
    // 0x80023D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D88:
    // 0x80023D88: jal         0x8003DC5C
    // 0x80023D8C: nop

    obj_init_silvercoin(rdram, ctx);
        goto after_72;
    // 0x80023D8C: nop

    after_72:
    // 0x80023D90: b           L_80023E24
    // 0x80023D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023D98:
    // 0x80023D98: jal         0x80038AC8
    // 0x80023D9C: nop

    obj_init_wardensmoke(rdram, ctx);
        goto after_73;
    // 0x80023D9C: nop

    after_73:
    // 0x80023DA0: b           L_80023E24
    // 0x80023DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DA8:
    // 0x80023DA8: jal         0x80042150
    // 0x80023DAC: nop

    obj_init_unknown94(rdram, ctx);
        goto after_74;
    // 0x80023DAC: nop

    after_74:
    // 0x80023DB0: b           L_80023E24
    // 0x80023DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DB8:
    // 0x80023DB8: jal         0x80038D58
    // 0x80023DBC: nop

    obj_init_teleport(rdram, ctx);
        goto after_75;
    // 0x80023DBC: nop

    after_75:
    // 0x80023DC0: b           L_80023E24
    // 0x80023DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DC8:
    // 0x80023DC8: jal         0x8003572C
    // 0x80023DCC: nop

    obj_init_lighthouse_rocketsignpost(rdram, ctx);
        goto after_76;
    // 0x80023DCC: nop

    after_76:
    // 0x80023DD0: b           L_80023E24
    // 0x80023DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DD8:
    // 0x80023DD8: jal         0x8004216C
    // 0x80023DDC: nop

    obj_init_rangetrigger(rdram, ctx);
        goto after_77;
    // 0x80023DDC: nop

    after_77:
    // 0x80023DE0: b           L_80023E24
    // 0x80023DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DE8:
    // 0x80023DE8: jal         0x80033F44
    // 0x80023DEC: nop

    obj_init_fireball_octoweapon(rdram, ctx);
        goto after_78;
    // 0x80023DEC: nop

    after_78:
    // 0x80023DF0: b           L_80023E24
    // 0x80023DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023DF8:
    // 0x80023DF8: jal         0x80042210
    // 0x80023DFC: nop

    obj_init_frog(rdram, ctx);
        goto after_79;
    // 0x80023DFC: nop

    after_79:
    // 0x80023E00: b           L_80023E24
    // 0x80023E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E08:
    // 0x80023E08: jal         0x8003DBA0
    // 0x80023E0C: nop

    obj_init_silvercoin_adv2(rdram, ctx);
        goto after_80;
    // 0x80023E0C: nop

    after_80:
    // 0x80023E10: b           L_80023E24
    // 0x80023E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80023E24;
    // 0x80023E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E18:
    // 0x80023E18: jal         0x80042A1C
    // 0x80023E1C: nop

    obj_init_levelname(rdram, ctx);
        goto after_81;
    // 0x80023E1C: nop

    after_81:
L_80023E20:
    // 0x80023E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80023E24:
    // 0x80023E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023E28: jr          $ra
    // 0x80023E2C: nop

    return;
    // 0x80023E2C: nop

;}
RECOMP_FUNC void music_tempo_set_relative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800014BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800014C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800014C4: jal         0x800015B8
    // 0x800014C8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    music_tempo(rdram, ctx);
        goto after_0;
    // 0x800014C8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800014CC: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800014D0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800014D4: bgez        $t6, L_800014EC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800014D8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800014EC;
    }
    // 0x800014D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800014DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800014E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800014E4: nop

    // 0x800014E8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800014EC:
    // 0x800014EC: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800014F0: nop

    // 0x800014F4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800014F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800014FC: nop

    // 0x80001500: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80001504: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001508: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000150C: nop

    // 0x80001510: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80001514: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80001518: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000151C: jal         0x80001534
    // 0x80001520: nop

    music_tempo_set(rdram, ctx);
        goto after_1;
    // 0x80001520: nop

    after_1:
    // 0x80001524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000152C: jr          $ra
    // 0x80001530: nop

    return;
    // 0x80001530: nop

;}
RECOMP_FUNC void func_8006ABB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ABB4: bgez        $a0, L_8006ABC4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006ABB8: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006ABC4;
    }
    // 0x8006ABB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006ABBC: jr          $ra
    // 0x8006ABC0: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
    return;
    // 0x8006ABC0: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
L_8006ABC4:
    // 0x8006ABC4: lw          $t6, 0x1170($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1170);
    // 0x8006ABC8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006ABCC: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006ABD0: bne         $at, $zero, L_8006ABE0
    if (ctx->r1 != 0) {
        // 0x8006ABD4: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006ABE0;
    }
    // 0x8006ABD4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006ABD8: jr          $ra
    // 0x8006ABDC: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
    return;
    // 0x8006ABDC: addiu       $v0, $zero, 0xE10
    ctx->r2 = ADD32(0, 0XE10);
L_8006ABE0:
    // 0x8006ABE0: lw          $t7, 0x117C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X117C);
    // 0x8006ABE4: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006ABE8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006ABEC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006ABF0: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x8006ABF4: nop

    // 0x8006ABF8: jr          $ra
    // 0x8006ABFC: nop

    return;
    // 0x8006ABFC: nop

;}
RECOMP_FUNC void obj_loop_rocketsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800357D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800357D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800357DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800357E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800357E4: jal         0x8001BAC8
    // 0x800357E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x800357E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800357EC: beq         $v0, $zero, L_8003586C
    if (ctx->r2 == 0) {
        // 0x800357F0: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_8003586C;
    }
    // 0x800357F0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800357F4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800357F8: nop

    // 0x800357FC: lw          $v1, 0x4C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X4C);
    // 0x80035800: nop

    // 0x80035804: lbu         $t7, 0x13($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X13);
    // 0x80035808: nop

    // 0x8003580C: slti        $at, $t7, 0xC8
    ctx->r1 = SIGNED(ctx->r15) < 0XC8 ? 1 : 0;
    // 0x80035810: beq         $at, $zero, L_8003586C
    if (ctx->r1 == 0) {
        // 0x80035814: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_8003586C;
    }
    // 0x80035814: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80035818: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8003581C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80035820: bne         $v0, $t8, L_8003586C
    if (ctx->r2 != ctx->r24) {
        // 0x80035824: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_8003586C;
    }
    // 0x80035824: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80035828: jal         0x8006A554
    // 0x8003582C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8003582C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80035830: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80035834: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
    // 0x80035838: bne         $t9, $zero, L_80035860
    if (ctx->r25 != 0) {
        // 0x8003583C: nop
    
            goto L_80035860;
    }
    // 0x8003583C: nop

    // 0x80035840: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80035844: nop

    // 0x80035848: lw          $t1, 0x5C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X5C);
    // 0x8003584C: nop

    // 0x80035850: lw          $t2, 0x100($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X100);
    // 0x80035854: nop

    // 0x80035858: bne         $a1, $t2, L_8003586C
    if (ctx->r5 != ctx->r10) {
        // 0x8003585C: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_8003586C;
    }
    // 0x8003585C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
L_80035860:
    // 0x80035860: jal         0x8006F29C
    // 0x80035864: nop

    begin_lighthouse_rocket_cutscene(rdram, ctx);
        goto after_2;
    // 0x80035864: nop

    after_2:
    // 0x80035868: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
L_8003586C:
    // 0x8003586C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80035870: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x80035874: nop

    // 0x80035878: sb          $t3, 0x13($t5)
    MEM_B(0X13, ctx->r13) = ctx->r11;
    // 0x8003587C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035880: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80035884: jr          $ra
    // 0x80035888: nop

    return;
    // 0x80035888: nop

;}
RECOMP_FUNC void func_80061C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061C0C: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x80061C10: nop

    // 0x80061C14: bgez        $v0, L_80061C28
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80061C18: nop
    
            goto L_80061C28;
    }
    // 0x80061C18: nop

    // 0x80061C1C: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x80061C20: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x80061C24: nop

L_80061C28:
    // 0x80061C28: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80061C2C: nop

    // 0x80061C30: lb          $v1, 0x55($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X55);
    // 0x80061C34: nop

    // 0x80061C38: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80061C3C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80061C40: beq         $at, $zero, L_80061C54
    if (ctx->r1 == 0) {
        // 0x80061C44: nop
    
            goto L_80061C54;
    }
    // 0x80061C44: nop

    // 0x80061C48: sb          $v1, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r3;
    // 0x80061C4C: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x80061C50: nop

L_80061C54:
    // 0x80061C54: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x80061C58: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80061C5C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80061C60: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80061C64: nop

    // 0x80061C68: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80061C6C: nop

    // 0x80061C70: lw          $t0, 0x44($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X44);
    // 0x80061C74: nop

    // 0x80061C78: beq         $t0, $zero, L_80061D20
    if (ctx->r8 == 0) {
        // 0x80061C7C: nop
    
            goto L_80061D20;
    }
    // 0x80061C7C: nop

    // 0x80061C80: lb          $v0, 0x3B($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3B);
    // 0x80061C84: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80061C88: bgez        $v0, L_80061C9C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80061C8C: nop
    
            goto L_80061C9C;
    }
    // 0x80061C8C: nop

    // 0x80061C90: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80061C94: lb          $v0, 0x3B($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3B);
    // 0x80061C98: nop

L_80061C9C:
    // 0x80061C9C: lh          $v1, 0x48($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X48);
    // 0x80061CA0: nop

    // 0x80061CA4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061CA8: bne         $at, $zero, L_80061CBC
    if (ctx->r1 != 0) {
        // 0x80061CAC: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80061CBC;
    }
    // 0x80061CAC: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80061CB0: sb          $t1, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r9;
    // 0x80061CB4: lh          $v1, 0x48($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X48);
    // 0x80061CB8: nop

L_80061CBC:
    // 0x80061CBC: blez        $v1, L_80061CE4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80061CC0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80061CE4;
    }
    // 0x80061CC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80061CC4: lb          $t3, 0x3B($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X3B);
    // 0x80061CC8: lw          $t2, 0x44($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X44);
    // 0x80061CCC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80061CD0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80061CD4: lw          $v1, 0x4($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X4);
    // 0x80061CD8: b           L_80061CE4
    // 0x80061CDC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
        goto L_80061CE4;
    // 0x80061CDC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x80061CE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80061CE4:
    // 0x80061CE4: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80061CE8: nop

    // 0x80061CEC: sra         $t6, $v0, 4
    ctx->r14 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80061CF0: bgez        $t6, L_80061D0C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80061CF4: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80061D0C;
    }
    // 0x80061CF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80061CF8: sh          $v1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r3;
    // 0x80061CFC: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80061D00: nop

    // 0x80061D04: sra         $t7, $v0, 4
    ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80061D08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80061D0C:
    // 0x80061D0C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80061D10: beq         $at, $zero, L_80061D20
    if (ctx->r1 == 0) {
        // 0x80061D14: nop
    
            goto L_80061D20;
    }
    // 0x80061D14: nop

    // 0x80061D18: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x80061D1C: sh          $t8, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r24;
L_80061D20:
    // 0x80061D20: jr          $ra
    // 0x80061D24: nop

    return;
    // 0x80061D24: nop

;}
RECOMP_FUNC void bgdraw_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B9C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80077BA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80077BA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80077BA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80077BAC: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80077BB0: jal         0x8007A520
    // 0x80077BB4: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80077BB4: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80077BB8: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x80077BBC: addiu       $t1, $t4, -0x1
    ctx->r9 = ADD32(ctx->r12, -0X1);
    // 0x80077BC0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80077BC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80077BC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80077BCC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80077BD0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077BD4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80077BD8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077BDC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80077BE0: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80077BE4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80077BE8: addiu       $t2, $t5, -0x1
    ctx->r10 = ADD32(ctx->r13, -0X1);
    // 0x80077BEC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80077BF0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80077BF4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80077BF8: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80077BFC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80077C00: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80077C04: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80077C08: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077C0C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80077C10: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80077C14: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80077C18: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80077C1C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077C20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80077C24: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80077C28: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80077C2C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80077C30: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80077C34: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80077C38: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x80077C3C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80077C40: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80077C44: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80077C48: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80077C4C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80077C50: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80077C54: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80077C58: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    extern void dkr_fix_fullscreen_clear_scissor(uint8_t*, recomp_context*); dkr_fix_fullscreen_clear_scissor(rdram, ctx);
    // 0x80077C5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077C60: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x80077C64: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80077C68: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80077C6C: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x80077C70: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x80077C74: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80077C78: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80077C7C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077C80: lui         $ra, 0xFF10
    ctx->r31 = S32(0XFF10 << 16);
    // 0x80077C84: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077C88: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80077C8C: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x80077C90: or          $t9, $t7, $ra
    ctx->r25 = ctx->r15 | ctx->r31;
    // 0x80077C94: lui         $t8, 0x200
    ctx->r24 = S32(0X200 << 16);
    // 0x80077C98: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80077C9C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80077CA0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077CA4: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x80077CA8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077CAC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80077CB0: lui         $a3, 0xF700
    ctx->r7 = S32(0XF700 << 16);
    // 0x80077CB4: ori         $t7, $t7, 0xFFFC
    ctx->r15 = ctx->r15 | 0XFFFC;
    // 0x80077CB8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80077CBC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80077CC0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077CC4: andi        $t8, $t1, 0x3FF
    ctx->r24 = ctx->r9 & 0X3FF;
    // 0x80077CC8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80077CCC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80077CD0: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80077CD4: andi        $t9, $t2, 0x3FF
    ctx->r25 = ctx->r10 & 0X3FF;
    // 0x80077CD8: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077CDC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80077CE0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80077CE4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80077CE8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80077CEC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80077CF0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077CF4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80077CF8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80077CFC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80077D00: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80077D04: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077D08: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077D0C: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x80077D10: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80077D14: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80077D18: or          $t9, $t6, $ra
    ctx->r25 = ctx->r14 | ctx->r31;
    // 0x80077D1C: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x80077D20: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80077D24: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80077D28: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80077D2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80077D30: beq         $t8, $zero, L_80078024
    if (ctx->r24 == 0) {
        // 0x80077D34: nop
    
            goto L_80078024;
    }
    // 0x80077D34: nop

    // 0x80077D38: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x80077D3C: jal         0x80066910
    // 0x80077D40: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    check_viewport_background_flag(rdram, ctx);
        goto after_1;
    // 0x80077D40: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    after_1:
    // 0x80077D44: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x80077D48: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80077D4C: beq         $v0, $zero, L_80077F34
    if (ctx->r2 == 0) {
        // 0x80077D50: lui         $a3, 0xF700
        ctx->r7 = S32(0XF700 << 16);
            goto L_80077F34;
    }
    // 0x80077D50: lui         $a3, 0xF700
    ctx->r7 = S32(0XF700 << 16);
    // 0x80077D54: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80077D58: lw          $t6, -0x1B34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1B34);
    // 0x80077D5C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80077D60: beq         $t6, $zero, L_80077D78
    if (ctx->r14 == 0) {
        // 0x80077D64: nop
    
            goto L_80077D78;
    }
    // 0x80077D64: nop

    // 0x80077D68: jal         0x800787FC
    // 0x80077D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_chequer(rdram, ctx);
        goto after_2;
    // 0x80077D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80077D70: b           L_80077E0C
    // 0x80077D74: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
        goto L_80077E0C;
    // 0x80077D74: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_80077D78:
    // 0x80077D78: lw          $t9, -0x1B3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1B3C);
    // 0x80077D7C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80077D80: beq         $t9, $zero, L_80077D98
    if (ctx->r25 == 0) {
        // 0x80077D84: nop
    
            goto L_80077D98;
    }
    // 0x80077D84: nop

    // 0x80077D88: jal         0x80078190
    // 0x80077D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_texture(rdram, ctx);
        goto after_3;
    // 0x80077D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80077D90: b           L_80077E0C
    // 0x80077D94: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
        goto L_80077E0C;
    // 0x80077D94: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_80077D98:
    // 0x80077D98: lw          $v0, -0x1B30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1B30);
    // 0x80077D9C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80077DA0: beq         $v0, $zero, L_80077DBC
    if (ctx->r2 == 0) {
        // 0x80077DA4: addiu       $t9, $t4, -0x1
        ctx->r25 = ADD32(ctx->r12, -0X1);
            goto L_80077DBC;
    }
    // 0x80077DA4: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x80077DA8: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x80077DAC: jalr        $v0
    // 0x80077DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80077DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80077DB4: b           L_80077E0C
    // 0x80077DB8: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
        goto L_80077E0C;
    // 0x80077DB8: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_80077DBC:
    extern void dkr_background_fill_stretch_begin(uint8_t*, recomp_context*); dkr_background_fill_stretch_begin(rdram, ctx);
    // 0x80077DBC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077DC0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077DC4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80077DC8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80077DCC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80077DD0: lw          $t8, -0x1B44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1B44);
    // 0x80077DD4: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80077DD8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80077DDC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077DE0: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80077DE4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077DE8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80077DEC: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x80077DF0: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80077DF4: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80077DF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80077DFC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80077E00: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80077E04: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80077E08: addiu       $t7, $sp, 0x84
    ctx->r15 = ADD32(ctx->r29, 0X84);
L_80077E0C:
    extern void dkr_background_fill_stretch_end(uint8_t*, recomp_context*); dkr_background_fill_stretch_end(rdram, ctx);
    // 0x80077E0C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80077E10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80077E14: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x80077E18: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x80077E1C: jal         0x80066BA8
    // 0x80077E20: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    copy_viewport_background_size_to_coords(rdram, ctx);
        goto after_5;
    // 0x80077E20: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    after_5:
    // 0x80077E24: beq         $v0, $zero, L_80078024
    if (ctx->r2 == 0) {
        // 0x80077E28: lui         $t8, 0xBA00
        ctx->r24 = S32(0XBA00 << 16);
            goto L_80078024;
    }
    // 0x80077E28: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80077E2C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077E30: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x80077E34: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077E38: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80077E3C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80077E40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077E44: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077E48: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80077E4C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80077E50: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80077E54: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80077E58: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077E5C: lbu         $t8, -0x1B50($t6)
    ctx->r24 = MEM_BU(ctx->r14, -0X1B50);
    // 0x80077E60: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077E64: lbu         $t6, -0x1B4C($t7)
    ctx->r14 = MEM_BU(ctx->r15, -0X1B4C);
    // 0x80077E68: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80077E6C: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80077E70: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80077E74: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80077E78: lbu         $t9, -0x1B48($t6)
    ctx->r25 = MEM_BU(ctx->r14, -0X1B48);
    // 0x80077E7C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077E80: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x80077E84: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80077E88: ori         $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 | 0XFF;
    // 0x80077E8C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80077E90: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077E94: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x80077E98: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80077E9C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80077EA0: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x80077EA4: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80077EA8: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x80077EAC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80077EB0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077EB4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077EB8: lui         $t8, 0xF0A
    ctx->r24 = S32(0XF0A << 16);
    // 0x80077EBC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80077EC0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80077EC4: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80077EC8: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80077ECC: ori         $t8, $t8, 0x4000
    ctx->r24 = ctx->r24 | 0X4000;
    // 0x80077ED0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80077ED4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077ED8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077EDC: nop

    // 0x80077EE0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077EE4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80077EE8: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x80077EEC: nop

    // 0x80077EF0: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80077EF4: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80077EF8: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80077EFC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80077F00: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80077F04: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80077F08: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80077F0C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80077F10: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80077F14: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x80077F18: andi        $t6, $t7, 0x3FF
    ctx->r14 = ctx->r15 & 0X3FF;
    // 0x80077F1C: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80077F20: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80077F24: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80077F28: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80077F2C: b           L_80078024
    // 0x80077F30: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80078024;
    // 0x80077F30: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80077F34:
    // 0x80077F34: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077F38: lw          $t7, -0x1B34($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1B34);
    // 0x80077F3C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80077F40: beq         $t7, $zero, L_80077F58
    if (ctx->r15 == 0) {
        // 0x80077F44: nop
    
            goto L_80077F58;
    }
    // 0x80077F44: nop

    // 0x80077F48: jal         0x800787FC
    // 0x80077F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_chequer(rdram, ctx);
        goto after_6;
    // 0x80077F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80077F50: b           L_80078028
    // 0x80077F54: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80078028;
    // 0x80077F54: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80077F58:
    // 0x80077F58: lw          $t8, -0x1B3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1B3C);
    // 0x80077F5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80077F60: beq         $t8, $zero, L_80077F78
    if (ctx->r24 == 0) {
        // 0x80077F64: nop
    
            goto L_80077F78;
    }
    // 0x80077F64: nop

    // 0x80077F68: jal         0x80078190
    // 0x80077F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bgdraw_texture(rdram, ctx);
        goto after_7;
    // 0x80077F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80077F70: b           L_80078028
    // 0x80077F74: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80078028;
    // 0x80077F74: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80077F78:
    // 0x80077F78: lw          $v0, -0x1B30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1B30);
    // 0x80077F7C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x80077F80: beq         $v0, $zero, L_80077F98
    if (ctx->r2 == 0) {
        // 0x80077F84: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_80077F98;
    }
    // 0x80077F84: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80077F88: jalr        $v0
    // 0x80077F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x80077F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80077F90: b           L_80078028
    // 0x80077F94: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_80078028;
    // 0x80077F94: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80077F98:
    extern void dkr_background_fill_stretch_begin(uint8_t*, recomp_context*); dkr_background_fill_stretch_begin(rdram, ctx);
    // 0x80077F98: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077F9C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077FA0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077FA4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80077FA8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80077FAC: lbu         $t9, -0x1B50($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1B50);
    // 0x80077FB0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80077FB4: lbu         $t6, -0x1B4C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1B4C);
    // 0x80077FB8: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x80077FBC: andi        $t8, $t7, 0xF800
    ctx->r24 = ctx->r15 & 0XF800;
    // 0x80077FC0: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x80077FC4: andi        $t7, $t9, 0x7C0
    ctx->r15 = ctx->r25 & 0X7C0;
    // 0x80077FC8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80077FCC: lbu         $t9, -0x1B48($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1B48);
    // 0x80077FD0: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80077FD4: sra         $t8, $t9, 2
    ctx->r24 = S32(SIGNED(ctx->r25) >> 2);
    // 0x80077FD8: andi        $t7, $t8, 0x3E
    ctx->r15 = ctx->r24 & 0X3E;
    // 0x80077FDC: or          $a0, $t6, $t7
    ctx->r4 = ctx->r14 | ctx->r15;
    // 0x80077FE0: ori         $t9, $a0, 0x1
    ctx->r25 = ctx->r4 | 0X1;
    // 0x80077FE4: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80077FE8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80077FEC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80077FF0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077FF4: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x80077FF8: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x80077FFC: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80078000: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078004: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078008: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007800C: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x80078010: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80078014: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80078018: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8007801C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078020: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80078024:
    extern void dkr_background_fill_stretch_end(uint8_t*, recomp_context*); dkr_background_fill_stretch_end(rdram, ctx);
    // 0x80078024: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80078028:
    // 0x80078028: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007802C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078030: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80078038: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007803C: jal         0x80067A3C
    // 0x80078040: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    viewport_scissor(rdram, ctx);
        goto after_9;
    // 0x80078040: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    after_9:
    // 0x80078044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80078048: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007804C: jr          $ra
    // 0x80078050: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80078050: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void set_skydome_visbility(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028044: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028048: jr          $ra
    // 0x8002804C: sw          $a0, -0x4F24($at)
    MEM_W(-0X4F24, ctx->r1) = ctx->r4;
    return;
    // 0x8002804C: sw          $a0, -0x4F24($at)
    MEM_W(-0X4F24, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void alLink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8790: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800C8794: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800C8798: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C879C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800C87A0: beq         $v0, $zero, L_800C87AC
    if (ctx->r2 == 0) {
        // 0x800C87A4: nop
    
            goto L_800C87AC;
    }
    // 0x800C87A4: nop

    // 0x800C87A8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_800C87AC:
    // 0x800C87AC: jr          $ra
    // 0x800C87B0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    return;
    // 0x800C87B0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void get_file_number(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800764E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800764EC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800764F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800764F4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800764F8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800764FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80076500: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80076504: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80076508: jal         0x80076A38
    // 0x8007650C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    string_to_font_codes(rdram, ctx);
        goto after_0;
    // 0x8007650C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x80076510: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80076514: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80076518: jal         0x80076A38
    // 0x8007651C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    string_to_font_codes(rdram, ctx);
        goto after_1;
    // 0x8007651C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80076520: jal         0x8009EB20
    // 0x80076524: nop

    get_language(rdram, ctx);
        goto after_2;
    // 0x80076524: nop

    after_2:
    // 0x80076528: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007652C: bne         $v0, $at, L_80076540
    if (ctx->r2 != ctx->r1) {
        // 0x80076530: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80076540;
    }
    // 0x80076530: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80076534: lui         $a2, 0x4E44
    ctx->r6 = S32(0X4E44 << 16);
    // 0x80076538: b           L_80076560
    // 0x8007653C: ori         $a2, $a2, 0x594A
    ctx->r6 = ctx->r6 | 0X594A;
        goto L_80076560;
    // 0x8007653C: ori         $a2, $a2, 0x594A
    ctx->r6 = ctx->r6 | 0X594A;
L_80076540:
    // 0x80076540: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80076544: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80076548: lui         $a2, 0x4E44
    ctx->r6 = S32(0X4E44 << 16);
    // 0x8007654C: bne         $t6, $zero, L_80076560
    if (ctx->r14 != 0) {
        // 0x80076550: ori         $a2, $a2, 0x5945
        ctx->r6 = ctx->r6 | 0X5945;
            goto L_80076560;
    }
    // 0x80076550: ori         $a2, $a2, 0x5945
    ctx->r6 = ctx->r6 | 0X5945;
    // 0x80076554: lui         $a2, 0x4E44
    ctx->r6 = S32(0X4E44 << 16);
    // 0x80076558: b           L_80076560
    // 0x8007655C: ori         $a2, $a2, 0x5950
    ctx->r6 = ctx->r6 | 0X5950;
        goto L_80076560;
    // 0x8007655C: ori         $a2, $a2, 0x5950
    ctx->r6 = ctx->r6 | 0X5950;
L_80076560:
    // 0x80076560: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80076564: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80076568: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007656C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80076570: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80076574: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80076578: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007657C: addiu       $t9, $t9, 0x4018
    ctx->r25 = ADD32(ctx->r25, 0X4018);
    // 0x80076580: addiu       $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x80076584: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80076588: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8007658C: addiu       $a1, $zero, 0x3459
    ctx->r5 = ADD32(0, 0X3459);
    // 0x80076590: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x80076594: jal         0x800D0E80
    // 0x80076598: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    osPfsFindFile_recomp(rdram, ctx);
        goto after_3;
    // 0x80076598: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_3:
    // 0x8007659C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800765A0: bne         $v0, $zero, L_800765B0
    if (ctx->r2 != 0) {
        // 0x800765A4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800765B0;
    }
    // 0x800765A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800765A8: b           L_80076608
    // 0x800765AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076608;
    // 0x800765AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800765B0:
    // 0x800765B0: beq         $v0, $at, L_800765C0
    if (ctx->r2 == ctx->r1) {
        // 0x800765B4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800765C0;
    }
    // 0x800765B4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800765B8: bne         $v0, $at, L_800765CC
    if (ctx->r2 != ctx->r1) {
        // 0x800765BC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800765CC;
    }
    // 0x800765BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800765C0:
    // 0x800765C0: b           L_80076608
    // 0x800765C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80076608;
    // 0x800765C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800765C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800765CC:
    // 0x800765CC: bne         $v0, $at, L_800765E0
    if (ctx->r2 != ctx->r1) {
        // 0x800765D0: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800765E0;
    }
    // 0x800765D0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800765D4: b           L_80076608
    // 0x800765D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80076608;
    // 0x800765D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800765DC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800765E0:
    // 0x800765E0: bne         $v0, $at, L_800765F4
    if (ctx->r2 != ctx->r1) {
        // 0x800765E4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800765F4;
    }
    // 0x800765E4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800765E8: b           L_80076608
    // 0x800765EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80076608;
    // 0x800765EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800765F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_800765F4:
    // 0x800765F4: bne         $v0, $at, L_80076608
    if (ctx->r2 != ctx->r1) {
        // 0x800765F8: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80076608;
    }
    // 0x800765F8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800765FC: b           L_80076608
    // 0x80076600: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80076608;
    // 0x80076600: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80076604: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80076608:
    // 0x80076608: jr          $ra
    // 0x8007660C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007660C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void scGetAudioTaskTimers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079584: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079588: lwc1        $f4, -0x18C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X18C0);
    // 0x8007958C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079590: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80079594: lwc1        $f6, -0x18B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X18B8);
    // 0x80079598: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007959C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800795A0: lwc1        $f8, -0x18B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X18B4);
    // 0x800795A4: jr          $ra
    // 0x800795A8: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    return;
    // 0x800795A8: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
;}
RECOMP_FUNC void obj_loop_characterflag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035F74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80035F78: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80035F7C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80035F80: bgez        $t6, L_80036034
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80035F84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036034;
    }
    // 0x80035F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035F88: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x80035F8C: jal         0x8001BAC8
    // 0x80035F90: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80035F90: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80035F94: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80035F98: beq         $v0, $zero, L_80036030
    if (ctx->r2 == 0) {
        // 0x80035F9C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80036030;
    }
    // 0x80035F9C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80035FA0: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x80035FA4: lw          $v1, 0x64($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X64);
    // 0x80035FA8: lb          $t7, 0x3($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3);
    // 0x80035FAC: addiu       $t8, $t8, -0x3680
    ctx->r24 = ADD32(ctx->r24, -0X3680);
    // 0x80035FB0: bltz        $t7, L_80035FC4
    if (SIGNED(ctx->r15) < 0) {
        // 0x80035FB4: sw          $t7, 0x7C($a2)
        MEM_W(0X7C, ctx->r6) = ctx->r15;
            goto L_80035FC4;
    }
    // 0x80035FB4: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80035FB8: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80035FBC: bne         $at, $zero, L_80035FC8
    if (ctx->r1 != 0) {
        // 0x80035FC0: nop
    
            goto L_80035FC8;
    }
    // 0x80035FC0: nop

L_80035FC4:
    // 0x80035FC4: sw          $zero, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = 0;
L_80035FC8:
    // 0x80035FC8: sw          $t8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r24;
    // 0x80035FCC: lw          $t0, 0x7C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X7C);
    // 0x80035FD0: lw          $t9, 0x68($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X68);
    // 0x80035FD4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80035FD8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80035FDC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80035FE0: lui         $t6, 0x4000
    ctx->r14 = S32(0X4000 << 16);
    // 0x80035FE4: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
    // 0x80035FE8: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x80035FEC: lbu         $a0, 0x1($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X1);
    // 0x80035FF0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80035FF4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80035FF8: sll         $t4, $v0, 21
    ctx->r12 = S32(ctx->r2 << 21);
    // 0x80035FFC: sll         $t5, $a0, 5
    ctx->r13 = S32(ctx->r4 << 5);
    // 0x80036000: lui         $t7, 0x4001
    ctx->r15 = S32(0X4001 << 16);
    // 0x80036004: ori         $t6, $t6, 0x103
    ctx->r14 = ctx->r14 | 0X103;
    // 0x80036008: ori         $t7, $t7, 0x203
    ctx->r15 = ctx->r15 | 0X203;
    // 0x8003600C: or          $t8, $t4, $t5
    ctx->r24 = ctx->r12 | ctx->r13;
    // 0x80036010: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80036014: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80036018: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x8003601C: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x80036020: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x80036024: sw          $t4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r12;
    // 0x80036028: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x8003602C: sw          $t5, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r13;
L_80036030:
    // 0x80036030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036034:
    // 0x80036034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036038: jr          $ra
    // 0x8003603C: nop

    return;
    // 0x8003603C: nop

;}
RECOMP_FUNC void mtxf_scale_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FE04: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x8006FE08: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006FE0C: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FE10: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x8006FE14: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8006FE18: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FE1C: swc1        $f16, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f16.u32l;
    // 0x8006FE20: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8006FE24: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FE28: jr          $ra
    // 0x8006FE2C: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x8006FE2C: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_8005698C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005698C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80056990: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80056994: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80056998: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8005699C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800569A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800569A4: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800569A8: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x800569AC: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800569B0: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x800569B4: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800569B8: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800569BC: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800569C0: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800569C4: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800569C8: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800569CC: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800569D0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800569D4: jal         0x8006BD98
    // 0x800569D8: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    level_type(rdram, ctx);
        goto after_0;
    // 0x800569D8: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    after_0:
    // 0x800569DC: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800569E0: andi        $a0, $v0, 0x40
    ctx->r4 = ctx->r2 & 0X40;
    // 0x800569E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800569E8: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800569EC: bne         $t6, $at, L_80056A20
    if (ctx->r14 != ctx->r1) {
        // 0x800569F0: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_80056A20;
    }
    // 0x800569F0: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800569F4: bne         $a0, $zero, L_80056A20
    if (ctx->r4 != 0) {
        // 0x800569F8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80056A20;
    }
    // 0x800569F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800569FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80056A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80056A04: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    // 0x80056A08: jal         0x8001B7A8
    // 0x80056A0C: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    racer_find_nearest_opponent_relative(rdram, ctx);
        goto after_1;
    // 0x80056A0C: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80056A10: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056A14: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80056A18: b           L_80056DE8
    // 0x80056A1C: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
        goto L_80056DE8;
    // 0x80056A1C: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
L_80056A20:
    // 0x80056A20: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80056A24: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80056A28: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80056A2C: mul.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80056A30: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80056A34: lwc1        $f20, 0x40($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80056A38: lwc1        $f12, 0x14($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80056A3C: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80056A40: lwc1        $f22, 0x50($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80056A44: lwc1        $f24, 0x58($s0)
    ctx->f24.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80056A48: lwc1        $f28, 0x54($s0)
    ctx->f28.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80056A4C: mul.s       $f4, $f12, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80056A50: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80056A54: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80056A58: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80056A5C: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80056A60: add.s       $f26, $f10, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80056A64: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80056A68: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80056A6C: mul.s       $f10, $f12, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x80056A70: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80056A74: swc1        $f16, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f16.u32l;
    // 0x80056A78: add.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056A7C: neg.s       $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = -ctx->f26.fl;
    // 0x80056A80: jal         0x8001BA74
    // 0x80056A84: neg.s       $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = -ctx->f30.fl;
    get_racer_objects(rdram, ctx);
        goto after_2;
    // 0x80056A84: neg.s       $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = -ctx->f30.fl;
    after_2:
    // 0x80056A88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056A8C: lwc1        $f12, 0x68C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X68C4);
    // 0x80056A90: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80056A94: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80056A98: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80056A9C: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80056AA0: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80056AA4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80056AA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80056AAC: blez        $t8, L_80056DD8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80056AB0: swc1        $f12, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->f12.u32l;
            goto L_80056DD8;
    }
    // 0x80056AB0: swc1        $f12, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f12.u32l;
    // 0x80056AB4: andi        $a0, $t8, 0x1
    ctx->r4 = ctx->r24 & 0X1;
    // 0x80056AB8: beq         $a0, $zero, L_80056BD4
    if (ctx->r4 == 0) {
        // 0x80056ABC: lw          $t3, 0x70($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X70);
            goto L_80056BD4;
    }
    // 0x80056ABC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80056AC0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80056AC4: nop

    // 0x80056AC8: beq         $s1, $a0, L_80056BC4
    if (ctx->r17 == ctx->r4) {
        // 0x80056ACC: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_80056BC4;
    }
    // 0x80056ACC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80056AD0: beq         $t2, $zero, L_80056AF0
    if (ctx->r10 == 0) {
        // 0x80056AD4: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80056AF0;
    }
    // 0x80056AD4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80056AD8: lw          $t9, 0x64($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X64);
    // 0x80056ADC: nop

    // 0x80056AE0: lb          $t4, 0x1D8($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X1D8);
    // 0x80056AE4: nop

    // 0x80056AE8: bne         $t4, $zero, L_80056BC4
    if (ctx->r12 != 0) {
        // 0x80056AEC: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_80056BC4;
    }
    // 0x80056AEC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
L_80056AF0:
    // 0x80056AF0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80056AF4: lb          $t5, 0x212($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X212);
    // 0x80056AF8: lb          $t7, 0x212($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X212);
    // 0x80056AFC: nop

    // 0x80056B00: bne         $t5, $t7, L_80056BC4
    if (ctx->r13 != ctx->r15) {
        // 0x80056B04: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_80056BC4;
    }
    // 0x80056B04: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80056B08: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056B0C: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056B10: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80056B14: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80056B18: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80056B1C: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056B20: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80056B24: mul.s       $f6, $f20, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80056B28: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056B2C: add.s       $f8, $f10, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x80056B30: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x80056B34: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x80056B38: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x80056B3C: bc1f        L_80056BC4
    if (!c1cs) {
        // 0x80056B40: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_80056BC4;
    }
    // 0x80056B40: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80056B44: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056B48: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056B4C: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80056B50: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056B54: mul.s       $f4, $f28, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f8.fl);
    // 0x80056B58: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056B5C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80056B60: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80056B64: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056B68: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80056B6C: add.s       $f2, $f4, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x80056B70: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80056B74: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80056B78: bc1f        L_80056B84
    if (!c1cs) {
        // 0x80056B7C: nop
    
            goto L_80056B84;
    }
    // 0x80056B7C: nop

    // 0x80056B80: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80056B84:
    // 0x80056B84: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80056B88: nop

    // 0x80056B8C: bc1t        L_80056B98
    if (c1cs) {
        // 0x80056B90: nop
    
            goto L_80056B98;
    }
    // 0x80056B90: nop

    // 0x80056B94: bne         $t1, $at, L_80056BC0
    if (ctx->r9 != ctx->r1) {
        // 0x80056B98: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80056BC0;
    }
L_80056B98:
    // 0x80056B98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056B9C: lwc1        $f6, 0x68C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X68C8);
    // 0x80056BA0: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056BA4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80056BA8: nop

    // 0x80056BAC: bc1f        L_80056BC4
    if (!c1cs) {
        // 0x80056BB0: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_80056BC4;
    }
    // 0x80056BB0: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80056BB4: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x80056BB8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80056BBC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_80056BC0:
    // 0x80056BC0: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
L_80056BC4:
    // 0x80056BC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80056BC8: beq         $v1, $t8, L_80056DD8
    if (ctx->r3 == ctx->r24) {
        // 0x80056BCC: nop
    
            goto L_80056DD8;
    }
    // 0x80056BCC: nop

    // 0x80056BD0: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
L_80056BD4:
    // 0x80056BD4: sll         $a3, $v1, 2
    ctx->r7 = S32(ctx->r3 << 2);
    // 0x80056BD8: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80056BDC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80056BE0: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x80056BE4: addu        $a2, $v0, $a3
    ctx->r6 = ADD32(ctx->r2, ctx->r7);
L_80056BE8:
    // 0x80056BE8: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80056BEC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80056BF0: beq         $s1, $a0, L_80056CE0
    if (ctx->r17 == ctx->r4) {
        // 0x80056BF4: nop
    
            goto L_80056CE0;
    }
    // 0x80056BF4: nop

    // 0x80056BF8: beq         $t2, $zero, L_80056C18
    if (ctx->r10 == 0) {
        // 0x80056BFC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80056C18;
    }
    // 0x80056BFC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80056C00: lw          $t4, 0x64($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X64);
    // 0x80056C04: nop

    // 0x80056C08: lb          $t6, 0x1D8($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X1D8);
    // 0x80056C0C: nop

    // 0x80056C10: bne         $t6, $zero, L_80056CE0
    if (ctx->r14 != 0) {
        // 0x80056C14: nop
    
            goto L_80056CE0;
    }
    // 0x80056C14: nop

L_80056C18:
    // 0x80056C18: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80056C1C: lb          $t5, 0x212($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X212);
    // 0x80056C20: lb          $t8, 0x212($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X212);
    // 0x80056C24: nop

    // 0x80056C28: bne         $t5, $t8, L_80056CE0
    if (ctx->r13 != ctx->r24) {
        // 0x80056C2C: nop
    
            goto L_80056CE0;
    }
    // 0x80056C2C: nop

    // 0x80056C30: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056C34: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056C38: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80056C3C: nop

    // 0x80056C40: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80056C44: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056C48: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056C4C: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80056C50: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80056C54: add.s       $f6, $f10, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x80056C58: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x80056C5C: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x80056C60: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x80056C64: bc1f        L_80056CE0
    if (!c1cs) {
        // 0x80056C68: nop
    
            goto L_80056CE0;
    }
    // 0x80056C68: nop

    // 0x80056C6C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056C70: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056C74: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80056C78: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056C7C: mul.s       $f4, $f28, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f6.fl);
    // 0x80056C80: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056C84: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80056C88: mul.s       $f10, $f24, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x80056C8C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056C90: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056C94: add.s       $f2, $f4, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x80056C98: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80056C9C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80056CA0: bc1f        L_80056CAC
    if (!c1cs) {
        // 0x80056CA4: nop
    
            goto L_80056CAC;
    }
    // 0x80056CA4: nop

    // 0x80056CA8: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80056CAC:
    // 0x80056CAC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80056CB0: nop

    // 0x80056CB4: bc1t        L_80056CC4
    if (c1cs) {
        // 0x80056CB8: nop
    
            goto L_80056CC4;
    }
    // 0x80056CB8: nop

    // 0x80056CBC: bne         $t1, $at, L_80056CE0
    if (ctx->r9 != ctx->r1) {
        // 0x80056CC0: nop
    
            goto L_80056CE0;
    }
    // 0x80056CC0: nop

L_80056CC4:
    // 0x80056CC4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80056CC8: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056CCC: bc1f        L_80056CE0
    if (!c1cs) {
        // 0x80056CD0: nop
    
            goto L_80056CE0;
    }
    // 0x80056CD0: nop

    // 0x80056CD4: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80056CD8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80056CDC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_80056CE0:
    // 0x80056CE0: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x80056CE4: nop

    // 0x80056CE8: beq         $s1, $a0, L_80056DD0
    if (ctx->r17 == ctx->r4) {
        // 0x80056CEC: nop
    
            goto L_80056DD0;
    }
    // 0x80056CEC: nop

    // 0x80056CF0: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x80056CF4: beq         $t2, $zero, L_80056D0C
    if (ctx->r10 == 0) {
        // 0x80056CF8: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80056D0C;
    }
    // 0x80056CF8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80056CFC: lb          $t9, 0x1D8($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1D8);
    // 0x80056D00: nop

    // 0x80056D04: bne         $t9, $zero, L_80056DD0
    if (ctx->r25 != 0) {
        // 0x80056D08: nop
    
            goto L_80056DD0;
    }
    // 0x80056D08: nop

L_80056D0C:
    // 0x80056D0C: lb          $t4, 0x212($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X212);
    // 0x80056D10: lb          $t6, 0x212($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X212);
    // 0x80056D14: nop

    // 0x80056D18: bne         $t4, $t6, L_80056DD0
    if (ctx->r12 != ctx->r14) {
        // 0x80056D1C: nop
    
            goto L_80056DD0;
    }
    // 0x80056D1C: nop

    // 0x80056D20: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056D24: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056D28: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80056D2C: nop

    // 0x80056D30: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80056D34: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056D38: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80056D3C: mul.s       $f4, $f20, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80056D40: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80056D44: add.s       $f6, $f8, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x80056D48: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80056D4C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x80056D50: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x80056D54: bc1f        L_80056DD0
    if (!c1cs) {
        // 0x80056D58: nop
    
            goto L_80056DD0;
    }
    // 0x80056D58: nop

    // 0x80056D5C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056D60: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80056D64: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80056D68: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056D6C: mul.s       $f10, $f28, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f6.fl);
    // 0x80056D70: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80056D74: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056D78: mul.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x80056D7C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056D80: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80056D84: add.s       $f2, $f10, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x80056D88: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80056D8C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80056D90: bc1f        L_80056D9C
    if (!c1cs) {
        // 0x80056D94: nop
    
            goto L_80056D9C;
    }
    // 0x80056D94: nop

    // 0x80056D98: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80056D9C:
    // 0x80056D9C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80056DA0: nop

    // 0x80056DA4: bc1t        L_80056DB4
    if (c1cs) {
        // 0x80056DA8: nop
    
            goto L_80056DB4;
    }
    // 0x80056DA8: nop

    // 0x80056DAC: bne         $t1, $at, L_80056DD0
    if (ctx->r9 != ctx->r1) {
        // 0x80056DB0: nop
    
            goto L_80056DD0;
    }
    // 0x80056DB0: nop

L_80056DB4:
    // 0x80056DB4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80056DB8: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80056DBC: bc1f        L_80056DD0
    if (!c1cs) {
        // 0x80056DC0: nop
    
            goto L_80056DD0;
    }
    // 0x80056DC0: nop

    // 0x80056DC4: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x80056DC8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80056DCC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_80056DD0:
    // 0x80056DD0: bne         $a3, $t3, L_80056BE8
    if (ctx->r7 != ctx->r11) {
        // 0x80056DD4: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80056BE8;
    }
    // 0x80056DD4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80056DD8:
    // 0x80056DD8: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80056DDC: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80056DE0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80056DE4: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
L_80056DE8:
    // 0x80056DE8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80056DEC: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80056DF0: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80056DF4: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80056DF8: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80056DFC: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80056E00: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056E04: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80056E08: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80056E0C: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80056E10: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80056E14: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80056E18: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80056E1C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80056E20: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80056E24: jr          $ra
    // 0x80056E28: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80056E28: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void menu_game_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C7BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008C7C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C7C4: jal         0x8008C168
    // 0x8008C7C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    charselect_music_channels(rdram, ctx);
        goto after_0;
    // 0x8008C7C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008C7CC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C7D0: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x8008C7D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008C7D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008C7DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C7E0: addiu       $a1, $a1, 0x63D8
    ctx->r5 = ADD32(ctx->r5, 0X63D8);
    // 0x8008C7E4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008C7E8: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8008C7EC: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8008C7F0: beq         $v0, $zero, L_8008C820
    if (ctx->r2 == 0) {
        // 0x8008C7F4: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008C820;
    }
    // 0x8008C7F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008C7F8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8008C7FC: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8008C800: bne         $at, $zero, L_8008C820
    if (ctx->r1 != 0) {
        // 0x8008C804: sw          $t9, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r25;
            goto L_8008C820;
    }
    // 0x8008C804: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8008C808: jal         0x800828B8
    // 0x8008C80C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    trackmenu_set_records(rdram, ctx);
        goto after_1;
    // 0x8008C80C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x8008C810: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C814: addiu       $a1, $a1, 0x63D8
    ctx->r5 = ADD32(ctx->r5, 0X63D8);
    // 0x8008C818: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008C81C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8008C820:
    // 0x8008C820: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008C824: addiu       $v1, $v1, -0xB84
    ctx->r3 = ADD32(ctx->r3, -0XB84);
    // 0x8008C828: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C82C: nop

    // 0x8008C830: beq         $v0, $zero, L_8008C85C
    if (ctx->r2 == 0) {
        // 0x8008C834: slti        $at, $v0, 0x1F
        ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
            goto L_8008C85C;
    }
    // 0x8008C834: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8008C838: bgez        $v0, L_8008C850
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008C83C: addu        $t2, $v0, $a0
        ctx->r10 = ADD32(ctx->r2, ctx->r4);
            goto L_8008C850;
    }
    // 0x8008C83C: addu        $t2, $v0, $a0
    ctx->r10 = ADD32(ctx->r2, ctx->r4);
    // 0x8008C840: subu        $t1, $v0, $a0
    ctx->r9 = SUB32(ctx->r2, ctx->r4);
    // 0x8008C844: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008C848: b           L_8008C858
    // 0x8008C84C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8008C858;
    // 0x8008C84C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8008C850:
    // 0x8008C850: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8008C854: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8008C858:
    // 0x8008C858: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
L_8008C85C:
    // 0x8008C85C: bne         $at, $zero, L_8008C8EC
    if (ctx->r1 != 0) {
        // 0x8008C860: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_8008C8EC;
    }
    // 0x8008C860: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x8008C864: jal         0x8008CACC
    // 0x8008C868: nop

    gameselect_free(rdram, ctx);
        goto after_2;
    // 0x8008C868: nop

    after_2:
    // 0x8008C86C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008C870: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008C874: lw          $t3, 0x63E0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X63E0);
    // 0x8008C878: lw          $v0, -0xBA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XBA0);
    // 0x8008C87C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C880: bne         $t3, $v0, L_8008C8C0
    if (ctx->r11 != ctx->r2) {
        // 0x8008C884: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008C8C0;
    }
    // 0x8008C884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008C888: jal         0x80000B28
    // 0x8008C88C: nop

    music_change_on(rdram, ctx);
        goto after_3;
    // 0x8008C88C: nop

    after_3:
    // 0x8008C890: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008C894: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C898: jal         0x8006E5BC
    // 0x8008C89C: sw          $t4, -0xB48($at)
    MEM_W(-0XB48, ctx->r1) = ctx->r12;
    init_racer_headers(rdram, ctx);
        goto after_4;
    // 0x8008C89C: sw          $t4, -0xB48($at)
    MEM_W(-0XB48, ctx->r1) = ctx->r12;
    after_4:
    // 0x8008C8A0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8008C8A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008C8A8: jal         0x8006E2E8
    // 0x8008C8AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_5;
    // 0x8008C8AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8008C8B0: jal         0x800813D0
    // 0x8008C8B4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    menu_init(rdram, ctx);
        goto after_6;
    // 0x8008C8B4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_6:
    // 0x8008C8B8: b           L_8008CABC
    // 0x8008C8BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008CABC;
    // 0x8008C8BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C8C0:
    // 0x8008C8C0: sw          $v0, -0xB6C($at)
    MEM_W(-0XB6C, ctx->r1) = ctx->r2;
    // 0x8008C8C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C8C8: sw          $zero, -0xB48($at)
    MEM_W(-0XB48, ctx->r1) = 0;
    // 0x8008C8CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C8D0: jal         0x8006DB14
    // 0x8008C8D4: sb          $zero, 0x69C0($at)
    MEM_B(0X69C0, ctx->r1) = 0;
    set_level_default_vehicle(rdram, ctx);
        goto after_7;
    // 0x8008C8D4: sb          $zero, 0x69C0($at)
    MEM_B(0X69C0, ctx->r1) = 0;
    after_7:
    // 0x8008C8D8: jal         0x800813D0
    // 0x8008C8DC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    menu_init(rdram, ctx);
        goto after_8;
    // 0x8008C8DC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_8:
    // 0x8008C8E0: b           L_8008CABC
    // 0x8008C8E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008CABC;
    // 0x8008C8E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008C8E8: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_8008C8EC:
    // 0x8008C8EC: beq         $at, $zero, L_8008C954
    if (ctx->r1 == 0) {
        // 0x8008C8F0: nop
    
            goto L_8008C954;
    }
    // 0x8008C8F0: nop

    // 0x8008C8F4: jal         0x8008CACC
    // 0x8008C8F8: nop

    gameselect_free(rdram, ctx);
        goto after_9;
    // 0x8008C8F8: nop

    after_9:
    // 0x8008C8FC: jal         0x8009ECD0
    // 0x8008C900: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_10;
    // 0x8008C900: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_10:
    // 0x8008C904: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C908: beq         $v0, $zero, L_8008C914
    if (ctx->r2 == 0) {
        // 0x8008C90C: nop
    
            goto L_8008C914;
    }
    // 0x8008C90C: nop

    // 0x8008C910: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8008C914:
    // 0x8008C914: jal         0x8009ECB8
    // 0x8008C918: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    is_tt_unlocked(rdram, ctx);
        goto after_11;
    // 0x8008C918: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_11:
    // 0x8008C91C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C920: beq         $v0, $zero, L_8008C930
    if (ctx->r2 == 0) {
        // 0x8008C924: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_8008C930;
    }
    // 0x8008C924: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008C928: xori        $t5, $a2, 0x3
    ctx->r13 = ctx->r6 ^ 0X3;
    // 0x8008C92C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
L_8008C930:
    // 0x8008C930: jal         0x8006E2E8
    // 0x8008C934: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_12;
    // 0x8008C934: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_12:
    // 0x8008C938: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008C93C: jal         0x8008AEB4
    // 0x8008C940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_13;
    // 0x8008C940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x8008C944: jal         0x800813D0
    // 0x8008C948: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    menu_init(rdram, ctx);
        goto after_14;
    // 0x8008C948: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x8008C94C: b           L_8008CABC
    // 0x8008C950: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008CABC;
    // 0x8008C950: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C954:
    // 0x8008C954: jal         0x8008C698
    // 0x8008C958: nop

    gameselect_render(rdram, ctx);
        goto after_15;
    // 0x8008C958: nop

    after_15:
    // 0x8008C95C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008C960: lw          $t6, -0xB84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB84);
    // 0x8008C964: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C968: bne         $t6, $zero, L_8008CAB0
    if (ctx->r14 != 0) {
        // 0x8008C96C: addiu       $a1, $a1, 0x63D8
        ctx->r5 = ADD32(ctx->r5, 0X63D8);
            goto L_8008CAB0;
    }
    // 0x8008C96C: addiu       $a1, $a1, 0x63D8
    ctx->r5 = ADD32(ctx->r5, 0X63D8);
    // 0x8008C970: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8008C974: nop

    // 0x8008C978: bne         $t7, $zero, L_8008CAB0
    if (ctx->r15 != 0) {
        // 0x8008C97C: nop
    
            goto L_8008CAB0;
    }
    // 0x8008C97C: nop

    // 0x8008C980: jal         0x8006A554
    // 0x8008C984: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_16;
    // 0x8008C984: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8008C988: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008C98C: lw          $t8, -0xB44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB44);
    // 0x8008C990: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008C994: lb          $a2, 0x6464($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X6464);
    // 0x8008C998: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008C99C: bne         $t8, $at, L_8008C9CC
    if (ctx->r24 != ctx->r1) {
        // 0x8008C9A0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008C9CC;
    }
    // 0x8008C9A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008C9A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008C9A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8008C9AC: jal         0x8006A554
    // 0x8008C9B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    input_pressed(rdram, ctx);
        goto after_17;
    // 0x8008C9B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_17:
    // 0x8008C9B4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008C9B8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8008C9BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008C9C0: lb          $t9, 0x6465($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X6465);
    // 0x8008C9C4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008C9C8: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_8008C9CC:
    // 0x8008C9CC: andi        $t0, $v1, 0x9000
    ctx->r8 = ctx->r3 & 0X9000;
    // 0x8008C9D0: beq         $t0, $zero, L_8008CA28
    if (ctx->r8 == 0) {
        // 0x8008C9D4: andi        $t4, $v1, 0x4000
        ctx->r12 = ctx->r3 & 0X4000;
            goto L_8008CA28;
    }
    // 0x8008C9D4: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x8008C9D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008C9DC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008C9E0: lw          $t2, -0xBA0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XBA0);
    // 0x8008C9E4: lw          $t1, 0x63E0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X63E0);
    // 0x8008C9E8: nop

    // 0x8008C9EC: bne         $t1, $t2, L_8008C9FC
    if (ctx->r9 != ctx->r10) {
        // 0x8008C9F0: nop
    
            goto L_8008C9FC;
    }
    // 0x8008C9F0: nop

    // 0x8008C9F4: jal         0x80000C98
    // 0x8008C9F8: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_18;
    // 0x8008C9F8: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_18:
L_8008C9FC:
    // 0x8008C9FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CA00: jal         0x800C01D8
    // 0x8008CA04: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_19;
    // 0x8008CA04: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_19:
    // 0x8008CA08: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008CA0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CA10: sw          $t3, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r11;
    // 0x8008CA14: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008CA18: jal         0x80001D04
    // 0x8008CA1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_20;
    // 0x8008CA1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x8008CA20: b           L_8008CAB0
    // 0x8008CA24: nop

        goto L_8008CAB0;
    // 0x8008CA24: nop

L_8008CA28:
    // 0x8008CA28: beq         $t4, $zero, L_8008CA48
    if (ctx->r12 == 0) {
        // 0x8008CA2C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008CA48;
    }
    // 0x8008CA2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CA30: jal         0x800C01D8
    // 0x8008CA34: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_21;
    // 0x8008CA34: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_21:
    // 0x8008CA38: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8008CA3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008CA40: b           L_8008CAB0
    // 0x8008CA44: sw          $t5, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r13;
        goto L_8008CAB0;
    // 0x8008CA44: sw          $t5, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r13;
L_8008CA48:
    // 0x8008CA48: bgez        $a2, L_8008CA88
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008CA4C: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8008CA88;
    }
    // 0x8008CA4C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008CA50: addiu       $v1, $v1, -0xBA0
    ctx->r3 = ADD32(ctx->r3, -0XBA0);
    // 0x8008CA54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008CA58: lw          $t6, 0x63E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63E0);
    // 0x8008CA5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008CA60: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008CA64: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8008CA68: beq         $at, $zero, L_8008CA88
    if (ctx->r1 == 0) {
        // 0x8008CA6C: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_8008CA88;
    }
    // 0x8008CA6C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8008CA70: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008CA74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008CA78: jal         0x80001D04
    // 0x8008CA7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    sound_play(rdram, ctx);
        goto after_22;
    // 0x8008CA7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_22:
    // 0x8008CA80: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008CA84: nop

L_8008CA88:
    // 0x8008CA88: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008CA8C: blez        $a2, L_8008CAB0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008CA90: addiu       $v1, $v1, -0xBA0
        ctx->r3 = ADD32(ctx->r3, -0XBA0);
            goto L_8008CAB0;
    }
    // 0x8008CA90: addiu       $v1, $v1, -0xBA0
    ctx->r3 = ADD32(ctx->r3, -0XBA0);
    // 0x8008CA94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008CA98: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008CA9C: blez        $v0, L_8008CAB0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008CAA0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8008CAB0;
    }
    // 0x8008CAA0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8008CAA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008CAA8: jal         0x80001D04
    // 0x8008CAAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x8008CAAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
L_8008CAB0:
    // 0x8008CAB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CAB4: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
    // 0x8008CAB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008CABC:
    // 0x8008CABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CAC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008CAC4: jr          $ra
    // 0x8008CAC8: nop

    return;
    // 0x8008CAC8: nop

;}
RECOMP_FUNC void init_racer_for_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800228F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800228F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800228F8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800228FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022900: sb          $t6, -0x5109($at)
    MEM_B(-0X5109, ctx->r1) = ctx->r14;
    // 0x80022904: jal         0x8001BAC8
    // 0x80022908: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80022908: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8002290C: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80022910: nop

    // 0x80022914: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x80022918: sb          $zero, 0x192($v1)
    MEM_B(0X192, ctx->r3) = 0;
    // 0x8002291C: sb          $zero, 0x193($v1)
    MEM_B(0X193, ctx->r3) = 0;
    // 0x80022920: sh          $zero, 0x1BA($v1)
    MEM_H(0X1BA, ctx->r3) = 0;
    // 0x80022924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80022928: jal         0x80017E74
    // 0x8002292C: nop

    set_taj_challenge_type(rdram, ctx);
        goto after_1;
    // 0x8002292C: nop

    after_1:
    // 0x80022930: jal         0x8006F388
    // 0x80022934: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    set_pause_lockout_timer(rdram, ctx);
        goto after_2;
    // 0x80022934: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x80022938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002293C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022940: jr          $ra
    // 0x80022944: nop

    return;
    // 0x80022944: nop

;}
RECOMP_FUNC void alSynDelete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2C60: jr          $ra
    // 0x800D2C64: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x800D2C64: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void transition_render_waves(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C23F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C23FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C2400: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C2404: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C2408: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C240C: jal         0x8007B3D0
    // 0x800C2410: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C2410: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C2414: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C2418: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800C241C: lw          $v1, 0x31D0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31D0);
    // 0x800C2420: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800C2424: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800C2428: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C242C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C2430: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800C2434: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C2438: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C243C: lw          $a2, 0x31C0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X31C0);
    // 0x800C2440: lw          $a3, 0x31C8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X31C8);
    // 0x800C2444: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C2448: addiu       $t9, $t9, 0x3648
    ctx->r25 = ADD32(ctx->r25, 0X3648);
    // 0x800C244C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800C2450: lui         $s0, 0x5D0
    ctx->r16 = S32(0X5D0 << 16);
    // 0x800C2454: lui         $t5, 0x5B0
    ctx->r13 = S32(0X5B0 << 16);
    // 0x800C2458: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800C245C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800C2460: ori         $t5, $t5, 0xC0
    ctx->r13 = ctx->r13 | 0XC0;
    // 0x800C2464: ori         $s0, $s0, 0xE0
    ctx->r16 = ctx->r16 | 0XE0;
    // 0x800C2468: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C246C: addiu       $ra, $zero, 0x6
    ctx->r31 = ADD32(0, 0X6);
    // 0x800C2470: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C2474: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C2478: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x800C247C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800C2480: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800C2484:
    // 0x800C2484: beq         $t0, $t3, L_800C2494
    if (ctx->r8 == ctx->r11) {
        // 0x800C2488: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C2494;
    }
    // 0x800C2488: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C248C: bne         $t0, $t4, L_800C24DC
    if (ctx->r8 != ctx->r12) {
        // 0x800C2490: addu        $a0, $a2, $t1
        ctx->r4 = ADD32(ctx->r6, ctx->r9);
            goto L_800C24DC;
    }
    // 0x800C2490: addu        $a0, $a2, $t1
    ctx->r4 = ADD32(ctx->r6, ctx->r9);
L_800C2494:
    // 0x800C2494: addu        $a0, $a2, $t1
    ctx->r4 = ADD32(ctx->r6, ctx->r9);
    // 0x800C2498: andi        $t6, $a0, 0x6
    ctx->r14 = ctx->r4 & 0X6;
    // 0x800C249C: ori         $t7, $t6, 0x68
    ctx->r15 = ctx->r14 | 0X68;
    // 0x800C24A0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800C24A4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C24A8: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x800C24AC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C24B0: ori         $t7, $t6, 0x104
    ctx->r15 = ctx->r14 | 0X104;
    // 0x800C24B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C24B8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C24BC: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C24C0: addu        $t8, $a3, $t1
    ctx->r24 = ADD32(ctx->r7, ctx->r9);
    // 0x800C24C4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800C24C8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800C24CC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C24D0: addiu       $a2, $a2, 0x8C
    ctx->r6 = ADD32(ctx->r6, 0X8C);
    // 0x800C24D4: b           L_800C2520
    // 0x800C24D8: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
        goto L_800C2520;
    // 0x800C24D8: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
L_800C24DC:
    // 0x800C24DC: andi        $t9, $a0, 0x6
    ctx->r25 = ctx->r4 & 0X6;
    // 0x800C24E0: ori         $t6, $t9, 0x78
    ctx->r14 = ctx->r25 | 0X78;
    // 0x800C24E4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800C24E8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800C24EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C24F0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C24F4: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x800C24F8: ori         $t6, $t9, 0x128
    ctx->r14 = ctx->r25 | 0X128;
    // 0x800C24FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C2500: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C2504: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C2508: addu        $t7, $a3, $t1
    ctx->r15 = ADD32(ctx->r7, ctx->r9);
    // 0x800C250C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800C2510: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800C2514: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800C2518: addiu       $a2, $a2, 0xA0
    ctx->r6 = ADD32(ctx->r6, 0XA0);
    // 0x800C251C: addiu       $a3, $a3, 0xE0
    ctx->r7 = ADD32(ctx->r7, 0XE0);
L_800C2520:
    // 0x800C2520: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C2524: bne         $t0, $ra, L_800C2484
    if (ctx->r8 != ctx->r31) {
        // 0x800C2528: nop
    
            goto L_800C2484;
    }
    // 0x800C2528: nop

    // 0x800C252C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C2530: jal         0x8007B3D0
    // 0x800C2534: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C2534: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    after_1:
    // 0x800C2538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C253C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C2540: jr          $ra
    // 0x800C2544: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C2544: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800756D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800756D4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800756D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800756DC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800756E0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800756E4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800756E8: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800756EC: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x800756F0: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x800756F4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800756F8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800756FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80075700: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80075704: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80075708: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007570C: jal         0x800758DC
    // 0x80075710: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075710: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x80075714: beq         $v0, $zero, L_80075734
    if (ctx->r2 == 0) {
        // 0x80075718: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80075734;
    }
    // 0x80075718: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8007571C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80075720: jal         0x80075AEC
    // 0x80075724: nop

    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80075724: nop

    after_1:
    // 0x80075728: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x8007572C: b           L_800758B0
    // 0x80075730: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800758B0;
    // 0x80075730: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80075734:
    // 0x80075734: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x80075738: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007573C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80075740: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80075744: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80075748: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8007574C: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
L_80075750:
    // 0x80075750: sb          $a3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r7;
    // 0x80075754: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80075758: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8007575C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80075760: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80075764: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80075768: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007576C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80075770: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80075774: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80075778: bne         $at, $zero, L_80075750
    if (ctx->r1 != 0) {
        // 0x8007577C: sb          $v0, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r2;
            goto L_80075750;
    }
    // 0x8007577C: sb          $v0, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r2;
    // 0x80075780: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80075784: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80075788: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007578C: addiu       $a2, $a2, 0x77DC
    ctx->r6 = ADD32(ctx->r6, 0X77DC);
    // 0x80075790: addiu       $a1, $a1, 0x77CC
    ctx->r5 = ADD32(ctx->r5, 0X77CC);
    // 0x80075794: jal         0x800764E8
    // 0x80075798: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x80075798: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_2:
    // 0x8007579C: bne         $v0, $zero, L_80075898
    if (ctx->r2 != 0) {
        // 0x800757A0: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80075898;
    }
    // 0x800757A0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800757A4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800757A8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800757AC: jal         0x80076924
    // 0x800757B0: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x800757B0: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_3:
    // 0x800757B4: bne         $v0, $zero, L_80075898
    if (ctx->r2 != 0) {
        // 0x800757B8: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80075898;
    }
    // 0x800757B8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800757BC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800757C0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800757C4: jal         0x80070C9C
    // 0x800757C8: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800757C8: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_4:
    // 0x800757CC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800757D0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800757D4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800757D8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800757DC: jal         0x80076610
    // 0x800757E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x800757E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x800757E4: bne         $v0, $zero, L_80075890
    if (ctx->r2 != 0) {
        // 0x800757E8: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_80075890;
    }
    // 0x800757E8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800757EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800757F0: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x800757F4: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
    // 0x800757F8: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_800757FC:
    // 0x800757FC: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x80075800: nop

    // 0x80075804: beq         $s3, $t6, L_80075884
    if (ctx->r19 == ctx->r14) {
        // 0x80075808: nop
    
            goto L_80075884;
    }
    // 0x80075808: nop

    // 0x8007580C: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80075810: jal         0x80074A4C
    // 0x80075814: addu        $a0, $t7, $s2
    ctx->r4 = ADD32(ctx->r15, ctx->r18);
    calculate_ghost_header_checksum(rdram, ctx);
        goto after_6;
    // 0x80075814: addu        $a0, $t7, $s2
    ctx->r4 = ADD32(ctx->r15, ctx->r18);
    after_6:
    // 0x80075818: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x8007581C: nop

    // 0x80075820: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x80075824: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80075828: nop

    // 0x8007582C: beq         $v0, $t0, L_8007583C
    if (ctx->r2 == ctx->r8) {
        // 0x80075830: addiu       $t1, $zero, 0x9
        ctx->r9 = ADD32(0, 0X9);
            goto L_8007583C;
    }
    // 0x80075830: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80075834: b           L_80075890
    // 0x80075838: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
        goto L_80075890;
    // 0x80075838: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
L_8007583C:
    // 0x8007583C: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x80075840: addu        $t3, $s6, $s0
    ctx->r11 = ADD32(ctx->r22, ctx->r16);
    // 0x80075844: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x80075848: lbu         $t4, 0x1($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X1);
    // 0x8007584C: addu        $t5, $fp, $s0
    ctx->r13 = ADD32(ctx->r30, ctx->r16);
    // 0x80075850: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x80075854: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x80075858: addu        $t9, $s7, $s0
    ctx->r25 = ADD32(ctx->r23, ctx->r16);
    // 0x8007585C: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80075860: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x80075864: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x80075868: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8007586C: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x80075870: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x80075874: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x80075878: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x8007587C: nop

    // 0x80075880: sh          $t2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r10;
L_80075884:
    // 0x80075884: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80075888: bne         $s0, $s4, L_800757FC
    if (ctx->r16 != ctx->r20) {
        // 0x8007588C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800757FC;
    }
    // 0x8007588C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80075890:
    // 0x80075890: jal         0x80071140
    // 0x80075894: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80075894: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
L_80075898:
    // 0x80075898: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8007589C: jal         0x80075AEC
    // 0x800758A0: nop

    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x800758A0: nop

    after_8:
    // 0x800758A4: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x800758A8: nop

    // 0x800758AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800758B0:
    // 0x800758B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800758B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800758B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800758BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800758C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800758C4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800758C8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800758CC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800758D0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800758D4: jr          $ra
    // 0x800758D8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800758D8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void mark_to_write_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EBE0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EBE4: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006EBE8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EBEC: nop

    // 0x8006EBF0: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8006EBF4: jr          $ra
    // 0x8006EBF8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EBF8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void set_taj_voice_line(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039320: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039324: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80039328: jr          $ra
    // 0x8003932C: sh          $a0, -0x2B1E($at)
    MEM_H(-0X2B1E, ctx->r1) = ctx->r4;
    return;
    // 0x8003932C: sh          $a0, -0x2B1E($at)
    MEM_H(-0X2B1E, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_loop_wizghosts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042CD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80042CDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80042CE0: jal         0x8001F460
    // 0x80042CE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80042CE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x80042CE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80042CEC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80042CF0: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80042CF4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80042CF8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80042CFC: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80042D00: sh          $t0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r8;
    // 0x80042D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042D0C: jr          $ra
    // 0x80042D10: nop

    return;
    // 0x80042D10: nop

;}
RECOMP_FUNC void alSavePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC514: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CC518: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CC51C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CC520: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800CC524: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800CC528: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CC52C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CC530: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800CC534: jalr        $t9
    // 0x800CC538: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC538: nop

    after_0:
    // 0x800CC53C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800CC540: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800CC544: lui         $t2, 0x440
    ctx->r10 = S32(0X440 << 16);
    // 0x800CC548: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800CC54C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800CC550: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x800CC554: ori         $t2, $t2, 0x580
    ctx->r10 = ctx->r10 | 0X580;
    // 0x800CC558: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x800CC55C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800CC560: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800CC564: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800CC568: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800CC56C: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x800CC570: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800CC574: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800CC578: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x800CC57C: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x800CC580: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CC584: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800CC588: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800CC58C: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x800CC590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC594: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CC598: jr          $ra
    // 0x800CC59C: nop

    return;
    // 0x800CC59C: nop

;}
RECOMP_FUNC void obj_loop_weaponballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E140: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003E144: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003E148: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003E14C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8003E150: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x8003E154: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003E158: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    // 0x8003E15C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003E160: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8003E164: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003E168: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003E16C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003E170: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003E174: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003E178: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8003E17C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E180: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003E184: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003E188: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003E18C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8003E190: sub.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d - ctx->f16.d;
    // 0x8003E194: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8003E198: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8003E19C: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x8003E1A0: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003E1A4: lwc1        $f6, 0x61AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61AC);
    // 0x8003E1A8: lwc1        $f7, 0x61A8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X61A8);
    // 0x8003E1AC: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x8003E1B0: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8003E1B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E1B8: bc1f        L_8003E1D8
    if (!c1cs) {
        // 0x8003E1BC: nop
    
            goto L_8003E1D8;
    }
    // 0x8003E1BC: nop

    // 0x8003E1C0: lwc1        $f8, 0x61B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61B0);
    // 0x8003E1C4: nop

    // 0x8003E1C8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8003E1CC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003E1D0: nop

    // 0x8003E1D4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
L_8003E1D8:
    // 0x8003E1D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E1DC: lwc1        $f11, 0x61B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X61B8);
    // 0x8003E1E0: lwc1        $f10, 0x61BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61BC);
    // 0x8003E1E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E1E8: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8003E1EC: nop

    // 0x8003E1F0: bc1f        L_8003E20C
    if (!c1cs) {
        // 0x8003E1F4: nop
    
            goto L_8003E20C;
    }
    // 0x8003E1F4: nop

    // 0x8003E1F8: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8003E1FC: nop

    // 0x8003E200: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x8003E204: b           L_8003E21C
    // 0x8003E208: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
        goto L_8003E21C;
    // 0x8003E208: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_8003E20C:
    // 0x8003E20C: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x8003E210: nop

    // 0x8003E214: andi        $t0, $t9, 0xBFFF
    ctx->r8 = ctx->r25 & 0XBFFF;
    // 0x8003E218: sh          $t0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r8;
L_8003E21C:
    // 0x8003E21C: lw          $t1, 0x7C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C);
    // 0x8003E220: nop

    // 0x8003E224: blez        $t1, L_8003E258
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8003E228: nop
    
            goto L_8003E258;
    }
    // 0x8003E228: nop

    // 0x8003E22C: sw          $t2, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r10;
    // 0x8003E230: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003E234: jal         0x800AFC3C
    // 0x8003E238: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    obj_spawn_particle(rdram, ctx);
        goto after_0;
    // 0x8003E238: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003E23C: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
    // 0x8003E240: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8003E244: nop

    // 0x8003E248: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8003E24C: sw          $t5, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r13;
    // 0x8003E250: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003E254: nop

L_8003E258:
    // 0x8003E258: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8003E25C: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x8003E260: beq         $v0, $zero, L_8003E2B8
    if (ctx->r2 == 0) {
        // 0x8003E264: nop
    
            goto L_8003E2B8;
    }
    // 0x8003E264: nop

    // 0x8003E268: bne         $v0, $at, L_8003E290
    if (ctx->r2 != ctx->r1) {
        // 0x8003E26C: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_8003E290;
    }
    // 0x8003E26C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8003E270: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003E274: nop

    // 0x8003E278: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003E27C: nop

    // 0x8003E280: slti        $at, $t7, 0x2D
    ctx->r1 = SIGNED(ctx->r15) < 0X2D ? 1 : 0;
    // 0x8003E284: bne         $at, $zero, L_8003E2A8
    if (ctx->r1 != 0) {
        // 0x8003E288: nop
    
            goto L_8003E2A8;
    }
    // 0x8003E288: nop

    // 0x8003E28C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_8003E290:
    // 0x8003E290: nop

    // 0x8003E294: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x8003E298: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x8003E29C: sh          $t0, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r8;
    // 0x8003E2A0: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8003E2A4: nop

L_8003E2A8:
    // 0x8003E2A8: bgez        $v0, L_8003E5A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003E2AC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5A4;
    }
    // 0x8003E2AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E2B0: b           L_8003E5A0
    // 0x8003E2B4: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
        goto L_8003E5A0;
    // 0x8003E2B4: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
L_8003E2B8:
    // 0x8003E2B8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x8003E2BC: nop

    // 0x8003E2C0: lbu         $t1, 0x13($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X13);
    // 0x8003E2C4: nop

    // 0x8003E2C8: slti        $at, $t1, 0x2D
    ctx->r1 = SIGNED(ctx->r9) < 0X2D ? 1 : 0;
    // 0x8003E2CC: beq         $at, $zero, L_8003E5A4
    if (ctx->r1 == 0) {
        // 0x8003E2D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5A4;
    }
    // 0x8003E2D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E2D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003E2D8: nop

    // 0x8003E2DC: beq         $v0, $zero, L_8003E5A4
    if (ctx->r2 == 0) {
        // 0x8003E2E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5A4;
    }
    // 0x8003E2E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E2E4: lw          $t2, 0x40($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X40);
    // 0x8003E2E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E2EC: lb          $t3, 0x54($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X54);
    // 0x8003E2F0: nop

    // 0x8003E2F4: bne         $a0, $t3, L_8003E5A4
    if (ctx->r4 != ctx->r11) {
        // 0x8003E2F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5A4;
    }
    // 0x8003E2F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003E2FC: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003E300: nop

    // 0x8003E304: lb          $t4, 0x1D6($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X1D6);
    // 0x8003E308: nop

    // 0x8003E30C: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8003E310: bne         $at, $zero, L_8003E328
    if (ctx->r1 != 0) {
        // 0x8003E314: nop
    
            goto L_8003E328;
    }
    // 0x8003E314: nop

    // 0x8003E318: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x8003E31C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003E320: beq         $t5, $at, L_8003E5A4
    if (ctx->r13 == ctx->r1) {
        // 0x8003E324: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003E5A4;
    }
    // 0x8003E324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003E328:
    // 0x8003E328: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x8003E32C: lb          $v0, 0x172($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X172);
    // 0x8003E330: sb          $t6, 0x172($v1)
    MEM_B(0X172, ctx->r3) = ctx->r14;
    // 0x8003E334: lb          $t7, 0x172($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X172);
    // 0x8003E338: nop

    // 0x8003E33C: bne         $v0, $t7, L_8003E368
    if (ctx->r2 != ctx->r15) {
        // 0x8003E340: nop
    
            goto L_8003E368;
    }
    // 0x8003E340: nop

    // 0x8003E344: lb          $t9, 0x173($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X173);
    // 0x8003E348: nop

    // 0x8003E34C: beq         $t9, $zero, L_8003E368
    if (ctx->r25 == 0) {
        // 0x8003E350: nop
    
            goto L_8003E368;
    }
    // 0x8003E350: nop

    // 0x8003E354: lb          $t8, 0x174($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X174);
    // 0x8003E358: nop

    // 0x8003E35C: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8003E360: b           L_8003E36C
    // 0x8003E364: sb          $t0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r8;
        goto L_8003E36C;
    // 0x8003E364: sb          $t0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r8;
L_8003E368:
    // 0x8003E368: sb          $zero, 0x174($v1)
    MEM_B(0X174, ctx->r3) = 0;
L_8003E36C:
    // 0x8003E36C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x8003E370: jal         0x8006BD98
    // 0x8003E374: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    level_type(rdram, ctx);
        goto after_1;
    // 0x8003E374: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003E378: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E37C: andi        $t1, $v0, 0x40
    ctx->r9 = ctx->r2 & 0X40;
    // 0x8003E380: beq         $t1, $zero, L_8003E3B4
    if (ctx->r9 == 0) {
        // 0x8003E384: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8003E3B4;
    }
    // 0x8003E384: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E388: lb          $t2, 0x174($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X174);
    // 0x8003E38C: nop

    // 0x8003E390: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8003E394: bne         $at, $zero, L_8003E3A0
    if (ctx->r1 != 0) {
        // 0x8003E398: nop
    
            goto L_8003E3A0;
    }
    // 0x8003E398: nop

    // 0x8003E39C: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
L_8003E3A0:
    // 0x8003E3A0: lb          $t3, 0x172($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X172);
    // 0x8003E3A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003E3A8: bne         $t3, $at, L_8003E3B8
    if (ctx->r11 != ctx->r1) {
        // 0x8003E3AC: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_8003E3B8;
    }
    // 0x8003E3AC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8003E3B0: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
L_8003E3B4:
    // 0x8003E3B4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_8003E3B8:
    // 0x8003E3B8: sb          $t4, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r12;
    // 0x8003E3BC: jal         0x8009C30C
    // 0x8003E3C0: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    get_filtered_cheats(rdram, ctx);
        goto after_2;
    // 0x8003E3C0: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_2:
    // 0x8003E3C4: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E3C8: sll         $t5, $v0, 11
    ctx->r13 = S32(ctx->r2 << 11);
    // 0x8003E3CC: bgez        $t5, L_8003E3D8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8003E3D0: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8003E3D8;
    }
    // 0x8003E3D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8003E3D4: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
L_8003E3D8:
    // 0x8003E3D8: lb          $t6, 0x174($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X174);
    // 0x8003E3DC: nop

    // 0x8003E3E0: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8003E3E4: bne         $at, $zero, L_8003E3F4
    if (ctx->r1 != 0) {
        // 0x8003E3E8: nop
    
            goto L_8003E3F4;
    }
    // 0x8003E3E8: nop

    // 0x8003E3EC: sb          $a0, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r4;
    // 0x8003E3F0: sb          $a0, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r4;
L_8003E3F4:
    // 0x8003E3F4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8003E3F8: jal         0x8001E29C
    // 0x8003E3FC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8003E3FC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_3:
    // 0x8003E400: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E404: nop

    // 0x8003E408: lb          $t7, 0x172($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X172);
    // 0x8003E40C: lb          $t8, 0x174($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X174);
    // 0x8003E410: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8003E414: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8003E418: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8003E41C: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8003E420: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8003E424: lbu         $t4, 0x209($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X209);
    // 0x8003E428: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8003E42C: lb          $t3, 0x1($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X1);
    // 0x8003E430: lb          $a2, 0x173($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X173);
    // 0x8003E434: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x8003E438: sb          $t5, 0x209($v1)
    MEM_B(0X209, ctx->r3) = ctx->r13;
    // 0x8003E43C: sb          $t3, 0x173($v1)
    MEM_B(0X173, ctx->r3) = ctx->r11;
    // 0x8003E440: jal         0x8009C3C8
    // 0x8003E444: sb          $a2, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r6;
    get_number_of_active_players(rdram, ctx);
        goto after_4;
    // 0x8003E444: sb          $a2, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r6;
    after_4:
    // 0x8003E448: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E44C: lb          $a2, 0x2E($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X2E);
    // 0x8003E450: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8003E454: beq         $at, $zero, L_8003E460
    if (ctx->r1 == 0) {
        // 0x8003E458: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_8003E460;
    }
    // 0x8003E458: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8003E45C: sw          $t6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r14;
L_8003E460:
    // 0x8003E460: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x8003E464: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003E468: bne         $a3, $at, L_8003E494
    if (ctx->r7 != ctx->r1) {
        // 0x8003E46C: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8003E494;
    }
    // 0x8003E46C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003E470: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003E474: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003E478: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003E47C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8003E480: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003E484: jal         0x80009558
    // 0x8003E488: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_5;
    // 0x8003E488: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x8003E48C: b           L_8003E584
    // 0x8003E490: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
        goto L_8003E584;
    // 0x8003E490: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E494:
    // 0x8003E494: lb          $v0, 0x174($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X174);
    // 0x8003E498: lb          $t8, 0x2D($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X2D);
    // 0x8003E49C: nop

    // 0x8003E4A0: bne         $t8, $v0, L_8003E534
    if (ctx->r24 != ctx->r2) {
        // 0x8003E4A4: nop
    
            goto L_8003E534;
    }
    // 0x8003E4A4: nop

    // 0x8003E4A8: lb          $t9, 0x1D8($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X1D8);
    // 0x8003E4AC: nop

    // 0x8003E4B0: bne         $t9, $zero, L_8003E584
    if (ctx->r25 != 0) {
        // 0x8003E4B4: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8003E584;
    }
    // 0x8003E4B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003E4B8: lb          $t0, 0x173($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X173);
    // 0x8003E4BC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003E4C0: beq         $a2, $t0, L_8003E514
    if (ctx->r6 == ctx->r8) {
        // 0x8003E4C4: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8003E514;
    }
    // 0x8003E4C4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8003E4C8: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    // 0x8003E4CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8003E4D0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8003E4D4: jal         0x800A7484
    // 0x8003E4D8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    hud_sound_play_delayed(rdram, ctx);
        goto after_6;
    // 0x8003E4D8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_6:
    // 0x8003E4DC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E4E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003E4E4: lb          $a2, 0x174($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X174);
    // 0x8003E4E8: nop

    // 0x8003E4EC: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x8003E4F0: bne         $at, $zero, L_8003E500
    if (ctx->r1 != 0) {
        // 0x8003E4F4: addiu       $a0, $a2, 0xA0
        ctx->r4 = ADD32(ctx->r6, 0XA0);
            goto L_8003E500;
    }
    // 0x8003E4F4: addiu       $a0, $a2, 0xA0
    ctx->r4 = ADD32(ctx->r6, 0XA0);
    // 0x8003E4F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8003E4FC: addiu       $a0, $a2, 0xA0
    ctx->r4 = ADD32(ctx->r6, 0XA0);
L_8003E500:
    // 0x8003E500: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8003E504: jal         0x80001D04
    // 0x8003E508: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x8003E508: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_7:
    // 0x8003E50C: b           L_8003E584
    // 0x8003E510: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
        goto L_8003E584;
    // 0x8003E510: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E514:
    // 0x8003E514: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003E518: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003E51C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003E520: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003E524: jal         0x80009558
    // 0x8003E528: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_8;
    // 0x8003E528: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_8:
    // 0x8003E52C: b           L_8003E584
    // 0x8003E530: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
        goto L_8003E584;
    // 0x8003E530: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E534:
    // 0x8003E534: lb          $t3, 0x1D8($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X1D8);
    // 0x8003E538: nop

    // 0x8003E53C: bne         $t3, $zero, L_8003E584
    if (ctx->r11 != 0) {
        // 0x8003E540: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8003E584;
    }
    // 0x8003E540: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003E544: blez        $v0, L_8003E56C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003E548: addiu       $a0, $zero, 0x13E
        ctx->r4 = ADD32(0, 0X13E);
            goto L_8003E56C;
    }
    // 0x8003E548: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    // 0x8003E54C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8003E550: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8003E554: jal         0x800A7484
    // 0x8003E558: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    hud_sound_play_delayed(rdram, ctx);
        goto after_9;
    // 0x8003E558: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_9:
    // 0x8003E55C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8003E560: nop

    // 0x8003E564: lb          $v0, 0x174($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X174);
    // 0x8003E568: nop

L_8003E56C:
    // 0x8003E56C: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    // 0x8003E570: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x8003E574: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8003E578: jal         0x80001D04
    // 0x8003E57C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8003E57C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8003E580: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8003E584:
    // 0x8003E584: sw          $t5, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r13;
    // 0x8003E588: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003E58C: jal         0x800AFC3C
    // 0x8003E590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_11;
    // 0x8003E590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8003E594: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8003E598: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x8003E59C: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
L_8003E5A0:
    // 0x8003E5A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003E5A4:
    // 0x8003E5A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003E5A8: jr          $ra
    // 0x8003E5AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8003E5AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void set_game_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DA1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA20: jr          $ra
    // 0x8006DA24: sw          $a0, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = ctx->r4;
    return;
    // 0x8006DA24: sw          $a0, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void hud_main_treasure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1248: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A124C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A1250: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800A1254: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800A1258: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800A125C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800A1260: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A1264: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A1268: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800A126C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800A1270: lw          $a3, 0x64($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X64);
    // 0x800A1274: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A1278: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800A127C: jal         0x8001BA74
    // 0x800A1280: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800A1280: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A1284: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800A1288: jal         0x80068508
    // 0x800A128C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A128C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800A1290: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800A1294: jal         0x800A3CE4
    // 0x800A1298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    hud_race_start(rdram, ctx);
        goto after_2;
    // 0x800A1298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A129C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A12A0: lbu         $v0, 0x6D37($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6D37);
    // 0x800A12A4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800A12A8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800A12AC: beq         $v0, $s3, L_800A12CC
    if (ctx->r2 == ctx->r19) {
        // 0x800A12B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A12CC;
    }
    // 0x800A12B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A12B4: beq         $v0, $at, L_800A13BC
    if (ctx->r2 == ctx->r1) {
        // 0x800A12B8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A13BC;
    }
    // 0x800A12B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A12BC: beq         $v0, $at, L_800A13BC
    if (ctx->r2 == ctx->r1) {
        // 0x800A12C0: nop
    
            goto L_800A13BC;
    }
    // 0x800A12C0: nop

    // 0x800A12C4: b           L_800A13C8
    // 0x800A12C8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
        goto L_800A13C8;
    // 0x800A12C8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_800A12CC:
    // 0x800A12CC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A12D0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A12D4: blez        $t7, L_800A137C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A12D8: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800A137C;
    }
    // 0x800A12D8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800A12DC: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A12E0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A12E4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A12E8: addiu       $s2, $s2, 0x6CDC
    ctx->r18 = ADD32(ctx->r18, 0X6CDC);
L_800A12EC:
    // 0x800A12EC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A12F0: nop

    // 0x800A12F4: lw          $a0, 0x64($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X64);
    // 0x800A12F8: jal         0x800A45F0
    // 0x800A12FC: nop

    hud_treasure(rdram, ctx);
        goto after_3;
    // 0x800A12FC: nop

    after_3:
    // 0x800A1300: bne         $s1, $s3, L_800A1338
    if (ctx->r17 != ctx->r19) {
        // 0x800A1304: nop
    
            goto L_800A1338;
    }
    // 0x800A1304: nop

    // 0x800A1308: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A130C: nop

    // 0x800A1310: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1314: nop

    // 0x800A1318: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A131C: swc1        $f6, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f6.u32l;
    // 0x800A1320: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1324: nop

    // 0x800A1328: lwc1        $f8, 0x40C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A132C: nop

    // 0x800A1330: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A1334: swc1        $f10, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f10.u32l;
L_800A1338:
    // 0x800A1338: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A133C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A1340: lwc1        $f16, 0x64C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1344: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A1348: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x800A134C: swc1        $f18, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f18.u32l;
    // 0x800A1350: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1354: nop

    // 0x800A1358: lwc1        $f4, 0x40C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A135C: nop

    // 0x800A1360: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A1364: swc1        $f6, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f6.u32l;
    // 0x800A1368: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800A136C: nop

    // 0x800A1370: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A1374: bne         $at, $zero, L_800A12EC
    if (ctx->r1 != 0) {
        // 0x800A1378: nop
    
            goto L_800A12EC;
    }
    // 0x800A1378: nop

L_800A137C:
    // 0x800A137C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A1380: addiu       $s2, $s2, 0x6CDC
    ctx->r18 = ADD32(ctx->r18, 0X6CDC);
    // 0x800A1384: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1388: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A138C: lwc1        $f0, -0x78E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78E8);
    // 0x800A1390: lwc1        $f8, 0x64C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1394: nop

    // 0x800A1398: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A139C: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A13A0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A13A4: nop

    // 0x800A13A8: lwc1        $f16, 0x40C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A13AC: nop

    // 0x800A13B0: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800A13B4: b           L_800A13C4
    // 0x800A13B8: swc1        $f18, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f18.u32l;
        goto L_800A13C4;
    // 0x800A13B8: swc1        $f18, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f18.u32l;
L_800A13BC:
    // 0x800A13BC: jal         0x800A45F0
    // 0x800A13C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_treasure(rdram, ctx);
        goto after_4;
    // 0x800A13C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
L_800A13C4:
    // 0x800A13C4: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_800A13C8:
    // 0x800A13C8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A13CC: lw          $a3, 0x64($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X64);
    // 0x800A13D0: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A13D4: jal         0x8007B3D0
    // 0x800A13D8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x800A13D8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A13DC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A13E0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800A13E4: jal         0x800A4154
    // 0x800A13E8: nop

    hud_bananas(rdram, ctx);
        goto after_6;
    // 0x800A13E8: nop

    after_6:
    // 0x800A13EC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800A13F0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800A13F4: jal         0x800A7520
    // 0x800A13F8: nop

    hud_weapon(rdram, ctx);
        goto after_7;
    // 0x800A13F8: nop

    after_7:
    // 0x800A13FC: jal         0x80068508
    // 0x800A1400: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_8;
    // 0x800A1400: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A1404: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1408: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800A140C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A1410: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1414: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800A1418: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800A141C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800A1420: jr          $ra
    // 0x800A1424: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800A1424: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void video_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A310: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007A314: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8007A318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A31C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007A324: bne         $v0, $zero, L_8007A35C
    if (ctx->r2 != 0) {
        // 0x8007A328: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8007A35C;
    }
    // 0x8007A328: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007A32C: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8007A330: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A334: sw          $t6, 0x6170($at)
    MEM_W(0X6170, ctx->r1) = ctx->r14;
    // 0x8007A338: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A33C: lwc1        $f4, 0x7AFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7AFC);
    // 0x8007A340: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A344: swc1        $f4, 0x6174($at)
    MEM_W(0X6174, ctx->r1) = ctx->f4.u32l;
    // 0x8007A348: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A34C: lwc1        $f6, 0x7B00($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7B00);
    // 0x8007A350: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A354: b           L_8007A3C0
    // 0x8007A358: swc1        $f6, 0x6178($at)
    MEM_W(0X6178, ctx->r1) = ctx->f6.u32l;
        goto L_8007A3C0;
    // 0x8007A358: swc1        $f6, 0x6178($at)
    MEM_W(0X6178, ctx->r1) = ctx->f6.u32l;
L_8007A35C:
    // 0x8007A35C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007A360: bne         $v0, $at, L_8007A398
    if (ctx->r2 != ctx->r1) {
        // 0x8007A364: addiu       $t8, $zero, 0x3C
        ctx->r24 = ADD32(0, 0X3C);
            goto L_8007A398;
    }
    // 0x8007A364: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8007A368: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8007A36C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A370: sw          $t7, 0x6170($at)
    MEM_W(0X6170, ctx->r1) = ctx->r15;
    // 0x8007A374: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A378: lwc1        $f8, 0x7B04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7B04);
    // 0x8007A37C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A380: swc1        $f8, 0x6174($at)
    MEM_W(0X6174, ctx->r1) = ctx->f8.u32l;
    // 0x8007A384: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A388: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007A38C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A390: b           L_8007A3C0
    // 0x8007A394: swc1        $f10, 0x6178($at)
    MEM_W(0X6178, ctx->r1) = ctx->f10.u32l;
        goto L_8007A3C0;
    // 0x8007A394: swc1        $f10, 0x6178($at)
    MEM_W(0X6178, ctx->r1) = ctx->f10.u32l;
L_8007A398:
    // 0x8007A398: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A39C: sw          $t8, 0x6170($at)
    MEM_W(0X6170, ctx->r1) = ctx->r24;
    // 0x8007A3A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A3A4: lwc1        $f16, 0x7B08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7B08);
    // 0x8007A3A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A3AC: swc1        $f16, 0x6174($at)
    MEM_W(0X6174, ctx->r1) = ctx->f16.u32l;
    // 0x8007A3B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007A3B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007A3B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A3BC: swc1        $f18, 0x6178($at)
    MEM_W(0X6178, ctx->r1) = ctx->f18.u32l;
L_8007A3C0:
    // 0x8007A3C0: bne         $v0, $zero, L_8007A40C
    if (ctx->r2 != 0) {
        // 0x8007A3C4: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8007A40C;
    }
    // 0x8007A3C4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007A3C8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007A3CC: addiu       $v0, $v0, -0x1884
    ctx->r2 = ADD32(ctx->r2, -0X1884);
    // 0x8007A3D0: addiu       $v1, $v1, -0x1844
    ctx->r3 = ADD32(ctx->r3, -0X1844);
L_8007A3D4:
    // 0x8007A3D4: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x8007A3D8: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8007A3DC: lw          $t5, 0x1C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C);
    // 0x8007A3E0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8007A3E4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8007A3E8: addiu       $t2, $t1, 0x18
    ctx->r10 = ADD32(ctx->r9, 0X18);
    // 0x8007A3EC: addiu       $t4, $t3, 0x18
    ctx->r12 = ADD32(ctx->r11, 0X18);
    // 0x8007A3F0: addiu       $t6, $t5, 0x18
    ctx->r14 = ADD32(ctx->r13, 0X18);
    // 0x8007A3F4: addiu       $t0, $t9, 0x18
    ctx->r8 = ADD32(ctx->r25, 0X18);
    // 0x8007A3F8: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8007A3FC: sw          $t4, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r12;
    // 0x8007A400: sw          $t2, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->r10;
    // 0x8007A404: bne         $v0, $v1, L_8007A3D4
    if (ctx->r2 != ctx->r3) {
        // 0x8007A408: sw          $t0, -0x1C($v0)
        MEM_W(-0X1C, ctx->r2) = ctx->r8;
            goto L_8007A3D4;
    }
    // 0x8007A408: sw          $t0, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->r8;
L_8007A40C:
    // 0x8007A40C: jal         0x8007A974
    // 0x8007A410: nop

    video_delta_reset(rdram, ctx);
        goto after_0;
    // 0x8007A410: nop

    after_0:
    // 0x8007A414: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007A418: jal         0x8007A4C0
    // 0x8007A41C: nop

    fb_mode_set(rdram, ctx);
        goto after_1;
    // 0x8007A41C: nop

    after_1:
    // 0x8007A420: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007A424: addiu       $v0, $v0, 0x62C0
    ctx->r2 = ADD32(ctx->r2, 0X62C0);
    // 0x8007A428: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8007A42C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007A430: jal         0x8007A7E8
    // 0x8007A434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    fb_alloc(rdram, ctx);
        goto after_2;
    // 0x8007A434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8007A438: jal         0x8007A7E8
    // 0x8007A43C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    fb_alloc(rdram, ctx);
        goto after_3;
    // 0x8007A43C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8007A440: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007A444: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A448: jal         0x8007AB9C
    // 0x8007A44C: sw          $t7, 0x62C8($at)
    MEM_W(0X62C8, ctx->r1) = ctx->r15;
    fb_swap(rdram, ctx);
        goto after_4;
    // 0x8007A44C: sw          $t7, 0x62C8($at)
    MEM_W(0X62C8, ctx->r1) = ctx->r15;
    after_4:
    // 0x8007A450: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007A454: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A458: addiu       $a1, $a1, 0x6180
    ctx->r5 = ADD32(ctx->r5, 0X6180);
    // 0x8007A45C: addiu       $a0, $a0, 0x61A0
    ctx->r4 = ADD32(ctx->r4, 0X61A0);
    // 0x8007A460: jal         0x800C8820
    // 0x8007A464: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x8007A464: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x8007A468: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A46C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A470: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007A474: addiu       $a2, $a2, 0x61A0
    ctx->r6 = ADD32(ctx->r6, 0X61A0);
    // 0x8007A478: addiu       $a1, $a1, 0x6310
    ctx->r5 = ADD32(ctx->r5, 0X6310);
    // 0x8007A47C: jal         0x80079480
    // 0x8007A480: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    osScAddClient(rdram, ctx);
        goto after_6;
    // 0x8007A480: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_6:
    // 0x8007A484: jal         0x8007A550
    // 0x8007A488: nop

    fb_init_vi(rdram, ctx);
        goto after_7;
    // 0x8007A488: nop

    after_7:
    // 0x8007A48C: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8007A490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A494: sw          $t8, 0x62D0($at)
    MEM_W(0X62D0, ctx->r1) = ctx->r24;
    // 0x8007A498: jal         0x800D1D10
    // 0x8007A49C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_8;
    // 0x8007A49C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x8007A4A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A4A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A4A8: sb          $zero, 0x6308($at)
    MEM_B(0X6308, ctx->r1) = 0;
    // 0x8007A4AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A4B0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8007A4B4: sb          $t9, 0x62E4($at)
    MEM_B(0X62E4, ctx->r1) = ctx->r25;
    // 0x8007A4B8: jr          $ra
    // 0x8007A4BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007A4BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void cinematic_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ABD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009ABDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009ABE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009ABE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009ABE8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8009ABEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8009ABF0: blez        $a1, L_8009AC24
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8009ABF4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8009AC24;
    }
    // 0x8009ABF4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009ABF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009ABFC:
    // 0x8009ABFC: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x8009AC00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009AC04: beq         $v0, $t6, L_8009AC1C
    if (ctx->r2 == ctx->r14) {
        // 0x8009AC08: nop
    
            goto L_8009AC1C;
    }
    // 0x8009AC08: nop

L_8009AC0C:
    // 0x8009AC0C: lb          $t7, 0x3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X3);
    // 0x8009AC10: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x8009AC14: bne         $v0, $t7, L_8009AC0C
    if (ctx->r2 != ctx->r15) {
        // 0x8009AC18: nop
    
            goto L_8009AC0C;
    }
    // 0x8009AC18: nop

L_8009AC1C:
    // 0x8009AC1C: bne         $v1, $a1, L_8009ABFC
    if (ctx->r3 != ctx->r5) {
        // 0x8009AC20: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8009ABFC;
    }
    // 0x8009AC20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8009AC24:
    // 0x8009AC24: bne         $v1, $zero, L_8009AC48
    if (ctx->r3 != 0) {
        // 0x8009AC28: nop
    
            goto L_8009AC48;
    }
    // 0x8009AC28: nop

    // 0x8009AC2C: jal         0x8001E29C
    // 0x8009AC30: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8009AC30: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_0:
    // 0x8009AC34: bne         $v0, $s0, L_8009AC48
    if (ctx->r2 != ctx->r16) {
        // 0x8009AC38: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8009AC48;
    }
    // 0x8009AC38: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009AC3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AC40: b           L_8009AC50
    // 0x8009AC44: sw          $t8, 0x684C($at)
    MEM_W(0X684C, ctx->r1) = ctx->r24;
        goto L_8009AC50;
    // 0x8009AC44: sw          $t8, 0x684C($at)
    MEM_W(0X684C, ctx->r1) = ctx->r24;
L_8009AC48:
    // 0x8009AC48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AC4C: sw          $zero, 0x684C($at)
    MEM_W(0X684C, ctx->r1) = 0;
L_8009AC50:
    // 0x8009AC50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AC54: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009AC58: sw          $s0, 0x67EC($at)
    MEM_W(0X67EC, ctx->r1) = ctx->r16;
    // 0x8009AC5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AC60: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8009AC64: sw          $t9, 0x6824($at)
    MEM_W(0X6824, ctx->r1) = ctx->r25;
    // 0x8009AC68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AC6C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8009AC70: sw          $t0, 0x683C($at)
    MEM_W(0X683C, ctx->r1) = ctx->r8;
    // 0x8009AC74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AC78: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8009AC7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009AC80: sw          $t1, 0x6844($at)
    MEM_W(0X6844, ctx->r1) = ctx->r9;
    // 0x8009AC84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AC88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009AC8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009AC90: jr          $ra
    // 0x8009AC94: sw          $t2, 0x6804($at)
    MEM_W(0X6804, ctx->r1) = ctx->r10;
    return;
    // 0x8009AC94: sw          $t2, 0x6804($at)
    MEM_W(0X6804, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void alMainBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC390: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CC394: bne         $a1, $at, L_800CC3B8
    if (ctx->r5 != ctx->r1) {
        // 0x800CC398: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_800CC3B8;
    }
    // 0x800CC398: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800CC39C: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800CC3A0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CC3A4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800CC3A8: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800CC3AC: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800CC3B0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CC3B4: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800CC3B8:
    // 0x800CC3B8: jr          $ra
    // 0x800CC3BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CC3BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void obj_init_setuppoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039190: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80039194: nop

    // 0x80039198: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x8003919C: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x800391A0: nop

    // 0x800391A4: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    // 0x800391A8: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800391AC: nop

    // 0x800391B0: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x800391B4: jr          $ra
    // 0x800391B8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    return;
    // 0x800391B8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void func_800159C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800159C8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800159CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800159D0: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800159D4: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800159D8: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800159DC: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800159E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800159E4: sub.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800159E8: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800159EC: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800159F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800159F4: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800159F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800159FC: lwc1        $f10, -0x5258($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5258);
    // 0x80015A00: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80015A04: lw          $a2, 0x4C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4C);
    // 0x80015A08: div.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80015A0C: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80015A10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015A14: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80015A18: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x80015A1C: lbu         $v0, 0x11($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X11);
    // 0x80015A20: nop

    // 0x80015A24: bne         $t1, $v0, L_80015A90
    if (ctx->r9 != ctx->r2) {
        // 0x80015A28: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80015A90;
    }
    // 0x80015A28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80015A2C: lb          $t9, 0x16($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X16);
    // 0x80015A30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80015A34: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80015A38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80015A3C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015A40: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80015A44: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80015A48: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80015A4C: nop

    // 0x80015A50: bc1t        L_800164F4
    if (c1cs) {
        // 0x80015A54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80015A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015A58: lb          $t2, 0x17($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X17);
    // 0x80015A5C: nop

    // 0x80015A60: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80015A64: nop

    // 0x80015A68: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80015A6C: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80015A70: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80015A74: nop

    // 0x80015A78: bc1t        L_800164F4
    if (c1cs) {
        // 0x80015A7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80015A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015A80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80015A84: nop

    // 0x80015A88: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80015A8C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80015A90:
    // 0x80015A90: bne         $v0, $at, L_80015AC4
    if (ctx->r2 != ctx->r1) {
        // 0x80015A94: nop
    
            goto L_80015AC4;
    }
    // 0x80015A94: nop

    // 0x80015A98: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015A9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015AA0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80015AA4: nop

    // 0x80015AA8: bc1f        L_80015AC4
    if (!c1cs) {
        // 0x80015AAC: nop
    
            goto L_80015AC4;
    }
    // 0x80015AAC: nop

    // 0x80015AB0: lwc1        $f9, 0x55B8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X55B8);
    // 0x80015AB4: lwc1        $f8, 0x55BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X55BC);
    // 0x80015AB8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80015ABC: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80015AC0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80015AC4:
    // 0x80015AC4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80015AC8: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80015ACC: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80015AD0: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80015AD4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80015AD8: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80015ADC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80015AE0: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80015AE4: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015AE8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80015AEC: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80015AF0: jal         0x800C9AD0
    // 0x80015AF4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80015AF4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80015AF8: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80015AFC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80015B00: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80015B04: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80015B08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015B0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80015B10: lh          $t6, 0x14($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X14);
    // 0x80015B14: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80015B18: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80015B1C: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80015B20: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80015B24: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80015B28: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80015B2C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015B30: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80015B34: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x80015B38: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80015B3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015B40: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80015B44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80015B48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80015B4C: nop

    // 0x80015B50: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80015B54: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80015B58: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80015B5C: beq         $t7, $zero, L_80015B68
    if (ctx->r15 == 0) {
        // 0x80015B60: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80015B68;
    }
    // 0x80015B60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015B64: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
L_80015B68:
    // 0x80015B68: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80015B6C: bne         $at, $zero, L_80015B78
    if (ctx->r1 != 0) {
        // 0x80015B70: nop
    
            goto L_80015B78;
    }
    // 0x80015B70: nop

    // 0x80015B74: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80015B78:
    // 0x80015B78: lbu         $t8, 0x13($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X13);
    // 0x80015B7C: nop

    // 0x80015B80: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015B84: bne         $at, $zero, L_80015B94
    if (ctx->r1 != 0) {
        // 0x80015B88: nop
    
            goto L_80015B94;
    }
    // 0x80015B88: nop

    // 0x80015B8C: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x80015B90: sb          $v0, 0x13($t0)
    MEM_B(0X13, ctx->r8) = ctx->r2;
L_80015B94:
    // 0x80015B94: lh          $a1, 0x14($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X14);
    // 0x80015B98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015B9C: andi        $t9, $a1, 0x20
    ctx->r25 = ctx->r5 & 0X20;
    // 0x80015BA0: beq         $t9, $zero, L_80015BB0
    if (ctx->r25 == 0) {
        // 0x80015BA4: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_80015BB0;
    }
    // 0x80015BA4: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80015BA8: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80015BAC: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
L_80015BB0:
    // 0x80015BB0: bne         $at, $zero, L_80015BBC
    if (ctx->r1 != 0) {
        // 0x80015BB4: nop
    
            goto L_80015BBC;
    }
    // 0x80015BB4: nop

    // 0x80015BB8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80015BBC:
    // 0x80015BBC: lbu         $t2, 0x13($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X13);
    // 0x80015BC0: nop

    // 0x80015BC4: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015BC8: bne         $at, $zero, L_80015BE0
    if (ctx->r1 != 0) {
        // 0x80015BCC: andi        $t4, $a1, 0x1
        ctx->r12 = ctx->r5 & 0X1;
            goto L_80015BE0;
    }
    // 0x80015BCC: andi        $t4, $a1, 0x1
    ctx->r12 = ctx->r5 & 0X1;
    // 0x80015BD0: lh          $a1, 0x14($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X14);
    // 0x80015BD4: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x80015BD8: sb          $v0, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r2;
    // 0x80015BDC: andi        $t4, $a1, 0x1
    ctx->r12 = ctx->r5 & 0X1;
L_80015BE0:
    // 0x80015BE0: beq         $t4, $zero, L_800164F4
    if (ctx->r12 == 0) {
        // 0x80015BE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80015BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015BE8: lb          $t3, 0x10($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X10);
    // 0x80015BEC: lb          $t5, 0x10($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X10);
    // 0x80015BF0: nop

    // 0x80015BF4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80015BF8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80015BFC: nop

    // 0x80015C00: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80015C04: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x80015C08: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80015C0C: nop

    // 0x80015C10: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80015C14: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80015C18: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80015C1C: nop

    // 0x80015C20: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80015C24: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x80015C28: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80015C2C: nop

    // 0x80015C30: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80015C34: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80015C38: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80015C3C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80015C40: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80015C44: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80015C48: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80015C4C: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80015C50: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80015C54: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80015C58: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x80015C5C: lbu         $t7, 0x11($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X11);
    // 0x80015C60: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80015C64: bne         $t1, $t7, L_80015C74
    if (ctx->r9 != ctx->r15) {
        // 0x80015C68: nop
    
            goto L_80015C74;
    }
    // 0x80015C68: nop

    // 0x80015C6C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80015C70: nop

L_80015C74:
    // 0x80015C74: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80015C78: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80015C7C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80015C80: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80015C84: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80015C88: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80015C8C: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80015C90: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015C94: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x80015C98: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80015C9C: nop

    // 0x80015CA0: bc1f        L_80015DDC
    if (!c1cs) {
        // 0x80015CA4: nop
    
            goto L_80015DDC;
    }
    // 0x80015CA4: nop

    // 0x80015CA8: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80015CAC: lwc1        $f18, 0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80015CB0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80015CB4: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80015CB8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80015CBC: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80015CC0: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80015CC4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80015CC8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80015CCC: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80015CD0: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80015CD4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80015CD8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80015CDC: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80015CE0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80015CE4: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80015CE8: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80015CEC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80015CF0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80015CF4: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80015CF8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80015CFC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80015D00: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80015D04: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80015D08: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80015D0C: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80015D10: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80015D14: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80015D18: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80015D1C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015D20: div.s       $f2, $f4, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80015D24: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x80015D28: nop

    // 0x80015D2C: bc1f        L_80015DDC
    if (!c1cs) {
        // 0x80015D30: nop
    
            goto L_80015DDC;
    }
    // 0x80015D30: nop

    // 0x80015D34: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80015D38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80015D3C: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80015D40: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x80015D44: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80015D48: bc1f        L_80015DDC
    if (!c1cs) {
        // 0x80015D4C: swc1        $f12, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->f12.u32l;
            goto L_80015DDC;
    }
    // 0x80015D4C: swc1        $f12, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f12.u32l;
    // 0x80015D50: mul.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80015D54: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80015D58: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80015D5C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80015D60: mul.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80015D64: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80015D68: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80015D6C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x80015D70: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80015D74: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80015D78: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80015D7C: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80015D80: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80015D84: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80015D88: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80015D8C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80015D90: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80015D94: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80015D98: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80015D9C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80015DA0: sub.s       $f14, $f18, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80015DA4: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x80015DA8: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80015DAC: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015DB0: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80015DB4: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80015DB8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80015DBC: jal         0x800C9AD0
    // 0x80015DC0: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80015DC0: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_1:
    // 0x80015DC4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80015DC8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80015DCC: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80015DD0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80015DD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015DD8: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80015DDC:
    // 0x80015DDC: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80015DE0: nop

    // 0x80015DE4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80015DE8: nop

    // 0x80015DEC: bc1f        L_800164F4
    if (!c1cs) {
        // 0x80015DF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80015DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015DF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80015DF8: nop

    // 0x80015DFC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80015E00: nop

    // 0x80015E04: bc1f        L_800164F4
    if (!c1cs) {
        // 0x80015E08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80015E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015E0C: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80015E10: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80015E14: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80015E18: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80015E1C: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80015E20: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80015E24: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80015E28: lbu         $t8, 0x11($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X11);
    // 0x80015E2C: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80015E30: bne         $t1, $t8, L_80015E40
    if (ctx->r9 != ctx->r24) {
        // 0x80015E34: sub.s       $f14, $f10, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
            goto L_80015E40;
    }
    // 0x80015E34: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80015E38: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80015E3C: nop

L_80015E40:
    // 0x80015E40: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80015E44: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80015E48: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80015E4C: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80015E50: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80015E54: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80015E58: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x80015E5C: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    // 0x80015E60: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80015E64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80015E68: swc1        $f16, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f16.u32l;
    // 0x80015E6C: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x80015E70: jal         0x800C9AD0
    // 0x80015E74: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80015E74: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_2:
    // 0x80015E78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015E7C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80015E80: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80015E84: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80015E88: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80015E8C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80015E90: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80015E94: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80015E98: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80015E9C: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80015EA0: bc1f        L_80015EC8
    if (!c1cs) {
        // 0x80015EA4: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80015EC8;
    }
    // 0x80015EA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80015EA8: nop

    // 0x80015EAC: div.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80015EB0: nop

    // 0x80015EB4: div.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80015EB8: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x80015EBC: div.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80015EC0: b           L_80015EEC
    // 0x80015EC4: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
        goto L_80015EEC;
    // 0x80015EC4: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
L_80015EC8:
    // 0x80015EC8: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80015ECC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80015ED0: div.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80015ED4: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015ED8: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80015EDC: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80015EE0: div.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80015EE4: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x80015EE8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
L_80015EEC:
    // 0x80015EEC: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80015EF0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80015EF4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80015EF8: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80015EFC: nop

    // 0x80015F00: bc1f        L_80015F0C
    if (!c1cs) {
        // 0x80015F04: nop
    
            goto L_80015F0C;
    }
    // 0x80015F04: nop

    // 0x80015F08: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
L_80015F0C:
    // 0x80015F0C: mul.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80015F10: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80015F14: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015F18: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80015F1C: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80015F20: nop

    // 0x80015F24: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80015F28: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x80015F2C: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80015F30: lh          $t9, 0x14($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X14);
    // 0x80015F34: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80015F38: ori         $t2, $t9, 0x8
    ctx->r10 = ctx->r25 | 0X8;
    // 0x80015F3C: sh          $t2, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r10;
    // 0x80015F40: lh          $t4, 0x14($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X14);
    // 0x80015F44: lbu         $t5, 0x12($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X12);
    // 0x80015F48: ori         $t3, $t4, 0x8
    ctx->r11 = ctx->r12 | 0X8;
    // 0x80015F4C: bne         $t5, $zero, L_80016268
    if (ctx->r13 != 0) {
        // 0x80015F50: sh          $t3, 0x14($a2)
        MEM_H(0X14, ctx->r6) = ctx->r11;
            goto L_80016268;
    }
    // 0x80015F50: sh          $t3, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r11;
    // 0x80015F54: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80015F58: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80015F5C: sub.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80015F60: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80015F64: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80015F68: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80015F6C: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80015F70: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80015F74: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015F78: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80015F7C: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80015F80: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x80015F84: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80015F88: nop

    // 0x80015F8C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80015F90: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x80015F94: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80015F98: nop

    // 0x80015F9C: bne         $t1, $t6, L_800164F4
    if (ctx->r9 != ctx->r14) {
        // 0x80015FA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80015FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015FA4: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x80015FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80015FAC: lb          $t7, 0x1D6($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1D6);
    // 0x80015FB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015FB4: bne         $t1, $t7, L_8001611C
    if (ctx->r9 != ctx->r15) {
        // 0x80015FB8: nop
    
            goto L_8001611C;
    }
    // 0x80015FB8: nop

    // 0x80015FBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015FC0: lwc1        $f7, 0x55C0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X55C0);
    // 0x80015FC4: lwc1        $f6, 0x55C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X55C4);
    // 0x80015FC8: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80015FCC: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80015FD0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80015FD4: bc1f        L_80016240
    if (!c1cs) {
        // 0x80015FD8: nop
    
            goto L_80016240;
    }
    // 0x80015FD8: nop

    // 0x80015FDC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80015FE0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80015FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015FE8: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x80015FEC: nop

    // 0x80015FF0: bc1f        L_80015FFC
    if (!c1cs) {
        // 0x80015FF4: nop
    
            goto L_80015FFC;
    }
    // 0x80015FF4: nop

    // 0x80015FF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80015FFC:
    // 0x80015FFC: beq         $v0, $zero, L_80016038
    if (ctx->r2 == 0) {
        // 0x80016000: nop
    
            goto L_80016038;
    }
    // 0x80016000: nop

    // 0x80016004: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80016008: lwc1        $f1, 0x55C8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X55C8);
    // 0x8001600C: lwc1        $f0, 0x55CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55CC);
    // 0x80016010: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80016014: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80016018: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8001601C: nop

    // 0x80016020: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80016024: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80016028: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x8001602C: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x80016030: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80016034: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
L_80016038:
    // 0x80016038: beq         $v0, $zero, L_80016240
    if (ctx->r2 == 0) {
        // 0x8001603C: nop
    
            goto L_80016240;
    }
    // 0x8001603C: nop

    // 0x80016040: lh          $t8, 0x14($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X14);
    // 0x80016044: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80016048: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x8001604C: sh          $t9, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r25;
    // 0x80016050: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80016054: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80016058: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001605C: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80016060: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80016064: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80016068: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001606C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80016070: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80016074: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80016078: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8001607C: sb          $t2, 0x1D2($a1)
    MEM_B(0X1D2, ctx->r5) = ctx->r10;
    // 0x80016080: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80016084: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016088: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8001608C: sub.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80016090: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x80016094: nop

    // 0x80016098: bc1f        L_800160E0
    if (!c1cs) {
        // 0x8001609C: nop
    
            goto L_800160E0;
    }
    // 0x8001609C: nop

    // 0x800160A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800160A4: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800160A8: lwc1        $f1, 0x55D0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X55D0);
    // 0x800160AC: lwc1        $f0, 0x55D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55D4);
    // 0x800160B0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800160B4: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x800160B8: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800160BC: swc1        $f8, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->f8.u32l;
    // 0x800160C0: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800160C4: nop

    // 0x800160C8: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800160CC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800160D0: mul.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800160D4: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800160D8: b           L_80016240
    // 0x800160DC: swc1        $f6, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f6.u32l;
        goto L_80016240;
    // 0x800160DC: swc1        $f6, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f6.u32l;
L_800160E0:
    // 0x800160E0: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800160E4: lwc1        $f1, 0x55D8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X55D8);
    // 0x800160E8: lwc1        $f0, 0x55DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55DC);
    // 0x800160EC: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800160F0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800160F4: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800160F8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800160FC: swc1        $f10, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->f10.u32l;
    // 0x80016100: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80016104: nop

    // 0x80016108: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8001610C: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80016110: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80016114: b           L_80016240
    // 0x80016118: swc1        $f10, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f10.u32l;
        goto L_80016240;
    // 0x80016118: swc1        $f10, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f10.u32l;
L_8001611C:
    // 0x8001611C: lwc1        $f5, 0x55E0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X55E0);
    // 0x80016120: lwc1        $f4, 0x55E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55E4);
    // 0x80016124: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80016128: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8001612C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80016130: bc1f        L_80016194
    if (!c1cs) {
        // 0x80016134: nop
    
            goto L_80016194;
    }
    // 0x80016134: nop

    // 0x80016138: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001613C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016140: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80016144: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80016148: nop

    // 0x8001614C: bc1f        L_80016158
    if (!c1cs) {
        // 0x80016150: nop
    
            goto L_80016158;
    }
    // 0x80016150: nop

    // 0x80016154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016158:
    // 0x80016158: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8001615C: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80016160: sub.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80016164: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80016168: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x8001616C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016170: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80016174: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80016178: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x8001617C: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x80016180: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80016184: nop

    // 0x80016188: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x8001618C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80016190: swc1        $f8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f8.u32l;
L_80016194:
    // 0x80016194: beq         $v0, $zero, L_80016240
    if (ctx->r2 == 0) {
        // 0x80016198: nop
    
            goto L_80016240;
    }
    // 0x80016198: nop

    // 0x8001619C: lh          $t4, 0x14($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X14);
    // 0x800161A0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800161A4: ori         $t3, $t4, 0x40
    ctx->r11 = ctx->r12 | 0X40;
    // 0x800161A8: sh          $t3, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r11;
    // 0x800161AC: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800161B0: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800161B4: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800161B8: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800161BC: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800161C0: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800161C4: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800161C8: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800161CC: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800161D0: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800161D4: nop

    // 0x800161D8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800161DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800161E0: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800161E4: sub.s       $f2, $f10, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800161E8: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x800161EC: nop

    // 0x800161F0: bc1f        L_80016208
    if (!c1cs) {
        // 0x800161F4: nop
    
            goto L_80016208;
    }
    // 0x800161F4: nop

    // 0x800161F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800161FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80016200: b           L_80016214
    // 0x80016204: lwc1        $f8, 0x50($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X50);
        goto L_80016214;
    // 0x80016204: lwc1        $f8, 0x50($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X50);
L_80016208:
    // 0x80016208: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001620C: nop

    // 0x80016210: lwc1        $f8, 0x50($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X50);
L_80016214:
    // 0x80016214: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80016218: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001621C: lwc1        $f4, 0x58($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X58);
    // 0x80016220: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80016224: sb          $t5, 0x1D2($a1)
    MEM_B(0X1D2, ctx->r5) = ctx->r13;
    // 0x80016228: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001622C: nop

    // 0x80016230: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80016234: swc1        $f10, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f10.u32l;
    // 0x80016238: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001623C: swc1        $f6, 0x120($a1)
    MEM_W(0X120, ctx->r5) = ctx->f6.u32l;
L_80016240:
    // 0x80016240: beq         $v0, $zero, L_800164F4
    if (ctx->r2 == 0) {
        // 0x80016244: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80016244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016248: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8001624C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80016250: beq         $t6, $at, L_800164F4
    if (ctx->r14 == ctx->r1) {
        // 0x80016254: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80016254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016258: jal         0x80016500
    // 0x8001625C: nop

    func_80016500(rdram, ctx);
        goto after_3;
    // 0x8001625C: nop

    after_3:
    // 0x80016260: b           L_800164F4
    // 0x80016264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800164F4;
    // 0x80016264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80016268:
    // 0x80016268: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8001626C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80016270: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80016274: mul.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x80016278: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001627C: nop

    // 0x80016280: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80016284: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016288: mul.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x8001628C: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80016290: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80016294: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80016298: mul.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x8001629C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800162A0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800162A4: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x800162A8: lbu         $t7, 0x12($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X12);
    // 0x800162AC: nop

    // 0x800162B0: beq         $t7, $zero, L_800162E8
    if (ctx->r15 == 0) {
        // 0x800162B4: nop
    
            goto L_800162E8;
    }
    // 0x800162B4: nop

    // 0x800162B8: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800162BC: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800162C0: sub.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800162C4: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x800162C8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800162CC: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800162D0: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800162D4: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x800162D8: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800162DC: nop

    // 0x800162E0: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800162E4: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
L_800162E8:
    // 0x800162E8: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800162EC: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800162F0: add.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800162F4: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x800162F8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800162FC: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80016300: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80016304: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
    // 0x80016308: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001630C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80016310: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80016314: swc1        $f4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f4.u32l;
    // 0x80016318: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001631C: nop

    // 0x80016320: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80016324: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x80016328: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    // 0x8001632C: nop

    // 0x80016330: bne         $t1, $t8, L_800164F4
    if (ctx->r9 != ctx->r24) {
        // 0x80016334: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80016334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016338: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x8001633C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80016340: bne         $t1, $t9, L_800164F4
    if (ctx->r9 != ctx->r25) {
        // 0x80016344: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80016344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016348: lbu         $t2, 0x12($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X12);
    // 0x8001634C: lbu         $t4, 0x12($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X12);
    // 0x80016350: lwc1        $f7, 0x55E8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X55E8);
    // 0x80016354: subu        $t3, $t2, $t4
    ctx->r11 = SUB32(ctx->r10, ctx->r12);
    // 0x80016358: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8001635C: lwc1        $f6, 0x55EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X55EC);
    // 0x80016360: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80016364: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x80016368: lw          $t5, 0x64($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X64);
    // 0x8001636C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80016370: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x80016374: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016378: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001637C: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x80016380: lb          $v0, 0x189($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X189);
    // 0x80016384: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80016388: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x8001638C: beq         $v0, $zero, L_800163A8
    if (ctx->r2 == 0) {
        // 0x80016390: cvt.s.d     $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
            goto L_800163A8;
    }
    // 0x80016390: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80016394: lb          $t7, 0x189($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X189);
    // 0x80016398: nop

    // 0x8001639C: bne         $t7, $zero, L_800163AC
    if (ctx->r15 != 0) {
        // 0x800163A0: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_800163AC;
    }
    // 0x800163A0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800163A4: sb          $v0, 0x1DB($t5)
    MEM_B(0X1DB, ctx->r13) = ctx->r2;
L_800163A8:
    // 0x800163A8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_800163AC:
    // 0x800163AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800163B0: lb          $v0, 0x189($t8)
    ctx->r2 = MEM_B(ctx->r24, 0X189);
    // 0x800163B4: nop

    // 0x800163B8: beq         $v0, $zero, L_800163D4
    if (ctx->r2 == 0) {
        // 0x800163BC: nop
    
            goto L_800163D4;
    }
    // 0x800163BC: nop

    // 0x800163C0: lb          $t9, 0x189($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X189);
    // 0x800163C4: nop

    // 0x800163C8: bne         $t9, $zero, L_800163D4
    if (ctx->r25 != 0) {
        // 0x800163CC: nop
    
            goto L_800163D4;
    }
    // 0x800163CC: nop

    // 0x800163D0: sb          $v0, 0x1DB($a1)
    MEM_B(0X1DB, ctx->r5) = ctx->r2;
L_800163D4:
    // 0x800163D4: lb          $t2, 0x1D6($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1D6);
    // 0x800163D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800163DC: bne         $t1, $t2, L_800163F0
    if (ctx->r9 != ctx->r10) {
        // 0x800163E0: nop
    
            goto L_800163F0;
    }
    // 0x800163E0: nop

    // 0x800163E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800163E8: b           L_8001643C
    // 0x800163EC: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
        goto L_8001643C;
    // 0x800163EC: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
L_800163F0:
    // 0x800163F0: lwc1        $f1, 0x55F0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X55F0);
    // 0x800163F4: lwc1        $f0, 0x55F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X55F4);
    // 0x800163F8: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800163FC: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80016400: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80016404: bc1f        L_8001643C
    if (!c1cs) {
        // 0x80016408: nop
    
            goto L_8001643C;
    }
    // 0x80016408: nop

    // 0x8001640C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80016414: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80016418: mul.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x8001641C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80016420: nop

    // 0x80016424: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80016428: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8001642C: mul.d       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x80016430: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x80016434: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80016438: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
L_8001643C:
    // 0x8001643C: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016440: beq         $v0, $zero, L_800164F4
    if (ctx->r2 == 0) {
        // 0x80016444: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800164F4;
    }
    // 0x80016444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016448: lbu         $t4, 0x12($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X12);
    // 0x8001644C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80016450: beq         $t4, $zero, L_800164B8
    if (ctx->r12 == 0) {
        // 0x80016454: nop
    
            goto L_800164B8;
    }
    // 0x80016454: nop

    // 0x80016458: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001645C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016460: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x80016464: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x80016468: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x8001646C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80016470: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80016474: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80016478: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001647C: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80016480: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80016484: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x80016488: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001648C: nop

    // 0x80016490: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80016494: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80016498: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8001649C: swc1        $f14, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f14.u32l;
    // 0x800164A0: jal         0x80016500
    // 0x800164A4: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    func_80016500(rdram, ctx);
        goto after_4;
    // 0x800164A4: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    after_4:
    // 0x800164A8: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x800164AC: lwc1        $f14, 0x90($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800164B0: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800164B4: nop

L_800164B8:
    // 0x800164B8: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800164BC: lwc1        $f4, 0x1C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x800164C0: lwc1        $f6, 0x24($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X24);
    // 0x800164C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800164C8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800164CC: swc1        $f10, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f10.u32l;
    // 0x800164D0: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800164D4: nop

    // 0x800164D8: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800164DC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800164E0: swc1        $f10, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f10.u32l;
    // 0x800164E4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800164E8: jal         0x80016500
    // 0x800164EC: nop

    func_80016500(rdram, ctx);
        goto after_5;
    // 0x800164EC: nop

    after_5:
    // 0x800164F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800164F4:
    // 0x800164F4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x800164F8: jr          $ra
    // 0x800164FC: nop

    return;
    // 0x800164FC: nop

;}
RECOMP_FUNC void render_3d_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800120C8: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800120CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800120D0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800120D4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800120D8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800120DC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800120E0: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x800120E4: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x800120E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800120EC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800120F0: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x800120F4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800120F8: beq         $s0, $zero, L_80012C14
    if (ctx->r16 == 0) {
        // 0x800120FC: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_80012C14;
    }
    // 0x800120FC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80012100: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80012104: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x80012108: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x8001210C: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    // 0x80012110: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x80012114: lw          $v1, 0x54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X54);
    // 0x80012118: nop

    // 0x8001211C: beq         $v1, $zero, L_8001217C
    if (ctx->r3 == 0) {
        // 0x80012120: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_8001217C;
    }
    // 0x80012120: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80012124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012128: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001212C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80012130: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80012134: addiu       $s1, $s1, -0x52D0
    ctx->r17 = ADD32(ctx->r17, -0X52D0);
    // 0x80012138: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8001213C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80012140: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80012144: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80012148: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
    // 0x8001214C: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    // 0x80012150: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80012154: nop

    // 0x80012158: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001215C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80012160: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80012164: nop

    // 0x80012168: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001216C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80012170: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80012174: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x80012178: nop

L_8001217C:
    // 0x8001217C: lh          $t7, 0x48($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X48);
    // 0x80012180: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80012184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012188: bne         $t7, $at, L_800121A4
    if (ctx->r15 != ctx->r1) {
        // 0x8001218C: addiu       $s1, $s1, -0x52D0
        ctx->r17 = ADD32(ctx->r17, -0X52D0);
            goto L_800121A4;
    }
    // 0x8001218C: addiu       $s1, $s1, -0x52D0
    ctx->r17 = ADD32(ctx->r17, -0X52D0);
    // 0x80012190: lw          $s3, 0x64($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X64);
    // 0x80012194: jal         0x80012E28
    // 0x80012198: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    object_do_player_tumble(rdram, ctx);
        goto after_0;
    // 0x80012198: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8001219C: b           L_800121AC
    // 0x800121A0: lb          $t6, 0x20($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X20);
        goto L_800121AC;
    // 0x800121A0: lb          $t6, 0x20($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X20);
L_800121A4:
    // 0x800121A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800121A8: lb          $t6, 0x20($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X20);
L_800121AC:
    // 0x800121AC: nop

    // 0x800121B0: bgtz        $t6, L_800122FC
    if (SIGNED(ctx->r14) > 0) {
        // 0x800121B4: nop
    
            goto L_800122FC;
    }
    // 0x800121B4: nop

    // 0x800121B8: lb          $t8, 0x1F($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1F);
    // 0x800121BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800121C0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800121C4: addu        $t5, $s0, $t9
    ctx->r13 = ADD32(ctx->r16, ctx->r25);
    // 0x800121C8: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x800121CC: nop

    // 0x800121D0: sw          $t7, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r15;
    // 0x800121D4: lb          $v1, 0x1E($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E);
    // 0x800121D8: nop

    // 0x800121DC: bne         $v1, $at, L_800121F4
    if (ctx->r3 != ctx->r1) {
        // 0x800121E0: nop
    
            goto L_800121F4;
    }
    // 0x800121E0: nop

    // 0x800121E4: jal         0x80061D30
    // 0x800121E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_animate(rdram, ctx);
        goto after_1;
    // 0x800121E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800121EC: lb          $v1, 0x1E($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E);
    // 0x800121F0: nop

L_800121F4:
    // 0x800121F4: beq         $v1, $zero, L_800122C4
    if (ctx->r3 == 0) {
        // 0x800121F8: nop
    
            goto L_800122C4;
    }
    // 0x800121F8: nop

    // 0x800121FC: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80012200: nop

    // 0x80012204: lw          $t8, 0x40($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X40);
    // 0x80012208: nop

    // 0x8001220C: beq         $t8, $zero, L_800122C4
    if (ctx->r24 == 0) {
        // 0x80012210: nop
    
            goto L_800122C4;
    }
    // 0x80012210: nop

    // 0x80012214: beq         $s3, $zero, L_80012244
    if (ctx->r19 == 0) {
        // 0x80012218: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80012244;
    }
    // 0x80012218: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001221C: lb          $t9, 0x1D6($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X1D6);
    // 0x80012220: nop

    // 0x80012224: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80012228: beq         $at, $zero, L_80012244
    if (ctx->r1 == 0) {
        // 0x8001222C: nop
    
            goto L_80012244;
    }
    // 0x8001222C: nop

    // 0x80012230: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x80012234: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012238: bne         $t5, $at, L_80012244
    if (ctx->r13 != ctx->r1) {
        // 0x8001223C: nop
    
            goto L_80012244;
    }
    // 0x8001223C: nop

    // 0x80012240: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80012244:
    // 0x80012244: jal         0x80066210
    // 0x80012248: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x80012248: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    after_2:
    // 0x8001224C: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80012250: beq         $v0, $zero, L_8001225C
    if (ctx->r2 == 0) {
        // 0x80012254: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_8001225C;
    }
    // 0x80012254: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80012258: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8001225C:
    // 0x8001225C: lb          $t7, 0x1F($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1F);
    // 0x80012260: lh          $t5, 0x48($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X48);
    // 0x80012264: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80012268: addu        $t8, $s0, $t6
    ctx->r24 = ADD32(ctx->r16, ctx->r14);
    // 0x8001226C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80012270: bne         $t5, $at, L_80012294
    if (ctx->r13 != ctx->r1) {
        // 0x80012274: sw          $t9, 0x44($s2)
        MEM_W(0X44, ctx->r18) = ctx->r25;
            goto L_80012294;
    }
    // 0x80012274: sw          $t9, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r25;
    // 0x80012278: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8001227C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80012280: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012284: jal         0x8001D6E4
    // 0x80012288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    obj_shade_fancy(rdram, ctx);
        goto after_3;
    // 0x80012288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8001228C: b           L_800122C4
    // 0x80012290: nop

        goto L_800122C4;
    // 0x80012290: nop

L_80012294:
    // 0x80012294: beq         $t1, $zero, L_800122B4
    if (ctx->r9 == 0) {
        // 0x80012298: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800122B4;
    }
    // 0x80012298: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001229C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800122A0: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800122A4: jal         0x8001D6E4
    // 0x800122A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    obj_shade_fancy(rdram, ctx);
        goto after_4;
    // 0x800122A8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_4:
    // 0x800122AC: b           L_800122C4
    // 0x800122B0: nop

        goto L_800122C4;
    // 0x800122B0: nop

L_800122B4:
    // 0x800122B4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800122B8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800122BC: jal         0x800245F0
    // 0x800122C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    obj_shade_fast(rdram, ctx);
        goto after_5;
    // 0x800122C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
L_800122C4:
    // 0x800122C4: beq         $s3, $zero, L_800122F8
    if (ctx->r19 == 0) {
        // 0x800122C8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800122F8;
    }
    // 0x800122C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800122CC: lh          $t7, 0x0($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X0);
    // 0x800122D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800122D4: bne         $t7, $at, L_800122F8
    if (ctx->r15 != ctx->r1) {
        // 0x800122D8: nop
    
            goto L_800122F8;
    }
    // 0x800122D8: nop

    // 0x800122DC: lb          $t6, 0x1D6($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X1D6);
    // 0x800122E0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800122E4: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x800122E8: beq         $at, $zero, L_800122F8
    if (ctx->r1 == 0) {
        // 0x800122EC: nop
    
            goto L_800122F8;
    }
    // 0x800122EC: nop

    // 0x800122F0: b           L_800122FC
    // 0x800122F4: sb          $t8, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r24;
        goto L_800122FC;
    // 0x800122F4: sb          $t8, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r24;
L_800122F8:
    // 0x800122F8: sb          $t9, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r25;
L_800122FC:
    // 0x800122FC: lb          $t5, 0x1F($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1F);
    // 0x80012300: lh          $t9, 0x48($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X48);
    // 0x80012304: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80012308: addu        $t6, $s0, $t7
    ctx->r14 = ADD32(ctx->r16, ctx->r15);
    // 0x8001230C: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80012310: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80012314: bne         $t9, $at, L_80012328
    if (ctx->r25 != ctx->r1) {
        // 0x80012318: sw          $t8, 0x44($s2)
        MEM_W(0X44, ctx->r18) = ctx->r24;
            goto L_80012328;
    }
    // 0x80012318: sw          $t8, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r24;
    // 0x8001231C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80012320: jal         0x80011264
    // 0x80012324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    obj_door_number(rdram, ctx);
        goto after_6;
    // 0x80012324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
L_80012328:
    // 0x80012328: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8001232C: nop

    // 0x80012330: lh          $a1, 0x52($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X52);
    // 0x80012334: nop

    // 0x80012338: beq         $a1, $zero, L_80012364
    if (ctx->r5 == 0) {
        // 0x8001233C: nop
    
            goto L_80012364;
    }
    // 0x8001233C: nop

    // 0x80012340: lh          $t7, 0x50($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X50);
    // 0x80012344: nop

    // 0x80012348: blez        $t7, L_80012364
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001234C: nop
    
            goto L_80012364;
    }
    // 0x8001234C: nop

    // 0x80012350: jal         0x80011134
    // 0x80012354: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_tex_animate(rdram, ctx);
        goto after_7;
    // 0x80012354: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80012358: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8001235C: nop

    // 0x80012360: sh          $zero, 0x52($t6)
    MEM_H(0X52, ctx->r14) = 0;
L_80012364:
    // 0x80012364: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80012368: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001236C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80012370: addiu       $s1, $s1, -0x5174
    ctx->r17 = ADD32(ctx->r17, -0X5174);
    // 0x80012374: lw          $a3, -0x52D8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X52D8);
    // 0x80012378: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001237C: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x80012380: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80012384: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80012388: jal         0x80069484
    // 0x8001238C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_8;
    // 0x8001238C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80012390: beq         $s3, $zero, L_800123E4
    if (ctx->r19 == 0) {
        // 0x80012394: sw          $zero, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = 0;
            goto L_800123E4;
    }
    // 0x80012394: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x80012398: jal         0x80012F30
    // 0x8001239C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    object_undo_player_tumble(rdram, ctx);
        goto after_9;
    // 0x8001239C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x800123A0: lb          $t8, 0x3B($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X3B);
    // 0x800123A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800123A8: beq         $t8, $zero, L_800123C4
    if (ctx->r24 == 0) {
        // 0x800123AC: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800123C4;
    }
    // 0x800123AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800123B0: lb          $t9, 0x1D6($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X1D6);
    // 0x800123B4: nop

    // 0x800123B8: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x800123BC: bne         $at, $zero, L_800123E0
    if (ctx->r1 != 0) {
        // 0x800123C0: nop
    
            goto L_800123E0;
    }
    // 0x800123C0: nop

L_800123C4:
    // 0x800123C4: lh          $a3, 0x16A($s3)
    ctx->r7 = MEM_H(ctx->r19, 0X16A);
    // 0x800123C8: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x800123CC: jal         0x80069790
    // 0x800123D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtx_head_push(rdram, ctx);
        goto after_10;
    // 0x800123D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_10:
    // 0x800123D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800123D8: b           L_800123E4
    // 0x800123DC: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
        goto L_800123E4;
    // 0x800123DC: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
L_800123E0:
    // 0x800123E0: sh          $zero, 0x16A($s3)
    MEM_H(0X16A, ctx->r19) = 0;
L_800123E4:
    // 0x800123E4: lbu         $t0, 0x39($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X39);
    // 0x800123E8: nop

    // 0x800123EC: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x800123F0: bne         $at, $zero, L_800123FC
    if (ctx->r1 != 0) {
        // 0x800123F4: nop
    
            goto L_800123FC;
    }
    // 0x800123F4: nop

    // 0x800123F8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800123FC:
    // 0x800123FC: lh          $t7, 0x48($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X48);
    // 0x80012400: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80012404: bne         $t7, $at, L_80012410
    if (ctx->r15 != ctx->r1) {
        // 0x80012408: sra         $t6, $t0, 1
        ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80012410;
    }
    // 0x80012408: sra         $t6, $t0, 1
    ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8001240C: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_80012410:
    // 0x80012410: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
    // 0x80012414: beq         $at, $zero, L_80012420
    if (ctx->r1 == 0) {
        // 0x80012418: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80012420;
    }
    // 0x80012418: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001241C: sw          $t8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r24;
L_80012420:
    // 0x80012420: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80012424: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80012428: beq         $t9, $zero, L_8001247C
    if (ctx->r25 == 0) {
        // 0x8001242C: nop
    
            goto L_8001247C;
    }
    // 0x8001242C: nop

    // 0x80012430: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012434: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80012438: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8001243C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80012440: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80012444: lw          $v1, 0x54($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X54);
    // 0x80012448: nop

    // 0x8001244C: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x80012450: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x80012454: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80012458: lbu         $t7, 0x6($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X6);
    // 0x8001245C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80012460: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80012464: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80012468: lbu         $t7, 0x7($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X7);
    // 0x8001246C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80012470: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80012474: b           L_80012494
    // 0x80012478: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80012494;
    // 0x80012478: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8001247C:
    // 0x8001247C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012480: addiu       $t6, $zero, -0x100
    ctx->r14 = ADD32(0, -0X100);
    // 0x80012484: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80012488: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8001248C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012490: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80012494:
    // 0x80012494: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x80012498: nop

    // 0x8001249C: lbu         $t8, 0x71($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X71);
    // 0x800124A0: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x800124A4: beq         $t8, $zero, L_80012504
    if (ctx->r24 == 0) {
        // 0x800124A8: nop
    
            goto L_80012504;
    }
    // 0x800124A8: nop

    // 0x800124AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800124B0: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800124B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800124B8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800124BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800124C0: lw          $v1, 0x54($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X54);
    // 0x800124C4: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x800124C8: lbu         $t5, 0x19($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X19);
    // 0x800124CC: lbu         $t7, 0x18($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X18);
    // 0x800124D0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800124D4: lbu         $t5, 0x1A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1A);
    // 0x800124D8: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800124DC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800124E0: sll         $t8, $t5, 8
    ctx->r24 = S32(ctx->r13 << 8);
    // 0x800124E4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800124E8: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x800124EC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800124F0: jal         0x8007B43C
    // 0x800124F4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    directional_lighting_on(rdram, ctx);
        goto after_11;
    // 0x800124F4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    after_11:
    // 0x800124F8: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800124FC: b           L_8001256C
    // 0x80012500: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
        goto L_8001256C;
    // 0x80012500: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
L_80012504:
    // 0x80012504: beq         $t7, $zero, L_80012550
    if (ctx->r15 == 0) {
        // 0x80012508: lui         $t6, 0xFA00
        ctx->r14 = S32(0XFA00 << 16);
            goto L_80012550;
    }
    // 0x80012508: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8001250C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012510: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80012514: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012518: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8001251C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80012520: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x80012524: nop

    // 0x80012528: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8001252C: sll         $t5, $t9, 24
    ctx->r13 = S32(ctx->r25 << 24);
    // 0x80012530: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x80012534: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80012538: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x8001253C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80012540: andi        $t5, $t0, 0xFF
    ctx->r13 = ctx->r8 & 0XFF;
    // 0x80012544: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x80012548: b           L_80012568
    // 0x8001254C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_80012568;
    // 0x8001254C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80012550:
    // 0x80012550: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012554: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80012558: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001255C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80012560: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80012564: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80012568:
    // 0x80012568: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
L_8001256C:
    // 0x8001256C: beq         $at, $zero, L_8001259C
    if (ctx->r1 == 0) {
        // 0x80012570: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_8001259C;
    }
    // 0x80012570: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012574: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80012578: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8001257C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80012584: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80012588: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x8001258C: jal         0x800143A8
    // 0x80012590: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    render_mesh(rdram, ctx);
        goto after_12;
    // 0x80012590: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_12:
    // 0x80012594: b           L_800125BC
    // 0x80012598: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
        goto L_800125BC;
    // 0x80012598: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
L_8001259C:
    // 0x8001259C: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x800125A0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800125A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800125A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800125AC: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x800125B0: jal         0x800143A8
    // 0x800125B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    render_mesh(rdram, ctx);
        goto after_13;
    // 0x800125B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_13:
    // 0x800125B8: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
L_800125BC:
    // 0x800125BC: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x800125C0: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800125C4: lbu         $t6, 0x71($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X71);
    // 0x800125C8: nop

    // 0x800125CC: beq         $t6, $zero, L_80012644
    if (ctx->r14 == 0) {
        // 0x800125D0: nop
    
            goto L_80012644;
    }
    // 0x800125D0: nop

    // 0x800125D4: beq         $t9, $zero, L_80012624
    if (ctx->r25 == 0) {
        // 0x800125D8: lui         $t6, 0xFA00
        ctx->r14 = S32(0XFA00 << 16);
            goto L_80012624;
    }
    // 0x800125D8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800125DC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800125E0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800125E4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800125E8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800125EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800125F0: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x800125F4: nop

    // 0x800125F8: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800125FC: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x80012600: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80012604: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x80012608: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8001260C: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80012610: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80012614: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80012618: or          $t5, $t8, $t9
    ctx->r13 = ctx->r24 | ctx->r25;
    // 0x8001261C: b           L_8001263C
    // 0x80012620: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_8001263C;
    // 0x80012620: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80012624:
    // 0x80012624: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012628: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001262C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80012630: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80012634: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80012638: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8001263C:
    // 0x8001263C: jal         0x8007B454
    // 0x80012640: nop

    directional_lighting_off(rdram, ctx);
        goto after_14;
    // 0x80012640: nop

    after_14:
L_80012644:
    // 0x80012644: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x80012648: nop

    // 0x8001264C: beq         $v0, $zero, L_800129A0
    if (ctx->r2 == 0) {
        // 0x80012650: lw          $a1, 0x78($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X78);
            goto L_800129A0;
    }
    // 0x80012650: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80012654: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80012658: beq         $s3, $zero, L_80012674
    if (ctx->r19 == 0) {
        // 0x8001265C: sw          $t9, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r25;
            goto L_80012674;
    }
    // 0x8001265C: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x80012660: lb          $t5, 0x1D6($s3)
    ctx->r13 = MEM_B(ctx->r19, 0X1D6);
    // 0x80012664: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80012668: bne         $t5, $at, L_80012678
    if (ctx->r13 != ctx->r1) {
        // 0x8001266C: lw          $t7, 0xAC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XAC);
            goto L_80012678;
    }
    // 0x8001266C: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80012670: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
L_80012674:
    // 0x80012674: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
L_80012678:
    // 0x80012678: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8001267C: blez        $t7, L_8001299C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80012680: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8001299C;
    }
    // 0x80012680: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80012684: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80012688:
    // 0x80012688: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x8001268C: nop

    // 0x80012690: addu        $t6, $v0, $t3
    ctx->r14 = ADD32(ctx->r2, ctx->r11);
    // 0x80012694: lw          $s0, 0x4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X4);
    // 0x80012698: nop

    // 0x8001269C: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800126A0: nop

    // 0x800126A4: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x800126A8: bne         $t9, $zero, L_80012990
    if (ctx->r25 != 0) {
        // 0x800126AC: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80012990;
    }
    // 0x800126AC: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800126B0: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x800126B4: nop

    // 0x800126B8: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x800126BC: lb          $v1, 0x0($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X0);
    // 0x800126C0: nop

    // 0x800126C4: bltz        $v1, L_80012990
    if (SIGNED(ctx->r3) < 0) {
        // 0x800126C8: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80012990;
    }
    // 0x800126C8: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800126CC: lh          $t6, 0x18($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X18);
    // 0x800126D0: nop

    // 0x800126D4: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800126D8: beq         $at, $zero, L_80012990
    if (ctx->r1 == 0) {
        // 0x800126DC: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80012990;
    }
    // 0x800126DC: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800126E0: lb          $t9, 0x3A($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3A);
    // 0x800126E4: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x800126E8: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800126EC: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x800126F0: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800126F4: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x800126F8: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800126FC: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x80012700: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80012704: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80012708: lw          $t6, 0x44($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X44);
    // 0x8001270C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80012710: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80012714: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80012718: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8001271C: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80012720: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80012724: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x80012728: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001272C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80012730: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80012734: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80012738: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001273C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80012740: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x80012744: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80012748: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8001274C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80012750: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80012754: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012758: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8001275C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80012760: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80012764: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80012768: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8001276C: lb          $t7, 0x53($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X53);
    // 0x80012770: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x80012774: bne         $t7, $at, L_80012784
    if (ctx->r15 != ctx->r1) {
        // 0x80012778: lui         $t5, 0x8000
        ctx->r13 = S32(0X8000 << 16);
            goto L_80012784;
    }
    // 0x80012778: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8001277C: b           L_80012788
    // 0x80012780: addiu       $t1, $zero, 0x10A
    ctx->r9 = ADD32(0, 0X10A);
        goto L_80012788;
    // 0x80012780: addiu       $t1, $zero, 0x10A
    ctx->r9 = ADD32(0, 0X10A);
L_80012784:
    // 0x80012784: addiu       $t1, $zero, 0x10B
    ctx->r9 = ADD32(0, 0X10B);
L_80012788:
    // 0x80012788: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x8001278C: beq         $at, $zero, L_80012798
    if (ctx->r1 == 0) {
        // 0x80012790: ori         $t8, $t1, 0x4
        ctx->r24 = ctx->r9 | 0X4;
            goto L_80012798;
    }
    // 0x80012790: ori         $t8, $t1, 0x4
    ctx->r24 = ctx->r9 | 0X4;
    // 0x80012794: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
L_80012798:
    // 0x80012798: addiu       $t5, $zero, 0x17D7
    ctx->r13 = ADD32(0, 0X17D7);
    // 0x8001279C: addiu       $at, $zero, 0x17D7
    ctx->r1 = ADD32(0, 0X17D7);
    // 0x800127A0: beq         $t5, $at, L_800127AC
    if (ctx->r13 == ctx->r1) {
        // 0x800127A4: nop
    
            goto L_800127AC;
    }
    // 0x800127A4: nop

    // 0x800127A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800127AC:
    // 0x800127AC: bne         $a0, $zero, L_80012960
    if (ctx->r4 != 0) {
        // 0x800127B0: nop
    
            goto L_80012960;
    }
    // 0x800127B0: nop

    // 0x800127B4: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x800127B8: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x800127BC: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800127C0: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    // 0x800127C4: beq         $v0, $zero, L_800127DC
    if (ctx->r2 == 0) {
        // 0x800127C8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800127DC;
    }
    // 0x800127C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800127CC: lw          $v0, 0xAC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XAC);
    // 0x800127D0: nop

    // 0x800127D4: xori        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 ^ 0X3;
    // 0x800127D8: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_800127DC:
    // 0x800127DC: sll         $t0, $v0, 24
    ctx->r8 = S32(ctx->r2 << 24);
    // 0x800127E0: sra         $t8, $t0, 24
    ctx->r24 = S32(SIGNED(ctx->r8) >> 24);
    // 0x800127E4: beq         $s3, $zero, L_80012804
    if (ctx->r19 == 0) {
        // 0x800127E8: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_80012804;
    }
    // 0x800127E8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800127EC: lbu         $t5, 0x1F7($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X1F7);
    // 0x800127F0: nop

    // 0x800127F4: slti        $at, $t5, 0xFF
    ctx->r1 = SIGNED(ctx->r13) < 0XFF ? 1 : 0;
    // 0x800127F8: beq         $at, $zero, L_80012804
    if (ctx->r1 == 0) {
        // 0x800127FC: nop
    
            goto L_80012804;
    }
    // 0x800127FC: nop

    // 0x80012800: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80012804:
    // 0x80012804: beq         $t0, $zero, L_800128B4
    if (ctx->r8 == 0) {
        // 0x80012808: andi        $t6, $v1, 0xFF
        ctx->r14 = ctx->r3 & 0XFF;
            goto L_800128B4;
    }
    // 0x80012808: andi        $t6, $v1, 0xFF
    ctx->r14 = ctx->r3 & 0XFF;
    // 0x8001280C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80012810: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80012814: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80012818: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8001281C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80012820: sll         $t5, $t6, 8
    ctx->r13 = S32(ctx->r14 << 8);
    // 0x80012824: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80012828: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8001282C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80012830: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80012834: sb          $t0, 0x8A($sp)
    MEM_B(0X8A, ctx->r29) = ctx->r8;
    // 0x80012838: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    // 0x8001283C: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x80012840: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80012844: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x80012848: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8001284C: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x80012850: jal         0x80012C98
    // 0x80012854: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    func_80012C98(rdram, ctx);
        goto after_15;
    // 0x80012854: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    after_15:
    // 0x80012858: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001285C: lb          $t0, 0x8A($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X8A);
    // 0x80012860: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80012864: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80012868: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x8001286C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80012870: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80012874: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80012878: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001287C: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80012880: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80012884: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80012888: addiu       $t6, $zero, -0x100
    ctx->r14 = ADD32(0, -0X100);
    // 0x8001288C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012890: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80012894: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012898: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8001289C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800128A0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800128A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800128A8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800128AC: nop

    // 0x800128B0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_800128B4:
    // 0x800128B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800128B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800128BC: addiu       $a2, $a2, -0x516C
    ctx->r6 = ADD32(ctx->r6, -0X516C);
    // 0x800128C0: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x800128C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800128C8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800128CC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800128D0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800128D4: sb          $t0, 0x8A($sp)
    MEM_B(0X8A, ctx->r29) = ctx->r8;
    // 0x800128D8: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x800128DC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800128E0: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x800128E4: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x800128E8: jal         0x80068514
    // 0x800128EC: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    render_sprite_billboard(rdram, ctx);
        goto after_16;
    // 0x800128EC: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    after_16:
    // 0x800128F0: lb          $t0, 0x8A($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X8A);
    // 0x800128F4: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x800128F8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800128FC: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80012900: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80012904: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80012908: beq         $t0, $zero, L_80012960
    if (ctx->r8 == 0) {
        // 0x8001290C: sw          $v0, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->r2;
            goto L_80012960;
    }
    // 0x8001290C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x80012910: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012914: lui         $t6, 0xBC00
    ctx->r14 = S32(0XBC00 << 16);
    // 0x80012918: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001291C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80012920: ori         $t6, $t6, 0xA
    ctx->r14 = ctx->r14 | 0XA;
    // 0x80012924: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80012928: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001292C: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    // 0x80012930: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x80012934: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80012938: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8001293C: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x80012940: jal         0x80012CE8
    // 0x80012944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80012CE8(rdram, ctx);
        goto after_17;
    // 0x80012944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80012948: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x8001294C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80012950: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80012954: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80012958: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8001295C: nop

L_80012960:
    // 0x80012960: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80012964: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80012968: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8001296C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80012970: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80012974: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80012978: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8001297C: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80012980: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80012984: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80012988: nop

    // 0x8001298C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_80012990:
    // 0x80012990: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80012994: bne         $t2, $t9, L_80012688
    if (ctx->r10 != ctx->r25) {
        // 0x80012998: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_80012688;
    }
    // 0x80012998: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
L_8001299C:
    // 0x8001299C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
L_800129A0:
    // 0x800129A0: beq         $s3, $zero, L_80012AF8
    if (ctx->r19 == 0) {
        // 0x800129A4: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129A4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129A8: lw          $s0, 0x144($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X144);
    // 0x800129AC: nop

    // 0x800129B0: beq         $s0, $zero, L_80012AF8
    if (ctx->r16 == 0) {
        // 0x800129B4: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129B4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129B8: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x800129BC: nop

    // 0x800129C0: lb          $v1, 0x58($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X58);
    // 0x800129C4: nop

    // 0x800129C8: bltz        $v1, L_80012AF8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800129CC: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129CC: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129D0: lh          $t5, 0x18($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X18);
    // 0x800129D4: nop

    // 0x800129D8: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800129DC: beq         $at, $zero, L_80012AF8
    if (ctx->r1 == 0) {
        // 0x800129E0: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x800129E0: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800129E4: lb          $t6, 0x3A($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3A);
    // 0x800129E8: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x800129EC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800129F0: lw          $t5, 0x14($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X14);
    // 0x800129F4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800129F8: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800129FC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80012A00: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x80012A04: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x80012A08: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80012A0C: lw          $t5, 0x44($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X44);
    // 0x80012A10: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x80012A14: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80012A18: addu        $v0, $t5, $t8
    ctx->r2 = ADD32(ctx->r13, ctx->r24);
    // 0x80012A1C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80012A20: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80012A24: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80012A28: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x80012A2C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80012A30: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80012A34: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80012A38: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80012A3C: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80012A40: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80012A44: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80012A48: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x80012A4C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80012A50: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012A54: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80012A58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012A5C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80012A60: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x80012A64: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80012A68: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80012A6C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012A70: addiu       $a2, $a2, -0x516C
    ctx->r6 = ADD32(ctx->r6, -0X516C);
    // 0x80012A74: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x80012A78: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x80012A7C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80012A80: addiu       $t6, $zero, 0x10A
    ctx->r14 = ADD32(0, 0X10A);
    // 0x80012A84: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80012A88: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80012A8C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80012A90: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80012A94: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80012A98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80012A9C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80012AA0: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x80012AA4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80012AA8: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80012AAC: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80012AB0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80012AB4: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80012AB8: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x80012ABC: sub.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80012AC0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80012AC4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80012AC8: mul.d       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x80012ACC: add.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d + ctx->f10.d;
    // 0x80012AD0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80012AD4: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80012AD8: lb          $t8, 0x53($t5)
    ctx->r24 = MEM_B(ctx->r13, 0X53);
    // 0x80012ADC: nop

    // 0x80012AE0: bne         $t8, $at, L_80012AF8
    if (ctx->r24 != ctx->r1) {
        // 0x80012AE4: lw          $t7, 0x9C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X9C);
            goto L_80012AF8;
    }
    // 0x80012AE4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80012AE8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80012AEC: jal         0x80068514
    // 0x80012AF0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    render_sprite_billboard(rdram, ctx);
        goto after_18;
    // 0x80012AF0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_18:
    // 0x80012AF4: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
L_80012AF8:
    // 0x80012AF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80012AFC: beq         $t7, $at, L_80012BA8
    if (ctx->r15 == ctx->r1) {
        // 0x80012B00: lw          $t6, 0xA8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA8);
            goto L_80012BA8;
    }
    // 0x80012B00: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80012B04: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x80012B08: nop

    // 0x80012B0C: lbu         $t5, 0x71($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X71);
    // 0x80012B10: nop

    // 0x80012B14: beq         $t5, $zero, L_80012B6C
    if (ctx->r13 == 0) {
        // 0x80012B18: lw          $t5, 0xB0($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB0);
            goto L_80012B6C;
    }
    // 0x80012B18: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80012B1C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012B20: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80012B24: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012B28: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80012B2C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80012B30: lw          $v1, 0x54($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X54);
    // 0x80012B34: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x80012B38: lbu         $t6, 0x19($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X19);
    // 0x80012B3C: lbu         $t9, 0x18($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18);
    // 0x80012B40: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80012B44: lbu         $t6, 0x1A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1A);
    // 0x80012B48: sll         $t5, $t9, 24
    ctx->r13 = S32(ctx->r25 << 24);
    // 0x80012B4C: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x80012B50: sll         $t5, $t6, 8
    ctx->r13 = S32(ctx->r14 << 8);
    // 0x80012B54: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x80012B58: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80012B5C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80012B60: jal         0x8007B43C
    // 0x80012B64: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    directional_lighting_on(rdram, ctx);
        goto after_19;
    // 0x80012B64: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_19:
    // 0x80012B68: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
L_80012B6C:
    // 0x80012B6C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80012B70: lw          $a2, 0x9C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X9C);
    // 0x80012B74: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80012B78: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80012B7C: jal         0x800143A8
    // 0x80012B80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    render_mesh(rdram, ctx);
        goto after_20;
    // 0x80012B80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_20:
    // 0x80012B84: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x80012B88: nop

    // 0x80012B8C: lbu         $t7, 0x71($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X71);
    // 0x80012B90: nop

    // 0x80012B94: beq         $t7, $zero, L_80012BA8
    if (ctx->r15 == 0) {
        // 0x80012B98: lw          $t6, 0xA8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA8);
            goto L_80012BA8;
    }
    // 0x80012B98: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80012B9C: jal         0x8007B454
    // 0x80012BA0: nop

    directional_lighting_off(rdram, ctx);
        goto after_21;
    // 0x80012BA0: nop

    after_21:
    // 0x80012BA4: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_80012BA8:
    // 0x80012BA8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80012BAC: bne         $t6, $zero, L_80012BCC
    if (ctx->r14 != 0) {
        // 0x80012BB0: nop
    
            goto L_80012BCC;
    }
    // 0x80012BB0: nop

    // 0x80012BB4: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x80012BB8: nop

    // 0x80012BBC: lbu         $t5, 0x71($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X71);
    // 0x80012BC0: nop

    // 0x80012BC4: beq         $t5, $zero, L_80012BE8
    if (ctx->r13 == 0) {
        // 0x80012BC8: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_80012BE8;
    }
    // 0x80012BC8: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80012BCC:
    // 0x80012BCC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012BD0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012BD4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012BD8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80012BDC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80012BE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80012BE4: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80012BE8:
    // 0x80012BE8: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80012BEC: beq         $t9, $zero, L_80012C0C
    if (ctx->r25 == 0) {
        // 0x80012BF0: nop
    
            goto L_80012C0C;
    }
    // 0x80012BF0: nop

    // 0x80012BF4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80012BF8: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x80012BFC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80012C00: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80012C04: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80012C08: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80012C0C:
    // 0x80012C0C: jal         0x80069A40
    // 0x80012C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_pop(rdram, ctx);
        goto after_22;
    // 0x80012C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
L_80012C14:
    // 0x80012C14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80012C18: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80012C1C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80012C20: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80012C24: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80012C28: jr          $ra
    // 0x80012C2C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80012C2C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void set_render_printf_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B62B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B62B8: addiu       $v0, $v0, -0x7A28
    ctx->r2 = ADD32(ctx->r2, -0X7A28);
    // 0x800B62BC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B62C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B62C4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B62C8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800B62CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800B62D0: addiu       $t0, $zero, 0x85
    ctx->r8 = ADD32(0, 0X85);
    // 0x800B62D4: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x800B62D8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B62DC: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800B62E0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B62E4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B62E8: sb          $a0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r4;
    // 0x800B62EC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800B62F0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B62F4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800B62F8: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x800B62FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B6300: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800B6304: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x800B6308: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B630C: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x800B6310: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800B6314: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B6318: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B631C: sb          $a2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r6;
    // 0x800B6320: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B6324: nop

    // 0x800B6328: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B632C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800B6330: sb          $a3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r7;
    // 0x800B6334: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B6338: nop

    // 0x800B633C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B6340: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B6344: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800B6348: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B634C: nop

    // 0x800B6350: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B6354: jr          $ra
    // 0x800B6358: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800B6358: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void audspat_play_sound_direct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800095E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800095EC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800095F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800095F4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800095F8: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800095FC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80009600: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80009604: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80009608: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8000960C: lbu         $t7, 0x4B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4B);
    // 0x80009610: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x80009614: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80009618: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8000961C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80009620: addiu       $t0, $zero, 0x3A98
    ctx->r8 = ADD32(0, 0X3A98);
    // 0x80009624: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80009628: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8000962C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80009630: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80009634: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80009638: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8000963C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80009640: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80009644: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80009648: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000964C: beq         $t2, $zero, L_8000969C
    if (ctx->r10 == 0) {
        // 0x80009650: sw          $t9, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r25;
            goto L_8000969C;
    }
    // 0x80009650: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80009654: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80009658: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000965C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80009660: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80009664: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80009668: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8000966C: nop

    // 0x80009670: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80009674: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80009678: nop

    // 0x8000967C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80009680: bne         $t2, $zero, L_80009694
    if (ctx->r10 != 0) {
        // 0x80009684: nop
    
            goto L_80009694;
    }
    // 0x80009684: nop

    // 0x80009688: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8000968C: b           L_800096AC
    // 0x80009690: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800096AC;
    // 0x80009690: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80009694:
    // 0x80009694: b           L_800096AC
    // 0x80009698: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800096AC;
    // 0x80009698: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8000969C:
    // 0x8000969C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800096A0: nop

    // 0x800096A4: bltz        $t2, L_80009694
    if (SIGNED(ctx->r10) < 0) {
        // 0x800096A8: nop
    
            goto L_80009694;
    }
    // 0x800096A8: nop

L_800096AC:
    // 0x800096AC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800096B0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800096B4: addiu       $t3, $zero, 0x3F
    ctx->r11 = ADD32(0, 0X3F);
    // 0x800096B8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800096BC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800096C0: jal         0x8000974C
    // 0x800096C4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    audspat_point_create(rdram, ctx);
        goto after_0;
    // 0x800096C4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_0:
    // 0x800096C8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800096CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800096D0: jr          $ra
    // 0x800096D4: nop

    return;
    // 0x800096D4: nop

;}
RECOMP_FUNC void func_8000CBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CBC0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000CBC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CBC8: addiu       $v0, $v0, -0x51B8
    ctx->r2 = ADD32(ctx->r2, -0X51B8);
    // 0x8000CBCC: addiu       $v1, $v1, -0x51F8
    ctx->r3 = ADD32(ctx->r3, -0X51F8);
L_8000CBD0:
    // 0x8000CBD0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8000CBD4: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x8000CBD8: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x8000CBDC: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x8000CBE0: bne         $v1, $v0, L_8000CBD0
    if (ctx->r3 != ctx->r2) {
        // 0x8000CBE4: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_8000CBD0;
    }
    // 0x8000CBE4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8000CBE8: jr          $ra
    // 0x8000CBEC: nop

    return;
    // 0x8000CBEC: nop

;}
RECOMP_FUNC void repair_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075D38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80075D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075D40: jal         0x800758DC
    // 0x80075D44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075D44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80075D48: beq         $v0, $zero, L_80075D58
    if (ctx->r2 == 0) {
        // 0x80075D4C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075D58;
    }
    // 0x80075D4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075D50: bne         $v0, $at, L_80075DA8
    if (ctx->r2 != ctx->r1) {
        // 0x80075D54: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80075DA8;
    }
    // 0x80075D54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80075D58:
    // 0x80075D58: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80075D5C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80075D60: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80075D64: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80075D68: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80075D6C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80075D70: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80075D74: addiu       $t8, $t8, 0x4018
    ctx->r24 = ADD32(ctx->r24, 0X4018);
    // 0x80075D78: jal         0x800CF530
    // 0x80075D7C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    osPfsChecker_recomp(rdram, ctx);
        goto after_1;
    // 0x80075D7C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80075D80: bne         $v0, $zero, L_80075D90
    if (ctx->r2 != 0) {
        // 0x80075D84: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075D90;
    }
    // 0x80075D84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075D88: b           L_80075DA8
    // 0x80075D8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80075DA8;
    // 0x80075D8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80075D90:
    // 0x80075D90: bne         $v0, $at, L_80075DA0
    if (ctx->r2 != ctx->r1) {
        // 0x80075D94: nop
    
            goto L_80075DA0;
    }
    // 0x80075D94: nop

    // 0x80075D98: b           L_80075DA8
    // 0x80075D9C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80075DA8;
    // 0x80075D9C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80075DA0:
    // 0x80075DA0: b           L_80075DA8
    // 0x80075DA4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80075DA8;
    // 0x80075DA4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80075DA8:
    // 0x80075DA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80075DAC: jal         0x80075AEC
    // 0x80075DB0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_2;
    // 0x80075DB0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80075DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075DB8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80075DBC: jr          $ra
    // 0x80075DC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80075DC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void dialogue_tt_gamestatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E3D0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8009E3D4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009E3D8: addiu       $v1, $v1, 0x1E28
    ctx->r3 = ADD32(ctx->r3, 0X1E28);
    // 0x8009E3DC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009E3E0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8009E3E4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8009E3E8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8009E3EC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8009E3F0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8009E3F4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8009E3F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8009E3FC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8009E400: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8009E404: bne         $s4, $v0, L_8009E418
    if (ctx->r20 != ctx->r2) {
        // 0x8009E408: swc1        $f20, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
            goto L_8009E418;
    }
    // 0x8009E408: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8009E40C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8009E410: b           L_8009E7BC
    // 0x8009E414: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
        goto L_8009E7BC;
    // 0x8009E414: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_8009E418:
    // 0x8009E418: jal         0x8006EA90
    // 0x8009E41C: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009E41C: nop

    after_0:
    // 0x8009E420: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8009E424: jal         0x80068508
    // 0x8009E428: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x8009E428: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8009E42C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009E430: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8009E434: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8009E438: bne         $t7, $zero, L_8009E448
    if (ctx->r15 != 0) {
        // 0x8009E43C: lui         $s2, 0x800E
        ctx->r18 = S32(0X800E << 16);
            goto L_8009E448;
    }
    // 0x8009E43C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8009E440: b           L_8009E44C
    // 0x8009E444: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
        goto L_8009E44C;
    // 0x8009E444: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
L_8009E448:
    // 0x8009E448: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
L_8009E44C:
    // 0x8009E44C: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8009E450: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x8009E454: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8009E458: beq         $t0, $zero, L_8009E464
    if (ctx->r8 == 0) {
        // 0x8009E45C: addiu       $s2, $s2, -0x8A4
        ctx->r18 = ADD32(ctx->r18, -0X8A4);
            goto L_8009E464;
    }
    // 0x8009E45C: addiu       $s2, $s2, -0x8A4
    ctx->r18 = ADD32(ctx->r18, -0X8A4);
    // 0x8009E460: addiu       $s3, $zero, 0x9
    ctx->r19 = ADD32(0, 0X9);
L_8009E464:
    // 0x8009E464: addiu       $t1, $zero, -0x4A
    ctx->r9 = ADD32(0, -0X4A);
    // 0x8009E468: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8009E46C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009E470: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009E474: sll         $v0, $s3, 5
    ctx->r2 = S32(ctx->r19 << 5);
    // 0x8009E478: addiu       $t4, $zero, 0x41
    ctx->r12 = ADD32(0, 0X41);
    // 0x8009E47C: subu        $t5, $t4, $s5
    ctx->r13 = SUB32(ctx->r12, ctx->r21);
    // 0x8009E480: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8009E484: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8009E488: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x8009E48C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8009E490: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009E494: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8009E498: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8009E49C: jal         0x8009CA60
    // 0x8009E4A0: swc1        $f10, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_2;
    // 0x8009E4A0: swc1        $f10, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f10.u32l;
    after_2:
    // 0x8009E4A4: jal         0x8007BF1C
    // 0x8009E4A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_3;
    // 0x8009E4A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8009E4AC: addiu       $t8, $zero, -0x1D
    ctx->r24 = ADD32(0, -0X1D);
    // 0x8009E4B0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8009E4B4: addiu       $t0, $zero, 0x62
    ctx->r8 = ADD32(0, 0X62);
    // 0x8009E4B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009E4BC: subu        $t1, $t0, $s5
    ctx->r9 = SUB32(ctx->r8, ctx->r21);
    // 0x8009E4C0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8009E4C4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8009E4C8: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8009E4CC: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009E4D0: swc1        $f18, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f18.u32l;
    // 0x8009E4D4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009E4D8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8009E4DC: swc1        $f20, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f20.u32l;
    // 0x8009E4E0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8009E4E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009E4E8: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8009E4EC: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8009E4F0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009E4F4: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8009E4F8: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8009E4FC: nop

    // 0x8009E500: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8009E504: nop

    // 0x8009E508: lh          $a1, 0x0($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X0);
    // 0x8009E50C: nop

    // 0x8009E510: div         $zero, $a1, $s0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r16)));
    // 0x8009E514: bne         $s0, $zero, L_8009E520
    if (ctx->r16 != 0) {
        // 0x8009E518: nop
    
            goto L_8009E520;
    }
    // 0x8009E518: nop

    // 0x8009E51C: break       7
    do_break(2148132124);
L_8009E520:
    // 0x8009E520: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009E524: bne         $s0, $at, L_8009E538
    if (ctx->r16 != ctx->r1) {
        // 0x8009E528: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009E538;
    }
    // 0x8009E528: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009E52C: bne         $a1, $at, L_8009E538
    if (ctx->r5 != ctx->r1) {
        // 0x8009E530: nop
    
            goto L_8009E538;
    }
    // 0x8009E530: nop

    // 0x8009E534: break       6
    do_break(2148132148);
L_8009E538:
    // 0x8009E538: mflo        $v0
    ctx->r2 = lo;
    // 0x8009E53C: beq         $v0, $zero, L_8009E588
    if (ctx->r2 == 0) {
        // 0x8009E540: nop
    
            goto L_8009E588;
    }
    // 0x8009E540: nop

    // 0x8009E544: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009E548: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009E54C: jal         0x8009CA60
    // 0x8009E550: sh          $v0, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r2;
    menu_element_render(rdram, ctx);
        goto after_4;
    // 0x8009E550: sh          $v0, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r2;
    after_4:
    // 0x8009E554: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8009E558: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8009E55C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009E560: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8009E564: nop

    // 0x8009E568: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8009E56C: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x8009E570: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8009E574: nop

    // 0x8009E578: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009E57C: nop

    // 0x8009E580: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x8009E584: nop

L_8009E588:
    // 0x8009E588: div         $zero, $a1, $s0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r16)));
    // 0x8009E58C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8009E590: bne         $s0, $zero, L_8009E59C
    if (ctx->r16 != 0) {
        // 0x8009E594: nop
    
            goto L_8009E59C;
    }
    // 0x8009E594: nop

    // 0x8009E598: break       7
    do_break(2148132248);
L_8009E59C:
    // 0x8009E59C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009E5A0: bne         $s0, $at, L_8009E5B4
    if (ctx->r16 != ctx->r1) {
        // 0x8009E5A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009E5B4;
    }
    // 0x8009E5A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009E5A8: bne         $a1, $at, L_8009E5B4
    if (ctx->r5 != ctx->r1) {
        // 0x8009E5AC: nop
    
            goto L_8009E5B4;
    }
    // 0x8009E5AC: nop

    // 0x8009E5B0: break       6
    do_break(2148132272);
L_8009E5B4:
    // 0x8009E5B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009E5B8: mfhi        $t8
    ctx->r24 = hi;
    // 0x8009E5BC: sh          $t8, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r24;
    // 0x8009E5C0: jal         0x8009CA60
    // 0x8009E5C4: nop

    menu_element_render(rdram, ctx);
        goto after_5;
    // 0x8009E5C4: nop

    after_5:
    // 0x8009E5C8: addiu       $t0, $zero, -0x31
    ctx->r8 = ADD32(0, -0X31);
    // 0x8009E5CC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8009E5D0: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8009E5D4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009E5D8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8009E5DC: swc1        $f8, 0x14C($t1)
    MEM_W(0X14C, ctx->r9) = ctx->f8.u32l;
    // 0x8009E5E0: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009E5E4: jal         0x8009CA60
    // 0x8009E5E8: swc1        $f20, 0x150($t2)
    MEM_W(0X150, ctx->r10) = ctx->f20.u32l;
    menu_element_render(rdram, ctx);
        goto after_6;
    // 0x8009E5E8: swc1        $f20, 0x150($t2)
    MEM_W(0X150, ctx->r10) = ctx->f20.u32l;
    after_6:
    // 0x8009E5EC: jal         0x8007BF1C
    // 0x8009E5F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    sprite_opaque(rdram, ctx);
        goto after_7;
    // 0x8009E5F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x8009E5F4: addiu       $t3, $zero, -0x59
    ctx->r11 = ADD32(0, -0X59);
    // 0x8009E5F8: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8009E5FC: addiu       $s5, $s5, 0x32
    ctx->r21 = ADD32(ctx->r21, 0X32);
    // 0x8009E600: addiu       $t5, $zero, 0x5F
    ctx->r13 = ADD32(0, 0X5F);
    // 0x8009E604: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009E608: subu        $t6, $t5, $s5
    ctx->r14 = SUB32(ctx->r13, ctx->r21);
    // 0x8009E60C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8009E610: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8009E614: swc1        $f16, 0x1EC($t4)
    MEM_W(0X1EC, ctx->r12) = ctx->f16.u32l;
    // 0x8009E618: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009E61C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8009E620: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8009E624: swc1        $f20, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f20.u32l;
    // 0x8009E628: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8009E62C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8009E630: lbu         $t9, 0x17($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X17);
    // 0x8009E634: jal         0x8009CA60
    // 0x8009E638: sh          $t9, 0x1F8($t0)
    MEM_H(0X1F8, ctx->r8) = ctx->r25;
    menu_element_render(rdram, ctx);
        goto after_8;
    // 0x8009E638: sh          $t9, 0x1F8($t0)
    MEM_H(0X1F8, ctx->r8) = ctx->r25;
    after_8:
    // 0x8009E63C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009E640: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8009E644: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8009E648: swc1        $f4, 0x20C($t1)
    MEM_W(0X20C, ctx->r9) = ctx->f4.u32l;
    // 0x8009E64C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009E650: nop

    // 0x8009E654: swc1        $f20, 0x210($t2)
    MEM_W(0X210, ctx->r10) = ctx->f20.u32l;
    // 0x8009E658: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8009E65C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009E660: lbu         $t4, 0x16($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X16);
    // 0x8009E664: jal         0x8009CA60
    // 0x8009E668: sh          $t4, 0x218($t5)
    MEM_H(0X218, ctx->r13) = ctx->r12;
    menu_element_render(rdram, ctx);
        goto after_9;
    // 0x8009E668: sh          $t4, 0x218($t5)
    MEM_H(0X218, ctx->r13) = ctx->r12;
    after_9:
    // 0x8009E66C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8009E670: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8009E674: lhu         $v1, 0xE($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0XE);
    // 0x8009E678: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009E67C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8009E680:
    // 0x8009E680: and         $t7, $v1, $v0
    ctx->r15 = ctx->r3 & ctx->r2;
    // 0x8009E684: bne         $v0, $t7, L_8009E690
    if (ctx->r2 != ctx->r15) {
        // 0x8009E688: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8009E690;
    }
    // 0x8009E688: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8009E68C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8009E690:
    // 0x8009E690: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009E694: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8009E698: bne         $at, $zero, L_8009E680
    if (ctx->r1 != 0) {
        // 0x8009E69C: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8009E680;
    }
    // 0x8009E69C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009E6A0: addiu       $s5, $s5, 0x32
    ctx->r21 = ADD32(ctx->r21, 0X32);
    // 0x8009E6A4: addiu       $t9, $zero, 0x5F
    ctx->r25 = ADD32(0, 0X5F);
    // 0x8009E6A8: subu        $t0, $t9, $s5
    ctx->r8 = SUB32(ctx->r25, ctx->r21);
    // 0x8009E6AC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8009E6B0: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x8009E6B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009E6B8: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
L_8009E6BC:
    // 0x8009E6BC: addiu       $t1, $s1, -0x7C
    ctx->r9 = ADD32(ctx->r17, -0X7C);
    // 0x8009E6C0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8009E6C4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009E6C8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009E6CC: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8009E6D0: swc1        $f10, 0x1AC($t2)
    MEM_W(0X1AC, ctx->r10) = ctx->f10.u32l;
    // 0x8009E6D4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8009E6D8: beq         $at, $zero, L_8009E6EC
    if (ctx->r1 == 0) {
        // 0x8009E6DC: swc1        $f20, 0x1B0($t3)
        MEM_W(0X1B0, ctx->r11) = ctx->f20.u32l;
            goto L_8009E6EC;
    }
    // 0x8009E6DC: swc1        $f20, 0x1B0($t3)
    MEM_W(0X1B0, ctx->r11) = ctx->f20.u32l;
    // 0x8009E6E0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8009E6E4: b           L_8009E6F8
    // 0x8009E6E8: sh          $s4, 0x1B8($t4)
    MEM_H(0X1B8, ctx->r12) = ctx->r20;
        goto L_8009E6F8;
    // 0x8009E6E8: sh          $s4, 0x1B8($t4)
    MEM_H(0X1B8, ctx->r12) = ctx->r20;
L_8009E6EC:
    // 0x8009E6EC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009E6F0: nop

    // 0x8009E6F4: sh          $zero, 0x1B8($t5)
    MEM_H(0X1B8, ctx->r13) = 0;
L_8009E6F8:
    // 0x8009E6F8: jal         0x8009CA60
    // 0x8009E6FC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    menu_element_render(rdram, ctx);
        goto after_10;
    // 0x8009E6FC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_10:
    // 0x8009E700: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009E704: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8009E708: bne         $at, $zero, L_8009E6BC
    if (ctx->r1 != 0) {
        // 0x8009E70C: addiu       $s1, $s1, 0x1E
        ctx->r17 = ADD32(ctx->r17, 0X1E);
            goto L_8009E6BC;
    }
    // 0x8009E70C: addiu       $s1, $s1, 0x1E
    ctx->r17 = ADD32(ctx->r17, 0X1E);
    // 0x8009E710: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8009E714: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009E718: lhu         $v1, 0x8($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X8);
    // 0x8009E71C: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8009E720: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8009E724:
    // 0x8009E724: and         $t7, $v1, $v0
    ctx->r15 = ctx->r3 & ctx->r2;
    // 0x8009E728: bne         $v0, $t7, L_8009E734
    if (ctx->r2 != ctx->r15) {
        // 0x8009E72C: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_8009E734;
    }
    // 0x8009E72C: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8009E730: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8009E734:
    // 0x8009E734: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009E738: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8009E73C: bne         $at, $zero, L_8009E724
    if (ctx->r1 != 0) {
        // 0x8009E740: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8009E724;
    }
    // 0x8009E740: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009E744: addiu       $s5, $s5, 0x2D
    ctx->r21 = ADD32(ctx->r21, 0X2D);
    // 0x8009E748: addiu       $t9, $zero, 0x5F
    ctx->r25 = ADD32(0, 0X5F);
    // 0x8009E74C: subu        $t0, $t9, $s5
    ctx->r8 = SUB32(ctx->r25, ctx->r21);
    // 0x8009E750: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8009E754: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x8009E758: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009E75C: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
L_8009E760:
    // 0x8009E760: addiu       $t1, $s1, -0x7C
    ctx->r9 = ADD32(ctx->r17, -0X7C);
    // 0x8009E764: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8009E768: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8009E76C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009E770: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8009E774: swc1        $f4, 0x1CC($t2)
    MEM_W(0X1CC, ctx->r10) = ctx->f4.u32l;
    // 0x8009E778: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8009E77C: beq         $at, $zero, L_8009E790
    if (ctx->r1 == 0) {
        // 0x8009E780: swc1        $f20, 0x1D0($t3)
        MEM_W(0X1D0, ctx->r11) = ctx->f20.u32l;
            goto L_8009E790;
    }
    // 0x8009E780: swc1        $f20, 0x1D0($t3)
    MEM_W(0X1D0, ctx->r11) = ctx->f20.u32l;
    // 0x8009E784: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8009E788: b           L_8009E79C
    // 0x8009E78C: sh          $s4, 0x1D8($t4)
    MEM_H(0X1D8, ctx->r12) = ctx->r20;
        goto L_8009E79C;
    // 0x8009E78C: sh          $s4, 0x1D8($t4)
    MEM_H(0X1D8, ctx->r12) = ctx->r20;
L_8009E790:
    // 0x8009E790: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8009E794: nop

    // 0x8009E798: sh          $zero, 0x1D8($t5)
    MEM_H(0X1D8, ctx->r13) = 0;
L_8009E79C:
    // 0x8009E79C: jal         0x8009CA60
    // 0x8009E7A0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    menu_element_render(rdram, ctx);
        goto after_11;
    // 0x8009E7A0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_11:
    // 0x8009E7A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009E7A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009E7AC: bne         $s0, $at, L_8009E760
    if (ctx->r16 != ctx->r1) {
        // 0x8009E7B0: addiu       $s1, $s1, 0x1E
        ctx->r17 = ADD32(ctx->r17, 0X1E);
            goto L_8009E760;
    }
    // 0x8009E7B0: addiu       $s1, $s1, 0x1E
    ctx->r17 = ADD32(ctx->r17, 0X1E);
    // 0x8009E7B4: jal         0x80068508
    // 0x8009E7B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_12;
    // 0x8009E7B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
L_8009E7BC:
    // 0x8009E7BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8009E7C0: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8009E7C4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8009E7C8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E7CC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8009E7D0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8009E7D4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8009E7D8: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8009E7DC: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8009E7E0: jr          $ra
    // 0x8009E7E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8009E7E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void weather_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB1F0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AB1F4: addiu       $v1, $v1, 0x28D8
    ctx->r3 = ADD32(ctx->r3, 0X28D8);
    // 0x800AB1F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AB1FC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800AB200: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB204: sw          $zero, 0x28D4($at)
    MEM_W(0X28D4, ctx->r1) = 0;
    // 0x800AB208: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AB20C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB210: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800AB214: addiu       $v0, $v0, 0x7C00
    ctx->r2 = ADD32(ctx->r2, 0X7C00);
    // 0x800AB218: sw          $zero, 0x7BB0($at)
    MEM_W(0X7BB0, ctx->r1) = 0;
    // 0x800AB21C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800AB220: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800AB224: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AB228: sra         $t0, $t8, 1
    ctx->r8 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AB22C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB230: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB234: sw          $t0, 0x7C04($at)
    MEM_W(0X7C04, ctx->r1) = ctx->r8;
    // 0x800AB238: addiu       $a0, $a0, 0x2914
    ctx->r4 = ADD32(ctx->r4, 0X2914);
    // 0x800AB23C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800AB240: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800AB244: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB248: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AB24C: sw          $zero, 0x290C($at)
    MEM_W(0X290C, ctx->r1) = 0;
    // 0x800AB250: addiu       $a1, $a1, 0x7BF8
    ctx->r5 = ADD32(ctx->r5, 0X7BF8);
    // 0x800AB254: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AB258: addiu       $t1, $zero, -0x200
    ctx->r9 = ADD32(0, -0X200);
    // 0x800AB25C: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
    // 0x800AB260: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // 0x800AB264: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB268: sw          $zero, 0x2A80($at)
    MEM_W(0X2A80, ctx->r1) = 0;
    // 0x800AB26C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB270: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AB274: sw          $t2, 0x2A84($at)
    MEM_W(0X2A84, ctx->r1) = ctx->r10;
    // 0x800AB278: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AB27C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB280: addiu       $a3, $a3, 0x291C
    ctx->r7 = ADD32(ctx->r7, 0X291C);
    // 0x800AB284: sw          $zero, 0x2A88($at)
    MEM_W(0X2A88, ctx->r1) = 0;
    // 0x800AB288: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800AB28C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AB290: bne         $t3, $zero, L_800AB2F4
    if (ctx->r11 != 0) {
        // 0x800AB294: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AB2F4;
    }
    // 0x800AB294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AB298: jal         0x80076C58
    // 0x800AB29C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x800AB29C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_0:
    // 0x800AB2A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB2A4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AB2A8: addiu       $a3, $a3, 0x291C
    ctx->r7 = ADD32(ctx->r7, 0X291C);
    // 0x800AB2AC: addiu       $a0, $a0, 0x2920
    ctx->r4 = ADD32(ctx->r4, 0X2920);
    // 0x800AB2B0: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800AB2B4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800AB2B8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800AB2BC: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800AB2C0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800AB2C4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AB2C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800AB2CC: beq         $a2, $t6, L_800AB2F4
    if (ctx->r6 == ctx->r14) {
        // 0x800AB2D0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AB2F4;
    }
    // 0x800AB2D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AB2D4: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_800AB2D8:
    // 0x800AB2D8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AB2DC: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800AB2E0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800AB2E4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800AB2E8: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800AB2EC: bne         $a2, $t0, L_800AB2D8
    if (ctx->r6 != ctx->r8) {
        // 0x800AB2F0: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_800AB2D8;
    }
    // 0x800AB2F0: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_800AB2F4:
    // 0x800AB2F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AB2F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB2FC: sw          $zero, 0x7C08($at)
    MEM_W(0X7C08, ctx->r1) = 0;
    // 0x800AB300: jr          $ra
    // 0x800AB304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AB304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void alFxNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064A08: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80064A0C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80064A10: sll         $s0, $a2, 16
    ctx->r16 = S32(ctx->r6 << 16);
    // 0x80064A14: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80064A18: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80064A1C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80064A20: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80064A24: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80064A28: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80064A2C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80064A30: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80064A34: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80064A38: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80064A3C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80064A40: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80064A44: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80064A48: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80064A4C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80064A50: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80064A54: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80064A58: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80064A5C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80064A60: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80064A64: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80064A68: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80064A6C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80064A70: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80064A74: addiu       $a2, $a2, 0x3F94
    ctx->r6 = ADD32(ctx->r6, 0X3F94);
    // 0x80064A78: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80064A7C: jal         0x800CA0B0
    // 0x80064A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80064A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80064A84: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80064A88: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80064A8C: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80064A90: addiu       $t7, $t7, 0x3C30
    ctx->r15 = ADD32(ctx->r15, 0X3C30);
    // 0x80064A94: addiu       $t8, $t8, 0x3FAC
    ctx->r24 = ADD32(ctx->r24, 0X3FAC);
    // 0x80064A98: sw          $t7, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r15;
    // 0x80064A9C: sw          $t8, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r24;
    // 0x80064AA0: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x80064AA4: lbu         $t0, 0x1C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1C);
    // 0x80064AA8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064AAC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80064AB0: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x80064AB4: beq         $at, $zero, L_80064B28
    if (ctx->r1 == 0) {
        // 0x80064AB8: addiu       $s3, $s3, -0x2FD8
        ctx->r19 = ADD32(ctx->r19, -0X2FD8);
            goto L_80064B28;
    }
    // 0x80064AB8: addiu       $s3, $s3, -0x2FD8
    ctx->r19 = ADD32(ctx->r19, -0X2FD8);
    // 0x80064ABC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80064AC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064AC4: addu        $at, $at, $t1
    gpr jr_addend_80064AD0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80064AC8: lw          $t1, 0x6EA0($at)
    ctx->r9 = ADD32(ctx->r1, 0X6EA0);
    // 0x80064ACC: nop

    // 0x80064AD0: jr          $t1
    // 0x80064AD4: nop

    switch (jr_addend_80064AD0 >> 2) {
        case 0: goto L_80064AD8; break;
        case 1: goto L_80064AE4; break;
        case 2: goto L_80064AFC; break;
        case 3: goto L_80064B08; break;
        case 4: goto L_80064AF0; break;
        case 5: goto L_80064B14; break;
        default: switch_error(__func__, 0x80064AD0, 0x800E6EA0);
    }
    // 0x80064AD4: nop

L_80064AD8:
    // 0x80064AD8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064ADC: b           L_80064B28
    // 0x80064AE0: addiu       $s3, $s3, -0x3140
    ctx->r19 = ADD32(ctx->r19, -0X3140);
        goto L_80064B28;
    // 0x80064AE0: addiu       $s3, $s3, -0x3140
    ctx->r19 = ADD32(ctx->r19, -0X3140);
L_80064AE4:
    // 0x80064AE4: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064AE8: b           L_80064B28
    // 0x80064AEC: addiu       $s3, $s3, -0x30D8
    ctx->r19 = ADD32(ctx->r19, -0X30D8);
        goto L_80064B28;
    // 0x80064AEC: addiu       $s3, $s3, -0x30D8
    ctx->r19 = ADD32(ctx->r19, -0X30D8);
L_80064AF0:
    // 0x80064AF0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064AF4: b           L_80064B28
    // 0x80064AF8: addiu       $s3, $s3, -0x3050
    ctx->r19 = ADD32(ctx->r19, -0X3050);
        goto L_80064B28;
    // 0x80064AF8: addiu       $s3, $s3, -0x3050
    ctx->r19 = ADD32(ctx->r19, -0X3050);
L_80064AFC:
    // 0x80064AFC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064B00: b           L_80064B28
    // 0x80064B04: addiu       $s3, $s3, -0x3028
    ctx->r19 = ADD32(ctx->r19, -0X3028);
        goto L_80064B28;
    // 0x80064B04: addiu       $s3, $s3, -0x3028
    ctx->r19 = ADD32(ctx->r19, -0X3028);
L_80064B08:
    // 0x80064B08: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80064B0C: b           L_80064B28
    // 0x80064B10: addiu       $s3, $s3, -0x3000
    ctx->r19 = ADD32(ctx->r19, -0X3000);
        goto L_80064B28;
    // 0x80064B10: addiu       $s3, $s3, -0x3000
    ctx->r19 = ADD32(ctx->r19, -0X3000);
L_80064B14:
    // 0x80064B14: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80064B18: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80064B1C: lw          $s3, 0x20($t3)
    ctx->r19 = MEM_W(ctx->r11, 0X20);
    // 0x80064B20: b           L_80064B2C
    // 0x80064B24: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
        goto L_80064B2C;
    // 0x80064B24: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80064B28:
    // 0x80064B28: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80064B2C:
    // 0x80064B2C: addiu       $fp, $zero, 0x28
    ctx->r30 = ADD32(0, 0X28);
    // 0x80064B30: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x80064B34: multu       $t6, $fp
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064B38: sb          $t4, 0x24($s6)
    MEM_B(0X24, ctx->r22) = ctx->r12;
    // 0x80064B3C: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x80064B40: lui         $s5, 0xFF
    ctx->r21 = S32(0XFF << 16);
    // 0x80064B44: ori         $s5, $s5, 0xFFFF
    ctx->r21 = ctx->r21 | 0XFFFF;
    // 0x80064B48: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80064B4C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80064B50: sw          $t5, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r13;
    // 0x80064B54: mflo        $a0
    ctx->r4 = lo;
    // 0x80064B58: jal         0x80070C9C
    // 0x80064B5C: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80064B5C: nop

    after_1:
    // 0x80064B60: lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X1C);
    // 0x80064B64: sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // 0x80064B68: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80064B6C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80064B70: jal         0x80070C9C
    // 0x80064B74: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80064B74: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
    // 0x80064B78: lw          $t8, 0x1C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X1C);
    // 0x80064B7C: sw          $v0, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->r2;
    // 0x80064B80: sw          $v0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r2;
    // 0x80064B84: beq         $t8, $zero, L_80064BB4
    if (ctx->r24 == 0) {
        // 0x80064B88: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80064BB4;
    }
    // 0x80064B88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80064B8C:
    // 0x80064B8C: lw          $t9, 0x14($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X14);
    // 0x80064B90: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x80064B94: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80064B98: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x80064B9C: lw          $t3, 0x1C($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X1C);
    // 0x80064BA0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80064BA4: andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // 0x80064BA8: sltu        $at, $t2, $t3
    ctx->r1 = ctx->r10 < ctx->r11 ? 1 : 0;
    // 0x80064BAC: bne         $at, $zero, L_80064B8C
    if (ctx->r1 != 0) {
        // 0x80064BB0: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80064B8C;
    }
    // 0x80064BB0: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_80064BB4:
    // 0x80064BB4: lbu         $t4, 0x24($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X24);
    // 0x80064BB8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80064BBC: blez        $t4, L_80064E04
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80064BC0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80064E04;
    }
    // 0x80064BC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80064BC4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80064BC8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80064BCC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80064BD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064BD4: lwc1        $f21, 0x6EB8($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X6EB8);
    // 0x80064BD8: lwc1        $f20, 0x6EBC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6EBC);
    // 0x80064BDC: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80064BE0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_80064BE4:
    // 0x80064BE4: multu       $s4, $fp
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064BE8: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80064BEC: lw          $t5, 0x20($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X20);
    // 0x80064BF0: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80064BF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064BF8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80064BFC: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x80064C00: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80064C04: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x80064C08: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x80064C0C: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x80064C10: addiu       $s1, $t4, 0x1
    ctx->r17 = ADD32(ctx->r12, 0X1);
    // 0x80064C14: mflo        $t6
    ctx->r14 = lo;
    // 0x80064C18: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x80064C1C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80064C20: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80064C24: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80064C28: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80064C2C: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80064C30: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80064C34: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x80064C38: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80064C3C: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x80064C40: addiu       $s1, $t8, 0x1
    ctx->r17 = ADD32(ctx->r24, 0X1);
    // 0x80064C44: sh          $t7, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r15;
    // 0x80064C48: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80064C4C: andi        $t2, $s1, 0xFFFF
    ctx->r10 = ctx->r17 & 0XFFFF;
    // 0x80064C50: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80064C54: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x80064C58: addiu       $s1, $t2, 0x1
    ctx->r17 = ADD32(ctx->r10, 0X1);
    // 0x80064C5C: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    // 0x80064C60: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80064C64: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x80064C68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80064C6C: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80064C70: sh          $t5, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r13;
    // 0x80064C74: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80064C78: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80064C7C: beq         $v0, $zero, L_80064D6C
    if (ctx->r2 == 0) {
        // 0x80064C80: or          $t2, $s1, $zero
        ctx->r10 = ctx->r17 | 0;
            goto L_80064D6C;
    }
    // 0x80064C80: or          $t2, $s1, $zero
    ctx->r10 = ctx->r17 | 0;
    // 0x80064C84: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80064C88: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80064C8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80064C90: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x80064C94: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80064C98: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80064C9C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80064CA0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80064CA4: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x80064CA8: addiu       $s1, $t6, 0x1
    ctx->r17 = ADD32(ctx->r14, 0X1);
    // 0x80064CAC: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x80064CB0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80064CB4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80064CB8: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80064CBC: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80064CC0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80064CC4: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80064CC8: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x80064CCC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80064CD0: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80064CD4: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x80064CD8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80064CDC: bgez        $t4, L_80064CF4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80064CE0: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_80064CF4;
    }
    // 0x80064CE0: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80064CE4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80064CE8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80064CEC: nop

    // 0x80064CF0: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_80064CF4:
    // 0x80064CF4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80064CF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064CFC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80064D00: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x80064D04: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80064D08: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x80064D0C: swc1        $f24, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f24.u32l;
    // 0x80064D10: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80064D14: nop

    // 0x80064D18: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80064D1C: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80064D20: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x80064D24: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80064D28: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80064D2C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80064D30: jal         0x80070C9C
    // 0x80064D34: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80064D34: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x80064D38: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80064D3C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80064D40: jal         0x80070C9C
    // 0x80064D44: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80064D44: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x80064D48: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80064D4C: nop

    // 0x80064D50: sw          $v0, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r2;
    // 0x80064D54: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80064D58: nop

    // 0x80064D5C: swc1        $f26, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f26.u32l;
    // 0x80064D60: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80064D64: b           L_80064D7C
    // 0x80064D68: sw          $s7, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r23;
        goto L_80064D7C;
    // 0x80064D68: sw          $s7, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r23;
L_80064D6C:
    // 0x80064D6C: addiu       $s1, $t2, 0x2
    ctx->r17 = ADD32(ctx->r10, 0X2);
    // 0x80064D70: andi        $t3, $s1, 0xFFFF
    ctx->r11 = ctx->r17 & 0XFFFF;
    // 0x80064D74: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80064D78: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_80064D7C:
    // 0x80064D7C: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80064D80: addu        $s2, $s3, $t4
    ctx->r18 = ADD32(ctx->r19, ctx->r12);
    // 0x80064D84: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80064D88: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80064D8C: beq         $t5, $zero, L_80064DDC
    if (ctx->r13 == 0) {
        // 0x80064D90: nop
    
            goto L_80064DDC;
    }
    // 0x80064D90: nop

    // 0x80064D94: jal         0x80070C9C
    // 0x80064D98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x80064D98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
    // 0x80064D9C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80064DA0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80064DA4: jal         0x80070C9C
    // 0x80064DA8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x80064DA8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_6:
    // 0x80064DAC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80064DB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064DB4: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    // 0x80064DB8: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x80064DBC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80064DC0: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x80064DC4: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80064DC8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80064DCC: jal         0x80064950
    // 0x80064DD0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    init_lpfilter(rdram, ctx);
        goto after_7;
    // 0x80064DD0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    after_7:
    // 0x80064DD4: b           L_80064DF0
    // 0x80064DD8: lbu         $t2, 0x24($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X24);
        goto L_80064DF0;
    // 0x80064DD8: lbu         $t2, 0x24($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X24);
L_80064DDC:
    // 0x80064DDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064DE0: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x80064DE4: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80064DE8: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80064DEC: lbu         $t2, 0x24($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X24);
L_80064DF0:
    // 0x80064DF0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80064DF4: andi        $t1, $s4, 0xFFFF
    ctx->r9 = ctx->r20 & 0XFFFF;
    // 0x80064DF8: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80064DFC: bne         $at, $zero, L_80064BE4
    if (ctx->r1 != 0) {
        // 0x80064E00: or          $s4, $t1, $zero
        ctx->r20 = ctx->r9 | 0;
            goto L_80064BE4;
    }
    // 0x80064E00: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
L_80064E04:
    // 0x80064E04: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80064E08: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80064E0C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80064E10: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80064E14: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80064E18: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80064E1C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80064E20: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80064E24: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80064E28: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80064E2C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80064E30: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80064E34: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80064E38: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80064E3C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80064E40: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80064E44: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80064E48: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80064E4C: jr          $ra
    // 0x80064E50: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80064E50: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void bgload_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7448: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C744C: lw          $v0, 0x377C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X377C);
    // 0x800C7450: jr          $ra
    // 0x800C7454: nop

    return;
    // 0x800C7454: nop

;}
RECOMP_FUNC void compute_grid_overlap_mask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800314DC: beq         $a0, $zero, L_800315F8
    if (ctx->r4 == 0) {
        // 0x800314E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800315F8;
    }
    // 0x800314E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800314E4: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x800314E8: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800314EC: lh          $t1, 0x4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4);
    // 0x800314F0: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800314F4: lh          $t2, 0x6($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X6);
    // 0x800314F8: beq         $at, $zero, L_80031504
    if (ctx->r1 == 0) {
        // 0x800314FC: lh          $t3, 0xA($a0)
        ctx->r11 = MEM_H(ctx->r4, 0XA);
            goto L_80031504;
    }
    // 0x800314FC: lh          $t3, 0xA($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XA);
    // 0x80031500: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_80031504:
    // 0x80031504: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80031508: beql        $at, $zero, L_80031518
    if (ctx->r1 == 0) {
        // 0x8003150C: slt         $at, $t5, $t1
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80031518;
    }
    goto skip_0;
    // 0x8003150C: slt         $at, $t5, $t1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
    skip_0:
    // 0x80031510: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80031514: slt         $at, $t5, $t1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
L_80031518:
    // 0x80031518: beql        $at, $zero, L_80031528
    if (ctx->r1 == 0) {
        // 0x8003151C: slt         $at, $a2, $t1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80031528;
    }
    goto skip_1;
    // 0x8003151C: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    skip_1:
    // 0x80031520: or          $t5, $t1, $zero
    ctx->r13 = ctx->r9 | 0;
    // 0x80031524: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
L_80031528:
    // 0x80031528: beql        $at, $zero, L_80031538
    if (ctx->r1 == 0) {
        // 0x8003152C: slt         $at, $t2, $a3
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80031538;
    }
    goto skip_2;
    // 0x8003152C: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    skip_2:
    // 0x80031530: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80031534: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
L_80031538:
    // 0x80031538: beql        $at, $zero, L_80031548
    if (ctx->r1 == 0) {
        // 0x8003153C: slt         $at, $t2, $a1
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80031548;
    }
    goto skip_3;
    // 0x8003153C: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    skip_3:
    // 0x80031540: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80031544: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
L_80031548:
    // 0x80031548: beql        $at, $zero, L_80031558
    if (ctx->r1 == 0) {
        // 0x8003154C: slt         $at, $t3, $t5
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
            goto L_80031558;
    }
    goto skip_4;
    // 0x8003154C: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    skip_4:
    // 0x80031550: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80031554: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
L_80031558:
    // 0x80031558: beql        $at, $zero, L_80031568
    if (ctx->r1 == 0) {
        // 0x8003155C: slt         $at, $t3, $a2
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80031568;
    }
    goto skip_5;
    // 0x8003155C: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    skip_5:
    // 0x80031560: or          $t5, $t3, $zero
    ctx->r13 = ctx->r11 | 0;
    // 0x80031564: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
L_80031568:
    // 0x80031568: beql        $at, $zero, L_80031578
    if (ctx->r1 == 0) {
        // 0x8003156C: sub         $t2, $t2, $t0
        ctx->r10 = SUB32(ctx->r10, ctx->r8);
            goto L_80031578;
    }
    goto skip_6;
    // 0x8003156C: sub         $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    skip_6:
    // 0x80031570: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80031574: sub         $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
L_80031578:
    // 0x80031578: sra         $t2, $t2, 3
    ctx->r10 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8003157C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80031580: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80031584: add         $t4, $t2, $t0
    ctx->r12 = ADD32(ctx->r10, ctx->r8);
L_80031588:
    // 0x80031588: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003158C: bne         $at, $zero, L_800315A0
    if (ctx->r1 != 0) {
        // 0x80031590: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800315A0;
    }
    // 0x80031590: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80031594: bnel        $at, $zero, L_800315A4
    if (ctx->r1 != 0) {
        // 0x80031598: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_800315A4;
    }
    goto skip_7;
    // 0x80031598: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    skip_7:
    // 0x8003159C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_800315A0:
    // 0x800315A0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_800315A4:
    // 0x800315A4: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800315A8: add         $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800315AC: bne         $at, $zero, L_80031588
    if (ctx->r1 != 0) {
        // 0x800315B0: add         $t0, $t0, $t2
        ctx->r8 = ADD32(ctx->r8, ctx->r10);
            goto L_80031588;
    }
    // 0x800315B0: add         $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x800315B4: sub         $t2, $t3, $t1
    ctx->r10 = SUB32(ctx->r11, ctx->r9);
    // 0x800315B8: sra         $t2, $t2, 3
    ctx->r10 = S32(SIGNED(ctx->r10) >> 3);
    // 0x800315BC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800315C0: add         $t4, $t2, $t1
    ctx->r12 = ADD32(ctx->r10, ctx->r9);
    // 0x800315C4: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_800315C8:
    // 0x800315C8: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800315CC: bne         $at, $zero, L_800315E0
    if (ctx->r1 != 0) {
        // 0x800315D0: slt         $at, $t5, $t0
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800315E0;
    }
    // 0x800315D0: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800315D4: bnel        $at, $zero, L_800315E4
    if (ctx->r1 != 0) {
        // 0x800315D8: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_800315E4;
    }
    goto skip_8;
    // 0x800315D8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    skip_8:
    // 0x800315DC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_800315E0:
    // 0x800315E0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_800315E4:
    // 0x800315E4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800315E8: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800315EC: add         $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800315F0: bne         $at, $zero, L_800315C8
    if (ctx->r1 != 0) {
        // 0x800315F4: add         $t0, $t0, $t2
        ctx->r8 = ADD32(ctx->r8, ctx->r10);
            goto L_800315C8;
    }
    // 0x800315F4: add         $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
L_800315F8:
    // 0x800315F8: jr          $ra
    // 0x800315FC: nop

    return;
    // 0x800315FC: nop

;}
RECOMP_FUNC void rumble_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072348: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007234C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80072350: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80072354: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80072358: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007235C: slti        $at, $t8, 0x13
    ctx->r1 = SIGNED(ctx->r24) < 0X13 ? 1 : 0;
    // 0x80072360: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80072364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072368: beq         $at, $zero, L_80072414
    if (ctx->r1 == 0) {
        // 0x8007236C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80072414;
    }
    // 0x8007236C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80072370: bltz        $t7, L_80072414
    if (SIGNED(ctx->r15) < 0) {
        // 0x80072374: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_80072414;
    }
    // 0x80072374: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80072378: beq         $at, $zero, L_80072418
    if (ctx->r1 == 0) {
        // 0x8007237C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80072418;
    }
    // 0x8007237C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072380: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
    // 0x80072384: jal         0x80072250
    // 0x80072388: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    input_get_id(rdram, ctx);
        goto after_0;
    // 0x80072388: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x8007238C: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x80072390: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80072394: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80072398: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8007239C: addiu       $t1, $t1, 0x41B8
    ctx->r9 = ADD32(ctx->r9, 0X41B8);
    // 0x800723A0: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800723A4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800723A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800723AC: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800723B0: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x800723B4: bne         $a2, $t2, L_800723E8
    if (ctx->r6 != ctx->r10) {
        // 0x800723B8: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800723E8;
    }
    // 0x800723B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800723BC: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x800723C0: addiu       $t4, $zero, -0x12C
    ctx->r12 = ADD32(0, -0X12C);
    // 0x800723C4: bgez        $t3, L_800723D0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800723C8: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800723D0;
    }
    // 0x800723C8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800723CC: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
L_800723D0:
    // 0x800723D0: lw          $t5, 0x41E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X41E0);
    // 0x800723D4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800723D8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800723DC: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800723E0: b           L_80072414
    // 0x800723E4: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
        goto L_80072414;
    // 0x800723E4: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
L_800723E8:
    // 0x800723E8: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800723EC: lw          $t0, 0x41E0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X41E0);
    // 0x800723F0: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x800723F4: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x800723F8: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x800723FC: nop

    // 0x80072400: beq         $a1, $zero, L_80072418
    if (ctx->r5 == 0) {
        // 0x80072404: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80072418;
    }
    // 0x80072404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072408: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8007240C: jal         0x80072578
    // 0x80072410: nop

    rumble_start(rdram, ctx);
        goto after_1;
    // 0x80072410: nop

    after_1:
L_80072414:
    // 0x80072414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80072418:
    // 0x80072418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007241C: jr          $ra
    // 0x80072420: nop

    return;
    // 0x80072420: nop

;}
RECOMP_FUNC void draw_text_plain_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4404: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4408: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800C440C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C4410: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C4414: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4418: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C441C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C4420: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4424: lw          $a1, -0x5818($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5818);
    // 0x800C4428: jal         0x800C45A4
    // 0x800C442C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C442C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800C4430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4438: jr          $ra
    // 0x800C443C: nop

    return;
    // 0x800C443C: nop

;}
