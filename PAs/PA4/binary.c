# include <stdio.h>
int binery(int n){
    static int i  = 0;
    i++;
	if(n == 0 || n == 1){
		return i;
	}else {
        return (binery(n/2));
	}
}
int main(){
	int a;
	scanf("%d",&a);
	printf("%d",binery(a));
	return 0;
}