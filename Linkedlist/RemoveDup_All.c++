//this time when we meet with the duplicates we will delete them all
//and thus we need a flag variable to record if the last value is one of the duplicates to delete

class Foo{
public:
	ListNode *removeDup_All(ListNode *head){
		//this function will finally return a var of ListNode type
		if(!head || !head->next)
			return head;
		//first thing is always judge the pointers are legal and not nullptr

		ListNode *check = head->next;

		//iteration could be combined with recursion!!!
		//must be very logically clear
		if(head->data == check->data){
			//every time the head is already updated by the calling of next recursion's parameter
			//we use the parameter itself to update rather than using the statement in iteration

			while(check && head->data == check->data){
				ListNode *temp = check;
				check = check->next;
				delete temp;
			}

			delete head;//because we have to delete all the duplicates 
			//after the loop check is actually stop at the first not duplicates
			//and we need to pass this distinct node as the head of next recursion checking
			return removeDup_All(check);
		}else{
			//else the first pair is not duplicate 
			//we then need to let the next node compared with the head node
			head->next = removeDup_All(head->next);
			//here we are returning head rather than the head->next!!!
			return head;
		}

	}

	ListNode *removeDup_All(ListNode *head){
		if(head == nullptr)
			return head;

		//make up a new head as the previous
		//which must have the different value compared with head
		ListNode dummy(INT_MIN);
		//use the constructor defined in node struct 
		/*
		struct ListNode{
			int data;
			ListNode *next;

			//constructor with initializing list
			//only need to offer one of the parameter
			//constructor could not be virtual but destructor could be
			ListNode(int x): val(x), next(nullptr){}
		};
		*/

		dummy.next = head;
		//as for the struct we need to use dot operation to visit the internal var
		//could not use dummy->next = head!!!   although head itself is a pointer
		ListNode *prev = &dummy;
		//however, when we use a pointer pointing to this struct 
		//we then could use prev->next to visit the next defined in the next struct
		//which is similar to prev.next when prev is a struct rather than a pointer


		ListNode *cur = head;
		while(cur != nullptr){

			//cur stands for current
			bool duplicates = false;
			while(cur->next != nullptr && cur->data == cur->next->data){
				//using cur->next->data rather than cur->next.data because 
				//in the struct next is defined as the LinkedNode * pointer next
				duplicates = true;
				ListNode *temp = cur;
				cur = cur->next;
				delete cur;
			}

			if(duplicates)//delete the last of the duplicates
			{
				ListNode *temp = cur;
				cur = cur->next;
				delete temp;
				continue;
			}

			//jump at the first of the next linkedlist
			prev->next = cur;
			prev = prev->next;
			//the two statements above is actually used to prev = cur;
			cur = cur->next;
			//still keep the order of previous pointer and current pointer
		}

		prev->next =cur;//this is useless
		return dummy.next;//return the real head of the linkedlist

	}
};

