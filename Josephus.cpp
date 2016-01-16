#include<stdio.h>
#define N 100
void josephus(int man[],int n,int m);
 main(){
	int i,m,n;
	int man[N]={0};
	printf("总人数和报数间隔：\n");
	scanf("%d%d",&n,&m);
	josephus(man,n,m);
	printf("\n约瑟夫环中每个元素对应的选中位序：\n");
	for(i=0;i<n;i++)
		printf("%4d%c",man[i],((i+1)%15)==0?'\n':' ');
}
void josephus(int man[],int n,int m){
    int i,k,pos;
	for(i=0;i<n;i++)
		man[i]=0;
	i=k=0;
	printf("约瑟夫环中元素出环的顺序:\n");
	for(pos=0;k<n;pos=(pos+1)%n){
		if(man[pos]==0)
			i++;
		if(i==m){
			i=0;
			k++;
			man[pos]=k;
			printf("%4d%c",pos+1,(k%15)==0?'\n':' ');
		}
	}
}