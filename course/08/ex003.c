#include <stdio.h>

// Define the struct to represent a 3D vector
struct Vector {
    float x;  // X coordinate
    float y;  // Y coordinate
    float z;  // Z coordinate
};

// Function to read a vector from the user
struct Vector readVector() {
    struct Vector v;
    printf("Enter the x, y, and z components of the vector: ");
    scanf("%f %f %f", &v.x, &v.y, &v.z);
    return v;
}

// Function to add two vectors and return the result
struct Vector addVectors(struct Vector v1, struct Vector v2) {
    struct Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

int main() {
    // Read two vectors from the user
    printf("Enter the first vector:\n");
    struct Vector vector1 = readVector();

    printf("Enter the second vector:\n");
    struct Vector vector2 = readVector();

    // Calculate the sum of the two vectors
    struct Vector sum = addVectors(vector1, vector2);

    // Print the result
    printf("The sum of the vectors is: (%.2f, %.2f, %.2f)\n", sum.x, sum.y, sum.z);

    return 0;
}
