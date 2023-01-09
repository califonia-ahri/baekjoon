#include <iostream>
#include <vector>

using namespace std;

int n, e;
vector<vector<int> > vertices(n+1, vector<int>(n+1, 0));

int main()
{
    
    cin>>n>>e;

    

    for(int i=0;i<e;i++)
    {
        int x, y, r;
        cin>>x>>y>>r;

        vertices[x][y] = r;
        vertices[y][x] = r;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=1;k<n+1;k++)
            {
                vertices[i][j] = min(vertices[i][k] + vertices[k][j], vertices[i][j]);
            }
        }
    }
}