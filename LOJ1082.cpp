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

#define MAX 500000
ll tree[MAX*3];

void init(ll *arr,ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    ll Lnode=node*2;
    ll Rnode=node*2+1;
    ll mid=(b+e)/2;
    init(arr,Lnode,b,mid);
    init(arr,Rnode,mid+1,e);
    tree[node]=min(tree[Lnode],tree[Rnode]);
}

int findmin(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)
    {
        return INT_MAX;
    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    ll Lnode=node*2;
    ll Rnode=node*2+1;
    ll mid=(b+e)/2;
    ll m1=findmin(Lnode,b,mid,i,j);
    ll m2=findmin(Rnode,mid+1,e,i,j);
    return min(m1,m2);
}

int main()
{
    ll t,n,q,a,b;
    scanf("%lld",&t);
    for(ll j=1; j<=t; j++)
    {
        scanf("%lld %lld",&n,&q);
        ll arr[n+1];
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&arr[i]);
        }
        init(arr,1,1,n);
        printf("Case %lld:\n",j);
        for(ll i=1; i<=q; i++)
        {
            scanf("%lld %lld",&a,&b);
            ll mn=findmin(1,1,n,a,b);
            printf("%lld\n",mn);
        }
    }
    return 0;
}
