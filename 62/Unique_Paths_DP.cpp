#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> ret(m,vector<int>(n,0));
       for(int i=0;i<m;++i)
       {
            ret[i][n-1]=1;
       }
       for(int i=0;i<n;++i)
       {
            ret[m-1][i]=1;
       }

       for(int i= m-2;i>=0;i--)
       {
        for(int j=n-2;j>=0;j--)
        {
            ret[i][j]=ret[i+1][j]+ret[i][j+1];
        }
       }

       return ret[0][0];
    }

    
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.uniquePaths(4,5);
	cout<<ret<<endl;
	return 0;
}