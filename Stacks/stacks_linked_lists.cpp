#include <iostream>

class Stack {

private:
    struct Node
    {
        int data;
        Node* next;
    };

    Node* top;

public:
    // Insert an element to the Stack
    void Push(int x){
        // Create a new node
        Node* new_node = new Node();
        // Add data
        new_node -> data = x;
        // The new element will point to the previous top
        new_node -> next = top;
        // Update top to point to the new element
        top = new_node;
    }

    // Remove the element at the top
    void Pop(){
        // Create a pointer temp
        Node *temp;

        // If top is NULL then is empty, don't do anything
        if(top == NULL) return;

        // temp will point to the actual top
        temp = top;

        // top will now point to the next element
        // Example
        // Node1 -> Node2 -> Node3 -> NULL | top -> Node1
        // top -> Node2
        top = top -> next;

        // Release memory of the previous top
        delete temp;
    }

    // Print the last inserted element
    void Last(){
        if(top == NULL) return;
        printf("Last element: %d \n", top->data);
    }

    // Print the Stack
    void Print(){
        // Pointer to the current node
        Node* current_node = top;

        printf("Stack: ");
        // While next nodes exists...
        while(current_node != NULL){
            // Print data inside the node
            printf(" %d", current_node->data);
            // current_node will now be the next node
            current_node = current_node -> next;
        }
        printf("\n");
    }

    // Construct
    Stack(){
        top = NULL;
    }
};

int main(){
    // Create an object from Stack
    Stack s = Stack();

    // Add elements
    s.Push(12);
    s.Push(4);
    s.Push(5);

    // Print the Stack
    s.Print();
    
    // Remove
    s.Pop();

    // Print last
    s.Last();

    // Print the Stack
    s.Print();

    // Add elements
    s.Push(7);

    // Print the Stack
    s.Print();
}