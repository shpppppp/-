#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"


//�䲽�����λ����㷨
int main()
{
    double eps=1e-7; //����
    double a,b; //����������
    printf("��������: ");scanf("%lf,%lf",&a,&b);
    double h=b-a,Tn,T2n; //�ߣ�����ǰ���ֽ�������ƻ��ֽ��
    int n=1;
    int done=0;
    //��ʼ����Func1������a,b�Ļ���
    //����n=1ʱ�Ļ���ֵ
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
    printf("���ֽ��:%.8f",T2n);


    return 0;
}




