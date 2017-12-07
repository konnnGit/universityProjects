.text
fib:

addi $s0,$0,0#s0,s1 have the first 2 values of the fibonacci order
addi $s1,$0,1
beq $t0,$0,fib1# if n=0 or n=1 go to fib1 or fib2 where s3 has the F(n).In the whole code F(n) goes to s3.If n>1 the programme goes to fib3.
beq $t0,$s1,fib2

fib3:
addi $t4,$0,1#t4 is a counter of n.
fib31:
add $s3,$s0,$s1#in this part of the code i renew the values of s1,s0 and the sesult goes to s3 until t4 reach n.then programme goes to ra. 
add $s0,$s1,$0
add $s1,$s3,$0
addi $t4,$t4,1
bne $t4,$t0,fib31
j exit1
j exit
fib2:
add $s3,$s0,$s1
j exit
fib1:
add $s3,$s0,$0
j exit
exit:
jr $ra
exit1:
j $ra

main:
addi $t0,$0,1#t0 orisma(n)
jal fib
