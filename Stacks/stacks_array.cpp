#include <iostream>
#include <stdio.h>

#define MAX_SIZE 101

class Stack {
    
    int A[MAX_SIZE];
    int Top;

public:
    void Push(int x){
        if (Top == MAX_SIZE-1){
            std::cout<<"Error: Stack Overflow"<<std::endl;
            return;
        }
        A[++Top] = x;
    }

    void Pop(){
        if (Top == -1){
            std::cout<<"Error: No element to pop"<<std::endl;
            return;
        }
        Top--;
    }

    int Last(){
        return A[Top];
    }

    void Print(){
        int i;
        printf("Stack: ");
        for(int i=0; i<=Top; i++){
            printf("%d ", A[i]);
        }
        printf("\n");
    }

    // Construct
    Stack(){
        Top = -1;
    }
};

int main(){
    Stack s = Stack();

    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Push(10);
    s.Print();
    s.Pop();
    printf("%d \n", s.Last());
}