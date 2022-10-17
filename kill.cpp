#include <stdio.h>

int q_arr[10];
int front = -1;
int rear = -1;

void Enqueuedata(int temp){
	if(front == 0&& rear == 9 ){
		printf("::queue overflow error::\n");
		return;
	}
	if(front == -1){
		front = 0;
		rear = 0;
	}
	else{
		if (rear==9){
			rear = 0;
		}else{
			rear = rear+1;
		}
	}
	q_arr[rear]=temp;
}

void Dequeuedata(){
	if(front == -1){
		printf("::queue underflow error::\n");
		return;
	}
	printf("Deleted data : %d \n",q_arr[front]);
	if(front==rear){
		front = -1;
		rear = -1;
	}else{
		if(front==9){
			front = 0;
		}else{
			front = front+1;
		}
	}
	printf("\n\n");
}

void printdata(){
	int front_sh = front,rear_sh = rear;
	if(front == -1)
	{
		printf("! Data is emptyn !\n"); 
		return;
	}
	printf("Front : %d\n",front_sh);
	printf("Rear  : %d\n",rear_sh);
	printf("Queue elements : ");
	if( front_sh <= rear_sh )
		while(front_sh <= rear_sh) 
		{
			printf("%d ",q_arr[front_sh]);
			front_sh++;
		}
	else
	{
		while(front_sh <= 9) 
		{
			printf("%d ",q_arr[front_sh]);
			front_sh++;
		}
		front_sh = 0; 
		while(front_sh <= rear_sh)
		{
			printf("%d ",q_arr[front_sh]);
			front_sh++;
		}	
	}
	printf("\n\n");
	
}

void Showmenu(){
	printf("::Circular Queue::\n");
	printf("1. Enqueue(input Data)\n");
	printf("2. Dequeue(Delete Data)\n");
	printf("3. Show Data\n");
	printf("4. Exit!\n");
	printf("\n");
	printf("Your choice>> ");
}

int getchoice(){
	int choice;
	scanf("%d",&choice);
	printf("\n\n");
	return choice;
}

int main(){
	int data,front_sh,rear_sh;
	for(;;){
		Showmenu();
		int choice = getchoice();
		switch(choice){
			case 1:
				printf("Input data : ");
				scanf("%d", &data);
				printf("\n");
				Enqueuedata(data);
				break;
			case 2:
				Dequeuedata();
				break;
			case 3:
				printdata();
				break;
			case 4:
					return 0;
			default:
				printf("Wrong choice \n\n");
		}
	}
	return 0;
	
	
}
