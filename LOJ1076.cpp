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
#define          get_pos(vect,x)        (lower_bound(vect.begin(),vect.end(),x)-vect.begin())
#define          CASEL(t)               printf("Case %d:\n",t)

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

ll n, m ;
vl vec, v ;

ll BinSearch( ll low, ll high )
{
    ll mid, ans ;
    while( low <= high )
    {
        mid = ( low + high ) >> 1 ;
        ll cnt = 1, sum = 0 ;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            sum += v[ i ] ;
            if( sum > mid )
            {
                sum = v[ i ] ;
                cnt ++ ;
            }
        }

        // cout << cnt << " " << mid << endl ;
        if( cnt <= m )
        {
            ans = mid ;
            high = mid - 1 ;
        }
        else
        {
            low = mid + 1 ;
        }
    }
    return ans ;
}

int main()
{
    CIN ;
    ll t, a ;
    cin >> t ;

    for( int k = 1 ; k <= t ; k ++ )
    {
        cin >> n >> m ;
        ll arr[ n ] ;
        zero( arr ) ;
        ll sum = 0, mx = INT_MIN ;
        for( int i = 0 ; i < n ; i ++ )
        {
            cin >> a ;
            mx = max( mx, a) ;
            v.pb( a ) ;
            sum += a ;
        }

        ll ans = BinSearch( mx, sum ) ;


        pf("Case %d: %lld\n", k, ans ) ;
        v.clear() ;
    }

    return 0 ;
}


