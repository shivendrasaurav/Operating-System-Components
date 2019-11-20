#include<stdio.h>

int main(){
	int n,nf,i,j,fc=0,f1=0,f2=0;
	printf("Enter No Of Pages : ");
	scanf("%d",&n);
	int ref[n];
	printf("\nEnter Reference String : ");
	for(i=0;i<n;i++){
		scanf("%d",&ref[i]);
	}
	printf("\nEnter Number Of Frames: ");
	scanf("%d",&nf);
	int fr[nf];
	for(i=0;i<nf;i++)
		fr[i]=-1;
	for(i=0;i<n;i++){
		f1=f2=0;
		for(j=0;j<nf;j++){
			if(fr[j]==ref[i]){
				f1=f2=1;
				break;
			}
		}
		if(f1==0){
			for(j=0;j<nf;j++){
				if(fr[j]==-1){
					fr[j]=ref[i];
					f2=1;
					break;
				}
			}
		}
		if(f2==0){
			for(j=0;j<nf;j++){
				if(fr[j]!=ref[i]){
					fr[j]=ref[i];
					fc++;
					break;
				}
			}
		}
		printf("\n\nFrames Status: ");
		for(j=0;j<nf;j++)
			printf("%d\t", j[fr]);

	}
	printf("\n\nNo of page faults: %d", fc);
}
