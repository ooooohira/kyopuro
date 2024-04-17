#include <iostream>
#include <vector> //for vector
#include <algorithm> //for sort

using namespace std;

struct Struct {
    int num1;
    int num2;
    Struct() {
    }
    Struct(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }

    bool operator<(const Struct& another) const {
        return num1 < another.num1;
    }
};

int main() {
    vector<Struct> vec;
    vec.push_back(Struct(10, 20));
    vec.push_back(Struct(5, 5));
    vec.push_back(Struct(15, 10));

    cout << "Before" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << i << ": num1=" << vec[i].num1 << ", num2=" << vec[i].num2 << endl;
    }

    //ここでソートする
    sort(vec.begin(), vec.end());

    cout << "\nAfter" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << i << ": num1=" << vec[i].num1 << ", num2=" << vec[i].num2 << endl;
    }

    return 0;
}