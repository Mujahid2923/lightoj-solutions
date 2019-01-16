#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#define white 0
#define red 1
#define blue 2

vector<ll > adj[100005];
ll visited[100005];

vector<ll>r;
vector<ll>h;

ll BFS(ll s)
{
    r.clear();
    h.clear();
    queue<ll>Q;
    Q.push(s);
    visited[s]=red;
    r.push_back(s);
    // cout<<"red "<<s<<endl;

    while(!Q.empty())
    {
        ll u=Q.front();
        Q.pop();

        ll siz=adj[u].size();

        for(ll i=0; i<siz; i++)
        {
            ll v=adj[u][i];
            if(visited[v]==white)
            {
                Q.push(v);
                if(visited[u]==red)
                {
                    visited[v]=blue;
                    h.push_back(v);
                    //   cout<<"blue "<<v<<endl;
                }
                else
                {
                    visited[v]=red;
                    r.push_back(v);
                    //  cout<<"red "<<v<<endl;
                }
            }
        }
    }
    // cout<<r.size()<<" "<<h.size()<<endl;
    ll x=max(r.size(),h.size());
    // cout<<x<<endl;
    r.clear();
    h.clear();
    return x;
}

int main()
{
    ll t,a,b,s;
    set <ll> st;
    cin>>t;
    for(ll k=1; k<=t; k++)
    {
        memset(visited,white,sizeof visited);
        ll sum=0;
        scanf("%lld",&s);
        for(ll i=0; i<s; i++)
        {
            scanf("%lld %lld",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            st.insert(a);
            st.insert(b);
        }

        set < ll > :: iterator it;

        for(it = st.begin(); it != st.end(); it++)
        {
            //cout<<*it<<" ";
            if(visited[*it]==white)
            {
                //cout<<*it<<" ";
                ll f=BFS(*it);
                sum=sum+f;
            }
        }
        printf("Case %lld: %lld\n",k,sum);



        for(ll i=0; i<100005; i++)
        {
            adj[i].clear();
        }
        st.clear();
    }

    return 0;
}
/*
final:
4
8
1 2
2 3
3 4
3 5
6 7
7 8
7 9
7 10

1
100 200

3
1 10
10 20
5 40

1
5 40

correct output:
Case 1: 7
Case 2: 1
Case 3: 3
Case 4: 1

*/
