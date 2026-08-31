#include "Book.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Book::Book(string n, string a, int id)
{
    //validation
    if(n.empty())
    {
        throw invalid_argument("No name entered\n");
    }
    name = n;

    if(a.empty())
    {
        throw invalid_argument("No author name entered\n");
    }
    author = a;

    //handling argumnt error
    if(id<= 0)
    {
        throw invalid_argument("Book ID must be positive\n"); 
    }
    this->id = id;
}

int Book::getId() const
{
    return id;
}
void Book::display() const
{
    cout << name << " "
    << author << " "
    << id << endl;
}

void Book::borrowBook()
{
    if(available)
    {
        cout << "Book borrowed successfully\n";
        available = false;
    }

    else
    {
        cout << "Book already Borrowed\n";
    }
}

void Book::returnBook()
{
    if(!available)
    {
        cout << "Book returned successfully\n";
        available = true;
    }

    else
    {
        cout << "Book already available\n";
    }
}
