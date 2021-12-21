#include <stdio.h>
#include <math.h>

#define GRAPH_WIDTH 150
#define GRAPH_HEIGHT 120

char graph[GRAPH_WIDTH][GRAPH_HEIGHT];
int total = 0;

void drawCircle(int x, int y, double r);

int main(void) {

    // Clear grid
    for(int i = 0; i < GRAPH_HEIGHT; i++) {
        for(int j = 0; j < GRAPH_WIDTH; j++) {
            graph[j][i] = '-';
        }
    }

    // Get length of graph
    int length;
    printf("Enter graph length: ");
    scanf("%d", &length);
    
    // Get height of graph
    int height;
    printf("Enter graph height: ");
    scanf("%d", &height);

    // Get pen radius
    double rad;
    printf("Enter pen radius: ");
    scanf("%lf", &rad);

   // Draw on the graph
    int xLoc, yLoc, yLocNew, yRadCeil;
    xLoc = rad;
    yLoc = rad;
    yRadCeil = (int)ceil(rad);
    while(xLoc < length - rad) {
        yLocNew = (int)round(rad + ((double)height - rad) * (1.0 - (1.0 + cos((M_PI * ((double)xLoc - rad) / ((double)length - rad * 2)) )) / 2) );
        int yLocPrev;
        do {
            drawCircle(xLoc, yLoc, rad);
            yLocPrev = yLoc;
            if(yLoc < yLocNew) yLoc++;
            else yLoc--;
        } while(yLocPrev != yLocNew);

        xLoc++;
    } 

     // drawCircle(20,30, 7, 14, 2);
    
      // Output
      for(int i = 0; i < height; i++) {
             for(int j = 0; j < length; j++) {
                printf("%c", graph[j][i]);
            }

            printf("\n");
        }

        printf("%d\n", total);
    //}*/
}

void drawCircle(int x, int y, double r) {

    // Fill circle with data
    double fwidth, fheight, fheightp, radius, dist;
    radius = r;
    for(int i = y - r; i < y + r; i++) { // 0

        for(int j = x - r; j < x + r; j++) { // 0

            fwidth = (double)j - ((double)x);
            fheight = (double)i - ((double)y);
            graph[j][i] = '.';
            dist = sqrt(fwidth * fwidth + fheight * fheight);
            if(dist <= radius) {
                graph[j][i] = '#'; total++;
            }
            
           // graph[j][i] = '#';
        }
    }

}