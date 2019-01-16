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

vector<int>graph[10005];
int visited[1005];
vector<int>v;
map<int,int>mp;

void BFS(int s)
{
    memset(visited,0,sizeof visited);
    queue<int>q;
    q.push(s);
    visited[s]=1;
    mp[s]++;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            int v=graph[u][i];
            if(visited[v]==0)
            {
                q.push(v);
                visited[v]=1;
                mp[v]++;
            }
        }
    }
}

int main()
{
    int t,k,n,m,a,b;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int cnt=0;
        scanf("%d %d %d",&k,&n,&m);
        for(int j=0; j<k; j++)
        {
            int a;
            scanf("%d",&a);
            v.push_back(a);
        }
        for(int j=0; j<m; j++)
        {
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
        }
        for(int j=0; j<v.size(); j++)
        {
            BFS(v[j]);
        }
        int f=0;
        for(int j=1; j<=n; j++)
        {
            if(mp[j]==k)
            {
                f++;
            }
        }
        printf("Case %d: %d\n",i,f);

        for(int j=0; j<n; j++)
        {
            graph[j].clear();
            visited[j]=0;
        }
        v.clear();
        mp.clear();
    }
}
/*
2
3 5 4
1
1
1
1 2
1 4
2 3
3 5
3 5 4
1
1
5
1 2
1 4
2 3
3 5
ans:5
1
*/
