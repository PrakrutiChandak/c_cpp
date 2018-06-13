#include<stdio.h>
#define MAX 20
struct stack
{
	int top;
	int data[MAX];
}s;
void initialize()
{
	s.top=-1;
}
int full()
{
	if(s.top==MAX-1)
		return 1;
	return 0;
	
}
int empty()
{
	if(s.top<0)
		return 1;
	return 0;
}
void push(int x)
{
	int f;
	f=full();
	
	if(f!=1)
	{	s.top++;
		s.data[s.top]=x;
		
	}
}
int pop()
{
	int e,x;
	e=empty();
	if(e!=1)
	{
		x=s.data[s.top];
		s.top--;
	}
	return x;
}
void main()
{	struct s;
	int rem,num,j,a=0;
	
	initialize();
	printf("Enter a number:");
	scanf("%d",&num);
	
	while(num!=0)
	{
		rem=num%2;
		push(rem);
		num=num/2;
		a++;
	}
	for(;a>0;a--)
	{
		j=pop();
		printf("%d",j);

	}
	
}

