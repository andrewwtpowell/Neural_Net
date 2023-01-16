#include <NeuralNetwork.hpp>

NeuralNetwork::NeuralNetwork(std::vector<uint> topology, Scalar learningRate) {

    //The topology vector details how many neurons are present in each layer
    //Size of the topology vector is equal to the number of layers in the network 
    this->topology = topology;
    this->learningRate = learningRate;

    //Loop through each layer of the network
    for(uint i = 0; i < topology.size(); i++) {

        //Initialize each neuron layer
        //Add an extra bias neuron to each layer except for the output layer (topology.size() - 1)
        if(i == topology.size() - 1)
            neuronLayers.push_back(new RowVector(topology[i]));
        else
            neuronLayers.push_back(new RowVector(topology[i] + 1));

        //Initialize cache and delta vectors
        //The cache vector contains the sum of weighted inputs from the previous layer; no activation function applied
        cacheLayers.push_back(new RowVector(neuronLayers.size()));
        //The deltas vector stores the error contribution of each neuron
        deltas.push_back(new RowVector(neuronLayers.size()));

        //Statement executes for all layers other than output layer
        if(i != topology.size() - 1) {
            
        }
    }
}