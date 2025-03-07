# include <stdio.h>
# include <stdlib.h>


int max (int a, int b)
{
	if(a >= b){
		return ;
	}else{
		return b;
	}
}
void lcm(int a, int b)
{
	int m;
	for(int i = max (a,b); i < a*b+1 ; i++){
		if ( i%a == 0 && i%b == 0){
			printf("%d",i);
			break;
		}
	}
}
int main(){
	int a, b;
	scanf("%d %d",&a, &b);
	lcm(a,b);
	return 0;
}