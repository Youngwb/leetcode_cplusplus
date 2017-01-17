#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
    	string::size_type pos1=s.find_last_not_of(' ');
    	cout<<pos1<<endl;
        if(pos1 != string::npos)
        {
        	string::size_type pos2=s.find_last_of(' ',pos1);
        	cout<<pos2<<endl;
        	if(pos2 != string::npos)
        		return pos1-pos2;
        	else
        		return pos1+1;
        } 
        else
        	return 0;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.lengthOfLastWord("a bcd  ");
	cout<<ret<<endl;
	return 0;
}