#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	if(argc!=2){
		return -1;
	}
	
        char *path = argv[1];
        DIR *dir = opendir(path);
        if(dir==NULL){
                printf("Cannot open dir %s: %s\n", path, strerror(errno));
                return -1;
         }
      	 struct dirent *entry;
	 struct stat statbuf;
	 int count = 0;
	 chdir(path);
      	 while((entry=readdir(dir))!=NULL){
              	char *filename = entry->d_name;
		if(count<2){
			count++;
			continue;
                }
         	stat(filename,&statbuf);
		printf("%s\t%ld\t%ld\t%s", filename, statbuf.st_nlink,statbuf.st_size,ctime(&(statbuf.st_mtime)));        
	 }
        return 0;
}

