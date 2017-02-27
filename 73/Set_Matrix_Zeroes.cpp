#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
        	return ;
        int m=matrix.size();
        int n=matrix[0].size();

        std::vector<bool> row(m,false);
        std::vector<bool> col(n,false);

        for(int i=0;i<m;i++)
        	for(int j=0;j<n;j++)
        		if(matrix[i][j]==0)
        		{
        			row[i]=true;
        			col[j]=true;
        		}

       for(int i=0;i<m;i++)
       {
       		if(row[i]==true)
       		{
       			for(int j=0;j<n;j++)
       				matrix[i][j]=0;
       		}
       }

       for(int i=0;i<n;i++)
       {
       		if(col[i] == true)
       		{
       			for(int j=0;j<m;j++)
       			{
       				matrix[j][i]=0;
       			}
       		}
       }
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;

	return 0;
}