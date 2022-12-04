#include <iostream>
#include <vector>

using namespace std;

vector<int> col(15,0);
int n, count;

bool check(int x)
{
    for(int i=0;i<x;i++)
    {
        if(col[i]==col[x] || abs(col[x]-col[i]) == x-i)
            return false;
    }
    return true;
}

void nQueen(int x)
{
    if(x==n)
        ::count++;
        
    else
    {
        for(int i=0;i<n;i++)
        {
            col[x] = i;
            if(check(x))
                nQueen(x+1);
        }
    }
}

int main()
{
    cin>>n;
    nQueen(0);
    cout<<::count;
}