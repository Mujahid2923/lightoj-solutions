#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
int visited[1000];
int node,edge;
int distance1[100];
int distance2[100];
int result[100];

void BFS(int s,int level[])
{
    for(int i=0; i<node; i++)
    {
        visited[i]=0;
        level[i]=0;
    }

    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    level[s]=0;



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
                level[v]=level[u]+1;
            }
        }
    }
}

int main()
{
    int s,d;
    int t,a,b;
    cin>>t;

    for(int k=1; k<=t; k++)
    {
        cin>>node>>edge;
        for(int i=0; i<edge; i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cin>>s>>d;
        BFS(s,distance1);
        BFS(d,distance2);
        int ans=-1;
        for(int i=0;i<node;i++)
        {
            result[i]=distance1[i]+distance2[i];
        }

        sort(result,result+node);
        ans=result[node-1];

        printf("Case %d: %d\n",k,ans);

        for(int i=0; i<node; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}

