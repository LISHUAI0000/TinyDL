#ifndef TINYDL_LOGOPERATOR_H
#define TINYDL_LOGOPERATOR_H

#include "operator/Operator.h"

class LogOperator : public Operator {
public:
    LogOperator(const Tensor& tensor1,const Tensor& tensor2);
    Tensor operator()() override;
    void backward(Tensor& result) override;
};

#endif