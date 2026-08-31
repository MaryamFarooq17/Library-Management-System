#include "Book.h"
#include <vector>

using namespace std;

class Library
{
    private:
    vector<Book> books;

    public:
    void addBook(const Book &b);

    void displayBooks() const;

    Book& searchBook(int enteredid);

    void borrowBook(int enteredid);

    void returnBook(int enteredid);

    void removeBook(int enteredid);
};