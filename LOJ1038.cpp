
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


///sum accumulate( v.begin(), v.begin() + k, 0LL )///bool operator < ( const Node& p ) const{ return cost < p.cost ; }
///priority_queue<int,vector<int>,greater<int> >pq;///std::set<ll, std::greater<ll> > Set;///string str = "abcdefghijklmnopqrstuvwxyz";///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = bitset<64>( n ).to_string() ; ll val =  bitset< 64 >( s ).to_ullong() ;

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0}; ///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move ///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move ///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


///--------------------**********----------------------------------

vector < ll > v, v1, v2, v3, v4 ;
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
double dp[ 100005 ] ;

void pre()
{
    for( int i = 2 ; i <= 100000 ; i ++ )
    {
        double a = 0 , b = 0 ;
        for( int j = 1 ; j * j <= i ; j ++ )
        {
            if( i % j == 0 )
            {
                if( j * j == i )
                {
                    a += dp[ j ] + 1 ;
                    b ++ ;
                }
                else
                {
                    a += dp[ i / j ] + 1 ;
                    a += dp[ j ] + 1 ;
                    b += 2 ;
                }
            }
        }
        dp[ i ] = a / ( b - 1 ) ;
    }
}
void Reset() {}

void Input()
{
    cin >> n ;
}


void Calculation()
{
    pf( "Case %d: %.7f\n",T , dp[ n ] ) ;
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
    cin >> t ;
    while( t-- )
    {
        T ++ ;
        solve() ;
    }

    return 0 ;
}






