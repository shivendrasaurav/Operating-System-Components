#include<stdio.h>

int main(){
	int n,i,j,at,t1,t2;
	printf("\nEnter Number Of Processes: ");
	scanf("%d",&n);
	printf("\nEnter Arrival Time In Seconds : ");
	scanf("%d", &at);
	int pos[n], bt[n], wt[n], tat[n];
	printf("\nEnter Burst Time Array For Processes: \n");
	for(i=0;i<n;i++){
		scanf("%d", &bt[i]);
		pos[i]=i;
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(bt[i]>bt[j]){
				t1=bt[i];
				bt[i]=bt[j];
				bt[j]=t1;
				t2=pos[i];
				pos[i]=pos[j];
				pos[j]=t1;
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
		totat = totat + tat[i];
	}
	printf("\nTotal Waiting Time : %f \n\nAverage Waiting Time: %f \n\nTotal Turnaround Time : %f \n\nAverage Turnaround Time: %f",totwt, totwt/n, totat, totat/n);
}
