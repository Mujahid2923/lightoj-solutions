
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

ll T, n ;
ll dp[ 65 ][ 65 ] ;
string s ;

void Reset()
{
    memset( dp, -1, sizeof dp ) ;
}

void Input()
{
    cin >> s ;
    n = s.size() ;
}

ll Fun( int i, int j )
{
    if( i > j ) return 0 ;
    if( dp[ i ][ j ] != -1 ) return dp[ i ][ j ] ;

    ll res = 0 ;
    if( s[ i ] == s[ j ] ) res = ( 1 + Fun( i + 1, j - 1 ) ) + Fun( i + 1, j ) + Fun( i, j - 1 ) - Fun( i + 1, j - 1 ) ;
    else res = Fun( i + 1, j ) + Fun( i, j - 1 ) - Fun( i + 1, j - 1 ) ;

    return dp[ i ][ j ] = res ;
}

void Calculation()
{
    ll ans = Fun( 0, n - 1 ) ;
    pf( "Case %lld: %lld\n",T, ans ) ;
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


/// Explanation


I hope this explanation makes the solution clear to you.
If there is just one character in the string, it is a palindrome.
If there are more characters left in the string,
you can remove character from left Fun( i + 1, j ) or right Fun( i, j - 1 ).
But in both recursions you will count Fun( i + 1, j - 1 ) .
To avoid counting twice, we subtract it from ret.
There is only one case left: when str[ i ] == str[ j ] ,
you can keep both characters (do not remove them) and
then you should call Fun( i + 1, j - 1 ) to build the middle and
we add one because we never count the palindrome consisting of just these two characters.

