#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include"Vector.h"
#include"Wave.h"
#include"Heat.h"

using namespace std;

Vector vec_sin( Vector vec_input );
Vector vec_cos( Vector vec_input );
Vector vec_tan( Vector vec_input );


int main(){
  
  // Conditions and constants
  float dt = 0.003; 
  float dx = 0.1; 
  float x_end = 3.2;
  float t_end = 60.0;
  float coef = 1.0;
  float b[2] = {0.0, 0.0}; // Boundary conditions

  // Initial conditon time
  Vector (*init)(Vector);  // Pointer to function
  init = &vec_sin;    // Pointer to function sin

  // Creating the instance
  Heat test_heat(dt, dx, t_end, x_end, coef, b, init);

  // Solving it and plotting
  // test.Wave_Solve();
  test_heat.Heat_Solve();

  // Ploting the results
//  test_heat.Heat_Plot(2);
  test_heat.Heat_nPlot(2);

  // Wave Equation
//  Wave test_wave(dt, dx, t_end, x_end, coef, b, init);
//  test_wave.Wave_Solve();
//  test_wave.Wave_Plot();
//  test_wave.Wave_nPlot(2);

  return 0;
}



// Return the sin of all elements of the vector input argument
Vector vec_sin( Vector vec_input ){

  int i, Ndata = vec_input.getNdata();
  Vector vec_output(Ndata);

  float value;
  for (i = 0; i < Ndata; i++){

    value = vec_input.getData(i);
    vec_output.setData( sin( value), i);
  }

  return vec_output;
}

// Return the cos of all elements of the vector input argument
Vector vec_cos( Vector vec_input ){

  int i, Ndata = vec_input.getNdata();
  Vector vec_output(Ndata);

  float value;
  for (i = 0; i < Ndata; i++){

    value = vec_input.getData(i);
    vec_output.setData( cos( value), i);
  }

  return vec_output;
}

// Return the tan of all elements of the vector input argument
Vector vec_tan( Vector vec_input ){

  int i, Ndata = vec_input.getNdata();
  Vector vec_output(Ndata);

  float value;
  for (i = 0; i < Ndata; i++){

    value = vec_input.getData(i);
    vec_output.setData( tan( value), i);
  }

  return vec_output;
}









