using namespace std;


#define MAX_SIZE_OF_MATRIX 50

struct matrix{
    float array[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
    int size;
};

bool check(int line, int col);
bool checkSingular(int numOfSteps, int DIM);
double findCoef(struct matrix a, int lineNullHead, int lineReadHead);
void zeroingElement(struct matrix a, int lineNullHead, int lineReadHead ,float coef);
void printMatrix(struct matrix a);
struct matrix readMatrix(int inputDIM, string path);
