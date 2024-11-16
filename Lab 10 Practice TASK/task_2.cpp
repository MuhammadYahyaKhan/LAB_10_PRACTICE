#include<stdio.h>


void calc(int l,int freq1,int freq2,int freq3){
	if(l >= 3){
		calc(l-3,freq1,freq2,freq3 + 1);
	}else if(l < 3 and l == 2){
		
		calc(l-2,freq1,freq2 + 1,freq3);
	}else if(l < 3 and l == 1){
		
		calc(l-1,freq1 + 1,freq2,freq3);
	}else if(l == 0){
		
		printf("freq1 = %d\nfreq2 = %d\nfreq3 = %d\n",freq1,freq2,freq3);
	}
}
int main(){
	int l; printf("Enter the length of rope : "); scanf("%d",&l);
	int freq1 = 0; 
	int freq2 = 0; 
	int freq3 = 0; 
	calc(l,freq1,freq2,freq3);
	return 0;
}