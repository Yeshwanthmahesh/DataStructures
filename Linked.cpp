#include<iostream>
using namespace std;

typedef struct list_node {
   int data;
   struct list_node *next; 
}node;

node *getNewNode(int data) {
   node *new_node = new node;
   new_node->data = data;
   new_node->next = NULL;
   return new_node;
}

node *searchNode(node *head, int data) {
   node *ptr = NULL;
   while (head) {
      if (head->data == data) {
         ptr = head;
         break;
      }
      head = head->next;
   }
   return ptr;
}

void displayList(node *head) {
   cout << "Displaying List : ";
   while (head != NULL) {
      cout << head->data << " -> ";
      head = head->next;
   }
   cout << "NULL " << endl;
}

node *insertNodeAfter(node *head, int element, int data) {
   node *temp = searchNode(head, element);
   if (temp == NULL) {
      cout << "Element not found ... " << endl;
   }
   else {
      node *ptr = getNewNode(data);
      if (temp->next == NULL) { 
         temp->next = ptr;
      }
      else {  
         ptr->next = temp->next;
         temp->next = ptr;
      }
   }
   return head;
}

node *insertNodeBeg(node *head, int data) {
   node *ptr = getNewNode(data);
   if (head == NULL) { // if list is empty
      head = ptr;
   }
   else {
      ptr->next = head;
      head = ptr;
   }
   return head;
}

node *deleteNode(node *head, int element) {
   node *temp = searchNode(head, element);
   if (temp == NULL) {
      cout << "Node to be deleted not found ... " << endl;
   }
   else {
      if (temp == head) {
         head = head->next;
         delete temp;
      }
      else {
         node *ptr = head;
         while (ptr->next != temp) {
            ptr = ptr->next;
         }
         ptr->next = temp->next;
         delete temp;
      }
   }
   return head;
}

int main() {
   node *head = NULL;
    displayList(head);
    head = insertNodeBeg(head, 1);
    head = insertNodeAfter(head, 1, 2);
    head = insertNodeAfter(head, 2, 3);
    head = insertNodeAfter(head, 3, 4);
    displayList(head);
    head = deleteNode(head, 1);
    displayList(head);
    head = deleteNode(head, 2);
    displayList(head);
    head = deleteNode(head, 4); 
    displayList(head);
    return 0;
}