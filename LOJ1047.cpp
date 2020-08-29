ll n, a, b, c, test ;
ll arr[ 25 ][ 5 ] ,dp[ 25 ][ 5 ] ;

void Reset()
{
    zero( dp ) ;
}

void Input()
{
    scanf( "%lld", &n ) ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= 3 ; j ++ )
        {
            scanf( "%lld", &arr[ i ][ j ] ) ;
        }
    }
}

void Calculation()
{
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= 3 ; j ++ )
        {
            if( j == 1 ) dp[ i ][ j ] = min( arr[ i ][ j ] + dp[ i - 1 ][ 2 ], arr[ i ][ j ] + dp[ i - 1 ][ 3 ] ) ;
            if( j == 2 ) dp[ i ][ j ] = min( arr[ i ][ j ] + dp[ i - 1 ][ 1 ], arr[ i ][ j ] + dp[ i - 1 ][ 3 ] ) ;
            if( j == 3 ) dp[ i ][ j ] = min( arr[ i ][ j ] + dp[ i - 1 ][ 1 ], arr[ i ][ j ] + dp[ i - 1 ][ 2 ] ) ;
        }
    }
    pf( "Case %lld: %lld\n", ++ test , min( { dp[ n ][ 1 ], dp[ n ][ 2 ], dp[ n ][ 3 ] } ) ) ;
}


---------------------------------------------------***************************---------------------------------------------

#include<bits/stdc++.h>
using namespace std;

vector < int > adj[ 5 ] ;
int DP[ 50 ][ 5 ] ;
int t, n, a, b, c ;

int Fun( int pos, int ck )
{
    if( pos < 0 )  return 0 ;
    if( DP[ pos ][ ck ] != -1 ) return DP[ pos ][ ck ] ;
    int ans = INT_MAX ;
    if( ck == 1 )
    {
        ans = min( ans, adj[ 2 ][ pos ] + Fun( pos - 1, 2 ) ) ;
        ans = min( ans, adj[ 3 ][ pos ] + Fun( pos - 1, 3 ) ) ;
        return DP[ pos ][ ck ] = ans ;
    }
    else if( ck == 2 )
    {
        ans = min( ans, adj[ 1 ][ pos ] + Fun( pos - 1, 1 ) ) ;
        ans = min( ans, adj[ 3 ][ pos ] + Fun( pos - 1, 3 ) ) ;
        return DP[ pos ][ ck ] = ans ;
    }
    else if( ck == 3 )
    {
        ans = min( ans, adj[ 1 ][ pos ] + Fun( pos - 1, 1 ) ) ;
        ans = min( ans, adj[ 2 ][ pos ] + Fun( pos - 1, 2 ) ) ;
        return DP[ pos ][ ck ] = ans ;
    }
}
---------------------------****************----------------------------------------
int Fun( int pos, int ck )
{
    if( pos < 0 ) return 0 ;
    if( DP[ pos ][ ck ] != -1 ) return DP[ pos ][ ck ] ;

    int ans = INT_MAX ;
    for( int i = 1 ; i <= 3 ; i ++ )
    {
        if( ck != i ) ans = min( ans, adj[ i ][ pos ] + Fun( pos - 1, i ) ) ;
    }
    return DP[ pos ][ ck ] = ans ;
}

-------------------------------*************--------------------------------------
int main()
{

    scin( t ) ;
    for( int k = 1 ; k <= t ; k ++ )
    {
        memset( DP, -1, sizeof DP ) ;
        scin( n ) ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            scin3( a, b, c ) ;
            adj[ 1 ].pb( a ) ;
            adj[ 2 ].pb( b ) ;
            adj[ 3 ].pb( c ) ;
        }
        int ans = INT_MAX ;
        for( int i = 1 ; i <= 3 ; i ++ )  ans = min( ans, Fun( n - 1, i ) ) ;
        pf("Case %d: %d\n", k, ans ) ;

        for( int i = 1 ; i <= n ; i ++ )  adj[ i ].clear() ;
    }
    return 0 ;
}


