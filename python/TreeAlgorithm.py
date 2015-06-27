# -*- coding: utf-8 -*-
"""
Created on Sun Mar 29 11:10:28 2015

@author: Kuilin
"""

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):
        if root is None:
            return 0
        else:
            return max(self.maxDepth(root.left), self.maxDepth(root.right))+1
    
    # @param p, a tree node
    # @param q, a tree node
    # @return a boolean
    def isSameTree(self, p, q):
        if p == None and q == None:
            return True
        elif p and q and p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        else:
            return False
            
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        resultlist = []
        self.recursive_preorder(root,resultlist)
        return resultlist
    
    def recursive_preorder(self, root, treelist):
        if root:
            treelist.append(root.val)
            self.recursive_preorder(root.left,treelist)
            self.recursive_preorder(root.right,treelist)
            
    # @param root, a tree node
    # @return a list of integers
    def inorderTraversal(self, root):
        resultlist = []
        self.recursive_inorder(root,resultlist)
        return resultlist
    
    def recursive_inorder(self, root, treelist):
        if root:
            self.recursive_inorder(root.left,treelist)
            treelist.append(root.val)
            self.recursive_inorder(root.right,treelist)
        
     
            
            