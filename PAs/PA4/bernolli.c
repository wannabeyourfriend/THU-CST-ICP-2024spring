# include <stdio.h>

int binerpower(int k, int n){
	if(k == 0 || k== n){
		return 1;
	}else{
		return( binerpower(k, n-1) +binerpower(k-1,n-1));
	}
}

int main(void){
	int a, b;
	scanf("%d %d",&a,&b);
	printf("%d",binerpower(a,b));
}