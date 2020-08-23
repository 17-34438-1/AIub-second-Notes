#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
int arr[100][100],e,v;
bool visit[100];
void dfs(int st)
{
    stack<int> s;
    s.push(st);
    visit[st]=true;
    cout<<st<<"\t";
    while(!s.empty())
    {
        st = s.top();
        s.pop();
        for(int j=1;j<=v;j++)
        {
            if(arr[st][j]==1 && visit[j]==false)
            {
                s.push(j);
                cout<<j<<"\t";
                visit[j]=true;

            }
        }
        visit[st]=true;
    }
}

int main()
{
    cin>>v>>e;
    int f,l,st;
    for(int i=0;i<v; i++)
    {
        cin>>f>>l;
        arr[f][l]=0;
        visit[f]=false;
        visit[l]=false;
    }
    cin>>st;
    dfs(st);
    return 0;
}
