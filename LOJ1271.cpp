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
#define          siz                    50005

///--------------------**********----------------------------------

vector < int > v, v1, v2, v3, v4 ;
vector < pll > vec ;
vector < int > adj[ siz ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int n, x, y, test ;
int parent[ siz ] ;
int visited[ siz ] ;


void Reset()
{
    for( int i = 0 ; i < siz ; i ++ ) adj[ i ].clear() ;
    v1.clear() ;
    v2.clear() ;
    zero( parent ) ;
    zero( visited ) ;
}

void Input()
{
    cin >> n ;
    for( int i = 0 ; i < n ; i ++ )
    {
        scanf( "%d", &x ) ;
        v1.pb( x ) ;
    }
    for( int i = 0 ; i < n - 1 ; i ++ )
    {
        adj[ v1[ i ] ].pb( v1[ i + 1 ] ) ;
        adj[ v1[ i + 1 ] ].pb( v1[ i ] ) ;
    }
}

void bfs( int s )
{
    visited[ s ] = 1 ;
    parent[ s ] = -1 ;
    queue < int > Q ;
    Q.push( s ) ;
    while( !Q.empty() )
    {
        int u = Q.front() ;
        Q.pop() ;

        for( auto v : adj[ u ] )
        {
            if( !visited[ v ] )
            {
                visited[ v ] = 1 ;
                parent[ v ] = u ;
                if( v == v1[ n - 1 ] ) return ;
                Q.push( v ) ;
            }
        }
    }
}

void Calculation()
{
    pf( "Case %d:\n", ++test ) ;
    for( int i = 1 ; i <= siz ; i ++ ) sort( all( adj[ i ] ) ) ;
    bfs( v1[ 0 ] ) ;
    for( int i = v1[ n - 1 ] ; i != -1 ; i = parent[ i ] ) v2.pb( i ) ;
    reverse( all( v2 ) ) ;
    for( int i = 0 ; i < v2.size() ; i ++ )
    {
        if( i == v2.size() - 1 ) pf( "%d\n", v2[ i ] ) ;
        else pf( "%d ", v2[ i ] ) ;
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
    while( t-- )
    {
        solve() ;
    }
    return 0 ;
}



