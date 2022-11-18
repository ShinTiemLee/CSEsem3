#include <stdio.h>
#include <string.h>

int palin(char str[],int start,int end){
	if(start>=end)
		return 1;
	if(str[start]!=str[end])
		return 0;
	palin(str,start+1,end-1);
}

int main(){
	char str[30];
	fgets(str,30,stdin);
	int p=palin(str,0,strlen(str)-2);
	if(p==0)
		printf("The string is not a palindrome");
	else
		printf("The string is a palindrome");
	return 0;
}