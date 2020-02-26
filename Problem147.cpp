struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 插入排序的链表版本
 * 2020年2月26日
 *
 */



ListNode* insertionSortList(ListNode* head) {
	// implement insertion sort with linked list
	ListNode* dummy = new ListNode(0);	// create a dummy head, will return this
	ListNode* prev = NULL;	// initially set to dummy and increment until prev -> next -> val is larger than the val to be sorted
	ListNode* cur = head;	// traverse through the entire linked list
	ListNode* temp = NULL;	// a temp node is needed to store the next node to be sorted
	while (cur && cur -> next) {	// for loop is not used since we don't know exactly how many cycles do we need
		if (cur -> val <= cur -> next -> val)
			cur = cur -> next;	// if the next val is larger than the current val, no need to insert
		else {
			temp = cur -> next;	// before jump the next node, store it using temp.
			cur -> next = cur -> next -> next;	// cur -> next -> next can be null. jump the next node.
			prev = dummy;	// we initialize prev here because it should be set to dummy for every iteration
			while (prev -> next -> val <= temp -> val)	
				prev = prev -> next;	// loop for the correct place to insert
			temp -> next = prev -> next;	// 插入分为两步，就像火车一样，先将要插入的车厢的尾部和后面一节车厢的头部连接起来
			prev -> next = temp;	// 第二部是将头部和前一节车厢的车尾连接起来
		}
	}
	return dummy -> next;	// 返回dummy -> next
}
	
 