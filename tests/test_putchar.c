/*
** EPITECH PROJECT, 2025
** Asembly
** File description:
** main
*/

// #include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

bool test_putchar(const char string)
{
    void *handle = dlopen("./libasmo.so", RTLD_NOW);
    bool val = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }
    dlerror();
    int (*my_putchar)(const char) = dlsym(handle, "putchar");

    char *error = dlerror();
    if (error) {
        printf("Error locating strlen: %s\n", error);
        return false;
    }
    int my_putchar_result = my_putchar(string);
    my_putchar(' ');
    int putchar_result = putchar(string);
    my_putchar(' ');

    if (my_putchar_result != putchar_result) {
        printf("\033[1;31m KO %i vs %i \033[0m %c\n", my_putchar_result, putchar_result, string);
        val = false;
    } else {
        printf("\033[1;32m OK \033[0m %c\n", string);
        val = true;
    }
    dlclose(handle);
    return val;
}


int main()
{
    const char test[6] = {'a', 'b', 'c', 'd', 'e', '\n'};
    printf("TEST PUTCHAR FUNCTION\n");
    bool val = false;
    bool test_bool = true;

    for (int i = 0; i < 6; i++) {
        val = test_putchar(test[i]);
        if (val == false)
            test_bool = false;
    }
    if (test_bool == true)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");
    return 0;
}


// int main()
// {
//     char a = 'a';

//     putchar(a);
//     putchar('\n');
//     return 0;
// }
