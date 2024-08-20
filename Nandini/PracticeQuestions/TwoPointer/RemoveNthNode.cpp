#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *s = head;
        ListNode *p = head;
        for (int i = 0; i < n - 1; i++)
            if (s->next != NULL)
                s = s->next;

        ListNode *prev = head;
        cout << "s=" << s->val << endl;
        while (s->next != NULL)
        {
            s = s->next;
            prev = p;
            p = p->next;
        }
        if (prev == p)
        {
            if (prev->next == NULL)
                return NULL;
            else
                return prev->next;
        }

        prev->next = p->next;
        return head;
    }
};