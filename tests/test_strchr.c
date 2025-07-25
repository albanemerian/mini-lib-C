/*
** EPITECH PROJECT, 2025
** Asembly
** File description:
** test_strchr
*/
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

static bool test_strchr(const char *string, const char c, int index)
{
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }
    dlerror();
    char *(*my_strchr)(const char *, int) = dlsym(handle, "strchr");
    char *error = dlerror();
    if (error) {
        printf("Error locating strchr: %s\n", error);
        return false;
    }
    char *result_my_strchr = my_strchr(string, c);
    char *result_strchr = strchr(string, c);

    if (result_my_strchr == NULL && result_strchr == NULL) {
        printf("\033[1;32mOK\033[0m %s\n", result_my_strchr);
        val = true;
    } else if (result_my_strchr == NULL || result_strchr == NULL || strcmp(result_my_strchr, result_strchr) != 0) {
        printf("\033[1;93mTest N°%i\033[0m %s vs %s \033[1;31mKO\033[0m\n", index,result_my_strchr, result_strchr);
        val = false;
    } else {
        printf("\033[1;93mTest N°%i\033[0m %s \033[1;32mOK\033[0m\n", index, result_my_strchr);
        val = true;
    }
    dlclose(handle);
    return val;
}


int main()
{
    const char *test[10] = {
        "Hello, world!","Hello, world how are you!","", "aaaa","ag","kdkd","1234567890","special@characters!","Find me at the end!","Look for z" };

    const char val_char[10] = {'w','o', '\0', 'a','g','x','5', '@', '!', 'z'};
    bool val = false;
    bool test_bool = true;

    printf("TEST STRCHR FUNCTION\n");

    for (int i = 0; i < 10; i++) {
        val = test_strchr(test[i], val_char[i], i);
        if (val == false)
            test_bool = false;
    }
    if (test_bool == true)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");

    return 0;
}
