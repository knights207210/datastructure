#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int c1,c2,len1,len2;float sum=0.0;
int max(int x,int y){
	return (x>=y)?x:y;
}
int min(int x,int y){
	return (x<y)?x:y;
}
int SentenceNum(FILE *fp)//数文件中的句子，一个标点标识有一个句子
{
	int count = 0;
	char fc;
	fc = fgetc(fp);
	while (!feof(fp))
	{
		if (fc == '.' || fc == '?' || fc == '!')
		{
			count++;
			fc = fgetc(fp);
		}
		else
		{   fc = fgetc(fp);
			if (fc == -1)                //最后一个字符结束，句子数加一 
				count++;
		}
	}
	return count;
}
int GetLCSLen(char *Str1, char *Str2)//获得最长公共序列长度
{
	int i, j, len1, len2,c[200][200];char fs1[200], fs2[200];
	len1 = strlen(Str1);
	len2 = strlen(Str2);
	for (i = 0; i < max(len1, len2); i++)
	{
		c[i][0] = 0;
		c[0][1] = 0;
	}
	for (i = 1; i <= len1; i++)
	{
		for (j = 1; j <= len2; j++)
		{
			if (Str1[i - 1] == Str2[j - 1])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
		}
	}
	return(c[len1][len2]);
}

void Similar(FILE *fp1, FILE *fp2)
{
	char sent1, sent2;char fs1[200], fs2[200];
	/*sent1，sent2分别是在文件1,2中读得的当前字符，fs1，fs2分别是文件1,2中读出的当前字符串*/
	int i, j, slen, len,sum1;
	//sum1计数相似句子即相似字符串的个数,c1计数文件1的句子数,c2计数文件2的句子数
	while (!feof(fp1))
	{
		sum = 0.0;
		sent1 = fgetc(fp1);
		for (i = 0;; i++)
		{
			if (sent1 == '.' || sent1 == '?' || sent1 == '!' || sent1 == -1)/*如果遇到标点，则为一句，当前读取过程结束。*/
			{
				break;
			}
			if (sent1 == ' ' || sent1 == ','|| sent1 == ';' || sent1 == '\n' || sent1 == '"' || sent1 == '"')
			{
				i--;
			}
			else
			{
				fs1[i] = sent1;  //当前字符给fs1
			}
			sent1 = fgetc(fp1);
		}
		fs1[i] = '\0';
		rewind(fp2);//将文件的内置指针重置
		while (!feof(fp2))
		{
			sent2 = fgetc(fp2);
			for (j = 0;; j++)
			{
				if (sent2 == '.' || sent2 == '?' || sent2 == '!' || sent2 == -1)
				{
					break;}
				if (sent2 == ' '|| sent2 == ',' || sent2 == ';' || sent2 == '\n' || sent2 == '"' || sent2 == '"')
				{
					j--;}
				else{
			         fs2[j] = sent2;}
				sent2 = fgetc(fp2);
			}
			fs2[j] = '\0';
			len = GetLCSLen(fs1, fs2);
			slen = (strlen(fs1) > strlen(fs2)) ? strlen(fs1) : strlen(fs2);
			if ((float)len/slen>=0.5)            
			{ printf(" %f ",(float)len/slen);
			sum1++;
			}if(sum1=1)sum+=1.0;
		}	
	}
	rewind(fp1);//重置两文件指针
	rewind(fp2);
	c1 = SentenceNum(fp1);
	c2 = SentenceNum(fp2);
	fclose(fp1);//关闭文件
	fclose(fp2);
}

void similarity(){
	
	printf("There are %d centences in text1.\n", c1);
	printf("There are %d centences in text2.\n", c2);
	printf("The similarity is %f.\n", (float)sum / min(c1, c2));                         //输出整体相似度
}
main()
{
	FILE *fp1, *fp2; 
	fp1 = fopen("paper1.txt", "r");
	if (fp1 == NULL)
	{
		printf("Can't open this file.\n");
		exit(0);
	}
	fp2 = fopen("paper2.txt", "r");
	if (fp2 == NULL)
	{
		printf("Can't open this file.\n");
		exit(0);
	}
	Similar(fp1, fp2);
	similarity();             
}
