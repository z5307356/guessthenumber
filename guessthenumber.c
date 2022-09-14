#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <winsock2.h>
#include <conio.h>
#include <string.h>

int func(char *str)
{
	char buffer[25];
	strcpy(buffer,str);
	printf ("\n\nWould you like to continue %s?(Y/N)\n\n\a",buffer);
	return 0;
	
}

int main(){
char name[2048]={0};    //variable to read players name 
FILE *fp; //pointer to the file
char ans;			//variable for Y/N question
int  userinput,attempt,random, i; //userinput ->number guessed by the user attempt - intended number of tries random- variable to store random number i- iteration
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY); //changes the colour of the font
printf("\n\n****THIS IS A SIMPLE GAME TO GUESS A 4 DIGITS NUMBER***\n\n\a");
//Guess1(); //function call from dll
printf("\n\n\tATTENTION!!!ATTENTION!!!ATTENTION!!!!\n\nUPDATE NAME IN THE FILE (password.txt) BEFORE YOU BEGIN\n\n\a");
fp = fopen(".\\passcode.txt","rb");    // read mode rb
fread(name,sizeof(char),2048,fp);
fclose(fp);

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
func(name);
scanf("%s",&ans);
srand(time(NULL));   //embedded function to generate random number 
random = (rand()%10000); //generate 4 digit number and assign to random variable 
//printf("%d",random); To check if the program logic works

if(ans=='Y'){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("\n\nHow many attempts would you like to guess the number?\a\n\n");
	scanf("%d", &attempt);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("\n\nThat's Great! Enter a four(4) digit number to continue:\a\n\n");
	scanf("%d", &userinput);
			
	for(i=1; i <= attempt; i++){
			if(userinput != random && i!=attempt){  //check to see if the number is incorrect and continue will remaining attempts
				
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
			printf("\n\nOoops!!!!Your guess is incorrect\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
			printf("\n\nPlease Try Again!!!!\a You have %d attempts left\n\n", attempt -i);
			scanf("%d", &userinput);
			
			}
			
			else if (userinput!=random && (i==attempt))	{   //if the player cannot guess the number after full attempt displays the random number
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
			printf("\n\nOoops!!!!You could not guess the number. Better Luck Next time.\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
			printf("\n\nThe number is %d", random);
			Guess1();
			exit(0);
			
			}
			else {  //if user guesses the correct numbter below message is displayed
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			printf("\n\nAWESOME!!! YOU GUESSED THE NUMBER IN %d ATTEMPT/S.\n\n", i);
			Guess1();
			
			exit(0);
			}
	}
			
		
	 	
	}		
else {
	exit(0);
	 }
	
return 0;
}