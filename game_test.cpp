#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void play_game()
{
    int random = rand() % 251;
    cout<<"Let's begin"<<endl;
    cout<<"Random Number = " << random <<endl;
    while (true)
    {
        int guess;
        cin>>guess;
        if (guess == random)
        {
            cout<<"ADHBHUTH"<<endl;
            break;
        } else if(guess > random) {
            cout<<"BHUT TEZ HO RHE HO?"<<endl;
        } else {
            cout<<"ROHIT, TU ABHI BHI CHOTA HAI"<<endl;
        }
        
    }
    
}

int main()
{
    srand(time(NULL));
    int choice;
    do
    {
        cout<<"0 - Quit\n1 - Play Game"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0:
            cout<<"See you later"<<endl;
            break;
        case 1:
            play_game();
            break;
        default:
            cout<<"defaulto "<<choice<<endl;
            break;
        }
    } while (choice!=0);

    return 0;
}