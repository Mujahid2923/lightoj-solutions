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
//#define  input freopen("input.txt","rt", stdin)//#define output freopen("output.txt","wt", stdout)
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

int T, n, k ;
string s ;

void pre() {}
void Reset() {}

void Input()
{
    cin >> s ;
}

int Fun( string A , string B )
{
    int n = A.size() ;
    int dp[ n + 2 ][ n + 2 ] ;
    zero( dp ) ;

    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++ )
        {
            if( A[ i - 1 ] == B[ j - 1 ] ) dp[ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ] ;
            else dp[ i ][ j ] = max( dp[ i ][ j - 1 ], dp[ i - 1 ][ j ] ) ;
        }
    }
    return n - dp[ n ][ n ] ;
}

void Calculation()
{
    string s1 = s ;
    reverse( s1.begin() , s1.end() ) ;
    int ans = Fun( s, s1 ) ;
    pf( "Case %d: %d\n", T, ans ) ;
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
    scin( t ) ;
    while( t-- )
    {
        T ++ ;
        solve() ;
    }

    return 0 ;
}



