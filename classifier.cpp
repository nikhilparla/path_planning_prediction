#include "classifier.h"
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

using Eigen::ArrayXd;
using std::string;
using std::vector;
using namespace std;

// Initializes GNB
GNB::GNB()
{
  /**
   * TODO: Initialize GNB, if necessary. May depend on your implementation.
   */
}

GNB::~GNB() {}

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

void GNB::train(const vector<vector<double>> &data,
                const vector<string> &labels)
{
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

  int count_left = 0;
  int count_keep = 0;
  int count_right = 0;

  double prob_left;
  double prob_keep;
  double prob_right;

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
  mean_left_d_dot = mean_left_d_dot / count_left;

  mean_keep_s = mean_keep_s / count_keep;
  mean_keep_d = mean_keep_d / count_keep;
  mean_keep_s_dot = mean_keep_s_dot / count_keep;
  mean_keep_d_dot = mean_keep_d_dot / count_keep;

  mean_right_s = mean_right_s / count_right;
  mean_right_d = mean_right_d / count_right;
  mean_right_s_dot = mean_right_s_dot / count_right;
  mean_right_d_dot = mean_right_d_dot / count_right;

  cout << "Printing the mean values of left ..." << endl;
  cout << mean_left_s << " , " << mean_left_d << " , " << mean_left_s_dot << " , " << mean_left_d_dot << endl;
  cout << "Printing the mean values of keep ..." << endl;
  cout << mean_keep_s << " , " << mean_keep_d << " , " << mean_keep_s_dot << " , " << mean_keep_d_dot << endl;
  cout << "Printing the mean values of right ..." << endl;
  cout << mean_right_s << " , " << mean_right_d << " , " << mean_right_s_dot << " , " << mean_right_d_dot << endl;

  // find variance
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
      stddev_left_s += pow(data[i][0] - mean_left_s, 2);
      stddev_left_d += pow(data[i][1] - mean_left_d, 2);
      stddev_left_s_dot += pow(data[i][2] - mean_left_s_dot, 2);
      stddev_left_d_dot += pow(data[i][3] - mean_left_d_dot, 2);
    }
    case 1: // keep
    {
      stddev_keep_s += pow(data[i][0] - mean_keep_s, 2);
      stddev_keep_d += pow(data[i][1] - mean_keep_d, 2);
      stddev_keep_s_dot += pow(data[i][2] - mean_keep_s_dot, 2);
      stddev_keep_d_dot += pow(data[i][3] - mean_keep_d_dot, 2);
    }
    case 2: // right
    {
      stddev_right_s += pow(data[i][0] - mean_right_s, 2);
      stddev_right_d += pow(data[i][1] - mean_right_d, 2);
      stddev_right_s_dot += pow(data[i][2] - mean_right_s_dot, 2);
      stddev_right_d_dot += pow(data[i][3] - mean_right_d_dot, 2);
    }
    } // end of switch
  }
  stddev_left_s = stddev_left_s / count_left;
  stddev_left_s = sqrt(stddev_left_s);

  stddev_left_d = stddev_left_d / count_left;
  stddev_left_d = sqrt(stddev_left_d);

  stddev_left_s_dot = stddev_left_s_dot / count_left;
  stddev_left_s_dot = sqrt(stddev_left_s_dot);

  stddev_left_d_dot = stddev_left_d_dot / count_left;
  stddev_left_d_dot = sqrt(stddev_left_d_dot);

  stddev_keep_s = stddev_keep_s / count_keep;
  stddev_keep_s = sqrt(stddev_keep_s);

  stddev_keep_d = stddev_keep_d / count_keep;
  stddev_keep_d = sqrt(stddev_keep_d);

  stddev_keep_s_dot = stddev_keep_s_dot / count_keep;
  stddev_keep_s_dot = sqrt(stddev_keep_s_dot);

  stddev_keep_d_dot = stddev_keep_d_dot / count_keep;
  stddev_keep_d_dot = sqrt(stddev_keep_d_dot);

  stddev_right_s = stddev_right_s / count_right;
  stddev_right_s = sqrt(stddev_right_s);

  stddev_right_d = stddev_right_d / count_right;
  stddev_right_d = sqrt(stddev_right_d);

  stddev_right_s_dot = stddev_right_s_dot / count_right;
  stddev_right_s_dot = sqrt(stddev_right_s_dot);

  stddev_right_d_dot = stddev_right_d_dot / count_right;
  stddev_right_d_dot = sqrt(stddev_right_d_dot);

  cout << "Printing the stddev values of left ..." << endl;
  cout << stddev_left_s << " , " << stddev_left_d << " , " << stddev_left_s_dot << " , " << stddev_left_d_dot << endl;
  cout << "Printing the stddev values of keep ..." << endl;
  cout << stddev_keep_s << " , " << stddev_keep_d << " , " << stddev_keep_s_dot << " , " << stddev_keep_d_dot << endl;
  cout << "Printing the stddev values of right ..." << endl;
  cout << stddev_right_s << " , " << stddev_right_d << " , " << stddev_right_s_dot << " , " << stddev_right_d_dot << endl;

  prob_left = count_left / labels.size();
  prob_keep = count_keep / labels.size();
  prob_right = prob_right / labels.size();

  cout << endl;
  cout << "Printing the probablilites..." << endl;
  cout << prob_left << " , " << prob_keep << " , " << prob_right << endl;
}

string GNB::predict(const vector<double> &sample)
{
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
  double prob_s;
  double prob_left = 1;
  double prob_keep = 1;
  double prob_right = 1;

  // prob of s being left * prob of d being left * prob of sdot being left * prob of ddot being left
  // prob of s being keep * prob of d being keep * prob of sdot being keep * prob of ddot being keep
  // prob of s being right * prob of d being right * prob of sdot being right * prob of ddot being right
  // Once you have all these probs, find the max one out of them.

  // prob of being left
  prob_s = exp(-1 * pow(sample[0] - mean_left_s,2) / (2 * pow(stddev_left_s,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_left_s,2));
  prob_left *= prob_s;

  prob_s = exp(-1 * pow(sample[1] - mean_left_d,2) / (2 * pow(stddev_left_d,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_left_s,2));
  prob_left *= prob_s;

  prob_s = exp(-1 * pow(sample[2] - mean_left_s_dot,2) / (2 * pow(stddev_left_s_dot,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_left_s_dot,2));
  prob_left *= prob_s;

  prob_s = exp(-1 * pow(sample[3] - mean_left_d_dot,2) / (2 * pow(stddev_left_d_dot,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_left_d_dot,2));
  prob_left *= prob_s;

  // prob of being keep
  prob_s = exp(-1 * pow(sample[0] - mean_keep_s,2) / (2 * pow(stddev_keep_s,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_keep_s,2));
  prob_keep *= prob_s;

  prob_s = exp(-1 * pow(sample[1] - mean_keep_d,2) / (2 * pow(stddev_keep_d,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_keep_s,2));
  prob_keep *= prob_s;

  prob_s = exp(-1 * pow(sample[2] - mean_keep_s_dot,2) / (2 * pow(stddev_keep_s_dot,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_keep_s_dot,2));
  prob_keep *= prob_s;

  prob_s = exp(-1 * pow(sample[3] - mean_keep_d_dot,2) / (2 * pow(stddev_keep_d_dot,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_keep_d_dot,2));
  prob_keep *= prob_s;

  // prob of being right
  prob_s = exp(-1 * pow(sample[0] - mean_right_s,2) / (2 * pow(stddev_right_s,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_right_s,2));
  prob_right *= prob_s;

  prob_s = exp(-1 * pow(sample[1] - mean_right_d,2) / (2 * pow(stddev_right_d,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_right_s,2));
  prob_right *= prob_s;

  prob_s = exp(-1 * pow(sample[2] - mean_right_s_dot,2) / (2 * pow(stddev_right_s_dot,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_right_s_dot,2));
  prob_right *= prob_s;

  prob_s = exp(-1 * pow(sample[3] - mean_right_d_dot,2) / (2 * pow(stddev_right_d_dot,2)));
  prob_s = prob_s / sqrt(2 * M_PI * pow(stddev_right_d_dot,2));
  prob_right *= prob_s;

  if (prob_left >= prob_right)
  {
    if (prob_left >= prob_keep)
    {
      return this->possible_labels[0];
    }
    else
    {
      return this->possible_labels[1];
    }
  }
  else
  {
    return this->possible_labels[1];
  }
}
