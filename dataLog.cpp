//
//  dataLog.cpp
//  RPi
//
//  Created by ed on 12/12/2012.
//  Copyright (c) 2012 ed. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"
#include "atod.h"
#include "GPIO/wiringPi.h"
#include <fstream>
#include <vector>
#include <unistd.h>
using namespace std;
int main(int argc, const char * argv[])
{
    cout << "Data Logging for temperature sensor values\n";
    
    if (wiringPiSetup () == -1){
        cout << "couldn't setup GPIO";
        exit (1) ;
    }
    
    //the info for this equasion is taken from pages 3 and 8 on the data sheet
    //degrees C=(voltage-0.5)*100
    
    string filename="output.txt";
    
    //setup chip
    atod sensor(14,10,13,12); //clock,shutdown,dout,din
    
    time_t start_time;
    start_time=time(NULL);
    
    int run_time;
    cout << "In minutes how long would you like to run the program for? :";
    cin >> run_time;
    
    time_t end_time;
    end_time=start_time+(run_time*60);
    
    //runs for a set number of hours and minutes
    //bool run=true;
    for(int i=0;i<run_time;i++){
        time_t curr;
        curr=time(NULL);
        int temp=floor((sensor.voltage(1000)-0.5)*100);
        fstream file;
        file.open(filename.c_str(), fstream::in | fstream::out | fstream::app); //input and output streams, appending
        string new_line;
        file<<curr<<","<<temp<<"\n";
        file.close();
        sleep(59);
    }
    cout << "\n";
    cout << "expected to end at: " << end_time << " ; Ended at: "<<time(NULL);
} 