# -*- coding: utf-8 -*-
"""
Created on Sun Mar 29 15:51:03 2015

@author: Kuilin
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        if head == None or head.next == None:
            return head
        p = head
        while p.next:
            if p.val == p.next.val:
                p.next = p.next.next
            else:
                p = p.next
        return head
        
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        if head == None or head.next == None:
            return head
        else:
            dummy = ListNode(0)
            dummy.next = head
            p = dummy
            while p.next and p.next.next:
                temp = p.next.next
                p.next.next = temp.next
                temp.next = p.next
                p.next = temp
                p = p.next.next
        return dummy.next


    def hasCycle(self, head: ListNode) -> bool:
        if (head is None) or (head.next is None):
            return False
        
        slow = head
        fast = head.next
        while fast and fast.next:
            if slow == fast:
                return True
            slow = slow.next
            fast = fast.next.next
        return False
                
            
        