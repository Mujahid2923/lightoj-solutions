#include<bits/stdc++.h>
using namespace std;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          output                 freopen("output.txt","wt", stdout)
#define          ld                     long double
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    10056
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

///--------------------**********----------------------------------

vector < int > v, v1, v2, v3, v4 ;
vector < pii > vec( 16 ) ;
vector < int > adj[ 100005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < int > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;
deque < ll > A ;

///---------------------**********--------------------------------

int n, m, test, siz = 1 ;
int dp[ 16 ][ 1 << 16 ] ;
char ch ;

void Reset()
{
    siz = 1 ;
    vec.clear() ;
    memset( dp, -1, sizeof dp ) ;
}

void Input()
{
    scanf( "%d %d", &n, &m ) ;
    for( int i = 0 ; i < n ; i ++ )
    {
        for( int j = 0 ; j < m ; j ++ )
        {
            cin >> ch ;
            if( ch == 'x' ) vec[ 0 ] = { i, j } ;
            if( ch == 'g' ) vec[ siz ++ ] = { i, j } ;
        }
    }
}

int Distance( pii x, pii y )
{
    return max( abs( x.ff - y.ff ), abs( x.ss - y.ss ) ) ;
}

int Fun( int pos, int mask )
{
    if( mask == ( 1 << siz ) - 1 ) return Distance( vec[ 0 ], vec[ pos ] ) ;
    if( dp[ pos ][ mask ] != -1 ) return dp[ pos ][ mask ] ;

    int res = 1e5 ;
    for( int i = 0 ; i < siz ; i ++ )
    {
        if( !( mask & ( 1 << i ) ) )
        {
            res = min( res, Distance( vec[ i ], vec[ pos ] ) + Fun( i, mask | ( 1 << i ) ) ) ;
        }
    }
    return dp[ pos ][ mask ] = res ;
}

void Calculation()
{
    printf( "Case %d: %d\n", ++test, Fun( 0 , 0 ) ) ;
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



