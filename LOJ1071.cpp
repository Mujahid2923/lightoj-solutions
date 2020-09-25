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
#define          mone(a)                memset(a,-1,sizeof a)
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
vector < pair < ll, ll > > vec ;
vector < ll > adj[ 100 ],cost[ 100 ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int row, col, test ;
int arr[ 105 ][ 105 ] ;
int dp[ 105 ][ 105 ][ 105 ] ;

void Reset()
{
    mone( dp ) ;
}

void Input()
{
    scanf( "%d %d", &row, &col ) ;
    for( int i = 1 ; i <= row ; i ++ )
    {
        for( int j = 1 ; j <= col ; j ++ )
        {
            scanf( "%d", &arr[ i ][ j ] ) ;
        }
    }
}

int Fun( int r1, int c1, int r2, int c2 )
{
    if( r1 > row || r2 > row || c1 > col || c2 > col ) return 0 ;
    if( r1 == r2 && c1 == c2 ) return 0 ;
    if( dp[ r1 ][ c1 ][ c2 ] != -1 ) return dp[ r1 ][ c1 ][ c2 ] ;
    int res = 0 ;
    res = max( res, arr[ r1 ][ c1 ] + arr[ r2 ][ c2 ] + Fun( r1 + 1, c1, r2 + 1, c2 ) ) ;
    res = max( res, arr[ r1 ][ c1 ] + arr[ r2 ][ c2 ] + Fun( r1 + 1, c1, r2, c2 + 1 ) ) ;
    res = max( res, arr[ r1 ][ c1 ] + arr[ r2 ][ c2 ] + Fun( r1, c1 + 1, r2 + 1, c2 ) ) ;
    res = max( res, arr[ r1 ][ c1 ] + arr[ r2 ][ c2 ] + Fun( r1, c1 + 1, r2, c2 + 1 ) ) ;
    return dp[ r1 ][ c1 ][ c2 ] = res ;
}

void Calculation()
{
    printf( "Case %d: %d\n", ++test, Fun( 1, 2, 2, 1 ) + arr[ 1 ][ 1 ] + arr[ row ][ col ] ) ;
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

