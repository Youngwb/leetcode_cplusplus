#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_len=word1.size();
        int word2_len=word2.size();
        

        vector<vector<int>> vec(word1_len+1,vector<int>(word2_len+1,0));

        for(int i=0;i<=word1_len;i++)
        {
            vec[i][0]=i;
        }

        for(int i=0;i<=word2_len;i++)
        {
            vec[0][i]= i;
        }

        for(int i=1;i<=word1_len;i++)
        {
            for(int j=1;j<=word2_len;j++)
            {
                if(word1[i-1] == word2[j-1])
                    vec[i][j] = vec[i-1][j-1];
                else
                    vec[i][j]=min(min(vec[i-1][j]+1,vec[i-1][j-1]+1),vec[i][j-1]+1);
            }
        }
        
        return vec[word1_len][word2_len];
        
    }
};

int main(int argc, char const *argv[])
{
	Solution sln;
	auto ret=sln.minDistance("","");
	cout<<ret<<endl;
	return 0;
}