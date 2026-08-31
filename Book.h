#include <string>

using namespace std;
class Book
{
    private:
    string name;
    string author;
    int id;
    bool available = true;

    public:
    Book(string n, string a, int id);

    int getId() const;

    void display() const;

    void borrowBook();

    void returnBook();
};

