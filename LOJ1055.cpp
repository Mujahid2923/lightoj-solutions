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
#define          siz                    100005
int dx[] = { +1, -1, +0, +0 } ;
int dy[] = { +0, +0, +1, -1 } ;

///--------------------**********----------------------------------

vector < ll > v, v1, v2, v3, v4 ;
vector < pll > vec ;
vector < ll > adj[ 5 ] ;
map < pii, int > Mp ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int n, test ;
struct data
{
    pii A, B, C ;
};


int level[ 12 ][ 12 ][ 12 ][ 12 ][ 12 ][ 12 ], visited[ 12 ][ 12 ][ 12 ][ 12 ][ 12 ][ 12 ] ;
char s[ 12 ][ 12 ] ;

void Reset()
{
    zero( level ) ;
    zero( visited ) ;
    Mp.clear() ;
}

void Input()
{
    cin >> n ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++ )
        {
            cin >> s[ i ][ j ] ;
        }
    }
}

bool valid( pii val )
{
    int x = val.ff, y = val.ss ;
    if( x >= 1 && x <= n && y >= 1 && y <= n && s[ x ][ y ] != '#' ) return true ;
    else return false ;
}

int bfs( data S )
{
    queue < data > Q ;
    Q.push( S ) ;
    visited[ S.A.ff ][ S.A.ss ][ S.B.ff ][ S.B.ss ][ S.C.ff ][ S.C.ss ] = 1 ;

    while( !Q.empty() )
    {
        data u = Q.front() ;
        Q.pop() ;


        if( Mp[ u.A ] && Mp[ u.B ] && Mp[ u.C ] && u.A != u.B && u.B != u.C && u.A != u.C ) return level[ u.A.ff ][ u.A.ss ][ u.B.ff ][ u.B.ss ][ u.C.ff ][ u.C.ss ] ;

        for( int i = 0 ; i < 4 ; i ++ )
        {
            data v ;
            v.A.ff = u.A.ff + dx[ i ], v.A.ss = u.A.ss + dy[ i ], v.B.ff = u.B.ff + dx[ i ], v.B.ss = u.B.ss + dy[ i ], v.C.ff = u.C.ff + dx[ i ], v.C.ss = u.C.ss + dy[ i ] ;

            if( !valid( v.A ) ) v.A = u.A ;
            if( !valid( v.B ) ) v.B = u.B ;
            if( !valid( v.C ) ) v.C = u.C ;

            if( v.A == v.B )
            {
                v.A = u.A, v.B = u.B ;
                if( v.B == v.C ) v.C = u.C ;
            }

            if( v.A == v.C ) v.A = u.A, v.C = u.C ;

            if( v.B == v.C )
            {
                v.B = u.B, v.C = u.C ;
                if( v.B == v.A ) v.A = u.A ;
            }

            if( !visited[ v.A.ff ][ v.A.ss ][ v.B.ff ][ v.B.ss ][ v.C.ff ][ v.C.ss ] )
            {
                visited[ v.A.ff ][ v.A.ss ][ v.B.ff ][ v.B.ss ][ v.C.ff ][ v.C.ss ] = 1 ;
                level[ v.A.ff ][ v.A.ss ][ v.B.ff ][ v.B.ss ][ v.C.ff ][ v.C.ss ] = level[ u.A.ff ][ u.A.ss ][ u.B.ff ][ u.B.ss ][ u.C.ff ][ u.C.ss ] + 1 ;
                Q.push( v ) ;
            }
        }
    }

    return -1 ;
}

void Calculation()
{
    data Start ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++ )
        {
            if( s[ i ][ j ] == 'A' ) Start.A = { i, j } ;
            if( s[ i ][ j ] == 'B' ) Start.B = { i, j } ;
            if( s[ i ][ j ] == 'C' ) Start.C = { i, j } ;
            if( s[ i ][ j ] == 'X' ) Mp[ { i, j } ] = 1 ;
        }
    }

    int ans = bfs( Start ) ;
    if( ans == -1 ) pf( "Case %d: trapped\n", ++test ) ;
    else pf( "Case %d: %d\n", ++test, ans ) ;
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
    while( t-- ) solve() ;
    return 0 ;
}



