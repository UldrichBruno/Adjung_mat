#include <iostream>
#include "engine.h"

int main(){
    struct matrix origin;

    int inputDIM;
    string path1;        // Example: C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt
    string path2;        // Example: C:/Users/Uzivatel/CLionProjects2/inverze_adj/vector.txt

    cout << "Welcome to program which compute inverse matrix and uses the Cramer rule to find vector x in equation A*x=b, where x, b are vectors and A is a matrix." << endl;
    cout << "Please, enter matrix A ϵ T^(n,n) and b ϵ T^n only. Otherwise this program will work badly." << endl;
    cout << "Input dimension of matrix:" << endl;
    cin >> inputDIM;
    cout << "Input path to find Your matrix in computer:" << endl;
    cin >> path1;
    cout << "Input path to read vector b." << endl;
    cin >> path2;

    origin = readMatrix(inputDIM, path1);
    cout << "Matrix A:" << endl;;
    printMatrix(origin);
    cout << "Matrix A^(-1):"<<endl;;
    printMatrix(inverse(origin));
    struct vector solution = computeSolution(origin, readVector(inputDIM, path2));
    cout << "Vector x:" << endl;;
    printVector(solution);
}