#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "engine.h"



void printMatrix(struct matrix a) {
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < a.size; j++) {
            cout << setw(7) << setprecision(3) << a.array[i][j] << " ";
        }
        cout << endl;
    }
    cout <<"--------------------------------------------------"<< endl;
}

struct matrix readMatrix(int inputa.size, string path) {       //Ukládání matice na vstupu.
    struct matrix a;
    a.size = inputa.size;
    int x;
    ifstream inFile;
    inFile.open(path);
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

bool check(struct matrix a, int line, int col) {
    return a.array[line][col] != 0;
}

bool checkSingular(int numOfSteps, int DIM){
    return numOfSteps<DIM+3;
}

void zeroingElement(struct matrix a, int lineNullHead, int lineReadHead, float coef) {            //Vynuluje číslo pod diagonálou v závislosti na umístění čtecí hlavy.
    for (int i = 0; i < a.size; i++) {
        a.array[lineNullHead][i] = a.array[lineNullHead][i] + a.array[lineReadHead][i] * coef;
    }
    numberOfstep++;
}

double findCoef(struct matrix a, int lineNullHead, int lineReadHead) {
    float coef;
    return coef = (-1 * (a.array[lineNullHead][lineReadHead] / a.array[lineReadHead][lineReadHead]));
}

void zeroingElement(struct matrix a, int lineNullHead, int lineReadHead ,float coef) {            //Vynuluje číslo pod diagonálou v závislosti na umístění čtecí hlavy.

    for (int i = 0; i < a.size; i++) {
        a.array[lineNullHead][i] = a.array[lineNullHead][i] + a.array[lineReadHead][i] * coef;
    }
    numberOfstep++;
}


struct matrix HST(struct matrix a) {             //Převod do horního stupňovitého tvaru.
    int numOfLoops = 0;
    Start:
    for (int i = 0; i < a.size; i++) {         //Čtecí hlava.
        if (check(i, i) == 1) {
            for (int x = i + 1; x < a.size; x++) {    //Nulovací hlava.
                zeroingElement(x, i);
            }
        } else {
            numOfLoops++;
            if (checkSingular(numOfLoops, a.size)==1) {
                moveLine(i);             //Přesuny řádků.
                goto Start;
            } else{
                cout << "Given matrix is singular!" << endl;
                exit(2);
            }
        }
    }
}