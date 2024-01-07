#include <stdio.h>
#include <stdlib.h>

class Stack {

private:
    struct Node
    {
        int data;
        Node* next;
    };

    Node* top;

public:

    void Push(int x){
        Node* temp = new Node();
        temp -> data = x;
        temp -> next = top;
        top = temp;
    }

    void Pop(){
        struct Node *temp;
        if(top == NULL) return;
        temp = top;
        top = top -> next;
        free(temp);
    }

    void Last(){
        if(top == NULL) return;

        printf("Last element: %d \n", top->data);
    }

    void Print(){
        Node* temp = top;

        printf("Stack: ");
        while(temp != NULL){
            printf(" %d", temp->data);
            temp = temp -> next;
        }
        printf("\n");
    }

    Stack(){
        top = NULL;
    }
};

int main(){
    Stack s = Stack();
    s.Push(12);
    s.Push(4);
    s.Push(5);
    s.Pop();
    s.Last();
    s.Push(7);
    s.Print();
}