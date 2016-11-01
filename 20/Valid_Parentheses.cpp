#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	stack<char> st;
        for(auto &  itr:s){
        	if(itr == '(' || itr == '{' || itr == '['){
        		st.push(itr);
        	}
        	else{
	        	if(st.empty())
	        		return false;
	            if(itr == ')'){
	    			if(st.top()=='(')
	    				st.pop();
	    			else 
	    				return false;
	        	}
	        	if(itr == '}'){
	        		if(st.top() == '{')
	        			st.pop();
	        		else
	        			return false;
	        	}
	        	if(itr == ']'){
	        		// cout<<"test"<<endl;
	        		if(st.top()== '[')
	        			st.pop();
	        		else
	        			return false;
	        	}
        		}	
    	}
	    if(st.empty())
	    	return true;
	    else
	    	return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	if(sln.isValid("]"))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}