#include<stdio.h>
#define N 100
void josephus(int man[],int n,int m);
 main(){
	int i,m,n;
	int man[N]={0};
	printf("�������ͱ��������\n");
	scanf("%d%d",&n,&m);
	josephus(man,n,m);
	printf("\nԼɪ����ÿ��Ԫ�ض�Ӧ��ѡ��λ��\n");
	for(i=0;i<n;i++)
		printf("%4d%c",man[i],((i+1)%15)==0?'\n':' ');
}
void josephus(int man[],int n,int m){
    int i,k,pos;
	for(i=0;i<n;i++)
		man[i]=0;
	i=k=0;
	printf("Լɪ����Ԫ�س�����˳��:\n");
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