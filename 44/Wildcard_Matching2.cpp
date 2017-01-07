#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> f(m+1,vector<bool>(n+1,false));
        f[0][0]=true;

        for(int i=1;i<=m;i++)
        {
            f[i][0]=false;
        }
        for(int j=1;j<=n;j++)
        {
            f[0][j] = p[j-1] == '*' && f[0][j-1];
        }

        for(int i=1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(p[j-1] == '*')
                {
                    f[i][j] = f[i][j-1] || f[i-1][j];
                }
                else
                {
                    f[i][j] =( s[i-1] == p[j-1] || p[j-1] == '?' )&&f[i-1][j-1]; 
                }
            }
        }
        return f[m][n];
    }

   
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.isMatch("ho","h*o*");
	cout<<ret<<endl;
	return 0;
}