#include<stdio.h>

int main(){
	int np, nr, i, j, k;
	printf("\nEnter Number Of Processes: ");
	scanf("%d",&np);
	int process[np];
	printf("\nEnter Number Of Resources	: ");
	scanf("%d",&nr);
	int res[nr], alloc[np][nr], max[np][nr];
	printf("\nEnter Total Resources Matrix: \n");
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
        f[k] = 0; 
    } 
    int need[np][nr]; 
    for (i = 0; i < np; i++) { 
        for (j = 0; j < nr; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    } 
    int y = 0; 
    for (k = 0; k < 5; k++) { 
        for (i = 0; i < np; i++) { 
            if (f[i] == 0) { 
  
                int flag = 0; 
                for (j = 0; j < nr; j++) { 
                    if (need[i][j] > res[j]){ 
                        flag = 1; 
                         break; 
                    } 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 0; y < nr; y++) 
                        res[y] += alloc[i][y]; 
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
