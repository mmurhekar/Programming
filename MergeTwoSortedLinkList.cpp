#include <stdio.h>

typedef struct node_t {
    int val;
    struct node_t *next;
    node_t(int val)
    {
        this->val = val;
        this->next = NULL;
    }
} node_t;

node_t *MergeList(node_t *Head1, node_t *Head2)
{
    node_t dummy(-1);
    node_t *l1 = Head1;
    node_t *l2 = Head2;
    node_t *curr = &dummy;

    // Iterate through both the Linklist and
    // add the node to the dummy list.
    while (l1 != NULL && l2 != NULL) {
        if ( l1->val <= l2->val )
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }

        // goto the next node.
        curr = curr->next;
    }

    if (l1 != NULL)
    {
        curr = l1;
    }
    else
    {
        curr = l2;
    }

    return dummy.next;
}

int main()
{
    node_t *head1 = new node_t(0);
    head1->next = new node_t(1);
    head1->next->next = new node_t(3);
    head1->next->next->next = new node_t(5);
    head1->next->next->next->next = new node_t(7);

    node_t *head2 = new node_t(-1);
    head2->next = new node_t(2);
    head2->next->next = new node_t(4);
    head2->next->next->next = new node_t(6);
    head2->next->next->next->next = new node_t(8);

    head2 = head1 = MergeList(head1, head2);

    printf("Merged LinkList: ");
    while (head2 != NULL)
    {
        printf("%d ", head2->val);
        head2 = head2->next;
    }

    return 0;
}
