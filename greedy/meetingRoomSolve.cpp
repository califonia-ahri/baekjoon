#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<pair<int, int>> meetings;      // store each meeting's start and end time
    for(int i=0;i<n;i++)
    {
        int start, end;
        cin>>start>>end;
        meetings.push_back(make_pair(end,start));
    }

    sort(meetings.begin(), meetings.end());

    int time = meetings[0].first;
    int count = 1;
    for(int i=1;i<n;i++)
    {
        if(time <= meetings[i].second)
        {
            count++;
            time = meetings[i].first;
        }
    }

    cout<<count;
}