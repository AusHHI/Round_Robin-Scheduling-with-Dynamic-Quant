#include<stdio.h>
#include<stdlib.h>
struct node{
	int at,pt,cp,ta,wai,rem,pname;
	struct node *next;
};
struct node * getnode(int,int,int); 

struct node *getnode(int info,int x,int y)
{
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	q->at=x;
	q->pt=y;
	q->rem=y;
	q->cp=0;
	q->ta=0;
	q->wai=0;
	q->pname=info;
	q->next=NULL;
	return q;
}

void main(){
	struct node *robin,*p,*q;
	robin=NULL;
	int y,x,info,quant,time=0,n,j,i,flag,it;
	float thru,b,t,util;
	printf("Enter number of processes");
	scanf("%d",&n);
	printf("Enter quant time");
	scanf("%d",&quant);
	for(i=0;i<n;++i){
		printf("Enter the name of process %d,arrival,process time\n",i);
		scanf("%d%d%d",&info,&x,&y);
		q=getnode(info,x,y);
		if(robin==NULL)
			robin=q;
		else
		{
			for(p=robin;p->next!=NULL;p=p->next)
			{
			}
			p->next=q;
		}
	}
	do{
		j=0;
		flag=0;
		for(p=robin;p->next!=NULL;p=p->next){
			if((p->at<=time)&&(p->rem>0)){
				printf("%d\t",p->pname);
				j=1;
				time=time+quant;
				if(p->rem<quant)
					time=time-(quant-p->rem);
				
				p->rem=p->rem-quant;
					p->cp=time;
			}
		}
		if(j==0){
			it=it+1;
			time=time+1;
		}
		for(p=robin;p->next!=NULL;p=p->next)
			if(p->rem>0)
				flag=1;
		
	}while(flag==1);
	//printf("\nTime:%d\n",time);
	thru=(float)(n-1)/time;
	util=((time-it)/time)*100;
	printf("\nThroughput :%f\n" ,thru);
	printf("Utilisation :%f\n",util);
		
	printf("\nPName\tArrival\tPTime\tCTime\tWaiting\tTurnAround\n");
	for(p=robin;p->next!=NULL;p=p->next){
		p->ta=p->cp-p->at;
		p->wai=p->ta-p->pt;
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\n",p->pname,p->at,p->pt,p->cp,p->wai,p->ta);
		b+=p->wai;
		t+=p->ta;
	}
	printf("\nAverage Waiting Time:%f\n",(b/(n-1)));
	printf("\nAverage Turnaround Time:%f\n",(t/(n-1)));
}
	

