///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

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
#define          siz                    50005

int test, n, k ;
int arr[ 17 ][ 17 ] ;
int dp[ 1 << 17 ] ;

int Set( int n, int pos )
{
    return n = n | ( 1 << pos ) ;
}

bool check( int n, int pos )
{
    return (bool) ( n & ( 1 << pos ) ) ;
}

void Reset()
{
    memset( dp, -1, sizeof dp ) ;
}

void Input()
{
    scanf( "%d", &n ) ;
    for( int i = 0 ; i < n ; i ++ )
    {
        for( int j = 0 ; j < n ; j ++ )
        {
            scanf( "%d", &arr[ i ][ j ] ) ;
        }
    }
}

int Fun( int mask , int pos )
{
    if( mask == ( 1 << n ) - 1 ) return 0 ;
    if( dp[ mask ] != -1 ) return dp[ mask ] ;

    int ans = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if( !check( mask, i ) )
        {
            int val = arr[ pos ][ i ] + Fun( Set( mask, i ), pos + 1 ) ;
            ans = max( ans , val ) ;
        }
    }
    return dp[ mask ] = ans ;
}

void Calculation()
{
    printf( "Case %d: %d\n", ++ test, Fun( 0, 0 ) ) ;
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
