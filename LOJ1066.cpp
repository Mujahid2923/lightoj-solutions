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
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

char s[100][100];
int visited[100][100];
int level[100][100];
string str="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool isvalid(int siz,int x,int y,char ch)
{
    if(x>=0 && x<siz && y>=0 && y<siz && visited[x][y]==0 && (s[x][y]=='.'|| s[x][y]==ch))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BFS(int siz,int x,int y,char ch)
{
    for(int i=0; i<siz; i++)
    {
        for(int j=0; j<siz; j++)
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

        if(s[a][b]==ch)
        {
            return;
        }
        for(int i=0; i<4; i++)
        {
            int xx=a+fx[i];
            int yy=b+fy[i];

            if(isvalid(siz,xx,yy,ch))
            {
                visited[xx][yy]=1;
                level[xx][yy]=level[a][b]+1;
                q.push(pii(xx,yy));
            }
        }
    }
}

int main()
{
    //output;
    int t,k,siz,x,y;
    scin(t);
    RUN_CASE(k,t)
    {
        int fg=0;
        scin(siz);
        for(int i=0; i<siz; i++)
        {
            for(int j=0; j<siz; j++)
            {
                cin>>s[i][j];
                if(s[i][j]=='A')
                {
                    x=i;
                    y=j;
                }
                if(s[i][j]>='A' && s[i][j]<='Z')
                {
                    fg++;
                }
            }
        }

        int sum=0,ck=0;
        int a=x,b=y;
        for(int f=0; f<fg; f++)
        {
            char ch=str.at(f);
            BFS(siz,a,b,ch);
            for(int i=0; i<siz; i++)
            {
                for(int j=0; j<siz; j++)
                {

                    if(s[i][j]==ch)
                    {
                        a=i;
                        b=j;
                        s[i][j]='.';
                    }
                }
            }
            if(level[a][b]==INT_MAX)
            {
                ck=1;
                break;
            }
            int lev=level[a][b];
            sum+=lev;
        }
        if(ck==1)
        {
            pf("Case %d: Impossible\n",k);
        }
        else
        {
            pf("Case %d: %d\n",k,sum);
        }
        /* for(int i=0; i<siz; i++)
         {
             for(int j=0; j<siz; j++)
             {

                 cout<<s[i][j];
             }
             cout<<endl;
         }*/
    }
    return 0;
}

/*
1
4
.ID#
GA..
H#E.
FC.B
*/
