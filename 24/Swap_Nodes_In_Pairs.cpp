#include <iostream>

using namespace std;

//  Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)
        	return nullptr;
        if(head -> next == nullptr)
        	return head;
        
        ListNode* ptr=head;
        ListNode* nptr=head->next;
        while(ptr != nullptr && nptr != nullptr){
        	int tmp=ptr->val;
        	ptr->val=nptr->val;
        	nptr->val=tmp;

        	ptr=nptr->next;
        	if(ptr != nullptr)
        		nptr=ptr->next;
        }
       
        return head;
    }

};

int main(int argc, char const *argv[])
{
	Solution sln;
	ListNode* p1=new ListNode(1);
	ListNode* p2=new ListNode(2);
	p1->next=p2;
	sln.swapPairs(p1);
	return 0;
}