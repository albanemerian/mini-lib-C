/*
** EPITECH PROJECT, 2025
** Asembly
** File description:
** test_strrchr
*/
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

static bool test_strrchr(const char *string, const char c, int index)
{
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }
    dlerror();
    char *(*my_strrchr)(const char *, int) = dlsym(handle, "strrchr");
    char *error = dlerror();
    if (error) {
        printf("Error locating strchr: %s\n", error);
        return false;
    }
    char *result_my_strrchr = my_strrchr(string, c);
    char *result_strrchr = strrchr(string, c);

    if (result_my_strrchr == NULL && result_strrchr == NULL) {
        printf("\033[1;93mTest N°%i\033[0m %s \033[1;32mOK\033[0m\n", index, result_my_strrchr);
        val = true;
    } else if (result_my_strrchr == NULL || result_strrchr == NULL || strcmp(result_my_strrchr, result_strrchr) != 0) {
        printf("\033[1;93mTest N°%i\033[0m %s \033[1;31mKO\033[0m\n", index, result_my_strrchr);
        val = false;
    } else {
        printf("\033[1;93mTest N°%i\033[0m %s \033[1;32mOK\033[0m\n", index, result_my_strrchr);
        val = true;
    }
    dlclose(handle);
    return val;
}

int main()
{
    const char *test[10] = {"Hello, world!", "Hello, world how are you!", "", "aaaa", "ag", "kdkd", "1234567890", "special@characters!", "Find me at the end!", "Look for z"};
    const char val_char[10] = {'w', 'd', 'a', 'a', 'g', 'k', '0', '@', '!', 'z'};

    bool val = false;
    bool test_bool = true;

    printf("TEST STRRCHR FUNCTION\n");
    for (int i = 0; i < 10; i++) {
        val = test_strrchr(test[i], val_char[i], i);
        if (val == false)
            test_bool = false;
    }
    if (test_bool == true)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");
    return 0;
}
