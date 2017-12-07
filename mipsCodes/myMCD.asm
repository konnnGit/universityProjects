.text

mkd:    add $t0,$t3,$0
	add $t1,$t4,$0 #ta s0,s1 einai ta a,b antistoixa.

l1:	bne $t1,$0,l2
	add $v0,$v0,$t0
	jr $ra
l2:	slt $t2,$t1,$t0
	beq $t2,$0,l3

	sub $t0,$t0,$t1
	j l1

l3:	sub $t1,$t1,$t0
	j l1


main:


addi $t3,$t3,124




addi $t4,$t4,34


jal mkd




