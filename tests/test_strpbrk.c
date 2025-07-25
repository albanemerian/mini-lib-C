/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-albane.merian
** File description:
** test_strpbrk
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <dlfcn.h>

static bool test_strpbrk(const char *string, const char *accept, int index)
{
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }
    dlerror();
    char *(*my_strpbrk)(const char *, const char *) = dlsym(handle, "strpbrk");
    char *error = dlerror();
    if (error) {
        printf("Error locating strpbrk: %s\n", error);
        dlclose(handle);
        return false;
    }

    char *result_my_strpbrk = my_strpbrk(string, accept);
    char *result_strpbrk = strpbrk(string, accept);

    if (result_my_strpbrk == NULL && result_strpbrk == NULL) {
        printf("\033[1;32mOK\033[0m NULL\n");
        val = true;
    } else if (result_my_strpbrk == NULL || result_strpbrk == NULL || strcmp(result_my_strpbrk, result_strpbrk) != 0) {
        printf("\033[1;93mTest N°%i\033[0m %s vs %s \033[1;31mKO\033[0m\n", index, result_my_strpbrk, result_strpbrk);
        val = false;
    } else {
        printf("\033[1;93mTest N°%i\033[0m %s \033[1;32mOK\033[0m\n", index, result_my_strpbrk);
        val = true;
    }

    dlclose(handle);
    return val;
}

int main()
{
    const char *test_strings[] = {
        "Hello, world!",          // Match in middle
        "Hello, world how are you!", // Multiple matches
        "",                      // Empty string (should return NULL)
        "aaaa",                  // All same character, match
        "ag",                    // One match at the beginning
        "kdkd",                  // No match
        "1234567890",            // Match in middle
        "special@characters!",   // Match at the beginning
        "Find me at the end!",   // Match at the end
        "Look for z",            // No match
        "Testing multiple letters", // Multiple match positions
        "Case Sensitivity Test"  // Case-sensitive match
    };

    const char *accept_sets[] = {
        "aeiou",  // Match 'o'
        "how",    // Match 'h'
        "abc",    // Empty input, should return NULL
        "a",      // First character matches
        "g",      // 'g' matches
        "xyz",    // No match, should return NULL
        "567",    // Matches '5'
        "@#",     // Matches '@'
        "!",      // Matches '!'
        "xyz",    // No match, should return NULL
        "lm",     // Matches 'l'
        "T"       // Matches 'T' (case-sensitive)
    };

    bool test_bool = true;

    printf("TEST STRPBRK FUNCTION\n");

    for (int i = 0; i < 12; i++) {
        if (!test_strpbrk(test_strings[i], accept_sets[i], i)) {
            test_bool = false;
        }
    }

    if (test_bool)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");

    return 0;
}
