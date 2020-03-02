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

#define mx 100005
ll Tree[ mx * 4 ];
ll arr[ mx ];

void init( int node, int b, int e )
{
    int Lnode = node << 1 ;
    int Rnode= Lnode + 1 ;
    int mid = ( b + e ) >> 1 ;

    if( b == e )
    {
        Tree[ node ] = arr[ b ] ;
        return;
    }


    init( Lnode, b, mid ) ;
    init( Rnode, mid + 1, e ) ;
    Tree[ node ] = min( Tree[ Lnode ],Tree[ Rnode ] ) ;
}

int Findmin(int node,int b,int e,int i,int j)
{
    int Lnode = node << 1 ;
    int Rnode= Lnode + 1 ;
    int mid = ( b + e ) >> 1 ;

    if( i > e || j < b )
    {
        return INT_MAX ;
    }
    if( b >= i && e <= j )
    {
        return Tree[ node ] ;
    }

    int m1 = Findmin( Lnode, b, mid, i, j ) ;
    int m2 = Findmin( Rnode, mid + 1, e, i, j ) ;
    return min(m1,m2);
}

int main()
{
    int t, n, q, a, b ;
    scin( t ) ;
    for( int j = 1 ; j <= t ; j ++ )
    {
        scin2( n, q ) ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            scin( arr[ i ] ) ;
        }
        init( 1, 1, n ) ;
        printf( "Case %d:\n", j ) ;
        for(int i=1; i<=q; i++)
        {
            scin2( a, b ) ;
            int mn = Findmin( 1, 1, n, a, b ) ;
            printf( "%d\n", mn ) ;
        }
    }
    return 0;
}
