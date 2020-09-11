
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
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scin3(x,y,z)           scanf("%d %d %d",&(x),&(y),&(z))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          scln3(x,y,z)           scanf("%lld %lld %lld",&(x),&(y),&(z))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
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

vector < char > v, v1, v2, v3, v4 ;
vector < pair < ll, pll > > vec1 ;
vector < pair < int, string > > vec ;
vector < ll > adj[ 200005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < ll > st, st1,st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int test, n1, n2 , dp[ 105 ][ 105 ] ;
string s1, s2, sp[ 105 ][ 105 ] ;
void Reset()
{
    zero( dp );
    v.clear() ;
}

void Input()
{
    cin >> s1 >> s2 ;
    n1 = s1.size(), n2 = s2.size() ;
}


void Calculation()
{
    for( int i = 1 ; i <= n1 ; i ++ )
    {
        for( int j = 1 ; j <= n2 ; j ++ )
        {
            if( s1[ i - 1 ] == s2[ j - 1 ] )
            {
                dp[ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ] ;
                sp[ i ][ j ] = sp[ i - 1 ][ j - 1 ] + s1[ i - 1 ] ;
            }
            else
            {
                if( dp[ i - 1 ][ j ] > dp[ i ][ j - 1 ] )
                {
                    dp[ i ][ j ] = dp[ i - 1 ][ j ] ;
                    sp[ i ][ j ] = sp[ i - 1 ][ j ] ;
                }
                else if( dp[ i ][ j - 1 ] > dp[ i - 1 ][ j ] )
                {
                    dp[ i ][ j ] = dp[ i ][ j - 1 ] ;
                    sp[ i ][ j ] = sp[ i ][ j - 1 ] ;
                }
                else
                {
                    dp[ i ][ j ] = dp[ i ][ j - 1 ] ;
                    sp[ i ][ j ] = min( sp[ i - 1 ][ j ], sp[ i ][ j - 1 ] ) ;
                }
            }
        }
    }

    if( !dp[ n1 ][ n2 ] ) cout << "Case " << test << ": " << ":(" << endl ;
    else cout << "Case " << test << ": " << sp[ n1 ][ n2 ] << endl ;
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

