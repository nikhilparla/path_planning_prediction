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
