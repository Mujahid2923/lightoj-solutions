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
#define       zero(a)              memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


vector<pair<string,string> >vec;
set<string>st;
map<string,int>Mp;
vector<int>adj[10005];
int visited[100005];
int Cycle=0;

void arrayCompression()
{
    int cnt=1;
    for(auto s : st)
    {
        Mp[s]=cnt++;
    }
}

void checkCycle(int s)
{
    visited[s]=1;
    for(int i=0; i<adj[s].size(); i++)
    {
        int v=adj[s][i];
        if(visited[v]==0)
        {
            checkCycle(v);
        }
        else if(visited[v]==1)
        {
            Cycle=1;
            return;
        }
    }
    visited[s]=2;
}

int main()
{
    //output;
    //input;
    int t,n;
    string s1,s2;
    scin(t);
    for(int k=1; k<=t; k++)
    {
        scin(n);
        for(int i=1; i<=n; i++)
        {
            cin>>s1>>s2;
            vec.pb(mp(s1,s2));
            st.insert(s1);
            st.insert(s2);
        }

        arrayCompression();

        for(int i=0; i<n; i++)
        {
            adj[Mp[vec[i].first]].pb(Mp[vec[i].second]);
        }

        zero(visited);

        for(int i=1;i<=st.size();i++)
        {
            if(Cycle==1)
            {
                break;
            }
            if(visited[i]==0)
            {
                checkCycle(i);
            }
        }

        if(Cycle==1)
        {
            pf("Case %d: No\n",k);
        }
        else
        {
            pf("Case %d: Yes\n",k);
        }

        Cycle=0;
        for(int i=1; i<=st.size(); i++)
        {
            adj[i].clear();
        }
        Mp.clear();
        st.clear();
        vec.clear();
    }
    return 0;
}





/*
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
#define       zero(a)              memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


vector<pair<string,string> >vec;
set<string>st;
map<string,int>Mp;
vector<int>adj[10005];
int visited[100005];
int cnt=0,Cycle=0;


void checkCycle(int u)
{
    visited[u]=1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(visited[v]==0)
        {
            checkCycle(v);
        }
        else if(visited[v]==1)
        {
            Cycle=1;
            return;
        }
    }
    visited[u]=2;
}

int main()
{
    //output;
   // input;
    int t,n;
    string s1,s2;
    scin(t);
    for(int k=1; k<=t; k++)
    {
        scin(n);
        for(int i=1; i<=n; i++)
        {
            cin>>s1>>s2;
            if(!Mp[s1])
                Mp[s1]=++cnt;
            if(!Mp[s2])
                Mp[s2]=++cnt;
            adj[Mp[s1]].pb(Mp[s2]);
        }

        zero(visited);
        Cycle=0;

        for(int i=1; i<=cnt; i++)
        {
            if(Cycle==1)
            {
                break;
            }
            if(visited[i]==0)
            {
                checkCycle(i);
            }
        }

        if(Cycle==1)
        {
            pf("Case %d: No\n",k);
        }
        else
        {
            pf("Case %d: Yes\n",k);
        }

        for(int i=1; i<=cnt; i++)
        {
            adj[i].clear();
        }
        Mp.clear();
        st.clear();
        vec.clear();
        cnt=0;
    }
    return 0;
}

*/
