#include <iostream>

using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        dfs(head,k);
        return head;
    }

    void dfs(ListNode* & ptr,int k){
    	int i=0;
    	ListNode* res=ptr;
    	for(;res!=nullptr;){
    		++i;
    		if(i==k)
    			break;
    		res=res->next;
    	}
    	if(i<k)
    		return ;
    	else{
    		ListNode* cur=ptr;
    		ListNode* next=ptr->next;
    		// cout<<"cur:"<<cur->val<<endl;
    		// cout<<"next:"<<next->val<<endl;
    		while(cur != res){
    			if(next != nullptr){
    				ListNode* pnext=next->next;
    				next->next=cur;
    				cur=next;
    				next=pnext;
    			}
    		}
    		ListNode* tmp=ptr;
    		ptr->next=next;
    		ptr=cur;
    		if(next != nullptr){
    			
    			dfs(tmp->next,k);
    		}
    	}
    }
};

int main(int argc, char const *argv[])
{
	ListNode* p1=new ListNode(1);
	// ListNode* p2=new ListNode(2);
	// ListNode* p3=new ListNode(3);
	// ListNode* p4=new ListNode(4);
	// ListNode* p5=new ListNode(5);
	// p1->next=p2;
	// p2->next=p3;
	// p3->next=p4;
	// p4->next=p5;
	Solution sln;
	ListNode* ret;
	ret=sln.reverseKGroup(p1,1);
	while(ret != nullptr){
		cout<<ret->val<<" ";
		ret=ret->next;
	}
	cout<<endl;
	return 0;
}