#include "operator/AddOperator.h"
#include "CuMatrix.h"
AddOperator::AddOperator(const Tensor &tensor1, const Tensor &tensor2) : Operator(tensor1, tensor2) {

}

Tensor AddOperator::operator()() {
   shared_ptr<CuMatrix> value = nullptr;
   if (tensor1.isConstant()){
     CuMatrix m(tensor2.row(),tensor2.col(), tensor2.isCuda());
     m.setOnes();
   }

}