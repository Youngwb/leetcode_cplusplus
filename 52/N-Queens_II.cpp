#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int totalNQueens(int n) {
        int ret=0;
        vector<string> val(n,string(n,'.'));
        solveNQueens_backtracking(ret,val,0);
        return ret;
    }

    void solveNQueens_backtracking(int& ret,vector<string>& val,int row)
    {
    	if(row == val.size())
    	{
    		++ret;
    		return ;
    	}

    	int n=val.size();
    	for(int col=0;col<n;++col)
    	{
    		if(check_col(val,row,col)  &&  check_cross(val,row,col))
    		{
    			val[row][col] ='Q';
    			solveNQueens_backtracking(ret,val,row+1);
    			val[row][col] = '.';
    		}
    	}
    	
    }

    bool check_col(vector<string>& val,int row,int col)
    {
  
    	for(int i=0;i<row;i++)
    	{
    		if(val[i][col] == 'Q')
    			return false;
    	}
    	
    	return true;
    }

    bool check_cross(vector<string>& val,int row, int col)
    {
    	int n = val.size();
    	for(int i=row-1,j=col-1,jj=col+1;i>=0;--i,--j,++jj)
    	{
    		if(j >=0 && val[i][j] == 'Q')
    			return false;
    		if(jj<n && val[i][jj] == 'Q')
    			return false;
    	}

    	return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.totalNQueens(1);
	cout<<ret<<endl;
	return 0;
}