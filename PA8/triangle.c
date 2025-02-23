//为二维空间中的点设计一个结构体，在此基础上为三角形设计一个结构体。分别设计独立的函数计算三角形的周长、面积、中心和重心。输入三个点，输出这三个点构成的三角形的周长、面积、外心和重心。结果保留小数点后2位数字。
# include <stdio.h>
# include <math.h>

typedef struct{
    double x;
    double y;
} Point;
Point* pointPointer_ ; 

// typedef struct {
//     double a_b;
//     double b_c;
//     double c_a;
// } Edgelength;
// Edgelength* edgelengthPointer_ ;

typedef struct{
    Point* a;
    Point* b;
    Point* c;
    //Edgelength edgelength;
} Triangle;
Triangle* trianglePointer_ ;

double distance(Point* a, Point* b){
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}//计算两点之间的距离

double circumference(Triangle* t){
    return distance(t->a, t->b) + distance(t->b, t->c) + distance(t->c, t->a);
}//计算周长

double area(Triangle* t){
    double p = circumference(t) / 2;
    return sqrt(p * (p - distance(t->a, t->b)) * (p - distance(t->b, t->c)) * (p - distance(t->c, t->a)));
}//得到三角形的面积，利用海伦公式


Point* createCircumcenter(Triangle *t){
    Point* circumcenter  = (Point*)malloc( sizeof(Point) );
    double A1 = 2*(t->b->x  - t->a->x);
    double B1 = 2*(t->b->y  - t->a->y);
    double C1 = pow(t->b->x , 2) + pow(t->b->y , 2) - pow(t->a->x , 2) - pow(t->a->y , 2);
    double A2 = 2*(t->c->x  - t->b->x);
    double B2 = 2*(t->c->y  - t->b->y);
    double C2 = pow(t->c->x , 2) + pow(t->c->y , 2) - pow(t->b->x , 2) - pow(t->b->y , 2);
    circumcenter->x = (C1 * B2 - C2 * B1) / (A1 * B2 - A2 * B1);
    circumcenter->y = (A1 * C2 - A2 * C1) / (A1 * B2 - A2 * B1);
    return circumcenter;
}//找到三角形的外心，利用外心公式

Point* creategravityPoint(Triangle* t){
    Point* gravityPoint = (Point*)malloc( sizeof(Point) );
    gravityPoint->x = (t->a->x + t->b->x + t->c->x) / 3;
    gravityPoint->y = (t->a->y + t->b->y + t->c->y) / 3;
    return gravityPoint;
}//找到三角形的重心，利用重心公式


void printTriangle(Triangle* t){
    printf("%.2lf\n", circumference(t));
    printf("%.2lf\n", area(t));
    Point* gravityPoint = creategravityPoint(t);
    Point* circumcenter = createCircumcenter(t);
    printf("%.2lf %.2lf\n", circumcenter->x, circumcenter->y);
    printf("%.2lf %.2lf\n", gravityPoint->x, gravityPoint->y);
}


int main(void){
    Point* first = (Point*)malloc( sizeof(Point));
    Point* second = (Point*)malloc( sizeof(Point));
    Point* third =  (Point*)malloc( sizeof(Point));
    Triangle* t = (Triangle*)malloc( sizeof(Triangle));
    scanf("%lf %lf %lf %lf %lf %lf",  &first->x, &first->y, &second->x, &second->y, &third->x, &third->y);
    t->a = first;
    t->b = second;
    t->c = third;
    printTriangle(t);
    free( first );
    free( second );
    free( third );
    free( t );
    return 0;

}

