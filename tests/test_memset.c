/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-albane.merian
** File description:
** test_memset
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dlfcn.h>

bool test_memset(char *buffer, int val, size_t size, int index) {
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val_bool = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }
    dlerror();
    void *(*my_memset)(void *, int, size_t) = dlsym(handle, "memset");
    char *error = dlerror();
    if (error) {
        printf("Error locating memset: %s\n", error);
        dlclose(handle);
        return false;
    }

    char expected[size];  // Buffer for standard memset
    memset(expected, val, size);  // Fill with standard memset

    my_memset(buffer, val, size);  // Fill with custom memset

    printf("Expected: ");
    for (size_t i = 0; i < size; i++)
        printf("%02X ", (unsigned char)expected[i]);
    printf("\n");

    printf("Result:   ");
    for (size_t i = 0; i < size; i++)
        printf("%02X ", (unsigned char)buffer[i]);
    printf("\n");

    if (memcmp(buffer, expected, size) != 0) {
        printf("\033[1;93mTest N°%i\033[0m \033[1;31mKO\033[0m\n", index);
        val_bool = false;
    } else {
        printf("\033[1;93mTest N°%i\033[0m \033[1;32mOK\033[0m\n", index);
        val_bool = true;
    }

    dlclose(handle);
    return val_bool;
}

int main()
{
    char buffer1[20], buffer2[10], buffer3[5], buffer4[1], buffer5[1];
    char buffer6[10], buffer7[10], buffer8[10], buffer9[10], buffer10[10]; // Additional buffers

    // Test values and sizes
    int val_set[10] = {'A', 0, 255, 'Z', 'X', 'B', 'C', 0x1F, 0x2A, 0xFF};
    size_t sizes[10] = {sizeof(buffer1), sizeof(buffer2), sizeof(buffer3), sizeof(buffer4), sizeof(buffer5),
                        sizeof(buffer6), sizeof(buffer7), sizeof(buffer8), sizeof(buffer9), sizeof(buffer10)};

    printf("TEST MEMSET FUNCTION\n");
    bool val = false;
    bool test_bool = true;

    // First 5 tests
    for (int i = 0; i < 5; i++) {
        memset(buffer1, 0, sizeof(buffer1)); // Clear buffer before test
        val = test_memset(buffer1, val_set[i], sizes[i], i);
        if (val == false)
            test_bool = false;
    }

    // Additional tests
    for (int i = 5; i < 10; i++) {
        memset(buffer6, 0, sizeof(buffer6)); // Clear buffer before each additional test
        val = test_memset(buffer6, val_set[i], sizes[i], i);
        if (val == false)
            test_bool = false;
    }

    if (test_bool)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");

    return 0;
}
