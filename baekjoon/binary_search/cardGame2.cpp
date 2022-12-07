#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

 int n, m;
 vector<int> cards;
int binary_search2(int target)
{
    int left = 0;
    int right = cards.size()-1;

    while(left<=right)
    {
        int mid = left + (right-left)/2;

        if(cards[mid]==target)
        {
            if(cards[mid+1]==target)
                left = mid+1;
            else
                return mid;
        }
        else if(cards[mid]>target)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return -1;
}

int binary_search(int target)
{
    int left = 0;
    int right = cards.size()-1;

    while(left<=right)
    {
        int mid = left + (right-left)/2;

        if(cards[mid]==target)
        {
            if(cards[mid-1]==target)
                right = mid-1;
            else
                return mid;
        }
        else if(cards[mid]>target)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return -1;
}

int main()
{
    cin>>n;

    string temp;
    cin.ignore();
    getline(cin, temp);

    stringstream ss(temp);
    ss.str(temp);

    string card;
    while(ss>>card)
    {
        cards.push_back(stoi(card));
    }

    sort(cards.begin(), cards.end());

    cin>>m;
    cin.ignore();
    getline(cin, temp);

    stringstream s2(temp);
    s2.str(temp);

    while(s2>>card)
    {
        int pos1 = binary_search2(stoi(card));
        int pos2 = binary_search(stoi(card));
        if(pos1==-1)
            cout<<"0 ";
        else
            cout<<pos1-pos2+1<<" ";
    }
}