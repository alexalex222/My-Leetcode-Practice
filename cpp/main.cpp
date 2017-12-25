//
//  main.cpp
//  LeetcodeCppXCode
//
//  Created by Kuilin Chen on 2017-10-02.
//  Copyright © 2017 Kuilin Chen. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <climits>
#include <functional>
#include <stdint.h>
#include <unordered_set>
#include <bitset>
#include <assert.h>

using namespace std;
#include "Answer.h"
#include "QueueStack.h"
#include "StackQueue.h"
#include "RangeSum.h"
#include "RandomizedSet.h"
#include "BSTIterator.h"
#include "HitCounter.h"
#include "LRUCache.h"
#include "PhoneDirectory.h"
#include "MovingAverage.h"
#include "RangeSum.h"
#include "Trie.h"
#include "Twitter.h"
#include "TwoSum.h"
#include "ValidWordAbbr.h"
#include "Vector2D.h"
#include "WordDictionary.h"
#include "ZigzagIterator.h"
#include "NumMatrix.h"
#include "NumArray.h"
#include "MedianFinder.h"
#include "ConstructBinaryTree.h"
#include "Permutation.h"
#include "Codec.h"
#include "Calculator.h"
#include "TicTacToe.h"
#include "NestedInteger.h"
#include "PeekingIterator.h"
#include "Read4.h"
#include "Logger.h"


int main() {

    LFUCache LFUobj = LFUCache(0);
    LFUobj.set(0, 0);
    int  p = LFUobj.get(0);
    LFUobj.set(2, 2);

    LFUobj.set(3, 3);
    p = LFUobj.get(2);
    p = LFUobj.get(3);
    LFUobj.set(4, 4);
    p = LFUobj.get(1);
    p = LFUobj.get(3);
    p = LFUobj.get(4);




    Solution mySolution = Solution();

    vector<vector<int>> v{ { 1,2,3,4 },{ 5,6,7,8 },{ 9,10,11,12 }, { 13,14,15,16} };
    vector<int> height{ 1, 0};

    int ret = mySolution.findMaxConsecutiveOnes(height);



    return ret;
}
