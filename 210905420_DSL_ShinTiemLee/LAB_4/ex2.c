#include <stdio.h>
#include <string.h>

void copy(char source[],char destination[],int index){
	if(source[index]=='\0')
		return;
	destination[index]=source[index];
	copy(source,destination,index+1);
}

int main(){
	char source[30],destination[30];
	fgets(source,30,stdin);
	copy(source,destination,0);
	puts(destination);
	return 0;
}