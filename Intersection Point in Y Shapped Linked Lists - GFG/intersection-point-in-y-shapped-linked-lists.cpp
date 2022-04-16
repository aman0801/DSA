// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    struct Node *curr1=head1;
    struct Node *curr2=head2;
    int count1=0;
    int count2=0;
    while(curr1!=NULL){
        count1++;
        curr1=curr1->next;
    }
     while(curr2!=NULL){
        count2++;
        curr2=curr2->next;
    }
    int diff = abs(count1-count2);
    curr1=head1;
    curr2=head2;
    if(count1>count2){
        for(int i=0;i<diff;i++){
            curr1=curr1->next;
        }
        }else if(count2>count1){
            for(int i=0;i<diff;i++){
            curr2=curr2->next;
        }
        }
        while(curr1!=curr2){
        curr1=curr1->next;
        curr2=curr2->next;
        }
        if(curr1==curr2){
            return curr1->data;
        }
        return -1;
        
    
}

