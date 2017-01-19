#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> ret(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        		if(obstacleGrid[i][j] == 1)
        			ret[i][j]=-1;
        	}
        }
        if(ret[m-1][n-1] != -1)
        	ret[m-1][n-1] =1;
        else
        	return 0;

        for(int i=m-2;i>=0;i--)
        {
        	if(ret[i][n-1] !=-1)
        		ret[i][n-1] = ret[i+1][n-1];
        	else
        		ret[i][n-1] = 0;
        }

        for(int i=n-2;i>=0;i--)
        {
        	if(ret[m-1][i] !=-1)
        		ret[m-1][i] =ret[m-1][i+1];
        	else
        		ret[m-1][i] =0;
        }

        for(int i=m-2;i>=0;i--)
        {
        	for(int j=n-2;j>=0;j--)
        	{
        		if(ret[i][j] != -1)
        		{
        			ret[i][j]=ret[i+1][j]+ret[i][j+1];
        		}
        		else
        		{
        			ret[i][j]=0;
        		}
        	}
        }

        return ret[0][0];
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<vector<int>> v={{0,0,0},{0,1,0},{0,0,0}};
	auto ret=sln.uniquePathsWithObstacles(v);
	cout<<ret<<endl;
	return 0;
}