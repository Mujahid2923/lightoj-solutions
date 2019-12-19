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
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
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

ll arr[ 1005 ] ;
ll visited[ 1005 ] ;
ll val = 0 ;
ll divide = 0 ;

void bfs( ll s )
{
    val += arr[ s ] ;
    divide ++ ;
    visited[ s ] = 1 ;
    queue < ll > Q ;
    Q.push( s ) ;
    //cout << s << " " ;

    while( !Q.empty() )
    {
        ll u = Q.front() ;
        Q.pop() ;

        for( int i = 0 ; i < adj[ u ].size() ; i ++ )
        {
            ll v = adj[ u ][ i ] ;
            if( visited[ v ] == 0 )
            {
                //cout << v << " " ;
                val += arr[ v ] ;
                divide ++ ;
                visited[ v ] = 1 ;
                Q.push( v ) ;
            }
        }

    }
}


int main()
{
    CIN ;
    //output ;
    ll t, n, a, b, m ;
    cin >> t ;

    for( int k = 1 ; k <= t ; k ++ )
    {
        cin >> n >> m ;

        ll sum = 0, ck = 0 ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            cin >> arr[ i ] ;
            sum += arr[ i ] ;
        }

        if( sum % n != 0 )
        {
            for( int i = 1 ; i <= m ; i ++ )
            {
                cin >> a >> b ;
                adj[ a ].pb( b ) ;
                adj[ b ].pb( a ) ;
            }
            ck = 1 ;
        }
        else
        {
            sum /= n ;
            for( int i = 1 ; i <= m ; i ++ )
            {
                cin >> a >> b ;
                adj[ a ].pb( b ) ;
                adj[ b ].pb( a ) ;
            }

            for( int i = 1 ; i <= n ; i ++ )
            {
                if( visited[ i ] == 0 )
                {
                    bfs( i ) ;
                    //cout << endl << sum << " " << divide << " " << val << endl;
                    if( val / divide != sum || val % divide != 0 )
                    {
                        ck = 1 ;
                        break ;
                    }
                }
            }
        }

        if( ck )
        {
            pf( "Case %d: No\n",k ) ;
        }
        else
        {
            pf( "Case %d: Yes\n",k ) ;
        }

        for( int i = 1 ; i <= n ; i ++ )
        {
            adj[ i ].clear() ;
        }
        zero( visited ) ;
        val = 0 ;
        divide = 0 ;
    }


    return 0 ;
}
