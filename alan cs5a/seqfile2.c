
#include<stdio.h>

void main()
{
int f[50],i,st,len,j,c,k,count=0;
for(i=0;i<50;i++)
f[i]=0;
printf("File allocated are: \n");
x: count=0;
printf("Enter starting block and length:");
scanf("%d%d",&st,&len);
printf("frames allocated: \n");
for(k=st;k<(st+len);k++)
if(f[k]==0)
count++;
if(len==count){
for(j=st;j<(st+len);j++)
if(f[j]==0)
{
f[j]=1;
printf("%d\t%d\n",j,f[j]);
}
if(j!=(st+len-1))
printf("File is allocated\n");
}

else
printf("File is not allocated");

printf("Do you want to allocate more?(Yes-1 no-0)");
scanf("%d",&c);
if(c==1)
goto x;
else
return;






}


