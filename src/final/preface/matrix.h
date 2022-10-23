#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* using struct of pair
//? level up to pair and seeing how we can fill the constructor ourSelf
//? another looping behaviour
//? other return data types for attributes or methods
struct pairr {
    // i made it struct cauze the whole idea of this object created is to be accessed directly as a pair
    // but that doesn't mean that we can't make it a class. let's see ?
    // also cpp and other languages have some pre-built pair class that take generic types we define through the program
    int first, second;
    pairr(int first, int second) {
        this->first = first;
        this->second = second;
    }
};
class PairMatrix {
    //i used it in math4 (numerical methods) project to store the coordinates [x,y] of the matrix
private:
    int rows, cols;
    std::vector<std::vector<pairr>> matrix; //using struct

public:
    PairMatrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        matrix = std::vector<std::vector<pairr>>(rows, std::vector<pairr>(cols, pairr(0, 0))); //initializition
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j] = { i, j };
    }
    void setElement(int row, int col, pair<int, int> value) {
        matrix[row][col] = { value.first, value.second };
    }
    pair<int, int> getElement(int row, int col) {
        return { matrix[row][col].first, matrix[row][col].second };
    }
    void print() {
        for (auto& row : matrix) //std::vector of pairs
            for (auto& element : row) //pair of ints
                cout << element.first << element.second << "\n";
    }
    ~PairMatrix() {
       for (auto& row : matrix) row.clear(); //this how we clear a std::vector
    }
};
*/
// ...............................................
/* using pair generic
class PairMatrix2 {
private:
    int rows, cols;
    std::vector<std::vector<pair<int, int>>> matrix; //generic

public:
    PairMatrix2(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        matrix = std::vector<std::vector<pair<int, int>>>(rows, std::vector<pair<int, int>>(cols));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j] = { i,j };


    }
    void setElement(int row, int col, pair<int, int> value) {
        matrix[row][col] = value;
    }
    pair<int, int> getElement(int row, int col) {
        return matrix[row][col];
    }
    void print() {
        for (auto& row : matrix) //std::vector of pairs
            for (auto& element : row) //pair of ints
                cout << element.first << element.second << "\n";
    }
    ~PairMatrix2() {
        for (auto& row : matrix) row.clear(); //this how we clear a std::vector
    }
};
*/
// .....................................

class Matrix {
    //the whole idea here is inheritance
private:
    int rows, cols;
    std::vector<std::vector<int>> matrix;
public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        matrix = std::vector<std::vector<int>>(rows, std::vector<int>(cols)); //this is how wo initialize a 2d std::vector
        //we can also intialize it with values instead of garbage values

        // for (int i = 0; i < rows; i++) {
        //     for (int j = 0; j < cols; j++) {
        //         matrix[i][j] = i * rows + j;
        //     }
        // }

    }
    void setElement(int row, int col, int value) {
        //what if i only need pos values!
        // can i leave it public and let any one modify it and break my code?
        // this is encapsulation
        // any behaviour that's vary from other parts i encapsolate it so i can make my own rules
        matrix[row][col] = value;
    }
    int getElement(int row, int col) {
        return matrix[row][col];
    }
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~Matrix() {
        for (auto& row : matrix) row.clear(); //this how we clear a std::vector
    }
};

// ...............................................
/* alternative matrix using dynamic array
class Matrix2 {
private:
    int rows, cols;
    int** matrix;
public:

    Matrix2(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        matrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
    }
    void setElement(int row, int col, int value) {
        matrix[row][col] = value;
    }
    int getElement(int row, int col) {
        return matrix[row][col];
    }
    void print() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cout << matrix[i][j] << " " << "\n"[j == cols - 1];
    }
    ~Matrix2() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};
*/
// ..............................


class SymmetricMatrix : public Matrix {
public:
    SymmetricMatrix(int size) : Matrix(size, size) {}
    void setElement(int row, int col, int value) { //overriding our superclass behaviour
        Matrix::setElement(row, col, value);
        Matrix::setElement(col, row, value);
        /*
            without encapsolation here any one can modify a specific postion in the matrix
            without garantee that it will be also modified in the other side.
            remember?? it's a symmetric matrix !!

            besides that any one will use this behaviour doesn't know what is going on inside,
            he only knows that it's symetric so he expect it to be symetric.
            easy right? nothing further.
        */
    }

    /*
        can any one notice something???
        I didn't redefine print() or getElement() as they behave the same..
        see?? there is no duplication and they work just fine!!
    */
};
//the output here generated from our main program we will see everything in the session. -->




/* void print() {
        Matrix::print();
} */
