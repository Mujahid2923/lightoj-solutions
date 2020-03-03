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

///bool operator < ( const Node& p ) const{ return cost < p.cost ; }
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

#define siz 100005

ll arr[ siz ] ;
ll Tree[ 4 * siz ] ;
ll Lazy[ 4 * siz ] ;

void update( ll node, ll b, ll e, ll i, ll j, ll value )
{
    ll Lnode = node << 1 ;
    ll Rnode = ( node << 1 ) + 1 ;
    ll mid = ( b + e ) >> 1 ;

    if( Lazy[ node ] != 0 )
    {
        Tree[ node ] += ( e - b + 1 ) * Lazy[ node ] ;
        if( b != e )
        {
            Lazy[ Lnode ] += Lazy[ node ] ;
            Lazy[ Rnode ] += Lazy[ node ] ;
        }
        Lazy[ node ] = 0 ;
    }

    if( b > e || b > j || e < i )
    {
        return ;
    }

    if( b >= i && e <= j )
    {
        Tree[ node ] += ( e - b + 1 ) * value ;
        if( b != e )
        {
            Lazy[ Lnode ] += value ;
            Lazy[ Rnode ] += value ;
        }
        return ;
    }

    update( Lnode, b, mid, i, j, value ) ;
    update( Rnode, mid + 1, e, i, j, value ) ;

    Tree[ node ] = Tree[ Lnode ] + Tree[ Rnode ] ;
}

ll query( ll node, ll b, ll e, ll i, ll j )
{
    ll Lnode = node << 1 ;
    ll Rnode = ( node << 1 ) + 1 ;
    ll mid = ( b + e ) >> 1 ;

    if( Lazy[ node ] != 0 )
    {
        Tree[ node ] += ( e - b + 1 ) * Lazy[ node ] ;
        if( b != e )
        {
            Lazy[ Lnode ] += Lazy[ node ] ;
            Lazy[ Rnode ] += Lazy[ node ] ;
        }
        Lazy[ node ] = 0 ;
    }

    if( b > e || b > j || e < i )
    {
        return 0 ;
    }

    if( b >= i && e <= j )
    {
        return Tree[ node ] ;
    }

    ll s1 = query( Lnode, b, mid, i, j ) ;
    ll s2 = query( Rnode, mid + 1, e, i, j ) ;

    return s1 + s2 ;
}

int main()
{
    ll t, a, b, c, q, n, val ;
    scln( t ) ;
    for( ll k = 1 ; k <= t ; k ++ )
    {
        zero( Tree ) ;
        zero( Lazy ) ;
        scln2( n, q ) ;
        printf( "Case %lld:\n", k ) ;
        while( q-- )
        {
            scln( c ) ;
            if( c == 0 )
            {
                scln2( a, b ) ;
                scln( val ) ;
                update( 1, 1, n, a + 1, b + 1, val ) ;
            }
            else
            {
                scln2( a, b ) ;
                ll ans = query( 1, 1, n, a + 1, b + 1 ) ;
                printf( "%lld\n", ans ) ;
            }
        }
    }
    return 0 ;
}
