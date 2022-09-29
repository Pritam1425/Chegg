.text
main:
    li $t0,0#loop iterator
    li $t1,7
    li $t8,0 #t8 will store the sum of products
label:
    mul $t2,$t0,4
    lw $t3,A_vec($t2)#Now load the value stored at A_vec+$t2
    
    lw $t4,B_vec($t2)#Now load the value stored at B_vec+$t2
    
    mul $t5,$t3,$t4 #mul -> $t8 = $t3 * $t4
    
    add $t8,$t8,$t5#add the product in $t8

    addi $t0,$t0,1#increment the iterator

    beq $t0,$t1,exit# branch to exit if $t0 = 7,i.e size of the vector

    j label#jump to label for loop
exit:
    sw $t8,DOTPROD($zero) #here we store the value of dot product in DOTPROD memory location
    
    move $a0,$t8#printing the dotproduct
    li $v0,1#For printing integers
    syscall
    
    li $v0,10#exit
    syscall
.data 
A_vec: .word 2 4 20 13 3 10 5 #A vector
B_vec: .word 4 2 1 2 5 2 4 #B vector
DOTPROD: .word 0#Memory location to store the dot product