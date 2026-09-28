#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void skydome_spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027FC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80027FC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027FCC: jal         0x8005A3D0
    // 0x80027FD0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    drm_checksum_balloon(rdram, ctx);
        goto after_0;
    // 0x80027FD0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80027FD4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80027FD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80027FDC: bne         $v0, $at, L_80027FF0
    if (ctx->r2 != ctx->r1) {
        // 0x80027FE0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80027FF0;
    }
    // 0x80027FE0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80027FE4: addiu       $a0, $a0, -0x4F48
    ctx->r4 = ADD32(ctx->r4, -0X4F48);
    // 0x80027FE8: b           L_80028034
    // 0x80027FEC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_80028034;
    // 0x80027FEC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80027FF0:
    // 0x80027FF0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80027FF4: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // 0x80027FF8: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x80027FFC: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x80028000: sb          $t6, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r14;
    // 0x80028004: sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
    // 0x80028008: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002800C: jal         0x8000EA54
    // 0x80028010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    spawn_object(rdram, ctx);
        goto after_1;
    // 0x80028010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80028014: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028018: addiu       $a0, $a0, -0x4F48
    ctx->r4 = ADD32(ctx->r4, -0X4F48);
    // 0x8002801C: beq         $v0, $zero, L_80028034
    if (ctx->r2 == 0) {
        // 0x80028020: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80028034;
    }
    // 0x80028020: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80028024: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80028028: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8002802C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80028030: sh          $t7, 0x4A($t8)
    MEM_H(0X4A, ctx->r24) = ctx->r15;
L_80028034:
    // 0x80028034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028038: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002803C: jr          $ra
    // 0x80028040: nop

    return;
    // 0x80028040: nop

;}
RECOMP_FUNC void bgdraw_texture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_postrace_background_stretch_begin(uint8_t*, recomp_context*); dkr_postrace_background_stretch_begin(rdram, ctx);
    // 0x80078190: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80078194: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80078198: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007819C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800781A0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800781A4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800781A8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800781AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800781B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800781B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800781B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800781BC: jal         0x8007A520
    // 0x800781C0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800781C0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x800781C4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800781C8: sra         $t0, $v0, 16
    ctx->r8 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800781CC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800781D0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800781D4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800781D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800781DC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800781E0: andi        $t6, $t0, 0xFFFF
    ctx->r14 = ctx->r8 & 0XFFFF;
    // 0x800781E4: addiu       $t9, $t9, -0x1A68
    ctx->r25 = ADD32(ctx->r25, -0X1A68);
    // 0x800781E8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800781EC: addiu       $t2, $t2, -0x1B38
    ctx->r10 = ADD32(ctx->r10, -0X1B38);
    // 0x800781F0: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x800781F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800781F8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800781FC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80078200: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80078204: bne         $t6, $zero, L_800783C8
    if (ctx->r14 != 0) {
        // 0x80078208: addiu       $t1, $t1, -0x1B3C
        ctx->r9 = ADD32(ctx->r9, -0X1B3C);
            goto L_800783C8;
    }
    // 0x80078208: addiu       $t1, $t1, -0x1B3C
    ctx->r9 = ADD32(ctx->r9, -0X1B3C);
    // 0x8007820C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078210: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80078214: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078218: addiu       $t1, $t1, -0x1B3C
    ctx->r9 = ADD32(ctx->r9, -0X1B3C);
    // 0x8007821C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078220: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80078224: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80078228: lh          $a3, 0xA($t8)
    ctx->r7 = MEM_H(ctx->r24, 0XA);
    // 0x8007822C: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x80078230: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x80078234: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80078238: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x8007823C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80078240: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80078244: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80078248: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007824C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80078250: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80078254: lw          $t7, 0xC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XC);
    // 0x80078258: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8007825C: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x80078260: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80078264: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80078268: sll         $s6, $t0, 2
    ctx->r22 = S32(ctx->r8 << 2);
    // 0x8007826C: lbu         $s0, 0x0($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X0);
    // 0x80078270: lbu         $s4, 0x1($a2)
    ctx->r20 = MEM_BU(ctx->r6, 0X1);
    // 0x80078274: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80078278: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x8007827C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80078280: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80078284: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x80078288: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8007828C: blez        $s6, L_80078730
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80078290: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80078730;
    }
    // 0x80078290: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80078294: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80078298: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x8007829C: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x800782A0: addiu       $s7, $s7, -0x1B40
    ctx->r23 = ADD32(ctx->r23, -0X1B40);
    // 0x800782A4: addiu       $s5, $t8, -0x1
    ctx->r21 = ADD32(ctx->r24, -0X1);
    // 0x800782A8: lui         $t5, 0xB200
    ctx->r13 = S32(0XB200 << 16);
    // 0x800782AC: lui         $t4, 0xB300
    ctx->r12 = S32(0XB300 << 16);
    // 0x800782B0: lui         $t3, 0xE400
    ctx->r11 = S32(0XE400 << 16);
L_800782B4:
    // 0x800782B4: negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // 0x800782B8: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800782BC: beq         $at, $zero, L_800783A8
    if (ctx->r1 == 0) {
        // 0x800782C0: addu        $t1, $s2, $s4
        ctx->r9 = ADD32(ctx->r18, ctx->r20);
            goto L_800783A8;
    }
    // 0x800782C0: addu        $t1, $s2, $s4
    ctx->r9 = ADD32(ctx->r18, ctx->r20);
    // 0x800782C4: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x800782C8: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800782CC: andi        $t2, $s2, 0xFFF
    ctx->r10 = ctx->r18 & 0XFFF;
L_800782D0:
    // 0x800782D0: bgez        $v0, L_8007833C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800782D4: addu        $a2, $v0, $s0
        ctx->r6 = ADD32(ctx->r2, ctx->r16);
            goto L_8007833C;
    }
    // 0x800782D4: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x800782D8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800782DC: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x800782E0: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x800782E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800782E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800782EC: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800782F0: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x800782F4: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x800782F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800782FC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80078300: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078304: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80078308: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8007830C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078310: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x80078314: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80078318: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007831C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078320: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078324: nop

    // 0x80078328: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007832C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078330: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078334: b           L_8007839C
    // 0x80078338: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
        goto L_8007839C;
    // 0x80078338: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_8007833C:
    // 0x8007833C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078340: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x80078344: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80078348: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x8007834C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078350: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078354: andi        $t6, $v0, 0xFFF
    ctx->r14 = ctx->r2 & 0XFFF;
    // 0x80078358: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007835C: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x80078360: or          $t7, $t8, $t2
    ctx->r15 = ctx->r24 | ctx->r10;
    // 0x80078364: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078368: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007836C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078370: nop

    // 0x80078374: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078378: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007837C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078380: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078384: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078388: nop

    // 0x8007838C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078390: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078394: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078398: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_8007839C:
    // 0x8007839C: slt         $at, $a2, $s1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800783A0: bne         $at, $zero, L_800782D0
    if (ctx->r1 != 0) {
        // 0x800783A4: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800782D0;
    }
    // 0x800783A4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800783A8:
    // 0x800783A8: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800783AC: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
    // 0x800783B0: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x800783B4: addu        $t7, $s3, $t8
    ctx->r15 = ADD32(ctx->r19, ctx->r24);
    // 0x800783B8: bne         $at, $zero, L_800782B4
    if (ctx->r1 != 0) {
        // 0x800783BC: and         $s3, $t7, $s5
        ctx->r19 = ctx->r15 & ctx->r21;
            goto L_800782B4;
    }
    // 0x800783BC: and         $s3, $t7, $s5
    ctx->r19 = ctx->r15 & ctx->r21;
    // 0x800783C0: b           L_80078734
    // 0x800783C4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
        goto L_80078734;
    // 0x800783C4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_800783C8:
    // 0x800783C8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800783CC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800783D0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800783D4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800783D8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800783DC: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x800783E0: lh          $a3, 0xA($t6)
    ctx->r7 = MEM_H(ctx->r14, 0XA);
    // 0x800783E4: sll         $s6, $t0, 2
    ctx->r22 = S32(ctx->r8 << 2);
    // 0x800783E8: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x800783EC: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800783F0: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x800783F4: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800783F8: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800783FC: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80078400: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078404: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80078408: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007840C: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x80078410: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80078414: addu        $t8, $t9, $at
    ctx->r24 = ADD32(ctx->r25, ctx->r1);
    // 0x80078418: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007841C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80078420: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80078424: lbu         $s0, 0x0($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X0);
    // 0x80078428: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8007842C: lbu         $s4, 0x1($a2)
    ctx->r20 = MEM_BU(ctx->r6, 0X1);
    // 0x80078430: lbu         $t7, 0x1($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X1);
    // 0x80078434: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80078438: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8007843C: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x80078440: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80078444: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80078448: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
    // 0x8007844C: addu        $fp, $t6, $t9
    ctx->r30 = ADD32(ctx->r14, ctx->r25);
    // 0x80078450: blez        $s6, L_80078588
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80078454: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80078588;
    }
    // 0x80078454: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80078458: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8007845C: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x80078460: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x80078464: addiu       $s7, $s7, -0x1B40
    ctx->r23 = ADD32(ctx->r23, -0X1B40);
    // 0x80078468: addiu       $s5, $s0, -0x1
    ctx->r21 = ADD32(ctx->r16, -0X1);
    // 0x8007846C: lui         $t5, 0xB200
    ctx->r13 = S32(0XB200 << 16);
    // 0x80078470: lui         $t4, 0xB300
    ctx->r12 = S32(0XB300 << 16);
    // 0x80078474: lui         $t3, 0xE400
    ctx->r11 = S32(0XE400 << 16);
L_80078478:
    // 0x80078478: negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // 0x8007847C: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80078480: beq         $at, $zero, L_8007856C
    if (ctx->r1 == 0) {
        // 0x80078484: addu        $t1, $s2, $s4
        ctx->r9 = ADD32(ctx->r18, ctx->r20);
            goto L_8007856C;
    }
    // 0x80078484: addu        $t1, $s2, $s4
    ctx->r9 = ADD32(ctx->r18, ctx->r20);
    // 0x80078488: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x8007848C: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x80078490: andi        $t2, $s2, 0xFFF
    ctx->r10 = ctx->r18 & 0XFFF;
L_80078494:
    // 0x80078494: bgez        $v0, L_80078500
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80078498: addu        $a2, $v0, $s0
        ctx->r6 = ADD32(ctx->r2, ctx->r16);
            goto L_80078500;
    }
    // 0x80078498: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x8007849C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800784A0: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x800784A4: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x800784A8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800784AC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800784B0: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800784B4: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x800784B8: or          $t8, $t9, $t1
    ctx->r24 = ctx->r25 | ctx->r9;
    // 0x800784BC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800784C0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800784C4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800784C8: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800784CC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800784D0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800784D4: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800784D8: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800784DC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800784E0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800784E4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800784E8: nop

    // 0x800784EC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800784F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800784F4: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x800784F8: b           L_80078560
    // 0x800784FC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
        goto L_80078560;
    // 0x800784FC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80078500:
    // 0x80078500: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078504: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x80078508: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8007850C: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x80078510: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078514: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078518: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x8007851C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80078520: or          $t9, $t6, $t1
    ctx->r25 = ctx->r14 | ctx->r9;
    // 0x80078524: or          $t6, $t7, $t2
    ctx->r14 = ctx->r15 | ctx->r10;
    // 0x80078528: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007852C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078530: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078534: nop

    // 0x80078538: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007853C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078540: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078544: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078548: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007854C: nop

    // 0x80078550: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078554: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078558: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x8007855C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80078560:
    // 0x80078560: slt         $at, $a2, $s1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80078564: bne         $at, $zero, L_80078494
    if (ctx->r1 != 0) {
        // 0x80078568: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80078494;
    }
    // 0x80078568: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8007856C:
    // 0x8007856C: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80078570: addu        $s2, $s2, $fp
    ctx->r18 = ADD32(ctx->r18, ctx->r30);
    // 0x80078574: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80078578: addu        $t6, $s3, $t7
    ctx->r14 = ADD32(ctx->r19, ctx->r15);
    // 0x8007857C: bne         $at, $zero, L_80078478
    if (ctx->r1 != 0) {
        // 0x80078580: and         $s3, $t6, $s5
        ctx->r19 = ctx->r14 & ctx->r21;
            goto L_80078478;
    }
    // 0x80078580: and         $s3, $t6, $s5
    ctx->r19 = ctx->r14 & ctx->r21;
    // 0x80078584: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80078588:
    // 0x80078588: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007858C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80078590: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078594: addiu       $a2, $a2, -0x1B38
    ctx->r6 = ADD32(ctx->r6, -0X1B38);
    // 0x80078598: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007859C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800785A0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800785A4: lh          $a1, 0xA($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XA);
    // 0x800785A8: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x800785AC: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800785B0: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800785B4: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x800785B8: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x800785BC: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800785C0: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800785C4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800785C8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800785CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800785D0: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800785D4: sll         $t8, $s6, 2
    ctx->r24 = S32(ctx->r22 << 2);
    // 0x800785D8: addu        $t7, $t9, $at
    ctx->r15 = ADD32(ctx->r25, ctx->r1);
    // 0x800785DC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800785E0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800785E4: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800785E8: lbu         $s4, 0x1($t9)
    ctx->r20 = MEM_BU(ctx->r25, 0X1);
    // 0x800785EC: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800785F0: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800785F4: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800785F8: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x800785FC: addiu       $s7, $s7, -0x1B40
    ctx->r23 = ADD32(ctx->r23, -0X1B40);
    // 0x80078600: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x80078604: lui         $t3, 0xE400
    ctx->r11 = S32(0XE400 << 16);
    // 0x80078608: lui         $t4, 0xB300
    ctx->r12 = S32(0XB300 << 16);
    // 0x8007860C: lui         $t5, 0xB200
    ctx->r13 = S32(0XB200 << 16);
    // 0x80078610: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80078614: or          $s6, $t8, $zero
    ctx->r22 = ctx->r24 | 0;
    // 0x80078618: beq         $at, $zero, L_80078730
    if (ctx->r1 == 0) {
        // 0x8007861C: or          $s4, $t7, $zero
        ctx->r20 = ctx->r15 | 0;
            goto L_80078730;
    }
    // 0x8007861C: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x80078620: addiu       $s5, $s0, -0x1
    ctx->r21 = ADD32(ctx->r16, -0X1);
L_80078624:
    // 0x80078624: negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // 0x80078628: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8007862C: beq         $at, $zero, L_80078718
    if (ctx->r1 == 0) {
        // 0x80078630: addu        $t1, $s2, $s4
        ctx->r9 = ADD32(ctx->r18, ctx->r20);
            goto L_80078718;
    }
    // 0x80078630: addu        $t1, $s2, $s4
    ctx->r9 = ADD32(ctx->r18, ctx->r20);
    // 0x80078634: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x80078638: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8007863C: andi        $t2, $s2, 0xFFF
    ctx->r10 = ctx->r18 & 0XFFF;
L_80078640:
    // 0x80078640: bgez        $v0, L_800786AC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80078644: addu        $a2, $v0, $s0
        ctx->r6 = ADD32(ctx->r2, ctx->r16);
            goto L_800786AC;
    }
    // 0x80078644: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x80078648: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007864C: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x80078650: andi        $t9, $a2, 0xFFF
    ctx->r25 = ctx->r6 & 0XFFF;
    // 0x80078654: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078658: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007865C: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80078660: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x80078664: or          $t8, $t6, $t1
    ctx->r24 = ctx->r14 | ctx->r9;
    // 0x80078668: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007866C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80078670: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078674: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80078678: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007867C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078680: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80078684: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80078688: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007868C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078690: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078694: nop

    // 0x80078698: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007869C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800786A0: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x800786A4: b           L_8007870C
    // 0x800786A8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
        goto L_8007870C;
    // 0x800786A8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800786AC:
    // 0x800786AC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800786B0: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x800786B4: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800786B8: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x800786BC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800786C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800786C4: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x800786C8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800786CC: or          $t6, $t7, $t1
    ctx->r14 = ctx->r15 | ctx->r9;
    // 0x800786D0: or          $t7, $t9, $t2
    ctx->r15 = ctx->r25 | ctx->r10;
    // 0x800786D4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800786D8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800786DC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800786E0: nop

    // 0x800786E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800786E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800786EC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800786F0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800786F4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800786F8: nop

    // 0x800786FC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078700: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078704: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078708: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_8007870C:
    // 0x8007870C: slt         $at, $a2, $s1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80078710: bne         $at, $zero, L_80078640
    if (ctx->r1 != 0) {
        // 0x80078714: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80078640;
    }
    // 0x80078714: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80078718:
    // 0x80078718: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x8007871C: addu        $s2, $s2, $fp
    ctx->r18 = ADD32(ctx->r18, ctx->r30);
    // 0x80078720: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80078724: addu        $t7, $s3, $t9
    ctx->r15 = ADD32(ctx->r19, ctx->r25);
    // 0x80078728: bne         $at, $zero, L_80078624
    if (ctx->r1 != 0) {
        // 0x8007872C: and         $s3, $t7, $s5
        ctx->r19 = ctx->r15 & ctx->r21;
            goto L_80078624;
    }
    // 0x8007872C: and         $s3, $t7, $s5
    ctx->r19 = ctx->r15 & ctx->r21;
L_80078730:
    // 0x80078730: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_80078734:
    // 0x80078734: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80078738: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8007873C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078740: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078744: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    extern void dkr_postrace_background_stretch_end(uint8_t*, recomp_context*); dkr_postrace_background_stretch_end(rdram, ctx);
    // 0x80078748: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007874C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80078750: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80078754: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80078758: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007875C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80078760: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80078764: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80078768: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007876C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80078770: jr          $ra
    // 0x80078774: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80078774: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void trophyround_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009820C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098210: jal         0x8006EA90
    // 0x80098214: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80098214: nop

    after_0:
    // 0x80098218: lbu         $t6, 0x48($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X48);
    // 0x8009821C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098220: sw          $t6, 0xFE8($at)
    MEM_W(0XFE8, ctx->r1) = ctx->r14;
    // 0x80098224: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098228: sw          $zero, 0xFEC($at)
    MEM_W(0XFEC, ctx->r1) = 0;
    // 0x8009822C: lw          $t8, 0x4C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4C);
    // 0x80098230: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x80098234: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098238: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8009823C: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x80098240: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80098244: sb          $zero, 0xF($t9)
    MEM_B(0XF, ctx->r25) = 0;
    // 0x80098248: lw          $t0, 0x4C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4C);
    // 0x8009824C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80098250: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x80098254: jal         0x8000E4BC
    // 0x80098258: sb          $t1, -0xBB0($at)
    MEM_B(-0XBB0, ctx->r1) = ctx->r9;
    set_time_trial_enabled(rdram, ctx);
        goto after_1;
    // 0x80098258: sb          $t1, -0xBB0($at)
    MEM_B(-0XBB0, ctx->r1) = ctx->r9;
    after_1:
    // 0x8009825C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098264: jr          $ra
    // 0x80098268: nop

    return;
    // 0x80098268: nop

;}
RECOMP_FUNC void rocket_prevent_overshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EC14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003EC18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003EC1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003EC20: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8003EC24: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x8003EC28: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8003EC2C: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x8003EC30: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8003EC34: slti        $at, $t6, 0x50
    ctx->r1 = SIGNED(ctx->r14) < 0X50 ? 1 : 0;
    // 0x8003EC38: bne         $at, $zero, L_8003EC50
    if (ctx->r1 != 0) {
        // 0x8003EC3C: nop
    
            goto L_8003EC50;
    }
    // 0x8003EC3C: nop

    // 0x8003EC40: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x8003EC44: nop

    // 0x8003EC48: beq         $t7, $zero, L_8003EC84
    if (ctx->r15 == 0) {
        // 0x8003EC4C: nop
    
            goto L_8003EC84;
    }
    // 0x8003EC4C: nop

L_8003EC50:
    // 0x8003EC50: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8003EC54: nop

    // 0x8003EC58: beq         $a1, $zero, L_8003EC84
    if (ctx->r5 == 0) {
        // 0x8003EC5C: nop
    
            goto L_8003EC84;
    }
    // 0x8003EC5C: nop

    // 0x8003EC60: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8003EC64: nop

    // 0x8003EC68: beq         $a1, $t8, L_8003EC84
    if (ctx->r5 == ctx->r24) {
        // 0x8003EC6C: nop
    
            goto L_8003EC84;
    }
    // 0x8003EC6C: nop

    // 0x8003EC70: lh          $t9, 0x48($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X48);
    // 0x8003EC74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003EC78: bne         $t9, $at, L_8003EC84
    if (ctx->r25 != ctx->r1) {
        // 0x8003EC7C: nop
    
            goto L_8003EC84;
    }
    // 0x8003EC7C: nop

    // 0x8003EC80: sw          $a1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r5;
L_8003EC84:
    // 0x8003EC84: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8003EC88: nop

    // 0x8003EC8C: beq         $v0, $zero, L_8003EDBC
    if (ctx->r2 == 0) {
        // 0x8003EC90: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8003EDBC;
    }
    // 0x8003EC90: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8003EC94: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003EC98: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8003EC9C: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003ECA0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003ECA4: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8003ECA8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003ECAC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003ECB0: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003ECB4: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8003ECB8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003ECBC: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003ECC0: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8003ECC4: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8003ECC8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003ECCC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003ECD0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8003ECD4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8003ECD8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003ECDC: jal         0x800C9AD0
    // 0x8003ECE0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8003ECE0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003ECE4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003ECE8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003ECEC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8003ECF0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003ECF4: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003ECF8: bc1f        L_8003EDB8
    if (!c1cs) {
        // 0x8003ECFC: swc1        $f0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
            goto L_8003EDB8;
    }
    // 0x8003ECFC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8003ED00: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8003ED04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003ED08: nop

    // 0x8003ED0C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8003ED10: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003ED14: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8003ED18: jal         0x80070750
    // 0x8003ED1C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x8003ED1C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_1:
    // 0x8003ED20: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003ED24: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8003ED28: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x8003ED2C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8003ED30: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
    // 0x8003ED34: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8003ED38: subu        $a0, $a2, $t2
    ctx->r4 = SUB32(ctx->r6, ctx->r10);
    // 0x8003ED3C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003ED40: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003ED44: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003ED48: bne         $at, $zero, L_8003ED58
    if (ctx->r1 != 0) {
        // 0x8003ED4C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003ED58;
    }
    // 0x8003ED4C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003ED50: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003ED54: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8003ED58:
    // 0x8003ED58: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x8003ED5C: beq         $at, $zero, L_8003ED68
    if (ctx->r1 == 0) {
        // 0x8003ED60: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003ED68;
    }
    // 0x8003ED60: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003ED64: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8003ED68:
    // 0x8003ED68: slti        $at, $a0, 0x6001
    ctx->r1 = SIGNED(ctx->r4) < 0X6001 ? 1 : 0;
    // 0x8003ED6C: beq         $at, $zero, L_8003ED7C
    if (ctx->r1 == 0) {
        // 0x8003ED70: slti        $at, $a0, -0x6000
        ctx->r1 = SIGNED(ctx->r4) < -0X6000 ? 1 : 0;
            goto L_8003ED7C;
    }
    // 0x8003ED70: slti        $at, $a0, -0x6000
    ctx->r1 = SIGNED(ctx->r4) < -0X6000 ? 1 : 0;
    // 0x8003ED74: beq         $at, $zero, L_8003ED94
    if (ctx->r1 == 0) {
        // 0x8003ED78: nop
    
            goto L_8003ED94;
    }
    // 0x8003ED78: nop

L_8003ED7C:
    // 0x8003ED7C: lw          $t3, 0x4C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4C);
    // 0x8003ED80: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003ED84: sw          $a1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r5;
    // 0x8003ED88: lw          $t5, 0x4C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4C);
    // 0x8003ED8C: nop

    // 0x8003ED90: sb          $t4, 0x13($t5)
    MEM_B(0X13, ctx->r13) = ctx->r12;
L_8003ED94:
    // 0x8003ED94: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8003ED98: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003ED9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003EDA0: jal         0x80070750
    // 0x8003EDA4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x8003EDA4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x8003EDA8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003EDAC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003EDB0: sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // 0x8003EDB4: sh          $a2, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r6;
L_8003EDB8:
    // 0x8003EDB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8003EDBC:
    // 0x8003EDBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003EDC0: jal         0x8003F0F8
    // 0x8003EDC4: addiu       $a2, $zero, 0x137
    ctx->r6 = ADD32(0, 0X137);
    play_rocket_trailing_sound(rdram, ctx);
        goto after_3;
    // 0x8003EDC4: addiu       $a2, $zero, 0x137
    ctx->r6 = ADD32(0, 0X137);
    after_3:
    // 0x8003EDC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EDCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003EDD0: jr          $ra
    // 0x8003EDD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003EDD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void audspat_jingle_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008168: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000816C: jr          $ra
    // 0x80008170: sb          $zero, -0x53E8($at)
    MEM_B(-0X53E8, ctx->r1) = 0;
    return;
    // 0x80008170: sb          $zero, -0x53E8($at)
    MEM_B(-0X53E8, ctx->r1) = 0;
;}
RECOMP_FUNC void race_calc_distance_to_start_line(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B954: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B958: lw          $v0, -0x5130($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5130);
    // 0x8001B95C: nop

    // 0x8001B960: bgtz        $v0, L_8001B974
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001B964: nop
    
            goto L_8001B974;
    }
    // 0x8001B964: nop

    // 0x8001B968: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B96C: jr          $ra
    // 0x8001B970: nop

    return;
    // 0x8001B970: nop

L_8001B974:
    // 0x8001B974: lb          $a1, 0x192($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X192);
    // 0x8001B978: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001B97C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001B980: beq         $at, $zero, L_8001B9B8
    if (ctx->r1 == 0) {
        // 0x8001B984: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8001B9B8;
    }
    // 0x8001B984: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8001B988: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B98C: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8001B990: lw          $t6, -0x5134($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5134);
    // 0x8001B994: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8001B998: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001B99C: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
L_8001B9A0:
    // 0x8001B9A0: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x8001B9A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001B9A8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001B9AC: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    // 0x8001B9B0: bne         $at, $zero, L_8001B9A0
    if (ctx->r1 != 0) {
        // 0x8001B9B4: add.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_8001B9A0;
    }
    // 0x8001B9B4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
L_8001B9B8:
    // 0x8001B9B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B9BC: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8001B9C0: lw          $a2, -0x5134($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5134);
    // 0x8001B9C4: bgez        $v1, L_8001B9D4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001B9C8: sll         $t8, $v1, 4
        ctx->r24 = S32(ctx->r3 << 4);
            goto L_8001B9D4;
    }
    // 0x8001B9C8: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x8001B9CC: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8001B9D0: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
L_8001B9D4:
    // 0x8001B9D4: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8001B9D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001B9DC: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8001B9E0: lwc1        $f6, 0x20($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8001B9E4: lwc1        $f8, 0xA8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x8001B9E8: nop

    // 0x8001B9EC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001B9F0: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8001B9F4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001B9F8: jr          $ra
    // 0x8001B9FC: nop

    return;
    // 0x8001B9FC: nop

;}
RECOMP_FUNC void mempool_alloc_safe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070C9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80070CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070CA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80070CA8: bne         $a0, $zero, L_80070CCC
    if (ctx->r4 != 0) {
        // 0x80070CAC: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80070CCC;
    }
    // 0x80070CAC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80070CB0: jal         0x800B7D10
    // 0x80070CB4: nop

    stack_pointer(rdram, ctx);
        goto after_0;
    // 0x80070CB4: nop

    after_0:
    // 0x80070CB8: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80070CBC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80070CC0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80070CC4: jal         0x800B7460
    // 0x80070CC8: nop

    dump_memory_to_cpak(rdram, ctx);
        goto after_1;
    // 0x80070CC8: nop

    after_1:
L_80070CCC:
    // 0x80070CCC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80070CD0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80070CD4: jal         0x80070D3C
    // 0x80070CD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_slot_find(rdram, ctx);
        goto after_2;
    // 0x80070CD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80070CDC: bne         $v0, $zero, L_80070D00
    if (ctx->r2 != 0) {
        // 0x80070CE0: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80070D00;
    }
    // 0x80070CE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80070CE4: jal         0x800B7D10
    // 0x80070CE8: nop

    stack_pointer(rdram, ctx);
        goto after_3;
    // 0x80070CE8: nop

    after_3:
    // 0x80070CEC: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80070CF0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80070CF4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80070CF8: jal         0x800B7460
    // 0x80070CFC: nop

    dump_memory_to_cpak(rdram, ctx);
        goto after_4;
    // 0x80070CFC: nop

    after_4:
L_80070D00:
    // 0x80070D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070D04: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80070D08: jr          $ra
    // 0x80070D0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80070D0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void free_particle_vertices_triangles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE438: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE43C: lw          $a0, 0x2CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CE0);
    // 0x800AE440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE444: beq         $a0, $zero, L_800AE45C
    if (ctx->r4 == 0) {
        // 0x800AE448: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE45C;
    }
    // 0x800AE448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE44C: jal         0x80071140
    // 0x800AE450: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AE450: nop

    after_0:
    // 0x800AE454: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE458: sw          $zero, 0x2CE0($at)
    MEM_W(0X2CE0, ctx->r1) = 0;
L_800AE45C:
    // 0x800AE45C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE460: lw          $a0, 0x2CE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CE4);
    // 0x800AE464: nop

    // 0x800AE468: beq         $a0, $zero, L_800AE484
    if (ctx->r4 == 0) {
        // 0x800AE46C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AE484;
    }
    // 0x800AE46C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE470: jal         0x80071140
    // 0x800AE474: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AE474: nop

    after_1:
    // 0x800AE478: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE47C: sw          $zero, 0x2CE4($at)
    MEM_W(0X2CE4, ctx->r1) = 0;
    // 0x800AE480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AE484:
    // 0x800AE484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE488: jr          $ra
    // 0x800AE48C: nop

    return;
    // 0x800AE48C: nop

;}
RECOMP_FUNC void asset_table_load_zipped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_asset_api(uint8_t*, recomp_context*, unsigned); if (dkr_legacy_asset_api(rdram, ctx, 5U)) return;
    // 0x80076CF0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80076CF4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80076CF8: lw          $v0, 0x4290($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4290);
    // 0x80076CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076D00: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80076D04: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80076D08: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80076D0C: sltu        $at, $t6, $a0
    ctx->r1 = ctx->r14 < ctx->r4 ? 1 : 0;
    // 0x80076D10: beq         $at, $zero, L_80076D20
    if (ctx->r1 == 0) {
        // 0x80076D14: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80076D20;
    }
    // 0x80076D14: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80076D18: b           L_80076DEC
    // 0x80076D1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076DEC;
    // 0x80076D1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076D20:
    // 0x80076D20: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80076D24: addu        $a3, $t7, $v0
    ctx->r7 = ADD32(ctx->r15, ctx->r2);
    // 0x80076D28: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80076D2C: lw          $t8, 0x4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4);
    // 0x80076D30: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80076D34: subu        $t9, $t8, $v1
    ctx->r25 = SUB32(ctx->r24, ctx->r3);
    // 0x80076D38: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80076D3C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80076D40: jal         0x80070C9C
    // 0x80076D44: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80076D44: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x80076D48: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80076D4C: lui         $t0, 0xF
    ctx->r8 = S32(0XF << 16);
    // 0x80076D50: addiu       $t0, $t0, -0x33D0
    ctx->r8 = ADD32(ctx->r8, -0X33D0);
    // 0x80076D54: addu        $a0, $v1, $t0
    ctx->r4 = ADD32(ctx->r3, ctx->r8);
    // 0x80076D58: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80076D5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80076D60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80076D64: jal         0x80076F78
    // 0x80076D68: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    dmacopy(rdram, ctx);
        goto after_1;
    // 0x80076D68: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80076D6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80076D70: jal         0x800C61AC
    // 0x80076D74: nop

    byteswap32(rdram, ctx);
        goto after_2;
    // 0x80076D74: nop

    after_2:
    // 0x80076D78: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80076D7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80076D80: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80076D84: jal         0x80071140
    // 0x80076D88: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80076D88: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_3:
    // 0x80076D8C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80076D90: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80076D94: lui         $a1, 0x7F7F
    ctx->r5 = S32(0X7F7F << 16);
    // 0x80076D98: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80076D9C: jal         0x80070C9C
    // 0x80076DA0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80076DA0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x80076DA4: bne         $v0, $zero, L_80076DB4
    if (ctx->r2 != 0) {
        // 0x80076DA8: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80076DB4;
    }
    // 0x80076DA8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80076DAC: b           L_80076DEC
    // 0x80076DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076DEC;
    // 0x80076DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076DB4:
    // 0x80076DB4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80076DB8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80076DBC: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x80076DC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80076DC4: subu        $a1, $t6, $a2
    ctx->r5 = SUB32(ctx->r14, ctx->r6);
    // 0x80076DC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80076DCC: jal         0x80076F78
    // 0x80076DD0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    dmacopy(rdram, ctx);
        goto after_5;
    // 0x80076DD0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_5:
    // 0x80076DD4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80076DD8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80076DDC: jal         0x800C6218
    // 0x80076DE0: nop

    gzip_inflate(rdram, ctx);
        goto after_6;
    // 0x80076DE0: nop

    after_6:
    // 0x80076DE4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80076DE8: nop

L_80076DEC:
    // 0x80076DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076DF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80076DF4: jr          $ra
    // 0x80076DF8: nop

    return;
    // 0x80076DF8: nop

;}
RECOMP_FUNC void obj_init_treasuresucker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D038: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8003D03C: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x8003D040: lb          $t7, 0x8($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X8);
    // 0x8003D044: nop

    // 0x8003D048: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8003D04C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8003D050: jr          $ra
    // 0x8003D054: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
    return;
    // 0x8003D054: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void racetype_demo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E148: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E14C: lb          $v0, -0x38E4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X38E4);
    // 0x8000E150: jr          $ra
    // 0x8000E154: nop

    return;
    // 0x8000E154: nop

;}
RECOMP_FUNC void update_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030838: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003083C: blez        $a0, L_80030934
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80030840: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80030934;
    }
    // 0x80030840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030844: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80030848: addiu       $v1, $v1, -0x2C78
    ctx->r3 = ADD32(ctx->r3, -0X2C78);
L_8003084C:
    // 0x8003084C: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    // 0x80030850: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80030854: blez        $a1, L_8003092C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80030858: slt         $at, $a2, $a1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8003092C;
    }
    // 0x80030858: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003085C: beq         $at, $zero, L_800308EC
    if (ctx->r1 == 0) {
        // 0x80030860: nop
    
            goto L_800308EC;
    }
    // 0x80030860: nop

    // 0x80030864: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x80030868: lw          $t1, 0x18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X18);
    // 0x8003086C: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030870: lw          $t5, 0x1C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X1C);
    // 0x80030874: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80030878: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8003087C: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x80030880: mflo        $t8
    ctx->r24 = lo;
    // 0x80030884: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80030888: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8003088C: multu       $t1, $a2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030890: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x80030894: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x80030898: mflo        $t2
    ctx->r10 = lo;
    // 0x8003089C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800308A0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800308A4: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800308A8: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x800308AC: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    // 0x800308B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800308B4: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x800308B8: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x800308BC: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800308C0: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x800308C4: subu        $t6, $t7, $a2
    ctx->r14 = SUB32(ctx->r15, ctx->r6);
    // 0x800308C8: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x800308CC: mflo        $t1
    ctx->r9 = lo;
    // 0x800308D0: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x800308D4: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x800308D8: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800308DC: mflo        $t5
    ctx->r13 = lo;
    // 0x800308E0: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x800308E4: b           L_8003092C
    // 0x800308E8: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
        goto L_8003092C;
    // 0x800308E8: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
L_800308EC:
    // 0x800308EC: lbu         $t9, 0x28($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X28);
    // 0x800308F0: lbu         $t1, 0x29($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X29);
    // 0x800308F4: lbu         $t3, 0x2A($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2A);
    // 0x800308F8: lh          $t5, 0x2C($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2C);
    // 0x800308FC: lh          $t7, 0x2E($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2E);
    // 0x80030900: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80030904: sll         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9 << 16);
    // 0x80030908: sll         $t2, $t3, 16
    ctx->r10 = S32(ctx->r11 << 16);
    // 0x8003090C: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80030910: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80030914: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80030918: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8003091C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80030920: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x80030924: sw          $t6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r14;
    // 0x80030928: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
L_8003092C:
    // 0x8003092C: bne         $v0, $a0, L_8003084C
    if (ctx->r2 != ctx->r4) {
        // 0x80030930: addiu       $v1, $v1, 0x38
        ctx->r3 = ADD32(ctx->r3, 0X38);
            goto L_8003084C;
    }
    // 0x80030930: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
L_80030934:
    // 0x80030934: jr          $ra
    // 0x80030938: nop

    return;
    // 0x80030938: nop

;}
RECOMP_FUNC void aitable_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BFC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006BFCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006BFD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006BFD4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006BFD8: jal         0x8009C2D0
    // 0x8006BFDC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8006BFDC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x8006BFE0: bne         $v0, $zero, L_8006C028
    if (ctx->r2 != 0) {
        // 0x8006BFE4: nop
    
            goto L_8006C028;
    }
    // 0x8006BFE4: nop

    // 0x8006BFE8: jal         0x8006EA90
    // 0x8006BFEC: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x8006BFEC: nop

    after_1:
    // 0x8006BFF0: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x8006BFF4: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8006BFF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006BFFC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8006C000: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8006C004: nop

    // 0x8006C008: andi        $t1, $a3, 0x2
    ctx->r9 = ctx->r7 & 0X2;
    // 0x8006C00C: beq         $t1, $zero, L_8006C018
    if (ctx->r9 == 0) {
        // 0x8006C010: andi        $t2, $a3, 0x4
        ctx->r10 = ctx->r7 & 0X4;
            goto L_8006C018;
    }
    // 0x8006C010: andi        $t2, $a3, 0x4
    ctx->r10 = ctx->r7 & 0X4;
    // 0x8006C014: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8006C018:
    // 0x8006C018: beq         $t2, $zero, L_8006C02C
    if (ctx->r10 == 0) {
        // 0x8006C01C: nop
    
            goto L_8006C02C;
    }
    // 0x8006C01C: nop

    // 0x8006C020: b           L_8006C02C
    // 0x8006C024: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_8006C02C;
    // 0x8006C024: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_8006C028:
    // 0x8006C028: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_8006C02C:
    // 0x8006C02C: jal         0x8009962C
    // 0x8006C030: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_2;
    // 0x8006C030: nop

    after_2:
    // 0x8006C034: beq         $v0, $zero, L_8006C040
    if (ctx->r2 == 0) {
        // 0x8006C038: nop
    
            goto L_8006C040;
    }
    // 0x8006C038: nop

    // 0x8006C03C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_8006C040:
    // 0x8006C040: jal         0x8009EC70
    // 0x8006C044: nop

    is_in_adventure_two(rdram, ctx);
        goto after_3;
    // 0x8006C044: nop

    after_3:
    // 0x8006C048: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006C04C: beq         $v0, $zero, L_8006C064
    if (ctx->r2 == 0) {
        // 0x8006C050: addu        $t7, $s0, $t5
        ctx->r15 = ADD32(ctx->r16, ctx->r13);
            goto L_8006C064;
    }
    // 0x8006C050: addu        $t7, $s0, $t5
    ctx->r15 = ADD32(ctx->r16, ctx->r13);
    // 0x8006C054: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
    // 0x8006C058: sll         $t3, $s0, 24
    ctx->r11 = S32(ctx->r16 << 24);
    // 0x8006C05C: sra         $s0, $t3, 24
    ctx->r16 = S32(SIGNED(ctx->r11) >> 24);
    // 0x8006C060: addu        $t7, $s0, $t5
    ctx->r15 = ADD32(ctx->r16, ctx->r13);
L_8006C064:
    // 0x8006C064: lb          $s0, 0x0($t7)
    ctx->r16 = MEM_B(ctx->r15, 0X0);
    // 0x8006C068: jal         0x8009C30C
    // 0x8006C06C: nop

    get_filtered_cheats(rdram, ctx);
        goto after_4;
    // 0x8006C06C: nop

    after_4:
    // 0x8006C070: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x8006C074: bgez        $t6, L_8006C080
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006C078: nop
    
            goto L_8006C080;
    }
    // 0x8006C078: nop

    // 0x8006C07C: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_8006C080:
    // 0x8006C080: jal         0x8006DA0C
    // 0x8006C084: nop

    get_game_mode(rdram, ctx);
        goto after_5;
    // 0x8006C084: nop

    after_5:
    // 0x8006C088: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C08C: bne         $v0, $at, L_8006C098
    if (ctx->r2 != ctx->r1) {
        // 0x8006C090: nop
    
            goto L_8006C098;
    }
    // 0x8006C090: nop

    // 0x8006C094: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_8006C098:
    // 0x8006C098: jal         0x80076C58
    // 0x8006C09C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    asset_table_load(rdram, ctx);
        goto after_6;
    // 0x8006C09C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8006C0A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C0A4: addiu       $t0, $t0, 0x1160
    ctx->r8 = ADD32(ctx->r8, 0X1160);
    // 0x8006C0A8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8006C0AC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8006C0B0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8006C0B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006C0B8: beq         $a0, $t8, L_8006C0E4
    if (ctx->r4 == ctx->r24) {
        // 0x8006C0BC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8006C0E4;
    }
    // 0x8006C0BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8006C0C0:
    // 0x8006C0C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C0C4: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8006C0C8: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8006C0CC: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8006C0D0: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x8006C0D4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8006C0D8: nop

    // 0x8006C0DC: bne         $a0, $t4, L_8006C0C0
    if (ctx->r4 != ctx->r12) {
        // 0x8006C0E0: nop
    
            goto L_8006C0C0;
    }
    // 0x8006C0E0: nop

L_8006C0E4:
    // 0x8006C0E4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8006C0E8: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x8006C0EC: sra         $t7, $t5, 16
    ctx->r15 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8006C0F0: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8006C0F4: bne         $at, $zero, L_8006C100
    if (ctx->r1 != 0) {
        // 0x8006C0F8: lui         $a1, 0xFFFF
        ctx->r5 = S32(0XFFFF << 16);
            goto L_8006C100;
    }
    // 0x8006C0F8: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006C0FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006C100:
    // 0x8006C100: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8006C104: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x8006C108: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8006C10C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8006C110: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006C114: subu        $a0, $t8, $v1
    ctx->r4 = SUB32(ctx->r24, ctx->r3);
    // 0x8006C118: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8006C11C: jal         0x80070C9C
    // 0x8006C120: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x8006C120: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_7:
    // 0x8006C124: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006C128: addiu       $v1, $v1, 0x11C0
    ctx->r3 = ADD32(ctx->r3, 0X11C0);
    // 0x8006C12C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8006C130: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8006C134: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8006C138: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006C13C: jal         0x80076E68
    // 0x8006C140: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_8;
    // 0x8006C140: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x8006C144: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C148: lw          $a0, 0x1160($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1160);
    // 0x8006C14C: jal         0x80071140
    // 0x8006C150: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x8006C150: nop

    after_9:
    // 0x8006C154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C158: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C15C: jr          $ra
    // 0x8006C160: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006C160: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void unload_level_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DBE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DBE8: addiu       $v0, $v0, 0x3514
    ctx->r2 = ADD32(ctx->r2, 0X3514);
    // 0x8006DBEC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8006DBF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DBF4: bne         $t6, $zero, L_8006DC48
    if (ctx->r14 != 0) {
        // 0x8006DBF8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006DC48;
    }
    // 0x8006DBF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DBFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006DC00: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8006DC04: jal         0x800710B0
    // 0x8006DC08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006DC08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006DC0C: jal         0x8006BEFC
    // 0x8006DC10: nop

    level_free(rdram, ctx);
        goto after_1;
    // 0x8006DC10: nop

    after_1:
    // 0x8006DC14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006DC18: jal         0x800C01D8
    // 0x8006DC1C: addiu       $a0, $a0, -0x2C0C
    ctx->r4 = ADD32(ctx->r4, -0X2C0C);
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8006DC1C: addiu       $a0, $a0, -0x2C0C
    ctx->r4 = ADD32(ctx->r4, -0X2C0C);
    after_2:
    // 0x8006DC20: jal         0x800AE270
    // 0x8006DC24: nop

    reset_particles(rdram, ctx);
        goto after_3;
    // 0x8006DC24: nop

    after_3:
    // 0x8006DC28: jal         0x800A003C
    // 0x8006DC2C: nop

    hud_free(rdram, ctx);
        goto after_4;
    // 0x8006DC2C: nop

    after_4:
    // 0x8006DC30: jal         0x800C30CC
    // 0x8006DC34: nop

    free_game_text_table(rdram, ctx);
        goto after_5;
    // 0x8006DC34: nop

    after_5:
    // 0x8006DC38: jal         0x800710B0
    // 0x8006DC3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_6;
    // 0x8006DC3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8006DC40: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DC44: addiu       $v0, $v0, 0x3514
    ctx->r2 = ADD32(ctx->r2, 0X3514);
L_8006DC48:
    // 0x8006DC48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DC4C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8006DC50: jr          $ra
    // 0x8006DC54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006DC54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void alSynFreeVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9938: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x800C993C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C9940: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C9944: beql        $a2, $zero, L_800C99D4
    if (ctx->r6 == 0) {
        // 0x800C9948: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C99D4;
    }
    goto skip_0;
    // 0x800C9948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C994C: lw          $t6, 0xD8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD8);
    // 0x800C9950: beql        $t6, $zero, L_800C99BC
    if (ctx->r14 == 0) {
        // 0x800C9954: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800C99BC;
    }
    goto skip_1;
    // 0x800C9954: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    skip_1:
    // 0x800C9958: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C995C: jal         0x80065668
    // 0x800C9960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9960: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C9964: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9968: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C996C: beq         $v0, $zero, L_800C99D0
    if (ctx->r2 == 0) {
        // 0x800C9970: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C99D0;
    }
    // 0x800C9970: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9974: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x800C9978: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800C997C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9980: lw          $t9, 0xD8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD8);
    // 0x800C9984: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800C9988: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x800C998C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9990: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800C9994: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800C9998: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800C999C: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800C99A0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800C99A4: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C99A8: jalr        $t9
    // 0x800C99AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C99AC: nop

    after_1:
    // 0x800C99B0: b           L_800C99CC
    // 0x800C99B4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_800C99CC;
    // 0x800C99B4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C99B8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800C99BC:
    // 0x800C99BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800C99C0: jal         0x8006571C
    // 0x800C99C4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _freePVoice(rdram, ctx);
        goto after_2;
    // 0x800C99C4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800C99C8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800C99CC:
    // 0x800C99CC: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_800C99D0:
    // 0x800C99D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C99D4:
    // 0x800C99D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C99D8: jr          $ra
    // 0x800C99DC: nop

    return;
    // 0x800C99DC: nop

;}
RECOMP_FUNC void func_8007FFEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FFEC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007FFF0: addiu       $a2, $a2, 0x6C2C
    ctx->r6 = ADD32(ctx->r6, 0X6C2C);
    // 0x8007FFF4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8007FFF8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007FFFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80080000: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80080004: beq         $t6, $zero, L_80080014
    if (ctx->r14 == 0) {
        // 0x80080008: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80080014;
    }
    // 0x80080008: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008000C: jal         0x8007FF88
    // 0x80080010: nop

    menu_button_free(rdram, ctx);
        goto after_0;
    // 0x80080010: nop

    after_0:
L_80080014:
    // 0x80080014: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80080018: multu       $s0, $t1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008001C: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80080020: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x80080024: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80080028: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8008002C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80080030: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80080034: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080038: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x8008003C: sw          $v0, 0x1DC0($at)
    MEM_W(0X1DC0, ctx->r1) = ctx->r2;
    // 0x80080040: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080044: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x80080048: mflo        $v1
    ctx->r3 = lo;
    // 0x8008004C: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x80080050: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80080054: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80080058: sw          $v0, 0x1DC4($at)
    MEM_W(0X1DC4, ctx->r1) = ctx->r2;
    // 0x8008005C: addu        $a0, $t6, $t4
    ctx->r4 = ADD32(ctx->r14, ctx->r12);
    // 0x80080060: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80080064: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80080068: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8008006C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80080070: jal         0x80070C9C
    // 0x80080074: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80080074: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x80080078: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8008007C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80080080: addiu       $a3, $a3, 0x1DAC
    ctx->r7 = ADD32(ctx->r7, 0X1DAC);
    // 0x80080084: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80080088: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008008C: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x80080090: sw          $t8, 0x1DB0($at)
    MEM_W(0X1DB0, ctx->r1) = ctx->r24;
    // 0x80080094: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x80080098: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008009C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800800A0: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800800A4: addiu       $a2, $a2, 0x6C2C
    ctx->r6 = ADD32(ctx->r6, 0X6C2C);
    // 0x800800A8: sw          $t6, 0x6C2C($at)
    MEM_W(0X6C2C, ctx->r1) = ctx->r14;
    // 0x800800AC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800800B0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800800B4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800800B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800800BC: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x800800C0: addiu       $t0, $t0, 0x1DA4
    ctx->r8 = ADD32(ctx->r8, 0X1DA4);
    // 0x800800C4: sw          $t8, 0x1DA4($at)
    MEM_W(0X1DA4, ctx->r1) = ctx->r24;
    // 0x800800C8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800800CC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800800D0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800800D4: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800800D8: sw          $t6, 0x1DA8($at)
    MEM_W(0X1DA8, ctx->r1) = ctx->r14;
    // 0x800800DC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800800E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800800E4: blez        $s0, L_80080408
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800800E8: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_80080408;
    }
    // 0x800800E8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800800EC: andi        $a0, $s0, 0x3
    ctx->r4 = ctx->r16 & 0X3;
    // 0x800800F0: beq         $a0, $zero, L_800801A4
    if (ctx->r4 == 0) {
        // 0x800800F4: or          $t4, $a0, $zero
        ctx->r12 = ctx->r4 | 0;
            goto L_800801A4;
    }
    // 0x800800F4: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x800800F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800800FC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80080100: sll         $v0, $zero, 5
    ctx->r2 = S32(0 << 5);
L_80080104:
    // 0x80080104: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80080108: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8008010C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080110: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080114: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80080118: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008011C: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80080120: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080124: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80080128: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8008012C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080130: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80080134: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080138: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8008013C: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80080140: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x80080144: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80080148: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x8008014C: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080150: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x80080154: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x80080158: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8008015C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80080160: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080164: sw          $zero, 0x10($t8)
    MEM_W(0X10, ctx->r24) = 0;
    // 0x80080168: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8008016C: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80080170: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080174: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
    // 0x80080178: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8008017C: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x80080180: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080184: sw          $zero, 0x18($t8)
    MEM_W(0X18, ctx->r24) = 0;
    // 0x80080188: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8008018C: addiu       $t2, $t2, 0x14
    ctx->r10 = ADD32(ctx->r10, 0X14);
    // 0x80080190: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080194: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
    // 0x80080198: bne         $t4, $t3, L_80080104
    if (ctx->r12 != ctx->r11) {
        // 0x8008019C: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_80080104;
    }
    // 0x8008019C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800801A0: beq         $t3, $s0, L_80080404
    if (ctx->r11 == ctx->r16) {
        // 0x800801A4: sll         $v1, $t2, 2
        ctx->r3 = S32(ctx->r10 << 2);
            goto L_80080404;
    }
L_800801A4:
    // 0x800801A4: sll         $v1, $t2, 2
    ctx->r3 = S32(ctx->r10 << 2);
    // 0x800801A8: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x800801AC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800801B0: sll         $v0, $t3, 5
    ctx->r2 = S32(ctx->r11 << 5);
    // 0x800801B4: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
L_800801B8:
    // 0x800801B8: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800801BC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800801C0: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800801C4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800801C8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800801CC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800801D0: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x800801D4: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800801D8: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800801DC: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800801E0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800801E4: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800801E8: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x800801EC: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800801F0: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800801F4: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x800801F8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800801FC: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80080200: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080204: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x80080208: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8008020C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080210: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x80080214: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080218: sw          $zero, 0x10($t8)
    MEM_W(0X10, ctx->r24) = 0;
    // 0x8008021C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080220: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80080224: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080228: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
    // 0x8008022C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080230: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080234: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080238: sw          $zero, 0x18($t8)
    MEM_W(0X18, ctx->r24) = 0;
    // 0x8008023C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080240: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80080244: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080248: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
    // 0x8008024C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080250: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80080254: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080258: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8008025C: sw          $t8, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r24;
    // 0x80080260: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80080264: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80080268: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x8008026C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80080270: sw          $t9, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r25;
    // 0x80080274: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080278: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8008027C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080280: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80080284: sw          $t8, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r24;
    // 0x80080288: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008028C: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80080290: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080294: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x80080298: sw          $t9, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r25;
    // 0x8008029C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800802A0: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x800802A4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800802A8: sw          $zero, 0x30($t8)
    MEM_W(0X30, ctx->r24) = 0;
    // 0x800802AC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800802B0: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x800802B4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800802B8: sw          $zero, 0x34($t6)
    MEM_W(0X34, ctx->r14) = 0;
    // 0x800802BC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800802C0: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x800802C4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800802C8: sw          $zero, 0x38($t8)
    MEM_W(0X38, ctx->r24) = 0;
    // 0x800802CC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800802D0: nop

    // 0x800802D4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800802D8: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    // 0x800802DC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800802E0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800802E4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800802E8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800802EC: sw          $t8, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r24;
    // 0x800802F0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800802F4: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x800802F8: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800802FC: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80080300: sw          $t9, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r25;
    // 0x80080304: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080308: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8008030C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080310: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80080314: sw          $t8, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r24;
    // 0x80080318: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008031C: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80080320: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080324: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x80080328: sw          $t9, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r25;
    // 0x8008032C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080330: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x80080334: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080338: sw          $zero, 0x50($t8)
    MEM_W(0X50, ctx->r24) = 0;
    // 0x8008033C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080340: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080344: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080348: sw          $zero, 0x54($t6)
    MEM_W(0X54, ctx->r14) = 0;
    // 0x8008034C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080350: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80080354: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080358: sw          $zero, 0x58($t8)
    MEM_W(0X58, ctx->r24) = 0;
    // 0x8008035C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080360: nop

    // 0x80080364: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080368: sw          $zero, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = 0;
    // 0x8008036C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080370: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80080374: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080378: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8008037C: sw          $t8, 0x60($t6)
    MEM_W(0X60, ctx->r14) = ctx->r24;
    // 0x80080380: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80080384: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80080388: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x8008038C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80080390: sw          $t9, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r25;
    // 0x80080394: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080398: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8008039C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800803A0: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800803A4: sw          $t8, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->r24;
    // 0x800803A8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800803AC: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x800803B0: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800803B4: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800803B8: sw          $t9, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->r25;
    // 0x800803BC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800803C0: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x800803C4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800803C8: sw          $zero, 0x70($t8)
    MEM_W(0X70, ctx->r24) = 0;
    // 0x800803CC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800803D0: nop

    // 0x800803D4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800803D8: sw          $zero, 0x74($t6)
    MEM_W(0X74, ctx->r14) = 0;
    // 0x800803DC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800803E0: nop

    // 0x800803E4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800803E8: sw          $zero, 0x78($t8)
    MEM_W(0X78, ctx->r24) = 0;
    // 0x800803EC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800803F0: nop

    // 0x800803F4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800803F8: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x800803FC: bne         $v0, $t4, L_800801B8
    if (ctx->r2 != ctx->r12) {
        // 0x80080400: sw          $zero, 0x7C($t6)
        MEM_W(0X7C, ctx->r14) = 0;
            goto L_800801B8;
    }
    // 0x80080400: sw          $zero, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = 0;
L_80080404:
    // 0x80080404: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80080408:
    // 0x80080408: blez        $s0, L_800804F4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008040C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800804F4;
    }
    // 0x8008040C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080410: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080414: addiu       $a2, $a2, 0x1DB4
    ctx->r6 = ADD32(ctx->r6, 0X1DB4);
    // 0x80080418: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008041C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
L_80080420:
    // 0x80080420: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080424: addiu       $a0, $a0, 0x1CD0
    ctx->r4 = ADD32(ctx->r4, 0X1CD0);
    // 0x80080428: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8008042C:
    // 0x8008042C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80080430: addiu       $v0, $v0, 0x1DAC
    ctx->r2 = ADD32(ctx->r2, 0X1DAC);
L_80080434:
    // 0x80080434: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80080438: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008043C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080440: sb          $a1, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r5;
    // 0x80080444: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80080448: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8008044C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80080450: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x80080454: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80080458: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x8008045C: addu        $t9, $t6, $v1
    ctx->r25 = ADD32(ctx->r14, ctx->r3);
    // 0x80080460: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
    // 0x80080464: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80080468: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
    // 0x8008046C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x80080470: sb          $t7, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r15;
    // 0x80080474: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x80080478: nop

    // 0x8008047C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x80080480: sh          $zero, 0x4($t6)
    MEM_H(0X4, ctx->r14) = 0;
    // 0x80080484: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80080488: nop

    // 0x8008048C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080490: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x80080494: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x80080498: nop

    // 0x8008049C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800804A0: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800804A4: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800804A8: nop

    // 0x800804AC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800804B0: sh          $zero, 0xA($t8)
    MEM_H(0XA, ctx->r24) = 0;
    // 0x800804B4: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800804B8: nop

    // 0x800804BC: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800804C0: sh          $zero, 0xC($t6)
    MEM_H(0XC, ctx->r14) = 0;
    // 0x800804C4: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800804C8: nop

    // 0x800804CC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800804D0: bne         $v0, $a2, L_80080434
    if (ctx->r2 != ctx->r6) {
        // 0x800804D4: sh          $zero, 0xE($t8)
        MEM_H(0XE, ctx->r24) = 0;
            goto L_80080434;
    }
    // 0x800804D4: sh          $zero, 0xE($t8)
    MEM_H(0XE, ctx->r24) = 0;
    // 0x800804D8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800804DC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800804E0: bne         $a3, $t1, L_8008042C
    if (ctx->r7 != ctx->r9) {
        // 0x800804E4: addiu       $a0, $a0, 0x3
        ctx->r4 = ADD32(ctx->r4, 0X3);
            goto L_8008042C;
    }
    // 0x800804E4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800804E8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800804EC: bne         $t3, $s0, L_80080420
    if (ctx->r11 != ctx->r16) {
        // 0x800804F0: nop
    
            goto L_80080420;
    }
    // 0x800804F0: nop

L_800804F4:
    // 0x800804F4: sw          $zero, 0x1DB4($at)
    MEM_W(0X1DB4, ctx->r1) = 0;
    // 0x800804F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800804FC: sw          $zero, 0x1DB8($at)
    MEM_W(0X1DB8, ctx->r1) = 0;
    // 0x80080500: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80080508: sw          $s0, 0x1DBC($at)
    MEM_W(0X1DBC, ctx->r1) = ctx->r16;
    // 0x8008050C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80080510: jr          $ra
    // 0x80080514: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80080514: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void audspat_play_sound_at_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { extern int dkr_legacy_character_play_sound(uint8_t*, recomp_context*, unsigned); if (dkr_legacy_character_play_sound(rdram, ctx, 0U)) return; }
    // 0x80009558: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000955C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80009560: lhu         $t7, 0x3A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3A);
    // 0x80009564: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80009568: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000956C: lw          $t6, -0x63C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X63C0);
    // 0x80009570: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80009574: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80009578: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x8000957C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80009580: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80009584: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80009588: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8000958C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80009590: lbu         $t0, 0x3($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X3);
    // 0x80009594: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80009598: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8000959C: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x800095A0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800095A4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800095A8: lhu         $t2, 0x6($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X6);
    // 0x800095AC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800095B0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800095B4: lbu         $t3, 0x4($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4);
    // 0x800095B8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800095BC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800095C0: lbu         $t4, 0x8($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X8);
    // 0x800095C4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800095C8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800095CC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800095D0: jal         0x8000974C
    // 0x800095D4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    audspat_point_create(rdram, ctx);
        goto after_0;
    // 0x800095D4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_0:
    // 0x800095D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800095DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800095E0: jr          $ra
    // 0x800095E4: nop

    return;
    // 0x800095E4: nop

;}
RECOMP_FUNC void rain_render_splashes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD658: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800AD65C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AD660: lw          $t6, 0x2C8C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2C8C);
    // 0x800AD664: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800AD668: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AD66C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800AD670: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AD674: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800AD678: beq         $t6, $zero, L_800ADAA0
    if (ctx->r14 == 0) {
        // 0x800AD67C: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_800ADAA0;
    }
    // 0x800AD67C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800AD680: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AD684: lw          $t7, 0x2C6C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2C6C);
    // 0x800AD688: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AD68C: lw          $t9, 0x2C60($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2C60);
    // 0x800AD690: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x800AD694: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AD698: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AD69C: mflo        $v0
    ctx->r2 = lo;
    // 0x800AD6A0: sra         $t0, $v0, 14
    ctx->r8 = S32(SIGNED(ctx->r2) >> 14);
    // 0x800AD6A4: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
    // 0x800AD6A8: bne         $at, $zero, L_800AD9AC
    if (ctx->r1 != 0) {
        // 0x800AD6AC: nop
    
            goto L_800AD9AC;
    }
    // 0x800AD6AC: nop

    // 0x800AD6B0: jal         0x8001BB18
    // 0x800AD6B4: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    get_racer_object_by_port(rdram, ctx);
        goto after_0;
    // 0x800AD6B4: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_0:
    // 0x800AD6B8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AD6BC: addiu       $a2, $a2, 0x2C84
    ctx->r6 = ADD32(ctx->r6, 0X2C84);
    // 0x800AD6C0: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800AD6C4: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x800AD6C8: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800AD6CC: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800AD6D0: bgtz        $t3, L_800AD9AC
    if (SIGNED(ctx->r11) > 0) {
        // 0x800AD6D4: sw          $t3, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r11;
            goto L_800AD9AC;
    }
    // 0x800AD6D4: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800AD6D8: beq         $v0, $zero, L_800AD9AC
    if (ctx->r2 == 0) {
        // 0x800AD6DC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AD9AC;
    }
    // 0x800AD6DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AD6E0: sll         $t5, $zero, 3
    ctx->r13 = S32(0 << 3);
    // 0x800AD6E4: subu        $t5, $t5, $zero
    ctx->r13 = SUB32(ctx->r13, 0);
    // 0x800AD6E8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AD6EC: addiu       $t6, $t6, 0x2B4C
    ctx->r14 = ADD32(ctx->r14, 0X2B4C);
    // 0x800AD6F0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800AD6F4: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800AD6F8: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
L_800AD6FC:
    // 0x800AD6FC: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x800AD700: nop

    // 0x800AD704: bne         $t7, $zero, L_800AD710
    if (ctx->r15 != 0) {
        // 0x800AD708: nop
    
            goto L_800AD710;
    }
    // 0x800AD708: nop

    // 0x800AD70C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800AD710:
    // 0x800AD710: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AD714: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x800AD718: beq         $at, $zero, L_800AD728
    if (ctx->r1 == 0) {
        // 0x800AD71C: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800AD728;
    }
    // 0x800AD71C: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800AD720: bltz        $s1, L_800AD6FC
    if (SIGNED(ctx->r17) < 0) {
        // 0x800AD724: nop
    
            goto L_800AD6FC;
    }
    // 0x800AD724: nop

L_800AD728:
    // 0x800AD728: bltz        $s1, L_800AD9AC
    if (SIGNED(ctx->r17) < 0) {
        // 0x800AD72C: addiu       $a0, $zero, -0x2000
        ctx->r4 = ADD32(0, -0X2000);
            goto L_800AD9AC;
    }
    // 0x800AD72C: addiu       $a0, $zero, -0x2000
    ctx->r4 = ADD32(0, -0X2000);
    // 0x800AD730: jal         0x8006F94C
    // 0x800AD734: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800AD734: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    after_1:
    // 0x800AD738: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800AD73C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800AD740: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800AD744: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800AD748: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800AD74C: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x800AD750: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x800AD754: jal         0x8006F94C
    // 0x800AD758: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800AD758: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_2:
    // 0x800AD75C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800AD760: lh          $s0, 0x6E($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X6E);
    // 0x800AD764: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AD768: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800AD76C: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AD770: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800AD774: jal         0x800707C4
    // 0x800AD778: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x800AD778: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_3:
    // 0x800AD77C: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800AD780: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800AD784: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800AD788: lwc1        $f16, 0xC($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800AD78C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800AD790: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AD794: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AD798: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800AD79C: jal         0x800707F8
    // 0x800AD7A0: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    coss_f(rdram, ctx);
        goto after_4;
    // 0x800AD7A0: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x800AD7A4: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800AD7A8: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x800AD7AC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AD7B0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AD7B4: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800AD7B8: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800AD7BC: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AD7C0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800AD7C4: jal         0x80029F18
    // 0x800AD7C8: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x800AD7C8: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800AD7CC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800AD7D0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800AD7D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AD7D8: jal         0x8002B0F4
    // 0x800AD7DC: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    get_level_segment_waves(rdram, ctx);
        goto after_6;
    // 0x800AD7DC: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x800AD7E0: beq         $v0, $zero, L_800AD9AC
    if (ctx->r2 == 0) {
        // 0x800AD7E4: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_800AD9AC;
    }
    // 0x800AD7E4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800AD7E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800AD7EC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800AD7F0: bne         $at, $zero, L_800AD8A8
    if (ctx->r1 != 0) {
        // 0x800AD7F4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AD8A8;
    }
    // 0x800AD7F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AD7F8: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x800AD7FC: blez        $a0, L_800AD868
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800AD800: nop
    
            goto L_800AD868;
    }
    // 0x800AD800: nop

    // 0x800AD804: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800AD808: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800AD80C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AD810: lwc1        $f0, 0x10($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800AD814: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800AD818: nop

    // 0x800AD81C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800AD820: nop

    // 0x800AD824: bc1f        L_800AD868
    if (!c1cs) {
        // 0x800AD828: nop
    
            goto L_800AD868;
    }
    // 0x800AD828: nop

L_800AD82C:
    // 0x800AD82C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AD830: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800AD834: beq         $at, $zero, L_800AD868
    if (ctx->r1 == 0) {
        // 0x800AD838: nop
    
            goto L_800AD868;
    }
    // 0x800AD838: nop

    // 0x800AD83C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800AD840: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800AD844: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD848: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800AD84C: nop

    // 0x800AD850: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800AD854: nop

    // 0x800AD858: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800AD85C: nop

    // 0x800AD860: bc1t        L_800AD82C
    if (c1cs) {
        // 0x800AD864: nop
    
            goto L_800AD82C;
    }
    // 0x800AD864: nop

L_800AD868:
    // 0x800AD868: blez        $v1, L_800AD8A8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800AD86C: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_800AD8A8;
    }
    // 0x800AD86C: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800AD870: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800AD874: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800AD878: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AD87C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800AD880: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x800AD884: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800AD888: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AD88C: sub.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800AD890: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AD894: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800AD898: nop

    // 0x800AD89C: bc1f        L_800AD8A8
    if (!c1cs) {
        // 0x800AD8A0: nop
    
            goto L_800AD8A8;
    }
    // 0x800AD8A0: nop

    // 0x800AD8A4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_800AD8A8:
    // 0x800AD8A8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800AD8AC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800AD8B0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800AD8B4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800AD8B8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800AD8BC: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800AD8C0: lwc1        $f8, 0x10($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800AD8C4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AD8C8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AD8CC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AD8D0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800AD8D4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800AD8D8: bc1f        L_800AD8E4
    if (!c1cs) {
        // 0x800AD8DC: addiu       $t2, $t2, 0x2B4C
        ctx->r10 = ADD32(ctx->r10, 0X2B4C);
            goto L_800AD8E4;
    }
    // 0x800AD8DC: addiu       $t2, $t2, 0x2B4C
    ctx->r10 = ADD32(ctx->r10, 0X2B4C);
    // 0x800AD8E0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800AD8E4:
    // 0x800AD8E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AD8E8: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800AD8EC: bc1f        L_800AD918
    if (!c1cs) {
        // 0x800AD8F0: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800AD918;
    }
    // 0x800AD8F0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800AD8F4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800AD8F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD8FC: nop

    // 0x800AD900: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800AD904: nop

    // 0x800AD908: bc1f        L_800AD934
    if (!c1cs) {
        // 0x800AD90C: nop
    
            goto L_800AD934;
    }
    // 0x800AD90C: nop

    // 0x800AD910: b           L_800AD934
    // 0x800AD914: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
        goto L_800AD934;
    // 0x800AD914: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_800AD918:
    // 0x800AD918: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AD91C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AD920: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800AD924: nop

    // 0x800AD928: bc1f        L_800AD934
    if (!c1cs) {
        // 0x800AD92C: nop
    
            goto L_800AD934;
    }
    // 0x800AD92C: nop

    // 0x800AD930: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_800AD934:
    // 0x800AD934: bltz        $s1, L_800AD9AC
    if (SIGNED(ctx->r17) < 0) {
        // 0x800AD938: sll         $t1, $s1, 3
        ctx->r9 = S32(ctx->r17 << 3);
            goto L_800AD9AC;
    }
    // 0x800AD938: sll         $t1, $s1, 3
    ctx->r9 = S32(ctx->r17 << 3);
    // 0x800AD93C: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x800AD940: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800AD944: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x800AD948: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800AD94C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800AD950: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800AD954: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800AD958: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800AD95C: sra         $t5, $v1, 10
    ctx->r13 = S32(SIGNED(ctx->r3) >> 10);
    // 0x800AD960: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800AD964: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x800AD968: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800AD96C: addiu       $a1, $t5, 0xBF
    ctx->r5 = ADD32(ctx->r13, 0XBF);
    // 0x800AD970: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800AD974: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x800AD978: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x800AD97C: jal         0x8006F94C
    // 0x800AD980: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800AD980: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_7:
    // 0x800AD984: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD988: addiu       $a0, $a0, 0x2C84
    ctx->r4 = ADD32(ctx->r4, 0X2C84);
    // 0x800AD98C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800AD990: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800AD994: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // 0x800AD998: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x800AD99C: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x800AD9A0: bgez        $t8, L_800AD9AC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800AD9A4: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_800AD9AC;
    }
    // 0x800AD9A4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800AD9A8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800AD9AC:
    // 0x800AD9AC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AD9B0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800AD9B4: addiu       $s1, $s1, 0x7C0C
    ctx->r17 = ADD32(ctx->r17, 0X7C0C);
    // 0x800AD9B8: addiu       $s0, $s0, 0x2B4C
    ctx->r16 = ADD32(ctx->r16, 0X2B4C);
L_800AD9BC:
    // 0x800AD9BC: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AD9C0: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x800AD9C4: beq         $t0, $zero, L_800ADA70
    if (ctx->r8 == 0) {
        // 0x800AD9C8: nop
    
            goto L_800ADA70;
    }
    // 0x800AD9C8: nop

    // 0x800AD9CC: lh          $t1, 0x18($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X18);
    // 0x800AD9D0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800AD9D4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800AD9D8: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
    // 0x800AD9DC: lh          $t5, 0x18($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18);
    // 0x800AD9E0: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x800AD9E4: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x800AD9E8: bne         $at, $zero, L_800AD9F8
    if (ctx->r1 != 0) {
        // 0x800AD9EC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800AD9F8;
    }
    // 0x800AD9EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AD9F0: b           L_800ADA70
    // 0x800AD9F4: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
        goto L_800ADA70;
    // 0x800AD9F4: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
L_800AD9F8:
    // 0x800AD9F8: beq         $s2, $zero, L_800ADA20
    if (ctx->r18 == 0) {
        // 0x800AD9FC: lui         $at, 0xC0C0
        ctx->r1 = S32(0XC0C0 << 16);
            goto L_800ADA20;
    }
    // 0x800AD9FC: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x800ADA00: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800ADA04: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800ADA08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800ADA0C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800ADA10: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x800ADA14: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800ADA18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800ADA1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800ADA20:
    // 0x800ADA20: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800ADA24: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x800ADA28: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800ADA2C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800ADA30: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800ADA34: lh          $t2, 0x1A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A);
    // 0x800ADA38: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800ADA3C: andi        $t1, $t2, 0xFF
    ctx->r9 = ctx->r10 & 0XFF;
    // 0x800ADA40: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x800ADA44: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800ADA48: lw          $t4, 0x2C8C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2C8C);
    // 0x800ADA4C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800ADA50: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800ADA54: addiu       $t5, $zero, 0x10E
    ctx->r13 = ADD32(0, 0X10E);
    // 0x800ADA58: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800ADA5C: addiu       $a2, $a2, 0x7C14
    ctx->r6 = ADD32(ctx->r6, 0X7C14);
    // 0x800ADA60: addiu       $a1, $a1, 0x7C10
    ctx->r5 = ADD32(ctx->r5, 0X7C10);
    // 0x800ADA64: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800ADA68: jal         0x80068514
    // 0x800ADA6C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    render_sprite_billboard(rdram, ctx);
        goto after_8;
    // 0x800ADA6C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_8:
L_800ADA70:
    // 0x800ADA70: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADA74: addiu       $t6, $t6, 0x2C2C
    ctx->r14 = ADD32(ctx->r14, 0X2C2C);
    // 0x800ADA78: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800ADA7C: bne         $s0, $t6, L_800AD9BC
    if (ctx->r16 != ctx->r14) {
        // 0x800ADA80: nop
    
            goto L_800AD9BC;
    }
    // 0x800ADA80: nop

    // 0x800ADA84: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800ADA88: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800ADA8C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800ADA90: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800ADA94: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800ADA98: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800ADA9C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800ADAA0:
    // 0x800ADAA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800ADAA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800ADAA8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800ADAAC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800ADAB0: jr          $ra
    // 0x800ADAB4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800ADAB4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void init_particle_buffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE728: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800AE72C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AE730: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AE734: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AE738: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AE73C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE740: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800AE744: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800AE748: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800AE74C: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x800AE750: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AE754: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AE758: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AE75C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AE760: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AE764: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AE768: bgez        $a0, L_800AE774
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800AE76C: sw          $zero, 0x2D00($at)
        MEM_W(0X2D00, ctx->r1) = 0;
            goto L_800AE774;
    }
    // 0x800AE76C: sw          $zero, 0x2D00($at)
    MEM_W(0X2D00, ctx->r1) = 0;
    // 0x800AE770: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_800AE774:
    // 0x800AE774: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x800AE778: bgez        $s3, L_800AE784
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800AE77C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AE784;
    }
    // 0x800AE77C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE780: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_800AE784:
    // 0x800AE784: bgez        $s7, L_800AE790
    if (SIGNED(ctx->r23) >= 0) {
        // 0x800AE788: nop
    
            goto L_800AE790;
    }
    // 0x800AE788: nop

    // 0x800AE78C: addiu       $s7, $zero, 0xD0
    ctx->r23 = ADD32(0, 0XD0);
L_800AE790:
    // 0x800AE790: bgez        $s4, L_800AE79C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800AE794: nop
    
            goto L_800AE79C;
    }
    // 0x800AE794: nop

    // 0x800AE798: addiu       $s4, $zero, 0xA0
    ctx->r20 = ADD32(0, 0XA0);
L_800AE79C:
    // 0x800AE79C: bgez        $fp, L_800AE7A8
    if (SIGNED(ctx->r30) >= 0) {
        // 0x800AE7A0: nop
    
            goto L_800AE7A8;
    }
    // 0x800AE7A0: nop

    // 0x800AE7A4: addiu       $fp, $zero, 0x40
    ctx->r30 = ADD32(0, 0X40);
L_800AE7A8:
    // 0x800AE7A8: sw          $s1, 0x2E4C($at)
    MEM_W(0X2E4C, ctx->r1) = ctx->r17;
    // 0x800AE7AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7B0: sw          $zero, 0x2CA4($at)
    MEM_W(0X2CA4, ctx->r1) = 0;
    // 0x800AE7B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7B8: sw          $s3, 0x2E50($at)
    MEM_W(0X2E50, ctx->r1) = ctx->r19;
    // 0x800AE7BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7C0: sw          $zero, 0x2CB0($at)
    MEM_W(0X2CB0, ctx->r1) = 0;
    // 0x800AE7C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7C8: sw          $s7, 0x2E54($at)
    MEM_W(0X2E54, ctx->r1) = ctx->r23;
    // 0x800AE7CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7D0: sw          $zero, 0x2CBC($at)
    MEM_W(0X2CBC, ctx->r1) = 0;
    // 0x800AE7D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7D8: sw          $s4, 0x2E58($at)
    MEM_W(0X2E58, ctx->r1) = ctx->r20;
    // 0x800AE7DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7E0: sw          $zero, 0x2CC8($at)
    MEM_W(0X2CC8, ctx->r1) = 0;
    // 0x800AE7E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7E8: sw          $fp, 0x2E5C($at)
    MEM_W(0X2E5C, ctx->r1) = ctx->r30;
    // 0x800AE7EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE7F0: jal         0x800AE438
    // 0x800AE7F4: sw          $zero, 0x2CD4($at)
    MEM_W(0X2CD4, ctx->r1) = 0;
    free_particle_vertices_triangles(rdram, ctx);
        goto after_0;
    // 0x800AE7F4: sw          $zero, 0x2CD4($at)
    MEM_W(0X2CD4, ctx->r1) = 0;
    after_0:
    // 0x800AE7F8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800AE7FC: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x800AE800: subu        $t1, $t1, $s4
    ctx->r9 = SUB32(ctx->r9, ctx->r20);
    // 0x800AE804: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800AE808: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x800AE80C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AE810: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800AE814: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800AE818: sll         $t3, $fp, 4
    ctx->r11 = S32(ctx->r30 << 4);
    // 0x800AE81C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x800AE820: lui         $s2, 0x8080
    ctx->r18 = S32(0X8080 << 16);
    // 0x800AE824: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800AE828: ori         $s2, $s2, 0x8080
    ctx->r18 = ctx->r18 | 0X8080;
    // 0x800AE82C: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x800AE830: sll         $a0, $t4, 1
    ctx->r4 = S32(ctx->r12 << 1);
    // 0x800AE834: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800AE838: jal         0x80070C9C
    // 0x800AE83C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800AE83C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_1:
    // 0x800AE840: sll         $t5, $s3, 1
    ctx->r13 = S32(ctx->r19 << 1);
    // 0x800AE844: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x800AE848: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    // 0x800AE84C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE850: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800AE854: sw          $v0, 0x2CE0($at)
    MEM_W(0X2CE0, ctx->r1) = ctx->r2;
    // 0x800AE858: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800AE85C: jal         0x80070C9C
    // 0x800AE860: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800AE860: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800AE864: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AE868: addiu       $s0, $s0, 0x2CE4
    ctx->r16 = ADD32(ctx->r16, 0X2CE4);
    // 0x800AE86C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800AE870: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE874: jal         0x800AE374
    // 0x800AE878: sw          $zero, 0x2CDC($at)
    MEM_W(0X2CDC, ctx->r1) = 0;
    free_particle_buffers(rdram, ctx);
        goto after_3;
    // 0x800AE878: sw          $zero, 0x2CDC($at)
    MEM_W(0X2CDC, ctx->r1) = 0;
    after_3:
    // 0x800AE87C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AE880: lw          $t8, 0x2E4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2E4C);
    // 0x800AE884: nop

    // 0x800AE888: blez        $t8, L_800AE8AC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800AE88C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AE8AC;
    }
    // 0x800AE88C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE890: sw          $zero, 0x2CA0($at)
    MEM_W(0X2CA0, ctx->r1) = 0;
    // 0x800AE894: sll         $a0, $s1, 7
    ctx->r4 = S32(ctx->r17 << 7);
    // 0x800AE898: jal         0x80070C9C
    // 0x800AE89C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800AE89C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800AE8A0: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AE8A4: addiu       $s5, $s5, 0x2CA8
    ctx->r21 = ADD32(ctx->r21, 0X2CA8);
    // 0x800AE8A8: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
L_800AE8AC:
    // 0x800AE8AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AE8B0: lw          $t9, 0x2E50($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2E50);
    // 0x800AE8B4: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AE8B8: blez        $t9, L_800AE8E0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800AE8BC: addiu       $s5, $s5, 0x2CA8
        ctx->r21 = ADD32(ctx->r21, 0X2CA8);
            goto L_800AE8E0;
    }
    // 0x800AE8BC: addiu       $s5, $s5, 0x2CA8
    ctx->r21 = ADD32(ctx->r21, 0X2CA8);
    // 0x800AE8C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE8C4: sw          $zero, 0x2CAC($at)
    MEM_W(0X2CAC, ctx->r1) = 0;
    // 0x800AE8C8: sll         $a0, $s3, 7
    ctx->r4 = S32(ctx->r19 << 7);
    // 0x800AE8CC: jal         0x80070C9C
    // 0x800AE8D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800AE8D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x800AE8D4: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800AE8D8: addiu       $s6, $s6, 0x2CB4
    ctx->r22 = ADD32(ctx->r22, 0X2CB4);
    // 0x800AE8DC: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
L_800AE8E0:
    // 0x800AE8E0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AE8E4: lw          $t1, 0x2E54($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2E54);
    // 0x800AE8E8: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800AE8EC: blez        $t1, L_800AE918
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800AE8F0: addiu       $s6, $s6, 0x2CB4
        ctx->r22 = ADD32(ctx->r22, 0X2CB4);
            goto L_800AE918;
    }
    // 0x800AE8F0: addiu       $s6, $s6, 0x2CB4
    ctx->r22 = ADD32(ctx->r22, 0X2CB4);
    // 0x800AE8F4: sll         $a0, $s7, 3
    ctx->r4 = S32(ctx->r23 << 3);
    // 0x800AE8F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE8FC: subu        $a0, $a0, $s7
    ctx->r4 = SUB32(ctx->r4, ctx->r23);
    // 0x800AE900: sw          $zero, 0x2CB8($at)
    MEM_W(0X2CB8, ctx->r1) = 0;
    // 0x800AE904: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x800AE908: jal         0x80070C9C
    // 0x800AE90C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x800AE90C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x800AE910: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE914: sw          $v0, 0x2CC0($at)
    MEM_W(0X2CC0, ctx->r1) = ctx->r2;
L_800AE918:
    // 0x800AE918: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AE91C: lw          $t2, 0x2E58($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2E58);
    // 0x800AE920: nop

    // 0x800AE924: blez        $t2, L_800AE948
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AE928: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AE948;
    }
    // 0x800AE928: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE92C: sw          $zero, 0x2CC4($at)
    MEM_W(0X2CC4, ctx->r1) = 0;
    // 0x800AE930: sll         $a0, $s4, 7
    ctx->r4 = S32(ctx->r20 << 7);
    // 0x800AE934: jal         0x80070C9C
    // 0x800AE938: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x800AE938: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x800AE93C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AE940: addiu       $s7, $s7, 0x2CCC
    ctx->r23 = ADD32(ctx->r23, 0X2CCC);
    // 0x800AE944: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
L_800AE948:
    // 0x800AE948: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AE94C: lw          $t3, 0x2E5C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2E5C);
    // 0x800AE950: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AE954: blez        $t3, L_800AE984
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800AE958: addiu       $s7, $s7, 0x2CCC
        ctx->r23 = ADD32(ctx->r23, 0X2CCC);
            goto L_800AE984;
    }
    // 0x800AE958: addiu       $s7, $s7, 0x2CCC
    ctx->r23 = ADD32(ctx->r23, 0X2CCC);
    // 0x800AE95C: sll         $a0, $fp, 4
    ctx->r4 = S32(ctx->r30 << 4);
    // 0x800AE960: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE964: addu        $a0, $a0, $fp
    ctx->r4 = ADD32(ctx->r4, ctx->r30);
    // 0x800AE968: sw          $zero, 0x2CD0($at)
    MEM_W(0X2CD0, ctx->r1) = 0;
    // 0x800AE96C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800AE970: jal         0x80070C9C
    // 0x800AE974: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x800AE974: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x800AE978: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800AE97C: addiu       $fp, $fp, 0x2CD8
    ctx->r30 = ADD32(ctx->r30, 0X2CD8);
    // 0x800AE980: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
L_800AE984:
    // 0x800AE984: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AE988: lw          $v0, 0x2E4C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2E4C);
    // 0x800AE98C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AE990: lw          $t5, 0x2CE0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2CE0);
    // 0x800AE994: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800AE998: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800AE99C: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x800AE9A0: sll         $t4, $zero, 3
    ctx->r12 = S32(0 << 3);
    // 0x800AE9A4: sll         $t7, $zero, 4
    ctx->r15 = S32(0 << 4);
    // 0x800AE9A8: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800AE9AC: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800AE9B0: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800AE9B4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AE9B8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AE9BC: addiu       $fp, $fp, 0x2CD8
    ctx->r30 = ADD32(ctx->r30, 0X2CD8);
    // 0x800AE9C0: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x800AE9C4: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x800AE9C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AE9CC: blez        $v0, L_800AEA28
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AE9D0: addu        $s2, $t1, $t2
        ctx->r18 = ADD32(ctx->r9, ctx->r10);
            goto L_800AEA28;
    }
    // 0x800AE9D0: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x800AE9D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AE9D8: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x800AE9DC: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
L_800AE9E0:
    // 0x800AE9E0: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x800AE9E4: sll         $t3, $s1, 4
    ctx->r11 = S32(ctx->r17 << 4);
    // 0x800AE9E8: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800AE9EC: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800AE9F0: sw          $t4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r12;
    // 0x800AE9F4: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800AE9F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AE9FC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AEA00: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    // 0x800AEA04: jal         0x800AEE14
    // 0x800AEA08: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_triangle_particle_model(rdram, ctx);
        goto after_9;
    // 0x800AEA08: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_9:
    // 0x800AEA0C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AEA10: lw          $t9, 0x2E4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2E4C);
    // 0x800AEA14: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEA18: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AEA1C: bne         $at, $zero, L_800AE9E0
    if (ctx->r1 != 0) {
        // 0x800AEA20: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AE9E0;
    }
    // 0x800AEA20: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AEA24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEA28:
    // 0x800AEA28: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEA2C: addiu       $v1, $v1, 0x2E50
    ctx->r3 = ADD32(ctx->r3, 0X2E50);
    // 0x800AEA30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AEA34: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x800AEA38: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800AEA3C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800AEA40: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800AEA44: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
    // 0x800AEA48: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x800AEA4C: blez        $v0, L_800AEAA8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AEA50: addu        $s2, $t1, $t2
        ctx->r18 = ADD32(ctx->r9, ctx->r10);
            goto L_800AEAA8;
    }
    // 0x800AEA50: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x800AEA54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AEA58:
    // 0x800AEA58: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x800AEA5C: sll         $t3, $s1, 4
    ctx->r11 = S32(ctx->r17 << 4);
    // 0x800AEA60: addu        $t5, $t3, $s2
    ctx->r13 = ADD32(ctx->r11, ctx->r18);
    // 0x800AEA64: addu        $t6, $t4, $s0
    ctx->r14 = ADD32(ctx->r12, ctx->r16);
    // 0x800AEA68: sw          $t5, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r13;
    // 0x800AEA6C: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800AEA70: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AEA74: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AEA78: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    // 0x800AEA7C: jal         0x800AEEB8
    // 0x800AEA80: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_rectangle_particle_model(rdram, ctx);
        goto after_10;
    // 0x800AEA80: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_10:
    // 0x800AEA84: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AEA88: lw          $t9, 0x2E50($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2E50);
    // 0x800AEA8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEA90: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AEA94: bne         $at, $zero, L_800AEA58
    if (ctx->r1 != 0) {
        // 0x800AEA98: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AEA58;
    }
    // 0x800AEA98: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AEA9C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEAA0: addiu       $v1, $v1, 0x2E50
    ctx->r3 = ADD32(ctx->r3, 0X2E50);
    // 0x800AEAA4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEAA8:
    // 0x800AEAA8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AEAAC: addiu       $a3, $a3, 0x2E58
    ctx->r7 = ADD32(ctx->r7, 0X2E58);
    // 0x800AEAB0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800AEAB4: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800AEAB8: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800AEABC: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800AEAC0: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800AEAC4: blez        $v0, L_800AEB34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AEAC8: addu        $s2, $t1, $t2
        ctx->r18 = ADD32(ctx->r9, ctx->r10);
            goto L_800AEB34;
    }
    // 0x800AEAC8: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x800AEACC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AEAD0:
    // 0x800AEAD0: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x800AEAD4: sll         $t3, $s1, 4
    ctx->r11 = S32(ctx->r17 << 4);
    // 0x800AEAD8: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800AEADC: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800AEAE0: sw          $t4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r12;
    // 0x800AEAE4: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800AEAE8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AEAEC: addiu       $t7, $t7, 0x2D08
    ctx->r15 = ADD32(ctx->r15, 0X2D08);
    // 0x800AEAF0: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800AEAF4: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800AEAF8: lw          $a0, 0x44($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X44);
    // 0x800AEAFC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AEB00: jal         0x800AEF88
    // 0x800AEB04: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_line_particle_model(rdram, ctx);
        goto after_11;
    // 0x800AEB04: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_11:
    // 0x800AEB08: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AEB0C: lw          $t1, 0x2E58($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2E58);
    // 0x800AEB10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEB14: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AEB18: bne         $at, $zero, L_800AEAD0
    if (ctx->r1 != 0) {
        // 0x800AEB1C: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AEAD0;
    }
    // 0x800AEB1C: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AEB20: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AEB24: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEB28: addiu       $v1, $v1, 0x2E50
    ctx->r3 = ADD32(ctx->r3, 0X2E50);
    // 0x800AEB2C: addiu       $a3, $a3, 0x2E58
    ctx->r7 = ADD32(ctx->r7, 0X2E58);
    // 0x800AEB30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEB34:
    // 0x800AEB34: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AEB38: addiu       $t0, $t0, 0x2E5C
    ctx->r8 = ADD32(ctx->r8, 0X2E5C);
    // 0x800AEB3C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800AEB40: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800AEB44: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x800AEB48: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800AEB4C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800AEB50: blez        $v0, L_800AEBC8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AEB54: addu        $s2, $t2, $t3
        ctx->r18 = ADD32(ctx->r10, ctx->r11);
            goto L_800AEBC8;
    }
    // 0x800AEB54: addu        $s2, $t2, $t3
    ctx->r18 = ADD32(ctx->r10, ctx->r11);
    // 0x800AEB58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AEB5C:
    // 0x800AEB5C: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800AEB60: sll         $t5, $s1, 4
    ctx->r13 = S32(ctx->r17 << 4);
    // 0x800AEB64: addu        $t4, $t5, $s2
    ctx->r12 = ADD32(ctx->r13, ctx->r18);
    // 0x800AEB68: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800AEB6C: sw          $t4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r12;
    // 0x800AEB70: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800AEB74: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AEB78: addiu       $t8, $t8, 0x2D78
    ctx->r24 = ADD32(ctx->r24, 0X2D78);
    // 0x800AEB7C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800AEB80: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800AEB84: lw          $a0, 0x44($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X44);
    // 0x800AEB88: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AEB8C: jal         0x800AF024
    // 0x800AEB90: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_point_particle_model(rdram, ctx);
        goto after_12;
    // 0x800AEB90: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_12:
    // 0x800AEB94: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AEB98: lw          $t2, 0x2E5C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2E5C);
    // 0x800AEB9C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEBA0: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800AEBA4: bne         $at, $zero, L_800AEB5C
    if (ctx->r1 != 0) {
        // 0x800AEBA8: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_800AEB5C;
    }
    // 0x800AEBA8: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x800AEBAC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AEBB0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AEBB4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEBB8: addiu       $v1, $v1, 0x2E50
    ctx->r3 = ADD32(ctx->r3, 0X2E50);
    // 0x800AEBBC: addiu       $a3, $a3, 0x2E58
    ctx->r7 = ADD32(ctx->r7, 0X2E58);
    // 0x800AEBC0: addiu       $t0, $t0, 0x2E5C
    ctx->r8 = ADD32(ctx->r8, 0X2E5C);
    // 0x800AEBC4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEBC8:
    // 0x800AEBC8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AEBCC: lw          $t3, 0x2E4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2E4C);
    // 0x800AEBD0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AEBD4: blez        $t3, L_800AEC10
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800AEBD8: addiu       $s3, $s3, 0x2E60
        ctx->r19 = ADD32(ctx->r19, 0X2E60);
            goto L_800AEC10;
    }
    // 0x800AEBD8: addiu       $s3, $s3, 0x2E60
    ctx->r19 = ADD32(ctx->r19, 0X2E60);
    // 0x800AEBDC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AEBE0:
    // 0x800AEBE0: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x800AEBE4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AEBE8: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800AEBEC: sh          $zero, 0x2C($t6)
    MEM_H(0X2C, ctx->r14) = 0;
    // 0x800AEBF0: lw          $t4, 0x2E4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2E4C);
    // 0x800AEBF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEBF8: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AEBFC: bne         $at, $zero, L_800AEBE0
    if (ctx->r1 != 0) {
        // 0x800AEC00: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AEBE0;
    }
    // 0x800AEC00: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AEC04: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AEC08: addiu       $t0, $t0, 0x2E5C
    ctx->r8 = ADD32(ctx->r8, 0X2E5C);
    // 0x800AEC0C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEC10:
    // 0x800AEC10: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AEC14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AEC18: blez        $t7, L_800AEC50
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800AEC1C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800AEC50;
    }
    // 0x800AEC1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
L_800AEC20:
    // 0x800AEC20: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800AEC24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEC28: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800AEC2C: sh          $zero, 0x2C($t9)
    MEM_H(0X2C, ctx->r25) = 0;
    // 0x800AEC30: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800AEC34: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AEC38: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AEC3C: bne         $at, $zero, L_800AEC20
    if (ctx->r1 != 0) {
        // 0x800AEC40: nop
    
            goto L_800AEC20;
    }
    // 0x800AEC40: nop

    // 0x800AEC44: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AEC48: addiu       $t0, $t0, 0x2E5C
    ctx->r8 = ADD32(ctx->r8, 0X2E5C);
    // 0x800AEC4C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEC50:
    // 0x800AEC50: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEC54: addiu       $v1, $v1, 0x2E54
    ctx->r3 = ADD32(ctx->r3, 0X2E54);
    // 0x800AEC58: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800AEC5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AEC60: blez        $t2, L_800AEC98
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AEC64: addiu       $v0, $v0, 0x2CC0
        ctx->r2 = ADD32(ctx->r2, 0X2CC0);
            goto L_800AEC98;
    }
    // 0x800AEC64: addiu       $v0, $v0, 0x2CC0
    ctx->r2 = ADD32(ctx->r2, 0X2CC0);
L_800AEC68:
    // 0x800AEC68: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800AEC6C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEC70: addu        $t5, $t3, $s0
    ctx->r13 = ADD32(ctx->r11, ctx->r16);
    // 0x800AEC74: sh          $zero, 0x2C($t5)
    MEM_H(0X2C, ctx->r13) = 0;
    // 0x800AEC78: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AEC7C: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AEC80: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AEC84: bne         $at, $zero, L_800AEC68
    if (ctx->r1 != 0) {
        // 0x800AEC88: nop
    
            goto L_800AEC68;
    }
    // 0x800AEC88: nop

    // 0x800AEC8C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AEC90: addiu       $t0, $t0, 0x2E5C
    ctx->r8 = ADD32(ctx->r8, 0X2E5C);
    // 0x800AEC94: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEC98:
    // 0x800AEC98: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800AEC9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AECA0: blez        $t4, L_800AECD8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800AECA4: addiu       $a0, $zero, 0x2F
        ctx->r4 = ADD32(0, 0X2F);
            goto L_800AECD8;
    }
    // 0x800AECA4: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
L_800AECA8:
    // 0x800AECA8: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800AECAC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AECB0: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AECB4: sh          $zero, 0x2C($t8)
    MEM_H(0X2C, ctx->r24) = 0;
    // 0x800AECB8: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800AECBC: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AECC0: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AECC4: bne         $at, $zero, L_800AECA8
    if (ctx->r1 != 0) {
        // 0x800AECC8: nop
    
            goto L_800AECA8;
    }
    // 0x800AECC8: nop

    // 0x800AECCC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AECD0: addiu       $t0, $t0, 0x2E5C
    ctx->r8 = ADD32(ctx->r8, 0X2E5C);
    // 0x800AECD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AECD8:
    // 0x800AECD8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800AECDC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AECE0: blez        $t1, L_800AED0C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800AECE4: nop
    
            goto L_800AED0C;
    }
    // 0x800AECE4: nop

L_800AECE8:
    // 0x800AECE8: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800AECEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AECF0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800AECF4: sh          $zero, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = 0;
    // 0x800AECF8: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800AECFC: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x800AED00: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AED04: bne         $at, $zero, L_800AECE8
    if (ctx->r1 != 0) {
        // 0x800AED08: nop
    
            goto L_800AECE8;
    }
    // 0x800AED08: nop

L_800AED0C:
    // 0x800AED0C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800AED10: nop

    // 0x800AED14: bne         $t6, $zero, L_800AEDE8
    if (ctx->r14 != 0) {
        // 0x800AED18: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AEDE8;
    }
    // 0x800AED18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AED1C: jal         0x80076C58
    // 0x800AED20: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    asset_table_load(rdram, ctx);
        goto after_13;
    // 0x800AED20: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_13:
    // 0x800AED24: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AED28: addiu       $a2, $a2, 0x2E64
    ctx->r6 = ADD32(ctx->r6, 0X2E64);
    // 0x800AED2C: sll         $t4, $zero, 1
    ctx->r12 = S32(0 << 1);
    // 0x800AED30: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800AED34: addu        $t7, $v0, $t4
    ctx->r15 = ADD32(ctx->r2, ctx->r12);
    // 0x800AED38: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800AED3C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800AED40: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800AED44: beq         $a0, $t8, L_800AED6C
    if (ctx->r4 == ctx->r24) {
        // 0x800AED48: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AED6C;
    }
    // 0x800AED48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AED4C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AED50:
    // 0x800AED50: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800AED54: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x800AED58: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800AED5C: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x800AED60: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800AED64: bne         $a0, $t3, L_800AED50
    if (ctx->r4 != ctx->r11) {
        // 0x800AED68: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_800AED50;
    }
    // 0x800AED68: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AED6C:
    // 0x800AED6C: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800AED70: jal         0x80070C9C
    // 0x800AED74: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_14;
    // 0x800AED74: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_14:
    // 0x800AED78: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AED7C: addiu       $a2, $a2, 0x2E64
    ctx->r6 = ADD32(ctx->r6, 0X2E64);
    // 0x800AED80: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800AED84: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800AED88: blez        $t5, L_800AEDDC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800AED8C: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800AEDDC;
    }
    // 0x800AED8C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800AED90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800AED94:
    // 0x800AED94: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800AED98: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800AED9C: andi        $t6, $a0, 0x3FFF
    ctx->r14 = ctx->r4 & 0X3FFF;
    // 0x800AEDA0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800AEDA4: jal         0x8007C12C
    // 0x800AEDA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    tex_load_sprite(rdram, ctx);
        goto after_15;
    // 0x800AEDA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x800AEDAC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800AEDB0: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800AEDB4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AEDB8: addu        $t7, $t4, $v1
    ctx->r15 = ADD32(ctx->r12, ctx->r3);
    // 0x800AEDBC: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800AEDC0: addiu       $a2, $a2, 0x2E64
    ctx->r6 = ADD32(ctx->r6, 0X2E64);
    // 0x800AEDC4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800AEDC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEDCC: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AEDD0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800AEDD4: bne         $at, $zero, L_800AED94
    if (ctx->r1 != 0) {
        // 0x800AEDD8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800AED94;
    }
    // 0x800AEDD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800AEDDC:
    // 0x800AEDDC: jal         0x80071140
    // 0x800AEDE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_16;
    // 0x800AEDE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_16:
    // 0x800AEDE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800AEDE8:
    // 0x800AEDE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AEDEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AEDF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AEDF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AEDF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AEDFC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AEE00: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AEE04: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800AEE08: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800AEE0C: jr          $ra
    // 0x800AEE10: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AEE10: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void set_current_dialogue_box_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4EDC: blez        $a0, L_800C4F74
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C4EE0: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C4F74;
    }
    // 0x800C4EE0: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C4EE4: beq         $at, $zero, L_800C4F74
    if (ctx->r1 == 0) {
        // 0x800C4EE8: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C4F74;
    }
    // 0x800C4EE8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C4EEC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C4EF0: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C4EF4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C4EF8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C4EFC: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C4F00: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C4F04: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800C4F08: beq         $at, $zero, L_800C4F1C
    if (ctx->r1 == 0) {
        // 0x800C4F0C: sh          $zero, 0x2($v0)
        MEM_H(0X2, ctx->r2) = 0;
            goto L_800C4F1C;
    }
    // 0x800C4F0C: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800C4F10: sh          $a1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r5;
    // 0x800C4F14: b           L_800C4F24
    // 0x800C4F18: sh          $a3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r7;
        goto L_800C4F24;
    // 0x800C4F18: sh          $a3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r7;
L_800C4F1C:
    // 0x800C4F1C: sh          $a1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r5;
    // 0x800C4F20: sh          $a3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r7;
L_800C4F24:
    // 0x800C4F24: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800C4F28: nop

    // 0x800C4F2C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C4F30: beq         $at, $zero, L_800C4F44
    if (ctx->r1 == 0) {
        // 0x800C4F34: nop
    
            goto L_800C4F44;
    }
    // 0x800C4F34: nop

    // 0x800C4F38: sh          $a2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r6;
    // 0x800C4F3C: b           L_800C4F4C
    // 0x800C4F40: sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
        goto L_800C4F4C;
    // 0x800C4F40: sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
L_800C4F44:
    // 0x800C4F44: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
    // 0x800C4F48: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
L_800C4F4C:
    // 0x800C4F4C: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x800C4F50: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800C4F54: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x800C4F58: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x800C4F5C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800C4F60: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800C4F64: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C4F68: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C4F6C: sh          $t1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r9;
    // 0x800C4F70: sh          $t5, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r13;
L_800C4F74:
    // 0x800C4F74: jr          $ra
    // 0x800C4F78: nop

    return;
    // 0x800C4F78: nop

;}
RECOMP_FUNC void sins_f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800707C4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800707C8: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x800707CC: jal         0x80070830
    // 0x800707D0: nop

    sins_s16(rdram, ctx);
        goto after_0;
    // 0x800707D0: nop

    after_0:
    // 0x800707D4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800707D8: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x800707DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800707E0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800707E4: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x800707E8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800707EC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800707F0: jr          $ra
    // 0x800707F4: nop

    return;
    // 0x800707F4: nop

;}
RECOMP_FUNC void init_pulsating_light_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F414: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8007F418: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F41C: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x8007F420: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x8007F424: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x8007F428: blez        $v1, L_8007F458
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007F42C: sw          $t6, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r14;
            goto L_8007F458;
    }
    // 0x8007F42C: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8007F430: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8007F434: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x8007F438: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007F43C:
    // 0x8007F43C: lhu         $t8, 0x6($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6);
    // 0x8007F440: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x8007F444: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8007F448: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8007F44C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8007F450: bne         $at, $zero, L_8007F43C
    if (ctx->r1 != 0) {
        // 0x8007F454: sh          $t0, 0x6($a0)
        MEM_H(0X6, ctx->r4) = ctx->r8;
            goto L_8007F43C;
    }
    // 0x8007F454: sh          $t0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r8;
L_8007F458:
    // 0x8007F458: jr          $ra
    // 0x8007F45C: nop

    return;
    // 0x8007F45C: nop

;}
RECOMP_FUNC void si_mesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A100: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A104: jr          $ra
    // 0x8006A108: addiu       $v0, $v0, 0x10E0
    ctx->r2 = ADD32(ctx->r2, 0X10E0);
    return;
    // 0x8006A108: addiu       $v0, $v0, 0x10E0
    ctx->r2 = ADD32(ctx->r2, 0X10E0);
;}
RECOMP_FUNC void hud_treasure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A45F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A45F4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800A45F8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A45FC: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x800A4600: addiu       $s7, $s7, 0x6CDC
    ctx->r23 = ADD32(ctx->r23, 0X6CDC);
    // 0x800A4604: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A4608: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800A460C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A4610: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800A4614: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800A4618: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800A461C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800A4620: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A4624: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A4628: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A462C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A4630: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A4634: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A4638: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A463C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4640: lwc1        $f4, 0x410($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X410);
    // 0x800A4644: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A4648: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A464C: lbu         $v0, 0x6D37($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6D37);
    // 0x800A4650: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A4654: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A4658: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800A465C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800A4660: bne         $at, $zero, L_800A4684
    if (ctx->r1 != 0) {
        // 0x800A4664: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800A4684;
    }
    // 0x800A4664: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800A4668: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A466C: bne         $v0, $at, L_800A46CC
    if (ctx->r2 != ctx->r1) {
        // 0x800A4670: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_800A46CC;
    }
    // 0x800A4670: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800A4674: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800A4678: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A467C: bne         $t8, $at, L_800A46CC
    if (ctx->r24 != ctx->r1) {
        // 0x800A4680: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_800A46CC;
    }
    // 0x800A4680: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_800A4684:
    // 0x800A4684: lb          $t9, 0x3($s6)
    ctx->r25 = MEM_B(ctx->r22, 0X3);
    // 0x800A4688: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A468C: addiu       $t0, $t9, 0x38
    ctx->r8 = ADD32(ctx->r25, 0X38);
    // 0x800A4690: sh          $t0, 0x646($s1)
    MEM_H(0X646, ctx->r17) = ctx->r8;
    // 0x800A4694: lw          $a3, 0x0($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X0);
    // 0x800A4698: addiu       $s2, $s2, 0x6CD5
    ctx->r18 = ADD32(ctx->r18, 0X6CD5);
    // 0x800A469C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800A46A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A46A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A46A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A46AC: sb          $fp, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r30;
    // 0x800A46B0: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A46B4: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A46B8: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    { extern void dkr_legacy_character_hud_bind(uint8_t*, recomp_context*, uint32_t, uint32_t); dkr_legacy_character_hud_bind(rdram, ctx, (uint32_t)ctx->r7 + 1600U, (uint32_t)(ctx->r22)); }
    // 0x800A46BC: jal         0x800AA600
    // 0x800A46C0: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A46C0: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_0:
    { extern void dkr_legacy_character_hud_unbind(uint8_t*, recomp_context*); dkr_legacy_character_hud_unbind(rdram, ctx); }
    // 0x800A46C4: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800A46C8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_800A46CC:
    // 0x800A46CC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A46D0: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800A46D4: lui         $s3, 0x8080
    ctx->r19 = S32(0X8080 << 16);
    // 0x800A46D8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A46DC: addiu       $s2, $s2, 0x6CD5
    ctx->r18 = ADD32(ctx->r18, 0X6CD5);
    // 0x800A46E0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800A46E4: ori         $s3, $s3, 0x8080
    ctx->r19 = ctx->r19 | 0X8080;
    // 0x800A46E8: addiu       $s5, $s5, 0x2834
    ctx->r21 = ADD32(ctx->r21, 0X2834);
    // 0x800A46EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A46F0: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_800A46F4:
    // 0x800A46F4: lb          $t1, 0x193($s6)
    ctx->r9 = MEM_B(ctx->r22, 0X193);
    // 0x800A46F8: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800A46FC: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A4700: bne         $at, $zero, L_800A470C
    if (ctx->r1 != 0) {
        // 0x800A4704: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A470C;
    }
    // 0x800A4704: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4708: sw          $s3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r19;
L_800A470C:
    // 0x800A470C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4710: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4714: sb          $fp, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r30;
    // 0x800A4718: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A471C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A4720: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4724: jal         0x800AA600
    // 0x800A4728: addiu       $a3, $s1, 0x400
    ctx->r7 = ADD32(ctx->r17, 0X400);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A4728: addiu       $a3, $s1, 0x400
    ctx->r7 = ADD32(ctx->r17, 0X400);
    after_1:
    // 0x800A472C: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800A4730: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800A4734: lwc1        $f8, 0x410($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X410);
    // 0x800A4738: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A473C: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800A4740: bne         $s0, $s4, L_800A46F4
    if (ctx->r16 != ctx->r20) {
        // 0x800A4744: swc1        $f10, 0x410($s1)
        MEM_W(0X410, ctx->r17) = ctx->f10.u32l;
            goto L_800A46F4;
    }
    // 0x800A4744: swc1        $f10, 0x410($s1)
    MEM_W(0X410, ctx->r17) = ctx->f10.u32l;
    // 0x800A4748: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800A474C: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x800A4750: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800A4754: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x800A4758: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A475C: swc1        $f18, 0x410($t3)
    MEM_W(0X410, ctx->r11) = ctx->f18.u32l;
    // 0x800A4760: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800A4764: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x800A4768: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800A476C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A4770: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800A4774: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800A4778: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800A477C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800A4780: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A4784: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4788: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A478C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A4790: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A4794: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A4798: jr          $ra
    // 0x800A479C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A479C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void obj_loop_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038DC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038DCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038DD0: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80038DD4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038DD8: beq         $t6, $zero, L_80038E30
    if (ctx->r14 == 0) {
        // 0x80038DDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038E30;
    }
    // 0x80038DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038DE0: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038DE4: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80038DE8: lbu         $t8, 0x13($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X13);
    // 0x80038DEC: nop

    // 0x80038DF0: slti        $at, $t8, 0x78
    ctx->r1 = SIGNED(ctx->r24) < 0X78 ? 1 : 0;
    // 0x80038DF4: beq         $at, $zero, L_80038E30
    if (ctx->r1 == 0) {
        // 0x80038DF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038E30;
    }
    // 0x80038DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038DFC: lb          $a0, 0x8($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X8);
    // 0x80038E00: jal         0x8006F338
    // 0x80038E04: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    begin_level_teleport(rdram, ctx);
        goto after_0;
    // 0x80038E04: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80038E08: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80038E0C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80038E10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038E14: jal         0x80001D04
    // 0x80038E18: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80038E18: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    after_1:
    // 0x80038E1C: addiu       $a0, $zero, 0x12A
    ctx->r4 = ADD32(0, 0X12A);
    // 0x80038E20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038E24: jal         0x80000FDC
    // 0x80038E28: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_2;
    // 0x80038E28: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x80038E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038E30:
    // 0x80038E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038E34: jr          $ra
    // 0x80038E38: nop

    return;
    // 0x80038E38: nop

;}
RECOMP_FUNC void cutscene_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E440: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E444: lh          $v0, -0x5186($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5186);
    // 0x8001E448: jr          $ra
    // 0x8001E44C: nop

    return;
    // 0x8001E44C: nop

;}
RECOMP_FUNC void obj_init_texscroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800400A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800400A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800400AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800400B0: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x800400B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800400B8: jal         0x8002C7C4
    // 0x800400BC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x800400BC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800400C0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800400C4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800400C8: lh          $t6, 0x8($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X8);
    // 0x800400CC: nop

    // 0x800400D0: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800400D4: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800400D8: nop

    // 0x800400DC: bgez        $a0, L_800400F0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800400E0: nop
    
            goto L_800400F0;
    }
    // 0x800400E0: nop

    // 0x800400E4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800400E8: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800400EC: nop

L_800400F0:
    // 0x800400F0: lh          $a1, 0x18($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X18);
    // 0x800400F4: nop

    // 0x800400F8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800400FC: bne         $at, $zero, L_80040108
    if (ctx->r1 != 0) {
        // 0x80040100: addiu       $t7, $a1, -0x1
        ctx->r15 = ADD32(ctx->r5, -0X1);
            goto L_80040108;
    }
    // 0x80040100: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x80040104: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
L_80040108:
    // 0x80040108: lb          $t8, 0xA($a3)
    ctx->r24 = MEM_B(ctx->r7, 0XA);
    // 0x8004010C: nop

    // 0x80040110: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80040114: lb          $t9, 0xB($a3)
    ctx->r25 = MEM_B(ctx->r7, 0XB);
    // 0x80040118: nop

    // 0x8004011C: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x80040120: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80040124: nop

    // 0x80040128: bne         $t0, $zero, L_8004013C
    if (ctx->r8 != 0) {
        // 0x8004012C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004013C;
    }
    // 0x8004012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040130: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x80040134: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x80040138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004013C:
    // 0x8004013C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040140: jr          $ra
    // 0x80040144: nop

    return;
    // 0x80040144: nop

;}
RECOMP_FUNC void alAuxBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065900: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80065904: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80065908: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8006590C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80065910: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80065914: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80065918: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006591C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80065920: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80065924: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80065928: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x8006592C: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x80065930: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80065934: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x80065938: ori         $t6, $t6, 0x6C0
    ctx->r14 = ctx->r14 | 0X6C0;
    // 0x8006593C: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x80065940: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80065944: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80065948: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
    // 0x8006594C: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80065950: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x80065954: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80065958: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8006595C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80065960: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80065964: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065968: blez        $t8, L_800659A8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8006596C: addiu       $s2, $s1, 0x10
        ctx->r18 = ADD32(ctx->r17, 0X10);
            goto L_800659A8;
    }
    // 0x8006596C: addiu       $s2, $s1, 0x10
    ctx->r18 = ADD32(ctx->r17, 0X10);
    // 0x80065970: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_80065974:
    // 0x80065974: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80065978: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8006597C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80065980: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80065984: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80065988: jalr        $t9
    // 0x8006598C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8006598C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_0:
    // 0x80065990: lw          $t0, 0x14($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X14);
    // 0x80065994: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065998: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006599C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800659A0: bne         $at, $zero, L_80065974
    if (ctx->r1 != 0) {
        // 0x800659A4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80065974;
    }
    // 0x800659A4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800659A8:
    // 0x800659A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800659AC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800659B0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800659B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800659B8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800659BC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800659C0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800659C4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800659C8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800659CC: jr          $ra
    // 0x800659D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800659D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void transition_init_shape(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0B00: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C0B04: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800C0B08: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x800C0B0C: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x800C0B10: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800C0B14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C0B18: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C0B1C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C0B20: sll         $t0, $a2, 4
    ctx->r8 = S32(ctx->r6 << 4);
    // 0x800C0B24: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C0B28: addu        $t6, $v1, $t0
    ctx->r14 = ADD32(ctx->r3, ctx->r8);
    // 0x800C0B2C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800C0B30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C0B34: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C0B38: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C0B3C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800C0B40: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x800C0B44: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800C0B48: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800C0B4C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800C0B50: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800C0B54: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C0B58: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800C0B5C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800C0B60: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800C0B64: jal         0x80070C9C
    // 0x800C0B68: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C0B68: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x800C0B6C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800C0B70: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C0B74: addiu       $a0, $a0, 0x31C0
    ctx->r4 = ADD32(ctx->r4, 0X31C0);
    // 0x800C0B78: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C0B7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0B80: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x800C0B84: sw          $t4, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r12;
    // 0x800C0B88: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x800C0B8C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C0B90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0B94: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800C0B98: addiu       $a1, $a1, 0x31C8
    ctx->r5 = ADD32(ctx->r5, 0X31C8);
    // 0x800C0B9C: sw          $t6, 0x31C8($at)
    MEM_W(0X31C8, ctx->r1) = ctx->r14;
    // 0x800C0BA0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C0BA4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800C0BA8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C0BAC: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x800C0BB0: sw          $t8, 0x31CC($at)
    MEM_W(0X31CC, ctx->r1) = ctx->r24;
    // 0x800C0BB4: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800C0BB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0BBC: addu        $t4, $t9, $t0
    ctx->r12 = ADD32(ctx->r25, ctx->r8);
    // 0x800C0BC0: addiu       $a2, $a2, -0x5890
    ctx->r6 = ADD32(ctx->r6, -0X5890);
    // 0x800C0BC4: sw          $t4, -0x5890($at)
    MEM_W(-0X5890, ctx->r1) = ctx->r12;
    // 0x800C0BC8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C0BCC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C0BD0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C0BD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0BD8: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x800C0BDC: addiu       $t3, $t3, -0x588C
    ctx->r11 = ADD32(ctx->r11, -0X588C);
    // 0x800C0BE0: sw          $t6, -0x588C($at)
    MEM_W(-0X588C, ctx->r1) = ctx->r14;
    // 0x800C0BE4: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800C0BE8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800C0BEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0BF0: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x800C0BF4: sw          $t8, -0x5888($at)
    MEM_W(-0X5888, ctx->r1) = ctx->r24;
    // 0x800C0BF8: lbu         $t4, 0x0($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X0);
    // 0x800C0BFC: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800C0C00: andi        $t5, $t4, 0x80
    ctx->r13 = ctx->r12 & 0X80;
    // 0x800C0C04: beq         $t5, $zero, L_800C0C28
    if (ctx->r13 == 0) {
        // 0x800C0C08: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800C0C28;
    }
    // 0x800C0C08: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C0C0C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800C0C10: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800C0C14: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800C0C18: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800C0C1C: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800C0C20: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800C0C24: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
L_800C0C28:
    // 0x800C0C28: blez        $s0, L_800C0E5C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800C0C2C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800C0E5C;
    }
    // 0x800C0C2C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800C0C30: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C0C34: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800C0C38: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800C0C3C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800C0C40: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800C0C44: addiu       $v1, $v1, -0x5888
    ctx->r3 = ADD32(ctx->r3, -0X5888);
    // 0x800C0C48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0C4C: addiu       $t1, $t1, 0x31B0
    ctx->r9 = ADD32(ctx->r9, 0X31B0);
L_800C0C50:
    // 0x800C0C50: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0C54: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C0C58: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C0C5C: addu        $t4, $s2, $t9
    ctx->r12 = ADD32(ctx->r18, ctx->r25);
    // 0x800C0C60: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800C0C64: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C0C68: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C0C6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0C70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C0C74: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x800C0C78: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0C7C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C0C80: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C0C84: addu        $t4, $s2, $t9
    ctx->r12 = ADD32(ctx->r18, ctx->r25);
    // 0x800C0C88: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x800C0C8C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C0C90: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800C0C94: nop

    // 0x800C0C98: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C0C9C: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x800C0CA0: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x800C0CA4: nop

    // 0x800C0CA8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800C0CAC: bgez        $t8, L_800C0CC0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C0CB0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800C0CC0;
    }
    // 0x800C0CB0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C0CB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C0CB8: nop

    // 0x800C0CBC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800C0CC0:
    // 0x800C0CC0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C0CC4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0CC8: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C0CCC: swc1        $f18, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f18.u32l;
    // 0x800C0CD0: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x800C0CD4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C0CD8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800C0CDC: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x800C0CE0: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800C0CE4: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C0CE8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800C0CEC: nop

    // 0x800C0CF0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C0CF4: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x800C0CF8: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x800C0CFC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C0D00: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800C0D04: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x800C0D08: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800C0D0C: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C0D10: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800C0D14: nop

    // 0x800C0D18: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C0D1C: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x800C0D20: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800C0D24: nop

    // 0x800C0D28: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C0D2C: bgez        $t5, L_800C0D40
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C0D30: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C0D40;
    }
    // 0x800C0D30: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C0D34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C0D38: nop

    // 0x800C0D3C: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_800C0D40:
    // 0x800C0D40: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C0D44: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0D48: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C0D4C: swc1        $f18, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f18.u32l;
    // 0x800C0D50: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C0D54: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C0D58: lhu         $t6, 0x0($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X0);
    // 0x800C0D5C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C0D60: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C0D64: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800C0D68: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800C0D6C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800C0D70: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C0D74: bgez        $t6, L_800C0D88
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800C0D78: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C0D88;
    }
    // 0x800C0D78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C0D7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C0D80: nop

    // 0x800C0D84: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_800C0D88:
    // 0x800C0D88: nop

    // 0x800C0D8C: div.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800C0D90: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800C0D94: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0D98: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0D9C: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x800C0DA0: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C0DA4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C0DA8: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x800C0DAC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C0DB0: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C0DB4: lwc1        $f10, 0x4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C0DB8: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800C0DBC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800C0DC0: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800C0DC4: bgez        $t7, L_800C0DD8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C0DC8: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800C0DD8;
    }
    // 0x800C0DC8: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C0DCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C0DD0: nop

    // 0x800C0DD4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800C0DD8:
    // 0x800C0DD8: nop

    // 0x800C0DDC: div.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800C0DE0: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800C0DE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0DE8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C0DEC: swc1        $f10, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f10.u32l;
    // 0x800C0DF0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C0DF4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C0DF8: lhu         $t8, 0x0($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X0);
    // 0x800C0DFC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C0E00: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C0E04: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x800C0E08: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C0E0C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800C0E10: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800C0E14: bgez        $t8, L_800C0E28
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C0E18: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800C0E28;
    }
    // 0x800C0E18: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C0E1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C0E20: nop

    // 0x800C0E24: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800C0E28:
    // 0x800C0E28: nop

    // 0x800C0E2C: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C0E30: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800C0E34: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C0E38: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C0E3C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C0E40: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C0E44: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C0E48: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C0E4C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C0E50: bne         $t2, $s0, L_800C0C50
    if (ctx->r10 != ctx->r16) {
        // 0x800C0E54: swc1        $f4, 0x8($t4)
        MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
            goto L_800C0C50;
    }
    // 0x800C0E54: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
    // 0x800C0E58: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_800C0E5C:
    // 0x800C0E5C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C0E60: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C0E64: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C0E68: addiu       $a2, $a2, -0x58CC
    ctx->r6 = ADD32(ctx->r6, -0X58CC);
    // 0x800C0E6C: addiu       $a3, $a3, -0x58CB
    ctx->r7 = ADD32(ctx->r7, -0X58CB);
    // 0x800C0E70: addiu       $t0, $t0, -0x58CA
    ctx->r8 = ADD32(ctx->r8, -0X58CA);
    // 0x800C0E74: addiu       $a0, $zero, -0x10
    ctx->r4 = ADD32(0, -0X10);
L_800C0E78:
    // 0x800C0E78: blez        $s0, L_800C1010
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800C0E7C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800C1010;
    }
    // 0x800C0E7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C0E80: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C0E84: addiu       $t6, $t6, 0x31C0
    ctx->r14 = ADD32(ctx->r14, 0X31C0);
    // 0x800C0E88: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x800C0E8C: andi        $t3, $s0, 0x3
    ctx->r11 = ctx->r16 & 0X3;
    // 0x800C0E90: beq         $t3, $zero, L_800C0EF0
    if (ctx->r11 == 0) {
        // 0x800C0E94: addu        $v1, $t5, $t6
        ctx->r3 = ADD32(ctx->r13, ctx->r14);
            goto L_800C0EF0;
    }
    // 0x800C0E94: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x800C0E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0E9C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C0EA0: or          $t1, $t3, $zero
    ctx->r9 = ctx->r11 | 0;
L_800C0EA4:
    // 0x800C0EA4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C0EA8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C0EAC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0EB0: sh          $a0, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r4;
    // 0x800C0EB4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C0EB8: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800C0EBC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C0EC0: sb          $t9, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r25;
    // 0x800C0EC4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C0EC8: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x800C0ECC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0ED0: sb          $t6, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r14;
    // 0x800C0ED4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C0ED8: lbu         $t4, 0x0($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X0);
    // 0x800C0EDC: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C0EE0: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800C0EE4: bne         $t1, $a1, L_800C0EA4
    if (ctx->r9 != ctx->r5) {
        // 0x800C0EE8: sb          $t4, 0x8($t5)
        MEM_B(0X8, ctx->r13) = ctx->r12;
            goto L_800C0EA4;
    }
    // 0x800C0EE8: sb          $t4, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r12;
    // 0x800C0EEC: beq         $a1, $s0, L_800C1010
    if (ctx->r5 == ctx->r16) {
        // 0x800C0EF0: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_800C1010;
    }
L_800C0EF0:
    // 0x800C0EF0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800C0EF4: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800C0EF8: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x800C0EFC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C0F00: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C0F04: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
L_800C0F08:
    // 0x800C0F08: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C0F0C: nop

    // 0x800C0F10: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0F14: sh          $a0, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r4;
    // 0x800C0F18: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C0F1C: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x800C0F20: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C0F24: sb          $t8, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r24;
    // 0x800C0F28: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C0F2C: lbu         $t5, 0x0($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X0);
    // 0x800C0F30: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0F34: sb          $t5, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r13;
    // 0x800C0F38: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C0F3C: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x800C0F40: addu        $t4, $t8, $v0
    ctx->r12 = ADD32(ctx->r24, ctx->r2);
    // 0x800C0F44: sb          $t9, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r25;
    // 0x800C0F48: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C0F4C: nop

    // 0x800C0F50: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0F54: sh          $a0, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r4;
    // 0x800C0F58: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C0F5C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800C0F60: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C0F64: sb          $t6, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r14;
    // 0x800C0F68: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C0F6C: lbu         $t4, 0x0($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X0);
    // 0x800C0F70: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0F74: sb          $t4, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r12;
    // 0x800C0F78: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C0F7C: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x800C0F80: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800C0F84: sb          $t8, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r24;
    // 0x800C0F88: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C0F8C: nop

    // 0x800C0F90: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0F94: sh          $a0, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r4;
    // 0x800C0F98: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C0F9C: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x800C0FA0: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800C0FA4: sb          $t5, 0x1A($t8)
    MEM_B(0X1A, ctx->r24) = ctx->r13;
    // 0x800C0FA8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C0FAC: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x800C0FB0: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0FB4: sb          $t9, 0x1B($t4)
    MEM_B(0X1B, ctx->r12) = ctx->r25;
    // 0x800C0FB8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C0FBC: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x800C0FC0: addu        $t8, $t5, $v0
    ctx->r24 = ADD32(ctx->r13, ctx->r2);
    // 0x800C0FC4: sb          $t6, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r14;
    // 0x800C0FC8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C0FCC: nop

    // 0x800C0FD0: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0FD4: sh          $a0, 0x22($t9)
    MEM_H(0X22, ctx->r25) = ctx->r4;
    // 0x800C0FD8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C0FDC: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x800C0FE0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C0FE4: sb          $t4, 0x24($t6)
    MEM_B(0X24, ctx->r14) = ctx->r12;
    // 0x800C0FE8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C0FEC: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x800C0FF0: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C0FF4: sb          $t8, 0x25($t9)
    MEM_B(0X25, ctx->r25) = ctx->r24;
    // 0x800C0FF8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C0FFC: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800C1000: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1004: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800C1008: bne         $v0, $t1, L_800C0F08
    if (ctx->r2 != ctx->r9) {
        // 0x800C100C: sb          $t5, 0x26($t6)
        MEM_B(0X26, ctx->r14) = ctx->r13;
            goto L_800C0F08;
    }
    // 0x800C100C: sb          $t5, 0x26($t6)
    MEM_B(0X26, ctx->r14) = ctx->r13;
L_800C1010:
    // 0x800C1010: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C1014: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800C1018: bne         $at, $zero, L_800C0E78
    if (ctx->r1 != 0) {
        // 0x800C101C: nop
    
            goto L_800C0E78;
    }
    // 0x800C101C: nop

    // 0x800C1020: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800C1024: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800C1028: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C102C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
L_800C1030:
    // 0x800C1030: blez        $s1, L_800C10F8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800C1034: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800C10F8;
    }
    // 0x800C1034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C1038: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C103C: addiu       $t8, $t8, 0x31C8
    ctx->r24 = ADD32(ctx->r24, 0X31C8);
    // 0x800C1040: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800C1044: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800C1048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C104C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800C1050:
    // 0x800C1050: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1054: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C1058: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C105C: sb          $a2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r6;
    // 0x800C1060: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1064: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1068: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C106C: sb          $t5, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r13;
    // 0x800C1070: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C1074: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800C1078: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C107C: sh          $zero, 0x4($t9)
    MEM_H(0X4, ctx->r25) = 0;
    // 0x800C1080: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1084: nop

    // 0x800C1088: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C108C: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    // 0x800C1090: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1094: lbu         $t5, -0x2($a0)
    ctx->r13 = MEM_BU(ctx->r4, -0X2);
    // 0x800C1098: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C109C: sb          $t5, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r13;
    // 0x800C10A0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C10A4: nop

    // 0x800C10A8: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C10AC: sh          $zero, 0x8($t4)
    MEM_H(0X8, ctx->r12) = 0;
    // 0x800C10B0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C10B4: nop

    // 0x800C10B8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C10BC: sh          $zero, 0xA($t7)
    MEM_H(0XA, ctx->r15) = 0;
    // 0x800C10C0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C10C4: lbu         $t5, -0x1($a0)
    ctx->r13 = MEM_BU(ctx->r4, -0X1);
    // 0x800C10C8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C10CC: sb          $t5, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r13;
    // 0x800C10D0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C10D4: nop

    // 0x800C10D8: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C10DC: sh          $zero, 0xC($t6)
    MEM_H(0XC, ctx->r14) = 0;
    // 0x800C10E0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C10E4: nop

    // 0x800C10E8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C10EC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C10F0: bne         $a1, $s1, L_800C1050
    if (ctx->r5 != ctx->r17) {
        // 0x800C10F4: sh          $zero, 0xE($t8)
        MEM_H(0XE, ctx->r24) = 0;
            goto L_800C1050;
    }
    // 0x800C10F4: sh          $zero, 0xE($t8)
    MEM_H(0XE, ctx->r24) = 0;
L_800C10F8:
    // 0x800C10F8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C10FC: bne         $t2, $t0, L_800C1030
    if (ctx->r10 != ctx->r8) {
        // 0x800C1100: nop
    
            goto L_800C1030;
    }
    // 0x800C1100: nop

    // 0x800C1104: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800C1108: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C110C: sw          $t5, 0x31AC($at)
    MEM_W(0X31AC, ctx->r1) = ctx->r13;
    // 0x800C1110: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C1118: sw          $s0, -0x5884($at)
    MEM_W(-0X5884, ctx->r1) = ctx->r16;
    // 0x800C111C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C1120: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1124: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C1128: jr          $ra
    // 0x800C112C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C112C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void get_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E948: bltz        $a0, L_8000E964
    if (SIGNED(ctx->r4) < 0) {
        // 0x8000E94C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8000E964;
    }
    // 0x8000E94C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E950: lw          $t6, -0x51A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X51A4);
    // 0x8000E954: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000E958: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000E95C: bne         $at, $zero, L_8000E96C
    if (ctx->r1 != 0) {
        // 0x8000E960: nop
    
            goto L_8000E96C;
    }
    // 0x8000E960: nop

L_8000E964:
    // 0x8000E964: jr          $ra
    // 0x8000E968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000E968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E96C:
    // 0x8000E96C: lw          $t7, -0x51A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X51A8);
    // 0x8000E970: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8000E974: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8000E978: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000E97C: nop

    // 0x8000E980: jr          $ra
    // 0x8000E984: nop

    return;
    // 0x8000E984: nop

;}
RECOMP_FUNC void move_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011570: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80011574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011578: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8001157C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80011580: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80011584: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80011588: jal         0x8002C7C4
    // 0x8001158C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x8001158C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80011590: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80011594: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80011598: lwc1        $f14, 0x10($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001159C: lwc1        $f2, 0xC($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800115A0: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x800115A4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800115A8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800115AC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800115B0: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800115B4: add.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800115B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800115BC: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800115C0: bne         $v0, $zero, L_800115D8
    if (ctx->r2 != 0) {
        // 0x800115C4: swc1        $f4, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
            goto L_800115D8;
    }
    // 0x800115C4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800115C8: addiu       $a0, $a0, -0x37B8
    ctx->r4 = ADD32(ctx->r4, -0X37B8);
    // 0x800115CC: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x800115D0: b           L_80011950
    // 0x800115D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011950;
    // 0x800115D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800115D8:
    // 0x800115D8: lh          $t6, 0x3E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3E);
    // 0x800115DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800115E0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800115E4: lwc1        $f13, 0x5538($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X5538);
    // 0x800115E8: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800115EC: lwc1        $f12, 0x553C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X553C);
    // 0x800115F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800115F4: add.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d + ctx->f12.d;
    // 0x800115F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800115FC: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80011600: addiu       $a0, $a0, -0x37B8
    ctx->r4 = ADD32(ctx->r4, -0X37B8);
    // 0x80011604: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80011608: nop

    // 0x8001160C: bc1f        L_80011618
    if (!c1cs) {
        // 0x80011610: nop
    
            goto L_80011618;
    }
    // 0x80011610: nop

    // 0x80011614: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011618:
    // 0x80011618: lh          $t7, 0x3C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3C);
    // 0x8001161C: nop

    // 0x80011620: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80011624: nop

    // 0x80011628: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8001162C: sub.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f6.d - ctx->f12.d;
    // 0x80011630: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80011634: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80011638: nop

    // 0x8001163C: bc1f        L_80011648
    if (!c1cs) {
        // 0x80011640: nop
    
            goto L_80011648;
    }
    // 0x80011640: nop

    // 0x80011644: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011648:
    // 0x80011648: lh          $t8, 0x42($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X42);
    // 0x8001164C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011650: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80011654: lwc1        $f7, 0x5540($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5540);
    // 0x80011658: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8001165C: lwc1        $f6, 0x5544($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5544);
    // 0x80011660: nop

    // 0x80011664: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80011668: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x8001166C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80011670: nop

    // 0x80011674: bc1f        L_80011680
    if (!c1cs) {
        // 0x80011678: nop
    
            goto L_80011680;
    }
    // 0x80011678: nop

    // 0x8001167C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011680:
    // 0x80011680: lh          $t9, 0x40($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X40);
    // 0x80011684: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011688: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8001168C: lwc1        $f7, 0x5548($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5548);
    // 0x80011690: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x80011694: lwc1        $f6, 0x554C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X554C);
    // 0x80011698: nop

    // 0x8001169C: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x800116A0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800116A4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800116A8: nop

    // 0x800116AC: bc1f        L_800116B8
    if (!c1cs) {
        // 0x800116B0: nop
    
            goto L_800116B8;
    }
    // 0x800116B0: nop

    // 0x800116B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800116B8:
    // 0x800116B8: lh          $t1, 0x46($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X46);
    // 0x800116BC: nop

    // 0x800116C0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800116C4: nop

    // 0x800116C8: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x800116CC: add.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d + ctx->f12.d;
    // 0x800116D0: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800116D4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800116D8: nop

    // 0x800116DC: bc1f        L_800116E8
    if (!c1cs) {
        // 0x800116E0: nop
    
            goto L_800116E8;
    }
    // 0x800116E0: nop

    // 0x800116E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800116E8:
    // 0x800116E8: lh          $t2, 0x44($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X44);
    // 0x800116EC: nop

    // 0x800116F0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800116F4: nop

    // 0x800116F8: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800116FC: sub.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f10.d - ctx->f12.d;
    // 0x80011700: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x80011704: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80011708: nop

    // 0x8001170C: bc1f        L_80011718
    if (!c1cs) {
        // 0x80011710: nop
    
            goto L_80011718;
    }
    // 0x80011710: nop

    // 0x80011714: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011718:
    // 0x80011718: lb          $t3, 0x0($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X0);
    // 0x8001171C: nop

    // 0x80011720: beq         $t3, $zero, L_8001172C
    if (ctx->r11 == 0) {
        // 0x80011724: nop
    
            goto L_8001172C;
    }
    // 0x80011724: nop

    // 0x80011728: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001172C:
    // 0x8001172C: beq         $v1, $zero, L_80011744
    if (ctx->r3 == 0) {
        // 0x80011730: sb          $zero, 0x0($a0)
        MEM_B(0X0, ctx->r4) = 0;
            goto L_80011744;
    }
    // 0x80011730: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80011734: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80011738: sh          $t4, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r12;
    // 0x8001173C: b           L_80011950
    // 0x80011740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80011950;
    // 0x80011740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80011744:
    // 0x80011744: swc1        $f18, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f18.u32l;
    // 0x80011748: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001174C: lh          $a0, 0x2E($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X2E);
    // 0x80011750: swc1        $f6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f6.u32l;
    // 0x80011754: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80011758: nop

    // 0x8001175C: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    // 0x80011760: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80011764: jal         0x8002A2DC
    // 0x80011768: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    block_boundbox(rdram, ctx);
        goto after_1;
    // 0x80011768: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_1:
    // 0x8001176C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80011770: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80011774: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80011778: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001177C: bne         $v0, $zero, L_80011834
    if (ctx->r2 != 0) {
        // 0x80011780: nop
    
            goto L_80011834;
    }
    // 0x80011780: nop

    // 0x80011784: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80011788: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8001178C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80011790: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011794: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011798: nop

    // 0x8001179C: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800117A0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800117A4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800117A8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800117AC: nop

    // 0x800117B0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800117B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800117B8: nop

    // 0x800117BC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800117C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800117C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800117C8: nop

    // 0x800117CC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800117D0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800117D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800117D8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800117DC: nop

    // 0x800117E0: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800117E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800117E8: nop

    // 0x800117EC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800117F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800117F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800117F8: nop

    // 0x800117FC: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80011800: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80011804: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80011808: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8001180C: nop

    // 0x80011810: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011814: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80011818: jal         0x80029F18
    // 0x8001181C: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_2;
    // 0x8001181C: nop

    after_2:
    // 0x80011820: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80011824: nop

    // 0x80011828: sh          $v0, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r2;
    // 0x8001182C: b           L_80011950
    // 0x80011830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011950;
    // 0x80011830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011834:
    // 0x80011834: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80011838: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8001183C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80011840: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011844: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001184C: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80011850: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80011854: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80011858: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001185C: bne         $at, $zero, L_80011878
    if (ctx->r1 != 0) {
        // 0x80011860: nop
    
            goto L_80011878;
    }
    // 0x80011860: nop

    // 0x80011864: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80011868: nop

    // 0x8001186C: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80011870: beq         $at, $zero, L_8001187C
    if (ctx->r1 == 0) {
        // 0x80011874: nop
    
            goto L_8001187C;
    }
    // 0x80011874: nop

L_80011878:
    // 0x80011878: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001187C:
    // 0x8001187C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80011880: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80011884: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80011888: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001188C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011890: nop

    // 0x80011894: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80011898: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8001189C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800118A0: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800118A4: bne         $at, $zero, L_800118C0
    if (ctx->r1 != 0) {
        // 0x800118A8: nop
    
            goto L_800118C0;
    }
    // 0x800118A8: nop

    // 0x800118AC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800118B0: nop

    // 0x800118B4: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800118B8: beq         $at, $zero, L_800118C4
    if (ctx->r1 == 0) {
        // 0x800118BC: nop
    
            goto L_800118C4;
    }
    // 0x800118BC: nop

L_800118C0:
    // 0x800118C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800118C4:
    // 0x800118C4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800118C8: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x800118CC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800118D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800118D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800118D8: nop

    // 0x800118DC: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800118E0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800118E4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800118E8: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800118EC: bne         $at, $zero, L_80011908
    if (ctx->r1 != 0) {
        // 0x800118F0: nop
    
            goto L_80011908;
    }
    // 0x800118F0: nop

    // 0x800118F4: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x800118F8: nop

    // 0x800118FC: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011900: beq         $at, $zero, L_8001190C
    if (ctx->r1 == 0) {
        // 0x80011904: nop
    
            goto L_8001190C;
    }
    // 0x80011904: nop

L_80011908:
    // 0x80011908: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001190C:
    // 0x8001190C: beq         $a0, $zero, L_80011950
    if (ctx->r4 == 0) {
        // 0x80011910: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80011950;
    }
    // 0x80011910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011914: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80011918: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8001191C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80011920: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80011924: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80011928: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8001192C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011930: jal         0x80029F18
    // 0x80011934: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    get_level_segment_index_from_position(rdram, ctx);
        goto after_3;
    // 0x80011934: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_3:
    // 0x80011938: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8001193C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80011940: beq         $v0, $at, L_8001194C
    if (ctx->r2 == ctx->r1) {
        // 0x80011944: nop
    
            goto L_8001194C;
    }
    // 0x80011944: nop

    // 0x80011948: sh          $v0, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r2;
L_8001194C:
    // 0x8001194C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011950:
    // 0x80011950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011954: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80011958: jr          $ra
    // 0x8001195C: nop

    return;
    // 0x8001195C: nop

;}
RECOMP_FUNC void hud_audio_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0BD4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A0BD8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A0BDC: addiu       $v1, $v1, 0x6D74
    ctx->r3 = ADD32(ctx->r3, 0X6D74);
    // 0x800A0BE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A0BE4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A0BE8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800A0BEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A0BF0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A0BF4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A0BF8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A0BFC: blez        $v0, L_800A0C34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A0C00: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800A0C34;
    }
    // 0x800A0C00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A0C04: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800A0C08: bgtz        $t6, L_800A0C34
    if (SIGNED(ctx->r14) > 0) {
        // 0x800A0C0C: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_800A0C34;
    }
    // 0x800A0C0C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800A0C10: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0C14: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    // 0x800A0C18: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800A0C1C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800A0C20: bne         $t8, $zero, L_800A0C34
    if (ctx->r24 != 0) {
        // 0x800A0C24: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A0C34;
    }
    // 0x800A0C24: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0C28: lhu         $a0, 0x6D7C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X6D7C);
    // 0x800A0C2C: jal         0x80001D04
    // 0x800A0C30: nop

    sound_play(rdram, ctx);
        goto after_0;
    // 0x800A0C30: nop

    after_0:
L_800A0C34:
    // 0x800A0C34: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800A0C38: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800A0C3C: addiu       $s3, $s3, 0x2790
    ctx->r19 = ADD32(ctx->r19, 0X2790);
    // 0x800A0C40: addiu       $s0, $s0, 0x2770
    ctx->r16 = ADD32(ctx->r16, 0X2770);
    // 0x800A0C44: addiu       $s4, $zero, 0x7F
    ctx->r20 = ADD32(0, 0X7F);
    // 0x800A0C48: addiu       $s2, $zero, 0x7F
    ctx->r18 = ADD32(0, 0X7F);
L_800A0C4C:
    // 0x800A0C4C: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800A0C50: nop

    // 0x800A0C54: beq         $a2, $zero, L_800A0D08
    if (ctx->r6 == 0) {
        // 0x800A0C58: nop
    
            goto L_800A0D08;
    }
    // 0x800A0C58: nop

    // 0x800A0C5C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800A0C60: nop

    // 0x800A0C64: bne         $a1, $zero, L_800A0C84
    if (ctx->r5 != 0) {
        // 0x800A0C68: nop
    
            goto L_800A0C84;
    }
    // 0x800A0C68: nop

    // 0x800A0C6C: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800A0C70: jal         0x80001D04
    // 0x800A0C74: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800A0C74: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x800A0C78: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800A0C7C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800A0C80: nop

L_800A0C84:
    // 0x800A0C84: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800A0C88: jal         0x80001FB8
    // 0x800A0C8C: nop

    sound_volume_set_relative(rdram, ctx);
        goto after_2;
    // 0x800A0C8C: nop

    after_2:
    // 0x800A0C90: lb          $a0, 0x3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X3);
    // 0x800A0C94: nop

    // 0x800A0C98: blez        $a0, L_800A0CD0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800A0C9C: nop
    
            goto L_800A0CD0;
    }
    // 0x800A0C9C: nop

    // 0x800A0CA0: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A0CA4: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x800A0CA8: mflo        $v0
    ctx->r2 = lo;
    // 0x800A0CAC: subu        $t9, $s2, $v0
    ctx->r25 = SUB32(ctx->r18, ctx->r2);
    // 0x800A0CB0: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A0CB4: bne         $at, $zero, L_800A0CC4
    if (ctx->r1 != 0) {
        // 0x800A0CB8: addu        $t0, $v1, $v0
        ctx->r8 = ADD32(ctx->r3, ctx->r2);
            goto L_800A0CC4;
    }
    // 0x800A0CB8: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x800A0CBC: b           L_800A0D24
    // 0x800A0CC0: sb          $t0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r8;
        goto L_800A0D24;
    // 0x800A0CC0: sb          $t0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r8;
L_800A0CC4:
    // 0x800A0CC4: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800A0CC8: b           L_800A0D24
    // 0x800A0CCC: sb          $s4, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r20;
        goto L_800A0D24;
    // 0x800A0CCC: sb          $s4, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r20;
L_800A0CD0:
    // 0x800A0CD0: bgez        $a0, L_800A0D24
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800A0CD4: nop
    
            goto L_800A0D24;
    }
    // 0x800A0CD4: nop

    // 0x800A0CD8: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A0CDC: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x800A0CE0: mflo        $v0
    ctx->r2 = lo;
    // 0x800A0CE4: negu        $t1, $v0
    ctx->r9 = SUB32(0, ctx->r2);
    // 0x800A0CE8: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A0CEC: beq         $at, $zero, L_800A0CFC
    if (ctx->r1 == 0) {
        // 0x800A0CF0: addu        $t2, $v1, $v0
        ctx->r10 = ADD32(ctx->r3, ctx->r2);
            goto L_800A0CFC;
    }
    // 0x800A0CF0: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x800A0CF4: b           L_800A0D24
    // 0x800A0CF8: sb          $t2, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r10;
        goto L_800A0D24;
    // 0x800A0CF8: sb          $t2, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r10;
L_800A0CFC:
    // 0x800A0CFC: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800A0D00: b           L_800A0D24
    // 0x800A0D04: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
        goto L_800A0D24;
    // 0x800A0D04: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
L_800A0D08:
    // 0x800A0D08: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800A0D0C: nop

    // 0x800A0D10: beq         $a1, $zero, L_800A0D24
    if (ctx->r5 == 0) {
        // 0x800A0D14: nop
    
            goto L_800A0D24;
    }
    // 0x800A0D14: nop

    // 0x800A0D18: jal         0x8000488C
    // 0x800A0D1C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    sndp_stop(rdram, ctx);
        goto after_3;
    // 0x800A0D1C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x800A0D20: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800A0D24:
    // 0x800A0D24: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800A0D28: bne         $s0, $s3, L_800A0C4C
    if (ctx->r16 != ctx->r19) {
        // 0x800A0D2C: nop
    
            goto L_800A0C4C;
    }
    // 0x800A0D2C: nop

    // 0x800A0D30: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A0D34: addiu       $v1, $v1, 0x6D70
    ctx->r3 = ADD32(ctx->r3, 0X6D70);
    // 0x800A0D38: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x800A0D3C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800A0D40: beq         $t3, $zero, L_800A0DA4
    if (ctx->r11 == 0) {
        // 0x800A0D44: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A0DA4;
    }
    // 0x800A0D44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0D48: lbu         $t4, 0x2772($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X2772);
    // 0x800A0D4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0D50: bne         $t4, $zero, L_800A0DA4
    if (ctx->r12 != 0) {
        // 0x800A0D54: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A0DA4;
    }
    // 0x800A0D54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0D58: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800A0D5C: lbu         $v0, 0x6D37($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6D37);
    // 0x800A0D60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0D64: bne         $v0, $at, L_800A0D80
    if (ctx->r2 != ctx->r1) {
        // 0x800A0D68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A0D80;
    }
    // 0x800A0D68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A0D6C: jal         0x8000318C
    // 0x800A0D70: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_4;
    // 0x800A0D70: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
    // 0x800A0D74: b           L_800A0DA4
    // 0x800A0D78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800A0DA4;
    // 0x800A0D78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0D7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800A0D80:
    // 0x800A0D80: bne         $v0, $at, L_800A0D98
    if (ctx->r2 != ctx->r1) {
        // 0x800A0D84: nop
    
            goto L_800A0D98;
    }
    // 0x800A0D84: nop

    // 0x800A0D88: jal         0x8000318C
    // 0x800A0D8C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_5;
    // 0x800A0D8C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_5:
    // 0x800A0D90: b           L_800A0DA4
    // 0x800A0D94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800A0DA4;
    // 0x800A0D94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800A0D98:
    // 0x800A0D98: jal         0x8000318C
    // 0x800A0D9C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_6;
    // 0x800A0D9C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_6:
    // 0x800A0DA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800A0DA4:
    // 0x800A0DA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A0DA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A0DAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A0DB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A0DB4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A0DB8: jr          $ra
    // 0x800A0DBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A0DBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void reset_title_logo_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800813C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800813C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800813C8: jr          $ra
    // 0x800813CC: sw          $t6, -0xBA8($at)
    MEM_W(-0XBA8, ctx->r1) = ctx->r14;
    return;
    // 0x800813CC: sw          $t6, -0xBA8($at)
    MEM_W(-0XBA8, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void obj_animate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061D30: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061D34: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x80061D38: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x80061D3C: lb          $t0, 0x3A($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X3A);
    // 0x80061D40: bgezl       $t0, L_80061D50
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80061D44: lw          $t1, 0x40($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X40);
            goto L_80061D50;
    }
    goto skip_0;
    // 0x80061D44: lw          $t1, 0x40($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X40);
    skip_0:
    // 0x80061D48: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80061D4C: lw          $t1, 0x40($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X40);
L_80061D50:
    // 0x80061D50: lb          $t2, 0x55($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X55);
    // 0x80061D54: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80061D58: bnel        $at, $zero, L_80061D68
    if (ctx->r1 != 0) {
        // 0x80061D5C: lw          $t1, 0x68($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X68);
            goto L_80061D68;
    }
    goto skip_1;
    // 0x80061D5C: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    skip_1:
    // 0x80061D60: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80061D64: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
L_80061D68:
    // 0x80061D68: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80061D6C: add         $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80061D70: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80061D74: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80061D78: lw          $t0, 0x44($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X44);
    // 0x80061D7C: bnel        $t0, $zero, L_80061D90
    if (ctx->r8 != 0) {
        // 0x80061D80: lh          $t9, 0x18($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X18);
            goto L_80061D90;
    }
    goto skip_2;
    // 0x80061D80: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
    skip_2:
    // 0x80061D84: b           L_8006227C
    // 0x80061D88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006227C;
    // 0x80061D88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061D8C: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
L_80061D90:
    // 0x80061D90: lh          $t0, 0x14($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X14);
    // 0x80061D94: lb          $a3, 0x3B($a0)
    ctx->r7 = MEM_B(ctx->r4, 0X3B);
    // 0x80061D98: bne         $t9, $t0, L_80061DB4
    if (ctx->r25 != ctx->r8) {
        // 0x80061D9C: nop
    
            goto L_80061DB4;
    }
    // 0x80061D9C: nop

    // 0x80061DA0: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x80061DA4: bne         $a3, $t0, L_80061DB4
    if (ctx->r7 != ctx->r8) {
        // 0x80061DA8: nop
    
            goto L_80061DB4;
    }
    // 0x80061DA8: nop

    // 0x80061DAC: b           L_8006227C
    // 0x80061DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006227C;
    // 0x80061DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061DB4:
    // 0x80061DB4: bgezl       $a3, L_80061DC4
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80061DB8: lh          $t0, 0x48($a2)
        ctx->r8 = MEM_H(ctx->r6, 0X48);
            goto L_80061DC4;
    }
    goto skip_3;
    // 0x80061DB8: lh          $t0, 0x48($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X48);
    skip_3:
    // 0x80061DBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80061DC0: lh          $t0, 0x48($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X48);
L_80061DC4:
    // 0x80061DC4: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80061DC8: bne         $at, $zero, L_80061DD4
    if (ctx->r1 != 0) {
        // 0x80061DCC: nop
    
            goto L_80061DD4;
    }
    // 0x80061DCC: nop

    // 0x80061DD0: addiu       $a3, $t0, -0x1
    ctx->r7 = ADD32(ctx->r8, -0X1);
L_80061DD4:
    // 0x80061DD4: blez        $t0, L_80061DF0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80061DD8: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80061DF0;
    }
    // 0x80061DD8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80061DDC: lw          $t1, 0x44($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X44);
    // 0x80061DE0: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x80061DE4: add         $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80061DE8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80061DEC: addi        $t2, $t2, -0x2
    ctx->r10 = ADD32(ctx->r10, -0X2);
L_80061DF0:
    // 0x80061DF0: srl         $a0, $t9, 4
    ctx->r4 = S32(U32(ctx->r25) >> 4);
    // 0x80061DF4: bgezl       $a0, L_80061E08
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80061DF8: slt         $at, $t2, $a0
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80061E08;
    }
    goto skip_4;
    // 0x80061DF8: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    skip_4:
    // 0x80061DFC: or          $t9, $t2, $zero
    ctx->r25 = ctx->r10 | 0;
    // 0x80061E00: srl         $a0, $t2, 4
    ctx->r4 = S32(U32(ctx->r10) >> 4);
    // 0x80061E04: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
L_80061E08:
    // 0x80061E08: beql        $at, $zero, L_80061E24
    if (ctx->r1 == 0) {
        // 0x80061E0C: lh          $t0, 0x10($a1)
        ctx->r8 = MEM_H(ctx->r5, 0X10);
            goto L_80061E24;
    }
    goto skip_5;
    // 0x80061E0C: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    skip_5:
    // 0x80061E10: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80061E14: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80061E18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80061E1C: sh          $t0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r8;
    // 0x80061E20: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
L_80061E24:
    // 0x80061E24: lw          $s1, 0xC($a1)
    ctx->r17 = MEM_W(ctx->r5, 0XC);
    // 0x80061E28: beql        $a3, $t0, L_80061E3C
    if (ctx->r7 == ctx->r8) {
        // 0x80061E2C: lh          $s0, 0x12($a1)
        ctx->r16 = MEM_H(ctx->r5, 0X12);
            goto L_80061E3C;
    }
    goto skip_6;
    // 0x80061E2C: lh          $s0, 0x12($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X12);
    skip_6:
    // 0x80061E30: b           L_80061E3C
    // 0x80061E34: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_80061E3C;
    // 0x80061E34: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80061E38: lh          $s0, 0x12($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X12);
L_80061E3C:
    // 0x80061E3C: sh          $a3, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r7;
    // 0x80061E40: sh          $t9, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r25;
    // 0x80061E44: sh          $a0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r4;
    // 0x80061E48: beq         $a0, $zero, L_80061E64
    if (ctx->r4 == 0) {
        // 0x80061E4C: andi        $t8, $t9, 0xF
        ctx->r24 = ctx->r25 & 0XF;
            goto L_80061E64;
    }
    // 0x80061E4C: andi        $t8, $t9, 0xF
    ctx->r24 = ctx->r25 & 0XF;
    // 0x80061E50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80061E54: beql        $s0, $at, L_80061E68
    if (ctx->r16 == ctx->r1) {
        // 0x80061E58: lw          $v0, 0x44($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X44);
            goto L_80061E68;
    }
    goto skip_7;
    // 0x80061E58: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    skip_7:
    // 0x80061E5C: b           L_80061EF8
    // 0x80061E60: lh          $v1, 0x4A($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X4A);
        goto L_80061EF8;
    // 0x80061E60: lh          $v1, 0x4A($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X4A);
L_80061E64:
    // 0x80061E64: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
L_80061E68:
    // 0x80061E68: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80061E6C: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x80061E70: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80061E74: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80061E78: lh          $v0, 0x24($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X24);
    // 0x80061E7C: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x80061E80: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80061E84: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80061E88: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_80061E8C:
    // 0x80061E8C: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x80061E90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80061E94: beql        $v0, $at, L_80061EE4
    if (ctx->r2 == ctx->r1) {
        // 0x80061E98: addiu       $t5, $t5, 0x2
        ctx->r13 = ADD32(ctx->r13, 0X2);
            goto L_80061EE4;
    }
    goto skip_8;
    // 0x80061E98: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    skip_8:
    // 0x80061E9C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80061EA0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80061EA4: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80061EA8: add         $v1, $s1, $v0
    ctx->r3 = ADD32(ctx->r17, ctx->r2);
    // 0x80061EAC: add         $v0, $t6, $v0
    ctx->r2 = ADD32(ctx->r14, ctx->r2);
    // 0x80061EB0: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x80061EB4: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80061EB8: add         $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061EBC: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x80061EC0: lh          $t0, 0x2($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X2);
    // 0x80061EC4: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80061EC8: add         $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061ECC: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    // 0x80061ED0: lh          $t0, 0x4($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X4);
    // 0x80061ED4: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x80061ED8: add         $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061EDC: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x80061EE0: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
L_80061EE4:
    // 0x80061EE4: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061EE8: bne         $at, $zero, L_80061E8C
    if (ctx->r1 != 0) {
        // 0x80061EEC: addiu       $t7, $t7, 0xA
        ctx->r15 = ADD32(ctx->r15, 0XA);
            goto L_80061E8C;
    }
    // 0x80061EEC: addiu       $t7, $t7, 0xA
    ctx->r15 = ADD32(ctx->r15, 0XA);
    // 0x80061EF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80061EF4: lh          $v1, 0x4A($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X4A);
L_80061EF8:
    // 0x80061EF8: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80061EFC: add         $v0, $v1, $v1
    ctx->r2 = ADD32(ctx->r3, ctx->r3);
    // 0x80061F00: add         $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x80061F04: beq         $at, $zero, L_80061FA0
    if (ctx->r1 == 0) {
        // 0x80061F08: addiu       $t4, $t4, 0xC
        ctx->r12 = ADD32(ctx->r12, 0XC);
            goto L_80061FA0;
    }
    // 0x80061F08: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80061F0C: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x80061F10: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80061F14: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80061F18: addiu       $v1, $s0, 0x2
    ctx->r3 = ADD32(ctx->r16, 0X2);
    // 0x80061F1C: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061F20: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80061F24: mflo        $v1
    ctx->r3 = lo;
    // 0x80061F28: add         $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80061F2C: nop

    // 0x80061F30: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
L_80061F34:
    // 0x80061F34: or          $t6, $t2, $zero
    ctx->r14 = ctx->r10 | 0;
    // 0x80061F38: or          $t5, $s1, $zero
    ctx->r13 = ctx->r17 | 0;
    // 0x80061F3C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80061F40: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80061F44: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80061F48: add         $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x80061F4C: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_80061F50:
    // 0x80061F50: lh          $t0, 0x0($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X0);
    // 0x80061F54: lb          $t1, 0x0($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X0);
    // 0x80061F58: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x80061F5C: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061F60: add         $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80061F64: sh          $t0, -0x6($t5)
    MEM_H(-0X6, ctx->r13) = ctx->r8;
    // 0x80061F68: lh          $t0, -0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X4);
    // 0x80061F6C: lb          $t1, 0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X1);
    // 0x80061F70: addiu       $t6, $t6, 0x3
    ctx->r14 = ADD32(ctx->r14, 0X3);
    // 0x80061F74: add         $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80061F78: sh          $t0, -0x4($t5)
    MEM_H(-0X4, ctx->r13) = ctx->r8;
    // 0x80061F7C: lh          $t0, -0x2($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X2);
    // 0x80061F80: lb          $t1, -0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, -0X1);
    // 0x80061F84: add         $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80061F88: bne         $at, $zero, L_80061F50
    if (ctx->r1 != 0) {
        // 0x80061F8C: sh          $t0, -0x2($t5)
        MEM_H(-0X2, ctx->r13) = ctx->r8;
            goto L_80061F50;
    }
    // 0x80061F8C: sh          $t0, -0x2($t5)
    MEM_H(-0X2, ctx->r13) = ctx->r8;
    // 0x80061F90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80061F94: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80061F98: bnel        $at, $zero, L_80061F34
    if (ctx->r1 != 0) {
        // 0x80061F9C: lh          $v0, 0x4A($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X4A);
            goto L_80061F34;
    }
    goto skip_9;
    // 0x80061F9C: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
    skip_9:
L_80061FA0:
    // 0x80061FA0: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80061FA4: beql        $at, $zero, L_80062044
    if (ctx->r1 == 0) {
        // 0x80061FA8: lw          $v0, 0x44($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X44);
            goto L_80062044;
    }
    goto skip_10;
    // 0x80061FA8: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    skip_10:
    // 0x80061FAC: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x80061FB0: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80061FB4: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80061FB8: addiu       $v1, $s0, 0x2
    ctx->r3 = ADD32(ctx->r16, 0X2);
    // 0x80061FBC: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061FC0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80061FC4: mflo        $v1
    ctx->r3 = lo;
    // 0x80061FC8: add         $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80061FCC: nop

    // 0x80061FD0: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
L_80061FD4:
    // 0x80061FD4: sub         $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x80061FD8: or          $t5, $s1, $zero
    ctx->r13 = ctx->r17 | 0;
    // 0x80061FDC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80061FE0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80061FE4: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80061FE8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80061FEC: or          $t6, $t2, $zero
    ctx->r14 = ctx->r10 | 0;
    // 0x80061FF0: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_80061FF4:
    // 0x80061FF4: lh          $t0, 0x0($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X0);
    // 0x80061FF8: lb          $t1, 0x0($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X0);
    // 0x80061FFC: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x80062000: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80062004: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80062008: sh          $t0, -0x6($t5)
    MEM_H(-0X6, ctx->r13) = ctx->r8;
    // 0x8006200C: lh          $t0, -0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X4);
    // 0x80062010: lb          $t1, 0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X1);
    // 0x80062014: addiu       $t6, $t6, 0x3
    ctx->r14 = ADD32(ctx->r14, 0X3);
    // 0x80062018: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8006201C: sh          $t0, -0x4($t5)
    MEM_H(-0X4, ctx->r13) = ctx->r8;
    // 0x80062020: lh          $t0, -0x2($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X2);
    // 0x80062024: lb          $t1, -0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, -0X1);
    // 0x80062028: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8006202C: bne         $at, $zero, L_80061FF4
    if (ctx->r1 != 0) {
        // 0x80062030: sh          $t0, -0x2($t5)
        MEM_H(-0X2, ctx->r13) = ctx->r8;
            goto L_80061FF4;
    }
    // 0x80062030: sh          $t0, -0x2($t5)
    MEM_H(-0X2, ctx->r13) = ctx->r8;
    // 0x80062034: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80062038: bnel        $at, $zero, L_80061FD4
    if (ctx->r1 != 0) {
        // 0x8006203C: lh          $v0, 0x4A($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X4A);
            goto L_80061FD4;
    }
    goto skip_11;
    // 0x8006203C: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
    skip_11:
    // 0x80062040: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
L_80062044:
    // 0x80062044: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80062048: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006204C: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062050: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80062054: addiu       $v0, $s0, 0x2
    ctx->r2 = ADD32(ctx->r16, 0X2);
    // 0x80062058: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006205C: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
    // 0x80062060: lw          $t5, -0x29BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X29BC);
    // 0x80062064: mflo        $v1
    ctx->r3 = lo;
    // 0x80062068: add         $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8006206C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80062070: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80062074: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062078: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_8006207C:
    // 0x8006207C: lb          $t0, 0x0($t6)
    ctx->r8 = MEM_B(ctx->r14, 0X0);
    // 0x80062080: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x80062084: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80062088: multu       $t0, $t8
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006208C: addiu       $t6, $t6, 0x3
    ctx->r14 = ADD32(ctx->r14, 0X3);
    // 0x80062090: mflo        $t0
    ctx->r8 = lo;
    // 0x80062094: srl         $t0, $t0, 4
    ctx->r8 = S32(U32(ctx->r8) >> 4);
    // 0x80062098: sh          $t0, -0x6($t5)
    MEM_H(-0X6, ctx->r13) = ctx->r8;
    // 0x8006209C: lb          $t1, -0x2($t6)
    ctx->r9 = MEM_B(ctx->r14, -0X2);
    // 0x800620A0: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800620A4: mflo        $t1
    ctx->r9 = lo;
    // 0x800620A8: srl         $t1, $t1, 4
    ctx->r9 = S32(U32(ctx->r9) >> 4);
    // 0x800620AC: sh          $t1, -0x4($t5)
    MEM_H(-0X4, ctx->r13) = ctx->r9;
    // 0x800620B0: lb          $t2, -0x1($t6)
    ctx->r10 = MEM_B(ctx->r14, -0X1);
    // 0x800620B4: multu       $t2, $t8
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800620B8: mflo        $t2
    ctx->r10 = lo;
    // 0x800620BC: srl         $t2, $t2, 4
    ctx->r10 = S32(U32(ctx->r10) >> 4);
    // 0x800620C0: bne         $at, $zero, L_8006207C
    if (ctx->r1 != 0) {
        // 0x800620C4: sh          $t2, -0x2($t5)
        MEM_H(-0X2, ctx->r13) = ctx->r10;
            goto L_8006207C;
    }
    // 0x800620C4: sh          $t2, -0x2($t5)
    MEM_H(-0X2, ctx->r13) = ctx->r10;
    // 0x800620C8: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x800620CC: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x800620D0: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800620D4: beq         $a0, $zero, L_800620F0
    if (ctx->r4 == 0) {
        // 0x800620D8: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_800620F0;
    }
    // 0x800620D8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800620DC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800620E0: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800620E4: mflo        $v1
    ctx->r3 = lo;
    // 0x800620E8: add         $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800620EC: addiu       $t6, $t6, -0xC
    ctx->r14 = ADD32(ctx->r14, -0XC);
L_800620F0:
    // 0x800620F0: lb          $v0, 0x0($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X0);
    // 0x800620F4: lbu         $v1, 0x1($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X1);
    // 0x800620F8: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800620FC: or          $t0, $v0, $v1
    ctx->r8 = ctx->r2 | ctx->r3;
    // 0x80062100: lb          $v0, 0x2($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X2);
    // 0x80062104: lbu         $v1, 0x3($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X3);
    // 0x80062108: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006210C: or          $t1, $v0, $v1
    ctx->r9 = ctx->r2 | ctx->r3;
    // 0x80062110: lb          $v0, 0x4($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X4);
    // 0x80062114: lbu         $v1, 0x5($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X5);
    // 0x80062118: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006211C: or          $t2, $v0, $v1
    ctx->r10 = ctx->r2 | ctx->r3;
    // 0x80062120: lb          $v0, 0xA($t6)
    ctx->r2 = MEM_B(ctx->r14, 0XA);
    // 0x80062124: lbu         $v1, 0xB($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XB);
    // 0x80062128: add         $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8006212C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80062130: bne         $a0, $zero, L_80062140
    if (ctx->r4 != 0) {
        // 0x80062134: or          $t3, $v0, $v1
        ctx->r11 = ctx->r2 | ctx->r3;
            goto L_80062140;
    }
    // 0x80062134: or          $t3, $v0, $v1
    ctx->r11 = ctx->r2 | ctx->r3;
    // 0x80062138: add         $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8006213C: addiu       $t6, $t6, -0xC
    ctx->r14 = ADD32(ctx->r14, -0XC);
L_80062140:
    // 0x80062140: lb          $v0, 0x0($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X0);
    // 0x80062144: lbu         $v1, 0x1($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X1);
    // 0x80062148: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006214C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80062150: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80062154: sub         $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x80062158: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006215C: mflo        $v0
    ctx->r2 = lo;
    // 0x80062160: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x80062164: add         $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80062168: sh          $t0, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r8;
    // 0x8006216C: lb          $v0, 0x2($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X2);
    // 0x80062170: lbu         $v1, 0x3($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X3);
    // 0x80062174: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80062178: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006217C: sub         $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x80062180: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062184: mflo        $v0
    ctx->r2 = lo;
    // 0x80062188: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x8006218C: add         $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80062190: sh          $t1, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r9;
    // 0x80062194: lb          $v0, 0x4($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X4);
    // 0x80062198: lbu         $v1, 0x5($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X5);
    // 0x8006219C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800621A0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800621A4: sub         $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x800621A8: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800621AC: mflo        $v0
    ctx->r2 = lo;
    // 0x800621B0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800621B4: add         $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800621B8: sh          $t2, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r10;
    // 0x800621BC: lb          $v0, 0xA($t6)
    ctx->r2 = MEM_B(ctx->r14, 0XA);
    // 0x800621C0: lbu         $v1, 0xB($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XB);
    // 0x800621C4: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800621C8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800621CC: sub         $v0, $v0, $t3
    ctx->r2 = SUB32(ctx->r2, ctx->r11);
    // 0x800621D0: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800621D4: addiu       $v1, $a1, 0x4
    ctx->r3 = ADD32(ctx->r5, 0X4);
    // 0x800621D8: mflo        $v0
    ctx->r2 = lo;
    // 0x800621DC: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800621E0: add         $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x800621E4: lb          $v0, 0x1F($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1F);
    // 0x800621E8: sh          $t3, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r11;
    // 0x800621EC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800621F0: sb          $v0, 0x1F($a1)
    MEM_B(0X1F, ctx->r5) = ctx->r2;
    // 0x800621F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800621F8: add         $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800621FC: lh          $v0, 0x24($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X24);
    // 0x80062200: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x80062204: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80062208: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8006220C: lw          $t9, -0x29BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X29BC);
    // 0x80062210: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_80062214:
    // 0x80062214: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x80062218: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006221C: addi        $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    // 0x80062220: beql        $v0, $at, L_80062270
    if (ctx->r2 == ctx->r1) {
        // 0x80062224: slt         $at, $t5, $t3
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80062270;
    }
    goto skip_12;
    // 0x80062224: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    skip_12:
    // 0x80062228: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8006222C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80062230: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062234: add         $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80062238: add         $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    // 0x8006223C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80062240: lh          $v1, 0x0($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X0);
    // 0x80062244: add         $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x80062248: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
    // 0x8006224C: lh          $v0, 0x2($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X2);
    // 0x80062250: lh          $v1, 0x2($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X2);
    // 0x80062254: add         $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x80062258: sh          $t2, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r10;
    // 0x8006225C: lh          $v0, 0x4($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X4);
    // 0x80062260: lh          $v1, 0x4($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X4);
    // 0x80062264: add         $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x80062268: sh          $t2, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r10;
    // 0x8006226C: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
L_80062270:
    // 0x80062270: bne         $at, $zero, L_80062214
    if (ctx->r1 != 0) {
        // 0x80062274: addi        $t6, $t6, 0xA
        ctx->r14 = ADD32(ctx->r14, 0XA);
            goto L_80062214;
    }
    // 0x80062274: addi        $t6, $t6, 0xA
    ctx->r14 = ADD32(ctx->r14, 0XA);
    // 0x80062278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006227C:
    // 0x8006227C: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x80062280: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x80062284: jr          $ra
    // 0x80062288: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80062288: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9AD0: jr          $ra
    // 0x800C9AD4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x800C9AD4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void get_distance_to_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069DC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80069DCC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80069DD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80069DD4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80069DD8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80069DDC: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x80069DE0: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x80069DE4: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x80069DE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069DEC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80069DF0: addiu       $a0, $a0, 0xF60
    ctx->r4 = ADD32(ctx->r4, 0XF60);
    // 0x80069DF4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80069DF8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80069DFC: jal         0x8006F64C
    // 0x80069E00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mtxf_transform_point(rdram, ctx);
        goto after_0;
    // 0x80069E00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80069E04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80069E08: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80069E0C: jr          $ra
    // 0x80069E10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80069E10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void process_subtitles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2F1C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C2F20: lw          $t6, 0x3680($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3680);
    // 0x800C2F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2F28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2F2C: bne         $t6, $zero, L_800C2F40
    if (ctx->r14 != 0) {
        // 0x800C2F30: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800C2F40;
    }
    // 0x800C2F30: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800C2F34: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C2F38: addiu       $a3, $a3, -0x584A
    ctx->r7 = ADD32(ctx->r7, -0X584A);
    // 0x800C2F3C: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
L_800C2F40:
    // 0x800C2F40: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C2F44: addiu       $a3, $a3, -0x584A
    ctx->r7 = ADD32(ctx->r7, -0X584A);
    // 0x800C2F48: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x800C2F4C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C2F50: beq         $a0, $zero, L_800C3028
    if (ctx->r4 == 0) {
        // 0x800C2F54: addiu       $a2, $a2, -0x5854
        ctx->r6 = ADD32(ctx->r6, -0X5854);
            goto L_800C3028;
    }
    // 0x800C2F54: addiu       $a2, $a2, -0x5854
    ctx->r6 = ADD32(ctx->r6, -0X5854);
    // 0x800C2F58: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x800C2F5C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C2F60: bgtz        $v1, L_800C2FC4
    if (SIGNED(ctx->r3) > 0) {
        // 0x800C2F64: subu        $t7, $v1, $a1
        ctx->r15 = SUB32(ctx->r3, ctx->r5);
            goto L_800C2FC4;
    }
    // 0x800C2F64: subu        $t7, $v1, $a1
    ctx->r15 = SUB32(ctx->r3, ctx->r5);
    // 0x800C2F68: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C2F6C: lh          $t8, -0x5856($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X5856);
    // 0x800C2F70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C2F74: multu       $a1, $t8
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2F78: addiu       $v0, $v0, -0x5858
    ctx->r2 = ADD32(ctx->r2, -0X5858);
    // 0x800C2F7C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800C2F80: mflo        $t9
    ctx->r25 = lo;
    // 0x800C2F84: subu        $t0, $t7, $t9
    ctx->r8 = SUB32(ctx->r15, ctx->r25);
    // 0x800C2F88: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x800C2F8C: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800C2F90: nop

    // 0x800C2F94: bgez        $t1, L_800C3028
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800C2F98: nop
    
            goto L_800C3028;
    }
    // 0x800C2F98: nop

    // 0x800C2F9C: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800C2FA0: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x800C2FA4: jal         0x800C5620
    // 0x800C2FA8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_close(rdram, ctx);
        goto after_0;
    // 0x800C2FA8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x800C2FAC: jal         0x800C5494
    // 0x800C2FB0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_1;
    // 0x800C2FB0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x800C2FB4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C2FB8: lh          $a0, -0x584A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X584A);
    // 0x800C2FBC: b           L_800C3028
    // 0x800C2FC0: nop

        goto L_800C3028;
    // 0x800C2FC0: nop

L_800C2FC4:
    // 0x800C2FC4: lh          $t3, -0x5856($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X5856);
    // 0x800C2FC8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C2FCC: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2FD0: addiu       $v0, $v0, -0x5858
    ctx->r2 = ADD32(ctx->r2, -0X5858);
    // 0x800C2FD4: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800C2FD8: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x800C2FDC: mflo        $t4
    ctx->r12 = lo;
    // 0x800C2FE0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800C2FE4: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x800C2FE8: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800C2FEC: nop

    // 0x800C2FF0: slti        $at, $t6, 0x101
    ctx->r1 = SIGNED(ctx->r14) < 0X101 ? 1 : 0;
    // 0x800C2FF4: bne         $at, $zero, L_800C3000
    if (ctx->r1 != 0) {
        // 0x800C2FF8: nop
    
            goto L_800C3000;
    }
    // 0x800C2FF8: nop

    // 0x800C2FFC: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_800C3000:
    // 0x800C3000: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x800C3004: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800C3008: nop

    // 0x800C300C: bgtz        $t9, L_800C3028
    if (SIGNED(ctx->r25) > 0) {
        // 0x800C3010: nop
    
            goto L_800C3028;
    }
    // 0x800C3010: nop

    // 0x800C3014: jal         0x800C2D6C
    // 0x800C3018: nop

    find_next_subtitle(rdram, ctx);
        goto after_2;
    // 0x800C3018: nop

    after_2:
    // 0x800C301C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3020: lh          $a0, -0x584A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X584A);
    // 0x800C3024: nop

L_800C3028:
    // 0x800C3028: beq         $a0, $zero, L_800C303C
    if (ctx->r4 == 0) {
        // 0x800C302C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C303C;
    }
    // 0x800C302C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3030: jal         0x800C2B00
    // 0x800C3034: nop

    render_subtitles(rdram, ctx);
        goto after_3;
    // 0x800C3034: nop

    after_3:
    // 0x800C3038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C303C:
    // 0x800C303C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3040: jr          $ra
    // 0x800C3044: nop

    return;
    // 0x800C3044: nop

;}
RECOMP_FUNC void get_stereo_pan_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065BDC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80065BE0: lh          $v0, -0x2FB0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2FB0);
    // 0x80065BE4: jr          $ra
    // 0x80065BE8: nop

    return;
    // 0x80065BE8: nop

;}
RECOMP_FUNC void area_triangle_2d(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A2C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80070A30: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80070A34: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80070A38: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80070A3C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80070A40: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80070A44: sub.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80070A48: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80070A4C: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80070A50: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80070A54: mul.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80070A58: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80070A5C: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80070A60: mul.s       $f16, $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80070A64: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80070A68: mul.s       $f18, $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80070A6C: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80070A70: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80070A74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80070A78: add.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80070A7C: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80070A80: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070A84: sqrt.s      $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = sqrtf(ctx->f12.fl);
    // 0x80070A88: sqrt.s      $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = sqrtf(ctx->f16.fl);
    // 0x80070A8C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070A90: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80070A94: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x80070A98: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80070A9C: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80070AA0: mul.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070AA4: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80070AA8: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80070AAC: mul.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80070AB0: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80070AB4: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80070AB8: nop

    // 0x80070ABC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80070AC0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80070AC4: bc1fl       L_80070AD0
    if (!c1cs) {
        // 0x80070AC8: nop
    
            goto L_80070AD0;
    }
    goto skip_0;
    // 0x80070AC8: nop

    skip_0:
    // 0x80070ACC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80070AD0:
    // 0x80070AD0: jr          $ra
    // 0x80070AD4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    return;
    // 0x80070AD4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
;}
RECOMP_FUNC void lensflare_override_add(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACF60: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800ACF64: addiu       $v1, $v1, 0x2A88
    ctx->r3 = ADD32(ctx->r3, 0X2A88);
    // 0x800ACF68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800ACF6C: nop

    // 0x800ACF70: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800ACF74: beq         $at, $zero, L_800ACF90
    if (ctx->r1 == 0) {
        // 0x800ACF78: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800ACF90;
    }
    // 0x800ACF78: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800ACF7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ACF80: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800ACF84: sw          $a0, 0x7C40($at)
    MEM_W(0X7C40, ctx->r1) = ctx->r4;
    // 0x800ACF88: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800ACF8C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800ACF90:
    // 0x800ACF90: jr          $ra
    // 0x800ACF94: nop

    return;
    // 0x800ACF94: nop

;}
RECOMP_FUNC void transition_update_shape(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1130: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C1134: addiu       $a3, $a3, 0x31B0
    ctx->r7 = ADD32(ctx->r7, 0X31B0);
    // 0x800C1138: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800C113C: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x800C1140: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1144: blez        $v0, L_800C13B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C1148: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C13B4;
    }
    // 0x800C1148: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C114C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C1150: beq         $at, $zero, L_800C1224
    if (ctx->r1 == 0) {
        // 0x800C1154: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_800C1224;
    }
    // 0x800C1154: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C1158: addiu       $t0, $t0, -0x5884
    ctx->r8 = ADD32(ctx->r8, -0X5884);
    // 0x800C115C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C1160: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C1164: blez        $a1, L_800C1210
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C1168: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_800C1210;
    }
    // 0x800C1168: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C116C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C1170: addiu       $t1, $t1, -0x5890
    ctx->r9 = ADD32(ctx->r9, -0X5890);
    // 0x800C1174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1178: addiu       $t2, $t2, -0x588C
    ctx->r10 = ADD32(ctx->r10, -0X588C);
L_800C117C:
    // 0x800C117C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800C1180: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800C1184: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1188: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C118C: addu        $a2, $t6, $v0
    ctx->r6 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1190: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C1194: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C1198: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C119C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C11A0: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x800C11A4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800C11A8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800C11AC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C11B0: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C11B4: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x800C11B8: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C11BC: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800C11C0: nop

    // 0x800C11C4: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800C11C8: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x800C11CC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800C11D0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C11D4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C11D8: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C11DC: addu        $a2, $t5, $v0
    ctx->r6 = ADD32(ctx->r13, ctx->r2);
    // 0x800C11E0: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800C11E4: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800C11E8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C11EC: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800C11F0: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
    // 0x800C11F4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C11F8: nop

    // 0x800C11FC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C1200: bne         $at, $zero, L_800C117C
    if (ctx->r1 != 0) {
        // 0x800C1204: nop
    
            goto L_800C117C;
    }
    // 0x800C1204: nop

    // 0x800C1208: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x800C120C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C1210:
    // 0x800C1210: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C1214: subu        $t8, $v0, $a0
    ctx->r24 = SUB32(ctx->r2, ctx->r4);
    // 0x800C1218: addiu       $t1, $t1, -0x5890
    ctx->r9 = ADD32(ctx->r9, -0X5890);
    // 0x800C121C: b           L_800C12B8
    // 0x800C1220: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_800C12B8;
    // 0x800C1220: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_800C1224:
    // 0x800C1224: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C1228: addiu       $t0, $t0, -0x5884
    ctx->r8 = ADD32(ctx->r8, -0X5884);
    // 0x800C122C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C1230: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C1234: blez        $a1, L_800C12AC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C1238: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_800C12AC;
    }
    // 0x800C1238: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C123C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C1240: addiu       $a0, $a0, -0x5888
    ctx->r4 = ADD32(ctx->r4, -0X5888);
    // 0x800C1244: addiu       $t1, $t1, -0x5890
    ctx->r9 = ADD32(ctx->r9, -0X5890);
    // 0x800C1248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C124C:
    // 0x800C124C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800C1250: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800C1254: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1258: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800C125C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1260: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x800C1264: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C1268: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800C126C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1270: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800C1274: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1278: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x800C127C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800C1280: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C1284: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C1288: lwc1        $f16, 0x8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800C128C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1290: swc1        $f16, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f16.u32l;
    // 0x800C1294: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C1298: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C129C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C12A0: bne         $at, $zero, L_800C124C
    if (ctx->r1 != 0) {
        // 0x800C12A4: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800C124C;
    }
    // 0x800C12A4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C12A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C12AC:
    // 0x800C12AC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C12B0: addiu       $t1, $t1, -0x5890
    ctx->r9 = ADD32(ctx->r9, -0X5890);
    // 0x800C12B4: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
L_800C12B8:
    // 0x800C12B8: blez        $a1, L_800C13DC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C12BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C13DC;
    }
    // 0x800C12BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C12C0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C12C4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C12C8: addiu       $a1, $a1, 0x31C0
    ctx->r5 = ADD32(ctx->r5, 0X31C0);
    // 0x800C12CC: addiu       $a2, $a2, 0x31D0
    ctx->r6 = ADD32(ctx->r6, 0X31D0);
    // 0x800C12D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800C12D4:
    // 0x800C12D4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C12D8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800C12DC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C12E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C12E4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C12E8: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C12EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C12F0: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C12F4: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C12F8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C12FC: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x800C1300: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C1304: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C1308: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800C130C: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800C1310: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800C1314: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x800C1318: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800C131C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800C1320: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1324: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1328: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C132C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1330: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C1334: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C1338: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x800C133C: addu        $t8, $a1, $t3
    ctx->r24 = ADD32(ctx->r5, ctx->r11);
    // 0x800C1340: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800C1344: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800C1348: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800C134C: addu        $t4, $t9, $a0
    ctx->r12 = ADD32(ctx->r25, ctx->r4);
    // 0x800C1350: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800C1354: sh          $t6, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r14;
    // 0x800C1358: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C135C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800C1360: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C1364: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1368: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800C136C: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C1370: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1374: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800C1378: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C137C: addu        $t4, $a1, $t6
    ctx->r12 = ADD32(ctx->r5, ctx->r14);
    // 0x800C1380: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C1384: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800C1388: addu        $t7, $t5, $a0
    ctx->r15 = ADD32(ctx->r13, ctx->r4);
    // 0x800C138C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800C1390: sb          $t8, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r24;
    // 0x800C1394: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800C1398: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C139C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800C13A0: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800C13A4: bne         $at, $zero, L_800C12D4
    if (ctx->r1 != 0) {
        // 0x800C13A8: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800C12D4;
    }
    // 0x800C13A8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C13AC: jr          $ra
    // 0x800C13B0: nop

    return;
    // 0x800C13B0: nop

L_800C13B4:
    // 0x800C13B4: addiu       $v1, $v1, 0x31B4
    ctx->r3 = ADD32(ctx->r3, 0X31B4);
    // 0x800C13B8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800C13BC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800C13C0: beq         $v0, $at, L_800C13DC
    if (ctx->r2 == ctx->r1) {
        // 0x800C13C4: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800C13DC;
    }
    // 0x800C13C4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C13C8: beq         $at, $zero, L_800C13D8
    if (ctx->r1 == 0) {
        // 0x800C13CC: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_800C13D8;
    }
    // 0x800C13CC: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x800C13D0: jr          $ra
    // 0x800C13D4: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x800C13D4: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_800C13D8:
    // 0x800C13D8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_800C13DC:
    // 0x800C13DC: jr          $ra
    // 0x800C13E0: nop

    return;
    // 0x800C13E0: nop

;}
RECOMP_FUNC void debug_text_character(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B69FC: slti        $at, $a1, 0x40
    ctx->r1 = SIGNED(ctx->r5) < 0X40 ? 1 : 0;
    // 0x800B6A00: beq         $at, $zero, L_800B6B10
    if (ctx->r1 == 0) {
        // 0x800B6A04: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800B6B10;
    }
    // 0x800B6A04: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B6A08: addiu       $v1, $v1, 0x7CCC
    ctx->r3 = ADD32(ctx->r3, 0X7CCC);
    // 0x800B6A0C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B6A10: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800B6A14: beq         $t6, $zero, L_800B6B08
    if (ctx->r14 == 0) {
        // 0x800B6A18: nop
    
            goto L_800B6B08;
    }
    // 0x800B6A18: nop

    // 0x800B6A1C: lw          $t7, 0x7CB8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7CB8);
    // 0x800B6A20: lui         $t9, 0xFD70
    ctx->r25 = S32(0XFD70 << 16);
    // 0x800B6A24: beq         $t7, $zero, L_800B6B04
    if (ctx->r15 == 0) {
        // 0x800B6A28: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800B6B04;
    }
    // 0x800B6A28: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800B6A2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6A30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6A34: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B6A38: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6A3C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B6A40: lw          $t4, 0x7CA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7CA0);
    // 0x800B6A44: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800B6A48: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800B6A4C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B6A50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6A54: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x800B6A58: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B6A5C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B6A60: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800B6A64: lui         $t7, 0xF570
    ctx->r15 = S32(0XF570 << 16);
    // 0x800B6A68: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B6A6C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B6A70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6A74: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800B6A78: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B6A7C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B6A80: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6A84: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B6A88: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6A8C: lui         $t7, 0x741
    ctx->r15 = S32(0X741 << 16);
    // 0x800B6A90: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B6A94: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B6A98: ori         $t7, $t7, 0xF056
    ctx->r15 = ctx->r15 | 0XF056;
    // 0x800B6A9C: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800B6AA0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B6AA4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B6AA8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6AAC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800B6AB0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B6AB4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6AB8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6ABC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B6AC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6AC4: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800B6AC8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B6ACC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B6AD0: lui         $t5, 0xF568
    ctx->r13 = S32(0XF568 << 16);
    // 0x800B6AD4: ori         $t5, $t5, 0x3000
    ctx->r13 = ctx->r13 | 0X3000;
    // 0x800B6AD8: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B6ADC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B6AE0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B6AE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6AE8: lui         $t9, 0x2F
    ctx->r25 = S32(0X2F << 16);
    // 0x800B6AEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B6AF0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B6AF4: ori         $t9, $t9, 0xC028
    ctx->r25 = ctx->r25 | 0XC028;
    // 0x800B6AF8: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B6AFC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B6B00: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800B6B04:
    // 0x800B6B04: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800B6B08:
    // 0x800B6B08: b           L_800B6D34
    // 0x800B6B0C: addiu       $a1, $a1, -0x21
    ctx->r5 = ADD32(ctx->r5, -0X21);
        goto L_800B6D34;
    // 0x800B6B0C: addiu       $a1, $a1, -0x21
    ctx->r5 = ADD32(ctx->r5, -0X21);
L_800B6B10:
    // 0x800B6B10: slti        $at, $a1, 0x60
    ctx->r1 = SIGNED(ctx->r5) < 0X60 ? 1 : 0;
    // 0x800B6B14: beq         $at, $zero, L_800B6C24
    if (ctx->r1 == 0) {
        // 0x800B6B18: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800B6C24;
    }
    // 0x800B6B18: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B6B1C: addiu       $v1, $v1, 0x7CCC
    ctx->r3 = ADD32(ctx->r3, 0X7CCC);
    // 0x800B6B20: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800B6B24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B6B28: beq         $a2, $t4, L_800B6C1C
    if (ctx->r6 == ctx->r12) {
        // 0x800B6B2C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800B6C1C;
    }
    // 0x800B6B2C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800B6B30: lw          $t5, 0x7CB8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7CB8);
    // 0x800B6B34: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x800B6B38: beq         $t5, $zero, L_800B6C18
    if (ctx->r13 == 0) {
        // 0x800B6B3C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800B6C18;
    }
    // 0x800B6B3C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800B6B40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6B44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6B48: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B6B4C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B6B50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B6B54: lw          $t8, 0x7CA4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7CA4);
    // 0x800B6B58: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800B6B5C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800B6B60: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B6B64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6B68: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800B6B6C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B6B70: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B6B74: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B6B78: lui         $t5, 0xF570
    ctx->r13 = S32(0XF570 << 16);
    // 0x800B6B7C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B6B80: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B6B84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6B88: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800B6B8C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B6B90: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B6B94: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6B98: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B6B9C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6BA0: lui         $t5, 0x755
    ctx->r13 = S32(0X755 << 16);
    // 0x800B6BA4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B6BA8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B6BAC: ori         $t5, $t5, 0x3043
    ctx->r13 = ctx->r13 | 0X3043;
    // 0x800B6BB0: lui         $t4, 0xF300
    ctx->r12 = S32(0XF300 << 16);
    // 0x800B6BB4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B6BB8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B6BBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6BC0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B6BC4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B6BC8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B6BCC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6BD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B6BD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6BD8: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x800B6BDC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B6BE0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6BE4: lui         $t9, 0xF568
    ctx->r25 = S32(0XF568 << 16);
    // 0x800B6BE8: ori         $t9, $t9, 0x3E00
    ctx->r25 = ctx->r25 | 0X3E00;
    // 0x800B6BEC: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x800B6BF0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B6BF4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B6BF8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6BFC: lui         $t7, 0x3D
    ctx->r15 = S32(0X3D << 16);
    // 0x800B6C00: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B6C04: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B6C08: ori         $t7, $t7, 0xC028
    ctx->r15 = ctx->r15 | 0XC028;
    // 0x800B6C0C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800B6C10: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B6C14: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_800B6C18:
    // 0x800B6C18: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_800B6C1C:
    // 0x800B6C1C: b           L_800B6D34
    // 0x800B6C20: addiu       $a1, $a1, -0x40
    ctx->r5 = ADD32(ctx->r5, -0X40);
        goto L_800B6D34;
    // 0x800B6C20: addiu       $a1, $a1, -0x40
    ctx->r5 = ADD32(ctx->r5, -0X40);
L_800B6C24:
    // 0x800B6C24: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x800B6C28: beq         $at, $zero, L_800B6D34
    if (ctx->r1 == 0) {
        // 0x800B6C2C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800B6D34;
    }
    // 0x800B6C2C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B6C30: addiu       $v1, $v1, 0x7CCC
    ctx->r3 = ADD32(ctx->r3, 0X7CCC);
    // 0x800B6C34: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800B6C38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800B6C3C: beq         $a2, $t8, L_800B6D34
    if (ctx->r6 == ctx->r24) {
        // 0x800B6C40: addiu       $a1, $a1, -0x60
        ctx->r5 = ADD32(ctx->r5, -0X60);
            goto L_800B6D34;
    }
    // 0x800B6C40: addiu       $a1, $a1, -0x60
    ctx->r5 = ADD32(ctx->r5, -0X60);
    // 0x800B6C44: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800B6C48: lw          $t9, 0x7CB8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7CB8);
    // 0x800B6C4C: lui         $t5, 0xFD70
    ctx->r13 = S32(0XFD70 << 16);
    // 0x800B6C50: beq         $t9, $zero, L_800B6D30
    if (ctx->r25 == 0) {
        // 0x800B6C54: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800B6D30;
    }
    // 0x800B6C54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B6C58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6C5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6C60: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B6C64: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B6C68: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B6C6C: lw          $t6, 0x7CA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7CA8);
    // 0x800B6C70: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800B6C74: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800B6C78: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B6C7C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6C80: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x800B6C84: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B6C88: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6C8C: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x800B6C90: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x800B6C94: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B6C98: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B6C9C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6CA0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800B6CA4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B6CA8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B6CAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6CB0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B6CB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6CB8: lui         $t9, 0x741
    ctx->r25 = S32(0X741 << 16);
    // 0x800B6CBC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B6CC0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B6CC4: ori         $t9, $t9, 0xF056
    ctx->r25 = ctx->r25 | 0XF056;
    // 0x800B6CC8: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800B6CCC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B6CD0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B6CD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6CD8: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800B6CDC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B6CE0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B6CE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6CE8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B6CEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6CF0: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800B6CF4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B6CF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B6CFC: lui         $t7, 0xF568
    ctx->r15 = S32(0XF568 << 16);
    // 0x800B6D00: ori         $t7, $t7, 0x3000
    ctx->r15 = ctx->r15 | 0X3000;
    // 0x800B6D04: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800B6D08: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B6D0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B6D10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6D14: lui         $t5, 0x2F
    ctx->r13 = S32(0X2F << 16);
    // 0x800B6D18: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B6D1C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B6D20: ori         $t5, $t5, 0xC028
    ctx->r13 = ctx->r13 | 0XC028;
    // 0x800B6D24: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x800B6D28: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B6D2C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_800B6D30:
    // 0x800B6D30: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_800B6D34:
    // 0x800B6D34: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B6D38: addiu       $v1, $v1, 0x7CCC
    ctx->r3 = ADD32(ctx->r3, 0X7CCC);
    // 0x800B6D3C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B6D40: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x800B6D44: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B6D48: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800B6D4C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B6D50: addiu       $t4, $t4, 0x2EF4
    ctx->r12 = ADD32(ctx->r12, 0X2EF4);
    // 0x800B6D54: addu        $v0, $t9, $t4
    ctx->r2 = ADD32(ctx->r25, ctx->r12);
    // 0x800B6D58: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800B6D5C: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x800B6D60: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B6D64: lw          $t6, 0x7CB8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7CB8);
    // 0x800B6D68: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    // 0x800B6D6C: beq         $t6, $zero, L_800B6E48
    if (ctx->r14 == 0) {
        // 0x800B6D70: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800B6E48;
    }
    // 0x800B6D70: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B6D74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6D78: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x800B6D7C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B6D80: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B6D84: lui         $t9, 0xFFFE
    ctx->r25 = S32(0XFFFE << 16);
    // 0x800B6D88: ori         $t9, $t9, 0xF379
    ctx->r25 = ctx->r25 | 0XF379;
    // 0x800B6D8C: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800B6D90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B6D94: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B6D98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6D9C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800B6DA0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B6DA4: addiu       $t2, $t2, 0x7CAC
    ctx->r10 = ADD32(ctx->r10, 0X7CAC);
    // 0x800B6DA8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B6DAC: lhu         $t5, 0x0($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X0);
    // 0x800B6DB0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800B6DB4: addu        $t6, $t5, $a3
    ctx->r14 = ADD32(ctx->r13, ctx->r7);
    // 0x800B6DB8: addiu       $t3, $t3, 0x7CAE
    ctx->r11 = ADD32(ctx->r11, 0X7CAE);
    // 0x800B6DBC: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x800B6DC0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B6DC4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B6DC8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800B6DCC: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x800B6DD0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B6DD4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B6DD8: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x800B6DDC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B6DE0: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x800B6DE4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B6DE8: lhu         $t5, 0x0($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X0);
    // 0x800B6DEC: lhu         $t8, 0x0($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X0);
    // 0x800B6DF0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B6DF4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B6DF8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B6DFC: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B6E00: sll         $t4, $t7, 12
    ctx->r12 = S32(ctx->r15 << 12);
    // 0x800B6E04: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x800B6E08: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B6E0C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6E10: sll         $t5, $a2, 21
    ctx->r13 = S32(ctx->r6 << 21);
    // 0x800B6E14: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B6E18: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B6E1C: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x800B6E20: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B6E24: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B6E28: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6E2C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800B6E30: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B6E34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B6E38: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x800B6E3C: lui         $t7, 0xB200
    ctx->r15 = S32(0XB200 << 16);
    // 0x800B6E40: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B6E44: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_800B6E48:
    // 0x800B6E48: jr          $ra
    // 0x800B6E4C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800B6E4C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
RECOMP_FUNC void func_8001EE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EE74: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001EE78: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001EE7C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8001EE80: addiu       $s7, $s7, -0x5188
    ctx->r23 = ADD32(ctx->r23, -0X5188);
    // 0x8001EE84: lh          $t6, 0x0($s7)
    ctx->r14 = MEM_H(ctx->r23, 0X0);
    // 0x8001EE88: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001EE8C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001EE90: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001EE94: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001EE98: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001EE9C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001EEA0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001EEA4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001EEA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001EEAC: blez        $t6, L_8001EF68
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001EEB0: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001EF68;
    }
    // 0x8001EEB0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001EEB4: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8001EEB8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8001EEBC: addiu       $s4, $s4, -0x518C
    ctx->r20 = ADD32(ctx->r20, -0X518C);
    // 0x8001EEC0: addiu       $fp, $fp, -0x52DA
    ctx->r30 = ADD32(ctx->r30, -0X52DA);
    // 0x8001EEC4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001EEC8: addiu       $s6, $zero, 0x14
    ctx->r22 = ADD32(0, 0X14);
    // 0x8001EECC: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
L_8001EED0:
    // 0x8001EED0: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8001EED4: nop

    // 0x8001EED8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8001EEDC: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x8001EEE0: nop

    // 0x8001EEE4: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x8001EEE8: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
    // 0x8001EEEC: bne         $t9, $zero, L_8001EF1C
    if (ctx->r25 != 0) {
        // 0x8001EEF0: nop
    
            goto L_8001EF1C;
    }
    // 0x8001EEF0: nop

    // 0x8001EEF4: lb          $t0, 0x11($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X11);
    // 0x8001EEF8: nop

    // 0x8001EEFC: bne         $t0, $zero, L_8001EF1C
    if (ctx->r8 != 0) {
        // 0x8001EF00: nop
    
            goto L_8001EF1C;
    }
    // 0x8001EF00: nop

    // 0x8001EF04: lh          $t1, 0xC($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XC);
    // 0x8001EF08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001EF0C: beq         $s5, $t1, L_8001EF1C
    if (ctx->r21 == ctx->r9) {
        // 0x8001EF10: nop
    
            goto L_8001EF1C;
    }
    // 0x8001EF10: nop

    // 0x8001EF14: jal         0x8001F23C
    // 0x8001EF18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001F23C(rdram, ctx);
        goto after_0;
    // 0x8001EF18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
L_8001EF1C:
    // 0x8001EF1C: lb          $t2, 0x0($fp)
    ctx->r10 = MEM_B(ctx->r30, 0X0);
    // 0x8001EF20: nop

    // 0x8001EF24: bne         $t2, $zero, L_8001EF3C
    if (ctx->r10 != 0) {
        // 0x8001EF28: nop
    
            goto L_8001EF3C;
    }
    // 0x8001EF28: nop

    // 0x8001EF2C: lb          $t3, 0x21($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X21);
    // 0x8001EF30: nop

    // 0x8001EF34: beq         $s6, $t3, L_8001EF54
    if (ctx->r22 == ctx->r11) {
        // 0x8001EF38: nop
    
            goto L_8001EF54;
    }
    // 0x8001EF38: nop

L_8001EF3C:
    // 0x8001EF3C: lw          $a1, 0x64($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X64);
    // 0x8001EF40: nop

    // 0x8001EF44: beq         $a1, $zero, L_8001EF54
    if (ctx->r5 == 0) {
        // 0x8001EF48: nop
    
            goto L_8001EF54;
    }
    // 0x8001EF48: nop

    // 0x8001EF4C: jal         0x8001EFA4
    // 0x8001EF50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_1;
    // 0x8001EF50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
L_8001EF54:
    // 0x8001EF54: lh          $t4, 0x0($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X0);
    // 0x8001EF58: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001EF5C: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001EF60: bne         $at, $zero, L_8001EED0
    if (ctx->r1 != 0) {
        // 0x8001EF64: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8001EED0;
    }
    // 0x8001EF64: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8001EF68:
    // 0x8001EF68: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8001EF6C: addiu       $fp, $fp, -0x52DA
    ctx->r30 = ADD32(ctx->r30, -0X52DA);
    // 0x8001EF70: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001EF74: sb          $zero, 0x0($fp)
    MEM_B(0X0, ctx->r30) = 0;
    // 0x8001EF78: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001EF7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001EF80: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EF84: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001EF88: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001EF8C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001EF90: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EF94: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001EF98: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001EF9C: jr          $ra
    // 0x8001EFA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001EFA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mark_read_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EB78: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EB7C: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006EB80: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EB84: addiu       $at, $zero, -0x301
    ctx->r1 = ADD32(0, -0X301);
    // 0x8006EB88: andi        $t0, $a0, 0x3
    ctx->r8 = ctx->r4 & 0X3;
    // 0x8006EB8C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8006EB90: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8006EB94: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8006EB98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006EB9C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8006EBA0: jr          $ra
    // 0x8006EBA4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    return;
    // 0x8006EBA4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
;}
RECOMP_FUNC void func_80060910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060910: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80060914: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80060918: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8006091C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80060920: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80060924: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80060928: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006092C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80060930: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80060934: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80060938: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006093C: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x80060940: lh          $a1, 0x28($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X28);
    // 0x80060944: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80060948: blez        $a1, L_80060A98
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006094C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80060A98;
    }
    // 0x8006094C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80060950: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80060954: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80060958: addiu       $s7, $sp, 0x60
    ctx->r23 = ADD32(ctx->r29, 0X60);
    // 0x8006095C: addiu       $s6, $sp, 0x5C
    ctx->r22 = ADD32(ctx->r29, 0X5C);
L_80060960:
    // 0x80060960: lw          $t6, 0x38($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X38);
    // 0x80060964: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80060968: sll         $t4, $s4, 3
    ctx->r12 = S32(ctx->r20 << 3);
    // 0x8006096C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80060970: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x80060974: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80060978: lh          $s5, 0x2($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X2);
    // 0x8006097C: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x80060980: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80060984: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x80060988: andi        $t1, $t9, 0x200
    ctx->r9 = ctx->r25 & 0X200;
    // 0x8006098C: beq         $t1, $zero, L_8006099C
    if (ctx->r9 == 0) {
        // 0x80060990: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_8006099C;
    }
    // 0x80060990: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80060994: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x80060998: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_8006099C:
    // 0x8006099C: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x800609A0: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800609A4: beq         $at, $zero, L_80060A7C
    if (ctx->r1 == 0) {
        // 0x800609A8: lw          $t7, 0x88($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X88);
            goto L_80060A7C;
    }
    // 0x800609A8: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800609AC: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
L_800609B0:
    // 0x800609B0: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x800609B4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800609B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800609BC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800609C0: sh          $s4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r20;
    // 0x800609C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800609C8:
    // 0x800609C8: addiu       $s1, $v1, 0x1
    ctx->r17 = ADD32(ctx->r3, 0X1);
    // 0x800609CC: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800609D0: bne         $at, $zero, L_800609DC
    if (ctx->r1 != 0) {
        // 0x800609D4: or          $t0, $s1, $zero
        ctx->r8 = ctx->r17 | 0;
            goto L_800609DC;
    }
    // 0x800609D4: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x800609D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800609DC:
    // 0x800609DC: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x800609E0: sll         $t9, $s3, 4
    ctx->r25 = S32(ctx->r19 << 4);
    // 0x800609E4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800609E8: addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // 0x800609EC: addu        $t3, $v0, $t0
    ctx->r11 = ADD32(ctx->r2, ctx->r8);
    // 0x800609F0: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x800609F4: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x800609F8: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x800609FC: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80060A00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80060A04: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80060A08: addu        $a2, $t2, $s5
    ctx->r6 = ADD32(ctx->r10, ctx->r21);
    // 0x80060A0C: jal         0x80060AC8
    // 0x80060A10: addu        $a3, $t4, $s5
    ctx->r7 = ADD32(ctx->r12, ctx->r21);
    func_80060AC8(rdram, ctx);
        goto after_0;
    // 0x80060A10: addu        $a3, $t4, $s5
    ctx->r7 = ADD32(ctx->r12, ctx->r21);
    after_0:
    // 0x80060A14: beq         $v0, $fp, L_80060A34
    if (ctx->r2 == ctx->r30) {
        // 0x80060A18: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_80060A34;
    }
    // 0x80060A18: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80060A1C: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x80060A20: sll         $t6, $s4, 3
    ctx->r14 = S32(ctx->r20 << 3);
    // 0x80060A24: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80060A28: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80060A2C: b           L_80060A48
    // 0x80060A30: sh          $v0, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r2;
        goto L_80060A48;
    // 0x80060A30: sh          $v0, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r2;
L_80060A34:
    // 0x80060A34: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80060A38: sll         $t1, $s4, 3
    ctx->r9 = S32(ctx->r20 << 3);
    // 0x80060A3C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80060A40: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80060A44: sh          $s4, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r20;
L_80060A48:
    // 0x80060A48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80060A4C: bne         $s1, $at, L_800609C8
    if (ctx->r17 != ctx->r1) {
        // 0x80060A50: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800609C8;
    }
    // 0x80060A50: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80060A54: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80060A58: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80060A5C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80060A60: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80060A64: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x80060A68: bne         $s3, $t6, L_800609B0
    if (ctx->r19 != ctx->r14) {
        // 0x80060A6C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800609B0;
    }
    // 0x80060A6C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060A70: lh          $a1, 0x28($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X28);
    // 0x80060A74: nop

    // 0x80060A78: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
L_80060A7C:
    // 0x80060A7C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80060A80: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80060A84: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060A88: addiu       $t1, $t9, 0xC
    ctx->r9 = ADD32(ctx->r25, 0XC);
    // 0x80060A8C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x80060A90: bne         $at, $zero, L_80060960
    if (ctx->r1 != 0) {
        // 0x80060A94: sw          $t8, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r24;
            goto L_80060960;
    }
    // 0x80060A94: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
L_80060A98:
    // 0x80060A98: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80060A9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80060AA0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80060AA4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80060AA8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80060AAC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80060AB0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80060AB4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80060AB8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80060ABC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80060AC0: jr          $ra
    // 0x80060AC4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80060AC4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void obj_init_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FAC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000FAC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000FACC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000FAD0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000FAD4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000FAD8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000FADC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8000FAE0: sw          $a1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r5;
    // 0x8000FAE4: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
    // 0x8000FAE8: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x8000FAEC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000FAF0: blez        $v1, L_8000FB9C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000FAF4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000FB9C;
    }
    // 0x8000FAF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000FAF8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8000FAFC: lui         $s3, 0xFFFF
    ctx->r19 = S32(0XFFFF << 16);
L_8000FB00:
    // 0x8000FB00: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000FB04: sll         $t1, $s0, 5
    ctx->r9 = S32(ctx->r16 << 5);
    // 0x8000FB08: and         $t6, $v0, $s3
    ctx->r14 = ctx->r2 & ctx->r19;
    // 0x8000FB0C: bne         $s3, $t6, L_8000FB3C
    if (ctx->r19 != ctx->r14) {
        // 0x8000FB10: sra         $a1, $v0, 24
        ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
            goto L_8000FB3C;
    }
    // 0x8000FB10: sra         $a1, $v0, 24
    ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8000FB14: lw          $t7, 0x6C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X6C);
    // 0x8000FB18: sra         $a1, $v0, 8
    ctx->r5 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8000FB1C: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x8000FB20: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x8000FB24: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8000FB28: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x8000FB2C: jal         0x800AF1E0
    // 0x8000FB30: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    emitter_init(rdram, ctx);
        goto after_0;
    // 0x8000FB30: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x8000FB34: b           L_8000FB84
    // 0x8000FB38: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
        goto L_8000FB84;
    // 0x8000FB38: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_8000FB3C:
    // 0x8000FB3C: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8000FB40: lw          $t0, 0x6C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X6C);
    // 0x8000FB44: sra         $a2, $v0, 16
    ctx->r6 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000FB48: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8000FB4C: sra         $t6, $v1, 16
    ctx->r14 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000FB50: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8000FB54: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x8000FB58: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x8000FB5C: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x8000FB60: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8000FB64: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8000FB68: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8000FB6C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8000FB70: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8000FB74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000FB78: jal         0x800AF29C
    // 0x8000FB7C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    emitter_init_with_pos(rdram, ctx);
        goto after_1;
    // 0x8000FB7C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x8000FB80: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_8000FB84:
    // 0x8000FB84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000FB88: lb          $v1, 0x57($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X57);
    // 0x8000FB8C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8000FB90: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000FB94: bne         $at, $zero, L_8000FB00
    if (ctx->r1 != 0) {
        // 0x8000FB98: nop
    
            goto L_8000FB00;
    }
    // 0x8000FB98: nop

L_8000FB9C:
    // 0x8000FB9C: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8000FBA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FBA4: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8000FBA8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8000FBAC: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x8000FBB0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FBB4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000FBB8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000FBBC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000FBC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000FBC4: jr          $ra
    // 0x8000FBC8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8000FBC8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void ainode_tail(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001D1E8: addiu       $v1, $v1, -0x50F8
    ctx->r3 = ADD32(ctx->r3, -0X50F8);
    // 0x8001D1EC: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8001D1F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001D1F4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001D1F8: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8001D1FC: lw          $t7, -0x50FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X50FC);
    // 0x8001D200: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001D204: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8001D208: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8001D20C: jr          $ra
    // 0x8001D210: nop

    return;
    // 0x8001D210: nop

;}
RECOMP_FUNC void reset_rocket_sound_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F0D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003F0D4: jr          $ra
    // 0x8003F0D8: sw          $zero, -0x2B24($at)
    MEM_W(-0X2B24, ctx->r1) = 0;
    return;
    // 0x8003F0D8: sw          $zero, -0x2B24($at)
    MEM_W(-0X2B24, ctx->r1) = 0;
;}
RECOMP_FUNC void obj_loop_lavaspurt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003759C: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x800375A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800375A4: blez        $v0, L_800375C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800375A8: sll         $t2, $a1, 2
        ctx->r10 = S32(ctx->r5 << 2);
            goto L_800375C4;
    }
    // 0x800375A8: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x800375AC: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800375B0: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x800375B4: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x800375B8: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x800375BC: b           L_80037614
    // 0x800375C0: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
        goto L_80037614;
    // 0x800375C0: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
L_800375C4:
    // 0x800375C4: lh          $t1, 0x18($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X18);
    // 0x800375C8: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x800375CC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800375D0: sh          $t3, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r11;
    // 0x800375D4: lh          $t4, 0x18($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X18);
    // 0x800375D8: andi        $t0, $t9, 0xBFFF
    ctx->r8 = ctx->r25 & 0XBFFF;
    // 0x800375DC: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x800375E0: bne         $at, $zero, L_80037614
    if (ctx->r1 != 0) {
        // 0x800375E4: sh          $t0, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r8;
            goto L_80037614;
    }
    // 0x800375E4: sh          $t0, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r8;
    // 0x800375E8: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
    // 0x800375EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800375F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800375F4: jal         0x8006F94C
    // 0x800375F8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800375F8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x800375FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80037600: nop

    // 0x80037604: lw          $t5, 0x7C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X7C);
    // 0x80037608: nop

    // 0x8003760C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80037610: sw          $t6, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r14;
L_80037614:
    // 0x80037614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003761C: jr          $ra
    // 0x80037620: nop

    return;
    // 0x80037620: nop

;}
RECOMP_FUNC void mark_save_file_to_erase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECAC: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x8006ECB0: sll         $t7, $t6, 10
    ctx->r15 = S32(ctx->r14 << 10);
    // 0x8006ECB4: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x8006ECB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006ECBC: jr          $ra
    // 0x8006ECC0: sw          $t8, -0x2C84($at)
    MEM_W(-0X2C84, ctx->r1) = ctx->r24;
    return;
    // 0x8006ECC0: sw          $t8, -0x2C84($at)
    MEM_W(-0X2C84, ctx->r1) = ctx->r24;
;}
