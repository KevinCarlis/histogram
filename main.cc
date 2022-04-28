#include <iostream>
#include <fstream>
#include <array>
#include <set>
#include <algorithm>
#include <compare>
using namespace std;

struct Character {
    int count;
    char c;
    strong_ordering operator<=> (const Character &that) const {
        if (auto cmp = count <=> that.count; cmp != 0)
            return cmp;
        if (auto cmp = c <=> that.c; cmp!= 0) {
            if (cmp == strong_ordering::less)
                return strong_ordering::greater;
            else if (cmp == strong_ordering::greater)
                return strong_ordering::less;
            return cmp;
        }
        return count <=> that.count;
    }
    /*friend bool operator> (const Character &lhs, const Character &rhs) {
        if (lhs.count > rhs.count) return true;
        else if (lhs.count < rhs.count) return false;
        else
            if (lhs.c < rhs.c) return true;
        return false;
    }*/
    friend ostream &operator<<(ostream &outs, const Character &rhs) {
        return outs << rhs.c << ": " << rhs.count;
    }
};

int main() {
   /*
    const int ASCII = 256;
    array<int,ASCII> count = {}; //Zero filled 256 array
    uint8_t c;
    cout << "Please enter a string (ctrl-d to quit):" << endl;
    while (cin >> c) {
        if (!cin) {
            break;
        }
        count[c]++;
        cout << "Please enter a string (ctrl-d to quit):" << endl;
    }
    cout << "Sorted by letter:\n";
    set<Character,greater<Character>> shor;
    for (int i = 0; i < ASCII; i++) {
        if (count[i]) {
            Character temp = {count[i], char(i)};
            cout << temp << endl;
            shor.insert(temp);
        }
    }
    cout << "Sorted by count:\n";
    for (const Character &c: shor) {
        cout << c << endl;
    }*/
    string filename;
    cout << "Please enter a filename" << endl;
    cin >> filename;
    if(!cin)
        return 1;
    ifstream infile(filename);
    const int ASCII = 256;
    array<int,ASCII> count = {}; //Zero filled 256 array
    char c;
    while (infile.get(c)) {
        if (isascii(c))
            count[c]++;
    }
    set<Character,greater<Character>> shor;
    for (int i = 0; i < ASCII; i++) {
        if (count[i]) {
            Character temp = {count[i], char(i)};
            cout << temp << endl;
            shor.insert(temp);
        }
    }
    cout << "Do you wish to sort by count?\n";
    cin >> c;
    if (c == 'y' || c == 'Y') {
        for (const Character &c: shor) {
            cout << c << endl;
    }
}
