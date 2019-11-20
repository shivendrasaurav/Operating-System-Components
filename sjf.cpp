#include<stdio.h>

int main(){
	int n,i,j,at,t1,t2;
	printf("\nEnter Number Of Processes: ");
	scanf("%d",&n);
	printf("\nEnter Arrival Time In Seconds : ");
	scanf("%d", &at);
	int dur[n], bt[n], wt[n], tat[n];
	printf("\nEnter Burst Time Array For Processes: \n");
	for(i=0;i<n;i++){
		scanf("%d", &bt[i]);
		dur[i]=i;
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(bt[i]>bt[j]){
				t1=bt[i];
				bt[i]=bt[j];
				bt[j]=t1;
				t2=dur[i];
				dur[i]=dur[j];
				dur[j]=t1;
			}
		}
	}
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
