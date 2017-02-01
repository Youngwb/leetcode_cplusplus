#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
       string str,tmp;
       istringstream is(path);
       vector<string> vec;
       while(getline(is,tmp,'/'))
       {
            if(tmp == "" || tmp == ".")
                continue;
            if(tmp == ".." && !vec.empty())
                vec.pop_back();
            else if(tmp != "..")
                vec.push_back(tmp);
       }

        if(vec.empty())
            return "/";
        for(auto itr:vec)
        {
            str+="/";
            str+=itr;
        }

        return str;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.simplifyPath("/../");
	cout<<ret<<endl;
	return 0;
}