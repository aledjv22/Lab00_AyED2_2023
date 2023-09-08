#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

// Prints an array
static void print_array(int arr[], unsigned int length) {
    printf("Your array is: [");
    for (unsigned int i = 0; i < length; ++i) {
        printf("%d", arr[i]);
        if (i < length - 1) printf(", ");
    }
    printf("]\n");
}

// Reads items into an array
static void items_in_array(int arr[], unsigned int length) {
    printf("Enter %u items.\n", length);
    for (unsigned int i = 0; i < length; ++i) {
        printf("Item %u: ", i);
        scanf("%d", &arr[i]);
    }
    print_array(arr, length);
}

// Checks if a value is in an array and if it is the upper or lower bound
static struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = false;
    res.is_lowerbound = false;
    res.exists = false;

    for (unsigned int i = 0; i < length; ++i){
        if (arr[i] == value) {
            res.exists = true;
            res.where = i;
        }else if (arr[i] <= value) res.is_upperbound = true;
        else if (arr[i] >= value) res.is_lowerbound = true;
    }
    
    printf("\n");

    return res;
}

int main(void) {
    int value;
    unsigned int ARRAY_SIZE;
    printf("Enter array size: ");
    scanf("%u", &ARRAY_SIZE);

    int a[ARRAY_SIZE];

    items_in_array(a, ARRAY_SIZE);

    printf("Enter value to check: ");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // Print results
    if (result.exists && result.is_lowerbound)
        printf("Value %d is in array and is the minimum. It is in position %d.\n", value, result.where);
    else if (result.exists && result.is_upperbound)
        printf("Value %d is in array and is the maximum. It is in position %d.\n", value, result.where);
    else if (result.is_lowerbound)
        printf("Value %d is not in array. It is lower bound.\n", value);
    else if (result.is_upperbound)
        printf("Value %d is not in array. It is upper bound.\n",value);
    else printf("Value %d is not in array. It is not upper or lower bound.\n",value);

    return EXIT_SUCCESS;
}

