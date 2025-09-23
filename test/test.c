#include <stdio.h>

int run_all_tests(void);

int main() {
    printf("Running tests...\n");
    int result = run_all_tests();
    if (result == 0) {
        printf("All tests passed.\n");
    }
	else {
        printf("Some tests failed.\n");
    }
    return result;
}
