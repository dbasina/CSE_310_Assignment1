// Assignment: #1
// File Name: LinkedList.h
// Name:
// ASU ID:
// ASU Email Address:
// Description:

#include <iostream>
#include <iomanip> //to format the output
#include <string>

using namespace std;

//struct Book represents a LinkedList node which is a book
struct Book
{
    string title;
    int pages;
    double price;
    struct Book * next;
};

//class LinkedList will contains a linked list of books
class LinkedList
{
private:
    struct Book * head;   //head of the linked list
    
public:
    LinkedList();   //constructor
    ~LinkedList();  //destructor
    bool isFound(string bookTitle);
    bool addBook(string bookTitle, int bookPages, double bookPrice);
    bool removeBook(string bookTitle);
    bool changeBookTitle(string oldBookTitle, string newBookTitle);
    bool changeBookPrice(string bookTitle, double newPrice);
    void printBookList();
};

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Before termination, the destructor is called to free associated memory occupied by the existing linked list.
//It deletes all the nodes including the head and finally prints the number of nodes deleted by it.
LinkedList::~LinkedList()
{
    //fill in your codes here
    //----
    
    cout<< "The number of deleted books is: " << //bookCount <<"\n";
}

//A function to identify if a book is inside the LinkedList or not.
//Return true if it exists and false otherwise.
//This function is given as a guide/reference. Do NOT change it.
bool LinkedList::isFound(string bookTitle)
{
    struct Book *start = head;
    bool found = false;
    while(start != NULL)
    {
        if(start->title.compare(bookTitle)== 0)
        {
            found = true;
            break;
        }
        else
            start = start->next;
    }
    return found;
}

//Creates a new node and inserts it into the list at the right place.
//It also maintains an alphabetical ordering of the books while inserting it into the list.
//Return value: true if it is successfully inserted and false in case of other failures.
bool LinkedList::addBook(string bookTitle, int bookPages, double bookPrice)
{
    //fill in your codes here
    //----
    
}

//Removes the given book from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise.
bool LinkedList::removeBook(string bookTitle)
{
    //fill in your codes here
    //----
    
}

//Modifies the data of the given book.
//Return true if it modifies successfully and false otherwise.
bool LinkedList::changeBookTitle(string oldBookTitle, string newBookTitle)
{
    //fill in your codes here
    //----
    
}

bool LinkedList::changeBookPrice(string bookTitle, double newPrice)
{
    //fill in your codes here
    //----
    
}

//Prints all the elements in the linked list starting from the head node.
void LinkedList::printBookList()
{
    //fill in your codes here
    //----
    
}
// Adding more functionality in the Tutorial Branch

