#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
        	return false;

        int rows=matrix.size();
        int cols=matrix[0].size();

        int row_begin=0;
        int row_end=rows-1;
        int row_mid=0;
        while(row_begin<=row_end)
        {
        	row_mid=(row_begin+row_end)/2;
        	if(target == matrix[row_mid][0] || target == matrix[row_mid][cols-1])
        		return true;
        	else if(target> matrix[row_mid][0] && target < matrix[row_mid][cols-1])
        		break;
        	else if(target > matrix[row_mid][cols-1])
        		row_begin++;
        	else
        		row_end--;
        }

        int col_begin=0;
        int col_end=cols-1;

        while(col_begin<= col_end)
        {
        	int col_mid=(col_begin+col_end)/2;
        	if(matrix[row_mid][col_mid] == target)
        		return true;
        	else if(matrix[row_mid][col_mid]< target)
        		col_begin++;
        	else
        		col_end--;
        	
        }

        return false;

    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	return 0;
}