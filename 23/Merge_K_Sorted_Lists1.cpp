#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 


class Solution {
private:
	struct cmp
	{
		bool operator ()(const ListNode* lhs,const ListNode* rhs){
			return lhs->val > rhs->val;
		}
	};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	int n=lists.size();
    	if (n==0)
    		return NULL;
    	ListNode* dummy = new ListNode(0);
    	ListNode* res=dummy;
    	priority_queue<ListNode*,vector<ListNode*>,cmp> que;
    	for(int i=0;i<n;++i){
    		if(lists[i] != NULL)
    			que.push(lists[i]);
    	}
    	while(!que.empty()){
    		ListNode* tmp=que.top();
    		que.pop();
    		res->next=tmp;
    		res=res->next;
    		if(tmp->next != NULL)
    			que.push(tmp->next);
    	}
    	return dummy->next;
    }


};