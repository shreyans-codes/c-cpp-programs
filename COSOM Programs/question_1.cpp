#include <iostream>
#define ROW 2
#define COL 2

using std::cin;
using std::cout;
using std::endl;
//The Matrix class containing the matrix and basic functions
class Matrix
{
public:
    int matrix[ROW][COL];
    //To get the values
    void getValue()
    {
        int input;
        for (int i = 0; i < ROW; i++)
        {
            cout << "Row " << i + 1 << ":";
            for (int j = 0; j < COL; j++)
            {
                cin >> input;
                matrix[i][j] = input;
            }
        }
    }
    //To print the Matrix
    void printMatrix()
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    //Parameterized Contructor
    Matrix(bool)
    {
        getValue();
    }
    //Normal Constructor
    Matrix() {}
    //Desctructor
    ~Matrix() {}
};
//Function to multiply two matrices
void operator*(Matrix mat1, Matrix mat2)
{
    Matrix mulMatrix;
    int val = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            for (int k = 0; k < COL; k++)
            {
                val += mat1.matrix[i][k] * mat2.matrix[k][j];
            }
            mulMatrix.matrix[i][j] = val;
            val = 0;
        }
    }
    cout << "Result of multiplication: " << endl;
    mulMatrix.printMatrix();
}
//Function to facilitate flow of program
void assignFunction(int &choice, Matrix &mat1, Matrix &mat2)
{

    switch (choice)
    {
    case 1:
        mat1 * mat2;
        break;
    default:
        break;
    }
}

int main()
{
    //Matrix class objects
    cout << "Enter details for Matrix 1:" << endl;
    Matrix matrix1(true);
    cout << "Enter details for Matrix 2:" << endl;
    Matrix matrix2(true);

    int choice;
    do
    {
        cout << "\nSelect an operation to perform on Matrices:" << endl
             << "1. Multiplication" << endl
             << "0. Exit" << endl
             << "Your choice: ";
        cin >> choice;
        if (choice > 0 && choice <= 5)
        {
            assignFunction(choice, matrix1, matrix2);
        }
        else if (choice == 0)
        {
            cout << "See you later";
        }
        else
        {

            cout << "Incorrect option selected";
        }

    } while (choice != 0);
    return 0;
}