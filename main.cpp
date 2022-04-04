#include <iostream>
#include "LinkedList.h"
using namespace std;

/* 18.1 INTRO TO THE LINKED LIST ADT
 * Dynamically allocated data structures may be linked together in memory to for a chain.
 *  A linked list is a series of connected nodes, where each node is a data structure.
 *  A linked list can grow or shrink in size as the program runs.
 *  This is possible because the nodes in a linked list are dynamically allocated.
 *  If new data need to be added to a linked list,
 *      the program simply allocates another node and inserts it into a series.
 *
 * Composition of Linked List
 *  Each node n a linked list contains one or more members that represent data.
 *      (such as inventory records, customer names, addresses, and telephone numbers)
 *  In addition to the data each node contains a pointer, which can point to another node
 *      A linked list is called "linked" because each node in the series has a pointer that points to the next node in the list.
 *      This creates a chain where the first node points to the second node, the second node points to the third etc..\
 *          NOTE: Nodes may be scattered around various parts of memory
 *
 * Declaration
 *  First you must declare a data structure that will be used for the nodes
 *      struct Listnode
 *      {
 *          double value;
 *          ListNode *next;
 *      };
 *  The first member of the ListNode structure is a double named value.
 *  It will be used to hold the node's data.
 *  The second member is a pointer named next.
 *  The pointer can hold the address of any object that is a ListNode structure
 *  This allows the ListNode structure to point to the next ListNode structure in the list.
 *
 *  Because he ListNode structure contains a pointer to an object of the same type as hat being declared,
 *  it is known as self referential data structure.
 *  This structure makes it possible to create nodes that point to other nodes of the same type.
 *
 *  The next step is to define a pointer to serve as list head:
 *      ListNode *head;
 *  Before you use head pointer in operations,
 *  you must be sure to initialized to nullptr because that marks the end of the list.
 *  Once you have declared a node data structure and have created a null head pointer,
 *  you have an empty linked list.
 */



/* 18.2 LINKED LIST OPERATIONS (SEE LINKEDLIST.h) */

//Appending a node to the List
    /*Create a new node.
     *Store data in the new node.
     *If there are no nodes in the list.
     *  Make the new node the first node.
     *Else
     *  Traverse the list to find the last node.
     *  add the new node to the end of the list.
     *End If
     */
void NumberList:: appendNode(double num)
{
    ListNode *newNode; // to point to a new node
    ListNode *nodePtr; // to moce through the list

    //Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    //if there are no nodes in the list
    //makes newNode the first node
    if (!head)
        head = newNode;
    else //otherwise, insert newNode at the end.
    {
        //Initialize nodePtr to head of list
        nodePtr = head;

        //Find the last node in the list
        while(nodePtr->next)
            nodePtr = nodePtr->next;

        //insert newNode as the last node
        nodePtr->next = newNode;
    }
}
//Traversing a Linked List
    /*Assign List head to node pointer
     * While node pointer is not null
     *  Display the value member of the node pointed to by node pointer
     *  Assign node pointer to its own next member
     *End While
     *
void NumberList::displayList() const
{
    ListNode *nodePtr; // move through the list

    //position nodePtr as the head of the list.
    nodePtr = head;

    //While nodePtr points to a node, traverse the list
    while (nodePtr)
    {
        //Display the value in this node.
        cout << nodePtr->value << endl;

        //Move to the next node.
        nodePtr = nodePtr->next;
    }
 }
*/
//Inserting a Node
  //This algorithm assumes the nodes in the list are already in order
    /*Create a new node
     * Store data in the new node
     * If there are no nodes in the list
     *      make the new node the first node
     * Else
     *      find the first node whose value is greater than or equal to the new
     *          value, or the end of the list (whichever is first)
     *      Insert the new node before the found node, or at the end of the list
     *          if no such node was found.
     * End If
     */
    /*This algorithm finds the first node whose value is greater than or equal to the new value
     *  The new node is then inserted before the found code.
     *  This will require the ise of two node pointers during the traversal
     *  the following is the change traversal algorithm
     */
void NumberList::insertNode(double num)
{
      ListNode *newNode;                 //A new node
      ListNode *nodePtr;                //to traverse the list
      ListNode *previousNode = nullptr; //the previous node

      //Allocate a new node and store num there.
      newNode = new ListNode;
      newNode->value = num;

      //If there are no nodes in the list
      // make newNode the first node
      if (!head)
      {
          head = newNode;
          newNode->next = nullptr;
      }
      else // Otherwise, insert newNode
      {
          //Position nodePtr at the head of the list.
          nodePtr = head;

          //Initialize previousNode to nullptr
          previousNode = nullptr;

          //skip all nodes whose value is less than num.
          while (nodePtr != nullptr && nodePtr->value < num)
          {
              previousNode = nodePtr;
              nodePtr = nodePtr->next;
          }

          //If the new node is to bethe 1st n the list,
          //insert before all other nodes.
          if (previousNode == nullptr)
          {
              head = newNode;
              newNode->next = nodePtr;
          }
          else // otherwise insert after the previous node.
          {
              previousNode->next = newNode;
              newNode->next = nodePtr;
          }
      }
}
 //ADAPTED TRAVERSAL FOR INSERTING NODE
void NumberList::displayList() const
{
    ListNode *nodePtr; // move through the list
    ListNode *previousNode = nullptr;
    //position nodePtr as the head of the list.
    nodePtr = head;
    //Initialize previousNode to nullPtr
    previousNode = nullptr;

    //While nodePtr points to a node, traverse the list
    while (nodePtr)
    {
        //Display the value in this node.
        cout << nodePtr->value << endl;

        //Move to the next node.
        nodePtr = nodePtr->next;
    }
}
//DELETING A NODE
/* The deleteNode member function searches for a node containing a particular value and deletes it from list.
 * Algorithm similar to insertNode.
 * When nodePtr points to the node that is to be deleted, previousNode->next is made to point to nodePtr->next
 * This removes the node pointed to by nodePtr from the list.
 * The final step performed by this function is to free the memory used by the node with the delete operator.
 */
void NumberList::deleteNode(double num) {
    ListNode *nodePtr;          // To traverse the list
    ListNode *previousNode;     // To point to the previous node

    //if the list is empty, do nothing
    if (!head) {
        cout << "The Linked List is empty.";
        return;
    }
    //determine if the first node is the one
    if (head->value == num) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {
        //Initialize nodePtr to head of list
        nodePtr = head;

        //Skip all nodes whose value member is
        //Not equal to num
        while (nodePtr != nullptr && nodePtr->value != num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //If nodePtr is not at the end of the list.
        //Link the precious node to the node after,
        //then delete nodePtr
        if (nodePtr) {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
//DESTROYING THE LIST
NumberList::~NumberList()
{
    ListNode *nodePtr;    //To traverse the list
    ListNode *nextNode;   //To point to the next node

    //Position nodePtr at the head of the list
    nodePtr = head;

    //While nodePtr is not at the end of the list
    while (nodePtr != nullptr)
    {
        //Save a pointer to the next node
        nextNode = nodePtr->next;

        //Delete the current node
        delete nodePtr;

        //Position nodePtr at the next node
        nodePtr = nextNode;
    }
}


//INT MAIN FOR ALL LINKED LIST OPERATIONS
int main()
{
    //Define a NumberList object
    NumberList list;

    //build the list with some values
    list.appendNode(47.5);
    list.appendNode(80.2);
    list.appendNode(300.4);

    //Insert values in list
    list.insertNode(81.3);
    list.insertNode(500.8);

    //Display the list
    cout << "Here are the initial values: " << endl;
    list.displayList();
    cout << endl;

    //Delete the values in list individually
    list.deleteNode(81.3);
    cout << "Middle value in list was deleted: " << endl;
    list.displayList();
    list.deleteNode(500.8);
    cout << "End value in list was deleted: " << endl;
    list.displayList();
    cout << endl;
    list.deleteNode(47.5);
    cout << "Head value in list was deleted: " << endl;
    list.displayList();
    cout << endl;
    list.deleteNode(300.4);
    cout << "Second to last value in list was deleted: " << endl;
    list.displayList();
    cout << endl;
    list.deleteNode(80.2);
    cout << "Last value in list was deleted: " << endl;
    list.displayList();
    cout << endl;
    list.deleteNode(10);

    return 0;
}