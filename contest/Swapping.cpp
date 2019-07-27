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
        vector<long long int>vt(n+7);
        for(int i=0;i<n;i++)
        {
            cin >> vt[i+1];
        }
        vt[n+1] = -INT_MIN;
        long long int sum = 0;
        long long int i;
        for(i=1;i<=n-2;)
        {
            long long int t1 = vt[i] * (i+1) + vt[i+1]*i + vt[i+2]*(i+2);
            long long int t2 = vt[i] * i + vt[i+1]*(i+2) + vt[i+2]*(i+1);
            if(t1>t2)
            {
                sum+= vt[i] * (i+1) + vt[i+1]*i ;
                i+=2;
                swap(vt[i],vt[i+1]);
            } 
            else
            {
                sum+= vt[i]*i;
                i++;
            }
        }
        if(i==n)
        {
            sum+=vt[n]*n;
        }
        else
        {
            long long int t1 = vt[n-1] * (n-1) + vt[n]*n ;
            long long int t2 = vt[n] * (n-1) + vt[n-1]*n ;
            sum+=max(t1,t2);
        }
        cout << sum << endl;
    }
    return 0;
}