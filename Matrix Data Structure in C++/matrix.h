// Name: Het Bharatkumar Patel
// SID: 1742431
// CCID: hetbhara
// AnonID: 1000348298
// CMPUT 275, Winter 2023

// Weekly Exercise #5: Matrix Class
// -------------------------------------------

#ifndef __MATRIX_H__
#define __MATRIX_H__

using namespace std;

class Matrix
{
public:
    // creates a new 2D matrix and initializes all the elements to init (CONSTRUCTOR)
    Matrix(size_t num_rows, size_t num_columns, float init);
    // creates a new 2D matrix and initializes all the elements to using (CONSTRUCTOR)
    // data stored in 1D array which is pointed at arr_ptr
    Matrix(size_t num_rows, size_t num_columns, float *arr_ptr);

    // overloads the addition '+' operator and performs addition operation on matricies
    // we are creating a new instances rather that modifying the objects. So, it's a constant method
    Matrix operator+(const Matrix &rhs) const;

    // overloads the subtraction '-' operator and performs subtraction operation on matricies
    // we are creating a new instances rather that modifying the objects. So, it's a constant method
    Matrix operator-(const Matrix &rhs) const;

    // overloads the multiplication '*' operator and performs multiplication operation on matricies
    // we are creating a new instances rather that modifying the objects. So, it's a constant method
    Matrix operator*(const Matrix &rhs) const;

    // returns a matrix where all the element's signs are flipped
    // we are creating a new instances rather that modifying the objects. So, it's a constant method
    Matrix operator-() const;

    // returns a transpose matrix by converting rows into columns and vice-versa
    // we are creating a new instances rather that modifying the objects. So, it's a constant method
    Matrix transpose() const;

    // returns the index row of matrix as a float pointer
    float *operator[](unsigned int index);
    const float *operator[](unsigned int index) const;

    // the insertion operator reads space seperated elements from std input stream 
    friend istream& operator>>(istream& in, Matrix& rhs);

    // the exertion operator prints elements of a matrix row by row
    friend ostream& operator<<(ostream& out, const Matrix& rhs);

    // returns a deep copy of a matrix (COPY CONSTRUCTOR)
    Matrix(const Matrix &copy);

    // frees up all the allocated memory (DESTRUCTOR)
    ~Matrix();

    // public attributes
    unsigned int num_rows, num_columns, size;

private:
    float **matrix;
};
#endif