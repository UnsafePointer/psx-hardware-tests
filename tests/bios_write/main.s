.set mips1
.set noreorder

.text

.global main
.type main, function

/* Test writes to the BIOS region (word, halfword and byte)
 *
 * Output on the real console:
 *    0xbfc00000 = 0x3c080013
 *    0xbfc00000 = 0x3c080013
 *
 * The actual value can change depending on the BIOS version, what
 * matters in that it remains the same (meaning that the BIOS is
 * read-only) and no exception is generated by any store.
 *
 * Returns 0 if the value doesn't change, 1 otherwise.
 */

.equ BIOS_BASE, 0xbfc00000

main:
	addiu $sp, -32
	sw    $ra, 28($sp)
	sw    $fp, 24($sp)
	sw    $s1, 20($sp)
	sw    $s0, 16($sp)
	move  $fp, $sp

	/* Dump the value of the first word in the BIOS */
	li    $s0, BIOS_BASE
	lw    $s1, 0($s0)
	la    $a0, display_msg
	move  $a1, $s0
	jal   bios_printf
	move  $a2, $s1

	/* Attempt to overwrite it */
	li    $t0, 0xdeadbeef
	sw    $t0, 0($s0)
	nop
	sh    $t0, 2($s0)
	nop
	sb    $t0, 3($s0)
	nop

	/* Then dump it again */
	move  $a1, $s0
	lw    $s0, 0($s0)
	la    $a0, display_msg
	jal   bios_printf
	move  $a2, $s0

	/* Comapare first($s1) and 2nd($s0) fetched values and set the
	 * return value */
	xor  $t0, $s0, $s1
	sltu $v0, $zero, $t0

	move  $sp, $fp
	lw    $ra, 28($sp)
	lw    $fp, 24($sp)
	lw    $s1, 20($sp)
	lw    $s0, 16($sp)
	jr    $ra
	addiu $sp, 32

.data

display_msg:
.string "0x%08x = 0x%08x\n"
