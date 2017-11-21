.section .init
	/*gcc puts the contents of crtend.o's .init section here :3*/
	popl %ebp
	ret

.section .fini
	/*gcc puts the contents of crtend.o's .fini section here :3*/
	popl %ebp
	ret
