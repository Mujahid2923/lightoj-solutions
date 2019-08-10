আমরা জানি, 10 based number system এ x এর ডিজিট সংখ্যা = ⌊log10x⌋+1
একইভাবে, b based number system এ x এর ডিজিট সংখ্যা = ⌊logbx⌋+1
লগারিদমের সূত্রানুসারে,
logxy = logxz * logzy
⟹logzy = logxy / logxz
∴logbn=log10n / log10b

আবার, আমরা জানি,
log10(x * y * z)=log10x+log10y+log10z
যেহেতু, n! = 1 * 2 * 3 * 4 *..........* n  , অতএব, 
log10(n!)=log101+log102+..........+log10n

অতএব, আমরা আগেই 106 পর্যন্ত সব সংখ্যার log এর মান বের করে অ্যারেতে রাখব ।
এরপরে, প্রতি কেসে শুধু n ও b এর মান ইনপুট নেব এবং ⌊log10n / log10b⌋+1 এর মান প্রিন্ট করে আউটপুটে দেখাব ।



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

vector < db > v ;

void cal()
{
    v.pb( 0 ) ;
    for( int i = 1 ; i <= 1000000 ; i ++ )
    {
        v.pb( log10( i ) + v[ i - 1 ] ) ;
    }
}

int main()
{
    cal() ;
    int t , n , b ;
    scin( t ) ;
    for( int k = 1 ; k <= t ; k ++ )
    {
        scin2( n , b ) ;
        ll x = floor( v[ n ] / log10( b ) ) + 1 ;
        pf("Case %d: %lld\n", k , x ) ;
    }

    return 0;
}

