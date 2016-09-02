#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>


int main(void){
	//initialize timer and vars
	alarm(5);
	int randNum, guess;
	randNum = (rand()%10)+1; // integer cuts dec, so only [0,9], add 1 for [1,10]
	//printf("%d\n",randNum);
	//loop for guessing answer
	printf("Guess a number [1-10]: ");
	while(1){
		scanf("%d", &guess);
		if(guess == randNum){
			printf("You got it!\n");
			break;
		}
		else{
			printf("Guess again: ");
		}
	}
	return(0);
}
