#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty())
        	return ret;
        int m=matrix.size();
        int n=matrix[0].size();

        int row_min=0;
        int row_max=n;
        int col_min=0;
        int col_max=m;

        while(row_min < row_max && col_min < col_max)
        {
        	for(int i=row_min;i<row_max;i++)
        		ret.push_back(matrix[col_min][i]);
        	col_min++;
        	
        	for(int i=col_min;i<col_max;i++)
        		ret.push_back(matrix[i][row_max-1]);
        	row_max--;

   
			if(col_min >= col_max || row_min>= row_max)
				break;
        	
        	for(int i=row_max-1;i>=row_min;i--)
        		ret.push_back(matrix[col_max-1][i]);
        	col_max--;
        	
        	
        	
        	for(int i=col_max-1;i>=col_min;i--)
        		ret.push_back(matrix[i][row_min]);
        	row_min++;

        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<vector<int>> v={{7},{9},{6}};
	auto ret=sln.spiralOrder(v);
	for(auto & itr:ret)
		cout<<itr<<" ";
	cout<<endl;
	return 0;
}