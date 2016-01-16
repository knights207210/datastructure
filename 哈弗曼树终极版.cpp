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
 int count=0;
void Select(HuffmanTree HT,int n,int *s1,int *s2){ 
 int i;
 int min1=999,min2=999;
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
                                                                       /*建哈夫曼树*/
Select(HT,i-1,&s1,&s2);
 HT[s1].parent=i;
 HT[s2].parent=i;
 HT[i].lchild=s1;
 HT[i].rchild=s2;
 HT[i].weight=HT[s1].weight+HT[s2].weight;
 }


                                                                       /*从叶子到根逆向求每个字符的哈夫曼编码*/
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

 void Weight(FILE *fp,HuffmanCode &HC,int &n){                          /*求出一共有多少种字符及权值*/
int i,j,k,l;
 i=j=k=n=0;
 HC=(HuffmanCode)malloc(1000000*sizeof(Code));
 for(l=0;l<1000000;l++){
	 HC[l].weight=0;
	 HC[l].node='\0';
 }
 k=fgetc(fp);
 while(!feof(fp)){
	 count++;
 HC[k+256].weight++;
 k=fgetc(fp);
 }
 
 for(;j<512;j++){
	 if(HC[j].weight!=0) {
		 n++;
         HC[j].node=(char)(j-256);
	 }
 }
 }
 void printHTree(HuffmanTree HT,int n){
	int i;printf("\nHuffmantree:\nweight,parent,lchild,rchild\n");
	for(i=0;i<=2*n-3;i++){
		printf("%5d%5d%5d%5d\n",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	}
}
 main(){
	 HuffmanTree HT;
     HuffmanCode HC;
	 int n;
	 int str1,str2;
	 double rate;
     FILE *fp;
	fp=fopen("text.txt","r");
	if (fp == NULL)
	{
		printf("Can't open this file.\n");
		exit(0);
	}
	 Weight(fp,HC,n);
	 CreateandEncode(HT,HC,n,str2);
	 printHTree(HT,n);
     str1=count;
	 rate=(double)str1/(double)(str2*7);
	 printf("压缩比为：%lf%%\n",rate*100);
	 fclose(fp);
}