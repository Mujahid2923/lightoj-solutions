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
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
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
int arr[102];

vector<int>v,g,f;

void findPrime()
{
    int n=1000;
    bool prime[n+1];
    memset(prime,false,sizeof prime);

    for(int i=4; i<=n; i+=2)
    {
        prime[i]=true;
    }

    prime[1]=true;

    for(int i=3; i*i<=n; i+=2)
    {
        if(prime[i]==false)
        {
            for(int j=2; i*j<=n; j++)
            {
                prime[i*j]=true;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(prime[i]==false)
        {
            v.push_back(i);
        }
    }
}

void fact()
{
    for(int i=1; i<=100; i++)
    {
        g.push_back(i);
    }
}

int main()
{
    findPrime();
    fact();
    int t,n;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        f=g;
        bool ck=false;
        memset(arr,0,sizeof arr);
        cin>>n;
        for(int j=1; j<n; j++)
        {
            for(int i=0; v[i]<=f[j]; i++)
            {
                //cout<<f[j]<<" "<<v[i]<<endl;
                while(f[j]%v[i]==0)
                {
                    arr[v[i]]++;
                    f[j]=f[j]/v[i];
                }
            }
        }
        printf("Case %d: %d = ",k,n);
        for(int i=1; i<=n; i++)
        {
            if(arr[i]!=0)
            {
                if(ck)
                {
                    printf(" * ");
                }
                printf("%d (%d)",i,arr[i]);
                ck=true;
            }
        }
        cout<<endl;
        f.clear();
    }
}

------------------------------------------------------Same Solution-------------------------------------------------------------------
    
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


vector < int > v, vec ;
map < int, int > Mp ;
set < int > st;

void findPrime( int n )
{
    bool prime[n];
    memset( prime, false, sizeof prime ) ;

    for( int i = 4 ; i <= n ; i += 2 )
    {
        prime[ i ] = true ;
    }

    prime[1] = true ;

    for( int i = 3 ; i*i <= n ; i+= 2 )
    {
        if(!prime[i])
        {
            for( int j = 2 ; i*j <= n ; j++ )
            {
                prime[ i*j ] = true ;
            }
        }
    }

    for( int i = 1 ; i <= n ; i++ )
    {
        if( !prime[i] )
        {
            v.pb( i );
        }
    }
}

int main()
{
    output;
    findPrime(10000) ;
    int t, x, n;
    cin >> t;

    for( int k = 1 ; k <= t ; k++ )
    {
        cin >> x ;

        for( int j = 1 ; j <= x ; j++ )
        {
            n = j ;

            for( int i = 0 ; v[i]*v[i] <= n ; i++ )
            {
                while( n % v[i] == 0 )
                {
                    n = n / v[i] ;
                    vec.pb( v[i] ) ;
                }
            }

            if( n > 1 )
            {
                vec.pb( n ) ;
            }
        }

        sort( all(vec) ) ;

        for( int i = 0 ; i < vec.size() ; i++ )
        {
            Mp[ vec[i] ]++;
        }

        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );

        pf("Case %d: %d = ", k, x ) ;

        for( int i = 0 ; i < vec.size() ; i++ )
        {
            if( i == vec.size()-1 )
                pf("%d (%d)\n", vec[i], Mp[ vec[i] ]);
            else
                pf("%d (%d) * ", vec[i], Mp[ vec[i] ]);
        }
        vec.clear() ;
        Mp.clear() ;
    }
    return 0;
}

---------------------------------**************----------------------------------------
    
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

vector< ll > v, vec ;
const int MAXN = 100 ;
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
map < ll, ll > Mp ;

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
            Mp[ v[ i ] ] += cnt ;
        }
    }

    if( n > 1 )
    {
        st.insert( n ) ;
        Mp[ n ] ++ ;
    }
}


int main()
{
    CIN ;
    findPrime();
    ll t, n, m ;
    cin >> t ;
    for( int k = 1 ; k <= t ; k ++ )
    {
        cin >> n ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            primeFactorization( i ) ;
        }


        for( auto x : st )
        {
            vec.pb( x ) ;
        }

        pf("Case %d: %d = ", k, n ) ;

        for( int i = 0 ; i < vec.size() ; i++ )
        {
            if( i == vec.size() - 1 )
            {
                pf("%lld (%lld)\n", vec[ i ], Mp[ vec[ i ] ] ) ;
            }
            else
            {
                pf("%lld (%lld) * ", vec[ i ], Mp[ vec[ i ] ] );
            }
        }

        st.clear() ;
        Mp.clear() ;
        vec.clear() ;
    }

    return 0;
}

    
