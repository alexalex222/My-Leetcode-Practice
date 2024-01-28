#
# @lc app=leetcode id=148 lang=python3
#
# [148] Sort List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (not head) or (not head.next):
            return head

        mid = None
        slow = head
        fast = head

        while fast and fast.next:
            mid = slow
            slow = slow.next
            fast = fast.next.next

        mid.next = None

        left = self.sortList(head)
        right = self.sortList(slow)

        return self.merge_list(left, right)

    
    def merge_list(self, l1, l2):
        result = ListNode(0)
        curr = result

        while l1 and l2:
            if l1.val < l2.val:
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2 
                l2 = l2.next

            curr = curr.next
        
        if l1: curr.next = l1
        if l2: curr.next = l2

        return result.next

    
        
# @lc code=end

