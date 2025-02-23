# include <stdio.h>
double pi = 3.1415926536;

double S(double r){
	return(pi*(r*r));
}

double C(double r){
	return(4*pi*r*r);
}

double V(double r){
	return ((4.0/3.0)*pi*(r*r*r));
}

void main(void){
	double r;
	scanf("%lf",&r);
	printf("%-20.10lf%-20.10lf%-20.10lf",S(r),C(r),V(r));
}

