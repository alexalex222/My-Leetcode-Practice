# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        start = curr = ListNode(0)
        carry = 0

        while(l1 or l2 or carry):
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0

            carry, current_val = divmod(x + y + carry, 10)
            curr.next = ListNode(current_val)
            
            curr = curr.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        return start.next

