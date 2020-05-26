//
//  main.c
//  CLearn
//
//  Created by zhangalan on 2020/2/24.
//  Copyright © 2020 zhangalan. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define STLEN 10

char *s_gets(char * st, int n){
    char * ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        }else{
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}

#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)

int main(int argc, const char * argv[]) {
    // insert code here...
    double X = 48;
    double y;
    y = sqrt(X);
    PR(1, "x = %g\n", X);
    PR(2, "x = %.2f, y = %.2f\n", X, y);
    return 0;
}
