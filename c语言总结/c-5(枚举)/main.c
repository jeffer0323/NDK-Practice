/**
 * 枚举类型
 */

#include <stdio.h>

enum color{
    RED = 2,  // 定义为2时，后续的枚举类型+1，即GREEN= 3 ， BLUE = 4； 如果不设置RED默认为0。GREEN和BLUE则分别为1 ， 2
    GREEN,   // GREEN = 3；
    BLUE    // RED = 4；
};

int main() {
    enum color d = BLUE;
    printf("color is %d\n" , d);

    int colorRed = 2;
    enum color red;
    red = (enum color)colorRed;
    printf("color is %d\n" , red);

    return 0;
}
