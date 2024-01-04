#include <iostream>
#include <sstream>
using namespace std;

int calculateFine(string &dueDate, string &returnDate)
{
    istringstream ds(dueDate);
    istringstream rs(returnDate);

    int dd, dm, dy;
    int rd, rm, ry;

    char colon;

    ds >> dd >> colon >> dm >> colon >> dy;
    rs >> rd >> colon >> rm >> colon >> ry;

    if (rd <= dd && rm <= dm && ry <= dy)
    {
        return 0;
    }
    else if (dy == ry && dm == rm)
    {
        return 50;
    }
    else if (dy == ry)
    {
        return 200;
    }
    else
    {
        return 1000;
    }
}

int main()
{
    string dueDate, returnDate;

    // cout << "Enter due date (DD-MM-YYYY): ";
    cin >> dueDate;

    // cout << "Enter return date (DD-MM-YYYY): ";
    cin >> returnDate;

    int fine = calculateFine(dueDate, returnDate);

    cout << fine << endl;

    return 0;
}
