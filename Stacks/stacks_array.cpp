#include <iostream>

#define MAX_SIZE 101

class Stack {

private:
    int A[MAX_SIZE];
    int Top;

public:
    // Insert an element
    void Push(int new_data){
        if (Top == MAX_SIZE-1){
            std::cout<<"Error: Stack Overflow"<<std::endl;
            return;
        }
        // Increase Top by 1, and add new_data to the stack
        A[++Top] = new_data;
    }
    
    // Remove the last element of the stack
    void Pop(){
        if (Top == -1){
            std::cout<<"Error: No element to pop"<<std::endl;
            return;
        }
        // Since Push will overwrite the actual element, we just need to decrease Top by 1.
        Top--;
    }

    // Return the last element
    int Last(){
        return A[Top];
    }

    // Display the Stack
    void Print(){

        printf("Stack: ");

        // Loop over the stack
        for(int i=0; i<=Top; i++){
            printf("%d ", A[i]);
        }
        printf("\n");
    }

    // Construct
    Stack(){
        // Initialize Top to be -1
        Top = -1;
    }
};

int main(){
    // Create an object from Stack
    Stack s = Stack();

    // Add elements
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Push(10);

    // Print the Stack
    s.Print();

    // Remove elements
    s.Pop();

    // Print the Stack
    s.Print();

    // Print the last element
    printf("%d \n", s.Last());
}