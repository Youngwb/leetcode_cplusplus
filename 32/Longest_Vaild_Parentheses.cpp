#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxlen=0;
        int last=-1;
        for(int i=0;i<s.size();++i)
        {
        	if(s[i] == '(')
        	{
        		st.push(i);
        	}else
        	{
        		if(st.empty())
        		{
        			last=i;
        		}
        		else
        		{
        			st.pop();
        			if(st.empty())
        			{
        				maxlen=max(maxlen,i-last);
        			}else
        			{
        				maxlen=max(maxlen,i-st.top());
        			}
        			
        		}
        	    
        	}
        }
        
        return maxlen;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	string s("()(()()");
	int ret=sln.longestValidParentheses(s);
	cout<<ret<<endl;
	return 0;
}