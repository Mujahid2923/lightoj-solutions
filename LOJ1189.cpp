///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               3.141592653589793238462643
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define        zero(a)             memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

vector<ull>v,vec,bit;
void check()
{
    ll val=1;
    int i=1;
    while(val<1e18)
    {
        v.pb(val);
        val*=i;
        i++;
    }
}

int main()
{
    ll t,n;
    check();

    cin>>t;
    for(int k=1; k<=t; k++)
    {
        scln(n);
        ll far=n;
        for(int i=v.size()-1; i>=0; i--)
        {
            if(v[i]<=n)
            {
                bit.pb(v[i]);
                n-=v[i];
            }
            if(n==1)
            {
                bit.pb(1);
                break;
            }
            else if(n<1)
            {
                break;
            }
        }
        int ck=0;
        ull sum=0;
        for(int i=0; i<bit.size(); i++)
        {
            sum+=bit[i];
            if(bit[i]==1)
                ck++;
        }
        if(ck>2 || sum!=far)
        {
            pf("Case %d: impossible\n",k);
        }
        else
        {
            reverse(bit.begin(),bit.end());
            pf("Case %d: ",k);
            int x=0;
            for(int i=0; i<bit.size(); i++)
            {
                for(int j=0; j<v.size(); j++)
                {
                    if(bit[i]==v[j])
                    {
                        if(i==0)
                        {
                            cout<<j<<"!";
                        }
                        else
                        {
                            if(j==0 && x==1)
                            {
                                cout<<"+"<<j+1<<"!";
                            }
                            else
                            {
                                cout<<"+"<<j<<"!";
                            }

                        }
                        if(j==0)
                        {
                            x=1;
                        }
                        break;
                    }
                }
            }
            cout<<endl;
        }
        bit.clear();
    }

    return 0;
}


