#include<stdio.h>

int main(){
	int tot_mem, os_rem, n, i, j;
	printf("\nEnter Memory Space: ");
	scanf("%d",&tot_mem);
	printf("\nEnter OS Reserved Memory: ");
	scanf("%d",&os_rem);
	printf("\nEnter Number Of Processes: ");
	scanf("%d",&n);
	int pcs_mem[n];
	printf("\nEnter Process Array: ");
	for(i=0;i<n;i++){
		scanf("%d", &pcs_mem[i]);
	}
	printf("Total Memory: %d", tot_mem);
	tot_mem = tot_mem - os_rem;
	printf("\nMemory After Removing OS Reserved: %d", tot_mem);
	for(i=0;i<n;i++){
		if(tot_mem>pcs_mem[i]){
			tot_mem = tot_mem - pcs_mem[i];
			printf("\nMemory After Allocation Of Process %d: %d", i, tot_mem);		
		}
		else{
			printf("\nMemory Overflow Occured, Not Enough Memory To Allocate To Process: %d", i);
		}
	}
}
