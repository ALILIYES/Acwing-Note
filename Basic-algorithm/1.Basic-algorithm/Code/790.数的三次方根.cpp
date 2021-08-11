#include<iostream>
#include<cmath>
using namespace std;
double n;
double threetime(double l, double r)
{
    // eps 表示精度，取决于题目对精度的要求
    while (abs(r-l)>= 1e-7){
        double mid = (l + r) / 2;
        if (mid*mid*mid>n) r = mid;
        else l = mid;
    }
    return l;
}
int main(){
    scanf("%lf",&n);
    printf("%lf",threetime(-10000,10000));
}