#include "include/lab1.h"

int main(){
    int length = 4;
    final_repr_res out2[4];
    final_representation(2, length, out2, 4./25, 0.5, 0.16, 2.);
    for (int i = 0; i < length; i++){
        printf("%d\n", out2[i]);
    }
    return 0;
}