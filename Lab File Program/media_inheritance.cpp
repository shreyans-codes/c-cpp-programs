#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//? The Media class containing virtual functions
class Media
{
protected:
    string title;
    string publication;

public:
    //* Read Function to get and set the details
    virtual void read()
    {
        cout << "Enter Title : ";
        cin >> title;
        cout << "Enter Publication : ";
        cin >> publication;
    }
    //* Show function to print the details
    virtual void show()
    {
        cout << endl
             << endl;
        cout << "Title : " << title;
        cout << "\nPublication : " << publication;
    }
};

//? The Book class inheriting Media class publically
class Book : public Media
{
private:
    int page_length;
    string author;

public:
    //* The read and show function are defined here
    void read()
    {
        Media::read();
        cout << "Enter number of pages : ";
        cin >> page_length;
        cout << "Enter the name of the author : ";
        cin >> author;
    }
    void show()
    {
        Media::show();
        cout << "\nNumber of number of pages : " << page_length;
        cout << "\nAuthor Name : " << author<<endl;
    }
};
//? The Tape class inheriting Media class publically
class Tape : public Media
{
    int playing_time;
    void read()
    {
        Media::read();
        cout << "Enter the playing time : ";
        cin >> playing_time;
    }
    void show()
    {
        Media::show();
        cout << "\nPlaying Time : " << playing_time << endl;
    }
};

//* Function to get the choice of the user and return it. It simplifies the code and adds reusablity
int getChoice()
{
    int choice;
    cout << "\n1. Read\n2. Show\n0. Main Menu\nEnter your choice : ";
    cin >> choice;
    return choice;
}

int main()
{
    //* Pointer to a media class object
    Media *m = new Media;
    int c = 0, n = 0;
    //? This do-while loop determines which object to be created - Book or Tape
    do
    {
        cout << "1. Book\n2. Tape\n0. Exit\nEnter your choice : ";
        cin >> c;
        //* Switch Case to assign proper functions
        switch (c)
        {
        case 1:
            n = 0;
            m = new Book;
            //? This loop determines which function to be called
            do
            {
                n = getChoice();
                switch (n)
                {
                case 1:
                    m->read();
                    break;
                case 2:
                    m->show();
                    break;
                case 0:
                    break;
                default:
                    cout << "Please Select an appropriate option";
                    break;
                }
            } while (n != 0);
            break;
        case 2:
            n = 0;
            m = new Tape;
            //? This loop determines which function to be called
            do
            {
                n = getChoice();
                switch (n)
                {
                case 1:
                    m->read();
                    break;
                case 2:
                    m->show();
                    break;
                case 0:
                    break;
                default:
                    cout << "Please Select an appropriate option";
                    break;
                }
            } while (n != 0);
            break;
        //? The Exit Case
        case 0:
            cout << "Thank You!";
            break;
        //? The default case
        default:
            cout << "Please Select an appropriate option";
            break;
        }
    } while (c != 0);
}