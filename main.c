#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"


//变步长梯形积分算法
int main()
{
    double eps=1e-7; //精度
    double a,b; //积分上下限
    printf("积分区间: ");scanf("%lf,%lf",&a,&b);
    double h=b-a,Tn,T2n; //高，二分前积分结果，递推积分结果
    int n=1;
    int done=0;
    //开始计算Func1在区间a,b的积分
    //计算n=1时的积分值
    Tn=(Func1(a)+Func1(b))*h/2.0;
    while(!done)
    {
        double temp=0.0;
        for(int k=0;k<n;k++)
        {
            double x=a+(k+0.5)*h;
            temp+=Func1(x);
        }
        T2n=(Tn+h*temp)/2.0;
        if(fabs(T2n-Tn)<eps)
        {
            done=1;
        }
        else
        {
            Tn=T2n;
            n*=2;
            h/=2;
        }
    }
    printf("积分结果:%.8f",T2n);


    return 0;
}




