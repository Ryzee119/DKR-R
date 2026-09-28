#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void camDisableUserView(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066894: beq         $a1, $zero, L_800668D0
    if (ctx->r5 == 0) {
        // 0x80066898: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_800668D0;
    }
    // 0x80066898: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8006689C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800668A0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800668A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800668A8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800668AC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800668B0: addiu       $t7, $t7, -0x2F9C
    ctx->r15 = ADD32(ctx->r15, -0X2F9C);
    // 0x800668B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800668B8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800668BC: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x800668C0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800668C4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800668C8: b           L_800668FC
    // 0x800668CC: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_800668FC;
    // 0x800668CC: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_800668D0:
    // 0x800668D0: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800668D4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800668D8: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x800668DC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800668E0: addiu       $t1, $t1, -0x2F9C
    ctx->r9 = ADD32(ctx->r9, -0X2F9C);
    // 0x800668E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800668E8: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x800668EC: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x800668F0: nop

    // 0x800668F4: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x800668F8: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_800668FC:
    // 0x800668FC: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80066900: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80066904: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80066908: jr          $ra
    // 0x8006690C: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    return;
    // 0x8006690C: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_80023568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023568: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002356C: lb          $t6, -0x52C4($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X52C4);
    // 0x80023570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023574: beq         $t6, $zero, L_8002358C
    if (ctx->r14 == 0) {
        // 0x80023578: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8002358C;
    }
    // 0x80023578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002357C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023580: lb          $v0, -0x52DB($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52DB);
    // 0x80023584: b           L_800235B0
    // 0x80023588: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800235B0;
    // 0x80023588: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002358C:
    // 0x8002358C: jal         0x8006BD98
    // 0x80023590: nop

    level_type(rdram, ctx);
        goto after_0;
    // 0x80023590: nop

    after_0:
    // 0x80023594: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80023598: bne         $v0, $at, L_800235AC
    if (ctx->r2 != ctx->r1) {
        // 0x8002359C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800235AC;
    }
    // 0x8002359C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800235A0: lb          $v0, -0x52DB($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52DB);
    // 0x800235A4: b           L_800235B0
    // 0x800235A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800235B0;
    // 0x800235A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800235AC:
    // 0x800235AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800235B0:
    // 0x800235B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800235B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800235B8: jr          $ra
    // 0x800235BC: nop

    return;
    // 0x800235BC: nop

;}
RECOMP_FUNC void obj_loop_vehicleanim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800380F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800380FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80038104: jal         0x8001F460
    // 0x80038108: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80038108: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x8003810C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038110: nop

    // 0x80038114: lw          $v1, 0x60($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X60);
    // 0x80038118: nop

    // 0x8003811C: beq         $v1, $zero, L_80038180
    if (ctx->r3 == 0) {
        // 0x80038120: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038180;
    }
    // 0x80038120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038124: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80038128: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003812C: blez        $v0, L_8003817C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80038130: addiu       $t6, $zero, 0x4000
        ctx->r14 = ADD32(0, 0X4000);
            goto L_8003817C;
    }
    // 0x80038130: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80038134: bne         $v0, $at, L_80038148
    if (ctx->r2 != ctx->r1) {
        // 0x80038138: nop
    
            goto L_80038148;
    }
    // 0x80038138: nop

    // 0x8003813C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80038140: b           L_80038154
    // 0x80038144: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
        goto L_80038154;
    // 0x80038144: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
L_80038148:
    // 0x80038148: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8003814C: nop

    // 0x80038150: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
L_80038154:
    // 0x80038154: lw          $t9, 0x40($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X40);
    // 0x80038158: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8003815C: sb          $t8, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r24;
    // 0x80038160: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80038164: lb          $t1, 0x3A($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X3A);
    // 0x80038168: lb          $t0, 0x55($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X55);
    // 0x8003816C: nop

    // 0x80038170: bne         $t0, $t1, L_80038180
    if (ctx->r8 != ctx->r9) {
        // 0x80038174: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038180;
    }
    // 0x80038174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038178: sb          $zero, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = 0;
L_8003817C:
    // 0x8003817C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038180:
    // 0x80038180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038184: jr          $ra
    // 0x80038188: nop

    return;
    // 0x80038188: nop

;}
RECOMP_FUNC void func_8005B818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B818: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x8005B81C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8005B820: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x8005B824: mtc1        $a3, $f30
    ctx->f30.u32l = ctx->r7;
    // 0x8005B828: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8005B82C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8005B830: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8005B834: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8005B838: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8005B83C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8005B840: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8005B844: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8005B848: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x8005B84C: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8005B850: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8005B854: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8005B858: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8005B85C: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8005B860: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8005B864: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005B868: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8005B86C: sw          $a2, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r6;
    // 0x8005B870: jal         0x8001E29C
    // 0x8005B874: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8005B874: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x8005B878: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005B87C: jal         0x8006BDB0
    // 0x8005B880: sw          $v0, -0x2A9C($at)
    MEM_W(-0X2A9C, ctx->r1) = ctx->r2;
    level_header(rdram, ctx);
        goto after_1;
    // 0x8005B880: sw          $v0, -0x2A9C($at)
    MEM_W(-0X2A9C, ctx->r1) = ctx->r2;
    after_1:
    // 0x8005B884: jal         0x8001BA64
    // 0x8005B888: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    get_checkpoint_count(rdram, ctx);
        goto after_2;
    // 0x8005B888: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005B88C: beq         $v0, $zero, L_8005C210
    if (ctx->r2 == 0) {
        // 0x8005B890: sw          $v0, 0x11C($sp)
        MEM_W(0X11C, ctx->r29) = ctx->r2;
            goto L_8005C210;
    }
    // 0x8005B890: sw          $v0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r2;
    // 0x8005B894: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B898: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8005B89C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005B8A0: sb          $zero, 0x1C9($s1)
    MEM_B(0X1C9, ctx->r17) = 0;
    // 0x8005B8A4: sb          $zero, 0x1F5($s1)
    MEM_B(0X1F5, ctx->r17) = 0;
    // 0x8005B8A8: sb          $zero, 0x187($s1)
    MEM_B(0X187, ctx->r17) = 0;
    // 0x8005B8AC: swc1        $f4, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f4.u32l;
    // 0x8005B8B0: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8005B8B4: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    // 0x8005B8B8: lwc1        $f0, 0x124($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X124);
    // 0x8005B8BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005B8C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B8C4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8005B8C8: nop

    // 0x8005B8CC: bc1f        L_8005B8E4
    if (!c1cs) {
        // 0x8005B8D0: nop
    
            goto L_8005B8E4;
    }
    // 0x8005B8D0: nop

    // 0x8005B8D4: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8005B8D8: swc1        $f8, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->f8.u32l;
    // 0x8005B8DC: lwc1        $f0, 0x124($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X124);
    // 0x8005B8E0: nop

L_8005B8E4:
    // 0x8005B8E4: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005B8E8: nop

    // 0x8005B8EC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8005B8F0: nop

    // 0x8005B8F4: bc1f        L_8005B908
    if (!c1cs) {
        // 0x8005B8F8: nop
    
            goto L_8005B908;
    }
    // 0x8005B8F8: nop

    // 0x8005B8FC: swc1        $f10, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->f10.u32l;
    // 0x8005B900: lwc1        $f0, 0x124($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X124);
    // 0x8005B904: nop

L_8005B908:
    // 0x8005B908: lwc1        $f5, 0x69C0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X69C0);
    // 0x8005B90C: lwc1        $f4, 0x69C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69C4);
    // 0x8005B910: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8005B914: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8005B918: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B91C: lwc1        $f9, 0x69C8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69C8);
    // 0x8005B920: lwc1        $f8, 0x69CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69CC);
    // 0x8005B924: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B928: lwc1        $f19, 0x69D0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X69D0);
    // 0x8005B92C: lwc1        $f18, 0x69D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X69D4);
    // 0x8005B930: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005B934: nop

    // 0x8005B938: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8005B93C: jal         0x800C9AD0
    // 0x8005B940: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8005B940: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_3:
    // 0x8005B944: lb          $t6, 0x1D3($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D3);
    // 0x8005B948: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8005B94C: beq         $t6, $zero, L_8005B96C
    if (ctx->r14 == 0) {
        // 0x8005B950: addiu       $v1, $sp, 0x100
        ctx->r3 = ADD32(ctx->r29, 0X100);
            goto L_8005B96C;
    }
    // 0x8005B950: addiu       $v1, $sp, 0x100
    ctx->r3 = ADD32(ctx->r29, 0X100);
    // 0x8005B954: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B958: lwc1        $f9, 0x69D8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69D8);
    // 0x8005B95C: lwc1        $f8, 0x69DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69DC);
    // 0x8005B960: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005B964: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005B968: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_8005B96C:
    // 0x8005B96C: lb          $t7, 0x1D6($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1D6);
    // 0x8005B970: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B974: bne         $t7, $at, L_8005BA74
    if (ctx->r15 != ctx->r1) {
        // 0x8005B978: addiu       $a2, $sp, 0xEC
        ctx->r6 = ADD32(ctx->r29, 0XEC);
            goto L_8005BA74;
    }
    // 0x8005B978: addiu       $a2, $sp, 0xEC
    ctx->r6 = ADD32(ctx->r29, 0XEC);
    // 0x8005B97C: lh          $t8, 0x1BE($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X1BE);
    // 0x8005B980: lh          $t2, 0x1C2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1C2);
    // 0x8005B984: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8005B988: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8005B98C: subu        $v0, $t9, $t3
    ctx->r2 = SUB32(ctx->r25, ctx->r11);
    // 0x8005B990: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005B994: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005B998: bne         $at, $zero, L_8005B9A8
    if (ctx->r1 != 0) {
        // 0x8005B99C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8005B9A8;
    }
    // 0x8005B99C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005B9A0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005B9A4: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8005B9A8:
    // 0x8005B9A8: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8005B9AC: beq         $at, $zero, L_8005B9B8
    if (ctx->r1 == 0) {
        // 0x8005B9B0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005B9B8;
    }
    // 0x8005B9B0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005B9B4: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8005B9B8:
    // 0x8005B9B8: bgez        $v0, L_8005B9C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005B9BC: nop
    
            goto L_8005B9C4;
    }
    // 0x8005B9BC: nop

    // 0x8005B9C0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8005B9C4:
    // 0x8005B9C4: addiu       $v0, $v0, -0xC8
    ctx->r2 = ADD32(ctx->r2, -0XC8);
    // 0x8005B9C8: bgez        $v0, L_8005B9D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005B9CC: nop
    
            goto L_8005B9D4;
    }
    // 0x8005B9CC: nop

    // 0x8005B9D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B9D4:
    // 0x8005B9D4: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8005B9D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B9DC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005B9E0: lwc1        $f9, 0x69E0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69E0);
    // 0x8005B9E4: lwc1        $f8, 0x69E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69E4);
    // 0x8005B9E8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005B9EC: nop

    // 0x8005B9F0: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8005B9F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005B9F8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005B9FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005BA00: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005BA04: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8005BA08: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8005BA0C: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    // 0x8005BA10: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x8005BA14: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8005BA18: nop

    // 0x8005BA1C: bc1f        L_8005BA2C
    if (!c1cs) {
        // 0x8005BA20: nop
    
            goto L_8005BA2C;
    }
    // 0x8005BA20: nop

    // 0x8005BA24: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005BA28: nop

L_8005BA2C:
    // 0x8005BA2C: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005BA30: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x8005BA34: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005BA38: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8005BA3C: bc1f        L_8005BA4C
    if (!c1cs) {
        // 0x8005BA40: nop
    
            goto L_8005BA4C;
    }
    // 0x8005BA40: nop

    // 0x8005BA44: b           L_8005BAA4
    // 0x8005BA48: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
        goto L_8005BAA4;
    // 0x8005BA48: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
L_8005BA4C:
    // 0x8005BA4C: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005BA50: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005BA54: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005BA58: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005BA5C: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8005BA60: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8005BA64: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x8005BA68: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005BA6C: b           L_8005BAA4
    // 0x8005BA70: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
        goto L_8005BAA4;
    // 0x8005BA70: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
L_8005BA74:
    // 0x8005BA74: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005BA78: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x8005BA7C: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8005BA80: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8005BA84: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005BA88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005BA8C: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8005BA90: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8005BA94: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8005BA98: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x8005BA9C: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8005BAA0: swc1        $f18, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f18.u32l;
L_8005BAA4:
    // 0x8005BAA4: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x8005BAA8: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    // 0x8005BAAC: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8005BAB0: bgez        $a0, L_8005BAC4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005BAB4: addiu       $t1, $sp, 0xB8
        ctx->r9 = ADD32(ctx->r29, 0XB8);
            goto L_8005BAC4;
    }
    // 0x8005BAB4: addiu       $t1, $sp, 0xB8
    ctx->r9 = ADD32(ctx->r29, 0XB8);
    // 0x8005BAB8: lw          $v0, 0x11C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X11C);
    // 0x8005BABC: nop

    // 0x8005BAC0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_8005BAC4:
    // 0x8005BAC4: lw          $v0, 0x11C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X11C);
    // 0x8005BAC8: addiu       $t0, $sp, 0xA4
    ctx->r8 = ADD32(ctx->r29, 0XA4);
    // 0x8005BACC: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005BAD0: bne         $at, $zero, L_8005BADC
    if (ctx->r1 != 0) {
        // 0x8005BAD4: addiu       $s0, $sp, 0xB8
        ctx->r16 = ADD32(ctx->r29, 0XB8);
            goto L_8005BADC;
    }
    // 0x8005BAD4: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // 0x8005BAD8: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
L_8005BADC:
    // 0x8005BADC: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x8005BAE0: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x8005BAE4: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x8005BAE8: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8005BAEC: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8005BAF0: sw          $a0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r4;
    // 0x8005BAF4: jal         0x8001BA1C
    // 0x8005BAF8: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    find_next_checkpoint_node(rdram, ctx);
        goto after_4;
    // 0x8005BAF8: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    after_4:
    // 0x8005BAFC: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x8005BB00: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005BB04: lw          $a0, 0x120($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X120);
    // 0x8005BB08: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x8005BB0C: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x8005BB10: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8005BB14: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005BB18: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8005BB1C: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005BB20: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005BB24: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x8005BB28: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8005BB2C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005BB30: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8005BB34: lb          $t4, 0x1CA($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BB38: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005BB3C: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8005BB40: lb          $t6, 0x2E($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X2E);
    // 0x8005BB44: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8005BB48: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8005BB4C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005BB50: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005BB54: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x8005BB58: lb          $t7, 0x1CA($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BB5C: nop

    // 0x8005BB60: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8005BB64: lb          $t2, 0x32($t8)
    ctx->r10 = MEM_B(ctx->r24, 0X32);
    // 0x8005BB68: nop

    // 0x8005BB6C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8005BB70: nop

    // 0x8005BB74: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005BB78: swc1        $f10, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f10.u32l;
    // 0x8005BB7C: lb          $t9, 0x1CA($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BB80: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005BB84: addu        $t3, $v0, $t9
    ctx->r11 = ADD32(ctx->r2, ctx->r25);
    // 0x8005BB88: lb          $t4, 0x2E($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X2E);
    // 0x8005BB8C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005BB90: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8005BB94: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8005BB98: lwc1        $f4, -0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X4);
    // 0x8005BB9C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005BBA0: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8005BBA4: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8005BBA8: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x8005BBAC: lb          $t5, 0x1CA($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BBB0: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005BBB4: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005BBB8: lb          $t7, 0x32($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X32);
    // 0x8005BBBC: lwc1        $f6, -0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8005BBC0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8005BBC4: nop

    // 0x8005BBC8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005BBCC: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005BBD0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005BBD4: swc1        $f10, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f10.u32l;
    // 0x8005BBD8: lb          $t8, 0x1CA($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BBDC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005BBE0: addu        $t2, $v0, $t8
    ctx->r10 = ADD32(ctx->r2, ctx->r24);
    // 0x8005BBE4: lb          $t9, 0x2E($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X2E);
    // 0x8005BBE8: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005BBEC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8005BBF0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005BBF4: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8005BBF8: lwc1        $f6, -0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, -0X4);
    // 0x8005BBFC: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005BC00: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8005BC04: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8005BC08: swc1        $f10, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f10.u32l;
    // 0x8005BC0C: lw          $t3, 0x11C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X11C);
    // 0x8005BC10: nop

    // 0x8005BC14: bne         $a0, $t3, L_8005BC20
    if (ctx->r4 != ctx->r11) {
        // 0x8005BC18: nop
    
            goto L_8005BC20;
    }
    // 0x8005BC18: nop

    // 0x8005BC1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8005BC20:
    // 0x8005BC20: bne         $t0, $s0, L_8005BADC
    if (ctx->r8 != ctx->r16) {
        // 0x8005BC24: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_8005BADC;
    }
    // 0x8005BC24: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8005BC28: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005BC2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005BC30: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x8005BC34: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005BC38: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8005BC3C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005BC40: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005BC44: bc1f        L_8005BC54
    if (!c1cs) {
        // 0x8005BC48: nop
    
            goto L_8005BC54;
    }
    // 0x8005BC48: nop

    // 0x8005BC4C: neg.s       $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = -ctx->f4.fl;
    // 0x8005BC50: swc1        $f18, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f18.u32l;
L_8005BC54:
    // 0x8005BC54: lwc1        $f8, 0xAC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BC58: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005BC5C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8005BC60: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x8005BC64: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8005BC68: bc1f        L_8005BC7C
    if (!c1cs) {
        // 0x8005BC6C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005BC7C;
    }
    // 0x8005BC6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BC70: lwc1        $f4, 0x69E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69E8);
    // 0x8005BC74: nop

    // 0x8005BC78: swc1        $f4, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f4.u32l;
L_8005BC7C:
    // 0x8005BC7C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005BC80: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8005BC84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8005BC88:
    // 0x8005BC88: lwc1        $f6, 0xAC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BC8C: lwc1        $f18, 0xA8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x8005BC90: mul.s       $f4, $f6, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f30.fl);
    // 0x8005BC94: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8005BC98: addiu       $a0, $sp, 0x100
    ctx->r4 = ADD32(ctx->r29, 0X100);
    // 0x8005BC9C: addiu       $a3, $sp, 0x9C
    ctx->r7 = ADD32(ctx->r29, 0X9C);
    // 0x8005BCA0: sub.d       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f20.d - ctx->f8.d;
    // 0x8005BCA4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8005BCA8: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x8005BCAC: cvt.s.d     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f22.fl = CVT_S_D(ctx->f8.d);
    // 0x8005BCB0: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x8005BCB4: c.le.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d <= ctx->f2.d;
    // 0x8005BCB8: nop

    // 0x8005BCBC: bc1f        L_8005BCD0
    if (!c1cs) {
        // 0x8005BCC0: nop
    
            goto L_8005BCD0;
    }
    // 0x8005BCC0: nop

    // 0x8005BCC4: sub.d       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = ctx->f2.d - ctx->f20.d;
    // 0x8005BCC8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8005BCCC: cvt.s.d     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f22.fl = CVT_S_D(ctx->f6.d);
L_8005BCD0:
    // 0x8005BCD0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8005BCD4: jal         0x8002263C
    // 0x8005BCD8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    cubic_spline_interpolation(rdram, ctx);
        goto after_5;
    // 0x8005BCD8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8005BCDC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8005BCE0: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x8005BCE4: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
    // 0x8005BCE8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005BCEC: jal         0x8002263C
    // 0x8005BCF0: addiu       $a3, $sp, 0x98
    ctx->r7 = ADD32(ctx->r29, 0X98);
    cubic_spline_interpolation(rdram, ctx);
        goto after_6;
    // 0x8005BCF0: addiu       $a3, $sp, 0x98
    ctx->r7 = ADD32(ctx->r29, 0X98);
    after_6:
    // 0x8005BCF4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8005BCF8: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8005BCFC: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x8005BD00: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005BD04: jal         0x8002263C
    // 0x8005BD08: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    cubic_spline_interpolation(rdram, ctx);
        goto after_7;
    // 0x8005BD08: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    after_7:
    // 0x8005BD0C: lwc1        $f4, 0x68($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8005BD10: lwc1        $f10, 0x6C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8005BD14: lwc1        $f18, 0x70($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8005BD18: sub.s       $f26, $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x8005BD1C: sub.s       $f24, $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x8005BD20: bne         $s0, $zero, L_8005BDA4
    if (ctx->r16 != 0) {
        // 0x8005BD24: sub.s       $f28, $f0, $f18
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f0.fl - ctx->f18.fl;
            goto L_8005BDA4;
    }
    // 0x8005BD24: sub.s       $f28, $f0, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8005BD28: mul.s       $f8, $f26, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8005BD2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8005BD30: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8005BD34: nop

    // 0x8005BD38: mul.s       $f10, $f28, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8005BD3C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8005BD40: jal         0x800C9AD0
    // 0x8005BD44: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005BD44: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_8:
    // 0x8005BD48: nop

    // 0x8005BD4C: div.s       $f12, $f0, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8005BD50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005BD54: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005BD58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BD5C: c.eq.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl == ctx->f12.fl;
    // 0x8005BD60: nop

    // 0x8005BD64: bc1t        L_8005BD84
    if (c1cs) {
        // 0x8005BD68: nop
    
            goto L_8005BD84;
    }
    // 0x8005BD68: nop

    // 0x8005BD6C: div.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8005BD70: lwc1        $f8, 0xAC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BD74: nop

    // 0x8005BD78: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8005BD7C: b           L_8005BDA4
    // 0x8005BD80: swc1        $f10, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f10.u32l;
        goto L_8005BDA4;
    // 0x8005BD80: swc1        $f10, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f10.u32l;
L_8005BD84:
    // 0x8005BD84: lwc1        $f18, 0xAC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BD88: lwc1        $f9, 0x69F0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69F0);
    // 0x8005BD8C: lwc1        $f8, 0x69F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69F4);
    // 0x8005BD90: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8005BD94: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x8005BD98: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8005BD9C: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8005BDA0: swc1        $f10, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f10.u32l;
L_8005BDA4:
    // 0x8005BDA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005BDA8: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8005BDAC: bne         $at, $zero, L_8005BC88
    if (ctx->r1 != 0) {
        // 0x8005BDB0: nop
    
            goto L_8005BC88;
    }
    // 0x8005BDB0: nop

    // 0x8005BDB4: lwc1        $f18, 0x68($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8005BDB8: lwc1        $f8, 0x6C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8005BDBC: lwc1        $f10, 0x70($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8005BDC0: add.s       $f6, $f18, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f26.fl;
    // 0x8005BDC4: add.s       $f4, $f8, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8005BDC8: swc1        $f6, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f6.u32l;
    // 0x8005BDCC: add.s       $f18, $f10, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8005BDD0: swc1        $f4, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f4.u32l;
    // 0x8005BDD4: swc1        $f18, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f18.u32l;
    // 0x8005BDD8: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005BDDC: lwc1        $f6, 0x68($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8005BDE0: lwc1        $f18, 0x70($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8005BDE4: sub.s       $f26, $f6, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8005BDE8: lwc1        $f6, 0x14($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005BDEC: mul.s       $f8, $f26, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8005BDF0: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005BDF4: lwc1        $f4, 0x6C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8005BDF8: sub.s       $f28, $f18, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8005BDFC: sub.s       $f24, $f4, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8005BE00: mul.s       $f4, $f28, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8005BE04: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x8005BE08: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x8005BE0C: swc1        $f3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f_odd[(3 - 1) * 2];
    // 0x8005BE10: jal         0x800C9AD0
    // 0x8005BE14: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x8005BE14: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_9:
    // 0x8005BE18: nop

    // 0x8005BE1C: div.s       $f12, $f0, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8005BE20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BE24: lwc1        $f17, 0x69F8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X69F8);
    // 0x8005BE28: lwc1        $f16, 0x69FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X69FC);
    // 0x8005BE2C: lwc1        $f3, 0x60($sp)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r29, 0X60);
    // 0x8005BE30: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005BE34: nop

    // 0x8005BE38: sub.d       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f20.d - ctx->f2.d;
    // 0x8005BE3C: cvt.d.s     $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.d = CVT_D_S(ctx->f12.fl);
    // 0x8005BE40: c.lt.d      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.d < ctx->f14.d;
    // 0x8005BE44: swc1        $f12, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f12.u32l;
    // 0x8005BE48: bc1f        L_8005BE6C
    if (!c1cs) {
        // 0x8005BE4C: cvt.s.d     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
            goto L_8005BE6C;
    }
    // 0x8005BE4C: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8005BE50: nop

    // 0x8005BE54: div.d       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f14.d);
    // 0x8005BE58: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x8005BE5C: mul.s       $f26, $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8005BE60: nop

    // 0x8005BE64: mul.s       $f28, $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8005BE68: nop

L_8005BE6C:
    // 0x8005BE6C: beq         $s2, $zero, L_8005BF00
    if (ctx->r18 == 0) {
        // 0x8005BE70: swc1        $f6, 0xA8($s1)
        MEM_W(0XA8, ctx->r17) = ctx->f6.u32l;
            goto L_8005BF00;
    }
    // 0x8005BE70: swc1        $f6, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f6.u32l;
    // 0x8005BE74: lb          $t4, 0x192($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X192);
    // 0x8005BE78: nop

    // 0x8005BE7C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8005BE80: sb          $t5, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r13;
    // 0x8005BE84: lw          $t7, 0x11C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X11C);
    // 0x8005BE88: lb          $t6, 0x192($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X192);
    // 0x8005BE8C: nop

    // 0x8005BE90: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005BE94: bne         $at, $zero, L_8005BEC8
    if (ctx->r1 != 0) {
        // 0x8005BE98: lw          $t9, 0x80($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X80);
            goto L_8005BEC8;
    }
    // 0x8005BE98: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8005BE9C: lh          $t8, 0x190($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X190);
    // 0x8005BEA0: sb          $zero, 0x192($s1)
    MEM_B(0X192, ctx->r17) = 0;
    // 0x8005BEA4: blez        $t8, L_8005BEC8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005BEA8: lw          $t9, 0x80($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X80);
            goto L_8005BEC8;
    }
    // 0x8005BEA8: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8005BEAC: lb          $v0, 0x193($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X193);
    // 0x8005BEB0: nop

    // 0x8005BEB4: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x8005BEB8: beq         $at, $zero, L_8005BEC4
    if (ctx->r1 == 0) {
        // 0x8005BEBC: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8005BEC4;
    }
    // 0x8005BEBC: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8005BEC0: sb          $t2, 0x193($s1)
    MEM_B(0X193, ctx->r17) = ctx->r10;
L_8005BEC4:
    // 0x8005BEC4: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
L_8005BEC8:
    // 0x8005BEC8: lw          $t5, 0x11C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X11C);
    // 0x8005BECC: lb          $t3, 0x4B($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X4B);
    // 0x8005BED0: lh          $v0, 0x190($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X190);
    // 0x8005BED4: addiu       $t4, $t3, 0x3
    ctx->r12 = ADD32(ctx->r11, 0X3);
    // 0x8005BED8: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BEDC: addiu       $t8, $zero, 0x2710
    ctx->r24 = ADD32(0, 0X2710);
    // 0x8005BEE0: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8005BEE4: mflo        $t6
    ctx->r14 = lo;
    // 0x8005BEE8: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8005BEEC: beq         $at, $zero, L_8005BEF8
    if (ctx->r1 == 0) {
        // 0x8005BEF0: nop
    
            goto L_8005BEF8;
    }
    // 0x8005BEF0: nop

    // 0x8005BEF4: sh          $t7, 0x190($s1)
    MEM_H(0X190, ctx->r17) = ctx->r15;
L_8005BEF8:
    // 0x8005BEF8: b           L_8005BF40
    // 0x8005BEFC: sh          $t8, 0x1A8($s1)
    MEM_H(0X1A8, ctx->r17) = ctx->r24;
        goto L_8005BF40;
    // 0x8005BEFC: sh          $t8, 0x1A8($s1)
    MEM_H(0X1A8, ctx->r17) = ctx->r24;
L_8005BF00:
    // 0x8005BF00: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005BF04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005BF08: lwc1        $f8, 0xA8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x8005BF0C: nop

    // 0x8005BF10: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8005BF14: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005BF18: nop

    // 0x8005BF1C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005BF20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005BF24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005BF28: nop

    // 0x8005BF2C: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8005BF30: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8005BF34: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005BF38: sh          $t9, 0x1A8($s1)
    MEM_H(0X1A8, ctx->r17) = ctx->r25;
    // 0x8005BF3C: nop

L_8005BF40:
    // 0x8005BF40: lb          $v0, 0x1D3($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X1D3);
    // 0x8005BF44: lw          $t3, 0x130($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X130);
    // 0x8005BF48: blez        $v0, L_8005BF58
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005BF4C: subu        $t4, $v0, $t3
        ctx->r12 = SUB32(ctx->r2, ctx->r11);
            goto L_8005BF58;
    }
    // 0x8005BF4C: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x8005BF50: b           L_8005BF5C
    // 0x8005BF54: sb          $t4, 0x1D3($s1)
    MEM_B(0X1D3, ctx->r17) = ctx->r12;
        goto L_8005BF5C;
    // 0x8005BF54: sb          $t4, 0x1D3($s1)
    MEM_B(0X1D3, ctx->r17) = ctx->r12;
L_8005BF58:
    // 0x8005BF58: sb          $zero, 0x1D3($s1)
    MEM_B(0X1D3, ctx->r17) = 0;
L_8005BF5C:
    // 0x8005BF5C: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8005BF60: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8005BF64: nop

    // 0x8005BF68: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8005BF6C: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8005BF70: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8005BF74: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8005BF78: nop

    // 0x8005BF7C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8005BF80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005BF84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005BF88: nop

    // 0x8005BF8C: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8005BF90: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8005BF94: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8005BF98: sh          $t6, 0x1BA($s1)
    MEM_H(0X1BA, ctx->r17) = ctx->r14;
    // 0x8005BF9C: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8005BFA0: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8005BFA4: nop

    // 0x8005BFA8: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8005BFAC: mul.s       $f18, $f8, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8005BFB0: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8005BFB4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005BFB8: nop

    // 0x8005BFBC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005BFC0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005BFC4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005BFC8: nop

    // 0x8005BFCC: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005BFD0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8005BFD4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005BFD8: sh          $t8, 0x1BC($s1)
    MEM_H(0X1BC, ctx->r17) = ctx->r24;
    // 0x8005BFDC: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8005BFE0: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005BFE4: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8005BFE8: nop

    // 0x8005BFEC: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8005BFF0: jal         0x800C9AD0
    // 0x8005BFF4: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x8005BFF4: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_10:
    // 0x8005BFF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005BFFC: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8005C000: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8005C004: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005C008: bc1t        L_8005C060
    if (c1cs) {
        // 0x8005C00C: nop
    
            goto L_8005C060;
    }
    // 0x8005C00C: nop

    // 0x8005C010: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8005C014: div.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8005C018: nop

    // 0x8005C01C: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8005C020: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x8005C024: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8005C028: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    // 0x8005C02C: jal         0x80070750
    // 0x8005C030: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x8005C030: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x8005C034: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8005C038: addu        $t2, $v0, $at
    ctx->r10 = ADD32(ctx->r2, ctx->r1);
    // 0x8005C03C: sh          $t2, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r10;
    // 0x8005C040: lh          $t9, 0x1A0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1A0);
    // 0x8005C044: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005C048: sh          $t9, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r25;
    // 0x8005C04C: lwc1        $f12, 0x98($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8005C050: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8005C054: jal         0x80070750
    // 0x8005C058: nop

    arctan2_f(rdram, ctx);
        goto after_12;
    // 0x8005C058: nop

    after_12:
    // 0x8005C05C: sh          $v0, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r2;
L_8005C060:
    // 0x8005C060: lh          $t3, 0x1BE($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X1BE);
    // 0x8005C064: lh          $t4, 0x1C0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X1C0);
    // 0x8005C068: lh          $t5, 0x1A0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1A0);
    // 0x8005C06C: sh          $t3, 0x1C2($s1)
    MEM_H(0X1C2, ctx->r17) = ctx->r11;
    // 0x8005C070: sh          $t4, 0x1C4($s1)
    MEM_H(0X1C4, ctx->r17) = ctx->r12;
    // 0x8005C074: sh          $t5, 0x1BE($s1)
    MEM_H(0X1BE, ctx->r17) = ctx->r13;
    // 0x8005C078: lh          $t6, 0x2($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2);
    // 0x8005C07C: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8005C080: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8005C084: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8005C088: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C08C: jal         0x80011570
    // 0x8005C090: sh          $t6, 0x1C0($s1)
    MEM_H(0X1C0, ctx->r17) = ctx->r14;
    move_object(rdram, ctx);
        goto after_13;
    // 0x8005C090: sh          $t6, 0x1C0($s1)
    MEM_H(0X1C0, ctx->r17) = ctx->r14;
    after_13:
    // 0x8005C094: beq         $v0, $zero, L_8005C0C0
    if (ctx->r2 == 0) {
        // 0x8005C098: lui         $at, 0x4034
        ctx->r1 = S32(0X4034 << 16);
            goto L_8005C0C0;
    }
    // 0x8005C098: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8005C09C: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C0A0: lwc1        $f4, 0x10($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C0A4: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C0A8: add.s       $f6, $f18, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f26.fl;
    // 0x8005C0AC: add.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8005C0B0: swc1        $f6, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f6.u32l;
    // 0x8005C0B4: add.s       $f18, $f10, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8005C0B8: swc1        $f8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f8.u32l;
    // 0x8005C0BC: swc1        $f18, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f18.u32l;
L_8005C0C0:
    // 0x8005C0C0: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8005C0C4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005C0C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005C0CC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8005C0D0: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8005C0D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C0D8: bc1f        L_8005C100
    if (!c1cs) {
        // 0x8005C0DC: nop
    
            goto L_8005C100;
    }
    // 0x8005C0DC: nop

    // 0x8005C0E0: div.s       $f10, $f26, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = DIV_S(ctx->f26.fl, ctx->f30.fl);
    // 0x8005C0E4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8005C0E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005C0EC: nop

    // 0x8005C0F0: swc1        $f18, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f18.u32l;
    // 0x8005C0F4: div.s       $f6, $f28, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = DIV_S(ctx->f28.fl, ctx->f30.fl);
    // 0x8005C0F8: swc1        $f10, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f10.u32l;
    // 0x8005C0FC: swc1        $f6, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f6.u32l;
L_8005C100:
    // 0x8005C100: lw          $a2, 0x130($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X130);
    // 0x8005C104: jal         0x80042D20
    // 0x8005C108: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042D20(rdram, ctx);
        goto after_14;
    // 0x8005C108: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_14:
    // 0x8005C10C: lw          $a2, 0x130($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X130);
    // 0x8005C110: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C114: jal         0x80055EC0
    // 0x8005C118: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    handle_racer_items(rdram, ctx);
        goto after_15;
    // 0x8005C118: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x8005C11C: sb          $zero, 0x1E5($s1)
    MEM_B(0X1E5, ctx->r17) = 0;
    // 0x8005C120: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C124: lw          $t7, 0x4C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4C);
    // 0x8005C128: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005C12C: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x8005C130: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C134: lw          $t8, 0x4C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X4C);
    // 0x8005C138: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005C13C: swc1        $f8, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
    // 0x8005C140: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C144: lw          $t2, 0x4C($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X4C);
    // 0x8005C148: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C14C: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x8005C150: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005C154: sb          $zero, 0x1E6($s1)
    MEM_B(0X1E6, ctx->r17) = 0;
    // 0x8005C158: sh          $zero, 0x1A2($s1)
    MEM_H(0X1A2, ctx->r17) = 0;
    // 0x8005C15C: sh          $zero, 0x1A6($s1)
    MEM_H(0X1A6, ctx->r17) = 0;
    // 0x8005C160: sb          $zero, 0x1D2($s1)
    MEM_B(0X1D2, ctx->r17) = 0;
    // 0x8005C164: swc1        $f18, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f18.u32l;
    // 0x8005C168: swc1        $f6, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f6.u32l;
    // 0x8005C16C: swc1        $f4, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f4.u32l;
    // 0x8005C170: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C174: swc1        $f8, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f8.u32l;
    // 0x8005C178: swc1        $f10, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f10.u32l;
    // 0x8005C17C: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C180: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C184: swc1        $f18, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f18.u32l;
    // 0x8005C188: lwc1        $f6, 0x14($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C18C: nop

    // 0x8005C190: swc1        $f6, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f6.u32l;
    // 0x8005C194: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C198: nop

    // 0x8005C19C: swc1        $f4, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f4.u32l;
    // 0x8005C1A0: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C1A4: nop

    // 0x8005C1A8: swc1        $f8, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f8.u32l;
    // 0x8005C1AC: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C1B0: nop

    // 0x8005C1B4: swc1        $f10, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f10.u32l;
    // 0x8005C1B8: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C1BC: nop

    // 0x8005C1C0: swc1        $f18, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f18.u32l;
    // 0x8005C1C4: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C1C8: nop

    // 0x8005C1CC: swc1        $f6, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f6.u32l;
    // 0x8005C1D0: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C1D4: nop

    // 0x8005C1D8: swc1        $f4, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f4.u32l;
    // 0x8005C1DC: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C1E0: nop

    // 0x8005C1E4: swc1        $f8, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f8.u32l;
    // 0x8005C1E8: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C1EC: nop

    // 0x8005C1F0: swc1        $f10, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->f10.u32l;
    // 0x8005C1F4: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C1F8: nop

    // 0x8005C1FC: swc1        $f18, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->f18.u32l;
    // 0x8005C200: sw          $zero, 0x74($s3)
    MEM_W(0X74, ctx->r19) = 0;
    // 0x8005C204: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x8005C208: jal         0x800AF714
    // 0x8005C20C: nop

    update_vehicle_particles(rdram, ctx);
        goto after_16;
    // 0x8005C20C: nop

    after_16:
L_8005C210:
    // 0x8005C210: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8005C214: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8005C218: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8005C21C: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005C220: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005C224: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8005C228: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005C22C: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8005C230: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005C234: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8005C238: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8005C23C: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8005C240: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005C244: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8005C248: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8005C24C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C250: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8005C254: jr          $ra
    // 0x8005C258: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x8005C258: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void start_bridge_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E344: bltz        $a0, L_8001E364
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E348: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_8001E364;
    }
    // 0x8001E348: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8001E34C: beq         $at, $zero, L_8001E364
    if (ctx->r1 == 0) {
        // 0x8001E350: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8001E364;
    }
    // 0x8001E350: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001E354: lw          $t7, -0x5234($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5234);
    // 0x8001E358: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8001E35C: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8001E360: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
L_8001E364:
    // 0x8001E364: jr          $ra
    // 0x8001E368: nop

    return;
    // 0x8001E368: nop

;}
RECOMP_FUNC void cheatlist_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AD1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008AD20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008AD24: jal         0x8009C508
    // 0x8008AD28: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    menu_asset_free(rdram, ctx);
        goto after_0;
    // 0x8008AD28: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_0:
    // 0x8008AD2C: jal         0x800C422C
    // 0x8008AD30: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x8008AD30: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8008AD34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008AD38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AD3C: jr          $ra
    // 0x8008AD40: nop

    return;
    // 0x8008AD40: nop

;}
RECOMP_FUNC void tri2d_xz_contains_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800704F0: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800704F4: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x800704F8: lh          $t1, 0x4($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X4);
    // 0x800704FC: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x80070500: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80070504: lh          $t5, 0x4($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X4);
    // 0x80070508: sub         $t6, $a0, $t0
    ctx->r14 = SUB32(ctx->r4, ctx->r8);
    // 0x8007050C: sub         $t7, $t3, $t1
    ctx->r15 = SUB32(ctx->r11, ctx->r9);
    // 0x80070510: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070514: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x80070518: sub         $t9, $a1, $t1
    ctx->r25 = SUB32(ctx->r5, ctx->r9);
    // 0x8007051C: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x80070520: sub         $t8, $t2, $t0
    ctx->r24 = SUB32(ctx->r10, ctx->r8);
    // 0x80070524: ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // 0x80070528: mflo        $t6
    ctx->r14 = lo;
    // 0x8007052C: mflo        $t6
    ctx->r14 = lo;
    // 0x80070530: nop

    // 0x80070534: nop

    // 0x80070538: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007053C: mflo        $t7
    ctx->r15 = lo;
    // 0x80070540: mflo        $t8
    ctx->r24 = lo;
    // 0x80070544: sub         $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80070548: bgezl       $t6, L_80070558
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8007054C: sub         $t6, $a0, $t2
        ctx->r14 = SUB32(ctx->r4, ctx->r10);
            goto L_80070558;
    }
    goto skip_0;
    // 0x8007054C: sub         $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
    skip_0:
    // 0x80070550: xor         $a3, $a3, $a3
    ctx->r7 = ctx->r7 ^ ctx->r7;
    // 0x80070554: sub         $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
L_80070558:
    // 0x80070558: sub         $t7, $t5, $t3
    ctx->r15 = SUB32(ctx->r13, ctx->r11);
    // 0x8007055C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070560: sub         $t8, $t4, $t2
    ctx->r24 = SUB32(ctx->r12, ctx->r10);
    // 0x80070564: sub         $t9, $a1, $t3
    ctx->r25 = SUB32(ctx->r5, ctx->r11);
    // 0x80070568: ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // 0x8007056C: mflo        $t6
    ctx->r14 = lo;
    // 0x80070570: mflo        $t6
    ctx->r14 = lo;
    // 0x80070574: nop

    // 0x80070578: nop

    // 0x8007057C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070580: mflo        $t7
    ctx->r15 = lo;
    // 0x80070584: mflo        $t8
    ctx->r24 = lo;
    // 0x80070588: sub         $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8007058C: bgez        $t6, L_80070598
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80070590: nop
    
            goto L_80070598;
    }
    // 0x80070590: nop

    // 0x80070594: xor         $a2, $a2, $a2
    ctx->r6 = ctx->r6 ^ ctx->r6;
L_80070598:
    // 0x80070598: bne         $a3, $a2, L_800705F0
    if (ctx->r7 != ctx->r6) {
        // 0x8007059C: nop
    
            goto L_800705F0;
    }
    // 0x8007059C: nop

    // 0x800705A0: sub         $t6, $a0, $t4
    ctx->r14 = SUB32(ctx->r4, ctx->r12);
    // 0x800705A4: sub         $t7, $t1, $t5
    ctx->r15 = SUB32(ctx->r9, ctx->r13);
    // 0x800705A8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800705AC: sub         $t8, $t0, $t4
    ctx->r24 = SUB32(ctx->r8, ctx->r12);
    // 0x800705B0: sub         $t9, $a1, $t5
    ctx->r25 = SUB32(ctx->r5, ctx->r13);
    // 0x800705B4: ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // 0x800705B8: mflo        $t6
    ctx->r14 = lo;
    // 0x800705BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800705C0: nop

    // 0x800705C4: nop

    // 0x800705C8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800705CC: mflo        $t7
    ctx->r15 = lo;
    // 0x800705D0: mflo        $t8
    ctx->r24 = lo;
    // 0x800705D4: sub         $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x800705D8: bgez        $t6, L_800705E4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800705DC: nop
    
            goto L_800705E4;
    }
    // 0x800705DC: nop

    // 0x800705E0: xor         $a1, $a1, $a1
    ctx->r5 = ctx->r5 ^ ctx->r5;
L_800705E4:
    // 0x800705E4: bne         $a1, $a2, L_800705F0
    if (ctx->r5 != ctx->r6) {
        // 0x800705E8: nop
    
            goto L_800705F0;
    }
    // 0x800705E8: nop

    // 0x800705EC: ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_800705F0:
    // 0x800705F0: jr          $ra
    // 0x800705F4: nop

    return;
    // 0x800705F4: nop

;}
RECOMP_FUNC void music_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B34: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80000B38: lw          $t7, -0x39B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X39B8);
    // 0x80000B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000B44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000B48: bne         $t7, $zero, L_80000BD0
    if (ctx->r15 != 0) {
        // 0x80000B4C: andi        $t6, $a0, 0xFF
        ctx->r14 = ctx->r4 & 0XFF;
            goto L_80000BD0;
    }
    // 0x80000B4C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80000B50: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80000B54: lw          $t8, -0x39AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X39AC);
    // 0x80000B58: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000B5C: beq         $t8, $zero, L_80000BD0
    if (ctx->r24 == 0) {
        // 0x80000B60: addiu       $v0, $v0, 0x5D04
        ctx->r2 = ADD32(ctx->r2, 0X5D04);
            goto L_80000BD0;
    }
    // 0x80000B60: addiu       $v0, $v0, 0x5D04
    ctx->r2 = ADD32(ctx->r2, 0X5D04);
    // 0x80000B64: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80000B68: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80000B6C: lbu         $t0, -0x39C0($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X39C0);
    // 0x80000B70: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x80000B74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000B78: beq         $t0, $zero, L_80000B94
    if (ctx->r8 == 0) {
        // 0x80000B7C: sb          $t9, -0x39C8($at)
        MEM_B(-0X39C8, ctx->r1) = ctx->r25;
            goto L_80000B94;
    }
    // 0x80000B7C: sb          $t9, -0x39C8($at)
    MEM_B(-0X39C8, ctx->r1) = ctx->r25;
    // 0x80000B80: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80000B84: lw          $a1, -0x39D0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X39D0);
    // 0x80000B88: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80000B8C: jal         0x800022BC
    // 0x80000B90: nop

    music_sequence_start(rdram, ctx);
        goto after_0;
    // 0x80000B90: nop

    after_0:
L_80000B94:
    // 0x80000B94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000B98: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80000B9C: jal         0x800C7890
    // 0x80000BA0: nop

    alCSPGetTempo(rdram, ctx);
        goto after_1;
    // 0x80000BA0: nop

    after_1:
    // 0x80000BA4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000BA8: jal         0x800C78D0
    // 0x80000BAC: sw          $v0, 0x5D08($at)
    MEM_W(0X5D08, ctx->r1) = ctx->r2;
    osGetCount_recomp(rdram, ctx);
        goto after_2;
    // 0x80000BAC: sw          $v0, 0x5D08($at)
    MEM_W(0X5D08, ctx->r1) = ctx->r2;
    after_2:
    // 0x80000BB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000BB4: sw          $v0, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = ctx->r2;
    // 0x80000BB8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000BBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80000BC0: sb          $t1, 0x5D40($at)
    MEM_B(0X5D40, ctx->r1) = ctx->r9;
    // 0x80000BC4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000BC8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80000BCC: sw          $t2, 0x5F7C($at)
    MEM_W(0X5F7C, ctx->r1) = ctx->r10;
L_80000BD0:
    // 0x80000BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000BD8: jr          $ra
    // 0x80000BDC: nop

    return;
    // 0x80000BDC: nop

;}
RECOMP_FUNC void is_taj_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002341C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023420: lb          $v0, -0x510A($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X510A);
    // 0x80023424: jr          $ra
    // 0x80023428: nop

    return;
    // 0x80023428: nop

;}
RECOMP_FUNC void music_jingle_pan_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001B58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001B5C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80001B60: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80001B64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80001B68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80001B6C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80001B70: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
    // 0x80001B74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001B78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001B7C: addiu       $s2, $s2, -0x39CC
    ctx->r18 = ADD32(ctx->r18, -0X39CC);
    // 0x80001B80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80001B84: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_80001B88:
    // 0x80001B88: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80001B8C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x80001B90: jal         0x800C78E0
    // 0x80001B94: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    alCSPSetChlPan(rdram, ctx);
        goto after_0;
    // 0x80001B94: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    after_0:
    // 0x80001B98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80001B9C: bne         $s0, $s3, L_80001B88
    if (ctx->r16 != ctx->r19) {
        // 0x80001BA0: nop
    
            goto L_80001B88;
    }
    // 0x80001BA0: nop

    // 0x80001BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001BA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80001BAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80001BB0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80001BB4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80001BB8: jr          $ra
    // 0x80001BBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001BBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alCSeqNewMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8110: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x800C8114: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C8118: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C811C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C8120: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x800C8124: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C8128: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800C812C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800C8130: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C8134: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C8138: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C813C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800C8140: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800C8144: jal         0x800C7FFC
    // 0x800C8148: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    alCSeqNew(rdram, ctx);
        goto after_0;
    // 0x800C8148: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800C814C: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x800C8150: addiu       $s4, $sp, 0x140
    ctx->r20 = ADD32(ctx->r29, 0X140);
    // 0x800C8154: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800C8158: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_800C815C:
    // 0x800C815C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800C8160: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C8164: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C8168: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800C816C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800C8170: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C8174: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x800C8178: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800C817C: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
L_800C8180:
    // 0x800C8180: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x800C8184: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C8188: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C818C: sw          $t0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r8;
    // 0x800C8190: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x800C8194: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800C8198: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800C819C: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x800C81A0: lbu         $t2, 0x94($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X94);
    // 0x800C81A4: sb          $t2, 0x88($a1)
    MEM_B(0X88, ctx->r5) = ctx->r10;
    // 0x800C81A8: lbu         $t3, 0xA4($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA4);
    // 0x800C81AC: sb          $t3, 0x98($a1)
    MEM_B(0X98, ctx->r5) = ctx->r11;
    // 0x800C81B0: lw          $t4, 0xA8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA8);
    // 0x800C81B4: sw          $t4, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r12;
    // 0x800C81B8: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800C81BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C81C0: lw          $t6, 0x4C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4C);
    // 0x800C81C4: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x800C81C8: lbu         $t7, 0x95($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X95);
    // 0x800C81CC: sb          $t7, 0x89($a1)
    MEM_B(0X89, ctx->r5) = ctx->r15;
    // 0x800C81D0: lbu         $t8, 0xA5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA5);
    // 0x800C81D4: sb          $t8, 0x99($a1)
    MEM_B(0X99, ctx->r5) = ctx->r24;
    // 0x800C81D8: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x800C81DC: sw          $t9, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r25;
    // 0x800C81E0: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x800C81E4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800C81E8: lw          $t1, 0x50($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X50);
    // 0x800C81EC: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x800C81F0: lbu         $t2, 0x96($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X96);
    // 0x800C81F4: sb          $t2, 0x8A($a1)
    MEM_B(0X8A, ctx->r5) = ctx->r10;
    // 0x800C81F8: lbu         $t3, 0xA6($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA6);
    // 0x800C81FC: sb          $t3, 0x9A($a1)
    MEM_B(0X9A, ctx->r5) = ctx->r11;
    // 0x800C8200: lw          $t4, 0xB0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XB0);
    // 0x800C8204: sw          $t4, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r12;
    // 0x800C8208: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x800C820C: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800C8210: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x800C8214: sw          $t6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r14;
    // 0x800C8218: lbu         $t7, 0x97($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X97);
    // 0x800C821C: sb          $t7, 0x8B($a1)
    MEM_B(0X8B, ctx->r5) = ctx->r15;
    // 0x800C8220: lbu         $t8, 0xA7($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA7);
    // 0x800C8224: sb          $t8, 0x9B($a1)
    MEM_B(0X9B, ctx->r5) = ctx->r24;
    // 0x800C8228: lw          $t9, 0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB4);
    // 0x800C822C: bne         $a0, $s0, L_800C8180
    if (ctx->r4 != ctx->r16) {
        // 0x800C8230: sw          $t9, 0xA8($v0)
        MEM_W(0XA8, ctx->r2) = ctx->r25;
            goto L_800C8180;
    }
    // 0x800C8230: sw          $t9, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r25;
    // 0x800C8234: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C8238: jal         0x800C7D04
    // 0x800C823C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alCSeqNextEvent(rdram, ctx);
        goto after_1;
    // 0x800C823C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x800C8240: lh          $t0, 0x140($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X140);
    // 0x800C8244: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800C8248: beq         $t0, $s5, L_800C8258
    if (ctx->r8 == ctx->r21) {
        // 0x800C824C: sltu        $at, $t1, $s2
        ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
            goto L_800C8258;
    }
    // 0x800C824C: sltu        $at, $t1, $s2
    ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x800C8250: bnel        $at, $zero, L_800C815C
    if (ctx->r1 != 0) {
        // 0x800C8254: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_800C815C;
    }
    goto skip_0;
    // 0x800C8254: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_800C8258:
    // 0x800C8258: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C825C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C8260: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C8264: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8268: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C826C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800C8270: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800C8274: jr          $ra
    // 0x800C8278: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x800C8278: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void drm_disable_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A6A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006A6A4: jr          $ra
    // 0x8006A6A8: sh          $zero, -0x2CFC($at)
    MEM_H(-0X2CFC, ctx->r1) = 0;
    return;
    // 0x8006A6A8: sh          $zero, -0x2CFC($at)
    MEM_H(-0X2CFC, ctx->r1) = 0;
;}
RECOMP_FUNC void menu_unload_bigfont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800981E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800981EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800981F0: jal         0x800C422C
    // 0x800981F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x800981F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x800981F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800981FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098200: jr          $ra
    // 0x80098204: nop

    return;
    // 0x80098204: nop

;}
RECOMP_FUNC void mode_end_taj_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022E18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80022E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022E20: jal         0x8006BDB0
    // 0x80022E24: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80022E24: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80022E28: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80022E2C: sb          $t6, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r14;
    // 0x80022E30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80022E34: lb          $t7, -0x5108($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X5108);
    // 0x80022E38: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80022E3C: sb          $t7, 0x52($v0)
    MEM_B(0X52, ctx->r2) = ctx->r15;
    // 0x80022E40: lw          $t8, -0x5104($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5104);
    // 0x80022E44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80022E48: jal         0x800AB1AC
    // 0x80022E4C: sh          $t8, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r24;
    minimap_opacity_set(rdram, ctx);
        goto after_1;
    // 0x80022E4C: sh          $t8, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r24;
    after_1:
    // 0x80022E50: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80022E54: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80022E58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022E5C: addiu       $a2, $a2, -0x5110
    ctx->r6 = ADD32(ctx->r6, -0X5110);
    // 0x80022E60: addiu       $a3, $a3, -0x511C
    ctx->r7 = ADD32(ctx->r7, -0X511C);
    // 0x80022E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80022E68:
    // 0x80022E68: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80022E6C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80022E70: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80022E74: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80022E78: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022E7C: lw          $v1, 0x64($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X64);
    // 0x80022E80: nop

    // 0x80022E84: sb          $zero, 0x1D8($v1)
    MEM_B(0X1D8, ctx->r3) = 0;
    // 0x80022E88: sb          $zero, 0x193($v1)
    MEM_B(0X193, ctx->r3) = 0;
    // 0x80022E8C: sb          $zero, 0x192($v1)
    MEM_B(0X192, ctx->r3) = 0;
    // 0x80022E90: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x80022E94: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80022E98: nop

    // 0x80022E9C: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80022EA0: bne         $at, $zero, L_80022E68
    if (ctx->r1 != 0) {
        // 0x80022EA4: nop
    
            goto L_80022E68;
    }
    // 0x80022EA4: nop

    // 0x80022EA8: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80022EAC: nop

    // 0x80022EB0: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x80022EB4: jal         0x8000FFB8
    // 0x80022EB8: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x80022EB8: nop

    after_2:
    // 0x80022EBC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80022EC0: addiu       $a3, $a3, -0x511C
    ctx->r7 = ADD32(ctx->r7, -0X511C);
    // 0x80022EC4: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80022EC8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80022ECC: lw          $t6, -0x5118($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5118);
    // 0x80022ED0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80022ED4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80022ED8: addiu       $a2, $a2, -0x5110
    ctx->r6 = ADD32(ctx->r6, -0X5110);
    // 0x80022EDC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80022EE0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80022EE4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80022EE8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80022EEC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80022EF0: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x80022EF4: lw          $a1, -0x51A0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X51A0);
    // 0x80022EF8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80022EFC: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022F00: beq         $at, $zero, L_80022F50
    if (ctx->r1 == 0) {
        // 0x80022F04: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_80022F50;
    }
    // 0x80022F04: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80022F08: lw          $t8, -0x51A8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X51A8);
    // 0x80022F0C: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
    // 0x80022F10: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80022F14: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
L_80022F18:
    // 0x80022F18: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80022F1C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022F20: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80022F24: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80022F28: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80022F2C: bne         $t0, $zero, L_80022F48
    if (ctx->r8 != 0) {
        // 0x80022F30: nop
    
            goto L_80022F48;
    }
    // 0x80022F30: nop

    // 0x80022F34: lh          $t1, 0x48($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X48);
    // 0x80022F38: nop

    // 0x80022F3C: bne         $a1, $t1, L_80022F48
    if (ctx->r5 != ctx->r9) {
        // 0x80022F40: nop
    
            goto L_80022F48;
    }
    // 0x80022F40: nop

    // 0x80022F44: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_80022F48:
    // 0x80022F48: bne         $at, $zero, L_80022F18
    if (ctx->r1 != 0) {
        // 0x80022F4C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80022F18;
    }
    // 0x80022F4C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80022F50:
    // 0x80022F50: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80022F54: nop

    // 0x80022F58: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80022F5C: nop

    // 0x80022F60: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x80022F64: nop

    // 0x80022F68: lw          $a0, 0x15C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X15C);
    // 0x80022F6C: nop

    // 0x80022F70: beq         $a0, $zero, L_80022F90
    if (ctx->r4 == 0) {
        // 0x80022F74: lw          $t4, 0x30($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X30);
            goto L_80022F90;
    }
    // 0x80022F74: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80022F78: jal         0x8000FFB8
    // 0x80022F7C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    free_object(rdram, ctx);
        goto after_3;
    // 0x80022F7C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80022F80: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80022F84: nop

    // 0x80022F88: sw          $zero, 0x15C($v1)
    MEM_W(0X15C, ctx->r3) = 0;
    // 0x80022F8C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80022F90:
    // 0x80022F90: nop

    // 0x80022F94: bne         $t4, $zero, L_80023048
    if (ctx->r12 != 0) {
        // 0x80022F98: nop
    
            goto L_80023048;
    }
    // 0x80022F98: nop

    // 0x80022F9C: lh          $t5, 0x1AC($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1AC);
    // 0x80022FA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80022FA4: bne         $t5, $at, L_80023024
    if (ctx->r13 != ctx->r1) {
        // 0x80022FA8: nop
    
            goto L_80023024;
    }
    // 0x80022FA8: nop

    // 0x80022FAC: jal         0x8006EA90
    // 0x80022FB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    get_settings(rdram, ctx);
        goto after_4;
    // 0x80022FB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x80022FB4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80022FB8: lhu         $t8, 0x14($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X14);
    // 0x80022FBC: lb          $a3, 0x1D6($v1)
    ctx->r7 = MEM_B(ctx->r3, 0X1D6);
    // 0x80022FC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80022FC4: addiu       $t6, $a3, 0x3
    ctx->r14 = ADD32(ctx->r7, 0X3);
    // 0x80022FC8: sllv        $a1, $t7, $t6
    ctx->r5 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80022FCC: and         $t9, $t8, $a1
    ctx->r25 = ctx->r24 & ctx->r5;
    // 0x80022FD0: beq         $t9, $zero, L_80022FE8
    if (ctx->r25 == 0) {
        // 0x80022FD4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80022FE8;
    }
    // 0x80022FD4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80022FD8: jal         0x8009D330
    // 0x80022FDC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_5;
    // 0x80022FDC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x80022FE0: b           L_80023030
    // 0x80022FE4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
        goto L_80023030;
    // 0x80022FE4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80022FE8:
    // 0x80022FE8: addiu       $a0, $a3, 0x6
    ctx->r4 = ADD32(ctx->r7, 0X6);
    // 0x80022FEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80022FF0: jal         0x8009D330
    // 0x80022FF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_6;
    // 0x80022FF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_6:
    // 0x80022FF8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80022FFC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80023000: lhu         $t0, 0x14($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X14);
    // 0x80023004: nop

    // 0x80023008: or          $t1, $t0, $a1
    ctx->r9 = ctx->r8 | ctx->r5;
    // 0x8002300C: jal         0x8009C1A0
    // 0x80023010: sh          $t1, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r9;
    get_save_file_index(rdram, ctx);
        goto after_7;
    // 0x80023010: sh          $t1, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r9;
    after_7:
    // 0x80023014: jal         0x8006EC48
    // 0x80023018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_8;
    // 0x80023018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x8002301C: b           L_80023030
    // 0x80023020: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
        goto L_80023030;
    // 0x80023020: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80023024:
    // 0x80023024: jal         0x8009D330
    // 0x80023028: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_9;
    // 0x80023028: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_9:
    // 0x8002302C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80023030:
    // 0x80023030: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x80023034: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80023038: jal         0x800521B8
    // 0x8002303C: sw          $t2, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->r10;
    set_taj_status(rdram, ctx);
        goto after_10;
    // 0x8002303C: sw          $t2, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->r10;
    after_10:
    // 0x80023040: b           L_8002309C
    // 0x80023044: nop

        goto L_8002309C;
    // 0x80023044: nop

L_80023048:
    // 0x80023048: jal         0x80000B28
    // 0x8002304C: nop

    music_change_on(rdram, ctx);
        goto after_11;
    // 0x8002304C: nop

    after_11:
    // 0x80023050: jal         0x80001844
    // 0x80023054: nop

    music_stop(rdram, ctx);
        goto after_12;
    // 0x80023054: nop

    after_12:
    // 0x80023058: jal         0x8009D330
    // 0x8002305C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_13;
    // 0x8002305C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80023060: jal         0x80008168
    // 0x80023064: nop

    audspat_jingle_on(rdram, ctx);
        goto after_14;
    // 0x80023064: nop

    after_14:
    // 0x80023068: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8002306C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023070: bne         $t4, $at, L_80023080
    if (ctx->r12 != ctx->r1) {
        // 0x80023074: nop
    
            goto L_80023080;
    }
    // 0x80023074: nop

    // 0x80023078: jal         0x800C31EC
    // 0x8002307C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_current_text(rdram, ctx);
        goto after_15;
    // 0x8002307C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
L_80023080:
    // 0x80023080: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80023084: sw          $zero, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = 0;
    // 0x80023088: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002308C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80023090: sw          $zero, -0x5248($at)
    MEM_W(-0X5248, ctx->r1) = 0;
    // 0x80023094: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80023098: sw          $t5, 0x78($t7)
    MEM_W(0X78, ctx->r15) = ctx->r13;
L_8002309C:
    // 0x8002309C: jal         0x80000B28
    // 0x800230A0: nop

    music_change_on(rdram, ctx);
        goto after_16;
    // 0x800230A0: nop

    after_16:
    // 0x800230A4: jal         0x800A0B74
    // 0x800230A8: nop

    hud_audio_init(rdram, ctx);
        goto after_17;
    // 0x800230A8: nop

    after_17:
    // 0x800230AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800230B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800230B4: jal         0x8006BD10
    // 0x800230B8: nop

    level_music_start(rdram, ctx);
        goto after_18;
    // 0x800230B8: nop

    after_18:
    // 0x800230BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800230C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800230C4: sb          $zero, -0x510A($at)
    MEM_B(-0X510A, ctx->r1) = 0;
    // 0x800230C8: jr          $ra
    // 0x800230CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800230CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bgload_kill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C73BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C73C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C73C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C73C8: jal         0x800C8AF0
    // 0x800C73CC: addiu       $a0, $a0, -0x5510
    ctx->r4 = ADD32(ctx->r4, -0X5510);
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800C73CC: addiu       $a0, $a0, -0x5510
    ctx->r4 = ADD32(ctx->r4, -0X5510);
    after_0:
    // 0x800C73D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C73D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C73D8: jr          $ra
    // 0x800C73DC: nop

    return;
    // 0x800C73DC: nop

;}
RECOMP_FUNC void lensflare_override(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD030: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AD034: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AD038: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800AD03C: addiu       $s6, $s6, 0x2A88
    ctx->r22 = ADD32(ctx->r22, 0X2A88);
    // 0x800AD040: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AD044: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800AD048: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AD04C: addiu       $s5, $s5, 0x2A84
    ctx->r21 = ADD32(ctx->r21, 0X2A84);
    // 0x800AD050: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AD054: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800AD058: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800AD05C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AD060: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AD064: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AD068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AD06C: blez        $v0, L_800AD11C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AD070: sw          $zero, 0x0($s5)
        MEM_W(0X0, ctx->r21) = 0;
            goto L_800AD11C;
    }
    // 0x800AD070: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800AD074: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AD078: lw          $t6, 0x2A80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2A80);
    // 0x800AD07C: nop

    // 0x800AD080: beq         $t6, $zero, L_800AD120
    if (ctx->r14 == 0) {
        // 0x800AD084: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800AD120;
    }
    // 0x800AD084: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800AD088: blez        $v0, L_800AD11C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AD08C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800AD11C;
    }
    // 0x800AD08C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AD090: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800AD094: addiu       $s0, $s0, 0x7C40
    ctx->r16 = ADD32(ctx->r16, 0X7C40);
    // 0x800AD098: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800AD09C:
    // 0x800AD09C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AD0A0: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800AD0A4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AD0A8: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800AD0AC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AD0B0: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800AD0B4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800AD0B8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AD0BC: lwc1        $f16, 0x14($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800AD0C0: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AD0C4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800AD0C8: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AD0CC: lw          $s2, 0x3C($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X3C);
    // 0x800AD0D0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800AD0D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AD0D8: jal         0x800C9AD0
    // 0x800AD0DC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800AD0DC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800AD0E0: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    // 0x800AD0E4: nop

    // 0x800AD0E8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800AD0EC: nop

    // 0x800AD0F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AD0F4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800AD0F8: nop

    // 0x800AD0FC: bc1f        L_800AD108
    if (!c1cs) {
        // 0x800AD100: nop
    
            goto L_800AD108;
    }
    // 0x800AD100: nop

    // 0x800AD104: sw          $s4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r20;
L_800AD108:
    // 0x800AD108: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800AD10C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AD110: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AD114: bne         $at, $zero, L_800AD09C
    if (ctx->r1 != 0) {
        // 0x800AD118: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800AD09C;
    }
    // 0x800AD118: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800AD11C:
    // 0x800AD11C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800AD120:
    // 0x800AD120: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AD124: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD128: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AD12C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AD130: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AD134: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AD138: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AD13C: jr          $ra
    // 0x800AD140: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AD140: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800BF9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF9F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BF9FC: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x800BFA00: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800BFA04: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800BFA08: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800BFA0C: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BFA10: beq         $a0, $zero, L_800BFC3C
    if (ctx->r4 == 0) {
        // 0x800BFA14: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_800BFC3C;
    }
    // 0x800BFA14: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800BFA18: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BFA1C: lw          $t6, -0x6010($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6010);
    // 0x800BFA20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BFA24: lwc1        $f0, -0x5F48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5F48);
    // 0x800BFA28: beq         $t6, $zero, L_800BFA44
    if (ctx->r14 == 0) {
        // 0x800BFA2C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BFA44;
    }
    // 0x800BFA2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFA30: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BFA34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BFA38: nop

    // 0x800BFA3C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800BFA40: nop

L_800BFA44:
    // 0x800BFA44: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BFA48: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BFA4C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BFA50: lhu         $v1, 0x18($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X18);
    // 0x800BFA54: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BFA58: addiu       $t3, $t3, -0x5F30
    ctx->r11 = ADD32(ctx->r11, -0X5F30);
    // 0x800BFA5C: addiu       $t4, $t4, 0x318C
    ctx->r12 = ADD32(ctx->r12, 0X318C);
    // 0x800BFA60: addiu       $t5, $t5, 0x3184
    ctx->r13 = ADD32(ctx->r13, 0X3184);
    // 0x800BFA64: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x800BFA68: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
L_800BFA6C:
    // 0x800BFA6C: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800BFA70: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800BFA74: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800BFA78: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800BFA7C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BFA80: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x800BFA84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800BFA88: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800BFA8C: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800BFA90: nop

    // 0x800BFA94: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BFA98: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BFA9C: nop

    // 0x800BFAA0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BFAA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BFAA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BFAAC: nop

    // 0x800BFAB0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800BFAB4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800BFAB8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BFABC: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800BFAC0: bne         $at, $zero, L_800BFAD0
    if (ctx->r1 != 0) {
        // 0x800BFAC4: nop
    
            goto L_800BFAD0;
    }
    // 0x800BFAC4: nop

    // 0x800BFAC8: b           L_800BFADC
    // 0x800BFACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800BFADC;
    // 0x800BFACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800BFAD0:
    // 0x800BFAD0: bgez        $a2, L_800BFADC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800BFAD4: nop
    
            goto L_800BFADC;
    }
    // 0x800BFAD4: nop

    // 0x800BFAD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800BFADC:
    // 0x800BFADC: beq         $a1, $zero, L_800BFB34
    if (ctx->r5 == 0) {
        // 0x800BFAE0: nop
    
            goto L_800BFB34;
    }
    // 0x800BFAE0: nop

    // 0x800BFAE4: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800BFAE8: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800BFAEC: nop

    // 0x800BFAF0: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BFAF4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BFAF8: nop

    // 0x800BFAFC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BFB00: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BFB04: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BFB08: nop

    // 0x800BFB0C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BFB10: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800BFB14: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BFB18: bgez        $t0, L_800BFB28
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800BFB1C: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800BFB28;
    }
    // 0x800BFB1C: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800BFB20: b           L_800BFB34
    // 0x800BFB24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800BFB34;
    // 0x800BFB24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800BFB28:
    // 0x800BFB28: bne         $at, $zero, L_800BFB34
    if (ctx->r1 != 0) {
        // 0x800BFB2C: nop
    
            goto L_800BFB34;
    }
    // 0x800BFB2C: nop

    // 0x800BFB30: addiu       $t0, $a3, -0x1
    ctx->r8 = ADD32(ctx->r7, -0X1);
L_800BFB34:
    // 0x800BFB34: beq         $a1, $zero, L_800BFBF0
    if (ctx->r5 == 0) {
        // 0x800BFB38: slt         $at, $t0, $a2
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800BFBF0;
    }
    // 0x800BFB38: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BFB3C: bne         $at, $zero, L_800BFBF0
    if (ctx->r1 != 0) {
        // 0x800BFB40: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800BFBF0;
    }
    // 0x800BFB40: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800BFB44: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
L_800BFB48:
    // 0x800BFB48: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800BFB4C: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800BFB50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BFB54: beq         $v0, $zero, L_800BFB94
    if (ctx->r2 == 0) {
        // 0x800BFB58: addu        $a2, $t6, $t7
        ctx->r6 = ADD32(ctx->r14, ctx->r15);
            goto L_800BFB94;
    }
    // 0x800BFB58: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800BFB5C: lbu         $t8, 0x7($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X7);
    // 0x800BFB60: nop

    // 0x800BFB64: bne         $s0, $t8, L_800BFBE4
    if (ctx->r16 != ctx->r24) {
        // 0x800BFB68: nop
    
            goto L_800BFBE4;
    }
    // 0x800BFB68: nop

    // 0x800BFB6C: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800BFB70: nop

    // 0x800BFB74: beq         $s0, $t9, L_800BFB8C
    if (ctx->r16 == ctx->r25) {
        // 0x800BFB78: nop
    
            goto L_800BFB8C;
    }
    // 0x800BFB78: nop

L_800BFB7C:
    // 0x800BFB7C: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x800BFB80: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BFB84: bne         $s0, $t6, L_800BFB7C
    if (ctx->r16 != ctx->r14) {
        // 0x800BFB88: nop
    
            goto L_800BFB7C;
    }
    // 0x800BFB88: nop

L_800BFB8C:
    // 0x800BFB8C: b           L_800BFBE4
    // 0x800BFB90: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
        goto L_800BFBE4;
    // 0x800BFB90: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
L_800BFB94:
    // 0x800BFB94: addu        $t1, $a2, $a3
    ctx->r9 = ADD32(ctx->r6, ctx->r7);
L_800BFB98:
    // 0x800BFB98: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x800BFB9C: slti        $at, $a3, 0x7
    ctx->r1 = SIGNED(ctx->r7) < 0X7 ? 1 : 0;
    // 0x800BFBA0: bne         $v1, $t7, L_800BFBD4
    if (ctx->r3 != ctx->r15) {
        // 0x800BFBA4: nop
    
            goto L_800BFBD4;
    }
    // 0x800BFBA4: nop

    // 0x800BFBA8: beq         $at, $zero, L_800BFBC8
    if (ctx->r1 == 0) {
        // 0x800BFBAC: nop
    
            goto L_800BFBC8;
    }
    // 0x800BFBAC: nop

L_800BFBB0:
    // 0x800BFBB0: lbu         $t8, 0x1($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1);
    // 0x800BFBB4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BFBB8: slti        $at, $a3, 0x7
    ctx->r1 = SIGNED(ctx->r7) < 0X7 ? 1 : 0;
    // 0x800BFBBC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800BFBC0: bne         $at, $zero, L_800BFBB0
    if (ctx->r1 != 0) {
        // 0x800BFBC4: sb          $t8, -0x1($t1)
        MEM_B(-0X1, ctx->r9) = ctx->r24;
            goto L_800BFBB0;
    }
    // 0x800BFBC4: sb          $t8, -0x1($t1)
    MEM_B(-0X1, ctx->r9) = ctx->r24;
L_800BFBC8:
    // 0x800BFBC8: sb          $s1, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r17;
    // 0x800BFBCC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BFBD0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800BFBD4:
    // 0x800BFBD4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BFBD8: slti        $at, $a3, 0x8
    ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x800BFBDC: bne         $at, $zero, L_800BFB98
    if (ctx->r1 != 0) {
        // 0x800BFBE0: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800BFB98;
    }
    // 0x800BFBE0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800BFBE4:
    // 0x800BFBE4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BFBE8: bne         $t2, $a1, L_800BFB48
    if (ctx->r10 != ctx->r5) {
        // 0x800BFBEC: nop
    
            goto L_800BFB48;
    }
    // 0x800BFBEC: nop

L_800BFBF0:
    // 0x800BFBF0: bne         $v0, $zero, L_800BFC2C
    if (ctx->r2 != 0) {
        // 0x800BFBF4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800BFC2C;
    }
    // 0x800BFBF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BFBF8: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800BFBFC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BFC00: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800BFC04: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800BFC08: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800BFC0C: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800BFC10: add.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f20.fl;
    // 0x800BFC14: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x800BFC18: add.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x800BFC1C: swc1        $f14, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f14.u32l;
    // 0x800BFC20: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x800BFC24: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800BFC28: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
L_800BFC2C:
    // 0x800BFC2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BFC30: bne         $v0, $at, L_800BFA6C
    if (ctx->r2 != ctx->r1) {
        // 0x800BFC34: nop
    
            goto L_800BFA6C;
    }
    // 0x800BFC34: nop

    // 0x800BFC38: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_800BFC3C:
    // 0x800BFC3C: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800BFC40: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800BFC44: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800BFC48: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800BFC4C: jr          $ra
    // 0x800BFC50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800BFC50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void savemenu_input_confirm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800876D0: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x800876D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800876D8: beq         $t6, $zero, L_800876FC
    if (ctx->r14 == 0) {
        // 0x800876DC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800876FC;
    }
    // 0x800876DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800876E0: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800876E4: jal         0x80001D04
    // 0x800876E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x800876E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800876EC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800876F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800876F4: b           L_80087724
    // 0x800876F8: sw          $t7, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r15;
        goto L_80087724;
    // 0x800876F8: sw          $t7, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r15;
L_800876FC:
    // 0x800876FC: andi        $t8, $a0, 0x9000
    ctx->r24 = ctx->r4 & 0X9000;
    // 0x80087700: beq         $t8, $zero, L_80087724
    if (ctx->r24 == 0) {
        // 0x80087704: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80087724;
    }
    // 0x80087704: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80087708: jal         0x80001D04
    // 0x8008770C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8008770C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80087710: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80087714: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087718: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
    // 0x8008771C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087720: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
L_80087724:
    // 0x80087724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008772C: jr          $ra
    // 0x80087730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80087730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void set_text_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C42EC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C42F0: lw          $t6, -0x5820($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5820);
    // 0x800C42F4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C42F8: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C42FC: beq         $at, $zero, L_800C4310
    if (ctx->r1 == 0) {
        // 0x800C4300: nop
    
            goto L_800C4310;
    }
    // 0x800C4300: nop

    // 0x800C4304: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C4308: nop

    // 0x800C430C: sb          $a0, 0x1D($t7)
    MEM_B(0X1D, ctx->r15) = ctx->r4;
L_800C4310:
    // 0x800C4310: jr          $ra
    // 0x800C4314: nop

    return;
    // 0x800C4314: nop

;}
RECOMP_FUNC void obj_loop_airzippers_waterzippers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003596C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80035970: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80035974: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80035978: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8003597C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80035980: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80035984: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80035988: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003598C: jal         0x8000E1CC
    // 0x80035990: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    find_non_car_racers(rdram, ctx);
        goto after_0;
    // 0x80035990: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80035994: bne         $v0, $zero, L_800359B0
    if (ctx->r2 != 0) {
        // 0x80035998: nop
    
            goto L_800359B0;
    }
    // 0x80035998: nop

    // 0x8003599C: lh          $t6, 0x6($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X6);
    // 0x800359A0: nop

    // 0x800359A4: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x800359A8: b           L_800359C0
    // 0x800359AC: sh          $t7, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r15;
        goto L_800359C0;
    // 0x800359AC: sh          $t7, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r15;
L_800359B0:
    // 0x800359B0: lh          $t8, 0x6($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X6);
    // 0x800359B4: nop

    // 0x800359B8: andi        $t9, $t8, 0xBFFF
    ctx->r25 = ctx->r24 & 0XBFFF;
    // 0x800359BC: sh          $t9, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r25;
L_800359C0:
    // 0x800359C0: lw          $t0, 0x4C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4C);
    // 0x800359C4: nop

    // 0x800359C8: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x800359CC: nop

    // 0x800359D0: slti        $at, $t1, 0x64
    ctx->r1 = SIGNED(ctx->r9) < 0X64 ? 1 : 0;
    // 0x800359D4: beq         $at, $zero, L_80035ACC
    if (ctx->r1 == 0) {
        // 0x800359D8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80035ACC;
    }
    // 0x800359D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800359DC: lh          $t2, 0x6($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X6);
    // 0x800359E0: nop

    // 0x800359E4: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x800359E8: bne         $t3, $zero, L_80035ACC
    if (ctx->r11 != 0) {
        // 0x800359EC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80035ACC;
    }
    // 0x800359EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800359F0: jal         0x8001BA74
    // 0x800359F4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x800359F4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x800359F8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800359FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80035A00: blez        $t4, L_80035AC8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80035A04: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80035AC8;
    }
    // 0x80035A04: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80035A08: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80035A0C:
    // 0x80035A0C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80035A10: nop

    // 0x80035A14: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x80035A18: nop

    // 0x80035A1C: lbu         $t5, 0x1F5($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1F5);
    // 0x80035A20: nop

    // 0x80035A24: bne         $t5, $zero, L_80035AB8
    if (ctx->r13 != 0) {
        // 0x80035A28: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80035AB8;
    }
    // 0x80035A28: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80035A2C: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x80035A30: nop

    // 0x80035A34: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x80035A38: beq         $at, $zero, L_80035AB8
    if (ctx->r1 == 0) {
        // 0x80035A3C: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80035AB8;
    }
    // 0x80035A3C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80035A40: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80035A44: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80035A48: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80035A4C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80035A50: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x80035A54: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80035A58: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80035A5C: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80035A60: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80035A64: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80035A68: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80035A6C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80035A70: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80035A74: jal         0x800C9AD0
    // 0x80035A78: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80035A78: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80035A7C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80035A80: nop

    // 0x80035A84: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80035A88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035A8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035A90: nop

    // 0x80035A94: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80035A98: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80035A9C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80035AA0: slti        $at, $t8, 0x64
    ctx->r1 = SIGNED(ctx->r24) < 0X64 ? 1 : 0;
    // 0x80035AA4: beq         $at, $zero, L_80035AB8
    if (ctx->r1 == 0) {
        // 0x80035AA8: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80035AB8;
    }
    // 0x80035AA8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80035AAC: sb          $s4, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = ctx->r20;
    // 0x80035AB0: sw          $s3, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r19;
    // 0x80035AB4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_80035AB8:
    // 0x80035AB8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80035ABC: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80035AC0: bne         $at, $zero, L_80035A0C
    if (ctx->r1 != 0) {
        // 0x80035AC4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80035A0C;
    }
    // 0x80035AC4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80035AC8:
    // 0x80035AC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035ACC:
    // 0x80035ACC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80035AD0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80035AD4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80035AD8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80035ADC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80035AE0: jr          $ra
    // 0x80035AE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80035AE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80012CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012CE8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012CEC: addiu       $a2, $a2, -0x525C
    ctx->r6 = ADD32(ctx->r6, -0X525C);
    // 0x80012CF0: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x80012CF4: nop

    // 0x80012CF8: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x80012CFC: beq         $at, $zero, L_80012D54
    if (ctx->r1 == 0) {
        // 0x80012D00: nop
    
            goto L_80012D54;
    }
    // 0x80012D00: nop

    // 0x80012D04: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80012D08: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x80012D0C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80012D10: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80012D14: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012D18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80012D1C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x80012D20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80012D24: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80012D28: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80012D2C: lw          $a1, -0x5288($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5288);
    // 0x80012D30: lui         $t1, 0x601
    ctx->r9 = S32(0X601 << 16);
    // 0x80012D34: sw          $t1, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r9;
    // 0x80012D38: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80012D3C: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
    // 0x80012D40: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x80012D44: lh          $t3, 0x0($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X0);
    // 0x80012D48: nop

    // 0x80012D4C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80012D50: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
L_80012D54:
    // 0x80012D54: jr          $ra
    // 0x80012D58: nop

    return;
    // 0x80012D58: nop

;}
RECOMP_FUNC void __initFromBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ACE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000ACE4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000ACE8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000ACEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000ACF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000ACF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000ACF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000ACFC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000AD00:
    // 0x8000AD00: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    // 0x8000AD04: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000AD08: beq         $s1, $zero, L_8000AD00
    if (ctx->r17 == 0) {
        // 0x8000AD0C: nop
    
            goto L_8000AD00;
    }
    // 0x8000AD0C: nop

    // 0x8000AD10: lbu         $t6, 0x34($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X34);
    // 0x8000AD14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000AD18: blez        $t6, L_8000AD4C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000AD1C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000AD4C;
    }
    // 0x8000AD1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8000AD20:
    // 0x8000AD20: jal         0x8000ADF4
    // 0x8000AD24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x8000AD24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8000AD28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AD2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000AD30: jal         0x8000AD98
    // 0x8000AD34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    __setInstChanState(rdram, ctx);
        goto after_1;
    // 0x8000AD34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x8000AD38: lbu         $t7, 0x34($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X34);
    // 0x8000AD3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000AD40: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000AD44: bne         $at, $zero, L_8000AD20
    if (ctx->r1 != 0) {
        // 0x8000AD48: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000AD20;
    }
    // 0x8000AD48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8000AD4C:
    // 0x8000AD4C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AD50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AD54: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8000AD58: nop

    // 0x8000AD5C: beq         $t9, $zero, L_8000AD84
    if (ctx->r25 == 0) {
        // 0x8000AD60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000AD84;
    }
    // 0x8000AD60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000AD64: jal         0x8000ADF4
    // 0x8000AD68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_2;
    // 0x8000AD68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8000AD6C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AD70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AD74: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x8000AD78: jal         0x8000AD98
    // 0x8000AD7C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    __setInstChanState(rdram, ctx);
        goto after_3;
    // 0x8000AD7C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_3:
    // 0x8000AD80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000AD84:
    // 0x8000AD84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000AD88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AD8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000AD90: jr          $ra
    // 0x8000AD94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000AD94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void render_racer_magnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013DCC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80013DD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013DD4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80013DD8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80013DDC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80013DE0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80013DE4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80013DE8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80013DEC: lw          $t3, 0x64($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X64);
    // 0x80013DF0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80013DF4: lb          $t0, 0x2($t3)
    ctx->r8 = MEM_B(ctx->r11, 0X2);
    // 0x80013DF8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80013DFC: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80013E00: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80013E04: lbu         $t8, -0x4F85($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4F85);
    // 0x80013E08: addiu       $s0, $s0, -0x389C
    ctx->r16 = ADD32(ctx->r16, -0X389C);
    // 0x80013E0C: beq         $t8, $zero, L_80014080
    if (ctx->r24 == 0) {
        // 0x80013E10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80014080;
    }
    // 0x80013E10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013E14: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80013E18: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80013E1C: beq         $t9, $zero, L_8001407C
    if (ctx->r25 == 0) {
        // 0x80013E20: addiu       $s1, $s1, -0x5174
        ctx->r17 = ADD32(ctx->r17, -0X5174);
            goto L_8001407C;
    }
    // 0x80013E20: addiu       $s1, $s1, -0x5174
    ctx->r17 = ADD32(ctx->r17, -0X5174);
    // 0x80013E24: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80013E28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013E2C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80013E30: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80013E34: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80013E38: sw          $t7, -0x5170($at)
    MEM_W(-0X5170, ctx->r1) = ctx->r15;
    // 0x80013E3C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80013E40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013E44: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80013E48: jal         0x8001E29C
    // 0x80013E4C: sw          $t9, -0x516C($at)
    MEM_W(-0X516C, ctx->r1) = ctx->r25;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013E4C: sw          $t9, -0x516C($at)
    MEM_W(-0X516C, ctx->r1) = ctx->r25;
    after_0:
    // 0x80013E50: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80013E54: nop

    // 0x80013E58: lb          $a0, 0x1D6($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X1D6);
    // 0x80013E5C: nop

    // 0x80013E60: bltz        $a0, L_80013E70
    if (SIGNED(ctx->r4) < 0) {
        // 0x80013E64: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80013E70;
    }
    // 0x80013E64: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80013E68: bne         $at, $zero, L_80013E74
    if (ctx->r1 != 0) {
        // 0x80013E6C: nop
    
            goto L_80013E74;
    }
    // 0x80013E6C: nop

L_80013E70:
    // 0x80013E70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80013E74:
    // 0x80013E74: lb          $t0, 0x2($t3)
    ctx->r8 = MEM_B(ctx->r11, 0X2);
    // 0x80013E78: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80013E7C: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x80013E80: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013E84: slti        $at, $t0, 0xB
    ctx->r1 = SIGNED(ctx->r8) < 0XB ? 1 : 0;
    // 0x80013E88: bne         $at, $zero, L_80013E94
    if (ctx->r1 != 0) {
        // 0x80013E8C: addu        $v1, $t5, $v0
        ctx->r3 = ADD32(ctx->r13, ctx->r2);
            goto L_80013E94;
    }
    // 0x80013E8C: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x80013E90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80013E94:
    // 0x80013E94: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80013E98: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80013E9C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80013EA0: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x80013EA4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80013EA8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80013EAC: addiu       $t4, $t4, -0x4F88
    ctx->r12 = ADD32(ctx->r12, -0X4F88);
    // 0x80013EB0: swc1        $f6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f6.u32l;
    // 0x80013EB4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80013EB8: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80013EBC: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80013EC0: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x80013EC4: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
    // 0x80013EC8: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x80013ECC: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80013ED0: sll         $t6, $t5, 26
    ctx->r14 = S32(ctx->r13 << 26);
    // 0x80013ED4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80013ED8: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80013EDC: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80013EE0: jal         0x800707F8
    // 0x80013EE4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80013EE4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_1:
    // 0x80013EE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013EEC: lwc1        $f10, 0x5580($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5580);
    // 0x80013EF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013EF4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80013EF8: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80013EFC: lwc1        $f18, 0x5584($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5584);
    // 0x80013F00: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80013F04: add.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80013F08: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80013F0C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80013F10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80013F14: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80013F18: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80013F1C: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x80013F20: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80013F24: lbu         $t9, 0x2($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X2);
    // 0x80013F28: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80013F2C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80013F30: sll         $t4, $t9, 12
    ctx->r12 = S32(ctx->r25 << 12);
    // 0x80013F34: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80013F38: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80013F3C: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x80013F40: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80013F44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80013F48: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x80013F4C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80013F50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80013F54: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x80013F58: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80013F5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80013F60: lw          $t8, 0x68($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X68);
    // 0x80013F64: nop

    // 0x80013F68: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80013F6C: nop

    // 0x80013F70: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80013F74: nop

    // 0x80013F78: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x80013F7C: lb          $t4, 0x1F($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1F);
    // 0x80013F80: nop

    // 0x80013F84: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013F88: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80013F8C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80013F90: nop

    // 0x80013F94: sw          $t7, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r15;
    // 0x80013F98: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x80013F9C: lb          $t4, 0x184($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X184);
    // 0x80013FA0: sll         $t8, $t2, 3
    ctx->r24 = S32(ctx->r10 << 3);
    // 0x80013FA4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013FA8: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80013FAC: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80013FB0: addiu       $t2, $t9, 0x80
    ctx->r10 = ADD32(ctx->r25, 0X80);
    // 0x80013FB4: lw          $a3, -0x37B4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X37B4);
    // 0x80013FB8: jal         0x8007F594
    // 0x80013FBC: or          $a2, $t2, $at
    ctx->r6 = ctx->r10 | ctx->r1;
    gfx_init_basic_xlu(rdram, ctx);
        goto after_2;
    // 0x80013FBC: or          $a2, $t2, $at
    ctx->r6 = ctx->r10 | ctx->r1;
    after_2:
    // 0x80013FC0: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80013FC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80013FC8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80013FCC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80013FD0: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x80013FD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80013FD8: jal         0x80068FA8
    // 0x80013FDC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    mtx_shear_push(rdram, ctx);
        goto after_3;
    // 0x80013FDC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80013FE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80013FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013FE8: sw          $t6, -0x38E0($at)
    MEM_W(-0X38E0, ctx->r1) = ctx->r14;
    // 0x80013FEC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80013FF0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80013FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013FF8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80013FFC: jal         0x800143A8
    // 0x80014000: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    render_mesh(rdram, ctx);
        goto after_4;
    // 0x80014000: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80014004: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80014008: sw          $zero, -0x38E0($at)
    MEM_W(-0X38E0, ctx->r1) = 0;
    // 0x8001400C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80014010: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80014014: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80014018: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8001401C: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x80014020: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80014024: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80014028: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8001402C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80014030: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80014034: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80014038: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8001403C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80014040: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80014044: jal         0x8007B3D0
    // 0x80014048: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x80014048: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    after_5:
    // 0x8001404C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80014050: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80014054: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80014058: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8001405C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80014060: lw          $t8, -0x5170($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5170);
    // 0x80014064: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80014068: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8001406C: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80014070: lw          $t4, -0x516C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X516C);
    // 0x80014074: nop

    // 0x80014078: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
L_8001407C:
    // 0x8001407C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80014080:
    // 0x80014080: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80014084: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80014088: jr          $ra
    // 0x8001408C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001408C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void input_clamp_stick_x(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A59C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A5A0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A5A4: lbu         $t6, 0x1150($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1150);
    // 0x8006A5A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A5AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006A5B0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006A5B4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006A5B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A5BC: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8006A5C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A5C4: lb          $a0, 0x1112($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X1112);
    // 0x8006A5C8: jal         0x8006A624
    // 0x8006A5CC: nop

    input_clamp_stick_mag(rdram, ctx);
        goto after_0;
    // 0x8006A5CC: nop

    after_0:
    // 0x8006A5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A5D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A5D8: jr          $ra
    // 0x8006A5DC: nop

    return;
    // 0x8006A5DC: nop

;}
RECOMP_FUNC void render_track_selection_viewport_border(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CD7C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8009CD80: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009CD84: lw          $t7, -0x89C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X89C);
    // 0x8009CD88: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8009CD8C: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8009CD90: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8009CD94: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8009CD98: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8009CD9C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8009CDA0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8009CDA4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8009CDA8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8009CDAC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009CDB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009CDB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009CDB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009CDBC: beq         $t7, $at, L_8009CDCC
    if (ctx->r15 == ctx->r1) {
        // 0x8009CDC0: sw          $t6, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r14;
            goto L_8009CDCC;
    }
    // 0x8009CDC0: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x8009CDC4: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x8009CDC8: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
L_8009CDCC:
    // 0x8009CDCC: lh          $a2, 0x28($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X28);
    // 0x8009CDD0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8009CDD4: blez        $a2, L_8009CF38
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8009CDD8: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8009CF38;
    }
    // 0x8009CDD8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8009CDDC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8009CDE0: addiu       $s1, $s1, 0x63A0
    ctx->r17 = ADD32(ctx->r17, 0X63A0);
L_8009CDE4:
    // 0x8009CDE4: lw          $t9, 0x38($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X38);
    // 0x8009CDE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009CDEC: addu        $v0, $t9, $s7
    ctx->r2 = ADD32(ctx->r25, ctx->r23);
    // 0x8009CDF0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8009CDF4: nop

    // 0x8009CDF8: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x8009CDFC: bne         $t3, $zero, L_8009CF28
    if (ctx->r11 != 0) {
        // 0x8009CE00: nop
    
            goto L_8009CF28;
    }
    // 0x8009CE00: nop

    // 0x8009CE04: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x8009CE08: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x8009CE0C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8009CE10: lh          $t4, 0xE($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XE);
    // 0x8009CE14: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x8009CE18: lw          $t6, 0x4($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X4);
    // 0x8009CE1C: lw          $t8, 0x8($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X8);
    // 0x8009CE20: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x8009CE24: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8009CE28: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8009CE2C: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x8009CE30: subu        $s0, $t4, $v1
    ctx->r16 = SUB32(ctx->r12, ctx->r3);
    // 0x8009CE34: subu        $s2, $t5, $a0
    ctx->r18 = SUB32(ctx->r13, ctx->r4);
    // 0x8009CE38: addu        $fp, $t6, $t7
    ctx->r30 = ADD32(ctx->r14, ctx->r15);
    // 0x8009CE3C: bne         $a1, $at, L_8009CE54
    if (ctx->r5 != ctx->r1) {
        // 0x8009CE40: addu        $t0, $t8, $t9
        ctx->r8 = ADD32(ctx->r24, ctx->r25);
            goto L_8009CE54;
    }
    // 0x8009CE40: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8009CE44: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009CE48: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8009CE4C: b           L_8009CE74
    // 0x8009CE50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8009CE74;
    // 0x8009CE50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8009CE54:
    // 0x8009CE54: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x8009CE58: lbu         $a3, 0x7($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X7);
    // 0x8009CE5C: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8009CE60: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8009CE64: sll         $t5, $a3, 14
    ctx->r13 = S32(ctx->r7 << 14);
    // 0x8009CE68: lw          $s3, 0x0($t4)
    ctx->r19 = MEM_W(ctx->r12, 0X0);
    // 0x8009CE6C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8009CE70: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
L_8009CE74:
    // 0x8009CE74: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8009CE78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009CE7C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8009CE80: jal         0x8007B4E8
    // 0x8009CE84: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    material_set(rdram, ctx);
        goto after_0;
    // 0x8009CE84: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_0:
    // 0x8009CE88: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8009CE8C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8009CE90: addu        $a0, $fp, $t1
    ctx->r4 = ADD32(ctx->r30, ctx->r9);
    // 0x8009CE94: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8009CE98: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CE9C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8009CEA0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8009CEA4: andi        $t9, $a0, 0x6
    ctx->r25 = ctx->r4 & 0X6;
    // 0x8009CEA8: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x8009CEAC: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x8009CEB0: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8009CEB4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009CEB8: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8009CEBC: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8009CEC0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8009CEC4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8009CEC8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8009CECC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8009CED0: andi        $t2, $t9, 0xFFFF
    ctx->r10 = ctx->r25 & 0XFFFF;
    // 0x8009CED4: or          $t3, $t5, $t2
    ctx->r11 = ctx->r13 | ctx->r10;
    // 0x8009CED8: addiu       $t6, $s2, -0x1
    ctx->r14 = ADD32(ctx->r18, -0X1);
    // 0x8009CEDC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8009CEE0: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8009CEE4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEE8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8009CEEC: or          $t8, $t7, $s4
    ctx->r24 = ctx->r15 | ctx->r20;
    // 0x8009CEF0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8009CEF4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8009CEF8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8009CEFC: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x8009CF00: sll         $t3, $s2, 4
    ctx->r11 = S32(ctx->r18 << 4);
    // 0x8009CF04: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8009CF08: or          $t2, $t5, $at
    ctx->r10 = ctx->r13 | ctx->r1;
    // 0x8009CF0C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8009CF10: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x8009CF14: addu        $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x8009CF18: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CF1C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009CF20: lh          $a2, 0x28($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X28);
    // 0x8009CF24: nop

L_8009CF28:
    // 0x8009CF28: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8009CF2C: slt         $at, $s6, $a2
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8009CF30: bne         $at, $zero, L_8009CDE4
    if (ctx->r1 != 0) {
        // 0x8009CF34: addiu       $s7, $s7, 0xC
        ctx->r23 = ADD32(ctx->r23, 0XC);
            goto L_8009CDE4;
    }
    // 0x8009CF34: addiu       $s7, $s7, 0xC
    ctx->r23 = ADD32(ctx->r23, 0XC);
L_8009CF38:
    // 0x8009CF38: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8009CF3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009CF40: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CF44: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009CF48: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8009CF4C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8009CF50: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8009CF54: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8009CF58: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8009CF5C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8009CF60: jr          $ra
    // 0x8009CF64: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8009CF64: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void set_current_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C31EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C31F0: lb          $t6, 0x3670($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3670);
    // 0x800C31F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C31F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C31FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C3200: beq         $t6, $zero, L_800C33E4
    if (ctx->r14 == 0) {
        // 0x800C3204: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800C33E4;
    }
    // 0x800C3204: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3208: bltz        $a0, L_800C33E4
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C320C: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800C33E4;
    }
    // 0x800C320C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C3210: lh          $t7, -0x5870($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X5870);
    // 0x800C3214: nop

    // 0x800C3218: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C321C: beq         $at, $zero, L_800C33E8
    if (ctx->r1 == 0) {
        // 0x800C3220: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800C33E8;
    }
    // 0x800C3220: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C3224: jal         0x8009EB20
    // 0x800C3228: nop

    get_language(rdram, ctx);
        goto after_0;
    // 0x800C3228: nop

    after_0:
    // 0x800C322C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3230: beq         $v0, $at, L_800C3254
    if (ctx->r2 == ctx->r1) {
        // 0x800C3234: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800C3254;
    }
    // 0x800C3234: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800C3238: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C323C: beq         $v0, $at, L_800C325C
    if (ctx->r2 == ctx->r1) {
        // 0x800C3240: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800C325C;
    }
    // 0x800C3240: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C3244: beq         $v0, $at, L_800C3264
    if (ctx->r2 == ctx->r1) {
        // 0x800C3248: nop
    
            goto L_800C3264;
    }
    // 0x800C3248: nop

    // 0x800C324C: b           L_800C326C
    // 0x800C3250: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
        goto L_800C326C;
    // 0x800C3250: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
L_800C3254:
    // 0x800C3254: b           L_800C3268
    // 0x800C3258: addiu       $s0, $s0, 0x55
    ctx->r16 = ADD32(ctx->r16, 0X55);
        goto L_800C3268;
    // 0x800C3258: addiu       $s0, $s0, 0x55
    ctx->r16 = ADD32(ctx->r16, 0X55);
L_800C325C:
    // 0x800C325C: b           L_800C3268
    // 0x800C3260: addiu       $s0, $s0, 0xAA
    ctx->r16 = ADD32(ctx->r16, 0XAA);
        goto L_800C3268;
    // 0x800C3260: addiu       $s0, $s0, 0xAA
    ctx->r16 = ADD32(ctx->r16, 0XAA);
L_800C3264:
    // 0x800C3264: addiu       $s0, $s0, 0xFF
    ctx->r16 = ADD32(ctx->r16, 0XFF);
L_800C3268:
    // 0x800C3268: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
L_800C326C:
    // 0x800C326C: and         $a2, $s0, $at
    ctx->r6 = ctx->r16 & ctx->r1;
    // 0x800C3270: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C3274: lw          $a1, -0x5880($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5880);
    // 0x800C3278: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800C327C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C3280: jal         0x80076E68
    // 0x800C3284: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    asset_load(rdram, ctx);
        goto after_1;
    // 0x800C3284: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_1:
    // 0x800C3288: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C328C: lw          $a0, -0x5880($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5880);
    // 0x800C3290: andi        $t9, $s0, 0x1
    ctx->r25 = ctx->r16 & 0X1;
    // 0x800C3294: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800C3298: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
    // 0x800C329C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800C32A0: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800C32A4: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x800C32A8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800C32AC: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800C32B0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800C32B4: and         $t5, $t0, $a1
    ctx->r13 = ctx->r8 & ctx->r5;
    // 0x800C32B8: and         $t4, $t3, $a1
    ctx->r12 = ctx->r11 & ctx->r5;
    // 0x800C32BC: beq         $t1, $zero, L_800C3324
    if (ctx->r9 == 0) {
        // 0x800C32C0: subu        $a3, $t4, $t5
        ctx->r7 = SUB32(ctx->r12, ctx->r13);
            goto L_800C3324;
    }
    // 0x800C32C0: subu        $a3, $t4, $t5
    ctx->r7 = SUB32(ctx->r12, ctx->r13);
    // 0x800C32C4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C32C8: addiu       $s0, $s0, -0x582C
    ctx->r16 = ADD32(ctx->r16, -0X582C);
    // 0x800C32CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800C32D0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C32D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C32D8: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800C32DC: lw          $a1, -0x5838($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5838);
    // 0x800C32E0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C32E4: jal         0x80076E68
    // 0x800C32E8: xor         $a2, $t0, $t1
    ctx->r6 = ctx->r8 ^ ctx->r9;
    asset_load(rdram, ctx);
        goto after_2;
    // 0x800C32E8: xor         $a2, $t0, $t1
    ctx->r6 = ctx->r8 ^ ctx->r9;
    after_2:
    // 0x800C32EC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800C32F0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C32F4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C32F8: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800C32FC: lw          $t2, -0x5838($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5838);
    // 0x800C3300: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3304: jal         0x800C2D6C
    // 0x800C3308: sw          $t2, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r10;
    find_next_subtitle(rdram, ctx);
        goto after_3;
    // 0x800C3308: sw          $t2, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r10;
    after_3:
    // 0x800C330C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800C3310: nop

    // 0x800C3314: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800C3318: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800C331C: b           L_800C33F0
    // 0x800C3320: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_800C33F0;
    // 0x800C3320: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_800C3324:
    // 0x800C3324: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3328: addiu       $s0, $s0, -0x585C
    ctx->r16 = ADD32(ctx->r16, -0X585C);
    // 0x800C332C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800C3330: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C3334: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C3338: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800C333C: lw          $a1, -0x5868($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5868);
    // 0x800C3340: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C3344: xor         $a2, $t0, $t1
    ctx->r6 = ctx->r8 ^ ctx->r9;
    // 0x800C3348: jal         0x80076E68
    // 0x800C334C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    asset_load(rdram, ctx);
        goto after_4;
    // 0x800C334C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_4:
    // 0x800C3350: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800C3354: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C3358: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800C335C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C3360: lw          $t9, -0x5868($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5868);
    // 0x800C3364: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3368: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800C336C: addiu       $a0, $a0, -0x5860
    ctx->r4 = ADD32(ctx->r4, -0X5860);
    // 0x800C3370: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800C3374: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800C3378: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C337C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C3380: sb          $zero, -0x5878($at)
    MEM_B(-0X5878, ctx->r1) = 0;
    // 0x800C3384: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3388: sb          $zero, -0x587A($at)
    MEM_B(-0X587A, ctx->r1) = 0;
    // 0x800C338C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3390: sb          $zero, -0x587C($at)
    MEM_B(-0X587C, ctx->r1) = 0;
    // 0x800C3394: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3398: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800C339C: sb          $t4, -0x5879($at)
    MEM_B(-0X5879, ctx->r1) = ctx->r12;
    // 0x800C33A0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800C33A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C33A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C33AC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800C33B0: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800C33B4: addiu       $a1, $a1, -0x5877
    ctx->r5 = ADD32(ctx->r5, -0X5877);
    // 0x800C33B8: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x800C33BC: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800C33C0: nop

    // 0x800C33C4: bne         $t8, $zero, L_800C33F0
    if (ctx->r24 != 0) {
        // 0x800C33C8: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800C33F0;
    }
    // 0x800C33C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C33CC: sh          $zero, -0x5872($at)
    MEM_H(-0X5872, ctx->r1) = 0;
    // 0x800C33D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C33D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C33D8: sb          $v0, -0x5876($at)
    MEM_B(-0X5876, ctx->r1) = ctx->r2;
    // 0x800C33DC: b           L_800C33F0
    // 0x800C33E0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_800C33F0;
    // 0x800C33E0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_800C33E4:
    // 0x800C33E4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800C33E8:
    // 0x800C33E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C33EC: sb          $t9, -0x587C($at)
    MEM_B(-0X587C, ctx->r1) = ctx->r25;
L_800C33F0:
    // 0x800C33F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C33F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C33F8: jr          $ra
    // 0x800C33FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C33FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void process_object_interactions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800155B8: addiu       $sp, $sp, -0x490
    ctx->r29 = ADD32(ctx->r29, -0X490);
    // 0x800155BC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800155C0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800155C4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800155C8: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x800155CC: lw          $s3, -0x51A0($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X51A0);
    // 0x800155D0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800155D4: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800155D8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800155DC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800155E0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800155E4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800155E8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800155EC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800155F0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800155F4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800155F8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800155FC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80015600: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80015604: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80015608: beq         $at, $zero, L_800156A4
    if (ctx->r1 == 0) {
        // 0x8001560C: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800156A4;
    }
    // 0x8001560C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80015610: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80015614: addiu       $a0, $a0, -0x51A8
    ctx->r4 = ADD32(ctx->r4, -0X51A8);
    // 0x80015618: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x8001561C: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80015620: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x80015624: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80015628: addiu       $a1, $zero, -0x49
    ctx->r5 = ADD32(0, -0X49);
L_8001562C:
    // 0x8001562C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80015630: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80015634: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80015638: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x8001563C: nop

    // 0x80015640: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x80015644: nop

    // 0x80015648: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001564C: bne         $t9, $zero, L_8001569C
    if (ctx->r25 != 0) {
        // 0x80015650: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001569C;
    }
    // 0x80015650: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80015654: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015658: sll         $t0, $s5, 2
    ctx->r8 = S32(ctx->r21 << 2);
    // 0x8001565C: beq         $s2, $zero, L_80015698
    if (ctx->r18 == 0) {
        // 0x80015660: addu        $t1, $s6, $t0
        ctx->r9 = ADD32(ctx->r22, ctx->r8);
            goto L_80015698;
    }
    // 0x80015660: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x80015664: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x80015668: lbu         $t2, 0x11($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X11);
    // 0x8001566C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80015670: beq         $fp, $t2, L_8001569C
    if (ctx->r30 == ctx->r10) {
        // 0x80015674: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001569C;
    }
    // 0x80015674: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80015678: lh          $t3, 0x14($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X14);
    // 0x8001567C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x80015680: and         $t4, $t3, $a1
    ctx->r12 = ctx->r11 & ctx->r5;
    // 0x80015684: sh          $t4, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r12;
    // 0x80015688: sb          $a2, 0x13($s2)
    MEM_B(0X13, ctx->r18) = ctx->r6;
    // 0x8001568C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80015690: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x80015694: nop

L_80015698:
    // 0x80015698: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
L_8001569C:
    // 0x8001569C: bne         $at, $zero, L_8001562C
    if (ctx->r1 != 0) {
        // 0x800156A0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8001562C;
    }
    // 0x800156A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800156A4:
    // 0x800156A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800156A8: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x800156AC: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x800156B0: sw          $zero, -0x5190($at)
    MEM_W(-0X5190, ctx->r1) = 0;
    // 0x800156B4: blez        $s5, L_80015864
    if (SIGNED(ctx->r21) <= 0) {
        // 0x800156B8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80015864;
    }
    // 0x800156B8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800156BC: lui         $at, 0x4880
    ctx->r1 = S32(0X4880 << 16);
    // 0x800156C0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800156C4: lui         $at, 0x4A80
    ctx->r1 = S32(0X4A80 << 16);
    // 0x800156C8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800156CC: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x800156D0: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_800156D4:
    // 0x800156D4: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800156D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800156DC: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x800156E0: nop

    // 0x800156E4: lbu         $t5, 0x11($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X11);
    // 0x800156E8: nop

    // 0x800156EC: bne         $fp, $t5, L_80015728
    if (ctx->r30 != ctx->r13) {
        // 0x800156F0: nop
    
            goto L_80015728;
    }
    // 0x800156F0: nop

    // 0x800156F4: lw          $v0, -0x5190($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5190);
    // 0x800156F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800156FC: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80015700: beq         $at, $zero, L_80015728
    if (ctx->r1 == 0) {
        // 0x80015704: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80015728;
    }
    // 0x80015704: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80015708: lw          $t6, -0x5194($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5194);
    // 0x8001570C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80015710: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80015714: sw          $s1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r17;
    // 0x80015718: lw          $t9, -0x5190($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5190);
    // 0x8001571C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80015720: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80015724: sw          $t0, -0x5190($at)
    MEM_W(-0X5190, ctx->r1) = ctx->r8;
L_80015728:
    // 0x80015728: lh          $v0, 0x14($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X14);
    // 0x8001572C: nop

    // 0x80015730: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x80015734: beq         $t1, $zero, L_80015804
    if (ctx->r9 == 0) {
        // 0x80015738: andi        $t6, $v0, 0x100
        ctx->r14 = ctx->r2 & 0X100;
            goto L_80015804;
    }
    // 0x80015738: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x8001573C: blez        $s5, L_80015800
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80015740: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80015800;
    }
    // 0x80015740: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80015744:
    // 0x80015744: beq         $s3, $s0, L_800157EC
    if (ctx->r19 == ctx->r16) {
        // 0x80015748: sll         $t2, $s0, 2
        ctx->r10 = S32(ctx->r16 << 2);
            goto L_800157EC;
    }
    // 0x80015748: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8001574C: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x80015750: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80015754: nop

    // 0x80015758: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8001575C: nop

    // 0x80015760: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // 0x80015764: nop

    // 0x80015768: andi        $t4, $v1, 0x3
    ctx->r12 = ctx->r3 & 0X3;
    // 0x8001576C: beq         $t4, $zero, L_800157EC
    if (ctx->r12 == 0) {
        // 0x80015770: nop
    
            goto L_800157EC;
    }
    // 0x80015770: nop

    // 0x80015774: lbu         $a0, 0x11($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X11);
    // 0x80015778: nop

    // 0x8001577C: bne         $s4, $a0, L_80015794
    if (ctx->r20 != ctx->r4) {
        // 0x80015780: nop
    
            goto L_80015794;
    }
    // 0x80015780: nop

    // 0x80015784: jal         0x80016748
    // 0x80015788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80016748(rdram, ctx);
        goto after_0;
    // 0x80015788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8001578C: b           L_800157F0
    // 0x80015790: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800157F0;
    // 0x80015790: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80015794:
    // 0x80015794: beq         $fp, $a0, L_800157EC
    if (ctx->r30 == ctx->r4) {
        // 0x80015798: andi        $t5, $v1, 0x20
        ctx->r13 = ctx->r3 & 0X20;
            goto L_800157EC;
    }
    // 0x80015798: andi        $t5, $v1, 0x20
    ctx->r13 = ctx->r3 & 0X20;
    // 0x8001579C: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800157A0: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800157A4: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800157A8: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800157AC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800157B0: beq         $t5, $zero, L_800157C0
    if (ctx->r13 == 0) {
        // 0x800157B4: sub.s       $f2, $f8, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
            goto L_800157C0;
    }
    // 0x800157B4: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800157B8: b           L_800157C4
    // 0x800157BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
        goto L_800157C4;
    // 0x800157BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_800157C0:
    // 0x800157C0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_800157C4:
    // 0x800157C4: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800157C8: nop

    // 0x800157CC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800157D0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800157D4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800157D8: nop

    // 0x800157DC: bc1f        L_800157EC
    if (!c1cs) {
        // 0x800157E0: nop
    
            goto L_800157EC;
    }
    // 0x800157E0: nop

    // 0x800157E4: jal         0x800159C8
    // 0x800157E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800159C8(rdram, ctx);
        goto after_1;
    // 0x800157E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
L_800157EC:
    // 0x800157EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800157F0:
    // 0x800157F0: bne         $s0, $s5, L_80015744
    if (ctx->r16 != ctx->r21) {
        // 0x800157F4: nop
    
            goto L_80015744;
    }
    // 0x800157F4: nop

    // 0x800157F8: lh          $v0, 0x14($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X14);
    // 0x800157FC: nop

L_80015800:
    // 0x80015800: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
L_80015804:
    // 0x80015804: beq         $t6, $zero, L_80015854
    if (ctx->r14 == 0) {
        // 0x80015808: nop
    
            goto L_80015854;
    }
    // 0x80015808: nop

    // 0x8001580C: blez        $s5, L_80015854
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80015810: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80015854;
    }
    // 0x80015810: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80015814:
    // 0x80015814: beq         $s3, $s0, L_80015848
    if (ctx->r19 == ctx->r16) {
        // 0x80015818: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_80015848;
    }
    // 0x80015818: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8001581C: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x80015820: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80015824: nop

    // 0x80015828: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8001582C: nop

    // 0x80015830: lbu         $t9, 0x11($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X11);
    // 0x80015834: nop

    // 0x80015838: bne         $s4, $t9, L_80015848
    if (ctx->r20 != ctx->r25) {
        // 0x8001583C: nop
    
            goto L_80015848;
    }
    // 0x8001583C: nop

    // 0x80015840: jal         0x80016748
    // 0x80015844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80016748(rdram, ctx);
        goto after_2;
    // 0x80015844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_80015848:
    // 0x80015848: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001584C: bne         $s0, $s5, L_80015814
    if (ctx->r16 != ctx->r21) {
        // 0x80015850: nop
    
            goto L_80015814;
    }
    // 0x80015850: nop

L_80015854:
    // 0x80015854: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80015858: bne         $s3, $s5, L_800156D4
    if (ctx->r19 != ctx->r21) {
        // 0x8001585C: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_800156D4;
    }
    // 0x8001585C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80015860: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80015864:
    // 0x80015864: blez        $s5, L_80015988
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80015868: andi        $v1, $s5, 0x3
        ctx->r3 = ctx->r21 & 0X3;
            goto L_80015988;
    }
    // 0x80015868: andi        $v1, $s5, 0x3
    ctx->r3 = ctx->r21 & 0X3;
    // 0x8001586C: beq         $v1, $zero, L_800158B4
    if (ctx->r3 == 0) {
        // 0x80015870: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800158B4;
    }
    // 0x80015870: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015874: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x80015878: addiu       $t1, $sp, 0x64
    ctx->r9 = ADD32(ctx->r29, 0X64);
    // 0x8001587C: addu        $s7, $t0, $t1
    ctx->r23 = ADD32(ctx->r8, ctx->r9);
L_80015880:
    // 0x80015880: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x80015884: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80015888: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x8001588C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015890: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80015894: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80015898: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8001589C: nop

    // 0x800158A0: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x800158A4: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800158A8: bne         $v0, $s3, L_80015880
    if (ctx->r2 != ctx->r19) {
        // 0x800158AC: swc1        $f10, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
            goto L_80015880;
    }
    // 0x800158AC: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
    // 0x800158B0: beq         $s3, $s5, L_80015988
    if (ctx->r19 == ctx->r21) {
        // 0x800158B4: addiu       $t3, $sp, 0x64
        ctx->r11 = ADD32(ctx->r29, 0X64);
            goto L_80015988;
    }
L_800158B4:
    // 0x800158B4: addiu       $t3, $sp, 0x64
    ctx->r11 = ADD32(ctx->r29, 0X64);
    // 0x800158B8: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x800158BC: sll         $t4, $s5, 2
    ctx->r12 = S32(ctx->r21 << 2);
    // 0x800158C0: addu        $v0, $t4, $t3
    ctx->r2 = ADD32(ctx->r12, ctx->r11);
    // 0x800158C4: addu        $s7, $t2, $t3
    ctx->r23 = ADD32(ctx->r10, ctx->r11);
L_800158C8:
    // 0x800158C8: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800158CC: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // 0x800158D0: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x800158D4: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800158D8: nop

    // 0x800158DC: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x800158E0: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800158E4: nop

    // 0x800158E8: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
    // 0x800158EC: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800158F0: nop

    // 0x800158F4: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x800158F8: lw          $s1, -0xC($s7)
    ctx->r17 = MEM_W(ctx->r23, -0XC);
    // 0x800158FC: nop

    // 0x80015900: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015904: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015908: nop

    // 0x8001590C: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80015910: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80015914: nop

    // 0x80015918: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x8001591C: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80015920: nop

    // 0x80015924: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
    // 0x80015928: lw          $s1, -0x8($s7)
    ctx->r17 = MEM_W(ctx->r23, -0X8);
    // 0x8001592C: nop

    // 0x80015930: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015934: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015938: nop

    // 0x8001593C: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x80015940: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80015944: nop

    // 0x80015948: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
    // 0x8001594C: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80015950: nop

    // 0x80015954: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x80015958: lw          $s1, -0x4($s7)
    ctx->r17 = MEM_W(ctx->r23, -0X4);
    // 0x8001595C: nop

    // 0x80015960: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015964: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015968: nop

    // 0x8001596C: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80015970: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80015974: nop

    // 0x80015978: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x8001597C: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80015980: bne         $s7, $v0, L_800158C8
    if (ctx->r23 != ctx->r2) {
        // 0x80015984: swc1        $f10, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
            goto L_800158C8;
    }
    // 0x80015984: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
L_80015988:
    // 0x80015988: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8001598C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80015990: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80015994: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80015998: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001599C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800159A0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800159A4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800159A8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800159AC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800159B0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800159B4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800159B8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800159BC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800159C0: jr          $ra
    // 0x800159C4: addiu       $sp, $sp, 0x490
    ctx->r29 = ADD32(ctx->r29, 0X490);
    return;
    // 0x800159C4: addiu       $sp, $sp, 0x490
    ctx->r29 = ADD32(ctx->r29, 0X490);
;}
RECOMP_FUNC void music_jingle_voicelimit_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000C40: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80000C44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000C48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000C4C: lw          $a0, -0x39CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39CC);
    // 0x80000C50: jal         0x8000B010
    // 0x80000C54: nop

    set_voice_limit(rdram, ctx);
        goto after_0;
    // 0x80000C54: nop

    after_0:
    // 0x80000C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000C60: jr          $ra
    // 0x80000C64: nop

    return;
    // 0x80000C64: nop

;}
RECOMP_FUNC void titlescreen_controller_assign(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AF00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008AF04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008AF08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AF0C: addiu       $a1, $t6, 0x63E8
    ctx->r5 = ADD32(ctx->r14, 0X63E8);
    // 0x8008AF10: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008AF14: sw          $a2, -0xB44($at)
    MEM_W(-0XB44, ctx->r1) = ctx->r6;
    // 0x8008AF18: addiu       $v0, $v0, 0x63F0
    ctx->r2 = ADD32(ctx->r2, 0X63F0);
    // 0x8008AF1C: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x8008AF20: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8008AF24:
    // 0x8008AF24: bne         $a1, $v1, L_8008AF34
    if (ctx->r5 != ctx->r3) {
        // 0x8008AF28: nop
    
            goto L_8008AF34;
    }
    // 0x8008AF28: nop

    // 0x8008AF2C: b           L_8008AF38
    // 0x8008AF30: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
        goto L_8008AF38;
    // 0x8008AF30: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
L_8008AF34:
    // 0x8008AF34: sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
L_8008AF38:
    // 0x8008AF38: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008AF3C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8008AF40: bne         $at, $zero, L_8008AF24
    if (ctx->r1 != 0) {
        // 0x8008AF44: nop
    
            goto L_8008AF24;
    }
    // 0x8008AF44: nop

    // 0x8008AF48: bne         $a0, $zero, L_8008AF60
    if (ctx->r4 != 0) {
        // 0x8008AF4C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008AF60;
    }
    // 0x8008AF4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AF50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008AF54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AF58: b           L_8008AF64
    // 0x8008AF5C: sb          $t7, 0x63D4($at)
    MEM_B(0X63D4, ctx->r1) = ctx->r15;
        goto L_8008AF64;
    // 0x8008AF5C: sb          $t7, 0x63D4($at)
    MEM_B(0X63D4, ctx->r1) = ctx->r15;
L_8008AF60:
    // 0x8008AF60: sb          $zero, 0x63D4($at)
    MEM_B(0X63D4, ctx->r1) = 0;
L_8008AF64:
    // 0x8008AF64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008AF68: bne         $a0, $at, L_8008AF7C
    if (ctx->r4 != ctx->r1) {
        // 0x8008AF6C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008AF7C;
    }
    // 0x8008AF6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008AF70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AF74: b           L_8008AF84
    // 0x8008AF78: sb          $t8, 0x63D5($at)
    MEM_B(0X63D5, ctx->r1) = ctx->r24;
        goto L_8008AF84;
    // 0x8008AF78: sb          $t8, 0x63D5($at)
    MEM_B(0X63D5, ctx->r1) = ctx->r24;
L_8008AF7C:
    // 0x8008AF7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AF80: sb          $zero, 0x63D5($at)
    MEM_B(0X63D5, ctx->r1) = 0;
L_8008AF84:
    // 0x8008AF84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008AF88: bne         $a0, $at, L_8008AF9C
    if (ctx->r4 != ctx->r1) {
        // 0x8008AF8C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008AF9C;
    }
    // 0x8008AF8C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008AF90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AF94: b           L_8008AFA4
    // 0x8008AF98: sb          $t9, 0x63D6($at)
    MEM_B(0X63D6, ctx->r1) = ctx->r25;
        goto L_8008AFA4;
    // 0x8008AF98: sb          $t9, 0x63D6($at)
    MEM_B(0X63D6, ctx->r1) = ctx->r25;
L_8008AF9C:
    // 0x8008AF9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AFA0: sb          $zero, 0x63D6($at)
    MEM_B(0X63D6, ctx->r1) = 0;
L_8008AFA4:
    // 0x8008AFA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008AFA8: bne         $a0, $at, L_8008AFBC
    if (ctx->r4 != ctx->r1) {
        // 0x8008AFAC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8008AFBC;
    }
    // 0x8008AFAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008AFB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AFB4: jr          $ra
    // 0x8008AFB8: sb          $t0, 0x63D7($at)
    MEM_B(0X63D7, ctx->r1) = ctx->r8;
    return;
    // 0x8008AFB8: sb          $t0, 0x63D7($at)
    MEM_B(0X63D7, ctx->r1) = ctx->r8;
L_8008AFBC:
    // 0x8008AFBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AFC0: sb          $zero, 0x63D7($at)
    MEM_B(0X63D7, ctx->r1) = 0;
    // 0x8008AFC4: jr          $ra
    // 0x8008AFC8: nop

    return;
    // 0x8008AFC8: nop

;}
RECOMP_FUNC void input_clamp_stick_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A5E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A5E4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A5E8: lbu         $t6, 0x1150($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1150);
    // 0x8006A5EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A5F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006A5F4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006A5F8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006A5FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A600: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8006A604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A608: lb          $a0, 0x1113($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X1113);
    // 0x8006A60C: jal         0x8006A624
    // 0x8006A610: nop

    input_clamp_stick_mag(rdram, ctx);
        goto after_0;
    // 0x8006A610: nop

    after_0:
    // 0x8006A614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A61C: jr          $ra
    // 0x8006A620: nop

    return;
    // 0x8006A620: nop

;}
RECOMP_FUNC void menu_assetgroup_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C4A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009C4AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009C4B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009C4B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009C4B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009C4BC: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8009C4C0: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009C4C4: beq         $s2, $t6, L_8009C4F4
    if (ctx->r18 == ctx->r14) {
        // 0x8009C4C8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009C4F4;
    }
    // 0x8009C4C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009C4CC: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8009C4D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009C4D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009C4D8:
    // 0x8009C4D8: jal         0x8009C508
    // 0x8009C4DC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    menu_asset_free(rdram, ctx);
        goto after_0;
    // 0x8009C4DC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x8009C4E0: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x8009C4E4: nop

    // 0x8009C4E8: bne         $s2, $s1, L_8009C4D8
    if (ctx->r18 != ctx->r17) {
        // 0x8009C4EC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009C4D8;
    }
    // 0x8009C4EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009C4F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009C4F4:
    // 0x8009C4F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009C4F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C4FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009C500: jr          $ra
    // 0x8009C504: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009C504: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_log(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040570: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80040574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040578: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004057C: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80040580: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80040584: beq         $a3, $zero, L_800405A0
    if (ctx->r7 == 0) {
        // 0x80040588: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800405A0;
    }
    // 0x80040588: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8004058C: jal         0x800BEEB4
    // 0x80040590: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    obj_wave_height(rdram, ctx);
        goto after_0;
    // 0x80040590: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80040594: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80040598: b           L_800405C0
    // 0x8004059C: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
        goto L_800405C0;
    // 0x8004059C: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
L_800405A0:
    // 0x800405A0: lw          $t6, 0x3C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X3C);
    // 0x800405A4: nop

    // 0x800405A8: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x800405AC: nop

    // 0x800405B0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800405B4: nop

    // 0x800405B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800405BC: swc1        $f6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
L_800405C0:
    // 0x800405C0: lw          $v0, 0x5C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X5C);
    // 0x800405C4: nop

    // 0x800405C8: lw          $t8, 0x100($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X100);
    // 0x800405CC: nop

    // 0x800405D0: beq         $t8, $zero, L_80040748
    if (ctx->r24 == 0) {
        // 0x800405D4: nop
    
            goto L_80040748;
    }
    // 0x800405D4: nop

    // 0x800405D8: lw          $t9, 0x7C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X7C);
    // 0x800405DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800405E0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800405E4: sw          $t0, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r8;
    // 0x800405E8: lw          $v1, 0x100($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X100);
    // 0x800405EC: nop

    // 0x800405F0: lh          $t1, 0x48($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X48);
    // 0x800405F4: nop

    // 0x800405F8: bne         $t1, $at, L_80040654
    if (ctx->r9 != ctx->r1) {
        // 0x800405FC: nop
    
            goto L_80040654;
    }
    // 0x800405FC: nop

    // 0x80040600: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x80040604: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x80040608: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8004060C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80040610: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80040614: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80040618: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8004061C: nop

    // 0x80040620: bc1f        L_80040654
    if (!c1cs) {
        // 0x80040624: nop
    
            goto L_80040654;
    }
    // 0x80040624: nop

    // 0x80040628: lb          $t2, 0x1D8($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1D8);
    // 0x8004062C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80040630: bne         $t2, $zero, L_80040654
    if (ctx->r10 != 0) {
        // 0x80040634: nop
    
            goto L_80040654;
    }
    // 0x80040634: nop

    // 0x80040638: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8004063C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80040640: jal         0x80072348
    // 0x80040644: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    rumble_set(rdram, ctx);
        goto after_1;
    // 0x80040644: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80040648: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8004064C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80040650: nop

L_80040654:
    // 0x80040654: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80040658: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004065C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80040660: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x80040664: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80040668: jal         0x800707C4
    // 0x8004066C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x8004066C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80040670: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80040674: nop

    // 0x80040678: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8004067C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80040680: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80040684: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x80040688: jal         0x800707F8
    // 0x8004068C: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    coss_f(rdram, ctx);
        goto after_3;
    // 0x8004068C: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_3:
    // 0x80040690: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80040694: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80040698: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8004069C: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800406A0: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800406A4: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800406A8: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800406AC: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800406B0: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800406B4: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800406B8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800406BC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800406C0: lwc1        $f6, 0x24($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X24);
    // 0x800406C4: mul.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800406C8: lw          $t7, 0x78($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X78);
    // 0x800406CC: addiu       $t2, $zero, -0x200
    ctx->r10 = ADD32(0, -0X200);
    // 0x800406D0: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800406D4: add.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800406D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800406DC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800406E0: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800406E4: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800406E8: nop

    // 0x800406EC: div.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800406F0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800406F4: nop

    // 0x800406F8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800406FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80040700: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80040704: nop

    // 0x80040708: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8004070C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80040710: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80040714: subu        $v0, $t7, $t9
    ctx->r2 = SUB32(ctx->r15, ctx->r25);
    // 0x80040718: slti        $at, $v0, 0x201
    ctx->r1 = SIGNED(ctx->r2) < 0X201 ? 1 : 0;
    // 0x8004071C: bne         $at, $zero, L_8004072C
    if (ctx->r1 != 0) {
        // 0x80040720: sw          $v0, 0x78($a2)
        MEM_W(0X78, ctx->r6) = ctx->r2;
            goto L_8004072C;
    }
    // 0x80040720: sw          $v0, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r2;
    // 0x80040724: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x80040728: sw          $v0, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r2;
L_8004072C:
    // 0x8004072C: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
    // 0x80040730: beq         $at, $zero, L_8004073C
    if (ctx->r1 == 0) {
        // 0x80040734: nop
    
            goto L_8004073C;
    }
    // 0x80040734: nop

    // 0x80040738: sw          $t2, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r10;
L_8004073C:
    // 0x8004073C: lw          $v1, 0x7C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X7C);
    // 0x80040740: b           L_80040764
    // 0x80040744: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
        goto L_80040764;
    // 0x80040744: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
L_80040748:
    // 0x80040748: lw          $v1, 0x7C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X7C);
    // 0x8004074C: nop

    // 0x80040750: blez        $v1, L_80040760
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80040754: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_80040760;
    }
    // 0x80040754: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80040758: sw          $t3, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r11;
    // 0x8004075C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_80040760:
    // 0x80040760: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
L_80040764:
    // 0x80040764: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80040768: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004076C: lw          $v0, 0x78($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X78);
    // 0x80040770: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80040774: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80040778: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x8004077C: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80040780: blez        $v0, L_800407A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80040784: swc1        $f6, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
            goto L_800407A8;
    }
    // 0x80040784: swc1        $f6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
    // 0x80040788: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8004078C: nop

    // 0x80040790: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x80040794: sw          $t5, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r13;
    // 0x80040798: bgez        $t5, L_800407A8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8004079C: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_800407A8;
    }
    // 0x8004079C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800407A0: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x800407A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800407A8:
    // 0x800407A8: bgez        $v0, L_800407D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800407AC: lw          $t9, 0x2C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X2C);
            goto L_800407D4;
    }
    // 0x800407AC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800407B0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800407B4: nop

    // 0x800407B8: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x800407BC: sw          $t8, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r24;
    // 0x800407C0: blez        $t8, L_800407D0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800407C4: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800407D0;
    }
    // 0x800407C4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800407C8: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x800407CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800407D0:
    // 0x800407D0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
L_800407D4:
    // 0x800407D4: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x800407D8: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800407DC: lw          $t2, 0x5C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X5C);
    // 0x800407E0: mflo        $t0
    ctx->r8 = lo;
    // 0x800407E4: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x800407E8: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    // 0x800407EC: sw          $zero, 0x100($t2)
    MEM_W(0X100, ctx->r10) = 0;
    // 0x800407F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800407F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800407F8: jr          $ra
    // 0x800407FC: nop

    return;
    // 0x800407FC: nop

;}
RECOMP_FUNC void audspat_point_create(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000974C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80009750: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80009754: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80009758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000975C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80009760: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80009764: beq         $a1, $zero, L_8000978C
    if (ctx->r5 == 0) {
        // 0x80009768: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8000978C;
    }
    // 0x80009768: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8000976C: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x80009770: nop

    // 0x80009774: ori         $t6, $a0, 0xE000
    ctx->r14 = ctx->r4 | 0XE000;
    // 0x80009778: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8000977C: jal         0x800245B4
    // 0x80009780: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x80009780: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_0:
    // 0x80009784: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80009788: nop

L_8000978C:
    // 0x8000978C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80009790: addiu       $a0, $a0, -0x3920
    ctx->r4 = ADD32(ctx->r4, -0X3920);
    // 0x80009794: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80009798: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8000979C: bne         $t9, $at, L_800097C0
    if (ctx->r25 != ctx->r1) {
        // 0x800097A0: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800097C0;
    }
    // 0x800097A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800097A4: beq         $a1, $zero, L_800097B0
    if (ctx->r5 == 0) {
        // 0x800097A8: nop
    
            goto L_800097B0;
    }
    // 0x800097A8: nop

    // 0x800097AC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800097B0:
    // 0x800097B0: jal         0x800245B4
    // 0x800097B4: addiu       $a0, $zero, -0x55AB
    ctx->r4 = ADD32(0, -0X55AB);
    func_800245B4(rdram, ctx);
        goto after_1;
    // 0x800097B4: addiu       $a0, $zero, -0x55AB
    ctx->r4 = ADD32(0, -0X55AB);
    after_1:
    // 0x800097B8: b           L_80009898
    // 0x800097BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80009898;
    // 0x800097BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800097C0:
    // 0x800097C0: addiu       $a2, $a2, -0x63B4
    ctx->r6 = ADD32(ctx->r6, -0X63B4);
    // 0x800097C4: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x800097C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800097CC: lw          $t0, -0x63B0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63B0);
    // 0x800097D0: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800097D4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800097D8: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800097DC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800097E0: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x800097E4: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x800097E8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800097EC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800097F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800097F4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x800097F8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800097FC: nop

    // 0x80009800: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80009804: lhu         $t4, 0x1A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X1A);
    // 0x80009808: nop

    // 0x8000980C: sh          $t4, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r12;
    // 0x80009810: lbu         $t5, 0x2B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2B);
    // 0x80009814: nop

    // 0x80009818: sb          $t5, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r13;
    // 0x8000981C: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x80009820: nop

    // 0x80009824: sb          $t6, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r14;
    // 0x80009828: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x8000982C: nop

    // 0x80009830: sb          $t7, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r15;
    // 0x80009834: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x80009838: nop

    // 0x8000983C: sb          $t8, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r24;
    // 0x80009840: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80009844: nop

    // 0x80009848: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x8000984C: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x80009850: nop

    // 0x80009854: sb          $t0, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r8;
    // 0x80009858: lbu         $t1, 0x43($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X43);
    // 0x8000985C: sb          $zero, 0x22($v0)
    MEM_B(0X22, ctx->r2) = 0;
    // 0x80009860: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x80009864: sb          $t1, 0x21($v0)
    MEM_B(0X21, ctx->r2) = ctx->r9;
    // 0x80009868: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x8000986C: lw          $t2, -0x63BC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X63BC);
    // 0x80009870: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80009874: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80009878: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8000987C: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80009880: nop

    // 0x80009884: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80009888: beq         $a1, $zero, L_80009894
    if (ctx->r5 == 0) {
        // 0x8000988C: sh          $t7, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r15;
            goto L_80009894;
    }
    // 0x8000988C: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80009890: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80009894:
    // 0x80009894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80009898:
    // 0x80009898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000989C: jr          $ra
    // 0x800098A0: nop

    return;
    // 0x800098A0: nop

;}
RECOMP_FUNC void func_800149C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800149C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800149C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800149C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800149CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800149D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800149D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800149D8: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800149DC: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800149E0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800149E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800149E8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800149EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800149F0: lbu         $a3, 0x4($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X4);
    // 0x800149F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800149F8: jal         0x80014B50
    // 0x800149FC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80014B50(rdram, ctx);
        goto after_0;
    // 0x800149FC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80014A00: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80014A04: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80014A08: lbu         $a3, 0x4($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X4);
    // 0x80014A0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80014A10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80014A14: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80014A18: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80014A1C: jal         0x80014B50
    // 0x80014A20: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80014B50(rdram, ctx);
        goto after_1;
    // 0x80014A20: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_1:
    // 0x80014A24: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80014A28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80014A2C: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80014A30: beq         $at, $zero, L_80014B28
    if (ctx->r1 == 0) {
        // 0x80014A34: subu        $a0, $t3, $v0
        ctx->r4 = SUB32(ctx->r11, ctx->r2);
            goto L_80014B28;
    }
    // 0x80014A34: subu        $a0, $t3, $v0
    ctx->r4 = SUB32(ctx->r11, ctx->r2);
    // 0x80014A38: andi        $t9, $a0, 0x3
    ctx->r25 = ctx->r4 & 0X3;
    // 0x80014A3C: beq         $t9, $zero, L_80014A80
    if (ctx->r25 == 0) {
        // 0x80014A40: addu        $a2, $t9, $v0
        ctx->r6 = ADD32(ctx->r25, ctx->r2);
            goto L_80014A80;
    }
    // 0x80014A40: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x80014A44: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80014A48: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80014A4C: addiu       $t1, $t1, -0x51A8
    ctx->r9 = ADD32(ctx->r9, -0X51A8);
    // 0x80014A50: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_80014A54:
    // 0x80014A54: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80014A58: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80014A5C: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80014A60: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80014A64: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80014A68: lb          $t7, 0x38($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X38);
    // 0x80014A6C: nop

    // 0x80014A70: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x80014A74: bne         $a2, $a1, L_80014A54
    if (ctx->r6 != ctx->r5) {
        // 0x80014A78: sb          $t6, 0x38($a0)
        MEM_B(0X38, ctx->r4) = ctx->r14;
            goto L_80014A54;
    }
    // 0x80014A78: sb          $t6, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r14;
    // 0x80014A7C: beq         $a1, $t3, L_80014B28
    if (ctx->r5 == ctx->r11) {
        // 0x80014A80: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80014B28;
    }
L_80014A80:
    // 0x80014A80: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80014A84: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80014A88: addiu       $t1, $t1, -0x51A8
    ctx->r9 = ADD32(ctx->r9, -0X51A8);
    // 0x80014A8C: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80014A90: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
L_80014A94:
    // 0x80014A94: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80014A98: nop

    // 0x80014A9C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80014AA0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80014AA4: nop

    // 0x80014AA8: lb          $t4, 0x38($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X38);
    // 0x80014AAC: nop

    // 0x80014AB0: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80014AB4: sb          $t5, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r13;
    // 0x80014AB8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80014ABC: nop

    // 0x80014AC0: addu        $t6, $t7, $v1
    ctx->r14 = ADD32(ctx->r15, ctx->r3);
    // 0x80014AC4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x80014AC8: nop

    // 0x80014ACC: lb          $t8, 0x38($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X38);
    // 0x80014AD0: nop

    // 0x80014AD4: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80014AD8: sb          $t9, 0x38($a1)
    MEM_B(0X38, ctx->r5) = ctx->r25;
    // 0x80014ADC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80014AE0: nop

    // 0x80014AE4: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80014AE8: lw          $a2, 0x8($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X8);
    // 0x80014AEC: nop

    // 0x80014AF0: lb          $t7, 0x38($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X38);
    // 0x80014AF4: nop

    // 0x80014AF8: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x80014AFC: sb          $t6, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r14;
    // 0x80014B00: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80014B04: nop

    // 0x80014B08: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80014B0C: lw          $a3, 0xC($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XC);
    // 0x80014B10: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80014B14: lb          $t4, 0x38($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X38);
    // 0x80014B18: nop

    // 0x80014B1C: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80014B20: bne         $v1, $t2, L_80014A94
    if (ctx->r3 != ctx->r10) {
        // 0x80014B24: sb          $t5, 0x38($a3)
        MEM_B(0X38, ctx->r7) = ctx->r13;
            goto L_80014A94;
    }
    // 0x80014B24: sb          $t5, 0x38($a3)
    MEM_B(0X38, ctx->r7) = ctx->r13;
L_80014B28:
    // 0x80014B28: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80014B2C: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x80014B30: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80014B34: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80014B38: nop

    // 0x80014B3C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80014B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014B44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80014B48: jr          $ra
    // 0x80014B4C: nop

    return;
    // 0x80014B4C: nop

;}
RECOMP_FUNC void void_generate_primitive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027184: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80027188: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8002718C: addiu       $a2, $a2, -0x2B48
    ctx->r6 = ADD32(ctx->r6, -0X2B48);
    // 0x80027190: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80027194: lh          $t7, -0x2B44($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2B44);
    // 0x80027198: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x8002719C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800271A0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800271A4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800271A8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800271AC: bne         $at, $zero, L_800271BC
    if (ctx->r1 != 0) {
        // 0x800271B0: sw          $a3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r7;
            goto L_800271BC;
    }
    // 0x800271B0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800271B4: b           L_80027558
    // 0x800271B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80027558;
    // 0x800271B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800271BC:
    // 0x800271BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800271C0: addiu       $v1, $v1, -0x2B4A
    ctx->r3 = ADD32(ctx->r3, -0X2B4A);
    // 0x800271C4: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800271C8: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800271CC: bne         $v0, $at, L_800272B8
    if (ctx->r2 != ctx->r1) {
        // 0x800271D0: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800272B8;
    }
    // 0x800271D0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800271D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800271D8: addiu       $t5, $t5, -0x4F60
    ctx->r13 = ADD32(ctx->r13, -0X4F60);
    // 0x800271DC: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x800271E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800271E4: addiu       $s0, $s0, -0x2B78
    ctx->r16 = ADD32(ctx->r16, -0X2B78);
    // 0x800271E8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800271EC: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x800271F0: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    // 0x800271F4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800271F8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800271FC: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x80027200: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80027204: andi        $t9, $t8, 0x6
    ctx->r25 = ctx->r24 & 0X6;
    // 0x80027208: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8002720C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80027210: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80027214: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80027218: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002721C: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80027220: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80027224: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80027228: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002722C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80027230: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80027234: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80027238: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002723C: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80027240: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x80027244: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80027248: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x8002724C: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x80027250: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80027254: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80027258: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x8002725C: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80027260: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80027264: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x80027268: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x8002726C: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80027270: sll         $t9, $t4, 4
    ctx->r25 = S32(ctx->r12 << 4);
    // 0x80027274: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x80027278: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002727C: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80027280: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80027284: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80027288: lw          $t9, -0x2B68($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2B68);
    // 0x8002728C: addiu       $a3, $a3, -0x4F58
    ctx->r7 = ADD32(ctx->r7, -0X4F58);
    // 0x80027290: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x80027294: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80027298: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002729C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800272A0: addiu       $t0, $t0, -0x4F54
    ctx->r8 = ADD32(ctx->r8, -0X4F54);
    // 0x800272A4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800272A8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800272AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800272B0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800272B4: sw          $t6, -0x2B68($at)
    MEM_W(-0X2B68, ctx->r1) = ctx->r14;
L_800272B8:
    // 0x800272B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800272BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800272C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800272C4: lwc1        $f0, -0x2B60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B60);
    // 0x800272C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800272CC: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800272D0: lwc1        $f2, -0x2B54($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2B54);
    // 0x800272D4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800272D8: addiu       $a3, $a3, -0x4F58
    ctx->r7 = ADD32(ctx->r7, -0X4F58);
    // 0x800272DC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800272E0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800272E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800272E8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800272EC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800272F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800272F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800272F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800272FC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80027300: lwc1        $f14, -0x2B5C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x80027304: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80027308: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002730C: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80027310: lwc1        $f16, -0x2B50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B50);
    // 0x80027314: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80027318: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002731C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80027320: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80027324: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80027328: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002732C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80027330: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027334: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027338: lbu         $t5, -0x4F1F($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4F1F);
    // 0x8002733C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80027340: lbu         $s0, -0x4F1E($s0)
    ctx->r16 = MEM_BU(ctx->r16, -0X4F1E);
    // 0x80027344: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80027348: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8002734C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80027350: lbu         $s1, -0x4F1D($s1)
    ctx->r17 = MEM_BU(ctx->r17, -0X4F1D);
    // 0x80027354: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x80027358: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002735C: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80027360: addiu       $t0, $t0, -0x4F54
    ctx->r8 = ADD32(ctx->r8, -0X4F54);
    // 0x80027364: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80027368: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8002736C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80027370: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027374: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027378: nop

    // 0x8002737C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80027380: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80027384: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80027388: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8002738C: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80027390: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80027394: sb          $t8, -0x1F($v0)
    MEM_B(-0X1F, ctx->r2) = ctx->r24;
    // 0x80027398: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8002739C: sb          $t5, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r13;
    // 0x800273A0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800273A4: sb          $s0, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r16;
    // 0x800273A8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800273AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800273B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800273B4: sh          $t2, -0x24($v0)
    MEM_H(-0X24, ctx->r2) = ctx->r10;
    // 0x800273B8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800273BC: sb          $s1, -0x20($v0)
    MEM_B(-0X20, ctx->r2) = ctx->r17;
    // 0x800273C0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800273C4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800273C8: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800273CC: sh          $t3, -0x1E($v0)
    MEM_H(-0X1E, ctx->r2) = ctx->r11;
    // 0x800273D0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800273D4: nop

    // 0x800273D8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800273DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800273E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800273E4: nop

    // 0x800273E8: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800273EC: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800273F0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800273F4: sh          $t7, -0x26($v0)
    MEM_H(-0X26, ctx->r2) = ctx->r15;
    // 0x800273F8: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800273FC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80027400: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80027404: sb          $t7, -0x15($v0)
    MEM_B(-0X15, ctx->r2) = ctx->r15;
    // 0x80027408: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002740C: sh          $t1, -0x14($v0)
    MEM_H(-0X14, ctx->r2) = ctx->r9;
    // 0x80027410: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80027414: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027418: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002741C: sb          $t5, -0x18($v0)
    MEM_B(-0X18, ctx->r2) = ctx->r13;
    // 0x80027420: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80027424: sb          $s0, -0x17($v0)
    MEM_B(-0X17, ctx->r2) = ctx->r16;
    // 0x80027428: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8002742C: sb          $s1, -0x16($v0)
    MEM_B(-0X16, ctx->r2) = ctx->r17;
    // 0x80027430: sh          $t4, -0x1A($v0)
    MEM_H(-0X1A, ctx->r2) = ctx->r12;
    // 0x80027434: sh          $t9, -0x1C($v0)
    MEM_H(-0X1C, ctx->r2) = ctx->r25;
    // 0x80027438: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002743C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80027440: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80027444: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80027448: sb          $t9, -0xB($v0)
    MEM_B(-0XB, ctx->r2) = ctx->r25;
    // 0x8002744C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80027450: sb          $t5, -0xE($v0)
    MEM_B(-0XE, ctx->r2) = ctx->r13;
    // 0x80027454: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80027458: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002745C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027460: sb          $s0, -0xD($v0)
    MEM_B(-0XD, ctx->r2) = ctx->r16;
    // 0x80027464: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80027468: sh          $t2, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r10;
    // 0x8002746C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80027470: sb          $s1, -0xC($v0)
    MEM_B(-0XC, ctx->r2) = ctx->r17;
    // 0x80027474: sh          $t3, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r11;
    // 0x80027478: sh          $t6, -0x12($v0)
    MEM_H(-0X12, ctx->r2) = ctx->r14;
    // 0x8002747C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80027480: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80027484: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80027488: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8002748C: sb          $t5, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r13;
    // 0x80027490: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80027494: sb          $s0, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r16;
    // 0x80027498: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002749C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800274A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800274A4: sh          $t4, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r12;
    // 0x800274A8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800274AC: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
    // 0x800274B0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800274B4: sb          $s1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r17;
    // 0x800274B8: sh          $t8, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r24;
    extern void dkr_widen_void_primitive(uint8_t*, recomp_context*); dkr_widen_void_primitive(rdram, ctx);
    // 0x800274BC: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    // 0x800274C0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800274C4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800274C8: addiu       $t5, $zero, 0x3E0
    ctx->r13 = ADD32(0, 0X3E0);
    // 0x800274CC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800274D0: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800274D4: addiu       $t2, $a1, 0x2
    ctx->r10 = ADD32(ctx->r5, 0X2);
    // 0x800274D8: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x800274DC: addiu       $t9, $a1, 0x3
    ctx->r25 = ADD32(ctx->r5, 0X3);
    // 0x800274E0: sb          $t9, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r25;
    // 0x800274E4: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x800274E8: sb          $t2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r10;
    // 0x800274EC: sb          $t3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r11;
    // 0x800274F0: sb          $a1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r5;
    // 0x800274F4: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x800274F8: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    // 0x800274FC: sh          $t5, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r13;
    // 0x80027500: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x80027504: sh          $s0, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r16;
    // 0x80027508: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x8002750C: sb          $t4, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r12;
    // 0x80027510: sb          $t3, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r11;
    // 0x80027514: sb          $t2, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r10;
    // 0x80027518: sh          $s0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r16;
    // 0x8002751C: sh          $t5, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r13;
    // 0x80027520: sh          $t5, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r13;
    // 0x80027524: sh          $t5, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r13;
    // 0x80027528: sh          $s0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r16;
    // 0x8002752C: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
    // 0x80027530: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80027534: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80027538: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x8002753C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80027540: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80027544: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80027548: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x8002754C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80027550: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80027554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027558:
    // 0x80027558: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002755C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80027560: jr          $ra
    // 0x80027564: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80027564: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void sound_pitch_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800020C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800020C4: beq         $a0, $zero, L_800020D8
    if (ctx->r4 == 0) {
        // 0x800020C8: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800020D8;
    }
    // 0x800020C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800020CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800020D0: jal         0x800049F8
    // 0x800020D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_0;
    // 0x800020D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
L_800020D8:
    // 0x800020D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800020DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800020E0: jr          $ra
    // 0x800020E4: nop

    return;
    // 0x800020E4: nop

;}
RECOMP_FUNC void strcasecmp_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4794: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800B4798: nop

    // 0x800B479C: bne         $v0, $zero, L_800B47B4
    if (ctx->r2 != 0) {
        // 0x800B47A0: andi        $a2, $v0, 0xFF
        ctx->r6 = ctx->r2 & 0XFF;
            goto L_800B47B4;
    }
    // 0x800B47A0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800B47A4: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B47A8: nop

    // 0x800B47AC: beq         $t6, $zero, L_800B483C
    if (ctx->r14 == 0) {
        // 0x800B47B0: andi        $a2, $v0, 0xFF
        ctx->r6 = ctx->r2 & 0XFF;
            goto L_800B483C;
    }
L_800B47B0:
    // 0x800B47B0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_800B47B4:
    // 0x800B47B4: slti        $at, $a2, 0x61
    ctx->r1 = SIGNED(ctx->r6) < 0X61 ? 1 : 0;
    // 0x800B47B8: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800B47BC: bne         $at, $zero, L_800B47D4
    if (ctx->r1 != 0) {
        // 0x800B47C0: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800B47D4;
    }
    // 0x800B47C0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800B47C4: slti        $at, $a2, 0x7B
    ctx->r1 = SIGNED(ctx->r6) < 0X7B ? 1 : 0;
    // 0x800B47C8: beq         $at, $zero, L_800B47D4
    if (ctx->r1 == 0) {
        // 0x800B47CC: addiu       $a2, $a2, -0x20
        ctx->r6 = ADD32(ctx->r6, -0X20);
            goto L_800B47D4;
    }
    // 0x800B47CC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800B47D0: andi        $a3, $a2, 0xFF
    ctx->r7 = ctx->r6 & 0XFF;
L_800B47D4:
    // 0x800B47D4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B47D8: slti        $at, $v0, 0x61
    ctx->r1 = SIGNED(ctx->r2) < 0X61 ? 1 : 0;
    // 0x800B47DC: bne         $at, $zero, L_800B47F4
    if (ctx->r1 != 0) {
        // 0x800B47E0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800B47F4;
    }
    // 0x800B47E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800B47E4: slti        $at, $v0, 0x7B
    ctx->r1 = SIGNED(ctx->r2) < 0X7B ? 1 : 0;
    // 0x800B47E8: beq         $at, $zero, L_800B47F4
    if (ctx->r1 == 0) {
        // 0x800B47EC: addiu       $v0, $v0, -0x20
        ctx->r2 = ADD32(ctx->r2, -0X20);
            goto L_800B47F4;
    }
    // 0x800B47EC: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x800B47F0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_800B47F4:
    // 0x800B47F4: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800B47F8: beq         $at, $zero, L_800B480C
    if (ctx->r1 == 0) {
        // 0x800B47FC: slt         $at, $a2, $a3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800B480C;
    }
    // 0x800B47FC: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B4800: jr          $ra
    // 0x800B4804: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800B4804: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B4808: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
L_800B480C:
    // 0x800B480C: beq         $at, $zero, L_800B481C
    if (ctx->r1 == 0) {
        // 0x800B4810: nop
    
            goto L_800B481C;
    }
    // 0x800B4810: nop

    // 0x800B4814: jr          $ra
    // 0x800B4818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800B4818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B481C:
    // 0x800B481C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800B4820: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4824: bne         $v0, $zero, L_800B47B0
    if (ctx->r2 != 0) {
        // 0x800B4828: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800B47B0;
    }
    // 0x800B4828: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B482C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4830: nop

    // 0x800B4834: bne         $t9, $zero, L_800B47B4
    if (ctx->r25 != 0) {
        // 0x800B4838: andi        $a2, $v0, 0xFF
        ctx->r6 = ctx->r2 & 0XFF;
            goto L_800B47B4;
    }
    // 0x800B4838: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_800B483C:
    // 0x800B483C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4840: jr          $ra
    // 0x800B4844: nop

    return;
    // 0x800B4844: nop

;}
RECOMP_FUNC void soundoptions_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085200: lw          $a0, 0x69FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X69FC);
    // 0x80085204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085208: beq         $a0, $zero, L_80085218
    if (ctx->r4 == 0) {
        // 0x8008520C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80085218;
    }
    // 0x8008520C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085210: jal         0x8000488C
    // 0x80085214: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80085214: nop

    after_0:
L_80085218:
    // 0x80085218: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008521C: lw          $t6, 0x63D8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63D8);
    // 0x80085220: nop

    // 0x80085224: bltz        $t6, L_8008524C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80085228: nop
    
            goto L_8008524C;
    }
    // 0x80085228: nop

    // 0x8008522C: jal         0x80000BE0
    // 0x80085230: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_1;
    // 0x80085230: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_1:
    // 0x80085234: jal         0x80000B34
    // 0x80085238: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_2;
    // 0x80085238: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_2:
    // 0x8008523C: jal         0x80000C98
    // 0x80085240: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    music_fade(rdram, ctx);
        goto after_3;
    // 0x80085240: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_3:
    // 0x80085244: jal         0x80000B18
    // 0x80085248: nop

    music_change_off(rdram, ctx);
        goto after_4;
    // 0x80085248: nop

    after_4:
L_8008524C:
    // 0x8008524C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085250: jal         0x8009C4A8
    // 0x80085254: addiu       $a0, $a0, -0x5D4
    ctx->r4 = ADD32(ctx->r4, -0X5D4);
    menu_assetgroup_free(rdram, ctx);
        goto after_5;
    // 0x80085254: addiu       $a0, $a0, -0x5D4
    ctx->r4 = ADD32(ctx->r4, -0X5D4);
    after_5:
    // 0x80085258: jal         0x800C422C
    // 0x8008525C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_6;
    // 0x8008525C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x80085260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085268: jr          $ra
    // 0x8008526C: nop

    return;
    // 0x8008526C: nop

;}
RECOMP_FUNC void transition_update_fullscreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0834: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0838: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800C083C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800C0840: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C0844: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C0848: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C084C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C0850: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C0854: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C0858: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C085C: addiu       $a1, $a1, 0x31B0
    ctx->r5 = ADD32(ctx->r5, 0X31B0);
    // 0x800C0860: addiu       $a2, $a2, -0x58B0
    ctx->r6 = ADD32(ctx->r6, -0X58B0);
    // 0x800C0864: addiu       $a3, $a3, -0x58C9
    ctx->r7 = ADD32(ctx->r7, -0X58C9);
    // 0x800C0868: addiu       $t1, $t1, 0x31B4
    ctx->r9 = ADD32(ctx->r9, 0X31B4);
    // 0x800C086C: addiu       $t2, $t2, 0x31A8
    ctx->r10 = ADD32(ctx->r10, 0X31A8);
    // 0x800C0870: addiu       $t3, $t3, 0x31B8
    ctx->r11 = ADD32(ctx->r11, 0X31B8);
    // 0x800C0874: addiu       $t4, $t4, -0x58AC
    ctx->r12 = ADD32(ctx->r12, -0X58AC);
    // 0x800C0878: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
L_800C087C:
    // 0x800C087C: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800C0880: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C0884: blez        $v1, L_800C09A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C0888: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800C09A4;
    }
    // 0x800C0888: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C088C: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C0890: beq         $at, $zero, L_800C08BC
    if (ctx->r1 == 0) {
        // 0x800C0894: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800C08BC;
    }
    // 0x800C0894: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C0898: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800C089C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C08A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C08A4: subu        $t6, $v1, $a0
    ctx->r14 = SUB32(ctx->r3, ctx->r4);
    // 0x800C08A8: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800C08AC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C08B0: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800C08B4: b           L_800C08DC
    // 0x800C08B8: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
        goto L_800C08DC;
    // 0x800C08B8: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
L_800C08BC:
    // 0x800C08BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C08C0: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C08C4: bc1f        L_800C08D4
    if (!c1cs) {
        // 0x800C08C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C08D4;
    }
    // 0x800C08C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C08CC: b           L_800C08D8
    // 0x800C08D0: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
        goto L_800C08D8;
    // 0x800C08D0: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
L_800C08D4:
    // 0x800C08D4: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
L_800C08D8:
    // 0x800C08D8: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_800C08DC:
    // 0x800C08DC: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C08E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C08E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C08E8: nop

    // 0x800C08EC: bc1f        L_800C0904
    if (!c1cs) {
        // 0x800C08F0: nop
    
            goto L_800C0904;
    }
    // 0x800C08F0: nop

    // 0x800C08F4: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x800C08F8: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C08FC: b           L_800C0924
    // 0x800C0900: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
        goto L_800C0924;
    // 0x800C0900: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
L_800C0904:
    // 0x800C0904: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800C0908: nop

    // 0x800C090C: bc1f        L_800C0920
    if (!c1cs) {
        // 0x800C0910: nop
    
            goto L_800C0920;
    }
    // 0x800C0910: nop

    // 0x800C0914: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
    // 0x800C0918: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C091C: nop

L_800C0920:
    // 0x800C0920: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
L_800C0924:
    // 0x800C0924: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0928: nop

    // 0x800C092C: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800C0930: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C0934: nop

    // 0x800C0938: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C093C: beq         $t8, $zero, L_800C0988
    if (ctx->r24 == 0) {
        // 0x800C0940: nop
    
            goto L_800C0988;
    }
    // 0x800C0940: nop

    // 0x800C0944: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C0948: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C094C: sub.s       $f18, $f0, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800C0950: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C0954: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0958: nop

    // 0x800C095C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C0960: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C0964: nop

    // 0x800C0968: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C096C: bne         $t8, $zero, L_800C0980
    if (ctx->r24 != 0) {
        // 0x800C0970: nop
    
            goto L_800C0980;
    }
    // 0x800C0970: nop

    // 0x800C0974: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800C0978: b           L_800C0998
    // 0x800C097C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800C0998;
    // 0x800C097C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800C0980:
    // 0x800C0980: b           L_800C0998
    // 0x800C0984: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800C0998;
    // 0x800C0984: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800C0988:
    // 0x800C0988: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800C098C: nop

    // 0x800C0990: bltz        $t8, L_800C0980
    if (SIGNED(ctx->r24) < 0) {
        // 0x800C0994: nop
    
            goto L_800C0980;
    }
    // 0x800C0994: nop

L_800C0998:
    // 0x800C0998: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C099C: b           L_800C09F0
    // 0x800C09A0: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
        goto L_800C09F0;
    // 0x800C09A0: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
L_800C09A4:
    // 0x800C09A4: lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X0);
    // 0x800C09A8: nop

    // 0x800C09AC: beq         $t0, $v1, L_800C09F0
    if (ctx->r8 == ctx->r3) {
        // 0x800C09B0: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800C09F0;
    }
    // 0x800C09B0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C09B4: beq         $at, $zero, L_800C09C4
    if (ctx->r1 == 0) {
        // 0x800C09B8: subu        $t9, $v1, $a0
        ctx->r25 = SUB32(ctx->r3, ctx->r4);
            goto L_800C09C4;
    }
    // 0x800C09B8: subu        $t9, $v1, $a0
    ctx->r25 = SUB32(ctx->r3, ctx->r4);
    // 0x800C09BC: b           L_800C09F0
    // 0x800C09C0: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
        goto L_800C09F0;
    // 0x800C09C0: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
L_800C09C4:
    // 0x800C09C4: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800C09C8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C09CC: beq         $t5, $zero, L_800C09F0
    if (ctx->r13 == 0) {
        // 0x800C09D0: sh          $zero, 0x0($t1)
        MEM_H(0X0, ctx->r9) = 0;
            goto L_800C09F0;
    }
    // 0x800C09D0: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x800C09D4: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C09D8: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x800C09DC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800C09E0: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800C09E4: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x800C09E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C09EC: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
L_800C09F0:
    // 0x800C09F0: bne         $v0, $zero, L_800C0A00
    if (ctx->r2 != 0) {
        // 0x800C09F4: nop
    
            goto L_800C0A00;
    }
    // 0x800C09F4: nop

    // 0x800C09F8: bgtz        $a0, L_800C087C
    if (SIGNED(ctx->r4) > 0) {
        // 0x800C09FC: nop
    
            goto L_800C087C;
    }
    // 0x800C09FC: nop

L_800C0A00:
    // 0x800C0A00: jr          $ra
    // 0x800C0A04: nop

    return;
    // 0x800C0A04: nop

;}
RECOMP_FUNC void sndp_get_state(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000461C: beq         $a0, $zero, L_80004630
    if (ctx->r4 == 0) {
        // 0x80004620: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80004630;
    }
    // 0x80004620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004624: lbu         $v0, 0x3F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3F);
    // 0x80004628: jr          $ra
    // 0x8000462C: nop

    return;
    // 0x8000462C: nop

L_80004630:
    // 0x80004630: jr          $ra
    // 0x80004634: nop

    return;
    // 0x80004634: nop

;}
RECOMP_FUNC void lerp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022888: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8002288C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80022890: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80022894: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80022898: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8002289C: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800228A0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800228A4: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800228A8: jr          $ra
    // 0x800228AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800228AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void music_is_playing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800015C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800015CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800015D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800015D4: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x800015D8: jal         0x800C7A50
    // 0x800015DC: nop

    alCSPGetState(rdram, ctx);
        goto after_0;
    // 0x800015DC: nop

    after_0:
    // 0x800015E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800015E4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800015E8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800015EC: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x800015F0: jr          $ra
    // 0x800015F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800015F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void find_taj_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018C6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80018C70: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80018C74: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x80018C78: lw          $v0, -0x51A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A0);
    // 0x80018C7C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80018C80: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80018C84: beq         $at, $zero, L_80018CD4
    if (ctx->r1 == 0) {
        // 0x80018C88: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80018CD4;
    }
    // 0x80018C88: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80018C8C: lw          $t6, -0x51A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X51A8);
    // 0x80018C90: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    // 0x80018C94: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
L_80018C98:
    // 0x80018C98: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80018C9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80018CA0: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80018CA4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80018CA8: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80018CAC: bne         $t9, $zero, L_80018CCC
    if (ctx->r25 != 0) {
        // 0x80018CB0: nop
    
            goto L_80018CCC;
    }
    // 0x80018CB0: nop

    // 0x80018CB4: lh          $t0, 0x48($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X48);
    // 0x80018CB8: nop

    // 0x80018CBC: bne         $a2, $t0, L_80018CCC
    if (ctx->r6 != ctx->r8) {
        // 0x80018CC0: nop
    
            goto L_80018CCC;
    }
    // 0x80018CC0: nop

    // 0x80018CC4: jr          $ra
    // 0x80018CC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80018CC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80018CCC:
    // 0x80018CCC: bne         $at, $zero, L_80018C98
    if (ctx->r1 != 0) {
        // 0x80018CD0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80018C98;
    }
    // 0x80018CD0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80018CD4:
    // 0x80018CD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018CD8: jr          $ra
    // 0x80018CDC: nop

    return;
    // 0x80018CDC: nop

;}
RECOMP_FUNC void music_jingle_play_safe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000178C: jal         0x80001C08
    // 0x80001790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    music_jingle_playing(rdram, ctx);
        goto after_0;
    // 0x80001790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80001794: bne         $v0, $zero, L_800017C4
    if (ctx->r2 != 0) {
        // 0x80001798: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_800017C4;
    }
    // 0x80001798: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000179C: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800017A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800017A4: addiu       $v0, $v0, 0x5D05
    ctx->r2 = ADD32(ctx->r2, 0X5D05);
    // 0x800017A8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800017AC: lw          $a1, -0x39CC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X39CC);
    // 0x800017B0: jal         0x800022BC
    // 0x800017B4: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    music_sequence_start(rdram, ctx);
        goto after_1;
    // 0x800017B4: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    after_1:
    // 0x800017B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800017BC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800017C0: sb          $t7, 0x5D41($at)
    MEM_B(0X5D41, ctx->r1) = ctx->r15;
L_800017C4:
    // 0x800017C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800017C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800017CC: jr          $ra
    // 0x800017D0: nop

    return;
    // 0x800017D0: nop

;}
RECOMP_FUNC void func_80012C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80012C9C: addiu       $a1, $a1, -0x525C
    ctx->r5 = ADD32(ctx->r5, -0X525C);
    // 0x80012CA0: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80012CA4: nop

    // 0x80012CA8: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x80012CAC: beq         $at, $zero, L_80012CE0
    if (ctx->r1 == 0) {
        // 0x80012CB0: nop
    
            goto L_80012CE0;
    }
    // 0x80012CB0: nop

    // 0x80012CB4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80012CB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012CBC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80012CC0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80012CC4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012CC8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80012CCC: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x80012CD0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80012CD4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80012CD8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80012CDC: sw          $t8, -0x5288($at)
    MEM_W(-0X5288, ctx->r1) = ctx->r24;
L_80012CE0:
    // 0x80012CE0: jr          $ra
    // 0x80012CE4: nop

    return;
    // 0x80012CE4: nop

;}
RECOMP_FUNC void postrace_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_netplay_postrace_barrier(uint8_t*, recomp_context*); dkr_netplay_postrace_barrier(rdram, ctx); extern void dkr_postrace_presentation_start(uint8_t*, recomp_context*); dkr_postrace_presentation_start(rdram, ctx);
    // 0x80094688: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009468C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80094690: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80094694: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80094698: jal         0x80072298
    // 0x8009469C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_init(rdram, ctx);
        goto after_0;
    // 0x8009469C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800946A0: jal         0x8006BDB0
    // 0x800946A4: nop

    level_header(rdram, ctx);
        goto after_1;
    // 0x800946A4: nop

    after_1:
    // 0x800946A8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800946AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800946B0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800946B4: jal         0x8009EC80
    // 0x800946B8: sb          $t6, 0x6C28($at)
    MEM_B(0X6C28, ctx->r1) = ctx->r14;
    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x800946B8: sb          $t6, 0x6C28($at)
    MEM_B(0X6C28, ctx->r1) = ctx->r14;
    after_2:
    // 0x800946BC: beq         $v0, $zero, L_800946CC
    if (ctx->r2 == 0) {
        // 0x800946C0: nop
    
            goto L_800946CC;
    }
    // 0x800946C0: nop

    // 0x800946C4: jal         0x800249E0
    // 0x800946C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_scene_viewport_num(rdram, ctx);
        goto after_3;
    // 0x800946C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
L_800946CC:
    // 0x800946CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800946D0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800946D4: lw          $t7, -0xB44($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB44);
    // 0x800946D8: sw          $zero, 0x6A90($at)
    MEM_W(0X6A90, ctx->r1) = 0;
    // 0x800946DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800946E0: bne         $t7, $at, L_800947E0
    if (ctx->r15 != ctx->r1) {
        // 0x800946E4: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800947E0;
    }
    // 0x800946E4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800946E8: lw          $t8, 0xFE8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XFE8);
    // 0x800946EC: nop

    // 0x800946F0: bne         $t8, $zero, L_800947E4
    if (ctx->r24 != 0) {
        // 0x800946F4: addiu       $t3, $zero, 0x7
        ctx->r11 = ADD32(0, 0X7);
            goto L_800947E4;
    }
    // 0x800946F4: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x800946F8: jal         0x8009C2D0
    // 0x800946FC: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_4;
    // 0x800946FC: nop

    after_4:
    // 0x80094700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80094704: bne         $v0, $a2, L_8009474C
    if (ctx->r2 != ctx->r6) {
        // 0x80094708: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8009474C;
    }
    // 0x80094708: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009470C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80094710: lw          $v0, -0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB60);
    // 0x80094714: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80094718: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x8009471C: addiu       $a1, $a1, 0x6BF0
    ctx->r5 = ADD32(ctx->r5, 0X6BF0);
    // 0x80094720: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80094724: lw          $t0, 0x60($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X60);
    // 0x80094728: addiu       $a0, $a0, 0x6C14
    ctx->r4 = ADD32(ctx->r4, 0X6C14);
    // 0x8009472C: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80094730: lw          $t1, 0x68($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X68);
    // 0x80094734: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80094738: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8009473C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094740: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x80094744: b           L_800947B8
    // 0x80094748: sw          $a2, 0x6A90($at)
    MEM_W(0X6A90, ctx->r1) = ctx->r6;
        goto L_800947B8;
    // 0x80094748: sw          $a2, 0x6A90($at)
    MEM_W(0X6A90, ctx->r1) = ctx->r6;
L_8009474C:
    // 0x8009474C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80094750: nop

    // 0x80094754: bne         $t3, $zero, L_80094780
    if (ctx->r11 != 0) {
        // 0x80094758: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80094780;
    }
    // 0x80094758: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009475C: lw          $v0, -0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB60);
    // 0x80094760: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80094764: lw          $t4, 0x5C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X5C);
    // 0x80094768: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009476C: addiu       $a1, $a1, 0x6BF0
    ctx->r5 = ADD32(ctx->r5, 0X6BF0);
    // 0x80094770: addiu       $a0, $a0, 0x6C14
    ctx->r4 = ADD32(ctx->r4, 0X6C14);
    // 0x80094774: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80094778: b           L_8009479C
    // 0x8009477C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
        goto L_8009479C;
    // 0x8009477C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
L_80094780:
    // 0x80094780: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80094784: addiu       $a0, $a0, 0x6C14
    ctx->r4 = ADD32(ctx->r4, 0X6C14);
    // 0x80094788: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8009478C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80094790: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80094794: lw          $v0, -0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB60);
    // 0x80094798: addiu       $a1, $a1, 0x6BF0
    ctx->r5 = ADD32(ctx->r5, 0X6BF0);
L_8009479C:
    // 0x8009479C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800947A0: lw          $t5, 0x64($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X64);
    // 0x800947A4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800947A8: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800947AC: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800947B0: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x800947B4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_800947B8:
    // 0x800947B8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800947BC: lw          $t9, 0x70($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X70);
    // 0x800947C0: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800947C4: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x800947C8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800947CC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800947D0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800947D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800947D8: b           L_800947EC
    // 0x800947DC: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
        goto L_800947EC;
    // 0x800947DC: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
L_800947E0:
    // 0x800947E0: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
L_800947E4:
    // 0x800947E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800947E8: sw          $t3, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r11;
L_800947EC:
    // 0x800947EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800947F0: sw          $zero, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = 0;
    // 0x800947F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800947F8: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x800947FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094800: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    // 0x80094804: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094808: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x8009480C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094810: sw          $zero, -0xBA0($at)
    MEM_W(-0XBA0, ctx->r1) = 0;
    // 0x80094814: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094818: sw          $zero, 0x6A68($at)
    MEM_W(0X6A68, ctx->r1) = 0;
    // 0x8009481C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094820: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80094824: sw          $t4, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = ctx->r12;
    // 0x80094828: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009482C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80094830: sw          $t6, 0x6C54($at)
    MEM_W(0X6C54, ctx->r1) = ctx->r14;
    // 0x80094834: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094838: sw          $zero, 0x988($at)
    MEM_W(0X988, ctx->r1) = 0;
    // 0x8009483C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094840: sw          $zero, 0x6C1C($at)
    MEM_W(0X6C1C, ctx->r1) = 0;
    // 0x80094844: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80094848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009484C: sw          $zero, 0x6A98($at)
    MEM_W(0X6A98, ctx->r1) = 0;
    // 0x80094850: lb          $t7, 0x4C($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X4C);
    // 0x80094854: nop

    // 0x80094858: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x8009485C: beq         $t8, $zero, L_80094874
    if (ctx->r24 == 0) {
        // 0x80094860: nop
    
            goto L_80094874;
    }
    // 0x80094860: nop

    // 0x80094864: jal         0x8000C8B4
    // 0x80094868: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    normalise_time(rdram, ctx);
        goto after_5;
    // 0x80094868: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    after_5:
    // 0x8009486C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094870: sw          $v0, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = ctx->r2;
L_80094874:
    // 0x80094874: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80094878: lb          $t0, 0x6C28($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X6C28);
    // 0x8009487C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80094880: beq         $t0, $zero, L_80094898
    if (ctx->r8 == 0) {
        // 0x80094884: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80094898;
    }
    // 0x80094884: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094888: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
    // 0x8009488C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094890: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x80094894: sw          $t1, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r9;
L_80094898:
    // 0x80094898: jal         0x8006DA0C
    // 0x8009489C: nop

    get_game_mode(rdram, ctx);
        goto after_6;
    // 0x8009489C: nop

    after_6:
    // 0x800948A0: beq         $v0, $zero, L_800948B0
    if (ctx->r2 == 0) {
        // 0x800948A4: addiu       $t2, $zero, 0x7
        ctx->r10 = ADD32(0, 0X7);
            goto L_800948B0;
    }
    // 0x800948A4: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800948A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800948AC: sw          $t2, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r10;
L_800948B0:
    // 0x800948B0: jal         0x8009BE5C
    // 0x800948B4: nop

    reset_controller_sticks(rdram, ctx);
        goto after_7;
    // 0x800948B4: nop

    after_7:
    // 0x800948B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800948BC: jal         0x8006D8E0
    // 0x800948C0: nop

    race_postrace_type(rdram, ctx);
        goto after_8;
    // 0x800948C0: nop

    after_8:
    // 0x800948C4: jal         0x8007A520
    // 0x800948C8: nop

    fb_size(rdram, ctx);
        goto after_9;
    // 0x800948C8: nop

    after_9:
    // 0x800948CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800948D0: addiu       $a1, $a1, 0x647C
    ctx->r5 = ADD32(ctx->r5, 0X647C);
    // 0x800948D4: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800948D8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800948DC: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800948E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800948E4: sw          $t4, 0x6480($at)
    MEM_W(0X6480, ctx->r1) = ctx->r12;
    // 0x800948E8: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x800948EC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800948F0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800948F4: lw          $t8, 0x6480($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6480);
    // 0x800948F8: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800948FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094900: sw          $t7, 0x6474($at)
    MEM_W(0X6474, ctx->r1) = ctx->r15;
    // 0x80094904: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094908: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009490C: sra         $t0, $t8, 1
    ctx->r8 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80094910: lw          $t9, -0xB44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB44);
    // 0x80094914: sw          $t0, 0x6478($at)
    MEM_W(0X6478, ctx->r1) = ctx->r8;
    // 0x80094918: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009491C: bne         $t9, $at, L_80094A44
    if (ctx->r25 != ctx->r1) {
        // 0x80094920: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_80094A44;
    }
    // 0x80094920: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80094924: lw          $t1, 0xFE8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XFE8);
    // 0x80094928: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009492C: bne         $t1, $zero, L_80094A44
    if (ctx->r9 != 0) {
        // 0x80094930: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80094A44;
    }
    // 0x80094930: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80094934: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80094938: sw          $zero, 0x6C54($at)
    MEM_W(0X6C54, ctx->r1) = 0;
    // 0x8009493C: lb          $v0, 0x0($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X0);
    // 0x80094940: addiu       $t6, $t6, 0x710
    ctx->r14 = ADD32(ctx->r14, 0X710);
    // 0x80094944: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80094948: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8009494C: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x80094950: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80094954: addu        $v1, $t4, $t6
    ctx->r3 = ADD32(ctx->r12, ctx->r14);
    // 0x80094958: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8009495C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094960: beq         $a0, $at, L_80094994
    if (ctx->r4 == ctx->r1) {
        // 0x80094964: nop
    
            goto L_80094994;
    }
    // 0x80094964: nop

    // 0x80094968: jal         0x8009C6D4
    // 0x8009496C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    menu_asset_load(rdram, ctx);
        goto after_10;
    // 0x8009496C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_10:
    // 0x80094970: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80094974: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80094978: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x8009497C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094980: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80094984: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80094988: lw          $t8, 0x6550($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6550);
    // 0x8009498C: b           L_8009499C
    // 0x80094990: sw          $t8, 0x6BB8($at)
    MEM_W(0X6BB8, ctx->r1) = ctx->r24;
        goto L_8009499C;
    // 0x80094990: sw          $t8, 0x6BB8($at)
    MEM_W(0X6BB8, ctx->r1) = ctx->r24;
L_80094994:
    // 0x80094994: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094998: sw          $zero, 0x6BB8($at)
    MEM_W(0X6BB8, ctx->r1) = 0;
L_8009499C:
    // 0x8009499C: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800949A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800949A4: beq         $a0, $at, L_800949D8
    if (ctx->r4 == ctx->r1) {
        // 0x800949A8: nop
    
            goto L_800949D8;
    }
    // 0x800949A8: nop

    // 0x800949AC: jal         0x8009C6D4
    // 0x800949B0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    menu_asset_load(rdram, ctx);
        goto after_11;
    // 0x800949B0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_11:
    // 0x800949B4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800949B8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800949BC: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x800949C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800949C4: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800949C8: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800949CC: lw          $t1, 0x6550($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6550);
    // 0x800949D0: b           L_800949E0
    // 0x800949D4: sw          $t1, 0x6BBC($at)
    MEM_W(0X6BBC, ctx->r1) = ctx->r9;
        goto L_800949E0;
    // 0x800949D4: sw          $t1, 0x6BBC($at)
    MEM_W(0X6BBC, ctx->r1) = ctx->r9;
L_800949D8:
    // 0x800949D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800949DC: sw          $zero, 0x6BBC($at)
    MEM_W(0X6BBC, ctx->r1) = 0;
L_800949E0:
    // 0x800949E0: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x800949E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800949E8: jal         0x8006DA0C
    // 0x800949EC: sw          $t2, 0x6BC0($at)
    MEM_W(0X6BC0, ctx->r1) = ctx->r10;
    get_game_mode(rdram, ctx);
        goto after_12;
    // 0x800949EC: sw          $t2, 0x6BC0($at)
    MEM_W(0X6BC0, ctx->r1) = ctx->r10;
    after_12:
    // 0x800949F0: bne         $v0, $zero, L_80094A14
    if (ctx->r2 != 0) {
        // 0x800949F4: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80094A14;
    }
    // 0x800949F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800949F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800949FC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80094A00: lw          $a2, 0x6BC0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6BC0);
    // 0x80094A04: lw          $a1, 0x6BBC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6BBC);
    // 0x80094A08: lw          $a0, 0x6BB8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6BB8);
    // 0x80094A0C: jal         0x80078170
    // 0x80094A10: nop

    bgdraw_texture_init(rdram, ctx);
        goto after_13;
    // 0x80094A10: nop

    after_13:
L_80094A14:
    // 0x80094A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80094A18: jal         0x80066818
    // 0x80094A1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_14;
    // 0x80094A1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80094A20: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80094A24: lw          $t3, 0x6480($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6480);
    // 0x80094A28: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80094A2C: lw          $a3, 0x647C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X647C);
    // 0x80094A30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80094A34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80094A38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80094A3C: jal         0x80066940
    // 0x80094A40: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    viewport_menu_set(rdram, ctx);
        goto after_15;
    // 0x80094A40: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_15:
L_80094A44:
    // 0x80094A44: jal         0x80000968
    // 0x80094A48: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    sound_volume_change(rdram, ctx);
        goto after_16;
    // 0x80094A48: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_16:
    // 0x80094A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80094A50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80094A54: jr          $ra
    // 0x80094A58: nop

    return;
    // 0x80094A58: nop

;}
RECOMP_FUNC void menu_track_select_unload(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F534: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008F538: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008F53C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008F540: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008F544: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008F548: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F54C: jal         0x80066894
    // 0x8008F550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_0;
    // 0x8008F550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8008F554: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F558: jal         0x8009C4A8
    // 0x8008F55C: addiu       $a0, $a0, 0x7C4
    ctx->r4 = ADD32(ctx->r4, 0X7C4);
    menu_assetgroup_free(rdram, ctx);
        goto after_1;
    // 0x8008F55C: addiu       $a0, $a0, 0x7C4
    ctx->r4 = ADD32(ctx->r4, 0X7C4);
    after_1:
    // 0x8008F560: jal         0x800710B0
    // 0x8008F564: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_2;
    // 0x8008F564: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8008F568: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F56C: lw          $a0, 0x970($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X970);
    // 0x8008F570: jal         0x80071140
    // 0x8008F574: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8008F574: nop

    after_3:
    // 0x8008F578: jal         0x800710B0
    // 0x8008F57C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_4;
    // 0x8008F57C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8008F580: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008F584: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008F588: addiu       $s2, $s2, 0x72E
    ctx->r18 = ADD32(ctx->r18, 0X72E);
    // 0x8008F58C: addiu       $s0, $s0, 0x710
    ctx->r16 = ADD32(ctx->r16, 0X710);
    // 0x8008F590: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8008F594:
    // 0x8008F594: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8008F598: nop

    // 0x8008F59C: beq         $s1, $a0, L_8008F5AC
    if (ctx->r17 == ctx->r4) {
        // 0x8008F5A0: nop
    
            goto L_8008F5AC;
    }
    // 0x8008F5A0: nop

    // 0x8008F5A4: jal         0x8009C508
    // 0x8008F5A8: nop

    menu_asset_free(rdram, ctx);
        goto after_5;
    // 0x8008F5A8: nop

    after_5:
L_8008F5AC:
    // 0x8008F5AC: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x8008F5B0: nop

    // 0x8008F5B4: beq         $s1, $a0, L_8008F5C4
    if (ctx->r17 == ctx->r4) {
        // 0x8008F5B8: nop
    
            goto L_8008F5C4;
    }
    // 0x8008F5B8: nop

    // 0x8008F5BC: jal         0x8009C508
    // 0x8008F5C0: nop

    menu_asset_free(rdram, ctx);
        goto after_6;
    // 0x8008F5C0: nop

    after_6:
L_8008F5C4:
    // 0x8008F5C4: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x8008F5C8: bne         $s0, $s2, L_8008F594
    if (ctx->r16 != ctx->r18) {
        // 0x8008F5CC: nop
    
            goto L_8008F594;
    }
    // 0x8008F5CC: nop

    // 0x8008F5D0: jal         0x800C422C
    // 0x8008F5D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_7;
    // 0x8008F5D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x8008F5D8: jal         0x8007FF88
    // 0x8008F5DC: nop

    menu_button_free(rdram, ctx);
        goto after_8;
    // 0x8008F5DC: nop

    after_8:
    // 0x8008F5E0: jal         0x80000B28
    // 0x8008F5E4: nop

    music_change_on(rdram, ctx);
        goto after_9;
    // 0x8008F5E4: nop

    after_9:
    // 0x8008F5E8: jal         0x80000C2C
    // 0x8008F5EC: nop

    music_voicelimit_change_on(rdram, ctx);
        goto after_10;
    // 0x8008F5EC: nop

    after_10:
    // 0x8008F5F0: jal         0x80001844
    // 0x8008F5F4: nop

    music_stop(rdram, ctx);
        goto after_11;
    // 0x8008F5F4: nop

    after_11:
    // 0x8008F5F8: jal         0x8006F564
    // 0x8008F5FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_gIntDisFlag(rdram, ctx);
        goto after_12;
    // 0x8008F5FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x8008F600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008F604: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008F608: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F60C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008F610: jr          $ra
    // 0x8008F614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008F614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void tex_get_table_3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AE54: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007AE58: lw          $v0, 0x633C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X633C);
    // 0x8007AE5C: jr          $ra
    // 0x8007AE60: nop

    return;
    // 0x8007AE60: nop

;}
RECOMP_FUNC void reset_particles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE278: jal         0x800AE374
    // 0x800AE27C: nop

    free_particle_buffers(rdram, ctx);
        goto after_0;
    // 0x800AE27C: nop

    after_0:
    // 0x800AE280: jal         0x800AE438
    // 0x800AE284: nop

    free_particle_vertices_triangles(rdram, ctx);
        goto after_1;
    // 0x800AE284: nop

    after_1:
    // 0x800AE288: jal         0x800AE2D8
    // 0x800AE28C: nop

    particle_free_dummy(rdram, ctx);
        goto after_2;
    // 0x800AE28C: nop

    after_2:
    // 0x800AE290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE298: jr          $ra
    // 0x800AE29C: nop

    return;
    // 0x800AE29C: nop

;}
RECOMP_FUNC void skydome_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028C10: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028C14: addiu       $v1, $v1, -0x4F48
    ctx->r3 = ADD32(ctx->r3, -0X4F48);
    // 0x80028C18: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80028C1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028C20: beq         $t6, $zero, L_80028CC0
    if (ctx->r14 == 0) {
        // 0x80028C24: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80028CC0;
    }
    // 0x80028C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028C28: jal         0x80069D20
    // 0x80028C2C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80028C2C: nop

    after_0:
    // 0x80028C30: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80028C34: lw          $t7, -0x36E4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X36E4);
    // 0x80028C38: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028C3C: lb          $t8, 0x49($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X49);
    // 0x80028C40: addiu       $v1, $v1, -0x4F48
    ctx->r3 = ADD32(ctx->r3, -0X4F48);
    // 0x80028C44: bne         $t8, $zero, L_80028C7C
    if (ctx->r24 != 0) {
        // 0x80028C48: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80028C7C;
    }
    // 0x80028C48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028C4C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80028C50: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80028C54: nop

    // 0x80028C58: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x80028C5C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80028C60: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80028C64: nop

    // 0x80028C68: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
    // 0x80028C6C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80028C70: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80028C74: nop

    // 0x80028C78: swc1        $f8, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f8.u32l;
L_80028C7C:
    // 0x80028C7C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80028C80: addiu       $a1, $a1, -0x4F5C
    ctx->r5 = ADD32(ctx->r5, -0X4F5C);
    // 0x80028C84: jal         0x80068408
    // 0x80028C88: addiu       $a0, $a0, -0x4F60
    ctx->r4 = ADD32(ctx->r4, -0X4F60);
    mtx_world_origin(rdram, ctx);
        goto after_1;
    // 0x80028C88: addiu       $a0, $a0, -0x4F60
    ctx->r4 = ADD32(ctx->r4, -0X4F60);
    after_1:
    // 0x80028C8C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80028C90: lw          $t2, -0x4F24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4F24);
    // 0x80028C94: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028C98: beq         $t2, $zero, L_80028CC0
    if (ctx->r10 == 0) {
        // 0x80028C9C: addiu       $v1, $v1, -0x4F48
        ctx->r3 = ADD32(ctx->r3, -0X4F48);
            goto L_80028CC0;
    }
    // 0x80028C9C: addiu       $v1, $v1, -0x4F48
    ctx->r3 = ADD32(ctx->r3, -0X4F48);
    extern void dkr_skybox_cover_begin(uint8_t*, recomp_context*); dkr_skybox_cover_begin(rdram, ctx);
    // 0x80028CA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028CA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80028CA8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80028CAC: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x80028CB0: addiu       $a2, $a2, -0x4F58
    ctx->r6 = ADD32(ctx->r6, -0X4F58);
    // 0x80028CB4: addiu       $a1, $a1, -0x4F5C
    ctx->r5 = ADD32(ctx->r5, -0X4F5C);
    // 0x80028CB8: jal         0x80012D5C
    // 0x80028CBC: addiu       $a0, $a0, -0x4F60
    ctx->r4 = ADD32(ctx->r4, -0X4F60);
    render_object(rdram, ctx);
        goto after_2;
    // 0x80028CBC: addiu       $a0, $a0, -0x4F60
    ctx->r4 = ADD32(ctx->r4, -0X4F60);
    after_2:
L_80028CC0:
    extern void dkr_skybox_cover_end(uint8_t*, recomp_context*); dkr_skybox_cover_end(rdram, ctx);
    // 0x80028CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028CC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028CC8: jr          $ra
    // 0x80028CCC: nop

    return;
    // 0x80028CCC: nop

;}
