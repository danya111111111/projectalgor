#include "inter.h"

int main(){
    int z;
    //printf(" 1,2,3,4,5,6,7 - labs : \n");
    //printf(" 11,22,33,44,55 - dops: \n");
    printf(" labs/dops : \n");
    printf(" 1,11 \n");
    printf(" 2,22 \n");
    printf(" 3,33 \n");
    printf(" 4,44 \n");
    printf(" 5,55 \n");
    printf(" 6 \n");
    printf(" 7 \n");
    printf(" input number %i", 0);
    scanf("%i",&z);
    if (z == 1)
        return  laba1();
    if (z == 2)
        return  laba2();
    if (z == 3)
        return  laba3();
    if (z == 4)
        return laba4();
    if (z == 5)
        return laba5();
    if (z == 6)
        return laba6();
    if (z == 7)
        return laba7();
    if (z == 11)
        return  laba1dop();
    if (z == 22)
        return  laba2dop();
    if (z == 33)
        return  laba3dop();
    if (z == 44)
        return laba4dop();
    if (z == 55)
        return laba5dop();
    if (z == 7)
        return laba7();
    else{
        printf(" false %i", 0);
    }
}