#include <sys/types.h> 
#include <errno.h>
#include <stdio.h>      
#include <sys/wait.h>
#include <stdlib.h>     
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE * fp;
	fp = fopen("number.dat","r");
	long int num;
	fscanf(fp, "%li", &num);
	int *array = (long int*)malloc(num*sizeof(long int)); //allocate space for array
	int count=0; //actual number of elements in array
	while(1){					//1 num at a time!
		if(fscanf(fp, "%li", &num)==EOF)
			break;
		array[count]= num;
		count++;
	}
	int fd[2]; 					//File Descriptor with 2 vars
							//fd[0] opened for reading, 
							//fd[1] opened for writing
	pipe(fd); 					//

	pid_t result= fork();				//
	long int sum = 0;
	long int buffer;
	if(result>0){ 					//Parent Process runs this
		for(int i = 0; i<(count/2);i++){	//Do the first half of the work
			sum = sum + array[i];		//hope the other group partner
							//did something
		}	
		read(fd[0], &buffer, sizeof(buffer));	//time of reckoning..did the group partner
							//do something useful? :D	
		//printf("Received %ld\n", buffer);	//Serious note: commented out
							//since example did not have this			
		int status;				
		wait(&status); 				//Hey child, you alright?
	}

	else if  (result == 0) { 			//Child Process runs this
		for(int i=(count/2);i<count;i++){	//The only time when group project partners
							//actually do 50% of the work
			sum = sum + array[i]; 		//getting 'sum'thing
		}	
		write(fd[1], &sum, sizeof(sum));	//pipe back some number~
		exit(0); //exiting right~~
	}
	else{ //ERROR..
		fprintf(stderr, "fork() failed: %s\n", strerror(errno)); //print error msg like a champ
		return 1;//"lol, nope it didnt work."
	}
	double total = ((sum*1.0+buffer*1.0)/count*1.0); //cast everything as a double lazily
	printf("The average is %f\n",total); //prints out an awesome answer of 32715.061050
	return 0; //"it works right....right?"
}
