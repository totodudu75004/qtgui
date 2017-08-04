#ifndef LUT_H
#define LUT_H


class LUT
{
public:
    LUT();
    //~LUT();
    int linear(double x);
    void limit(double xmi, double xma);
    void initsig(double xmi, double xma);
    void siglim(double sig);
    void bitNumber(int Nbit);
    double sigmin;
    double sigmax;
    double xmin;
    double xmax;
    int maxlut;
private:
    int bit;
};

#endif // LUT_H
