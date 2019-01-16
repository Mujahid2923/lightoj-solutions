#include<bits/stdc++.h>
using namespace std;

#define MAX 1000010
int len[MAX];
char text[MAX];
char pattern[MAX];

void findPattern(string pattern,int m)
{
    len[m];
    int index=0;
    len[0]=0;
    for(int i=1; i<m;)
    {
        if(pattern[i]==pattern[index])
        {
            len[i]=index+1;
            i++;
            index++;
        }
        else
        {
            if(index!=0)
            {
                index=len[index-1];
            }
            else
            {
                len[i]=0;
                i++;
            }
        }
    }

}


int calculate(string text,string pattern)
{
    int n=text.length();
    int m=pattern.length();
    findPattern(pattern,m);
    int i=0;
    int j=0;
    int cnt=0;
    while(i<n)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
            if(j==m)
            {
                cnt++;
            }
        }
        else
        {
            if(j!=0)
            {
                j=len[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return cnt;
}


int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        scanf("%s %s",&text,&pattern);
        int result=calculate(text,pattern);
        printf("Case %d: %d\n",i,result);
    }
    return 0;
}
