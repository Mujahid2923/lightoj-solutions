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
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
///sort( all( v ) ) ;

char s[ 20 ][ 20 ] ;
int visited[ 20 ][ 20 ] ;
int row, col ;

bool isValid( int x, int y )
{
    if(x >= 0 && x < row && y >= 0 && y < col && visited[ x ][ y ] == 0 && s[ x ][ y ] == '.' )
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

void BFS( int x,int y )
{
    visited[ x ][ y ] = 1;
    queue< pii > Q ;
    Q.push( mp( x, y ) ) ;

    while( !Q.empty() )
    {
        x = Q.front().first ;
        y = Q.front().second ;
        Q.pop() ;
        for(int i = 0 ; i < 4 ; i++)
        {
            int xx = x + fx[ i ] ;
            int yy = y + fy[ i ] ;

            if(isValid( xx, yy ) )
            {
                visited[ xx ][ yy ] = 1;
                Q.push( mp( xx, yy ) ) ;
            }
        }
    }
}

int main()
{
    int t ;
    cin >> t ;

    for(int k = 1 ; k <= t ; k ++ )
    {
        int cnt = 0 ;
        cin >> col >> row ;
        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                cin >> s[i][j];
            }
        }

        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                if( s[ i ][ j ] == '@' )
                {
                    BFS( i, j ) ;
                    break ;
                }
            }
        }



        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                if( visited[ i ][ j ] == 1 )
                {
                    cnt ++ ;
                }
            }
        }

        pf("Case %d: %d\n", k, cnt ) ;
        zero( visited ) ;
    }
    return 0;
}

