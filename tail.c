#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[])
{

        if(argc!=2){
                return -1;
        }

        char *filename = argv[1];
        FILE *input = fopen(filename,"r");
        if(input==NULL){
                printf("Cannot open %s: %s\n", filename, strerror(errno));
                return 1;

        }

	char line[10][BUFSIZ];
	int count=0;
	char c = "\0";//set char to a null character
        while(1){
		fgets(line[count],BUFSIZ,input);//get the line from file pointer->\n
		if(fgetc(input)==EOF){//Is it the end of the file?
			count+=1; 
			for(int i=count;i<10;i++){//position in array + 1 -> end of array
				printf("%s",line[i]);
			}
			for(int j=0;j<count;j++){//start of array->position of array
				printf("%s",line[j]);
			}
        		break;        
		}
		fseek(input,-1, SEEK_CUR);//fgetc increments FP or input, so decrement 1
		count+=1;
		if(count>9)//reached the end of array? Lets go again! :D
			count=0;//use the array as a "ring" structure
        }

        return 0;
}
