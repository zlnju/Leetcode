#include<iostream>
#include "Tree.h"
#include<vector>
#include<algorithm>
#include <math.h>
#include "LinkedList.h"
#include<string>
#include<queue>

#define MaxSize 10
using namespace std;
class Solution {
    public: ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1; ListNode* p2 = l2;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        int carry = 0, x = 0, y = 0;
        while(p1 != NULL || p2 != NULL)
        {
            if(p1 == NULL) x = 0;
            else {x = p1->val; p1=p1->next;};
            if(p2 == NULL) y = 0;
            else {y=p2->val; p2=p2->next;};
            cur->next = new ListNode((carry + x + y)%10);
            cur = cur->next;
            carry = (carry + x + y)/10;
            cout<<carry<<endl;
        }
        if(carry == 1) cur->next = new ListNode(1);
        return res->next;
    }
};




int main(){
    struct ListNode *p1= new ListNode(2);
    p1->next = new ListNode(4);
    p1->next->next = new ListNode(7);
    struct ListNode *p2= new ListNode(5);
    p2->next = new ListNode(6);
    p2->next->next = new ListNode(4);
    Solution sol;
    ListNode* res = sol.addTwoNumbers(p1,p2);
    while(res!=NULL){cout<<res->val;res = res->next;}
    cout<<endl;


}