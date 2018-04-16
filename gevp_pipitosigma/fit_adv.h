#ifndef _FIT_ADV_H
#define _FIT_ADV_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<tuple>
#include<vector>
#include<complex>

#include<Eigen/Dense>

#include "three_momentum_simple.h"
#include "GEVP_tianle.h"

using namespace std;
using namespace Eigen;
class fit_adv
{
  private:

    static const int    Lt=64;
    const int    traj_step=4;

    static const int ndir = 4;
//    const std::string pipi_work_dir[ndir] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_EOFA_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM_sep2" };
    const std::string work_dir[ndir] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/KEK_EOFA_STREAM1", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/KEK_EOFA_STREAM2", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_EOFA_STREAM_sigma"};

//this line indicate the factor we use to devide average and error before fitting
    const double avg_fac = 100000000.0;
    const double err_fac = 100000000.0;

//this line can be changed according to our need, but by doing so we need to change other things, careful if you want to change them!!!!!
//other changes if tdis is changed includes but not limited to, sortout data, folding process,
//other changes if tstep is changed includes but not limited to, 
    static const int tdis = 4;
    static const int tstep = 8;

//these are "fake" momentum container of pion and sigma
    const std::string pion_mom[8]       = {"222", "_2_2_2", "_222", "2_2_2", "2_22", "_22_2", "22_2", "_2_22"};
    const std::string pion_mom_chris[8] = {"111", "_1_1_1", "_111", "1_1_1", "1_11", "_11_1", "11_1", "_1_11"};
    const std::string sigma_mom[8]      = {"111", "_1_1_1", "_311", "3_1_1", "1_31", "_13_1", "11_3", "_1_13"};

//this is the newly introduced mom_container which is almost the same as above, but they support most of operation Chris defined in threemomentum. Notice they are different!
//we can get pion_mom[i] by pionmom[i], and we can get underlying basemom by pionmom(i)
    pion_basemom_container pionmom;

//These two are coeff used for rep-proj
    MovingPiPiCase3_sdCoeff policysd;
    MovingPiPiCase3_ddCoeff policydd;

//these section decides what to do and what not to do
  private:
    bool corr=true, corr_sub=true, scat=true, scat_sub=true, corr_sub_check=true, scat_sub_check=true, pipi=true;

//this section collects the original data, and no information is lost here
//the name looks like "origin_xxxx"
  private:
    std::array<std::vector<std::pair<std::array<double,Lt*Lt>,int> >,64>          origin_corr;
    std::array<std::vector<std::pair<std::array<double,Lt   >,int> >,8 >          origin_self;
    std::array<std::vector<std::pair<std::array<double,Lt*Lt>,int> >,64>          origin_scat;              //ppiidx=pidx/8; psigidx=pidx%8

    std::array<std::vector<std::pair<std::array<double,Lt*Lt/tstep>,int> >,64>    origin_pipiC;             //psrc=pidx/8; psnk=pidx%8
    std::array<std::vector<std::pair<std::array<double,Lt*Lt/tstep>,int> >,64>    origin_pipiD;             //psrc=pidx/8; psnk=pidx%8
    std::array<std::vector<std::pair<std::array<double,Lt*Lt/tstep>,int> >,64>    origin_pipiR;             //psrc=pidx/8; psnk=pidx%8
    std::array<std::vector<std::pair<std::array<double,Lt   >,int> >,8 >          origin_pipiV;            

  public:
    
    bool read_origin_data(int traj_min, int traj_max)
    {
      for(int i=0; i<ndir; i++)
      {
        for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
        {
          bool successful_read = false;
          int count_traj = 0;
          for(int pidx=0; pidx<64; pidx++)
          {
    	    int psigsrc = pidx / 8;
  	    int psigsnk = pidx % 8;
	    std::string p_sigma_src = sigma_mom[psigsrc];
	    std::string p_sigma_snk = sigma_mom[psigsnk];
  	    std::ostringstream fs;
  	    fs << work_dir[i] << "/traj_" << traj << "_sigmacorr_mom" << "psrc" << p_sigma_src << "psnk" << p_sigma_snk << "_v2";
	    std::string str_tmp = fs.str();
  	    std::pair<std::array<double,Lt*Lt>,int> tmp;
  	    if(read_single_file(str_tmp,traj,tmp))
            {
              successful_read = true;
  	      origin_corr[pidx].push_back(tmp);
              count_traj++;
            }
  	  }
          for(int pidx=0; pidx<8; pidx++)
          {
	    std::string p_sigma_src = sigma_mom[pidx];
  	    std::ostringstream fs;
   	    fs << work_dir[i] << "/traj_" << traj << "_sigmaself_mom" << p_sigma_src << "_v2"; 
	    std::string str_tmp = fs.str();
    	    std::pair<std::array<double,Lt>,int> tmp;
  	    if(read_single_file(str_tmp,traj,tmp))
            {
              successful_read = true;
  	      origin_self[pidx].push_back(tmp);
              count_traj++;
            }
  	  }
          for(int pidx=0; pidx<64; pidx++)
          {
  	    int ppiidx = pidx / 8;
	    int psigidx = pidx % 8;
	    std::string p_pi_src = pion_mom[ppiidx];
	    std::string p_sigma_snk = sigma_mom[psigidx];
	    std::ostringstream fs;
	    fs << work_dir[i] << "/traj_" << traj << "_pipitosigma_sigmawdagmom" << p_sigma_snk << "_pionmom" << p_pi_src << "_v2";
	    std::string str_tmp = fs.str();
	    std::pair<std::array<double,Lt*Lt>,int> tmp;
	    if(read_single_file(str_tmp,traj,tmp))
            {
              successful_read = true;
	      origin_scat[pidx].push_back(tmp);
              count_traj++;
            }
	  }
	  for(int pidx=0; pidx<64; pidx++)
  	  {
	    int psrc = pidx / 8;
	    int psnk = pidx % 8;
	    std::string p_pi_src = pion_mom_chris[psrc];
	    std::string p_pi_snk = pion_mom_chris[psnk];
	    std::ostringstream fsC;
	    fsC << work_dir[i] << "/traj_" << traj << "_FigureC_sep" << tdis << "_mom" << p_pi_src << "_mom" << p_pi_snk;
	    std::string str_tmp_C = fsC.str();
	    std::pair<std::array<double,Lt*Lt/tstep>,int> tmpC;
	    if(read_single_file(str_tmp_C,traj,tmpC))
            {
              successful_read = true;
	      origin_pipiC[pidx].push_back(tmpC);
              count_traj++;
            }
	    else
	      continue;
	    std::ostringstream fsD;
	    fsD << work_dir[i] << "/traj_" << traj << "_FigureD_sep" << tdis << "_mom" << p_pi_src << "_mom" << p_pi_snk;
  	    std::string str_tmp_D = fsD.str();
  	    std::pair<std::array<double,Lt*Lt/tstep>,int> tmpD;
  	    if(read_single_file(str_tmp_D,traj,tmpD))
            {
              successful_read = true;
  	      origin_pipiD[pidx].push_back(tmpD);
              count_traj++;
            }
  	    std::ostringstream fsR;
  	    fsR << work_dir[i] << "/traj_" << traj << "_FigureR_sep" << tdis << "_mom" << p_pi_src << "_mom" << p_pi_snk;
  	    std::string str_tmp_R = fsR.str();
  	    std::pair<std::array<double,Lt*Lt/tstep>,int> tmpR;
  	    if(read_single_file(str_tmp_R,traj,tmpR))
            {
              successful_read = true;
  	      origin_pipiR[pidx].push_back(tmpR);
              count_traj++;
            }
  	  }
  	  for(int pidx=0; pidx<8; pidx++)
	  {
	    std::string p_pi_src = pion_mom_chris[pidx];
	    std::ostringstream fs;
	    fs << work_dir[i] << "/traj_" << traj << "_FigureVdis_sep" << tdis << "_mom" << p_pi_src;
	    std::string str_tmp = fs.str();
	    std::pair<std::array<double,Lt>,int> tmp;
	    if(read_single_file(str_tmp,traj,tmp))
            {
              successful_read = true;
	      origin_pipiV[pidx].push_back(tmp);
              count_traj++;
            }
	  }
          if (successful_read == true)
          {
            std::cout << "count_traj = " << count_traj << '\v' << std::endl;
            assert(count_traj == 336);
          }
        }
      }
    }

    bool output_origin_data()
    {
      if(this->corr)
      {
	output_data<64,Lt*Lt>("origin_sigmacorr",origin_corr);
	output_data<8,Lt>("origin_sigmaself",origin_self);
      }
      if(this->scat)
	output_data<64,Lt*Lt>("origin_pipisigma",origin_scat);
      if(this->pipi)
      {
	output_data<64,Lt*Lt/tstep>("origin_pipi_FigureC",origin_pipiC);
	output_data<64,Lt*Lt/tstep>("origin_pipi_FigureD",origin_pipiD);
	output_data<64,Lt*Lt/tstep>("origin_pipi_FigureR",origin_pipiR);
	output_data<8,Lt>("origin_pipi_FigureV_seperate",origin_pipiV);
      }
    }

//this section generate tsrc averaging data for later calculation, also we sort out data that are useful for vacuum subtraction
//names look like "tavg_xxxx" and "tsep_x_xxxx", the former one is tavged and latter is for fixed tsep and has an index of tsrc
  private:
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_corr;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_scat;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_pipiC;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_pipiD;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_pipiR;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_pipiV;

  public:

    bool tavg_generate()
    {
      std::cout << "Start tavg_generate\n" << std::endl;
      if(this->corr)  		tavg_generate_prototype<64>(origin_corr,tavg_corr);
      if(this->scat)   		tavg_generate_prototype<64>(origin_scat,tavg_scat);
      if(this->pipi)
      {
	tavg_generate_prototype<64>(origin_pipiC,tavg_pipiC);
	tavg_generate_prototype<64>(origin_pipiD,tavg_pipiD);
	tavg_generate_prototype<64>(origin_pipiR,tavg_pipiR);
      }
      if(this->pipi)
      {
	for(int pidx=0; pidx<64; pidx++)
	{
	  int psrc=pidx/8, psnk=pidx%8;
	  tavg_pipiV[pidx].resize(origin_pipiV[0].size());
	  for(int traj=0; traj<tavg_pipiV[pidx].size(); traj++)
	  {
	    tavg_pipiV[pidx][traj].second=origin_pipiV[0][traj].second;
	    for(int t=0; t<Lt; t++)
	    {
	      tavg_pipiV[pidx][traj].first[t]=0.0;
	      for(int tsrc=0; tsrc<Lt; tsrc++)
	      {
		int p_rev = rev_mom(psnk);
		int tnew = (tsrc+t+tdis)%Lt;
		tavg_pipiV[pidx][traj].first[t]+=origin_pipiV[psrc][traj].first[tsrc] * origin_pipiV[p_rev][traj].first[tnew];
	      }
	      tavg_pipiV[pidx][traj].first[t]/=Lt;
	    }
	  }
	}
      }
      std::cout << "Finish tavg_generate\n" << std::endl;
    }

    bool output_tavg_data()
    {
      if(this->corr)
	output_data<64,Lt>("origin->tavg_sigmacorr",tavg_corr);
      if(this->scat)
	output_data<64,Lt>("origin->tavg_pipisigma",tavg_scat);
      if(this->pipi)
      {
	output_data<64,Lt>("origin->tavg_pipi_FigureC",tavg_pipiC);
	output_data<64,Lt>("origin->tavg_pipi_FigureD",tavg_pipiD);
	output_data<64,Lt>("origin->tavg_pipi_FigureR",tavg_pipiR);
	output_data<64,Lt>("origin->tavg_pipi_FigureV",tavg_pipiV);
      }
    }


//this section generates different angular momentum of tavg or fixed tsep data (and other linear combination of momentum)
//the name looks like "xx_xx_xxxx" or "xx_xxxx" for vacuum term
//s1 stands for swave for cubic symmetry group
//s2 s3 stands for swave for D3d symmetry
//d1 stands for dwave for cubic symmetry
  private:
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_corr;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_corr;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_corr;

    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_scat;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_scat;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_scat;

    std::vector<std::pair<std::array<double,Lt>,int> >   s1_self;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_self;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_self;

    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiI_2;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiI_2;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiI_2;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiI_2;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiI_0;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiI_0;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiI_0;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiI_0;

  public:

    //need further debugging
    bool rep_proj()
    {
      std::cout << "Start rep_proj\n" << std::endl;
      std::array<double,64> s1_s1_coeff;
      std::array<double,64> s2_s2_coeff;
      std::array<double,64> s3_s3_coeff;
      std::array<double,64> d1_d1_coeff;
      s1_s1_coeff.fill(1.0/64.0);
      for(int idx=0; idx<64; idx++)
      {
	s2_s2_coeff[idx] = 0.0;
	s3_s3_coeff[idx] = 0.0;
	int i = idx % 8;
	int j = idx / 8;
	if(i<2 && j<2)
	  s2_s2_coeff[idx] = 1.0/4.0;
	else if(i>=2 && j>=2)
	  s3_s3_coeff[idx] = 1.0/36.0;
      }
      std::array<double,8> s1_coeff_8;
      std::array<double,8> s2_coeff_8;
      std::array<double,8> s3_coeff_8;
      std::array<double,8> d1_coeff_8;
      s1_coeff_8.fill(1.0/8.0);
      for(int idx=0; idx<8; idx++)
      {
	if(idx<2)
	{
	  s2_coeff_8[idx] = 0.5;
	  s3_coeff_8[idx] = 0;
	}
	else
	{
	  s2_coeff_8[idx] = 0;
	  s3_coeff_8[idx] = 1.0/6.0;
	}
      }
      for(int i=0; i<8; i++)
      {
        if(i<2)
        {   
          d1_coeff_8[i]=3.0;
          for(int j=0; j<8; j++)
          {   
            if(j<2)
              d1_d1_coeff[8*i+j]=9.0;
            else
              d1_d1_coeff[8*i+j]=-3.0;
          }   
        }   
        else
        {   
          d1_coeff_8[i]=-1.0;
          for(int j=0; j<8; j++)
          {   
            if(j<2)
              d1_d1_coeff[8*i+j]=-3.0;
            else
              d1_d1_coeff[8*i+j]=1.0;
          }   
        }   
      }
      if(this->corr)		
      {
	rep_proj_prototype<64>(tavg_corr,s1_s1_corr,s1_s1_coeff);
	rep_proj_prototype<64>(tavg_corr,s2_s2_corr,s2_s2_coeff);
	rep_proj_prototype<64>(tavg_corr,s3_s3_corr,s3_s3_coeff);
      }
      if(this->scat)		
      {
        rep_proj_prototype<64>(tavg_scat,s1_s1_scat,s1_s1_coeff);
	rep_proj_prototype<64>(tavg_scat,s2_s2_scat,s2_s2_coeff);
	rep_proj_prototype<64>(tavg_scat,s3_s3_scat,s3_s3_coeff);
      }
      if(this->corr)
      {
        rep_proj_prototype<8>(origin_self,s1_self,s1_coeff_8);
	rep_proj_prototype<8>(origin_self,s2_self,s2_coeff_8);
	rep_proj_prototype<8>(origin_self,s3_self,s3_coeff_8);
      }
      if(this->pipi)
      {
	rep_proj_prototype<64>(tavg_pipiC,s1_s1_pipiC,s1_s1_coeff);
	rep_proj_prototype<64>(tavg_pipiC,s2_s2_pipiC,s2_s2_coeff);
	rep_proj_prototype<64>(tavg_pipiC,s3_s3_pipiC,s3_s3_coeff);
        rep_proj_prototype<64>(tavg_pipiC,d1_d1_pipiC,d1_d1_coeff);

	rep_proj_prototype<64>(tavg_pipiD,s1_s1_pipiD,s1_s1_coeff);
	rep_proj_prototype<64>(tavg_pipiD,s2_s2_pipiD,s2_s2_coeff);
	rep_proj_prototype<64>(tavg_pipiD,s3_s3_pipiD,s3_s3_coeff);
        rep_proj_prototype<64>(tavg_pipiD,d1_d1_pipiD,d1_d1_coeff);

	rep_proj_prototype<64>(tavg_pipiR,s1_s1_pipiR,s1_s1_coeff);
	rep_proj_prototype<64>(tavg_pipiR,s2_s2_pipiR,s2_s2_coeff);
	rep_proj_prototype<64>(tavg_pipiR,s3_s3_pipiR,s3_s3_coeff);
        rep_proj_prototype<64>(tavg_pipiR,d1_d1_pipiR,d1_d1_coeff);

	rep_proj_prototype<64>(tavg_pipiV,s1_s1_pipiV,s1_s1_coeff);
	rep_proj_prototype<64>(tavg_pipiV,s2_s2_pipiV,s2_s2_coeff);
	rep_proj_prototype<64>(tavg_pipiV,s3_s3_pipiV,s3_s3_coeff);
        rep_proj_prototype<64>(tavg_pipiV,d1_d1_pipiV,d1_d1_coeff);

	rep_proj_prototype<8>(origin_pipiV,s1_pipiV,s1_coeff_8);
	rep_proj_prototype<8>(origin_pipiV,s2_pipiV,s2_coeff_8);
	rep_proj_prototype<8>(origin_pipiV,s3_pipiV,s3_coeff_8);
        rep_proj_prototype<8>(origin_pipiV,d1_pipiV,d1_coeff_8);
      }
      //here we get I=2 pipi state--> I=2 pipi state
      if(this->pipi)
      {
	s1_s1_pipiI_2.resize(s1_s1_pipiC.size());
	s2_s2_pipiI_2.resize(s2_s2_pipiC.size());
	s3_s3_pipiI_2.resize(s3_s3_pipiC.size());
        d1_d1_pipiI_2.resize(d1_d1_pipiC.size());
	for(int traj=0; traj<s1_s1_pipiC.size(); traj++)
	{
	  s1_s1_pipiI_2[traj].second=s1_s1_pipiC[traj].second;
	  s2_s2_pipiI_2[traj].second=s2_s2_pipiC[traj].second;
	  s3_s3_pipiI_2[traj].second=s3_s3_pipiC[traj].second;
          d1_d1_pipiI_2[traj].second=d1_d1_pipiC[traj].second;
	  for(int t=0; t<Lt; t++)
	  {
	    s1_s1_pipiI_2[traj].first[t] = 2.0 * s1_s1_pipiD[traj].first[t] - 2.0 * s1_s1_pipiC[traj].first[t];
	    s2_s2_pipiI_2[traj].first[t] = 2.0 * s2_s2_pipiD[traj].first[t] - 2.0 * s2_s2_pipiC[traj].first[t];
	    s3_s3_pipiI_2[traj].first[t] = 2.0 * s3_s3_pipiD[traj].first[t] - 2.0 * s3_s3_pipiC[traj].first[t];
            d1_d1_pipiI_2[traj].first[t] = 2.0 * d1_d1_pipiD[traj].first[t] - 2.0 * d1_d1_pipiC[traj].first[t];
	  }
	}
      }
      //here we get I=0 pipi state--> I=0 pipi state
      if(this->pipi)
      {
        s1_s1_pipiI_0.resize(s1_s1_pipiC.size());
	s2_s2_pipiI_0.resize(s2_s2_pipiC.size());
        s3_s3_pipiI_0.resize(s3_s3_pipiC.size());
        d1_d1_pipiI_0.resize(d1_d1_pipiC.size());
        for(int traj=0; traj<s1_s1_pipiC.size(); traj++)
        {
          s1_s1_pipiI_0[traj].second=s1_s1_pipiC[traj].second;
	  s2_s2_pipiI_0[traj].second=s2_s2_pipiC[traj].second;
          s3_s3_pipiI_0[traj].second=s3_s3_pipiC[traj].second;
          d1_d1_pipiI_0[traj].second=d1_d1_pipiC[traj].second;
          for(int t=0; t<Lt; t++)
          {
            s1_s1_pipiI_0[traj].first[t] = 2.0 * s1_s1_pipiD[traj].first[t] + s1_s1_pipiC[traj].first[t] - 6.0 * s1_s1_pipiR[traj].first[t] + 3.0 * s1_s1_pipiV[traj].first[t];
	    s2_s2_pipiI_0[traj].first[t] = 2.0 * s2_s2_pipiD[traj].first[t] + s2_s2_pipiC[traj].first[t] - 6.0 * s2_s2_pipiR[traj].first[t] + 3.0 * s2_s2_pipiV[traj].first[t];
	    s3_s3_pipiI_0[traj].first[t] = 2.0 * s3_s3_pipiD[traj].first[t] + s3_s3_pipiC[traj].first[t] - 6.0 * s3_s3_pipiR[traj].first[t] + 3.0 * s3_s3_pipiV[traj].first[t];
            d1_d1_pipiI_0[traj].first[t] = 2.0 * d1_d1_pipiD[traj].first[t] + d1_d1_pipiC[traj].first[t] - 6.0 * d1_d1_pipiR[traj].first[t] + 3.0 * d1_d1_pipiV[traj].first[t];
          }
        }
      }
      std::cout << "Finish rep_proj\n" << std::endl;
    }

    bool output_rep_proj_data()
    {
      if(this->corr)
      {
	output_data<Lt>("swave1->swave1_tavg_sigmacorr",s1_s1_corr);
	output_data<Lt>("swave1_sigmaself",s1_self);
      }
      if(this->scat)
	output_data<Lt>("swave1->swave1_tavg_pipisigma",s1_s1_scat);
      if(this->pipi)
      {
	output_data<Lt>("swave1->swave1_tavg_pipi_FigureC",s1_s1_pipiC);
        output_data<Lt>("swave1->swave1_tavg_pipi_FigureC_s2_s2",s2_s2_pipiC);
        output_data<Lt>("swave1->swave1_tavg_pipi_FigureC_s3_s3",s3_s3_pipiC);
	output_data<Lt>("swave1->swave1_tavg_pipi_FigureD",s1_s1_pipiD);
        output_data<Lt>("swave1->swave1_tavg_pipi_FigureD_s2_s2",s2_s2_pipiD);
        output_data<Lt>("swave1->swave1_tavg_pipi_FigureD_s3_s3",s3_s3_pipiD);
	output_data<Lt>("swave1->swave1_tavg_pipi_FigureR",s1_s1_pipiR);
	output_data<Lt>("swave1->swave1_tavg_pipi_FigureV",s1_s1_pipiV);
	output_data<Lt>("swave1->swave1_tavg_pipi_I=2",s1_s1_pipiI_2);
        output_data<Lt>("swave1->swave1_tavg_pipi_I=2_s2",s2_s2_pipiI_2);
        output_data<Lt>("swave1->swave1_tavg_pipi_I=2_s3",s3_s3_pipiI_2);
	output_data<Lt>("swave1->swave1_tavg_pipi_I=0",s1_s1_pipiI_0);
        output_data<Lt>("swave1->swave1_tavg_pipi_I=0_s2_s2",s2_s2_pipiI_0);
        output_data<Lt>("swave1->swave1_tavg_pipi_I=0_s3_s3",s3_s3_pipiI_0);
        output_data<Lt>("swave1->swave1_tavg_pipiVdis_s1",s1_pipiV);
        output_data<Lt>("swave1->swave1_tavg_pipiVdis_s2",s2_pipiV);
        output_data<Lt>("swave1->swave1_tavg_pipiVdis_s3",s3_pipiV);
      }
    }

//here are the new, double jackknife method of treating data, and they should generate the same result as Chris's
  private:
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_2;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_2_s2_s2;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_2_s3_s3;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_2_d1_d1;

    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_0;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_0_s2_s2;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_0_s3_s3;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_0_d1_d1;
    std::vector<std::vector<std::array<double,Lt> > > 		double_jk_pipiI_0_vac;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_0_vac_s2;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_0_vac_s3;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_0_vac_d1;

    std::vector<std::vector<std::array<double,Lt> > >		double_jk_corr;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_corr_s2_s2;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_corr_s3_s3;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_scat;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_scat_s2_s2;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_scat_s3_s3;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_sigma_vac;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_sigma_vac_s2;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_sigma_vac_s3;


    std::vector<std::vector<std::array<double,Lt> > > 		double_jk_pipiI_0_sub;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_0_sub_s2_s2;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_0_sub_s3_s3;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_pipiI_0_sub_d1_d1;

    std::vector<std::vector<std::array<double,Lt> > >           double_jk_corr_sub;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_corr_sub_s2_s2;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_corr_sub_s3_s3;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_scat_sub;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_scat_sub_s2_s2;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_scat_sub_s3_s3;

    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_2_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_2_fold_s2_s2;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_2_fold_s3_s3;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_2_fold_d1_d1;

    std::vector<std::vector<std::vector<double> > >   		double_jk_pipiI_0_sub_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_0_sub_fold_s2_s2;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_0_sub_fold_s3_s3;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_0_sub_fold_d1_d1;

    std::vector<std::vector<std::vector<double> > >             double_jk_corr_sub_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_corr_sub_fold_s2_s2;
    std::vector<std::vector<std::vector<double> > >             double_jk_corr_sub_fold_s3_s3;
    std::vector<std::vector<std::vector<double> > >             double_jk_scat_sub_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_scat_sub_fold_s2_s2;
    std::vector<std::vector<std::vector<double> > >             double_jk_scat_sub_fold_s3_s3;

    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_2_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_2_fold_fit_s2_s2;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_2_fold_fit_s3_s3;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_2_fold_fit_d1_d1;

    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_0_sub_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_0_sub_fold_fit_s2_s2;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_0_sub_fold_fit_s3_s3;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_0_sub_fold_fit_d1_d1;

    std::vector<std::vector<std::pair<double,int> > >           double_jk_corr_sub_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_corr_sub_fold_fit_s2_s2;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_corr_sub_fold_fit_s3_s3;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_scat_sub_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_scat_sub_fold_fit_s2_s2;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_scat_sub_fold_fit_s3_s3;

    std::vector<MatrixXd>                                       double_jk_pipiI_2_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_pipiI_2_fold_cov_mat_s2_s2;
    std::vector<MatrixXd>                                       double_jk_pipiI_2_fold_cov_mat_s3_s3;
    std::vector<MatrixXd>                                       double_jk_pipiI_2_fold_cov_mat_d1_d1;

    std::vector<MatrixXd>			     		double_jk_pipiI_0_sub_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_pipiI_0_sub_fold_cov_mat_s2_s2;
    std::vector<MatrixXd>                                       double_jk_pipiI_0_sub_fold_cov_mat_s3_s3;
    std::vector<MatrixXd>                                       double_jk_pipiI_0_sub_fold_cov_mat_d1_d1;

    std::vector<MatrixXd>                                       double_jk_corr_sub_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_corr_sub_fold_cov_mat_s2_s2;
    std::vector<MatrixXd>                                       double_jk_corr_sub_fold_cov_mat_s3_s3;

    std::vector<MatrixXd>                                       double_jk_scat_sub_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_scat_sub_fold_cov_mat_s2_s2;
    std::vector<MatrixXd>                                       double_jk_scat_sub_fold_cov_mat_s3_s3;

    std::vector<std::pair<double,double> >			double_jk_pipiI_0_sub_fold_fit_result;
    std::vector<std::pair<double,double> >                      double_jk_corr_sub_fold_fit_result;
    std::vector<std::pair<double,double> >                      double_jk_scat_sub_fold_fit_result;

    std::array<std::vector<std::vector<std::pair<double,int> > >,4> double_jk_pipisigma_gevp;
  public:

    void double_jk_generate()
    {
      std::cout << "Start double_jk_generate\n" << std::endl;
      double_jk_generate_prototype(double_jk_pipiI_2, s1_s1_pipiI_2);
      double_jk_generate_prototype(double_jk_pipiI_2_s2_s2, s2_s2_pipiI_2);
      double_jk_generate_prototype(double_jk_pipiI_2_s3_s3, s3_s3_pipiI_2);
      double_jk_generate_prototype(double_jk_pipiI_2_d1_d1, d1_d1_pipiI_2);

      double_jk_generate_prototype(double_jk_pipiI_0, s1_s1_pipiI_0);
      double_jk_generate_prototype(double_jk_pipiI_0_s2_s2, s2_s2_pipiI_0);
      double_jk_generate_prototype(double_jk_pipiI_0_s3_s3, s3_s3_pipiI_0);
      double_jk_generate_prototype(double_jk_pipiI_0_d1_d1, d1_d1_pipiI_0);
      double_jk_generate_prototype(double_jk_pipiI_0_vac, s1_pipiV);
      double_jk_generate_prototype(double_jk_pipiI_0_vac_s2, s2_pipiV);
      double_jk_generate_prototype(double_jk_pipiI_0_vac_s3, s3_pipiV);
      double_jk_generate_prototype(double_jk_pipiI_0_vac_d1, d1_pipiV);

      double_jk_generate_prototype(double_jk_corr, s1_s1_corr);
      double_jk_generate_prototype(double_jk_corr_s2_s2, s2_s2_corr);
      double_jk_generate_prototype(double_jk_corr_s3_s3, s3_s3_corr);
      double_jk_generate_prototype(double_jk_scat, s1_s1_scat);
      double_jk_generate_prototype(double_jk_scat_s2_s2, s2_s2_scat);
      double_jk_generate_prototype(double_jk_scat_s3_s3, s3_s3_scat);
      double_jk_generate_prototype(double_jk_sigma_vac, s1_self);
      double_jk_generate_prototype(double_jk_sigma_vac_s2, s2_self);
      double_jk_generate_prototype(double_jk_sigma_vac_s3, s3_self);
      std::cout << "Finish double_jk_generate\n" << std::endl;
    }

    void double_jk_vac_sub(bool do_sub = true)
    {
      std::cout << "Start double_jk_vac_sub\n" << std::endl;
      if(this->corr)
      {
	int n_traj = double_jk_corr.size();
	assert(n_traj == double_jk_sigma_vac.size());
	double_jk_corr_sub.resize(n_traj);
	for(int idx_I=0; idx_I<n_traj; idx_I++)
	{
	  double_jk_corr_sub[idx_I].resize(n_traj-1);
	  for(int idx_J=0; idx_J<n_traj-1; idx_J++)
	  {
	    for(int t=0; t<Lt; t++)
	    {
	      double_jk_corr_sub[idx_I][idx_J][t] = double_jk_corr[idx_I][idx_J][t];
	      if(do_sub)
	      {
	        for(int tsrc=0; tsrc<Lt; tsrc++)
	        {
		  double_jk_corr_sub[idx_I][idx_J][t] -= 0.5 * double_jk_sigma_vac[idx_I][idx_J][tsrc] * double_jk_sigma_vac[idx_I][idx_J][(t+tsrc)%Lt] / Lt;
	        }
	      }
	    }
	  }
	}

	n_traj = double_jk_corr_s2_s2.size();
        assert(n_traj == double_jk_sigma_vac_s2.size());
        double_jk_corr_sub_s2_s2.resize(n_traj);
        for(int idx_I=0; idx_I<n_traj; idx_I++)
        {
          double_jk_corr_sub_s2_s2[idx_I].resize(n_traj-1);
          for(int idx_J=0; idx_J<n_traj-1; idx_J++)
          {
            for(int t=0; t<Lt; t++)
            {
              double_jk_corr_sub_s2_s2[idx_I][idx_J][t] = double_jk_corr_s2_s2[idx_I][idx_J][t];
	      if(do_sub)
	      {
                for(int tsrc=0; tsrc<Lt; tsrc++)
	        {
                  double_jk_corr_sub_s2_s2[idx_I][idx_J][t] -= 0.5 * double_jk_sigma_vac_s2[idx_I][idx_J][tsrc] * double_jk_sigma_vac_s2[idx_I][idx_J][(t+tsrc)%Lt] / Lt;
	        }
	      }
            }
          }
        }

	n_traj = double_jk_corr_s3_s3.size();
        assert(n_traj == double_jk_sigma_vac_s3.size());
        double_jk_corr_sub_s3_s3.resize(n_traj);
        for(int idx_I=0; idx_I<n_traj; idx_I++)
        {
          double_jk_corr_sub_s3_s3[idx_I].resize(n_traj-1);
          for(int idx_J=0; idx_J<n_traj-1; idx_J++)
          {
            for(int t=0; t<Lt; t++)
            {
              double_jk_corr_sub_s3_s3[idx_I][idx_J][t] = double_jk_corr_s3_s3[idx_I][idx_J][t];
	      if(do_sub)
	      {
                for(int tsrc=0; tsrc<Lt; tsrc++)
	        {
                  double_jk_corr_sub_s3_s3[idx_I][idx_J][t] -= 0.5 * double_jk_sigma_vac_s3[idx_I][idx_J][tsrc] * double_jk_sigma_vac_s3[idx_I][idx_J][(t+tsrc)%Lt] / Lt;
	        }
	      }
            }
          }
        }
      }
      if(this->scat)
      {
	int n_traj = double_jk_scat.size();
        if(do_sub)
        {
	  assert(n_traj == double_jk_sigma_vac.size());
	  assert(n_traj == double_jk_pipiI_0_vac.size());
        }
	double_jk_scat_sub.resize(n_traj);
	for(int idx_I=0; idx_I<n_traj; idx_I++)
	{
	  double_jk_scat_sub[idx_I].resize(n_traj-1);
	  for(int idx_J=0; idx_J<n_traj-1; idx_J++)
	  {
	    for(int t=0; t<Lt; t++)
	    {
	      double_jk_scat_sub[idx_I][idx_J][t] = double_jk_scat[idx_I][idx_J][t];
	      if(do_sub)
	      {
	        for(int tsrc=0; tsrc<Lt; tsrc++)
	        {
	  	  double_jk_scat_sub[idx_I][idx_J][t] -= 1.22474487139 * double_jk_sigma_vac[idx_I][idx_J][(tsrc+t)%Lt] * double_jk_pipiI_0_vac[idx_I][idx_J][tsrc] / Lt;
	        }
	      }
	    }
	  }
	}

	n_traj = double_jk_scat_s2_s2.size();
        if(do_sub)
        {
          assert(n_traj == double_jk_sigma_vac_s2.size());
          assert(n_traj == double_jk_pipiI_0_vac_s2.size());
        }
        double_jk_scat_sub_s2_s2.resize(n_traj);
        for(int idx_I=0; idx_I<n_traj; idx_I++)
        {
          double_jk_scat_sub_s2_s2[idx_I].resize(n_traj-1);
          for(int idx_J=0; idx_J<n_traj-1; idx_J++)
          {
            for(int t=0; t<Lt; t++)
            {
              double_jk_scat_sub_s2_s2[idx_I][idx_J][t] = double_jk_scat_s2_s2[idx_I][idx_J][t];
	      if(do_sub)
	      {
                for(int tsrc=0; tsrc<Lt; tsrc++)
	        {
                  double_jk_scat_sub_s2_s2[idx_I][idx_J][t] -= 1.22474487139 * double_jk_sigma_vac_s2[idx_I][idx_J][(tsrc+t)%Lt] * double_jk_pipiI_0_vac_s2[idx_I][idx_J][tsrc] / Lt;
	        }
	      }
            }
          }
        }

	n_traj = double_jk_scat_s3_s3.size();
        if(do_sub)
        {
          assert(n_traj == double_jk_sigma_vac_s3.size());
          assert(n_traj == double_jk_pipiI_0_vac_s3.size());
        }
        double_jk_scat_sub_s3_s3.resize(n_traj);
        for(int idx_I=0; idx_I<n_traj; idx_I++)
        {
          double_jk_scat_sub_s3_s3[idx_I].resize(n_traj-1);
          for(int idx_J=0; idx_J<n_traj-1; idx_J++)
          {
            for(int t=0; t<Lt; t++)
            {
              double_jk_scat_sub_s3_s3[idx_I][idx_J][t] = double_jk_scat_s3_s3[idx_I][idx_J][t];
	      if(do_sub)
	      {
                for(int tsrc=0; tsrc<Lt; tsrc++)
	        {
                  double_jk_scat_sub_s3_s3[idx_I][idx_J][t] -= 1.22474487139 * double_jk_sigma_vac_s3[idx_I][idx_J][(tsrc+t)%Lt] * double_jk_pipiI_0_vac_s3[idx_I][idx_J][tsrc] / Lt;
	        }
	      }
            }
          }
        }
      }
      int n_traj = double_jk_pipiI_0.size();
      assert(n_traj == double_jk_pipiI_0_vac.size());
      double_jk_pipiI_0_sub.resize(n_traj);
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
	double_jk_pipiI_0_sub[idx_I].resize(n_traj-1);
	for(int idx_J=0; idx_J<n_traj-1; idx_J++)
	{
	  for(int t=0; t<Lt; t++)
	  {
	    double_jk_pipiI_0_sub[idx_I][idx_J][t] = double_jk_pipiI_0[idx_I][idx_J][t];
	    if(do_sub)
	    {
	      for(int tsrc=0; tsrc<Lt; tsrc++)
	      {
	        double_jk_pipiI_0_sub[idx_I][idx_J][t] -= 3.0 * double_jk_pipiI_0_vac[idx_I][idx_J][tsrc] * double_jk_pipiI_0_vac[idx_I][idx_J][(t+tsrc+tdis)%Lt] / Lt;
	      }
	    }
	  }
	}
      }

      n_traj = double_jk_pipiI_0_s2_s2.size();
      assert(n_traj == double_jk_pipiI_0_vac_s2.size());
      double_jk_pipiI_0_sub_s2_s2.resize(n_traj);
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
        double_jk_pipiI_0_sub_s2_s2[idx_I].resize(n_traj-1);
        for(int idx_J=0; idx_J<n_traj-1; idx_J++)
        {
          for(int t=0; t<Lt; t++)
          {
            double_jk_pipiI_0_sub_s2_s2[idx_I][idx_J][t] = double_jk_pipiI_0_s2_s2[idx_I][idx_J][t];
	    if(do_sub)
	    {
              for(int tsrc=0; tsrc<Lt; tsrc++)
	      {
                double_jk_pipiI_0_sub_s2_s2[idx_I][idx_J][t] -= 3.0 * double_jk_pipiI_0_vac_s2[idx_I][idx_J][tsrc] * double_jk_pipiI_0_vac_s2[idx_I][idx_J][(t+tsrc+tdis)%Lt] / Lt;
	      }
	    }
          }
        }
      }

      n_traj = double_jk_pipiI_0_s3_s3.size();
      assert(n_traj == double_jk_pipiI_0_vac_s3.size());
      double_jk_pipiI_0_sub_s3_s3.resize(n_traj);
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
        double_jk_pipiI_0_sub_s3_s3[idx_I].resize(n_traj-1);
        for(int idx_J=0; idx_J<n_traj-1; idx_J++)
        {
          for(int t=0; t<Lt; t++)
          {
            double_jk_pipiI_0_sub_s3_s3[idx_I][idx_J][t] = double_jk_pipiI_0_s3_s3[idx_I][idx_J][t];
	    if(do_sub)
	    {
              for(int tsrc=0; tsrc<Lt; tsrc++)
	      {
                double_jk_pipiI_0_sub_s3_s3[idx_I][idx_J][t] -= 3.0 * double_jk_pipiI_0_vac_s3[idx_I][idx_J][tsrc] * double_jk_pipiI_0_vac_s3[idx_I][idx_J][(t+tsrc+tdis)%Lt] / Lt;
	      }
	    }
          }
        }
      }

      n_traj = double_jk_pipiI_0_d1_d1.size();
      assert(n_traj == double_jk_pipiI_0_vac_d1.size());
      double_jk_pipiI_0_sub_d1_d1.resize(n_traj);
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
        double_jk_pipiI_0_sub_d1_d1[idx_I].resize(n_traj-1);
        for(int idx_J=0; idx_J<n_traj-1; idx_J++)
        {
          for(int t=0; t<Lt; t++)
          {
            double_jk_pipiI_0_sub_d1_d1[idx_I][idx_J][t] = double_jk_pipiI_0_d1_d1[idx_I][idx_J][t];
            if(do_sub)
            {
              for(int tsrc=0; tsrc<Lt; tsrc++)
              {
                double_jk_pipiI_0_sub_d1_d1[idx_I][idx_J][t] -= 3.0 * double_jk_pipiI_0_vac_d1[idx_I][idx_J][tsrc] * double_jk_pipiI_0_vac_d1[idx_I][idx_J][(t+tsrc+tdis)%Lt] / Lt;
              }
            }
          }
        }
      }
      std::cout << "Finish double_jk_vac_sub\n" << std::endl;
    }

    void double_jk_fold()
    {
      std::cout << "Start double_jk_fold\n" << std::endl;

      double_jk_fold_prototype(double_jk_pipiI_2,double_jk_pipiI_2_fold,2*tdis);
      double_jk_fold_prototype(double_jk_pipiI_2_s2_s2,double_jk_pipiI_2_fold_s2_s2,2*tdis);
      double_jk_fold_prototype(double_jk_pipiI_2_s3_s3,double_jk_pipiI_2_fold_s3_s3,2*tdis);
      double_jk_fold_prototype(double_jk_pipiI_2_d1_d1,double_jk_pipiI_2_fold_d1_d1,2*tdis);

      double_jk_fold_prototype(double_jk_pipiI_0_sub,double_jk_pipiI_0_sub_fold,2*tdis);
      double_jk_fold_prototype(double_jk_pipiI_0_sub_s2_s2,double_jk_pipiI_0_sub_fold_s2_s2,2*tdis);
      double_jk_fold_prototype(double_jk_pipiI_0_sub_s3_s3,double_jk_pipiI_0_sub_fold_s3_s3,2*tdis);
      double_jk_fold_prototype(double_jk_pipiI_0_sub_d1_d1,double_jk_pipiI_0_sub_fold_d1_d1,2*tdis);

      double_jk_fold_prototype(double_jk_corr_sub,double_jk_corr_sub_fold,0);
      double_jk_fold_prototype(double_jk_corr_sub_s2_s2,double_jk_corr_sub_fold_s2_s2,0);
      double_jk_fold_prototype(double_jk_corr_sub_s3_s3,double_jk_corr_sub_fold_s3_s3,0);

      double_jk_fold_prototype(double_jk_scat_sub,double_jk_scat_sub_fold,tdis);
      double_jk_fold_prototype(double_jk_scat_sub_s2_s2,double_jk_scat_sub_fold_s2_s2,tdis);
      double_jk_fold_prototype(double_jk_scat_sub_s3_s3,double_jk_scat_sub_fold_s3_s3,tdis);
      std::cout << "Finish double_jk_fold\n" << std::endl;
    }
 
    void double_jk_fit_input_generate(bool corfit = true)
    {
      std::cout << "Start double_jk_fit_input_generate\n" << std::endl;

      double_jk_fit_input_generate_prototype(double_jk_pipiI_2_fold, double_jk_pipiI_2_fold_fit, double_jk_pipiI_2_fold_cov_mat,corfit);     
      double_jk_fit_input_generate_prototype(double_jk_pipiI_2_fold_s2_s2, double_jk_pipiI_2_fold_fit_s2_s2, double_jk_pipiI_2_fold_cov_mat_s2_s2,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_2_fold_s3_s3, double_jk_pipiI_2_fold_fit_s3_s3, double_jk_pipiI_2_fold_cov_mat_s3_s3,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_2_fold_d1_d1, double_jk_pipiI_2_fold_fit_d1_d1, double_jk_pipiI_2_fold_cov_mat_d1_d1,corfit);

      double_jk_fit_input_generate_prototype(double_jk_pipiI_0_sub_fold, double_jk_pipiI_0_sub_fold_fit, double_jk_pipiI_0_sub_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_0_sub_fold_s2_s2, double_jk_pipiI_0_sub_fold_fit_s2_s2, double_jk_pipiI_0_sub_fold_cov_mat_s2_s2,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_0_sub_fold_s3_s3, double_jk_pipiI_0_sub_fold_fit_s3_s3, double_jk_pipiI_0_sub_fold_cov_mat_s3_s3,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_0_sub_fold_d1_d1, double_jk_pipiI_0_sub_fold_fit_d1_d1, double_jk_pipiI_0_sub_fold_cov_mat_d1_d1,corfit);

      double_jk_fit_input_generate_prototype(double_jk_corr_sub_fold, double_jk_corr_sub_fold_fit, double_jk_corr_sub_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_corr_sub_fold_s2_s2, double_jk_corr_sub_fold_fit_s2_s2, double_jk_corr_sub_fold_cov_mat_s2_s2,corfit);
      double_jk_fit_input_generate_prototype(double_jk_corr_sub_fold_s3_s3, double_jk_corr_sub_fold_fit_s3_s3, double_jk_corr_sub_fold_cov_mat_s3_s3,corfit);

      double_jk_fit_input_generate_prototype(double_jk_scat_sub_fold, double_jk_scat_sub_fold_fit, double_jk_scat_sub_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_scat_sub_fold_s2_s2, double_jk_scat_sub_fold_fit_s2_s2, double_jk_scat_sub_fold_cov_mat_s2_s2,corfit);
      double_jk_fit_input_generate_prototype(double_jk_scat_sub_fold_s3_s3, double_jk_scat_sub_fold_fit_s3_s3, double_jk_scat_sub_fold_cov_mat_s3_s3,corfit);
      std::cout << "Finish double_jk_fit_input_generate\n" << std::endl;
    }

    void output_double_jk_fit_input(bool diag = false)
    {
//      output_data("double jk pipi_scat_I=0 no folding!", double_jk_pipiI_0_sub_fit, double_jk_pipiI_0_sub_cov_mat);
      output_data("double jk pipi_scat_I=0", double_jk_pipiI_0_sub_fold_fit, double_jk_pipiI_0_sub_fold_cov_mat,diag);
      output_data("double jk pipi_scat_I=0_s2_s2", double_jk_pipiI_0_sub_fold_fit_s2_s2, double_jk_pipiI_0_sub_fold_cov_mat_s2_s2,diag);
      output_data("double jk pipi_scat_I=0_s3_s3", double_jk_pipiI_0_sub_fold_fit_s3_s3, double_jk_pipiI_0_sub_fold_cov_mat_s3_s3,diag);
      output_data("double jk pipi_scat_I=0_d1_d1", double_jk_pipiI_0_sub_fold_fit_d1_d1, double_jk_pipiI_0_sub_fold_cov_mat_d1_d1,diag);
      output_data("double jk sigmacorr", double_jk_corr_sub_fold_fit, double_jk_corr_sub_fold_cov_mat,diag);
      output_data("double jk sigmacorr_s2_s2", double_jk_corr_sub_fold_fit_s2_s2, double_jk_corr_sub_fold_cov_mat_s2_s2,diag);
      output_data("double jk sigmacorr_s3_s3", double_jk_corr_sub_fold_fit_s3_s3, double_jk_corr_sub_fold_cov_mat_s3_s3,diag);
      output_data("double jk pipisigma", double_jk_scat_sub_fold_fit, double_jk_scat_sub_fold_cov_mat,diag);
      output_data("double jk pipisigma_s2_s2", double_jk_scat_sub_fold_fit_s2_s2, double_jk_scat_sub_fold_cov_mat_s2_s2,diag);
      output_data("double jk pipisigma_s3_s3", double_jk_scat_sub_fold_fit_s3_s3, double_jk_scat_sub_fold_cov_mat_s3_s3,diag);
    }

    void double_jk_input_result()
    {
      double_jk_input_average_prototype(double_jk_pipiI_0_sub_fold_fit, double_jk_pipiI_0_sub_fold_fit_result);
      double_jk_input_average_prototype(double_jk_corr_sub_fold_fit, double_jk_corr_sub_fold_fit_result);
      double_jk_input_average_prototype(double_jk_scat_sub_fold_fit, double_jk_scat_sub_fold_fit_result);
    }

    void output_double_jk_input_result()
    {
      output_data("double_jk_pipiI_0_fit_input_output_average_and_error", double_jk_pipiI_0_sub_fold_fit_result);
      output_data("double_jk_corr_fit_input_output_average_and_error", double_jk_corr_sub_fold_fit_result);
      output_data("double_jk_scat_fit_input_output_average_and_error", double_jk_scat_sub_fold_fit_result);
    }

//here we use GEVP to calculate eff_energy. Notice 1d original gevp is actually worse than 2pt eff mass
  private:

    template<typename tt, size_t Nop>
    void output_gevp_energy(const std::map<tt,std::array<std::pair<std::complex<double>,double>,Nop> > &input, tt t0)
    {
      for(size_t i=0; i<Nop; i++)
        for(auto it=input.begin(); it!=input.end(); it++)
          std::cout << "The " << i << "-th state at t0 = " << t0 << " and t = " << it->first << " has eff energy " << it->second[i].first.real() << " + " << it->second[i].first.imag() << " i" <<  "  +- " << it->second[i].second << '\n';
    }

    template<typename tt, size_t Nop>
    void EffEnergyEnsembleAverage(const std::vector<std::map<tt,std::array<std::complex<double>,Nop> > > &input, std::map<tt,std::array<std::pair<std::complex<double>,double>,Nop> > &output)
    {
      for(auto it=input[0].begin(); it!=input[0].end(); it++)
      {
        tt key = it->first;
        output[key].fill(std::pair<std::complex<double>,double> (0.0,0.0));
        for(size_t n=0; n<Nop; n++)
        {
          for(int traj=0; traj<input.size(); traj++)
          {
            output[key][n].first += input[traj].at(key)[n];
            output[key][n].second += input[traj].at(key)[n].real() * input[traj].at(key)[n].real();
          }
          output[key][n].first /= static_cast<double>(input.size());
          output[key][n].second -= output[key][n].first.real() * output[key][n].first.real() * static_cast<double>(input.size());
          output[key][n].second = output[key][n].second * (static_cast<double>(input.size()) -1.0) / static_cast<double>(input.size());
          output[key][n].second = sqrt(output[key][n].second);
        }
      }
      std::cout << "Finish doing EffEnergyEnsembleAverage" << std::endl;
    }

    template<typename tt, size_t Nop>
    void GeneralizedEigenValueWrapper(const std::array<std::vector<std::vector<std::pair<double,int> > >,Nop*Nop> &input, std::map<tt,std::array<std::pair<std::complex<double>,double>,Nop> > &output, const tt t0, const tt tmin, const tt tmax, bool gevp_sub)
    {
      std::vector<std::map<tt,std::array<std::complex<double>,Nop> > > output_noavg;
      output_noavg.resize(input[0].size());
      for(int traj=0; traj<output_noavg.size(); traj++)
      {
        GeneralizedEigenValueSolver<Nop> gevp(tmin,tmax,gevp_sub);
//make sure input[0].size() is the smallest
        for(int tidx=0; tidx<input[0][traj].size(); tidx++)
        {
          tt t = input[0][traj][tidx].second;
          Matrix<double,Nop,Nop> mat;
          for(int i=0; i<Nop; i++)
            for(int j=0; j<Nop; j++)
              mat(i,j) = input[i*Nop+j][traj][tidx].first;
          gevp.setData(t,mat);          
        }
        if(gevp_sub)
          gevp.generateSubData();
        gevp.CalcEffEnergyFixedt0(t0);
        for(tt t=t0+1; t<tmax-1; t++)
        {
          output_noavg[traj][t] = gevp.getEnergy(t,t0);
        }
      }
      EffEnergyEnsembleAverage(output_noavg,output);
    }

    template<typename tt, size_t Nop>
    void gevp_entire_wrapper(const std::array<std::vector<std::vector<std::pair<double,int> > >,Nop*Nop> &input, const tt t0, const tt tmin, const tt tmax, bool gevp_sub)
    {
      std::map<tt,std::array<std::pair<std::complex<double>,double>,Nop> > tmp;
      GeneralizedEigenValueWrapper(input,tmp,t0,tmin,tmax,gevp_sub);
      output_gevp_energy(tmp,t0);
    }

    void pipiandsigma_gevp_input_wrapper()
    {
      double_jk_pipisigma_gevp[0] = double_jk_pipiI_0_sub_fold_fit;
      double_jk_pipisigma_gevp[1] = double_jk_scat_sub_fold_fit;
      double_jk_pipisigma_gevp[2] = double_jk_scat_sub_fold_fit;
      double_jk_pipisigma_gevp[3] = double_jk_corr_sub_fold_fit; 
    }

  public:
    void gevp_start(bool do_sub)
    {
      std::cout << "Start gevp\n" << std::endl;
      pipiandsigma_gevp_input_wrapper();
      std::cout << "wrapper for pipiandsigma successful\n" <<std::endl;
      gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,1,1,16,do_sub);
      gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,2,1,16,do_sub);
      gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,3,1,16,do_sub);
      gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,4,1,16,do_sub);
      gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,5,1,16,do_sub);
      gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,6,1,16,do_sub);
      gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,7,1,16,do_sub);
      gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,8,1,16,do_sub);
      gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,9,1,16,do_sub);
      std::cout << "Finish gevp\n" << std::endl;
    }

//this section provides implementation for function we use above
  private:

    bool read_single_file(std::string fs, int traj, std::pair<std::array<double,Lt*Lt>,int> &output)
    {
      ifstream infile(fs.c_str());
      if(infile.is_open())
      {
        for(int i=0; i<Lt*Lt; i++)
        {
          output.first[i]=0.0;
        }
        int tsrc=0, tdis=0, idx=0;
        double reval=0.0, imval=0.0;
        while(infile >> tsrc >> tdis >> reval >> imval)
        {
          output.first[idx]=reval;
          idx++;
        }
        output.second=traj;
        cout << "successfully reading file with name "<< fs <<'\n';
	infile.close();
        return true;
      }
      else
        return false;
    }

    bool read_single_file(std::string fs, int traj, std::pair<std::array<double,Lt>,int> &output)
    {
      ifstream infile(fs.c_str());
      if(infile.is_open())
      {
        for(int i=0; i<Lt; i++)
        {
          output.first[i]=0.0;
        }
        int tsrc=0;
        double reval=0.0, imval=0.0;
        while(infile >> tsrc >> reval >> imval)
          output.first[tsrc]=reval;
        output.second=traj;
        cout << "successfully reading file with name "<< fs <<'\n';
        infile.close();
        return true;
      }
      else
        return false;
    }

    bool read_single_file(std::string fs, int traj, std::pair<std::array<double,Lt*Lt/tstep>,int> &output)
    {
      ifstream infile(fs.c_str());
      if(infile.is_open())
      {
	for(int i=0; i<Lt*Lt/tstep; i++)
	{
	  output.first[i]=0.0;
	}
	int tsrc=0, tdis=0, idx=0;
	double reval=0.0, imval=0.0;
	while(infile >> tsrc >> tdis >> reval >> imval)
	{
	  if(tsrc % tstep == 0)
	  {
	    output.first[idx]=reval;
	    idx++;
	  }
	}
	output.second=traj;
	infile.close();
        cout << "successfully reading file with name "<< fs <<'\n';
	return true;
      }
      else
	return false;
    }


    bool output_data(std::string name, std::array<std::pair<double,double>,Lt> output)
    {
      cout<<"Now we are output "<<name<<'\n';
      for(int t=0; t<Lt; t++)
      {
	cout<<"t= "<<t<<"\taverage= "<<output[t].first<<"\terror= "<<output[t].second<<'\n';
      }   
      cout<<'\n';
    }

    template<int N_ele>
    bool output_data(std::string name, std::vector<std::map<int,std::array<double,N_ele> > > output)
    {
      cout << "Now we are output map like data " << name << '\n';
      for(int traj=0; traj<output.size(); traj++)
      {
        for(auto it = output[traj].cbegin(); it!= output[traj].cend(); it++)
        {
          for(int t=0; t<N_ele; t++)
            cout << "t= " << t << "\tcode = "<< it->first << "\tdata = "<< it->second[t] << '\n';
        }
      }
    }

    template<int N_pidx, int N_ele>
    bool output_data(std::string name, std::array<std::vector<std::pair<std::array<double, N_ele>,int> >,N_pidx > output)
    {
      for(int pidx=0 ;pidx<N_pidx; pidx++)
      {
	for(int traj=0; traj<output[pidx].size(); traj++)
	{
          cout<<"Now we are output "<<name<<" with p_idx = "<<pidx<<" and traj num = "<<output[pidx][traj].second<<'\n';
          for(int n=0; n<N_ele; n++)
	    cout<<output[pidx][traj].first[n]<<'\n';
	  cout<<'\n';
	}
	cout<<'\n';
      }
      cout<<'\n';
    }

    template<int N_ele>
    bool output_data(std::string name, std::vector<std::pair<std::array<double,Lt>,int> > output)
    {
      for(int traj=0; traj<output.size(); traj++)
      {
	cout<<"Now we are output "<<name<<" with traj num = "<<output[traj].second<<'\n';
	for(int n=0; n<N_ele; n++)
	  cout<<output[traj].first[n]<<'\n';
	cout<<'\n';
      }
      cout<<'\n';
    }

    bool output_data(std::string name, std::vector<std::vector<std::tuple<double,double,int> > > output)
    {
      for(int traj=0; traj<output.size(); traj++)
      {
	cout<<"Now we are output uncorrelated fit input of "<<name<<" with "<<traj<<" th ensemble\n";
	for(int t=0; t<output[traj].size(); t++)
	{
	  cout<<"t= "<<std::get<2>(output[traj][t])<<"\tavg= "<<std::get<0>(output[traj][t])<<"\terr= "<<std::get<1>(output[traj][t])<<'\n';
	}
	cout<<'\n';
      }
      cout<<'\n';
    }

    bool output_data(std::string name, std::vector<std::vector<std::pair<double,int> > > output)
    {
      for(int traj=0; traj<output.size(); traj++)
      {
	cout<<"Now we are output correlated fit input of "<<name<<" with "<<traj<<" th ensemble\n";
	for(int t=0; t<output[traj].size(); t++)
	{
	  cout<<"t= "<<output[traj][t].second<<"\tavg= "<<output[traj][t].first<<'\n';
	}
	cout<<'\n';
      }
      cout<<'\n';
    }

    bool output_data(std::string name, std::vector<std::pair<double,double> > output)
    {
      cout<<"Now we are output "<<name<<'\n';
      for(int t=0; t<output.size(); t++)
      {
	cout<<"t= "<<t<<"\taverage=  "<<output[t].first<<"\terror=  "<<output[t].second<<'\n';
      }
      cout<<'\n';
    }

    bool output_data(std::string name, std::vector<std::vector<std::pair<double,int> > > output, std::vector<MatrixXd> mat, bool diag=true)
    {
      for(int traj=0; traj<output.size(); traj++)
      {
	assert(mat[traj].rows() == mat[traj].cols());
	assert(mat[traj].rows() == output[traj].size());
	if(diag)
	{
          cout<<"Now we are output correlated fit input of "<<name<<" with "<<traj<<" th ensemble but only the diagonal element of cov_mat\n";
          for(int t=0; t<output[traj].size(); t++)
          {
            cout<<"t= "<<output[traj][t].second<<"\tavg= "<<output[traj][t].first<<"\terr= "<<mat[traj](t,t)<<'\n';
          }
          cout<<'\n';
        }
	else
	{
	  cout<<"Now we are output correlated fit input of "<<name<<" with "<<traj<<" th ensemble\n";
	  cout<<"Now we are output cov mat\n"<<mat[traj]<<'\n';
	  for(int t=0; t<output[traj].size(); t++)
          {
            cout<<"t= "<<output[traj][t].second<<"\tavg= "<<output[traj][t].first<<'\n';
          }
	}
        cout<<'\n';
      }
    }

    template<int N_pidx>
    bool tavg_generate_prototype(std::array<std::vector<std::pair<std::array<double,Lt*Lt>,int> >,N_pidx > input, std::array<std::vector<std::pair<std::array<double,Lt>,int> >,N_pidx> &output)
    {
      for(int pidx=0; pidx<N_pidx; pidx++)
      {
	output[pidx].resize(input[pidx].size());
	for(int traj=0; traj<output[pidx].size(); traj++)
	{
	  output[pidx][traj].second=input[pidx][traj].second;
	  for(int idx=0; idx<Lt; idx++)
	    output[pidx][traj].first[idx]=0.0;
	  for(int idx=0; idx<Lt*Lt; idx++)
	    output[pidx][traj].first[idx%Lt]+=input[pidx][traj].first[idx];
	  for(int idx=0; idx<Lt; idx++)
	    output[pidx][traj].first[idx]/=Lt;
	}
      }
    }

    template<int N_pidx>
    bool tavg_generate_prototype(std::array<std::vector<std::pair<std::array<double,Lt*Lt/tstep>,int> >,N_pidx > input, std::array<std::vector<std::pair<std::array<double,Lt>,int> >,N_pidx> &output)
    {
      for(int pidx=0; pidx<N_pidx; pidx++)
      {
	output[pidx].resize(input[pidx].size());
	for(int traj=0; traj<output[pidx].size(); traj++)
	{
	  output[pidx][traj].second=input[pidx][traj].second;
	  for(int idx=0; idx<Lt; idx++)
	    output[pidx][traj].first[idx]=0.0;
	  for(int idx=0; idx<Lt*Lt/tstep; idx++)
	    output[pidx][traj].first[idx%Lt]+=input[pidx][traj].first[idx];
	  for(int idx=0; idx<Lt; idx++)
	    output[pidx][traj].first[idx]/=(Lt/tstep);
	}
      }
    }


    template<int N_pidx>
    bool rep_proj_prototype(std::array<std::vector<std::pair<std::array<double,Lt>,int> >,N_pidx > input, std::vector<std::pair<std::array<double,Lt>,int> > &output, std::array<double,N_pidx> coeff)
    {
      output.resize(input[0].size());
      for(int traj=0; traj<output.size(); traj++)
      {
	output[traj].second=input[0][traj].second;
	for(int idx=0; idx<Lt; idx++)
	{
	  output[traj].first[idx]=0.0;
	  for(int pidx=0; pidx<N_pidx; pidx++)
	    output[traj].first[idx]+=coeff[pidx]*input[pidx][traj].first[idx];
	}
      }
    }

 
    bool vec_generate(std::vector<double> &output, std::vector<std::pair<std::array<double,Lt>,int> > input, int traj, int idx)
    {
      assert(idx<Lt);
      assert(traj<input.size());
      output.resize(0);
      for(int t=0; t<input.size(); t++)
      {
	if(t!=traj)
	  output.push_back(input[t].first[idx]);
      }
      assert(output.size() == (input.size() -1) );
    }
    
    bool ensemble_nosub_prototype(std::vector<std::pair<std::array<double,Lt>,int> > input, std::vector<std::vector<std::tuple<double,double,int> > > &output, double fit_avg_fac, double fit_err_fac, std::vector<Matrix<double,Lt,Lt> > &cov_mat)
    {
      output.resize(input.size());
      cov_mat.resize(0);
      for(int traj=0; traj<input.size(); traj++)
      {
	Matrix<double,Lt,Lt> tmp_mat;
	output[traj].resize(0);
	for(int tsep=0; tsep<Lt; tsep++)
	{
	  std::vector<double> vec;
	  std::tuple<double,double,int> tmp;
	  vec_generate(vec,input,traj,tsep);
	  std::get<0>(tmp)=vec_avg(vec)/fit_avg_fac;
	  std::get<1>(tmp)=vec_err(vec)/fit_err_fac;
	  std::get<2>(tmp)=tsep;
	  output[traj].push_back(tmp);
	  for(int tsrc=0; tsrc<Lt; tsrc++)
	  {
	    std::vector<double> vec2;
	    vec_generate(vec2,input,traj,tsrc);
	    tmp_mat(tsep,tsrc)=vec_cov_err(vec,vec2);
	  }
	}
	cov_mat.push_back(tmp_mat);
      }
    }

    bool ensemble_sub_prototype(std::vector<std::pair<std::array<double,Lt>,int> > input, std::vector<std::pair<std::array<double,Lt>,int> > vac_src, std::vector<std::pair<std::array<double,Lt>,int> > vac_snk, double coeff_in, std::vector<std::vector<std::tuple<double,double,int> > > &output, double fit_avg_fac, double fit_err_fac)
    {
      std::vector<Matrix<double,Lt,Lt> > vec_temp;
      ensemble_nosub_prototype(input,output,1.0,fit_err_fac,vec_temp);
      double coeff=coeff_in/64.0;
      for(int traj=0; traj<output.size(); traj++)
      {
	std::array<double,Lt> avg_vac_src;
	std::array<double,Lt> avg_vac_snk;
	for(int tsrc=0; tsrc<Lt; tsrc++)
	{
	  std::vector<double> vec;
	  vec_generate(vec,vac_src,traj,tsrc);
	  avg_vac_src[tsrc]=vec_avg(vec);
	  vec_generate(vec,vac_snk,traj,tsrc);
	  avg_vac_snk[tsrc]=vec_avg(vec);
	}
	for(int tsep=0; tsep<Lt; tsep++)
	{
	  for(int tsrc=0; tsrc<Lt; tsrc++)
	    std::get<0>(output[traj][tsep])-=avg_vac_src[tsrc]*avg_vac_snk[(tsrc+tsep)%Lt]*coeff;
	  std::get<0>(output[traj][tsep])/=fit_avg_fac;
	}
      }
    }

    bool cor_fit_generate_prototype(std::vector<std::vector<std::tuple<double,double,int> > > input, std::vector<std::vector<std::pair<double,int> > > &output)
    {
      output.resize(input.size());
      for(int i=0; i<output.size(); i++)
	output[i].resize(input[i].size());
      for(int i=0; i<output.size(); i++)
      {
	for(int j=0; j<output[i].size(); j++)
	{
	  output[i][j].first=std::get<0>(input[i][j]);
	  output[i][j].second=std::get<2>(input[i][j]);
	}
      }
    }

    bool vec_generate(std::vector<double> &output, std::vector<std::vector<std::pair<double,int> > > input, int idx)
    {
      output.resize(0);
      for(int t=0; t<input.size(); t++)
      {
	assert(idx<input[t].size());
	output.push_back(input[t][idx].first);
      }
      assert(output.size() == input.size());
    }

    void double_jk_fold_prototype(std::vector<std::vector<std::array<double,Lt> > > input, std::vector<std::vector<std::vector<double> > > &output, int bias)
    {
      int n_traj = input.size();
      output.resize(n_traj);
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
	assert(input[idx_I].size() == n_traj -1);
	output[idx_I].resize(n_traj-1);
	for(int idx_J=0; idx_J<n_traj-1; idx_J++)
	{
	  output[idx_I][idx_J].resize((Lt-bias)/2);
	  output[idx_I][idx_J][0] = input[idx_I][idx_J][0];
	  for(int t=1; t<(Lt-bias)/2; t++)
	    output[idx_I][idx_J][t] = 0.5 * (input[idx_I][idx_J][t] + input[idx_I][idx_J][Lt-bias-t]);
	}
      }
    }

    void double_jk_generate_prototype(std::vector<std::vector<std::array<double,Lt> > > &output, std::vector<std::pair<std::array<double,Lt>,int> > input)
    {
      std::array<double,Lt> sum;
      int n_traj = input.size();
      for(int t=0; t<Lt; t++)
      {
	sum[t] = 0.0;
	for(int traj=0; traj<n_traj; traj++)
	  sum[t] += input[traj].first[t];
      }
      output.resize(n_traj);
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
	output[idx_I].resize(n_traj);
	for(int idx_J=0; idx_J<n_traj; idx_J++)
	{
	  for(int t=0; t<Lt; t++)
	    output[idx_I][idx_J][t] = (sum[t] - input[idx_I].first[t] - input[idx_J].first[t]) / (n_traj -2.0);
	}
	output[idx_I].erase(output[idx_I].begin() + idx_I);
      }
    }

    void double_jk_generate_test()
    {
      if(this->pipi)
      {
	std::array<double,Lt> sum;
	int n_traj = s1_s1_pipiI_0.size();
	for(int t=0; t<Lt; t++)
	{
	  sum[t] = 0.0;
	  for(int traj=0; traj<n_traj; traj++)
	    sum[t] += s1_s1_pipiI_0[traj].first[t];
	}

	double_jk_pipiI_0.resize(n_traj);
	double_jk_pipiI_0_vac.resize(n_traj);
	for(int idx_I=0; idx_I<n_traj; idx_I++)
	{
	  double_jk_pipiI_0[idx_I].resize(n_traj);
	  double_jk_pipiI_0_vac[idx_I].resize(n_traj);
	  for(int idx_J=0; idx_J<n_traj; idx_J++)
	  {
	    for(int t=0; t<Lt; t++)
	    {
	      double_jk_pipiI_0[idx_I][idx_J][t] = (sum[t] - s1_s1_pipiI_0[idx_I].first[t] - s1_s1_pipiI_0[idx_J].first[t]) / (n_traj -2);
	      double_jk_pipiI_0_vac[idx_I][idx_J][t] = (sum[t] - s1_s1_pipiV[idx_I].first[t] - s1_s1_pipiV[idx_J].first[t]) / (n_traj -2);
	    }
	  }
	  double_jk_pipiI_0[idx_I].erase(double_jk_pipiI_0[idx_I].begin() + idx_I);
	  double_jk_pipiI_0_vac[idx_I].erase(double_jk_pipiI_0_vac[idx_I].begin() + idx_I);
	}
      }
    }

    void double_jk_fit_input_generate_prototype(std::vector<std::vector<std::array<double,Lt> > > input, std::vector<std::vector<std::pair<double,int> > > &output, std::vector<MatrixXd> &output_mat, bool corfit=true)
    {
      int n_traj = input.size();
      output.resize(n_traj);
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
        for(int idx_J=0; idx_J<n_traj-1; idx_J++)
        {
          for(int t=0; t<Lt; t++)
          {
            input[idx_I][idx_J][t] /= avg_fac;
          }
        }
      }
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
        output[idx_I].resize(Lt);
        for(int t=0; t<Lt; t++)
        {
          output[idx_I][t].second = t;
          output[idx_I][t].first = 0;
          for(int idx_J=0; idx_J<n_traj-1; idx_J++)
            output[idx_I][t].first += input[idx_I][idx_J][t];
          output[idx_I][t].first /= (n_traj - 1);
        }
      }
      output_mat.resize(n_traj);
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
        output_mat[idx_I].resize(Lt,Lt);
        for(int t1=0; t1<Lt; t1++)
        {
          for(int t2=0; t2<Lt; t2++)
          {
            output_mat[idx_I](t1,t2) = 0;
	    if(corfit || t1==t2)
	    {
              for(int idx_J=0; idx_J<n_traj-1; idx_J++)
                output_mat[idx_I](t1,t2) += (input[idx_I][idx_J][t1] - output[idx_I][t1].first) * (input[idx_I][idx_J][t2] - output[idx_I][t2].first);
              output_mat[idx_I](t1,t2) /= (n_traj - 1);
              output_mat[idx_I](t1,t2) *= (n_traj - 2);
	    }
          }
        }
      }
    }
    void double_jk_fit_input_generate_prototype(std::vector<std::vector<std::vector<double> > > input, std::vector<std::vector<std::pair<double,int> > > &output, std::vector<MatrixXd> &output_mat, bool corfit=true)
    {
      int n_traj = input.size();
      output.resize(n_traj);
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
	for(int idx_J=0; idx_J<n_traj-1; idx_J++)
	{
	  for(int t=0; t<input[idx_I][idx_J].size(); t++)
	  {
	    input[idx_I][idx_J][t] /= avg_fac;
	  }
	}
      }
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
	output[idx_I].resize(input[idx_I][0].size());
	for(int t=0; t<input[idx_I][0].size(); t++)
	{
	  output[idx_I][t].second = t;
	  output[idx_I][t].first = 0;
	  for(int idx_J=0; idx_J<n_traj-1; idx_J++)
	    output[idx_I][t].first += input[idx_I][idx_J][t];
	  output[idx_I][t].first /= (n_traj - 1);
	}
      }
      output_mat.resize(n_traj);
      for(int idx_I=0; idx_I<n_traj; idx_I++)
      {
	int tmax = input[idx_I][0].size();
	output_mat[idx_I].resize(tmax,tmax);
	for(int t1=0; t1<tmax; t1++)
	{
	  for(int t2=0; t2<tmax; t2++)
	  {
	    output_mat[idx_I](t1,t2) = 0;
	    if(corfit || t1==t2)
	    {
	      for(int idx_J=0; idx_J<n_traj-1; idx_J++)
	        output_mat[idx_I](t1,t2) += (input[idx_I][idx_J][t1] - output[idx_I][t1].first) * (input[idx_I][idx_J][t2] - output[idx_I][t2].first);
	      output_mat[idx_I](t1,t2) /= (n_traj - 1);
              output_mat[idx_I](t1,t2) *= (n_traj - 2);
	    }
	  }
	}
      }
    }

    //this function read fitted para from each fitted reduced ensemble
    template<int N_para>
    void get_vector_para_result(std::vector<std::array<double,N_para> > result_input, std::vector<double> &output, int n)
    {
      output.resize(0);
      assert(n < N_para);
      for(int i=0; i<result_input.size(); i++)
	output.push_back(result_input[i][n]);
    }

    //this function read const term from each fitted reduced ensemble, which is used for eff_mass plotting when we want to get rid of the effect of const
    void get_vector_const_three_para_result(std::vector<std::array<double,3> > result_input, std::vector<double> &output)
    {
      get_vector_para_result<3>(result_input, output, 2);
    }

    //this function generate average and error from rep_projed data on each time slice
    void rep_proj_average_prototype(std::vector<std::pair<std::array<double,Lt>,int> > input, std::array<std::pair<double,double>,Lt> &output, double bias=0)
    {
      int n_traj = input.size();
      for(int t=0; t<Lt; t++)
      {
	std::vector<double> tmp;
	tmp.resize(0);
	for(int traj=0; traj<n_traj; traj++)
	  tmp.push_back(input[traj].first[t]);
	output[t].first = vec_avg(tmp) - bias;
	output[t].second = vec_err(tmp);
      }
    }


    void double_jk_input_average_prototype(std::vector<std::vector<std::pair<double,int> > > input, std::vector<std::pair<double,double> > &output)
    {
      int n_traj = input.size();
      output.resize(input[0].size());
      for(int t=0; t<output.size(); t++)
      {
	std::vector<double> tmp;
	tmp.resize(0);
	for(int traj=0; traj<n_traj; traj++)
	  tmp.push_back(input[traj][t].first);
	output[t].first = vec_avg(tmp);
	output[t].second = jack_vec_err(tmp);
      }
    }

  public:

    static int rev_mom(int p)
    {
      assert(p>=0);
      assert(p<8);
      return p + 1 - 2 * (p % 2);
    }

    static double vec_avg(std::vector<double> input)
    {
      double tmp=0.0;
      for(int idx=0; idx<input.size(); idx++)
	tmp+=input[idx];
      tmp/=(input.size());
      return tmp;
    }

    static double vec_err(std::vector<double> input)
    {
      int num=input.size();
      double avg=vec_avg(input);
      double tmp=0.0;
      for(int i=0; i<num; i++)
	tmp+=pow((input[i]-avg),2.0);
      tmp /= (double(num)*(double(num)-1.0));
      tmp = sqrt(tmp);
      return tmp;
    }

    static double jack_vec_err(std::vector<double> input)
    {
      return (vec_err(input) * (input.size() -1 ) );
    }

    static double vec_cov_err(std::vector<double> vec1, std::vector<double> vec2)
    {
      int num = vec1.size();
      assert(vec2.size() == vec1.size());
      double tmp = 0;
      double avg1 = vec_avg(vec1);
      double avg2 = vec_avg(vec2);
      for(int i=0; i<num; i++)
	tmp += (vec1[i] - avg1) * (vec2[i] - avg2);
      tmp /= (num * num - num);
      return tmp;
    }

};























#endif

