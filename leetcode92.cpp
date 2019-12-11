/**
 * Definition for singly-linked list.*/

  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if (head == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* con = nullptr;
        ListNode* tail = nullptr;
        for (int i=1;i<=n;i++){

            if (i == (m-1))
                con = cur;
            if (i == m){
                tail = cur;
            }   
            if (i < m){
                cur = cur->next;
            }
            if (i >= m){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
        }
        if (con != nullptr) {
            con->next = prev;
        } else {
            head = prev;
        }
        tail->next = cur;
        //con->next = prev;
        
        return head;
    }
};

int main(){
    return 1;
}