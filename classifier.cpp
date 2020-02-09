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
 
double mean_left_s;
double mean_left_d;
double mean_left_s_dot;
double mean_left_d_dot;
 
double mean_left_s;
double mean_left_d;
double mean_left_s_dot;
double mean_left_d_dot;
 
double stddev_keep_s;
double stddev_keep_d;
double stddev_keep_s_dot;
double stddev_keep_d_dot;
 
double stddev_right_s;
double stddev_right_d;
double stddev_right_s_dot;
double stddev_right_d_dot;
 
double stddev_left_s;;
double stddev_left_d;
double stddev_left_s_dot;
double stddev_left_d_dot;



  printf("Size of data0 is %lu \n", data[0].size()) ;
  printf("The first value is %f \n", data[0][0]);
  
  vector<double>::const_iterator it;
  cout << "The vector1 elements are: ";
  for ( it = data[0].begin(); it != data[0].end(); ++it)
    cout << *it << " "<<endl; // printing the values of v vector

  vector<vector<double>>::const_iterator itt;
  vector<double>::const_iterator obs;
  // for ( itt = data.begin(); itt != data.end(); ++itt)

  for(int i=0; i<data.size(); i++)
  {
    sum_s += data[i][0];
    sum_d += data[i][1];
    sum_sdot += data[i][2];
    sum_ddot += data[i][3];
  }
  mean_s = sum_s/data.size();
  mean_d = sum_d/data.size();
  mean_sdot = sum_sdot/data.size();
  mean_ddot = sum_ddot/data.size();

  cout << "sum of s values = "  << sum_s<< endl;
  cout << "Mean of s values = "  << mean_s<< endl;
  cout << "sum of d values = "  << sum_d<< endl;
  cout << "Mean of d values = "  << mean_d<< endl;
  cout << "sum of sdot values = "  << sum_sdot<< endl;
  cout << "Mean of sdot values = "  << mean_sdot<< endl;
  cout << "sum of ddot values = "  << sum_ddot<< endl;
  cout << "Mean of ddot values = "  << mean_ddot<< endl;

  for(int i=0; i<labels.size(); i++)
  {
    int lab;
    if(labels[i].compare("left"))
      lab = 0;
    else if(labels[i].compare("keep"))
      lab = 1;
    else if(labels[i].compare("right"))
      lab = 2;
    else
      ;

    switch(lab)
    {
    case 0: // left
    {
      mean_left_s;
      mean_left_d;
      mean_left_s_dot;
      mean_left_d_dot;
      }
    
    }

  // double sum = std::accumulate(data.begin()[0], data.end()[1], 0.0);
  // double mean = sum / v.size();

  // std::vector<double> diff(v.size());
  // std::transform(v.begin(), v.end(), diff.begin(),
  //               std::bind2nd(std::minus<double>(), mean));
  // double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
  // double stdev = std::sqrt(sq_sum / v.size())
  

  
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
