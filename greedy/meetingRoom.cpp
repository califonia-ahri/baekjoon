#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Machine
{
    public: 
    int count;
    int end;
    
    Machine()
    {
        this->count = 0;
        this->end = 0;
    }
    Machine(int count, int end)
    {
        this->count = count;
        this->end = end;
    }

    bool operator < (Machine& machine)
    {
        return this->end<machine.end;
    }
};



class Room
{
    public: 
    int start;
    int end;
    
    Room()
    {
        this->start = 0;
        this->end = 0;
    }
    Room(int start, int end)
    {
        this->start = start;
        this->end = end;
    }

    bool operator < (Room& room)
    {
        return this->end<room.end;
    }
};

int isAvailable(vector<Machine> machines, int time)
{
    for(int i=0;i<machines.size();i++)
    {
        if(machines[i].end<time)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;

    vector<Room> meetings; 

    int start, end;

    for(int i=0;i<n;i++)
    {
        cin>>start>>end;
        Room room(start, end);
        meetings.push_back(room);
    }
    sort(meetings.begin(), meetings.end());

    vector<Machine> machines;
    for(int i=0;i<n;i++)
    {
        int avail = isAvailable(machines, meetings[i].start);
        if(avail!=-1)
        {
            machines[avail].end = meetings[i].end;
            machines[avail].count++;
        }
        else
        {
            Machine machine(1, meetings[i].end);
            machines.push_back(machine);
        }
    }
    
    sort(machines.begin(), machines.end());

    cout<<(machines.end()-1)->count;
    
    return 0;
}