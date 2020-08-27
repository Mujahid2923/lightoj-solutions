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
#define          siz                    30005
///--------------------**********----------------------------------

vector < int > v, v1, v2, v3, v4 ;
vector < pair < ll, pll > > vec ;
vector < int > adj[ siz ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int n, x, y, z, cnt, q, L, T ;
int A[ siz ], arr[ 2 * siz ], Tree[ 4 * siz ],start[ siz ], finish[ siz ], level[ siz ],P[ siz ][ 20 ] ;
void Reset()
{
    cnt = 0 ;
    zero( A ) ;
    zero( arr ) ;
    zero( Tree ) ;
    zero( start ) ;
    zero( finish ) ;
    zero( level ) ;
    zero( P ) ;
    for( int i = 1 ; i <= n ; i ++ ) adj[ i ].clear() ;
}

void Input()
{
    scanf( "%d", &n ) ;
    L = ceil( log2( n ) ) ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        scanf( "%d", &A[ i ] ) ;
    }
    for( int i = 1 ; i < n ; i ++ )
    {
        scanf( "%d %d", &x, &y ) ;
        ++ x, ++ y ;
        adj[ x ].pb( y ) ;
        adj[ y ].pb( x ) ;
    }
}

void dfs( int u, int p, int lev )
{
    level[ u ] = lev ;
    for( int i = 1 ; i <= L ; i ++ ) P[ u ][ i ] = P[ P[ u ][ i - 1 ] ][ i - 1 ] ;
    start[ u ] = ++ cnt ;
    arr[ cnt ] = A[ u ] ;
    for( auto v : adj[ u ] ) if( v != p ) P[ v ][ 0 ] = u, dfs( v, u, lev + 1 ) ;
    finish[ u ] = ++ cnt ;
    arr[ cnt ] = -A[ u ] ;
}

void init( int node, int b, int e )
{
    if( b == e )
    {
        Tree[ node ] = arr[ b ] ;
        return ;
    }
    segment_tree ;
    init( Lnode, b, mid ) ;
    init( Rnode, mid + 1, e ) ;
    Tree[ node ] = Tree[ Lnode ] + Tree[ Rnode ] ;
}

void update( int node, int b, int e, int i, int newvalue )
{
    if( i > e || i < b ) return ;
    if( b >= i && e <= i )
    {
        Tree[ node ] = newvalue ;
        return ;
    }

    segment_tree ;
    update( Lnode, b, mid, i, newvalue ) ;
    update( Rnode, mid + 1, e, i, newvalue ) ;
    Tree[ node ] = Tree[ Lnode ] + Tree[ Rnode ] ;
}

int query( int node, int b, int e, int i, int j )
{
    if( b > j || e < i ) return 0 ;
    if( b >= i && e <= j ) return Tree[ node ] ;
    segment_tree ;
    return query( Lnode, b, mid, i, j ) + query( Rnode, mid + 1, e, i, j ) ;
}

int up( int x, int step )
{
    for( int i = 0 ; i <= L ; i ++ ) if( step & ( 1 << i ) ) x = P[ x ][ i ] ;
    return x ;
}

int lca( int a, int b )
{
    if( level[ a ] < level[ b ] ) swap( a, b ) ;
    a = up( a, level[ a ] - level[ b ] ) ;
    if( a == b ) return a ;
    for( int i = L ; i >= 0 ; i -- )
    {
        if( P[ a ][ i ] != P[ b ][ i ] )
        {
            a = P[ a ][ i ] ;
            b = P[ b ][ i ] ;
        }
    }
    return P[ a ][ 0 ] ;
}

void Calculation()
{
    printf( "Case %d:\n", ++ T ) ;
    dfs( 1, -1, 0 ) ;
    init( 1, 1, cnt ) ;
    scanf( "%d", &q ) ;
    while( q-- )
    {
        scanf( "%d %d %d", &x, &y, &z ) ;
        if( x )
        {
            ++ y ;
            update( 1, 1, cnt, start[ y ], z ) ;
            update( 1, 1, cnt, finish[ y ], -z ) ;
            A[ y ] = z ;
        }
        else
        {
            ++ y, ++ z ;
            int par = lca( y, z ) ;
            int ans = query( 1, 1, cnt, start[ par ], start[ y ] ) + query( 1, 1, cnt, start[ par ], start[ z ] ) - A[ par ] ;
            printf( "%d\n", ans ) ;
        }
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
    scanf( "%d", &t ) ;
    while( t-- ) solve() ;
    return 0 ;
}
