#include<stdio.h>
#include<string.h>
#define MAX 100
char src1[100],src2[100];
char *s1[50],*s2[50];
int longest;int n1,n2;char *same[50];int m=0;
int c[MAX][MAX];int b[MAX][MAX];

int wordnum(char src[]){
	int i;int count=0;
	for(i=0;src[i]!='\0';i++){
		if(src[i]==' '||src[i]==',')count++;
	}
	count++;
	return count;
}

void convert(char src[100],char *s[50],int &n){
		char *p,*q;int i,j;n=0;
		p=src;
		while(*p!='\0'){
			if(*p==' '||*p==','){
				p++;
				continue;
			}
			else{
				i=0;
				while(*(p+i)!=' '&&*(p+i)!='\0'&&*(p+i)!=',')i++;
				q=new char[i+1];
				for(j=0;j<i;j++)
					q[j]=p[j];
				q[i]='\0';
				s[n++]=q;
				p+=i;
			}
		}
}

void lcs(char *s1[],char *s2[],int c[][MAX],int b[][MAX]){
	int i,j,x,y;int k=0;         
	for(i=0;i<=n1;i++)c[i][0]=0;
	for(j=1;j<=n2;j++)c[0][j]=0;   
	for(i=1;i<=n1;i++){ 
	   for(j=1;j<=n2;j++){
	       if(strcmp(s1[i-1],s2[j-1])==0){
		       c[i][j]=c[i-1][j-1]+1;
			   b[i][j]=0;}
		   else if(c[i-1][j]>=c[i][j-1]){
		       c[i][j]=c[i-1][j]; 
			   b[i][j]=1;}
		   else{
		       c[i][j]=c[i][j-1];
			   b[i][j]=-1;}
	   }
	} 
}
void printlcs(int b[][MAX],char *s1[],int i,int j){
	if(i==0||j==0)return;
	if(b[i][j]==0){
		printlcs(b,s1,i-1,j-1);
		printf("%s ",s1[i-1]);m++;
	}
	else if(b[i][j]==1)printlcs(b,s1,i-1,j);
	else
	     printlcs(b,s1,i,j-1);
	
}
    
main(){
	int i;int sum;float percentage;
	printf("Please input a sentence:\n");
	gets(src1);
	printf("Please input another sentence:\n");
	gets(src2);
	convert(src1,s1,n1);
	convert(src2,s2,n2);
	lcs(s1,s2,c,b);
	printf("\n");
	printf("The mutual word(s) is(are):");
	printlcs(b,s1,n1,n2);
	printf("\n");
	percentage=((float)m/wordnum(src1)+(float)m/wordnum(src2))/2;
	printf("The similarity is %f.",percentage);
}

