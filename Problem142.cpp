struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Floyd算法
 * 2020年2月26日
 *
 */
 
ListNode* detectCycle(ListNode* head) {
	ListNode *fast, *slow;
	while (fast && slow && fast -> next) {
		fast = fast -> next -> next;
		slow = slow -> next;
		if (slow == fast) {
			slow = head;
			while (fast != slow) {
				fast = fast -> next;
				slow = slow -> next;
			}
			return slow;
		}
	}	
	return NULL;
}