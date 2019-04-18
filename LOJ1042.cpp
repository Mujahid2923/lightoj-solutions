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
#define           PI               3.141592653589793238462643
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define        zero(a)             memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


vi v,vec;
int bit=0;

void call()
{
    ll sum=0;
    for(int i=0; i<vec.size(); i++)
    {
       // cout<<vec[i];
        sum+=(vec[i]*pow(2,i));
    }
    pf("Case %d: %lld\n",bit,sum);
}

int main()
{
    output;
    ll t,n;
    cin>>t;
    while(t--)
    {
        bit++;
        scln(n);
        string s = std::bitset<64>(n).to_string();
        for(int j=0; j<s.size(); j++)
        {
            if(s[j]=='1')
            {
                for(int k=j; k<s.size(); k++)
                {
                    v.pb(s[k]-'0');
                }
                break;
            }
        }
        reverse(v.begin(),v.end());
        int a=v.size(),one=0,zero=0,ck=0;
        for(int j=0; j<v.size(); j++)
        {
            if(ck==1 && v[j]==0)
            {
                a=j;
                break;
            }
            else if(ck==0 && v[j]==1)
            {
                one++;
                ck=1;
            }
            else if(ck==1 && v[j]==1)
            {
                one++;
            }
            else if(ck==0 && v[j]==0)
            {
                zero++;
            }
        }
        one--;
        //cout<<a<<" "<<one<<" "<<zero<<endl;
        int mn=min(one,zero);
        int mn2=mn;
        for(int j=0; j<v.size(); j++)
        {
            if(j==a-1)
            {
                vec.pb(0);
                vec.pb(1);
                j++;
            }

            else if(mn2>0 && v[j]==0)
            {
                vec.pb(1);
                mn2--;
            }
            else
            {
                vec.pb(v[j]);
            }
        }

        for(int j=a-2; j>=0; j--)
        {
            if(mn>0 && v[j]==1)
            {
                vec[j]=0;
                mn--;
            }
        }

        call();
        vec.clear();
        v.clear();
    }
    return 0;
}
