/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-albane.merian
** File description:
** test_strcasecmp
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <dlfcn.h>

bool test_strcasecmp(const char *str1, const char *str2, int index)
{
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }
    dlerror();
    int (*my_strcasecmp)(const char *, const char *) = dlsym(handle, "strcasecmp");
    char *error = dlerror();
    if (error) {
        printf("Error locating strcasecmp: %s\n", error);
        return false;
    }
    int res = my_strcasecmp(str1, str2);
    int res2 = strcasecmp(str1, str2);
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

int main() {
    const char *test1[14] = {"Hello", "HELLO", "CaseInsensitive", "MixedCase", "TeSt", "example", "UPPER", "lower", "123abc", "", "", "empty", "same", "different"};
    const char *test2[14] = {"hello", "hello", "caseinsensitive", "MIXEDcase", "test", "EXAMPLE", "upper", "LOWER", "123ABC", "", "non-empty", "", "SAME", "different"};
    bool val = false;
    bool test_bool = true;

    printf("TEST STRCASECMP FUNCTION\n");
    for (int i = 0; i < 14; i++) {
        val = test_strcasecmp(test1[i], test2[i], i);
        if (val == false)
            test_bool = false;
    }
    if (test_bool == true)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");

    return 0;
}
