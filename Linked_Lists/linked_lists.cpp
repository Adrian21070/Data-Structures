#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

Node* head = NULL;

void Insert(int data, int n){

    Node* temp_1 = new Node();
    temp_1 -> data = data;
    temp_1 -> next = NULL;

    if(n == 1){
        temp_1 -> next = head;
        head = temp_1;
        return;
    }

    Node* temp_2 = head;

    for(int i = 0; i<n-2; i++){
        temp_2 = temp_2 -> next;
    }
    temp_1 -> next = temp_2 -> next;
    temp_2 -> next = temp_1;
};

void Print(){
};


int main(){
    head = NULL;
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
};

/*
void Insert(Node** pointerToHead, int x){
    Node* temp = new Node();
    //Node* temp = (Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;
    if(*pointerToHead != NULL){
        temp -> next = *pointerToHead;
    }

    *pointerToHead = temp;
};

void Print(Node** head){
    Node* temp = *head;

    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp -> next;
    }
    printf("\n");
};


int main() {
    Node* head = NULL;
    printf("How many numbers?\n");
    int n, x;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(&head, x);
        Print(&head);
    }
}
*/