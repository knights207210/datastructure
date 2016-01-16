#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
struct HTNode{
	double weight;
	int parent,lchild,rchild;
};
struct Code{
	double weight;
	char code[MAX+1];
};
HTNode HT[2*MAX-1];
Code cd[MAX+1];
double w[MAX];
void Select(HTNode HT[],int n,int &s1,int &s2){
	int i,min=0;
	for(i=0;i<n;i++){
		if(HT[i].parent!=0)
			continue;
		else{
			if(HT[i].weight<=HT[min].weight)
				min=i;
		}
		
	}
		s1=min;	
		if(min==0)
			min=1;
		else
			min=0;
		for(i=0;i<n;i++){
			if((HT[i].parent!=0)||(i==s1))
				continue;
            else{
				if(HT[i].weight<=HT[min].weight)
					min=i;
			}
		}
			s2=min;
}
void CreateHT(HTNode HT[],double w[],int n){
	int m,i,s1,s2;
	m=2*n-1;
    for(i=0;i<m;i++){
		HT[i].weight=i<=n?w[i]:0;
		HT[i].lchild=0;
		HT[i].rchild=0;
		HT[i].parent=0;
	}

	for(i=n;i<m;i++){
		Select(HT,n,s1,s2);
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		HT[s1].parent=HT[s2].parent=i;
	}
}
void Encode(HTNode HT[],int n){
	char b[100];
	int k,start,c,f,i;
	b[n-1]='\0';
	for(i=0;i<n;i++){
		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent){
			if(HT[f].lchild==c)
				b[--start]='0';
			else
				b[--start]='1';
		}
		k=n-start;
		j=HT[i].
void statistics(char string[],double w[],int &n){
	int count[MAX]={0};
	int i,j,k=0;
	double weight[MAX]={0};
	for(i=0;string[i]!='\0';i++)
		count[string[i]]++;
	for(j=0;string[j]!='\0';j++)
		weight[string[j]]=(double)count[string[j]]/(double)i;
	for(i=0;i<=256;i++){
		if(weight[i]!=0)
			w[k++]=weight[i];}
		n=k-1;
}
main(){
	int n,i,j;
	char string[100];
	scanf("%s",string);
	statistics(string,w,n);
	CreateHT(HT,w,n);
	Encode(HT,n);
}





		