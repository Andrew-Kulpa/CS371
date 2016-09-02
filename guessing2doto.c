#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

void timeout(){
	printf("\nYou ran out of time!\n");
	exit(0);	
}


int main(void){
	//initialize timer and vars
	alarm(5);
	signal(SIGALRM,timeout);//if times up, run timeout()
	int randNum, guess,seed;
	srand(time(NULL));
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
