#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[])
{

        if(argc!=2){
                return -1;
        }

        int c;
        char *filename = argv[1];
        FILE *input = fopen(filename,"r");
        if(input==NULL){
                printf("Cannot open %s: %s\n", filename, strerror(errno));
                return 1;

        }
        while(1){
                c = fgetc(input);
                if(c == EOF)
                        break;
		if(c>96 && c<123){
                	c-=32;
		}
                putchar(c);
        }

        return 0;
}

