#include "classifier.h"
#include <math.h>
#include <string>
#include <vector>
#include<iostream>


using Eigen::ArrayXd;
using std::string;
using std::vector;
using namespace std;

// Initializes GNB
GNB::GNB() {
  /**
   * TODO: Initialize GNB, if necessary. May depend on your implementation.
   */
  
}

GNB::~GNB() {}

void GNB::train(const vector<vector<double>> &data, 
                const vector<string> &labels) {
  /**
   * Trains the classifier with N data points and labels.
   * @param data - array of N observations
   *   - Each observation is a tuple with 4 values: s, d, s_dot and d_dot.
   *   - Example : [[3.5, 0.1, 5.9, -0.02],
   *                [8.0, -0.3, 3.0, 2.2],
   *                 ...
   *                ]
   * @param labels - array of N labels
   *   - Each label is one of "left", "keep", or "right".
   *
   * TODO: Implement the training function for your classifier.
   */

  // find mean and std_dev for each lable/feature pair
  // we have 4 features and 3 labels == 12 means and 12 std devs
  // so 24 variables in total if brute forcing
  // starting with mean for s/left feature lable
  double sum_s = 0;
  double sum_d = 0;
  double sum_sdot = 0;
  double sum_ddot = 0;
  double mean_s = 0;
  double mean_d = 0;
  double mean_sdot = 0;
  double mean_ddot = 0;

  double mean_left_s;
  double mean_left_d;
  double mean_left_s_dot;
  double mean_left_d_dot;

  double mean_keep_s;
  double mean_keep_d;
  double mean_keep_s_dot;
  double mean_keep_d_dot;

  double mean_right_s;
  double mean_right_d;
  double mean_right_s_dot;
  double mean_right_d_dot;

  double stddev_keep_s;
  double stddev_keep_d;
  double stddev_keep_s_dot;
  double stddev_keep_d_dot;

  double stddev_right_s;
  double stddev_right_d;
  double stddev_right_s_dot;
  double stddev_right_d_dot;

  double stddev_left_s;
  double stddev_left_d;
  double stddev_left_s_dot;
  double stddev_left_d_dot;

  int count_left = 0;
  int count_keep = 0;
  int count_right = 0;

  // printf("Size of data0 is %lu \n", data[0].size()) ;
  // printf("The first value is %f \n", data[0][0]);
  
  // vector<double>::const_iterator it;
  // cout << "The vector1 elements are: ";
  // for ( it = data[0].begin(); it != data[0].end(); ++it)
  //   cout << *it << " "<<endl; // printing the values of v vector

  // vector<vector<double>>::const_iterator itt;
  // vector<double>::const_iterator obs;

  for (int i = 0; i < labels.size(); i++)
  {
    int lab;
    if (!(labels[i].compare("left")))
      lab = 0;
    else if (!(labels[i].compare("keep")))
      lab = 1;
    else if (!(labels[i].compare("right")))
      lab = 2;
    else
      ;

    switch (lab)
    {
    case 0: // left
    {
      count_left++;

      mean_left_s += data[i][0];
      mean_left_d += data[i][1];
      mean_left_s_dot += data[i][2];
      mean_left_d_dot += data[i][3];
    }
    case 1: // keep
    {
      count_keep++;

      mean_keep_s += data[i][0];
      mean_keep_d += data[i][1];
      mean_keep_s_dot += data[i][2];
      mean_keep_d_dot += data[i][3];
    }
    case 2: // right
    {
      count_right++;

      mean_right_s += data[i][0];
      mean_right_d += data[i][1];
      mean_right_s_dot += data[i][2];
      mean_right_d_dot += data[i][3];
    }
    } // end of switch
  }   // all lables done
  mean_left_s = mean_left_s / count_left;
  mean_left_d = mean_left_d / count_left;
  mean_left_s_dot = mean_left_s_dot / count_left;
  mean_left_d_dot = mean_right_d_dot / count_left;

  mean_keep_s = mean_keep_s / count_keep;
  mean_keep_d = mean_keep_d / count_keep;
  mean_keep_s_dot = mean_keep_s_dot / count_keep;
  mean_keep_d_dot = mean_left_d_dot / count_keep;

  mean_right_s = mean_right_s / count_right;
  mean_right_d = mean_right_d / count_right;
  mean_right_s_dot = mean_right_s_dot / count_right;
  mean_right_d_dot = mean_right_d_dot / count_right;

  cout << "Printing the mean values of left ..." << endl;
  cout << mean_left_s << " , " << mean_left_d <<  " , " << mean_left_s_dot <<  " , " << mean_left_d_dot << endl;
  cout << "Printing the mean values of keep ..." << endl;
  cout << mean_keep_s << " , " << mean_keep_d <<  " , " << mean_keep_s_dot <<  " , " << mean_keep_d_dot << endl;
  cout << "Printing the mean values of right ..." << endl;
  cout << mean_right_s << " , " << mean_right_d <<  " , " << mean_right_s_dot <<  " , " << mean_right_d_dot << endl;
}

string GNB::predict(const vector<double> &sample) {
  /**
   * Once trained, this method is called and expected to return 
   *   a predicted behavior for the given observation.
   * @param observation - a 4 tuple with s, d, s_dot, d_dot.
   *   - Example: [3.5, 0.1, 8.5, -0.2]
   * @output A label representing the best guess of the classifier. Can
   *   be one of "left", "keep" or "right".
   *
   * TODO: Complete this function to return your classifier's prediction
   */
  
  return this -> possible_labels[1];
}
