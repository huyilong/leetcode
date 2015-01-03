class Bar{
public:
	ListNode *removeDup(ListNode *head){
		if(!head) 
			return head;

		ListNode dummy(head->data + 1); //as long as it has the different value with head
		dummy.next = head;

		recur( &dummy, head);
		//be careful! because the dummy is the struct but the head itself is already a pointer
		//so we need to pass the address of dummy and the name of head to the recur function

		return dummy.next;
		//dummy is the previous of the head, therefore we need only return the dummy.next
		//which is the head of the linkedlist
	}

private:
	//this is static so that it could be called without instantiate the obj of the class
	static void recur(ListNode *prev, ListNode *cur){
		if(cur == nullptr)
			return;
		//this recursion is only depended on the operation rather than returned value to connect
		//the original vlaue of prev is dummy and the cur is head of the linkedlist

		if(prev->data == cur->data)
			//two runners pointers 
		{
			prev->next = cur->next;
			delete cur;//delete the node repeated
			//actually cur is now deleted and we need to update cur with the value of prev -> next
			//rather than using a statement, we just pass the prev->next
			//to the next recursion of cur in parameter list
			recur(prev, prev->next);
			//anyway, cur is always contiguous and one later than the prev
		}else{

			//if does not find the duplicates then we could just update it
			recur(prev->next, cur->next);
		}
	}
};


class Foo{
public:
	ListNode *removeDup(ListNode *head){
		if(head == nullptr)
			return nullptr;

		//here we did not need dummy anymore
		for(ListNode *prev = head, *cur = head->next;
			cur;
			cur=cur->next){

			if(prev->data == cur->data){
				prev->next = cur->next;
				delete cur;
			}else{

				//if the cur is not duplicates then jump two pointers together
				prev = cur;
			}
		}

		return head;
	}
};

/*
typedef struct item {
   int val;
   item * next;
} item;

int main() {
   item * head = NULL;
   int i;
   for(i=1;i<=10;i++) {
      item * curr = new item;
      curr->val = i;
      curr->next  = head;
      head = curr;
   }
   while(head) {
      cout << head->val << " ";
      head = head->next ;
   }
   return 0;
}
*/