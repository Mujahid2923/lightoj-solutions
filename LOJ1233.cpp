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

vector < ll > v, v1( 105 ), v2( 105 ), v3, v4 ;
vector < pair < ll, pll > > vec ;
vector < ll > adj[ sz ],cost[ sz ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int n, m, test ;
int dp[ 100005 ] ;

void Reset()
{
    v1.clear() ;
    v2.clear() ;
    zero( dp ) ;
}

void Input()
{
    scanf( "%d %d", &n, &m ) ;
    for( int i = 0 ; i < n ; i ++ ) scanf( "%d", &v1[ i ] ) ;
    for( int i = 0 ; i < n ; i ++ ) scanf( "%d", &v2[ i ] ) ;
}

int Fun( int pos, int cnt, int amount )
{
    //cout << pos << " " << cnt << " " << amount << endl ;
    if( pos == n ) return 0 ;
    if( dp[ amount ] ) return dp[ amount ] ;

    int res = 1 ;
    if( cnt < v2[ pos ] && v1[ pos ] + amount <= m )
    {
        res = Fun( pos, cnt + 1, amount + v1[ pos ] ) ;
    }
    res = max( res, Fun( pos + 1, 0, amount ) ) ;
    return dp[ amount ] = res ;
}

void Calculation()
{
    int ans = 0 ;
    int x = Fun( 0, 0, 0 ) ;
    for( int i = 1 ; i <= m ; i ++ )
    {
        if( dp[ i ] ) ans ++ ;
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
