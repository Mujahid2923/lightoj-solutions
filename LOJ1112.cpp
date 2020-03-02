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

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

#define MAX 100000
ll Tree[ MAX * 4 ] ;
ll arr[ MAX ];

void init( int node,int b,int e )
{
    int Lnode = node << 1 ;
    int Rnode= ( node << 1 ) + 1 ;
    int mid= ( b + e ) >> 1 ;

    if( b == e )
    {
        Tree[ node ] = arr[ b ] ;
        return ;
    }


    init( Lnode, b, mid ) ;
    init( Rnode, mid + 1, e ) ;

    Tree[ node ] = Tree[ Lnode ] + Tree[ Rnode ] ;
}

int query( int node, int b, int e, int i, int j )
{
    int Lnode = node << 1 ;
    int Rnode= ( node << 1 ) + 1 ;
    int mid= ( b + e ) >> 1 ;

    if( b > j || e < i )
    {
        return 0 ;
    }

    if( b >= i && e <= j )
    {
        return Tree[ node ] ;
    }

    int s1 = query( Lnode, b, mid, i, j ) ;
    int s2 = query( Rnode, mid + 1, e, i, j ) ;

    return s1 + s2 ;

}


void update( int node, int b, int e, int i, int newvalue )
{
    int Lnode = node << 1 ;
    int Rnode= ( node << 1 ) + 1 ;
    int mid= ( b + e ) >> 1 ;

    if( i > e || i < b )
    {
        return ;
    }

    if( b >= i && e <= i )
    {
        Tree[ node ] += newvalue ;
        return ;
    }

    update( Lnode, b, mid, i, newvalue ) ;
    update( Rnode, mid + 1, e, i, newvalue ) ;

    Tree[ node ] = Tree[ Lnode ] + Tree[ Rnode ] ;

}


int main()
{
    int t, n, q, ck, a, val, b ;
    scin( t ) ;
    for( int k = 1 ; k <= t ; k ++ )
    {
        scin2( n, q ) ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            scln( arr[ i ] ) ;
        }

        init( 1, 1, n ) ;
        printf( "Case %d:\n", k ) ;
        for( int i = 0 ; i < q ; i ++ )
        {
            scin( ck ) ;
            if( ck == 1 )
            {
                scin( a ) ;
                int ans = query( 1, 1, n, a + 1, a + 1 );
                printf( "%d\n", ans ) ;
                update( 1, 1, n, a + 1, -ans );
            }
            else if(ck == 2 )
            {
                scin2( a, val ) ;
                update( 1, 1, n, a + 1, val );

            }
            else
            {
                scin2( a, b ) ;
                int ans = query( 1, 1, n, a + 1, b + 1 ) ;
                printf( "%d\n", ans ) ;
            }
        }
        zero( arr ) ;
        zero( Tree ) ;
    }
    return 0;
}
