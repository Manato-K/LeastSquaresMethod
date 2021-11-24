/*least squares method*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20

int main(void)
{
    int i, j, n;
    float x[N], y[N], a, b, sx=0.0, sy=0.0, sx2=0.0, sxy=0.0;
    FILE *fp;

    if ((fp=fopen("20211125-1.dat","r"))==NULL){
        printf("cannot open file/n");
        exit(0);
    }
    i=0;
    while (fscanf(fp,"%f",&x[i])!=EOF&&i<N)
    {
        fscanf(fp,"%f",&y[i]);
        sx+=x[i];
        sy+=y[i];
        sx2+=x[i]*x[i];
        sxy+=x[i]*y[i];
    }
    n=i;
    fclose(fp);

    a=(sx2*sy-sx*sxy)/(n*sx2-sx*sx);
    b=(n*sxy-sx*sy)/(n*sx2-sx*sx);
    printf("y=%.4f",b);
    if(b>0) printf("+");
    printf("%.4f %.4f(%4.f)/n",x[i],y[i],a+b*x[i]);
    
}