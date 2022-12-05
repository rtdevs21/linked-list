#include<bits/stdc++.h>
using namespace std;

class doublyNode
{
public:

    int val;
    doublyNode * next;
    doublyNode * prev;

    doublyNode(int val)
    {
        this->val = val;
        next = NULL;
        prev =NULL;
    }
};

void addTohead(doublyNode * &head,int v)
{
    if(head == NULL)
    {
        doublyNode * newNode = new doublyNode(v);
        head = newNode;
        return;
    }
// create new node
    doublyNode * newNode = new doublyNode(v);
//  Update head prev
    head->prev = newNode;
//   update new node next
    newNode->next = head;
//  update of head
    head = newNode;
}

void addToTail(doublyNode * &head,int v)
{
    doublyNode * newNode = new doublyNode(v);

    if(head == NULL)
    {
        head = newNode;
        return;
    }
    doublyNode *tmp = head;
    while(tmp->next != NULL)
    {
        tmp  = tmp->next;
    }

    tmp->next = newNode;
    newNode = tmp; //add to prev
}

void printNode(doublyNode * node)
{
    while(node != NULL)
    {
        cout<<node->val;
        node  = node->next;
        if(node !=NULL)
        {
            cout<<"-> ";
        }

    }
    cout<<"\n\n";
}

void printReverseNode(doublyNode * node)
{

    doublyNode *tmp = node;
    while(tmp->next != NULL)
    {
        tmp=tmp->next;
    }

    while(tmp != NULL)
    {
        cout<<tmp->val;
        if(tmp->prev != NULL)
        {
            cout<<"-> ";
        }
        tmp=tmp->prev;
    }
    cout<<"\n\n";
}

int countNode(doublyNode * &head)
{
    doublyNode * tmp =head;
    int i=1;

    while(tmp != NULL)
    {
        tmp = tmp->next;
        i++;
    }

    if(i == 1)
    {
        return -1;
    }
    else
    {
        return i;
    }


}

int main()
{
    cout<<"TO Add new Node to Head: 1";
    cout<<"\nTO Add new Node to Tail: 2";
    cout<<"\nTO Print doublyNode 3";
    cout<<"\nTO Reverse Print doublyNode 4";
    cout<<"\nTO Counting Node 4";
    cout<<"\nTO Exit: 0 \n";

    doublyNode * head =NULL;
    int n=1,v,pos;

    while(n != 0)
    {
        cout<<"Enter- ";
        cin>>n;
        switch(n)
        {
        case 1:
            cout<<"Type value for insert to head: ";
            cin>>v;
            addTohead(head, v);
            break;
        case 2:
            cout<<"Type value for insert to tail: ";
            cin>>v;
            addToTail(head, v);
            break;
        case 3:
            printNode(head);
            break;
        case 4:
            printReverseNode(head);
            break;
        case 5:
            v = countNode(head);
            cout<<v;
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
    }
}
