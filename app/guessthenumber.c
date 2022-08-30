#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(){
char name[20];
char ans;
int  userinput,attempt,random, i;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
printf("\n\n****THIS IS A SIMPLE GAME TO GUESS A 4 DIGITS NUMBER***\n\n\a");
printf("\n\nTo start the game, please enter your name: \n\n\a");
scanf("%s", &name);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
printf ("\n\nWould you like to continue %s? (Y/N)\n\n\a", name);
scanf("%s",&ans);
srand(time(NULL));
random = (rand()%10000);
//printf("%d",random); To check if the program logic works

if(ans=='Y'){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("\n\nHow many attempts would you like to guess the number?\a\n\n");
	scanf("%d", &attempt);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("\n\nThat's Great! Enter a four(4) digit number to continue:\a\n\n");
	scanf("%d", &userinput);
	
	
	
			
	for(i=1; i <= attempt; i++){
			if(userinput != random && i!=attempt){
				
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
			printf("\n\nOoops!!!!Your guess is incorrect\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
			printf("\n\nPlease Try Again!!!!\a You have %d attempts left\n\n", attempt -i);
			scanf("%d", &userinput);
			
			}
			
			else if (userinput!=random && (i==attempt))	{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
			printf("\n\nOoops!!!!You could not guess the number. Better Luck Next time.\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
			printf("\n\nThe number is %d", random);
			
			exit(0);
			
			}
			else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			printf("\n\nAWESOME!!! YOU GUESSED THE NUMBER IN %d ATTEMPT/S.\n\n", i);
			
			
			exit(0);
			}
	}
			
		
	 	
	}		
else {
	exit(0);
	 }
	
return 0;
}