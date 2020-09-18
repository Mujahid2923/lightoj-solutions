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

ll n, m, k, test ;
ll nCr[ 1005 ][ 1005 ] ;
ll Fact[ 1005 ] ;

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

    Fact[ 0 ] = 1 ;
    for( ll i = 1 ; i <= 1000 ; i ++ )
    {
        Fact[ i ] = ( Fact[ i - 1 ] * i ) % MOD ;
    }
}

void Reset()
{

}

void Input()
{
    scanf( "%lld %lld %lld", &n, &m, &k ) ;
}


void Calculation()
{
    ll ans1 = nCr[ m ][ k ] ;
    ll ans2 = Fact[ n - k ] ;
    for( int i = 1 ; i <= m - k ; i ++ )
    {
        if( i & 1 ) ans2 = ( ( ans2 - ( nCr[ m - k ][ i ] * Fact[ n - k - i ] ) % MOD ) + MOD ) % MOD ;
        else ans2 = ( ans2 + (  nCr[ m - k ][ i ] * Fact[ n - k - i ] ) % MOD ) % MOD ;
    }
    printf( "Case %lld: %lld\n", ++test, ( ans1 * ans2 ) % MOD ) ;
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
    int t ;
    scanf( "%d", &t ) ;
    while( t-- ) solve() ;
    return 0 ;
}

/*
http://www.shafaetsplanet.com/planetcoding/?p=600

10 6 3
1 2 3 4 5 6 | 7 8 9 10
From first 6 position 3 position must need to be in the the same position with index.
from 6 to 3 we can arrange in nCr = 6C3 ways.
and then 10 - 3 = 7 position if empty .That can be arrange in 7! way .
But by dearrangement method we need to remove the overlapping part .
As from 7 , last 4 element can be arrange in any position ( index dones not matter for them ).
But for the remaining 6 - 3 = 3 position index matter .
So, From these 3 position if we remove those position where 1 person on their own position .
then add 2 person on their own position then remove 3 person on own position ........
( inclusion - exclution principal : | A ∪ B| = |A| + | B | − | A ∩ B | )
*/




