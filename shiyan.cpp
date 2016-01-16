#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
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
main(){
	int i,count=0;
	char paras1[N][N]={0};
	char *para1 = (char *)malloc(N);
	fgets(para1,N,stdin);
	read(para1,paras1,count);
	for(i=0;i<count;i++)
		printf("%s",paras1[i]);

}

