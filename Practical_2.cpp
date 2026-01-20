// Exercise 2: Area of the Mandelbrot Set

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define NPOINTS 2000
#define MAXITER 2000

struct complex
{
    double real;
    double imag;
};

int main()
{
    int numoutside = 0;
    double area, error;
    double start, finish;

    /*
     *
     *
     *     Outer loops run over npoints, initialise z=c
     *
     *     Inner loop has the iteration z=z*z+c, and threshold test
     */

    start = omp_get_wtime();
#pragma omp parallel reduction(+ : numoutside)
    {
        int tid = omp_get_thread_num();       // 当前线程 ID
        int nthreads = omp_get_num_threads(); // 总线程数
        for (int i = tid; i < NPOINTS; i += nthreads)
        {
            for (int j = 0; j < NPOINTS; j++)
            {
                struct complex z, c;
                c.real = -2.0 + 2.5 * (double)(i) / (double)(NPOINTS) + 1.0e-7;
                c.imag = 1.125 * (double)(j) / (double)(NPOINTS) + 1.0e-7;
                z = c;
                for (int iter = 0; iter < MAXITER; iter++)
                {
                    double ztemp = (z.real * z.real) - (z.imag * z.imag) + c.real;
                    z.imag = z.real * z.imag * 2 + c.imag;
                    z.real = ztemp;
                    if ((z.real * z.real + z.imag * z.imag) > 4.0e0)
                    {
                        numoutside++;
                        break;
                    }
                }
            }
        }
    }
    finish = omp_get_wtime();

    /*
     *  Calculate area and error and output the results
     */

    area = 2.0 * 2.5 * 1.125 * (double)(NPOINTS * NPOINTS - numoutside) / (double)(NPOINTS * NPOINTS);
    error = area / (double)NPOINTS;

    printf("Area of Mandlebrot set = %12.8f +/- %12.8f\n", area, error);
    printf("Time = %12.8f seconds\n", finish - start);
}
