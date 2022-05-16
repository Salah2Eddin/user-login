//
// Created by Salah on 16/05/2022.
//
#include<iostream>
#include<string>

using namespace std;

string cyphering(string mesg){
    char cha;
    for(int i = 0; i < mesg.size(); ++i) {
        cha = mesg[i];
        //encrypt characters
        cha = cha + 1;
        mesg[i] = cha;
    }
    return mesg;
}
