#include <iostream>
#include <queue>
struct cell
{
    int x = -1;
    int y = -1;
    int level = 0;
    bool isvalid(int N, int M)
    {
        if (x >= 0 && x < N  && y >= 0 && y < M)
        {
            return true;
        }
        else return false;
    }
};
int main()
{
    int N;
    int M;
    int T;
    std::cin>>N>>M>>T;
    cell a[2];
    int x,y;
    int t = 0;
    while (std::cin>>x>>y && t < 2)
    {
        a[t].x = x - 1;
        a[t].y = y - 1;
        t++;
    }
    std::queue<cell> rotten;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    short** appls = new short*[N];
    for (int i = 0; i < N; i++)
    {
        appls[i] = new short[M];
        for (int j = 0; j < M; j++)
        {
            appls[i][j] = 1;
        }
    }
    if (a[0].isvalid(N,M))
    {
        appls[a[0].x][a[0].y] = 0;
            rotten.push(a[0]);
    }
    if (a[1].isvalid(N,M))
    {
        appls[a[1].x][a[1].y] = 0;
            rotten.push(a[1]);
    }
    
    cell temp;
    while (!rotten.empty() && T > rotten.front().level)
    {
        temp = rotten.front();
        rotten.pop();
        for (int i = 0; i < 4; i++)
        {
            cell rot;
            rot.x = temp.x + dx[i];
            rot.y = temp.y + dy[i];
            rot.level = temp.level + 1;
            if (rot.isvalid(N,M) && appls[rot.x][rot.y] != 0)
            {
                appls[rot.x][rot.y] = 0;
                rotten.push(rot);
            }
            
        }
    }
    int ctr = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (appls[i][j] == 1) ctr++;
           // std::cout<<appls[i][j]<<" ";
        }
      // std::cout<<std::endl;
    }
    std::cout<<ctr;
    
}
