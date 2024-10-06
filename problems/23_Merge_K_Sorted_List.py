# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from typing import List, Optional

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        ret = list()
        for index in range(len(lists)):
            tmp = lists[index]
            while tmp != None:
                ret.append(tmp.val)
                tmp = tmp.next
        ret.sort()
        retList = ListNode()
        tmp = retList
        for val in ret:
            tmp.next = ListNode(val)
            tmp = tmp.next
        return retList.next
    
def main():
    lists_1 = [[1,4,5],[1,3,4],[2,6]]
    
    a = ListNode(1)
    b = ListNode(4)
    c = ListNode(5)
    a.next = b
    b.next =c
    test = list()
    
    for index in range(len(lists_1)):
        test.append(ListNode(lists_1[index][0]))
        tmp = test[index]
        for subindex in range(1, len(lists_1[index])):
            tmp.next = ListNode(lists_1[index][subindex])
            print(lists_1[index][subindex], tmp.val)
            tmp = tmp.next
            
    '''
    for index in range(len(test)):
        tmp = test[index]
        while tmp != None:
            print(tmp.val)
            tmp = tmp.next
    '''    
    leet = Solution()
    #print(f"1.Answer : {leet.mergeKLists(test)}")
    ret = leet.mergeKLists(test)
    
    while ret != None:
        print(ret.val)
        ret = ret.next


if __name__ == "__main__":
    main()