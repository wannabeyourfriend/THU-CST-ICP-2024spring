#include <stdio.h>

int pow(int n, int m){
	int power = 1;
	for(int i =1; i<= m ;i++){
		power = n*power;
	}
	return power;
}


void print_power_sequence(int n, int m) {
    static int count = 0;
    
    for (int i = 1; i <= m; i++) {
        printf("%12d", pow(n, i));
        count++;
        
        if (count % 5 == 0) {
            printf("\n");
        }
    }
}

int main() {
    int n, m;
	scanf("%d %d", &n, &m);
    print_power_sequence(n, m);
    
    return 0;
}
