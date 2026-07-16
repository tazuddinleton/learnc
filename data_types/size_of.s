	.file	"size_of.c"
	.text
	.section	.rodata
.LC0:
	.string	"long long "
.LC1:
	.string	"%-20s %lu bytes\n"
.LC2:
	.string	"char "
.LC3:
	.string	"%-20s %lu byte\n"
.LC4:
	.string	"short "
.LC5:
	.string	"int "
.LC6:
	.string	"float "
.LC7:
	.string	"double "
.LC8:
	.string	"long "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	.LC0(%rip), %rcx
	leaq	.LC1(%rip), %rax
	movl	$8, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC2(%rip), %rcx
	leaq	.LC3(%rip), %rax
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC4(%rip), %rcx
	leaq	.LC1(%rip), %rax
	movl	$2, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC5(%rip), %rcx
	leaq	.LC1(%rip), %rax
	movl	$4, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC6(%rip), %rcx
	leaq	.LC1(%rip), %rax
	movl	$4, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC7(%rip), %rcx
	leaq	.LC1(%rip), %rax
	movl	$8, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC8(%rip), %rcx
	leaq	.LC1(%rip), %rax
	movl	$8, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 16.1.1 20260430"
	.section	.note.GNU-stack,"",@progbits
