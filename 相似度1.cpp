#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
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
void similarity(char *string1,char *string2){
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
	printf("相似的部分为:%s\n",same);
	m2=strlen(string1);
	n2=strlen(string2);
	similarity=1-(double)(m2+n2)/(double)(m1+n1);
	printf("两个句子的相似度为:%6.2lf%%\n",similarity*100);
}
main(){
		printf("请输入两个句子:\n");
	char *string1 = (char *)malloc(N);
	fgets(string1,N,stdin);
	char *string2 = (char *)malloc(N);
	fgets(string2,N,stdin); 
    similarity(string1,string2);
}




