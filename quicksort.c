#include<stdio.h>
#define MAX 20
void quicksort(int [],int ,int ,int );
int partition (int [],int ,int ,int );
void print(int [],int );

void main()
{
	int a[MAX],n,i;
	printf("Enter array length:");
	scanf("%d",&n);
	printf("\nEnter array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Before sorting:\n");
	print(a,n);
	quicksort(a,0,n-1,n);
	printf("\nAfter sorting:\n");
	print(a,n);

}
void print(int a[MAX],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void quicksort(int a[MAX],int low,int high,int n)
{
	int j,i;
	if(low<high)
	{
		j=partition(a,low,high,n);
		quicksort(a,low,j,n);
		quicksort(a,j+1,high,n);
	
		
	}
}
int partition(int a[MAX],int low ,int high,int n)
{
	int pivot,i,j,temp,mid;
	i=low-1;
	j=high+1;
	mid=(low+high)/2;
	pivot=a[mid];
	
	while(j>=i)
	{
		do{i++;}while(a[i]<pivot);
		do{j--;}while(a[j]>pivot);
		
		if(j>i)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
/*	temp=a[j];
	a[j]=a[mid];
	a[mid]=temp;*/
	

	
	return j;
		
}
