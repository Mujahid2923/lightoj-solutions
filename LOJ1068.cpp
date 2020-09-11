
///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          eb                     emplace_back
#define          sc                     scanf
#define          pf                     printf
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
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
#define          segment_tree           int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;

vector < int > v ;
int T, a, b, k ;
int dp[ 12 ][ 102 ][ 102 ][ 2 ] ;

void Reset() { }

void Input()
{
    cin >> a >> b >> k ;
}

int Fun( int pos, int moddig, int modnum, int small )
{
    if( pos == v.size() ) return ( moddig == 0 && modnum == 0 ) ;
    if( dp[ pos ][ moddig ][ modnum ][ small ] != -1 ) return dp[ pos ][ moddig ][ modnum ][ small ] ;

    int res = 0, mxdig ;

    if( small ) mxdig = 9 ;
    else mxdig = v[ pos ] ;


    for( int i = 0 ; i <= mxdig ; i ++ )
    {
        //cout << pos<< " " << i << " " << " " << mxdig << " " << small << endl ;
        res += Fun( pos + 1, ( moddig + i ) % k, ( modnum * 10 + i ) % k, ( i < mxdig || small ) ) ;
    }

    return dp[ pos ][ moddig ][ modnum ][ small ] = res ;
}

int CAL( int n )
{
    memset( dp, -1, sizeof dp ) ;
    v.clear() ;
    while( n )
    {
        v.pb( n % 10 ) ;
        n /= 10 ;
    }
    reverse( all( v ) ) ;
    return Fun( 0, 0, 0, 0 ) ;
}

void Calculation()
{
    int ans ;
    if( k > 99 ) ans = 0 ;
    else ans = CAL( b ) - CAL( a - 1 ) ;
    pf( "Case %d: %d\n", T, ans ) ;
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    int t ;
    cin >> t ;
    while( t-- )
    {
        T ++ ;
        solve() ;
    }

    return 0 ;
}

/// https://www.geeksforgeeks.org/digit-dp-introduction/

/*
Suppose,
We have to find the value till 23

if , small = 1 , maximum digit = 9
else if small = 0 , maximum digit = v[ i ] or ( 2 for index '1' and 3 for index '2' )

At first , small = 0 , then mxdig = 2 ( from 0, 1, 2 )
when 0 then as it samller than mxdig , so it make small = 1 , now next digit move [ 0 - 9 ]
then, as 1 and samller than mxdig, small = 1 , now next digit move [ 0 - 9 ]
then as 2 is equal then small = 0, now next digit move [ 0 - v[ i ]( means 3 ) ]

That's how keep's going on
*/

