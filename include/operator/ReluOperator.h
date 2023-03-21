#ifndef TINYDL_RELUOPERATOR_H
#define TINYDL_RELUOPERATOR_H

#include "operator/Operator.h"

class ReluOperator:public Operator{
    public:
        explicit ReluOperator(const Tensor& tensor1);
        Tensor operator()() override;
        void backward(Tensor& result) override;
};



#endif