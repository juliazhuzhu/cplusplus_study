
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == nullptr)
            return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = prev->next;
        bool bPrevEqual = false;
        int lastval = 0;
        while(cur){
            int num = 0;
            ListNode* p = cur;
            //loop until current node is nullptr or not equal with previous node
            while (p&& cur->val == p->val){
                num++;
                p = p->next;
                
            }
            if (num > 1){
                prev->next = p;
            }else{
                prev = cur;
            }
            cur = p;
        }

        ListNode * retNode = dummy->next;
        delete dummy;

        return retNode;


    }
};

int main(){

    int arr[] = {1,2,3,3,4,4,5};
    int len = sizeof(arr)/sizeof(int);
    
    ListNode* head = createLists(arr,len);
    printList(head);
    Solution sl;
    ListNode* retNode1 = sl.deleteDuplicates(head);
    printList(retNode1);

    int arr2[] = {1,1,1,2,3};
    int len2 = sizeof(arr2)/sizeof(int);

    head = createLists(arr2,len2);
    printList(head);

    retNode1 = sl.deleteDuplicates(head);
    printList(retNode1);

    int arr3[] = {1,1};
    int len3 = sizeof(arr3)/sizeof(int);

    head = createLists(arr3,len3);
    printList(head);

    retNode1 = sl.deleteDuplicates(head);
    printList(retNode1);

    int arr4[] = {1,1,1};
    int len4 = sizeof(arr4)/sizeof(int);

    head = createLists(arr4,len4);
    printList(head);

    retNode1 = sl.deleteDuplicates(head);
    printList(retNode1);

    return 1;
}