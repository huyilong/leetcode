class Foo{
	//1->2->3->4->5->nullptr if the k=2 to rotate
	//3->4->5->1->2->nullptr

public:
	ListNode *rotateList( ListNode *head, int k){
		//be careful!!! the k could be possibly bigger than the length of the list!!!
		if(head == nullptr || k==0)
			return head;

		int len = 1;
		ListNode *check = head;
		while(check->next){
			len++;
			check = check->next;
		}//calculate the length of the linkedlist

		k = len - k%len;

		//at this time check is pointing to the last node in the list
		//then let this become a loop and then break at one point

		check->next = head;
		for(int step=0; step<k; ++step){
			check = check->next;
		}

		//create as a new head
		head = check->next;
		//create as the new tail
		check->next = nullptr;
		return head;
	}
}