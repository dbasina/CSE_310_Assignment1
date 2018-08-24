// Assignment: #1
// Name:
// ASU ID:
// ASU Email Address:
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void printMenu();

int main()
{
    // local variables, can be accessed anywhere from the main method
    char input1 = 'Z';
    string inputInfo;
    string bookTitle, oldTitle, newTitle;
    int pages;
    double price;
    string line;
    bool success = false;
    
    // instantiate a Linked List object
    LinkedList * list1 = new LinkedList();
    
    printMenu();
    
    do  // will ask for user input
    {
        cout << "\nWhat action would you like to perform?\n";
        cin.get(input1);
        input1 = toupper(input1);  //change it to upper case
        cin.ignore(20, '\n');      //flush the buffer
        
        // matches one of the case statement
        switch (input1)
        {
            case 'A':   //Add the book
                cout << "Please enter the book information:\n";
                cout << "Enter the book title:\n";
                getline(cin, bookTitle);
                cout << "Enter number of pages:\n";
                cin >> pages;
                cin.ignore(20, '\n'); //flush the buffer
                
                cout << "Enter the book price:\n";
                cin >> price;
                cin.ignore(20, '\n'); //flush the buffer
                
                success = list1->addBook(bookTitle, pages, price);
                
                if (success == true)
                    cout << "The book \"" << bookTitle << "\" is added\n";
                else
                    cout << "The book \"" << bookTitle << "\" is not added\n";
                break;
                
            case 'C':  //Change book title
                cout << "Please enter the original book title:\n";
                getline(cin, oldTitle);
                cout << "Please enter the new book title:\n";
                getline(cin, newTitle);
                
                success = list1->changeBookTitle(oldTitle, newTitle);
                if (success == true)
                    cout << oldTitle << " title was updated\n";
                else
                    cout << oldTitle << " does not exist\n";
                break;
                
            case 'D':   //Display all books
                list1->printBookList();
                break;
                
            case 'F':   //Find a book
                cout << "Please enter the book title to search:\n";
                getline(cin, bookTitle);
                success = list1->isFound(bookTitle);
                if (success == true)
                    cout << bookTitle << " was found\n";
                else
                    cout << bookTitle << " was not found\n";
                break;
                
            case 'P':  //Change a book price
                cout << "Please enter the book title you want to change the price:\n";
                getline(cin, bookTitle);
                
                if (list1->isFound(bookTitle))  //book found inside
                {
                    cout << "Please enter the new book price:\n";
                    cin >> price;
                    cin.ignore(20, '\n');   //flush the buffer
                    success = list1->changeBookPrice(bookTitle, price);
                }
                
                if (success == true)
                    cout << bookTitle << " price was updated\n";
                else
                    cout << bookTitle << " does not exist\n";
                break;
                
            case 'R':  //Remove a book from the list
                cout << "Please enter the book title to remove:\n";
                getline(cin, bookTitle);
                success = list1->removeBook(bookTitle);
                if (success == true)
                    cout << bookTitle << " was removed\n";
                else
                    cout << bookTitle << " does not exist\n";
                break;
                
            case 'Q':   //Quit
                delete list1;
                break;
                
            case '?':   //Display Menu
                printMenu();
                break;
                
            default:
                cout << "Unknown action\n";
                break;
        }
        
    } while (input1 != 'Q');
    return 0;
}

/** The method printMenu displays the menu to a user**/
void printMenu()
{
    cout << "Choice\t\tAction\n";
    cout << "------\t\t------\n";
    cout << "A\t\tAdd Book\n";
    cout << "C\t\tChange A Book Title\n";
    cout << "D\t\tDisplay All Books\n";
    cout << "F\t\tFind A Book\n";
    cout << "P\t\tChange A Book Price\n";
    cout << "R\t\tRemove Book\n";
    cout << "Q\t\tQuit\n";
    cout << "?\t\tDisplay Help\n\n";
}
