/*
    This program takes values from an input file and stores them into
    variables inside a data structure to find y-values using multiple
    x-values, then writes the data into a binary output file.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

// Data structure for storing title, slope, intercept, x-values, and y-values
struct slope_form
{
    char title[64];

    float m;
    float b;

    double x[10];
    double y[10];
};

typedef struct slope_form data_structure;

// Function to calculate y from slope-intercept form
void y_function(double *y, float m, double x, float b)
{
    *y = (m * x) + b;
}

int main(void)
{
    int i;
    int j;
    int n;

    FILE *ifp;
    FILE *ofp;

    // Open input and output files
    ifp = fopen("as4input.txt", "r");

    ofp = fopen("as4output-Ramdihal-Ryan.bin", "wb");

    // Read integer count from input file
    fscanf(ifp, "%d ", &n);

    // Create array of data structures
    data_structure data_set[n];

    // Loop through each structure instance
    for (i = 0; i < n; i++)
    {
        // Read title
        fgets(data_set[i].title, 63, ifp);

        // Read slope and y-intercept
        fscanf(ifp, "%f %f ", &data_set[i].m, &data_set[i].b);

        // Read x-values and calculate y-values
        for (j = 0; j < 10; j++)
        {
            fscanf(ifp, "%lf ", &data_set[i].x[j]);

            y_function(
                &data_set[i].y[j],
                data_set[i].m,
                data_set[i].x[j],
                data_set[i].b
            );
        }

        // Write structure into binary output file
        fwrite(&data_set[i], sizeof(data_structure), 1, ofp);
    }

    // Close files
    fclose(ifp);
    fclose(ofp);

    return 0;
}
