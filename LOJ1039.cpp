///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
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
#define          no                     cout << "No" << endl ;
#define          yes                    cout << "Yes" << endl ;
//#define          endl                   '\n'

///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = std::bitset<64>(n).to_string();
///---------------Order set-------------------
///template<typename T> using orderset =tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
///#include <ext/pb_ds/assoc_container.hpp>
///using namespace __gnu_pbds;
///*os.find_by_order(index) os.order_of_key(value)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
///sort( all( v ) ) ;

vector < ll > v, v1, v2, v3 ;
vector < pll > vec, vec1, vec2 ;
vector < pair < ll, pll > > vec3 ;
vector < ll > adj[ 200005 ] ;
map < ll, ll > Mp;
map < ll, ll > Mp2;
set < ll > st,st1, st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S, S2 ;
multiset < ll > :: iterator it ;


int fx[] = {0, 0, 1, 0, 0, -1};
int fy[] = {0, 1, 0, 0, -1, 0};
int fz[] = {1, 0, 0, -1, 0, 0};

string s, d ;
ll visited[ 50 ][ 50 ][ 50 ] ;
ll level[ 50 ][ 50 ][ 50 ] ;

void input1()
{
    cin >> s >> d ;
}

void input2()
{
    ll n ;
    string a, b, c ;
    cin >> n ;
    while( n -- )
    {
        cin >> a >> b >> c ;
        for( int i = 0 ; i < a.size() ; i ++ )
        {
            for( int j = 0 ; j < b.size() ; j ++ )
            {
                for( int k = 0 ; k < c.size() ; k ++ )
                {
                    visited[ a[ i ] - 'a' ][ b[ j ] - 'a' ][ c[ k ] - 'a' ] = 1 ;
                }
            }
        }
    }
}

struct point
{
    int x, y, z ;
    point() {} ;
    point( int a, int b, int c )
    {
        x = a ;
        y = b ;
        z = c ;
    }
};

ll bfs()
{
    queue < point > Q ;
    if( visited[ s[ 0 ] - 'a' ][ s[ 1 ] - 'a' ][ s[ 2 ] - 'a' ] == 0 )
    {
        visited[ s[ 0 ] - 'a' ][ s[ 1 ] - 'a' ][ s[ 2 ] - 'a' ] = 1 ;
        Q.push( point( s[ 0 ] - 'a', s[ 1 ] - 'a', s[ 2 ] - 'a' ) ) ;
    }

    while( !Q.empty() )
    {
        point u = Q.front() ;
        Q.pop() ;

        if( u.x == d[ 0 ] - 'a' && u.y == d[ 1 ] - 'a' && u.z == d[ 2 ] - 'a' )
        {
            return level[ u.x ][ u.y ][ u.z ] ;
        }

        for( int i = 0 ; i < 6 ; i ++ )
        {
            int a = ( u.x + fx[ i ] ) % 26 ;
            int b = ( u.y + fy[ i ] ) % 26 ;
            int c = ( u.z + fz[ i ] ) % 26 ;

            if( a < 0 ) a += 26 ;
            if( b < 0 ) b += 26 ;
            if( c < 0 ) c += 26 ;

            if( visited[ a ][ b ][ c ] == 0 )
            {
                visited[ a ][ b ][ c ] = 1 ;
                level[ a ][ b ][ c ] = level[ u.x ][ u.y ][ u.z ] + 1 ;
                Q.push( point( a, b, c ) ) ;
            }
        }
    }
    return -1 ;
}

int main()
{
    CIN ;
    ll t ;
    cin >> t ;
    for( int k = 1 ; k <= t ; k ++ )
    {
        input1() ;
        input2() ;
        ll x = bfs() ;
        pf( "Case %d: %lld\n", k, x ) ;
        zero( visited ) ;
        zero( level ) ;
    }


    return 0 ;
}
