#pragma once
extern "C" {
#include "Opt.h"
}
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void SolveWarping(int width, int height, float* unknown, float* target) {
    Opt_InitializationParameters param;
    param.doublePrecision = 1;
    param.verbosityLevel = 1;
    param.collectPerKernelTimingInfo = 1;
    Opt_State* state = Opt_NewState(param);
    // load the Opt DSL file containing the cost description
    Opt_Problem* problem = Opt_ProblemDefine(state,"warpingEnergy.opt", NULL);
    // describe the dimensions of the instance of the problem
    uint32_t dims[] = { width, height };
    Opt_Plan* plan = Opt_ProblemPlan(state, problem, dims);
    // run the solver
    void* problem_data[] = { unknown, target };
    Opt_ProblemSolve(state, plan, problem_data);
}


int main(){


  int width, height;
  float *unknown;
  float *target;
  Mat image;
  image = imread("../data/cat512.png");

  namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
  imshow( "Display window", image );                   // Show our image inside it.

  width = image.cols;
  height = image.rows;

  waitKey(0);                                          // Wait for a keystroke in the window
  return 0;
  SolveWarping(width, height, unknown, target);

}