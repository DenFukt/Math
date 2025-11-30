#include <iostream>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>>& M) {
    for (const auto& row : M) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}

void checkProperties(const vector<vector<int>>& R) {
    int n = R.size();
    bool reflexive = true, symmetric = true, antisymmetric = true, transitive = true;

    for (int i = 0; i < n; ++i) {
        if (R[i][i] == 0) reflexive = false;
        for (int j = 0; j < n; ++j) {
            if (R[i][j] != R[j][i]) symmetric = false;
            if (R[i][j] && R[j][i] && i != j) antisymmetric = false;
            for (int k = 0; k < n; ++k){
                if (R[i][j] && R[j][k] && !R[i][k]) transitive = false;
            }
        }
    }

    cout << "\n Влативості відношення:\n";
    cout << "Рефлексивне: " << (reflexive ? "так" : "ні") << endl;
    cout << "Симетричне: " << (symmetric ? "так" : "ні") << endl;
    cout << "Антисиметричне: " << (antisymmetric ? "так" : "ні") << endl;
    cout << "Транзитивне: " << (transitive ? "так" : "ні") << endl;
}

int main() {
    int nA, nB;
    cout << "Введіть кількість елементів множини A: ";
    cin >> nA;
    vector<int> A(nA);
    cout << "Елементи множини A: ";
    for (int i = 0; i < nA; ++i) cin >> A[i];

    cout << "Введіть кількість елементів множини B: ";
    cin >> nB;
    vector<int> B(nB);
    cout << "Елементи множини B: ";
    for (int i = 0; i < nB; ++i) cin >> B[i];

    vector<vector<int>> R(nA, vector<int>(nB));

    for (int i = 0; i < nA; ++i)
        for (int j = 0; j < nB; ++j)
            R[i][j] = ((2 * B[j] + 1) > A[i]) ? 1 : 0;

    cout << "\n Матриця бінарного відношення p:\n";
    printMatrix(R);

    if (A == B) checkProperties(R);
    else cout << "\n Перевірка властивостей не проводиться (A != B).\n";

    return 0;
}
