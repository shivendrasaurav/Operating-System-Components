#include<iostream>
using namespace std;

int main(){
	int n,i,j,fs,ch,sb;
	printf("\nEnter Storage Space in MB: ");
	scanf("%d",&n);
	int mem[n]={0};
	while(1){
	printf("\n1. Insert More File(s) \n2. Exit \nEnter Your Choice: ");
	scanf("%d",&ch);
	if(ch==1){
		printf("\nEnter file size in MB: ");
		scanf("%d",&fs);
		printf("\nEnter Starting Block: ");
		scanf("%d",&sb);
		int eb=sb+fs;
		for(j=sb;j<eb;j++){
			if(mem[j]==1){
				printf("\nblock %d is already full, skipping this block", j);
				eb++;
			}
			else if(mem[j]==0){
				mem[j]=1;
				printf("\nSpace Allocated at block : %d", j);
			}
		}
		printf("\n\nStatus of memory: \n");
		for(i=0;i<n;i++)
			printf("%d\t", mem[i]);
	}
	else if(ch==2)
		exit(0);
	else
		continue;
	}
}
