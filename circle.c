#include <stdio.h>
#include <math.h>

int main(void) {

    int width, height;

    printf("Enter width: ");
    scanf("%d", &width); // 4
    printf("Enter height: ");
    scanf("%d", &height); // 3

    // Create circle array
    char circle[width][height];

    // Fill circle with data
    double fwidth, fheight, fheightp, radius, dist;
    radius = (double)width / 2.; // 2
    for(int i = 0; i < height; i++) { // 0

        for(int j = 0; j < width; j++) { // 0

            fwidth = (double)j + 0.5 - (double) width / 2.;
            fheight = (double)i + 0.5 - (double)height / 2.;
            fheightp = fheight * (double)width / (double)height; 
            circle[j][i] = ' ';
            dist = sqrt(fwidth * fwidth + fheightp * fheightp);
            if(dist <= radius) {
                circle[j][i] = '#';
            }
        }
    }

    // Print circle
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%c", circle[j][i]);
        }

        printf("\n");
    }
}