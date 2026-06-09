#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;

    cout << "===== CGPA CALCULATOR =====" << endl;

    cout << "Enter number of courses: ";
    cin >> n;

    string subject[n];
    string grade[n];
    int credit[n];

    float gradePoint[n];
    float totalCredits = 0;
    float totalPoints = 0;

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter subject name: ";
        cin >> subject[i];

        cout << "Enter grade (O/A+/A/B+/B/C/U): ";
        cin >> grade[i];

        cout << "Enter credit hours: ";
        cin >> credit[i];

        // Grade conversion
        if(grade[i] == "O")
            gradePoint[i] = 10;

        else if(grade[i] == "A+")
            gradePoint[i] = 9;

        else if(grade[i] == "A")
            gradePoint[i] = 8;

        else if(grade[i] == "B+")
            gradePoint[i] = 7;

        else if(grade[i] == "B")
            gradePoint[i] = 6;

        else if(grade[i] == "C")
            gradePoint[i] = 5;

        else
            gradePoint[i] = 0;

        totalCredits += credit[i];
        totalPoints += gradePoint[i] * credit[i];
    }

    float cgpa = totalPoints / totalCredits;

    cout << "\n===== RESULT =====" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "Subject: " << subject[i]
             << " | Grade: " << grade[i]
             << " | Credit: " << credit[i]
             << endl;
    }

    cout << "\nTotal Credits = " << totalCredits << endl;
    cout << "CGPA = " << cgpa << endl;

    return 0;
}
