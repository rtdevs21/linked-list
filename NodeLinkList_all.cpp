#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node * next;

    Node(int v)
    {
        value = v;
        next =NULL;
    }
};

struct Array
{
    int arrays[1000];
};

int countNode(Node * &head);
void insertToTail(Node * &head,int v);
void insertToHead(Node * &head,int v);
void insertIntoCustomPos(Node * &head,int v, int pos);
void reversedListPrint(Node * node);
void print(Node * node);
int searchNode(Node * &head,int v);
void searchDuplicateNode(Node * &head, int v);
int countNode(Node * &head);
void deleteNodeHead(Node * &head);
void deleteNodeTail(Node * &head);
void addSpecificValueAfterValue(Node * &head,int v, int pos);
void deleteIntoCustomPos(Node * &head, int pos);
void deleteBySpecificValue(Node * &head, int val);

void  insertToTail(Node * &head,int v)
{
    Node * newNode = new Node(v);

    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while(tmp->next != NULL)
    {
        tmp  = tmp->next;

    }
    tmp->next = newNode;

}

void insertToHead(Node * &head,int v)
{
    Node * newNode = new Node(v);
    newNode->next = head;
    head = newNode;

}

void insertIntoCustomPos(Node * &head, int v, int pos)
{
    int i=0;
    Node * tmp = head;

    // 12 8 // 3 10 26

    while(i<pos-2)
    {
        tmp = tmp->next; //2 3
        i++; // 1 2
    }

    Node * newNode = new Node(v);
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void print(Node * node)
{
    while(node != NULL)
    {
        cout<<node->value;
        node  = node->next;
        if(node !=NULL)
        {
            cout<<"-> ";
        }
    }
    cout<<"\n\n";
}

void reversedListPrint(Node * node)
{
    if(node == NULL)
    {
        return;
    }
    reversedListPrint(node->next);
    cout<<"-> "<<node->value;
}

int searchNode(Node * &head,int v)
{
    Node * tmp = head;
    int i=1,get=0;

    while(tmp->value != v)
    {
        //   cout<<"Finding: "<<i<<"-> "<<tmp->next<<endl;
        if(tmp->next == NULL)
        {
            cout<<"Not Found!";
            return -1;
        }
        else if(tmp!= NULL)
        {
            tmp =tmp->next;
            i++;
        }
    }

   return i;


}

void searchDuplicateNode(Node * &head, int v)
{
    Node * tmp =head;

    int i=1;
    while(tmp != NULL)
    {

        if(tmp->value == v)
        {
            cout<<i<<" ";
        }
        tmp = tmp->next;
        i++;
    }

}

int countNode(Node * &head)
{
    Node * tmp =head;
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

void addSpecificValueAfterValue(Node * &head,int insertV, int findV)
{
    int pos= searchNode(head, findV);
    cout<<"Find at: "<<pos;
    insertIntoCustomPos(head,insertV, pos+1);
}

void deleteNodeHead(Node * &head)
{
    Node * tmp = head;
    if(tmp ==NULL)
    {
        cout<<"Value not available, Please Insert First";
    }
    else
    {
        head = tmp->next;
        delete tmp;
        cout<<"Delete successful !"<<endl;

    }


}

void deleteNodeTail(Node * &head)
{
    Node * tmp = head;
    if(tmp != NULL && tmp->next != NULL)
    {
        while(tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }

        Node * delNode = tmp->next;
        tmp->next =NULL;
        delete delNode;
        cout<<"Delete successful !"<<endl;
    }
    else
    {
        if(tmp->next ==NULL) deleteNodeTail(head);
        else cout<<"Value not available, Please Insert First";
    }
}

void deleteIntoCustomPos(Node * &head, int pos)
{
    Node * tmp = head;
    int i=1;
    if(pos ==1){
       deleteNodeHead(head);
       return;
    }
    else
    while(i<pos-1 && tmp->next != NULL){
        tmp = tmp->next;
        i++;
    }
    if(tmp->next != NULL){
    Node * delNode = tmp->next;
    tmp->next = delNode->next;
    delete delNode;

    cout<<"Delete Successful!";
    }else{
    cout<<"Invalid Position!\n";
    }





}

void deleteBySpecificValue(Node * &head, int val)
{
   int pos = searchNode(head, val);

   if(pos != -1){
    deleteIntoCustomPos(head, pos);
   }else{
   cout<<"This Value Not Available into Linked List\n";
   }


}

Node * reverseNodeNonRecursive(Node * & head)
{
    Node *prev = NULL;
    Node *current = head;
    if(head == NULL){
            cout<<"Linked list is empty! ";
      return head;
    }

     Node *nextt = head->next;

   // prev 11 22 33 44
    while(true)
    {
        current->next =prev;
        prev =current;
        current = nextt;
        if(current == NULL)break;

        nextt = nextt->next;


    }
    return prev;


}

Node * reverseNodeRecursive(Node * & head)
{
    if(head == NULL || head->next == NULL){
            if(head ==NULL) cout<<"The linked list is empty! ";
        return head;
    }

        Node * newNode  = reverseNodeRecursive(head->next);
         head->next->next = head;
    head->next = NULL;

    return newNode;

}

int main()
{
    Node *head =NULL;
    int n,v,getInd;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        //  cin>>v;
        insertToTail(head, i+1);
    }

        cout<<"\n\n TO Add new Node to Head: 1";
        cout<<"\nTO Add new Node to Tail: 2";
        cout<<"\nTO Add new Node to Specific Position: 3";
        cout<<"\nTO Search Duplicate Value: 4";
        cout<<"\nTO Search Value: 5";
        cout<<"\nTO Print: 6";
        cout<<"\nTO Reverse way: 7";
        cout<<"\nTO Total Node: 8";
        cout<<"\nTO Add values Specific Value After: 9";
        cout<<"\nTO Delete head value: 10";
        cout<<"\nTO Delete Tail value: 11";
        cout<<"\nTO Delete Value From Specific Position: 12";
        cout<<"\nTO Delete By Specific Value: 13";
        cout<<"\nTO Reverse a Linear Linked List (NonRecursive): 14";
        cout<<"\nTO Reverse a Linear Linked List (Recursive): 15";
        cout<<"\nTO Exit: 0\n";
    int i=1,pos=0,x;
    while(i != 0)
    {
          print(head);

        cin>>x;

        switch(x)
        {

        case 1:
            cout<<"\nType value: ";
            cin>>v;
            insertToHead(head, v);
            break;
        case 2:
            cout<<"\nType value: ";
            cin>>v;
            insertToTail(head, v);
            break;
        case 3:
            cout<<"\nType value & position: ";
            cin>>v>>pos;;
            insertIntoCustomPos(head, v,pos);
            break;
        case 4:
            cout<<"\nType value For Searching Duplicate: ";
            cin>>v;
            searchDuplicateNode(head,v);
            break;
        case 5:
            cout<<"\nType value: ";
            cin>>v;
            getInd = searchNode(head,v);
            if(getInd != -1)cout<<"Value "<<v<<" find into "<<getInd;
            break;
        case 6:
            print(head);
            break;
        case 7:
            reversedListPrint(head);
            break;
        case 8:
            cout<<countNode(head);
            break;
        case 9:
            cout<<"Type Add Value & Specific Value to After Insert";
            cin>>v>>pos;
            addSpecificValueAfterValue(head,v,pos);
            break;
        case 10:
            deleteNodeHead(head);
            break;
        case 11:
            deleteNodeTail(head);
            break;
        case 12:
            cout<<"Type Specific Position For Delete Node";
            cin>>pos;
            deleteIntoCustomPos(head, pos);
            break;
        case 13:
            cout<<"Type Specific Value For Delete";
            cin>>v;
            deleteIntoCustomPos(head, v);
            break;
        case 14:
          head= reverseNodeNonRecursive(head);
          break;
        case 15:
          head= reverseNodeRecursive(head);
          break;
        default:
            break;
        }
    }


}
