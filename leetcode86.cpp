
#include <iostream>

/**
 * Definition for singly-linked list.
 */
 using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLists(int arr[],int len){

    if (len == 0)
        return NULL;

    ListNode* head  = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i=1; i< len;i++){
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode* head){

    while(head != NULL){
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* small_tail = NULL;
        ListNode* small_head = NULL;
        ListNode* big_head = NULL;
        ListNode* big_tail = NULL;
        ListNode* cur = head;
        while (cur != NULL){
            if (cur->val < x){
                if (small_tail == NULL){
                    small_tail = cur;
                    small_head = small_tail;
                }
                else{
                    small_tail->next = cur;
                    small_tail = cur;
                }
            }else{
                if (big_tail == NULL){
                    big_head = cur;
                    big_tail = cur;
                }
                else{
                    big_tail->next = cur;
                    big_tail = cur;
                }
            }
            cur = cur->next;
        }
        big_tail->next = NULL;

        if (small_tail != NULL){
            small_tail->next = big_head;
            return small_head;
        }
        if (big_head != NULL)
            return big_head;
        
        return head;
    }
};

int main() {
    int arr[] = {1,4,3,2,5,2};
    int len = sizeof(arr)/sizeof(int);
    
    ListNode* head = createLists(arr,len);
    printList(head);
    Solution sl;
    ListNode* head2 = sl.partition(head,3);
    printList(head2);

    return 1;
}