#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct
{
	char dname[10],fname[10][10];
	int cf;
}dir[10];
void main()
{
	int ch,i,cd;
	char f[30],d[30];
	dir.c=0;
	printf("enter directory name: ");
	scanf("%s",dir.dname);
	while(1)
	{
		printf("\nSELECT OPERATION\n");
		printf("1.CREATE DIRECTORY\t2.CREATE FILE\t3.DELETE\t4.SEARCH\t5.DISPLAY\t6.EXIT");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
			printf("enter directory name: ");
			scanf("%s",dir[cd].dname);
			cd++;
			printf("directory created\n");
			break;
			case 2:
			printf("enter directory name: ");
			scanf("%s",d);
			for(i=0;i<cd:i++)
			{
				if(strcmp(d,dir[i].dname)==0)
				{
					printf("enter file name: ");
					scanf("%s",dir[i].fname[dir.cf]);
					dir.cf++;
					printf("file is created\n");
					break;
				}
				if(i==cd)
				{
					printf("directory not found\n");
				}
				break;
			}
			
			






			printf("Enter the name of file: ");
			scanf("%s",dir.fname[dir.c]);
			dir.c++;
			break;
			case 2:
			printf("Enter name of file to delete: ");
			scanf("%s",f);
			for(i=0;i<dir.c;i++)
			{
				if(strcmp(f,dir.fname[i])==0)
	  		{
	  			printf("file is deleted\n");
	  			strcpy(dir.fname[i],dir.fname[dir.c-1]);
	  			strcpy(dir.fname[dir.c-1],"");
	  			break;
	  		}
			}
			if(i==dir.c)
				{
					printf("file not found\n");
				  break;
			  }
			break;
			case 3:
			printf("Enter file name to be searched: ");
			scanf("%s",f);
			for(i=0;i<dir.c;i++)
			{
				if(strcmp(f,dir.fname[i])==0)
				{
					printf("file %s is found\n",f);
					break;
				}
			} 
			if(i==dir.c)
				{
					printf("file not found\n");
					break;
			  }
			break;
			case 4:
			if(dir.c==0)
			{ 
				printf("the file is empty\n");
				break;
			}
			else
			{
				printf("the files are : ");
				for(i=0;i<dir.c;i++)
				{
					printf("%s",dir.fname[i]);
				}
				printf("\n");
			}
			break;
			case 5:
			exit(0);
		}
	}
	
}
