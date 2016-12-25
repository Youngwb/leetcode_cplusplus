#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i)
        {
        	for(int j=0;j<9;++j)
        	{
        		if(board[i][j] != '.')
        			fill(i,j,board[i][j]-'0');
        	}
        }
        solver(board,0);
    }

    bool solver(vector<vector<char>>& board , int index)
    {
    	if(index > 80)
    		return true;
    	int row = index / 9; 
    	int column = index - 9*row;
    	if(board[row][column] != '.')
    		return solver(board,index+1);
    	for(int value='1';value <= '9';++value)
    	{
    		if(isValid(row,column,value-'0'))
    		{
    			board[row][column]=value;
    			fill(row,column,value-'0');
    			if(solver(board,index+1))
    				return true;
    			clear(row,column,value-'0');
    		}
    	}
    	board[row][column]='.';
    	return false;
    }

    bool isValid(int row, int column ,int value)
    {
    	if(rowValid[row][value] != 0 || columnValid[column][value] !=0 || subBoardValid[row/3*3+column/3][value] !=0)
    		return false;
    	return true;
    }

    void fill(int row,int column, int value)
    {
    	rowValid[row][value]=1;
    	columnValid[column][value]=1;
    	subBoardValid[row/3*3+column/3][value]=1;

    }

    void clear(int row,int column, int value)
    {
    	rowValid[row][value]=0;
    	columnValid[column][value]=0;
    	subBoardValid[row/3*3+column/3][value]=0;

    }

private:
	int rowValid[9][10];
	int columnValid[9][10];
	int subBoardValid[9][10];
};

int main(int argc, char const *argv[])
{
	
	return 0;
}
