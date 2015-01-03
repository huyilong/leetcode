//the digits are already stored in reverse order for later calculation
struct ListNode{
	int data;
	ListNode *next;

	//constructor with initializing list
	ListNode(int x): val(x), next(nullptr){}
};

//bit manipulation   ^ xor a<<b  a moves left for b bits
class Boo{
public:
	ListNode *addTwoNums(ListNode *l1, ListNode *l2){
		ListNode head(-1); // head node
		//this is used as a new head of the linkedlist 
		int carry = 0;
		ListNode *prev = &head;//different from java
		//using the pointer named prev to continuously construct the new linkedlist

		//pa and pa are pointers to pointers
		for(ListNode *pa = l1, *pb = l2; pa!=nullptr && pb!=nullptr; 
			pa = pa==nullptr? nullptr : pa->next,
			pb = pb==nullptr? nullptr : pb->next,
			prev = prev->next){

			const int ai = pa==nullptr ? 0 : pa->data;
			const int bi = pb==nullptr ? 0 : pb->data;

			const int value = (ai + bi + carry )% 10;
			carry = (ai + bi + carry)/ 10;

			prev -> next = new ListNode(value)// insertion at the tail rather than head
		}

		//attention if all is done but still have a carry pending in the air
		if(carry>0){
			prev ->next = new ListNode(carry);
		}

		return head.next;
		//head is a dummy which stored the value of 0
	}
};

