//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  private:
    Node* merge(Node* first, Node* second) {
        if (first == nullptr) {
            return second;
        } else if (second == nullptr) {
            return first;
        }
        
        Node* head = nullptr;
        if (first->data < second->data) {
            head = first;
            first = first->next;
        } else {
            head = second;
            second = second->next;
        }
        head->prev = nullptr;
        
        Node* tmp = head;
        while (first != nullptr and second != nullptr) {
            if (first->data < second->data) {
                tmp->next = first;
                first = first->next;
            } else {
                tmp->next = second;
                second = second->next;
            }
            tmp->next->prev = tmp;
            tmp = tmp->next;
        }
        
        while (first != nullptr) {
            tmp->next = first;
            first = first->next;
            tmp->next->prev = tmp;
            tmp = tmp->next;
        }

        while (second != nullptr) {
            tmp->next = second;
            second = second->next;
            tmp->next->prev = tmp;
            tmp = tmp->next;
        }
        
        tmp->next = nullptr;
        return head;
    }

  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node* sortDoubly(struct Node* head) {
        // Your code here
        if (head == nullptr or head->next == nullptr) {
            return head;
        }
        
        Node* fast = head;
        Node* slow = head;
        while (fast != nullptr and fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->prev->next = nullptr;
        slow->prev = nullptr;
        Node* first = sortDoubly(head);
        Node* second = sortDoubly(slow);
        
        return merge(first, second);
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends