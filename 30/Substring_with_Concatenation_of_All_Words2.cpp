#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
	vector<int> findSubstring(string s,vector<string>& words){
		vector<int> res;
		if(s.empty() || words.empty())
			return res;
		
		int n=words.size();
		int m=words[0].size();
		unordered_map<string,int> m1;
		for(auto& itr : words)
			++m1[itr];
		
		for(int start=0;start<=(int)s.size()-n*m;start++)
		{
			unordered_map<string,int> m2;
			int j=0;
			for(;j<n;++j)
			{
				string temp=s.substr(start+j*m,m);
				if(m1.find(temp) == m1.end())
					break;
				++m2[temp];
				if(m2[temp] > m1[temp])
					break;
			}
			if(j==n)
				res.push_back(start);
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	string s="a";
	vector<string> words={"a","a"};
	Solution sln;
	vector<int> ret=sln.findSubstring(s,words);
	for(auto &itr:ret)
	{
		cout<<itr<<" ";
	}
	cout<<endl;
	return 0;
	return 0;
}