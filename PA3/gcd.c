# include <stdio.h>
# include <stdlib.h>

int main()
{
	int i ;
	for(i = 1; i <1001 ;i++){
		if( i % 11 == 0 && i % 17 == 0){
			printf("%d\n",i);
		}
	}
	return 0;
}