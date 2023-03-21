#ifndef TINYDL_POWOPERATOR_H
#define TINYDL_POWOPERATOR_H

#include "operator/Operator.h"

class PowOperator : public Operator {
public:
	PowOperator(const Tensor& tensor1, const Tensor& tensor2);
	Tensor operator()() override;
	void backward(Tensor& result) override;
};
