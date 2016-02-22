#include "Layer.h"

Layer::Layer()
{

}

Layer::Layer(int n_neurons)
{
    setNNeurons(n_neurons);
}

Layer::~Layer()
{

}

int Layer::getNNeurons()
{
    return _n_neurons;
}

void Layer::setNNeurons(int n_neurons)
{
    _n_neurons = n_neurons;
    _neurons = (Neuron*)malloc(sizeof(Neuron) * _n_neurons);
}


void Layer::setFunc(int func)
{
    _func = func;
}

void Layer::setWeights(double** weights)
{
    _weights = weights;
}

double** Layer::getWeights()
{
    return _weights;
}

Neuron* Layer::getNeurons()
{
    return _neurons;
}

int Layer::getFunc()
{
    return _func;
}




