#include<stdio.h>
#include<stdlib.h>

// Creating a structure for node...
struct Node{
    int data;
    struct Node * next;
};
// Inserting Nodes
void addAtBeginning(struct Node * head,int val){
    struct Node * newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = val;
    newNode -> next = head -> next;
    head -> next = newNode;
}

void addAtLocation(struct Node * head,int val, int location){
    struct Node * current = head;
    struct Node * previous = NULL;
    if(location < 1){
        printf("Invalid location");
        return;
    }
    for(register int i = 0 ; i < location ; i++){
        if(i == location-1){
            previous = current;
        }
        current = current -> next;
        if(current == NULL){
            break;
        }
    }

    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = val;
    newNode -> next = current;
    previous -> next = newNode;

}

void addAtEnd(struct Node * head,int val){
    struct Node * newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = val;
    newNode -> next = NULL; // Assigning NULL to next field of newNode
    
    struct Node * ptr = head;
    while (ptr -> next != NULL) {
        ptr = ptr -> next;
    }
    
    ptr -> next = newNode;
}

// Deleting from the linked list
void deleteAtBeginning(struct Node * head){
    struct Node * ptr = head -> next;
    head -> next = ptr -> next;
    free(ptr);
}

void deleteAtLocation(struct Node * head, int location){
    if(location < 1){
        printf("Invalid Location\n");
        return;
    }
    struct Node * ptr = head;
    struct Node * before, * after;
    for(register int i = 0 ; i < location ; i++){
        before = ptr;
        ptr = ptr -> next;
        if(ptr == NULL){
            printf("Location out of bounds!\n");
            return;
        }
    }
    after = ptr -> next;
    before -> next = after;
    free(ptr);
}

void deleteAtEnd(struct Node * head){
    struct Node * ptr = head;
    struct Node * previous;
    while(ptr -> next != NULL){
        previous = ptr;
        ptr = ptr -> next;
    }
    previous -> next = NULL;
    free(ptr);
}

//  Displaying the linked list(traversing also)
void display(struct Node * head){
    struct Node* current = head;
    printf("Linked List: ");
    current = head -> next; 
    while (current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");

}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); 
    head->data = 0;
    head->next = 0;

    int opt_1,opt_2,val,loc;
        //cli design done here
    while(1){
        printf("Enter Option: 1. Insert 2. Delete 3. Display - ");
        scanf("%d",&opt_1);
        switch(opt_1){
            case 1:
                printf("Enter Option: 1. At Beginning 2. At Location 3. At End - ");
                scanf("%d",&opt_2);
                switch (opt_2)
                {
                    case 1:
                        printf("Enter value to be added at start: ");
                        scanf("%d",&val);
                        addAtBeginning(head,val);
                        break;
                    case 2:
                        printf("Enter value & location: ");
                        scanf("%d%d",&val,&loc);
                        addAtLocation(head,val,loc);
                        break;
                    case 3:
                        printf("Enter value to be added at end: ");
                        scanf("%d",&val);
                        addAtEnd(head,val);
                        break;
                    default:
                    printf("Invalid Option!\n");
                        break;
                }
                break;

            case 2:
                printf("Enter Option: 1. From Beginning 2. From Location 3. From End - ");
                scanf("%d",&opt_2);
                switch (opt_2)
                {
                    case 1:
                        deleteAtBeginning(head);
                        printf("Value has been deleted from start of linked list!\n");
                        break;
                    case 2:
                        printf("Enter location from which value is to be deleted: ");
                        scanf("%d",&loc);
                        deleteAtLocation(head,loc);
                        break;
                    case 3:
                        deleteAtEnd(head);
                        printf("Value has been deleted from end of linked list!\n");
                        break;
                    default:
                        printf("Invalid Option!\n");
                        break;
                }
                break;

            case 3:
                display(head);
                break;
            default:
                printf("Invalid Option!\n");
                break;
        }
    }   
    return 0;
}
