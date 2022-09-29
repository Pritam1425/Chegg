
         .data     
D:	.word 1,2,3,4,5
a:	.word 5
b:	.word 2
i:	.word 0
j:	.word 0
         .text
         .globl main
main:
	lw $s0,a#load a
	lw $s1,b#load b
	lw $t0,i#load i
	lw $t1,j#load j
	la $s2,D#load base address of D
loop1:	#outerloop
	beq $t0,$s0,exit#if i==a, exit
	li $t1,0	#j=0

loop2:#innerloop
	
	sll $t2,$t1,4#j*16 j*4*size of int, D+(4*j)*4 is the address to be stored
	sll $t3,$t1,2#j*4
	add $t4,$s2,$t2#D+(4*j)*4 calculates the effective address
	add $t5,$t0,$t3#i+4*j the value to be stored
	sw $t5,0($t4)#D[4*j] = i+4*j
	addi $t1,$t1,1#j++
	beq $t1,$s1,loopincr#if j==b, go to loop increment
	j loop2#innnerloop again
loopincr:
	addi $t0,$t0,1#i++
	j loop1#jump to outerloop
exit:#exit
	li $v0,10
	syscall