#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>adj[30005];
vector<int>cost[30005];

int visited[30005];
ll Dist[30005];
int n;

int BFS(int s)
{
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
        Dist[i]=0;
    }

    Dist[s]=0;
    visited[s]=1;
    queue<int>Q;
    Q.push(s);


    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                Q.push(v);
                Dist[v]=Dist[u]+cost[u][i];
            }
        }
    }
    int index=0;
    ll mx=0;
    for(int i=0; i<n; i++)
    {
        if(Dist[i]>mx)
        {
            mx=Dist[i];
            index=i;
        }
    }
    return index;
}



int main()
{
    int t,u,v,w;
    scanf("%d",&t);
    for(int k=1; k<=t; k++)
    {
        scanf("%d",&n);
        for(int i=0; i<n-1; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        int x=BFS(0);

        ll result=BFS(x);
        printf("Case %d: %lld\n",k,Dist[result]);

        for(int i=0; i<n; i++)
        {
            adj[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

