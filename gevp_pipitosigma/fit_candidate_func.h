#ifndef _FIT_CANDIDATE_FUNC_H
#define _FIT_CANDIDATE_FUNC_H
#include<iostream>
#include<math.h>
#include<array>

class linear	//a0*t+a1
{
  public:
    const static int N_para=2;

    std::array<double,2> para;

    linear()
    {
      for(int i=0; i<2; i++)
	para[i]=0;
    }

    void set_para(std::array<double,2> input)
    {
      for(int i=0; i<2; i++)
	para[i]=input[i];
    }

    double value(int tsep)
    {
      return para[0]*tsep+para[1];
    }

    std::array<double,2> dyda(int tsep)
    {
      std::array<double,2> deriv;
      deriv[0]=tsep;
      deriv[1]=1;
      return deriv;
    }
};

template<int Lt>
class eff_mass_2pt	//(exp(-a1*t)+exp(-a1*(Lt-t)))/(exp(-a1*(t+1))+exp(-a1*(Lt-t-1)))
{
  public:
    const static int N_para=1;

    std::array<double,1> para;

    eff_mass_2pt()
    {
      para[0]=0.0;
    }

    void set_para(std::array<double,1> input)
    {
      para[0]=input[0];
    }

    double value(int t)
    {
      t=double(t);
      return cosh( para[0] * (Lt / 2.0 - t) ) / cosh ( para[0] * (Lt / 2.0 - 1.0 - t) );
    }

    std::array<double,1> dyda(int t)
    {
      std::array<double,1> tmp;
      double temp = pow( cosh ( para[0] * (Lt / 2.0 - 1.0 - t) ), 2.0 );
      tmp[0] = ( (Lt / 2.0 - t) * sinh( para[0] * (Lt / 2.0 - t) ) * cosh( para[0] * (Lt / 2.0 - 1.0 - t) ) - cosh( para[0] * (Lt / 2.0 - t) ) * (Lt / 2.0 - 1.0 - t) * sinh ( para[0] * (Lt / 2.0 - 1.0 - t) ) ) / temp;
      return tmp;
    }
};

template<int Lt>
class single_cosh   //a0*(exp(-a1*t)+exp(-a1*(Lt-t)))
{
  public:
    const static int N_para=2;

    std::array<double, 2> para;

    single_cosh()
    {
      for(int i=0; i<2; i++)
	para[i]=0;
    }

    void set_para(std::array<double,2> input)
    {
      for(int i=0; i<2; i++)
	para[i]=input[i]; 
    }

    double value(int t)
    {
      return para[0]*(exp(-1.0*para[1]*double(t))+exp(-1.0*para[1]*(double(Lt)-double(t))));
    }
    
    std::array<double,2> dyda(int t)
    {
      std::array<double,2> deriv;
      deriv[0]=exp(-1.0*para[1]*double(t))+exp(-1.0*para[1]*(double(Lt)-double(t)));
      deriv[1]=para[0]*(-1.0*double(t)*exp(-1.0*para[1]*double(t))-(double(Lt)-double(t))*exp(-1.0*para[1]*(double(Lt)-double(t))));
      return deriv;
    }
};

template<int Lt>
class single_cosh_const   //a0*(exp(-a1*t)+exp(-a1*(Lt-t)))+a2
{
  public:
    const static int N_para=3;

    std::array<double, 3> para;

    single_cosh_const()
    {
      for(int i=0; i<3; i++)
        para[i]=0.0;
    }

    void set_para(std::array<double,3> input)
    {
      for(int i=0; i<3; i++)
        para[i]=input[i];
    }

    double value(int t)
    {
      return para[0]*(exp(-1.0*para[1]*double(t))+exp(-1.0*para[1]*(double(Lt)-double(t))))+para[2];
    }

    std::array<double,3> dyda(int t)
    {
      std::array<double,3> deriv;
      deriv[0]=exp(-1.0*para[1]*double(t))+exp(-1.0*para[1]*(double(Lt)-double(t)));
      deriv[1]=para[0]*(-1.0*double(t)*exp(-1.0*para[1]*double(t))-(double(Lt)-double(t))*exp(-1.0*para[1]*(double(Lt)-double(t))));
      deriv[2]=1.0;
      return deriv;
    }
};

template<int Lt>
class asym_single_cosh_const	//a0*exp(-a1*t)+a2*exp(-a1*(Lt-t))+a3
{
  public:
    const static int N_para = 4;

    std::array<double, 4> para;

    asym_single_cosh_const()
    {
      for(int i=0; i<4; i++)
	para[i] = 0.0;
    }

    void set_para(std::array<double,4> input)
    {
      for(int i=0; i<4; i++)
	para[i] = input[i];
    }

    double value(int t)
    {
      return para[0] * exp(-1.0 * para[1] * double(t)) + para[2] * exp(-1.0 * para[1] * (double(Lt) - double(t))) + para[3];
    }

    std::array<double,4> dyda(int t)
    {
      std::array<double,4> deriv;
      deriv[0] = exp(-1.0 * para[1] * double(t));
      deriv[1] = para[0] * (-1.0 * double(t)) * exp(-1.0 * para[1] * double(t)) + para[2] * (double(t) - double(Lt)) * exp(para[1] * (double(t) - double(Lt)));
      deriv[2] = exp(-1.0 * para[1] * (double(Lt) - double(t)));
      deriv[3] = 1.0;
      return deriv;
    }
};

template<int Lt>
class double_cosh_one_fixed_mass_const
{
  public:
    const static int N_para = 4;

    constexpr static double mass = 0.39846;
    std::array<double, 4> para;

    double_cosh_one_fixed_mass_const()
    {
      for(int i=0; i<4; i++)
	para[i] = 0.0;
    }

    void set_para(std::array<double,4> input)
    {
      for(int i=0; i<4; i++)
	para[i] = input[i];
    }

    double value(int t)
    {
      return para[0] * (exp(-1.0 * para[1] * double(t)) + exp(para[1] * double(t-Lt))) + para[2] * (exp(-1.0 * mass * double(t)) + exp(mass * double(t-Lt))) + para[3];
    }

    std::array<double,4> dyda(int t)
    {
      std::array<double,4> deriv;
      deriv[0] = exp(-1.0 * para[1] * double(t)) + exp(para[1] * double(t-Lt));
      deriv[1] = para[0] * (-1.0 * double(t) * exp(-1.0 * para[1] * double(t)) - double(Lt-t) * exp(-1.0 * para[1] * (double(Lt-t))));
      deriv[2] = exp(-1.0 * mass * double(t)) + exp(mass * double(t-Lt));
      deriv[3] = 1.0;
      return deriv;
    }
};

template<int Lt>
class double_cosh_const
{
  public:
    const static int N_para = 5;

    std::array<double, 5> para;

    double_cosh_const()
    {   
      for(int i=0; i<5; i++)
        para[i] = 0.0;
    }   

    void set_para(std::array<double,5> input)
    {
      for(int i=0; i<5; i++)
        para[i] = input[i];
    }

    double value(int t)
    {
      return para[0] * (exp(-1.0 * para[1] * double(t)) + exp(para[1] * double(t-Lt))) + para[2] * (exp(-1.0 * para[3] * double(t)) + exp(para[3] * double(t-Lt))) + para[4];
    }

    std::array<double,5> dyda(int t)
    {
      std::array<double,5> deriv;
      deriv[0] = exp(-1.0 * para[1] * double(t)) + exp(para[1] * double(t-Lt));
      deriv[1] = para[0] * (-1.0 * double(t) * exp(-1.0 * para[1] * double(t)) - double(Lt-t) * exp(-1.0 * para[1] * (double(Lt-t))));
      deriv[2] = exp(-1.0 * para[3] * double(t)) + exp(para[3] * double(t-Lt));
      deriv[3] = para[2] * (-1.0 * double(t) * exp(-1.0 * para[3] * double(t)) - double(Lt-t) * exp(-1.0 * para[3] * (double(Lt-t))));
      deriv[4] = 1.0;
      return deriv;
    }

};
#endif
