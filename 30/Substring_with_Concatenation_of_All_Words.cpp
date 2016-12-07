#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_len= words[0].size();
        int str_len=s.size();
        int Concatenation_len=word_len*words.size();
        vector<int> ret;
        for(int i=0;i<str_len-Concatenation_len+1;)
        {
        	string str=s.substr(i,Concatenation_len);
        	if(findConcatenationwords(str,words))
        	{	
        		ret.push_back(i);	
        	}
        	++i;
   		}
   		return ret;
   	}

   	bool findConcatenationwords(string& s,vector<string>& words)
   	{
   		int word_len=words[0].size();
   		int vec_len=words.size();
   		vector<bool> sz(false,vec_len);
   		for(int i=0;i!=s.size();i+=word_len)
   		{
   			string temp=s.substr(i,word_len);
   			int j=0;
   			for(;j!=vec_len;j++)
   			{
   				if(sz[j] == false)
   				{
	   				if(temp == words[j])
	   				{
	   					sz[j]=true;
	   					break;
	   				}
   				}
   			}
   			if(j== vec_len && sz[j]==false)
   				return false;
   				
   		}
   		return true;;
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
}