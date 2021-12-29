#include <cstdio>
using namespace std;

int main() {
    int n, x, a=0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        a ^= x;
    }
    printf("%d\n", a);
}