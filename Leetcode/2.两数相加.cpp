/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, num1, num2;

        ListNode* ans = new ListNode(0);
        auto cur = ans;

        while (l1 || l2)
        {
            num1 = l1 == nullptr? 0 : l1 -> val;
            num2 = l2 == nullptr? 0 : l2 -> val;

            cur -> next = new ListNode((carry + num1 + num2) % 10);
            cur = cur -> next;
            carry = (carry + num1 + num2) / 10;

            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
        }
        // 处理进位
        if (carry) {
            cur -> next = new ListNode(carry);
        }
        return ans -> next;
    }
};