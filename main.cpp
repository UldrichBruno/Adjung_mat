#include <iostream>
#include "engine.h"



int main(){
    struct matrix origin;

    int inputDIM;
    cout << "Input dimension of matrix:";
    cin >> inputDIM;

    string path;        // Příklad: C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt
   /* cout << "Input path to find Your matrix in computer:";
    cin >> path;*/
    path="C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt";

    origin = readMatrix(inputDIM, path);
    printMatrix(origin);

}