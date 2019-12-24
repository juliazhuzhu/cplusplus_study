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
    void deleteNode(ListNode* node) {

        if (node->next == nullptr){
            node = nullptr;
            return;
        }

        node->val = node->next->val;
        ListNode* delNode = node->next;
        node->next = delNode->next;

        return;


        
    }
};


int main() {
    int arr[] = {4,5,1,9};
    int len = sizeof(arr)/sizeof(int);
    
    ListNode* head = createLists(arr,len);
    printList(head);
    Solution sl;
    sl.deleteNode(head->next);
    printList(head);
    return 1;
}