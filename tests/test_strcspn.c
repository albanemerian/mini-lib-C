/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-albane.merian
** File description:
** test_strcspn
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <dlfcn.h>

bool test_strcspn(const char *str, const char *reject, int index)
{
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val_bool = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }

    dlerror();
    size_t (*my_strcspn)(const char *, const char *) = dlsym(handle, "strcspn");
    char *error = dlerror();
    if (error) {
        printf("Error locating strcspn: %s\n", error);
        dlclose(handle);
        return false;
    }

    size_t expected = strcspn(str, reject);
    size_t result = my_strcspn(str, reject);

    printf("Input: \"%s\" | Reject: \"%s\"\n", str, reject);
    printf("Expected: %zu | Result: %zu\n", expected, result);

    if (expected != result) {
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
    const char *test_strings[] = {"Hello, world!", "abcdefg", "", "123456", "special!@#", "lasttest", "overlap test", "zzzzzzzz", "hello"};
    const char *reject_sets[] = {"aeiou", "xyz", "abc", "6789", "!@#", "t", "test", "z", ""};
    size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    printf("TEST STRCSPN FUNCTION\n");
    bool test_bool = true;

    for (size_t i = 0; i < num_tests; i++) {
        if (!test_strcspn(test_strings[i], reject_sets[i] ,i)) {
            test_bool = false;
        }
    }

    if (test_bool)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");

    return 0;
}
