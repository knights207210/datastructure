#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
#define a 46
void diagscan(int mat[][N],int m,int n,int i,int j,int &maxlen,int &jpos){
	int eq=0,len=0,sj;
	while(i<m&&j<n){
		if(mat[i][j]==1){
			len++;
			if(!eq){
				eq=1;sj=j;
			}
		}else if(eq){
			if(len>maxlen){
				maxlen=len;jpos=sj;
			}
			eq=0;len=0;
		}
		i++;j++;
	}
	if(len>maxlen){
		maxlen=len;jpos=sj;
	}
}
void diagmax(int mat[][N],int m,int n,int &maxlen,int &jpos){
	int istart,k,i,j;
	maxlen=0;jpos=-1;
	istart=0;
	for(k=-(n-1);k<=m-1;k++){
		i=istart;j=i-k;
		diagscan(mat,m,n,i,j,maxlen,jpos);
		istart+=(k>=0)?1:0;
	}
}
void getmaxsamestr(char *string1,char *string2,char *&sub){
    char *p1,*p2;
	int m,n,i,j,mat[N][N],maxlen,jpos;
	p1=string1;
	m=strlen(string1);
	p2=string2;
	n=strlen(string2);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			mat[i][j]=(string1[i]==string2[j])?1:0;
		diagmax(mat,m,n,maxlen,jpos);
		if(maxlen==0)
			sub[0]='\0';
		else strncpy(sub,&string2[jpos],maxlen);
		sub[maxlen]='\0';
}
bool strdelete(char *&string,int pos,int len){
	if((pos<0)||(pos>strlen(string)))
		return false;
	int i;
	for(i=pos+len;i<strlen(string);i++)
		string[i-len]=string[i];
		string[i-len]='\0';
		return true;
}
int index(char *S,char *T,int pos){
	int slen,tlen,i,j;
	slen=strlen(S);
	tlen=strlen(T);
	i=pos;
	j=0;
	while(i<slen-tlen&&j<tlen){
		if(S[i]==T[j]){
			i++;
			j++;
		}
		else{
			i=i-j+1;
			j=0;}
	}
	if(j==tlen)
		return -1;
	else
		return (i-j);
}
void similarity(char *string1,char *string2,int s1,int s2,double &psimilarity){
		char *sub=(char *)malloc(N);
		char same[N]={0};
	int k1,k2,m1,n1,m2,n2,i=0,j=0;
	double similarity; 
    m1=strlen(string1);
	n1=strlen(string2);
	do{
	getmaxsamestr(string1,string2,sub);
	strcat(same,sub);
	k1=index(string1,sub,0);
	k2=index(string2,sub,0);
    strdelete(string1,k1,strlen(sub));
	strdelete(string2,k2,strlen(sub));
	}while(sub[0]!='\0');
	m2=strlen(string1);
	n2=strlen(string2);
	similarity=1-(double)(m2+n2)/(double)(m1+n1);
	psimilarity=similarity*(m1+n1);
}
int isalpha(char t){
	return( (t>='a'&&t<='z') || (t>='A'&&t<='Z')||(t==' ')||(t==','));
}
void read(char *string,char words[N][N],int &count){
   char tmp[2]={0,0};   
   int i,length,totalNumber;
   int prvIsAlpha;   
   int countt=0;
   while(1)   {           
	   if(string[0]=='\0') break;           
	   totalNumber=0;     
	   length=strlen(string);          
	   prvIsAlpha=0;
	   for(i=0;i<length;++i) {  
		 	
		   if(isalpha(string[i]))      { 
			   tmp[0]=string[i];        
			   if(prvIsAlpha) strcat(words[totalNumber-1],tmp);	           
			   else words[totalNumber++][0]=string[i];        prvIsAlpha=1;      }      
		   else {prvIsAlpha=0;countt++;}	}
		   break;
   }
     count=countt-1;
}
void paragraphs(char *para1,char *para2,double &p){
	double psimilarity[N]={0};
	char paras1[N][N]={0},paras2[N][N]={0};
	int count1,count2,s1,s2,i;
	p=0;
	read(para1,paras1,count1);
	read(para2,paras2,count2);
	for(s1=1 ;s1<count1-1;s1++)
		for(s2=1;s2<count2-1;s2++){
			similarity(paras1[s1],paras2[s2],s1,s2,psimilarity[s1*(count1-1)+count2-1]);
		}
		for(i=0;i<s1*(count1-1)+count2-1;i++)
			p+=psimilarity[i];
}
main(){
	int len1,len2;
	double p;
		printf("请输入两段话:\n");
	char *para1 = (char *)malloc(N);
	fgets(para1,N,stdin);
	len1=strlen(para1);
	char *para2 = (char *)malloc(N);
	fgets(para2,N,stdin);
	len2=strlen(para2);
	paragraphs(para1,para2,p);
	printf("两段话相似度为p=%6.2lf%%\n",2.0*p/(len1+len2)*100);
	
}


