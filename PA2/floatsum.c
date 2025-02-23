# include <stdio.h>

float money(float a,float b){
	return a+(a*b*0.0095);
}
void main(void){
    float a,b;
	scanf("%f %f",&a,&b);
	printf("%.2f", money(a,b));
}