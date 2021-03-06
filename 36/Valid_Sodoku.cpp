#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowValid[10]={0};
        int columnValid[9][10]={0};
        int subboardValid[9][10]={0};

        for(int i=0;i<9;++i)
        {
        	memset(rowValid,0,sizeof(rowValid));
        	for(int j=0;j<9;++j)
        	{
        		if(board[i][j] != '.')
        		{
	        		if(!checkValid(rowValid,board[i][j]-'0') || !checkValid(columnValid[j],board[i][j]-'0')
	        			|| !checkValid(subboardValid[i/3*3+j/3],board[i][j]-'0'))
	        			{
	        				return false;
	        			} 
        		}
        	}
        }
        return true;
    }

    bool checkValid(int vec[],int value)
    {
    	if(vec[value] == 1)
    		return false;
    	vec[value]=1;
    	return true;
    }
};

