#include "strkitten.h"
char strkitten(char* strone, char* strtwo) {
    int last_sigh = 0;
    for (int i = 0; i < 300; i++) {
        if (strone[i] == '\0') {
            last_sigh = i;
            break;
        }
    }
    for (int i = last_sigh; i < 600; i++) {
        strone[i] = strtwo[i - last_sigh];
    }
    return *strone;
}