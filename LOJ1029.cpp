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


///bool operator < ( const Node& p ) const{ return cost < p.cost ; }//choto theke boro
///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = std::bitset<64>(n).to_string();
///---------------Order set-------------------
///template<typename T> using orderset =tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
///#include <ext/pb_ds/assoc_container.hpp>
///using namespace __gnu_pbds;
///*os.Find_by_order(index) os.order_of_key(value)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
///sort( all( v ) ) ;

ll n , sum1 = 0 , sum2 = 0 ;
struct node1
{
    ll a1, b1, c1 ;
    node1( ll x, ll y, ll z )
    {
        a1 = x ;
        b1 = y ;
        c1 = z ;
    }

    bool operator < ( const node1 &p ) const
    {
        return c1 < p.c1 ;
    }
};

struct node2
{
    ll a2, b2, c2 ;
    node2( ll x, ll y, ll z )
    {
        a2 = x ;
        b2 = y ;
        c2 = z ;
    }

    bool operator < ( const node2 &p ) const
    {
        return c2 > p.c2 ;
    }
};

vector < node1 > v1 ;
vector < node2 > v2 ;

ll par1[ 105 ] , par2[ 105 ] ;

ll Find1( ll r )
{
    if( r == par1[ r ] )
        return r ;
    else
        return par1[ r ] = Find1( par1[ r ] ) ;
}

ll kruskal1()
{
    for( int i = 1 ; i <= n ; i ++ )
    {
        par1[ i ] = i ;
    }

    ll cnt1 = 0 ;
    for( int i = 0 ; i < v1.size() ; i ++ )
    {
        ll u = Find1( v1[ i ].a1 ) ;
        ll v = Find1( v1[ i ].b1 ) ;

        if( u != v )
        {
            cnt1 ++ ;
            par1[ u ] = v ;
            sum1 += v1[ i ].c1 ;
            if( cnt1 == n )
            {
                break ;
            }
        }
    }
}

ll Find2( ll r )
{
    if( r == par2[ r ] )
        return r ;
    else
        return par2[ r ] = Find2( par2[ r ] ) ;
}

ll kruskal2()
{
    for( int i = 1 ; i <= n ; i ++ )
    {
        par2[ i ] = i ;
    }

    ll cnt2 = 0 ;
    for( int i = 0 ; i < v2.size() ; i ++ )
    {
        ll u = Find2( v2[ i ].a2 ) ;
        ll v = Find2( v2[ i ].b2 ) ;

        if( u != v )
        {
            cnt2 ++ ;
            par2[ u ] = v ;
            sum2 += v2[ i ].c2 ;
            if( cnt2 == n )
            {
                break ;
            }
        }
    }
}

int main()
{
    ll t, u, v, w ;
    cin >> t ;
    for( int k = 1 ; k <= t ; k ++ )
    {
        cin >> n ;
        while( cin >> u >> v >> w )
        {
            if( u == 0 && v == 0 && w == 0 )
            {
                break ;
            }
            v1.pb( node1( u, v, w ) ) ;
            v2.pb( node2( u, v, w ) ) ;
        }
        sort( all( v1 ) ) ;
        sort( all( v2 ) ) ;
        kruskal1() ;
        kruskal2() ;
        ll sum = sum1 + sum2 ;
        if( sum & 1 )
        {
            pf( "Case %d: %lld/2\n" , k , sum ) ;
        }
        else
        {
            pf( "Case %d: %lld\n" , k , sum / 2 ) ;
        }
        v1.clear() ;
        v2.clear() ;
        zero( par1 ) ;
        zero( par2 ) ;
        sum1 = 0 , sum2 = 0 ;
    }

    return 0;
}



