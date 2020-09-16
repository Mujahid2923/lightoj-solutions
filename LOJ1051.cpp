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
string s ;
int dp[ 55 ][ 3 ][ 5 ] ;

void Reset()
{
    memset( dp, -1, sizeof dp ) ;
}

void Input()
{
    cin >> s ;
    n = s.size() ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if( s[ i ] == '?' ) continue ;
        else if( s[ i ] == 'A' || s[ i ] == 'E' || s[ i ] == 'I' || s[ i ] == 'O' || s[ i ] == 'U' ) s[ i ] = '0' ;
        else s[ i ] = '1' ;
    }
}

int Fun( int pos, int x, int y )
{
    if( x == 3 || y == 5 ) return 1 ;
    if( pos == n ) return 0 ;
    if( dp[ pos ][ x ][ y ] != -1 ) return dp[ pos ][ x ][ y ] ;

    int res = 0 ;
    if( s[ pos ] == '?' )
    {
        int a = Fun( pos + 1, x + 1, 0 ) ;
        int b = Fun( pos + 1, 0, y + 1 ) ;

        if( a != b || a == 2 || b == 2 ) res = 2 ;
        else if( a == 1 && b == 1 ) res = 1 ;
        else if( a == 0 && b == 0 ) res = 0 ;
    }
    else if( s[ pos ] == '0' ) res = Fun( pos + 1, x + 1, 0 ) ;
    else res = Fun( pos + 1, 0, y + 1 ) ;

    return dp[ pos ][ x ][ y ] = res ;
}

void Calculation()
{
    int ans = Fun( 0, 0, 0 ) ;
    if( ans == 2 ) printf( "Case %d: MIXED\n", ++test ) ;
    else if( ans == 1 ) printf( "Case %d: BAD\n", ++test ) ;
    else printf( "Case %d: GOOD\n", ++test ) ;
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
