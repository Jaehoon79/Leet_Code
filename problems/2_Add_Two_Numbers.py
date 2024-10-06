# Definition for singly-linked list.
from typing import Optional, List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ret = ListNode()
        carry = 0
        tail = ret
        
        while l1 or l2:
            intsum = l1.val + l2.val + carry
            tail.next = ListNode(int(intsum % 10))
            carry = int(intsum / 10)
            tail = tail.next
            
            l1 = l1.next
            l2 = l2.next
            
            if l1 == None and l2 != None:
                l1 = ListNode(0)
            if l1 != None and l2 == None:
                l2 = ListNode(0)

        if carry != 0:
            tail.next = ListNode(carry)
      
        return ret.next
   

def main():
    
    list1_1 = ListNode(2)
    tmp1 = ListNode(4)
    tmp2 = ListNode(3)
    list1_1.next = tmp1
    tmp1.next = tmp2
    
    list2_1 = ListNode(5)
    tmp1 = ListNode(6)
    tmp2 = ListNode(4)
    list2_1.next = tmp1
    tmp1.next = tmp2
        
    list1_2 = ListNode(0)
    list2_2 = ListNode(0)
    
    leet = Solution()
 
    print("1st Answer")
    ret = leet.addTwoNumbers(list1_1, list2_1)
    while ret != None:
        print(ret.val)
        ret = ret.next
    
    print("2nd Answer")
    ret = leet.addTwoNumbers(list1_2, list2_2)
    while ret != None:
        print(ret.val)
        ret = ret.next

if __name__ == "__main__":
    main()