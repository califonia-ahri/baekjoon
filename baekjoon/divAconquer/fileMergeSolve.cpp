#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    while(n--)
    {
        int n2;
        cin>>n2;
        
        vector<int> sum(n2+1, 0);
        vector<vector<int> > dp(n2+1, vector<int>(n2+1, 0));

        for(int i=1;i<=n2;i++)
        {
            int file;
            cin>> file;
            sum[i] = sum[i-1] + file;
        }

        for(int i=1;i<n2;i++)
        {
            for(int j=1;j<=n2-i;j++)
            {
                int k = i + j;
                dp[j][k] = INT_MAX;

                for(int mid = j;mid<k;mid++)
                {
                    dp[j][k] = min(dp[j][k], dp[j][mid] + dp[mid+1][k] + sum[k] - sum[j-1]);
                }
            }
        }

        cout<<dp[1][n2]<<endl;
    }
}