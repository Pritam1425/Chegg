.text
main: 
li $t0,0
li $t8,0
lw $t7,data3($zero)
label:
mul $t1,$t0,4
lw $t2,data1($t1)
lw $t3,data2($t1)
mul $t4,$t2,$t3
add $t8,$t8,$t4
addi $t0,$t0,1
beq $t0,$t7,exit
j label
exit:

sw $t8,data4($zero)
move $a0,$t8
li $v0,1
syscall
li $v0,10
syscall
.data
data1: .word 7 8 9 10
data2: .word 29 1 2 3
data3: .word 4
data4: .word 0