
///--------Mujahidul Islam---------
///            Department of Ict
///                 " Talk is cheap. Show me the code." -Linus Torvalds



#include<bits/stdc++.h>

#define ll              long long int
#define ull             unsigned long long int
#define pii             pair < int, int>
#define pll             pair < ll, ll>
#define sc              scanf
#define scin(x)         sc("%d",&(x))
#define scln(x)         sc("%lld",&(x))
#define pf              printf
#define ms(a,b)         memset(a,b,sizeof(a))
#define pb(a)           push_back(a)
#define mp              make_pair
#define db              double
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define vi              vector< int >
#define vl              vector< ll >
#define vii             vector<vector< int > >
#define vll             vector<vector< ll > >
#define DBG             pf("HI\n")
#define MOD             1000000007
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RUN_CASE(t,T)   for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)         printf("Case %d: ",t)
#define CASEL(t)        printf("Case %d:\n",t)
#define intlimit        2147483648
#define longlimit       9223372036854775808
#define infinity        (1<<28)
#define gcd(a, b)       __gcd(a,b)
#define lcm(a, b)       ((a)*(b)/gcd(a,b))
#define mx              1234567899
#define PI              2*acos(0.0)
#define all(v)          v.begin(),v.end()
#define rep(i,a,b)      for(__typeof(i) i=a; i<=b; i++)
#define rev(i,a,b)      for(__typeof(i) i=a; i>=b; i--)

using namespace std;

//template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return sqr(POW(B,P/2));}
//ll Bigmod(ll base, ll power, ll mod){if(power==0) return 1%mod; if(power==1) return base%mod; ll x = Bigmod(base,power/2,mod); x = (x*x)%mod; if(power%2){x = (x*(base%mod))%mod;}return x;}
//ll Mulmod(ll base, ll power, ll mod){if(power==0) return 0; if(power==1) return base%mod; ll x = Mulmod(base,power/2,mod); x = (x+x)%mod; if(power%2){x = (x+(base%mod))%mod;}return x;}
//bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
//ll ModInverse(ll number, ll mod){return Bigmod(number, mod-2, mod);}
//bool isConso(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
//int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
//bool isPrime( ll val ) { if( val == 2 ) return true ; if( val % 2 == 0 || val == 1 ) return false ; ll sqrt_N = (ll) ( ( double ) sqrt( val ) ) ; for( ll i = 3 ; i <= sqrt_N ; i += 2 ) { if( val % i == 0 ) return false ; } return true ; }
//template<class T> string convert(T _input) { stringstream blah; blah << _input; return blah.str(); }

/**
// Ordered set
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
*/

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin>>n;
    vector<ll>v,A;
    for(ll i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
                v.push_back(i);
            else
            {
                v.push_back(n/i);
                v.push_back(i);
            }
        }
    }

    ll sum;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]==1)
        {
            sum=(n*(n+1))/2;
        }
        else
        {
            ll p=n/v[i];
            sum=(p*(2+(p-1)*v[i]))/2;
        }
        A.push_back(sum);
    }

    sort(A.begin(),A.end());
    for(int i=0; i<A.size(); i++)
    {
        cout<<A[i]<<" ";
    }


    return 0;
}

char s[100][100];
int visited[100][100];

int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};

vector<char>v;
vector<int>bi;
pair<int,int>p[26];
int level[100][100];

bool isvalid(int z,int x,int y,char c)
{
    if((x>=0 && x<z && y>=0 && y<z && s[x][y] !='#' && visited[x][y]==0) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BFS(int z,int x,int y,char c)
{
    for(int i=0; i<z; i++)
    {
        for(int j=0; j<z; j++)
        {
            visited[i][j]=0;
            level[i][j]=INT_MAX;
        }
    }

    queue<pii>q;
    q.push(pii(x,y));
    visited[x][y]=1;
    level[x][y]=0;

    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        int a=top.first;
        int b=top.second;

        for(int i=0; i<4; i++)
        {
            int xx=a+dx[i];
            int yy=b+dy[i];
            if(isvalid(z,xx,yy,c))
            {
                level[xx][yy]=min(level[a][b]+1,level[xx][yy]);
                q.push(pii(xx,yy));
                visited[xx][yy]=1;
            }
        }
    }
}



int main()
{
    int t,z;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int sum=0;
        cin>>z;
        for(int i=0; i<z; i++)
        {
            for(int j=0; j<z; j++)
            {
                cin>>s[i][j];
                if(s[i][j]>='A' && s[i][j]<='Z')
                {
                    v.push_back(s[i][j]);
                }
            }
        }

        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++)
        {
            for(int j1=0; j1<z; j1++)
            {
                for(int j2=0; j2<z; j2++)
                {
                    if(s[j1][j2]==v[i])
                    {
                        p[i].first=j1;
                        p[i].second=j2;
                    }
                }
            }
        }

        for(int i=0; i<v.size()-1; i++)
        {
            char ch=v[i+1];
            BFS(z,p[i].first,p[i].second,ch);

            int c=p[i+1].first;
            int d=p[i+1].second;
            bi.push_back(level[c][d]);
        }

        for(int i=0; i<bi.size(); i++)
        {
            sum+=bi[i];
        }

        if(sum>z*z || sum<0)
        {
            cout<<"Case "<<k<<": "<<"Impossible"<<endl;
        }
        else
        {
            cout<<"Case "<<k<<": "<<sum<<endl;
        }

        v.clear();
        bi.clear();
    }
}
