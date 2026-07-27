class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;
        ListNode* p2 = secondHalf;
        bool isPalin = true;

        while (p2 != nullptr) {
            if (firstHalf->val != p2->val) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            p2 = p2->next;
        }

        return isPalin;
    }
};