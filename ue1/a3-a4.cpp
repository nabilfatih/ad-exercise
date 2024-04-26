#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <chrono>

using namespace std;

class Matrix
{
private:
    int rows, cols;
    vector<vector<int>> data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
        data.resize(rows, vector<int>(cols, 0)); // Initialize all elements to 0
    }

    void init()
    {
        for (auto &row : data)
        {
            fill(row.begin(), row.end(), 0);
        }
    }

    void print()
    {
        for (const auto &row : data)
        {
            for (const auto &element : row)
            {
                cout << element << " ";
            }
            cout << endl;
        }
    };

    void input()
    {
        cout << "Enter matrix values for " << rows << " rows and " << cols << " columns:" << endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << "Enter value for [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }

    void randomFill()
    {
        srand(time(0));
        for (auto &row : data)
        {
            for (auto &element : row)
            {
                element = rand() % 10; // Random number between 0 and 9
            }
        }
    }

    Matrix add(const Matrix &M)
    {
        auto start = chrono::high_resolution_clock::now(); // Start time

        int actions = 0;

        if (this->rows != M.rows || this->cols != M.cols)
        {
            throw invalid_argument("Matrices must have the same dimensions for addition.");
        }

        Matrix result(this->rows, this->cols);

        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
                result.data[i][j] = this->data[i][j] + M.data[i][j];
                actions++;
            }
        }

        auto end = chrono::high_resolution_clock::now();                          // End time
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Time taken in microseconds

        cout << "Addition took " << duration.count() << " microseconds and " << actions << " actions." << endl;

        return result;
    }

    Matrix mult(const Matrix &M)
    {
        auto start = chrono::high_resolution_clock::now(); // Start time

        int actions = 0;

        if (this->cols != M.rows)
        {
            throw invalid_argument("Matrices must have compatible dimensions for multiplication.");
        }

        Matrix result(this->rows, M.cols);

        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < M.cols; ++j)
            {
                for (int k = 0; k < this->cols; ++k)
                {
                    result.data[i][j] += this->data[i][k] * M.data[k][j];
                    actions++;
                }
            }
        }

        auto end = chrono::high_resolution_clock::now();                          // End time
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Time taken in microseconds

        cout << "Multiplication took " << duration.count() << " microseconds and " << actions << " actions." << endl;

        return result;
    }
};

int main()
{
    Matrix matrix1(2, 3);
    matrix1.randomFill();
    std::cout << "Matrix 1:" << std::endl;
    matrix1.print();

    Matrix matrix2(2, 3);
    matrix2.randomFill();
    std::cout << "Matrix 2:" << std::endl;
    matrix2.print();

    Matrix sumMatrix = matrix1.add(matrix2);
    std::cout << "Sum of Matrix 1 and Matrix 2:" << std::endl;
    sumMatrix.print();

    // For multiplication, let's create a compatible matrix.
    Matrix matrix3(3, 2);
    matrix3.randomFill();
    std::cout << "Matrix 3:" << std::endl;
    matrix3.print();

    Matrix productMatrix = matrix1.mult(matrix3);
    std::cout << "Product of Matrix 1 and Matrix 3:" << std::endl;
    productMatrix.print();

    std::cout << "Creating a 2x3 matrix." << std::endl;
    Matrix matrix(2, 3);

    std::cout << "Please input the values for the matrix:" << std::endl;
    matrix.input();

    std::cout << "Here's your matrix:" << std::endl;
    matrix.print();

    return 0;
}