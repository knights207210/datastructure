#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
		return(-1);
	else
		return i-j;
}main(){
        char *string1 = (char *)malloc(100);
	fgets(string1,20,stdin);
	char *string2 = (char *)malloc(100);
	fgets(string2,20,stdin);
	
	printf("%d",index(string1,string2,0));
}
