#pragma once
extern "C" {
#include "Opt.h"
}
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void SolveLaplacian(int width, int height, float* unknown, float* target) {
    Opt_InitializationParameters param;
    param.doublePrecision = 1;
    param.verbosityLevel = 1;
    param.collectPerKernelTimingInfo = 1;
    Opt_State* state = Opt_NewState(param);
    // load the Opt DSL file containing the cost description
    Opt_Problem* problem = Opt_ProblemDefine(state,"../src/laplacian.opt", "solverGaussNewtonGPU");
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
  Mat image, output;
  image = imread("../data/cat512.png");
  image.convertTo(image,CV_32F);

  /*namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
  imshow( "Display window", image );               // Show our image inside it.
  waitKey(10);  */                                   // Wait for a keystroke in the window

  width = image.cols;
  height = image.rows;
  output = Mat::ones(height,width,CV_32F);

  target = new float[width*height];
  unknown = new float[width*height];
  target = (float*)image.data;
  unknown = (float*)output.data;
  SolveLaplacian(width, height, unknown, target);

  return 0;

}
