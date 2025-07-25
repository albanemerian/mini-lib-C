/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-albane.merian
** File description:
** test_memmove
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dlfcn.h>

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <stdlib.h>

#define BUFFER_SIZE 32  // Define a reasonable buffer size

// Function to test memmove with overlapping memory
bool test_overlap(const char *test_name, size_t offset, size_t size) {
    // Allocate memory for test
    char buffer1[BUFFER_SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char buffer2[BUFFER_SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Overlapping regions
    char *src1 = buffer1 + offset;
    char *dest1 = buffer1;

    char *src2 = buffer2 + offset;
    char *dest2 = buffer2;

    // Load shared library containing memmove
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }

    // Get pointer to your memmove function
    void *(*asm_memmove)(void *, const void *, size_t) = dlsym(handle, "memmove");
    if (!asm_memmove) {
        printf("Error locating memmove: %s\n", dlerror());
        dlclose(handle);
        return false;
    }

    // Perform memmove operations
    asm_memmove(dest1, src1, size);
    memmove(dest2, src2, size);  // Standard memmove for reference

    // Compare results
    bool passed = (memcmp(buffer1, buffer2, BUFFER_SIZE) == 0);

    // Print results
    printf("\nTest: %s\n", test_name);
    printf("Before: %s\n", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    printf("Expected: %s\n", buffer2);
    printf("Got:      %s\n", buffer1);
    printf("%s\n", passed ? "\033[1;32mPASS\033[0m" : "\033[1;31mFAIL\033[0m");

    dlclose(handle);
    return passed;
}

int temp() {
    printf("\nTESTING ASM MEMMOVE WITH OVERLAPPING MEMORY\n");

    bool all_pass = true;

    // Forward overlap tests (destination starts before source)
    all_pass &= test_overlap("Forward overlap: offset 2, size 10", 2, 10);
    all_pass &= test_overlap("Forward overlap: offset 5, size 15", 5, 15);

    // Backward overlap tests (destination starts inside source)
    all_pass &= test_overlap("Backward overlap: offset 1, size 5", 1, 5);
    all_pass &= test_overlap("Backward overlap: offset 10, size 10", 10, 10);
    all_pass &= test_overlap("Backward overlap: offset 20, size 5", 20, 5);

    // Edge case: Full buffer copy
    all_pass &= test_overlap("Full buffer overlap", 0, BUFFER_SIZE - 1);

    if (all_pass) {
        printf("\n\033[1;32mAll tests passed successfully!\033[0m\n");
    } else {
        printf("\n\033[1;31mSome tests failed.\033[0m\n");
    }

    return 0;
}

bool test_memmove(void *dest, void *dest2, const void *src, size_t size, int index) {
    void *handle = dlopen("./libasm.so", RTLD_NOW);
    bool val_bool = false;

    if (!handle) {
        printf("Failed to load libasm.so: %s\n", dlerror());
        return false;
    }

    dlerror();
    void *(*my_memmove)(void *, const void *, size_t) = dlsym(handle, "memmove");
    char *error = dlerror();
    if (error) {
        printf("Error locating memmove: %s\n", error);
        dlclose(handle);
        return false;
    }

    // Prevent NULL pointer dereference unless size is 0
    void *my = my_memmove(dest, src, size);
    if ((dest == NULL || src == NULL) && size > 0) {
        printf("Skipping test %d due to NULL pointer with non-zero size\n", index);
        dlclose(handle);
        return true;
    }

    //char expected[size];  // Expected result array
    memset(dest2, 0, size); // Initialize expected memory
    void *temp = memmove(dest2, src, size); // Fill with standard memmove

    printf("Expected: ");
    for (size_t i = 0; i < 10; i++) {
        printf("%02X ", ((unsigned char *)dest2)[i]);
    }
    printf("\n");

    printf("Result:   ");
    for (size_t i = 0; i < 10; i++) {
        printf("%02X ", ((unsigned char *)dest)[i]);
    }
    printf("\n");

    // Compare results
    printf("Expected: %p\n", temp);
    printf("Got %p\n", my);
    if (memcmp(dest, dest2, size) != 0 || my != temp) {
        printf("\033[1;93mTest N°%i\033[0m \033[1;31mKO\033[0m\n", index);
        val_bool = false;
    } else {
        printf("\033[1;93mTest N°%i\033[0m \033[1;32mOK\033[0m\n", index);
        val_bool = true;
    }

    dlclose(handle);
    return val_bool;
}

int main() {
    char dest1[20], dest2[10], dest3[5], dest4[1], dest5[1];
    char overlap_src[] = "123456789";  // Overlapping case
    char overlap_dest[] = "abcdefghi"; // Overlapping case
    char same_buffer[] = "SelfCopyTest"; // Same buffer move
    char unaligned_src[] = "Misaligned"; // Misaligned access test
    char unaligned_dest[20];
    char large_src[10000], large_dest[10000]; // Large memory block
    char exact_size_src[] = "1234567890";
    char exact_size_dest[10];

    memset(large_src, 'A', sizeof(large_src));

    // New overlapping cases
    char overlap_forward[] = "OverlappingTest";
    char overlap_backward[] = "OverlappingTest";
    char overlap_entire_buffer[50];
    char overlap_large[10000];

    // Initialize large overlap test
    memset(overlap_entire_buffer, 'X', sizeof(overlap_entire_buffer));
    memset(overlap_large, 'Y', sizeof(overlap_large));

    const char *src_set[] = {
        "Hello, World!",
        "123456789",
        "",
        "A",
        "Test memmove!",
        NULL,
        NULL,
        "OldData",
        overlap_src + 2,
        overlap_dest,
        same_buffer,
        unaligned_src + 1,
        large_src,
        exact_size_src,

        // New Overlap Tests
        overlap_forward + 5, // Forward overlapping
        overlap_backward,    // Backward overlapping
        overlap_entire_buffer + 10,  // Copying within the same buffer
        overlap_large + 5000 // Large memory shift
    };

    void *dest_set[] = {
        dest1, dest2, dest3, dest4, dest5,
        NULL, dest2, dest3, overlap_src, overlap_dest + 2,
        same_buffer, unaligned_dest + 1, large_dest, exact_size_dest,

        // New Overlap Tests
        overlap_forward,   // Forward overlapping destination
        overlap_backward + 5,  // Backward overlapping destination
        overlap_entire_buffer, // Same buffer move
        overlap_large      // Large overlapping case
    };

    size_t sizes[] = {
        13, 9, 0, 1, 14,
        5, 5, 0, 6, 6,
        strlen(same_buffer), 9, sizeof(large_src), 10,

        // New Overlap Test Sizes
        8, 8, 30, 4000
    };

    printf("TEST MEMMOVE FUNCTION\n");
    bool test_bool = true;

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        if (!test_memmove(dest_set[i], dest_set[i], src_set[i], sizes[i], i)) {
            test_bool = false;
        }
    }

    if (test_bool) {
        printf("\033[1;32mAll tests passed\033[0m\n\n");
    } else {
        printf("\033[1;31mSome tests failed\033[0m\n\n");
    }
    temp();
    return 0;
}

// int main() {
//     char dest1[20], dest2[10], dest3[5], dest4[1], dest5[1];
//     char overlap_src[] = "123456789";
//     char overlap_dest[] = "abcdefghi";
//     char same_buffer[] = "SelfCopyTest";
//     char unaligned_src[] = "Misaligned";
//     char unaligned_dest[20];
//     char large_src[10000], large_dest[10000];
//     char exact_size_src[] = "1234567890";
//     char exact_size_dest[10];

//     memset(large_src, 'A', sizeof(large_src));

//     const char *src_set[] = {
//         "Hello, World!",    // Normal case
//         "123456789",        // Exact size match
//         "",                 // Empty string
//         "A",                // Single character
//         "Test memmove!",    // Longer source than destination
//         NULL,               // NULL destination
//         NULL,               // NULL source
//         "OldData",          // Zero-size copy
//         overlap_src,        // Overlapping forward
//         overlap_dest + 2,   // Overlapping backward
//         same_buffer,        // Copying to itself
//         unaligned_src + 1,  // Misaligned memory
//         large_src,          // Large buffer copy
//         exact_size_src      // Copy exact buffer size
//     };

//     void *dest_set[] = {
//         dest1, dest2, dest3, dest4, dest5,
//         NULL, dest2, dest3, overlap_src + 2, overlap_dest,
//         same_buffer, unaligned_dest + 1, large_dest, exact_size_dest
//     };

//     size_t sizes[] = {
//         13, 9, 0, 1, 14, // Original tests
//         5, 5, 0, 6, 6,   // New tests (NULL, zero-size, overlap)
//         strlen(same_buffer), 9, sizeof(large_src), 10
//     };

//     printf("TEST MEMMOVE FUNCTION\n");
//     bool test_bool = true;

//     for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
//         if (!test_memmove(dest_set[i], dest_set[i], src_set[i], sizes[i], i)) {
//             test_bool = false;
//         }
//     }

//     if (test_bool) {
//         printf("\033[1;32mAll tests passed\033[0m\n\n");
//     } else {
//         printf("\033[1;31mSome tests failed\033[0m\n\n");
//     }

//     return 0;
// }

//source et destination ce superspose
// befire et after la source et la destination
