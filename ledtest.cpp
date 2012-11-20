//
//  main.cpp
//  Rpi
//
//  Created by ed on 05/11/2012.
//  Copyright (c) 2012 ed. All rights reserved.
//
//#include "util.h"
//#include "file.h"
//#include "log.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "GPIO/wiringPi.h"
using namespace std;

int main(int argc, const char * argv[])
{
    //testing my RPi GPIO
    cout << "GPIO Test Program.\n";
    
    if (wiringPiSetup () == -1){
        cout << "couldn't setup GPIO";
        exit (1) ;
    }
    pinMode(0,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    for(int i=0;i<10;i++){
        digitalWrite(0,1);
        digitalWrite(2,0);
        delay(100);
        digitalWrite(0,0);
        digitalWrite(2,1);
        delay(100);
        digitalWrite(2,0);
        digitalWrite(3,1);
        delay(100);
    }
    
    digitalWrite(0,0);
    digitalWrite(2,0);
    digitalWrite(3,0);
}
