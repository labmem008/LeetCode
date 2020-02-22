/**
 * Definition for singly-linked list
 * struct ListNode
 * {
 * 	int val;
 * 	ListNode *next;
 * 	ListNode(int x) : val(x), next(NULL) { }
 * };
 *
 * 给出两个非空的链表
 * 反向存储了两个数字
 * 要求返回一个新的链表来表示这两个链表的和
 * 例如给出 2 -> 4 -> 3 + 5 -> 6 -> 4
 * 输出 7 -> 0 -> 8
 * 因为 342 + 465 = 807
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	ListNode* head = new ListNode(-1);	// dummy head, will return this
	ListNode* current = head;
	int carry = 0;
	while (p1 != NULL || p2 != NULL)
	{
		int a = (p1 != NULL) ? p1 -> val : 0;
		// int a = p1 if p1 is not null
		// a = 0 if p1 is null
		int b = (p2 != NULL) ? p2 -> val : 0;
		int sum = carry + a + b;	// calculate sum
		carry = sum / 10;		// calculate carry
		current -> next = new ListNode(sum % 10);	// 把sum记录到我们创建的链表里面
		current = current -> next;	// update current pointing to next element
		if (p1 != NULL) p1 = p1 -> next;
		if (p2 != NULL) p2 = p2 -> next;	// update p1 and p2
	}
	if (carry > 0)
		current -> next = new ListNode(1);	// if at the last step we still have a carry
							// we add a leading 1 to our result
		return head -> next;
}
