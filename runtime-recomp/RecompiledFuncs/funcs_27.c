#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void obj_init_rangetrigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004216C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80042170: jr          $ra
    // 0x80042174: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80042174: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void sndp_set_group_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004A60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80004A64: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80004A68: andi        $s2, $a0, 0xFF
    ctx->r18 = ctx->r4 & 0XFF;
    // 0x80004A6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80004A70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80004A74: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80004A78: andi        $s1, $a1, 0xFFFF
    ctx->r17 = ctx->r5 & 0XFFFF;
    // 0x80004A7C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80004A80: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80004A84: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80004A88: jal         0x800C9A30
    // 0x80004A8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80004A8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80004A90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80004A94: lw          $t6, -0x63D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X63D8);
    // 0x80004A98: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80004A9C: lw          $s0, -0x3950($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X3950);
    // 0x80004AA0: sll         $t7, $s2, 1
    ctx->r15 = S32(ctx->r18 << 1);
    // 0x80004AA4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80004AA8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80004AAC: beq         $s0, $zero, L_80004B0C
    if (ctx->r16 == 0) {
        // 0x80004AB0: sh          $s1, 0x0($t8)
        MEM_H(0X0, ctx->r24) = ctx->r17;
            goto L_80004B0C;
    }
    // 0x80004AB0: sh          $s1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r17;
    // 0x80004AB4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80004AB8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80004ABC: addiu       $s2, $s2, -0x3944
    ctx->r18 = ADD32(ctx->r18, -0X3944);
    // 0x80004AC0: addiu       $s3, $sp, 0x2C
    ctx->r19 = ADD32(ctx->r29, 0X2C);
L_80004AC4:
    // 0x80004AC4: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80004AC8: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x80004ACC: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80004AD0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80004AD4: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80004AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004ADC: andi        $t2, $t1, 0x3F
    ctx->r10 = ctx->r9 & 0X3F;
    // 0x80004AE0: bne         $s1, $t2, L_80004AFC
    if (ctx->r17 != ctx->r10) {
        // 0x80004AE4: nop
    
            goto L_80004AFC;
    }
    // 0x80004AE4: nop

    // 0x80004AE8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80004AEC: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
    // 0x80004AF0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80004AF4: jal         0x800C91AC
    // 0x80004AF8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80004AF8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
L_80004AFC:
    // 0x80004AFC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80004B00: nop

    // 0x80004B04: bne         $s0, $zero, L_80004AC4
    if (ctx->r16 != 0) {
        // 0x80004B08: nop
    
            goto L_80004AC4;
    }
    // 0x80004B08: nop

L_80004B0C:
    // 0x80004B0C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80004B10: jal         0x800C9A30
    // 0x80004B14: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80004B14: nop

    after_2:
    // 0x80004B18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80004B1C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80004B20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80004B24: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80004B28: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80004B2C: jr          $ra
    // 0x80004B30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80004B30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void asset_table_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_asset_api(uint8_t*, recomp_context*, unsigned); if (dkr_legacy_asset_api(rdram, ctx, 0U)) return; extern void dkr_custom_tracks_table_load_begin(uint8_t*, recomp_context*); dkr_custom_tracks_table_load_begin(rdram, ctx);
    // 0x80076C58: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80076C5C: lw          $v1, 0x4290($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4290);
    // 0x80076C60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80076C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076C68: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80076C6C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80076C70: sltu        $at, $t6, $a0
    ctx->r1 = ctx->r14 < ctx->r4 ? 1 : 0;
    // 0x80076C74: beq         $at, $zero, L_80076C84
    if (ctx->r1 == 0) {
        // 0x80076C78: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80076C84;
    }
    // 0x80076C78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80076C7C: b           L_80076CE0
    // 0x80076C80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076CE0;
    // 0x80076C80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076C84:
    // 0x80076C84: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80076C88: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80076C8C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80076C90: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80076C94: lui         $a1, 0x7F7F
    ctx->r5 = S32(0X7F7F << 16);
    // 0x80076C98: subu        $a0, $t8, $a3
    ctx->r4 = SUB32(ctx->r24, ctx->r7);
    // 0x80076C9C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80076CA0: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80076CA4: jal         0x80070C9C
    // 0x80076CA8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80076CA8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80076CAC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80076CB0: bne         $v0, $zero, L_80076CC0
    if (ctx->r2 != 0) {
        // 0x80076CB4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80076CC0;
    }
    // 0x80076CB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80076CB8: b           L_80076CE0
    // 0x80076CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076CE0;
    // 0x80076CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076CC0:
    // 0x80076CC0: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x80076CC4: addiu       $t9, $t9, -0x33D0
    ctx->r25 = ADD32(ctx->r25, -0X33D0);
    // 0x80076CC8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80076CCC: addu        $a0, $a3, $t9
    ctx->r4 = ADD32(ctx->r7, ctx->r25);
    // 0x80076CD0: jal         0x80076F78
    // 0x80076CD4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    dmacopy(rdram, ctx);
        goto after_1;
    // 0x80076CD4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x80076CD8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80076CDC: nop

L_80076CE0:
    extern void dkr_custom_tracks_table_load_end(uint8_t*, recomp_context*); dkr_custom_tracks_table_load_end(rdram, ctx);
    // 0x80076CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076CE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80076CE8: jr          $ra
    // 0x80076CEC: nop

    return;
    // 0x80076CEC: nop

;}
RECOMP_FUNC void sprintfSetSpacingCodes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4A08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B4A0C: jr          $ra
    // 0x800B4A10: sw          $a0, 0x2EF0($at)
    MEM_W(0X2EF0, ctx->r1) = ctx->r4;
    return;
    // 0x800B4A10: sw          $a0, 0x2EF0($at)
    MEM_W(0X2EF0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void light_setup_light_sources(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F758: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000F75C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F760: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000F764: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000F768: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000F76C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000F770: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F774: lw          $s0, 0x40($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X40);
    // 0x8000F778: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000F77C: lb          $t6, 0x5A($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F780: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F784: blez        $t6, L_8000F7CC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000F788: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000F7CC;
    }
    // 0x8000F788: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000F78C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8000F790:
    // 0x8000F790: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8000F794: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F798: jal         0x80031F88
    // 0x8000F79C: addu        $a1, $t7, $s3
    ctx->r5 = ADD32(ctx->r15, ctx->r19);
    light_add_from_object_header(rdram, ctx);
        goto after_0;
    // 0x8000F79C: addu        $a1, $t7, $s3
    ctx->r5 = ADD32(ctx->r15, ctx->r19);
    after_0:
    // 0x8000F7A0: lw          $t8, 0x70($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X70);
    // 0x8000F7A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F7A8: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x8000F7AC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8000F7B0: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F7B4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8000F7B8: lb          $t0, 0x5A($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F7BC: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // 0x8000F7C0: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000F7C4: bne         $at, $zero, L_8000F790
    if (ctx->r1 != 0) {
        // 0x8000F7C8: nop
    
            goto L_8000F790;
    }
    // 0x8000F7C8: nop

L_8000F7CC:
    // 0x8000F7CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F7D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000F7D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F7D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000F7DC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000F7E0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000F7E4: jr          $ra
    // 0x8000F7E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000F7E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void render_racer_shield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013A0C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80013A10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013A14: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80013A18: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80013A1C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80013A20: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80013A24: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80013A28: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80013A2C: lw          $t0, 0x64($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X64);
    // 0x80013A30: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80013A34: lh          $t7, 0x18E($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X18E);
    // 0x80013A38: addiu       $s0, $s0, -0x38A4
    ctx->r16 = ADD32(ctx->r16, -0X38A4);
    // 0x80013A3C: blez        $t7, L_80013DBC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80013A40: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80013DBC;
    }
    // 0x80013A40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013A44: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80013A48: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80013A4C: beq         $t8, $zero, L_80013DBC
    if (ctx->r24 == 0) {
        // 0x80013A50: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80013DBC;
    }
    // 0x80013A50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013A54: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80013A58: addiu       $s1, $s1, -0x5174
    ctx->r17 = ADD32(ctx->r17, -0X5174);
    // 0x80013A5C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80013A60: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80013A64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013A68: sw          $t3, -0x5170($at)
    MEM_W(-0X5170, ctx->r1) = ctx->r11;
    // 0x80013A6C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80013A70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013A74: sw          $t5, -0x516C($at)
    MEM_W(-0X516C, ctx->r1) = ctx->r13;
    // 0x80013A78: lb          $a2, 0x2($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X2);
    // 0x80013A7C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80013A80: slti        $at, $a2, 0xB
    ctx->r1 = SIGNED(ctx->r6) < 0XB ? 1 : 0;
    // 0x80013A84: bne         $at, $zero, L_80013A90
    if (ctx->r1 != 0) {
        // 0x80013A88: nop
    
            goto L_80013A90;
    }
    // 0x80013A88: nop

    // 0x80013A8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80013A90:
    // 0x80013A90: lb          $a1, 0x1D6($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X1D6);
    // 0x80013A94: nop

    // 0x80013A98: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80013A9C: bne         $at, $zero, L_80013AA8
    if (ctx->r1 != 0) {
        // 0x80013AA0: nop
    
            goto L_80013AA8;
    }
    // 0x80013AA0: nop

    // 0x80013AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80013AA8:
    // 0x80013AA8: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x80013AAC: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80013AB0: jal         0x8001E29C
    // 0x80013AB4: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013AB4: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_0:
    // 0x80013AB8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80013ABC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80013AC0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80013AC4: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80013AC8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80013ACC: addu        $a1, $t6, $a2
    ctx->r5 = ADD32(ctx->r14, ctx->r6);
    // 0x80013AD0: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x80013AD4: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x80013AD8: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80013ADC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80013AE0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80013AE4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80013AE8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80013AEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013AF0: addiu       $t5, $t5, -0x4FF0
    ctx->r13 = ADD32(ctx->r13, -0X4FF0);
    // 0x80013AF4: addu        $a3, $a2, $t5
    ctx->r7 = ADD32(ctx->r6, ctx->r13);
    // 0x80013AF8: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x80013AFC: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x80013B00: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80013B04: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80013B08: nop

    // 0x80013B0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80013B10: swc1        $f10, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f10.u32l;
    // 0x80013B14: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x80013B18: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80013B1C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80013B20: nop

    // 0x80013B24: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80013B28: swc1        $f18, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f18.u32l;
    // 0x80013B2C: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x80013B30: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80013B34: sll         $t7, $t6, 25
    ctx->r15 = S32(ctx->r14 << 25);
    // 0x80013B38: jal         0x800707C4
    // 0x80013B3C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80013B3C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80013B40: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80013B44: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013B48: lh          $t1, 0x6($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X6);
    // 0x80013B4C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80013B50: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80013B54: nop

    // 0x80013B58: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80013B5C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80013B60: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80013B64: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x80013B68: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80013B6C: nop

    // 0x80013B70: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80013B74: nop

    // 0x80013B78: sll         $t4, $t3, 26
    ctx->r12 = S32(ctx->r11 << 26);
    // 0x80013B7C: jal         0x800707F8
    // 0x80013B80: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80013B80: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_2:
    // 0x80013B84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013B88: lwc1        $f18, 0x556C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X556C);
    // 0x80013B8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013B90: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80013B94: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80013B98: lwc1        $f8, 0x5570($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5570);
    // 0x80013B9C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80013BA0: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80013BA4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80013BA8: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80013BAC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80013BB0: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x80013BB4: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
    // 0x80013BB8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80013BBC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80013BC0: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80013BC4: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80013BC8: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x80013BCC: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x80013BD0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80013BD4: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80013BD8: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
    // 0x80013BDC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80013BE0: nop

    // 0x80013BE4: sh          $zero, 0x4($t4)
    MEM_H(0X4, ctx->r12) = 0;
    // 0x80013BE8: lb          $a0, 0x189($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X189);
    // 0x80013BEC: nop

    // 0x80013BF0: beq         $a0, $zero, L_80013C00
    if (ctx->r4 == 0) {
        // 0x80013BF4: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80013C00;
    }
    // 0x80013BF4: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80013BF8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80013BFC: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_80013C00:
    // 0x80013C00: bne         $at, $zero, L_80013C0C
    if (ctx->r1 != 0) {
        // 0x80013C04: nop
    
            goto L_80013C0C;
    }
    // 0x80013C04: nop

    // 0x80013C08: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80013C0C:
    // 0x80013C0C: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80013C10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013C14: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80013C18: lwc1        $f5, 0x5578($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5578);
    // 0x80013C1C: lwc1        $f4, 0x557C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X557C);
    // 0x80013C20: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80013C24: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80013C28: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80013C2C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80013C30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80013C34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013C38: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80013C3C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80013C40: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x80013C44: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80013C48: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80013C4C: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x80013C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80013C54: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80013C58: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013C5C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80013C60: lw          $t5, 0x68($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X68);
    // 0x80013C64: nop

    // 0x80013C68: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80013C6C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80013C70: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80013C74: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80013C78: nop

    // 0x80013C7C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x80013C80: lb          $t9, 0x1F($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1F);
    // 0x80013C84: nop

    // 0x80013C88: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80013C8C: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x80013C90: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80013C94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80013C98: sw          $t3, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r11;
    // 0x80013C9C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013CA0: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x80013CA4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80013CA8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80013CAC: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80013CB0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80013CB4: lh          $t6, 0x18E($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X18E);
    // 0x80013CB8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80013CBC: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x80013CC0: beq         $at, $zero, L_80013CF8
    if (ctx->r1 == 0) {
        // 0x80013CC4: nop
    
            goto L_80013CF8;
    }
    // 0x80013CC4: nop

    // 0x80013CC8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013CCC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80013CD0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80013CD4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80013CD8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80013CDC: lh          $t9, 0x18E($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X18E);
    // 0x80013CE0: nop

    // 0x80013CE4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80013CE8: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80013CEC: or          $t3, $t2, $a3
    ctx->r11 = ctx->r10 | ctx->r7;
    // 0x80013CF0: b           L_80013D10
    // 0x80013CF4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
        goto L_80013D10;
    // 0x80013CF4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_80013CF8:
    // 0x80013CF8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013CFC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80013D00: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80013D04: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80013D08: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80013D0C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80013D10:
    // 0x80013D10: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80013D14: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80013D18: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x80013D1C: jal         0x80068FA8
    // 0x80013D20: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    mtx_shear_push(rdram, ctx);
        goto after_3;
    // 0x80013D20: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_3:
    // 0x80013D24: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80013D28: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80013D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013D30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80013D34: jal         0x800143A8
    // 0x80013D38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    render_mesh(rdram, ctx);
        goto after_4;
    // 0x80013D38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80013D3C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013D40: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80013D44: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80013D48: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80013D4C: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80013D50: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x80013D54: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80013D58: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80013D5C: lh          $t9, 0x18E($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X18E);
    // 0x80013D60: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80013D64: slti        $at, $t9, 0x40
    ctx->r1 = SIGNED(ctx->r25) < 0X40 ? 1 : 0;
    // 0x80013D68: beq         $at, $zero, L_80013D88
    if (ctx->r1 == 0) {
        // 0x80013D6C: nop
    
            goto L_80013D88;
    }
    // 0x80013D6C: nop

    // 0x80013D70: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80013D74: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80013D78: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80013D7C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80013D80: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80013D84: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80013D88:
    // 0x80013D88: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80013D8C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80013D90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80013D94: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80013D98: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80013D9C: lw          $t6, -0x5170($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5170);
    // 0x80013DA0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80013DA4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80013DA8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80013DAC: lw          $t8, -0x516C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X516C);
    // 0x80013DB0: nop

    // 0x80013DB4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80013DB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80013DBC:
    // 0x80013DBC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80013DC0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80013DC4: jr          $ra
    // 0x80013DC8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80013DC8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void fileselect_input_erase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DC7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008DC80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DC84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008DC88: jal         0x8006A554
    // 0x8008DC8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008DC8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8008DC90: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008DC94: lw          $t6, -0xB44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB44);
    // 0x8008DC98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008DC9C: lb          $a1, 0x645C($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X645C);
    // 0x8008DCA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008DCA4: bne         $t6, $at, L_8008DCD4
    if (ctx->r14 != ctx->r1) {
        // 0x8008DCA8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008DCD4;
    }
    // 0x8008DCA8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008DCAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008DCB0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008DCB4: jal         0x8006A554
    // 0x8008DCB8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008DCB8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8008DCBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008DCC0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DCC4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008DCC8: lb          $t7, 0x645D($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X645D);
    // 0x8008DCCC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008DCD0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_8008DCD4:
    // 0x8008DCD4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008DCD8: lw          $t8, 0x6494($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6494);
    // 0x8008DCDC: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x8008DCE0: bne         $t8, $zero, L_8008DDB8
    if (ctx->r24 != 0) {
        // 0x8008DCE4: andi        $t7, $v1, 0x9000
        ctx->r15 = ctx->r3 & 0X9000;
            goto L_8008DDB8;
    }
    // 0x8008DCE4: andi        $t7, $v1, 0x9000
    ctx->r15 = ctx->r3 & 0X9000;
    // 0x8008DCE8: beq         $t9, $zero, L_8008DD08
    if (ctx->r25 == 0) {
        // 0x8008DCEC: andi        $t0, $v1, 0x9000
        ctx->r8 = ctx->r3 & 0X9000;
            goto L_8008DD08;
    }
    // 0x8008DCEC: andi        $t0, $v1, 0x9000
    ctx->r8 = ctx->r3 & 0X9000;
    // 0x8008DCF0: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DCF4: jal         0x80001D04
    // 0x8008DCF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008DCF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8008DCFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DD00: b           L_8008DE60
    // 0x8008DD04: sw          $zero, 0x6488($at)
    MEM_W(0X6488, ctx->r1) = 0;
        goto L_8008DE60;
    // 0x8008DD04: sw          $zero, 0x6488($at)
    MEM_W(0X6488, ctx->r1) = 0;
L_8008DD08:
    // 0x8008DD08: beq         $t0, $zero, L_8008DD68
    if (ctx->r8 == 0) {
        // 0x8008DD0C: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8008DD68;
    }
    // 0x8008DD0C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DD10: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DD14: addiu       $a2, $a2, 0x648C
    ctx->r6 = ADD32(ctx->r6, 0X648C);
    // 0x8008DD18: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8008DD1C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008DD20: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8008DD24: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8008DD28: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008DD2C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8008DD30: lbu         $t3, 0x64A1($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X64A1);
    // 0x8008DD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008DD38: beq         $t3, $zero, L_8008DD58
    if (ctx->r11 == 0) {
        // 0x8008DD3C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008DD58;
    }
    // 0x8008DD3C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DD40: jal         0x80001D04
    // 0x8008DD44: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008DD44: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    after_3:
    // 0x8008DD48: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008DD4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DD50: b           L_8008DE60
    // 0x8008DD54: sw          $t4, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = ctx->r12;
        goto L_8008DE60;
    // 0x8008DD54: sw          $t4, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = ctx->r12;
L_8008DD58:
    // 0x8008DD58: jal         0x80001D04
    // 0x8008DD5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008DD5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008DD60: b           L_8008DE64
    // 0x8008DD64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008DE64;
    // 0x8008DD64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DD68:
    // 0x8008DD68: addiu       $a2, $a2, 0x648C
    ctx->r6 = ADD32(ctx->r6, 0X648C);
    // 0x8008DD6C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008DD70: bgez        $a1, L_8008DD88
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008DD74: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8008DD88;
    }
    // 0x8008DD74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008DD78: blez        $v1, L_8008DD88
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008DD7C: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8008DD88;
    }
    // 0x8008DD7C: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x8008DD80: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8008DD84: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_8008DD88:
    // 0x8008DD88: blez        $a1, L_8008DDA0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8008DD8C: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008DDA0;
    }
    // 0x8008DD8C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008DD90: beq         $at, $zero, L_8008DDA0
    if (ctx->r1 == 0) {
        // 0x8008DD94: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8008DDA0;
    }
    // 0x8008DD94: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8008DD98: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8008DD9C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8008DDA0:
    // 0x8008DDA0: beq         $v0, $v1, L_8008DE60
    if (ctx->r2 == ctx->r3) {
        // 0x8008DDA4: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008DE60;
    }
    // 0x8008DDA4: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008DDA8: jal         0x80001D04
    // 0x8008DDAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8008DDAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8008DDB0: b           L_8008DE64
    // 0x8008DDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008DE64;
    // 0x8008DDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DDB8:
    // 0x8008DDB8: beq         $t7, $zero, L_8008DE44
    if (ctx->r15 == 0) {
        // 0x8008DDBC: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008DE44;
    }
    // 0x8008DDBC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DDC0: jal         0x80001D04
    // 0x8008DDC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008DDC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8008DDC8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DDCC: addiu       $a2, $a2, 0x648C
    ctx->r6 = ADD32(ctx->r6, 0X648C);
    // 0x8008DDD0: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8008DDD4: jal         0x8006ECAC
    // 0x8008DDD8: nop

    mark_save_file_to_erase(rdram, ctx);
        goto after_7;
    // 0x8008DDD8: nop

    after_7:
    // 0x8008DDDC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DDE0: addiu       $a2, $a2, 0x648C
    ctx->r6 = ADD32(ctx->r6, 0X648C);
    // 0x8008DDE4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008DDE8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008DDEC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8008DDF0: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8008DDF4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008DDF8: addiu       $t9, $t9, 0x64A0
    ctx->r25 = ADD32(ctx->r25, 0X64A0);
    // 0x8008DDFC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8008DE00: addiu       $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
    // 0x8008DE04: addiu       $t1, $zero, 0x4B
    ctx->r9 = ADD32(0, 0X4B);
    // 0x8008DE08: addiu       $t2, $zero, 0x52
    ctx->r10 = ADD32(0, 0X52);
    // 0x8008DE0C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008DE10: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8008DE14: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008DE18: sb          $t0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r8;
    // 0x8008DE1C: sb          $t1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r9;
    // 0x8008DE20: sb          $t2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r10;
    // 0x8008DE24: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x8008DE28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008DE2C: sw          $v1, -0xB34($at)
    MEM_W(-0XB34, ctx->r1) = ctx->r3;
    // 0x8008DE30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DE34: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x8008DE38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DE3C: b           L_8008DE60
    // 0x8008DE40: sw          $zero, 0x6488($at)
    MEM_W(0X6488, ctx->r1) = 0;
        goto L_8008DE60;
    // 0x8008DE40: sw          $zero, 0x6488($at)
    MEM_W(0X6488, ctx->r1) = 0;
L_8008DE44:
    // 0x8008DE44: andi        $t3, $v1, 0x4000
    ctx->r11 = ctx->r3 & 0X4000;
    // 0x8008DE48: beq         $t3, $zero, L_8008DE60
    if (ctx->r11 == 0) {
        // 0x8008DE4C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008DE60;
    }
    // 0x8008DE4C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DE50: jal         0x80001D04
    // 0x8008DE54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8008DE54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8008DE58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DE5C: sw          $zero, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = 0;
L_8008DE60:
    // 0x8008DE60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DE64:
    // 0x8008DE64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008DE68: jr          $ra
    // 0x8008DE6C: nop

    return;
    // 0x8008DE6C: nop

;}
RECOMP_FUNC void obj_init_infopoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038854: lbu         $t6, 0x9($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X9);
    // 0x80038858: addiu       $t7, $zero, 0x21
    ctx->r15 = ADD32(0, 0X21);
    // 0x8003885C: beq         $t6, $zero, L_80038870
    if (ctx->r14 == 0) {
        // 0x80038860: nop
    
            goto L_80038870;
    }
    // 0x80038860: nop

    // 0x80038864: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80038868: b           L_8003887C
    // 0x8003886C: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
        goto L_8003887C;
    // 0x8003886C: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
L_80038870:
    // 0x80038870: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80038874: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x80038878: sh          $t9, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r25;
L_8003887C:
    // 0x8003887C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038880: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80038884: sb          $zero, 0x11($t1)
    MEM_B(0X11, ctx->r9) = 0;
    // 0x80038888: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x8003888C: nop

    // 0x80038890: sb          $t2, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r10;
    // 0x80038894: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x80038898: nop

    // 0x8003889C: sb          $zero, 0x12($t4)
    MEM_B(0X12, ctx->r12) = 0;
    // 0x800388A0: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x800388A4: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x800388A8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800388AC: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800388B0: sw          $t8, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r24;
    // 0x800388B4: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x800388B8: nop

    // 0x800388BC: sw          $t9, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r25;
    // 0x800388C0: lbu         $t0, 0xB($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XB);
    // 0x800388C4: nop

    // 0x800388C8: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x800388CC: jr          $ra
    // 0x800388D0: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    return;
    // 0x800388D0: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void set_delayed_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3158: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800C315C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800C3160: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C3164: bne         $t6, $zero, L_800C31A8
    if (ctx->r14 != 0) {
        // 0x800C3168: lui         $at, 0x404E
        ctx->r1 = S32(0X404E << 16);
            goto L_800C31A8;
    }
    // 0x800C3168: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x800C316C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800C3170: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C3174: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3178: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C317C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C3180: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C3184: nop

    // 0x800C3188: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800C318C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C3190: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C3194: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C3198: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C319C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C31A0: b           L_800C31E0
    // 0x800C31A4: swc1        $f10, 0x3678($at)
    MEM_W(0X3678, ctx->r1) = ctx->f10.u32l;
        goto L_800C31E0;
    // 0x800C31A4: swc1        $f10, 0x3678($at)
    MEM_W(0X3678, ctx->r1) = ctx->f10.u32l;
L_800C31A8:
    // 0x800C31A8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C31AC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C31B0: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800C31B4: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800C31B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C31BC: nop

    // 0x800C31C0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C31C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C31C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C31CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C31D0: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800C31D4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C31D8: swc1        $f6, 0x3678($at)
    MEM_W(0X3678, ctx->r1) = ctx->f6.u32l;
    // 0x800C31DC: nop

L_800C31E0:
    // 0x800C31E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C31E4: jr          $ra
    // 0x800C31E8: sw          $a0, 0x367C($at)
    MEM_W(0X367C, ctx->r1) = ctx->r4;
    return;
    // 0x800C31E8: sw          $a0, 0x367C($at)
    MEM_W(0X367C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void music_volume_config(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001AFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001B00: lw          $v0, -0x39AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X39AC);
    // 0x80001B04: jr          $ra
    // 0x80001B08: nop

    return;
    // 0x80001B08: nop

;}
RECOMP_FUNC void charselect_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { extern int dkr_legacy_character_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*); static const uint32_t dkr_character_menu_fields[] = { 0x801263d4U, 0x801263dcU, 0x801263e8U, 0x801263f0U, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df480U, 0x800df4bcU, 0x800df47cU, 0x801263a0U, 0x801263ccU, 0x800e3690U, 0x800e36c8U, 0x80126808U, 0x801263c0U, 0x8011ae5cU, 0x8011aec8U }; dkr_legacy_character_menu(rdram, ctx, 3U, dkr_character_menu_fields); }
    // 0x8008C128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C12C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C130: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C134: jal         0x8009C4A8
    // 0x8008C138: addiu       $a0, $a0, -0x238
    ctx->r4 = ADD32(ctx->r4, -0X238);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8008C138: addiu       $a0, $a0, -0x238
    ctx->r4 = ADD32(ctx->r4, -0X238);
    after_0:
    // 0x8008C13C: jal         0x800710B0
    // 0x8008C140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_1;
    // 0x8008C140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8008C144: jal         0x800C422C
    // 0x8008C148: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_2;
    // 0x8008C148: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8008C14C: jal         0x800710B0
    // 0x8008C150: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_3;
    // 0x8008C150: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x8008C154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C158: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C15C: sw          $zero, -0x30($at)
    MEM_W(-0X30, ctx->r1) = 0;
    // 0x8008C160: jr          $ra
    // 0x8008C164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008C164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ttcam_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800278E8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800278EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800278F0: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800278F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800278F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800278FC: jal         0x8001BA74
    // 0x80027900: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x80027900: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80027904: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80027908: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002790C: blez        $t6, L_800279D4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80027910: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800279D4;
    }
    // 0x80027910: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80027914: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80027918:
    // 0x80027918: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002791C: nop

    // 0x80027920: beq         $v0, $zero, L_800279C4
    if (ctx->r2 == 0) {
        // 0x80027924: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_800279C4;
    }
    // 0x80027924: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80027928: lw          $s1, 0x64($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X64);
    // 0x8002792C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80027930: lb          $t7, 0x1FD($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027934: nop

    // 0x80027938: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8002793C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80027940: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80027944: jal         0x8001BDD4
    // 0x80027948: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    spectate_nearest(rdram, ctx);
        goto after_1;
    // 0x80027948: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002794C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80027950: lb          $t9, 0x1D8($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1D8);
    // 0x80027954: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80027958: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8002795C: beq         $t9, $zero, L_80027984
    if (ctx->r25 == 0) {
        // 0x80027960: sb          $t8, 0x1FD($s1)
        MEM_B(0X1FD, ctx->r17) = ctx->r24;
            goto L_80027984;
    }
    // 0x80027960: sb          $t8, 0x1FD($s1)
    MEM_B(0X1FD, ctx->r17) = ctx->r24;
    // 0x80027964: lh          $t0, 0x1AC($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X1AC);
    // 0x80027968: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002796C: bne         $t0, $at, L_800279C4
    if (ctx->r8 != ctx->r1) {
        // 0x80027970: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_800279C4;
    }
    // 0x80027970: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80027974: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80027978: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8002797C: b           L_800279C0
    // 0x80027980: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
        goto L_800279C0;
    // 0x80027980: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
L_80027984:
    // 0x80027984: bne         $v1, $zero, L_8002799C
    if (ctx->r3 != 0) {
        // 0x80027988: nop
    
            goto L_8002799C;
    }
    // 0x80027988: nop

    // 0x8002798C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80027990: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80027994: b           L_800279C0
    // 0x80027998: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
        goto L_800279C0;
    // 0x80027998: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_8002799C:
    // 0x8002799C: lh          $t3, 0x1AE($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X1AE);
    // 0x800279A0: lh          $t4, 0x1AE($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X1AE);
    // 0x800279A4: nop

    // 0x800279A8: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800279AC: beq         $at, $zero, L_800279C4
    if (ctx->r1 == 0) {
        // 0x800279B0: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_800279C4;
    }
    // 0x800279B0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800279B4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800279B8: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800279BC: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_800279C0:
    // 0x800279C0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_800279C4:
    // 0x800279C4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800279C8: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800279CC: bne         $at, $zero, L_80027918
    if (ctx->r1 != 0) {
        // 0x800279D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80027918;
    }
    // 0x800279D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800279D4:
    // 0x800279D4: beq         $v1, $zero, L_800279EC
    if (ctx->r3 == 0) {
        // 0x800279D8: lw          $s1, 0x3C($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X3C);
            goto L_800279EC;
    }
    // 0x800279D8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800279DC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800279E0: b           L_800279F4
    // 0x800279E4: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
        goto L_800279F4;
    // 0x800279E4: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800279E8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
L_800279EC:
    // 0x800279EC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800279F0: nop

L_800279F4:
    // 0x800279F4: lb          $a0, 0x1FD($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X1FD);
    // 0x800279F8: jal         0x8001BD94
    // 0x800279FC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    spectate_object(rdram, ctx);
        goto after_2;
    // 0x800279FC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_2:
    // 0x80027A00: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80027A04: lw          $t7, -0x4EFC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4EFC);
    // 0x80027A08: lb          $t8, 0x1FD($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027A0C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80027A10: beq         $t7, $t8, L_80027A28
    if (ctx->r15 == ctx->r24) {
        // 0x80027A14: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80027A28;
    }
    // 0x80027A14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80027A18: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027A1C: addiu       $a3, $a3, -0x4EF8
    ctx->r7 = ADD32(ctx->r7, -0X4EF8);
    // 0x80027A20: b           L_80027A5C
    // 0x80027A24: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80027A5C;
    // 0x80027A24: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80027A28:
    // 0x80027A28: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80027A2C: addiu       $v1, $v1, -0x4F00
    ctx->r3 = ADD32(ctx->r3, -0X4F00);
    // 0x80027A30: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80027A34: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x80027A38: nop

    // 0x80027A3C: beq         $t9, $t0, L_80027A5C
    if (ctx->r25 == ctx->r8) {
        // 0x80027A40: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80027A5C;
    }
    // 0x80027A40: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027A44: addiu       $a3, $a3, -0x4EF8
    ctx->r7 = ADD32(ctx->r7, -0X4EF8);
    // 0x80027A48: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x80027A4C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80027A50: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x80027A54: nop

    // 0x80027A58: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80027A5C:
    // 0x80027A5C: beq         $v0, $zero, L_80027E14
    if (ctx->r2 == 0) {
        // 0x80027A60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80027E14;
    }
    // 0x80027A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80027A64: jal         0x80069CFC
    // 0x80027A68: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_3;
    // 0x80027A68: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_3:
    // 0x80027A6C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027A70: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80027A74: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80027A78: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027A7C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80027A80: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80027A84: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027A88: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80027A8C: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80027A90: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80027A94: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80027A98: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80027A9C: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80027AA0: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80027AA4: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80027AA8: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80027AAC: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80027AB0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80027AB4: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80027AB8: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80027ABC: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80027AC0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80027AC4: jal         0x800C9AD0
    // 0x80027AC8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80027AC8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_4:
    // 0x80027ACC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027AD0: addiu       $a3, $a3, -0x4EF8
    ctx->r7 = ADD32(ctx->r7, -0X4EF8);
    // 0x80027AD4: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80027AD8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027ADC: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80027AE0: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80027AE4: beq         $t3, $zero, L_80027D18
    if (ctx->r11 == 0) {
        // 0x80027AE8: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80027D18;
    }
    // 0x80027AE8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80027AEC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80027AF0: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80027AF4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80027AF8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027AFC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027B00: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x80027B04: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80027B08: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80027B0C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80027B10: nop

    // 0x80027B14: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80027B18: nop

    // 0x80027B1C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80027B20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027B24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027B28: nop

    // 0x80027B2C: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80027B30: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80027B34: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80027B38: jal         0x8007066C
    // 0x80027B3C: nop

    atan2s(rdram, ctx);
        goto after_5;
    // 0x80027B3C: nop

    after_5:
    // 0x80027B40: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027B44: negu        $t6, $v0
    ctx->r14 = SUB32(0, ctx->r2);
    // 0x80027B48: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x80027B4C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80027B50: subu        $s0, $t6, $a2
    ctx->r16 = SUB32(ctx->r14, ctx->r6);
    // 0x80027B54: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x80027B58: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x80027B5C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80027B60: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80027B64: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027B68: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80027B6C: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80027B70: addiu       $a3, $a3, -0x4EF8
    ctx->r7 = ADD32(ctx->r7, -0X4EF8);
    // 0x80027B74: bne         $at, $zero, L_80027B94
    if (ctx->r1 != 0) {
        // 0x80027B78: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_80027B94;
    }
    // 0x80027B78: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80027B7C: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x80027B80: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x80027B84: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80027B88: subu        $s0, $t0, $t9
    ctx->r16 = SUB32(ctx->r8, ctx->r25);
    // 0x80027B8C: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x80027B90: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
L_80027B94:
    // 0x80027B94: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80027B98: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80027B9C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80027BA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027BA4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80027BA8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80027BAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027BB0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80027BB4: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80027BB8: nop

    // 0x80027BBC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80027BC0: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80027BC4: nop

    // 0x80027BC8: div.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80027BCC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80027BD0: nop

    // 0x80027BD4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80027BD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027BDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027BE0: nop

    // 0x80027BE4: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80027BE8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80027BEC: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80027BF0: nop

    // 0x80027BF4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80027BF8: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80027BFC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80027C00: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80027C04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027C08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027C0C: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80027C10: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80027C14: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80027C18: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80027C1C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80027C20: nop

    // 0x80027C24: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80027C28: nop

    // 0x80027C2C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80027C30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027C34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027C38: nop

    // 0x80027C3C: cvt.w.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80027C40: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80027C44: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80027C48: jal         0x8007066C
    // 0x80027C4C: nop

    atan2s(rdram, ctx);
        goto after_6;
    // 0x80027C4C: nop

    after_6:
    // 0x80027C50: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027C54: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80027C58: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x80027C5C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027C60: subu        $s0, $v0, $a0
    ctx->r16 = SUB32(ctx->r2, ctx->r4);
    // 0x80027C64: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x80027C68: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80027C6C: slt         $at, $t1, $at
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80027C70: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80027C74: bne         $at, $zero, L_80027C94
    if (ctx->r1 != 0) {
        // 0x80027C78: addiu       $a3, $a3, -0x4EF8
        ctx->r7 = ADD32(ctx->r7, -0X4EF8);
            goto L_80027C94;
    }
    // 0x80027C78: addiu       $a3, $a3, -0x4EF8
    ctx->r7 = ADD32(ctx->r7, -0X4EF8);
    // 0x80027C7C: lui         $t3, 0xFFFF
    ctx->r11 = S32(0XFFFF << 16);
    // 0x80027C80: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x80027C84: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80027C88: subu        $s0, $t3, $t2
    ctx->r16 = SUB32(ctx->r11, ctx->r10);
    // 0x80027C8C: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80027C90: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
L_80027C94:
    // 0x80027C94: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80027C98: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80027C9C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80027CA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027CA4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80027CA8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80027CAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027CB0: div.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80027CB4: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x80027CB8: nop

    // 0x80027CBC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80027CC0: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80027CC4: nop

    // 0x80027CC8: div.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80027CCC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80027CD0: nop

    // 0x80027CD4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80027CD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027CDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027CE0: nop

    // 0x80027CE4: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80027CE8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80027CEC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80027CF0: addu        $t9, $a0, $t0
    ctx->r25 = ADD32(ctx->r4, ctx->r8);
    // 0x80027CF4: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x80027CF8: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80027CFC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80027D00: nop

    // 0x80027D04: subu        $t2, $t1, $t3
    ctx->r10 = SUB32(ctx->r9, ctx->r11);
    // 0x80027D08: bgez        $t2, L_80027DE0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80027D0C: sw          $t2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r10;
            goto L_80027DE0;
    }
    // 0x80027D0C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80027D10: b           L_80027DE0
    // 0x80027D14: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80027DE0;
    // 0x80027D14: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80027D18:
    // 0x80027D18: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80027D1C: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80027D20: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80027D24: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027D28: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027D2C: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x80027D30: cvt.w.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80027D34: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80027D38: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80027D3C: nop

    // 0x80027D40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80027D44: nop

    // 0x80027D48: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80027D4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027D50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027D54: nop

    // 0x80027D58: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80027D5C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80027D60: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80027D64: jal         0x8007066C
    // 0x80027D68: nop

    atan2s(rdram, ctx);
        goto after_7;
    // 0x80027D68: nop

    after_7:
    // 0x80027D6C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80027D70: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027D74: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80027D78: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80027D7C: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80027D80: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80027D84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027D88: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80027D8C: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80027D90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027D94: nop

    // 0x80027D98: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80027D9C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80027DA0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80027DA4: nop

    // 0x80027DA8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80027DAC: nop

    // 0x80027DB0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80027DB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027DB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027DBC: nop

    // 0x80027DC0: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80027DC4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80027DC8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80027DCC: jal         0x8007066C
    // 0x80027DD0: nop

    atan2s(rdram, ctx);
        goto after_8;
    // 0x80027DD0: nop

    after_8:
    // 0x80027DD4: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027DD8: nop

    // 0x80027DDC: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_80027DE0:
    // 0x80027DE0: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80027DE4: lwc1        $f14, 0x3C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80027DE8: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80027DEC: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x80027DF0: jal         0x80029F18
    // 0x80027DF4: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_9;
    // 0x80027DF4: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_9:
    // 0x80027DF8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80027DFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80027E00: sh          $v0, 0x34($v1)
    MEM_H(0X34, ctx->r3) = ctx->r2;
    // 0x80027E04: lb          $t1, 0x1FD($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1FD);
    // 0x80027E08: nop

    // 0x80027E0C: sw          $t1, -0x4EFC($at)
    MEM_W(-0X4EFC, ctx->r1) = ctx->r9;
    // 0x80027E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80027E14:
    // 0x80027E14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80027E18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80027E1C: jr          $ra
    // 0x80027E20: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80027E20: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void menu_asset_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C508: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009C50C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009C510: addiu       $t6, $t6, 0x6750
    ctx->r14 = ADD32(ctx->r14, 0X6750);
    // 0x8009C514: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8009C518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C51C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8009C520: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x8009C524: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8009C528: beq         $t9, $zero, L_8009C604
    if (ctx->r25 == 0) {
        // 0x8009C52C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8009C604;
    }
    // 0x8009C52C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009C530: addiu       $t1, $t1, 0x6550
    ctx->r9 = ADD32(ctx->r9, 0X6550);
    // 0x8009C534: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8009C538: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8009C53C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8009C540: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009C544: beq         $v0, $zero, L_8009C5DC
    if (ctx->r2 == 0) {
        // 0x8009C548: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_8009C5DC;
    }
    // 0x8009C548: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8009C54C: lw          $t3, -0x8B0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X8B0);
    // 0x8009C550: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8009C554: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8009C558: lh          $v1, 0x0($t5)
    ctx->r3 = MEM_H(ctx->r13, 0X0);
    // 0x8009C55C: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8009C560: andi        $t6, $v1, 0xC000
    ctx->r14 = ctx->r3 & 0XC000;
    // 0x8009C564: bne         $t6, $at, L_8009C5A0
    if (ctx->r14 != ctx->r1) {
        // 0x8009C568: andi        $t8, $v1, 0x8000
        ctx->r24 = ctx->r3 & 0X8000;
            goto L_8009C5A0;
    }
    // 0x8009C568: andi        $t8, $v1, 0x8000
    ctx->r24 = ctx->r3 & 0X8000;
    // 0x8009C56C: beq         $v0, $zero, L_8009C5A0
    if (ctx->r2 == 0) {
        // 0x8009C570: nop
    
            goto L_8009C5A0;
    }
    // 0x8009C570: nop

    // 0x8009C574: jal         0x800710B0
    // 0x8009C578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8009C578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8009C57C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8009C580: nop

    // 0x8009C584: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8009C588: jal         0x8007B2BC
    // 0x8009C58C: nop

    tex_free(rdram, ctx);
        goto after_1;
    // 0x8009C58C: nop

    after_1:
    // 0x8009C590: jal         0x800710B0
    // 0x8009C594: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_2;
    // 0x8009C594: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8009C598: b           L_8009C5DC
    // 0x8009C59C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_8009C5DC;
    // 0x8009C59C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009C5A0:
    // 0x8009C5A0: beq         $t8, $zero, L_8009C5B8
    if (ctx->r24 == 0) {
        // 0x8009C5A4: andi        $t9, $v1, 0x4000
        ctx->r25 = ctx->r3 & 0X4000;
            goto L_8009C5B8;
    }
    // 0x8009C5A4: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x8009C5A8: jal         0x8007CCB0
    // 0x8009C5AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sprite_free(rdram, ctx);
        goto after_3;
    // 0x8009C5AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8009C5B0: b           L_8009C5DC
    // 0x8009C5B4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_8009C5DC;
    // 0x8009C5B4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009C5B8:
    // 0x8009C5B8: beq         $t9, $zero, L_8009C5D0
    if (ctx->r25 == 0) {
        // 0x8009C5BC: nop
    
            goto L_8009C5D0;
    }
    // 0x8009C5BC: nop

    // 0x8009C5C0: jal         0x8000FFB8
    // 0x8009C5C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_object(rdram, ctx);
        goto after_4;
    // 0x8009C5C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8009C5C8: b           L_8009C5DC
    // 0x8009C5CC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
        goto L_8009C5DC;
    // 0x8009C5CC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009C5D0:
    // 0x8009C5D0: jal         0x8005FF40
    // 0x8009C5D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_3d_model(rdram, ctx);
        goto after_5;
    // 0x8009C5D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8009C5D8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8009C5DC:
    // 0x8009C5DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C5E0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8009C5E4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C5E8: addiu       $v0, $v0, -0x8A8
    ctx->r2 = ADD32(ctx->r2, -0X8A8);
    // 0x8009C5EC: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x8009C5F0: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8009C5F4: nop

    // 0x8009C5F8: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8009C5FC: jal         0x8001004C
    // 0x8009C600: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    gParticlePtrList_flush(rdram, ctx);
        goto after_6;
    // 0x8009C600: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    after_6:
L_8009C604:
    // 0x8009C604: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009C608: lh          $t4, -0x8A8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X8A8);
    // 0x8009C60C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009C610: bne         $t4, $zero, L_8009C668
    if (ctx->r12 != 0) {
        // 0x8009C614: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009C668;
    }
    // 0x8009C614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C618: lw          $a0, -0x8A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X8A4);
    // 0x8009C61C: nop

    // 0x8009C620: beq         $a0, $zero, L_8009C638
    if (ctx->r4 == 0) {
        // 0x8009C624: nop
    
            goto L_8009C638;
    }
    // 0x8009C624: nop

    // 0x8009C628: jal         0x80071140
    // 0x8009C62C: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8009C62C: nop

    after_7:
    // 0x8009C630: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C634: sw          $zero, -0x8A4($at)
    MEM_W(-0X8A4, ctx->r1) = 0;
L_8009C638:
    // 0x8009C638: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009C63C: lw          $a0, -0x8B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X8B0);
    // 0x8009C640: nop

    // 0x8009C644: beq         $a0, $zero, L_8009C668
    if (ctx->r4 == 0) {
        // 0x8009C648: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009C668;
    }
    // 0x8009C648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C64C: jal         0x80071140
    // 0x8009C650: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8009C650: nop

    after_8:
    // 0x8009C654: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C658: sw          $zero, -0x8B0($at)
    MEM_W(-0X8B0, ctx->r1) = 0;
    // 0x8009C65C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C660: sh          $zero, -0x8AC($at)
    MEM_H(-0X8AC, ctx->r1) = 0;
    // 0x8009C664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C668:
    // 0x8009C668: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009C66C: jr          $ra
    // 0x8009C670: nop

    return;
    // 0x8009C670: nop

;}
RECOMP_FUNC void obj_init_laserbolt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034844: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80034848: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003484C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80034850: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80034854: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80034858: jr          $ra
    // 0x8003485C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    return;
    // 0x8003485C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
;}
RECOMP_FUNC void music_jingle_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800018E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800018E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800018E8: jal         0x80001C08
    // 0x800018EC: nop

    music_jingle_playing(rdram, ctx);
        goto after_0;
    // 0x800018EC: nop

    after_0:
    // 0x800018F0: bne         $v0, $zero, L_80001908
    if (ctx->r2 != 0) {
        // 0x800018F4: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_80001908;
    }
    // 0x800018F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800018F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800018FC: lw          $a0, -0x39CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39CC);
    // 0x80001900: jal         0x80002570
    // 0x80001904: sb          $zero, 0x5D05($at)
    MEM_B(0X5D05, ctx->r1) = 0;
    music_sequence_stop(rdram, ctx);
        goto after_1;
    // 0x80001904: sb          $zero, 0x5D05($at)
    MEM_B(0X5D05, ctx->r1) = 0;
    after_1:
L_80001908:
    // 0x80001908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000190C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001910: jr          $ra
    // 0x80001914: nop

    return;
    // 0x80001914: nop

;}
RECOMP_FUNC void hud_main_taj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A263C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2640: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2644: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A2648: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A264C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A2650: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A2654: lw          $s0, 0x64($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X64);
    // 0x800A2658: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800A265C: jal         0x80068508
    // 0x800A2660: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A2660: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A2664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2668: jal         0x800A5A64
    // 0x800A266C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_wrong_way(rdram, ctx);
        goto after_1;
    // 0x800A266C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800A2670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2674: jal         0x800A4F50
    // 0x800A2678: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_lap_count(rdram, ctx);
        goto after_2;
    // 0x800A2678: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800A267C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2680: jal         0x800A4C44
    // 0x800A2684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_race_position(rdram, ctx);
        goto after_3;
    // 0x800A2684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800A2688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A268C: jal         0x800A7B68
    // 0x800A2690: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_race_time(rdram, ctx);
        goto after_4;
    // 0x800A2690: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800A2694: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A2698: jal         0x800A3CE4
    // 0x800A269C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_race_start(rdram, ctx);
        goto after_5;
    // 0x800A269C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800A26A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A26A4: jal         0x800A3884
    // 0x800A26A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    hud_speedometre(rdram, ctx);
        goto after_6;
    // 0x800A26A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800A26AC: jal         0x80068508
    // 0x800A26B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_7;
    // 0x800A26B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A26B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A26B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A26BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A26C0: jr          $ra
    // 0x800A26C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A26C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void hud_speedometre(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3884: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A3888: lbu         $t6, 0x6D37($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X6D37);
    // 0x800A388C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A3890: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A3894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3898: bne         $t6, $at, L_800A3CD4
    if (ctx->r14 != ctx->r1) {
        // 0x800A389C: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_800A3CD4;
    }
    // 0x800A389C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A38A0: jal         0x80066510
    // 0x800A38A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_0;
    // 0x800A38A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A38A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A38AC: bne         $v0, $zero, L_800A3CD8
    if (ctx->r2 != 0) {
        // 0x800A38B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3CD8;
    }
    // 0x800A38B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A38B4: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800A38B8: nop

    // 0x800A38BC: lb          $t7, 0x1D8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A38C0: nop

    // 0x800A38C4: bne         $t7, $zero, L_800A3CD8
    if (ctx->r15 != 0) {
        // 0x800A38C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3CD8;
    }
    // 0x800A38C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A38CC: lb          $t8, 0x1D6($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1D6);
    // 0x800A38D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A38D4: bne         $t8, $at, L_800A3914
    if (ctx->r24 != ctx->r1) {
        // 0x800A38D8: nop
    
            goto L_800A3914;
    }
    // 0x800A38D8: nop

    // 0x800A38DC: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800A38E0: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800A38E4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800A38E8: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A38EC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800A38F0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800A38F4: nop

    // 0x800A38F8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A38FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A3900: jal         0x800C9AD0
    // 0x800A3904: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800A3904: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x800A3908: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800A390C: b           L_800A3938
    // 0x800A3910: nop

        goto L_800A3938;
    // 0x800A3910: nop

L_800A3914:
    // 0x800A3914: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800A3918: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800A391C: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800A3920: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800A3924: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A3928: jal         0x800C9AD0
    // 0x800A392C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800A392C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_2:
    // 0x800A3930: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800A3934: nop

L_800A3938:
    // 0x800A3938: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A393C: lwc1        $f4, 0x2838($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2838);
    // 0x800A3940: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800A3944: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800A3948: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A394C: bc1f        L_800A3958
    if (!c1cs) {
        // 0x800A3950: nop
    
            goto L_800A3958;
    }
    // 0x800A3950: nop

    // 0x800A3954: swc1        $f0, 0x2838($at)
    MEM_W(0X2838, ctx->r1) = ctx->f0.u32l;
L_800A3958:
    // 0x800A3958: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A395C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A3960: lb          $t9, 0x1E6($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1E6);
    // 0x800A3964: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A3968: beq         $t9, $zero, L_800A397C
    if (ctx->r25 == 0) {
        // 0x800A396C: lui         $at, 0x40E0
        ctx->r1 = S32(0X40E0 << 16);
            goto L_800A397C;
    }
    // 0x800A396C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x800A3970: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A3974: nop

    // 0x800A3978: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
L_800A397C:
    // 0x800A397C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A3980: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A3984: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A3988: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800A398C: nop

    // 0x800A3990: bc1f        L_800A399C
    if (!c1cs) {
        // 0x800A3994: nop
    
            goto L_800A399C;
    }
    // 0x800A3994: nop

    // 0x800A3998: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800A399C:
    // 0x800A399C: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800A39A0: nop

    // 0x800A39A4: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x800A39A8: nop

    // 0x800A39AC: bc1f        L_800A39B8
    if (!c1cs) {
        // 0x800A39B0: nop
    
            goto L_800A39B8;
    }
    // 0x800A39B0: nop

    // 0x800A39B4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800A39B8:
    // 0x800A39B8: lwc1        $f12, -0x78C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X78C0);
    // 0x800A39BC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800A39C0: sub.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800A39C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A39C8: nop

    // 0x800A39CC: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800A39D0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800A39D4: nop

    // 0x800A39D8: bc1f        L_800A39E4
    if (!c1cs) {
        // 0x800A39DC: nop
    
            goto L_800A39E4;
    }
    // 0x800A39DC: nop

    // 0x800A39E0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800A39E4:
    // 0x800A39E4: jal         0x8006EAA0
    // 0x800A39E8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    is_game_paused(rdram, ctx);
        goto after_3;
    // 0x800A39E8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x800A39EC: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A39F0: bne         $v0, $zero, L_800A3AAC
    if (ctx->r2 != 0) {
        // 0x800A39F4: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A3AAC;
    }
    // 0x800A39F4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A39F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A39FC: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A3A00: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800A3A04: lh          $t0, 0x4C4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4C4);
    // 0x800A3A08: nop

    // 0x800A3A0C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800A3A10: nop

    // 0x800A3A14: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A3A18: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800A3A1C: nop

    // 0x800A3A20: bc1f        L_800A3A6C
    if (!c1cs) {
        // 0x800A3A24: nop
    
            goto L_800A3A6C;
    }
    // 0x800A3A24: nop

    // 0x800A3A28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A3A2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A3A30: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A3A34: nop

    // 0x800A3A38: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A3A3C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800A3A40: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A3A44: nop

    // 0x800A3A48: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A3A4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3A50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3A54: nop

    // 0x800A3A58: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A3A5C: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x800A3A60: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A3A64: b           L_800A3AAC
    // 0x800A3A68: sh          $t2, 0x4C4($v0)
    MEM_H(0X4C4, ctx->r2) = ctx->r10;
        goto L_800A3AAC;
    // 0x800A3A68: sh          $t2, 0x4C4($v0)
    MEM_H(0X4C4, ctx->r2) = ctx->r10;
L_800A3A6C:
    // 0x800A3A6C: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800A3A70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A3A74: nop

    // 0x800A3A78: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A3A7C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800A3A80: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A3A84: nop

    // 0x800A3A88: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A3A8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3A90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3A94: nop

    // 0x800A3A98: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A3A9C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A3AA0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A3AA4: sh          $t4, 0x4C4($v0)
    MEM_H(0X4C4, ctx->r2) = ctx->r12;
    // 0x800A3AA8: nop

L_800A3AAC:
    // 0x800A3AAC: lw          $t5, 0x6D0C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D0C);
    // 0x800A3AB0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A3AB4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800A3AB8: lb          $t6, 0x27A4($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X27A4);
    // 0x800A3ABC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3AC0: bne         $t6, $zero, L_800A3CD4
    if (ctx->r14 != 0) {
        // 0x800A3AC4: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A3CD4;
    }
    // 0x800A3AC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3AC8: lb          $t7, 0x6CD3($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6CD3);
    // 0x800A3ACC: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3AD0: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800A3AD4: beq         $t8, $zero, L_800A3B54
    if (ctx->r24 == 0) {
        // 0x800A3AD8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A3B54;
    }
    // 0x800A3AD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3ADC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A3AE0: lb          $t9, 0x6CD0($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X6CD0);
    // 0x800A3AE4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A3AE8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A3AEC: lbu         $t0, 0x718B($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X718B);
    // 0x800A3AF0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A3AF4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A3AF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A3AFC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800A3B00: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800A3B04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A3B08: bgez        $t0, L_800A3B1C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A3B0C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A3B1C;
    }
    // 0x800A3B0C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A3B10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A3B14: nop

    // 0x800A3B18: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800A3B1C:
    // 0x800A3B1C: nop

    // 0x800A3B20: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800A3B24: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A3B28: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A3B2C: nop

    // 0x800A3B30: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A3B34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3B38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3B3C: nop

    // 0x800A3B40: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A3B44: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800A3B48: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A3B4C: b           L_800A3B5C
    // 0x800A3B50: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
        goto L_800A3B5C;
    // 0x800A3B50: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_800A3B54:
    // 0x800A3B54: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A3B58: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_800A3B5C:
    // 0x800A3B5C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A3B60: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A3B64: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3B68: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A3B6C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A3B70: jal         0x800AA600
    // 0x800A3B74: addiu       $a3, $a3, 0x5A0
    ctx->r7 = ADD32(ctx->r7, 0X5A0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A3B74: addiu       $a3, $a3, 0x5A0
    ctx->r7 = ADD32(ctx->r7, 0X5A0);
    after_4:
    // 0x800A3B78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3B7C: jal         0x8007B3D0
    // 0x800A3B80: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x800A3B80: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    after_5:
    // 0x800A3B84: jal         0x8007BF1C
    // 0x800A3B88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_6;
    // 0x800A3B88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A3B8C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3B90: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3B94: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A3B98: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A3B9C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800A3BA0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800A3BA4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800A3BA8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800A3BAC: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800A3BB0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800A3BB4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800A3BB8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A3BBC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800A3BC0: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A3BC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3BC8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3BCC: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A3BD0: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A3BD4: jal         0x800AA600
    // 0x800A3BD8: addiu       $a3, $a3, 0x4C0
    ctx->r7 = ADD32(ctx->r7, 0X4C0);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A3BD8: addiu       $a3, $a3, 0x4C0
    ctx->r7 = ADD32(ctx->r7, 0X4C0);
    after_7:
    // 0x800A3BDC: jal         0x8007BF1C
    // 0x800A3BE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_8;
    // 0x800A3BE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A3BE4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A3BE8: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A3BEC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3BF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3BF4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3BF8: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A3BFC: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A3C00: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3C04: jal         0x800AA600
    // 0x800A3C08: addiu       $a3, $a3, 0x4E0
    ctx->r7 = ADD32(ctx->r7, 0X4E0);
    hud_element_render(rdram, ctx);
        goto after_9;
    // 0x800A3C08: addiu       $a3, $a3, 0x4E0
    ctx->r7 = ADD32(ctx->r7, 0X4E0);
    after_9:
    // 0x800A3C0C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A3C10: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A3C14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3C18: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3C1C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3C20: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A3C24: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A3C28: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3C2C: jal         0x800AA600
    // 0x800A3C30: addiu       $a3, $a3, 0x500
    ctx->r7 = ADD32(ctx->r7, 0X500);
    hud_element_render(rdram, ctx);
        goto after_10;
    // 0x800A3C30: addiu       $a3, $a3, 0x500
    ctx->r7 = ADD32(ctx->r7, 0X500);
    after_10:
    // 0x800A3C34: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A3C38: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A3C3C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3C40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3C44: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3C48: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A3C4C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A3C50: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3C54: jal         0x800AA600
    // 0x800A3C58: addiu       $a3, $a3, 0x520
    ctx->r7 = ADD32(ctx->r7, 0X520);
    hud_element_render(rdram, ctx);
        goto after_11;
    // 0x800A3C58: addiu       $a3, $a3, 0x520
    ctx->r7 = ADD32(ctx->r7, 0X520);
    after_11:
    // 0x800A3C5C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A3C60: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A3C64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3C68: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3C6C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3C70: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A3C74: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A3C78: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3C7C: jal         0x800AA600
    // 0x800A3C80: addiu       $a3, $a3, 0x540
    ctx->r7 = ADD32(ctx->r7, 0X540);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A3C80: addiu       $a3, $a3, 0x540
    ctx->r7 = ADD32(ctx->r7, 0X540);
    after_12:
    // 0x800A3C84: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A3C88: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A3C8C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3C90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3C94: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3C98: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A3C9C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A3CA0: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3CA4: jal         0x800AA600
    // 0x800A3CA8: addiu       $a3, $a3, 0x560
    ctx->r7 = ADD32(ctx->r7, 0X560);
    hud_element_render(rdram, ctx);
        goto after_13;
    // 0x800A3CA8: addiu       $a3, $a3, 0x560
    ctx->r7 = ADD32(ctx->r7, 0X560);
    after_13:
    // 0x800A3CAC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A3CB0: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A3CB4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3CB8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3CBC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3CC0: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A3CC4: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A3CC8: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3CCC: jal         0x800AA600
    // 0x800A3CD0: addiu       $a3, $a3, 0x580
    ctx->r7 = ADD32(ctx->r7, 0X580);
    hud_element_render(rdram, ctx);
        goto after_14;
    // 0x800A3CD0: addiu       $a3, $a3, 0x580
    ctx->r7 = ADD32(ctx->r7, 0X580);
    after_14:
L_800A3CD4:
    // 0x800A3CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3CD8:
    // 0x800A3CD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A3CDC: jr          $ra
    // 0x800A3CE0: nop

    return;
    // 0x800A3CE0: nop

;}
RECOMP_FUNC void minimap_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A83B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A83B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A83BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A83C0: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A83C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A83C8: srl         $t8, $t6, 16
    ctx->r24 = S32(U32(ctx->r14) >> 16);
    // 0x800A83CC: sb          $t8, 0x6D54($at)
    MEM_B(0X6D54, ctx->r1) = ctx->r24;
    // 0x800A83D0: lw          $t9, 0x38($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X38);
    // 0x800A83D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A83D8: srl         $t1, $t9, 8
    ctx->r9 = S32(U32(ctx->r25) >> 8);
    // 0x800A83DC: sb          $t1, 0x6D55($at)
    MEM_B(0X6D55, ctx->r1) = ctx->r9;
    // 0x800A83E0: lw          $t3, 0x38($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X38);
    // 0x800A83E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A83E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A83EC: sb          $t3, 0x6D56($at)
    MEM_B(0X6D56, ctx->r1) = ctx->r11;
    // 0x800A83F0: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    // 0x800A83F4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x800A83F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A83FC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A8400: addiu       $a2, $a2, 0x6D20
    ctx->r6 = ADD32(ctx->r6, 0X6D20);
    // 0x800A8404: addiu       $a1, $a1, 0x6D1C
    ctx->r5 = ADD32(ctx->r5, 0X6D1C);
    // 0x800A8408: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800A840C: jal         0x8007C8E0
    // 0x800A8410: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    load_sprite_info(rdram, ctx);
        goto after_0;
    // 0x800A8410: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A8414: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x800A8418: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A841C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A8420: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x800A8424: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800A8428: addiu       $a3, $a3, 0x6D18
    ctx->r7 = ADD32(ctx->r7, 0X6D18);
    // 0x800A842C: addiu       $a2, $a2, 0x6D14
    ctx->r6 = ADD32(ctx->r6, 0X6D14);
    // 0x800A8430: jal         0x8007CA68
    // 0x800A8434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8007CA68(rdram, ctx);
        goto after_1;
    // 0x800A8434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800A8438: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x800A843C: jal         0x8007C12C
    // 0x800A8440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    tex_load_sprite(rdram, ctx);
        goto after_2;
    // 0x800A8440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800A8444: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800A8448: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A844C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A8450: jr          $ra
    // 0x800A8454: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A8454: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void free_track(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C7D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002C7D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C7DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002C7E0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002C7E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002C7E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002C7EC: jal         0x8000B290
    // 0x8002C7F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    racerfx_free(rdram, ctx);
        goto after_0;
    // 0x8002C7F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8002C7F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002C7F8: lw          $t6, -0x2C7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2C7C);
    // 0x8002C7FC: nop

    // 0x8002C800: beq         $t6, $zero, L_8002C810
    if (ctx->r14 == 0) {
        // 0x8002C804: nop
    
            goto L_8002C810;
    }
    // 0x8002C804: nop

    // 0x8002C808: jal         0x800B7D20
    // 0x8002C80C: nop

    waves_free(rdram, ctx);
        goto after_1;
    // 0x8002C80C: nop

    after_1:
L_8002C810:
    // 0x8002C810: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8002C814: addiu       $s4, $s4, -0x36E8
    ctx->r20 = ADD32(ctx->r20, -0X36E8);
    // 0x8002C818: lw          $s1, 0x0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X0);
    // 0x8002C81C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002C820: lh          $t7, 0x18($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X18);
    // 0x8002C824: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002C828: blez        $t7, L_8002C864
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8002C82C: nop
    
            goto L_8002C864;
    }
    // 0x8002C82C: nop

L_8002C830:
    // 0x8002C830: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002C834: nop

    // 0x8002C838: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8002C83C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8002C840: jal         0x8007B2BC
    // 0x8002C844: nop

    tex_free(rdram, ctx);
        goto after_2;
    // 0x8002C844: nop

    after_2:
    // 0x8002C848: lw          $s1, 0x0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X0);
    // 0x8002C84C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C850: lh          $t0, 0x18($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X18);
    // 0x8002C854: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8002C858: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002C85C: bne         $at, $zero, L_8002C830
    if (ctx->r1 != 0) {
        // 0x8002C860: nop
    
            goto L_8002C830;
    }
    // 0x8002C860: nop

L_8002C864:
    // 0x8002C864: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C868: lw          $a0, -0x2CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2CF4);
    // 0x8002C86C: jal         0x80071140
    // 0x8002C870: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8002C870: nop

    after_3:
    // 0x8002C874: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C878: lw          $a0, -0x2C90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2C90);
    // 0x8002C87C: jal         0x80071140
    // 0x8002C880: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x8002C880: nop

    after_4:
    // 0x8002C884: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C888: lw          $a0, -0x2C8C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2C8C);
    // 0x8002C88C: jal         0x80071140
    // 0x8002C890: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8002C890: nop

    after_5:
    // 0x8002C894: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x8002C898: nop

    // 0x8002C89C: lw          $a0, 0x20($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X20);
    // 0x8002C8A0: jal         0x8007CCB0
    // 0x8002C8A4: nop

    sprite_free(rdram, ctx);
        goto after_6;
    // 0x8002C8A4: nop

    after_6:
    // 0x8002C8A8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002C8AC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8002C8B0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002C8B4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002C8B8: addiu       $s3, $s3, -0x2CB8
    ctx->r19 = ADD32(ctx->r19, -0X2CB8);
    // 0x8002C8BC: addiu       $s0, $s0, -0x2CC8
    ctx->r16 = ADD32(ctx->r16, -0X2CC8);
    // 0x8002C8C0: addiu       $s2, $s2, -0x2CE0
    ctx->r18 = ADD32(ctx->r18, -0X2CE0);
    // 0x8002C8C4: addiu       $s1, $s1, -0x2CB0
    ctx->r17 = ADD32(ctx->r17, -0X2CB0);
L_8002C8C8:
    // 0x8002C8C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002C8CC: jal         0x80071140
    // 0x8002C8D0: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8002C8D0: nop

    after_7:
    // 0x8002C8D4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8002C8D8: jal         0x80071140
    // 0x8002C8DC: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8002C8DC: nop

    after_8:
    // 0x8002C8E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002C8E4: jal         0x80071140
    // 0x8002C8E8: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x8002C8E8: nop

    after_9:
    // 0x8002C8EC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8002C8F0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002C8F4: bne         $s0, $s3, L_8002C8C8
    if (ctx->r16 != ctx->r19) {
        // 0x8002C8F8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8002C8C8;
    }
    // 0x8002C8F8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002C8FC: jal         0x800257D0
    // 0x8002C900: nop

    void_free(rdram, ctx);
        goto after_10;
    // 0x8002C900: nop

    after_10:
    // 0x8002C904: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C908: lw          $a0, -0x4F48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4F48);
    // 0x8002C90C: nop

    // 0x8002C910: beq         $a0, $zero, L_8002C928
    if (ctx->r4 == 0) {
        // 0x8002C914: nop
    
            goto L_8002C928;
    }
    // 0x8002C914: nop

    // 0x8002C918: jal         0x8000FFB8
    // 0x8002C91C: nop

    free_object(rdram, ctx);
        goto after_11;
    // 0x8002C91C: nop

    after_11:
    // 0x8002C920: jal         0x8001004C
    // 0x8002C924: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_12;
    // 0x8002C924: nop

    after_12:
L_8002C928:
    // 0x8002C928: jal         0x8000C604
    // 0x8002C92C: nop

    free_all_objects(rdram, ctx);
        goto after_13;
    // 0x8002C92C: nop

    after_13:
    // 0x8002C930: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C934: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x8002C938: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002C93C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002C940: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C944: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002C948: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002C94C: jr          $ra
    // 0x8002C950: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002C950: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void leveltable_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B14C: bltz        $a0, L_8006B184
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B150: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B184;
    }
    // 0x8006B150: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B154: lw          $t6, 0x1170($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1170);
    // 0x8006B158: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B15C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B160: beq         $at, $zero, L_8006B184
    if (ctx->r1 == 0) {
        // 0x8006B164: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B184;
    }
    // 0x8006B164: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B168: lw          $t7, 0x117C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X117C);
    // 0x8006B16C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B170: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B174: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B178: lb          $v0, 0x1($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X1);
    // 0x8006B17C: jr          $ra
    // 0x8006B180: nop

    return;
    // 0x8006B180: nop

L_8006B184:
    // 0x8006B184: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006B188: jr          $ra
    // 0x8006B18C: nop

    return;
    // 0x8006B18C: nop

;}
RECOMP_FUNC void postrace_message(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095624: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80095628: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8009562C: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80095630: beq         $at, $zero, L_800956C8
    if (ctx->r1 == 0) {
        // 0x80095634: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800956C8;
    }
    // 0x80095634: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80095638: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009563C: addu        $at, $at, $t7
    gpr jr_addend_80095648 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80095640: lw          $t7, -0x7ADC($at)
    ctx->r15 = ADD32(ctx->r1, -0X7ADC);
    // 0x80095644: nop

    // 0x80095648: jr          $t7
    // 0x8009564C: nop

    switch (jr_addend_80095648 >> 2) {
        case 0: goto L_80095650; break;
        case 1: goto L_800956C8; break;
        case 2: goto L_800956C8; break;
        case 3: goto L_80095668; break;
        case 4: goto L_80095650; break;
        case 5: goto L_80095668; break;
        case 6: goto L_80095680; break;
        case 7: goto L_80095698; break;
        case 8: goto L_800956B0; break;
        default: switch_error(__func__, 0x80095648, 0x800E8524);
    }
    // 0x8009564C: nop

L_80095650:
    // 0x80095650: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095654: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80095658: addiu       $t8, $t8, 0x9D8
    ctx->r24 = ADD32(ctx->r24, 0X9D8);
    // 0x8009565C: addiu       $a0, $a0, 0x6C1C
    ctx->r4 = ADD32(ctx->r4, 0X6C1C);
    // 0x80095660: b           L_800956DC
    // 0x80095664: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_800956DC;
    // 0x80095664: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_80095668:
    // 0x80095668: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009566C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80095670: addiu       $t9, $t9, 0x9C4
    ctx->r25 = ADD32(ctx->r25, 0X9C4);
    // 0x80095674: addiu       $a0, $a0, 0x6C1C
    ctx->r4 = ADD32(ctx->r4, 0X6C1C);
    // 0x80095678: b           L_800956DC
    // 0x8009567C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
        goto L_800956DC;
    // 0x8009567C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_80095680:
    // 0x80095680: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095684: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80095688: addiu       $a0, $a0, 0x6C1C
    ctx->r4 = ADD32(ctx->r4, 0X6C1C);
    // 0x8009568C: addiu       $t0, $t0, 0xA04
    ctx->r8 = ADD32(ctx->r8, 0XA04);
    // 0x80095690: b           L_800956DC
    // 0x80095694: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
        goto L_800956DC;
    // 0x80095694: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_80095698:
    // 0x80095698: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009569C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800956A0: addiu       $a0, $a0, 0x6C1C
    ctx->r4 = ADD32(ctx->r4, 0X6C1C);
    // 0x800956A4: addiu       $t1, $t1, 0xA14
    ctx->r9 = ADD32(ctx->r9, 0XA14);
    // 0x800956A8: b           L_800956DC
    // 0x800956AC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
        goto L_800956DC;
    // 0x800956AC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_800956B0:
    // 0x800956B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800956B4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800956B8: addiu       $a0, $a0, 0x6C1C
    ctx->r4 = ADD32(ctx->r4, 0X6C1C);
    // 0x800956BC: addiu       $t2, $t2, 0x9EC
    ctx->r10 = ADD32(ctx->r10, 0X9EC);
    // 0x800956C0: b           L_800956DC
    // 0x800956C4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
        goto L_800956DC;
    // 0x800956C4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_800956C8:
    // 0x800956C8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800956CC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800956D0: addiu       $a0, $a0, 0x6C1C
    ctx->r4 = ADD32(ctx->r4, 0X6C1C);
    // 0x800956D4: addiu       $t3, $t3, 0x9B0
    ctx->r11 = ADD32(ctx->r11, 0X9B0);
    // 0x800956D8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_800956DC:
    // 0x800956DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800956E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800956E4: addiu       $a1, $a1, 0x6C24
    ctx->r5 = ADD32(ctx->r5, 0X6C24);
    // 0x800956E8: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800956EC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800956F0: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800956F4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800956F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800956FC: beq         $t6, $zero, L_80095720
    if (ctx->r14 == 0) {
        // 0x80095700: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_80095720;
    }
    // 0x80095700: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_80095704:
    // 0x80095704: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80095708: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8009570C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80095710: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80095714: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80095718: bne         $t0, $zero, L_80095704
    if (ctx->r8 != 0) {
        // 0x8009571C: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_80095704;
    }
    // 0x8009571C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_80095720:
    // 0x80095720: jr          $ra
    // 0x80095724: nop

    return;
    // 0x80095724: nop

;}
RECOMP_FUNC void reset_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800307BC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800307C0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800307C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800307C8: addiu       $t7, $t7, -0x2C78
    ctx->r15 = ADD32(ctx->r15, -0X2C78);
    // 0x800307CC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800307D0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800307D4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800307D8: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800307DC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x800307E0: lui         $t8, 0x3FA
    ctx->r24 = S32(0X3FA << 16);
    // 0x800307E4: lui         $t9, 0x3FF
    ctx->r25 = S32(0X3FF << 16);
    // 0x800307E8: addiu       $t6, $zero, 0x3FA
    ctx->r14 = ADD32(0, 0X3FA);
    // 0x800307EC: addiu       $t7, $zero, 0x3FF
    ctx->r15 = ADD32(0, 0X3FF);
    // 0x800307F0: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800307F4: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800307F8: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800307FC: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80030800: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80030804: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80030808: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8003080C: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80030810: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x80030814: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x80030818: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x8003081C: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80030820: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80030824: sh          $t6, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r14;
    // 0x80030828: sh          $t7, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r15;
    // 0x8003082C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80030830: jr          $ra
    // 0x80030834: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    return;
    // 0x80030834: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
;}
RECOMP_FUNC void obj_init_seamonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003CF04: jr          $ra
    // 0x8003CF08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003CF08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void music_sequence_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002110: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80002114: lw          $t6, 0x5CF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5CF8);
    // 0x80002118: nop

    // 0x8000211C: lbu         $v0, 0x3($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X3);
    // 0x80002120: jr          $ra
    // 0x80002124: nop

    return;
    // 0x80002124: nop

;}
RECOMP_FUNC void obj_loop_flycoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D2B8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003D2BC: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003D2C0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003D2C4: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003D2C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003D2CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D2D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D2D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003D2D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003D2DC: bne         $t7, $zero, L_8003D2FC
    if (ctx->r15 != 0) {
        // 0x8003D2E0: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8003D2FC;
    }
    // 0x8003D2E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003D2E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D2E8: lwc1        $f9, 0x6188($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6188);
    // 0x8003D2EC: lwc1        $f8, 0x618C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X618C);
    // 0x8003D2F0: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D2F4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003D2F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8003D2FC:
    // 0x8003D2FC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003D300: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003D304: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003D308: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8003D30C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8003D310: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D314: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D318: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003D31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D320: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x8003D324: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8003D328: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D32C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003D330: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x8003D334: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D338: nop

    // 0x8003D33C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003D340: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003D344: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003D348: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003D34C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8003D350: jal         0x80011570
    // 0x8003D354: nop

    move_object(rdram, ctx);
        goto after_0;
    // 0x8003D354: nop

    after_0:
    // 0x8003D358: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x8003D35C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D364: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8003D368: bgtz        $t0, L_8003D3C8
    if (SIGNED(ctx->r8) > 0) {
        // 0x8003D36C: sw          $t0, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->r8;
            goto L_8003D3C8;
    }
    // 0x8003D36C: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
    // 0x8003D370: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8003D374: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003D378: lb          $t2, 0x193($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X193);
    // 0x8003D37C: nop

    // 0x8003D380: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8003D384: sb          $t3, 0x193($v0)
    MEM_B(0X193, ctx->r2) = ctx->r11;
    // 0x8003D388: lb          $t4, 0x193($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X193);
    // 0x8003D38C: nop

    // 0x8003D390: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x8003D394: bne         $at, $zero, L_8003D3A0
    if (ctx->r1 != 0) {
        // 0x8003D398: nop
    
            goto L_8003D3A0;
    }
    // 0x8003D398: nop

    // 0x8003D39C: sb          $t5, 0x1D8($v0)
    MEM_B(0X1D8, ctx->r2) = ctx->r13;
L_8003D3A0:
    // 0x8003D3A0: jal         0x8000FFB8
    // 0x8003D3A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8003D3A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003D3A8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8003D3AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003D3B0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8003D3B4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8003D3B8: beq         $t6, $at, L_8003D3CC
    if (ctx->r14 == ctx->r1) {
        // 0x8003D3BC: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_8003D3CC;
    }
    // 0x8003D3BC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D3C0: jal         0x80001D04
    // 0x8003D3C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8003D3C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8003D3C8:
    // 0x8003D3C8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_8003D3CC:
    // 0x8003D3CC: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x8003D3D0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8003D3D4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8003D3D8: sh          $t0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r8;
    // 0x8003D3DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D3E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D3E4: jr          $ra
    // 0x8003D3E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003D3E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void rain_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD4B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AD4BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AD4C0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AD4C4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800AD4C8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AD4CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AD4D0: jal         0x80066210
    // 0x800AD4D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800AD4D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800AD4D8: bne         $v0, $zero, L_800AD63C
    if (ctx->r2 != 0) {
        // 0x800AD4DC: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800AD63C;
    }
    // 0x800AD4DC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AD4E0: lw          $t6, 0x2C5C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2C5C);
    // 0x800AD4E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD4E8: beq         $t6, $zero, L_800AD63C
    if (ctx->r14 == 0) {
        // 0x800AD4EC: addiu       $v1, $v1, 0x2C78
        ctx->r3 = ADD32(ctx->r3, 0X2C78);
            goto L_800AD63C;
    }
    // 0x800AD4EC: addiu       $v1, $v1, 0x2C78
    ctx->r3 = ADD32(ctx->r3, 0X2C78);
    // 0x800AD4F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AD4F4: nop

    // 0x800AD4F8: blez        $v0, L_800AD588
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AD4FC: slt         $at, $s2, $v0
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800AD588;
    }
    // 0x800AD4FC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800AD500: beq         $at, $zero, L_800AD560
    if (ctx->r1 == 0) {
        // 0x800AD504: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800AD560;
    }
    // 0x800AD504: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD508: subu        $t7, $v0, $s2
    ctx->r15 = SUB32(ctx->r2, ctx->r18);
    // 0x800AD50C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800AD510: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AD514: lw          $t9, 0x2C64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2C64);
    // 0x800AD518: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AD51C: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AD520: addiu       $s0, $s0, 0x2C60
    ctx->r16 = ADD32(ctx->r16, 0X2C60);
    // 0x800AD524: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800AD528: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AD52C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD530: addiu       $a0, $a0, 0x2C6C
    ctx->r4 = ADD32(ctx->r4, 0X2C6C);
    // 0x800AD534: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800AD538: mflo        $t0
    ctx->r8 = lo;
    // 0x800AD53C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800AD540: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800AD544: lw          $t3, 0x2C70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2C70);
    // 0x800AD548: nop

    // 0x800AD54C: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AD550: mflo        $t4
    ctx->r12 = lo;
    // 0x800AD554: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800AD558: b           L_800AD588
    // 0x800AD55C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_800AD588;
    // 0x800AD55C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_800AD560:
    // 0x800AD560: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AD564: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AD568: lw          $t6, 0x2C68($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2C68);
    // 0x800AD56C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AD570: addiu       $s0, $s0, 0x2C60
    ctx->r16 = ADD32(ctx->r16, 0X2C60);
    // 0x800AD574: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AD578: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AD57C: lw          $t7, 0x2C74($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2C74);
    // 0x800AD580: addiu       $a0, $a0, 0x2C6C
    ctx->r4 = ADD32(ctx->r4, 0X2C6C);
    // 0x800AD584: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800AD588:
    // 0x800AD588: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AD58C: addiu       $s0, $s0, 0x2C60
    ctx->r16 = ADD32(ctx->r16, 0X2C60);
    // 0x800AD590: jal         0x800ADBC8
    // 0x800AD594: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rain_sound(rdram, ctx);
        goto after_1;
    // 0x800AD594: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800AD598: jal         0x800AD658
    // 0x800AD59C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rain_render_splashes(rdram, ctx);
        goto after_2;
    // 0x800AD59C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800AD5A0: jal         0x800ADAB8
    // 0x800AD5A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rain_lightning(rdram, ctx);
        goto after_3;
    // 0x800AD5A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x800AD5A8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800AD5AC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800AD5B0: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x800AD5B4: bne         $at, $zero, L_800AD63C
    if (ctx->r1 != 0) {
        // 0x800AD5B8: addiu       $s3, $s3, 0x7C0C
        ctx->r19 = ADD32(ctx->r19, 0X7C0C);
            goto L_800AD63C;
    }
    // 0x800AD5B8: addiu       $s3, $s3, 0x7C0C
    ctx->r19 = ADD32(ctx->r19, 0X7C0C);
    // 0x800AD5BC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AD5C0: addiu       $a1, $a1, 0x7C10
    ctx->r5 = ADD32(ctx->r5, 0X7C10);
    // 0x800AD5C4: jal         0x80067F2C
    // 0x800AD5C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mtx_ortho(rdram, ctx);
        goto after_4;
    // 0x800AD5C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x800AD5CC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AD5D0: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800AD5D4: addiu       $s1, $s1, 0x2C5C
    ctx->r17 = ADD32(ctx->r17, 0X2C5C);
    // 0x800AD5D8: addiu       $s0, $s0, 0x2C2C
    ctx->r16 = ADD32(ctx->r16, 0X2C2C);
    // 0x800AD5DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800AD5E0:
    // 0x800AD5E0: jal         0x800ADCBC
    // 0x800AD5E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    rain_render(rdram, ctx);
        goto after_5;
    // 0x800AD5E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x800AD5E8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800AD5EC: bne         $s0, $s1, L_800AD5E0
    if (ctx->r16 != ctx->r17) {
        // 0x800AD5F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800AD5E0;
    }
    // 0x800AD5F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD5F4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800AD5F8: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x800AD5FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AD600: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800AD604: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800AD608: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800AD60C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800AD610: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800AD614: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800AD618: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800AD61C: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x800AD620: addiu       $t4, $zero, -0x100
    ctx->r12 = ADD32(0, -0X100);
    // 0x800AD624: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800AD628: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800AD62C: jal         0x8007B3D0
    // 0x800AD630: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    rendermode_reset(rdram, ctx);
        goto after_6;
    // 0x800AD630: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_6:
    // 0x800AD634: jal         0x800682AC
    // 0x800AD638: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    viewport_reset(rdram, ctx);
        goto after_7;
    // 0x800AD638: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
L_800AD63C:
    // 0x800AD63C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AD640: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AD644: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AD648: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD64C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AD650: jr          $ra
    // 0x800AD654: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AD654: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void load_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F92C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F930: lw          $a0, -0x2BC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2BC8);
    // 0x8006F934: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F938: jr          $ra
    // 0x8006F93C: sw          $a0, -0x2BCC($at)
    MEM_W(-0X2BCC, ctx->r1) = ctx->r4;
    return;
    // 0x8006F93C: sw          $a0, -0x2BCC($at)
    MEM_W(-0X2BCC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void snow_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABB34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800ABB38: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800ABB3C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800ABB40: addiu       $s4, $s4, 0x28D8
    ctx->r20 = ADD32(ctx->r20, 0X28D8);
    // 0x800ABB44: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x800ABB48: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800ABB4C: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800ABB50: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800ABB54: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800ABB58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800ABB5C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800ABB60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ABB64: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800ABB68: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800ABB6C: bne         $v0, $zero, L_800ABB78
    if (ctx->r2 != 0) {
        // 0x800ABB70: nop
    
            goto L_800ABB78;
    }
    // 0x800ABB70: nop

    // 0x800ABB74: break       7
    do_break(2148186996);
L_800ABB78:
    // 0x800ABB78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ABB7C: bne         $v0, $at, L_800ABB90
    if (ctx->r2 != ctx->r1) {
        // 0x800ABB80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800ABB90;
    }
    // 0x800ABB80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ABB84: bne         $t6, $at, L_800ABB90
    if (ctx->r14 != ctx->r1) {
        // 0x800ABB88: nop
    
            goto L_800ABB90;
    }
    // 0x800ABB88: nop

    // 0x800ABB8C: break       6
    do_break(2148187020);
L_800ABB90:
    // 0x800ABB90: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800ABB94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800ABB98: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800ABB9C: lui         $s6, 0xFFFC
    ctx->r22 = S32(0XFFFC << 16);
    // 0x800ABBA0: mflo        $s5
    ctx->r21 = lo;
    // 0x800ABBA4: blez        $v0, L_800ABC18
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800ABBA8: or          $s3, $s1, $zero
        ctx->r19 = ctx->r17 | 0;
            goto L_800ABC18;
    }
L_800ABBA8:
    // 0x800ABBA8: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x800ABBAC: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800ABBB0: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800ABBB4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x800ABBB8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800ABBBC: jal         0x8007082C
    // 0x800ABBC0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    coss_s16(rdram, ctx);
        goto after_0;
    // 0x800ABBC0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x800ABBC4: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800ABBC8: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x800ABBCC: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800ABBD0: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800ABBD4: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800ABBD8: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x800ABBDC: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800ABBE0: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800ABBE4: sw          $s6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r22;
    // 0x800ABBE8: jal         0x80070830
    // 0x800ABBEC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    sins_s16(rdram, ctx);
        goto after_1;
    // 0x800ABBEC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_1:
    // 0x800ABBF0: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800ABBF4: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800ABBF8: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABBFC: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x800ABC00: lw          $t9, 0x4($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X4);
    // 0x800ABC04: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800ABC08: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800ABC0C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800ABC10: bne         $at, $zero, L_800ABBA8
    if (ctx->r1 != 0) {
        // 0x800ABC14: addu        $s1, $s1, $s5
        ctx->r17 = ADD32(ctx->r17, ctx->r21);
            goto L_800ABBA8;
    }
    // 0x800ABC14: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_800ABC18:
    // 0x800ABC18: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800ABC1C: lw          $t1, 0x291C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X291C);
    // 0x800ABC20: nop

    // 0x800ABC24: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800ABC28: jal         0x8007AE74
    // 0x800ABC2C: nop

    load_texture(rdram, ctx);
        goto after_2;
    // 0x800ABC2C: nop

    after_2:
    // 0x800ABC30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800ABC34: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // 0x800ABC38: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800ABC3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ABC40: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABC44: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800ABC48: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800ABC4C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800ABC50: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800ABC54: jr          $ra
    // 0x800ABC58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800ABC58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void string_to_font_codes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076A38: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80076A3C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80076A40: beq         $t6, $zero, L_80076AA4
    if (ctx->r14 == 0) {
        // 0x80076A44: nop
    
            goto L_80076AA4;
    }
    // 0x80076A44: nop

    // 0x80076A48: beq         $a2, $zero, L_80076AA4
    if (ctx->r6 == 0) {
        // 0x80076A4C: addiu       $t1, $zero, 0x41
        ctx->r9 = ADD32(0, 0X41);
            goto L_80076AA4;
    }
    // 0x80076A4C: addiu       $t1, $zero, 0x41
    ctx->r9 = ADD32(0, 0X41);
L_80076A50:
    // 0x80076A50: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076A54: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80076A58: lbu         $a3, 0x0($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X0);
    // 0x80076A5C: addiu       $t0, $t0, -0x1BBC
    ctx->r8 = ADD32(ctx->r8, -0X1BBC);
    // 0x80076A60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076A64:
    // 0x80076A64: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x80076A68: nop

    // 0x80076A6C: bne         $a3, $t7, L_80076A80
    if (ctx->r7 != ctx->r15) {
        // 0x80076A70: nop
    
            goto L_80076A80;
    }
    // 0x80076A70: nop

    // 0x80076A74: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80076A78: b           L_80076A8C
    // 0x80076A7C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80076A8C;
    // 0x80076A7C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80076A80:
    // 0x80076A80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80076A84: bne         $v0, $t1, L_80076A64
    if (ctx->r2 != ctx->r9) {
        // 0x80076A88: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80076A64;
    }
    // 0x80076A88: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80076A8C:
    // 0x80076A8C: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80076A90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80076A94: beq         $t8, $zero, L_80076AA4
    if (ctx->r24 == 0) {
        // 0x80076A98: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80076AA4;
    }
    // 0x80076A98: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076A9C: bne         $a2, $zero, L_80076A50
    if (ctx->r6 != 0) {
        // 0x80076AA0: nop
    
            goto L_80076A50;
    }
    // 0x80076AA0: nop

L_80076AA4:
    // 0x80076AA4: beq         $a2, $zero, L_80076AE8
    if (ctx->r6 == 0) {
        // 0x80076AA8: andi        $a0, $a2, 0x3
        ctx->r4 = ctx->r6 & 0X3;
            goto L_80076AE8;
    }
    // 0x80076AA8: andi        $a0, $a2, 0x3
    ctx->r4 = ctx->r6 & 0X3;
    // 0x80076AAC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80076AB0: beq         $a0, $zero, L_80076ACC
    if (ctx->r4 == 0) {
        // 0x80076AB4: addu        $v0, $a0, $a2
        ctx->r2 = ADD32(ctx->r4, ctx->r6);
            goto L_80076ACC;
    }
    // 0x80076AB4: addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
L_80076AB8:
    // 0x80076AB8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076ABC: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076AC0: bne         $v0, $a2, L_80076AB8
    if (ctx->r2 != ctx->r6) {
        // 0x80076AC4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80076AB8;
    }
    // 0x80076AC4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80076AC8: beq         $a2, $zero, L_80076AE8
    if (ctx->r6 == 0) {
        // 0x80076ACC: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80076AE8;
    }
L_80076ACC:
    // 0x80076ACC: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80076AD0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076AD4: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x80076AD8: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x80076ADC: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x80076AE0: bne         $a2, $zero, L_80076ACC
    if (ctx->r6 != 0) {
        // 0x80076AE4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80076ACC;
    }
    // 0x80076AE4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80076AE8:
    // 0x80076AE8: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076AEC: jr          $ra
    // 0x80076AF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80076AF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void music_volume_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000CBC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CC0: sw          $zero, 0x5D38($at)
    MEM_W(0X5D38, ctx->r1) = 0;
    // 0x80000CC4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CC8: sw          $zero, 0x5D3C($at)
    MEM_W(0X5D3C, ctx->r1) = 0;
    // 0x80000CCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000CD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80000CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000CD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000CE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000CE4: lbu         $a0, -0x39C8($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X39C8);
    // 0x80000CE8: jal         0x80001990
    // 0x80000CEC: swc1        $f4, -0x39B0($at)
    MEM_W(-0X39B0, ctx->r1) = ctx->f4.u32l;
    music_volume_set(rdram, ctx);
        goto after_0;
    // 0x80000CEC: swc1        $f4, -0x39B0($at)
    MEM_W(-0X39B0, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80000CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000CF8: jr          $ra
    // 0x80000CFC: nop

    return;
    // 0x80000CFC: nop

;}
RECOMP_FUNC void set_racer_tail_lights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F77C: lbu         $t6, 0x20A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X20A);
    // 0x8004F780: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8004F784: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8004F788: sb          $t7, 0x20A($a0)
    MEM_B(0X20A, ctx->r4) = ctx->r15;
    // 0x8004F78C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004F790: lw          $t8, -0x2AD8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AD8);
    // 0x8004F794: ori         $t1, $t7, 0x80
    ctx->r9 = ctx->r15 | 0X80;
    // 0x8004F798: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x8004F79C: beq         $t9, $zero, L_8004F7A8
    if (ctx->r25 == 0) {
        // 0x8004F7A0: nop
    
            goto L_8004F7A8;
    }
    // 0x8004F7A0: nop

    // 0x8004F7A4: sb          $t1, 0x20A($a0)
    MEM_B(0X20A, ctx->r4) = ctx->r9;
L_8004F7A8:
    // 0x8004F7A8: lbu         $v0, 0x20A($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X20A);
    // 0x8004F7AC: nop

    // 0x8004F7B0: andi        $t2, $v0, 0xC0
    ctx->r10 = ctx->r2 & 0XC0;
    // 0x8004F7B4: beq         $t2, $zero, L_8004F7D4
    if (ctx->r10 == 0) {
        // 0x8004F7B8: andi        $v1, $v0, 0xF
        ctx->r3 = ctx->r2 & 0XF;
            goto L_8004F7D4;
    }
    // 0x8004F7B8: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x8004F7BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004F7C0: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8004F7C4: bne         $at, $zero, L_8004F7E8
    if (ctx->r1 != 0) {
        // 0x8004F7C8: andi        $t3, $v0, 0xFFF0
        ctx->r11 = ctx->r2 & 0XFFF0;
            goto L_8004F7E8;
    }
    // 0x8004F7C8: andi        $t3, $v0, 0xFFF0
    ctx->r11 = ctx->r2 & 0XFFF0;
    // 0x8004F7CC: b           L_8004F7E4
    // 0x8004F7D0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8004F7E4;
    // 0x8004F7D0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8004F7D4:
    // 0x8004F7D4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004F7D8: bgez        $v1, L_8004F7E8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004F7DC: andi        $t3, $v0, 0xFFF0
        ctx->r11 = ctx->r2 & 0XFFF0;
            goto L_8004F7E8;
    }
    // 0x8004F7DC: andi        $t3, $v0, 0xFFF0
    ctx->r11 = ctx->r2 & 0XFFF0;
    // 0x8004F7E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004F7E4:
    // 0x8004F7E4: andi        $t3, $v0, 0xFFF0
    ctx->r11 = ctx->r2 & 0XFFF0;
L_8004F7E8:
    // 0x8004F7E8: or          $t4, $t3, $v1
    ctx->r12 = ctx->r11 | ctx->r3;
    // 0x8004F7EC: jr          $ra
    // 0x8004F7F0: sb          $t4, 0x20A($a0)
    MEM_B(0X20A, ctx->r4) = ctx->r12;
    return;
    // 0x8004F7F0: sb          $t4, 0x20A($a0)
    MEM_B(0X20A, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void func_80021400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021400: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021404: lh          $v1, -0x5188($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X5188);
    // 0x80021408: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8002140C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80021410: blez        $v1, L_80021470
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80021414: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80021470;
    }
    // 0x80021414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021418: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002141C: lw          $a1, -0x518C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X518C);
    // 0x80021420: nop

    // 0x80021424: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80021428: nop

    // 0x8002142C: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x80021430: nop

    // 0x80021434: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80021438: beq         $t6, $t9, L_80021474
    if (ctx->r14 == ctx->r25) {
        // 0x8002143C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80021474;
    }
    // 0x8002143C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80021440:
    // 0x80021440: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80021444: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021448: beq         $at, $zero, L_80021470
    if (ctx->r1 == 0) {
        // 0x8002144C: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_80021470;
    }
    // 0x8002144C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80021450: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x80021454: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80021458: nop

    // 0x8002145C: lw          $t3, 0x7C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X7C);
    // 0x80021460: nop

    // 0x80021464: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80021468: bne         $a0, $t4, L_80021440
    if (ctx->r4 != ctx->r12) {
        // 0x8002146C: nop
    
            goto L_80021440;
    }
    // 0x8002146C: nop

L_80021470:
    // 0x80021470: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80021474:
    // 0x80021474: beq         $at, $zero, L_800214BC
    if (ctx->r1 == 0) {
        // 0x80021478: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800214BC;
    }
    // 0x80021478: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002147C: lw          $t5, -0x518C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X518C);
    // 0x80021480: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80021484: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80021488: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8002148C: nop

    // 0x80021490: lw          $v1, 0x64($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X64);
    // 0x80021494: nop

    // 0x80021498: beq         $v1, $zero, L_800214BC
    if (ctx->r3 == 0) {
        // 0x8002149C: nop
    
            goto L_800214BC;
    }
    // 0x8002149C: nop

    // 0x800214A0: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x800214A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800214A8: lh          $t9, 0x2A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2A);
    // 0x800214AC: nop

    // 0x800214B0: bgez        $t9, L_800214BC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800214B4: nop
    
            goto L_800214BC;
    }
    // 0x800214B4: nop

    // 0x800214B8: sh          $t0, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r8;
L_800214BC:
    // 0x800214BC: jr          $ra
    // 0x800214C0: nop

    return;
    // 0x800214C0: nop

;}
RECOMP_FUNC void enable_interupts_on_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B70D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B70D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B70D8: jal         0x800D2470
    // 0x800B70DC: nop

    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x800B70DC: nop

    after_0:
    // 0x800B70E0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800B70E4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800B70E8: beq         $a0, $t6, L_800B7134
    if (ctx->r4 == ctx->r14) {
        // 0x800B70EC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800B7134;
    }
    // 0x800B70EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B70F0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800B70F4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
L_800B70F8:
    // 0x800B70F8: bne         $v0, $zero, L_800B711C
    if (ctx->r2 != 0) {
        // 0x800B70FC: nop
    
            goto L_800B711C;
    }
    // 0x800B70FC: nop

    // 0x800B7100: lw          $t7, 0x118($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X118);
    // 0x800B7104: ori         $at, $at, 0xFE
    ctx->r1 = ctx->r1 | 0XFE;
    // 0x800B7108: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B710C: sw          $t8, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r24;
    // 0x800B7110: ori         $t0, $t8, 0x6C01
    ctx->r8 = ctx->r24 | 0X6C01;
    // 0x800B7114: b           L_800B7134
    // 0x800B7118: sw          $t0, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r8;
        goto L_800B7134;
    // 0x800B7118: sw          $t0, 0x118($v1)
    MEM_W(0X118, ctx->r3) = ctx->r8;
L_800B711C:
    // 0x800B711C: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    // 0x800B7120: nop

    // 0x800B7124: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800B7128: nop

    // 0x800B712C: bne         $a0, $v0, L_800B70F8
    if (ctx->r4 != ctx->r2) {
        // 0x800B7130: nop
    
            goto L_800B70F8;
    }
    // 0x800B7130: nop

L_800B7134:
    // 0x800B7134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7138: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B713C: jr          $ra
    // 0x800B7140: nop

    return;
    // 0x800B7140: nop

;}
RECOMP_FUNC void menu_ghost_data_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099A5C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80099A60: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80099A64: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80099A68: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80099A6C: addiu       $t6, $t6, 0x64F8
    ctx->r14 = ADD32(ctx->r14, 0X64F8);
    // 0x80099A70: lw          $a0, 0x64D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64D0);
    // 0x80099A74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80099A78: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80099A7C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80099A80: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80099A84: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80099A88: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80099A8C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80099A90: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80099A94: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80099A98: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80099A9C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80099AA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80099AA4: addiu       $a3, $a3, 0x64E4
    ctx->r7 = ADD32(ctx->r7, 0X64E4);
    // 0x80099AA8: addiu       $a2, $a2, 0x64EC
    ctx->r6 = ADD32(ctx->r6, 0X64EC);
    // 0x80099AAC: addiu       $a1, $a1, 0x64DC
    ctx->r5 = ADD32(ctx->r5, 0X64DC);
    // 0x80099AB0: jal         0x800756D4
    // 0x80099AB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800756D4(rdram, ctx);
        goto after_0;
    // 0x80099AB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80099AB8: bne         $v0, $zero, L_80099AC8
    if (ctx->r2 != 0) {
        // 0x80099ABC: sw          $v0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r2;
            goto L_80099AC8;
    }
    // 0x80099ABC: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80099AC0: jal         0x8009963C
    // 0x80099AC4: nop

    ghostmenu_generate(rdram, ctx);
        goto after_1;
    // 0x80099AC4: nop

    after_1:
L_80099AC8:
    // 0x80099AC8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80099ACC: jal         0x8009C674
    // 0x80099AD0: addiu       $a0, $a0, 0x1708
    ctx->r4 = ADD32(ctx->r4, 0X1708);
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x80099AD0: addiu       $a0, $a0, 0x1708
    ctx->r4 = ADD32(ctx->r4, 0X1708);
    after_2:
    // 0x80099AD4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80099AD8: jal         0x8009C8A4
    // 0x80099ADC: addiu       $a0, $a0, 0x174C
    ctx->r4 = ADD32(ctx->r4, 0X174C);
    menu_imagegroup_load(rdram, ctx);
        goto after_3;
    // 0x80099ADC: addiu       $a0, $a0, 0x174C
    ctx->r4 = ADD32(ctx->r4, 0X174C);
    after_3:
    // 0x80099AE0: jal         0x800C4170
    // 0x80099AE4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_4;
    // 0x80099AE4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80099AE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80099AEC: addiu       $v0, $v0, 0x6550
    ctx->r2 = ADD32(ctx->r2, 0X6550);
    // 0x80099AF0: lw          $s7, 0x38($v0)
    ctx->r23 = MEM_W(ctx->r2, 0X38);
    // 0x80099AF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099AF8: sw          $s7, 0x153C($at)
    MEM_W(0X153C, ctx->r1) = ctx->r23;
    // 0x80099AFC: lw          $fp, 0x3C($v0)
    ctx->r30 = MEM_W(ctx->r2, 0X3C);
    // 0x80099B00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099B04: sw          $fp, 0x1564($at)
    MEM_W(0X1564, ctx->r1) = ctx->r30;
    // 0x80099B08: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x80099B0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099B10: sw          $v1, 0x1594($at)
    MEM_W(0X1594, ctx->r1) = ctx->r3;
    // 0x80099B14: lw          $a0, 0x44($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X44);
    // 0x80099B18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099B1C: sw          $a0, 0x15BC($at)
    MEM_W(0X15BC, ctx->r1) = ctx->r4;
    // 0x80099B20: lw          $a1, 0x48($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X48);
    // 0x80099B24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099B28: sw          $a1, 0x15EC($at)
    MEM_W(0X15EC, ctx->r1) = ctx->r5;
    // 0x80099B2C: lw          $a2, 0x4C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4C);
    // 0x80099B30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099B34: sw          $a2, 0x1614($at)
    MEM_W(0X1614, ctx->r1) = ctx->r6;
    // 0x80099B38: lw          $a3, 0x50($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X50);
    // 0x80099B3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099B40: sw          $a3, 0x1644($at)
    MEM_W(0X1644, ctx->r1) = ctx->r7;
    // 0x80099B44: lw          $t1, 0x54($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X54);
    // 0x80099B48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099B4C: sw          $t1, 0x166C($at)
    MEM_W(0X166C, ctx->r1) = ctx->r9;
    // 0x80099B50: lw          $t2, 0x58($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X58);
    // 0x80099B54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099B58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80099B5C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80099B60: sw          $t2, 0x169C($at)
    MEM_W(0X169C, ctx->r1) = ctx->r10;
    // 0x80099B64: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x80099B68: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80099B6C: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x80099B70: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099B74: lw          $t3, 0x5C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X5C);
    // 0x80099B78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099B7C: sw          $t3, 0x16C4($at)
    MEM_W(0X16C4, ctx->r1) = ctx->r11;
    // 0x80099B80: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80099B84: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80099B88: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80099B8C: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80099B90: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80099B94: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80099B98: addiu       $t7, $t7, 0x153C
    ctx->r15 = ADD32(ctx->r15, 0X153C);
    // 0x80099B9C: addiu       $a1, $a1, 0x1594
    ctx->r5 = ADD32(ctx->r5, 0X1594);
    // 0x80099BA0: mflo        $t8
    ctx->r24 = lo;
    // 0x80099BA4: addu        $t3, $t0, $t8
    ctx->r11 = ADD32(ctx->r8, ctx->r24);
    // 0x80099BA8: xori        $t8, $t2, 0x1
    ctx->r24 = ctx->r10 ^ 0X1;
    // 0x80099BAC: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099BB0: sll         $t9, $t3, 3
    ctx->r25 = S32(ctx->r11 << 3);
    // 0x80099BB4: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x80099BB8: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x80099BBC: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x80099BC0: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x80099BC4: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x80099BC8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80099BCC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80099BD0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80099BD4: addiu       $a3, $a3, 0x169C
    ctx->r7 = ADD32(ctx->r7, 0X169C);
    // 0x80099BD8: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x80099BDC: mflo        $t9
    ctx->r25 = lo;
    // 0x80099BE0: addu        $t4, $t0, $t9
    ctx->r12 = ADD32(ctx->r8, ctx->r25);
    // 0x80099BE4: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x80099BE8: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x80099BEC: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x80099BF0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80099BF4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80099BF8: addiu       $t9, $t9, 0x15EC
    ctx->r25 = ADD32(ctx->r25, 0X15EC);
    // 0x80099BFC: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x80099C00: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80099C04: addiu       $t8, $t8, 0x1644
    ctx->r24 = ADD32(ctx->r24, 0X1644);
    // 0x80099C08: sw          $t7, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r15;
    // 0x80099C0C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80099C10: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    // 0x80099C14: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x80099C18: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80099C1C: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x80099C20: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099C24: or          $t5, $t7, $zero
    ctx->r13 = ctx->r15 | 0;
    // 0x80099C28: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x80099C2C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80099C30: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80099C34: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80099C38: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80099C3C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80099C40: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80099C44: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    // 0x80099C48: addu        $t6, $a3, $t4
    ctx->r14 = ADD32(ctx->r7, ctx->r12);
    // 0x80099C4C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80099C50: mflo        $t8
    ctx->r24 = lo;
    // 0x80099C54: addu        $ra, $t0, $t8
    ctx->r31 = ADD32(ctx->r8, ctx->r24);
    // 0x80099C58: xori        $t8, $t5, 0x1
    ctx->r24 = ctx->r13 ^ 0X1;
    // 0x80099C5C: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099C60: sll         $t9, $ra, 3
    ctx->r25 = S32(ctx->r31 << 3);
    // 0x80099C64: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80099C68: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x80099C6C: or          $ra, $t9, $zero
    ctx->r31 = ctx->r25 | 0;
    // 0x80099C70: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80099C74: sw          $fp, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r30;
    // 0x80099C78: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x80099C7C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80099C80: addiu       $s1, $t0, 0x2
    ctx->r17 = ADD32(ctx->r8, 0X2);
    // 0x80099C84: sw          $s7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r23;
    // 0x80099C88: sw          $fp, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r30;
    // 0x80099C8C: mflo        $t9
    ctx->r25 = lo;
    // 0x80099C90: addu        $s0, $t0, $t9
    ctx->r16 = ADD32(ctx->r8, ctx->r25);
    // 0x80099C94: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x80099C98: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x80099C9C: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80099CA0: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80099CA4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80099CA8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80099CAC: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x80099CB0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80099CB4: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x80099CB8: addu        $t6, $a3, $ra
    ctx->r14 = ADD32(ctx->r7, ctx->r31);
    // 0x80099CBC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80099CC0: andi        $t9, $s1, 0x1
    ctx->r25 = ctx->r17 & 0X1;
    // 0x80099CC4: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099CC8: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80099CCC: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80099CD0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80099CD4: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80099CD8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80099CDC: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x80099CE0: addu        $t8, $a3, $s0
    ctx->r24 = ADD32(ctx->r7, ctx->r16);
    // 0x80099CE4: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80099CE8: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80099CEC: addiu       $s4, $t0, 0x3
    ctx->r20 = ADD32(ctx->r8, 0X3);
    // 0x80099CF0: sw          $s7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r23;
    // 0x80099CF4: mflo        $t6
    ctx->r14 = lo;
    // 0x80099CF8: addu        $s2, $t0, $t6
    ctx->r18 = ADD32(ctx->r8, ctx->r14);
    // 0x80099CFC: xori        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 ^ 0X1;
    // 0x80099D00: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099D04: sll         $t7, $s2, 3
    ctx->r15 = S32(ctx->r18 << 3);
    // 0x80099D08: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x80099D0C: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80099D10: sw          $t8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r24;
    // 0x80099D14: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80099D18: sw          $fp, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r30;
    // 0x80099D1C: mflo        $t7
    ctx->r15 = lo;
    // 0x80099D20: addu        $s3, $t0, $t7
    ctx->r19 = ADD32(ctx->r8, ctx->r15);
    // 0x80099D24: sll         $t8, $s3, 3
    ctx->r24 = S32(ctx->r19 << 3);
    // 0x80099D28: addu        $t6, $a1, $t8
    ctx->r14 = ADD32(ctx->r5, ctx->r24);
    // 0x80099D2C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80099D30: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80099D34: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x80099D38: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80099D3C: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x80099D40: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80099D44: sw          $t8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r24;
    // 0x80099D48: addu        $t8, $a3, $s2
    ctx->r24 = ADD32(ctx->r7, ctx->r18);
    // 0x80099D4C: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80099D50: andi        $t7, $s4, 0x1
    ctx->r15 = ctx->r20 & 0X1;
    // 0x80099D54: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099D58: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x80099D5C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80099D60: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80099D64: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x80099D68: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80099D6C: sw          $t6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r14;
    // 0x80099D70: addu        $t6, $a3, $s3
    ctx->r14 = ADD32(ctx->r7, ctx->r19);
    // 0x80099D74: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80099D78: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80099D7C: sw          $s7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r23;
    // 0x80099D80: sw          $fp, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r30;
    // 0x80099D84: mflo        $t8
    ctx->r24 = lo;
    // 0x80099D88: addu        $s5, $t0, $t8
    ctx->r21 = ADD32(ctx->r8, ctx->r24);
    // 0x80099D8C: xori        $t8, $s4, 0x1
    ctx->r24 = ctx->r20 ^ 0X1;
    // 0x80099D90: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099D94: sll         $t9, $s5, 3
    ctx->r25 = S32(ctx->r21 << 3);
    // 0x80099D98: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x80099D9C: or          $s5, $t9, $zero
    ctx->r21 = ctx->r25 | 0;
    // 0x80099DA0: sw          $t6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r14;
    // 0x80099DA4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80099DA8: mflo        $t9
    ctx->r25 = lo;
    // 0x80099DAC: addu        $s6, $t0, $t9
    ctx->r22 = ADD32(ctx->r8, ctx->r25);
    // 0x80099DB0: sll         $t6, $s6, 3
    ctx->r14 = S32(ctx->r22 << 3);
    // 0x80099DB4: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x80099DB8: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    // 0x80099DBC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80099DC0: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x80099DC4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80099DC8: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x80099DCC: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80099DD0: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80099DD4: sw          $t6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r14;
    // 0x80099DD8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80099DDC: addu        $t6, $a3, $s5
    ctx->r14 = ADD32(ctx->r7, ctx->r21);
    // 0x80099DE0: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x80099DE4: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x80099DE8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80099DEC: sw          $t8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r24;
    // 0x80099DF0: addu        $t8, $a3, $s6
    ctx->r24 = ADD32(ctx->r7, ctx->r22);
    // 0x80099DF4: jal         0x8008E45C
    // 0x80099DF8: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    menu_init_vehicle_textures(rdram, ctx);
        goto after_5;
    // 0x80099DF8: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    after_5:
    // 0x80099DFC: jal         0x80094604
    // 0x80099E00: nop

    menu_racer_portraits(rdram, ctx);
        goto after_6;
    // 0x80099E00: nop

    after_6:
    // 0x80099E04: jal         0x8008E4B0
    // 0x80099E08: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_7;
    // 0x80099E08: nop

    after_7:
    // 0x80099E0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099E10: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x80099E14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099E18: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x80099E1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099E20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80099E24: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    // 0x80099E28: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80099E2C: addiu       $v0, $v0, -0xB84
    ctx->r2 = ADD32(ctx->r2, -0XB84);
    // 0x80099E30: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80099E34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099E38: bne         $t9, $zero, L_80099E54
    if (ctx->r25 != 0) {
        // 0x80099E3C: sw          $zero, 0x6498($at)
        MEM_W(0X6498, ctx->r1) = 0;
            goto L_80099E54;
    }
    // 0x80099E3C: sw          $zero, 0x6498($at)
    MEM_W(0X6498, ctx->r1) = 0;
    // 0x80099E40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80099E44: jal         0x800C01D8
    // 0x80099E48: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_8;
    // 0x80099E48: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_8:
    // 0x80099E4C: b           L_80099E60
    // 0x80099E50: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80099E60;
    // 0x80099E50: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80099E54:
    // 0x80099E54: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80099E58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80099E5C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80099E60:
    // 0x80099E60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80099E64: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80099E68: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80099E6C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80099E70: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80099E74: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80099E78: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80099E7C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80099E80: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80099E84: jr          $ra
    // 0x80099E88: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80099E88: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void init_object_shadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FBCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FBD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FBD4: sw          $a1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r5;
    // 0x8000FBD8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000FBDC: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x8000FBE0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000FBE4: lh          $t6, 0x32($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X32);
    // 0x8000FBE8: nop

    // 0x8000FBEC: beq         $t6, $zero, L_8000FC18
    if (ctx->r14 == 0) {
        // 0x8000FBF0: nop
    
            goto L_8000FC18;
    }
    // 0x8000FBF0: nop

    // 0x8000FBF4: lh          $a0, 0x34($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X34);
    // 0x8000FBF8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000FBFC: jal         0x8007AE74
    // 0x8000FC00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x8000FC00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000FC04: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FC08: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8000FC0C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8000FC10: lw          $v1, 0x40($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X40);
    // 0x8000FC14: nop

L_8000FC18:
    // 0x8000FC18: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000FC1C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8000FC20: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000FC24: sh          $t7, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r15;
    // 0x8000FC28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000FC2C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8000FC30: sw          $t8, -0x51B0($at)
    MEM_W(-0X51B0, ctx->r1) = ctx->r24;
    // 0x8000FC34: lw          $t9, 0x40($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X40);
    // 0x8000FC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FC3C: lh          $t0, 0x32($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X32);
    // 0x8000FC40: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8000FC44: beq         $t0, $zero, L_8000FC64
    if (ctx->r8 == 0) {
        // 0x8000FC48: nop
    
            goto L_8000FC64;
    }
    // 0x8000FC48: nop

    // 0x8000FC4C: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x8000FC50: nop

    // 0x8000FC54: bne         $t1, $zero, L_8000FC64
    if (ctx->r9 != 0) {
        // 0x8000FC58: nop
    
            goto L_8000FC64;
    }
    // 0x8000FC58: nop

    // 0x8000FC5C: b           L_8000FC64
    // 0x8000FC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FC64;
    // 0x8000FC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FC64:
    // 0x8000FC64: jr          $ra
    // 0x8000FC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000FC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void music_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001844: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001848: lw          $t6, -0x39B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X39B8);
    // 0x8000184C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001850: bne         $t6, $zero, L_80001868
    if (ctx->r14 != 0) {
        // 0x80001854: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80001868;
    }
    // 0x80001854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001858: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000185C: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80001860: jal         0x80002570
    // 0x80001864: nop

    music_sequence_stop(rdram, ctx);
        goto after_0;
    // 0x80001864: nop

    after_0:
L_80001868:
    // 0x80001868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000186C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001870: jr          $ra
    // 0x80001874: nop

    return;
    // 0x80001874: nop

;}
RECOMP_FUNC void __osGetActiveQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2470: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800D2474: jr          $ra
    // 0x800D2478: lw          $v0, 0x488C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X488C);
    return;
    // 0x800D2478: lw          $v0, 0x488C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X488C);
;}
RECOMP_FUNC void level_transition_begin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F140: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F144: addiu       $v0, $v0, -0x2C6C
    ctx->r2 = ADD32(ctx->r2, -0X2C6C);
    // 0x8006F148: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8006F14C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F154: bne         $t6, $zero, L_8006F1FC
    if (ctx->r14 != 0) {
        // 0x8006F158: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8006F1FC;
    }
    // 0x8006F158: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006F15C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F160: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8006F164: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F168: sb          $zero, 0x3524($at)
    MEM_B(0X3524, ctx->r1) = 0;
    // 0x8006F16C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F170: sb          $zero, 0x3526($at)
    MEM_B(0X3526, ctx->r1) = 0;
    // 0x8006F174: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006F178: bne         $a0, $at, L_8006F198
    if (ctx->r4 != ctx->r1) {
        // 0x8006F17C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006F198;
    }
    // 0x8006F17C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F180: addiu       $a0, $a0, -0x2BE4
    ctx->r4 = ADD32(ctx->r4, -0X2BE4);
    // 0x8006F184: jal         0x800C01D8
    // 0x8006F188: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F188: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006F18C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F190: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F194: addiu       $v0, $v0, -0x2C6C
    ctx->r2 = ADD32(ctx->r2, -0X2C6C);
L_8006F198:
    // 0x8006F198: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006F19C: bne         $a1, $at, L_8006F1C4
    if (ctx->r5 != ctx->r1) {
        // 0x8006F1A0: addiu       $t8, $zero, 0x11A
        ctx->r24 = ADD32(0, 0X11A);
            goto L_8006F1C4;
    }
    // 0x8006F1A0: addiu       $t8, $zero, 0x11A
    ctx->r24 = ADD32(0, 0X11A);
    // 0x8006F1A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F1A8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8006F1AC: addiu       $a0, $a0, -0x2BDC
    ctx->r4 = ADD32(ctx->r4, -0X2BDC);
    // 0x8006F1B0: jal         0x800C01D8
    // 0x8006F1B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8006F1B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8006F1B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F1BC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F1C0: addiu       $v0, $v0, -0x2C6C
    ctx->r2 = ADD32(ctx->r2, -0X2C6C);
L_8006F1C4:
    // 0x8006F1C4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006F1C8: bne         $a1, $at, L_8006F1F0
    if (ctx->r5 != ctx->r1) {
        // 0x8006F1CC: addiu       $t9, $zero, 0x168
        ctx->r25 = ADD32(0, 0X168);
            goto L_8006F1F0;
    }
    // 0x8006F1CC: addiu       $t9, $zero, 0x168
    ctx->r25 = ADD32(0, 0X168);
    // 0x8006F1D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F1D4: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8006F1D8: addiu       $a0, $a0, -0x2BDC
    ctx->r4 = ADD32(ctx->r4, -0X2BDC);
    // 0x8006F1DC: jal         0x800C01D8
    // 0x8006F1E0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8006F1E0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x8006F1E4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F1E8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006F1EC: addiu       $v0, $v0, -0x2C6C
    ctx->r2 = ADD32(ctx->r2, -0X2C6C);
L_8006F1F0:
    // 0x8006F1F0: bne         $a1, $zero, L_8006F1FC
    if (ctx->r5 != 0) {
        // 0x8006F1F4: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8006F1FC;
    }
    // 0x8006F1F4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8006F1F8: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_8006F1FC:
    // 0x8006F1FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F204: jr          $ra
    // 0x8006F208: nop

    return;
    // 0x8006F208: nop

;}
RECOMP_FUNC void racer_activate_magnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056E2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80056E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056E34: lb          $t6, 0x175($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X175);
    // 0x80056E38: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80056E3C: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x80056E40: sb          $t7, 0x175($a1)
    MEM_B(0X175, ctx->r5) = ctx->r15;
    // 0x80056E44: lb          $t8, 0x175($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X175);
    // 0x80056E48: nop

    // 0x80056E4C: bgez        $t8, L_80056E5C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80056E50: nop
    
            goto L_80056E5C;
    }
    // 0x80056E50: nop

    // 0x80056E54: b           L_80057038
    // 0x80056E58: sb          $zero, 0x175($a1)
    MEM_B(0X175, ctx->r5) = 0;
        goto L_80057038;
    // 0x80056E58: sb          $zero, 0x175($a1)
    MEM_B(0X175, ctx->r5) = 0;
L_80056E5C:
    // 0x80056E5C: lw          $v0, 0x140($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X140);
    // 0x80056E60: nop

    // 0x80056E64: bne         $v0, $zero, L_80056E74
    if (ctx->r2 != 0) {
        // 0x80056E68: nop
    
            goto L_80056E74;
    }
    // 0x80056E68: nop

    // 0x80056E6C: b           L_80057038
    // 0x80056E70: sb          $zero, 0x175($a3)
    MEM_B(0X175, ctx->r7) = 0;
        goto L_80057038;
    // 0x80056E70: sb          $zero, 0x175($a3)
    MEM_B(0X175, ctx->r7) = 0;
L_80056E74:
    // 0x80056E74: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80056E78: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80056E7C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80056E80: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80056E84: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80056E88: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80056E8C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80056E90: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80056E94: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80056E98: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80056E9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80056EA0: jal         0x800C9AD0
    // 0x80056EA4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80056EA4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x80056EA8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80056EAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80056EB0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80056EB4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80056EB8: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056EBC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80056EC0: bc1f        L_80056F64
    if (!c1cs) {
        // 0x80056EC4: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80056F64;
    }
    // 0x80056EC4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80056EC8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80056ECC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80056ED0: nop

    // 0x80056ED4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80056ED8: nop

    // 0x80056EDC: bc1f        L_80056F64
    if (!c1cs) {
        // 0x80056EE0: nop
    
            goto L_80056F64;
    }
    // 0x80056EE0: nop

    // 0x80056EE4: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80056EE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056EEC: beq         $t9, $at, L_80056EF8
    if (ctx->r25 == ctx->r1) {
        // 0x80056EF0: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_80056EF8;
    }
    // 0x80056EF0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80056EF4: sb          $t0, 0x1D3($a3)
    MEM_B(0X1D3, ctx->r7) = ctx->r8;
L_80056EF8:
    // 0x80056EF8: lbu         $t1, 0x20C($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X20C);
    // 0x80056EFC: sb          $zero, 0x203($a3)
    MEM_B(0X203, ctx->r7) = 0;
    // 0x80056F00: beq         $t1, $zero, L_80056F18
    if (ctx->r9 == 0) {
        // 0x80056F04: nop
    
            goto L_80056F18;
    }
    // 0x80056F04: nop

    // 0x80056F08: lb          $t2, 0x203($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X203);
    // 0x80056F0C: nop

    // 0x80056F10: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80056F14: sb          $t3, 0x203($a3)
    MEM_B(0X203, ctx->r7) = ctx->r11;
L_80056F18:
    // 0x80056F18: lw          $t4, 0x178($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X178);
    // 0x80056F1C: nop

    // 0x80056F20: bne         $t4, $zero, L_80056F6C
    if (ctx->r12 != 0) {
        // 0x80056F24: nop
    
            goto L_80056F6C;
    }
    // 0x80056F24: nop

    // 0x80056F28: lb          $t5, 0x1D8($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1D8);
    // 0x80056F2C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    // 0x80056F30: bne         $t5, $zero, L_80056F6C
    if (ctx->r13 != 0) {
        // 0x80056F34: addiu       $a1, $a3, 0x178
        ctx->r5 = ADD32(ctx->r7, 0X178);
            goto L_80056F6C;
    }
    // 0x80056F34: addiu       $a1, $a3, 0x178
    ctx->r5 = ADD32(ctx->r7, 0X178);
    // 0x80056F38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80056F3C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80056F40: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80056F44: jal         0x80001D04
    // 0x80056F48: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80056F48: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80056F4C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80056F50: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80056F54: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056F58: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80056F5C: b           L_80056F70
    // 0x80056F60: lw          $t6, 0x140($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X140);
        goto L_80056F70;
    // 0x80056F60: lw          $t6, 0x140($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X140);
L_80056F64:
    // 0x80056F64: b           L_80057038
    // 0x80056F68: sb          $zero, 0x175($a3)
    MEM_B(0X175, ctx->r7) = 0;
        goto L_80057038;
    // 0x80056F68: sb          $zero, 0x175($a3)
    MEM_B(0X175, ctx->r7) = 0;
L_80056F6C:
    // 0x80056F6C: lw          $t6, 0x140($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X140);
L_80056F70:
    // 0x80056F70: div.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80056F74: lw          $v0, 0x64($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X64);
    // 0x80056F78: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80056F7C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80056F80: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80056F84: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80056F88: div.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80056F8C: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80056F90: nop

    // 0x80056F94: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80056F98: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80056F9C: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80056FA0: nop

    // 0x80056FA4: bc1f        L_80056FCC
    if (!c1cs) {
        // 0x80056FA8: lui         $at, 0x4034
        ctx->r1 = S32(0X4034 << 16);
            goto L_80056FCC;
    }
    // 0x80056FA8: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80056FAC: lb          $t7, 0x195($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X195);
    // 0x80056FB0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80056FB4: bne         $t7, $zero, L_80056FC8
    if (ctx->r15 != 0) {
        // 0x80056FB8: nop
    
            goto L_80056FC8;
    }
    // 0x80056FB8: nop

    // 0x80056FBC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80056FC0: nop

    // 0x80056FC4: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80056FC8:
    // 0x80056FC8: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
L_80056FCC:
    // 0x80056FCC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80056FD0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80056FD4: c.lt.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d < ctx->f0.d;
    // 0x80056FD8: nop

    // 0x80056FDC: bc1f        L_80056FEC
    if (!c1cs) {
        // 0x80056FE0: nop
    
            goto L_80056FEC;
    }
    // 0x80056FE0: nop

    // 0x80056FE4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80056FE8: nop

L_80056FEC:
    // 0x80056FEC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80056FF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80056FF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80056FF8: add.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80056FFC: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80057000: nop

    // 0x80057004: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80057008: swc1        $f6, -0x2A88($at)
    MEM_W(-0X2A88, ctx->r1) = ctx->f6.u32l;
    // 0x8005700C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80057010: swc1        $f8, -0x2A84($at)
    MEM_W(-0X2A84, ctx->r1) = ctx->f8.u32l;
    // 0x80057014: lh          $t8, 0x18E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X18E);
    // 0x80057018: nop

    // 0x8005701C: beq         $t8, $zero, L_80057038
    if (ctx->r24 == 0) {
        // 0x80057020: nop
    
            goto L_80057038;
    }
    // 0x80057020: nop

    // 0x80057024: lb          $t9, 0x195($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X195);
    // 0x80057028: nop

    // 0x8005702C: bne         $t9, $zero, L_8005703C
    if (ctx->r25 != 0) {
        // 0x80057030: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005703C;
    }
    // 0x80057030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057034: sb          $zero, 0x175($a3)
    MEM_B(0X175, ctx->r7) = 0;
L_80057038:
    // 0x80057038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005703C:
    // 0x8005703C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80057040: jr          $ra
    // 0x80057044: nop

    return;
    // 0x80057044: nop

;}
RECOMP_FUNC void emitter_init_with_pos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF29C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AF2A0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AF2A4: lw          $t8, 0x2CFC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2CFC);
    // 0x800AF2A8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800AF2AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF2B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AF2B4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800AF2B8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AF2BC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800AF2C0: sh          $a2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r6;
    // 0x800AF2C4: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    // 0x800AF2C8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800AF2CC: lh          $t1, 0x3A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3A);
    // 0x800AF2D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AF2D4: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
    // 0x800AF2D8: lh          $t2, 0x3E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3E);
    // 0x800AF2DC: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
    // 0x800AF2E0: sh          $t2, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r10;
    // 0x800AF2E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AF2E8: addiu       $t4, $zero, 0x4000
    ctx->r12 = ADD32(0, 0X4000);
    // 0x800AF2EC: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x800AF2F0: beq         $t3, $zero, L_800AF314
    if (ctx->r11 == 0) {
        // 0x800AF2F4: andi        $t5, $v0, 0x400
        ctx->r13 = ctx->r2 & 0X400;
            goto L_800AF314;
    }
    // 0x800AF2F4: andi        $t5, $v0, 0x400
    ctx->r13 = ctx->r2 & 0X400;
    // 0x800AF2F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AF2FC: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
    // 0x800AF300: sb          $zero, 0x6($a0)
    MEM_B(0X6, ctx->r4) = 0;
    // 0x800AF304: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800AF308: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x800AF30C: b           L_800AF3F4
    // 0x800AF310: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
        goto L_800AF3F4;
    // 0x800AF310: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
L_800AF314:
    // 0x800AF314: beq         $t5, $zero, L_800AF3A8
    if (ctx->r13 == 0) {
        // 0x800AF318: addiu       $t6, $zero, 0x400
        ctx->r14 = ADD32(0, 0X400);
            goto L_800AF3A8;
    }
    // 0x800AF318: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x800AF31C: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x800AF320: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
    // 0x800AF324: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF328: lw          $t7, 0x2CF0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2CF0);
    // 0x800AF32C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800AF330: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AF334: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800AF338: lui         $a1, 0x8080
    ctx->r5 = S32(0X8080 << 16);
    // 0x800AF33C: lh          $v0, 0x8($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X8);
    // 0x800AF340: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800AF344: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800AF348: beq         $at, $zero, L_800AF358
    if (ctx->r1 == 0) {
        // 0x800AF34C: ori         $a1, $a1, 0x8080
        ctx->r5 = ctx->r5 | 0X8080;
            goto L_800AF358;
    }
    // 0x800AF34C: ori         $a1, $a1, 0x8080
    ctx->r5 = ctx->r5 | 0X8080;
    // 0x800AF350: b           L_800AF35C
    // 0x800AF354: sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
        goto L_800AF35C;
    // 0x800AF354: sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
L_800AF358:
    // 0x800AF358: sb          $t1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r9;
L_800AF35C:
    // 0x800AF35C: lbu         $a0, 0x7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7);
    // 0x800AF360: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800AF364: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800AF368: jal         0x80070C9C
    // 0x800AF36C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800AF36C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_0:
    // 0x800AF370: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800AF374: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x800AF378: lh          $t3, 0x14($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X14);
    // 0x800AF37C: nop

    // 0x800AF380: sh          $t3, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r11;
    // 0x800AF384: lh          $t4, 0x16($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X16);
    // 0x800AF388: nop

    // 0x800AF38C: sh          $t4, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r12;
    // 0x800AF390: lh          $t5, 0x22($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X22);
    // 0x800AF394: nop

    // 0x800AF398: sh          $t5, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r13;
    // 0x800AF39C: lh          $t6, 0x24($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X24);
    // 0x800AF3A0: b           L_800AF3F4
    // 0x800AF3A4: sh          $t6, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r14;
        goto L_800AF3F4;
    // 0x800AF3A4: sh          $t6, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r14;
L_800AF3A8:
    // 0x800AF3A8: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x800AF3AC: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x800AF3B0: nop

    // 0x800AF3B4: sh          $t7, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r15;
    // 0x800AF3B8: lh          $t8, 0x16($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X16);
    // 0x800AF3BC: nop

    // 0x800AF3C0: sh          $t8, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r24;
    // 0x800AF3C4: lh          $t9, 0x18($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X18);
    // 0x800AF3C8: nop

    // 0x800AF3CC: sh          $t9, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r25;
    // 0x800AF3D0: lh          $t0, 0x22($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X22);
    // 0x800AF3D4: nop

    // 0x800AF3D8: sh          $t0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r8;
    // 0x800AF3DC: lh          $t1, 0x24($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X24);
    // 0x800AF3E0: nop

    // 0x800AF3E4: sh          $t1, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r9;
    // 0x800AF3E8: lh          $t2, 0x26($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X26);
    // 0x800AF3EC: nop

    // 0x800AF3F0: sh          $t2, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r10;
L_800AF3F4:
    // 0x800AF3F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF3F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AF3FC: jr          $ra
    // 0x800AF400: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AF400: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mark_read_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECC4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006ECC8: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006ECCC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006ECD0: nop

    // 0x8006ECD4: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8006ECD8: jr          $ra
    // 0x8006ECDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006ECDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void get_character_id_from_slot_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C23C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C240: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C244: lb          $v0, 0x63F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X63F0);
    // 0x8009C248: jr          $ra
    // 0x8009C24C: nop

    return;
    // 0x8009C24C: nop

;}
RECOMP_FUNC void __allocParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065668: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006566C: lw          $v0, 0x3780($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3780);
    // 0x80065670: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80065674: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x80065678: nop

    // 0x8006567C: beq         $a0, $zero, L_80065694
    if (ctx->r4 == 0) {
        // 0x80065680: nop
    
            goto L_80065694;
    }
    // 0x80065680: nop

    // 0x80065684: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80065688: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8006568C: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x80065690: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80065694:
    // 0x80065694: jr          $ra
    // 0x80065698: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80065698: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mempool_print_tags_usb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071AE0: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071AE4: jal         0x80071A24
    // 0x80071AE8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_0;
    // 0x80071AE8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_0:
    // 0x80071AEC: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071AF0: jal         0x80071A24
    // 0x80071AF4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_1;
    // 0x80071AF4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x80071AF8: jal         0x80071A24
    // 0x80071AFC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_2;
    // 0x80071AFC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    after_2:
    // 0x80071B00: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x80071B04: jal         0x80071A24
    // 0x80071B08: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_3;
    // 0x80071B08: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_3:
    // 0x80071B0C: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071B10: jal         0x80071A24
    // 0x80071B14: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_4;
    // 0x80071B14: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_4:
    // 0x80071B18: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071B1C: jal         0x80071A24
    // 0x80071B20: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_5;
    // 0x80071B20: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_5:
    // 0x80071B24: jal         0x80071A24
    // 0x80071B28: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    get_memory_colour_tag_count(rdram, ctx);
        goto after_6;
    // 0x80071B28: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_6:
    // 0x80071B2C: lui         $a0, 0x7F7F
    ctx->r4 = S32(0X7F7F << 16);
    // 0x80071B30: jal         0x80071A24
    // 0x80071B34: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_7;
    // 0x80071B34: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_7:
    // 0x80071B38: lui         $a0, 0xFF7F
    ctx->r4 = S32(0XFF7F << 16);
    // 0x80071B3C: jal         0x80071A24
    // 0x80071B40: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_8;
    // 0x80071B40: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_8:
    // 0x80071B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071B4C: jr          $ra
    // 0x80071B50: nop

    return;
    // 0x80071B50: nop

;}
RECOMP_FUNC void _alFxEnabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006493C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80064940: lbu         $v0, -0x3150($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3150);
    // 0x80064944: jr          $ra
    // 0x80064948: nop

    return;
    // 0x80064948: nop

;}
RECOMP_FUNC void alHeapDBAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C77F0: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800C77F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C77F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C77FC: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7800: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800C7804: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C7808: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800C780C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800C7810: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C7814: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C7818: mflo        $v0
    ctx->r2 = lo;
    // 0x800C781C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800C7820: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800C7824: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x800C7828: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800C782C: bne         $at, $zero, L_800C783C
    if (ctx->r1 != 0) {
        // 0x800C7830: addu        $t2, $a0, $t7
        ctx->r10 = ADD32(ctx->r4, ctx->r15);
            goto L_800C783C;
    }
    // 0x800C7830: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x800C7834: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7838: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
L_800C783C:
    // 0x800C783C: jr          $ra
    // 0x800C7840: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C7840: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void level_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD88: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006BD8C: lw          $v0, 0x1164($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1164);
    // 0x8006BD90: jr          $ra
    // 0x8006BD94: nop

    return;
    // 0x8006BD94: nop

;}
RECOMP_FUNC void sprite_opaque(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BF1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007BF20: sw          $a0, -0x183C($at)
    MEM_W(-0X183C, ctx->r1) = ctx->r4;
    // 0x8007BF24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007BF28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007BF2C: jr          $ra
    // 0x8007BF30: sh          $t6, 0x6382($at)
    MEM_H(0X6382, ctx->r1) = ctx->r14;
    return;
    // 0x8007BF30: sh          $t6, 0x6382($at)
    MEM_H(0X6382, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void snow_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC5A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AC5A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AC5AC: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800AC5B0: addiu       $s1, $s1, 0x28D8
    ctx->r17 = ADD32(ctx->r17, 0X28D8);
    // 0x800AC5B4: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x800AC5B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AC5BC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800AC5C0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800AC5C4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AC5C8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AC5CC: beq         $t6, $zero, L_800AC82C
    if (ctx->r14 == 0) {
        // 0x800AC5D0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800AC82C;
    }
    // 0x800AC5D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AC5D4: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AC5D8: addiu       $s3, $s3, 0x2908
    ctx->r19 = ADD32(ctx->r19, 0X2908);
    // 0x800AC5DC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800AC5E0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800AC5E4: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800AC5E8: addiu       $s5, $s5, 0x7C04
    ctx->r21 = ADD32(ctx->r21, 0X7C04);
    // 0x800AC5EC: addiu       $s4, $s4, 0x7C00
    ctx->r20 = ADD32(ctx->r20, 0X7C00);
    // 0x800AC5F0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800AC5F4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800AC5F8: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x800AC5FC: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800AC600: bne         $at, $zero, L_800AC82C
    if (ctx->r1 != 0) {
        // 0x800AC604: sw          $t8, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r24;
            goto L_800AC82C;
    }
    // 0x800AC604: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x800AC608: jal         0x80069DB0
    // 0x800AC60C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    get_projection_matrix_s16(rdram, ctx);
        goto after_0;
    // 0x800AC60C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x800AC610: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800AC614: addiu       $s0, $s0, 0x7C0C
    ctx->r16 = ADD32(ctx->r16, 0X7C0C);
    // 0x800AC618: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800AC61C: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800AC620: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800AC624: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AC628: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x800AC62C: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x800AC630: addu        $t8, $v0, $t3
    ctx->r24 = ADD32(ctx->r2, ctx->r11);
    // 0x800AC634: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800AC638: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800AC63C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800AC640: lui         $t6, 0xBC00
    ctx->r14 = S32(0XBC00 << 16);
    // 0x800AC644: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800AC648: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AC64C: ori         $t6, $t6, 0xA
    ctx->r14 = ctx->r14 | 0XA;
    // 0x800AC650: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800AC654: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800AC658: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x800AC65C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AC660: jal         0x8007B4C8
    // 0x800AC664: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    material_set_no_tex_offset(rdram, ctx);
        goto after_1;
    // 0x800AC664: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x800AC668: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800AC66C: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800AC670: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800AC674: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AC678: beq         $at, $zero, L_800AC75C
    if (ctx->r1 == 0) {
        // 0x800AC67C: lui         $t3, 0x8000
        ctx->r11 = S32(0X8000 << 16);
            goto L_800AC75C;
    }
    // 0x800AC67C: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800AC680: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AC684: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AC688: addiu       $t5, $t5, 0x2904
    ctx->r13 = ADD32(ctx->r13, 0X2904);
    // 0x800AC68C: addiu       $s2, $s2, 0x290C
    ctx->r18 = ADD32(ctx->r18, 0X290C);
    // 0x800AC690: lui         $s1, 0x500
    ctx->r17 = S32(0X500 << 16);
    // 0x800AC694: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800AC698: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
L_800AC69C:
    // 0x800AC69C: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC6A0: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x800AC6A4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800AC6A8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800AC6AC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800AC6B0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AC6B4: mflo        $t7
    ctx->r15 = lo;
    // 0x800AC6B8: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x800AC6BC: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x800AC6C0: andi        $t8, $a3, 0x6
    ctx->r24 = ctx->r7 & 0X6;
    // 0x800AC6C4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800AC6C8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800AC6CC: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x800AC6D0: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800AC6D4: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800AC6D8: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800AC6DC: or          $t8, $t7, $ra
    ctx->r24 = ctx->r15 | ctx->r31;
    // 0x800AC6E0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800AC6E4: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800AC6E8: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800AC6EC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800AC6F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800AC6F4: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800AC6F8: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x800AC6FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800AC700: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x800AC704: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x800AC708: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800AC70C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800AC710: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800AC714: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800AC718: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800AC71C: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x800AC720: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800AC724: or          $t6, $t8, $s1
    ctx->r14 = ctx->r24 | ctx->r17;
    // 0x800AC728: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800AC72C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800AC730: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AC734: nop

    // 0x800AC738: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x800AC73C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800AC740: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800AC744: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800AC748: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800AC74C: addu        $t9, $t0, $v0
    ctx->r25 = ADD32(ctx->r8, ctx->r2);
    // 0x800AC750: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AC754: bne         $at, $zero, L_800AC69C
    if (ctx->r1 != 0) {
        // 0x800AC758: nop
    
            goto L_800AC69C;
    }
    // 0x800AC758: nop

L_800AC75C:
    // 0x800AC75C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800AC760: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC764: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AC768: addiu       $t5, $t5, 0x2904
    ctx->r13 = ADD32(ctx->r13, 0X2904);
    // 0x800AC76C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800AC770: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800AC774: subu        $v0, $t1, $t0
    ctx->r2 = SUB32(ctx->r9, ctx->r8);
    // 0x800AC778: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800AC77C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800AC780: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AC784: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800AC788: lui         $s1, 0x500
    ctx->r17 = S32(0X500 << 16);
    // 0x800AC78C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AC790: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC794: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x800AC798: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x800AC79C: andi        $t7, $a3, 0x6
    ctx->r15 = ctx->r7 & 0X6;
    // 0x800AC7A0: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x800AC7A4: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800AC7A8: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800AC7AC: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800AC7B0: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800AC7B4: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800AC7B8: or          $t7, $t8, $ra
    ctx->r15 = ctx->r24 | ctx->r31;
    // 0x800AC7BC: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800AC7C0: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800AC7C4: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x800AC7C8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800AC7CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800AC7D0: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800AC7D4: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800AC7D8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800AC7DC: subu        $a2, $t7, $t0
    ctx->r6 = SUB32(ctx->r15, ctx->r8);
    // 0x800AC7E0: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800AC7E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800AC7E8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800AC7EC: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800AC7F0: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x800AC7F4: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800AC7F8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800AC7FC: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800AC800: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800AC804: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x800AC808: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800AC80C: or          $t6, $t8, $s1
    ctx->r14 = ctx->r24 | ctx->r17;
    // 0x800AC810: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800AC814: addiu       $s2, $s2, 0x290C
    ctx->r18 = ADD32(ctx->r18, 0X290C);
    // 0x800AC818: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800AC81C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AC820: nop

    // 0x800AC824: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x800AC828: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800AC82C:
    // 0x800AC82C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AC830: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AC834: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AC838: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC83C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AC840: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800AC844: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800AC848: jr          $ra
    // 0x800AC84C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AC84C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void dialogue_close_stub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E9A8: jr          $ra
    // 0x8009E9AC: nop

    return;
    // 0x8009E9AC: nop

;}
