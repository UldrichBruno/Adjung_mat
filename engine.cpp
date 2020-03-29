#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "engine.h"
#include <cmath>

void printMatrix(struct matrix a) {
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < a.size; j++) {
            cout << setw(7) << setprecision(3) << a.array[i][j] << " ";
        }
        cout << endl;
    }
    cout <<"--------------------------------------------------"<< endl;
}

struct matrix readMatrix(int size, string path1) {
    struct matrix a;
    a.size = size;
    int x;
    ifstream inFile;
    inFile.open(path1);
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (inFile >> x) {
        for (int i = 0; i < a.size; i++) {
            for (int j = 0; j < a.size; j++) {
                a.array[i][j] = x;
                inFile >> x;
            }
        }
    }
    inFile.close();
    return a;
}

bool check(struct matrix a, int line, int col) {            //Catches zeroes to lead the function UTM to success.
    return a.array[line][col] != 0;
}

bool checkSingular(int numOfSteps, int inputDIM){
    return numOfSteps < inputDIM + 3;
}

struct matrix zeroingElement(struct matrix a, int lineNullHead, int lineReadHead, double coef) {            // Makes zeroes under the main diagonal.
    for (int i = 0; i < a.size; i++) {
        a.array[lineNullHead][i] = a.array[lineNullHead][i] + a.array[lineReadHead][i] * coef;
    }
return a;
}

double findCoef(struct matrix a, int lineNullHead, int lineReadHead) {                  // Finds a coefficient, which multiplies a number on the main diagonal to annul numbers below.
    double coef;
    return coef = (-1 * (a.array[lineNullHead][lineReadHead] / a.array[lineReadHead][lineReadHead]));
}


struct matrix moveLine(struct matrix a, int lineReadHead) {

    double opmatrix[MAX_SIZE_OF_MATRIX];

    for (int k = 0; k < a.size; k++) {
        opmatrix[k] = a.array[lineReadHead][k];
    }

    for (int i = lineReadHead; i < a.size; i++) {
        for (int k = 0; k < a.size; k++) {
            a.array[i][k] = a.array[i + 1][k];
        }
    }

    for (int k = 0; k < a.size; k++) {
        a.array[a.size - 1][k] = opmatrix[k];
    }
    return a;
}

struct matrix UTM(struct matrix a) {             // Upper-triangular-matrix function.
    int numOfLoops = 0;
    Start:
    for (int i = 0; i < a.size; i++) {         // ReadHead
        if (check(a, i, i) == 1) {
            for (int j = i + 1; j < a.size; j++) {    //NullHead.
               double coef = findCoef(a, j, i);
                a = zeroingElement(a, j, i, coef);
            }
        } else {
            numOfLoops++;
            if (checkSingular(numOfLoops, a.size) == 1) {
                a = moveLine(a, i);
                goto Start;
            } else{
                cout << "Given matrix is singular!" << endl;
                exit(2);
            }
        }
    }
    return a;
}

double determinant(struct matrix a){
    double det = 1;
    for (int i = 0; i < a.size; i++){
        det = det * a.array[i][i];
    }
    return det;
}

struct matrix inverse(struct matrix a){
    struct matrix b;
    b = UTM(a);
    double det = determinant(b);
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < a.size; j++) {
            b.array[i][j] = cofactor (a, i, j) / det;
        }
    }
    return b;
}

double cofactor(struct matrix a, int y, int x){
    for (int i = x; i < a.size; i++) {
        for (int j = 0; j < a.size; j++) {
            a.array[i][j] = a.array[i + 1][j];
        }
    }
    for (int i = y; i < a.size; i++) {
        for (int j = 0; j < a.size; j++)

        {
            a.array[j][i] = a.array[j][i + 1];
        }
    }
    a.size = a.size - 1;
    double c = pow(-1, x + y) * determinant(a);
    return c;
}

struct vector readVector(int size, string path2) {
    struct vector v;
    v.size = size;
    int x;
    ifstream inFile;
    inFile.open(path2);
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (inFile >> x) {
        for (int i = 0; i < v.size; i++) {
                v.array[i] = x;
                inFile >> x;
            }
    }
    inFile.close();
    return v;
}
struct vector computeSolution(struct matrix origin, struct vector v){

    struct vector z = v;
    struct matrix a = origin;
    for (int i = 0; i<v.size; i++) {
        for (int j = 0; j < v.size; j++) {
            a.array[j][i] = v.array[j];
        }
        z.array[i] = determinant(UTM(a)) / determinant(UTM(origin));
        a = origin;
    }
        return z;
}

void printVector(struct vector z) {
    for (int i = 0; i < z.size; i++) {
            cout << setw(7) << setprecision(3) << z.array[i]<< " ";
        }
        cout << endl;
    cout <<"--------------------------------------------------"<< endl;
}