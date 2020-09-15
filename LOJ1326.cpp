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

int n, t, test ;
int dp[ 1005 ], nCr[ 1005 ][ 1005 ] ; ;

void pre()
{
    for( int i = 0 ; i <= 1000 ; i ++ )
    {
        nCr[ i ][ 0 ] = nCr[ i ][ i ] = 1 ;
        for( int j = 1 ; j < i ; j ++ )
        {
            nCr[ i ][ j ] = ( nCr[ i - 1 ][ j ] + nCr[ i - 1 ][ j - 1 ] ) % MOD ;
        }
    }
    memset( dp, -1, sizeof dp ) ;
}

void Reset()
{
}

void Input()
{
    scanf( "%d", &n ) ;
}

int Fun( int n )
{
    if( n <= 1 ) return 1 ;
    if( dp[ n ] != -1 ) return dp[ n ] ;
    int cnt = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        cnt = ( cnt + ( nCr[ n ][ i ] * Fun( n - i ) ) % MOD ) % MOD ;
    }
    return dp[ n ] = cnt ;
}

void Calculation()
{
    printf( "Case %d: %d\n", ++test, Fun( n ) ) ;
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
    scanf( "%d", &t ) ;
    while( t-- ) solve() ;
    return 0 ;
}


/// https://shahidul-brur.blogspot.com/2017/04/tutorial-lightoj-1326-uva-12034-solution.html
