#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int> > vertice(n+1, vector<int>(0));

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }

    vector<int> visited(n+1, 0);
    int result = 0;
    deque<int> queue;

    queue.push_back(1);
    while(!queue.empty())
    {
        int dest = queue.front();
        queue.pop_front();

        if(!visited[dest])
        {
            visited[dest] = 1;
            result++;

            for(int i=0;i<vertice[dest].size();i++)
            {
                queue.push_back(vertice[dest][i]);
            }
        }
    }

    cout<<result-1;
    return 0;
}