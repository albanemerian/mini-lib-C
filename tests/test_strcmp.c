/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-albane.merian
** File description:
** test_strcmp
*/

#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

bool test_strcmp(const char *strr1, const char *str2, int index)
{
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }
    dlerror();
    int (*my_strcmp)(const char *, const char *) = dlsym(handle, "strcmp");
    char *error = dlerror();
    if (error) {
        printf("Error locating strcmp: %s\n", error);
        return false;
    }
    int res = my_strcmp(strr1, str2);
    int res2 = strcmp(strr1, str2);
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
    const char *str1[12] = {"Hello, world!", "Hello, world how are you!", "", "aaaaaaaa", "ag", "kdkd", "apple", "banana", "hello!", "", "hello", "Doof"};
    const char *str2[12] = {"Hello, world!", "Hello, world ho are you!", "", "aaaa", "agq", "kdkd", "banana", "apple", "hello" , "hello", "", "doof"};
    printf("TEST STRCMP FUNCTION\n");
    bool val = false;
    bool test_bool = true;

    for (int i = 0; i < 12; i++) {
        val = test_strcmp(str1[i], str2[i], i);
        if (val == false)
            test_bool = false;
    }
    if (test_bool == true)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");
    return 0;
}
