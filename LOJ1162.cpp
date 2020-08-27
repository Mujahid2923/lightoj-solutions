#include<bits/stdc++.h>
using namespace std;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          output                 freopen("output.txt","wt", stdout)
#define          ld                     long double
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          pf                     printf
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          PI                     acos(-1.0)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Min(v)                 *min_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;
#define          segment_tree           int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;
#define          sz                     100005
///--------------------**********----------------------------------

vector < ll > v, v1, v2, v3, v4 ;
vector < pair < ll, pll > > vec ;
vector < ll > adj[ sz ],cost[ sz ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int n, m, x, y, z, L, ans1 = INT_MAX, ans2 = 0, q, T ;
int level[ sz ] ,P[ sz ][ 20 ] ,mnE[ sz ][ 20 ], mxE[ sz ][ 20 ] ;

void Reset()
{
    zero( level ) ;
    zero( P ) ;
    zero( mnE ) ;
    zero( mxE ) ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        adj[ i ].clear() ;
        cost[ i ].clear() ;
    }
}

void Input()
{
    cin >> n ;
    L = ceil( log2( n ) ) ;
    for( int i = 1 ; i < n ; i ++ )
    {
        scanf( "%d %d %d", &x, &y, &z ) ;
        adj[ x ].pb( y ) ;
        adj[ y ].pb( x ) ;
        cost[ x ].pb( z ) ;
        cost[ y ].pb( z ) ;
    }
}


void dfs( int u, int p )
{
    P[ u ][ 0 ] = p ;
    level[ u ] = level[ p ] + 1 ;
    for( int i = 1 ; i <= L ; i ++ )
    {
        P[ u ][ i ] = P[ P[ u ][ i - 1 ] ][ i - 1 ] ;
        mnE[ u ][ i ] = min( mnE[ u ][ i - 1 ], mnE[ P[ u ][ i - 1 ] ][ i - 1 ] ) ;
        mxE[ u ][ i ] = max( mxE[ u ][ i - 1 ], mxE[ P[ u ][ i - 1 ] ][ i - 1 ] ) ;
    }
    for( int i = 0 ; i < adj[ u ].size() ; i ++ )
    {
        int v = adj[ u ][ i ] ;
        if( v != p )
        {
            mnE[ v ][ 0 ] = cost[ u ][ i ] ;
            mxE[ v ][ 0 ] = cost[ u ][ i ] ;
            dfs( v, u ) ;
        }
    }
}

int up( int x, int step )
{
    for( int i = 0 ; i <= L ; i ++ )
    {
        if( step & ( 1 << i ) )
        {
            ans1 = min( ans1 , mnE[ x ][ i ] ) ;
            ans2 = max( ans2 , mxE[ x ][ i ] ) ;
            x = P[ x ][ i ] ;
        }
    }
    return x ;
}

void lca( int p, int q )
{
    if( level[ p ] < level[ q ] ) swap( p, q ) ;
    p = up( p, level[ p ] - level[ q ] ) ;

    if( p == q ) return ;

    for( int i = L ; i >= 0 ; i -- )
    {
        if( P[ p ][ i ] != P[ q ][ i ] )
        {
            ans1 = min( { ans1 , mnE[ p ][ i ], mnE[ q ][ i ] } ) ;
            ans2 = max( { ans2 , mxE[ p ][ i ], mxE[ q ][ i ] } ) ;
            p = P[ p ][ i ], q = P[ q ][ i ] ;

        }
    }

    ans1 = min( { ans1 , mnE[ p ][ 0 ], mnE[ q ][ 0 ] } ) ;
    ans2 = max( { ans2 , mxE[ p ][ 0 ], mxE[ q ][ 0 ] } ) ;
    return ;
}


void Calculation()
{
    printf( "Case %d:\n", T ) ;
    dfs( 1, 0 ) ;
    cin >> q ;
    while( q-- )
    {
        ans1 = INT_MAX, ans2 = 0 ;
        scanf( "%d %d", &x, &y ) ;
        lca( x, y ) ;
        printf( "%d %d\n", ans1, ans2 ) ;
    }
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    int t ;
    cin >> t ;
    //t = 1 ;
    while( t-- )
    {
        T ++ ;
        solve() ;
    }
    return 0 ;
}

