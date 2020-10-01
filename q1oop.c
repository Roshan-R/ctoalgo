#include <stdio.h>
	void main()
	{
		int i,flag=0,N;
		printf("Enter the natural number N: \n");
		scanf("%d",&N);
		for(i=2;i< N;i++){
			if(N%i == 0){
				flag =1;
				break;
			}
		}
		if(flag== 0)
			printf(" %d is a prime number",N);
		else
			printf(" %d is not a prime number",N);
	}
