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
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* head) {
	if (NULL == head || NULL == head->next)
	{
		return head;
	}

	ListNode *r = head;
	ListNode *m = r->next;
	ListNode *l = m->next;
	head->next = NULL;
	

	while (NULL != l)
	{
		m->next = r;
		r = m;
		m = l;
		l = l->next;
	}
	m->next = r;

	// while (m != NULL)
	// {
	// 	cout << m->val << endl;
	// 	m = m->next;
	// }

	return m;
}

int main() {
	ListNode* h1 = new(std::nothrow) ListNode(1);
	ListNode* h2 = new(std::nothrow) ListNode(2);
	ListNode* h3 = new(std::nothrow) ListNode(3);
	ListNode* h4 = new(std::nothrow) ListNode(4);

	h1->next = h2;
	h2->next = h3;
	h3->next = h4;

	ListNode* tmp = reverseList(h1);

	while (tmp != NULL)
	{
		cout << tmp->val << endl;
		tmp = tmp->next;
	}

	return 0;
}
