// C program to merge two sorted linked lists 
// in-place. 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	struct Node* next; 
}; 

// Function to create newNode in a linkedlist 
Node* newNode(int key) 
{ 
	struct Node* temp = new Node; 
	temp->data = key; 
	temp->next = NULL; 
	return temp; 
} 

// A utility function to print linked list 
void printList(Node* node) 
{ 
	while (node != NULL) { 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 

// Merges two given lists in-place. This function 
// mainly compares head nodes and calls mergeUtil() 
Node* merge(Node* h1, Node* h2) 
{ 
	if (!h1) 
		return h2; 
	if (!h2) 
		return h1; 

	// start with the linked list 
	// whose head data is the least 
	if (h1->data < h2->data) { 
		h1->next = merge(h1->next, h2); 
		return h1; 
	} 
	else { 
		h2->next = merge(h1, h2->next); 
		return h2; 
	} 
} 

// Driver program 
int main() 
{ 

	int n,i,j,m;
    cin>>n,m;
    	Node* head1 = newNode(n); 
	
	Node* head2 = newNode(m); 
   while (n--)
   {
      cin>>i;
      newNode(i);
   }
   while (m--)
   {
      cin>>j;
      newNode(j);
   }
   

	

	Node* mergedhead = merge(head1, head2); 

	printList(mergedhead); 
	return 0; 
} 
