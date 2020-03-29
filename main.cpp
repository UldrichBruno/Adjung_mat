#include <iostream>
#include "engine.h"



int main(){
    struct matrix origin;

    int inputDIM;
    string path1;        // Příklad: C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt
    string path2;        // Příklad: C:/Users/Uzivatel/CLionProjects2/inverze_adj/vector.txt

    cout << "Input dimension of matrix:";
    cin >> inputDIM;
  //  cout << "Input path to read vector b." <<endl;
  //  cin >> path2;


   /* cout << "Input path to find Your matrix in computer:";
    cin >> path;*/
    path1="C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt";
    path2="C:/Users/Uzivatel/CLionProjects2/inverze_adj/vector.txt";
    origin = readMatrix(inputDIM, path1);
    printMatrix(origin);
    printMatrix(inverse(origin));
    struct vector solution = computeSolution(origin, readVector(inputDIM, path2));
    printVector(solution);


}