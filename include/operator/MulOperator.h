
#ifndef TINYDL_MULOPERATOR_H
#define TINYDL_MULOPERATOR_H

#include "operator/Operator.h"

class MulOperator : public Operator {
public:
	MulOperator(const Tensor& tensor1, const Tensor& tensor2);
	Tensor operator()() override;
	void backward(Tensor& result) override;
};


#endif //TINYDL_MULOPERATOR_H