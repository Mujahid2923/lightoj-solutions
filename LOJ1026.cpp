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
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define     all( v )               v.begin() , v.end()
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

vector < int > adj[ 10005 ] ;
int disc[ 10005 ] ;
int low[ 10005 ] ;
int Time = 0 ;
vector < pii > vec ;

void dfs( int u, int p )
{
    disc[ u ] = low[ u ] = ++ Time ;

    for( auto v : adj[ u ] )
    {
        if( v == p )
            continue ;

        if( !disc[ v ] )
        {
            dfs( v, u ) ;
            if( disc[ u ] < low[ v ] )
            {
                if( u > v )
                {
                    vec.pb( { v, u } ) ;
                }
                else
                {
                    vec.pb( { u, v } ) ;
                }
            }
            low[ u ] = min( low[ u ], low[ v ] ) ;
        }
        else
        {
            low[ u ] = min( low[ u ], disc[ v ] ) ;
        }
    }
}

int main()
{
    int t, n, idx, m, l ;
    char c1, c2 ;
    cin >> t ;
    for( int k = 1 ; k <= t ; k ++ )
    {
        cin >> n ;
        for( int i = 0 ; i < n ; i ++ )
        {
            cin >> idx >> c1 >> m >> c2 ;
            for( int j = 0 ; j < m ; j ++ )
            {
                cin >> l ;
                adj[ idx ].pb( l ) ;
                adj[ l ].pb( idx ) ;
            }
        }

        for( int i = 0 ; i < n ; i ++ )
        {
            if( !disc[ i ] )
            {
                dfs( i, i ) ;
            }
        }
        sort( all( vec ) ) ;
        pf( "Case %d:\n", k ) ;
        pf( "%d critical links\n", vec.size() ) ;
        for( auto x : vec )
        {
            pf( "%d - %d\n", x.first, x.second ) ;
        }
        zero( disc ) ;
        zero( low ) ;
        vec.clear() ;
        Time = 0 ;
        for( int i = 0 ; i < n ; i ++ )
        {
            adj[ i ].clear() ;
        }
    }

    return 0;
}

