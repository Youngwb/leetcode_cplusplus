#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0)
        	return 0;
        heights.push_back(0);
        stack<int> st;
        int i=0;
        int len=heights.size();
        int maxarea=0;
        while(i<len)
        {
        	if(st.empty() || heights[st.top()] <= heights[i])
        		st.push(i++);
        	else
        	{
        		int tp=st.top();
        		st.pop();
        		int maxareatop=heights[tp] * (st.empty()?i:(i-1-st.top()));
        		if(maxareatop > maxarea)
        			maxarea=maxareatop;
        	}
        }
        return maxarea;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<int> v={2,1,5,6,2,3};
	auto ret=sln.largestRectangleArea(v);
	cout<<ret<<endl;
	return 0;
}