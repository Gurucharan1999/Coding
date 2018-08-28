#include<bits/stdc++.h>

using namespace std;

int dp[100001];

void no_of_zeroes()
{
    dp[0] = 0;
    for(int i = 1; i <= 100000; i++)
        if(i%5 == 0)
        {
            int Count = 0, j = i;
            while(j/5 && j%5 == 0)
            {
                Count++;
                j /= 5;
            }
            dp[i] = dp[i-1] + Count;
        }
        else dp[i] = dp[i-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    no_of_zeroes();
    while(t--)
    {
        int n;
        cin >> n;
        bool x = binary_search(dp, dp+100000, n);
        if(!x) cout << -1 << '\n';
        else
        {
            int *p = find(dp, dp+100000, n);
            for(int *i = p; i < p + 5; i++)
                cout << i-dp << ' ';
            cout << '\n';
        }
    }
    return 0;
}
