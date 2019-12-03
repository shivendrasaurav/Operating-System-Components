#include<stdio.h>

int mutex=1, full=0, empty=3, x=0;

int signal(int s){
	return ++s;
}
int wait(int s){
	return --s;
}
int producer(){
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	x++;
	printf("\nProducer has produced the item %d: ", x);
	mutex=signal(mutex);
}
int consumer(){
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	x--;
	printf("\nConsumer has consumed the item %d: ", x);
	mutex=signal(mutex);
}

int main(){
	int n;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);
	printf("\n1.Producer\n2.Consumer\n3.Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((mutex==1)&&(empty!=0))
						producer();
					else
						printf("Buffer is full!!");
					break;
			case 2:	if((mutex==1)&&(full!=0))
						consumer();
					else
						printf("Buffer is empty!!");
					break;
			case 3:
					break;
		}
	}
	
	return 0;
}
