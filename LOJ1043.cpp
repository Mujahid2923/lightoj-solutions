#include<bits/stdc++.h>
using namespace std;

double triangle(double ab,double ac,double bc,double Ratio)
{
    double low=0;
    double high=ab;
    double ad=0;
    while(high-low>.0000000001)
    {
        ad=(low+high)/2;
        double ae=ac*(ad/ab);
        double de=bc*(ad/ab);

        //area of ade
        double s=(ad+ae+de)/2.0;
        double ade=(sqrt(s*(s-ad)*(s-ae)*(s-de)));

        double bd=ab-ad;
        double ec=ac-ae;

        //area of bdec
        double c=(bc-de);
        double hs=(bd+ec+c)/2.0;
        double area=(sqrt(hs*(hs-bd)*(hs-ec)*(hs-c)));
        double h=(2*area)/c;
        double bdec=(.5*(de+bc)*h);


        if(ade/bdec<Ratio)
        {
            low=ad;
        }
        else
        {
            high=ad;
        }
    }

    return ad;
}


int main()
{

    int t;
    double ab,ac,bc,Ratio;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        cin>>ab>>ac>>bc>>Ratio;
        double ans=triangle(ab,ac,bc,Ratio);
        printf("Case %d: %.10f\n",i,ans);
    }
    return 0;
}
