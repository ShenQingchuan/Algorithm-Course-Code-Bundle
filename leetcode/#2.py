class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = 0
        num2 = 0
        
        index_cusor = 0
        ptr = l1
        while ptr != None:
            num1 += ptr.val * (10**index_cusor)
            index_cusor = index_cusor + 1
            ptr = ptr.next
        
        index_cusor = 0
        ptr = l2
        while ptr != None:
            num2 += ptr.val * (10**index_cusor)
            index_cusor = index_cusor + 1
            ptr = ptr.next
        
        resultNum = num1 + num2
        
        head = ListNode(resultNum % 10)
        resultNum = resultNum // 10
        ptr = head
        while resultNum != 0:
            ptr.next = ListNode(resultNum % 10)
            resultNum = resultNum // 10
            ptr = ptr.next

        return head