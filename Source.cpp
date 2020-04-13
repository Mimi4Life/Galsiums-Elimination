/***

Purpose: This program performs Galsiums elimination to put a linear system in row echelon form. This program also performs partial pivoting of three linear equations.
Author: Miriam Ekiye
           ***/

#include<bits/stdc++.h> 
#include<cstdio>
#include <cmath> 
using namespace std;

#define Num 3     

// function to calculate the values from the backsub function
void backSub(double matrix[Num][Num + 1]);
// This function performs partial pivoting with the input fromthe user 
int partialPivot(double matrix[Num][Num + 1]);


/***
Program Name: swap
Function Purpose: This function performs the swaping two coeffiecient for partial pivoting.
Author: Miriam Ekiye
           ***/


void swap(double matrix[Num][Num + 1], int i, int j)
{

    for (int k = 0; k <= Num; k++)
    {
        double temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }


}



/***
Program Name: gE
Function Purpose: In this function Galsiums elimination by reducing th equation to row echlon form it also uses backsubstitution in printing the operation. If the matrix is singular this method will indicate it. If the matrix is inconsist this indicate it as well
Author: Miriam Ekiye
           ***/

void gE(double matrix[Num][Num + 1])
{
    /* Reduces equation to row echelon form */
    int check = partialPivot(matrix);

    /* if matrix is singular */
    if (check != -1)
    {
        printf("This is a Singular Matrix.\n");

        /* This system has infinately many solutions if the right hand side coresonds to zero. or it is inconsistent   */
        if (matrix[check][Num])
            printf("This system is inconsisant");
        else
            printf(" infinately many solutions ");

        return;
    }

    /* get solution to system and print it using
       backward substitution */
    backSub(matrix);
}

/***
Program Name: print
Function Purpose: This function prints out the values of the matrix at any stage.
Author: Miriam Ekiye

           ***/

void print(double matrix[Num][Num + 1])
{
    for (int i = 0; i < Num; i++, printf("\n"))
        for (int j = 0; j <= Num; j++)
            printf(("%.1f"), matrix[i][j]);

    printf("\n");
}



/***
Program Name: forwardElim
Function Purpose: This function is made for performing partial pivoting. It also uses the swap function in performing this operation. The partial pivot solutions are printed out here aswell
Author: Miriam Ekiye

           ***/

           // function to reduce equation to row echlon form 
int partialPivot(double matrix[Num][Num + 1])
{
    for (int k = 0; k < Num; k++)
    {
        // Initialize maximum value and index for pivot 
        int i_max = k;
        int v_max = matrix[i_max][k];

        /* find greater amplitude for pivot if any */
        for (int i = k + 1; i < Num; i++)
            if (abs(matrix[i][k]) > v_max)
                v_max = matrix[i][k], i_max = i;

        /* if a prinicipal diagonal element  is zero,
         * it denotes that matrix is singular, and
         * will lead to a division-by-zero later. */
        if (!matrix[k][i_max])
            return k;


        /* Swap the greatest value row with current row */
        if (i_max != k)
            swap(matrix, k, i_max);


        for (int i = k + 1; i < Num; i++)
        {
            int j;
            /* factor f to set current row kth element to 0,
             * and subsequently remaining kth column to 0 */
            double f = matrix[i][k] / matrix[k][k];

            /* subtract fth multiple of corresponding kth
               row element*/
            for (j = k + 1; j <= Num; j++)
                matrix[i][j] -= matrix[k][j] * f;

            cout << "Partial pivot solution is: (" << f << "X)" << "\n";

            /* filling lower triangular matrix with zeros*/
            matrix[i][k] = 0;

        }

    }
    return -1;
}


/***
Program Name: backsub
Function Purpose: This function performs back substitution and is used in printing solution
Author: Miriam Ekiye

           ***/


void backSub(double matrix[Num][Num + 1])
{
    double x[Num];  // An array to store solution 

    /* Start calculating from last equation up to the
       first */
    for (int i = Num - 1; i >= 0; i--)
    {
        /* start with the RHS of the equation */
        x[i] = matrix[i][Num];

        /* Initialize j to i+1 since matrix is upper
           triangular*/
        for (int j = i + 1; j < Num; j++)
        {
            /* subtract all the lhs values
             * except the coefficient of the variable
             * whose value is being calculated */
            x[i] -= matrix[i][j] * x[j];
        }

        /* divide the RHS by the coefficient of the
           unknown being calculated */
        x[i] = x[i] / matrix[i][i];

    }

    //printf("\nThe solution for this system of equations is:\n"); 
    int n = 1;

    for (int i = 0; i < Num; i++)
    {


        cout << "Galsiums elimination solution is: (" << printf("%.1f", x[i]) << "X)\n";

    }
    cout << "End of the solutions\n";

}


// Driver program 
int main()
{

    double first1, first2, first3, first4; //Coefficients for the first equation
    double second1, second2, second3, second4;//Coefficients for the second equation
    double third1, third2, third3, third4;//Coefficients for the third equation

    cout << " Enter four coefficients for the first linear equation \n";

    cin >> first1 >> first2 >> first3 >> first4;

    cout << " Enter four coefficients for the second linear equation \n";

    cin >> second1 >> second2 >> second3 >> second4;

    cout << " Enter four coefficients for the third linear equation \n";

    cin >> third1 >> third2 >> third3 >> third4;
    //The coefficients entered by the uses are used for the matrixs
    double matrix[Num][Num + 1] = { {first1, first2,first3,first4},
                          {second1, second2, second3,second4},
                          {third1, third2, third3,third4}
    };
    //computes values
    gE(matrix);

    return 0;

}










