#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;
/**
* Definition for singly-linked list.
**/ 
struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *newHead;
		ListNode *before = NULL, *cur = head, *next = head;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = before;
			before = cur;
			cur = next;
		}

		return before;
	}
};

int main()
{
	ListNode *head;
	ListNode node1(1), node2(2);
	head = &node1;
	node1.next = &node2;

	Solution sol;
	auto c = sol.reverseList(head);

	return 0;
}