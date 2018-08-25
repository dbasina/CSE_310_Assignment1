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
    // Write a loop to traverse the linkedlist
    // Inside loop, access the title of every book
    // use removeBook method on each title.
    struct Book *tracker = head;
    struct Book *previous=nullptr;
    int count=0;
    while (tracker!=nullptr)
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
        struct Book *new_book = (struct Book*) malloc(sizeof(struct Book));
        new_book->title= bookTitle;
        new_book->pages= bookPages;
        new_book->price= bookPrice;
        
        // Search for an appropriate location for book.
        
        // Check if list is empty
        if (head!=nullptr)
        {
            struct Book *tracker = head;
            struct Book *previous = nullptr;
            while ((tracker !=nullptr) && ((tracker->title).compare(new_book->title)<0))
            {
                previous=tracker;
                tracker = tracker->next;
            }
        
            // If new book is smallest.
            if (tracker==head)
            {
                new_book->next=head;
                head=new_book;
            }
            
            // Check if new_book is greatest
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
    if (isFound(bookTitle))
    {
        struct Book *tracker = head;
        struct Book *previous = nullptr;
        struct Book *temp =nullptr;
        while ((tracker->title).compare(bookTitle)!=0)
        {
            previous=tracker;
            tracker = tracker->next;
        }
        
        if (previous != nullptr)
        {
            temp = tracker;
            previous->next = tracker->next;
            tracker->next= nullptr;
            free (temp);
            return true;
        }
        
        else
        {
            temp = tracker;
            head = tracker->next;
            tracker->next=nullptr;
            free (temp);
            return true;
        }
       
    }
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
    else
    {
        return false;
    }
}

//Prints all the elements in the linked list starting from the head node.
void LinkedList::printBookList()
{
    struct Book *tracker = head;
    while (tracker!=nullptr)
    {
        //Print
        //Book Title: Purple Hibiscus, 307, 14.95
        cout<< "Book Title: " << tracker->title << ", " << tracker->pages <<", "<< tracker->price <<endl;
        tracker = tracker->next;
    }
}
// Adding more functionality in the Tutorial Branch

