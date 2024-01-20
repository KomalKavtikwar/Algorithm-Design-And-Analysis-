//Write a program for Huffman Coding using Greedy approach
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARACTERS 100

// Define a structure for a node in the Huffman tree
struct Node {   //Huffman tree, containing character data, frequency, and pointers to left and right child nodes.
    char data;
    int freq;
    struct Node *left, *right;
};

// Define a structure for a min-priority queue
struct MinPriorityQueue {   //Huffman tree, containing character data, frequency, and pointers to left and right child nodes.
    struct Node* array[MAX_CHARACTERS];    //This line declares an array of pointers to structures of type Node
    int size;
};

// Function to create a new node with given data and frequency
struct Node* createNode(char data, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));   // dynamically allocates memory for a new node using the malloc function.
// Set the data and frequency of the new node
    newNode->data = data;
    newNode->freq = freq;
// Set the left and right child pointers to NULL
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new min-priority queue
struct MinPriorityQueue* createQueue() {
    struct MinPriorityQueue* queue = (struct MinPriorityQueue*)malloc(sizeof(struct MinPriorityQueue));
    queue->size = 0;   // it ensures that the size of the queue is properly initialized before any elements are added.
    return queue;
}

// Function to swap two nodes in the queue
void swapNodes(struct Node** a, struct Node** b) {
// Store the value pointed to by 'a' in a temporary variable 'temp'
    struct Node* temp = *a;
// Update the value pointed to by 'a' with the value pointed to by 'b'
    *a = *b;
    *b = temp;
}

// Function to heapify the queue
void minHeapify(struct MinPriorityQueue* queue, int idx) {
   // 'smallest' initially set to the current index
    int smallest = idx;

    // Calculate indices of the left and right children
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    // Check if the left child exists and has a smaller frequency than the current smallest
    if (left < queue->size && queue->array[left]->freq < queue->array[smallest]->freq)
        smallest = left;

    // Check if the right child exists and has a smaller frequency than the current smallest
    if (right < queue->size && queue->array[right]->freq < queue->array[smallest]->freq)
        smallest = right;

    // If the smallest element is not the current element, swap and recursively call minHeapify
    if (smallest != idx) {
        swapNodes(&queue->array[smallest], &queue->array[idx]);
        minHeapify(queue, smallest);
    }
}
// Function to check if the queue has only one node
int isSizeOne(struct MinPriorityQueue* queue) {
    return queue->size == 1;
}

// Function to extract the minimum node from the queue
struct Node* extractMin(struct MinPriorityQueue* queue) {
    // Store the pointer to the minimum node (root) in a temporary variable 'temp'
    struct Node* temp = queue->array[0];

    // Replace the root with the last node in the heap
    queue->array[0] = queue->array[queue->size - 1];

    // Decrease the size of the heap
    --queue->size;

    // Restore the min-heap property by heapifying from the root
    minHeapify(queue, 0);

    // Return the pointer to the minimum node that was extracted
    return temp;
}
// Function to insert a new node into the queue
void insert(struct MinPriorityQueue* queue, struct Node* node) {
    // Increase the size of the min-priority queue
    ++queue->size;

    // Initialize index 'i' to the last position in the heap
    int i = queue->size - 1;

    // Compare the frequency of the new node with its parent's frequency
    while (i && node->freq < queue->array[(i - 1) / 2]->freq) {
        // Move the parent down to make room for the new node
        queue->array[i] = queue->array[(i - 1) / 2];

        // Update the index to the parent's index
        i = (i - 1) / 2;
    }

    // Insert the new node at the correct position in the heap
    queue->array[i] = node;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char data[], int freq[], int n) {
    // Create a min-priority queue
    struct MinPriorityQueue* queue = createQueue();

    // Insert nodes for each character and its frequency into the queue
    for (int i = 0; i < n; ++i) {
        struct Node* node = createNode(data[i], freq[i]);
        insert(queue, node);
    }
    while (!isSizeOne(queue)) {
        // Extract the two nodes with the minimum frequencies
        struct Node* x = extractMin(queue);
        struct Node* y = extractMin(queue);

        // Create a new internal node with '$' as data and the sum of frequencies as frequency
        struct Node* z = createNode('$', x->freq + y->freq);
        z->left = x;
        z->right = y;

        // Insert the new internal node back into the min-priority queue
        insert(queue, z);
    }
    return extractMin(queue);
}

// Function to print the codes for characters in the Huffman tree
void printCodes(struct Node* root, int array[], int top) {
    if (root->left) {  // Checks if the left child of the current node exists.
        array[top] = 0;  // Appends 0 to the array to represent a left branch in the binary code.
        printCodes(root->left, array, top + 1);   // printCodes function for the left subtree, moving down the tree.
    }

    if (root->right) {
        array[top] = 1;  // right branch in the binary code.
        printCodes(root->right, array, top + 1);
    }

    if (!(root->left) && !(root->right)) {   // has no left or right child
        printf("'%c': ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", array[i]);
        }
        printf("\n");
    }
}

// Function to perform Huffman coding
void huffman(char data[], int freq[], int n) {
    struct Node* root = buildHuffmanTree(data, freq, n);
// Initializes an array to store the binary code for each character during traversal. top is used to keep track of the top index in the array.
    int array[MAX_CHARACTERS], top = 0;

    printf("Huffman Codes:\n");
    printCodes(root, array, top);  //printCodes function, starting from the root of the Huffman tree
}

int main() {
    char data[MAX_CHARACTERS];
    int freq[MAX_CHARACTERS], n;

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    printf("Enter the characters and their frequencies:\n");
    for (int i = 0; i < n; ++i) {
        scanf(" %c %d", &data[i], &freq[i]);
    }

    huffman(data, freq, n);

    return 0;
}
