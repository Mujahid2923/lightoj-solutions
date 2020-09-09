///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          eb                     emplace_back
#define          sc                     scanf
#define          pf                     printf
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

ll T, lcs,n1, n2 ;
ll dp1[ 35 ][ 35 ] ;
ll dp2[ 35 ][ 35 ][ 35 ] ;
string s1, s2 ;

void Reset()
{
    memset( dp1, -1, sizeof dp1 ) ;
    memset( dp2, -1, sizeof dp2 ) ;
}

void Input()
{
    cin >> s1 >> s2 ;
    n1 = s1.size() ;
    n2 = s2.size() ;
}

int Fun1( int i, int j )
{
   if( i == n1 || j == n2 ) return 0 ;
   if( dp1[ i ][ j ] != -1 ) return dp1[ i ][ j ] ;

   int sum = 0 ;
   if( s1[ i ] == s2[ j ] ) sum = 1 + Fun1( i + 1, j + 1 ) ;
   else sum = max( Fun1( i + 1, j ), Fun1( i, j + 1 ) ) ;

   return dp1[ i ][ j ] = sum ;
}

ll Fun2( int i, int j, int cnt )
{
    if( i == n1 || j == n2 ) return ( cnt == lcs ) ;
    if( dp2[ i ][ j ][ cnt ] != -1 ) return dp2[ i ][ j ][ cnt ] ;

    ll res = 0 ;
    if( s1[ i ] == s2[ j ] ) res += Fun2( i + 1, j + 1, cnt + 1 ) ;
    else res += Fun2( i + 1, j, cnt ) + Fun2( i, j + 1, cnt ) ;

    return dp2[ i ][ j ][ cnt ] = res ;
}

void Calculation()
{
    lcs = Fun1( 0, 0 ) ;
    ll ans = n1 + n2 - lcs ;
    pf( "Case %lld: %lld %lld\n", T, ans, Fun2( 0, 0, 0 ) ) ;
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
    cin >> t ;
    while( t-- )
    {
        T ++ ;
        solve() ;
    }

    return 0 ;
}


