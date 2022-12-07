#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;
    while(--n)
    {
        int n2;
        vector<int> sum;
        vector<vector<int> > dp(n2, vector<int>(n2, 0));
        vector<int> files;
        cin>>n2;
        for(int i=1;i<=n2;i++)
        {
            int file;
            cin>> file;
            files.push_back(file);
            sum[i] = sum[i-1] + files[i];
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
        cout<<dp[0][n2-1]<<endl;
    }
}