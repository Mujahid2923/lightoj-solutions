///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///
#include<bits/stdc++.h>
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

vi adj[105];
vi vec1,vec2;
int cost[105][105];
int visited[105];

void BFS(int s)
{
    ms(visited,0);
    queue<int>q;
    vec1.pb(s);
    visited[s]=1;
    int x=adj[s][0];
    visited[x]=1;
    q.push(x);
    vec1.pb(x);



    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                vec1.pb(v);
                q.push(v);
            }
        }
    }
}

int main()
{
    int t,k,n,a,b,c,i;
    scin(t);
    RUN_CASE(k,t)
    {
        scin(n);
        RUN_CASE(i,n)
        {
            scin2(a,b);
            scin(c);
            adj[a].pb(b);
            adj[b].pb(a);
            cost[a][b]=c;
            cost[b][a]=-1;
        }

        BFS(1);
        int p=0,q=0;
        for(int i=1; i<vec1.size(); i++)
        {
            int x=vec1[i-1];
            int y=vec1[i];
            if(i==vec1.size()-1)
            {
                int s=vec1[i];
                int t=vec1[0];
                if(cost[s][t]==-1)
                {
                    p+=cost[t][s];
                }
            }
            if(cost[x][y]==-1)
            {
                p+=cost[y][x];
            }
        }


        vec2=vec1;
        reverse(vec2.begin(),vec2.end());

        for(int i=1; i<vec2.size(); i++)
        {
            int x=vec2[i-1];
            int y=vec2[i];

            if(i==vec2.size()-1)
            {
                int s=vec2[i];
                int t=vec2[0];
                if(cost[s][t]==-1)
                {
                    q+=cost[t][s];
                }
            }
            if(cost[x][y]==-1)
            {
                q+=cost[y][x];
            }
        }
        pf("Case %d: %d\n",k,min(p,q));
        vec1.clear();
        vec2.clear();
        for(int i=0; i<=n; i++)
        {
            adj[i].clear();
        }
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                cost[i][j]=0;
            }
        }
    }
    return 0;
}
