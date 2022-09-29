# Compute the sum and integer average
# for an array of integer values using memory variables.
# -----------------------------------------------------
# Data Declarations

.data

array:    .word 1, 3, 5, 7, 9, 11, 13, 15, 17, 19
   .word 21, 23, 25, 27, 29, 31, 33, 35, 37, 39
   .word 41, 43, 45, 47, 49, 51, 53, 55, 57, 59
length: .word 30
sum:    .word 0
average: .word 0
name: .asciiz "Your Name"	#Here you declare name as your name
newLine: .asciiz "\n"
space:.asciiz " "

# ------------------------------------------
# text/code section
# Basic approach:
   # loop through the array
       # accessing each value
       # update sum
   # calculate the average

.text
.globl main

main:

# ----------------------------------------
#Loop through the array to calculate sum

   la $t0, array            # array starting address
   li $t1, 0            # loop index, i=0
   lw $t2, length            # length
   li $t3, 0            # initialize sum=0
sumLoop:
   lw $t4, ($t0)            # get array[i]
   add $t3, $t3, $t4        # sum = sum + array[i]
   add $t1, $t1, 1        # i = i+1
   add $t0, $t0, 4        # update array address
   blt $t1, $t2, sumLoop        # if i<length, continue
   sw $t3, sum            # save sum
   # -------------------------------

#Calculate average
# note, sum and length set in section above.

   div $t5, $t3, $t2        # ave = sum / length
   sw $t5, average

# --------------------------------------
# Done, terminate program.
   
   li $v0,4		#For printing string we need service number 4 to load in $v0
   la $a0,name		#For printing string we need to load the address of the string in $a0.
   syscall		#Now call syscall
   
   li $v0,4
   la $a0,space		
   syscall
   
   
   li $v0, 1		#For printing integer we need service number 1 to load in $v0
   lw $a0, sum		#For printing integer we need to load the word in $a0.
   syscall
   
   li $v0,4
   la $a0,newLine
   syscall
   
   li $v0,4
   la $a0,name
   syscall
   
   li $v0,4
   la $a0,space
   syscall
   
   li $v0, 1
   lw $a0, average
   syscall
   
   li $v0, 10
   syscall        # all done!
.end main