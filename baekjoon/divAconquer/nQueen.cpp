#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPossible(const vector<vector<bool> > & board, const vector<pair<int, int> > &queens, int i, int j)
{
    for(int k=0;j<k;k++)
    {
        if(i==k || abs(i-k)==j-k)
            return false;
    }

    return true;
}

int testBoard(vector<vector<bool> > board, vector<pair<int, int> > queens, int i)
{
    if(i==board.size())
    {
        return 1;
    }
    
    int temp = 0;
    for(int j=0;j<board.size();j++)
    {
        if(!isPossible(board, queens, i, j))
            continue;

        board[i][j] = false;
        queens.push_back(make_pair(i, j));
        
        int can = testBoard(board, queens, i+1);
        temp += can;

        queens.pop_back();
        board[i][j] = true;
    }

    return temp;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<bool> > board(n, vector<bool>(n, true));
    vector<pair <int, int> > queens;

    cout<<testBoard(board, queens, 0);
}