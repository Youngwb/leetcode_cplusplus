#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        auto itr=words.begin();
        vector<string> ret;
        while(itr != words.end())
        {
        	int currentlen=itr->size();
        	int wordslen=itr->size();
        	int word_num=1;
        	auto it=itr+1;
        	for(;it!= words.end();it++,word_num++)
        	{
        		currentlen+=it->size()+1;

        		if(currentlen > maxWidth)
        			break;
        		wordslen+=it->size();
        	}
        	int space_num =word_num-1;
        	// cout<<"space_num :"<<space_num<<endl;
        	int space_total_len=maxWidth-wordslen;
        	// cout<<"space_total_len : "<<space_total_len<<endl;
        	if(space_num == 0)
        	{
        		string str(*itr);
        		str_space_insert(str,space_total_len);
        		ret.push_back(str);
        	}else
        	{
        		if(it == words.end())
        		{
        			string str(*itr);
        			for(auto itr_copy=itr+1;itr_copy!=it;itr_copy++)
        			{
        				str+=' ';
        				str+=*itr_copy;
        			}
        			str_space_insert(str,maxWidth-wordslen-space_num);
        			ret.push_back(str);
        		}else
        		{
        			int space_extra_len=space_total_len%space_num;
        			// cout<<"space_extra_len : "<<space_extra_len<<endl;
        			int space_even_len=space_total_len/space_num;
        			string str(*itr);
        			for(auto itr_copy=itr+1;itr_copy!=it;itr_copy++)
        			{
        				int space_len=space_even_len;
        				if(space_extra_len!=0)
        				{
        					space_len++;
        					space_extra_len--;
        				}
        				str_space_insert(str,space_len);
        				str+=*itr_copy;
        			}
        			ret.push_back(str);
        		}
        	}

        	itr=it;
        }
        return ret;
    }
private:
	void str_space_insert(string& str,int n)
	{
		for(int i=0;i<n;i++)
			str.push_back(' ');
	}
};

int main(int argc, char const *argv[])
{
	Solution sln;
	std::vector<string> v={"This", "is", "an", "example", "of", "text", "justification."};
	auto ret=sln.fullJustify(v,16);
	for(auto & itr:ret)
	{
		cout<<"'"<<itr<<"'"<<"   "<<itr.size()<<endl;;
	}
	return 0;
}