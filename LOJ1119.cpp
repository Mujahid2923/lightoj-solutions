
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

vector < int > v, v1, v2, v3, v4 ;
vector < pair < ll, pll > > vec1 ;
vector < pair < ll, ll > > vec ;
vector < ll > adj[ 200005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < ll > st, st1,st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

int T, n ;
int dp[ 1 << 14 ] ;
int arr[ 14 ][ 14 ] ;

void Reset()
{
    memset( dp, -1, sizeof dp ) ;
}

void Input()
{
    cin >> n ;
    for( int i = 0 ; i < n ; i ++ )
    {
        for( int j = 0 ; j < n ; j ++ )
        {
            cin >> arr[ i ][ j ] ;
        }
    }
}

int Fun( int mask )
{
    if( mask == ( 1 << n ) - 1 ) return 0 ;
    if( dp[ mask ] != -1 ) return dp[ mask ] ;

    int res = 1e9 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if( !( mask & ( 1 << i ) ) )
        {
            int val = arr[ i ][ i ] ;
            for( int j = 0 ; j < n ; j ++ )
            {
                if( mask & ( 1 << j ) ) val += arr[ i ][ j ] ;
            }
            res = min( res, val + Fun( mask | ( 1 << i ) ) ) ;
        }
    }
    return dp[ mask ] = res ;
}

void Calculation()
{
    int ans = Fun( 0 ) ;
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
    int t ;
    cin >> t ;
    while( t-- )
    {
        T ++ ;
        solve() ;
    }

    return 0 ;
}


3
1st 2nd 3rd
14  23   0
0   14   0
17  90   14

We will permute the taken oreder. And the optimal order is 3 1 2
At first we take 3rd value ( 14 ) = 14
then want to take 1st value but as we already taken 3rd value so now taken value is ( 14( 1st ) + 0( 3rd ) ) = 14
Then finally we take 2nd value but as we already taken 3rd and 1st value so now taken value is ( 14( 1st ) + 0( 3rd ) + 0( 3rd ) ) = 14
ans is 14 + 14 + 14 = 42

