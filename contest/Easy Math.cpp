#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int>vt(n);
        for(int i=0;i<n;i++)
        {
            cin >> vt[i];
        }
        int mx = INT_MIN;
        for(int i=0;i<vt.size();i++)
        {
            for(int j=i+1;j<vt.size();j++)
            {
                int p = vt[i]*vt[j];
                // cout << "Here the product is " << p << endl;
                int temp  = 0;
                while(p)
                {
                    temp+=p%10;
                    p/=10;
                }
                mx = max(mx,temp);
            }
        }
        cout << mx << endl;
    }
    return 0;
}