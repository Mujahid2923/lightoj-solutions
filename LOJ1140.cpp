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
#define          siz                    10005

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

ll n, t, test, a, b ;
ll dp[ 12 ][ 12 ][ 2 ][ 2 ] ;

void Reset()
{

}

void Input()
{
    scanf( "%lld %lld", &a, &b ) ;
}

ll Fun( int pos, int cnt, int stat, int sm )
{
    if( pos == v.size() ) return cnt ;
    if( dp[ pos ][ cnt ][ stat ][ sm ] != -1 ) return dp[ pos ][ cnt ][ stat ][ sm ] ;

    int limit = v[ pos ] ;
    if( sm ) limit = 9 ;

    ll res = 0 ;
    for( int i = 0 ; i <= limit ; i ++ )
    {
        if( i == 0 ) res += Fun( pos + 1, cnt + stat, stat, ( i < limit ) || sm ) ;
        else res += Fun( pos + 1, cnt, 1, ( i < limit ) || sm ) ;
    }
    return dp[ pos ][ cnt ][ stat ][ sm ] = res ;
}

ll Cal( ll n )
{
    memset( dp, -1, sizeof dp ) ;
    if( n == -1 ) return -1 ;
    v.clear() ;
    while( n )
    {
        v.pb( n % 10 ) ;
        n /= 10 ;
    }
    reverse( all( v ) ) ;
    return Fun( 0, 0, 0, 0 ) ;
}

void Calculation()
{
    printf( "Case %lld: %lld\n", ++test, Cal( b ) - Cal( a - 1 ) ) ;
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    scanf( "%lld", &t ) ;
    while( t-- ) solve() ;
    return 0 ;
}

