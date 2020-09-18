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
vector < int > adj[ 100005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < int > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;
deque < ll > A ;

///---------------------**********--------------------------------

ll n, q, x, d, m, test ;
ll dp[ 1005 ][ 12 ][ 22 ] ;



void Reset()
{
    v.clear() ;
}

void Input()
{
    scanf( "%lld %lld", &n, &q ) ;
    for( int i = 0 ; i < n ; i ++ )
    {
        scanf( "%lld", &x ) ;
        v.pb( x ) ;
    }
}

ll Fun( int pos, int cnt, ll sum )
{
    sum = ( sum + d ) % d ;
    if( cnt == m )
    {
        if( sum == 0 ) return 1 ;
        else return 0 ;
    }
    if( pos == n ) return 0 ;

    if( dp[ pos ][ cnt ][ sum ] != -1 ) return dp[ pos ][ cnt ][ sum ] ;

    ll res = 0 ;
    res += Fun( pos + 1, cnt + 1, ( sum + v[ pos ] ) % d ) ;
    res += Fun( pos + 1, cnt , sum ) ;
    return dp[ pos ][ cnt ][ sum ] = res ;
}

void Calculation()
{
    printf( "Case %lld:\n", ++test ) ;
    while( q-- )
    {
        memset( dp, -1, sizeof dp ) ;
        scanf( "%lld %lld", &d, &m ) ;
        printf( "%lld\n", Fun( 0, 0, 0 ) ) ;
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
