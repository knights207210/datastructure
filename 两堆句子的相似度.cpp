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
int SentenceNum(FILE *fp)//���ļ��еľ��ӣ�һ������ʶ��һ������
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
			if (fc == -1)                //���һ���ַ���������������һ 
				count++;
		}
	}
	return count;
}
int GetLCSLen(char *Str1, char *Str2)//�����������г���
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
	/*sent1��sent2�ֱ������ļ�1,2�ж��õĵ�ǰ�ַ���fs1��fs2�ֱ����ļ�1,2�ж����ĵ�ǰ�ַ���*/
	int i, j, slen, len,sum1;
	//sum1�������ƾ��Ӽ������ַ����ĸ���,c1�����ļ�1�ľ�����,c2�����ļ�2�ľ�����
	while (!feof(fp1))
	{
		sum = 0.0;
		sent1 = fgetc(fp1);
		for (i = 0;; i++)
		{
			if (sent1 == '.' || sent1 == '?' || sent1 == '!' || sent1 == -1)/*���������㣬��Ϊһ�䣬��ǰ��ȡ���̽�����*/
			{
				break;
			}
			if (sent1 == ' ' || sent1 == ','|| sent1 == ';' || sent1 == '\n' || sent1 == '"' || sent1 == '"')
			{
				i--;
			}
			else
			{
				fs1[i] = sent1;  //��ǰ�ַ���fs1
			}
			sent1 = fgetc(fp1);
		}
		fs1[i] = '\0';
		rewind(fp2);//���ļ�������ָ������
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
	rewind(fp1);//�������ļ�ָ��
	rewind(fp2);
	c1 = SentenceNum(fp1);
	c2 = SentenceNum(fp2);
	fclose(fp1);//�ر��ļ�
	fclose(fp2);
}

void similarity(){
	
	printf("There are %d centences in text1.\n", c1);
	printf("There are %d centences in text2.\n", c2);
	printf("The similarity is %f.\n", (float)sum / min(c1, c2));                         //����������ƶ�
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
