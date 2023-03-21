// Name: Het Bharatkumar Patel
// SID: 1742431
// CCID: hetbhara
// AnonID: 1000348298
// CMPUT 275, Winter 2023

// Weekly Exercise #5: Matrix Class
// -------------------------------------------

#include <iostream>
#include "matrix.h"
using namespace std;

/*
    Description: This is a Paramatrized Constructor for matrix class.
                 Initializes a new 2D matrix and initializes all the elements to init
    Arguments:
            num_rows(size_t): Number of Rows
            num_columns(size_t): Number of Columns
            init(float): The value of every element to be initialized
    Returns: None
*/
Matrix::Matrix(size_t num_rows, size_t num_columns, float init)
{
    // initializing the dimentions and size of the Matrix
    this->num_rows = num_rows;
    this->num_columns = num_columns;
    this->size = (num_rows * num_columns);

    // allocating memory to an array of float-pointers
    this->matrix = new float *[num_rows];

    // allocating memory for each row using number of columns
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new float[num_columns];
    }

    // initialize all elements of the matrix to the value of init
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            matrix[i][j] = init;
        }
    }
}

/*
    Description: This is a Paramatrized Constructor for matrix class.
                 Initializes a new 2D matrix and initializes the elements from the
                 data stored in 1D array which is pointed to 'arr_ptr'
    Arguments:
            num_rows(size_t): Number of Rows
            num_columns(size_t): Number of Columns
            arr_ptr(float*): Pointer to the 1D array of elements
    Returns: None
*/
Matrix::Matrix(size_t num_rows, size_t num_columns, float *arr_ptr)
{

    unsigned ind = 0;

    // initializing the dimentions and size of the Matrix
    this->num_rows = num_rows;
    this->num_columns = num_columns;
    this->size = (num_rows * num_columns);

    // allocating memory to an array of float-pointers
    this->matrix = new float *[num_rows];

    // allocating memory for each row using number of columns
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new float[num_columns];
    }

    // initialize all elements of the matrix by the value of stored in
    // 1D array which is pointed to arr_ptr
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            matrix[i][j] = arr_ptr[ind];
            ind++;
        }
    }
}

/*
    Description: This is a constant method of matrix class.
                 Overloads the addition '+' operator and performs addition operation on matricies
    Arguments:
            rhs(Matrix&): Reference to the matrix instances
    Returns:
            final_matrix(Matrix): Resulting matrix after applying addition operation
*/
Matrix Matrix::operator+(const Matrix &rhs) const
{
    // initializes new final_matrix using paramatrized constructor
    Matrix final_matrix = Matrix(this->num_rows, this->num_columns, 1.0);

    // apply the addition operation to each element of the matrix
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            final_matrix.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
        }
    }
    return final_matrix;
}

/*
    Description: This is a constant method of matrix class.
                 Overloads the subtraction '-' operator and performs subtraction operation on matricies
    Arguments:
            rhs(Matrix&): Reference to the matrix instances
    Returns:
            final_matrix(Matrix): Resulting matrix after applying subtraction operation
*/
Matrix Matrix::operator-(const Matrix &rhs) const
{
    // initializes new final_matrix using paramatrized constructor
    Matrix final_matrix = Matrix(this->num_rows, this->num_columns, 1.0);

    // apply the subtraction operation to each element of the matrix
    for (unsigned int i = 0; i < num_rows; i++)
    {
        for (unsigned int j = 0; j < num_columns; j++)
        {
            final_matrix.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
        }
    }
    return final_matrix;
}

/*
    Description: This is a constant method of matrix class.
                 Overloads the multiplication '*' operator and performs multiplication operation on matricies
    Arguments:
            rhs(Matrix&): Reference to the matrix instances
    Returns:
            final_matrix(Matrix): Resulting matrix after applying multiplication operation
*/
Matrix Matrix::operator*(const Matrix &rhs) const
{
    // initializes new final_matrix using paramatrized constructor
    Matrix final_matrix = Matrix(this->num_rows, rhs.num_columns, 1.0);

    // apply the multiplication operation to each element of the matrix
    for (int i = 0; i < this->num_rows; i++)
    {
        for (int j = 0; j < rhs.num_columns; j++)
        {
            float answer = 0.0;
            for (int k = 0; k < this->num_columns; k++)
            {
                answer += (this->matrix[i][k] * rhs.matrix[k][j]);
            }
            final_matrix.matrix[i][j] = answer;
        }
    }
    return final_matrix;
}

/*
    Description: This is a constant method of matrix class.
                 Overloads the negation '-' operator and performs negation operation on a matrix
                 returns a matrix where all the element's signs are flipped
    Arguments: None
    Returns:
            final_matrix(Matrix): Resulting matrix after applying negation operation
*/
Matrix Matrix::operator-() const
{
    // initializes new final_matrix using paramatrized constructor
    Matrix final_matrix = Matrix(num_rows, num_columns, 1.0);

    // apply the negation operation to each element of the matrix
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            final_matrix.matrix[i][j] = -(this->matrix[i][j]);
        }
    }
    return final_matrix;
}

/*
    Description: This is a constant method of matrix class.
                 performs transpose on a matrix
                 returns a transpose matrix by converting rows into columns and vice-versa
    Arguments: None
    Returns:
            final_matrix(Matrix): Resulting matrix after applying transpose
*/
Matrix Matrix::transpose() const
{
    // initializes new final_matrix using paramatrized constructor
    Matrix final_matrix = Matrix(num_columns, num_rows, 1.0);

    // apply the transpose to the matrix (row -> column and vice-versa)
    for (int i = 0; i < this->num_columns; i++)
    {
        for (int j = 0; j < this->num_rows; j++)
        {
            final_matrix.matrix[i][j] = this->matrix[j][i];
        }
    }
    return final_matrix;
}

/*
    Description: This is a method of matrix class.
                 Returns the index row of matrix as a float pointer
    Arguments:
            index(unsigned int): The index of Matrix
    Returns:
            float*
*/
float *Matrix::operator[](unsigned int index)
{
    return this->matrix[index];
}

const float *Matrix::operator[](unsigned int index) const
{
    return this->matrix[index];
}

/*
    Description: This is a friend function of matrix class.
                 the insertion operator reads space seperated elements from std input stream
    Arguments:
            in(istream&): Entered values of elements of a matrix
            rhs(Matrix&): Reference to the matrix instances
    Returns:
            in(istream&)
*/
istream &operator>>(istream &in, Matrix &rhs)
{
    // take the input from the user using std input stream and
    for (int i = 0; i < rhs.num_rows; i++)
    {
        for (int j = 0; j < rhs.num_columns; j++)
        {
            in >> rhs.matrix[i][j];
        }
    }
    return in;
}

/*
    Description: This is a friend function of matrix class.
                 the exertion operator prints elements of a matrix row by row
    Arguments:
            out(ostream&): Entered values of elements of a matrix
            rhs(Matrix&): Reference to the matrix instances
    Returns:
            out(ostream&)
*/
ostream &operator<<(ostream &out, const Matrix &rhs)
{
    // print the matrix row by row using std output stream
    for (int i = 0; i < rhs.num_rows; i++)
    {
        for (int j = 0; j < rhs.num_columns; j++)
        {
            if (j != rhs.num_columns - 1)
                out << rhs.matrix[i][j] << " ";
            else
                out << rhs.matrix[i][j];
        }
        if (i != rhs.num_rows - 1)
        {
            out << endl;
        }
    }
    return out;
}

/*
    Description: This is a copy constructor of matrix class.
                 returns a deep copy of a matrix
    Arguments:
            copy(const Matrix&): Constant Matrix instance
    Returns:
            None
*/
Matrix::Matrix(const Matrix &copy)
{
    // initializing the dimentions and size of the copy Matrix
    this->num_rows = copy.num_rows;
    this->num_columns = copy.num_columns;
    this->size = ((copy.num_rows) * (copy.num_columns));

    // allocating memory to an array of float-pointers
    this->matrix = new float *[num_rows];

    // allocating memory for each row using number of columns
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new float[num_columns];
    }

    // copying the old matrix and initializing the new one
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            this->matrix[i][j] = copy.matrix[i][j];
        }
    }
}

/*
    Description: This is a destructor of matrix class.
                 frees up all the allocated memory
    Arguments:
            None
    Returns:
            None
*/
Matrix::~Matrix()
{
    // unallocate the memory assigned to the matrix using 'delete'
    for (unsigned int i = 0; i < this->num_rows; i++)
    {
        if (matrix[i] != NULL)
        {
            delete[] matrix[i];
            matrix[i] = NULL;
        }
    }
    if (matrix != NULL)
    {
        delete[] matrix;
        matrix = NULL;
    }
}