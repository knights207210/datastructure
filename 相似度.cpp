#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isalpha(char t){
	return( (t>='a'&&t<='z') || (t>='A'&&t<='Z') );
}
int m0,n0;
void read(char *string,char words[100][20],int &count){
   char tmp[2]={0,0};   
   int i,length,totalNumber;
   int prvIsAlpha;   
   count=0;
   while(1)   {           
	   if(string[0]=='\0') break;           
	   totalNumber=0;     
	   length=strlen(string);          
	   prvIsAlpha=0;      
	   for(i=0;i<length;++i)      
		   if(isalpha(string[i]))      {         
			   tmp[0]=string[i];        
			   if(prvIsAlpha) strcat(words[totalNumber-1],tmp);        
			   else words[totalNumber++][0]=string[i];         prvIsAlpha=1;      }      
		   else prvIsAlpha=0;
		   count++;
   }
}          /*将字符串中的单词存入words的二维数组中并且找出字符串中有多少个单词count*/
int StrCompare_sq(char *s,char *t){
	int i;
	for(i=0;s[i]!='\0'&&t[i]!='\0';i++)
		if(s[i]!=t[i])return(s[i]-t[i]);
		return(s[i]-t[i]);/*比较两字符串的大小，若相同返回0*/
}
void diagscan(int mat[100][100],int m,int n, int i,int j,int &maxlen,int &jpos){
	int eq=0,len=0,sj;
	maxlen=0;
	while(i<m&&j<n){
		if(mat[i][j]==1){
			len++;
			if(!eq){
				eq=1;sj=j;
			}
		}
		else if(eq){
			if(len>maxlen){
				maxlen=len;jpos=sj;
			}
			eq=0;len=0;
		}
		i++;j++;
	}
	if(len>maxlen){
		maxlen=len;
		jpos=sj;
	}
}               /*从[i,j]开始沿对角线方向扫描最长的连续1，maxlen和jpos分别返回最长连续1的长度和起点j的坐标*/
void diagmax(int mat[100][100],int m,int n, int &maxlen,int &jpos){
	int istart=0,k,i,j;
	maxlen=0;
	jpos=-1;
	for(k=-(n-1);k<=m-1;k++){
		i=istart;
		j=i-k;
		diagscan(mat,m,n,i,j,maxlen,jpos);
		istart+=(k>=0)?1:0;
	}
}             /*求矩阵mat中对角线方向上连续1的最长长度maxlen和起点的j坐标jpos*/
void Strncpy_sq(char *sub[100],char *words[100][],int jpos,int i){
	int j;
	for(j=0;words[jpos][j]!='\0';j++)
		sub[i][j]=words[jpos][j];
	sub[i][j]='\0';
}
void getmaxsamewords(char *string1,char *string2,char sub[100][],int &max){
   int i,j,mat[100][100],maxlen,jpos;
   char words1[100][20],words2[100][20];
   read(string1,words1,m0);
   read(string2,words2,n0);
   for(i=0;i<m0;i++)
	   for(j=0;j<n0;j++)
		   mat[i][j]=(StrCompare_sq(words1[i],words2[j])==0)?1:0;
	   diagmax(mat,m0,n0,maxlen,jpos);
	   if(maxlen==0)
		   sub[0]=;
	   else{
		   for(i=0;i<maxlen;i++,jpos++)
			   Strncpy_sq(sub,words2,jpos,i);
		   sub[maxlen]='\0';}
	   max=maxlen;
}        /*找出最大的公共单词串并存入二维数组sub中*/
void deletemax(char string1[],char string2[],char sub[100][]){
void main(){
	int countnum=0,m0,n0,max[100],i,sum=0;
	double S;
	char string1,string2,sub[100][20];
	printf("请输入两个句子:\n");
	scanf("%s",&string1);
	scanf("%s",&string2);	
    getmaxsamewords(string1,string2,sub,max[countnum]);
	for(i=0;sub[i]!='\0';i++)
	printf("%s",sub[i]);
	while(1){
		if(sub='\0')
			break;
		deletemax(string1,string2,sub);   
	getmaxsamewords(string1,string2,sub,max[countnum++]);
    for(i=0;sub[i]!='\0';i++)
	printf("%s",sub[i]);
	}
    for(i=0;i<countnum;i++)
		sum+=max[i];
    S=2.0*(double)sum/(double)(m0+n0);
    printf("相似度为%lf\%\n",S*100);
}

