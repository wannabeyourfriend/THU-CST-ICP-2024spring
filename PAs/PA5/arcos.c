# include <stdio.h>
# include <math.h>
# define _PI_ 3.1415926

double solve_arccos(double x){
    double left = 0.0, right = _PI_;
    double mid;
    while(right - left > 1e-8){
        mid = (left + right) / 2.0;
        if(cos(mid) < x){
            right = mid;
        }else if(cos(mid) > x){
            left = mid;
        }else{
            return mid;
        }
    }
    return mid;
}

int main(){
    double x;
    scanf("%lf", &x);
    double arccos_x = _PI_/2.0;
    double temp;
    if(fabs(cos( arccos_x ) - x) > 1e-8){
        printf( "%.5lf\n", solve_arccos(x));
    }
    if(fabs(cos( arccos_x ) - x) < 1e-8){
        printf("%.5lf\n", arccos_x);
    }
    return 0;
}