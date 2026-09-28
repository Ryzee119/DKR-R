#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8001C6C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C6C4: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8001C6C8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8001C6CC: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8001C6D0: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8001C6D4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001C6D8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8001C6DC: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8001C6E0: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8001C6E4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8001C6E8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8001C6EC: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8001C6F0: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8001C6F4: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x8001C6F8: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8001C6FC: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x8001C700: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8001C704: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8001C708: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8001C70C: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8001C710: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001C714: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8001C718: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001C71C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8001C720: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x8001C724: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x8001C728: bne         $t6, $zero, L_8001C750
    if (ctx->r14 != 0) {
        // 0x8001C72C: sw          $a3, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r7;
            goto L_8001C750;
    }
    // 0x8001C72C: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
    // 0x8001C730: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C734: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001C738: lwc1        $f9, 0x5648($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5648);
    // 0x8001C73C: lwc1        $f8, 0x564C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X564C);
    // 0x8001C740: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001C744: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8001C748: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8001C74C: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
L_8001C750:
    // 0x8001C750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001C754: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001C758: addiu       $s5, $sp, 0xAC
    ctx->r21 = ADD32(ctx->r29, 0XAC);
    // 0x8001C75C: addiu       $s4, $sp, 0xC0
    ctx->r20 = ADD32(ctx->r29, 0XC0);
    // 0x8001C760: addiu       $s3, $sp, 0xD4
    ctx->r19 = ADD32(ctx->r29, 0XD4);
    // 0x8001C764: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x8001C768: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
L_8001C76C:
    // 0x8001C76C: lbu         $a0, 0xC($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XC);
    // 0x8001C770: nop

    // 0x8001C774: bne         $s0, $a0, L_8001C788
    if (ctx->r16 != ctx->r4) {
        // 0x8001C778: nop
    
            goto L_8001C788;
    }
    // 0x8001C778: nop

    // 0x8001C77C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C780: b           L_8001CBF8
    // 0x8001C784: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8001CBF8;
    // 0x8001C784: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8001C788:
    // 0x8001C788: sw          $a1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r5;
    // 0x8001C78C: jal         0x8001D214
    // 0x8001C790: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    ainode_get(rdram, ctx);
        goto after_0;
    // 0x8001C790: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001C794: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x8001C798: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8001C79C: bne         $v0, $zero, L_8001C7B0
    if (ctx->r2 != 0) {
        // 0x8001C7A0: sll         $v1, $a1, 2
        ctx->r3 = S32(ctx->r5 << 2);
            goto L_8001C7B0;
    }
    // 0x8001C7A0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8001C7A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C7A8: b           L_8001CBF8
    // 0x8001C7AC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8001CBF8;
    // 0x8001C7AC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8001C7B0:
    // 0x8001C7B0: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C7B4: addu        $t7, $s3, $v1
    ctx->r15 = ADD32(ctx->r19, ctx->r3);
    // 0x8001C7B8: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8001C7BC: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C7C0: addu        $t8, $s4, $v1
    ctx->r24 = ADD32(ctx->r20, ctx->r3);
    // 0x8001C7C4: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8001C7C8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C7CC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001C7D0: addu        $t9, $s5, $v1
    ctx->r25 = ADD32(ctx->r21, ctx->r3);
    // 0x8001C7D4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001C7D8: bne         $a1, $s1, L_8001C76C
    if (ctx->r5 != ctx->r17) {
        // 0x8001C7DC: swc1        $f6, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
            goto L_8001C76C;
    }
    // 0x8001C7DC: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x8001C7E0: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x8001C7E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001C7E8: jal         0x80022540
    // 0x8001C7EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_1;
    // 0x8001C7EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001C7F0: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x8001C7F4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x8001C7F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001C7FC: jal         0x80022540
    // 0x8001C800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_2;
    // 0x8001C800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8001C804: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x8001C808: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x8001C80C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001C810: jal         0x80022540
    // 0x8001C814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_3;
    // 0x8001C814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8001C818: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x8001C81C: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001C820: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001C824: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x8001C828: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8001C82C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C830: bc1f        L_8001C844
    if (!c1cs) {
        // 0x8001C834: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8001C844;
    }
    // 0x8001C834: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C838: lwc1        $f16, 0x5650($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5650);
    // 0x8001C83C: nop

    // 0x8001C840: swc1        $f16, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f16.u32l;
L_8001C844:
    // 0x8001C844: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001C848: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x8001C84C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001C850:
    // 0x8001C850: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001C854: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001C858: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8001C85C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001C860: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001C864: add.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001C868: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8001C86C: c.le.d      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.d <= ctx->f0.d;
    // 0x8001C870: nop

    // 0x8001C874: bc1f        L_8001C888
    if (!c1cs) {
        // 0x8001C878: nop
    
            goto L_8001C888;
    }
    // 0x8001C878: nop

    // 0x8001C87C: sub.d       $f10, $f0, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f28.d); 
    ctx->f10.d = ctx->f0.d - ctx->f28.d;
    // 0x8001C880: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8001C884: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
L_8001C888:
    // 0x8001C888: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001C88C: jal         0x80022540
    // 0x8001C890: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x8001C890: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8001C894: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001C898: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8001C89C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001C8A0: jal         0x80022540
    // 0x8001C8A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_5;
    // 0x8001C8A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x8001C8A8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001C8AC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8001C8B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001C8B4: jal         0x80022540
    // 0x8001C8B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_6;
    // 0x8001C8B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8001C8BC: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C8C0: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001C8C4: sub.s       $f24, $f24, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f30.fl;
    // 0x8001C8C8: sub.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f16.fl;
    // 0x8001C8CC: bne         $s0, $zero, L_8001C928
    if (ctx->r16 != 0) {
        // 0x8001C8D0: sub.s       $f26, $f0, $f18
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f18.fl;
            goto L_8001C928;
    }
    // 0x8001C8D0: sub.s       $f26, $f0, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8001C8D4: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001C8D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C8DC: mul.s       $f8, $f24, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8001C8E0: nop

    // 0x8001C8E4: mul.s       $f10, $f26, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8001C8E8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001C8EC: jal         0x800C9AD0
    // 0x8001C8F0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8001C8F0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_7:
    // 0x8001C8F4: lwc1        $f16, 0xF0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001C8F8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001C8FC: div.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8001C900: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8001C904: c.eq.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl == ctx->f2.fl;
    // 0x8001C908: nop

    // 0x8001C90C: bc1t        L_8001C928
    if (c1cs) {
        // 0x8001C910: nop
    
            goto L_8001C928;
    }
    // 0x8001C910: nop

    // 0x8001C914: div.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001C918: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8001C91C: nop

    // 0x8001C920: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001C924: swc1        $f10, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f10.u32l;
L_8001C928:
    // 0x8001C928: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001C92C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001C930: bne         $s0, $at, L_8001C850
    if (ctx->r16 != ctx->r1) {
        // 0x8001C934: nop
    
            goto L_8001C850;
    }
    // 0x8001C934: nop

    // 0x8001C938: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
    // 0x8001C93C: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
    // 0x8001C940: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C944: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001C948: add.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x8001C94C: add.s       $f30, $f24, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = ctx->f24.fl + ctx->f30.fl;
    // 0x8001C950: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x8001C954: add.s       $f4, $f26, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f26.fl + ctx->f8.fl;
    // 0x8001C958: swc1        $f30, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f30.u32l;
    // 0x8001C95C: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x8001C960: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C964: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C968: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C96C: sub.s       $f22, $f6, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8001C970: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001C974: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001C978: sub.s       $f24, $f30, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x8001C97C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C980: swc1        $f22, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f22.u32l;
    // 0x8001C984: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8001C988: sub.s       $f26, $f18, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8001C98C: swc1        $f26, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f26.u32l;
    // 0x8001C990: mul.s       $f16, $f26, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8001C994: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001C998: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
    // 0x8001C99C: jal         0x800C9AD0
    // 0x8001C9A0: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8001C9A0: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_8:
    // 0x8001C9A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001C9A8: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8001C9AC: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x8001C9B0: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8001C9B4: bc1t        L_8001C9EC
    if (c1cs) {
        // 0x8001C9B8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8001C9EC;
    }
    // 0x8001C9B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C9BC: lwc1        $f9, 0x5658($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5658);
    // 0x8001C9C0: lwc1        $f8, 0x565C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X565C);
    // 0x8001C9C4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8001C9C8: nop

    // 0x8001C9CC: div.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x8001C9D0: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8001C9D4: mul.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8001C9D8: nop

    // 0x8001C9DC: mul.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8001C9E0: nop

    // 0x8001C9E4: mul.s       $f26, $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x8001C9E8: nop

L_8001C9EC:
    // 0x8001C9EC: mul.s       $f18, $f30, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x8001C9F0: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001C9F4: nop

    // 0x8001C9F8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8001C9FC: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001CA00: jal         0x800C9AD0
    // 0x8001CA04: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x8001CA04: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_9:
    // 0x8001CA08: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8001CA0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001CA10: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8001CA14: div.s       $f20, $f0, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8001CA18: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8001CA1C: nop

    // 0x8001CA20: bc1f        L_8001CA2C
    if (!c1cs) {
        // 0x8001CA24: nop
    
            goto L_8001CA2C;
    }
    // 0x8001CA24: nop

    // 0x8001CA28: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
L_8001CA2C:
    // 0x8001CA2C: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8001CA30: c.le.d      $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f28.d <= ctx->f18.d;
    // 0x8001CA34: nop

    // 0x8001CA38: bc1f        L_8001CB2C
    if (!c1cs) {
        // 0x8001CA3C: lw          $t3, 0xEC($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XEC);
            goto L_8001CB2C;
    }
    // 0x8001CA3C: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CA40: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8001CA44: jal         0x80070750
    // 0x8001CA48: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    arctan2_f(rdram, ctx);
        goto after_10;
    // 0x8001CA48: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_10:
    // 0x8001CA4C: lw          $t0, 0xEC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CA50: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8001CA54: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
    // 0x8001CA58: ori         $s4, $zero, 0x8001
    ctx->r20 = 0 | 0X8001;
    // 0x8001CA5C: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x8001CA60: subu        $s0, $v0, $t1
    ctx->r16 = SUB32(ctx->r2, ctx->r9);
    // 0x8001CA64: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x8001CA68: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8001CA6C: bne         $at, $zero, L_8001CA7C
    if (ctx->r1 != 0) {
        // 0x8001CA70: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8001CA7C;
    }
    // 0x8001CA70: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001CA74: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8001CA78: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CA7C:
    // 0x8001CA7C: slti        $at, $s0, -0x8000
    ctx->r1 = SIGNED(ctx->r16) < -0X8000 ? 1 : 0;
    // 0x8001CA80: beq         $at, $zero, L_8001CA8C
    if (ctx->r1 == 0) {
        // 0x8001CA84: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8001CA8C;
    }
    // 0x8001CA84: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001CA88: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CA8C:
    // 0x8001CA8C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001CA90: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001CA94: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8001CA98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001CA9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001CAA0: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CAA4: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001CAA8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001CAAC: mfc1        $s3, $f8
    ctx->r19 = (int32_t)ctx->f8.u32l;
    // 0x8001CAB0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8001CAB4: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001CAB8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001CABC: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8001CAC0: mflo        $t3
    ctx->r11 = lo;
    // 0x8001CAC4: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8001CAC8: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8001CACC: jal         0x80070750
    // 0x8001CAD0: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x8001CAD0: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    after_11:
    // 0x8001CAD4: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CAD8: nop

    // 0x8001CADC: lh          $v1, 0x2($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X2);
    // 0x8001CAE0: nop

    // 0x8001CAE4: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8001CAE8: subu        $s0, $v0, $t8
    ctx->r16 = SUB32(ctx->r2, ctx->r24);
    // 0x8001CAEC: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8001CAF0: bne         $at, $zero, L_8001CB00
    if (ctx->r1 != 0) {
        // 0x8001CAF4: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8001CB00;
    }
    // 0x8001CAF4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8001CAF8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8001CAFC: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CB00:
    // 0x8001CB00: slti        $at, $s0, -0x8000
    ctx->r1 = SIGNED(ctx->r16) < -0X8000 ? 1 : 0;
    // 0x8001CB04: beq         $at, $zero, L_8001CB10
    if (ctx->r1 == 0) {
        // 0x8001CB08: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8001CB10;
    }
    // 0x8001CB08: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001CB0C: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
L_8001CB10:
    // 0x8001CB10: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001CB14: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CB18: mflo        $t9
    ctx->r25 = lo;
    // 0x8001CB1C: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8001CB20: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8001CB24: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x8001CB28: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
L_8001CB2C:
    // 0x8001CB2C: ori         $s0, $zero, 0x8000
    ctx->r16 = 0 | 0X8000;
    // 0x8001CB30: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8001CB34: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x8001CB38: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    // 0x8001CB3C: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8001CB40: jal         0x800707C4
    // 0x8001CB44: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_12;
    // 0x8001CB44: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_12:
    // 0x8001CB48: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CB4C: mul.s       $f22, $f0, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001CB50: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8001CB54: nop

    // 0x8001CB58: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x8001CB5C: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8001CB60: jal         0x800707F8
    // 0x8001CB64: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    coss_f(rdram, ctx);
        goto after_13;
    // 0x8001CB64: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_13:
    // 0x8001CB68: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001CB6C: lw          $a0, 0xEC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CB70: mul.s       $f10, $f22, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8001CB74: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8001CB78: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001CB7C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8001CB80: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8001CB84: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8001CB88: jal         0x80011570
    // 0x8001CB8C: nop

    move_object(rdram, ctx);
        goto after_14;
    // 0x8001CB8C: nop

    after_14:
    // 0x8001CB90: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001CB94: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x8001CB98: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001CB9C: swc1        $f4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f4.u32l;
    // 0x8001CBA0: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8001CBA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001CBA8: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x8001CBAC: nop

    // 0x8001CBB0: mul.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001CBB4: beq         $s1, $zero, L_8001CBF0
    if (ctx->r17 == 0) {
        // 0x8001CBB8: nop
    
            goto L_8001CBF0;
    }
    // 0x8001CBB8: nop

    // 0x8001CBBC: lbu         $t2, 0xD($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XD);
    // 0x8001CBC0: lbu         $t3, 0xE($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0XE);
    // 0x8001CBC4: lbu         $t4, 0xF($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XF);
    // 0x8001CBC8: lbu         $t5, 0x10($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X10);
    // 0x8001CBCC: sb          $t2, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r10;
    // 0x8001CBD0: sb          $t3, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r11;
    // 0x8001CBD4: sb          $t4, 0xE($s2)
    MEM_B(0XE, ctx->r18) = ctx->r12;
    // 0x8001CBD8: sb          $t5, 0xF($s2)
    MEM_B(0XF, ctx->r18) = ctx->r13;
    // 0x8001CBDC: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x8001CBE0: andi        $a1, $t4, 0xFF
    ctx->r5 = ctx->r12 & 0XFF;
    // 0x8001CBE4: jal         0x8001CC48
    // 0x8001CBE8: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    ainode_find_next(rdram, ctx);
        goto after_15;
    // 0x8001CBE8: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    after_15:
    // 0x8001CBEC: sb          $v0, 0x10($s2)
    MEM_B(0X10, ctx->r18) = ctx->r2;
L_8001CBF0:
    // 0x8001CBF0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x8001CBF4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8001CBF8:
    // 0x8001CBF8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001CBFC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001CC00: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001CC04: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001CC08: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8001CC0C: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CC10: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8001CC14: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001CC18: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8001CC1C: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001CC20: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8001CC24: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001CC28: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8001CC2C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8001CC30: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8001CC34: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8001CC38: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8001CC3C: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8001CC40: jr          $ra
    // 0x8001CC44: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8001CC44: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void waves_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7D20: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7D24: lw          $a0, 0x3040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3040);
    // 0x800B7D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7D2C: beq         $a0, $zero, L_800B7D44
    if (ctx->r4 == 0) {
        // 0x800B7D30: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B7D44;
    }
    // 0x800B7D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7D34: jal         0x80071140
    // 0x800B7D38: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800B7D38: nop

    after_0:
    // 0x800B7D3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7D40: sw          $zero, 0x3040($at)
    MEM_W(0X3040, ctx->r1) = 0;
L_800B7D44:
    // 0x800B7D44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7D48: lw          $a0, 0x3044($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3044);
    // 0x800B7D4C: nop

    // 0x800B7D50: beq         $a0, $zero, L_800B7D68
    if (ctx->r4 == 0) {
        // 0x800B7D54: nop
    
            goto L_800B7D68;
    }
    // 0x800B7D54: nop

    // 0x800B7D58: jal         0x80071140
    // 0x800B7D5C: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800B7D5C: nop

    after_1:
    // 0x800B7D60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7D64: sw          $zero, 0x3044($at)
    MEM_W(0X3044, ctx->r1) = 0;
L_800B7D68:
    // 0x800B7D68: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7D6C: lw          $a0, 0x3048($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3048);
    // 0x800B7D70: nop

    // 0x800B7D74: beq         $a0, $zero, L_800B7D8C
    if (ctx->r4 == 0) {
        // 0x800B7D78: nop
    
            goto L_800B7D8C;
    }
    // 0x800B7D78: nop

    // 0x800B7D7C: jal         0x80071140
    // 0x800B7D80: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800B7D80: nop

    after_2:
    // 0x800B7D84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7D88: sw          $zero, 0x3048($at)
    MEM_W(0X3048, ctx->r1) = 0;
L_800B7D8C:
    // 0x800B7D8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7D90: lw          $a0, 0x304C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X304C);
    // 0x800B7D94: nop

    // 0x800B7D98: beq         $a0, $zero, L_800B7DB0
    if (ctx->r4 == 0) {
        // 0x800B7D9C: nop
    
            goto L_800B7DB0;
    }
    // 0x800B7D9C: nop

    // 0x800B7DA0: jal         0x80071140
    // 0x800B7DA4: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800B7DA4: nop

    after_3:
    // 0x800B7DA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7DAC: sw          $zero, 0x304C($at)
    MEM_W(0X304C, ctx->r1) = 0;
L_800B7DB0:
    // 0x800B7DB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7DB4: lw          $a0, 0x3070($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3070);
    // 0x800B7DB8: nop

    // 0x800B7DBC: beq         $a0, $zero, L_800B7DD4
    if (ctx->r4 == 0) {
        // 0x800B7DC0: nop
    
            goto L_800B7DD4;
    }
    // 0x800B7DC0: nop

    // 0x800B7DC4: jal         0x80071140
    // 0x800B7DC8: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800B7DC8: nop

    after_4:
    // 0x800B7DCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7DD0: sw          $zero, 0x3070($at)
    MEM_W(0X3070, ctx->r1) = 0;
L_800B7DD4:
    // 0x800B7DD4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7DD8: lw          $a0, 0x3080($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3080);
    // 0x800B7DDC: nop

    // 0x800B7DE0: beq         $a0, $zero, L_800B7DF8
    if (ctx->r4 == 0) {
        // 0x800B7DE4: nop
    
            goto L_800B7DF8;
    }
    // 0x800B7DE4: nop

    // 0x800B7DE8: jal         0x80071140
    // 0x800B7DEC: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800B7DEC: nop

    after_5:
    // 0x800B7DF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7DF4: sw          $zero, 0x3080($at)
    MEM_W(0X3080, ctx->r1) = 0;
L_800B7DF8:
    // 0x800B7DF8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7DFC: lw          $a0, 0x30D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30D0);
    // 0x800B7E00: nop

    // 0x800B7E04: beq         $a0, $zero, L_800B7E1C
    if (ctx->r4 == 0) {
        // 0x800B7E08: nop
    
            goto L_800B7E1C;
    }
    // 0x800B7E08: nop

    // 0x800B7E0C: jal         0x8007B2BC
    // 0x800B7E10: nop

    tex_free(rdram, ctx);
        goto after_6;
    // 0x800B7E10: nop

    after_6:
    // 0x800B7E14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7E18: sw          $zero, 0x30D0($at)
    MEM_W(0X30D0, ctx->r1) = 0;
L_800B7E1C:
    // 0x800B7E1C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7E20: lw          $a0, 0x30D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30D4);
    // 0x800B7E24: nop

    // 0x800B7E28: beq         $a0, $zero, L_800B7E40
    if (ctx->r4 == 0) {
        // 0x800B7E2C: nop
    
            goto L_800B7E40;
    }
    // 0x800B7E2C: nop

    // 0x800B7E30: jal         0x80071140
    // 0x800B7E34: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x800B7E34: nop

    after_7:
    // 0x800B7E38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7E3C: sw          $zero, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = 0;
L_800B7E40:
    // 0x800B7E40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7E44: lw          $a0, 0x30D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30D8);
    // 0x800B7E48: nop

    // 0x800B7E4C: beq         $a0, $zero, L_800B7E64
    if (ctx->r4 == 0) {
        // 0x800B7E50: nop
    
            goto L_800B7E64;
    }
    // 0x800B7E50: nop

    // 0x800B7E54: jal         0x80071140
    // 0x800B7E58: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x800B7E58: nop

    after_8:
    // 0x800B7E5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7E60: sw          $zero, 0x30D8($at)
    MEM_W(0X30D8, ctx->r1) = 0;
L_800B7E64:
    // 0x800B7E64: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7E68: lw          $a0, 0x3178($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3178);
    // 0x800B7E6C: nop

    // 0x800B7E70: beq         $a0, $zero, L_800B7E88
    if (ctx->r4 == 0) {
        // 0x800B7E74: nop
    
            goto L_800B7E88;
    }
    // 0x800B7E74: nop

    // 0x800B7E78: jal         0x80071140
    // 0x800B7E7C: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x800B7E7C: nop

    after_9:
    // 0x800B7E80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7E84: sw          $zero, 0x3178($at)
    MEM_W(0X3178, ctx->r1) = 0;
L_800B7E88:
    // 0x800B7E88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7E8C: sw          $zero, 0x3190($at)
    MEM_W(0X3190, ctx->r1) = 0;
    // 0x800B7E90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7E94: sw          $zero, 0x3194($at)
    MEM_W(0X3194, ctx->r1) = 0;
    // 0x800B7E98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7EA0: sw          $zero, 0x3184($at)
    MEM_W(0X3184, ctx->r1) = 0;
    // 0x800B7EA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7EA8: sw          $zero, 0x3188($at)
    MEM_W(0X3188, ctx->r1) = 0;
    // 0x800B7EAC: jr          $ra
    // 0x800B7EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B7EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void free_game_text_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C30CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C30D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C30D4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800C30D8: addiu       $s1, $s1, 0x3670
    ctx->r17 = ADD32(ctx->r17, 0X3670);
    // 0x800C30DC: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x800C30E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C30E4: beq         $t6, $zero, L_800C312C
    if (ctx->r14 == 0) {
        // 0x800C30E8: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800C312C;
    }
    // 0x800C30E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C30EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C30F0: lw          $a0, -0x5880($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5880);
    // 0x800C30F4: jal         0x80071140
    // 0x800C30F8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800C30F8: nop

    after_0:
    // 0x800C30FC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x800C3100: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3104: sb          $zero, -0x5877($at)
    MEM_B(-0X5877, ctx->r1) = 0;
    // 0x800C3108: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x800C310C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800C3110:
    // 0x800C3110: jal         0x8009CFB0
    // 0x800C3114: nop

    dialogue_try_close(rdram, ctx);
        goto after_1;
    // 0x800C3114: nop

    after_1:
    // 0x800C3118: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C311C: bne         $s0, $s1, L_800C3110
    if (ctx->r16 != ctx->r17) {
        // 0x800C3120: nop
    
            goto L_800C3110;
    }
    // 0x800C3120: nop

    // 0x800C3124: jal         0x800C2AB4
    // 0x800C3128: nop

    free_message_box(rdram, ctx);
        goto after_2;
    // 0x800C3128: nop

    after_2:
L_800C312C:
    // 0x800C312C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3130: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C3134: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C3138: jr          $ra
    // 0x800C313C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C313C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void cam_shake_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800660C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800660C8: jr          $ra
    // 0x800660CC: sw          $t6, 0xD18($at)
    MEM_W(0XD18, ctx->r1) = ctx->r14;
    return;
    // 0x800660CC: sw          $t6, 0xD18($at)
    MEM_W(0XD18, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void savemenu_render_error(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800871DC: lui         $at, 0x3FFF
    ctx->r1 = S32(0X3FFF << 16);
    // 0x800871E0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800871E4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800871E8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800871EC: sra         $t6, $a0, 30
    ctx->r14 = S32(SIGNED(ctx->r4) >> 30);
    // 0x800871F0: and         $t8, $a0, $at
    ctx->r24 = ctx->r4 & ctx->r1;
    // 0x800871F4: addiu       $s5, $s5, -0x520
    ctx->r21 = ADD32(ctx->r21, -0X520);
    // 0x800871F8: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x800871FC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80087200: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80087204: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80087208: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x8008720C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80087210: lw          $t0, -0x424($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X424);
    // 0x80087214: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80087218: addiu       $s4, $s4, 0x6A70
    ctx->r20 = ADD32(ctx->r20, 0X6A70);
    // 0x8008721C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087220: sw          $t0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r8;
    // 0x80087224: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80087228: sw          $t8, -0x524($at)
    MEM_W(-0X524, ctx->r1) = ctx->r24;
    // 0x8008722C: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80087230: addiu       $a1, $a1, 0x6A74
    ctx->r5 = ADD32(ctx->r5, 0X6A74);
    // 0x80087234: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80087238: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8008723C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80087240: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80087244: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80087248: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8008724C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80087250: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80087254: beq         $t1, $zero, L_80087270
    if (ctx->r9 == 0) {
        // 0x80087258: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80087270;
    }
    // 0x80087258: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008725C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80087260:
    // 0x80087260: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x80087264: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80087268: bne         $t2, $zero, L_80087260
    if (ctx->r10 != 0) {
        // 0x8008726C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80087260;
    }
    // 0x8008726C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80087270:
    // 0x80087270: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80087274: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80087278: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x8008727C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80087280: nop

    // 0x80087284: beq         $t4, $zero, L_800872AC
    if (ctx->r12 == 0) {
        // 0x80087288: nop
    
            goto L_800872AC;
    }
    // 0x80087288: nop

L_8008728C:
    // 0x8008728C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80087290: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80087294: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80087298: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8008729C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800872A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800872A4: bne         $t7, $zero, L_8008728C
    if (ctx->r15 != 0) {
        // 0x800872A8: nop
    
            goto L_8008728C;
    }
    // 0x800872A8: nop

L_800872AC:
    // 0x800872AC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800872B0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800872B4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800872B8: jal         0x800C5494
    // 0x800872BC: sw          $t9, 0x6A78($at)
    MEM_W(0X6A78, ctx->r1) = ctx->r25;
    dialogue_clear(rdram, ctx);
        goto after_0;
    // 0x800872BC: sw          $t9, 0x6A78($at)
    MEM_W(0X6A78, ctx->r1) = ctx->r25;
    after_0:
    // 0x800872C0: sll         $v0, $s0, 4
    ctx->r2 = S32(ctx->r16 << 4);
    // 0x800872C4: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x800872C8: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800872CC: addiu       $t2, $t0, 0x78
    ctx->r10 = ADD32(ctx->r8, 0X78);
    // 0x800872D0: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x800872D4: subu        $a2, $t1, $t0
    ctx->r6 = SUB32(ctx->r9, ctx->r8);
    // 0x800872D8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800872DC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800872E0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800872E4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800872E8: jal         0x800C4EDC
    // 0x800872EC: addiu       $a3, $zero, 0x118
    ctx->r7 = ADD32(0, 0X118);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x800872EC: addiu       $a3, $zero, 0x118
    ctx->r7 = ADD32(0, 0X118);
    after_1:
    // 0x800872F0: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x800872F4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800872F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800872FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087300: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087304: jal         0x800C4FBC
    // 0x80087308: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x80087308: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8008730C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087314: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087318: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008731C: jal         0x800C5050
    // 0x80087320: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_3;
    // 0x80087320: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80087324: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087328: jal         0x800C4F7C
    // 0x8008732C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_dialogue_font(rdram, ctx);
        goto after_4;
    // 0x8008732C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80087330: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80087334: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80087338: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8008733C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80087340: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80087344: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80087348: jal         0x800C5000
    // 0x8008734C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_5;
    // 0x8008734C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80087350: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80087354: lw          $v0, -0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB60);
    // 0x80087358: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8008735C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80087360: addiu       $t5, $t5, -0x474
    ctx->r13 = ADD32(ctx->r13, -0X474);
    // 0x80087364: lw          $a3, 0x100($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X100);
    // 0x80087368: beq         $v1, $t5, L_80087380
    if (ctx->r3 == ctx->r13) {
        // 0x8008736C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80087380;
    }
    // 0x8008736C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087370: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80087374: addiu       $t6, $t6, -0x45C
    ctx->r14 = ADD32(ctx->r14, -0X45C);
    // 0x80087378: bne         $v1, $t6, L_8008738C
    if (ctx->r3 != ctx->r14) {
        // 0x8008737C: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8008738C;
    }
    // 0x8008737C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
L_80087380:
    // 0x80087380: lw          $a3, 0x260($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X260);
    // 0x80087384: b           L_800873A4
    // 0x80087388: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_800873A4;
    // 0x80087388: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8008738C:
    // 0x8008738C: addiu       $t7, $t7, -0x444
    ctx->r15 = ADD32(ctx->r15, -0X444);
    // 0x80087390: bne         $v1, $t7, L_800873A4
    if (ctx->r3 != ctx->r15) {
        // 0x80087394: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800873A4;
    }
    // 0x80087394: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80087398: lw          $a3, 0x1F4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1F4);
    // 0x8008739C: nop

    // 0x800873A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_800873A4:
    // 0x800873A4: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800873A8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800873AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800873B0: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x800873B4: jal         0x800C5168
    // 0x800873B8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    render_dialogue_text(rdram, ctx);
        goto after_6;
    // 0x800873B8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_6:
    // 0x800873BC: addiu       $s2, $zero, 0x34
    ctx->r18 = ADD32(0, 0X34);
    // 0x800873C0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800873C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800873C8: jal         0x800C4F7C
    // 0x800873CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_7;
    // 0x800873CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800873D0: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800873D4: sll         $s0, $s3, 2
    ctx->r16 = S32(ctx->r19 << 2);
    // 0x800873D8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800873DC: addu        $t1, $v1, $s0
    ctx->r9 = ADD32(ctx->r3, ctx->r16);
    // 0x800873E0: beq         $t0, $zero, L_80087434
    if (ctx->r8 == 0) {
        // 0x800873E4: nop
    
            goto L_80087434;
    }
    // 0x800873E4: nop

    // 0x800873E8: lw          $s1, 0x0($t1)
    ctx->r17 = MEM_W(ctx->r9, 0X0);
    // 0x800873EC: nop

L_800873F0:
    // 0x800873F0: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x800873F4: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x800873F8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800873FC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80087400: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80087404: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087408: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008740C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80087410: jal         0x800C5168
    // 0x80087414: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_8;
    // 0x80087414: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_8:
    // 0x80087418: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8008741C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80087420: addu        $t5, $v1, $s0
    ctx->r13 = ADD32(ctx->r3, ctx->r16);
    // 0x80087424: lw          $s1, 0x0($t5)
    ctx->r17 = MEM_W(ctx->r13, 0X0);
    // 0x80087428: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008742C: bne         $s1, $zero, L_800873F0
    if (ctx->r17 != 0) {
        // 0x80087430: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_800873F0;
    }
    // 0x80087430: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_80087434:
    // 0x80087434: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80087438: sll         $s0, $s3, 2
    ctx->r16 = S32(ctx->r19 << 2);
    // 0x8008743C: addu        $t6, $v1, $s0
    ctx->r14 = ADD32(ctx->r3, ctx->r16);
    // 0x80087440: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x80087444: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80087448: beq         $s1, $zero, L_80087498
    if (ctx->r17 == 0) {
        // 0x8008744C: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_80087498;
    }
    // 0x8008744C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80087450: addiu       $s3, $s3, 0x6A80
    ctx->r19 = ADD32(ctx->r19, 0X6A80);
L_80087454:
    // 0x80087454: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80087458: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8008745C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80087460: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80087464: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80087468: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008746C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80087470: jal         0x800C5168
    // 0x80087474: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_9;
    // 0x80087474: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_9:
    // 0x80087478: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8008747C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80087480: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80087484: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80087488: lw          $s1, 0x0($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X0);
    // 0x8008748C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80087490: bne         $s1, $zero, L_80087454
    if (ctx->r17 != 0) {
        // 0x80087494: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_80087454;
    }
    // 0x80087494: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_80087498:
    // 0x80087498: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008749C: addiu       $v0, $v0, 0x63E0
    ctx->r2 = ADD32(ctx->r2, 0X63E0);
    // 0x800874A0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800874A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800874A8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800874AC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800874B0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800874B4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800874B8: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800874BC: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800874C0: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x800874C4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800874C8: jr          $ra
    // 0x800874CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800874CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void align4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071888: andi        $v1, $a0, 0x3
    ctx->r3 = ctx->r4 & 0X3;
    // 0x8007188C: blez        $v1, L_8007189C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071890: nop
    
            goto L_8007189C;
    }
    // 0x80071890: nop

    // 0x80071894: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80071898: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8007189C:
    // 0x8007189C: jr          $ra
    // 0x800718A0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800718A0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void hud_main_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0DC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A0DC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A0DC8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A0DCC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A0DD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A0DD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A0DD8: lw          $s1, 0x64($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X64);
    // 0x800A0DDC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800A0DE0: jal         0x80068508
    // 0x800A0DE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A0DE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A0DE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A0DEC: jal         0x800A0EB4
    // 0x800A0DF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_course_arrows(rdram, ctx);
        goto after_1;
    // 0x800A0DF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800A0DF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A0DF8: jal         0x800A5A64
    // 0x800A0DFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_wrong_way(rdram, ctx);
        goto after_2;
    // 0x800A0DFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800A0E00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A0E04: jal         0x800A3CE4
    // 0x800A0E08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_start(rdram, ctx);
        goto after_3;
    // 0x800A0E08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800A0E0C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A0E10: lw          $t7, 0x6D60($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D60);
    // 0x800A0E14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A0E18: lb          $t8, 0x4C($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X4C);
    // 0x800A0E1C: nop

    // 0x800A0E20: bne         $t8, $zero, L_800A0E30
    if (ctx->r24 != 0) {
        // 0x800A0E24: nop
    
            goto L_800A0E30;
    }
    // 0x800A0E24: nop

    // 0x800A0E28: jal         0x800A4F50
    // 0x800A0E2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_lap_count(rdram, ctx);
        goto after_4;
    // 0x800A0E2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
L_800A0E30:
    // 0x800A0E30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A0E34: jal         0x800A4154
    // 0x800A0E38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_bananas(rdram, ctx);
        goto after_5;
    // 0x800A0E38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800A0E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A0E40: jal         0x800A7B68
    // 0x800A0E44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_time(rdram, ctx);
        goto after_6;
    // 0x800A0E44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800A0E48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A0E4C: jal         0x800A4C44
    // 0x800A0E50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_position(rdram, ctx);
        goto after_7;
    // 0x800A0E50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800A0E54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A0E58: jal         0x800A3884
    // 0x800A0E5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_speedometre(rdram, ctx);
        goto after_8;
    // 0x800A0E5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800A0E60: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A0E64: lbu         $t9, 0x7188($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7188);
    // 0x800A0E68: nop

    // 0x800A0E6C: beq         $t9, $zero, L_800A0E90
    if (ctx->r25 == 0) {
        // 0x800A0E70: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800A0E90;
    }
    // 0x800A0E70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A0E74: lb          $t0, 0x1D8($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X1D8);
    // 0x800A0E78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A0E7C: bne         $t0, $zero, L_800A0E8C
    if (ctx->r8 != 0) {
        // 0x800A0E80: nop
    
            goto L_800A0E8C;
    }
    // 0x800A0E80: nop

    // 0x800A0E84: jal         0x800A47A0
    // 0x800A0E88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_silver_coins(rdram, ctx);
        goto after_9;
    // 0x800A0E88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
L_800A0E8C:
    // 0x800A0E8C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_800A0E90:
    // 0x800A0E90: jal         0x800A7520
    // 0x800A0E94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_weapon(rdram, ctx);
        goto after_10;
    // 0x800A0E94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800A0E98: jal         0x80068508
    // 0x800A0E9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_11;
    // 0x800A0E9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A0EA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A0EA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A0EA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A0EAC: jr          $ra
    // 0x800A0EB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A0EB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void set_boss_voice_clip_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CA78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005CA7C: jr          $ra
    // 0x8005CA80: sw          $a0, -0x2A38($at)
    MEM_W(-0X2A38, ctx->r1) = ctx->r4;
    return;
    // 0x8005CA80: sw          $a0, -0x2A38($at)
    MEM_W(-0X2A38, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void asset_table_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_asset_api(uint8_t*, recomp_context*, unsigned); if (dkr_legacy_asset_api(rdram, ctx, 3U)) return;
    // 0x80076F30: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80076F34: lw          $v1, 0x4290($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4290);
    // 0x80076F38: nop

    // 0x80076F3C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80076F40: nop

    // 0x80076F44: sltu        $at, $t6, $a0
    ctx->r1 = ctx->r14 < ctx->r4 ? 1 : 0;
    // 0x80076F48: beq         $at, $zero, L_80076F58
    if (ctx->r1 == 0) {
        // 0x80076F4C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80076F58;
    }
    // 0x80076F4C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80076F50: jr          $ra
    // 0x80076F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80076F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076F58:
    // 0x80076F58: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80076F5C: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80076F60: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80076F64: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80076F68: nop

    // 0x80076F6C: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    // 0x80076F70: jr          $ra
    // 0x80076F74: nop

    return;
    // 0x80076F74: nop

;}
RECOMP_FUNC void update_AI_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A6F0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8005A6F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005A6F8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005A6FC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8005A700: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A704: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8005A708: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8005A70C: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8005A710: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x8005A714: jal         0x8006DA0C
    // 0x8005A718: sw          $t6, -0x2AA4($at)
    MEM_W(-0X2AA4, ctx->r1) = ctx->r14;
    get_game_mode(rdram, ctx);
        goto after_0;
    // 0x8005A718: sw          $t6, -0x2AA4($at)
    MEM_W(-0X2AA4, ctx->r1) = ctx->r14;
    after_0:
    // 0x8005A71C: jal         0x8006BDB0
    // 0x8005A720: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    level_header(rdram, ctx);
        goto after_1;
    // 0x8005A720: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005A724: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8005A728: lb          $v1, 0x1F6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1F6);
    // 0x8005A72C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005A730: blez        $v1, L_8005A74C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005A734: nop
    
            goto L_8005A74C;
    }
    // 0x8005A734: nop

    // 0x8005A738: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8005A73C: nop

    // 0x8005A740: subu        $t8, $v1, $t7
    ctx->r24 = SUB32(ctx->r3, ctx->r15);
    // 0x8005A744: b           L_8005A750
    // 0x8005A748: sb          $t8, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r24;
        goto L_8005A750;
    // 0x8005A748: sb          $t8, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r24;
L_8005A74C:
    // 0x8005A74C: sb          $zero, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = 0;
L_8005A750:
    // 0x8005A750: lw          $t9, -0x2AC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AC0);
    // 0x8005A754: nop

    // 0x8005A758: beq         $t9, $zero, L_8005A770
    if (ctx->r25 == 0) {
        // 0x8005A75C: addiu       $a0, $zero, -0x3C
        ctx->r4 = ADD32(0, -0X3C);
            goto L_8005A770;
    }
    // 0x8005A75C: addiu       $a0, $zero, -0x3C
    ctx->r4 = ADD32(0, -0X3C);
    // 0x8005A760: jal         0x8006F94C
    // 0x8005A764: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x8005A764: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x8005A768: addiu       $t5, $v0, 0x78
    ctx->r13 = ADD32(ctx->r2, 0X78);
    // 0x8005A76C: sh          $t5, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r13;
L_8005A770:
    // 0x8005A770: lh          $v0, 0x18C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18C);
    // 0x8005A774: nop

    // 0x8005A778: blez        $v0, L_8005A794
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005A77C: nop
    
            goto L_8005A794;
    }
    // 0x8005A77C: nop

    // 0x8005A780: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005A784: nop

    // 0x8005A788: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8005A78C: b           L_8005A798
    // 0x8005A790: sh          $t7, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r15;
        goto L_8005A798;
    // 0x8005A790: sh          $t7, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r15;
L_8005A794:
    // 0x8005A794: sh          $zero, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = 0;
L_8005A798:
    // 0x8005A798: jal         0x8001E29C
    // 0x8005A79C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8005A79C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_3:
    // 0x8005A7A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005A7A4: addiu       $v1, $v1, -0x2A9C
    ctx->r3 = ADD32(ctx->r3, -0X2A9C);
    // 0x8005A7A8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005A7AC: lb          $t9, 0x3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3);
    // 0x8005A7B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A7B4: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8005A7B8: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005A7BC: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005A7C0: lwc1        $f9, 0x6940($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6940);
    // 0x8005A7C4: lwc1        $f8, 0x6944($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6944);
    // 0x8005A7C8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005A7CC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005A7D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8005A7D4: addiu       $t4, $t4, -0x2A94
    ctx->r12 = ADD32(ctx->r12, -0X2A94);
    // 0x8005A7D8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005A7DC: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x8005A7E0: lh          $t7, 0x204($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X204);
    // 0x8005A7E4: nop

    // 0x8005A7E8: blez        $t7, L_8005A7FC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005A7EC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005A7FC;
    }
    // 0x8005A7EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A7F0: lwc1        $f4, 0x6948($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6948);
    // 0x8005A7F4: nop

    // 0x8005A7F8: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
L_8005A7FC:
    // 0x8005A7FC: jal         0x8001E29C
    // 0x8005A800: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    get_misc_asset(rdram, ctx);
        goto after_4;
    // 0x8005A800: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_4:
    // 0x8005A804: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005A808: addiu       $v1, $v1, -0x2A9C
    ctx->r3 = ADD32(ctx->r3, -0X2A9C);
    // 0x8005A80C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005A810: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x8005A814: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A818: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8005A81C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005A820: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005A824: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8005A828: jal         0x8001E29C
    // 0x8005A82C: swc1        $f6, -0x2A90($at)
    MEM_W(-0X2A90, ctx->r1) = ctx->f6.u32l;
    get_misc_asset(rdram, ctx);
        goto after_5;
    // 0x8005A82C: swc1        $f6, -0x2A90($at)
    MEM_W(-0X2A90, ctx->r1) = ctx->f6.u32l;
    after_5:
    // 0x8005A830: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005A834: addiu       $a1, $a1, -0x2A9C
    ctx->r5 = ADD32(ctx->r5, -0X2A9C);
    // 0x8005A838: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8005A83C: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x8005A840: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005A844: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005A848: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x8005A84C: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8005A850: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A854: swc1        $f8, -0x2A8C($at)
    MEM_W(-0X2A8C, ctx->r1) = ctx->f8.u32l;
    // 0x8005A858: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005A85C: nop

    // 0x8005A860: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x8005A864: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005A868: nop

    // 0x8005A86C: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x8005A870: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8005A874: nop

    // 0x8005A878: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x8005A87C: lh          $v1, 0x1B2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1B2);
    // 0x8005A880: nop

    // 0x8005A884: blez        $v1, L_8005A8B0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005A888: nop
    
            goto L_8005A8B0;
    }
    // 0x8005A888: nop

    // 0x8005A88C: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005A890: nop

    // 0x8005A894: subu        $t8, $v1, $t6
    ctx->r24 = SUB32(ctx->r3, ctx->r14);
    // 0x8005A898: sh          $t8, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = ctx->r24;
    // 0x8005A89C: lh          $t7, 0x1B2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1B2);
    // 0x8005A8A0: nop

    // 0x8005A8A4: bgez        $t7, L_8005A8B0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005A8A8: nop
    
            goto L_8005A8B0;
    }
    // 0x8005A8A8: nop

    // 0x8005A8AC: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
L_8005A8B0:
    // 0x8005A8B0: lb          $t9, 0x1E7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005A8B4: nop

    // 0x8005A8B8: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8005A8BC: jal         0x8002341C
    // 0x8005A8C0: sb          $t5, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r13;
    is_taj_challenge(rdram, ctx);
        goto after_6;
    // 0x8005A8C0: sb          $t5, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r13;
    after_6:
    // 0x8005A8C4: bne         $v0, $zero, L_8005A930
    if (ctx->r2 != 0) {
        // 0x8005A8C8: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A930;
    }
    // 0x8005A8C8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A8CC: jal         0x80023568
    // 0x8005A8D0: nop

    func_80023568(rdram, ctx);
        goto after_7;
    // 0x8005A8D0: nop

    after_7:
    // 0x8005A8D4: bne         $v0, $zero, L_8005A930
    if (ctx->r2 != 0) {
        // 0x8005A8D8: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A930;
    }
    // 0x8005A8D8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A8DC: lb          $t6, 0x1D6($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D6);
    // 0x8005A8E0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005A8E4: beq         $t6, $at, L_8005A92C
    if (ctx->r14 == ctx->r1) {
        // 0x8005A8E8: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8005A92C;
    }
    // 0x8005A8E8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005A8EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005A8F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A8F4: lwc1        $f8, -0x2ABC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2ABC);
    // 0x8005A8F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005A8FC: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8005A900: nop

    // 0x8005A904: bc1t        L_8005A930
    if (c1cs) {
        // 0x8005A908: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A930;
    }
    // 0x8005A908: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A90C: lw          $t8, -0x2AC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AC0);
    // 0x8005A910: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8005A914: bne         $t8, $zero, L_8005A930
    if (ctx->r24 != 0) {
        // 0x8005A918: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A930;
    }
    // 0x8005A918: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8005A91C: lb          $t9, 0x4C($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X4C);
    // 0x8005A920: nop

    // 0x8005A924: andi        $t5, $t9, 0x40
    ctx->r13 = ctx->r25 & 0X40;
    // 0x8005A928: beq         $t5, $zero, L_8005A934
    if (ctx->r13 == 0) {
        // 0x8005A92C: addiu       $t6, $zero, 0x1E
        ctx->r14 = ADD32(0, 0X1E);
            goto L_8005A934;
    }
L_8005A92C:
    // 0x8005A92C: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
L_8005A930:
    // 0x8005A930: sb          $t6, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r14;
L_8005A934:
    // 0x8005A934: lb          $t8, 0x201($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X201);
    // 0x8005A938: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A93C: lwc1        $f2, 0x694C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X694C);
    // 0x8005A940: bne         $t8, $zero, L_8005AB34
    if (ctx->r24 != 0) {
        // 0x8005A944: addiu       $a0, $sp, 0x90
        ctx->r4 = ADD32(ctx->r29, 0X90);
            goto L_8005AB34;
    }
    // 0x8005A944: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8005A948: jal         0x8001BA74
    // 0x8005A94C: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    get_racer_objects(rdram, ctx);
        goto after_8;
    // 0x8005A94C: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x8005A950: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8005A954: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8005A958: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005A95C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005A960: blez        $t7, L_8005AAB8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005A964: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8005AAB8;
    }
    // 0x8005A964: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005A968: andi        $v1, $t7, 0x3
    ctx->r3 = ctx->r15 & 0X3;
    // 0x8005A96C: beq         $v1, $zero, L_8005A9D0
    if (ctx->r3 == 0) {
        // 0x8005A970: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_8005A9D0;
    }
    // 0x8005A970: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8005A974: sll         $t9, $zero, 2
    ctx->r25 = S32(0 << 2);
    // 0x8005A978: addu        $a2, $v0, $t9
    ctx->r6 = ADD32(ctx->r2, ctx->r25);
    // 0x8005A97C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005A980:
    // 0x8005A980: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8005A984: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8005A988: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8005A98C: nop

    // 0x8005A990: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x8005A994: nop

    // 0x8005A998: bne         $t5, $zero, L_8005A9A4
    if (ctx->r13 != 0) {
        // 0x8005A99C: nop
    
            goto L_8005A9A4;
    }
    // 0x8005A99C: nop

    // 0x8005A9A0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_8005A9A4:
    // 0x8005A9A4: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8005A9A8: nop

    // 0x8005A9AC: bne         $t3, $t6, L_8005A9B8
    if (ctx->r11 != ctx->r14) {
        // 0x8005A9B0: nop
    
            goto L_8005A9B8;
    }
    // 0x8005A9B0: nop

    // 0x8005A9B4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_8005A9B8:
    // 0x8005A9B8: bne         $t1, $t2, L_8005A980
    if (ctx->r9 != ctx->r10) {
        // 0x8005A9BC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8005A980;
    }
    // 0x8005A9BC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005A9C0: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x8005A9C4: nop

    // 0x8005A9C8: beq         $t2, $t8, L_8005AAB8
    if (ctx->r10 == ctx->r24) {
        // 0x8005A9CC: nop
    
            goto L_8005AAB8;
    }
    // 0x8005A9CC: nop

L_8005A9D0:
    // 0x8005A9D0: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8005A9D4: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8005A9D8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005A9DC: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8005A9E0: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8005A9E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005A9E8:
    // 0x8005A9E8: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8005A9EC: nop

    // 0x8005A9F0: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8005A9F4: nop

    // 0x8005A9F8: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8005A9FC: nop

    // 0x8005AA00: bne         $t6, $zero, L_8005AA0C
    if (ctx->r14 != 0) {
        // 0x8005AA04: nop
    
            goto L_8005AA0C;
    }
    // 0x8005AA04: nop

    // 0x8005AA08: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_8005AA0C:
    // 0x8005AA0C: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x8005AA10: nop

    // 0x8005AA14: bne         $t3, $t8, L_8005AA20
    if (ctx->r11 != ctx->r24) {
        // 0x8005AA18: nop
    
            goto L_8005AA20;
    }
    // 0x8005AA18: nop

    // 0x8005AA1C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_8005AA20:
    // 0x8005AA20: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    // 0x8005AA24: nop

    // 0x8005AA28: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8005AA2C: nop

    // 0x8005AA30: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8005AA34: nop

    // 0x8005AA38: bne         $a0, $zero, L_8005AA44
    if (ctx->r4 != 0) {
        // 0x8005AA3C: nop
    
            goto L_8005AA44;
    }
    // 0x8005AA3C: nop

    // 0x8005AA40: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8005AA44:
    // 0x8005AA44: bne         $t3, $a0, L_8005AA50
    if (ctx->r11 != ctx->r4) {
        // 0x8005AA48: nop
    
            goto L_8005AA50;
    }
    // 0x8005AA48: nop

    // 0x8005AA4C: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8005AA50:
    // 0x8005AA50: lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X8);
    // 0x8005AA54: nop

    // 0x8005AA58: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8005AA5C: nop

    // 0x8005AA60: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8005AA64: nop

    // 0x8005AA68: bne         $a0, $zero, L_8005AA74
    if (ctx->r4 != 0) {
        // 0x8005AA6C: nop
    
            goto L_8005AA74;
    }
    // 0x8005AA6C: nop

    // 0x8005AA70: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8005AA74:
    // 0x8005AA74: bne         $t3, $a0, L_8005AA80
    if (ctx->r11 != ctx->r4) {
        // 0x8005AA78: nop
    
            goto L_8005AA80;
    }
    // 0x8005AA78: nop

    // 0x8005AA7C: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8005AA80:
    // 0x8005AA80: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8005AA84: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8005AA88: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8005AA8C: nop

    // 0x8005AA90: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8005AA94: nop

    // 0x8005AA98: bne         $a0, $zero, L_8005AAA4
    if (ctx->r4 != 0) {
        // 0x8005AA9C: nop
    
            goto L_8005AAA4;
    }
    // 0x8005AA9C: nop

    // 0x8005AAA0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8005AAA4:
    // 0x8005AAA4: bne         $t3, $a0, L_8005AAB0
    if (ctx->r11 != ctx->r4) {
        // 0x8005AAA8: nop
    
            goto L_8005AAB0;
    }
    // 0x8005AAA8: nop

    // 0x8005AAAC: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8005AAB0:
    // 0x8005AAB0: bne         $a2, $t1, L_8005A9E8
    if (ctx->r6 != ctx->r9) {
        // 0x8005AAB4: nop
    
            goto L_8005A9E8;
    }
    // 0x8005AAB4: nop

L_8005AAB8:
    // 0x8005AAB8: beq         $a3, $zero, L_8005AAE8
    if (ctx->r7 == 0) {
        // 0x8005AABC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005AAE8;
    }
    // 0x8005AABC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AAC0: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AAC4: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005AAC8: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005AACC: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8005AAD0: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005AAD4: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8005AAD8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005AADC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005AAE0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005AAE4: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
L_8005AAE8:
    // 0x8005AAE8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AAEC: beq         $t0, $zero, L_8005AB34
    if (ctx->r8 == 0) {
        // 0x8005AAF0: nop
    
            goto L_8005AB34;
    }
    // 0x8005AAF0: nop

    // 0x8005AAF4: lwc1        $f5, 0x6950($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6950);
    // 0x8005AAF8: lwc1        $f4, 0x6954($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6954);
    // 0x8005AAFC: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x8005AB00: c.le.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d <= ctx->f18.d;
    // 0x8005AB04: nop

    // 0x8005AB08: bc1f        L_8005AB34
    if (!c1cs) {
        // 0x8005AB0C: nop
    
            goto L_8005AB34;
    }
    // 0x8005AB0C: nop

    // 0x8005AB10: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8005AB14: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005AB18: lwc1        $f10, 0x14($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8005AB1C: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8005AB20: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8005AB24: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005AB28: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005AB2C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005AB30: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
L_8005AB34:
    // 0x8005AB34: lh          $v0, 0x204($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X204);
    // 0x8005AB38: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AB3C: blez        $v0, L_8005AB68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005AB40: nop
    
            goto L_8005AB68;
    }
    // 0x8005AB40: nop

    // 0x8005AB44: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AB48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AB4C: subu        $t7, $v0, $a2
    ctx->r15 = SUB32(ctx->r2, ctx->r6);
    // 0x8005AB50: sh          $t7, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r15;
    // 0x8005AB54: lwc1        $f10, 0x6958($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6958);
    // 0x8005AB58: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005AB5C: nop

    // 0x8005AB60: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005AB64: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_8005AB68:
    // 0x8005AB68: lh          $v0, 0x206($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X206);
    // 0x8005AB6C: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AB70: blez        $v0, L_8005AB80
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005AB74: subu        $t9, $v0, $a2
        ctx->r25 = SUB32(ctx->r2, ctx->r6);
            goto L_8005AB80;
    }
    // 0x8005AB74: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x8005AB78: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
    // 0x8005AB7C: sh          $t9, 0x206($s0)
    MEM_H(0X206, ctx->r16) = ctx->r25;
L_8005AB80:
    // 0x8005AB80: lb          $v0, 0x201($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X201);
    // 0x8005AB84: nop

    // 0x8005AB88: bne         $v0, $zero, L_8005ABB8
    if (ctx->r2 != 0) {
        // 0x8005AB8C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005ABB8;
    }
    // 0x8005AB8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AB90: lwc1        $f7, 0x6960($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6960);
    // 0x8005AB94: lwc1        $f6, 0x6964($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6964);
    // 0x8005AB98: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005AB9C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005ABA0: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x8005ABA4: bc1f        L_8005ABB8
    if (!c1cs) {
        // 0x8005ABA8: nop
    
            goto L_8005ABB8;
    }
    // 0x8005ABA8: nop

    // 0x8005ABAC: sb          $t5, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r13;
    // 0x8005ABB0: lb          $v0, 0x201($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X201);
    // 0x8005ABB4: nop

L_8005ABB8:
    // 0x8005ABB8: beq         $v0, $zero, L_8005B41C
    if (ctx->r2 == 0) {
        // 0x8005ABBC: lw          $a3, 0xAC($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XAC);
            goto L_8005B41C;
    }
    // 0x8005ABBC: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
    // 0x8005ABC0: jal         0x80044170
    // 0x8005ABC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_AI_pathing_inputs(rdram, ctx);
        goto after_9;
    // 0x8005ABC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x8005ABC8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8005ABCC: lw          $t6, -0x2AD8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AD8);
    // 0x8005ABD0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8005ABD4: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x8005ABD8: addiu       $t4, $t4, -0x2A94
    ctx->r12 = ADD32(ctx->r12, -0X2A94);
    // 0x8005ABDC: bne         $t8, $zero, L_8005ABEC
    if (ctx->r24 != 0) {
        // 0x8005ABE0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8005ABEC;
    }
    // 0x8005ABE0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005ABE4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005ABE8: sb          $t7, 0x20C($s0)
    MEM_B(0X20C, ctx->r16) = ctx->r15;
L_8005ABEC:
    // 0x8005ABEC: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8005ABF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005ABF4: bne         $v0, $at, L_8005AC3C
    if (ctx->r2 != ctx->r1) {
        // 0x8005ABF8: nop
    
            goto L_8005AC3C;
    }
    // 0x8005ABF8: nop

    // 0x8005ABFC: lbu         $t9, 0x1FF($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005AC00: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005AC04: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8005AC08: bgez        $t9, L_8005AC1C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005AC0C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8005AC1C;
    }
    // 0x8005AC0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005AC10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005AC14: nop

    // 0x8005AC18: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8005AC1C:
    // 0x8005AC1C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8005AC20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005AC24: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8005AC28: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8005AC2C: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8005AC30: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x8005AC34: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8005AC38: nop

L_8005AC3C:
    // 0x8005AC3C: bne         $t3, $v0, L_8005ACB8
    if (ctx->r11 != ctx->r2) {
        // 0x8005AC40: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005ACB8;
    }
    // 0x8005AC40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005AC44: lbu         $t5, 0x1FF($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005AC48: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8005AC4C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8005AC50: bgez        $t5, L_8005AC68
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8005AC54: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8005AC68;
    }
    // 0x8005AC54: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005AC58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005AC5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005AC60: nop

    // 0x8005AC64: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8005AC68:
    // 0x8005AC68: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8005AC6C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8005AC70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005AC74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AC78: div.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8005AC7C: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8005AC80: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8005AC84: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x8005AC88: lh          $t6, 0x204($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X204);
    // 0x8005AC8C: nop

    // 0x8005AC90: blez        $t6, L_8005ACA8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005AC94: nop
    
            goto L_8005ACA8;
    }
    // 0x8005AC94: nop

    // 0x8005AC98: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8005AC9C: nop

    // 0x8005ACA0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005ACA4: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
L_8005ACA8:
    // 0x8005ACA8: sw          $t8, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r24;
    // 0x8005ACAC: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8005ACB0: nop

    // 0x8005ACB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8005ACB8:
    // 0x8005ACB8: bne         $v0, $at, L_8005AD78
    if (ctx->r2 != ctx->r1) {
        // 0x8005ACBC: nop
    
            goto L_8005AD78;
    }
    // 0x8005ACBC: nop

    // 0x8005ACC0: lbu         $t7, 0x1FF($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005ACC4: nop

    // 0x8005ACC8: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x8005ACCC: jal         0x800707C4
    // 0x8005ACD0: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    sins_f(rdram, ctx);
        goto after_10;
    // 0x8005ACD0: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_10:
    // 0x8005ACD4: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8005ACD8: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8005ACDC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005ACE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005ACE4: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8005ACE8: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8005ACEC: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005ACF0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005ACF4: lbu         $t6, 0x1FF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8005ACF8: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8005ACFC: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x8005AD00: cvt.d.s     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f12.d = CVT_D_S(ctx->f18.fl);
    // 0x8005AD04: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8005AD08: mul.d       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f14.d);
    // 0x8005AD0C: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8005AD10: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8005AD14: mul.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x8005AD18: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8005AD1C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8005AD20: swc1        $f18, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f18.u32l;
    // 0x8005AD24: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8005AD28: jal         0x800707F8
    // 0x8005AD2C: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    coss_f(rdram, ctx);
        goto after_11;
    // 0x8005AD2C: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    after_11:
    // 0x8005AD30: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8005AD34: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8005AD38: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005AD3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005AD40: lwc1        $f2, 0x88($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8005AD44: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8005AD48: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005AD4C: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005AD50: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005AD54: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8005AD58: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8005AD5C: mul.d       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f14.d);
    // 0x8005AD60: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8005AD64: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8005AD68: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8005AD6C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8005AD70: b           L_8005ADC8
    // 0x8005AD74: swc1        $f18, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f18.u32l;
        goto L_8005ADC8;
    // 0x8005AD74: swc1        $f18, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f18.u32l;
L_8005AD78:
    // 0x8005AD78: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8005AD7C: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8005AD80: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8005AD84: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005AD88: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005AD8C: mul.d       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f14.d);
    // 0x8005AD90: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005AD94: nop

    // 0x8005AD98: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x8005AD9C: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8005ADA0: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x8005ADA4: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x8005ADA8: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8005ADAC: sub.d       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f0.d - ctx->f6.d;
    // 0x8005ADB0: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x8005ADB4: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8005ADB8: swc1        $f10, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f10.u32l;
    // 0x8005ADBC: sub.d       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f2.d - ctx->f6.d;
    // 0x8005ADC0: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8005ADC4: swc1        $f10, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f10.u32l;
L_8005ADC8:
    // 0x8005ADC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005ADCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005ADD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005ADD4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8005ADD8: jal         0x8001E29C
    // 0x8005ADDC: swc1        $f8, -0x2A90($at)
    MEM_W(-0X2A90, ctx->r1) = ctx->f8.u32l;
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8005ADDC: swc1        $f8, -0x2A90($at)
    MEM_W(-0X2A90, ctx->r1) = ctx->f8.u32l;
    after_12:
    // 0x8005ADE0: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8005ADE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005ADE8: sw          $v0, -0x2A9C($at)
    MEM_W(-0X2A9C, ctx->r1) = ctx->r2;
    // 0x8005ADEC: lw          $t5, 0x40($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X40);
    // 0x8005ADF0: nop

    // 0x8005ADF4: lbu         $a0, 0x5D($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X5D);
    // 0x8005ADF8: jal         0x8001E29C
    // 0x8005ADFC: nop

    get_misc_asset(rdram, ctx);
        goto after_13;
    // 0x8005ADFC: nop

    after_13:
    // 0x8005AE00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AE04: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AE08: sw          $v0, -0x2A98($at)
    MEM_W(-0X2A98, ctx->r1) = ctx->r2;
    // 0x8005AE0C: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8005AE10: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005AE14: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005AE18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005AE1C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005AE20: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8005AE24: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005AE28: bc1f        L_8005AE68
    if (!c1cs) {
        // 0x8005AE2C: nop
    
            goto L_8005AE68;
    }
    // 0x8005AE2C: nop

    // 0x8005AE30: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005AE34: nop

    // 0x8005AE38: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8005AE3C: beq         $at, $zero, L_8005AE64
    if (ctx->r1 == 0) {
        // 0x8005AE40: nop
    
            goto L_8005AE64;
    }
    // 0x8005AE40: nop

    // 0x8005AE44: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8005AE48: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8005AE4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005AE50: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8005AE54: c.eq.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d == ctx->f4.d;
    // 0x8005AE58: nop

    // 0x8005AE5C: bc1t        L_8005AE68
    if (c1cs) {
        // 0x8005AE60: nop
    
            goto L_8005AE68;
    }
    // 0x8005AE60: nop

L_8005AE64:
    // 0x8005AE64: sb          $zero, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = 0;
L_8005AE68:
    // 0x8005AE68: lb          $t7, 0x175($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X175);
    // 0x8005AE6C: nop

    // 0x8005AE70: beq         $t7, $zero, L_8005AE8C
    if (ctx->r15 == 0) {
        // 0x8005AE74: nop
    
            goto L_8005AE8C;
    }
    // 0x8005AE74: nop

    // 0x8005AE78: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AE7C: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AE80: jal         0x80056E2C
    // 0x8005AE84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_activate_magnet(rdram, ctx);
        goto after_14;
    // 0x8005AE84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x8005AE88: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005AE8C:
    // 0x8005AE8C: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x8005AE90: nop

    // 0x8005AE94: beq         $t3, $t9, L_8005AEB8
    if (ctx->r11 == ctx->r25) {
        // 0x8005AE98: lw          $t5, 0xA0($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA0);
            goto L_8005AEB8;
    }
    // 0x8005AE98: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AE9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005AEA0: sb          $zero, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = 0;
    // 0x8005AEA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AEA8: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
    // 0x8005AEAC: b           L_8005AED8
    // 0x8005AEB0: sb          $zero, -0x2A52($at)
    MEM_B(-0X2A52, ctx->r1) = 0;
        goto L_8005AED8;
    // 0x8005AEB0: sb          $zero, -0x2A52($at)
    MEM_B(-0X2A52, ctx->r1) = 0;
    // 0x8005AEB4: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
L_8005AEB8:
    // 0x8005AEB8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8005AEBC: lh          $a0, 0x2E($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X2E);
    // 0x8005AEC0: lw          $a1, 0xC($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC);
    // 0x8005AEC4: lw          $a2, 0x14($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X14);
    // 0x8005AEC8: jal         0x8002B0F4
    // 0x8005AECC: addiu       $a3, $a3, -0x2A50
    ctx->r7 = ADD32(ctx->r7, -0X2A50);
    get_level_segment_waves(rdram, ctx);
        goto after_15;
    // 0x8005AECC: addiu       $a3, $a3, -0x2A50
    ctx->r7 = ADD32(ctx->r7, -0X2A50);
    after_15:
    // 0x8005AED0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AED4: sb          $v0, -0x2A52($at)
    MEM_B(-0X2A52, ctx->r1) = ctx->r2;
L_8005AED8:
    // 0x8005AED8: jal         0x8002ACC8
    // 0x8005AEDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_collision_mode(rdram, ctx);
        goto after_16;
    // 0x8005AEDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8005AEE0: lw          $t6, 0x148($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X148);
    // 0x8005AEE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005AEE8: bne         $t6, $zero, L_8005AF10
    if (ctx->r14 != 0) {
        // 0x8005AEEC: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8005AF10;
    }
    // 0x8005AEEC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005AEF0: addiu       $t0, $t0, -0x2AC0
    ctx->r8 = ADD32(ctx->r8, -0X2AC0);
    // 0x8005AEF4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8005AEF8: nop

    // 0x8005AEFC: bne         $t8, $zero, L_8005AF10
    if (ctx->r24 != 0) {
        // 0x8005AF00: nop
    
            goto L_8005AF10;
    }
    // 0x8005AF00: nop

    // 0x8005AF04: lh          $t7, 0x204($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X204);
    // 0x8005AF08: nop

    // 0x8005AF0C: blez        $t7, L_8005AF48
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005AF10: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005AF48;
    }
L_8005AF10:
    // 0x8005AF10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF14: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
    // 0x8005AF18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF1C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005AF20: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
    // 0x8005AF24: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005AF28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005AF2C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8005AF30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005AF34: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005AF38: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005AF3C: sw          $zero, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = 0;
    // 0x8005AF40: addiu       $t0, $t0, -0x2AC0
    ctx->r8 = ADD32(ctx->r8, -0X2AC0);
    // 0x8005AF44: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8005AF48:
    // 0x8005AF48: lbu         $t9, 0x1D6($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1D6);
    // 0x8005AF4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005AF50: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005AF54: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x8005AF58: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005AF5C: beq         $at, $zero, L_8005B1B0
    if (ctx->r1 == 0) {
        // 0x8005AF60: addiu       $v0, $v0, -0x2AD4
        ctx->r2 = ADD32(ctx->r2, -0X2AD4);
            goto L_8005B1B0;
    }
    // 0x8005AF60: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005AF64: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005AF68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005AF6C: addu        $at, $at, $t9
    gpr jr_addend_8005AF78 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8005AF70: lw          $t9, 0x6968($at)
    ctx->r25 = ADD32(ctx->r1, 0X6968);
    // 0x8005AF74: nop

    // 0x8005AF78: jr          $t9
    // 0x8005AF7C: nop

    switch (jr_addend_8005AF78 >> 2) {
        case 0: goto L_8005AF80; break;
        case 1: goto L_8005AFD8; break;
        case 2: goto L_8005B004; break;
        case 3: goto L_8005B030; break;
        case 4: goto L_8005AFAC; break;
        case 5: goto L_8005B05C; break;
        case 6: goto L_8005B094; break;
        case 7: goto L_8005B0CC; break;
        case 8: goto L_8005B0CC; break;
        case 9: goto L_8005B1B0; break;
        case 10: goto L_8005B030; break;
        case 11: goto L_8005B10C; break;
        case 12: goto L_8005B144; break;
        case 13: goto L_8005B17C; break;
        default: switch_error(__func__, 0x8005AF78, 0x800E6968);
    }
    // 0x8005AF7C: nop

L_8005AF80:
    // 0x8005AF80: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AF84: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005AF88: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AF8C: jal         0x8004F7F4
    // 0x8005AF90: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004F7F4(rdram, ctx);
        goto after_17;
    // 0x8005AF90: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_17:
    // 0x8005AF94: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005AF98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005AF9C: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005AFA0: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005AFA4: b           L_8005B1B0
    // 0x8005AFA8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B1B0;
    // 0x8005AFA8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005AFAC:
    // 0x8005AFAC: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AFB0: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005AFB4: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AFB8: jal         0x8004CC20
    // 0x8005AFBC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004CC20(rdram, ctx);
        goto after_18;
    // 0x8005AFBC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_18:
    // 0x8005AFC0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005AFC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005AFC8: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005AFCC: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005AFD0: b           L_8005B1B0
    // 0x8005AFD4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B1B0;
    // 0x8005AFD4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005AFD8:
    // 0x8005AFD8: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005AFDC: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005AFE0: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005AFE4: jal         0x80046524
    // 0x8005AFE8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80046524(rdram, ctx);
        goto after_19;
    // 0x8005AFE8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_19:
    // 0x8005AFEC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005AFF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005AFF4: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005AFF8: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005AFFC: b           L_8005B1B0
    // 0x8005B000: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B1B0;
    // 0x8005B000: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B004:
    // 0x8005B004: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B008: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B00C: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B010: jal         0x80049794
    // 0x8005B014: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_20;
    // 0x8005B014: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_20:
    // 0x8005B018: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B01C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B020: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005B024: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005B028: b           L_8005B1B0
    // 0x8005B02C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B1B0;
    // 0x8005B02C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B030:
    // 0x8005B030: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B034: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B038: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B03C: jal         0x8004D95C
    // 0x8005B040: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_carpet(rdram, ctx);
        goto after_21;
    // 0x8005B040: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_21:
    // 0x8005B044: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B048: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B04C: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005B050: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005B054: b           L_8005B1B0
    // 0x8005B058: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B1B0;
    // 0x8005B058: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B05C:
    // 0x8005B05C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B060: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B064: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B068: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B06C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B070: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B074: jal         0x8005C364
    // 0x8005B078: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_tricky(rdram, ctx);
        goto after_22;
    // 0x8005B078: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_22:
    // 0x8005B07C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B080: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B084: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005B088: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005B08C: b           L_8005B1B0
    // 0x8005B090: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B1B0;
    // 0x8005B090: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B094:
    // 0x8005B094: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B098: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B09C: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B0A0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B0A4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B0A8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B0AC: jal         0x8005D0D0
    // 0x8005B0B0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_bluey(rdram, ctx);
        goto after_23;
    // 0x8005B0B0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_23:
    // 0x8005B0B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B0B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B0BC: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005B0C0: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005B0C4: b           L_8005B1B0
    // 0x8005B0C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B1B0;
    // 0x8005B0C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B0CC:
    // 0x8005B0CC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8005B0D0: addiu       $t5, $t5, -0x2ACC
    ctx->r13 = ADD32(ctx->r13, -0X2ACC);
    // 0x8005B0D4: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B0D8: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B0DC: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B0E0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005B0E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B0E8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B0EC: jal         0x8005D820
    // 0x8005B0F0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_smokey(rdram, ctx);
        goto after_24;
    // 0x8005B0F0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_24:
    // 0x8005B0F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B0F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B0FC: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005B100: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005B104: b           L_8005B1B0
    // 0x8005B108: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B1B0;
    // 0x8005B108: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B10C:
    // 0x8005B10C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B110: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B114: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B118: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B11C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B120: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B124: jal         0x8005E4C0
    // 0x8005B128: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_bubbler(rdram, ctx);
        goto after_25;
    // 0x8005B128: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_25:
    // 0x8005B12C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B130: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B134: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005B138: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005B13C: b           L_8005B1B0
    // 0x8005B140: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B1B0;
    // 0x8005B140: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B144:
    // 0x8005B144: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B148: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B14C: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B150: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B154: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B158: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B15C: jal         0x8005EA90
    // 0x8005B160: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_wizpig(rdram, ctx);
        goto after_26;
    // 0x8005B160: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_26:
    // 0x8005B164: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B168: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B16C: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005B170: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005B174: b           L_8005B1B0
    // 0x8005B178: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8005B1B0;
    // 0x8005B178: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B17C:
    // 0x8005B17C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B180: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x8005B184: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B188: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005B18C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8005B190: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8005B194: jal         0x8005F310
    // 0x8005B198: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    update_rocket(rdram, ctx);
        goto after_27;
    // 0x8005B198: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_27:
    // 0x8005B19C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005B1A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005B1A4: addiu       $v0, $v0, -0x2AD4
    ctx->r2 = ADD32(ctx->r2, -0X2AD4);
    // 0x8005B1A8: addiu       $v1, $v1, -0x2AD8
    ctx->r3 = ADD32(ctx->r3, -0X2AD8);
    // 0x8005B1AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8005B1B0:
    // 0x8005B1B0: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x8005B1B4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B1B8: beq         $t6, $t3, L_8005B1D4
    if (ctx->r14 == ctx->r11) {
        // 0x8005B1BC: nop
    
            goto L_8005B1D4;
    }
    // 0x8005B1BC: nop

    // 0x8005B1C0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005B1C4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x8005B1C8: lw          $a3, 0xA8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B1CC: jal         0x800050D0
    // 0x8005B1D0: nop

    racer_sound_update(rdram, ctx);
        goto after_28;
    // 0x8005B1D0: nop

    after_28:
L_8005B1D4:
    // 0x8005B1D4: lwc1        $f18, 0xA8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8005B1D8: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8005B1DC: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x8005B1E0: lb          $t8, 0x192($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X192);
    // 0x8005B1E4: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B1E8: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x8005B1EC: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005B1F0: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8005B1F4: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x8005B1F8: addiu       $t7, $s0, 0xA8
    ctx->r15 = ADD32(ctx->r16, 0XA8);
    // 0x8005B1FC: addiu       $t9, $s0, 0x1C8
    ctx->r25 = ADD32(ctx->r16, 0X1C8);
    // 0x8005B200: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8005B204: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8005B208: jal         0x800185E4
    // 0x8005B20C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    checkpoint_is_passed(rdram, ctx);
        goto after_29;
    // 0x8005B20C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_29:
    // 0x8005B210: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x8005B214: bne         $v0, $at, L_8005B230
    if (ctx->r2 != ctx->r1) {
        // 0x8005B218: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_8005B230;
    }
    // 0x8005B218: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8005B21C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005B220: jal         0x8005C270
    // 0x8005B224: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    racer_update_progress(rdram, ctx);
        goto after_30;
    // 0x8005B224: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    after_30:
    // 0x8005B228: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x8005B22C: nop

L_8005B230:
    // 0x8005B230: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005B234: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8005B238: jal         0x8001BA1C
    // 0x8005B23C: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    find_next_checkpoint_node(rdram, ctx);
        goto after_31;
    // 0x8005B23C: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    after_31:
    // 0x8005B240: lb          $t5, 0x1CA($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B244: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x8005B248: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005B24C: lb          $t8, 0x36($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X36);
    // 0x8005B250: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005B254: bne         $t8, $at, L_8005B274
    if (ctx->r24 != ctx->r1) {
        // 0x8005B258: nop
    
            goto L_8005B274;
    }
    // 0x8005B258: nop

    // 0x8005B25C: lb          $t9, 0x1E5($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E5);
    // 0x8005B260: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8005B264: beq         $t9, $zero, L_8005B274
    if (ctx->r25 == 0) {
        // 0x8005B268: sb          $t7, 0x201($s0)
        MEM_B(0X201, ctx->r16) = ctx->r15;
            goto L_8005B274;
    }
    // 0x8005B268: sb          $t7, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r15;
    // 0x8005B26C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005B270: sb          $t5, 0x1C8($s0)
    MEM_B(0X1C8, ctx->r16) = ctx->r13;
L_8005B274:
    // 0x8005B274: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B278: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8005B27C: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x8005B280: lb          $v1, 0x36($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X36);
    // 0x8005B284: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8005B288: bne         $v1, $at, L_8005B2B0
    if (ctx->r3 != ctx->r1) {
        // 0x8005B28C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005B2B0;
    }
    // 0x8005B28C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005B290: lb          $t9, 0x4B($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X4B);
    // 0x8005B294: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B298: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8005B29C: sb          $t5, 0x193($s0)
    MEM_B(0X193, ctx->r16) = ctx->r13;
    // 0x8005B2A0: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x8005B2A4: lb          $v1, 0x36($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X36);
    // 0x8005B2A8: nop

    // 0x8005B2AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8005B2B0:
    // 0x8005B2B0: bne         $v1, $at, L_8005B2F4
    if (ctx->r3 != ctx->r1) {
        // 0x8005B2B4: nop
    
            goto L_8005B2F4;
    }
    // 0x8005B2B4: nop

    // 0x8005B2B8: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005B2BC: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8005B2C0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005B2C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B2C8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B2CC: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005B2D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B2D4: bc1f        L_8005B2F4
    if (!c1cs) {
        // 0x8005B2D8: nop
    
            goto L_8005B2F4;
    }
    // 0x8005B2D8: nop

    // 0x8005B2DC: lwc1        $f7, 0x69A0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X69A0);
    // 0x8005B2E0: lwc1        $f6, 0x69A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X69A4);
    // 0x8005B2E4: nop

    // 0x8005B2E8: mul.d       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8005B2EC: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8005B2F0: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8005B2F4:
    // 0x8005B2F4: bne         $t2, $zero, L_8005B3A8
    if (ctx->r10 != 0) {
        // 0x8005B2F8: nop
    
            goto L_8005B3A8;
    }
    // 0x8005B2F8: nop

    // 0x8005B2FC: lb          $t7, 0x1CA($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005B300: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005B304: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8005B308: lb          $t5, 0x36($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X36);
    // 0x8005B30C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005B310: bne         $t5, $at, L_8005B31C
    if (ctx->r13 != ctx->r1) {
        // 0x8005B314: nop
    
            goto L_8005B31C;
    }
    // 0x8005B314: nop

    // 0x8005B318: sb          $t6, 0x1C8($s0)
    MEM_B(0X1C8, ctx->r16) = ctx->r14;
L_8005B31C:
    // 0x8005B31C: jal         0x8001BA64
    // 0x8005B320: nop

    get_checkpoint_count(rdram, ctx);
        goto after_32;
    // 0x8005B320: nop

    after_32:
    // 0x8005B324: lb          $t8, 0x192($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X192);
    // 0x8005B328: nop

    // 0x8005B32C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8005B330: sb          $t7, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r15;
    // 0x8005B334: lb          $t9, 0x192($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X192);
    // 0x8005B338: nop

    // 0x8005B33C: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005B340: bne         $at, $zero, L_8005B374
    if (ctx->r1 != 0) {
        // 0x8005B344: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_8005B374;
    }
    // 0x8005B344: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8005B348: lh          $t5, 0x190($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X190);
    // 0x8005B34C: sb          $zero, 0x192($s0)
    MEM_B(0X192, ctx->r16) = 0;
    // 0x8005B350: blez        $t5, L_8005B374
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005B354: lw          $t8, 0x70($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X70);
            goto L_8005B374;
    }
    // 0x8005B354: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8005B358: lb          $v1, 0x193($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X193);
    // 0x8005B35C: nop

    // 0x8005B360: slti        $at, $v1, 0x78
    ctx->r1 = SIGNED(ctx->r3) < 0X78 ? 1 : 0;
    // 0x8005B364: beq         $at, $zero, L_8005B370
    if (ctx->r1 == 0) {
        // 0x8005B368: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8005B370;
    }
    // 0x8005B368: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8005B36C: sb          $t6, 0x193($s0)
    MEM_B(0X193, ctx->r16) = ctx->r14;
L_8005B370:
    // 0x8005B370: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
L_8005B374:
    // 0x8005B374: lh          $v1, 0x190($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X190);
    // 0x8005B378: lb          $t7, 0x4B($t8)
    ctx->r15 = MEM_B(ctx->r24, 0X4B);
    // 0x8005B37C: addiu       $t8, $zero, 0x2710
    ctx->r24 = ADD32(0, 0X2710);
    // 0x8005B380: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x8005B384: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B388: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8005B38C: mflo        $t5
    ctx->r13 = lo;
    // 0x8005B390: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005B394: beq         $at, $zero, L_8005B3A0
    if (ctx->r1 == 0) {
        // 0x8005B398: nop
    
            goto L_8005B3A0;
    }
    // 0x8005B398: nop

    // 0x8005B39C: sh          $t6, 0x190($s0)
    MEM_H(0X190, ctx->r16) = ctx->r14;
L_8005B3A0:
    // 0x8005B3A0: b           L_8005B3DC
    // 0x8005B3A4: sh          $t8, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r24;
        goto L_8005B3DC;
    // 0x8005B3A4: sh          $t8, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r24;
L_8005B3A8:
    // 0x8005B3A8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8005B3AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005B3B0: bne         $t7, $at, L_8005B3D8
    if (ctx->r15 != ctx->r1) {
        // 0x8005B3B4: nop
    
            goto L_8005B3D8;
    }
    // 0x8005B3B4: nop

    // 0x8005B3B8: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8005B3BC: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8005B3C0: nop

    // 0x8005B3C4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8005B3C8: nop

    // 0x8005B3CC: bc1f        L_8005B3D8
    if (!c1cs) {
        // 0x8005B3D0: nop
    
            goto L_8005B3D8;
    }
    // 0x8005B3D0: nop

    // 0x8005B3D4: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
L_8005B3D8:
    // 0x8005B3D8: sh          $t2, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r10;
L_8005B3DC:
    // 0x8005B3DC: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B3E0: nop

    // 0x8005B3E4: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8005B3E8: nop

    // 0x8005B3EC: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    // 0x8005B3F0: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B3F4: nop

    // 0x8005B3F8: lwc1        $f6, 0x10($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X10);
    // 0x8005B3FC: nop

    // 0x8005B400: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x8005B404: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B408: nop

    // 0x8005B40C: lwc1        $f18, 0x14($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8005B410: b           L_8005B450
    // 0x8005B414: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
        goto L_8005B450;
    // 0x8005B414: swc1        $f18, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f18.u32l;
    // 0x8005B418: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
L_8005B41C:
    // 0x8005B41C: jal         0x8005B818
    // 0x8005B420: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005B818(rdram, ctx);
        goto after_33;
    // 0x8005B420: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_33:
    // 0x8005B424: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8005B428: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005B42C: beq         $t8, $t3, L_8005B450
    if (ctx->r24 == ctx->r11) {
        // 0x8005B430: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8005B450;
    }
    // 0x8005B430: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005B434: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8005B438: lw          $a2, -0x2AD8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2AD8);
    // 0x8005B43C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B440: lw          $a1, -0x2AD4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2AD4);
    // 0x8005B444: lw          $a3, 0xA8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B448: jal         0x800050D0
    // 0x8005B44C: nop

    racer_sound_update(rdram, ctx);
        goto after_34;
    // 0x8005B44C: nop

    after_34:
L_8005B450:
    // 0x8005B450: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005B454: lb          $t7, 0x175($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X175);
    // 0x8005B458: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x8005B45C: bne         $t7, $zero, L_8005B490
    if (ctx->r15 != 0) {
        // 0x8005B460: lw          $t9, 0xA8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA8);
            goto L_8005B490;
    }
    // 0x8005B460: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B464: lw          $a0, 0x178($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X178);
    // 0x8005B468: nop

    // 0x8005B46C: beq         $a0, $zero, L_8005B490
    if (ctx->r4 == 0) {
        // 0x8005B470: lw          $t9, 0xA8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA8);
            goto L_8005B490;
    }
    // 0x8005B470: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B474: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x8005B478: jal         0x8000488C
    // 0x8005B47C: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    sndp_stop(rdram, ctx);
        goto after_35;
    // 0x8005B47C: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_35:
    // 0x8005B480: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005B484: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005B488: sw          $zero, 0x178($s0)
    MEM_W(0X178, ctx->r16) = 0;
    // 0x8005B48C: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
L_8005B490:
    // 0x8005B490: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B494: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8005B498: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x8005B49C: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x8005B4A0: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x8005B4A4: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x8005B4A8: jal         0x80018CE0
    // 0x8005B4AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80018CE0(rdram, ctx);
        goto after_36;
    // 0x8005B4AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_36:
    // 0x8005B4B0: lb          $a2, 0x188($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X188);
    // 0x8005B4B4: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005B4B8: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005B4BC: blez        $a2, L_8005B4E4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8005B4C0: nop
    
            goto L_8005B4E4;
    }
    // 0x8005B4C0: nop

    // 0x8005B4C4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B4C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005B4CC: swc1        $f13, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x8005B4D0: jal         0x800576E0
    // 0x8005B4D4: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    drop_bananas(rdram, ctx);
        goto after_37;
    // 0x8005B4D4: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_37:
    // 0x8005B4D8: lwc1        $f13, 0x40($sp)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8005B4DC: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005B4E0: nop

L_8005B4E4:
    // 0x8005B4E4: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005B4E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005B4EC: beq         $t5, $zero, L_8005B504
    if (ctx->r13 == 0) {
        // 0x8005B4F0: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8005B504;
    }
    // 0x8005B4F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005B4F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005B4F8: sw          $zero, 0x148($s0)
    MEM_W(0X148, ctx->r16) = 0;
    // 0x8005B4FC: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8005B500: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_8005B504:
    // 0x8005B504: lwc1        $f14, 0x90($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8005B508: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8005B50C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005B510: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8005B514: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B518: bc1f        L_8005B530
    if (!c1cs) {
        // 0x8005B51C: sub.s       $f10, $f14, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
            goto L_8005B530;
    }
    // 0x8005B51C: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8005B520: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B524: lwc1        $f2, 0x69A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X69A8);
    // 0x8005B528: b           L_8005B53C
    // 0x8005B52C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
        goto L_8005B53C;
    // 0x8005B52C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8005B530:
    // 0x8005B530: lwc1        $f2, 0x69AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X69AC);
    // 0x8005B534: nop

    // 0x8005B538: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8005B53C:
    // 0x8005B53C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005B540: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B544: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005B548: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8005B54C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005B550: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8005B554: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x8005B558: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8005B55C: add.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f6.d + ctx->f4.d;
    // 0x8005B560: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8005B564: bc1f        L_8005B584
    if (!c1cs) {
        // 0x8005B568: swc1        $f8, 0x8C($s0)
        MEM_W(0X8C, ctx->r16) = ctx->f8.u32l;
            goto L_8005B584;
    }
    // 0x8005B568: swc1        $f8, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f8.u32l;
    // 0x8005B56C: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8005B570: nop

    // 0x8005B574: c.le.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl <= ctx->f14.fl;
    // 0x8005B578: nop

    // 0x8005B57C: bc1t        L_8005B5AC
    if (c1cs) {
        // 0x8005B580: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005B5AC;
    }
    // 0x8005B580: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8005B584:
    // 0x8005B584: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8005B588: nop

    // 0x8005B58C: bc1f        L_8005B5B8
    if (!c1cs) {
        // 0x8005B590: nop
    
            goto L_8005B5B8;
    }
    // 0x8005B590: nop

    // 0x8005B594: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8005B598: nop

    // 0x8005B59C: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
    // 0x8005B5A0: nop

    // 0x8005B5A4: bc1f        L_8005B5B8
    if (!c1cs) {
        // 0x8005B5A8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005B5B8;
    }
    // 0x8005B5A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8005B5AC:
    // 0x8005B5AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005B5B0: swc1        $f14, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f14.u32l;
    // 0x8005B5B4: swc1        $f4, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f4.u32l;
L_8005B5B8:
    // 0x8005B5B8: lh          $v1, 0x16A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X16A);
    // 0x8005B5BC: lh          $t6, 0x16C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16C);
    // 0x8005B5C0: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B5C4: subu        $t8, $t6, $v1
    ctx->r24 = SUB32(ctx->r14, ctx->r3);
    // 0x8005B5C8: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B5CC: mflo        $t2
    ctx->r10 = lo;
    // 0x8005B5D0: sra         $t9, $t2, 3
    ctx->r25 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8005B5D4: slti        $at, $t9, 0x801
    ctx->r1 = SIGNED(ctx->r25) < 0X801 ? 1 : 0;
    // 0x8005B5D8: bne         $at, $zero, L_8005B5E4
    if (ctx->r1 != 0) {
        // 0x8005B5DC: or          $t2, $t9, $zero
        ctx->r10 = ctx->r25 | 0;
            goto L_8005B5E4;
    }
    // 0x8005B5DC: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x8005B5E0: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
L_8005B5E4:
    // 0x8005B5E4: slti        $at, $t2, -0x800
    ctx->r1 = SIGNED(ctx->r10) < -0X800 ? 1 : 0;
    // 0x8005B5E8: beq         $at, $zero, L_8005B5F4
    if (ctx->r1 == 0) {
        // 0x8005B5EC: nop
    
            goto L_8005B5F4;
    }
    // 0x8005B5EC: nop

    // 0x8005B5F0: addiu       $t2, $zero, -0x800
    ctx->r10 = ADD32(0, -0X800);
L_8005B5F4:
    // 0x8005B5F4: lh          $v0, -0x34AC($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X34AC);
    // 0x8005B5F8: addu        $t6, $v1, $t2
    ctx->r14 = ADD32(ctx->r3, ctx->r10);
    // 0x8005B5FC: beq         $v0, $zero, L_8005B60C
    if (ctx->r2 == 0) {
        // 0x8005B600: addu        $t5, $v1, $v0
        ctx->r13 = ADD32(ctx->r3, ctx->r2);
            goto L_8005B60C;
    }
    // 0x8005B600: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x8005B604: b           L_8005B610
    // 0x8005B608: sh          $t5, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r13;
        goto L_8005B610;
    // 0x8005B608: sh          $t5, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r13;
L_8005B60C:
    // 0x8005B60C: sh          $t6, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r14;
L_8005B610:
    // 0x8005B610: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B614: nop

    // 0x8005B618: blez        $v0, L_8005B6E0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005B61C: slti        $at, $v0, 0x3D
        ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
            goto L_8005B6E0;
    }
    // 0x8005B61C: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8005B620: bne         $at, $zero, L_8005B69C
    if (ctx->r1 != 0) {
        // 0x8005B624: nop
    
            goto L_8005B69C;
    }
    // 0x8005B624: nop

    // 0x8005B628: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8005B62C: nop

    // 0x8005B630: beq         $a0, $zero, L_8005B660
    if (ctx->r4 == 0) {
        // 0x8005B634: nop
    
            goto L_8005B660;
    }
    // 0x8005B634: nop

    // 0x8005B638: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B63C: nop

    // 0x8005B640: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8005B644: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x8005B648: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    // 0x8005B64C: jal         0x800096D8
    // 0x8005B650: nop

    audspat_point_set_position(rdram, ctx);
        goto after_38;
    // 0x8005B650: nop

    after_38:
    // 0x8005B654: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B658: b           L_8005B6C0
    // 0x8005B65C: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
        goto L_8005B6C0;
    // 0x8005B65C: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_8005B660:
    // 0x8005B660: lw          $t8, 0x118($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X118);
    // 0x8005B664: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B668: beq         $t8, $zero, L_8005B6BC
    if (ctx->r24 == 0) {
        // 0x8005B66C: addiu       $a0, $zero, 0x9F
        ctx->r4 = ADD32(0, 0X9F);
            goto L_8005B6BC;
    }
    // 0x8005B66C: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    // 0x8005B670: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    // 0x8005B674: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x8005B678: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x8005B67C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005B680: addiu       $t5, $s0, 0x17C
    ctx->r13 = ADD32(ctx->r16, 0X17C);
    // 0x8005B684: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005B688: jal         0x80009558
    // 0x8005B68C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_39;
    // 0x8005B68C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_39:
    // 0x8005B690: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B694: b           L_8005B6C0
    // 0x8005B698: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
        goto L_8005B6C0;
    // 0x8005B698: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_8005B69C:
    // 0x8005B69C: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8005B6A0: nop

    // 0x8005B6A4: beq         $a0, $zero, L_8005B6C0
    if (ctx->r4 == 0) {
        // 0x8005B6A8: lw          $t6, 0xA8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA8);
            goto L_8005B6C0;
    }
    // 0x8005B6A8: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005B6AC: jal         0x800096F8
    // 0x8005B6B0: nop

    audspat_point_stop(rdram, ctx);
        goto after_40;
    // 0x8005B6B0: nop

    after_40:
    // 0x8005B6B4: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B6B8: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_8005B6BC:
    // 0x8005B6BC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
L_8005B6C0:
    // 0x8005B6C0: nop

    // 0x8005B6C4: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x8005B6C8: sh          $t8, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r24;
    // 0x8005B6CC: lh          $t7, 0x18E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18E);
    // 0x8005B6D0: nop

    // 0x8005B6D4: bgtz        $t7, L_8005B6E0
    if (SIGNED(ctx->r15) > 0) {
        // 0x8005B6D8: nop
    
            goto L_8005B6E0;
    }
    // 0x8005B6D8: nop

    // 0x8005B6DC: sb          $zero, 0x189($s0)
    MEM_B(0X189, ctx->r16) = 0;
L_8005B6E0:
    // 0x8005B6E0: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8005B6E4: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B6E8: beq         $a0, $zero, L_8005B704
    if (ctx->r4 == 0) {
        // 0x8005B6EC: nop
    
            goto L_8005B704;
    }
    // 0x8005B6EC: nop

    // 0x8005B6F0: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8005B6F4: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x8005B6F8: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    // 0x8005B6FC: jal         0x800096D8
    // 0x8005B700: nop

    audspat_point_set_position(rdram, ctx);
        goto after_41;
    // 0x8005B700: nop

    after_41:
L_8005B704:
    // 0x8005B704: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005B708: sb          $zero, -0x2A7C($at)
    MEM_B(-0X2A7C, ctx->r1) = 0;
    // 0x8005B70C: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8005B710: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005B714: beq         $v0, $zero, L_8005B7F8
    if (ctx->r2 == 0) {
        // 0x8005B718: nop
    
            goto L_8005B7F8;
    }
    // 0x8005B718: nop

    // 0x8005B71C: lw          $t9, -0x2AC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AC0);
    // 0x8005B720: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B724: bne         $t9, $zero, L_8005B7F8
    if (ctx->r25 != 0) {
        // 0x8005B728: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005B7F8;
    }
    // 0x8005B728: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005B72C: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8005B730: jal         0x8001E29C
    // 0x8005B734: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    get_misc_asset(rdram, ctx);
        goto after_42;
    // 0x8005B734: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    after_42:
    // 0x8005B738: lb          $t6, 0x3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3);
    // 0x8005B73C: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x8005B740: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x8005B744: lb          $t7, 0x0($t8)
    ctx->r15 = MEM_B(ctx->r24, 0X0);
    // 0x8005B748: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005B74C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8005B750: lw          $t9, 0x150($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X150);
    // 0x8005B754: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005B758: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B75C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8005B760: swc1        $f4, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f4.u32l;
    // 0x8005B764: lw          $t5, 0x150($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X150);
    // 0x8005B768: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8005B76C: nop

    // 0x8005B770: swc1        $f18, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f18.u32l;
    // 0x8005B774: lwc1        $f10, 0x69B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X69B0);
    // 0x8005B778: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8005B77C: lw          $t6, 0x150($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X150);
    // 0x8005B780: div.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005B784: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B788: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x8005B78C: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8005B790: lwc1        $f8, 0x69BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69BC);
    // 0x8005B794: lwc1        $f9, 0x69B8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69B8);
    // 0x8005B798: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8005B79C: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x8005B7A0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005B7A4: bc1f        L_8005B7C4
    if (!c1cs) {
        // 0x8005B7A8: nop
    
            goto L_8005B7C4;
    }
    // 0x8005B7A8: nop

    // 0x8005B7AC: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8005B7B0: nop

    // 0x8005B7B4: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x8005B7B8: nop

    // 0x8005B7BC: ori         $t7, $t8, 0x4000
    ctx->r15 = ctx->r24 | 0X4000;
    // 0x8005B7C0: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
L_8005B7C4:
    // 0x8005B7C4: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8005B7C8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005B7CC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005B7D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B7D4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8005B7D8: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8005B7DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005B7E0: bc1f        L_8005B7F4
    if (!c1cs) {
        // 0x8005B7E4: nop
    
            goto L_8005B7F4;
    }
    // 0x8005B7E4: nop

    // 0x8005B7E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005B7EC: nop

    // 0x8005B7F0: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
L_8005B7F4:
    // 0x8005B7F4: sw          $zero, 0x150($s0)
    MEM_W(0X150, ctx->r16) = 0;
L_8005B7F8:
    // 0x8005B7F8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8005B7FC: sb          $t9, 0x1FE($s0)
    MEM_B(0X1FE, ctx->r16) = ctx->r25;
    // 0x8005B800: jal         0x8004F77C
    // 0x8005B804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_racer_tail_lights(rdram, ctx);
        goto after_43;
    // 0x8005B804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x8005B808: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005B80C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005B810: jr          $ra
    // 0x8005B814: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8005B814: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void set_option_text_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D118: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D11C: bne         $a0, $zero, L_8009D180
    if (ctx->r4 != 0) {
        // 0x8009D120: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8009D180;
    }
    // 0x8009D120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D124: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x8009D128: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009D12C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009D130: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009D134: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D13C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009D140: jal         0x800C5000
    // 0x8009D144: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    set_current_text_colour(rdram, ctx);
        goto after_0;
    // 0x8009D144: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_0:
    // 0x8009D148: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D14C: lb          $t8, -0xB14($t8)
    ctx->r24 = MEM_B(ctx->r24, -0XB14);
    // 0x8009D150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D154: beq         $t8, $zero, L_8009D1A4
    if (ctx->r24 == 0) {
        // 0x8009D158: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009D1A4;
    }
    // 0x8009D158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D15C: addiu       $t9, $zero, 0x5A
    ctx->r25 = ADD32(0, 0X5A);
    // 0x8009D160: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x8009D164: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009D168: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009D16C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009D170: jal         0x800C5000
    // 0x8009D174: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    set_current_text_colour(rdram, ctx);
        goto after_1;
    // 0x8009D174: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_1:
    // 0x8009D178: b           L_8009D1A8
    // 0x8009D17C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D1A8;
    // 0x8009D17C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D180:
    // 0x8009D180: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x8009D184: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009D188: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009D18C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009D190: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D194: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    // 0x8009D198: addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // 0x8009D19C: jal         0x800C5000
    // 0x8009D1A0: addiu       $a3, $zero, 0xCF
    ctx->r7 = ADD32(0, 0XCF);
    set_current_text_colour(rdram, ctx);
        goto after_2;
    // 0x8009D1A0: addiu       $a3, $zero, 0xCF
    ctx->r7 = ADD32(0, 0XCF);
    after_2:
L_8009D1A4:
    // 0x8009D1A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D1A8:
    // 0x8009D1A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D1AC: sb          $zero, -0xB14($at)
    MEM_B(-0XB14, ctx->r1) = 0;
    // 0x8009D1B0: jr          $ra
    // 0x8009D1B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009D1B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80075000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075000: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80075004: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80075008: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8007500C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80075010: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80075014: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80075018: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8007501C: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80075020: jal         0x800758DC
    // 0x80075024: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075024: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    after_0:
    // 0x80075028: beq         $v0, $zero, L_80075044
    if (ctx->r2 == 0) {
        // 0x8007502C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80075044;
    }
    // 0x8007502C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80075030: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075034: jal         0x80075AEC
    // 0x80075038: nop

    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80075038: nop

    after_1:
    // 0x8007503C: b           L_800753C0
    // 0x80075040: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800753C0;
    // 0x80075040: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80075044:
    // 0x80075044: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075048: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007504C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80075050: addiu       $s1, $zero, 0x1100
    ctx->r17 = ADD32(0, 0X1100);
    // 0x80075054: addiu       $a2, $a2, 0x778C
    ctx->r6 = ADD32(ctx->r6, 0X778C);
    // 0x80075058: addiu       $a1, $a1, 0x777C
    ctx->r5 = ADD32(ctx->r5, 0X777C);
    // 0x8007505C: jal         0x800764E8
    // 0x80075060: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x80075060: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x80075064: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80075068: bne         $v0, $at, L_800750B0
    if (ctx->r2 != ctx->r1) {
        // 0x8007506C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800750B0;
    }
    // 0x8007506C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80075070: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075074: jal         0x80075AEC
    // 0x80075078: nop

    start_reading_controller_data(rdram, ctx);
        goto after_3;
    // 0x80075078: nop

    after_3:
    // 0x8007507C: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
    // 0x80075080: lh          $t7, 0x8E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8E);
    // 0x80075084: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80075088: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8007508C: lh          $a1, 0x7E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X7E);
    // 0x80075090: lh          $a2, 0x82($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X82);
    // 0x80075094: lh          $a3, 0x86($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X86);
    // 0x80075098: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8007509C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800750A0: jal         0x80074EB8
    // 0x800750A4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80074EB8(rdram, ctx);
        goto after_4;
    // 0x800750A4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_4:
    // 0x800750A8: b           L_800753C4
    // 0x800750AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800753C4;
    // 0x800750AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800750B0:
    // 0x800750B0: beq         $v0, $zero, L_800750D0
    if (ctx->r2 == 0) {
        // 0x800750B4: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_800750D0;
    }
    // 0x800750B4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800750B8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800750BC: jal         0x80075AEC
    // 0x800750C0: nop

    start_reading_controller_data(rdram, ctx);
        goto after_5;
    // 0x800750C0: nop

    after_5:
    // 0x800750C4: b           L_800753C0
    // 0x800750C8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800753C0;
    // 0x800750C8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800750CC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_800750D0:
    // 0x800750D0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800750D4: jal         0x80076924
    // 0x800750D8: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    get_file_size(rdram, ctx);
        goto after_6;
    // 0x800750D8: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_6:
    // 0x800750DC: beq         $v0, $zero, L_800750F8
    if (ctx->r2 == 0) {
        // 0x800750E0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800750F8;
    }
    // 0x800750E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800750E4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800750E8: jal         0x80075AEC
    // 0x800750EC: nop

    start_reading_controller_data(rdram, ctx);
        goto after_7;
    // 0x800750EC: nop

    after_7:
    // 0x800750F0: b           L_800753C0
    // 0x800750F4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800753C0;
    // 0x800750F4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800750F8:
    // 0x800750F8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800750FC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075100: jal         0x80070C9C
    // 0x80075104: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x80075104: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_8:
    // 0x80075108: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8007510C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80075110: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80075114: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80075118: jal         0x80076610
    // 0x8007511C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_9;
    // 0x8007511C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_9:
    // 0x80075120: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80075124: jal         0x80075AEC
    // 0x80075128: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_10;
    // 0x80075128: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_10:
    // 0x8007512C: beq         $s0, $zero, L_80075144
    if (ctx->r16 == 0) {
        // 0x80075130: lui         $at, 0x4748
        ctx->r1 = S32(0X4748 << 16);
            goto L_80075144;
    }
    // 0x80075130: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x80075134: jal         0x80071140
    // 0x80075138: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_11;
    // 0x80075138: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x8007513C: b           L_800753C0
    // 0x80075140: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800753C0;
    // 0x80075140: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80075144:
    // 0x80075144: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80075148: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x8007514C: bne         $t9, $at, L_800753B4
    if (ctx->r25 != ctx->r1) {
        // 0x80075150: addiu       $s0, $zero, 0x9
        ctx->r16 = ADD32(0, 0X9);
            goto L_800753B4;
    }
    // 0x80075150: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
    // 0x80075154: addiu       $a2, $s2, 0x4
    ctx->r6 = ADD32(ctx->r18, 0X4);
    // 0x80075158: lh          $t3, 0x82($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X82);
    // 0x8007515C: lh          $t2, 0x7E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X7E);
    // 0x80075160: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80075164: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80075168: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_8007516C:
    // 0x8007516C: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x80075170: nop

    // 0x80075174: bne         $t2, $t4, L_80075194
    if (ctx->r10 != ctx->r12) {
        // 0x80075178: nop
    
            goto L_80075194;
    }
    // 0x80075178: nop

    // 0x8007517C: lbu         $t5, 0x1($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1);
    // 0x80075180: nop

    // 0x80075184: bne         $t3, $t5, L_80075194
    if (ctx->r11 != ctx->r13) {
        // 0x80075188: nop
    
            goto L_80075194;
    }
    // 0x80075188: nop

    // 0x8007518C: b           L_800751A4
    // 0x80075190: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
        goto L_800751A4;
    // 0x80075190: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_80075194:
    // 0x80075194: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80075198: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x8007519C: bne         $at, $zero, L_8007516C
    if (ctx->r1 != 0) {
        // 0x800751A0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8007516C;
    }
    // 0x800751A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800751A4:
    // 0x800751A4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800751A8: beq         $t1, $a0, L_800751D8
    if (ctx->r9 == ctx->r4) {
        // 0x800751AC: sll         $t6, $t1, 2
        ctx->r14 = S32(ctx->r9 << 2);
            goto L_800751D8;
    }
    // 0x800751AC: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x800751B0: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x800751B4: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800751B8: lh          $t9, 0x8A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8A);
    // 0x800751BC: addu        $v1, $t8, $s2
    ctx->r3 = ADD32(ctx->r24, ctx->r18);
    // 0x800751C0: lh          $v1, 0x4($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4);
    // 0x800751C4: nop

    // 0x800751C8: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800751CC: beq         $at, $zero, L_800751D8
    if (ctx->r1 == 0) {
        // 0x800751D0: nop
    
            goto L_800751D8;
    }
    // 0x800751D0: nop

    // 0x800751D4: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
L_800751D8:
    // 0x800751D8: bne         $t1, $a0, L_80075214
    if (ctx->r9 != ctx->r4) {
        // 0x800751DC: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80075214;
    }
    // 0x800751DC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800751E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800751E4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800751E8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x800751EC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800751F0:
    // 0x800751F0: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x800751F4: nop

    // 0x800751F8: bne         $v0, $t4, L_80075208
    if (ctx->r2 != ctx->r12) {
        // 0x800751FC: nop
    
            goto L_80075208;
    }
    // 0x800751FC: nop

    // 0x80075200: b           L_80075214
    // 0x80075204: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
        goto L_80075214;
    // 0x80075204: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_80075208:
    // 0x80075208: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007520C: bne         $v1, $a3, L_800751F0
    if (ctx->r3 != ctx->r7) {
        // 0x80075210: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800751F0;
    }
    // 0x80075210: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80075214:
    // 0x80075214: bne         $t1, $at, L_80075224
    if (ctx->r9 != ctx->r1) {
        // 0x80075218: nop
    
            goto L_80075224;
    }
    // 0x80075218: nop

    // 0x8007521C: b           L_800753B4
    // 0x80075220: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800753B4;
    // 0x80075220: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80075224:
    // 0x80075224: bne         $t1, $a0, L_80075234
    if (ctx->r9 != ctx->r4) {
        // 0x80075228: sll         $t0, $t1, 2
        ctx->r8 = S32(ctx->r9 << 2);
            goto L_80075234;
    }
    // 0x80075228: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8007522C: b           L_800753B4
    // 0x80075230: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_800753B4;
    // 0x80075230: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_80075234:
    // 0x80075234: addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // 0x80075238: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x8007523C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80075240: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80075244: subu        $t6, $s1, $t5
    ctx->r14 = SUB32(ctx->r17, ctx->r13);
    // 0x80075248: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007524C: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80075250: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80075254: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80075258: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8007525C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80075260: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075264: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80075268: jal         0x80070C9C
    // 0x8007526C: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_12;
    // 0x8007526C: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_12:
    // 0x80075270: lui         $t9, 0x4748
    ctx->r25 = S32(0X4748 << 16);
    // 0x80075274: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80075278: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8007527C: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x80075280: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80075284: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80075288: ori         $t9, $t9, 0x5353
    ctx->r25 = ctx->r25 | 0X5353;
    // 0x8007528C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80075290: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    // 0x80075294: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x80075298: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8007529C: sb          $t5, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r13;
    // 0x800752A0: lh          $t6, 0x1A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A);
    // 0x800752A4: nop

    // 0x800752A8: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800752AC: sh          $t7, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r15;
    // 0x800752B0: lw          $s1, 0x70($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X70);
    // 0x800752B4: nop

L_800752B8:
    // 0x800752B8: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x800752BC: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800752C0: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800752C4: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x800752C8: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800752CC: bne         $at, $zero, L_800752E0
    if (ctx->r1 != 0) {
        // 0x800752D0: sb          $t9, 0x1($s1)
        MEM_B(0X1, ctx->r17) = ctx->r25;
            goto L_800752E0;
    }
    // 0x800752D0: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x800752D4: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x800752D8: b           L_800752F0
    // 0x800752DC: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
        goto L_800752F0;
    // 0x800752DC: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
L_800752E0:
    // 0x800752E0: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x800752E4: nop

    // 0x800752E8: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x800752EC: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
L_800752F0:
    // 0x800752F0: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x800752F4: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x800752F8: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x800752FC: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80075300: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80075304: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x80075308: addu        $a0, $v0, $s2
    ctx->r4 = ADD32(ctx->r2, ctx->r18);
    // 0x8007530C: subu        $a2, $t9, $v0
    ctx->r6 = SUB32(ctx->r25, ctx->r2);
    // 0x80075310: jal         0x800C9DA0
    // 0x80075314: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    _bcopy(rdram, ctx);
        goto after_13;
    // 0x80075314: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_13:
    // 0x80075318: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8007531C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80075320: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80075324: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80075328: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8007532C: bne         $v1, $a3, L_800752B8
    if (ctx->r3 != ctx->r7) {
        // 0x80075330: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800752B8;
    }
    // 0x80075330: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80075334: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80075338: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8007533C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80075340: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x80075344: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x80075348: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x8007534C: lh          $a1, 0x86($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X86);
    // 0x80075350: lh          $a2, 0x8A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X8A);
    // 0x80075354: lh          $a3, 0x8E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X8E);
    // 0x80075358: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8007535C: jal         0x80074AA8
    // 0x80075360: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80074AA8(rdram, ctx);
        goto after_14;
    // 0x80075360: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_14:
    // 0x80075364: lh          $t9, 0x7E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X7E);
    // 0x80075368: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007536C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x80075370: lh          $t4, 0x82($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X82);
    // 0x80075374: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80075378: sb          $t4, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r12;
    // 0x8007537C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80075380: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80075384: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80075388: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8007538C: addiu       $a3, $a3, 0x77A0
    ctx->r7 = ADD32(ctx->r7, 0X77A0);
    // 0x80075390: addiu       $a2, $a2, 0x7790
    ctx->r6 = ADD32(ctx->r6, 0X7790);
    // 0x80075394: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80075398: jal         0x800766D4
    // 0x8007539C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    write_controller_pak_file(rdram, ctx);
        goto after_15;
    // 0x8007539C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_15:
    // 0x800753A0: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800753A4: jal         0x80071140
    // 0x800753A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    mempool_free(rdram, ctx);
        goto after_16;
    // 0x800753A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_16:
    // 0x800753AC: b           L_800753B4
    // 0x800753B0: nop

        goto L_800753B4;
    // 0x800753B0: nop

L_800753B4:
    // 0x800753B4: jal         0x80071140
    // 0x800753B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_17;
    // 0x800753B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x800753BC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800753C0:
    // 0x800753C0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800753C4:
    // 0x800753C4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800753C8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800753CC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800753D0: jr          $ra
    // 0x800753D4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800753D4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8002FF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FF6C: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x8002FF70: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002FF74: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002FF78: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002FF7C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002FF80: or          $ra, $a2, $zero
    ctx->r31 = ctx->r6 | 0;
    // 0x8002FF84: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002FF88: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002FF8C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002FF90: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002FF94: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002FF98: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002FF9C: swc1        $f29, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002FFA0: swc1        $f28, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f28.u32l;
    // 0x8002FFA4: swc1        $f27, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002FFA8: swc1        $f26, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f26.u32l;
    // 0x8002FFAC: swc1        $f25, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002FFB0: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x8002FFB4: swc1        $f23, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002FFB8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8002FFBC: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002FFC0: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x8002FFC4: sw          $a3, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r7;
    // 0x8002FFC8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8002FFCC: addiu       $s0, $sp, 0xE0
    ctx->r16 = ADD32(ctx->r29, 0XE0);
    // 0x8002FFD0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002FFD4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8002FFD8: blez        $a2, L_80030358
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002FFDC: sw          $a1, 0x164($sp)
        MEM_W(0X164, ctx->r29) = ctx->r5;
            goto L_80030358;
    }
    // 0x8002FFDC: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x8002FFE0: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8002FFE4: bne         $at, $zero, L_80030358
    if (ctx->r1 != 0) {
        // 0x8002FFE8: sw          $a1, 0x164($sp)
        MEM_W(0X164, ctx->r29) = ctx->r5;
            goto L_80030358;
    }
    // 0x8002FFE8: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x8002FFEC: sll         $t7, $zero, 3
    ctx->r15 = S32(0 << 3);
    // 0x8002FFF0: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8002FFF4: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002FFF8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002FFFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80030000: addiu       $s1, $s1, -0x4CD0
    ctx->r17 = ADD32(ctx->r17, -0X4CD0);
    // 0x80030004: addiu       $s4, $s4, -0x4CE0
    ctx->r20 = ADD32(ctx->r20, -0X4CE0);
    // 0x80030008: addiu       $s6, $s6, -0x2F44
    ctx->r22 = ADD32(ctx->r22, -0X2F44);
    // 0x8003000C: addu        $s7, $a3, $t7
    ctx->r23 = ADD32(ctx->r7, ctx->r15);
    // 0x80030010: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x80030014: addiu       $s5, $zero, 0x1F
    ctx->r21 = ADD32(0, 0X1F);
    // 0x80030018: addiu       $fp, $t5, 0x1
    ctx->r30 = ADD32(ctx->r13, 0X1);
L_8003001C:
    // 0x8003001C: slt         $at, $fp, $ra
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80030020: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x80030024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030028: bne         $at, $zero, L_80030034
    if (ctx->r1 != 0) {
        // 0x8003002C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80030034;
    }
    // 0x8003002C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80030030: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80030034:
    // 0x80030034: lw          $t8, 0x16C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X16C);
    // 0x80030038: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8003003C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80030040: lwc1        $f20, 0x0($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80030044: lwc1        $f22, 0x0($s7)
    ctx->f22.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80030048: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8003004C: lwc1        $f18, 0x4($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X4);
    // 0x80030050: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x80030054: sub.s       $f14, $f20, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80030058: or          $t1, $s3, $zero
    ctx->r9 = ctx->r19 | 0;
    // 0x8003005C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80030060: bc1f        L_80030080
    if (!c1cs) {
        // 0x80030064: sub.s       $f12, $f16, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
            goto L_80030080;
    }
    // 0x80030064: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80030068: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8003006C: nop

    // 0x80030070: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x80030074: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80030078: b           L_80030094
    // 0x8003007C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80030094;
    // 0x8003007C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80030080:
    // 0x80030080: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80030084: nop

    // 0x80030088: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x8003008C: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80030090: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80030094:
    // 0x80030094: blez        $s2, L_8003032C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80030098: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_8003032C;
    }
L_80030098:
    // 0x80030098: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8003009C: slt         $at, $t4, $s2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800300A0: bne         $at, $zero, L_800300AC
    if (ctx->r1 != 0) {
        // 0x800300A4: or          $v1, $t4, $zero
        ctx->r3 = ctx->r12 | 0;
            goto L_800300AC;
    }
    // 0x800300A4: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x800300A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800300AC:
    // 0x800300AC: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800300B0: lwc1        $f20, 0x0($t1)
    ctx->f20.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800300B4: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800300B8: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x800300BC: addu        $a3, $s3, $t6
    ctx->r7 = ADD32(ctx->r19, ctx->r14);
    // 0x800300C0: lwc1        $f24, 0x8($a3)
    ctx->f24.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800300C4: mul.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800300C8: lwc1        $f26, 0x0($a3)
    ctx->f26.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800300CC: mul.s       $f10, $f24, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f14.fl);
    // 0x800300D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800300D4: mul.s       $f4, $f12, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f26.fl);
    // 0x800300D8: add.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800300DC: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x800300E0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800300E4: bc1f        L_800300FC
    if (!c1cs) {
        // 0x800300E8: add.s       $f22, $f6, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f2.fl;
            goto L_800300FC;
    }
    // 0x800300E8: add.s       $f22, $f6, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800300EC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x800300F0: nop

    // 0x800300F4: bc1t        L_8003011C
    if (c1cs) {
        // 0x800300F8: sll         $t7, $t5, 2
        ctx->r15 = S32(ctx->r13 << 2);
            goto L_8003011C;
    }
    // 0x800300F8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
L_800300FC:
    // 0x800300FC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80030100: nop

    // 0x80030104: bc1f        L_800302F0
    if (!c1cs) {
        // 0x80030108: nop
    
            goto L_800302F0;
    }
    // 0x80030108: nop

    // 0x8003010C: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x80030110: nop

    // 0x80030114: bc1f        L_800302F0
    if (!c1cs) {
        // 0x80030118: sll         $t7, $t5, 2
        ctx->r15 = S32(ctx->r13 << 2);
            goto L_800302F0;
    }
    // 0x80030118: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
L_8003011C:
    // 0x8003011C: addu        $t0, $s4, $t7
    ctx->r8 = ADD32(ctx->r20, ctx->r15);
    // 0x80030120: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80030124: sll         $t3, $t5, 5
    ctx->r11 = S32(ctx->r13 << 5);
    // 0x80030128: sll         $t8, $t2, 4
    ctx->r24 = S32(ctx->r10 << 4);
    // 0x8003012C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80030130: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80030134: blez        $a0, L_8003021C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80030138: addu        $a2, $s0, $t8
        ctx->r6 = ADD32(ctx->r16, ctx->r24);
            goto L_8003021C;
    }
    // 0x80030138: addu        $a2, $s0, $t8
    ctx->r6 = ADD32(ctx->r16, ctx->r24);
    // 0x8003013C: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x80030140: addu        $v0, $s1, $t9
    ctx->r2 = ADD32(ctx->r17, ctx->r25);
L_80030144:
    // 0x80030144: lwc1        $f28, 0x10($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80030148: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8003014C: c.eq.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl == ctx->f20.fl;
    // 0x80030150: nop

    // 0x80030154: bc1f        L_800301AC
    if (!c1cs) {
        // 0x80030158: nop
    
            goto L_800301AC;
    }
    // 0x80030158: nop

    // 0x8003015C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80030160: nop

    // 0x80030164: c.eq.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl == ctx->f18.fl;
    // 0x80030168: nop

    // 0x8003016C: bc1f        L_800301AC
    if (!c1cs) {
        // 0x80030170: nop
    
            goto L_800301AC;
    }
    // 0x80030170: nop

    // 0x80030174: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80030178: nop

    // 0x8003017C: c.eq.s      $f10, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f10.fl == ctx->f26.fl;
    // 0x80030180: nop

    // 0x80030184: bc1f        L_800301AC
    if (!c1cs) {
        // 0x80030188: nop
    
            goto L_800301AC;
    }
    // 0x80030188: nop

    // 0x8003018C: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80030190: nop

    // 0x80030194: c.eq.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl == ctx->f24.fl;
    // 0x80030198: nop

    // 0x8003019C: bc1f        L_800301AC
    if (!c1cs) {
        // 0x800301A0: nop
    
            goto L_800301AC;
    }
    // 0x800301A0: nop

    // 0x800301A4: b           L_80030208
    // 0x800301A8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_80030208;
    // 0x800301A8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_800301AC:
    // 0x800301AC: c.eq.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl == ctx->f26.fl;
    // 0x800301B0: nop

    // 0x800301B4: bc1f        L_80030208
    if (!c1cs) {
        // 0x800301B8: nop
    
            goto L_80030208;
    }
    // 0x800301B8: nop

    // 0x800301BC: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800301C0: nop

    // 0x800301C4: c.eq.s      $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f6.fl == ctx->f24.fl;
    // 0x800301C8: nop

    // 0x800301CC: bc1f        L_80030208
    if (!c1cs) {
        // 0x800301D0: nop
    
            goto L_80030208;
    }
    // 0x800301D0: nop

    // 0x800301D4: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800301D8: nop

    // 0x800301DC: c.eq.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl == ctx->f20.fl;
    // 0x800301E0: nop

    // 0x800301E4: bc1f        L_80030208
    if (!c1cs) {
        // 0x800301E8: nop
    
            goto L_80030208;
    }
    // 0x800301E8: nop

    // 0x800301EC: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800301F0: nop

    // 0x800301F4: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x800301F8: nop

    // 0x800301FC: bc1f        L_80030208
    if (!c1cs) {
        // 0x80030200: nop
    
            goto L_80030208;
    }
    // 0x80030200: nop

    // 0x80030204: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80030208:
    // 0x80030208: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003020C: blez        $a0, L_8003021C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80030210: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_8003021C;
    }
    // 0x80030210: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80030214: bltz        $a1, L_80030144
    if (SIGNED(ctx->r5) < 0) {
        // 0x80030218: nop
    
            goto L_80030144;
    }
    // 0x80030218: nop

L_8003021C:
    // 0x8003021C: bltz        $a1, L_80030244
    if (SIGNED(ctx->r5) < 0) {
        // 0x80030220: sll         $t6, $a1, 5
        ctx->r14 = S32(ctx->r5 << 5);
            goto L_80030244;
    }
    // 0x80030220: sll         $t6, $a1, 5
    ctx->r14 = S32(ctx->r5 << 5);
    // 0x80030224: sh          $a1, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r5;
    // 0x80030228: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x8003022C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80030230: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80030234: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80030238: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003023C: b           L_800302F0
    // 0x80030240: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
        goto L_800302F0;
    // 0x80030240: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
L_80030244:
    // 0x80030244: sub.s       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x80030248: nop

    // 0x8003024C: div.s       $f24, $f16, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80030250: sub.s       $f10, $f26, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x80030254: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80030258: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8003025C: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x80030260: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80030264: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80030268: nop

    // 0x8003026C: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80030270: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80030274: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80030278: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8003027C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80030280: nop

    // 0x80030284: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x80030288: bne         $at, $zero, L_8003029C
    if (ctx->r1 != 0) {
        // 0x8003028C: addu        $v1, $a0, $t3
        ctx->r3 = ADD32(ctx->r4, ctx->r11);
            goto L_8003029C;
    }
    // 0x8003028C: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
    // 0x80030290: sw          $s5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r21;
    // 0x80030294: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80030298: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
L_8003029C:
    // 0x8003029C: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800302A0: sll         $t7, $v1, 5
    ctx->r15 = S32(ctx->r3 << 5);
    // 0x800302A4: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x800302A8: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x800302AC: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800302B0: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800302B4: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x800302B8: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800302BC: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800302C0: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x800302C4: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800302C8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800302CC: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x800302D0: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800302D4: nop

    // 0x800302D8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800302DC: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800302E0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800302E4: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x800302E8: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x800302EC: sh          $v1, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r3;
L_800302F0:
    // 0x800302F0: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800302F4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800302F8: bc1f        L_80030324
    if (!c1cs) {
        // 0x800302FC: sll         $t6, $t2, 4
        ctx->r14 = S32(ctx->r10 << 4);
            goto L_80030324;
    }
    // 0x800302FC: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x80030300: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
    // 0x80030304: addu        $a2, $s0, $t6
    ctx->r6 = ADD32(ctx->r16, ctx->r14);
    // 0x80030308: sh          $t7, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r15;
    // 0x8003030C: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80030310: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80030314: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80030318: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8003031C: nop

    // 0x80030320: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
L_80030324:
    // 0x80030324: bne         $t4, $s2, L_80030098
    if (ctx->r12 != ctx->r18) {
        // 0x80030328: addiu       $t1, $t1, 0x10
        ctx->r9 = ADD32(ctx->r9, 0X10);
            goto L_80030098;
    }
    // 0x80030328: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
L_8003032C:
    // 0x8003032C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80030330: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x80030334: slt         $at, $fp, $ra
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80030338: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8003033C: or          $t5, $fp, $zero
    ctx->r13 = ctx->r30 | 0;
    // 0x80030340: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
    // 0x80030344: beq         $at, $zero, L_80030358
    if (ctx->r1 == 0) {
        // 0x80030348: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80030358;
    }
    // 0x80030348: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003034C: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x80030350: beq         $at, $zero, L_8003001C
    if (ctx->r1 == 0) {
        // 0x80030354: addiu       $fp, $t5, 0x1
        ctx->r30 = ADD32(ctx->r13, 0X1);
            goto L_8003001C;
    }
    // 0x80030354: addiu       $fp, $t5, 0x1
    ctx->r30 = ADD32(ctx->r13, 0X1);
L_80030358:
    // 0x80030358: lw          $a1, 0x164($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X164);
    // 0x8003035C: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x80030360: bne         $at, $zero, L_80030468
    if (ctx->r1 != 0) {
        // 0x80030364: nop
    
            goto L_80030468;
    }
    // 0x80030364: nop

    // 0x80030368: beq         $s3, $a1, L_80030470
    if (ctx->r19 == ctx->r5) {
        // 0x8003036C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80030470;
    }
    // 0x8003036C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80030370: blez        $s2, L_8003046C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80030374: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003046C;
    }
    // 0x80030374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030378: andi        $a3, $s2, 0x3
    ctx->r7 = ctx->r18 & 0X3;
    // 0x8003037C: beq         $a3, $zero, L_800303BC
    if (ctx->r7 == 0) {
        // 0x80030380: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_800303BC;
    }
    // 0x80030380: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80030384: sll         $v1, $zero, 4
    ctx->r3 = S32(0 << 4);
    // 0x80030388: addu        $t1, $s3, $v1
    ctx->r9 = ADD32(ctx->r19, ctx->r3);
    // 0x8003038C: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_80030390:
    // 0x80030390: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80030394: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80030398: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8003039C: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800303A0: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x800303A4: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800303A8: lh          $t8, -0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, -0X2);
    // 0x800303AC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800303B0: bne         $a2, $v0, L_80030390
    if (ctx->r6 != ctx->r2) {
        // 0x800303B4: sh          $t8, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r24;
            goto L_80030390;
    }
    // 0x800303B4: sh          $t8, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r24;
    // 0x800303B8: beq         $v0, $s2, L_8003046C
    if (ctx->r2 == ctx->r18) {
        // 0x800303BC: sll         $v1, $v0, 4
        ctx->r3 = S32(ctx->r2 << 4);
            goto L_8003046C;
    }
L_800303BC:
    // 0x800303BC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800303C0: sll         $t9, $s2, 4
    ctx->r25 = S32(ctx->r18 << 4);
    // 0x800303C4: addu        $a2, $t9, $a1
    ctx->r6 = ADD32(ctx->r25, ctx->r5);
    // 0x800303C8: addu        $t1, $s3, $v1
    ctx->r9 = ADD32(ctx->r19, ctx->r3);
    // 0x800303CC: addu        $a0, $a1, $v1
    ctx->r4 = ADD32(ctx->r5, ctx->r3);
L_800303D0:
    // 0x800303D0: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800303D4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x800303D8: swc1        $f4, -0x40($a0)
    MEM_W(-0X40, ctx->r4) = ctx->f4.u32l;
    // 0x800303DC: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800303E0: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
    // 0x800303E4: swc1        $f6, -0x38($a0)
    MEM_W(-0X38, ctx->r4) = ctx->f6.u32l;
    // 0x800303E8: lh          $t6, -0x32($t1)
    ctx->r14 = MEM_H(ctx->r9, -0X32);
    // 0x800303EC: nop

    // 0x800303F0: sh          $t6, -0x32($a0)
    MEM_H(-0X32, ctx->r4) = ctx->r14;
    // 0x800303F4: lwc1        $f8, -0x30($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, -0X30);
    // 0x800303F8: nop

    // 0x800303FC: swc1        $f8, -0x30($a0)
    MEM_W(-0X30, ctx->r4) = ctx->f8.u32l;
    // 0x80030400: lwc1        $f10, -0x28($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, -0X28);
    // 0x80030404: nop

    // 0x80030408: swc1        $f10, -0x28($a0)
    MEM_W(-0X28, ctx->r4) = ctx->f10.u32l;
    // 0x8003040C: lh          $t7, -0x22($t1)
    ctx->r15 = MEM_H(ctx->r9, -0X22);
    // 0x80030410: nop

    // 0x80030414: sh          $t7, -0x22($a0)
    MEM_H(-0X22, ctx->r4) = ctx->r15;
    // 0x80030418: lwc1        $f4, -0x20($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, -0X20);
    // 0x8003041C: nop

    // 0x80030420: swc1        $f4, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = ctx->f4.u32l;
    // 0x80030424: lwc1        $f6, -0x18($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, -0X18);
    // 0x80030428: nop

    // 0x8003042C: swc1        $f6, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = ctx->f6.u32l;
    // 0x80030430: lh          $t8, -0x12($t1)
    ctx->r24 = MEM_H(ctx->r9, -0X12);
    // 0x80030434: nop

    // 0x80030438: sh          $t8, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = ctx->r24;
    // 0x8003043C: lwc1        $f8, -0x10($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, -0X10);
    // 0x80030440: nop

    // 0x80030444: swc1        $f8, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80030448: lwc1        $f10, -0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, -0X8);
    // 0x8003044C: nop

    // 0x80030450: swc1        $f10, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80030454: lh          $t9, -0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, -0X2);
    // 0x80030458: bne         $a0, $a2, L_800303D0
    if (ctx->r4 != ctx->r6) {
        // 0x8003045C: sh          $t9, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r25;
            goto L_800303D0;
    }
    // 0x8003045C: sh          $t9, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r25;
    // 0x80030460: b           L_80030470
    // 0x80030464: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80030470;
    // 0x80030464: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80030468:
    // 0x80030468: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8003046C:
    // 0x8003046C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80030470:
    // 0x80030470: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80030474: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80030478: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x8003047C: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80030480: lwc1        $f23, 0x10($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80030484: lwc1        $f22, 0x14($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80030488: lwc1        $f25, 0x18($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8003048C: lwc1        $f24, 0x1C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80030490: lwc1        $f27, 0x20($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80030494: lwc1        $f26, 0x24($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80030498: lwc1        $f29, 0x28($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8003049C: lwc1        $f28, 0x2C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800304A0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800304A4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800304A8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800304AC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800304B0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800304B4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800304B8: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800304BC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800304C0: jr          $ra
    // 0x800304C4: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x800304C4: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void func_8001F3EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F3EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001F3F0: lh          $v0, -0x5188($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5188);
    // 0x8001F3F4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001F3F8: bne         $v0, $zero, L_8001F408
    if (ctx->r2 != 0) {
        // 0x8001F3FC: nop
    
            goto L_8001F408;
    }
    // 0x8001F3FC: nop

    // 0x8001F400: jr          $ra
    // 0x8001F404: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8001F404: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001F408:
    // 0x8001F408: blez        $v0, L_8001F444
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F40C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001F444;
    }
    // 0x8001F40C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001F410: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001F414: lw          $a2, -0x518C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X518C);
    // 0x8001F418: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F41C: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
L_8001F420:
    // 0x8001F420: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8001F424: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001F428: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x8001F42C: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001F430: bne         $a1, $t7, L_8001F43C
    if (ctx->r5 != ctx->r15) {
        // 0x8001F434: nop
    
            goto L_8001F43C;
    }
    // 0x8001F434: nop

    // 0x8001F438: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001F43C:
    // 0x8001F43C: bne         $at, $zero, L_8001F420
    if (ctx->r1 != 0) {
        // 0x8001F440: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8001F420;
    }
    // 0x8001F440: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8001F444:
    // 0x8001F444: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001F448: jr          $ra
    // 0x8001F44C: nop

    return;
    // 0x8001F44C: nop

;}
RECOMP_FUNC void check_if_in_draw_range(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A900: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002A904: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002A908: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A90C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8002A910: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A914: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8002A918: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A91C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8002A920: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A924: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8002A928: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8002A92C: nop

    // 0x8002A930: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8002A934: bne         $t7, $zero, L_8002ABD4
    if (ctx->r15 != 0) {
        // 0x8002A938: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002ABD4;
    }
    // 0x8002A938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A93C: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8002A940: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8002A944: lh          $v1, 0x4E($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X4E);
    extern void dkr_extend_object_draw_distance(uint8_t*, recomp_context*); dkr_extend_object_draw_distance(rdram, ctx);
    // 0x8002A948: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002A94C: beq         $v1, $zero, L_8002AAC0
    if (ctx->r3 == 0) {
        // 0x8002A950: nop
    
            goto L_8002AAC0;
    }
    // 0x8002A950: nop

    // 0x8002A954: lw          $t9, -0x2C84($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C84);
    // 0x8002A958: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002A95C: bne         $t9, $at, L_8002A9A8
    if (ctx->r25 != ctx->r1) {
        // 0x8002A960: nop
    
            goto L_8002A9A8;
    }
    // 0x8002A960: nop

    // 0x8002A964: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8002A968: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002A96C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8002A970: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002A974: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A978: nop

    // 0x8002A97C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8002A980: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8002A984: nop

    // 0x8002A988: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8002A98C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002A990: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002A994: nop

    // 0x8002A998: cvt.w.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_D(ctx->f10.d);
    // 0x8002A99C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8002A9A0: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8002A9A4: nop

L_8002A9A8:
    // 0x8002A9A8: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002A9AC: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002A9B0: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x8002A9B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8002A9B8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8002A9BC: jal         0x80066348
    // 0x8002A9C0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    get_distance_to_active_camera(rdram, ctx);
        goto after_0;
    // 0x8002A9C0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002A9C4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8002A9C8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8002A9CC: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8002A9D0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002A9D4: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A9D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002A9DC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8002A9E0: nop

    // 0x8002A9E4: bc1f        L_8002A9F4
    if (!c1cs) {
        // 0x8002A9E8: nop
    
            goto L_8002A9F4;
    }
    // 0x8002A9E8: nop

    // 0x8002A9EC: b           L_8002ABD4
    // 0x8002A9F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002ABD4;
    // 0x8002A9F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A9F4:
    // 0x8002A9F4: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8002A9F8: lwc1        $f5, 0x5EB0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5EB0);
    // 0x8002A9FC: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8002AA00: lwc1        $f4, 0x5EB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EB4);
    // 0x8002AA04: nop

    // 0x8002AA08: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8002AA0C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8002AA10: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002AA14: nop

    // 0x8002AA18: bc1f        L_8002AAC0
    if (!c1cs) {
        // 0x8002AA1C: nop
    
            goto L_8002AAC0;
    }
    // 0x8002AA1C: nop

    // 0x8002AA20: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8002AA24: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8002AA28: nop

    // 0x8002AA2C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8002AA30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002AA34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002AA38: nop

    // 0x8002AA3C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002AA40: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8002AA44: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8002AA48: blez        $v1, L_8002AAB4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002AA4C: nop
    
            goto L_8002AAB4;
    }
    // 0x8002AA4C: nop

    // 0x8002AA50: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8002AA54: sub.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002AA58: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002AA5C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002AA60: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002AA64: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002AA68: div.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8002AA6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002AA70: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AA74: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x8002AA78: lwc1        $f6, 0x5EBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5EBC);
    // 0x8002AA7C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002AA80: lwc1        $f7, 0x5EB8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5EB8);
    // 0x8002AA84: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AA88: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8002AA8C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002AA90: nop

    // 0x8002AA94: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8002AA98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002AA9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002AAA0: nop

    // 0x8002AAA4: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x8002AAA8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002AAAC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002AAB0: nop

L_8002AAB4:
    // 0x8002AAB4: bne         $a1, $zero, L_8002AAC0
    if (ctx->r5 != 0) {
        // 0x8002AAB8: nop
    
            goto L_8002AAC0;
    }
    // 0x8002AAB8: nop

    // 0x8002AABC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8002AAC0:
    // 0x8002AAC0: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    // 0x8002AAC4: nop

    // 0x8002AAC8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8002AACC: bne         $at, $zero, L_8002AAF8
    if (ctx->r1 != 0) {
        // 0x8002AAD0: addiu       $t3, $v0, -0x32
        ctx->r11 = ADD32(ctx->r2, -0X32);
            goto L_8002AAF8;
    }
    // 0x8002AAD0: addiu       $t3, $v0, -0x32
    ctx->r11 = ADD32(ctx->r2, -0X32);
    // 0x8002AAD4: sltiu       $at, $t3, 0x20
    ctx->r1 = ctx->r11 < 0X20 ? 1 : 0;
    // 0x8002AAD8: beq         $at, $zero, L_8002AB54
    if (ctx->r1 == 0) {
        // 0x8002AADC: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8002AB54;
    }
    // 0x8002AADC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002AAE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002AAE4: addu        $at, $at, $t3
    gpr jr_addend_8002AAF0 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8002AAE8: lw          $t3, 0x5EC0($at)
    ctx->r11 = ADD32(ctx->r1, 0X5EC0);
    // 0x8002AAEC: nop

    // 0x8002AAF0: jr          $t3
    // 0x8002AAF4: nop

    switch (jr_addend_8002AAF0 >> 2) {
        case 0: goto L_8002AB40; break;
        case 1: goto L_8002AB40; break;
        case 2: goto L_8002AB54; break;
        case 3: goto L_8002AB40; break;
        case 4: goto L_8002AB40; break;
        case 5: goto L_8002AB54; break;
        case 6: goto L_8002AB40; break;
        case 7: goto L_8002AB54; break;
        case 8: goto L_8002AB2C; break;
        case 9: goto L_8002AB54; break;
        case 10: goto L_8002AB54; break;
        case 11: goto L_8002AB54; break;
        case 12: goto L_8002AB58; break;
        case 13: goto L_8002AB54; break;
        case 14: goto L_8002AB54; break;
        case 15: goto L_8002AB54; break;
        case 16: goto L_8002AB54; break;
        case 17: goto L_8002AB54; break;
        case 18: goto L_8002AB54; break;
        case 19: goto L_8002AB54; break;
        case 20: goto L_8002AB40; break;
        case 21: goto L_8002AB54; break;
        case 22: goto L_8002AB40; break;
        case 23: goto L_8002AB54; break;
        case 24: goto L_8002AB54; break;
        case 25: goto L_8002AB54; break;
        case 26: goto L_8002AB54; break;
        case 27: goto L_8002AB58; break;
        case 28: goto L_8002AB54; break;
        case 29: goto L_8002AB54; break;
        case 30: goto L_8002AB58; break;
        case 31: goto L_8002AB40; break;
        default: switch_error(__func__, 0x8002AAF0, 0x800E5EC0);
    }
    // 0x8002AAF4: nop

L_8002AAF8:
    // 0x8002AAF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AAFC: bne         $v0, $at, L_8002AB54
    if (ctx->r2 != ctx->r1) {
        // 0x8002AB00: nop
    
            goto L_8002AB54;
    }
    // 0x8002AB00: nop

    // 0x8002AB04: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8002AB08: nop

    // 0x8002AB0C: lbu         $t4, 0x1F7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1F7);
    // 0x8002AB10: nop

    // 0x8002AB14: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002AB18: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002AB1C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002AB20: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8002AB24: b           L_8002AB58
    // 0x8002AB28: sb          $t7, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r15;
        goto L_8002AB58;
    // 0x8002AB28: sb          $t7, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r15;
L_8002AB2C:
    // 0x8002AB2C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8002AB30: nop

    // 0x8002AB34: lbu         $t8, 0x1F7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1F7);
    // 0x8002AB38: b           L_8002AB58
    // 0x8002AB3C: sb          $t8, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r24;
        goto L_8002AB58;
    // 0x8002AB3C: sb          $t8, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r24;
L_8002AB40:
    // 0x8002AB40: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8002AB44: nop

    // 0x8002AB48: lbu         $t9, 0x42($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X42);
    // 0x8002AB4C: b           L_8002AB58
    // 0x8002AB50: sb          $t9, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r25;
        goto L_8002AB58;
    // 0x8002AB50: sb          $t9, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r25;
L_8002AB54:
    // 0x8002AB54: sb          $a1, 0x39($a0)
    MEM_B(0X39, ctx->r4) = ctx->r5;
L_8002AB58:
    // 0x8002AB58: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002AB5C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002AB60: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002AB64: lwc1        $f20, 0x10($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002AB68: lwc1        $f22, 0x14($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002AB6C: lwc1        $f24, 0x34($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8002AB70: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8002AB74: addiu       $v1, $v1, -0x2ED8
    ctx->r3 = ADD32(ctx->r3, -0X2ED8);
    // 0x8002AB78: addiu       $v0, $v0, -0x2F08
    ctx->r2 = ADD32(ctx->r2, -0X2F08);
L_8002AB7C:
    // 0x8002AB7C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002AB80: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002AB84: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8002AB88: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002AB8C: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002AB90: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002AB94: mul.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8002AB98: nop

    // 0x8002AB9C: mul.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8002ABA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002ABA4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002ABA8: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8002ABAC: add.s       $f16, $f6, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8002ABB0: c.lt.s      $f16, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f16.fl < ctx->f26.fl;
    // 0x8002ABB4: nop

    // 0x8002ABB8: bc1f        L_8002ABC8
    if (!c1cs) {
        // 0x8002ABBC: nop
    
            goto L_8002ABC8;
    }
    // 0x8002ABBC: nop

    // 0x8002ABC0: b           L_8002ABD4
    // 0x8002ABC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002ABD4;
    // 0x8002ABC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002ABC8:
    // 0x8002ABC8: bne         $v0, $v1, L_8002AB7C
    if (ctx->r2 != ctx->r3) {
        // 0x8002ABCC: nop
    
            goto L_8002AB7C;
    }
    // 0x8002ABCC: nop

    // 0x8002ABD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002ABD4:
    // 0x8002ABD4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002ABD8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8002ABDC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8002ABE0: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002ABE4: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002ABE8: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002ABEC: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002ABF0: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002ABF4: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002ABF8: jr          $ra
    // 0x8002ABFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8002ABFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void menu_racer_portraits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094604: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80094608: addiu       $v0, $v0, 0x6550
    ctx->r2 = ADD32(ctx->r2, 0X6550);
    // 0x8009460C: lw          $t6, 0xC8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC8);
    // 0x80094610: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094614: sw          $t6, 0xA50($at)
    MEM_W(0XA50, ctx->r1) = ctx->r14;
    // 0x80094618: lw          $t7, 0xCC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XCC);
    // 0x8009461C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094620: sw          $t7, 0xA60($at)
    MEM_W(0XA60, ctx->r1) = ctx->r15;
    // 0x80094624: lw          $t8, 0xD0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XD0);
    // 0x80094628: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009462C: sw          $t8, 0xA70($at)
    MEM_W(0XA70, ctx->r1) = ctx->r24;
    // 0x80094630: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x80094634: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094638: sw          $t9, 0xA90($at)
    MEM_W(0XA90, ctx->r1) = ctx->r25;
    // 0x8009463C: lw          $t0, 0xD4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XD4);
    // 0x80094640: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094644: sw          $t0, 0xA80($at)
    MEM_W(0XA80, ctx->r1) = ctx->r8;
    // 0x80094648: lw          $t1, 0xDC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XDC);
    // 0x8009464C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094650: sw          $t1, 0xAA0($at)
    MEM_W(0XAA0, ctx->r1) = ctx->r9;
    // 0x80094654: lw          $t2, 0xE0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XE0);
    // 0x80094658: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009465C: sw          $t2, 0xAB0($at)
    MEM_W(0XAB0, ctx->r1) = ctx->r10;
    // 0x80094660: lw          $t3, 0xE4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XE4);
    // 0x80094664: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094668: sw          $t3, 0xAC0($at)
    MEM_W(0XAC0, ctx->r1) = ctx->r11;
    // 0x8009466C: lw          $t4, 0xE8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XE8);
    // 0x80094670: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094674: sw          $t4, 0xAD0($at)
    MEM_W(0XAD0, ctx->r1) = ctx->r12;
    // 0x80094678: lw          $t5, 0xEC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XEC);
    // 0x8009467C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094680: jr          $ra
    // 0x80094684: sw          $t5, 0xAE0($at)
    MEM_W(0XAE0, ctx->r1) = ctx->r13;
    return;
    // 0x80094684: sw          $t5, 0xAE0($at)
    MEM_W(0XAE0, ctx->r1) = ctx->r13;
;}
RECOMP_FUNC void menu_init_vehicle_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E45C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008E460: addiu       $v1, $v1, 0x6550
    ctx->r3 = ADD32(ctx->r3, 0X6550);
    // 0x8008E464: lw          $t6, 0x60($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X60);
    // 0x8008E468: lw          $t7, 0x64($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X64);
    // 0x8008E46C: lw          $t8, 0x68($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X68);
    // 0x8008E470: lw          $t9, 0x6C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6C);
    // 0x8008E474: lw          $t0, 0x70($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X70);
    // 0x8008E478: lw          $t1, 0x74($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X74);
    // 0x8008E47C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E480: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E484: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008E488: addiu       $a1, $a1, 0x48C
    ctx->r5 = ADD32(ctx->r5, 0X48C);
    // 0x8008E48C: addiu       $a0, $a0, 0x474
    ctx->r4 = ADD32(ctx->r4, 0X474);
    // 0x8008E490: addiu       $v0, $v0, 0x45C
    ctx->r2 = ADD32(ctx->r2, 0X45C);
    // 0x8008E494: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008E498: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8008E49C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8008E4A0: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8008E4A4: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8008E4A8: jr          $ra
    // 0x8008E4AC: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    return;
    // 0x8008E4AC: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void alResampleNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80064FA0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80064FA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80064FA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80064FAC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80064FB0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80064FB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80064FB8: addiu       $a2, $a2, -0x3F70
    ctx->r6 = ADD32(ctx->r6, -0X3F70);
    // 0x80064FBC: addiu       $a1, $a1, -0x3E84
    ctx->r5 = ADD32(ctx->r5, -0X3E84);
    // 0x80064FC0: jal         0x800CA0B0
    // 0x80064FC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80064FC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80064FC8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80064FCC: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80064FD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80064FD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80064FDC: jal         0x800C77F0
    // 0x80064FE0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80064FE0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80064FE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80064FE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80064FEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80064FF0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80064FF4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80064FF8: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x80064FFC: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80065000: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80065004: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80065008: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x8006500C: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x80065010: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80065014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80065018: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006501C: jr          $ra
    // 0x80065020: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065020: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mtxf_translate_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FE30: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x8006FE34: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006FE38: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8006FE3C: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8006FE40: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8006FE44: lwc1        $f2, 0x30($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8006FE48: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8006FE4C: mul.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8006FE50: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8006FE54: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006FE58: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006FE5C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006FE60: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x8006FE64: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006FE68: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x8006FE6C: jr          $ra
    // 0x8006FE70: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8006FE70: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void add_particle_to_entity_list(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E9D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E9D8: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8000E9DC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000E9E0: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8000E9E4: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x8000E9E8: lh          $a0, 0x2C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2C);
    // 0x8000E9EC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8000E9F0: ori         $t8, $a0, 0xC000
    ctx->r24 = ctx->r4 | 0XC000;
    // 0x8000E9F4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8000E9F8: jal         0x800245B4
    // 0x8000E9FC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x8000E9FC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_0:
    // 0x8000EA00: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EA04: addiu       $v0, $v0, -0x51A4
    ctx->r2 = ADD32(ctx->r2, -0X51A4);
    // 0x8000EA08: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA0C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000EA10: lw          $t1, -0x51A8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X51A8);
    // 0x8000EA14: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8000EA18: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000EA1C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000EA20: sw          $a1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r5;
    // 0x8000EA24: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA28: nop

    // 0x8000EA2C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000EA30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000EA34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EA38: addiu       $v0, $v0, -0x519C
    ctx->r2 = ADD32(ctx->r2, -0X519C);
    // 0x8000EA3C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8000EA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000EA44: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000EA48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000EA4C: jr          $ra
    // 0x8000EA50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000EA50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void check_if_silver_coin_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E1E0: lb          $v0, -0x51FD($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X51FD);
    // 0x8000E1E4: jr          $ra
    // 0x8000E1E8: nop

    return;
    // 0x8000E1E8: nop

;}
RECOMP_FUNC void obj_init_ainode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CFE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CFE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003CFE8: lbu         $a2, 0x9($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X9);
    // 0x8003CFEC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003CFF0: bne         $a2, $at, L_8003D00C
    if (ctx->r6 != ctx->r1) {
        // 0x8003CFF4: nop
    
            goto L_8003D00C;
    }
    // 0x8003CFF4: nop

    // 0x8003CFF8: jal         0x8001C48C
    // 0x8003CFFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ainode_register(rdram, ctx);
        goto after_0;
    // 0x8003CFFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003D000: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D004: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x8003D008: sb          $v0, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r2;
L_8003D00C:
    // 0x8003D00C: jal         0x8001D1BC
    // 0x8003D010: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ainode_tail_set(rdram, ctx);
        goto after_1;
    // 0x8003D010: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8003D014: jal         0x8001D1AC
    // 0x8003D018: nop

    ainode_enable(rdram, ctx);
        goto after_2;
    // 0x8003D018: nop

    after_2:
    // 0x8003D01C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D024: jr          $ra
    // 0x8003D028: nop

    return;
    // 0x8003D028: nop

;}
RECOMP_FUNC void bgload_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7350: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7354: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7358: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C735C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C7360: addiu       $a1, $a1, -0x5348
    ctx->r5 = ADD32(ctx->r5, -0X5348);
    // 0x800C7364: addiu       $a0, $a0, -0x5360
    ctx->r4 = ADD32(ctx->r4, -0X5360);
    // 0x800C7368: jal         0x800C8820
    // 0x800C736C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800C736C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800C7370: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C7374: addiu       $t6, $t6, -0x3340
    ctx->r14 = ADD32(ctx->r14, -0X3340);
    // 0x800C7378: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C737C: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800C7380: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800C7384: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C7388: addiu       $a2, $a2, 0x74A0
    ctx->r6 = ADD32(ctx->r6, 0X74A0);
    // 0x800C738C: addiu       $a0, $a0, -0x5510
    ctx->r4 = ADD32(ctx->r4, -0X5510);
    // 0x800C7390: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C7394: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800C7398: jal         0x800C8850
    // 0x800C739C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800C739C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800C73A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C73A4: jal         0x800C89A0
    // 0x800C73A8: addiu       $a0, $a0, -0x5510
    ctx->r4 = ADD32(ctx->r4, -0X5510);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800C73A8: addiu       $a0, $a0, -0x5510
    ctx->r4 = ADD32(ctx->r4, -0X5510);
    after_2:
    // 0x800C73AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C73B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C73B4: jr          $ra
    // 0x800C73B8: nop

    return;
    // 0x800C73B8: nop

;}
RECOMP_FUNC void func_80012C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C3C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80012C40: addiu       $a3, $a3, -0x525C
    ctx->r7 = ADD32(ctx->r7, -0X525C);
    // 0x80012C44: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x80012C48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012C4C: blez        $t6, L_80012C90
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80012C50: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_80012C90;
    }
    // 0x80012C50: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012C54: addiu       $a2, $a2, -0x5288
    ctx->r6 = ADD32(ctx->r6, -0X5288);
    // 0x80012C58: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
L_80012C5C:
    // 0x80012C5C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80012C60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80012C64: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80012C68: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80012C6C: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80012C70: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80012C74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80012C78: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80012C7C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80012C80: nop

    // 0x80012C84: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80012C88: bne         $at, $zero, L_80012C5C
    if (ctx->r1 != 0) {
        // 0x80012C8C: nop
    
            goto L_80012C5C;
    }
    // 0x80012C8C: nop

L_80012C90:
    // 0x80012C90: jr          $ra
    // 0x80012C94: nop

    return;
    // 0x80012C94: nop

;}
RECOMP_FUNC void obj_wave_height(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEEB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BEEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BEEBC: lhu         $t6, 0x4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X4);
    // 0x800BEEC0: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x800BEEC4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800BEEC8: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x800BEECC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEED0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BEED4: bne         $at, $zero, L_800BEEF0
    if (ctx->r1 != 0) {
        // 0x800BEED8: sh          $t7, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r15;
            goto L_800BEEF0;
    }
    // 0x800BEED8: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
L_800BEEDC:
    // 0x800BEEDC: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x800BEEE0: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x800BEEE4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEEE8: beq         $at, $zero, L_800BEEDC
    if (ctx->r1 == 0) {
        // 0x800BEEEC: sh          $t8, 0x4($a3)
        MEM_H(0X4, ctx->r7) = ctx->r24;
            goto L_800BEEDC;
    }
    // 0x800BEEEC: sh          $t8, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r24;
L_800BEEF0:
    // 0x800BEEF0: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800BEEF4: addu        $a0, $a3, $t9
    ctx->r4 = ADD32(ctx->r7, ctx->r25);
    // 0x800BEEF8: lb          $t0, 0xE($a0)
    ctx->r8 = MEM_B(ctx->r4, 0XE);
    // 0x800BEEFC: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800BEF00: beq         $t1, $zero, L_800BEF4C
    if (ctx->r9 == 0) {
        // 0x800BEF04: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_800BEF4C;
    }
    // 0x800BEF04: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x800BEF08: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEF0C: bne         $at, $zero, L_800BEF20
    if (ctx->r1 != 0) {
        // 0x800BEF10: nop
    
            goto L_800BEF20;
    }
    // 0x800BEF10: nop

    // 0x800BEF14: lb          $t3, 0xE($a3)
    ctx->r11 = MEM_B(ctx->r7, 0XE);
    // 0x800BEF18: b           L_800BEF2C
    // 0x800BEF1C: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
        goto L_800BEF2C;
    // 0x800BEF1C: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
L_800BEF20:
    // 0x800BEF20: lb          $t4, 0xF($a0)
    ctx->r12 = MEM_B(ctx->r4, 0XF);
    // 0x800BEF24: nop

    // 0x800BEF28: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
L_800BEF2C:
    // 0x800BEF2C: lbu         $v0, 0x2($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2);
    // 0x800BEF30: sra         $t6, $t0, 1
    ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800BEF34: blez        $v0, L_800BEF44
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BEF38: addiu       $t5, $v0, 0x1F
        ctx->r13 = ADD32(ctx->r2, 0X1F);
            goto L_800BEF44;
    }
    // 0x800BEF38: addiu       $t5, $v0, 0x1F
    ctx->r13 = ADD32(ctx->r2, 0X1F);
    // 0x800BEF3C: b           L_800BEF58
    // 0x800BEF40: sllv        $t0, $t0, $t5
    ctx->r8 = S32(ctx->r8 << (ctx->r13 & 31));
        goto L_800BEF58;
    // 0x800BEF40: sllv        $t0, $t0, $t5
    ctx->r8 = S32(ctx->r8 << (ctx->r13 & 31));
L_800BEF44:
    // 0x800BEF44: b           L_800BEF58
    // 0x800BEF48: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
        goto L_800BEF58;
    // 0x800BEF48: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_800BEF4C:
    // 0x800BEF4C: lbu         $t7, 0x2($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2);
    // 0x800BEF50: nop

    // 0x800BEF54: sllv        $t0, $t0, $t7
    ctx->r8 = S32(ctx->r8 << (ctx->r15 & 31));
L_800BEF58:
    // 0x800BEF58: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800BEF5C: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800BEF60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BEF64: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x800BEF68: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800BEF6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BEF70: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800BEF74: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800BEF78: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800BEF7C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BEF80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BEF84: lwc1        $f10, -0x5FF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5FF8);
    // 0x800BEF88: lhu         $a0, 0xC($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0XC);
    // 0x800BEF8C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800BEF90: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x800BEF94: lhu         $a1, 0x8($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X8);
    // 0x800BEF98: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800BEF9C: lhu         $a2, 0xA($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0XA);
    // 0x800BEFA0: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800BEFA4: jal         0x800BEFC4
    // 0x800BEFA8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800BEFA8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800BEFAC: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800BEFB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BEFB4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800BEFB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BEFBC: jr          $ra
    // 0x800BEFC0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800BEFC0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void update_onscreen_AI_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054110: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80054114: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80054118: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005411C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80054120: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x80054124: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x80054128: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8005412C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054130: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x80054134: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80054138: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8005413C: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x80054140: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80054144: sw          $zero, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = 0;
    // 0x80054148: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8005414C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054150: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80054154: sw          $zero, -0x2AA8($at)
    MEM_W(-0X2AA8, ctx->r1) = 0;
    // 0x80054158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005415C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80054160: jal         0x800579B0
    // 0x80054164: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    handle_base_steering(rdram, ctx);
        goto after_0;
    // 0x80054164: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80054168: jal         0x80053664
    // 0x8005416C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    handle_car_velocity_control(rdram, ctx);
        goto after_1;
    // 0x8005416C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80054170: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054174: jal         0x800575EC
    // 0x80054178: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800575EC(rdram, ctx);
        goto after_2;
    // 0x80054178: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8005417C: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x80054180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054184: jal         0x80055EC0
    // 0x80054188: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    handle_racer_items(rdram, ctx);
        goto after_3;
    // 0x80054188: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8005418C: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x80054190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054194: jal         0x80053E9C
    // 0x80054198: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_attack_handler_car(rdram, ctx);
        goto after_4;
    // 0x80054198: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8005419C: lb          $t6, 0x1DB($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1DB);
    // 0x800541A0: nop

    // 0x800541A4: beq         $t6, $zero, L_800541C8
    if (ctx->r14 == 0) {
        // 0x800541A8: nop
    
            goto L_800541C8;
    }
    // 0x800541A8: nop

    // 0x800541AC: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x800541B0: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x800541B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800541B8: jal         0x80052B64
    // 0x800541BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_spinout_car(rdram, ctx);
        goto after_5;
    // 0x800541BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800541C0: b           L_80054204
    // 0x800541C4: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
        goto L_80054204;
    // 0x800541C4: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
L_800541C8:
    // 0x800541C8: lb          $t7, 0x1E2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E2);
    // 0x800541CC: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x800541D0: blez        $t7, L_800541F4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800541D4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800541F4;
    }
    // 0x800541D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800541D8: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x800541DC: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x800541E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800541E4: jal         0x8005492C
    // 0x800541E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_car_velocity_ground(rdram, ctx);
        goto after_6;
    // 0x800541E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800541EC: b           L_80054204
    // 0x800541F0: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
        goto L_80054204;
    // 0x800541F0: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
L_800541F4:
    // 0x800541F4: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x800541F8: jal         0x80052D7C
    // 0x800541FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_car_velocity_offground(rdram, ctx);
        goto after_7;
    // 0x800541FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80054200: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
L_80054204:
    // 0x80054204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80054208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005420C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80054210: jal         0x80050850
    // 0x80054214: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    apply_vehicle_rotation_offset(rdram, ctx);
        goto after_8;
    // 0x80054214: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80054218: jal         0x8006BDB0
    // 0x8005421C: nop

    level_header(rdram, ctx);
        goto after_9;
    // 0x8005421C: nop

    after_9:
    // 0x80054220: lwc1        $f16, 0xC0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80054224: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80054228: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005422C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80054230: c.eq.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d == ctx->f18.d;
    // 0x80054234: nop

    // 0x80054238: bc1t        L_8005424C
    if (c1cs) {
        // 0x8005423C: nop
    
            goto L_8005424C;
    }
    // 0x8005423C: nop

    // 0x80054240: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x80054244: nop

    // 0x80054248: bne         $t8, $zero, L_80054260
    if (ctx->r24 != 0) {
        // 0x8005424C: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80054260;
    }
L_8005424C:
    // 0x8005424C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80054250: lb          $t9, -0x2A7F($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2A7F);
    // 0x80054254: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80054258: bne         $t9, $at, L_80054398
    if (ctx->r25 != ctx->r1) {
        // 0x8005425C: nop
    
            goto L_80054398;
    }
    // 0x8005425C: nop

L_80054260:
    // 0x80054260: lbu         $t0, 0x1F0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1F0);
    // 0x80054264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054268: beq         $t0, $zero, L_80054294
    if (ctx->r8 == 0) {
        // 0x8005426C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80054294;
    }
    // 0x8005426C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80054270: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054274: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x80054278: lwc1        $f9, 0x67C8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X67C8);
    // 0x8005427C: lwc1        $f8, 0x67CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X67CC);
    // 0x80054280: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80054284: sub.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f6.d - ctx->f8.d;
    // 0x80054288: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8005428C: b           L_800542B4
    // 0x80054290: swc1        $f10, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f10.u32l;
        goto L_800542B4;
    // 0x80054290: swc1        $f10, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f10.u32l;
L_80054294:
    // 0x80054294: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054298: lwc1        $f18, 0xA8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8005429C: lwc1        $f7, 0x67D0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X67D0);
    // 0x800542A0: lwc1        $f6, 0x67D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X67D4);
    // 0x800542A4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800542A8: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x800542AC: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800542B0: swc1        $f16, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f16.u32l;
L_800542B4:
    // 0x800542B4: addiu       $t1, $sp, 0xA4
    ctx->r9 = ADD32(ctx->r29, 0XA4);
    // 0x800542B8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800542BC: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    // 0x800542C0: jal         0x80059080
    // 0x800542C4: addiu       $a3, $sp, 0xA0
    ctx->r7 = ADD32(ctx->r29, 0XA0);
    set_position_goal_from_path(rdram, ctx);
        goto after_10;
    // 0x800542C4: addiu       $a3, $sp, 0xA0
    ctx->r7 = ADD32(ctx->r29, 0XA0);
    after_10:
    // 0x800542C8: lbu         $t2, 0x1F0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1F0);
    // 0x800542CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800542D0: beq         $t2, $zero, L_800542FC
    if (ctx->r10 == 0) {
        // 0x800542D4: nop
    
            goto L_800542FC;
    }
    // 0x800542D4: nop

    // 0x800542D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800542DC: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x800542E0: lwc1        $f5, 0x67D8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X67D8);
    // 0x800542E4: lwc1        $f4, 0x67DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X67DC);
    // 0x800542E8: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800542EC: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800542F0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800542F4: b           L_80054318
    // 0x800542F8: swc1        $f8, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f8.u32l;
        goto L_80054318;
    // 0x800542F8: swc1        $f8, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f8.u32l;
L_800542FC:
    // 0x800542FC: lwc1        $f16, 0xA8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x80054300: lwc1        $f19, 0x67E0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X67E0);
    // 0x80054304: lwc1        $f18, 0x67E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X67E4);
    // 0x80054308: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8005430C: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x80054310: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80054314: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
L_80054318:
    // 0x80054318: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8005431C: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80054320: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80054324: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80054328: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x8005432C: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80054330: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80054334: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80054338: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x8005433C: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80054340: jal         0x800C9AD0
    // 0x80054344: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x80054344: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    after_11:
    // 0x80054348: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8005434C: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80054350: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80054354: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80054358: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005435C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x80054360: lui         $at, 0x4118
    ctx->r1 = S32(0X4118 << 16);
    // 0x80054364: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80054368: div.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8005436C: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80054370: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x80054374: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80054378: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x8005437C: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x80054380: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80054384: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x80054388: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8005438C: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x80054390: b           L_800543B0
    // 0x80054394: sb          $t3, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = ctx->r11;
        goto L_800543B0;
    // 0x80054394: sb          $t3, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = ctx->r11;
L_80054398:
    // 0x80054398: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005439C: nop

    // 0x800543A0: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800543A4: bne         $at, $zero, L_800543B0
    if (ctx->r1 != 0) {
        // 0x800543A8: nop
    
            goto L_800543B0;
    }
    // 0x800543A8: nop

    // 0x800543AC: sb          $zero, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = 0;
L_800543B0:
    // 0x800543B0: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x800543B4: lh          $t5, 0x1A2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A2);
    // 0x800543B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800543BC: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800543C0: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800543C4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800543C8: lwc1        $f8, -0x2A90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2A90);
    // 0x800543CC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800543D0: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x800543D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800543D8: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800543DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800543E0: nop

    // 0x800543E4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800543E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800543EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800543F0: nop

    // 0x800543F4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800543F8: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800543FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80054400: subu        $v0, $t9, $v0
    ctx->r2 = SUB32(ctx->r25, ctx->r2);
    // 0x80054404: bgez        $v0, L_80054414
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80054408: slti        $at, $v0, 0x4A
        ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
            goto L_80054414;
    }
    // 0x80054408: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x8005440C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80054410: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
L_80054414:
    // 0x80054414: bne         $at, $zero, L_80054420
    if (ctx->r1 != 0) {
        // 0x80054418: nop
    
            goto L_80054420;
    }
    // 0x80054418: nop

    // 0x8005441C: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_80054420:
    // 0x80054420: jal         0x8005234C
    // 0x80054424: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    slowly_reset_head_angle(rdram, ctx);
        goto after_12;
    // 0x80054424: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    after_12:
    // 0x80054428: lh          $a0, 0x1A2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A2);
    // 0x8005442C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80054430: lw          $t0, -0x2AAC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AAC);
    // 0x80054434: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x80054438: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005443C: subu        $v0, $t0, $t1
    ctx->r2 = SUB32(ctx->r8, ctx->r9);
    // 0x80054440: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80054444: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x80054448: bne         $at, $zero, L_80054458
    if (ctx->r1 != 0) {
        // 0x8005444C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80054458;
    }
    // 0x8005444C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80054450: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80054454: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80054458:
    // 0x80054458: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8005445C: beq         $at, $zero, L_80054468
    if (ctx->r1 == 0) {
        // 0x80054460: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80054468;
    }
    // 0x80054460: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80054464: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80054468:
    // 0x80054468: sra         $t2, $v0, 2
    ctx->r10 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8005446C: slti        $at, $t2, 0x2EF
    ctx->r1 = SIGNED(ctx->r10) < 0X2EF ? 1 : 0;
    // 0x80054470: bne         $at, $zero, L_8005447C
    if (ctx->r1 != 0) {
        // 0x80054474: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8005447C;
    }
    // 0x80054474: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80054478: addiu       $v0, $zero, 0x2EE
    ctx->r2 = ADD32(0, 0X2EE);
L_8005447C:
    // 0x8005447C: slti        $at, $v0, -0x2EE
    ctx->r1 = SIGNED(ctx->r2) < -0X2EE ? 1 : 0;
    // 0x80054480: beq         $at, $zero, L_8005448C
    if (ctx->r1 == 0) {
        // 0x80054484: nop
    
            goto L_8005448C;
    }
    // 0x80054484: nop

    // 0x80054488: addiu       $v0, $zero, -0x2EE
    ctx->r2 = ADD32(0, -0X2EE);
L_8005448C:
    // 0x8005448C: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054490: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x80054494: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80054498: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005449C: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x800544A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800544A4: mflo        $t4
    ctx->r12 = lo;
    // 0x800544A8: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x800544AC: sh          $t5, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r13;
    // 0x800544B0: lh          $t7, 0x1A2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A2);
    // 0x800544B4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800544B8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800544BC: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x800544C0: lh          $v1, 0x1A6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A6);
    // 0x800544C4: lw          $t9, -0x2AA8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AA8);
    // 0x800544C8: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x800544CC: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x800544D0: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800544D4: lh          $t5, 0x1A4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A4);
    // 0x800544D8: mflo        $t2
    ctx->r10 = lo;
    // 0x800544DC: sra         $t3, $t2, 4
    ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
    // 0x800544E0: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800544E4: sh          $t4, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r12;
    // 0x800544E8: lh          $t6, 0x1A6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A6);
    // 0x800544EC: nop

    // 0x800544F0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800544F4: sh          $t7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r15;
    // 0x800544F8: lbu         $t8, 0x1F0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F0);
    // 0x800544FC: nop

    // 0x80054500: bne         $t8, $zero, L_80054568
    if (ctx->r24 != 0) {
        // 0x80054504: nop
    
            goto L_80054568;
    }
    // 0x80054504: nop

    // 0x80054508: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x8005450C: lw          $t0, 0x10C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10C);
    // 0x80054510: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80054514: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80054518: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8005451C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x80054520: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80054524: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80054528: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8005452C: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80054530: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x80054534: jal         0x8006FE74
    // 0x80054538: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_13;
    // 0x80054538: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    after_13:
    // 0x8005453C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80054540: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x80054544: addiu       $t2, $s1, 0x1C
    ctx->r10 = ADD32(ctx->r17, 0X1C);
    // 0x80054548: addiu       $t3, $sp, 0xAC
    ctx->r11 = ADD32(ctx->r29, 0XAC);
    // 0x8005454C: addiu       $t4, $s1, 0x24
    ctx->r12 = ADD32(ctx->r17, 0X24);
    // 0x80054550: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80054554: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80054558: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005455C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80054560: jal         0x8006F64C
    // 0x80054564: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    mtxf_transform_point(rdram, ctx);
        goto after_14;
    // 0x80054564: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_14:
L_80054568:
    // 0x80054568: lb          $t5, 0x175($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X175);
    // 0x8005456C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054570: beq         $t5, $zero, L_80054590
    if (ctx->r13 == 0) {
        // 0x80054574: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80054590;
    }
    // 0x80054574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054578: lwc1        $f6, -0x2A88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2A88);
    // 0x8005457C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054580: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x80054584: lwc1        $f4, -0x2A84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A84);
    // 0x80054588: nop

    // 0x8005458C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
L_80054590:
    // 0x80054590: lw          $t6, 0x148($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X148);
    // 0x80054594: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x80054598: bne         $t6, $zero, L_80054640
    if (ctx->r14 != 0) {
        // 0x8005459C: nop
    
            goto L_80054640;
    }
    // 0x8005459C: nop

    // 0x800545A0: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800545A4: nop

    // 0x800545A8: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x800545AC: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800545B0: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800545B4: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x800545B8: lb          $t7, 0x1D2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D2);
    // 0x800545BC: nop

    // 0x800545C0: beq         $t7, $zero, L_800545E8
    if (ctx->r15 == 0) {
        // 0x800545C4: nop
    
            goto L_800545E8;
    }
    // 0x800545C4: nop

    // 0x800545C8: lwc1        $f10, 0x11C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x800545CC: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800545D0: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800545D4: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x800545D8: lwc1        $f8, 0x120($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X120);
    // 0x800545DC: nop

    // 0x800545E0: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800545E4: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
L_800545E8:
    // 0x800545E8: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800545EC: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800545F0: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800545F4: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800545F8: lwc1        $f0, 0xBC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800545FC: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x80054600: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80054604: mul.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80054608: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8005460C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054610: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x80054614: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80054618: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005461C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80054620: nop

    // 0x80054624: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80054628: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8005462C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80054630: jal         0x80011570
    // 0x80054634: nop

    move_object(rdram, ctx);
        goto after_15;
    // 0x80054634: nop

    after_15:
    // 0x80054638: b           L_80054648
    // 0x8005463C: nop

        goto L_80054648;
    // 0x8005463C: nop

L_80054640:
    // 0x80054640: jal         0x80050754
    // 0x80054644: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_approach_object(rdram, ctx);
        goto after_16;
    // 0x80054644: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
L_80054648:
    // 0x80054648: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005464C: lw          $t8, -0x2AA4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AA4);
    // 0x80054650: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054654: bne         $t8, $at, L_80054684
    if (ctx->r24 != ctx->r1) {
        // 0x80054658: lw          $a2, 0xB8($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB8);
            goto L_80054684;
    }
    // 0x80054658: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x8005465C: jal         0x80023568
    // 0x80054660: nop

    func_80023568(rdram, ctx);
        goto after_17;
    // 0x80054660: nop

    after_17:
    // 0x80054664: bne         $v0, $zero, L_80054680
    if (ctx->r2 != 0) {
        // 0x80054668: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80054680;
    }
    // 0x80054668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005466C: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x80054670: jal         0x80055A84
    // 0x80054674: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    onscreen_ai_racer_physics(rdram, ctx);
        goto after_18;
    // 0x80054674: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
    // 0x80054678: b           L_80054694
    // 0x8005467C: lb          $t9, 0x201($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X201);
        goto L_80054694;
    // 0x8005467C: lb          $t9, 0x201($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X201);
L_80054680:
    // 0x80054680: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
L_80054684:
    // 0x80054684: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80054688: jal         0x80054FD0
    // 0x8005468C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80054FD0(rdram, ctx);
        goto after_19;
    // 0x8005468C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
    // 0x80054690: lb          $t9, 0x201($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X201);
L_80054694:
    // 0x80054694: nop

    // 0x80054698: bne         $t9, $zero, L_800546A8
    if (ctx->r25 != 0) {
        // 0x8005469C: nop
    
            goto L_800546A8;
    }
    // 0x8005469C: nop

    // 0x800546A0: b           L_800546C4
    // 0x800546A4: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
        goto L_800546C4;
    // 0x800546A4: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
L_800546A8:
    // 0x800546A8: lb          $t0, 0x1D6($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D6);
    // 0x800546AC: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x800546B0: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x800546B4: beq         $at, $zero, L_800546C8
    if (ctx->r1 == 0) {
        // 0x800546B8: lw          $a2, 0xBC($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XBC);
            goto L_800546C8;
    }
    // 0x800546B8: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x800546BC: jal         0x800AF714
    // 0x800546C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    update_vehicle_particles(rdram, ctx);
        goto after_20;
    // 0x800546C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
L_800546C4:
    // 0x800546C4: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
L_800546C8:
    // 0x800546C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800546CC: jal         0x80053750
    // 0x800546D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80053750(rdram, ctx);
        goto after_21;
    // 0x800546D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_21:
    // 0x800546D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800546D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800546DC: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800546E0: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800546E4: div.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800546E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800546EC: lwc1        $f6, -0x2AB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2AB8);
    // 0x800546F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800546F4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800546F8: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x800546FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80054700: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80054704: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x80054708: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005470C: nop

    // 0x80054710: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80054714: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80054718: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005471C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80054720: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80054724: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80054728: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x8005472C: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80054730: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80054734: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80054738: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8005473C: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x80054740: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80054744: lwc1        $f4, -0x2AB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2AB4);
    // 0x80054748: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005474C: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80054750: sub.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80054754: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80054758: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8005475C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80054760: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80054764: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80054768: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x8005476C: lw          $t2, 0x10C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10C);
    // 0x80054770: lh          $t1, 0x1A0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A0);
    // 0x80054774: nop

    // 0x80054778: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8005477C: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x80054780: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x80054784: lh          $t5, 0x2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2);
    // 0x80054788: nop

    // 0x8005478C: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80054790: sh          $t6, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r14;
    // 0x80054794: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x80054798: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8005479C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800547A0: sh          $t8, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r24;
    // 0x800547A4: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x800547A8: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x800547AC: jal         0x8006FE74
    // 0x800547B0: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_22;
    // 0x800547B0: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_22:
    // 0x800547B4: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x800547B8: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x800547BC: addiu       $t9, $sp, 0x9C
    ctx->r25 = ADD32(ctx->r29, 0X9C);
    // 0x800547C0: addiu       $t0, $sp, 0xAC
    ctx->r8 = ADD32(ctx->r29, 0XAC);
    // 0x800547C4: addiu       $t1, $sp, 0xA0
    ctx->r9 = ADD32(ctx->r29, 0XA0);
    // 0x800547C8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800547CC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800547D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800547D4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800547D8: jal         0x8006F64C
    // 0x800547DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    mtxf_transform_point(rdram, ctx);
        goto after_23;
    // 0x800547DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_23:
    // 0x800547E0: lb          $v0, 0x1D2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D2);
    // 0x800547E4: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800547E8: beq         $v0, $zero, L_80054818
    if (ctx->r2 == 0) {
        // 0x800547EC: nop
    
            goto L_80054818;
    }
    // 0x800547EC: nop

    // 0x800547F0: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x800547F4: nop

    // 0x800547F8: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x800547FC: sb          $t3, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r11;
    // 0x80054800: lb          $t4, 0x1D2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D2);
    // 0x80054804: nop

    // 0x80054808: bgez        $t4, L_8005491C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8005480C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005491C;
    }
    // 0x8005480C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80054810: b           L_80054918
    // 0x80054814: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
        goto L_80054918;
    // 0x80054814: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
L_80054818:
    // 0x80054818: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005481C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80054820: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80054824: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80054828: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
    // 0x8005482C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80054830: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80054834: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80054838: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8005483C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80054840: bc1f        L_8005486C
    if (!c1cs) {
        // 0x80054844: lui         $at, 0xBFE0
        ctx->r1 = S32(0XBFE0 << 16);
            goto L_8005486C;
    }
    // 0x80054844: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80054848: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005484C: sub.d       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f0.d - ctx->f2.d;
    // 0x80054850: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80054854: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x80054858: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8005485C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80054860: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80054864: nop

    // 0x80054868: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
L_8005486C:
    // 0x8005486C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80054870: nop

    // 0x80054874: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80054878: nop

    // 0x8005487C: bc1f        L_8005489C
    if (!c1cs) {
        // 0x80054880: nop
    
            goto L_8005489C;
    }
    // 0x80054880: nop

    // 0x80054884: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80054888: add.d       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f0.d + ctx->f2.d;
    // 0x8005488C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80054890: sub.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d - ctx->f10.d;
    // 0x80054894: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x80054898: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8005489C:
    // 0x8005489C: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800548A0: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800548A4: nop

    // 0x800548A8: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800548AC: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
    // 0x800548B0: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800548B4: nop

    // 0x800548B8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800548BC: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x800548C0: nop

    // 0x800548C4: bc1f        L_800548F0
    if (!c1cs) {
        // 0x800548C8: nop
    
            goto L_800548F0;
    }
    // 0x800548C8: nop

    // 0x800548CC: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800548D0: sub.d       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f0.d - ctx->f2.d;
    // 0x800548D4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x800548D8: sub.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f8.d - ctx->f6.d;
    // 0x800548DC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800548E0: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x800548E4: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800548E8: nop

    // 0x800548EC: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
L_800548F0:
    // 0x800548F0: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x800548F4: nop

    // 0x800548F8: bc1f        L_8005491C
    if (!c1cs) {
        // 0x800548FC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005491C;
    }
    // 0x800548FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80054900: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80054904: add.d       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f0.d + ctx->f2.d;
    // 0x80054908: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8005490C: sub.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f8.d - ctx->f6.d;
    // 0x80054910: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80054914: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
L_80054918:
    // 0x80054918: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005491C:
    // 0x8005491C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80054920: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80054924: jr          $ra
    // 0x80054928: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80054928: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void shadow_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D8DC: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8002D8E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D8E4: lw          $t6, -0x4F38($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4F38);
    // 0x8002D8E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002D8EC: addiu       $v1, $v1, -0x4F34
    ctx->r3 = ADD32(ctx->r3, -0X4F34);
    // 0x8002D8F0: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002D8F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D8F8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8002D8FC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002D900: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002D904: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002D908: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002D90C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002D910: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002D914: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002D918: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002D91C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002D920: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002D924: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8002D928: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002D92C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002D930: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002D934: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002D938: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8002D93C: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x8002D940: bne         $a0, $at, L_8002D950
    if (ctx->r4 != ctx->r1) {
        // 0x8002D944: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8002D950;
    }
    // 0x8002D944: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002D948: addiu       $t8, $t6, 0x2
    ctx->r24 = ADD32(ctx->r14, 0X2);
    // 0x8002D94C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8002D950:
    // 0x8002D950: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002D954: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002D958: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8002D95C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002D960: lw          $t0, -0x2CE0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2CE0);
    // 0x8002D964: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002D968: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D96C: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8002D970: lw          $t1, -0x2CC8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2CC8);
    // 0x8002D974: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8002D978: sw          $t0, -0x2CD0($at)
    MEM_W(-0X2CD0, ctx->r1) = ctx->r8;
    // 0x8002D97C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D980: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8002D984: lw          $t2, -0x2CB0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2CB0);
    // 0x8002D988: sw          $t1, -0x2CB8($at)
    MEM_W(-0X2CB8, ctx->r1) = ctx->r9;
    // 0x8002D98C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D990: sw          $t2, -0x2CA0($at)
    MEM_W(-0X2CA0, ctx->r1) = ctx->r10;
    // 0x8002D994: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D998: sw          $zero, -0x2C9C($at)
    MEM_W(-0X2C9C, ctx->r1) = 0;
    // 0x8002D99C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9A0: sw          $zero, -0x2C98($at)
    MEM_W(-0X2C98, ctx->r1) = 0;
    // 0x8002D9A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D9A8: jal         0x80066210
    // 0x8002D9AC: sw          $zero, -0x2C94($at)
    MEM_W(-0X2C94, ctx->r1) = 0;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8002D9AC: sw          $zero, -0x2C94($at)
    MEM_W(-0X2C94, ctx->r1) = 0;
    after_0:
    // 0x8002D9B0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8002D9B4: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8002D9B8: jal         0x8000E988
    // 0x8002D9BC: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    objGetObjList(rdram, ctx);
        goto after_1;
    // 0x8002D9BC: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_1:
    // 0x8002D9C0: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8002D9C4: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x8002D9C8: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8002D9CC: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002D9D0: beq         $at, $zero, L_8002DDA0
    if (ctx->r1 == 0) {
        // 0x8002D9D4: addiu       $s7, $zero, 0x5
        ctx->r23 = ADD32(0, 0X5);
            goto L_8002DDA0;
    }
    // 0x8002D9D4: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
    // 0x8002D9D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002D9DC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002D9E0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8002D9E4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8002D9E8: addiu       $s5, $s5, -0x2F2C
    ctx->r21 = ADD32(ctx->r21, -0X2F2C);
    // 0x8002D9EC: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x8002D9F0: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x8002D9F4: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
L_8002D9F8:
    // 0x8002D9F8: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8002D9FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002DA00: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8002DA04: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x8002DA08: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8002DA0C: lw          $s2, 0x40($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X40);
    // 0x8002DA10: lw          $s0, 0x58($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X58);
    // 0x8002DA14: lw          $v0, 0x50($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X50);
    // 0x8002DA18: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x8002DA1C: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
    // 0x8002DA20: nop

    // 0x8002DA24: andi        $t0, $v1, 0x8000
    ctx->r8 = ctx->r3 & 0X8000;
    // 0x8002DA28: bne         $t0, $zero, L_8002DD8C
    if (ctx->r8 != 0) {
        // 0x8002DA2C: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DD8C;
    }
    // 0x8002DA2C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DA30: beq         $v0, $zero, L_8002DA70
    if (ctx->r2 == 0) {
        // 0x8002DA34: andi        $t2, $v1, 0x4000
        ctx->r10 = ctx->r3 & 0X4000;
            goto L_8002DA70;
    }
    // 0x8002DA34: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8002DA38: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002DA3C: nop

    // 0x8002DA40: c.lt.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl < ctx->f4.fl;
    // 0x8002DA44: nop

    // 0x8002DA48: bc1f        L_8002DA70
    if (!c1cs) {
        // 0x8002DA4C: andi        $t2, $v1, 0x4000
        ctx->r10 = ctx->r3 & 0X4000;
            goto L_8002DA70;
    }
    // 0x8002DA4C: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8002DA50: lh          $t1, 0x32($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X32);
    // 0x8002DA54: nop

    // 0x8002DA58: bne         $fp, $t1, L_8002DA70
    if (ctx->r30 != ctx->r9) {
        // 0x8002DA5C: andi        $t2, $v1, 0x4000
        ctx->r10 = ctx->r3 & 0X4000;
            goto L_8002DA70;
    }
    // 0x8002DA5C: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8002DA60: sh          $s3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r19;
    // 0x8002DA64: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
    // 0x8002DA68: nop

    // 0x8002DA6C: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
L_8002DA70:
    // 0x8002DA70: beq         $t2, $zero, L_8002DA7C
    if (ctx->r10 == 0) {
        // 0x8002DA74: nop
    
            goto L_8002DA7C;
    }
    // 0x8002DA74: nop

    // 0x8002DA78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002DA7C:
    // 0x8002DA7C: beq         $v0, $zero, L_8002DA94
    if (ctx->r2 == 0) {
        // 0x8002DA80: nop
    
            goto L_8002DA94;
    }
    // 0x8002DA80: nop

    // 0x8002DA84: lh          $t3, 0x32($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X32);
    // 0x8002DA88: nop

    // 0x8002DA8C: beq         $s4, $t3, L_8002DAAC
    if (ctx->r20 == ctx->r11) {
        // 0x8002DA90: nop
    
            goto L_8002DAAC;
    }
    // 0x8002DA90: nop

L_8002DA94:
    // 0x8002DA94: beq         $s0, $zero, L_8002DACC
    if (ctx->r16 == 0) {
        // 0x8002DA98: nop
    
            goto L_8002DACC;
    }
    // 0x8002DA98: nop

    // 0x8002DA9C: lh          $t4, 0x36($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X36);
    // 0x8002DAA0: nop

    // 0x8002DAA4: bne         $s4, $t4, L_8002DACC
    if (ctx->r20 != ctx->r12) {
        // 0x8002DAA8: nop
    
            goto L_8002DACC;
    }
    // 0x8002DAA8: nop

L_8002DAAC:
    // 0x8002DAAC: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8002DAB0: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8002DAB4: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x8002DAB8: jal         0x80066348
    // 0x8002DABC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    get_distance_to_active_camera(rdram, ctx);
        goto after_2;
    // 0x8002DABC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8002DAC0: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8002DAC4: b           L_8002DAD4
    // 0x8002DAC8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8002DAD4;
    // 0x8002DAC8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8002DACC:
    // 0x8002DACC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002DAD0: nop

L_8002DAD4:
    // 0x8002DAD4: beq         $v0, $zero, L_8002DC08
    if (ctx->r2 == 0) {
        // 0x8002DAD8: nop
    
            goto L_8002DC08;
    }
    // 0x8002DAD8: nop

    // 0x8002DADC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002DAE0: nop

    // 0x8002DAE4: c.lt.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl < ctx->f6.fl;
    // 0x8002DAE8: nop

    // 0x8002DAEC: bc1f        L_8002DC08
    if (!c1cs) {
        // 0x8002DAF0: nop
    
            goto L_8002DC08;
    }
    // 0x8002DAF0: nop

    // 0x8002DAF4: lh          $t5, 0x32($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X32);
    // 0x8002DAF8: nop

    // 0x8002DAFC: bne         $fp, $t5, L_8002DC08
    if (ctx->r30 != ctx->r13) {
        // 0x8002DB00: nop
    
            goto L_8002DC08;
    }
    // 0x8002DB00: nop

    // 0x8002DB04: swc1        $f24, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f24.u32l;
    // 0x8002DB08: sh          $s3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r19;
    // 0x8002DB0C: lh          $t7, 0x32($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X32);
    // 0x8002DB10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002DB14: bne         $s4, $t7, L_8002DB7C
    if (ctx->r20 != ctx->r15) {
        // 0x8002DB18: nop
    
            goto L_8002DB7C;
    }
    // 0x8002DB18: nop

    // 0x8002DB1C: blez        $s6, L_8002DB7C
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8002DB20: slti        $at, $s6, 0x4
        ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
            goto L_8002DB7C;
    }
    // 0x8002DB20: slti        $at, $s6, 0x4
    ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
    // 0x8002DB24: beq         $at, $zero, L_8002DB7C
    if (ctx->r1 == 0) {
        // 0x8002DB28: nop
    
            goto L_8002DB7C;
    }
    // 0x8002DB28: nop

    // 0x8002DB2C: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x8002DB30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DB34: bne         $v0, $at, L_8002DB64
    if (ctx->r2 != ctx->r1) {
        // 0x8002DB38: nop
    
            goto L_8002DB64;
    }
    // 0x8002DB38: nop

    // 0x8002DB3C: lw          $t8, 0x64($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X64);
    // 0x8002DB40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DB44: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
    // 0x8002DB48: nop

    // 0x8002DB4C: beq         $v0, $s3, L_8002DBE8
    if (ctx->r2 == ctx->r19) {
        // 0x8002DB50: nop
    
            goto L_8002DBE8;
    }
    // 0x8002DB50: nop

    // 0x8002DB54: jal         0x8002E234
    // 0x8002DB58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_generate(rdram, ctx);
        goto after_3;
    // 0x8002DB58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8002DB5C: b           L_8002DBE8
    // 0x8002DB60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8002DBE8;
    // 0x8002DB60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002DB64:
    // 0x8002DB64: bne         $s7, $v0, L_8002DBE8
    if (ctx->r23 != ctx->r2) {
        // 0x8002DB68: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8002DBE8;
    }
    // 0x8002DB68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DB6C: jal         0x8002E234
    // 0x8002DB70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_generate(rdram, ctx);
        goto after_4;
    // 0x8002DB70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8002DB74: b           L_8002DBE8
    // 0x8002DB78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8002DBE8;
    // 0x8002DB78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002DB7C:
    // 0x8002DB7C: lh          $v1, 0x4A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X4A);
    // 0x8002DB80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002DB84: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8002DB88: nop

    // 0x8002DB8C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002DB90: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8002DB94: nop

    // 0x8002DB98: bc1f        L_8002DBE8
    if (!c1cs) {
        // 0x8002DB9C: nop
    
            goto L_8002DBE8;
    }
    // 0x8002DB9C: nop

    // 0x8002DBA0: lh          $v0, 0x4C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4C);
    // 0x8002DBA4: nop

    // 0x8002DBA8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8002DBAC: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x8002DBB0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002DBB4: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8002DBB8: nop

    // 0x8002DBBC: bc1f        L_8002DBDC
    if (!c1cs) {
        // 0x8002DBC0: nop
    
            goto L_8002DBDC;
    }
    // 0x8002DBC0: nop

    // 0x8002DBC4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002DBC8: sub.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8002DBCC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002DBD0: nop

    // 0x8002DBD4: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8002DBD8: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
L_8002DBDC:
    // 0x8002DBDC: jal         0x8002E234
    // 0x8002DBE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_generate(rdram, ctx);
        goto after_5;
    // 0x8002DBE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8002DBE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002DBE8:
    // 0x8002DBE8: bne         $a0, $zero, L_8002DC08
    if (ctx->r4 != 0) {
        // 0x8002DBEC: nop
    
            goto L_8002DC08;
    }
    // 0x8002DBEC: nop

    // 0x8002DBF0: lw          $t9, 0x54($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X54);
    // 0x8002DBF4: nop

    // 0x8002DBF8: beq         $t9, $zero, L_8002DC08
    if (ctx->r25 == 0) {
        // 0x8002DBFC: nop
    
            goto L_8002DC08;
    }
    // 0x8002DBFC: nop

    // 0x8002DC00: jal         0x8002DE30
    // 0x8002DC04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002DE30(rdram, ctx);
        goto after_6;
    // 0x8002DC04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
L_8002DC08:
    // 0x8002DC08: beq         $s0, $zero, L_8002DD8C
    if (ctx->r16 == 0) {
        // 0x8002DC0C: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DD8C;
    }
    // 0x8002DC0C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DC10: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002DC14: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x8002DC18: c.lt.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl < ctx->f10.fl;
    // 0x8002DC1C: nop

    // 0x8002DC20: bc1f        L_8002DD8C
    if (!c1cs) {
        // 0x8002DC24: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DD8C;
    }
    // 0x8002DC24: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DC28: lh          $t1, 0x36($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X36);
    // 0x8002DC2C: nop

    // 0x8002DC30: bne         $t0, $t1, L_8002DD8C
    if (ctx->r8 != ctx->r9) {
        // 0x8002DC34: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DD8C;
    }
    // 0x8002DC34: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DC38: sh          $s3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r19;
    // 0x8002DC3C: swc1        $f24, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f24.u32l;
    // 0x8002DC40: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8002DC44: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x8002DC48: beq         $a0, $zero, L_8002DCB0
    if (ctx->r4 == 0) {
        // 0x8002DC4C: nop
    
            goto L_8002DCB0;
    }
    // 0x8002DC4C: nop

    // 0x8002DC50: beq         $t2, $zero, L_8002DCB0
    if (ctx->r10 == 0) {
        // 0x8002DC54: nop
    
            goto L_8002DCB0;
    }
    // 0x8002DC54: nop

    // 0x8002DC58: lhu         $t3, 0x12($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X12);
    // 0x8002DC5C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x8002DC60: beq         $t3, $at, L_8002DCB0
    if (ctx->r11 == ctx->r1) {
        // 0x8002DC64: nop
    
            goto L_8002DCB0;
    }
    // 0x8002DC64: nop

    // 0x8002DC68: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x8002DC6C: lh          $t5, 0xE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE);
    // 0x8002DC70: nop

    // 0x8002DC74: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8002DC78: sh          $t7, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r15;
    // 0x8002DC7C: lh          $v1, 0xC($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC);
    // 0x8002DC80: lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X12);
    // 0x8002DC84: nop

    // 0x8002DC88: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002DC8C: beq         $at, $zero, L_8002DCB0
    if (ctx->r1 == 0) {
        // 0x8002DC90: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_8002DCB0;
    }
    // 0x8002DC90: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_8002DC94:
    // 0x8002DC94: sh          $t8, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r24;
    // 0x8002DC98: lh          $v1, 0xC($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC);
    // 0x8002DC9C: lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X12);
    // 0x8002DCA0: nop

    // 0x8002DCA4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002DCA8: bne         $at, $zero, L_8002DC94
    if (ctx->r1 != 0) {
        // 0x8002DCAC: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_8002DC94;
    }
    // 0x8002DCAC: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_8002DCB0:
    // 0x8002DCB0: lh          $t6, 0x32($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X32);
    // 0x8002DCB4: nop

    // 0x8002DCB8: bne         $s4, $t6, L_8002DD20
    if (ctx->r20 != ctx->r14) {
        // 0x8002DCBC: nop
    
            goto L_8002DD20;
    }
    // 0x8002DCBC: nop

    // 0x8002DCC0: blez        $s6, L_8002DD20
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8002DCC4: slti        $at, $s6, 0x4
        ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
            goto L_8002DD20;
    }
    // 0x8002DCC4: slti        $at, $s6, 0x4
    ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
    // 0x8002DCC8: beq         $at, $zero, L_8002DD20
    if (ctx->r1 == 0) {
        // 0x8002DCCC: nop
    
            goto L_8002DD20;
    }
    // 0x8002DCCC: nop

    // 0x8002DCD0: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x8002DCD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DCD8: bne         $v0, $at, L_8002DD08
    if (ctx->r2 != ctx->r1) {
        // 0x8002DCDC: nop
    
            goto L_8002DD08;
    }
    // 0x8002DCDC: nop

    // 0x8002DCE0: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x8002DCE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002DCE8: lh          $v0, 0x0($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X0);
    // 0x8002DCEC: nop

    // 0x8002DCF0: beq         $v0, $s3, L_8002DD8C
    if (ctx->r2 == ctx->r19) {
        // 0x8002DCF4: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DD8C;
    }
    // 0x8002DCF4: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DCF8: jal         0x8002E234
    // 0x8002DCFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    shadow_generate(rdram, ctx);
        goto after_7;
    // 0x8002DCFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8002DD00: b           L_8002DD8C
    // 0x8002DD04: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
        goto L_8002DD8C;
    // 0x8002DD04: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
L_8002DD08:
    // 0x8002DD08: bne         $s7, $v0, L_8002DD88
    if (ctx->r23 != ctx->r2) {
        // 0x8002DD0C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8002DD88;
    }
    // 0x8002DD0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002DD10: jal         0x8002E234
    // 0x8002DD14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    shadow_generate(rdram, ctx);
        goto after_8;
    // 0x8002DD14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8002DD18: b           L_8002DD8C
    // 0x8002DD1C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
        goto L_8002DD8C;
    // 0x8002DD1C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
L_8002DD20:
    // 0x8002DD20: lh          $v1, 0x4A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X4A);
    // 0x8002DD24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002DD28: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8002DD2C: nop

    // 0x8002DD30: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002DD34: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8002DD38: nop

    // 0x8002DD3C: bc1f        L_8002DD8C
    if (!c1cs) {
        // 0x8002DD40: lw          $t1, 0x94($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X94);
            goto L_8002DD8C;
    }
    // 0x8002DD40: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8002DD44: lh          $v0, 0x4C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4C);
    // 0x8002DD48: nop

    // 0x8002DD4C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8002DD50: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    // 0x8002DD54: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002DD58: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x8002DD5C: nop

    // 0x8002DD60: bc1f        L_8002DD80
    if (!c1cs) {
        // 0x8002DD64: nop
    
            goto L_8002DD80;
    }
    // 0x8002DD64: nop

    // 0x8002DD68: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8002DD6C: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8002DD70: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002DD74: nop

    // 0x8002DD78: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002DD7C: swc1        $f16, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f16.u32l;
L_8002DD80:
    // 0x8002DD80: jal         0x8002E234
    // 0x8002DD84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    shadow_generate(rdram, ctx);
        goto after_9;
    // 0x8002DD84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_8002DD88:
    // 0x8002DD88: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
L_8002DD8C:
    // 0x8002DD8C: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x8002DD90: nop

    // 0x8002DD94: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002DD98: bne         $at, $zero, L_8002D9F8
    if (ctx->r1 != 0) {
        // 0x8002DD9C: lw          $t6, 0x94($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X94);
            goto L_8002D9F8;
    }
    // 0x8002DD9C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
L_8002DDA0:
    // 0x8002DDA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002DDA4: addiu       $v1, $v1, -0x2C9C
    ctx->r3 = ADD32(ctx->r3, -0X2C9C);
    // 0x8002DDA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002DDAC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8002DDB0: addiu       $v0, $v0, -0x2CA0
    ctx->r2 = ADD32(ctx->r2, -0X2CA0);
    // 0x8002DDB4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8002DDB8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8002DDBC: lw          $t3, -0x2C98($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2C98);
    // 0x8002DDC0: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x8002DDC4: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8002DDC8: sh          $t3, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r11;
    // 0x8002DDCC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8002DDD0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002DDD4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002DDD8: lw          $t6, -0x2C94($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2C94);
    // 0x8002DDDC: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8002DDE0: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8002DDE4: sh          $t6, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r14;
    // 0x8002DDE8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002DDEC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002DDF0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002DDF4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002DDF8: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002DDFC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002DE00: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002DE04: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002DE08: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002DE0C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002DE10: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002DE14: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002DE18: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002DE1C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002DE20: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002DE24: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002DE28: jr          $ra
    // 0x8002DE2C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8002DE2C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void gzip_inflate_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6DDC: addiu       $sp, $sp, -0x530
    ctx->r29 = ADD32(ctx->r29, -0X530);
    // 0x800C6DE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C6DE4: addi        $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x800C6DE8: addiu       $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
    // 0x800C6DEC: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_800C6DF0:
    // 0x800C6DF0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C6DF4: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C6DF8: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C6DFC: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C6E00: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C6E04: bne         $t0, $zero, L_800C6DF0
    if (ctx->r8 != 0) {
        // 0x800C6E08: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_800C6DF0;
    }
    // 0x800C6E08: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x800C6E0C: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x800C6E10: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
L_800C6E14:
    // 0x800C6E14: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C6E18: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C6E1C: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C6E20: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C6E24: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C6E28: bne         $t0, $zero, L_800C6E14
    if (ctx->r8 != 0) {
        // 0x800C6E2C: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_800C6E14;
    }
    // 0x800C6E2C: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x800C6E30: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800C6E34: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
L_800C6E38:
    // 0x800C6E38: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C6E3C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C6E40: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C6E44: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C6E48: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C6E4C: bne         $t0, $zero, L_800C6E38
    if (ctx->r8 != 0) {
        // 0x800C6E50: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_800C6E38;
    }
    // 0x800C6E50: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x800C6E54: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800C6E58: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C6E5C: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C6E60: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C6E64: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x800C6E68: sw          $t1, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r9;
    // 0x800C6E6C: sw          $t1, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r9;
    // 0x800C6E70: sw          $t1, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r9;
    // 0x800C6E74: sw          $t1, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r9;
    // 0x800C6E78: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800C6E7C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800C6E80: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C6E84: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C6E88: addiu       $v0, $v0, -0x6BEE
    ctx->r2 = ADD32(ctx->r2, -0X6BEE);
    // 0x800C6E8C: addi        $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x800C6E90: addi        $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800C6E94: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C6E98: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x800C6E9C: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x800C6EA0: addiu       $a3, $a3, -0x6C2C
    ctx->r7 = ADD32(ctx->r7, -0X6C2C);
    // 0x800C6EA4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C6EA8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C6EAC: jal         0x800C6274
    // 0x800C6EB0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_0;
    // 0x800C6EB0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x800C6EB4: addi        $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x800C6EB8: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800C6EBC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
L_800C6EC0:
    // 0x800C6EC0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800C6EC4: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800C6EC8: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800C6ECC: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x800C6ED0: bne         $t0, $zero, L_800C6EC0
    if (ctx->r8 != 0) {
        // 0x800C6ED4: addiu       $t3, $t3, 0xC
        ctx->r11 = ADD32(ctx->r11, 0XC);
            goto L_800C6EC0;
    }
    // 0x800C6ED4: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800C6ED8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C6EDC: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C6EE0: addiu       $v0, $v0, -0x6B92
    ctx->r2 = ADD32(ctx->r2, -0X6B92);
    // 0x800C6EE4: addi        $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // 0x800C6EE8: addi        $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x800C6EEC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x800C6EF0: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C6EF4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800C6EF8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C6EFC: addiu       $a3, $a3, -0x6BCE
    ctx->r7 = ADD32(ctx->r7, -0X6BCE);
    // 0x800C6F00: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C6F04: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C6F08: jal         0x800C6274
    // 0x800C6F0C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_1;
    // 0x800C6F0C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_1:
    // 0x800C6F10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C6F14: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800C6F18: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C6F1C: jal         0x800C7040
    // 0x800C6F20: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    gzip_inflate_codes(rdram, ctx);
        goto after_2;
    // 0x800C6F20: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800C6F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6F28: addiu       $sp, $sp, 0x530
    ctx->r29 = ADD32(ctx->r29, 0X530);
    // 0x800C6F2C: jr          $ra
    // 0x800C6F30: nop

    return;
    // 0x800C6F30: nop

;}
RECOMP_FUNC void get_save_file_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C1A0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C1A4: lw          $v0, -0xB34($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB34);
    // 0x8009C1A8: jr          $ra
    // 0x8009C1AC: nop

    return;
    // 0x8009C1AC: nop

;}
RECOMP_FUNC void filename_decompress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800976F8: addu        $t6, $a1, $a2
    ctx->r14 = ADD32(ctx->r5, ctx->r6);
    // 0x800976FC: addiu       $v1, $a2, -0x1
    ctx->r3 = ADD32(ctx->r6, -0X1);
    // 0x80097700: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80097704: bltz        $v1, L_8009773C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80097708: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8009773C;
    }
    // 0x80097708: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009770C: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80097710: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80097714: addiu       $a1, $a1, 0xF6C
    ctx->r5 = ADD32(ctx->r5, 0XF6C);
L_80097718:
    // 0x80097718: andi        $t7, $a0, 0x1F
    ctx->r15 = ctx->r4 & 0X1F;
    // 0x8009771C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80097720: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80097724: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80097728: srl         $t0, $a0, 5
    ctx->r8 = S32(U32(ctx->r4) >> 5);
    // 0x8009772C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80097730: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80097734: bgez        $v0, L_80097718
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80097738: sb          $t9, 0x1($v1)
        MEM_B(0X1, ctx->r3) = ctx->r25;
            goto L_80097718;
    }
    // 0x80097738: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
L_8009773C:
    // 0x8009773C: jr          $ra
    // 0x80097740: nop

    return;
    // 0x80097740: nop

;}
RECOMP_FUNC void free_3d_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FF40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FF48: beq         $a0, $zero, L_80060048
    if (ctx->r4 == 0) {
        // 0x8005FF4C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80060048;
    }
    // 0x8005FF4C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005FF50: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8005FF54: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005FF58: lh          $t6, 0x30($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X30);
    // 0x8005FF5C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005FF60: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8005FF64: sh          $t7, 0x30($a1)
    MEM_H(0X30, ctx->r5) = ctx->r15;
    // 0x8005FF68: lh          $t8, 0x30($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X30);
    // 0x8005FF6C: nop

    // 0x8005FF70: blez        $t8, L_8005FF88
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005FF74: nop
    
            goto L_8005FF88;
    }
    // 0x8005FF74: nop

    // 0x8005FF78: jal         0x80071140
    // 0x8005FF7C: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8005FF7C: nop

    after_0:
    // 0x8005FF80: b           L_8006004C
    // 0x8005FF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006004C;
    // 0x8005FF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FF88:
    // 0x8005FF88: lw          $v1, -0x29D4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X29D4);
    // 0x8005FF8C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005FF90: blez        $v1, L_8005FFD0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005FF94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005FFD0;
    }
    // 0x8005FF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005FF98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005FF9C: lw          $a0, -0x29DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X29DC);
    // 0x8005FFA0: nop

    // 0x8005FFA4: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
L_8005FFA8:
    // 0x8005FFA8: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x8005FFAC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8005FFB0: nop

    // 0x8005FFB4: bne         $a1, $t3, L_8005FFC0
    if (ctx->r5 != ctx->r11) {
        // 0x8005FFB8: nop
    
            goto L_8005FFC0;
    }
    // 0x8005FFB8: nop

    // 0x8005FFBC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8005FFC0:
    // 0x8005FFC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005FFC4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005FFC8: bne         $at, $zero, L_8005FFA8
    if (ctx->r1 != 0) {
        // 0x8005FFCC: sll         $t1, $v0, 3
        ctx->r9 = S32(ctx->r2 << 3);
            goto L_8005FFA8;
    }
    // 0x8005FFCC: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
L_8005FFD0:
    // 0x8005FFD0: beq         $a2, $t0, L_80060048
    if (ctx->r6 == ctx->r8) {
        // 0x8005FFD4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80060048;
    }
    // 0x8005FFD4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8005FFD8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8005FFDC: jal         0x80060058
    // 0x8005FFE0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    free_model_data(rdram, ctx);
        goto after_1;
    // 0x8005FFE0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x8005FFE4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005FFE8: addiu       $v1, $v1, -0x29CC
    ctx->r3 = ADD32(ctx->r3, -0X29CC);
    // 0x8005FFEC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8005FFF0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8005FFF4: lw          $t4, -0x29D8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X29D8);
    // 0x8005FFF8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8005FFFC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80060000: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80060004: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80060008: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006000C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80060010: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80060014: addiu       $a1, $a1, -0x29DC
    ctx->r5 = ADD32(ctx->r5, -0X29DC);
    // 0x80060018: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8006001C: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x80060020: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80060024: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80060028: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006002C: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x80060030: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x80060034: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80060038: nop

    // 0x8006003C: addu        $t4, $t5, $t1
    ctx->r12 = ADD32(ctx->r13, ctx->r9);
    // 0x80060040: jal         0x80071140
    // 0x80060044: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80060044: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    after_2:
L_80060048:
    // 0x80060048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006004C:
    // 0x8006004C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80060050: jr          $ra
    // 0x80060054: nop

    return;
    // 0x80060054: nop

;}
RECOMP_FUNC void func_8004F7F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F7F4: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8004F7F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004F7FC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004F800: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004F804: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x8004F808: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x8004F80C: sb          $zero, 0x53($sp)
    MEM_B(0X53, ctx->r29) = 0;
    // 0x8004F810: lb          $t6, 0x1D2($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1D2);
    // 0x8004F814: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8004F818: beq         $t6, $zero, L_8004F83C
    if (ctx->r14 == 0) {
        // 0x8004F81C: or          $s1, $a2, $zero
        ctx->r17 = ctx->r6 | 0;
            goto L_8004F83C;
    }
    // 0x8004F81C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8004F820: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004F824: addiu       $a0, $a0, -0x2AD8
    ctx->r4 = ADD32(ctx->r4, -0X2AD8);
    // 0x8004F828: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8004F82C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004F830: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004F834: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8004F838: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_8004F83C:
    // 0x8004F83C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004F840: lw          $t9, -0x2AA4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AA4);
    // 0x8004F844: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004F848: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F84C: beq         $t9, $at, L_8004F864
    if (ctx->r25 == ctx->r1) {
        // 0x8004F850: addiu       $a0, $a0, -0x2AD8
        ctx->r4 = ADD32(ctx->r4, -0X2AD8);
            goto L_8004F864;
    }
    // 0x8004F850: addiu       $a0, $a0, -0x2AD8
    ctx->r4 = ADD32(ctx->r4, -0X2AD8);
    // 0x8004F854: lb          $t0, 0x1D8($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D8);
    // 0x8004F858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004F85C: beq         $t0, $zero, L_8004F880
    if (ctx->r8 == 0) {
        // 0x8004F860: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8004F880;
    }
    // 0x8004F860: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8004F864:
    // 0x8004F864: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004F868: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x8004F86C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F870: jal         0x80054110
    // 0x8004F874: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_onscreen_AI_racer(rdram, ctx);
        goto after_0;
    // 0x8004F874: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8004F878: b           L_80050744
    // 0x8004F87C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80050744;
    // 0x8004F87C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004F880:
    // 0x8004F880: lb          $t1, 0x1D4($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004F884: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004F888: beq         $t1, $zero, L_8004F8C0
    if (ctx->r9 == 0) {
        // 0x8004F88C: addiu       $v1, $v1, -0x2AD4
        ctx->r3 = ADD32(ctx->r3, -0X2AD4);
            goto L_8004F8C0;
    }
    // 0x8004F88C: addiu       $v1, $v1, -0x2AD4
    ctx->r3 = ADD32(ctx->r3, -0X2AD4);
    // 0x8004F890: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8004F894: addiu       $at, $zero, -0x2011
    ctx->r1 = ADD32(0, -0X2011);
    // 0x8004F898: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8004F89C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8004F8A0: lb          $v0, 0x1D4($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004F8A4: nop

    // 0x8004F8A8: blez        $v0, L_8004F8BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004F8AC: addiu       $t5, $v0, 0x4
        ctx->r13 = ADD32(ctx->r2, 0X4);
            goto L_8004F8BC;
    }
    // 0x8004F8AC: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x8004F8B0: addiu       $t4, $v0, -0x4
    ctx->r12 = ADD32(ctx->r2, -0X4);
    // 0x8004F8B4: b           L_8004F8C0
    // 0x8004F8B8: sb          $t4, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r12;
        goto L_8004F8C0;
    // 0x8004F8B8: sb          $t4, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r12;
L_8004F8BC:
    // 0x8004F8BC: sb          $t5, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r13;
L_8004F8C0:
    // 0x8004F8C0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004F8C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004F8C8: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8004F8CC: beq         $t7, $zero, L_8004F904
    if (ctx->r15 == 0) {
        // 0x8004F8D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8004F904;
    }
    // 0x8004F8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004F8D4: lb          $v0, 0x1E6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004F8D8: nop

    // 0x8004F8DC: beq         $v0, $zero, L_8004F904
    if (ctx->r2 == 0) {
        // 0x8004F8E0: nop
    
            goto L_8004F904;
    }
    // 0x8004F8E0: nop

    // 0x8004F8E4: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8004F8E8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004F8EC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004F8F0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004F8F4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004F8F8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8004F8FC: b           L_8004F904
    // 0x8004F900: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
        goto L_8004F904;
    // 0x8004F900: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
L_8004F904:
    // 0x8004F904: lbu         $t8, 0x1FE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004F908: nop

    // 0x8004F90C: bne         $t8, $zero, L_8004F928
    if (ctx->r24 != 0) {
        // 0x8004F910: lw          $a1, 0xC0($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XC0);
            goto L_8004F928;
    }
    // 0x8004F910: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x8004F914: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x8004F918: nop

    // 0x8004F91C: ori         $t0, $t9, 0x400
    ctx->r8 = ctx->r25 | 0X400;
    // 0x8004F920: sw          $t0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r8;
    // 0x8004F924: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
L_8004F928:
    // 0x8004F928: jal         0x80050850
    // 0x8004F92C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    apply_vehicle_rotation_offset(rdram, ctx);
        goto after_1;
    // 0x8004F92C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_1:
    // 0x8004F930: lw          $a2, 0xC4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC4);
    // 0x8004F934: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F938: jal         0x80053750
    // 0x8004F93C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80053750(rdram, ctx);
        goto after_2;
    // 0x8004F93C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8004F940: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004F944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F948: jal         0x800521C4
    // 0x8004F94C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    handle_racer_head_turning(rdram, ctx);
        goto after_3;
    // 0x8004F94C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8004F950: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F954: sh          $zero, -0x2AB0($at)
    MEM_H(-0X2AB0, ctx->r1) = 0;
    // 0x8004F958: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F95C: sw          $zero, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = 0;
    // 0x8004F960: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F964: sw          $zero, -0x2AA8($at)
    MEM_W(-0X2AA8, ctx->r1) = 0;
    // 0x8004F968: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004F96C: nop

    // 0x8004F970: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x8004F974: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004F978: nop

    // 0x8004F97C: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x8004F980: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004F984: nop

    // 0x8004F988: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x8004F98C: lb          $v0, 0x1E6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004F990: nop

    // 0x8004F994: beq         $v0, $zero, L_8004FB38
    if (ctx->r2 == 0) {
        // 0x8004F998: nop
    
            goto L_8004FB38;
    }
    // 0x8004F998: nop

    // 0x8004F99C: bgez        $v0, L_8004F9EC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004F9A0: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8004F9EC;
    }
    // 0x8004F9A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004F9A4: addiu       $a2, $a2, -0x2ACC
    ctx->r6 = ADD32(ctx->r6, -0X2ACC);
    // 0x8004F9A8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8004F9AC: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
    // 0x8004F9B0: slti        $at, $t1, 0x1A
    ctx->r1 = SIGNED(ctx->r9) < 0X1A ? 1 : 0;
    // 0x8004F9B4: bne         $at, $zero, L_8004F9EC
    if (ctx->r1 != 0) {
        // 0x8004F9B8: nop
    
            goto L_8004F9EC;
    }
    // 0x8004F9B8: nop

    // 0x8004F9BC: lh          $t2, 0x16E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X16E);
    // 0x8004F9C0: nop

    // 0x8004F9C4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004F9C8: sh          $t4, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = ctx->r12;
    // 0x8004F9CC: lh          $v0, 0x16E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X16E);
    // 0x8004F9D0: nop

    // 0x8004F9D4: bgez        $v0, L_8004FA48
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004F9D8: nop
    
            goto L_8004FA48;
    }
    // 0x8004F9D8: nop

    // 0x8004F9DC: sh          $zero, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = 0;
    // 0x8004F9E0: lh          $v0, 0x16E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X16E);
    // 0x8004F9E4: b           L_8004FA4C
    // 0x8004F9E8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
        goto L_8004FA4C;
    // 0x8004F9E8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_8004F9EC:
    // 0x8004F9EC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004F9F0: blez        $v0, L_8004FA3C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004F9F4: addiu       $a2, $a2, -0x2ACC
        ctx->r6 = ADD32(ctx->r6, -0X2ACC);
            goto L_8004FA3C;
    }
    // 0x8004F9F4: addiu       $a2, $a2, -0x2ACC
    ctx->r6 = ADD32(ctx->r6, -0X2ACC);
    // 0x8004F9F8: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8004F9FC: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FA00: slti        $at, $t5, -0x19
    ctx->r1 = SIGNED(ctx->r13) < -0X19 ? 1 : 0;
    // 0x8004FA04: beq         $at, $zero, L_8004FA3C
    if (ctx->r1 == 0) {
        // 0x8004FA08: nop
    
            goto L_8004FA3C;
    }
    // 0x8004FA08: nop

    // 0x8004FA0C: lh          $t6, 0x16E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA10: nop

    // 0x8004FA14: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8004FA18: sh          $t8, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = ctx->r24;
    // 0x8004FA1C: lh          $v0, 0x16E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA20: nop

    // 0x8004FA24: blez        $v0, L_8004FA48
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004FA28: nop
    
            goto L_8004FA48;
    }
    // 0x8004FA28: nop

    // 0x8004FA2C: sh          $zero, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = 0;
    // 0x8004FA30: lh          $v0, 0x16E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA34: b           L_8004FA4C
    // 0x8004FA38: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
        goto L_8004FA4C;
    // 0x8004FA38: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_8004FA3C:
    // 0x8004FA3C: sh          $zero, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = 0;
    // 0x8004FA40: lh          $v0, 0x16E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X16E);
    // 0x8004FA44: nop

L_8004FA48:
    // 0x8004FA48: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_8004FA4C:
    // 0x8004FA4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004FA50: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004FA54: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8004FA58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004FA5C: swc1        $f16, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f16.u32l;
    // 0x8004FA60: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004FA64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FA68: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8004FA6C: nop

    // 0x8004FA70: bc1f        L_8004FA80
    if (!c1cs) {
        // 0x8004FA74: nop
    
            goto L_8004FA80;
    }
    // 0x8004FA74: nop

    // 0x8004FA78: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x8004FA7C: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
L_8004FA80:
    // 0x8004FA80: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004FA84: nop

    // 0x8004FA88: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8004FA8C: nop

    // 0x8004FA90: bc1f        L_8004FAB8
    if (!c1cs) {
        // 0x8004FA94: nop
    
            goto L_8004FAB8;
    }
    // 0x8004FA94: nop

    // 0x8004FA98: jal         0x80057048
    // 0x8004FA9C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    racer_play_sound(rdram, ctx);
        goto after_4;
    // 0x8004FA9C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_4:
    // 0x8004FAA0: lb          $t9, 0x1E6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004FAA4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004FAA8: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8004FAAC: addiu       $a2, $a2, -0x2ACC
    ctx->r6 = ADD32(ctx->r6, -0X2ACC);
    // 0x8004FAB0: sb          $t0, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r8;
    // 0x8004FAB4: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
L_8004FAB8:
    // 0x8004FAB8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8004FABC: nop

    // 0x8004FAC0: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x8004FAC4: bne         $at, $zero, L_8004FAD8
    if (ctx->r1 != 0) {
        // 0x8004FAC8: slti        $at, $v1, -0x32
        ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
            goto L_8004FAD8;
    }
    // 0x8004FAC8: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
    // 0x8004FACC: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x8004FAD0: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8004FAD4: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
L_8004FAD8:
    // 0x8004FAD8: beq         $at, $zero, L_8004FAE8
    if (ctx->r1 == 0) {
        // 0x8004FADC: nop
    
            goto L_8004FAE8;
    }
    // 0x8004FADC: nop

    // 0x8004FAE0: addiu       $v1, $zero, -0x32
    ctx->r3 = ADD32(0, -0X32);
    // 0x8004FAE4: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
L_8004FAE8:
    // 0x8004FAE8: blez        $v1, L_8004FB00
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004FAEC: nop
    
            goto L_8004FB00;
    }
    // 0x8004FAEC: nop

    // 0x8004FAF0: lb          $t3, 0x1E6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004FAF4: nop

    // 0x8004FAF8: bgtz        $t3, L_8004FB14
    if (SIGNED(ctx->r11) > 0) {
        // 0x8004FAFC: sra         $t4, $v1, 2
        ctx->r12 = S32(SIGNED(ctx->r3) >> 2);
            goto L_8004FB14;
    }
    // 0x8004FAFC: sra         $t4, $v1, 2
    ctx->r12 = S32(SIGNED(ctx->r3) >> 2);
L_8004FB00:
    // 0x8004FB00: lb          $v0, 0x1E6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004FB04: bgez        $v1, L_8004FB24
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004FB08: sll         $t5, $v0, 4
        ctx->r13 = S32(ctx->r2 << 4);
            goto L_8004FB24;
    }
    // 0x8004FB08: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x8004FB0C: bgez        $v0, L_8004FB20
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004FB10: sra         $t4, $v1, 2
        ctx->r12 = S32(SIGNED(ctx->r3) >> 2);
            goto L_8004FB20;
    }
    // 0x8004FB10: sra         $t4, $v1, 2
    ctx->r12 = S32(SIGNED(ctx->r3) >> 2);
L_8004FB14:
    // 0x8004FB14: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8004FB18: lb          $v0, 0x1E6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E6);
    // 0x8004FB1C: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_8004FB20:
    // 0x8004FB20: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
L_8004FB24:
    // 0x8004FB24: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8004FB28: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8004FB2C: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8004FB30: b           L_8004FB3C
    // 0x8004FB34: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
        goto L_8004FB3C;
    // 0x8004FB34: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_8004FB38:
    // 0x8004FB38: sh          $zero, 0x16E($s0)
    MEM_H(0X16E, ctx->r16) = 0;
L_8004FB3C:
    // 0x8004FB3C: lw          $a2, 0xC4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC4);
    // 0x8004FB40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004FB44: jal         0x800579B0
    // 0x8004FB48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    handle_base_steering(rdram, ctx);
        goto after_5;
    // 0x8004FB48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8004FB4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FB50: jal         0x800575EC
    // 0x8004FB54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800575EC(rdram, ctx);
        goto after_6;
    // 0x8004FB54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8004FB58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FB5C: jal         0x800535C4
    // 0x8004FB60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800535C4(rdram, ctx);
        goto after_7;
    // 0x8004FB60: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8004FB64: jal         0x80053664
    // 0x8004FB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    handle_car_velocity_control(rdram, ctx);
        goto after_8;
    // 0x8004FB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8004FB6C: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FB70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FB74: jal         0x80055EC0
    // 0x8004FB78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    handle_racer_items(rdram, ctx);
        goto after_9;
    // 0x8004FB78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x8004FB7C: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FB80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FB84: jal         0x80053E9C
    // 0x8004FB88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_attack_handler_car(rdram, ctx);
        goto after_10;
    // 0x8004FB88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x8004FB8C: lb          $t7, 0x1DB($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004FB90: nop

    // 0x8004FB94: beq         $t7, $zero, L_8004FBB8
    if (ctx->r15 == 0) {
        // 0x8004FB98: nop
    
            goto L_8004FBB8;
    }
    // 0x8004FB98: nop

    // 0x8004FB9C: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FBA0: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x8004FBA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FBA8: jal         0x80052B64
    // 0x8004FBAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_spinout_car(rdram, ctx);
        goto after_11;
    // 0x8004FBAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8004FBB0: b           L_8004FBF4
    // 0x8004FBB4: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
        goto L_8004FBF4;
    // 0x8004FBB4: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
L_8004FBB8:
    // 0x8004FBB8: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004FBBC: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FBC0: blez        $t8, L_8004FBE4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8004FBC4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004FBE4;
    }
    // 0x8004FBC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FBC8: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FBCC: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x8004FBD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FBD4: jal         0x80050A28
    // 0x8004FBD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80050A28(rdram, ctx);
        goto after_12;
    // 0x8004FBD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x8004FBDC: b           L_8004FBF4
    // 0x8004FBE0: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
        goto L_8004FBF4;
    // 0x8004FBE0: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
L_8004FBE4:
    // 0x8004FBE4: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x8004FBE8: jal         0x80052D7C
    // 0x8004FBEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_car_velocity_offground(rdram, ctx);
        goto after_13;
    // 0x8004FBEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x8004FBF0: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
L_8004FBF4:
    // 0x8004FBF4: nop

    // 0x8004FBF8: beq         $v0, $zero, L_8004FC0C
    if (ctx->r2 == 0) {
        // 0x8004FBFC: nop
    
            goto L_8004FC0C;
    }
    // 0x8004FBFC: nop

    // 0x8004FC00: jal         0x8000488C
    // 0x8004FC04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_14;
    // 0x8004FC04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x8004FC08: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
L_8004FC0C:
    // 0x8004FC0C: lwc1        $f0, 0xC0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004FC10: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004FC14: nop

    // 0x8004FC18: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x8004FC1C: nop

    // 0x8004FC20: bc1t        L_8004FC84
    if (c1cs) {
        // 0x8004FC24: nop
    
            goto L_8004FC84;
    }
    // 0x8004FC24: nop

    // 0x8004FC28: lb          $t9, 0x1D7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004FC2C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8004FC30: beq         $t9, $at, L_8004FC84
    if (ctx->r25 == ctx->r1) {
        // 0x8004FC34: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_8004FC84;
    }
    // 0x8004FC34: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8004FC38: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004FC3C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004FC40: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8004FC44: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x8004FC48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FC4C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8004FC50: lwc1        $f17, 0x6600($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6600);
    // 0x8004FC54: lwc1        $f16, 0x6604($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6604);
    // 0x8004FC58: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004FC5C: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8004FC60: lwc1        $f18, 0xC4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8004FC64: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
    // 0x8004FC68: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8004FC6C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004FC70: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8004FC74: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8004FC78: add.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d + ctx->f8.d;
    // 0x8004FC7C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8004FC80: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
L_8004FC84:
    // 0x8004FC84: jal         0x8006BDB0
    // 0x8004FC88: nop

    level_header(rdram, ctx);
        goto after_15;
    // 0x8004FC88: nop

    after_15:
    // 0x8004FC8C: lwc1        $f10, 0xC0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004FC90: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8004FC94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004FC98: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8004FC9C: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x8004FCA0: nop

    // 0x8004FCA4: bc1t        L_8004FCB8
    if (c1cs) {
        // 0x8004FCA8: nop
    
            goto L_8004FCB8;
    }
    // 0x8004FCA8: nop

    // 0x8004FCAC: lb          $t0, 0x2($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X2);
    // 0x8004FCB0: nop

    // 0x8004FCB4: bne         $t0, $zero, L_8004FCCC
    if (ctx->r8 != 0) {
        // 0x8004FCB8: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8004FCCC;
    }
L_8004FCB8:
    // 0x8004FCB8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004FCBC: lb          $t1, -0x2A7F($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X2A7F);
    // 0x8004FCC0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004FCC4: bne         $t1, $at, L_8004FE04
    if (ctx->r9 != ctx->r1) {
        // 0x8004FCC8: nop
    
            goto L_8004FE04;
    }
    // 0x8004FCC8: nop

L_8004FCCC:
    // 0x8004FCCC: lbu         $t2, 0x1F0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1F0);
    // 0x8004FCD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FCD4: beq         $t2, $zero, L_8004FD00
    if (ctx->r10 == 0) {
        // 0x8004FCD8: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8004FD00;
    }
    // 0x8004FCD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004FCDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FCE0: lwc1        $f8, 0xA8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FCE4: lwc1        $f5, 0x6608($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6608);
    // 0x8004FCE8: lwc1        $f4, 0x660C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X660C);
    // 0x8004FCEC: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8004FCF0: sub.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f18.d - ctx->f4.d;
    // 0x8004FCF4: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8004FCF8: b           L_8004FD20
    // 0x8004FCFC: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
        goto L_8004FD20;
    // 0x8004FCFC: swc1        $f6, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f6.u32l;
L_8004FD00:
    // 0x8004FD00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FD04: lwc1        $f16, 0xA8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FD08: lwc1        $f19, 0x6610($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6610);
    // 0x8004FD0C: lwc1        $f18, 0x6614($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6614);
    // 0x8004FD10: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8004FD14: sub.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f8.d - ctx->f18.d;
    // 0x8004FD18: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8004FD1C: swc1        $f10, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f10.u32l;
L_8004FD20:
    // 0x8004FD20: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x8004FD24: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8004FD28: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    // 0x8004FD2C: jal         0x80059080
    // 0x8004FD30: addiu       $a3, $sp, 0xB0
    ctx->r7 = ADD32(ctx->r29, 0XB0);
    set_position_goal_from_path(rdram, ctx);
        goto after_16;
    // 0x8004FD30: addiu       $a3, $sp, 0xB0
    ctx->r7 = ADD32(ctx->r29, 0XB0);
    after_16:
    // 0x8004FD34: lbu         $t4, 0x1F0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1F0);
    // 0x8004FD38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FD3C: beq         $t4, $zero, L_8004FD68
    if (ctx->r12 == 0) {
        // 0x8004FD40: nop
    
            goto L_8004FD68;
    }
    // 0x8004FD40: nop

    // 0x8004FD44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FD48: lwc1        $f6, 0xA8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FD4C: lwc1        $f9, 0x6618($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6618);
    // 0x8004FD50: lwc1        $f8, 0x661C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X661C);
    // 0x8004FD54: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8004FD58: add.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d + ctx->f8.d;
    // 0x8004FD5C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8004FD60: b           L_8004FD84
    // 0x8004FD64: swc1        $f4, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f4.u32l;
        goto L_8004FD84;
    // 0x8004FD64: swc1        $f4, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f4.u32l;
L_8004FD68:
    // 0x8004FD68: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004FD6C: lwc1        $f17, 0x6620($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6620);
    // 0x8004FD70: lwc1        $f16, 0x6624($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6624);
    // 0x8004FD74: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8004FD78: add.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f6.d + ctx->f16.d;
    // 0x8004FD7C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8004FD80: swc1        $f18, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f18.u32l;
L_8004FD84:
    // 0x8004FD84: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004FD88: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004FD8C: lwc1        $f16, 0xB4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8004FD90: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8004FD94: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x8004FD98: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004FD9C: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8004FDA0: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8004FDA4: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
    // 0x8004FDA8: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8004FDAC: jal         0x800C9AD0
    // 0x8004FDB0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_17;
    // 0x8004FDB0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_17:
    // 0x8004FDB4: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004FDB8: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8004FDBC: div.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004FDC0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004FDC4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004FDC8: swc1        $f0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
    // 0x8004FDCC: lui         $at, 0x4118
    ctx->r1 = S32(0X4118 << 16);
    // 0x8004FDD0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004FDD4: div.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004FDD8: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004FDDC: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
    // 0x8004FDE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004FDE4: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
    // 0x8004FDE8: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x8004FDEC: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8004FDF0: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x8004FDF4: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8004FDF8: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
    // 0x8004FDFC: b           L_8004FE1C
    // 0x8004FE00: sb          $t5, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = ctx->r13;
        goto L_8004FE1C;
    // 0x8004FE00: sb          $t5, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = ctx->r13;
L_8004FE04:
    // 0x8004FE04: lb          $t6, 0x1E2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004FE08: nop

    // 0x8004FE0C: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8004FE10: bne         $at, $zero, L_8004FE1C
    if (ctx->r1 != 0) {
        // 0x8004FE14: nop
    
            goto L_8004FE1C;
    }
    // 0x8004FE14: nop

    // 0x8004FE18: sb          $zero, 0x1F0($s0)
    MEM_B(0X1F0, ctx->r16) = 0;
L_8004FE1C:
    // 0x8004FE1C: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x8004FE20: nop

    // 0x8004FE24: bne         $t7, $zero, L_8004FE3C
    if (ctx->r15 != 0) {
        // 0x8004FE28: nop
    
            goto L_8004FE3C;
    }
    // 0x8004FE28: nop

    // 0x8004FE2C: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FE30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004FE34: jal         0x8005250C
    // 0x8004FE38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8005250C(rdram, ctx);
        goto after_18;
    // 0x8004FE38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
L_8004FE3C:
    // 0x8004FE3C: lh          $a1, 0x1A2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004FE40: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004FE44: lw          $t8, -0x2AAC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AAC);
    // 0x8004FE48: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x8004FE4C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004FE50: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x8004FE54: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004FE58: lw          $t1, 0xC0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FE5C: bne         $at, $zero, L_8004FE6C
    if (ctx->r1 != 0) {
        // 0x8004FE60: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004FE6C;
    }
    // 0x8004FE60: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004FE64: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004FE68: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004FE6C:
    // 0x8004FE6C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004FE70: beq         $at, $zero, L_8004FE7C
    if (ctx->r1 == 0) {
        // 0x8004FE74: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004FE7C;
    }
    // 0x8004FE74: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004FE78: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004FE7C:
    // 0x8004FE7C: sra         $t0, $v1, 2
    ctx->r8 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8004FE80: slti        $at, $t0, 0x2EF
    ctx->r1 = SIGNED(ctx->r8) < 0X2EF ? 1 : 0;
    // 0x8004FE84: bne         $at, $zero, L_8004FE90
    if (ctx->r1 != 0) {
        // 0x8004FE88: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8004FE90;
    }
    // 0x8004FE88: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8004FE8C: addiu       $v1, $zero, 0x2EE
    ctx->r3 = ADD32(0, 0X2EE);
L_8004FE90:
    // 0x8004FE90: slti        $at, $v1, -0x2EE
    ctx->r1 = SIGNED(ctx->r3) < -0X2EE ? 1 : 0;
    // 0x8004FE94: beq         $at, $zero, L_8004FEA0
    if (ctx->r1 == 0) {
        // 0x8004FE98: nop
    
            goto L_8004FEA0;
    }
    // 0x8004FE98: nop

    // 0x8004FE9C: addiu       $v1, $zero, -0x2EE
    ctx->r3 = ADD32(0, -0X2EE);
L_8004FEA0:
    // 0x8004FEA0: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004FEA4: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004FEA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004FEAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004FEB0: mflo        $t2
    ctx->r10 = lo;
    // 0x8004FEB4: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8004FEB8: sh          $t3, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r11;
    // 0x8004FEBC: lh          $t5, 0x1A2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004FEC0: nop

    // 0x8004FEC4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8004FEC8: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x8004FECC: lh          $v0, 0x1A6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004FED0: lw          $t7, -0x2AA8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AA8);
    // 0x8004FED4: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x8004FED8: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x8004FEDC: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004FEE0: lh          $t3, 0x1A4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004FEE4: mflo        $t0
    ctx->r8 = lo;
    // 0x8004FEE8: sra         $t1, $t0, 4
    ctx->r9 = S32(SIGNED(ctx->r8) >> 4);
    // 0x8004FEEC: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8004FEF0: sh          $t2, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r10;
    // 0x8004FEF4: lh          $t4, 0x1A6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004FEF8: nop

    // 0x8004FEFC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004FF00: sh          $t5, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r13;
    // 0x8004FF04: lhu         $a0, -0x2AB0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2AB0);
    // 0x8004FF08: nop

    // 0x8004FF0C: beq         $a0, $zero, L_8004FFA0
    if (ctx->r4 == 0) {
        // 0x8004FF10: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8004FFA0;
    }
    // 0x8004FF10: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004FF14: lw          $t6, -0x2AA4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AA4);
    // 0x8004FF18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004FF1C: beq         $t6, $at, L_8004FF5C
    if (ctx->r14 == ctx->r1) {
        // 0x8004FF20: addiu       $at, $zero, 0x10C
        ctx->r1 = ADD32(0, 0X10C);
            goto L_8004FF5C;
    }
    // 0x8004FF20: addiu       $at, $zero, 0x10C
    ctx->r1 = ADD32(0, 0X10C);
    // 0x8004FF24: beq         $a0, $at, L_8004FF5C
    if (ctx->r4 == ctx->r1) {
        // 0x8004FF28: addiu       $t7, $s0, 0x21C
        ctx->r15 = ADD32(ctx->r16, 0X21C);
            goto L_8004FF5C;
    }
    // 0x8004FF28: addiu       $t7, $s0, 0x21C
    ctx->r15 = ADD32(ctx->r16, 0X21C);
    // 0x8004FF2C: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004FF30: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004FF34: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004FF38: jal         0x80001EA8
    // 0x8004FF3C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    sound_play_spatial(rdram, ctx);
        goto after_19;
    // 0x8004FF3C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_19:
    // 0x8004FF40: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004FF44: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004FF48: lbu         $a2, -0x2AAD($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2AAD);
    // 0x8004FF4C: lhu         $a0, -0x2AB0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2AB0);
    // 0x8004FF50: lw          $a1, 0x21C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X21C);
    // 0x8004FF54: jal         0x80001FB8
    // 0x8004FF58: nop

    sound_volume_set_relative(rdram, ctx);
        goto after_20;
    // 0x8004FF58: nop

    after_20:
L_8004FF5C:
    // 0x8004FF5C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004FF60: lhu         $t8, -0x2AAE($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2AAE);
    // 0x8004FF64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004FF68: addiu       $t9, $t8, -0x28
    ctx->r25 = ADD32(ctx->r24, -0X28);
    // 0x8004FF6C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8004FF70: lwc1        $f11, 0x6628($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6628);
    // 0x8004FF74: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8004FF78: lwc1        $f10, 0x662C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X662C);
    // 0x8004FF7C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004FF80: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8004FF84: mul.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x8004FF88: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004FF8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004FF90: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004FF94: sub.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d - ctx->f16.d;
    // 0x8004FF98: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8004FF9C: swc1        $f8, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f8.u32l;
L_8004FFA0:
    // 0x8004FFA0: lbu         $t0, 0x1F0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1F0);
    // 0x8004FFA4: nop

    // 0x8004FFA8: bne         $t0, $zero, L_80050020
    if (ctx->r8 != 0) {
        // 0x8004FFAC: nop
    
            goto L_80050020;
    }
    // 0x8004FFAC: nop

    // 0x8004FFB0: lh          $t1, 0x1A0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004FFB4: lw          $t2, 0x10C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10C);
    // 0x8004FFB8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004FFBC: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x8004FFC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004FFC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004FFC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004FFCC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8004FFD0: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x8004FFD4: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x8004FFD8: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8004FFDC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8004FFE0: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8004FFE4: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x8004FFE8: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x8004FFEC: jal         0x8006FE74
    // 0x8004FFF0: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_21;
    // 0x8004FFF0: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_21:
    // 0x8004FFF4: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8004FFF8: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x8004FFFC: addiu       $t4, $s1, 0x1C
    ctx->r12 = ADD32(ctx->r17, 0X1C);
    // 0x80050000: addiu       $t5, $sp, 0xBC
    ctx->r13 = ADD32(ctx->r29, 0XBC);
    // 0x80050004: addiu       $t6, $s1, 0x24
    ctx->r14 = ADD32(ctx->r17, 0X24);
    // 0x80050008: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8005000C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80050010: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80050014: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80050018: jal         0x8006F64C
    // 0x8005001C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    mtxf_transform_point(rdram, ctx);
        goto after_22;
    // 0x8005001C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_22:
L_80050020:
    // 0x80050020: lb          $t7, 0x175($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X175);
    // 0x80050024: nop

    // 0x80050028: beq         $t7, $zero, L_80050048
    if (ctx->r15 == 0) {
        // 0x8005002C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80050048;
    }
    // 0x8005002C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050030: lwc1        $f10, -0x2A88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2A88);
    // 0x80050034: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050038: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x8005003C: lwc1        $f6, -0x2A84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2A84);
    // 0x80050040: nop

    // 0x80050044: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
L_80050048:
    // 0x80050048: lw          $t8, 0x148($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X148);
    // 0x8005004C: lw          $a2, 0xC4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC4);
    // 0x80050050: bne         $t8, $zero, L_8005021C
    if (ctx->r24 != 0) {
        // 0x80050054: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005021C;
    }
    // 0x80050054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050058: lwc1        $f16, 0x1C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005005C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80050060: swc1        $f16, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f16.u32l;
    // 0x80050064: lwc1        $f18, 0x24($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80050068: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8005006C: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
    // 0x80050070: lb          $t9, 0x1D2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D2);
    // 0x80050074: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80050078: beq         $t9, $zero, L_800500A0
    if (ctx->r25 == 0) {
        // 0x8005007C: nop
    
            goto L_800500A0;
    }
    // 0x8005007C: nop

    // 0x80050080: lwc1        $f4, 0x11C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x80050084: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80050088: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8005008C: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x80050090: lwc1        $f16, 0x120($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80050094: nop

    // 0x80050098: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8005009C: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
L_800500A0:
    // 0x800500A0: lb          $t0, -0x2A7C($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2A7C);
    // 0x800500A4: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800500A8: beq         $t0, $zero, L_8005019C
    if (ctx->r8 == 0) {
        // 0x800500AC: nop
    
            goto L_8005019C;
    }
    // 0x800500AC: nop

    // 0x800500B0: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800500B4: lwc1        $f3, 0x6630($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X6630);
    // 0x800500B8: lwc1        $f2, 0x6634($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6634);
    // 0x800500BC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800500C0: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x800500C4: lwc1        $f16, 0xB4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800500C8: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x800500CC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800500D0: mul.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x800500D4: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800500D8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800500DC: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x800500E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800500E4: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x800500E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800500EC: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x800500F0: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800500F4: nop

    // 0x800500F8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800500FC: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x80050100: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80050104: bc1t        L_80050128
    if (c1cs) {
        // 0x80050108: nop
    
            goto L_80050128;
    }
    // 0x80050108: nop

    // 0x8005010C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80050110: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80050114: nop

    // 0x80050118: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x8005011C: nop

    // 0x80050120: bc1f        L_80050144
    if (!c1cs) {
        // 0x80050124: nop
    
            goto L_80050144;
    }
    // 0x80050124: nop

L_80050128:
    // 0x80050128: mul.d       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8005012C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80050130: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80050134: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80050138: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8005013C: b           L_80050150
    // 0x80050140: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
        goto L_80050150;
    // 0x80050140: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_80050144:
    // 0x80050144: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80050148: nop

    // 0x8005014C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_80050150:
    // 0x80050150: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80050154: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80050158: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005015C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80050160: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80050164: nop

    // 0x80050168: bc1t        L_80050180
    if (c1cs) {
        // 0x8005016C: nop
    
            goto L_80050180;
    }
    // 0x8005016C: nop

    // 0x80050170: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x80050174: nop

    // 0x80050178: bc1f        L_80050190
    if (!c1cs) {
        // 0x8005017C: nop
    
            goto L_80050190;
    }
    // 0x8005017C: nop

L_80050180:
    // 0x80050180: mul.d       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80050184: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x80050188: b           L_800501BC
    // 0x8005018C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
        goto L_800501BC;
    // 0x8005018C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_80050190:
    // 0x80050190: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80050194: b           L_800501BC
    // 0x80050198: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
        goto L_800501BC;
    // 0x80050198: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
L_8005019C:
    // 0x8005019C: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800501A0: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800501A4: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800501A8: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x800501AC: lwc1        $f16, 0x88($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800501B0: nop

    // 0x800501B4: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800501B8: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
L_800501BC:
    // 0x800501BC: lwc1        $f0, 0xC4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800501C0: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800501C4: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800501C8: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800501CC: lwc1        $f16, 0xB4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800501D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800501D4: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800501D8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800501DC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800501E0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800501E4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800501E8: jal         0x80011570
    // 0x800501EC: nop

    move_object(rdram, ctx);
        goto after_23;
    // 0x800501EC: nop

    after_23:
    // 0x800501F0: beq         $v0, $zero, L_8005020C
    if (ctx->r2 == 0) {
        // 0x800501F4: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8005020C;
    }
    // 0x800501F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800501F8: lw          $t1, -0x2AA4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AA4);
    // 0x800501FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050200: beq         $t1, $at, L_8005020C
    if (ctx->r9 == ctx->r1) {
        // 0x80050204: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8005020C;
    }
    // 0x80050204: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80050208: sb          $t2, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r10;
L_8005020C:
    // 0x8005020C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80050210: lw          $v0, -0x2AA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AA4);
    // 0x80050214: b           L_80050234
    // 0x80050218: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_80050234;
    // 0x80050218: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8005021C:
    // 0x8005021C: jal         0x80050754
    // 0x80050220: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_approach_object(rdram, ctx);
        goto after_24;
    // 0x80050220: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_24:
    // 0x80050224: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80050228: lw          $v0, -0x2AA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AA4);
    // 0x8005022C: nop

    // 0x80050230: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80050234:
    // 0x80050234: bne         $v0, $at, L_80050254
    if (ctx->r2 != ctx->r1) {
        // 0x80050238: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80050254;
    }
    // 0x80050238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005023C: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x80050240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050244: jal         0x80055A84
    // 0x80050248: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    onscreen_ai_racer_physics(rdram, ctx);
        goto after_25;
    // 0x80050248: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_25:
    // 0x8005024C: b           L_80050264
    // 0x80050250: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_80050264;
    // 0x80050250: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80050254:
    // 0x80050254: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x80050258: jal         0x80054FD0
    // 0x8005025C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80054FD0(rdram, ctx);
        goto after_26;
    // 0x8005025C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_26:
    // 0x80050260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80050264:
    // 0x80050264: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80050268: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8005026C: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80050270: div.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80050274: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050278: lwc1        $f8, -0x2AB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2AB8);
    // 0x8005027C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050280: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80050284: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x80050288: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005028C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80050290: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x80050294: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80050298: nop

    // 0x8005029C: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800502A0: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800502A4: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800502A8: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800502AC: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800502B0: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800502B4: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    // 0x800502B8: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800502BC: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800502C0: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800502C4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800502C8: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x800502CC: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800502D0: lwc1        $f6, -0x2AB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2AB4);
    // 0x800502D4: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800502D8: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800502DC: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800502E0: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800502E4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800502E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800502EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800502F0: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800502F4: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x800502F8: lw          $t4, 0x10C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10C);
    // 0x800502FC: lh          $t3, 0x1A0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X1A0);
    // 0x80050300: nop

    // 0x80050304: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80050308: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x8005030C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80050310: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80050314: nop

    // 0x80050318: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8005031C: sh          $t8, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r24;
    // 0x80050320: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x80050324: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x80050328: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8005032C: sh          $t0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r8;
    // 0x80050330: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80050334: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x80050338: jal         0x8006FE74
    // 0x8005033C: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_27;
    // 0x8005033C: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    after_27:
    // 0x80050340: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x80050344: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x80050348: addiu       $t1, $sp, 0xAC
    ctx->r9 = ADD32(ctx->r29, 0XAC);
    // 0x8005034C: addiu       $t2, $sp, 0xBC
    ctx->r10 = ADD32(ctx->r29, 0XBC);
    // 0x80050350: addiu       $t3, $sp, 0xB0
    ctx->r11 = ADD32(ctx->r29, 0XB0);
    // 0x80050354: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80050358: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8005035C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80050360: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80050364: jal         0x8006F64C
    // 0x80050368: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    mtxf_transform_point(rdram, ctx);
        goto after_28;
    // 0x80050368: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_28:
    // 0x8005036C: lb          $v0, 0x1D2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D2);
    // 0x80050370: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80050374: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80050378: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8005037C: beq         $v0, $zero, L_800503AC
    if (ctx->r2 == 0) {
        // 0x80050380: lui         $at, 0xBFE0
        ctx->r1 = S32(0XBFE0 << 16);
            goto L_800503AC;
    }
    // 0x80050380: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80050384: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x80050388: nop

    // 0x8005038C: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x80050390: sb          $t5, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r13;
    // 0x80050394: lb          $t6, 0x1D2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D2);
    // 0x80050398: nop

    // 0x8005039C: bgez        $t6, L_800504B8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800503A0: nop
    
            goto L_800504B8;
    }
    // 0x800503A0: nop

    // 0x800503A4: b           L_800504B8
    // 0x800503A8: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
        goto L_800504B8;
    // 0x800503A8: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
L_800503AC:
    // 0x800503AC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800503B0: lwc1        $f16, 0xB0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800503B4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800503B8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800503BC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x800503C0: swc1        $f18, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f18.u32l;
    // 0x800503C4: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800503C8: nop

    // 0x800503CC: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800503D0: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x800503D4: nop

    // 0x800503D8: bc1f        L_80050404
    if (!c1cs) {
        // 0x800503DC: nop
    
            goto L_80050404;
    }
    // 0x800503DC: nop

    // 0x800503E0: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800503E4: sub.d       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f0.d - ctx->f12.d;
    // 0x800503E8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800503EC: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x800503F0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800503F4: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x800503F8: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800503FC: nop

    // 0x80050400: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
L_80050404:
    // 0x80050404: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80050408: nop

    // 0x8005040C: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80050410: nop

    // 0x80050414: bc1f        L_80050434
    if (!c1cs) {
        // 0x80050418: nop
    
            goto L_80050434;
    }
    // 0x80050418: nop

    // 0x8005041C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050420: add.d       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = ctx->f0.d + ctx->f12.d;
    // 0x80050424: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80050428: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8005042C: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x80050430: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_80050434:
    // 0x80050434: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80050438: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005043C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80050440: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80050444: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x80050448: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8005044C: nop

    // 0x80050450: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80050454: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x80050458: nop

    // 0x8005045C: bc1f        L_80050488
    if (!c1cs) {
        // 0x80050460: nop
    
            goto L_80050488;
    }
    // 0x80050460: nop

    // 0x80050464: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80050468: sub.d       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f0.d - ctx->f12.d;
    // 0x8005046C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80050470: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x80050474: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80050478: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x8005047C: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80050480: nop

    // 0x80050484: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
L_80050488:
    // 0x80050488: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005048C: nop

    // 0x80050490: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x80050494: nop

    // 0x80050498: bc1f        L_800504B8
    if (!c1cs) {
        // 0x8005049C: nop
    
            goto L_800504B8;
    }
    // 0x8005049C: nop

    // 0x800504A0: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800504A4: add.d       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f0.d + ctx->f12.d;
    // 0x800504A8: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800504AC: sub.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d - ctx->f6.d;
    // 0x800504B0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800504B4: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_800504B8:
    // 0x800504B8: lb          $t7, 0x1D3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D3);
    // 0x800504BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800504C0: bne         $t7, $zero, L_800505D0
    if (ctx->r15 != 0) {
        // 0x800504C4: nop
    
            goto L_800505D0;
    }
    // 0x800504C4: nop

    // 0x800504C8: lw          $t8, -0x3468($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3468);
    // 0x800504CC: nop

    // 0x800504D0: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x800504D4: beq         $at, $zero, L_800505D0
    if (ctx->r1 == 0) {
        // 0x800504D8: nop
    
            goto L_800505D0;
    }
    // 0x800504D8: nop

    // 0x800504DC: jal         0x8001E29C
    // 0x800504E0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_29;
    // 0x800504E0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_29:
    // 0x800504E4: lb          $v1, 0x203($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X203);
    // 0x800504E8: lb          $t9, 0x2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X2);
    // 0x800504EC: andi        $t1, $v1, 0x4
    ctx->r9 = ctx->r3 & 0X4;
    // 0x800504F0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800504F4: sra         $t2, $t1, 2
    ctx->r10 = S32(SIGNED(ctx->r9) >> 2);
    // 0x800504F8: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800504FC: addiu       $v1, $t2, 0x10
    ctx->r3 = ADD32(ctx->r10, 0X10);
    // 0x80050500: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80050504: slti        $at, $v1, 0x11
    ctx->r1 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // 0x80050508: sll         $t0, $t9, 7
    ctx->r8 = S32(ctx->r25 << 7);
    // 0x8005050C: bne         $at, $zero, L_80050558
    if (ctx->r1 != 0) {
        // 0x80050510: addu        $a0, $t0, $v0
        ctx->r4 = ADD32(ctx->r8, ctx->r2);
            goto L_80050558;
    }
    // 0x80050510: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    // 0x80050514: lbu         $t3, 0x70($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X70);
    // 0x80050518: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005051C: bgtz        $t3, L_80050544
    if (SIGNED(ctx->r11) > 0) {
        // 0x80050520: nop
    
            goto L_80050544;
    }
    // 0x80050520: nop

    // 0x80050524: lwc1        $f8, 0x74($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X74);
    // 0x80050528: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8005052C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80050530: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80050534: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80050538: nop

    // 0x8005053C: bc1f        L_800505D0
    if (!c1cs) {
        // 0x80050540: nop
    
            goto L_800505D0;
    }
    // 0x80050540: nop

L_80050544:
    // 0x80050544: lw          $t4, 0x74($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X74);
    // 0x80050548: sllv        $t6, $t5, $v1
    ctx->r14 = S32(ctx->r13 << (ctx->r3 & 31));
    // 0x8005054C: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80050550: b           L_800505D0
    // 0x80050554: sw          $t7, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r15;
        goto L_800505D0;
    // 0x80050554: sw          $t7, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r15;
L_80050558:
    // 0x80050558: lbu         $v0, 0x70($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X70);
    // 0x8005055C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80050560: bne         $v0, $at, L_8005059C
    if (ctx->r2 != ctx->r1) {
        // 0x80050564: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8005059C;
    }
    // 0x80050564: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80050568: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8005056C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80050570: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80050574: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x80050578: nop

    // 0x8005057C: bc1f        L_8005059C
    if (!c1cs) {
        // 0x80050580: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8005059C;
    }
    // 0x80050580: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80050584: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x80050588: sllv        $t0, $t9, $v1
    ctx->r8 = S32(ctx->r25 << (ctx->r3 & 31));
    // 0x8005058C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80050590: b           L_800505D0
    // 0x80050594: sw          $t1, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r9;
        goto L_800505D0;
    // 0x80050594: sw          $t1, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r9;
    // 0x80050598: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_8005059C:
    // 0x8005059C: beq         $at, $zero, L_800505D0
    if (ctx->r1 == 0) {
        // 0x800505A0: nop
    
            goto L_800505D0;
    }
    // 0x800505A0: nop

    // 0x800505A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800505A8: lwc1        $f8, 0x74($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800505AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800505B0: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800505B4: nop

    // 0x800505B8: bc1f        L_800505D0
    if (!c1cs) {
        // 0x800505BC: nop
    
            goto L_800505D0;
    }
    // 0x800505BC: nop

    // 0x800505C0: lw          $t2, 0x74($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X74);
    // 0x800505C4: sllv        $t5, $t3, $v1
    ctx->r13 = S32(ctx->r11 << (ctx->r3 & 31));
    // 0x800505C8: or          $t4, $t2, $t5
    ctx->r12 = ctx->r10 | ctx->r13;
    // 0x800505CC: sw          $t4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r12;
L_800505D0:
    // 0x800505D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800505D4: lw          $t6, -0x2AA4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AA4);
    // 0x800505D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800505DC: beq         $t6, $at, L_800506A0
    if (ctx->r14 == ctx->r1) {
        // 0x800505E0: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800506A0;
    }
    // 0x800505E0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800505E4: lw          $t7, -0x3468($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3468);
    // 0x800505E8: nop

    // 0x800505EC: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800505F0: beq         $at, $zero, L_800506A0
    if (ctx->r1 == 0) {
        // 0x800505F4: lui         $at, 0x4160
        ctx->r1 = S32(0X4160 << 16);
            goto L_800506A0;
    }
    // 0x800505F4: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x800505F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800505FC: lwc1        $f0, 0xC0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80050600: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80050604: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80050608: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8005060C: bc1f        L_80050638
    if (!c1cs) {
        // 0x80050610: nop
    
            goto L_80050638;
    }
    // 0x80050610: nop

    // 0x80050614: jal         0x8006F94C
    // 0x80050618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_30;
    // 0x80050618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x8005061C: beq         $v0, $zero, L_800506A0
    if (ctx->r2 == 0) {
        // 0x80050620: nop
    
            goto L_800506A0;
    }
    // 0x80050620: nop

    // 0x80050624: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x80050628: lui         $at, 0x30
    ctx->r1 = S32(0X30 << 16);
    // 0x8005062C: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80050630: b           L_800506A0
    // 0x80050634: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
        goto L_800506A0;
    // 0x80050634: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
L_80050638:
    // 0x80050638: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005063C: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x80050640: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80050644: nop

    // 0x80050648: bc1f        L_800506A0
    if (!c1cs) {
        // 0x8005064C: nop
    
            goto L_800506A0;
    }
    // 0x8005064C: nop

    // 0x80050650: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050654: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80050658: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005065C: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80050660: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x80050664: nop

    // 0x80050668: bc1f        L_800506A0
    if (!c1cs) {
        // 0x8005066C: nop
    
            goto L_800506A0;
    }
    // 0x8005066C: nop

    // 0x80050670: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80050674: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80050678: bc1f        L_800506A0
    if (!c1cs) {
        // 0x8005067C: nop
    
            goto L_800506A0;
    }
    // 0x8005067C: nop

    // 0x80050680: jal         0x8006F94C
    // 0x80050684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_31;
    // 0x80050684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x80050688: beq         $v0, $zero, L_800506A0
    if (ctx->r2 == 0) {
        // 0x8005068C: nop
    
            goto L_800506A0;
    }
    // 0x8005068C: nop

    // 0x80050690: lw          $t0, 0x74($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X74);
    // 0x80050694: lui         $at, 0xC
    ctx->r1 = S32(0XC << 16);
    // 0x80050698: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8005069C: sw          $t1, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r9;
L_800506A0:
    // 0x800506A0: lb          $t3, 0x1D6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D6);
    // 0x800506A4: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x800506A8: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x800506AC: beq         $at, $zero, L_800506C0
    if (ctx->r1 == 0) {
        // 0x800506B0: lw          $a3, 0xC4($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XC4);
            goto L_800506C0;
    }
    // 0x800506B0: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x800506B4: jal         0x800AF714
    // 0x800506B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    update_vehicle_particles(rdram, ctx);
        goto after_32;
    // 0x800506B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_32:
    // 0x800506BC: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
L_800506C0:
    // 0x800506C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800506C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800506C8: jal         0x800580B4
    // 0x800506CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    second_racer_camera_update(rdram, ctx);
        goto after_33;
    // 0x800506CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_33:
    // 0x800506D0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800506D4: lw          $t2, -0x3468($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3468);
    // 0x800506D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800506DC: bne         $t2, $at, L_8005072C
    if (ctx->r10 != ctx->r1) {
        // 0x800506E0: lb          $t4, 0x53($sp)
        ctx->r12 = MEM_B(ctx->r29, 0X53);
            goto L_8005072C;
    }
    // 0x800506E0: lb          $t4, 0x53($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X53);
    // 0x800506E4: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800506E8: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x800506EC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800506F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800506F4: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x800506F8: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x800506FC: nop

    // 0x80050700: bc1f        L_8005072C
    if (!c1cs) {
        // 0x80050704: lb          $t4, 0x53($sp)
        ctx->r12 = MEM_B(ctx->r29, 0X53);
            goto L_8005072C;
    }
    // 0x80050704: lb          $t4, 0x53($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X53);
    // 0x80050708: jal         0x8006EA90
    // 0x8005070C: nop

    get_settings(rdram, ctx);
        goto after_34;
    // 0x8005070C: nop

    after_34:
    // 0x80050710: lbu         $t5, 0x49($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X49);
    // 0x80050714: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80050718: beq         $t5, $at, L_8005072C
    if (ctx->r13 == ctx->r1) {
        // 0x8005071C: lb          $t4, 0x53($sp)
        ctx->r12 = MEM_B(ctx->r29, 0X53);
            goto L_8005072C;
    }
    // 0x8005071C: lb          $t4, 0x53($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X53);
    // 0x80050720: jal         0x80028FA0
    // 0x80050724: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_35;
    // 0x80050724: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x80050728: lb          $t4, 0x53($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X53);
L_8005072C:
    // 0x8005072C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80050730: beq         $t4, $zero, L_80050744
    if (ctx->r12 == 0) {
        // 0x80050734: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80050744;
    }
    // 0x80050734: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80050738: jal         0x800230D0
    // 0x8005073C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800230D0(rdram, ctx);
        goto after_36;
    // 0x8005073C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_36:
    // 0x80050740: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80050744:
    // 0x80050744: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80050748: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005074C: jr          $ra
    // 0x80050750: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80050750: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_8002F440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F440: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8002F444: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002F448: addiu       $t4, $t4, -0x2F3C
    ctx->r12 = ADD32(ctx->r12, -0X2F3C);
    // 0x8002F44C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8002F450: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002F454: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002F458: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002F45C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002F460: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002F464: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002F468: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002F46C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002F470: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002F474: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002F478: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    // 0x8002F47C: jal         0x800707C4
    // 0x8002F480: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8002F480: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    after_0:
    // 0x8002F484: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002F488: addiu       $t4, $t4, -0x2F3C
    ctx->r12 = ADD32(ctx->r12, -0X2F3C);
    // 0x8002F48C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8002F490: nop

    // 0x8002F494: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x8002F498: jal         0x800707F8
    // 0x8002F49C: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x8002F49C: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8002F4A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002F4A4: lw          $t8, -0x2F40($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2F40);
    // 0x8002F4A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F4AC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8002F4B0: lwc1        $f6, -0x2F24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F24);
    // 0x8002F4B4: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8002F4B8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002F4BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002F4C0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002F4C4: lwc1        $f8, 0x5F54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F54);
    // 0x8002F4C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F4CC: div.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8002F4D0: lwc1        $f12, -0x2F10($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2F10);
    // 0x8002F4D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002F4D8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002F4DC: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x8002F4E0: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002F4E4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002F4E8: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8002F4EC: addiu       $t4, $t4, -0x2F3C
    ctx->r12 = ADD32(ctx->r12, -0X2F3C);
    // 0x8002F4F0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002F4F4: addiu       $fp, $fp, -0x2C9C
    ctx->r30 = ADD32(ctx->r30, -0X2C9C);
    // 0x8002F4F8: addiu       $t5, $t5, -0x3DC8
    ctx->r13 = ADD32(ctx->r13, -0X3DC8);
    // 0x8002F4FC: mul.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8002F500: bc1f        L_8002F5BC
    if (!c1cs) {
        // 0x8002F504: addiu       $s6, $zero, 0x40
        ctx->r22 = ADD32(0, 0X40);
            goto L_8002F5BC;
    }
    // 0x8002F504: addiu       $s6, $zero, 0x40
    ctx->r22 = ADD32(0, 0X40);
    // 0x8002F508: lh          $t8, -0x2F30($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2F30);
    // 0x8002F50C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8002F510: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8002F514: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8002F518: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002F51C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8002F520: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8002F524: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8002F528: nop

    // 0x8002F52C: bc1f        L_8002F584
    if (!c1cs) {
        // 0x8002F530: nop
    
            goto L_8002F584;
    }
    // 0x8002F530: nop

    // 0x8002F534: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002F538: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8002F53C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F540: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8002F544: lwc1        $f8, -0x2F0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2F0C);
    // 0x8002F548: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8002F54C: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8002F550: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F554: nop

    // 0x8002F558: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F55C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F560: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F564: nop

    // 0x8002F568: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002F56C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002F570: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F574: subu        $s7, $t7, $t6
    ctx->r23 = SUB32(ctx->r15, ctx->r14);
    // 0x8002F578: bgez        $s7, L_8002F584
    if (SIGNED(ctx->r23) >= 0) {
        // 0x8002F57C: nop
    
            goto L_8002F584;
    }
    // 0x8002F57C: nop

    // 0x8002F580: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8002F584:
    // 0x8002F584: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002F588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002F58C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8002F590: nop

    // 0x8002F594: bc1f        L_8002F5BC
    if (!c1cs) {
        // 0x8002F598: nop
    
            goto L_8002F5BC;
    }
    // 0x8002F598: nop

    // 0x8002F59C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002F5A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002F5A4: lwc1        $f10, 0x5F58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F58);
    // 0x8002F5A8: nop

    // 0x8002F5AC: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8002F5B0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002F5B4: mul.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8002F5B8: nop

L_8002F5BC:
    // 0x8002F5BC: mtc1        $s7, $f10
    ctx->f10.u32l = ctx->r23;
    // 0x8002F5C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002F5C4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002F5C8: lwc1        $f6, -0x2F2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2F2C);
    // 0x8002F5CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F5D0: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002F5D4: lw          $t9, -0x3DD0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3DD0);
    // 0x8002F5D8: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002F5DC: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002F5E0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002F5E4: addiu       $s2, $zero, 0x19
    ctx->r18 = ADD32(0, 0X19);
    // 0x8002F5E8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002F5EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F5F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F5F4: addiu       $s4, $s4, -0x2CB8
    ctx->r20 = ADD32(ctx->r20, -0X2CB8);
    // 0x8002F5F8: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F5FC: addiu       $s5, $s5, -0x2CD0
    ctx->r21 = ADD32(ctx->r21, -0X2CD0);
    // 0x8002F600: mfc1        $s7, $f10
    ctx->r23 = (int32_t)ctx->f10.u32l;
    // 0x8002F604: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002F608: blez        $t9, L_8002FA34
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002F60C: sw          $zero, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = 0;
            goto L_8002FA34;
    }
    // 0x8002F60C: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x8002F610: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002F614: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002F618: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8002F61C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8002F620: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002F624: addiu       $t1, $t1, -0x4CD0
    ctx->r9 = ADD32(ctx->r9, -0X4CD0);
    // 0x8002F628: addiu       $t2, $t2, -0x4EE0
    ctx->r10 = ADD32(ctx->r10, -0X4EE0);
    // 0x8002F62C: addiu       $ra, $ra, -0x2C98
    ctx->r31 = ADD32(ctx->r31, -0X2C98);
    // 0x8002F630: addiu       $s0, $s0, -0x2C94
    ctx->r16 = ADD32(ctx->r16, -0X2C94);
    // 0x8002F634: addiu       $s1, $s1, -0x2F38
    ctx->r17 = ADD32(ctx->r17, -0X2F38);
    // 0x8002F638: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8002F63C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_8002F640:
    // 0x8002F640: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002F644: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002F648: addu        $t7, $v0, $s2
    ctx->r15 = ADD32(ctx->r2, ctx->r18);
    // 0x8002F64C: slti        $at, $t7, 0x18
    ctx->r1 = SIGNED(ctx->r15) < 0X18 ? 1 : 0;
    // 0x8002F650: bne         $at, $zero, L_8002F6B8
    if (ctx->r1 != 0) {
        // 0x8002F654: addiu       $v1, $v1, -0x2CA0
        ctx->r3 = ADD32(ctx->r3, -0X2CA0);
            goto L_8002F6B8;
    }
    // 0x8002F654: addiu       $v1, $v1, -0x2CA0
    ctx->r3 = ADD32(ctx->r3, -0X2CA0);
    // 0x8002F658: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x8002F65C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8002F660: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002F664: lw          $t6, -0x2F40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2F40);
    // 0x8002F668: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x8002F66C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8002F670: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8002F674: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x8002F678: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002F67C: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x8002F680: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x8002F684: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x8002F688: sh          $t8, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r24;
    // 0x8002F68C: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8002F690: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8002F694: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002F698: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x8002F69C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F6A0: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x8002F6A4: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x8002F6A8: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002F6AC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8002F6B0: sw          $t6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r14;
    // 0x8002F6B4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8002F6B8:
    // 0x8002F6B8: lbu         $t0, 0x1($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X1);
    // 0x8002F6BC: blez        $v0, L_8002F968
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002F6C0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8002F968;
    }
    // 0x8002F6C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002F6C4: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8002F6C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F6CC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002F6D0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8002F6D4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002F6D8: addiu       $t9, $t9, -0x3DC8
    ctx->r25 = ADD32(ctx->r25, -0X3DC8);
    // 0x8002F6DC: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8002F6E0: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8002F6E4: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
L_8002F6E8:
    // 0x8002F6E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002F6EC: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8002F6F0: multu       $a0, $s3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F6F4: andi        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 & 0X1;
    // 0x8002F6F8: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x8002F6FC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002F700: mflo        $t6
    ctx->r14 = lo;
    // 0x8002F704: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F708: beq         $t9, $zero, L_8002F7E8
    if (ctx->r25 == 0) {
        // 0x8002F70C: nop
    
            goto L_8002F7E8;
    }
    // 0x8002F70C: nop

    // 0x8002F710: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F714: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F718: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8002F71C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F720: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F724: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8002F728: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002F72C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F730: nop

    // 0x8002F734: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F738: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002F73C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F740: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8002F744: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F748: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x8002F74C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8002F750: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
    // 0x8002F754: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F758: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8002F75C: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8002F760: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002F764: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002F768: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002F76C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002F770: nop

    // 0x8002F774: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002F778: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F77C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F780: nop

    // 0x8002F784: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F788: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8002F78C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002F790: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x8002F794: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F798: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002F79C: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8002F7A0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002F7A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F7A8: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x8002F7AC: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8002F7B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F7B4: nop

    // 0x8002F7B8: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F7BC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8002F7C0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002F7C4: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x8002F7C8: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F7CC: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8002F7D0: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x8002F7D4: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8002F7D8: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002F7DC: lwc1        $f10, 0x14($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8002F7E0: b           L_8002F8C0
    // 0x8002F7E4: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
        goto L_8002F8C0;
    // 0x8002F7E4: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
L_8002F7E8:
    // 0x8002F7E8: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F7EC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002F7F0: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8002F7F4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002F7F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F7FC: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8002F800: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002F804: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F808: nop

    // 0x8002F80C: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F810: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8002F814: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002F818: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8002F81C: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F820: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8002F824: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8002F828: addu        $a0, $t2, $t7
    ctx->r4 = ADD32(ctx->r10, ctx->r15);
    // 0x8002F82C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F830: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8002F834: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8002F838: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8002F83C: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002F840: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002F844: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F848: nop

    // 0x8002F84C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F850: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F854: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F858: nop

    // 0x8002F85C: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F860: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8002F864: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F868: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x8002F86C: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F870: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002F874: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8002F878: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002F87C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F880: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x8002F884: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8002F888: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F88C: nop

    // 0x8002F890: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F894: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8002F898: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002F89C: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x8002F8A0: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x8002F8A4: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8002F8A8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8002F8AC: addu        $t6, $t2, $t9
    ctx->r14 = ADD32(ctx->r10, ctx->r25);
    // 0x8002F8B0: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8002F8B4: lwc1        $f10, 0x14($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X14);
    // 0x8002F8B8: nop

    // 0x8002F8BC: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
L_8002F8C0:
    // 0x8002F8C0: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8002F8C4: sra         $t8, $t0, 1
    ctx->r24 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8002F8C8: sb          $t3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r11;
    // 0x8002F8CC: sb          $t3, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r11;
    // 0x8002F8D0: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8002F8D4: sb          $t3, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r11;
    // 0x8002F8D8: sb          $s7, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r23;
    // 0x8002F8DC: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002F8E0: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8002F8E4: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8002F8E8: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8002F8EC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002F8F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F8F4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8002F8F8: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8002F8FC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002F900: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002F904: nop

    // 0x8002F908: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002F90C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F910: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F914: nop

    // 0x8002F918: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002F91C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002F920: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002F924: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8002F928: sh          $t6, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r14;
    // 0x8002F92C: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8002F930: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002F934: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8002F938: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8002F93C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002F940: nop

    // 0x8002F944: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002F948: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002F94C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002F950: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002F954: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002F958: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8002F95C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002F960: bne         $at, $zero, L_8002F6E8
    if (ctx->r1 != 0) {
        // 0x8002F964: sh          $t8, -0x2($a2)
        MEM_H(-0X2, ctx->r6) = ctx->r24;
            goto L_8002F6E8;
    }
    // 0x8002F964: sh          $t8, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r24;
L_8002F968:
    // 0x8002F968: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8002F96C: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8002F970: bne         $at, $zero, L_8002FA10
    if (ctx->r1 != 0) {
        // 0x8002F974: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8002FA10;
    }
    // 0x8002F974: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002F978: addiu       $a0, $s2, 0x1
    ctx->r4 = ADD32(ctx->r18, 0X1);
    // 0x8002F97C: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    // 0x8002F980: addiu       $a1, $sp, 0x92
    ctx->r5 = ADD32(ctx->r29, 0X92);
    // 0x8002F984: addiu       $a2, $sp, 0x82
    ctx->r6 = ADD32(ctx->r29, 0X82);
L_8002F988:
    // 0x8002F988: lw          $v1, 0x0($ra)
    ctx->r3 = MEM_W(ctx->r31, 0X0);
    // 0x8002F98C: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8002F990: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8002F994: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8002F998: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
    // 0x8002F99C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F9A0: sb          $s6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r22;
    // 0x8002F9A4: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x8002F9A8: sb          $t0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r8;
    // 0x8002F9AC: sb          $s2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r18;
    // 0x8002F9B0: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x8002F9B4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002F9B8: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x8002F9BC: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x8002F9C0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8002F9C4: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x8002F9C8: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x8002F9CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002F9D0: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x8002F9D4: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x8002F9D8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8002F9DC: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x8002F9E0: lh          $t9, 0x90($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X90);
    // 0x8002F9E4: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002F9E8: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
    // 0x8002F9EC: lh          $t6, 0x80($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X80);
    // 0x8002F9F0: nop

    // 0x8002F9F4: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
    // 0x8002F9F8: lbu         $v0, 0x0($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X0);
    // 0x8002F9FC: nop

    // 0x8002FA00: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8002FA04: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002FA08: bne         $at, $zero, L_8002F988
    if (ctx->r1 != 0) {
        // 0x8002FA0C: nop
    
            goto L_8002F988;
    }
    // 0x8002FA0C: nop

L_8002FA10:
    // 0x8002FA10: lw          $v1, 0xAC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XAC);
    // 0x8002FA14: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002FA18: lw          $t8, -0x3DD0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3DD0);
    // 0x8002FA1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002FA20: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002FA24: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    // 0x8002FA28: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8002FA2C: bne         $at, $zero, L_8002F640
    if (ctx->r1 != 0) {
        // 0x8002FA30: addu        $s2, $s2, $v0
        ctx->r18 = ADD32(ctx->r18, ctx->r2);
            goto L_8002F640;
    }
    // 0x8002FA30: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_8002FA34:
    // 0x8002FA34: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002FA38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002FA3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FA40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002FA44: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002FA48: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002FA4C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FA50: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002FA54: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002FA58: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002FA5C: jr          $ra
    // 0x8002FA60: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8002FA60: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void music_channel_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000114C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001150: lw          $t6, -0x39D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X39D0);
    // 0x80001154: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80001158: lhu         $t7, 0x30($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X30);
    // 0x8000115C: sllv        $t9, $t8, $a0
    ctx->r25 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x80001160: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
    // 0x80001164: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80001168: jr          $ra
    // 0x8000116C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8000116C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void racer_update_eggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045128: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004512C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045130: lw          $v0, 0x64($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X64);
    // 0x80045134: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80045138: lb          $t7, 0x193($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X193);
    // 0x8004513C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80045140: sb          $t7, -0x2A78($at)
    MEM_B(-0X2A78, ctx->r1) = ctx->r15;
    // 0x80045144: lb          $t8, 0x1CF($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1CF);
    // 0x80045148: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004514C: beq         $t8, $zero, L_80045164
    if (ctx->r24 == 0) {
        // 0x80045150: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80045164;
    }
    // 0x80045150: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80045154: lb          $t9, -0x2A78($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2A78);
    // 0x80045158: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004515C: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x80045160: sb          $t0, -0x2A78($at)
    MEM_B(-0X2A78, ctx->r1) = ctx->r8;
L_80045164:
    // 0x80045164: lw          $t1, 0x144($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X144);
    // 0x80045168: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004516C: beq         $t1, $zero, L_80045184
    if (ctx->r9 == 0) {
        // 0x80045170: nop
    
            goto L_80045184;
    }
    // 0x80045170: nop

    // 0x80045174: lb          $t2, -0x2A78($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X2A78);
    // 0x80045178: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004517C: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x80045180: sb          $t3, -0x2A78($at)
    MEM_B(-0X2A78, ctx->r1) = ctx->r11;
L_80045184:
    // 0x80045184: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x80045188: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004518C: lw          $v0, 0x64($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X64);
    // 0x80045190: nop

    // 0x80045194: lb          $t5, 0x193($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X193);
    // 0x80045198: nop

    // 0x8004519C: sb          $t5, -0x2A77($at)
    MEM_B(-0X2A77, ctx->r1) = ctx->r13;
    // 0x800451A0: lb          $t6, 0x1CF($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1CF);
    // 0x800451A4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800451A8: beq         $t6, $zero, L_800451C0
    if (ctx->r14 == 0) {
        // 0x800451AC: nop
    
            goto L_800451C0;
    }
    // 0x800451AC: nop

    // 0x800451B0: lb          $t7, -0x2A77($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2A77);
    // 0x800451B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800451B8: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x800451BC: sb          $t8, -0x2A77($at)
    MEM_B(-0X2A77, ctx->r1) = ctx->r24;
L_800451C0:
    // 0x800451C0: lw          $t9, 0x144($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X144);
    // 0x800451C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800451C8: beq         $t9, $zero, L_800451E0
    if (ctx->r25 == 0) {
        // 0x800451CC: nop
    
            goto L_800451E0;
    }
    // 0x800451CC: nop

    // 0x800451D0: lb          $t0, -0x2A77($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2A77);
    // 0x800451D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800451D8: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x800451DC: sb          $t1, -0x2A77($at)
    MEM_B(-0X2A77, ctx->r1) = ctx->r9;
L_800451E0:
    // 0x800451E0: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800451E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800451E8: lw          $v0, 0x64($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X64);
    // 0x800451EC: nop

    // 0x800451F0: lb          $t3, 0x193($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X193);
    // 0x800451F4: nop

    // 0x800451F8: sb          $t3, -0x2A76($at)
    MEM_B(-0X2A76, ctx->r1) = ctx->r11;
    // 0x800451FC: lb          $t4, 0x1CF($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1CF);
    // 0x80045200: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80045204: beq         $t4, $zero, L_8004521C
    if (ctx->r12 == 0) {
        // 0x80045208: nop
    
            goto L_8004521C;
    }
    // 0x80045208: nop

    // 0x8004520C: lb          $t5, -0x2A76($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X2A76);
    // 0x80045210: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045214: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x80045218: sb          $t6, -0x2A76($at)
    MEM_B(-0X2A76, ctx->r1) = ctx->r14;
L_8004521C:
    // 0x8004521C: lw          $t7, 0x144($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X144);
    // 0x80045220: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80045224: beq         $t7, $zero, L_8004523C
    if (ctx->r15 == 0) {
        // 0x80045228: nop
    
            goto L_8004523C;
    }
    // 0x80045228: nop

    // 0x8004522C: lb          $t8, -0x2A76($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X2A76);
    // 0x80045230: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045234: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80045238: sb          $t9, -0x2A76($at)
    MEM_B(-0X2A76, ctx->r1) = ctx->r25;
L_8004523C:
    // 0x8004523C: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x80045240: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045244: lw          $v0, 0x64($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X64);
    // 0x80045248: nop

    // 0x8004524C: lb          $t1, 0x193($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X193);
    // 0x80045250: nop

    // 0x80045254: sb          $t1, -0x2A75($at)
    MEM_B(-0X2A75, ctx->r1) = ctx->r9;
    // 0x80045258: lb          $t2, 0x1CF($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1CF);
    // 0x8004525C: nop

    // 0x80045260: beq         $t2, $zero, L_80045278
    if (ctx->r10 == 0) {
        // 0x80045264: nop
    
            goto L_80045278;
    }
    // 0x80045264: nop

    // 0x80045268: lb          $t3, -0x2A75($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X2A75);
    // 0x8004526C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045270: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x80045274: sb          $t4, -0x2A75($at)
    MEM_B(-0X2A75, ctx->r1) = ctx->r12;
L_80045278:
    // 0x80045278: lw          $t5, 0x144($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X144);
    // 0x8004527C: nop

    // 0x80045280: beq         $t5, $zero, L_80045298
    if (ctx->r13 == 0) {
        // 0x80045284: nop
    
            goto L_80045298;
    }
    // 0x80045284: nop

    // 0x80045288: lb          $t6, -0x2A75($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2A75);
    // 0x8004528C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045290: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x80045294: sb          $t7, -0x2A75($at)
    MEM_B(-0X2A75, ctx->r1) = ctx->r15;
L_80045298:
    // 0x80045298: jr          $ra
    // 0x8004529C: nop

    return;
    // 0x8004529C: nop

;}
RECOMP_FUNC void rotate_racer_in_water(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800494E0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800494E4: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800494E8: sll         $t6, $a3, 24
    ctx->r14 = S32(ctx->r7 << 24);
    // 0x800494EC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800494F0: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800494F4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800494F8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800494FC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80049500: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80049504: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80049508: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004950C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80049510: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x80049514: bne         $t7, $at, L_8004957C
    if (ctx->r15 != ctx->r1) {
        // 0x80049518: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8004957C;
    }
    // 0x80049518: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004951C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049520: lwc1        $f2, 0x2C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80049524: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049528: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004952C: nop

    // 0x80049530: bc1f        L_8004953C
    if (!c1cs) {
        // 0x80049534: nop
    
            goto L_8004953C;
    }
    // 0x80049534: nop

    // 0x80049538: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8004953C:
    // 0x8004953C: lwc1        $f9, 0x64A0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X64A0);
    // 0x80049540: lwc1        $f8, 0x64A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64A4);
    // 0x80049544: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80049548: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8004954C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80049550: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80049554: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80049558: nop

    // 0x8004955C: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x80049560: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x80049564: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80049568: nop

    // 0x8004956C: bc1f        L_800495C0
    if (!c1cs) {
        // 0x80049570: nop
    
            goto L_800495C0;
    }
    // 0x80049570: nop

    // 0x80049574: b           L_800495C0
    // 0x80049578: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_800495C0;
    // 0x80049578: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8004957C:
    // 0x8004957C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80049580: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80049584: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049588: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004958C: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80049590: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80049594: mul.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80049598: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004959C: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800495A0: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x800495A4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800495A8: nop

    // 0x800495AC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800495B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800495B4: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800495B8: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800495BC: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
L_800495C0:
    // 0x800495C0: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x800495C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800495C8: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x800495CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800495D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800495D4: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x800495D8: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x800495DC: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x800495E0: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x800495E4: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x800495E8: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x800495EC: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x800495F0: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800495F4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800495F8: jal         0x8006FE74
    // 0x800495FC: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x800495FC: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    after_0:
    // 0x80049600: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80049604: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80049608: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8004960C: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x80049610: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x80049614: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80049618: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8004961C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80049620: jal         0x8006F64C
    // 0x80049624: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x80049624: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x80049628: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8004962C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80049630: jal         0x80070750
    // 0x80049634: nop

    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x80049634: nop

    after_2:
    // 0x80049638: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8004963C: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80049640: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80049644: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80049648: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004964C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049650: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80049654: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80049658: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004965C: lh          $v1, 0x1A4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X1A4);
    // 0x80049660: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x80049664: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x80049668: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8004966C: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x80049670: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80049674: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80049678: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004967C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80049680: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80049684: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80049688: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8004968C: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x80049690: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80049694: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    // 0x80049698: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004969C: bne         $at, $zero, L_800496AC
    if (ctx->r1 != 0) {
        // 0x800496A0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800496AC;
    }
    // 0x800496A0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800496A4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800496A8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800496AC:
    // 0x800496AC: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x800496B0: beq         $at, $zero, L_800496BC
    if (ctx->r1 == 0) {
        // 0x800496B4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800496BC;
    }
    // 0x800496B4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800496B8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800496BC:
    // 0x800496BC: multu       $a0, $t4
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800496C0: mflo        $t5
    ctx->r13 = lo;
    // 0x800496C4: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800496C8: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800496CC: sh          $t7, 0x1A4($a1)
    MEM_H(0X1A4, ctx->r5) = ctx->r15;
    // 0x800496D0: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800496D4: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800496D8: jal         0x80070750
    // 0x800496DC: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x800496DC: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x800496E0: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800496E4: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800496E8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800496EC: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800496F0: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800496F4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800496F8: lw          $t2, -0x2AC8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AC8);
    // 0x800496FC: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80049700: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80049704: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80049708: lh          $a1, 0x2($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X2);
    // 0x8004970C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80049710: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80049714: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80049718: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004971C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049720: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80049724: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80049728: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8004972C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80049730: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80049734: addu        $v1, $t1, $t4
    ctx->r3 = ADD32(ctx->r9, ctx->r12);
    // 0x80049738: addiu       $v1, $v1, 0x3C0
    ctx->r3 = ADD32(ctx->r3, 0X3C0);
    // 0x8004973C: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x80049740: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x80049744: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80049748: bne         $at, $zero, L_80049758
    if (ctx->r1 != 0) {
        // 0x8004974C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80049758;
    }
    // 0x8004974C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80049750: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80049754: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80049758:
    // 0x80049758: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x8004975C: beq         $at, $zero, L_80049768
    if (ctx->r1 == 0) {
        // 0x80049760: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80049768;
    }
    // 0x80049760: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80049764: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80049768:
    // 0x80049768: multu       $a0, $t7
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004976C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80049770: mflo        $t9
    ctx->r25 = lo;
    // 0x80049774: sra         $t8, $t9, 4
    ctx->r24 = S32(SIGNED(ctx->r25) >> 4);
    // 0x80049778: addu        $t0, $a1, $t8
    ctx->r8 = ADD32(ctx->r5, ctx->r24);
    // 0x8004977C: sh          $t0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r8;
    // 0x80049780: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80049784: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80049788: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8004978C: jr          $ra
    // 0x80049790: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80049790: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void get_first_active_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014814: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80014818: addiu       $a2, $a2, -0x51A4
    ctx->r6 = ADD32(ctx->r6, -0X51A4);
    // 0x8001481C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80014820: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014824: addiu       $t2, $t2, -0x5184
    ctx->r10 = ADD32(ctx->r10, -0X5184);
    // 0x80014828: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001482C: lh          $v1, 0x0($t2)
    ctx->r3 = MEM_H(ctx->r10, 0X0);
    // 0x80014830: nop

    // 0x80014834: beq         $v1, $zero, L_80014844
    if (ctx->r3 == 0) {
        // 0x80014838: nop
    
            goto L_80014844;
    }
    // 0x80014838: nop

    // 0x8001483C: jr          $ra
    // 0x80014840: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80014840: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80014844:
    // 0x80014844: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80014848: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001484C: lw          $v1, -0x51A0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A0);
    // 0x80014850: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80014854: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80014858: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001485C: bne         $at, $zero, L_800149B0
    if (ctx->r1 != 0) {
        // 0x80014860: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800149B0;
    }
    // 0x80014860: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80014864: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80014868: addiu       $t3, $t3, -0x51A8
    ctx->r11 = ADD32(ctx->r11, -0X51A8);
    // 0x8001486C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_80014870:
    // 0x80014870: bne         $at, $zero, L_800148EC
    if (ctx->r1 != 0) {
        // 0x80014874: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800148EC;
    }
    // 0x80014874: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80014878: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8001487C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80014880: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
L_80014884:
    // 0x80014884: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80014888: nop

    // 0x8001488C: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x80014890: nop

    // 0x80014894: andi        $t4, $t9, 0x8000
    ctx->r12 = ctx->r25 & 0X8000;
    // 0x80014898: bne         $t4, $zero, L_800148D0
    if (ctx->r12 != 0) {
        // 0x8001489C: nop
    
            goto L_800148D0;
    }
    // 0x8001489C: nop

    // 0x800148A0: lw          $t5, 0x40($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X40);
    // 0x800148A4: nop

    // 0x800148A8: lhu         $t6, 0x30($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X30);
    // 0x800148AC: nop

    // 0x800148B0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800148B4: beq         $t7, $zero, L_800148C8
    if (ctx->r15 == 0) {
        // 0x800148B8: nop
    
            goto L_800148C8;
    }
    // 0x800148B8: nop

    // 0x800148BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800148C0: b           L_800148D8
    // 0x800148C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
        goto L_800148D8;
    // 0x800148C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_800148C8:
    // 0x800148C8: b           L_800148D8
    // 0x800148CC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_800148D8;
    // 0x800148CC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800148D0:
    // 0x800148D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800148D4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_800148D8:
    // 0x800148D8: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800148DC: bne         $at, $zero, L_800148F0
    if (ctx->r1 != 0) {
        // 0x800148E0: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800148F0;
    }
    // 0x800148E0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800148E4: beq         $a2, $zero, L_80014884
    if (ctx->r6 == 0) {
        // 0x800148E8: nop
    
            goto L_80014884;
    }
    // 0x800148E8: nop

L_800148EC:
    // 0x800148EC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
L_800148F0:
    // 0x800148F0: bne         $at, $zero, L_80014968
    if (ctx->r1 != 0) {
        // 0x800148F4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80014968;
    }
    // 0x800148F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800148F8: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800148FC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80014900: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
L_80014904:
    // 0x80014904: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80014908: nop

    // 0x8001490C: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x80014910: nop

    // 0x80014914: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80014918: beq         $t5, $zero, L_80014928
    if (ctx->r13 == 0) {
        // 0x8001491C: nop
    
            goto L_80014928;
    }
    // 0x8001491C: nop

    // 0x80014920: b           L_80014954
    // 0x80014924: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_80014954;
    // 0x80014924: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80014928:
    // 0x80014928: lw          $t6, 0x40($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X40);
    // 0x8001492C: nop

    // 0x80014930: lhu         $t7, 0x30($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X30);
    // 0x80014934: nop

    // 0x80014938: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8001493C: bne         $t8, $zero, L_80014950
    if (ctx->r24 != 0) {
        // 0x80014940: nop
    
            goto L_80014950;
    }
    // 0x80014940: nop

    // 0x80014944: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80014948: b           L_80014954
    // 0x8001494C: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
        goto L_80014954;
    // 0x8001494C: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
L_80014950:
    // 0x80014950: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80014954:
    // 0x80014954: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014958: bne         $at, $zero, L_8001496C
    if (ctx->r1 != 0) {
        // 0x8001495C: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001496C;
    }
    // 0x8001495C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014960: beq         $a2, $zero, L_80014904
    if (ctx->r6 == 0) {
        // 0x80014964: nop
    
            goto L_80014904;
    }
    // 0x80014964: nop

L_80014968:
    // 0x80014968: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8001496C:
    // 0x8001496C: beq         $at, $zero, L_800149A4
    if (ctx->r1 == 0) {
        // 0x80014970: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_800149A4;
    }
    // 0x80014970: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80014974: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x80014978: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8001497C: addu        $t4, $a2, $t0
    ctx->r12 = ADD32(ctx->r6, ctx->r8);
    // 0x80014980: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80014984: addu        $a3, $a2, $t9
    ctx->r7 = ADD32(ctx->r6, ctx->r25);
    // 0x80014988: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8001498C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80014990: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80014994: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80014998: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8001499C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800149A0: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
L_800149A4:
    // 0x800149A4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800149A8: beq         $at, $zero, L_80014870
    if (ctx->r1 == 0) {
        // 0x800149AC: slt         $at, $a1, $v1
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014870;
    }
    // 0x800149AC: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_800149B0:
    // 0x800149B0: sh          $v1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r3;
    // 0x800149B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800149B8: jr          $ra
    // 0x800149BC: nop

    return;
    // 0x800149BC: nop

;}
RECOMP_FUNC void timetrial_ghost_full(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059E20: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059E24: lb          $t6, -0x2A64($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2A64);
    // 0x80059E28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80059E2C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80059E30: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80059E34: lh          $v0, -0x2A58($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2A58);
    // 0x80059E38: jr          $ra
    // 0x80059E3C: nop

    return;
    // 0x80059E3C: nop

;}
RECOMP_FUNC void level_world_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B1D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B1D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B1DC: bltz        $a0, L_8006B1FC
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B1E0: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8006B1FC;
    }
    // 0x8006B1E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006B1E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B1E8: lw          $t6, 0x1174($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1174);
    // 0x8006B1EC: nop

    // 0x8006B1F0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B1F4: bne         $at, $zero, L_8006B204
    if (ctx->r1 != 0) {
        // 0x8006B1F8: addiu       $a0, $zero, 0x1B
        ctx->r4 = ADD32(0, 0X1B);
            goto L_8006B204;
    }
    // 0x8006B1F8: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
L_8006B1FC:
    // 0x8006B1FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006B200: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
L_8006B204:
    // 0x8006B204: jal         0x8001E29C
    // 0x8006B208: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8006B208: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006B20C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006B210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B214: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x8006B218: lb          $v0, 0x0($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X0);
    // 0x8006B21C: jr          $ra
    // 0x8006B220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006B220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void alEvtqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern uint32_t dkr_audio_event_queue_next(uint8_t*, recomp_context*); ctx->r2 = dkr_audio_event_queue_next(rdram, ctx); return;
    // 0x800C92D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C92D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C92D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C92DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C92E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C92E4: jal         0x800C9A30
    // 0x800C92E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C92E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C92EC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C92F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C92F4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800C92F8: lw          $s0, 0x8($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X8);
    // 0x800C92FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C9300: beql        $s0, $zero, L_800C9338
    if (ctx->r16 == 0) {
        // 0x800C9304: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_800C9338;
    }
    goto skip_0;
    // 0x800C9304: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_0:
    // 0x800C9308: jal         0x800C8760
    // 0x800C930C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C930C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9310: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x800C9314: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800C9318: jal         0x800D3820
    // 0x800C931C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    alCopy(rdram, ctx);
        goto after_2;
    // 0x800C931C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x800C9320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9324: jal         0x800C8790
    // 0x800C9328: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800C9328: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800C932C: b           L_800C933C
    // 0x800C9330: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
        goto L_800C933C;
    // 0x800C9330: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800C9334: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_800C9338:
    // 0x800C9338: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_800C933C:
    // 0x800C933C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800C9340: jal         0x800C9A30
    // 0x800C9344: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x800C9344: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x800C9348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C934C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800C9350: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C9354: jr          $ra
    // 0x800C9358: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C9358: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void set_viewport_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066AA8: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x80066AAC: beq         $a1, $t0, L_80066AE8
    if (ctx->r5 == ctx->r8) {
        // 0x80066AB0: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_80066AE8;
    }
    // 0x80066AB0: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80066AB4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066AB8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066ABC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066AC0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066AC4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066AC8: addiu       $t7, $t7, -0x2F9C
    ctx->r15 = ADD32(ctx->r15, -0X2F9C);
    // 0x80066ACC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066AD0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066AD4: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x80066AD8: sw          $a1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r5;
    // 0x80066ADC: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80066AE0: b           L_80066B14
    // 0x80066AE4: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_80066B14;
    // 0x80066AE4: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_80066AE8:
    // 0x80066AE8: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80066AEC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80066AF0: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x80066AF4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80066AF8: addiu       $t2, $t2, -0x2F9C
    ctx->r10 = ADD32(ctx->r10, -0X2F9C);
    // 0x80066AFC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80066B00: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80066B04: lw          $t3, 0x30($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X30);
    // 0x80066B08: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80066B0C: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80066B10: sw          $t4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r12;
L_80066B14:
    // 0x80066B14: beq         $a2, $t0, L_80066B30
    if (ctx->r6 == ctx->r8) {
        // 0x80066B18: nop
    
            goto L_80066B30;
    }
    // 0x80066B18: nop

    // 0x80066B1C: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
    // 0x80066B20: sw          $a2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r6;
    // 0x80066B24: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x80066B28: b           L_80066B40
    // 0x80066B2C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
        goto L_80066B40;
    // 0x80066B2C: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
L_80066B30:
    // 0x80066B30: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x80066B34: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80066B38: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80066B3C: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
L_80066B40:
    // 0x80066B40: beq         $a3, $t0, L_80066B5C
    if (ctx->r7 == ctx->r8) {
        // 0x80066B44: nop
    
            goto L_80066B5C;
    }
    // 0x80066B44: nop

    // 0x80066B48: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x80066B4C: sw          $a3, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r7;
    // 0x80066B50: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x80066B54: b           L_80066B6C
    // 0x80066B58: sw          $t1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r9;
        goto L_80066B6C;
    // 0x80066B58: sw          $t1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r9;
L_80066B5C:
    // 0x80066B5C: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x80066B60: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80066B64: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80066B68: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_80066B6C:
    // 0x80066B6C: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80066B70: nop

    // 0x80066B74: beq         $v1, $t0, L_80066B90
    if (ctx->r3 == ctx->r8) {
        // 0x80066B78: nop
    
            goto L_80066B90;
    }
    // 0x80066B78: nop

    // 0x80066B7C: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80066B80: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x80066B84: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x80066B88: jr          $ra
    // 0x80066B8C: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    return;
    // 0x80066B8C: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
L_80066B90:
    // 0x80066B90: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x80066B94: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80066B98: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80066B9C: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x80066BA0: jr          $ra
    // 0x80066BA4: nop

    return;
    // 0x80066BA4: nop

;}
RECOMP_FUNC void obj_loop_snowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003827C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80038280: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80038284: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80038288: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003828C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80038290: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80038294: lh          $v1, 0x24($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X24);
    // 0x80038298: nop

    // 0x8003829C: bne         $v1, $zero, L_800382C0
    if (ctx->r3 != 0) {
        // 0x800382A0: nop
    
            goto L_800382C0;
    }
    // 0x800382A0: nop

    // 0x800382A4: lb          $a0, 0x38($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X38);
    // 0x800382A8: nop

    // 0x800382AC: beq         $a0, $zero, L_800382C0
    if (ctx->r4 == 0) {
        // 0x800382B0: andi        $t6, $a0, 0xFF
        ctx->r14 = ctx->r4 & 0XFF;
            goto L_800382C0;
    }
    // 0x800382B0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800382B4: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x800382B8: lh          $v1, 0x24($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X24);
    // 0x800382BC: nop

L_800382C0:
    // 0x800382C0: beq         $v1, $zero, L_80038314
    if (ctx->r3 == 0) {
        // 0x800382C4: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80038314;
    }
    // 0x800382C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800382C8: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x800382CC: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x800382D0: bne         $t0, $zero, L_800382FC
    if (ctx->r8 != 0) {
        // 0x800382D4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800382FC;
    }
    // 0x800382D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800382D8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800382DC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800382E0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x800382E4: addiu       $t8, $v0, 0x20
    ctx->r24 = ADD32(ctx->r2, 0X20);
    // 0x800382E8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800382EC: jal         0x80009558
    // 0x800382F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_0;
    // 0x800382F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x800382F4: b           L_80038314
    // 0x800382F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
        goto L_80038314;
    // 0x800382F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_800382FC:
    // 0x800382FC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80038300: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80038304: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80038308: jal         0x800096D8
    // 0x8003830C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    audspat_point_set_position(rdram, ctx);
        goto after_1;
    // 0x8003830C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x80038310: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_80038314:
    // 0x80038314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038318: jal         0x8001F460
    // 0x8003831C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F460(rdram, ctx);
        goto after_2;
    // 0x8003831C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80038320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80038324: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80038328: jr          $ra
    // 0x8003832C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003832C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80014B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014B50: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80014B54: sltiu       $at, $a3, 0xB
    ctx->r1 = ctx->r7 < 0XB ? 1 : 0;
    // 0x80014B58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80014B5C: beq         $at, $zero, L_80015340
    if (ctx->r1 == 0) {
        // 0x80014B60: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80015340;
    }
    // 0x80014B60: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80014B64: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80014B68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80014B6C: addu        $at, $at, $t6
    gpr jr_addend_80014B78 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80014B70: lw          $t6, 0x5588($at)
    ctx->r14 = ADD32(ctx->r1, 0X5588);
    // 0x80014B74: nop

    // 0x80014B78: jr          $t6
    // 0x80014B7C: nop

    switch (jr_addend_80014B78 >> 2) {
        case 0: goto L_80014B80; break;
        case 1: goto L_80014CCC; break;
        case 2: goto L_80014E18; break;
        case 3: goto L_80015340; break;
        case 4: goto L_80015340; break;
        case 5: goto L_80015340; break;
        case 6: goto L_80015340; break;
        case 7: goto L_80015340; break;
        case 8: goto L_80014F64; break;
        case 9: goto L_800150B0; break;
        case 10: goto L_800151FC; break;
        default: switch_error(__func__, 0x80014B78, 0x800E5588);
    }
    // 0x80014B7C: nop

L_80014B80:
    // 0x80014B80: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014B84: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014B88: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014B88: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014B8C: addiu       $t2, $t2, -0x51A8
    ctx->r10 = ADD32(ctx->r10, -0X51A8);
    // 0x80014B90: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014B94:
    // 0x80014B94: bne         $at, $zero, L_80014C0C
    if (ctx->r1 != 0) {
        // 0x80014B98: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014C0C;
    }
    // 0x80014B98: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014B9C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x80014BA0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80014BA4: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x80014BA8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014BAC: nop

    // 0x80014BB0: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014BB4: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014BB8: nop

    // 0x80014BBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014BC0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014BC4: nop

    // 0x80014BC8: bc1f        L_80014C0C
    if (!c1cs) {
        // 0x80014BCC: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014C0C;
    }
    // 0x80014BCC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014BD0:
    // 0x80014BD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014BD4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014BD8: bne         $at, $zero, L_80014C08
    if (ctx->r1 != 0) {
        // 0x80014BDC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014C08;
    }
    // 0x80014BDC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014BE0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014BE4: nop

    // 0x80014BE8: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014BEC: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014BF0: nop

    // 0x80014BF4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014BF8: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014BFC: nop

    // 0x80014C00: bc1t        L_80014BD0
    if (c1cs) {
        // 0x80014C04: nop
    
            goto L_80014BD0;
    }
    // 0x80014C04: nop

L_80014C08:
    // 0x80014C08: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014C0C:
    // 0x80014C0C: bne         $at, $zero, L_80014C80
    if (ctx->r1 != 0) {
        // 0x80014C10: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_80014C80;
    }
    // 0x80014C10: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80014C14: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80014C18: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80014C1C: addu        $a2, $t9, $t3
    ctx->r6 = ADD32(ctx->r25, ctx->r11);
    // 0x80014C20: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014C24: nop

    // 0x80014C28: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80014C2C: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014C30: nop

    // 0x80014C34: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014C38: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80014C3C: nop

    // 0x80014C40: bc1f        L_80014C84
    if (!c1cs) {
        // 0x80014C44: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80014C84;
    }
    // 0x80014C44: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014C48:
    // 0x80014C48: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014C4C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014C50: bne         $at, $zero, L_80014C80
    if (ctx->r1 != 0) {
        // 0x80014C54: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80014C80;
    }
    // 0x80014C54: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80014C58: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014C5C: nop

    // 0x80014C60: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80014C64: lwc1        $f16, 0x34($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014C68: nop

    // 0x80014C6C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014C70: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80014C74: nop

    // 0x80014C78: bc1t        L_80014C48
    if (c1cs) {
        // 0x80014C7C: nop
    
            goto L_80014C48;
    }
    // 0x80014C7C: nop

L_80014C80:
    // 0x80014C80: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014C84:
    // 0x80014C84: beq         $at, $zero, L_80014CB8
    if (ctx->r1 == 0) {
        // 0x80014C88: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80014CB8;
    }
    // 0x80014C88: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80014C8C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80014C90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014C94: addu        $t5, $a2, $t0
    ctx->r13 = ADD32(ctx->r6, ctx->r8);
    // 0x80014C98: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80014C9C: addu        $a3, $a2, $t4
    ctx->r7 = ADD32(ctx->r6, ctx->r12);
    // 0x80014CA0: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80014CA4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80014CA8: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x80014CAC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014CB0: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x80014CB4: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
L_80014CB8:
    // 0x80014CB8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014CBC: beq         $at, $zero, L_80014B94
    if (ctx->r1 == 0) {
        // 0x80014CC0: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014B94;
    }
    // 0x80014CC0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014CC4: jr          $ra
    // 0x80014CC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80014CC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80014CCC:
    // 0x80014CCC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014CD0: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014CD4: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014CD4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014CD8: addiu       $t2, $t2, -0x51A8
    ctx->r10 = ADD32(ctx->r10, -0X51A8);
    // 0x80014CDC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014CE0:
    // 0x80014CE0: bne         $at, $zero, L_80014D58
    if (ctx->r1 != 0) {
        // 0x80014CE4: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014D58;
    }
    // 0x80014CE4: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014CE8: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80014CEC: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80014CF0: addu        $a3, $t9, $t3
    ctx->r7 = ADD32(ctx->r25, ctx->r11);
    // 0x80014CF4: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014CF8: nop

    // 0x80014CFC: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80014D00: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014D04: nop

    // 0x80014D08: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014D0C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014D10: nop

    // 0x80014D14: bc1f        L_80014D58
    if (!c1cs) {
        // 0x80014D18: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014D58;
    }
    // 0x80014D18: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014D1C:
    // 0x80014D1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014D20: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014D24: bne         $at, $zero, L_80014D54
    if (ctx->r1 != 0) {
        // 0x80014D28: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014D54;
    }
    // 0x80014D28: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014D2C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014D30: nop

    // 0x80014D34: lwc1        $f10, 0x10($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80014D38: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014D3C: nop

    // 0x80014D40: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014D44: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014D48: nop

    // 0x80014D4C: bc1t        L_80014D1C
    if (c1cs) {
        // 0x80014D50: nop
    
            goto L_80014D1C;
    }
    // 0x80014D50: nop

L_80014D54:
    // 0x80014D54: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014D58:
    // 0x80014D58: bne         $at, $zero, L_80014DCC
    if (ctx->r1 != 0) {
        // 0x80014D5C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80014DCC;
    }
    // 0x80014D5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80014D60: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80014D64: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80014D68: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x80014D6C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014D70: nop

    // 0x80014D74: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80014D78: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014D7C: nop

    // 0x80014D80: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014D84: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80014D88: nop

    // 0x80014D8C: bc1f        L_80014DD0
    if (!c1cs) {
        // 0x80014D90: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80014DD0;
    }
    // 0x80014D90: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014D94:
    // 0x80014D94: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014D98: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014D9C: bne         $at, $zero, L_80014DCC
    if (ctx->r1 != 0) {
        // 0x80014DA0: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80014DCC;
    }
    // 0x80014DA0: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80014DA4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014DA8: nop

    // 0x80014DAC: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80014DB0: lwc1        $f16, 0x34($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014DB4: nop

    // 0x80014DB8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014DBC: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80014DC0: nop

    // 0x80014DC4: bc1t        L_80014D94
    if (c1cs) {
        // 0x80014DC8: nop
    
            goto L_80014D94;
    }
    // 0x80014DC8: nop

L_80014DCC:
    // 0x80014DCC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014DD0:
    // 0x80014DD0: beq         $at, $zero, L_80014E04
    if (ctx->r1 == 0) {
        // 0x80014DD4: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80014E04;
    }
    // 0x80014DD4: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80014DD8: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80014DDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014DE0: addu        $t7, $a2, $t0
    ctx->r15 = ADD32(ctx->r6, ctx->r8);
    // 0x80014DE4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80014DE8: addu        $a3, $a2, $t6
    ctx->r7 = ADD32(ctx->r6, ctx->r14);
    // 0x80014DEC: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80014DF0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80014DF4: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80014DF8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014DFC: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x80014E00: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
L_80014E04:
    // 0x80014E04: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E08: beq         $at, $zero, L_80014CE0
    if (ctx->r1 == 0) {
        // 0x80014E0C: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014CE0;
    }
    // 0x80014E0C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E10: jr          $ra
    // 0x80014E14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80014E14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80014E18:
    // 0x80014E18: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E1C: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014E20: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014E20: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014E24: addiu       $t2, $t2, -0x51A8
    ctx->r10 = ADD32(ctx->r10, -0X51A8);
    // 0x80014E28: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014E2C:
    // 0x80014E2C: bne         $at, $zero, L_80014EA4
    if (ctx->r1 != 0) {
        // 0x80014E30: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014EA4;
    }
    // 0x80014E30: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014E34: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80014E38: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80014E3C: addu        $a3, $t4, $t5
    ctx->r7 = ADD32(ctx->r12, ctx->r13);
    // 0x80014E40: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014E44: nop

    // 0x80014E48: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80014E4C: lwc1        $f6, 0x34($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014E50: nop

    // 0x80014E54: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014E58: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014E5C: nop

    // 0x80014E60: bc1f        L_80014EA4
    if (!c1cs) {
        // 0x80014E64: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014EA4;
    }
    // 0x80014E64: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014E68:
    // 0x80014E68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014E6C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014E70: bne         $at, $zero, L_80014EA0
    if (ctx->r1 != 0) {
        // 0x80014E74: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014EA0;
    }
    // 0x80014E74: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014E78: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014E7C: nop

    // 0x80014E80: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80014E84: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014E88: nop

    // 0x80014E8C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014E90: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014E94: nop

    // 0x80014E98: bc1t        L_80014E68
    if (c1cs) {
        // 0x80014E9C: nop
    
            goto L_80014E68;
    }
    // 0x80014E9C: nop

L_80014EA0:
    // 0x80014EA0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014EA4:
    // 0x80014EA4: bne         $at, $zero, L_80014F18
    if (ctx->r1 != 0) {
        // 0x80014EA8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_80014F18;
    }
    // 0x80014EA8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80014EAC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80014EB0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80014EB4: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80014EB8: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014EBC: nop

    // 0x80014EC0: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80014EC4: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014EC8: nop

    // 0x80014ECC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80014ED0: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80014ED4: nop

    // 0x80014ED8: bc1f        L_80014F1C
    if (!c1cs) {
        // 0x80014EDC: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80014F1C;
    }
    // 0x80014EDC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014EE0:
    // 0x80014EE0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014EE4: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014EE8: bne         $at, $zero, L_80014F18
    if (ctx->r1 != 0) {
        // 0x80014EEC: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80014F18;
    }
    // 0x80014EEC: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80014EF0: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80014EF4: nop

    // 0x80014EF8: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80014EFC: lwc1        $f16, 0x34($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80014F00: nop

    // 0x80014F04: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80014F08: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80014F0C: nop

    // 0x80014F10: bc1t        L_80014EE0
    if (c1cs) {
        // 0x80014F14: nop
    
            goto L_80014EE0;
    }
    // 0x80014F14: nop

L_80014F18:
    // 0x80014F18: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80014F1C:
    // 0x80014F1C: beq         $at, $zero, L_80014F50
    if (ctx->r1 == 0) {
        // 0x80014F20: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80014F50;
    }
    // 0x80014F20: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80014F24: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80014F28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014F2C: addu        $t9, $a2, $t0
    ctx->r25 = ADD32(ctx->r6, ctx->r8);
    // 0x80014F30: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80014F34: addu        $a3, $a2, $t8
    ctx->r7 = ADD32(ctx->r6, ctx->r24);
    // 0x80014F38: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80014F3C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80014F40: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80014F44: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80014F48: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80014F4C: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
L_80014F50:
    // 0x80014F50: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014F54: beq         $at, $zero, L_80014E2C
    if (ctx->r1 == 0) {
        // 0x80014F58: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014E2C;
    }
    // 0x80014F58: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014F5C: jr          $ra
    // 0x80014F60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80014F60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80014F64:
    // 0x80014F64: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014F68: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80014F6C: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80014F6C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80014F70: addiu       $t2, $t2, -0x51A8
    ctx->r10 = ADD32(ctx->r10, -0X51A8);
    // 0x80014F74: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80014F78:
    // 0x80014F78: bne         $at, $zero, L_80014FF0
    if (ctx->r1 != 0) {
        // 0x80014F7C: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014FF0;
    }
    // 0x80014F7C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80014F80: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80014F84: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80014F88: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80014F8C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014F90: nop

    // 0x80014F94: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014F98: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014F9C: nop

    // 0x80014FA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80014FA4: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80014FA8: nop

    // 0x80014FAC: bc1f        L_80014FF0
    if (!c1cs) {
        // 0x80014FB0: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80014FF0;
    }
    // 0x80014FB0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014FB4:
    // 0x80014FB4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014FB8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014FBC: bne         $at, $zero, L_80014FEC
    if (ctx->r1 != 0) {
        // 0x80014FC0: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80014FEC;
    }
    // 0x80014FC0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80014FC4: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80014FC8: nop

    // 0x80014FCC: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80014FD0: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80014FD4: nop

    // 0x80014FD8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80014FDC: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80014FE0: nop

    // 0x80014FE4: bc1t        L_80014FB4
    if (c1cs) {
        // 0x80014FE8: nop
    
            goto L_80014FB4;
    }
    // 0x80014FE8: nop

L_80014FEC:
    // 0x80014FEC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80014FF0:
    // 0x80014FF0: bne         $at, $zero, L_80015064
    if (ctx->r1 != 0) {
        // 0x80014FF4: sll         $t3, $a0, 2
        ctx->r11 = S32(ctx->r4 << 2);
            goto L_80015064;
    }
    // 0x80014FF4: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80014FF8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80014FFC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80015000: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80015004: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80015008: nop

    // 0x8001500C: lwc1        $f4, 0x34($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80015010: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80015014: nop

    // 0x80015018: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001501C: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80015020: nop

    // 0x80015024: bc1f        L_80015068
    if (!c1cs) {
        // 0x80015028: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80015068;
    }
    // 0x80015028: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_8001502C:
    // 0x8001502C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80015030: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015034: bne         $at, $zero, L_80015064
    if (ctx->r1 != 0) {
        // 0x80015038: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80015064;
    }
    // 0x80015038: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8001503C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80015040: nop

    // 0x80015044: lwc1        $f10, 0x34($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80015048: lwc1        $f16, 0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8001504C: nop

    // 0x80015050: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015054: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x80015058: nop

    // 0x8001505C: bc1t        L_8001502C
    if (c1cs) {
        // 0x80015060: nop
    
            goto L_8001502C;
    }
    // 0x80015060: nop

L_80015064:
    // 0x80015064: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80015068:
    // 0x80015068: beq         $at, $zero, L_8001509C
    if (ctx->r1 == 0) {
        // 0x8001506C: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_8001509C;
    }
    // 0x8001506C: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80015070: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80015074: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015078: addu        $t4, $a2, $t0
    ctx->r12 = ADD32(ctx->r6, ctx->r8);
    // 0x8001507C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80015080: addu        $a3, $a2, $t3
    ctx->r7 = ADD32(ctx->r6, ctx->r11);
    // 0x80015084: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80015088: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8001508C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80015090: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80015094: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80015098: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
L_8001509C:
    // 0x8001509C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800150A0: beq         $at, $zero, L_80014F78
    if (ctx->r1 == 0) {
        // 0x800150A4: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014F78;
    }
    // 0x800150A4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800150A8: jr          $ra
    // 0x800150AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800150AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800150B0:
    // 0x800150B0: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800150B4: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x800150B8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x800150B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800150BC: addiu       $t2, $t2, -0x51A8
    ctx->r10 = ADD32(ctx->r10, -0X51A8);
    // 0x800150C0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_800150C4:
    // 0x800150C4: bne         $at, $zero, L_8001513C
    if (ctx->r1 != 0) {
        // 0x800150C8: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001513C;
    }
    // 0x800150C8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800150CC: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800150D0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800150D4: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x800150D8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x800150DC: nop

    // 0x800150E0: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800150E4: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800150E8: nop

    // 0x800150EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800150F0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x800150F4: nop

    // 0x800150F8: bc1f        L_8001513C
    if (!c1cs) {
        // 0x800150FC: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001513C;
    }
    // 0x800150FC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80015100:
    // 0x80015100: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015104: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015108: bne         $at, $zero, L_80015138
    if (ctx->r1 != 0) {
        // 0x8001510C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80015138;
    }
    // 0x8001510C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80015110: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80015114: nop

    // 0x80015118: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x8001511C: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80015120: nop

    // 0x80015124: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015128: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x8001512C: nop

    // 0x80015130: bc1t        L_80015100
    if (c1cs) {
        // 0x80015134: nop
    
            goto L_80015100;
    }
    // 0x80015134: nop

L_80015138:
    // 0x80015138: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8001513C:
    // 0x8001513C: bne         $at, $zero, L_800151B0
    if (ctx->r1 != 0) {
        // 0x80015140: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_800151B0;
    }
    // 0x80015140: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80015144: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80015148: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8001514C: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80015150: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80015154: nop

    // 0x80015158: lwc1        $f4, 0x34($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8001515C: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80015160: nop

    // 0x80015164: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80015168: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x8001516C: nop

    // 0x80015170: bc1f        L_800151B4
    if (!c1cs) {
        // 0x80015174: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800151B4;
    }
    // 0x80015174: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80015178:
    // 0x80015178: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001517C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015180: bne         $at, $zero, L_800151B0
    if (ctx->r1 != 0) {
        // 0x80015184: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_800151B0;
    }
    // 0x80015184: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80015188: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8001518C: nop

    // 0x80015190: lwc1        $f10, 0x34($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80015194: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80015198: nop

    // 0x8001519C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800151A0: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x800151A4: nop

    // 0x800151A8: bc1t        L_80015178
    if (c1cs) {
        // 0x800151AC: nop
    
            goto L_80015178;
    }
    // 0x800151AC: nop

L_800151B0:
    // 0x800151B0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_800151B4:
    // 0x800151B4: beq         $at, $zero, L_800151E8
    if (ctx->r1 == 0) {
        // 0x800151B8: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_800151E8;
    }
    // 0x800151B8: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x800151BC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800151C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800151C4: addu        $t6, $a2, $t0
    ctx->r14 = ADD32(ctx->r6, ctx->r8);
    // 0x800151C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800151CC: addu        $a3, $a2, $t5
    ctx->r7 = ADD32(ctx->r6, ctx->r13);
    // 0x800151D0: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x800151D4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800151D8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800151DC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800151E0: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800151E4: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
L_800151E8:
    // 0x800151E8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800151EC: beq         $at, $zero, L_800150C4
    if (ctx->r1 == 0) {
        // 0x800151F0: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800150C4;
    }
    // 0x800151F0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800151F4: jr          $ra
    // 0x800151F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800151F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800151FC:
    // 0x800151FC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015200: bne         $at, $zero, L_80015340
    if (ctx->r1 != 0) {
        // 0x80015204: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80015340;
    }
    // 0x80015204: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80015208: addiu       $t2, $t2, -0x51A8
    ctx->r10 = ADD32(ctx->r10, -0X51A8);
    // 0x8001520C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80015210:
    // 0x80015210: bne         $at, $zero, L_80015288
    if (ctx->r1 != 0) {
        // 0x80015214: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80015288;
    }
    // 0x80015214: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80015218: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001521C: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80015220: addu        $a3, $t3, $t4
    ctx->r7 = ADD32(ctx->r11, ctx->r12);
    // 0x80015224: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80015228: nop

    // 0x8001522C: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80015230: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80015234: nop

    // 0x80015238: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001523C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80015240: nop

    // 0x80015244: bc1f        L_80015288
    if (!c1cs) {
        // 0x80015248: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80015288;
    }
    // 0x80015248: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8001524C:
    // 0x8001524C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015250: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015254: bne         $at, $zero, L_80015284
    if (ctx->r1 != 0) {
        // 0x80015258: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80015284;
    }
    // 0x80015258: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8001525C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80015260: nop

    // 0x80015264: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80015268: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8001526C: nop

    // 0x80015270: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80015274: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80015278: nop

    // 0x8001527C: bc1t        L_8001524C
    if (c1cs) {
        // 0x80015280: nop
    
            goto L_8001524C;
    }
    // 0x80015280: nop

L_80015284:
    // 0x80015284: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_80015288:
    // 0x80015288: bne         $at, $zero, L_800152FC
    if (ctx->r1 != 0) {
        // 0x8001528C: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_800152FC;
    }
    // 0x8001528C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80015290: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80015294: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80015298: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8001529C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800152A0: nop

    // 0x800152A4: lwc1        $f4, 0x34($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X34);
    // 0x800152A8: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800152AC: nop

    // 0x800152B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800152B4: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x800152B8: nop

    // 0x800152BC: bc1f        L_80015300
    if (!c1cs) {
        // 0x800152C0: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80015300;
    }
    // 0x800152C0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_800152C4:
    // 0x800152C4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800152C8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800152CC: bne         $at, $zero, L_800152FC
    if (ctx->r1 != 0) {
        // 0x800152D0: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_800152FC;
    }
    // 0x800152D0: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800152D4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800152D8: nop

    // 0x800152DC: lwc1        $f10, 0x34($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X34);
    // 0x800152E0: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800152E4: nop

    // 0x800152E8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800152EC: c.le.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl <= ctx->f18.fl;
    // 0x800152F0: nop

    // 0x800152F4: bc1t        L_800152C4
    if (c1cs) {
        // 0x800152F8: nop
    
            goto L_800152C4;
    }
    // 0x800152F8: nop

L_800152FC:
    // 0x800152FC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80015300:
    // 0x80015300: beq         $at, $zero, L_80015334
    if (ctx->r1 == 0) {
        // 0x80015304: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80015334;
    }
    // 0x80015304: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80015308: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8001530C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015310: addu        $t8, $a2, $t0
    ctx->r24 = ADD32(ctx->r6, ctx->r8);
    // 0x80015314: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80015318: addu        $a3, $a2, $t7
    ctx->r7 = ADD32(ctx->r6, ctx->r15);
    // 0x8001531C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80015320: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80015324: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80015328: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001532C: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80015330: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
L_80015334:
    // 0x80015334: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015338: beq         $at, $zero, L_80015210
    if (ctx->r1 == 0) {
        // 0x8001533C: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80015210;
    }
    // 0x8001533C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_80015340:
    // 0x80015340: jr          $ra
    // 0x80015344: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80015344: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void fb_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A520: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007A524: lw          $v1, 0x62C8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X62C8);
    // 0x8007A528: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007A52C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8007A530: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8007A534: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007A538: lw          $t8, 0x62B8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X62B8);
    // 0x8007A53C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007A540: lw          $t7, 0x62B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62B0);
    // 0x8007A544: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8007A548: jr          $ra
    // 0x8007A54C: or          $v0, $t7, $t9
    ctx->r2 = ctx->r15 | ctx->r25;
    return;
    // 0x8007A54C: or          $v0, $t7, $t9
    ctx->r2 = ctx->r15 | ctx->r25;
;}
RECOMP_FUNC void obj_loop_bridge_whaleramp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CA68: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003CA6C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003CA70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003CA74: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003CA78: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8003CA7C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003CA80: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003CA84: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003CA88: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8003CA8C: lw          $t0, 0x3C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X3C);
    // 0x8003CA90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003CA94: bne         $t7, $zero, L_8003CAB4
    if (ctx->r15 != 0) {
        // 0x8003CA98: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_8003CAB4;
    }
    // 0x8003CA98: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8003CA9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003CAA0: lwc1        $f9, 0x6178($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6178);
    // 0x8003CAA4: lwc1        $f8, 0x617C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X617C);
    // 0x8003CAA8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003CAAC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003CAB0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_8003CAB4:
    // 0x8003CAB4: lbu         $t8, 0xB($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XB);
    // 0x8003CAB8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003CABC: beq         $t8, $at, L_8003CBEC
    if (ctx->r24 == ctx->r1) {
        // 0x8003CAC0: nop
    
            goto L_8003CBEC;
    }
    // 0x8003CAC0: nop

    // 0x8003CAC4: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x8003CAC8: nop

    // 0x8003CACC: beq         $t9, $zero, L_8003CB74
    if (ctx->r25 == 0) {
        // 0x8003CAD0: nop
    
            goto L_8003CB74;
    }
    // 0x8003CAD0: nop

    // 0x8003CAD4: lb          $t1, 0xE($t0)
    ctx->r9 = MEM_B(ctx->r8, 0XE);
    // 0x8003CAD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003CADC: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8003CAE0: nop

    // 0x8003CAE4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003CAE8: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8003CAEC: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x8003CAF0: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8003CAF4: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8003CAF8: nop

    // 0x8003CAFC: bc1f        L_8003CB3C
    if (!c1cs) {
        // 0x8003CB00: nop
    
            goto L_8003CB3C;
    }
    // 0x8003CB00: nop

    // 0x8003CB04: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CB08: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CB0C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8003CB10: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CB14: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8003CB18: nop

    // 0x8003CB1C: bc1f        L_8003CD20
    if (!c1cs) {
        // 0x8003CB20: nop
    
            goto L_8003CD20;
    }
    // 0x8003CB20: nop

    // 0x8003CB24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003CB28: nop

    // 0x8003CB2C: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8003CB30: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8003CB34: b           L_8003CD20
    // 0x8003CB38: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
        goto L_8003CD20;
    // 0x8003CB38: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8003CB3C:
    // 0x8003CB3C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CB40: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CB44: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8003CB48: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CB4C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8003CB50: nop

    // 0x8003CB54: bc1f        L_8003CD20
    if (!c1cs) {
        // 0x8003CB58: nop
    
            goto L_8003CD20;
    }
    // 0x8003CB58: nop

    // 0x8003CB5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CB60: nop

    // 0x8003CB64: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8003CB68: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8003CB6C: b           L_8003CD20
    // 0x8003CB70: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
        goto L_8003CD20;
    // 0x8003CB70: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
L_8003CB74:
    // 0x8003CB74: lbu         $t2, 0xC($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XC);
    // 0x8003CB78: nop

    // 0x8003CB7C: blez        $t2, L_8003CBB8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8003CB80: nop
    
            goto L_8003CBB8;
    }
    // 0x8003CB80: nop

    // 0x8003CB84: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CB88: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CB8C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CB90: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003CB94: nop

    // 0x8003CB98: bc1f        L_8003CD20
    if (!c1cs) {
        // 0x8003CB9C: nop
    
            goto L_8003CD20;
    }
    // 0x8003CB9C: nop

    // 0x8003CBA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003CBA4: nop

    // 0x8003CBA8: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8003CBAC: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8003CBB0: b           L_8003CD20
    // 0x8003CBB4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
        goto L_8003CD20;
    // 0x8003CBB4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_8003CBB8:
    // 0x8003CBB8: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003CBBC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003CBC0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CBC4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8003CBC8: nop

    // 0x8003CBCC: bc1f        L_8003CD20
    if (!c1cs) {
        // 0x8003CBD0: nop
    
            goto L_8003CD20;
    }
    // 0x8003CBD0: nop

    // 0x8003CBD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003CBD8: nop

    // 0x8003CBDC: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8003CBE0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8003CBE4: b           L_8003CD20
    // 0x8003CBE8: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
        goto L_8003CD20;
    // 0x8003CBE8: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_8003CBEC:
    // 0x8003CBEC: lw          $t3, 0x78($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X78);
    // 0x8003CBF0: nop

    // 0x8003CBF4: beq         $t3, $zero, L_8003CC84
    if (ctx->r11 == 0) {
        // 0x8003CBF8: nop
    
            goto L_8003CC84;
    }
    // 0x8003CBF8: nop

    // 0x8003CBFC: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8003CC00: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8003CC04: slti        $at, $v0, -0x12FF
    ctx->r1 = SIGNED(ctx->r2) < -0X12FF ? 1 : 0;
    // 0x8003CC08: bne         $at, $zero, L_8003CC2C
    if (ctx->r1 != 0) {
        // 0x8003CC0C: sll         $t5, $t4, 2
        ctx->r13 = S32(ctx->r12 << 2);
            goto L_8003CC2C;
    }
    // 0x8003CC0C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8003CC10: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8003CC14: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8003CC18: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8003CC1C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8003CC20: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8003CC24: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x8003CC28: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
L_8003CC2C:
    // 0x8003CC2C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8003CC30: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8003CC34: bne         $t7, $zero, L_8003CD20
    if (ctx->r15 != 0) {
        // 0x8003CC38: addiu       $a2, $sp, 0x4C
        ctx->r6 = ADD32(ctx->r29, 0X4C);
            goto L_8003CD20;
    }
    // 0x8003CC38: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8003CC3C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
    // 0x8003CC40: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8003CC44: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x8003CC48: jal         0x8001E36C
    // 0x8003CC4C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    obj_bridge_pos(rdram, ctx);
        goto after_0;
    // 0x8003CC4C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x8003CC50: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8003CC54: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8003CC58: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8003CC5C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8003CC60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003CC64: addiu       $t9, $v1, 0x4
    ctx->r25 = ADD32(ctx->r3, 0X4);
    // 0x8003CC68: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003CC6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003CC70: jal         0x80009558
    // 0x8003CC74: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_1;
    // 0x8003CC74: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    after_1:
    // 0x8003CC78: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CC7C: b           L_8003CD24
    // 0x8003CC80: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
        goto L_8003CD24;
    // 0x8003CC80: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
L_8003CC84:
    // 0x8003CC84: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8003CC88: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8003CC8C: bgez        $v0, L_8003CCFC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003CC90: sll         $t2, $t1, 2
        ctx->r10 = S32(ctx->r9 << 2);
            goto L_8003CCFC;
    }
    // 0x8003CC90: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8003CC94: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8003CC98: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8003CC9C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8003CCA0: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x8003CCA4: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x8003CCA8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8003CCAC: bne         $t4, $zero, L_8003CD20
    if (ctx->r12 != 0) {
        // 0x8003CCB0: addiu       $a2, $sp, 0x40
        ctx->r6 = ADD32(ctx->r29, 0X40);
            goto L_8003CD20;
    }
    // 0x8003CCB0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8003CCB4: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
    // 0x8003CCB8: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8003CCBC: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x8003CCC0: jal         0x8001E36C
    // 0x8003CCC4: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    obj_bridge_pos(rdram, ctx);
        goto after_2;
    // 0x8003CCC4: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x8003CCC8: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8003CCCC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8003CCD0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8003CCD4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8003CCD8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003CCDC: addiu       $t6, $v1, 0x4
    ctx->r14 = ADD32(ctx->r3, 0X4);
    // 0x8003CCE0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8003CCE4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003CCE8: jal         0x80009558
    // 0x8003CCEC: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x8003CCEC: addiu       $a0, $zero, 0x249
    ctx->r4 = ADD32(0, 0X249);
    after_3:
    // 0x8003CCF0: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CCF4: b           L_8003CD24
    // 0x8003CCF8: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
        goto L_8003CD24;
    // 0x8003CCF8: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
L_8003CCFC:
    // 0x8003CCFC: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8003CD00: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8003CD04: nop

    // 0x8003CD08: beq         $a0, $zero, L_8003CD20
    if (ctx->r4 == 0) {
        // 0x8003CD0C: nop
    
            goto L_8003CD20;
    }
    // 0x8003CD0C: nop

    // 0x8003CD10: jal         0x800096F8
    // 0x8003CD14: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    audspat_point_stop(rdram, ctx);
        goto after_4;
    // 0x8003CD14: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_4:
    // 0x8003CD18: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CD1C: nop

L_8003CD20:
    // 0x8003CD20: lbu         $v1, 0xB($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XB);
L_8003CD24:
    // 0x8003CD24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003CD28: beq         $v1, $zero, L_8003CD40
    if (ctx->r3 == 0) {
        // 0x8003CD2C: nop
    
            goto L_8003CD40;
    }
    // 0x8003CD2C: nop

    // 0x8003CD30: beq         $v1, $at, L_8003CD6C
    if (ctx->r3 == ctx->r1) {
        // 0x8003CD34: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8003CD6C;
    }
    // 0x8003CD34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003CD38: b           L_8003CDE0
    // 0x8003CD3C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
        goto L_8003CDE0;
    // 0x8003CD3C: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
L_8003CD40:
    // 0x8003CD40: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CD44: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8003CD48: lbu         $t8, 0xC($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XC);
    // 0x8003CD4C: lbu         $t7, 0x13($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X13);
    // 0x8003CD50: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003CD54: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003CD58: beq         $at, $zero, L_8003CE2C
    if (ctx->r1 == 0) {
        // 0x8003CD5C: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_8003CE2C;
    }
    // 0x8003CD5C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003CD60: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CD64: b           L_8003CE28
    // 0x8003CD68: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
        goto L_8003CE28;
    // 0x8003CD68: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
L_8003CD6C:
    // 0x8003CD6C: sw          $t1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r9;
    // 0x8003CD70: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8003CD74: jal         0x8001BAC8
    // 0x8003CD78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_5;
    // 0x8003CD78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8003CD7C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CD80: beq         $v0, $zero, L_8003CDD0
    if (ctx->r2 == 0) {
        // 0x8003CD84: nop
    
            goto L_8003CDD0;
    }
    // 0x8003CD84: nop

    // 0x8003CD88: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x8003CD8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003CD90: lb          $v1, 0x1D6($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X1D6);
    // 0x8003CD94: nop

    // 0x8003CD98: beq         $v1, $at, L_8003CDB0
    if (ctx->r3 == ctx->r1) {
        // 0x8003CD9C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003CDB0;
    }
    // 0x8003CD9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003CDA0: beq         $v1, $at, L_8003CDB8
    if (ctx->r3 == ctx->r1) {
        // 0x8003CDA4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8003CDB8;
    }
    // 0x8003CDA4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8003CDA8: b           L_8003CDB8
    // 0x8003CDAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003CDB8;
    // 0x8003CDAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003CDB0:
    // 0x8003CDB0: b           L_8003CDB8
    // 0x8003CDB4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8003CDB8;
    // 0x8003CDB4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8003CDB8:
    // 0x8003CDB8: lbu         $t2, 0xF($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XF);
    // 0x8003CDBC: nop

    // 0x8003CDC0: and         $t3, $t2, $v0
    ctx->r11 = ctx->r10 & ctx->r2;
    // 0x8003CDC4: beq         $t3, $zero, L_8003CDD0
    if (ctx->r11 == 0) {
        // 0x8003CDC8: nop
    
            goto L_8003CDD0;
    }
    // 0x8003CDC8: nop

    // 0x8003CDCC: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003CDD0:
    // 0x8003CDD0: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CDD4: b           L_8003CE2C
    // 0x8003CDD8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
        goto L_8003CE2C;
    // 0x8003CDD8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003CDDC: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
L_8003CDE0:
    // 0x8003CDE0: jal         0x8001E2EC
    // 0x8003CDE4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    is_bridge_raised(rdram, ctx);
        goto after_6;
    // 0x8003CDE4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_6:
    // 0x8003CDE8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8003CDEC: beq         $v0, $zero, L_8003CE04
    if (ctx->r2 == 0) {
        // 0x8003CDF0: nop
    
            goto L_8003CE04;
    }
    // 0x8003CDF0: nop

    // 0x8003CDF4: lbu         $t4, 0xD($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XD);
    // 0x8003CDF8: nop

    // 0x8003CDFC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8003CE00: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
L_8003CE04:
    // 0x8003CE04: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8003CE08: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8003CE0C: blez        $v0, L_8003CE1C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003CE10: subu        $t7, $v0, $t6
        ctx->r15 = SUB32(ctx->r2, ctx->r14);
            goto L_8003CE1C;
    }
    // 0x8003CE10: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8003CE14: b           L_8003CE20
    // 0x8003CE18: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
        goto L_8003CE20;
    // 0x8003CE18: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
L_8003CE1C:
    // 0x8003CE1C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003CE20:
    // 0x8003CE20: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE24: nop

L_8003CE28:
    // 0x8003CE28: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8003CE2C:
    // 0x8003CE2C: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
    // 0x8003CE30: lw          $t9, 0x4C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE34: nop

    // 0x8003CE38: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8003CE3C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003CE40: nop

    // 0x8003CE44: lh          $t1, 0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X14);
    // 0x8003CE48: nop

    // 0x8003CE4C: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x8003CE50: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    // 0x8003CE54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003CE58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003CE5C: jr          $ra
    // 0x8003CE60: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003CE60: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void timetrial_staff_unbeaten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B650: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B654: lbu         $v0, -0x38C8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X38C8);
    // 0x8001B658: nop

    // 0x8001B65C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001B660: jr          $ra
    // 0x8001B664: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8001B664: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void obj_loop_char_select(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { extern int dkr_legacy_character_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*); static const uint32_t dkr_character_menu_fields[] = { 0x801263d4U, 0x801263dcU, 0x801263e8U, 0x801263f0U, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df480U, 0x800df4bcU, 0x800df47cU, 0x801263a0U, 0x801263ccU, 0x800e3690U, 0x800e36c8U, 0x80126808U, 0x801263c0U, 0x8011ae5cU, 0x8011aec8U }; if (dkr_legacy_character_menu(rdram, ctx, 6U, dkr_character_menu_fields)) return; }
    // 0x8003833C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80038340: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80038344: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80038348: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003834C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80038350: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80038354: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80038358: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8003835C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80038360: jal         0x8001F460
    // 0x80038364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80038364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80038368: lw          $v1, 0x64($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X64);
    // 0x8003836C: sw          $zero, 0x74($s2)
    MEM_W(0X74, ctx->r18) = 0;
    // 0x80038370: beq         $v1, $zero, L_800386F8
    if (ctx->r3 == 0) {
        // 0x80038374: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800386F8;
    }
    // 0x80038374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80038378: lb          $t7, 0x3A($s2)
    ctx->r15 = MEM_B(ctx->r18, 0X3A);
    // 0x8003837C: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    // 0x80038380: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80038384: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80038388: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8003838C: nop

    // 0x80038390: beq         $v0, $zero, L_800386F8
    if (ctx->r2 == 0) {
        // 0x80038394: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800386F8;
    }
    // 0x80038394: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80038398: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x8003839C: jal         0x8009ECD0
    // 0x800383A0: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    is_drumstick_unlocked(rdram, ctx);
        goto after_1;
    // 0x800383A0: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_1:
    // 0x800383A4: beq         $v0, $zero, L_800383D8
    if (ctx->r2 == 0) {
        // 0x800383A8: nop
    
            goto L_800383D8;
    }
    // 0x800383A8: nop

    // 0x800383AC: jal         0x8009ECB8
    // 0x800383B0: nop

    is_tt_unlocked(rdram, ctx);
        goto after_2;
    // 0x800383B0: nop

    after_2:
    // 0x800383B4: beq         $v0, $zero, L_800383CC
    if (ctx->r2 == 0) {
        // 0x800383B8: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_800383CC;
    }
    // 0x800383B8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800383BC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800383C0: addiu       $a2, $a2, -0x3590
    ctx->r6 = ADD32(ctx->r6, -0X3590);
    // 0x800383C4: b           L_80038400
    // 0x800383C8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_80038400;
    // 0x800383C8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_800383CC:
    // 0x800383CC: addiu       $a2, $a2, -0x35A8
    ctx->r6 = ADD32(ctx->r6, -0X35A8);
    // 0x800383D0: b           L_80038400
    // 0x800383D4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
        goto L_80038400;
    // 0x800383D4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_800383D8:
    // 0x800383D8: jal         0x8009ECB8
    // 0x800383DC: nop

    is_tt_unlocked(rdram, ctx);
        goto after_3;
    // 0x800383DC: nop

    after_3:
    // 0x800383E0: beq         $v0, $zero, L_800383F8
    if (ctx->r2 == 0) {
        // 0x800383E4: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_800383F8;
    }
    // 0x800383E4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800383E8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800383EC: addiu       $a2, $a2, -0x359C
    ctx->r6 = ADD32(ctx->r6, -0X359C);
    // 0x800383F0: b           L_80038400
    // 0x800383F4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
        goto L_80038400;
    // 0x800383F4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_800383F8:
    // 0x800383F8: addiu       $a2, $a2, -0x35B0
    ctx->r6 = ADD32(ctx->r6, -0X35B0);
    // 0x800383FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80038400:
    // 0x80038400: blez        $a0, L_8003843C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80038404: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003843C;
    }
    // 0x80038404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038408: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8003840C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80038410: lh          $v1, 0x28($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X28);
    // 0x80038414: nop

L_80038418:
    // 0x80038418: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8003841C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80038420: bne         $v1, $t2, L_8003842C
    if (ctx->r3 != ctx->r10) {
        // 0x80038424: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8003842C;
    }
    // 0x80038424: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80038428: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8003842C:
    // 0x8003842C: beq         $at, $zero, L_8003843C
    if (ctx->r1 == 0) {
        // 0x80038430: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8003843C;
    }
    // 0x80038430: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80038434: beq         $s0, $zero, L_80038418
    if (ctx->r16 == 0) {
        // 0x80038438: nop
    
            goto L_80038418;
    }
    // 0x80038438: nop

L_8003843C:
    // 0x8003843C: beq         $s0, $zero, L_800385F8
    if (ctx->r16 == 0) {
        // 0x80038440: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800385F8;
    }
    // 0x80038440: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80038444: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80038448: sb          $t3, 0x3B($s2)
    MEM_B(0X3B, ctx->r18) = ctx->r11;
    // 0x8003844C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80038450: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80038454: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80038458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003845C:
    // 0x8003845C: sb          $v1, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r3;
    // 0x80038460: jal         0x8009C280
    // 0x80038464: sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    get_player_character(rdram, ctx);
        goto after_4;
    // 0x80038464: sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    after_4:
    { extern int dkr_legacy_character_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*); static const uint32_t dkr_character_menu_fields[] = { 0x801263d4U, 0x801263dcU, 0x801263e8U, 0x801263f0U, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df480U, 0x800df4bcU, 0x800df47cU, 0x801263a0U, 0x801263ccU, 0x800e3690U, 0x800e36c8U, 0x80126808U, 0x801263c0U, 0x8011ae5cU, 0x8011aec8U }; dkr_legacy_character_menu(rdram, ctx, 7U, dkr_character_menu_fields); }
    // 0x80038468: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8003846C: lbu         $v1, 0x4F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X4F);
    // 0x80038470: bne         $v0, $a1, L_8003848C
    if (ctx->r2 != ctx->r5) {
        // 0x80038474: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8003848C;
    }
    // 0x80038474: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80038478: addu        $t4, $s1, $v1
    ctx->r12 = ADD32(ctx->r17, ctx->r3);
    // 0x8003847C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80038480: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x80038484: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80038488: sb          $s0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r16;
L_8003848C:
    // 0x8003848C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80038490: bne         $s0, $at, L_8003845C
    if (ctx->r16 != ctx->r1) {
        // 0x80038494: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003845C;
    }
    // 0x80038494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038498: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8003849C: addiu       $t7, $t7, -0x3584
    ctx->r15 = ADD32(ctx->r15, -0X3584);
    // 0x800384A0: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x800384A4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800384A8: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800384AC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800384B0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800384B4: andi        $a0, $t9, 0xFF
    ctx->r4 = ctx->r25 & 0XFF;
    // 0x800384B8: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x800384BC: bne         $at, $zero, L_800384E4
    if (ctx->r1 != 0) {
        // 0x800384C0: sb          $t9, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r25;
            goto L_800384E4;
    }
    // 0x800384C0: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800384C4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800384C8: addiu       $t2, $t2, -0x3578
    ctx->r10 = ADD32(ctx->r10, -0X3578);
    // 0x800384CC: addu        $t0, $a1, $t2
    ctx->r8 = ADD32(ctx->r5, ctx->r10);
    // 0x800384D0: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x800384D4: andi        $t1, $a0, 0xF
    ctx->r9 = ctx->r4 & 0XF;
    // 0x800384D8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800384DC: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800384E0: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
L_800384E4:
    // 0x800384E4: addiu       $t5, $t5, -0x3578
    ctx->r13 = ADD32(ctx->r13, -0X3578);
    // 0x800384E8: addu        $t0, $a1, $t5
    ctx->r8 = ADD32(ctx->r5, ctx->r13);
    // 0x800384EC: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x800384F0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800384F4: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800384F8: bne         $at, $zero, L_80038504
    if (ctx->r1 != 0) {
        // 0x800384FC: nop
    
            goto L_80038504;
    }
    // 0x800384FC: nop

    // 0x80038500: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_80038504:
    // 0x80038504: blez        $a3, L_800385F8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80038508: nop
    
            goto L_800385F8;
    }
    // 0x80038508: nop

    // 0x8003850C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80038510: jal         0x8009C274
    // 0x80038514: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    charselect_status(rdram, ctx);
        goto after_5;
    // 0x80038514: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_5:
    // 0x80038518: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8003851C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80038520: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80038524: blez        $a3, L_80038594
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80038528: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80038594;
    }
    // 0x80038528: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003852C: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x80038530: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80038534:
    // 0x80038534: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80038538: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003853C: addu        $t8, $t6, $a2
    ctx->r24 = ADD32(ctx->r14, ctx->r6);
    // 0x80038540: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x80038544: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038548: bne         $t9, $at, L_80038584
    if (ctx->r25 != ctx->r1) {
        // 0x8003854C: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80038584;
    }
    // 0x8003854C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80038550: sw          $s0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r16;
    // 0x80038554: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80038558: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8003855C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80038560: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x80038564: jal         0x800AFC3C
    // 0x80038568: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    obj_spawn_particle(rdram, ctx);
        goto after_6;
    // 0x80038568: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_6:
    // 0x8003856C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80038570: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80038574: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80038578: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8003857C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80038580: nop

L_80038584:
    // 0x80038584: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80038588: bne         $v1, $a3, L_80038534
    if (ctx->r3 != ctx->r7) {
        // 0x8003858C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80038534;
    }
    // 0x8003858C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80038590: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80038594:
    // 0x80038594: lh          $a2, 0x28($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X28);
    // 0x80038598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003859C: blez        $a2, L_800385F4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800385A0: nop
    
            goto L_800385F4;
    }
    // 0x800385A0: nop

L_800385A4:
    // 0x800385A4: lw          $t1, 0x38($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X38);
    // 0x800385A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800385AC: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    // 0x800385B0: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x800385B4: nop

    // 0x800385B8: bltz        $a1, L_800385E8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800385BC: slti        $at, $a1, 0x4
        ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
            goto L_800385E8;
    }
    // 0x800385BC: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x800385C0: beq         $at, $zero, L_800385EC
    if (ctx->r1 == 0) {
        // 0x800385C4: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800385EC;
    }
    // 0x800385C4: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800385C8: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800385CC: nop

    // 0x800385D0: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x800385D4: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800385D8: nop

    // 0x800385DC: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x800385E0: lh          $a2, 0x28($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X28);
    // 0x800385E4: nop

L_800385E8:
    // 0x800385E8: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_800385EC:
    // 0x800385EC: bne         $at, $zero, L_800385A4
    if (ctx->r1 != 0) {
        // 0x800385F0: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800385A4;
    }
    // 0x800385F0: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_800385F4:
    // 0x800385F4: sb          $zero, 0x3B($s2)
    MEM_B(0X3B, ctx->r18) = 0;
L_800385F8:
    // 0x800385F8: lb          $v0, 0x3B($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X3B);
    // 0x800385FC: nop

    // 0x80038600: bltz        $v0, L_800386F8
    if (SIGNED(ctx->r2) < 0) {
        // 0x80038604: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800386F8;
    }
    // 0x80038604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80038608: lh          $t5, 0x48($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X48);
    // 0x8003860C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80038610: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80038614: beq         $at, $zero, L_800386F4
    if (ctx->r1 == 0) {
        // 0x80038618: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_800386F4;
    }
    // 0x80038618: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8003861C: lw          $t7, 0x44($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X44);
    // 0x80038620: lbu         $t2, 0x2C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2C);
    // 0x80038624: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80038628: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x8003862C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038630: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80038634: bne         $t2, $at, L_800386F4
    if (ctx->r10 != ctx->r1) {
        // 0x80038638: sll         $t9, $a1, 4
        ctx->r25 = S32(ctx->r5 << 4);
            goto L_800386F4;
    }
    // 0x80038638: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8003863C: jal         0x800015F8
    // 0x80038640: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    music_animation_fraction(rdram, ctx);
        goto after_7;
    // 0x80038640: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    after_7:
    extern void dkr_character_select_animation_fraction(uint8_t*, recomp_context*); dkr_character_select_animation_fraction(rdram, ctx);
    // 0x80038644: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80038648: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003864C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80038650: cvt.d.s     $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.d = CVT_D_S(ctx->f0.fl);
    // 0x80038654: c.lt.d      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.d < ctx->f14.d;
    // 0x80038658: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8003865C: bc1f        L_800386B4
    if (!c1cs) {
        // 0x80038660: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800386B4;
    }
    // 0x80038660: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80038664: sub.d       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f14.d - ctx->f18.d;
    // 0x80038668: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x8003866C: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80038670: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80038674: add.d       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f2.d + ctx->f2.d;
    // 0x80038678: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003867C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80038680: mul.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80038684: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80038688: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8003868C: nop

    // 0x80038690: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80038694: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80038698: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003869C: nop

    // 0x800386A0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800386A4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800386A8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800386AC: b           L_800386F4
    // 0x800386B0: sh          $t4, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r12;
        goto L_800386F4;
    // 0x800386B0: sh          $t4, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r12;
L_800386B4:
    // 0x800386B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800386B8: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x800386BC: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800386C0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800386C4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800386C8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800386CC: nop

    // 0x800386D0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800386D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800386D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800386DC: nop

    // 0x800386E0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800386E4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800386E8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800386EC: sh          $t7, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r15;
    // 0x800386F0: nop

L_800386F4:
    // 0x800386F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800386F8:
    // 0x800386F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800386FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80038700: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80038704: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80038708: jr          $ra
    // 0x8003870C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8003870C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void music_voicelimit_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000BE0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80000BE4: lbu         $t6, -0x3990($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3990);
    // 0x80000BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000BF4: bne         $t6, $zero, L_80000C0C
    if (ctx->r14 != 0) {
        // 0x80000BF8: andi        $a1, $a0, 0xFF
        ctx->r5 = ctx->r4 & 0XFF;
            goto L_80000C0C;
    }
    // 0x80000BF8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80000BFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000C00: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80000C04: jal         0x8000B010
    // 0x80000C08: nop

    set_voice_limit(rdram, ctx);
        goto after_0;
    // 0x80000C08: nop

    after_0:
L_80000C0C:
    // 0x80000C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000C14: jr          $ra
    // 0x80000C18: nop

    return;
    // 0x80000C18: nop

;}
RECOMP_FUNC void audioStartThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002A58: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002A5C: jal         0x800C89A0
    // 0x80002A60: addiu       $a0, $a0, 0x5FB0
    ctx->r4 = ADD32(ctx->r4, 0X5FB0);
    osStartThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80002A60: addiu       $a0, $a0, 0x5FB0
    ctx->r4 = ADD32(ctx->r4, 0X5FB0);
    after_0:
    // 0x80002A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002A6C: jr          $ra
    // 0x80002A70: nop

    return;
    // 0x80002A70: nop

;}
RECOMP_FUNC void hud_lives_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A22F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A22F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A22FC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A2300: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2304: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A2308: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A230C: lb          $t7, 0x3($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3);
    // 0x800A2310: addiu       $s0, $s0, 0x6CDC
    ctx->r16 = ADD32(ctx->r16, 0X6CDC);
    // 0x800A2314: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A2318: addiu       $t8, $t7, 0x38
    ctx->r24 = ADD32(ctx->r15, 0X38);
    // 0x800A231C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A2320: sh          $t8, 0x646($t9)
    MEM_H(0X646, ctx->r25) = ctx->r24;
    // 0x800A2324: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x800A2328: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800A232C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A2330: bne         $at, $zero, L_800A2358
    if (ctx->r1 != 0) {
        // 0x800A2334: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A2358;
    }
    // 0x800A2334: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A2338: bne         $v1, $at, L_800A23AC
    if (ctx->r3 != ctx->r1) {
        // 0x800A233C: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_800A23AC;
    }
    // 0x800A233C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800A2340: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A2344: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A2348: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800A234C: nop

    // 0x800A2350: bne         $t1, $at, L_800A23AC
    if (ctx->r9 != ctx->r1) {
        // 0x800A2354: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_800A23AC;
    }
    // 0x800A2354: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_800A2358:
    // 0x800A2358: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800A235C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2360: sb          $t2, 0x6CD5($at)
    MEM_B(0X6CD5, ctx->r1) = ctx->r10;
    // 0x800A2364: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A2368: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A236C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2370: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2374: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A2378: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A237C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    { extern void dkr_legacy_character_hud_bind(uint8_t*, recomp_context*, uint32_t, uint32_t); dkr_legacy_character_hud_bind(rdram, ctx, (uint32_t)ctx->r7 + 1600U, (uint32_t)(MEM_W(ctx->r29, 0x20))); }
    // 0x800A2380: jal         0x800AA600
    // 0x800A2384: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A2384: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_0:
    { extern void dkr_legacy_character_hud_unbind(uint8_t*, recomp_context*); dkr_legacy_character_hud_unbind(rdram, ctx); }
    // 0x800A2388: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A238C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2390: sb          $zero, 0x6CD5($at)
    MEM_B(0X6CD5, ctx->r1) = 0;
    // 0x800A2394: jal         0x80078054
    // 0x800A2398: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    rdp_init(rdram, ctx);
        goto after_1;
    // 0x800A2398: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    after_1:
    // 0x800A239C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A23A0: jal         0x8007B3D0
    // 0x800A23A4: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    rendermode_reset(rdram, ctx);
        goto after_2;
    // 0x800A23A4: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    after_2:
    // 0x800A23A8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_800A23AC:
    // 0x800A23AC: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800A23B0: lb          $v0, 0x185($t3)
    ctx->r2 = MEM_B(ctx->r11, 0X185);
    // 0x800A23B4: nop

    // 0x800A23B8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800A23BC: beq         $at, $zero, L_800A2400
    if (ctx->r1 == 0) {
        // 0x800A23C0: nop
    
            goto L_800A2400;
    }
    // 0x800A23C0: nop

    // 0x800A23C4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A23C8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A23CC: sh          $v0, 0x6D8($t4)
    MEM_H(0X6D8, ctx->r12) = ctx->r2;
    // 0x800A23D0: lbu         $t5, 0x6D37($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X6D37);
    // 0x800A23D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A23D8: bne         $t5, $at, L_800A2498
    if (ctx->r13 != ctx->r1) {
        // 0x800A23DC: nop
    
            goto L_800A2498;
    }
    // 0x800A23DC: nop

    // 0x800A23E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A23E4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800A23E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A23EC: lwc1        $f4, 0x6CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A23F0: nop

    // 0x800A23F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A23F8: b           L_800A2498
    // 0x800A23FC: swc1        $f8, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f8.u32l;
        goto L_800A2498;
    // 0x800A23FC: swc1        $f8, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f8.u32l;
L_800A2400:
    // 0x800A2400: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800A2404: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A2408: bne         $v1, $zero, L_800A2414
    if (ctx->r3 != 0) {
        // 0x800A240C: nop
    
            goto L_800A2414;
    }
    // 0x800A240C: nop

    // 0x800A2410: break       7
    do_break(2148148240);
L_800A2414:
    // 0x800A2414: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A2418: bne         $v1, $at, L_800A242C
    if (ctx->r3 != ctx->r1) {
        // 0x800A241C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A242C;
    }
    // 0x800A241C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2420: bne         $v0, $at, L_800A242C
    if (ctx->r2 != ctx->r1) {
        // 0x800A2424: nop
    
            goto L_800A242C;
    }
    // 0x800A2424: nop

    // 0x800A2428: break       6
    do_break(2148148264);
L_800A242C:
    // 0x800A242C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2430: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2434: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2438: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A243C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A2440: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A2444: mflo        $t6
    ctx->r14 = lo;
    // 0x800A2448: sh          $t6, 0x6D8($t7)
    MEM_H(0X6D8, ctx->r15) = ctx->r14;
    // 0x800A244C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A2450: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800A2454: lb          $t9, 0x185($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X185);
    // 0x800A2458: nop

    // 0x800A245C: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x800A2460: bne         $v1, $zero, L_800A246C
    if (ctx->r3 != 0) {
        // 0x800A2464: nop
    
            goto L_800A246C;
    }
    // 0x800A2464: nop

    // 0x800A2468: break       7
    do_break(2148148328);
L_800A246C:
    // 0x800A246C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A2470: bne         $v1, $at, L_800A2484
    if (ctx->r3 != ctx->r1) {
        // 0x800A2474: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A2484;
    }
    // 0x800A2474: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2478: bne         $t9, $at, L_800A2484
    if (ctx->r25 != ctx->r1) {
        // 0x800A247C: nop
    
            goto L_800A2484;
    }
    // 0x800A247C: nop

    // 0x800A2480: break       6
    do_break(2148148352);
L_800A2484:
    // 0x800A2484: mfhi        $t0
    ctx->r8 = hi;
    // 0x800A2488: sh          $t0, 0x6F8($t1)
    MEM_H(0X6F8, ctx->r9) = ctx->r8;
    // 0x800A248C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A2490: jal         0x800AA600
    // 0x800A2494: addiu       $a3, $a3, 0x6E0
    ctx->r7 = ADD32(ctx->r7, 0X6E0);
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A2494: addiu       $a3, $a3, 0x6E0
    ctx->r7 = ADD32(ctx->r7, 0X6E0);
    after_3:
L_800A2498:
    // 0x800A2498: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A249C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A24A0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A24A4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A24A8: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A24AC: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A24B0: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A24B4: jal         0x800AA600
    // 0x800A24B8: addiu       $a3, $a3, 0x6C0
    ctx->r7 = ADD32(ctx->r7, 0X6C0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A24B8: addiu       $a3, $a3, 0x6C0
    ctx->r7 = ADD32(ctx->r7, 0X6C0);
    after_4:
    // 0x800A24BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A24C0: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x800A24C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800A24C8: bne         $a0, $v1, L_800A2510
    if (ctx->r4 != ctx->r3) {
        // 0x800A24CC: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A2510;
    }
    // 0x800A24CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A24D0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800A24D4: nop

    // 0x800A24D8: lb          $t3, 0x185($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X185);
    // 0x800A24DC: nop

    // 0x800A24E0: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x800A24E4: beq         $at, $zero, L_800A2510
    if (ctx->r1 == 0) {
        // 0x800A24E8: nop
    
            goto L_800A2510;
    }
    // 0x800A24E8: nop

    // 0x800A24EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A24F0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800A24F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A24F8: lwc1        $f10, 0x6CC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A24FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A2500: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A2504: swc1        $f18, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f18.u32l;
    // 0x800A2508: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x800A250C: nop

L_800A2510:
    // 0x800A2510: beq         $a0, $v1, L_800A257C
    if (ctx->r4 == ctx->r3) {
        // 0x800A2514: addiu       $a1, $a1, 0x6D00
        ctx->r5 = ADD32(ctx->r5, 0X6D00);
            goto L_800A257C;
    }
    // 0x800A2514: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A2518: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A251C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2520: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2524: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A2528: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A252C: jal         0x800AA600
    // 0x800A2530: addiu       $a3, $a3, 0x6A0
    ctx->r7 = ADD32(ctx->r7, 0X6A0);
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A2530: addiu       $a3, $a3, 0x6A0
    ctx->r7 = ADD32(ctx->r7, 0X6A0);
    after_5:
    // 0x800A2534: jal         0x8007BF1C
    // 0x800A2538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_6;
    // 0x800A2538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A253C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A2540: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2544: sb          $t4, 0x6CD5($at)
    MEM_B(0X6CD5, ctx->r1) = ctx->r12;
    // 0x800A2548: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A254C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2550: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2554: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2558: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A255C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A2560: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A2564: jal         0x800AA600
    // 0x800A2568: addiu       $a3, $a3, 0x680
    ctx->r7 = ADD32(ctx->r7, 0X680);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A2568: addiu       $a3, $a3, 0x680
    ctx->r7 = ADD32(ctx->r7, 0X680);
    after_7:
    // 0x800A256C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2570: sb          $zero, 0x6CD5($at)
    MEM_B(0X6CD5, ctx->r1) = 0;
    // 0x800A2574: jal         0x8007BF1C
    // 0x800A2578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_8;
    // 0x800A2578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
L_800A257C:
    // 0x800A257C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2580: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2584: jr          $ra
    // 0x800A2588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A2588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
