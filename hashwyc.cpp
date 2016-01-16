#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sum=0;
int list[113]={0};
struct node{
	char name[20];
	char stu_num[20];
	int num;
	node* next;
};
node* a[113];
int hash(char x[]);                                                    //哈希函数 
void Insertlist(char s1[],char s2[],int num);                          //将每一条记录存入哈希表中 ，用拉链法解决冲突 
int search(char s1[],char s2[]);                                       //查找名字对应的信息 

main(){
	system( "color F1 "); 
	char s1[100],s2[100];
	int n=0,i=0;
	FILE *fp;
	for(i=0;i<113;i++)a[i]=0;
	fp=fopen("text.txt","r");
	while(fscanf(fp,"%s%s",s1,s2)!=EOF){
		Insertlist(s1,s2,n);
		n++;		
	}
	fclose(fp);
	printf("冲突率为：%f\n",float(sum-n)/float(n));
	printf("请输入要查找的人名,#表示结束查找：");
	scanf("%s",s1);
	while(strcmp(s1,"#")!=0){
	strcpy(s2,"名单里没有这个人，请重新输入！！！");
	printf("%d\n%s\n%s\n",search(s1,s2),s1,s2);
	printf("请输入要查找的人名，#表示结束查找：");
	scanf("%s",s1);
    }
}


void convert(int n,int s[]) {
   int j=0;
   while((n/10)!=0){
	   s[j]=n%10;
	   j++;
	   n=n/10;
   }
   s[j]=n;
}
int hash(char x[20]){
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

void Insertlist(char s1[],char s2[],int num){                           //将每一条记录存入哈希表中 ，用拉链法解决冲突 
	int h;
	node* p;
	h=hash(s1);	
	list[h]++;
	sum+=list[h];
	p=(node*)malloc(sizeof(node));
	strcpy(p->name,s1);
	strcpy(p->stu_num,s2);
	p->num=num;
	p->next=a[h];
	a[h]=p;	
}

int search(char s1[],char s2[]){                          //查找名字对应的信息 
	int t;
	t=hash(s1);
	node* p;
	for(p=a[t];p!=0;p=p->next){		
		if(!strcmp(p->name,s1)){
			strcpy(s2,p->stu_num);
			return p->num;
		}
	}
	return -1;
}
