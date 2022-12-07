#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cards;
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for(int i=0;i<n;i++)
    {
        int card;
        cin>>card;

        cards.push_back(card);
    }
    sort(cards.begin(), cards.end());

    cin>>m;
    for(int i=0;i<m;i++)
    {
        int card;
        cin>>card;
        cout<<upper_bound(cards.begin(), cards.end(), card) - lower_bound(cards.begin(), cards.end(), card)<<" ";
    }
}