#include <bits/stdc++.h>

using namespace std;
int MAXVALUE = 99999;

int main()
{
    int N,M;
    cin>>N;
    cin>>M; 
    int** G = new int*[N];
    for (int i = 0; i < N; i++)
    {
        G[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                G[i][j] = 0;
            }
            else G[i][j] = MAXVALUE;
        }
    }
   
    int a,b,w;
    for (int i = 0; i < M; i++)
    {
        cin>>a>>b>>w;
        G[a - 1][b - 1] = w;
    }
    
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (G[i][j] > G[i][k] + G[k][j])
                {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
    
 
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        cin>>a>>b;
        a--;
        b--;
        if (G[a][b] == MAXVALUE)
        {
            cout<<-1<<endl;
        }
        else cout<<G[a][b]<<endl;
    }
}
