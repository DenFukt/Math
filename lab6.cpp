#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long factorial(int n){
    if(n <= 1){
        return 1;
    }
    long long res = 1;
    for(int i = 2; i <= n; i++){
        res *= i;
    }
    return res;
}

long long C_n_k(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n - k));
}

void printCombination(const vector<int>& A){
    cout << "{ ";
    for(size_t i = 0; i < A.size(); i++){
        cout << A[i] << (i < A.size() - 1 ? ", " : " ");
    }
    cout << "}" << endl;
}

bool nextCombination(vector<int>& A, int n, int k){
    int i = k - 1;
    while(i >= 0 && A[i] == n - k + i + 1){
        i--;
    }

    if(i < 0){
        return false;
    }
    A[i]++;

    for(int j = i + 1; j < k; j++){
        A[j] = A[j - 1] + 1;
    }

    return true;
}

void printBinomialNewton(int n){
    cout << "(x + y)^" << n << " = ";

    for(int k = 0; k <= n; k++){
        long long coef = C_n_k(n, k);

        if(k > 0){
            cout << " + ";
        }
        if(coef != 1 || (n - k == 0 && k == 0)){
            cout << coef;
        }
        if(n - k > 0){
            cout << "x";
            if (n - k > 1){
                cout << "^" << (n - k);
            }
        }

        if(k > 0){
            cout << "y";
            if (k > 1){
                cout << "^" << k;
            }
        }
    }
    cout << endl;
}

int main(){
    cout << "Сполучення" << endl;
    int n_comb = 6;
    int k_comb = 4;
    cout << "Лексикографічний порядок:" << endl;

    vector<int> A(k_comb);
    for(int i = 0; i < k_comb; i++){
        A[i] = i + 1;
    }

    int counter = 1;
    do{
        cout << counter++ << ": ";
        printCombination(A);
    }while(nextCombination(A, n_comb, k_comb));

    cout << endl;

    cout << "Біном Ньютона" << endl;
    int n_binom = 9;
    printBinomialNewton(n_binom);

    return 0;
}