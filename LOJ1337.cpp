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
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

char s[505][505];
int visited[505][505];
int cost[505][505];
int cnt=0;

bool isValid(int row,int col,int x,int y)
{
    if(x>=0 && x<row && y>=0 && y<col && visited[x][y]==0 && s[x][y]!='#')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DFS(int row,int col,int x,int y)
{
    visited[x][y]=1;

    for(int i=0; i<4; i++)
    {
        int xx=fx[i]+x;
        int yy=fy[i]+y;

        if(isValid(row,col,xx,yy))
        {
            if(s[xx][yy]=='C')
            {
                cnt++;
            }
            DFS(row,col,xx,yy);
        }
    }
}

int main()
{
    //output;
    int t,k,row,col,q,x,y;
    scin(t);
    RUN_CASE(k,t)
    {
        ms(visited,0);
        ms(cost,-1);
        scin2(row,col);
        scin(q);
        char ch;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                sc(" %c",&s[i][j]);
            }
        }

        pf("Case %d:\n",k);

        while(q--)
        {
            cnt=0;
            scin2(x,y);

            if(cost[x-1][y-1]!=-1)
            {
                pf("%d\n",cost[x-1][y-1]);
            }
            else
            {
                ms(visited,0);
                DFS(row,col,x-1,y-1);
                pf("%d\n",cnt);

                for(int i=0; i<row; i++)
                {
                    for(int j=0; j<col; j++)
                    {
                        if(visited[i][j]==1)
                        {
                            cost[i][j]=cnt;
                        }

                    }
                }
            }
        }
    }
    return 0;
}

