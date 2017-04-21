#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
        	return 0;

        int rows=matrix.size();
        int cols=matrix[0].size();

        std::vector<int> height(cols+1);
        height[cols]=0;
        int maxval=0;
        for(int i=0;i<rows;++i)
        {
        	stack<int> st;
        	for(int j=0;j<cols+1;++j)
        	{
        		if(j<cols)
        		{
	        		if(matrix[i][j]=='1')
	        			height[j]+=1;
	        		else
	        			height[j]=0;
        		}

        		if(st.empty() || height[st.top()] <= height[j])
        			st.push(j);
        		else
        		{
        			while(!st.empty() && height[st.top()] > height[j])
        			{
	        			int tp=st.top();
	        			st.pop();
	        			int maxareatop=height[tp]*(st.empty()?j:j-st.top()-1);
	        			if(maxareatop>maxval)
	        				maxval=maxareatop;
        			}
        			st.push(j);
        		}
        	}
        }

        return maxval;

    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<vector<char>> v={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	auto ret=sln.maximalRectangle(v);
	cout<<ret<<endl;
	return 0;
}