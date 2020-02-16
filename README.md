## Path Planning Prediction

#### Two approaches to ppredictions
 - Data driven approach
 - Model based approach

##### Data Driven approach
 - Offline Training
	- Define Similarity
	- Unsupervised Clustering
	- Define Prototype Trajectories
 - Online Prediction
	- Observe Partial Trajectory
	- Compare to prototype trajectories
	- Generate Predictions

##### Model based approach
 - Define process model
 - Using process model
 - Probabilistic classification
 - Extrapolating to genetate trajectories

##### Cmake configuration
 - Added CMakeLists.txt file to the folder for build
 - Takes classifier.cpp and main.cpp and buils main.o
 - Added the c++11 flag for compilation
 - Added 'generator expressions' for copying the target as a post build step


## Behavioral Planning

#### Cost Functions
 - Folder with same name has the code for handling the cost functions for distance
 - The cost functions 2 has the code for handling the cost function for speed
 - behavioral_cloning folder has the final project for the topic
