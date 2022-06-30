/*
Given the heads of two singly linked-lists headA and headB, 
return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
For example, the following two linked lists begin to intersect at node c1
   a1->a2
         \
          c1->c2->c3
         /
b1->b2->b3
return c1 Node.
method 1: is two pointer Floyd's method. 
    Time complexity O(m+n)
    Space complexity O(1)
method 2: hashmap unordered_map<Node *, int> 
    Time complexity O(m+n)
    Space complexity O(m)
method 3: Brute force. Outer while loop picks one NodeA and compares to all NodeB in inner while loop. 
    Time complexity O(m*n)
    Space compelxity O(1)
https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1215/
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode * a = headA, *b = headB;
    if(a==NULL || b ==NULL)
        return NULL;
    while(a!= b)
    {
        a = a->next;
        b = b->next;
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        if(a==b)
            return a;
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        if(a==NULL)
            a = headB;
        if(b==NULL)
            b = headA;
    }
    return a;
}