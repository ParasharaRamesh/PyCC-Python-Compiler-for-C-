
//scope #0
int main()
{
	//scope #1
	//single 1
	int i=1;
	do{
		//scope #2
		printf("%d\n",i);
		i++;
	}while(i<=10);

/*
multi 1

*/
	char c;
	scanf("%c",&c);
	switch(c)
	{
	//scope #3
		case 'a':
		//scope #4
			printf("a\n");
			break;
		case 'b':
		//scope #5
			printf("b\n");
			break;
		default:
		//scope #6
			printf("c\n");
			break;
	}
	/* multi 2*/
	printf("Program finished!");
	return 0;
}
//single 2
