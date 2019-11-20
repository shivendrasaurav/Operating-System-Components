#include<stdio.h>

int main(){
	int n,i,j,at;
	printf("\nEnter Number Of Processes: ");
	scanf("%d",&n);
	printf("\nEnter Arrival Time In Seconds : ");
	scanf("%d", &at);
	int dur[n], bt[n], wt[n], tat[n];
	printf("\nEnter Burst Time Array For Processes: \n");
	for(i=0;i<n;i++)
		scanf("%d", &bt[i]);
	wt[0]=at;
	for(i=1;i<n;i++){
		wt[i] = bt[i-1] + wt[i-1];
		printf("%d\t", wt[i]);
	}
	for(i=0;i<n;i++){
		tat[i] = wt[i] + bt[i];		
		printf("%d\t", tat[i]);
	}
	float avgwt, avgtat, totwt=0, totat=0;
	for(i=0;i<n;i++){
		totwt = totwt + wt[i];
		totat = totwt + tat[i];
	}
	printf("\nAverage Waiting Time: %f \n\nAverage Turnaround Time: %f", totwt/n, totat/n);
}
