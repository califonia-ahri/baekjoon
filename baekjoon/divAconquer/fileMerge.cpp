#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n1, n2;
vector<int> times;

int getMinTime()
{
    while(times.size()!=1)
    {
        sort(times.begin(), times.end());
        int mid = (times.size()-1)/2;

        int merged = times[mid] + times[mid+1];
        times.erase(times.begin()+mid);
        times.erase(times.begin()+mid+1);
        times.push_back(merged);
    }

    return times[0];
}

int main()
{
    cin>> n1;
    for(int i=0;i<n1;i++)
    {
        cin>>n2;

        for(int j=0;j<n2;j++)
        {
            int time;
            cin>>time;

            times.push_back(time);
        }

        cout<<getMinTime()<<endl;

        times.clear();
    }

}