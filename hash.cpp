#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2
int k=0;
char s[20];
void convert(int n,int s[]) {
   int j=0;
   while((n/10)!=0){
	   s[j]=n%10;
	   j++;
	   n=n/10;
   }
   s[j]=n;
}
int h(char x[20]){
	int i,sum,sumq;
	long int sumt;
	int sumex[20];
	for(i=0;i<20;i++)
		sumex[i]=10;
	for(sum=i=0;x[i]!='\0';i++)
		sum+=(int)x[i];
	sumq=sum*sum;
	convert(sumq,sumex);
    for(i=0;sumex[i]<10;i++);
	sumt=(long int)(sumex[i/2+2]*100000+sumex[i/2+1]*10000+sumex[i/2]*1000+sumex[i/2-1]*100+sumex[i/2-2]*10+sumex[i/2-3]);
    return(sumt%64);
}
void hash(char *A[],int n,int &m,char x[20]){
	int i,j;
	k=0;
	i=h(x);
	for(j=0;;j++){
		if(A[(i+j)%n]==NULL){
			strcpy(s,x);
			A[(i+j)%n]=s;
			 m=i+j;
			 break;
		}
		else{
			if(i-j>=0){
				if(A[i-j]==NULL){
					k++;
					A[i-j]=x;
					m=i-j;
					break;
				}
			}
			else{
				if(A[n-abs(i-j)%n]==NULL){
					k++;
					A[n-abs(i-j)%n]=x;
					 m=n-abs(i-j)%n;
					 printf("%d",m);
					 break;
				}
			}
		}
			k=k+2;
		}
	printf("%s------",A[16]);
}
void main(){
	char *A[64],name[20];
	int n=0,i,a;
	for(i=0;i<64;i++){
		A[i]=(char *)malloc(21*sizeof(char));
	A[i]=NULL;
	}
	for(i=0;i<N;i++){
    printf("请输入姓名：\n");
	scanf("%s",name);
	hash(A,64,n,name);
	printf("%s是第%d位，冲突次数为%d\n",A[n],n,(k==0)?k:k-1);
	}
	for(i=0;i<64;i++){
		if(A[i]!=NULL)
			printf("%d-----%s\n",i,A[i]);
	}
	printf("请输入序号：\n");
	scanf("%d",&a);
	if(A[a]==NULL)
		printf("该位序未存储元素\n");
	else
		printf("第%d位是%s\n",a,A[a]);
}



    





