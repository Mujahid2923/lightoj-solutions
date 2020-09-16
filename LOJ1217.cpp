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

vector < int > v, v1, v2, v3, v4 ;
vector < pii > vec ;
vector < int > adj[ 100005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < int > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;
deque < ll > A ;

///---------------------**********--------------------------------

int n, x, t, test ;
int dp[ 1005 ] ;

void Reset()
{
    v1.clear() ;
    v2.clear() ;
}

void Input()
{
    scanf( "%d", &n ) ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        scanf( "%d", &x ) ;
        if( i == 1 ) v1.pb( x ) ;
        else if( i == n ) v2.pb( x ) ;
        else
        {
            v1.pb( x ) ;
            v2.pb( x ) ;
        }
    }
}

int Fun( vector< int > v, int pos )
{
    if( pos >= n - 1 ) return 0 ;
    if( dp[ pos ] != -1 ) return dp[ pos ] ;
    return dp[ pos ] = max( v[ pos ] + Fun( v, pos + 2 ), Fun( v, pos + 1 ) ) ;
}

void Calculation()
{
    memset( dp, -1, sizeof dp ) ;
    int a = Fun( v1, 0 ) ;
    memset( dp, -1, sizeof dp ) ;
    int b = Fun( v2, 0 ) ;
    printf( "Case %d: %d\n", ++test, max( a , b ) ) ;
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    scanf( "%d", &t ) ;
    while( t-- ) solve() ;
    return 0 ;
}


