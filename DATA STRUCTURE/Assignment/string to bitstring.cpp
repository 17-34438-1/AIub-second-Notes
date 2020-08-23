#include<iostream>
#include<string>
using namespace std;

struct Node{
    int c;
    char data;
    string bit = "";
    Node *next;
};
 Node *Root = NULL;

 void add_value(char c)
 {
     Node *tempnode = new Node;
     tempnode->c =1;
     tempnode->data = c;
     tempnode->next = NULL;

     if(Root == NULL)
     {
         Root = tempnode;
     }
     else
     {
         Node *t = Root;
         while(t->next != NULL)
         {
             t = t->next;
         }
         t->next = tempnode;
     }
 }

 void add_c(char data)
 {
     Node *t = Root;
     if(t->data == data)
        t->c++;
     else
     {
         while(true)
         {
             if(t->data == data)
             {
                 t->c++;
                 break;
             }
             else
                t = t->next;
         }
     }
 }

 bool src(char c)
 {
     Node *t = Root;
     if(t == NULL)
        return false;
     else
     {
         while(t!=NULL)
         {
             if(t->data == c)
                return true;
             else
                t = t->next;
         }
         return false;
     }
 }

 void counter(string s)
 {
     int l = s.size();
     for(int i=0; i<l; i++)
     {
         if(src(s[i]))
         {
             add_c(s[i]); continue;
         }
         else
         {
             add_value(s[i]); continue;
         }
     }
 }
 void sort_list()
 {
     Node *r = Root;
     int c=0;
     while(r!=NULL)
     {
         c++;
         r=r->next;
     }
     for(int i=0; i<c; i++)
     {
         Node *t = Root;
         for(int j=0; j<c; j++)
         {
             if(t->next != NULL) {
                if(t->c < t->next->c)
                {
                    Node *tempnode = new Node;
                    tempnode->c = t->c ;
                    tempnode->data = t->data ;

                    t->c = t->next->c;
                    t->data = t->next->data;

                    t->next->c = tempnode->c;
                    t->next->data = tempnode->data ;
                }
             }
             t = t->next;
         }
     }
 }
 void print()
 {
     Node *t = Root;
     cout<<endl;
     while(t!=NULL)
     {
         cout<<t->data<<" "<<t->c<<" times."<<endl;
         t = t->next;
     }
 }
 struct bst_Node
{
	int data;
	string  s = "";
	Node *n = new Node;
	bst_Node* left;
	bst_Node* right;
};

bst_Node* b_Root = NULL;

void bst()
{
    if(b_Root == NULL)
    {
        bst_Node *temp = new bst_Node;
        temp->left = NULL;
        temp->right = NULL;
        temp->n = NULL;
        temp->s = "Root";

        b_Root = temp;
        bst();
    }
    else
    {
        bst_Node *br = b_Root;
        Node *t = Root;

        while(t!=NULL)
        {
            bst_Node *temp = new bst_Node;
            temp->left = NULL;
            temp->right = NULL;
            temp->n = NULL;

            if(br->left == NULL)
            {
                br->left = temp;
                br->left->n = t;
                br->left->s = br->left->s +"0";

                t= t->next;
            }
            else if(br->left != NULL && br->right == NULL && t->next != NULL)
            {
                br->right = temp;
                br->right->s = br->right->s + "1";

                br = br->right;

                br->left = new bst_Node;
                br->left->n = t;
                br->left->s = br->left->s +"0";

                t= t->next;
            }
            else if(t->next == NULL && br->left != NULL && br->right == NULL)
            {
                br->right = temp;

                br = br->right;
                br->n = t;
                br->s = br->s +"1";
                t = t->next;
            }
        }
    }
}

void add_bit()
{
    Node *t = Root;

    while(t!=NULL)
    {
        bst_Node *br = b_Root;
        while(br!=NULL)
        {
            if(t->data == b_Root->left->n->data)
            {
                t->bit = t->bit + "0";
                break;
            }

            else if( t->data == br->left->n->data)
            {
                t->bit = t->bit + "0";
                break;
            }

            else if(br->right->n != NULL)
            {
                if(br->right->n->data == t->data) {
                t->bit = t->bit + "1";
                t->bit = t->bit + "1";
                break;
                }
                else
                    continue;
            }

            else
            {
                t->bit = t->bit + "1";
                br = br->right;
            }

        }
        t = t->next;
    }
}
void bitstring()
{
    Node *t = Root;
    while(t!=NULL)
    {
        cout<<"bit for "<<t->data<<" is : "<<t->bit<<endl;
        t = t->next;
    }
}
void print_bitstring(string s)
{
    int j = s.size();
    for(int i=0; i<j; i++)
    {
        Node *t = Root;
        while(true)
        {
            if(s[i] == t->data)
            {
                cout<<t->bit<<" ";
                break;
            }
            else
                t = t->next;
        }
    }
    cout<<endl;
}
void print_bst()
{
    cout<<"\nBst in Pre-Order with bit : ";
    bst_Node *br = b_Root;
    while(br != NULL)
    {
        if(br->n == NULL)
        {
            cout<<br->s<<"\t";
            cout<<br->left->n->data<<"  "<<br->left->s<<"\t";
            br = br->right;
        }
        else if(br->n != NULL)
        {
            cout<<br->n->data<<" "<<br->s<<"\t ";
            br = br->right;
        }
    }
    cout<<endl;
}
int main()
{
    string st;
    getline(cin,st);

    counter(st);
    sort_list();
    print();

    bst();
    print_bst();

    add_bit();
    cout<<endl;
    bitstring();

    cout<<"\n\nBitstring for "<<st<<" is: "<<endl<<endl;
    print_bitstring(st);

    return 0;
}
