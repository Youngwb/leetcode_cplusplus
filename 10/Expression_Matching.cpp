#include <iostream>
#include <regex>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        cout<<s<<endl;
       try{
        regex r(p);
        smatch results;
        if(regex_match(s,results,r)){
			cout<<"match"<<endl;
			return true;
        }
        
       }catch(regex_error e)
       {
       	cout<<e.what()<<"\ncode:"<<e.code()<<endl;
       }
       cout<<"not match "<<endl;
       return false;
        
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	sln.isMatch("aa","c*a*b*");
	return 0;
}