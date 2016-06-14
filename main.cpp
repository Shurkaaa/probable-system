//
//  main.cpp
//  laba_6
//
//  Created by Alexandr on 07.05.16.
//  Copyright © 2016 Kamenskiy-Dev. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Matrix.h"
#include <iterator>

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<matrix<int>> mass(1);
    
    mass[0] = readMatrix<int>();
    mass[0].printMatr();
    
    return 0;
}