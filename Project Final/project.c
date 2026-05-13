#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>

/* Maximum number of stored results for "b" (history navigation) */
#define HISTORY_SIZE 10000

/* =========================================================
   FUNCTION: remove_crlf
   PURPOSE: Remove newline (\n) and carriage return (\r)
   from input strings read using fgets()
========================================================= */
void remove_crlf(char *s)
{
    char *t = s + strlen(s);
    t--;

    while (t >= s && (*t == '\n' || *t == '\r'))
    {
        *t = '\0';
        t--;
    }
}

/* =========================================================
   BASIC MATH OPERATIONS (BINARY)
========================================================= */

double addition(double x, double y) { return x + y; }
double subtraction(double x, double y) { return x - y; }
double multiplication(double x, double y) { return x * y; }

/* Division with basic error handling */
double division(double x, double y)
{
    if (y == 0)
    {
        printf("error\n");
        return NAN;
    }
    return x / y;
}

/* Exponentiation */
double exponent(double x, double y) { return pow(x, y); }

/* =========================================================
   TRIGONOMETRIC FUNCTIONS (UNARY)
========================================================= */

double sine(double x) { return sin(x); }
double cosine(double x) { return cos(x); }
double tangent(double x) { return tan(x); }

double arc_sine(double x) { return asin(x); }
double arc_cosine(double x) { return acos(x); }
double arc_tangent(double x) { return atan(x); }

/* =========================================================
   OTHER UNARY FUNCTIONS
========================================================= */

double square_root(double x) { return sqrt(x); }
double absolute_value(double x) { return fabs(x); }

/* Reciprocal (1/x) */
double inverse(double x) { return 1.0 / x; }

/* Log base 10 */
double logten(double x) { return log10(x); }

/* Log base 2 */
double logtwo(double x) { return log(x) / log(2); }

/* =========================================================
   INPUT PARSER
   PURPOSE:
   - Converts string input into numeric value
   - Handles constants like pi and e
========================================================= */
double parse_input(char *buf)
{
    remove_crlf(buf);

    if (strcasecmp(buf, "pi") == 0)
        return M_PI;

    if (strcasecmp(buf, "e") == 0)
        return M_E;

    return atof(buf); // fallback numeric conversion
}

/* =========================================================
   MAIN PROGRAM
========================================================= */

int main(void)
{
    /* Open history file for paper tape output */
    FILE *history = fopen("history.txt", "w");

    /* Stores results for BACKTRACKING ("b" feature) */
    double history_values[HISTORY_SIZE];
    int history_index = -1;

    /* Input buffers */
    char x_buffer[64], y_buffer[64], op_buffer[64], temp[64];

    /* Working variables */
    double x, y, result;

    /* =====================================================
       MAIN LOOP (runs until user quits)
    ===================================================== */
    while (1)
    {
        /* =================================================
           STEP 1: INPUT FIRST VALUE (X)
           Supports:
           - number
           - pi / e
           - "b" (history backtracking)
        ================================================= */
        printf("Enter value: ");
        fgets(x_buffer, 63, stdin);
        remove_crlf(x_buffer);

        /* =========================
           BACKTRACK FEATURE ("b")
        ========================= */
        if (strcasecmp(x_buffer, "b") == 0)
        {
            int idx = history_index;

            while (1)
            {
                /* No more history available */
                if (idx < 0)
                {
                    printf("error\n");
                    goto restart;
                }

                /* Show previous value */
                printf("Previous: %.6lf\n", history_values[idx]);
                printf("Press ENTER to accept, 'b' to go back: ");

                fgets(temp, 63, stdin);
                remove_crlf(temp);

                /* Accept current history value */
                if (strlen(temp) == 0)
                {
                    x = history_values[idx];
                    break;
                }
                /* Go further back */
                else if (strcasecmp(temp, "b") == 0)
                {
                    idx--;
                }
                /* Invalid input */
                else
                {
                    printf("error\n");
                    goto restart;
                }
            }
        }
        else
        {
            /* Normal numeric / constant input */
            x = parse_input(x_buffer);
        }

        /* =================================================
           STEP 2: OPERATION INPUT
        ================================================= */
        printf("Enter operation: ");
        fgets(op_buffer, 63, stdin);
        remove_crlf(op_buffer);

        /* =================================================
           STEP 3: BINARY OPERATIONS
        ================================================= */
        if (strcasecmp(op_buffer, "+") == 0 ||
            strcasecmp(op_buffer, "-") == 0 ||
            strcasecmp(op_buffer, "x") == 0 ||
            strcasecmp(op_buffer, "/") == 0 ||
            strcasecmp(op_buffer, "^") == 0)
        {
            printf("Enter value: ");
            fgets(y_buffer, 63, stdin);
            remove_crlf(y_buffer);

            y = parse_input(y_buffer);

            /* Perform selected operation */
            if (strcasecmp(op_buffer, "+") == 0)
                result = addition(x, y);
            else if (strcasecmp(op_buffer, "-") == 0)
                result = subtraction(x, y);
            else if (strcasecmp(op_buffer, "x") == 0)
                result = multiplication(x, y);
            else if (strcasecmp(op_buffer, "/") == 0)
                result = division(x, y);
            else if (strcasecmp(op_buffer, "^") == 0)
                result = exponent(x, y);
        }

        /* =================================================
           STEP 4: UNARY OPERATIONS
        ================================================= */
        else if (strcasecmp(op_buffer, "sin") == 0)
            result = sine(x);

        else if (strcasecmp(op_buffer, "cos") == 0)
            result = cosine(x);

        else if (strcasecmp(op_buffer, "tan") == 0)
            result = tangent(x);

        else if (strcasecmp(op_buffer, "asin") == 0)
            result = arc_sine(x);

        else if (strcasecmp(op_buffer, "acos") == 0)
            result = arc_cosine(x);

        else if (strcasecmp(op_buffer, "atan") == 0)
            result = arc_tangent(x);

        else if (strcasecmp(op_buffer, "sqrt") == 0)
            result = square_root(x);

        else if (strcasecmp(op_buffer, "abs") == 0)
            result = absolute_value(x);

        else if (strcasecmp(op_buffer, "inv") == 0)
            result = inverse(x);

        else if (strcasecmp(op_buffer, "log10") == 0)
            result = logten(x);

        else if (strcasecmp(op_buffer, "log2") == 0)
            result = logtwo(x);

        /* =================================================
           EXIT CONDITION
        ================================================= */
        else if (strcasecmp(op_buffer, "q") == 0)
        {
            fclose(history);
            return 0;
        }

        /* =================================================
           ERROR HANDLING
        ================================================= */
        else
        {
            printf("error\n");
            goto restart;
        }

        /* =================================================
           STEP 5: OUTPUT + STORE HISTORY
        ================================================= */
        printf("Result: %.6lf\n", result);

        /* Write to paper tape file */
        fprintf(history, "%.6lf\n", result);

        /* Store in memory for "b" feature */
        history_values[++history_index] = result;

    /* Restart loop safely after errors */
    restart:
        continue;
    }

    return 0;
}
