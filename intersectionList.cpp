#include <algorithm>
//#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = getCount(headA);
        int countB = getCount(headB);
        if (countB > countA){
            std::swap(headA, headB);
            std::swap(countA, countB);
        }
        int diff = countA - countB;
        for (int i =0; i < diff; ++i){
            headA = headA->next;
        }
        while(headA != NULL){
            if (headA == headB){
                break;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    int getCount(ListNode * headA){
        if (!headA){
            return 0;
        }
        int count = 1;
        while (headA->next != NULL){
            headA = headA->next;
            ++count;
        }    
       return count;
    }

};
int main() {
Solution sol;
ListNode a(1);
sol.getIntersectionNode(&a, 0);
sol.getIntersectionNode(0, &a);

}
