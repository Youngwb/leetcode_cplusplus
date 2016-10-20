#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> numbersCopy;
        for(int i=0;i<nums.size();i++)
        numbersCopy.push_back(nums[i]);
        
        sort(numbersCopy.begin(),numbersCopy.end());
        vector<int> returnNumbers=twoSumAlgorithm(numbersCopy,target);
        
        vector<int> returnIndexes;
        if(returnNumbers[0]==returnNumbers[1]){
            for(int i=0;i<nums.size();i++){
            if(nums[i]==returnNumbers[0]){
                returnIndexes.push_back(i);
              }
            }
        }else{
        for(int j=0;j<returnNumbers.size();j++)
            for(int i=0;i<nums.size();i++){
            if(nums[i]==returnNumbers[j]){
                returnIndexes.push_back(i);
            }
            }
        }
        
        if(returnIndexes[0]>returnIndexes[1]){
            returnIndexes[0]=returnIndexes[0]^returnIndexes[1];
            returnIndexes[1]=returnIndexes[0]^returnIndexes[1];
            returnIndexes[0]=returnIndexes[0]^returnIndexes[1];
        }
          return returnIndexes;
 //         return returnNumbers;
    }
    
    vector<int> twoSumAlgorithm(vector<int> &numbers, int target) { 
        int length=numbers.size();
        vector<int> r;
        int i=0;int j=length-1;
        while(i<j){
            int x=numbers[i]+numbers[j];
            if(x==target){
                r.push_back(numbers[i]);
                r.push_back(numbers[j]);
                i++;j--;
            }else if(x>target){
                j--;
            }else{
                i++;
            }
        }
        cout<<r[0]<<"\t"<<r[1]<<endl;
        return r;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution slt;
    vector<int> Given_nums = {3,2,4};
    int target = 6;
    vector<int> ret=slt.twoSum(Given_nums,target);
    for(int i=0;i<ret.size();i++)
        std::cout<<ret[i]<<"\t";
    return 0;
}