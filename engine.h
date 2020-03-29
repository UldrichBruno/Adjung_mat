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
void printVector(struct vector z);
struct matrix readMatrix(int inputDIM, string path1);       // Load matrix from a file.
struct vector readVector(int inputDIM, string path2);       // Load vector from a file.
struct matrix UTM(struct matrix a);                         // Reduce the matrix to an upper triangular matrix.
double determinant(struct matrix a);
double cofactor(struct matrix a, int y, int x);             //Compute D(j,i).
struct matrix inverse(struct matrix a);
struct vector computeSolution(struct matrix a, struct vector v);        //Compute vector x.
