#include<stdio.h>
#include<malloc.h>
#include<time.h>
#define N 8
#define STACKSIZE 100
struct Point{               
	int x;
	int y;
	int from;
};                                /*����ṹ���ʾ���λ��*/
struct Stack{
	Point *elem;
	int stacksize;
	int top;
};                                /*����ṹ���ʾջ*/
Point g_round[N]={0,0,0};         /*�洢����ߵ�λ��*/
int Initstack(Stack &s){
	s.elem=(Point*)malloc(STACKSIZE*sizeof(Point));
	if(!s.elem)
		return 0;
	else{
		s.stacksize=STACKSIZE;
		s.top=-1;
		return 1;
	}
}                                 /*ջ��ʼ��*/
void Push(Stack &s,Point e){
	s.elem[++s.top]=e;
}                                 /*ѹջ*/
int Pop(Stack &s,Point &e){
	if(s.top==-1)
		return 0;
	e=s.elem[s.top--];
        return 1;
}                                 /*��ջ*/
void DestoryStack(Stack &s){
	free(s.elem);
	s.top=-1;
	s.stacksize=0;
}                                 /*����ջ*/
int StackEmpty(Stack &s){
	if(s.top==-1)
		return 1;
	else
		return 0;
}                                 /*�ж�ջ�Ƿ�Ϊ��*/
int GetTop(Stack &s,Point &e){
	if(s.top==-1)
		return 0;
	e=s.elem[s.top];
	    return 1;
}                                 /*ȡջ��Ԫ��*/
int GetDeep(Stack s){
	return(s.top+1);
}                                 /*��ջ��*/
void Setround(Point cur){
	Point round[]={
    cur.x-2,cur.y+1,0,cur.x-1,cur.y+2,0,  
    cur.x+1,cur.y+2,0,cur.x+2,cur.y+1,0,  
    cur.x+2,cur.y-1,0,cur.x+1,cur.y-2,0,  
    cur.x-1,cur.y-2,0,cur.x-2,cur.y-1,0,
	};
	for(int i=0;i<N;i++){
		g_round[i].x = round[i].x;  
        g_round[i].y = round[i].y; 
    }
}                               /*�������λ��*/
int GetRound(int i,Point &pt){
	pt.x = g_round[i-1].x;  
    pt.y = g_round[i-1].y;   
    if(pt.x<0 || pt.y<0 || pt.x>N-1 || pt.y>N-1)
        return 0;  
    else    
        return 1; 
}                               /*�ж��Ƿ�����������*/
void main(){
		int order[N][N] = {0};   
        int count = 0; 
		clock_t start=0,end=0;
		double t=0.00;
		Point begin;  
		printf("������ĳ�ʼλ�ã�\n");
		scanf("%d%d",&begin.x,&begin.y);
		begin.from=0;
		while(begin.x>N || begin.x<1 || begin.y>N || begin.y<1){
			printf("���������������룺\n");
			scanf("%d%d",&begin.x,&begin.y);
		}
		start=clock();
		begin.x--;
		begin.y--;
		Stack horse;
		Point cur,next;
		Initstack(horse);
		Push(horse,begin);
		order[begin.x][begin.y]=++count;
		while(count<N*N){
			GetTop(horse,cur);
			Setround(cur);
			int flag=0;
			for(int i=cur.from+1; i<=N;i++){
				if(GetRound(i,next)&&order[next.x][next.y]==0){
				 flag=1;
				 order[next.x][next.y]=++count;
				 Pop(horse,cur);
				 cur.from=i;
				 Push(horse,cur);
				 next.from=0;
				 Push(horse,next);
				 break;
				}
			}
			if(!flag){
				Pop(horse,cur);
				order[cur.x][cur.y]=0;
				count--;
			}
		}
		DestoryStack(horse);
		end=clock();
		t=(double)(end-start)/CLOCKS_PER_SEC;
		printf("����������£�\n");
		for(int m=0;m<N;m++){
			for(int n=0;n<N;n++){
				printf("%6d ",order[m][n]);}
			printf("\n");}
		printf("����ʱ����:%6.2lf\n",t);
}

