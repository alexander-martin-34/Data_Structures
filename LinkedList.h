#ifndef CHAPTER18_LINKEDLISTS_LINKEDLIST_H
#define CHAPTER18_LINKEDLISTS_LINKEDLIST_H
#include <iostream>
using namespace std;


/* 18.2 LINKED LIST OPERATIONS
 * The basic linked list operations are appending a node,
 * traversing the list, inserting a node,
 * deleting a node, and destroying the list.
 */
// Class declaration for LinkedList
class NumberList
{
private:
    //Declare structure for the list
    struct ListNode
    {
        double value;
        struct ListNode *next;
    };
    ListNode *head;
public:
    //Constructor
    NumberList()
    { head=nullptr;}
    //Destructor
    ~NumberList();

    //Linked list operations
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayList() const;
};
#endif //CHAPTER18_LINKEDLISTS_LINKEDLIST_H
