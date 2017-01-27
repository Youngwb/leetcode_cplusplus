#include <iostream>
#include <vector>
#include <deque>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	deque<int> dq(digits.begin(),digits.end());
    	int carry=1;
    	for(auto itr=dq.rbegin();itr !=dq.rend() ;itr++)
    	{
    		if(*itr +carry < 10 )
    		{
    			*itr+=carry;
    			carry=0;
    			break;
    		}
    		else
    		{
    			*itr=0;
    			carry=1;
    			
    		}
    	}

    	if(carry ==1)
		{
			dq.push_front(1);
		}
    	return vector<int>(dq.begin(),dq.end());
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<int> v={9};
	auto ret= sln.plusOne(v);
	for(auto itr: ret)
	{
		cout<<itr<<" ";
	}
	cout<<endl;
	return 0;
}