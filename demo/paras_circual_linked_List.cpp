#include<iostream>
using namespace std;

int count = 0;

struct node{
    int data;
    struct node* next;
};

class linked_list{
    private:
    struct node* head;

    public:

    linked_list (){
        head == NULL;
    }

    void traverse()
    {
        node* temp = head;
        int i = 1;
        while(temp->next != head)
        {
            cout<<"This is node "<<i<<endl;
            i++;
            temp = temp->next;
        } 
        cout<<"This is node "<<i<<endl;
    }

void push_back(int value){

        node* newnode = new node();
        int count = 1;
        newnode->data = value;
        newnode->next = head;

        if(head == NULL){
            head = newnode;
            count ++;

        }
        else{
            node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newnode;
            count ++;
        }
    }

    void push_front(int value)
    {

        struct node* newnode = new node();

        newnode->data = value;


        if(head == NULL){
            newnode->next = head;
            head = newnode;
            count ++;
        }
        else{
            newnode->next = head;
            node* temp = head;


            while(temp->next != head){
                temp = temp->next;
            }


            temp->next = newnode;
            head = newnode;
            delete(temp);
            count ++;
        }

    }

    void display()
    {
        if(head == NULL)
        {
            cout<<"The list is empty!"<<endl;
        }
        else{
            node* temp = head;

        while(temp->next != head){
            cout<<temp->data<<" ";
        }
        cout<<temp->data<<endl;
        }

    }



};


int main()
{
    linked_list new_list;
    // cout<<"The number of items in list are : "<<count<<endl;
    new_list.push_front(54);
    // cout<<"The number of items in list are : "<<count<<endl;
    // new_list.push_back(444);
    // cout<<"The number of items in list are : "<<count<<endl;
    // new_list.push_front(5);
    // cout<<"The number of items in list are : "<<count<<endl;




    new_list.display();

    return 0;
}