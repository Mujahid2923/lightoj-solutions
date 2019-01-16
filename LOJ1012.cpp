#include<bits/stdc++.h>
using namespace std;

vector<int>v;
char s[20][20];
int visited[20][20];

int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};

bool isValid(int row,int col,int x,int y)
{
    if(x>=0 && x<row && y>=0 && y<col && visited[x][y]==0 && s[x][y]=='.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DFS(int row,int col,int x,int y)
{
    visited[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];

        if(isValid(row,col,xx,yy))
        {
            DFS(row,col,xx,yy);
        }
    }
}

int main()
{
    int t,row,col,x,y;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int cnt=0;
        cin>>col>>row;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cin>>s[i][j];
            }
        }
        //  cout<<s[3][9]<<endl;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(s[i][j]=='@')
                {
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        //cout<<x<<" "<<y<<endl;
        DFS(row,col,x,y);
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(visited[i][j]==1)
                {
                    // cout<<s[i][j]<<" ";
                    cnt++;
                }
            }
        }

        cout<<"Case "<<k<<":"<<" "<<cnt<<endl;
        memset(visited,0,sizeof visited);

    }
    return 0;
}
