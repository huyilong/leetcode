//read the problem very carefully 
//swap every two adjacent nodes in the linkedlist
//version 1:could modify the values in the list
class Foo{
public:
	//because we always need to return the head back to the main function
	//therefore the return type of the function should also be the pointer 
	ListNode *swapPairs(ListNode *head){
		ListNode *runner = head;
		while(runner && runner -> next){
			//as for the next field defined in the ListNode struct 
			//next is the pointer pointing to the struct and thus should be used with ->
			//however the struct itself such as ListNode dummy(INT_MIN)
			//should be used in the pattern of dummy.next->data
			swap(runner->data, runner->next->data);

			runner = runner->next->next;
		}

		return head;
	}
};

//version 2: we cannot modify the data but only the node itself
class Bar{
public:
	ListNode *swapPairs(ListNode *head){

		if(head == nullptr || head->next == nullptr)//at least the linkedlist should have a pair inside
			return head;

		ListNode dummy(-1);
		//ListNode dummy(INT_MIN);
		dummy.next = head;

		for(ListNode *prev = &dummy, *cur = prev->next, *next = cur->next;
			next;
			//let the previous become the cur and thus guarantee that prev will not be altered anymore
			prev = cur, cur = cur->next, next = cur ? cur->next : nullptr)
			//actually prev is used as the guarder and each time the cur and next will be swapped

		{
			prev->next = next;
			//let the guard linked with the 2nd node -> it becomes the first 

			cur->next = next->next;
			//let the 1st node linked with the 3rd node -> it becomes the second

			next->next = cur;
			//let the first's next points to the second

			//the next before becomes the current now

		}

		return dummy.next;

};

