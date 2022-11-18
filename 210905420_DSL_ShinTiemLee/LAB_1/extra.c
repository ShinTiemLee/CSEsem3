#include <stdio.h>
struct candidate{
	int code;
	int count;
};
int main(){
	int m,n,vote;
	printf("Enter the number of voters and candidates: ");
	scanf("%d %d",&n,&m);
	struct candidate can[m];
	for(int i=0;i<m;i++){
		can[i].code=i+1;
		can[i].count=0;
	}
	for(int j=0;j<n;j++){
		printf("Voter number %d\n",j+1);
		printf("Cast vote for candidate with code ranging from 1 to %d",m);
		scanf("%d",&vote);
		can[vote-1].count++;
	}
	for( int i=0;i<m;i++){
		printf("Candidate code: %d; Number of votes: %d",can[i].code,can[i].count);
	}
	} 