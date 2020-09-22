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

vector < ll > v, v1, v2, v3, v4 ;
vector < pair < ll, pll > > vec ;
vector < ll > adj[ sz ],cost[ sz ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int n, test, sum = 0 ;
double pb ;
double dp[ 10005 ],P[ 105 ] ;
int W[ 105 ] ;

void Reset()
{
    sum = 0 ;
    zero( dp ) ;
}

void Input()
{
    scanf( "%lf %d", &pb, &n ) ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        scanf( "%d %lf", &W[ i ], &P[ i ] ) ;
        sum += W[ i ] ;
        P[ i ] = 1 - P[ i ] ;
    }
    pb = 1 - pb ;
}


void Calculation()
{
    dp[ 0 ] = 1 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = sum ; j >= W[ i ] ; j -- )
        {
            dp[ j ] = max( dp[ j ], dp[ j - W[ i ] ] * P[ i ] ) ;
        }
    }

    //printf( "Probability of not getting caught-> %.4f\n", pb ) ;
    int ans = 0 ;
    for( int i = 0 ; i <= sum ; i ++ )
    {
        if( dp[ i ] > pb ) ans = i ;
    }
    printf( "Case %d: %d\n", ++test, ans ) ;
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
