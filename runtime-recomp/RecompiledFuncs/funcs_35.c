#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void write_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800744DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800744E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800744E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800744E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800744EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800744F0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800744F4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800744F8: jal         0x8006A100
    // 0x800744FC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x800744FC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_0:
    // 0x80074500: jal         0x800CE210
    // 0x80074504: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074504: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074508: bne         $v0, $zero, L_80074518
    if (ctx->r2 != 0) {
        // 0x8007450C: addiu       $s2, $zero, 0x5
        ctx->r18 = ADD32(0, 0X5);
            goto L_80074518;
    }
    // 0x8007450C: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80074510: b           L_800745B4
    // 0x80074514: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800745B4;
    // 0x80074514: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074518:
    // 0x80074518: beq         $s0, $zero, L_8007453C
    if (ctx->r16 == 0) {
        // 0x8007451C: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_8007453C;
    }
    // 0x8007451C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80074520: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80074524: beq         $s0, $at, L_80074544
    if (ctx->r16 == ctx->r1) {
        // 0x80074528: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80074544;
    }
    // 0x80074528: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007452C: beq         $s0, $at, L_8007454C
    if (ctx->r16 == ctx->r1) {
        // 0x80074530: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_8007454C;
    }
    // 0x80074530: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80074534: b           L_8007454C
    // 0x80074538: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_8007454C;
    // 0x80074538: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_8007453C:
    // 0x8007453C: b           L_8007454C
    // 0x80074540: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8007454C;
    // 0x80074540: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80074544:
    // 0x80074544: b           L_8007454C
    // 0x80074548: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_8007454C;
    // 0x80074548: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8007454C:
    // 0x8007454C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80074550: jal         0x80070C9C
    // 0x80074554: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80074554: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80074558: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007455C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80074560: jal         0x800732E8
    // 0x80074564: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800732E8(rdram, ctx);
        goto after_3;
    // 0x80074564: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80074568: jal         0x8006EAC0
    // 0x8007456C: nop

    is_reset_pressed(rdram, ctx);
        goto after_4;
    // 0x8007456C: nop

    after_4:
    // 0x80074570: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80074574: bne         $v0, $zero, L_800745A8
    if (ctx->r2 != 0) {
        // 0x80074578: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800745A8;
    }
    // 0x80074578: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007457C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_80074580:
    // 0x80074580: jal         0x8006A100
    // 0x80074584: nop

    si_mesg(rdram, ctx);
        goto after_5;
    // 0x80074584: nop

    after_5:
    // 0x80074588: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x8007458C: addu        $a2, $t6, $s3
    ctx->r6 = ADD32(ctx->r14, ctx->r19);
    // 0x80074590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074594: jal         0x800CE580
    // 0x80074598: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    osEepromWrite_recomp(rdram, ctx);
        goto after_6;
    // 0x80074598: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_6:
    // 0x8007459C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800745A0: bne         $s0, $s2, L_80074580
    if (ctx->r16 != ctx->r18) {
        // 0x800745A4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80074580;
    }
    // 0x800745A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800745A8:
    // 0x800745A8: jal         0x80071140
    // 0x800745AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x800745AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x800745B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800745B4:
    // 0x800745B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800745B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800745BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800745C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800745C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800745C8: jr          $ra
    // 0x800745CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800745CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void weather_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABE68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ABE6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ABE70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800ABE74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800ABE78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800ABE7C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800ABE80: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800ABE84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ABE88: sw          $t7, 0x7C0C($at)
    MEM_W(0X7C0C, ctx->r1) = ctx->r15;
    // 0x800ABE8C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800ABE90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ABE94: sw          $t9, 0x7C10($at)
    MEM_W(0X7C10, ctx->r1) = ctx->r25;
    // 0x800ABE98: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800ABE9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ABEA0: sw          $t1, 0x7C14($at)
    MEM_W(0X7C14, ctx->r1) = ctx->r9;
    // 0x800ABEA4: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800ABEA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ABEAC: jal         0x80069D20
    // 0x800ABEB0: sw          $t3, 0x7C18($at)
    MEM_W(0X7C18, ctx->r1) = ctx->r11;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x800ABEB0: sw          $t3, 0x7C18($at)
    MEM_W(0X7C18, ctx->r1) = ctx->r11;
    after_0:
    // 0x800ABEB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ABEB8: jal         0x80069DBC
    // 0x800ABEBC: sw          $v0, 0x7C1C($at)
    MEM_W(0X7C1C, ctx->r1) = ctx->r2;
    get_camera_matrix(rdram, ctx);
        goto after_1;
    // 0x800ABEBC: sw          $v0, 0x7C1C($at)
    MEM_W(0X7C1C, ctx->r1) = ctx->r2;
    after_1:
    // 0x800ABEC0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800ABEC4: lw          $t4, 0x2C5C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2C5C);
    // 0x800ABEC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ABECC: beq         $t4, $zero, L_800ABEE8
    if (ctx->r12 == 0) {
        // 0x800ABED0: sw          $v0, 0x7C20($at)
        MEM_W(0X7C20, ctx->r1) = ctx->r2;
            goto L_800ABEE8;
    }
    // 0x800ABED0: sw          $v0, 0x7C20($at)
    MEM_W(0X7C20, ctx->r1) = ctx->r2;
    // 0x800ABED4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800ABED8: jal         0x800AD4B8
    // 0x800ABEDC: nop

    rain_update(rdram, ctx);
        goto after_2;
    // 0x800ABEDC: nop

    after_2:
    // 0x800ABEE0: b           L_800AC074
    // 0x800ABEE4: nop

        goto L_800AC074;
    // 0x800ABEE4: nop

L_800ABEE8:
    // 0x800ABEE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800ABEEC: addiu       $v0, $v0, 0x7BB8
    ctx->r2 = ADD32(ctx->r2, 0X7BB8);
    // 0x800ABEF0: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x800ABEF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800ABEF8: blez        $v1, L_800ABFB8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800ABEFC: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800ABFB8;
    }
    // 0x800ABEFC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800ABF00: beq         $at, $zero, L_800ABF8C
    if (ctx->r1 == 0) {
        // 0x800ABF04: nop
    
            goto L_800ABF8C;
    }
    // 0x800ABF04: nop

    // 0x800ABF08: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800ABF0C: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800ABF10: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ABF14: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x800ABF18: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800ABF1C: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x800ABF20: lw          $t3, 0x18($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18);
    // 0x800ABF24: mflo        $t7
    ctx->r15 = lo;
    // 0x800ABF28: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800ABF2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800ABF30: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ABF34: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x800ABF38: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x800ABF3C: mflo        $t1
    ctx->r9 = lo;
    // 0x800ABF40: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800ABF44: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800ABF48: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ABF4C: lw          $t2, 0x34($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X34);
    // 0x800ABF50: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x800ABF54: mflo        $t6
    ctx->r14 = lo;
    // 0x800ABF58: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x800ABF5C: subu        $t6, $v1, $a0
    ctx->r14 = SUB32(ctx->r3, ctx->r4);
    // 0x800ABF60: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ABF64: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x800ABF68: sw          $t6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r14;
    // 0x800ABF6C: mflo        $t0
    ctx->r8 = lo;
    // 0x800ABF70: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800ABF74: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x800ABF78: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ABF7C: mflo        $t4
    ctx->r12 = lo;
    // 0x800ABF80: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x800ABF84: b           L_800ABFB8
    // 0x800ABF88: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
        goto L_800ABFB8;
    // 0x800ABF88: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_800ABF8C:
    // 0x800ABF8C: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800ABF90: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x800ABF94: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x800ABF98: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x800ABF9C: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x800ABFA0: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800ABFA4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800ABFA8: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x800ABFAC: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x800ABFB0: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x800ABFB4: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_800ABFB8:
    // 0x800ABFB8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800ABFBC: lw          $t2, 0x7BB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7BB0);
    // 0x800ABFC0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800ABFC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800ABFC8: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ABFCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ABFD0: addiu       $a1, $a1, 0x7BF8
    ctx->r5 = ADD32(ctx->r5, 0X7BF8);
    // 0x800ABFD4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800ABFD8: mflo        $t4
    ctx->r12 = lo;
    // 0x800ABFDC: sra         $t3, $t4, 16
    ctx->r11 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800ABFE0: sw          $t3, 0x7BB4($at)
    MEM_W(0X7BB4, ctx->r1) = ctx->r11;
    // 0x800ABFE4: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x800ABFE8: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x800ABFEC: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x800ABFF0: subu        $t5, $t6, $v1
    ctx->r13 = SUB32(ctx->r14, ctx->r3);
    // 0x800ABFF4: multu       $t5, $t8
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ABFF8: mflo        $t7
    ctx->r15 = lo;
    // 0x800ABFFC: addu        $t0, $v1, $t7
    ctx->r8 = ADD32(ctx->r3, ctx->r15);
    // 0x800AC000: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800AC004: jal         0x800AC0C8
    // 0x800AC008: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    snow_update(rdram, ctx);
        goto after_3;
    // 0x800AC008: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    after_3:
    // 0x800AC00C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800AC010: lw          $t2, 0x7BB4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7BB4);
    // 0x800AC014: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AC018: blez        $t2, L_800AC074
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AC01C: addiu       $a1, $a1, 0x7BF8
        ctx->r5 = ADD32(ctx->r5, 0X7BF8);
            goto L_800AC074;
    }
    // 0x800AC01C: addiu       $a1, $a1, 0x7BF8
    ctx->r5 = ADD32(ctx->r5, 0X7BF8);
    // 0x800AC020: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x800AC024: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800AC028: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AC02C: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AC030: beq         $at, $zero, L_800AC074
    if (ctx->r1 == 0) {
        // 0x800AC034: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800AC074;
    }
    // 0x800AC034: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AC038: lw          $t3, 0x7C08($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7C08);
    // 0x800AC03C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC040: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800AC044: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800AC048: lw          $t5, 0x2914($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2914);
    // 0x800AC04C: jal         0x800AC21C
    // 0x800AC050: sw          $t5, 0x2904($at)
    MEM_W(0X2904, ctx->r1) = ctx->r13;
    snow_vertices(rdram, ctx);
        goto after_4;
    // 0x800AC050: sw          $t5, 0x2904($at)
    MEM_W(0X2904, ctx->r1) = ctx->r13;
    after_4:
    // 0x800AC054: jal         0x800AC5A4
    // 0x800AC058: nop

    snow_render(rdram, ctx);
        goto after_5;
    // 0x800AC058: nop

    after_5:
    // 0x800AC05C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AC060: addiu       $v0, $v0, 0x7C08
    ctx->r2 = ADD32(ctx->r2, 0X7C08);
    // 0x800AC064: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AC068: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AC06C: subu        $t0, $t7, $t8
    ctx->r8 = SUB32(ctx->r15, ctx->r24);
    // 0x800AC070: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_800AC074:
    // 0x800AC074: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AC078: lw          $t9, 0x7C0C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7C0C);
    // 0x800AC07C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800AC080: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AC084: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800AC088: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC08C: lw          $t1, 0x7C10($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7C10);
    // 0x800AC090: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AC094: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800AC098: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800AC09C: lw          $t3, 0x7C14($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7C14);
    // 0x800AC0A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AC0A4: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AC0A8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800AC0AC: lw          $t5, 0x7C18($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7C18);
    // 0x800AC0B0: nop

    // 0x800AC0B4: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x800AC0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC0BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AC0C0: jr          $ra
    // 0x800AC0C4: nop

    return;
    // 0x800AC0C4: nop

;}
RECOMP_FUNC void func_8007F1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F1E8: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x8007F1EC: lbu         $t7, 0x15($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X15);
    // 0x8007F1F0: lbu         $t8, 0x16($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X16);
    // 0x8007F1F4: lbu         $t9, 0x17($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X17);
    // 0x8007F1F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007F1FC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007F200: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8007F204: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8007F208: sb          $t6, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r14;
    // 0x8007F20C: sb          $t7, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r15;
    // 0x8007F210: sb          $t8, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r24;
    // 0x8007F214: blez        $v1, L_8007F244
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007F218: sb          $t9, 0x13($a0)
        MEM_B(0X13, ctx->r4) = ctx->r25;
            goto L_8007F244;
    }
    // 0x8007F218: sb          $t9, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r25;
    // 0x8007F21C: sll         $t0, $v1, 3
    ctx->r8 = S32(ctx->r3 << 3);
    // 0x8007F220: addu        $a1, $t0, $a0
    ctx->r5 = ADD32(ctx->r8, ctx->r4);
    // 0x8007F224: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007F228:
    // 0x8007F228: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8007F22C: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    // 0x8007F230: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007F234: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8007F238: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8007F23C: bne         $at, $zero, L_8007F228
    if (ctx->r1 != 0) {
        // 0x8007F240: sw          $t3, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r11;
            goto L_8007F228;
    }
    // 0x8007F240: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
L_8007F244:
    // 0x8007F244: jr          $ra
    // 0x8007F248: nop

    return;
    // 0x8007F248: nop

;}
RECOMP_FUNC void drm_vehicle_traction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C25C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C260: lwc1        $f4, 0x6A00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6A00);
    // 0x8005C264: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C268: jr          $ra
    // 0x8005C26C: swc1        $f4, -0x3464($at)
    MEM_W(-0X3464, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x8005C26C: swc1        $f4, -0x3464($at)
    MEM_W(-0X3464, ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void racer_ai_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004447C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044480: sw          $zero, -0x2AD4($at)
    MEM_W(-0X2AD4, ctx->r1) = 0;
    // 0x80044484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044488: sw          $zero, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = 0;
    // 0x8004448C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044490: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80044494: sw          $zero, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = 0;
    // 0x80044498: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004449C: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
    // 0x800444A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800444A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800444A8: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800444AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800444B0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800444B4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800444B8: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
    // 0x800444BC: jal         0x8001BA74
    // 0x800444C0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800444C0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x800444C4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800444C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800444CC: bne         $t6, $at, L_8004511C
    if (ctx->r14 != ctx->r1) {
        // 0x800444D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004511C;
    }
    // 0x800444D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800444D4: jal         0x8006BDB0
    // 0x800444D8: nop

    level_header(rdram, ctx);
        goto after_1;
    // 0x800444D8: nop

    after_1:
    // 0x800444DC: lb          $t7, 0x4C($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X4C);
    // 0x800444E0: addiu       $t8, $v0, 0x2A
    ctx->r24 = ADD32(ctx->r2, 0X2A);
    // 0x800444E4: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800444E8: sb          $t7, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r15;
    // 0x800444EC: lbu         $t9, 0x1CD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1CD);
    // 0x800444F0: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800444F4: bne         $t9, $zero, L_80044538
    if (ctx->r25 != 0) {
        // 0x800444F8: nop
    
            goto L_80044538;
    }
    // 0x800444F8: nop

    // 0x800444FC: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80044500: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80044504: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80044508: jal         0x8001C524
    // 0x8004450C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_2;
    // 0x8004450C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80044510: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044514: beq         $v0, $at, L_80044538
    if (ctx->r2 == ctx->r1) {
        // 0x80044518: sw          $v0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r2;
            goto L_80044538;
    }
    // 0x80044518: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004451C: jal         0x8001D214
    // 0x80044520: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    ainode_get(rdram, ctx);
        goto after_3;
    // 0x80044520: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80044524: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80044528: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8004452C: sw          $v0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r2;
    // 0x80044530: sb          $t4, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r12;
    // 0x80044534: sb          $t5, 0x1CE($s0)
    MEM_B(0X1CE, ctx->r16) = ctx->r13;
L_80044538:
    // 0x80044538: lw          $a2, 0x154($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X154);
    // 0x8004453C: nop

    // 0x80044540: beq         $a2, $zero, L_8004460C
    if (ctx->r6 == 0) {
        // 0x80044544: nop
    
            goto L_8004460C;
    }
    // 0x80044544: nop

    // 0x80044548: lw          $t6, 0x3C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X3C);
    // 0x8004454C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80044550: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x80044554: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80044558: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004455C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80044560: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80044564: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80044568: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8004456C: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80044570: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80044574: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80044578: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8004457C: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    // 0x80044580: jal         0x800C9AD0
    // 0x80044584: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80044584: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_4:
    // 0x80044588: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8004458C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80044590: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80044594: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80044598: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8004459C: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800445A0: bc1f        L_8004460C
    if (!c1cs) {
        // 0x800445A4: swc1        $f0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
            goto L_8004460C;
    }
    // 0x800445A4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800445A8: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800445AC: jal         0x80070750
    // 0x800445B0: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    arctan2_f(rdram, ctx);
        goto after_5;
    // 0x800445B0: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    after_5:
    // 0x800445B4: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800445B8: addu        $t7, $v0, $at
    ctx->r15 = ADD32(ctx->r2, ctx->r1);
    // 0x800445BC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800445C0: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x800445C4: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x800445C8: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800445CC: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800445D0: subu        $v1, $t8, $t4
    ctx->r3 = SUB32(ctx->r24, ctx->r12);
    // 0x800445D4: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x800445D8: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800445DC: bne         $at, $zero, L_800445EC
    if (ctx->r1 != 0) {
        // 0x800445E0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800445EC;
    }
    // 0x800445E0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800445E4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800445E8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800445EC:
    // 0x800445EC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800445F0: beq         $at, $zero, L_800445FC
    if (ctx->r1 == 0) {
        // 0x800445F4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800445FC;
    }
    // 0x800445F4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800445F8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800445FC:
    // 0x800445FC: negu        $t5, $v1
    ctx->r13 = SUB32(0, ctx->r3);
    // 0x80044600: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x80044604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044608: sw          $t6, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r14;
L_8004460C:
    // 0x8004460C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80044610: lw          $t7, -0x2AC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC0);
    // 0x80044614: nop

    // 0x80044618: beq         $t7, $zero, L_80044624
    if (ctx->r15 == 0) {
        // 0x8004461C: nop
    
            goto L_80044624;
    }
    // 0x8004461C: nop

    // 0x80044620: sh          $zero, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = 0;
L_80044624:
    // 0x80044624: lbu         $v1, 0x1CD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1CD);
    // 0x80044628: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004462C: beq         $v1, $at, L_80044644
    if (ctx->r3 == ctx->r1) {
        // 0x80044630: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80044644;
    }
    // 0x80044630: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80044634: beq         $v1, $at, L_80044644
    if (ctx->r3 == ctx->r1) {
        // 0x80044638: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80044644;
    }
    // 0x80044638: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004463C: bne         $v1, $at, L_80044664
    if (ctx->r3 != ctx->r1) {
        // 0x80044640: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_80044664;
    }
    // 0x80044640: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
L_80044644:
    // 0x80044644: lh          $v0, 0x1C6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C6);
    // 0x80044648: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8004464C: blez        $v0, L_8004465C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80044650: subu        $t8, $v0, $t9
        ctx->r24 = SUB32(ctx->r2, ctx->r25);
            goto L_8004465C;
    }
    // 0x80044650: subu        $t8, $v0, $t9
    ctx->r24 = SUB32(ctx->r2, ctx->r25);
    // 0x80044654: b           L_80044660
    // 0x80044658: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
        goto L_80044660;
    // 0x80044658: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
L_8004465C:
    // 0x8004465C: sh          $zero, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = 0;
L_80044660:
    // 0x80044660: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
L_80044664:
    // 0x80044664: nop

    // 0x80044668: lwc1        $f12, 0x10($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8004466C: jal         0x8001C418
    // 0x80044670: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    obj_elevation(rdram, ctx);
        goto after_6;
    // 0x80044670: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    after_6:
    // 0x80044674: lbu         $v1, 0x1CD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1CD);
    // 0x80044678: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8004467C: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80044680: sltiu       $at, $t5, 0x7
    ctx->r1 = ctx->r13 < 0X7 ? 1 : 0;
    // 0x80044684: sb          $v0, 0x212($s0)
    MEM_B(0X212, ctx->r16) = ctx->r2;
    // 0x80044688: beq         $at, $zero, L_80044FA0
    if (ctx->r1 == 0) {
        // 0x8004468C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80044FA0;
    }
    // 0x8004468C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044690: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80044694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044698: addu        $at, $at, $t5
    gpr jr_addend_800446A4 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8004469C: lw          $t5, 0x6318($at)
    ctx->r13 = ADD32(ctx->r1, 0X6318);
    // 0x800446A0: nop

    // 0x800446A4: jr          $t5
    // 0x800446A8: nop

    switch (jr_addend_800446A4 >> 2) {
        case 0: goto L_800446AC; break;
        case 1: goto L_80044A04; break;
        case 2: goto L_80044A04; break;
        case 3: goto L_80044A04; break;
        case 4: goto L_80044A04; break;
        case 5: goto L_80044F54; break;
        case 6: goto L_80044A04; break;
        default: switch_error(__func__, 0x800446A4, 0x800E6318);
    }
    // 0x800446A8: nop

L_800446AC:
    // 0x800446AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800446B0: jal         0x8006F94C
    // 0x800446B4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800446B4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_7:
    // 0x800446B8: lb          $t6, 0x173($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X173);
    // 0x800446BC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800446C0: bne         $t6, $zero, L_80044798
    if (ctx->r14 != 0) {
        // 0x800446C4: nop
    
            goto L_80044798;
    }
    // 0x800446C4: nop

    // 0x800446C8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800446CC: nop

    // 0x800446D0: lb          $a0, 0x3($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X3);
    // 0x800446D4: jal         0x80044450
    // 0x800446D8: nop

    roll_percent_chance(rdram, ctx);
        goto after_8;
    // 0x800446D8: nop

    after_8:
    // 0x800446DC: beq         $v0, $zero, L_800446EC
    if (ctx->r2 == 0) {
        // 0x800446E0: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_800446EC;
    }
    // 0x800446E0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800446E4: b           L_80044FA0
    // 0x800446E8: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
        goto L_80044FA0;
    // 0x800446E8: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
L_800446EC:
    // 0x800446EC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800446F0: nop

    // 0x800446F4: lb          $a0, 0x6($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X6);
    // 0x800446F8: jal         0x80044450
    // 0x800446FC: nop

    roll_percent_chance(rdram, ctx);
        goto after_9;
    // 0x800446FC: nop

    after_9:
    // 0x80044700: beq         $v0, $zero, L_80044738
    if (ctx->r2 == 0) {
        // 0x80044704: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80044738;
    }
    // 0x80044704: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80044708: lb          $t4, 0x3F($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X3F);
    // 0x8004470C: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x80044710: bne         $t4, $at, L_80044738
    if (ctx->r12 != ctx->r1) {
        // 0x80044714: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80044738;
    }
    // 0x80044714: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80044718: lb          $t5, 0x185($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X185);
    // 0x8004471C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80044720: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x80044724: bne         $at, $zero, L_80044738
    if (ctx->r1 != 0) {
        // 0x80044728: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80044738;
    }
    // 0x80044728: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8004472C: b           L_80044FA0
    // 0x80044730: sb          $t6, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r14;
        goto L_80044FA0;
    // 0x80044730: sb          $t6, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r14;
    // 0x80044734: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
L_80044738:
    // 0x80044738: nop

    // 0x8004473C: lb          $a0, 0x5($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X5);
    // 0x80044740: jal         0x80044450
    // 0x80044744: nop

    roll_percent_chance(rdram, ctx);
        goto after_10;
    // 0x80044744: nop

    after_10:
    // 0x80044748: beq         $v0, $zero, L_80044784
    if (ctx->r2 == 0) {
        // 0x8004474C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80044784;
    }
    // 0x8004474C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80044750: lb          $t9, 0x2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X2);
    // 0x80044754: addiu       $t8, $t8, -0x2A74
    ctx->r24 = ADD32(ctx->r24, -0X2A74);
    // 0x80044758: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x8004475C: lb          $t4, 0x0($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X0);
    // 0x80044760: addiu       $t5, $zero, 0x4B0
    ctx->r13 = ADD32(0, 0X4B0);
    // 0x80044764: beq         $t4, $zero, L_80044784
    if (ctx->r12 == 0) {
        // 0x80044768: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_80044784;
    }
    // 0x80044768: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8004476C: sh          $t5, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r13;
    // 0x80044770: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80044774: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x80044778: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8004477C: b           L_80044FA0
    // 0x80044780: sb          $t7, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r15;
        goto L_80044FA0;
    // 0x80044780: sb          $t7, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r15;
L_80044784:
    // 0x80044784: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80044788: addiu       $t4, $zero, 0x12C
    ctx->r12 = ADD32(0, 0X12C);
    // 0x8004478C: sb          $t8, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r24;
    // 0x80044790: b           L_80044FA0
    // 0x80044794: sh          $t4, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r12;
        goto L_80044FA0;
    // 0x80044794: sh          $t4, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r12;
L_80044798:
    // 0x80044798: lb          $a0, 0x6($t5)
    ctx->r4 = MEM_B(ctx->r13, 0X6);
    // 0x8004479C: jal         0x80044450
    // 0x800447A0: nop

    roll_percent_chance(rdram, ctx);
        goto after_11;
    // 0x800447A0: nop

    after_11:
    // 0x800447A4: beq         $v0, $zero, L_800447DC
    if (ctx->r2 == 0) {
        // 0x800447A8: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_800447DC;
    }
    // 0x800447A8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800447AC: lb          $t6, 0x3F($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X3F);
    // 0x800447B0: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800447B4: bne         $t6, $at, L_800447DC
    if (ctx->r14 != ctx->r1) {
        // 0x800447B8: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_800447DC;
    }
    // 0x800447B8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800447BC: lb          $t7, 0x185($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X185);
    // 0x800447C0: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800447C4: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800447C8: bne         $at, $zero, L_800447DC
    if (ctx->r1 != 0) {
        // 0x800447CC: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_800447DC;
    }
    // 0x800447CC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800447D0: b           L_80044FA0
    // 0x800447D4: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
        goto L_80044FA0;
    // 0x800447D4: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x800447D8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_800447DC:
    // 0x800447DC: nop

    // 0x800447E0: lb          $a0, 0x0($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X0);
    // 0x800447E4: jal         0x80044450
    // 0x800447E8: nop

    roll_percent_chance(rdram, ctx);
        goto after_12;
    // 0x800447E8: nop

    after_12:
    // 0x800447EC: beq         $v0, $zero, L_800449F4
    if (ctx->r2 == 0) {
        // 0x800447F0: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_800449F4;
    }
    // 0x800447F0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800447F4: jal         0x80044450
    // 0x800447F8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    roll_percent_chance(rdram, ctx);
        goto after_13;
    // 0x800447F8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_13:
    // 0x800447FC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80044800: beq         $v0, $zero, L_80044810
    if (ctx->r2 == 0) {
        // 0x80044804: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80044810;
    }
    // 0x80044804: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80044808: b           L_80044810
    // 0x8004480C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80044810;
    // 0x8004480C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80044810:
    // 0x80044810: lb          $a0, 0x1($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X1);
    // 0x80044814: jal         0x80044450
    // 0x80044818: sh          $t2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r10;
    roll_percent_chance(rdram, ctx);
        goto after_14;
    // 0x80044818: sh          $t2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r10;
    after_14:
    // 0x8004481C: lh          $t2, 0x4C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4C);
    // 0x80044820: beq         $v0, $zero, L_80044830
    if (ctx->r2 == 0) {
        // 0x80044824: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_80044830;
    }
    // 0x80044824: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80044828: b           L_80044834
    // 0x8004482C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_80044834;
    // 0x8004482C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80044830:
    // 0x80044830: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80044834:
    // 0x80044834: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80044838: sll         $t5, $a3, 20
    ctx->r13 = S32(ctx->r7 << 20);
    // 0x8004483C: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80044840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80044844:
    // 0x80044844: beq         $t2, $zero, L_80044860
    if (ctx->r10 == 0) {
        // 0x80044848: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80044860;
    }
    // 0x80044848: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004484C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80044850: subu        $a2, $t7, $a1
    ctx->r6 = SUB32(ctx->r15, ctx->r5);
    // 0x80044854: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80044858: b           L_8004486C
    // 0x8004485C: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
        goto L_8004486C;
    // 0x8004485C: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
L_80044860:
    // 0x80044860: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x80044864: sra         $t4, $a2, 16
    ctx->r12 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80044868: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
L_8004486C:
    // 0x8004486C: addu        $t5, $t5, $a2
    ctx->r13 = ADD32(ctx->r13, ctx->r6);
    // 0x80044870: lb          $t5, -0x2A74($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X2A74);
    // 0x80044874: nop

    // 0x80044878: bne         $t5, $zero, L_80044930
    if (ctx->r13 != 0) {
        // 0x8004487C: nop
    
            goto L_80044930;
    }
    // 0x8004487C: nop

    // 0x80044880: lb          $t6, 0x2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X2);
    // 0x80044884: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80044888: beq         $a2, $t6, L_80044930
    if (ctx->r6 == ctx->r14) {
        // 0x8004488C: nop
    
            goto L_80044930;
    }
    // 0x8004488C: nop

    // 0x80044890: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    // 0x80044894: sh          $a2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r6;
    // 0x80044898: sh          $a3, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r7;
    // 0x8004489C: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    // 0x800448A0: sh          $t1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r9;
    // 0x800448A4: jal         0x8001BAC8
    // 0x800448A8: sh          $t2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r10;
    get_racer_object(rdram, ctx);
        goto after_15;
    // 0x800448A8: sh          $t2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r10;
    after_15:
    // 0x800448AC: lh          $t1, 0x46($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X46);
    // 0x800448B0: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    // 0x800448B4: lh          $a2, 0x50($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X50);
    // 0x800448B8: lh          $a3, 0x48($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X48);
    // 0x800448BC: lh          $t0, 0x4A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4A);
    // 0x800448C0: lh          $t2, 0x4C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4C);
    // 0x800448C4: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x800448C8: bne         $t1, $zero, L_80044900
    if (ctx->r9 != 0) {
        // 0x800448CC: nop
    
            goto L_80044900;
    }
    // 0x800448CC: nop

    // 0x800448D0: lb          $v0, 0x185($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X185);
    // 0x800448D4: nop

    // 0x800448D8: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800448DC: beq         $at, $zero, L_80044930
    if (ctx->r1 == 0) {
        // 0x800448E0: nop
    
            goto L_80044930;
    }
    // 0x800448E0: nop

    // 0x800448E4: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x800448E8: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x800448EC: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800448F0: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800448F4: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800448F8: b           L_80044930
    // 0x800448FC: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
        goto L_80044930;
    // 0x800448FC: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
L_80044900:
    // 0x80044900: lb          $v0, 0x185($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X185);
    // 0x80044904: nop

    // 0x80044908: blez        $v0, L_80044930
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004490C: slt         $at, $v0, $a3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80044930;
    }
    // 0x8004490C: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80044910: beq         $at, $zero, L_80044930
    if (ctx->r1 == 0) {
        // 0x80044914: nop
    
            goto L_80044930;
    }
    // 0x80044914: nop

    // 0x80044918: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8004491C: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x80044920: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80044924: sra         $t4, $t0, 16
    ctx->r12 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80044928: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8004492C: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
L_80044930:
    // 0x80044930: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80044934: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80044938: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004493C: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80044940: bne         $at, $zero, L_80044844
    if (ctx->r1 != 0) {
        // 0x80044944: nop
    
            goto L_80044844;
    }
    // 0x80044944: nop

    // 0x80044948: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8004494C: nop

    // 0x80044950: lb          $a0, 0x2($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X2);
    // 0x80044954: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    // 0x80044958: jal         0x80044450
    // 0x8004495C: sh          $a2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r6;
    roll_percent_chance(rdram, ctx);
        goto after_16;
    // 0x8004495C: sh          $a2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r6;
    after_16:
    // 0x80044960: lh          $a2, 0x50($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X50);
    // 0x80044964: lh          $t0, 0x4A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4A);
    // 0x80044968: beq         $v0, $zero, L_800449B0
    if (ctx->r2 == 0) {
        // 0x8004496C: nop
    
            goto L_800449B0;
    }
    // 0x8004496C: nop

    // 0x80044970: sh          $a2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r6;
    // 0x80044974: jal         0x80066210
    // 0x80044978: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    cam_get_viewport_layout(rdram, ctx);
        goto after_17;
    // 0x80044978: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    after_17:
    // 0x8004497C: lh          $a2, 0x50($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X50);
    // 0x80044980: lh          $t0, 0x4A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4A);
    // 0x80044984: bne         $v0, $zero, L_800449B0
    if (ctx->r2 != 0) {
        // 0x80044988: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800449B0;
    }
    // 0x80044988: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004498C: jal         0x8001BAC8
    // 0x80044990: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    get_racer_object(rdram, ctx);
        goto after_18;
    // 0x80044990: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    after_18:
    // 0x80044994: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80044998: lh          $t0, 0x4A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4A);
    // 0x8004499C: lb          $t9, 0x185($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X185);
    // 0x800449A0: nop

    // 0x800449A4: blez        $t9, L_800449B0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800449A8: nop
    
            goto L_800449B0;
    }
    // 0x800449A8: nop

    // 0x800449AC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800449B0:
    // 0x800449B0: bltz        $t0, L_800449E4
    if (SIGNED(ctx->r8) < 0) {
        // 0x800449B4: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800449E4;
    }
    // 0x800449B4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800449B8: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
    // 0x800449BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800449C0: sb          $t0, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r8;
    // 0x800449C4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800449C8: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x800449CC: sb          $t4, -0x2A74($at)
    MEM_B(-0X2A74, ctx->r1) = ctx->r12;
    // 0x800449D0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800449D4: addiu       $t6, $zero, 0x4B0
    ctx->r14 = ADD32(0, 0X4B0);
    // 0x800449D8: sb          $t5, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r13;
    // 0x800449DC: b           L_80044FA0
    // 0x800449E0: sh          $t6, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r14;
        goto L_80044FA0;
    // 0x800449E0: sh          $t6, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r14;
L_800449E4:
    // 0x800449E4: addiu       $t9, $zero, 0x4B0
    ctx->r25 = ADD32(0, 0X4B0);
    // 0x800449E8: sb          $t7, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r15;
    // 0x800449EC: b           L_80044FA0
    // 0x800449F0: sh          $t9, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r25;
        goto L_80044FA0;
    // 0x800449F0: sh          $t9, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r25;
L_800449F4:
    // 0x800449F4: addiu       $t4, $zero, 0x12C
    ctx->r12 = ADD32(0, 0X12C);
    // 0x800449F8: sb          $t8, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r24;
    // 0x800449FC: b           L_80044FA0
    // 0x80044A00: sh          $t4, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r12;
        goto L_80044FA0;
    // 0x80044A00: sh          $t4, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r12;
L_80044A04:
    // 0x80044A04: addiu       $t5, $v1, -0x2
    ctx->r13 = ADD32(ctx->r3, -0X2);
    // 0x80044A08: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x80044A0C: beq         $at, $zero, L_80044ADC
    if (ctx->r1 == 0) {
        // 0x80044A10: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80044ADC;
    }
    // 0x80044A10: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80044A14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044A18: addu        $at, $at, $t5
    gpr jr_addend_80044A24 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80044A1C: lw          $t5, 0x6334($at)
    ctx->r13 = ADD32(ctx->r1, 0X6334);
    // 0x80044A20: nop

    // 0x80044A24: jr          $t5
    // 0x80044A28: nop

    switch (jr_addend_80044A24 >> 2) {
        case 0: goto L_80044A2C; break;
        case 1: goto L_80044A44; break;
        case 2: goto L_80044A60; break;
        case 3: goto L_80044A94; break;
        case 4: goto L_80044ADC; break;
        case 5: goto L_80044AC8; break;
        default: switch_error(__func__, 0x80044A24, 0x800E6334);
    }
    // 0x80044A28: nop

L_80044A2C:
    // 0x80044A2C: lh          $t6, 0x1C6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1C6);
    // 0x80044A30: nop

    // 0x80044A34: bne         $t6, $zero, L_80044ADC
    if (ctx->r14 != 0) {
        // 0x80044A38: nop
    
            goto L_80044ADC;
    }
    // 0x80044A38: nop

    // 0x80044A3C: b           L_80044ADC
    // 0x80044A40: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
        goto L_80044ADC;
    // 0x80044A40: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
L_80044A44:
    // 0x80044A44: lb          $t7, 0x172($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X172);
    // 0x80044A48: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80044A4C: beq         $t7, $zero, L_80044ADC
    if (ctx->r15 == 0) {
        // 0x80044A50: addiu       $t8, $zero, 0xB4
        ctx->r24 = ADD32(0, 0XB4);
            goto L_80044ADC;
    }
    // 0x80044A50: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x80044A54: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x80044A58: b           L_80044ADC
    // 0x80044A5C: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
        goto L_80044ADC;
    // 0x80044A5C: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
L_80044A60:
    // 0x80044A60: lb          $t4, 0x173($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X173);
    // 0x80044A64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044A68: beq         $t4, $zero, L_80044A80
    if (ctx->r12 == 0) {
        // 0x80044A6C: nop
    
            goto L_80044A80;
    }
    // 0x80044A6C: nop

    // 0x80044A70: lh          $t5, 0x1C6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1C6);
    // 0x80044A74: nop

    // 0x80044A78: bne         $t5, $zero, L_80044ADC
    if (ctx->r13 != 0) {
        // 0x80044A7C: nop
    
            goto L_80044ADC;
    }
    // 0x80044A7C: nop

L_80044A80:
    // 0x80044A80: lb          $t6, 0x1CF($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CF);
    // 0x80044A84: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
    // 0x80044A88: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80044A8C: b           L_80044ADC
    // 0x80044A90: sb          $zero, -0x2A74($at)
    MEM_B(-0X2A74, ctx->r1) = 0;
        goto L_80044ADC;
    // 0x80044A90: sb          $zero, -0x2A74($at)
    MEM_B(-0X2A74, ctx->r1) = 0;
L_80044A94:
    // 0x80044A94: lb          $t7, 0x2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X2);
    // 0x80044A98: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80044A9C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80044AA0: lb          $t9, -0x2A74($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2A74);
    // 0x80044AA4: nop

    // 0x80044AA8: beq         $t9, $zero, L_80044AC0
    if (ctx->r25 == 0) {
        // 0x80044AAC: nop
    
            goto L_80044AC0;
    }
    // 0x80044AAC: nop

    // 0x80044AB0: lh          $t8, 0x1C6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1C6);
    // 0x80044AB4: nop

    // 0x80044AB8: bne         $t8, $zero, L_80044ADC
    if (ctx->r24 != 0) {
        // 0x80044ABC: nop
    
            goto L_80044ADC;
    }
    // 0x80044ABC: nop

L_80044AC0:
    // 0x80044AC0: b           L_80044ADC
    // 0x80044AC4: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
        goto L_80044ADC;
    // 0x80044AC4: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
L_80044AC8:
    // 0x80044AC8: lb          $t4, 0x185($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X185);
    // 0x80044ACC: nop

    // 0x80044AD0: bne         $t4, $zero, L_80044ADC
    if (ctx->r12 != 0) {
        // 0x80044AD4: nop
    
            goto L_80044ADC;
    }
    // 0x80044AD4: nop

    // 0x80044AD8: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
L_80044ADC:
    // 0x80044ADC: lbu         $a0, 0x1CE($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044AE0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044AE4: beq         $a0, $at, L_80044B80
    if (ctx->r4 == ctx->r1) {
        // 0x80044AE8: nop
    
            goto L_80044B80;
    }
    // 0x80044AE8: nop

    // 0x80044AEC: lb          $v1, 0x212($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X212);
    // 0x80044AF0: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    // 0x80044AF4: jal         0x8001D214
    // 0x80044AF8: sh          $v1, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r3;
    ainode_get(rdram, ctx);
        goto after_19;
    // 0x80044AF8: sh          $v1, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r3;
    after_19:
    // 0x80044AFC: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80044B00: lw          $t2, 0x3C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X3C);
    // 0x80044B04: lb          $a0, 0xE($t3)
    ctx->r4 = MEM_B(ctx->r11, 0XE);
    // 0x80044B08: lb          $a1, 0xE($t2)
    ctx->r5 = MEM_B(ctx->r10, 0XE);
    // 0x80044B0C: lh          $v1, 0x4E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X4E);
    // 0x80044B10: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80044B14: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80044B18: beq         $at, $zero, L_80044B3C
    if (ctx->r1 == 0) {
        // 0x80044B1C: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80044B3C;
    }
    // 0x80044B1C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80044B20: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80044B24: bne         $at, $zero, L_80044B34
    if (ctx->r1 != 0) {
        // 0x80044B28: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80044B34;
    }
    // 0x80044B28: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80044B2C: beq         $at, $zero, L_80044B54
    if (ctx->r1 == 0) {
        // 0x80044B30: nop
    
            goto L_80044B54;
    }
    // 0x80044B30: nop

L_80044B34:
    // 0x80044B34: b           L_80044B54
    // 0x80044B38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80044B54;
    // 0x80044B38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80044B3C:
    // 0x80044B3C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80044B40: bne         $at, $zero, L_80044B50
    if (ctx->r1 != 0) {
        // 0x80044B44: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80044B50;
    }
    // 0x80044B44: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80044B48: beq         $at, $zero, L_80044B54
    if (ctx->r1 == 0) {
        // 0x80044B4C: nop
    
            goto L_80044B54;
    }
    // 0x80044B4C: nop

L_80044B50:
    // 0x80044B50: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80044B54:
    // 0x80044B54: beq         $t1, $zero, L_80044B80
    if (ctx->r9 == 0) {
        // 0x80044B58: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_80044B80;
    }
    // 0x80044B58: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80044B5C: lbu         $t5, 0x1CD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1CD);
    // 0x80044B60: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80044B64: bne         $t5, $at, L_80044B7C
    if (ctx->r13 != ctx->r1) {
        // 0x80044B68: nop
    
            goto L_80044B7C;
    }
    // 0x80044B68: nop

    // 0x80044B6C: lb          $t6, 0x1CF($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CF);
    // 0x80044B70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044B74: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80044B78: sb          $zero, -0x2A74($at)
    MEM_B(-0X2A74, ctx->r1) = 0;
L_80044B7C:
    // 0x80044B7C: sb          $t7, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r15;
L_80044B80:
    // 0x80044B80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80044B84: lw          $v0, -0x2ACC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2ACC);
    // 0x80044B88: nop

    // 0x80044B8C: slti        $at, $v0, -0x1D
    ctx->r1 = SIGNED(ctx->r2) < -0X1D ? 1 : 0;
    // 0x80044B90: bne         $at, $zero, L_80044BCC
    if (ctx->r1 != 0) {
        // 0x80044B94: slti        $at, $v0, 0x1E
        ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
            goto L_80044BCC;
    }
    // 0x80044B94: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x80044B98: beq         $at, $zero, L_80044BCC
    if (ctx->r1 == 0) {
        // 0x80044B9C: nop
    
            goto L_80044BCC;
    }
    // 0x80044B9C: nop

    // 0x80044BA0: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80044BA4: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x80044BA8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80044BAC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80044BB0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80044BB4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x80044BB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044BBC: bc1f        L_80044C2C
    if (!c1cs) {
        // 0x80044BC0: ori         $t9, $zero, 0x8000
        ctx->r25 = 0 | 0X8000;
            goto L_80044C2C;
    }
    // 0x80044BC0: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x80044BC4: b           L_80044C2C
    // 0x80044BC8: sw          $t9, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r25;
        goto L_80044C2C;
    // 0x80044BC8: sw          $t9, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r25;
L_80044BCC:
    // 0x80044BCC: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80044BD0: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x80044BD4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80044BD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80044BDC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80044BE0: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80044BE4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80044BE8: bc1f        L_80044C00
    if (!c1cs) {
        // 0x80044BEC: addiu       $t4, $zero, 0x4000
        ctx->r12 = ADD32(0, 0X4000);
            goto L_80044C00;
    }
    // 0x80044BEC: addiu       $t4, $zero, 0x4000
    ctx->r12 = ADD32(0, 0X4000);
    // 0x80044BF0: ori         $t8, $zero, 0xC000
    ctx->r24 = 0 | 0XC000;
    // 0x80044BF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044BF8: b           L_80044C08
    // 0x80044BFC: sw          $t8, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r24;
        goto L_80044C08;
    // 0x80044BFC: sw          $t8, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r24;
L_80044C00:
    // 0x80044C00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044C04: sw          $t4, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r12;
L_80044C08:
    // 0x80044C08: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80044C0C: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80044C10: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80044C14: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80044C18: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80044C1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044C20: bc1f        L_80044C2C
    if (!c1cs) {
        // 0x80044C24: ori         $t5, $zero, 0x8000
        ctx->r13 = 0 | 0X8000;
            goto L_80044C2C;
    }
    // 0x80044C24: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x80044C28: sw          $t5, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r13;
L_80044C2C:
    // 0x80044C2C: lw          $t0, 0x158($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X158);
    // 0x80044C30: nop

    // 0x80044C34: beq         $t0, $zero, L_80044D24
    if (ctx->r8 == 0) {
        // 0x80044C38: nop
    
            goto L_80044D24;
    }
    // 0x80044C38: nop

    // 0x80044C3C: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80044C40: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80044C44: lwc1        $f6, 0x14($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80044C48: sub.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80044C4C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80044C50: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80044C54: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80044C58: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80044C5C: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80044C60: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80044C64: jal         0x800C9AD0
    // 0x80044C68: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_20;
    // 0x80044C68: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_20:
    // 0x80044C6C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80044C70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80044C74: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80044C78: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x80044C7C: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80044C80: bc1f        L_80044D24
    if (!c1cs) {
        // 0x80044C84: nop
    
            goto L_80044D24;
    }
    // 0x80044C84: nop

    // 0x80044C88: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80044C8C: jal         0x80070750
    // 0x80044C90: nop

    arctan2_f(rdram, ctx);
        goto after_21;
    // 0x80044C90: nop

    after_21:
    // 0x80044C94: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80044C98: addu        $t6, $v0, $at
    ctx->r14 = ADD32(ctx->r2, ctx->r1);
    // 0x80044C9C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80044CA0: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x80044CA4: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x80044CA8: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80044CAC: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x80044CB0: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x80044CB4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80044CB8: bne         $at, $zero, L_80044CC8
    if (ctx->r1 != 0) {
        // 0x80044CBC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80044CC8;
    }
    // 0x80044CBC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80044CC0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80044CC4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80044CC8:
    // 0x80044CC8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80044CCC: beq         $at, $zero, L_80044CD8
    if (ctx->r1 == 0) {
        // 0x80044CD0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80044CD8;
    }
    // 0x80044CD0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80044CD4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80044CD8:
    // 0x80044CD8: slti        $at, $v1, 0x1501
    ctx->r1 = SIGNED(ctx->r3) < 0X1501 ? 1 : 0;
    // 0x80044CDC: beq         $at, $zero, L_80044CEC
    if (ctx->r1 == 0) {
        // 0x80044CE0: slti        $at, $v1, -0x1500
        ctx->r1 = SIGNED(ctx->r3) < -0X1500 ? 1 : 0;
            goto L_80044CEC;
    }
    // 0x80044CE0: slti        $at, $v1, -0x1500
    ctx->r1 = SIGNED(ctx->r3) < -0X1500 ? 1 : 0;
    // 0x80044CE4: beq         $at, $zero, L_80044D24
    if (ctx->r1 == 0) {
        // 0x80044CE8: nop
    
            goto L_80044D24;
    }
    // 0x80044CE8: nop

L_80044CEC:
    // 0x80044CEC: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80044CF0: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x80044CF4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80044CF8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80044CFC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80044D00: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80044D04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044D08: bc1f        L_80044D20
    if (!c1cs) {
        // 0x80044D0C: addiu       $t5, $zero, 0x4000
        ctx->r13 = ADD32(0, 0X4000);
            goto L_80044D20;
    }
    // 0x80044D0C: addiu       $t5, $zero, 0x4000
    ctx->r13 = ADD32(0, 0X4000);
    // 0x80044D10: ori         $t4, $zero, 0xC000
    ctx->r12 = 0 | 0XC000;
    // 0x80044D14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044D18: b           L_80044D24
    // 0x80044D1C: sw          $t4, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r12;
        goto L_80044D24;
    // 0x80044D1C: sw          $t4, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r12;
L_80044D20:
    // 0x80044D20: sw          $t5, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r13;
L_80044D24:
    // 0x80044D24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044D28: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80044D2C: lwc1        $f19, 0x6350($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6350);
    // 0x80044D30: lwc1        $f18, 0x6354($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6354);
    // 0x80044D34: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80044D38: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x80044D3C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80044D40: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80044D44: bc1f        L_80044EE0
    if (!c1cs) {
        // 0x80044D48: swc1        $f5, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
            goto L_80044EE0;
    }
    // 0x80044D48: swc1        $f5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x80044D4C: lw          $t6, 0x158($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X158);
    // 0x80044D50: nop

    // 0x80044D54: bne         $t6, $zero, L_80044EE4
    if (ctx->r14 != 0) {
        // 0x80044D58: lui         $at, 0x4049
        ctx->r1 = S32(0X4049 << 16);
            goto L_80044EE4;
    }
    // 0x80044D58: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80044D5C: lbu         $v0, 0x1CD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1CD);
    // 0x80044D60: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80044D64: beq         $v0, $at, L_80044D9C
    if (ctx->r2 == ctx->r1) {
        // 0x80044D68: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80044D9C;
    }
    // 0x80044D68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80044D6C: beq         $v0, $at, L_80044DB8
    if (ctx->r2 == ctx->r1) {
        // 0x80044D70: nop
    
            goto L_80044DB8;
    }
    // 0x80044D70: nop

    // 0x80044D74: lbu         $t9, 0x1CE($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044D78: lb          $a3, 0x2($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X2);
    // 0x80044D7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80044D80: beq         $v0, $at, L_80044E40
    if (ctx->r2 == ctx->r1) {
        // 0x80044D84: sw          $t9, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r25;
            goto L_80044E40;
    }
    // 0x80044D84: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80044D88: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80044D8C: beq         $v0, $at, L_80044E58
    if (ctx->r2 == ctx->r1) {
        // 0x80044D90: nop
    
            goto L_80044E58;
    }
    // 0x80044D90: nop

    // 0x80044D94: b           L_80044E74
    // 0x80044D98: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
        goto L_80044E74;
    // 0x80044D98: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
L_80044D9C:
    // 0x80044D9C: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
    // 0x80044DA0: lbu         $a2, 0x1CE($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044DA4: lb          $a3, 0x2($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X2);
    // 0x80044DA8: jal         0x8001CD28
    // 0x80044DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8001CD28(rdram, ctx);
        goto after_22;
    // 0x80044DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80044DB0: b           L_80044E84
    // 0x80044DB4: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80044E84;
    // 0x80044DB4: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_80044DB8:
    // 0x80044DB8: lb          $a0, 0x1CF($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1CF);
    // 0x80044DBC: jal         0x8001BAC8
    // 0x80044DC0: nop

    get_racer_object(rdram, ctx);
        goto after_23;
    // 0x80044DC0: nop

    after_23:
    // 0x80044DC4: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80044DC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80044DCC: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80044DD0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80044DD4: bne         $t7, $at, L_80044E08
    if (ctx->r15 != ctx->r1) {
        // 0x80044DD8: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80044E08;
    }
    // 0x80044DD8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80044DDC: lw          $t0, 0x154($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X154);
    // 0x80044DE0: lbu         $a0, 0x9($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X9);
    // 0x80044DE4: lw          $t2, 0x3C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X3C);
    // 0x80044DE8: lbu         $a2, 0x1CE($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044DEC: lbu         $a1, 0x9($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X9);
    // 0x80044DF0: lb          $a3, 0x2($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X2);
    // 0x80044DF4: ori         $t4, $a1, 0x100
    ctx->r12 = ctx->r5 | 0X100;
    // 0x80044DF8: jal         0x8001CD28
    // 0x80044DFC: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    func_8001CD28(rdram, ctx);
        goto after_24;
    // 0x80044DFC: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_24:
    // 0x80044E00: b           L_80044E84
    // 0x80044E04: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80044E84;
    // 0x80044E04: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_80044E08:
    // 0x80044E08: lwc1        $f12, 0xC($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80044E0C: lwc1        $f14, 0x10($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80044E10: lw          $a2, 0x14($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X14);
    // 0x80044E14: jal         0x8001C524
    // 0x80044E18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_25;
    // 0x80044E18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_25:
    // 0x80044E1C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80044E20: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80044E24: lb          $a3, 0x2($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X2);
    // 0x80044E28: lbu         $a2, 0x1CE($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044E2C: lbu         $a0, 0x9($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X9);
    // 0x80044E30: jal         0x8001CD28
    // 0x80044E34: ori         $a1, $v0, 0x100
    ctx->r5 = ctx->r2 | 0X100;
    func_8001CD28(rdram, ctx);
        goto after_26;
    // 0x80044E34: ori         $a1, $v0, 0x100
    ctx->r5 = ctx->r2 | 0X100;
    after_26:
    // 0x80044E38: b           L_80044E84
    // 0x80044E3C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80044E84;
    // 0x80044E3C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_80044E40:
    // 0x80044E40: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
    // 0x80044E44: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80044E48: jal         0x8001CD28
    // 0x80044E4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8001CD28(rdram, ctx);
        goto after_27;
    // 0x80044E4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80044E50: b           L_80044E84
    // 0x80044E54: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80044E84;
    // 0x80044E54: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_80044E58:
    // 0x80044E58: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
    // 0x80044E5C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80044E60: jal         0x8001CD28
    // 0x80044E64: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    func_8001CD28(rdram, ctx);
        goto after_28;
    // 0x80044E64: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    after_28:
    // 0x80044E68: b           L_80044E84
    // 0x80044E6C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80044E84;
    // 0x80044E6C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80044E70: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
L_80044E74:
    // 0x80044E74: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80044E78: jal         0x8001CC48
    // 0x80044E7C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    ainode_find_next(rdram, ctx);
        goto after_29;
    // 0x80044E7C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_29:
    // 0x80044E80: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_80044E84:
    // 0x80044E84: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044E88: beq         $v0, $at, L_80044EAC
    if (ctx->r2 == ctx->r1) {
        // 0x80044E8C: nop
    
            goto L_80044EAC;
    }
    // 0x80044E8C: nop

    // 0x80044E90: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80044E94: jal         0x8001D214
    // 0x80044E98: nop

    ainode_get(rdram, ctx);
        goto after_30;
    // 0x80044E98: nop

    after_30:
    // 0x80044E9C: sw          $v0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->r2;
    // 0x80044EA0: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80044EA4: b           L_80044EE4
    // 0x80044EA8: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
        goto L_80044EE4;
    // 0x80044EA8: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
L_80044EAC:
    // 0x80044EAC: lbu         $a0, 0x1CE($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044EB0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044EB4: beq         $a0, $at, L_80044ED4
    if (ctx->r4 == ctx->r1) {
        // 0x80044EB8: nop
    
            goto L_80044ED4;
    }
    // 0x80044EB8: nop

    // 0x80044EBC: jal         0x8001D214
    // 0x80044EC0: nop

    ainode_get(rdram, ctx);
        goto after_31;
    // 0x80044EC0: nop

    after_31:
    // 0x80044EC4: sw          $v0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->r2;
    // 0x80044EC8: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80044ECC: b           L_80044EE4
    // 0x80044ED0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
        goto L_80044EE4;
    // 0x80044ED0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
L_80044ED4:
    // 0x80044ED4: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
    // 0x80044ED8: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80044EDC: nop

L_80044EE0:
    // 0x80044EE0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
L_80044EE4:
    // 0x80044EE4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80044EE8: lwc1        $f9, 0x20($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80044EEC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80044EF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80044EF4: lui         $at, 0x4074
    ctx->r1 = S32(0X4074 << 16);
    // 0x80044EF8: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80044EFC: nop

    // 0x80044F00: bc1t        L_80044F34
    if (c1cs) {
        // 0x80044F04: nop
    
            goto L_80044F34;
    }
    // 0x80044F04: nop

    // 0x80044F08: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80044F0C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80044F10: nop

    // 0x80044F14: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80044F18: nop

    // 0x80044F1C: bc1f        L_80044FA4
    if (!c1cs) {
        // 0x80044F20: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80044FA4;
    }
    // 0x80044F20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80044F24: lw          $t6, 0x158($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X158);
    // 0x80044F28: nop

    // 0x80044F2C: beq         $t6, $zero, L_80044FA4
    if (ctx->r14 == 0) {
        // 0x80044F30: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80044FA4;
    }
    // 0x80044F30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80044F34:
    // 0x80044F34: lbu         $t9, 0x9($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X9);
    // 0x80044F38: lw          $v0, 0x158($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X158);
    // 0x80044F3C: sb          $t9, 0x1CE($s0)
    MEM_B(0X1CE, ctx->r16) = ctx->r25;
    // 0x80044F40: bne         $v0, $zero, L_80044F4C
    if (ctx->r2 != 0) {
        // 0x80044F44: sw          $v0, 0x154($s0)
        MEM_W(0X154, ctx->r16) = ctx->r2;
            goto L_80044F4C;
    }
    // 0x80044F44: sw          $v0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r2;
    // 0x80044F48: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
L_80044F4C:
    // 0x80044F4C: b           L_80044FA0
    // 0x80044F50: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
        goto L_80044FA0;
    // 0x80044F50: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
L_80044F54:
    // 0x80044F54: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80044F58: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80044F5C: lwc1        $f12, 0xC($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80044F60: lwc1        $f14, 0x10($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80044F64: lw          $a2, 0x14($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X14);
    // 0x80044F68: jal         0x8001C524
    // 0x80044F6C: nop

    ainode_find_nearest(rdram, ctx);
        goto after_32;
    // 0x80044F6C: nop

    after_32:
    // 0x80044F70: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044F78: beq         $v0, $at, L_80044F9C
    if (ctx->r2 == ctx->r1) {
        // 0x80044F7C: sw          $v0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r2;
            goto L_80044F9C;
    }
    // 0x80044F7C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80044F80: jal         0x8001D214
    // 0x80044F84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    ainode_get(rdram, ctx);
        goto after_33;
    // 0x80044F84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_33:
    // 0x80044F88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044F8C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80044F90: sw          $v0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r2;
    // 0x80044F94: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
    // 0x80044F98: sb          $t8, 0x1CE($s0)
    MEM_B(0X1CE, ctx->r16) = ctx->r24;
L_80044F9C:
    // 0x80044F9C: sb          $a1, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r5;
L_80044FA0:
    // 0x80044FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80044FA4:
    // 0x80044FA4: lb          $t4, 0x2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X2);
    // 0x80044FA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80044FAC: beq         $a1, $t4, L_80045100
    if (ctx->r5 == ctx->r12) {
        // 0x80044FB0: nop
    
            goto L_80045100;
    }
    // 0x80044FB0: nop

    // 0x80044FB4: jal         0x8001BAC8
    // 0x80044FB8: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    get_racer_object(rdram, ctx);
        goto after_34;
    // 0x80044FB8: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    after_34:
    // 0x80044FBC: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80044FC0: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    // 0x80044FC4: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80044FC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80044FCC: beq         $t5, $at, L_80044FE4
    if (ctx->r13 == ctx->r1) {
        // 0x80044FD0: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80044FE4;
    }
    // 0x80044FD0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80044FD4: lb          $t6, 0x212($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X212);
    // 0x80044FD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044FDC: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80044FE0: sb          $t6, -0x2A4C($at)
    MEM_B(-0X2A4C, ctx->r1) = ctx->r14;
L_80044FE4:
    // 0x80044FE4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80044FE8: lb          $t9, 0x2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X2);
    // 0x80044FEC: addiu       $t7, $t7, -0x2A4C
    ctx->r15 = ADD32(ctx->r15, -0X2A4C);
    // 0x80044FF0: addu        $t5, $a1, $t7
    ctx->r13 = ADD32(ctx->r5, ctx->r15);
    // 0x80044FF4: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80044FF8: lb          $t4, 0x0($t8)
    ctx->r12 = MEM_B(ctx->r24, 0X0);
    // 0x80044FFC: lb          $t6, 0x0($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X0);
    // 0x80045000: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80045004: bne         $t4, $t6, L_80045100
    if (ctx->r12 != ctx->r14) {
        // 0x80045008: nop
    
            goto L_80045100;
    }
    // 0x80045008: nop

    // 0x8004500C: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80045010: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80045014: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80045018: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8004501C: lwc1        $f6, 0x14($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80045020: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80045024: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80045028: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8004502C: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80045030: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80045034: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    // 0x80045038: jal         0x800C9AD0
    // 0x8004503C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_35;
    // 0x8004503C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_35:
    // 0x80045040: lui         $at, 0x4089
    ctx->r1 = S32(0X4089 << 16);
    // 0x80045044: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80045048: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004504C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80045050: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x80045054: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    // 0x80045058: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8004505C: bc1f        L_80045100
    if (!c1cs) {
        // 0x80045060: nop
    
            goto L_80045100;
    }
    // 0x80045060: nop

    // 0x80045064: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80045068: jal         0x80070750
    // 0x8004506C: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_36;
    // 0x8004506C: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    after_36:
    // 0x80045070: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80045074: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80045078: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x8004507C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80045080: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80045084: subu        $t5, $v0, $t7
    ctx->r13 = SUB32(ctx->r2, ctx->r15);
    // 0x80045088: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    // 0x8004508C: slt         $at, $t5, $at
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80045090: bne         $at, $zero, L_800450A4
    if (ctx->r1 != 0) {
        // 0x80045094: sw          $t5, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r13;
            goto L_800450A4;
    }
    // 0x80045094: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x80045098: lui         $t6, 0xFFFF
    ctx->r14 = S32(0XFFFF << 16);
    // 0x8004509C: ori         $t6, $t6, 0x1
    ctx->r14 = ctx->r14 | 0X1;
    // 0x800450A0: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_800450A4:
    // 0x800450A4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800450A8: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x800450AC: slti        $at, $t9, -0x8000
    ctx->r1 = SIGNED(ctx->r25) < -0X8000 ? 1 : 0;
    // 0x800450B0: beq         $at, $zero, L_800450BC
    if (ctx->r1 == 0) {
        // 0x800450B4: addiu       $v1, $zero, 0x800
        ctx->r3 = ADD32(0, 0X800);
            goto L_800450BC;
    }
    // 0x800450B4: addiu       $v1, $zero, 0x800
    ctx->r3 = ADD32(0, 0X800);
    // 0x800450B8: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
L_800450BC:
    // 0x800450BC: lb          $t7, 0x174($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X174);
    // 0x800450C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800450C4: bne         $t7, $at, L_800450D4
    if (ctx->r15 != ctx->r1) {
        // 0x800450C8: nop
    
            goto L_800450D4;
    }
    // 0x800450C8: nop

    // 0x800450CC: b           L_800450D4
    // 0x800450D0: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
        goto L_800450D4;
    // 0x800450D0: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
L_800450D4:
    // 0x800450D4: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800450D8: negu        $t5, $v1
    ctx->r13 = SUB32(0, ctx->r3);
    // 0x800450DC: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800450E0: beq         $at, $zero, L_80045100
    if (ctx->r1 == 0) {
        // 0x800450E4: slt         $at, $t4, $v1
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80045100;
    }
    // 0x800450E4: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800450E8: beq         $at, $zero, L_80045100
    if (ctx->r1 == 0) {
        // 0x800450EC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80045100;
    }
    // 0x800450EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800450F0: lw          $t6, -0x2AD0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AD0);
    // 0x800450F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800450F8: ori         $t9, $t6, 0x2000
    ctx->r25 = ctx->r14 | 0X2000;
    // 0x800450FC: sw          $t9, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = ctx->r25;
L_80045100:
    // 0x80045100: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80045104: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80045108: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004510C: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80045110: bne         $at, $zero, L_80044FA4
    if (ctx->r1 != 0) {
        // 0x80045114: nop
    
            goto L_80044FA4;
    }
    // 0x80045114: nop

    // 0x80045118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004511C:
    // 0x8004511C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80045120: jr          $ra
    // 0x80045124: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80045124: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void thread3_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C338: jal         0x8006C3E0
    // 0x8006C33C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    init_game(rdram, ctx);
        goto after_0;
    // 0x8006C33C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006C340: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C344: lw          $a0, -0x2C84($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2C84);
    // 0x8006C348: jal         0x8006A1C4
    // 0x8006C34C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    input_update(rdram, ctx);
        goto after_1;
    // 0x8006C34C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8006C350: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C354: sw          $v0, -0x2C84($at)
    MEM_W(-0X2C84, ctx->r1) = ctx->r2;
    // 0x8006C358: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C35C: sw          $zero, 0x3520($at)
    MEM_W(0X3520, ctx->r1) = 0;
    // 0x8006C360: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C364: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8006C368: sw          $t6, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = ctx->r14;
L_8006C36C:
    // 0x8006C36C: jal         0x8006EAC0
    // 0x8006C370: nop

    is_reset_pressed(rdram, ctx);
        goto after_2;
    // 0x8006C370: nop

    after_2:
    // 0x8006C374: beq         $v0, $zero, L_8006C3B0
    if (ctx->r2 == 0) {
        // 0x8006C378: nop
    
            goto L_8006C3B0;
    }
    // 0x8006C378: nop

    // 0x8006C37C: jal         0x80072708
    // 0x8006C380: nop

    rumble_kill(rdram, ctx);
        goto after_3;
    // 0x8006C380: nop

    after_3:
    // 0x8006C384: jal         0x80002A74
    // 0x8006C388: nop

    audioStopThread(rdram, ctx);
        goto after_4;
    // 0x8006C388: nop

    after_4:
    // 0x8006C38C: jal         0x800C73BC
    // 0x8006C390: nop

    bgload_kill(rdram, ctx);
        goto after_5;
    // 0x8006C390: nop

    after_5:
    // 0x8006C394: lui         $a0, 0xAA
    ctx->r4 = S32(0XAA << 16);
    // 0x8006C398: jal         0x800CD240
    // 0x8006C39C: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    __osSpSetStatus_recomp(rdram, ctx);
        goto after_6;
    // 0x8006C39C: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    after_6:
    // 0x8006C3A0: jal         0x800CD250
    // 0x8006C3A4: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_7;
    // 0x8006C3A4: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    after_7:
L_8006C3A8:
    // 0x8006C3A8: b           L_8006C3A8
    pause_self(rdram);
    // 0x8006C3AC: nop

L_8006C3B0:
    extern int dkr_netplay_drive_authored_tick(uint8_t*, recomp_context*); if (dkr_netplay_drive_authored_tick(rdram, ctx)) { goto after_8; }
    // 0x8006C3B0: jal         0x8006C60C
    // 0x8006C3B4: nop

    main_game_loop(rdram, ctx);
        goto after_8;
    // 0x8006C3B4: nop

    after_8:
    // 0x8006C3B8: jal         0x80065E30
    // 0x8006C3BC: nop

    thread3_verify_stack(rdram, ctx);
        goto after_9;
    // 0x8006C3BC: nop

    after_9:
    // 0x8006C3C0: b           L_8006C36C
    // 0x8006C3C4: nop

        goto L_8006C36C;
    // 0x8006C3C4: nop

    // 0x8006C3C8: nop

    // 0x8006C3CC: nop

    // 0x8006C3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C3D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C3D8: jr          $ra
    // 0x8006C3DC: nop

    return;
    // 0x8006C3DC: nop

;}
RECOMP_FUNC void alEnvmixerNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80064E58: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80064E5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80064E60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80064E64: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80064E68: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80064E6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80064E70: addiu       $a2, $a2, -0x5584
    ctx->r6 = ADD32(ctx->r6, -0X5584);
    // 0x80064E74: addiu       $a1, $a1, -0x5F30
    ctx->r5 = ADD32(ctx->r5, -0X5F30);
    // 0x80064E78: jal         0x800CA0B0
    // 0x80064E7C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80064E7C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x80064E80: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80064E84: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80064E88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80064E8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064E90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80064E94: jal         0x800C77F0
    // 0x80064E98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80064E98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80064E9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80064EA0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80064EA4: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x80064EA8: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x80064EAC: sh          $v1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r3;
    // 0x80064EB0: sh          $v1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r3;
    // 0x80064EB4: sh          $v1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r3;
    // 0x80064EB8: sh          $v1, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r3;
    // 0x80064EBC: sh          $v1, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r3;
    // 0x80064EC0: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x80064EC4: sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
    // 0x80064EC8: sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    // 0x80064ECC: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    // 0x80064ED0: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80064ED4: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80064ED8: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x80064EDC: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80064EE0: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80064EE4: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80064EE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80064EEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80064EF0: jr          $ra
    // 0x80064EF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80064EF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mode_lockup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B77D4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B77D8: addiu       $v0, $v0, 0x3028
    ctx->r2 = ADD32(ctx->r2, 0X3028);
    // 0x800B77DC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B77E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B77E4: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800B77E8: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x800B77EC: bne         $at, $zero, L_800B7808
    if (ctx->r1 != 0) {
        // 0x800B77F0: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_800B7808;
    }
    // 0x800B77F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B77F4: addiu       $v1, $v1, 0x3024
    ctx->r3 = ADD32(ctx->r3, 0X3024);
    // 0x800B77F8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800B77FC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B7800: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B7804: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800B7808:
    // 0x800B7808: jr          $ra
    // 0x800B780C: nop

    return;
    // 0x800B780C: nop

;}
RECOMP_FUNC void obj_init_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038D60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038D64: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038D68: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80038D6C: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038D70: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80038D74: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80038D78: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80038D7C: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80038D80: nop

    // 0x80038D84: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80038D88: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038D8C: nop

    // 0x80038D90: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x80038D94: jal         0x8006EA90
    // 0x80038D98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80038D98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038D9C: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x80038DA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038DA4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80038DA8: beq         $t3, $zero, L_80038DB4
    if (ctx->r11 == 0) {
        // 0x80038DAC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80038DB4;
    }
    // 0x80038DAC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80038DB0: sw          $t4, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r12;
L_80038DB4:
    // 0x80038DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038DBC: jr          $ra
    // 0x80038DC0: nop

    return;
    // 0x80038DC0: nop

;}
RECOMP_FUNC void add_shading_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D2A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D2A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D2A8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001D2AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001D2B0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001D2B4: lw          $s0, 0x54($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X54);
    // 0x8001D2B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D2BC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D2C0: beq         $s0, $zero, L_8001D4A0
    if (ctx->r16 == 0) {
        // 0x8001D2C4: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_8001D4A0;
    }
    // 0x8001D2C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001D2C8: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8001D2CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001D2D0: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8001D2D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D2D8: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x8001D2DC: lw          $s0, 0x54($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X54);
    // 0x8001D2E0: nop

    // 0x8001D2E4: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8001D2E8: nop

    // 0x8001D2EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001D2F0: nop

    // 0x8001D2F4: bc1f        L_8001D30C
    if (!c1cs) {
        // 0x8001D2F8: nop
    
            goto L_8001D30C;
    }
    // 0x8001D2F8: nop

    // 0x8001D2FC: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x8001D300: lw          $s0, 0x54($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X54);
    // 0x8001D304: b           L_8001D334
    // 0x8001D308: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
        goto L_8001D334;
    // 0x8001D308: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
L_8001D30C:
    // 0x8001D30C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001D310: nop

    // 0x8001D314: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001D318: nop

    // 0x8001D31C: bc1f        L_8001D330
    if (!c1cs) {
        // 0x8001D320: nop
    
            goto L_8001D330;
    }
    // 0x8001D320: nop

    // 0x8001D324: swc1        $f12, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f12.u32l;
    // 0x8001D328: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D32C: nop

L_8001D330:
    // 0x8001D330: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
L_8001D334:
    // 0x8001D334: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001D338: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8001D33C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001D340: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x8001D344: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D348: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001D34C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8001D350: nop

    // 0x8001D354: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001D358: nop

    // 0x8001D35C: bc1f        L_8001D378
    if (!c1cs) {
        // 0x8001D360: nop
    
            goto L_8001D378;
    }
    // 0x8001D360: nop

    // 0x8001D364: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8001D368: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D36C: nop

    // 0x8001D370: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8001D374: nop

L_8001D378:
    // 0x8001D378: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8001D37C: nop

    // 0x8001D380: bc1f        L_8001D3A4
    if (!c1cs) {
        // 0x8001D384: nop
    
            goto L_8001D3A4;
    }
    // 0x8001D384: nop

    // 0x8001D388: lwc1        $f18, 0x5660($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5660);
    // 0x8001D38C: nop

    // 0x8001D390: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8001D394: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D398: nop

    // 0x8001D39C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8001D3A0: nop

L_8001D3A4:
    // 0x8001D3A4: lh          $t0, 0x24($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X24);
    // 0x8001D3A8: lh          $t1, 0x3A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3A);
    // 0x8001D3AC: lh          $t6, 0x22($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X22);
    // 0x8001D3B0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x8001D3B4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001D3B8: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x8001D3BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001D3C0: lh          $t3, 0x26($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X26);
    // 0x8001D3C4: lh          $t4, 0x3E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3E);
    // 0x8001D3C8: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x8001D3CC: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x8001D3D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001D3D4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8001D3D8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8001D3DC: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001D3E0: jal         0x8001D4B4
    // 0x8001D3E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_shading_properties(rdram, ctx);
        goto after_0;
    // 0x8001D3E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8001D3E8: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x8001D3EC: nop

    // 0x8001D3F0: lbu         $t6, 0x3D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3D);
    // 0x8001D3F4: nop

    // 0x8001D3F8: beq         $t6, $zero, L_8001D4A4
    if (ctx->r14 == 0) {
        // 0x8001D3FC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001D4A4;
    }
    // 0x8001D3FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D400: lbu         $t7, 0x3A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3A);
    // 0x8001D404: lw          $t8, 0x54($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X54);
    // 0x8001D408: nop

    // 0x8001D40C: sb          $t7, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r15;
    // 0x8001D410: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x8001D414: lw          $t1, 0x54($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X54);
    // 0x8001D418: lbu         $t0, 0x3B($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X3B);
    // 0x8001D41C: nop

    // 0x8001D420: sb          $t0, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r8;
    // 0x8001D424: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x8001D428: lw          $t4, 0x54($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X54);
    // 0x8001D42C: lbu         $t3, 0x3C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3C);
    // 0x8001D430: nop

    // 0x8001D434: sb          $t3, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r11;
    // 0x8001D438: lw          $t5, 0x40($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X40);
    // 0x8001D43C: lw          $t7, 0x54($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X54);
    // 0x8001D440: lbu         $t6, 0x3D($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X3D);
    // 0x8001D444: nop

    // 0x8001D448: sb          $t6, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r14;
    // 0x8001D44C: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D450: nop

    // 0x8001D454: lh          $t8, 0x1C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1C);
    // 0x8001D458: nop

    // 0x8001D45C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8001D460: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8001D464: sh          $t0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r8;
    // 0x8001D468: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D46C: nop

    // 0x8001D470: lh          $t1, 0x1E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1E);
    // 0x8001D474: nop

    // 0x8001D478: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8001D47C: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8001D480: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x8001D484: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D488: nop

    // 0x8001D48C: lh          $t4, 0x20($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X20);
    // 0x8001D490: nop

    // 0x8001D494: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8001D498: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x8001D49C: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
L_8001D4A0:
    // 0x8001D4A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D4A4:
    // 0x8001D4A4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D4A8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001D4AC: jr          $ra
    // 0x8001D4B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001D4B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mempool_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071314: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80071318: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007131C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80071320: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80071324: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80071328: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007132C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80071330: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80071334: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071338: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007133C: jal         0x8006F510
    // 0x80071340: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071340: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80071344: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80071348: lw          $s2, 0x35C0($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X35C0);
    // 0x8007134C: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80071350: beq         $s2, $s6, L_80071404
    if (ctx->r18 == ctx->r22) {
        // 0x80071354: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_80071404;
    }
    // 0x80071354: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80071358: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007135C: addiu       $t7, $t7, 0x3580
    ctx->r15 = ADD32(ctx->r15, 0X3580);
    // 0x80071360: sll         $t6, $s2, 4
    ctx->r14 = S32(ctx->r18 << 4);
    // 0x80071364: addu        $s5, $t6, $t7
    ctx->r21 = ADD32(ctx->r14, ctx->r15);
    // 0x80071368: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8007136C: addiu       $s7, $zero, 0x14
    ctx->r23 = ADD32(0, 0X14);
    // 0x80071370: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80071374:
    // 0x80071374: lw          $s4, 0x8($s5)
    ctx->r20 = MEM_W(ctx->r21, 0X8);
    // 0x80071378: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007137C:
    // 0x8007137C: multu       $s0, $s7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071380: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80071384: mflo        $t8
    ctx->r24 = lo;
    // 0x80071388: addu        $s1, $t8, $s4
    ctx->r17 = ADD32(ctx->r24, ctx->r20);
    // 0x8007138C: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x80071390: nop

    // 0x80071394: bne         $s3, $v0, L_800713AC
    if (ctx->r19 != ctx->r2) {
        // 0x80071398: nop
    
            goto L_800713AC;
    }
    // 0x80071398: nop

    // 0x8007139C: jal         0x8007164C
    // 0x800713A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_slot_clear(rdram, ctx);
        goto after_1;
    // 0x800713A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800713A4: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x800713A8: nop

L_800713AC:
    // 0x800713AC: bne         $fp, $v0, L_800713E8
    if (ctx->r30 != ctx->r2) {
        // 0x800713B0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800713E8;
    }
    // 0x800713B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800713B4: lw          $t9, 0x4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X4);
    // 0x800713B8: nop

    // 0x800713BC: bne         $s3, $t9, L_800713D4
    if (ctx->r19 != ctx->r25) {
        // 0x800713C0: nop
    
            goto L_800713D4;
    }
    // 0x800713C0: nop

    // 0x800713C4: jal         0x8007164C
    // 0x800713C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_slot_clear(rdram, ctx);
        goto after_2;
    // 0x800713C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800713CC: b           L_800713EC
    // 0x800713D0: lh          $s0, 0xC($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XC);
        goto L_800713EC;
    // 0x800713D0: lh          $s0, 0xC($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XC);
L_800713D4:
    // 0x800713D4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800713D8: jal         0x8006F53C
    // 0x800713DC: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x800713DC: nop

    after_3:
    // 0x800713E0: b           L_80071414
    // 0x800713E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80071414;
    // 0x800713E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800713E8:
    // 0x800713E8: lh          $s0, 0xC($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XC);
L_800713EC:
    // 0x800713EC: nop

    // 0x800713F0: bne         $s0, $s6, L_8007137C
    if (ctx->r16 != ctx->r22) {
        // 0x800713F4: nop
    
            goto L_8007137C;
    }
    // 0x800713F4: nop

    // 0x800713F8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800713FC: bne         $s2, $s6, L_80071374
    if (ctx->r18 != ctx->r22) {
        // 0x80071400: addiu       $s5, $s5, -0x10
        ctx->r21 = ADD32(ctx->r21, -0X10);
            goto L_80071374;
    }
    // 0x80071400: addiu       $s5, $s5, -0x10
    ctx->r21 = ADD32(ctx->r21, -0X10);
L_80071404:
    // 0x80071404: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80071408: jal         0x8006F53C
    // 0x8007140C: nop

    interrupts_enable(rdram, ctx);
        goto after_4;
    // 0x8007140C: nop

    after_4:
    // 0x80071410: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80071414:
    // 0x80071414: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071418: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007141C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071420: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80071424: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80071428: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007142C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80071430: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80071434: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80071438: jr          $ra
    // 0x8007143C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007143C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void racer_attack_handler_plane(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C140: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004C144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004C148: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004C14C: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8004C150: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C154: bne         $t6, $at, L_8004C164
    if (ctx->r14 != ctx->r1) {
        // 0x8004C158: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_8004C164;
    }
    // 0x8004C158: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8004C15C: b           L_8004C16C
    // 0x8004C160: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8004C16C;
    // 0x8004C160: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004C164:
    // 0x8004C164: lb          $v1, 0x185($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X185);
    // 0x8004C168: nop

L_8004C16C:
    // 0x8004C16C: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
    // 0x8004C170: nop

    // 0x8004C174: beq         $v0, $zero, L_8004C18C
    if (ctx->r2 == 0) {
        // 0x8004C178: nop
    
            goto L_8004C18C;
    }
    // 0x8004C178: nop

    // 0x8004C17C: lh          $t7, 0x18E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18E);
    // 0x8004C180: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004C184: blez        $t7, L_8004C194
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8004C188: nop
    
            goto L_8004C194;
    }
    // 0x8004C188: nop

L_8004C18C:
    // 0x8004C18C: b           L_8004C2A0
    // 0x8004C190: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
        goto L_8004C2A0;
    // 0x8004C190: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_8004C194:
    // 0x8004C194: beq         $v0, $at, L_8004C1B8
    if (ctx->r2 == ctx->r1) {
        // 0x8004C198: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8004C1B8;
    }
    // 0x8004C198: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004C19C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004C1A0: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    // 0x8004C1A4: jal         0x800576E0
    // 0x8004C1A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    drop_bananas(rdram, ctx);
        goto after_0;
    // 0x8004C1A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004C1AC: lb          $v1, 0x27($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X27);
    // 0x8004C1B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004C1B4: nop

L_8004C1B8:
    // 0x8004C1B8: lbu         $t9, 0x1C9($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1C9);
    // 0x8004C1BC: addiu       $t8, $zero, 0x168
    ctx->r24 = ADD32(0, 0X168);
    // 0x8004C1C0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004C1C4: bne         $t9, $at, L_8004C1D0
    if (ctx->r25 != ctx->r1) {
        // 0x8004C1C8: sh          $t8, 0x18C($s0)
        MEM_H(0X18C, ctx->r16) = ctx->r24;
            goto L_8004C1D0;
    }
    // 0x8004C1C8: sh          $t8, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r24;
    // 0x8004C1CC: sb          $zero, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = 0;
L_8004C1D0:
    // 0x8004C1D0: lb          $t0, 0x1D6($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004C1D4: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x8004C1D8: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8004C1DC: beq         $at, $zero, L_8004C2A0
    if (ctx->r1 == 0) {
        // 0x8004C1E0: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_8004C2A0;
    }
    // 0x8004C1E0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8004C1E4: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x8004C1E8: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    // 0x8004C1EC: jal         0x800570B8
    // 0x8004C1F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    play_random_character_voice(rdram, ctx);
        goto after_1;
    // 0x8004C1F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x8004C1F4: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
    // 0x8004C1F8: lb          $v1, 0x27($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X27);
    // 0x8004C1FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004C200: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C204: beq         $v0, $at, L_8004C22C
    if (ctx->r2 == ctx->r1) {
        // 0x8004C208: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004C22C;
    }
    // 0x8004C208: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004C20C: beq         $v0, $at, L_8004C22C
    if (ctx->r2 == ctx->r1) {
        // 0x8004C210: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004C22C;
    }
    // 0x8004C210: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004C214: beq         $v0, $at, L_8004C248
    if (ctx->r2 == ctx->r1) {
        // 0x8004C218: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8004C248;
    }
    // 0x8004C218: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004C21C: beq         $v0, $at, L_8004C264
    if (ctx->r2 == ctx->r1) {
        // 0x8004C220: addiu       $t5, $zero, 0x78
        ctx->r13 = ADD32(0, 0X78);
            goto L_8004C264;
    }
    // 0x8004C220: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x8004C224: b           L_8004C2A0
    // 0x8004C228: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
        goto L_8004C2A0;
    // 0x8004C228: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_8004C22C:
    // 0x8004C22C: beq         $v1, $zero, L_8004C240
    if (ctx->r3 == 0) {
        // 0x8004C230: addiu       $t2, $zero, 0x3C
        ctx->r10 = ADD32(0, 0X3C);
            goto L_8004C240;
    }
    // 0x8004C230: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8004C234: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8004C238: b           L_8004C29C
    // 0x8004C23C: sb          $t1, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r9;
        goto L_8004C29C;
    // 0x8004C23C: sb          $t1, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r9;
L_8004C240:
    // 0x8004C240: b           L_8004C29C
    // 0x8004C244: sb          $t2, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r10;
        goto L_8004C29C;
    // 0x8004C244: sb          $t2, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r10;
L_8004C248:
    // 0x8004C248: beq         $v1, $zero, L_8004C25C
    if (ctx->r3 == 0) {
        // 0x8004C24C: addiu       $t4, $zero, 0x3C
        ctx->r12 = ADD32(0, 0X3C);
            goto L_8004C25C;
    }
    // 0x8004C24C: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x8004C250: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x8004C254: b           L_8004C29C
    // 0x8004C258: sb          $t3, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r11;
        goto L_8004C29C;
    // 0x8004C258: sb          $t3, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r11;
L_8004C25C:
    // 0x8004C25C: b           L_8004C29C
    // 0x8004C260: sb          $t4, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r12;
        goto L_8004C29C;
    // 0x8004C260: sb          $t4, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r12;
L_8004C264:
    // 0x8004C264: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004C268: lwc1        $f1, 0x6550($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6550);
    // 0x8004C26C: lwc1        $f0, 0x6554($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6554);
    // 0x8004C270: sh          $t5, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r13;
    // 0x8004C274: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8004C278: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8004C27C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8004C280: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8004C284: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8004C288: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8004C28C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8004C290: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x8004C294: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004C298: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
L_8004C29C:
    // 0x8004C29C: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_8004C2A0:
    // 0x8004C2A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004C2A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004C2A8: jr          $ra
    // 0x8004C2AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004C2AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_init_wizpigship(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80037D70: jr          $ra
    // 0x80037D74: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80037D74: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_8001F460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F460: addiu       $sp, $sp, -0x198
    ctx->r29 = ADD32(ctx->r29, -0X198);
    // 0x8001F464: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001F468: lh          $t6, -0x5186($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X5186);
    // 0x8001F46C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8001F470: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001F474: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8001F478: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8001F47C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8001F480: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8001F484: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001F488: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001F48C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001F490: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001F494: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001F498: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x8001F49C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001F4A0: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8001F4A4: bgez        $t6, L_8001F4B4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001F4A8: sw          $a1, 0x19C($sp)
        MEM_W(0X19C, ctx->r29) = ctx->r5;
            goto L_8001F4B4;
    }
    // 0x8001F4A8: sw          $a1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r5;
    // 0x8001F4AC: b           L_80021094
    // 0x8001F4B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80021094;
    // 0x8001F4B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001F4B4:
    // 0x8001F4B4: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F4B8: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8001F4BC: slti        $at, $t7, 0x9
    ctx->r1 = SIGNED(ctx->r15) < 0X9 ? 1 : 0;
    // 0x8001F4C0: bne         $at, $zero, L_8001F4CC
    if (ctx->r1 != 0) {
        // 0x8001F4C4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8001F4CC;
    }
    // 0x8001F4C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001F4C8: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
L_8001F4CC:
    // 0x8001F4CC: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F4D0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8001F4D4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8001F4D8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8001F4DC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F4E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001F4E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F4E8: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    // 0x8001F4EC: lw          $s3, 0x64($s6)
    ctx->r19 = MEM_W(ctx->r22, 0X64);
    // 0x8001F4F0: bne         $t6, $zero, L_8001F510
    if (ctx->r14 != 0) {
        // 0x8001F4F4: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_8001F510;
    }
    // 0x8001F4F4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8001F4F8: lwc1        $f9, 0x5670($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5670);
    // 0x8001F4FC: lwc1        $f8, 0x5674($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5674);
    // 0x8001F500: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8001F504: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8001F508: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8001F50C: swc1        $f4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f4.u32l;
L_8001F510:
    // 0x8001F510: lh          $t7, 0x2A($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F514: nop

    // 0x8001F518: bgez        $t7, L_8001F580
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8001F51C: nop
    
            goto L_8001F580;
    }
    // 0x8001F51C: nop

    // 0x8001F520: lbu         $v0, 0x34($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X34);
    // 0x8001F524: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001F528: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8001F52C: beq         $t8, $zero, L_8001F538
    if (ctx->r24 == 0) {
        // 0x8001F530: andi        $t9, $v0, 0x2
        ctx->r25 = ctx->r2 & 0X2;
            goto L_8001F538;
    }
    // 0x8001F530: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x8001F534: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
L_8001F538:
    // 0x8001F538: beq         $t9, $zero, L_8001F548
    if (ctx->r25 == 0) {
        // 0x8001F53C: andi        $t7, $v0, 0x4
        ctx->r15 = ctx->r2 & 0X4;
            goto L_8001F548;
    }
    // 0x8001F53C: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8001F540: ori         $t6, $t0, 0x4000
    ctx->r14 = ctx->r8 | 0X4000;
    // 0x8001F544: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_8001F548:
    // 0x8001F548: beq         $t7, $zero, L_8001F554
    if (ctx->r15 == 0) {
        // 0x8001F54C: ori         $t8, $t0, 0x1000
        ctx->r24 = ctx->r8 | 0X1000;
            goto L_8001F554;
    }
    // 0x8001F54C: ori         $t8, $t0, 0x1000
    ctx->r24 = ctx->r8 | 0X1000;
    // 0x8001F550: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_8001F554:
    // 0x8001F554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001F558: jal         0x8006A554
    // 0x8001F55C: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8001F55C: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    after_0:
    // 0x8001F560: lw          $t0, 0x174($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X174);
    // 0x8001F564: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001F568: bne         $s0, $s1, L_8001F554
    if (ctx->r16 != ctx->r17) {
        // 0x8001F56C: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_8001F554;
    }
    // 0x8001F56C: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x8001F570: and         $t9, $s2, $t0
    ctx->r25 = ctx->r18 & ctx->r8;
    // 0x8001F574: beq         $t9, $zero, L_8001F580
    if (ctx->r25 == 0) {
        // 0x8001F578: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8001F580;
    }
    // 0x8001F578: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F57C: sh          $t6, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = ctx->r14;
L_8001F580:
    // 0x8001F580: lh          $v0, 0x2A($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F584: nop

    // 0x8001F588: bltz        $v0, L_8001F5EC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001F58C: nop
    
            goto L_8001F5EC;
    }
    // 0x8001F58C: nop

    // 0x8001F590: lb          $t7, 0x45($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X45);
    // 0x8001F594: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F598: bne         $t7, $zero, L_8001F5EC
    if (ctx->r15 != 0) {
        // 0x8001F59C: subu        $t9, $v0, $t8
        ctx->r25 = SUB32(ctx->r2, ctx->r24);
            goto L_8001F5EC;
    }
    // 0x8001F59C: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x8001F5A0: sh          $t9, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = ctx->r25;
    // 0x8001F5A4: lh          $v0, 0x2A($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F5A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F5AC: bgtz        $v0, L_8001F5EC
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001F5B0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8001F5EC;
    }
    // 0x8001F5B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001F5B4: lw          $t7, 0x1C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X1C);
    // 0x8001F5B8: sb          $t6, 0x45($s3)
    MEM_B(0X45, ctx->r19) = ctx->r14;
    // 0x8001F5BC: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x8001F5C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8001F5C4: jal         0x80021104
    // 0x8001F5C8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80021104(rdram, ctx);
        goto after_1;
    // 0x8001F5C8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x8001F5CC: sh          $zero, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = 0;
    // 0x8001F5D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001F5D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001F5D8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8001F5DC: jal         0x8002125C
    // 0x8001F5E0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    func_8002125C(rdram, ctx);
        goto after_2;
    // 0x8001F5E0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_2:
    // 0x8001F5E4: lh          $v0, 0x2A($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F5E8: nop

L_8001F5EC:
    // 0x8001F5EC: beq         $v0, $zero, L_8001F624
    if (ctx->r2 == 0) {
        // 0x8001F5F0: nop
    
            goto L_8001F624;
    }
    // 0x8001F5F0: nop

    // 0x8001F5F4: lb          $t8, 0x3A($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X3A);
    // 0x8001F5F8: nop

    // 0x8001F5FC: beq         $t8, $zero, L_8001F61C
    if (ctx->r24 == 0) {
        // 0x8001F600: nop
    
            goto L_8001F61C;
    }
    // 0x8001F600: nop

    // 0x8001F604: lh          $t9, 0x6($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X6);
    // 0x8001F608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001F60C: ori         $t6, $t9, 0x4000
    ctx->r14 = ctx->r25 | 0X4000;
    // 0x8001F610: sh          $t6, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r14;
    // 0x8001F614: b           L_80021094
    // 0x8001F618: sb          $zero, 0x42($s3)
    MEM_B(0X42, ctx->r19) = 0;
        goto L_80021094;
    // 0x8001F618: sb          $zero, 0x42($s3)
    MEM_B(0X42, ctx->r19) = 0;
L_8001F61C:
    // 0x8001F61C: b           L_80021094
    // 0x8001F620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021094;
    // 0x8001F620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F624:
    // 0x8001F624: lh          $t7, 0x6($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X6);
    // 0x8001F628: addiu       $s0, $zero, -0x4001
    ctx->r16 = ADD32(0, -0X4001);
    // 0x8001F62C: andi        $t8, $t7, 0xBFFF
    ctx->r24 = ctx->r15 & 0XBFFF;
    // 0x8001F630: sh          $t8, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r24;
    // 0x8001F634: lb          $v1, 0x39($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X39);
    // 0x8001F638: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8001F63C: blez        $v1, L_8001F680
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001F640: nop
    
            goto L_8001F680;
    }
    // 0x8001F640: nop

    // 0x8001F644: jal         0x80001918
    // 0x8001F648: nop

    music_current_sequence(rdram, ctx);
        goto after_3;
    // 0x8001F648: nop

    after_3:
    // 0x8001F64C: lb          $v1, 0x39($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X39);
    // 0x8001F650: nop

    // 0x8001F654: beq         $v1, $v0, L_8001F670
    if (ctx->r3 == ctx->r2) {
        // 0x8001F658: addiu       $t9, $zero, -0x2
        ctx->r25 = ADD32(0, -0X2);
            goto L_8001F670;
    }
    // 0x8001F658: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x8001F65C: jal         0x80000B34
    // 0x8001F660: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    music_play(rdram, ctx);
        goto after_4;
    // 0x8001F660: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    after_4:
    // 0x8001F664: jal         0x80000B18
    // 0x8001F668: nop

    music_change_off(rdram, ctx);
        goto after_5;
    // 0x8001F668: nop

    after_5:
    // 0x8001F66C: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
L_8001F670:
    // 0x8001F670: jal         0x80000CBC
    // 0x8001F674: sb          $t9, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r25;
    music_volume_reset(rdram, ctx);
        goto after_6;
    // 0x8001F674: sb          $t9, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r25;
    after_6:
    // 0x8001F678: b           L_8001F69C
    // 0x8001F67C: lb          $v1, 0x38($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X38);
        goto L_8001F69C;
    // 0x8001F67C: lb          $v1, 0x38($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X38);
L_8001F680:
    // 0x8001F680: bne         $v1, $at, L_8001F698
    if (ctx->r3 != ctx->r1) {
        // 0x8001F684: nop
    
            goto L_8001F698;
    }
    // 0x8001F684: nop

    // 0x8001F688: jal         0x80000B28
    // 0x8001F68C: nop

    music_change_on(rdram, ctx);
        goto after_7;
    // 0x8001F68C: nop

    after_7:
    // 0x8001F690: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001F694: sb          $t6, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r14;
L_8001F698:
    // 0x8001F698: lb          $v1, 0x38($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X38);
L_8001F69C:
    // 0x8001F69C: nop

    // 0x8001F6A0: beq         $v1, $zero, L_8001F718
    if (ctx->r3 == 0) {
        // 0x8001F6A4: nop
    
            goto L_8001F718;
    }
    // 0x8001F6A4: nop

    // 0x8001F6A8: lh          $t7, 0x24($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X24);
    // 0x8001F6AC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8001F6B0: bne         $t7, $zero, L_8001F718
    if (ctx->r15 != 0) {
        // 0x8001F6B4: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8001F718;
    }
    // 0x8001F6B4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8001F6B8: bne         $v0, $at, L_8001F6E0
    if (ctx->r2 != ctx->r1) {
        // 0x8001F6BC: nop
    
            goto L_8001F6E0;
    }
    // 0x8001F6BC: nop

    // 0x8001F6C0: lw          $a0, 0x18($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X18);
    // 0x8001F6C4: nop

    // 0x8001F6C8: beq         $a0, $zero, L_8001F714
    if (ctx->r4 == 0) {
        // 0x8001F6CC: nop
    
            goto L_8001F714;
    }
    // 0x8001F6CC: nop

    // 0x8001F6D0: jal         0x8000488C
    // 0x8001F6D4: nop

    sndp_stop(rdram, ctx);
        goto after_8;
    // 0x8001F6D4: nop

    after_8:
    // 0x8001F6D8: b           L_8001F718
    // 0x8001F6DC: sb          $zero, 0x38($s3)
    MEM_B(0X38, ctx->r19) = 0;
        goto L_8001F718;
    // 0x8001F6DC: sb          $zero, 0x38($s3)
    MEM_B(0X38, ctx->r19) = 0;
L_8001F6E0:
    // 0x8001F6E0: lw          $a0, 0x18($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X18);
    // 0x8001F6E4: nop

    // 0x8001F6E8: beq         $a0, $zero, L_8001F708
    if (ctx->r4 == 0) {
        // 0x8001F6EC: nop
    
            goto L_8001F708;
    }
    // 0x8001F6EC: nop

    // 0x8001F6F0: jal         0x8000488C
    // 0x8001F6F4: nop

    sndp_stop(rdram, ctx);
        goto after_9;
    // 0x8001F6F4: nop

    after_9:
    // 0x8001F6F8: lb          $v0, 0x38($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X38);
    // 0x8001F6FC: nop

    // 0x8001F700: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8001F704: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8001F708:
    // 0x8001F708: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8001F70C: jal         0x80001D04
    // 0x8001F710: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8001F710: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    after_10:
L_8001F714:
    // 0x8001F714: sb          $zero, 0x38($s3)
    MEM_B(0X38, ctx->r19) = 0;
L_8001F718:
    // 0x8001F718: lb          $v0, 0x43($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X43);
    // 0x8001F71C: nop

    // 0x8001F720: beq         $v0, $zero, L_8001F734
    if (ctx->r2 == 0) {
        // 0x8001F724: nop
    
            goto L_8001F734;
    }
    // 0x8001F724: nop

    // 0x8001F728: jal         0x80000C98
    // 0x8001F72C: sll         $a0, $v0, 8
    ctx->r4 = S32(ctx->r2 << 8);
    music_fade(rdram, ctx);
        goto after_11;
    // 0x8001F72C: sll         $a0, $v0, 8
    ctx->r4 = S32(ctx->r2 << 8);
    after_11:
    // 0x8001F730: sb          $zero, 0x43($s3)
    MEM_B(0X43, ctx->r19) = 0;
L_8001F734:
    // 0x8001F734: lb          $v0, 0x41($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X41);
    // 0x8001F738: lbu         $t0, 0x42($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X42);
    // 0x8001F73C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8001F740: beq         $t9, $zero, L_8001F784
    if (ctx->r25 == 0) {
        // 0x8001F744: andi        $t6, $v0, 0x2
        ctx->r14 = ctx->r2 & 0X2;
            goto L_8001F784;
    }
    // 0x8001F744: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8001F748: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8001F74C: lw          $v0, 0x19C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F750: beq         $t6, $zero, L_8001F75C
    if (ctx->r14 == 0) {
        // 0x8001F754: sll         $t7, $v0, 3
        ctx->r15 = S32(ctx->r2 << 3);
            goto L_8001F75C;
    }
    // 0x8001F754: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8001F758: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001F75C:
    // 0x8001F75C: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001F760: beq         $at, $zero, L_8001F770
    if (ctx->r1 == 0) {
        // 0x8001F764: nop
    
            goto L_8001F770;
    }
    // 0x8001F764: nop

    // 0x8001F768: b           L_8001F7B8
    // 0x8001F76C: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
        goto L_8001F7B8;
    // 0x8001F76C: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
L_8001F770:
    // 0x8001F770: lh          $t8, 0x6($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X6);
    // 0x8001F774: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001F778: ori         $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 | 0X4000;
    // 0x8001F77C: b           L_8001F7B8
    // 0x8001F780: sh          $t9, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r25;
        goto L_8001F7B8;
    // 0x8001F780: sh          $t9, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r25;
L_8001F784:
    // 0x8001F784: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F788: beq         $t6, $zero, L_8001F794
    if (ctx->r14 == 0) {
        // 0x8001F78C: sll         $t8, $t7, 3
        ctx->r24 = S32(ctx->r15 << 3);
            goto L_8001F794;
    }
    // 0x8001F78C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8001F790: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8001F794:
    // 0x8001F794: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8001F798: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x8001F79C: bne         $at, $zero, L_8001F7A8
    if (ctx->r1 != 0) {
        // 0x8001F7A0: nop
    
            goto L_8001F7A8;
    }
    // 0x8001F7A0: nop

    // 0x8001F7A4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8001F7A8:
    // 0x8001F7A8: lh          $t9, 0x6($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X6);
    // 0x8001F7AC: nop

    // 0x8001F7B0: and         $t6, $t9, $s0
    ctx->r14 = ctx->r25 & ctx->r16;
    // 0x8001F7B4: sh          $t6, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r14;
L_8001F7B8:
    // 0x8001F7B8: lbu         $v0, 0x3B($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X3B);
    // 0x8001F7BC: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x8001F7C0: andi        $s2, $v0, 0x7F
    ctx->r18 = ctx->r2 & 0X7F;
    // 0x8001F7C4: beq         $s2, $at, L_8001F988
    if (ctx->r18 == ctx->r1) {
        // 0x8001F7C8: sb          $t0, 0x42($s3)
        MEM_B(0X42, ctx->r19) = ctx->r8;
            goto L_8001F988;
    }
    // 0x8001F7C8: sb          $t0, 0x42($s3)
    MEM_B(0X42, ctx->r19) = ctx->r8;
    // 0x8001F7CC: slti        $at, $s2, 0x8
    ctx->r1 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // 0x8001F7D0: bne         $at, $zero, L_8001F86C
    if (ctx->r1 != 0) {
        // 0x8001F7D4: slti        $at, $s2, 0x6
        ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
            goto L_8001F86C;
    }
    // 0x8001F7D4: slti        $at, $s2, 0x6
    ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // 0x8001F7D8: jal         0x8001E29C
    // 0x8001F7DC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8001F7DC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_12:
    // 0x8001F7E0: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8001F7E4: addu        $t7, $t7, $s2
    ctx->r15 = ADD32(ctx->r15, ctx->r18);
    // 0x8001F7E8: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x8001F7EC: addiu       $s1, $v1, -0x28
    ctx->r17 = ADD32(ctx->r3, -0X28);
    // 0x8001F7F0: lb          $t0, 0x0($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X0);
    // 0x8001F7F4: lb          $s0, 0x1($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X1);
    // 0x8001F7F8: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x8001F7FC: addiu       $t0, $t8, 0x384
    ctx->r8 = ADD32(ctx->r24, 0X384);
    // 0x8001F800: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x8001F804: addiu       $s0, $t9, 0x384
    ctx->r16 = ADD32(ctx->r25, 0X384);
    // 0x8001F808: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    // 0x8001F80C: jal         0x8000C8B4
    // 0x8001F810: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    normalise_time(rdram, ctx);
        goto after_13;
    // 0x8001F810: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_13:
    // 0x8001F814: lw          $t0, 0x174($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X174);
    // 0x8001F818: lb          $a1, 0x2($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X2);
    // 0x8001F81C: lb          $a2, 0x3($s1)
    ctx->r6 = MEM_B(ctx->r17, 0X3);
    // 0x8001F820: lb          $a3, 0x4($s1)
    ctx->r7 = MEM_B(ctx->r17, 0X4);
    // 0x8001F824: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001F828: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8001F82C: lbu         $t9, 0x3C($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X3C);
    // 0x8001F830: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8001F834: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F838: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8001F83C: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8001F840: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x8001F844: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8001F848: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8001F84C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F850: mflo        $t6
    ctx->r14 = lo;
    // 0x8001F854: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8001F858: jal         0x80030DE0
    // 0x8001F85C: nop

    slowly_change_fog(rdram, ctx);
        goto after_14;
    // 0x8001F85C: nop

    after_14:
    // 0x8001F860: b           L_8001F984
    // 0x8001F864: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
        goto L_8001F984;
    // 0x8001F864: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001F868: slti        $at, $s2, 0x6
    ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
L_8001F86C:
    // 0x8001F86C: bne         $at, $zero, L_8001F8D8
    if (ctx->r1 != 0) {
        // 0x8001F870: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8001F8D8;
    }
    // 0x8001F870: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8001F874: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8001F878: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8001F87C: bne         $s2, $at, L_8001F8A0
    if (ctx->r18 != ctx->r1) {
        // 0x8001F880: sb          $t7, 0xA4($sp)
        MEM_B(0XA4, ctx->r29) = ctx->r15;
            goto L_8001F8A0;
    }
    // 0x8001F880: sb          $t7, 0xA4($sp)
    MEM_B(0XA4, ctx->r29) = ctx->r15;
    // 0x8001F884: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x8001F888: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8001F88C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8001F890: sb          $t6, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r14;
    // 0x8001F894: sb          $t9, 0xA6($sp)
    MEM_B(0XA6, ctx->r29) = ctx->r25;
    // 0x8001F898: b           L_8001F8B8
    // 0x8001F89C: sb          $t8, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r24;
        goto L_8001F8B8;
    // 0x8001F89C: sb          $t8, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r24;
L_8001F8A0:
    // 0x8001F8A0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8001F8A4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001F8A8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8001F8AC: sb          $t9, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r25;
    // 0x8001F8B0: sb          $t8, 0xA6($sp)
    MEM_B(0XA6, ctx->r29) = ctx->r24;
    // 0x8001F8B4: sb          $t7, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r15;
L_8001F8B8:
    // 0x8001F8B8: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8001F8BC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8001F8C0: sh          $t6, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r14;
    // 0x8001F8C4: sh          $t7, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r15;
    // 0x8001F8C8: jal         0x800C01D8
    // 0x8001F8CC: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    transition_begin(rdram, ctx);
        goto after_15;
    // 0x8001F8CC: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    after_15:
    // 0x8001F8D0: b           L_8001F984
    // 0x8001F8D4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
        goto L_8001F984;
    // 0x8001F8D4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8001F8D8:
    // 0x8001F8D8: jal         0x8001E29C
    // 0x8001F8DC: sb          $v0, 0xA4($sp)
    MEM_B(0XA4, ctx->r29) = ctx->r2;
    get_misc_asset(rdram, ctx);
        goto after_16;
    // 0x8001F8DC: sb          $v0, 0xA4($sp)
    MEM_B(0XA4, ctx->r29) = ctx->r2;
    after_16:
    // 0x8001F8E0: lb          $t8, 0x40($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X40);
    // 0x8001F8E4: nop

    // 0x8001F8E8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001F8EC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001F8F0: addu        $s1, $v0, $t9
    ctx->r17 = ADD32(ctx->r2, ctx->r25);
    // 0x8001F8F4: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x8001F8F8: nop

    // 0x8001F8FC: sb          $t6, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r14;
    // 0x8001F900: lb          $t7, 0x1($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1);
    // 0x8001F904: nop

    // 0x8001F908: sb          $t7, 0xA6($sp)
    MEM_B(0XA6, ctx->r29) = ctx->r15;
    // 0x8001F90C: lb          $t8, 0x2($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X2);
    // 0x8001F910: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x8001F914: sb          $t8, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r24;
    // 0x8001F918: lbu         $t9, 0x3B($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X3B);
    // 0x8001F91C: nop

    // 0x8001F920: andi        $t6, $t9, 0x80
    ctx->r14 = ctx->r25 & 0X80;
    // 0x8001F924: beq         $t6, $zero, L_8001F934
    if (ctx->r14 == 0) {
        // 0x8001F928: nop
    
            goto L_8001F934;
    }
    // 0x8001F928: nop

    // 0x8001F92C: b           L_8001F938
    // 0x8001F930: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
        goto L_8001F938;
    // 0x8001F930: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
L_8001F934:
    // 0x8001F934: sh          $t7, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r15;
L_8001F938:
    // 0x8001F938: jal         0x8000C8B4
    // 0x8001F93C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    normalise_time(rdram, ctx);
        goto after_17;
    // 0x8001F93C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_17:
    // 0x8001F940: lbu         $t8, 0x3C($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3C);
    // 0x8001F944: nop

    // 0x8001F948: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F94C: mflo        $t9
    ctx->r25 = lo;
    // 0x8001F950: sh          $t9, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r25;
    // 0x8001F954: jal         0x800C018C
    // 0x8001F958: nop

    check_fadeout_transition(rdram, ctx);
        goto after_18;
    // 0x8001F958: nop

    after_18:
    // 0x8001F95C: beq         $v0, $zero, L_8001F978
    if (ctx->r2 == 0) {
        // 0x8001F960: nop
    
            goto L_8001F978;
    }
    // 0x8001F960: nop

    // 0x8001F964: lbu         $t6, 0xA4($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XA4);
    // 0x8001F968: nop

    // 0x8001F96C: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x8001F970: beq         $t7, $zero, L_8001F984
    if (ctx->r15 == 0) {
        // 0x8001F974: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_8001F984;
    }
    // 0x8001F974: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8001F978:
    // 0x8001F978: jal         0x800C01D8
    // 0x8001F97C: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    transition_begin(rdram, ctx);
        goto after_19;
    // 0x8001F97C: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    after_19:
    // 0x8001F980: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8001F984:
    // 0x8001F984: sb          $t8, 0x3B($s3)
    MEM_B(0X3B, ctx->r19) = ctx->r24;
L_8001F988:
    // 0x8001F988: lbu         $t9, 0x2E($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X2E);
    // 0x8001F98C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001F990: bne         $t9, $at, L_8001FA8C
    if (ctx->r25 != ctx->r1) {
        // 0x8001F994: nop
    
            goto L_8001FA8C;
    }
    // 0x8001F994: nop

    // 0x8001F998: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001F99C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001F9A0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001F9A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001F9A8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001F9AC: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8001F9B0: lb          $t7, 0x31($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X31);
    // 0x8001F9B4: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
    // 0x8001F9B8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001F9BC: lh          $t7, 0x2($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X2);
    // 0x8001F9C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F9C4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8001F9C8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001F9CC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001F9D0: nop

    // 0x8001F9D4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001F9D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001F9DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001F9E0: nop

    // 0x8001F9E4: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001F9E8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001F9EC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001F9F0: nop

    // 0x8001F9F4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001F9F8: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    // 0x8001F9FC: lb          $t6, 0x32($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X32);
    // 0x8001FA00: nop

    // 0x8001FA04: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8001FA08: lh          $t6, 0x4($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X4);
    // 0x8001FA0C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001FA10: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001FA14: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001FA18: nop

    // 0x8001FA1C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001FA20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FA24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FA28: nop

    // 0x8001FA2C: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001FA30: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001FA34: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001FA38: nop

    // 0x8001FA3C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001FA40: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    // 0x8001FA44: lb          $t7, 0x33($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X33);
    // 0x8001FA48: nop

    // 0x8001FA4C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001FA50: nop

    // 0x8001FA54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001FA58: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001FA5C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001FA60: nop

    // 0x8001FA64: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001FA68: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FA6C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FA70: nop

    // 0x8001FA74: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001FA78: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001FA7C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001FA80: nop

    // 0x8001FA84: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001FA88: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
L_8001FA8C:
    // 0x8001FA8C: beq         $s4, $zero, L_8001FDA4
    if (ctx->r20 == 0) {
        // 0x8001FA90: nop
    
            goto L_8001FDA4;
    }
    // 0x8001FA90: nop

    // 0x8001FA94: lw          $t7, 0x40($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X40);
    // 0x8001FA98: nop

    // 0x8001FA9C: lb          $t6, 0x53($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X53);
    // 0x8001FAA0: nop

    // 0x8001FAA4: bne         $t6, $zero, L_8001FDA4
    if (ctx->r14 != 0) {
        // 0x8001FAA8: nop
    
            goto L_8001FDA4;
    }
    // 0x8001FAA8: nop

    // 0x8001FAAC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001FAB0: lb          $t8, 0x3B($s6)
    ctx->r24 = MEM_B(ctx->r22, 0X3B);
    // 0x8001FAB4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001FAB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FABC: sb          $t8, 0x3B($s4)
    MEM_B(0X3B, ctx->r20) = ctx->r24;
    // 0x8001FAC0: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FAC4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FAC8: lh          $v0, 0x18($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X18);
    // 0x8001FACC: cvt.w.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8001FAD0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8001FAD4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001FAD8: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8001FADC: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001FAE0: beq         $v0, $t8, L_8001FB00
    if (ctx->r2 == ctx->r24) {
        // 0x8001FAE4: nop
    
            goto L_8001FB00;
    }
    // 0x8001FAE4: nop

    // 0x8001FAE8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8001FAEC: nop

    // 0x8001FAF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001FAF4: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FAF8: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FAFC: nop

L_8001FB00:
    // 0x8001FB00: lb          $t7, 0x3A($s4)
    ctx->r15 = MEM_B(ctx->r20, 0X3A);
    // 0x8001FB04: lw          $t9, 0x68($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X68);
    // 0x8001FB08: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8001FB0C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8001FB10: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x8001FB14: nop

    // 0x8001FB18: beq         $v1, $zero, L_8001FD78
    if (ctx->r3 == 0) {
        // 0x8001FB1C: nop
    
            goto L_8001FD78;
    }
    // 0x8001FB1C: nop

    // 0x8001FB20: lb          $v0, 0x3B($s4)
    ctx->r2 = MEM_B(ctx->r20, 0X3B);
    // 0x8001FB24: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8001FB28: bltz        $v0, L_8001FD78
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FB2C: nop
    
            goto L_8001FD78;
    }
    // 0x8001FB2C: nop

    // 0x8001FB30: lh          $t7, 0x48($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X48);
    // 0x8001FB34: nop

    // 0x8001FB38: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001FB3C: beq         $at, $zero, L_8001FD78
    if (ctx->r1 == 0) {
        // 0x8001FB40: nop
    
            goto L_8001FD78;
    }
    // 0x8001FB40: nop

    // 0x8001FB44: lw          $t9, 0x44($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X44);
    // 0x8001FB48: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8001FB4C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8001FB50: lw          $s5, 0x4($t8)
    ctx->r21 = MEM_W(ctx->r24, 0X4);
    // 0x8001FB54: lbu         $v1, 0x2C($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X2C);
    // 0x8001FB58: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x8001FB5C: sll         $t7, $s5, 4
    ctx->r15 = S32(ctx->r21 << 4);
    // 0x8001FB60: beq         $v1, $zero, L_8001FB8C
    if (ctx->r3 == 0) {
        // 0x8001FB64: or          $s5, $t7, $zero
        ctx->r21 = ctx->r15 | 0;
            goto L_8001FB8C;
    }
    // 0x8001FB64: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
    // 0x8001FB68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FB6C: beq         $v1, $at, L_8001FC2C
    if (ctx->r3 == ctx->r1) {
        // 0x8001FB70: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001FC2C;
    }
    // 0x8001FB70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001FB74: beq         $v1, $at, L_8001FBD8
    if (ctx->r3 == ctx->r1) {
        // 0x8001FB78: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001FBD8;
    }
    // 0x8001FB78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001FB7C: beq         $v1, $at, L_8001FCD4
    if (ctx->r3 == ctx->r1) {
        // 0x8001FB80: nop
    
            goto L_8001FCD4;
    }
    // 0x8001FB80: nop

    // 0x8001FB84: b           L_8001FD7C
    // 0x8001FB88: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FD7C;
    // 0x8001FB88: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FB8C:
    // 0x8001FB8C: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FB90: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FB94: nop

    // 0x8001FB98: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FB9C: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x8001FBA0: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8001FBA4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001FBA8: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FBAC: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FBB0: nop

    // 0x8001FBB4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FBB8: nop

    // 0x8001FBBC: bc1f        L_8001FD78
    if (!c1cs) {
        // 0x8001FBC0: nop
    
            goto L_8001FD78;
    }
    // 0x8001FBC0: nop

    // 0x8001FBC4: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8001FBC8: swc1        $f6, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f6.u32l;
    // 0x8001FBCC: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FBD0: b           L_8001FD7C
    // 0x8001FBD4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FD7C;
    // 0x8001FBD4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FBD8:
    // 0x8001FBD8: lwc1        $f8, 0x14($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FBDC: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FBE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FBE4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001FBE8: mtc1        $s5, $f8
    ctx->f8.u32l = ctx->r21;
    // 0x8001FBEC: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001FBF0: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001FBF4: swc1        $f6, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f6.u32l;
    // 0x8001FBF8: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FBFC: nop

    // 0x8001FC00: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FC04: nop

    // 0x8001FC08: bc1f        L_8001FD78
    if (!c1cs) {
        // 0x8001FC0C: nop
    
            goto L_8001FD78;
    }
    // 0x8001FC0C: nop

    // 0x8001FC10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001FC14: nop

    // 0x8001FC18: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8001FC1C: swc1        $f4, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f4.u32l;
    // 0x8001FC20: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC24: b           L_8001FD7C
    // 0x8001FC28: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FD7C;
    // 0x8001FC28: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FC2C:
    // 0x8001FC2C: lbu         $t9, 0x2D($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X2D);
    // 0x8001FC30: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FC34: bne         $t9, $zero, L_8001FC98
    if (ctx->r25 != 0) {
        // 0x8001FC38: nop
    
            goto L_8001FC98;
    }
    // 0x8001FC38: nop

    // 0x8001FC3C: lwc1        $f6, 0x14($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FC40: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FC44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FC48: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001FC4C: mtc1        $s5, $f6
    ctx->f6.u32l = ctx->r21;
    // 0x8001FC50: add.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8001FC54: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001FC58: swc1        $f4, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f4.u32l;
    // 0x8001FC5C: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC60: nop

    // 0x8001FC64: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FC68: nop

    // 0x8001FC6C: bc1f        L_8001FC90
    if (!c1cs) {
        // 0x8001FC70: nop
    
            goto L_8001FC90;
    }
    // 0x8001FC70: nop

    // 0x8001FC74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001FC78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001FC7C: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8001FC80: sb          $t6, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = ctx->r14;
    // 0x8001FC84: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FC88: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC8C: nop

L_8001FC90:
    // 0x8001FC90: b           L_8001FD7C
    // 0x8001FC94: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FD7C;
    // 0x8001FC94: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FC98:
    // 0x8001FC98: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FC9C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001FCA0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FCA4: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8001FCA8: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FCAC: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FCB0: nop

    // 0x8001FCB4: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x8001FCB8: nop

    // 0x8001FCBC: bc1f        L_8001FD78
    if (!c1cs) {
        // 0x8001FCC0: nop
    
            goto L_8001FD78;
    }
    // 0x8001FCC0: nop

    // 0x8001FCC4: swc1        $f22, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f22.u32l;
    // 0x8001FCC8: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FCCC: b           L_8001FD78
    // 0x8001FCD0: sb          $zero, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = 0;
        goto L_8001FD78;
    // 0x8001FCD0: sb          $zero, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = 0;
L_8001FCD4:
    // 0x8001FCD4: lbu         $t8, 0x2D($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X2D);
    // 0x8001FCD8: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FCDC: bne         $t8, $zero, L_8001FD40
    if (ctx->r24 != 0) {
        // 0x8001FCE0: nop
    
            goto L_8001FD40;
    }
    // 0x8001FCE0: nop

    // 0x8001FCE4: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FCE8: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FCEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FCF0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FCF4: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x8001FCF8: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8001FCFC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001FD00: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FD04: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD08: nop

    // 0x8001FD0C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FD10: nop

    // 0x8001FD14: bc1f        L_8001FD38
    if (!c1cs) {
        // 0x8001FD18: nop
    
            goto L_8001FD38;
    }
    // 0x8001FD18: nop

    // 0x8001FD1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001FD20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001FD24: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001FD28: sb          $t7, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = ctx->r15;
    // 0x8001FD2C: swc1        $f8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f8.u32l;
    // 0x8001FD30: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD34: nop

L_8001FD38:
    // 0x8001FD38: b           L_8001FD7C
    // 0x8001FD3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FD7C;
    // 0x8001FD3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FD40:
    // 0x8001FD40: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FD44: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001FD48: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001FD4C: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8001FD50: swc1        $f8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f8.u32l;
    // 0x8001FD54: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD58: nop

    // 0x8001FD5C: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x8001FD60: nop

    // 0x8001FD64: bc1f        L_8001FD78
    if (!c1cs) {
        // 0x8001FD68: nop
    
            goto L_8001FD78;
    }
    // 0x8001FD68: nop

    // 0x8001FD6C: swc1        $f22, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f22.u32l;
    // 0x8001FD70: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD74: nop

L_8001FD78:
    // 0x8001FD78: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FD7C:
    // 0x8001FD7C: nop

    // 0x8001FD80: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001FD84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FD88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FD8C: nop

    // 0x8001FD90: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8001FD94: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8001FD98: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001FD9C: sh          $t6, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r14;
    // 0x8001FDA0: nop

L_8001FDA4:
    // 0x8001FDA4: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8001FDA8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8001FDAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001FDB0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001FDB4: c.le.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d <= ctx->f4.d;
    // 0x8001FDB8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001FDBC: bc1f        L_8001FDD8
    if (!c1cs) {
        // 0x8001FDC0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8001FDD8;
    }
    // 0x8001FDC0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001FDC4: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FDC8: jal         0x800214E4
    // 0x8001FDCC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_20;
    // 0x8001FDCC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_20:
    // 0x8001FDD0: b           L_80021098
    // 0x8001FDD4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80021098;
    // 0x8001FDD4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FDD8:
    // 0x8001FDD8: lh          $v1, -0x5188($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X5188);
    // 0x8001FDDC: lh          $a1, 0x28($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X28);
    // 0x8001FDE0: blez        $v1, L_8001FE3C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001FDE4: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8001FE3C;
    }
    // 0x8001FDE4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001FDE8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001FDEC: addiu       $a3, $a3, -0x518C
    ctx->r7 = ADD32(ctx->r7, -0X518C);
    // 0x8001FDF0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8001FDF4: nop

    // 0x8001FDF8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8001FDFC: nop

    // 0x8001FE00: lw          $t7, 0x7C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X7C);
    // 0x8001FE04: nop

    // 0x8001FE08: beq         $a1, $t7, L_8001FE3C
    if (ctx->r5 == ctx->r15) {
        // 0x8001FE0C: nop
    
            goto L_8001FE3C;
    }
    // 0x8001FE0C: nop

L_8001FE10:
    // 0x8001FE10: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001FE14: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FE18: beq         $at, $zero, L_8001FE3C
    if (ctx->r1 == 0) {
        // 0x8001FE1C: sll         $t9, $s4, 2
        ctx->r25 = S32(ctx->r20 << 2);
            goto L_8001FE3C;
    }
    // 0x8001FE1C: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x8001FE20: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x8001FE24: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001FE28: nop

    // 0x8001FE2C: lw          $t7, 0x7C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X7C);
    // 0x8001FE30: nop

    // 0x8001FE34: bne         $a1, $t7, L_8001FE10
    if (ctx->r5 != ctx->r15) {
        // 0x8001FE38: nop
    
            goto L_8001FE10;
    }
    // 0x8001FE38: nop

L_8001FE3C:
    // 0x8001FE3C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001FE40: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FE44: bne         $at, $zero, L_8001FE60
    if (ctx->r1 != 0) {
        // 0x8001FE48: addiu       $a3, $a3, -0x518C
        ctx->r7 = ADD32(ctx->r7, -0X518C);
            goto L_8001FE60;
    }
    // 0x8001FE48: addiu       $a3, $a3, -0x518C
    ctx->r7 = ADD32(ctx->r7, -0X518C);
    // 0x8001FE4C: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FE50: jal         0x800214E4
    // 0x8001FE54: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_21;
    // 0x8001FE54: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_21:
    // 0x8001FE58: b           L_80021098
    // 0x8001FE5C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80021098;
    // 0x8001FE5C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FE60:
    // 0x8001FE60: addiu       $t9, $s4, 0x1
    ctx->r25 = ADD32(ctx->r20, 0X1);
    // 0x8001FE64: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FE68: beq         $at, $zero, L_8001FEC0
    if (ctx->r1 == 0) {
        // 0x8001FE6C: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_8001FEC0;
    }
    // 0x8001FE6C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8001FE70: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8001FE74: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8001FE78: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x8001FE7C: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8001FE80: addu        $v0, $s4, $s5
    ctx->r2 = ADD32(ctx->r20, ctx->r21);
    // 0x8001FE84: lw          $t9, 0x7C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X7C);
    // 0x8001FE88: nop

    // 0x8001FE8C: bne         $a1, $t9, L_8001FEC0
    if (ctx->r5 != ctx->r25) {
        // 0x8001FE90: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001FEC0;
    }
    // 0x8001FE90: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001FE94:
    // 0x8001FE94: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FE98: beq         $at, $zero, L_8001FEC0
    if (ctx->r1 == 0) {
        // 0x8001FE9C: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8001FEC0;
    }
    // 0x8001FE9C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001FEA0: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8001FEA4: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x8001FEA8: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8001FEAC: nop

    // 0x8001FEB0: lw          $t9, 0x7C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X7C);
    // 0x8001FEB4: nop

    // 0x8001FEB8: beq         $a1, $t9, L_8001FE94
    if (ctx->r5 == ctx->r25) {
        // 0x8001FEBC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001FE94;
    }
    // 0x8001FEBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001FEC0:
    // 0x8001FEC0: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x8001FEC4: beq         $at, $zero, L_8001FEE0
    if (ctx->r1 == 0) {
        // 0x8001FEC8: nop
    
            goto L_8001FEE0;
    }
    // 0x8001FEC8: nop

    // 0x8001FECC: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FED0: jal         0x800214E4
    // 0x8001FED4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_22;
    // 0x8001FED4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_22:
    // 0x8001FED8: b           L_80021098
    // 0x8001FEDC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80021098;
    // 0x8001FEDC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FEE0:
    // 0x8001FEE0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8001FEE4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001FEE8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8001FEEC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001FEF0: lw          $t8, 0x40($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X40);
    // 0x8001FEF4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001FEF8: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8001FEFC: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x8001FF00: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8001FF04: nop

    // 0x8001FF08: div.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x8001FF0C: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8001FF10: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x8001FF14: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8001FF18: slti        $at, $s5, 0x3
    ctx->r1 = SIGNED(ctx->r21) < 0X3 ? 1 : 0;
    // 0x8001FF1C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8001FF20: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8001FF24: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x8001FF28: lw          $t7, -0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, -0X4);
    // 0x8001FF2C: nop

    // 0x8001FF30: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x8001FF34: bne         $at, $zero, L_8001FF5C
    if (ctx->r1 != 0) {
        // 0x8001FF38: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8001FF5C;
    }
    // 0x8001FF38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001FF3C: lb          $v0, 0x1D($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X1D);
    // 0x8001FF40: addiu       $t9, $s5, -0x1
    ctx->r25 = ADD32(ctx->r21, -0X1);
    // 0x8001FF44: bltz        $v0, L_8001FF58
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FF48: slt         $at, $v0, $t9
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_8001FF58;
    }
    // 0x8001FF48: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001FF4C: beq         $at, $zero, L_8001FF5C
    if (ctx->r1 == 0) {
        // 0x8001FF50: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8001FF5C;
    }
    // 0x8001FF50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001FF54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001FF58:
    // 0x8001FF58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8001FF5C:
    // 0x8001FF5C: bne         $v1, $at, L_8001FF8C
    if (ctx->r3 != ctx->r1) {
        // 0x8001FF60: nop
    
            goto L_8001FF8C;
    }
    // 0x8001FF60: nop

    // 0x8001FF64: lh          $t6, 0x26($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X26);
    // 0x8001FF68: addiu       $t8, $s5, -0x1
    ctx->r24 = ADD32(ctx->r21, -0X1);
    // 0x8001FF6C: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001FF70: bne         $at, $zero, L_8001FF8C
    if (ctx->r1 != 0) {
        // 0x8001FF74: nop
    
            goto L_8001FF8C;
    }
    // 0x8001FF74: nop

    // 0x8001FF78: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FF7C: jal         0x800214E4
    // 0x8001FF80: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_23;
    // 0x8001FF80: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_23:
    // 0x8001FF84: b           L_80021098
    // 0x8001FF88: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80021098;
    // 0x8001FF88: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FF8C:
    // 0x8001FF8C: lh          $v0, 0x36($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X36);
    // 0x8001FF90: sw          $v1, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r3;
    // 0x8001FF94: bltz        $v0, L_8001FFBC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FF98: addiu       $t1, $sp, 0x154
        ctx->r9 = ADD32(ctx->r29, 0X154);
            goto L_8001FFBC;
    }
    // 0x8001FF98: addiu       $t1, $sp, 0x154
    ctx->r9 = ADD32(ctx->r29, 0X154);
    // 0x8001FF9C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001FFA0: lb          $t7, -0x52AD($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X52AD);
    // 0x8001FFA4: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FFA8: bne         $t7, $zero, L_8001FFB4
    if (ctx->r15 != 0) {
        // 0x8001FFAC: subu        $t6, $v0, $t9
        ctx->r14 = SUB32(ctx->r2, ctx->r25);
            goto L_8001FFB4;
    }
    // 0x8001FFAC: subu        $t6, $v0, $t9
    ctx->r14 = SUB32(ctx->r2, ctx->r25);
    // 0x8001FFB0: sh          $t6, 0x36($s3)
    MEM_H(0X36, ctx->r19) = ctx->r14;
L_8001FFB4:
    // 0x8001FFB4: b           L_80021094
    // 0x8001FFB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021094;
    // 0x8001FFB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001FFBC:
    // 0x8001FFBC: lh          $s0, 0x26($s3)
    ctx->r16 = MEM_H(ctx->r19, 0X26);
    // 0x8001FFC0: addiu       $t2, $sp, 0x140
    ctx->r10 = ADD32(ctx->r29, 0X140);
    // 0x8001FFC4: addiu       $t3, $sp, 0x12C
    ctx->r11 = ADD32(ctx->r29, 0X12C);
    // 0x8001FFC8: addiu       $t5, $sp, 0xE0
    ctx->r13 = ADD32(ctx->r29, 0XE0);
    // 0x8001FFCC: addiu       $t4, $sp, 0xCC
    ctx->r12 = ADD32(ctx->r29, 0XCC);
    // 0x8001FFD0: addiu       $ra, $sp, 0xB8
    ctx->r31 = ADD32(ctx->r29, 0XB8);
    // 0x8001FFD4: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    // 0x8001FFD8: addiu       $s2, $sp, 0x108
    ctx->r18 = ADD32(ctx->r29, 0X108);
    // 0x8001FFDC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8001FFE0:
    // 0x8001FFE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001FFE4: bne         $s0, $at, L_80020190
    if (ctx->r16 != ctx->r1) {
        // 0x8001FFE8: slt         $at, $s0, $s5
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_80020190;
    }
    // 0x8001FFE8: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8001FFEC: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x8001FFF0: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x8001FFF4: beq         $t8, $zero, L_800200D4
    if (ctx->r24 == 0) {
        // 0x8001FFF8: addu        $t6, $s4, $s5
        ctx->r14 = ADD32(ctx->r20, ctx->r21);
            goto L_800200D4;
    }
    // 0x8001FFF8: addu        $t6, $s4, $s5
    ctx->r14 = ADD32(ctx->r20, ctx->r21);
    // 0x8001FFFC: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
    // 0x80020000: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80020004: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80020008: lwc1        $f0, 0xC($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8002000C: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80020010: nop

    // 0x80020014: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80020018: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002001C: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x80020020: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80020024: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80020028: lwc1        $f2, 0x10($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8002002C: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80020030: nop

    // 0x80020034: sub.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80020038: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8002003C: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x80020040: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80020044: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80020048: lwc1        $f12, 0x14($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8002004C: lwc1        $f8, 0x14($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80020050: nop

    // 0x80020054: sub.s       $f6, $f12, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80020058: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8002005C: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80020060: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80020064: nop

    // 0x80020068: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x8002006C: nop

    // 0x80020070: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80020074: nop

    // 0x80020078: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002007C: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x80020080: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80020084: nop

    // 0x80020088: lh          $t6, 0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X2);
    // 0x8002008C: nop

    // 0x80020090: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80020094: nop

    // 0x80020098: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002009C: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800200A0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800200A4: nop

    // 0x800200A8: lh          $t7, 0x4($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X4);
    // 0x800200AC: nop

    // 0x800200B0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800200B4: nop

    // 0x800200B8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800200BC: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800200C0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800200C4: nop

    // 0x800200C8: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800200CC: b           L_800204F8
    // 0x800200D0: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
        goto L_800204F8;
    // 0x800200D0: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_800200D4:
    // 0x800200D4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800200D8: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x800200DC: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800200E0: nop

    // 0x800200E4: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800200E8: nop

    // 0x800200EC: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x800200F0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800200F4: nop

    // 0x800200F8: lwc1        $f4, 0x10($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800200FC: nop

    // 0x80020100: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x80020104: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80020108: nop

    // 0x8002010C: lwc1        $f8, 0x14($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80020110: nop

    // 0x80020114: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x80020118: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x8002011C: nop

    // 0x80020120: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x80020124: nop

    // 0x80020128: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002012C: nop

    // 0x80020130: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80020134: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x80020138: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x8002013C: nop

    // 0x80020140: lh          $t6, 0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X2);
    // 0x80020144: nop

    // 0x80020148: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002014C: nop

    // 0x80020150: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80020154: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x80020158: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x8002015C: nop

    // 0x80020160: lh          $t7, 0x4($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X4);
    // 0x80020164: nop

    // 0x80020168: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002016C: nop

    // 0x80020170: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80020174: swc1        $f10, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f10.u32l;
    // 0x80020178: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x8002017C: nop

    // 0x80020180: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80020184: b           L_800204F8
    // 0x80020188: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
        goto L_800204F8;
    // 0x80020188: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x8002018C: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
L_80020190:
    // 0x80020190: bne         $at, $zero, L_800203C4
    if (ctx->r1 != 0) {
        // 0x80020194: addu        $a1, $s0, $s4
        ctx->r5 = ADD32(ctx->r16, ctx->r20);
            goto L_800203C4;
    }
    // 0x80020194: addu        $a1, $s0, $s4
    ctx->r5 = ADD32(ctx->r16, ctx->r20);
    // 0x80020198: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x8002019C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800201A0: bne         $t6, $at, L_800202F8
    if (ctx->r14 != ctx->r1) {
        // 0x800201A4: addu        $v0, $s5, $s4
        ctx->r2 = ADD32(ctx->r21, ctx->r20);
            goto L_800202F8;
    }
    // 0x800201A4: addu        $v0, $s5, $s4
    ctx->r2 = ADD32(ctx->r21, ctx->r20);
    // 0x800201A8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800201AC: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800201B0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800201B4: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800201B8: lw          $s1, 0x3C($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X3C);
    // 0x800201BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800201C0: lb          $t6, 0x22($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X22);
    // 0x800201C4: addiu       $s0, $s5, -0x1
    ctx->r16 = ADD32(ctx->r21, -0X1);
    // 0x800201C8: bne         $t6, $at, L_80020234
    if (ctx->r14 != ctx->r1) {
        // 0x800201CC: addiu       $a1, $a1, -0x4
        ctx->r5 = ADD32(ctx->r5, -0X4);
            goto L_80020234;
    }
    // 0x800201CC: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800201D0: lb          $a0, 0x30($s3)
    ctx->r4 = MEM_B(ctx->r19, 0X30);
    // 0x800201D4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800201D8: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x800201DC: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x800201E0: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x800201E4: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x800201E8: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x800201EC: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x800201F0: jal         0x800665E8
    // 0x800201F4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    set_active_camera(rdram, ctx);
        goto after_24;
    // 0x800201F4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_24:
    // 0x800201F8: jal         0x80069CFC
    // 0x800201FC: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_25;
    // 0x800201FC: nop

    after_25:
    // 0x80020200: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80020204: lw          $a2, -0x518C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X518C);
    // 0x80020208: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8002020C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80020210: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80020214: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80020218: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8002021C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80020220: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80020224: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80020228: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002022C: b           L_80020240
    // 0x80020230: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
        goto L_80020240;
    // 0x80020230: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
L_80020234:
    // 0x80020234: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
    // 0x80020238: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8002023C: nop

L_80020240:
    // 0x80020240: lw          $t8, -0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, -0X4);
    // 0x80020244: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80020248: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8002024C: nop

    // 0x80020250: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80020254: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80020258: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x8002025C: lw          $t7, -0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X4);
    // 0x80020260: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80020264: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80020268: nop

    // 0x8002026C: sub.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80020270: add.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80020274: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x80020278: lw          $t9, -0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, -0X4);
    // 0x8002027C: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80020280: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80020284: nop

    // 0x80020288: sub.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x8002028C: add.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80020290: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x80020294: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x80020298: nop

    // 0x8002029C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800202A0: nop

    // 0x800202A4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800202A8: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800202AC: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x800202B0: nop

    // 0x800202B4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800202B8: nop

    // 0x800202BC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800202C0: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800202C4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800202C8: nop

    // 0x800202CC: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800202D0: nop

    // 0x800202D4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800202D8: nop

    // 0x800202DC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800202E0: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800202E4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800202E8: nop

    // 0x800202EC: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800202F0: b           L_800204F8
    // 0x800202F4: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
        goto L_800204F8;
    // 0x800202F4: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_800202F8:
    // 0x800202F8: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x800202FC: nop

    // 0x80020300: addu        $t8, $s4, $t6
    ctx->r24 = ADD32(ctx->r20, ctx->r14);
    // 0x80020304: addu        $t7, $t8, $s0
    ctx->r15 = ADD32(ctx->r24, ctx->r16);
    // 0x80020308: subu        $t9, $t7, $s5
    ctx->r25 = SUB32(ctx->r15, ctx->r21);
    // 0x8002030C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80020310: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x80020314: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80020318: nop

    // 0x8002031C: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80020320: nop

    // 0x80020324: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x80020328: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8002032C: nop

    // 0x80020330: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80020334: nop

    // 0x80020338: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x8002033C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80020340: nop

    // 0x80020344: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80020348: nop

    // 0x8002034C: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80020350: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80020354: nop

    // 0x80020358: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8002035C: nop

    // 0x80020360: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80020364: nop

    // 0x80020368: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002036C: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x80020370: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80020374: nop

    // 0x80020378: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x8002037C: nop

    // 0x80020380: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80020384: nop

    // 0x80020388: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002038C: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x80020390: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80020394: nop

    // 0x80020398: lh          $t8, 0x4($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X4);
    // 0x8002039C: nop

    // 0x800203A0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800203A4: nop

    // 0x800203A8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800203AC: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800203B0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800203B4: nop

    // 0x800203B8: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800203BC: b           L_800204F8
    // 0x800203C0: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
        goto L_800204F8;
    // 0x800203C0: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_800203C4:
    // 0x800203C4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800203C8: addu        $a0, $a2, $t9
    ctx->r4 = ADD32(ctx->r6, ctx->r25);
    // 0x800203CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800203D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800203D4: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x800203D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800203DC: lb          $t6, 0x22($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X22);
    // 0x800203E0: nop

    // 0x800203E4: bne         $t6, $at, L_80020450
    if (ctx->r14 != ctx->r1) {
        // 0x800203E8: nop
    
            goto L_80020450;
    }
    // 0x800203E8: nop

    // 0x800203EC: lb          $a0, 0x30($s3)
    ctx->r4 = MEM_B(ctx->r19, 0X30);
    // 0x800203F0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800203F4: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x800203F8: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x800203FC: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x80020400: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x80020404: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x80020408: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x8002040C: jal         0x800665E8
    // 0x80020410: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    set_active_camera(rdram, ctx);
        goto after_26;
    // 0x80020410: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    after_26:
    // 0x80020414: jal         0x80069CFC
    // 0x80020418: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_27;
    // 0x80020418: nop

    after_27:
    // 0x8002041C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80020420: lw          $a2, -0x518C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X518C);
    // 0x80020424: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x80020428: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8002042C: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80020430: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80020434: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80020438: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8002043C: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80020440: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80020444: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80020448: b           L_80020450
    // 0x8002044C: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
        goto L_80020450;
    // 0x8002044C: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
L_80020450:
    // 0x80020450: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80020454: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020458: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x8002045C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80020460: nop

    // 0x80020464: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x80020468: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8002046C: nop

    // 0x80020470: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x80020474: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80020478: nop

    // 0x8002047C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80020480: nop

    // 0x80020484: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80020488: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x8002048C: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80020490: nop

    // 0x80020494: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80020498: nop

    // 0x8002049C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800204A0: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800204A4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800204A8: nop

    // 0x800204AC: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800204B0: nop

    // 0x800204B4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800204B8: nop

    // 0x800204BC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800204C0: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800204C4: lb          $t6, 0x22($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X22);
    // 0x800204C8: nop

    // 0x800204CC: bne         $t6, $at, L_800204E4
    if (ctx->r14 != ctx->r1) {
        // 0x800204D0: nop
    
            goto L_800204E4;
    }
    // 0x800204D0: nop

    // 0x800204D4: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800204D8: nop

    // 0x800204DC: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800204E0: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
L_800204E4:
    // 0x800204E4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800204E8: nop

    // 0x800204EC: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800204F0: nop

    // 0x800204F4: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_800204F8:
    // 0x800204F8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800204FC: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80020500: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80020504: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80020508: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x8002050C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80020510: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80020514: bne         $a3, $s2, L_8001FFE0
    if (ctx->r7 != ctx->r18) {
        // 0x80020518: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001FFE0;
    }
    // 0x80020518: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002051C: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80020520: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80020524: c.eq.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl == ctx->f10.fl;
    // 0x80020528: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002052C: bc1f        L_80020544
    if (!c1cs) {
        // 0x80020530: addiu       $s1, $sp, 0x154
        ctx->r17 = ADD32(ctx->r29, 0X154);
            goto L_80020544;
    }
    // 0x80020530: addiu       $s1, $sp, 0x154
    ctx->r17 = ADD32(ctx->r29, 0X154);
    // 0x80020534: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80020538: lwc1        $f4, 0x5678($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5678);
    // 0x8002053C: nop

    // 0x80020540: swc1        $f4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f4.u32l;
L_80020544:
    // 0x80020544: lwc1        $f8, 0x4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80020548: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8002054C: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80020550: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80020554: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80020558: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002055C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80020560: add.s       $f20, $f4, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80020564: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80020568: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8002056C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x80020570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020574: bc1f        L_80020590
    if (!c1cs) {
        // 0x80020578: nop
    
            goto L_80020590;
    }
    // 0x80020578: nop

    // 0x8002057C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80020580: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80020584: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80020588: sub.d       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f0.d - ctx->f6.d;
    // 0x8002058C: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
L_80020590:
    // 0x80020590: lb          $t7, 0x3F($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X3F);
    // 0x80020594: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020598: bne         $t7, $zero, L_800205DC
    if (ctx->r15 != 0) {
        // 0x8002059C: nop
    
            goto L_800205DC;
    }
    // 0x8002059C: nop

    // 0x800205A0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205A4: jal         0x80022540
    // 0x800205A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_28;
    // 0x800205A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_28:
    // 0x800205AC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205B0: swc1        $f0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f0.u32l;
    // 0x800205B4: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x800205B8: jal         0x80022540
    // 0x800205BC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_29;
    // 0x800205BC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_29:
    // 0x800205C0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205C4: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x800205C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800205CC: jal         0x80022540
    // 0x800205D0: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_30;
    // 0x800205D0: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    after_30:
    // 0x800205D4: b           L_80020614
    // 0x800205D8: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
        goto L_80020614;
    // 0x800205D8: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
L_800205DC:
    // 0x800205DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205E0: jal         0x80022888
    // 0x800205E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lerp(rdram, ctx);
        goto after_31;
    // 0x800205E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_31:
    // 0x800205E8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205EC: swc1        $f0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f0.u32l;
    // 0x800205F0: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x800205F4: jal         0x80022888
    // 0x800205F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lerp(rdram, ctx);
        goto after_32;
    // 0x800205F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_32:
    // 0x800205FC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020600: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x80020604: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020608: jal         0x80022888
    // 0x8002060C: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_33;
    // 0x8002060C: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x80020610: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
L_80020614:
    // 0x80020614: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020618: lwc1        $f8, 0xC($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0XC);
    // 0x8002061C: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80020620: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80020624: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020628: swc1        $f6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f6.u32l;
    // 0x8002062C: lwc1        $f10, 0x10($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80020630: nop

    // 0x80020634: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80020638: swc1        $f8, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f8.u32l;
    // 0x8002063C: lwc1        $f4, 0x14($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80020640: nop

    // 0x80020644: sub.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80020648: beq         $s0, $at, L_800206A4
    if (ctx->r16 == ctx->r1) {
        // 0x8002064C: swc1        $f10, 0x11C($sp)
        MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
            goto L_800206A4;
    }
    // 0x8002064C: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
    // 0x80020650: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80020654: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80020658: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002065C: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80020660: nop

    // 0x80020664: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80020668: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002066C: jal         0x800C9AD0
    // 0x80020670: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_34;
    // 0x80020670: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_34:
    // 0x80020674: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80020678: nop

    // 0x8002067C: div.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80020680: c.eq.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl == ctx->f2.fl;
    // 0x80020684: nop

    // 0x80020688: bc1t        L_800206A4
    if (c1cs) {
        // 0x8002068C: nop
    
            goto L_800206A4;
    }
    // 0x8002068C: nop

    // 0x80020690: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80020694: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80020698: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8002069C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800206A0: swc1        $f4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f4.u32l;
L_800206A4:
    // 0x800206A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800206A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800206AC: bne         $s0, $at, L_80020544
    if (ctx->r16 != ctx->r1) {
        // 0x800206B0: nop
    
            goto L_80020544;
    }
    // 0x800206B0: nop

    // 0x800206B4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800206B8: addiu       $a0, $sp, 0xF4
    ctx->r4 = ADD32(ctx->r29, 0XF4);
    // 0x800206BC: jal         0x80022540
    // 0x800206C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_35;
    // 0x800206C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_35:
    // 0x800206C4: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800206C8: lw          $t9, 0x40($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X40);
    // 0x800206CC: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800206D0: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800206D4: nop

    // 0x800206D8: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800206DC: beq         $s2, $zero, L_80020770
    if (ctx->r18 == 0) {
        // 0x800206E0: swc1        $f4, 0x8($s6)
        MEM_W(0X8, ctx->r22) = ctx->f4.u32l;
            goto L_80020770;
    }
    // 0x800206E0: swc1        $f4, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f4.u32l;
    // 0x800206E4: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x800206E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800206EC: bne         $t6, $at, L_80020770
    if (ctx->r14 != ctx->r1) {
        // 0x800206F0: nop
    
            goto L_80020770;
    }
    // 0x800206F0: nop

    // 0x800206F4: lh          $t8, 0x26($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X26);
    // 0x800206F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800206FC: addiu       $t7, $t8, 0x2
    ctx->r15 = ADD32(ctx->r24, 0X2);
    // 0x80020700: bne         $s5, $t7, L_80020770
    if (ctx->r21 != ctx->r15) {
        // 0x80020704: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80020770;
    }
    // 0x80020704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020708: jal         0x80022540
    // 0x8002070C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    catmull_rom_interpolation(rdram, ctx);
        goto after_36;
    // 0x8002070C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_36:
    // 0x80020710: swc1        $f0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f0.u32l;
    // 0x80020714: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x80020718: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002071C: jal         0x80022540
    // 0x80020720: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    catmull_rom_interpolation(rdram, ctx);
        goto after_37;
    // 0x80020720: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_37:
    // 0x80020724: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x80020728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002072C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80020730: jal         0x80022540
    // 0x80020734: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_38;
    // 0x80020734: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    after_38:
    // 0x80020738: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
    // 0x8002073C: lwc1        $f10, 0xC($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80020740: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020744: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80020748: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8002074C: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x80020750: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80020754: nop

    // 0x80020758: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002075C: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x80020760: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80020764: nop

    // 0x80020768: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8002076C: swc1        $f4, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f4.u32l;
L_80020770:
    // 0x80020770: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020774: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80020778: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8002077C: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80020780: swc1        $f8, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->f8.u32l;
    // 0x80020784: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80020788: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8002078C: nop

    // 0x80020790: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80020794: swc1        $f10, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->f10.u32l;
    // 0x80020798: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8002079C: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800207A0: nop

    // 0x800207A4: div.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800207A8: swc1        $f6, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->f6.u32l;
    // 0x800207AC: lw          $a3, 0x11C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X11C);
    // 0x800207B0: lw          $a2, 0x120($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X120);
    // 0x800207B4: lw          $a1, 0x124($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X124);
    // 0x800207B8: jal         0x80011570
    // 0x800207BC: nop

    move_object(rdram, ctx);
        goto after_39;
    // 0x800207BC: nop

    after_39:
    // 0x800207C0: lbu         $v1, 0x2E($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X2E);
    // 0x800207C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800207C8: beq         $v1, $at, L_80020D38
    if (ctx->r3 == ctx->r1) {
        // 0x800207CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80020D38;
    }
    // 0x800207CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800207D0: beq         $v1, $at, L_800207E8
    if (ctx->r3 == ctx->r1) {
        // 0x800207D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800207E8;
    }
    // 0x800207D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800207D8: beq         $v1, $at, L_80020D38
    if (ctx->r3 == ctx->r1) {
        // 0x800207DC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80020D38;
    }
    // 0x800207DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800207E0: b           L_80020920
    // 0x800207E4: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
        goto L_80020920;
    // 0x800207E4: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
L_800207E8:
    // 0x800207E8: lb          $t9, 0x3F($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X3F);
    // 0x800207EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800207F0: bne         $t9, $zero, L_8002083C
    if (ctx->r25 != 0) {
        // 0x800207F4: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_8002083C;
    }
    // 0x800207F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800207F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800207FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020800: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020804: jal         0x8002263C
    // 0x80020808: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    cubic_spline_interpolation(rdram, ctx);
        goto after_40;
    // 0x80020808: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    after_40:
    // 0x8002080C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020810: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x80020814: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020818: jal         0x8002263C
    // 0x8002081C: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    cubic_spline_interpolation(rdram, ctx);
        goto after_41;
    // 0x8002081C: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    after_41:
    // 0x80020820: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020824: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x80020828: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002082C: jal         0x8002263C
    // 0x80020830: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_42;
    // 0x80020830: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    after_42:
    // 0x80020834: b           L_80020874
    // 0x80020838: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
        goto L_80020874;
    // 0x80020838: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
L_8002083C:
    // 0x8002083C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020840: jal         0x800228B0
    // 0x80020844: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    lerp_and_get_derivative(rdram, ctx);
        goto after_43;
    // 0x80020844: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    after_43:
    // 0x80020848: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8002084C: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x80020850: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020854: jal         0x800228B0
    // 0x80020858: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    lerp_and_get_derivative(rdram, ctx);
        goto after_44;
    // 0x80020858: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    after_44:
    // 0x8002085C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020860: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x80020864: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020868: jal         0x800228B0
    // 0x8002086C: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    lerp_and_get_derivative(rdram, ctx);
        goto after_45;
    // 0x8002086C: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    after_45:
    // 0x80020870: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
L_80020874:
    // 0x80020874: lwc1        $f2, 0x120($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80020878: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8002087C: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80020880: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80020884: nop

    // 0x80020888: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8002088C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80020890: jal         0x800C9AD0
    // 0x80020894: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_46;
    // 0x80020894: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_46:
    // 0x80020898: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x8002089C: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x800208A0: bc1t        L_800208E8
    if (c1cs) {
        // 0x800208A4: nop
    
            goto L_800208E8;
    }
    // 0x800208A4: nop

    // 0x800208A8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800208AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800208B0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800208B4: nop

    // 0x800208B8: div.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x800208BC: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800208C0: lwc1        $f2, 0x120($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800208C4: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800208C8: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800208CC: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800208D0: nop

    // 0x800208D4: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800208D8: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x800208DC: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800208E0: swc1        $f2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f2.u32l;
    // 0x800208E4: swc1        $f14, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f14.u32l;
L_800208E8:
    // 0x800208E8: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800208EC: lwc1        $f12, 0x124($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800208F0: jal         0x80070750
    // 0x800208F4: nop

    arctan2_f(rdram, ctx);
        goto after_47;
    // 0x800208F4: nop

    after_47:
    // 0x800208F8: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800208FC: addu        $t6, $v0, $at
    ctx->r14 = ADD32(ctx->r2, ctx->r1);
    // 0x80020900: sh          $t6, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r14;
    // 0x80020904: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80020908: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002090C: lwc1        $f12, 0x120($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80020910: jal         0x80070750
    // 0x80020914: nop

    arctan2_f(rdram, ctx);
        goto after_48;
    // 0x80020914: nop

    after_48:
    // 0x80020918: b           L_80020D38
    // 0x8002091C: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
        goto L_80020D38;
    // 0x8002091C: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
L_80020920:
    // 0x80020920: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x80020924: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80020928: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8002092C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80020930: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80020934: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x80020938: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002093C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80020940: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80020944: addiu       $t4, $sp, 0xD0
    ctx->r12 = ADD32(ctx->r29, 0XD0);
    // 0x80020948: addiu       $ra, $sp, 0xBC
    ctx->r31 = ADD32(ctx->r29, 0XBC);
    // 0x8002094C: addiu       $a3, $sp, 0xCC
    ctx->r7 = ADD32(ctx->r29, 0XCC);
    // 0x80020950: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x80020954: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
L_80020958:
    // 0x80020958: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8002095C: lwc1        $f6, -0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, -0X4);
    // 0x80020960: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80020964: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80020968: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8002096C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80020970: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x80020974: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x80020978: bc1f        L_80020990
    if (!c1cs) {
        // 0x8002097C: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_80020990;
    }
    // 0x8002097C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80020980: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80020984: sub.d       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f10.d - ctx->f14.d;
    // 0x80020988: b           L_800209AC
    // 0x8002098C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_800209AC;
    // 0x8002098C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80020990:
    // 0x80020990: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x80020994: nop

    // 0x80020998: bc1f        L_800209AC
    if (!c1cs) {
        // 0x8002099C: nop
    
            goto L_800209AC;
    }
    // 0x8002099C: nop

    // 0x800209A0: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x800209A4: add.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f4.d + ctx->f14.d;
    // 0x800209A8: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_800209AC:
    // 0x800209AC: beq         $at, $zero, L_80020A38
    if (ctx->r1 == 0) {
        // 0x800209B0: or          $s0, $t0, $zero
        ctx->r16 = ctx->r8 | 0;
            goto L_80020A38;
    }
    // 0x800209B0: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800209B4: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    // 0x800209B8: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x800209BC: beq         $t7, $zero, L_800209F0
    if (ctx->r15 == 0) {
        // 0x800209C0: addu        $v1, $t7, $t0
        ctx->r3 = ADD32(ctx->r15, ctx->r8);
            goto L_800209F0;
    }
    // 0x800209C0: addu        $v1, $t7, $t0
    ctx->r3 = ADD32(ctx->r15, ctx->r8);
    // 0x800209C4: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800209C8: addiu       $t6, $sp, 0xE0
    ctx->r14 = ADD32(ctx->r29, 0XE0);
    // 0x800209CC: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
L_800209D0:
    // 0x800209D0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800209D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800209D8: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800209DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800209E0: bne         $v1, $s0, L_800209D0
    if (ctx->r3 != ctx->r16) {
        // 0x800209E4: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_800209D0;
    }
    // 0x800209E4: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800209E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800209EC: beq         $s0, $at, L_80020A34
    if (ctx->r16 == ctx->r1) {
        // 0x800209F0: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_80020A34;
    }
L_800209F0:
    // 0x800209F0: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800209F4: addiu       $t7, $sp, 0xE0
    ctx->r15 = ADD32(ctx->r29, 0XE0);
    // 0x800209F8: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
L_800209FC:
    // 0x800209FC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020A00: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80020A04: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020A08: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020A0C: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020A10: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80020A14: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020A18: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80020A1C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020A20: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80020A24: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020A28: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80020A2C: bne         $v0, $a1, L_800209FC
    if (ctx->r2 != ctx->r5) {
        // 0x80020A30: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_800209FC;
    }
    // 0x80020A30: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80020A34:
    // 0x80020A34: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80020A38:
    // 0x80020A38: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80020A3C: lwc1        $f6, -0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, -0X4);
    // 0x80020A40: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80020A44: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80020A48: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80020A4C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80020A50: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x80020A54: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x80020A58: bc1f        L_80020A70
    if (!c1cs) {
        // 0x80020A5C: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_80020A70;
    }
    // 0x80020A5C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80020A60: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80020A64: sub.d       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f10.d - ctx->f14.d;
    // 0x80020A68: b           L_80020A8C
    // 0x80020A6C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_80020A8C;
    // 0x80020A6C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80020A70:
    // 0x80020A70: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x80020A74: nop

    // 0x80020A78: bc1f        L_80020A8C
    if (!c1cs) {
        // 0x80020A7C: nop
    
            goto L_80020A8C;
    }
    // 0x80020A7C: nop

    // 0x80020A80: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x80020A84: add.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f4.d + ctx->f14.d;
    // 0x80020A88: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80020A8C:
    // 0x80020A8C: beq         $at, $zero, L_80020B14
    if (ctx->r1 == 0) {
        // 0x80020A90: subu        $a0, $t9, $t0
        ctx->r4 = SUB32(ctx->r25, ctx->r8);
            goto L_80020B14;
    }
    // 0x80020A90: subu        $a0, $t9, $t0
    ctx->r4 = SUB32(ctx->r25, ctx->r8);
    // 0x80020A94: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x80020A98: beq         $t6, $zero, L_80020ACC
    if (ctx->r14 == 0) {
        // 0x80020A9C: addu        $v1, $t6, $t0
        ctx->r3 = ADD32(ctx->r14, ctx->r8);
            goto L_80020ACC;
    }
    // 0x80020A9C: addu        $v1, $t6, $t0
    ctx->r3 = ADD32(ctx->r14, ctx->r8);
    // 0x80020AA0: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80020AA4: addiu       $t7, $sp, 0xCC
    ctx->r15 = ADD32(ctx->r29, 0XCC);
    // 0x80020AA8: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
L_80020AAC:
    // 0x80020AAC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020AB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020AB4: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020AB8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020ABC: bne         $v1, $s0, L_80020AAC
    if (ctx->r3 != ctx->r16) {
        // 0x80020AC0: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020AAC;
    }
    // 0x80020AC0: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020AC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020AC8: beq         $s0, $at, L_80020B10
    if (ctx->r16 == ctx->r1) {
        // 0x80020ACC: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_80020B10;
    }
L_80020ACC:
    // 0x80020ACC: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80020AD0: addiu       $t6, $sp, 0xCC
    ctx->r14 = ADD32(ctx->r29, 0XCC);
    // 0x80020AD4: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
L_80020AD8:
    // 0x80020AD8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020ADC: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80020AE0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020AE4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020AE8: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020AEC: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80020AF0: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020AF4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80020AF8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020AFC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80020B00: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020B04: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80020B08: bne         $v0, $a2, L_80020AD8
    if (ctx->r2 != ctx->r6) {
        // 0x80020B0C: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020AD8;
    }
    // 0x80020B0C: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80020B10:
    // 0x80020B10: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80020B14:
    // 0x80020B14: lwc1        $f4, 0x0($ra)
    ctx->f4.u32l = MEM_W(ctx->r31, 0X0);
    // 0x80020B18: lwc1        $f6, -0x4($ra)
    ctx->f6.u32l = MEM_W(ctx->r31, -0X4);
    // 0x80020B1C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80020B20: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80020B24: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    // 0x80020B28: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80020B2C: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x80020B30: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x80020B34: bc1f        L_80020B4C
    if (!c1cs) {
        // 0x80020B38: slti        $at, $t0, 0x5
        ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
            goto L_80020B4C;
    }
    // 0x80020B38: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80020B3C: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80020B40: sub.d       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f10.d - ctx->f14.d;
    // 0x80020B44: b           L_80020B68
    // 0x80020B48: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_80020B68;
    // 0x80020B48: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80020B4C:
    // 0x80020B4C: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x80020B50: nop

    // 0x80020B54: bc1f        L_80020B68
    if (!c1cs) {
        // 0x80020B58: nop
    
            goto L_80020B68;
    }
    // 0x80020B58: nop

    // 0x80020B5C: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x80020B60: add.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f4.d + ctx->f14.d;
    // 0x80020B64: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80020B68:
    // 0x80020B68: beq         $at, $zero, L_80020BE8
    if (ctx->r1 == 0) {
        // 0x80020B6C: andi        $t7, $a0, 0x3
        ctx->r15 = ctx->r4 & 0X3;
            goto L_80020BE8;
    }
    // 0x80020B6C: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x80020B70: beq         $t7, $zero, L_80020BA4
    if (ctx->r15 == 0) {
        // 0x80020B74: addu        $v1, $t7, $t0
        ctx->r3 = ADD32(ctx->r15, ctx->r8);
            goto L_80020BA4;
    }
    // 0x80020B74: addu        $v1, $t7, $t0
    ctx->r3 = ADD32(ctx->r15, ctx->r8);
    // 0x80020B78: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80020B7C: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x80020B80: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
L_80020B84:
    // 0x80020B84: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020B88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020B8C: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020B90: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020B94: bne         $v1, $s0, L_80020B84
    if (ctx->r3 != ctx->r16) {
        // 0x80020B98: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020B84;
    }
    // 0x80020B98: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020B9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020BA0: beq         $s0, $at, L_80020BE8
    if (ctx->r16 == ctx->r1) {
        // 0x80020BA4: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_80020BE8;
    }
L_80020BA4:
    // 0x80020BA4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80020BA8: addiu       $t7, $sp, 0xB8
    ctx->r15 = ADD32(ctx->r29, 0XB8);
    // 0x80020BAC: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
L_80020BB0:
    // 0x80020BB0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020BB4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80020BB8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020BBC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020BC0: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020BC4: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80020BC8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020BCC: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80020BD0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020BD4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80020BD8: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020BDC: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80020BE0: bne         $v0, $a3, L_80020BB0
    if (ctx->r2 != ctx->r7) {
        // 0x80020BE4: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020BB0;
    }
    // 0x80020BE4: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80020BE8:
    // 0x80020BE8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80020BEC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020BF0: bne         $t0, $at, L_80020958
    if (ctx->r8 != ctx->r1) {
        // 0x80020BF4: addiu       $ra, $ra, 0x4
        ctx->r31 = ADD32(ctx->r31, 0X4);
            goto L_80020958;
    }
    // 0x80020BF4: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80020BF8: lb          $t9, 0x3F($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X3F);
    // 0x80020BFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020C00: bne         $t9, $zero, L_80020CA0
    if (ctx->r25 != 0) {
        // 0x80020C04: addiu       $a0, $sp, 0xE0
        ctx->r4 = ADD32(ctx->r29, 0XE0);
            goto L_80020CA0;
    }
    // 0x80020C04: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x80020C08: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020C0C: jal         0x80022540
    // 0x80020C10: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    catmull_rom_interpolation(rdram, ctx);
        goto after_49;
    // 0x80020C10: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    after_49:
    // 0x80020C14: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80020C18: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020C1C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80020C20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020C24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020C28: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80020C2C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020C30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020C34: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80020C38: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80020C3C: jal         0x80022540
    // 0x80020C40: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    catmull_rom_interpolation(rdram, ctx);
        goto after_50;
    // 0x80020C40: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    after_50:
    // 0x80020C44: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80020C48: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020C4C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80020C50: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020C54: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020C58: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80020C5C: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020C60: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020C64: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80020C68: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80020C6C: jal         0x80022540
    // 0x80020C70: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    catmull_rom_interpolation(rdram, ctx);
        goto after_51;
    // 0x80020C70: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    after_51:
    // 0x80020C74: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80020C78: nop

    // 0x80020C7C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80020C80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020C84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020C88: nop

    // 0x80020C8C: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020C90: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80020C94: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80020C98: b           L_80020D38
    // 0x80020C9C: sh          $t8, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r24;
        goto L_80020D38;
    // 0x80020C9C: sh          $t8, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r24;
L_80020CA0:
    // 0x80020CA0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020CA4: jal         0x80022888
    // 0x80020CA8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lerp(rdram, ctx);
        goto after_52;
    // 0x80020CA8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_52:
    // 0x80020CAC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80020CB0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020CB4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80020CB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020CBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020CC0: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80020CC4: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020CC8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020CCC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80020CD0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80020CD4: jal         0x80022888
    // 0x80020CD8: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    lerp(rdram, ctx);
        goto after_53;
    // 0x80020CD8: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    after_53:
    // 0x80020CDC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80020CE0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020CE4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80020CE8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020CEC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020CF0: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80020CF4: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020CF8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020CFC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80020D00: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80020D04: jal         0x80022888
    // 0x80020D08: sh          $t8, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r24;
    lerp(rdram, ctx);
        goto after_54;
    // 0x80020D08: sh          $t8, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r24;
    after_54:
    // 0x80020D0C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80020D10: nop

    // 0x80020D14: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80020D18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020D1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020D20: nop

    // 0x80020D24: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020D28: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80020D2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80020D30: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
    // 0x80020D34: nop

L_80020D38:
    // 0x80020D38: lw          $v1, 0x168($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X168);
    // 0x80020D3C: lh          $t0, 0x26($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X26);
    // 0x80020D40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020D44: beq         $v1, $at, L_80020D5C
    if (ctx->r3 == ctx->r1) {
        // 0x80020D48: swc1        $f20, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
            goto L_80020D5C;
    }
    // 0x80020D48: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
    // 0x80020D4C: slt         $at, $t0, $s5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020D50: bne         $at, $zero, L_80020D5C
    if (ctx->r1 != 0) {
        // 0x80020D54: subu        $t6, $t0, $s5
        ctx->r14 = SUB32(ctx->r8, ctx->r21);
            goto L_80020D5C;
    }
    // 0x80020D54: subu        $t6, $t0, $s5
    ctx->r14 = SUB32(ctx->r8, ctx->r21);
    // 0x80020D58: addu        $t0, $t6, $v1
    ctx->r8 = ADD32(ctx->r14, ctx->r3);
L_80020D5C:
    // 0x80020D5C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80020D60: addiu       $t1, $t1, -0x518C
    ctx->r9 = ADD32(ctx->r9, -0X518C);
    // 0x80020D64: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80020D68: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80020D6C: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80020D70: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80020D74: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80020D78: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80020D7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80020D80: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x80020D84: lwc1        $f1, 0x5680($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5680);
    // 0x80020D88: lb          $t9, 0x14($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X14);
    // 0x80020D8C: lwc1        $f0, 0x5684($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5684);
    // 0x80020D90: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80020D94: nop

    // 0x80020D98: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80020D9C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80020DA0: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80020DA4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80020DA8: c.lt.s      $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f10.fl < ctx->f22.fl;
    // 0x80020DAC: swc1        $f10, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f10.u32l;
    // 0x80020DB0: bc1f        L_80020DC4
    if (!c1cs) {
        // 0x80020DB4: nop
    
            goto L_80020DC4;
    }
    // 0x80020DB4: nop

    // 0x80020DB8: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80020DBC: b           L_80020DD0
    // 0x80020DC0: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
        goto L_80020DD0;
    // 0x80020DC0: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
L_80020DC4:
    // 0x80020DC4: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020DC8: nop

    // 0x80020DCC: swc1        $f4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f4.u32l;
L_80020DD0:
    // 0x80020DD0: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020DD4: nop

    // 0x80020DD8: c.le.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl <= ctx->f6.fl;
    // 0x80020DDC: nop

    // 0x80020DE0: bc1f        L_80020E88
    if (!c1cs) {
        // 0x80020DE4: nop
    
            goto L_80020E88;
    }
    // 0x80020DE4: nop

    // 0x80020DE8: bne         $s2, $zero, L_80020E88
    if (ctx->r18 != 0) {
        // 0x80020DEC: addiu       $v0, $t0, 0x1
        ctx->r2 = ADD32(ctx->r8, 0X1);
            goto L_80020E88;
    }
    // 0x80020DEC: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x80020DF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020DF4: beq         $v1, $at, L_80020E0C
    if (ctx->r3 == ctx->r1) {
        // 0x80020DF8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80020E0C;
    }
    // 0x80020DF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80020DFC: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020E00: bne         $at, $zero, L_80020E0C
    if (ctx->r1 != 0) {
        // 0x80020E04: subu        $t6, $v0, $s5
        ctx->r14 = SUB32(ctx->r2, ctx->r21);
            goto L_80020E0C;
    }
    // 0x80020E04: subu        $t6, $v0, $s5
    ctx->r14 = SUB32(ctx->r2, ctx->r21);
    // 0x80020E08: addu        $s0, $t6, $v1
    ctx->r16 = ADD32(ctx->r14, ctx->r3);
L_80020E0C:
    // 0x80020E0C: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020E10: beq         $at, $zero, L_80020E6C
    if (ctx->r1 == 0) {
        // 0x80020E14: sll         $t7, $s4, 2
        ctx->r15 = S32(ctx->r20 << 2);
            goto L_80020E6C;
    }
    // 0x80020E14: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80020E18: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80020E1C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80020E20: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80020E24: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80020E28: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80020E2C: lwc1        $f14, 0x124($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020E30: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x80020E34: nop

    // 0x80020E38: lb          $v0, 0x14($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X14);
    // 0x80020E3C: nop

    // 0x80020E40: bltz        $v0, L_80020E68
    if (SIGNED(ctx->r2) < 0) {
        // 0x80020E44: nop
    
            goto L_80020E68;
    }
    // 0x80020E44: nop

    // 0x80020E48: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80020E4C: nop

    // 0x80020E50: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80020E54: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80020E58: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80020E5C: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80020E60: b           L_80020E6C
    // 0x80020E64: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
        goto L_80020E6C;
    // 0x80020E64: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
L_80020E68:
    // 0x80020E68: swc1        $f14, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f14.u32l;
L_80020E6C:
    // 0x80020E6C: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80020E70: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020E74: nop

    // 0x80020E78: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80020E7C: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80020E80: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80020E84: swc1        $f8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f8.u32l;
L_80020E88:
    // 0x80020E88: beq         $s2, $zero, L_80020F48
    if (ctx->r18 == 0) {
        // 0x80020E8C: nop
    
            goto L_80020F48;
    }
    // 0x80020E8C: nop

    // 0x80020E90: lh          $t9, 0x26($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X26);
    // 0x80020E94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020E98: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80020E9C: bne         $v1, $at, L_80020EF0
    if (ctx->r3 != ctx->r1) {
        // 0x80020EA0: sh          $t6, 0x26($s3)
        MEM_H(0X26, ctx->r19) = ctx->r14;
            goto L_80020EF0;
    }
    // 0x80020EA0: sh          $t6, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r14;
    // 0x80020EA4: lh          $v0, 0x26($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X26);
    // 0x80020EA8: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x80020EAC: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020EB0: bne         $at, $zero, L_80020EC4
    if (ctx->r1 != 0) {
        // 0x80020EB4: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80020EC4;
    }
    // 0x80020EB4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80020EB8: addiu       $t8, $s5, -0x1
    ctx->r24 = ADD32(ctx->r21, -0X1);
    // 0x80020EBC: b           L_80020F48
    // 0x80020EC0: sh          $t8, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r24;
        goto L_80020F48;
    // 0x80020EC0: sh          $t8, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r24;
L_80020EC4:
    // 0x80020EC4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80020EC8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80020ECC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80020ED0: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80020ED4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80020ED8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80020EDC: lw          $a1, 0x3C($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X3C);
    // 0x80020EE0: jal         0x8002125C
    // 0x80020EE4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8002125C(rdram, ctx);
        goto after_55;
    // 0x80020EE4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_55:
    // 0x80020EE8: b           L_80020F4C
    // 0x80020EEC: lbu         $t7, 0x2E($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X2E);
        goto L_80020F4C;
    // 0x80020EEC: lbu         $t7, 0x2E($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X2E);
L_80020EF0:
    // 0x80020EF0: lh          $v0, 0x26($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X26);
    // 0x80020EF4: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80020EF8: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80020EFC: beq         $at, $zero, L_80020F10
    if (ctx->r1 == 0) {
        // 0x80020F00: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80020F10;
    }
    // 0x80020F00: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80020F04: sh          $t6, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r14;
    // 0x80020F08: lh          $v0, 0x26($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X26);
    // 0x80020F0C: nop

L_80020F10:
    // 0x80020F10: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020F14: bne         $at, $zero, L_80020F24
    if (ctx->r1 != 0) {
        // 0x80020F18: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80020F24;
    }
    // 0x80020F18: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80020F1C: subu        $t8, $v0, $s5
    ctx->r24 = SUB32(ctx->r2, ctx->r21);
    // 0x80020F20: addu        $s2, $t8, $v1
    ctx->r18 = ADD32(ctx->r24, ctx->r3);
L_80020F24:
    // 0x80020F24: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80020F28: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
    // 0x80020F2C: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80020F30: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80020F34: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80020F38: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80020F3C: lw          $a1, 0x3C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X3C);
    // 0x80020F40: jal         0x8002125C
    // 0x80020F44: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8002125C(rdram, ctx);
        goto after_56;
    // 0x80020F44: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_56:
L_80020F48:
    // 0x80020F48: lbu         $t7, 0x2E($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X2E);
L_80020F4C:
    // 0x80020F4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80020F50: bne         $t7, $at, L_80021078
    if (ctx->r15 != ctx->r1) {
        // 0x80020F54: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80021078;
    }
    // 0x80020F54: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80020F58: lh          $v1, -0x5188($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X5188);
    // 0x80020F5C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80020F60: blez        $v1, L_80020FB8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80020F64: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80020FB8;
    }
    // 0x80020F64: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80020F68: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80020F6C: lw          $a2, -0x518C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X518C);
    // 0x80020F70: lb          $v0, 0x3E($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X3E);
    // 0x80020F74: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80020F78: nop

    // 0x80020F7C: lw          $t6, 0x7C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X7C);
    // 0x80020F80: nop

    // 0x80020F84: beq         $v0, $t6, L_80020FB8
    if (ctx->r2 == ctx->r14) {
        // 0x80020F88: nop
    
            goto L_80020FB8;
    }
    // 0x80020F88: nop

L_80020F8C:
    // 0x80020F8C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80020F90: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80020F94: beq         $at, $zero, L_80020FB8
    if (ctx->r1 == 0) {
        // 0x80020F98: sll         $t8, $t0, 2
        ctx->r24 = S32(ctx->r8 << 2);
            goto L_80020FB8;
    }
    // 0x80020F98: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80020F9C: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x80020FA0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80020FA4: nop

    // 0x80020FA8: lw          $t6, 0x7C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X7C);
    // 0x80020FAC: nop

    // 0x80020FB0: bne         $v0, $t6, L_80020F8C
    if (ctx->r2 != ctx->r14) {
        // 0x80020FB4: nop
    
            goto L_80020F8C;
    }
    // 0x80020FB4: nop

L_80020FB8:
    // 0x80020FB8: beq         $t0, $v1, L_80021078
    if (ctx->r8 == ctx->r3) {
        // 0x80020FBC: addiu       $t1, $t1, -0x518C
        ctx->r9 = ADD32(ctx->r9, -0X518C);
            goto L_80021078;
    }
    // 0x80020FBC: addiu       $t1, $t1, -0x518C
    ctx->r9 = ADD32(ctx->r9, -0X518C);
    // 0x80020FC0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80020FC4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80020FC8: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80020FCC: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80020FD0: nop

    // 0x80020FD4: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x80020FD8: nop

    // 0x80020FDC: beq         $v1, $zero, L_80021078
    if (ctx->r3 == 0) {
        // 0x80020FE0: nop
    
            goto L_80021078;
    }
    // 0x80020FE0: nop

    // 0x80020FE4: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80020FE8: lwc1        $f10, 0xC($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80020FEC: nop

    // 0x80020FF0: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80020FF4: swc1        $f4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f4.u32l;
    // 0x80020FF8: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80020FFC: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80021000: nop

    // 0x80021004: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80021008: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x8002100C: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80021010: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80021014: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80021018: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8002101C: lwc1        $f8, 0x120($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80021020: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80021024: swc1        $f6, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f6.u32l;
    // 0x80021028: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8002102C: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80021030: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80021034: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80021038: jal         0x800C9AD0
    // 0x8002103C: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_57;
    // 0x8002103C: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_57:
    // 0x80021040: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80021044: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80021048: bc1f        L_80021078
    if (!c1cs) {
        // 0x8002104C: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_80021078;
    }
    // 0x8002104C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80021050: lwc1        $f12, 0x124($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80021054: jal         0x80070750
    // 0x80021058: nop

    arctan2_f(rdram, ctx);
        goto after_58;
    // 0x80021058: nop

    after_58:
    // 0x8002105C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80021060: addu        $t8, $v0, $at
    ctx->r24 = ADD32(ctx->r2, ctx->r1);
    // 0x80021064: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    // 0x80021068: lwc1        $f12, 0x120($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8002106C: jal         0x80070750
    // 0x80021070: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_59;
    // 0x80021070: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_59:
    // 0x80021074: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
L_80021078:
    // 0x80021078: lb          $t7, 0x2F($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X2F);
    // 0x8002107C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80021080: sw          $t7, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->r15;
    // 0x80021084: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x80021088: jal         0x800AFC3C
    // 0x8002108C: nop

    obj_spawn_particle(rdram, ctx);
        goto after_60;
    // 0x8002108C: nop

    after_60:
    // 0x80021090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80021094:
    // 0x80021094: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80021098:
    // 0x80021098: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002109C: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800210A0: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800210A4: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800210A8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800210AC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800210B0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800210B4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800210B8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800210BC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800210C0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800210C4: jr          $ra
    // 0x800210C8: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
    return;
    // 0x800210C8: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
;}
RECOMP_FUNC void get_inside_segment_count_xz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A05C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002A060: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8002A064: lw          $a3, -0x36E8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X36E8);
    // 0x8002A068: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002A06C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002A070: lh          $t0, 0x1A($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X1A);
    // 0x8002A074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002A078: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8002A07C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002A080: blez        $t0, L_8002A120
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8002A084: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002A120;
    }
    // 0x8002A084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002A088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8002A08C:
    // 0x8002A08C: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x8002A090: nop

    // 0x8002A094: addu        $a0, $t6, $a1
    ctx->r4 = ADD32(ctx->r14, ctx->r5);
    // 0x8002A098: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8002A09C: nop

    // 0x8002A0A0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8002A0A4: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002A0A8: beq         $at, $zero, L_8002A110
    if (ctx->r1 == 0) {
        // 0x8002A0AC: nop
    
            goto L_8002A110;
    }
    // 0x8002A0AC: nop

    // 0x8002A0B0: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x8002A0B4: nop

    // 0x8002A0B8: addiu       $t1, $t9, -0x4
    ctx->r9 = ADD32(ctx->r25, -0X4);
    // 0x8002A0BC: slt         $at, $t1, $s0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002A0C0: beq         $at, $zero, L_8002A110
    if (ctx->r1 == 0) {
        // 0x8002A0C4: nop
    
            goto L_8002A110;
    }
    // 0x8002A0C4: nop

    // 0x8002A0C8: lh          $t2, 0xA($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XA);
    // 0x8002A0CC: nop

    // 0x8002A0D0: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8002A0D4: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002A0D8: beq         $at, $zero, L_8002A110
    if (ctx->r1 == 0) {
        // 0x8002A0DC: nop
    
            goto L_8002A110;
    }
    // 0x8002A0DC: nop

    // 0x8002A0E0: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
    // 0x8002A0E4: nop

    // 0x8002A0E8: addiu       $t5, $t4, -0x4
    ctx->r13 = ADD32(ctx->r12, -0X4);
    // 0x8002A0EC: slt         $at, $t5, $s1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8002A0F0: beq         $at, $zero, L_8002A110
    if (ctx->r1 == 0) {
        // 0x8002A0F4: nop
    
            goto L_8002A110;
    }
    // 0x8002A0F4: nop

    // 0x8002A0F8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8002A0FC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8002A100: lw          $a3, -0x36E8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X36E8);
    // 0x8002A104: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A108: lh          $t0, 0x1A($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X1A);
    // 0x8002A10C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8002A110:
    // 0x8002A110: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A114: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002A118: bne         $at, $zero, L_8002A08C
    if (ctx->r1 != 0) {
        // 0x8002A11C: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8002A08C;
    }
    // 0x8002A11C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_8002A120:
    // 0x8002A120: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002A124: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002A128: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8002A12C: jr          $ra
    // 0x8002A130: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002A130: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void obj_loop_eggcreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003564C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80035650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035654: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80035658: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x8003565C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80035660: bne         $t6, $zero, L_80035720
    if (ctx->r14 != 0) {
        // 0x80035664: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035720;
    }
    // 0x80035664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035668: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003566C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80035670: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80035674: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035678: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003567C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80035680: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80035684: addiu       $t4, $zero, 0x34
    ctx->r12 = ADD32(0, 0X34);
    // 0x80035688: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003568C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80035690: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80035694: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80035698: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    // 0x8003569C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800356A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800356A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800356A8: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800356AC: nop

    // 0x800356B0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800356B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800356B8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800356BC: nop

    // 0x800356C0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800356C4: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
    // 0x800356C8: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800356CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800356D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800356D4: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800356D8: sb          $t3, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r11;
    // 0x800356DC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800356E0: sb          $t4, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r12;
    // 0x800356E4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800356E8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800356EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800356F0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800356F4: jal         0x8000EA54
    // 0x800356F8: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x800356F8: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    after_0:
    // 0x800356FC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80035700: beq         $v0, $zero, L_80035720
    if (ctx->r2 == 0) {
        // 0x80035704: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035720;
    }
    // 0x80035704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035708: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003570C: nop

    // 0x80035710: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x80035714: sw          $v0, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r2;
    // 0x80035718: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003571C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035720:
    // 0x80035720: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80035724: jr          $ra
    // 0x80035728: nop

    return;
    // 0x80035728: nop

;}
RECOMP_FUNC void charselect_prev(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AEB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008AEB8: beq         $a0, $v0, L_8008AEDC
    if (ctx->r4 == ctx->r2) {
        // 0x8008AEBC: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8008AEDC;
    }
    // 0x8008AEBC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8008AEC0: beq         $a0, $v1, L_8008AEE8
    if (ctx->r4 == ctx->r3) {
        // 0x8008AEC4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8008AEE8;
    }
    // 0x8008AEC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AEC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008AECC: beq         $a0, $at, L_8008AEDC
    if (ctx->r4 == ctx->r1) {
        // 0x8008AED0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8008AEDC;
    }
    // 0x8008AED0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AED4: jr          $ra
    // 0x8008AED8: sw          $zero, -0x30($at)
    MEM_W(-0X30, ctx->r1) = 0;
    return;
    // 0x8008AED8: sw          $zero, -0x30($at)
    MEM_W(-0X30, ctx->r1) = 0;
L_8008AEDC:
    // 0x8008AEDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AEE0: jr          $ra
    // 0x8008AEE4: sw          $v0, -0x30($at)
    MEM_W(-0X30, ctx->r1) = ctx->r2;
    return;
    // 0x8008AEE4: sw          $v0, -0x30($at)
    MEM_W(-0X30, ctx->r1) = ctx->r2;
L_8008AEE8:
    // 0x8008AEE8: sw          $v1, -0x30($at)
    MEM_W(-0X30, ctx->r1) = ctx->r3;
    // 0x8008AEEC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8008AEF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AEF4: sw          $t6, -0x2C($at)
    MEM_W(-0X2C, ctx->r1) = ctx->r14;
    // 0x8008AEF8: jr          $ra
    // 0x8008AEFC: nop

    return;
    // 0x8008AEFC: nop

;}
RECOMP_FUNC void dialogue_open_stub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E9A0: jr          $ra
    // 0x8009E9A4: nop

    return;
    // 0x8009E9A4: nop

;}
RECOMP_FUNC void get_particle_asset_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4488: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B448C: lw          $v1, 0x2CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2CE8);
    // 0x800B4490: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B4494: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B4498: beq         $at, $zero, L_800B44B8
    if (ctx->r1 == 0) {
        // 0x800B449C: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800B44B8;
    }
    // 0x800B449C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B44A0: lw          $t6, 0x2CF0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2CF0);
    // 0x800B44A4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800B44A8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B44AC: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800B44B0: jr          $ra
    // 0x800B44B4: nop

    return;
    // 0x800B44B4: nop

L_800B44B8:
    // 0x800B44B8: lw          $t9, 0x2CF0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2CF0);
    // 0x800B44BC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B44C0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B44C4: lw          $v0, -0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, -0X4);
    // 0x800B44C8: nop

    // 0x800B44CC: jr          $ra
    // 0x800B44D0: nop

    return;
    // 0x800B44D0: nop

;}
RECOMP_FUNC void update_pulsating_light_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F460: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F464: nop

    // 0x8007F468: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8007F46C: bne         $at, $zero, L_8007F58C
    if (ctx->r1 != 0) {
        // 0x8007F470: nop
    
            goto L_8007F58C;
    }
    // 0x8007F470: nop

    // 0x8007F474: lhu         $t7, 0x4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X4);
    // 0x8007F478: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x8007F47C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8007F480: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8007F484: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F488: bne         $at, $zero, L_8007F4A4
    if (ctx->r1 != 0) {
        // 0x8007F48C: sh          $t8, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r24;
            goto L_8007F4A4;
    }
    // 0x8007F48C: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
L_8007F490:
    // 0x8007F490: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x8007F494: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
    // 0x8007F498: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F49C: beq         $at, $zero, L_8007F490
    if (ctx->r1 == 0) {
        // 0x8007F4A0: sh          $t9, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r25;
            goto L_8007F490;
    }
    // 0x8007F4A0: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
L_8007F4A4:
    // 0x8007F4A4: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x8007F4A8: nop

    // 0x8007F4AC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8007F4B0: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8007F4B4: lhu         $a1, 0xE($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0XE);
    // 0x8007F4B8: nop

    // 0x8007F4BC: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F4C0: bne         $at, $zero, L_8007F510
    if (ctx->r1 != 0) {
        // 0x8007F4C4: nop
    
            goto L_8007F510;
    }
    // 0x8007F4C4: nop

L_8007F4C8:
    // 0x8007F4C8: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F4CC: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x8007F4D0: andi        $v1, $t3, 0xFFFF
    ctx->r3 = ctx->r11 & 0XFFFF;
    // 0x8007F4D4: subu        $t2, $v0, $a1
    ctx->r10 = SUB32(ctx->r2, ctx->r5);
    // 0x8007F4D8: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8007F4DC: sh          $t2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r10;
    // 0x8007F4E0: bne         $at, $zero, L_8007F4F0
    if (ctx->r1 != 0) {
        // 0x8007F4E4: sh          $t3, 0x2($a0)
        MEM_H(0X2, ctx->r4) = ctx->r11;
            goto L_8007F4F0;
    }
    // 0x8007F4E4: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x8007F4E8: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x8007F4EC: andi        $v1, $zero, 0xFFFF
    ctx->r3 = 0 & 0XFFFF;
L_8007F4F0:
    // 0x8007F4F0: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8007F4F4: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x8007F4F8: lhu         $a1, 0xE($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XE);
    // 0x8007F4FC: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x8007F500: nop

    // 0x8007F504: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F508: beq         $at, $zero, L_8007F4C8
    if (ctx->r1 == 0) {
        // 0x8007F50C: nop
    
            goto L_8007F4C8;
    }
    // 0x8007F50C: nop

L_8007F510:
    // 0x8007F510: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F514: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
    // 0x8007F518: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8007F51C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8007F520: bne         $at, $zero, L_8007F52C
    if (ctx->r1 != 0) {
        // 0x8007F524: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_8007F52C;
    }
    // 0x8007F524: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007F528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8007F52C:
    // 0x8007F52C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8007F530: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8007F534: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x8007F538: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8007F53C: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F540: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8007F544: lhu         $t3, 0xE($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0XE);
    // 0x8007F548: lhu         $t5, 0xC($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XC);
    // 0x8007F54C: mflo        $t2
    ctx->r10 = lo;
    // 0x8007F550: nop

    // 0x8007F554: nop

    // 0x8007F558: div         $zero, $t2, $t3
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r11)));
    // 0x8007F55C: bne         $t3, $zero, L_8007F568
    if (ctx->r11 != 0) {
        // 0x8007F560: nop
    
            goto L_8007F568;
    }
    // 0x8007F560: nop

    // 0x8007F564: break       7
    do_break(2148005220);
L_8007F568:
    // 0x8007F568: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007F56C: bne         $t3, $at, L_8007F580
    if (ctx->r11 != ctx->r1) {
        // 0x8007F570: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007F580;
    }
    // 0x8007F570: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F574: bne         $t2, $at, L_8007F580
    if (ctx->r10 != ctx->r1) {
        // 0x8007F578: nop
    
            goto L_8007F580;
    }
    // 0x8007F578: nop

    // 0x8007F57C: break       6
    do_break(2148005244);
L_8007F580:
    // 0x8007F580: mflo        $t4
    ctx->r12 = lo;
    // 0x8007F584: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F588: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
L_8007F58C:
    // 0x8007F58C: jr          $ra
    // 0x8007F590: nop

    return;
    // 0x8007F590: nop

;}
RECOMP_FUNC void menu_button_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FF88: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FF8C: addiu       $v0, $v0, 0x1DAC
    ctx->r2 = ADD32(ctx->r2, 0X1DAC);
    // 0x8007FF90: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8007FF94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007FF98: beq         $a0, $zero, L_8007FFB4
    if (ctx->r4 == 0) {
        // 0x8007FF9C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8007FFB4;
    }
    // 0x8007FF9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FFA0: jal         0x80071140
    // 0x8007FFA4: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8007FFA4: nop

    after_0:
    // 0x8007FFA8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FFAC: addiu       $v0, $v0, 0x1DAC
    ctx->r2 = ADD32(ctx->r2, 0X1DAC);
    // 0x8007FFB0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8007FFB4:
    // 0x8007FFB4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007FFB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007FFBC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FFC0: sw          $zero, 0x6C2C($at)
    MEM_W(0X6C2C, ctx->r1) = 0;
    // 0x8007FFC4: addiu       $v1, $v1, 0x1DA4
    ctx->r3 = ADD32(ctx->r3, 0X1DA4);
    // 0x8007FFC8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8007FFCC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007FFD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007FFD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FFD8: sw          $zero, 0x1DB8($at)
    MEM_W(0X1DB8, ctx->r1) = 0;
    // 0x8007FFDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007FFE0: sw          $zero, 0x1DBC($at)
    MEM_W(0X1DBC, ctx->r1) = 0;
    // 0x8007FFE4: jr          $ra
    // 0x8007FFE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007FFE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void transition_begin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C01D8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C01DC: lw          $t6, 0x31A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31A0);
    // 0x800C01E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C01E4: beq         $t6, $zero, L_800C01F4
    if (ctx->r14 == 0) {
        // 0x800C01E8: sw          $ra, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r31;
            goto L_800C01F4;
    }
    // 0x800C01E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C01EC: b           L_800C0484
    // 0x800C01F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0484;
    // 0x800C01F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C01F4:
    // 0x800C01F4: jal         0x800C0724
    // 0x800C01F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    transition_end(rdram, ctx);
        goto after_0;
    // 0x800C01F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C01FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800C0200: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0204: bne         $a0, $zero, L_800C0214
    if (ctx->r4 != 0) {
        // 0x800C0208: addiu       $v1, $v1, 0x31BC
        ctx->r3 = ADD32(ctx->r3, 0X31BC);
            goto L_800C0214;
    }
    // 0x800C0208: addiu       $v1, $v1, 0x31BC
    ctx->r3 = ADD32(ctx->r3, 0X31BC);
    // 0x800C020C: b           L_800C0484
    // 0x800C0210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0484;
    // 0x800C0210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0214:
    // 0x800C0214: lhu         $t7, 0x4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X4);
    // 0x800C0218: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C021C: addiu       $a2, $a2, 0x31B0
    ctx->r6 = ADD32(ctx->r6, 0X31B0);
    // 0x800C0220: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x800C0224: lhu         $t8, 0x4($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X4);
    // 0x800C0228: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C022C: sh          $t8, 0x31B8($at)
    MEM_H(0X31B8, ctx->r1) = ctx->r24;
    // 0x800C0230: lhu         $t9, 0x6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6);
    // 0x800C0234: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0238: sh          $t9, 0x31B4($at)
    MEM_H(0X31B4, ctx->r1) = ctx->r25;
    // 0x800C023C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0240: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C0244: andi        $t0, $v0, 0x80
    ctx->r8 = ctx->r2 & 0X80;
    // 0x800C0248: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800C024C: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x800C0250: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0254: addiu       $a3, $a3, -0x58D0
    ctx->r7 = ADD32(ctx->r7, -0X58D0);
    // 0x800C0258: andi        $t3, $t2, 0x3F
    ctx->r11 = ctx->r10 & 0X3F;
    // 0x800C025C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x800C0260: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0264: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0268: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x800C026C: sw          $t5, 0x31A8($at)
    MEM_W(0X31A8, ctx->r1) = ctx->r13;
    // 0x800C0270: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x800C0274: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C0278: addiu       $a1, $a1, 0x31A4
    ctx->r5 = ADD32(ctx->r5, 0X31A4);
    // 0x800C027C: bne         $t6, $zero, L_800C028C
    if (ctx->r14 != 0) {
        // 0x800C0280: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_800C028C;
    }
    // 0x800C0280: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800C0284: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800C0288: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_800C028C:
    // 0x800C028C: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800C0290: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C0294: blez        $t9, L_800C0478
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800C0298: addiu       $v0, $v0, -0x58CC
        ctx->r2 = ADD32(ctx->r2, -0X58CC);
            goto L_800C0478;
    }
    // 0x800C0298: addiu       $v0, $v0, -0x58CC
    ctx->r2 = ADD32(ctx->r2, -0X58CC);
    // 0x800C029C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x800C02A0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C02A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C02A8: addiu       $v1, $v1, -0x58CB
    ctx->r3 = ADD32(ctx->r3, -0X58CB);
    // 0x800C02AC: sw          $t0, -0x58C8($at)
    MEM_W(-0X58C8, ctx->r1) = ctx->r8;
    // 0x800C02B0: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x800C02B4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C02B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C02BC: addiu       $a1, $a1, -0x58CA
    ctx->r5 = ADD32(ctx->r5, -0X58CA);
    // 0x800C02C0: sw          $t1, -0x58C4($at)
    MEM_W(-0X58C4, ctx->r1) = ctx->r9;
    // 0x800C02C4: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
    // 0x800C02C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C02CC: sw          $t2, -0x58C0($at)
    MEM_W(-0X58C0, ctx->r1) = ctx->r10;
    // 0x800C02D0: lbu         $t3, 0x1($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1);
    // 0x800C02D4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800C02D8: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x800C02DC: lbu         $t4, 0x2($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X2);
    // 0x800C02E0: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x800C02E4: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x800C02E8: lbu         $t5, 0x3($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X3);
    // 0x800C02EC: beq         $at, $zero, L_800C0478
    if (ctx->r1 == 0) {
        // 0x800C02F0: sb          $t5, 0x0($a1)
        MEM_B(0X0, ctx->r5) = ctx->r13;
            goto L_800C0478;
    }
    // 0x800C02F0: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    // 0x800C02F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C02F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C02FC: addu        $at, $at, $t6
    gpr jr_addend_800C0308 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C0300: lw          $t6, -0x6D30($at)
    ctx->r14 = ADD32(ctx->r1, -0X6D30);
    // 0x800C0304: nop

    // 0x800C0308: jr          $t6
    // 0x800C030C: nop

    switch (jr_addend_800C0308 >> 2) {
        case 0: goto L_800C0310; break;
        case 1: goto L_800C0320; break;
        case 2: goto L_800C0370; break;
        case 3: goto L_800C03C0; break;
        case 4: goto L_800C03D0; break;
        case 5: goto L_800C0420; break;
        case 6: goto L_800C0470; break;
        default: switch_error(__func__, 0x800C0308, 0x800E92D0);
    }
    // 0x800C030C: nop

L_800C0310:
    // 0x800C0310: jal         0x800C0780
    // 0x800C0314: nop

    transition_fullscreen_start(rdram, ctx);
        goto after_1;
    // 0x800C0314: nop

    after_1:
    // 0x800C0318: b           L_800C0478
    // 0x800C031C: nop

        goto L_800C0478;
    // 0x800C031C: nop

L_800C0320:
    // 0x800C0320: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0324: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C0328: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C032C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C0330: addiu       $v0, $v0, 0x32D0
    ctx->r2 = ADD32(ctx->r2, 0X32D0);
    // 0x800C0334: addiu       $t9, $t9, 0x32B8
    ctx->r25 = ADD32(ctx->r25, 0X32B8);
    // 0x800C0338: addiu       $t8, $t8, 0x32AC
    ctx->r24 = ADD32(ctx->r24, 0X32AC);
    // 0x800C033C: addiu       $t7, $t7, 0x32A0
    ctx->r15 = ADD32(ctx->r15, 0X32A0);
    // 0x800C0340: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C0344: addiu       $a3, $a3, 0x3230
    ctx->r7 = ADD32(ctx->r7, 0X3230);
    // 0x800C0348: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C034C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800C0350: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800C0354: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C0358: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C035C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800C0360: jal         0x800C0B00
    // 0x800C0364: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    transition_init_shape(rdram, ctx);
        goto after_2;
    // 0x800C0364: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800C0368: b           L_800C0478
    // 0x800C036C: nop

        goto L_800C0478;
    // 0x800C036C: nop

L_800C0370:
    // 0x800C0370: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0374: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800C0378: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C037C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C0380: addiu       $v0, $v0, 0x32D0
    ctx->r2 = ADD32(ctx->r2, 0X32D0);
    // 0x800C0384: addiu       $t2, $t2, 0x32B8
    ctx->r10 = ADD32(ctx->r10, 0X32B8);
    // 0x800C0388: addiu       $t1, $t1, 0x32AC
    ctx->r9 = ADD32(ctx->r9, 0X32AC);
    // 0x800C038C: addiu       $t0, $t0, 0x32A0
    ctx->r8 = ADD32(ctx->r8, 0X32A0);
    // 0x800C0390: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C0394: addiu       $a3, $a3, 0x3268
    ctx->r7 = ADD32(ctx->r7, 0X3268);
    // 0x800C0398: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C039C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800C03A0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800C03A4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C03A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C03AC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800C03B0: jal         0x800C0B00
    // 0x800C03B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    transition_init_shape(rdram, ctx);
        goto after_3;
    // 0x800C03B4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x800C03B8: b           L_800C0478
    // 0x800C03BC: nop

        goto L_800C0478;
    // 0x800C03BC: nop

L_800C03C0:
    // 0x800C03C0: jal         0x800C15D4
    // 0x800C03C4: nop

    transition_init_circle(rdram, ctx);
        goto after_4;
    // 0x800C03C4: nop

    after_4:
    // 0x800C03C8: b           L_800C0478
    // 0x800C03CC: nop

        goto L_800C0478;
    // 0x800C03CC: nop

L_800C03D0:
    // 0x800C03D0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C03D4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800C03D8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C03DC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C03E0: addiu       $v0, $v0, 0x34F8
    ctx->r2 = ADD32(ctx->r2, 0X34F8);
    // 0x800C03E4: addiu       $t5, $t5, 0x3554
    ctx->r13 = ADD32(ctx->r13, 0X3554);
    // 0x800C03E8: addiu       $t4, $t4, 0x3440
    ctx->r12 = ADD32(ctx->r12, 0X3440);
    // 0x800C03EC: addiu       $t3, $t3, 0x349C
    ctx->r11 = ADD32(ctx->r11, 0X349C);
    // 0x800C03F0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C03F4: addiu       $a3, $a3, 0x3344
    ctx->r7 = ADD32(ctx->r7, 0X3344);
    // 0x800C03F8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800C03FC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800C0400: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800C0404: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C0408: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C040C: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x800C0410: jal         0x800C0B00
    // 0x800C0414: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    transition_init_shape(rdram, ctx);
        goto after_5;
    // 0x800C0414: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_5:
    // 0x800C0418: b           L_800C0478
    // 0x800C041C: nop

        goto L_800C0478;
    // 0x800C041C: nop

L_800C0420:
    // 0x800C0420: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0424: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C0428: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C042C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C0430: addiu       $v0, $v0, 0x3338
    ctx->r2 = ADD32(ctx->r2, 0X3338);
    // 0x800C0434: addiu       $t8, $t8, 0x3324
    ctx->r24 = ADD32(ctx->r24, 0X3324);
    // 0x800C0438: addiu       $t7, $t7, 0x3318
    ctx->r15 = ADD32(ctx->r15, 0X3318);
    // 0x800C043C: addiu       $t6, $t6, 0x330C
    ctx->r14 = ADD32(ctx->r14, 0X330C);
    // 0x800C0440: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C0444: addiu       $a3, $a3, 0x32DC
    ctx->r7 = ADD32(ctx->r7, 0X32DC);
    // 0x800C0448: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C044C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C0450: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800C0454: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C0458: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C045C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C0460: jal         0x800C0B00
    // 0x800C0464: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    transition_init_shape(rdram, ctx);
        goto after_6;
    // 0x800C0464: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_6:
    // 0x800C0468: b           L_800C0478
    // 0x800C046C: nop

        goto L_800C0478;
    // 0x800C046C: nop

L_800C0470:
    // 0x800C0470: jal         0x800C2640
    // 0x800C0474: nop

    transition_init_blank(rdram, ctx);
        goto after_7;
    // 0x800C0474: nop

    after_7:
L_800C0478:
    // 0x800C0478: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C047C: lw          $v0, 0x31AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31AC);
    // 0x800C0480: nop

L_800C0484:
    // 0x800C0484: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C0488: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C048C: jr          $ra
    // 0x800C0490: nop

    return;
    // 0x800C0490: nop

;}
RECOMP_FUNC void force_mark_write_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC18: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EC1C: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006EC20: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EC24: addiu       $at, $zero, -0xC01
    ctx->r1 = ADD32(0, -0XC01);
    // 0x8006EC28: andi        $t0, $a0, 0x3
    ctx->r8 = ctx->r4 & 0X3;
    // 0x8006EC2C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8006EC30: ori         $t9, $t7, 0x40
    ctx->r25 = ctx->r15 | 0X40;
    // 0x8006EC34: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x8006EC38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006EC3C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8006EC40: jr          $ra
    // 0x8006EC44: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    return;
    // 0x8006EC44: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
;}
RECOMP_FUNC void postrace_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096790: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80096794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096798: jal         0x8006BDB0
    // 0x8009679C: nop

    level_header(rdram, ctx);
        goto after_0;
    // 0x8009679C: nop

    after_0:
    // 0x800967A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800967A4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800967A8: jal         0x8009C4A8
    // 0x800967AC: addiu       $a0, $a0, 0xA24
    ctx->r4 = ADD32(ctx->r4, 0XA24);
    menu_assetgroup_free(rdram, ctx);
        goto after_1;
    // 0x800967AC: addiu       $a0, $a0, 0xA24
    ctx->r4 = ADD32(ctx->r4, 0XA24);
    after_1:
    // 0x800967B0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800967B4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800967B8: lw          $t7, 0x6BB8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BB8);
    // 0x800967BC: lb          $v0, 0x0($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X0);
    // 0x800967C0: beq         $t7, $zero, L_800967F0
    if (ctx->r15 == 0) {
        // 0x800967C4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800967F0;
    }
    // 0x800967C4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800967C8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800967CC: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800967D0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800967D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800967D8: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800967DC: lh          $a0, 0x710($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X710);
    // 0x800967E0: jal         0x8009C508
    // 0x800967E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    menu_asset_free(rdram, ctx);
        goto after_2;
    // 0x800967E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x800967E8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800967EC: nop

L_800967F0:
    // 0x800967F0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800967F4: lw          $t0, 0x6BBC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6BBC);
    // 0x800967F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800967FC: beq         $t0, $zero, L_80096824
    if (ctx->r8 == 0) {
        // 0x80096800: sw          $zero, 0x6BB8($at)
        MEM_W(0X6BB8, ctx->r1) = 0;
            goto L_80096824;
    }
    // 0x80096800: sw          $zero, 0x6BB8($at)
    MEM_W(0X6BB8, ctx->r1) = 0;
    // 0x80096804: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80096808: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x8009680C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80096810: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096814: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80096818: lh          $a0, 0x712($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X712);
    // 0x8009681C: jal         0x8009C508
    // 0x80096820: nop

    menu_asset_free(rdram, ctx);
        goto after_3;
    // 0x80096820: nop

    after_3:
L_80096824:
    // 0x80096824: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096828: jal         0x800981E8
    // 0x8009682C: sw          $zero, 0x6BBC($at)
    MEM_W(0X6BBC, ctx->r1) = 0;
    menu_unload_bigfont(rdram, ctx);
        goto after_4;
    // 0x8009682C: sw          $zero, 0x6BBC($at)
    MEM_W(0X6BBC, ctx->r1) = 0;
    after_4:
    // 0x80096830: jal         0x80000968
    // 0x80096834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_5;
    // 0x80096834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80096838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009683C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80096840: jr          $ra
    // 0x80096844: nop

    return;
    // 0x80096844: nop

;}
RECOMP_FUNC void render_subtitles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2B00: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C2B04: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C2B08: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C2B0C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C2B10: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C2B14: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C2B18: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C2B1C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C2B20: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C2B24: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C2B28: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C2B2C: jal         0x800C5494
    // 0x800C2B30: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_0;
    // 0x800C2B30: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x800C2B34: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C2B38: addiu       $s1, $s1, -0x584C
    ctx->r17 = ADD32(ctx->r17, -0X584C);
    // 0x800C2B3C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C2B40: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800C2B44: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800C2B48: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x800C2B4C: addiu       $s6, $s6, -0x584E
    ctx->r22 = ADD32(ctx->r22, -0X584E);
    // 0x800C2B50: addiu       $s5, $s5, -0x5852
    ctx->r21 = ADD32(ctx->r21, -0X5852);
    // 0x800C2B54: addiu       $s0, $s0, -0x5850
    ctx->r16 = ADD32(ctx->r16, -0X5850);
    // 0x800C2B58: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x800C2B5C: lh          $a1, 0x0($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X0);
    // 0x800C2B60: lh          $a3, 0x0($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X0);
    // 0x800C2B64: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C2B68: jal         0x800C4EDC
    // 0x800C2B6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x800C2B6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800C2B70: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C2B74: addiu       $s7, $s7, -0x5858
    ctx->r23 = ADD32(ctx->r23, -0X5858);
    // 0x800C2B78: lh          $t7, 0x0($s7)
    ctx->r15 = MEM_H(ctx->r23, 0X0);
    // 0x800C2B7C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C2B80: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C2B84: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C2B88: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800C2B8C: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800C2B90: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C2B94: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800C2B98: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x800C2B9C: jal         0x800C4FBC
    // 0x800C2BA0: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x800C2BA0: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_2:
    // 0x800C2BA4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C2BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C2BAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C2BB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C2BB4: jal         0x800C5050
    // 0x800C2BB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_3;
    // 0x800C2BB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x800C2BBC: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800C2BC0: addiu       $fp, $fp, -0x5848
    ctx->r30 = ADD32(ctx->r30, -0X5848);
    // 0x800C2BC4: lh          $v0, 0x0($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X0);
    // 0x800C2BC8: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x800C2BCC: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x800C2BD0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800C2BD4: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800C2BD8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800C2BDC: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800C2BE0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800C2BE4: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x800C2BE8: subu        $s3, $t4, $t5
    ctx->r19 = SUB32(ctx->r12, ctx->r13);
    // 0x800C2BEC: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800C2BF0: sra         $t6, $s3, 1
    ctx->r14 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800C2BF4: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x800C2BF8: blez        $v0, L_800C2D34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C2BFC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800C2D34;
    }
    // 0x800C2BFC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C2C00: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C2C04: addiu       $s2, $s2, -0x5840
    ctx->r18 = ADD32(ctx->r18, -0X5840);
L_800C2C08:
    // 0x800C2C08: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800C2C0C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C2C10: lbu         $a1, 0x5($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X5);
    // 0x800C2C14: jal         0x800C4F7C
    // 0x800C2C18: nop

    set_dialogue_font(rdram, ctx);
        goto after_4;
    // 0x800C2C18: nop

    after_4:
    // 0x800C2C1C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800C2C20: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C2C24: lbu         $s0, 0x6($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X6);
    // 0x800C2C28: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800C2C2C: bne         $s0, $at, L_800C2C54
    if (ctx->r16 != ctx->r1) {
        // 0x800C2C30: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800C2C54;
    }
    // 0x800C2C30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C2C34: lh          $t8, 0x0($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X0);
    // 0x800C2C38: lh          $t9, 0x0($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X0);
    // 0x800C2C3C: nop

    // 0x800C2C40: subu        $s1, $t8, $t9
    ctx->r17 = SUB32(ctx->r24, ctx->r25);
    // 0x800C2C44: sra         $t0, $s1, 1
    ctx->r8 = S32(SIGNED(ctx->r17) >> 1);
    // 0x800C2C48: b           L_800C2C74
    // 0x800C2C4C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
        goto L_800C2C74;
    // 0x800C2C4C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x800C2C50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800C2C54:
    // 0x800C2C54: bne         $s0, $at, L_800C2C74
    if (ctx->r16 != ctx->r1) {
        // 0x800C2C58: addiu       $s1, $zero, 0x8
        ctx->r17 = ADD32(0, 0X8);
            goto L_800C2C74;
    }
    // 0x800C2C58: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x800C2C5C: lh          $t1, 0x0($s6)
    ctx->r9 = MEM_H(ctx->r22, 0X0);
    // 0x800C2C60: lh          $t2, 0x0($s5)
    ctx->r10 = MEM_H(ctx->r21, 0X0);
    // 0x800C2C64: nop

    // 0x800C2C68: subu        $s1, $t1, $t2
    ctx->r17 = SUB32(ctx->r9, ctx->r10);
    // 0x800C2C6C: b           L_800C2C74
    // 0x800C2C70: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
        goto L_800C2C74;
    // 0x800C2C70: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
L_800C2C74:
    // 0x800C2C74: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x800C2C78: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x800C2C7C: lbu         $a3, 0x3($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X3);
    // 0x800C2C80: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800C2C84: lbu         $t4, 0x4($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4);
    // 0x800C2C88: lh          $t5, 0x0($s7)
    ctx->r13 = MEM_H(ctx->r23, 0X0);
    // 0x800C2C8C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C2C90: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2C94: mflo        $t6
    ctx->r14 = lo;
    // 0x800C2C98: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800C2C9C: jal         0x800C5000
    // 0x800C2CA0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    set_current_text_colour(rdram, ctx);
        goto after_5;
    // 0x800C2CA0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_5:
    // 0x800C2CA4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800C2CA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C2CAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C2CB0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C2CB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C2CB8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800C2CBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C2CC0: jal         0x800C5168
    // 0x800C2CC4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    render_dialogue_text(rdram, ctx);
        goto after_6;
    // 0x800C2CC4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_6:
    // 0x800C2CC8: lh          $t0, 0x0($s7)
    ctx->r8 = MEM_H(ctx->r23, 0X0);
    // 0x800C2CCC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800C2CD0: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800C2CD4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C2CD8: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x800C2CDC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800C2CE0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C2CE4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C2CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C2CEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C2CF0: jal         0x800C5000
    // 0x800C2CF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_text_colour(rdram, ctx);
        goto after_7;
    // 0x800C2CF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x800C2CF8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800C2CFC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C2D00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800C2D04: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C2D08: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x800C2D0C: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x800C2D10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C2D14: jal         0x800C5168
    // 0x800C2D18: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    render_dialogue_text(rdram, ctx);
        goto after_8;
    // 0x800C2D18: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_8:
    // 0x800C2D1C: lh          $t4, 0x0($fp)
    ctx->r12 = MEM_H(ctx->r30, 0X0);
    // 0x800C2D20: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C2D24: slt         $at, $s4, $t4
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800C2D28: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C2D2C: bne         $at, $zero, L_800C2C08
    if (ctx->r1 != 0) {
        // 0x800C2D30: addiu       $s3, $s3, 0xE
        ctx->r19 = ADD32(ctx->r19, 0XE);
            goto L_800C2C08;
    }
    // 0x800C2D30: addiu       $s3, $s3, 0xE
    ctx->r19 = ADD32(ctx->r19, 0XE);
L_800C2D34:
    // 0x800C2D34: jal         0x800C55F4
    // 0x800C2D38: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    open_dialogue_box(rdram, ctx);
        goto after_9;
    // 0x800C2D38: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    // 0x800C2D3C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C2D40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C2D44: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C2D48: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C2D4C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2D50: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C2D54: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C2D58: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C2D5C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C2D60: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C2D64: jr          $ra
    // 0x800C2D68: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C2D68: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void __CSPVoiceHandler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062408: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8006240C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80062410: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80062414: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80062418: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006241C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80062420: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x80062424: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80062428: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006242C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80062430: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062434: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062438: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006243C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80062440: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
    // 0x80062444: addiu       $s6, $zero, 0x7F
    ctx->r22 = ADD32(0, 0X7F);
    // 0x80062448: addiu       $s7, $a0, 0x48
    ctx->r23 = ADD32(ctx->r4, 0X48);
    // 0x8006244C: addiu       $fp, $sp, 0x6C
    ctx->r30 = ADD32(ctx->r29, 0X6C);
L_80062450:
    // 0x80062450: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x80062454: nop

    // 0x80062458: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x8006245C: beq         $at, $zero, L_80062978
    if (ctx->r1 == 0) {
        // 0x80062460: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80062978;
    }
    // 0x80062460: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80062464: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80062468: addu        $at, $at, $t7
    gpr jr_addend_80062474 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8006246C: lw          $t7, 0x6C30($at)
    ctx->r15 = ADD32(ctx->r1, 0X6C30);
    // 0x80062470: nop

    // 0x80062474: jr          $t7
    // 0x80062478: nop

    switch (jr_addend_80062474 >> 2) {
        case 0: goto L_8006247C; break;
        case 1: goto L_80062978; break;
        case 2: goto L_800626F8; break;
        case 3: goto L_80062978; break;
        case 4: goto L_80062978; break;
        case 5: goto L_800624AC; break;
        case 6: goto L_800624FC; break;
        case 7: goto L_8006270C; break;
        case 8: goto L_80062978; break;
        case 9: goto L_8006248C; break;
        case 10: goto L_80062720; break;
        case 11: goto L_80062978; break;
        case 12: goto L_80062924; break;
        case 13: goto L_80062944; break;
        case 14: goto L_80062968; break;
        case 15: goto L_80062788; break;
        case 16: goto L_800627AC; break;
        case 17: goto L_80062880; break;
        case 18: goto L_80062978; break;
        case 19: goto L_80062978; break;
        case 20: goto L_80062978; break;
        case 21: goto L_800626F8; break;
        case 22: goto L_80062564; break;
        case 23: goto L_80062668; break;
        default: switch_error(__func__, 0x80062474, 0x800E6C30);
    }
    // 0x80062478: nop

L_8006247C:
    // 0x8006247C: jal         0x80062A3C
    // 0x80062480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    static_3_80062A3C(rdram, ctx);
        goto after_0;
    // 0x80062480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80062484: b           L_8006297C
    // 0x80062488: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x80062488: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_8006248C:
    // 0x8006248C: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80062490: sh          $t8, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r24;
    // 0x80062494: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x80062498: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8006249C: jal         0x800C91AC
    // 0x800624A0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x800624A0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_1:
    // 0x800624A4: b           L_8006297C
    // 0x800624A8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x800624A8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800624AC:
    // 0x800624AC: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x800624B0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800624B4: jal         0x800C98B0
    // 0x800624B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_2;
    // 0x800624B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800624BC: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800624C0: jal         0x800C9930
    // 0x800624C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_3;
    // 0x800624C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800624C8: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x800624CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800624D0: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x800624D4: nop

    // 0x800624D8: beq         $t9, $zero, L_800624E8
    if (ctx->r25 == 0) {
        // 0x800624DC: nop
    
            goto L_800624E8;
    }
    // 0x800624DC: nop

    // 0x800624E0: jal         0x8000AEFC
    // 0x800624E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_4;
    // 0x800624E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
L_800624E8:
    // 0x800624E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800624EC: jal         0x8000A7C4
    // 0x800624F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_5;
    // 0x800624F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800624F4: b           L_8006297C
    // 0x800624F8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x800624F8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800624FC:
    // 0x800624FC: lw          $s0, 0x3C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X3C);
    // 0x80062500: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80062504: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x80062508: nop

    // 0x8006250C: lbu         $t0, 0x34($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X34);
    // 0x80062510: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80062514: bne         $t0, $zero, L_80062520
    if (ctx->r8 != 0) {
        // 0x80062518: nop
    
            goto L_80062520;
    }
    // 0x80062518: nop

    // 0x8006251C: sb          $t1, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r9;
L_80062520:
    // 0x80062520: lw          $s3, 0x40($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X40);
    // 0x80062524: lw          $t2, 0x1C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X1C);
    // 0x80062528: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8006252C: addu        $t3, $t2, $s3
    ctx->r11 = ADD32(ctx->r10, ctx->r19);
    // 0x80062530: sw          $t3, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r11;
    // 0x80062534: lbu         $t4, 0x44($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X44);
    // 0x80062538: jal         0x8000A9F8
    // 0x8006253C: sb          $t4, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r12;
    __vsVol(rdram, ctx);
        goto after_6;
    // 0x8006253C: sb          $t4, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r12;
    after_6:
    // 0x80062540: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80062544: sra         $t5, $a2, 16
    ctx->r13 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80062548: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8006254C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80062550: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80062554: jal         0x800C9650
    // 0x80062558: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    alSynSetVol(rdram, ctx);
        goto after_7;
    // 0x80062558: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_7:
    // 0x8006255C: b           L_8006297C
    // 0x80062560: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x80062560: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062564:
    // 0x80062564: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x80062568: lw          $t9, 0x78($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X78);
    // 0x8006256C: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x80062570: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80062574: jalr        $t9
    // 0x80062578: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x80062578: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x8006257C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80062580: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80062584: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80062588: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8006258C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80062590: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80062594: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80062598: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006259C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800625A0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800625A4: beq         $t7, $zero, L_800625F0
    if (ctx->r15 == 0) {
        // 0x800625A8: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800625F0;
    }
    // 0x800625A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800625AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800625B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800625B4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800625B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800625BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800625C0: nop

    // 0x800625C4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800625C8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800625CC: nop

    // 0x800625D0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800625D4: bne         $t7, $zero, L_800625E8
    if (ctx->r15 != 0) {
        // 0x800625D8: nop
    
            goto L_800625E8;
    }
    // 0x800625D8: nop

    // 0x800625DC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800625E0: b           L_80062600
    // 0x800625E4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80062600;
    // 0x800625E4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800625E8:
    // 0x800625E8: b           L_80062600
    // 0x800625EC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80062600;
    // 0x800625EC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_800625F0:
    // 0x800625F0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800625F4: nop

    // 0x800625F8: bltz        $t7, L_800625E8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800625FC: nop
    
            goto L_800625E8;
    }
    // 0x800625FC: nop

L_80062600:
    // 0x80062600: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80062604: jal         0x8000A9F8
    // 0x80062608: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    __vsVol(rdram, ctx);
        goto after_9;
    // 0x80062608: sb          $t7, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r15;
    after_9:
    // 0x8006260C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80062610: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80062614: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x80062618: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8006261C: jal         0x8000AA88
    // 0x80062620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    __vsDelta(rdram, ctx);
        goto after_10;
    // 0x80062620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80062624: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80062628: sra         $t0, $a2, 16
    ctx->r8 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006262C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062630: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80062634: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80062638: jal         0x800C9650
    // 0x8006263C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_11;
    // 0x8006263C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_11:
    // 0x80062640: addiu       $t1, $zero, 0x16
    ctx->r9 = ADD32(0, 0X16);
    // 0x80062644: sh          $t1, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r9;
    // 0x80062648: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    // 0x8006264C: sw          $s4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r20;
    // 0x80062650: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80062654: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80062658: jal         0x800C91AC
    // 0x8006265C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_12;
    // 0x8006265C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_12:
    // 0x80062660: b           L_8006297C
    // 0x80062664: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x80062664: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062668:
    // 0x80062668: lw          $s4, 0x40($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X40);
    // 0x8006266C: lw          $t9, 0x78($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X78);
    // 0x80062670: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x80062674: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x80062678: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8006267C: jalr        $t9
    // 0x80062680: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x80062680: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
    // 0x80062684: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062688: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8006268C: lwc1        $f16, 0x28($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80062690: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x80062694: lwc1        $f18, 0x2C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80062698: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x8006269C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800626A0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800626A4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800626A8: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800626AC: mflo        $t3
    ctx->r11 = lo;
    // 0x800626B0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800626B4: lwc1        $f10, 0xC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800626B8: nop

    // 0x800626BC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800626C0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800626C4: jal         0x800C9780
    // 0x800626C8: nop

    alSynSetPitch(rdram, ctx);
        goto after_14;
    // 0x800626C8: nop

    after_14:
    // 0x800626CC: addiu       $t5, $zero, 0x17
    ctx->r13 = ADD32(0, 0X17);
    // 0x800626D0: sh          $t5, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r13;
    // 0x800626D4: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    // 0x800626D8: sw          $s4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r20;
    // 0x800626DC: sb          $s0, 0x78($sp)
    MEM_B(0X78, ctx->r29) = ctx->r16;
    // 0x800626E0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800626E4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800626E8: jal         0x800C91AC
    // 0x800626EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_15;
    // 0x800626EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_15:
    // 0x800626F0: b           L_8006297C
    // 0x800626F4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x800626F4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800626F8:
    // 0x800626F8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800626FC: jal         0x80062B00
    // 0x80062700: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    static_3_80062B00(rdram, ctx);
        goto after_16;
    // 0x80062700: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_16:
    // 0x80062704: b           L_8006297C
    // 0x80062708: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x80062708: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_8006270C:
    // 0x8006270C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80062710: jal         0x800637EC
    // 0x80062714: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    static_3_800637EC(rdram, ctx);
        goto after_17;
    // 0x80062714: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80062718: b           L_8006297C
    // 0x8006271C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x8006271C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062720:
    // 0x80062720: lh          $t6, 0x3C($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X3C);
    // 0x80062724: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x80062728: sh          $t6, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r14;
    // 0x8006272C: beq         $s1, $zero, L_80062978
    if (ctx->r17 == 0) {
        // 0x80062730: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80062978;
    }
    // 0x80062730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80062734:
    // 0x80062734: jal         0x8000A9F8
    // 0x80062738: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_18;
    // 0x80062738: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x8006273C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80062740: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80062744: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x80062748: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8006274C: jal         0x8000AA88
    // 0x80062750: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    __vsDelta(rdram, ctx);
        goto after_19;
    // 0x80062750: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80062754: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80062758: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006275C: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062760: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80062764: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80062768: jal         0x800C9650
    // 0x8006276C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_20;
    // 0x8006276C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_20:
    // 0x80062770: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80062774: nop

    // 0x80062778: bne         $s1, $zero, L_80062734
    if (ctx->r17 != 0) {
        // 0x8006277C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80062734;
    }
    // 0x8006277C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80062780: b           L_8006297C
    // 0x80062784: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x80062784: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062788:
    // 0x80062788: lw          $t0, 0x2C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X2C);
    // 0x8006278C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80062790: beq         $t0, $at, L_80062978
    if (ctx->r8 == ctx->r1) {
        // 0x80062794: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80062978;
    }
    // 0x80062794: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80062798: sw          $t1, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r9;
    // 0x8006279C: jal         0x800629CC
    // 0x800627A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_21;
    // 0x800627A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_21:
    // 0x800627A4: b           L_8006297C
    // 0x800627A8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x800627A8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800627AC:
    // 0x800627AC: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x800627B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800627B4: bne         $t9, $at, L_80062978
    if (ctx->r25 != ctx->r1) {
        // 0x800627B8: ori         $t2, $zero, 0xFFFF
        ctx->r10 = 0 | 0XFFFF;
            goto L_80062978;
    }
    // 0x800627B8: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800627BC: lbu         $t3, 0x34($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X34);
    // 0x800627C0: sh          $t2, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r10;
    // 0x800627C4: blez        $t3, L_80062818
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800627C8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80062818;
    }
    // 0x800627C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800627CC:
    // 0x800627CC: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800627D0: lw          $t4, 0x60($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X60);
    // 0x800627D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800627D8: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x800627DC: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800627E0: mflo        $v0
    ctx->r2 = lo;
    // 0x800627E4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800627E8: sb          $s6, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r22;
    // 0x800627EC: lw          $t6, 0x60($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X60);
    // 0x800627F0: nop

    // 0x800627F4: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x800627F8: lbu         $t7, 0x11($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X11);
    // 0x800627FC: nop

    // 0x80062800: sb          $t7, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r15;
    // 0x80062804: lbu         $t0, 0x34($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X34);
    // 0x80062808: nop

    // 0x8006280C: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80062810: bne         $at, $zero, L_800627CC
    if (ctx->r1 != 0) {
        // 0x80062814: nop
    
            goto L_800627CC;
    }
    // 0x80062814: nop

L_80062818:
    // 0x80062818: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x8006281C: nop

    // 0x80062820: beq         $s1, $zero, L_80062878
    if (ctx->r17 == 0) {
        // 0x80062824: nop
    
            goto L_80062878;
    }
    // 0x80062824: nop

L_80062828:
    // 0x80062828: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8006282C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80062830: jal         0x800C98B0
    // 0x80062834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_22;
    // 0x80062834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_22:
    // 0x80062838: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8006283C: jal         0x800C9930
    // 0x80062840: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_23;
    // 0x80062840: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_23:
    // 0x80062844: lbu         $t1, 0x37($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X37);
    // 0x80062848: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006284C: beq         $t1, $zero, L_8006285C
    if (ctx->r9 == 0) {
        // 0x80062850: nop
    
            goto L_8006285C;
    }
    // 0x80062850: nop

    // 0x80062854: jal         0x8000AEFC
    // 0x80062858: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_24;
    // 0x80062858: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_24:
L_8006285C:
    // 0x8006285C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062860: jal         0x8000A7C4
    // 0x80062864: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_25;
    // 0x80062864: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_25:
    // 0x80062868: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x8006286C: nop

    // 0x80062870: bne         $s1, $zero, L_80062828
    if (ctx->r17 != 0) {
        // 0x80062874: nop
    
            goto L_80062828;
    }
    // 0x80062874: nop

L_80062878:
    // 0x80062878: b           L_80062978
    // 0x8006287C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_80062978;
    // 0x8006287C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_80062880:
    // 0x80062880: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x80062884: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80062888: bne         $t9, $at, L_80062978
    if (ctx->r25 != ctx->r1) {
        // 0x8006288C: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80062978;
    }
    // 0x8006288C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80062890: jal         0x800C9090
    // 0x80062894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alEvtqFlushType(rdram, ctx);
        goto after_26;
    // 0x80062894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80062898: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8006289C: jal         0x800C9090
    // 0x800628A0: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    alEvtqFlushType(rdram, ctx);
        goto after_27;
    // 0x800628A0: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_27:
    // 0x800628A4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800628A8: jal         0x800C9090
    // 0x800628AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alEvtqFlushType(rdram, ctx);
        goto after_28;
    // 0x800628AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_28:
    // 0x800628B0: lw          $s1, 0x64($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X64);
    // 0x800628B4: nop

    // 0x800628B8: beq         $s1, $zero, L_800628FC
    if (ctx->r17 == 0) {
        // 0x800628BC: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_800628FC;
    }
    // 0x800628BC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_800628C0:
    // 0x800628C0: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x800628C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800628C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800628CC: jal         0x8000AC34
    // 0x800628D0: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __voiceNeedsNoteKill(rdram, ctx);
        goto after_29;
    // 0x800628D0: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_29:
    // 0x800628D4: beq         $v0, $zero, L_800628E8
    if (ctx->r2 == 0) {
        // 0x800628D8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800628E8;
    }
    // 0x800628D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800628DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800628E0: jal         0x8000AB00
    // 0x800628E4: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __seqpReleaseVoice(rdram, ctx);
        goto after_30;
    // 0x800628E4: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_30:
L_800628E8:
    // 0x800628E8: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800628EC: nop

    // 0x800628F0: bne         $s1, $zero, L_800628C0
    if (ctx->r17 != 0) {
        // 0x800628F4: nop
    
            goto L_800628C0;
    }
    // 0x800628F4: nop

    // 0x800628F8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_800628FC:
    // 0x800628FC: sw          $t2, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r10;
    // 0x80062900: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80062904: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80062908: sh          $t3, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r11;
    // 0x8006290C: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80062910: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80062914: jal         0x800C91AC
    // 0x80062918: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_31;
    // 0x80062918: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_31:
    // 0x8006291C: b           L_8006297C
    // 0x80062920: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x80062920: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062924:
    // 0x80062924: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x80062928: lw          $t5, 0x60($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X60);
    // 0x8006292C: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062930: lbu         $t4, 0x3D($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X3D);
    // 0x80062934: mflo        $t6
    ctx->r14 = lo;
    // 0x80062938: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8006293C: b           L_80062978
    // 0x80062940: sb          $t4, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r12;
        goto L_80062978;
    // 0x80062940: sb          $t4, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r12;
L_80062944:
    // 0x80062944: lw          $t8, 0x3C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X3C);
    // 0x80062948: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x8006294C: sw          $t8, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r24;
    // 0x80062950: beq         $a1, $zero, L_80062978
    if (ctx->r5 == 0) {
        // 0x80062954: nop
    
            goto L_80062978;
    }
    // 0x80062954: nop

    // 0x80062958: jal         0x8000ACE0
    // 0x8006295C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __initFromBank(rdram, ctx);
        goto after_32;
    // 0x8006295C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_32:
    // 0x80062960: b           L_8006297C
    // 0x80062964: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8006297C;
    // 0x80062964: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_80062968:
    // 0x80062968: lw          $a1, 0x3C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X3C);
    // 0x8006296C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062970: jal         0x8000ACE0
    // 0x80062974: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    __initFromBank(rdram, ctx);
        goto after_33;
    // 0x80062974: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_33:
L_80062978:
    // 0x80062978: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_8006297C:
    // 0x8006297C: jal         0x800C92D0
    // 0x80062980: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    alEvtqNextEvent(rdram, ctx);
        goto after_34;
    // 0x80062980: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_34:
    // 0x80062984: beq         $v0, $zero, L_80062450
    if (ctx->r2 == 0) {
        // 0x80062988: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_80062450;
    }
    // 0x80062988: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x8006298C: lw          $t0, 0x1C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X1C);
    // 0x80062990: nop

    // 0x80062994: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80062998: sw          $t1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r9;
    // 0x8006299C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800629A0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800629A4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800629A8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800629AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800629B0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800629B4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800629B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800629BC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800629C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800629C4: jr          $ra
    // 0x800629C8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800629C8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void __amMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A98: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80002A9C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80002AA0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002AA4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80002AA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80002AAC: lw          $a0, 0x5F90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5F90);
    // 0x80002AB0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80002AB4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80002AB8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80002ABC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80002AC0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80002AC4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80002AC8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80002ACC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80002AD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80002AD4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80002AD8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80002ADC: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80002AE0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80002AE4: addiu       $a2, $a2, 0x6160
    ctx->r6 = ADD32(ctx->r6, 0X6160);
    // 0x80002AE8: addiu       $a1, $a1, 0x6220
    ctx->r5 = ADD32(ctx->r5, 0X6220);
    // 0x80002AEC: jal         0x80079480
    // 0x80002AF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    osScAddClient(rdram, ctx);
        goto after_0;
    // 0x80002AF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80002AF4: lui         $fp, 0x8011
    ctx->r30 = S32(0X8011 << 16);
    // 0x80002AF8: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80002AFC: lui         $s5, 0x8011
    ctx->r21 = S32(0X8011 << 16);
    // 0x80002B00: addiu       $s5, $s5, 0x5F98
    ctx->r21 = ADD32(ctx->r21, 0X5F98);
    // 0x80002B04: addiu       $s6, $s6, -0x3980
    ctx->r22 = ADD32(ctx->r22, -0X3980);
    // 0x80002B08: addiu       $fp, $fp, 0x6198
    ctx->r30 = ADD32(ctx->r30, 0X6198);
    // 0x80002B0C: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x80002B10: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80002B14: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80002B18: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80002B1C: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
L_80002B20:
    // 0x80002B20: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002B24: addiu       $a0, $a0, 0x6160
    ctx->r4 = ADD32(ctx->r4, 0X6160);
    // 0x80002B28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80002B2C: jal         0x800C8BB0
    // 0x80002B30: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80002B30: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80002B34: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80002B38: nop

    // 0x80002B3C: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x80002B40: nop

    // 0x80002B44: beq         $v0, $s2, L_80002B64
    if (ctx->r2 == ctx->r18) {
        // 0x80002B48: nop
    
            goto L_80002B64;
    }
    // 0x80002B48: nop

    // 0x80002B4C: beq         $v0, $s3, L_80002BBC
    if (ctx->r2 == ctx->r19) {
        // 0x80002B50: nop
    
            goto L_80002BBC;
    }
    // 0x80002B50: nop

    // 0x80002B54: beq         $v0, $s4, L_80002BB8
    if (ctx->r2 == ctx->r20) {
        // 0x80002B58: nop
    
            goto L_80002BB8;
    }
    // 0x80002B58: nop

    // 0x80002B5C: b           L_80002BBC
    // 0x80002B60: nop

        goto L_80002BBC;
    // 0x80002B60: nop

L_80002B64:
    // 0x80002B64: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x80002B68: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80002B6C: divu        $zero, $t7, $s7
    lo = S32(U32(ctx->r15) / U32(ctx->r23)); hi = S32(U32(ctx->r15) % U32(ctx->r23));
    // 0x80002B70: bne         $s7, $zero, L_80002B7C
    if (ctx->r23 != 0) {
        // 0x80002B74: nop
    
            goto L_80002B7C;
    }
    // 0x80002B74: nop

    // 0x80002B78: break       7
    do_break(2147494776);
L_80002B7C:
    // 0x80002B7C: mfhi        $t8
    ctx->r24 = hi;
    // 0x80002B80: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80002B84: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x80002B88: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x80002B8C: jal         0x80002C00
    // 0x80002B90: nop

    __amHandleFrameMsg(rdram, ctx);
        goto after_2;
    // 0x80002B90: nop

    after_2:
    // 0x80002B94: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80002B98: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80002B9C: jal         0x800C8BB0
    // 0x80002BA0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80002BA0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x80002BA4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80002BA8: jal         0x80002DF8
    // 0x80002BAC: nop

    __amHandleDoneMsg(rdram, ctx);
        goto after_4;
    // 0x80002BAC: nop

    after_4:
    // 0x80002BB0: b           L_80002BBC
    // 0x80002BB4: nop

        goto L_80002BBC;
    // 0x80002BB4: nop

L_80002BB8:
    // 0x80002BB8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80002BBC:
    // 0x80002BBC: beq         $s0, $zero, L_80002B20
    if (ctx->r16 == 0) {
        // 0x80002BC0: nop
    
            goto L_80002B20;
    }
    // 0x80002BC0: nop

    // 0x80002BC4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002BC8: jal         0x800C87B4
    // 0x80002BCC: addiu       $a0, $a0, 0x61D0
    ctx->r4 = ADD32(ctx->r4, 0X61D0);
    alClose(rdram, ctx);
        goto after_5;
    // 0x80002BCC: addiu       $a0, $a0, 0x61D0
    ctx->r4 = ADD32(ctx->r4, 0X61D0);
    after_5:
    // 0x80002BD0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80002BD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002BD8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80002BDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80002BE0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80002BE4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80002BE8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80002BEC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80002BF0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80002BF4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80002BF8: jr          $ra
    // 0x80002BFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80002BFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void __amHandleFrameMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002C00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002C04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002C08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80002C0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80002C10: jal         0x80003040
    // 0x80002C14: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    __clearAudioDMA(rdram, ctx);
        goto after_0;
    // 0x80002C14: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80002C18: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80002C1C: jal         0x800C8CF0
    // 0x80002C20: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80002C20: nop

    after_1:
    // 0x80002C24: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80002C28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80002C2C: beq         $v1, $zero, L_80002C7C
    if (ctx->r3 == 0) {
        // 0x80002C30: nop
    
            goto L_80002C7C;
    }
    // 0x80002C30: nop

    // 0x80002C34: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80002C38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002C3C: sw          $a0, -0x3968($at)
    MEM_W(-0X3968, ctx->r1) = ctx->r4;
    // 0x80002C40: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x80002C44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002C48: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80002C4C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80002C50: jal         0x800C8D70
    // 0x80002C54: sw          $t6, -0x3964($at)
    MEM_W(-0X3964, ctx->r1) = ctx->r14;
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x80002C54: sw          $t6, -0x3964($at)
    MEM_W(-0X3964, ctx->r1) = ctx->r14;
    after_2:
    // 0x80002C58: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002C5C: lb          $t7, -0x3974($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X3974);
    // 0x80002C60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80002C64: beq         $t7, $zero, L_80002C7C
    if (ctx->r15 == 0) {
        // 0x80002C68: nop
    
            goto L_80002C7C;
    }
    // 0x80002C68: nop

    // 0x80002C6C: jal         0x8006F94C
    // 0x80002C70: addiu       $a1, $zero, 0x2710
    ctx->r5 = ADD32(0, 0X2710);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x80002C70: addiu       $a1, $zero, 0x2710
    ctx->r5 = ADD32(0, 0X2710);
    after_3:
    // 0x80002C74: jal         0x800C8600
    // 0x80002C78: addiu       $a0, $v0, 0x5622
    ctx->r4 = ADD32(ctx->r2, 0X5622);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_4;
    // 0x80002C78: addiu       $a0, $v0, 0x5622
    ctx->r4 = ADD32(ctx->r2, 0X5622);
    after_4:
L_80002C7C:
    // 0x80002C7C: jal         0x800C8E20
    // 0x80002C80: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_5;
    // 0x80002C80: nop

    after_5:
    // 0x80002C84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80002C88: lw          $t8, -0x69D4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X69D4);
    // 0x80002C8C: srl         $t9, $v0, 2
    ctx->r25 = S32(U32(ctx->r2) >> 2);
    // 0x80002C90: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80002C94: addiu       $t1, $t0, 0x70
    ctx->r9 = ADD32(ctx->r8, 0X70);
    // 0x80002C98: andi        $t2, $t1, 0xFFF0
    ctx->r10 = ctx->r9 & 0XFFF0;
    // 0x80002C9C: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    // 0x80002CA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80002CA4: lw          $v1, -0x69D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X69D8);
    // 0x80002CA8: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x80002CAC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80002CB0: sltu        $at, $a3, $v1
    ctx->r1 = ctx->r7 < ctx->r3 ? 1 : 0;
    // 0x80002CB4: beq         $at, $zero, L_80002CC8
    if (ctx->r1 == 0) {
        // 0x80002CB8: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80002CC8;
    }
    // 0x80002CB8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002CBC: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // 0x80002CC0: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x80002CC4: nop

L_80002CC8:
    // 0x80002CC8: lw          $t3, -0x3978($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3978);
    // 0x80002CCC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80002CD0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80002CD4: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80002CD8: lw          $a0, 0x5F98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5F98);
    // 0x80002CDC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80002CE0: jal         0x80065494
    // 0x80002CE4: addiu       $a1, $a1, -0x69CC
    ctx->r5 = ADD32(ctx->r5, -0X69CC);
    alAudioFrame(rdram, ctx);
        goto after_6;
    // 0x80002CE4: addiu       $a1, $a1, -0x69CC
    ctx->r5 = ADD32(ctx->r5, -0X69CC);
    after_6:
    // 0x80002CE8: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80002CEC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80002CF0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80002CF4: addiu       $t5, $t5, 0x6198
    ctx->r13 = ADD32(ctx->r13, 0X6198);
    // 0x80002CF8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80002CFC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80002D00: addiu       $a2, $a2, -0x3978
    ctx->r6 = ADD32(ctx->r6, -0X3978);
    // 0x80002D04: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80002D08: sw          $t5, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r13;
    // 0x80002D0C: sw          $s0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r16;
    // 0x80002D10: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x80002D14: sw          $t6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r14;
    // 0x80002D18: sw          $t7, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r15;
    // 0x80002D1C: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x80002D20: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x80002D24: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80002D28: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80002D2C: addiu       $a3, $a3, 0x5F98
    ctx->r7 = ADD32(ctx->r7, 0X5F98);
    // 0x80002D30: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80002D34: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x80002D38: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80002D3C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80002D40: sw          $t1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r9;
    // 0x80002D44: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80002D48: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80002D4C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80002D50: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80002D54: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80002D58: addiu       $a1, $a1, -0x7B40
    ctx->r5 = ADD32(ctx->r5, -0X7B40);
    // 0x80002D5C: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x80002D60: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80002D64: addiu       $t9, $t9, -0x7A70
    ctx->r25 = ADD32(ctx->r25, -0X7A70);
    // 0x80002D68: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80002D6C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x80002D70: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80002D74: subu        $t0, $t9, $a1
    ctx->r8 = SUB32(ctx->r25, ctx->r5);
    // 0x80002D78: addiu       $t1, $t1, 0x7600
    ctx->r9 = ADD32(ctx->r9, 0X7600);
    // 0x80002D7C: addiu       $t2, $t2, -0x6730
    ctx->r10 = ADD32(ctx->r10, -0X6730);
    // 0x80002D80: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x80002D84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80002D88: sw          $t8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r24;
    // 0x80002D8C: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x80002D90: sw          $a1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r5;
    // 0x80002D94: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    // 0x80002D98: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x80002D9C: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x80002DA0: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
    // 0x80002DA4: sw          $t3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r11;
    // 0x80002DA8: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x80002DAC: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80002DB0: sw          $t4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r12;
    // 0x80002DB4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002DB8: lw          $a0, 0x5F90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5F90);
    // 0x80002DBC: jal         0x80079574
    // 0x80002DC0: nop

    osScGetCmdQ(rdram, ctx);
        goto after_7;
    // 0x80002DC0: nop

    after_7:
    // 0x80002DC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80002DC8: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x80002DCC: jal         0x800C8E30
    // 0x80002DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80002DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80002DD4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80002DD8: addiu       $v1, $v1, -0x3978
    ctx->r3 = ADD32(ctx->r3, -0X3978);
    // 0x80002DDC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80002DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002DE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002DE8: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x80002DEC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80002DF0: jr          $ra
    // 0x80002DF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80002DF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __amHandleDoneMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002E00: jal         0x800C8E20
    // 0x80002E04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osAiGetLength_recomp(rdram, ctx);
        goto after_0;
    // 0x80002E04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80002E08: srl         $t6, $v0, 2
    ctx->r14 = S32(U32(ctx->r2) >> 2);
    // 0x80002E0C: bne         $t6, $zero, L_80002E28
    if (ctx->r14 != 0) {
        // 0x80002E10: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80002E28;
    }
    // 0x80002E10: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002E14: lw          $t7, -0x3960($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3960);
    // 0x80002E18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002E1C: bne         $t7, $zero, L_80002E2C
    if (ctx->r15 != 0) {
        // 0x80002E20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80002E2C;
    }
    // 0x80002E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002E24: sw          $zero, -0x3960($at)
    MEM_W(-0X3960, ctx->r1) = 0;
L_80002E28:
    // 0x80002E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80002E2C:
    // 0x80002E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002E30: jr          $ra
    // 0x80002E34: nop

    return;
    // 0x80002E34: nop

;}
RECOMP_FUNC void __amDMA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002E38: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80002E3C: addiu       $t1, $t1, -0x6DD0
    ctx->r9 = ADD32(ctx->r9, -0X6DD0);
    // 0x80002E40: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80002E44: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x80002E48: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80002E4C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80002E50: andi        $t2, $a0, 0x1
    ctx->r10 = ctx->r4 & 0X1;
    // 0x80002E54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80002E58: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80002E5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80002E60: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80002E64: beq         $t0, $zero, L_80002EC0
    if (ctx->r8 == 0) {
        // 0x80002E68: or          $s0, $t0, $zero
        ctx->r16 = ctx->r8 | 0;
            goto L_80002EC0;
    }
    // 0x80002E68: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80002E6C:
    // 0x80002E6C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80002E70: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x80002E74: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80002E78: bne         $at, $zero, L_80002EC0
    if (ctx->r1 != 0) {
        // 0x80002E7C: addiu       $v1, $v0, 0x400
        ctx->r3 = ADD32(ctx->r2, 0X400);
            goto L_80002EC0;
    }
    // 0x80002E7C: addiu       $v1, $v0, 0x400
    ctx->r3 = ADD32(ctx->r2, 0X400);
    // 0x80002E80: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80002E84: bne         $at, $zero, L_80002EB0
    if (ctx->r1 != 0) {
        // 0x80002E88: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_80002EB0;
    }
    // 0x80002E88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80002E8C: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x80002E90: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002E94: lw          $t7, -0x3980($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3980);
    // 0x80002E98: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x80002E9C: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
    // 0x80002EA0: jal         0x800C8CF0
    // 0x80002EA4: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80002EA4: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    after_0:
    // 0x80002EA8: b           L_80002FFC
    // 0x80002EAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80002FFC;
    // 0x80002EAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80002EB0:
    // 0x80002EB0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80002EB4: nop

    // 0x80002EB8: bne         $s0, $zero, L_80002E6C
    if (ctx->r16 != 0) {
        // 0x80002EBC: nop
    
            goto L_80002E6C;
    }
    // 0x80002EBC: nop

L_80002EC0:
    // 0x80002EC0: lw          $s0, 0x8($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X8);
    // 0x80002EC4: nop

    // 0x80002EC8: bne         $s0, $zero, L_80002EDC
    if (ctx->r16 != 0) {
        // 0x80002ECC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002EDC;
    }
    // 0x80002ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80002ED0: bne         $a2, $zero, L_80002EDC
    if (ctx->r6 != 0) {
        // 0x80002ED4: nop
    
            goto L_80002EDC;
    }
    // 0x80002ED4: nop

    // 0x80002ED8: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_80002EDC:
    // 0x80002EDC: bne         $s0, $zero, L_80002EFC
    if (ctx->r16 != 0) {
        // 0x80002EE0: nop
    
            goto L_80002EFC;
    }
    // 0x80002EE0: nop

    // 0x80002EE4: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    // 0x80002EE8: jal         0x800C8CF0
    // 0x80002EEC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80002EEC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_1:
    // 0x80002EF0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80002EF4: b           L_80002FF8
    // 0x80002EF8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
        goto L_80002FF8;
    // 0x80002EF8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_80002EFC:
    // 0x80002EFC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80002F00: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x80002F04: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80002F08: jal         0x800C8760
    // 0x80002F0C: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x80002F0C: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    after_2:
    // 0x80002F10: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80002F14: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80002F18: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80002F1C: beq         $a2, $zero, L_80002F40
    if (ctx->r6 == 0) {
        // 0x80002F20: addiu       $t1, $t1, -0x6DD0
        ctx->r9 = ADD32(ctx->r9, -0X6DD0);
            goto L_80002F40;
    }
    // 0x80002F20: addiu       $t1, $t1, -0x6DD0
    ctx->r9 = ADD32(ctx->r9, -0X6DD0);
    // 0x80002F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80002F28: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80002F2C: jal         0x800C8790
    // 0x80002F30: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    alLink(rdram, ctx);
        goto after_3;
    // 0x80002F30: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_3:
    // 0x80002F34: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80002F38: b           L_80002F74
    // 0x80002F3C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
        goto L_80002F74;
    // 0x80002F3C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_80002F40:
    // 0x80002F40: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x80002F44: nop

    // 0x80002F48: beq         $t0, $zero, L_80002F64
    if (ctx->r8 == 0) {
        // 0x80002F4C: nop
    
            goto L_80002F64;
    }
    // 0x80002F4C: nop

    // 0x80002F50: sw          $s0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r16;
    // 0x80002F54: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80002F58: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80002F5C: b           L_80002F70
    // 0x80002F60: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
        goto L_80002F70;
    // 0x80002F60: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
L_80002F64:
    // 0x80002F64: sw          $s0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r16;
    // 0x80002F68: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80002F6C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80002F70:
    // 0x80002F70: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_80002F74:
    // 0x80002F74: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80002F78: subu        $a3, $a3, $t4
    ctx->r7 = SUB32(ctx->r7, ctx->r12);
    // 0x80002F7C: sw          $a3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r7;
    // 0x80002F80: lw          $t5, -0x3980($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3980);
    // 0x80002F84: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80002F88: addiu       $t0, $t0, -0x397C
    ctx->r8 = ADD32(ctx->r8, -0X397C);
    // 0x80002F8C: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
    // 0x80002F90: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80002F94: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80002F98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80002F9C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80002FA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80002FA4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80002FA8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80002FAC: addiu       $t9, $t9, -0x6510
    ctx->r25 = ADD32(ctx->r25, -0X6510);
    // 0x80002FB0: addiu       $t7, $t7, -0x69C0
    ctx->r15 = ADD32(ctx->r15, -0X69C0);
    // 0x80002FB4: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x80002FB8: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80002FBC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80002FC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80002FC4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80002FC8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80002FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80002FD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80002FD4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80002FD8: nop

    // 0x80002FDC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    extern void dkr_legacy_pi_start_dma(uint8_t*, recomp_context*); dkr_legacy_pi_start_dma(rdram, ctx);
    // 0x80002FE0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80002FE4: jal         0x800C8CF0
    // 0x80002FE8: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x80002FE8: nop

    after_4:
    // 0x80002FEC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80002FF0: nop

    // 0x80002FF4: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
L_80002FF8:
    // 0x80002FF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80002FFC:
    // 0x80002FFC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80003000: jr          $ra
    // 0x80003004: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80003004: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void __amDmaNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003008: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000300C: addiu       $v1, $v1, -0x6DD0
    ctx->r3 = ADD32(ctx->r3, -0X6DD0);
    // 0x80003010: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80003014: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80003018: bne         $t6, $zero, L_80003038
    if (ctx->r14 != 0) {
        // 0x8000301C: addiu       $v0, $v0, 0x2E38
        ctx->r2 = ADD32(ctx->r2, 0X2E38);
            goto L_80003038;
    }
    // 0x8000301C: addiu       $v0, $v0, 0x2E38
    ctx->r2 = ADD32(ctx->r2, 0X2E38);
    // 0x80003020: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80003024: addiu       $t7, $t7, -0x6DC0
    ctx->r15 = ADD32(ctx->r15, -0X6DC0);
    // 0x80003028: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000302C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80003030: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x80003034: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_80003038:
    // 0x80003038: jr          $ra
    // 0x8000303C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    return;
    // 0x8000303C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void __clearAudioDMA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003040: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80003044: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80003048: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8000304C: addiu       $s4, $s4, -0x397C
    ctx->r20 = ADD32(ctx->r20, -0X397C);
    // 0x80003050: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80003054: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80003058: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000305C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80003060: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80003064: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80003068: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8000306C: beq         $t6, $zero, L_800030A4
    if (ctx->r14 == 0) {
        // 0x80003070: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800030A4;
    }
    // 0x80003070: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80003074: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80003078: addiu       $s1, $s1, -0x6510
    ctx->r17 = ADD32(ctx->r17, -0X6510);
    // 0x8000307C: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x80003080: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80003084:
    // 0x80003084: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80003088: jal         0x800C8BB0
    // 0x8000308C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000308C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80003090: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80003094: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80003098: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x8000309C: bne         $at, $zero, L_80003084
    if (ctx->r1 != 0) {
        // 0x800030A0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80003084;
    }
    // 0x800030A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800030A4:
    // 0x800030A4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800030A8: addiu       $s2, $s2, -0x6DD0
    ctx->r18 = ADD32(ctx->r18, -0X6DD0);
    // 0x800030AC: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x800030B0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800030B4: beq         $s0, $zero, L_80003128
    if (ctx->r16 == 0) {
        // 0x800030B8: addiu       $s3, $s3, -0x3980
        ctx->r19 = ADD32(ctx->r19, -0X3980);
            goto L_80003128;
    }
    // 0x800030B8: addiu       $s3, $s3, -0x3980
    ctx->r19 = ADD32(ctx->r19, -0X3980);
L_800030BC:
    // 0x800030BC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800030C0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800030C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800030C8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800030CC: sltu        $at, $t0, $t8
    ctx->r1 = ctx->r8 < ctx->r24 ? 1 : 0;
    // 0x800030D0: beq         $at, $zero, L_80003120
    if (ctx->r1 == 0) {
        // 0x800030D4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80003120;
    }
    // 0x800030D4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800030D8: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x800030DC: nop

    // 0x800030E0: bne         $s0, $t1, L_800030EC
    if (ctx->r16 != ctx->r9) {
        // 0x800030E4: nop
    
            goto L_800030EC;
    }
    // 0x800030E4: nop

    // 0x800030E8: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_800030EC:
    // 0x800030EC: jal         0x800C8760
    // 0x800030F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800030F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800030F4: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x800030F8: nop

    // 0x800030FC: beq         $a1, $zero, L_80003114
    if (ctx->r5 == 0) {
        // 0x80003100: nop
    
            goto L_80003114;
    }
    // 0x80003100: nop

    // 0x80003104: jal         0x800C8790
    // 0x80003108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x80003108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8000310C: b           L_80003120
    // 0x80003110: nop

        goto L_80003120;
    // 0x80003110: nop

L_80003114:
    // 0x80003114: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
    // 0x80003118: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8000311C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80003120:
    // 0x80003120: bne         $s1, $zero, L_800030BC
    if (ctx->r17 != 0) {
        // 0x80003124: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800030BC;
    }
    // 0x80003124: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80003128:
    // 0x80003128: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8000312C: addiu       $s3, $s3, -0x3980
    ctx->r19 = ADD32(ctx->r19, -0X3980);
    // 0x80003130: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80003134: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80003138: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000313C: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x80003140: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80003144: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80003148: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000314C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80003150: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80003154: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80003158: jr          $ra
    // 0x8000315C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8000315C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void __scMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800795AC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800795B0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800795B4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800795B8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800795BC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800795C0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800795C4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800795C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800795CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800795D0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800795D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800795D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800795DC: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x800795E0: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x800795E4: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x800795E8: addiu       $s3, $a0, 0x40
    ctx->r19 = ADD32(ctx->r4, 0X40);
    // 0x800795EC: addiu       $s4, $sp, 0x64
    ctx->r20 = ADD32(ctx->r29, 0X64);
    // 0x800795F0: addiu       $s5, $zero, 0x63
    ctx->r21 = ADD32(0, 0X63);
    // 0x800795F4: addiu       $s6, $zero, 0x29A
    ctx->r22 = ADD32(0, 0X29A);
    // 0x800795F8: addiu       $s7, $zero, 0x29B
    ctx->r23 = ADD32(0, 0X29B);
    // 0x800795FC: addiu       $fp, $zero, 0x29C
    ctx->r30 = ADD32(0, 0X29C);
    // 0x80079600: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079604:
    // 0x80079604: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80079608: jal         0x800C8BB0
    // 0x8007960C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8007960C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80079610: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80079614: nop

    // 0x80079618: beq         $t6, $s5, L_80079678
    if (ctx->r14 == ctx->r21) {
        // 0x8007961C: nop
    
            goto L_80079678;
    }
    // 0x8007961C: nop

    // 0x80079620: beq         $t6, $s6, L_80079648
    if (ctx->r14 == ctx->r22) {
        // 0x80079624: nop
    
            goto L_80079648;
    }
    // 0x80079624: nop

    // 0x80079628: beq         $t6, $s7, L_80079658
    if (ctx->r14 == ctx->r23) {
        // 0x8007962C: nop
    
            goto L_80079658;
    }
    // 0x8007962C: nop

    // 0x80079630: beq         $t6, $fp, L_80079668
    if (ctx->r14 == ctx->r30) {
        // 0x80079634: addiu       $at, $zero, 0x29D
        ctx->r1 = ADD32(0, 0X29D);
            goto L_80079668;
    }
    // 0x80079634: addiu       $at, $zero, 0x29D
    ctx->r1 = ADD32(0, 0X29D);
    // 0x80079638: beq         $t6, $at, L_80079688
    if (ctx->r14 == ctx->r1) {
        // 0x8007963C: nop
    
            goto L_80079688;
    }
    // 0x8007963C: nop

    // 0x80079640: b           L_800796C4
    // 0x80079644: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
        goto L_800796C4;
    // 0x80079644: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
L_80079648:
    // 0x80079648: jal         0x80079818
    // 0x8007964C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    static_3_80079818(rdram, ctx);
        goto after_1;
    // 0x8007964C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80079650: b           L_80079604
    // 0x80079654: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079604;
    // 0x80079654: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079658:
    // 0x80079658: jal         0x80079B44
    // 0x8007965C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __scHandleRSP(rdram, ctx);
        goto after_2;
    // 0x8007965C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80079660: b           L_80079604
    // 0x80079664: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079604;
    // 0x80079664: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079668:
    // 0x80079668: jal         0x80079D5C
    // 0x8007966C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __scHandleRDP(rdram, ctx);
        goto after_3;
    // 0x8007966C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80079670: b           L_80079604
    // 0x80079674: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079604;
    // 0x80079674: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079678:
    // 0x80079678: jal         0x80079760
    // 0x8007967C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80079760(rdram, ctx);
        goto after_4;
    // 0x8007967C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80079680: b           L_80079604
    // 0x80079684: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079604;
    // 0x80079684: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079688:
    // 0x80079688: lw          $s0, 0x260($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X260);
    // 0x8007968C: addiu       $s1, $s2, 0x20
    ctx->r17 = ADD32(ctx->r18, 0X20);
    // 0x80079690: beq         $s0, $zero, L_80079604
    if (ctx->r16 == 0) {
        // 0x80079694: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80079604;
    }
    // 0x80079694: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80079698:
    // 0x80079698: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8007969C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800796A0: jal         0x800C8E30
    // 0x800796A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x800796A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x800796A8: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x800796AC: nop

    // 0x800796B0: bne         $s0, $zero, L_80079698
    if (ctx->r16 != 0) {
        // 0x800796B4: nop
    
            goto L_80079698;
    }
    // 0x800796B4: nop

    // 0x800796B8: b           L_80079604
    // 0x800796BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079604;
    // 0x800796BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800796C0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
L_800796C4:
    // 0x800796C4: jal         0x80079F40
    // 0x800796C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    static_3_80079F40(rdram, ctx);
        goto after_6;
    // 0x800796C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800796CC: lw          $t7, 0x274($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X274);
    // 0x800796D0: lw          $t0, 0x278($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X278);
    // 0x800796D4: sltiu       $t8, $t7, 0x1
    ctx->r24 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800796D8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800796DC: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800796E0: or          $s0, $t9, $t1
    ctx->r16 = ctx->r25 | ctx->r9;
    // 0x800796E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800796E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800796EC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800796F0: jal         0x8007A0D4
    // 0x800796F4: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    static_3_8007A0D4(rdram, ctx);
        goto after_7;
    // 0x800796F4: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_7:
    // 0x800796F8: beq         $v0, $s0, L_80079604
    if (ctx->r2 == ctx->r16) {
        // 0x800796FC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80079604;
    }
    // 0x800796FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80079700: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80079704: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80079708: jal         0x80079FA8
    // 0x8007970C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    static_3_80079FA8(rdram, ctx);
        goto after_8;
    // 0x8007970C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x80079710: b           L_80079604
    // 0x80079714: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80079604;
    // 0x80079714: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80079718: nop

    // 0x8007971C: nop

    // 0x80079720: nop

    // 0x80079724: nop

    // 0x80079728: nop

    // 0x8007972C: nop

    // 0x80079730: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80079734: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80079738: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007973C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80079740: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80079744: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80079748: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007974C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80079750: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80079754: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80079758: jr          $ra
    // 0x8007975C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8007975C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void __scHandleRSP(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_scheduler_sp_event_valid(uint8_t*, recomp_context*); if (!dkr_scheduler_sp_event_valid(rdram, ctx)) { return; }
    // 0x80079B44: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80079B48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80079B4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80079B50: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80079B54: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80079B58: lw          $a1, 0x274($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X274);
    // 0x80079B5C: sw          $zero, 0x274($a0)
    MEM_W(0X274, ctx->r4) = 0;
    // 0x80079B60: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80079B64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079B68: bne         $t6, $at, L_80079C50
    if (ctx->r14 != ctx->r1) {
        // 0x80079B6C: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80079C50;
    }
    // 0x80079B6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80079B70: jal         0x800C78D0
    // 0x80079B74: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x80079B74: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80079B78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80079B7C: addiu       $v1, $v1, 0x6124
    ctx->r3 = ADD32(ctx->r3, 0X6124);
    // 0x80079B80: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80079B84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80079B88: lw          $t8, 0x6120($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6120);
    // 0x80079B8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80079B90: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80079B94: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80079B98: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80079B9C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80079BA0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80079BA4: addiu       $a3, $a3, -0x18C0
    ctx->r7 = ADD32(ctx->r7, -0X18C0);
    // 0x80079BA8: addiu       $a2, $a2, -0x18BC
    ctx->r6 = ADD32(ctx->r6, -0X18BC);
    // 0x80079BAC: addiu       $a0, $a0, -0x18B4
    ctx->r4 = ADD32(ctx->r4, -0X18B4);
    // 0x80079BB0: bgez        $t9, L_80079BC8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80079BB4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80079BC8;
    }
    // 0x80079BB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079BB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80079BBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80079BC0: nop

    // 0x80079BC4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80079BC8:
    // 0x80079BC8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80079BCC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80079BD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079BD4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80079BD8: lwc1        $f18, 0x796C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X796C);
    // 0x80079BDC: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80079BE0: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80079BE4: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80079BE8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80079BEC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80079BF0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80079BF4: nop

    // 0x80079BF8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80079BFC: add.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80079C00: bc1f        L_80079C0C
    if (!c1cs) {
        // 0x80079C04: swc1        $f6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
            goto L_80079C0C;
    }
    // 0x80079C04: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x80079C08: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_80079C0C:
    // 0x80079C0C: lw          $v0, -0x18B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X18B0);
    // 0x80079C10: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80079C14: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80079C18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80079C1C: mfhi        $t0
    ctx->r8 = hi;
    // 0x80079C20: beq         $t0, $at, L_80079C2C
    if (ctx->r8 == ctx->r1) {
        // 0x80079C24: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80079C2C;
    }
    // 0x80079C24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079C28: bne         $t0, $at, L_80079C50
    if (ctx->r8 != ctx->r1) {
        // 0x80079C2C: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_80079C50;
    }
L_80079C2C:
    // 0x80079C2C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80079C30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80079C34: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80079C38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80079C3C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80079C40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079C44: swc1        $f4, -0x18B8($at)
    MEM_W(-0X18B8, ctx->r1) = ctx->f4.u32l;
    // 0x80079C48: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x80079C4C: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_80079C50:
    // 0x80079C50: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80079C54: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80079C58: andi        $t1, $v0, 0x10
    ctx->r9 = ctx->r2 & 0X10;
    // 0x80079C5C: beq         $t1, $zero, L_80079CF8
    if (ctx->r9 == 0) {
        // 0x80079C60: and         $t2, $v0, $at
        ctx->r10 = ctx->r2 & ctx->r1;
            goto L_80079CF8;
    }
    // 0x80079C60: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x80079C64: addiu       $a0, $a1, 0x10
    ctx->r4 = ADD32(ctx->r5, 0X10);
    // 0x80079C68: jal         0x800D1DF0
    // 0x80079C6C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_1;
    // 0x80079C6C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_1:
    // 0x80079C70: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80079C74: beq         $v0, $zero, L_80079CCC
    if (ctx->r2 == 0) {
        // 0x80079C78: addiu       $at, $zero, -0x3
        ctx->r1 = ADD32(0, -0X3);
            goto L_80079CCC;
    }
    // 0x80079C78: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80079C7C: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x80079C80: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    // 0x80079C84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80079C88: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x80079C8C: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x80079C90: bne         $t5, $at, L_80079CB8
    if (ctx->r13 != ctx->r1) {
        // 0x80079C94: sw          $t3, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r11;
            goto L_80079CB8;
    }
    // 0x80079C94: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x80079C98: lw          $t6, 0x268($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X268);
    // 0x80079C9C: nop

    // 0x80079CA0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80079CA4: lw          $t7, 0x270($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X270);
    // 0x80079CA8: sw          $a1, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r5;
    // 0x80079CAC: bne         $t7, $zero, L_80079CB8
    if (ctx->r15 != 0) {
        // 0x80079CB0: nop
    
            goto L_80079CB8;
    }
    // 0x80079CB0: nop

    // 0x80079CB4: sw          $a1, 0x270($s0)
    MEM_W(0X270, ctx->r16) = ctx->r5;
L_80079CB8:
    // 0x80079CB8: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80079CBC: nop

    // 0x80079CC0: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x80079CC4: b           L_80079CE4
    // 0x80079CC8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80079CE4;
    // 0x80079CC8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80079CCC:
    // 0x80079CCC: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80079CD0: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80079CD4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80079CD8: andi        $t1, $v0, 0x7
    ctx->r9 = ctx->r2 & 0X7;
    // 0x80079CDC: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80079CE0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80079CE4:
    // 0x80079CE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80079CE8: beq         $v0, $at, L_80079D04
    if (ctx->r2 == ctx->r1) {
        // 0x80079CEC: nop
    
            goto L_80079D04;
    }
    // 0x80079CEC: nop

    // 0x80079CF0: b           L_80079D08
    // 0x80079CF4: lw          $t3, 0x274($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X274);
        goto L_80079D08;
    // 0x80079CF4: lw          $t3, 0x274($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X274);
L_80079CF8:
    // 0x80079CF8: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x80079CFC: jal         0x80079E40
    // 0x80079D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    static_3_80079E40(rdram, ctx);
        goto after_2;
    // 0x80079D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80079D04:
    // 0x80079D04: lw          $t3, 0x274($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X274);
L_80079D08:
    // 0x80079D08: lw          $t6, 0x278($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X278);
    // 0x80079D0C: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80079D10: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80079D14: sltiu       $t7, $t6, 0x1
    ctx->r15 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80079D18: or          $a3, $t5, $t7
    ctx->r7 = ctx->r13 | ctx->r15;
    // 0x80079D1C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80079D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079D24: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80079D28: jal         0x8007A0D4
    // 0x80079D2C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    static_3_8007A0D4(rdram, ctx);
        goto after_3;
    // 0x80079D2C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80079D30: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80079D34: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80079D38: beq         $v0, $a3, L_80079D50
    if (ctx->r2 == ctx->r7) {
        // 0x80079D3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80079D50;
    }
    // 0x80079D3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80079D40: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80079D44: jal         0x80079FA8
    // 0x80079D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    static_3_80079FA8(rdram, ctx);
        goto after_4;
    // 0x80079D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80079D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80079D50:
    extern void dkr_scheduler_sp_handled(uint8_t*, recomp_context*); dkr_scheduler_sp_handled(rdram, ctx);
    // 0x80079D50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80079D54: jr          $ra
    // 0x80079D58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80079D58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void __scHandleRDP(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_scheduler_dp_event_valid(uint8_t*, recomp_context*); if (!dkr_scheduler_dp_event_valid(rdram, ctx)) { return; }
    // 0x80079D5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80079D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079D64: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80079D68: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80079D6C: lw          $a1, 0x278($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X278);
    // 0x80079D70: sw          $zero, 0x278($a0)
    MEM_W(0X278, ctx->r4) = 0;
    // 0x80079D74: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80079D78: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80079D7C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80079D80: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80079D84: jal         0x80079E40
    // 0x80079D88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    static_3_80079E40(rdram, ctx);
        goto after_0;
    // 0x80079D88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80079D8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80079D90: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80079D94: lw          $t8, 0x274($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X274);
    // 0x80079D98: lw          $t1, 0x278($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X278);
    // 0x80079D9C: sltiu       $t9, $t8, 0x1
    ctx->r25 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80079DA0: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80079DA4: sltiu       $t2, $t1, 0x1
    ctx->r10 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80079DA8: or          $a3, $t0, $t2
    ctx->r7 = ctx->r8 | ctx->r10;
    // 0x80079DAC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80079DB0: jal         0x8007A0D4
    // 0x80079DB4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    static_3_8007A0D4(rdram, ctx);
        goto after_1;
    // 0x80079DB4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80079DB8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80079DBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80079DC0: beq         $v0, $a3, L_80079DDC
    if (ctx->r2 == ctx->r7) {
        // 0x80079DC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80079DDC;
    }
    // 0x80079DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079DC8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80079DCC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80079DD0: jal         0x80079FA8
    // 0x80079DD4: nop

    static_3_80079FA8(rdram, ctx);
        goto after_2;
    // 0x80079DD4: nop

    after_2:
    // 0x80079DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80079DDC:
    extern void dkr_scheduler_dp_handled(uint8_t*, recomp_context*); dkr_scheduler_dp_handled(rdram, ctx);
    // 0x80079DDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80079DE0: jr          $ra
    // 0x80079DE4: nop

    return;
    // 0x80079DE4: nop

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
        goto after_3;
    // 0x80079DFC: nop

    after_3:
    // 0x80079E00: jal         0x800D1EB0
    // 0x80079E04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_4;
    // 0x80079E04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_4:
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
RECOMP_FUNC void static_3_800041FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800041FC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80004200: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004204: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80004208: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000420C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004210: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004214: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80004218: andi        $s4, $a2, 0xFFFF
    ctx->r20 = ctx->r6 & 0XFFFF;
    // 0x8000421C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004224: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80004228: jal         0x800C9A30
    // 0x8000422C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8000422C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80004230: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80004234: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x80004238: nop

    // 0x8000423C: beq         $s0, $zero, L_800042A4
    if (ctx->r16 == 0) {
        // 0x80004240: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800042A4;
    }
    // 0x80004240: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80004244:
    // 0x80004244: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80004248: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000424C: bne         $s3, $t6, L_80004298
    if (ctx->r19 != ctx->r14) {
        // 0x80004250: nop
    
            goto L_80004298;
    }
    // 0x80004250: nop

    // 0x80004254: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
    // 0x80004258: nop

    // 0x8000425C: and         $t8, $t7, $s4
    ctx->r24 = ctx->r15 & ctx->r20;
    // 0x80004260: beq         $t8, $zero, L_80004298
    if (ctx->r24 == 0) {
        // 0x80004264: nop
    
            goto L_80004298;
    }
    // 0x80004264: nop

    // 0x80004268: beq         $s1, $zero, L_80004284
    if (ctx->r17 == 0) {
        // 0x8000426C: nop
    
            goto L_80004284;
    }
    // 0x8000426C: nop

    // 0x80004270: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80004274: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80004278: nop

    // 0x8000427C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80004280: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_80004284:
    // 0x80004284: jal         0x800C8760
    // 0x80004288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x80004288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000428C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004290: jal         0x800C8790
    // 0x80004294: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x80004294: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_80004298:
    // 0x80004298: bne         $s1, $zero, L_80004244
    if (ctx->r17 != 0) {
        // 0x8000429C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80004244;
    }
    // 0x8000429C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800042A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_800042A4:
    // 0x800042A4: jal         0x800C9A30
    // 0x800042A8: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800042A8: nop

    after_3:
    // 0x800042AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800042B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800042B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800042B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800042BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800042C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800042C4: jr          $ra
    // 0x800042C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800042C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void static_3_80062A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062A3C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80062A40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062A44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062A48: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x80062A4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80062A50: beq         $a2, $zero, L_80062AF0
    if (ctx->r6 == 0) {
        // 0x80062A54: addiu       $a1, $sp, 0x28
        ctx->r5 = ADD32(ctx->r29, 0X28);
            goto L_80062AF0;
    }
    // 0x80062A54: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80062A58: jal         0x800C7D04
    // 0x80062A5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    alCSeqNextEvent(rdram, ctx);
        goto after_0;
    // 0x80062A5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80062A60: lh          $t6, 0x28($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X28);
    // 0x80062A64: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80062A68: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80062A6C: sltiu       $at, $t7, 0x14
    ctx->r1 = ctx->r15 < 0X14 ? 1 : 0;
    // 0x80062A70: beq         $at, $zero, L_80062AF0
    if (ctx->r1 == 0) {
        // 0x80062A74: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80062AF0;
    }
    // 0x80062A74: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80062A78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80062A7C: addu        $at, $at, $t7
    gpr jr_addend_80062A88 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80062A80: lw          $t7, 0x6C90($at)
    ctx->r15 = ADD32(ctx->r1, 0X6C90);
    // 0x80062A84: nop

    // 0x80062A88: jr          $t7
    // 0x80062A8C: nop

    switch (jr_addend_80062A88 >> 2) {
        case 0: goto L_80062A90; break;
        case 1: goto L_80062AF0; break;
        case 2: goto L_80062AA8; break;
        case 3: goto L_80062AC0; break;
        case 4: goto L_80062AF0; break;
        case 5: goto L_80062AF0; break;
        case 6: goto L_80062AF0; break;
        case 7: goto L_80062AF0; break;
        case 8: goto L_80062AF0; break;
        case 9: goto L_80062AF0; break;
        case 10: goto L_80062AF0; break;
        case 11: goto L_80062AF0; break;
        case 12: goto L_80062AF0; break;
        case 13: goto L_80062AF0; break;
        case 14: goto L_80062AF0; break;
        case 15: goto L_80062AF0; break;
        case 16: goto L_80062AF0; break;
        case 17: goto L_80062AE8; break;
        case 18: goto L_80062AE8; break;
        case 19: goto L_80062AE8; break;
        default: switch_error(__func__, 0x80062A88, 0x800E6C90);
    }
    // 0x80062A8C: nop

L_80062A90:
    // 0x80062A90: jal         0x80062B00
    // 0x80062A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    static_3_80062B00(rdram, ctx);
        goto after_1;
    // 0x80062A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80062A98: jal         0x800629CC
    // 0x80062A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_2;
    // 0x80062A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80062AA0: b           L_80062AF4
    // 0x80062AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80062AF4;
    // 0x80062AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80062AA8:
    // 0x80062AA8: jal         0x800637EC
    // 0x80062AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    static_3_800637EC(rdram, ctx);
        goto after_3;
    // 0x80062AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80062AB0: jal         0x800629CC
    // 0x80062AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_4;
    // 0x80062AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80062AB8: b           L_80062AF4
    // 0x80062ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80062AF4;
    // 0x80062ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80062AC0:
    // 0x80062AC0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80062AC4: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x80062AC8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80062ACC: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80062AD0: sh          $t9, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r25;
    // 0x80062AD4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80062AD8: jal         0x800C91AC
    // 0x80062ADC: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x80062ADC: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    after_5:
    // 0x80062AE0: b           L_80062AF4
    // 0x80062AE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80062AF4;
    // 0x80062AE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80062AE8:
    // 0x80062AE8: jal         0x800629CC
    // 0x80062AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_6;
    // 0x80062AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80062AF0:
    // 0x80062AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80062AF4:
    // 0x80062AF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062AF8: jr          $ra
    // 0x80062AFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80062AFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void static_3_80062B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062B00: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80062B04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80062B08: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80062B0C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80062B10: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80062B14: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80062B18: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80062B1C: lbu         $a3, 0x8($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X8);
    // 0x80062B20: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80062B24: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x80062B28: sb          $t7, 0xCA($sp)
    MEM_B(0XCA, ctx->r29) = ctx->r15;
    // 0x80062B2C: lbu         $s3, 0xA($a1)
    ctx->r19 = MEM_BU(ctx->r5, 0XA);
    // 0x80062B30: andi        $v1, $a3, 0xF0
    ctx->r3 = ctx->r7 & 0XF0;
    // 0x80062B34: andi        $t6, $a3, 0xF
    ctx->r14 = ctx->r7 & 0XF;
    // 0x80062B38: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80062B3C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80062B40: bne         $v1, $a2, L_80062BE0
    if (ctx->r3 != ctx->r6) {
        // 0x80062B44: or          $a3, $t6, $zero
        ctx->r7 = ctx->r14 | 0;
            goto L_80062BE0;
    }
    // 0x80062B44: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80062B48: andi        $s1, $t7, 0xFF
    ctx->r17 = ctx->r15 & 0XFF;
    // 0x80062B4C: addiu       $at, $zero, 0x6A
    ctx->r1 = ADD32(0, 0X6A);
    // 0x80062B50: bne         $s1, $at, L_80062BC0
    if (ctx->r17 != ctx->r1) {
        // 0x80062B54: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80062BC0;
    }
    // 0x80062B54: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80062B58: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80062B5C: lhu         $t8, 0x30($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X30);
    // 0x80062B60: sllv        $t1, $t0, $s3
    ctx->r9 = S32(ctx->r8 << (ctx->r19 & 31));
    // 0x80062B64: lw          $s0, 0x64($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X64);
    // 0x80062B68: nor         $t2, $t1, $zero
    ctx->r10 = ~(ctx->r9 | 0);
    // 0x80062B6C: and         $t3, $t8, $t2
    ctx->r11 = ctx->r24 & ctx->r10;
    // 0x80062B70: beq         $s0, $zero, L_800637CC
    if (ctx->r16 == 0) {
        // 0x80062B74: sh          $t3, 0x30($a0)
        MEM_H(0X30, ctx->r4) = ctx->r11;
            goto L_800637CC;
    }
    // 0x80062B74: sh          $t3, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r11;
    // 0x80062B78: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
L_80062B7C:
    // 0x80062B7C: lbu         $t5, 0x31($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X31);
    // 0x80062B80: nop

    // 0x80062B84: bne         $t4, $t5, L_80062BA8
    if (ctx->r12 != ctx->r13) {
        // 0x80062B88: nop
    
            goto L_80062BA8;
    }
    // 0x80062B88: nop

    // 0x80062B8C: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80062B90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062B94: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80062B98: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80062B9C: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    // 0x80062BA0: jal         0x8000AB00
    // 0x80062BA4: nop

    __seqpReleaseVoice(rdram, ctx);
        goto after_0;
    // 0x80062BA4: nop

    after_0:
L_80062BA8:
    // 0x80062BA8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80062BAC: nop

    // 0x80062BB0: bne         $s0, $zero, L_80062B7C
    if (ctx->r16 != 0) {
        // 0x80062BB4: lw          $t4, 0x58($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X58);
            goto L_80062B7C;
    }
    // 0x80062BB4: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80062BB8: b           L_800637D0
    // 0x80062BBC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x80062BBC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80062BC0:
    // 0x80062BC0: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80062BC4: bne         $s1, $at, L_80062BE0
    if (ctx->r17 != ctx->r1) {
        // 0x80062BC8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80062BE0;
    }
    // 0x80062BC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80062BCC: lhu         $t0, 0x30($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X30);
    // 0x80062BD0: sllv        $t1, $t9, $s3
    ctx->r9 = S32(ctx->r25 << (ctx->r19 & 31));
    // 0x80062BD4: or          $t8, $t0, $t1
    ctx->r24 = ctx->r8 | ctx->r9;
    // 0x80062BD8: b           L_800637CC
    // 0x80062BDC: sh          $t8, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r24;
        goto L_800637CC;
    // 0x80062BDC: sh          $t8, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r24;
L_80062BE0:
    // 0x80062BE0: lhu         $t4, 0x30($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X30);
    // 0x80062BE4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80062BE8: sllv        $t3, $t2, $a3
    ctx->r11 = S32(ctx->r10 << (ctx->r7 & 31));
    // 0x80062BEC: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x80062BF0: bne         $t5, $zero, L_80062C10
    if (ctx->r13 != 0) {
        // 0x80062BF4: or          $s4, $a3, $zero
        ctx->r20 = ctx->r7 | 0;
            goto L_80062C10;
    }
    // 0x80062BF4: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80062BF8: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x80062BFC: beq         $v1, $at, L_80062C14
    if (ctx->r3 == ctx->r1) {
        // 0x80062C00: addiu       $t6, $v1, -0x80
        ctx->r14 = ADD32(ctx->r3, -0X80);
            goto L_80062C14;
    }
    // 0x80062C00: addiu       $t6, $v1, -0x80
    ctx->r14 = ADD32(ctx->r3, -0X80);
    // 0x80062C04: beq         $v1, $a2, L_80062C10
    if (ctx->r3 == ctx->r6) {
        // 0x80062C08: addiu       $at, $zero, 0xE0
        ctx->r1 = ADD32(0, 0XE0);
            goto L_80062C10;
    }
    // 0x80062C08: addiu       $at, $zero, 0xE0
    ctx->r1 = ADD32(0, 0XE0);
    // 0x80062C0C: bne         $v1, $at, L_800637CC
    if (ctx->r3 != ctx->r1) {
        // 0x80062C10: addiu       $t6, $v1, -0x80
        ctx->r14 = ADD32(ctx->r3, -0X80);
            goto L_800637CC;
    }
L_80062C10:
    // 0x80062C10: addiu       $t6, $v1, -0x80
    ctx->r14 = ADD32(ctx->r3, -0X80);
L_80062C14:
    // 0x80062C14: sltiu       $at, $t6, 0x61
    ctx->r1 = ctx->r14 < 0X61 ? 1 : 0;
    // 0x80062C18: beq         $at, $zero, L_800637CC
    if (ctx->r1 == 0) {
        // 0x80062C1C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800637CC;
    }
    // 0x80062C1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80062C20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80062C24: addu        $at, $at, $t6
    gpr jr_addend_80062C30 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80062C28: lw          $t6, 0x6CE0($at)
    ctx->r14 = ADD32(ctx->r1, 0X6CE0);
    // 0x80062C2C: nop

    // 0x80062C30: jr          $t6
    // 0x80062C34: nop

    switch (jr_addend_80062C30 >> 2) {
        case 0: goto L_80063068; break;
        case 1: goto L_800637CC; break;
        case 2: goto L_800637CC; break;
        case 3: goto L_800637CC; break;
        case 4: goto L_800637CC; break;
        case 5: goto L_800637CC; break;
        case 6: goto L_800637CC; break;
        case 7: goto L_800637CC; break;
        case 8: goto L_800637CC; break;
        case 9: goto L_800637CC; break;
        case 10: goto L_800637CC; break;
        case 11: goto L_800637CC; break;
        case 12: goto L_800637CC; break;
        case 13: goto L_800637CC; break;
        case 14: goto L_800637CC; break;
        case 15: goto L_800637CC; break;
        case 16: goto L_80062C38; break;
        case 17: goto L_800637CC; break;
        case 18: goto L_800637CC; break;
        case 19: goto L_800637CC; break;
        case 20: goto L_800637CC; break;
        case 21: goto L_800637CC; break;
        case 22: goto L_800637CC; break;
        case 23: goto L_800637CC; break;
        case 24: goto L_800637CC; break;
        case 25: goto L_800637CC; break;
        case 26: goto L_800637CC; break;
        case 27: goto L_800637CC; break;
        case 28: goto L_800637CC; break;
        case 29: goto L_800637CC; break;
        case 30: goto L_800637CC; break;
        case 31: goto L_800637CC; break;
        case 32: goto L_800630C0; break;
        case 33: goto L_800637CC; break;
        case 34: goto L_800637CC; break;
        case 35: goto L_800637CC; break;
        case 36: goto L_800637CC; break;
        case 37: goto L_800637CC; break;
        case 38: goto L_800637CC; break;
        case 39: goto L_800637CC; break;
        case 40: goto L_800637CC; break;
        case 41: goto L_800637CC; break;
        case 42: goto L_800637CC; break;
        case 43: goto L_800637CC; break;
        case 44: goto L_800637CC; break;
        case 45: goto L_800637CC; break;
        case 46: goto L_800637CC; break;
        case 47: goto L_800637CC; break;
        case 48: goto L_8006319C; break;
        case 49: goto L_800637CC; break;
        case 50: goto L_800637CC; break;
        case 51: goto L_800637CC; break;
        case 52: goto L_800637CC; break;
        case 53: goto L_800637CC; break;
        case 54: goto L_800637CC; break;
        case 55: goto L_800637CC; break;
        case 56: goto L_800637CC; break;
        case 57: goto L_800637CC; break;
        case 58: goto L_800637CC; break;
        case 59: goto L_800637CC; break;
        case 60: goto L_800637CC; break;
        case 61: goto L_800637CC; break;
        case 62: goto L_800637CC; break;
        case 63: goto L_800637CC; break;
        case 64: goto L_800636E0; break;
        case 65: goto L_800637CC; break;
        case 66: goto L_800637CC; break;
        case 67: goto L_800637CC; break;
        case 68: goto L_800637CC; break;
        case 69: goto L_800637CC; break;
        case 70: goto L_800637CC; break;
        case 71: goto L_800637CC; break;
        case 72: goto L_800637CC; break;
        case 73: goto L_800637CC; break;
        case 74: goto L_800637CC; break;
        case 75: goto L_800637CC; break;
        case 76: goto L_800637CC; break;
        case 77: goto L_800637CC; break;
        case 78: goto L_800637CC; break;
        case 79: goto L_800637CC; break;
        case 80: goto L_80063124; break;
        case 81: goto L_800637CC; break;
        case 82: goto L_800637CC; break;
        case 83: goto L_800637CC; break;
        case 84: goto L_800637CC; break;
        case 85: goto L_800637CC; break;
        case 86: goto L_800637CC; break;
        case 87: goto L_800637CC; break;
        case 88: goto L_800637CC; break;
        case 89: goto L_800637CC; break;
        case 90: goto L_800637CC; break;
        case 91: goto L_800637CC; break;
        case 92: goto L_800637CC; break;
        case 93: goto L_800637CC; break;
        case 94: goto L_800637CC; break;
        case 95: goto L_800637CC; break;
        case 96: goto L_80063714; break;
        default: switch_error(__func__, 0x80062C30, 0x800E6CE0);
    }
    // 0x80062C34: nop

L_80062C38:
    // 0x80062C38: beq         $s3, $zero, L_8006306C
    if (ctx->r19 == 0) {
        // 0x80062C3C: lbu         $a1, 0xCA($sp)
        ctx->r5 = MEM_BU(ctx->r29, 0XCA);
            goto L_8006306C;
    }
    // 0x80062C3C: lbu         $a1, 0xCA($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCA);
    // 0x80062C40: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x80062C44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80062C48: bne         $t7, $at, L_800637CC
    if (ctx->r15 != ctx->r1) {
        // 0x80062C4C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800637CC;
    }
    // 0x80062C4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062C50: lbu         $a1, 0xCA($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCA);
    // 0x80062C54: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    // 0x80062C58: sb          $a3, 0xCB($sp)
    MEM_B(0XCB, ctx->r29) = ctx->r7;
    // 0x80062C5C: jal         0x8000A8D0
    // 0x80062C60: sw          $s0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r16;
    __lookupSoundQuick(rdram, ctx);
        goto after_1;
    // 0x80062C60: sw          $s0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r16;
    after_1:
    // 0x80062C64: beq         $v0, $zero, L_800637CC
    if (ctx->r2 == 0) {
        // 0x80062C68: sw          $v0, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r2;
            goto L_800637CC;
    }
    // 0x80062C68: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80062C6C: lbu         $a3, 0xCB($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XCB);
    // 0x80062C70: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x80062C74: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x80062C78: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80062C7C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80062C80: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80062C84: lbu         $t1, 0x8($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X8);
    // 0x80062C88: lbu         $a1, 0xCA($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCA);
    // 0x80062C8C: sh          $zero, 0x96($sp)
    MEM_H(0X96, ctx->r29) = 0;
    // 0x80062C90: sb          $zero, 0x98($sp)
    MEM_B(0X98, ctx->r29) = 0;
    // 0x80062C94: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80062C98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80062C9C: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    // 0x80062CA0: jal         0x8000A71C
    // 0x80062CA4: sh          $t1, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r9;
    __mapVoice(rdram, ctx);
        goto after_2;
    // 0x80062CA4: sh          $t1, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r9;
    after_2:
    // 0x80062CA8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062CAC: beq         $v0, $zero, L_800637CC
    if (ctx->r2 == 0) {
        // 0x80062CB0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800637CC;
    }
    // 0x80062CB0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80062CB4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062CB8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80062CBC: lbu         $s1, 0xCA($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0XCA);
    // 0x80062CC0: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x80062CC4: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80062CC8: jal         0x800C9508
    // 0x80062CCC: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    alSynAllocVoice(rdram, ctx);
        goto after_3;
    // 0x80062CCC: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    after_3:
    // 0x80062CD0: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062CD4: beq         $v0, $zero, L_80062CF8
    if (ctx->r2 == 0) {
        // 0x80062CD8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80062CF8;
    }
    // 0x80062CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80062CDC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80062CE0: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062CE4: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    // 0x80062CE8: jal         0x80065A80
    // 0x80062CEC: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    func_80065A80(rdram, ctx);
        goto after_4;
    // 0x80062CEC: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_4:
    // 0x80062CF0: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062CF4: nop

L_80062CF8:
    // 0x80062CF8: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x80062CFC: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x80062D00: sw          $a1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r5;
    // 0x80062D04: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x80062D08: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80062D0C: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80062D10: lbu         $t4, 0xB($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XB);
    // 0x80062D14: nop

    // 0x80062D18: slti        $at, $t4, 0x40
    ctx->r1 = SIGNED(ctx->r12) < 0X40 ? 1 : 0;
    // 0x80062D1C: bne         $at, $zero, L_80062D2C
    if (ctx->r1 != 0) {
        // 0x80062D20: nop
    
            goto L_80062D2C;
    }
    // 0x80062D20: nop

    // 0x80062D24: b           L_80062D30
    // 0x80062D28: sb          $t5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r13;
        goto L_80062D30;
    // 0x80062D28: sb          $t5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r13;
L_80062D2C:
    // 0x80062D2C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_80062D30:
    // 0x80062D30: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80062D34: nop

    // 0x80062D38: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x80062D3C: lb          $t0, 0x5($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X5);
    // 0x80062D40: subu        $t7, $s1, $t6
    ctx->r15 = SUB32(ctx->r17, ctx->r14);
    // 0x80062D44: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80062D48: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80062D4C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80062D50: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80062D54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80062D58: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80062D5C: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x80062D60: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80062D64: jal         0x800C99E0
    // 0x80062D68: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    alCents2Ratio(rdram, ctx);
        goto after_5;
    // 0x80062D68: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_5:
    // 0x80062D6C: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062D70: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80062D74: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x80062D78: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80062D7C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80062D80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80062D84: lbu         $t4, 0xC($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XC);
    // 0x80062D88: nop

    // 0x80062D8C: sb          $t4, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r12;
    // 0x80062D90: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80062D94: lw          $t5, 0x1C($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C);
    // 0x80062D98: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80062D9C: nop

    // 0x80062DA0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80062DA4: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x80062DA8: addu        $t0, $t5, $t9
    ctx->r8 = ADD32(ctx->r13, ctx->r25);
    // 0x80062DAC: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    // 0x80062DB0: lw          $t1, 0x60($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X60);
    // 0x80062DB4: nop

    // 0x80062DB8: addu        $t8, $t1, $v1
    ctx->r24 = ADD32(ctx->r9, ctx->r3);
    // 0x80062DBC: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x80062DC0: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x80062DC4: lbu         $a2, 0x4($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X4);
    // 0x80062DC8: nop

    // 0x80062DCC: beq         $a2, $zero, L_80062E40
    if (ctx->r6 == 0) {
        // 0x80062DD0: nop
    
            goto L_80062E40;
    }
    // 0x80062DD0: nop

    // 0x80062DD4: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x80062DD8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80062DDC: beq         $v0, $zero, L_80062E40
    if (ctx->r2 == 0) {
        // 0x80062DE0: addiu       $a1, $sp, 0x84
        ctx->r5 = ADD32(ctx->r29, 0X84);
            goto L_80062E40;
    }
    // 0x80062DE0: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80062DE4: lbu         $t2, 0x6($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X6);
    // 0x80062DE8: lbu         $a3, 0x5($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X5);
    // 0x80062DEC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80062DF0: lbu         $t3, 0x7($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X7);
    // 0x80062DF4: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80062DF8: jalr        $v0
    // 0x80062DFC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80062DFC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_6:
    // 0x80062E00: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062E04: beq         $v0, $zero, L_80062E40
    if (ctx->r2 == 0) {
        // 0x80062E08: addiu       $t4, $zero, 0x16
        ctx->r12 = ADD32(0, 0X16);
            goto L_80062E40;
    }
    // 0x80062E08: addiu       $t4, $zero, 0x16
    ctx->r12 = ADD32(0, 0X16);
    // 0x80062E0C: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80062E10: sh          $t4, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r12;
    // 0x80062E14: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x80062E18: addiu       $a0, $s2, 0x48
    ctx->r4 = ADD32(ctx->r18, 0X48);
    // 0x80062E1C: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80062E20: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80062E24: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80062E28: jal         0x800C91AC
    // 0x80062E2C: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x80062E2C: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    after_7:
    // 0x80062E30: lbu         $t7, 0x37($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X37);
    // 0x80062E34: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062E38: ori         $t5, $t7, 0x1
    ctx->r13 = ctx->r15 | 0X1;
    // 0x80062E3C: sb          $t5, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r13;
L_80062E40:
    // 0x80062E40: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80062E44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80062E48: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80062E4C: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80062E50: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80062E54: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80062E58: addiu       $t1, $s2, 0x48
    ctx->r9 = ADD32(ctx->r18, 0X48);
    // 0x80062E5C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80062E60: nop

    // 0x80062E64: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80062E68: beq         $t0, $zero, L_80062EB4
    if (ctx->r8 == 0) {
        // 0x80062E6C: nop
    
            goto L_80062EB4;
    }
    // 0x80062E6C: nop

    // 0x80062E70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80062E74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80062E78: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80062E7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80062E80: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80062E84: nop

    // 0x80062E88: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80062E8C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80062E90: nop

    // 0x80062E94: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80062E98: bne         $t0, $zero, L_80062EAC
    if (ctx->r8 != 0) {
        // 0x80062E9C: nop
    
            goto L_80062EAC;
    }
    // 0x80062E9C: nop

    // 0x80062EA0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80062EA4: b           L_80062EC4
    // 0x80062EA8: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80062EC4;
    // 0x80062EA8: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80062EAC:
    // 0x80062EAC: b           L_80062EC4
    // 0x80062EB0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80062EC4;
    // 0x80062EB0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80062EB4:
    // 0x80062EB4: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80062EB8: nop

    // 0x80062EBC: bltz        $t0, L_80062EAC
    if (SIGNED(ctx->r8) < 0) {
        // 0x80062EC0: nop
    
            goto L_80062EAC;
    }
    // 0x80062EC0: nop

L_80062EC4:
    // 0x80062EC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80062EC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80062ECC: sb          $t0, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r8;
    // 0x80062ED0: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x80062ED4: lbu         $a2, 0x8($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X8);
    // 0x80062ED8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80062EDC: beq         $a2, $zero, L_80062F58
    if (ctx->r6 == 0) {
        // 0x80062EE0: sw          $t1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r9;
            goto L_80062F58;
    }
    // 0x80062EE0: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80062EE4: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x80062EE8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80062EEC: beq         $v0, $zero, L_80062F58
    if (ctx->r2 == 0) {
        // 0x80062EF0: addiu       $a1, $sp, 0x84
        ctx->r5 = ADD32(ctx->r29, 0X84);
            goto L_80062F58;
    }
    // 0x80062EF0: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x80062EF4: lbu         $t8, 0xA($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XA);
    // 0x80062EF8: lbu         $a3, 0x9($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X9);
    // 0x80062EFC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80062F00: lbu         $t2, 0xB($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0XB);
    // 0x80062F04: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80062F08: jalr        $v0
    // 0x80062F0C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x80062F0C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_8:
    // 0x80062F10: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062F14: beq         $v0, $zero, L_80062F58
    if (ctx->r2 == 0) {
        // 0x80062F18: addiu       $t3, $zero, 0x17
        ctx->r11 = ADD32(0, 0X17);
            goto L_80062F58;
    }
    // 0x80062F18: addiu       $t3, $zero, 0x17
    ctx->r11 = ADD32(0, 0X17);
    // 0x80062F1C: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80062F20: lbu         $t6, 0xCB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XCB);
    // 0x80062F24: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80062F28: sh          $t3, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r11;
    // 0x80062F2C: sw          $s0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r16;
    // 0x80062F30: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80062F34: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80062F38: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80062F3C: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    // 0x80062F40: jal         0x800C91AC
    // 0x80062F44: sb          $t6, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r14;
    alEvtqPostEvent(rdram, ctx);
        goto after_9;
    // 0x80062F44: sb          $t6, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r14;
    after_9:
    // 0x80062F48: lbu         $t7, 0x37($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X37);
    // 0x80062F4C: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80062F50: ori         $t5, $t7, 0x2
    ctx->r13 = ctx->r15 | 0X2;
    // 0x80062F54: sb          $t5, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r13;
L_80062F58:
    // 0x80062F58: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80062F5C: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80062F60: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80062F64: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x80062F68: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80062F6C: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x80062F70: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80062F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80062F78: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80062F7C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80062F80: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80062F84: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x80062F88: lbu         $s1, 0xA($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0XA);
    // 0x80062F8C: jal         0x8000AAAC
    // 0x80062F90: nop

    __vsPan(rdram, ctx);
        goto after_10;
    // 0x80062F90: nop

    after_10:
    // 0x80062F94: sb          $v0, 0xA3($sp)
    MEM_B(0XA3, ctx->r29) = ctx->r2;
    // 0x80062F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80062F9C: jal         0x8000A9F8
    // 0x80062FA0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_11;
    // 0x80062FA0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_11:
    // 0x80062FA4: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80062FA8: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80062FAC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80062FB0: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x80062FB4: lw          $s3, 0x0($t1)
    ctx->r19 = MEM_W(ctx->r9, 0X0);
    // 0x80062FB8: lbu         $t8, 0xA3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XA3);
    // 0x80062FBC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80062FC0: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80062FC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80062FC8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80062FCC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80062FD0: jal         0x80065C38
    // 0x80062FD4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    alSynStartVoiceParams(rdram, ctx);
        goto after_12;
    // 0x80062FD4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_12:
    // 0x80062FD8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80062FDC: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80062FE0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80062FE4: sh          $t2, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r10;
    // 0x80062FE8: sw          $t3, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r11;
    // 0x80062FEC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80062FF0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80062FF4: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x80062FF8: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80062FFC: sb          $t7, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r15;
    // 0x80063000: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80063004: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80063008: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x8006300C: jal         0x800C91AC
    // 0x80063010: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    alEvtqPostEvent(rdram, ctx);
        goto after_13;
    // 0x80063010: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    after_13:
    // 0x80063014: lw          $v0, 0xDC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XDC);
    // 0x80063018: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x8006301C: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80063020: ori         $t8, $s4, 0x80
    ctx->r24 = ctx->r20 | 0X80;
    // 0x80063024: beq         $t1, $zero, L_800637CC
    if (ctx->r9 == 0) {
        // 0x80063028: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800637CC;
    }
    // 0x80063028: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006302C: lbu         $t2, 0xCA($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XCA);
    // 0x80063030: sh          $t0, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r8;
    // 0x80063034: sb          $t8, 0xB4($sp)
    MEM_B(0XB4, ctx->r29) = ctx->r24;
    // 0x80063038: sb          $zero, 0xB6($sp)
    MEM_B(0XB6, ctx->r29) = 0;
    // 0x8006303C: sb          $t2, 0xB5($sp)
    MEM_B(0XB5, ctx->r29) = ctx->r10;
    // 0x80063040: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80063044: lw          $t3, 0x24($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X24);
    // 0x80063048: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8006304C: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063050: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80063054: mflo        $a2
    ctx->r6 = lo;
    // 0x80063058: jal         0x800C91AC
    // 0x8006305C: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_14;
    // 0x8006305C: nop

    after_14:
    // 0x80063060: b           L_800637D0
    // 0x80063064: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x80063064: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063068:
    // 0x80063068: lbu         $a1, 0xCA($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCA);
L_8006306C:
    // 0x8006306C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80063070: jal         0x8000A84C
    // 0x80063074: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_15;
    // 0x80063074: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    after_15:
    // 0x80063078: beq         $v0, $zero, L_800637CC
    if (ctx->r2 == 0) {
        // 0x8006307C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800637CC;
    }
    // 0x8006307C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80063080: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x80063084: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80063088: bne         $s1, $t7, L_8006309C
    if (ctx->r17 != ctx->r15) {
        // 0x8006308C: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_8006309C;
    }
    // 0x8006308C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80063090: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80063094: b           L_800637CC
    // 0x80063098: sb          $t4, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r12;
        goto L_800637CC;
    // 0x80063098: sb          $t4, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r12;
L_8006309C:
    // 0x8006309C: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x800630A0: sb          $t5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r13;
    // 0x800630A4: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800630A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800630AC: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x800630B0: jal         0x8000AB00
    // 0x800630B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    __seqpReleaseVoice(rdram, ctx);
        goto after_16;
    // 0x800630B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_16:
    // 0x800630B8: b           L_800637D0
    // 0x800630BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x800630BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800630C0:
    // 0x800630C0: lbu         $a1, 0xCA($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCA);
    // 0x800630C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800630C8: jal         0x8000A84C
    // 0x800630CC: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_17;
    // 0x800630CC: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    after_17:
    // 0x800630D0: beq         $v0, $zero, L_800637CC
    if (ctx->r2 == 0) {
        // 0x800630D4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800637CC;
    }
    // 0x800630D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800630D8: sb          $s3, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r19;
    // 0x800630DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800630E0: jal         0x8000A9F8
    // 0x800630E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_18;
    // 0x800630E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x800630E8: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800630EC: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800630F0: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x800630F4: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x800630F8: jal         0x8000AA88
    // 0x800630FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __vsDelta(rdram, ctx);
        goto after_19;
    // 0x800630FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80063100: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x80063104: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80063108: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8006310C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80063110: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80063114: jal         0x800C9650
    // 0x80063118: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_20;
    // 0x80063118: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_20:
    // 0x8006311C: b           L_800637D0
    // 0x80063120: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x80063120: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063124:
    // 0x80063124: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80063128: nop

    // 0x8006312C: beq         $s0, $zero, L_800637D0
    if (ctx->r16 == 0) {
        // 0x80063130: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800637D0;
    }
    // 0x80063130: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063134:
    // 0x80063134: lbu         $t2, 0x31($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X31);
    // 0x80063138: lbu         $t3, 0xCA($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XCA);
    // 0x8006313C: bne         $s4, $t2, L_80063184
    if (ctx->r20 != ctx->r10) {
        // 0x80063140: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80063184;
    }
    // 0x80063140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80063144: sb          $t3, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r11;
    // 0x80063148: jal         0x8000A9F8
    // 0x8006314C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_21;
    // 0x8006314C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_21:
    // 0x80063150: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80063154: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80063158: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x8006315C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80063160: jal         0x8000AA88
    // 0x80063164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __vsDelta(rdram, ctx);
        goto after_22;
    // 0x80063164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80063168: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x8006316C: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80063170: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80063174: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80063178: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006317C: jal         0x800C9650
    // 0x80063180: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_23;
    // 0x80063180: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_23:
L_80063184:
    // 0x80063184: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80063188: nop

    // 0x8006318C: bne         $s0, $zero, L_80063134
    if (ctx->r16 != 0) {
        // 0x80063190: nop
    
            goto L_80063134;
    }
    // 0x80063190: nop

    // 0x80063194: b           L_800637D0
    // 0x80063198: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x80063198: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8006319C:
    // 0x8006319C: lbu         $s1, 0xCA($sp)
    ctx->r17 = MEM_BU(ctx->r29, 0XCA);
    // 0x800631A0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800631A4: beq         $s1, $at, L_80063260
    if (ctx->r17 == ctx->r1) {
        // 0x800631A8: sll         $v1, $a3, 2
        ctx->r3 = S32(ctx->r7 << 2);
            goto L_80063260;
    }
    // 0x800631A8: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x800631AC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800631B0: beq         $s1, $at, L_800633D0
    if (ctx->r17 == ctx->r1) {
        // 0x800631B4: sll         $v1, $a3, 2
        ctx->r3 = S32(ctx->r7 << 2);
            goto L_800633D0;
    }
    // 0x800631B4: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x800631B8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800631BC: beq         $s1, $at, L_800631FC
    if (ctx->r17 == ctx->r1) {
        // 0x800631C0: sll         $t5, $a3, 2
        ctx->r13 = S32(ctx->r7 << 2);
            goto L_800631FC;
    }
    // 0x800631C0: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x800631C4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800631C8: beq         $s1, $at, L_80063520
    if (ctx->r17 == ctx->r1) {
        // 0x800631CC: sll         $t3, $a3, 2
        ctx->r11 = S32(ctx->r7 << 2);
            goto L_80063520;
    }
    // 0x800631CC: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x800631D0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800631D4: beq         $s1, $at, L_80063538
    if (ctx->r17 == ctx->r1) {
        // 0x800631D8: sll         $t4, $a3, 2
        ctx->r12 = S32(ctx->r7 << 2);
            goto L_80063538;
    }
    // 0x800631D8: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x800631DC: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x800631E0: beq         $s1, $at, L_800635E0
    if (ctx->r17 == ctx->r1) {
        // 0x800631E4: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_800635E0;
    }
    // 0x800631E4: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800631E8: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x800631EC: beq         $s1, $at, L_80063638
    if (ctx->r17 == ctx->r1) {
        // 0x800631F0: nop
    
            goto L_80063638;
    }
    // 0x800631F0: nop

    // 0x800631F4: b           L_800637D0
    // 0x800631F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x800631F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800631FC:
    // 0x800631FC: lw          $t4, 0x60($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X60);
    // 0x80063200: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x80063204: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80063208: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x8006320C: sb          $s3, 0x7($t9)
    MEM_B(0X7, ctx->r25) = ctx->r19;
    // 0x80063210: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80063214: nop

    // 0x80063218: beq         $s0, $zero, L_800637D0
    if (ctx->r16 == 0) {
        // 0x8006321C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800637D0;
    }
    // 0x8006321C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063220:
    // 0x80063220: lbu         $t1, 0x31($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X31);
    // 0x80063224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80063228: bne         $s4, $t1, L_80063248
    if (ctx->r20 != ctx->r9) {
        // 0x8006322C: nop
    
            goto L_80063248;
    }
    // 0x8006322C: nop

    // 0x80063230: jal         0x8000AAAC
    // 0x80063234: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsPan(rdram, ctx);
        goto after_24;
    // 0x80063234: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x80063238: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8006323C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80063240: jal         0x80065B20
    // 0x80063244: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_25;
    // 0x80063244: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_25:
L_80063248:
    // 0x80063248: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8006324C: nop

    // 0x80063250: bne         $s0, $zero, L_80063220
    if (ctx->r16 != 0) {
        // 0x80063254: nop
    
            goto L_80063220;
    }
    // 0x80063254: nop

    // 0x80063258: b           L_800637D0
    // 0x8006325C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x8006325C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063260:
    // 0x80063260: lw          $t0, 0x60($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X60);
    // 0x80063264: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80063268: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006326C: addu        $t8, $t0, $v1
    ctx->r24 = ADD32(ctx->r8, ctx->r3);
    // 0x80063270: sb          $s3, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r19;
    // 0x80063274: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x80063278: mtc1        $s3, $f6
    ctx->f6.u32l = ctx->r19;
    // 0x8006327C: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x80063280: lbu         $t3, 0x10($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X10);
    // 0x80063284: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80063288: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8006328C: bgez        $t3, L_800632A0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80063290: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800632A0;
    }
    // 0x80063290: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80063294: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80063298: nop

    // 0x8006329C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800632A0:
    // 0x800632A0: bgez        $s3, L_800632B8
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800632A4: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800632B8;
    }
    // 0x800632A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800632A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800632AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800632B0: nop

    // 0x800632B4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800632B8:
    // 0x800632B8: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800632BC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800632C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800632C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800632C8: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800632CC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800632D0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800632D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800632D8: nop

    // 0x800632DC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800632E0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800632E4: nop

    // 0x800632E8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800632EC: beq         $t7, $zero, L_80063338
    if (ctx->r15 == 0) {
        // 0x800632F0: nop
    
            goto L_80063338;
    }
    // 0x800632F0: nop

    // 0x800632F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800632F8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800632FC: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80063300: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80063304: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80063308: nop

    // 0x8006330C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80063310: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80063314: nop

    // 0x80063318: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8006331C: bne         $t7, $zero, L_80063330
    if (ctx->r15 != 0) {
        // 0x80063320: nop
    
            goto L_80063330;
    }
    // 0x80063320: nop

    // 0x80063324: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80063328: b           L_80063348
    // 0x8006332C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80063348;
    // 0x8006332C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80063330:
    // 0x80063330: b           L_80063348
    // 0x80063334: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80063348;
    // 0x80063334: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80063338:
    // 0x80063338: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8006333C: nop

    // 0x80063340: bltz        $t7, L_80063330
    if (SIGNED(ctx->r15) < 0) {
        // 0x80063344: nop
    
            goto L_80063330;
    }
    // 0x80063344: nop

L_80063348:
    // 0x80063348: sb          $t7, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r15;
    // 0x8006334C: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80063350: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80063354: beq         $s0, $zero, L_800637D0
    if (ctx->r16 == 0) {
        // 0x80063358: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800637D0;
    }
    // 0x80063358: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8006335C:
    // 0x8006335C: lbu         $t4, 0x31($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X31);
    // 0x80063360: nop

    // 0x80063364: bne         $s4, $t4, L_800633B8
    if (ctx->r20 != ctx->r12) {
        // 0x80063368: nop
    
            goto L_800633B8;
    }
    // 0x80063368: nop

    // 0x8006336C: lbu         $t5, 0x34($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X34);
    // 0x80063370: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80063374: beq         $t5, $at, L_800633B8
    if (ctx->r13 == ctx->r1) {
        // 0x80063378: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800633B8;
    }
    // 0x80063378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006337C: jal         0x8000A9F8
    // 0x80063380: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_26;
    // 0x80063380: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_26:
    // 0x80063384: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80063388: sra         $t9, $s1, 16
    ctx->r25 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8006338C: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x80063390: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80063394: jal         0x8000AA88
    // 0x80063398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __vsDelta(rdram, ctx);
        goto after_27;
    // 0x80063398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8006339C: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800633A0: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800633A4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800633A8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800633AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800633B0: jal         0x800C9650
    // 0x800633B4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_28;
    // 0x800633B4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_28:
L_800633B8:
    // 0x800633B8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800633BC: nop

    // 0x800633C0: bne         $s0, $zero, L_8006335C
    if (ctx->r16 != 0) {
        // 0x800633C4: nop
    
            goto L_8006335C;
    }
    // 0x800633C4: nop

    // 0x800633C8: b           L_800637D0
    // 0x800633CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x800633CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800633D0:
    // 0x800633D0: lw          $t0, 0x60($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X60);
    // 0x800633D4: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800633D8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800633DC: addu        $t8, $t0, $v1
    ctx->r24 = ADD32(ctx->r8, ctx->r3);
    // 0x800633E0: sb          $s3, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r19;
    // 0x800633E4: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x800633E8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800633EC: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x800633F0: lbu         $t3, 0x10($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X10);
    // 0x800633F4: lbu         $t6, 0x11($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X11);
    // 0x800633F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800633FC: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063400: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80063404: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80063408: mflo        $t7
    ctx->r15 = lo;
    // 0x8006340C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80063410: nop

    // 0x80063414: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80063418: nop

    // 0x8006341C: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80063420: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80063424: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80063428: nop

    // 0x8006342C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80063430: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80063434: nop

    // 0x80063438: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8006343C: beq         $t5, $zero, L_80063488
    if (ctx->r13 == 0) {
        // 0x80063440: nop
    
            goto L_80063488;
    }
    // 0x80063440: nop

    // 0x80063444: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80063448: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8006344C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80063450: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80063454: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80063458: nop

    // 0x8006345C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80063460: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80063464: nop

    // 0x80063468: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8006346C: bne         $t5, $zero, L_80063480
    if (ctx->r13 != 0) {
        // 0x80063470: nop
    
            goto L_80063480;
    }
    // 0x80063470: nop

    // 0x80063474: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80063478: b           L_80063498
    // 0x8006347C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80063498;
    // 0x8006347C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80063480:
    // 0x80063480: b           L_80063498
    // 0x80063484: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80063498;
    // 0x80063484: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80063488:
    // 0x80063488: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8006348C: nop

    // 0x80063490: bltz        $t5, L_80063480
    if (SIGNED(ctx->r13) < 0) {
        // 0x80063494: nop
    
            goto L_80063480;
    }
    // 0x80063494: nop

L_80063498:
    // 0x80063498: sb          $t5, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r13;
    // 0x8006349C: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800634A0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800634A4: beq         $s0, $zero, L_800637D0
    if (ctx->r16 == 0) {
        // 0x800634A8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800637D0;
    }
    // 0x800634A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800634AC:
    // 0x800634AC: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    // 0x800634B0: nop

    // 0x800634B4: bne         $s4, $t9, L_80063508
    if (ctx->r20 != ctx->r25) {
        // 0x800634B8: nop
    
            goto L_80063508;
    }
    // 0x800634B8: nop

    // 0x800634BC: lbu         $t1, 0x34($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X34);
    // 0x800634C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800634C4: beq         $t1, $at, L_80063508
    if (ctx->r9 == ctx->r1) {
        // 0x800634C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80063508;
    }
    // 0x800634C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800634CC: jal         0x8000A9F8
    // 0x800634D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_29;
    // 0x800634D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_29:
    // 0x800634D4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800634D8: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800634DC: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x800634E0: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x800634E4: jal         0x8000AA88
    // 0x800634E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __vsDelta(rdram, ctx);
        goto after_30;
    // 0x800634E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x800634EC: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800634F0: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800634F4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800634F8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800634FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80063500: jal         0x800C9650
    // 0x80063504: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_31;
    // 0x80063504: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_31:
L_80063508:
    // 0x80063508: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8006350C: nop

    // 0x80063510: bne         $s0, $zero, L_800634AC
    if (ctx->r16 != 0) {
        // 0x80063514: nop
    
            goto L_800634AC;
    }
    // 0x80063514: nop

    // 0x80063518: b           L_800637D0
    // 0x8006351C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x8006351C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063520:
    // 0x80063520: lw          $t2, 0x60($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X60);
    // 0x80063524: addu        $t3, $t3, $a3
    ctx->r11 = ADD32(ctx->r11, ctx->r7);
    // 0x80063528: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8006352C: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x80063530: b           L_800637CC
    // 0x80063534: sb          $s3, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r19;
        goto L_800637CC;
    // 0x80063534: sb          $s3, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r19;
L_80063538:
    // 0x80063538: lw          $t7, 0x60($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X60);
    // 0x8006353C: addu        $t4, $t4, $a3
    ctx->r12 = ADD32(ctx->r12, ctx->r7);
    // 0x80063540: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80063544: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x80063548: sb          $s3, 0xB($t5)
    MEM_B(0XB, ctx->r13) = ctx->r19;
    // 0x8006354C: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x80063550: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80063554: beq         $s0, $zero, L_800637D0
    if (ctx->r16 == 0) {
        // 0x80063558: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800637D0;
    }
    // 0x80063558: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8006355C:
    // 0x8006355C: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    // 0x80063560: nop

    // 0x80063564: bne         $s4, $t9, L_800635C8
    if (ctx->r20 != ctx->r25) {
        // 0x80063568: nop
    
            goto L_800635C8;
    }
    // 0x80063568: nop

    // 0x8006356C: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x80063570: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80063574: beq         $v0, $at, L_800635C8
    if (ctx->r2 == ctx->r1) {
        // 0x80063578: slti        $at, $s3, 0x40
        ctx->r1 = SIGNED(ctx->r19) < 0X40 ? 1 : 0;
            goto L_800635C8;
    }
    // 0x80063578: slti        $at, $s3, 0x40
    ctx->r1 = SIGNED(ctx->r19) < 0X40 ? 1 : 0;
    // 0x8006357C: bne         $at, $zero, L_80063594
    if (ctx->r1 != 0) {
        // 0x80063580: nop
    
            goto L_80063594;
    }
    // 0x80063580: nop

    // 0x80063584: bne         $v0, $zero, L_800635C8
    if (ctx->r2 != 0) {
        // 0x80063588: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_800635C8;
    }
    // 0x80063588: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8006358C: b           L_800635C8
    // 0x80063590: sb          $t1, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r9;
        goto L_800635C8;
    // 0x80063590: sb          $t1, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r9;
L_80063594:
    // 0x80063594: bne         $s1, $v0, L_800635A4
    if (ctx->r17 != ctx->r2) {
        // 0x80063598: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800635A4;
    }
    // 0x80063598: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006359C: b           L_800635C8
    // 0x800635A0: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_800635C8;
    // 0x800635A0: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800635A4:
    // 0x800635A4: bne         $v0, $at, L_800635C8
    if (ctx->r2 != ctx->r1) {
        // 0x800635A8: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_800635C8;
    }
    // 0x800635A8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800635AC: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x800635B0: sb          $t0, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r8;
    // 0x800635B4: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x800635B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800635BC: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x800635C0: jal         0x8000AB00
    // 0x800635C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    __seqpReleaseVoice(rdram, ctx);
        goto after_32;
    // 0x800635C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_32:
L_800635C8:
    // 0x800635C8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800635CC: nop

    // 0x800635D0: bne         $s0, $zero, L_8006355C
    if (ctx->r16 != 0) {
        // 0x800635D4: nop
    
            goto L_8006355C;
    }
    // 0x800635D4: nop

    // 0x800635D8: b           L_800637D0
    // 0x800635DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x800635DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800635E0:
    // 0x800635E0: lw          $t3, 0x60($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X60);
    // 0x800635E4: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x800635E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800635EC: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800635F0: sb          $s3, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r19;
    // 0x800635F4: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x800635F8: nop

    // 0x800635FC: beq         $s0, $zero, L_800637D0
    if (ctx->r16 == 0) {
        // 0x80063600: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800637D0;
    }
    // 0x80063600: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063604:
    // 0x80063604: lbu         $t4, 0x31($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X31);
    // 0x80063608: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006360C: bne         $s4, $t4, L_80063620
    if (ctx->r20 != ctx->r12) {
        // 0x80063610: nop
    
            goto L_80063620;
    }
    // 0x80063610: nop

    // 0x80063614: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x80063618: jal         0x800C9810
    // 0x8006361C: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_33;
    // 0x8006361C: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    after_33:
L_80063620:
    // 0x80063620: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80063624: nop

    // 0x80063628: bne         $s0, $zero, L_80063604
    if (ctx->r16 != 0) {
        // 0x8006362C: nop
    
            goto L_80063604;
    }
    // 0x8006362C: nop

    // 0x80063630: b           L_800637D0
    // 0x80063634: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x80063634: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063638:
    // 0x80063638: lbu         $t5, 0x34($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X34);
    // 0x8006363C: sb          $s3, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r19;
    // 0x80063640: blez        $t5, L_800637CC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80063644: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800637CC;
    }
    // 0x80063644: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80063648: or          $s4, $s3, $zero
    ctx->r20 = ctx->r19 | 0;
    // 0x8006364C: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_80063650:
    // 0x80063650: lw          $t9, 0x60($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X60);
    // 0x80063654: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80063658: nop

    // 0x8006365C: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80063660: lbu         $t0, 0xA($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XA);
    // 0x80063664: nop

    // 0x80063668: slt         $at, $t0, $s4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8006366C: beq         $at, $zero, L_800636B8
    if (ctx->r1 == 0) {
        // 0x80063670: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_800636B8;
    }
    // 0x80063670: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80063674: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    // 0x80063678: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x8006367C: nop

    // 0x80063680: beq         $s0, $zero, L_800636B8
    if (ctx->r16 == 0) {
        // 0x80063684: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_800636B8;
    }
    // 0x80063684: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
L_80063688:
    // 0x80063688: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    // 0x8006368C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80063690: bne         $s1, $t8, L_800636A4
    if (ctx->r17 != ctx->r24) {
        // 0x80063694: nop
    
            goto L_800636A4;
    }
    // 0x80063694: nop

    // 0x80063698: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8006369C: jal         0x800C9810
    // 0x800636A0: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_34;
    // 0x800636A0: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    after_34:
L_800636A4:
    // 0x800636A4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800636A8: nop

    // 0x800636AC: bne         $s0, $zero, L_80063688
    if (ctx->r16 != 0) {
        // 0x800636B0: nop
    
            goto L_80063688;
    }
    // 0x800636B0: nop

    // 0x800636B4: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
L_800636B8:
    // 0x800636B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800636BC: addiu       $t3, $t2, 0x14
    ctx->r11 = ADD32(ctx->r10, 0X14);
    // 0x800636C0: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x800636C4: lbu         $t6, 0x34($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X34);
    // 0x800636C8: nop

    // 0x800636CC: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800636D0: bne         $at, $zero, L_80063650
    if (ctx->r1 != 0) {
        // 0x800636D4: nop
    
            goto L_80063650;
    }
    // 0x800636D4: nop

    // 0x800636D8: b           L_800637D0
    // 0x800636DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x800636DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800636E0:
    // 0x800636E0: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x800636E4: lbu         $t7, 0xCA($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XCA);
    // 0x800636E8: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800636EC: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800636F0: slt         $at, $t7, $t4
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800636F4: beq         $at, $zero, L_800637CC
    if (ctx->r1 == 0) {
        // 0x800636F8: addu        $t9, $v0, $t5
        ctx->r25 = ADD32(ctx->r2, ctx->r13);
            goto L_800637CC;
    }
    // 0x800636F8: addu        $t9, $v0, $t5
    ctx->r25 = ADD32(ctx->r2, ctx->r13);
    // 0x800636FC: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    // 0x80063700: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80063704: jal         0x8000AD98
    // 0x80063708: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    __setInstChanState(rdram, ctx);
        goto after_35;
    // 0x80063708: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_35:
    // 0x8006370C: b           L_800637D0
    // 0x80063710: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800637D0;
    // 0x80063710: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063714:
    // 0x80063714: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x80063718: lw          $t3, 0x60($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X60);
    // 0x8006371C: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80063720: lbu         $t0, 0xCA($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XCA);
    // 0x80063724: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80063728: sll         $t1, $s3, 7
    ctx->r9 = S32(ctx->r19 << 7);
    // 0x8006372C: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x80063730: lh          $t4, 0x4($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X4);
    // 0x80063734: addu        $t8, $t1, $t0
    ctx->r24 = ADD32(ctx->r9, ctx->r8);
    // 0x80063738: addiu       $t2, $t8, -0x2000
    ctx->r10 = ADD32(ctx->r24, -0X2000);
    // 0x8006373C: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063740: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x80063744: mflo        $a0
    ctx->r4 = lo;
    // 0x80063748: bgez        $a0, L_80063758
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006374C: sra         $t7, $a0, 13
        ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
            goto L_80063758;
    }
    // 0x8006374C: sra         $t7, $a0, 13
    ctx->r15 = S32(SIGNED(ctx->r4) >> 13);
    // 0x80063750: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x80063754: sra         $t7, $at, 13
    ctx->r15 = S32(SIGNED(ctx->r1) >> 13);
L_80063758:
    // 0x80063758: jal         0x800C99E0
    // 0x8006375C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    alCents2Ratio(rdram, ctx);
        goto after_36;
    // 0x8006375C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_36:
    // 0x80063760: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80063764: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80063768: lw          $t5, 0x60($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X60);
    // 0x8006376C: nop

    // 0x80063770: addu        $t9, $t5, $v1
    ctx->r25 = ADD32(ctx->r13, ctx->r3);
    // 0x80063774: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x80063778: lw          $s0, 0x64($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X64);
    // 0x8006377C: nop

    // 0x80063780: beq         $s0, $zero, L_800637D0
    if (ctx->r16 == 0) {
        // 0x80063784: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800637D0;
    }
    // 0x80063784: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80063788:
    // 0x80063788: lbu         $t1, 0x31($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X31);
    // 0x8006378C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80063790: bne         $s4, $t1, L_800637BC
    if (ctx->r20 != ctx->r9) {
        // 0x80063794: nop
    
            goto L_800637BC;
    }
    // 0x80063794: nop

    // 0x80063798: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8006379C: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800637A0: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800637A4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800637A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800637AC: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800637B0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800637B4: jal         0x800C9780
    // 0x800637B8: nop

    alSynSetPitch(rdram, ctx);
        goto after_37;
    // 0x800637B8: nop

    after_37:
L_800637BC:
    // 0x800637BC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800637C0: nop

    // 0x800637C4: bne         $s0, $zero, L_80063788
    if (ctx->r16 != 0) {
        // 0x800637C8: nop
    
            goto L_80063788;
    }
    // 0x800637C8: nop

L_800637CC:
    // 0x800637CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800637D0:
    // 0x800637D0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800637D4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800637D8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800637DC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800637E0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800637E4: jr          $ra
    // 0x800637E8: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800637E8: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void static_3_800637EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800637EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800637F0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800637F4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800637F8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800637FC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80063800: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80063804: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80063808: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006380C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80063810: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80063814: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80063818: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8006381C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80063820: bne         $t6, $at, L_8006395C
    if (ctx->r14 != ctx->r1) {
        // 0x80063824: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8006395C;
    }
    // 0x80063824: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80063828: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x8006382C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80063830: bne         $t7, $at, L_8006395C
    if (ctx->r15 != ctx->r1) {
        // 0x80063834: addiu       $v0, $a1, 0x4
        ctx->r2 = ADD32(ctx->r5, 0X4);
            goto L_8006395C;
    }
    // 0x80063834: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x80063838: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x8006383C: lbu         $t0, 0x8($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X8);
    // 0x80063840: lbu         $t3, 0x9($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X9);
    // 0x80063844: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80063848: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8006384C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80063850: or          $v1, $t2, $t3
    ctx->r3 = ctx->r10 | ctx->r11;
    // 0x80063854: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80063858: lw          $s6, 0x24($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X24);
    // 0x8006385C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063860: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80063864: jal         0x80063A34
    // 0x80063868: nop

    static_3_80063A34(rdram, ctx);
        goto after_0;
    // 0x80063868: nop

    after_0:
    // 0x8006386C: lw          $s0, 0x50($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X50);
    // 0x80063870: nop

    // 0x80063874: beq         $s0, $zero, L_800638EC
    if (ctx->r16 == 0) {
        // 0x80063878: nop
    
            goto L_800638EC;
    }
    // 0x80063878: nop

    // 0x8006387C: addiu       $s4, $zero, 0x15
    ctx->r20 = ADD32(0, 0X15);
L_80063880:
    // 0x80063880: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80063884: lh          $t5, 0xC($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XC);
    // 0x80063888: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8006388C: bne         $s4, $t5, L_800638E4
    if (ctx->r20 != ctx->r13) {
        // 0x80063890: addu        $s2, $s2, $t4
        ctx->r18 = ADD32(ctx->r18, ctx->r12);
            goto L_800638E4;
    }
    // 0x80063890: addu        $s2, $s2, $t4
    ctx->r18 = ADD32(ctx->r18, ctx->r12);
    // 0x80063894: jal         0x800C8760
    // 0x80063898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x80063898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006389C: beq         $s3, $zero, L_800638B8
    if (ctx->r19 == 0) {
        // 0x800638A0: nop
    
            goto L_800638B8;
    }
    // 0x800638A0: nop

    // 0x800638A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800638A8: jal         0x800C8790
    // 0x800638AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800638AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x800638B0: b           L_800638C4
    // 0x800638B4: nop

        goto L_800638C4;
    // 0x800638B4: nop

L_800638B8:
    // 0x800638B8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800638BC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800638C0: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
L_800638C4:
    // 0x800638C4: beq         $s1, $zero, L_800638E0
    if (ctx->r17 == 0) {
        // 0x800638C8: or          $v1, $s2, $zero
        ctx->r3 = ctx->r18 | 0;
            goto L_800638E0;
    }
    // 0x800638C8: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800638CC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800638D0: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x800638D4: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800638D8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800638DC: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
L_800638E0:
    // 0x800638E0: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
L_800638E4:
    // 0x800638E4: bne         $s1, $zero, L_80063880
    if (ctx->r17 != 0) {
        // 0x800638E8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80063880;
    }
    // 0x800638E8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800638EC:
    // 0x800638EC: beq         $s3, $zero, L_8006395C
    if (ctx->r19 == 0) {
        // 0x800638F0: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_8006395C;
    }
    // 0x800638F0: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800638F4: addiu       $s2, $s5, 0x48
    ctx->r18 = ADD32(ctx->r21, 0X48);
L_800638F8:
    // 0x800638F8: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800638FC: lw          $t0, 0x24($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X24);
    // 0x80063900: div         $zero, $t8, $s6
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r22)));
    // 0x80063904: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80063908: bne         $s6, $zero, L_80063914
    if (ctx->r22 != 0) {
        // 0x8006390C: nop
    
            goto L_80063914;
    }
    // 0x8006390C: nop

    // 0x80063910: break       7
    do_break(2147891472);
L_80063914:
    // 0x80063914: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80063918: bne         $s6, $at, L_8006392C
    if (ctx->r22 != ctx->r1) {
        // 0x8006391C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006392C;
    }
    // 0x8006391C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80063920: bne         $t8, $at, L_8006392C
    if (ctx->r24 != ctx->r1) {
        // 0x80063924: nop
    
            goto L_8006392C;
    }
    // 0x80063924: nop

    // 0x80063928: break       6
    do_break(2147891496);
L_8006392C:
    // 0x8006392C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80063930: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80063934: mflo        $v0
    ctx->r2 = lo;
    // 0x80063938: nop

    // 0x8006393C: nop

    // 0x80063940: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063944: mflo        $t9
    ctx->r25 = lo;
    // 0x80063948: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x8006394C: jal         0x80063984
    // 0x80063950: nop

    static_3_80063984(rdram, ctx);
        goto after_3;
    // 0x80063950: nop

    after_3:
    // 0x80063954: bne         $s1, $zero, L_800638F8
    if (ctx->r17 != 0) {
        // 0x80063958: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800638F8;
    }
    // 0x80063958: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8006395C:
    // 0x8006395C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80063960: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80063964: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80063968: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006396C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80063970: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80063974: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80063978: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006397C: jr          $ra
    // 0x80063980: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80063980: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80063984: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80063988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006398C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80063990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80063994: jal         0x800C9A30
    // 0x80063998: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x80063998: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x8006399C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800639A0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800639A4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800639A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800639AC: beq         $v1, $at, L_80063A18
    if (ctx->r3 == ctx->r1) {
        // 0x800639B0: addiu       $a1, $v1, 0x8
        ctx->r5 = ADD32(ctx->r3, 0X8);
            goto L_80063A18;
    }
    // 0x800639B0: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
L_800639B4:
    // 0x800639B4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800639B8: nop

    // 0x800639BC: bne         $a0, $zero, L_800639D4
    if (ctx->r4 != 0) {
        // 0x800639C0: nop
    
            goto L_800639D4;
    }
    // 0x800639C0: nop

    // 0x800639C4: jal         0x800C8790
    // 0x800639C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alLink(rdram, ctx);
        goto after_5;
    // 0x800639C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
    // 0x800639CC: b           L_80063A1C
    // 0x800639D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_80063A1C;
    // 0x800639D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800639D4:
    // 0x800639D4: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x800639D8: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800639DC: nop

    // 0x800639E0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800639E4: beq         $at, $zero, L_80063A04
    if (ctx->r1 == 0) {
        // 0x800639E8: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_80063A04;
    }
    // 0x800639E8: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x800639EC: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x800639F0: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800639F4: jal         0x800C8790
    // 0x800639F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alLink(rdram, ctx);
        goto after_6;
    // 0x800639F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x800639FC: b           L_80063A1C
    // 0x80063A00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_80063A1C;
    // 0x80063A00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80063A04:
    // 0x80063A04: sw          $t7, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r15;
    // 0x80063A08: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x80063A0C: nop

    // 0x80063A10: bne         $a1, $zero, L_800639B4
    if (ctx->r5 != 0) {
        // 0x80063A14: nop
    
            goto L_800639B4;
    }
    // 0x80063A14: nop

L_80063A18:
    // 0x80063A18: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80063A1C:
    // 0x80063A1C: jal         0x800C9A30
    // 0x80063A20: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_7;
    // 0x80063A20: nop

    after_7:
    // 0x80063A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063A28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80063A2C: jr          $ra
    // 0x80063A30: nop

    return;
    // 0x80063A30: nop

    // 0x80063A34: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80063A38: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80063A3C: beq         $v0, $zero, L_80063A7C
    if (ctx->r2 == 0) {
        // 0x80063A40: addiu       $t8, $zero, 0x1E8
        ctx->r24 = ADD32(0, 0X1E8);
            goto L_80063A7C;
    }
    // 0x80063A40: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x80063A44: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80063A48: nop

    // 0x80063A4C: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80063A50: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80063A54: nop

    // 0x80063A58: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80063A5C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80063A60: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80063A64: nop

    // 0x80063A68: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80063A6C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80063A70: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80063A74: jr          $ra
    // 0x80063A78: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    return;
    // 0x80063A78: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_80063A7C:
    // 0x80063A7C: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x80063A80: jr          $ra
    // 0x80063A84: nop

    return;
    // 0x80063A84: nop

    // 0x80063A88: nop

    // 0x80063A8C: nop

;}
RECOMP_FUNC void static_3_80065754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065754: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x80065758: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8006575C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80065760: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80065764: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80065768: lwc1        $f5, 0x6EC0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6EC0);
    // 0x8006576C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80065770: lwc1        $f4, 0x6EC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6EC4);
    // 0x80065774: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80065778: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8006577C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80065780: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80065784: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80065788: nop

    // 0x8006578C: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x80065790: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80065794: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80065798: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006579C: nop

    // 0x800657A0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800657A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800657A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800657AC: nop

    // 0x800657B0: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800657B4: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800657B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800657BC: jr          $ra
    // 0x800657C0: nop

    return;
    // 0x800657C0: nop

;}
RECOMP_FUNC void static_3_800657EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800657EC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800657F0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800657F4: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x800657F8: beq         $v1, $zero, L_80065844
    if (ctx->r3 == 0) {
        // 0x800657FC: ori         $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 | 0XFFFF;
            goto L_80065844;
    }
    // 0x800657FC: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80065800: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x80065804: nop

L_80065808:
    // 0x80065808: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x8006580C: nop

    // 0x80065810: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x80065814: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80065818: beq         $at, $zero, L_80065834
    if (ctx->r1 == 0) {
        // 0x8006581C: nop
    
            goto L_80065834;
    }
    // 0x8006581C: nop

    // 0x80065820: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80065824: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x80065828: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x8006582C: nop

    // 0x80065830: subu        $v0, $t8, $a2
    ctx->r2 = SUB32(ctx->r24, ctx->r6);
L_80065834:
    // 0x80065834: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80065838: nop

    // 0x8006583C: bne         $v1, $zero, L_80065808
    if (ctx->r3 != 0) {
        // 0x80065840: nop
    
            goto L_80065808;
    }
    // 0x80065840: nop

L_80065844:
    // 0x80065844: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80065848: nop

    // 0x8006584C: lw          $v0, 0x10($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X10);
    // 0x80065850: jr          $ra
    // 0x80065854: nop

    return;
    // 0x80065854: nop

    // 0x80065858: nop

    // 0x8006585C: nop

;}
RECOMP_FUNC void static_3_80070890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void static_3_80079818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079818: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007981C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80079820: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80079824: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80079828: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8007982C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80079830: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80079834: sb          $zero, 0x32($sp)
    MEM_B(0X32, ctx->r29) = 0;
    // 0x80079838: lw          $t6, 0x274($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X274);
    // 0x8007983C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80079840: beq         $t6, $zero, L_80079860
    if (ctx->r14 == 0) {
        // 0x80079844: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80079860;
    }
    // 0x80079844: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80079848: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007984C: addiu       $v1, $v1, -0x18AC
    ctx->r3 = ADD32(ctx->r3, -0X18AC);
    // 0x80079850: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80079854: nop

    // 0x80079858: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8007985C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80079860:
    // 0x80079860: lw          $t9, 0x278($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X278);
    // 0x80079864: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80079868: beq         $t9, $zero, L_80079884
    if (ctx->r25 == 0) {
        // 0x8007986C: addiu       $v1, $v1, -0x18AC
        ctx->r3 = ADD32(ctx->r3, -0X18AC);
            goto L_80079884;
    }
    // 0x8007986C: addiu       $v1, $v1, -0x18AC
    ctx->r3 = ADD32(ctx->r3, -0X18AC);
    // 0x80079870: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80079874: lw          $t0, -0x18A8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X18A8);
    // 0x80079878: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007987C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80079880: sw          $t1, -0x18A8($at)
    MEM_W(-0X18A8, ctx->r1) = ctx->r9;
L_80079884:
    // 0x80079884: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80079888: lw          $v0, 0x274($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X274);
    // 0x8007988C: slti        $at, $t2, 0xB
    ctx->r1 = SIGNED(ctx->r10) < 0XB ? 1 : 0;
    // 0x80079890: bne         $at, $zero, L_800798B8
    if (ctx->r1 != 0) {
        // 0x80079894: nop
    
            goto L_800798B8;
    }
    // 0x80079894: nop

    // 0x80079898: beq         $v0, $zero, L_800798B8
    if (ctx->r2 == 0) {
        // 0x8007989C: lui         $a0, 0xAA
        ctx->r4 = S32(0XAA << 16);
            goto L_800798B8;
    }
    // 0x8007989C: lui         $a0, 0xAA
    ctx->r4 = S32(0XAA << 16);
    // 0x800798A0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800798A4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800798A8: jal         0x800CD240
    // 0x800798AC: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    __osSpSetStatus_recomp(rdram, ctx);
        goto after_0;
    // 0x800798AC: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    after_0:
    // 0x800798B0: b           L_800798C8
    // 0x800798B4: nop

        goto L_800798C8;
    // 0x800798B4: nop

L_800798B8:
    // 0x800798B8: beq         $v0, $zero, L_800798C8
    if (ctx->r2 == 0) {
        // 0x800798BC: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800798C8;
    }
    // 0x800798BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800798C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800798C4: sw          $t3, 0x6110($at)
    MEM_W(0X6110, ctx->r1) = ctx->r11;
L_800798C8:
    // 0x800798C8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800798CC: lw          $t4, -0x18A8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X18A8);
    // 0x800798D0: lw          $v0, 0x278($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X278);
    // 0x800798D4: slti        $at, $t4, 0xB
    ctx->r1 = SIGNED(ctx->r12) < 0XB ? 1 : 0;
    // 0x800798D8: bne         $at, $zero, L_80079934
    if (ctx->r1 != 0) {
        // 0x800798DC: nop
    
            goto L_80079934;
    }
    // 0x800798DC: nop

    // 0x800798E0: beq         $v0, $zero, L_80079934
    if (ctx->r2 == 0) {
        // 0x800798E4: nop
    
            goto L_80079934;
    }
    // 0x800798E4: nop

    // 0x800798E8: lw          $t5, 0x68($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X68);
    // 0x800798EC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800798F0: bne         $t5, $zero, L_80079904
    if (ctx->r13 != 0) {
        // 0x800798F4: addiu       $a1, $a1, -0x18C8
        ctx->r5 = ADD32(ctx->r5, -0X18C8);
            goto L_80079904;
    }
    // 0x800798F4: addiu       $a1, $a1, -0x18C8
    ctx->r5 = ADD32(ctx->r5, -0X18C8);
    // 0x800798F8: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x800798FC: jal         0x800C8E30
    // 0x80079900: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80079900: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80079904:
    // 0x80079904: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80079908: sb          $t6, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r14;
    // 0x8007990C: sw          $zero, 0x280($s1)
    MEM_W(0X280, ctx->r17) = 0;
    // 0x80079910: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079914: lui         $a0, 0xAA
    ctx->r4 = S32(0XAA << 16);
    // 0x80079918: sw          $zero, -0x18A8($at)
    MEM_W(-0X18A8, ctx->r1) = 0;
    // 0x8007991C: jal         0x800CD240
    // 0x80079920: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    __osSpSetStatus_recomp(rdram, ctx);
        goto after_2;
    // 0x80079920: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    after_2:
    // 0x80079924: jal         0x800CD250
    // 0x80079928: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_3;
    // 0x80079928: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    after_3:
    // 0x8007992C: b           L_80079944
    // 0x80079930: nop

        goto L_80079944;
    // 0x80079930: nop

L_80079934:
    // 0x80079934: beq         $v0, $zero, L_80079944
    if (ctx->r2 == 0) {
        // 0x80079938: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80079944;
    }
    // 0x80079938: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007993C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80079940: sw          $t7, 0x6114($at)
    MEM_W(0X6114, ctx->r1) = ctx->r15;
L_80079944:
    // 0x80079944: beq         $s0, $zero, L_80079950
    if (ctx->r16 == 0) {
        // 0x80079948: addiu       $a0, $s1, 0x78
        ctx->r4 = ADD32(ctx->r17, 0X78);
            goto L_80079950;
    }
    // 0x80079948: addiu       $a0, $s1, 0x78
    ctx->r4 = ADD32(ctx->r17, 0X78);
    // 0x8007994C: sw          $zero, 0x274($s1)
    MEM_W(0X274, ctx->r17) = 0;
L_80079950:
    // 0x80079950: lbu         $t8, 0x32($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X32);
    // 0x80079954: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80079958: beq         $t8, $zero, L_80079964
    if (ctx->r24 == 0) {
        // 0x8007995C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80079964;
    }
    // 0x8007995C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80079960: sw          $zero, 0x278($s1)
    MEM_W(0X278, ctx->r17) = 0;
L_80079964:
    // 0x80079964: jal         0x800C8BB0
    // 0x80079968: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80079968: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_4:
    // 0x8007996C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80079970: beq         $v0, $s0, L_8007999C
    if (ctx->r2 == ctx->r16) {
        // 0x80079974: nop
    
            goto L_8007999C;
    }
    // 0x80079974: nop

    // 0x80079978: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
L_8007997C:
    // 0x8007997C: jal         0x80079F40
    // 0x80079980: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    static_3_80079F40(rdram, ctx);
        goto after_5;
    // 0x80079980: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80079984: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80079988: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8007998C: jal         0x800C8BB0
    // 0x80079990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80079990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80079994: bne         $v0, $s0, L_8007997C
    if (ctx->r2 != ctx->r16) {
        // 0x80079998: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_8007997C;
    }
    // 0x80079998: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
L_8007999C:
    // 0x8007999C: lw          $t9, 0x274($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X274);
    // 0x800799A0: lw          $t2, 0x278($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X278);
    // 0x800799A4: sltiu       $t0, $t9, 0x1
    ctx->r8 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800799A8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800799AC: sltiu       $t3, $t2, 0x1
    ctx->r11 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x800799B0: or          $s0, $t1, $t3
    ctx->r16 = ctx->r9 | ctx->r11;
    // 0x800799B4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800799B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800799BC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800799C0: jal         0x8007A0D4
    // 0x800799C4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    static_3_8007A0D4(rdram, ctx);
        goto after_7;
    // 0x800799C4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x800799C8: beq         $v0, $s0, L_800799E0
    if (ctx->r2 == ctx->r16) {
        // 0x800799CC: nop
    
            goto L_800799E0;
    }
    // 0x800799CC: nop

    // 0x800799D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800799D4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800799D8: jal         0x80079FA8
    // 0x800799DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    static_3_80079FA8(rdram, ctx);
        goto after_8;
    // 0x800799DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_800799E0:
    // 0x800799E0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800799E4: lw          $t5, -0x189C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X189C);
    // 0x800799E8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800799EC: lw          $t4, -0x18A0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X18A0);
    // 0x800799F0: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x800799F4: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800799F8: addu        $t6, $t4, $at
    ctx->r14 = ADD32(ctx->r12, ctx->r1);
    // 0x800799FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079A00: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80079A04: addiu       $v0, $v0, -0x18B0
    ctx->r2 = ADD32(ctx->r2, -0X18B0);
    // 0x80079A08: sw          $t6, -0x18A0($at)
    MEM_W(-0X18A0, ctx->r1) = ctx->r14;
    // 0x80079A0C: sw          $t7, -0x189C($at)
    MEM_W(-0X189C, ctx->r1) = ctx->r15;
    // 0x80079A10: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80079A14: nop

    // 0x80079A18: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80079A1C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80079A20: lw          $t0, 0x280($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X280);
    // 0x80079A24: lw          $v1, 0x27C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X27C);
    // 0x80079A28: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x80079A2C: beq         $v1, $zero, L_80079A94
    if (ctx->r3 == 0) {
        // 0x80079A30: sw          $t2, 0x280($s1)
        MEM_W(0X280, ctx->r17) = ctx->r10;
            goto L_80079A94;
    }
    // 0x80079A30: sw          $t2, 0x280($s1)
    MEM_W(0X280, ctx->r17) = ctx->r10;
    // 0x80079A34: sltiu       $at, $t2, 0x2
    ctx->r1 = ctx->r10 < 0X2 ? 1 : 0;
    // 0x80079A38: bne         $at, $zero, L_80079A94
    if (ctx->r1 != 0) {
        // 0x80079A3C: nop
    
            goto L_80079A94;
    }
    // 0x80079A3C: nop

    // 0x80079A40: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x80079A44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80079A48: beq         $a0, $zero, L_80079A8C
    if (ctx->r4 == 0) {
        // 0x80079A4C: nop
    
            goto L_80079A8C;
    }
    // 0x80079A4C: nop

    // 0x80079A50: lw          $t3, 0x68($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X68);
    // 0x80079A54: nop

    // 0x80079A58: bne         $t3, $zero, L_80079A70
    if (ctx->r11 != 0) {
        // 0x80079A5C: nop
    
            goto L_80079A70;
    }
    // 0x80079A5C: nop

    // 0x80079A60: lw          $t4, 0x54($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X54);
    // 0x80079A64: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80079A68: beq         $t4, $zero, L_80079A84
    if (ctx->r12 == 0) {
        // 0x80079A6C: addiu       $a1, $a1, -0x18D0
        ctx->r5 = ADD32(ctx->r5, -0X18D0);
            goto L_80079A84;
    }
    // 0x80079A6C: addiu       $a1, $a1, -0x18D0
    ctx->r5 = ADD32(ctx->r5, -0X18D0);
L_80079A70:
    // 0x80079A70: lw          $a1, 0x54($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X54);
    // 0x80079A74: jal         0x800C8E30
    // 0x80079A78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80079A78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80079A7C: b           L_80079A90
    // 0x80079A80: sw          $zero, 0x280($s1)
    MEM_W(0X280, ctx->r17) = 0;
        goto L_80079A90;
    // 0x80079A80: sw          $zero, 0x280($s1)
    MEM_W(0X280, ctx->r17) = 0;
L_80079A84:
    // 0x80079A84: jal         0x800C8E30
    // 0x80079A88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x80079A88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
L_80079A8C:
    // 0x80079A8C: sw          $zero, 0x280($s1)
    MEM_W(0X280, ctx->r17) = 0;
L_80079A90:
    // 0x80079A90: sw          $zero, 0x27C($s1)
    MEM_W(0X27C, ctx->r17) = 0;
L_80079A94:
    // 0x80079A94: lw          $s0, 0x260($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X260);
    // 0x80079A98: nop

    // 0x80079A9C: beq         $s0, $zero, L_80079B34
    if (ctx->r16 == 0) {
        // 0x80079AA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80079B34;
    }
    // 0x80079AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80079AA4:
    // 0x80079AA4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80079AA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80079AAC: bne         $v0, $at, L_80079B08
    if (ctx->r2 != ctx->r1) {
        // 0x80079AB0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80079B08;
    }
    // 0x80079AB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80079AB4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80079AB8: lw          $a1, -0x189C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X189C);
    // 0x80079ABC: lw          $a0, -0x18A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X18A0);
    // 0x80079AC0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80079AC4: jal         0x800CEA8C
    // 0x80079AC8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    __ull_rem_recomp(rdram, ctx);
        goto after_11;
    // 0x80079AC8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_11:
    // 0x80079ACC: bne         $v0, $zero, L_80079B20
    if (ctx->r2 != 0) {
        // 0x80079AD0: nop
    
            goto L_80079B20;
    }
    // 0x80079AD0: nop

    // 0x80079AD4: bne         $v1, $zero, L_80079B20
    if (ctx->r3 != 0) {
        // 0x80079AD8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80079B20;
    }
    // 0x80079AD8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079ADC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80079AE0: jal         0x800C8E30
    // 0x80079AE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x80079AE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80079AE8: lw          $t5, 0x264($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X264);
    // 0x80079AEC: nop

    // 0x80079AF0: beq         $t5, $zero, L_80079B20
    if (ctx->r13 == 0) {
        // 0x80079AF4: nop
    
            goto L_80079B20;
    }
    // 0x80079AF4: nop

    // 0x80079AF8: jal         0x80079760
    // 0x80079AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80079760(rdram, ctx);
        goto after_13;
    // 0x80079AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80079B00: b           L_80079B24
    // 0x80079B04: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
        goto L_80079B24;
    // 0x80079B04: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80079B08:
    // 0x80079B08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079B0C: bne         $v0, $at, L_80079B20
    if (ctx->r2 != ctx->r1) {
        // 0x80079B10: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80079B20;
    }
    // 0x80079B10: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079B14: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80079B18: jal         0x800C8E30
    // 0x80079B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x80079B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
L_80079B20:
    // 0x80079B20: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80079B24:
    // 0x80079B24: nop

    // 0x80079B28: bne         $s0, $zero, L_80079AA4
    if (ctx->r16 != 0) {
        // 0x80079B2C: nop
    
            goto L_80079AA4;
    }
    // 0x80079B2C: nop

    // 0x80079B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80079B34:
    // 0x80079B34: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80079B38: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80079B3C: jr          $ra
    // 0x80079B40: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80079B40: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80079B44: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80079B48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80079B4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80079B50: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80079B54: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80079B58: lw          $a1, 0x274($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X274);
    // 0x80079B5C: sw          $zero, 0x274($a0)
    MEM_W(0X274, ctx->r4) = 0;
    // 0x80079B60: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80079B64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079B68: bne         $t6, $at, L_80079C50
    if (ctx->r14 != ctx->r1) {
        // 0x80079B6C: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80079C50;
    }
    // 0x80079B6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80079B70: jal         0x800C78D0
    // 0x80079B74: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    osGetCount_recomp(rdram, ctx);
        goto after_15;
    // 0x80079B74: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_15:
    // 0x80079B78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80079B7C: addiu       $v1, $v1, 0x6124
    ctx->r3 = ADD32(ctx->r3, 0X6124);
    // 0x80079B80: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80079B84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80079B88: lw          $t8, 0x6120($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6120);
    // 0x80079B8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80079B90: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80079B94: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80079B98: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80079B9C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80079BA0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80079BA4: addiu       $a3, $a3, -0x18C0
    ctx->r7 = ADD32(ctx->r7, -0X18C0);
    // 0x80079BA8: addiu       $a2, $a2, -0x18BC
    ctx->r6 = ADD32(ctx->r6, -0X18BC);
    // 0x80079BAC: addiu       $a0, $a0, -0x18B4
    ctx->r4 = ADD32(ctx->r4, -0X18B4);
    // 0x80079BB0: bgez        $t9, L_80079BC8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80079BB4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80079BC8;
    }
    // 0x80079BB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079BB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80079BBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80079BC0: nop

    // 0x80079BC4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80079BC8:
    // 0x80079BC8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80079BCC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80079BD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079BD4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80079BD8: lwc1        $f18, 0x796C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X796C);
    // 0x80079BDC: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80079BE0: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80079BE4: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80079BE8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80079BEC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80079BF0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80079BF4: nop

    // 0x80079BF8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80079BFC: add.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80079C00: bc1f        L_80079C0C
    if (!c1cs) {
        // 0x80079C04: swc1        $f6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
            goto L_80079C0C;
    }
    // 0x80079C04: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x80079C08: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_80079C0C:
    // 0x80079C0C: lw          $v0, -0x18B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X18B0);
    // 0x80079C10: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80079C14: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80079C18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80079C1C: mfhi        $t0
    ctx->r8 = hi;
    // 0x80079C20: beq         $t0, $at, L_80079C2C
    if (ctx->r8 == ctx->r1) {
        // 0x80079C24: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80079C2C;
    }
    // 0x80079C24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079C28: bne         $t0, $at, L_80079C50
    if (ctx->r8 != ctx->r1) {
        // 0x80079C2C: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_80079C50;
    }
L_80079C2C:
    // 0x80079C2C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80079C30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80079C34: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80079C38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80079C3C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80079C40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80079C44: swc1        $f4, -0x18B8($at)
    MEM_W(-0X18B8, ctx->r1) = ctx->f4.u32l;
    // 0x80079C48: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x80079C4C: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_80079C50:
    // 0x80079C50: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80079C54: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80079C58: andi        $t1, $v0, 0x10
    ctx->r9 = ctx->r2 & 0X10;
    // 0x80079C5C: beq         $t1, $zero, L_80079CF8
    if (ctx->r9 == 0) {
        // 0x80079C60: and         $t2, $v0, $at
        ctx->r10 = ctx->r2 & ctx->r1;
            goto L_80079CF8;
    }
    // 0x80079C60: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x80079C64: addiu       $a0, $a1, 0x10
    ctx->r4 = ADD32(ctx->r5, 0X10);
    // 0x80079C68: jal         0x800D1DF0
    // 0x80079C6C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_16;
    // 0x80079C6C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_16:
    // 0x80079C70: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80079C74: beq         $v0, $zero, L_80079CCC
    if (ctx->r2 == 0) {
        // 0x80079C78: addiu       $at, $zero, -0x3
        ctx->r1 = ADD32(0, -0X3);
            goto L_80079CCC;
    }
    // 0x80079C78: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80079C7C: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x80079C80: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    // 0x80079C84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80079C88: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x80079C8C: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x80079C90: bne         $t5, $at, L_80079CB8
    if (ctx->r13 != ctx->r1) {
        // 0x80079C94: sw          $t3, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r11;
            goto L_80079CB8;
    }
    // 0x80079C94: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x80079C98: lw          $t6, 0x268($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X268);
    // 0x80079C9C: nop

    // 0x80079CA0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80079CA4: lw          $t7, 0x270($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X270);
    // 0x80079CA8: sw          $a1, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r5;
    // 0x80079CAC: bne         $t7, $zero, L_80079CB8
    if (ctx->r15 != 0) {
        // 0x80079CB0: nop
    
            goto L_80079CB8;
    }
    // 0x80079CB0: nop

    // 0x80079CB4: sw          $a1, 0x270($s0)
    MEM_W(0X270, ctx->r16) = ctx->r5;
L_80079CB8:
    // 0x80079CB8: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80079CBC: nop

    // 0x80079CC0: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x80079CC4: b           L_80079CE4
    // 0x80079CC8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80079CE4;
    // 0x80079CC8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80079CCC:
    // 0x80079CCC: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80079CD0: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x80079CD4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80079CD8: andi        $t1, $v0, 0x7
    ctx->r9 = ctx->r2 & 0X7;
    // 0x80079CDC: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80079CE0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80079CE4:
    // 0x80079CE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80079CE8: beq         $v0, $at, L_80079D04
    if (ctx->r2 == ctx->r1) {
        // 0x80079CEC: nop
    
            goto L_80079D04;
    }
    // 0x80079CEC: nop

    // 0x80079CF0: b           L_80079D08
    // 0x80079CF4: lw          $t3, 0x274($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X274);
        goto L_80079D08;
    // 0x80079CF4: lw          $t3, 0x274($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X274);
L_80079CF8:
    // 0x80079CF8: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x80079CFC: jal         0x80079E40
    // 0x80079D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    static_3_80079E40(rdram, ctx);
        goto after_17;
    // 0x80079D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_80079D04:
    // 0x80079D04: lw          $t3, 0x274($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X274);
L_80079D08:
    // 0x80079D08: lw          $t6, 0x278($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X278);
    // 0x80079D0C: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80079D10: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80079D14: sltiu       $t7, $t6, 0x1
    ctx->r15 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80079D18: or          $a3, $t5, $t7
    ctx->r7 = ctx->r13 | ctx->r15;
    // 0x80079D1C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80079D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079D24: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80079D28: jal         0x8007A0D4
    // 0x80079D2C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    static_3_8007A0D4(rdram, ctx);
        goto after_18;
    // 0x80079D2C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_18:
    // 0x80079D30: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80079D34: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80079D38: beq         $v0, $a3, L_80079D50
    if (ctx->r2 == ctx->r7) {
        // 0x80079D3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80079D50;
    }
    // 0x80079D3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80079D40: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80079D44: jal         0x80079FA8
    // 0x80079D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    static_3_80079FA8(rdram, ctx);
        goto after_19;
    // 0x80079D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80079D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80079D50:
    // 0x80079D50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80079D54: jr          $ra
    // 0x80079D58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80079D58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80079D5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80079D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079D64: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80079D68: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80079D6C: lw          $a1, 0x278($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X278);
    // 0x80079D70: sw          $zero, 0x278($a0)
    MEM_W(0X278, ctx->r4) = 0;
    // 0x80079D74: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80079D78: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80079D7C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80079D80: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80079D84: jal         0x80079E40
    // 0x80079D88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    static_3_80079E40(rdram, ctx);
        goto after_20;
    // 0x80079D88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_20:
    // 0x80079D8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80079D90: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80079D94: lw          $t8, 0x274($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X274);
    // 0x80079D98: lw          $t1, 0x278($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X278);
    // 0x80079D9C: sltiu       $t9, $t8, 0x1
    ctx->r25 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80079DA0: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80079DA4: sltiu       $t2, $t1, 0x1
    ctx->r10 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80079DA8: or          $a3, $t0, $t2
    ctx->r7 = ctx->r8 | ctx->r10;
    // 0x80079DAC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80079DB0: jal         0x8007A0D4
    // 0x80079DB4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    static_3_8007A0D4(rdram, ctx);
        goto after_21;
    // 0x80079DB4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_21:
    // 0x80079DB8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80079DBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80079DC0: beq         $v0, $a3, L_80079DDC
    if (ctx->r2 == ctx->r7) {
        // 0x80079DC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80079DDC;
    }
    // 0x80079DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079DC8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80079DCC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80079DD0: jal         0x80079FA8
    // 0x80079DD4: nop

    static_3_80079FA8(rdram, ctx);
        goto after_22;
    // 0x80079DD4: nop

    after_22:
    // 0x80079DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80079DDC:
    // 0x80079DDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80079DE0: jr          $ra
    // 0x80079DE4: nop

    return;
    // 0x80079DE4: nop

;}
RECOMP_FUNC void static_3_80079E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079E48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80079E4C: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80079E50: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80079E54: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80079E58: bne         $t7, $zero, L_80079F30
    if (ctx->r15 != 0) {
        // 0x80079E5C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80079F30;
    }
    // 0x80079E5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80079E60: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
    // 0x80079E64: nop

    // 0x80079E68: beq         $a0, $zero, L_80079F28
    if (ctx->r4 == 0) {
        // 0x80079E6C: nop
    
            goto L_80079F28;
    }
    // 0x80079E6C: nop

    // 0x80079E70: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80079E74: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80079E78: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x80079E7C: beq         $t9, $zero, L_80079EEC
    if (ctx->r25 == 0) {
        // 0x80079E80: nop
    
            goto L_80079EEC;
    }
    // 0x80079E80: nop

    // 0x80079E84: lw          $t1, 0x280($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X280);
    // 0x80079E88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80079E8C: sltiu       $at, $t1, 0x2
    ctx->r1 = ctx->r9 < 0X2 ? 1 : 0;
    // 0x80079E90: beq         $at, $zero, L_80079EA0
    if (ctx->r1 == 0) {
        // 0x80079E94: nop
    
            goto L_80079EA0;
    }
    // 0x80079E94: nop

    // 0x80079E98: b           L_80079F30
    // 0x80079E9C: sw          $a1, 0x27C($t0)
    MEM_W(0X27C, ctx->r8) = ctx->r5;
        goto L_80079F30;
    // 0x80079E9C: sw          $a1, 0x27C($t0)
    MEM_W(0X27C, ctx->r8) = ctx->r5;
L_80079EA0:
    // 0x80079EA0: lw          $t2, 0x68($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X68);
    // 0x80079EA4: nop

    // 0x80079EA8: bne         $t2, $zero, L_80079EC0
    if (ctx->r10 != 0) {
        // 0x80079EAC: nop
    
            goto L_80079EC0;
    }
    // 0x80079EAC: nop

    // 0x80079EB0: lw          $t3, 0x54($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X54);
    // 0x80079EB4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80079EB8: beq         $t3, $zero, L_80079ED4
    if (ctx->r11 == 0) {
        // 0x80079EBC: addiu       $a1, $a1, -0x18D0
        ctx->r5 = ADD32(ctx->r5, -0X18D0);
            goto L_80079ED4;
    }
    // 0x80079EBC: addiu       $a1, $a1, -0x18D0
    ctx->r5 = ADD32(ctx->r5, -0X18D0);
L_80079EC0:
    // 0x80079EC0: lw          $a1, 0x54($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X54);
    // 0x80079EC4: jal         0x800C8E30
    // 0x80079EC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80079EC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80079ECC: b           L_80079EE0
    // 0x80079ED0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
        goto L_80079EE0;
    // 0x80079ED0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
L_80079ED4:
    // 0x80079ED4: jal         0x800C8E30
    // 0x80079ED8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80079ED8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80079EDC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
L_80079EE0:
    // 0x80079EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80079EE4: b           L_80079F30
    // 0x80079EE8: sw          $zero, 0x280($t4)
    MEM_W(0X280, ctx->r12) = 0;
        goto L_80079F30;
    // 0x80079EE8: sw          $zero, 0x280($t4)
    MEM_W(0X280, ctx->r12) = 0;
L_80079EEC:
    // 0x80079EEC: lw          $t5, 0x68($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X68);
    // 0x80079EF0: nop

    // 0x80079EF4: bne         $t5, $zero, L_80079F0C
    if (ctx->r13 != 0) {
        // 0x80079EF8: nop
    
            goto L_80079F0C;
    }
    // 0x80079EF8: nop

    // 0x80079EFC: lw          $t6, 0x54($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X54);
    // 0x80079F00: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80079F04: beq         $t6, $zero, L_80079F20
    if (ctx->r14 == 0) {
        // 0x80079F08: addiu       $a1, $a1, -0x18D0
        ctx->r5 = ADD32(ctx->r5, -0X18D0);
            goto L_80079F20;
    }
    // 0x80079F08: addiu       $a1, $a1, -0x18D0
    ctx->r5 = ADD32(ctx->r5, -0X18D0);
L_80079F0C:
    // 0x80079F0C: lw          $a1, 0x54($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X54);
    // 0x80079F10: jal         0x800C8E30
    // 0x80079F14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80079F14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80079F18: b           L_80079F30
    // 0x80079F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80079F30;
    // 0x80079F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80079F20:
    // 0x80079F20: jal         0x800C8E30
    // 0x80079F24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80079F24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_80079F28:
    // 0x80079F28: b           L_80079F30
    // 0x80079F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80079F30;
    // 0x80079F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80079F30:
    // 0x80079F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80079F38: jr          $ra
    // 0x80079F3C: nop

    return;
    // 0x80079F3C: nop

;}
RECOMP_FUNC void static_3_80079F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079F40: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x80079F44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079F48: bne         $v0, $at, L_80079F74
    if (ctx->r2 != ctx->r1) {
        // 0x80079F4C: nop
    
            goto L_80079F74;
    }
    // 0x80079F4C: nop

    // 0x80079F50: lw          $v0, 0x26C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X26C);
    // 0x80079F54: nop

    // 0x80079F58: beq         $v0, $zero, L_80079F68
    if (ctx->r2 == 0) {
        // 0x80079F5C: nop
    
            goto L_80079F68;
    }
    // 0x80079F5C: nop

    // 0x80079F60: b           L_80079F6C
    // 0x80079F64: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_80079F6C;
    // 0x80079F64: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_80079F68:
    // 0x80079F68: sw          $a1, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->r5;
L_80079F6C:
    // 0x80079F6C: b           L_80079F94
    // 0x80079F70: sw          $a1, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r5;
        goto L_80079F94;
    // 0x80079F70: sw          $a1, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r5;
L_80079F74:
    // 0x80079F74: lw          $v0, 0x270($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X270);
    // 0x80079F78: nop

    // 0x80079F7C: beq         $v0, $zero, L_80079F8C
    if (ctx->r2 == 0) {
        // 0x80079F80: nop
    
            goto L_80079F8C;
    }
    // 0x80079F80: nop

    // 0x80079F84: b           L_80079F90
    // 0x80079F88: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_80079F90;
    // 0x80079F88: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_80079F8C:
    // 0x80079F8C: sw          $a1, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r5;
L_80079F90:
    // 0x80079F90: sw          $a1, 0x270($a0)
    MEM_W(0X270, ctx->r4) = ctx->r5;
L_80079F94:
    // 0x80079F94: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80079F98: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80079F9C: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80079FA0: jr          $ra
    // 0x80079FA4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    return;
    // 0x80079FA4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void static_3_80079FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079FA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80079FAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80079FB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80079FB4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80079FB8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80079FBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80079FC0: beq         $a1, $zero, L_8007A038
    if (ctx->r5 == 0) {
        // 0x80079FC4: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8007A038;
    }
    // 0x80079FC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80079FC8: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80079FCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079FD0: bne         $t6, $at, L_80079FF0
    if (ctx->r14 != ctx->r1) {
        // 0x80079FD4: nop
    
            goto L_80079FF0;
    }
    // 0x80079FD4: nop

    // 0x80079FD8: jal         0x800D18A0
    // 0x80079FDC: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80079FDC: nop

    after_0:
    // 0x80079FE0: jal         0x800C78D0
    // 0x80079FE4: nop

    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x80079FE4: nop

    after_1:
    // 0x80079FE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80079FEC: sw          $v0, 0x6120($at)
    MEM_W(0X6120, ctx->r1) = ctx->r2;
L_80079FF0:
    // 0x80079FF0: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80079FF4: addiu       $at, $zero, -0x31
    ctx->r1 = ADD32(0, -0X31);
    // 0x80079FF8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80079FFC: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8007A000: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8007A004: jal         0x800D200C
    // 0x8007A008: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_2;
    // 0x8007A008: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8007A00C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8007A010: jal         0x800D216C
    // 0x8007A014: nop

    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_3;
    // 0x8007A014: nop

    after_3:
    // 0x8007A018: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A01C: sw          $zero, -0x18AC($at)
    MEM_W(-0X18AC, ctx->r1) = 0;
    // 0x8007A020: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007A024: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A028: sw          $zero, -0x18A8($at)
    MEM_W(-0X18A8, ctx->r1) = 0;
    // 0x8007A02C: bne         $s0, $s1, L_8007A038
    if (ctx->r16 != ctx->r17) {
        // 0x8007A030: sw          $s0, 0x274($t9)
        MEM_W(0X274, ctx->r25) = ctx->r16;
            goto L_8007A038;
    }
    // 0x8007A030: sw          $s0, 0x274($t9)
    MEM_W(0X274, ctx->r25) = ctx->r16;
    // 0x8007A034: sw          $s1, 0x278($t9)
    MEM_W(0X278, ctx->r25) = ctx->r17;
L_8007A038:
    // 0x8007A038: beq         $s1, $zero, L_8007A070
    if (ctx->r17 == 0) {
        // 0x8007A03C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A070;
    }
    // 0x8007A03C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A040: beq         $s1, $s0, L_8007A070
    if (ctx->r17 == ctx->r16) {
        // 0x8007A044: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A070;
    }
    // 0x8007A044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A048: lw          $t0, 0x3C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X3C);
    // 0x8007A04C: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x8007A050: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8007A054: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x8007A058: jal         0x800D18E0
    // 0x8007A05C: nop

    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_4;
    // 0x8007A05C: nop

    after_4:
    // 0x8007A060: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A064: nop

    // 0x8007A068: sw          $s1, 0x278($t1)
    MEM_W(0X278, ctx->r9) = ctx->r17;
    // 0x8007A06C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007A070:
    // 0x8007A070: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007A074: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007A078: jr          $ra
    // 0x8007A07C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007A07C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void static_3_8007A080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A088: lw          $v0, 0x274($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X274);
    // 0x8007A08C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007A090: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8007A094: nop

    // 0x8007A098: bne         $t6, $at, L_8007A0C8
    if (ctx->r14 != ctx->r1) {
        // 0x8007A09C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007A0C8;
    }
    // 0x8007A09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A0A0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8007A0A4: nop

    // 0x8007A0A8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8007A0AC: jal         0x800D21B0
    // 0x8007A0B0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A0B0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    after_0:
    // 0x8007A0B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A0B8: sw          $v0, 0x6118($at)
    MEM_W(0X6118, ctx->r1) = ctx->r2;
    // 0x8007A0BC: jal         0x800D2240
    // 0x8007A0C0: sw          $v1, 0x611C($at)
    MEM_W(0X611C, ctx->r1) = ctx->r3;
    osSpTaskYield_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A0C0: sw          $v1, 0x611C($at)
    MEM_W(0X611C, ctx->r1) = ctx->r3;
    after_1:
    // 0x8007A0C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A0C8:
    // 0x8007A0C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007A0CC: jr          $ra
    // 0x8007A0D0: nop

    return;
    // 0x8007A0D0: nop

;}
RECOMP_FUNC void static_3_8007A0D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A0D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A0D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007A0DC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007A0E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A0E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007A0E8: addiu       $t0, $zero, -0x3
    ctx->r8 = ADD32(0, -0X3);
L_8007A0EC:
    // 0x8007A0EC: lw          $t6, 0x284($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X284);
    // 0x8007A0F0: lw          $s0, 0x268($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X268);
    // 0x8007A0F4: lw          $v0, 0x264($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X264);
    // 0x8007A0F8: beq         $t6, $zero, L_8007A154
    if (ctx->r14 == 0) {
        // 0x8007A0FC: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8007A154;
    }
    // 0x8007A0FC: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007A100: andi        $t7, $a3, 0x2
    ctx->r15 = ctx->r7 & 0X2;
    // 0x8007A104: beq         $t7, $zero, L_8007A158
    if (ctx->r15 == 0) {
        // 0x8007A108: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8007A158;
    }
    // 0x8007A108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A10C: beq         $s0, $zero, L_8007A130
    if (ctx->r16 == 0) {
        // 0x8007A110: nop
    
            goto L_8007A130;
    }
    // 0x8007A110: nop

    // 0x8007A114: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8007A118: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A11C: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x8007A120: beq         $t9, $zero, L_8007A130
    if (ctx->r25 == 0) {
        // 0x8007A124: nop
    
            goto L_8007A130;
    }
    // 0x8007A124: nop

    // 0x8007A128: b           L_8007A2A4
    // 0x8007A12C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
        goto L_8007A2A4;
    // 0x8007A12C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
L_8007A130:
    // 0x8007A130: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007A134: lw          $t2, 0x264($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X264);
    // 0x8007A138: sw          $zero, 0x284($s1)
    MEM_W(0X284, ctx->r17) = 0;
    // 0x8007A13C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007A140: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A144: bne         $t3, $zero, L_8007A2A4
    if (ctx->r11 != 0) {
        // 0x8007A148: sw          $t3, 0x264($s1)
        MEM_W(0X264, ctx->r17) = ctx->r11;
            goto L_8007A2A4;
    }
    // 0x8007A148: sw          $t3, 0x264($s1)
    MEM_W(0X264, ctx->r17) = ctx->r11;
    // 0x8007A14C: b           L_8007A2A4
    // 0x8007A150: sw          $zero, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = 0;
        goto L_8007A2A4;
    // 0x8007A150: sw          $zero, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = 0;
L_8007A154:
    // 0x8007A154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8007A158:
    // 0x8007A158: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8007A15C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007A160: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007A164: jal         0x80079DE8
    // 0x8007A168: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    __scTaskReady(rdram, ctx);
        goto after_0;
    // 0x8007A168: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8007A16C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8007A170: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A174: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8007A178: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8007A17C: addiu       $t0, $zero, -0x3
    ctx->r8 = ADD32(0, -0X3);
    // 0x8007A180: beq         $v0, $zero, L_8007A2A4
    if (ctx->r2 == 0) {
        // 0x8007A184: addiu       $t1, $zero, -0x2
        ctx->r9 = ADD32(0, -0X2);
            goto L_8007A2A4;
    }
    // 0x8007A184: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
    // 0x8007A188: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8007A18C: nop

    // 0x8007A190: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8007A194: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007A198: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8007A19C: beq         $at, $zero, L_8007A2A4
    if (ctx->r1 == 0) {
        // 0x8007A1A0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8007A2A4;
    }
    // 0x8007A1A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007A1A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A1A8: addu        $at, $at, $t7
    gpr jr_addend_8007A1B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007A1AC: lw          $t7, 0x7970($at)
    ctx->r15 = ADD32(ctx->r1, 0X7970);
    // 0x8007A1B0: nop

    // 0x8007A1B4: jr          $t7
    // 0x8007A1B8: nop

    switch (jr_addend_8007A1B4 >> 2) {
        case 0: goto L_8007A2A4; break;
        case 1: goto L_8007A248; break;
        case 2: goto L_8007A1BC; break;
        case 3: goto L_8007A2A4; break;
        case 4: goto L_8007A2A4; break;
        case 5: goto L_8007A248; break;
        case 6: goto L_8007A248; break;
        default: switch_error(__func__, 0x8007A1B4, 0x800E7970);
    }
    // 0x8007A1B8: nop

L_8007A1BC:
    // 0x8007A1BC: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8007A1C0: andi        $t2, $a3, 0x2
    ctx->r10 = ctx->r7 & 0X2;
    // 0x8007A1C4: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x8007A1C8: beq         $t9, $zero, L_8007A218
    if (ctx->r25 == 0) {
        // 0x8007A1CC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8007A218;
    }
    // 0x8007A1CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007A1D0: beq         $t2, $zero, L_8007A2A4
    if (ctx->r10 == 0) {
        // 0x8007A1D4: nop
    
            goto L_8007A2A4;
    }
    // 0x8007A1D4: nop

    // 0x8007A1D8: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A1DC: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8007A1E0: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A1E4: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8007A1E8: beq         $t4, $zero, L_8007A1F8
    if (ctx->r12 == 0) {
        // 0x8007A1EC: nop
    
            goto L_8007A1F8;
    }
    // 0x8007A1EC: nop

    // 0x8007A1F0: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A1F4: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
L_8007A1F8:
    // 0x8007A1F8: lw          $t5, 0x268($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X268);
    // 0x8007A1FC: nop

    // 0x8007A200: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8007A204: nop

    // 0x8007A208: bne         $t6, $zero, L_8007A2A4
    if (ctx->r14 != 0) {
        // 0x8007A20C: sw          $t6, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r14;
            goto L_8007A2A4;
    }
    // 0x8007A20C: sw          $t6, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r14;
    // 0x8007A210: b           L_8007A2A4
    // 0x8007A214: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
        goto L_8007A2A4;
    // 0x8007A214: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A218:
    // 0x8007A218: bne         $a3, $at, L_8007A2A4
    if (ctx->r7 != ctx->r1) {
        // 0x8007A21C: nop
    
            goto L_8007A2A4;
    }
    // 0x8007A21C: nop

    // 0x8007A220: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A224: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A228: lw          $t8, 0x268($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X268);
    // 0x8007A22C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8007A230: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8007A234: and         $v1, $a3, $at
    ctx->r3 = ctx->r7 & ctx->r1;
    // 0x8007A238: bne         $t9, $zero, L_8007A2A4
    if (ctx->r25 != 0) {
        // 0x8007A23C: sw          $t9, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r25;
            goto L_8007A2A4;
    }
    // 0x8007A23C: sw          $t9, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r25;
    // 0x8007A240: b           L_8007A2A4
    // 0x8007A244: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
        goto L_8007A2A4;
    // 0x8007A244: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A248:
    // 0x8007A248: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8007A24C: andi        $t4, $a3, 0x2
    ctx->r12 = ctx->r7 & 0X2;
    // 0x8007A250: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8007A254: beq         $t3, $zero, L_8007A274
    if (ctx->r11 == 0) {
        // 0x8007A258: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8007A274;
    }
    // 0x8007A258: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8007A25C: beq         $t4, $zero, L_8007A274
    if (ctx->r12 == 0) {
        // 0x8007A260: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8007A274;
    }
    // 0x8007A260: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8007A264: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A268: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8007A26C: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A270: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
L_8007A274:
    // 0x8007A274: beq         $t5, $zero, L_8007A2A4
    if (ctx->r13 == 0) {
        // 0x8007A278: andi        $t6, $v1, 0x1
        ctx->r14 = ctx->r3 & 0X1;
            goto L_8007A2A4;
    }
    // 0x8007A278: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8007A27C: beq         $t6, $zero, L_8007A2A4
    if (ctx->r14 == 0) {
        // 0x8007A280: nop
    
            goto L_8007A2A4;
    }
    // 0x8007A280: nop

    // 0x8007A284: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A288: lw          $t7, 0x268($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X268);
    // 0x8007A28C: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
    // 0x8007A290: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007A294: nop

    // 0x8007A298: bne         $t8, $zero, L_8007A2A4
    if (ctx->r24 != 0) {
        // 0x8007A29C: sw          $t8, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r24;
            goto L_8007A2A4;
    }
    // 0x8007A29C: sw          $t8, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r24;
    // 0x8007A2A0: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A2A4:
    // 0x8007A2A4: beq         $v1, $a3, L_8007A2B8
    if (ctx->r3 == ctx->r7) {
        // 0x8007A2A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A2B8;
    }
    // 0x8007A2A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A2AC: b           L_8007A0EC
    // 0x8007A2B0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8007A0EC;
    // 0x8007A2B0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8007A2B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007A2B8:
    // 0x8007A2B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007A2BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007A2C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007A2C4: jr          $ra
    // 0x8007A2C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8007A2C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007A2CC: nop

;}
RECOMP_FUNC void static_3_800C75B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C75B0: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x800C75B4: bne         $t6, $zero, L_800C7694
    if (ctx->r14 != 0) {
        // 0x800C75B8: nop
    
            goto L_800C7694;
    }
    // 0x800C75B8: nop

    // 0x800C75BC: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x800C75C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C75C4: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
    // 0x800C75C8: blez        $t7, L_800C7694
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C75CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C7694;
    }
    // 0x800C75CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C75D0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C75D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800C75D8: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_800C75DC:
    // 0x800C75DC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C75E0: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800C75E4: lbu         $t6, 0xE($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XE);
    // 0x800C75E8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C75EC: bnel        $t6, $zero, L_800C7680
    if (ctx->r14 != 0) {
        // 0x800C75F0: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C7680;
    }
    goto skip_0;
    // 0x800C75F0: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_0:
    // 0x800C75F4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800C75F8: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
    // 0x800C75FC: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C7600: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C7604: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x800C7608: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x800C760C: addu        $t6, $t9, $a1
    ctx->r14 = ADD32(ctx->r25, ctx->r5);
    // 0x800C7610: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C7614: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800C7618: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800C761C: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x800C7620: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800C7624: bnel        $t9, $zero, L_800C7680
    if (ctx->r25 != 0) {
        // 0x800C7628: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C7680;
    }
    goto skip_1;
    // 0x800C7628: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_1:
    // 0x800C762C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800C7630: lbu         $a2, 0x8($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X8);
    // 0x800C7634: sb          $t1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r9;
    // 0x800C7638: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800C763C: bne         $a2, $zero, L_800C7664
    if (ctx->r6 != 0) {
        // 0x800C7640: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_800C7664;
    }
    // 0x800C7640: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C7644: lw          $t8, 0x10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X10);
    // 0x800C7648: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C764C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C7650: beq         $a2, $zero, L_800C767C
    if (ctx->r6 == 0) {
        // 0x800C7654: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_800C767C;
    }
    // 0x800C7654: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x800C7658: addu        $t6, $a2, $a1
    ctx->r14 = ADD32(ctx->r6, ctx->r5);
    // 0x800C765C: b           L_800C767C
    // 0x800C7660: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
        goto L_800C767C;
    // 0x800C7660: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
L_800C7664:
    // 0x800C7664: bnel        $t2, $a2, L_800C7680
    if (ctx->r10 != ctx->r6) {
        // 0x800C7668: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C7680;
    }
    goto skip_2;
    // 0x800C7668: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_2:
    // 0x800C766C: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C7670: beq         $a2, $zero, L_800C767C
    if (ctx->r6 == 0) {
        // 0x800C7674: addu        $t7, $a2, $a1
        ctx->r15 = ADD32(ctx->r6, ctx->r5);
            goto L_800C767C;
    }
    // 0x800C7674: addu        $t7, $a2, $a1
    ctx->r15 = ADD32(ctx->r6, ctx->r5);
    // 0x800C7678: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_800C767C:
    // 0x800C767C: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
L_800C7680:
    // 0x800C7680: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C7684: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C7688: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C768C: bnel        $at, $zero, L_800C75DC
    if (ctx->r1 != 0) {
        // 0x800C7690: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_800C75DC;
    }
    goto skip_3;
    // 0x800C7690: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_3:
L_800C7694:
    // 0x800C7694: jr          $ra
    // 0x800C7698: nop

    return;
    // 0x800C7698: nop

    // 0x800C769C: jr          $ra
    // 0x800C76A0: nop

    return;
    // 0x800C76A0: nop

;}
RECOMP_FUNC void static_3_800C7BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7BE0: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800C7BE4: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800C7BE8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C7BEC: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800C7BF0: beql        $t6, $zero, L_800C7C28
    if (ctx->r14 == 0) {
        // 0x800C7BF4: lw          $a3, 0x18($a2)
        ctx->r7 = MEM_W(ctx->r6, 0X18);
            goto L_800C7C28;
    }
    goto skip_0;
    // 0x800C7BF4: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
    skip_0:
    // 0x800C7BF8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C7BFC: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800C7C00: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x800C7C04: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C7C08: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C7C0C: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x800C7C10: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x800C7C14: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800C7C18: sb          $t6, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r14;
    // 0x800C7C1C: jr          $ra
    // 0x800C7C20: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C7C20: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C7C24: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
L_800C7C28:
    // 0x800C7C28: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x800C7C2C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C7C30: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C7C34: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x800C7C38: bne         $t0, $v1, L_800C7C9C
    if (ctx->r8 != ctx->r3) {
        // 0x800C7C3C: nop
    
            goto L_800C7C9C;
    }
    // 0x800C7C3C: nop

    // 0x800C7C40: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x800C7C44: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C7C48: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x800C7C4C: beq         $t0, $a0, L_800C7C9C
    if (ctx->r8 == ctx->r4) {
        // 0x800C7C50: addiu       $t6, $t9, 0x1
        ctx->r14 = ADD32(ctx->r25, 0X1);
            goto L_800C7C9C;
    }
    // 0x800C7C50: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C7C54: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800C7C58: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x800C7C5C: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x800C7C60: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C7C64: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x800C7C68: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x800C7C6C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800C7C70: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C7C74: addiu       $t9, $t7, -0x4
    ctx->r25 = ADD32(ctx->r15, -0X4);
    // 0x800C7C78: sw          $t9, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r25;
    // 0x800C7C7C: sb          $a1, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r5;
    // 0x800C7C80: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x800C7C84: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C7C88: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C7C8C: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x800C7C90: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800C7C94: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800C7C98: sb          $t7, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r15;
L_800C7C9C:
    // 0x800C7C9C: jr          $ra
    // 0x800C7CA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C7CA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
