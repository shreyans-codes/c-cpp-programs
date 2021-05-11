#include <stdio.h>

void main()
{
    int marks;
    // It will only hold 1 character
    char grade;
    printf("Enter Marks: ");
    scanf("%d", &marks);
    if (marks <= 60)
    {
        grade = 'F';
    }
    else if (marks >= 60 && marks <= 70)
    {
        grade = 'D';
    }
    else if (marks >= 70 && marks <= 80)
    {
        grade = 'C';
    }
    else if (marks >= 80 && marks <= 90)
    {
        grade = 'B';
    }
    else
    {
        grade = 'A';
    }
    switch (grade)
    {
    case 'A':
        printf("Congratulation");
        break;
    case 'B':
        printf("Congratulation. You can do better.");
        break;
    case 'C':
        printf("Bhot Badiya.");
        break;
    case 'D':
        printf("Thik Hai.");
        break;
    case 'F':
    printf("Very Bad.");
        break;
    default:
    printf("Error");
        break;
    }
}