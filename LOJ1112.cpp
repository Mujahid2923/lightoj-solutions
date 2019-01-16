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

#define MAX 100000
ll tree[MAX*4];

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

    tree[node]=tree[Lnode]+tree[Rnode];
}

ll donateAll(ll node,ll b,ll e,ll i)
{
    if(b > i || e < i)
    {
        return 0;
    }

    if(b>=i && e<=i)
    {
        return tree[node];
    }

    ll Lnode=node*2;
    ll Rnode=node*2+1;
    ll mid=(b+e)/2;

    ll d1=donateAll(Lnode,b,mid,i);
    ll d2=donateAll(Rnode,mid+1,e,i);
    return d1+d2;
}

void update(ll node,ll b,ll e,ll i,ll v)
{
    if(i>e || i<b)
    {
        return;
    }

    if(b>=i && e<=i)
    {
        tree[node]=tree[node]+v;
        return;
    }
    ll Lnode=node*2;
    ll Rnode=node*2+1;
    ll mid=(b+e)/2;
    update(Lnode,b,mid,i,v);
    update(Rnode,mid+1,e,i,v);
    tree[node]=tree[Lnode]+tree[Rnode];
}

void update2(ll node,ll b,ll e,ll i)
{
    if(i>e || i<b)
    {
        return;
    }

    if(b>=i && e<=i)
    {
        tree[node]=0;
        return;
    }
    ll Lnode=node*2;
    ll Rnode=node*2+1;
    ll mid=(b+e)/2;
    update2(Lnode,b,mid,i);
    update2(Rnode,mid+1,e,i);
    tree[node]=tree[Lnode]+tree[Rnode];
}

ll sum(ll node,ll b,ll e,ll i,ll j)
{
    if(j<b || i>e)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    ll Lnode=node*2;
    ll Rnode=node*2+1;
    ll mid=(b+e)/2;

    ll s1=sum(Lnode,b,mid,i,j);
    ll s2=sum(Rnode,mid+1,e,i,j);
    return s1+s2;
}

int main()
{
    ll t,n,q,ck,a,v,b;
    scanf("%lld",&t);
    for(ll k=1; k<=t; k++)
    {
        scanf("%lld %lld",&n,&q);
        ll arr[n+10];
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&arr[i]);
        }
        init(arr,1,1,n);
        printf("Case %lld:\n",k);
        for(ll i=0; i<q; i++)
        {
            scanf("%lld",&ck);
            if(ck==1)
            {
                scanf("%lld",&a);
                ll ans=donateAll(1,1,n,a+1);
                printf("%lld\n",ans);
                update2(1,1,n,a+1);
            }
            else if(ck==2)
            {
                scanf("%lld %lld",&a,&v);
                update(1,1,n,a+1,v);

            }
            else
            {
                scanf("%lld %lld",&a,&b);
                ll ans=sum(1,1,n,a+1,b+1);
                printf("%lld\n",ans);
            }
        }
        memset(arr,0,sizeof arr);
        memset(tree,0,sizeof tree);
    }
    return 0;
}
