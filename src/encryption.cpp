#include "encryption.h"

int encrypt(int message, int key){

    if (message + key > 100)
    {
        return  message + key - 100;
    }
    
    return  message + key;

}

int decrypt(int cipher,int key){

    if (cipher - key < 1)
    {
        return  100 + cipher - key;
    }

    return cipher - key;
    

}