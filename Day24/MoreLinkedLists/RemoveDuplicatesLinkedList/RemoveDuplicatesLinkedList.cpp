#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Solution
{
public:

    Node* removeDuplicates(Node* head)
    {
        //Write your code here
        vector<int> v;
        Node* start = head;
        Node* previous = NULL;
        //v.push_back(head->data);

        while (start != NULL)
        {
            // check vector for existing data
            auto found = find_if(v.begin(), v.end(), [&](auto& n) { return n == start->data; });

            // if current data not found in vector load it into vector
            if (found == v.end())
            {
                v.push_back(start->data);
                previous = start;
                start = start->next;
            }
            else // remove the node which contains the data
            {
                // update previous node's next node
                previous->next = start->next;

                // temp node for duplacate
                Node* duplicate = start;

                start = duplicate->next;

                // remove duplicate node
                delete duplicate;
            }
        }
        return head;
    }

    Node* insert(Node* head, int data)
    {
        Node* p = new Node(data);
        if (head == NULL) {
            head = p;

        }
        else if (head->next == NULL) {
            head->next = p;

        }
        else {
            Node* start = head;
            while (start->next != NULL) {
                start = start->next;
            }
            start->next = p;

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
    head = mylist.removeDuplicates(head);

    mylist.display(head);

}