#ifndef LVM_FIT_H
#define LVM_FIT_H
#include<Eigen/Dense>
#include "fit_candidate_func.h"
#include<assert.h>
#include<tuple>
#include<vector>
#include <stdlib.h>
#include <cmath>
using std::cout;
using namespace Eigen;

//that's the uncorrelated chisq, tuple stores (y_avg,y_err,x), vector.size is the number of data points we use (usually small than Lt)
template<class func_type>
double chisq(std::vector<std::tuple<double,double,int> > input, func_type func)
{    
  double temp=0;
  for(int t=0; t<input.size(); t++)
  {
    double y_avg = std::get<0>(input[t]);
    int	     x 	 = std::get<2>(input[t]);
    double y_err = std::get<1>(input[t]);
    temp += pow( ( (y_avg - func.value(x)) / y_err), 2.0);
  }
  return temp;
}

//that's the correlated chisq, pair stores (y_avg,x), cov_inv is the INVERSE of blocked cov_mat
template<class func_type>
double chisq(std::vector<std::pair<double,int> > input, MatrixXd cov_inv, func_type func, bool chisq_distributed=false)
{
  //assert cov_inv is square matrix and dimension matches dimension of input
  assert(cov_inv.cols()==cov_inv.rows());
  assert(input.size()==cov_inv.cols());
  double temp=0;
  for(int i=0; i<input.size(); i++)
  {
    double yi_avg = input[i].first;
    double xi     = input[i].second;
    for(int j=0; j<input.size(); j++)
    {
      double yj_avg = input[j].first;
      double xj     = input[j].second;
      double add_term = (yi_avg - func.value(xi) ) * cov_inv(i,j) * (yj_avg - func.value(xj) );
      if(chisq_distributed)
	cout<<"Now we are output how chisq distributed along different matrix element with index i = "<<i<<" j = "<<j<<" and chisq on this index is "<<add_term<<'\n';
      temp += add_term;
    }
  }
  return temp;
}


template<class func_type>
void lvm_fit(std::vector<std::tuple<double,double,int> > input, std::array<double,func_type::N_para> para_init, std::array<double,func_type::N_para> &para_fin, double &chisq_fin, bool DeBug=false)
{
  int err_num=99999;
  func_type func;
  func.set_para(para_init);
  if(DeBug)
  {
    for(int i=0; i<func_type::N_para; i++)
      cout<<"init para "<<i<<" equals "<<func.para[i]<<'\n';
  }
  Matrix<double,func_type::N_para,1> beta;
  Matrix<double,func_type::N_para,func_type::N_para> alpha;
  Matrix<double,func_type::N_para,1> delta;
  double lambda=0.01;
  double chisqnew = 1.0;
  double chisqold=chisq<func_type>(input,func);
  int step=0;
  while( chisqnew > 1e-20 || std::isnan(chisqnew) || std::isinf(chisqnew) )
  {
    step+=1;
    if(DeBug)  {  cout<<"step "<<step<<'\n';  }
    for(int i=0; i<func_type::N_para; i++)
    {
      beta(i) = 0;
      for(int t=0; t<input.size(); t++)
      { 
	double x     = std::get<2>( input[t] );
        double y_err = std::get<1>( input[t] );
        double y_avg = std::get<0>( input[t] );
        beta(i) += func.dyda( x )[i] * ( y_avg - func.value( x ) ) / pow( y_err , 2.0);
      }
      if(DeBug)  {  cout<<"beta "<<i<<" = "<<beta[i]<<'\t';}
    }
    if(DeBug)  {  cout<<'\n';}
    for(int i=0; i<func_type::N_para; i++)
    {
      for(int j=0; j<func_type::N_para; j++)
      {
        alpha(i,j)=0;              // can be improved here since alpha is symmetric
        for(int t=0; t<input.size(); t++)
	{
          double x     = std::get<2>( input[t] );
          double y_err = std::get<1>( input[t] );
          double y_avg = std::get<0>( input[t] ); 
          alpha(i,j) += func.dyda( x )[i] * func.dyda( x )[j] / pow( y_err, 2.0);
	}
        if(i==j)
          alpha(i,j) *= (1+lambda);
      }
    }
    if(DeBug)
    {
      std::cout<<"alpha\n";
      std::cout<<alpha<<std::endl;
      cout<<"lambda=\t"<<lambda<<'\n';
    }
    delta=alpha.colPivHouseholderQr().solve(beta);
    if(DeBug)
    {
      for(int i=0; i<func_type::N_para; i++)
        cout<<"delta "<<i<<" = "<<delta(i)<<'\t';
      cout<<'\n';
    }
    for(int i=0; i<func_type::N_para; i++)
      func.para[i]+=delta(i);
    chisqnew=chisq<func_type>(input,func);
    if(chisqnew>chisqold || std::isnan(chisqnew) || std::isinf(chisqnew))
    {
      lambda*=10;
      for(int i=0; i<func_type::N_para; i++)
	func.para[i] -= delta(i);
    }
    else
    {
      lambda/=10;
      if(chisqnew > 0.99999999 * chisqold)
	break;
      chisqold=chisqnew;
    }
    if(DeBug)
    {
      for(int i=0; i<func_type::N_para; i++)
        cout<<"para "<<i<<" = "<<func.para[i]<<'\t';
      cout<<"chisqnew=\t"<<chisqnew<<'\n';
      cout<<"\n\n\n";
    }
    if(step>1500)
    {
      cout<<"LVM algorithm fails because chisq does not converge, stop!!!";
      for(int i=0; i<func_type::N_para; i++)
	func.para[i]=err_num;
      break;
    }
  }
  for(int i=0; i<func_type::N_para; i++)
    para_fin[i]=func.para[i];
  for(int i=0; i<func_type::N_para; i++)
    std::cout<<"para "<<i<<" = "<<para_fin[i]<<'\t';
  if(chisqnew > 3.0 * input.size() - func_type::N_para)
    cout<<"warning! there might be a mistake in fitting: chisq is too big\n";
  std::cout<<"chisqnew=\t"<<chisqnew<<'\n';
  chisq_fin=chisqnew;
  cout<<'\n';
}

template<class func_type>
void lvm_fit(std::vector<std::pair<double,int> > input, MatrixXd cov_inv, std::array<double,func_type::N_para> para_init, std::array<double,func_type::N_para> &para_fin, double &chisq_fin, bool DeBug=false)
{
  int err_num=99999;
  func_type func;
  func.set_para(para_init);
  if(DeBug)
  {
  for(int i=0; i<func_type::N_para; i++)
    cout<<"init para "<<i<<" equals "<<func.para[i]<<'\n';
  }
  Matrix<double,func_type::N_para,1> beta;
  Matrix<double,func_type::N_para,func_type::N_para> alpha;
  Matrix<double,func_type::N_para,1> delta;
  double lambda=0.01;
  double chisqnew=1.0;
  double chisqold=chisq<func_type>(input,cov_inv,func);
  int step=0;
  while(chisqnew > 1e-20 || std::isnan(chisqnew) || std::isinf(chisqnew))
  {
    step+=1;
    if(DeBug)  {  cout<<"step "<<step<<'\n';  }
    for(int i=0; i<func_type::N_para; i++)
    {   
      beta(i)=0;
      for(int t1=0; t1<input.size(); t1++)
        for(int t2=0; t2<input.size(); t2++)
          beta(i)+=func.dyda(input[t1].second)[i]*cov_inv(t1,t2)*(input[t2].first-func.value(input[t2].second));
      if(DeBug)  {  cout<<"beta "<<i<<" = "<<beta[i]<<'\t';}
    }   
    if(DeBug)  {  cout<<'\n';}
    for(int i=0; i<func_type::N_para; i++)
    {   
      for(int j=0; j<func_type::N_para; j++)
      {   
        alpha(i,j)=0;              // can be improved here since alpha is symmetric
        for(int t1=0; t1<input.size(); t1++)
          for(int t2=0; t2<input.size(); t2++)
            alpha(i,j)+= func.dyda(input[t1].second)[i] * cov_inv(t1,t2) * func.dyda(input[t2].second)[j] ;
        if(i==j)
          alpha(i,j)*=(1+lambda);
      }   
    }   
    if(DeBug)
    {   
      std::cout<<"alpha\n";
      std::cout<<alpha<<std::endl;
      cout<<"lambda=\t"<<lambda<<'\n';
    }   
    delta=alpha.colPivHouseholderQr().solve(beta);
    if(DeBug)
    {   
      for(int i=0; i<func_type::N_para; i++)
        cout<<"delta "<<i<<" = "<<delta(i)<<'\t';
      cout<<'\n';
    }   
    for(int i=0; i<func_type::N_para; i++)
      func.para[i]+=delta(i);
    chisqnew=chisq<func_type>(input,cov_inv,func);
    if(chisqnew>chisqold || std::isnan(chisqnew) || std::isinf(chisqnew))
    {
      lambda*=10;
      for(int i=0; i<func_type::N_para; i++)
	func.para[i] -= delta(i);
    }
    else
    {
      lambda/=10;
      if((chisqold - chisqnew) < 0.0000001)
	break;
      chisqold=chisqnew;
    }
    if(DeBug)
    {   
      for(int i=0; i<func_type::N_para; i++)
        cout<<"para "<<i<<" = "<<func.para[i]<<'\t';
      cout<<"chisqnew=\t"<<chisqnew<<'\n';
      cout<<"\n\n\n";
    }   
    if(step>1500)
    {   
      cout<<"LVM algorithm fails because chisq does not converge, stop!!!";
      for(int i=0; i<func_type::N_para; i++)
	func.para[i]=err_num;
      break;
    }   
  }
  for(int i=0; i<func_type::N_para; i++)
    para_fin[i]=func.para[i];
  for(int i=0; i<func_type::N_para; i++)
    std::cout<<"para "<<i<<" = "<<para_fin[i]<<'\t';
  if(chisqnew > 3.0 * input.size() - func_type::N_para)
    cout<<"warning! there might be a mistake in fitting: chisq is too big\n";
  chisqnew = chisq<func_type>(input,cov_inv,func,false);
  std::cout<<"chisqnew=\t"<<chisqnew<<'\n';
  chisq_fin=chisqnew;
  cout<<'\n';
}




//that's an old version of chisq and lvm_fit, which is designed for particular data whose x-component is from 1 to N
template<class func_type, int N>
double chisq(std::array<std::pair<double,double>,N> input, func_type func)
{    
  double temp=0;
  for(int t=0; t<N; t++) 
    temp+=pow((input[t].first-func.value(t))/input[t].second,2.0);
  return temp;
}

//template<class func_type, int N>
//void lvm_fit(std::array<std::pair<double,double>,N> input, std::array<double,func_type::N_para> para_init, std::array<double,func_type::N_para> &para_fin, double &chisq_fin=0.0)
//{
//  func_type func;
//  func.set_para(para_init);
//  for(int i=0; i<func_type::N_para; i++)
//    cout<<"init para "<<i<<" equals "<<func.para[i]<<'\n';
//  std::array<double,func_type::N_para> beta={0};
//  Matrix<double,func_type::N_para> alpha;
//  alpha.Zero();
//  std::array<double,func_type::N_para> delta={0};
//  double lambda=1;
//  double chisqold=0.0;
//  double chisqnew=chisq<func_type,N>(input,func);
//  int step=0;
//  while(chisqnew < 0.999999999999*chisqold || chisqnew > chisqold)
//  {
//    step+=1;
//    cout<<"step "<<step<<'\n';
//    if(chisqnew>chisqold)
//      lambda*=10;
//    else
//      lambda/=10;
//    chisqold=chisqnew;
//    for(int i=0; i<func_type::N_para; i++)
//    {
//      beta[i]=0;
//      for(int t=0; t<N; t++)
//        beta[i]+=func.dyda(t)[i]*(input[t].first-func.value(t))/(input[t].second*input[t].second);
//      cout<<"beta "<<i<<" = "<<beta[i]<<'\t';
//    }
//    cout<<'\n';
//    for(int i=0; i<func.para.size(); i++)
//    {
//      for(int j=0; j<func.para.size(); j++)
//      {
//        alpha[i][j]=0;              // can be improved here since alpha is symmetric
//        for(int t=0; t<N; t++)
//          alpha[i][j]+=func.dyda(t)[i]*func.dyda(t)[j]/(input[t].second*input[t].second);
//        if(i==j)
//          alpha[i][j]*=(1+lambda);
//      }
//    }
//    alpha.Print("alpha");
//    alpha.Inverse().Print("alpha_Inv");
//    delta=alpha.Inverse()*beta;
//    cout<<"lambda=\t"<<lambda<<'\n';
//    for(int i=0; i<func_type::N_para; i++)
//      cout<<"delta "<<i<<" = "<<delta[i]<<'\t';
//    cout<<'\n';
//    for(int i=0; i<func_type::N_para; i++)
//      func.para[i]+=delta[i];
//    chisqnew=chisq<func_type,N>(input,func);
//    for(int i=0; i<func_type::N_para; i++)
//      cout<<"para "<<i<<" = "<<func.para[i]<<'\t';
//    cout<<"chisqnew=\t"<<chisqnew<<'\n';
//    cout<<"\n\n\n";
//    if(step>400)
//    {
//      cout<<"LVM algorithm fails because chisq does not converge, stop!!!";
//      assert(0);
//    }
//  }
//  for(int i=0; i<func_type::N_para; i++)
//    para_fin[i]=func.para[i];
//  chisq_fin=chisqnew;
//  cout<<'\n';
//}
#endif
