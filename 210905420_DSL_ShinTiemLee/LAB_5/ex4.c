#include <stdio.h> 
#include <stdlib.h>

typedef struct {
    int *st;
    int tos;
} Stack;

Stack push(Stack s,int x) {
    s.tos +=1;
    s.st[s.tos] = x;
    return s;
}

Stack del(Stack s,int ind) {
    int i;
    for (i=ind;i<s.tos;i++) {
        s.st[i] = s.st[i+1];
    }
    s.tos-=1;
    return s;
}

int main() {

    Stack s;

    int n,i,j,k,count=0;
    
    printf("Enter number of elements ");
    scanf("%d",&n);

    s.st = (int *) malloc (n * sizeof(int));

   printf("Enter elements ");
    for(i=0;i<n;i++) {
        scanf("%d",&s.st[i]);
    }
    s.tos = n-1;

    printf("Enter the number of elements that must be deleted ");
    scanf("%d",&k);

    count=k;
    while(count>0){
    for(i=0;i<s.tos;i++){
    	if(s.st[i]<s.st[i+1]){
    		s=del(s,i);
    		count--;
    		break;
    	}
    }
}


    printf("The final array is:\n");
    for(i = 0;i <= s.tos; i++) {
        printf("%d ",s.st[i]);
    }

    return 0;
}
