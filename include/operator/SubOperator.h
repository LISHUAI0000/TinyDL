#ifndef TINYDL_SUBOPERATOR_H
#define TINYDL_SUBOPERATOR_H

#include "operator/Operator.h"

class SubOperator:public Operator{
public:
   SubOperator(const Tensor& tensor1,const Tensor& tensor2);
   Tensor operator()() override;
   void backward(Tensor& result) override;
};


#endif