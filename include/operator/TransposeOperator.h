#ifndef TINYDL_TRANSPOSEOPERATOR_H
#define TINYDL_TRANSPOSEOPERATOR_H


#include "operator/Operator.h"

class TransposeOperator:public Operator{
   TransposeOperator(const Tensor& tensor1, bool isNew);
   Tensor operator()() override;
   	void backward(Tensor& result) override;
private:
	bool isNew;
};

#endif