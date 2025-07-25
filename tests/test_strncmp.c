/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-albane.merian
** File description:
** test_strncmp
*/


#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

bool test_strncmp(const char *strr1, const char *str2, int i, int index)
{
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }
    dlerror();
    int (*my_strncmp)(const char *, const char *, int ) = dlsym(handle, "strncmp");
    char *error = dlerror();
    if (error) {
        printf("Error locating strcmp: %s\n", error);
        return false;
    }
    int res = my_strncmp(strr1, str2, i);
    int res2 = strncmp(strr1, str2, i);
    if (res != res2) {
        printf("\033[1;93mTest N°%i\033[0m %i vs %i \033[1;31mKO\033[0m\n", index, res, res2);
        val = false;
    } else {
        printf("\033[1;93mTest N°%i\033[0m %i - %i \033[1;32mOK\033[0m\n", index, res, res2);
        val = true;
    }
    dlclose(handle);
    return val;
}

int main()
{
    const char *test1[14] = {"Hello", "Hello", "abcd", "abcd", "test", "test", "example", "example", "different", "same", "", "", "empty", ""};
    const char *test2[14] = {"Hello", "Hello, world!", "abcd", "abce", "test", "tes", "example", "examp", "different", "same", "", "non-empty", "", "empty"};
    size_t n[14] = {5, 10, 4, 4, 4, 3, 7, 6, 9, 4, 0, 5, 5, 5};

    bool val = false;
    bool test_bool = true;

    printf("TEST STRNCMP FUNCTION\n");
    for (int i = 0; i < 14; i++) {
        val = test_strncmp(test1[i], test2[i], n[i], i);
        if (val == false)
            test_bool = false;
    }
    if (test_bool == true)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");

    return 0;
}
