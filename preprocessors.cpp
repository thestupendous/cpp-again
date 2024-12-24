// yesab hain - ifdef, ifndef, endif,
//              if 0, if 1

#include<iostream>
using namespace std;

#define DIPAWALI_WISH

int main(){


    # if 1          //this segment will be compiled
        //print raam raam
        cout<< "Raam Raam\n";
    # endif


    # if 0          //this segment won't be compiled
                    //this can be used to comment out segments of code also
        //print hello
        cout<< "Hello\n";
    # endif

    # ifdef CHRISTMAS_WISH
        cout<< " Happy Christmass!!\n";
    #endif

    #ifdef DIPAWALI_WISH
        cout<< "Happy Dipawali !!!\n";
    #endif


    return 0;

}