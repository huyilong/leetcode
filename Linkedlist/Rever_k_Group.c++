/*
1.break只是跳出最内层循环
2.如果希望能跳出所有循环，你需要往外层循环再传递信息，譬如一个布尔值，外层循环一旦检测到该
布尔值为真，则各自break;
3.简而言之，break,continue只是控制其所在的循环。continue并不是跳出循环，而是立马进入所在循环中的下次循环。
*/
class Difficult{
public:
	ListNode *reverseKGroup(ListNode *head, int group_size){
		if(head == nullptr || head->next == nullptr || group_size<2)
			return head;

		ListNode dummy(INT_MIN);
		dummy.next = head;

		for(ListNode *prev = &dummy, *end = head; 
			end;
			end = prev->next){
			for(int i=1; i<group_size && end; ++i){
				end= end->next;

				if(end == nullptr)
					//break只是跳出最内层循环
					break;//the left out will remain unchanged

				prev = reverseHelper(prev, prev->next, end);
				//prev is used as the guard pointer, in first group it would be dummy itself
				//prev->next is the first element in the group which would be reversed
				//end is the last element in the group which would be reversed
			}
		}
	}

	//prev is the element before the first element 
	//the reversed group should be [begin, end]
	//the returned value should be the "begin" passed in, which is actually the last element after reverse

	//the process is that 1->2->3->4->5 and group_size = 4
	//we first let the internal pointer be reversed : 1<-2<-3<-4
	//and then let the dummy.next (prev->next) points to the end:4
	//and the bigin: 1->next should point to the beginning of the next reversed group, i.e. 5
	ListNode *reverseHelper(ListNode *prev, ListNode *begin, ListNode *end)
	{
		ListNode *end_next = end->next;
		//end_next is actually the first element of the next group to be reversed
		for(ListNode *runner = begin, *cur = p->next, *next = cur->next;//reverse needs three pointers
			cur != end_next;
			runner = cur, cur = next, next = next ? next->next : nullptr)
		{
			cur->next = runner;
			//reverse the next field in each internal nodes in the reverse group
		}

		begin->next = end_next;
		//the first element still could be retrieved by using begin
		//and let the begin->next be the last element and points to the first element in the next group
		prev->next = end;
		//let the guard element: the element before the first element in the current group
		//let the next field points to the ending element, which is now the first element in the group

		return begin;//here we actually return the last element in the reversed group!!! not the first!
	}
};

