# -*- coding: utf-8 -*-
"""
Created on Tue Mar 24 18:55:30 2015

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
        return 0

#myTree = ['a', 
#          ['b', ['d',[],[]], ['e',[],[]] ], 
#        ['c', ['f',[],[]], []] ]
#print(myTree)
#print('left subtree = ', myTree[1])
#print('root = ', myTree[0])
#print('right subtree = ', myTree[2])
#t = myTree.pop(1)
#n = len(t)
#myTree.insert(1,['d',t,[]])


class BinaryTree:
    def __init__(self,rootObj):
        self.key = rootObj
        self.leftChild = None
        self.rightChild = None

    def insertLeft(self,newNode):
        if self.leftChild == None:
            self.leftChild = BinaryTree(newNode)
        else:
            t = BinaryTree(newNode)
            t.leftChild = self.leftChild
            self.leftChild = t

    def insertRight(self,newNode):
        if self.rightChild == None:
            self.rightChild = BinaryTree(newNode)
        else:
            t = BinaryTree(newNode)
            t.rightChild = self.rightChild
            self.rightChild = t


    def getRightChild(self):
        return self.rightChild

    def getLeftChild(self):
        return self.leftChild

    def setRootVal(self,obj):
        self.key = obj

    def getRootVal(self):
        return self.key

def preorder(tree):
    if tree:
        print(tree.val)
        preorder(tree.left)
        preorder(tree.right)

def postorder(tree):
    if tree:
        postorder(tree.left)
        postorder(tree.right)
        print(tree.val)
        
def inorder(tree):
  if tree:
      inorder(tree.left)
      print(tree.val)
      inorder(tree.right)
        
r = BinaryTree('a')

print(r.getRootVal())
print(r.getLeftChild())
r.insertLeft('b')
print(r.getLeftChild())
print(r.getLeftChild().getRootVal())
r.insertRight('c')
print(r.getRightChild())
print(r.getRightChild().getRootVal())
r.getRightChild().setRootVal('hello')
print(r.getRightChild().getRootVal())

t = TreeNode('a')
t.left = TreeNode('b')
t.right = TreeNode('c')
t.left.right = TreeNode('d')
t.left.left = TreeNode('e')
t.right.left = TreeNode('f')
t.right.right = TreeNode('g')
#preorder(t)
#postorder(t)
inorder(t)