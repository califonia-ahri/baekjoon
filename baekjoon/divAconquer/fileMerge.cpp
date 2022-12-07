#include <iostream>
#include <vector>

using namespace std;

int n1, n2;

int getMinTime()
{
    cin>>n2;

    vector<vector<int> > count(vector<int>(n2), 0);
    vector<int> times;
    for(int i=0;i<n2;i++)
    {
        int time;
        cin>>time;

        times.push_back(time);
    }

    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<n2-i;j++)
        {
            int temp = j + i;

            if(temp==j)

        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>> n1;

    for(int i=0;i<n1;i++)
    {
        
    }


}