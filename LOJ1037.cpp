
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
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          eb                     emplace_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scin3(x,y,z)           scanf("%d %d %d",&(x),&(y),&(z))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          scln3(x,y,z)           scanf("%lld %lld %lld",&(x),&(y),&(z))
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
#define          segment_tree           int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;

int Set( int n, int pos )
{
    return n = n | ( 1 << pos ) ;
}
int reset( int n, int pos )
{
    return n = n & ~( 1 << pos ) ;
}
bool check( int n, int pos )
{
    return (bool) ( n & ( 1 << pos ) ) ;
}

int test, n ;
string s ;
int dp[ 1 << 15 ] ;
int damage[ 15 ][ 15 ] ;
int health[ 15 ] ;

void Reset()
{
    memset( dp, -1, sizeof dp ) ;
}

void Input()
{
    cin >> n ;
    for( int i = 0 ; i < n ; i ++ )
    {
        cin >> health[ i ] ;
    }

    for( int i = 0 ; i < n ; i ++ )
    {
        cin >> s ;
        for( int j = 0 ; j < n ; j ++ ) damage[ i ][ j ] = s[ j ] - '0' ;
    }
}

int Fun( int mask )
{
    if( mask == ( 1 << n ) - 1 ) return 0 ;
    if( dp[ mask ] != -1 ) return dp[ mask ] ;

    int profit = 1e9 ;

    for( int i = 0 ; i < n ; i ++ ) /// i is the targets number
    {
        if( !( mask & ( 1 << i ) ) )
        {
            int power = 1 ;
            for( int j = 0 ; j < n ; j ++ )  /// j is the weapon of target i
            {
                if( ( mask & ( 1 << j ) ) ) power = max( power, damage[ j ][ i ] ) ;
            }

            int val = ceil( health[ i ] * 1.0 / power ) ;
            profit = min( profit, val + Fun( mask | ( 1 << i ) ) ) ;
        }
    }
    return dp[ mask ] = profit ;
}


void Calculation()
{
    int ans = Fun( 0 ) ;
    printf( "Case %d: %d\n", ++ test, ans ) ;
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
    while( t-- ) solve() ;

    return 0 ;
}




-> The answer will be some permutation of the n person
-> In bitmask dp , the condition For killing will be :
take the one For maximum damage among the already killed ones and kill with that


There is an agent who is going to run a mission, he is going to meet up to 15 targets
and the agents must kill them all. When he kills a target, he can use the target weapon
to kill the other person. So he had to have a sequence of killings that allowed him
to shoot the least number of times. Now give you a table that represents how much damage
each weapon can inflict on each target. And you know the amount of blood For each target.
When the target is blood volume is Less than or Equal to 0, it means the target has been
killed. At first, the agent had only one gun, and the gun could inflict 1 damage on a target.
Problem Analysis: First of all the damage caused by the enemy pre-processing,
and then a memory Search.

My explanation :
1
3
3 5 7
030
500
007

At the beginnig the agent has weapon with strength 1 1 1 ( means always damage 1 )

here , the 1st target has weapon with strength 0 3 0
here , the 2nd target has weapon with strength 5 0 0
here , the 3rd target has weapon with strength 0 0 7

If I kill targer 1 then I can use 1st target weapon with strength 0 3 0 to kill other targets
and so on .



For example :
4
20 22 27 20
0  1  1  7 <- 1st
0  0  0  0 <- 2nd
4  0  9  8 <- 3rd
0  2  5  0 <- 4th

We will have to permute the order to kill all of them
If we kill by the order 1 4 3 2 then the ans is optiomal.

First , He has his own weapon with strength 1.
So, strength is -> 1  1  1  1
He kill the 1st with cost ( 1 * 20 ) ( 20 >= 20 ) = 20 and
then strength is -> 1  1  1  7 ( maximum comparing with the previous )
He kill the 4th with cost ( 7 * 3 ) ( 21 >= 20 ) = 3 and
then strength is -> 1  2  5  7 ( maximum comparing with the previous )
He kill the 3rd with cost ( 5 * 6 ) ( 30 >= 27 ) = 6 and
then strength is -> 4  2  9  8 ( maximum comparing with the previous )
Finally, He kill the 2nd with cost ( 2 * 11 ) ( 22 >= 22 ) = 11 and
then strength is -> 4  2  9  8 ( maximum comparing with the previous )

The ans is - > 20 + 3 + 6 + 11 = 40




