#include <iostream>

class LinkedList {

private:
    // Node structure
    struct ListNode
    {
        int data;
        ListNode* pointer;
    };

    // Head
    ListNode* head;
    
public:
    
    // Push elements (Add elements at the beggining of the list)
    void Push(int data) {

        // Create the node for the new data
        ListNode* temp = new ListNode();
        // Assign data value
        temp -> data = data;
        // For now, the new node points to NULL
        temp -> pointer = NULL;

        // If the head points to another node
        if (head != NULL) {
            // Now the new node will point to the node the head is pointing.
            temp -> pointer = head;
        }

        // The new node is now the head
        head = temp;
    }

    // Delete the First element (current head)
    void Pop() {

        // If head is Null return an error and do noting
        if (head == NULL){
            printf("Error: Cannot delete an element of an empty list\n");
            return;
        }

        // Create a temp pointer equal to head
        ListNode* temp = head;
        
        // Head will now point to the next element of the list
        head = temp -> pointer;

        // Delete the node memory
        delete temp;
    }

    // Return the size of the List
    int Size() {
        // Create a temp pointer equal to head
        ListNode* temp = head;
        // Create an accumulator int
        int size = 0;

        // We traverse over the entire list until a NULL is found
        while (temp != NULL) {
            // Next pointer will be the succesor of the current one
            temp = temp -> pointer;
            // Increase the size by 1
            size++;
        }

        return size;
    }

    // Insert an element at an index position
    void Insert(int new_data, int index) {

        /*
        This function, will insert a new node with new_data at the position of index.
        If a node is already on that position, it will be moved (virtually) from index to index + 1
        
        Example (Insert Node_99 at index 2):
        Node_1 -> Node_2 -> Node_3 -> Node_4 -> NULL
        
        Result:
        Node_1 -> Node_2 -> Node_99 -> Node_3 -> Node_4 -> NULL
        */
        
        // If index is 0, then call Push
        if (index == 0) {
            Push(new_data);
            return;
        }

        // First, a new node is constructed
        ListNode* temp = new ListNode();
        // The data is written, pointer is let in standby
        temp -> data = new_data;

        // Make a copy of the head
        ListNode* current_node = head;

        // Loop over the list until the previous node of the index is found
        for (int i=0; i <= index-2; i++) {
            // If we found a null before reaching the index, throw an error.
            if (current_node == NULL) {
                printf("Error: Index out of the list size\n");
                return;
            }

            // Update the pointer to the next element
            current_node = current_node -> pointer;
        }

        // At this moment, current_node is pointing to the previous element of the desired index.
        // The new node will point to the node that current_node currently points.
        
        // current_node -> Node 53,  ---->   New_node -> Node 53
        temp -> pointer = current_node -> pointer;
        
        // current_node -> New_node
        current_node -> pointer = temp;
    }

    // Delete a node at an index position
    void Remove(int index) {

         /*
        This function, will remove a node at the position of index.
        
        Example (Remove at index 2):
        Node_1 -> Node_2 -> Node_3 -> Node_4 -> NULL
        
        Result:
        Node_1 -> Node_2 -> Node_4 -> NULL
        */

        // If index is 0, then call Pop
        if (index == 0) {
            Pop();
            return;
        }

        // Make a copy of the head
        ListNode* current_node = head;

        // Loop over the list until the previous node of the index is found
        for (int i=0; i <= index-2; i++) {
            // If we found a null before reaching the index, throw an error.
            if (current_node == NULL) {
                printf("Error: Index out of the list size\n");
                return;
            }

            // Update the pointer to the next element
            current_node = current_node -> pointer;
        }

        // At this moment, current_node is pointing to the previous element of the desired index.
        
        // Let's save the node to be removed in temp
        ListNode* temp = current_node -> pointer;

        // If we found that temp is null, throw an error.
        if (temp == NULL) {
            printf("Error: Index out of the list size\n");
            return;
        }
        
        // current_node now will point to the next node of temp
        // current_node -> temp -> Target_Node
        // current_node -> Target_Node
        current_node -> pointer = temp -> pointer;

        // Delete the node from memory
        delete temp;
    }

    // Print the Linked List
    void Print() {
        // Create a current_node pointer from head
        ListNode* current_node = head;
        
        printf("List: ");
        while (current_node != NULL) {
            // Print the data of the current_node
            printf("%d -> ", current_node -> data);
            // Go to the next node
            current_node = current_node -> pointer;
        }
        printf("NULL\n");
    }

    // Construct
    LinkedList() {
        // Initialize the head as Null
        head = NULL;
    }

};

int main(){
    // Create an object from linked list
    LinkedList link_list = LinkedList();

    // Insert some numbers
    link_list.Push(3);
    link_list.Push(54);
    link_list.Push(2);
    link_list.Push(94);
    link_list.Push(10);
    link_list.Print();

    // Pop two elements
    link_list.Pop();
    link_list.Pop();
    link_list.Print();
    
    // Insert elements
    link_list.Insert(61, 1);
    link_list.Insert(77, 3);
    link_list.Insert(99, 0);
    link_list.Print();

    // Remove elements
    link_list.Remove(0);
    link_list.Remove(2);
    link_list.Remove(3);
    link_list.Print();

    // Print size
    printf("Size of list: %d\n", link_list.Size());
}