
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int toDays(string date) {
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    int month = stoi(date.substr(0, 2));
    int day = stoi(date.substr(3, 2));

    int total = day;

    for (int i = 0; i < month - 1; i++) {
        total += days[i];
    }

    return total;
}

int countDaysTogether(string arriveAlice, string leaveAlice,
                      string arriveBob, string leaveBob) {
    int a1 = toDays(arriveAlice);
    int a2 = toDays(leaveAlice);
    int b1 = toDays(arriveBob);
    int b2 = toDays(leaveBob);

    return max(0, min(a2, b2) - max(a1, b1) + 1);
}

int main() {
    string arriveAlice, leaveAlice;
    string arriveBob, leaveBob;

    cout << "Enter Alice's arrival and departure dates: ";
    cin >> arriveAlice >> leaveAlice;

    cout << "Enter Bob's arrival and departure dates: ";
    cin >> arriveBob >> leaveBob;

    cout << "Days spent together: "
         << countDaysTogether(arriveAlice, leaveAlice,
                              arriveBob, leaveBob)
         << endl;

    return 0;
