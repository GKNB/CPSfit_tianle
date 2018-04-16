	.file	"main.C"
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.section	.text._ZnwmPv,"axG",@progbits,_ZnwmPv,comdat
	.weak	_ZnwmPv
	.type	_ZnwmPv, @function
_ZnwmPv:
.LFB382:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE382:
	.size	_ZnwmPv, .-_ZnwmPv
	.section	.text._ZdlPvS_,"axG",@progbits,_ZdlPvS_,comdat
	.weak	_ZdlPvS_
	.type	_ZdlPvS_, @function
_ZdlPvS_:
.LFB384:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE384:
	.size	_ZdlPvS_, .-_ZdlPvS_
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.type	_ZStL13allocator_arg, @object
	.size	_ZStL13allocator_arg, 1
_ZStL13allocator_arg:
	.zero	1
	.type	_ZStL6ignore, @object
	.size	_ZStL6ignore, 1
_ZStL6ignore:
	.zero	1
	.section	.text._ZN7basemomC2Ev,"axG",@progbits,_ZN7basemomC5Ev,comdat
	.align 2
	.weak	_ZN7basemomC2Ev
	.type	_ZN7basemomC2Ev, @function
_ZN7basemomC2Ev:
.LFB1772:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	movq	-8(%rbp), %rax
	movl	$0, 4(%rax)
	movq	-8(%rbp), %rax
	movl	$0, 8(%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1772:
	.size	_ZN7basemomC2Ev, .-_ZN7basemomC2Ev
	.weak	_ZN7basemomC1Ev
	.set	_ZN7basemomC1Ev,_ZN7basemomC2Ev
	.section	.text._ZN7basemomC2Eiii,"axG",@progbits,_ZN7basemomC5Eiii,comdat
	.align 2
	.weak	_ZN7basemomC2Eiii
	.type	_ZN7basemomC2Eiii, @function
_ZN7basemomC2Eiii:
.LFB1778:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	-16(%rbp), %edx
	movl	%edx, 4(%rax)
	movq	-8(%rbp), %rax
	movl	-20(%rbp), %edx
	movl	%edx, 8(%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1778:
	.size	_ZN7basemomC2Eiii, .-_ZN7basemomC2Eiii
	.weak	_ZN7basemomC1Eiii
	.set	_ZN7basemomC1Eiii,_ZN7basemomC2Eiii
	.section	.rodata
.LC0:
	.string	"three_momentum_simple.h"
.LC1:
	.string	"x >= 0 && x < 3"
	.section	.text._ZN7basemomclEi,"axG",@progbits,_ZN7basemomclEi,comdat
	.align 2
	.weak	_ZN7basemomclEi
	.type	_ZN7basemomclEi, @function
_ZN7basemomclEi:
.LFB1780:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	cmpl	$0, -12(%rbp)
	js	.L7
	cmpl	$2, -12(%rbp)
	jle	.L8
.L7:
	movl	$_ZZN7basemomclEiE19__PRETTY_FUNCTION__, %ecx
	movl	$46, %edx
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	__assert_fail
.L8:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1780:
	.size	_ZN7basemomclEi, .-_ZN7basemomclEi
	.section	.text._ZN7basemom5nzeroEv,"axG",@progbits,_ZN7basemom5nzeroEv,comdat
	.align 2
	.weak	_ZN7basemom5nzeroEv
	.type	_ZN7basemom5nzeroEv, @function
_ZN7basemom5nzeroEv:
.LFB1781:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -56(%rbp)
	movl	$0, -4(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	addq	$12, %rax
	movq	%rax, -32(%rbp)
	jmp	.L11
.L13:
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -36(%rbp)
	cmpl	$0, -36(%rbp)
	jne	.L12
	addl	$1, -4(%rbp)
.L12:
	addq	$4, -16(%rbp)
.L11:
	movq	-16(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jne	.L13
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1781:
	.size	_ZN7basemom5nzeroEv, .-_ZN7basemom5nzeroEv
	.section	.rodata
	.align 8
.LC2:
	.string	"abs(p[i]) % divide_by == 0 && \"Error: when convert basemom to file_str, has to make sure mom is integer multiples of devide num\\n\""
	.section	.text._ZNK7basemom8file_strEi,"axG",@progbits,_ZNK7basemom8file_strEi,comdat
	.align 2
	.weak	_ZNK7basemom8file_strEi
	.type	_ZNK7basemom8file_strEi, @function
_ZNK7basemom8file_strEi:
.LFB1782:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1782
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$408, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -392(%rbp)
	movq	%rsi, -400(%rbp)
	movl	%edx, -404(%rbp)
	leaq	-384(%rbp), %rax
	movl	$16, %esi
	movq	%rax, %rdi
.LEHB0:
	call	_ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEEC1ESt13_Ios_Openmode
.LEHE0:
	movl	$0, -20(%rbp)
	jmp	.L16
.L19:
	movq	-400(%rbp), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	testl	%eax, %eax
	jns	.L17
	leaq	-384(%rbp), %rax
	movl	$95, %esi
	movq	%rax, %rdi
.LEHB1:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
.L17:
	movq	-400(%rbp), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cltd
	xorl	%edx, %eax
	subl	%edx, %eax
	cltd
	idivl	-404(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	je	.L18
	movl	$_ZZNK7basemom8file_strEiE19__PRETTY_FUNCTION__, %ecx
	movl	$74, %edx
	movl	$.LC0, %esi
	movl	$.LC2, %edi
	call	__assert_fail
.L18:
	movq	-400(%rbp), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cltd
	idivl	-404(%rbp)
	cltd
	xorl	%edx, %eax
	subl	%edx, %eax
	leaq	-384(%rbp), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi
	addl	$1, -20(%rbp)
.L16:
	cmpl	$2, -20(%rbp)
	jle	.L19
	movq	-392(%rbp), %rax
	leaq	-384(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt19basic_ostringstreamIcSt11char_traitsIcESaIcEE3strEv
.LEHE1:
	nop
	leaq	-384(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L23
.L22:
	movq	%rax, %rbx
	leaq	-384(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L23:
	movq	-392(%rbp), %rax
	addq	$408, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1782:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZNK7basemom8file_strEi,"aG",@progbits,_ZNK7basemom8file_strEi,comdat
.LLSDA1782:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1782-.LLSDACSB1782
.LLSDACSB1782:
	.uleb128 .LEHB0-.LFB1782
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1782
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L22-.LFB1782
	.uleb128 0
	.uleb128 .LEHB2-.LFB1782
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE1782:
	.section	.text._ZNK7basemom8file_strEi,"axG",@progbits,_ZNK7basemom8file_strEi,comdat
	.size	_ZNK7basemom8file_strEi, .-_ZNK7basemom8file_strEi
	.section	.text._ZN7basemomngEv,"axG",@progbits,_ZN7basemomngEv,comdat
	.align 2
	.weak	_ZN7basemomngEv
	.type	_ZN7basemomngEv, @function
_ZN7basemomngEv:
.LFB1783:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	negl	%eax
	movl	%eax, %ecx
	movq	-40(%rbp), %rax
	movl	4(%rax), %eax
	negl	%eax
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	negl	%eax
	movl	%eax, %esi
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7basemomC1Eiii
	movq	-16(%rbp), %rax
	movq	%rax, -32(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -24(%rbp)
	movq	-32(%rbp), %rdx
	movl	-24(%rbp), %eax
	movq	%rdx, %rcx
	movl	%eax, %edx
	movq	%rcx, %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1783:
	.size	_ZN7basemomngEv, .-_ZN7basemomngEv
	.section	.text._ZNK7basemomneERKS_,"axG",@progbits,_ZNK7basemomneERKS_,comdat
	.align 2
	.weak	_ZNK7basemomneERKS_
	.type	_ZNK7basemomneERKS_, @function
_ZNK7basemomneERKS_:
.LFB1785:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jne	.L27
	movq	-8(%rbp), %rax
	movl	4(%rax), %edx
	movq	-16(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	%eax, %edx
	jne	.L27
	movq	-8(%rbp), %rax
	movl	8(%rax), %edx
	movq	-16(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	%eax, %edx
	je	.L28
.L27:
	movl	$1, %eax
	jmp	.L29
.L28:
	movl	$0, %eax
.L29:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1785:
	.size	_ZNK7basemomneERKS_, .-_ZNK7basemomneERKS_
	.section	.text._ZN7basemompLERKS_,"axG",@progbits,_ZN7basemompLERKS_,comdat
	.align 2
	.weak	_ZN7basemompLERKS_
	.type	_ZN7basemompLERKS_, @function
_ZN7basemompLERKS_:
.LFB1786:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L32
.L33:
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %ecx
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	addl	%eax, %ecx
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -4(%rbp)
.L32:
	cmpl	$2, -4(%rbp)
	jle	.L33
	movq	-24(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1786:
	.size	_ZN7basemompLERKS_, .-_ZN7basemompLERKS_
	.section	.text._ZNK7basemomplERKS_,"axG",@progbits,_ZNK7basemomplERKS_,comdat
	.align 2
	.weak	_ZNK7basemomplERKS_
	.type	_ZNK7basemomplERKS_, @function
_ZNK7basemomplERKS_:
.LFB1787:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movl	8(%rax), %ecx
	movq	-40(%rbp), %rax
	movl	4(%rax), %edx
	movq	-40(%rbp), %rax
	movl	(%rax), %esi
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7basemomC1Eiii
	movq	-48(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7basemompLERKS_
	movq	-32(%rbp), %rax
	movq	%rax, -16(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -8(%rbp)
	movq	-16(%rbp), %rdx
	movl	-8(%rbp), %eax
	movq	%rdx, %rcx
	movl	%eax, %edx
	movq	%rcx, %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1787:
	.size	_ZNK7basemomplERKS_, .-_ZNK7basemomplERKS_
	.section	.text._ZNSt5arrayI7basemomLm8EEC2Ev,"axG",@progbits,_ZNSt5arrayI7basemomLm8EEC5Ev,comdat
	.align 2
	.weak	_ZNSt5arrayI7basemomLm8EEC2Ev
	.type	_ZNSt5arrayI7basemomLm8EEC2Ev, @function
_ZNSt5arrayI7basemomLm8EEC2Ev:
.LFB1792:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	$7, %ebx
	movq	%rax, %r12
	jmp	.L38
.L39:
	movq	%r12, %rdi
	call	_ZN7basemomC1Ev
	addq	$12, %r12
	subq	$1, %rbx
.L38:
	cmpq	$-1, %rbx
	jne	.L39
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1792:
	.size	_ZNSt5arrayI7basemomLm8EEC2Ev, .-_ZNSt5arrayI7basemomLm8EEC2Ev
	.weak	_ZNSt5arrayI7basemomLm8EEC1Ev
	.set	_ZNSt5arrayI7basemomLm8EEC1Ev,_ZNSt5arrayI7basemomLm8EEC2Ev
	.section	.text._ZN22pion_basemom_containerC2Ev,"axG",@progbits,_ZN22pion_basemom_containerC5Ev,comdat
	.align 2
	.weak	_ZN22pion_basemom_containerC2Ev
	.type	_ZN22pion_basemom_containerC2Ev, @function
_ZN22pion_basemom_containerC2Ev:
.LFB1794:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt5arrayI7basemomLm8EEC1Ev
	movq	-72(%rbp), %rax
	movl	$2, 96(%rax)
	movq	-72(%rbp), %rax
	movl	$-2, 100(%rax)
	movl	$0, -20(%rbp)
	jmp	.L41
.L45:
	movl	$0, -24(%rbp)
	jmp	.L42
.L43:
	movl	-24(%rbp), %eax
	cltq
	movl	$0, -64(%rbp,%rax,4)
	addl	$1, -24(%rbp)
.L42:
	cmpl	$2, -24(%rbp)
	jle	.L43
	cmpl	$0, -20(%rbp)
	je	.L44
	movl	-20(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	subl	$1, %eax
	cltq
	movl	$1, -64(%rbp,%rax,4)
.L44:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt5arrayI7basemomLm8EEixEm
	movq	%rax, %rbx
	movl	-56(%rbp), %edx
	movq	-72(%rbp), %rax
	movslq	%edx, %rdx
	addq	$24, %rdx
	movl	(%rax,%rdx,4), %ecx
	movl	-60(%rbp), %edx
	movq	-72(%rbp), %rax
	movslq	%edx, %rdx
	addq	$24, %rdx
	movl	(%rax,%rdx,4), %edx
	movl	-64(%rbp), %esi
	movq	-72(%rbp), %rax
	movslq	%esi, %rsi
	addq	$24, %rsi
	movl	(%rax,%rsi,4), %esi
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7basemomC1Eiii
	movq	-48(%rbp), %rax
	movq	%rax, (%rbx)
	movl	-40(%rbp), %eax
	movl	%eax, 8(%rbx)
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt5arrayI7basemomLm8EEixEm
	movq	%rax, %rbx
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt5arrayI7basemomLm8EEixEm
	movq	%rax, %rdi
	call	_ZN7basemomngEv
	movq	%rax, %rcx
	movl	%edx, %eax
	movq	%rcx, (%rbx)
	movl	%eax, 8(%rbx)
	addl	$2, -20(%rbp)
.L41:
	cmpl	$7, -20(%rbp)
	jle	.L45
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1794:
	.size	_ZN22pion_basemom_containerC2Ev, .-_ZN22pion_basemom_containerC2Ev
	.weak	_ZN22pion_basemom_containerC1Ev
	.set	_ZN22pion_basemom_containerC1Ev,_ZN22pion_basemom_containerC2Ev
	.section	.text._ZN22pion_basemom_containerclEi,"axG",@progbits,_ZN22pion_basemom_containerclEi,comdat
	.align 2
	.weak	_ZN22pion_basemom_containerclEi
	.type	_ZN22pion_basemom_containerclEi, @function
_ZN22pion_basemom_containerclEi:
.LFB1796:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt5arrayI7basemomLm8EE2atEm
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1796:
	.size	_ZN22pion_basemom_containerclEi, .-_ZN22pion_basemom_containerclEi
	.section	.text._ZNK22pion_basemom_containerixEi,"axG",@progbits,_ZNK22pion_basemom_containerixEi,comdat
	.align 2
	.weak	_ZNK22pion_basemom_containerixEi
	.type	_ZNK22pion_basemom_containerixEi, @function
_ZNK22pion_basemom_containerixEi:
.LFB1797:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt5arrayI7basemomLm8EE2atEm
	movq	%rax, %rcx
	movq	-8(%rbp), %rax
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNK7basemom8file_strEi
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1797:
	.size	_ZNK22pion_basemom_containerixEi, .-_ZNK22pion_basemom_containerixEi
	.section	.rodata
.LC3:
	.string	"!(code<0 || code>4095)"
	.text
	.globl	_Z12code_to_pidxiRiS_S_S_
	.type	_Z12code_to_pidxiRiS_S_S_, @function
_Z12code_to_pidxiRiS_S_S_:
.LFB1798:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	%r8, -40(%rbp)
	cmpl	$0, -4(%rbp)
	js	.L51
	cmpl	$4095, -4(%rbp)
	jle	.L52
.L51:
	movl	$_ZZ12code_to_pidxiRiS_S_S_E19__PRETTY_FUNCTION__, %ecx
	movl	$163, %edx
	movl	$.LC0, %esi
	movl	$.LC3, %edi
	call	__assert_fail
.L52:
	movl	-4(%rbp), %eax
	cltd
	shrl	$29, %edx
	addl	%edx, %eax
	andl	$7, %eax
	subl	%edx, %eax
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
	sarl	$3, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$29, %eax
	addl	%eax, %edx
	andl	$7, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %edx
	movq	-32(%rbp), %rax
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
	sarl	$6, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$29, %eax
	addl	%eax, %edx
	andl	$7, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
	sarl	$9, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$29, %eax
	addl	%eax, %edx
	andl	$7, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1798:
	.size	_Z12code_to_pidxiRiS_S_S_, .-_Z12code_to_pidxiRiS_S_S_
	.section	.rodata
.LC4:
	.string	"!(code<0 || code>63)"
	.text
	.globl	_Z12code_to_pidxiRiS_
	.type	_Z12code_to_pidxiRiS_, @function
_Z12code_to_pidxiRiS_:
.LFB1799:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpl	$0, -4(%rbp)
	js	.L54
	cmpl	$63, -4(%rbp)
	jle	.L55
.L54:
	movl	$_ZZ12code_to_pidxiRiS_E19__PRETTY_FUNCTION__, %ecx
	movl	$172, %edx
	movl	$.LC0, %esi
	movl	$.LC4, %edi
	call	__assert_fail
.L55:
	movl	-4(%rbp), %eax
	cltd
	shrl	$29, %edx
	addl	%edx, %eax
	andl	$7, %eax
	subl	%edx, %eax
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
	sarl	$3, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$29, %eax
	addl	%eax, %edx
	andl	$7, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1799:
	.size	_Z12code_to_pidxiRiS_, .-_Z12code_to_pidxiRiS_
	.section	.rodata
	.align 8
.LC5:
	.string	"!(psrc1<0 || psrc1>7 || psrc2<0 || psrc2>7 || psnk1<0 || psnk1>7 || psnk2<0 || psnk2>7)"
	.text
	.globl	_Z12pidx_to_codeRiiiii
	.type	_Z12pidx_to_codeRiiiii, @function
_Z12pidx_to_codeRiiiii:
.LFB1800:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movl	%r8d, -24(%rbp)
	cmpl	$0, -12(%rbp)
	js	.L57
	cmpl	$7, -12(%rbp)
	jg	.L57
	cmpl	$0, -16(%rbp)
	js	.L57
	cmpl	$7, -16(%rbp)
	jg	.L57
	cmpl	$0, -20(%rbp)
	js	.L57
	cmpl	$7, -20(%rbp)
	jg	.L57
	cmpl	$0, -24(%rbp)
	js	.L57
	cmpl	$7, -24(%rbp)
	jle	.L58
.L57:
	movl	$_ZZ12pidx_to_codeRiiiiiE19__PRETTY_FUNCTION__, %ecx
	movl	$179, %edx
	movl	$.LC0, %esi
	movl	$.LC5, %edi
	call	__assert_fail
.L58:
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movl	-12(%rbp), %eax
	addl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	leal	0(,%rax,8), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movl	-16(%rbp), %eax
	addl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	leal	0(,%rax,8), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movl	-20(%rbp), %eax
	addl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	leal	0(,%rax,8), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movl	-24(%rbp), %eax
	addl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1800:
	.size	_Z12pidx_to_codeRiiiii, .-_Z12pidx_to_codeRiiiii
	.section	.rodata
	.align 8
.LC6:
	.string	"!(psrc<0 || psrc>7 || psnk<0 || psnk>7)"
	.text
	.globl	_Z12pidx_to_codeRiii
	.type	_Z12pidx_to_codeRiii, @function
_Z12pidx_to_codeRiii:
.LFB1801:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	cmpl	$0, -12(%rbp)
	js	.L60
	cmpl	$7, -12(%rbp)
	jg	.L60
	cmpl	$0, -16(%rbp)
	js	.L60
	cmpl	$7, -16(%rbp)
	jle	.L61
.L60:
	movl	$_ZZ12pidx_to_codeRiiiE19__PRETTY_FUNCTION__, %ecx
	movl	$192, %edx
	movl	$.LC0, %esi
	movl	$.LC6, %edi
	call	__assert_fail
.L61:
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movl	-12(%rbp), %eax
	addl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	leal	0(,%rax,8), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movl	-16(%rbp), %eax
	addl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1801:
	.size	_Z12pidx_to_codeRiii, .-_Z12pidx_to_codeRiii
	.section	.text._ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED2Ev,"axG",@progbits,_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED5Ev,comdat
	.align 2
	.weak	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED2Ev
	.type	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED2Ev, @function
_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED2Ev:
.LFB1804:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED1Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1804:
	.size	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED2Ev, .-_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED2Ev
	.weak	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED1Ev
	.set	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED1Ev,_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED2Ev
	.section	.rodata
.LC7:
	.string	"prod = "
	.align 8
.LC8:
	.string	"prod == p_src2(i) * p_src2(j) * p_snk2(i) * p_snk2(j)"
.LC9:
	.string	"  "
	.section	.text._ZN23MovingPiPiCase3_ddCoeffC2Ev,"axG",@progbits,_ZN23MovingPiPiCase3_ddCoeffC5Ev,comdat
	.align 2
	.weak	_ZN23MovingPiPiCase3_ddCoeffC2Ev
	.type	_ZN23MovingPiPiCase3_ddCoeffC2Ev, @function
_ZN23MovingPiPiCase3_ddCoeffC2Ev:
.LFB1806:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1806
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$376, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -376(%rbp)
	movq	-376(%rbp), %rax
	movq	%rax, %rdi
.LEHB3:
	call	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC1Ev
.LEHE3:
	leaq	-368(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN22pion_basemom_containerC1Ev
	movq	-376(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE5clearEv
	movl	$0, -148(%rbp)
	jmp	.L65
.L79:
	movl	-148(%rbp), %eax
	leaq	-144(%rbp), %rdi
	leaq	-140(%rbp), %rcx
	leaq	-136(%rbp), %rdx
	leaq	-132(%rbp), %rsi
	movq	%rdi, %r8
	movl	%eax, %edi
	call	_Z12code_to_pidxiRiS_S_S_
	movl	-132(%rbp), %edx
	leaq	-368(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
.LEHB4:
	call	_ZN22pion_basemom_containerclEi
	movq	(%rax), %rdx
	movq	%rdx, -160(%rbp)
	movl	8(%rax), %eax
	movl	%eax, -152(%rbp)
	movl	-136(%rbp), %edx
	leaq	-368(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN22pion_basemom_containerclEi
	movq	(%rax), %rdx
	movq	%rdx, -176(%rbp)
	movl	8(%rax), %eax
	movl	%eax, -168(%rbp)
	movl	-140(%rbp), %edx
	leaq	-368(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN22pion_basemom_containerclEi
	movq	(%rax), %rdx
	movq	%rdx, -192(%rbp)
	movl	8(%rax), %eax
	movl	%eax, -184(%rbp)
	movl	-144(%rbp), %edx
	leaq	-368(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN22pion_basemom_containerclEi
	movq	(%rax), %rdx
	movq	%rdx, -208(%rbp)
	movl	8(%rax), %eax
	movl	%eax, -200(%rbp)
	leaq	-176(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNK7basemomplERKS_
	movq	%rax, %rcx
	movl	%edx, %eax
	movq	%rcx, -224(%rbp)
	movl	%eax, -216(%rbp)
	leaq	-208(%rbp), %rdx
	leaq	-192(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNK7basemomplERKS_
	movq	%rax, %rcx
	movl	%edx, %eax
	movq	%rcx, -240(%rbp)
	movl	%eax, -232(%rbp)
	leaq	-240(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7basemomngEv
	movq	%rax, %rcx
	movl	%edx, %eax
	movq	%rcx, -128(%rbp)
	movl	%eax, -120(%rbp)
	movl	$1, %ebx
	leaq	-128(%rbp), %rdx
	leaq	-224(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNK7basemomneERKS_
	testb	%al, %al
	jne	.L66
	leaq	-224(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7basemom5nzeroEv
	cmpl	$2, %eax
	je	.L67
.L66:
	movl	$1, %eax
	jmp	.L68
.L67:
	movl	$0, %eax
.L68:
	testb	%bl, %bl
	testb	%al, %al
	jne	.L71
	movl	$0, -20(%rbp)
	jmp	.L72
.L75:
	movl	-20(%rbp), %edx
	leaq	-224(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN7basemomclEi
	movl	(%rax), %eax
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L73
	jmp	.L74
.L73:
	addl	$1, -20(%rbp)
.L72:
	cmpl	$2, -20(%rbp)
	jle	.L75
.L74:
	movl	-20(%rbp), %eax
	leal	1(%rax), %ecx
	movl	$1431655766, %edx
	movl	%ecx, %eax
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -24(%rbp)
	movl	-20(%rbp), %eax
	leal	2(%rax), %ecx
	movl	$1431655766, %edx
	movl	%ecx, %eax
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %edx
	leaq	-160(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN7basemomclEi
	movl	(%rax), %ebx
	movl	-28(%rbp), %edx
	leaq	-160(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN7basemomclEi
	movl	(%rax), %eax
	imull	%eax, %ebx
	movl	-24(%rbp), %edx
	leaq	-192(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN7basemomclEi
	movl	(%rax), %eax
	imull	%eax, %ebx
	movl	-28(%rbp), %edx
	leaq	-192(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN7basemomclEi
	movl	(%rax), %eax
	imull	%ebx, %eax
	movl	%eax, -32(%rbp)
	movl	$.LC7, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movl	-32(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	-24(%rbp), %edx
	leaq	-176(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN7basemomclEi
	movl	(%rax), %ebx
	movl	-28(%rbp), %edx
	leaq	-176(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN7basemomclEi
	movl	(%rax), %eax
	imull	%eax, %ebx
	movl	-24(%rbp), %edx
	leaq	-208(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN7basemomclEi
	movl	(%rax), %eax
	imull	%eax, %ebx
	movl	-28(%rbp), %edx
	leaq	-208(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN7basemomclEi
	movl	(%rax), %eax
	imull	%ebx, %eax
	cmpl	-32(%rbp), %eax
	je	.L76
	movl	$_ZZN23MovingPiPiCase3_ddCoeffC4EvE19__PRETTY_FUNCTION__, %ecx
	movl	$228, %edx
	movl	$.LC0, %esi
	movl	$.LC8, %edi
	call	__assert_fail
.L76:
	movq	-376(%rbp), %rax
	leaq	-148(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_
	cmpl	$0, -32(%rbp)
	jle	.L77
	movl	$1, %edx
	jmp	.L78
.L77:
	movl	$-1, %edx
.L78:
	movl	%edx, (%rax)
.L71:
	movl	-148(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -148(%rbp)
.L65:
	movl	-148(%rbp), %eax
	cmpl	$4095, %eax
	jle	.L79
	movq	-376(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4sizeEv
	movq	%rax, %rsi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEm
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movq	-376(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE6cbeginEv
	movq	%rax, -256(%rbp)
	jmp	.L80
.L81:
	leaq	-256(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEptEv
	movl	(%rax), %eax
	leaq	-144(%rbp), %rdi
	leaq	-140(%rbp), %rcx
	leaq	-136(%rbp), %rdx
	leaq	-132(%rbp), %rsi
	movq	%rdi, %r8
	movl	%eax, %edi
	call	_Z12code_to_pidxiRiS_S_S_
	leaq	-256(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEptEv
	movl	4(%rax), %ebx
	movl	-144(%rbp), %edx
	leaq	-112(%rbp), %rax
	leaq	-368(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNK22pion_basemom_containerixEi
.LEHE4:
	movl	-140(%rbp), %edx
	leaq	-96(%rbp), %rax
	leaq	-368(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB5:
	call	_ZNK22pion_basemom_containerixEi
.LEHE5:
	movl	-136(%rbp), %edx
	leaq	-80(%rbp), %rax
	leaq	-368(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB6:
	call	_ZNK22pion_basemom_containerixEi
.LEHE6:
	movl	-132(%rbp), %edx
	leaq	-64(%rbp), %rax
	leaq	-368(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB7:
	call	_ZNK22pion_basemom_containerixEi
.LEHE7:
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt4cout, %edi
.LEHB8:
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$.LC9, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$.LC9, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$.LC9, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$.LC9, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
.LEHE8:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSsD1Ev
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSsD1Ev
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSsD1Ev
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSsD1Ev
	leaq	-256(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEppEi
.L80:
	movq	-376(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4cendEv
	movq	%rax, -48(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-256(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEneERKS3_
	testb	%al, %al
	jne	.L81
	jmp	.L92
.L90:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSsD1Ev
	jmp	.L83
.L89:
	movq	%rax, %rbx
.L83:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSsD1Ev
	jmp	.L84
.L88:
	movq	%rax, %rbx
.L84:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSsD1Ev
	jmp	.L85
.L87:
	movq	%rax, %rbx
.L85:
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSsD1Ev
	jmp	.L86
.L91:
	movq	%rax, %rbx
.L86:
	movq	-376(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB9:
	call	_Unwind_Resume
.LEHE9:
.L92:
	addq	$376, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1806:
	.section	.gcc_except_table._ZN23MovingPiPiCase3_ddCoeffC2Ev,"aG",@progbits,_ZN23MovingPiPiCase3_ddCoeffC5Ev,comdat
.LLSDA1806:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1806-.LLSDACSB1806
.LLSDACSB1806:
	.uleb128 .LEHB3-.LFB1806
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB1806
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L91-.LFB1806
	.uleb128 0
	.uleb128 .LEHB5-.LFB1806
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L87-.LFB1806
	.uleb128 0
	.uleb128 .LEHB6-.LFB1806
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L88-.LFB1806
	.uleb128 0
	.uleb128 .LEHB7-.LFB1806
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L89-.LFB1806
	.uleb128 0
	.uleb128 .LEHB8-.LFB1806
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L90-.LFB1806
	.uleb128 0
	.uleb128 .LEHB9-.LFB1806
	.uleb128 .LEHE9-.LEHB9
	.uleb128 0
	.uleb128 0
.LLSDACSE1806:
	.section	.text._ZN23MovingPiPiCase3_ddCoeffC2Ev,"axG",@progbits,_ZN23MovingPiPiCase3_ddCoeffC5Ev,comdat
	.size	_ZN23MovingPiPiCase3_ddCoeffC2Ev, .-_ZN23MovingPiPiCase3_ddCoeffC2Ev
	.weak	_ZN23MovingPiPiCase3_ddCoeffC1Ev
	.set	_ZN23MovingPiPiCase3_ddCoeffC1Ev,_ZN23MovingPiPiCase3_ddCoeffC2Ev
	.section	.text._ZN23MovingPiPiCase3_ddCoeffD2Ev,"axG",@progbits,_ZN23MovingPiPiCase3_ddCoeffD5Ev,comdat
	.align 2
	.weak	_ZN23MovingPiPiCase3_ddCoeffD2Ev
	.type	_ZN23MovingPiPiCase3_ddCoeffD2Ev, @function
_ZN23MovingPiPiCase3_ddCoeffD2Ev:
.LFB1810:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEED1Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1810:
	.size	_ZN23MovingPiPiCase3_ddCoeffD2Ev, .-_ZN23MovingPiPiCase3_ddCoeffD2Ev
	.weak	_ZN23MovingPiPiCase3_ddCoeffD1Ev
	.set	_ZN23MovingPiPiCase3_ddCoeffD1Ev,_ZN23MovingPiPiCase3_ddCoeffD2Ev
	.text
	.globl	main
	.type	main, @function
main:
.LFB1808:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN23MovingPiPiCase3_ddCoeffC1Ev
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN23MovingPiPiCase3_ddCoeffD1Ev
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1808:
	.size	main, .-main
	.section	.text._ZNSt14__array_traitsI7basemomLm8EE6_S_refERA8_KS0_m,"axG",@progbits,_ZNSt14__array_traitsI7basemomLm8EE6_S_refERA8_KS0_m,comdat
	.weak	_ZNSt14__array_traitsI7basemomLm8EE6_S_refERA8_KS0_m
	.type	_ZNSt14__array_traitsI7basemomLm8EE6_S_refERA8_KS0_m, @function
_ZNSt14__array_traitsI7basemomLm8EE6_S_refERA8_KS0_m:
.LFB1880:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-8(%rbp), %rdx
	addq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1880:
	.size	_ZNSt14__array_traitsI7basemomLm8EE6_S_refERA8_KS0_m, .-_ZNSt14__array_traitsI7basemomLm8EE6_S_refERA8_KS0_m
	.section	.text._ZNSt5arrayI7basemomLm8EEixEm,"axG",@progbits,_ZNSt5arrayI7basemomLm8EEixEm,comdat
	.align 2
	.weak	_ZNSt5arrayI7basemomLm8EEixEm
	.type	_ZNSt5arrayI7basemomLm8EEixEm, @function
_ZNSt5arrayI7basemomLm8EEixEm:
.LFB1879:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt14__array_traitsI7basemomLm8EE6_S_refERA8_KS0_m
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1879:
	.size	_ZNSt5arrayI7basemomLm8EEixEm, .-_ZNSt5arrayI7basemomLm8EEixEm
	.section	.rodata
	.align 8
.LC10:
	.string	"array::at: __n (which is %zu) >= _Nm (which is %zu)"
	.section	.text._ZNSt5arrayI7basemomLm8EE2atEm,"axG",@progbits,_ZNSt5arrayI7basemomLm8EE2atEm,comdat
	.align 2
	.weak	_ZNSt5arrayI7basemomLm8EE2atEm
	.type	_ZNSt5arrayI7basemomLm8EE2atEm, @function
_ZNSt5arrayI7basemomLm8EE2atEm:
.LFB1881:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$7, -16(%rbp)
	jbe	.L102
	movq	-16(%rbp), %rax
	movl	$8, %edx
	movq	%rax, %rsi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	_ZSt24__throw_out_of_range_fmtPKcz
.L102:
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt14__array_traitsI7basemomLm8EE6_S_refERA8_KS0_m
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1881:
	.size	_ZNSt5arrayI7basemomLm8EE2atEm, .-_ZNSt5arrayI7basemomLm8EE2atEm
	.section	.text._ZNKSt5arrayI7basemomLm8EE2atEm,"axG",@progbits,_ZNKSt5arrayI7basemomLm8EE2atEm,comdat
	.align 2
	.weak	_ZNKSt5arrayI7basemomLm8EE2atEm
	.type	_ZNKSt5arrayI7basemomLm8EE2atEm, @function
_ZNKSt5arrayI7basemomLm8EE2atEm:
.LFB1882:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$7, -16(%rbp)
	ja	.L105
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt14__array_traitsI7basemomLm8EE6_S_refERA8_KS0_m
	jmp	.L108
.L105:
	movq	-16(%rbp), %rax
	movl	$8, %edx
	movq	%rax, %rsi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	_ZSt24__throw_out_of_range_fmtPKcz
.L108:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1882:
	.size	_ZNKSt5arrayI7basemomLm8EE2atEm, .-_ZNKSt5arrayI7basemomLm8EE2atEm
	.section	.text._ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC2Ev,"axG",@progbits,_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC5Ev,comdat
	.align 2
	.weak	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC2Ev
	.type	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC2Ev, @function
_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC2Ev:
.LFB1884:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC1Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1884:
	.size	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC2Ev, .-_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC2Ev
	.weak	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC1Ev
	.set	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC1Ev,_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEC2Ev
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED5Ev,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED2Ev
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED2Ev, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED2Ev:
.LFB1888:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1888:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED2Ev, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED2Ev
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED1Ev
	.set	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED1Ev,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED2Ev
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED5Ev,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED2Ev
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED2Ev, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED2Ev:
.LFB1890:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1890
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EED1Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1890:
	.section	.gcc_except_table._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED2Ev,"aG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED5Ev,comdat
.LLSDA1890:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1890-.LLSDACSB1890
.LLSDACSB1890:
.LLSDACSE1890:
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED5Ev,comdat
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED2Ev, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED2Ev
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED1Ev
	.set	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED1Ev,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EED2Ev
	.section	.text._ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE5clearEv,"axG",@progbits,_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE5clearEv,comdat
	.align 2
	.weak	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE5clearEv
	.type	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE5clearEv, @function
_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE5clearEv:
.LFB1892:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1892:
	.size	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE5clearEv, .-_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE5clearEv
	.section	.text._ZNSt11_Tuple_implILm1EIEEC2Ev,"axG",@progbits,_ZNSt11_Tuple_implILm1EIEEC5Ev,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm1EIEEC2Ev
	.type	_ZNSt11_Tuple_implILm1EIEEC2Ev, @function
_ZNSt11_Tuple_implILm1EIEEC2Ev:
.LFB1898:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1898:
	.size	_ZNSt11_Tuple_implILm1EIEEC2Ev, .-_ZNSt11_Tuple_implILm1EIEEC2Ev
	.weak	_ZNSt11_Tuple_implILm1EJEEC2Ev
	.set	_ZNSt11_Tuple_implILm1EJEEC2Ev,_ZNSt11_Tuple_implILm1EIEEC2Ev
	.weak	_ZNSt11_Tuple_implILm1EIEEC1Ev
	.set	_ZNSt11_Tuple_implILm1EIEEC1Ev,_ZNSt11_Tuple_implILm1EIEEC2Ev
	.weak	_ZNSt11_Tuple_implILm1EJEEC1Ev
	.set	_ZNSt11_Tuple_implILm1EJEEC1Ev,_ZNSt11_Tuple_implILm1EIEEC1Ev
	.section	.text._ZNSt10_Head_baseILm0ERKiLb0EEC2ES1_,"axG",@progbits,_ZNSt10_Head_baseILm0ERKiLb0EEC5ES1_,comdat
	.align 2
	.weak	_ZNSt10_Head_baseILm0ERKiLb0EEC2ES1_
	.type	_ZNSt10_Head_baseILm0ERKiLb0EEC2ES1_, @function
_ZNSt10_Head_baseILm0ERKiLb0EEC2ES1_:
.LFB1901:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1901:
	.size	_ZNSt10_Head_baseILm0ERKiLb0EEC2ES1_, .-_ZNSt10_Head_baseILm0ERKiLb0EEC2ES1_
	.weak	_ZNSt10_Head_baseILm0ERKiLb0EEC1ES1_
	.set	_ZNSt10_Head_baseILm0ERKiLb0EEC1ES1_,_ZNSt10_Head_baseILm0ERKiLb0EEC2ES1_
	.section	.text._ZNSt11_Tuple_implILm0EIRKiEEC2ES1_,"axG",@progbits,_ZNSt11_Tuple_implILm0EIRKiEEC5ES1_,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm0EIRKiEEC2ES1_
	.type	_ZNSt11_Tuple_implILm0EIRKiEEC2ES1_, @function
_ZNSt11_Tuple_implILm0EIRKiEEC2ES1_:
.LFB1903:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm1EIEEC2Ev
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt10_Head_baseILm0ERKiLb0EEC2ES1_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1903:
	.size	_ZNSt11_Tuple_implILm0EIRKiEEC2ES1_, .-_ZNSt11_Tuple_implILm0EIRKiEEC2ES1_
	.weak	_ZNSt11_Tuple_implILm0EJRKiEEC2ES1_
	.set	_ZNSt11_Tuple_implILm0EJRKiEEC2ES1_,_ZNSt11_Tuple_implILm0EIRKiEEC2ES1_
	.weak	_ZNSt11_Tuple_implILm0EIRKiEEC1ES1_
	.set	_ZNSt11_Tuple_implILm0EIRKiEEC1ES1_,_ZNSt11_Tuple_implILm0EIRKiEEC2ES1_
	.weak	_ZNSt11_Tuple_implILm0EJRKiEEC1ES1_
	.set	_ZNSt11_Tuple_implILm0EJRKiEEC1ES1_,_ZNSt11_Tuple_implILm0EIRKiEEC1ES1_
	.section	.text._ZNSt5tupleIIRKiEEC2ES1_,"axG",@progbits,_ZNSt5tupleIIRKiEEC5ES1_,comdat
	.align 2
	.weak	_ZNSt5tupleIIRKiEEC2ES1_
	.type	_ZNSt5tupleIIRKiEEC2ES1_, @function
_ZNSt5tupleIIRKiEEC2ES1_:
.LFB1905:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EIRKiEEC2ES1_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1905:
	.size	_ZNSt5tupleIIRKiEEC2ES1_, .-_ZNSt5tupleIIRKiEEC2ES1_
	.weak	_ZNSt5tupleIJRKiEEC2ES1_
	.set	_ZNSt5tupleIJRKiEEC2ES1_,_ZNSt5tupleIIRKiEEC2ES1_
	.weak	_ZNSt5tupleIIRKiEEC1ES1_
	.set	_ZNSt5tupleIIRKiEEC1ES1_,_ZNSt5tupleIIRKiEEC2ES1_
	.weak	_ZNSt5tupleIJRKiEEC1ES1_
	.set	_ZNSt5tupleIJRKiEEC1ES1_,_ZNSt5tupleIIRKiEEC1ES1_
	.section	.text._ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_,"axG",@progbits,_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_,comdat
	.align 2
	.weak	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_
	.type	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_, @function
_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_:
.LFB1894:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1894
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movq	%rdi, -104(%rbp)
	movq	%rsi, -112(%rbp)
	movq	-112(%rbp), %rdx
	movq	-104(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB10:
	call	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE11lower_boundERS3_
.LEHE10:
	movq	%rax, -96(%rbp)
	movl	$0, %ebx
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE3endEv
	movq	%rax, -80(%rbp)
	movl	$1, %r12d
	leaq	-80(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEeqERKS3_
	testb	%al, %al
	jne	.L120
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEdeEv
	movq	%rax, %r13
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
.LEHB11:
	call	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE8key_compEv
.LEHE11:
	movl	$1, %ebx
	movq	-112(%rbp), %rcx
	leaq	-66(%rbp), %rax
	movq	%r13, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	testb	%al, %al
	je	.L121
.L120:
	movl	$1, %eax
	jmp	.L122
.L121:
	movl	$0, %eax
.L122:
	testb	%bl, %bl
	testb	%r12b, %r12b
	testb	%al, %al
	je	.L125
	movq	-112(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt5tupleIIRKiEEC1ES1_
	leaq	-96(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC1ERKSt17_Rb_tree_iteratorIS2_E
	movq	-104(%rbp), %rax
	leaq	-65(%rbp), %rcx
	leaq	-64(%rbp), %rdx
	movq	-48(%rbp), %rsi
	movq	%rcx, %r8
	movq	%rdx, %rcx
	movl	$_ZStL19piecewise_construct, %edx
	movq	%rax, %rdi
.LEHB12:
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	movq	%rax, -96(%rbp)
.L125:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEdeEv
	addq	$4, %rax
	jmp	.L131
.L130:
	testb	%bl, %bl
	testb	%r12b, %r12b
	nop
	movq	%rax, %rdi
	call	_Unwind_Resume
.LEHE12:
.L131:
	addq	$88, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1894:
	.section	.gcc_except_table._ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_,"aG",@progbits,_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_,comdat
.LLSDA1894:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1894-.LLSDACSB1894
.LLSDACSB1894:
	.uleb128 .LEHB10-.LFB1894
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB11-.LFB1894
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L130-.LFB1894
	.uleb128 0
	.uleb128 .LEHB12-.LFB1894
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
.LLSDACSE1894:
	.section	.text._ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_,"axG",@progbits,_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_,comdat
	.size	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_, .-_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixERS3_
	.section	.text._ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4sizeEv,"axG",@progbits,_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4sizeEv,comdat
	.align 2
	.weak	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4sizeEv
	.type	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4sizeEv, @function
_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4sizeEv:
.LFB1907:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE4sizeEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1907:
	.size	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4sizeEv, .-_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4sizeEv
	.section	.text._ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE6cbeginEv,"axG",@progbits,_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE6cbeginEv,comdat
	.align 2
	.weak	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE6cbeginEv
	.type	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE6cbeginEv, @function
_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE6cbeginEv:
.LFB1909:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1909:
	.size	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE6cbeginEv, .-_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE6cbeginEv
	.section	.text._ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4cendEv,"axG",@progbits,_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4cendEv,comdat
	.align 2
	.weak	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4cendEv
	.type	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4cendEv, @function
_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4cendEv:
.LFB1910:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1910:
	.size	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4cendEv, .-_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE4cendEv
	.section	.text._ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEneERKS3_,"axG",@progbits,_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEneERKS3_,comdat
	.align 2
	.weak	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEneERKS3_
	.type	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEneERKS3_, @function
_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEneERKS3_:
.LFB1911:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	setne	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1911:
	.size	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEneERKS3_, .-_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEneERKS3_
	.section	.text._ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEppEi,"axG",@progbits,_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEppEi,comdat
	.align 2
	.weak	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEppEi
	.type	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEppEi, @function
_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEppEi:
.LFB1912:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZSt18_Rb_tree_incrementPKSt18_Rb_tree_node_base
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1912:
	.size	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEppEi, .-_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEppEi
	.section	.text._ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEptEv,"axG",@progbits,_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEptEv,comdat
	.align 2
	.weak	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEptEv
	.type	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEptEv, @function
_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEptEv:
.LFB1913:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZNKSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1913:
	.size	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEptEv, .-_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEEptEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC5Ev,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC2Ev
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC2Ev, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC2Ev:
.LFB1980:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC1Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1980:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC2Ev, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC2Ev
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC1Ev
	.set	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC1Ev,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EEC2Ev
	.section	.text._ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev,"axG",@progbits,_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED5Ev,comdat
	.align 2
	.weak	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev
	.type	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev, @function
_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev:
.LFB1983:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1983:
	.size	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev, .-_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev
	.weak	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED1Ev
	.set	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED1Ev,_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E:
.LFB1985:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	jmp	.L148
.L149:
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_S_leftEPSt18_Rb_tree_node_base
	movq	%rax, -8(%rbp)
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E
	movq	-8(%rbp), %rax
	movq	%rax, -32(%rbp)
.L148:
	cmpq	$0, -32(%rbp)
	jne	.L149
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1985:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv:
.LFB1986:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1986:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv:
.LFB1987:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1987
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv
	movq	%rax, (%rbx)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_M_rootEv
	movq	$0, (%rax)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv
	movq	%rax, (%rbx)
	movq	-24(%rbp), %rax
	movq	$0, 40(%rax)
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1987:
	.section	.gcc_except_table._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv,"aG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv,comdat
.LLSDA1987:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1987-.LLSDACSB1987
.LLSDACSB1987:
.LLSDACSE1987:
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv,comdat
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5clearEv
	.section	.text._ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE11lower_boundERS3_,"axG",@progbits,_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE11lower_boundERS3_,comdat
	.align 2
	.weak	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE11lower_boundERS3_
	.type	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE11lower_boundERS3_, @function
_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE11lower_boundERS3_:
.LFB1989:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11lower_boundERS1_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1989:
	.size	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE11lower_boundERS3_, .-_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE11lower_boundERS3_
	.section	.text._ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE8key_compEv,"axG",@progbits,_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE8key_compEv,comdat
	.align 2
	.weak	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE8key_compEv
	.type	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE8key_compEv, @function
_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE8key_compEv:
.LFB1990:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8key_compEv
	movl	%ebx, %eax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1990:
	.size	_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE8key_compEv, .-_ZNKSt3mapIiiSt4lessIiESaISt4pairIKiiEEE8key_compEv
	.section	.text._ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEdeEv,"axG",@progbits,_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEdeEv,comdat
	.align 2
	.weak	_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEdeEv
	.type	_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEdeEv, @function
_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEdeEv:
.LFB1991:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZNSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1991:
	.size	_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEdeEv, .-_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEdeEv
	.section	.text._ZNKSt4lessIiEclERKiS2_,"axG",@progbits,_ZNKSt4lessIiEclERKiS2_,comdat
	.align 2
	.weak	_ZNKSt4lessIiEclERKiS2_
	.type	_ZNKSt4lessIiEclERKiS2_, @function
_ZNKSt4lessIiEclERKiS2_:
.LFB1992:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	setl	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1992:
	.size	_ZNKSt4lessIiEclERKiS2_, .-_ZNKSt4lessIiEclERKiS2_
	.section	.text._ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE3endEv,"axG",@progbits,_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE3endEv,comdat
	.align 2
	.weak	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE3endEv
	.type	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE3endEv, @function
_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE3endEv:
.LFB1993:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1993:
	.size	_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE3endEv, .-_ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEE3endEv
	.section	.text._ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEeqERKS3_,"axG",@progbits,_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEeqERKS3_,comdat
	.align 2
	.weak	_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEeqERKS3_
	.type	_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEeqERKS3_, @function
_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEeqERKS3_:
.LFB1994:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	sete	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1994:
	.size	_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEeqERKS3_, .-_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEeqERKS3_
	.section	.text._ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2ERKSt17_Rb_tree_iteratorIS2_E,"axG",@progbits,_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC5ERKSt17_Rb_tree_iteratorIS2_E,comdat
	.align 2
	.weak	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2ERKSt17_Rb_tree_iteratorIS2_E
	.type	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2ERKSt17_Rb_tree_iteratorIS2_E, @function
_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2ERKSt17_Rb_tree_iteratorIS2_E:
.LFB1996:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1996:
	.size	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2ERKSt17_Rb_tree_iteratorIS2_E, .-_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2ERKSt17_Rb_tree_iteratorIS2_E
	.weak	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC1ERKSt17_Rb_tree_iteratorIS2_E
	.set	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC1ERKSt17_Rb_tree_iteratorIS2_E,_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2ERKSt17_Rb_tree_iteratorIS2_E
	.section	.text._ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE,"axG",@progbits,_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE,comdat
	.weak	_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	.type	_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE, @function
_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE:
.LFB1999:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1999:
	.size	_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE, .-_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	.section	.text._ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE,"axG",@progbits,_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE,comdat
	.weak	_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE
	.type	_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE, @function
_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE:
.LFB2000:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2000:
	.size	_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE, .-_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE
	.weak	_ZSt7forwardISt5tupleIJRKiEEEOT_RNSt16remove_referenceIS4_E4typeE
	.set	_ZSt7forwardISt5tupleIJRKiEEEOT_RNSt16remove_referenceIS4_E4typeE,_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE
	.section	.text._ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE,"axG",@progbits,_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE,comdat
	.weak	_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE
	.type	_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE, @function
_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE:
.LFB2001:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2001:
	.size	_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE, .-_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE
	.weak	_ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE
	.set	_ZSt7forwardISt5tupleIJEEEOT_RNSt16remove_referenceIS2_E4typeE,_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_:
.LFB1998:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1998
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$80, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%rcx, -80(%rbp)
	movq	%r8, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %r12
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %rbx
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movq	%rax, %rsi
	movq	-56(%rbp), %rax
	movq	%r12, %rcx
	movq	%rbx, %rdx
	movq	%rax, %rdi
.LEHB13:
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_
.LEHE13:
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
.LEHB14:
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E
	movq	%rax, %rdx
	movq	-64(%rbp), %rcx
	movq	-56(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rax
	testq	%rax, %rax
	je	.L173
	movq	-40(%rbp), %rdx
	movq	-48(%rbp), %rsi
	movq	-24(%rbp), %rcx
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E
.LEHE14:
	jmp	.L180
.L173:
	movq	-24(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E
	movq	-48(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC1EPSt13_Rb_tree_nodeIS2_E
	movq	-32(%rbp), %rax
	jmp	.L180
.L178:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	-24(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E
.LEHB15:
	call	__cxa_rethrow
.LEHE15:
.L179:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB16:
	call	_Unwind_Resume
.LEHE16:
.L180:
	addq	$80, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1998:
	.section	.gcc_except_table._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,"aG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,comdat
	.align 4
.LLSDA1998:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT1998-.LLSDATTD1998
.LLSDATTD1998:
	.byte	0x1
	.uleb128 .LLSDACSE1998-.LLSDACSB1998
.LLSDACSB1998:
	.uleb128 .LEHB13-.LFB1998
	.uleb128 .LEHE13-.LEHB13
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB14-.LFB1998
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L178-.LFB1998
	.uleb128 0x1
	.uleb128 .LEHB15-.LFB1998
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L179-.LFB1998
	.uleb128 0
	.uleb128 .LEHB16-.LFB1998
	.uleb128 .LEHE16-.LEHB16
	.uleb128 0
	.uleb128 0
.LLSDACSE1998:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT1998:
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,comdat
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.set	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE22_M_emplace_hint_uniqueIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_
	.section	.text._ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE4sizeEv,"axG",@progbits,_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE4sizeEv,comdat
	.align 2
	.weak	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE4sizeEv
	.type	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE4sizeEv, @function
_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE4sizeEv:
.LFB2002:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	40(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2002:
	.size	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE4sizeEv, .-_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE4sizeEv
	.section	.text._ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv,"axG",@progbits,_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv,comdat
	.align 2
	.weak	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv
	.type	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv, @function
_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv:
.LFB2003:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	24(%rax), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC1EPKSt13_Rb_tree_nodeIS2_E
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2003:
	.size	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv, .-_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv
	.section	.text._ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv,"axG",@progbits,_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv,comdat
	.align 2
	.weak	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv
	.type	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv, @function
_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv:
.LFB2004:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC1EPKSt13_Rb_tree_nodeIS2_E
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2004:
	.size	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv, .-_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv
	.section	.text._ZNKSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv,"axG",@progbits,_ZNKSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv,comdat
	.align 2
	.weak	_ZNKSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv
	.type	_ZNKSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv, @function
_ZNKSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv:
.LFB2005:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2005:
	.size	_ZNKSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv, .-_ZNKSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC5Ev,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC2Ev
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC2Ev, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC2Ev:
.LFB2047:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev
	movq	-8(%rbp), %rax
	movl	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 24(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 32(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 40(%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EE13_M_initializeEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2047:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC2Ev, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC2Ev
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC1Ev
	.set	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC1Ev,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EEC2Ev
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev:
.LFB2050:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2050:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED1Ev
	.set	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED1Ev,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEED2Ev
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base,comdat
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base:
.LFB2052:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2052:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_S_leftEPSt18_Rb_tree_node_base,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_S_leftEPSt18_Rb_tree_node_base,comdat
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_S_leftEPSt18_Rb_tree_node_base
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_S_leftEPSt18_Rb_tree_node_base, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_S_leftEPSt18_Rb_tree_node_base:
.LFB2053:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2053:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_S_leftEPSt18_Rb_tree_node_base, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_S_leftEPSt18_Rb_tree_node_base
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E:
.LFB2054:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA2054
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE7destroyIS3_EEvRS5_PT_
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2054:
	.section	.gcc_except_table._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E,"aG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E,comdat
.LLSDA2054:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2054-.LLSDACSB2054
.LLSDACSB2054:
.LLSDACSE2054:
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E,comdat
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE15_M_destroy_nodeEPSt13_Rb_tree_nodeIS2_E
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv:
.LFB2055:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2055:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv:
.LFB2056:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$24, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2056:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_M_rootEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_M_rootEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_M_rootEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_M_rootEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_M_rootEv:
.LFB2057:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$16, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2057:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_M_rootEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_M_rootEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv:
.LFB2058:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$32, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2058:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11lower_boundERS1_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11lower_boundERS1_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11lower_boundERS1_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11lower_boundERS1_, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11lower_boundERS1_:
.LFB2060:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv
	movq	%rax, %rsi
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rcx
	movq	%rbx, %rdx
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_lower_boundEPSt13_Rb_tree_nodeIS2_ESB_RS1_
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2060:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11lower_boundERS1_, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11lower_boundERS1_
	.section	.text._ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8key_compEv,"axG",@progbits,_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8key_compEv,comdat
	.align 2
	.weak	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8key_compEv
	.type	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8key_compEv, @function
_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8key_compEv:
.LFB2061:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2061:
	.size	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8key_compEv, .-_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8key_compEv
	.section	.text._ZNSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv,"axG",@progbits,_ZNSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv,comdat
	.align 2
	.weak	_ZNSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv
	.type	_ZNSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv, @function
_ZNSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv:
.LFB2062:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2062:
	.size	_ZNSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv, .-_ZNSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv:
.LFB2063:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC1EPSt13_Rb_tree_nodeIS2_E
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2063:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE3endEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_:
.LFB2064:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA2064
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$48, %rsp
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%rcx, -80(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
.LEHB17:
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_get_nodeEv
.LEHE17:
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rsi
	movl	$40, %edi
	call	_ZnwmPv
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %r14
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %r13
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movq	%rax, %r12
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv
	movq	%r14, %r8
	movq	%r13, %rcx
	movq	%r12, %rdx
	movq	%rbx, %rsi
	movq	%rax, %rdi
.LEHB18:
	call	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_
.LEHE18:
	movq	-40(%rbp), %rax
	jmp	.L219
.L217:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	-40(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E
.LEHB19:
	call	__cxa_rethrow
.LEHE19:
.L218:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB20:
	call	_Unwind_Resume
.LEHE20:
.L219:
	addq	$48, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2064:
	.section	.gcc_except_table._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_,"aG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_,comdat
	.align 4
.LLSDA2064:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT2064-.LLSDATTD2064
.LLSDATTD2064:
	.byte	0x1
	.uleb128 .LLSDACSE2064-.LLSDACSB2064
.LLSDACSB2064:
	.uleb128 .LEHB17-.LFB2064
	.uleb128 .LEHE17-.LEHB17
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB18-.LFB2064
	.uleb128 .LEHE18-.LEHB18
	.uleb128 .L217-.LFB2064
	.uleb128 0x1
	.uleb128 .LEHB19-.LFB2064
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L218-.LFB2064
	.uleb128 0
	.uleb128 .LEHB20-.LFB2064
	.uleb128 .LEHE20-.LEHB20
	.uleb128 0
	.uleb128 0
.LLSDACSE2064:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT2064:
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_,comdat
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_
	.set	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_create_nodeIIRKSt21piecewise_construct_tSt5tupleIIRS1_EESD_IIEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_
	.section	.text._ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE,"axG",@progbits,_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE,comdat
	.weak	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	.type	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE, @function
_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE:
.LFB2067:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2067:
	.size	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE, .-_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	.section	.text._ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEERKS1_OT_,"axG",@progbits,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC5IRS1_vEERKS1_OT_,comdat
	.align 2
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEERKS1_OT_
	.type	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEERKS1_OT_, @function
_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEERKS1_OT_:
.LFB2068:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2068:
	.size	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEERKS1_OT_, .-_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEERKS1_OT_
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_vEERKS1_OT_
	.set	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_vEERKS1_OT_,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEERKS1_OT_
	.section	.text._ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_S4_vEEOT_OT0_,"axG",@progbits,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC5IRS1_S4_vEEOT_OT0_,comdat
	.align 2
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_S4_vEEOT_OT0_
	.type	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_S4_vEEOT_OT0_, @function
_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_S4_vEEOT_OT0_:
.LFB2071:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2071:
	.size	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_S4_vEEOT_OT0_, .-_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_S4_vEEOT_OT0_
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_vEEOT_OT0_
	.set	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_vEEOT_OT0_,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_S4_vEEOT_OT0_
	.section	.text._ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEEOT_RKS1_,"axG",@progbits,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC5IRS1_vEEOT_RKS1_,comdat
	.align 2
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEEOT_RKS1_
	.type	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEEOT_RKS1_, @function
_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEEOT_RKS1_:
.LFB2074:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2074:
	.size	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEEOT_RKS1_, .-_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEEOT_RKS1_
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_vEEOT_RKS1_
	.set	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_vEEOT_RKS1_,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_vEEOT_RKS1_
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_:
.LFB2065:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$296, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -280(%rbp)
	movq	%rsi, -288(%rbp)
	movq	%rdx, -296(%rbp)
	leaq	-288(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEE13_M_const_castEv
	movq	%rax, -240(%rbp)
	movq	-240(%rbp), %rbx
	movq	-280(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv
	cmpq	%rax, %rbx
	sete	%al
	testb	%al, %al
	je	.L226
	movq	-280(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE4sizeEv
	testq	%rax, %rax
	je	.L227
	movq	-280(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base
	movq	%rax, %rcx
	movq	-280(%rbp), %rax
	movq	-296(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	testb	%al, %al
	je	.L227
	movl	$1, %eax
	jmp	.L228
.L227:
	movl	$0, %eax
.L228:
	testb	%al, %al
	je	.L229
	movq	-280(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv
	movq	%rax, %rdx
	movq	$0, -200(%rbp)
	leaq	-200(%rbp), %rcx
	leaq	-224(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_vEERKS1_OT_
	movq	-224(%rbp), %rax
	movq	-216(%rbp), %rdx
	jmp	.L241
.L229:
	movq	-296(%rbp), %rdx
	movq	-280(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	jmp	.L241
.L226:
	movq	-240(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base
	movq	%rax, %rdx
	movq	-280(%rbp), %rax
	movq	-296(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	testb	%al, %al
	je	.L231
	movq	-240(%rbp), %rax
	movq	%rax, -256(%rbp)
	movq	-240(%rbp), %rbx
	movq	-280(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv
	movq	(%rax), %rax
	cmpq	%rax, %rbx
	sete	%al
	testb	%al, %al
	je	.L232
	movq	-280(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv
	movq	%rax, %rbx
	movq	-280(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_leftmostEv
	movq	%rax, %rcx
	leaq	-192(%rbp), %rax
	movq	%rbx, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_vEEOT_OT0_
	movq	-192(%rbp), %rax
	movq	-184(%rbp), %rdx
	jmp	.L241
.L232:
	leaq	-256(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEmmEv
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base
	movq	%rax, %rcx
	movq	-280(%rbp), %rax
	movq	-296(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	testb	%al, %al
	je	.L234
	movq	-256(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base
	testq	%rax, %rax
	sete	%al
	testb	%al, %al
	je	.L235
	movq	$0, -152(%rbp)
	leaq	-256(%rbp), %rdx
	leaq	-152(%rbp), %rcx
	leaq	-176(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_vEERKS1_OT_
	movq	-176(%rbp), %rax
	movq	-168(%rbp), %rdx
	jmp	.L241
.L235:
	leaq	-240(%rbp), %rdx
	leaq	-240(%rbp), %rcx
	leaq	-144(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_vEEOT_OT0_
	movq	-144(%rbp), %rax
	movq	-136(%rbp), %rdx
	jmp	.L241
.L234:
	movq	-296(%rbp), %rdx
	movq	-280(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	jmp	.L241
.L231:
	movq	-240(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base
	movq	%rax, %rcx
	movq	-280(%rbp), %rax
	movq	-296(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	testb	%al, %al
	je	.L236
	movq	-240(%rbp), %rax
	movq	%rax, -272(%rbp)
	movq	-240(%rbp), %rbx
	movq	-280(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv
	movq	(%rax), %rax
	cmpq	%rax, %rbx
	sete	%al
	testb	%al, %al
	je	.L237
	movq	-280(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE12_M_rightmostEv
	movq	%rax, %rdx
	movq	$0, -104(%rbp)
	leaq	-104(%rbp), %rcx
	leaq	-128(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_vEERKS1_OT_
	movq	-128(%rbp), %rax
	movq	-120(%rbp), %rdx
	jmp	.L241
.L237:
	leaq	-272(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEppEv
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base
	movq	%rax, %rdx
	movq	-280(%rbp), %rax
	movq	-296(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	testb	%al, %al
	je	.L239
	movq	-240(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base
	testq	%rax, %rax
	sete	%al
	testb	%al, %al
	je	.L240
	movq	$0, -72(%rbp)
	leaq	-240(%rbp), %rdx
	leaq	-72(%rbp), %rcx
	leaq	-96(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_vEERKS1_OT_
	movq	-96(%rbp), %rax
	movq	-88(%rbp), %rdx
	jmp	.L241
.L240:
	leaq	-272(%rbp), %rdx
	leaq	-272(%rbp), %rcx
	leaq	-64(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_S4_vEEOT_OT0_
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rdx
	jmp	.L241
.L239:
	movq	-296(%rbp), %rdx
	movq	-280(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	jmp	.L241
.L236:
	movq	$0, -24(%rbp)
	leaq	-24(%rbp), %rdx
	leaq	-240(%rbp), %rcx
	leaq	-48(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_vEEOT_RKS1_
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
.L241:
	addq	$296, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2065:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E,comdat
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E:
.LFB2076:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt13_Rb_tree_nodeIS2_E
	movq	%rax, %rdx
	leaq	-1(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt10_Select1stISt4pairIKiiEEclERKS2_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2076:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E:
.LFB2077:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%rcx, -64(%rbp)
	cmpq	$0, -48(%rbp)
	jne	.L245
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv
	cmpq	-56(%rbp), %rax
	je	.L245
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base
	movq	%rax, %rbx
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	movq	%rbx, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	testb	%al, %al
	je	.L246
.L245:
	movl	$1, %eax
	jmp	.L247
.L246:
	movl	$0, %eax
.L247:
	movb	%al, -17(%rbp)
	movq	-40(%rbp), %rax
	leaq	8(%rax), %rcx
	movzbl	-17(%rbp), %eax
	movq	-56(%rbp), %rdx
	movq	-64(%rbp), %rsi
	movl	%eax, %edi
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	movq	-40(%rbp), %rax
	movq	40(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, 40(%rax)
	movq	-64(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC1EPSt13_Rb_tree_nodeIS2_E
	movq	-32(%rbp), %rax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2077:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_insert_nodeEPSt18_Rb_tree_node_baseSA_PSt13_Rb_tree_nodeIS2_E
	.section	.text._ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC2EPSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC5EPSt13_Rb_tree_nodeIS2_E,comdat
	.align 2
	.weak	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC2EPSt13_Rb_tree_nodeIS2_E
	.type	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC2EPSt13_Rb_tree_nodeIS2_E, @function
_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC2EPSt13_Rb_tree_nodeIS2_E:
.LFB2079:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2079:
	.size	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC2EPSt13_Rb_tree_nodeIS2_E, .-_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC2EPSt13_Rb_tree_nodeIS2_E
	.weak	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC1EPSt13_Rb_tree_nodeIS2_E
	.set	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC1EPSt13_Rb_tree_nodeIS2_E,_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC2EPSt13_Rb_tree_nodeIS2_E
	.section	.text._ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2EPKSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC5EPKSt13_Rb_tree_nodeIS2_E,comdat
	.align 2
	.weak	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2EPKSt13_Rb_tree_nodeIS2_E
	.type	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2EPKSt13_Rb_tree_nodeIS2_E, @function
_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2EPKSt13_Rb_tree_nodeIS2_E:
.LFB2082:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2082:
	.size	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2EPKSt13_Rb_tree_nodeIS2_E, .-_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2EPKSt13_Rb_tree_nodeIS2_E
	.weak	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC1EPKSt13_Rb_tree_nodeIS2_E
	.set	_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC1EPKSt13_Rb_tree_nodeIS2_E,_ZNSt23_Rb_tree_const_iteratorISt4pairIKiiEEC2EPKSt13_Rb_tree_nodeIS2_E
	.section	.text._ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv,"axG",@progbits,_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv
	.type	_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv, @function
_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv:
.LFB2084:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2084:
	.size	_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv, .-_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv
	.section	.text._ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev,"axG",@progbits,_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC5Ev,comdat
	.align 2
	.weak	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev
	.type	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev, @function
_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev:
.LFB2088:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2088:
	.size	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev, .-_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev
	.weak	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC1Ev
	.set	_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC1Ev,_ZNSaISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EE13_M_initializeEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EE13_M_initializeEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EE13_M_initializeEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EE13_M_initializeEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EE13_M_initializeEv:
.LFB2090:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-8(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 24(%rax)
	movq	-8(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 32(%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2090:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EE13_M_initializeEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE13_Rb_tree_implIS6_Lb1EE13_M_initializeEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv:
.LFB2091:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2091:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv
	.section	.text._ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE7destroyIS3_EEvRS5_PT_,"axG",@progbits,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE7destroyIS3_EEvRS5_PT_,comdat
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE7destroyIS3_EEvRS5_PT_
	.type	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE7destroyIS3_EEvRS5_PT_, @function
_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE7destroyIS3_EEvRS5_PT_:
.LFB2092:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IINS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2092:
	.size	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE7destroyIS3_EEvRS5_PT_, .-_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE7destroyIS3_EEvRS5_PT_
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E:
.LFB2093:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA2093
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv
	movq	%rax, %rcx
	movq	-16(%rbp), %rax
	movl	$1, %edx
	movq	%rax, %rsi
	movq	%rcx, %rdi
	call	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10deallocateERS5_PS4_m
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2093:
	.section	.gcc_except_table._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E,"aG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E,comdat
.LLSDA2093:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2093-.LLSDACSB2093
.LLSDACSB2093:
.LLSDACSE2093:
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E,comdat
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_put_nodeEPSt13_Rb_tree_nodeIS2_E
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_lower_boundEPSt13_Rb_tree_nodeIS2_ESB_RS1_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_lower_boundEPSt13_Rb_tree_nodeIS2_ESB_RS1_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_lower_boundEPSt13_Rb_tree_nodeIS2_ESB_RS1_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_lower_boundEPSt13_Rb_tree_nodeIS2_ESB_RS1_, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_lower_boundEPSt13_Rb_tree_nodeIS2_ESB_RS1_:
.LFB2094:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	jmp	.L260
.L262:
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E
	movq	%rax, %rcx
	movq	-24(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	xorl	$1, %eax
	testb	%al, %al
	je	.L261
	movq	-32(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_S_leftEPSt18_Rb_tree_node_base
	movq	%rax, -32(%rbp)
	jmp	.L260
.L261:
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base
	movq	%rax, -32(%rbp)
.L260:
	cmpq	$0, -32(%rbp)
	jne	.L262
	movq	-40(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC1EPSt13_Rb_tree_nodeIS2_E
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2094:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_lower_boundEPSt13_Rb_tree_nodeIS2_ESB_RS1_, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE14_M_lower_boundEPSt13_Rb_tree_nodeIS2_ESB_RS1_
	.section	.text._ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv,"axG",@progbits,_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv
	.type	_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv, @function
_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv:
.LFB2095:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2095:
	.size	_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv, .-_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE6_M_ptrEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_get_nodeEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_get_nodeEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_get_nodeEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_get_nodeEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_get_nodeEv:
.LFB2096:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE21_M_get_Node_allocatorEv
	movl	$1, %esi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE8allocateERS5_m
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2096:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_get_nodeEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE11_M_get_nodeEv
	.section	.text._ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_,"axG",@progbits,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_,comdat
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_
	.type	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_, @function
_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_:
.LFB2097:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$48, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	%r8, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %r12
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movq	%rax, %rdx
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rax
	movq	%r12, %r8
	movq	%rbx, %rcx
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEENSt9enable_ifIXsrSt6__and_IINS6_18__construct_helperIT_IDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_
	addq	$48, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2097:
	.size	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_, .-_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_JRKSt21piecewise_construct_tSt5tupleIJRS2_EESB_IJEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_
	.set	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_JRKSt21piecewise_construct_tSt5tupleIJRS2_EESB_IJEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE9constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEEDTcl12_S_constructfp_fp0_spcl7forwardIT0_Efp1_EEERS5_PT_DpOSF_
	.section	.text._ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEE13_M_const_castEv,"axG",@progbits,_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEE13_M_const_castEv,comdat
	.align 2
	.weak	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEE13_M_const_castEv
	.type	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEE13_M_const_castEv, @function
_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEE13_M_const_castEv:
.LFB2098:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC1EPSt13_Rb_tree_nodeIS2_E
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2098:
	.size	_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEE13_M_const_castEv, .-_ZNKSt23_Rb_tree_const_iteratorISt4pairIKiiEE13_M_const_castEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base,comdat
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base:
.LFB2099:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt18_Rb_tree_node_base
	movq	%rax, %rdx
	leaq	-1(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt10_Select1stISt4pairIKiiEEclERKS2_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2099:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base
	.section	.text._ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKiiEEEOT_RNSt16remove_referenceIS7_E4typeE,"axG",@progbits,_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKiiEEEOT_RNSt16remove_referenceIS7_E4typeE,comdat
	.weak	_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKiiEEEOT_RNSt16remove_referenceIS7_E4typeE
	.type	_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKiiEEEOT_RNSt16remove_referenceIS7_E4typeE, @function
_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKiiEEEOT_RNSt16remove_referenceIS7_E4typeE:
.LFB2102:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2102:
	.size	_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKiiEEEOT_RNSt16remove_referenceIS7_E4typeE, .-_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKiiEEEOT_RNSt16remove_referenceIS7_E4typeE
	.section	.text._ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_,"axG",@progbits,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC5IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_,comdat
	.align 2
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_
	.type	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_, @function
_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_:
.LFB2103:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKiiEEEOT_RNSt16remove_referenceIS7_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPSt13_Rb_tree_nodeISt4pairIKiiEEEOT_RNSt16remove_referenceIS7_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2103:
	.size	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_, .-_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_
	.set	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_:
.LFB2100:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movq	%rdi, -120(%rbp)
	movq	%rsi, -128(%rbp)
	movq	-120(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_M_beginEv
	movq	%rax, -88(%rbp)
	movq	-120(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_M_endEv
	movq	%rax, -96(%rbp)
	movb	$1, -1(%rbp)
	jmp	.L277
.L280:
	movq	-88(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt13_Rb_tree_nodeIS2_E
	movq	%rax, %rdx
	movq	-120(%rbp), %rax
	movq	-128(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	movb	%al, -1(%rbp)
	cmpb	$0, -1(%rbp)
	je	.L278
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE7_S_leftEPSt18_Rb_tree_node_base
	jmp	.L279
.L278:
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_rightEPSt18_Rb_tree_node_base
.L279:
	movq	%rax, -88(%rbp)
.L277:
	movq	-88(%rbp), %rax
	testq	%rax, %rax
	jne	.L280
	movq	-96(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC1EPSt13_Rb_tree_nodeIS2_E
	cmpb	$0, -1(%rbp)
	je	.L281
	movq	-120(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv
	movq	%rax, -80(%rbp)
	leaq	-80(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt17_Rb_tree_iteratorISt4pairIKiiEEeqERKS3_
	testb	%al, %al
	je	.L282
	leaq	-96(%rbp), %rdx
	leaq	-88(%rbp), %rcx
	leaq	-64(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rdx
	jmp	.L285
.L282:
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEmmEv
.L281:
	movq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE6_S_keyEPKSt18_Rb_tree_node_base
	movq	%rax, %rcx
	movq	-120(%rbp), %rax
	movq	-128(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	testb	%al, %al
	je	.L284
	leaq	-96(%rbp), %rdx
	leaq	-88(%rbp), %rcx
	leaq	-48(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIS_IKiiEES9_vEEOT_OT0_
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	jmp	.L285
.L284:
	movq	$0, -16(%rbp)
	leaq	-16(%rbp), %rdx
	leaq	-112(%rbp), %rcx
	leaq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_vEEOT_RKS1_
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
.L285:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2100:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE24_M_get_insert_unique_posERS1_
	.section	.text._ZNSt17_Rb_tree_iteratorISt4pairIKiiEEmmEv,"axG",@progbits,_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEmmEv,comdat
	.align 2
	.weak	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEmmEv
	.type	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEmmEv, @function
_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEmmEv:
.LFB2105:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2105:
	.size	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEmmEv, .-_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEmmEv
	.section	.text._ZNSt17_Rb_tree_iteratorISt4pairIKiiEEppEv,"axG",@progbits,_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEppEv,comdat
	.align 2
	.weak	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEppEv
	.type	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEppEv, @function
_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEppEv:
.LFB2106:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2106:
	.size	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEppEv, .-_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEppEv
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt13_Rb_tree_nodeIS2_E,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt13_Rb_tree_nodeIS2_E,comdat
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt13_Rb_tree_nodeIS2_E
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt13_Rb_tree_nodeIS2_E, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt13_Rb_tree_nodeIS2_E:
.LFB2107:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2107:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt13_Rb_tree_nodeIS2_E, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt13_Rb_tree_nodeIS2_E
	.section	.text._ZNKSt10_Select1stISt4pairIKiiEEclERKS2_,"axG",@progbits,_ZNKSt10_Select1stISt4pairIKiiEEclERKS2_,comdat
	.align 2
	.weak	_ZNKSt10_Select1stISt4pairIKiiEEclERKS2_
	.type	_ZNKSt10_Select1stISt4pairIKiiEEclERKS2_, @function
_ZNKSt10_Select1stISt4pairIKiiEEclERKS2_:
.LFB2108:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2108:
	.size	_ZNKSt10_Select1stISt4pairIKiiEEclERKS2_, .-_ZNKSt10_Select1stISt4pairIKiiEEclERKS2_
	.section	.text._ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv,"axG",@progbits,_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv
	.type	_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv, @function
_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv:
.LFB2109:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2109:
	.size	_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv, .-_ZNK9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev:
.LFB2113:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2113:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC1Ev
	.set	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC1Ev,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEEC2Ev
	.section	.text._ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IINS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_,"axG",@progbits,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IINS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_,comdat
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IINS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_
	.type	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IINS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_, @function
_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IINS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_:
.LFB2115:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE7destroyIS4_EEvPT_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2115:
	.size	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IINS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_, .-_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IINS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IJNS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_
	.set	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IJNS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10_S_destroyIS3_EENSt9enable_ifIXsrSt6__and_IINS6_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS5_PSB_
	.section	.text._ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10deallocateERS5_PS4_m,"axG",@progbits,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10deallocateERS5_PS4_m,comdat
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10deallocateERS5_PS4_m
	.type	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10deallocateERS5_PS4_m, @function
_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10deallocateERS5_PS4_m:
.LFB2116:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE10deallocateEPS5_m
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2116:
	.size	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10deallocateERS5_PS4_m, .-_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE10deallocateERS5_PS4_m
	.section	.text._ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv,"axG",@progbits,_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv
	.type	_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv, @function
_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv:
.LFB2117:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2117:
	.size	_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv, .-_ZN9__gnu_cxx16__aligned_bufferISt4pairIKiiEE7_M_addrEv
	.section	.text._ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE8allocateERS5_m,"axG",@progbits,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE8allocateERS5_m,comdat
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE8allocateERS5_m
	.type	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE8allocateERS5_m, @function
_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE8allocateERS5_m:
.LFB2118:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8allocateEmPKv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2118:
	.size	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE8allocateERS5_m, .-_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE8allocateERS5_m
	.section	.text._ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEENSt9enable_ifIXsrSt6__and_IINS6_18__construct_helperIT_IDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_,"axG",@progbits,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEENSt9enable_ifIXsrSt6__and_IINS6_18__construct_helperIT_IDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_,comdat
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEENSt9enable_ifIXsrSt6__and_IINS6_18__construct_helperIT_IDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_
	.type	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEENSt9enable_ifIXsrSt6__and_IINS6_18__construct_helperIT_IDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_, @function
_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEENSt9enable_ifIXsrSt6__and_IINS6_18__construct_helperIT_IDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_:
.LFB2119:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$48, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	%r8, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %r12
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movq	%rax, %rdx
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rax
	movq	%r12, %r8
	movq	%rbx, %rcx
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_
	addq	$48, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2119:
	.size	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEENSt9enable_ifIXsrSt6__and_IINS6_18__construct_helperIT_IDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_, .-_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEENSt9enable_ifIXsrSt6__and_IINS6_18__construct_helperIT_IDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_JRKSt21piecewise_construct_tSt5tupleIJRS2_EESB_IJEEEEENSt9enable_ifIXsrSt6__and_IJNS6_18__construct_helperIT_JDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_
	.set	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_JRKSt21piecewise_construct_tSt5tupleIJRS2_EESB_IJEEEEENSt9enable_ifIXsrSt6__and_IJNS6_18__construct_helperIT_JDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeISt4pairIKiiEEEE12_S_constructIS3_IRKSt21piecewise_construct_tSt5tupleIIRS2_EESB_IIEEEEENSt9enable_ifIXsrSt6__and_IINS6_18__construct_helperIT_IDpT0_EE4typeEEE5valueEvE4typeERS5_PSI_DpOSJ_
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt18_Rb_tree_node_base,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt18_Rb_tree_node_base,comdat
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt18_Rb_tree_node_base
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt18_Rb_tree_node_base, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt18_Rb_tree_node_base:
.LFB2120:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt13_Rb_tree_nodeISt4pairIKiiEE9_M_valptrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2120:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt18_Rb_tree_node_base, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE8_S_valueEPKSt18_Rb_tree_node_base
	.section	.text._ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv,"axG",@progbits,_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv
	.type	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv, @function
_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv:
.LFB2121:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	24(%rax), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorISt4pairIKiiEEC1EPSt13_Rb_tree_nodeIS2_E
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2121:
	.size	_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv, .-_ZNSt8_Rb_treeIiSt4pairIKiiESt10_Select1stIS2_ESt4lessIiESaIS2_EE5beginEv
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE7destroyIS4_EEvPT_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE7destroyIS4_EEvPT_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE7destroyIS4_EEvPT_
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE7destroyIS4_EEvPT_, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE7destroyIS4_EEvPT_:
.LFB2132:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2132:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE7destroyIS4_EEvPT_, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE7destroyIS4_EEvPT_
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE10deallocateEPS5_m,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE10deallocateEPS5_m,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE10deallocateEPS5_m
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE10deallocateEPS5_m, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE10deallocateEPS5_m:
.LFB2133:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2133:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE10deallocateEPS5_m, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE10deallocateEPS5_m
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8allocateEmPKv,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8allocateEmPKv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8allocateEmPKv
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8allocateEmPKv, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8allocateEmPKv:
.LFB2134:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8max_sizeEv
	cmpq	-16(%rbp), %rax
	setb	%al
	testb	%al, %al
	je	.L311
	call	_ZSt17__throw_bad_allocv
.L311:
	movq	-16(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdi
	call	_Znwm
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2134:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8allocateEmPKv, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8allocateEmPKv
	.section	.text._ZNSt11_Tuple_implILm0EIRKiEE7_M_tailERS2_,"axG",@progbits,_ZNSt11_Tuple_implILm0EIRKiEE7_M_tailERS2_,comdat
	.weak	_ZNSt11_Tuple_implILm0EIRKiEE7_M_tailERS2_
	.type	_ZNSt11_Tuple_implILm0EIRKiEE7_M_tailERS2_, @function
_ZNSt11_Tuple_implILm0EIRKiEE7_M_tailERS2_:
.LFB2138:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2138:
	.size	_ZNSt11_Tuple_implILm0EIRKiEE7_M_tailERS2_, .-_ZNSt11_Tuple_implILm0EIRKiEE7_M_tailERS2_
	.weak	_ZNSt11_Tuple_implILm0EJRKiEE7_M_tailERS2_
	.set	_ZNSt11_Tuple_implILm0EJRKiEE7_M_tailERS2_,_ZNSt11_Tuple_implILm0EIRKiEE7_M_tailERS2_
	.section	.text._ZSt4moveIRSt11_Tuple_implILm1EIEEEONSt16remove_referenceIT_E4typeEOS4_,"axG",@progbits,_ZSt4moveIRSt11_Tuple_implILm1EIEEEONSt16remove_referenceIT_E4typeEOS4_,comdat
	.weak	_ZSt4moveIRSt11_Tuple_implILm1EIEEEONSt16remove_referenceIT_E4typeEOS4_
	.type	_ZSt4moveIRSt11_Tuple_implILm1EIEEEONSt16remove_referenceIT_E4typeEOS4_, @function
_ZSt4moveIRSt11_Tuple_implILm1EIEEEONSt16remove_referenceIT_E4typeEOS4_:
.LFB2139:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2139:
	.size	_ZSt4moveIRSt11_Tuple_implILm1EIEEEONSt16remove_referenceIT_E4typeEOS4_, .-_ZSt4moveIRSt11_Tuple_implILm1EIEEEONSt16remove_referenceIT_E4typeEOS4_
	.weak	_ZSt4moveIRSt11_Tuple_implILm1EJEEEONSt16remove_referenceIT_E4typeEOS4_
	.set	_ZSt4moveIRSt11_Tuple_implILm1EJEEEONSt16remove_referenceIT_E4typeEOS4_,_ZSt4moveIRSt11_Tuple_implILm1EIEEEONSt16remove_referenceIT_E4typeEOS4_
	.section	.text._ZNSt10_Head_baseILm0ERKiLb0EE7_M_headERS2_,"axG",@progbits,_ZNSt10_Head_baseILm0ERKiLb0EE7_M_headERS2_,comdat
	.weak	_ZNSt10_Head_baseILm0ERKiLb0EE7_M_headERS2_
	.type	_ZNSt10_Head_baseILm0ERKiLb0EE7_M_headERS2_, @function
_ZNSt10_Head_baseILm0ERKiLb0EE7_M_headERS2_:
.LFB2141:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2141:
	.size	_ZNSt10_Head_baseILm0ERKiLb0EE7_M_headERS2_, .-_ZNSt10_Head_baseILm0ERKiLb0EE7_M_headERS2_
	.section	.text._ZNSt11_Tuple_implILm0EIRKiEE7_M_headERS2_,"axG",@progbits,_ZNSt11_Tuple_implILm0EIRKiEE7_M_headERS2_,comdat
	.weak	_ZNSt11_Tuple_implILm0EIRKiEE7_M_headERS2_
	.type	_ZNSt11_Tuple_implILm0EIRKiEE7_M_headERS2_, @function
_ZNSt11_Tuple_implILm0EIRKiEE7_M_headERS2_:
.LFB2140:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10_Head_baseILm0ERKiLb0EE7_M_headERS2_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2140:
	.size	_ZNSt11_Tuple_implILm0EIRKiEE7_M_headERS2_, .-_ZNSt11_Tuple_implILm0EIRKiEE7_M_headERS2_
	.weak	_ZNSt11_Tuple_implILm0EJRKiEE7_M_headERS2_
	.set	_ZNSt11_Tuple_implILm0EJRKiEE7_M_headERS2_,_ZNSt11_Tuple_implILm0EIRKiEE7_M_headERS2_
	.section	.text._ZSt7forwardIRKiEOT_RNSt16remove_referenceIS2_E4typeE,"axG",@progbits,_ZSt7forwardIRKiEOT_RNSt16remove_referenceIS2_E4typeE,comdat
	.weak	_ZSt7forwardIRKiEOT_RNSt16remove_referenceIS2_E4typeE
	.type	_ZSt7forwardIRKiEOT_RNSt16remove_referenceIS2_E4typeE, @function
_ZSt7forwardIRKiEOT_RNSt16remove_referenceIS2_E4typeE:
.LFB2142:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2142:
	.size	_ZSt7forwardIRKiEOT_RNSt16remove_referenceIS2_E4typeE, .-_ZSt7forwardIRKiEOT_RNSt16remove_referenceIS2_E4typeE
	.section	.text._ZNSt11_Tuple_implILm0EIRKiEEC2EOS2_,"axG",@progbits,_ZNSt11_Tuple_implILm0EIRKiEEC5EOS2_,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm0EIRKiEEC2EOS2_
	.type	_ZNSt11_Tuple_implILm0EIRKiEEC2EOS2_, @function
_ZNSt11_Tuple_implILm0EIRKiEEC2EOS2_:
.LFB2143:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EIRKiEE7_M_tailERS2_
	movq	%rax, %rdi
	call	_ZSt4moveIRSt11_Tuple_implILm1EIEEEONSt16remove_referenceIT_E4typeEOS4_
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EIRKiEE7_M_headERS2_
	movq	%rax, %rdi
	call	_ZSt7forwardIRKiEOT_RNSt16remove_referenceIS2_E4typeE
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt10_Head_baseILm0ERKiLb0EEC2ES1_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2143:
	.size	_ZNSt11_Tuple_implILm0EIRKiEEC2EOS2_, .-_ZNSt11_Tuple_implILm0EIRKiEEC2EOS2_
	.weak	_ZNSt11_Tuple_implILm0EJRKiEEC2EOS2_
	.set	_ZNSt11_Tuple_implILm0EJRKiEEC2EOS2_,_ZNSt11_Tuple_implILm0EIRKiEEC2EOS2_
	.weak	_ZNSt11_Tuple_implILm0EIRKiEEC1EOS2_
	.set	_ZNSt11_Tuple_implILm0EIRKiEEC1EOS2_,_ZNSt11_Tuple_implILm0EIRKiEEC2EOS2_
	.weak	_ZNSt11_Tuple_implILm0EJRKiEEC1EOS2_
	.set	_ZNSt11_Tuple_implILm0EJRKiEEC1EOS2_,_ZNSt11_Tuple_implILm0EIRKiEEC1EOS2_
	.section	.text._ZNSt5tupleIIRKiEEC2EOS2_,"axG",@progbits,_ZNSt5tupleIIRKiEEC5EOS2_,comdat
	.align 2
	.weak	_ZNSt5tupleIIRKiEEC2EOS2_
	.type	_ZNSt5tupleIIRKiEEC2EOS2_, @function
_ZNSt5tupleIIRKiEEC2EOS2_:
.LFB2145:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EIRKiEEC2EOS2_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2145:
	.size	_ZNSt5tupleIIRKiEEC2EOS2_, .-_ZNSt5tupleIIRKiEEC2EOS2_
	.weak	_ZNSt5tupleIJRKiEEC2EOS2_
	.set	_ZNSt5tupleIJRKiEEC2EOS2_,_ZNSt5tupleIIRKiEEC2EOS2_
	.weak	_ZNSt5tupleIIRKiEEC1EOS2_
	.set	_ZNSt5tupleIIRKiEEC1EOS2_,_ZNSt5tupleIIRKiEEC2EOS2_
	.weak	_ZNSt5tupleIJRKiEEC1EOS2_
	.set	_ZNSt5tupleIJRKiEEC1EOS2_,_ZNSt5tupleIIRKiEEC1EOS2_
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_:
.LFB2135:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA2135
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	%rcx, -96(%rbp)
	movq	%r8, -104(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRKSt21piecewise_construct_tEOT_RNSt16remove_referenceIS3_E4typeE
	movb	%r12b, -49(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt5tupleIIRKiEEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	%rax, %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt5tupleIIRKiEEC1EOS2_
	leaq	-48(%rbp), %r13
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt5tupleIIEEEOT_RNSt16remove_referenceIS2_E4typeE
	movb	%bl, -33(%rbp)
	movq	-80(%rbp), %r12
	movq	%r12, %rsi
	movl	$8, %edi
	call	_ZnwmPv
	movq	%rax, %rbx
	testq	%rbx, %rbx
	je	.L326
	movzbl	-33(%rbp), %eax
	pushq	%rax
	movzbl	-49(%rbp), %eax
	pushq	%rax
	movq	%r13, %rsi
	movq	%rbx, %rdi
.LEHB21:
	.cfi_escape 0x2e,0x10
	call	_ZNSt4pairIKiiEC1IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE
.LEHE21:
	addq	$16, %rsp
	jmp	.L325
.L326:
	jmp	.L325
.L329:
	movq	%rax, %r13
	movq	%r12, %rsi
	movq	%rbx, %rdi
	call	_ZdlPvS_
	movq	%r13, %rax
	movq	%rax, %rdi
.LEHB22:
	call	_Unwind_Resume
.LEHE22:
.L325:
	leaq	-24(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2135:
	.section	.gcc_except_table._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_,"aG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_,comdat
.LLSDA2135:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2135-.LLSDACSB2135
.LLSDACSB2135:
	.uleb128 .LEHB21-.LFB2135
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L329-.LFB2135
	.uleb128 0
	.uleb128 .LEHB22-.LFB2135
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0
	.uleb128 0
.LLSDACSE2135:
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_,comdat
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_JRKSt21piecewise_construct_tSt5tupleIJRS3_EESB_IJEEEEEvPT_DpOT0_
	.set	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_JRKSt21piecewise_construct_tSt5tupleIJRS3_EESB_IJEEEEEvPT_DpOT0_,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE9constructIS4_IRKSt21piecewise_construct_tSt5tupleIIRS3_EESB_IIEEEEEvPT_DpOT0_
	.section	.text._ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8max_sizeEv,"axG",@progbits,_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8max_sizeEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8max_sizeEv
	.type	_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8max_sizeEv, @function
_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8max_sizeEv:
.LFB2155:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movabsq	$461168601842738790, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2155:
	.size	_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8max_sizeEv, .-_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeISt4pairIKiiEEE8max_sizeEv
	.section	.text._ZNSt4pairIKiiEC2IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE,"axG",@progbits,_ZNSt4pairIKiiEC5IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE,comdat
	.align 2
	.weak	_ZNSt4pairIKiiEC2IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE
	.type	_ZNSt4pairIKiiEC2IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE, @function
_ZNSt4pairIKiiEC2IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE:
.LFB2157:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	leaq	24(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rax
	pushq	%r9
	pushq	%r8
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIKiiEC1IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE
	addq	$16, %rsp
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2157:
	.size	_ZNSt4pairIKiiEC2IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE, .-_ZNSt4pairIKiiEC2IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE
	.weak	_ZNSt4pairIKiiEC2IJRS0_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EES5_IJDpT0_EE
	.set	_ZNSt4pairIKiiEC2IJRS0_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EES5_IJDpT0_EE,_ZNSt4pairIKiiEC2IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE
	.weak	_ZNSt4pairIKiiEC1IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE
	.set	_ZNSt4pairIKiiEC1IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE,_ZNSt4pairIKiiEC2IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE
	.weak	_ZNSt4pairIKiiEC1IJRS0_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EES5_IJDpT0_EE
	.set	_ZNSt4pairIKiiEC1IJRS0_EJEEESt21piecewise_construct_tSt5tupleIJDpT_EES5_IJDpT0_EE,_ZNSt4pairIKiiEC1IIRS0_EIEEESt21piecewise_construct_tSt5tupleIIDpT_EES5_IIDpT0_EE
	.section	.text._ZSt12__get_helperILm0ERKiIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm0ERKiIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE,comdat
	.weak	_ZSt12__get_helperILm0ERKiIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE
	.type	_ZSt12__get_helperILm0ERKiIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE, @function
_ZSt12__get_helperILm0ERKiIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE:
.LFB2161:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EIRKiEE7_M_headERS2_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2161:
	.size	_ZSt12__get_helperILm0ERKiIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE, .-_ZSt12__get_helperILm0ERKiIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE
	.weak	_ZSt12__get_helperILm0ERKiJEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EJS3_DpT1_EE
	.set	_ZSt12__get_helperILm0ERKiJEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EJS3_DpT1_EE,_ZSt12__get_helperILm0ERKiIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE
	.section	.text._ZSt3getILm0EIRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS7_,"axG",@progbits,_ZSt3getILm0EIRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS7_,comdat
	.weak	_ZSt3getILm0EIRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS7_
	.type	_ZSt3getILm0EIRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS7_, @function
_ZSt3getILm0EIRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS7_:
.LFB2160:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__get_helperILm0ERKiIEENSt9__add_refIT0_E4typeERSt11_Tuple_implIXT_EIS3_DpT1_EE
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2160:
	.size	_ZSt3getILm0EIRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS7_, .-_ZSt3getILm0EIRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS7_
	.weak	_ZSt3getILm0EJRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEE4typeERS7_
	.set	_ZSt3getILm0EJRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeEE4typeERS7_,_ZSt3getILm0EIRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS7_
	.section	.text._ZNSt4pairIKiiEC2IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE,"axG",@progbits,_ZNSt4pairIKiiEC5IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE,comdat
	.align 2
	.weak	_ZNSt4pairIKiiEC2IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE
	.type	_ZNSt4pairIKiiEC2IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE, @function
_ZNSt4pairIKiiEC2IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE:
.LFB2162:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt3getILm0EIRKiEENSt9__add_refINSt13tuple_elementIXT_ESt5tupleIIDpT0_EEE4typeEE4typeERS7_
	movq	%rax, %rdi
	call	_ZSt7forwardIRKiEOT_RNSt16remove_referenceIS2_E4typeE
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	$0, 4(%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2162:
	.size	_ZNSt4pairIKiiEC2IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE, .-_ZNSt4pairIKiiEC2IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE
	.weak	_ZNSt4pairIKiiEC2IJRS0_EJLm0EEJEJEEERSt5tupleIJDpT_EERS4_IJDpT1_EESt12_Index_tupleIJXspT0_EEESD_IJXspT2_EEE
	.set	_ZNSt4pairIKiiEC2IJRS0_EJLm0EEJEJEEERSt5tupleIJDpT_EERS4_IJDpT1_EESt12_Index_tupleIJXspT0_EEESD_IJXspT2_EEE,_ZNSt4pairIKiiEC2IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE
	.weak	_ZNSt4pairIKiiEC1IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE
	.set	_ZNSt4pairIKiiEC1IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE,_ZNSt4pairIKiiEC2IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE
	.weak	_ZNSt4pairIKiiEC1IJRS0_EJLm0EEJEJEEERSt5tupleIJDpT_EERS4_IJDpT1_EESt12_Index_tupleIJXspT0_EEESD_IJXspT2_EEE
	.set	_ZNSt4pairIKiiEC1IJRS0_EJLm0EEJEJEEERSt5tupleIJDpT_EERS4_IJDpT1_EESt12_Index_tupleIJXspT0_EEESD_IJXspT2_EEE,_ZNSt4pairIKiiEC1IIRS0_EILm0EEIEIEEERSt5tupleIIDpT_EERS4_IIDpT1_EESt12_Index_tupleIIXspT0_EEESD_IIXspT2_EEE
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2164:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L338
	cmpl	$65535, -8(%rbp)
	jne	.L338
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L338:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2164:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z12code_to_pidxiRiS_S_S_, @function
_GLOBAL__sub_I__Z12code_to_pidxiRiS_S_S_:
.LFB2165:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2165:
	.size	_GLOBAL__sub_I__Z12code_to_pidxiRiS_S_S_, .-_GLOBAL__sub_I__Z12code_to_pidxiRiS_S_S_
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z12code_to_pidxiRiS_S_S_
	.section	.rodata
	.align 32
	.type	_ZZ12code_to_pidxiRiS_S_S_E19__PRETTY_FUNCTION__, @object
	.size	_ZZ12code_to_pidxiRiS_S_S_E19__PRETTY_FUNCTION__, 47
_ZZ12code_to_pidxiRiS_S_S_E19__PRETTY_FUNCTION__:
	.string	"void code_to_pidx(int, int&, int&, int&, int&)"
	.align 32
	.type	_ZZ12code_to_pidxiRiS_E19__PRETTY_FUNCTION__, @object
	.size	_ZZ12code_to_pidxiRiS_E19__PRETTY_FUNCTION__, 35
_ZZ12code_to_pidxiRiS_E19__PRETTY_FUNCTION__:
	.string	"void code_to_pidx(int, int&, int&)"
	.align 32
	.type	_ZZ12pidx_to_codeRiiiiiE19__PRETTY_FUNCTION__, @object
	.size	_ZZ12pidx_to_codeRiiiiiE19__PRETTY_FUNCTION__, 44
_ZZ12pidx_to_codeRiiiiiE19__PRETTY_FUNCTION__:
	.string	"void pidx_to_code(int&, int, int, int, int)"
	.align 32
	.type	_ZZ12pidx_to_codeRiiiE19__PRETTY_FUNCTION__, @object
	.size	_ZZ12pidx_to_codeRiiiE19__PRETTY_FUNCTION__, 34
_ZZ12pidx_to_codeRiiiE19__PRETTY_FUNCTION__:
	.string	"void pidx_to_code(int&, int, int)"
	.align 32
	.type	_ZZN23MovingPiPiCase3_ddCoeffC4EvE19__PRETTY_FUNCTION__, @object
	.size	_ZZN23MovingPiPiCase3_ddCoeffC4EvE19__PRETTY_FUNCTION__, 51
_ZZN23MovingPiPiCase3_ddCoeffC4EvE19__PRETTY_FUNCTION__:
	.string	"MovingPiPiCase3_ddCoeff::MovingPiPiCase3_ddCoeff()"
	.align 16
	.type	_ZZN7basemomclEiE19__PRETTY_FUNCTION__, @object
	.size	_ZZN7basemomclEiE19__PRETTY_FUNCTION__, 30
_ZZN7basemomclEiE19__PRETTY_FUNCTION__:
	.string	"int& basemom::operator()(int)"
	.align 32
	.type	_ZZNK7basemom8file_strEiE19__PRETTY_FUNCTION__, @object
	.size	_ZZNK7basemom8file_strEiE19__PRETTY_FUNCTION__, 41
_ZZNK7basemom8file_strEiE19__PRETTY_FUNCTION__:
	.string	"std::string basemom::file_str(int) const"
	.align 8
	.type	_ZZL18__gthread_active_pvE20__gthread_active_ptr, @object
	.size	_ZZL18__gthread_active_pvE20__gthread_active_ptr, 8
_ZZL18__gthread_active_pvE20__gthread_active_ptr:
	.quad	_ZL28__gthrw___pthread_key_createPjPFvPvE
	.weakref	_ZL28__gthrw___pthread_key_createPjPFvPvE,__pthread_key_create
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 4.9.3"
	.section	.note.GNU-stack,"",@progbits
