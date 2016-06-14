//
//  Matrix.h
//  laba_6
//
//  Created by Alexandr on 07.05.16.
//  Copyright © 2016 Kamenskiy-Dev. All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h


#endif /* Matrix_h */


#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;


template <typename type>

class matrix {
private:
    
    vector<vector<type>> matr;
    
    uint32_t M, N;
public:
    matrix() : M(0), N(0)
    {}
    
    
    matrix(uint32_t n, uint32_t m) : M(m), N(n) {
        matr.resize(N);
        for (int i = 0; i< N; i++)
            matr[i].resize(M);
    }
    
    type& operator()(int i, int j) {
        assert(i < N && j < M);
        return matr[i][j];
    }
    
    void multyply(type a)
    {
        for (int i = 0; i<= M; i++) {
            for (int j = 0; j <= N; j++) {
                matr[i][j] = a * matr[i][j];
            }
        }
    }
    
    void printMatr()
    {
        for (int i = 0; i< M; i++) {
            for (int j = 0; j < N; j++) {
                cout << "  " << matr[i][j];
            }
            cout << endl;
        }
    }
};

template <class T>
matrix<T> readMatrix()
{
    int M, N;
    cout << "Enter number of rows  ";
    cin >> N;
    
    cout << "Enter number of colomns  ";
    cin >> M;
    
    matrix<T> matr(N, M);
    
    for (int i = 0; i< N; i++) {
        for (int j = 0; j < M; j++) {
            cout << " enter [" << i << " ;" << j << "] element of matrix   ";
            cin >> matr(i, j);
        }
    }
    return matr;
};


































