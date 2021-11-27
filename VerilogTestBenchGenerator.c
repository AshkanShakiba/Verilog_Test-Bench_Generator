#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int i, j, bit, count;
    printf("Signals count: ");
    scanf("%d", &count);
    char signals[count][32];
    for (i = 0; i < count; i++) {
        printf("Signal #%d name: ", i + 1);
        scanf("%s", signals[i]);
    }
    char test_bench[4096], signal_test[64];
    strcpy(test_bench, "initial begin\n");
    for (i = 0; i < pow(2, count); i++) {
        strcat(test_bench, "  ");
        for (j = 0; j < count; j++) {
            bit = (i / (int) pow(2, count - j - 1)) % 2;
            sprintf(signal_test, "%s = 1'b%d;", signals[j], bit);
            strcat(test_bench, signal_test);
        }
        strcat(test_bench, "\n#100;\n");
    }
    strcat(test_bench, "end\n");
    printf("-------------\n");
    printf("%s", test_bench);
    return 0;
}
// Verilog Test Bench Generator
