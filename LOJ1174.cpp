///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ull                    unsigned long long int
#define          db                     double
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
#define          scin3(x,y,z)           scanf("%d %d %d",&(x),&(y),&(z))
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
#define          PI                     3.141592653589793238462643
#define          rep( i , a , b )       for( i=a ; i<b ; i++)
#define          rev( i , a , b )       for( i=a ; i>=b ; i--)
#define          repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define          RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          get_pos(c,x)           (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          CASEL(t)               printf("Case %d:\n",t)
#define          Unique(X)             (X).erase(unique(all(X)),(X).end())

///priority_queue<int,vector<int>,greater<int> >pq;

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

vector< int >adj[ 1000 ] ;
int visited[ 1000 ] ;
int node , edge ;
int Dist1[ 100 ] ;
int Dist2[ 100 ] ;
int P[ 100 ] ;

void BFS( int s , int level[] )
{
    zero( visited ) ;
    zero( level ) ;

    queue< int > Q ;
    Q.push( s );
    visited[ s ] = 1 ;
    level[ s ] = 0 ;

    while( !Q.empty() )
    {
        int u = Q.front() ;
        Q.pop() ;

        for( int i = 0 ; i < adj[ u ].size() ; i ++ )
        {
            int v = adj[ u ][ i ] ;
            if( visited[ v ] == 0 )
            {
                visited[ v ] = 1 ;
                Q.push( v ) ;
                level[ v ] = level[ u ] + 1 ;
            }
        }
    }
}

int main()
{
    int s , d ;
    int t , a , b ;
    cin >> t ;

    for( int k = 1 ; k <= t ; k ++ )
    {
        scin2( node , edge ) ;
        for( int i = 0 ; i < edge ; i ++ )
        {
            scin2( a , b ) ;
            adj[ a ].pb( b ) ;
            adj[ b ].pb( a ) ;
        }

        scin2( s , d ) ;

        BFS( s , Dist1 );
        BFS( d , Dist2 ) ;

        for( int i = 0 ; i < node ; i ++ )
        {
            P[ i ] = Dist1[ i ] + Dist2[ i ] ;
        }

        sort( P , P + node ) ;

        pf("Case %d: %d\n", k , P[ node - 1 ] );

        for( int i = 0 ; i < node ; i ++ )
        {
            adj[ i ].clear() ;
        }
    }
    return 0;
}

