#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(0);
        ListNode* tmp=dummy;
        if(lists.size()==0)
        	return nullptr;
        if(lists.size()==1)
        	return lists[0];
        int list_size=lists.size();
        int count=0;
        while(count <list_size){
        	vector<ListNode*>::iterator min_idx;
    		int min=INT_MAX;
    		count=0;
	    	for(auto itr=lists.begin();itr!=lists.end();++itr){
	    		
	    		if(*itr == nullptr){
	    			++count;
	    			if(count == list_size)
	    				return dummy->next;
	    			// cout<<"new count:"<<count<<endl;
	    			// min_idx=itr;
	    			continue;
	    		}
	    		
	    		if((*itr)->val<min){
	    			min=(*itr)->val;
	    			min_idx=itr;
	    		}
	    		
	    		
	    	}
	    	// if(*min_idx != nullptr)
	    	//  	cout<<"min_idx:"<<*min_idx<<endl;
    		tmp->next=*min_idx;
    		// cout<<tmp->next->val<<endl;
    		tmp=tmp->next;
    		if(*min_idx != nullptr)
    			*min_idx=(*min_idx)->next;
    		// cout<<"count:"<<count<<endl;

        }
        return dummy->next;
    }

};

int main(int argc, char const *argv[])
{
	Solution sln;
	ListNode* x=new ListNode(1);
	ListNode* y=new ListNode(2);
	vector<ListNode*> lists={nullptr,nullptr};
	
	ListNode* ret=sln.mergeKLists(lists);
	while(ret != nullptr){
		cout<<ret->val<<" ";
		ret=ret->next;
	}
	cout<<endl;
	return 0;
}