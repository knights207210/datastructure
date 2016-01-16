#include"stdio.h"
#include"string.h"
#define N(a,b) 2.0*a/b*100
FILE *pa,*pb;
int t,m;
char a[100],b[100];
/*创建文件1*/
void Creat1_Z(){   
	if((pa=fopen("d:\\file1.txt","w+"))==NULL)     
		printf("\tCannot open this file!\n");  else    
	{ printf("\tEnter a string to File1:\n");getchar();      
	gets(a);       
	fputs(a,pa);    
	printf("\tSuccess!\n");   }  
	fclose(pa);}
/*创建文件2*/
void Creat2_Z(){  
	if((pb=fopen("d:\\file2.txt","w+"))==NULL)     
		printf("\tCannot open this file!\n");  
	else    { 
		printf("\tEnter a string to File2:\n");
	getchar(); gets(b);      
	fputs(b,pb);    
	printf("\tSuccess!\n");   }  
	fclose(pb);}
/*相似性比较*/
void contrast( ){  
	char str1[15],str2[15];  
	int i=0,j=0,t=0,s,k=1,f=1;  
	while(k==1)  {    
		for(s=0;(a[i]!=32)&&(a[i]!=0)==1;s++,i++)    
			str1[s]=a[i];    
		str1[s]='\0';    
		if(str1=="") continue;    
		f=1;    
		j=0;    
		while(f==1)      {      
			for(s=0;(b[j]!=32)&&(b[j]!=0)==1;j++,s++)        
				str2[s]=b[j];      
			str2[s]='\0';      
			if(str2=="") continue;      
			if(strcmp(str1,str2)==0)        {          
				t++;          
				f=0;          
				continue;        }      
			j++;      
			if(b[j]==0) f=0;      }
		i++;    
		if(a[i]==0) k=0;  }  
	printf("相同单词数:%d\n",t);  
	for(i=0,j=0,s=0;a[i]!=0;i++)    
		if(a[i]==32) s=0;    
		else if(s==0) {s=1;j++;}  
		for(i=0,s=0;b[i]!=0;i++)    
			if(b[i]==32) s=0;    
			else if(s==0) {s=1;j++;}  
			printf("相似度:%5.2f%%\n",N(t,j));  
			if(N(t,j)>=80) printf("相同!\n");  
			else printf("不同!\n");}
void main(){    
	contrast();  
 }
  