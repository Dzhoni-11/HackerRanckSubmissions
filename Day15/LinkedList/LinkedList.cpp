#include <iostream>
#include <cstddef>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int d)
    {
        cout << "Created New Node" << endl;
        data = d;
        next = NULL;
    }
};

class Solution
{
public:

    Node* insert(Node* head, int data)
    {
        //Complete this method
        if (head == NULL)
        {
            head = new Node(data);
        }
        else
        {
                       // &ptr
            Node** pptr = &head->next;
            while (true)
            {
                if (*pptr == NULL)
                {
                    cout << "Breaking" << endl;
                    break;
                }
                else
                {
                    cout << "Here" << endl;
                    pptr = &(*pptr)->next;
                }
            }
            *pptr = new Node(data);
        }
        return head;
    }

    void display(Node* head)
    {
        Node* start = head;
        while (start)
        {
            cout << start->data << " ";
            start = start->next;
        }
    }
};

int main()
{
    Node* head = NULL;
    Solution mylist;
    int T, data;
    cin >> T;
    while (T-- > 0)
    {
        cin >> data;
        head = mylist.insert(head, data);
    }
    mylist.display(head);
}

