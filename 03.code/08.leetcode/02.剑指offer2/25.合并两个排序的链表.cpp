#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <unistd.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 0
// 方法一 迭代
// 时间复杂度 O(m + n)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new(std::nothrow) ListNode(-1);

		ListNode *ret = head;
		while (nullptr != l1 && nullptr != l2)
		{
			if (l1->val > l2->val)
			{
				ret->next = l2;
				l2 = l2->next;
			}
			else if (l2->val > l1->val)
			{
				ret->next = l1;
				l1 = l1->next;
			}
			else
			{
				ret->next = l1;
				l1 = l1->next;
				ret = ret->next;

				ret->next = l2;
				l2 = l2->next;
			}
			ret = ret->next;
		}

		if (nullptr != l1)
		{
			ret->next = l1;
		}
		else if (nullptr != l2)
		{
			ret->next = l2;
		}
        
        return head->next;
    }
#endif

// 方法2 递归
// 时间复杂度 O(m + n)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (nullptr == l1)
	{
		return l2;
	}
	else if (nullptr == l2)
	{
		return l1;
	}
	else if (l1->val > l2->val)
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
	else // if (l2->val >= l1->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
}

int main() {

	ListNode* h1 = new(std::nothrow) ListNode(1);
	ListNode* h2 = new(std::nothrow) ListNode(2);
	ListNode* h3 = new(std::nothrow) ListNode(4);

	ListNode* h4 = new(std::nothrow) ListNode(1);
	ListNode* h5 = new(std::nothrow) ListNode(3);
	ListNode* h6 = new(std::nothrow) ListNode(4);

	h1->next = h2;
	h2->next = h3;

	h4->next = h5;
	h5->next = h6;

	ListNode* tmp = mergeTwoLists(h1, h4);

	while (tmp != NULL)
	{
		cout << tmp->val << ", ";
		tmp = tmp->next;
	}
	cout << endl;


	return 0;
}
