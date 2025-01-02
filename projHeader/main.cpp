//two files proj
//other file is used for performing IO operations, this file is clean! , from cin/cout and importing iostream

#include "headers/io.h"

int main(){
    int n1 ( readNumber() );
    int n2 ( readNumber() );

    int sum = n1 + n2;
    writeAnswer(sum);

    return 0;
}