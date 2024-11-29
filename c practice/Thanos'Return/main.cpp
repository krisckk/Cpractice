#include <iostream>
#include <vector>
#include <string>
const int MAX_N = 102;
class Matrix {
    public:
        Matrix() {
            row = col = 0;
            memset(mat, 0, sizeof(mat));
        }
        // TODO
        Matrix(int r, int c);
        const int &getrow() {
            return row;
        }
        const int &getcol() {
            return col;
        }
        // TODO
        int *operator[] (const int &x);
        const int *operator[] (const int &x) const {
            return mat[x];
        }
        // TODO
        Matrix operator+ (const Matrix &x) const;
        // TODO: note that this function is declared with the keyword "friend"
        friend Matrix operator* (const Matrix &x, const Matrix &y);
        void print() {
            for(int i=0;i<row;i++) {
                if(i==0) std::cout << "/";
                else if(i==row-1) std::cout << "\\";
                else std::cout << "|";
                for(int j=0;j<col;j++) {
                    std::cout << std::right << std::setw(8) << mat[i][j];
                }
                if(i==0) std::cout << " \\\n";
                else if(i==row-1) std::cout << " /\n";
                else std::cout << " |\n";
            }
        }
    private:
        int mat[MAX_N][MAX_N];
        int row, col;
};
Matrix::Matrix(int r, int c){
    row = r;
    col = c;
    memset(mat, 0, sizeof(mat));
}
int* Matrix::operator[](const int &x){
    return mat[x];
}
Matrix Matrix::operator+(const Matrix &x) const{
	Matrix ret(row, col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
        	ret[i][j] = ((mat[i][j] + x[i][j]) % 10007 + 10007) % 10007;
        }
    }
    return ret;
}
Matrix operator* (const Matrix &x, const Matrix &y){
			Matrix a = x;
            Matrix b = y;
            Matrix ret(a.getrow(), b.getcol());
            for (int i = 0; i < ret.getrow(); i++) {
                for (int j = 0; j < ret.getcol(); j++) {
                    ret[i][j] = 0;
                    for (int k = 0; k < a.getcol(); k++) {
                        ret[i][j] = (ret[i][j] + a[i][k] * y[k][j] % 10007 + 10007) % 10007; // Modulo operation for multiplication
                    }
                }
            }
       return ret;  
}