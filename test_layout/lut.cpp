#include "lut.h"
#include <stdlib.h>
#include <stdio.h>

LUT::LUT()
{
    bit = 8;
    maxlut = 255;
    xmin = 0.0;
    xmax = 1.0;
    sigmin = 0.0;
    sigmax = 0.0;
}

void LUT::bitNumber(int Nbit)
{
    printf("new number of bits : %i\n",Nbit);
    if (Nbit > 0 && Nbit < 9)
    {
        bit=Nbit;
    }
}

void LUT::limit(double xmi, double xma)
{
    xmin=xmi;
    xmax=xma;
}

void LUT::initsig(double min, double max)
{
    sigmin=min;
    sigmax=max;
}

void LUT::siglim(double sig)
{
    if (sig < sigmin) {sigmin=sig;}
    else if (sig > sigmax) {sigmax=sig;}
}

int LUT::linear(double x)
{
    int out=0;
    double bitlim=2.0;
    for (int i=1 ; i<bit ; i++) {bitlim*=2.0;}
    maxlut=(int)bitlim-1;
    double delta=(bitlim-1.0)/(xmax-xmin);
    if (x > xmax) {out=maxlut;}
    else if (x > xmin)
    {
        out=(int)(delta*(x-xmin));
    }
    return out;
}
