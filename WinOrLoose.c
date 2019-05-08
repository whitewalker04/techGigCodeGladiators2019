#include<stdio.h>
#include<stdlib.h>


void swap(float *xp, float *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 

} 

void sort(float *arr, int n)
{
	 int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
}



int main()
{
	int testCases;
	int number;
	float *villian, *player;
	char *st;
	int status=0;
	scanf("%d", &testCases);
	st=(char *)malloc(sizeof(char)*testCases);
	if(testCases>=0 && testCases<=10)
	{
		for(int t=0; t<testCases;t++)
		{
			scanf("%d", &number);
			villian=(float *)malloc(sizeof(float) * number);
			player =(float *)malloc(sizeof(float) * number);
			for(int i=0;i<number;i++)
			{
				scanf("%f", &villian[i]);
			}
			for(int i=0;i<number;i++)
			{
				scanf("%f", &player[i]);
			}
			sort(villian, number);
			sort(player, number);

			for(int i=0;i<number;i++)
			{
				if(villian[i]>player[i])
				{
					status=-1;
					break;
				}
			}
			if(status!=-1)
				st[t]='W';
			else
			{
				st[t]='L';
				status=0;
			}
			free(villian);
			free(player);
		}
		for(int i=0;i<testCases;i++)
		{
			if(st[i]=='W')
				printf("WIN\n");
			else
				printf("LOSE\n");
			
		}
		
	}
	free(st);
	return 0;
}