#include<bits/stdc++.h>
using namespace std;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          output                 freopen("output.txt","wt", stdout)
#define          ll                     long long int
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
vector < pair < string, string > > vec1, vec2 ;
vector < pll > vec, Vec ;
vector < int > adj[ 100005 ] ;
map < ll, ll > Mp ;
set < ll > st, st1, st2 ;
queue < ll > Q ;
stack < char > Stk ;
multiset < pll > S, B ;
vector < string > vs ;

///---------------------**********--------------------------------

int n, q, T ;
#define mx 505
int Tree[ mx ][ mx * 4 ] ;
int arr[ mx ] ;


void Reset()
{
    zero( Tree ) ;
}

int query( int idx, int node, int b, int e, int i, int j )
{
    if( b > j || e < i )
    {
        return -1 ;
    }

    if( b >= i && e <= j )
    {
        return Tree[ idx ][ node ] ;
    }

    segment_tree ;

    int s1 = query( idx, Lnode, b, mid, i, j ) ;
    int s2 = query( idx, Rnode, mid + 1, e, i, j ) ;

    return max( s1, s2 ) ;
}

void init( int idx, int node, int b, int e )
{
    if( b == e )
    {
        Tree[ idx ][ node ] = arr[ b ] ;
        return ;
    }

    segment_tree ;

    init( idx, Lnode, b, mid ) ;
    init( idx, Rnode, mid + 1, e ) ;
    Tree[ idx ][ node ] = max( Tree[ idx ][ Lnode ], Tree[ idx ][ Rnode ] ) ;
}

void Input()
{
    cin >> n >> q ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1, x ; j <= n ; j ++ )
        {
            scanf( "%d", &arr[ j ] ) ;
        }
        init( i, 1, 1, n ) ;
    }
}


void Calculation()
{
    printf( "Case %d:\n", ++T ) ;
    int x1, y1, x2, y2, k ;
    while( q-- )
    {
        int ans = 0 ;
        scanf( "%d", &x1 ) ;
        scanf( "%d", &y1 ) ;
        scanf( "%d", &k ) ;
        x2 = x1 + k - 1 ;
        y2 = y1 + k - 1 ;
        for( int i = x1 ; i <= x2 ; i ++ )
        {
            ans = max( ans, query( i, 1, 1, n, y1, y2 ) ) ;
        }
        printf( "%d\n", ans ) ;
    }
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
    //t = 1 ;
    while( t-- ) solve() ;
    return 0 ;
}

