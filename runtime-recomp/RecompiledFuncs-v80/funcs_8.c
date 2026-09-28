#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void cam_get_fov(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800660E0: lwc1        $f0, 0xD10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XD10);
    // 0x800660E4: jr          $ra
    // 0x800660E8: nop

    return;
    // 0x800660E8: nop

;}
RECOMP_FUNC void transition_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0724: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0728: addiu       $v0, $v0, 0x31C0
    ctx->r2 = ADD32(ctx->r2, 0X31C0);
    // 0x800C072C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800C0730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0734: beq         $a0, $zero, L_800C0764
    if (ctx->r4 == 0) {
        // 0x800C0738: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C0764;
    }
    // 0x800C0738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C073C: jal         0x80071140
    // 0x800C0740: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800C0740: nop

    after_0:
    // 0x800C0744: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0748: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C074C: addiu       $v1, $v1, 0x31C8
    ctx->r3 = ADD32(ctx->r3, 0X31C8);
    // 0x800C0750: addiu       $v0, $v0, 0x31C0
    ctx->r2 = ADD32(ctx->r2, 0X31C0);
    // 0x800C0754: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C0758: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C075C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C0760: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_800C0764:
    // 0x800C0764: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C076C: sw          $zero, 0x31AC($at)
    MEM_W(0X31AC, ctx->r1) = 0;
    // 0x800C0770: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0774: sw          $zero, 0x31D0($at)
    MEM_W(0X31D0, ctx->r1) = 0;
    // 0x800C0778: jr          $ra
    // 0x800C077C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C077C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void obj_init_rgbalight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800403A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800403AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800403B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800403B4: jal         0x80031CAC
    // 0x800403B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    light_add_from_level_object_entry(rdram, ctx);
        goto after_0;
    // 0x800403B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800403BC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800403C0: nop

    // 0x800403C4: sw          $v0, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r2;
    // 0x800403C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800403CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800403D0: jr          $ra
    // 0x800403D4: nop

    return;
    // 0x800403D4: nop

;}
RECOMP_FUNC void music_sequence_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002570: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80002574: lw          $t6, -0x39D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X39D0);
    // 0x80002578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000257C: bne         $a0, $t6, L_800025BC
    if (ctx->r4 != ctx->r14) {
        // 0x80002580: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800025BC;
    }
    // 0x80002580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002584: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002588: lbu         $t7, 0x5D40($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5D40);
    // 0x8000258C: nop

    // 0x80002590: beq         $t7, $zero, L_800025BC
    if (ctx->r15 == 0) {
        // 0x80002594: nop
    
            goto L_800025BC;
    }
    // 0x80002594: nop

    // 0x80002598: jal         0x800C85D0
    // 0x8000259C: nop

    alCSPStop(rdram, ctx);
        goto after_0;
    // 0x8000259C: nop

    after_0:
    // 0x800025A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800025A4: sb          $zero, 0x5D40($at)
    MEM_B(0X5D40, ctx->r1) = 0;
    // 0x800025A8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800025AC: sb          $zero, 0x5D04($at)
    MEM_B(0X5D04, ctx->r1) = 0;
    // 0x800025B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800025B4: b           L_800025F8
    // 0x800025B8: sb          $zero, -0x39A4($at)
    MEM_B(-0X39A4, ctx->r1) = 0;
        goto L_800025F8;
    // 0x800025B8: sb          $zero, -0x39A4($at)
    MEM_B(-0X39A4, ctx->r1) = 0;
L_800025BC:
    // 0x800025BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800025C0: lw          $t8, -0x39CC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X39CC);
    // 0x800025C4: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800025C8: bne         $a0, $t8, L_800025FC
    if (ctx->r4 != ctx->r24) {
        // 0x800025CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800025FC;
    }
    // 0x800025CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800025D0: lbu         $t9, 0x5D41($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X5D41);
    // 0x800025D4: nop

    // 0x800025D8: beq         $t9, $zero, L_800025FC
    if (ctx->r25 == 0) {
        // 0x800025DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800025FC;
    }
    // 0x800025DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800025E0: jal         0x800C85D0
    // 0x800025E4: nop

    alCSPStop(rdram, ctx);
        goto after_1;
    // 0x800025E4: nop

    after_1:
    // 0x800025E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800025EC: sb          $zero, 0x5D41($at)
    MEM_B(0X5D41, ctx->r1) = 0;
    // 0x800025F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800025F4: sb          $zero, -0x39A0($at)
    MEM_B(-0X39A0, ctx->r1) = 0;
L_800025F8:
    // 0x800025F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800025FC:
    // 0x800025FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002600: jr          $ra
    // 0x80002604: nop

    return;
    // 0x80002604: nop

;}
RECOMP_FUNC void alInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87EC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C87F0: addiu       $v0, $v0, 0x3780
    ctx->r2 = ADD32(ctx->r2, 0X3780);
    // 0x800C87F4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C87F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C87FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8800: bnel        $t6, $zero, L_800C8814
    if (ctx->r14 != 0) {
        // 0x800C8804: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8814;
    }
    goto skip_0;
    // 0x800C8804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C8808: jal         0x80065130
    // 0x800C880C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    alSynNew(rdram, ctx);
        goto after_0;
    // 0x800C880C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x800C8810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8814:
    // 0x800C8814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8818: jr          $ra
    // 0x800C881C: nop

    return;
    // 0x800C881C: nop

;}
RECOMP_FUNC void leveltable_world_level_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B054: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006B058: lw          $a1, 0x1170($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1170);
    // 0x8006B05C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006B060: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x8006B064: sra         $a0, $t6, 24
    ctx->r4 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006B068: blez        $a1, L_8006B0A4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006B06C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006B0A4;
    }
    // 0x8006B06C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006B070: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006B074: sll         $a3, $a1, 2
    ctx->r7 = S32(ctx->r5 << 2);
    // 0x8006B078: subu        $a3, $a3, $a1
    ctx->r7 = SUB32(ctx->r7, ctx->r5);
    // 0x8006B07C: lw          $a2, 0x117C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X117C);
    // 0x8006B080: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x8006B084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006B088:
    // 0x8006B088: lb          $t8, 0x0($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X0);
    // 0x8006B08C: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8006B090: bne         $a0, $t8, L_8006B09C
    if (ctx->r4 != ctx->r24) {
        // 0x8006B094: slt         $at, $v0, $a3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8006B09C;
    }
    // 0x8006B094: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8006B098: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006B09C:
    // 0x8006B09C: bne         $at, $zero, L_8006B088
    if (ctx->r1 != 0) {
        // 0x8006B0A0: addiu       $a2, $a2, 0x6
        ctx->r6 = ADD32(ctx->r6, 0X6);
            goto L_8006B088;
    }
    // 0x8006B0A0: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
L_8006B0A4:
    // 0x8006B0A4: jr          $ra
    // 0x8006B0A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8006B0A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800BBF78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBF78: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BBF7C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800BBF80: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800BBF84: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800BBF88: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800BBF8C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800BBF90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800BBF94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800BBF98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800BBF9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800BBFA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BBFA4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800BBFA8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BBFAC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BBFB0: lw          $t7, -0x6038($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6038);
    // 0x800BBFB4: lw          $t8, -0x6010($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6010);
    // 0x800BBFB8: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800BBFBC: lw          $s4, 0x8($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X8);
    // 0x800BBFC0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800BBFC4: beq         $t8, $zero, L_800BBFD4
    if (ctx->r24 == 0) {
        // 0x800BBFC8: sw          $t7, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r15;
            goto L_800BBFD4;
    }
    // 0x800BBFC8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x800BBFCC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800BBFD0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800BBFD4:
    // 0x800BBFD4: lh          $t6, 0x0($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X0);
    // 0x800BBFD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBFDC: addiu       $v1, $v1, -0x5F40
    ctx->r3 = ADD32(ctx->r3, -0X5F40);
    // 0x800BBFE0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BBFE4: lh          $t8, 0x6($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X6);
    // 0x800BBFE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BBFEC: addiu       $a0, $a0, -0x5F38
    ctx->r4 = ADD32(ctx->r4, -0X5F38);
    // 0x800BBFF0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800BBFF4: lh          $t7, 0x4($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X4);
    // 0x800BBFF8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BBFFC: addiu       $a2, $a2, -0x5F3C
    ctx->r6 = ADD32(ctx->r6, -0X5F3C);
    // 0x800BC000: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800BC004: lh          $t9, 0xA($s4)
    ctx->r25 = MEM_H(ctx->r20, 0XA);
    // 0x800BC008: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BC00C: addiu       $t1, $t1, -0x5F34
    ctx->r9 = ADD32(ctx->r9, -0X5F34);
    // 0x800BC010: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800BC014: lh          $t6, 0x1A($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC018: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x800BC01C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800BC020: bne         $at, $zero, L_800BC0AC
    if (ctx->r1 != 0) {
        // 0x800BC024: lui         $s6, 0x8013
        ctx->r22 = S32(0X8013 << 16);
            goto L_800BC0AC;
    }
    // 0x800BC024: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800BC028: addiu       $s0, $s4, 0xC
    ctx->r16 = ADD32(ctx->r20, 0XC);
L_800BC02C:
    // 0x800BC02C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BC030: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800BC034: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x800BC038: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BC03C: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x800BC040: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BC044: beq         $at, $zero, L_800BC050
    if (ctx->r1 == 0) {
        // 0x800BC048: nop
    
            goto L_800BC050;
    }
    // 0x800BC048: nop

    // 0x800BC04C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800BC050:
    // 0x800BC050: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x800BC054: nop

    // 0x800BC058: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BC05C: beq         $at, $zero, L_800BC068
    if (ctx->r1 == 0) {
        // 0x800BC060: nop
    
            goto L_800BC068;
    }
    // 0x800BC060: nop

    // 0x800BC064: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_800BC068:
    // 0x800BC068: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x800BC06C: nop

    // 0x800BC070: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BC074: beq         $at, $zero, L_800BC080
    if (ctx->r1 == 0) {
        // 0x800BC078: nop
    
            goto L_800BC080;
    }
    // 0x800BC078: nop

    // 0x800BC07C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800BC080:
    // 0x800BC080: lh          $v0, 0xA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA);
    // 0x800BC084: nop

    // 0x800BC088: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BC08C: beq         $at, $zero, L_800BC098
    if (ctx->r1 == 0) {
        // 0x800BC090: nop
    
            goto L_800BC098;
    }
    // 0x800BC090: nop

    // 0x800BC094: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_800BC098:
    // 0x800BC098: lh          $t7, 0x1A($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC09C: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC0A0: slt         $at, $ra, $t7
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC0A4: bne         $at, $zero, L_800BC02C
    if (ctx->r1 != 0) {
        // 0x800BC0A8: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800BC02C;
    }
    // 0x800BC0A8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800BC0AC:
    // 0x800BC0AC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BC0B0: lw          $a0, -0x5F50($t9)
    ctx->r4 = MEM_W(ctx->r25, -0X5F50);
    // 0x800BC0B4: addiu       $s6, $s6, -0x5F30
    ctx->r22 = ADD32(ctx->r22, -0X5F30);
    // 0x800BC0B8: sw          $a0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r4;
    // 0x800BC0BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BC0C0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BC0C4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BC0C8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800BC0CC: lw          $t0, -0x5F34($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5F34);
    // 0x800BC0D0: lw          $a1, -0x5F3C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5F3C);
    // 0x800BC0D4: lw          $a3, -0x5F38($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5F38);
    // 0x800BC0D8: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BC0DC: beq         $at, $zero, L_800BC104
    if (ctx->r1 == 0) {
        // 0x800BC0E0: lui         $s5, 0x8013
        ctx->r21 = S32(0X8013 << 16);
            goto L_800BC104;
    }
    // 0x800BC0E0: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800BC0E4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BC0E8: lw          $a2, -0x5F58($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5F58);
    // 0x800BC0EC: nop

L_800BC0F0:
    // 0x800BC0F0: subu        $t6, $a0, $a2
    ctx->r14 = SUB32(ctx->r4, ctx->r6);
    // 0x800BC0F4: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BC0F8: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x800BC0FC: bne         $at, $zero, L_800BC0F0
    if (ctx->r1 != 0) {
        // 0x800BC100: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800BC0F0;
    }
    // 0x800BC100: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_800BC104:
    // 0x800BC104: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BC108: lw          $t8, -0x5F4C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5F4C);
    // 0x800BC10C: addiu       $s5, $s5, -0x5F2C
    ctx->r21 = ADD32(ctx->r21, -0X5F2C);
    // 0x800BC110: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BC114: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x800BC118: lw          $a2, -0x5F58($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5F58);
    // 0x800BC11C: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BC120: beq         $at, $zero, L_800BC148
    if (ctx->r1 == 0) {
        // 0x800BC124: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800BC148;
    }
    // 0x800BC124: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800BC128: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC12C: lw          $v1, -0x5F54($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5F54);
    // 0x800BC130: nop

L_800BC134:
    // 0x800BC134: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x800BC138: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC13C: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x800BC140: bne         $at, $zero, L_800BC134
    if (ctx->r1 != 0) {
        // 0x800BC144: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800BC134;
    }
    // 0x800BC144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800BC148:
    // 0x800BC148: subu        $t9, $a3, $a0
    ctx->r25 = SUB32(ctx->r7, ctx->r4);
    // 0x800BC14C: div         $zero, $t9, $a2
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r6)));
    // 0x800BC150: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800BC154: addiu       $fp, $fp, -0x5F54
    ctx->r30 = ADD32(ctx->r30, -0X5F54);
    // 0x800BC158: subu        $t7, $t0, $v0
    ctx->r15 = SUB32(ctx->r8, ctx->r2);
    // 0x800BC15C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800BC160: addiu       $s7, $s7, -0x5F28
    ctx->r23 = ADD32(ctx->r23, -0X5F28);
    // 0x800BC164: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800BC168: addiu       $s2, $s2, 0x30D4
    ctx->r18 = ADD32(ctx->r18, 0X30D4);
    // 0x800BC16C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800BC170: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800BC174: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BC178: addiu       $s1, $s1, -0x5F24
    ctx->r17 = ADD32(ctx->r17, -0X5F24);
    // 0x800BC17C: addiu       $s0, $s0, 0x318C
    ctx->r16 = ADD32(ctx->r16, 0X318C);
    // 0x800BC180: bne         $a2, $zero, L_800BC18C
    if (ctx->r6 != 0) {
        // 0x800BC184: nop
    
            goto L_800BC18C;
    }
    // 0x800BC184: nop

    // 0x800BC188: break       7
    do_break(2148254088);
L_800BC18C:
    // 0x800BC18C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC190: bne         $a2, $at, L_800BC1A4
    if (ctx->r6 != ctx->r1) {
        // 0x800BC194: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC1A4;
    }
    // 0x800BC194: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC198: bne         $t9, $at, L_800BC1A4
    if (ctx->r25 != ctx->r1) {
        // 0x800BC19C: nop
    
            goto L_800BC1A4;
    }
    // 0x800BC19C: nop

    // 0x800BC1A0: break       6
    do_break(2148254112);
L_800BC1A4:
    // 0x800BC1A4: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800BC1A8: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC1AC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BC1B0: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x800BC1B4: div         $zero, $t7, $t9
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r25)));
    // 0x800BC1B8: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x800BC1BC: bne         $t9, $zero, L_800BC1C8
    if (ctx->r25 != 0) {
        // 0x800BC1C0: nop
    
            goto L_800BC1C8;
    }
    // 0x800BC1C0: nop

    // 0x800BC1C4: break       7
    do_break(2148254148);
L_800BC1C8:
    // 0x800BC1C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC1CC: bne         $t9, $at, L_800BC1E0
    if (ctx->r25 != ctx->r1) {
        // 0x800BC1D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC1E0;
    }
    // 0x800BC1D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC1D4: bne         $t7, $at, L_800BC1E0
    if (ctx->r15 != ctx->r1) {
        // 0x800BC1D8: nop
    
            goto L_800BC1E0;
    }
    // 0x800BC1D8: nop

    // 0x800BC1DC: break       6
    do_break(2148254172);
L_800BC1E0:
    // 0x800BC1E0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800BC1E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC1E8: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BC1EC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BC1F0: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC1F4: mflo        $t9
    ctx->r25 = lo;
    // 0x800BC1F8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BC1FC: beq         $a1, $zero, L_800BC214
    if (ctx->r5 == 0) {
        // 0x800BC200: sw          $t6, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r14;
            goto L_800BC214;
    }
    // 0x800BC200: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800BC204: jal         0x80071140
    // 0x800BC208: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800BC208: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800BC20C: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x800BC210: nop

L_800BC214:
    // 0x800BC214: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800BC218: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800BC21C: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC220: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800BC224: mflo        $a0
    ctx->r4 = lo;
    // 0x800BC228: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BC22C: jal         0x80070C9C
    // 0x800BC230: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800BC230: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x800BC234: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800BC238: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BC23C: lw          $a0, 0x30D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30D8);
    // 0x800BC240: nop

    // 0x800BC244: beq         $a0, $zero, L_800BC254
    if (ctx->r4 == 0) {
        // 0x800BC248: nop
    
            goto L_800BC254;
    }
    // 0x800BC248: nop

    // 0x800BC24C: jal         0x80071140
    // 0x800BC250: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800BC250: nop

    after_2:
L_800BC254:
    // 0x800BC254: lh          $t9, 0x1A($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC258: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800BC25C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800BC260: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x800BC264: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BC268: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x800BC26C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800BC270: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800BC274: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800BC278: jal         0x80070C9C
    // 0x800BC27C: addiu       $a0, $a0, 0x880
    ctx->r4 = ADD32(ctx->r4, 0X880);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800BC27C: addiu       $a0, $a0, 0x880
    ctx->r4 = ADD32(ctx->r4, 0X880);
    after_3:
    // 0x800BC280: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC284: sw          $v0, 0x30D8($at)
    MEM_W(0X30D8, ctx->r1) = ctx->r2;
    // 0x800BC288: lh          $t8, 0x1A($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC28C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BC290: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800BC294: lw          $t9, 0x30D8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30D8);
    // 0x800BC298: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800BC29C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BC2A0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BC2A4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800BC2A8: addiu       $a1, $a1, 0x3190
    ctx->r5 = ADD32(ctx->r5, 0X3190);
    // 0x800BC2AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BC2B0: addiu       $t9, $t7, 0x800
    ctx->r25 = ADD32(ctx->r15, 0X800);
    // 0x800BC2B4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800BC2B8: addiu       $a0, $a0, 0x3194
    ctx->r4 = ADD32(ctx->r4, 0X3194);
    // 0x800BC2BC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800BC2C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BC2C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800BC2C8: addiu       $t7, $t9, 0x80
    ctx->r15 = ADD32(ctx->r25, 0X80);
    // 0x800BC2CC: addiu       $v1, $v1, 0x3184
    ctx->r3 = ADD32(ctx->r3, 0X3184);
    // 0x800BC2D0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BC2D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BC2D8: blez        $t9, L_800BC30C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BC2DC: or          $ra, $zero, $zero
        ctx->r31 = 0 | 0;
            goto L_800BC30C;
    }
    // 0x800BC2DC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800BC2E0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800BC2E4:
    // 0x800BC2E4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BC2E8: nop

    // 0x800BC2EC: addu        $t7, $t6, $ra
    ctx->r15 = ADD32(ctx->r14, ctx->r31);
    // 0x800BC2F0: sb          $v0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r2;
    // 0x800BC2F4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800BC2F8: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC2FC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BC300: slt         $at, $ra, $t9
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BC304: bne         $at, $zero, L_800BC2E4
    if (ctx->r1 != 0) {
        // 0x800BC308: nop
    
            goto L_800BC2E4;
    }
    // 0x800BC308: nop

L_800BC30C:
    // 0x800BC30C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BC310:
    // 0x800BC310: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800BC314: nop

    // 0x800BC318: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800BC31C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC320: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800BC324: bne         $at, $zero, L_800BC310
    if (ctx->r1 != 0) {
        // 0x800BC328: sw          $zero, 0x0($t7)
        MEM_W(0X0, ctx->r15) = 0;
            goto L_800BC310;
    }
    // 0x800BC328: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800BC32C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC330: sw          $zero, 0x3188($at)
    MEM_W(0X3188, ctx->r1) = 0;
    // 0x800BC334: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800BC338: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800BC33C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800BC340: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC344: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC348: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800BC34C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800BC350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BC354: addiu       $v1, $v1, -0x5E18
    ctx->r3 = ADD32(ctx->r3, -0X5E18);
    // 0x800BC358: addiu       $s4, $s4, -0x5F58
    ctx->r20 = ADD32(ctx->r20, -0X5F58);
    // 0x800BC35C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800BC360: lui         $t3, 0x40
    ctx->r11 = S32(0X40 << 16);
    // 0x800BC364: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800BC368: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC36C: blez        $t6, L_800BC3A4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BC370: nop
    
            goto L_800BC3A4;
    }
    // 0x800BC370: nop

L_800BC374:
    // 0x800BC374: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800BC378: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC37C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800BC380: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BC384: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BC388: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800BC38C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC390: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC394: mflo        $t7
    ctx->r15 = lo;
    // 0x800BC398: slt         $at, $ra, $t7
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC39C: bne         $at, $zero, L_800BC374
    if (ctx->r1 != 0) {
        // 0x800BC3A0: nop
    
            goto L_800BC374;
    }
    // 0x800BC3A0: nop

L_800BC3A4:
    // 0x800BC3A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BC3A8: addiu       $v0, $v0, -0x5F18
    ctx->r2 = ADD32(ctx->r2, -0X5F18);
L_800BC3AC:
    // 0x800BC3AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC3B0: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800BC3B4: bne         $at, $zero, L_800BC3AC
    if (ctx->r1 != 0) {
        // 0x800BC3B8: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800BC3AC;
    }
    // 0x800BC3B8: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800BC3BC: lh          $t9, 0x1A($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC3C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BC3C4: addiu       $v0, $v0, -0x5F20
    ctx->r2 = ADD32(ctx->r2, -0X5F20);
    // 0x800BC3C8: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800BC3CC: blez        $t9, L_800BC698
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BC3D0: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_800BC698;
    }
    // 0x800BC3D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BC3D4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800BC3D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BC3DC: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x800BC3E0: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800BC3E4:
    // 0x800BC3E4: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x800BC3E8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800BC3EC: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x800BC3F0: subu        $t1, $t7, $a0
    ctx->r9 = SUB32(ctx->r15, ctx->r4);
    // 0x800BC3F4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800BC3F8: div         $zero, $t1, $a2
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r6)));
    // 0x800BC3FC: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x800BC400: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x800BC404: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x800BC408: subu        $t2, $t8, $v0
    ctx->r10 = SUB32(ctx->r24, ctx->r2);
    // 0x800BC40C: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x800BC410: bne         $a2, $zero, L_800BC41C
    if (ctx->r6 != 0) {
        // 0x800BC414: nop
    
            goto L_800BC41C;
    }
    // 0x800BC414: nop

    // 0x800BC418: break       7
    do_break(2148254744);
L_800BC41C:
    // 0x800BC41C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC420: bne         $a2, $at, L_800BC434
    if (ctx->r6 != ctx->r1) {
        // 0x800BC424: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC434;
    }
    // 0x800BC424: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC428: bne         $t1, $at, L_800BC434
    if (ctx->r9 != ctx->r1) {
        // 0x800BC42C: nop
    
            goto L_800BC434;
    }
    // 0x800BC42C: nop

    // 0x800BC430: break       6
    do_break(2148254768);
L_800BC434:
    // 0x800BC434: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800BC438: lh          $t5, 0x20($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X20);
    // 0x800BC43C: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC440: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800BC444: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BC448: mflo        $t9
    ctx->r25 = lo;
    // 0x800BC44C: nop

    // 0x800BC450: nop

    // 0x800BC454: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC458: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC45C: addu        $t1, $t6, $a0
    ctx->r9 = ADD32(ctx->r14, ctx->r4);
    // 0x800BC460: nop

    // 0x800BC464: div         $zero, $t2, $v1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r3)));
    // 0x800BC468: bne         $v1, $zero, L_800BC474
    if (ctx->r3 != 0) {
        // 0x800BC46C: nop
    
            goto L_800BC474;
    }
    // 0x800BC46C: nop

    // 0x800BC470: break       7
    do_break(2148254832);
L_800BC474:
    // 0x800BC474: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC478: bne         $v1, $at, L_800BC48C
    if (ctx->r3 != ctx->r1) {
        // 0x800BC47C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC48C;
    }
    // 0x800BC47C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC480: bne         $t2, $at, L_800BC48C
    if (ctx->r10 != ctx->r1) {
        // 0x800BC484: nop
    
            goto L_800BC48C;
    }
    // 0x800BC484: nop

    // 0x800BC488: break       6
    do_break(2148254856);
L_800BC48C:
    // 0x800BC48C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BC490: nop

    // 0x800BC494: nop

    // 0x800BC498: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC49C: mflo        $t8
    ctx->r24 = lo;
    // 0x800BC4A0: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800BC4A4: blez        $t5, L_800BC504
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800BC4A8: nop
    
            goto L_800BC504;
    }
    // 0x800BC4A8: nop

    // 0x800BC4AC: sll         $a2, $t5, 2
    ctx->r6 = S32(ctx->r13 << 2);
    // 0x800BC4B0: subu        $a2, $a2, $t5
    ctx->r6 = SUB32(ctx->r6, ctx->r13);
    // 0x800BC4B4: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x800BC4B8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800BC4BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800BC4C0:
    // 0x800BC4C0: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x800BC4C4: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800BC4C8: andi        $t9, $a0, 0x2000
    ctx->r25 = ctx->r4 & 0X2000;
    // 0x800BC4CC: beq         $t9, $zero, L_800BC4FC
    if (ctx->r25 == 0) {
        // 0x800BC4D0: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800BC4FC;
    }
    // 0x800BC4D0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BC4D4: and         $t6, $a0, $t3
    ctx->r14 = ctx->r4 & ctx->r11;
    // 0x800BC4D8: beq         $t6, $zero, L_800BC4FC
    if (ctx->r14 == 0) {
        // 0x800BC4DC: nop
    
            goto L_800BC4FC;
    }
    // 0x800BC4DC: nop

    // 0x800BC4E0: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x800BC4E4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BC4E8: multu       $t8, $t4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC4EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BC4F0: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800BC4F4: lh          $a3, 0x2($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X2);
    // 0x800BC4F8: nop

L_800BC4FC:
    // 0x800BC4FC: bne         $at, $zero, L_800BC4C0
    if (ctx->r1 != 0) {
        // 0x800BC500: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800BC4C0;
    }
    // 0x800BC500: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_800BC504:
    // 0x800BC504: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BC508: lw          $t8, 0x30D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30D8);
    // 0x800BC50C: addiu       $t0, $t0, 0x44
    ctx->r8 = ADD32(ctx->r8, 0X44);
    // 0x800BC510: addu        $a0, $s2, $t8
    ctx->r4 = ADD32(ctx->r18, ctx->r24);
    // 0x800BC514: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x800BC518: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    // 0x800BC51C: sh          $a3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r7;
    // 0x800BC520: sh          $t2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r10;
    // 0x800BC524: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800BC528: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800BC52C: subu        $t9, $t1, $t7
    ctx->r25 = SUB32(ctx->r9, ctx->r15);
    // 0x800BC530: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x800BC534: bne         $t6, $zero, L_800BC540
    if (ctx->r14 != 0) {
        // 0x800BC538: nop
    
            goto L_800BC540;
    }
    // 0x800BC538: nop

    // 0x800BC53C: break       7
    do_break(2148255036);
L_800BC540:
    // 0x800BC540: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC544: bne         $t6, $at, L_800BC558
    if (ctx->r14 != ctx->r1) {
        // 0x800BC548: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC558;
    }
    // 0x800BC548: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC54C: bne         $t9, $at, L_800BC558
    if (ctx->r25 != ctx->r1) {
        // 0x800BC550: nop
    
            goto L_800BC558;
    }
    // 0x800BC550: nop

    // 0x800BC554: break       6
    do_break(2148255060);
L_800BC558:
    // 0x800BC558: mflo        $t8
    ctx->r24 = lo;
    // 0x800BC55C: sb          $t8, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r24;
    // 0x800BC560: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800BC564: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800BC568: subu        $t9, $t2, $t7
    ctx->r25 = SUB32(ctx->r10, ctx->r15);
    // 0x800BC56C: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x800BC570: lbu         $a2, 0xA($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0XA);
    // 0x800BC574: bne         $t6, $zero, L_800BC580
    if (ctx->r14 != 0) {
        // 0x800BC578: nop
    
            goto L_800BC580;
    }
    // 0x800BC578: nop

    // 0x800BC57C: break       7
    do_break(2148255100);
L_800BC580:
    // 0x800BC580: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC584: bne         $t6, $at, L_800BC598
    if (ctx->r14 != ctx->r1) {
        // 0x800BC588: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC598;
    }
    // 0x800BC588: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC58C: bne         $t9, $at, L_800BC598
    if (ctx->r25 != ctx->r1) {
        // 0x800BC590: nop
    
            goto L_800BC598;
    }
    // 0x800BC590: nop

    // 0x800BC594: break       6
    do_break(2148255124);
L_800BC598:
    // 0x800BC598: mflo        $t8
    ctx->r24 = lo;
    // 0x800BC59C: sb          $t8, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r24;
    // 0x800BC5A0: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800BC5A4: andi        $s1, $t8, 0xFF
    ctx->r17 = ctx->r24 & 0XFF;
    // 0x800BC5A8: multu       $s1, $t7
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC5AC: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x800BC5B0: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x800BC5B4: or          $t5, $s1, $zero
    ctx->r13 = ctx->r17 | 0;
    // 0x800BC5B8: mflo        $t9
    ctx->r25 = lo;
    // 0x800BC5BC: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x800BC5C0: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x800BC5C4: lb          $t8, -0x19($t0)
    ctx->r24 = MEM_B(ctx->r8, -0X19);
    // 0x800BC5C8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800BC5CC: beq         $t8, $zero, L_800BC660
    if (ctx->r24 == 0) {
        // 0x800BC5D0: nop
    
            goto L_800BC660;
    }
    // 0x800BC5D0: nop

    // 0x800BC5D4: multu       $a2, $t7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC5D8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC5DC: lw          $v1, -0x6034($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6034);
    // 0x800BC5E0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BC5E4: addiu       $t8, $t8, -0x5F18
    ctx->r24 = ADD32(ctx->r24, -0X5F18);
    // 0x800BC5E8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800BC5EC: mflo        $v0
    ctx->r2 = lo;
    // 0x800BC5F0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC5F4: bne         $at, $zero, L_800BC60C
    if (ctx->r1 != 0) {
        // 0x800BC5F8: nop
    
            goto L_800BC60C;
    }
    // 0x800BC5F8: nop

L_800BC5FC:
    // 0x800BC5FC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800BC600: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC604: beq         $at, $zero, L_800BC5FC
    if (ctx->r1 == 0) {
        // 0x800BC608: nop
    
            goto L_800BC5FC;
    }
    // 0x800BC608: nop

L_800BC60C:
    // 0x800BC60C: sh          $v0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r2;
    // 0x800BC610: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800BC614: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC618: multu       $t5, $t9
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC61C: lw          $v1, -0x6034($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6034);
    // 0x800BC620: mflo        $v0
    ctx->r2 = lo;
    // 0x800BC624: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC628: bne         $at, $zero, L_800BC640
    if (ctx->r1 != 0) {
        // 0x800BC62C: nop
    
            goto L_800BC640;
    }
    // 0x800BC62C: nop

L_800BC630:
    // 0x800BC630: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800BC634: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC638: beq         $at, $zero, L_800BC630
    if (ctx->r1 == 0) {
        // 0x800BC63C: nop
    
            goto L_800BC630;
    }
    // 0x800BC63C: nop

L_800BC640:
    // 0x800BC640: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x800BC644: lbu         $t9, 0xA($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XA);
    // 0x800BC648: sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // 0x800BC64C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800BC650: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800BC654: sllv        $t8, $t6, $t9
    ctx->r24 = S32(ctx->r14 << (ctx->r25 & 31));
    // 0x800BC658: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800BC65C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800BC660:
    // 0x800BC660: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BC664: sb          $a1, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r5;
    // 0x800BC668: sb          $a1, 0x19($a0)
    MEM_B(0X19, ctx->r4) = ctx->r5;
    // 0x800BC66C: sb          $a1, 0x16($a0)
    MEM_B(0X16, ctx->r4) = ctx->r5;
    // 0x800BC670: sb          $a1, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r5;
    // 0x800BC674: sb          $a1, 0x17($a0)
    MEM_B(0X17, ctx->r4) = ctx->r5;
    // 0x800BC678: sb          $a1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r5;
    // 0x800BC67C: sb          $a1, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r5;
    // 0x800BC680: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x800BC684: lw          $t9, -0x5F20($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5F20);
    // 0x800BC688: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x800BC68C: slt         $at, $ra, $t9
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BC690: bne         $at, $zero, L_800BC3E4
    if (ctx->r1 != 0) {
        // 0x800BC694: addiu       $s3, $s3, 0x44
        ctx->r19 = ADD32(ctx->r19, 0X44);
            goto L_800BC3E4;
    }
    // 0x800BC694: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
L_800BC698:
    // 0x800BC698: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800BC69C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BC6A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC6A4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BC6A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800BC6AC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800BC6B0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800BC6B4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800BC6B8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800BC6BC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800BC6C0: jr          $ra
    // 0x800BC6C4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BC6C4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void render_dialogue_option(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D1B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009D1BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009D1C0: lb          $t7, 0x64D8($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X64D8);
    // 0x8009D1C4: lb          $t6, 0x6504($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X6504);
    // 0x8009D1C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D1CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009D1D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D1D4: xor         $a0, $t6, $t7
    ctx->r4 = ctx->r14 ^ ctx->r15;
    // 0x8009D1D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009D1DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8009D1E0: jal         0x8009D118
    // 0x8009D1E4: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
    set_option_text_colour(rdram, ctx);
        goto after_0;
    // 0x8009D1E4: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
    after_0:
    // 0x8009D1E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D1EC: addiu       $v0, $v0, 0x6504
    ctx->r2 = ADD32(ctx->r2, 0X6504);
    // 0x8009D1F0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009D1F4: lb          $t9, 0x64D8($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X64D8);
    // 0x8009D1F8: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8009D1FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D200: bne         $t8, $t9, L_8009D214
    if (ctx->r24 != ctx->r25) {
        // 0x8009D204: addiu       $a1, $zero, -0x8000
        ctx->r5 = ADD32(0, -0X8000);
            goto L_8009D214;
    }
    // 0x8009D204: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009D208: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8009D20C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D210: sb          $t0, 0x6516($at)
    MEM_B(0X6516, ctx->r1) = ctx->r8;
L_8009D214:
    // 0x8009D214: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009D218: lb          $a2, 0x650E($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X650E);
    // 0x8009D21C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009D220: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009D224: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009D228: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009D22C: jal         0x800C5168
    // 0x8009D230: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    render_dialogue_text(rdram, ctx);
        goto after_1;
    // 0x8009D230: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_1:
    // 0x8009D234: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D238: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009D23C: addiu       $v1, $v1, 0x650E
    ctx->r3 = ADD32(ctx->r3, 0X650E);
    // 0x8009D240: addiu       $v0, $v0, 0x6504
    ctx->r2 = ADD32(ctx->r2, 0X6504);
    // 0x8009D244: lb          $t3, 0x0($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X0);
    // 0x8009D248: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8009D24C: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D254: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8009D258: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009D25C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8009D260: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8009D264: jr          $ra
    // 0x8009D268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009D268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void vec3f_rotate_py(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070490: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070494: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070498: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007049C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800704A0: jal         0x800707C4
    // 0x800704A4: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800704A4: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    after_0:
    // 0x800704A8: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800704AC: jal         0x800707F8
    // 0x800704B0: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800704B0: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    after_1:
    // 0x800704B4: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800704B8: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x800704BC: jal         0x800707C4
    // 0x800704C0: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    sins_f(rdram, ctx);
        goto after_2;
    // 0x800704C0: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_2:
    // 0x800704C4: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800704C8: jal         0x800707F8
    // 0x800704CC: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    coss_f(rdram, ctx);
        goto after_3;
    // 0x800704CC: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_3:
    // 0x800704D0: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800704D4: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800704D8: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800704DC: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x800704E0: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x800704E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800704E8: jr          $ra
    // 0x800704EC: nop

    return;
    // 0x800704EC: nop

;}
RECOMP_FUNC void viewport_rsp_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006815C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068160: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80068164: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80068168: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8006816C: jal         0x8009C30C
    // 0x80068170: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80068170: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80068174: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80068178: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8006817C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80068180: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x80068184: beq         $t6, $zero, L_80068194
    if (ctx->r14 == 0) {
        // 0x80068188: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80068194;
    }
    // 0x80068188: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006818C: b           L_80068198
    // 0x80068190: negu        $a2, $a1
    ctx->r6 = SUB32(0, ctx->r5);
        goto L_80068198;
    // 0x80068190: negu        $a2, $a1
    ctx->r6 = SUB32(0, ctx->r5);
L_80068194:
    // 0x80068194: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80068198:
    // 0x80068198: lb          $t7, -0x2FA0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2FA0);
    // 0x8006819C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800681A0: beq         $t7, $zero, L_800681B0
    if (ctx->r15 == 0) {
        // 0x800681A4: addiu       $a3, $a3, 0xCE4
        ctx->r7 = ADD32(ctx->r7, 0XCE4);
            goto L_800681B0;
    }
    // 0x800681A4: addiu       $a3, $a3, 0xCE4
    ctx->r7 = ADD32(ctx->r7, 0XCE4);
    // 0x800681A8: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x800681AC: negu        $a2, $a1
    ctx->r6 = SUB32(0, ctx->r5);
L_800681B0:
    // 0x800681B0: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800681B4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800681B8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800681BC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x800681C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800681C4: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x800681C8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800681CC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800681D0: lw          $t9, -0x2F6C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2F6C);
    // 0x800681D4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800681D8: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x800681DC: bne         $t3, $zero, L_80068248
    if (ctx->r11 != 0) {
        // 0x800681E0: addiu       $t2, $t2, -0x2EB8
        ctx->r10 = ADD32(ctx->r10, -0X2EB8);
            goto L_80068248;
    }
    // 0x800681E0: addiu       $t2, $t2, -0x2EB8
    ctx->r10 = ADD32(ctx->r10, -0X2EB8);
    // 0x800681E4: sll         $t4, $a1, 4
    ctx->r12 = S32(ctx->r5 << 4);
    // 0x800681E8: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x800681EC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800681F0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800681F4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800681F8: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800681FC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80068200: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80068204: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80068208: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x8006820C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80068210: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
    // 0x80068214: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80068218: lui         $t5, 0x380
    ctx->r13 = S32(0X380 << 16);
    // 0x8006821C: addiu       $t4, $a0, 0x8
    ctx->r12 = ADD32(ctx->r4, 0X8);
    // 0x80068220: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80068224: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x80068228: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8006822C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80068230: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068234: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80068238: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8006823C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80068240: b           L_8006829C
    // 0x80068244: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
        goto L_8006829C;
    // 0x80068244: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
L_80068248:
    // 0x80068248: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006824C: lui         $t4, 0x380
    ctx->r12 = S32(0X380 << 16);
    // 0x80068250: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x80068254: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80068258: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x8006825C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80068260: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80068264: lw          $t8, -0x2ECC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2ECC);
    // 0x80068268: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8006826C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80068270: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80068274: addiu       $t2, $t2, -0x2EB8
    ctx->r10 = ADD32(ctx->r10, -0X2EB8);
    // 0x80068278: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006827C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80068280: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x80068284: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x80068288: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006828C: ori         $at, $at, 0xA0
    ctx->r1 = ctx->r1 | 0XA0;
    // 0x80068290: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x80068294: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80068298: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
L_8006829C:
    // 0x8006829C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800682A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800682A4: jr          $ra
    // 0x800682A8: nop

    return;
    // 0x800682A8: nop

;}
RECOMP_FUNC void is_in_tracks_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2D0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C2D4: lw          $v0, -0xB48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB48);
    // 0x8009C2D8: jr          $ra
    // 0x8009C2DC: nop

    return;
    // 0x8009C2DC: nop

;}
RECOMP_FUNC void sndp_voice_handler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800033C8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800033CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800033D0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800033D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800033D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800033DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800033E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800033E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800033E8: addiu       $s1, $a0, 0x28
    ctx->r17 = ADD32(ctx->r4, 0X28);
    // 0x800033EC: addiu       $s2, $a0, 0x14
    ctx->r18 = ADD32(ctx->r4, 0X14);
    // 0x800033F0: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
    // 0x800033F4: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
L_800033F8:
    // 0x800033F8: lh          $t6, 0x28($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X28);
    // 0x800033FC: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80003400: bne         $s3, $t6, L_80003424
    if (ctx->r19 != ctx->r14) {
        // 0x80003404: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80003424;
    }
    // 0x80003404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80003408: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x8000340C: lw          $a2, 0x4C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4C);
    // 0x80003410: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80003414: jal         0x800C91AC
    // 0x80003418: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80003418: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8000341C: b           L_80003430
    // 0x80003420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_80003430;
    // 0x80003420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80003424:
    // 0x80003424: jal         0x80003470
    // 0x80003428: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    sndp_handle_event(rdram, ctx);
        goto after_1;
    // 0x80003428: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8000342C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80003430:
    // 0x80003430: jal         0x800C92D0
    // 0x80003434: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    alEvtqNextEvent(rdram, ctx);
        goto after_2;
    // 0x80003434: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80003438: beq         $v0, $zero, L_800033F8
    if (ctx->r2 == 0) {
        // 0x8000343C: sw          $v0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->r2;
            goto L_800033F8;
    }
    // 0x8000343C: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80003440: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x80003444: nop

    // 0x80003448: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8000344C: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    // 0x80003450: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80003454: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80003458: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000345C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80003460: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80003464: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80003468: jr          $ra
    // 0x8000346C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000346C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void tex_get_table_2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AE44: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007AE48: lw          $v0, 0x6338($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6338);
    // 0x8007AE4C: jr          $ra
    // 0x8007AE50: nop

    return;
    // 0x8007AE50: nop

;}
RECOMP_FUNC void get_distance_to_active_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006634C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80066350: lb          $t6, 0xD14($t6)
    ctx->r14 = MEM_B(ctx->r14, 0XD14);
    // 0x80066354: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80066358: lw          $v1, 0xCE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XCE4);
    // 0x8006635C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066360: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80066364: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80066368: beq         $t6, $zero, L_80066374
    if (ctx->r14 == 0) {
        // 0x8006636C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80066374;
    }
    // 0x8006636C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80066370: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80066374:
    // 0x80066374: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80066378: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8006637C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80066380: addiu       $t8, $t8, 0xAC0
    ctx->r24 = ADD32(ctx->r24, 0XAC0);
    // 0x80066384: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80066388: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8006638C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80066390: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80066394: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80066398: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006639C: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800663A0: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800663A4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800663A8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800663AC: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800663B0: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800663B4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800663B8: nop

    // 0x800663BC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800663C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800663C4: jal         0x800C9AD0
    // 0x800663C8: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800663C8: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x800663CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800663D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800663D4: jr          $ra
    // 0x800663D8: nop

    return;
    // 0x800663D8: nop

;}
RECOMP_FUNC void level_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B224: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B228: lw          $t6, 0x1170($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1170);
    // 0x8006B22C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B230: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8006B234: lw          $t7, 0x1174($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1174);
    // 0x8006B238: jr          $ra
    // 0x8006B23C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    return;
    // 0x8006B23C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void mtx_head_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069790: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80069794: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80069798: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8006979C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800697A0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800697A4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800697A8: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800697AC: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800697B0: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800697B4: lh          $t9, 0x16($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X16);
    // 0x800697B8: nop

    // 0x800697BC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800697C0: nop

    // 0x800697C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800697C8: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x800697CC: lh          $t0, 0x18($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X18);
    // 0x800697D0: nop

    // 0x800697D4: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800697D8: nop

    // 0x800697DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800697E0: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x800697E4: lh          $t1, 0x1A($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X1A);
    // 0x800697E8: nop

    // 0x800697EC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800697F0: nop

    // 0x800697F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800697F8: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
    // 0x800697FC: lh          $a0, 0x1C($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1C);
    // 0x80069800: jal         0x800707F8
    // 0x80069804: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80069804: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    after_0:
    // 0x80069808: lw          $a2, 0x108($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X108);
    // 0x8006980C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80069810: lh          $a0, 0x1C($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1C);
    // 0x80069814: jal         0x800707C4
    // 0x80069818: nop

    sins_f(rdram, ctx);
        goto after_1;
    // 0x80069818: nop

    after_1:
    // 0x8006981C: lh          $a0, 0x10E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X10E);
    // 0x80069820: jal         0x800707F8
    // 0x80069824: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80069824: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80069828: lh          $a0, 0x10E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X10E);
    // 0x8006982C: jal         0x800707C4
    // 0x80069830: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80069830: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_3:
    // 0x80069834: mul.s       $f18, $f22, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x80069838: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8006983C: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80069840: lwc1        $f12, 0xF0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80069844: mul.s       $f10, $f22, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80069848: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8006984C: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80069850: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    // 0x80069854: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80069858: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006985C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x80069860: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80069864: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80069868: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8006986C: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x80069870: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x80069874: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80069878: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x8006987C: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x80069880: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80069884: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80069888: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8006988C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069890: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    // 0x80069894: mul.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80069898: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8006989C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800698A0: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x800698A4: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x800698A8: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800698AC: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x800698B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800698B4: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x800698B8: add.s       $f18, $f2, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x800698BC: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800698C0: swc1        $f16, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f16.u32l;
    // 0x800698C4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800698C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800698CC: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x800698D0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800698D4: mul.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800698D8: add.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800698DC: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800698E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800698E4: add.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800698E8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800698EC: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x800698F0: mul.s       $f16, $f12, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800698F4: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x800698F8: lwc1        $f14, 0xF8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800698FC: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x80069900: mul.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80069904: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069908: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8006990C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80069910: mul.s       $f10, $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80069914: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80069918: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8006991C: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x80069920: add.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80069924: swc1        $f22, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f22.u32l;
    // 0x80069928: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x8006992C: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80069930: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    // 0x80069934: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x80069938: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
    // 0x8006993C: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80069940: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80069944: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069948: addiu       $a1, $a1, 0x10A0
    ctx->r5 = ADD32(ctx->r5, 0X10A0);
    // 0x8006994C: swc1        $f16, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f16.u32l;
    // 0x80069950: jal         0x8006F768
    // 0x80069954: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    mtxf_mul(rdram, ctx);
        goto after_4;
    // 0x80069954: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    after_4:
    // 0x80069958: lw          $t2, 0x104($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X104);
    // 0x8006995C: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x80069960: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x80069964: jal         0x8006F870
    // 0x80069968: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_5;
    // 0x80069968: nop

    after_5:
    // 0x8006996C: lw          $a1, 0x100($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X100);
    // 0x80069970: lw          $a2, 0x104($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X104);
    // 0x80069974: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80069978: lui         $t4, 0x180
    ctx->r12 = S32(0X180 << 16);
    // 0x8006997C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80069980: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x80069984: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80069988: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8006998C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80069990: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069994: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80069998: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8006999C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800699A0: lui         $t0, 0xBC00
    ctx->r8 = S32(0XBC00 << 16);
    // 0x800699A4: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x800699A8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800699AC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800699B0: ori         $t0, $t0, 0xA
    ctx->r8 = ctx->r8 | 0XA;
    // 0x800699B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800699B8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800699BC: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x800699C0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800699C4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800699C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800699CC: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800699D0: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800699D4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800699D8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800699DC: jr          $ra
    // 0x800699E0: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800699E0: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_80074EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074EB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80074EBC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80074EC0: addiu       $a2, $zero, 0x1100
    ctx->r6 = ADD32(0, 0X1100);
    // 0x80074EC4: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80074EC8: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80074ECC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074ED0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80074ED4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80074ED8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80074EDC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80074EE0: addiu       $a0, $v0, 0x200
    ctx->r4 = ADD32(ctx->r2, 0X200);
    // 0x80074EE4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80074EE8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80074EEC: jal         0x80070C9C
    // 0x80074EF0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80074EF0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80074EF4: lui         $t6, 0x4748
    ctx->r14 = S32(0X4748 << 16);
    // 0x80074EF8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80074EFC: ori         $t6, $t6, 0x5353
    ctx->r14 = ctx->r14 | 0X5353;
    // 0x80074F00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80074F04: lh          $t7, 0x46($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X46);
    // 0x80074F08: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80074F0C: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
    // 0x80074F10: lh          $t8, 0x4A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4A);
    // 0x80074F14: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x80074F18: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    // 0x80074F1C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80074F20: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x80074F24: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x80074F28: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x80074F2C: sb          $t8, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r24;
    // 0x80074F30: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x80074F34: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80074F38: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x80074F3C: lh          $t4, 0x6($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X6);
    // 0x80074F40: sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // 0x80074F44: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x80074F48: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x80074F4C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80074F50: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80074F54: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // 0x80074F58: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x80074F5C: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x80074F60: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x80074F64: sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // 0x80074F68: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x80074F6C: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x80074F70: sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
    // 0x80074F74: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x80074F78: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80074F7C: sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
    // 0x80074F80: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80074F84: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    // 0x80074F88: nop

    // 0x80074F8C: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x80074F90: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80074F94: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80074F98: lh          $a3, 0x56($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X56);
    // 0x80074F9C: lh          $a2, 0x52($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X52);
    // 0x80074FA0: lh          $a1, 0x4E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4E);
    // 0x80074FA4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80074FA8: addu        $a0, $t3, $t1
    ctx->r4 = ADD32(ctx->r11, ctx->r9);
    // 0x80074FAC: jal         0x80074AA8
    // 0x80074FB0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_80074AA8(rdram, ctx);
        goto after_1;
    // 0x80074FB0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_1:
    // 0x80074FB4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80074FB8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80074FBC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80074FC0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80074FC4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80074FC8: addiu       $t7, $t6, 0x100
    ctx->r15 = ADD32(ctx->r14, 0X100);
    // 0x80074FCC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80074FD0: addiu       $a3, $a3, 0x7778
    ctx->r7 = ADD32(ctx->r7, 0X7778);
    // 0x80074FD4: addiu       $a2, $a2, 0x7768
    ctx->r6 = ADD32(ctx->r6, 0X7768);
    // 0x80074FD8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80074FDC: jal         0x800766D4
    // 0x80074FE0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    write_controller_pak_file(rdram, ctx);
        goto after_2;
    // 0x80074FE0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x80074FE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80074FE8: jal         0x80071140
    // 0x80074FEC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80074FEC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x80074FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074FF4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80074FF8: jr          $ra
    // 0x80074FFC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80074FFC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_wardensmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038AC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038ACC: jr          $ra
    // 0x80038AD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038AD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void textbox_visible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3400: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C3404: lb          $t6, 0x3670($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3670);
    // 0x800C3408: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C340C: beq         $t6, $zero, L_800C3438
    if (ctx->r14 == 0) {
        // 0x800C3410: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800C3438;
    }
    // 0x800C3410: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C3414: lbu         $t7, -0x5877($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X5877);
    // 0x800C3418: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C341C: beq         $t7, $zero, L_800C3438
    if (ctx->r15 == 0) {
        // 0x800C3420: nop
    
            goto L_800C3438;
    }
    // 0x800C3420: nop

    // 0x800C3424: lb          $t8, -0x5878($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X5878);
    // 0x800C3428: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C342C: beq         $t8, $zero, L_800C3438
    if (ctx->r24 == 0) {
        // 0x800C3430: nop
    
            goto L_800C3438;
    }
    // 0x800C3430: nop

    // 0x800C3434: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800C3438:
    // 0x800C3438: jr          $ra
    // 0x800C343C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C343C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void alLoadNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064EF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80064EFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80064F00: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80064F04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80064F08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80064F0C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80064F10: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80064F14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80064F18: addiu       $a1, $a1, -0x4414
    ctx->r5 = ADD32(ctx->r5, -0X4414);
    // 0x80064F1C: addiu       $a2, $a2, -0x4AC0
    ctx->r6 = ADD32(ctx->r6, -0X4AC0);
    // 0x80064F20: jal         0x800CA0B0
    // 0x80064F24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80064F24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80064F28: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80064F2C: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80064F30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80064F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064F38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80064F3C: jal         0x800C77F0
    // 0x80064F40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80064F40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80064F44: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80064F48: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80064F4C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80064F50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80064F54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064F58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80064F5C: jal         0x800C77F0
    // 0x80064F60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x80064F60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80064F64: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80064F68: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80064F6C: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80064F70: jalr        $t9
    // 0x80064F74: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80064F74: nop

    after_3:
    // 0x80064F78: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80064F7C: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80064F80: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80064F84: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x80064F88: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80064F8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80064F90: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80064F94: jr          $ra
    // 0x80064F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80064F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void strcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4710: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4714: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B4718: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B471C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4720: beq         $v0, $zero, L_800B473C
    if (ctx->r2 == 0) {
        // 0x800B4724: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B473C;
    }
    // 0x800B4724: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B4728:
    // 0x800B4728: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B472C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4730: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4734: bne         $v0, $zero, L_800B4728
    if (ctx->r2 != 0) {
        // 0x800B4738: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B4728;
    }
    // 0x800B4738: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B473C:
    // 0x800B473C: jr          $ra
    // 0x800B4740: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B4740: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void racer_ai_eggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800452A0: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800452A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800452A8: sw          $zero, -0x2AD4($at)
    MEM_W(-0X2AD4, ctx->r1) = 0;
    // 0x800452AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800452B0: sw          $zero, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = 0;
    // 0x800452B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800452B8: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x800452BC: sw          $t6, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r14;
    // 0x800452C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800452C4: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800452C8: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
    // 0x800452CC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800452D0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800452D4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800452D8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800452DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800452E0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800452E4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800452E8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800452EC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800452F0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800452F4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800452F8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800452FC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80045300: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80045304: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80045308: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8004530C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80045310: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80045314: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80045318: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
    // 0x8004531C: jal         0x8001BA74
    // 0x80045320: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x80045320: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    after_0:
    // 0x80045324: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80045328: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004532C: bne         $t7, $at, L_80045C04
    if (ctx->r15 != ctx->r1) {
        // 0x80045330: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C04;
    }
    // 0x80045330: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045334: jal         0x8006BDB0
    // 0x80045338: nop

    level_header(rdram, ctx);
        goto after_1;
    // 0x80045338: nop

    after_1:
    // 0x8004533C: addiu       $t8, $v0, 0x2A
    ctx->r24 = ADD32(ctx->r2, 0X2A);
    // 0x80045340: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80045344: lb          $t9, 0x1E2($s5)
    ctx->r25 = MEM_B(ctx->r21, 0X1E2);
    // 0x80045348: nop

    // 0x8004534C: beq         $t9, $zero, L_80045388
    if (ctx->r25 == 0) {
        // 0x80045350: nop
    
            goto L_80045388;
    }
    // 0x80045350: nop

    // 0x80045354: lh          $t0, 0x1C6($s5)
    ctx->r8 = MEM_H(ctx->r21, 0X1C6);
    // 0x80045358: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8004535C: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80045360: sh          $t1, 0x1C6($s5)
    MEM_H(0X1C6, ctx->r21) = ctx->r9;
    // 0x80045364: lh          $t2, 0x1C6($s5)
    ctx->r10 = MEM_H(ctx->r21, 0X1C6);
    // 0x80045368: nop

    // 0x8004536C: slti        $at, $t2, 0x3D
    ctx->r1 = SIGNED(ctx->r10) < 0X3D ? 1 : 0;
    // 0x80045370: bne         $at, $zero, L_8004538C
    if (ctx->r1 != 0) {
        // 0x80045374: nop
    
            goto L_8004538C;
    }
    // 0x80045374: nop

    // 0x80045378: sh          $zero, 0x1C6($s5)
    MEM_H(0X1C6, ctx->r21) = 0;
    // 0x8004537C: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
    // 0x80045380: b           L_8004538C
    // 0x80045384: sb          $t3, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r11;
        goto L_8004538C;
    // 0x80045384: sb          $t3, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r11;
L_80045388:
    // 0x80045388: sh          $zero, 0x1C6($s5)
    MEM_H(0X1C6, ctx->r21) = 0;
L_8004538C:
    // 0x8004538C: lbu         $v1, 0x1CD($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X1CD);
    // 0x80045390: nop

    // 0x80045394: bne         $v1, $zero, L_800458A8
    if (ctx->r3 != 0) {
        // 0x80045398: nop
    
            goto L_800458A8;
    }
    // 0x80045398: nop

    // 0x8004539C: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800453A0: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
L_800453A4:
    // 0x800453A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800453A8: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800453AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800453B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800453B4: addiu       $a1, $a1, -0x2A75
    ctx->r5 = ADD32(ctx->r5, -0X2A75);
    // 0x800453B8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800453BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800453C0:
    // 0x800453C0: lb          $v0, 0x0($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X0);
    // 0x800453C4: nop

    // 0x800453C8: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x800453CC: multu       $t4, $s7
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800453D0: andi        $t7, $v0, 0x40
    ctx->r15 = ctx->r2 & 0X40;
    // 0x800453D4: andi        $t0, $v0, 0x80
    ctx->r8 = ctx->r2 & 0X80;
    // 0x800453D8: mflo        $v1
    ctx->r3 = lo;
    // 0x800453DC: sll         $t5, $v1, 24
    ctx->r13 = S32(ctx->r3 << 24);
    // 0x800453E0: sra         $t6, $t5, 24
    ctx->r14 = S32(SIGNED(ctx->r13) >> 24);
    // 0x800453E4: beq         $t7, $zero, L_800453FC
    if (ctx->r15 == 0) {
        // 0x800453E8: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800453FC;
    }
    // 0x800453E8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800453EC: addiu       $v1, $t6, 0x2
    ctx->r3 = ADD32(ctx->r14, 0X2);
    // 0x800453F0: sll         $t8, $v1, 24
    ctx->r24 = S32(ctx->r3 << 24);
    // 0x800453F4: b           L_80045410
    // 0x800453F8: sra         $v1, $t8, 24
    ctx->r3 = S32(SIGNED(ctx->r24) >> 24);
        goto L_80045410;
    // 0x800453F8: sra         $v1, $t8, 24
    ctx->r3 = S32(SIGNED(ctx->r24) >> 24);
L_800453FC:
    // 0x800453FC: beq         $t0, $zero, L_80045414
    if (ctx->r8 == 0) {
        // 0x80045400: slt         $at, $s2, $v1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80045414;
    }
    // 0x80045400: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80045404: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80045408: sll         $t1, $v1, 24
    ctx->r9 = S32(ctx->r3 << 24);
    // 0x8004540C: sra         $v1, $t1, 24
    ctx->r3 = S32(SIGNED(ctx->r9) >> 24);
L_80045410:
    // 0x80045410: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
L_80045414:
    // 0x80045414: beq         $at, $zero, L_80045434
    if (ctx->r1 == 0) {
        // 0x80045418: nop
    
            goto L_80045434;
    }
    // 0x80045418: nop

    // 0x8004541C: sll         $s2, $v1, 24
    ctx->r18 = S32(ctx->r3 << 24);
    // 0x80045420: sll         $s0, $a0, 24
    ctx->r16 = S32(ctx->r4 << 24);
    // 0x80045424: sra         $t3, $s2, 24
    ctx->r11 = S32(SIGNED(ctx->r18) >> 24);
    // 0x80045428: sra         $t4, $s0, 24
    ctx->r12 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8004542C: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x80045430: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_80045434:
    // 0x80045434: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80045438: bgez        $a0, L_800453C0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8004543C: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800453C0;
    }
    // 0x8004543C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80045440: lbu         $v0, 0x1CE($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X1CE);
    // 0x80045444: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80045448: andi        $t5, $v0, 0x40
    ctx->r13 = ctx->r2 & 0X40;
    // 0x8004544C: beq         $t5, $zero, L_80045470
    if (ctx->r13 == 0) {
        // 0x80045450: andi        $t9, $v0, 0x80
        ctx->r25 = ctx->r2 & 0X80;
            goto L_80045470;
    }
    // 0x80045450: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x80045454: andi        $s1, $v0, 0xF
    ctx->r17 = ctx->r2 & 0XF;
    // 0x80045458: sll         $t6, $s1, 24
    ctx->r14 = S32(ctx->r17 << 24);
    // 0x8004545C: sra         $s1, $t6, 24
    ctx->r17 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80045460: sb          $t8, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r24;
    // 0x80045464: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x80045468: sb          $zero, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = 0;
    // 0x8004546C: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
L_80045470:
    // 0x80045470: beq         $t9, $zero, L_800455E0
    if (ctx->r25 == 0) {
        // 0x80045474: nop
    
            goto L_800455E0;
    }
    // 0x80045474: nop

    // 0x80045478: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8004547C: nop

    // 0x80045480: lb          $a0, 0x6($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X6);
    // 0x80045484: jal         0x80044450
    // 0x80045488: nop

    roll_percent_chance(rdram, ctx);
        goto after_2;
    // 0x80045488: nop

    after_2:
    // 0x8004548C: beq         $v0, $zero, L_800454A0
    if (ctx->r2 == 0) {
        // 0x80045490: lw          $t1, 0x74($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X74);
            goto L_800454A0;
    }
    // 0x80045490: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80045494: b           L_800454CC
    // 0x80045498: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
        goto L_800454CC;
    // 0x80045498: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x8004549C: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
L_800454A0:
    // 0x800454A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800454A4: lb          $a0, 0x2($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X2);
    // 0x800454A8: jal         0x80044450
    // 0x800454AC: nop

    roll_percent_chance(rdram, ctx);
        goto after_3;
    // 0x800454AC: nop

    after_3:
    // 0x800454B0: beq         $v0, $zero, L_800454D0
    if (ctx->r2 == 0) {
        // 0x800454B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800454D0;
    }
    // 0x800454B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800454B8: jal         0x80066210
    // 0x800454BC: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_4;
    // 0x800454BC: nop

    after_4:
    // 0x800454C0: bne         $v0, $zero, L_800454D0
    if (ctx->r2 != 0) {
        // 0x800454C4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800454D0;
    }
    // 0x800454C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800454C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800454CC:
    // 0x800454CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800454D0:
    // 0x800454D0: bne         $s2, $at, L_8004558C
    if (ctx->r18 != ctx->r1) {
        // 0x800454D4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8004558C;
    }
    // 0x800454D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800454D8: lb          $v0, 0x2($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X2);
    // 0x800454DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800454E0: beq         $v0, $zero, L_80045500
    if (ctx->r2 == 0) {
        // 0x800454E4: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80045500;
    }
    // 0x800454E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800454E8: lb          $t2, -0x2A78($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X2A78);
    // 0x800454EC: nop

    // 0x800454F0: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x800454F4: beq         $t3, $zero, L_80045500
    if (ctx->r11 == 0) {
        // 0x800454F8: nop
    
            goto L_80045500;
    }
    // 0x800454F8: nop

    // 0x800454FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80045500:
    // 0x80045500: beq         $v0, $at, L_80045520
    if (ctx->r2 == ctx->r1) {
        // 0x80045504: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80045520;
    }
    // 0x80045504: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80045508: lb          $t4, -0x2A77($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X2A77);
    // 0x8004550C: nop

    // 0x80045510: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x80045514: beq         $t5, $zero, L_80045524
    if (ctx->r13 == 0) {
        // 0x80045518: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80045524;
    }
    // 0x80045518: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004551C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80045520:
    // 0x80045520: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80045524:
    // 0x80045524: beq         $v0, $at, L_80045544
    if (ctx->r2 == ctx->r1) {
        // 0x80045528: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80045544;
    }
    // 0x80045528: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004552C: lb          $t6, -0x2A76($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2A76);
    // 0x80045530: nop

    // 0x80045534: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x80045538: beq         $t7, $zero, L_80045548
    if (ctx->r15 == 0) {
        // 0x8004553C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80045548;
    }
    // 0x8004553C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80045540: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80045544:
    // 0x80045544: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80045548:
    // 0x80045548: beq         $v0, $at, L_80045570
    if (ctx->r2 == ctx->r1) {
        // 0x8004554C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80045570;
    }
    // 0x8004554C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80045550: lb          $t8, -0x2A75($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X2A75);
    // 0x80045554: nop

    // 0x80045558: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x8004555C: beq         $t9, $zero, L_80045574
    if (ctx->r25 == 0) {
        // 0x80045560: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80045574;
    }
    // 0x80045560: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80045564: sll         $s1, $s7, 24
    ctx->r17 = S32(ctx->r23 << 24);
    // 0x80045568: sra         $t0, $s1, 24
    ctx->r8 = S32(SIGNED(ctx->r17) >> 24);
    // 0x8004556C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
L_80045570:
    // 0x80045570: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80045574:
    // 0x80045574: bne         $s1, $at, L_80045584
    if (ctx->r17 != ctx->r1) {
        // 0x80045578: addiu       $t1, $zero, 0x7
        ctx->r9 = ADD32(0, 0X7);
            goto L_80045584;
    }
    // 0x80045578: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8004557C: b           L_80045588
    // 0x80045580: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_80045588;
    // 0x80045580: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80045584:
    // 0x80045584: sb          $t1, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r9;
L_80045588:
    // 0x80045588: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8004558C:
    // 0x8004558C: bne         $s2, $at, L_800455DC
    if (ctx->r18 != ctx->r1) {
        // 0x80045590: nop
    
            goto L_800455DC;
    }
    // 0x80045590: nop

    // 0x80045594: lb          $t2, 0x173($s5)
    ctx->r10 = MEM_B(ctx->r21, 0X173);
    // 0x80045598: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8004559C: beq         $t2, $zero, L_800455D8
    if (ctx->r10 == 0) {
        // 0x800455A0: nop
    
            goto L_800455D8;
    }
    // 0x800455A0: nop

    // 0x800455A4: lb          $v0, 0x2($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X2);
    // 0x800455A8: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800455AC: beq         $s0, $v0, L_800455C4
    if (ctx->r16 == ctx->r2) {
        // 0x800455B0: sb          $t3, 0x1CD($s5)
        MEM_B(0X1CD, ctx->r21) = ctx->r11;
            goto L_800455C4;
    }
    // 0x800455B0: sb          $t3, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r11;
    // 0x800455B4: sll         $s1, $s0, 24
    ctx->r17 = S32(ctx->r16 << 24);
    // 0x800455B8: sra         $t4, $s1, 24
    ctx->r12 = S32(SIGNED(ctx->r17) >> 24);
    // 0x800455BC: b           L_800455DC
    // 0x800455C0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
        goto L_800455DC;
    // 0x800455C0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
L_800455C4:
    // 0x800455C4: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x800455C8: andi        $t5, $s1, 0x3
    ctx->r13 = ctx->r17 & 0X3;
    // 0x800455CC: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x800455D0: b           L_800455DC
    // 0x800455D4: sra         $s1, $t6, 24
    ctx->r17 = S32(SIGNED(ctx->r14) >> 24);
        goto L_800455DC;
    // 0x800455D4: sra         $s1, $t6, 24
    ctx->r17 = S32(SIGNED(ctx->r14) >> 24);
L_800455D8:
    // 0x800455D8: sb          $t8, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r24;
L_800455DC:
    // 0x800455DC: sb          $zero, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = 0;
L_800455E0:
    // 0x800455E0: lw          $t9, 0x144($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X144);
    // 0x800455E4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800455E8: beq         $t9, $zero, L_800455F4
    if (ctx->r25 == 0) {
        // 0x800455EC: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_800455F4;
    }
    // 0x800455EC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800455F0: sb          $t0, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r8;
L_800455F4:
    // 0x800455F4: lbu         $v0, 0x1CE($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X1CE);
    // 0x800455F8: nop

    // 0x800455FC: beq         $v0, $zero, L_80045608
    if (ctx->r2 == 0) {
        // 0x80045600: nop
    
            goto L_80045608;
    }
    // 0x80045600: nop

    // 0x80045604: sb          $v0, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r2;
L_80045608:
    // 0x80045608: lbu         $t1, 0x1CD($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X1CD);
    // 0x8004560C: sb          $zero, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = 0;
    // 0x80045610: bne         $t1, $zero, L_8004565C
    if (ctx->r9 != 0) {
        // 0x80045614: nop
    
            goto L_8004565C;
    }
    // 0x80045614: nop

    // 0x80045618: lw          $t2, 0x4C($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X4C);
    // 0x8004561C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045620: lbu         $v0, 0x12($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X12);
    // 0x80045624: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80045628: beq         $v0, $at, L_80045648
    if (ctx->r2 == ctx->r1) {
        // 0x8004562C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80045648;
    }
    // 0x8004562C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80045630: beq         $v0, $at, L_80045650
    if (ctx->r2 == ctx->r1) {
        // 0x80045634: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80045650;
    }
    // 0x80045634: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80045638: beq         $v0, $s7, L_80045658
    if (ctx->r2 == ctx->r23) {
        // 0x8004563C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80045658;
    }
    // 0x8004563C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80045640: b           L_80045660
    // 0x80045644: lb          $t6, 0x1D8($s5)
    ctx->r14 = MEM_B(ctx->r21, 0X1D8);
        goto L_80045660;
    // 0x80045644: lb          $t6, 0x1D8($s5)
    ctx->r14 = MEM_B(ctx->r21, 0X1D8);
L_80045648:
    // 0x80045648: b           L_8004565C
    // 0x8004564C: sb          $t3, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r11;
        goto L_8004565C;
    // 0x8004564C: sb          $t3, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r11;
L_80045650:
    // 0x80045650: b           L_8004565C
    // 0x80045654: sb          $t4, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r12;
        goto L_8004565C;
    // 0x80045654: sb          $t4, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r12;
L_80045658:
    // 0x80045658: sb          $t5, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r13;
L_8004565C:
    // 0x8004565C: lb          $t6, 0x1D8($s5)
    ctx->r14 = MEM_B(ctx->r21, 0X1D8);
L_80045660:
    // 0x80045660: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80045664: beq         $t6, $zero, L_80045670
    if (ctx->r14 == 0) {
        // 0x80045668: nop
    
            goto L_80045670;
    }
    // 0x80045668: nop

    // 0x8004566C: sb          $t7, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r15;
L_80045670:
    // 0x80045670: lbu         $t8, 0x1CD($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X1CD);
    // 0x80045674: nop

    // 0x80045678: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8004567C: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x80045680: beq         $at, $zero, L_800456E4
    if (ctx->r1 == 0) {
        // 0x80045684: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800456E4;
    }
    // 0x80045684: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80045688: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004568C: addu        $at, $at, $t9
    gpr jr_addend_80045698 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80045690: lw          $t9, 0x6358($at)
    ctx->r25 = ADD32(ctx->r1, 0X6358);
    // 0x80045694: nop

    // 0x80045698: jr          $t9
    // 0x8004569C: nop

    switch (jr_addend_80045698 >> 2) {
        case 0: goto L_800456A0; break;
        case 1: goto L_800456A8; break;
        case 2: goto L_800456B0; break;
        case 3: goto L_800456BC; break;
        case 4: goto L_800456CC; break;
        case 5: goto L_800456D4; break;
        case 6: goto L_800456B0; break;
        case 7: goto L_800456DC; break;
        default: switch_error(__func__, 0x80045698, 0x800E6358);
    }
    // 0x8004569C: nop

L_800456A0:
    // 0x800456A0: b           L_800456E4
    // 0x800456A4: addiu       $s3, $zero, 0x2D
    ctx->r19 = ADD32(0, 0X2D);
        goto L_800456E4;
    // 0x800456A4: addiu       $s3, $zero, 0x2D
    ctx->r19 = ADD32(0, 0X2D);
L_800456A8:
    // 0x800456A8: b           L_800456E4
    // 0x800456AC: addiu       $s3, $zero, 0x5C
    ctx->r19 = ADD32(0, 0X5C);
        goto L_800456E4;
    // 0x800456AC: addiu       $s3, $zero, 0x5C
    ctx->r19 = ADD32(0, 0X5C);
L_800456B0:
    // 0x800456B0: addiu       $s3, $zero, 0x5C
    ctx->r19 = ADD32(0, 0X5C);
    // 0x800456B4: b           L_800456E4
    // 0x800456B8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
        goto L_800456E4;
    // 0x800456B8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_800456BC:
    // 0x800456BC: lb          $s1, 0x2($s5)
    ctx->r17 = MEM_B(ctx->r21, 0X2);
    // 0x800456C0: addiu       $s3, $zero, 0x5C
    ctx->r19 = ADD32(0, 0X5C);
    // 0x800456C4: b           L_800456E4
    // 0x800456C8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
        goto L_800456E4;
    // 0x800456C8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_800456CC:
    // 0x800456CC: b           L_800456E4
    // 0x800456D0: addiu       $s3, $zero, 0x11
    ctx->r19 = ADD32(0, 0X11);
        goto L_800456E4;
    // 0x800456D0: addiu       $s3, $zero, 0x11
    ctx->r19 = ADD32(0, 0X11);
L_800456D4:
    // 0x800456D4: b           L_800456E4
    // 0x800456D8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_800456E4;
    // 0x800456D8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800456DC:
    // 0x800456DC: addiu       $s3, $zero, 0x2D
    ctx->r19 = ADD32(0, 0X2D);
    // 0x800456E0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800456E4:
    // 0x800456E4: beq         $s3, $zero, L_80045860
    if (ctx->r19 == 0) {
        // 0x800456E8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80045860;
    }
    // 0x800456E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800456EC: beq         $s3, $at, L_80045860
    if (ctx->r19 == ctx->r1) {
        // 0x800456F0: addiu       $a0, $sp, 0x94
        ctx->r4 = ADD32(ctx->r29, 0X94);
            goto L_80045860;
    }
    // 0x800456F0: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x800456F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800456F8: lwc1        $f24, 0x6378($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X6378);
    // 0x800456FC: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x80045700: jal         0x8000E988
    // 0x80045704: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    objGetObjList(rdram, ctx);
        goto after_5;
    // 0x80045704: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    after_5:
    // 0x80045708: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x8004570C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80045710: blez        $t0, L_80045860
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80045714: sw          $zero, 0x94($sp)
        MEM_W(0X94, ctx->r29) = 0;
            goto L_80045860;
    }
    // 0x80045714: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
L_80045718:
    // 0x80045718: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8004571C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80045720: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80045724: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x80045728: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x8004572C: nop

    // 0x80045730: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x80045734: nop

    // 0x80045738: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8004573C: bne         $t5, $zero, L_800457EC
    if (ctx->r13 != 0) {
        // 0x80045740: nop
    
            goto L_800457EC;
    }
    // 0x80045740: nop

    // 0x80045744: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x80045748: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8004574C: bne         $s3, $t6, L_800457EC
    if (ctx->r19 != ctx->r14) {
        // 0x80045750: nop
    
            goto L_800457EC;
    }
    // 0x80045750: nop

    // 0x80045754: beq         $s3, $at, L_800457A4
    if (ctx->r19 == ctx->r1) {
        // 0x80045758: addiu       $at, $zero, 0x5C
        ctx->r1 = ADD32(0, 0X5C);
            goto L_800457A4;
    }
    // 0x80045758: addiu       $at, $zero, 0x5C
    ctx->r1 = ADD32(0, 0X5C);
    // 0x8004575C: beq         $s3, $at, L_8004576C
    if (ctx->r19 == ctx->r1) {
        // 0x80045760: nop
    
            goto L_8004576C;
    }
    // 0x80045760: nop

    // 0x80045764: b           L_800457EC
    // 0x80045768: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800457EC;
    // 0x80045768: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8004576C:
    // 0x8004576C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80045770: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80045774: lb          $t7, 0x8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X8);
    // 0x80045778: nop

    // 0x8004577C: bne         $s2, $t7, L_800457EC
    if (ctx->r18 != ctx->r15) {
        // 0x80045780: nop
    
            goto L_800457EC;
    }
    // 0x80045780: nop

    // 0x80045784: beq         $s1, $at, L_8004579C
    if (ctx->r17 == ctx->r1) {
        // 0x80045788: nop
    
            goto L_8004579C;
    }
    // 0x80045788: nop

    // 0x8004578C: lb          $t8, 0x9($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X9);
    // 0x80045790: nop

    // 0x80045794: bne         $s1, $t8, L_800457EC
    if (ctx->r17 != ctx->r24) {
        // 0x80045798: nop
    
            goto L_800457EC;
    }
    // 0x80045798: nop

L_8004579C:
    // 0x8004579C: b           L_800457EC
    // 0x800457A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800457EC;
    // 0x800457A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800457A4:
    // 0x800457A4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x800457A8: bne         $s2, $zero, L_800457C8
    if (ctx->r18 != 0) {
        // 0x800457AC: nop
    
            goto L_800457C8;
    }
    // 0x800457AC: nop

    // 0x800457B0: lb          $t9, 0xB($v0)
    ctx->r25 = MEM_B(ctx->r2, 0XB);
    // 0x800457B4: nop

    // 0x800457B8: bne         $t9, $zero, L_800457EC
    if (ctx->r25 != 0) {
        // 0x800457BC: nop
    
            goto L_800457EC;
    }
    // 0x800457BC: nop

    // 0x800457C0: b           L_800457EC
    // 0x800457C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800457EC;
    // 0x800457C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800457C8:
    // 0x800457C8: lb          $t0, 0xB($v0)
    ctx->r8 = MEM_B(ctx->r2, 0XB);
    // 0x800457CC: nop

    // 0x800457D0: bne         $s7, $t0, L_800457EC
    if (ctx->r23 != ctx->r8) {
        // 0x800457D4: nop
    
            goto L_800457EC;
    }
    // 0x800457D4: nop

    // 0x800457D8: lb          $t1, 0xA($v0)
    ctx->r9 = MEM_B(ctx->r2, 0XA);
    // 0x800457DC: nop

    // 0x800457E0: bne         $s1, $t1, L_800457EC
    if (ctx->r17 != ctx->r9) {
        // 0x800457E4: nop
    
            goto L_800457EC;
    }
    // 0x800457E4: nop

    // 0x800457E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800457EC:
    // 0x800457EC: beq         $v1, $zero, L_8004584C
    if (ctx->r3 == 0) {
        // 0x800457F0: lw          $t2, 0x94($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X94);
            goto L_8004584C;
    }
    // 0x800457F0: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800457F4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800457F8: lwc1        $f6, 0xC($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0XC);
    // 0x800457FC: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80045800: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80045804: lwc1        $f10, 0x10($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80045808: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8004580C: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80045810: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80045814: lwc1        $f18, 0x14($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80045818: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8004581C: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80045820: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80045824: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80045828: jal         0x800C9AD0
    // 0x8004582C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x8004582C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_6:
    // 0x80045830: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80045834: nop

    // 0x80045838: bc1f        L_8004584C
    if (!c1cs) {
        // 0x8004583C: lw          $t2, 0x94($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X94);
            goto L_8004584C;
    }
    // 0x8004583C: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80045840: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80045844: or          $fp, $s0, $zero
    ctx->r30 = ctx->r16 | 0;
    // 0x80045848: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
L_8004584C:
    // 0x8004584C: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80045850: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80045854: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80045858: bne         $at, $zero, L_80045718
    if (ctx->r1 != 0) {
        // 0x8004585C: sw          $t3, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r11;
            goto L_80045718;
    }
    // 0x8004585C: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
L_80045860:
    // 0x80045860: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045864: bne         $s3, $at, L_80045880
    if (ctx->r19 != ctx->r1) {
        // 0x80045868: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80045880;
    }
    // 0x80045868: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004586C: beq         $s1, $at, L_80045880
    if (ctx->r17 == ctx->r1) {
        // 0x80045870: nop
    
            goto L_80045880;
    }
    // 0x80045870: nop

    // 0x80045874: jal         0x8001BAC8
    // 0x80045878: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    get_racer_object(rdram, ctx);
        goto after_7;
    // 0x80045878: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8004587C: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_80045880:
    // 0x80045880: bne         $fp, $zero, L_80045894
    if (ctx->r30 != 0) {
        // 0x80045884: sw          $fp, 0x154($s5)
        MEM_W(0X154, ctx->r21) = ctx->r30;
            goto L_80045894;
    }
    // 0x80045884: sw          $fp, 0x154($s5)
    MEM_W(0X154, ctx->r21) = ctx->r30;
    // 0x80045888: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8004588C: sb          $t5, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r13;
    // 0x80045890: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045894:
    // 0x80045894: lbu         $v1, 0x1CD($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X1CD);
    // 0x80045898: nop

    // 0x8004589C: beq         $v1, $zero, L_800453A4
    if (ctx->r3 == 0) {
        // 0x800458A0: nop
    
            goto L_800453A4;
    }
    // 0x800458A0: nop

    // 0x800458A4: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
L_800458A8:
    // 0x800458A8: lw          $s0, 0x154($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X154);
    // 0x800458AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800458B0: beq         $s0, $zero, L_80045AA8
    if (ctx->r16 == 0) {
        // 0x800458B4: addiu       $s7, $zero, 0x3
        ctx->r23 = ADD32(0, 0X3);
            goto L_80045AA8;
    }
    // 0x800458B4: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x800458B8: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x800458BC: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800458C0: bne         $t6, $at, L_80045910
    if (ctx->r14 != ctx->r1) {
        // 0x800458C4: nop
    
            goto L_80045910;
    }
    // 0x800458C4: nop

    // 0x800458C8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x800458CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800458D0: bne         $v1, $at, L_800458F0
    if (ctx->r3 != ctx->r1) {
        // 0x800458D4: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800458F0;
    }
    // 0x800458D4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800458D8: lb          $t7, 0xB($v0)
    ctx->r15 = MEM_B(ctx->r2, 0XB);
    // 0x800458DC: nop

    // 0x800458E0: beq         $t7, $zero, L_800458F4
    if (ctx->r15 == 0) {
        // 0x800458E4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800458F4;
    }
    // 0x800458E4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800458E8: lbu         $a0, 0x1CD($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0X1CD);
    // 0x800458EC: sw          $zero, 0x154($s5)
    MEM_W(0X154, ctx->r21) = 0;
L_800458F0:
    // 0x800458F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_800458F4:
    // 0x800458F4: bne         $a0, $at, L_80045910
    if (ctx->r4 != ctx->r1) {
        // 0x800458F8: nop
    
            goto L_80045910;
    }
    // 0x800458F8: nop

    // 0x800458FC: lb          $t8, 0xB($v0)
    ctx->r24 = MEM_B(ctx->r2, 0XB);
    // 0x80045900: nop

    // 0x80045904: beq         $s7, $t8, L_80045910
    if (ctx->r23 == ctx->r24) {
        // 0x80045908: nop
    
            goto L_80045910;
    }
    // 0x80045908: nop

    // 0x8004590C: sw          $zero, 0x154($s5)
    MEM_W(0X154, ctx->r21) = 0;
L_80045910:
    // 0x80045910: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80045914: lwc1        $f18, 0xC($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80045918: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8004591C: sub.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80045920: lwc1        $f10, 0x14($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80045924: mul.s       $f24, $f20, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80045928: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004592C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80045930: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80045934: mul.s       $f0, $f14, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80045938: sub.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004593C: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    // 0x80045940: mul.s       $f16, $f22, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80045944: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80045948: add.s       $f18, $f24, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f24.fl + ctx->f16.fl;
    // 0x8004594C: jal         0x800C9AD0
    // 0x80045950: add.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f0.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x80045950: add.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f0.fl;
    after_8:
    // 0x80045954: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80045958: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004595C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80045960: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80045964: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80045968: bc1f        L_80045A30
    if (!c1cs) {
        // 0x8004596C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80045A30;
    }
    // 0x8004596C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80045970: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80045974: jal         0x80070750
    // 0x80045978: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    arctan2_f(rdram, ctx);
        goto after_9;
    // 0x80045978: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x8004597C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80045980: addu        $t9, $v0, $at
    ctx->r25 = ADD32(ctx->r2, ctx->r1);
    // 0x80045984: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80045988: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    // 0x8004598C: lh          $t1, 0x1A0($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X1A0);
    // 0x80045990: ori         $s1, $zero, 0x8001
    ctx->r17 = 0 | 0X8001;
    // 0x80045994: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80045998: subu        $v1, $t0, $t2
    ctx->r3 = SUB32(ctx->r8, ctx->r10);
    // 0x8004599C: lwc1        $f2, 0xA8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800459A0: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800459A4: bne         $at, $zero, L_800459B4
    if (ctx->r1 != 0) {
        // 0x800459A8: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800459B4;
    }
    // 0x800459A8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800459AC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800459B0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800459B4:
    // 0x800459B4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800459B8: beq         $at, $zero, L_800459C4
    if (ctx->r1 == 0) {
        // 0x800459BC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800459C4;
    }
    // 0x800459BC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800459C0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800459C4:
    // 0x800459C4: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800459C8: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800459CC: sra         $t4, $t3, 5
    ctx->r12 = S32(SIGNED(ctx->r11) >> 5);
    // 0x800459D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800459D4: sw          $t4, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r12;
    // 0x800459D8: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    // 0x800459DC: jal         0x800C9AD0
    // 0x800459E0: add.s       $f12, $f24, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f24.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x800459E0: add.s       $f12, $f24, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f24.fl + ctx->f8.fl;
    after_10:
    // 0x800459E4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800459E8: jal         0x80070750
    // 0x800459EC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x800459EC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_11:
    // 0x800459F0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800459F4: lwc1        $f2, 0xA8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800459F8: slt         $at, $a0, $s1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800459FC: bne         $at, $zero, L_80045A10
    if (ctx->r1 != 0) {
        // 0x80045A00: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80045A10;
    }
    // 0x80045A00: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80045A04: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80045A08: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80045A0C: addu        $v1, $a0, $at
    ctx->r3 = ADD32(ctx->r4, ctx->r1);
L_80045A10:
    // 0x80045A10: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80045A14: beq         $at, $zero, L_80045A20
    if (ctx->r1 == 0) {
        // 0x80045A18: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80045A20;
    }
    // 0x80045A18: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80045A1C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80045A20:
    // 0x80045A20: negu        $t5, $v1
    ctx->r13 = SUB32(0, ctx->r3);
    // 0x80045A24: sra         $t6, $t5, 7
    ctx->r14 = S32(SIGNED(ctx->r13) >> 7);
    // 0x80045A28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045A2C: sw          $t6, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r14;
L_80045A30:
    // 0x80045A30: lb          $v0, 0x1CC($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X1CC);
    // 0x80045A34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045A38: bgez        $v0, L_80045A64
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80045A3C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80045A64;
    }
    // 0x80045A3C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80045A40: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
    // 0x80045A44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045A48: addiu       $t7, $zero, -0x23
    ctx->r15 = ADD32(0, -0X23);
    // 0x80045A4C: sw          $t7, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r15;
    // 0x80045A50: lb          $t8, 0x1CC($s5)
    ctx->r24 = MEM_B(ctx->r21, 0X1CC);
    // 0x80045A54: nop

    // 0x80045A58: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80045A5C: b           L_80045AAC
    // 0x80045A60: sb          $t9, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = ctx->r25;
        goto L_80045AAC;
    // 0x80045A60: sb          $t9, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = ctx->r25;
L_80045A64:
    // 0x80045A64: lw          $v1, -0x2ACC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2ACC);
    // 0x80045A68: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80045A6C: slti        $at, $v1, 0x3D
    ctx->r1 = SIGNED(ctx->r3) < 0X3D ? 1 : 0;
    // 0x80045A70: beq         $at, $zero, L_80045A80
    if (ctx->r1 == 0) {
        // 0x80045A74: slti        $at, $v1, -0x3C
        ctx->r1 = SIGNED(ctx->r3) < -0X3C ? 1 : 0;
            goto L_80045A80;
    }
    // 0x80045A74: slti        $at, $v1, -0x3C
    ctx->r1 = SIGNED(ctx->r3) < -0X3C ? 1 : 0;
    // 0x80045A78: beq         $at, $zero, L_80045AA0
    if (ctx->r1 == 0) {
        // 0x80045A7C: nop
    
            goto L_80045AA0;
    }
    // 0x80045A7C: nop

L_80045A80:
    // 0x80045A80: sb          $t1, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = ctx->r9;
    // 0x80045A84: lb          $t0, 0x1CC($s5)
    ctx->r8 = MEM_B(ctx->r21, 0X1CC);
    // 0x80045A88: addiu       $t2, $zero, -0x28
    ctx->r10 = ADD32(0, -0X28);
    // 0x80045A8C: slti        $at, $t0, 0x6F
    ctx->r1 = SIGNED(ctx->r8) < 0X6F ? 1 : 0;
    // 0x80045A90: bne         $at, $zero, L_80045AAC
    if (ctx->r1 != 0) {
        // 0x80045A94: nop
    
            goto L_80045AAC;
    }
    // 0x80045A94: nop

    // 0x80045A98: b           L_80045AAC
    // 0x80045A9C: sb          $t2, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = ctx->r10;
        goto L_80045AAC;
    // 0x80045A9C: sb          $t2, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = ctx->r10;
L_80045AA0:
    // 0x80045AA0: b           L_80045AAC
    // 0x80045AA4: sb          $zero, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = 0;
        goto L_80045AAC;
    // 0x80045AA4: sb          $zero, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = 0;
L_80045AA8:
    // 0x80045AA8: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045AAC:
    // 0x80045AAC: lbu         $t3, 0x1CD($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X1CD);
    // 0x80045AB0: nop

    // 0x80045AB4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80045AB8: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x80045ABC: beq         $at, $zero, L_80045C00
    if (ctx->r1 == 0) {
        // 0x80045AC0: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80045C00;
    }
    // 0x80045AC0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80045AC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80045AC8: addu        $at, $at, $t4
    gpr jr_addend_80045AD4 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80045ACC: lw          $t4, 0x637C($at)
    ctx->r12 = ADD32(ctx->r1, 0X637C);
    // 0x80045AD0: nop

    // 0x80045AD4: jr          $t4
    // 0x80045AD8: nop

    switch (jr_addend_80045AD4 >> 2) {
        case 0: goto L_80045ADC; break;
        case 1: goto L_80045AF8; break;
        case 2: goto L_80045B30; break;
        case 3: goto L_80045B30; break;
        case 4: goto L_80045B58; break;
        case 5: goto L_80045B70; break;
        case 6: goto L_80045BB8; break;
        case 7: goto L_80045ADC; break;
        default: switch_error(__func__, 0x80045AD4, 0x800E637C);
    }
    // 0x80045AD8: nop

L_80045ADC:
    // 0x80045ADC: lw          $t5, 0x144($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X144);
    // 0x80045AE0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80045AE4: beq         $t5, $zero, L_80045C04
    if (ctx->r13 == 0) {
        // 0x80045AE8: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C04;
    }
    // 0x80045AE8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045AEC: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
    // 0x80045AF0: b           L_80045C00
    // 0x80045AF4: sb          $t6, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r14;
        goto L_80045C00;
    // 0x80045AF4: sb          $t6, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r14;
L_80045AF8:
    // 0x80045AF8: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80045AFC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80045B00: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80045B04: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80045B08: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80045B0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80045B10: bc1f        L_80045C00
    if (!c1cs) {
        // 0x80045B14: addiu       $v0, $v0, -0x2AD4
        ctx->r2 = ADD32(ctx->r2, -0X2AD4);
            goto L_80045C00;
    }
    // 0x80045B14: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x80045B18: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
    // 0x80045B1C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80045B20: nop

    // 0x80045B24: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x80045B28: b           L_80045C00
    // 0x80045B2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_80045C00;
    // 0x80045B2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80045B30:
    // 0x80045B30: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x80045B34: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80045B38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80045B3C: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x80045B40: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80045B44: nop

    // 0x80045B48: bc1f        L_80045C04
    if (!c1cs) {
        // 0x80045B4C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C04;
    }
    // 0x80045B4C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045B50: b           L_80045C00
    // 0x80045B54: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
        goto L_80045C00;
    // 0x80045B54: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045B58:
    // 0x80045B58: lb          $t9, 0x173($s5)
    ctx->r25 = MEM_B(ctx->r21, 0X173);
    // 0x80045B5C: nop

    // 0x80045B60: beq         $t9, $zero, L_80045C04
    if (ctx->r25 == 0) {
        // 0x80045B64: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C04;
    }
    // 0x80045B64: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045B68: b           L_80045C00
    // 0x80045B6C: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
        goto L_80045C00;
    // 0x80045B6C: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045B70:
    // 0x80045B70: lb          $t1, 0x173($s5)
    ctx->r9 = MEM_B(ctx->r21, 0X173);
    // 0x80045B74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80045B78: bne         $t1, $zero, L_80045B84
    if (ctx->r9 != 0) {
        // 0x80045B7C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80045B84;
    }
    // 0x80045B7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80045B80: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045B84:
    // 0x80045B84: lwc1        $f9, 0x63A0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X63A0);
    // 0x80045B88: lwc1        $f8, 0x63A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X63A4);
    // 0x80045B8C: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80045B90: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80045B94: addiu       $v0, $v0, -0x2AD0
    ctx->r2 = ADD32(ctx->r2, -0X2AD0);
    // 0x80045B98: bc1f        L_80045C04
    if (!c1cs) {
        // 0x80045B9C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C04;
    }
    // 0x80045B9C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045BA0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80045BA4: nop

    // 0x80045BA8: ori         $t2, $t0, 0x2000
    ctx->r10 = ctx->r8 | 0X2000;
    // 0x80045BAC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80045BB0: b           L_80045C00
    // 0x80045BB4: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
        goto L_80045C00;
    // 0x80045BB4: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045BB8:
    // 0x80045BB8: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x80045BBC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80045BC0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80045BC4: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80045BC8: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80045BCC: nop

    // 0x80045BD0: bc1f        L_80045C04
    if (!c1cs) {
        // 0x80045BD4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C04;
    }
    // 0x80045BD4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045BD8: beq         $s0, $zero, L_80045C04
    if (ctx->r16 == 0) {
        // 0x80045BDC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C04;
    }
    // 0x80045BDC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045BE0: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
    // 0x80045BE4: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80045BE8: nop

    // 0x80045BEC: lb          $t3, 0x9($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X9);
    // 0x80045BF0: nop

    // 0x80045BF4: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80045BF8: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x80045BFC: sb          $t5, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r13;
L_80045C00:
    // 0x80045C00: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80045C04:
    // 0x80045C04: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80045C08: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80045C0C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80045C10: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80045C14: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80045C18: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80045C1C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80045C20: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80045C24: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80045C28: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80045C2C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80045C30: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80045C34: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80045C38: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80045C3C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80045C40: jr          $ra
    // 0x80045C44: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80045C44: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void timetrial_write_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059B7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059B80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80059B84: lb          $v0, -0x2A64($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2A64);
    // 0x80059B88: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059B8C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80059B90: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x80059B94: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80059B98: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80059B9C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80059BA0: lh          $t2, -0x2A60($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X2A60);
    // 0x80059BA4: lw          $t4, -0x2A70($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2A70);
    // 0x80059BA8: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x80059BAC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059BB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059BB4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80059BB8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80059BBC: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80059BC0: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x80059BC4: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x80059BC8: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80059BCC: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80059BD0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80059BD4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80059BD8: jal         0x80075000
    // 0x80059BDC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80075000(rdram, ctx);
        goto after_0;
    // 0x80059BDC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x80059BE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80059BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80059BE8: jr          $ra
    // 0x80059BEC: nop

    return;
    // 0x80059BEC: nop

;}
RECOMP_FUNC void get_language(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EB20: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009EB24: lw          $t7, 0x644C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X644C);
    // 0x8009EB28: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8009EB2C: andi        $t9, $t7, 0xC
    ctx->r25 = ctx->r15 & 0XC;
    // 0x8009EB30: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009EB34: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8009EB38: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8009EB3C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8009EB40: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009EB44: beq         $t9, $at, L_8009EB74
    if (ctx->r25 == ctx->r1) {
        // 0x8009EB48: nop
    
            goto L_8009EB74;
    }
    // 0x8009EB48: nop

    // 0x8009EB4C: bne         $t8, $zero, L_8009EB5C
    if (ctx->r24 != 0) {
        // 0x8009EB50: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8009EB5C;
    }
    // 0x8009EB50: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8009EB54: beq         $t9, $at, L_8009EB7C
    if (ctx->r25 == ctx->r1) {
        // 0x8009EB58: nop
    
            goto L_8009EB7C;
    }
    // 0x8009EB58: nop

L_8009EB5C:
    // 0x8009EB5C: bne         $t8, $zero, L_8009EB88
    if (ctx->r24 != 0) {
        // 0x8009EB60: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8009EB88;
    }
    // 0x8009EB60: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8009EB64: beq         $t9, $at, L_8009EB84
    if (ctx->r25 == ctx->r1) {
        // 0x8009EB68: nop
    
            goto L_8009EB84;
    }
    // 0x8009EB68: nop

    // 0x8009EB6C: b           L_8009EB8C
    // 0x8009EB70: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8009EB8C;
    // 0x8009EB70: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009EB74:
    // 0x8009EB74: b           L_8009EB88
    // 0x8009EB78: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8009EB88;
    // 0x8009EB78: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8009EB7C:
    // 0x8009EB7C: b           L_8009EB88
    // 0x8009EB80: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8009EB88;
    // 0x8009EB80: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8009EB84:
    // 0x8009EB84: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8009EB88:
    // 0x8009EB88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009EB8C:
    // 0x8009EB8C: jr          $ra
    // 0x8009EB90: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8009EB90: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void clear_lap_records(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E770: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006E774: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006E778: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006E77C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006E780: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8006E784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E788: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8006E78C: jal         0x8006B224
    // 0x8006E790: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    level_count(rdram, ctx);
        goto after_0;
    // 0x8006E790: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x8006E794: jal         0x8001E29C
    // 0x8006E798: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8006E798: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_1:
    // 0x8006E79C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8006E7A0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8006E7A4: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8006E7A8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_8006E7AC:
    // 0x8006E7AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006E7B0: blez        $t6, L_8006E974
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006E7B4: andi        $t2, $s1, 0x1
        ctx->r10 = ctx->r17 & 0X1;
            goto L_8006E974;
    }
    // 0x8006E7B4: andi        $t2, $s1, 0x1
    ctx->r10 = ctx->r17 & 0X1;
    // 0x8006E7B8: andi        $v1, $t6, 0x1
    ctx->r3 = ctx->r14 & 0X1;
    // 0x8006E7BC: beq         $v1, $zero, L_8006E83C
    if (ctx->r3 == 0) {
        // 0x8006E7C0: andi        $t3, $s1, 0x2
        ctx->r11 = ctx->r17 & 0X2;
            goto L_8006E83C;
    }
    // 0x8006E7C0: andi        $t3, $s1, 0x2
    ctx->r11 = ctx->r17 & 0X2;
    // 0x8006E7C4: beq         $t2, $zero, L_8006E7F8
    if (ctx->r10 == 0) {
        // 0x8006E7C8: sll         $v1, $t0, 2
        ctx->r3 = S32(ctx->r8 << 2);
            goto L_8006E7F8;
    }
    // 0x8006E7C8: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006E7CC: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8006E7D0: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8006E7D4: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006E7D8: lw          $t9, 0x18($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X18);
    // 0x8006E7DC: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    // 0x8006E7E0: nop

    // 0x8006E7E4: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8006E7E8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8006E7EC: lhu         $t5, 0x4($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X4);
    // 0x8006E7F0: nop

    // 0x8006E7F4: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
L_8006E7F8:
    // 0x8006E7F8: beq         $t3, $zero, L_8006E82C
    if (ctx->r11 == 0) {
        // 0x8006E7FC: sll         $v1, $t0, 2
        ctx->r3 = S32(ctx->r8 << 2);
            goto L_8006E82C;
    }
    // 0x8006E7FC: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006E800: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8006E804: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8006E808: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006E80C: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x8006E810: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x8006E814: nop

    // 0x8006E818: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8006E81C: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8006E820: lhu         $t5, 0x0($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X0);
    // 0x8006E824: nop

    // 0x8006E828: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
L_8006E82C:
    // 0x8006E82C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8006E830: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006E834: beq         $a3, $t7, L_8006E974
    if (ctx->r7 == ctx->r15) {
        // 0x8006E838: nop
    
            goto L_8006E974;
    }
    // 0x8006E838: nop

L_8006E83C:
    // 0x8006E83C: beq         $t2, $zero, L_8006E884
    if (ctx->r10 == 0) {
        // 0x8006E840: nop
    
            goto L_8006E884;
    }
    // 0x8006E840: nop

    // 0x8006E844: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006E848: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006E84C: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006E850: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x8006E854: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006E858: mflo        $t8
    ctx->r24 = lo;
    // 0x8006E85C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006E860: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8006E864: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006E868: lhu         $t6, 0x6($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X6);
    // 0x8006E86C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8006E870: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x8006E874: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x8006E878: lhu         $t9, 0x4($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X4);
    // 0x8006E87C: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006E880: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
L_8006E884:
    // 0x8006E884: beq         $t3, $zero, L_8006E8CC
    if (ctx->r11 == 0) {
        // 0x8006E888: nop
    
            goto L_8006E8CC;
    }
    // 0x8006E888: nop

    // 0x8006E88C: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006E890: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006E894: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006E898: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x8006E89C: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006E8A0: mflo        $t6
    ctx->r14 = lo;
    // 0x8006E8A4: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x8006E8A8: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x8006E8AC: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006E8B0: lhu         $t9, 0x2($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X2);
    // 0x8006E8B4: addu        $t6, $t7, $a1
    ctx->r14 = ADD32(ctx->r15, ctx->r5);
    // 0x8006E8B8: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x8006E8BC: lw          $t5, 0x3C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3C);
    // 0x8006E8C0: lhu         $t8, 0x0($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X0);
    // 0x8006E8C4: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006E8C8: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
L_8006E8CC:
    // 0x8006E8CC: beq         $t2, $zero, L_8006E918
    if (ctx->r10 == 0) {
        // 0x8006E8D0: nop
    
            goto L_8006E918;
    }
    // 0x8006E8D0: nop

    // 0x8006E8D4: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006E8D8: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006E8DC: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006E8E0: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x8006E8E4: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006E8E8: mflo        $t9
    ctx->r25 = lo;
    // 0x8006E8EC: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E8F0: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x8006E8F4: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006E8F8: lhu         $t8, 0x1E($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X1E);
    // 0x8006E8FC: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x8006E900: sh          $t8, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r24;
    // 0x8006E904: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x8006E908: lhu         $t6, 0x1C($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X1C);
    // 0x8006E90C: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006E910: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8006E914: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
L_8006E918:
    // 0x8006E918: beq         $t3, $zero, L_8006E968
    if (ctx->r11 == 0) {
        // 0x8006E91C: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_8006E968;
    }
    // 0x8006E91C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006E920: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006E924: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006E928: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006E92C: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x8006E930: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006E934: mflo        $t8
    ctx->r24 = lo;
    // 0x8006E938: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006E93C: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8006E940: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006E944: lhu         $t6, 0x1A($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X1A);
    // 0x8006E948: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8006E94C: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
    // 0x8006E950: lw          $t5, 0x3C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3C);
    // 0x8006E954: lhu         $t9, 0x18($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X18);
    // 0x8006E958: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006E95C: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8006E960: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x8006E964: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_8006E968:
    // 0x8006E968: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8006E96C: bne         $a3, $t6, L_8006E83C
    if (ctx->r7 != ctx->r14) {
        // 0x8006E970: nop
    
            goto L_8006E83C;
    }
    // 0x8006E970: nop

L_8006E974:
    // 0x8006E974: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8006E978: bne         $t0, $t4, L_8006E7AC
    if (ctx->r8 != ctx->r12) {
        // 0x8006E97C: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_8006E7AC;
    }
    // 0x8006E97C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006E980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E984: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006E988: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006E98C: jr          $ra
    // 0x8006E990: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006E990: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alSeqChOff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063AF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063AF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063AFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063B00: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063B04: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063B08: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80063B0C: addiu       $t8, $zero, 0x6A
    ctx->r24 = ADD32(0, 0X6A);
    // 0x80063B10: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063B14: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063B18: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063B1C: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063B20: sb          $a3, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r7;
    // 0x80063B24: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063B28: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063B2C: jal         0x800C91AC
    // 0x80063B30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063B30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80063B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063B38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063B3C: jr          $ra
    // 0x80063B40: nop

    return;
    // 0x80063B40: nop

;}
RECOMP_FUNC void instShowBearBar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E128: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x8000E12C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E130: jr          $ra
    // 0x8000E134: sh          $t6, -0x38F8($at)
    MEM_H(-0X38F8, ctx->r1) = ctx->r14;
    return;
    // 0x8000E134: sh          $t6, -0x38F8($at)
    MEM_H(-0X38F8, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void trackmenu_setup_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090F30: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80090F34: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80090F38: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80090F3C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80090F40: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80090F44: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80090F48: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80090F4C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80090F50: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80090F54: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80090F58: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80090F5C: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80090F60: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x80090F64: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80090F68: jal         0x8006EA90
    // 0x80090F6C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80090F6C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    after_0:
    // 0x80090F70: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80090F74: addiu       $s0, $s0, 0x300
    ctx->r16 = ADD32(ctx->r16, 0X300);
    // 0x80090F78: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80090F7C: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80090F80: bne         $t6, $zero, L_80090F90
    if (ctx->r14 != 0) {
        // 0x80090F84: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80090F90;
    }
    // 0x80090F84: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80090F88: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80090F8C: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
L_80090F90:
    // 0x80090F90: lw          $t8, -0xB44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB44);
    // 0x80090F94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80090F98: bne         $t8, $at, L_80090FD0
    if (ctx->r24 != ctx->r1) {
        // 0x80090F9C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80090FD0;
    }
    // 0x80090F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80090FA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80090FA4: lw          $t9, 0x69C8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X69C8);
    // 0x80090FA8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80090FAC: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80090FB0: beq         $at, $zero, L_80090FD0
    if (ctx->r1 == 0) {
        // 0x80090FB4: nop
    
            goto L_80090FD0;
    }
    // 0x80090FB4: nop

    // 0x80090FB8: lw          $t0, 0x63E0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X63E0);
    // 0x80090FBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80090FC0: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x80090FC4: bne         $at, $zero, L_80090FD0
    if (ctx->r1 != 0) {
        // 0x80090FC8: nop
    
            goto L_80090FD0;
    }
    // 0x80090FC8: nop

    // 0x80090FCC: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
L_80090FD0:
    // 0x80090FD0: jal         0x80066894
    // 0x80090FD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camDisableUserView(rdram, ctx);
        goto after_1;
    // 0x80090FD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80090FD8: jal         0x8009BD5C
    // 0x80090FDC: nop

    menu_camera_centre(rdram, ctx);
        goto after_2;
    // 0x80090FDC: nop

    after_2:
    // 0x80090FE0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80090FE4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80090FE8: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x80090FEC: jal         0x80067F2C
    // 0x80090FF0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    mtx_ortho(rdram, ctx);
        goto after_3;
    // 0x80090FF0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_3:
    // 0x80090FF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80090FF8: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80090FFC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80091000: bgez        $v0, L_800910A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80091004: addiu       $v1, $v1, -0x8A4
        ctx->r3 = ADD32(ctx->r3, -0X8A4);
            goto L_800910A8;
    }
    // 0x80091004: addiu       $v1, $v1, -0x8A4
    ctx->r3 = ADD32(ctx->r3, -0X8A4);
    // 0x80091008: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009100C: lw          $v0, 0x69F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69F4);
    // 0x80091010: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80091014: bne         $v0, $at, L_80091028
    if (ctx->r2 != ctx->r1) {
        // 0x80091018: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80091028;
    }
    // 0x80091018: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009101C: b           L_80091048
    // 0x80091020: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
        goto L_80091048;
    // 0x80091020: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80091024: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80091028:
    // 0x80091028: bne         $v0, $at, L_80091040
    if (ctx->r2 != ctx->r1) {
        // 0x8009102C: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_80091040;
    }
    // 0x8009102C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80091030: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80091034: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
    // 0x80091038: b           L_80091048
    // 0x8009103C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
        goto L_80091048;
    // 0x8009103C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_80091040:
    // 0x80091040: sw          $t3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r11;
    // 0x80091044: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80091048:
    // 0x80091048: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8009104C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80091050: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x80091054: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80091058: swc1        $f0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f0.u32l;
    // 0x8009105C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80091060: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80091064: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80091068: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
    // 0x8009106C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80091070: nop

    // 0x80091074: bne         $t8, $zero, L_80091088
    if (ctx->r24 != 0) {
        // 0x80091078: nop
    
            goto L_80091088;
    }
    // 0x80091078: nop

    // 0x8009107C: lwc1        $f4, -0x7B10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7B10);
    // 0x80091080: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80091084: swc1        $f4, -0xBAC($at)
    MEM_W(-0XBAC, ctx->r1) = ctx->f4.u32l;
L_80091088:
    // 0x80091088: jal         0x8009CA60
    // 0x8009108C: nop

    menu_element_render(rdram, ctx);
        goto after_4;
    // 0x8009108C: nop

    after_4:
    // 0x80091090: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80091094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80091098: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009109C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800910A0: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x800910A4: swc1        $f6, -0xBAC($at)
    MEM_W(-0XBAC, ctx->r1) = ctx->f6.u32l;
L_800910A8:
    // 0x800910A8: slti        $at, $v0, -0x16
    ctx->r1 = SIGNED(ctx->r2) < -0X16 ? 1 : 0;
    // 0x800910AC: bne         $at, $zero, L_80092158
    if (ctx->r1 != 0) {
        // 0x800910B0: slti        $at, $v0, 0x1F
        ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
            goto L_80092158;
    }
    // 0x800910B0: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x800910B4: beq         $at, $zero, L_80092158
    if (ctx->r1 == 0) {
        // 0x800910B8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80092158;
    }
    // 0x800910B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800910BC: bgez        $v0, L_800910D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800910C0: lui         $fp, 0x800E
        ctx->r30 = S32(0X800E << 16);
            goto L_800910D8;
    }
    // 0x800910C0: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800910C4: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x800910C8: addiu       $t0, $t9, 0xFF
    ctx->r8 = ADD32(ctx->r25, 0XFF);
    // 0x800910CC: addiu       $fp, $fp, -0x89C
    ctx->r30 = ADD32(ctx->r30, -0X89C);
    // 0x800910D0: b           L_800910E8
    // 0x800910D4: sw          $t0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r8;
        goto L_800910E8;
    // 0x800910D4: sw          $t0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r8;
L_800910D8:
    // 0x800910D8: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800910DC: addiu       $fp, $fp, -0x89C
    ctx->r30 = ADD32(ctx->r30, -0X89C);
    // 0x800910E0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800910E4: sw          $t1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r9;
L_800910E8:
    // 0x800910E8: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800910EC: nop

    // 0x800910F0: bgez        $t2, L_800910FC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800910F4: nop
    
            goto L_800910FC;
    }
    // 0x800910F4: nop

    // 0x800910F8: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
L_800910FC:
    // 0x800910FC: lw          $a0, -0xB3C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XB3C);
    // 0x80091100: jal         0x8006B0F8
    // 0x80091104: nop

    leveltable_vehicle_usable(rdram, ctx);
        goto after_5;
    // 0x80091104: nop

    after_5:
    // 0x80091108: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009110C: lw          $a0, -0xB3C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XB3C);
    // 0x80091110: jal         0x8006BDDC
    // 0x80091114: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    level_name(rdram, ctx);
        goto after_6;
    // 0x80091114: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_6:
    // 0x80091118: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8009111C: jal         0x800C42EC
    // 0x80091120: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x80091120: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x80091124: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x80091128: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x8009112C: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x80091130: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80091134: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80091138: jal         0x800C4384
    // 0x8009113C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x8009113C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_8:
    // 0x80091140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80091144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80091148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009114C: jal         0x800C43CC
    // 0x80091150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_9;
    // 0x80091150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80091154: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091158: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8009115C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80091160: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091164: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80091168: addiu       $a2, $zero, 0x2B
    ctx->r6 = ADD32(0, 0X2B);
    // 0x8009116C: jal         0x800C4440
    // 0x80091170: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_10;
    // 0x80091170: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_10:
    // 0x80091174: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80091178: lw          $a2, 0x63BC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X63BC);
    // 0x8009117C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80091180: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x80091184: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x80091188: bne         $at, $zero, L_80091198
    if (ctx->r1 != 0) {
        // 0x8009118C: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_80091198;
    }
    // 0x8009118C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80091190: addiu       $t6, $zero, 0x1FF
    ctx->r14 = ADD32(0, 0X1FF);
    // 0x80091194: subu        $a2, $t6, $t5
    ctx->r6 = SUB32(ctx->r14, ctx->r13);
L_80091198:
    // 0x80091198: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8009119C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800911A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800911A4: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    // 0x800911A8: jal         0x800C4FBC
    // 0x800911AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_11;
    // 0x800911AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_11:
    // 0x800911B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800911B4: lw          $v0, 0x63E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63E0);
    // 0x800911B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800911BC: beq         $v0, $at, L_800911E8
    if (ctx->r2 == ctx->r1) {
        // 0x800911C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800911E8;
    }
    // 0x800911C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800911C4: bne         $v0, $at, L_80091394
    if (ctx->r2 != ctx->r1) {
        // 0x800911C8: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80091394;
    }
    // 0x800911C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800911CC: lw          $t8, 0x69C8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X69C8);
    // 0x800911D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800911D4: bne         $t8, $at, L_80091394
    if (ctx->r24 != ctx->r1) {
        // 0x800911D8: nop
    
            goto L_80091394;
    }
    // 0x800911D8: nop

    // 0x800911DC: jal         0x8009EC60
    // 0x800911E0: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_12;
    // 0x800911E0: nop

    after_12:
    // 0x800911E4: beq         $v0, $zero, L_80091394
    if (ctx->r2 == 0) {
        // 0x800911E8: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_80091394;
    }
L_800911E8:
    // 0x800911E8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800911EC: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x800911F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800911F4: lw          $a0, 0x248($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X248);
    // 0x800911F8: jal         0x800C4DA0
    // 0x800911FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_text_width(rdram, ctx);
        goto after_13;
    // 0x800911FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80091200: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80091204: lw          $t0, -0xB60($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB60);
    // 0x80091208: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8009120C: lw          $a0, 0x24C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X24C);
    // 0x80091210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80091214: jal         0x800C4DA0
    // 0x80091218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_text_width(rdram, ctx);
        goto after_14;
    // 0x80091218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x8009121C: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80091220: beq         $at, $zero, L_8009122C
    if (ctx->r1 == 0) {
        // 0x80091224: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_8009122C;
    }
    // 0x80091224: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80091228: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_8009122C:
    // 0x8009122C: addiu       $s0, $s0, 0x700
    ctx->r16 = ADD32(ctx->r16, 0X700);
    // 0x80091230: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x80091234: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091238: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8009123C: beq         $at, $zero, L_8009124C
    if (ctx->r1 == 0) {
        // 0x80091240: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_8009124C;
    }
    // 0x80091240: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091244: b           L_80091250
    // 0x80091248: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
        goto L_80091250;
    // 0x80091248: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_8009124C:
    // 0x8009124C: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
L_80091250:
    // 0x80091250: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80091254: lui         $at, 0xB0E0
    ctx->r1 = S32(0XB0E0 << 16);
    // 0x80091258: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009125C: lw          $t8, 0x665C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X665C);
    // 0x80091260: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80091264: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x80091268: lh          $t4, 0x8($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8);
    // 0x8009126C: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x80091270: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80091274: sra         $a1, $s4, 1
    ctx->r5 = S32(SIGNED(ctx->r20) >> 1);
    // 0x80091278: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x8009127C: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80091280: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80091284: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80091288: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8009128C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80091290: subu        $a2, $t2, $t1
    ctx->r6 = SUB32(ctx->r10, ctx->r9);
    // 0x80091294: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80091298: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8009129C: jal         0x80080580
    // 0x800912A0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    func_80080580(rdram, ctx);
        goto after_15;
    // 0x800912A0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_15:
    // 0x800912A4: jal         0x80080E6C
    // 0x800912A8: nop

    menu_geometry_end(rdram, ctx);
        goto after_16;
    // 0x800912A8: nop

    after_16:
    // 0x800912AC: jal         0x800C42EC
    // 0x800912B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_17;
    // 0x800912B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x800912B4: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    // 0x800912B8: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x800912BC: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x800912C0: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x800912C4: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800912C8: addu        $s7, $t2, $t1
    ctx->r23 = ADD32(ctx->r10, ctx->r9);
    // 0x800912CC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800912D0: addiu       $s6, $s6, 0x418
    ctx->r22 = ADD32(ctx->r22, 0X418);
    // 0x800912D4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800912D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800912DC: addiu       $s2, $zero, 0xA1
    ctx->r18 = ADD32(0, 0XA1);
L_800912E0:
    // 0x800912E0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800912E4: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
L_800912E8:
    // 0x800912E8: bne         $s3, $zero, L_80091318
    if (ctx->r19 != 0) {
        // 0x800912EC: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80091318;
    }
    // 0x800912EC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800912F0: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x800912F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800912F8: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800912FC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80091300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80091304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80091308: jal         0x800C4384
    // 0x8009130C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x8009130C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_18:
    // 0x80091310: b           L_80091344
    // 0x80091314: nop

        goto L_80091344;
    // 0x80091314: nop

L_80091318:
    // 0x80091318: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8009131C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80091320: bne         $s4, $t5, L_80091330
    if (ctx->r20 != ctx->r13) {
        // 0x80091324: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80091330;
    }
    // 0x80091324: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80091328: lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X84);
    // 0x8009132C: nop

L_80091330:
    // 0x80091330: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80091334: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80091338: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8009133C: jal         0x800C4384
    // 0x80091340: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    set_text_colour(rdram, ctx);
        goto after_19;
    // 0x80091340: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_19:
L_80091344:
    // 0x80091344: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80091348: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x8009134C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091350: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80091354: lw          $a3, 0x248($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X248);
    // 0x80091358: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x8009135C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80091360: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091364: subu        $a1, $s2, $s3
    ctx->r5 = SUB32(ctx->r18, ctx->r19);
    // 0x80091368: jal         0x800C4440
    // 0x8009136C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_20;
    // 0x8009136C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_20:
    // 0x80091370: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80091374: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80091378: bne         $s3, $at, L_800912E8
    if (ctx->r19 != ctx->r1) {
        // 0x8009137C: addiu       $s0, $s0, -0x2
        ctx->r16 = ADD32(ctx->r16, -0X2);
            goto L_800912E8;
    }
    // 0x8009137C: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x80091380: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80091384: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091388: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8009138C: bne         $s4, $at, L_800912E0
    if (ctx->r20 != ctx->r1) {
        // 0x80091390: addiu       $s7, $s7, 0x10
        ctx->r23 = ADD32(ctx->r23, 0X10);
            goto L_800912E0;
    }
    // 0x80091390: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
L_80091394:
    // 0x80091394: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80091398: lw          $t0, 0x69C8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X69C8);
    // 0x8009139C: nop

    // 0x800913A0: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x800913A4: beq         $at, $zero, L_80091F08
    if (ctx->r1 == 0) {
        // 0x800913A8: nop
    
            goto L_80091F08;
    }
    // 0x800913A8: nop

    // 0x800913AC: jal         0x800C42EC
    // 0x800913B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_21;
    // 0x800913B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
    // 0x800913B4: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800913B8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800913BC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800913C0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800913C4: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x800913C8: jal         0x800C4384
    // 0x800913CC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_text_colour(rdram, ctx);
        goto after_22;
    // 0x800913CC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_22:
    // 0x800913D0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800913D4: lw          $t1, -0xB60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB60);
    // 0x800913D8: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x800913DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800913E0: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800913E4: lw          $a3, 0x24($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X24);
    // 0x800913E8: addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
    // 0x800913EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800913F0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800913F4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800913F8: jal         0x800C4440
    // 0x800913FC: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    draw_text(rdram, ctx);
        goto after_23;
    // 0x800913FC: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_23:
    // 0x80091400: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80091404: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x80091408: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x8009140C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091410: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80091414: lw          $a3, 0x28($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X28);
    // 0x80091418: addiu       $s2, $s2, 0x5C
    ctx->r18 = ADD32(ctx->r18, 0X5C);
    // 0x8009141C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80091420: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80091424: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091428: jal         0x800C4440
    // 0x8009142C: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    draw_text(rdram, ctx);
        goto after_24;
    // 0x8009142C: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_24:
    // 0x80091430: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80091434: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80091438: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x8009143C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80091440: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x80091444: jal         0x800C4384
    // 0x80091448: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    set_text_colour(rdram, ctx);
        goto after_25;
    // 0x80091448: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_25:
    // 0x8009144C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80091450: lb          $t8, 0x69C0($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X69C0);
    // 0x80091454: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80091458: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009145C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80091460: lw          $t1, -0xB3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB3C);
    // 0x80091464: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80091468: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x8009146C: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x80091470: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80091474: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x80091478: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x8009147C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80091480: jal         0x800976F8
    // 0x80091484: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_26;
    // 0x80091484: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_26:
    // 0x80091488: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009148C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80091490: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80091494: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091498: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x8009149C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800914A0: jal         0x800C4440
    // 0x800914A4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    draw_text(rdram, ctx);
        goto after_27;
    // 0x800914A4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_27:
    // 0x800914A8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800914AC: lb          $t8, 0x69C0($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X69C0);
    // 0x800914B0: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800914B4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800914B8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800914BC: lw          $t1, -0xB3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB3C);
    // 0x800914C0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800914C4: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x800914C8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800914CC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800914D0: lhu         $a0, 0x0($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X0);
    // 0x800914D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800914D8: jal         0x800976F8
    // 0x800914DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_28;
    // 0x800914DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_28:
    // 0x800914E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800914E4: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x800914E8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800914EC: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800914F0: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x800914F4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800914F8: jal         0x800C4440
    // 0x800914FC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    draw_text(rdram, ctx);
        goto after_29;
    // 0x800914FC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_29:
    // 0x80091500: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80091504: lb          $t8, 0x69C0($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X69C0);
    // 0x80091508: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8009150C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80091510: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80091514: lw          $t1, -0xB3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB3C);
    // 0x80091518: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8009151C: lw          $t9, 0x3C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X3C);
    // 0x80091520: sll         $t0, $t1, 1
    ctx->r8 = S32(ctx->r9 << 1);
    // 0x80091524: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80091528: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x8009152C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80091530: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80091534: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80091538: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009153C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80091540: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80091544: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x80091548: jal         0x80081800
    // 0x8009154C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    menu_timestamp_render(rdram, ctx);
        goto after_30;
    // 0x8009154C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_30:
    // 0x80091550: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80091554: lb          $t5, 0x69C0($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X69C0);
    // 0x80091558: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8009155C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80091560: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80091564: lw          $t9, -0xB3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB3C);
    // 0x80091568: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8009156C: lw          $t1, 0x24($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X24);
    // 0x80091570: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80091574: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80091578: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x8009157C: addiu       $t3, $zero, 0xC0
    ctx->r11 = ADD32(0, 0XC0);
    // 0x80091580: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80091584: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80091588: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009158C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80091590: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80091594: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x80091598: jal         0x80081800
    // 0x8009159C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    menu_timestamp_render(rdram, ctx);
        goto after_31;
    // 0x8009159C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_31:
    // 0x800915A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800915A4: lw          $t5, 0x63E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X63E0);
    // 0x800915A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800915AC: beq         $t5, $at, L_80091F08
    if (ctx->r13 == ctx->r1) {
        // 0x800915B0: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80091F08;
    }
    // 0x800915B0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800915B4: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x800915B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800915BC: bne         $v0, $at, L_80091748
    if (ctx->r2 != ctx->r1) {
        // 0x800915C0: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80091748;
    }
    // 0x800915C0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800915C4: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x800915C8: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x800915CC: addiu       $t6, $t8, 0x89
    ctx->r14 = ADD32(ctx->r24, 0X89);
    // 0x800915D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800915D4: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    // 0x800915D8: jal         0x800C4EDC
    // 0x800915DC: addiu       $a2, $t8, 0x70
    ctx->r6 = ADD32(ctx->r24, 0X70);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_32;
    // 0x800915DC: addiu       $a2, $t8, 0x70
    ctx->r6 = ADD32(ctx->r24, 0X70);
    after_32:
    // 0x800915E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800915E4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800915E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800915EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800915F0: jal         0x800C5B58
    // 0x800915F4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_33;
    // 0x800915F4: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_33:
    // 0x800915F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800915FC: lw          $t7, 0x63E0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63E0);
    // 0x80091600: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091604: bgtz        $t7, L_80091654
    if (SIGNED(ctx->r15) > 0) {
        // 0x80091608: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_80091654;
    }
    // 0x80091608: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8009160C: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    // 0x80091610: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x80091614: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091618: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009161C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80091620: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80091624: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80091628: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8009162C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80091630: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80091634: addiu       $a1, $a1, 0x5B4
    ctx->r5 = ADD32(ctx->r5, 0X5B4);
    // 0x80091638: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8009163C: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x80091640: addiu       $a3, $a3, 0x72
    ctx->r7 = ADD32(ctx->r7, 0X72);
    // 0x80091644: jal         0x80078AB8
    // 0x80091648: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    texrect_draw(rdram, ctx);
        goto after_34;
    // 0x80091648: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_34:
    // 0x8009164C: b           L_80091738
    // 0x80091650: nop

        goto L_80091738;
    // 0x80091650: nop

L_80091654:
    // 0x80091654: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    // 0x80091658: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8009165C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80091660: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80091664: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80091668: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009166C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80091670: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80091674: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80091678: addiu       $a1, $a1, 0x5C4
    ctx->r5 = ADD32(ctx->r5, 0X5C4);
    // 0x8009167C: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x80091680: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80091684: addiu       $a3, $a3, 0x72
    ctx->r7 = ADD32(ctx->r7, 0X72);
    // 0x80091688: jal         0x80078AB8
    // 0x8009168C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    texrect_draw(rdram, ctx);
        goto after_35;
    // 0x8009168C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_35:
    // 0x80091690: lw          $s7, 0x80($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X80);
    // 0x80091694: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80091698: addiu       $s0, $s0, 0x648
    ctx->r16 = ADD32(ctx->r16, 0X648);
    // 0x8009169C: addiu       $s7, $s7, 0x97
    ctx->r23 = ADD32(ctx->r23, 0X97);
L_800916A0:
    // 0x800916A0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800916A4: lw          $t6, 0x414($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X414);
    // 0x800916A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800916AC: bne         $s5, $t6, L_800916F4
    if (ctx->r21 != ctx->r14) {
        // 0x800916B0: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_800916F4;
    }
    // 0x800916B0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800916B4: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x800916B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800916BC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800916C0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800916C4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800916C8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800916CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800916D0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800916D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800916D8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800916DC: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    // 0x800916E0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800916E4: jal         0x80078AB8
    // 0x800916E8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    texrect_draw(rdram, ctx);
        goto after_36;
    // 0x800916E8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_36:
    // 0x800916EC: b           L_80091728
    // 0x800916F0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
        goto L_80091728;
    // 0x800916F0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800916F4:
    // 0x800916F4: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x800916F8: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x800916FC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80091700: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80091704: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80091708: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8009170C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80091710: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80091714: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    // 0x80091718: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x8009171C: jal         0x80078AB8
    // 0x80091720: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    texrect_draw(rdram, ctx);
        goto after_37;
    // 0x80091720: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_37:
    // 0x80091724: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80091728:
    // 0x80091728: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009172C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80091730: bne         $s5, $at, L_800916A0
    if (ctx->r21 != ctx->r1) {
        // 0x80091734: addiu       $s7, $s7, 0x18
        ctx->r23 = ADD32(ctx->r23, 0X18);
            goto L_800916A0;
    }
    // 0x80091734: addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
L_80091738:
    // 0x80091738: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009173C: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x80091740: b           L_80091870
    // 0x80091744: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
        goto L_80091870;
    // 0x80091744: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80091748:
    // 0x80091748: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8009174C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80091750: bne         $t8, $zero, L_80091870
    if (ctx->r24 != 0) {
        // 0x80091754: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80091870;
    }
    // 0x80091754: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80091758: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009175C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80091760: addiu       $t9, $t9, 0x688
    ctx->r25 = ADD32(ctx->r25, 0X688);
    // 0x80091764: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80091768: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8009176C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80091770: addiu       $s2, $s2, 0x69C4
    ctx->r18 = ADD32(ctx->r18, 0X69C4);
    // 0x80091774: addiu       $s1, $s1, 0x660
    ctx->r17 = ADD32(ctx->r17, 0X660);
    // 0x80091778: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8009177C: mflo        $s3
    ctx->r19 = lo;
    // 0x80091780: sll         $t7, $s3, 1
    ctx->r15 = S32(ctx->r19 << 1);
    // 0x80091784: blez        $v0, L_8009186C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80091788: addu        $s0, $t7, $t9
        ctx->r16 = ADD32(ctx->r15, ctx->r25);
            goto L_8009186C;
    }
    // 0x80091788: addu        $s0, $t7, $t9
    ctx->r16 = ADD32(ctx->r15, ctx->r25);
L_8009178C:
    // 0x8009178C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091790: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x80091794: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80091798: bne         $v0, $at, L_800917AC
    if (ctx->r2 != ctx->r1) {
        // 0x8009179C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800917AC;
    }
    // 0x8009179C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800917A0: lw          $t1, 0x63E0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X63E0);
    // 0x800917A4: nop

    // 0x800917A8: beq         $s5, $t1, L_800917C8
    if (ctx->r21 == ctx->r9) {
        // 0x800917AC: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800917C8;
    }
L_800917AC:
    // 0x800917AC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800917B0: bne         $at, $zero, L_8009180C
    if (ctx->r1 != 0) {
        // 0x800917B4: addu        $t0, $s2, $s5
        ctx->r8 = ADD32(ctx->r18, ctx->r21);
            goto L_8009180C;
    }
    // 0x800917B4: addu        $t0, $s2, $s5
    ctx->r8 = ADD32(ctx->r18, ctx->r21);
    // 0x800917B8: lb          $t2, 0x0($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X0);
    // 0x800917BC: nop

    // 0x800917C0: bne         $t2, $zero, L_8009180C
    if (ctx->r10 != 0) {
        // 0x800917C4: nop
    
            goto L_8009180C;
    }
    // 0x800917C4: nop

L_800917C8:
    // 0x800917C8: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x800917CC: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800917D0: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800917D4: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800917D8: addiu       $t5, $v1, 0x17
    ctx->r13 = ADD32(ctx->r3, 0X17);
    // 0x800917DC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800917E0: addiu       $a2, $v1, -0x2
    ctx->r6 = ADD32(ctx->r3, -0X2);
    // 0x800917E4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800917E8: addiu       $a1, $v0, -0x2
    ctx->r5 = ADD32(ctx->r2, -0X2);
    // 0x800917EC: jal         0x800C4EDC
    // 0x800917F0: addiu       $a3, $v0, 0x32
    ctx->r7 = ADD32(ctx->r2, 0X32);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_38;
    // 0x800917F0: addiu       $a3, $v0, 0x32
    ctx->r7 = ADD32(ctx->r2, 0X32);
    after_38:
    // 0x800917F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800917F8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800917FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80091800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80091804: jal         0x800C5B58
    // 0x80091808: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_39;
    // 0x80091808: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_39:
L_8009180C:
    // 0x8009180C: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80091810: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80091814: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x80091818: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009181C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80091820: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x80091824: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80091828: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009182C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80091830: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80091834: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80091838: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009183C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091840: addu        $a3, $t8, $t6
    ctx->r7 = ADD32(ctx->r24, ctx->r14);
    // 0x80091844: jal         0x80078AB8
    // 0x80091848: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    texrect_draw(rdram, ctx);
        goto after_40;
    // 0x80091848: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_40:
    // 0x8009184C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80091850: slt         $at, $s5, $s7
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80091854: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80091858: bne         $at, $zero, L_8009178C
    if (ctx->r1 != 0) {
        // 0x8009185C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8009178C;
    }
    // 0x8009185C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80091860: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091864: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x80091868: nop

L_8009186C:
    // 0x8009186C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80091870:
    // 0x80091870: beq         $at, $zero, L_80091888
    if (ctx->r1 == 0) {
        // 0x80091874: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80091888;
    }
    // 0x80091874: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80091878: lw          $t2, 0x63E0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X63E0);
    // 0x8009187C: nop

    // 0x80091880: bne         $t2, $zero, L_80091A2C
    if (ctx->r10 != 0) {
        // 0x80091884: lw          $s0, 0x80($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X80);
            goto L_80091A2C;
    }
    // 0x80091884: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
L_80091888:
    // 0x80091888: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8009188C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80091890: bne         $t3, $zero, L_80091A2C
    if (ctx->r11 != 0) {
        // 0x80091894: lw          $s0, 0x80($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X80);
            goto L_80091A2C;
    }
    // 0x80091894: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x80091898: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009189C: lw          $s7, 0x80($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X80);
    // 0x800918A0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800918A4: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x800918A8: addiu       $s7, $s7, 0x8B
    ctx->r23 = ADD32(ctx->r23, 0X8B);
    // 0x800918AC: mflo        $s3
    ctx->r19 = lo;
    // 0x800918B0: sra         $t5, $s3, 1
    ctx->r13 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800918B4: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x800918B8: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_800918BC:
    // 0x800918BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800918C0: sllv        $t6, $t8, $s5
    ctx->r14 = S32(ctx->r24 << (ctx->r21 & 31));
    // 0x800918C4: and         $t9, $t6, $t7
    ctx->r25 = ctx->r14 & ctx->r15;
    // 0x800918C8: beq         $t9, $zero, L_80091A1C
    if (ctx->r25 == 0) {
        // 0x800918CC: nop
    
            goto L_80091A1C;
    }
    // 0x800918CC: nop

    // 0x800918D0: blez        $v0, L_80091A18
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800918D4: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80091A18;
    }
    // 0x800918D4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800918D8: sll         $t1, $s5, 2
    ctx->r9 = S32(ctx->r21 << 2);
    // 0x800918DC: subu        $t1, $t1, $s5
    ctx->r9 = SUB32(ctx->r9, ctx->r21);
    // 0x800918E0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800918E4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800918E8: addiu       $t4, $t4, 0x6B0
    ctx->r12 = ADD32(ctx->r12, 0X6B0);
    // 0x800918EC: addiu       $t2, $t2, 0x624
    ctx->r10 = ADD32(ctx->r10, 0X624);
    // 0x800918F0: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x800918F4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800918F8: sll         $t3, $s3, 1
    ctx->r11 = S32(ctx->r19 << 1);
    // 0x800918FC: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x80091900: addiu       $s1, $s1, 0x69C0
    ctx->r17 = ADD32(ctx->r17, 0X69C0);
    // 0x80091904: addu        $s2, $t0, $t2
    ctx->r18 = ADD32(ctx->r8, ctx->r10);
L_80091908:
    // 0x80091908: lb          $t5, 0x0($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X0);
    // 0x8009190C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80091910: bne         $s5, $t5, L_80091958
    if (ctx->r21 != ctx->r13) {
        // 0x80091914: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_80091958;
    }
    // 0x80091914: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80091918: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x8009191C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091920: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x80091924: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x80091928: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009192C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80091930: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80091934: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80091938: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8009193C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80091940: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091944: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80091948: jal         0x80078AB8
    // 0x8009194C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    texrect_draw(rdram, ctx);
        goto after_41;
    // 0x8009194C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_41:
    // 0x80091950: b           L_800919FC
    // 0x80091954: nop

        goto L_800919FC;
    // 0x80091954: nop

L_80091958:
    // 0x80091958: lw          $t2, -0xB3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB3C);
    // 0x8009195C: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x80091960: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80091964: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80091968: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8009196C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091970: andi        $t8, $t5, 0x2
    ctx->r24 = ctx->r13 & 0X2;
    // 0x80091974: beq         $t8, $zero, L_800919BC
    if (ctx->r24 == 0) {
        // 0x80091978: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_800919BC;
    }
    // 0x80091978: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8009197C: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x80091980: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091984: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x80091988: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x8009198C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80091990: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80091994: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80091998: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8009199C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800919A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800919A4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800919A8: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800919AC: jal         0x80078AB8
    // 0x800919B0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    texrect_draw(rdram, ctx);
        goto after_42;
    // 0x800919B0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_42:
    // 0x800919B4: b           L_800919FC
    // 0x800919B8: nop

        goto L_800919FC;
    // 0x800919B8: nop

L_800919BC:
    // 0x800919BC: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x800919C0: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x800919C4: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x800919C8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800919CC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800919D0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800919D4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800919D8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800919DC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800919E0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800919E4: bgez        $t4, L_800919F4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800919E8: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800919F4;
    }
    // 0x800919E8: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800919EC: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800919F0: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800919F4:
    // 0x800919F4: jal         0x80078AB8
    // 0x800919F8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    texrect_draw(rdram, ctx);
        goto after_43;
    // 0x800919F8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_43:
L_800919FC:
    // 0x800919FC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091A00: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x80091A04: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80091A08: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80091A0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80091A10: bne         $at, $zero, L_80091908
    if (ctx->r1 != 0) {
        // 0x80091A14: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80091908;
    }
    // 0x80091A14: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80091A18:
    // 0x80091A18: addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
L_80091A1C:
    // 0x80091A1C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80091A20: bne         $s5, $s6, L_800918BC
    if (ctx->r21 != ctx->r22) {
        // 0x80091A24: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_800918BC;
    }
    // 0x80091A24: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80091A28: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
L_80091A2C:
    // 0x80091A2C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80091A30: lb          $v1, 0x69C0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X69C0);
    // 0x80091A34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091A38: addiu       $s0, $s0, 0x8B
    ctx->r16 = ADD32(ctx->r16, 0X8B);
    // 0x80091A3C: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80091A40: bne         $v1, $at, L_80091A4C
    if (ctx->r3 != ctx->r1) {
        // 0x80091A44: or          $s7, $s0, $zero
        ctx->r23 = ctx->r16 | 0;
            goto L_80091A4C;
    }
    // 0x80091A44: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
    // 0x80091A48: addiu       $s7, $s0, 0x2
    ctx->r23 = ADD32(ctx->r16, 0X2);
L_80091A4C:
    // 0x80091A4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80091A50: bne         $v0, $at, L_80091B28
    if (ctx->r2 != ctx->r1) {
        // 0x80091A54: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80091B28;
    }
    // 0x80091A54: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80091A58: lw          $t8, 0x63E0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63E0);
    // 0x80091A5C: nop

    // 0x80091A60: bne         $t8, $zero, L_80091AC8
    if (ctx->r24 != 0) {
        // 0x80091A64: nop
    
            goto L_80091AC8;
    }
    // 0x80091A64: nop

    // 0x80091A68: multu       $v1, $s6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091A6C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80091A70: addiu       $s1, $s1, 0x624
    ctx->r17 = ADD32(ctx->r17, 0X624);
    // 0x80091A74: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x80091A78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091A7C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80091A80: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80091A84: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80091A88: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091A8C: addiu       $a2, $zero, 0x95
    ctx->r6 = ADD32(0, 0X95);
    // 0x80091A90: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80091A94: mflo        $t6
    ctx->r14 = lo;
    // 0x80091A98: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80091A9C: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x80091AA0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80091AA4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80091AA8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80091AAC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80091AB0: jal         0x80078AB8
    // 0x80091AB4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    texrect_draw(rdram, ctx);
        goto after_44;
    // 0x80091AB4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_44:
    // 0x80091AB8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091ABC: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x80091AC0: b           L_80091B28
    // 0x80091AC4: nop

        goto L_80091B28;
    // 0x80091AC4: nop

L_80091AC8:
    // 0x80091AC8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80091ACC: lw          $t4, 0x414($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X414);
    // 0x80091AD0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80091AD4: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091AD8: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x80091ADC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091AE0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80091AE4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80091AE8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80091AEC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80091AF0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80091AF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80091AF8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091AFC: addiu       $a2, $zero, 0x95
    ctx->r6 = ADD32(0, 0X95);
    // 0x80091B00: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80091B04: mflo        $t5
    ctx->r13 = lo;
    // 0x80091B08: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80091B0C: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80091B10: lw          $a1, 0x648($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X648);
    // 0x80091B14: jal         0x80078AB8
    // 0x80091B18: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    texrect_draw(rdram, ctx);
        goto after_45;
    // 0x80091B18: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_45:
    // 0x80091B1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091B20: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x80091B24: nop

L_80091B28:
    // 0x80091B28: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80091B2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091B30: bne         $v0, $at, L_80091BF8
    if (ctx->r2 != ctx->r1) {
        // 0x80091B34: addiu       $s1, $s1, 0x624
        ctx->r17 = ADD32(ctx->r17, 0X624);
            goto L_80091BF8;
    }
    // 0x80091B34: addiu       $s1, $s1, 0x624
    ctx->r17 = ADD32(ctx->r17, 0X624);
    // 0x80091B38: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80091B3C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80091B40: bne         $t2, $zero, L_80091BF8
    if (ctx->r10 != 0) {
        // 0x80091B44: nop
    
            goto L_80091BF8;
    }
    // 0x80091B44: nop

    // 0x80091B48: lb          $t0, 0x69C0($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X69C0);
    // 0x80091B4C: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x80091B50: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091B54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091B58: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80091B5C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80091B60: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80091B64: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80091B68: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
    // 0x80091B6C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091B70: addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    // 0x80091B74: mflo        $t3
    ctx->r11 = lo;
    // 0x80091B78: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80091B7C: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x80091B80: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x80091B84: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80091B88: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80091B8C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80091B90: jal         0x80078AB8
    // 0x80091B94: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    texrect_draw(rdram, ctx);
        goto after_46;
    // 0x80091B94: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_46:
    // 0x80091B98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80091B9C: lb          $v0, 0x69C1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X69C1);
    // 0x80091BA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091BA4: bne         $v0, $at, L_80091BB0
    if (ctx->r2 != ctx->r1) {
        // 0x80091BA8: nop
    
            goto L_80091BB0;
    }
    // 0x80091BA8: nop

    // 0x80091BAC: addiu       $s7, $s0, 0x2
    ctx->r23 = ADD32(ctx->r16, 0X2);
L_80091BB0:
    // 0x80091BB0: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091BB4: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x80091BB8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091BBC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80091BC0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80091BC4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80091BC8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091BCC: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80091BD0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80091BD4: mflo        $t1
    ctx->r9 = lo;
    // 0x80091BD8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80091BDC: addu        $t0, $s1, $t2
    ctx->r8 = ADD32(ctx->r17, ctx->r10);
    // 0x80091BE0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80091BE4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80091BE8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80091BEC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80091BF0: jal         0x80078AB8
    // 0x80091BF4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    texrect_draw(rdram, ctx);
        goto after_47;
    // 0x80091BF4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_47:
L_80091BF8:
    // 0x80091BF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091BFC: jal         0x8007B3D0
    // 0x80091C00: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    rendermode_reset(rdram, ctx);
        goto after_48;
    // 0x80091C00: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_48:
    // 0x80091C04: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80091C08: lw          $t6, -0xB44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB44);
    // 0x80091C0C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80091C10: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80091C14: beq         $at, $zero, L_80091CA0
    if (ctx->r1 == 0) {
        // 0x80091C18: lw          $t4, 0x74($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X74);
            goto L_80091CA0;
    }
    // 0x80091C18: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80091C1C: bne         $t7, $zero, L_80091C9C
    if (ctx->r15 != 0) {
        // 0x80091C20: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80091C9C;
    }
    // 0x80091C20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091C24: addiu       $v0, $v0, -0x8A4
    ctx->r2 = ADD32(ctx->r2, -0X8A4);
    // 0x80091C28: lui         $at, 0xC250
    ctx->r1 = S32(0XC250 << 16);
    // 0x80091C2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80091C30: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80091C34: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80091C38: swc1        $f8, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f8.u32l;
    // 0x80091C3C: lw          $t1, -0xB44($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB44);
    // 0x80091C40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80091C44: bne         $t1, $at, L_80091C6C
    if (ctx->r9 != ctx->r1) {
        // 0x80091C48: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80091C6C;
    }
    // 0x80091C48: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80091C4C: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x80091C50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80091C54: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80091C58: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80091C5C: jal         0x8009CA60
    // 0x80091C60: swc1        $f10, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_49;
    // 0x80091C60: swc1        $f10, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f10.u32l;
    after_49:
    // 0x80091C64: b           L_80091CA0
    // 0x80091C68: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
        goto L_80091CA0;
    // 0x80091C68: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
L_80091C6C:
    // 0x80091C6C: lui         $at, 0xC240
    ctx->r1 = S32(0XC240 << 16);
    // 0x80091C70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80091C74: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80091C78: jal         0x8009CA60
    // 0x80091C7C: swc1        $f16, 0xEC($t0)
    MEM_W(0XEC, ctx->r8) = ctx->f16.u32l;
    menu_element_render(rdram, ctx);
        goto after_50;
    // 0x80091C7C: swc1        $f16, 0xEC($t0)
    MEM_W(0XEC, ctx->r8) = ctx->f16.u32l;
    after_50:
    // 0x80091C80: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80091C84: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80091C88: lw          $t3, -0x8A4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X8A4);
    // 0x80091C8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80091C90: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80091C94: jal         0x8009CA60
    // 0x80091C98: swc1        $f18, 0xEC($t3)
    MEM_W(0XEC, ctx->r11) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_51;
    // 0x80091C98: swc1        $f18, 0xEC($t3)
    MEM_W(0XEC, ctx->r11) = ctx->f18.u32l;
    after_51:
L_80091C9C:
    // 0x80091C9C: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
L_80091CA0:
    // 0x80091CA0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80091CA4: beq         $t4, $zero, L_80091F08
    if (ctx->r12 == 0) {
        // 0x80091CA8: nop
    
            goto L_80091F08;
    }
    // 0x80091CA8: nop

    // 0x80091CAC: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x80091CB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80091CB4: lw          $a0, 0x220($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X220);
    // 0x80091CB8: jal         0x800C4DA0
    // 0x80091CBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_text_width(rdram, ctx);
        goto after_52;
    // 0x80091CBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_52:
    // 0x80091CC0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80091CC4: addiu       $s2, $s2, 0x6E4
    ctx->r18 = ADD32(ctx->r18, 0X6E4);
    // 0x80091CC8: lh          $v1, 0x4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X4);
    // 0x80091CCC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091CD0: addiu       $t8, $v1, -0xC
    ctx->r24 = ADD32(ctx->r3, -0XC);
    // 0x80091CD4: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80091CD8: beq         $at, $zero, L_80091CE8
    if (ctx->r1 == 0) {
        // 0x80091CDC: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_80091CE8;
    }
    // 0x80091CDC: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80091CE0: b           L_80091CEC
    // 0x80091CE4: addiu       $s4, $v0, 0xC
    ctx->r20 = ADD32(ctx->r2, 0XC);
        goto L_80091CEC;
    // 0x80091CE4: addiu       $s4, $v0, 0xC
    ctx->r20 = ADD32(ctx->r2, 0XC);
L_80091CE8:
    // 0x80091CE8: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
L_80091CEC:
    // 0x80091CEC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80091CF0: lw          $t3, 0x665C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X665C);
    // 0x80091CF4: lh          $t6, 0x2($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X2);
    // 0x80091CF8: lh          $t9, 0x6($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X6);
    // 0x80091CFC: lh          $t1, 0x8($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X8);
    // 0x80091D00: lh          $t2, 0xA($s2)
    ctx->r10 = MEM_H(ctx->r18, 0XA);
    // 0x80091D04: lui         $t0, 0xB0E0
    ctx->r8 = S32(0XB0E0 << 16);
    // 0x80091D08: ori         $t0, $t0, 0xC0FF
    ctx->r8 = ctx->r8 | 0XC0FF;
    // 0x80091D0C: sra         $a1, $s4, 1
    ctx->r5 = S32(SIGNED(ctx->r20) >> 1);
    // 0x80091D10: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x80091D14: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80091D18: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80091D1C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80091D20: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80091D24: subu        $a2, $t7, $t6
    ctx->r6 = SUB32(ctx->r15, ctx->r14);
    // 0x80091D28: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80091D2C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80091D30: jal         0x80080580
    // 0x80091D34: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    func_80080580(rdram, ctx);
        goto after_53;
    // 0x80091D34: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_53:
    // 0x80091D38: jal         0x80080E6C
    // 0x80091D3C: nop

    menu_geometry_end(rdram, ctx);
        goto after_54;
    // 0x80091D3C: nop

    after_54:
    // 0x80091D40: jal         0x800C42EC
    // 0x80091D44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_55;
    // 0x80091D44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_55:
    // 0x80091D48: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80091D4C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80091D50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80091D54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80091D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80091D5C: jal         0x800C4384
    // 0x80091D60: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_56;
    // 0x80091D60: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_56:
    // 0x80091D64: lh          $t7, 0xE($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XE);
    // 0x80091D68: lh          $t6, 0x2($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X2);
    // 0x80091D6C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80091D70: lw          $t2, -0xB60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB60);
    // 0x80091D74: lh          $t5, 0xC($s2)
    ctx->r13 = MEM_H(ctx->r18, 0XC);
    // 0x80091D78: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x80091D7C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x80091D80: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80091D84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091D88: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80091D8C: lw          $a3, 0x220($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X220);
    // 0x80091D90: addu        $a1, $t5, $t8
    ctx->r5 = ADD32(ctx->r13, ctx->r24);
    // 0x80091D94: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    // 0x80091D98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80091D9C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80091DA0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80091DA4: jal         0x800C4440
    // 0x80091DA8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    draw_text(rdram, ctx);
        goto after_57;
    // 0x80091DA8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_57:
    // 0x80091DAC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80091DB0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80091DB4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80091DB8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80091DBC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80091DC0: jal         0x800C4384
    // 0x80091DC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_58;
    // 0x80091DC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_58:
    // 0x80091DC8: lh          $t8, 0xE($s2)
    ctx->r24 = MEM_H(ctx->r18, 0XE);
    // 0x80091DCC: lh          $t7, 0x2($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X2);
    // 0x80091DD0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80091DD4: lw          $t1, -0xB60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB60);
    // 0x80091DD8: lh          $t4, 0xC($s2)
    ctx->r12 = MEM_H(ctx->r18, 0XC);
    // 0x80091DDC: lh          $t5, 0x0($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X0);
    // 0x80091DE0: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80091DE4: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80091DE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091DEC: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80091DF0: lw          $a3, 0x220($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X220);
    // 0x80091DF4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x80091DF8: addu        $a2, $t6, $t9
    ctx->r6 = ADD32(ctx->r14, ctx->r25);
    // 0x80091DFC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80091E00: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80091E04: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80091E08: jal         0x800C4440
    // 0x80091E0C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    draw_text(rdram, ctx);
        goto after_59;
    // 0x80091E0C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_59:
    // 0x80091E10: jal         0x80068508
    // 0x80091E14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_60;
    // 0x80091E14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_60:
    // 0x80091E18: jal         0x8007BF1C
    // 0x80091E1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_61;
    // 0x80091E1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_61:
    // 0x80091E20: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x80091E24: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80091E28: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80091E2C: addiu       $s0, $s0, -0xB58
    ctx->r16 = ADD32(ctx->r16, -0XB58);
    // 0x80091E30: addiu       $s1, $s1, -0xB54
    ctx->r17 = ADD32(ctx->r17, -0XB54);
    // 0x80091E34: addiu       $s5, $s5, 0x410
    ctx->r21 = ADD32(ctx->r21, 0X410);
    // 0x80091E38: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80091E3C: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_80091E40:
    // 0x80091E40: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x80091E44: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80091E48: bne         $s4, $t0, L_80091E80
    if (ctx->r20 != ctx->r8) {
        // 0x80091E4C: sll         $v0, $s4, 1
        ctx->r2 = S32(ctx->r20 << 1);
            goto L_80091E80;
    }
    // 0x80091E4C: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x80091E50: lw          $t3, 0x63E0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X63E0);
    // 0x80091E54: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x80091E58: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x80091E5C: beq         $at, $zero, L_80091E74
    if (ctx->r1 == 0) {
        // 0x80091E60: addiu       $t5, $zero, 0xFF
        ctx->r13 = ADD32(0, 0XFF);
            goto L_80091E74;
    }
    // 0x80091E60: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80091E64: subu        $v0, $t5, $t4
    ctx->r2 = SUB32(ctx->r13, ctx->r12);
    // 0x80091E68: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80091E6C: b           L_80091E7C
    // 0x80091E70: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
        goto L_80091E7C;
    // 0x80091E70: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_80091E74:
    // 0x80091E74: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80091E78: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_80091E7C:
    // 0x80091E7C: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
L_80091E80:
    // 0x80091E80: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80091E84: addu        $v1, $s2, $t8
    ctx->r3 = ADD32(ctx->r18, ctx->r24);
    // 0x80091E88: lh          $t7, 0x10($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X10);
    // 0x80091E8C: lh          $t6, 0x0($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X0);
    // 0x80091E90: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80091E94: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80091E98: addiu       $t1, $t9, -0xA0
    ctx->r9 = ADD32(ctx->r25, -0XA0);
    // 0x80091E9C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80091EA0: addiu       $a1, $a1, -0x8A4
    ctx->r5 = ADD32(ctx->r5, -0X8A4);
    // 0x80091EA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80091EA8: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80091EAC: addiu       $t6, $v0, 0x2
    ctx->r14 = ADD32(ctx->r2, 0X2);
    // 0x80091EB0: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    // 0x80091EB4: lh          $t0, 0x12($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X12);
    // 0x80091EB8: lh          $t5, 0x2($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X2);
    // 0x80091EBC: negu        $t3, $t0
    ctx->r11 = SUB32(0, ctx->r8);
    // 0x80091EC0: subu        $t4, $t3, $t5
    ctx->r12 = SUB32(ctx->r11, ctx->r13);
    // 0x80091EC4: addiu       $t8, $t4, 0x78
    ctx->r24 = ADD32(ctx->r12, 0X78);
    // 0x80091EC8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80091ECC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80091ED0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80091ED4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80091ED8: swc1        $f10, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f10.u32l;
    // 0x80091EDC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80091EE0: jal         0x8009CA60
    // 0x80091EE4: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    menu_element_render(rdram, ctx);
        goto after_62;
    // 0x80091EE4: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    after_62:
    // 0x80091EE8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80091EEC: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x80091EF0: bne         $s4, $s6, L_80091E40
    if (ctx->r20 != ctx->r22) {
        // 0x80091EF4: sb          $s3, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r19;
            goto L_80091E40;
    }
    // 0x80091EF4: sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
    // 0x80091EF8: jal         0x8007BF1C
    // 0x80091EFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_63;
    // 0x80091EFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_63:
    // 0x80091F00: jal         0x80068508
    // 0x80091F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_64;
    // 0x80091F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_64:
L_80091F08:
    // 0x80091F08: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80091F0C: lw          $t1, 0x69C8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X69C8);
    // 0x80091F10: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80091F14: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80091F18: beq         $at, $zero, L_80092010
    if (ctx->r1 == 0) {
        // 0x80091F1C: nop
    
            goto L_80092010;
    }
    // 0x80091F1C: nop

    // 0x80091F20: jal         0x8007BF1C
    // 0x80091F24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_65;
    // 0x80091F24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_65:
    // 0x80091F28: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80091F2C: lw          $t2, -0xB6C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB6C);
    // 0x80091F30: addiu       $s5, $zero, 0xB
    ctx->r21 = ADD32(0, 0XB);
    // 0x80091F34: beq         $t2, $zero, L_80091F40
    if (ctx->r10 == 0) {
        // 0x80091F38: lui         $at, 0x4228
        ctx->r1 = S32(0X4228 << 16);
            goto L_80091F40;
    }
    // 0x80091F38: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x80091F3C: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_80091F40:
    // 0x80091F40: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80091F44: lw          $t0, -0x8A4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X8A4);
    // 0x80091F48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80091F4C: sll         $s0, $s5, 5
    ctx->r16 = S32(ctx->r21 << 5);
    // 0x80091F50: addu        $t3, $t0, $s0
    ctx->r11 = ADD32(ctx->r8, ctx->r16);
    // 0x80091F54: swc1        $f16, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f16.u32l;
    // 0x80091F58: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80091F5C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80091F60: lw          $t8, -0xB3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB3C);
    // 0x80091F64: lw          $t4, 0x4($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X4);
    // 0x80091F68: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80091F6C: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x80091F70: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80091F74: nop

    // 0x80091F78: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x80091F7C: bne         $t1, $zero, L_80091F90
    if (ctx->r9 != 0) {
        // 0x80091F80: nop
    
            goto L_80091F90;
    }
    // 0x80091F80: nop

    // 0x80091F84: jal         0x8009EC60
    // 0x80091F88: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_66;
    // 0x80091F88: nop

    after_66:
    // 0x80091F8C: beq         $v0, $zero, L_80091FB0
    if (ctx->r2 == 0) {
        // 0x80091F90: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_80091FB0;
    }
L_80091F90:
    // 0x80091F90: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80091F94: lw          $t2, -0x8A4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X8A4);
    // 0x80091F98: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x80091F9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80091FA0: addu        $t0, $t2, $s0
    ctx->r8 = ADD32(ctx->r10, ctx->r16);
    // 0x80091FA4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80091FA8: jal         0x8009CA60
    // 0x80091FAC: swc1        $f18, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_67;
    // 0x80091FAC: swc1        $f18, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f18.u32l;
    after_67:
L_80091FB0:
    // 0x80091FB0: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80091FB4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80091FB8: lw          $t8, -0xB3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB3C);
    // 0x80091FBC: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80091FC0: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x80091FC4: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80091FC8: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80091FCC: nop

    // 0x80091FD0: andi        $t9, $t6, 0x4
    ctx->r25 = ctx->r14 & 0X4;
    // 0x80091FD4: bne         $t9, $zero, L_80091FE8
    if (ctx->r25 != 0) {
        // 0x80091FD8: nop
    
            goto L_80091FE8;
    }
    // 0x80091FD8: nop

    // 0x80091FDC: jal         0x8009EC60
    // 0x80091FE0: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_68;
    // 0x80091FE0: nop

    after_68:
    // 0x80091FE4: beq         $v0, $zero, L_80092008
    if (ctx->r2 == 0) {
        // 0x80091FE8: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_80092008;
    }
L_80091FE8:
    // 0x80091FE8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80091FEC: lw          $t1, -0x8A4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X8A4);
    // 0x80091FF0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80091FF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80091FF8: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80091FFC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80092000: jal         0x8009CA60
    // 0x80092004: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    menu_element_render(rdram, ctx);
        goto after_69;
    // 0x80092004: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    after_69:
L_80092008:
    // 0x80092008: jal         0x8007BF1C
    // 0x8009200C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_70;
    // 0x8009200C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_70:
L_80092010:
    // 0x80092010: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80092014: lw          $t0, -0xB44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB44);
    // 0x80092018: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009201C: bne         $t0, $at, L_80092090
    if (ctx->r8 != ctx->r1) {
        // 0x80092020: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_80092090;
    }
    // 0x80092020: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092024: lw          $t3, 0x63E0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X63E0);
    // 0x80092028: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009202C: bltz        $t3, L_80092090
    if (SIGNED(ctx->r11) < 0) {
        // 0x80092030: nop
    
            goto L_80092090;
    }
    // 0x80092030: nop

    // 0x80092034: lw          $a0, -0xB3C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XB3C);
    // 0x80092038: jal         0x80092BE0
    // 0x8009203C: nop

    trackmenu_staff_beaten(rdram, ctx);
        goto after_71;
    // 0x8009203C: nop

    after_71:
    // 0x80092040: bltz        $v0, L_80092090
    if (SIGNED(ctx->r2) < 0) {
        // 0x80092044: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80092090;
    }
    // 0x80092044: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092048: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    // 0x8009204C: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80092050: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80092054: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80092058: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009205C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80092060: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80092064: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80092068: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009206C: addiu       $a1, $a1, 0x614
    ctx->r5 = ADD32(ctx->r5, 0X614);
    // 0x80092070: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80092074: addiu       $a2, $zero, 0xCC
    ctx->r6 = ADD32(0, 0XCC);
    // 0x80092078: addiu       $a3, $a3, 0x7A
    ctx->r7 = ADD32(ctx->r7, 0X7A);
    // 0x8009207C: jal         0x80078AB8
    // 0x80092080: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    texrect_draw(rdram, ctx);
        goto after_72;
    // 0x80092080: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_72:
    // 0x80092084: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092088: jal         0x8007B3D0
    // 0x8009208C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    rendermode_reset(rdram, ctx);
        goto after_73;
    // 0x8009208C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_73:
L_80092090:
    // 0x80092090: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80092094: lw          $t6, 0x69C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X69C8);
    // 0x80092098: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009209C: beq         $t6, $at, L_80092150
    if (ctx->r14 == ctx->r1) {
        // 0x800920A0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80092150;
    }
    // 0x800920A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800920A4: lw          $v0, 0x63E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63E0);
    // 0x800920A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800920AC: bne         $v0, $at, L_800920C4
    if (ctx->r2 != ctx->r1) {
        // 0x800920B0: nop
    
            goto L_800920C4;
    }
    // 0x800920B0: nop

    // 0x800920B4: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800920B8: nop

    // 0x800920BC: beq         $t9, $zero, L_800920E4
    if (ctx->r25 == 0) {
        // 0x800920C0: nop
    
            goto L_800920E4;
    }
    // 0x800920C0: nop

L_800920C4:
    // 0x800920C4: bne         $s6, $v0, L_800920DC
    if (ctx->r22 != ctx->r2) {
        // 0x800920C8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800920DC;
    }
    // 0x800920C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800920CC: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x800920D0: nop

    // 0x800920D4: bne         $t1, $zero, L_800920E4
    if (ctx->r9 != 0) {
        // 0x800920D8: nop
    
            goto L_800920E4;
    }
    // 0x800920D8: nop

L_800920DC:
    // 0x800920DC: bne         $v0, $at, L_80092154
    if (ctx->r2 != ctx->r1) {
        // 0x800920E0: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_80092154;
    }
    // 0x800920E0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
L_800920E4:
    // 0x800920E4: jal         0x800C42EC
    // 0x800920E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_74;
    // 0x800920E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_74:
    // 0x800920EC: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800920F0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800920F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800920F8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800920FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80092100: jal         0x800C4384
    // 0x80092104: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_text_colour(rdram, ctx);
        goto after_75;
    // 0x80092104: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_75:
    // 0x80092108: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009210C: lw          $t0, 0x69C8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X69C8);
    // 0x80092110: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092114: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80092118: bne         $at, $zero, L_80092130
    if (ctx->r1 != 0) {
        // 0x8009211C: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_80092130;
    }
    // 0x8009211C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80092120: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x80092124: nop

    // 0x80092128: addiu       $t8, $t3, 0x18
    ctx->r24 = ADD32(ctx->r11, 0X18);
    // 0x8009212C: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
L_80092130:
    // 0x80092130: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80092134: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80092138: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8009213C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80092140: addiu       $a3, $a3, -0x7DC4
    ctx->r7 = ADD32(ctx->r7, -0X7DC4);
    // 0x80092144: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80092148: jal         0x800C4440
    // 0x8009214C: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    draw_text(rdram, ctx);
        goto after_76;
    // 0x8009214C: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    after_76:
L_80092150:
    // 0x80092150: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
L_80092154:
    // 0x80092154: sw          $t4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r12;
L_80092158:
    // 0x80092158: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8009215C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80092160: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80092164: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80092168: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8009216C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80092170: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80092174: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80092178: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8009217C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80092180: jr          $ra
    // 0x80092184: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80092184: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void render_ortho_triangle_image(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068BF4: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80068BF8: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x80068BFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80068C00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068C04: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80068C08: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80068C0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80068C10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80068C14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80068C18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80068C1C: beq         $t6, $zero, L_80068F88
    if (ctx->r14 == 0) {
        // 0x80068C20: sw          $a1, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r5;
            goto L_80068F88;
    }
    // 0x80068C20: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x80068C24: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80068C28: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80068C2C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80068C30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068C34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068C38: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80068C3C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80068C40: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80068C44: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80068C48: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80068C4C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80068C50: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80068C54: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80068C58: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80068C5C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068C60: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068C64: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80068C68: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80068C6C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80068C70: addiu       $s4, $s4, 0xD1C
    ctx->r20 = ADD32(ctx->r20, 0XD1C);
    // 0x80068C74: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80068C78: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80068C7C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80068C80: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80068C84: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80068C88: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80068C8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068C90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068C94: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80068C98: sb          $a1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r5;
    // 0x80068C9C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80068CA0: sb          $a1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r5;
    // 0x80068CA4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80068CA8: sb          $a1, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r5;
    // 0x80068CAC: sb          $a1, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r5;
    // 0x80068CB0: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x80068CB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80068CB8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80068CBC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80068CC0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068CC4: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80068CC8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80068CCC: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x80068CD0: andi        $t8, $t7, 0x6
    ctx->r24 = ctx->r15 & 0X6;
    // 0x80068CD4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80068CD8: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x80068CDC: ori         $t2, $t1, 0x1A
    ctx->r10 = ctx->r9 | 0X1A;
    // 0x80068CE0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80068CE4: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80068CE8: addiu       $s2, $s2, 0xCF0
    ctx->r18 = ADD32(ctx->r18, 0XCF0);
    // 0x80068CEC: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80068CF0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80068CF4: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80068CF8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80068CFC: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x80068D00: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80068D04: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80068D08: lh          $s3, 0x18($a3)
    ctx->r19 = MEM_H(ctx->r7, 0X18);
    // 0x80068D0C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80068D10: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x80068D14: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80068D18: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80068D1C: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x80068D20: sh          $t1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r9;
    // 0x80068D24: lh          $t2, 0x2($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X2);
    // 0x80068D28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80068D2C: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80068D30: sh          $t3, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r11;
    // 0x80068D34: lw          $t4, 0xCE4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XCE4);
    // 0x80068D38: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x80068D3C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80068D40: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80068D44: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80068D48: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80068D4C: lh          $t6, 0xAC4($t6)
    ctx->r14 = MEM_H(ctx->r14, 0XAC4);
    // 0x80068D50: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80068D54: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80068D58: sh          $t8, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r24;
    // 0x80068D5C: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
    // 0x80068D60: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x80068D64: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x80068D68: lb          $t9, 0xD15($t9)
    ctx->r25 = MEM_B(ctx->r25, 0XD15);
    // 0x80068D6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068D70: beq         $t9, $zero, L_80068DC8
    if (ctx->r25 == 0) {
        // 0x80068D74: nop
    
            goto L_80068DC8;
    }
    // 0x80068D74: nop

    // 0x80068D78: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80068D7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80068D80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80068D84: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80068D88: jal         0x80070638
    // 0x80068D8C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    mtxf_from_scale(rdram, ctx);
        goto after_0;
    // 0x80068D8C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x80068D90: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80068D94: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x80068D98: lw          $a3, 0x6174($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6174);
    // 0x80068D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068DA4: jal         0x80070130
    // 0x80068DA8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_billboard(rdram, ctx);
        goto after_1;
    // 0x80068DA8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80068DAC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80068DB0: addiu       $a2, $a2, 0x1060
    ctx->r6 = ADD32(ctx->r6, 0X1060);
    // 0x80068DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068DB8: jal         0x8006F768
    // 0x80068DBC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    mtxf_mul(rdram, ctx);
        goto after_2;
    // 0x80068DBC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x80068DC0: b           L_80068DE8
    // 0x80068DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80068DE8;
    // 0x80068DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80068DC8:
    // 0x80068DC8: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80068DCC: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    // 0x80068DD0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80068DD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80068DD8: jal         0x80070638
    // 0x80068DDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    mtxf_from_scale(rdram, ctx);
        goto after_3;
    // 0x80068DDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80068DE0: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x80068DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80068DE8:
    // 0x80068DE8: jal         0x8006FE74
    // 0x80068DEC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_4;
    // 0x80068DEC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80068DF0: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80068DF4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80068DF8: addiu       $s2, $s2, 0xD70
    ctx->r18 = ADD32(ctx->r18, 0XD70);
    // 0x80068DFC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80068E00: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x80068E04: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x80068E08: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068E0C: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    // 0x80068E10: jal         0x8006F768
    // 0x80068E14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mtxf_mul(rdram, ctx);
        goto after_5;
    // 0x80068E14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80068E18: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80068E1C: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80068E20: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80068E24: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x80068E28: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80068E2C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80068E30: jal         0x8006F870
    // 0x80068E34: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_6;
    // 0x80068E34: nop

    after_6:
    // 0x80068E38: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x80068E3C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80068E40: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80068E44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068E48: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80068E4C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80068E50: sw          $t8, 0xD88($at)
    MEM_W(0XD88, ctx->r1) = ctx->r24;
    // 0x80068E54: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80068E58: lui         $t3, 0x180
    ctx->r11 = S32(0X180 << 16);
    // 0x80068E5C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80068E60: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80068E64: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x80068E68: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80068E6C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80068E70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068E74: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80068E78: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80068E7C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80068E80: lui         $s0, 0xBC00
    ctx->r16 = S32(0XBC00 << 16);
    // 0x80068E84: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x80068E88: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80068E8C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80068E90: ori         $s0, $s0, 0x2
    ctx->r16 = ctx->r16 | 0X2;
    // 0x80068E94: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80068E98: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80068E9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80068EA0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80068EA4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80068EA8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80068EAC: lw          $t1, 0xD0C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD0C);
    // 0x80068EB0: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x80068EB4: bne         $t1, $zero, L_80068EDC
    if (ctx->r9 != 0) {
        // 0x80068EB8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80068EDC;
    }
    // 0x80068EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80068EBC: lw          $t3, 0xF0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF0);
    // 0x80068EC0: andi        $t2, $s3, 0xFF
    ctx->r10 = ctx->r19 & 0XFF;
    // 0x80068EC4: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80068EC8: nop

    // 0x80068ECC: multu       $t2, $t4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068ED0: mflo        $s3
    ctx->r19 = lo;
    // 0x80068ED4: sra         $t5, $s3, 8
    ctx->r13 = S32(SIGNED(ctx->r19) >> 8);
    // 0x80068ED8: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
L_80068EDC:
    // 0x80068EDC: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x80068EE0: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x80068EE4: jal         0x8007BF34
    // 0x80068EE8: or          $a1, $t7, $t9
    ctx->r5 = ctx->r15 | ctx->r25;
    material_load_simple(rdram, ctx);
        goto after_7;
    // 0x80068EE8: or          $a1, $t7, $t9
    ctx->r5 = ctx->r15 | ctx->r25;
    after_7:
    // 0x80068EEC: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x80068EF0: nop

    // 0x80068EF4: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
    // 0x80068EF8: nop

    // 0x80068EFC: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80068F00: bne         $at, $zero, L_80068F0C
    if (ctx->r1 != 0) {
        // 0x80068F04: nop
    
            goto L_80068F0C;
    }
    // 0x80068F04: nop

    // 0x80068F08: addiu       $s3, $v0, -0x1
    ctx->r19 = ADD32(ctx->r2, -0X1);
L_80068F0C:
    // 0x80068F0C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80068F10: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80068F14: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80068F18: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80068F1C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80068F20: lw          $t2, 0xF0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF0);
    // 0x80068F24: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x80068F28: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80068F2C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80068F30: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x80068F34: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80068F38: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80068F3C: ori         $t3, $t3, 0xA
    ctx->r11 = ctx->r11 | 0XA;
    // 0x80068F40: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80068F44: bne         $t9, $zero, L_80068F54
    if (ctx->r25 != 0) {
        // 0x80068F48: sw          $t9, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r25;
            goto L_80068F54;
    }
    // 0x80068F48: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x80068F4C: b           L_80068F58
    // 0x80068F50: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80068F58;
    // 0x80068F50: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80068F54:
    // 0x80068F54: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80068F58:
    // 0x80068F58: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80068F5C: sll         $t2, $s3, 6
    ctx->r10 = S32(ctx->r19 << 6);
    // 0x80068F60: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80068F64: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80068F68: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80068F6C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80068F70: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80068F74: nop

    // 0x80068F78: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80068F7C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068F80: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80068F84: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_80068F88:
    // 0x80068F88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80068F8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068F90: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80068F94: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80068F98: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80068F9C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80068FA0: jr          $ra
    // 0x80068FA4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80068FA4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void alSaveNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800650E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800650E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800650EC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800650F0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800650F4: addiu       $a2, $a2, -0x3B20
    ctx->r6 = ADD32(ctx->r6, -0X3B20);
    // 0x800650F8: addiu       $a1, $a1, -0x3AEC
    ctx->r5 = ADD32(ctx->r5, -0X3AEC);
    // 0x800650FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065100: jal         0x800CA0B0
    // 0x80065104: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80065104: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80065108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006510C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80065110: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80065114: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80065118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006511C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065120: jr          $ra
    // 0x80065124: nop

    return;
    // 0x80065124: nop

;}
RECOMP_FUNC void set_level_default_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DB18: jr          $ra
    // 0x8006DB1C: sw          $a0, 0x3518($at)
    MEM_W(0X3518, ctx->r1) = ctx->r4;
    return;
    // 0x8006DB1C: sw          $a0, 0x3518($at)
    MEM_W(0X3518, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void render_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3740: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B3744: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B3748: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B374C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B3750: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B3754: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B3758: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800B375C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800B3760: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B3764: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800B3768: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800B376C: beq         $t8, $zero, L_800B378C
    if (ctx->r24 == 0) {
        // 0x800B3770: addiu       $t3, $zero, 0xA
        ctx->r11 = ADD32(0, 0XA);
            goto L_800B378C;
    }
    // 0x800B3770: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800B3774: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B3778: lw          $t9, 0x2CDC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2CDC);
    // 0x800B377C: nop

    // 0x800B3780: slti        $at, $t9, 0x200
    ctx->r1 = SIGNED(ctx->r25) < 0X200 ? 1 : 0;
    // 0x800B3784: bne         $at, $zero, L_800B3E50
    if (ctx->r1 != 0) {
        // 0x800B3788: nop
    
            goto L_800B3E50;
    }
    // 0x800B3788: nop

L_800B378C:
    // 0x800B378C: lh          $t2, 0x5C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X5C);
    // 0x800B3790: nop

    // 0x800B3794: sra         $t4, $t2, 8
    ctx->r12 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800B3798: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x800B379C: blez        $t2, L_800B3E50
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B37A0: nop
    
            goto L_800B3E50;
    }
    // 0x800B37A0: nop

    // 0x800B37A4: lh          $v1, 0x2C($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2C);
    // 0x800B37A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800B37AC: beq         $a1, $v1, L_800B3A7C
    if (ctx->r5 == ctx->r3) {
        // 0x800B37B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B3A7C;
    }
    // 0x800B37B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B37B4: beq         $v1, $at, L_800B3A7C
    if (ctx->r3 == ctx->r1) {
        // 0x800B37B8: addiu       $t1, $zero, 0xFF
        ctx->r9 = ADD32(0, 0XFF);
            goto L_800B3A7C;
    }
    // 0x800B37B8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800B37BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B37C0: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800B37C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B37C8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B37CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B37D0: lbu         $t6, 0x6D($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X6D);
    // 0x800B37D4: lbu         $t9, 0x6C($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6C);
    // 0x800B37D8: lbu         $t5, 0x6E($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X6E);
    // 0x800B37DC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800B37E0: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x800B37E4: lbu         $t9, 0x6F($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6F);
    // 0x800B37E8: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800B37EC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B37F0: or          $t4, $t8, $t6
    ctx->r12 = ctx->r24 | ctx->r14;
    // 0x800B37F4: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800B37F8: beq         $t2, $t1, L_800B3844
    if (ctx->r10 == ctx->r9) {
        // 0x800B37FC: sw          $t5, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r13;
            goto L_800B3844;
    }
    // 0x800B37FC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B3800: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B3804: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800B3808: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x800B380C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B3810: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B3814: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x800B3818: addiu       $t3, $zero, 0x10E
    ctx->r11 = ADD32(0, 0X10E);
    // 0x800B381C: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x800B3820: sll         $t4, $t7, 24
    ctx->r12 = S32(ctx->r15 << 24);
    // 0x800B3824: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800B3828: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800B382C: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800B3830: or          $t6, $t5, $t8
    ctx->r14 = ctx->r13 | ctx->r24;
    // 0x800B3834: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x800B3838: or          $t4, $t6, $t7
    ctx->r12 = ctx->r14 | ctx->r15;
    // 0x800B383C: b           L_800B3860
    // 0x800B3840: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
        goto L_800B3860;
    // 0x800B3840: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
L_800B3844:
    // 0x800B3844: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3848: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800B384C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3850: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3854: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B3858: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B385C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800B3860:
    // 0x800B3860: lh          $t6, 0x2C($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2C);
    // 0x800B3864: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B3868: bne         $t6, $at, L_800B3904
    if (ctx->r14 != ctx->r1) {
        // 0x800B386C: nop
    
            goto L_800B3904;
    }
    // 0x800B386C: nop

    // 0x800B3870: lh          $v1, 0x18($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X18);
    // 0x800B3874: lw          $t0, 0x44($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X44);
    // 0x800B3878: sra         $t7, $v1, 8
    ctx->r15 = S32(SIGNED(ctx->r3) >> 8);
    // 0x800B387C: sh          $t7, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r15;
    // 0x800B3880: lh          $t4, 0x18($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X18);
    // 0x800B3884: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x800B3888: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B388C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B3890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3894: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800B3898: mflo        $t9
    ctx->r25 = lo;
    // 0x800B389C: nop

    // 0x800B38A0: nop

    // 0x800B38A4: div         $zero, $t9, $t5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r13)));
    // 0x800B38A8: bne         $t5, $zero, L_800B38B4
    if (ctx->r13 != 0) {
        // 0x800B38AC: nop
    
            goto L_800B38B4;
    }
    // 0x800B38AC: nop

    // 0x800B38B0: break       7
    do_break(2148219056);
L_800B38B4:
    // 0x800B38B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B38B8: bne         $t5, $at, L_800B38CC
    if (ctx->r13 != ctx->r1) {
        // 0x800B38BC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B38CC;
    }
    // 0x800B38BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B38C0: bne         $t9, $at, L_800B38CC
    if (ctx->r25 != ctx->r1) {
        // 0x800B38C4: nop
    
            goto L_800B38CC;
    }
    // 0x800B38C4: nop

    // 0x800B38C8: break       6
    do_break(2148219080);
L_800B38CC:
    // 0x800B38CC: mflo        $t8
    ctx->r24 = lo;
    // 0x800B38D0: sh          $t8, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r24;
    // 0x800B38D4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800B38D8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800B38DC: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B38E0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800B38E4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800B38E8: jal         0x80068514
    // 0x800B38EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    render_sprite_billboard(rdram, ctx);
        goto after_0;
    // 0x800B38EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x800B38F0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800B38F4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B38F8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800B38FC: b           L_800B3A20
    // 0x800B3900: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
        goto L_800B3A20;
    // 0x800B3900: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
L_800B3904:
    // 0x800B3904: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B3908: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800B390C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B3910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3914: beq         $t6, $zero, L_800B3A20
    if (ctx->r14 == 0) {
        // 0x800B3918: or          $a2, $s1, $zero
        ctx->r6 = ctx->r17 | 0;
            goto L_800B3A20;
    }
    // 0x800B3918: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800B391C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B3920: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B3924: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800B3928: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B392C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800B3930: jal         0x80069484
    // 0x800B3934: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_1;
    // 0x800B3934: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800B3938: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B393C: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B3940: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3944: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B3948: sll         $t7, $a3, 8
    ctx->r15 = S32(ctx->r7 << 8);
    // 0x800B394C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800B3950: jal         0x8007B4E8
    // 0x800B3954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    material_set(rdram, ctx);
        goto after_2;
    // 0x800B3954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800B3958: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B395C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B3960: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B3964: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800B3968: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B396C: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x800B3970: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B3974: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800B3978: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x800B397C: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x800B3980: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800B3984: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800B3988: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x800B398C: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x800B3990: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800B3994: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x800B3998: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x800B399C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B39A0: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800B39A4: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x800B39A8: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800B39AC: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x800B39B0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B39B4: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B39B8: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800B39BC: addu        $t4, $t7, $a3
    ctx->r12 = ADD32(ctx->r15, ctx->r7);
    // 0x800B39C0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B39C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B39C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B39CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B39D0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B39D4: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800B39D8: nop

    // 0x800B39DC: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x800B39E0: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800B39E4: ori         $t5, $t8, 0x1
    ctx->r13 = ctx->r24 | 0X1;
    // 0x800B39E8: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x800B39EC: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800B39F0: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x800B39F4: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800B39F8: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x800B39FC: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800B3A00: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B3A04: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800B3A08: nop

    // 0x800B3A0C: addu        $t4, $t7, $a3
    ctx->r12 = ADD32(ctx->r15, ctx->r7);
    // 0x800B3A10: jal         0x80069A40
    // 0x800B3A14: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    mtx_pop(rdram, ctx);
        goto after_3;
    // 0x800B3A14: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    after_3:
    // 0x800B3A18: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B3A1C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
L_800B3A20:
    // 0x800B3A20: bne         $t2, $t1, L_800B3A38
    if (ctx->r10 != ctx->r9) {
        // 0x800B3A24: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_800B3A38;
    }
    // 0x800B3A24: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800B3A28: lh          $t6, 0x4A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4A);
    // 0x800B3A2C: nop

    // 0x800B3A30: beq         $t1, $t6, L_800B3A50
    if (ctx->r9 == ctx->r14) {
        // 0x800B3A34: nop
    
            goto L_800B3A50;
    }
    // 0x800B3A34: nop

L_800B3A38:
    // 0x800B3A38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3A3C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B3A40: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3A44: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3A48: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B3A4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800B3A50:
    // 0x800B3A50: lbu         $t7, 0x6F($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X6F);
    // 0x800B3A54: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800B3A58: beq         $t7, $zero, L_800B3E54
    if (ctx->r15 == 0) {
        // 0x800B3A5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B3E54;
    }
    // 0x800B3A5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B3A60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3A64: addiu       $t9, $zero, -0x100
    ctx->r25 = ADD32(0, -0X100);
    // 0x800B3A68: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B3A6C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800B3A70: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B3A74: b           L_800B3E50
    // 0x800B3A78: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_800B3E50;
    // 0x800B3A78: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800B3A7C:
    // 0x800B3A7C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3A80: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x800B3A84: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B3A88: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B3A8C: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x800B3A90: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B3A94: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B3A98: lh          $v1, 0x2C($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2C);
    // 0x800B3A9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B3AA0: bne         $a1, $v1, L_800B3C30
    if (ctx->r5 != ctx->r3) {
        // 0x800B3AA4: nop
    
            goto L_800B3C30;
    }
    // 0x800B3AA4: nop

    // 0x800B3AA8: lh          $t4, 0x3A($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X3A);
    // 0x800B3AAC: nop

    // 0x800B3AB0: blez        $t4, L_800B3E54
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B3AB4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B3E54;
    }
    // 0x800B3AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B3AB8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3ABC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800B3AC0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B3AC4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B3AC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B3ACC: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x800B3AD0: nop

    // 0x800B3AD4: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800B3AD8: sll         $t5, $t8, 24
    ctx->r13 = S32(ctx->r24 << 24);
    // 0x800B3ADC: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800B3AE0: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800B3AE4: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x800B3AE8: or          $t9, $t4, $t6
    ctx->r25 = ctx->r12 | ctx->r14;
    // 0x800B3AEC: ori         $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 | 0XFF;
    // 0x800B3AF0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B3AF4: lb          $t5, 0x77($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X77);
    // 0x800B3AF8: nop

    // 0x800B3AFC: bne         $t5, $zero, L_800B3B0C
    if (ctx->r13 != 0) {
        // 0x800B3B00: nop
    
            goto L_800B3B0C;
    }
    // 0x800B3B00: nop

    // 0x800B3B04: jal         0x800B3E64
    // 0x800B3B08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    regenerate_point_particles_mesh(rdram, ctx);
        goto after_4;
    // 0x800B3B08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_800B3B0C:
    // 0x800B3B0C: lbu         $v0, 0x75($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X75);
    // 0x800B3B10: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B3B14: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B3B18: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800B3B1C: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B3B20: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x800B3B24: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800B3B28: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x800B3B2C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800B3B30: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B3B34: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x800B3B38: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B3B3C: sll         $t8, $a3, 8
    ctx->r24 = S32(ctx->r7 << 8);
    // 0x800B3B40: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800B3B44: ori         $a2, $a2, 0x10B
    ctx->r6 = ctx->r6 | 0X10B;
    // 0x800B3B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3B4C: jal         0x8007B4E8
    // 0x800B3B50: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    material_set(rdram, ctx);
        goto after_5;
    // 0x800B3B50: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_5:
    // 0x800B3B54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3B58: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B3B5C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B3B60: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800B3B64: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3B68: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x800B3B6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B3B70: addu        $t0, $t7, $a3
    ctx->r8 = ADD32(ctx->r15, ctx->r7);
    // 0x800B3B74: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x800B3B78: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x800B3B7C: andi        $t9, $t0, 0x6
    ctx->r25 = ctx->r8 & 0X6;
    // 0x800B3B80: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800B3B84: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x800B3B88: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800B3B8C: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800B3B90: addu        $t9, $t6, $a1
    ctx->r25 = ADD32(ctx->r14, ctx->r5);
    // 0x800B3B94: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800B3B98: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B3B9C: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x800B3BA0: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x800B3BA4: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x800B3BA8: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x800B3BAC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B3BB0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800B3BB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3BB8: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800B3BBC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3BC0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3BC4: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800B3BC8: nop

    // 0x800B3BCC: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x800B3BD0: sll         $t5, $t8, 4
    ctx->r13 = S32(ctx->r24 << 4);
    // 0x800B3BD4: ori         $t4, $t5, 0x1
    ctx->r12 = ctx->r13 | 0X1;
    // 0x800B3BD8: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800B3BDC: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800B3BE0: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x800B3BE4: andi        $t5, $t8, 0xFFFF
    ctx->r13 = ctx->r24 & 0XFFFF;
    // 0x800B3BE8: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800B3BEC: or          $t4, $t9, $t5
    ctx->r12 = ctx->r25 | ctx->r13;
    // 0x800B3BF0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B3BF4: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800B3BF8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B3BFC: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x800B3C00: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B3C04: lh          $t8, 0x4A($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4A);
    // 0x800B3C08: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800B3C0C: beq         $t8, $at, L_800B3E54
    if (ctx->r24 == ctx->r1) {
        // 0x800B3C10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B3E54;
    }
    // 0x800B3C10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B3C14: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3C18: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B3C1C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3C20: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3C24: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B3C28: b           L_800B3E50
    // 0x800B3C2C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_800B3E50;
    // 0x800B3C2C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800B3C30:
    // 0x800B3C30: bne         $v1, $at, L_800B3E54
    if (ctx->r3 != ctx->r1) {
        // 0x800B3C34: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B3E54;
    }
    // 0x800B3C34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B3C38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3C3C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800B3C40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B3C44: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B3C48: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B3C4C: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x800B3C50: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x800B3C54: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800B3C58: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800B3C5C: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x800B3C60: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x800B3C64: or          $t4, $t9, $t5
    ctx->r12 = ctx->r25 | ctx->r13;
    // 0x800B3C68: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x800B3C6C: andi        $t8, $t2, 0xFF
    ctx->r24 = ctx->r10 & 0XFF;
    // 0x800B3C70: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B3C74: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B3C78: lbu         $a1, 0x68($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X68);
    // 0x800B3C7C: ori         $a2, $a2, 0x10B
    ctx->r6 = ctx->r6 | 0X10B;
    // 0x800B3C80: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x800B3C84: bne         $at, $zero, L_800B3D70
    if (ctx->r1 != 0) {
        // 0x800B3C88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800B3D70;
    }
    // 0x800B3C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3C8C: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B3C90: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B3C94: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B3C98: sll         $t5, $a3, 8
    ctx->r13 = S32(ctx->r7 << 8);
    // 0x800B3C9C: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x800B3CA0: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B3CA4: jal         0x8007B4E8
    // 0x800B3CA8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    material_set(rdram, ctx);
        goto after_6;
    // 0x800B3CA8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_6:
    // 0x800B3CAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3CB0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B3CB4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B3CB8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B3CBC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800B3CC0: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B3CC4: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x800B3CC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B3CCC: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x800B3CD0: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x800B3CD4: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800B3CD8: andi        $t5, $t9, 0x6
    ctx->r13 = ctx->r25 & 0X6;
    // 0x800B3CDC: or          $t4, $t6, $t5
    ctx->r12 = ctx->r14 | ctx->r13;
    // 0x800B3CE0: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800B3CE4: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800B3CE8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B3CEC: addu        $t5, $t6, $a1
    ctx->r13 = ADD32(ctx->r14, ctx->r5);
    // 0x800B3CF0: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x800B3CF4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B3CF8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800B3CFC: addiu       $t7, $t4, 0x8
    ctx->r15 = ADD32(ctx->r12, 0X8);
    // 0x800B3D00: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800B3D04: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800B3D08: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B3D0C: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B3D10: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800B3D14: addu        $t4, $t5, $a3
    ctx->r12 = ADD32(ctx->r13, ctx->r7);
    // 0x800B3D18: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B3D1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3D20: nop

    // 0x800B3D24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B3D28: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B3D2C: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800B3D30: nop

    // 0x800B3D34: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x800B3D38: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x800B3D3C: ori         $t6, $t8, 0x1
    ctx->r14 = ctx->r24 | 0X1;
    // 0x800B3D40: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x800B3D44: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x800B3D48: sll         $t9, $a2, 4
    ctx->r25 = S32(ctx->r6 << 4);
    // 0x800B3D4C: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800B3D50: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x800B3D54: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800B3D58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B3D5C: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800B3D60: nop

    // 0x800B3D64: addu        $t4, $t5, $a3
    ctx->r12 = ADD32(ctx->r13, ctx->r7);
    // 0x800B3D68: b           L_800B3E1C
    // 0x800B3D6C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_800B3E1C;
    // 0x800B3D6C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_800B3D70:
    // 0x800B3D70: blez        $a1, L_800B3E1C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800B3D74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800B3E1C;
    }
    // 0x800B3D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3D78: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B3D7C: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B3D80: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B3D84: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x800B3D88: sll         $t9, $a3, 8
    ctx->r25 = S32(ctx->r7 << 8);
    // 0x800B3D8C: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800B3D90: ori         $a2, $a2, 0x10B
    ctx->r6 = ctx->r6 | 0X10B;
    // 0x800B3D94: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B3D98: jal         0x8007B4E8
    // 0x800B3D9C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    material_set(rdram, ctx);
        goto after_7;
    // 0x800B3D9C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_7:
    // 0x800B3DA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3DA4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B3DA8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B3DAC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B3DB0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B3DB4: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B3DB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B3DBC: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800B3DC0: andi        $t5, $t6, 0x6
    ctx->r13 = ctx->r14 & 0X6;
    // 0x800B3DC4: ori         $t4, $t5, 0x18
    ctx->r12 = ctx->r13 | 0X18;
    // 0x800B3DC8: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x800B3DCC: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800B3DD0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B3DD4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B3DD8: ori         $t6, $t8, 0x50
    ctx->r14 = ctx->r24 | 0X50;
    // 0x800B3DDC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B3DE0: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B3DE4: lui         $t7, 0x501
    ctx->r15 = S32(0X501 << 16);
    // 0x800B3DE8: addu        $t4, $t5, $a3
    ctx->r12 = ADD32(ctx->r13, ctx->r7);
    // 0x800B3DEC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B3DF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3DF4: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800B3DF8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3DFC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3E00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B3E04: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x800B3E08: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x800B3E0C: sll         $t5, $t6, 4
    ctx->r13 = S32(ctx->r14 << 4);
    // 0x800B3E10: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x800B3E14: addu        $t9, $t4, $a3
    ctx->r25 = ADD32(ctx->r12, ctx->r7);
    // 0x800B3E18: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800B3E1C:
    // 0x800B3E1C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B3E20: bne         $t2, $at, L_800B3E38
    if (ctx->r10 != ctx->r1) {
        // 0x800B3E24: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_800B3E38;
    }
    // 0x800B3E24: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800B3E28: lh          $t7, 0x4A($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4A);
    // 0x800B3E2C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B3E30: beq         $t7, $at, L_800B3E54
    if (ctx->r15 == ctx->r1) {
        // 0x800B3E34: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B3E54;
    }
    // 0x800B3E34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B3E38:
    // 0x800B3E38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3E3C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B3E40: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B3E44: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B3E48: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B3E4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800B3E50:
    // 0x800B3E50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B3E54:
    // 0x800B3E54: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3E58: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B3E5C: jr          $ra
    // 0x800B3E60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B3E60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void music_jingle_current(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001980: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001984: lbu         $v0, 0x5D05($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5D05);
    // 0x80001988: jr          $ra
    // 0x8000198C: nop

    return;
    // 0x8000198C: nop

;}
RECOMP_FUNC void initialise_player_viewport_vars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028CD0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80028CD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028CD8: jal         0x80069D20
    // 0x80028CDC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80028CDC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80028CE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028CE4: jal         0x80066220
    // 0x80028CE8: sw          $v0, -0x4F50($at)
    MEM_W(-0X4F50, ctx->r1) = ctx->r2;
    get_current_viewport(rdram, ctx);
        goto after_1;
    // 0x80028CE8: sw          $v0, -0x4F50($at)
    MEM_W(-0X4F50, ctx->r1) = ctx->r2;
    after_1:
    // 0x80028CEC: jal         0x80031018
    // 0x80028CF0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    compute_scene_camera_transform_matrix(rdram, ctx);
        goto after_2;
    // 0x80028CF0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80028CF4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80028CF8: addiu       $v0, $v0, -0x2B98
    ctx->r2 = ADD32(ctx->r2, -0X2B98);
    // 0x80028CFC: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80028D00: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80028D04: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80028D08: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80028D0C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80028D10: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80028D14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80028D18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80028D1C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80028D20: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80028D24: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80028D28: nop

    // 0x80028D2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80028D30: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80028D34: div.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80028D38: jal         0x8001D5E0
    // 0x80028D3C: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    update_envmap_position(rdram, ctx);
        goto after_3;
    // 0x80028D3C: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    after_3:
    // 0x80028D40: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028D44: lw          $v1, -0x4F50($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4F50);
    // 0x80028D48: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80028D4C: lh          $v0, 0x34($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X34);
    // 0x80028D50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80028D54: bltz        $v0, L_80028D90
    if (SIGNED(ctx->r2) < 0) {
        // 0x80028D58: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80028D90;
    }
    // 0x80028D58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80028D5C: lw          $a0, -0x36E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X36E8);
    // 0x80028D60: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x80028D64: lh          $t9, 0x1A($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X1A);
    // 0x80028D68: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80028D6C: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80028D70: beq         $at, $zero, L_80028D90
    if (ctx->r1 == 0) {
        // 0x80028D74: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80028D90;
    }
    // 0x80028D74: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80028D78: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x80028D7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028D80: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80028D84: lh          $t4, 0x28($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X28);
    // 0x80028D88: b           L_80028D9C
    // 0x80028D8C: sw          $t4, -0x4F2C($at)
    MEM_W(-0X4F2C, ctx->r1) = ctx->r12;
        goto L_80028D9C;
    // 0x80028D8C: sw          $t4, -0x4F2C($at)
    MEM_W(-0X4F2C, ctx->r1) = ctx->r12;
L_80028D90:
    // 0x80028D90: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80028D94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028D98: sw          $t5, -0x4F2C($at)
    MEM_W(-0X4F2C, ctx->r1) = ctx->r13;
L_80028D9C:
    // 0x80028D9C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80028DA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DA4: swc1        $f6, -0x2CEC($at)
    MEM_W(-0X2CEC, ctx->r1) = ctx->f6.u32l;
    // 0x80028DA8: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80028DAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DB0: swc1        $f8, -0x2CE8($at)
    MEM_W(-0X2CE8, ctx->r1) = ctx->f8.u32l;
    // 0x80028DB4: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80028DB8: lw          $t6, -0x2C7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2C7C);
    // 0x80028DBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DC0: beq         $t6, $zero, L_80028F7C
    if (ctx->r14 == 0) {
        // 0x80028DC4: swc1        $f10, -0x2CE4($at)
        MEM_W(-0X2CE4, ctx->r1) = ctx->f10.u32l;
            goto L_80028F7C;
    }
    // 0x80028DC4: swc1        $f10, -0x2CE4($at)
    MEM_W(-0X2CE4, ctx->r1) = ctx->f10.u32l;
    // 0x80028DC8: jal         0x800B8B8C
    // 0x80028DCC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    waves_visibility_reset(rdram, ctx);
        goto after_4;
    // 0x80028DCC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80028DD0: jal         0x8001BA74
    // 0x80028DD4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    get_racer_objects(rdram, ctx);
        goto after_5;
    // 0x80028DD4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x80028DD8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80028DDC: lw          $t7, -0x4F50($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F50);
    // 0x80028DE0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80028DE4: lh          $t8, 0x36($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X36);
    // 0x80028DE8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80028DEC: beq         $t8, $at, L_80028EEC
    if (ctx->r24 == ctx->r1) {
        // 0x80028DF0: nop
    
            goto L_80028EEC;
    }
    // 0x80028DF0: nop

    // 0x80028DF4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80028DF8: nop

    // 0x80028DFC: blez        $t9, L_80028EEC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80028E00: nop
    
            goto L_80028EEC;
    }
    // 0x80028E00: nop

    // 0x80028E04: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80028E08: jal         0x80066510
    // 0x80028E0C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_6;
    // 0x80028E0C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80028E10: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80028E14: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80028E18: bne         $v0, $zero, L_80028EEC
    if (ctx->r2 != 0) {
        // 0x80028E1C: addiu       $v1, $a0, -0x4
        ctx->r3 = ADD32(ctx->r4, -0X4);
            goto L_80028EEC;
    }
    // 0x80028E1C: addiu       $v1, $a0, -0x4
    ctx->r3 = ADD32(ctx->r4, -0X4);
    // 0x80028E20: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80028E24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80028E28: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_80028E2C:
    // 0x80028E2C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80028E30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028E34: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80028E38: lw          $a0, 0x64($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X64);
    // 0x80028E3C: beq         $at, $zero, L_80028E54
    if (ctx->r1 == 0) {
        // 0x80028E40: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80028E54;
    }
    // 0x80028E40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80028E44: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x80028E48: nop

    // 0x80028E4C: bne         $a3, $t2, L_80028E2C
    if (ctx->r7 != ctx->r10) {
        // 0x80028E50: nop
    
            goto L_80028E2C;
    }
    // 0x80028E50: nop

L_80028E54:
    // 0x80028E54: jal         0x80066220
    // 0x80028E58: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    get_current_viewport(rdram, ctx);
        goto after_7;
    // 0x80028E58: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x80028E5C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80028E60: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80028E64: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80028E68: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80028E6C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028E70: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028E74: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80028E78: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80028E7C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80028E80: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80028E84: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80028E88: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80028E8C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80028E90: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80028E94: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80028E98: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80028E9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028EA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028EA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80028EA8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028EAC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80028EB0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80028EB4: nop

    // 0x80028EB8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80028EBC: nop

    // 0x80028EC0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80028EC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028EC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028ECC: nop

    // 0x80028ED0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028ED4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80028ED8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    extern void dkr_anchor_persistent_water_to_camera(uint8_t*, recomp_context*); dkr_anchor_persistent_water_to_camera(rdram, ctx);
    // 0x80028EDC: jal         0x800B8C04
    // 0x80028EE0: nop

    waves_visibility(rdram, ctx);
        goto after_8;
    // 0x80028EE0: nop

    after_8:
    // 0x80028EE4: b           L_80028F7C
    // 0x80028EE8: nop

        goto L_80028F7C;
    // 0x80028EE8: nop

L_80028EEC:
    // 0x80028EEC: jal         0x80066220
    // 0x80028EF0: nop

    get_current_viewport(rdram, ctx);
        goto after_9;
    // 0x80028EF0: nop

    after_9:
    // 0x80028EF4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028EF8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028EFC: lw          $v1, -0x4F50($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4F50);
    // 0x80028F00: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80028F04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028F08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028F0C: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80028F10: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80028F14: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80028F18: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80028F1C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028F20: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80028F24: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80028F28: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80028F2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80028F30: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80028F34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028F38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028F3C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80028F40: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028F44: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80028F48: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80028F4C: nop

    // 0x80028F50: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028F54: nop

    // 0x80028F58: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028F5C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028F60: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028F64: nop

    // 0x80028F68: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028F6C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80028F70: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028F74: jal         0x800B8C04
    // 0x80028F78: nop

    waves_visibility(rdram, ctx);
        goto after_10;
    // 0x80028F78: nop

    after_10:
L_80028F7C:
    // 0x80028F7C: jal         0x8006BDB0
    // 0x80028F80: nop

    level_header(rdram, ctx);
        goto after_11;
    // 0x80028F80: nop

    after_11:
    // 0x80028F84: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80028F88: jal         0x80028FAC
    // 0x80028F8C: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
    render_level_geometry_and_objects(rdram, ctx);
        goto after_12;
    // 0x80028F8C: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
    after_12:
    // 0x80028F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028F94: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80028F98: jr          $ra
    // 0x80028F9C: nop

    return;
    // 0x80028F9C: nop

;}
RECOMP_FUNC void gzip_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6178: addiu       $a0, $zero, 0x2800
    ctx->r4 = ADD32(0, 0X2800);
    // 0x800C617C: jal         0x80070C9C
    // 0x800C6180: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C6180: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
    // 0x800C6184: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6188: sw          $v0, 0x3760($at)
    MEM_W(0X3760, ctx->r1) = ctx->r2;
    // 0x800C618C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800C6190: jal         0x80070C9C
    // 0x800C6194: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800C6194: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_1:
    // 0x800C6198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C619C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C61A0: sw          $v0, 0x3764($at)
    MEM_W(0X3764, ctx->r1) = ctx->r2;
    // 0x800C61A4: jr          $ra
    // 0x800C61A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C61A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mempool_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070BE4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80070BE8: addiu       $t1, $t1, 0x35C0
    ctx->r9 = ADD32(ctx->r9, 0X35C0);
    // 0x80070BEC: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80070BF0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80070BF4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80070BF8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80070BFC: addiu       $t9, $t9, 0x3580
    ctx->r25 = ADD32(ctx->r25, 0X3580);
    // 0x80070C00: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x80070C04: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80070C08: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x80070C0C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80070C10: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x80070C14: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x80070C18: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80070C1C: blez        $a2, L_80070C3C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80070C20: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80070C3C;
    }
    // 0x80070C20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80070C24:
    // 0x80070C24: sh          $v1, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r3;
    // 0x80070C28: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80070C2C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80070C30: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80070C34: bne         $at, $zero, L_80070C24
    if (ctx->r1 != 0) {
        // 0x80070C38: addiu       $t0, $t0, 0x14
        ctx->r8 = ADD32(ctx->r8, 0X14);
            goto L_80070C24;
    }
    // 0x80070C38: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
L_80070C3C:
    // 0x80070C3C: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80070C40: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80070C44: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80070C48: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80070C4C: lw          $t0, 0x8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X8);
    // 0x80070C50: andi        $t3, $a0, 0xF
    ctx->r11 = ctx->r4 & 0XF;
    // 0x80070C54: beq         $t3, $zero, L_80070C70
    if (ctx->r11 == 0) {
        // 0x80070C58: subu        $t6, $a1, $v1
        ctx->r14 = SUB32(ctx->r5, ctx->r3);
            goto L_80070C70;
    }
    // 0x80070C58: subu        $t6, $a1, $v1
    ctx->r14 = SUB32(ctx->r5, ctx->r3);
    // 0x80070C5C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80070C60: and         $t4, $a0, $at
    ctx->r12 = ctx->r4 & ctx->r1;
    // 0x80070C64: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x80070C68: b           L_80070C74
    // 0x80070C6C: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
        goto L_80070C74;
    // 0x80070C6C: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_80070C70:
    // 0x80070C70: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
L_80070C74:
    // 0x80070C74: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80070C78: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80070C7C: sh          $zero, 0x8($t0)
    MEM_H(0X8, ctx->r8) = 0;
    // 0x80070C80: sh          $a0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r4;
    // 0x80070C84: sh          $a0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r4;
    // 0x80070C88: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80070C8C: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x80070C90: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80070C94: jr          $ra
    // 0x80070C98: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    return;
    // 0x80070C98: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
;}
RECOMP_FUNC void audspat_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008048: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000804C: addiu       $a0, $a0, -0x63C0
    ctx->r4 = ADD32(ctx->r4, -0X63C0);
    // 0x80008050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008054: jal         0x80002128
    // 0x80008058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sound_table_properties(rdram, ctx);
        goto after_0;
    // 0x80008058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000805C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80008060: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80008064: jal         0x80070C9C
    // 0x80008068: addiu       $a0, $zero, 0x5A0
    ctx->r4 = ADD32(0, 0X5A0);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80008068: addiu       $a0, $zero, 0x5A0
    ctx->r4 = ADD32(0, 0X5A0);
    after_1:
    // 0x8000806C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80008070: addiu       $a2, $a2, -0x63B8
    ctx->r6 = ADD32(ctx->r6, -0X63B8);
    // 0x80008074: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80008078: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8000807C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80008080: jal         0x80070C9C
    // 0x80008084: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80008084: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_2:
    // 0x80008088: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000808C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80008090: sw          $v0, -0x63B0($at)
    MEM_W(-0X63B0, ctx->r1) = ctx->r2;
    // 0x80008094: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80008098: jal         0x80070C9C
    // 0x8000809C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8000809C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_3:
    // 0x800080A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800080A4: sw          $v0, -0x63BC($at)
    MEM_W(-0X63BC, ctx->r1) = ctx->r2;
    // 0x800080A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800080AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800080B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800080B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800080B8: addiu       $a2, $a2, -0x63B8
    ctx->r6 = ADD32(ctx->r6, -0X63B8);
    // 0x800080BC: sh          $zero, -0x3920($at)
    MEM_H(-0X3920, ctx->r1) = 0;
    // 0x800080C0: addiu       $v1, $v1, -0x63A8
    ctx->r3 = ADD32(ctx->r3, -0X63A8);
    // 0x800080C4: addiu       $v0, $v0, -0x5928
    ctx->r2 = ADD32(ctx->r2, -0X5928);
L_800080C8:
    // 0x800080C8: addiu       $v1, $v1, 0x180
    ctx->r3 = ADD32(ctx->r3, 0X180);
    // 0x800080CC: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800080D0: bne         $at, $zero, L_800080C8
    if (ctx->r1 != 0) {
        // 0x800080D4: sw          $zero, -0x8($v1)
        MEM_W(-0X8, ctx->r3) = 0;
            goto L_800080C8;
    }
    // 0x800080D4: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800080D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800080DC: addiu       $v1, $zero, 0x5A0
    ctx->r3 = ADD32(0, 0X5A0);
L_800080E0:
    // 0x800080E0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800080E4: nop

    // 0x800080E8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800080EC: sw          $zero, 0x18($t7)
    MEM_W(0X18, ctx->r15) = 0;
    // 0x800080F0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800080F4: nop

    // 0x800080F8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800080FC: sw          $zero, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = 0;
    // 0x80008100: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80008104: nop

    // 0x80008108: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8000810C: sw          $zero, 0x60($t1)
    MEM_W(0X60, ctx->r9) = 0;
    // 0x80008110: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80008114: nop

    // 0x80008118: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8000811C: addiu       $v0, $v0, 0x90
    ctx->r2 = ADD32(ctx->r2, 0X90);
    // 0x80008120: bne         $v0, $v1, L_800080E0
    if (ctx->r2 != ctx->r3) {
        // 0x80008124: sw          $zero, 0x84($t3)
        MEM_W(0X84, ctx->r11) = 0;
            goto L_800080E0;
    }
    // 0x80008124: sw          $zero, 0x84($t3)
    MEM_W(0X84, ctx->r11) = 0;
    // 0x80008128: jal         0x80008174
    // 0x8000812C: nop

    audspat_reset(rdram, ctx);
        goto after_4;
    // 0x8000812C: nop

    after_4:
    // 0x80008130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008138: jr          $ra
    // 0x8000813C: nop

    return;
    // 0x8000813C: nop

;}
RECOMP_FUNC void obj_loop_banana(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D5A0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003D5A4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003D5A8: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003D5AC: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003D5B0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003D5B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003D5B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D5BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003D5C0: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8003D5C4: bne         $t7, $zero, L_8003D5E4
    if (ctx->r15 != 0) {
        // 0x8003D5C8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8003D5E4;
    }
    // 0x8003D5C8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003D5CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D5D0: lwc1        $f9, 0x6190($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6190);
    // 0x8003D5D4: lwc1        $f8, 0x6194($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x8003D5D8: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D5DC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003D5E0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8003D5E4:
    // 0x8003D5E4: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x8003D5E8: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003D5EC: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8003D5F0: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x8003D5F4: lw          $t5, 0x78($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X78);
    // 0x8003D5F8: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8003D5FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003D600: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8003D604: bne         $t5, $at, L_8003D66C
    if (ctx->r13 != ctx->r1) {
        // 0x8003D608: sh          $t4, 0x18($s0)
        MEM_H(0X18, ctx->r16) = ctx->r12;
            goto L_8003D66C;
    }
    // 0x8003D608: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
    // 0x8003D60C: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x8003D610: addiu       $t1, $s0, 0x78
    ctx->r9 = ADD32(ctx->r16, 0X78);
    // 0x8003D614: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x8003D618: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x8003D61C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003D620: lh          $t8, 0x6($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X6);
    // 0x8003D624: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003D628: subu        $t9, $t8, $t2
    ctx->r25 = SUB32(ctx->r24, ctx->r10);
    // 0x8003D62C: sh          $t9, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r25;
    // 0x8003D630: sw          $t3, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r11;
    // 0x8003D634: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8003D638: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003D63C: jal         0x800AFC3C
    // 0x8003D640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_0;
    // 0x8003D640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8003D644: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D648: nop

    // 0x8003D64C: lh          $t4, 0x6($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X6);
    // 0x8003D650: nop

    // 0x8003D654: bgtz        $t4, L_8003DB94
    if (SIGNED(ctx->r12) > 0) {
        // 0x8003D658: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DB94;
    }
    // 0x8003D658: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003D65C: jal         0x8000FFB8
    // 0x8003D660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8003D660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003D664: b           L_8003DB94
    // 0x8003D668: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003DB94;
    // 0x8003D668: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003D66C:
    // 0x8003D66C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D670: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8003D674: lb          $v0, 0x8($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X8);
    // 0x8003D678: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D67C: blez        $v0, L_8003D690
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D680: addiu       $t1, $s0, 0x78
        ctx->r9 = ADD32(ctx->r16, 0X78);
            goto L_8003D690;
    }
    // 0x8003D680: addiu       $t1, $s0, 0x78
    ctx->r9 = ADD32(ctx->r16, 0X78);
    // 0x8003D684: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8003D688: b           L_8003D698
    // 0x8003D68C: sb          $t7, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r15;
        goto L_8003D698;
    // 0x8003D68C: sb          $t7, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r15;
L_8003D690:
    // 0x8003D690: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x8003D694: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_8003D698:
    // 0x8003D698: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8003D69C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D6A0: bne         $t2, $at, L_8003D910
    if (ctx->r10 != ctx->r1) {
        // 0x8003D6A4: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_8003D910;
    }
    // 0x8003D6A4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D6A8: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D6AC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D6B0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003D6B4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003D6B8: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8003D6BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003D6C0: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8003D6C4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x8003D6C8: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8003D6CC: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D6D0: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D6D4: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003D6D8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003D6DC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8003D6E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003D6E4: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8003D6E8: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D6EC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D6F0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003D6F4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8003D6F8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003D6FC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003D700: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8003D704: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x8003D708: jal         0x80031130
    // 0x8003D70C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_2;
    // 0x8003D70C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8003D710: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D714: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003D718: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x8003D71C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8003D720: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8003D724: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003D728: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8003D72C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8003D730: jal         0x80031600
    // 0x8003D734: addiu       $a3, $sp, 0x43
    ctx->r7 = ADD32(ctx->r29, 0X43);
    resolve_collisions(rdram, ctx);
        goto after_3;
    // 0x8003D734: addiu       $a3, $sp, 0x43
    ctx->r7 = ADD32(ctx->r29, 0X43);
    after_3:
    // 0x8003D738: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003D73C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D740: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8003D744: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003D748: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D74C: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003D750: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D754: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003D758: mtc1        $zero, $f13
    ctx->f_odd[(13 - 1) * 2] = 0;
    // 0x8003D75C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D760: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8003D764: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003D768: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003D76C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8003D770: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003D774: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D778: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8003D77C: nop

    // 0x8003D780: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003D784: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8003D788: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003D78C: nop

    // 0x8003D790: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8003D794: nop

    // 0x8003D798: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003D79C: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8003D7A0: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003D7A4: nop

    // 0x8003D7A8: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003D7AC: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003D7B0: nop

    // 0x8003D7B4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8003D7B8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003D7BC: nop

    // 0x8003D7C0: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8003D7C4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D7C8: nop

    // 0x8003D7CC: lb          $t6, 0x9($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X9);
    // 0x8003D7D0: nop

    // 0x8003D7D4: beq         $t6, $at, L_8003D830
    if (ctx->r14 == ctx->r1) {
        // 0x8003D7D8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8003D830;
    }
    // 0x8003D7D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D7DC: lwc1        $f1, 0x6198($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6198);
    // 0x8003D7E0: lwc1        $f0, 0x619C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x8003D7E4: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D7E8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003D7EC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003D7F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003D7F4: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8003D7F8: sub.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d - ctx->f18.d;
    // 0x8003D7FC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D800: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8003D804: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D808: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003D80C: mul.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8003D810: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8003D814: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8003D818: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8003D81C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8003D820: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x8003D824: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8003D828: b           L_8003D844
    // 0x8003D82C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
        goto L_8003D844;
    // 0x8003D82C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_8003D830:
    // 0x8003D830: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D834: nop

    // 0x8003D838: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8003D83C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8003D840: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8003D844:
    // 0x8003D844: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D848: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003D84C: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D850: c.lt.d      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.d < ctx->f12.d;
    // 0x8003D854: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8003D858: bc1f        L_8003D864
    if (!c1cs) {
        // 0x8003D85C: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8003D864;
    }
    // 0x8003D85C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003D860: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8003D864:
    // 0x8003D864: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D868: nop

    // 0x8003D86C: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8003D870: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x8003D874: nop

    // 0x8003D878: bc1f        L_8003D884
    if (!c1cs) {
        // 0x8003D87C: nop
    
            goto L_8003D884;
    }
    // 0x8003D87C: nop

    // 0x8003D880: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8003D884:
    // 0x8003D884: blez        $t7, L_8003D8C0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8003D888: nop
    
            goto L_8003D8C0;
    }
    // 0x8003D888: nop

    // 0x8003D88C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8003D890: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003D894: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D898: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x8003D89C: nop

    // 0x8003D8A0: bc1f        L_8003D8C0
    if (!c1cs) {
        // 0x8003D8A4: nop
    
            goto L_8003D8C0;
    }
    // 0x8003D8A4: nop

    // 0x8003D8A8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003D8AC: c.lt.d      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.d < ctx->f12.d;
    // 0x8003D8B0: nop

    // 0x8003D8B4: bc1f        L_8003D8C0
    if (!c1cs) {
        // 0x8003D8B8: nop
    
            goto L_8003D8C0;
    }
    // 0x8003D8B8: nop

    // 0x8003D8BC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_8003D8C0:
    // 0x8003D8C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D8C4: lwc1        $f4, 0x61A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61A0);
    // 0x8003D8C8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003D8CC: jal         0x8002B9BC
    // 0x8003D8D0: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    func_8002B9BC(rdram, ctx);
        goto after_4;
    // 0x8003D8D0: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8003D8D4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D8D8: beq         $v0, $zero, L_8003D910
    if (ctx->r2 == 0) {
        // 0x8003D8DC: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_8003D910;
    }
    // 0x8003D8DC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D8E0: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D8E4: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003D8E8: nop

    // 0x8003D8EC: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8003D8F0: nop

    // 0x8003D8F4: bc1f        L_8003D910
    if (!c1cs) {
        // 0x8003D8F8: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_8003D910;
    }
    // 0x8003D8F8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D8FC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8003D900: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003D904: nop

    // 0x8003D908: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8003D90C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
L_8003D910:
    // 0x8003D910: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003D914: lb          $t8, 0x9($t5)
    ctx->r24 = MEM_B(ctx->r13, 0X9);
    // 0x8003D918: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003D91C: beq         $t8, $at, L_8003D928
    if (ctx->r24 == ctx->r1) {
        // 0x8003D920: addiu       $a0, $zero, 0x46
        ctx->r4 = ADD32(0, 0X46);
            goto L_8003D928;
    }
    // 0x8003D920: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x8003D924: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
L_8003D928:
    // 0x8003D928: lh          $v0, 0x4($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X4);
    // 0x8003D92C: nop

    // 0x8003D930: blez        $v0, L_8003D940
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D934: subu        $t9, $v0, $t2
        ctx->r25 = SUB32(ctx->r2, ctx->r10);
            goto L_8003D940;
    }
    // 0x8003D934: subu        $t9, $v0, $t2
    ctx->r25 = SUB32(ctx->r2, ctx->r10);
    // 0x8003D938: b           L_8003D944
    // 0x8003D93C: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
        goto L_8003D944;
    // 0x8003D93C: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
L_8003D940:
    // 0x8003D940: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
L_8003D944:
    // 0x8003D944: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x8003D948: nop

    // 0x8003D94C: lbu         $t4, 0x13($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X13);
    // 0x8003D950: nop

    // 0x8003D954: slti        $at, $t4, 0x78
    ctx->r1 = SIGNED(ctx->r12) < 0X78 ? 1 : 0;
    // 0x8003D958: beq         $at, $zero, L_8003D9CC
    if (ctx->r1 == 0) {
        // 0x8003D95C: nop
    
            goto L_8003D9CC;
    }
    // 0x8003D95C: nop

    // 0x8003D960: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    // 0x8003D964: jal         0x8006BD98
    // 0x8003D968: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    level_type(rdram, ctx);
        goto after_5;
    // 0x8003D968: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_5:
    // 0x8003D96C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8003D970: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D974: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8003D978: bne         $v0, $at, L_8003D9CC
    if (ctx->r2 != ctx->r1) {
        // 0x8003D97C: nop
    
            goto L_8003D9CC;
    }
    // 0x8003D97C: nop

    // 0x8003D980: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003D984: nop

    // 0x8003D988: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8003D98C: nop

    // 0x8003D990: beq         $v1, $zero, L_8003D9CC
    if (ctx->r3 == 0) {
        // 0x8003D994: nop
    
            goto L_8003D9CC;
    }
    // 0x8003D994: nop

    // 0x8003D998: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8003D99C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D9A0: lb          $t5, 0x54($t7)
    ctx->r13 = MEM_B(ctx->r15, 0X54);
    // 0x8003D9A4: nop

    // 0x8003D9A8: bne         $t5, $at, L_8003D9CC
    if (ctx->r13 != ctx->r1) {
        // 0x8003D9AC: nop
    
            goto L_8003D9CC;
    }
    // 0x8003D9AC: nop

    // 0x8003D9B0: lw          $t0, 0x64($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X64);
    // 0x8003D9B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003D9B8: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8003D9BC: nop

    // 0x8003D9C0: bne         $t8, $at, L_8003D9CC
    if (ctx->r24 != ctx->r1) {
        // 0x8003D9C4: nop
    
            goto L_8003D9CC;
    }
    // 0x8003D9C4: nop

    // 0x8003D9C8: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
L_8003D9CC:
    // 0x8003D9CC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003D9D0: nop

    // 0x8003D9D4: lbu         $t2, 0x13($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X13);
    // 0x8003D9D8: nop

    // 0x8003D9DC: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003D9E0: beq         $at, $zero, L_8003DB94
    if (ctx->r1 == 0) {
        // 0x8003D9E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DB94;
    }
    // 0x8003D9E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003D9E8: lh          $t9, 0x4($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X4);
    // 0x8003D9EC: nop

    // 0x8003D9F0: bne         $t9, $zero, L_8003DB94
    if (ctx->r25 != 0) {
        // 0x8003D9F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DB94;
    }
    // 0x8003D9F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003D9F8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003D9FC: nop

    // 0x8003DA00: beq         $v1, $zero, L_8003DB94
    if (ctx->r3 == 0) {
        // 0x8003DA04: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DB94;
    }
    // 0x8003DA04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DA08: lw          $t3, 0x40($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X40);
    // 0x8003DA0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DA10: lb          $t4, 0x54($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X54);
    // 0x8003DA14: nop

    // 0x8003DA18: bne         $t4, $at, L_8003DB94
    if (ctx->r12 != ctx->r1) {
        // 0x8003DA1C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DB94;
    }
    // 0x8003DA1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DA20: lw          $t0, 0x64($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X64);
    // 0x8003DA24: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003DA28: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x8003DA2C: jal         0x8006BD98
    // 0x8003DA30: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    level_type(rdram, ctx);
        goto after_6;
    // 0x8003DA30: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    after_6:
    // 0x8003DA34: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8003DA38: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DA3C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DA40: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8003DA44: bne         $v0, $at, L_8003DA60
    if (ctx->r2 != ctx->r1) {
        // 0x8003DA48: addiu       $a0, $zero, 0x22
        ctx->r4 = ADD32(0, 0X22);
            goto L_8003DA60;
    }
    // 0x8003DA48: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8003DA4C: lb          $t6, 0x185($t0)
    ctx->r14 = MEM_B(ctx->r8, 0X185);
    // 0x8003DA50: nop

    // 0x8003DA54: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8003DA58: beq         $at, $zero, L_8003DB94
    if (ctx->r1 == 0) {
        // 0x8003DA5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DB94;
    }
    // 0x8003DA5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003DA60:
    // 0x8003DA60: lw          $t7, 0x180($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X180);
    // 0x8003DA64: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8003DA68: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8003DA6C: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x8003DA70: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x8003DA74: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8003DA78: addiu       $t8, $t0, 0x180
    ctx->r24 = ADD32(ctx->r8, 0X180);
    // 0x8003DA7C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003DA80: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003DA84: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8003DA88: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x8003DA8C: jal         0x80009558
    // 0x8003DA90: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_7;
    // 0x8003DA90: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x8003DA94: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003DA98: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8003DA9C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DAA0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DAA4: beq         $a0, $zero, L_8003DACC
    if (ctx->r4 == 0) {
        // 0x8003DAA8: nop
    
            goto L_8003DACC;
    }
    // 0x8003DAA8: nop

    // 0x8003DAAC: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x8003DAB0: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8003DAB4: jal         0x800096F8
    // 0x8003DAB8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    audspat_point_stop(rdram, ctx);
        goto after_8;
    // 0x8003DAB8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_8:
    // 0x8003DABC: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8003DAC0: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DAC4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DAC8: nop

L_8003DACC:
    // 0x8003DACC: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x8003DAD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003DAD4: beq         $t2, $at, L_8003DB24
    if (ctx->r10 == ctx->r1) {
        // 0x8003DAD8: nop
    
            goto L_8003DB24;
    }
    // 0x8003DAD8: nop

    // 0x8003DADC: lb          $t9, 0x185($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X185);
    // 0x8003DAE0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8003DAE4: bne         $t9, $at, L_8003DB24
    if (ctx->r25 != ctx->r1) {
        // 0x8003DAE8: nop
    
            goto L_8003DB24;
    }
    // 0x8003DAE8: nop

    // 0x8003DAEC: lb          $a0, 0x3($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X3);
    // 0x8003DAF0: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8003DAF4: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x8003DAF8: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x8003DAFC: addiu       $a0, $a0, 0x7B
    ctx->r4 = ADD32(ctx->r4, 0X7B);
    // 0x8003DB00: andi        $t3, $a0, 0xFFFF
    ctx->r11 = ctx->r4 & 0XFFFF;
    // 0x8003DB04: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8003DB08: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003DB0C: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    { extern unsigned dkr_legacy_character_race_sound(uint8_t*, recomp_context*, uint32_t, unsigned); ctx->r4 = dkr_legacy_character_race_sound(rdram, ctx, (uint32_t)ctx->r8, (unsigned)ctx->r4); }
    // 0x8003DB10: jal         0x80001EA8
    // 0x8003DB14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_9;
    // 0x8003DB14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x8003DB18: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DB1C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DB20: nop

L_8003DB24:
    // 0x8003DB24: lb          $t4, 0x185($t0)
    ctx->r12 = MEM_B(ctx->r8, 0X185);
    // 0x8003DB28: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003DB2C: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8003DB30: sb          $t6, 0x185($t0)
    MEM_B(0X185, ctx->r8) = ctx->r14;
    // 0x8003DB34: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8003DB38: nop

    // 0x8003DB3C: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x8003DB40: nop

    // 0x8003DB44: beq         $v0, $zero, L_8003DB50
    if (ctx->r2 == 0) {
        // 0x8003DB48: nop
    
            goto L_8003DB50;
    }
    // 0x8003DB48: nop

    // 0x8003DB4C: sw          $t5, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r13;
L_8003DB50:
    // 0x8003DB50: jal         0x8009C3C8
    // 0x8003DB54: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    get_number_of_active_players(rdram, ctx);
        goto after_10;
    // 0x8003DB54: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_10:
    // 0x8003DB58: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DB5C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8003DB60: bne         $at, $zero, L_8003DB78
    if (ctx->r1 != 0) {
        // 0x8003DB64: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8003DB78;
    }
    // 0x8003DB64: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8003DB68: jal         0x8000FFB8
    // 0x8003DB6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_11;
    // 0x8003DB6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8003DB70: b           L_8003DB94
    // 0x8003DB74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003DB94;
    // 0x8003DB74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003DB78:
    // 0x8003DB78: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8003DB7C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003DB80: sw          $t2, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r10;
    // 0x8003DB84: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8003DB88: jal         0x800AFC3C
    // 0x8003DB8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_12;
    // 0x8003DB8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8003DB90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003DB94:
    // 0x8003DB94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003DB98: jr          $ra
    // 0x8003DB9C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003DB9C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void debug_render_checkpoint_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001BC44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001BC48: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001BC4C: jr          $ra
    // 0x8001BC50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x8001BC50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void swap_lead_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F39C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F3A0: jal         0x8006A50C
    // 0x8006F3A4: nop

    input_swap_id(rdram, ctx);
        goto after_0;
    // 0x8006F3A4: nop

    after_0:
    // 0x8006F3A8: jal         0x8000E194
    // 0x8006F3AC: nop

    toggle_lead_player_index(rdram, ctx);
        goto after_1;
    // 0x8006F3AC: nop

    after_1:
    // 0x8006F3B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006F3B4: lw          $v0, 0x3510($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3510);
    // 0x8006F3B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006F3BC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8006F3C0: addiu       $v1, $v0, 0x54
    ctx->r3 = ADD32(ctx->r2, 0X54);
    // 0x8006F3C4: addiu       $a0, $v0, 0x6C
    ctx->r4 = ADD32(ctx->r2, 0X6C);
L_8006F3C8:
    // 0x8006F3C8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006F3CC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8006F3D0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006F3D4: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8006F3D8: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8006F3DC: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8006F3E0: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x8006F3E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006F3E8: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x8006F3EC: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8006F3F0: lbu         $v0, -0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X2);
    // 0x8006F3F4: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x8006F3F8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006F3FC: sb          $t8, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r24;
    // 0x8006F400: sb          $v0, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r2;
    // 0x8006F404: lbu         $v0, -0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X1);
    // 0x8006F408: lbu         $t9, -0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X1);
    // 0x8006F40C: nop

    // 0x8006F410: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x8006F414: bne         $a1, $a2, L_8006F3C8
    if (ctx->r5 != ctx->r6) {
        // 0x8006F418: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_8006F3C8;
    }
    // 0x8006F418: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
    // 0x8006F41C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F424: jr          $ra
    // 0x8006F428: nop

    return;
    // 0x8006F428: nop

;}
RECOMP_FUNC void set_position_goal_from_path(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059080: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80059084: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80059088: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8005908C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80059090: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80059094: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80059098: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8005909C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800590A0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800590A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800590A8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800590AC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800590B0: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800590B4: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800590B8: jal         0x8001BA64
    // 0x800590BC: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    get_checkpoint_count(rdram, ctx);
        goto after_0;
    // 0x800590BC: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    after_0:
    // 0x800590C0: beq         $v0, $zero, L_800591D8
    if (ctx->r2 == 0) {
        // 0x800590C4: or          $s6, $v0, $zero
        ctx->r22 = ctx->r2 | 0;
            goto L_800591D8;
    }
    // 0x800590C4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800590C8: lwc1        $f6, 0xA8($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0XA8);
    // 0x800590CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800590D0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800590D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800590D8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800590DC: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x800590E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800590E4: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x800590E8: addiu       $s2, $sp, 0x84
    ctx->r18 = ADD32(ctx->r29, 0X84);
    // 0x800590EC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800590F0: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x800590F4: bc1f        L_80059100
    if (!c1cs) {
        // 0x800590F8: addiu       $s0, $sp, 0x5C
        ctx->r16 = ADD32(ctx->r29, 0X5C);
            goto L_80059100;
    }
    // 0x800590F8: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x800590FC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80059100:
    // 0x80059100: lb          $v1, 0x192($s5)
    ctx->r3 = MEM_B(ctx->r21, 0X192);
    // 0x80059104: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x80059108: addiu       $s1, $v1, -0x2
    ctx->r17 = ADD32(ctx->r3, -0X2);
    // 0x8005910C: bgez        $s1, L_80059118
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80059110: nop
    
            goto L_80059118;
    }
    // 0x80059110: nop

    // 0x80059114: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_80059118:
    // 0x80059118: lbu         $a1, 0x1C8($s5)
    ctx->r5 = MEM_BU(ctx->r21, 0X1C8);
    // 0x8005911C: jal         0x8001BA1C
    // 0x80059120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_1;
    // 0x80059120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80059124: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80059128: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005912C: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
    // 0x80059130: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80059134: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80059138: swc1        $f18, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f18.u32l;
    // 0x8005913C: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80059140: bne         $s1, $s6, L_8005914C
    if (ctx->r17 != ctx->r22) {
        // 0x80059144: swc1        $f6, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
            goto L_8005914C;
    }
    // 0x80059144: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x80059148: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8005914C:
    // 0x8005914C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80059150: bne         $s0, $s4, L_80059118
    if (ctx->r16 != ctx->r20) {
        // 0x80059154: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80059118;
    }
    // 0x80059154: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80059158: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005915C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80059160: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80059164: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x80059168: c.le.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d <= ctx->f0.d;
    // 0x8005916C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80059170: bc1f        L_80059190
    if (!c1cs) {
        // 0x80059174: addiu       $a0, $sp, 0x84
        ctx->r4 = ADD32(ctx->r29, 0X84);
            goto L_80059190;
    }
    // 0x80059174: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80059178: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005917C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80059180: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80059184: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80059188: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x8005918C: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
L_80059190:
    // 0x80059190: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80059194: jal         0x80022540
    // 0x80059198: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_2;
    // 0x80059198: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8005919C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800591A0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800591A4: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x800591A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800591AC: jal         0x80022540
    // 0x800591B0: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_3;
    // 0x800591B0: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    after_3:
    // 0x800591B4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800591B8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800591BC: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800591C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800591C4: jal         0x80022540
    // 0x800591C8: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x800591C8: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    after_4:
    // 0x800591CC: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x800591D0: nop

    // 0x800591D4: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
L_800591D8:
    // 0x800591D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800591DC: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800591E0: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800591E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800591E8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800591EC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800591F0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800591F4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800591F8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800591FC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80059200: jr          $ra
    // 0x80059204: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80059204: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800BB2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB2F4: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800BB2F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BB2FC: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800BB300: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800BB304: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800BB308: bltz        $a0, L_800BB328
    if (SIGNED(ctx->r4) < 0) {
        // 0x800BB30C: sw          $a3, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r7;
            goto L_800BB328;
    }
    // 0x800BB30C: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800BB310: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BB314: lw          $t7, -0x5F20($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5F20);
    // 0x800BB318: nop

    // 0x800BB31C: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BB320: bne         $at, $zero, L_800BB330
    if (ctx->r1 != 0) {
        // 0x800BB324: lw          $t8, 0xA8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA8);
            goto L_800BB330;
    }
    // 0x800BB324: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
L_800BB328:
    // 0x800BB328: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x800BB32C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
L_800BB330:
    // 0x800BB330: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BB334: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800BB338: lw          $t9, 0x30D8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30D8);
    // 0x800BB33C: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800BB340: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BB344: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x800BB348: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BB34C: lw          $t9, 0x317C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X317C);
    // 0x800BB350: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x800BB354: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB358: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800BB35C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB360: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB364: lwc1        $f6, -0x5F44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5F44);
    // 0x800BB368: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB36C: lwc1        $f8, -0x5F48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5F48);
    // 0x800BB370: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BB374: addiu       $t1, $t1, -0x6038
    ctx->r9 = ADD32(ctx->r9, -0X6038);
    // 0x800BB378: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x800BB37C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB380: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB384: lwc1        $f4, 0x44($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X44);
    // 0x800BB388: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800BB38C: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800BB390: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BB394: lw          $t7, 0x28($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X28);
    // 0x800BB398: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB39C: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x800BB3A0: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x800BB3A4: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x800BB3A8: beq         $t7, $zero, L_800BB3E0
    if (ctx->r15 == 0) {
        // 0x800BB3AC: div.s       $f16, $f10, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
            goto L_800BB3E0;
    }
    // 0x800BB3AC: div.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800BB3B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BB3B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB3B8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BB3BC: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BB3C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BB3C4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BB3C8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BB3CC: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800BB3D0: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x800BB3D4: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800BB3D8: b           L_800BB3F0
    // 0x800BB3DC: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
        goto L_800BB3F0;
    // 0x800BB3DC: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
L_800BB3E0:
    // 0x800BB3E0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BB3E4: nop

    // 0x800BB3E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BB3EC: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
L_800BB3F0:
    // 0x800BB3F0: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x800BB3F4: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB3F8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800BB3FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB400: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB404: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BB408: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800BB40C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800BB410: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x800BB414: bc1f        L_800BB428
    if (!c1cs) {
        // 0x800BB418: nop
    
            goto L_800BB428;
    }
    // 0x800BB418: nop

    // 0x800BB41C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BB420: b           L_800BB454
    // 0x800BB424: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
        goto L_800BB454;
    // 0x800BB424: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
L_800BB428:
    // 0x800BB428: lwc1        $f0, -0x5F60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5F60);
    // 0x800BB42C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB430: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB434: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x800BB438: nop

    // 0x800BB43C: bc1f        L_800BB454
    if (!c1cs) {
        // 0x800BB440: nop
    
            goto L_800BB454;
    }
    // 0x800BB440: nop

    // 0x800BB444: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB448: nop

    // 0x800BB44C: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800BB450: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
L_800BB454:
    // 0x800BB454: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x800BB458: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BB45C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800BB460: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB464: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB468: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800BB46C: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800BB470: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800BB474: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x800BB478: bc1f        L_800BB48C
    if (!c1cs) {
        // 0x800BB47C: nop
    
            goto L_800BB48C;
    }
    // 0x800BB47C: nop

    // 0x800BB480: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BB484: b           L_800BB4B8
    // 0x800BB488: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
        goto L_800BB4B8;
    // 0x800BB488: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
L_800BB48C:
    // 0x800BB48C: lwc1        $f0, -0x5F5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5F5C);
    // 0x800BB490: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BB494: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB498: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x800BB49C: nop

    // 0x800BB4A0: bc1f        L_800BB4B8
    if (!c1cs) {
        // 0x800BB4A4: nop
    
            goto L_800BB4B8;
    }
    // 0x800BB4A4: nop

    // 0x800BB4A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BB4AC: nop

    // 0x800BB4B0: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800BB4B4: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
L_800BB4B8:
    // 0x800BB4B8: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB4BC: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BB4C0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800BB4C4: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BB4C8: lw          $v1, 0x4($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X4);
    // 0x800BB4CC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BB4D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800BB4D4: nop

    // 0x800BB4D8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800BB4DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BB4E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BB4E4: nop

    // 0x800BB4E8: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BB4EC: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BB4F0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800BB4F4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800BB4F8: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BB4FC: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x800BB500: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800BB504: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BB508: nop

    // 0x800BB50C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BB510: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BB514: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BB518: nop

    // 0x800BB51C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BB520: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800BB524: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BB528: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BB52C: sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    // 0x800BB530: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB534: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800BB538: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BB53C: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800BB540: nop

    // 0x800BB544: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800BB548: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800BB54C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x800BB550: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB554: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800BB558: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800BB55C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BB560: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x800BB564: lh          $t9, 0x12($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X12);
    // 0x800BB568: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BB56C: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800BB570: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BB574: bne         $at, $zero, L_800BB58C
    if (ctx->r1 != 0) {
        // 0x800BB578: nop
    
            goto L_800BB58C;
    }
    // 0x800BB578: nop

L_800BB57C:
    // 0x800BB57C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x800BB580: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BB584: beq         $at, $zero, L_800BB57C
    if (ctx->r1 == 0) {
        // 0x800BB588: nop
    
            goto L_800BB57C;
    }
    // 0x800BB588: nop

L_800BB58C:
    // 0x800BB58C: lh          $t7, 0x10($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X10);
    // 0x800BB590: addiu       $ra, $t0, 0x1
    ctx->r31 = ADD32(ctx->r8, 0X1);
    // 0x800BB594: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x800BB598: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BB59C: bne         $at, $zero, L_800BB5B4
    if (ctx->r1 != 0) {
        // 0x800BB5A0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_800BB5B4;
    }
    // 0x800BB5A0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
L_800BB5A4:
    // 0x800BB5A4: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // 0x800BB5A8: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BB5AC: beq         $at, $zero, L_800BB5A4
    if (ctx->r1 == 0) {
        // 0x800BB5B0: nop
    
            goto L_800BB5A4;
    }
    // 0x800BB5B0: nop

L_800BB5B4:
    // 0x800BB5B4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800BB5B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BB5BC: bc1t        L_800BB5F0
    if (c1cs) {
        // 0x800BB5C0: slt         $at, $ra, $v1
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BB5F0;
    }
    // 0x800BB5C0: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BB5C4: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800BB5C8: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB5CC: div.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BB5D0: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BB5D4: nop

    // 0x800BB5D8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BB5DC: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800BB5E0: nop

    // 0x800BB5E4: bc1f        L_800BB5F0
    if (!c1cs) {
        // 0x800BB5E8: nop
    
            goto L_800BB5F0;
    }
    // 0x800BB5E8: nop

    // 0x800BB5EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800BB5F0:
    // 0x800BB5F0: beq         $v0, $zero, L_800BB970
    if (ctx->r2 == 0) {
        // 0x800BB5F4: nop
    
            goto L_800BB970;
    }
    // 0x800BB5F4: nop

    // 0x800BB5F8: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB5FC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BB600: lw          $t2, 0x3044($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3044);
    // 0x800BB604: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BB608: lw          $a1, 0x3040($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3040);
    // 0x800BB60C: lwc1        $f14, 0x40($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X40);
    // 0x800BB610: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BB614: lw          $t3, 0x3188($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3188);
    // 0x800BB618: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BB61C: mflo        $t9
    ctx->r25 = lo;
    // 0x800BB620: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800BB624: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BB628: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800BB62C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800BB630: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800BB634: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BB638: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BB63C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BB640: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BB644: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BB648: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BB64C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BB650: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800BB654: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800BB658: blez        $t3, L_800BB6B4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BB65C: swc1        $f8, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
            goto L_800BB6B4;
    }
    // 0x800BB65C: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x800BB660: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BB664: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800BB668: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800BB66C: jal         0x800BEFC4
    // 0x800BB670: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800BB670: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800BB674: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BB678: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BB67C: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800BB680: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BB684: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BB688: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB68C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BB690: lw          $t3, 0x3188($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3188);
    // 0x800BB694: lwc1        $f14, -0x5FF8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5FF8);
    // 0x800BB698: lw          $t2, 0x3044($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3044);
    // 0x800BB69C: lw          $a1, 0x3040($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3040);
    // 0x800BB6A0: lw          $v1, -0x6034($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6034);
    // 0x800BB6A4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800BB6A8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800BB6AC: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BB6B0: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
L_800BB6B4:
    // 0x800BB6B4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800BB6B8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800BB6BC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800BB6C0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB6C4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800BB6C8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BB6CC: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x800BB6D0: lw          $t4, 0x3178($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3178);
    // 0x800BB6D4: addiu       $t1, $a3, 0x1
    ctx->r9 = ADD32(ctx->r7, 0X1);
    // 0x800BB6D8: mflo        $t9
    ctx->r25 = lo;
    // 0x800BB6DC: addu        $ra, $t5, $t9
    ctx->r31 = ADD32(ctx->r13, ctx->r25);
    // 0x800BB6E0: addu        $t6, $t4, $ra
    ctx->r14 = ADD32(ctx->r12, ctx->r31);
    // 0x800BB6E4: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x800BB6E8: nop

    // 0x800BB6EC: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BB6F0: beq         $at, $zero, L_800BB720
    if (ctx->r1 == 0) {
        // 0x800BB6F4: slt         $at, $t1, $v1
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BB720;
    }
    // 0x800BB6F4: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BB6F8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800BB6FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB700: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB704: lwc1        $f4, -0x5FF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5FF4);
    // 0x800BB708: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BB70C: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BB710: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800BB714: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BB718: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x800BB71C: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
L_800BB720:
    // 0x800BB720: bne         $at, $zero, L_800BB730
    if (ctx->r1 != 0) {
        // 0x800BB724: nop
    
            goto L_800BB730;
    }
    // 0x800BB724: nop

    // 0x800BB728: b           L_800BB740
    // 0x800BB72C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_800BB740;
    // 0x800BB72C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800BB730:
    // 0x800BB730: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB734: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB738: addu        $a0, $t7, $t0
    ctx->r4 = ADD32(ctx->r15, ctx->r8);
    // 0x800BB73C: nop

L_800BB740:
    // 0x800BB740: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800BB744: addu        $v0, $t2, $t8
    ctx->r2 = ADD32(ctx->r10, ctx->r24);
    // 0x800BB748: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800BB74C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800BB750: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BB754: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800BB758: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BB75C: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x800BB760: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BB764: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BB768: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BB76C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800BB770: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BB774: mul.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BB778: blez        $t3, L_800BB7EC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BB77C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800BB7EC;
    }
    // 0x800BB77C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BB780: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BB784: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800BB788: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800BB78C: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800BB790: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800BB794: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BB798: jal         0x800BEFC4
    // 0x800BB79C: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_1;
    // 0x800BB79C: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x800BB7A0: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BB7A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BB7A8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BB7AC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BB7B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB7B4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BB7B8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BB7BC: lw          $t4, 0x3178($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3178);
    // 0x800BB7C0: lw          $t3, 0x3188($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3188);
    // 0x800BB7C4: lwc1        $f14, -0x5FF8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5FF8);
    // 0x800BB7C8: lw          $t2, 0x3044($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3044);
    // 0x800BB7CC: lw          $a1, 0x3040($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3040);
    // 0x800BB7D0: lw          $v1, -0x6034($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6034);
    // 0x800BB7D4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800BB7D8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800BB7DC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800BB7E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800BB7E4: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BB7E8: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_800BB7EC:
    // 0x800BB7EC: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800BB7F0: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800BB7F4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BB7F8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB7FC: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800BB800: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB804: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800BB808: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800BB80C: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB810: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800BB814: nop

    // 0x800BB818: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BB81C: mflo        $a2
    ctx->r6 = lo;
    // 0x800BB820: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    // 0x800BB824: beq         $at, $zero, L_800BB84C
    if (ctx->r1 == 0) {
        // 0x800BB828: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800BB84C;
    }
    // 0x800BB828: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BB82C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800BB830: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB834: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB838: lwc1        $f4, -0x5FF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5FF4);
    // 0x800BB83C: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BB840: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BB844: mul.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800BB848: nop

L_800BB84C:
    // 0x800BB84C: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BB850: bne         $at, $zero, L_800BB860
    if (ctx->r1 != 0) {
        // 0x800BB854: nop
    
            goto L_800BB860;
    }
    // 0x800BB854: nop

    // 0x800BB858: b           L_800BB860
    // 0x800BB85C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_800BB860;
    // 0x800BB85C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800BB860:
    // 0x800BB860: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BB864: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800BB868: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800BB86C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800BB870: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BB874: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BB878: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BB87C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BB880: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BB884: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BB888: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BB88C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BB890: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BB894: mul.s       $f2, $f8, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BB898: blez        $t3, L_800BB8D4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BB89C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800BB8D4;
    }
    // 0x800BB89C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BB8A0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BB8A4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800BB8A8: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x800BB8AC: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BB8B0: jal         0x800BEFC4
    // 0x800BB8B4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_2;
    // 0x800BB8B4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x800BB8B8: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800BB8BC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BB8C0: lw          $t4, 0x3178($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3178);
    // 0x800BB8C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800BB8C8: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BB8CC: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BB8D0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_800BB8D4:
    // 0x800BB8D4: addu        $t9, $t4, $ra
    ctx->r25 = ADD32(ctx->r12, ctx->r31);
    // 0x800BB8D8: lbu         $v0, 0x1($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X1);
    // 0x800BB8DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BB8E0: lw          $v1, -0x6010($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6010);
    // 0x800BB8E4: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BB8E8: beq         $at, $zero, L_800BB910
    if (ctx->r1 == 0) {
        // 0x800BB8EC: nop
    
            goto L_800BB910;
    }
    // 0x800BB8EC: nop

    // 0x800BB8F0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BB8F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB8F8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB8FC: lwc1        $f10, -0x5FF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5FF4);
    // 0x800BB900: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BB904: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800BB908: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800BB90C: nop

L_800BB910:
    // 0x800BB910: beq         $v1, $zero, L_800BB93C
    if (ctx->r3 == 0) {
        // 0x800BB914: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800BB93C;
    }
    // 0x800BB914: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BB918: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BB91C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB920: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BB924: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BB928: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BB92C: mul.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800BB930: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x800BB934: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800BB938: nop

L_800BB93C:
    // 0x800BB93C: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BB940: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BB944: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BB948: sub.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800BB94C: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x800BB950: mul.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800BB954: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BB958: nop

    // 0x800BB95C: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BB960: sub.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800BB964: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BB968: b           L_800BBD00
    // 0x800BB96C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
        goto L_800BBD00;
    // 0x800BB96C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
L_800BB970:
    // 0x800BB970: bne         $at, $zero, L_800BB988
    if (ctx->r1 != 0) {
        // 0x800BB974: nop
    
            goto L_800BB988;
    }
    // 0x800BB974: nop

    // 0x800BB978: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB97C: mflo        $a0
    ctx->r4 = lo;
    // 0x800BB980: b           L_800BB998
    // 0x800BB984: nop

        goto L_800BB998;
    // 0x800BB984: nop

L_800BB988:
    // 0x800BB988: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB98C: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB990: addu        $a0, $t0, $t6
    ctx->r4 = ADD32(ctx->r8, ctx->r14);
    // 0x800BB994: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800BB998:
    // 0x800BB998: lw          $t2, 0x3044($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3044);
    // 0x800BB99C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BB9A0: addu        $v0, $t2, $t7
    ctx->r2 = ADD32(ctx->r10, ctx->r15);
    // 0x800BB9A4: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x800BB9A8: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800BB9AC: lw          $a1, 0x3040($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3040);
    // 0x800BB9B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BB9B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BB9B8: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x800BB9BC: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BB9C0: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BB9C4: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BB9C8: lwc1        $f14, 0x40($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X40);
    // 0x800BB9CC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BB9D0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BB9D4: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800BB9D8: lw          $t3, 0x3188($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3188);
    // 0x800BB9DC: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BB9E0: blez        $t3, L_800BBA4C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BB9E4: swc1        $f10, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
            goto L_800BBA4C;
    }
    // 0x800BB9E4: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x800BB9E8: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BB9EC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BB9F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BB9F4: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800BB9F8: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800BB9FC: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x800BBA00: jal         0x800BEFC4
    // 0x800BBA04: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    waves_get_y(rdram, ctx);
        goto after_3;
    // 0x800BBA04: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_3:
    // 0x800BBA08: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBA0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBA10: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800BBA14: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BBA18: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BBA1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBA20: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBA24: lw          $t3, 0x3188($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3188);
    // 0x800BBA28: lwc1        $f14, -0x5FF8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5FF8);
    // 0x800BBA2C: lw          $t2, 0x3044($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3044);
    // 0x800BBA30: lw          $a1, 0x3040($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3040);
    // 0x800BBA34: lw          $v1, -0x6034($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6034);
    // 0x800BBA38: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800BBA3C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800BBA40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BBA44: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBA48: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
L_800BBA4C:
    // 0x800BBA4C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBA50: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800BBA54: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800BBA58: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBA5C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800BBA60: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBA64: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x800BBA68: lw          $t4, 0x3178($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3178);
    // 0x800BBA6C: addiu       $t1, $a3, 0x1
    ctx->r9 = ADD32(ctx->r7, 0X1);
    // 0x800BBA70: mflo        $t6
    ctx->r14 = lo;
    // 0x800BBA74: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800BBA78: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800BBA7C: lbu         $v0, 0x1($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X1);
    // 0x800BBA80: nop

    // 0x800BBA84: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBA88: beq         $at, $zero, L_800BBAB8
    if (ctx->r1 == 0) {
        // 0x800BBA8C: slt         $at, $t1, $v1
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BBAB8;
    }
    // 0x800BBA8C: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBA90: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800BBA94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBA98: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBA9C: lwc1        $f6, -0x5FF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5FF4);
    // 0x800BBAA0: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BBAA4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBAA8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800BBAAC: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBAB0: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x800BBAB4: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
L_800BBAB8:
    // 0x800BBAB8: bne         $at, $zero, L_800BBAC8
    if (ctx->r1 != 0) {
        // 0x800BBABC: nop
    
            goto L_800BBAC8;
    }
    // 0x800BBABC: nop

    // 0x800BBAC0: b           L_800BBAD8
    // 0x800BBAC4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_800BBAD8;
    // 0x800BBAC4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800BBAC8:
    // 0x800BBAC8: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBACC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BBAD0: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800BBAD4: nop

L_800BBAD8:
    // 0x800BBAD8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BBADC: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800BBAE0: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800BBAE4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800BBAE8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BBAEC: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BBAF0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BBAF4: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BBAF8: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BBAFC: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BBB00: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBB04: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800BBB08: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BBB0C: mul.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800BBB10: blez        $t3, L_800BBB7C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BBB14: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800BBB7C;
    }
    // 0x800BBB14: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BBB18: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BBB1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BBB20: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800BBB24: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800BBB28: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BBB2C: jal         0x800BEFC4
    // 0x800BBB30: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_4;
    // 0x800BBB30: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x800BBB34: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BBB38: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBB3C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BBB40: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BBB44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBB48: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBB4C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBB50: lw          $t4, 0x3178($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3178);
    // 0x800BBB54: lw          $t3, 0x3188($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3188);
    // 0x800BBB58: lwc1        $f14, -0x5FF8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5FF8);
    // 0x800BBB5C: lw          $t2, 0x3044($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3044);
    // 0x800BBB60: lw          $a1, 0x3040($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3040);
    // 0x800BBB64: lw          $v1, -0x6034($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6034);
    // 0x800BBB68: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800BBB6C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800BBB70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BBB74: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBB78: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_800BBB7C:
    // 0x800BBB7C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBB80: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800BBB84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BBB88: multu       $a2, $t9
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBB8C: or          $a0, $ra, $zero
    ctx->r4 = ctx->r31 | 0;
    // 0x800BBB90: mflo        $t6
    ctx->r14 = lo;
    // 0x800BBB94: addu        $a3, $t5, $t6
    ctx->r7 = ADD32(ctx->r13, ctx->r14);
    // 0x800BBB98: addu        $t7, $t4, $a3
    ctx->r15 = ADD32(ctx->r12, ctx->r7);
    // 0x800BBB9C: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800BBBA0: nop

    // 0x800BBBA4: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBBA8: beq         $at, $zero, L_800BBBD4
    if (ctx->r1 == 0) {
        // 0x800BBBAC: slt         $at, $ra, $v1
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BBBD4;
    }
    // 0x800BBBAC: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBBB0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800BBBB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBBB8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BBBBC: lwc1        $f6, -0x5FF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5FF4);
    // 0x800BBBC0: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BBBC4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800BBBC8: mul.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800BBBCC: nop

    // 0x800BBBD0: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
L_800BBBD4:
    // 0x800BBBD4: bne         $at, $zero, L_800BBBE4
    if (ctx->r1 != 0) {
        // 0x800BBBD8: nop
    
            goto L_800BBBE4;
    }
    // 0x800BBBD8: nop

    // 0x800BBBDC: b           L_800BBBE4
    // 0x800BBBE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800BBBE4;
    // 0x800BBBE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BBBE4:
    // 0x800BBBE4: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBBE8: beq         $at, $zero, L_800BBC04
    if (ctx->r1 == 0) {
        // 0x800BBBEC: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_800BBC04;
    }
    // 0x800BBBEC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BBBF0: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBBF4: mflo        $t8
    ctx->r24 = lo;
    // 0x800BBBF8: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800BBBFC: nop

    // 0x800BBC00: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
L_800BBC04:
    // 0x800BBC04: addu        $v0, $t2, $t9
    ctx->r2 = ADD32(ctx->r10, ctx->r25);
    // 0x800BBC08: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x800BBC0C: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800BBC10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BBC14: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BBC18: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BBC1C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800BBC20: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BBC24: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BBC28: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BBC2C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BBC30: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BBC34: mul.s       $f2, $f10, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800BBC38: blez        $t3, L_800BBC70
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BBC3C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800BBC70;
    }
    // 0x800BBC3C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BBC40: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800BBC44: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x800BBC48: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BBC4C: jal         0x800BEFC4
    // 0x800BBC50: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_5;
    // 0x800BBC50: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x800BBC54: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800BBC58: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBC5C: lw          $t4, 0x3178($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3178);
    // 0x800BBC60: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800BBC64: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BBC68: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBC6C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_800BBC70:
    // 0x800BBC70: addu        $t8, $t4, $a3
    ctx->r24 = ADD32(ctx->r12, ctx->r7);
    // 0x800BBC74: lbu         $v0, 0x1($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X1);
    // 0x800BBC78: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBC7C: lw          $v1, -0x6010($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6010);
    // 0x800BBC80: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBC84: beq         $at, $zero, L_800BBCAC
    if (ctx->r1 == 0) {
        // 0x800BBC88: nop
    
            goto L_800BBCAC;
    }
    // 0x800BBC88: nop

    // 0x800BBC8C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BBC90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBC94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBC98: lwc1        $f8, -0x5FF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5FF4);
    // 0x800BBC9C: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BBCA0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BBCA4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800BBCA8: nop

L_800BBCAC:
    // 0x800BBCAC: beq         $v1, $zero, L_800BBCD8
    if (ctx->r3 == 0) {
        // 0x800BBCB0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800BBCD8;
    }
    // 0x800BBCB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BBCB4: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBCB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BBCBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BBCC0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BBCC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BBCC8: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BBCCC: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x800BBCD0: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800BBCD4: nop

L_800BBCD8:
    // 0x800BBCD8: sub.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x800BBCDC: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BBCE0: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BBCE4: mul.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800BBCE8: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBCEC: swc1        $f8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
    // 0x800BBCF0: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800BBCF4: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800BBCF8: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BBCFC: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
L_800BBD00:
    // 0x800BBD00: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800BBD04: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x800BBD08: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x800BBD0C: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x800BBD10: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800BBD14: nop

    // 0x800BBD18: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800BBD1C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BBD20: jal         0x800C9AD0
    // 0x800BBD24: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x800BBD24: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_6:
    // 0x800BBD28: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800BBD2C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800BBD30: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800BBD34: c.eq.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d == ctx->f4.d;
    // 0x800BBD38: lwc1        $f14, 0x88($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800BBD3C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800BBD40: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800BBD44: bc1t        L_800BBDB4
    if (c1cs) {
        // 0x800BBD48: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800BBDB4;
    }
    // 0x800BBD48: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800BBD4C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x800BBD50: c.eq.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d == ctx->f6.d;
    // 0x800BBD54: nop

    // 0x800BBD58: bc1t        L_800BBDB0
    if (c1cs) {
        // 0x800BBD5C: nop
    
            goto L_800BBDB0;
    }
    // 0x800BBD5C: nop

    // 0x800BBD60: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800BBD64: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BBD68: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BBD6C: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BBD70: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800BBD74: nop

    // 0x800BBD78: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800BBD7C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800BBD80: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800BBD84: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800BBD88: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBD8C: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800BBD90: swc1        $f2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f2.u32l;
    // 0x800BBD94: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BBD98: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800BBD9C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800BBDA0: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800BBDA4: div.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BBDA8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800BBDAC: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
L_800BBDB0:
    // 0x800BBDB0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800BBDB4:
    // 0x800BBDB4: lwc1        $f2, 0x84($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800BBDB8: beq         $t9, $zero, L_800BBDD0
    if (ctx->r25 == 0) {
        // 0x800BBDBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BBDD0;
    }
    // 0x800BBDBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BBDC0: swc1        $f14, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f14.u32l;
    // 0x800BBDC4: swc1        $f2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f2.u32l;
    // 0x800BBDC8: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x800BBDCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BBDD0:
    // 0x800BBDD0: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800BBDD4: jr          $ra
    // 0x800BBDD8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800BBDD8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void racer_set_dialogue_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A3C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005A3C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A3C8: jr          $ra
    // 0x8005A3CC: sb          $t6, -0x2A7D($at)
    MEM_B(-0X2A7D, ctx->r1) = ctx->r14;
    return;
    // 0x8005A3CC: sb          $t6, -0x2A7D($at)
    MEM_B(-0X2A7D, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void objGetObjList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E988: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E98C: lw          $t6, -0x51A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X51A0);
    // 0x8000E990: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000E994: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000E998: lw          $t7, -0x51A4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X51A4);
    // 0x8000E99C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9A0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000E9A4: lw          $v0, -0x51A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A8);
    // 0x8000E9A8: jr          $ra
    // 0x8000E9AC: nop

    return;
    // 0x8000E9AC: nop

;}
RECOMP_FUNC void obj_loop_door(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B988: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8003B98C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003B990: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003B994: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003B998: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8003B99C: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8003B9A0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B9A4: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8003B9A8: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8003B9AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B9B0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003B9B4: bne         $t8, $zero, L_8003B9D4
    if (ctx->r24 != 0) {
        // 0x8003B9B8: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_8003B9D4;
    }
    // 0x8003B9B8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8003B9BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003B9C0: lwc1        $f9, 0x6168($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6168);
    // 0x8003B9C4: lwc1        $f8, 0x616C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X616C);
    // 0x8003B9C8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003B9CC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003B9D0: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_8003B9D4:
    // 0x8003B9D4: jal         0x8006EA90
    // 0x8003B9D8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003B9D8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8003B9DC: lbu         $t3, 0x49($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X49);
    // 0x8003B9E0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8003B9E4: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x8003B9E8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003B9EC: lb          $v1, 0xE($t0)
    ctx->r3 = MEM_B(ctx->r8, 0XE);
    // 0x8003B9F0: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8003B9F4: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x8003B9F8: bltz        $v1, L_8003C194
    if (SIGNED(ctx->r3) < 0) {
        // 0x8003B9FC: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8003C194;
    }
    // 0x8003B9FC: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8003BA00: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8003BA04: sllv        $t7, $t6, $v1
    ctx->r15 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x8003BA08: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8003BA0C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003BA10: nop

    // 0x8003BA14: lbu         $a0, 0x13($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X13);
    // 0x8003BA18: nop

    // 0x8003BA1C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8003BA20: lbu         $t8, 0xF($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XF);
    // 0x8003BA24: nop

    // 0x8003BA28: andi        $t3, $t8, 0x1
    ctx->r11 = ctx->r24 & 0X1;
    // 0x8003BA2C: bne         $t3, $zero, L_8003BA3C
    if (ctx->r11 != 0) {
        // 0x8003BA30: lw          $t9, 0x54($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X54);
            goto L_8003BA3C;
    }
    // 0x8003BA30: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8003BA34: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x8003BA38: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
L_8003BA3C:
    // 0x8003BA3C: nop

    // 0x8003BA40: and         $t4, $a1, $t9
    ctx->r12 = ctx->r5 & ctx->r25;
    // 0x8003BA44: bne         $t4, $zero, L_8003BB88
    if (ctx->r12 != 0) {
        // 0x8003BA48: sw          $t4, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r12;
            goto L_8003BB88;
    }
    // 0x8003BA48: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8003BA4C: lbu         $t6, 0x12($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X12);
    // 0x8003BA50: nop

    // 0x8003BA54: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003BA58: beq         $at, $zero, L_8003BB88
    if (ctx->r1 == 0) {
        // 0x8003BA5C: nop
    
            goto L_8003BB88;
    }
    // 0x8003BA5C: nop

    // 0x8003BA60: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003BA64: nop

    // 0x8003BA68: beq         $v1, $zero, L_8003BB88
    if (ctx->r3 == 0) {
        // 0x8003BA6C: nop
    
            goto L_8003BB88;
    }
    // 0x8003BA6C: nop

    // 0x8003BA70: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8003BA74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BA78: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x8003BA7C: nop

    // 0x8003BA80: bne         $a2, $t8, L_8003BB88
    if (ctx->r6 != ctx->r24) {
        // 0x8003BA84: nop
    
            goto L_8003BB88;
    }
    // 0x8003BA84: nop

    // 0x8003BA88: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003BA8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BA90: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x8003BA94: nop

    // 0x8003BA98: beq         $t3, $at, L_8003BB68
    if (ctx->r11 == ctx->r1) {
        // 0x8003BA9C: nop
    
            goto L_8003BB68;
    }
    // 0x8003BA9C: nop

    // 0x8003BAA0: lw          $t9, 0x5C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X5C);
    // 0x8003BAA4: nop

    // 0x8003BAA8: lw          $t4, 0x100($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X100);
    // 0x8003BAAC: nop

    // 0x8003BAB0: bne         $v1, $t4, L_8003BB68
    if (ctx->r3 != ctx->r12) {
        // 0x8003BAB4: nop
    
            goto L_8003BB68;
    }
    // 0x8003BAB4: nop

    // 0x8003BAB8: lb          $t5, 0x13($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X13);
    // 0x8003BABC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BAC0: beq         $t5, $at, L_8003BB64
    if (ctx->r13 == ctx->r1) {
        // 0x8003BAC4: addiu       $t3, $zero, 0x12C
        ctx->r11 = ADD32(0, 0X12C);
            goto L_8003BB64;
    }
    // 0x8003BAC4: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8003BAC8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BACC: jal         0x800C3400
    // 0x8003BAD0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    textbox_visible(rdram, ctx);
        goto after_1;
    // 0x8003BAD0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_1:
    // 0x8003BAD4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BAD8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BADC: bne         $v0, $zero, L_8003BB64
    if (ctx->r2 != 0) {
        // 0x8003BAE0: addiu       $t3, $zero, 0x12C
        ctx->r11 = ADD32(0, 0X12C);
            goto L_8003BB64;
    }
    // 0x8003BAE0: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8003BAE4: lh          $t6, 0xC($t0)
    ctx->r14 = MEM_H(ctx->r8, 0XC);
    // 0x8003BAE8: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    // 0x8003BAEC: bne         $t6, $zero, L_8003BB64
    if (ctx->r14 != 0) {
        // 0x8003BAF0: addiu       $t3, $zero, 0x12C
        ctx->r11 = ADD32(0, 0X12C);
            goto L_8003BB64;
    }
    // 0x8003BAF0: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8003BAF4: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BAF8: jal         0x80000C98
    // 0x8003BAFC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    music_fade(rdram, ctx);
        goto after_2;
    // 0x8003BAFC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_2:
    // 0x8003BB00: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB04: addiu       $t7, $zero, 0x8C
    ctx->r15 = ADD32(0, 0X8C);
    // 0x8003BB08: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8003BB0C: jal         0x80000C38
    // 0x8003BB10: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x8003BB10: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    after_3:
    // 0x8003BB14: jal         0x80008140
    // 0x8003BB18: nop

    audspat_jingle_off(rdram, ctx);
        goto after_4;
    // 0x8003BB18: nop

    after_4:
    // 0x8003BB1C: jal         0x80001BC0
    // 0x8003BB20: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    music_jingle_play(rdram, ctx);
        goto after_5;
    // 0x8003BB20: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_5:
    // 0x8003BB24: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB28: nop

    // 0x8003BB2C: lbu         $a0, 0x10($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X10);
    // 0x8003BB30: jal         0x800C3140
    // 0x8003BB34: nop

    set_textbox_display_value(rdram, ctx);
        goto after_6;
    // 0x8003BB34: nop

    after_6:
    // 0x8003BB38: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB3C: nop

    // 0x8003BB40: lb          $a0, 0x13($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X13);
    // 0x8003BB44: nop

    // 0x8003BB48: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x8003BB4C: jal         0x800C31EC
    // 0x8003BB50: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    set_current_text(rdram, ctx);
        goto after_7;
    // 0x8003BB50: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_7:
    // 0x8003BB54: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB58: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BB5C: nop

    // 0x8003BB60: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
L_8003BB64:
    // 0x8003BB64: sh          $t3, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r11;
L_8003BB68:
    // 0x8003BB68: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BB6C: jal         0x800C3400
    // 0x8003BB70: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    textbox_visible(rdram, ctx);
        goto after_8;
    // 0x8003BB70: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_8:
    // 0x8003BB74: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB78: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BB7C: beq         $v0, $zero, L_8003BB88
    if (ctx->r2 == 0) {
        // 0x8003BB80: addiu       $t9, $zero, 0x12C
        ctx->r25 = ADD32(0, 0X12C);
            goto L_8003BB88;
    }
    // 0x8003BB80: addiu       $t9, $zero, 0x12C
    ctx->r25 = ADD32(0, 0X12C);
    // 0x8003BB84: sh          $t9, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r25;
L_8003BB88:
    // 0x8003BB88: lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X8);
    // 0x8003BB8C: nop

    // 0x8003BB90: beq         $t4, $zero, L_8003BC00
    if (ctx->r12 == 0) {
        // 0x8003BB94: nop
    
            goto L_8003BC00;
    }
    // 0x8003BB94: nop

    // 0x8003BB98: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BB9C: jal         0x80001C08
    // 0x8003BBA0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    music_jingle_playing(rdram, ctx);
        goto after_9;
    // 0x8003BBA0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_9:
    // 0x8003BBA4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BBA8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BBAC: bne         $v0, $zero, L_8003BC00
    if (ctx->r2 != 0) {
        // 0x8003BBB0: nop
    
            goto L_8003BC00;
    }
    // 0x8003BBB0: nop

    // 0x8003BBB4: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8003BBB8: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8003BBBC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8003BBC0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003BBC4: beq         $at, $zero, L_8003BBD4
    if (ctx->r1 == 0) {
        // 0x8003BBC8: subu        $t5, $v0, $v1
        ctx->r13 = SUB32(ctx->r2, ctx->r3);
            goto L_8003BBD4;
    }
    // 0x8003BBC8: subu        $t5, $v0, $v1
    ctx->r13 = SUB32(ctx->r2, ctx->r3);
    // 0x8003BBCC: b           L_8003BC00
    // 0x8003BBD0: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
        goto L_8003BC00;
    // 0x8003BBD0: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
L_8003BBD4:
    // 0x8003BBD4: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x8003BBD8: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8003BBDC: jal         0x80000C98
    // 0x8003BBE0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    music_fade(rdram, ctx);
        goto after_10;
    // 0x8003BBE0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_10:
    // 0x8003BBE4: jal         0x80000C38
    // 0x8003BBE8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_11;
    // 0x8003BBE8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_11:
    // 0x8003BBEC: jal         0x80008168
    // 0x8003BBF0: nop

    audspat_jingle_on(rdram, ctx);
        goto after_12;
    // 0x8003BBF0: nop

    after_12:
    // 0x8003BBF4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BBF8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BBFC: nop

L_8003BC00:
    // 0x8003BC00: lh          $v0, 0xC($t0)
    ctx->r2 = MEM_H(ctx->r8, 0XC);
    // 0x8003BC04: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8003BC08: blez        $v0, L_8003BC1C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003BC0C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8003BC1C;
    }
    // 0x8003BC0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BC10: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // 0x8003BC14: b           L_8003BC20
    // 0x8003BC18: sh          $t6, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r14;
        goto L_8003BC20;
    // 0x8003BC18: sh          $t6, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r14;
L_8003BC1C:
    // 0x8003BC1C: sh          $zero, 0xC($t0)
    MEM_H(0XC, ctx->r8) = 0;
L_8003BC20:
    // 0x8003BC20: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003BC24: lbu         $t8, 0x12($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X12);
    // 0x8003BC28: lbu         $t7, 0x13($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X13);
    // 0x8003BC2C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003BC30: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003BC34: beq         $at, $zero, L_8003BC98
    if (ctx->r1 == 0) {
        // 0x8003BC38: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8003BC98;
    }
    // 0x8003BC38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003BC3C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003BC40: nop

    // 0x8003BC44: beq         $v1, $zero, L_8003BC98
    if (ctx->r3 == 0) {
        // 0x8003BC48: nop
    
            goto L_8003BC98;
    }
    // 0x8003BC48: nop

    // 0x8003BC4C: lw          $t3, 0x40($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X40);
    // 0x8003BC50: nop

    // 0x8003BC54: lb          $t9, 0x54($t3)
    ctx->r25 = MEM_B(ctx->r11, 0X54);
    // 0x8003BC58: nop

    // 0x8003BC5C: bne         $a2, $t9, L_8003BC98
    if (ctx->r6 != ctx->r25) {
        // 0x8003BC60: nop
    
            goto L_8003BC98;
    }
    // 0x8003BC60: nop

    // 0x8003BC64: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003BC68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003BC6C: lb          $a0, 0x1D6($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X1D6);
    // 0x8003BC70: nop

    // 0x8003BC74: beq         $a0, $a2, L_8003BC8C
    if (ctx->r4 == ctx->r6) {
        // 0x8003BC78: nop
    
            goto L_8003BC8C;
    }
    // 0x8003BC78: nop

    // 0x8003BC7C: beq         $a0, $at, L_8003BC98
    if (ctx->r4 == ctx->r1) {
        // 0x8003BC80: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_8003BC98;
    }
    // 0x8003BC80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8003BC84: b           L_8003BC98
    // 0x8003BC88: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_8003BC98;
    // 0x8003BC88: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8003BC8C:
    // 0x8003BC8C: b           L_8003BC98
    // 0x8003BC90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8003BC98;
    // 0x8003BC90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8003BC94: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8003BC98:
    // 0x8003BC98: lbu         $t4, 0x10($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X10);
    // 0x8003BC9C: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x8003BCA0: addiu       $at, $zero, 0x87
    ctx->r1 = ADD32(0, 0X87);
    // 0x8003BCA4: beq         $v0, $at, L_8003BCB8
    if (ctx->r2 == ctx->r1) {
        // 0x8003BCA8: and         $a0, $a0, $t4
        ctx->r4 = ctx->r4 & ctx->r12;
            goto L_8003BCB8;
    }
    // 0x8003BCA8: and         $a0, $a0, $t4
    ctx->r4 = ctx->r4 & ctx->r12;
    // 0x8003BCAC: addiu       $at, $zero, 0xD7
    ctx->r1 = ADD32(0, 0XD7);
    // 0x8003BCB0: bne         $v0, $at, L_8003BCE0
    if (ctx->r2 != ctx->r1) {
        // 0x8003BCB4: nop
    
            goto L_8003BCE0;
    }
    // 0x8003BCB4: nop

L_8003BCB8:
    // 0x8003BCB8: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x8003BCBC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BCC0: jal         0x800235C0
    // 0x8003BCC4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    obj_door_override(rdram, ctx);
        goto after_13;
    // 0x8003BCC4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_13:
    // 0x8003BCC8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8003BCCC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BCD0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BCD4: beq         $v0, $zero, L_8003BCE0
    if (ctx->r2 == 0) {
        // 0x8003BCD8: nop
    
            goto L_8003BCE0;
    }
    // 0x8003BCD8: nop

    // 0x8003BCDC: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_8003BCE0:
    // 0x8003BCE0: lb          $t5, 0x15($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X15);
    // 0x8003BCE4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003BCE8: bne         $t5, $zero, L_8003BD34
    if (ctx->r13 != 0) {
        // 0x8003BCEC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8003BD34;
    }
    // 0x8003BCEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BCF0: lbu         $v0, 0x12($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X12);
    // 0x8003BCF4: bne         $a0, $zero, L_8003BD20
    if (ctx->r4 != 0) {
        // 0x8003BCF8: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_8003BD20;
    }
    // 0x8003BCF8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8003BCFC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003BD00: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8003BD04: beq         $t6, $zero, L_8003BD1C
    if (ctx->r14 == 0) {
        // 0x8003BD08: slt         $at, $t7, $v0
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8003BD1C;
    }
    // 0x8003BD08: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003BD0C: beq         $at, $zero, L_8003BD20
    if (ctx->r1 == 0) {
        // 0x8003BD10: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_8003BD20;
    }
    // 0x8003BD10: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8003BD14: b           L_8003BD34
    // 0x8003BD18: sb          $a2, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r6;
        goto L_8003BD34;
    // 0x8003BD18: sb          $a2, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r6;
L_8003BD1C:
    // 0x8003BD1C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
L_8003BD20:
    // 0x8003BD20: addiu       $t3, $v0, 0xA
    ctx->r11 = ADD32(ctx->r2, 0XA);
    // 0x8003BD24: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003BD28: beq         $at, $zero, L_8003BD34
    if (ctx->r1 == 0) {
        // 0x8003BD2C: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_8003BD34;
    }
    // 0x8003BD2C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8003BD30: sb          $t9, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r25;
L_8003BD34:
    // 0x8003BD34: lbu         $t4, 0xF($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XF);
    // 0x8003BD38: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003BD3C: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8003BD40: beq         $t5, $zero, L_8003BEBC
    if (ctx->r13 == 0) {
        // 0x8003BD44: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003BEBC;
    }
    // 0x8003BD44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BD48: beq         $t6, $zero, L_8003BE18
    if (ctx->r14 == 0) {
        // 0x8003BD4C: nop
    
            goto L_8003BE18;
    }
    // 0x8003BD4C: nop

    // 0x8003BD50: lbu         $t7, 0x0($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X0);
    // 0x8003BD54: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8003BD58: bne         $t7, $at, L_8003BE18
    if (ctx->r15 != ctx->r1) {
        // 0x8003BD5C: nop
    
            goto L_8003BE18;
    }
    // 0x8003BD5C: nop

    // 0x8003BD60: lb          $t3, 0x14($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X14);
    // 0x8003BD64: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x8003BD68: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8003BD6C: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x8003BD70: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8003BD74: nop

    // 0x8003BD78: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x8003BD7C: beq         $t5, $zero, L_8003BE0C
    if (ctx->r13 == 0) {
        // 0x8003BD80: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_8003BE0C;
    }
    // 0x8003BD80: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x8003BD84: lbu         $v0, 0x48($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BD88: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003BD8C: beq         $v0, $at, L_8003BDA8
    if (ctx->r2 == ctx->r1) {
        // 0x8003BD90: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003BDA8;
    }
    // 0x8003BD90: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003BD94: lhu         $t6, 0xC($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0XC);
    // 0x8003BD98: sllv        $t3, $t7, $v0
    ctx->r11 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x8003BD9C: and         $t8, $t6, $t3
    ctx->r24 = ctx->r14 & ctx->r11;
    // 0x8003BDA0: beq         $t8, $zero, L_8003BDEC
    if (ctx->r24 == 0) {
        // 0x8003BDA4: nop
    
            goto L_8003BDEC;
    }
    // 0x8003BDA4: nop

L_8003BDA8:
    // 0x8003BDA8: lbu         $t9, 0x15($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X15);
    // 0x8003BDAC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003BDB0: andi        $t4, $t9, 0xFF
    ctx->r12 = ctx->r25 & 0XFF;
    // 0x8003BDB4: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x8003BDB8: bne         $at, $zero, L_8003BDCC
    if (ctx->r1 != 0) {
        // 0x8003BDBC: sb          $t9, 0x10($t0)
        MEM_B(0X10, ctx->r8) = ctx->r25;
            goto L_8003BDCC;
    }
    // 0x8003BDBC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003BDC0: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8003BDC4: b           L_8003BDD0
    // 0x8003BDC8: sb          $t5, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r13;
        goto L_8003BDD0;
    // 0x8003BDC8: sb          $t5, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r13;
L_8003BDCC:
    // 0x8003BDCC: sb          $t7, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r15;
L_8003BDD0:
    // 0x8003BDD0: lb          $t3, 0x14($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X14);
    // 0x8003BDD4: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x8003BDD8: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8003BDDC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8003BDE0: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8003BDE4: b           L_8003BE0C
    // 0x8003BDE8: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
        goto L_8003BE0C;
    // 0x8003BDE8: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
L_8003BDEC:
    // 0x8003BDEC: sb          $zero, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = 0;
    // 0x8003BDF0: lb          $t5, 0x14($t2)
    ctx->r13 = MEM_B(ctx->r10, 0X14);
    // 0x8003BDF4: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x8003BDF8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8003BDFC: addu        $t3, $t4, $t7
    ctx->r11 = ADD32(ctx->r12, ctx->r15);
    // 0x8003BE00: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8003BE04: nop

    // 0x8003BE08: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
L_8003BE0C:
    // 0x8003BE0C: beq         $t6, $zero, L_8003BE18
    if (ctx->r14 == 0) {
        // 0x8003BE10: nop
    
            goto L_8003BE18;
    }
    // 0x8003BE10: nop

    // 0x8003BE14: sb          $a2, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r6;
L_8003BE18:
    // 0x8003BE18: lb          $v1, 0x15($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X15);
    // 0x8003BE1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BE20: bne         $a2, $v1, L_8003BE78
    if (ctx->r6 != ctx->r3) {
        // 0x8003BE24: nop
    
            goto L_8003BE78;
    }
    // 0x8003BE24: nop

    // 0x8003BE28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003BE2C: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003BE30: lwc1        $f7, 0x6170($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6170);
    // 0x8003BE34: lwc1        $f6, 0x6174($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6174);
    // 0x8003BE38: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003BE3C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8003BE40: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8003BE44: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003BE48: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x8003BE4C: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8003BE50: nop

    // 0x8003BE54: bc1f        L_8003BFE8
    if (!c1cs) {
        // 0x8003BE58: nop
    
            goto L_8003BFE8;
    }
    // 0x8003BE58: nop

    // 0x8003BE5C: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8003BE60: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x8003BE64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003BE68: add.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f2.d + ctx->f16.d;
    // 0x8003BE6C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8003BE70: b           L_8003BFE8
    // 0x8003BE74: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
        goto L_8003BFE8;
    // 0x8003BE74: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8003BE78:
    // 0x8003BE78: bne         $v1, $at, L_8003BFE8
    if (ctx->r3 != ctx->r1) {
        // 0x8003BE7C: nop
    
            goto L_8003BFE8;
    }
    // 0x8003BE7C: nop

    // 0x8003BE80: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003BE84: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003BE88: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003BE8C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8003BE90: nop

    // 0x8003BE94: bc1f        L_8003BFE8
    if (!c1cs) {
        // 0x8003BE98: nop
    
            goto L_8003BFE8;
    }
    // 0x8003BE98: nop

    // 0x8003BE9C: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8003BEA0: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x8003BEA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003BEA8: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8003BEAC: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8003BEB0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8003BEB4: b           L_8003BFE8
    // 0x8003BEB8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
        goto L_8003BFE8;
    // 0x8003BEB8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8003BEBC:
    // 0x8003BEBC: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x8003BEC0: addiu       $at, $zero, 0xD7
    ctx->r1 = ADD32(0, 0XD7);
    // 0x8003BEC4: bne         $t8, $at, L_8003BF5C
    if (ctx->r24 != ctx->r1) {
        // 0x8003BEC8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8003BF5C;
    }
    // 0x8003BEC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003BECC: sb          $zero, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = 0;
    // 0x8003BED0: lbu         $a0, 0x48($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BED4: lhu         $v1, 0xC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XC);
    // 0x8003BED8: sllv        $t5, $t9, $a0
    ctx->r13 = S32(ctx->r25 << (ctx->r4 & 31));
    // 0x8003BEDC: and         $t4, $v1, $t5
    ctx->r12 = ctx->r3 & ctx->r13;
    // 0x8003BEE0: beq         $t4, $zero, L_8003BF14
    if (ctx->r12 == 0) {
        // 0x8003BEE4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8003BF14;
    }
    // 0x8003BEE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8003BEE8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8003BEEC: sll         $t3, $a0, 1
    ctx->r11 = S32(ctx->r4 << 1);
    // 0x8003BEF0: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x8003BEF4: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8003BEF8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003BEFC: bne         $t8, $at, L_8003BF18
    if (ctx->r24 != ctx->r1) {
        // 0x8003BF00: addiu       $t9, $v0, 0x6
        ctx->r25 = ADD32(ctx->r2, 0X6);
            goto L_8003BF18;
    }
    // 0x8003BF00: addiu       $t9, $v0, 0x6
    ctx->r25 = ADD32(ctx->r2, 0X6);
    // 0x8003BF04: sb          $a2, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r6;
    // 0x8003BF08: lhu         $v1, 0xC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XC);
    // 0x8003BF0C: lbu         $v0, 0x48($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BF10: nop

L_8003BF14:
    // 0x8003BF14: addiu       $t9, $v0, 0x6
    ctx->r25 = ADD32(ctx->r2, 0X6);
L_8003BF18:
    // 0x8003BF18: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003BF1C: sllv        $t4, $t5, $t9
    ctx->r12 = S32(ctx->r13 << (ctx->r25 & 31));
    // 0x8003BF20: and         $t7, $v1, $t4
    ctx->r15 = ctx->r3 & ctx->r12;
    // 0x8003BF24: beq         $t7, $zero, L_8003BF3C
    if (ctx->r15 == 0) {
        // 0x8003BF28: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8003BF3C;
    }
    // 0x8003BF28: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003BF2C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003BF30: sb          $t3, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r11;
    // 0x8003BF34: lbu         $v0, 0x48($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BF38: nop

L_8003BF3C:
    // 0x8003BF3C: bne         $v0, $at, L_8003BF5C
    if (ctx->r2 != ctx->r1) {
        // 0x8003BF40: nop
    
            goto L_8003BF5C;
    }
    // 0x8003BF40: nop

    // 0x8003BF44: lb          $v0, 0x3A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X3A);
    // 0x8003BF48: nop

    // 0x8003BF4C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8003BF50: beq         $at, $zero, L_8003BF5C
    if (ctx->r1 == 0) {
        // 0x8003BF54: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8003BF5C;
    }
    // 0x8003BF54: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8003BF58: sb          $t6, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r14;
L_8003BF5C:
    // 0x8003BF5C: lb          $v1, 0x15($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X15);
    // 0x8003BF60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003BF64: bne         $a2, $v1, L_8003BF88
    if (ctx->r6 != ctx->r3) {
        // 0x8003BF68: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8003BF88;
    }
    // 0x8003BF68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BF6C: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8003BF70: lw          $t5, 0x7C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X7C);
    // 0x8003BF74: nop

    // 0x8003BF78: subu        $v0, $t8, $t5
    ctx->r2 = SUB32(ctx->r24, ctx->r13);
    // 0x8003BF7C: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8003BF80: b           L_8003BFA8
    // 0x8003BF84: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
        goto L_8003BFA8;
    // 0x8003BF84: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
L_8003BF88:
    // 0x8003BF88: bne         $v1, $at, L_8003BFAC
    if (ctx->r3 != ctx->r1) {
        // 0x8003BF8C: sra         $t5, $v0, 3
        ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8003BFAC;
    }
    // 0x8003BF8C: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8003BF90: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8003BF94: lw          $t3, 0x78($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X78);
    // 0x8003BF98: nop

    // 0x8003BF9C: subu        $v0, $t7, $t3
    ctx->r2 = SUB32(ctx->r15, ctx->r11);
    // 0x8003BFA0: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8003BFA4: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
L_8003BFA8:
    // 0x8003BFA8: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
L_8003BFAC:
    // 0x8003BFAC: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8003BFB0: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8003BFB4: slti        $at, $v0, 0x201
    ctx->r1 = SIGNED(ctx->r2) < 0X201 ? 1 : 0;
    // 0x8003BFB8: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8003BFBC: bne         $at, $zero, L_8003BFCC
    if (ctx->r1 != 0) {
        // 0x8003BFC0: slti        $at, $v0, -0x200
        ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
            goto L_8003BFCC;
    }
    // 0x8003BFC0: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
    // 0x8003BFC4: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8003BFC8: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
L_8003BFCC:
    // 0x8003BFCC: beq         $at, $zero, L_8003BFDC
    if (ctx->r1 == 0) {
        // 0x8003BFD0: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_8003BFDC;
    }
    // 0x8003BFD0: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x8003BFD4: addiu       $v0, $zero, -0x200
    ctx->r2 = ADD32(0, -0X200);
    // 0x8003BFD8: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
L_8003BFDC:
    // 0x8003BFDC: beq         $v0, $zero, L_8003BFE8
    if (ctx->r2 == 0) {
        // 0x8003BFE0: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_8003BFE8;
    }
    // 0x8003BFE0: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8003BFE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8003BFE8:
    // 0x8003BFE8: beq         $a1, $zero, L_8003C038
    if (ctx->r5 == 0) {
        // 0x8003BFEC: nop
    
            goto L_8003C038;
    }
    // 0x8003BFEC: nop

    // 0x8003BFF0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8003BFF4: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    // 0x8003BFF8: bne         $t3, $zero, L_8003C068
    if (ctx->r11 != 0) {
        // 0x8003BFFC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8003C068;
    }
    // 0x8003BFFC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003C000: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003C004: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003C008: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003C00C: addiu       $t8, $t0, 0x4
    ctx->r24 = ADD32(ctx->r8, 0X4);
    // 0x8003C010: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003C014: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8003C018: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003C01C: jal         0x80009558
    // 0x8003C020: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_14;
    // 0x8003C020: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_14:
    // 0x8003C024: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003C028: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003C02C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003C030: b           L_8003C06C
    // 0x8003C034: lb          $v0, 0x14($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X14);
        goto L_8003C06C;
    // 0x8003C034: lb          $v0, 0x14($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X14);
L_8003C038:
    // 0x8003C038: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x8003C03C: sb          $zero, 0x15($t0)
    MEM_B(0X15, ctx->r8) = 0;
    // 0x8003C040: beq         $v0, $zero, L_8003C068
    if (ctx->r2 == 0) {
        // 0x8003C044: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003C068;
    }
    // 0x8003C044: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003C048: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003C04C: jal         0x800096F8
    // 0x8003C050: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    audspat_point_stop(rdram, ctx);
        goto after_15;
    // 0x8003C050: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_15:
    // 0x8003C054: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003C058: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003C05C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8003C060: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003C064: nop

L_8003C068:
    // 0x8003C068: lb          $v0, 0x14($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X14);
L_8003C06C:
    // 0x8003C06C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003C070: bltz        $v0, L_8003C0B4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8003C074: nop
    
            goto L_8003C0B4;
    }
    // 0x8003C074: nop

    // 0x8003C078: lhu         $t9, 0x8($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X8);
    // 0x8003C07C: sllv        $a0, $t5, $v0
    ctx->r4 = S32(ctx->r13 << (ctx->r2 & 31));
    // 0x8003C080: and         $t4, $t9, $a0
    ctx->r12 = ctx->r25 & ctx->r4;
    // 0x8003C084: beq         $t4, $zero, L_8003C194
    if (ctx->r12 == 0) {
        // 0x8003C088: nop
    
            goto L_8003C194;
    }
    // 0x8003C088: nop

    // 0x8003C08C: lbu         $t3, 0x49($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C090: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8003C094: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8003C098: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x8003C09C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003C0A0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003C0A4: nop

    // 0x8003C0A8: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x8003C0AC: b           L_8003C194
    // 0x8003C0B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_8003C194;
    // 0x8003C0B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8003C0B4:
    // 0x8003C0B4: lb          $t4, 0x13($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X13);
    // 0x8003C0B8: lw          $v1, 0x4($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X4);
    // 0x8003C0BC: bne         $t4, $zero, L_8003C128
    if (ctx->r12 != 0) {
        // 0x8003C0C0: nop
    
            goto L_8003C128;
    }
    // 0x8003C0C0: nop

    // 0x8003C0C4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8003C0C8: lbu         $t6, 0x10($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X10);
    // 0x8003C0CC: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x8003C0D0: nop

    // 0x8003C0D4: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003C0D8: bne         $at, $zero, L_8003C104
    if (ctx->r1 != 0) {
        // 0x8003C0DC: nop
    
            goto L_8003C104;
    }
    // 0x8003C0DC: nop

    // 0x8003C0E0: lbu         $t8, 0x49($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C0E4: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8003C0E8: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8003C0EC: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x8003C0F0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003C0F4: nop

    // 0x8003C0F8: or          $t3, $t9, $t4
    ctx->r11 = ctx->r25 | ctx->r12;
    // 0x8003C0FC: b           L_8003C194
    // 0x8003C100: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8003C194;
    // 0x8003C100: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8003C104:
    // 0x8003C104: lbu         $t7, 0x49($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C108: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003C10C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8003C110: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x8003C114: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003C118: nor         $t9, $t5, $zero
    ctx->r25 = ~(ctx->r13 | 0);
    // 0x8003C11C: and         $t4, $t8, $t9
    ctx->r12 = ctx->r24 & ctx->r25;
    // 0x8003C120: b           L_8003C194
    // 0x8003C124: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8003C194;
    // 0x8003C124: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8003C128:
    // 0x8003C128: lbu         $t7, 0x48($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X48);
    // 0x8003C12C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8003C130: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8003C134: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8003C138: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x8003C13C: lbu         $t9, 0x10($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X10);
    // 0x8003C140: nop

    // 0x8003C144: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003C148: bne         $at, $zero, L_8003C174
    if (ctx->r1 != 0) {
        // 0x8003C14C: nop
    
            goto L_8003C174;
    }
    // 0x8003C14C: nop

    // 0x8003C150: lbu         $t4, 0x49($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C154: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8003C158: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8003C15C: addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
    // 0x8003C160: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8003C164: nop

    // 0x8003C168: or          $t5, $t3, $t6
    ctx->r13 = ctx->r11 | ctx->r14;
    // 0x8003C16C: b           L_8003C194
    // 0x8003C170: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8003C194;
    // 0x8003C170: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8003C174:
    // 0x8003C174: lbu         $t8, 0x49($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C178: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8003C17C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003C180: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x8003C184: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8003C188: nor         $t3, $t7, $zero
    ctx->r11 = ~(ctx->r15 | 0);
    // 0x8003C18C: and         $t6, $t4, $t3
    ctx->r14 = ctx->r12 & ctx->r11;
    // 0x8003C190: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8003C194:
    // 0x8003C194: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C198: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8003C19C: sb          $t5, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r13;
    // 0x8003C1A0: lw          $t9, 0x4C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C1A4: nop

    // 0x8003C1A8: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8003C1AC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C1B0: nop

    // 0x8003C1B4: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    // 0x8003C1B8: nop

    // 0x8003C1BC: andi        $t4, $t7, 0xFFF7
    ctx->r12 = ctx->r15 & 0XFFF7;
    // 0x8003C1C0: sh          $t4, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r12;
    // 0x8003C1C4: lw          $t3, 0x5C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X5C);
    // 0x8003C1C8: nop

    // 0x8003C1CC: sw          $zero, 0x100($t3)
    MEM_W(0X100, ctx->r11) = 0;
    // 0x8003C1D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003C1D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003C1D8: jr          $ra
    // 0x8003C1DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8003C1DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void weather_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB35C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB360: lw          $a0, 0x290C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X290C);
    // 0x800AB364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AB368: beq         $a0, $zero, L_800AB380
    if (ctx->r4 == 0) {
        // 0x800AB36C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AB380;
    }
    // 0x800AB36C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AB370: jal         0x80071140
    // 0x800AB374: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AB374: nop

    after_0:
    // 0x800AB378: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB37C: sw          $zero, 0x290C($at)
    MEM_W(0X290C, ctx->r1) = 0;
L_800AB380:
    // 0x800AB380: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB384: addiu       $v0, $v0, 0x2914
    ctx->r2 = ADD32(ctx->r2, 0X2914);
    // 0x800AB388: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800AB38C: nop

    // 0x800AB390: beq         $a0, $zero, L_800AB3AC
    if (ctx->r4 == 0) {
        // 0x800AB394: nop
    
            goto L_800AB3AC;
    }
    // 0x800AB394: nop

    // 0x800AB398: jal         0x80071140
    // 0x800AB39C: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AB39C: nop

    after_1:
    // 0x800AB3A0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB3A4: addiu       $v0, $v0, 0x2914
    ctx->r2 = ADD32(ctx->r2, 0X2914);
    // 0x800AB3A8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800AB3AC:
    // 0x800AB3AC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800AB3B0: nop

    // 0x800AB3B4: beq         $a0, $zero, L_800AB3D0
    if (ctx->r4 == 0) {
        // 0x800AB3B8: nop
    
            goto L_800AB3D0;
    }
    // 0x800AB3B8: nop

    // 0x800AB3BC: jal         0x80071140
    // 0x800AB3C0: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800AB3C0: nop

    after_2:
    // 0x800AB3C4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB3C8: addiu       $v0, $v0, 0x2914
    ctx->r2 = ADD32(ctx->r2, 0X2914);
    // 0x800AB3CC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_800AB3D0:
    // 0x800AB3D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB3D4: lw          $a0, 0x28D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28D4);
    // 0x800AB3D8: nop

    // 0x800AB3DC: beq         $a0, $zero, L_800AB3F4
    if (ctx->r4 == 0) {
        // 0x800AB3E0: nop
    
            goto L_800AB3F4;
    }
    // 0x800AB3E0: nop

    // 0x800AB3E4: jal         0x80071140
    // 0x800AB3E8: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800AB3E8: nop

    after_3:
    // 0x800AB3EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB3F0: sw          $zero, 0x28D4($at)
    MEM_W(0X28D4, ctx->r1) = 0;
L_800AB3F4:
    // 0x800AB3F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB3F8: addiu       $v0, $v0, 0x28D8
    ctx->r2 = ADD32(ctx->r2, 0X28D8);
    // 0x800AB3FC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800AB400: nop

    // 0x800AB404: beq         $a0, $zero, L_800AB420
    if (ctx->r4 == 0) {
        // 0x800AB408: nop
    
            goto L_800AB420;
    }
    // 0x800AB408: nop

    // 0x800AB40C: jal         0x80071140
    // 0x800AB410: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800AB410: nop

    after_4:
    // 0x800AB414: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB418: addiu       $v0, $v0, 0x28D8
    ctx->r2 = ADD32(ctx->r2, 0X28D8);
    // 0x800AB41C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800AB420:
    // 0x800AB420: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x800AB424: nop

    // 0x800AB428: beq         $a0, $zero, L_800AB444
    if (ctx->r4 == 0) {
        // 0x800AB42C: nop
    
            goto L_800AB444;
    }
    // 0x800AB42C: nop

    // 0x800AB430: jal         0x8007B2BC
    // 0x800AB434: nop

    tex_free(rdram, ctx);
        goto after_5;
    // 0x800AB434: nop

    after_5:
    // 0x800AB438: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB43C: addiu       $v0, $v0, 0x28D8
    ctx->r2 = ADD32(ctx->r2, 0X28D8);
    // 0x800AB440: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
L_800AB444:
    // 0x800AB444: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB448: lw          $a0, 0x2910($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2910);
    // 0x800AB44C: nop

    // 0x800AB450: beq         $a0, $zero, L_800AB468
    if (ctx->r4 == 0) {
        // 0x800AB454: nop
    
            goto L_800AB468;
    }
    // 0x800AB454: nop

    // 0x800AB458: jal         0x80071140
    // 0x800AB45C: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800AB45C: nop

    after_6:
    // 0x800AB460: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB464: sw          $zero, 0x2910($at)
    MEM_W(0X2910, ctx->r1) = 0;
L_800AB468:
    // 0x800AB468: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB46C: sw          $zero, 0x2A88($at)
    MEM_W(0X2A88, ctx->r1) = 0;
    // 0x800AB470: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB474: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AB478: lw          $t7, 0x2C5C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2C5C);
    // 0x800AB47C: sw          $zero, 0x2A80($at)
    MEM_W(0X2A80, ctx->r1) = 0;
    // 0x800AB480: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB484: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AB488: beq         $t7, $zero, L_800AB498
    if (ctx->r15 == 0) {
        // 0x800AB48C: sw          $t6, 0x2A84($at)
        MEM_W(0X2A84, ctx->r1) = ctx->r14;
            goto L_800AB498;
    }
    // 0x800AB48C: sw          $t6, 0x2A84($at)
    MEM_W(0X2A84, ctx->r1) = ctx->r14;
    // 0x800AB490: jal         0x800AD220
    // 0x800AB494: nop

    free_rain_memory(rdram, ctx);
        goto after_7;
    // 0x800AB494: nop

    after_7:
L_800AB498:
    // 0x800AB498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AB49C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AB4A0: jr          $ra
    // 0x800AB4A4: nop

    return;
    // 0x800AB4A4: nop

;}
RECOMP_FUNC void mempool_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071140: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80071144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071148: jal         0x8006F510
    // 0x8007114C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x8007114C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80071150: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071154: lw          $t6, 0x3DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3DCC);
    // 0x80071158: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007115C: bne         $t6, $zero, L_80071174
    if (ctx->r14 != 0) {
        // 0x80071160: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80071174;
    }
    // 0x80071160: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80071164: jal         0x80071278
    // 0x80071168: nop

    mempool_free_addr(rdram, ctx);
        goto after_1;
    // 0x80071168: nop

    after_1:
    // 0x8007116C: b           L_80071180
    // 0x80071170: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_80071180;
    // 0x80071170: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80071174:
    // 0x80071174: jal         0x80071440
    // 0x80071178: nop

    mempool_free_queue(rdram, ctx);
        goto after_2;
    // 0x80071178: nop

    after_2:
    // 0x8007117C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80071180:
    // 0x80071180: jal         0x8006F53C
    // 0x80071184: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80071184: nop

    after_3:
    // 0x80071188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007118C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80071190: jr          $ra
    // 0x80071194: nop

    return;
    // 0x80071194: nop

;}
RECOMP_FUNC void hud_eggs_portrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A19A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A19A8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A19AC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A19B0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A19B4: addiu       $s2, $s2, 0x6CDC
    ctx->r18 = ADD32(ctx->r18, 0X6CDC);
    // 0x800A19B8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A19BC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A19C0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A19C4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800A19C8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800A19CC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A19D0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A19D4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A19D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A19DC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A19E0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A19E4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800A19E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A19EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A19F0: lwc1        $f4, 0x66C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A19F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A19F8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A19FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A1A00: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A1A04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A1A08: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x800A1A0C: lb          $t8, 0x3($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X3);
    // 0x800A1A10: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A1A14: addiu       $t9, $t8, 0x38
    ctx->r25 = ADD32(ctx->r24, 0X38);
    // 0x800A1A18: sh          $t9, 0x646($v0)
    MEM_H(0X646, ctx->r2) = ctx->r25;
    // 0x800A1A1C: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x800A1A20: sb          $t0, 0x6CD5($at)
    MEM_B(0X6CD5, ctx->r1) = ctx->r8;
    // 0x800A1A24: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A1A28: bne         $at, $zero, L_800A1A4C
    if (ctx->r1 != 0) {
        // 0x800A1A2C: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_800A1A4C;
    }
    // 0x800A1A2C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800A1A30: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800A1A34: bne         $s1, $v1, L_800A1A74
    if (ctx->r17 != ctx->r3) {
        // 0x800A1A38: nop
    
            goto L_800A1A74;
    }
    // 0x800A1A38: nop

    // 0x800A1A3C: lh          $t1, 0x0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X0);
    // 0x800A1A40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A1A44: bne         $t1, $at, L_800A1A74
    if (ctx->r9 != ctx->r1) {
        // 0x800A1A48: nop
    
            goto L_800A1A74;
    }
    // 0x800A1A48: nop

L_800A1A4C:
    // 0x800A1A4C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A1A50: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A1A54: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A1A58: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800A1A5C: addiu       $a2, $s6, 0x6D04
    ctx->r6 = ADD32(ctx->r22, 0X6D04);
    // 0x800A1A60: addiu       $a1, $s5, 0x6D00
    ctx->r5 = ADD32(ctx->r21, 0X6D00);
    // 0x800A1A64: addiu       $a0, $s4, 0x6CFC
    ctx->r4 = ADD32(ctx->r20, 0X6CFC);
    // 0x800A1A68: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    { extern void dkr_legacy_character_hud_bind(uint8_t*, recomp_context*, uint32_t, uint32_t); dkr_legacy_character_hud_bind(rdram, ctx, (uint32_t)ctx->r7 + 1600U, (uint32_t)(ctx->r19)); }
    // 0x800A1A6C: jal         0x800AA600
    // 0x800A1A70: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A1A70: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_0:
L_800A1A74:
    { extern void dkr_legacy_character_hud_unbind(uint8_t*, recomp_context*); dkr_legacy_character_hud_unbind(rdram, ctx); }
    // 0x800A1A74: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A1A78: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A1A7C: lb          $v0, 0x67A($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X67A);
    // 0x800A1A80: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A1A84: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800A1A88: addiu       $s6, $s6, 0x6D04
    ctx->r22 = ADD32(ctx->r22, 0X6D04);
    // 0x800A1A8C: addiu       $s5, $s5, 0x6D00
    ctx->r21 = ADD32(ctx->r21, 0X6D00);
    // 0x800A1A90: bgez        $v0, L_800A1AA8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A1A94: addiu       $s4, $s4, 0x6CFC
        ctx->r20 = ADD32(ctx->r20, 0X6CFC);
            goto L_800A1AA8;
    }
    // 0x800A1A94: addiu       $s4, $s4, 0x6CFC
    ctx->r20 = ADD32(ctx->r20, 0X6CFC);
    // 0x800A1A98: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x800A1A9C: addiu       $t4, $t3, 0x100
    ctx->r12 = ADD32(ctx->r11, 0X100);
    // 0x800A1AA0: b           L_800A1AB8
    // 0x800A1AA4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_800A1AB8;
    // 0x800A1AA4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800A1AA8:
    // 0x800A1AA8: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x800A1AAC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A1AB0: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x800A1AB4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800A1AB8:
    // 0x800A1AB8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800A1ABC: addiu       $t9, $zero, 0xFE
    ctx->r25 = ADD32(0, 0XFE);
    // 0x800A1AC0: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x800A1AC4: bne         $at, $zero, L_800A1AD0
    if (ctx->r1 != 0) {
        // 0x800A1AC8: nop
    
            goto L_800A1AD0;
    }
    // 0x800A1AC8: nop

    // 0x800A1ACC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800A1AD0:
    // 0x800A1AD0: lb          $t0, 0x193($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X193);
    // 0x800A1AD4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A1AD8: blez        $t0, L_800A1B34
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800A1ADC: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_800A1B34;
    }
    // 0x800A1ADC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800A1AE0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A1AE4: nop

L_800A1AE8:
    // 0x800A1AE8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A1AEC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A1AF0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800A1AF4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800A1AF8: jal         0x800AA600
    // 0x800A1AFC: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A1AFC: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    after_1:
    // 0x800A1B00: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1B04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A1B08: lwc1        $f8, 0x66C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A1B0C: nop

    // 0x800A1B10: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A1B14: swc1        $f10, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f10.u32l;
    // 0x800A1B18: lb          $t1, 0x193($s3)
    ctx->r9 = MEM_B(ctx->r19, 0X193);
    // 0x800A1B1C: nop

    // 0x800A1B20: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A1B24: beq         $at, $zero, L_800A1B38
    if (ctx->r1 == 0) {
        // 0x800A1B28: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_800A1B38;
    }
    // 0x800A1B28: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800A1B2C: bne         $s0, $s1, L_800A1AE8
    if (ctx->r16 != ctx->r17) {
        // 0x800A1B30: nop
    
            goto L_800A1AE8;
    }
    // 0x800A1B30: nop

L_800A1B34:
    // 0x800A1B34: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
L_800A1B38:
    // 0x800A1B38: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800A1B3C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A1B40: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800A1B44: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800A1B48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A1B4C: sw          $t3, 0x2834($at)
    MEM_W(0X2834, ctx->r1) = ctx->r11;
    // 0x800A1B50: lb          $t4, 0x1CF($s3)
    ctx->r12 = MEM_B(ctx->r19, 0X1CF);
    // 0x800A1B54: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800A1B58: blez        $t4, L_800A1BB8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A1B5C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800A1BB8;
    }
    // 0x800A1B5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A1B60: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800A1B64: beq         $at, $zero, L_800A1BBC
    if (ctx->r1 == 0) {
        // 0x800A1B68: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_800A1BBC;
    }
    // 0x800A1B68: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_800A1B6C:
    // 0x800A1B6C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A1B70: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A1B74: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800A1B78: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800A1B7C: jal         0x800AA600
    // 0x800A1B80: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A1B80: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    after_2:
    // 0x800A1B84: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1B88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A1B8C: lwc1        $f16, 0x66C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A1B90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A1B94: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x800A1B98: swc1        $f18, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f18.u32l;
    // 0x800A1B9C: lb          $t6, 0x1CF($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X1CF);
    // 0x800A1BA0: nop

    // 0x800A1BA4: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800A1BA8: beq         $at, $zero, L_800A1BB8
    if (ctx->r1 == 0) {
        // 0x800A1BAC: slti        $at, $s1, 0x3
        ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
            goto L_800A1BB8;
    }
    // 0x800A1BAC: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800A1BB0: bne         $at, $zero, L_800A1B6C
    if (ctx->r1 != 0) {
        // 0x800A1BB4: nop
    
            goto L_800A1B6C;
    }
    // 0x800A1BB4: nop

L_800A1BB8:
    // 0x800A1BB8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_800A1BBC:
    // 0x800A1BBC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A1BC0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800A1BC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A1BC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A1BCC: swc1        $f6, 0x66C($t7)
    MEM_W(0X66C, ctx->r15) = ctx->f6.u32l;
    // 0x800A1BD0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1BD4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800A1BD8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800A1BDC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A1BE0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1BE4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A1BE8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A1BEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A1BF0: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A1BF4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A1BF8: sb          $zero, 0x6CD5($at)
    MEM_B(0X6CD5, ctx->r1) = 0;
    // 0x800A1BFC: jr          $ra
    // 0x800A1C00: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A1C00: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void cam_get_active_camera_no_cutscenes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069CFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069D00: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x80069D04: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069D08: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80069D0C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80069D10: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069D14: addiu       $t8, $t8, 0xAC0
    ctx->r24 = ADD32(ctx->r24, 0XAC0);
    // 0x80069D18: jr          $ra
    // 0x80069D1C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x80069D1C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void reset_particles_with_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE2A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE2A8: jal         0x800AE374
    // 0x800AE2AC: nop

    free_particle_buffers(rdram, ctx);
        goto after_0;
    // 0x800AE2AC: nop

    after_0:
    // 0x800AE2B0: jal         0x800AE438
    // 0x800AE2B4: nop

    free_particle_vertices_triangles(rdram, ctx);
        goto after_1;
    // 0x800AE2B4: nop

    after_1:
    // 0x800AE2B8: jal         0x800AE490
    // 0x800AE2BC: nop

    free_particle_assets(rdram, ctx);
        goto after_2;
    // 0x800AE2BC: nop

    after_2:
    // 0x800AE2C0: jal         0x800AE2D8
    // 0x800AE2C4: nop

    particle_free_dummy(rdram, ctx);
        goto after_3;
    // 0x800AE2C4: nop

    after_3:
    // 0x800AE2C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE2CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE2D0: jr          $ra
    // 0x800AE2D4: nop

    return;
    // 0x800AE2D4: nop

;}
