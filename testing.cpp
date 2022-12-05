#include<bits/stdc++.h>
using namespace std;
class Node{
public:
 int Value;
 Node * Next;

 Node(int val){
 Value = val;
 Next=NULL;

 }
};

void  insertToTail(Node * &head,int v)
{
    Node * newNode = new Node(v);

    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while(tmp->Next != NULL)
    {
        tmp = tmp->Next;

    }
    tmp->Next = newNode;

}

void display_list(Node * n)

{

    while (n != NULL)
    {
        cout<<n->Value;
        cout<<"->";
        n = n->Next;
    }
}

int main()
{
 Node * head =NULL;
 //4, 3, 1, 9, 2.
for(int i=1; i<=5; i++){
  int x;
 cin>>x;
 insertToTail(head,x);
}

display_list(head);

}
