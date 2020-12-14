/**
 * @file main.cpp
 * @author Chiamaka Okeke
 * @brief Biconjugate gradient stabilized method
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include "bicgstab.hpp"

using namespace std;

bool True = 1;
/**
 * @brief Function prototype for generating random matrices 
 * @param size Input size
 * @return Matrix Returns a matrix
 */
matrix random_matrix(size_t size);

/**
 * @brief Function prototype for generating random vectors
 * @param size Input size
 * @return Vector Returns a matrix
 */
vector<double> random_vector(size_t size);

/**
 * @brief Implemetation of the random generator for matrices of given size
 * 
 * @param size Input size
 * @return Matrix Returns a matrix
*/
matrix random_matrix(size_t size)
{
    //Implementation of uniform random number generator mt19937
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distr(0.0, 25.0);
    matrix A(size);
    for (size_t row = 0; row < size; row++)
    {
        for (size_t col = 0; col < size; col++)
        {
            A(row, col) = distr(gen);
        }
    }
    return A;
}
/**
 * @brief Implemetation of the random generator for vector of given size
 * 
 * @param size Input size
 * @return Vector Returns a matrix
 */
vector<double> random_vector(size_t size)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distr(0.0, 1.0);
    vector<double> b(size);

    for (double i = 0; i < size; i++)
    {
        b[i] = 2.0 * distr(gen);
    }
    return b;
}
/**
 * @brief Main function performs the method and also prints out the genrated matrices and vectors to a file called MAtrix_Vector.txt
 * 
 * @return int 
 */
int main()
{
    try
    {
        ///Size of matrix
        size_t size = 4;

        //Matrix A
        matrix A = random_matrix(size);

        //Vector b
        vector<double> b = random_vector(size);

        //Biconjugate stabilized method
        vector<double> X = bicgstab(A, b, True);

        //Printing to file to view generated matrix and vectors
        string filename{"Matrix_Vector.txt"};

        // Outputs the generated matrix and vector to a file and will be overwritten each time there is a new run
        ofstream output{filename};
        if (!output)
        {
            perror("Error opening output file");
            return -1;
        }
        output << "Matrix A :" << A << '\n'
               << "Vector b :" << b << '\n';
        output.close();

        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
