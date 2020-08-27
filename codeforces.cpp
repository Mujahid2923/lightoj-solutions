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

int n, m, x, y, z, L, q, T ;
int level[ sz ] ,arr[ sz ][ 20 ], val[ sz ] ;

void Reset()
{
    zero( level ) ;
    zero( arr ) ;
    zero( val ) ;
    for( int i = 1 ; i <= n ; i ++ ) adj[ i ].clear() ;
}

void Input()
{
    scanf( "%d %d", &n, &q ) ;
    L = ceil( log2( n ) ) ;
    val[ 1 ] = 1 ;
    for( int i = 2 ; i <= n ; i ++ )
    {
        scanf( "%d %d", &x, &val[ i ] ) ;
        ++ x ;
        adj[ x ].pb( i ) ;
        adj[ i ].pb( x ) ;
    }
}


void dfs( int u, int p )
{
    arr[ u ][ 0 ] = p ;
    level[ u ] = level[ p ] + 1 ;
    for( int i = 1 ; i <= L ; i ++ ) arr[ u ][ i ] = arr[ arr[ u ][ i - 1 ] ][ i - 1 ] ;
    for( auto v : adj[ u ] ) if( v != p ) dfs( v, u ) ;
}

int lca( int x, int y )
{
    for( int i = L ; i >= 0 ; i -- ) if( val[ arr[ x ][ i ] ] >= y ) x = arr[ x ][ i ] ;
    return x ;
}


void Calculation()
{
    printf( "Case %d:\n", T ) ;
    dfs( 1, 0 ) ;
    while( q-- )
    {
        scanf( "%d %d", &x, &y ) ;
        ++ x ;
        printf( "%d\n",lca( x, y ) - 1 ) ;
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
