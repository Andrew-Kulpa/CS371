#include<stdio.h>
#include<string.h>
main(){
	int a = 0;
	int b = 1;
	printf("%d %d",a,b);
	for(int i = 0; i<8;i++){
		b = a + b;
		a = b - a;
		printf(" %d",b);
	}
}
