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


#define white 0
#define red 1
#define blue 2

vl adj[100005];
ll visited[100005];

vl r,h;

ll BFS(ll s)
{
    r.clear();
    h.clear();
    queue<ll>Q;
    Q.push(s);
    visited[s]=red;
    r.push_back(s);

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
                }
                else
                {
                    visited[v]=red;
                    r.push_back(v);
                }
            }
        }
    }

    ll x=max(r.size(),h.size());
    return x;
}

int main()
{
    ll t,a,b,s;
    set <ll> st;
    scin(t);
    for(ll k=1; k<=t; k++)
    {
        memset(visited,white,sizeof visited);
        ll sum=0;
        scln(s);
        for(ll i=0; i<s; i++)
        {
            scln2(a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            st.insert(a);
            st.insert(b);
        }



        for(auto x : st)
        {
            if(visited[x]==white)
            {
                ll f=BFS(x);
                sum=sum+f;
            }
        }
        pf("Case %lld: %lld\n",k,sum);



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
