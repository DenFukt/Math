#include <iostream>
#include <string>
using namespace std;

bool belongs(char x, const string &s) {
    for (char c : s)
        if (c == x) return true;
    return false;
}

void addUnique(char x, string &s) {
    if (!belongs(x, s))
        s += x;
}

int main() {
    string A, B, U = "";

    cout << "Введіть елементи множини A: ";
    cin >> A;
    cout << "Введіть елементи множини B: ";
    cin >> B;

    for (char x : A) addUnique(x, U);
    for (char x : B) addUnique(x, U);

    int UA[100] = {0}, UB[100] = {0}; 
    int n = U.size();

    for (int i = 0; i < n; i++) {
        if (belongs(U[i], A)) UA[i] = 1;
        if (belongs(U[i], B)) UB[i] = 1;
    }

    int diffAB[100], diffBA[100], compA[100], compB[100];

    for (int i = 0; i < n; i++) {
        diffAB[i] = UA[i] && !UB[i]; 
        diffBA[i] = UB[i] && !UA[i]; 
        compA[i] = !UA[i];           
        compB[i] = !UB[i];           
    }

    auto printSet = [&](int arr[]) {
        cout << "{ ";
        for (int i = 0; i < n; i++)
            if (arr[i]) cout << U[i] << " ";
        cout << "}";
    };

    auto power = [&](int arr[]) {
        int k = 0;
        for (int i = 0; i < n; i++)
            if (arr[i]) k++;
        return k;
    };

    cout << "A\\B = "; printSet(diffAB);
    cout << "  Потужність = " << power(diffAB);

    cout << "\nB\\A = "; printSet(diffBA);
    cout << "  Потужність = " << power(diffBA);

    cout << "\nA' = "; printSet(compA);
    cout << "  Потужність = " << power(compA);

    cout << "\nB' = "; printSet(compB);
    cout << "  Потужність = " << power(compB) << endl;

    return 0;
}
