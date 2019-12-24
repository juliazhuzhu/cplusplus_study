#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = nullptr;
        ListNode* oddTail = nullptr;
        ListNode* evenHead = nullptr;
        ListNode* evenTail = nullptr;
        ListNode* cur = head;
        int i = 1;
        while(cur != nullptr){
            if (i % 2 != 0){
                if (oddTail == nullptr){
                     oddHead = cur;
                     oddTail = cur;
                }
                else
                {
                    oddTail->next = cur;
                    oddTail = cur;
                }
                
            }else{
                if (evenTail == nullptr){
                    evenTail = cur;
                    evenHead = cur;
                }else{
                    evenTail->next = cur;
                    evenTail = cur;
                }
            }
            i++;
            cur = cur->next;
        }

        if (evenTail != nullptr)
            evenTail->next = nullptr;
        
        if (oddTail != nullptr){
            oddTail->next = evenHead;
            return oddHead;
        }

        return head;

    }
};

int main(){

    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(int);
    
    ListNode* head = createLists(arr,len);
    printList(head);

    Solution sl;
    ListNode*head2 = sl.oddEvenList(head);
    printList(head2);
    
    return 1;
}