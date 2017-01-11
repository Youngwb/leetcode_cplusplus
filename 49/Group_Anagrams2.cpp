#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>


using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,multiset<string>> ud_map;
        vector<vector<string>> ret;
        for(auto & itr: strs)
        {
            string tmp(itr);
            sort(tmp.begin(),tmp.end());
            ud_map[tmp].insert(itr);
        }

        for(auto &itr : ud_map )
        {
            vector<string> val(itr.second.begin(),itr.second.end());
            ret.push_back(val);
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	vector<string> v={"eat", "tea", "tan", "ate", "nat", "bat"};
	auto ret=sln.groupAnagrams(v);
	for(auto & itr: ret)
	{
		for(auto & it:itr)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}