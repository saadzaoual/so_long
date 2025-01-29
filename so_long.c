#include "so_long.h"
#include <stdio.h>

int main() {
    // Test printf functionality
    printf("Hello, so_long!\n");

    // Test a function from libft, for example ft_strlen
    const char *test_str = "Testing libft!";
    size_t length = ft_strlen(test_str);
    
    printf("Length of '%s' is: %zu\n", test_str, length);

    return 0;
}
