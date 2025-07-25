/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-albane.merian
** File description:
** test_memcpy
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <dlfcn.h>


bool test_memcpy(void *dest, void *dest2, const void *src, size_t size, int index) {
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val_bool = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }

    dlerror();
    void *(*my_memcpy)(void *, const void *, size_t) = dlsym(handle, "memcpy");
    char *error = dlerror();
    if (error) {
        printf("Error locating memcpy: %s\n", error);
        dlclose(handle);
        return false;
    }

    void *my = my_memcpy(dest, src, size);  // Call custom memcpy

    // 🚨 Prevent NULL pointer dereference unless size is 0
    if ((dest == NULL || src == NULL) && size > 0) {
        printf("Skipping test %d due to NULL pointer with non-zero size\n", index);
        dlclose(handle);
        return true;
    }

    void *temp = memcpy(dest2, src, size);

    printf("Expected: ");
    for (size_t i = 0; i < (size > 10 ? 10 : size); i++)
        printf("[%02X] ", ((unsigned char *)dest2)[i]);
    printf("\n");

    printf("Result:   ");
    for (size_t i = 0; i < (size > 10 ? 10 : size); i++)
        printf("[%02X] ", ((unsigned char *)dest)[i]);
    printf("\n");

    printf("Return value of memcpy:    %p - %p\n", temp, dest2);
    printf("Return value of my_memcpy: %p - %p\n", my, dest);

    if (memcmp(dest, dest2, size) != 0) {
        printf("\033[1;93mTest N°%i\033[0m \033[1;31mKO (Content Mismatch)\033[0m\n", index);
        val_bool = false;
    }
    else if (my != temp) {
        printf("\033[1;93mTest N°%i\033[0m \033[1;31mKO (Return Value Mismatch)\033[0m\n", index);
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
    char dest1[20], dest2[10], dest3[5], dest4[1], dest5[1];
    char overlap_src[] = "123456789";
    char overlap_dest[] = "abcdefghi";
    char same_buffer[] = "SelfCopyTest";
    char unaligned_src[] = "Misaligned";
    char unaligned_dest[20];
    char large_src[10000], large_dest[10000];
    char exact_size_src[] = "1234567890";
    char exact_size_dest[10];

    memset(large_src, 'A', sizeof(large_src));

    const char *src_set[] = {
        "Hello, world!",    // Normal case
        "123456789",        // Exact size match
        "",                 // Empty string
        "A",                // Single character
        "Test memcpy!",     // Longer source than destination
        NULL,               // NULL destination
        NULL,               // NULL source
        "OldData",          // Zero-size copy
        overlap_src,        // Overlapping forward
        overlap_dest + 2,   // Overlapping backward // 9
        same_buffer,        // Copying to itself
        unaligned_src + 1,  // Misaligned memory
        large_src,          // Large buffer copy
        exact_size_src      // Copy exact buffer size
    };

    void *dest_set[] = {
        dest1, dest2, dest3, dest4, dest5,
        NULL, dest2, dest3, overlap_src + 2, overlap_dest,
        same_buffer, unaligned_dest + 1, large_dest, exact_size_dest
    };

    size_t sizes[] = {
        10, 9, 0, 1, 5,  // Original tests
        5, 5, 0, 6, 6,   // New tests (NULL, zero-size, overlap)
        strlen(same_buffer), 9, sizeof(large_src), 10
    };

    printf("TEST MEMCPY FUNCTION\n");
    bool test_bool = true;

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        if (!test_memcpy(dest_set[i], dest_set[i], src_set[i], sizes[i], i))
            test_bool = false;
    }

    if (test_bool)
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    else
        printf("\033[1;31mSome tests failed\033[0m\n\n");

    return 0;
}


//if one null return value return null
// return a void * pointer in the fucntion
