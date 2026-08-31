#include "Library.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void Library::addBook(const Book &b1)
{
    //checking if this book already exists
    for(const Book &b : books)
    {
        if(b1.getId() == b.getId())
        {
            cout << "Book at this ID already exists"<< endl;
            return;
        }
    }
    books.push_back(b1);
    cout << "Book successfully added" << endl;
}

void Library::displayBooks()const
{
    for(const Book &b: books)
    {
        b.display();
    }
}

Book& Library::searchBook(int enteredid)
{
    for(Book &b : books)
    {
        if(b.getId() == enteredid)
        {
            cout << "Book found"<< endl;
            return b;
        }
    }
    throw runtime_error("Book doesnt exist");
}

void Library::borrowBook(int enteredid)
{
    Book &result = searchBook(enteredid);

    result.borrowBook();
}

void Library:: returnBook(int enteredid)
{
    Book &result = searchBook(enteredid);

    result.returnBook();
}

void Library:: removeBook(int enteredid)
{
    int i =0;
    for(const Book &b : books)
    {
        if(b.getId() == enteredid)
        {
            books.erase(books.begin() + i);
            cout << "Book removed successfully" << endl;
            return;
        }
        i++;
    }
    throw runtime_error("Book does not eixst");
}