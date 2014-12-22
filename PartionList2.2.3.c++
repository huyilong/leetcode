//the file name could be different with the class name in c++
//but in java they are the same 
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(nullptr){}
};

class Bar{
public:
	ListNode* seperate(ListNode* head, int x)
	{
		if(head == nullptr) return head;
		ListNode left(0);// head node
		ListNode right(0);
		//initialize two new pointers to check each position in the original list
		auto left_cur = & left;//make sure that the head should not be moved in checking
		auto right_cur = & right;

		//the head of the original list is useless and thus could be moved in the operation
		for(;head;head=head->next)
		{
			if(head->val<x){
				left_cur->next = head;
				left_cur = head;//insert from the end of the new list to ensure the original order
			}else{
				right_cur->next = head;
				right_cur = head;
			}
		}

		left_cur->next = right.next;
		right_cur -> next =nullptr;

		return left.next;
	}
};

//'auto' not allowed in function prototype
void insert(ListNode* cursor, ListNode x)
{
	cursor->next = & x;
    cursor = cursor->next;
}
//you cannot write as the ListNode = ListNode.next because as a new struct the operator = is not overloaded

int main(int argc, char** argv)
{
	ListNode head(0);//the original list's head node
	//when define the troublesome cursor or iterator in c++ always using auto to define the type
	auto cursor = &head;
	insert(cursor, ListNode(1));
	insert(cursor, ListNode(4));
	insert(cursor, ListNode(3));
	insert(cursor, ListNode(2));
	insert(cursor, ListNode(5));
	insert(cursor, ListNode(2));
	cursor->next =nullptr;
	cursor = &head;
	while (;cursor!=nullptr; cursor=cursor->next)
	{
		cout<< (*cursor).value <<" ";
	}
	cout<<endl;
}