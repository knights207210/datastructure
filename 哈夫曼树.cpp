#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>

typedef struct{
 char node;
 int weight;
 int parent,lchild,rchild;
 }HTNode,*HuffmanTree;

typedef struct{
 char node;
 int weight,len;
 char *code;
 }Code,*HuffmanCode;

void Select(HuffmanTree HT,int n,int *s1,int *s2){ 
 int i;
 int min1=99999999,min2=99999999;
 for(i=0;i<=n;i++){
 if(HT[i].parent!=-1) continue;
 else if(HT[i].weight<min1){
 min2=min1;
 *s2=*s1;
 min1=HT[i].weight;
 *s1=i;
 }
 else if(HT[i].weight<min2){
 min2=HT[i].weight;
 *s2=i;
 }
 }
 }

 void CreateandEncode(HuffmanTree &HT,HuffmanCode &HC,int n,int &str){
 int i,m,j=0,s1=-1,s2=-1;
 str=0;
 if(n<=1) return;
 m=2*n-1;
 HT=(HuffmanTree)malloc(m*sizeof(HTNode));
 for(i=-256;i<256;i++){
 if(HC[i+256].weight!=0){
 HT[j].node=HC[i+256].node;
 HT[j].weight=HC[i+256].weight;
 HT[j].parent=HT[j].lchild=HT[j].rchild=-1;
 j++;
 }
 }
 for(;j<m;j++){
 HT[j].node='\0';
 HT[j].weight=0;
 HT[j].parent=HT[j].lchild=HT[j].rchild=-1;
 }
 for(i=n;i<m;i++){
 //建哈夫曼树
Select(HT,i-1,&s1,&s2);
 HT[s1].parent=i;
 HT[s2].parent=i;
 HT[i].lchild=s1;
 HT[i].rchild=s2;
 HT[i].weight=HT[s1].weight+HT[s2].weight;
 }


 //从叶子到根逆向求每个字符的哈夫曼编码
char *cd;
 int k;
 cd=(char*)malloc(n*sizeof(char));
 int start,c,f;
 cd[n-1]='\0';
 for(i=0;i<n;i++){
 start=n-1;
 for(c=i,f=HT[i].parent;f!=-1;c=f,f=HT[f].parent){
 if(HT[f].lchild==c) cd[--start]='0';
 else cd[--start]='1';
 }
 k=n-start;
 j=HT[i].node;
 HC[j+256].code=(char*)malloc(k*sizeof(char));
 strcpy(HC[j+256].code,&cd[start]);
 HC[j+256].len=strlen(HC[j+256].code);
 str+=HC[j+256].len*HC[j+256].weight;
 printf("%c-------%s\n",HC[j+256].node,HC[j+256].code);
 }
 }

 void Weight(char *input,HuffmanCode &HC,int &n){
 //求出一共有多少种字符及权值
int i,j,k,l;
 i=j=k=n=0;
 HC=(HuffmanCode)malloc(1000000*sizeof(Code));
 for(l=0;l<1000000;l++){
	 HC[l].weight=0;
	 HC[l].node='\0';
 }
 while(input[i]){
 k=input[i];
 HC[k+256].weight++;
 i++;
 }
 
 for(;j<512;j++){
	 if(HC[j].weight!=0) {
		 n++;
         HC[j].node=(char)(j-256);
	 }
 }
 }
 main(){
	 HuffmanTree HT;
     HuffmanCode HC;
	 int n,i;
	 int str1,str2;
	 double rate;
	 printf("请输入一串字符：\n");
	 char input[100];
	 fgets(input,100,stdin);
	 Weight(input,HC,n);
	 CreateandEncode(HT,HC,n,str2);
     str1=strlen(input);
	 rate=(double)str1/(double)(str2*7);
	 printf("压缩比为：%lf%%\n",rate*100);

 }
