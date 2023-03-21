#ifndef TINYDL_TENSOR_H
#define TINYDL_TENSOR_H

#include <memory>
#include <iostream>
#include <vector>
#include "CuMatrix.h"

using std::vector;

class Tensor
{
private:
    bool constant;
    shared_ptr<CuMatrix> value;
    shared_ptr<CuMatrix> gradient;
    
public:
    Tensor(double value);
    Tensor(int row,int col,bool cuda=false);
    explicit Tensor(const vector<vector<double>>& v,bool cuda=false);
    explicit Tensor(const CuMatrix& value);
    Tensor(const Tensor& t) = default;
    Tensor(Tensor&& t) = default;
    Tensor& operator=(const Tensor& t) =default;
    Tensor& operator=(const Tensor&& t) = default;
    ~Tensor()=default;
    double operator()(int row,int col) const;
    void cpu();
    void cuda();
    bool isCuda() const;
    void info() const;
    void backward();
    void clearGradient();
    void freeOperator();
	void setZero();
	void setOnes();
	void setIdentity();
	void setRandom();
	bool isConstant() const;
    int row() const;
	int col() const;
	Tensor copy() const;
    CuMatrix& operator*() const;
	CuMatrix& grad();
	Tensor operator+(const Tensor& t) const;
	Tensor& operator+=(const Tensor& t);
	Tensor& operator++();
	const Tensor operator++(int);
	Tensor operator-(const Tensor& t) const;
	Tensor& operator-=(const Tensor& t);
	Tensor& operator--();
	const Tensor operator--(int);
	Tensor operator*(const Tensor& t) const;
	Tensor& operator*=(const Tensor& t);
	Tensor operator/(const Tensor& t) const;
	Tensor& operator/=(const Tensor& t);
	Tensor log(double t=std::exp(1.0)) const;
	Tensor pow(double t) const;
	Tensor exp() const;
	Tensor resize(int rowNum, int colNum, bool isNew=false) const;
	Tensor transpose(bool isNew=false) const;
	Tensor dot(const Tensor& t) const;

private:
    void _backward();

};




#endif //TINYDL_TENSOR_H