# include <stdio.h>

# define _PI_ (3.1415926)
# define _V_(r)  (4.0*r*r*r/3.0)

int main(){
	double r;
	scanf("%lf",&r);
	double v = _PI_*_V_(r);
	printf("%.5lf",v);
	return 0;
}
