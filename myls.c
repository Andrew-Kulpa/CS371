#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(void){
	FILE *ls_fp;
	char line[BUFSIZ];
	ls_fp = popen("ls -l","r");
	FILE *sort_fp = popen("sort -n -k5","w");
	if(ls_fp==NULL)
		return -1;
	while(1){
		if(fgets(line,BUFSIZ,ls_fp)!=NULL)
			fprintf(sort_fp,"%s",line);
		else
			break;
	}
	pclose(ls_fp);
	pclose(sort_fp);
	return(0);
}
