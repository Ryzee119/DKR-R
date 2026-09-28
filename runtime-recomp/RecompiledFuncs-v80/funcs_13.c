#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void alSynStopVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C98B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C98B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C98B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C98BC: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C98C0: beql        $t6, $zero, L_800C991C
    if (ctx->r14 == 0) {
        // 0x800C98C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C991C;
    }
    goto skip_0;
    // 0x800C98C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C98C8: jal         0x80065668
    // 0x800C98CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C98CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C98D0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C98D4: beq         $v0, $zero, L_800C9918
    if (ctx->r2 == 0) {
        // 0x800C98D8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9918;
    }
    // 0x800C98D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C98DC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C98E0: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C98E4: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800C98E8: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C98EC: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C98F0: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C98F4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C98F8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C98FC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9900: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800C9904: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9908: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800C990C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9910: jalr        $t9
    // 0x800C9914: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9914: nop

    after_1:
L_800C9918:
    // 0x800C9918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C991C:
    // 0x800C991C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9920: jr          $ra
    // 0x800C9924: nop

    return;
    // 0x800C9924: nop

;}
RECOMP_FUNC void audio_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000450: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80000454: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80000458: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000045C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80000460: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80000464: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80000468: lui         $a2, 0x2
    ctx->r6 = S32(0X2 << 16);
    // 0x8000046C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80000470: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80000474: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80000478: ori         $a2, $a2, 0x9D88
    ctx->r6 = ctx->r6 | 0X9D88;
    // 0x8000047C: addiu       $a1, $a1, -0x40A0
    ctx->r5 = ADD32(ctx->r5, -0X40A0);
    // 0x80000480: jal         0x800C7560
    // 0x80000484: addiu       $a0, $a0, 0x5CE8
    ctx->r4 = ADD32(ctx->r4, 0X5CE8);
    alHeapInit(rdram, ctx);
        goto after_0;
    // 0x80000484: addiu       $a0, $a0, 0x5CE8
    ctx->r4 = ADD32(ctx->r4, 0X5CE8);
    after_0:
    // 0x80000488: jal         0x80076C58
    // 0x8000048C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x8000048C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80000490: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80000494: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80000498: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8000049C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800004A0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800004A4: jal         0x80070C9C
    // 0x800004A8: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800004A8: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    after_2:
    // 0x800004AC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800004B0: addiu       $s0, $s0, 0x5D14
    ctx->r16 = ADD32(ctx->r16, 0X5D14);
    // 0x800004B4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800004B8: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x800004BC: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x800004C0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800004C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800004C8: jal         0x80076E68
    // 0x800004CC: subu        $a3, $t8, $a2
    ctx->r7 = SUB32(ctx->r24, ctx->r6);
    asset_load(rdram, ctx);
        goto after_3;
    // 0x800004CC: subu        $a3, $t8, $a2
    ctx->r7 = SUB32(ctx->r24, ctx->r6);
    after_3:
    // 0x800004D0: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x800004D4: jal         0x80076EE8
    // 0x800004D8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    asset_rom_offset(rdram, ctx);
        goto after_4;
    // 0x800004D8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_4:
    // 0x800004DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800004E0: jal         0x800C76A4
    // 0x800004E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alBnkfNew(rdram, ctx);
        goto after_5;
    // 0x800004E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x800004E8: lw          $t9, 0x1C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X1C);
    // 0x800004EC: lw          $t1, 0x18($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X18);
    // 0x800004F0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800004F4: addiu       $s0, $s0, 0x5D28
    ctx->r16 = ADD32(ctx->r16, 0X5D28);
    // 0x800004F8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800004FC: subu        $a0, $t9, $t1
    ctx->r4 = SUB32(ctx->r25, ctx->r9);
    // 0x80000500: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x80000504: jal         0x80070C9C
    // 0x80000508: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x80000508: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_6:
    // 0x8000050C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000510: addiu       $v1, $v1, 0x5D18
    ctx->r3 = ADD32(ctx->r3, 0X5D18);
    // 0x80000514: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80000518: lw          $a2, 0x18($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X18);
    // 0x8000051C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80000520: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80000524: jal         0x80076E68
    // 0x80000528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_7;
    // 0x80000528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8000052C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80000530: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80000534: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x80000538: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000053C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000540: addiu       $v1, $v1, 0x5D2C
    ctx->r3 = ADD32(ctx->r3, 0X5D2C);
    // 0x80000544: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80000548: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8000054C: mflo        $t4
    ctx->r12 = lo;
    // 0x80000550: sw          $t4, 0x5D20($at)
    MEM_W(0X5D20, ctx->r1) = ctx->r12;
    // 0x80000554: lw          $t6, 0x14($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X14);
    // 0x80000558: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    // 0x8000055C: nop

    // 0x80000560: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x80000564: jal         0x80070C9C
    // 0x80000568: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x80000568: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_8:
    // 0x8000056C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000570: addiu       $v1, $v1, 0x5D1C
    ctx->r3 = ADD32(ctx->r3, 0X5D1C);
    // 0x80000574: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80000578: addiu       $s0, $s0, 0x5D2C
    ctx->r16 = ADD32(ctx->r16, 0X5D2C);
    // 0x8000057C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80000580: lw          $a2, 0x14($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X14);
    // 0x80000584: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80000588: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8000058C: jal         0x80076E68
    // 0x80000590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_9;
    // 0x80000590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80000594: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80000598: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000059C: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x800005A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800005A4: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800005A8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800005AC: mflo        $t9
    ctx->r25 = lo;
    // 0x800005B0: sw          $t9, 0x5D24($at)
    MEM_W(0X5D24, ctx->r1) = ctx->r25;
    // 0x800005B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800005B8: jal         0x80070C9C
    // 0x800005BC: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_10;
    // 0x800005BC: nop

    after_10:
    // 0x800005C0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800005C4: addiu       $s0, $s0, 0x5D10
    ctx->r16 = ADD32(ctx->r16, 0X5D10);
    // 0x800005C8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800005CC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800005D0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800005D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800005D8: jal         0x80076E68
    // 0x800005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    asset_load(rdram, ctx);
        goto after_11;
    // 0x800005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x800005E0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800005E4: jal         0x80076EE8
    // 0x800005E8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    asset_rom_offset(rdram, ctx);
        goto after_12;
    // 0x800005E8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_12:
    // 0x800005EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800005F0: jal         0x800C76A4
    // 0x800005F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alBnkfNew(rdram, ctx);
        goto after_13;
    // 0x800005F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x800005F8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800005FC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80000600: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80000604: addiu       $a2, $a2, 0x5CE8
    ctx->r6 = ADD32(ctx->r6, 0X5CE8);
    // 0x80000608: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000060C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000610: jal         0x800C77F0
    // 0x80000614: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_14;
    // 0x80000614: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x80000618: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8000061C: addiu       $s0, $s0, 0x5CF8
    ctx->r16 = ADD32(ctx->r16, 0X5CF8);
    // 0x80000620: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80000624: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x80000628: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8000062C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80000630: jal         0x80076E68
    // 0x80000634: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    asset_load(rdram, ctx);
        goto after_15;
    // 0x80000634: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_15:
    // 0x80000638: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000063C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80000640: lh          $a3, 0x2($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X2);
    // 0x80000644: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80000648: sll         $t3, $a3, 3
    ctx->r11 = S32(ctx->r7 << 3);
    // 0x8000064C: addiu       $a0, $t3, 0x4
    ctx->r4 = ADD32(ctx->r11, 0X4);
    // 0x80000650: jal         0x80070C9C
    // 0x80000654: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_16;
    // 0x80000654: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_16:
    // 0x80000658: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000065C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80000660: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x80000664: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80000668: jal         0x80076E68
    // 0x8000066C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_17;
    // 0x8000066C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x80000670: lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10);
    // 0x80000674: jal         0x80076EE8
    // 0x80000678: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    asset_rom_offset(rdram, ctx);
        goto after_18;
    // 0x80000678: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_18:
    // 0x8000067C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000680: jal         0x800C77A8
    // 0x80000684: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alSeqFileNew(rdram, ctx);
        goto after_19;
    // 0x80000684: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_19:
    // 0x80000688: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000068C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80000690: lh          $a0, 0x2($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X2);
    // 0x80000694: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80000698: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8000069C: jal         0x80070C9C
    // 0x800006A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_20;
    // 0x800006A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_20:
    // 0x800006A4: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800006A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800006AC: addiu       $t0, $t0, 0x5D0C
    ctx->r8 = ADD32(ctx->r8, 0X5D0C);
    // 0x800006B0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800006B4: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800006B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800006BC: blez        $t6, L_80000744
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800006C0: addiu       $t5, $zero, 0x28
        ctx->r13 = ADD32(0, 0X28);
            goto L_80000744;
    }
    // 0x800006C0: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x800006C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800006C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800006CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800006D0:
    // 0x800006D0: addu        $t7, $a0, $a3
    ctx->r15 = ADD32(ctx->r4, ctx->r7);
    // 0x800006D4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800006D8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800006DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800006E0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800006E4: nop

    // 0x800006E8: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
    // 0x800006EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800006F0: nop

    // 0x800006F4: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800006F8: beq         $t1, $zero, L_80000718
    if (ctx->r9 == 0) {
        // 0x800006FC: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80000718;
    }
    // 0x800006FC: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80000700: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80000704: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80000708: nop

    // 0x8000070C: addu        $v1, $t3, $a1
    ctx->r3 = ADD32(ctx->r11, ctx->r5);
    // 0x80000710: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80000714: nop

L_80000718:
    // 0x80000718: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8000071C: beq         $at, $zero, L_80000728
    if (ctx->r1 == 0) {
        // 0x80000720: nop
    
            goto L_80000728;
    }
    // 0x80000720: nop

    // 0x80000724: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80000728:
    // 0x80000728: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000072C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80000730: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x80000734: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80000738: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000073C: bne         $at, $zero, L_800006D0
    if (ctx->r1 != 0) {
        // 0x80000740: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_800006D0;
    }
    // 0x80000740: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_80000744:
    // 0x80000744: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80000748: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8000074C: addiu       $t7, $zero, 0x60
    ctx->r15 = ADD32(0, 0X60);
    // 0x80000750: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80000754: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80000758: addiu       $t1, $t1, 0x5CE8
    ctx->r9 = ADD32(ctx->r9, 0X5CE8);
    // 0x8000075C: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x80000760: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x80000764: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x80000768: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x8000076C: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x80000770: sb          $t8, 0x8C($sp)
    MEM_B(0X8C, ctx->r29) = ctx->r24;
    // 0x80000774: sb          $t9, 0x8D($sp)
    MEM_B(0X8D, ctx->r29) = ctx->r25;
    // 0x80000778: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x8000077C: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x80000780: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80000784: jal         0x80002660
    // 0x80000788: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    amCreateAudioMgr(rdram, ctx);
        goto after_21;
    // 0x80000788: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_21:
    // 0x8000078C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80000790: jal         0x80002224
    // 0x80000794: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    sound_seqplayer_init(rdram, ctx);
        goto after_22;
    // 0x80000794: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_22:
    // 0x80000798: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000079C: addiu       $v1, $v1, -0x39D0
    ctx->r3 = ADD32(ctx->r3, -0X39D0);
    // 0x800007A0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800007A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800007A8: jal         0x8000B010
    // 0x800007AC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    set_voice_limit(rdram, ctx);
        goto after_23;
    // 0x800007AC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_23:
    // 0x800007B0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800007B4: jal         0x80002224
    // 0x800007B8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    sound_seqplayer_init(rdram, ctx);
        goto after_24;
    // 0x800007B8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_24:
    // 0x800007BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800007C0: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800007C4: sw          $v0, -0x39CC($at)
    MEM_W(-0X39CC, ctx->r1) = ctx->r2;
    // 0x800007C8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800007CC: jal         0x80070C9C
    // 0x800007D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_25;
    // 0x800007D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x800007D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800007D8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800007DC: sw          $v0, 0x5CFC($at)
    MEM_W(0X5CFC, ctx->r1) = ctx->r2;
    // 0x800007E0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800007E4: jal         0x80070C9C
    // 0x800007E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_26;
    // 0x800007E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x800007EC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800007F0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800007F4: addiu       $t2, $zero, 0x96
    ctx->r10 = ADD32(0, 0X96);
    // 0x800007F8: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800007FC: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80000800: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80000804: addiu       $t6, $t6, 0x5CE8
    ctx->r14 = ADD32(ctx->r14, 0X5CE8);
    // 0x80000808: sw          $v0, 0x5D00($at)
    MEM_W(0X5D00, ctx->r1) = ctx->r2;
    // 0x8000080C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80000810: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80000814: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80000818: sh          $t5, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r13;
    // 0x8000081C: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x80000820: jal         0x800031C0
    // 0x80000824: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    sndp_init_player(rdram, ctx);
        goto after_27;
    // 0x80000824: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_27:
    // 0x80000828: jal         0x80002A50
    // 0x8000082C: nop

    audioStartThread(rdram, ctx);
        goto after_28;
    // 0x8000082C: nop

    after_28:
    // 0x80000830: jal         0x80000968
    // 0x80000834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_29;
    // 0x80000834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_29:
    // 0x80000838: jal         0x80071140
    // 0x8000083C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_30;
    // 0x8000083C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_30:
    // 0x80000840: jal         0x8000318C
    // 0x80000844: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_31;
    // 0x80000844: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_31:
    // 0x80000848: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000084C: sw          $zero, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = 0;
    // 0x80000850: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000854: sb          $zero, 0x5D40($at)
    MEM_B(0X5D40, ctx->r1) = 0;
    // 0x80000858: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000085C: sb          $zero, 0x5D41($at)
    MEM_B(0X5D41, ctx->r1) = 0;
    // 0x80000860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000864: sw          $zero, -0x39A8($at)
    MEM_W(-0X39A8, ctx->r1) = 0;
    // 0x80000868: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000086C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000870: sb          $zero, 0x5F78($at)
    MEM_B(0X5F78, ctx->r1) = 0;
    // 0x80000874: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000878: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000087C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80000880: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80000884: sb          $zero, 0x5F79($at)
    MEM_B(0X5F79, ctx->r1) = 0;
    // 0x80000888: jr          $ra
    // 0x8000088C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8000088C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void emitter_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF1E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AF1E4: lw          $t6, 0x2CF4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2CF4);
    // 0x800AF1E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AF1EC: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AF1F0: beq         $at, $zero, L_800AF28C
    if (ctx->r1 == 0) {
        // 0x800AF1F4: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800AF28C;
    }
    // 0x800AF1F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF1F8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF1FC: lw          $t7, 0x2CFC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2CFC);
    // 0x800AF200: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AF204: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800AF208: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AF20C: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800AF210: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800AF214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AF218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AF21C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800AF220: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800AF224: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AF228: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AF22C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800AF230: nop

    // 0x800AF234: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AF238: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x800AF23C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AF240: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AF244: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AF248: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800AF24C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AF250: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AF254: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800AF258: nop

    // 0x800AF25C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AF260: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800AF264: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AF268: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AF26C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AF270: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AF274: nop

    // 0x800AF278: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AF27C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800AF280: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AF284: jal         0x800AF29C
    // 0x800AF288: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    emitter_init_with_pos(rdram, ctx);
        goto after_0;
    // 0x800AF288: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_0:
L_800AF28C:
    // 0x800AF28C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AF294: jr          $ra
    // 0x800AF298: nop

    return;
    // 0x800AF298: nop

;}
RECOMP_FUNC void set_anti_aliasing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028FA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028FA4: jr          $ra
    // 0x80028FA8: sw          $a0, -0x4F04($at)
    MEM_W(-0X4F04, ctx->r1) = ctx->r4;
    return;
    // 0x80028FA8: sw          $a0, -0x4F04($at)
    MEM_W(-0X4F04, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_init_unknown25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038A6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038A70: jr          $ra
    // 0x80038A74: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038A74: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void cam_shake_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800660D4: jr          $ra
    // 0x800660D8: sw          $zero, 0xD18($at)
    MEM_W(0XD18, ctx->r1) = 0;
    return;
    // 0x800660D8: sw          $zero, 0xD18($at)
    MEM_W(0XD18, ctx->r1) = 0;
;}
RECOMP_FUNC void obj_init_lavaspurt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037578: lbu         $t6, 0x9($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X9);
    // 0x8003757C: nop

    // 0x80037580: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80037584: sw          $t7, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r15;
    // 0x80037588: lbu         $t8, 0x8($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X8);
    // 0x8003758C: jr          $ra
    // 0x80037590: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
    return;
    // 0x80037590: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void racer_calc_distance_to_opponent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B834: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B838: lw          $v0, -0x5130($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5130);
    // 0x8001B83C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001B840: bgtz        $v0, L_8001B854
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001B844: nop
    
            goto L_8001B854;
    }
    // 0x8001B844: nop

    // 0x8001B848: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B84C: jr          $ra
    // 0x8001B850: nop

    return;
    // 0x8001B850: nop

L_8001B854:
    // 0x8001B854: lh          $a0, 0x190($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X190);
    // 0x8001B858: lh          $a3, 0x190($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X190);
    // 0x8001B85C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001B860: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001B864: beq         $at, $zero, L_8001B884
    if (ctx->r1 == 0) {
        // 0x8001B868: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001B884;
    }
    // 0x8001B868: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001B86C: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8001B870: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8001B874: lh          $a3, 0x190($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X190);
    // 0x8001B878: lh          $a0, 0x190($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X190);
    // 0x8001B87C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8001B880: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001B884:
    // 0x8001B884: lb          $t1, 0x192($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X192);
    // 0x8001B888: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001B88C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8001B890: beq         $at, $zero, L_8001B8D4
    if (ctx->r1 == 0) {
        // 0x8001B894: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_8001B8D4;
    }
    // 0x8001B894: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8001B898: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001B89C: lw          $a3, -0x5134($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5134);
    // 0x8001B8A0: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
L_8001B8A4:
    // 0x8001B8A4: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B8A8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8001B8AC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001B8B0: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001B8B4: mflo        $t6
    ctx->r14 = lo;
    // 0x8001B8B8: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8001B8BC: lwc1        $f4, 0x20($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8001B8C0: bne         $t0, $v0, L_8001B8CC
    if (ctx->r8 != ctx->r2) {
        // 0x8001B8C4: add.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_8001B8CC;
    }
    // 0x8001B8C4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001B8C8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001B8CC:
    // 0x8001B8CC: bne         $at, $zero, L_8001B8A4
    if (ctx->r1 != 0) {
        // 0x8001B8D0: nop
    
            goto L_8001B8A4;
    }
    // 0x8001B8D0: nop

L_8001B8D4:
    // 0x8001B8D4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001B8D8: addiu       $t0, $t1, -0x1
    ctx->r8 = ADD32(ctx->r9, -0X1);
    // 0x8001B8DC: lw          $a3, -0x5134($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5134);
    // 0x8001B8E0: bgez        $t0, L_8001B8EC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001B8E4: addiu       $t3, $zero, 0x3C
        ctx->r11 = ADD32(0, 0X3C);
            goto L_8001B8EC;
    }
    // 0x8001B8E4: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x8001B8E8: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
L_8001B8EC:
    // 0x8001B8EC: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B8F0: lwc1        $f8, 0xA8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XA8);
    // 0x8001B8F4: lb          $t0, 0x192($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X192);
    // 0x8001B8F8: nop

    // 0x8001B8FC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8001B900: mflo        $t8
    ctx->r24 = lo;
    // 0x8001B904: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8001B908: lwc1        $f6, 0x20($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8001B90C: nop

    // 0x8001B910: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001B914: bgez        $t0, L_8001B920
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001B918: add.s       $f2, $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
            goto L_8001B920;
    }
    // 0x8001B918: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8001B91C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
L_8001B920:
    // 0x8001B920: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B924: lwc1        $f18, 0xA8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XA8);
    // 0x8001B928: mflo        $t4
    ctx->r12 = lo;
    // 0x8001B92C: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x8001B930: lwc1        $f16, 0x20($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X20);
    // 0x8001B934: nop

    // 0x8001B938: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001B93C: beq         $v1, $zero, L_8001B948
    if (ctx->r3 == 0) {
        // 0x8001B940: sub.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_8001B948;
    }
    // 0x8001B940: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001B944: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8001B948:
    // 0x8001B948: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001B94C: jr          $ra
    // 0x8001B950: nop

    return;
    // 0x8001B950: nop

;}
RECOMP_FUNC void run_object_loop_func(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023F48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023F4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023F50: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80023F54: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80023F58: lh          $a1, 0x4A($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X4A);
    // 0x80023F5C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80023F60: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80023F64: jal         0x800B76B8
    // 0x80023F68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_0;
    // 0x80023F68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80023F6C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80023F70: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80023F74: lh          $t6, 0x48($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X48);
    // 0x80023F78: nop

    // 0x80023F7C: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80023F80: sltiu       $at, $t7, 0x76
    ctx->r1 = ctx->r15 < 0X76 ? 1 : 0;
    // 0x80023F84: beq         $at, $zero, L_80024570
    if (ctx->r1 == 0) {
        // 0x80023F88: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80024570;
    }
    // 0x80023F88: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80023F8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023F90: addu        $at, $at, $t7
    gpr jr_addend_80023F9C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80023F94: lw          $t7, 0x5C0C($at)
    ctx->r15 = ADD32(ctx->r1, 0X5C0C);
    // 0x80023F98: nop

    // 0x80023F9C: jr          $t7
    // 0x80023FA0: nop

    switch (jr_addend_80023F9C >> 2) {
        case 0: goto L_80023FA4; break;
        case 1: goto L_80023FB8; break;
        case 2: goto L_80023FCC; break;
        case 3: goto L_80024108; break;
        case 4: goto L_80023FE0; break;
        case 5: goto L_8002401C; break;
        case 6: goto L_80024570; break;
        case 7: goto L_80024570; break;
        case 8: goto L_80024030; break;
        case 9: goto L_80024044; break;
        case 10: goto L_80024058; break;
        case 11: goto L_8002406C; break;
        case 12: goto L_800240A8; break;
        case 13: goto L_800240BC; break;
        case 14: goto L_800240CC; break;
        case 15: goto L_800240E0; break;
        case 16: goto L_80024108; break;
        case 17: goto L_80024570; break;
        case 18: goto L_80024570; break;
        case 19: goto L_80024570; break;
        case 20: goto L_80024008; break;
        case 21: goto L_800240F4; break;
        case 22: goto L_80024570; break;
        case 23: goto L_80023FF4; break;
        case 24: goto L_8002411C; break;
        case 25: goto L_80024570; break;
        case 26: goto L_80024130; break;
        case 27: goto L_80024144; break;
        case 28: goto L_80024080; break;
        case 29: goto L_80024158; break;
        case 30: goto L_8002416C; break;
        case 31: goto L_80024570; break;
        case 32: goto L_80024570; break;
        case 33: goto L_80024570; break;
        case 34: goto L_80024180; break;
        case 35: goto L_800241A8; break;
        case 36: goto L_800241BC; break;
        case 37: goto L_800241D0; break;
        case 38: goto L_800241E4; break;
        case 39: goto L_80024094; break;
        case 40: goto L_80024570; break;
        case 41: goto L_80024570; break;
        case 42: goto L_80024570; break;
        case 43: goto L_800241F8; break;
        case 44: goto L_8002420C; break;
        case 45: goto L_80024220; break;
        case 46: goto L_80024570; break;
        case 47: goto L_80024570; break;
        case 48: goto L_80024234; break;
        case 49: goto L_8002425C; break;
        case 50: goto L_80024270; break;
        case 51: goto L_80024284; break;
        case 52: goto L_80024298; break;
        case 53: goto L_800242AC; break;
        case 54: goto L_800242C0; break;
        case 55: goto L_800242D4; break;
        case 56: goto L_800242E8; break;
        case 57: goto L_80024570; break;
        case 58: goto L_800242FC; break;
        case 59: goto L_8002430C; break;
        case 60: goto L_80024320; break;
        case 61: goto L_80024570; break;
        case 62: goto L_80024334; break;
        case 63: goto L_80024348; break;
        case 64: goto L_8002435C; break;
        case 65: goto L_80024194; break;
        case 66: goto L_80024370; break;
        case 67: goto L_80024384; break;
        case 68: goto L_80024398; break;
        case 69: goto L_80024570; break;
        case 70: goto L_80024398; break;
        case 71: goto L_800243C0; break;
        case 72: goto L_800243D4; break;
        case 73: goto L_800243E8; break;
        case 74: goto L_800243FC; break;
        case 75: goto L_80024410; break;
        case 76: goto L_80024424; break;
        case 77: goto L_80024438; break;
        case 78: goto L_8002444C; break;
        case 79: goto L_80024234; break;
        case 80: goto L_80024460; break;
        case 81: goto L_80024570; break;
        case 82: goto L_80024474; break;
        case 83: goto L_80024234; break;
        case 84: goto L_80024234; break;
        case 85: goto L_80024570; break;
        case 86: goto L_80024488; break;
        case 87: goto L_80024570; break;
        case 88: goto L_8002449C; break;
        case 89: goto L_80024570; break;
        case 90: goto L_80024570; break;
        case 91: goto L_800242D4; break;
        case 92: goto L_800244B0; break;
        case 93: goto L_80024570; break;
        case 94: goto L_800243AC; break;
        case 95: goto L_800243AC; break;
        case 96: goto L_800244C4; break;
        case 97: goto L_80024570; break;
        case 98: goto L_800244EC; break;
        case 99: goto L_800243AC; break;
        case 100: goto L_800243AC; break;
        case 101: goto L_80024398; break;
        case 102: goto L_80024398; break;
        case 103: goto L_800244D8; break;
        case 104: goto L_80024570; break;
        case 105: goto L_80024570; break;
        case 106: goto L_80024500; break;
        case 107: goto L_80024514; break;
        case 108: goto L_80024488; break;
        case 109: goto L_80024528; break;
        case 110: goto L_80024570; break;
        case 111: goto L_8002453C; break;
        case 112: goto L_80024570; break;
        case 113: goto L_80024550; break;
        case 114: goto L_80024500; break;
        case 115: goto L_80024564; break;
        case 116: goto L_80024570; break;
        case 117: goto L_80024248; break;
        default: switch_error(__func__, 0x80023F9C, 0x800E5C0C);
    }
    // 0x80023FA0: nop

L_80023FA4:
    // 0x80023FA4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80023FA8: jal         0x80033DD0
    // 0x80023FAC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_scenery(rdram, ctx);
        goto after_1;
    // 0x80023FAC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x80023FB0: b           L_80024574
    // 0x80023FB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80023FB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80023FB8:
    // 0x80023FB8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80023FBC: jal         0x800370D4
    // 0x80023FC0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_fish(rdram, ctx);
        goto after_2;
    // 0x80023FC0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x80023FC4: b           L_80024574
    // 0x80023FC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80023FC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80023FCC:
    // 0x80023FCC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80023FD0: jal         0x800377E4
    // 0x80023FD4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animator(rdram, ctx);
        goto after_3;
    // 0x80023FD4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_3:
    // 0x80023FD8: b           L_80024574
    // 0x80023FDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80023FDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80023FE0:
    // 0x80023FE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80023FE4: jal         0x800389B8
    // 0x80023FE8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_smoke(rdram, ctx);
        goto after_4;
    // 0x80023FE8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_4:
    // 0x80023FEC: b           L_80024574
    // 0x80023FF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80023FF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80023FF4:
    // 0x80023FF4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80023FF8: jal         0x80038A78
    // 0x80023FFC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_unknown25(rdram, ctx);
        goto after_5;
    // 0x80023FFC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_5:
    // 0x80024000: b           L_80024574
    // 0x80024004: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024004: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024008:
    // 0x80024008: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002400C: jal         0x80038BF4
    // 0x80024010: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bombexplosion(rdram, ctx);
        goto after_6;
    // 0x80024010: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_6:
    // 0x80024014: b           L_80024574
    // 0x80024018: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024018: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002401C:
    // 0x8002401C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024020: jal         0x80038F58
    // 0x80024024: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_exit(rdram, ctx);
        goto after_7;
    // 0x80024024: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_7:
    // 0x80024028: b           L_80024574
    // 0x8002402C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002402C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024030:
    // 0x80024030: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024034: jal         0x80039184
    // 0x80024038: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_cameracontrol(rdram, ctx);
        goto after_8;
    // 0x80024038: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
    // 0x8002403C: b           L_80024574
    // 0x80024040: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024040: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024044:
    // 0x80024044: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024048: jal         0x800391BC
    // 0x8002404C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_setuppoint(rdram, ctx);
        goto after_9;
    // 0x8002404C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_9:
    // 0x80024050: b           L_80024574
    // 0x80024054: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024054: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024058:
    // 0x80024058: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002405C: jal         0x800391FC
    // 0x80024060: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_dino_whale(rdram, ctx);
        goto after_10;
    // 0x80024060: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_10:
    // 0x80024064: b           L_80024574
    // 0x80024068: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024068: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002406C:
    // 0x8002406C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024070: jal         0x8003AD28
    // 0x80024074: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_checkpoint(rdram, ctx);
        goto after_11;
    // 0x80024074: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_11:
    // 0x80024078: b           L_80024574
    // 0x8002407C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002407C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024080:
    // 0x80024080: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024084: jal         0x8003AE50
    // 0x80024088: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_modechange(rdram, ctx);
        goto after_12;
    // 0x80024088: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_12:
    // 0x8002408C: b           L_80024574
    // 0x80024090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024094:
    // 0x80024094: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024098: jal         0x8003B174
    // 0x8002409C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bonus(rdram, ctx);
        goto after_13;
    // 0x8002409C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_13:
    // 0x800240A0: b           L_80024574
    // 0x800240A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800240A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240A8:
    // 0x800240A8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240AC: jal         0x8003B988
    // 0x800240B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_door(rdram, ctx);
        goto after_14;
    // 0x800240B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_14:
    // 0x800240B4: b           L_80024574
    // 0x800240B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800240B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240BC:
    // 0x800240BC: jal         0x80030A74
    // 0x800240C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    obj_loop_fogchanger(rdram, ctx);
        goto after_15;
    // 0x800240C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_15:
    // 0x800240C4: b           L_80024574
    // 0x800240C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800240C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240CC:
    // 0x800240CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240D0: jal         0x8003D02C
    // 0x800240D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_ainode(rdram, ctx);
        goto after_16;
    // 0x800240D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_16:
    // 0x800240D8: b           L_80024574
    // 0x800240DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800240DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240E0:
    // 0x800240E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240E4: jal         0x8003E140
    // 0x800240E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_weaponballoon(rdram, ctx);
        goto after_17;
    // 0x800240E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_17:
    // 0x800240EC: b           L_80024574
    // 0x800240F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800240F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240F4:
    // 0x800240F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240F8: jal         0x8003E5BC
    // 0x800240FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wballoonpop(rdram, ctx);
        goto after_18;
    // 0x800240FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_18:
    // 0x80024100: b           L_80024574
    // 0x80024104: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024104: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024108:
    // 0x80024108: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002410C: jal         0x8003E630
    // 0x80024110: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_weapon(rdram, ctx);
        goto after_19;
    // 0x80024110: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_19:
    // 0x80024114: b           L_80024574
    // 0x80024118: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024118: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002411C:
    // 0x8002411C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024120: jal         0x8003CF98
    // 0x80024124: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_skycontrol(rdram, ctx);
        goto after_20;
    // 0x80024124: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_20:
    // 0x80024128: b           L_80024574
    // 0x8002412C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002412C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024130:
    // 0x80024130: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024134: jal         0x80034B4C
    // 0x80024138: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_torch_mist(rdram, ctx);
        goto after_21;
    // 0x80024138: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_21:
    // 0x8002413C: b           L_80024574
    // 0x80024140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024144:
    // 0x80024144: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024148: jal         0x80040148
    // 0x8002414C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_texscroll(rdram, ctx);
        goto after_22;
    // 0x8002414C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_22:
    // 0x80024150: b           L_80024574
    // 0x80024154: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024154: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024158:
    // 0x80024158: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002415C: jal         0x800361E0
    // 0x80024160: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_stopwatchman(rdram, ctx);
        goto after_23;
    // 0x80024160: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_23:
    // 0x80024164: b           L_80024574
    // 0x80024168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002416C:
    // 0x8002416C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024170: jal         0x8003D5A0
    // 0x80024174: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_banana(rdram, ctx);
        goto after_24;
    // 0x80024174: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_24:
    // 0x80024178: b           L_80024574
    // 0x8002417C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002417C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024180:
    // 0x80024180: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024184: jal         0x80040448
    // 0x80024188: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_buoy_pirateship(rdram, ctx);
        goto after_25;
    // 0x80024188: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_25:
    // 0x8002418C: b           L_80024574
    // 0x80024190: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024190: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024194:
    // 0x80024194: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024198: jal         0x80040570
    // 0x8002419C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_log(rdram, ctx);
        goto after_26;
    // 0x8002419C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_26:
    // 0x800241A0: b           L_80024574
    // 0x800241A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800241A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241A8:
    // 0x800241A8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241AC: jal         0x80040820
    // 0x800241B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_weather(rdram, ctx);
        goto after_27;
    // 0x800241B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_27:
    // 0x800241B4: b           L_80024574
    // 0x800241B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800241B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241BC:
    // 0x800241BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241C0: jal         0x8003CA68
    // 0x800241C4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bridge_whaleramp(rdram, ctx);
        goto after_28;
    // 0x800241C4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_28:
    // 0x800241C8: b           L_80024574
    // 0x800241CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800241CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241D0:
    // 0x800241D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241D4: jal         0x8003CEA0
    // 0x800241D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_rampswitch(rdram, ctx);
        goto after_29;
    // 0x800241D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_29:
    // 0x800241DC: b           L_80024574
    // 0x800241E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800241E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241E4:
    // 0x800241E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241E8: jal         0x8003CF0C
    // 0x800241EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_seamonster(rdram, ctx);
        goto after_30;
    // 0x800241EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_30:
    // 0x800241F0: b           L_80024574
    // 0x800241F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800241F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241F8:
    // 0x800241F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241FC: jal         0x80035260
    // 0x80024200: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_collectegg(rdram, ctx);
        goto after_31;
    // 0x80024200: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_31:
    // 0x80024204: b           L_80024574
    // 0x80024208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002420C:
    // 0x8002420C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024210: jal         0x8003564C
    // 0x80024214: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_eggcreator(rdram, ctx);
        goto after_32;
    // 0x80024214: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_32:
    // 0x80024218: b           L_80024574
    // 0x8002421C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002421C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024220:
    // 0x80024220: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024224: jal         0x80035F6C
    // 0x80024228: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_characterflag(rdram, ctx);
        goto after_33;
    // 0x80024228: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_33:
    // 0x8002422C: b           L_80024574
    // 0x80024230: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024230: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024234:
    // 0x80024234: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024238: jal         0x80037CE8
    // 0x8002423C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animobject(rdram, ctx);
        goto after_34;
    // 0x8002423C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_34:
    // 0x80024240: b           L_80024574
    // 0x80024244: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024244: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024248:
    // 0x80024248: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002424C: jal         0x80042CD0
    // 0x80024250: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wizghosts(rdram, ctx);
        goto after_35;
    // 0x80024250: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_35:
    // 0x80024254: b           L_80024574
    // 0x80024258: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024258: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002425C:
    // 0x8002425C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024260: jal         0x80038710
    // 0x80024264: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animcamera(rdram, ctx);
        goto after_36;
    // 0x80024264: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_36:
    // 0x80024268: b           L_80024574
    // 0x8002426C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002426C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024270:
    // 0x80024270: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024274: jal         0x800388D4
    // 0x80024278: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_infopoint(rdram, ctx);
        goto after_37;
    // 0x80024278: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_37:
    // 0x8002427C: b           L_80024574
    // 0x80024280: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024280: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024284:
    // 0x80024284: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024288: jal         0x800387CC
    // 0x8002428C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animcar(rdram, ctx);
        goto after_38;
    // 0x8002428C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_38:
    // 0x80024290: b           L_80024574
    // 0x80024294: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024294: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024298:
    // 0x80024298: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002429C: jal         0x8003833C
    // 0x800242A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_char_select(rdram, ctx);
        goto after_39;
    // 0x800242A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_39:
    // 0x800242A4: b           L_80024574
    // 0x800242A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800242A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242AC:
    // 0x800242AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242B0: jal         0x8003C7A4
    // 0x800242B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_trigger(rdram, ctx);
        goto after_40;
    // 0x800242B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_40:
    // 0x800242B8: b           L_80024574
    // 0x800242BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800242BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242C0:
    // 0x800242C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242C4: jal         0x800380F8
    // 0x800242C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_vehicleanim(rdram, ctx);
        goto after_41;
    // 0x800242C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_41:
    // 0x800242CC: b           L_80024574
    // 0x800242D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800242D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242D4:
    // 0x800242D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242D8: jal         0x8003596C
    // 0x800242DC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_airzippers_waterzippers(rdram, ctx);
        goto after_42;
    // 0x800242DC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_42:
    // 0x800242E0: b           L_80024574
    // 0x800242E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800242E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242E8:
    // 0x800242E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242EC: jal         0x80035E34
    // 0x800242F0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_timetrialghost(rdram, ctx);
        goto after_43;
    // 0x800242F0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_43:
    // 0x800242F4: b           L_80024574
    // 0x800242F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800242F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242FC:
    // 0x800242FC: jal         0x800BFFDC
    // 0x80024300: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    obj_loop_wavepower(rdram, ctx);
        goto after_44;
    // 0x80024300: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_44:
    // 0x80024304: b           L_80024574
    // 0x80024308: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024308: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002430C:
    // 0x8002430C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024310: jal         0x80040C54
    // 0x80024314: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_butterfly(rdram, ctx);
        goto after_45;
    // 0x80024314: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_45:
    // 0x80024318: b           L_80024574
    // 0x8002431C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002431C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024320:
    // 0x80024320: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024324: jal         0x80039330
    // 0x80024328: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_parkwarden(rdram, ctx);
        goto after_46;
    // 0x80024328: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_46:
    // 0x8002432C: b           L_80024574
    // 0x80024330: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024330: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024334:
    // 0x80024334: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024338: jal         0x8003DF08
    // 0x8002433C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_worldkey(rdram, ctx);
        goto after_47;
    // 0x8002433C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_47:
    // 0x80024340: b           L_80024574
    // 0x80024344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024348:
    // 0x80024348: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002434C: jal         0x8003D3FC
    // 0x80024350: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bananacreator(rdram, ctx);
        goto after_48;
    // 0x80024350: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_48:
    // 0x80024354: b           L_80024574
    // 0x80024358: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024358: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002435C:
    // 0x8002435C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024360: jal         0x8003D058
    // 0x80024364: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_treasuresucker(rdram, ctx);
        goto after_49;
    // 0x80024364: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_49:
    // 0x80024368: b           L_80024574
    // 0x8002436C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002436C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024370:
    // 0x80024370: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024374: jal         0x80037594
    // 0x80024378: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_lavaspurt(rdram, ctx);
        goto after_50;
    // 0x80024378: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_50:
    // 0x8002437C: b           L_80024574
    // 0x80024380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024384:
    // 0x80024384: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024388: jal         0x8003763C
    // 0x8002438C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_posarrow(rdram, ctx);
        goto after_51;
    // 0x8002438C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_51:
    // 0x80024390: b           L_80024574
    // 0x80024394: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024394: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024398:
    // 0x80024398: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002439C: jal         0x800381C0
    // 0x800243A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_hittester(rdram, ctx);
        goto after_52;
    // 0x800243A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_52:
    // 0x800243A4: b           L_80024574
    // 0x800243A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800243A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243AC:
    // 0x800243AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243B0: jal         0x8003827C
    // 0x800243B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_snowball(rdram, ctx);
        goto after_53;
    // 0x800243B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_53:
    // 0x800243B8: b           L_80024574
    // 0x800243BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800243BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243C0:
    // 0x800243C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243C4: jal         0x80034B74
    // 0x800243C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_effectbox(rdram, ctx);
        goto after_54;
    // 0x800243C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_54:
    // 0x800243CC: b           L_80024574
    // 0x800243D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800243D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243D4:
    // 0x800243D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243D8: jal         0x80034E9C
    // 0x800243DC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_trophycab(rdram, ctx);
        goto after_55;
    // 0x800243DC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_55:
    // 0x800243E0: b           L_80024574
    // 0x800243E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800243E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243E8:
    // 0x800243E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243EC: jal         0x80042090
    // 0x800243F0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bubbler(rdram, ctx);
        goto after_56;
    // 0x800243F0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_56:
    // 0x800243F4: b           L_80024574
    // 0x800243F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800243F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243FC:
    // 0x800243FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024400: jal         0x8003D2B8
    // 0x80024404: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_flycoin(rdram, ctx);
        goto after_57;
    // 0x80024404: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_57:
    // 0x80024408: b           L_80024574
    // 0x8002440C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002440C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024410:
    // 0x80024410: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024414: jal         0x8003B4BC
    // 0x80024418: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_goldenballoon(rdram, ctx);
        goto after_58;
    // 0x80024418: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_58:
    // 0x8002441C: b           L_80024574
    // 0x80024420: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024420: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024424:
    // 0x80024424: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024428: jal         0x80034860
    // 0x8002442C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_laserbolt(rdram, ctx);
        goto after_59;
    // 0x8002442C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_59:
    // 0x80024430: b           L_80024574
    // 0x80024434: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024434: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024438:
    // 0x80024438: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002443C: jal         0x800345A0
    // 0x80024440: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_lasergun(rdram, ctx);
        goto after_60;
    // 0x80024440: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_60:
    // 0x80024444: b           L_80024574
    // 0x80024448: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024448: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002444C:
    // 0x8002444C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024450: jal         0x8003ACA0
    // 0x80024454: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_gbparkwarden(rdram, ctx);
        goto after_61;
    // 0x80024454: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_61:
    // 0x80024458: b           L_80024574
    // 0x8002445C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002445C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024460:
    // 0x80024460: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024464: jal         0x80035C50
    // 0x80024468: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_groundzipper(rdram, ctx);
        goto after_62;
    // 0x80024468: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_62:
    // 0x8002446C: b           L_80024574
    // 0x80024470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024474:
    // 0x80024474: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024478: jal         0x80037D78
    // 0x8002447C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wizpigship(rdram, ctx);
        goto after_63;
    // 0x8002447C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_63:
    // 0x80024480: b           L_80024574
    // 0x80024484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024488:
    // 0x80024488: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002448C: jal         0x8003DD14
    // 0x80024490: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_silvercoin(rdram, ctx);
        goto after_64;
    // 0x80024490: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_64:
    // 0x80024494: b           L_80024574
    // 0x80024498: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024498: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002449C:
    // 0x8002449C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244A0: jal         0x80038AD4
    // 0x800244A4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wardensmoke(rdram, ctx);
        goto after_65;
    // 0x800244A4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_65:
    // 0x800244A8: b           L_80024574
    // 0x800244AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800244AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244B0:
    // 0x800244B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244B4: jal         0x80042160
    // 0x800244B8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_unknown94(rdram, ctx);
        goto after_66;
    // 0x800244B8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_66:
    // 0x800244BC: b           L_80024574
    // 0x800244C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800244C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244C4:
    // 0x800244C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244C8: jal         0x80038DC4
    // 0x800244CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_teleport(rdram, ctx);
        goto after_67;
    // 0x800244CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_67:
    // 0x800244D0: b           L_80024574
    // 0x800244D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800244D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244D8:
    // 0x800244D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244DC: jal         0x80042178
    // 0x800244E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_rangetrigger(rdram, ctx);
        goto after_68;
    // 0x800244E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_68:
    // 0x800244E4: b           L_80024574
    // 0x800244E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800244E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244EC:
    // 0x800244EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244F0: jal         0x800357D4
    // 0x800244F4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_rocketsignpost(rdram, ctx);
        goto after_69;
    // 0x800244F4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_69:
    // 0x800244F8: b           L_80024574
    // 0x800244FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x800244FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024500:
    // 0x80024500: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024504: jal         0x80033F60
    // 0x80024508: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_fireball_octoweapon(rdram, ctx);
        goto after_70;
    // 0x80024508: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_70:
    // 0x8002450C: b           L_80024574
    // 0x80024510: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024510: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024514:
    // 0x80024514: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024518: jal         0x800422F0
    // 0x8002451C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_frog(rdram, ctx);
        goto after_71;
    // 0x8002451C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_71:
    // 0x80024520: b           L_80024574
    // 0x80024524: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024524: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024528:
    // 0x80024528: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002452C: jal         0x8003C2E4
    // 0x80024530: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_ttdoor(rdram, ctx);
        goto after_72;
    // 0x80024530: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_72:
    // 0x80024534: b           L_80024574
    // 0x80024538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002453C:
    // 0x8002453C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024540: jal         0x80037D08
    // 0x80024544: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_dooropener(rdram, ctx);
        goto after_73;
    // 0x80024544: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_73:
    // 0x80024548: b           L_80024574
    // 0x8002454C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x8002454C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024550:
    // 0x80024550: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024554: jal         0x80042998
    // 0x80024558: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_pigrocketeer(rdram, ctx);
        goto after_74;
    // 0x80024558: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_74:
    // 0x8002455C: b           L_80024574
    // 0x80024560: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024574;
    // 0x80024560: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024564:
    // 0x80024564: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024568: jal         0x80042A90
    // 0x8002456C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_levelname(rdram, ctx);
        goto after_75;
    // 0x8002456C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_75:
L_80024570:
    // 0x80024570: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024574:
    // 0x80024574: jal         0x800B76B8
    // 0x80024578: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_76;
    // 0x80024578: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_76:
    // 0x8002457C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024584: jr          $ra
    // 0x80024588: nop

    return;
    // 0x80024588: nop

;}
RECOMP_FUNC void guPerspectiveF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC920: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CC924: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800CC928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC92C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800CC930: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CC934: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CC938: jal         0x800D4940
    // 0x800CC93C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800CC93C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800CC940: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800CC944: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CC948: ldc1        $f6, -0x69C0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X69C0);
    // 0x800CC94C: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x800CC950: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CC954: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800CC958: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800CC95C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800CC960: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800CC964: jal         0x800D4AB0
    // 0x800CC968: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800CC968: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800CC96C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CC970: jal         0x800D4C20
    // 0x800CC974: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800CC974: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800CC978: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800CC97C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800CC980: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800CC984: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CC988: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800CC98C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800CC990: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CC994: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x800CC998: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800CC99C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CC9A0: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800CC9A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800CC9A8: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x800CC9AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CC9B0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800CC9B4: div.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800CC9B8: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x800CC9BC: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800CC9C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CC9C4: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x800CC9C8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800CC9CC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CC9D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CC9D4: nop

    // 0x800CC9D8: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x800CC9DC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800CC9E0: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800CC9E4: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x800CC9E8: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800CC9EC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CC9F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CC9F4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CC9F8: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CC9FC: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CCA00: beq         $v1, $a0, L_800CCA44
    if (ctx->r3 == ctx->r4) {
        // 0x800CCA04: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
            goto L_800CCA44;
    }
    // 0x800CCA04: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
L_800CCA08:
    // 0x800CCA08: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CCA0C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CCA10: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CCA14: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800CCA18: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CCA1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CCA20: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800CCA24: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CCA28: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800CCA2C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CCA30: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800CCA34: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800CCA38: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CCA3C: bne         $v1, $a0, L_800CCA08
    if (ctx->r3 != ctx->r4) {
        // 0x800CCA40: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_800CCA08;
    }
    // 0x800CCA40: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_800CCA44:
    // 0x800CCA44: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CCA48: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CCA4C: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x800CCA50: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800CCA54: nop

    // 0x800CCA58: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800CCA5C: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x800CCA60: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800CCA64: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x800CCA68: beq         $a1, $zero, L_800CCB40
    if (ctx->r5 == 0) {
        // 0x800CCA6C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800CCB40;
    }
    // 0x800CCA6C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CCA70: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800CCA74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CCA78: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x800CCA7C: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800CCA80: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x800CCA84: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800CCA88: bc1fl       L_800CCA9C
    if (!c1cs) {
        // 0x800CCA8C: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_800CCA9C;
    }
    goto skip_0;
    // 0x800CCA8C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800CCA90: b           L_800CCB40
    // 0x800CCA94: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_800CCB40;
    // 0x800CCA94: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800CCA98: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_800CCA9C:
    // 0x800CCA9C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CCAA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CCAA4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800CCAA8: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x800CCAAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CCAB0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800CCAB4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CCAB8: nop

    // 0x800CCABC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800CCAC0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800CCAC4: nop

    // 0x800CCAC8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800CCACC: beql        $t8, $zero, L_800CCB20
    if (ctx->r24 == 0) {
        // 0x800CCAD0: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_800CCB20;
    }
    goto skip_1;
    // 0x800CCAD0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x800CCAD4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CCAD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CCADC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CCAE0: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800CCAE4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CCAE8: nop

    // 0x800CCAEC: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800CCAF0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800CCAF4: nop

    // 0x800CCAF8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800CCAFC: bne         $t8, $zero, L_800CCB14
    if (ctx->r24 != 0) {
        // 0x800CCB00: nop
    
            goto L_800CCB14;
    }
    // 0x800CCB00: nop

    // 0x800CCB04: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800CCB08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CCB0C: b           L_800CCB2C
    // 0x800CCB10: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800CCB2C;
    // 0x800CCB10: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800CCB14:
    // 0x800CCB14: b           L_800CCB2C
    // 0x800CCB18: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800CCB2C;
    // 0x800CCB18: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800CCB1C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_800CCB20:
    // 0x800CCB20: nop

    // 0x800CCB24: bltz        $t8, L_800CCB14
    if (SIGNED(ctx->r24) < 0) {
        // 0x800CCB28: nop
    
            goto L_800CCB14;
    }
    // 0x800CCB28: nop

L_800CCB2C:
    // 0x800CCB2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800CCB30: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800CCB34: bgtz        $t9, L_800CCB40
    if (SIGNED(ctx->r25) > 0) {
        // 0x800CCB38: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_800CCB40;
    }
    // 0x800CCB38: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800CCB3C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_800CCB40:
    // 0x800CCB40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CCB44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CCB48: jr          $ra
    // 0x800CCB4C: nop

    return;
    // 0x800CCB4C: nop

;}
RECOMP_FUNC void music_sequence_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000232C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002330: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002334: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80002338: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000233C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80002340: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80002344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80002348: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000234C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80002350: jal         0x800C7A50
    // 0x80002354: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    alCSPGetState(rdram, ctx);
        goto after_0;
    // 0x80002354: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    after_0:
    // 0x80002358: bne         $v0, $zero, L_80002558
    if (ctx->r2 != 0) {
        // 0x8000235C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80002558;
    }
    // 0x8000235C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80002360: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x80002364: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80002368: beq         $t6, $zero, L_80002558
    if (ctx->r14 == 0) {
        // 0x8000236C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80002558;
    }
    // 0x8000236C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80002370: jal         0x80076EE8
    // 0x80002374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    asset_rom_offset(rdram, ctx);
        goto after_1;
    // 0x80002374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80002378: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x8000237C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002380: lw          $t7, 0x5CF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5CF8);
    // 0x80002384: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80002388: lw          $t1, 0x5D0C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5D0C);
    // 0x8000238C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80002390: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80002394: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80002398: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8000239C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800023A0: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x800023A4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800023A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800023AC: jal         0x80076E68
    // 0x800023B0: subu        $a2, $t0, $v0
    ctx->r6 = SUB32(ctx->r8, ctx->r2);
    asset_load(rdram, ctx);
        goto after_2;
    // 0x800023B0: subu        $a2, $t0, $v0
    ctx->r6 = SUB32(ctx->r8, ctx->r2);
    after_2:
    // 0x800023B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800023B8: jal         0x800C7FFC
    // 0x800023BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    alCSeqNew(rdram, ctx);
        goto after_3;
    // 0x800023BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800023C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800023C4: jal         0x800C8560
    // 0x800023C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alCSPSetSeq(rdram, ctx);
        goto after_4;
    // 0x800023C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800023CC: jal         0x800C85A0
    // 0x800023D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alCSPPlay(rdram, ctx);
        goto after_5;
    // 0x800023D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800023D4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800023D8: lw          $t4, -0x39D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X39D0);
    // 0x800023DC: nop

    // 0x800023E0: bne         $s0, $t4, L_800024E8
    if (ctx->r16 != ctx->r12) {
        // 0x800023E4: nop
    
            goto L_800024E8;
    }
    // 0x800023E4: nop

    // 0x800023E8: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x800023EC: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800023F0: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800023F4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800023F8: addiu       $s0, $s0, 0x5D1C
    ctx->r16 = ADD32(ctx->r16, 0X5D1C);
    // 0x800023FC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80002400: mflo        $t7
    ctx->r15 = lo;
    // 0x80002404: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80002408: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8000240C: jal         0x80001990
    // 0x80002410: nop

    music_volume_set(rdram, ctx);
        goto after_6;
    // 0x80002410: nop

    after_6:
    // 0x80002414: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    // 0x80002418: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000241C: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002420: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80002424: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002428: mflo        $t0
    ctx->r8 = lo;
    // 0x8000242C: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80002430: lbu         $a0, 0x1($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X1);
    // 0x80002434: nop

    // 0x80002438: beq         $a0, $zero, L_80002458
    if (ctx->r4 == 0) {
        // 0x8000243C: nop
    
            goto L_80002458;
    }
    // 0x8000243C: nop

    // 0x80002440: jal         0x80001534
    // 0x80002444: nop

    music_tempo_set(rdram, ctx);
        goto after_7;
    // 0x80002444: nop

    after_7:
    // 0x80002448: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000244C: lw          $v0, 0x5D1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5D1C);
    // 0x80002450: b           L_80002460
    // 0x80002454: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
        goto L_80002460;
    // 0x80002454: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
L_80002458:
    // 0x80002458: sh          $t2, 0x5D30($at)
    MEM_H(0X5D30, ctx->r1) = ctx->r10;
    // 0x8000245C: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
L_80002460:
    // 0x80002460: nop

    // 0x80002464: multu       $t3, $s1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002468: mflo        $t4
    ctx->r12 = lo;
    // 0x8000246C: addu        $t6, $v0, $t4
    ctx->r14 = ADD32(ctx->r2, ctx->r12);
    // 0x80002470: lbu         $a0, 0x2($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X2);
    // 0x80002474: jal         0x80002608
    // 0x80002478: nop

    sound_reverb_set(rdram, ctx);
        goto after_8;
    // 0x80002478: nop

    after_8:
    // 0x8000247C: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x80002480: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80002484: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002488: addiu       $s1, $s1, 0x5F7C
    ctx->r17 = ADD32(ctx->r17, 0X5F7C);
    // 0x8000248C: sb          $t5, 0x5D04($at)
    MEM_B(0X5D04, ctx->r1) = ctx->r13;
    // 0x80002490: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80002494: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80002498: beq         $t7, $at, L_80002550
    if (ctx->r15 == ctx->r1) {
        // 0x8000249C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80002550;
    }
    // 0x8000249C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800024A0: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_800024A4:
    // 0x800024A4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800024A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800024AC: sllv        $t9, $t8, $s0
    ctx->r25 = S32(ctx->r24 << (ctx->r16 & 31));
    // 0x800024B0: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800024B4: beq         $t1, $zero, L_800024CC
    if (ctx->r9 == 0) {
        // 0x800024B8: nop
    
            goto L_800024CC;
    }
    // 0x800024B8: nop

    // 0x800024BC: jal         0x80001170
    // 0x800024C0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_9;
    // 0x800024C0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_9:
    // 0x800024C4: b           L_800024D8
    // 0x800024C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800024D8;
    // 0x800024C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800024CC:
    // 0x800024CC: jal         0x80001114
    // 0x800024D0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_10;
    // 0x800024D0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_10:
    // 0x800024D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800024D8:
    // 0x800024D8: bne         $s0, $s2, L_800024A4
    if (ctx->r16 != ctx->r18) {
        // 0x800024DC: nop
    
            goto L_800024A4;
    }
    // 0x800024DC: nop

    // 0x800024E0: b           L_80002554
    // 0x800024E4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
        goto L_80002554;
    // 0x800024E4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
L_800024E8:
    // 0x800024E8: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x800024EC: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800024F0: multu       $t3, $s1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800024F4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800024F8: addiu       $s0, $s0, 0x5D1C
    ctx->r16 = ADD32(ctx->r16, 0X5D1C);
    // 0x800024FC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80002500: mflo        $t4
    ctx->r12 = lo;
    // 0x80002504: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x80002508: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x8000250C: jal         0x80001B0C
    // 0x80002510: nop

    music_jingle_volume_set(rdram, ctx);
        goto after_11;
    // 0x80002510: nop

    after_11:
    // 0x80002514: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80002518: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000251C: multu       $v1, $s1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002520: mflo        $t7
    ctx->r15 = lo;
    // 0x80002524: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80002528: lbu         $a0, 0x1($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X1);
    // 0x8000252C: nop

    // 0x80002530: beq         $a0, $zero, L_80002548
    if (ctx->r4 == 0) {
        // 0x80002534: nop
    
            goto L_80002548;
    }
    // 0x80002534: nop

    // 0x80002538: jal         0x800017D4
    // 0x8000253C: nop

    sound_jingle_tempo_set(rdram, ctx);
        goto after_12;
    // 0x8000253C: nop

    after_12:
    // 0x80002540: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80002544: nop

L_80002548:
    // 0x80002548: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000254C: sb          $v1, 0x5D05($at)
    MEM_B(0X5D05, ctx->r1) = ctx->r3;
L_80002550:
    // 0x80002550: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
L_80002554:
    // 0x80002554: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80002558:
    // 0x80002558: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000255C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80002560: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80002564: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80002568: jr          $ra
    // 0x8000256C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000256C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void hud_race_finish_1player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A497C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A4980: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A4984: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A4988: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A498C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4990: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A4994: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
    // 0x800A4998: addiu       $a3, $v0, 0x700
    ctx->r7 = ADD32(ctx->r2, 0X700);
    // 0x800A499C: lb          $v1, 0x1A($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1A);
    // 0x800A49A0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800A49A4: beq         $v1, $zero, L_800A49D4
    if (ctx->r3 == 0) {
        // 0x800A49A8: addiu       $s0, $v0, 0x740
        ctx->r16 = ADD32(ctx->r2, 0X740);
            goto L_800A49D4;
    }
    // 0x800A49A8: addiu       $s0, $v0, 0x740
    ctx->r16 = ADD32(ctx->r2, 0X740);
    // 0x800A49AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A49B0: beq         $v1, $at, L_800A4A30
    if (ctx->r3 == ctx->r1) {
        // 0x800A49B4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800A4A30;
    }
    // 0x800A49B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A49B8: beq         $v1, $v0, L_800A4B38
    if (ctx->r3 == ctx->r2) {
        // 0x800A49BC: sll         $t3, $a1, 2
        ctx->r11 = S32(ctx->r5 << 2);
            goto L_800A4B38;
    }
    // 0x800A49BC: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800A49C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A49C4: beq         $v1, $v0, L_800A4B98
    if (ctx->r3 == ctx->r2) {
        // 0x800A49C8: nop
    
            goto L_800A4B98;
    }
    // 0x800A49C8: nop

    // 0x800A49CC: b           L_800A4BA0
    // 0x800A49D0: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
        goto L_800A4BA0;
    // 0x800A49D0: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
L_800A49D4:
    // 0x800A49D4: jal         0x80000BE0
    // 0x800A49D8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    music_voicelimit_set(rdram, ctx);
        goto after_0;
    // 0x800A49D8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A49DC: jal         0x80000B34
    // 0x800A49E0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    music_play(rdram, ctx);
        goto after_1;
    // 0x800A49E0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x800A49E4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A49E8: jal         0x80001D04
    // 0x800A49EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800A49EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800A49F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A49F4: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    // 0x800A49F8: jal         0x80001D04
    // 0x800A49FC: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A49FC: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    after_3:
    // 0x800A4A00: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A4A04: addiu       $v0, $v0, 0x2770
    ctx->r2 = ADD32(ctx->r2, 0X2770);
    // 0x800A4A08: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800A4A0C: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x800A4A10: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x800A4A14: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800A4A18: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800A4A1C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4A20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A4A24: sb          $t8, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r24;
    // 0x800A4A28: b           L_800A4B9C
    // 0x800A4A2C: sb          $t9, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r25;
        goto L_800A4B9C;
    // 0x800A4A2C: sb          $t9, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r25;
L_800A4A30:
    // 0x800A4A30: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x800A4A34: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x800A4A38: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800A4A3C: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x800A4A40: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A4A44: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A4A48: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A4A4C: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x800A4A50: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A4A54: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A4A58: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x800A4A5C: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A4A60: nop

    // 0x800A4A64: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800A4A68: nop

    // 0x800A4A6C: bc1f        L_800A4A78
    if (!c1cs) {
        // 0x800A4A70: nop
    
            goto L_800A4A78;
    }
    // 0x800A4A70: nop

    // 0x800A4A74: swc1        $f2, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f2.u32l;
L_800A4A78:
    // 0x800A4A78: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A4A7C: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x800A4A80: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800A4A84: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A4A88: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800A4A8C: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A4A90: nop

    // 0x800A4A94: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800A4A98: nop

    // 0x800A4A9C: bc1f        L_800A4AB0
    if (!c1cs) {
        // 0x800A4AA0: nop
    
            goto L_800A4AB0;
    }
    // 0x800A4AA0: nop

    // 0x800A4AA4: swc1        $f12, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f12.u32l;
    // 0x800A4AA8: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A4AAC: nop

L_800A4AB0:
    // 0x800A4AB0: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x800A4AB4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A4AB8: bc1f        L_800A4B9C
    if (!c1cs) {
        // 0x800A4ABC: sb          $t1, 0x27($sp)
        MEM_B(0X27, ctx->r29) = ctx->r9;
            goto L_800A4B9C;
    }
    // 0x800A4ABC: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    // 0x800A4AC0: lb          $t2, 0x1B($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X1B);
    // 0x800A4AC4: addiu       $t5, $zero, -0x78
    ctx->r13 = ADD32(0, -0X78);
    // 0x800A4AC8: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x800A4ACC: sb          $t3, 0x1B($a3)
    MEM_B(0X1B, ctx->r7) = ctx->r11;
    // 0x800A4AD0: lb          $t4, 0x1B($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X1B);
    // 0x800A4AD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A4AD8: slti        $at, $t4, 0x78
    ctx->r1 = SIGNED(ctx->r12) < 0X78 ? 1 : 0;
    // 0x800A4ADC: bne         $at, $zero, L_800A4AF4
    if (ctx->r1 != 0) {
        // 0x800A4AE0: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800A4AF4;
    }
    // 0x800A4AE0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A4AE4: lb          $t6, 0x1C($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1C);
    // 0x800A4AE8: sb          $t5, 0x1B($a3)
    MEM_B(0X1B, ctx->r7) = ctx->r13;
    // 0x800A4AEC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A4AF0: sb          $t7, 0x1C($a3)
    MEM_B(0X1C, ctx->r7) = ctx->r15;
L_800A4AF4:
    // 0x800A4AF4: lb          $t8, 0x1C($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1C);
    // 0x800A4AF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A4AFC: bne         $v0, $t8, L_800A4BA0
    if (ctx->r2 != ctx->r24) {
        // 0x800A4B00: lb          $t5, 0x27($sp)
        ctx->r13 = MEM_B(ctx->r29, 0X27);
            goto L_800A4BA0;
    }
    // 0x800A4B00: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
    // 0x800A4B04: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
    // 0x800A4B08: jal         0x80001D04
    // 0x800A4B0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800A4B0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_4:
    // 0x800A4B10: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A4B14: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A4B18: addiu       $v0, $v0, 0x2770
    ctx->r2 = ADD32(ctx->r2, 0X2770);
    // 0x800A4B1C: lb          $t1, 0xC($v0)
    ctx->r9 = MEM_B(ctx->r2, 0XC);
    // 0x800A4B20: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800A4B24: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4B28: bne         $t0, $t1, L_800A4B9C
    if (ctx->r8 != ctx->r9) {
        // 0x800A4B2C: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_800A4B9C;
    }
    // 0x800A4B2C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800A4B30: b           L_800A4B9C
    // 0x800A4B34: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
        goto L_800A4B9C;
    // 0x800A4B34: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
L_800A4B38:
    // 0x800A4B38: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800A4B3C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A4B40: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x800A4B44: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800A4B48: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A4B4C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A4B50: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A4B54: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800A4B58: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A4B5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A4B60: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x800A4B64: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A4B68: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A4B6C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A4B70: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800A4B74: sb          $t4, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r12;
    // 0x800A4B78: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A4B7C: nop

    // 0x800A4B80: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800A4B84: nop

    // 0x800A4B88: bc1f        L_800A4BA0
    if (!c1cs) {
        // 0x800A4B8C: lb          $t5, 0x27($sp)
        ctx->r13 = MEM_B(ctx->r29, 0X27);
            goto L_800A4BA0;
    }
    // 0x800A4B8C: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
    // 0x800A4B90: b           L_800A4B9C
    // 0x800A4B94: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
        goto L_800A4B9C;
    // 0x800A4B94: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
L_800A4B98:
    // 0x800A4B98: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
L_800A4B9C:
    // 0x800A4B9C: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
L_800A4BA0:
    // 0x800A4BA0: nop

    // 0x800A4BA4: beq         $t5, $zero, L_800A4C24
    if (ctx->r13 == 0) {
        // 0x800A4BA8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A4C24;
    }
    // 0x800A4BA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4BAC: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4BB0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A4BB4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800A4BB8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800A4BBC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A4BC0: addiu       $t8, $zero, -0x2E
    ctx->r24 = ADD32(0, -0X2E);
    // 0x800A4BC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4BC8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4BCC: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A4BD0: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A4BD4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800A4BD8: jal         0x800AA600
    // 0x800A4BDC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A4BDC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    after_5:
    // 0x800A4BE0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4BE4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4BE8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4BEC: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4BF0: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A4BF4: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A4BF8: jal         0x800AA600
    // 0x800A4BFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A4BFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x800A4C00: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4C04: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4C08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A4C0C: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x800A4C10: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A4C14: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800A4C18: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800A4C1C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800A4C20: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800A4C24:
    // 0x800A4C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A4C28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4C2C: jr          $ra
    // 0x800A4C30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A4C30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void set_active_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800665E8: bltz        $a0, L_80066600
    if (SIGNED(ctx->r4) < 0) {
        // 0x800665EC: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_80066600;
    }
    // 0x800665EC: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x800665F0: beq         $at, $zero, L_80066600
    if (ctx->r1 == 0) {
        // 0x800665F4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80066600;
    }
    // 0x800665F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800665F8: jr          $ra
    // 0x800665FC: sw          $a0, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r4;
    return;
    // 0x800665FC: sw          $a0, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r4;
L_80066600:
    // 0x80066600: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066604: sw          $zero, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = 0;
    // 0x80066608: jr          $ra
    // 0x8006660C: nop

    return;
    // 0x8006660C: nop

;}
RECOMP_FUNC void get_controller_pak_file_list(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075E60: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80075E64: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80075E68: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80075E6C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80075E70: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80075E74: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80075E78: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80075E7C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80075E80: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80075E84: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80075E88: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80075E8C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80075E90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80075E94: jal         0x800758DC
    // 0x80075E98: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075E98: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80075E9C: beq         $v0, $zero, L_80075EB8
    if (ctx->r2 == 0) {
        // 0x80075EA0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80075EB8;
    }
    // 0x80075EA0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80075EA4: jal         0x80075AEC
    // 0x80075EA8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80075EA8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x80075EAC: sll         $t6, $s7, 30
    ctx->r14 = S32(ctx->r23 << 30);
    // 0x80075EB0: b           L_80076138
    // 0x80075EB4: or          $v0, $t6, $s0
    ctx->r2 = ctx->r14 | ctx->r16;
        goto L_80076138;
    // 0x80075EB4: or          $v0, $t6, $s0
    ctx->r2 = ctx->r14 | ctx->r16;
L_80075EB8:
    // 0x80075EB8: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x80075EBC: subu        $t7, $t7, $s7
    ctx->r15 = SUB32(ctx->r15, ctx->r23);
    // 0x80075EC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80075EC4: addu        $t7, $t7, $s7
    ctx->r15 = ADD32(ctx->r15, ctx->r23);
    // 0x80075EC8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80075ECC: addiu       $t8, $t8, 0x4018
    ctx->r24 = ADD32(ctx->r24, 0X4018);
    // 0x80075ED0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80075ED4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80075ED8: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x80075EDC: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80075EE0: jal         0x800D0390
    // 0x80075EE4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_2;
    // 0x80075EE4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_2:
    // 0x80075EE8: beq         $v0, $zero, L_80075F08
    if (ctx->r2 == 0) {
        // 0x80075EEC: nop
    
            goto L_80075F08;
    }
    // 0x80075EEC: nop

    // 0x80075EF0: jal         0x80075AEC
    // 0x80075EF4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_3;
    // 0x80075EF4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_3:
    // 0x80075EF8: sll         $v0, $s7, 30
    ctx->r2 = S32(ctx->r23 << 30);
    // 0x80075EFC: ori         $t9, $v0, 0x9
    ctx->r25 = ctx->r2 | 0X9;
    // 0x80075F00: b           L_80076138
    // 0x80075F04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80076138;
    // 0x80075F04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075F08:
    // 0x80075F08: jal         0x8009EB20
    // 0x80075F0C: nop

    get_language(rdram, ctx);
        goto after_4;
    // 0x80075F0C: nop

    after_4:
    // 0x80075F10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80075F14: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x80075F18: bne         $v0, $at, L_80075F2C
    if (ctx->r2 != ctx->r1) {
        // 0x80075F1C: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_80075F2C;
    }
    // 0x80075F1C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80075F20: lui         $s6, 0x4E44
    ctx->r22 = S32(0X4E44 << 16);
    // 0x80075F24: b           L_80075F4C
    // 0x80075F28: ori         $s6, $s6, 0x594A
    ctx->r22 = ctx->r22 | 0X594A;
        goto L_80075F4C;
    // 0x80075F28: ori         $s6, $s6, 0x594A
    ctx->r22 = ctx->r22 | 0X594A;
L_80075F2C:
    // 0x80075F2C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80075F30: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x80075F34: lui         $s6, 0x4E44
    ctx->r22 = S32(0X4E44 << 16);
    // 0x80075F38: bne         $t0, $zero, L_80075F4C
    if (ctx->r8 != 0) {
        // 0x80075F3C: ori         $s6, $s6, 0x5945
        ctx->r22 = ctx->r22 | 0X5945;
            goto L_80075F4C;
    }
    // 0x80075F3C: ori         $s6, $s6, 0x5945
    ctx->r22 = ctx->r22 | 0X5945;
    // 0x80075F40: lui         $s6, 0x4E44
    ctx->r22 = S32(0X4E44 << 16);
    // 0x80075F44: b           L_80075F4C
    // 0x80075F48: ori         $s6, $s6, 0x5950
    ctx->r22 = ctx->r22 | 0X5950;
        goto L_80075F4C;
    // 0x80075F48: ori         $s6, $s6, 0x5950
    ctx->r22 = ctx->r22 | 0X5950;
L_80075F4C:
    // 0x80075F4C: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80075F50: beq         $at, $zero, L_80075F5C
    if (ctx->r1 == 0) {
        // 0x80075F54: addiu       $s0, $s0, -0x1BC0
        ctx->r16 = ADD32(ctx->r16, -0X1BC0);
            goto L_80075F5C;
    }
    // 0x80075F54: addiu       $s0, $s0, -0x1BC0
    ctx->r16 = ADD32(ctx->r16, -0X1BC0);
    // 0x80075F58: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
L_80075F5C:
    // 0x80075F5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80075F60: nop

    // 0x80075F64: beq         $a0, $zero, L_80075F78
    if (ctx->r4 == 0) {
        // 0x80075F68: lw          $a2, 0x68($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X68);
            goto L_80075F78;
    }
    // 0x80075F68: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80075F6C: jal         0x80071140
    // 0x80075F70: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80075F70: nop

    after_5:
    // 0x80075F74: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
L_80075F78:
    // 0x80075F78: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075F7C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80075F80: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x80075F84: sll         $a0, $t2, 3
    ctx->r4 = S32(ctx->r10 << 3);
    // 0x80075F88: jal         0x80070C9C
    // 0x80075F8C: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x80075F8C: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    after_6:
    // 0x80075F90: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80075F94: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80075F98: jal         0x800D04E0
    // 0x80075F9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _bzero(rdram, ctx);
        goto after_7;
    // 0x80075F9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80075FA0: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80075FA4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80075FA8: blez        $t3, L_80075FFC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80075FAC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80075FFC;
    }
    // 0x80075FAC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80075FB0: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x80075FB4: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x80075FB8: lw          $s2, 0xA4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA4);
    // 0x80075FBC: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80075FC0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80075FC4:
    // 0x80075FC4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80075FC8: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80075FCC: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x80075FD0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80075FD4: sb          $a0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r4;
    // 0x80075FD8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80075FDC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80075FE0: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80075FE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80075FE8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80075FEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80075FF0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80075FF4: bne         $at, $zero, L_80075FC4
    if (ctx->r1 != 0) {
        // 0x80075FF8: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_80075FC4;
    }
    // 0x80075FF8: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
L_80075FFC:
    // 0x80075FFC: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x80076000: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80076004: beq         $at, $zero, L_80076058
    if (ctx->r1 == 0) {
        // 0x80076008: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80076058;
    }
    // 0x80076008: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8007600C: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x80076010: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x80076014: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80076018: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x8007601C: addu        $a1, $t7, $a3
    ctx->r5 = ADD32(ctx->r15, ctx->r7);
    // 0x80076020: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x80076024: addu        $s0, $a3, $v1
    ctx->r16 = ADD32(ctx->r7, ctx->r3);
    // 0x80076028: addu        $s1, $t5, $v1
    ctx->r17 = ADD32(ctx->r13, ctx->r3);
    // 0x8007602C: addu        $s2, $t6, $s3
    ctx->r18 = ADD32(ctx->r14, ctx->r19);
L_80076030:
    // 0x80076030: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80076034: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80076038: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8007603C: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x80076040: sltu        $at, $s0, $a1
    ctx->r1 = ctx->r16 < ctx->r5 ? 1 : 0;
    // 0x80076044: sb          $a0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r4;
    // 0x80076048: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8007604C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80076050: bne         $at, $zero, L_80076030
    if (ctx->r1 != 0) {
        // 0x80076054: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80076030;
    }
    // 0x80076054: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80076058:
    // 0x80076058: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8007605C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80076060: blez        $t8, L_8007612C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80076064: nop
    
            goto L_8007612C;
    }
    // 0x80076064: nop

    // 0x80076068: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_8007606C:
    // 0x8007606C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80076070: jal         0x800D0580
    // 0x80076074: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    osPfsFileState_recomp(rdram, ctx);
        goto after_8;
    // 0x80076074: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_8:
    // 0x80076078: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007607C: bne         $v0, $at, L_80076090
    if (ctx->r2 != ctx->r1) {
        // 0x80076080: sll         $t9, $s3, 2
        ctx->r25 = S32(ctx->r19 << 2);
            goto L_80076090;
    }
    // 0x80076080: sll         $t9, $s3, 2
    ctx->r25 = S32(ctx->r19 << 2);
    // 0x80076084: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x80076088: b           L_80076118
    // 0x8007608C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80076118;
    // 0x8007608C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80076090:
    // 0x80076090: beq         $v0, $zero, L_800760A8
    if (ctx->r2 == 0) {
        // 0x80076094: addiu       $a0, $sp, 0x7E
        ctx->r4 = ADD32(ctx->r29, 0X7E);
            goto L_800760A8;
    }
    // 0x80076094: addiu       $a0, $sp, 0x7E
    ctx->r4 = ADD32(ctx->r29, 0X7E);
    // 0x80076098: jal         0x80075AEC
    // 0x8007609C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_9;
    // 0x8007609C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x800760A0: b           L_80076138
    // 0x800760A4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80076138;
    // 0x800760A4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800760A8:
    // 0x800760A8: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x800760AC: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x800760B0: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x800760B4: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x800760B8: addu        $t1, $s5, $v1
    ctx->r9 = ADD32(ctx->r21, ctx->r3);
    // 0x800760BC: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800760C0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800760C4: addu        $s1, $t2, $v1
    ctx->r17 = ADD32(ctx->r10, ctx->r3);
    // 0x800760C8: addu        $s0, $t3, $v1
    ctx->r16 = ADD32(ctx->r11, ctx->r3);
    // 0x800760CC: jal         0x8007698C
    // 0x800760D0: addu        $s2, $t4, $s3
    ctx->r18 = ADD32(ctx->r12, ctx->r19);
    font_codes_to_string(rdram, ctx);
        goto after_10;
    // 0x800760D0: addu        $s2, $t4, $s3
    ctx->r18 = ADD32(ctx->r12, ctx->r19);
    after_10:
    // 0x800760D4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800760D8: addiu       $a0, $sp, 0x7A
    ctx->r4 = ADD32(ctx->r29, 0X7A);
    // 0x800760DC: jal         0x8007698C
    // 0x800760E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    font_codes_to_string(rdram, ctx);
        goto after_11;
    // 0x800760E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
    // 0x800760E4: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800760E8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800760EC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800760F0: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
    // 0x800760F4: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800760F8: lhu         $t8, 0x78($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X78);
    // 0x800760FC: bne         $t7, $s6, L_80076118
    if (ctx->r15 != ctx->r22) {
        // 0x80076100: addiu       $at, $zero, 0x3459
        ctx->r1 = ADD32(0, 0X3459);
            goto L_80076118;
    }
    // 0x80076100: addiu       $at, $zero, 0x3459
    ctx->r1 = ADD32(0, 0X3459);
    // 0x80076104: bne         $t8, $at, L_80076118
    if (ctx->r24 != ctx->r1) {
        // 0x80076108: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80076118;
    }
    // 0x80076108: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8007610C: jal         0x80076AF4
    // 0x80076110: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    get_file_type(rdram, ctx);
        goto after_12;
    // 0x80076110: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_12:
    // 0x80076114: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80076118:
    // 0x80076118: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8007611C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80076120: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80076124: bne         $at, $zero, L_8007606C
    if (ctx->r1 != 0) {
        // 0x80076128: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_8007606C;
    }
    // 0x80076128: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_8007612C:
    // 0x8007612C: jal         0x80075AEC
    // 0x80076130: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_13;
    // 0x80076130: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_13:
    // 0x80076134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076138:
    // 0x80076138: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8007613C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80076140: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80076144: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80076148: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007614C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80076150: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80076154: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80076158: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8007615C: jr          $ra
    // 0x80076160: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80076160: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void alEvtqFlushType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9090: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C9094: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C9098: sll         $s3, $a1, 16
    ctx->r19 = S32(ctx->r5 << 16);
    // 0x800C909C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C90A0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C90A4: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800C90A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C90AC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x800C90B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C90B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C90B8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800C90BC: jal         0x800C9A30
    // 0x800C90C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C90C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C90C4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C90C8: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800C90CC: beq         $s0, $zero, L_800C9118
    if (ctx->r16 == 0) {
        // 0x800C90D0: nop
    
            goto L_800C9118;
    }
    // 0x800C90D0: nop

L_800C90D4:
    // 0x800C90D4: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x800C90D8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800C90DC: bne         $s3, $t7, L_800C9110
    if (ctx->r19 != ctx->r15) {
        // 0x800C90E0: nop
    
            goto L_800C9110;
    }
    // 0x800C90E0: nop

    // 0x800C90E4: beq         $s1, $zero, L_800C90FC
    if (ctx->r17 == 0) {
        // 0x800C90E8: nop
    
            goto L_800C90FC;
    }
    // 0x800C90E8: nop

    // 0x800C90EC: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800C90F0: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800C90F4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C90F8: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_800C90FC:
    // 0x800C90FC: jal         0x800C8760
    // 0x800C9100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C9100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9108: jal         0x800C8790
    // 0x800C910C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C910C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_800C9110:
    // 0x800C9110: bne         $s1, $zero, L_800C90D4
    if (ctx->r17 != 0) {
        // 0x800C9114: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800C90D4;
    }
    // 0x800C9114: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800C9118:
    // 0x800C9118: jal         0x800C9A30
    // 0x800C911C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C911C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800C9120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9124: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C9128: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C912C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9130: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C9134: jr          $ra
    // 0x800C9138: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C9138: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gfx_init_basic_xlu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F594: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007F598: sltiu       $at, $a1, 0x2
    ctx->r1 = ctx->r5 < 0X2 ? 1 : 0;
    // 0x8007F59C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007F5A0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8007F5A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8007F5A8: addiu       $v0, $v0, -0xC58
    ctx->r2 = ADD32(ctx->r2, -0XC58);
    // 0x8007F5AC: bne         $at, $zero, L_8007F5C0
    if (ctx->r1 != 0) {
        // 0x8007F5B0: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8007F5C0;
    }
    // 0x8007F5B0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8007F5B4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007F5B8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8007F5BC: addiu       $v0, $v0, -0xC28
    ctx->r2 = ADD32(ctx->r2, -0XC28);
L_8007F5C0:
    // 0x8007F5C0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8007F5C4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8007F5C8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8007F5CC: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8007F5D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F5D4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007F5D8: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x8007F5DC: addiu       $t2, $t2, -0xBF0
    ctx->r10 = ADD32(ctx->r10, -0XBF0);
    // 0x8007F5E0: addu        $t1, $t9, $at
    ctx->r9 = ADD32(ctx->r25, ctx->r1);
    // 0x8007F5E4: lui         $t8, 0x702
    ctx->r24 = S32(0X702 << 16);
    // 0x8007F5E8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007F5EC: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8007F5F0: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8007F5F4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8007F5F8: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x8007F5FC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8007F600: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x8007F604: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8007F608: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x8007F60C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8007F610: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x8007F614: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8007F618: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x8007F61C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007F620: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8007F624: addiu       $a0, $t0, 0x8
    ctx->r4 = ADD32(ctx->r8, 0X8);
    // 0x8007F628: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8007F62C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007F630: jr          $ra
    // 0x8007F634: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    return;
    // 0x8007F634: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
;}
RECOMP_FUNC void music_channel_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001228: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x8000122C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001230: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80001234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001238: bne         $at, $zero, L_80001248
    if (ctx->r1 != 0) {
        // 0x8000123C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80001248;
    }
    // 0x8000123C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001240: b           L_80001258
    // 0x80001244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80001258;
    // 0x80001244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80001248:
    // 0x80001248: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000124C: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80001250: jal         0x800C79A0
    // 0x80001254: nop

    alCSPGetChlVol(rdram, ctx);
        goto after_0;
    // 0x80001254: nop

    after_0:
L_80001258:
    // 0x80001258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000125C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001260: jr          $ra
    // 0x80001264: nop

    return;
    // 0x80001264: nop

;}
RECOMP_FUNC void func_8002458C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002458C: jr          $ra
    // 0x80024590: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80024590: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void apply_plane_tilt_anim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C0A0: lb          $t6, 0x1D7($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X1D7);
    // 0x8004C0A4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004C0A8: beq         $t6, $at, L_8004C138
    if (ctx->r14 == ctx->r1) {
        // 0x8004C0AC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8004C138;
    }
    // 0x8004C0AC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004C0B0: andi        $t7, $zero, 0xFF
    ctx->r15 = 0 & 0XFF;
    // 0x8004C0B4: bne         $t7, $zero, L_8004C138
    if (ctx->r15 != 0) {
        // 0x8004C0B8: sb          $zero, 0x1F2($a2)
        MEM_B(0X1F2, ctx->r6) = 0;
            goto L_8004C138;
    }
    // 0x8004C0B8: sb          $zero, 0x1F2($a2)
    MEM_B(0X1F2, ctx->r6) = 0;
    // 0x8004C0BC: lb          $v0, 0x1E1($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X1E1);
    // 0x8004C0C0: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x8004C0C4: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8004C0C8: subu        $v0, $t9, $t8
    ctx->r2 = SUB32(ctx->r25, ctx->r24);
    // 0x8004C0CC: bgez        $v0, L_8004C0D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004C0D0: sll         $a2, $a3, 2
        ctx->r6 = S32(ctx->r7 << 2);
            goto L_8004C0D8;
    }
    // 0x8004C0D0: sll         $a2, $a3, 2
    ctx->r6 = S32(ctx->r7 << 2);
    // 0x8004C0D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004C0D8:
    // 0x8004C0D8: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x8004C0DC: bne         $at, $zero, L_8004C0E8
    if (ctx->r1 != 0) {
        // 0x8004C0E0: nop
    
            goto L_8004C0E8;
    }
    // 0x8004C0E0: nop

    // 0x8004C0E4: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_8004C0E8:
    // 0x8004C0E8: lh          $a0, 0x18($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X18);
    // 0x8004C0EC: nop

    // 0x8004C0F0: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x8004C0F4: blez        $v1, L_8004C110
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004C0F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004C110;
    }
    // 0x8004C0F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004C0FC: subu        $v0, $a2, $a3
    ctx->r2 = SUB32(ctx->r6, ctx->r7);
    // 0x8004C100: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004C104: beq         $at, $zero, L_8004C110
    if (ctx->r1 == 0) {
        // 0x8004C108: nop
    
            goto L_8004C110;
    }
    // 0x8004C108: nop

    // 0x8004C10C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004C110:
    // 0x8004C110: bgez        $v1, L_8004C130
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004C114: negu        $at, $a3
        ctx->r1 = SUB32(0, ctx->r7);
            goto L_8004C130;
    }
    // 0x8004C114: negu        $at, $a3
    ctx->r1 = SUB32(0, ctx->r7);
    // 0x8004C118: sll         $a2, $at, 2
    ctx->r6 = S32(ctx->r1 << 2);
    // 0x8004C11C: subu        $v0, $a2, $at
    ctx->r2 = SUB32(ctx->r6, ctx->r1);
    // 0x8004C120: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004C124: beq         $at, $zero, L_8004C134
    if (ctx->r1 == 0) {
        // 0x8004C128: addu        $t0, $a0, $v0
        ctx->r8 = ADD32(ctx->r4, ctx->r2);
            goto L_8004C134;
    }
    // 0x8004C128: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C12C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004C130:
    // 0x8004C130: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
L_8004C134:
    // 0x8004C134: sh          $t0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r8;
L_8004C138:
    // 0x8004C138: jr          $ra
    // 0x8004C13C: nop

    return;
    // 0x8004C13C: nop

;}
RECOMP_FUNC void obj_init_lensflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004092C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040934: jal         0x800AC8A8
    // 0x80040938: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    lensflare_init(rdram, ctx);
        goto after_0;
    // 0x80040938: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004093C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040940: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040944: jr          $ra
    // 0x80040948: nop

    return;
    // 0x80040948: nop

;}
RECOMP_FUNC void rumble_exists(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800722E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800722EC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800722F0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800722F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800722F8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800722FC: bltz        $t7, L_80072310
    if (SIGNED(ctx->r15) < 0) {
        // 0x80072300: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80072310;
    }
    // 0x80072300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072304: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80072308: bne         $at, $zero, L_80072318
    if (ctx->r1 != 0) {
        // 0x8007230C: nop
    
            goto L_80072318;
    }
    // 0x8007230C: nop

L_80072310:
    // 0x80072310: b           L_80072338
    // 0x80072314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80072338;
    // 0x80072314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80072318:
    // 0x80072318: jal         0x80072250
    // 0x8007231C: nop

    input_get_id(rdram, ctx);
        goto after_0;
    // 0x8007231C: nop

    after_0:
    // 0x80072320: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80072324: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80072328: lbu         $t8, 0x41E5($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X41E5);
    // 0x8007232C: sllv        $t0, $t9, $v0
    ctx->r8 = S32(ctx->r25 << (ctx->r2 & 31));
    // 0x80072330: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80072334: and         $v0, $t8, $t1
    ctx->r2 = ctx->r24 & ctx->r9;
L_80072338:
    // 0x80072338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007233C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072340: jr          $ra
    // 0x80072344: nop

    return;
    // 0x80072344: nop

;}
RECOMP_FUNC void menu_audio_options_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084754: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084758: sh          $zero, 0x6C46($at)
    MEM_H(0X6C46, ctx->r1) = 0;
    // 0x8008475C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084760: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x80084764: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084768: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x8008476C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084774: sw          $zero, 0x69FC($at)
    MEM_W(0X69FC, ctx->r1) = 0;
    // 0x80084778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008477C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084780: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80084784: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084788: sw          $t6, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r14;
    // 0x8008478C: jal         0x8009C674
    // 0x80084790: addiu       $a0, $a0, -0x5D4
    ctx->r4 = ADD32(ctx->r4, -0X5D4);
    menu_assetgroup_load(rdram, ctx);
        goto after_0;
    // 0x80084790: addiu       $a0, $a0, -0x5D4
    ctx->r4 = ADD32(ctx->r4, -0X5D4);
    after_0:
    // 0x80084794: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084798: jal         0x8009C8A4
    // 0x8008479C: addiu       $a0, $a0, -0x5C8
    ctx->r4 = ADD32(ctx->r4, -0X5C8);
    menu_imagegroup_load(rdram, ctx);
        goto after_1;
    // 0x8008479C: addiu       $a0, $a0, -0x5C8
    ctx->r4 = ADD32(ctx->r4, -0X5C8);
    after_1:
    // 0x800847A0: jal         0x8008E4B0
    // 0x800847A4: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_2;
    // 0x800847A4: nop

    after_2:
    // 0x800847A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800847AC: jal         0x800C01D8
    // 0x800847B0: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x800847B0: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_3:
    // 0x800847B4: jal         0x8007FFEC
    // 0x800847B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8007FFEC(rdram, ctx);
        goto after_4;
    // 0x800847B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x800847BC: jal         0x80001AFC
    // 0x800847C0: nop

    music_volume_config(rdram, ctx);
        goto after_5;
    // 0x800847C0: nop

    after_5:
    // 0x800847C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800847C8: jal         0x8000317C
    // 0x800847CC: sw          $v0, -0x53C($at)
    MEM_W(-0X53C, ctx->r1) = ctx->r2;
    sndp_get_global_volume(rdram, ctx);
        goto after_6;
    // 0x800847CC: sw          $v0, -0x53C($at)
    MEM_W(-0X53C, ctx->r1) = ctx->r2;
    after_6:
    // 0x800847D0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800847D4: lw          $t7, -0x268($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X268);
    // 0x800847D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800847DC: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x800847E0: beq         $t8, $zero, L_8008481C
    if (ctx->r24 == 0) {
        // 0x800847E4: sw          $v0, -0x540($at)
        MEM_W(-0X540, ctx->r1) = ctx->r2;
            goto L_8008481C;
    }
    // 0x800847E4: sw          $v0, -0x540($at)
    MEM_W(-0X540, ctx->r1) = ctx->r2;
    // 0x800847E8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800847EC: lw          $t9, 0x69E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X69E0);
    // 0x800847F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800847F4: addiu       $v0, $v0, -0x5C4
    ctx->r2 = ADD32(ctx->r2, -0X5C4);
    // 0x800847F8: addiu       $t0, $zero, 0xD4
    ctx->r8 = ADD32(0, 0XD4);
    // 0x800847FC: sh          $t0, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r8;
    // 0x80084800: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80084804: jal         0x80000BE0
    // 0x80084808: sw          $t9, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r25;
    music_voicelimit_set(rdram, ctx);
        goto after_7;
    // 0x80084808: sw          $t9, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r25;
    after_7:
    // 0x8008480C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80084810: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084814: b           L_8008483C
    // 0x80084818: sw          $t1, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r9;
        goto L_8008483C;
    // 0x80084818: sw          $t1, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r9;
L_8008481C:
    // 0x8008481C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80084820: addiu       $v0, $v0, -0x5C4
    ctx->r2 = ADD32(ctx->r2, -0X5C4);
    // 0x80084824: addiu       $t2, $zero, 0xC0
    ctx->r10 = ADD32(0, 0XC0);
    // 0x80084828: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x8008482C: sh          $t2, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r10;
    // 0x80084830: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80084834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084838: sw          $t3, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r11;
L_8008483C:
    // 0x8008483C: jal         0x800C4170
    // 0x80084840: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_8;
    // 0x80084840: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80084844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008484C: jr          $ra
    // 0x80084850: nop

    return;
    // 0x80084850: nop

;}
RECOMP_FUNC void racerfx_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BADC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BAE0: addiu       $v0, $v0, -0x4FF8
    ctx->r2 = ADD32(ctx->r2, -0X4FF8);
    // 0x8000BAE4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000BAE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000BAEC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000BAF0: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8000BAF4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000BAF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BAFC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000BB00: sw          $zero, -0x5004($at)
    MEM_W(-0X5004, ctx->r1) = 0;
    // 0x8000BB04: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000BB08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000BB0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BB10: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000BB14: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000BB18: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000BB1C: sw          $zero, -0x4FFC($at)
    MEM_W(-0X4FFC, ctx->r1) = 0;
    // 0x8000BB20: jal         0x8001E29C
    // 0x8000BB24: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8000BB24: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x8000BB28: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8000BB2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BB30: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000BB34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000BB38: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8000BB3C: sw          $t9, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->r25;
    // 0x8000BB40: addiu       $a0, $a0, -0x4FE0
    ctx->r4 = ADD32(ctx->r4, -0X4FE0);
    // 0x8000BB44: addiu       $v1, $v1, -0x4F98
    ctx->r3 = ADD32(ctx->r3, -0X4F98);
    // 0x8000BB48: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000BB4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8000BB50:
    // 0x8000BB50: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x8000BB54: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8000BB58: beq         $t4, $zero, L_8000BB74
    if (ctx->r12 == 0) {
        // 0x8000BB5C: addu        $t7, $a0, $t5
        ctx->r15 = ADD32(ctx->r4, ctx->r13);
            goto L_8000BB74;
    }
    // 0x8000BB5C: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x8000BB60: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8000BB64: nop

    // 0x8000BB68: beq         $v0, $zero, L_8000BB74
    if (ctx->r2 == 0) {
        // 0x8000BB6C: nop
    
            goto L_8000BB74;
    }
    // 0x8000BB6C: nop

    // 0x8000BB70: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
L_8000BB74:
    // 0x8000BB74: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000BB78: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8000BB7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000BB80: bne         $at, $zero, L_8000BB50
    if (ctx->r1 != 0) {
        // 0x8000BB84: sb          $t2, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r10;
            goto L_8000BB50;
    }
    // 0x8000BB84: sb          $t2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r10;
    // 0x8000BB88: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000BB8C: lw          $t6, -0x5110($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5110);
    // 0x8000BB90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000BB94: blez        $t6, L_8000BF0C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000BB98: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000BF0C;
    }
    // 0x8000BB98: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000BB9C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8000BBA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000BBA4: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8000BBA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000BBAC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000BBB0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000BBB4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000BBB8: addiu       $s3, $s3, -0x511C
    ctx->r19 = ADD32(ctx->r19, -0X511C);
    // 0x8000BBBC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8000BBC0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
L_8000BBC4:
    // 0x8000BBC4: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8000BBC8: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8000BBCC: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8000BBD0: bne         $t8, $zero, L_8000BBE8
    if (ctx->r24 != 0) {
        // 0x8000BBD4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000BBE8;
    }
    // 0x8000BBD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BBD8: lwc1        $f6, 0x5138($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5138);
    // 0x8000BBDC: nop

    // 0x8000BBE0: mul.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000BBE4: nop

L_8000BBE8:
    // 0x8000BBE8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8000BBEC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000BBF0: addu        $t4, $t9, $s2
    ctx->r12 = ADD32(ctx->r25, ctx->r18);
    // 0x8000BBF4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8000BBF8: addiu       $t8, $t8, -0x4FF0
    ctx->r24 = ADD32(ctx->r24, -0X4FF0);
    // 0x8000BBFC: lw          $s0, 0x64($t5)
    ctx->r16 = MEM_W(ctx->r13, 0X64);
    // 0x8000BC00: nop

    // 0x8000BC04: lb          $a0, 0x2($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X2);
    // 0x8000BC08: lh          $t6, 0x18E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18E);
    // 0x8000BC0C: sll         $t7, $a0, 7
    ctx->r15 = S32(ctx->r4 << 7);
    // 0x8000BC10: beq         $t6, $zero, L_8000BC2C
    if (ctx->r14 == 0) {
        // 0x8000BC14: addu        $v0, $t7, $t3
        ctx->r2 = ADD32(ctx->r15, ctx->r11);
            goto L_8000BC2C;
    }
    // 0x8000BC14: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x8000BC18: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8000BC1C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8000BC20: nop

    // 0x8000BC24: addu        $t4, $t9, $s1
    ctx->r12 = ADD32(ctx->r25, ctx->r17);
    // 0x8000BC28: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
L_8000BC2C:
    // 0x8000BC2C: lbu         $t5, 0x72($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X72);
    // 0x8000BC30: nop

    // 0x8000BC34: addu        $t7, $t5, $s1
    ctx->r15 = ADD32(ctx->r13, ctx->r17);
    // 0x8000BC38: sb          $t7, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r15;
    // 0x8000BC3C: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x8000BC40: nop

    // 0x8000BC44: beq         $t6, $zero, L_8000BD4C
    if (ctx->r14 == 0) {
        // 0x8000BC48: nop
    
            goto L_8000BD4C;
    }
    // 0x8000BC48: nop

    // 0x8000BC4C: lbu         $t9, 0x70($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BC50: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8000BC54: bne         $t9, $zero, L_8000BC9C
    if (ctx->r25 != 0) {
        // 0x8000BC58: sb          $t8, 0x73($v0)
        MEM_B(0X73, ctx->r2) = ctx->r24;
            goto L_8000BC9C;
    }
    // 0x8000BC58: sb          $t8, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r24;
    // 0x8000BC5C: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8000BC60: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BC64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BC68: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000BC6C: swc1        $f4, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f4.u32l;
    // 0x8000BC70: lwc1        $f6, 0x513C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X513C);
    // 0x8000BC74: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BC78: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8000BC7C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8000BC80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BC84: bc1f        L_8000BC9C
    if (!c1cs) {
        // 0x8000BC88: nop
    
            goto L_8000BC9C;
    }
    // 0x8000BC88: nop

    // 0x8000BC8C: lwc1        $f8, 0x5140($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5140);
    // 0x8000BC90: sb          $t2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r10;
    // 0x8000BC94: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8000BC98: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_8000BC9C:
    // 0x8000BC9C: lbu         $t4, 0x70($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BCA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000BCA4: bne         $t4, $at, L_8000BCE8
    if (ctx->r12 != ctx->r1) {
        // 0x8000BCA8: nop
    
            goto L_8000BCE8;
    }
    // 0x8000BCA8: nop

    // 0x8000BCAC: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8000BCB0: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BCB4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8000BCB8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8000BCBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000BCC0: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x8000BCC4: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BCC8: nop

    // 0x8000BCCC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8000BCD0: nop

    // 0x8000BCD4: bc1f        L_8000BCE8
    if (!c1cs) {
        // 0x8000BCD8: nop
    
            goto L_8000BCE8;
    }
    // 0x8000BCD8: nop

    // 0x8000BCDC: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8000BCE0: sb          $t5, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r13;
    // 0x8000BCE4: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_8000BCE8:
    // 0x8000BCE8: lbu         $t7, 0x70($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BCEC: nop

    // 0x8000BCF0: bne         $t1, $t7, L_8000BD40
    if (ctx->r9 != ctx->r15) {
        // 0x8000BCF4: nop
    
            goto L_8000BD40;
    }
    // 0x8000BCF4: nop

    // 0x8000BCF8: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BCFC: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8000BD00: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8000BD04: nop

    // 0x8000BD08: bc1f        L_8000BD40
    if (!c1cs) {
        // 0x8000BD0C: nop
    
            goto L_8000BD40;
    }
    // 0x8000BD0C: nop

    // 0x8000BD10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000BD14: nop

    // 0x8000BD18: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8000BD1C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8000BD20: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x8000BD24: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BD28: nop

    // 0x8000BD2C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8000BD30: nop

    // 0x8000BD34: bc1f        L_8000BD40
    if (!c1cs) {
        // 0x8000BD38: nop
    
            goto L_8000BD40;
    }
    // 0x8000BD38: nop

    // 0x8000BD3C: swc1        $f14, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f14.u32l;
L_8000BD40:
    // 0x8000BD40: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BD44: b           L_8000BE00
    // 0x8000BD48: nop

        goto L_8000BE00;
    // 0x8000BD48: nop

L_8000BD4C:
    // 0x8000BD4C: lb          $a0, 0x73($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X73);
    // 0x8000BD50: nop

    // 0x8000BD54: blez        $a0, L_8000BD68
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000BD58: subu        $t6, $a0, $s1
        ctx->r14 = SUB32(ctx->r4, ctx->r17);
            goto L_8000BD68;
    }
    // 0x8000BD58: subu        $t6, $a0, $s1
    ctx->r14 = SUB32(ctx->r4, ctx->r17);
    // 0x8000BD5C: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BD60: b           L_8000BE00
    // 0x8000BD64: sb          $t6, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r14;
        goto L_8000BE00;
    // 0x8000BD64: sb          $t6, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r14;
L_8000BD68:
    // 0x8000BD68: lbu         $t8, 0x70($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BD6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BD70: bne         $t1, $t8, L_8000BDB4
    if (ctx->r9 != ctx->r24) {
        // 0x8000BD74: nop
    
            goto L_8000BDB4;
    }
    // 0x8000BD74: nop

    // 0x8000BD78: lwc1        $f6, 0x5144($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5144);
    // 0x8000BD7C: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BD80: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8000BD84: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8000BD88: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8000BD8C: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
    // 0x8000BD90: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BD94: nop

    // 0x8000BD98: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8000BD9C: nop

    // 0x8000BDA0: bc1f        L_8000BDB4
    if (!c1cs) {
        // 0x8000BDA4: nop
    
            goto L_8000BDB4;
    }
    // 0x8000BDA4: nop

    // 0x8000BDA8: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8000BDAC: sb          $zero, 0x70($v0)
    MEM_B(0X70, ctx->r2) = 0;
    // 0x8000BDB0: swc1        $f6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f6.u32l;
L_8000BDB4:
    // 0x8000BDB4: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BDB8: nop

    // 0x8000BDBC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000BDC0: beq         $at, $zero, L_8000BE00
    if (ctx->r1 == 0) {
        // 0x8000BDC4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000BE00;
    }
    // 0x8000BDC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BDC8: lwc1        $f8, 0x5148($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5148);
    // 0x8000BDCC: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BDD0: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8000BDD4: andi        $v1, $zero, 0xFF
    ctx->r3 = 0 & 0XFF;
    // 0x8000BDD8: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000BDDC: swc1        $f6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f6.u32l;
    // 0x8000BDE0: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BDE4: nop

    // 0x8000BDE8: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8000BDEC: nop

    // 0x8000BDF0: bc1f        L_8000BDFC
    if (!c1cs) {
        // 0x8000BDF4: nop
    
            goto L_8000BDFC;
    }
    // 0x8000BDF4: nop

    // 0x8000BDF8: swc1        $f12, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f12.u32l;
L_8000BDFC:
    // 0x8000BDFC: sb          $zero, 0x70($v0)
    MEM_B(0X70, ctx->r2) = 0;
L_8000BE00:
    // 0x8000BE00: bgtz        $v1, L_8000BE20
    if (SIGNED(ctx->r3) > 0) {
        // 0x8000BE04: nop
    
            goto L_8000BE20;
    }
    // 0x8000BE04: nop

    // 0x8000BE08: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BE0C: nop

    // 0x8000BE10: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8000BE14: nop

    // 0x8000BE18: bc1f        L_8000BE74
    if (!c1cs) {
        // 0x8000BE1C: nop
    
            goto L_8000BE74;
    }
    // 0x8000BE1C: nop

L_8000BE20:
    // 0x8000BE20: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8000BE24: lb          $a1, 0x2($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X2);
    // 0x8000BE28: addu        $t4, $t9, $s2
    ctx->r12 = ADD32(ctx->r25, ctx->r18);
    // 0x8000BE2C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8000BE30: lb          $a2, 0x1D7($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1D7);
    // 0x8000BE34: lb          $a3, 0x203($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X203);
    // 0x8000BE38: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8000BE3C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8000BE40: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8000BE44: jal         0x8000B750
    // 0x8000BE48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8000B750(rdram, ctx);
        goto after_1;
    // 0x8000BE48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8000BE4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000BE50: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000BE54: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8000BE58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000BE5C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8000BE60: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8000BE64: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000BE68: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000BE6C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8000BE70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8000BE74:
    // 0x8000BE74: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x8000BE78: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000BE7C: addiu       $t7, $t7, -0x4F88
    ctx->r15 = ADD32(ctx->r15, -0X4F88);
    // 0x8000BE80: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8000BE84: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x8000BE88: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8000BE8C: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x8000BE90: addu        $t8, $t6, $s1
    ctx->r24 = ADD32(ctx->r14, ctx->r17);
    // 0x8000BE94: addu        $t4, $t9, $s1
    ctx->r12 = ADD32(ctx->r25, ctx->r17);
    // 0x8000BE98: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8000BE9C: sb          $t4, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r12;
    // 0x8000BEA0: lb          $t5, 0x175($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X175);
    // 0x8000BEA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000BEA8: beq         $t5, $zero, L_8000BED8
    if (ctx->r13 == 0) {
        // 0x8000BEAC: nop
    
            goto L_8000BED8;
    }
    // 0x8000BEAC: nop

    // 0x8000BEB0: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x8000BEB4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8000BEB8: addu        $v1, $t7, $t6
    ctx->r3 = ADD32(ctx->r15, ctx->r14);
    // 0x8000BEBC: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8000BEC0: beq         $at, $zero, L_8000BED0
    if (ctx->r1 == 0) {
        // 0x8000BEC4: addiu       $t8, $zero, 0x20
        ctx->r24 = ADD32(0, 0X20);
            goto L_8000BED0;
    }
    // 0x8000BEC4: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8000BEC8: b           L_8000BEF8
    // 0x8000BECC: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
        goto L_8000BEF8;
    // 0x8000BECC: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
L_8000BED0:
    // 0x8000BED0: b           L_8000BEF8
    // 0x8000BED4: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
        goto L_8000BEF8;
    // 0x8000BED4: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
L_8000BED8:
    // 0x8000BED8: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x8000BEDC: nop

    // 0x8000BEE0: subu        $v1, $t9, $s1
    ctx->r3 = SUB32(ctx->r25, ctx->r17);
    // 0x8000BEE4: blez        $v1, L_8000BEF4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000BEE8: nop
    
            goto L_8000BEF4;
    }
    // 0x8000BEE8: nop

    // 0x8000BEEC: b           L_8000BEF8
    // 0x8000BEF0: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
        goto L_8000BEF8;
    // 0x8000BEF0: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
L_8000BEF4:
    // 0x8000BEF4: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
L_8000BEF8:
    // 0x8000BEF8: lw          $t4, -0x5110($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5110);
    // 0x8000BEFC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000BF00: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000BF04: bne         $at, $zero, L_8000BBC4
    if (ctx->r1 != 0) {
        // 0x8000BF08: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8000BBC4;
    }
    // 0x8000BF08: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8000BF0C:
    // 0x8000BF0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000BF10: lw          $a0, -0x389C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X389C);
    // 0x8000BF14: nop

    // 0x8000BF18: beq         $a0, $zero, L_8000BF2C
    if (ctx->r4 == 0) {
        // 0x8000BF1C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000BF2C;
    }
    // 0x8000BF1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF20: jal         0x80011134
    // 0x8000BF24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    obj_tex_animate(rdram, ctx);
        goto after_2;
    // 0x8000BF24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8000BF28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000BF2C:
    // 0x8000BF2C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BF30: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000BF34: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000BF38: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000BF3C: jr          $ra
    // 0x8000BF40: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000BF40: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void get_level_default_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DB30: lw          $v0, 0x3518($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3518);
    // 0x8006DB34: jr          $ra
    // 0x8006DB38: nop

    return;
    // 0x8006DB38: nop

;}
RECOMP_FUNC void mtxf_from_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070638: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8007063C: addiu       $t1, $t0, 0x40
    ctx->r9 = ADD32(ctx->r8, 0X40);
L_80070640:
    // 0x80070640: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80070644: bne         $t1, $t0, L_80070640
    if (ctx->r9 != ctx->r8) {
        // 0x80070648: sw          $zero, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = 0;
            goto L_80070640;
    }
    // 0x80070648: sw          $zero, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = 0;
    // 0x8007064C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070650: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070654: nop

    // 0x80070658: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x8007065C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80070660: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    // 0x80070664: jr          $ra
    // 0x80070668: sw          $a3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r7;
    return;
    // 0x80070668: sw          $a3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void level_properties_pop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C22C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006C230: addiu       $t0, $t0, -0x2CD8
    ctx->r8 = ADD32(ctx->r8, -0X2CD8);
    // 0x8006C234: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x8006C238: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006C23C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006C240: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x8006C244: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8006C248: addiu       $t1, $t1, 0x11C8
    ctx->r9 = ADD32(ctx->r9, 0X11C8);
    // 0x8006C24C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8006C250: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x8006C254: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8006C258: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006C25C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8006C260: lh          $t4, 0x0($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X0);
    // 0x8006C264: nop

    // 0x8006C268: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8006C26C: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x8006C270: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C274: nop

    // 0x8006C278: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8006C27C: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8006C280: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
    // 0x8006C284: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8006C288: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8006C28C: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x8006C290: nop

    // 0x8006C294: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8006C298: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006C29C: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8006C2A0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006C2A4: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8006C2A8: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x8006C2AC: nop

    // 0x8006C2B0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8006C2B4: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
    // 0x8006C2B8: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8006C2BC: nop

    // 0x8006C2C0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8006C2C4: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x8006C2C8: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x8006C2CC: beq         $v1, $at, L_8006C2D8
    if (ctx->r3 == ctx->r1) {
        // 0x8006C2D0: sw          $t2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r10;
            goto L_8006C2D8;
    }
    // 0x8006C2D0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8006C2D4: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
L_8006C2D8:
    // 0x8006C2D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C2DC: jr          $ra
    // 0x8006C2E0: sh          $t3, -0x2CD4($at)
    MEM_H(-0X2CD4, ctx->r1) = ctx->r11;
    return;
    // 0x8006C2E0: sh          $t3, -0x2CD4($at)
    MEM_H(-0X2CD4, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void obj_init_lasergun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034530: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80034534: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80034538: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003453C: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80034540: nop

    // 0x80034544: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80034548: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003454C: lb          $t9, 0xA($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XA);
    // 0x80034550: nop

    // 0x80034554: sb          $t9, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r25;
    // 0x80034558: lb          $t0, 0xB($a1)
    ctx->r8 = MEM_B(ctx->r5, 0XB);
    // 0x8003455C: nop

    // 0x80034560: sb          $t0, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r8;
    // 0x80034564: lbu         $t1, 0xC($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XC);
    // 0x80034568: lb          $t3, 0xF($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XF);
    // 0x8003456C: sb          $t1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r9;
    // 0x80034570: lbu         $t2, 0xD($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XD);
    // 0x80034574: sh          $t3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r11;
    // 0x80034578: sb          $t2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r10;
    // 0x8003457C: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x80034580: nop

    // 0x80034584: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80034588: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x8003458C: lbu         $t8, 0x9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X9);
    // 0x80034590: nop

    // 0x80034594: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80034598: jr          $ra
    // 0x8003459C: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    return;
    // 0x8003459C: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void get_object_list_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E4B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E4B8: lw          $v0, -0x51A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A0);
    // 0x8001E4BC: jr          $ra
    // 0x8001E4C0: nop

    return;
    // 0x8001E4C0: nop

;}
RECOMP_FUNC void _frexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB104: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800CB108: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800CB10C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800CB110: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CB114: nop

    // 0x800CB118: c.eq.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d == ctx->f4.d;
    // 0x800CB11C: nop

    // 0x800CB120: bc1f        L_800CB130
    if (!c1cs) {
        // 0x800CB124: nop
    
            goto L_800CB130;
    }
    // 0x800CB124: nop

    // 0x800CB128: b           L_800CB280
    // 0x800CB12C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800CB280;
    // 0x800CB12C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
L_800CB130:
    // 0x800CB130: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800CB134: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB138: nop

    // 0x800CB13C: c.lt.d      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.d < ctx->f12.d;
    // 0x800CB140: nop

    // 0x800CB144: bc1f        L_800CB158
    if (!c1cs) {
        // 0x800CB148: nop
    
            goto L_800CB158;
    }
    // 0x800CB148: nop

    // 0x800CB14C: swc1        $f13, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x800CB150: b           L_800CB164
    // 0x800CB154: swc1        $f12, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f12.u32l;
        goto L_800CB164;
    // 0x800CB154: swc1        $f12, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f12.u32l;
L_800CB158:
    // 0x800CB158: neg.d       $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = -ctx->f12.d;
    // 0x800CB15C: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x800CB160: swc1        $f9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
L_800CB164:
    // 0x800CB164: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CB168: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CB16C: lwc1        $f11, 0x8($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB170: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB174: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CB178: nop

    // 0x800CB17C: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x800CB180: nop

    // 0x800CB184: bc1f        L_800CB1D4
    if (!c1cs) {
        // 0x800CB188: nop
    
            goto L_800CB1D4;
    }
    // 0x800CB188: nop

L_800CB18C:
    // 0x800CB18C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800CB190: nop

    // 0x800CB194: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CB198: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800CB19C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CB1A0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800CB1A4: lwc1        $f19, 0x8($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB1A8: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB1AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CB1B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CB1B4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800CB1B8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800CB1BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CB1C0: nop

    // 0x800CB1C4: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x800CB1C8: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x800CB1CC: bc1t        L_800CB18C
    if (c1cs) {
        // 0x800CB1D0: swc1        $f7, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
            goto L_800CB18C;
    }
    // 0x800CB1D0: swc1        $f7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
L_800CB1D4:
    // 0x800CB1D4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CB1D8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CB1DC: lwc1        $f11, 0x8($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB1E0: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB1E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CB1E8: nop

    // 0x800CB1EC: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x800CB1F0: nop

    // 0x800CB1F4: bc1f        L_800CB234
    if (!c1cs) {
        // 0x800CB1F8: nop
    
            goto L_800CB234;
    }
    // 0x800CB1F8: nop

L_800CB1FC:
    // 0x800CB1FC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800CB200: nop

    // 0x800CB204: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800CB208: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CB20C: lwc1        $f19, 0x8($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB210: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB214: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CB218: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CB21C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB220: add.d       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f18.d + ctx->f18.d;
    // 0x800CB224: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800CB228: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x800CB22C: bc1t        L_800CB1FC
    if (c1cs) {
        // 0x800CB230: swc1        $f5, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
            goto L_800CB1FC;
    }
    // 0x800CB230: swc1        $f5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
L_800CB234:
    // 0x800CB234: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800CB238: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CB23C: nop

    // 0x800CB240: c.lt.d      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.d < ctx->f12.d;
    // 0x800CB244: nop

    // 0x800CB248: bc1f        L_800CB260
    if (!c1cs) {
        // 0x800CB24C: nop
    
            goto L_800CB260;
    }
    // 0x800CB24C: nop

    // 0x800CB250: lwc1        $f15, 0x8($sp)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB254: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB258: b           L_800CB270
    // 0x800CB25C: nop

        goto L_800CB270;
    // 0x800CB25C: nop

L_800CB260:
    // 0x800CB260: lwc1        $f15, 0x8($sp)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB264: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB268: nop

    // 0x800CB26C: neg.d       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f14.d = -ctx->f14.d;
L_800CB270:
    // 0x800CB270: b           L_800CB280
    // 0x800CB274: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
        goto L_800CB280;
    // 0x800CB274: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
    // 0x800CB278: b           L_800CB280
    // 0x800CB27C: nop

        goto L_800CB280;
    // 0x800CB27C: nop

L_800CB280:
    // 0x800CB280: jr          $ra
    // 0x800CB284: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800CB284: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void light_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032398: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003239C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800323A0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800323A4: addiu       $s3, $s3, -0x36A4
    ctx->r19 = ADD32(ctx->r19, -0X36A4);
    // 0x800323A8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800323AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800323B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800323B4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800323B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800323BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800323C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800323C4: blez        $t6, L_80032404
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800323C8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80032404;
    }
    // 0x800323C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800323CC: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800323D0: addiu       $s4, $s4, -0x36B0
    ctx->r20 = ADD32(ctx->r20, -0X36B0);
    // 0x800323D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800323D8:
    // 0x800323D8: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800323DC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800323E0: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800323E4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800323E8: jal         0x80032424
    // 0x800323EC: nop

    light_update(rdram, ctx);
        goto after_0;
    // 0x800323EC: nop

    after_0:
    // 0x800323F0: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800323F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800323F8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800323FC: bne         $at, $zero, L_800323D8
    if (ctx->r1 != 0) {
        // 0x80032400: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800323D8;
    }
    // 0x80032400: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80032404:
    // 0x80032404: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80032408: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003240C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80032410: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80032414: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80032418: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003241C: jr          $ra
    // 0x80032420: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80032420: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void clear_dialogue_box_open_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C56D0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C56D4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C56D8: lw          $t6, -0x5818($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5818);
    // 0x800C56DC: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C56E0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C56E4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C56E8: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C56EC: nop

    // 0x800C56F0: andi        $t9, $t8, 0xBFFF
    ctx->r25 = ctx->r24 & 0XBFFF;
    // 0x800C56F4: jr          $ra
    // 0x800C56F8: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C56F8: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void ghostmenu_erase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800998E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800998E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800998E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800998EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800998F0: bltz        $a0, L_80099A48
    if (SIGNED(ctx->r4) < 0) {
        // 0x800998F4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80099A48;
    }
    // 0x800998F4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800998F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800998FC: addiu       $v1, $v1, 0x64D4
    ctx->r3 = ADD32(ctx->r3, 0X64D4);
    // 0x80099900: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80099904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80099908: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8009990C: beq         $at, $zero, L_80099A48
    if (ctx->r1 == 0) {
        // 0x80099910: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80099A48;
    }
    // 0x80099910: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80099914: jal         0x80001D04
    // 0x80099918: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80099918: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8009991C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80099920: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80099924: addu        $s0, $s0, $a2
    ctx->r16 = ADD32(ctx->r16, ctx->r6);
    // 0x80099928: lbu         $s0, 0x6540($s0)
    ctx->r16 = MEM_BU(ctx->r16, 0X6540);
    // 0x8009992C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80099930: lw          $a0, 0x64D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64D0);
    // 0x80099934: jal         0x800753D8
    // 0x80099938: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800753D8(rdram, ctx);
        goto after_1;
    // 0x80099938: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8009993C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80099940: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80099944: addiu       $v1, $v1, 0x64D4
    ctx->r3 = ADD32(ctx->r3, 0X64D4);
    // 0x80099948: bne         $v0, $zero, L_80099A48
    if (ctx->r2 != 0) {
        // 0x8009994C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_80099A48;
    }
    // 0x8009994C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80099950: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099954: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80099958: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009995C: sb          $t7, 0x64DC($at)
    MEM_B(0X64DC, ctx->r1) = ctx->r15;
    // 0x80099960: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80099964: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80099968: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8009996C: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80099970: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80099974: beq         $at, $zero, L_80099A10
    if (ctx->r1 == 0) {
        // 0x80099978: or          $t1, $t9, $zero
        ctx->r9 = ctx->r25 | 0;
            goto L_80099A10;
    }
    // 0x80099978: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8009997C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80099980: addiu       $t3, $t3, 0x6540
    ctx->r11 = ADD32(ctx->r11, 0X6540);
    // 0x80099984: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
    // 0x80099988: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009998C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80099990: addiu       $t5, $t5, 0x6510
    ctx->r13 = ADD32(ctx->r13, 0X6510);
    // 0x80099994: addiu       $t4, $t4, 0x6508
    ctx->r12 = ADD32(ctx->r12, 0X6508);
    // 0x80099998: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009999C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800999A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800999A4: addiu       $t8, $t8, 0x6520
    ctx->r24 = ADD32(ctx->r24, 0X6520);
    // 0x800999A8: addiu       $t6, $t6, 0x6518
    ctx->r14 = ADD32(ctx->r14, 0X6518);
    // 0x800999AC: addiu       $t3, $t3, 0x6520
    ctx->r11 = ADD32(ctx->r11, 0X6520);
    // 0x800999B0: addu        $a0, $a2, $t4
    ctx->r4 = ADD32(ctx->r6, ctx->r12);
    // 0x800999B4: addu        $a1, $a2, $t5
    ctx->r5 = ADD32(ctx->r6, ctx->r13);
    // 0x800999B8: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x800999BC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800999C0: addu        $a3, $t9, $t3
    ctx->r7 = ADD32(ctx->r25, ctx->r11);
    // 0x800999C4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800999C8: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_800999CC:
    // 0x800999CC: lbu         $t4, 0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1);
    // 0x800999D0: lbu         $t5, 0x1($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X1);
    // 0x800999D4: lbu         $t6, 0x1($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1);
    // 0x800999D8: lbu         $t7, 0x1($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1);
    // 0x800999DC: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x800999E0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800999E4: sltu        $at, $v1, $a3
    ctx->r1 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x800999E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800999EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800999F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800999F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800999F8: sb          $t4, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r12;
    // 0x800999FC: sb          $t5, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r13;
    // 0x80099A00: sb          $t6, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r14;
    // 0x80099A04: sb          $t7, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r15;
    // 0x80099A08: bne         $at, $zero, L_800999CC
    if (ctx->r1 != 0) {
        // 0x80099A0C: sh          $t8, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r24;
            goto L_800999CC;
    }
    // 0x80099A0C: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
L_80099A10:
    // 0x80099A10: blez        $t1, L_80099A48
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80099A14: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80099A48;
    }
    // 0x80099A14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80099A18: addiu       $v0, $t9, 0x6540
    ctx->r2 = ADD32(ctx->r25, 0X6540);
    // 0x80099A1C: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
L_80099A20:
    // 0x80099A20: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80099A24: nop

    // 0x80099A28: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80099A2C: beq         $at, $zero, L_80099A38
    if (ctx->r1 == 0) {
        // 0x80099A30: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_80099A38;
    }
    // 0x80099A30: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80099A34: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_80099A38:
    // 0x80099A38: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80099A3C: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80099A40: bne         $at, $zero, L_80099A20
    if (ctx->r1 != 0) {
        // 0x80099A44: nop
    
            goto L_80099A20;
    }
    // 0x80099A44: nop

L_80099A48:
    // 0x80099A48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80099A4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80099A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80099A54: jr          $ra
    // 0x80099A58: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x80099A58: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
;}
RECOMP_FUNC void get_level_segment_index_from_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029F18: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80029F1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80029F20: lw          $v0, -0x36E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36E8);
    // 0x80029F24: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80029F28: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80029F2C: bne         $v0, $zero, L_80029F3C
    if (ctx->r2 != 0) {
        // 0x80029F30: swc1        $f21, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
            goto L_80029F3C;
    }
    // 0x80029F30: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80029F34: b           L_8002A04C
    // 0x80029F38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8002A04C;
    // 0x80029F38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80029F3C:
    // 0x80029F3C: lh          $a3, 0x1A($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X1A);
    // 0x80029F40: lui         $a0, 0xF
    ctx->r4 = S32(0XF << 16);
    // 0x80029F44: ori         $a0, $a0, 0x4240
    ctx->r4 = ctx->r4 | 0X4240;
    // 0x80029F48: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80029F4C: blez        $a3, L_8002A048
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80029F50: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8002A048;
    }
    // 0x80029F50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80029F54: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80029F58: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80029F5C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80029F60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029F64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029F68: nop

    // 0x80029F6C: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80029F70: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80029F74: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80029F78: nop

L_80029F7C:
    // 0x80029F7C: lh          $t7, 0x6($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X6);
    // 0x80029F80: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80029F84: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80029F88: beq         $at, $zero, L_8002A038
    if (ctx->r1 == 0) {
        // 0x80029F8C: nop
    
            goto L_8002A038;
    }
    // 0x80029F8C: nop

    // 0x80029F90: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x80029F94: nop

    // 0x80029F98: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029F9C: beq         $at, $zero, L_8002A038
    if (ctx->r1 == 0) {
        // 0x80029FA0: nop
    
            goto L_8002A038;
    }
    // 0x80029FA0: nop

    // 0x80029FA4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80029FA8: lh          $t2, 0xA($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XA);
    // 0x80029FAC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80029FB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029FB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029FB8: nop

    // 0x80029FBC: cvt.w.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = CVT_W_S(ctx->f20.fl);
    // 0x80029FC0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80029FC4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80029FC8: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029FCC: beq         $at, $zero, L_8002A038
    if (ctx->r1 == 0) {
        // 0x80029FD0: nop
    
            goto L_8002A038;
    }
    // 0x80029FD0: nop

    // 0x80029FD4: lh          $t3, 0x4($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X4);
    // 0x80029FD8: nop

    // 0x80029FDC: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80029FE0: beq         $at, $zero, L_8002A038
    if (ctx->r1 == 0) {
        // 0x80029FE4: nop
    
            goto L_8002A038;
    }
    // 0x80029FE4: nop

    // 0x80029FE8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80029FEC: lh          $t4, 0x8($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X8);
    // 0x80029FF0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80029FF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029FF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029FFC: lh          $t5, 0x2($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X2);
    // 0x8002A000: cvt.w.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8002A004: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8002A008: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8002A00C: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8002A010: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002A014: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x8002A018: bgez        $v0, L_8002A028
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002A01C: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8002A028;
    }
    // 0x8002A01C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A020: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8002A024: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
L_8002A028:
    // 0x8002A028: beq         $at, $zero, L_8002A038
    if (ctx->r1 == 0) {
        // 0x8002A02C: nop
    
            goto L_8002A038;
    }
    // 0x8002A02C: nop

    // 0x8002A030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002A034: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_8002A038:
    // 0x8002A038: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002A03C: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8002A040: bne         $at, $zero, L_80029F7C
    if (ctx->r1 != 0) {
        // 0x8002A044: addiu       $t1, $t1, 0xC
        ctx->r9 = ADD32(ctx->r9, 0XC);
            goto L_80029F7C;
    }
    // 0x8002A044: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
L_8002A048:
    // 0x8002A048: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8002A04C:
    // 0x8002A04C: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x8002A050: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8002A054: jr          $ra
    // 0x8002A058: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002A058: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void hud_battle_portraits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1E48: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800A1E4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A1E50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A1E54: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800A1E58: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800A1E5C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800A1E60: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800A1E64: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800A1E68: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A1E6C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A1E70: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A1E74: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A1E78: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A1E7C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A1E80: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800A1E84: jal         0x8001BA74
    // 0x800A1E88: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800A1E88: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_0:
    // 0x800A1E8C: beq         $s0, $zero, L_800A1EA0
    if (ctx->r16 == 0) {
        // 0x800A1E90: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800A1EA0;
    }
    // 0x800A1E90: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800A1E94: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800A1E98: b           L_800A1EB4
    // 0x800A1E9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800A1EB4;
    // 0x800A1E9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800A1EA0:
    // 0x800A1EA0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800A1EA4: nop

    // 0x800A1EA8: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x800A1EAC: nop

    // 0x800A1EB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800A1EB4:
    // 0x800A1EB4: jal         0x80068508
    // 0x800A1EB8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A1EB8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    after_1:
    // 0x800A1EBC: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800A1EC0: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x800A1EC4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A1EC8: bne         $t7, $at, L_800A22B4
    if (ctx->r15 != ctx->r1) {
        // 0x800A1ECC: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800A22B4;
    }
    // 0x800A1ECC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A1ED0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A1ED4: addiu       $s0, $s0, 0x6CDC
    ctx->r16 = ADD32(ctx->r16, 0X6CDC);
    // 0x800A1ED8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A1EDC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A1EE0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1EE4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1EE8: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1EEC: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A1EF0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1EF4: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800A1EF8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A1EFC: mfc1        $s4, $f6
    ctx->r20 = (int32_t)ctx->f6.u32l;
    // 0x800A1F00: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A1F04: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A1F08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A1F0C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A1F10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1F14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1F18: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1F1C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1F20: lwc1        $f21, -0x78D0($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X78D0);
    // 0x800A1F24: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A1F28: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800A1F2C: lwc1        $f20, -0x78CC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X78CC);
    // 0x800A1F30: addiu       $s5, $s5, 0x6D37
    ctx->r21 = ADD32(ctx->r21, 0X6D37);
    // 0x800A1F34: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800A1F38: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x800A1F3C: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x800A1F40: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800A1F44: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
L_800A1F48:
    // 0x800A1F48: mtc1        $s4, $f16
    ctx->f16.u32l = ctx->r20;
    // 0x800A1F4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A1F50: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A1F54: lwc1        $f12, 0x64C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1F58: addu        $t3, $s1, $t0
    ctx->r11 = ADD32(ctx->r17, ctx->r8);
    // 0x800A1F5C: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800A1F60: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A1F64: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A1F68: lwc1        $f16, 0x650($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A1F6C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A1F70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1F74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1F78: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800A1F7C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1F80: lw          $a0, 0x64($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X64);
    // 0x800A1F84: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A1F88: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A1F8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A1F90: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800A1F94: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A1F98: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A1F9C: nop

    // 0x800A1FA0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A1FA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1FA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1FAC: nop

    // 0x800A1FB0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A1FB4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A1FB8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800A1FBC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A1FC0: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x800A1FC4: add.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A1FC8: swc1        $f8, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f8.u32l;
    // 0x800A1FCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A1FD0: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A1FD4: lwc1        $f16, 0x650($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A1FD8: nop

    // 0x800A1FDC: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A1FE0: swc1        $f18, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f18.u32l;
    // 0x800A1FE4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A1FE8: nop

    // 0x800A1FEC: lwc1        $f4, 0x68C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X68C);
    // 0x800A1FF0: nop

    // 0x800A1FF4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A1FF8: swc1        $f6, 0x68C($v0)
    MEM_W(0X68C, ctx->r2) = ctx->f6.u32l;
    // 0x800A1FFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2000: nop

    // 0x800A2004: lwc1        $f8, 0x690($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X690);
    // 0x800A2008: nop

    // 0x800A200C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800A2010: swc1        $f10, 0x690($v0)
    MEM_W(0X690, ctx->r2) = ctx->f10.u32l;
    // 0x800A2014: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2018: nop

    // 0x800A201C: lwc1        $f16, 0x6AC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6AC);
    // 0x800A2020: nop

    // 0x800A2024: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A2028: swc1        $f18, 0x6AC($v0)
    MEM_W(0X6AC, ctx->r2) = ctx->f18.u32l;
    // 0x800A202C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2030: nop

    // 0x800A2034: lwc1        $f4, 0x6B0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6B0);
    // 0x800A2038: nop

    // 0x800A203C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A2040: swc1        $f6, 0x6B0($v0)
    MEM_W(0X6B0, ctx->r2) = ctx->f6.u32l;
    // 0x800A2044: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2048: nop

    // 0x800A204C: lwc1        $f8, 0x6CC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A2050: nop

    // 0x800A2054: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A2058: swc1        $f10, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f10.u32l;
    // 0x800A205C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2060: nop

    // 0x800A2064: lwc1        $f16, 0x6D0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6D0);
    // 0x800A2068: nop

    // 0x800A206C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A2070: swc1        $f18, 0x6D0($v0)
    MEM_W(0X6D0, ctx->r2) = ctx->f18.u32l;
    // 0x800A2074: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2078: nop

    // 0x800A207C: lwc1        $f4, 0x6EC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6EC);
    // 0x800A2080: nop

    // 0x800A2084: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A2088: swc1        $f6, 0x6EC($v0)
    MEM_W(0X6EC, ctx->r2) = ctx->f6.u32l;
    // 0x800A208C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2090: nop

    // 0x800A2094: lwc1        $f8, 0x6F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6F0);
    // 0x800A2098: nop

    // 0x800A209C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A20A0: swc1        $f10, 0x6F0($v0)
    MEM_W(0X6F0, ctx->r2) = ctx->f10.u32l;
    // 0x800A20A4: lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X0);
    // 0x800A20A8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800A20AC: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A20B0: bne         $at, $zero, L_800A20CC
    if (ctx->r1 != 0) {
        // 0x800A20B4: nop
    
            goto L_800A20CC;
    }
    // 0x800A20B4: nop

    // 0x800A20B8: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x800A20BC: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800A20C0: nop

    // 0x800A20C4: bne         $t5, $t6, L_800A20E8
    if (ctx->r13 != ctx->r14) {
        // 0x800A20C8: nop
    
            goto L_800A20E8;
    }
    // 0x800A20C8: nop

L_800A20CC:
    // 0x800A20CC: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x800A20D0: jal         0x800A22F4
    // 0x800A20D4: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    hud_lives_render(rdram, ctx);
        goto after_2;
    // 0x800A20D4: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800A20D8: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x800A20DC: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800A20E0: lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X0);
    // 0x800A20E4: nop

L_800A20E8:
    // 0x800A20E8: bne         $s6, $v1, L_800A20F8
    if (ctx->r22 != ctx->r3) {
        // 0x800A20EC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800A20F8;
    }
    // 0x800A20EC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800A20F0: b           L_800A2150
    // 0x800A20F4: addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
        goto L_800A2150;
    // 0x800A20F4: addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
L_800A20F8:
    // 0x800A20F8: bne         $fp, $v1, L_800A2150
    if (ctx->r30 != ctx->r3) {
        // 0x800A20FC: lui         $t7, 0x8000
        ctx->r15 = S32(0X8000 << 16);
            goto L_800A2150;
    }
    // 0x800A20FC: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800A2100: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800A2104: nop

    // 0x800A2108: bne         $t7, $zero, L_800A214C
    if (ctx->r15 != 0) {
        // 0x800A210C: nop
    
            goto L_800A214C;
    }
    // 0x800A210C: nop

    // 0x800A2110: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x800A2114: nop

    // 0x800A2118: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800A211C: add.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = ctx->f18.d + ctx->f20.d;
    // 0x800A2120: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A2124: nop

    // 0x800A2128: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A212C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2130: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2134: nop

    // 0x800A2138: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800A213C: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x800A2140: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A2144: b           L_800A2150
    // 0x800A2148: nop

        goto L_800A2150;
    // 0x800A2148: nop

L_800A214C:
    // 0x800A214C: addiu       $s1, $s1, 0x37
    ctx->r17 = ADD32(ctx->r17, 0X37);
L_800A2150:
    // 0x800A2150: bne         $s2, $s7, L_800A1F48
    if (ctx->r18 != ctx->r23) {
        // 0x800A2154: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800A1F48;
    }
    // 0x800A2154: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800A2158: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800A215C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2160: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800A2164: lwc1        $f12, 0x64C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A2168: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A216C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A2170: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A2174: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A2178: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A217C: nop

    // 0x800A2180: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A2184: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2188: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A218C: nop

    // 0x800A2190: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A2194: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A2198: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A219C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A21A0: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800A21A4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A21A8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A21AC: nop

    // 0x800A21B0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A21B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A21B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A21BC: nop

    // 0x800A21C0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A21C4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A21C8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800A21CC: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A21D0: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800A21D4: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A21D8: swc1        $f4, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f4.u32l;
    // 0x800A21DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A21E0: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A21E4: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A21E8: nop

    // 0x800A21EC: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A21F0: swc1        $f10, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f10.u32l;
    // 0x800A21F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A21F8: nop

    // 0x800A21FC: lwc1        $f16, 0x68C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68C);
    // 0x800A2200: nop

    // 0x800A2204: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A2208: swc1        $f18, 0x68C($v0)
    MEM_W(0X68C, ctx->r2) = ctx->f18.u32l;
    // 0x800A220C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2210: nop

    // 0x800A2214: lwc1        $f4, 0x690($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X690);
    // 0x800A2218: nop

    // 0x800A221C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A2220: swc1        $f6, 0x690($v0)
    MEM_W(0X690, ctx->r2) = ctx->f6.u32l;
    // 0x800A2224: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2228: nop

    // 0x800A222C: lwc1        $f8, 0x6AC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6AC);
    // 0x800A2230: nop

    // 0x800A2234: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A2238: swc1        $f10, 0x6AC($v0)
    MEM_W(0X6AC, ctx->r2) = ctx->f10.u32l;
    // 0x800A223C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2240: nop

    // 0x800A2244: lwc1        $f16, 0x6B0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6B0);
    // 0x800A2248: nop

    // 0x800A224C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A2250: swc1        $f18, 0x6B0($v0)
    MEM_W(0X6B0, ctx->r2) = ctx->f18.u32l;
    // 0x800A2254: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2258: nop

    // 0x800A225C: lwc1        $f4, 0x6CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A2260: nop

    // 0x800A2264: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A2268: swc1        $f6, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f6.u32l;
    // 0x800A226C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2270: nop

    // 0x800A2274: lwc1        $f8, 0x6D0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6D0);
    // 0x800A2278: nop

    // 0x800A227C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A2280: swc1        $f10, 0x6D0($v0)
    MEM_W(0X6D0, ctx->r2) = ctx->f10.u32l;
    // 0x800A2284: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2288: nop

    // 0x800A228C: lwc1        $f16, 0x6EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6EC);
    // 0x800A2290: nop

    // 0x800A2294: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A2298: swc1        $f18, 0x6EC($v0)
    MEM_W(0X6EC, ctx->r2) = ctx->f18.u32l;
    // 0x800A229C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A22A0: nop

    // 0x800A22A4: lwc1        $f4, 0x6F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6F0);
    // 0x800A22A8: nop

    // 0x800A22AC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A22B0: swc1        $f6, 0x6F0($v0)
    MEM_W(0X6F0, ctx->r2) = ctx->f6.u32l;
L_800A22B4:
    // 0x800A22B4: jal         0x80068508
    // 0x800A22B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_3;
    // 0x800A22B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800A22BC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800A22C0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A22C4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A22C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A22CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A22D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A22D4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A22D8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A22DC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800A22E0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800A22E4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800A22E8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800A22EC: jr          $ra
    // 0x800A22F0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800A22F0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void get_next_particle_behaviour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B45C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B45C8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800B45CC: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x800B45D0: addiu       $a1, $a1, 0x2CF4
    ctx->r5 = ADD32(ctx->r5, 0X2CF4);
    // 0x800B45D4: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B45D8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B45DC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B45E0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B45E4: bne         $at, $zero, L_800B4604
    if (ctx->r1 != 0) {
        // 0x800B45E8: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B4604;
    }
    // 0x800B45E8: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B45EC:
    // 0x800B45EC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B45F0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B45F4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800B45F8: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B45FC: beq         $at, $zero, L_800B45EC
    if (ctx->r1 == 0) {
        // 0x800B4600: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B45EC;
    }
    // 0x800B4600: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B4604:
    // 0x800B4604: lw          $t9, 0x2CFC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2CFC);
    // 0x800B4608: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B460C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B4610: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800B4614: jr          $ra
    // 0x800B4618: nop

    return;
    // 0x800B4618: nop

;}
RECOMP_FUNC void read_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074204: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074208: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007420C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80074210: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80074214: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80074218: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007421C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80074220: jal         0x8006A100
    // 0x80074224: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074224: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80074228: jal         0x800CE210
    // 0x8007422C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x8007422C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074230: bne         $v0, $zero, L_80074240
    if (ctx->r2 != 0) {
        // 0x80074234: addiu       $s3, $zero, 0x5
        ctx->r19 = ADD32(0, 0X5);
            goto L_80074240;
    }
    // 0x80074234: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x80074238: b           L_80074300
    // 0x8007423C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074300;
    // 0x8007423C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074240:
    // 0x80074240: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80074244: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80074248: beq         $v0, $zero, L_8007426C
    if (ctx->r2 == 0) {
        // 0x8007424C: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_8007426C;
    }
    // 0x8007424C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80074250: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80074254: beq         $v0, $at, L_80074274
    if (ctx->r2 == ctx->r1) {
        // 0x80074258: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80074274;
    }
    // 0x80074258: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007425C: beq         $v0, $at, L_8007427C
    if (ctx->r2 == ctx->r1) {
        // 0x80074260: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_8007427C;
    }
    // 0x80074260: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80074264: b           L_8007427C
    // 0x80074268: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_8007427C;
    // 0x80074268: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_8007426C:
    // 0x8007426C: b           L_8007427C
    // 0x80074270: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8007427C;
    // 0x80074270: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80074274:
    // 0x80074274: b           L_8007427C
    // 0x80074278: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_8007427C;
    // 0x80074278: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8007427C:
    // 0x8007427C: jal         0x80070C9C
    // 0x80074280: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80074280: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80074284: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80074288: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8007428C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074290:
    // 0x80074290: jal         0x8006A100
    // 0x80074294: nop

    si_mesg(rdram, ctx);
        goto after_3;
    // 0x80074294: nop

    after_3:
    // 0x80074298: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x8007429C: addu        $a2, $t6, $s2
    ctx->r6 = ADD32(ctx->r14, ctx->r18);
    // 0x800742A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800742A4: jal         0x800CE280
    // 0x800742A8: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    osEepromRead_recomp(rdram, ctx);
        goto after_4;
    // 0x800742A8: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_4:
    // 0x800742AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800742B0: bne         $s0, $s3, L_80074290
    if (ctx->r16 != ctx->r19) {
        // 0x800742B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80074290;
    }
    // 0x800742B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800742B8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800742BC: jal         0x8007306C
    // 0x800742C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    populate_settings_from_save_data(rdram, ctx);
        goto after_5;
    // 0x800742C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x800742C4: jal         0x80071140
    // 0x800742C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800742C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800742CC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800742D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800742D4: lbu         $v1, 0x4B($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4B);
    // 0x800742D8: nop

    // 0x800742DC: beq         $v1, $zero, L_80074300
    if (ctx->r3 == 0) {
        // 0x800742E0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074300;
    }
    // 0x800742E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800742E4: jal         0x8007431C
    // 0x800742E8: nop

    erase_save_file(rdram, ctx);
        goto after_7;
    // 0x800742E8: nop

    after_7:
    // 0x800742EC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800742F0: nop

    // 0x800742F4: lbu         $v1, 0x4B($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X4B);
    // 0x800742F8: nop

    // 0x800742FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074300:
    // 0x80074300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80074304: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074308: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007430C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80074310: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80074314: jr          $ra
    // 0x80074318: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80074318: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void __cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4AB0: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800D4AB4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800D4AB8: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D4ABC: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D4AC0: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800D4AC4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D4AC8: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x800D4ACC: beql        $at, $zero, L_800D4BF4
    if (ctx->r1 == 0) {
        // 0x800D4AD0: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_800D4BF4;
    }
    goto skip_0;
    // 0x800D4AD0: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x800D4AD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D4AD8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D4ADC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800D4AE0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800D4AE4: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D4AE8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D4AEC: bc1fl       L_800D4B00
    if (!c1cs) {
        // 0x800D4AF0: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800D4B00;
    }
    goto skip_1;
    // 0x800D4AF0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x800D4AF4: b           L_800D4B00
    // 0x800D4AF8: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_800D4B00;
    // 0x800D4AF8: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800D4AFC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800D4B00:
    // 0x800D4B00: ldc1        $f8, -0x6818($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6818);
    // 0x800D4B04: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800D4B08: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800D4B0C: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x800D4B10: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800D4B14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D4B18: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x800D4B1C: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x800D4B20: nop

    // 0x800D4B24: bc1fl       L_800D4B44
    if (!c1cs) {
        // 0x800D4B28: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_800D4B44;
    }
    goto skip_2;
    // 0x800D4B28: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x800D4B2C: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x800D4B30: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800D4B34: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D4B38: b           L_800D4B54
    // 0x800D4B3C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_800D4B54;
    // 0x800D4B3C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800D4B40: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_800D4B44:
    // 0x800D4B44: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800D4B48: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800D4B4C: nop

    // 0x800D4B50: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_800D4B54:
    // 0x800D4B54: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D4B58: ldc1        $f10, -0x6810($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6810);
    // 0x800D4B5C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800D4B60: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D4B64: ldc1        $f6, -0x6808($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6808);
    // 0x800D4B68: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D4B6C: addiu       $v1, $v1, -0x6840
    ctx->r3 = ADD32(ctx->r3, -0X6840);
    // 0x800D4B70: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x800D4B74: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800D4B78: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x800D4B7C: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x800D4B80: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D4B84: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x800D4B88: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x800D4B8C: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x800D4B90: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D4B94: nop

    // 0x800D4B98: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x800D4B9C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800D4BA0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800D4BA4: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800D4BA8: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x800D4BAC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800D4BB0: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x800D4BB4: bne         $t0, $zero, L_800D4BD4
    if (ctx->r8 != 0) {
        // 0x800D4BB8: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_800D4BD4;
    }
    // 0x800D4BB8: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x800D4BBC: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x800D4BC0: nop

    // 0x800D4BC4: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800D4BC8: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800D4BCC: jr          $ra
    // 0x800D4BD0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800D4BD0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800D4BD4:
    // 0x800D4BD4: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x800D4BD8: nop

    // 0x800D4BDC: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800D4BE0: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x800D4BE4: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800D4BE8: jr          $ra
    // 0x800D4BEC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800D4BEC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800D4BF0: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_800D4BF4:
    // 0x800D4BF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D4BF8: bc1t        L_800D4C0C
    if (c1cs) {
        // 0x800D4BFC: nop
    
            goto L_800D4C0C;
    }
    // 0x800D4BFC: nop

    // 0x800D4C00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D4C04: jr          $ra
    // 0x800D4C08: lwc1        $f0, -0x6740($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6740);
    return;
    // 0x800D4C08: lwc1        $f0, -0x6740($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6740);
L_800D4C0C:
    // 0x800D4C0C: lwc1        $f0, -0x6800($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6800);
    // 0x800D4C10: jr          $ra
    // 0x800D4C14: nop

    return;
    // 0x800D4C14: nop

;}
RECOMP_FUNC void mempool_free_queue_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071198: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007119C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800711A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800711A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800711A8: jal         0x8006F510
    // 0x800711AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x800711AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800711B0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800711B4: addiu       $s1, $s1, 0x3DC8
    ctx->r17 = ADD32(ctx->r17, 0X3DC8);
    // 0x800711B8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800711BC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800711C0: blez        $v1, L_80071254
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800711C4: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80071254;
    }
    // 0x800711C4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800711C8: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800711CC: addiu       $s2, $s2, 0x35C8
    ctx->r18 = ADD32(ctx->r18, 0X35C8);
    // 0x800711D0: addiu       $s0, $s0, 0x35C8
    ctx->r16 = ADD32(ctx->r16, 0X35C8);
L_800711D4:
    // 0x800711D4: lbu         $t6, 0x4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4);
    // 0x800711D8: nop

    // 0x800711DC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800711E0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800711E4: bne         $t8, $zero, L_80071234
    if (ctx->r24 != 0) {
        // 0x800711E8: sb          $t7, 0x4($s0)
        MEM_B(0X4, ctx->r16) = ctx->r15;
            goto L_80071234;
    }
    // 0x800711E8: sb          $t7, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r15;
    // 0x800711EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800711F0: jal         0x80071278
    // 0x800711F4: nop

    mempool_free_addr(rdram, ctx);
        goto after_1;
    // 0x800711F4: nop

    after_1:
    // 0x800711F8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800711FC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80071200: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x80071204: addu        $v0, $s2, $t9
    ctx->r2 = ADD32(ctx->r18, ctx->r25);
    // 0x80071208: lw          $t0, -0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, -0X8);
    // 0x8007120C: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x80071210: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80071214: lbu         $t1, -0x4($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X4);
    // 0x80071218: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8007121C: addiu       $t4, $t4, 0x35C8
    ctx->r12 = ADD32(ctx->r12, 0X35C8);
    // 0x80071220: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80071224: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80071228: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x8007122C: b           L_80071248
    // 0x80071230: sb          $t1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r9;
        goto L_80071248;
    // 0x80071230: sb          $t1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r9;
L_80071234:
    // 0x80071234: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071238: addiu       $t6, $t6, 0x35C8
    ctx->r14 = ADD32(ctx->r14, 0X35C8);
    // 0x8007123C: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x80071240: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x80071244: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80071248:
    // 0x80071248: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x8007124C: bne         $at, $zero, L_800711D4
    if (ctx->r1 != 0) {
        // 0x80071250: nop
    
            goto L_800711D4;
    }
    // 0x80071250: nop

L_80071254:
    // 0x80071254: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80071258: jal         0x8006F53C
    // 0x8007125C: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x8007125C: nop

    after_2:
    // 0x80071260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80071264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071268: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007126C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071270: jr          $ra
    // 0x80071274: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80071274: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_init_bridge_whaleramp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C9EC: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003C9F0: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003C9F4: sb          $t6, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r14;
    // 0x8003C9F8: lbu         $t8, 0x9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X9);
    // 0x8003C9FC: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003CA00: sll         $t9, $t8, 10
    ctx->r25 = S32(ctx->r24 << 10);
    // 0x8003CA04: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x8003CA08: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8003CA0C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA10: addiu       $t0, $zero, 0x21
    ctx->r8 = ADD32(0, 0X21);
    // 0x8003CA14: sh          $t0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r8;
    // 0x8003CA18: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA1C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8003CA20: sb          $t2, 0x11($t3)
    MEM_B(0X11, ctx->r11) = ctx->r10;
    // 0x8003CA24: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA28: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8003CA2C: sb          $t4, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r12;
    // 0x8003CA30: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA34: nop

    // 0x8003CA38: sb          $zero, 0x12($t6)
    MEM_B(0X12, ctx->r14) = 0;
    // 0x8003CA3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003CA40: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8003CA44: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x8003CA48: lb          $t9, 0x55($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X55);
    // 0x8003CA4C: nop

    // 0x8003CA50: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003CA54: bne         $at, $zero, L_8003CA60
    if (ctx->r1 != 0) {
        // 0x8003CA58: nop
    
            goto L_8003CA60;
    }
    // 0x8003CA58: nop

    // 0x8003CA5C: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003CA60:
    // 0x8003CA60: jr          $ra
    // 0x8003CA64: nop

    return;
    // 0x8003CA64: nop

;}
RECOMP_FUNC void osCreateScheduler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079350: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80079354: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80079358: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007935C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80079360: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80079364: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80079368: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8007936C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80079370: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80079374: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80079378: sw          $zero, 0x274($a0)
    MEM_W(0X274, ctx->r4) = 0;
    // 0x8007937C: sw          $zero, 0x278($a0)
    MEM_W(0X278, ctx->r4) = 0;
    // 0x80079380: sw          $zero, 0x260($a0)
    MEM_W(0X260, ctx->r4) = 0;
    // 0x80079384: sw          $zero, 0x264($a0)
    MEM_W(0X264, ctx->r4) = 0;
    // 0x80079388: sw          $zero, 0x268($a0)
    MEM_W(0X268, ctx->r4) = 0;
    // 0x8007938C: sw          $zero, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = 0;
    // 0x80079390: sw          $zero, 0x270($a0)
    MEM_W(0X270, ctx->r4) = 0;
    // 0x80079394: sw          $zero, 0x280($a0)
    MEM_W(0X280, ctx->r4) = 0;
    // 0x80079398: sw          $zero, 0x27C($a0)
    MEM_W(0X27C, ctx->r4) = 0;
    // 0x8007939C: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800793A0: sh          $t7, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r15;
    // 0x800793A4: andi        $s1, $a3, 0xFF
    ctx->r17 = ctx->r7 & 0XFF;
    // 0x800793A8: jal         0x800D1990
    // 0x800793AC: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_0;
    // 0x800793AC: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_0:
    // 0x800793B0: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800793B4: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x800793B8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800793BC: addiu       $t9, $t9, 0x3900
    ctx->r25 = ADD32(ctx->r25, 0X3900);
    // 0x800793C0: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800793C4: jal         0x800D1CA0
    // 0x800793C8: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    osViSetMode_recomp(rdram, ctx);
        goto after_1;
    // 0x800793C8: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_1:
    // 0x800793CC: jal         0x800D1D10
    // 0x800793D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_2;
    // 0x800793D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800793D4: addiu       $s1, $s0, 0x40
    ctx->r17 = ADD32(ctx->r16, 0X40);
    // 0x800793D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800793DC: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    // 0x800793E0: jal         0x800C8820
    // 0x800793E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x800793E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x800793E8: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x800793EC: addiu       $a1, $s0, 0x90
    ctx->r5 = ADD32(ctx->r16, 0X90);
    // 0x800793F0: jal         0x800C8820
    // 0x800793F4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x800793F4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x800793F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800793FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079400: jal         0x800CCBB0
    // 0x80079404: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80079404: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    after_5:
    // 0x80079408: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8007940C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079410: jal         0x800CCBB0
    // 0x80079414: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80079414: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    after_6:
    // 0x80079418: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8007941C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079420: jal         0x800CCBB0
    // 0x80079424: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80079424: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    after_7:
    // 0x80079428: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x8007942C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80079430: jal         0x800D1D80
    // 0x80079434: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    osViSetEvent_recomp(rdram, ctx);
        goto after_8;
    // 0x80079434: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    after_8:
    // 0x80079438: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007943C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80079440: addiu       $s1, $s0, 0xB0
    ctx->r17 = ADD32(ctx->r16, 0XB0);
    // 0x80079444: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80079448: addiu       $a2, $a2, -0x6A54
    ctx->r6 = ADD32(ctx->r6, -0X6A54);
    // 0x8007944C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80079450: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80079454: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80079458: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8007945C: jal         0x800C8850
    // 0x80079460: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    osCreateThread_recomp(rdram, ctx);
        goto after_9;
    // 0x80079460: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_9:
    // 0x80079464: jal         0x800C89A0
    // 0x80079468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_10;
    // 0x80079468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8007946C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80079470: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80079474: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80079478: jr          $ra
    // 0x8007947C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007947C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE1C4: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800CE1C8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800CE1CC: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800CE1D0: beql        $t6, $v1, L_800CE1FC
    if (ctx->r14 == ctx->r3) {
        // 0x800CE1D4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800CE1FC;
    }
    goto skip_0;
    // 0x800CE1D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_800CE1D8:
    // 0x800CE1D8: bnel        $v1, $zero, L_800CE1EC
    if (ctx->r3 != 0) {
        // 0x800CE1DC: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_800CE1EC;
    }
    goto skip_1;
    // 0x800CE1DC: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x800CE1E0: jr          $ra
    // 0x800CE1E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE1E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CE1E8: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_800CE1EC:
    // 0x800CE1EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CE1F0: bne         $v0, $v1, L_800CE1D8
    if (ctx->r2 != ctx->r3) {
        // 0x800CE1F4: nop
    
            goto L_800CE1D8;
    }
    // 0x800CE1F4: nop

    // 0x800CE1F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800CE1FC:
    // 0x800CE1FC: jr          $ra
    // 0x800CE200: nop

    return;
    // 0x800CE200: nop

;}
RECOMP_FUNC void func_80026C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026C14: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80026C18: addiu       $t0, $t0, -0x2B62
    ctx->r8 = ADD32(ctx->r8, -0X2B62);
    // 0x80026C1C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80026C20: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80026C24: lh          $t8, -0x2B46($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2B46);
    // 0x80026C28: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80026C2C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80026C30: sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5 << 16);
    // 0x80026C34: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x80026C38: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80026C3C: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80026C40: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80026C44: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80026C48: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80026C4C: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80026C50: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80026C54: beq         $at, $zero, L_80026E48
    if (ctx->r1 == 0) {
        // 0x80026C58: sw          $a2, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r6;
            goto L_80026E48;
    }
    // 0x80026C58: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80026C5C: blez        $v0, L_80026CBC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80026C60: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80026CBC;
    }
    // 0x80026C60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80026C64: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80026C68: addiu       $t1, $t1, -0x2B88
    ctx->r9 = ADD32(ctx->r9, -0X2B88);
    // 0x80026C6C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80026C70: nop

    // 0x80026C74: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80026C78: nop

    // 0x80026C7C: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80026C80: beq         $at, $zero, L_80026CBC
    if (ctx->r1 == 0) {
        // 0x80026C84: nop
    
            goto L_80026CBC;
    }
    // 0x80026C84: nop

L_80026C88:
    // 0x80026C88: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026C8C: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80026C90: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80026C94: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80026C98: beq         $at, $zero, L_80026CBC
    if (ctx->r1 == 0) {
        // 0x80026C9C: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80026CBC;
    }
    // 0x80026C9C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80026CA0: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80026CA4: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80026CA8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80026CAC: nop

    // 0x80026CB0: slt         $at, $t6, $a3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80026CB4: bne         $at, $zero, L_80026C88
    if (ctx->r1 != 0) {
        // 0x80026CB8: nop
    
            goto L_80026C88;
    }
    // 0x80026CB8: nop

L_80026CBC:
    // 0x80026CBC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80026CC0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80026CC4: beq         $at, $zero, L_80026D40
    if (ctx->r1 == 0) {
        // 0x80026CC8: addiu       $t1, $t1, -0x2B88
        ctx->r9 = ADD32(ctx->r9, -0X2B88);
            goto L_80026D40;
    }
    // 0x80026CC8: addiu       $t1, $t1, -0x2B88
    ctx->r9 = ADD32(ctx->r9, -0X2B88);
    // 0x80026CCC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80026CD0: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80026CD4: addu        $a1, $a0, $t7
    ctx->r5 = ADD32(ctx->r4, ctx->r15);
    // 0x80026CD8: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80026CDC: nop

    // 0x80026CE0: bne         $a3, $t8, L_80026D40
    if (ctx->r7 != ctx->r24) {
        // 0x80026CE4: nop
    
            goto L_80026D40;
    }
    // 0x80026CE4: nop

    // 0x80026CE8: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x80026CEC: nop

    // 0x80026CF0: slt         $at, $t9, $s0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80026CF4: beq         $at, $zero, L_80026D44
    if (ctx->r1 == 0) {
        // 0x80026CF8: sll         $a1, $v0, 16
        ctx->r5 = S32(ctx->r2 << 16);
            goto L_80026D44;
    }
    // 0x80026CF8: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
L_80026CFC:
    // 0x80026CFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026D00: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80026D04: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80026D08: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80026D0C: beq         $at, $zero, L_80026D40
    if (ctx->r1 == 0) {
        // 0x80026D10: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80026D40;
    }
    // 0x80026D10: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80026D14: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80026D18: addu        $a1, $a0, $t4
    ctx->r5 = ADD32(ctx->r4, ctx->r12);
    // 0x80026D1C: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x80026D20: nop

    // 0x80026D24: bne         $a3, $t5, L_80026D40
    if (ctx->r7 != ctx->r13) {
        // 0x80026D28: nop
    
            goto L_80026D40;
    }
    // 0x80026D28: nop

    // 0x80026D2C: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x80026D30: nop

    // 0x80026D34: slt         $at, $t6, $s0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80026D38: bne         $at, $zero, L_80026CFC
    if (ctx->r1 != 0) {
        // 0x80026D3C: nop
    
            goto L_80026CFC;
    }
    // 0x80026D3C: nop

L_80026D40:
    // 0x80026D40: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
L_80026D44:
    // 0x80026D44: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80026D48: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80026D4C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80026D50: beq         $at, $zero, L_80026DB8
    if (ctx->r1 == 0) {
        // 0x80026D54: sll         $a0, $v1, 3
        ctx->r4 = S32(ctx->r3 << 3);
            goto L_80026DB8;
    }
    // 0x80026D54: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
L_80026D58:
    // 0x80026D58: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80026D5C: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80026D60: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x80026D64: lh          $t9, -0x8($a2)
    ctx->r25 = MEM_H(ctx->r6, -0X8);
    // 0x80026D68: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80026D6C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80026D70: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80026D74: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80026D78: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    // 0x80026D7C: lh          $t3, -0x6($a2)
    ctx->r11 = MEM_H(ctx->r6, -0X6);
    // 0x80026D80: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026D84: sh          $t3, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r11;
    // 0x80026D88: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80026D8C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80026D90: addu        $a2, $t4, $v0
    ctx->r6 = ADD32(ctx->r12, ctx->r2);
    // 0x80026D94: lb          $t5, -0x1($a2)
    ctx->r13 = MEM_B(ctx->r6, -0X1);
    // 0x80026D98: nop

    // 0x80026D9C: sb          $t5, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r13;
    // 0x80026DA0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80026DA4: nop

    // 0x80026DA8: addu        $a2, $t6, $v0
    ctx->r6 = ADD32(ctx->r14, ctx->r2);
    // 0x80026DAC: lb          $t7, -0x2($a2)
    ctx->r15 = MEM_B(ctx->r6, -0X2);
    // 0x80026DB0: bne         $at, $zero, L_80026D58
    if (ctx->r1 != 0) {
        // 0x80026DB4: sb          $t7, 0x6($a2)
        MEM_B(0X6, ctx->r6) = ctx->r15;
            goto L_80026D58;
    }
    // 0x80026DB4: sb          $t7, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r15;
L_80026DB8:
    // 0x80026DB8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80026DBC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80026DC0: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x80026DC4: sh          $a3, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r7;
    // 0x80026DC8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80026DCC: addiu       $v1, $v1, -0x2B64
    ctx->r3 = ADD32(ctx->r3, -0X2B64);
    // 0x80026DD0: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80026DD4: sh          $s0, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r16;
    // 0x80026DD8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80026DDC: nop

    // 0x80026DE0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80026DE4: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x80026DE8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80026DEC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80026DF0: addu        $t2, $t9, $a0
    ctx->r10 = ADD32(ctx->r25, ctx->r4);
    // 0x80026DF4: sb          $t8, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r24;
    // 0x80026DF8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80026DFC: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x80026E00: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80026E04: sb          $t3, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r11;
    // 0x80026E08: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80026E0C: lw          $t7, -0x2B84($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B84);
    // 0x80026E10: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80026E14: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80026E18: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80026E1C: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80026E20: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80026E24: nop

    // 0x80026E28: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80026E2C: beq         $t2, $zero, L_80026E44
    if (ctx->r10 == 0) {
        // 0x80026E30: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_80026E44;
    }
    // 0x80026E30: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80026E34: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x80026E38: nop

    // 0x80026E3C: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80026E40: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
L_80026E44:
    // 0x80026E44: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
L_80026E48:
    // 0x80026E48: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80026E4C: jr          $ra
    // 0x80026E50: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80026E50: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void set_stereo_pan_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065BD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80065BD4: jr          $ra
    // 0x80065BD8: sh          $a0, -0x2FB0($at)
    MEM_H(-0X2FB0, ctx->r1) = ctx->r4;
    return;
    // 0x80065BD8: sh          $a0, -0x2FB0($at)
    MEM_H(-0X2FB0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void get_particle_behaviour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4578: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B457C: lw          $v1, 0x2CF4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2CF4);
    // 0x800B4580: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B4584: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B4588: beq         $at, $zero, L_800B45A8
    if (ctx->r1 == 0) {
        // 0x800B458C: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800B45A8;
    }
    // 0x800B458C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B4590: lw          $t6, 0x2CFC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2CFC);
    // 0x800B4594: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800B4598: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B459C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800B45A0: jr          $ra
    // 0x800B45A4: nop

    return;
    // 0x800B45A4: nop

L_800B45A8:
    // 0x800B45A8: lw          $t9, 0x2CFC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2CFC);
    // 0x800B45AC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B45B0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B45B4: lw          $v0, -0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, -0X4);
    // 0x800B45B8: nop

    // 0x800B45BC: jr          $ra
    // 0x800B45C0: nop

    return;
    // 0x800B45C0: nop

;}
RECOMP_FUNC void func_8000E138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E138: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E13C: lb          $v0, -0x52E0($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52E0);
    // 0x8000E140: jr          $ra
    // 0x8000E144: nop

    return;
    // 0x8000E144: nop

;}
RECOMP_FUNC void strncasecmp_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4848: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800B484C: nop

    // 0x800B4850: bne         $v0, $zero, L_800B4868
    if (ctx->r2 != 0) {
        // 0x800B4854: nop
    
            goto L_800B4868;
    }
    // 0x800B4854: nop

    // 0x800B4858: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B485C: nop

    // 0x800B4860: beq         $t6, $zero, L_800B4900
    if (ctx->r14 == 0) {
        // 0x800B4864: nop
    
            goto L_800B4900;
    }
    // 0x800B4864: nop

L_800B4868:
    // 0x800B4868: beq         $a2, $zero, L_800B4900
    if (ctx->r6 == 0) {
        // 0x800B486C: andi        $a3, $v0, 0xFF
        ctx->r7 = ctx->r2 & 0XFF;
            goto L_800B4900;
    }
    // 0x800B486C: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_800B4870:
    // 0x800B4870: slti        $at, $a3, 0x61
    ctx->r1 = SIGNED(ctx->r7) < 0X61 ? 1 : 0;
    // 0x800B4874: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4878: bne         $at, $zero, L_800B4890
    if (ctx->r1 != 0) {
        // 0x800B487C: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_800B4890;
    }
    // 0x800B487C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800B4880: slti        $at, $a3, 0x7B
    ctx->r1 = SIGNED(ctx->r7) < 0X7B ? 1 : 0;
    // 0x800B4884: beq         $at, $zero, L_800B4890
    if (ctx->r1 == 0) {
        // 0x800B4888: addiu       $a3, $a3, -0x20
        ctx->r7 = ADD32(ctx->r7, -0X20);
            goto L_800B4890;
    }
    // 0x800B4888: addiu       $a3, $a3, -0x20
    ctx->r7 = ADD32(ctx->r7, -0X20);
    // 0x800B488C: andi        $t0, $a3, 0xFF
    ctx->r8 = ctx->r7 & 0XFF;
L_800B4890:
    // 0x800B4890: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B4894: slti        $at, $v0, 0x61
    ctx->r1 = SIGNED(ctx->r2) < 0X61 ? 1 : 0;
    // 0x800B4898: bne         $at, $zero, L_800B48B0
    if (ctx->r1 != 0) {
        // 0x800B489C: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B48B0;
    }
    // 0x800B489C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B48A0: slti        $at, $v0, 0x7B
    ctx->r1 = SIGNED(ctx->r2) < 0X7B ? 1 : 0;
    // 0x800B48A4: beq         $at, $zero, L_800B48B0
    if (ctx->r1 == 0) {
        // 0x800B48A8: addiu       $v0, $v0, -0x20
        ctx->r2 = ADD32(ctx->r2, -0X20);
            goto L_800B48B0;
    }
    // 0x800B48A8: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x800B48AC: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_800B48B0:
    // 0x800B48B0: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B48B4: beq         $at, $zero, L_800B48C4
    if (ctx->r1 == 0) {
        // 0x800B48B8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800B48C4;
    }
    // 0x800B48B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B48BC: jr          $ra
    // 0x800B48C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800B48C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B48C4:
    // 0x800B48C4: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B48C8: beq         $at, $zero, L_800B48D8
    if (ctx->r1 == 0) {
        // 0x800B48CC: nop
    
            goto L_800B48D8;
    }
    // 0x800B48CC: nop

    // 0x800B48D0: jr          $ra
    // 0x800B48D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800B48D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B48D8:
    // 0x800B48D8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800B48DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B48E0: bne         $v0, $zero, L_800B48F8
    if (ctx->r2 != 0) {
        // 0x800B48E4: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800B48F8;
    }
    // 0x800B48E4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800B48E8: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800B48EC: nop

    // 0x800B48F0: beq         $t9, $zero, L_800B4900
    if (ctx->r25 == 0) {
        // 0x800B48F4: nop
    
            goto L_800B4900;
    }
    // 0x800B48F4: nop

L_800B48F8:
    // 0x800B48F8: bne         $a2, $zero, L_800B4870
    if (ctx->r6 != 0) {
        // 0x800B48FC: andi        $a3, $v0, 0xFF
        ctx->r7 = ctx->r2 & 0XFF;
            goto L_800B4870;
    }
    // 0x800B48FC: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_800B4900:
    // 0x800B4900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4904: jr          $ra
    // 0x800B4908: nop

    return;
    // 0x800B4908: nop

;}
RECOMP_FUNC void thread1_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065D98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065D9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065DA0: jal         0x800B6F50
    // 0x80065DA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    thread0_create(rdram, ctx);
        goto after_0;
    // 0x80065DA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80065DA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80065DAC: addiu       $t6, $t6, -0x8A8
    ctx->r14 = ADD32(ctx->r14, -0X8A8);
    // 0x80065DB0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065DB4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80065DB8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80065DBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80065DC0: addiu       $a2, $a2, -0x3CD0
    ctx->r6 = ADD32(ctx->r6, -0X3CD0);
    // 0x80065DC4: addiu       $a0, $a0, -0x6F0
    ctx->r4 = ADD32(ctx->r4, -0X6F0);
    // 0x80065DC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065DCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80065DD0: jal         0x800C8850
    // 0x80065DD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80065DD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80065DD8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80065DDC: addiu       $v0, $v0, -0x28A8
    ctx->r2 = ADD32(ctx->r2, -0X28A8);
    // 0x80065DE0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80065DE4: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80065DE8: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80065DEC: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80065DF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065DF4: sw          $t9, 0x2004($v0)
    MEM_W(0X2004, ctx->r2) = ctx->r25;
    // 0x80065DF8: sw          $t8, 0x2000($v0)
    MEM_W(0X2000, ctx->r2) = ctx->r24;
    // 0x80065DFC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80065E00: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80065E04: jal         0x800C89A0
    // 0x80065E08: addiu       $a0, $a0, -0x6F0
    ctx->r4 = ADD32(ctx->r4, -0X6F0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80065E08: addiu       $a0, $a0, -0x6F0
    ctx->r4 = ADD32(ctx->r4, -0X6F0);
    after_2:
    // 0x80065E0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065E10: jal         0x800CC840
    // 0x80065E14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_3;
    // 0x80065E14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80065E18:
    // 0x80065E18: b           L_80065E18
    pause_self(rdram);
    // 0x80065E1C: nop

    // 0x80065E20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065E24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065E28: jr          $ra
    // 0x80065E2C: nop

    return;
    // 0x80065E2C: nop

;}
RECOMP_FUNC void debug_text_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B61E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B61E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B61E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B61EC: addiu       $t6, $t6, 0x7CD8
    ctx->r14 = ADD32(ctx->r14, 0X7CD8);
    // 0x800B61F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B61F4: jal         0x800B6EE0
    // 0x800B61F8: sw          $t6, -0x7A28($at)
    MEM_W(-0X7A28, ctx->r1) = ctx->r14;
    debug_text_origin(rdram, ctx);
        goto after_0;
    // 0x800B61F8: sw          $t6, -0x7A28($at)
    MEM_W(-0X7A28, ctx->r1) = ctx->r14;
    after_0:
    // 0x800B61FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B6204: jr          $ra
    // 0x800B6208: nop

    return;
    // 0x800B6208: nop

;}
RECOMP_FUNC void obj_init_torch_mist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034AF0: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80034AF4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80034AF8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80034AFC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034B00: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80034B04: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80034B08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034B0C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80034B10: nop

    // 0x80034B14: bc1f        L_80034B24
    if (!c1cs) {
        // 0x80034B18: nop
    
            goto L_80034B24;
    }
    // 0x80034B18: nop

    // 0x80034B1C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80034B20: nop

L_80034B24:
    // 0x80034B24: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80034B28: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80034B2C: nop

    // 0x80034B30: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80034B34: nop

    // 0x80034B38: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80034B3C: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80034B40: lbu         $t9, 0x8($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X8);
    // 0x80034B44: jr          $ra
    // 0x80034B48: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
    return;
    // 0x80034B48: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void obj_loop_fogchanger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030A74: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80030A78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80030A7C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80030A80: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80030A84: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80030A88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80030A8C: lw          $t3, 0x3C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X3C);
    // 0x80030A90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030A94: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80030A98: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80030A9C: jal         0x80066510
    // 0x80030AA0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_0;
    // 0x80030AA0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_0:
    // 0x80030AA4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80030AA8: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80030AAC: beq         $v0, $zero, L_80030ADC
    if (ctx->r2 == 0) {
        // 0x80030AB0: addiu       $a0, $sp, 0x74
        ctx->r4 = ADD32(ctx->r29, 0X74);
            goto L_80030ADC;
    }
    // 0x80030AB0: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80030AB4: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x80030AB8: jal         0x80069D7C
    // 0x80030ABC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    cam_get_cameras(rdram, ctx);
        goto after_1;
    // 0x80030ABC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_1:
    // 0x80030AC0: jal         0x80066210
    // 0x80030AC4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x80030AC4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_2:
    // 0x80030AC8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80030ACC: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80030AD0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80030AD4: b           L_80030AEC
    // 0x80030AD8: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
        goto L_80030AEC;
    // 0x80030AD8: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
L_80030ADC:
    // 0x80030ADC: jal         0x8001BA74
    // 0x80030AE0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    get_racer_objects(rdram, ctx);
        goto after_3;
    // 0x80030AE0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_3:
    // 0x80030AE4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80030AE8: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
L_80030AEC:
    // 0x80030AEC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80030AF0: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80030AF4: blez        $t7, L_80030DC4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80030AF8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80030DC4;
    }
    // 0x80030AF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80030AFC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80030B00: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80030B04: addiu       $t4, $t4, -0x2C78
    ctx->r12 = ADD32(ctx->r12, -0X2C78);
    // 0x80030B08: addiu       $s2, $zero, 0x44
    ctx->r18 = ADD32(0, 0X44);
    // 0x80030B0C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80030B10: addiu       $t5, $zero, 0x38
    ctx->r13 = ADD32(0, 0X38);
L_80030B14:
    // 0x80030B14: beq         $ra, $zero, L_80030B78
    if (ctx->r31 == 0) {
        // 0x80030B18: or          $t2, $s1, $zero
        ctx->r10 = ctx->r17 | 0;
            goto L_80030B78;
    }
    // 0x80030B18: or          $t2, $s1, $zero
    ctx->r10 = ctx->r17 | 0;
    // 0x80030B1C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80030B20: addu        $t9, $ra, $t8
    ctx->r25 = ADD32(ctx->r31, ctx->r24);
    // 0x80030B24: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80030B28: nop

    // 0x80030B2C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80030B30: nop

    // 0x80030B34: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80030B38: nop

    // 0x80030B3C: bltz        $v0, L_80030BBC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80030B40: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80030BBC;
    }
    // 0x80030B40: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80030B44: beq         $at, $zero, L_80030BBC
    if (ctx->r1 == 0) {
        // 0x80030B48: nop
    
            goto L_80030BBC;
    }
    // 0x80030B48: nop

    // 0x80030B4C: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030B50: mflo        $t6
    ctx->r14 = lo;
    // 0x80030B54: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80030B58: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x80030B5C: nop

    // 0x80030B60: beq         $s0, $t8, L_80030BBC
    if (ctx->r16 == ctx->r24) {
        // 0x80030B64: nop
    
            goto L_80030BBC;
    }
    // 0x80030B64: nop

    // 0x80030B68: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80030B6C: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80030B70: b           L_80030BBC
    // 0x80030B74: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
        goto L_80030BBC;
    // 0x80030B74: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_80030B78:
    // 0x80030B78: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80030B7C: beq         $at, $zero, L_80030BBC
    if (ctx->r1 == 0) {
        // 0x80030B80: nop
    
            goto L_80030BBC;
    }
    // 0x80030B80: nop

    // 0x80030B84: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030B88: mflo        $t9
    ctx->r25 = lo;
    // 0x80030B8C: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x80030B90: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x80030B94: nop

    // 0x80030B98: beq         $s0, $t7, L_80030BBC
    if (ctx->r16 == ctx->r15) {
        // 0x80030B9C: nop
    
            goto L_80030BBC;
    }
    // 0x80030B9C: nop

    // 0x80030BA0: multu       $a2, $s2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030BA4: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x80030BA8: mflo        $t8
    ctx->r24 = lo;
    // 0x80030BAC: addu        $v0, $s3, $t8
    ctx->r2 = ADD32(ctx->r19, ctx->r24);
    // 0x80030BB0: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80030BB4: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80030BB8: nop

L_80030BBC:
    // 0x80030BBC: beq         $t2, $s1, L_80030DB0
    if (ctx->r10 == ctx->r17) {
        // 0x80030BC0: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_80030DB0;
    }
    // 0x80030BC0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80030BC4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80030BC8: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80030BCC: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80030BD0: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80030BD4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80030BD8: sub.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80030BDC: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80030BE0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80030BE4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80030BE8: nop

    // 0x80030BEC: bc1f        L_80030DB0
    if (!c1cs) {
        // 0x80030BF0: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_80030DB0;
    }
    // 0x80030BF0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80030BF4: lh          $a0, 0xC($t3)
    ctx->r4 = MEM_H(ctx->r11, 0XC);
    // 0x80030BF8: lh          $v1, 0xE($t3)
    ctx->r3 = MEM_H(ctx->r11, 0XE);
    // 0x80030BFC: lbu         $a3, 0x9($t3)
    ctx->r7 = MEM_BU(ctx->r11, 0X9);
    // 0x80030C00: lbu         $t0, 0xA($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0XA);
    // 0x80030C04: lbu         $t1, 0xB($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0XB);
    // 0x80030C08: lh          $a1, 0x10($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X10);
    // 0x80030C0C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80030C10: beq         $at, $zero, L_80030C20
    if (ctx->r1 == 0) {
        // 0x80030C14: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80030C20;
    }
    // 0x80030C14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80030C18: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80030C1C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80030C20:
    // 0x80030C20: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80030C24: bne         $at, $zero, L_80030C34
    if (ctx->r1 != 0) {
        // 0x80030C28: addiu       $v0, $v1, -0x5
        ctx->r2 = ADD32(ctx->r3, -0X5);
            goto L_80030C34;
    }
    // 0x80030C28: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x80030C2C: addiu       $v1, $zero, 0x3FF
    ctx->r3 = ADD32(0, 0X3FF);
    // 0x80030C30: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
L_80030C34:
    // 0x80030C34: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030C38: bne         $at, $zero, L_80030C44
    if (ctx->r1 != 0) {
        // 0x80030C3C: nop
    
            goto L_80030C44;
    }
    // 0x80030C3C: nop

    // 0x80030C40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80030C44:
    // 0x80030C44: multu       $t2, $t5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030C48: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80030C4C: mflo        $t9
    ctx->r25 = lo;
    // 0x80030C50: addu        $v0, $t4, $t9
    ctx->r2 = ADD32(ctx->r12, ctx->r25);
    // 0x80030C54: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80030C58: sb          $a3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r7;
    // 0x80030C5C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030C60: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030C64: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80030C68: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x80030C6C: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80030C70: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80030C74: sh          $a0, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r4;
    // 0x80030C78: sh          $v1, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r3;
    // 0x80030C7C: bne         $a1, $zero, L_80030C88
    if (ctx->r5 != 0) {
        // 0x80030C80: nop
    
            goto L_80030C88;
    }
    // 0x80030C80: nop

    // 0x80030C84: break       7
    do_break(2147683460);
L_80030C88:
    // 0x80030C88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030C8C: bne         $a1, $at, L_80030CA0
    if (ctx->r5 != ctx->r1) {
        // 0x80030C90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030CA0;
    }
    // 0x80030C90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030C94: bne         $t8, $at, L_80030CA0
    if (ctx->r24 != ctx->r1) {
        // 0x80030C98: nop
    
            goto L_80030CA0;
    }
    // 0x80030C98: nop

    // 0x80030C9C: break       6
    do_break(2147683484);
L_80030CA0:
    // 0x80030CA0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030CA4: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80030CA8: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x80030CAC: sw          $a1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r5;
    // 0x80030CB0: sw          $s0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r16;
    // 0x80030CB4: mflo        $t9
    ctx->r25 = lo;
    // 0x80030CB8: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x80030CBC: nop

    // 0x80030CC0: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030CC4: bne         $a1, $zero, L_80030CD0
    if (ctx->r5 != 0) {
        // 0x80030CC8: nop
    
            goto L_80030CD0;
    }
    // 0x80030CC8: nop

    // 0x80030CCC: break       7
    do_break(2147683532);
L_80030CD0:
    // 0x80030CD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030CD4: bne         $a1, $at, L_80030CE8
    if (ctx->r5 != ctx->r1) {
        // 0x80030CD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030CE8;
    }
    // 0x80030CD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030CDC: bne         $t8, $at, L_80030CE8
    if (ctx->r24 != ctx->r1) {
        // 0x80030CE0: nop
    
            goto L_80030CE8;
    }
    // 0x80030CE0: nop

    // 0x80030CE4: break       6
    do_break(2147683556);
L_80030CE8:
    // 0x80030CE8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030CEC: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80030CF0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80030CF4: mflo        $t9
    ctx->r25 = lo;
    // 0x80030CF8: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x80030CFC: nop

    // 0x80030D00: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030D04: bne         $a1, $zero, L_80030D10
    if (ctx->r5 != 0) {
        // 0x80030D08: nop
    
            goto L_80030D10;
    }
    // 0x80030D08: nop

    // 0x80030D0C: break       7
    do_break(2147683596);
L_80030D10:
    // 0x80030D10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030D14: bne         $a1, $at, L_80030D28
    if (ctx->r5 != ctx->r1) {
        // 0x80030D18: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030D28;
    }
    // 0x80030D18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030D1C: bne         $t8, $at, L_80030D28
    if (ctx->r24 != ctx->r1) {
        // 0x80030D20: nop
    
            goto L_80030D28;
    }
    // 0x80030D20: nop

    // 0x80030D24: break       6
    do_break(2147683620);
L_80030D28:
    // 0x80030D28: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030D2C: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80030D30: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80030D34: mflo        $t9
    ctx->r25 = lo;
    // 0x80030D38: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x80030D3C: nop

    // 0x80030D40: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030D44: bne         $a1, $zero, L_80030D50
    if (ctx->r5 != 0) {
        // 0x80030D48: nop
    
            goto L_80030D50;
    }
    // 0x80030D48: nop

    // 0x80030D4C: break       7
    do_break(2147683660);
L_80030D50:
    // 0x80030D50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030D54: bne         $a1, $at, L_80030D68
    if (ctx->r5 != ctx->r1) {
        // 0x80030D58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030D68;
    }
    // 0x80030D58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030D5C: bne         $t8, $at, L_80030D68
    if (ctx->r24 != ctx->r1) {
        // 0x80030D60: nop
    
            goto L_80030D68;
    }
    // 0x80030D60: nop

    // 0x80030D64: break       6
    do_break(2147683684);
L_80030D68:
    // 0x80030D68: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030D6C: mflo        $t9
    ctx->r25 = lo;
    // 0x80030D70: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    // 0x80030D74: nop

    // 0x80030D78: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030D7C: bne         $a1, $zero, L_80030D88
    if (ctx->r5 != 0) {
        // 0x80030D80: nop
    
            goto L_80030D88;
    }
    // 0x80030D80: nop

    // 0x80030D84: break       7
    do_break(2147683716);
L_80030D88:
    // 0x80030D88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030D8C: bne         $a1, $at, L_80030DA0
    if (ctx->r5 != ctx->r1) {
        // 0x80030D90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030DA0;
    }
    // 0x80030D90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030D94: bne         $t8, $at, L_80030DA0
    if (ctx->r24 != ctx->r1) {
        // 0x80030D98: nop
    
            goto L_80030DA0;
    }
    // 0x80030D98: nop

    // 0x80030D9C: break       6
    do_break(2147683740);
L_80030DA0:
    // 0x80030DA0: mflo        $t9
    ctx->r25 = lo;
    // 0x80030DA4: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x80030DA8: nop

    // 0x80030DAC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80030DB0:
    // 0x80030DB0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80030DB4: bne         $a2, $t6, L_80030B14
    if (ctx->r6 != ctx->r14) {
        // 0x80030DB8: nop
    
            goto L_80030B14;
    }
    // 0x80030DB8: nop

    // 0x80030DBC: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    // 0x80030DC0: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
L_80030DC4:
    // 0x80030DC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80030DC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80030DCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80030DD0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80030DD4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80030DD8: jr          $ra
    // 0x80030DDC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80030DDC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
