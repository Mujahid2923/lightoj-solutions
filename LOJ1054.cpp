#include<bits/stdc++.h>

///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

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
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

vector<ll>v;
const int MAXN = 60000;

bitset<MAXN> status;


void sieve()
{
    int n = 6*1e4;
    int sq=sqrt(n);

    for(int i = 3; i <= sq; i+=2)
    {
        if(!status[i])
        {
            for(int j = i*i; j <= n; j+=(i<<1))
            {
                status[j] = true;
            }
        }
    }

    v.push_back(2);

    for(int i = 3; i <= n; i+=2)
    {
        if(!status[i])
        {
            v.push_back(i);
        }
    }
}


ll power(ll N, ll P)
{
    if(P==0)
        return 1;
    if(P%2==0)
    {
        ll divisor=power(N,P/2);
        return ((divisor%MOD)*(divisor%MOD))%MOD;
    }
    else
    {
        return ((N%MOD)*power(N,P-1)%MOD)%MOD;
    }
}


ll Find(ll n, ll m)
{
    ll i, l=0, divisor=1;
    for(i=0; v[i]<=sqrt(n); i++)
    {
        l=0;
        if(n%v[i]==0)
        {
            while(n%v[i]==0)
            {
                n=n/v[i];
                l++;
            }
            l=(l*m)+1;
            divisor=(divisor*(power(v[i],l)-1))%MOD;
            divisor=(divisor*(power(v[i]-1,MOD-2)))%MOD;
        }
    }
    if(n>1)
    {
        divisor=(divisor*(power(n,m+1)-1))%MOD;
        divisor=(divisor*(power(n-1,MOD-2)))%MOD;
    }
    return divisor;
}



int main()
{
    //output;
    sieve();
    ll i,t,a,b;
    ll ans;
    scln(t);
    RUN_CASE(i,t)
    {
        scln2(a,b);
        if(a%MOD==0)
        {
            ans=1;
        }
        else
        {
            ans=Find(a,b);
        }
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}

///same solution:
///https://paste.ubuntu.com/p/dgFwJkGrV8/
