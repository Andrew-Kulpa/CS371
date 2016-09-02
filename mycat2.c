#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[])
{

        if(argc<2){
                return -1;
        }
      
        int c;
	for(int i=1;i<argc;i++){
        	char *filename = argv[i];
		printf("%s contents:\n",argv[i]);
        	FILE *input = fopen(filename,"r");
        	if(input==NULL){
                	printf("Cannot open %s: %s\n", filename, strerror(errno));
                	return 1;

        	}
        	while(1){
                	c = fgetc(input);
                	if(c == EOF)
                        	break; 
                	putchar(c);
        	}
		printf("\n");
		fclose(input);
	}
        return 0;
}

