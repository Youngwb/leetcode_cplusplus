#include <iostream>
#include <string>
#include <climits>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        change_time=0;
        min_change_time=INT_MAX;
        minDistance_backtracking(word1,word2);
        return min_change_time;
    }

    void minDistance_backtracking(string word1,string word2)
    {
    	cout<<"word1 : "<<word1<<endl;
    	cout<<"word2 : "<<word2<<endl;
    	if(word1 == word2)
    	{
    		if(change_time<min_change_time)
    			min_change_time=change_time;
    		return ;
    	}

    	int i=0;
    	for(;i<word1.size() && i<word2.size();i++)
    	{
    		if(word1[i] != word2[i])
    			break ;
    	}
    	if(i==word1.size() || i==word2.size())
    	{
    		int len=abs(static_cast<int>(word2.size()-word1.size()));
    		change_time+=len;
    		if(change_time<min_change_time)
    			min_change_time=change_time;
    		change_time-=len;
    		return ;
    	}else
    	{
    		change_time++;
    		char tmp;
    		tmp=word1[i];
	    	word1[i]=word2[i];    //replace
	    	minDistance_backtracking(word1.substr(i),word2.substr(i));
	    	word1[i]=tmp;
	    	change_time--;	

	    	change_time++;
	    	word1.insert(i,1,word2[i]); //insert
	    	minDistance_backtracking(word1.substr(i),word2.substr(i));
	    	word1.erase(i,1);
	    	change_time--;

	    	change_time++;
	    	word1.erase(i,1);  //erase
	    	minDistance_backtracking(word1.substr(i),word2.substr(i));
	    	change_time--;
	    	
	    	
   		}
    }

private:
	int change_time;
	int min_change_time;
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.minDistance("strelno","strln");
	cout<<ret<<endl;
	return 0;
}