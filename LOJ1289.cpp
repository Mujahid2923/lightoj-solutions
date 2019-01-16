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

const int MAXN = 1e8 + 3;
const int SZ = 5761455 + 3;

bitset<MAXN> status;
int primes[SZ];
unsigned memo[SZ];

int primeCnt = 0;

void sieve()
{
    int n = 1e4;

    for(int i = 3; i < n; i+=2)
    {
        if(!status[i])
        {
            for(int j = i*i; j < MAXN; j+=(i<<1))
            {
                status[j] = true;
            }
        }
    }

    primes[primeCnt++] = 2;

    for(int i = 3; i < MAXN; i+=2)
    {
        if(!status[i])
        {
            primes[primeCnt++] = i;
        }
    }
}

unsigned solve(int n)
{
    unsigned ans=1;
    int x=sqrt(n);
    for(int i=0; primes[i]<=x; i++)
    {
        int cnt=n/primes[i];
        while(cnt>=primes[i])
        {
            ans*=primes[i];
            cnt/=primes[i];
        }
    }

    ans *= memo[upper_bound(primes, primes+primeCnt, n) - primes - 1];
    return ans;
}

int main()
{
    sieve();
    memo[0]=2;
    for(int i=1; i<primeCnt; i++)
    {
        memo[i]=memo[i-1]*primes[i];
    }
    int t;
    scin(t);

    for(int i = 1; i <= t; ++i)
    {
        int n;
        scin(n);
        printf("Case %d: %u\n", i, solve(n));
    }

    return 0;
}
