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

ll row, col ;
ll visited[ 205 ][ 205 ] ;
ll level[ 205 ][ 205 ] ;
char s[ 205 ][ 205 ] ;

void forJ( ll x, ll y )
{
    for( int i = 0 ; i < 4 ; i ++ )
    {
        ll xx = x + fx[ i ] ;
        ll yy = y + fy[ i ] ;
        if( xx >= 1 && xx <= row && yy >= 1 && yy <= col && s[ xx ][ yy ] == '.' )
        {
            level[ xx ][ yy ] = level[ x ][ y ] + 1 ;
            s[ xx ][ yy ] = 'J' ;
        }
    }
}

void forF( ll x, ll y )
{
    for( int i = 0 ; i < 4 ; i ++ )
    {
        ll xx = x + fx[ i ] ;
        ll yy = y + fy[ i ] ;
        if( xx >= 1 && xx <= row && yy >= 1 && yy <= col && s[ xx ][ yy ] == '.' || s[ xx ][ yy ] == 'J' )
        {
            s[ xx ][ yy ] = 'F' ;
        }
    }
}

//void print()
//{
//    cout << endl ;
//    for( int i = 1 ; i <= row ; i ++ )
//    {
//        for( int j = 1 ; j <= col ; j ++ )
//        {
//            cout << s[ i ][ j ] ;
//        }
//        cout << endl ;
//    }
//    cout << endl ;
//}

ll checking()
{
    ll ok = 0 ;
    for( int i = 1 ; i <= row ; i ++ )
    {
        for( int j = 1 ; j <= col ; j ++ )
        {
            if( s[ i ][ j ] == 'J' )
            {
                ok ++ ;
            }
            if( ( i == 1 || j == 1 || i == row || j == col ) && s[ i ][ j ] == 'J' )
            {
                return level[ i ][ j ] + 1 ;
                i = row ;
                j = col ;
            }
        }
    }
    if( ok == 0 )
    {
        return -1 ;
    }

    return 0 ;
}


int main()
{
    CIN ;
    ll t, a, b, c, n ;
    cin >> t ;

    for( int k = 1 ; k <= t ; k ++ )
    {
        cin >> row >> col ;

        for( int i = 1 ; i <= row ; i ++ )
        {
            for( int j = 1 ; j <= col ; j ++ )
            {
                cin >> s[ i ][ j ] ;
            }
        }

        ll ck = 0 ;

        while( 1 )
        {
            ll x = checking() ;
            if( x != 0 )
            {
                ck = x ;
                break ;
            }

            for( int i = 1 ; i <= row ; i ++ )
            {
                for( int j = 1 ; j <= col ; j ++ )
                {
                    if( s[ i ][ j ] == 'J' )
                    {
                        vec.pb( { i, j } ) ;
                    }
                }
            }

            for( auto x : vec )
            {
                forJ( x.first, x.second ) ;
                //print() ;
            }

            vec.clear() ;

            for( int i = 1 ; i <= row ; i ++ )
            {
                for( int j = 1 ; j <= col ; j ++ )
                {
                    if( s[ i ][ j ] == 'F' )
                    {
                        vec.pb( { i, j } ) ;
                    }
                }
            }

            for( auto x : vec )
            {
                forF( x.first, x.second ) ;
                //print() ;
            }
            vec.clear() ;

        }


        if( ck == -1 )
        {
            pf( "Case %d: IMPOSSIBLE\n",k ) ;
        }
        else
        {
            pf( "Case %d: %lld\n",k, ck ) ;
        }
        zero( level ) ;
    }


    return 0 ;
}
