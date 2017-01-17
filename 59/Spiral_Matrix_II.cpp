#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n));
        int row_begin=0,row_end=n-1;
        int col_begin=0,col_end=n-1;
        int num=0;
        while(num < n*n)
        {
		    for(int i=row_begin;i<=row_end;i++)
		    	ret[col_begin][i] = ++num;
		    col_begin++;

		    for(int i=col_begin;i<=col_end;i++)
		    	ret[i][row_end] =++num;
		    row_end--;

		    for(int i=row_end;i>=row_begin;i--)
		    	ret[col_end][i]=++num;
		    col_end--;

		    for(int i=col_end;i>=col_begin;i--)
		    	ret[i][row_begin] = ++num;
		    row_begin++;		    
		}
		return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.generateMatrix(10);
	for(auto & itr: ret)
	{
		for(auto & it:itr)
			cout<<it<<" ";
		cout<<endl;
	}

	return 0;
}