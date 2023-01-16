#include <Eigen/Eigen>
#include <iostream>
#include <vector>

typedef float Scalar;
typedef Eigen::MatrixXf Matrix;
typedef Eigen::RowVectorXf RowVector;
typedef Eigen::VectorXf ColVector;

class NeuralNetwork {

public:

    //Constructor
    NeuralNetwork(std::vector<uint> topology, Scalar learningRate = Scalar(0.005));

    //Function for forward propagation of data
    void propagateForward(RowVector& input);

    //Function for backward propagation of errors made by neurons
    void propagateBackward(RowVector& output);

    //Function to calculate errors made by neurons in each layer
    void calcErrors(RowVector& output);

    //Function to update the weights of the connections
    void updateWeights();

    //Function to train the neural network given an array of data points
    void train(std::vector<RowVector*> data);

    //Storage objects
    /*
        Use pointers when using std::vector<Class> because std::vector<Class> calls 
        Destructor of Class as soon as it is pushed back. Using pointers avoids this
        issue and also makes the class more lightweight.
    */
   std::vector<RowVector*> neuronLayers; //Stores layers of the network
   std::vector<RowVector*> cacheLayers; //Stores the unactivated (activation fn not yet applied) values of layers
   std::vector<RowVector*> deltas; //Stores the error contribution of each neuron
   std::vector<Matrix*> weights; //Stores the connection weights between neurons
   Scalar learningRate;

}
