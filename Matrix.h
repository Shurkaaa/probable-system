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

class ptr_shared
{
private:
    type* ptr;
    static int count; //считает указатели на ptr
public:
    ptr_shared(type* p)
    {
        ptr = p;
    }
    
    ptr_shared(const ptr_shared &p)
    {
        ptr_shared pl = new type();
        pl.ptr = p.ptr;
        count++;
    }
    
    ~ptr_shared()
    {
        if (count == 1)
        {
            delete ptr;
            count = 0;
            cout << "Another crash" << endl;
        } else {
            ptr = NULL;
            count--;
        }
    }
    
    ptr_shared& operator=(ptr_shared &ptr)
    {
        count++;
        return ptr;
    }

};

template <typename type>

class ptr_unique {
private:
    type *ptr;
public:
    ptr_unique(type* p)
    {
        ptr = p;
    }
    
    ptr_unique(ptr_unique&& src)
    {
        ptr = src.ptr;
        src.ptr = nullptr;
    }
    
    ~ptr_unique()
    {
        delete ptr;
    }
};



template <typename type>

class matrix {
private:
    
    vector<vector<type>> matr;
    
    uint32_t M, N;
public:
    matrix() : M(0), N(0) {}
    
    matrix operator + (const matrix arg) const
    {
        matrix result(M, N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                result.matr[i][j] = matr[i][j] + arg.matr[i][j];
            }
        }
    }

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
