/*
    This program reads input data into a dynamically allocated struct,
    allocates memory for arrays of x and computed y values, calculates
    y using the slope-intercept form, and writes the results to an output file.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct slope_data
{
    float m;      // slope
    float b;      // y-intercept
    int n;        // number of x values

    double *x;    // dynamically allocated x array
    double *y;    // dynamically allocated y array
};

typedef struct slope_data data_structure;

// Constructor: allocates memory for struct and arrays
data_structure *new_data(float m, float b, int n)
{
    data_structure *new_data_set = malloc(sizeof(data_structure));

    new_data_set->x = malloc(sizeof(double) * n);
    new_data_set->y = malloc(sizeof(double) * n);

    new_data_set->m = m;
    new_data_set->b = b;
    new_data_set->n = n;

    return new_data_set;
}

// Destructor: frees allocated memory
void destructor(data_structure *new_data)
{
    free(new_data->x);
    free(new_data->y);
    free(new_data);
}

// Computes y = mx + b
void y_function(double *y, float m, double x, float b)
{
    *y = (m * x) + b;
}

int main(void)
{
    FILE *ifp;
    FILE *ofp;

    ifp = fopen("as5input.txt", "r");
    ofp = fopen("as5output-Ramdihal-Ryan.txt", "w");

    int i;
    int n;
    float m;
    float b;

    // Read slope, intercept, and number of x values
    fscanf(ifp, "%f %f ", &m, &b);
    fscanf(ifp, "%d ", &n);

    // Create dynamically allocated data structure
    data_structure *data_set = new_data(m, b, n);

    fprintf(
        ofp,
        "slope(m): %f y-intercept(b): %f\n",
        data_set->m,
        data_set->b
    );

    // Read x values, compute y values, and write output
    for (i = 0; i < data_set->n; i++)
    {
        fscanf(ifp, "%lf ", &data_set->x[i]);

        y_function(
            &data_set->y[i],
            data_set->m,
            data_set->x[i],
            data_set->b
        );

        fprintf(
            ofp,
            "x[%d]: %+lf, y[%d]: %+lf\n",
            i,
            data_set->x[i],
            i,
            data_set->y[i]
        );
    }

    fclose(ifp);
    fclose(ofp);

    // Free allocated memory
    destructor(data_set);

    return 0;
}
