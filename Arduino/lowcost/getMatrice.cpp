#include <Arduino.h>
#include "getMatrice.h"

unsigned char front_left[8] ={
0b00000000,
0b01111000,
0b01100000,
0b01010000,
0b01001000,
0b00000100,
0b00000010,
0b00000000
};

unsigned char front_right[8] ={
0b00000000,
0b00011110,
0b00000110,
0b00001010,
0b00010010,
0b00100000,
0b01000000,
0b00000000
};

unsigned char front[8] ={
0b00000000,
0b00010000,
0b00111000,
0b01111100,
0b00010000,
0b00010000,
0b00010000,
0b00000000
};

unsigned char right[8] ={
0b00000000,
0b00001000,
0b00001100,
0b01111110,
0b00001100,
0b00001000,
0b00000000,
0b00000000
};

unsigned char left[8] ={
0b00000000,
0b00010000,
0b00110000,
0b01111110,
0b00110000,
0b00010000,
0b00000000,
0b00000000
};

unsigned char* getMatrice(const char s[4])
{
    if(strcmp(s, "0201") == 0)
    return right;
    else if(strcmp(s, "0202") == 0)
    return right;
    else if(strcmp(s, "0203") == 0)
    return right;
    else if(strcmp(s, "0204") == 0)
    return right;
    else if(strcmp(s, "0205") == 0)
    return right;
    else if(strcmp(s, "0206") == 0)
    return right;
    else if(strcmp(s, "0207") == 0)
    return right;
    else if(strcmp(s, "0208") == 0)
    return right;
    else if(strcmp(s, "0209") == 0)
    return right;
    else if(strcmp(s, "0210") == 0)
    return right;
    else if(strcmp(s, "0211") == 0)
    return right;
    else if(strcmp(s, "0212") == 0)
    return front_right;
    else if(strcmp(s, "0213") == 0)
    return front_right;
    else if(strcmp(s, "0214") == 0)
    return front_right;
    else if(strcmp(s, "0215") == 0)
    return front_right;
    else if(strcmp(s, "0216") == 0)
    return front_right;
    else if(strcmp(s, "0217") == 0)
    return front_right;
    else if(strcmp(s, "0218") == 0)
    return front_right;
    else if(strcmp(s, "0219") == 0)
    return front;
    else if(strcmp(s, "0220") == 0)
    return front;
    else if(strcmp(s, "0221") == 0)
    return front;
    else if(strcmp(s, "0222") == 0)
    return front_left;
    else if(strcmp(s, "0223") == 0)
    return front_left;
    else if(strcmp(s, "0224") == 0)
    return front_left;
    else if(strcmp(s, "0225") == 0)
    return front_left;
    else if(strcmp(s, "0226") == 0)
    return left;
    else if(strcmp(s, "0227") == 0)
    return left;
    else if(strcmp(s, "0228") == 0)
    return left;
    else
        return front;
}

