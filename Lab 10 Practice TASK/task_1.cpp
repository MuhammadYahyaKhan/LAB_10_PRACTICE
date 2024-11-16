#include<stdio.h>

void calc(int n,int w, int sum){
	sum = sum + w;
	if(n == 1){
		printf("sum = %d",sum);
		return;
	}
	calc(n -1,w,sum);
	
}

int main(){
	int n; printf("Enter the number of box : "); scanf("%d",&n);
	int w; printf("Enter the fixed weight : ");scanf("%d",&w);
	int sum = 0;
	calc(n,w,sum);
	
	return 0;
}