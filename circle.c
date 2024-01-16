#include <stdio.h>
#include <math.h>

// Function to print the circle
void printCircle(int radius) {
    // Determine the center of the circle
    int centerX = radius;
    int centerY = radius;

    // Define the size of the array
    int size = 2 * radius + 1;
    char circleArray[size][size];

    // Initialize the array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            circleArray[i][j] = ' ';
        }
    }

    // Mark the points inside the circle
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            float distance = (i - centerX)*(i - centerX)+ (j - centerY)*(j - centerY);
            if (distance <= radius) {
                circleArray[i][j] = '*';
            }
        }
    }

    // Print the array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", circleArray[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Set the radius of the circle
    int radius;
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    // Print the circle
    printCircle(radius);

    return 0;
}
