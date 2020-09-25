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

vector < ll > v, v1, v2, v3, v4 ;
vector < pair < ll, pll > > vec ;
vector < ll > adj[ sz ],cost[ sz ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int r, b, test ;
double dp[ 505 ][ 505 ] ;
int visited[ 505 ][ 505 ] ;

void Reset()
{

}

void Input()
{
    scanf( "%d %d", &r, &b ) ;
}

double Fun( int r, int b )
{
    if( !r && !b ) return 1.0 ;
    if( !b ) return 0.0 ;
    if( !r ) return 1.0 ;
    if( visited[ r ][ b ] ) return dp[ r ][ b ] ;
    else visited[ r ][ b ] = 1 ;
    double res = 0 ;
    res += ( r / (double)( r + b ) ) * Fun( r - 1, b - 1 ) ;
    if( b >= 2 ) res += ( b / (double)( r + b ) ) * Fun( r, b - 2 ) ;
    return dp[ r ][ b ] = res ;
}


void Calculation()
{
    printf( "Case %d: %.7f\n", ++test, Fun( r, b ) ) ;
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

