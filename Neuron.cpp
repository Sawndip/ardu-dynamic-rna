#include "Neuron.h"

Neuron::Neuron()
{
    setSignal(0);
    setSum(0);
}

Neuron::~Neuron()
{
    //dtor
}

void Neuron::setSignal(double __signal)
{
    _signal = __signal;
}

void Neuron::setSum(double sum)
{
    _sum = sum;
}

double Neuron::getSignal()
{
    return _signal;
}

double Neuron::getSum()
{
    return _sum;
}

