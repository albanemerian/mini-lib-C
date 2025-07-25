/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-albane.merian
** File description:
** test_strstr
*/

#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdbool.h>

bool test_strstr(const char *strr1, const char *str2, int index)
{
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }
    dlerror();
    char *(*my_strstr)(const char *, const char *) = dlsym(handle, "strstr");
    char *error = dlerror();
    if (error) {
        printf("Error locating strstr: %s\n", error);
        return false;
    }
    char *res2 = strstr(strr1, str2);
    char *res = my_strstr(strr1, str2);
    if (res != res2) {
        if (res == NULL || res2 == NULL)
            printf("\033[1;93mTest N°%i\033[0m \033[1;31mKO\033[0m",index);
        else
            printf("\033[1;93mTest N°%i\033[0m my %s vs %s \033[1;31mKO\033[0m\n", index,res, res2);
        val = false;
    } else {
        printf("\033[1;93mTest N°%i\033[0m %s vs %s \033[1;32mOK\033[0m\n", index,res, res2);
        val = true;
    }
    dlclose(handle);
    return val;
}
int main() {
    const char *haystack[22] = {
        "Hello, world!", "Hello, world!", "abcdef", "abcdef", "repeat repeat",
        "findme", "just a test", "", "", "abcdef", "abcdef", "short",
        "",              // 1. NULL haystack
        "test",            // 2. Normal string
        "hello",           // 3. Simple case
        "",                // 4. Empty string
        "abc",             // 5. Shorter than needle
        "\xFF\xFF\xFF\xFF", // 6. Non-printable characters
        "A",               // 7. Single character (non-null terminated risk)
        "aaaaa",           // 8. Repeating pattern
        "ababab",          // 9. Overlapping pattern
        "1234567890"    // 10. Standard numeric
    };

    const char *needle[22] = {
        "world", "Hello", "cde", "xyz", "repeat",
        "findme", "test", "anything", "", "", "abcdef", "too long",
        "test",            // 1. Normal string
        "",              // 2. NULL needle
        "",                // 3. Empty needle (should return haystack)
        "test",            // 4. Longer than empty haystack
        "abcdef",          // 5. Longer than haystack
        "\xFF\xFF",        // 6. Non-printable characters
        "A",               // 7. Single character match
        "aaa",             // 8. Substring within repeating pattern
        "bababa",          // 9. Partial pattern
        "\x00"          // 10. Null terminator as a needle
    };
    bool val = false;
    bool test_bool = true;
    printf("TEST STRSTR FUNCTION\n");

    for (int i = 0; i < 22; i++) {
        val = test_strstr(haystack[i], needle[i], i);
        if (val == false)
            test_bool = false;
    }
    if (test_bool == true)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");

    return 0;
}
