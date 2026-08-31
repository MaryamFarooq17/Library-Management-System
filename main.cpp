#include "Library.h"
#include <iostream>

using namespace std;

int showMenu()
    {
        cout << "----------------------------" << endl;
        cout << "1.Add Book" << endl << "2.Display Books "
        << endl << "3.Search Book" << endl 
        << "4.Borrow Book" << endl << "5.Return Book" << endl
        << "6.Remove Book" << endl << "7.Exit" << endl;
        cout << "----------------------------" << endl;
         cout << "choose an option: ";
        int choice = 0;
        cin >> choice;

        return choice;
    }

int main()
{
    int choice = showMenu();

    Library L;
    while(choice!= 7)
    {
        if(choice <1 || choice >7)
        {
            cout<<  "Invalid choice\n";
        }

        try
    {        
      switch(choice)
      {
        case 1:
        {
            string name;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            
            string author;
            cout << "Author: ";
            getline(cin, author);
            
            int id;
            cout << "Book ID: ";
            cin >> id;

            Book b1(name, author, id);
            L.addBook(b1);
            break;
        }

        case 2:
        {
            L.displayBooks();
            break;   
        }

        case 3:
        {
            int enteredid;
            cout << "Enter Book ID: ";
            cin >> enteredid;

            Book &result = L.searchBook(enteredid);
            cout << "Displaying found book" << endl;
            result.display();
            break;
        }

        case 4:
        {
            int enteredid;
            cout << "Enter Book ID: ";
            cin >> enteredid;

            L.borrowBook(enteredid);
            break;
        }

        case 5: //return book
        {
            int enteredid;
            cout << "Enter Book ID: ";
            cin >> enteredid;

            L.returnBook(enteredid);
            break;
        }

        case 6:
        {
            int enteredid;
            cout << "Enter book ID: ";
            cin >> enteredid;

            L.removeBook(enteredid);
            break;
        }
        default:
        {
            cout << "Invalid choice. enter otion between 1-7\n";
            break;
        }
        }
    }
      
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
       choice = showMenu();
    }
    return 0;
}