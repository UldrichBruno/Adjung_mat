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

struct matrix readMatrix(int size, string path) {       //Ukládání matice na vstupu.
    struct matrix a;
    a.size = size;
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

bool checkSingular(int numOfSteps, int inputDIM){
    return numOfSteps<inputDIM+3;
}

void zeroingElement(struct matrix a, int lineNullHead, int lineReadHead, float coef) {            //Vynuluje číslo pod diagonálou v závislosti na umístění čtecí hlavy.
    for (int i = 0; i < a.size; i++) {
        a.array[lineNullHead][i] = a.array[lineNullHead][i] + a.array[lineReadHead][i] * coef;
    }
  //  numberOfstep++;
}

double findCoef(struct matrix a, int lineNullHead, int lineReadHead) {
    float coef;
    return coef = (-1 * (a.array[lineNullHead][lineReadHead] / a.array[lineReadHead][lineReadHead]));
}


void moveLine(struct matrix a, int lineReadHead) {        //Odsun řádku kvůli nevyhovujícímu nulovému prvku pod čtecí hlavou na poslední řádek.

    double opmatrix[MAX_SIZE_OF_MATRIX];

    for (int k = 0; k <a.size; k++) {
        opmatrix[k] = a.array[lineReadHead][k];
    }

    for (int i = lineReadHead; i < a.size; i++) {
        for (int k = 0; k < a.size; k++) {
            a.array[i][k] = a.array[i + 1][k];
        }
    }

    for (int k = 0; k < a.size; k++) {
        a.array[a.size][k] = opmatrix[k];
    }
}

struct matrix HST(struct matrix a) {             //Převod do horního stupňovitého tvaru.
    int numOfLoops = 0;
    Start:
    for (int i = 0; i < a.size; i++) {         //Čtecí hlava.
        if (check(i, i) == 1) {
            for (int x = i + 1; x < a.size; x++) {    //Nulovací hlava.
                zeroingElement(struct matrix origin, x, i, float coef);
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