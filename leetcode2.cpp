#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.*/

  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

ListNode* createLists(int arr[],int len){

    if (len == 0)
        return nullptr;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur_l1 = l1;
        ListNode* cur_l2 = l2;
        ListNode* new_head = nullptr; 
        ListNode* new_cur = new_head;
        
        int reserved = 0;
        while(cur_l1 != nullptr || cur_l2 != nullptr){
            int val_l1 = 0;
            int val_l2 = 0;
            int val = 0;
            //reserved = 0;
            if (cur_l1 != nullptr){
                val_l1 = cur_l1->val;
                cur_l1 = cur_l1->next;
            }

            if (cur_l2 != nullptr){
                val_l2 = cur_l2->val;
                cur_l2 = cur_l2->next;
            }

            //printf("%d %d %d \n", val_l1, val_l2, reserved);
            val = val_l1 + val_l2 + reserved;
            if ( val >= 10){     
                reserved = 1;
            }
            else {
                reserved = 0;
            }
                 

            if (new_head == nullptr){
                new_head = new ListNode(val%10);
                new_cur = new_head;
            }
            else{
                new_cur->next = new ListNode(val%10);
                new_cur = new_cur->next;
            }
            
        }

        if (reserved != 0){
            new_cur->next = new ListNode(reserved);
            new_cur = new_cur->next;
        }

        return new_head;
    }
};


int main(){

    int arr_l1[] = {2,4,3};
    int arr_l2[] = {5,6,4};

    int len = sizeof(arr_l1)/sizeof(int);
    ListNode* head = createLists(arr_l1,len);
    printList(head);

    len = sizeof(arr_l2)/sizeof(int);
    ListNode* head2 = createLists(arr_l2,len);
    printList(head2);

    Solution sl;
    ListNode* ret_node = sl.addTwoNumbers(head,head2);
    printList(ret_node);


    return 1;
}