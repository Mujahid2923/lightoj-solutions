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

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

vi adj[105];
vi cost[105];
int distanc[105];
int node,edge;

struct Node
{
    int u,w;
    Node(int a,int b)
    {
        u=a;
        w=b;
    }
    bool operator <(const Node &p) const
    {
        return w<p.w;
    }
};

void dijkstra(int s)
{
    for(int i=1; i<=node; i++)
    {
        distanc[i]=INT_MAX;
    }

    priority_queue<Node>Q;
    distanc[s]=0;
    Q.push(Node(s,0));

    while(!Q.empty())
    {
        Node Top=Q.top();
        int u=Top.u;
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];

            if(distanc[v]>distanc[u]+cost[u][i])
            {
                //cout<<distanc[v]<<" "<<cost[u][i]<<" "<<distanc[u]<<endl;
                distanc[v]=distanc[u]+cost[u][i];
                Q.push(Node(v,distanc[v]));
            }
        }
    }
}

int main()
{
    int t,a,b,w;
    scin(t);
    for(int j=1; j<=t; j++)
    {
        scin2(node,edge);
        for(int i=0; i<edge; i++)
        {
            scin2(a,b);
            scin(w);
            adj[a].pb(b);
            adj[b].pb(a);
            cost[a].pb(w);
            cost[b].pb(w);
        }
        dijkstra(1);
        if(distanc[node]==INT_MAX)
        {
            pf("Case %d: Impossible\n",j);
        }
        else
        {
            pf("Case %d: %d\n",j,distanc[node]);
        }
        for(int i=1; i<=node; i++)
        {
            adj[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}

