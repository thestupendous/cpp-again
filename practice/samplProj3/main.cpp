//two files proj
//other file is used for performing IO operations, this file is clean! , from cin/cout and importing iostream

int readNumber();
void writeAnswer(int);


int main(){
    int n1 ( readNumber() );
    int n2 ( readNumber() );

    int sum = n1 + n2;
    writeAnswer(sum);

    return 0;
}