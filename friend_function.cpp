#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class BookModel
{
private:
    int noOfPages;
    string author;
    string bookName;
public:
    //* Constructor to initialize values 
    BookModel()
    {
        noOfPages = 280;
        author = "Fredrik Backman";
        bookName = "A Man Called Ove";
    }
    //* function to display data
    void displayData()
    {
        cout << endl;
        cout << "Book = " << bookName << endl;
        cout << "Author = " << author << endl;
        cout << "No Of Pages = " << noOfPages << endl;
    }
    //* Destructor
    ~BookModel()
    {
        cout << "\nDestructor Called" << endl;
    }
    //* Friend function declared
    friend void updatePages(BookModel &bModel, int newPageCount);
};
//* Friend function defined
void updatePages(BookModel &bModel, int newPageCount)
{
    bModel.noOfPages = newPageCount;
}

int main()
{
    //* Bookmodel object created
    BookModel book1;
    cout<<"\nDefault constructor values"<<endl;
    book1.displayData();
    //* friend function called
    updatePages(book1, 285);
    cout << endl
         << "Updated Data" << endl
         << endl;
    book1.displayData();
    return 0;
}