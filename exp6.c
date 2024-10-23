#include<stdlib.h>
#include<stdio.h>
#define size 5
char cq[size],ele;
int front=-1,rear=-1,ch;
void enque();
void deque();
void display();

void main()
{	
	printf("1.Insert 2.Delete 3.Display 4.Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enque();
				break;
			case 2:deque();
				break;
			case 3:display();
				break;
			case 4:exit(0);
		}
	}
}
void enque()
{
	if(front==(rear+1)%size)
	{
		printf("Circular Queue Overflow");
		return;
	}
	if(front==-1)
	front++;
	printf("Enter the character to the circular queue");
	scanf("\n%c",&ele);
	rear=(rear+1)%size;
	cq[rear]=ele;
}
void deque()
{
	char item;
	if(front==-1)
	{
		printf("Circular Queue Underflow");
		return;
	}
	else if(front==rear)
	{
	item=cq[front];
	printf("Deleted element is:%c",item);
	front=-1;
	rear=-1;
	}
	else
	{
	item=cq[front];
	printf("Deleted element is:%c",item);
	front=(front+1)%size;
	}
}
void display()
{
	int i;
	if(front==-1)
	printf("Circular Queue is Empty");	
	else
	{
	printf("Elements of the circular queue are:");
	for(i=front;i!=rear;i=(i+1)%size)
	{
	printf("%c\n",cq[i]);
	}
		printf("%c",cq[rear]);
	}
}
