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

vi adj[30005],cost[30005];
vi vec;
int visited[30005];
int dist1[30005],dist2[30005];
int n;

int BFS1(int s)
{
    ms(visited,0);
    queue<int>q;
    visited[s]=1;
    dist1[s]=0;
    q.push(s);

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
                q.push(v);
                dist1[v]=dist1[u]+cost[u][i];
            }
        }
    }
    int index=0;
    int mx=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(dist1[i]>mx)
        {
            mx=dist1[i];
            index=i;
        }
    }
    return index;
}


void BFS2(int s)
{
    ms(visited,0);
    queue<int>q;
    visited[s]=1;
    dist2[s]=0;
    q.push(s);

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
                q.push(v);
                dist2[v]=dist2[u]+cost[u][i];
            }
        }
    }
}


int main()
{
    int k,i,t,a,b,w;
    scin(t);
    RUN_CASE(k,t)
    {
        scin(n);
        RUN_CASE(i,n-1)
        {
            scin2(a,b);
            scin(w);
            adj[a].pb(b);
            adj[b].pb(a);
            cost[a].pb(w);
            cost[b].pb(w);
        }
        int x=BFS1(0);
        int y=BFS1(x);
        BFS2(y);
        for(int i=0; i<n; i++)
        {
            vec.pb(max(dist1[i],dist2[i]));
        }
        pf("Case %d:\n",k);
        for(auto x : vec)
        {
            pf("%d\n",x);
        }
        for(int i=0; i<n; i++)
        {
            adj[i].clear();
            cost[i].clear();
        }
        vec.clear();
        ms(dist1,0);
        ms(dist2,0);
    }
    return 0;
}



