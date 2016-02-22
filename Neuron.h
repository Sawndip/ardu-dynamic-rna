#ifndef NEURON_H
#define NEURON_H


class Neuron
{
    public:
        Neuron();
        virtual ~Neuron();
        double getSum();
        double getSignal();
        void setSum(double sum);
        void setSignal(double signal);

    protected:

    private:
        double _sum;
        double _signal;
};

#endif // NEURON_H
