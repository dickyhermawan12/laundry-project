#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

int globalNomorOrder = 1;

#include "structs.h"

void printEqualSign(int num){
    for(int i=0; i<num; i++){
        cout << "=";
    }
    cout << endl;
}

#include "rak.h"

#include "penerimaan.h"

#include "mesincuci.h"

#include "menu.h"

int main(){
    mainMenu.display();
}