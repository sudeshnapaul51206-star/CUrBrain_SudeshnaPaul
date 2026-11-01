#include <stdio.h>
#include <stdlib.h>

// Prime number for hash table size to minimize collisions
#define TABLE_SIZE 10007 

// Node structure for separate chaining in the hash map
typedef struct Node {
    int id;
    int frequency;
    struct Node* next;
} Node;

// Hash function
unsigned int hash(int id) {
    return (unsigned int)id % TABLE_SIZE;
}

// Function to find the most popular item in O(N) time
int mostPopularItem(int* sales, int n) {
    if (n == 0) return -1; // Safeguard

    Node* hashTable[TABLE_SIZE] = {NULL};
    
    int maxFreq = 0;
    int bestId = sales[0];

    for (int i = 0; i < n; i++) {
        int currentId = sales[i];
        unsigned int h = hash(currentId);

        Node* curr = hashTable[h];
        int found = 0;
        
        while (curr != NULL) {
            if (curr->id == currentId) {
                curr->frequency++;
                found = 1;

                if (curr->frequency > maxFreq) {
                    maxFreq = curr->frequency;
                    bestId = currentId;
                } else if (curr->frequency == maxFreq && currentId < bestId) {
                    bestId = currentId;
                }
                break;
            }
            curr = curr->next;
        }

        if (!found) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->id = currentId;
            newNode->frequency = 1;
            newNode->next = hashTable[h];
            hashTable[h] = newNode;

            if (1 > maxFreq) {
                maxFreq = 1;
                bestId = currentId;
            } else if (1 == maxFreq && currentId < bestId) {
                bestId = currentId;
            }
        }
    }

    // Free the hash table nodes
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    return bestId;
}

int main() {
    int n;
    
    // 1. Prompt user for the size of the array
    printf("Enter the number of sales records: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. The array must contain at least one element.\n");
        return 1; 
    }

    // 2. Dynamically allocate memory for the sales array based on user input
    int* sales = (int*)malloc(n * sizeof(int));
    if (sales == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 3. Prompt user for the actual array elements
    printf("Enter %d product IDs separated by space: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }

    // 4. Calculate and print the result
    int result = mostPopularItem(sales, n);
    printf("Expected Output: %d\n", result);

    // 5. Free the dynamically allocated array to prevent memory leaks
    free(sales);

    return 0;
}