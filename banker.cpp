#include<stdio.h>

int main(){
	int np, nr, i, j, k;
	printf("\nEnter Number Of Processes: ");
	scanf("%d",&np);
	int process[np];
	printf("\nEnter Number Of Resources	: ");
	scanf("%d",&nr);
	int res[nr], alloc[np][nr], max[np][nr];
	printf("\nEnter Available Resources Matrix: \n");
	for(i=0; i<nr; i++)
		scanf("%d", &res[i]);
	printf("\n\nEnter Allocation Matrix: \n");
	for(i=0;i<np;i++)
		for(j=0;j<nr;j++)
			scanf("%d",&alloc[i][j]);
	printf("\n\nEnter Max Matrix: \n");
	for(i=0;i<np;i++)
		for(j=0;j<nr;j++)
			scanf("%d",&max[i][j]);
	
    int f[np], ans[np], ind = 0; 
    for (k = 0; k < np; k++) { 
        f[k] = 0; 						//set all the flags to zero
    }
    int need[np][nr]; 
    for (i = 0; i < np; i++) { 
        for (j = 0; j < nr; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 		//Calculate need matrix
    }
    int y = 0;
    for (k = 0; k < np; k++) { 
        for (i = 0; i < np; i++) { 
            if (f[i] == 0) {   
                int flag = 0;
                for (j = 0; j < nr; j++) { 			//If need is greater than available, set flag=1 and break
                    if (need[i][j] > res[j]){
                        flag = 1;
                        break;
                    } 
                } 
  
                if (flag == 0) {				//If flag remains 0 it means need is less than available, and the process will run
                    ans[ind++] = i; 
                    for (y = 0; y < nr; y++) 
                        res[y] += alloc[i][y]; 			//add allocated matrix to resource matrix and set flag[i]=1
                    f[i] = 1;
                } 
            } 
        } 
    } 
  
    printf("Following is the SAFE Sequence\n"); 
    for (i = 0; i < np - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[np - 1]); 
  
    return (0); 
  
}
