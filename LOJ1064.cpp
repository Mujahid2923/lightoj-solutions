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
vector < pii > vec ;
vector < int > adj[ 100005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < int > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;
deque < ll > A ;

///---------------------**********--------------------------------

int n, x, test ;
ll dp[ 25 ][ 150 ] ;
ll arr[ 25 ] ;

void Reset()
{
    memset( dp, -1, sizeof dp ) ;
}

void pre()
{
    arr[ 1 ] = 6LL ;
    for( int i = 2 ; i < 25 ; i ++ ) arr[ i ] = arr[ i - 1 ] * 6LL ;
}

void Input()
{
    scanf( "%d %d", &n, &x ) ;
}

ll Fun( int pos, int sum )
{
    if( pos == n )
    {
        if( sum >= x ) return 1 ;
        else return 0 ;
    }

    if( dp[ pos ][ sum ] != -1 ) return dp[ pos ][ sum ] ;

    ll res = 0 ;
    for( int i = 1 ; i <= 6 ; i ++ )
    {
        res += Fun( pos + 1, sum + i ) ;
    }
    return dp[ pos ][ sum ] = res ;
}

void Calculation()
{
    ll up = Fun( 0, 0 ) ;
    ll down = arr[ n ] ;
    ll g = gcd( up, down ) ;
    if( up == 0 ) printf( "Case %d: 0\n", ++test ) ;
    else if( down / g == 1 ) printf( "Case %d: 1\n", ++test ) ;
    else printf( "Case %d: %lld/%lld\n", ++test, up / g, down / g ) ;
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    pre() ;
    int t ;
    scanf( "%d", &t ) ;
    while( t-- ) solve() ;
    return 0 ;
}




