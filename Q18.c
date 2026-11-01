#include <stdio.h>
#include <stdlib.h>

// Function to reverse the sub-segment in-place
void reverseSubSegment(int* arr, int start, int end) {
    // Continue swapping until the two pointers meet in the middle
    while (start < end) {
        // Swap the elements at the start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move the pointers inward
        start++;
        end--;
    }
}

int main() {
    int n, start, end;

    printf("Enter the size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements separated by space: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // --- NEW: Clear the input buffer of any leftover characters or newlines ---
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Discarding characters
    }

    printf("Enter start index: ");
    scanf("%d", &start);
    
    printf("Enter end index: ");
    scanf("%d", &end);

    if (start < 0 || end >= n || start > end) {
        printf("Invalid indices. Ensure 0 <= start <= end < array length.\n");
        free(arr);
        return 1;
    }

    reverseSubSegment(arr, start, end);

    printf("Modified array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}