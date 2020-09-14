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

int n, t, test ;
string s1, s2, s3 ;
int dp[ 55 ][ 55 ][ 55 ] ;

void Reset()
{
    memset( dp , -1, sizeof dp ) ;
}

void Input()
{
    cin >> s1 >> s2 >> s3 ;
}

int Fun( int i, int j, int k )
{
    if( i == s1.size() || j == s2.size() || k == s3.size() ) return 0 ;
    if( dp[ i ][ j ][ k ] != -1 ) return dp[ i ][ j ][ k ] ;

    int ans = 0 ;

    if( s1[ i ] == s2[ j ] &&  s1[ i ] == s3[ k ] )
    {
        ans = 1 + Fun( i + 1, j + 1, k + 1 ) ;
    }
    else
    {
        int r1 = Fun( i + 1, j, k ) ;
        int r2 = Fun( i, j + 1, k ) ;
        int r3 = Fun( i, j, k + 1 ) ;
        ans = max( { r1, r2, r3 } ) ;
    }
    return dp[ i ][ j ][ k ] = ans ;
}
void Calculation()
{
    printf( "Case %d: %d\n", ++test, Fun( 0, 0, 0 ) ) ;
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


