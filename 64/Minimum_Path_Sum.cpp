#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> ret(m,vector<int>(n,0));
        ret[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
       		ret[i][0]=ret[i-1][0]+grid[i][0];

       	for(int i=1;i<n;i++)
       		ret[0][i]=ret[0][i-1]+grid[0][i];

       	for(int i=1;i<m;i++)
       	{
       		for(int j=1;j<n;j++)
       			ret[i][j]=min(ret[i-1][j],ret[i][j-1])+grid[i][j];
       	}

       	return ret[m-1][n-1];
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<vector<int>> v={{0,1},{2,1}};
	auto ret = sln.minPathSum(v);
	cout<<ret<<endl;
	return 0;
}