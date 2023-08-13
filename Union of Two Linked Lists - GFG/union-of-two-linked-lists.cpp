//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    Node* insertEnd(Node* root, int x)
    {
        if(root==NULL)
            return new Node(x);
        
        Node* temp = root;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(x);
        return root;
    }
    
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int> unionSet;
        
        Node* curr = head1;
        while(curr!=NULL)
        {
            unionSet.insert(curr->data);
            curr = curr->next;
        }
        
        Node* curr1 = head2;
        while(curr1!=NULL)
        {
            unionSet.insert(curr1->data);
            curr1 = curr1->next;
        }
        
        Node* root = NULL;
        for(auto i:unionSet)
        {
            root = insertEnd(root,i);
        }
        return root;
        
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends