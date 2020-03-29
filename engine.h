using namespace std;


#define MAX_SIZE_OF_MATRIX 50

struct matrix{
    double array[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
    int size;
};

struct vector{
    double array[MAX_SIZE_OF_MATRIX];
    int size;
};
void printMatrix(struct matrix a);
void printVector(struct vector v);
struct matrix readMatrix(int inputDIM, string path1);
struct vector readVector(int inputDIM, string path2);
struct matrix HST(struct matrix a);
double determinant(struct matrix a);
double cofactor(struct matrix a, int y, int x);
struct matrix inverse(struct matrix a);
struct vector computeSolution(matrix a, vector v ,matrix origin);
