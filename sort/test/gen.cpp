#include "testlib.h"
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = 1;
    for (int i = 1; i <= 24; i++) {
        startTest(i);
        n = n * 2;
        printf("%d\n", n);
        for (int j = 0; j < n; j++) {
            printf("%d ", rnd.next(-1000000, 1000000));
        }
        puts("");
    }
    return 0;
}