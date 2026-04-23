#include <stdio.h>
#include <stdlib.h>

#define MY_INT_MIN -2147483648

typedef struct node {
int value;  
int size;  
struct node* next;  
} node;
node* createBlock(int value, int size) 
{
node* newBlock = (node*)malloc(sizeof(node));
newBlock->value = value;
newBlock->size = size;
newBlock->next = NULL;
return newBlock;
}
node* insertBlock(node* head, node* newBlock) 
{
if (head == NULL) 
{
head = newBlock;  
}
else 
{
node* temp = head;
while (temp->next) 
{
temp = temp->next;
}
temp->next = newBlock;
}
return head;
}
node* deallocateBlock(node* head, int pos) 
{
node* temp = head;
int i = 1;
while (temp != NULL && i < pos) 
{
temp = temp->next;
i++;
}
if (temp != NULL) 
{
temp->value = MY_INT_MIN;  
printf("Block at position %d is deallocated (marked as garbage).\n", pos);
}
return head;
}
void garbageCollection(node* head) 
{
node* temp = head;
int totalGarbage = 0;
while (temp != NULL) 
{
if (temp->value == MY_INT_MIN) 
{
totalGarbage += temp->size;
}
temp = temp->next;
}

printf("Total garbage collected: %d\n", totalGarbage);
}
void display(node* head) 
{
printf("\nCurrent memory blocks:\n");
node* temp = head;
while (temp != NULL) 
{
if (temp->value == MY_INT_MIN) 
{
printf("Garbage Block (Size: %d)\n", temp->size);  
} 
else 
{
printf("Block Value: %d, Size: %d\n", temp->value, temp->size);  
}
temp = temp->next;
}
}
int main() 
{
node* memoryList = NULL;  
int choice, value, size, pos;
while (1) 
{
printf("\n--------Memory Allocator and Garbage Collector--------\n");
printf("1. Allocate Block\n");
printf("2. Deallocate Block\n");
printf("3. Perform Garbage Collection\n");
printf("4. Display Memory Blocks\n");
printf("5. Exit\n\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) 
{
case 1:
printf("Enter the value of the block: ");
scanf("%d", &value);
printf("Enter the size of the block: ");
scanf("%d", &size);
memoryList = insertBlock(memoryList, createBlock(value, size));
break;
case 2:
printf("Enter the position of the block to deallocate: ");
scanf("%d", &pos);
memoryList = deallocateBlock(memoryList, pos);
break;
case 3:
garbageCollection(memoryList);
break;
case 4:
display(memoryList);
break;
case 5:
printf("Exiting...\n");
exit(0);
default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}


