#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,a,b,c;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
       cin>>a>>b>>c;
       int x=a*a+b*b;
       int y=c*c;
       if(a*a+b*b==c*c)
       {
           cout<<"Case "<<i<<": yes"<<endl;
       }
       else if(b*b+c*c==a*a)
       {
           cout<<"Case "<<i<<": yes"<<endl;
       }
       else if(c*c+a*a==b*b)
       {
           cout<<"Case "<<i<<": yes"<<endl;
       }
       else
       {
           cout<<"Case "<<i<<": no"<<endl;
       }

    }
    return 0;
}
