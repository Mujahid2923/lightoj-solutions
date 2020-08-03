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
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;
///#define          endl                   '\n'

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


ll n, m, k ;
ll parent[ 10005 ] ;
ll visited[ 10005 ] ;
vector < ll > adj[ 10005 ] ;

struct node
{
    ll a, b, c ;
    node( ll x, ll y, ll z )
    {
        a = x ;
        b = y ;
        c = z ;
    }

    bool operator < ( const node &p ) const
    {
        return c < p.c ;
    }
};

vector < node > vec ;

ll Find( ll r )
{
    if( r == parent[ r ] )
        return r ;
    else
        return parent[ r ] = Find( parent[ r ] ) ;
}

ll kruskal()
{
    for( int i = 1 ; i <= n ; i ++ )
    {
        parent[ i ] = i ;
    }

    ll sum = 0, cnt = 0 ;
    for( int i = 0 ; i < vec.size() ; i ++ )
    {
        ll u = Find( vec[ i ].a ) ;
        ll v = Find( vec[ i ].b ) ;
        if( u != v )
        {
            parent[ u ] = v ;
            sum += vec[ i ].c ;
            cnt ++ ;
            if( cnt == n )
            {
                return sum ;
            }
        }
    }
    return sum ;
}

void dfs( ll s )
{
    visited[ s ] = 1 ;
    for( int i = 0 ; i < adj[ s ].size() ; i ++ )
    {
        ll v = adj[ s ][ i ] ;
        if( visited[ v ] == 0 )
        {
            visited[ v ] = 1 ;
            dfs( v ) ;
        }
    }
}

int main()
{
    ll t, p, q, r ;
    cin >> t ;
    for( int j = 1 ; j <= t ; j ++ )
    {
        cin >> n >> m >> k ;
        for( int i = 1 ; i <= m ; i ++ )
        {
            cin >> p >> q >> r ;

            if( r < k )
            {
                adj[ p ].pb( q ) ;
                adj[ q ].pb( p ) ;
                vec.pb( node( p, q, r ) ) ;
            }
        }


        sort( all( vec ) ) ;
        ll ans = kruskal() ;
        ll cnt = 0 ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            if( visited[ i ] == 0 )
            {
                dfs( i ) ;
                cnt ++ ;
            }
        }

        pf( "Case %d: %lld %lld\n", j, ans + ( cnt * k ), cnt ) ;

        vec.clear() ;
        zero( parent ) ;
        zero( visited ) ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            adj[ i ].clear() ;
        }
    }

    return 0 ;
}


