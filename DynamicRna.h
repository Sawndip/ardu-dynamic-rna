#ifndef DYNAMICRNA_H
#define DYNAMICRNA_H

#include "Arduino.h"
#include "Layer.h"

#define VAL_BIAS       1

#define FUNC_TAN_SIG   0
#define FUNC_LOG_SIG   1
#define FUNC_PURELIN   2


class DynamicRna
{
    public:
        DynamicRna(int n_layers, int n_inputs, int n_outputs);
        virtual ~DynamicRna();
        void addLayer(int n_neurons, int func, double** weights);
        void addLayer(int n_neurons);
        void addOutputLayer();
        void feedFoward(double* inputs);
        double* getOutputs();
        void initializeLayer(Layer layer);

    protected:

    private:

        const int _val_bias = 1;
        int last_layer_added;
        int _n_layers;
        int _n_inputs;
        int _n_outputs;
        Layer* _layers;

        double _log_sig(double x);
        double _purelin(double x);
        double _tan_sig(double x);
};

#endif // DYNAMICRNA_H
