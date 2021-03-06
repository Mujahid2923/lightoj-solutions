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
#define          output                 freopen("output.txt","wt", stdout)
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

///--------------------**********----------------------------------

vector < ll > v, v1, v2, v3, v4 ;
vector < pii > vec ;
vector < int > adj[ 1005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < int > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;
deque < ll > A ;

///---------------------**********--------------------------------

int n, m, x, y, test ;
int dp[ 1005 ][ 5 ] , visited[ 1005 ] ;

void Reset()
{
    for( int i = 1 ; i <= n ; i ++ )
    {
        adj[ i ].clear() ;
        visited[ i ] = 0 ;
    }
}

void Input()
{
    scanf( "%d %d", &n, &m ) ;
    for( int i = 1 ; i <= m ; i ++ )
    {
        scanf( "%d %d", &x, &y ) ;
        adj[ x ].pb( y ) ;
        adj[ y ].pb( x ) ;
    }
}

int dfs( int node, int par, int ck )
{
    v.pb( node ) ;
    visited[ node ] = 1 ;
    if( dp[ node ][ ck ] != -1 ) return dp[ node ][ ck ] ;

    int res = ck ;
    for( auto v : adj[ node ] )
    {
        if( v != par )
        {
            if( ck ) res += dfs( v, node, 0 ) ;
            else res += max( dfs( v, node, 1 ), dfs( v, node, 0 ) ) ;
        }
    }

    return dp[ node ][ ck ] = res ;
}


void Calculation()
{
    int ans = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        if( !visited[ i ] )
        {
            memset( dp, -1, sizeof dp ) ;
            int a = dfs( i, -1, 1 ) ;
            memset( dp, -1, sizeof dp ) ;
            int b = dfs( i, -1, 0 ) ;
            ans += max( a, b ) ;
        }
    }
    printf( "Case %d: %d\n", ++test, ans ) ;
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

*****************************------------------------------------ bpm -----------------------------------------------******************************

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
#define          output                 freopen("output.txt","wt", stdout)
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

///--------------------**********----------------------------------

vector < ll > v, v1, v2, v3, v4 ;
vector < pii > vec ;
vector < int > adj[ 1005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < int > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;
deque < ll > A ;

///---------------------**********--------------------------------

int n, m, x, y, test ;
int match[ 1005 ] ;

void Reset()
{
    for( int i = 1 ; i <= 1000 ; i ++ )
    {
        adj[ i ].clear() ;
        match[ i ] = -1 ;
    }
}

void Input()
{
    scanf( "%d %d", &n, &m ) ;
    for( int i = 1 ; i <= m ; i ++ )
    {
        scanf( "%d %d", &x, &y ) ;
        adj[ x ].pb( y ) ;
        adj[ y ].pb( x ) ;
    }
}

int dfs( int u, int p )
{
    for( auto v : adj[ u ] )
    {
        if( v != p )
        {
            if( match[ v ] == -1 || dfs( match[ v ], v ) )
            {
                match[ v ] = u ;
                match[ u ] = v ;
                return 1 ;
            }
        }
    }
    return 0 ;
}

int bpm()
{
    int cnt = 0 ;
    for( int i = 1 ; i <= n ; i ++ ) if( match[ i ] != -1 || !dfs( i, -1 ) ) cnt ++ ;
    return cnt ;
}

void Calculation()
{
    printf( "Case %d: %d\n", ++ test, bpm() ) ;
    for( int i = 1 ; i <= n ; i ++ ) cout << i << " " << match[ i ] << endl ;
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

/*
 
 
Firstly bi-colored all nodes using a simple dfs. After that all red nodes is on left side
and all black nodes on the right side. Now made connection between nodes according to given edge.
Result is: N - bpm.
 
 
Why it works?
-------------
 
We need to find maximum set which are not connected at all. 
As we calculated bpm, it's maximum flow that can run through this network.
 
Now, we know max-flow = min-cut.
Here in bipartite graph, min-cut will be applied only on the edges like source->node or node->sink (can be proven
by greedy choice).
Thus, min-cut means: minimum number of node to be deleted to make this graph disconnected, i.e, no flow will
pass through this network after removing those node.
 
so, (N - bpm) is maximum set size which are not connected by any edge. That's the answer.
 
*/
 
