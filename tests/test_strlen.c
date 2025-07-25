/*
** EPITECH PROJECT, 2025
** Asembly
** File description:
** test_strlen
*/

#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>


bool test_strlen(const char *string, int index)
{
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }
    dlerror();
    size_t (*my_strlen)(const char *) = dlsym(handle, "strlen");
    char *error = dlerror();
    if (error) {
        printf("Error locating strlen: %s\n", error);
        return false;
    }
    if (my_strlen(string) != strlen(string)) {
        printf("\033[1;93mTest N°%i\033[0m \033[1;31mKO\033[0m %s\n",index, string);
        val = false;
    } else {
        printf("\033[1;93mTest N°%i\033[0m \033[1;32mOK\033[0m %s\n",index, string);
        val = true;
    }
    dlclose(handle);
    return val;
}

int main()
{
    const char *test[12] = {"Hello, world!", "Hello, world how are you!", "", "aaaa", "ag", "kdkd", "1234567890", "spaces and tabs   ", "special@characters!", "longer string with multiple words", "single character", "   "};

    printf("TEST STRLEN FUNCTION\n");
    bool val = false;
    bool test_bool = true;

    for (int i = 0; i < 12; i++) {
        val = test_strlen(test[i], i);
        if (val == false)
            test_bool = false;
    }
    if (test_bool == true)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");
    return 0;
}
