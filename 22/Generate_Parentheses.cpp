#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v_first;
        vector<int> v_second;

        v_first.push_back("(");
        v_second.push_back(1);
        // v_third.push_bacK(0)
        // int has_compute=0;
        for(int i=1;i<2*n-1;++i){
        	int len=v_first.size();
        	for(int j=0;j<len;++j){
        		string tmp=v_first[j];
        		int left_num=v_second[j];
        		int right_num=i-left_num;
        		// if(tmp.size()==i){
    			if(left_num -right_num>0 && left_num <n){
    				v_first.push_back(tmp+"(");
    				v_second.push_back(left_num+1);
    				v_first.push_back(tmp+")");
    				v_second.push_back(left_num);

    				
    			}else if(left_num - right_num==0){
    				v_first.push_back(tmp+"(");
    				v_second.push_back(left_num+1);
    			}else{
    				v_first.push_back(tmp+")");
    				v_second.push_back(left_num);
    			}
    			
        		// }
        	}
        	v_first.erase(v_first.begin(),v_first.begin()+len);
    		v_second.erase(v_second.begin(),v_second.begin()+len);
        }
      	for(auto &itr:v_first)
      		itr.push_back(')');
        return v_first;

    }
};


int main(int argc, char const *argv[])
{
	Solution sln;
	vector<string> ret;
	ret=sln.generateParenthesis(4);
	for(auto & itr :ret)
		cout<<itr<<endl;

	return 0;
}