# include <stdio.h>

int main(){
	int number; 
	scanf("%d", &number);
	int i;
	int j;
	for(i = 1; i < number+1 ; i++){
		for(j = 1; j < 2*number ; j++ ){
			if( j > number -i && j < number + i){
				printf("%c",'*');
			}else{
				printf("%s", " ");
			}
		}
		printf("\n");
	}
	return 0;
}
