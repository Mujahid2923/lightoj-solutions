a  b c   lcm
12 6 ?    900
prime factorization of 900 = 2^2 3^2 5^2

prime factorization of 12 = 2^2 3
prime factorization of 6 = 2 3
    maximum element ( means lcm ) = 2^3 3
    So...power of 3 and 5 is less...We have to fullform that..by taking 3^2 5^2..
    Finally we get c ..that is 3^2 5^2 = 225

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
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Upper(c,x)           (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)           (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)             (X).erase(unique(all(X)),(X).end())

///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

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


vector< ll > v ;
const int MAXN = 1e6 ;
bitset< MAXN > status ;

void findPrime()
{
    int rt = sqrt( MAXN ) + 1 ;

    for( int i = 3 ; i < rt ; i += 2 )
    {
        if( !status[ i ] )
        {
            for( int j = i * i ; j < MAXN ; j += ( i << 1 ) )
            {
                status[j] = true;
            }
        }
    }

    v.push_back( 2 ) ;

    for( int i = 3; i < MAXN; i += 2 )
    {
        if( !status[ i ] )
        {
            v.push_back( i ) ;
        }
    }
}

set < ll > st ;
map < ll, ll > Mp, Mp2 ;

void primeFactorization2( ll n )
{
    for( int i = 0 ; v[ i ] * v[ i ] <= n ; i ++ )
    {
        ll cnt = 0 ;
        while( n % v[ i ] == 0 )
        {
            cnt ++ ;
            n = n / v[ i ] ;
        }
        if( cnt > 0 )
        {
            st.insert( v[ i ] ) ;
            Mp2[ v[ i ] ] = max( Mp2[ v[ i ] ], cnt ) ;
        }
    }

    if( n > 1 )
    {
        st.insert( n ) ;
        ll x = 1 ;
        Mp2[ n ] = max( Mp2[ n ], x ) ;
    }
}

void primeFactorization( ll n )
{
    for( int i = 0 ; v[ i ] * v[ i ] <= n ; i ++ )
    {
        ll cnt = 0 ;
        while( n % v[ i ] == 0 )
        {
            cnt ++ ;
            n = n / v[ i ] ;
        }
        if( cnt > 0 )
        {
            st.insert( v[ i ] ) ;
            Mp[ v[ i ] ] = cnt ;
        }
    }

    if( n > 1 )
    {
        st.insert( n ) ;
        Mp[ n ] = 1 ;
    }
}


int main()
{
    findPrime() ;
    CIN ;
    ll t, a, b, l ;
    cin >> t ;
    for( int i = 1 ; i <= t ; i ++ )
    {
        cin >> a >> b >> l ;
        primeFactorization( l ) ;
        primeFactorization2( a ) ;
        primeFactorization2( b ) ;

        ll ans = 1, ck = 0 ;
        for( auto x : st )
        {
            if( Mp2[ x ] > Mp[ x ] )
            {
                ck = 1 ;
                break ;
            }
            else if( Mp2[ x ] < Mp[ x ] )
            {
                for( int i = 0 ; i < Mp[ x ] ; i ++ )
                {
                    ans *= x ;
                }
            }
        }

        if( ck == 1 )
        {
            pf("Case %d: impossible\n", i ) ;
        }
        else
        {
            pf("Case %d: %lld\n", i, ans ) ;
        }
        st.clear() ;
        Mp.clear() ;
        Mp2.clear() ;
    }

    return 0;
}



---------------------------------------*****************-------------------------------------
#include<bits/stdc++.h>

///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

using namespace std;
#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define          pb(a)             push_back(a)
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       max3(a,b,c)          max(a,max(b,c))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


int main()
{
    CIN;
    ll t,ans,a,b,d,f;
    scln(t);
    for(int k=1; k<=t; k++)
    {
        scln2(a,b);
        scln(d);
        ll x=lcm(a,b);
        if(d%x==0)
        {
            ll r=d/x;
            f=gcd(d,r);
            if(f==1)
            {
                pf("Case %d: %lld\n",k,r);
            }
            else
            {
                ans=r;
                ll ck=d;
                while(ans!=ck)
                {
                    f=lcm(d,ans);
                    d=d/f;
                    ans*=f;
                }
                pf("Case %d: %lld\n",k,ans);
            }
        }
        else
        {
            pf("Case %d: impossible\n",k);
        }
    }
    return 0;
}
