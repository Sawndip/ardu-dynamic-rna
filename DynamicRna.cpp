#include <stdio.h>
#include "math.h"

#include "DynamicRna.h"

DynamicRna::DynamicRna(int n_layers, int n_inputs, int n_outputs)
{
    _n_layers = n_layers;
    _layers = new Layer[n_layers];
    last_layer_added = 0;
    _n_inputs = n_inputs;
    _n_outputs = n_outputs;
}

DynamicRna::~DynamicRna()
{
    //dtor
}

void DynamicRna::addLayer(int n_neurons, int func, double** weights)
{
    _layers[last_layer_added].setNNeurons(n_neurons);
    _layers[last_layer_added].setFunc(func);
    _layers[last_layer_added].setWeights(weights);

    initializeLayer(_layers[last_layer_added]);

    last_layer_added++;
}

void DynamicRna::initializeLayer(Layer layer)
{
    int i;
    for(i = 0; i < layer.getNNeurons(); i++)
    {
        (&layer.getNeurons()[i])->setSignal(0);
        (&layer.getNeurons()[i])->setSum(0);
    }
}

void DynamicRna::addLayer(int n_neurons)
{
    _layers[last_layer_added].setNNeurons(n_neurons);
    last_layer_added++;
}

double* DynamicRna::getOutputs()
{
    double* ret = new double[_n_outputs];

    int i;
    for(i = 0; i < _n_outputs; i++)
    {
        ret[i] = _layers[_n_layers-1].getNeurons()[i].getSignal();
    }

    return ret;
}

void DynamicRna::addOutputLayer()
{
    addLayer(_n_outputs);
}

void DynamicRna::feedFoward(double* inputs)
{
    /** put the inputs values in the first layer **/
    (&_layers[0].getNeurons()[0])->setSignal(inputs[0]);
    (&_layers[0].getNeurons()[1])->setSignal(inputs[1]);

    int n;
    for(n = 1; n < _n_layers; n++)
    {
        Layer* layer = &_layers[n];
        int i;

        for(i = 0; i < layer->getNNeurons(); i++)
        {
            (&layer->getNeurons()[i])->setSum(layer->getWeights()[0][i] * VAL_BIAS);
            int k;
            for(k = 1; k < _layers[n-1].getNNeurons()  + 1; k++)
            {
                double sum = layer->getNeurons()[i].getSum();
                double weight = layer->getWeights()[k][i];
                sum += weight * _layers[n-1].getNeurons()[k-1].getSignal();
                (&layer->getNeurons()[i])->setSum(sum);
            }

            double signal = 0;
            switch(layer->getFunc())
            {
                case FUNC_LOG_SIG:
                    signal = _log_sig(layer->getNeurons()[i].getSum());
                    break;

                case FUNC_PURELIN:
                    signal = _purelin(layer->getNeurons()[i].getSum());
                    break;

                case FUNC_TAN_SIG:
                    signal = _tan_sig(layer->getNeurons()[i].getSum());
                    break;
            }

            Neuron* neuron = &(layer->getNeurons()[i]);
            neuron->setSignal(signal);
        }
    }

}

double DynamicRna::_tan_sig(double x)
{
    return (2 / (1 + exp(-2 * x)) - 1);
}

double DynamicRna::_purelin(double x)
{
    return x;
}

double DynamicRna::_log_sig(double x)
{
    return (1 / (1 + exp(-x)));
}



