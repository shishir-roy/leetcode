#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int target;
    string str;
    vector<string>vt;
    void rec(int ps,int num,string answer)
    {
        cout << answer << " tar  " << target << endl;
        if(ps>=str.size())
        {
            if(num == target)
            {
                cout << "yessssss  " << answer << endl;
                vt.push_back(answer);
            }
            return;
        }
        int temp = 0;
        for(int x = ps;x< str.size(); x++)
        {
            temp*=10;

            int t = temp+(str[x]-'0');
            rec(x+1,num+t,answer + '+' + to_string(t));

            t = temp-(str[x]-'0');
            rec(x+1,num-t,answer + '-' + to_string(t));

             t = temp * (str[x]-'0');
            rec(x+1,num*t,answer + '*' + to_string(t));
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        str = num;
        target = target;
        cout << "here" << endl;
        rec(0,0,"");
        return vt;
    }
};
int main()
{
    Solution t;
    t.addOperators("12",6);
    return 0;
}