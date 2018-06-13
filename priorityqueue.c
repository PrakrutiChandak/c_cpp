#include <stdio.h>
#include <conio.h>
#include<string.h>
#define MAX 5
struct data
{
char job[MAX] ;
int priority ;
int ord ;
} ;
struct pque
{
struct data d[MAX] ;
int front ;
int rear ;
} ;

void initialise(struct pque *pq);
void addq(struct pque *pq,struct data dt);
struct data deletq(struct pque *pq);
void display(struct pque *pq);


void main()
{
struct pque q;
struct data dt,temp;
int i,j=0;
initialise(&q);
printf("\nEnter Job & Its Priority\n");
printf("\nLower Number Highest Priority\n");
for(i=0;i<MAX;i++)
{
scanf ( "%s %d",dt.job,&dt.priority ) ;
dt.ord = j++ ;
addq (&q,dt) ;
}
display(&q);

printf("\nJob will be removed in following order\n");
printf ( "Job\tPriority\n" ) ;
for ( i = 0 ; i < MAX ; i++ )
{
temp = deletq(&q) ;
printf ( "%s\t%d\n", temp.job,temp.priority) ;
}
printf ( "\n" ) ;
getch();
}



void initialise(struct pque *pq)
{
	 pq->front=pq->rear=-1;
	 int i;

	 for(i=0;i<MAX;i++)
	 {
		 strcpy(pq->d[i].job,"\0");
		 pq->d[i].ord=0;
		 pq->d[i].priority=0;
	  }
 }



 void  addq(struct pque *pq,struct data dt)
 {
	  struct data tmp;
	  int i,j;
	  if(pq->rear==MAX-1)
	  printf("\nQueue is Full");
	  else if((pq->front==-1) && (pq->rear==-1))
	  {
		  pq->front=pq->rear=0;

		  pq->d[pq->rear]=dt;
	  }
	  else
	  {
		  pq->rear++;
		  pq->d[pq->rear]=dt;
		  for(i=pq->front;i<=pq->rear;i++)
		  {
		  for(j=i+1;j<=pq->rear;j++)
		  {
			 if(pq->d[i].priority>pq->d[j].priority)
			 {
				tmp=pq->d[i];
				pq->d[i]=pq->d[j];
				pq->d[j]=tmp;
			 }//end of if
			 else if(pq->d[i].priority==pq->d[j].priority)
			 {
			 if(pq->d[i].ord>pq->d[j].ord)
			 {
				  tmp=pq->d[i];
				  pq->d[i]=pq->d[j];
				  pq->d[j]=tmp;
			 }
			 }//end of else

		  }//end of j
		  } //end of i
		  } //end of else

 }                  //end of function


 void display(struct pque *q)
 {
		int i;
		printf("\nDisplay Jobs");
printf("\nProcess Priority Order\n");
for(i=0;i<MAX;i++)
{
	  printf("%s\t%d\t%d\n",q->d[i].job,q->d[i].priority,q->d[i].ord);
}
}

struct data deletq(pque *pq)
{

struct data t ;

if ( pq -> rear == -1 )
{
printf ( "\nQueue is Empty.\n" ) ;
}
t = pq -> d[pq -> front] ;
if ( pq -> front == pq -> rear )
pq -> front = pq -> rear = -1 ;
else
pq -> front++ ;
return t ;
}
