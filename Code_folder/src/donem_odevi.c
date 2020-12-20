#include<stdint.h>
#include<stdio.h>
#include<math.h>
#define PI 3.142857142857143 
#ifndef MAX
#define MAX  200              //Maximal  Number of triangle  if  Max number was not defined on compiling time
#endif

int main(int argc, char const *argv[])
{
    int n=4,r=3;
    float e_0=0.01,e_1,A[MAX];
    /*
      General Formule after calcule and at the begining a took n=4 for number 
      of the triangle inside the circle.After that we will increase the number
      for triangle until e_0>e_1.
    */
    do
    {  
         n=n+1;
         A[n]=n*(pow(r,2)*sin(PI/n)*cos(PI/n));
         A[n-1] = (n-1)*(pow(r,2)*sin(PI/(n-1))*cos(PI/(n-1)));
        e_1=fabs((A[n]-A[n-1])/A[n]);
        printf("%d_ Air value:%lf  with  error: %lf\n",n,A[n],e_1);
        A[n-1]=A[n];

    } while (e_0<e_1); //Control if(fabs((A[n]-A[n-1])/A[n])<e_0)
    
    return 0;
}

