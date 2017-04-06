	.text
	.globl	main
	.type	main, @function
main:
	push	%rbp
	movq	%rsp, %rbp
.BB0:
	jmp .BB1
.BB1:
	movq	$65, %rcx
	movq	%rcx, -32(%rbp)
	movq	-32(%rbp), %rdx
	movq	%rdx, -8(%rbp)
	movq	$22, %rsi
	movq	%rsi, -40(%rbp)
	movq	-40(%rbp), %rdi
	movq	%rdi, -8(%rbp)
	movq	$7, %r8
	movq	%r8, -48(%rbp)
	movq	-48(%rbp), %r9
	movq	%r9, -16(%rbp)
	movq	$2, %rcx
	movq	%rcx, -56(%rbp)
	movq	-56(%rbp), %rdx
	movq	-8(%rbp), %rsi
	movq	%rdx, %rdi
	imulq	%rsi, %rdi
	movq	%rdi, -64(%rbp)
	movq	-64(%rbp), %r8
	movq	-16(%rbp), %r9
	movq	%r8, %rcx
	addq	%r9, %rcx
	movq	%rcx, -72(%rbp)
	movq	-72(%rbp), %rdx
	movq	%rdx, -24(%rbp)
	jmp .BB2
.BB2:
	popq	%rbp
	ret
	.size	main, .-main
