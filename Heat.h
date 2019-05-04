#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

class Heat{

  private:
    float dt, dx;
    float t_end, x_end;
    float coef;
    float *b;
    Vector *data;
    Vector *x;
    Vector *t;
    Vector (*pf)(Vector);

    int NTimeVectors;
    int NPosElements;

  public:
    Heat(float, float, float, float, float, float*, Vector (*)(Vector) );
    Vector *getTimeVector(int);

    void Heat_Solve();
    void Heat_Plot(int);
    void Heat_nPlot(int);
};
