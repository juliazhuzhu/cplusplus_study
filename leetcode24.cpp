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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);

        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = prev->next;
        ListNode* node1 = cur;
        ListNode* node2 = cur->next;
        while (node1 && node2){
            ListNode* next = node2->next;
            prev->next = node2;
            node2->next = node1;
            node1->next = next;

            prev = node1;
            node1 = next;
            if (node1){
                node2 = node1->next;
            }
        }

        return dummy->next;
    }
};


int main() {

    int arr[] = {1,2,3,4};
    int len = sizeof(arr)/sizeof(int);
    
    ListNode* head = createLists(arr,len);
    printList(head);
    Solution sl;
    ListNode* retNode1 = sl.swapPairs(head);
    printList(retNode1);

    return 1;
}