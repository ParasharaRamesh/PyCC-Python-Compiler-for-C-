//this is the input code for our parser

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i=1;
	do{
		printf("%d\n",i);
		i++;
	}while(i<=10)
	
	char c;
	scanf("%c",&c);
	switch(c)
	{
		case 'a':
			printf("a\n");
			break;
		case 'b':
			printf("b\n");
			break;
		default:
			printf("c\n");
			break;
	}
	printf("Program finished!");
	return 0;
}
