// Assignment: #1
// File Name: LinkedList.h
// Name:
// ASU ID:
// ASU Email Address:
// Description:

#include <iostream>
#include <iomanip> //to format the output
#include <string>
#include <stdio.h>
#include <stdlib.h>

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
    // Write a loop to traverse the linkedlist
    // Inside loop, access the title of every book
    // use removeBook method on each title.
    struct Book *tracker = head;
    struct Book *previous=NULL;
    int count=0;
    while (tracker!=NULL)
    {
        previous = tracker;
        tracker = tracker->next;
        removeBook(previous->title);
        count = count+1;
    }
    cout << "The number of deleted books is: " << count << endl;
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
   // Check if book already exits
    if (!(isFound(bookTitle)))
    {
        //Create space and initialize new entry.
        Book *new_book = new Book();
        new_book->title= bookTitle;
        new_book->pages= bookPages;
        new_book->price= bookPrice;
        
        // Search for an appropriate location for book.
        
        // Check if list is empty
        if (head!=NULL)
        {
            struct Book *tracker = head;
            struct Book *previous = NULL;
            while ((tracker !=NULL) && ((tracker->title).compare(new_book->title)<0))
            {
                previous=tracker;
                tracker = tracker->next;
            }
        
            // If new_book is smallest.
            if (tracker==head)
            {
                new_book->next=head;
                head=new_book;
            }
            
            else
            {
                previous->next = new_book;
                new_book->next = tracker;
            }
            
        
        }
        
        // If list empty
        else
        {
            new_book->next = head;
            head= new_book;
        }
        return true;
    }
    else
    {
        return false;
    }
    
}

//Removes the given book from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise.
bool LinkedList::removeBook(string bookTitle)
{
    // Locate Book
    if (isFound(bookTitle))
    {
        // Track book location
        // Update pointers to maintain list.
        // free book from temporary pointer.
        struct Book *tracker = head;
        struct Book *previous = NULL;
        struct Book *temp =NULL;
        while ((tracker->title).compare(bookTitle)!=0)
        {
            previous=tracker;
            tracker = tracker->next;
        }
        // If the book to be removed is not the first book
        if (previous != NULL)
        {
            temp = tracker;
            previous->next = tracker->next;
            tracker->next= NULL;
            delete temp;
            return true;
        }
        // If the book to be removed is the first book
        else
        {
            temp = tracker;
            head = tracker->next;
            tracker->next=NULL;
            delete temp;
            return true;
        }
       
    }
    // If book not found
    else
    {
        return false;
    }
}

//Modifies the data of the given book.
//Return true if it modifies successfully and false otherwise.
bool LinkedList::changeBookTitle(string oldBookTitle, string newBookTitle)
{
    // Check if book exists.
    if (isFound(oldBookTitle))
    {
        // Find book and change title.
        struct Book *tracker = head;
        while ((tracker->title).compare(oldBookTitle)!=0)
        {
            tracker = tracker->next;
        }
        
        tracker->title = newBookTitle;
        return true;
    }
    // If book DNE
    else
    {
        return false;
    }
}

bool LinkedList::changeBookPrice(string bookTitle, double newPrice)
{
    // Check if book exists.
    if (isFound(bookTitle))
    {
        // Find book and change Price.
        struct Book *tracker = head;
        while ((tracker->title).compare(bookTitle)!=0)
        {
            tracker = tracker->next;
        }
        
        tracker->price = newPrice;
        return true;
    }
    // If book DNE
    else
    {
        return false;
    }
}

//Prints all the elements in the linked list starting from the head node.
void LinkedList::printBookList()
{
    struct Book *tracker = head;
    while (tracker!=NULL)
    {
        //Print
        //Format----Book Title: Purple Hibiscus, 307, 14.95
        cout<< "Book Title: " << tracker->title << ", " << tracker->pages <<", "<< tracker->price <<endl;
        tracker = tracker->next;
    }
}
// Commit and push regularly!!
// Modify the tutorial branch.
// Get familiar with branching.


