#include<stdio.h>
#include<math.h>
int main()
{
    double a, b, c, d;
    scanf("%lf%lf%lf", &a, &b, &c);
    d=b*b-4*a*c;
    if (d<0) printf("Error");
    else if (d==0) printf("%.6lf", -b/(2*a));
    else printf("%.6lf\n%.6lf", -b/(2*a)+sqrt(d)/(2*fabs(a)), -b/(2*a)-sqrt(d)/(2*fabs(a)));
    return 0;
}
