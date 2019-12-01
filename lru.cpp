#include<stdio.h>

int main(){
	int n,nf,i,j,flt_cnt=0,f1=0,f2=0,cnt=0;
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
		f1=f2=0;					//set flag 1 and 2 as zero
		for(j=0;j<nf;j++){
			if(fr[j]==ref[i]){			//checks if frame already exists, if yes, set flags as 1 and break
				f1=f2=1;
				break;
			}
		}
		if(f1==0){					//if frames are empty or not
			for(j=0;j<nf;j++){
				if(fr[j]==-1){				
					fr[j]=ref[i];
					f2=1;
					flt_cnt++;
					break;
				}
			}
		}
		if(f2==0){					//search for frame, if not found replace page
			for(j=0;j<nf;j++){
				if(ref[i]!=fr[j]){
					fr[j+cnt%nf]=ref[i];
					flt_cnt++;
					cnt++;
					break;
				}
			}
		}
		printf("\n\nFrames Status: ");
		for(j=0;j<nf;j++)
			printf("%d\t", j[fr]);
	}
	printf("\n\nNo of page faults: %d", flt_cnt);
}
