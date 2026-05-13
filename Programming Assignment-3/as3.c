// The purpose of this program is to read and write files into data parameters //

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <math.h>

// Function for the slope formula of the two ordered pairs
double slope_formula(double y2, double y1, double x2, double x1, double m)
{
    m = (y2 - y1) / (x2 - x1);
    return m;
}

// Function to find the y-intercept using the first ordered pair
double y_intercept_formula(double y1, double x1, double b, double m)
{
    b = y1 - (m * x1);
    return b;
}

// Function to calculate y-values from x-values
void y_formula(double *x_presets, double m, double b, int n, double *y_results)
{
    int i;

    for (i = 0; i < n; i++)
    {
        y_results[i] = (m * x_presets[i]) + b;
    }

    return;
}

int main(void)
{
    FILE *ifp;
    FILE *ofp;

    ifp = fopen("cop3223-as3input.txt", "r");
    ofp = fopen("cop3223-as3output-Ramdihal-Ryan.txt", "w");

    double m;      // slope
    double b;      // y-intercept
    double y2;     // second ordered pair y-value
    double y1;     // first ordered pair y-value
    double x1;     // first ordered pair x-value
    double x2;     // second ordered pair x-value

    char title[128];

    int i;
    int n;

    // Arrays from input file
    double x[16];
    double y[16];

    // Preset x-coordinate arrays
    double x_preset1[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    double x_preset2[11] = {0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10};

    double x_preset3_tens[8] =
    {
        0,
        1,
        10,
        100,
        1000,
        10000,
        100000,
        1000000
    };

    double x_preset4_tens[6] =
    {
        1.0,
        0.1,
        0.01,
        0.001,
        0.0001,
        0.00001
    };

    // Arrays to store y-results
    double y_results1[11];
    double y_results2[11];
    double y_results3_tens[8];
    double y_results4_tens[6];

    // Read title from input file
    fgets(title, 127, ifp);

    fprintf(ofp, "%s\n", title);

    // Read ordered pairs
    fscanf(ifp, "%lf, %lf", &x1, &y1);
    fscanf(ifp, "%lf, %lf", &x2, &y2);

    // Calculate slope and y-intercept
    m = slope_formula(y2, y1, x2, x1, m);

    b = y_intercept_formula(y1, x1, b, m);

    fprintf(
        ofp,
        "With the ordered pairs (%.2lf, %.2lf) and (%.2lf, %.2lf), "
        "the slope is %.2lf and the y-intercept is %.2lf.\n",
        x1,
        y1,
        x2,
        y2,
        m,
        b
    );

    // First preset
    n = 11;

    y_formula(x_preset1, m, b, n, y_results1);

    for (i = 0; i < n; i++)
    {
        fprintf(
            ofp,
            "The first set of ordered pairs: (%11.3lf, %14.3lf)\n",
            x_preset1[i],
            y_results1[i]
        );
    }

    fprintf(ofp, "\n");

    // Second preset
    y_formula(x_preset2, m, b, n, y_results2);

    for (i = 0; i < n; i++)
    {
        fprintf(
            ofp,
            "The second set of ordered pairs: (%11.3lf, %14.3lf)\n",
            x_preset2[i],
            y_results2[i]
        );
    }

    fprintf(ofp, "\n");

    // Third preset
    n = 8;

    y_formula(x_preset3_tens, m, b, n, y_results3_tens);

    for (i = 0; i < n; i++)
    {
        fprintf(
            ofp,
            "The third set of ordered pairs: (%11.3lf, %14.3lf)\n",
            x_preset3_tens[i],
            y_results3_tens[i]
        );
    }

    fprintf(ofp, "\n");

    // Fourth preset
    n = 6;

    y_formula(x_preset4_tens, m, b, n, y_results4_tens);

    for (i = 0; i < n; i++)
    {
        fprintf(
            ofp,
            "The fourth set of ordered pairs: (%13.5lf, %15.6lf)\n",
            x_preset4_tens[i],
            y_results4_tens[i]
        );
    }

    fprintf(ofp, "\n");

    // Read values from input file
    fscanf(ifp, "%d", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(ifp, "%lf", &x[i]);

        y_formula(x, m, b, n, y);

        fprintf(
            ofp,
            "Ordered pairs from input file: (%13.5lf, %12.3lf)\n",
            x[i],
            y[i]
        );
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
