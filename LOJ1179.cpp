#include<bits/stdc++.h>
using namespace std ;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          output                 freopen("output.txt","wt", stdout)
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

vector < ll > v, v1, v2, v3, v4 ;
vector < pair < ll, pll > > vec1, vec2 ;
vector < pll > vec, Vec ;
vector < ll > adj[ 100005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < ll > st, st1, st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S ;
vector < string > vs ;


///---------------------**********--------------------------------

int n, m, T ;

void Reset()
{

}

void Input()
{
    scanf( "%d", &n ) ;
    scanf( "%d", &m ) ;
}


void Calculation()
{
    int ans = 0 ;

    for( int i = 1 ; i <= n ; i ++ )
    {
        ans = ( ans + m ) % i ;
    }

    printf( "Case %d: %d\n", T, ans + 1 ) ;
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
    while( t-- )
    {
        T ++ ;
        solve() ;
    }
    return 0 ;
}

