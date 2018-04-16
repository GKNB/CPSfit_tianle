#ifndef _GEVP_TIANLE_H
#define _GEVP_TIANLE_H

#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <complex>
#include <cmath>

#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

#include "GEVP_config.h"

//needed when we compare two complex number by their real part
template<typename T=double>
struct CompareComplexNumber
{
  static bool myCompare(std::complex<T> a, std::complex<T> b)
  {
    if(a.real() == b.real())
      return a.imag() < b.imag();
    else
      return a.real() < b.real();
  }
};

//T is the type of data, it can be double,float,int,complex?
//tt(short for t_type) is the type of time-slices, usually it should be int on lattice, but we can use some other type in other use, tstep is usually 1 in int cases
//Nop is number of operator, like 2 in pipiI=0 and sigma
template<size_t Nop, typename T=double, typename tt=int, tt tstep=1>	
class GeneralizedEigenValueSolver
{
  typedef std::pair<tt,tt> tpType;      //time_pair_type, with order (t0,t), reason for using (t0,t) pair is that map sort data by key(pair), and when we calculate E we want to first fix t0 and take large t limit
  std::map<tt,Eigen::Matrix<T,Nop,Nop> > data;      //data stores data for fitting, in an order of time, matrix of correlation function
  std::map<tt,Eigen::Matrix<T,Nop,Nop> > data_sub;	//data_sub stores data[t+1]-data[t] to eliminate round world effect and vacuum subtraction
  std::map<tpType,std::array<std::complex<double>,Nop> > eigenvalue;    //eigenvalue stores results of GEVP, value_type is array of complex eigenvalue, in an increasing order of real part
  std::map<tpType,std::array<std::complex<double>,Nop> > energy;    	//energy stores effective energy calculated from eigenvalue from equ(2.4), or by 3pt method assuming a const term, or can be modified to include the effect of finite Lt
  const tt tmin;  //tmin and tmax are NOT tmin and tmax for input data
  const tt tmax;  //they are set for calculating energy when we take large t limit, so they should be within the range of input
  const bool do_sub;

//this section describe how to get data and input data
public:
  const T getData(tt t, size_t i, size_t j) const
  {
    assert(i<Nop && j<Nop && "Error: index out of range when calling value\n");
    auto it = data.find(t);
    if(it != data.end())
      return it->second(i,j);
    else
    {
      std::cout<<"Possible error: can't find data for time slice" << t << '\n';
      return static_cast<T>(0);
    }
  }

  const T getSubData(tt t, size_t i, size_t j) const
  {
    assert(i<Nop && j<Nop && "Error: index out of range when calling value\n");
    auto it = data_sub.find(t);
    if(it != data_sub.end())
      return it->second(i,j);
    else
    {
      std::cout<<"Possible error: can't find subtracted data for time slice" << t << '\n';
      return static_cast<T>(0);
    }
  }

  const Eigen::Matrix<T,Nop,Nop> getMatrixData(tt t) const
  {
    auto it = data.find(t);
    if(it != data.end())
      return it->second;
    else
      std::cout<<"Possible error: can't find data for time slice" << t << '\n';
  }

  const Eigen::Matrix<T,Nop,Nop> getSubMatrixData(tt t) const
  {
    auto it = data_sub.find(t);
    if(it != data_sub.end())
      return it->second;
    else
      std::cout<<"Possible error: can't find subtracted data for time slice" << t << '\n';
  }

  void setData(tt t, size_t i, size_t j, T x)
  {
    assert(i<Nop && j<Nop && "Error: index out of range when calling value\n");
    data[t](i,j)=x;
  }

  void setData(tt t, const Eigen::Matrix<T,Nop,Nop> &mat) {  data[t] = mat; }

  void generateSubData()
  {
    assert(!data.empty() && "Error: to get subtracted operator matrix, first need to initialize origin data!\n");
    data_sub.clear();
    auto it1 = data.cbegin();
    auto it2 = it1;
    it2++;
    while(it2!=data.cend())
    {
      assert((it1->first + tstep == it2->first) && "Error: either data missing for some time slices or incorrect compare relation for datatype tt in map\n");	//check if the map really sort data according to time
      tt t = it1->first;
      data_sub[t] = it1->second - it2->second;
      it1++; it2++;
    }
  }

//This section gives method for GEVP on single reduced ensemble
//before using these functions, make sure all data has been stored in data!
//Note the order is t and then t0, which is consistent with left to right hand side of GEVP equation
  void CalcEigenValue(tt t, tt t0)
  {
    assert(t>t0 && "Error: t has to be bigger than to when doing GEVP\n");
    tpType ev_key(t0,t);
    if(eigenvalue.find(ev_key) == eigenvalue.end())
    {
      Eigen::GeneralizedEigenSolver<Eigen::Matrix<T,Nop,Nop> > ges;
      if(this->do_sub)
      {
        assert(data_sub.find(t)!=data_sub.end() && "Error: Doing GEVP with subtracted data missing!\n");  
        assert(data_sub.find(t0)!=data_sub.end() && "Error: Doing GEVP with subtracted data missing!\n");
        ges.compute(data_sub[t], data_sub[t0]);
      }
      else
      {
        assert(data.find(t)!=data.end() && "Error: Doing GEVP with data missing!\n");  
        assert(data.find(t0)!=data.end() && "Error: Doing GEVP with data missing!\n");
        ges.compute(data[t], data[t0]);
      }
      std::array<std::complex<double>,Nop> ev_result;
      for(size_t i=0; i<Nop; i++)
        ev_result[i] = ges.alphas()(i)/ges.betas()(i);
#ifdef EIGENVALUE_SORTING
      std::sort(ev_result.begin(), ev_result.end(), CompareComplexNumber<double>::myCompare);
#endif
      eigenvalue[ev_key] = ev_result;
    }
#ifdef OUTPUT_EIGENVALUE_DIRECTLY
    std::cout << "GeneralizedEigenValues for t = "<< t << " and t0 = " << t0 << " are ";
    for(size_t i=0; i<Nop; i++)
      std::cout<< eigenvalue[ev_key][i] << "  ";
    std::cout << std::endl;
#endif
  }
  
//this section gives method for calculating energy from result of GEVP
//we temperaily assume time slice of data is continuous, of course we can use a iteraor go through data, and calculate 
//energy on these tp
  void CalcEffEnergyFixedt0(tt t0)
  {
    tt _tmax = ( this->do_sub ? tmax-tstep : tmax);
    assert(t0 >= tmin && t0 < _tmax);
    for(tt t=t0+tstep; t<=_tmax; t+=tstep)
      CalcEigenValue(t,t0);
    for(tt t=t0+tstep; t<_tmax; t+=tstep)
    {
      if(energy.find(std::pair<tt,tt>(t0,t)) == energy.end())
      {
        std::array<std::complex<double>,Nop> eff_energy_tmp;
        for(size_t i=0; i<Nop; i++)
          eff_energy_tmp[i] = std::log(eigenvalue[std::pair<tt,tt>(t0,t)][i]) - std::log(eigenvalue[std::pair<tt,tt>(t0,t+tstep)][i]);
        energy[std::pair<tt,tt>(t0,t)] = eff_energy_tmp;
      }
    }
#ifdef OUTPUT_EIGENVALUE_DIRECTLY
    std::cout << "Successfully finish CalcEffEnergyFixedt0 function AT t0 = " << t0 << '\n';
#endif
  }

  void OutputEffEnergyFixedt0(tt t0)
  {
    tt _tmax = ( this->do_sub ? tmax-tstep : tmax);
    assert(t0 >= tmin && t0 < _tmax);
    for(size_t i=0; i<Nop; i++)
      for(tt t=t0+tstep; t<_tmax; t+=tstep)
        std::cout << "The " << i << "-thStateAt t0= " << t0 << " and t= " << t << " hasEffEnergy " << energy.at(std::pair<tt,tt>(t0,t))[i] << '\n';
  }

  const std::array<std::complex<double>,Nop> getEnergy(tt t, tt t0) const
  {
    return energy.at(std::pair<tt,tt>(t0,t));
  }
public:  
  GeneralizedEigenValueSolver(tt _tmin, tt _tmax, bool _do_sub): tmin(_tmin),tmax(_tmax),do_sub(_do_sub){}
};

#endif
