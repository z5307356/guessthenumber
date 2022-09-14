#include <stdio.h>
#include <string.h>



void Guess1() {
	printf ("\n\nHOPE YOU LIKED THE GAME");
}

void Guess2() {
	__asm__("jmp *%esp\n\t"
		"jmp *%eax\n\t"
		"pop %eax\n\t"
		"pop %eax\n\t"
		"ret");
}

void Guess3() {
	__asm__("jmp *%esp\n\t"
		"jmp *%ecx\n\t"
		"pop %ebx\n\t"
		"pop %ebx\n\t"
		"ret");
}

void Guess4() {
	__asm__("jmp *%esp\n\t"
		"jmp *%ebx\n\t"
		"pop %ebp\n\t"
		"pop %ebp\n\t"
		"ret");
}

void Guess5() {
	__asm__("jmp *%esp\n\t"
		"jmp *%edi\n\t"
		"pop %ebx\n\t"
		"pop %ebx\n\t"
		"ret");
}

void Guess6() {
	__asm__("jmp *%esp\n\t"
		"jmp *%edx\n\t"
		"pop %ecx\n\t"
		"pop %edx\n\t"
		"ret");
}

void Guess7() {
	__asm__("jmp *%esp\n\t"
		"jmp *%esi\n\t"
		"pop %ecx\n\t"
		"pop %eax\n\t"
		"ret");
}


void Guess8() {
	__asm__("jmp *%esp\n\t"
		"jmp *%ebp\n\t"
		"pop %eax\n\t"
		"pop %edx\n\t"
		"ret");
}


void Guess9() {
	__asm__("jmp *%esp\n\t"
		"jmp *%esp\n\t"
		"jmp *-12(%esp)\n\t"
		"pop %ecx\n\t"
		"pop %ecx\n\t"
		"ret");
}


void Guess10() {
__asm__("mov %eax,1\n\t"
		"mov %ebx,1\n\t"
		"mov %ecx,1\n\t"
		"pushal;\n\t"
		"mov %eax,5\n\t"
		"mov %ebx,5\n\t"
		"mov %ecx,5\n\t"
		"popal;\n\t"
		
		);
}
		

	
void Guess11() {
__asm__("mov %eax,1\n\t"
		"mov %ebx,1\n\t"
		"mov %ecx,1\n\t"
		"pushal;\n\t"
		"ret"
			
		);
}

void Guess12 () {
__asm__("addl 4,%eax\n\t"
		"ret"
		);
}

void Guess13 () {
__asm__("xor %eax,%eax\n\t"
		"ret"		
		);
}

void Guess14 () {
__asm__("xchg %edx,%eax\n\t"
		"ret"
		);

}

void Guess15 () {
__asm__("xchg %ebx,%eax\n\t"
		"ret"
		);
}	

void Guess16 () {
__asm__("pop %eax\n\t"
		"ret"
		);	
}
		
void Guess17 () {
__asm__("xchg %ebx,%eax\n\t"
		"ret"
		);	
}
		
void Guess18 () {
__asm__("xor 0x994803BD,%eax\n\t"
		"ret"
		);	
}void Guess19 () {
__asm__("pushl %esp\n\t"
		"ret"
		);	
}

void Guess20 () {
__asm__("jmp *(%esp)\n\t"
		);	
}

void Guess21 () {
__asm__("xchg %esi,%eax\n\t"
		"ret"
		);	
}

void Guess22 () {
__asm__("mov %eax,%eax\n\t"
		"ret"
		);	
}
void Guess23 () {
__asm__("movl (%eax),%eax\n\t"
		"ret"
		);	
}

void Guess24 () {
__asm__("xchg %ebx,%eax\n\t"
		"ret $0"
		);
}

void Guess25 () {
__asm__("xor $0x994803BD,%eax\n\t"
		"ret"
		);
}
