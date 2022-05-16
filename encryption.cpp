#include "encryption.h"

string cyphering(string msg){
    char cha;
    for(int i = 0; i < msg.size(); ++i) {
        cha = msg[i];
        cha = cha + 1;
        msg[i] = cha;
    }
    return msg;
}
