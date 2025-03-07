
# include <stdio.h>
int main(void){
	double income;
	double money;
	scanf("%lf",&income);
	if (income <= 100000.0){
		money = income*0.10;
        goto result;
	}else if(income <= 200000.0){
		money = 10000.0 + (income-100000.0)*0.075;
        goto result;
	}else if(income <= 400000.0){
		money = 10000.0 + (200000.0-100000.0)*0.075 + (income - 200000.0)*0.05;
        goto result;
	}else if(income <= 600000.0){
		money = 10000.0 + (200000.0-100000.0)*0.075 + (400000.0 - 200000.0)*0.05 + (income - 400000.0)*0.03;
        goto result;
	}else if(income <= 1000000.0){
		money = 10000.0 + (200000.0-100000.0)*0.075 + (400000.0 - 200000.0)*0.05 + (600000 - 400000.0)*0.03 +(income -600000.0)*0.015;
        goto result;
	}else {
		money = 10000.0 + (200000.0-100000.0)*0.075 + (400000.0 - 200000.0)*0.05 + (600000 - 400000.0)*0.03 +(1000000.0 -600000.0)*0.015 + (income - 1000000.0)*0.01;
        goto result;
	}
result:
	printf("%6lf\n",money);
	return 0;

}