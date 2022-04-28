#include <iostream>
#include <fstream>
#include <array>
#include <set>
#include <algorithm>
using namespace std;

struct Character {
    int count;
    char c;
    auto operator <=> (const Character &rhs) const = default;
    friend ostream &operator<<(ostream &outs, const Character &rhs) {
        return outs << rhs.c << ": " << rhs.count;
    }
};

int main() {
    string filename;
    cout << "Please enter a filename:" << endl;
    cin >> filename;
    if(!cin)
        return 1;
    istream infile(filename);
    const int ASCII = 256;
    array<int,ASCII> count = {}; //Zero filled 256 array
    uint8_t c;
    while (cin >> c) {
        if (!cin) {
            break;
        }
        count[c]++;
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
    }
}
