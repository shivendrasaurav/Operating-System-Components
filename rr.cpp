#include<stdio.h>

int main(){
	int n, q, at, i, j, t=0, count=0;
	printf("\nEnter No Of Processes: ");
	scanf("%d", &n);
	printf("\nEnter Quantum Number: ");
	scanf("%d", &q);
	printf("\nEnter Arrival Time: ");
	scanf("%d", &at);
	int bt_rem[n], bt[n], wt[n] = {0}, tat[n];
	printf("\nEnter Burst Time Array: ");
	for(i=0; i<n; i++){
		scanf("%d", &bt[i]);
		bt_rem[i] = bt[i];
	}
	while(1){
		bool done=true;
		for(i=0; i<=n; i++){
			if(bt_rem[i]>0){
				done = false;
				if(bt_rem[i]>q){
					t= t + q;
					bt_rem[i] = bt_rem[i] - q;
				}
				else{
					t= t+bt_rem[i];
					printf("\nTotal Time: %d\n",t);
					wt[i]= t-bt[i];
					bt_rem[i] = 0;
					count++;
				}
			}
		}
		if(count==n)
			break;
	}
	printf("\nWaiting Time Array: "); 
	for(i=0; i<n; i++)
		printf("%d\t", wt[i]);
	printf("\nTurnaround Time Array: "); 
	for(i=0;i<n;i++){
		tat[i] = wt[i] + bt[i];
		printf("%d\t", tat[i]);
	}
	float avgwt, avgtat, totwt=0, totat=0;
	for(i=0;i<n;i++){
		totwt = totwt + wt[i];
		totat = totat + tat[i];
	}
	printf("\nTotal Waiting Time : %f \n\nAverage Waiting Time: %f \n\nTotal Turnaround Time : %f \n\nAverage Turnaround Time: %f",totwt, totwt/n, totat, totat/n);
}
