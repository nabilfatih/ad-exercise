#include <iostream>

// Node structure
struct Node
{
    int value;
    Node *next;

    Node(int val) : value(val), next(nullptr) {}
};

// Linked list class
class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    // Function to add a new node at the end of the list
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to print the list
    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

// Function to partition the list
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = nullptr, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is why we pass newHead and newEnd to update them
    while (cur != pivot)
    {
        if (cur->value < pivot->value)
        {
            if ((*newHead) == nullptr)
                (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            Node *tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == nullptr)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

// Recursive Quicksort function
Node *quickSortRecur(Node *head, Node *end)
{
    if (!head || head == end)
        return head;

    Node *newHead = nullptr, *newEnd = nullptr;

    Node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        Node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);

        tmp = newHead;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// The main function that sorts the linked list
void quickSort(LinkedList &list)
{
    list.head = quickSortRecur(list.head, nullptr);
}

int main()
{
    LinkedList myList;
    myList.append(10);
    myList.append(7);
    myList.append(3);
    myList.append(1);
    myList.append(9);

    std::cout << "Original List: ";
    myList.printList();

    quickSort(myList);

    std::cout << "Sorted List: ";
    myList.printList();

    return 0;
}