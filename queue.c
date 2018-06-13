#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 5
 struct lqueue {
   int data[MAX];
   int rear,front;
} q;

void initialize()
{
	q.rear=q.front=-1;
}
int full()
{
	if(q.rear==MAX-1)
	return 1;
	else
	return 0;
}

int empty()
{
	if((q.front==-1)||(q.front>q.rear))
	return 1;
	else
	return 0;
}
void enqueue(int item)
{
	
	int f;
	f=full();
	if(f!=1){
	if (q.front == -1)
	q.front=0;
	q.rear=q.rear+1;
    q.data[q.rear] = item;

}
else
printf("Queue Overflow");
}

void  dequeue()
{
	 int no,e;
	 e=empty();
	if(e!=1)
	{
	no=q.data[q.front];
	if(q.front==q.rear)
	q.front=q.rear=-1;
	else
	q.front= q.front+1;
	printf("Deleted data is %d",no);	
	}
	else
	printf("\nQueue Underflow");
	
		
//	return d;
}

void display()
{
	int i;
	if(q.front==-1)
		printf("\nQueue Underflow");
		else
		{
		printf("\nQueue is \n");
	    for(i=q.front;i<=q.rear;i++)
	     printf("%d\t",q.data[i]);
    	}
	
		
	
}
	
int main()
{
	int choice,item;
	char ans;
	initialize();
	printf("\n\tImplementation Of Queue");
   do {
      printf("\nMain Menu");
      printf("\n1.Insertion \n2.Deletion \n3.Display \n4.exit");
      printf("\nEnter Your Choice");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
          {
          printf("\nEnter The item to be inserted");
         scanf("%d", &item);
	     enqueue(item);
	 }
         break;
      
      case 2:
         dequeue();
         break;
      case 3:
      	 display();
      	 break;
      	 
      case 4:printf("Default Case");
      break;
      }
      printf("\nDo You want To Continue?");
      ans = getche();
   } while (ans == 'Y' || ans == 'y');
	return 0;
}



	

