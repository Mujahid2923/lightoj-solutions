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
vector < pii > vec ;
vector < int > adj[ 10005 ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int n, idx, m, x, test, cnt ;
int dist[ 10005 ],low[ 10005 ] ;

void Reset()
{
    zero( dist ) ;
    zero( low ) ;
    vec.clear() ;
    cnt = 0 ;
    for( int i = 0 ; i < n ; i ++ )  adj[ i ].clear() ;
}


void Input()
{
    char ch1, ch2 ;
    scanf( "%d", &n ) ;
    for( int i = 0 ; i < n ; i ++ )
    {
        scanf( "%d %c %d %c", &idx, &ch1, &m, &ch2 ) ;
        for( int j = 0 ; j < m ; j ++ )
        {
            scanf( "%d", &x ) ;
            adj[ idx ].pb( x ) ;
            adj[ x ].pb( idx ) ;
        }
    }
}

void dfs( int u, int p )
{
    dist[ u ] = low[ u ] = ++ cnt ;

    for( auto v : adj[ u ] )
    {
        if( v != p )
        {
            if( !dist[ v ] )
            {
                dfs( v, u ) ;
                if( dist[ u ] < low[ v ] ) vec.pb( { min( u, v ), max( u, v ) } ) ;
                low[ u ] = min( low[ u ], low[ v ] ) ;
            }
            else low[ u ] = min( low[ u ], dist[ v ] ) ;
        }
    }
}

void Calculation()
{
    for( int i = 0 ; i < n ; i ++ ) if( !dist[ i ] ) dfs( i, i ) ;

    sort( all( vec ) ) ;
    printf( "Case %d:\n%d critical links\n", ++test, vec.size() ) ;
    for( auto x : vec ) printf( "%d - %d\n", x.first, x.second ) ;
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



