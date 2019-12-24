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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (k == 1)
            return head;
        
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* new_head = nullptr;
        while (cur != nullptr){
            int index = 1;
            ListNode* p = cur;
            //ListNode* kStartNode = nullptr;
            //ListNode* kEndNode = nullptr;
            //kStartNode = cur;
            while (p != nullptr && index < k){
                p = p->next;
                //printf("p %p\n", p);
                index ++;
            }
           // printf("p val %d \n", p->val);
            ListNode* tail = nullptr;
            if (p){
                tail = p->next;
                ListNode* prev = nullptr;
                ListNode* curr = cur;
                int j= 1;
                while(j<=k){
                    ListNode* next = curr->next;
                    
                    curr->next = prev;
                    
                    prev = curr;
                    curr = next;
                    j++;
                }
                if (new_head == nullptr)
                    new_head = p;
                //printf("cur val %d, p val %d \n", cur->val, p->val);
                cur->next = tail;
                if (pre == nullptr)
                    pre = cur;
                else{     
                    //printf("big prev->val %d \n",prev->val);              
                    pre->next = p;
                    pre = cur;
                }
                //printf("cur next val %d, p->next val %d \n", cur->next->val,p->next->val);
                

            }
            else{
                break;
            }
            
            cur = tail;
            //printf("cur val %d \n", cur->val);
           // exit(1);
            
        }
       // printf("new_head %p, head %p\n", new_head,head);
        return (new_head==nullptr)?head:new_head;
        
    }
};


int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr)/sizeof(int);
    
    ListNode* head = createLists(arr,len);
    printList(head);
    Solution sl;
    ListNode* retNode1 = sl.reverseKGroup(head,3);
    printList(retNode1);


}