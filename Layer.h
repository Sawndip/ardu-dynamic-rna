#ifndef LAYER_H
#define LAYER_H

#include <stdlib.h>
#include "Neuron.h"

class Layer
{
    public:
        Layer();
        Layer(int n_neurons);
        virtual ~Layer();
        int getNNeurons();
        Neuron* getNeurons();
        void setNNeurons(int n_neurons);
        void setFunc(int func);
        int getFunc();
        void setWeights(double** weights);
        double** getWeights();

    protected:

    private:
        int _func;
        int _n_neurons;
        Neuron* _neurons;
        double** _weights;
};

#endif // LAYER_H
