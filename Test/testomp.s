	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 0
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x28, x27, [sp, #-32]!           ; 16-byte Folded Spill
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16                    ; =16
	mov	w9, #20032
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	sub	sp, sp, #4, lsl #12             ; =16384
	sub	sp, sp, #3648                   ; =3648
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-24]
	str	wzr, [sp, #20]
	str	wzr, [sp, #12]
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	mov	w9, #5000
	subs	w8, w8, w9
	b.ge	LBB0_5
; %bb.2:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #0                      ; =0
	str	w8, [sp, #8]
	ldr	w8, [sp, #8]
	ldrsw	x10, [sp, #8]
	add	x9, sp, #24                     ; =24
	str	w8, [x9, x10, lsl #2]
; %bb.3:                                ;   in Loop: Header=BB0_1 Depth=1
; %bb.4:                                ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1                      ; =1
	str	w8, [sp, #12]
	b	LBB0_1
LBB0_5:
	mov	w8, #5000
	str	w8, [sp, #8]
	ldr	w8, [sp, #20]
	str	w8, [sp, #4]                    ; 4-byte Folded Spill
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	ldur	x9, [x29, #-24]
	subs	x8, x8, x9
	b.ne	LBB0_7
; %bb.6:
	ldr	w0, [sp, #4]                    ; 4-byte Folded Reload
	add	sp, sp, #4, lsl #12             ; =16384
	add	sp, sp, #3648                   ; =3648
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x28, x27, [sp], #32             ; 16-byte Folded Reload
	ret
LBB0_7:
	bl	___stack_chk_fail
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
