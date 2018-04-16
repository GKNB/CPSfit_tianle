#ifndef _FIT_ADV_H
#define _FIT_ADV_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<tuple>
#include<vector>
#include<map>
#include<complex>

#include<Eigen/Dense>

#include "fit_candidate_func.h"
#include "lvm_fit.h"
#include "three_momentum_simple.h"
#include "luscherzeta_moving.h"
#include "GEVP_tianle.h"

using namespace std;
using namespace Eigen;
class fit_adv
{
  private:

    static const int    Lt=64;
    const double error_num=999999;
    const int    traj_step=4;
    const std::string pipi_work_dir[4] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_EOFA_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM_sep2" };
    const std::string work_dir[4] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/KEK_EOFA_STREAM1", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/KEK_EOFA_STREAM2", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_EOFA_STREAM_sigma"};
//    const std::string pipi_work_dir[3] = {"/auto/home8/ckelly/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_meas/all_inc_old_1187sloppy_252exact/sloppy", " ", " "};
//    const std::string pipi_work_dir[3] = {" ", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM", " "};
    const std::string comove_work_dir[3] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM", " ", " "};
//    const std::string comove_work_dir[1] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_EOFA_STREAM_No_fix_in_gamma5"};
//    const std::string comove_work_dir[3] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_EOFA_STREAM_Gamma5_topology_included", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/KEK_EOFA_STREAM1", " "};



//this line indicate the factor we use to devide average and error before fitting
    const double avg_fac = 100000000.0;
    const double err_fac = 100000000.0;
//    const double avg_fac = 1000000.0;
//    const double err_fac = 1000000.0;

//this line can be changed according to our need, but by doing so we need to change other things, careful if you want to change them!!!!!
//other changes if tdis is changed includes but not limited to, sortout data, folding process,
//other changes if tstep is changed includes but not limited to, 
    static const int tdis = 2;
    static const int tstep = 8;

//these are "fake" momentum container of pion and sigma
    const std::string pion_mom[8]       = {"222", "_2_2_2", "_222", "2_2_2", "2_22", "_22_2", "22_2", "_2_22"};
    const std::string pion_mom_chris[8] = {"111", "_1_1_1", "_111", "1_1_1", "1_11", "_11_1", "11_1", "_1_11"};
    const std::string sigma_mom[8]      = {"111", "_1_1_1", "_311", "3_1_1", "1_31", "_13_1", "11_3", "_1_13"};

    const std::array<int,3> type1_mom   = {{1,1,1}};
    const std::array<int,3> type2_mom   = {{1,1,0}};
    const std::array<int,3> type3_mom   = {{1,0,0}};

//this is the newly introduced mom_container which is almost the same as above, but they support most of operation Chris defined in threemomentum. Notice they are different!
//we can get pion_mom[i] by pionmom[i], and we can get underlying basemom by pionmom(i)
    pion_basemom_container pionmom;

//These two are coeff used for rep-proj
    MovingPiPiCase3_sdCoeff policysd;
    MovingPiPiCase3_ddCoeff policydd;

//these section decides what to do and what not to do
  private:
    bool pion=false, corr=false, corr_sub=false, scat=false, scat_sub=false, corr_sub_check=false, scat_sub_check=false, pipi=false, comove_pipi=false;

  public:

    void do_what(bool do_pion, bool do_corr, bool do_corr_sub, bool do_corr_sub_check, bool do_scat, bool do_scat_sub, bool do_scat_sub_check, bool do_pipi, bool do_comove_pipi = true)
    {
      if(do_pion)
	this->pion = true;
      if(do_corr)
	this->corr = true;
      if(do_corr_sub)
      {
	this->corr = true;
	this->corr_sub = true;
      }
      if(do_scat)
	this->scat = true;
      if(do_scat_sub)
      {
	this->scat_sub = true;
	this->scat = true;
      }
      if(do_corr_sub_check)
      {
	this->corr_sub_check = true;
	this->corr_sub = true;
	this->corr = true;
      }
      if(do_scat_sub_check)
      {
	this->scat_sub_check = true;
	this->scat_sub = true;
	this->scat = true;
      }
      if(do_pipi)
	this->pipi = true;
      if(do_comove_pipi)
      {
	this->comove_pipi = true;
      }
      cout<<"\nsignle_pion ? "<<this->pion
	  <<"\nsingle_sigma_nosub ? "<<this->corr<<"\nsingle_sigma_sub ? "<<this->corr_sub<<"\nsingle_sigma_sub_with_const ? "<<this->corr_sub_check
	  <<"\npipisigma_nosub ? "<<this->scat<<"\npipisigma_sub ? "<<this->scat_sub<<"\npipisigma_sub_with_const ? "<<this->scat_sub_check
	  <<"\npipi ? "<<this->pipi<<"\ncomove_pipi ? "<<this->comove_pipi  <<'\n';
    }


//this section collects the original data, and no information is lost here
//the name looks like "origin_xxxx"
  private:
    std::array<std::vector<std::pair<std::array<double,Lt*Lt>,int> >,4 >          origin_pion;
    std::array<std::vector<std::pair<std::array<double,Lt*Lt>,int> >,64>          origin_comove_pion;
    std::array<std::vector<std::pair<std::array<double,Lt*Lt>,int> >,64>          origin_corr;
    std::array<std::vector<std::pair<std::array<double,Lt   >,int> >,8 >          origin_self;
    std::array<std::vector<std::pair<std::array<double,Lt*Lt>,int> >,64>          origin_scat;              //ppiidx=pidx/8; psigidx=pidx%8

    std::array<std::vector<std::pair<std::array<double,Lt*Lt/tstep>,int> >,64>    origin_pipiC;             //psrc=pidx/8; psnk=pidx%8
    std::array<std::vector<std::pair<std::array<double,Lt*Lt/tstep>,int> >,64>    origin_pipiD;             //psrc=pidx/8; psnk=pidx%8
    std::array<std::vector<std::pair<std::array<double,Lt*Lt/tstep>,int> >,64>    origin_pipiR;             //psrc=pidx/8; psnk=pidx%8
    std::array<std::vector<std::pair<std::array<double,Lt   >,int> >,8 >          origin_pipiV;            

    std::array<std::vector<std::pair<std::array<double,Lt*Lt/tstep>,int> >,8>     origin_comove_type1_pipiC_old;
    std::array<std::vector<std::pair<std::array<double,Lt*Lt/tstep>,int> >,8>     origin_comove_type1_pipiD_old;
    std::array<std::vector<std::pair<std::array<double,Lt*Lt/tstep>,int> >,8>     origin_comove_type1_pipiR_old;
    std::array<std::vector<std::pair<std::array<double,Lt         >,int> >,8>     origin_comove_type1_pipiV_old;
    

  //here we use a different data structure to store type23 pipi, since how to treat them is a serious question
  //first vector means traj. second map means different momentum, key(int) stores a 4(2)-digit number which suggests the momentum of src and snk

    std::vector<std::map<int,std::array<double,Lt*Lt/tstep> > >                   origin_comove_type1_pipiC;
    std::vector<std::map<int,std::array<double,Lt*Lt/tstep> > >                   origin_comove_type1_pipiD;
    std::vector<std::map<int,std::array<double,Lt*Lt/tstep> > >                   origin_comove_type1_pipiR;

    std::vector<std::map<int,std::array<double,Lt*Lt/tstep> > >			  origin_comove_type2_pipiC;
    std::vector<std::map<int,std::array<double,Lt*Lt/tstep> > >     		  origin_comove_type2_pipiD;
    std::vector<std::map<int,std::array<double,Lt*Lt/tstep> > >                   origin_comove_type2_pipiR;

    std::vector<std::map<int,std::array<double,Lt*Lt/tstep> > >                   origin_comove_type3_pipiC;
    std::vector<std::map<int,std::array<double,Lt*Lt/tstep> > >                   origin_comove_type3_pipiD;
    std::vector<std::map<int,std::array<double,Lt*Lt/tstep> > >                   origin_comove_type3_pipiR;

    std::vector<std::map<int,std::array<double,Lt         > > >                   origin_comove_pipiV;
    std::vector<std::map<int,std::array<std::complex<double>,Lt> > >              origin_comove_pipiV_comp;
  public:
    
    bool read_origin_data(int traj_min, int traj_max, bool ground = true)
    {
      //type1_comove_pipi, which means all 3 component of p_CM have absolute value 1, where there will be 8 different cases
      for(int i=0; i<3; i++)
      {
        if(this->comove_pipi)
        {
          for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
          {
            std::map<int,std::array<double,Lt*Lt/tstep> > tmpC_type1;
            std::map<int,std::array<double,Lt*Lt/tstep> > tmpC_type2;
            std::map<int,std::array<double,Lt*Lt/tstep> > tmpC_type3;
            std::map<int,std::array<double,Lt*Lt/tstep> > tmpD_type1;
            std::map<int,std::array<double,Lt*Lt/tstep> > tmpD_type2;
            std::map<int,std::array<double,Lt*Lt/tstep> > tmpD_type3;
            std::map<int,std::array<double,Lt*Lt/tstep> > tmpR_type1;
            std::map<int,std::array<double,Lt*Lt/tstep> > tmpR_type2;
            std::map<int,std::array<double,Lt*Lt/tstep> > tmpR_type3;
            for(int p_src1 = 0; p_src1 < 8; p_src1++)
            {
              basemom psrc1 = pionmom(p_src1);
              for(int p_src2 = 0; p_src2 < 8; p_src2++)
              {
                basemom psrc2 = pionmom(p_src2);
                for(int p_snk1 = 0; p_snk1 < 8; p_snk1++)
                {
                  basemom psnk1 = pionmom(p_snk1);
                  for(int p_snk2 = 0; p_snk2 < 8; p_snk2++)
                  {
                    basemom psnk2 = pionmom(p_snk2);
                    if(psrc1 + psrc2 != -(psnk1 + psnk2))
                      continue;
                    basemom cmmom = psrc1 + psrc2;
                    int nz = cmmom.nzero();
                    int keycode=0;
                    pidx_to_code(keycode,p_src1,p_src2,p_snk1,p_snk2);

                    std::ostringstream fsC;
                    fsC << comove_work_dir[i] << "/traj_" << traj << "_FigureC_sep" << tdis << "_comove_pipi2pt" << "_srcmom1" << pionmom[p_src1]
                        << "_srcmom2" << pionmom[p_src2] << "_snkmom1" << pionmom[p_snk1] << "_snkmom2" << pionmom[p_snk2] << "_v2";
                    std::string str_tmp_C = fsC.str();

                    std::ostringstream fsD;
                    fsD << comove_work_dir[i] << "/traj_" << traj << "_FigureD_sep" << tdis << "_comove_pipi2pt" << "_srcmom1" << pionmom[p_src1]
                        << "_srcmom2" << pionmom[p_src2] << "_snkmom1" << pionmom[p_snk1] << "_snkmom2" << pionmom[p_snk2] << "_v2";
                    std::string str_tmp_D = fsD.str();

                    std::ostringstream fsR;
                    fsR << comove_work_dir[i] << "/traj_" << traj << "_FigureR_sep" << tdis << "_comove_pipi2pt" << "_srcmom1" << pionmom[p_src1]
                        << "_srcmom2" << pionmom[p_src2] << "_snkmom1" << pionmom[p_snk1] << "_snkmom2" << pionmom[p_snk2] << "_v2";
                    std::string str_tmp_R = fsR.str();

                    if(nz == 1)
                    {
                      read_single_file(str_tmp_C,keycode,tmpC_type2);
                      read_single_file(str_tmp_D,keycode,tmpD_type2);
                      read_single_file(str_tmp_R,keycode,tmpR_type2);
                    }
                    else if(nz == 2)
                    {
                      read_single_file(str_tmp_C,keycode,tmpC_type3);
                      read_single_file(str_tmp_D,keycode,tmpD_type3);
                      read_single_file(str_tmp_R,keycode,tmpR_type3);
                    }
                    else if(nz==0)
                    {
                      read_single_file(str_tmp_C,keycode,tmpC_type1);
                      read_single_file(str_tmp_D,keycode,tmpD_type1);
                      read_single_file(str_tmp_R,keycode,tmpR_type1);
                    }
                  }
                }
              }
            }
            std::cout << tmpC_type1.size() << ' ' << tmpD_type1.size() << ' ' << tmpR_type1.size() << ' ' 
                      << tmpC_type2.size() << ' ' << tmpD_type2.size() << ' ' << tmpR_type2.size() << ' '
                      << tmpC_type3.size() << ' ' << tmpD_type3.size() << ' ' << tmpR_type3.size() << '\n';
            if(tmpC_type1.size() == 8 && tmpC_type2.size() == 48 && tmpC_type3.size() == 96)
            {
              origin_comove_type1_pipiC.push_back(tmpC_type1);
              origin_comove_type2_pipiC.push_back(tmpC_type2);
              origin_comove_type3_pipiC.push_back(tmpC_type3);
              origin_comove_type1_pipiD.push_back(tmpD_type1);
              origin_comove_type2_pipiD.push_back(tmpD_type2);
              origin_comove_type3_pipiD.push_back(tmpD_type3);
              origin_comove_type1_pipiR.push_back(tmpR_type1);
              origin_comove_type2_pipiR.push_back(tmpR_type2);
              origin_comove_type3_pipiR.push_back(tmpR_type3);
            }
            else 
              assert(tmpC_type1.size() == 0 && tmpC_type2.size() == 0 && tmpC_type3.size() == 0);

            std::map<int,std::array<double,Lt> > tmpV;
            std::map<int,std::array<std::complex<double>,Lt> > tmpV_comp;
            for(int p_src=0; p_src<8; p_src++)
            {
              basemom psrc = pionmom(p_src);
              for(int p_snk=0; p_snk<8; p_snk++)
              {
                basemom psnk = pionmom(p_snk);
                int keycode=0;
                pidx_to_code(keycode,p_src,p_snk);
                std::ostringstream fs;
                fs << comove_work_dir[i] << "/traj_" << traj << "_FigureVdis_sep" << tdis << "_comove_pipi2pt" << "_srcmom" << pionmom[p_src]
                   << "_snkmom" << pionmom[p_snk] << "_v2";
                std::string str_tmp = fs.str();
                read_single_file(str_tmp,keycode,tmpV);
                read_single_file_comp(str_tmp,keycode,tmpV_comp);
              }
            }
            if(tmpV.size() == 64)
              origin_comove_pipiV.push_back(tmpV);
            else
              assert(tmpV.size() == 0);
            if(tmpV_comp.size() == 64)
              origin_comove_pipiV_comp.push_back(tmpV_comp);
            else
              assert(tmpV_comp.size() == 0);
          }
        }
      }
      for(int i=0; i<3; i++)
      {
	if(this->comove_pipi)
	{
	  for(int pidx = 0; pidx<8; pidx++)
	  {
	    std::string p_pi_src = pion_mom[pidx];
	    std::string p_pi_snk = pion_mom[rev_mom(pidx)];
	    for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
	    {
	      std::ostringstream fsC;
	      fsC << comove_work_dir[i] << "/traj_" << traj << "_FigureC_sep" << tdis << "_comove_pipi2pt" << "_srcmom1" << p_pi_src << "_srcmom2" << p_pi_src << "_snkmom1" << p_pi_snk
	          << "_snkmom2" << p_pi_snk;
	      std::string str_tmp_C = fsC.str();
	      std::pair<std::array<double,Lt*Lt/tstep>,int> tmpC;
	      if(read_single_file(str_tmp_C,traj,tmpC))
		origin_comove_type1_pipiC_old[pidx].push_back(tmpC);
	      else
		continue;

	      std::ostringstream fsD;
              fsD << comove_work_dir[i] << "/traj_" << traj << "_FigureD_sep" << tdis << "_comove_pipi2pt" << "_srcmom1" << p_pi_src << "_srcmom2" << p_pi_src << "_snkmom1" << p_pi_snk
                  << "_snkmom2" << p_pi_snk;
              std::string str_tmp_D = fsD.str();
              std::pair<std::array<double,Lt*Lt/tstep>,int> tmpD;
              if(read_single_file(str_tmp_D,traj,tmpD))
                origin_comove_type1_pipiD_old[pidx].push_back(tmpD);

	      std::ostringstream fsR;
              fsR << comove_work_dir[i] << "/traj_" << traj << "_FigureR_sep" << tdis << "_comove_pipi2pt" << "_srcmom1" << p_pi_src << "_srcmom2" << p_pi_src << "_snkmom1" << p_pi_snk
                  << "_snkmom2" << p_pi_snk;
              std::string str_tmp_R = fsR.str();
              std::pair<std::array<double,Lt*Lt/tstep>,int> tmpR;
              if(read_single_file(str_tmp_R,traj,tmpR))
                origin_comove_type1_pipiR_old[pidx].push_back(tmpR);
	    }
	  }

	  for(int pidx = 0; pidx<8; pidx++)
	  {
	    std::string p_pi_src = pion_mom[pidx];
	    for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
	    {
	      std::ostringstream fs;
	      fs << comove_work_dir[i] << "/traj_" << traj << "_FigureVdis_sep" << tdis << "_comove_pipi2pt" << "_srcmom" << p_pi_src << "_snkmom" << p_pi_src;
	      std::string str_tmp = fs.str();
	      std::pair<std::array<double,Lt>,int> tmp;
              if(read_single_file(str_tmp,traj,tmp))
                origin_comove_type1_pipiV_old[pidx].push_back(tmp);
	    }
	  }
	}
      }


//      for(int i=0; i<2; i++)
//      {
//	if(this->pion)
//	{
//	  for(int pidx=0; pidx<64; pidx++)
//	  {
//	    int psrc = pidx / 8;
//	    int psnk = pidx % 8;
//	    std::string p_pi_src = pion_mom[psrc];
//	    std::string p_pi_snk = pion_mom[psnk];
//	    for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
//	    {
//	      std::ostringstream fs;
//	      fs << work_dir[i] << "/traj_" << traj << "_comove_pioncorr_mom1" << p_pi_src << "_comove_pioncorr_mom2" << p_pi_snk << "_v2";
//	      std::string str_tmp = fs.str();
//	      std::pair<std::array<double,Lt*Lt>,int> tmp;
//	      if(read_single_file(str_tmp,traj,tmp))
//		origin_comove_pion[pidx].push_back(tmp);
//	    }
//	  }
//	}
//      }
      for(int i=0; i<4; i++)
      {
        //that's pioncorr
        if(this->pion)
        {  
	  for(int pidx=0; pidx<4; pidx++)
          {
	    std::string p_pi_src = pion_mom[pidx*2];
            for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
            {
              std::ostringstream fs;
              if(ground)
              {
                fs << work_dir[i] << "/traj_" << traj << "_pioncorr_mom" << p_pi_src << "_v2";
              }
              else
              {
                fs << work_dir[i] << "/traj_" << traj << "_pioncorr_mom" << p_pi_src << "_2s_v2";
              }
	      std::string str_tmp = fs.str();
              std::pair<std::array<double,Lt*Lt>,int> tmp;
              if(read_single_file(str_tmp,traj,tmp))
                origin_pion[pidx].push_back(tmp);
            }
          }
        }
        //that's sigmacorr
        if(this->corr)
        {
          for(int pidx=0; pidx<64; pidx++)
          {
    	    int psigsrc = pidx / 8;
  	    int psigsnk = pidx % 8;
	    std::string p_sigma_src = sigma_mom[psigsrc];
	    std::string p_sigma_snk = sigma_mom[psigsnk];
  	    for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
  	    {
  	      std::ostringstream fs;
              if(ground)
              {
  	        fs << work_dir[i] << "/traj_" << traj << "_sigmacorr_mom" << "psrc" << p_sigma_src << "psnk" << p_sigma_snk << "_v2";
              }
              else
              {
                fs << work_dir[i] << "/traj_" << traj << "_sigmacorr_mom" << "psrc" << p_sigma_src << "psnk" << p_sigma_snk << "_2s_v2";
              }
	      std::string str_tmp = fs.str();
  	      std::pair<std::array<double,Lt*Lt>,int> tmp;
  	      if(read_single_file(str_tmp,traj,tmp))
  	        origin_corr[pidx].push_back(tmp);
  	    }
          }
        }
        //that's sigmaself
        if(this->corr)
        {
          for(int pidx=0; pidx<8; pidx++)
          {
	    std::string p_sigma_src = sigma_mom[pidx];
  	    for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
  	    {
  	      std::ostringstream fs;
              if(ground)
              {
   	        fs << work_dir[i] << "/traj_" << traj << "_sigmaself_mom" << p_sigma_src << "_v2"; 
              }
              else
              {
                fs << work_dir[i] << "/traj_" << traj << "_sigmaself_mom" << p_sigma_src << "_2s_v2";
              }
	      std::string str_tmp = fs.str();
    	      std::pair<std::array<double,Lt>,int> tmp;
  	      if(read_single_file(str_tmp,traj,tmp))
  	        origin_self[pidx].push_back(tmp);
  	    }
          }
        }
        //that's pipisigma
        if(this->scat)
        {
          for(int pidx=0; pidx<64; pidx++)
          {
  	    int ppiidx = pidx / 8;
	    int psigidx = pidx % 8;
	    std::string p_pi_src = pion_mom[ppiidx];
	    std::string p_sigma_snk = sigma_mom[psigidx];
	    for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
	    {
	      std::ostringstream fs;
	      fs << work_dir[i] << "/traj_" << traj << "_pipitosigma_sigmawdagmom" << p_sigma_snk << "_pionmom" << p_pi_src << "_v2";
	      std::string str_tmp = fs.str();
	      std::pair<std::array<double,Lt*Lt>,int> tmp;
	      if(read_single_file(str_tmp,traj,tmp))
	        origin_scat[pidx].push_back(tmp);
	    }
	  }
        }

        //that's pipi_D/R/C_diag
        if(this->pipi)
        {
	  for(int pidx=0; pidx<64; pidx++)
  	  {
	    int psrc = pidx / 8;
	    int psnk = pidx % 8;
	    std::string p_pi_src = pion_mom_chris[psrc];
	    std::string p_pi_snk = pion_mom_chris[psnk];
	    for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
	    {
	      std::ostringstream fsC;
	      fsC << pipi_work_dir[i] << "/traj_" << traj << "_FigureC_sep" << tdis << "_mom" << p_pi_src << "_mom" << p_pi_snk;
	      std::string str_tmp_C = fsC.str();
	      std::pair<std::array<double,Lt*Lt/tstep>,int> tmpC;
	      if(read_single_file(str_tmp_C,traj,tmpC))
	        origin_pipiC[pidx].push_back(tmpC);
	      else
	        continue;

	      std::ostringstream fsD;
	      fsD << pipi_work_dir[i] << "/traj_" << traj << "_FigureD_sep" << tdis << "_mom" << p_pi_src << "_mom" << p_pi_snk;
  	      std::string str_tmp_D = fsD.str();
  	      std::pair<std::array<double,Lt*Lt/tstep>,int> tmpD;
  	      if(read_single_file(str_tmp_D,traj,tmpD))
  	        origin_pipiD[pidx].push_back(tmpD);
  
  	      std::ostringstream fsR;
  	      fsR << pipi_work_dir[i] << "/traj_" << traj << "_FigureR_sep" << tdis << "_mom" << p_pi_src << "_mom" << p_pi_snk;
  	      std::string str_tmp_R = fsR.str();
  	      std::pair<std::array<double,Lt*Lt/tstep>,int> tmpR;
  	      if(read_single_file(str_tmp_R,traj,tmpR))
  	        origin_pipiR[pidx].push_back(tmpR);
  	    }
  	  }
        }
        //that's pipi_V_diag
        if(this->pipi)
        {
  	  for(int pidx=0; pidx<8; pidx++)
	  {
	    std::string p_pi_src = pion_mom_chris[pidx];
	    for(int traj=traj_min; traj<=traj_max; traj+=traj_step)
	    {
	      std::ostringstream fs;
	      fs << pipi_work_dir[i] << "/traj_" << traj << "_FigureVdis_sep" << tdis << "_mom" << p_pi_src;
	      std::string str_tmp = fs.str();
	      std::pair<std::array<double,Lt>,int> tmp;
	      if(read_single_file(str_tmp,traj,tmp))
	        origin_pipiV[pidx].push_back(tmp);
	    }
	  }
        }
      }
    }

    bool output_origin_data()
    {
      if(this->pion)
	output_data<4,Lt*Lt>("origin_pion",origin_pion);
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
      if(this->comove_pipi)
      {
        output_data<Lt*Lt/tstep>("origin_comove_pipi_type2", origin_comove_type2_pipiC);
      }
    }

    //this function output the number of traj in each origin data and momentum
    void test_origin()
    {
      if(this->comove_pipi)
      {
        for(int i=0; i<8; i++)
        {
          std::cout << "i= "<< i << " C "<< this->origin_comove_type1_pipiC_old[i].size() <<'\n';
          std::cout << "i= "<< i << " D "<< this->origin_comove_type1_pipiD_old[i].size() <<'\n';
          std::cout << "i= "<< i << " R "<< this->origin_comove_type1_pipiR_old[i].size() <<'\n';
          std::cout << "i= "<< i << " V "<< this->origin_comove_type1_pipiV_old[i].size() <<'\n';
        }
        std::cout << "comove type1" << "C" << this->origin_comove_type1_pipiC.size() << '\n';
        std::cout << "comove type2" << "C" << this->origin_comove_type2_pipiC.size() << '\n';
        std::cout << "comove type3" << "C" << this->origin_comove_type3_pipiC.size() << '\n';
        std::cout << "comove type1" << "D" << this->origin_comove_type1_pipiD.size() << '\n';
        std::cout << "comove type2" << "D" << this->origin_comove_type2_pipiD.size() << '\n';
        std::cout << "comove type3" << "D" << this->origin_comove_type3_pipiD.size() << '\n';
        std::cout << "comove type1" << "R" << this->origin_comove_type1_pipiR.size() << '\n';
        std::cout << "comove type2" << "R" << this->origin_comove_type2_pipiR.size() << '\n';
        std::cout << "comove type3" << "R" << this->origin_comove_type3_pipiR.size() << '\n';
        std::cout << "comove" << "V" << this->origin_comove_pipiV.size() << '\n';
      }
    }

//this section generate tsrc averaging data for later calculation, also we sort out data that are useful for vacuum subtraction
//names look like "tavg_xxxx" and "tsep_x_xxxx", the former one is tavged and latter is for fixed tsep and has an index of tsrc
  private:
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,4 >    tavg_pion;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_comove_pion;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_corr;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_scat;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_pipiC;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_pipiD;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_pipiR;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    tavg_pipiV;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    noproj_pipiI_2;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,64>    noproj_nosub_pipiI_0;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,8 >    tavg_comove_type1_pipiC_old;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,8 >    tavg_comove_type1_pipiD_old;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,8 >    tavg_comove_type1_pipiR_old;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,8 >    tavg_comove_type1_pipiV_old;

    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type1_pipiC;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type2_pipiC;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type3_pipiC;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type1_pipiD;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type2_pipiD;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type3_pipiD;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type1_pipiR;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type2_pipiR;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type3_pipiR;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type1_pipiV;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type2_pipiV;
    std::vector<std::map<int,std::array<double,Lt> > >                   tavg_comove_type3_pipiV;

    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,4 >    tsep_4_pion;

  public:

    template<size_t N>
    void Calc_tavgDirectAvgErr(const std::vector<std::pair<std::array<double,N>,int> > &input, std::array<std::pair<double,double>,N> &output)
    {
      for(int t=0; t<N; t++)
      {
        double sum=0.0;
        double squsum=0.0;
        size_t ntraj = input.size();
        for(int traj=0; traj<ntraj; traj++)
        {
          sum += input[traj].first[t];
          squsum += input[traj].first[t] * input[traj].first[t];
        }
        sum /= static_cast<double>(ntraj);
        squsum -= sum * sum * static_cast<double>(ntraj);
        squsum /= (static_cast<double>(ntraj) * (static_cast<double>(ntraj) - 1.0));
        squsum = sqrt(squsum);
        output[t].first = sum;
        output[t].second = squsum;
      }
    }

//this output output the direct average, which means no jackknife is done
    template<size_t N>
    void OutputDirectAvgErr(std::string name, const std::array<std::pair<double,double>,N> &input, size_t n)
    {
      std::cout << name << '\n';
      for(size_t i=0; i<N; i++)
      {
        std::cout << "The " << n << " -th operator at time = " << i << " avg = " << input[i].first << " +- " << input[i].second << '\n';
      }
    }

    template<size_t N, size_t Ndiag>
    void tavgAvgErrWrapper(std::string name, const std::array<std::vector<std::pair<std::array<double,Lt>,int> >,Ndiag> &input)
    {
      for(size_t i=0; i<Ndiag; i++)
      {
        std::array<std::pair<double,double>,N> tmp;
        Calc_tavgDirectAvgErr(input[i],tmp);
        OutputDirectAvgErr(name,tmp,i);
      }
    }

    void Output_tavgAvgErr()
    {
      if(this->pipi)
      {
        tavgAvgErrWrapper<Lt,64>("tavg_pipiC",tavg_pipiC);
        tavgAvgErrWrapper<Lt,64>("tavg_pipiD",tavg_pipiD);
        tavgAvgErrWrapper<Lt,64>("tavg_pipiR",tavg_pipiR);
        tavgAvgErrWrapper<Lt,64>("tavg_pipiV",tavg_pipiV);
      }
      if(this->corr)
      {
        tavgAvgErrWrapper<Lt,64>("tavg_corr",tavg_corr);
      }
      if(this->scat)
      {
        tavgAvgErrWrapper<Lt,64>("tavg_scat",tavg_scat);
      }
    }

    bool tavg_generate()
    {
      std::cout << "Start tavg_generate\n" << std::endl;
      if(this->pion)            tavg_generate_prototype<64>(origin_comove_pion,tavg_comove_pion);
      if(this->pion)		tavg_generate_prototype<4 >(origin_pion,tavg_pion);
      if(this->corr)  		tavg_generate_prototype<64>(origin_corr,tavg_corr);
      if(this->scat)   		tavg_generate_prototype<64>(origin_scat,tavg_scat);
      if(this->pipi)
      {
	tavg_generate_prototype<64>(origin_pipiC,tavg_pipiC);
	tavg_generate_prototype<64>(origin_pipiD,tavg_pipiD);
	tavg_generate_prototype<64>(origin_pipiR,tavg_pipiR);
      }
      if(this->comove_pipi)
      {
	tavg_generate_prototype<8>(origin_comove_type1_pipiC_old,tavg_comove_type1_pipiC_old);
	tavg_generate_prototype<8>(origin_comove_type1_pipiD_old,tavg_comove_type1_pipiD_old);
	tavg_generate_prototype<8>(origin_comove_type1_pipiR_old,tavg_comove_type1_pipiR_old);
        tavg_generate_prototype(origin_comove_type1_pipiC,tavg_comove_type1_pipiC);
        tavg_generate_prototype(origin_comove_type2_pipiC,tavg_comove_type2_pipiC);
        tavg_generate_prototype(origin_comove_type3_pipiC,tavg_comove_type3_pipiC);
        tavg_generate_prototype(origin_comove_type1_pipiD,tavg_comove_type1_pipiD);
        tavg_generate_prototype(origin_comove_type2_pipiD,tavg_comove_type2_pipiD);
        tavg_generate_prototype(origin_comove_type3_pipiD,tavg_comove_type3_pipiD);
        tavg_generate_prototype(origin_comove_type1_pipiR,tavg_comove_type1_pipiR);
        tavg_generate_prototype(origin_comove_type2_pipiR,tavg_comove_type2_pipiR);
        tavg_generate_prototype(origin_comove_type3_pipiR,tavg_comove_type3_pipiR);
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
        for(int pidx=0; pidx<64; pidx++)
        {
          noproj_pipiI_2[pidx].resize(tavg_pipiD[pidx].size());
          noproj_nosub_pipiI_0[pidx].resize(tavg_pipiD[pidx].size());
          for(int traj=0; traj<noproj_pipiI_2[pidx].size(); traj++)
          {
            noproj_pipiI_2[pidx][traj].second = tavg_pipiD[pidx][traj].second;
            noproj_nosub_pipiI_0[pidx][traj].second = tavg_pipiD[pidx][traj].second;
            for(int t=0; t<Lt; t++)
            {
              noproj_pipiI_2[pidx][traj].first[t] = 2.0 * tavg_pipiD[pidx][traj].first[t] - 2.0 * tavg_pipiC[pidx][traj].first[t];
              noproj_nosub_pipiI_0[pidx][traj].first[t] = 2.0 * tavg_pipiD[pidx][traj].first[t] + tavg_pipiC[pidx][traj].first[t] - 6.0 * tavg_pipiR[pidx][traj].first[t] + 3.0 * tavg_pipiV[pidx][traj].first[t];
            }
          }
        }
      }
      if(this->comove_pipi)
      {
	for(int pidx=0; pidx<8; pidx++)
	{
	  tavg_comove_type1_pipiV_old[pidx].resize(origin_comove_type1_pipiV_old[0].size());
	  for(int traj=0; traj<tavg_comove_type1_pipiV_old[pidx].size(); traj++)
          {
	    tavg_comove_type1_pipiV_old[pidx][traj].second=origin_comove_type1_pipiV_old[0][traj].second;
	    for(int t=0; t<Lt; t++)
            {
	      tavg_comove_type1_pipiV_old[pidx][traj].first[t]=0.0;
	      for(int tsrc=0; tsrc<Lt; tsrc++)
              {
		int p_rev = rev_mom(pidx);
		int tnew = (tsrc+t+tdis)%Lt;
		tavg_comove_type1_pipiV_old[pidx][traj].first[t] += origin_comove_type1_pipiV_old[pidx][traj].first[tsrc] * origin_comove_type1_pipiV_old[p_rev][traj].first[tnew];
	      }
	      tavg_comove_type1_pipiV_old[pidx][traj].first[t]/=Lt;
	    }
	  }
	}

        tavg_comove_type1_pipiV.resize(origin_comove_pipiV.size());
        tavg_comove_type2_pipiV.resize(origin_comove_pipiV.size());
        tavg_comove_type3_pipiV.resize(origin_comove_pipiV.size());
        for(int traj=0; traj<origin_comove_pipiV.size(); traj++)
        {
          for(auto it1 = tavg_comove_type1_pipiC[traj].cbegin(); it1!=tavg_comove_type1_pipiC[traj].cend(); it1++)
          {
            assert(tavg_comove_type1_pipiV[traj].find(it1->first)==tavg_comove_type1_pipiV[traj].end());
            int psrc1, psrc2, psnk1, psnk2;
            int srccode, snkcode;
            code_to_pidx(it1->first,psrc1,psrc2,psnk1,psnk2);
            pidx_to_code(srccode,psrc2,psrc1);
            pidx_to_code(snkcode,psnk1,psnk2);
            for(int t=0; t<Lt; t++)
            {
              tavg_comove_type1_pipiV[traj][it1->first][t] = 0.0;
              for(int tsrc=0; tsrc<Lt; tsrc++)
              {
                int tnew = (tsrc + t + tdis) % Lt;
                tavg_comove_type1_pipiV[traj][it1->first][t] += origin_comove_pipiV[traj][srccode][tsrc] * origin_comove_pipiV[traj][snkcode][tnew];
//                std::complex<double> tmp = origin_comove_pipiV_comp[traj][srccode][tsrc] * origin_comove_pipiV_comp[traj][snkcode][tnew];
//                tavg_comove_type1_pipiV[traj][it1->first][t] += tmp.real();
              }
              tavg_comove_type1_pipiV[traj][it1->first][t] /= Lt;
            }
          }

          for(auto it2 = tavg_comove_type2_pipiC[traj].cbegin(); it2!=tavg_comove_type2_pipiC[traj].cend(); it2++)
          {
            assert(tavg_comove_type2_pipiV[traj].find(it2->first)==tavg_comove_type2_pipiV[traj].end());
            int psrc1, psrc2, psnk1, psnk2;
            int srccode, snkcode;
            code_to_pidx(it2->first,psrc1,psrc2,psnk1,psnk2);
            pidx_to_code(srccode,psrc2,psrc1);
            pidx_to_code(snkcode,psnk1,psnk2);
            for(int t=0; t<Lt; t++)
            {
              tavg_comove_type2_pipiV[traj][it2->first][t] = 0.0;
              for(int tsrc=0; tsrc<Lt; tsrc++)
              {
                int tnew = (tsrc + t + tdis) % Lt;
                tavg_comove_type2_pipiV[traj][it2->first][t] += origin_comove_pipiV[traj][srccode][tsrc] * origin_comove_pipiV[traj][snkcode][tnew];
              }
              tavg_comove_type2_pipiV[traj][it2->first][t] /= Lt;
            }
          }

          for(auto it3 = tavg_comove_type3_pipiC[traj].cbegin(); it3!=tavg_comove_type3_pipiC[traj].cend(); it3++)
          {
            assert(tavg_comove_type3_pipiV[traj].find(it3->first)==tavg_comove_type3_pipiV[traj].end());
            int psrc1, psrc2, psnk1, psnk2;
            int srccode, snkcode;
            code_to_pidx(it3->first,psrc1,psrc2,psnk1,psnk2);
            pidx_to_code(srccode,psrc2,psrc1);
            pidx_to_code(snkcode,psnk1,psnk2);
            for(int t=0; t<Lt; t++)
            {
              tavg_comove_type3_pipiV[traj][it3->first][t] = 0.0;
              for(int tsrc=0; tsrc<Lt; tsrc++)
              {
                int tnew = (tsrc + t + tdis) % Lt;
                tavg_comove_type3_pipiV[traj][it3->first][t] += origin_comove_pipiV[traj][srccode][tsrc] * origin_comove_pipiV[traj][snkcode][tnew];
              }
              tavg_comove_type3_pipiV[traj][it3->first][t] /= Lt;
            }
          }
        }
      }
      std::cout << "Finish tavg_generate\n" << std::endl;
    }

    //this function pull out vacuuum data from propagator, but we don't need it anymore since we always generate vac-diag seperately
    bool vacuum_sortout()
    {
      if(this->scat_sub)	vacuum_sortout_prototype<4>(origin_pion,tsep_4_pion,4);
    }

    bool output_tavg_data()
    {
      for(int pidx=0; pidx<8; pidx++)
        cout<<"testing size for debug!!!! pidx= "<<pidx<<origin_pipiV[pidx].size()<<'\n';
      if(this->pion)
	output_data<4,Lt>("origin->tavg_pion",tavg_pion);
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

    bool output_sortout_data()
    {
      if(this->scat_sub)
	output_data<4,Lt>("origin_tsep_4_pion",tsep_4_pion);
    }

    bool tavg_test()
    {
      if(this->comove_pipi)
      {
        for(int traj=0; traj<tavg_comove_type2_pipiC.size(); traj++)
        {
          cout << tavg_comove_type1_pipiC[traj].size() << ' ';
          cout << tavg_comove_type2_pipiC[traj].size() << ' ';
          cout << tavg_comove_type3_pipiC[traj].size() << ' ';
          cout << tavg_comove_type1_pipiD[traj].size() << ' ';
          cout << tavg_comove_type2_pipiD[traj].size() << ' ';
          cout << tavg_comove_type3_pipiD[traj].size() << ' ';
          cout << tavg_comove_type1_pipiR[traj].size() << ' ';
          cout << tavg_comove_type2_pipiR[traj].size() << ' ';
          cout << tavg_comove_type3_pipiR[traj].size() << ' ';
          cout << tavg_comove_type1_pipiV[traj].size() << ' ';
          cout << tavg_comove_type2_pipiV[traj].size() << ' ';
          cout << tavg_comove_type3_pipiV[traj].size() << ' ';
        }
        output_data<Lt>("tavg_comove_pipi_type1D", tavg_comove_type1_pipiD);
        output_data<Lt>("tavg_comove_pipi_type2C", tavg_comove_type2_pipiC);
        output_data<Lt>("tavg_comove_pipi_type3R", tavg_comove_type3_pipiR);
        output_data<Lt>("tavg_comove_pipi_type1V", tavg_comove_type1_pipiV);
        output_data<Lt>("tavg_comove_pipi_type2V", tavg_comove_type2_pipiV);
        output_data<Lt>("tavg_comove_pipi_type3V", tavg_comove_type3_pipiV);
        cout <<'\n';
      }
    }
//this is a test section, which trys to calculate if comove pion will have less error compare with rest pion

  private:
    std::array<std::array<double,2>,64> 	comove_pion_avg_err;

  public:
    bool comove_pion_avg_err_calculate()
    {
      for(int pidx=0; pidx<64; pidx++)
      {
	comove_pion_avg_err[pidx].fill(0.0);
	std::vector<double> tmp;
	for(int i=0; i<tavg_comove_pion[pidx].size(); i++)
	  tmp.push_back(tavg_comove_pion[pidx][i].first[4]);
	comove_pion_avg_err[pidx][0] = vec_avg(tmp);
	comove_pion_avg_err[pidx][1] = vec_err(tmp);
	cout << "comove_pion_pidx = "<< pidx << "\t_avg = " << comove_pion_avg_err[pidx][0] << "    _err = " << comove_pion_avg_err[pidx][1]<<'\n';
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
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiC_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_sd_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_dd_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiD_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_sd_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_dd_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiR_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_sd_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_dd_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiV_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_sd_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_dd_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiI_2;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiI_2;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiI_2;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiI_2;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_2_old;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,8>   comove_type1_pipiI_2_seperate_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_2_combine_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_2_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiI_2_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_2_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_2_sd_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_2_dd_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   s1_s1_pipiI_0;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_s2_pipiI_0;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_s3_pipiI_0;
    std::vector<std::pair<std::array<double,Lt>,int> >   d1_d1_pipiI_0;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_0_old;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,8>   comove_type1_pipiI_0_seperate_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_0_combine_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_0_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiI_0_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_0_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_0_sd_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_0_dd_combine_test;

    std::vector<std::pair<std::array<double,Lt>,int> >   s1_tsep_4_pion;
    std::vector<std::pair<std::array<double,Lt>,int> >   s2_tsep_4_pion;
    std::vector<std::pair<std::array<double,Lt>,int> >   s3_tsep_4_pion;

    std::array<std::pair<double,double>,Lt>		 s1_s1_corr_result;
    std::array<std::pair<double,double>,Lt>		 s1_s1_scat_result;
    std::array<std::pair<double,double>,Lt>		 s1_s1_pipiC_result;
    std::array<std::pair<double,double>,Lt>              s1_s1_pipiD_result;
    std::array<std::pair<double,double>,Lt>              s1_s1_pipiR_result;
    std::array<std::pair<double,double>,Lt>		 s1_s1_pipiV_result;
    std::array<std::pair<double,double>,Lt>              s2_s2_pipiC_result;
    std::array<std::pair<double,double>,Lt>              s2_s2_pipiD_result;
    std::array<std::pair<double,double>,Lt>              s2_s2_pipiR_result;
    std::array<std::pair<double,double>,Lt>              s2_s2_pipiV_result;
    std::array<std::pair<double,double>,Lt>              s3_s3_pipiC_result;
    std::array<std::pair<double,double>,Lt>              s3_s3_pipiD_result;
    std::array<std::pair<double,double>,Lt>              s3_s3_pipiR_result;
    std::array<std::pair<double,double>,Lt>              s3_s3_pipiV_result;
    std::array<std::pair<double,double>,Lt>              d1_d1_pipiC_result;
    std::array<std::pair<double,double>,Lt>              d1_d1_pipiD_result;
    std::array<std::pair<double,double>,Lt>              d1_d1_pipiR_result;
    std::array<std::pair<double,double>,Lt>              d1_d1_pipiV_result;
    std::array<std::pair<double,double>,Lt> 		 s1_s1_pipiI_2_result;
    std::array<std::pair<double,double>,Lt>              s2_s2_pipiI_2_result;
    std::array<std::pair<double,double>,Lt>              s3_s3_pipiI_2_result;
    std::array<std::pair<double,double>,Lt>              d1_d1_pipiI_2_result;
    

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
      if(this->scat_sub)
      {
        std::array<double,4> s1_coeff_4;
	std::array<double,4> s2_coeff_4;
	std::array<double,4> s3_coeff_4;
        s1_coeff_4.fill(1.0/4.0);
	s2_coeff_4.fill(0);
	s2_coeff_4[0] = 1.0;
	s3_coeff_4.fill(1.0/3.0);
	s3_coeff_4[0] = 0.0;
        rep_proj_prototype<4>(tsep_4_pion,s1_tsep_4_pion,s1_coeff_4);
	rep_proj_prototype<4>(tsep_4_pion,s2_tsep_4_pion,s2_coeff_4);
	rep_proj_prototype<4>(tsep_4_pion,s3_tsep_4_pion,s3_coeff_4);
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
      if(this->comove_pipi)
      {
        for(int pidx=0; pidx<8; pidx++)
        {
  	  comove_type1_pipiI_2_seperate_old[pidx].resize(tavg_comove_type1_pipiC_old[pidx].size());
	  comove_type1_pipiI_0_seperate_old[pidx].resize(tavg_comove_type1_pipiC_old[pidx].size());
	  for(int traj=0; traj<tavg_comove_type1_pipiC_old[pidx].size(); traj++)
	  {
	    comove_type1_pipiI_2_seperate_old[pidx][traj].second=tavg_comove_type1_pipiC_old[pidx][traj].second;
	    comove_type1_pipiI_0_seperate_old[pidx][traj].second=tavg_comove_type1_pipiC_old[pidx][traj].second;
	    for(int t=0; t<Lt; t++)
	    {
	      comove_type1_pipiI_2_seperate_old[pidx][traj].first[t] = 2.0 * tavg_comove_type1_pipiD_old[pidx][traj].first[t] - 2.0 * tavg_comove_type1_pipiC_old[pidx][traj].first[t];
	      comove_type1_pipiI_0_seperate_old[pidx][traj].first[t] = 2.0 * tavg_comove_type1_pipiD_old[pidx][traj].first[t] + tavg_comove_type1_pipiC_old[pidx][traj].first[t] - 6.0 * tavg_comove_type1_pipiR_old[pidx][traj].first[t] + 3.0 * tavg_comove_type1_pipiV_old[pidx][traj].first[t];
	    }
  	  }
        }
        comove_type1_pipiI_2_combine_old.insert(comove_type1_pipiI_2_combine_old.end(), comove_type1_pipiI_2_seperate_old[0].begin(), comove_type1_pipiI_2_seperate_old[0].end());
        comove_type1_pipiI_0_combine_old.insert(comove_type1_pipiI_0_combine_old.end(), comove_type1_pipiI_0_seperate_old[0].begin(), comove_type1_pipiI_0_seperate_old[0].end());
        for(int traj=0; traj<comove_type1_pipiI_2_combine_old.size(); traj++)
        {
          for(int t=0; t<Lt; t++)
          {
            for(int pidx=1; pidx<8; pidx++)
            {
              comove_type1_pipiI_2_combine_old[traj].first[t] += comove_type1_pipiI_2_seperate_old[pidx][traj].first[t];
              comove_type1_pipiI_0_combine_old[traj].first[t] += comove_type1_pipiI_0_seperate_old[pidx][traj].first[t];
            }
            comove_type1_pipiI_2_combine_old[traj].first[t] /= 8.0;
            comove_type1_pipiI_0_combine_old[traj].first[t] /= 8.0;
          }
        }
        rep_proj_prototype(tavg_comove_type1_pipiC, comove_type1_pipiC);
        rep_proj_prototype(tavg_comove_type2_pipiC, comove_type2_pipiC);
        rep_proj_prototype(tavg_comove_type3_pipiC, comove_type3_pipiC);
        rep_proj_advance(tavg_comove_type3_pipiC, comove_type3_sd_pipiC, policysd);
        rep_proj_advance(tavg_comove_type3_pipiC, comove_type3_dd_pipiC, policydd);
        rep_proj_prototype(tavg_comove_type1_pipiD, comove_type1_pipiD);
        rep_proj_prototype(tavg_comove_type2_pipiD, comove_type2_pipiD);
        rep_proj_prototype(tavg_comove_type3_pipiD, comove_type3_pipiD);
        rep_proj_advance(tavg_comove_type3_pipiD, comove_type3_sd_pipiD, policysd);
        rep_proj_advance(tavg_comove_type3_pipiD, comove_type3_dd_pipiD, policydd);
        rep_proj_prototype(tavg_comove_type1_pipiR, comove_type1_pipiR);
        rep_proj_prototype(tavg_comove_type2_pipiR, comove_type2_pipiR);
        rep_proj_prototype(tavg_comove_type3_pipiR, comove_type3_pipiR);
        rep_proj_advance(tavg_comove_type3_pipiR, comove_type3_sd_pipiR, policysd);
        rep_proj_advance(tavg_comove_type3_pipiR, comove_type3_dd_pipiR, policydd);
        rep_proj_prototype(tavg_comove_type1_pipiV, comove_type1_pipiV);
        rep_proj_prototype(tavg_comove_type2_pipiV, comove_type2_pipiV);
        rep_proj_prototype(tavg_comove_type3_pipiV, comove_type3_pipiV);
        rep_proj_advance(tavg_comove_type3_pipiV, comove_type3_sd_pipiV, policysd);
        rep_proj_advance(tavg_comove_type3_pipiV, comove_type3_dd_pipiV, policydd);

        comove_type1_pipiI_2_combine_test.resize(comove_type1_pipiC.size());
        comove_type2_pipiI_2_combine_test.resize(comove_type2_pipiC.size());
        comove_type3_pipiI_2_combine_test.resize(comove_type3_pipiC.size());
        comove_type3_pipiI_2_sd_combine_test.resize(comove_type3_sd_pipiC.size());
        comove_type3_pipiI_2_dd_combine_test.resize(comove_type3_dd_pipiC.size());
        comove_type1_pipiI_0_combine_test.resize(comove_type1_pipiC.size());
        comove_type2_pipiI_0_combine_test.resize(comove_type2_pipiC.size());
        comove_type3_pipiI_0_combine_test.resize(comove_type3_pipiC.size());
        comove_type3_pipiI_0_sd_combine_test.resize(comove_type3_sd_pipiC.size());
        comove_type3_pipiI_0_dd_combine_test.resize(comove_type3_dd_pipiC.size());
        for(int traj=0; traj<comove_type2_pipiC.size(); traj++)
        {
          comove_type1_pipiI_2_combine_test[traj].second = comove_type1_pipiC[traj].second;
          comove_type2_pipiI_2_combine_test[traj].second = comove_type2_pipiC[traj].second;
          comove_type3_pipiI_2_combine_test[traj].second = comove_type3_pipiC[traj].second;
          comove_type3_pipiI_2_sd_combine_test[traj].second = comove_type3_sd_pipiC[traj].second;
          comove_type3_pipiI_2_dd_combine_test[traj].second = comove_type3_dd_pipiC[traj].second;
          comove_type1_pipiI_0_combine_test[traj].second = comove_type1_pipiC[traj].second;
          comove_type2_pipiI_0_combine_test[traj].second = comove_type2_pipiC[traj].second;
          comove_type3_pipiI_0_combine_test[traj].second = comove_type3_pipiC[traj].second;
          comove_type3_pipiI_0_sd_combine_test[traj].second = comove_type3_sd_pipiC[traj].second;
          comove_type3_pipiI_0_dd_combine_test[traj].second = comove_type3_dd_pipiC[traj].second;
          for(int t=0; t<Lt; t++)
          {
            comove_type1_pipiI_2_combine_test[traj].first[t] = 2.0 * comove_type1_pipiD[traj].first[t] - 2.0 * comove_type1_pipiC[traj].first[t];
            comove_type2_pipiI_2_combine_test[traj].first[t] = 2.0 * comove_type2_pipiD[traj].first[t] - 2.0 * comove_type2_pipiC[traj].first[t];
            comove_type3_pipiI_2_combine_test[traj].first[t] = 2.0 * comove_type3_pipiD[traj].first[t] - 2.0 * comove_type3_pipiC[traj].first[t];
            comove_type3_pipiI_2_sd_combine_test[traj].first[t] = 2.0 * comove_type3_sd_pipiD[traj].first[t] - 2.0 * comove_type3_sd_pipiC[traj].first[t];
            comove_type3_pipiI_2_dd_combine_test[traj].first[t] = 2.0 * comove_type3_dd_pipiD[traj].first[t] - 2.0 * comove_type3_dd_pipiC[traj].first[t];
            comove_type1_pipiI_0_combine_test[traj].first[t] = 2.0 * comove_type1_pipiD[traj].first[t] + comove_type1_pipiC[traj].first[t] - 6.0 * comove_type1_pipiR[traj].first[t] + 3.0 * comove_type1_pipiV[traj].first[t];
            comove_type2_pipiI_0_combine_test[traj].first[t] = 2.0 * comove_type2_pipiD[traj].first[t] + comove_type2_pipiC[traj].first[t] - 6.0 * comove_type2_pipiR[traj].first[t] + 3.0 * comove_type2_pipiV[traj].first[t];
            comove_type3_pipiI_0_combine_test[traj].first[t] = 2.0 * comove_type3_pipiD[traj].first[t] + comove_type3_pipiC[traj].first[t] - 6.0 * comove_type3_pipiR[traj].first[t] + 3.0 * comove_type3_pipiV[traj].first[t];
            comove_type3_pipiI_0_sd_combine_test[traj].first[t] = 2.0 * comove_type3_sd_pipiD[traj].first[t] + comove_type3_sd_pipiC[traj].first[t] - 6.0 * comove_type3_sd_pipiR[traj].first[t] + 3.0 * comove_type3_sd_pipiV[traj].first[t];
            comove_type3_pipiI_0_dd_combine_test[traj].first[t] = 2.0 * comove_type3_dd_pipiD[traj].first[t] + comove_type3_dd_pipiC[traj].first[t] - 6.0 * comove_type3_dd_pipiR[traj].first[t] + 3.0 * comove_type3_dd_pipiV[traj].first[t];
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
      if(this->scat_sub)
	output_data<Lt>("swave1_tsep_4_pion",s1_tsep_4_pion);
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
      if(this->comove_pipi)
      {
        for(int traj=0; traj<comove_type1_pipiI_0_combine_old.size(); traj++)
        {
          for(int t=0; t<Lt; t++)
            cout << "TEST 2 COMOVE TYPE1: old  " << comove_type1_pipiI_2_combine_old[traj].first[t] << "   new  " << comove_type1_pipiI_2_combine_test[traj].first[t] << '\n';
        }
        output_data<Lt>("comove_type1_pipiC",comove_type1_pipiC);
        output_data<Lt>("comove_type2_pipiD",comove_type2_pipiD);
        output_data<Lt>("comove_type3_pipiV",comove_type3_pipiV);
        output_data<Lt>("comove_type1_pipiI_0_combine_test",comove_type1_pipiI_0_combine_test);
        output_data<Lt>("comove_type2_pipiI_2_combine_test",comove_type2_pipiI_2_combine_test);
        output_data<Lt>("comove_type3_pipiI_2_s->d_combine_test",comove_type3_pipiI_2_sd_combine_test);
      }
    }

    //this section calculates the average and error of raw data (not sampled) and output them 
    void rep_proj_average()
    {
      if(this->corr_sub)
        rep_proj_average_prototype(s1_s1_corr, s1_s1_corr_result, final_double_jk_corr[2].first * avg_fac);
      if(this->scat_sub)
        rep_proj_average_prototype(s1_s1_scat, s1_s1_scat_result, final_double_jk_scat[2].first * avg_fac);
      if(this->pipi)
      {
        rep_proj_average_prototype(s1_s1_pipiC, s1_s1_pipiC_result);
        rep_proj_average_prototype(s1_s1_pipiD, s1_s1_pipiD_result);
        rep_proj_average_prototype(s1_s1_pipiR, s1_s1_pipiR_result);
        rep_proj_average_prototype(s1_s1_pipiV, s1_s1_pipiV_result);
        rep_proj_average_prototype(s2_s2_pipiC, s2_s2_pipiC_result);
        rep_proj_average_prototype(s2_s2_pipiD, s2_s2_pipiD_result);
        rep_proj_average_prototype(s2_s2_pipiR, s2_s2_pipiR_result);
        rep_proj_average_prototype(s2_s2_pipiV, s2_s2_pipiV_result);
        rep_proj_average_prototype(s3_s3_pipiC, s3_s3_pipiC_result);
        rep_proj_average_prototype(s3_s3_pipiD, s3_s3_pipiD_result);
        rep_proj_average_prototype(s3_s3_pipiR, s3_s3_pipiR_result);
        rep_proj_average_prototype(s3_s3_pipiV, s3_s3_pipiV_result);
        rep_proj_average_prototype(d1_d1_pipiC, d1_d1_pipiC_result);
        rep_proj_average_prototype(d1_d1_pipiD, d1_d1_pipiD_result);
        rep_proj_average_prototype(d1_d1_pipiR, d1_d1_pipiR_result);
        rep_proj_average_prototype(d1_d1_pipiV, d1_d1_pipiV_result);
        rep_proj_average_prototype(s1_s1_pipiI_2, s1_s1_pipiI_2_result);
        rep_proj_average_prototype(s2_s2_pipiI_2, s2_s2_pipiI_2_result);
        rep_proj_average_prototype(s3_s3_pipiI_2, s3_s3_pipiI_2_result);
        rep_proj_average_prototype(d1_d1_pipiI_2, d1_d1_pipiI_2_result);
      }
    }

    void output_rep_proj_average()
    {
      if(this->corr)
        output_data("s1_s1_corr_rep_proj_result(average of raw data)", s1_s1_corr_result);
      if(this->scat)
        output_data("s1_s1_scat_rep_proj_result(average of raw data)", s1_s1_scat_result);
      if(this->pipi)
      {
        output_data("s1_s1_pipiC_rep_proj_result(average of raw data)", s1_s1_pipiC_result);
        output_data("s1_s1_pipiD_rep_proj_result(average of raw data)", s1_s1_pipiD_result);
        output_data("s1_s1_pipiR_rep_proj_result(average of raw data)", s1_s1_pipiR_result);
        output_data("s1_s1_pipiV_rep_proj_result(average of raw data)", s1_s1_pipiV_result);
        output_data("s2_s2_pipiC_rep_proj_result(average of raw data)", s2_s2_pipiC_result);
        output_data("s2_s2_pipiD_rep_proj_result(average of raw data)", s2_s2_pipiD_result);
        output_data("s2_s2_pipiR_rep_proj_result(average of raw data)", s2_s2_pipiR_result);
        output_data("s2_s2_pipiV_rep_proj_result(average of raw data)", s2_s2_pipiV_result);
        output_data("s3_s3_pipiC_rep_proj_result(average of raw data)", s3_s3_pipiC_result);
        output_data("s3_s3_pipiD_rep_proj_result(average of raw data)", s3_s3_pipiD_result);
        output_data("s3_s3_pipiR_rep_proj_result(average of raw data)", s3_s3_pipiR_result);
        output_data("s3_s3_pipiV_rep_proj_result(average of raw data)", s3_s3_pipiV_result);
        output_data("d1_d1_pipiC_rep_proj_result(average of raw data)", d1_d1_pipiC_result);
        output_data("d1_d1_pipiD_rep_proj_result(average of raw data)", d1_d1_pipiD_result);
        output_data("d1_d1_pipiR_rep_proj_result(average of raw data)", d1_d1_pipiR_result);
        output_data("d1_d1_pipiV_rep_proj_result(average of raw data)", d1_d1_pipiV_result);
        output_data("s1_s1_pipiI_2_rep_proj_result(average of raw data)", s1_s1_pipiI_2_result);
        output_data("s2_s2_pipiI_2_rep_proj_result(average of raw data)", s2_s2_pipiI_2_result);
        output_data("s3_s3_pipiI_2_rep_proj_result(average of raw data)", s3_s3_pipiI_2_result);
        output_data("d1_d1_pipiI_2_rep_proj_result(average of raw data)", d1_d1_pipiI_2_result);
      }
    }

//here are the new, double jackknife method of treating data, and they should generate the same result as Chris's
  private:
    std::array<std::vector<std::vector<std::array<double,Lt> > >,4>  double_jk_pion;

    std::array<std::vector<std::vector<std::array<double,Lt> > >,8>  double_jk_comove_type1_pipiI_2_seperate_old;
    std::array<std::vector<std::vector<std::array<double,Lt> > >,8>  double_jk_comove_type1_pipiI_0_seperate_old;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type1_pipiI_2_combine_old;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type1_pipiI_0_combine_old;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type1_pipiI_2_combine;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type1_pipiI_0_combine;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type2_pipiI_2_combine;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type2_pipiI_0_combine;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type3_pipiI_2_combine;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type3_pipiI_2_sd_combine;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type3_pipiI_2_dd_combine;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type3_pipiI_0_combine;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type3_pipiI_0_sd_combine;
    std::vector<std::vector<std::array<double,Lt> > >           double_jk_comove_type3_pipiI_0_dd_combine;

    std::array<std::vector<std::vector<std::array<double,Lt> > >,64> double_jk_noproj_pipiI_2;
    std::array<std::vector<std::vector<std::array<double,Lt> > >,64> double_jk_noproj_nosub_pipiI_0;
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

    std::array<std::vector<std::vector<std::array<double,Lt> > >,64> double_jk_noproj_nosub_corr;
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

    std::array<std::vector<std::vector<std::vector<double> > >,4>  double_jk_pion_fold;
    std::array<std::vector<std::vector<std::vector<double> > >,64> double_jk_noproj_pipiI_2_fold;
    std::array<std::vector<std::vector<std::vector<double> > >,64> double_jk_noproj_nosub_pipiI_0_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_2_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_2_fold_s2_s2;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_2_fold_s3_s3;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_2_fold_d1_d1;
    std::array<std::vector<std::vector<std::vector<double> > >,8>  double_jk_comove_type1_pipiI_2_seperate_fold_old;
    std::array<std::vector<std::vector<std::vector<double> > >,8>  double_jk_comove_type1_pipiI_0_seperate_fold_old;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type1_pipiI_2_combine_fold_old;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type1_pipiI_0_combine_fold_old;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type1_pipiI_2_combine_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type1_pipiI_0_combine_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type2_pipiI_2_combine_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type2_pipiI_0_combine_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type3_pipiI_2_combine_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type3_pipiI_2_sd_combine_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type3_pipiI_2_dd_combine_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type3_pipiI_0_combine_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type3_pipiI_0_sd_combine_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_comove_type3_pipiI_0_dd_combine_fold;

    std::vector<std::vector<std::vector<double> > >   		double_jk_pipiI_0_sub_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_0_sub_fold_s2_s2;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_0_sub_fold_s3_s3;
    std::vector<std::vector<std::vector<double> > >             double_jk_pipiI_0_sub_fold_d1_d1;

    std::array<std::vector<std::vector<std::vector<double> > >,64> double_jk_noproj_nosub_corr_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_corr_sub_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_corr_sub_fold_s2_s2;
    std::vector<std::vector<std::vector<double> > >             double_jk_corr_sub_fold_s3_s3;
    std::vector<std::vector<std::vector<double> > >             double_jk_scat_sub_fold;
    std::vector<std::vector<std::vector<double> > >             double_jk_scat_sub_fold_s2_s2;
    std::vector<std::vector<std::vector<double> > >             double_jk_scat_sub_fold_s3_s3;

    std::array<std::vector<std::vector<std::pair<double,int> > >,4>  double_jk_pion_fold_fit;
    std::array<std::vector<std::vector<std::pair<double,int> > >,4>  double_jk_pion_fit;
    std::array<std::vector<std::vector<std::pair<double,int> > >,64> double_jk_noproj_pipiI_2_fold_fit;
    std::array<std::vector<std::vector<std::pair<double,int> > >,16> double_jk_noproj_pipiI_2_fold_fit_gevp;
    std::array<std::vector<std::vector<std::pair<double,int> > >,64> double_jk_noproj_nosub_pipiI_0_fold_fit;
    std::array<std::vector<std::vector<std::pair<double,int> > >,16> double_jk_noproj_nosub_pipiI_0_fold_fit_gevp;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_2_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_2_fold_fit_s2_s2;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_2_fold_fit_s3_s3;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_2_fold_fit_d1_d1;
    std::array<std::vector<std::vector<std::pair<double,int> > >,8>  double_jk_comove_type1_pipiI_2_seperate_fold_fit_old;
    std::array<std::vector<std::vector<std::pair<double,int> > >,8>  double_jk_comove_type1_pipiI_0_seperate_fold_fit_old;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type1_pipiI_2_combine_fold_fit_old;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type1_pipiI_0_combine_fold_fit_old;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type1_pipiI_2_combine_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type1_pipiI_0_combine_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type2_pipiI_2_combine_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type2_pipiI_0_combine_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type3_pipiI_2_combine_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type3_pipiI_2_sd_combine_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type3_pipiI_2_dd_combine_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type3_pipiI_0_combine_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type3_pipiI_0_sd_combine_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_comove_type3_pipiI_0_dd_combine_fold_fit;

    std::array<std::vector<std::vector<std::pair<double,int> > >,4> double_jk_pipisigma_gevp; 
    std::vector<std::vector<std::pair<double,int> > > 		double_jk_pipiI_0_sub_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_0_sub_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_0_sub_fold_fit_s2_s2;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_0_sub_fold_fit_s3_s3;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_pipiI_0_sub_fold_fit_d1_d1;
    std::array<std::vector<std::vector<std::pair<double,int> > >,64> double_jk_noproj_nosub_corr_fold_fit;
    std::array<std::vector<std::vector<std::pair<double,int> > >,4> double_jk_noproj_nosub_corr_fold_fit_gevp;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_corr_sub_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_corr_sub_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_corr_sub_fold_fit_s2_s2;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_corr_sub_fold_fit_s3_s3;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_scat_sub_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_scat_sub_fold_fit;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_scat_sub_fold_fit_s2_s2;
    std::vector<std::vector<std::pair<double,int> > >           double_jk_scat_sub_fold_fit_s3_s3;

    std::array<std::vector<MatrixXd>,4>				double_jk_pion_fold_cov_mat;
    std::array<std::vector<MatrixXd>,4>                         double_jk_pion_cov_mat;
    std::array<std::vector<MatrixXd>,64>			double_jk_noproj_pipiI_2_fold_cov_mat;
    std::array<std::vector<MatrixXd>,64>                        double_jk_noproj_nosub_pipiI_0_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_pipiI_2_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_pipiI_2_fold_cov_mat_s2_s2;
    std::vector<MatrixXd>                                       double_jk_pipiI_2_fold_cov_mat_s3_s3;
    std::vector<MatrixXd>                                       double_jk_pipiI_2_fold_cov_mat_d1_d1;
    std::array<std::vector<MatrixXd>,8>                         double_jk_comove_type1_pipiI_2_seperate_fold_cov_mat_old;
    std::array<std::vector<MatrixXd>,8>                         double_jk_comove_type1_pipiI_0_seperate_fold_cov_mat_old;
    std::vector<MatrixXd>					double_jk_comove_type1_pipiI_2_combine_fold_cov_mat_old;
    std::vector<MatrixXd>                                       double_jk_comove_type1_pipiI_0_combine_fold_cov_mat_old;
    std::vector<MatrixXd>                                       double_jk_comove_type1_pipiI_2_combine_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_comove_type1_pipiI_0_combine_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_comove_type2_pipiI_2_combine_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_comove_type2_pipiI_0_combine_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_comove_type3_pipiI_2_combine_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_comove_type3_pipiI_2_sd_combine_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_comove_type3_pipiI_2_dd_combine_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_comove_type3_pipiI_0_combine_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_comove_type3_pipiI_0_sd_combine_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_comove_type3_pipiI_0_dd_combine_fold_cov_mat;

    std::vector<MatrixXd>                                       double_jk_pipiI_0_sub_cov_mat;
    std::vector<MatrixXd>			     		double_jk_pipiI_0_sub_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_pipiI_0_sub_fold_cov_mat_s2_s2;
    std::vector<MatrixXd>                                       double_jk_pipiI_0_sub_fold_cov_mat_s3_s3;
    std::vector<MatrixXd>                                       double_jk_pipiI_0_sub_fold_cov_mat_d1_d1;
    std::array<std::vector<MatrixXd>,64>                        double_jk_noproj_nosub_corr_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_corr_sub_cov_mat;
    std::vector<MatrixXd>                                       double_jk_corr_sub_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_corr_sub_fold_cov_mat_s2_s2;
    std::vector<MatrixXd>                                       double_jk_corr_sub_fold_cov_mat_s3_s3;
    std::vector<MatrixXd>                                       double_jk_scat_sub_cov_mat;
    std::vector<MatrixXd>                                       double_jk_scat_sub_fold_cov_mat;
    std::vector<MatrixXd>                                       double_jk_scat_sub_fold_cov_mat_s2_s2;
    std::vector<MatrixXd>                                       double_jk_scat_sub_fold_cov_mat_s3_s3;

    std::vector<std::pair<double,double> >			double_jk_pipiI_0_sub_fold_fit_result;
    std::vector<std::pair<double,double> >                      double_jk_corr_sub_fold_fit_result;
    std::vector<std::pair<double,double> >                      double_jk_scat_sub_fold_fit_result;
  public:

    void double_jk_generate()
    {
      std::cout << "Start double_jk_generate\n" << std::endl;
      double_jk_generate_prototype(double_jk_pipiI_2, s1_s1_pipiI_2);
      double_jk_generate_prototype(double_jk_pipiI_2_s2_s2, s2_s2_pipiI_2);
      double_jk_generate_prototype(double_jk_pipiI_2_s3_s3, s3_s3_pipiI_2);
      double_jk_generate_prototype(double_jk_pipiI_2_d1_d1, d1_d1_pipiI_2);
      for(int i=0; i<4; i++)
      {
        double_jk_generate_prototype(double_jk_pion[i], tavg_pion[i]);
      }
      for(int i=0; i<64; i++)
      {
        double_jk_generate_prototype(double_jk_noproj_pipiI_2[i], noproj_pipiI_2[i]);
        double_jk_generate_prototype(double_jk_noproj_nosub_pipiI_0[i], noproj_nosub_pipiI_0[i]);
        double_jk_generate_prototype(double_jk_noproj_nosub_corr[i], tavg_corr[i]);
      }
      for(int i=0; i<8; i++)
      {
	double_jk_generate_prototype(double_jk_comove_type1_pipiI_2_seperate_old[i], comove_type1_pipiI_2_seperate_old[i]);
	double_jk_generate_prototype(double_jk_comove_type1_pipiI_0_seperate_old[i], comove_type1_pipiI_0_seperate_old[i]);
      }
      double_jk_generate_prototype(double_jk_comove_type1_pipiI_2_combine_old, comove_type1_pipiI_2_combine_old);
      double_jk_generate_prototype(double_jk_comove_type1_pipiI_0_combine_old, comove_type1_pipiI_0_combine_old);
      double_jk_generate_prototype(double_jk_comove_type1_pipiI_2_combine, comove_type1_pipiI_2_combine_test);
      double_jk_generate_prototype(double_jk_comove_type1_pipiI_0_combine, comove_type1_pipiI_0_combine_test);
      double_jk_generate_prototype(double_jk_comove_type2_pipiI_2_combine, comove_type2_pipiI_2_combine_test);
      double_jk_generate_prototype(double_jk_comove_type2_pipiI_0_combine, comove_type2_pipiI_0_combine_test);
      double_jk_generate_prototype(double_jk_comove_type3_pipiI_2_combine, comove_type3_pipiI_2_combine_test);
      double_jk_generate_prototype(double_jk_comove_type3_pipiI_2_sd_combine, comove_type3_pipiI_2_sd_combine_test);
      double_jk_generate_prototype(double_jk_comove_type3_pipiI_2_dd_combine, comove_type3_pipiI_2_dd_combine_test);
      double_jk_generate_prototype(double_jk_comove_type3_pipiI_0_combine, comove_type3_pipiI_0_combine_test);
      double_jk_generate_prototype(double_jk_comove_type3_pipiI_0_sd_combine, comove_type3_pipiI_0_sd_combine_test);
      double_jk_generate_prototype(double_jk_comove_type3_pipiI_0_dd_combine, comove_type3_pipiI_0_dd_combine_test);

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
      for(int i=0; i<4; i++)
      {
        double_jk_fold_prototype(double_jk_pion[i],double_jk_pion_fold[i],0);
      }
      for(int i=0; i<8; i++)
      {
	double_jk_fold_prototype(double_jk_comove_type1_pipiI_2_seperate_old[i],double_jk_comove_type1_pipiI_2_seperate_fold_old[i],2*tdis);
	double_jk_fold_prototype(double_jk_comove_type1_pipiI_0_seperate_old[i],double_jk_comove_type1_pipiI_0_seperate_fold_old[i],2*tdis);
      }
      for(int i=0; i<64; i++)
      {
        double_jk_fold_prototype(double_jk_noproj_pipiI_2[i],double_jk_noproj_pipiI_2_fold[i],2*tdis);
        double_jk_fold_prototype(double_jk_noproj_nosub_pipiI_0[i],double_jk_noproj_nosub_pipiI_0_fold[i],2*tdis);
        double_jk_fold_prototype(double_jk_noproj_nosub_corr[i],double_jk_noproj_nosub_corr_fold[i],0);
      }
      double_jk_fold_prototype(double_jk_comove_type1_pipiI_2_combine_old,double_jk_comove_type1_pipiI_2_combine_fold_old,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type1_pipiI_0_combine_old,double_jk_comove_type1_pipiI_0_combine_fold_old,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type1_pipiI_2_combine,double_jk_comove_type1_pipiI_2_combine_fold,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type1_pipiI_0_combine,double_jk_comove_type1_pipiI_0_combine_fold,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type2_pipiI_2_combine,double_jk_comove_type2_pipiI_2_combine_fold,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type2_pipiI_0_combine,double_jk_comove_type2_pipiI_0_combine_fold,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type3_pipiI_2_combine,double_jk_comove_type3_pipiI_2_combine_fold,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type3_pipiI_2_sd_combine,double_jk_comove_type3_pipiI_2_sd_combine_fold,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type3_pipiI_2_dd_combine,double_jk_comove_type3_pipiI_2_dd_combine_fold,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type3_pipiI_0_combine,double_jk_comove_type3_pipiI_0_combine_fold,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type3_pipiI_0_sd_combine,double_jk_comove_type3_pipiI_0_sd_combine_fold,2*tdis);
      double_jk_fold_prototype(double_jk_comove_type3_pipiI_0_dd_combine,double_jk_comove_type3_pipiI_0_dd_combine_fold,2*tdis);

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
      for(int i=0; i<4; i++)
      {
        double_jk_fit_input_generate_prototype(double_jk_pion_fold[i], double_jk_pion_fold_fit[i], double_jk_pion_fold_cov_mat[i],corfit);
        double_jk_fit_input_generate_prototype(double_jk_pion[i], double_jk_pion_fit[i], double_jk_pion_cov_mat[i],corfit);
      }
      for(int i=0; i<8; i++)
      {
	double_jk_fit_input_generate_prototype(double_jk_comove_type1_pipiI_2_seperate_fold_old[i], double_jk_comove_type1_pipiI_2_seperate_fold_fit_old[i], double_jk_comove_type1_pipiI_2_seperate_fold_cov_mat_old[i],corfit);
	double_jk_fit_input_generate_prototype(double_jk_comove_type1_pipiI_0_seperate_fold_old[i], double_jk_comove_type1_pipiI_0_seperate_fold_fit_old[i], double_jk_comove_type1_pipiI_0_seperate_fold_cov_mat_old[i],corfit);
      }
      for(int i=0; i<64; i++)
      {
        double_jk_fit_input_generate_prototype(double_jk_noproj_pipiI_2_fold[i], double_jk_noproj_pipiI_2_fold_fit[i], double_jk_noproj_pipiI_2_fold_cov_mat[i],corfit);
        double_jk_fit_input_generate_prototype(double_jk_noproj_nosub_pipiI_0_fold[i], double_jk_noproj_nosub_pipiI_0_fold_fit[i], double_jk_noproj_nosub_pipiI_0_fold_cov_mat[i],corfit);
        double_jk_fit_input_generate_prototype(double_jk_noproj_nosub_corr_fold[i], double_jk_noproj_nosub_corr_fold_fit[i], double_jk_noproj_nosub_corr_fold_cov_mat[i],corfit);
      }
      double_jk_fit_input_generate_prototype(double_jk_comove_type1_pipiI_2_combine_fold_old, double_jk_comove_type1_pipiI_2_combine_fold_fit_old, double_jk_comove_type1_pipiI_2_combine_fold_cov_mat_old,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type1_pipiI_0_combine_fold_old, double_jk_comove_type1_pipiI_0_combine_fold_fit_old, double_jk_comove_type1_pipiI_0_combine_fold_cov_mat_old,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type1_pipiI_2_combine_fold, double_jk_comove_type1_pipiI_2_combine_fold_fit, double_jk_comove_type1_pipiI_2_combine_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type1_pipiI_0_combine_fold, double_jk_comove_type1_pipiI_0_combine_fold_fit, double_jk_comove_type1_pipiI_0_combine_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type2_pipiI_2_combine_fold, double_jk_comove_type2_pipiI_2_combine_fold_fit, double_jk_comove_type2_pipiI_2_combine_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type2_pipiI_0_combine_fold, double_jk_comove_type2_pipiI_0_combine_fold_fit, double_jk_comove_type2_pipiI_0_combine_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type3_pipiI_2_combine_fold, double_jk_comove_type3_pipiI_2_combine_fold_fit, double_jk_comove_type3_pipiI_2_combine_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type3_pipiI_2_sd_combine_fold, double_jk_comove_type3_pipiI_2_sd_combine_fold_fit, double_jk_comove_type3_pipiI_2_sd_combine_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type3_pipiI_2_dd_combine_fold, double_jk_comove_type3_pipiI_2_dd_combine_fold_fit, double_jk_comove_type3_pipiI_2_dd_combine_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type3_pipiI_0_combine_fold, double_jk_comove_type3_pipiI_0_combine_fold_fit, double_jk_comove_type3_pipiI_0_combine_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type3_pipiI_0_sd_combine_fold, double_jk_comove_type3_pipiI_0_sd_combine_fold_fit, double_jk_comove_type3_pipiI_0_sd_combine_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_comove_type3_pipiI_0_dd_combine_fold, double_jk_comove_type3_pipiI_0_dd_combine_fold_fit, double_jk_comove_type3_pipiI_0_dd_combine_fold_cov_mat,corfit);

      double_jk_fit_input_generate_prototype(double_jk_pipiI_2_fold, double_jk_pipiI_2_fold_fit, double_jk_pipiI_2_fold_cov_mat,corfit);     
      double_jk_fit_input_generate_prototype(double_jk_pipiI_2_fold_s2_s2, double_jk_pipiI_2_fold_fit_s2_s2, double_jk_pipiI_2_fold_cov_mat_s2_s2,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_2_fold_s3_s3, double_jk_pipiI_2_fold_fit_s3_s3, double_jk_pipiI_2_fold_cov_mat_s3_s3,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_2_fold_d1_d1, double_jk_pipiI_2_fold_fit_d1_d1, double_jk_pipiI_2_fold_cov_mat_d1_d1,corfit);

      double_jk_fit_input_generate_prototype(double_jk_pipiI_0_sub, double_jk_pipiI_0_sub_fit, double_jk_pipiI_0_sub_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_0_sub_fold, double_jk_pipiI_0_sub_fold_fit, double_jk_pipiI_0_sub_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_0_sub_fold_s2_s2, double_jk_pipiI_0_sub_fold_fit_s2_s2, double_jk_pipiI_0_sub_fold_cov_mat_s2_s2,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_0_sub_fold_s3_s3, double_jk_pipiI_0_sub_fold_fit_s3_s3, double_jk_pipiI_0_sub_fold_cov_mat_s3_s3,corfit);
      double_jk_fit_input_generate_prototype(double_jk_pipiI_0_sub_fold_d1_d1, double_jk_pipiI_0_sub_fold_fit_d1_d1, double_jk_pipiI_0_sub_fold_cov_mat_d1_d1,corfit);
      double_jk_fit_input_generate_prototype(double_jk_corr_sub, double_jk_corr_sub_fit, double_jk_corr_sub_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_corr_sub_fold, double_jk_corr_sub_fold_fit, double_jk_corr_sub_fold_cov_mat,corfit);
      double_jk_fit_input_generate_prototype(double_jk_corr_sub_fold_s2_s2, double_jk_corr_sub_fold_fit_s2_s2, double_jk_corr_sub_fold_cov_mat_s2_s2,corfit);
      double_jk_fit_input_generate_prototype(double_jk_corr_sub_fold_s3_s3, double_jk_corr_sub_fold_fit_s3_s3, double_jk_corr_sub_fold_cov_mat_s3_s3,corfit);
      double_jk_fit_input_generate_prototype(double_jk_scat_sub, double_jk_scat_sub_fit, double_jk_scat_sub_cov_mat,corfit);
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
    std::map<int,std::array<std::pair<std::complex<double>,double>,8> > noproj_pipiI_2_gevp;
    std::map<int,std::array<std::pair<std::complex<double>,double>,8> > noproj_nosub_pipiI_0_gevp;
    std::map<int,std::array<std::pair<std::complex<double>,double>,4> > noproj_nosub_corr_gevp;

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

    void pipiI_2_gevp_input_wrapper()
    {
      for(int idx=0; idx<16; idx++)
      {
        double_jk_noproj_pipiI_2_fold_fit_gevp[idx] = double_jk_noproj_pipiI_2_fold_fit[0];
        for(int traj=0; traj<double_jk_noproj_pipiI_2_fold_fit_gevp[idx].size(); traj++)
          for(int t=0; t<double_jk_noproj_pipiI_2_fold_fit_gevp[idx][traj].size(); t++)
            double_jk_noproj_pipiI_2_fold_fit_gevp[idx][traj][t].first = 0.0;
      }
      for(int i=0; i<8; i++)
      {
        int ii=i/2;
        for(int j=0; j<8; j++)
        {
          int jj=j/2;
          for(int traj=0; traj<double_jk_noproj_pipiI_2_fold_fit[i*8+j].size(); traj++)
            for(int t=0; t<double_jk_noproj_pipiI_2_fold_fit[i*8+j][traj].size(); t++)
              double_jk_noproj_pipiI_2_fold_fit_gevp[ii*4+jj][traj][t].first += double_jk_noproj_pipiI_2_fold_fit[i*8+j][traj][t].first;
        }
      }
    }

    void pipiI_0_nosub_gevp_input_wrapper()
    {
      for(int idx=0; idx<16; idx++)
      {
        double_jk_noproj_nosub_pipiI_0_fold_fit_gevp[idx] = double_jk_noproj_nosub_pipiI_0_fold_fit[0];
        for(int traj=0; traj<double_jk_noproj_nosub_pipiI_0_fold_fit_gevp[idx].size(); traj++)
          for(int t=0; t<double_jk_noproj_nosub_pipiI_0_fold_fit_gevp[idx][traj].size(); t++)
            double_jk_noproj_nosub_pipiI_0_fold_fit_gevp[idx][traj][t].first = 0.0;
      }
      for(int i=0; i<8; i++)
      {
        int ii=i/2;
        for(int j=0; j<8; j++)
        {
          int jj=j/2;
          for(int traj=0; traj<double_jk_noproj_nosub_pipiI_0_fold_fit[i*8+j].size(); traj++)
            for(int t=0; t<double_jk_noproj_nosub_pipiI_0_fold_fit[i*8+j][traj].size(); t++)
              double_jk_noproj_nosub_pipiI_0_fold_fit_gevp[ii*4+jj][traj][t].first += double_jk_noproj_nosub_pipiI_0_fold_fit[i*8+j][traj][t].first;
        }
      }
    }

    void corr_nosub_gevp_input_wrapper()
    {
      for(int idx=0; idx<4; idx++)
      {
        double_jk_noproj_nosub_corr_fold_fit_gevp[idx] = double_jk_noproj_nosub_corr_fold_fit[0];
        for(int traj=0; traj<double_jk_noproj_nosub_corr_fold_fit_gevp[idx].size(); traj++)
          for(int t=0; t<double_jk_noproj_nosub_corr_fold_fit_gevp[idx][traj].size(); t++)
            double_jk_noproj_nosub_corr_fold_fit_gevp[idx][traj][t].first = 0.0;
      }
      for(int i=0; i<8; i++)
      {
        int ii = (i<2? 0:1);
        for(int j=0; j<8; j++)
        {
          int jj = (j<2? 0:1);
          for(int traj=0; traj<double_jk_noproj_nosub_corr_fold_fit[i*8+j].size(); traj++)
          {
            for(int t=0; t<double_jk_noproj_nosub_corr_fold_fit[i*8+j][traj].size(); t++)
            {
              double gevp_fac = (1.0+ii*2.0)*(1.0+jj*2.0);
              double_jk_noproj_nosub_corr_fold_fit_gevp[ii*2+jj][traj][t].first += double_jk_noproj_nosub_corr_fold_fit[i*8+j][traj][t].first/gevp_fac;
            }
          }
        }
      }
    }

    void pipiandsigma_gevp_input_wrapper()
    {
      double_jk_pipisigma_gevp[0] = double_jk_pipiI_0_sub_fold_fit;
      double_jk_pipisigma_gevp[1] = double_jk_scat_sub_fold_fit;
      double_jk_pipisigma_gevp[2] = double_jk_scat_sub_fold_fit;
      double_jk_pipisigma_gevp[3] = double_jk_corr_sub_fold_fit; 
    }

  public:
    void gevp_start()
    {
      std::cout << "Start gevp\n" << std::endl;
      bool gevp_do_sub = true;
      bool gevp_no_sub = true;
//      if(this->pipi)
//      {
//        pipiI_2_gevp_input_wrapper();
//        pipiI_0_nosub_gevp_input_wrapper();
//        gevp_entire_wrapper<int,4>(double_jk_noproj_pipiI_2_fold_fit_gevp,2,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_pipiI_2_fold_fit_gevp,3,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_pipiI_2_fold_fit_gevp,4,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_pipiI_2_fold_fit_gevp,5,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_pipiI_2_fold_fit_gevp,6,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_pipiI_2_fold_fit_gevp,7,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_pipiI_2_fold_fit_gevp,8,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_pipiI_2_fold_fit_gevp,9,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_nosub_pipiI_0_fold_fit_gevp,2,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_nosub_pipiI_0_fold_fit_gevp,3,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_nosub_pipiI_0_fold_fit_gevp,4,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_nosub_pipiI_0_fold_fit_gevp,5,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_nosub_pipiI_0_fold_fit_gevp,6,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_nosub_pipiI_0_fold_fit_gevp,7,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_nosub_pipiI_0_fold_fit_gevp,8,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,4>(double_jk_noproj_nosub_pipiI_0_fold_fit_gevp,9,1,16,gevp_do_sub);
//      }
//      if(this->corr)
//      {
//        corr_nosub_gevp_input_wrapper();
//        gevp_entire_wrapper<int,2>(double_jk_noproj_nosub_corr_fold_fit_gevp,2,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,2>(double_jk_noproj_nosub_corr_fold_fit_gevp,3,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,2>(double_jk_noproj_nosub_corr_fold_fit_gevp,4,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,2>(double_jk_noproj_nosub_corr_fold_fit_gevp,5,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,2>(double_jk_noproj_nosub_corr_fold_fit_gevp,6,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,2>(double_jk_noproj_nosub_corr_fold_fit_gevp,7,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,2>(double_jk_noproj_nosub_corr_fold_fit_gevp,8,1,16,gevp_do_sub);
//        gevp_entire_wrapper<int,2>(double_jk_noproj_nosub_corr_fold_fit_gevp,9,1,16,gevp_do_sub);
//      }
      if(this->scat)
      {
        pipiandsigma_gevp_input_wrapper();
        std::cout << "wrapper for pipiandsigma successful\n" <<std::endl;
      //  gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,2,1,16,gevp_no_sub);
        gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,3,1,16,gevp_no_sub);
        gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,4,1,16,gevp_no_sub);
        gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,5,1,16,gevp_no_sub);
        gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,6,1,16,gevp_no_sub);
        gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,7,1,16,gevp_no_sub);
        gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,8,1,16,gevp_no_sub);
        gevp_entire_wrapper<int,2>(double_jk_pipisigma_gevp,9,1,16,gevp_no_sub);
      }
      std::cout << "Finish gevp\n" << std::endl;
    }
//these are the old way of doing fitting (single jackknife), which probably are incorrect
//this section generates average, error and tsep for each jackknife ensemble for fitting
//the name looks like "fit_xx_xx_xxxx_xxx"
  private:
    std::array<std::vector<std::vector<std::tuple<double,double,int> > >,4>   fit_pion;
    std::vector<std::vector<std::tuple<double,double,int> > >		      fit_s1_s1_corr;
    std::vector<std::vector<std::tuple<double,double,int> > >                 fit_s1_s1_corr_sub;
    std::vector<std::vector<std::tuple<double,double,int> > >                 fit_s1_s1_scat;
    std::vector<std::vector<std::tuple<double,double,int> > >                 fit_s1_s1_scat_sub;
    std::vector<std::vector<std::tuple<double,double,int> > >                 fit_s1_s1_pipiI_2;
    std::vector<std::vector<std::tuple<double,double,int> > >                 fit_s1_s1_pipiI_0;

    std::array<std::vector<std::vector<std::pair<double,int> > >,4>  	      cor_fit_pion;
    std::vector<std::vector<std::pair<double,int> > >			      cor_fit_s1_s1_corr;
    std::vector<std::vector<std::pair<double,int> > >                         cor_fit_s1_s1_corr_sub;
    std::vector<std::vector<std::pair<double,int> > >                         cor_fit_s1_s1_scat;
    std::vector<std::vector<std::pair<double,int> > >                         cor_fit_s1_s1_scat_sub;
    std::vector<std::vector<std::pair<double,int> > >                         cor_fit_s1_s1_pipiI_2;
    std::vector<std::vector<std::pair<double,int> > >                         cor_fit_s1_s1_pipiI_0;

    std::array<std::vector<Matrix<double,Lt,Lt> >,4>			      cov_mat_pion;
    std::vector<Matrix<double,Lt,Lt> >					      cov_mat_s1_s1_corr;
    std::vector<Matrix<double,Lt,Lt> >                                        cov_mat_s1_s1_scat;
    std::vector<Matrix<double,Lt,Lt> >                                        cov_mat_s1_s1_pipiI_2;
    std::vector<Matrix<double,Lt,Lt> >                                        cov_mat_s1_s1_pipiI_0;

  public:

    bool fit_data_generate()
    {
      if(this->pion)
	for(int pidx=0; pidx<4; pidx++)
	  ensemble_nosub_prototype(tavg_pion[pidx],fit_pion[pidx],avg_fac,err_fac,cov_mat_pion[pidx]);
      if(this->corr)      
	ensemble_nosub_prototype(s1_s1_corr,fit_s1_s1_corr,avg_fac,err_fac,cov_mat_s1_s1_corr);
      if(this->scat)      
	ensemble_nosub_prototype(s1_s1_scat,fit_s1_s1_scat,avg_fac,err_fac,cov_mat_s1_s1_scat);
      if(this->corr_sub)  
	ensemble_sub_prototype(s1_s1_corr,s1_self,s1_self,0.5,fit_s1_s1_corr_sub,avg_fac,err_fac);
      if(this->scat_sub)  
	ensemble_sub_prototype(s1_s1_scat,s1_tsep_4_pion,s1_self,1.22474487139,fit_s1_s1_scat_sub,avg_fac,err_fac);
      if(this->pipi)
      {
	ensemble_nosub_prototype(s1_s1_pipiI_2,fit_s1_s1_pipiI_2,avg_fac,err_fac,cov_mat_s1_s1_pipiI_2);
	ensemble_sub_prototype(s1_s1_pipiI_0,s1_pipiV,s1_pipiV,3.0,fit_s1_s1_pipiI_0,avg_fac,err_fac);
      }
    }

    bool cor_fit_data_generate()
    {
      cor_fit_generate_prototype(fit_s1_s1_corr,cor_fit_s1_s1_corr);
      cor_fit_generate_prototype(fit_s1_s1_corr_sub,cor_fit_s1_s1_corr_sub);
      cor_fit_generate_prototype(fit_s1_s1_scat,cor_fit_s1_s1_scat);
      cor_fit_generate_prototype(fit_s1_s1_scat_sub,cor_fit_s1_s1_scat_sub);
      cor_fit_generate_prototype(fit_s1_s1_pipiI_2,cor_fit_s1_s1_pipiI_2);
      cor_fit_generate_prototype(fit_s1_s1_pipiI_0,cor_fit_s1_s1_pipiI_0);
    }

    bool output_fit_input()
    {
      if(this->pion)
      {
        for(int pidx=0; pidx<4; pidx++)
        {
	  cout<<"pidx= "<<pidx;
	  output_data("pion",fit_pion[pidx]);
        }
      }
      if(this->corr)
	output_data("swave1->swave1_sigmacorr_nosub",fit_s1_s1_corr);
      if(this->corr_sub)
	output_data("swave1->swave1_sigmacorr_sub",fit_s1_s1_corr_sub);
      if(this->scat)
	output_data("swave1->swave1_pipisigma_nosub",fit_s1_s1_scat);
      if(this->scat_sub)
	output_data("swave1->swave1_pipisigma_sub",fit_s1_s1_scat_sub);
      if(this->pipi)
      {
	output_data("swave1->swave1_pipi_scat_I=2",fit_s1_s1_pipiI_2);
	output_data("swave1->swave1_pipi_scat_I=0",fit_s1_s1_pipiI_0);
      }
    }


//this section calculates eff_mass, we provide two methods to do that :using three point method or two point 0-dof fitting
//the name looks like "sample_mass_2pt(3pt)_xxxx" for mass for each ensemble, and "mass_xxxx" for mass after jackknife
  private:
    std::array<std::vector<std::vector<std::pair<double,int> > >,4> 	sample_mass_2pt_double_jk_pion;
    std::array<std::vector<std::vector<std::pair<double,int> > >,4>     sample_mass_3pt_double_jk_pion;

    std::array<std::vector<std::vector<std::pair<double,int> > >,8>     sample_mass_2pt_double_jk_comove_type1_pipiI_2_old;
    std::array<std::vector<std::vector<std::pair<double,int> > >,8>     sample_mass_2pt_double_jk_comove_type1_pipiI_0_old;
    std::vector<std::vector<std::pair<double,int> > >			sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine_old;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine_old;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type2_pipiI_2_combine;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type2_pipiI_0_combine;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type3_pipiI_2_combine;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type3_pipiI_2_sd_combine;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type3_pipiI_2_dd_combine;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type3_pipiI_0_combine;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type3_pipiI_0_sd_combine;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_comove_type3_pipiI_0_dd_combine;

    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_pipiI_0;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_pipiI_0_d1_d1;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_3pt_double_jk_pipiI_0;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_pipiI_2;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_pipiI_2_d1_d1;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_3pt_double_jk_pipiI_2;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_corr;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_corr_s2_s2;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_corr_s3_s3;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_scat;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_scat_s2_s2;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_2pt_double_jk_scat_s3_s3;

    std::array<std::vector<std::vector<std::pair<double,int> > >,4>     sample_mass_3pt_pion;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_3pt_corr;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_3pt_scat;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_3pt_pipiI_2;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_3pt_pipiI_0;

    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_3pt_double_jk_corr;
    std::vector<std::vector<std::pair<double,int> > >                   sample_mass_3pt_double_jk_scat;

    std::array<std::vector<std::tuple<double,double,int> >,4>		mass_2pt_double_jk_pion;
    std::array<std::vector<std::tuple<double,double,int> >,4>           mass_3pt_double_jk_pion;

    std::array<std::vector<std::tuple<double,double,int> >,8>           mass_2pt_double_jk_comove_type1_pipiI_2_old;
    std::array<std::vector<std::tuple<double,double,int> >,8>           mass_2pt_double_jk_comove_type1_pipiI_0_old;
    std::vector<std::tuple<double,double,int> >				mass_2pt_double_jk_comove_type1_pipiI_2_combine_old;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type1_pipiI_0_combine_old;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type1_pipiI_2_combine;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type1_pipiI_0_combine;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type2_pipiI_2_combine;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type2_pipiI_0_combine;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type3_pipiI_2_combine;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type3_pipiI_2_sd_combine;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type3_pipiI_2_dd_combine;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type3_pipiI_0_combine;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type3_pipiI_0_sd_combine;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_comove_type3_pipiI_0_dd_combine;

    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_pipiI_2;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_pipiI_2_d1_d1;
    std::vector<std::tuple<double,double,int> >                         mass_3pt_double_jk_pipiI_2;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_pipiI_0;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_pipiI_0_d1_d1;
    std::vector<std::tuple<double,double,int> >                         mass_3pt_double_jk_pipiI_0;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_corr;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_corr_s2_s2;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_corr_s3_s3;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_scat;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_scat_s2_s2;
    std::vector<std::tuple<double,double,int> >                         mass_2pt_double_jk_scat_s3_s3;

    std::array<std::vector<std::tuple<double,double,int> >,4>           mass_3pt_pion;
    std::vector<std::tuple<double,double,int> >                         mass_3pt_corr;
    std::vector<std::tuple<double,double,int> >                         mass_3pt_scat;
    std::vector<std::tuple<double,double,int> >                         mass_3pt_pipiI_2;
    std::vector<std::tuple<double,double,int> >                         mass_3pt_pipiI_0;

    std::vector<std::tuple<double,double,int> >                         mass_3pt_double_jk_corr;
    std::vector<std::tuple<double,double,int> >                         mass_3pt_double_jk_scat;

  public:

    bool mass_2pt_generate()
    {
      std::cout << "Start mass_2pt_generate\n" << std::endl;
      if(this->pion)
      {
        for(int pidx=0; pidx<4; pidx++)
        {
          eff_mass_2pt_wrapper<Lt>(double_jk_pion_fold_fit[pidx],sample_mass_2pt_double_jk_pion[pidx]);
          eff_mass_3pt_wrapper(double_jk_pion_fold_fit[pidx],sample_mass_3pt_double_jk_pion[pidx]);
        }
      }
      if(this->corr)
      {
	eff_mass_2pt_wrapper<Lt>(double_jk_corr_sub_fold_fit,sample_mass_2pt_double_jk_corr);
        eff_mass_2pt_wrapper<Lt>(double_jk_corr_sub_fold_fit_s2_s2,sample_mass_2pt_double_jk_corr_s2_s2);
        eff_mass_2pt_wrapper<Lt>(double_jk_corr_sub_fold_fit_s3_s3,sample_mass_2pt_double_jk_corr_s3_s3);
	eff_mass_3pt_bad_wrapper(double_jk_corr_sub_fold_fit,sample_mass_3pt_double_jk_corr);
      }
      if(this->scat)
      {
	eff_mass_2pt_wrapper<Lt-tdis>(double_jk_scat_sub_fold_fit,sample_mass_2pt_double_jk_scat);
        eff_mass_2pt_wrapper<Lt-tdis>(double_jk_scat_sub_fold_fit_s2_s2,sample_mass_2pt_double_jk_scat_s2_s2);
        eff_mass_2pt_wrapper<Lt-tdis>(double_jk_scat_sub_fold_fit_s3_s3,sample_mass_2pt_double_jk_scat_s3_s3);
	eff_mass_3pt_bad_wrapper(double_jk_scat_sub_fold_fit,sample_mass_3pt_double_jk_scat);
      }
      if(this->pipi)
      {  
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_pipiI_2_fold_fit_d1_d1,sample_mass_2pt_double_jk_pipiI_2_d1_d1);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_pipiI_0_sub_fold_fit_d1_d1,sample_mass_2pt_double_jk_pipiI_0_d1_d1);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_pipiI_2_fold_fit,sample_mass_2pt_double_jk_pipiI_2);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_pipiI_0_sub_fold_fit,sample_mass_2pt_double_jk_pipiI_0);
        eff_mass_3pt_wrapper(double_jk_pipiI_2_fold_fit,sample_mass_3pt_double_jk_pipiI_2);
        eff_mass_3pt_wrapper(double_jk_pipiI_0_sub_fold_fit,sample_mass_3pt_double_jk_pipiI_0);
//	eff_mass_3pt_bad_wrapper(double_jk_pipiI_0_sub_fold_fit,sample_mass_3pt_double_jk_pipiI_0);
      }
      if(this->comove_pipi)
      {
	for(int pidx=0; pidx<8; pidx++)
	{
//        eff_mass_3pt_wrapper(double_jk_comove_type1_pipiI_2_seperate_fold_fit_old[pidx],sample_mass_2pt_double_jk_comove_type1_pipiI_2_old[pidx]);
//        eff_mass_3pt_wrapper(double_jk_comove_type1_pipiI_0_seperate_fold_fit_old[pidx],sample_mass_2pt_double_jk_comove_type1_pipiI_0_old[pidx]);
//	  eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_2_seperate_fold_fit_old[pidx],sample_mass_2pt_double_jk_comove_type1_pipiI_2_old[pidx]);
//	  eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_0_seperate_fold_fit_old[pidx],sample_mass_2pt_double_jk_comove_type1_pipiI_0_old[pidx]);
	}
//	eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_2_combine_fold_fit_old,sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine_old);
//	eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_0_combine_fold_fit_old,sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine_old);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_2_combine_fold_fit,sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_0_combine_fold_fit,sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type2_pipiI_2_combine_fold_fit,sample_mass_2pt_double_jk_comove_type2_pipiI_2_combine);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type2_pipiI_0_combine_fold_fit,sample_mass_2pt_double_jk_comove_type2_pipiI_0_combine);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_2_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_2_combine);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_2_sd_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_2_sd_combine);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_2_dd_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_2_dd_combine);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_0_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_0_combine);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_0_sd_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_0_sd_combine);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_0_dd_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_0_dd_combine);
      }
      std::cout << "Finish mass_2pt_generate\n" << std::endl;
    }

    bool mass_2pt_generate_afterwards()
    {
      std::cout << "Start mass_2pt_generate_afterwards\n" << std::endl;
      std::vector<double> const_tmp;
      if(this->corr)
      {
	get_vector_const_three_para_result(result_double_jk_corr, const_tmp);
	eff_mass_2pt_wrapper<Lt>(double_jk_corr_sub_fold_fit,sample_mass_2pt_double_jk_corr,const_tmp);
        get_vector_const_three_para_result(result_double_jk_corr_s2_s2, const_tmp);
        eff_mass_2pt_wrapper<Lt>(double_jk_corr_sub_fold_fit_s2_s2,sample_mass_2pt_double_jk_corr_s2_s2,const_tmp);
        get_vector_const_three_para_result(result_double_jk_corr_s3_s3, const_tmp);
        eff_mass_2pt_wrapper<Lt>(double_jk_corr_sub_fold_fit_s3_s3,sample_mass_2pt_double_jk_corr_s3_s3,const_tmp);
      }
      if(this->scat)
      {
	get_vector_const_three_para_result(result_double_jk_scat, const_tmp);
	eff_mass_2pt_wrapper<Lt-tdis>(double_jk_scat_sub_fold_fit,sample_mass_2pt_double_jk_scat,const_tmp);
        get_vector_const_three_para_result(result_double_jk_scat_s2_s2, const_tmp);
        eff_mass_2pt_wrapper<Lt-tdis>(double_jk_scat_sub_fold_fit_s2_s2,sample_mass_2pt_double_jk_scat_s2_s2,const_tmp);
        get_vector_const_three_para_result(result_double_jk_scat_s3_s3, const_tmp);
        eff_mass_2pt_wrapper<Lt-tdis>(double_jk_scat_sub_fold_fit_s3_s3,sample_mass_2pt_double_jk_scat_s3_s3,const_tmp);
      }
      if(this->pipi)
      {
	get_vector_const_three_para_result(result_double_jk_pipiI_2, const_tmp);
	eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_pipiI_2_fold_fit,sample_mass_2pt_double_jk_pipiI_2,const_tmp);
        get_vector_const_three_para_result(result_double_jk_pipiI_2_d1_d1, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_pipiI_2_fold_fit_d1_d1,sample_mass_2pt_double_jk_pipiI_2_d1_d1,const_tmp);
	get_vector_const_three_para_result(result_double_jk_pipiI_0, const_tmp);
	eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_pipiI_0_sub_fold_fit,sample_mass_2pt_double_jk_pipiI_0,const_tmp);
        get_vector_const_three_para_result(result_double_jk_pipiI_0_d1_d1, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_pipiI_0_sub_fold_fit_d1_d1,sample_mass_2pt_double_jk_pipiI_0_d1_d1,const_tmp);
      }
      if(this->comove_pipi)
      {
//	for(int i=0; i<8; i++)
//      {
//	  get_vector_const_three_para_result(result_double_jk_comove_type1_pipiI_2_old[i], const_tmp);
//        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_2_seperate_fold_fit_old[i],sample_mass_2pt_double_jk_comove_type1_pipiI_2_old[i],const_tmp);
//	}
//	get_vector_const_three_para_result(result_double_jk_comove_type1_pipiI_2_combine_old, const_tmp);
//	eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_2_combine_fold_fit_old,sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine_old,const_tmp);
//      get_vector_const_three_para_result(result_double_jk_comove_type1_pipiI_0_combine_old, const_tmp);
//      eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_0_combine_fold_fit_old,sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine_old,const_tmp);
        get_vector_const_three_para_result(result_double_jk_comove_type1_pipiI_2_combine, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_2_combine_fold_fit,sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine,const_tmp);
        get_vector_const_three_para_result(result_double_jk_comove_type1_pipiI_0_combine, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_0_combine_fold_fit,sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine,const_tmp);
        get_vector_const_three_para_result(result_double_jk_comove_type2_pipiI_2_combine, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type2_pipiI_2_combine_fold_fit,sample_mass_2pt_double_jk_comove_type2_pipiI_2_combine,const_tmp);
        get_vector_const_three_para_result(result_double_jk_comove_type2_pipiI_0_combine, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type2_pipiI_0_combine_fold_fit,sample_mass_2pt_double_jk_comove_type2_pipiI_0_combine,const_tmp);
        get_vector_const_three_para_result(result_double_jk_comove_type3_pipiI_2_combine, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_2_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_2_combine,const_tmp);
        get_vector_const_three_para_result(result_double_jk_comove_type3_pipiI_2_sd_combine, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_2_sd_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_2_sd_combine,const_tmp);
        get_vector_const_three_para_result(result_double_jk_comove_type3_pipiI_2_dd_combine, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_2_dd_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_2_dd_combine,const_tmp);
        get_vector_const_three_para_result(result_double_jk_comove_type3_pipiI_0_combine, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_0_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_0_combine,const_tmp);
        get_vector_const_three_para_result(result_double_jk_comove_type3_pipiI_0_sd_combine, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_0_sd_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_0_sd_combine,const_tmp);
        get_vector_const_three_para_result(result_double_jk_comove_type3_pipiI_0_dd_combine, const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type3_pipiI_0_dd_combine_fold_fit,sample_mass_2pt_double_jk_comove_type3_pipiI_0_dd_combine,const_tmp);
      }
      std::cout << "Finish mass_2pt_generate_afterwards\n" << std::endl;
    }

    bool mass_3pt_generate()
    {
      std::cout << "Start mass_3pt_generate\n" << std::endl;
      if(this->pion)
	for(int pidx=0; pidx<4; pidx++)
	  eff_mass_3pt_wrapper(fit_pion[pidx],sample_mass_3pt_pion[pidx]);
      if(this->corr_sub)
	eff_mass_3pt_wrapper(fit_s1_s1_corr_sub,sample_mass_3pt_corr);
      if(this->scat_sub)
	eff_mass_3pt_wrapper(fit_s1_s1_scat_sub,sample_mass_3pt_scat);
      if(this->pipi)
      {
	eff_mass_3pt_wrapper(fit_s1_s1_pipiI_2,sample_mass_3pt_pipiI_2);
	eff_mass_3pt_wrapper(fit_s1_s1_pipiI_0,sample_mass_3pt_pipiI_0);
      }
      std::cout << "Finish mass_3pt_generate\n" << std::endl;
    }

    bool mass_step_output()
    {
      if(this->pion)
      {
	for(int pidx=0; pidx<4; pidx++)
	{
	  cout<<"pion pidx index = "<<pidx<<'\n';
	  eff_mass_step_output_prototype("pion 2pt mass double jk",sample_mass_2pt_double_jk_pion[pidx]);
	  eff_mass_step_output_prototype("pion 3pt mass",sample_mass_3pt_pion[pidx]);
	}
      }
      if(this->corr_sub)
      {
	eff_mass_step_output_prototype("swave1->swave1_sigmacorr 3pt mass",sample_mass_3pt_corr);
	eff_mass_step_output_prototype("swave1->swave1_sigmacorr 2pt mass double jk",sample_mass_2pt_double_jk_corr);

      }
      if(this->scat_sub)
      {
	eff_mass_step_output_prototype("swave1->swave1_pipisigma 3pt mass",sample_mass_3pt_scat);
	eff_mass_step_output_prototype("swave1->swave1_pipisigma 2pt mass double jk",sample_mass_2pt_double_jk_scat);
      }
      if(this->pipi)
      {
	eff_mass_step_output_prototype("swave1->swave1_pipi_scat_I=2 2pt mass double jk",sample_mass_2pt_double_jk_pipiI_2);
	eff_mass_step_output_prototype("swave1->swave1_pipi_scat_I=2 3pt mass",sample_mass_3pt_pipiI_2);
        eff_mass_step_output_prototype("swave1->swave1_pipi_scat_I=0 3pt mass",sample_mass_3pt_pipiI_0);
	eff_mass_step_output_prototype("swave1->swave1_pipi_scat_I=0 2pt mass double jk",sample_mass_2pt_double_jk_pipiI_0);
      }
    }

    bool mass_eff_final()
    {
      std::cout << "Start mass_eff_final\n" << std::endl;
      if(this->pion)
      {
	for(int pidx=0; pidx<4; pidx++)
	{
	  eff_mass_result_prototype(sample_mass_2pt_double_jk_pion[pidx], mass_2pt_double_jk_pion[pidx]);
          eff_mass_result_prototype(sample_mass_3pt_double_jk_pion[pidx], mass_3pt_double_jk_pion[pidx]);
//	  eff_mass_result_prototype(sample_mass_3pt_pion[pidx], mass_3pt_pion[pidx]);
	}
      }
      if(this->corr)
      {
//	eff_mass_result_prototype(sample_mass_3pt_corr, mass_3pt_corr);
	eff_mass_result_prototype(sample_mass_2pt_double_jk_corr, mass_2pt_double_jk_corr);
        eff_mass_result_prototype(sample_mass_2pt_double_jk_corr_s2_s2, mass_2pt_double_jk_corr_s2_s2);
        eff_mass_result_prototype(sample_mass_2pt_double_jk_corr_s3_s3, mass_2pt_double_jk_corr_s3_s3);
	eff_mass_result_prototype(sample_mass_3pt_double_jk_corr, mass_3pt_double_jk_corr);
      }
      if(this->scat)
      {
//	eff_mass_result_prototype(sample_mass_3pt_scat, mass_3pt_scat);
	eff_mass_result_prototype(sample_mass_2pt_double_jk_scat, mass_2pt_double_jk_scat);
        eff_mass_result_prototype(sample_mass_2pt_double_jk_scat_s2_s2, mass_2pt_double_jk_scat_s2_s2);
        eff_mass_result_prototype(sample_mass_2pt_double_jk_scat_s3_s3, mass_2pt_double_jk_scat_s3_s3);
	eff_mass_result_prototype(sample_mass_3pt_double_jk_scat, mass_3pt_double_jk_scat);
      }
      if(this->pipi)
      {
//	eff_mass_result_prototype(sample_mass_3pt_pipiI_2, mass_3pt_pipiI_2);
//        eff_mass_result_prototype(sample_mass_3pt_pipiI_0, mass_3pt_pipiI_0);
        eff_mass_result_prototype(sample_mass_2pt_double_jk_pipiI_2, mass_2pt_double_jk_pipiI_2);
        eff_mass_result_prototype(sample_mass_2pt_double_jk_pipiI_2_d1_d1, mass_2pt_double_jk_pipiI_2_d1_d1);
        eff_mass_result_prototype(sample_mass_3pt_double_jk_pipiI_2, mass_3pt_double_jk_pipiI_2); 
	eff_mass_result_prototype(sample_mass_2pt_double_jk_pipiI_0, mass_2pt_double_jk_pipiI_0);
        eff_mass_result_prototype(sample_mass_2pt_double_jk_pipiI_0_d1_d1, mass_2pt_double_jk_pipiI_0_d1_d1);
	eff_mass_result_prototype(sample_mass_3pt_double_jk_pipiI_0, mass_3pt_double_jk_pipiI_0);
      }
      if(this->comove_pipi)
      {
//	for(int pidx=0; pidx<8; pidx++)
//	{
//	  eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_2_old[pidx], mass_2pt_double_jk_comove_type1_pipiI_2_old[pidx]);
//	  eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_0_old[pidx], mass_2pt_double_jk_comove_type1_pipiI_0_old[pidx]);
//	}
//	eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine_old, mass_2pt_double_jk_comove_type1_pipiI_2_combine_old);
//	eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine_old, mass_2pt_double_jk_comove_type1_pipiI_0_combine_old);
std::cout << "2" << std::endl;
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine, mass_2pt_double_jk_comove_type1_pipiI_2_combine);
std::cout << "3" << std::endl;
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine, mass_2pt_double_jk_comove_type1_pipiI_0_combine);
std::cout << "4" << std::endl;
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type2_pipiI_2_combine, mass_2pt_double_jk_comove_type2_pipiI_2_combine);
std::cout << "5" << std::endl;
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type2_pipiI_0_combine, mass_2pt_double_jk_comove_type2_pipiI_0_combine);
std::cout << "6" << std::endl;
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_2_combine, mass_2pt_double_jk_comove_type3_pipiI_2_combine);
std::cout << "7" << std::endl;
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_2_sd_combine, mass_2pt_double_jk_comove_type3_pipiI_2_sd_combine);
std::cout << "8" << std::endl;
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_2_dd_combine, mass_2pt_double_jk_comove_type3_pipiI_2_dd_combine);
std::cout << "9" << std::endl;
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_0_combine, mass_2pt_double_jk_comove_type3_pipiI_0_combine);
std::cout << "10" << std::endl;
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_0_sd_combine, mass_2pt_double_jk_comove_type3_pipiI_0_sd_combine);
std::cout << "11" << std::endl;
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_0_dd_combine, mass_2pt_double_jk_comove_type3_pipiI_0_dd_combine);
std::cout << "12" << std::endl;
      }
      std::cout << "Finish mass_eff_final\n" << std::endl;
    }

    bool mass_eff_final_output()
    {
      std::cout << "Start mass_eff_final_output\n" << std::endl;
      if(this->pion)
      {
	for(int pidx=0; pidx<4; pidx++)
	{
	  cout<<"pion pidx index = "<<pidx<<'\n';
	  eff_mass_final_output_prototype("pion 2pt final mass double jk", mass_2pt_double_jk_pion[pidx]);
          eff_mass_final_output_prototype("pion 3pt final mass double jk", mass_3pt_double_jk_pion[pidx]);
//	  eff_mass_final_output_prototype("pion 3pt final mass", mass_3pt_pion[pidx]);
	}
      }
      if(this->comove_pipi)
      {
//	for(int pidx=0; pidx<8; pidx++)
//	{
//	  cout << "comove_pipi pidx index = "<< pidx << '\n';
//	  eff_mass_final_output_prototype("comove type1 pipiI_2 2pt final mass double jk old", mass_2pt_double_jk_comove_type1_pipiI_2_old[pidx]);
//	  eff_mass_final_output_prototype("comove type1 pipiI_0 2pt final mass double jk old", mass_2pt_double_jk_comove_type1_pipiI_0_old[pidx]);
//	}
//	eff_mass_final_output_prototype("comove type1 pipiI_2 combined data 2pt final mass double jk old", mass_2pt_double_jk_comove_type1_pipiI_2_combine_old);
//	eff_mass_final_output_prototype("comove type1 pipiI_0 combined data 2pt final mass double jk old", mass_2pt_double_jk_comove_type1_pipiI_0_combine_old);
        eff_mass_final_output_prototype("comove type1 pipiI_2 combined data 2pt final mass double jk", mass_2pt_double_jk_comove_type1_pipiI_2_combine);
        eff_mass_final_output_prototype("comove type1 pipiI_0 combined data 2pt final mass double jk", mass_2pt_double_jk_comove_type1_pipiI_0_combine);
        eff_mass_final_output_prototype("comove type2 pipiI_2 combined data 2pt final mass double jk", mass_2pt_double_jk_comove_type2_pipiI_2_combine);
        eff_mass_final_output_prototype("comove type2 pipiI_0 combined data 2pt final mass double jk", mass_2pt_double_jk_comove_type2_pipiI_0_combine);
        eff_mass_final_output_prototype("comove type3 pipiI_2 combined data 2pt final mass double jk", mass_2pt_double_jk_comove_type3_pipiI_2_combine);
        eff_mass_final_output_prototype("comove type3 pipiI_2 s->d combined data 2pt final mass double jk", mass_2pt_double_jk_comove_type3_pipiI_2_sd_combine);
        eff_mass_final_output_prototype("comove type3 pipiI_2 d->d combined data 2pt final mass double jk", mass_2pt_double_jk_comove_type3_pipiI_2_dd_combine);
        eff_mass_final_output_prototype("comove type3 pipiI_0 combined data 2pt final mass double jk", mass_2pt_double_jk_comove_type3_pipiI_0_combine);
        eff_mass_final_output_prototype("comove type3 pipiI_0 s->d combined data 2pt final mass double jk", mass_2pt_double_jk_comove_type3_pipiI_0_sd_combine);
        eff_mass_final_output_prototype("comove type3 pipiI_0 d->d combined data 2pt final mass double jk", mass_2pt_double_jk_comove_type3_pipiI_0_dd_combine);
      }
      if(this->corr)
      {
//	eff_mass_final_output_prototype("swave1->swave1_sigmacorr 3pt mass", mass_3pt_corr);
	eff_mass_final_output_prototype("swave1->swave1_sigmacorr 2pt mass double jk", mass_2pt_double_jk_corr);
        eff_mass_final_output_prototype("swave1->swave1_sigmacorr s2->s2 2pt mass double jk", mass_2pt_double_jk_corr_s2_s2);
        eff_mass_final_output_prototype("swave1->swave1_sigmacorr s3->s3 2pt mass double jk", mass_2pt_double_jk_corr_s3_s3);
	eff_mass_final_output_prototype("swave1->swave1_sigmacorr 3pt mass double jk", mass_3pt_double_jk_corr);
      }
      if(this->scat)
      {
//	eff_mass_final_output_prototype("swave1->swave1_pipisigma 3pt mass", mass_3pt_scat);
	eff_mass_final_output_prototype("swave1->swave1_pipisigma 2pt mass double jk", mass_2pt_double_jk_scat);
        eff_mass_final_output_prototype("swave1->swave1_pipisigma s2->s2 2pt mass double jk", mass_2pt_double_jk_scat_s2_s2);
        eff_mass_final_output_prototype("swave1->swave1_pipisigma s3->s3 2pt mass double jk", mass_2pt_double_jk_scat_s3_s3);
	eff_mass_final_output_prototype("swave1->swave1_pipisigma 3pt mass double jk", mass_3pt_double_jk_scat);
      }
      if(this->pipi)
      {
//	eff_mass_final_output_prototype("swave1->swave1_pipi_scat_I=2 3pt mass", mass_3pt_pipiI_2);
//      eff_mass_final_output_prototype("swave1->swave1_pipi_scat_I=0 3pt mass", mass_3pt_pipiI_0);
        eff_mass_final_output_prototype("swave1->swave1_pipi_scat_I=2 2pt mass double jk", mass_2pt_double_jk_pipiI_2);
        eff_mass_final_output_prototype("swave1->swave1_pipi_scat_I=2 dwave->dwave 2pt mass double jk", mass_2pt_double_jk_pipiI_2_d1_d1);
        eff_mass_final_output_prototype("swave1->swave1_pipi_scat_I=2 3pt mass double jk", mass_3pt_double_jk_pipiI_2);
	eff_mass_final_output_prototype("swave1->swave1_pipi_scat_I=0 2pt mass double jk", mass_2pt_double_jk_pipiI_0);
        eff_mass_final_output_prototype("swave1->swave1_pipi_scat_I=0 dwave->dwave 2pt mass double jk", mass_2pt_double_jk_pipiI_0_d1_d1);
	eff_mass_final_output_prototype("swave1->swave1_pipi_scat_I=0 3pt mass double jk", mass_3pt_double_jk_pipiI_0);
      }
      std::cout << "Finish mass_eff_final_output\n" << std::endl;
    }


//this section does 2/3 para local fitting for all above thing
  private:
    std::array<std::vector<std::array<double,2> >,4>  result_double_jk_pion;
    std::array<std::vector<std::array<double,2> >,4>  result_double_jk_pion_nofold;
    std::array<std::vector<std::array<double,3> >,8>  result_double_jk_comove_type1_pipiI_2_old;
    std::array<std::vector<std::array<double,3> >,8>  result_double_jk_comove_type1_pipiI_0_old;
    std::vector<std::array<double,3> >      result_double_jk_comove_type1_pipiI_2_combine_old;
    std::vector<std::array<double,3> >      result_double_jk_comove_type1_pipiI_0_combine_old;
    std::vector<std::array<double,3> >      result_double_jk_comove_type1_pipiI_2_combine;
    std::vector<std::array<double,3> >      result_double_jk_comove_type1_pipiI_0_combine;
    std::vector<std::array<double,3> >      result_double_jk_comove_type2_pipiI_2_combine;
    std::vector<std::array<double,3> >      result_double_jk_comove_type2_pipiI_0_combine;
    std::vector<std::array<double,3> >      result_double_jk_comove_type3_pipiI_2_combine;
    std::vector<std::array<double,3> >      result_double_jk_comove_type3_pipiI_2_sd_combine;
    std::vector<std::array<double,3> >      result_double_jk_comove_type3_pipiI_2_dd_combine;
    std::vector<std::array<double,3> >      result_double_jk_comove_type3_pipiI_0_combine;
    std::vector<std::array<double,3> >      result_double_jk_comove_type3_pipiI_0_sd_combine;
    std::vector<std::array<double,3> >      result_double_jk_comove_type3_pipiI_0_dd_combine;
    std::vector<std::array<double,5> >	    result_double_jk_comove_type1_pipiI_0_combine_doublecoshplusconst;
    std::vector<double>                     result_double_jk_comove_type1_pipiI_2_combine_phase;
    std::vector<double>                     result_double_jk_comove_type1_pipiI_0_combine_phase;
    std::vector<double>                     result_double_jk_comove_type2_pipiI_2_combine_phase;
    std::vector<double>                     result_double_jk_comove_type2_pipiI_0_combine_phase;
    std::vector<double>                     result_double_jk_comove_type3_pipiI_2_combine_phase;
    std::vector<double>                     result_double_jk_comove_type3_pipiI_0_combine_phase;

    std::vector<std::array<double,3> >      result_double_jk_pipiI_2;
    std::vector<double>			    result_double_jk_pipiI_2_phase;
    std::vector<std::array<double,3> >      result_double_jk_pipiI_2_s2_s2;
    std::vector<std::array<double,3> >      result_double_jk_pipiI_2_s3_s3;
    std::vector<std::array<double,3> >      result_double_jk_pipiI_2_d1_d1;

    std::vector<std::array<double,4> >      result_double_jk_pipiI_0_nofold;
    std::vector<std::array<double,3> >      result_double_jk_pipiI_0;
    std::vector<double>                     result_double_jk_pipiI_0_phase;
    std::vector<std::array<double,3> >      result_double_jk_pipiI_0_s2_s2;
    std::vector<std::array<double,4> >      result_double_jk_pipiI_0_s2_s2_4_para;
    std::vector<std::array<double,5> >      result_double_jk_pipiI_0_s2_s2_5_para;
    std::vector<std::array<double,3> >      result_double_jk_pipiI_0_s3_s3;
    std::vector<std::array<double,4> >      result_double_jk_pipiI_0_s3_s3_4_para;
    std::vector<std::array<double,5> >      result_double_jk_pipiI_0_s3_s3_5_para;
    std::vector<std::array<double,3> >      result_double_jk_pipiI_0_d1_d1;
    std::vector<std::array<double,4> >      result_double_jk_corr_nofold;
    std::vector<std::array<double,3> >      result_double_jk_corr;
    std::vector<std::array<double,3> >      result_double_jk_corr_s2_s2;
    std::vector<std::array<double,3> >      result_double_jk_corr_s3_s3;
    std::vector<std::array<double,4> >      result_double_jk_scat_nofold;
    std::vector<std::array<double,3> >      result_double_jk_scat;
    std::vector<std::array<double,3> >      result_double_jk_scat_s2_s2;
    std::vector<std::array<double,3> >      result_double_jk_scat_s3_s3;

    std::vector<std::array<double,3> >      result_double_jk_pipiI_0_nosub;
    std::vector<std::array<double,3> >      result_double_jk_pipiI_0_s2_s2_nosub;
    std::vector<std::array<double,3> >      result_double_jk_pipiI_0_s3_s3_nosub;

    std::array<std::pair<double,double>,3>  final_corr;
    std::array<std::pair<double,double>,3>  final_corr_sub;
    std::array<std::pair<double,double>,3>  final_scat;
    std::array<std::pair<double,double>,3>  final_scat_sub;
    std::array<std::pair<double,double>,3>  final_pipiI_2;
    std::array<std::pair<double,double>,3>  final_pipiI_0;

    std::array<std::array<std::pair<double,double>,2>,4>  final_double_jk_pion;
    std::array<std::array<std::pair<double,double>,2>,4>  final_double_jk_pion_nofold;
    std::array<std::array<std::pair<double,double>,3>,8>  final_double_jk_comove_type1_pipiI_2_old;
    std::array<std::array<std::pair<double,double>,3>,8>  final_double_jk_comove_type1_pipiI_0_old;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type1_pipiI_2_combine_old;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type1_pipiI_0_combine_old;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type1_pipiI_2_combine;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type1_pipiI_0_combine;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type2_pipiI_2_combine;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type2_pipiI_0_combine;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type3_pipiI_2_combine;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type3_pipiI_2_sd_combine;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type3_pipiI_2_dd_combine;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type3_pipiI_0_combine;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type3_pipiI_0_sd_combine;
    std::array<std::pair<double,double>,3>  final_double_jk_comove_type3_pipiI_0_dd_combine;
    std::array<std::pair<double,double>,5>  final_double_jk_comove_type1_pipiI_0_combine_doublecoshplusconst;
    std::array<std::pair<double,double>,3>  final_double_jk_pipiI_2;
    std::array<std::pair<double,double>,3>  final_double_jk_pipiI_2_s2_s2;
    std::array<std::pair<double,double>,3>  final_double_jk_pipiI_2_s3_s3;
    std::array<std::pair<double,double>,3>  final_double_jk_pipiI_2_d1_d1;

    std::array<std::pair<double,double>,4>  final_double_jk_pipiI_0_nofold;
    std::array<std::pair<double,double>,3>  final_double_jk_pipiI_0;
    std::array<std::pair<double,double>,3>  final_double_jk_pipiI_0_s2_s2;
    std::array<std::pair<double,double>,4>  final_double_jk_pipiI_0_s2_s2_4_para;
    std::array<std::pair<double,double>,5>  final_double_jk_pipiI_0_s2_s2_5_para;
    std::array<std::pair<double,double>,3>  final_double_jk_pipiI_0_s3_s3;
    std::array<std::pair<double,double>,4>  final_double_jk_pipiI_0_s3_s3_4_para;
    std::array<std::pair<double,double>,5>  final_double_jk_pipiI_0_s3_s3_5_para;
    std::array<std::pair<double,double>,3>  final_double_jk_pipiI_0_d1_d1;
    std::array<std::pair<double,double>,4>  final_double_jk_corr_nofold;
    std::array<std::pair<double,double>,3>  final_double_jk_corr;
    std::array<std::pair<double,double>,3>  final_double_jk_corr_s2_s2;
    std::array<std::pair<double,double>,3>  final_double_jk_corr_s3_s3;
    std::array<std::pair<double,double>,4>  final_double_jk_scat_nofold;
    std::array<std::pair<double,double>,3>  final_double_jk_scat;
    std::array<std::pair<double,double>,3>  final_double_jk_scat_s2_s2;
    std::array<std::pair<double,double>,3>  final_double_jk_scat_s3_s3;

  public:

    void fit_single_ensemble(int t_min, int t_max)
    {
      for(int i=0; i<4; i++)
      {
        two_para_cor_fit_prototype<Lt>("pioncorr_corfit", double_jk_pion_fold_fit[i], double_jk_pion_fold_cov_mat[i], result_double_jk_pion[i], t_min-1,31-t_max);
//        two_para_cor_fit_prototype<Lt>("pioncorr_corfit_nofold", double_jk_pion_fit[i], double_jk_pion_cov_mat[i], result_double_jk_pion_nofold[i], t_min-1,63-t_max);
      }
      if(this->comove_pipi)
      {
        for(int i=0; i<8; i++)
        {
	  three_para_cor_fit_prototype<Lt-2*tdis>("comove_pipiI_2_corfit old", double_jk_comove_type1_pipiI_2_seperate_fold_fit_old[i], double_jk_comove_type1_pipiI_2_seperate_fold_cov_mat_old[i], result_double_jk_comove_type1_pipiI_2_old[i], t_min-1,27-t_max);
	  three_para_cor_fit_prototype<Lt-2*tdis>("comove_pipiI_0_corfit old", double_jk_comove_type1_pipiI_0_seperate_fold_fit_old[i], double_jk_comove_type1_pipiI_0_seperate_fold_cov_mat_old[i], result_double_jk_comove_type1_pipiI_0_old[i], t_min-1,27-t_max);
        }
        DoubleCoshPlusConst_cor_fit_prototype<Lt-2*tdis>("type1_comove_pipiI_0_combined_data_corfit_doublecosh+const", double_jk_comove_type1_pipiI_0_combine_fold_fit, double_jk_comove_type1_pipiI_0_combine_fold_cov_mat, result_double_jk_comove_type1_pipiI_0_combine_doublecoshplusconst, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type1_comove_pipiI_2_combined_data_corfit_old", double_jk_comove_type1_pipiI_2_combine_fold_fit_old, double_jk_comove_type1_pipiI_2_combine_fold_cov_mat_old, result_double_jk_comove_type1_pipiI_2_combine_old, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type1_comove_pipiI_0_combined_data_corfit_old", double_jk_comove_type1_pipiI_0_combine_fold_fit_old, double_jk_comove_type1_pipiI_0_combine_fold_cov_mat_old, result_double_jk_comove_type1_pipiI_0_combine_old, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type1_comove_pipiI_2_combined_data_corfit", double_jk_comove_type1_pipiI_2_combine_fold_fit, double_jk_comove_type1_pipiI_2_combine_fold_cov_mat, result_double_jk_comove_type1_pipiI_2_combine, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type1_comove_pipiI_0_combined_data_corfit", double_jk_comove_type1_pipiI_0_combine_fold_fit, double_jk_comove_type1_pipiI_0_combine_fold_cov_mat, result_double_jk_comove_type1_pipiI_0_combine, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type2_comove_pipiI_2_combined_data_corfit", double_jk_comove_type2_pipiI_2_combine_fold_fit, double_jk_comove_type2_pipiI_2_combine_fold_cov_mat, result_double_jk_comove_type2_pipiI_2_combine, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type2_comove_pipiI_0_combined_data_corfit", double_jk_comove_type2_pipiI_0_combine_fold_fit, double_jk_comove_type2_pipiI_0_combine_fold_cov_mat, result_double_jk_comove_type2_pipiI_0_combine, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type3_comove_pipiI_2_combined_data_corfit", double_jk_comove_type3_pipiI_2_combine_fold_fit, double_jk_comove_type3_pipiI_2_combine_fold_cov_mat, result_double_jk_comove_type3_pipiI_2_combine, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type3_comove_pipiI_2_s->d_combined_data_corfit", double_jk_comove_type3_pipiI_2_sd_combine_fold_fit, double_jk_comove_type3_pipiI_2_sd_combine_fold_cov_mat, result_double_jk_comove_type3_pipiI_2_sd_combine, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type3_comove_pipiI_2_d->d_combined_data_corfit", double_jk_comove_type3_pipiI_2_dd_combine_fold_fit, double_jk_comove_type3_pipiI_2_dd_combine_fold_cov_mat, result_double_jk_comove_type3_pipiI_2_dd_combine, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type3_comove_pipiI_0_combined_data_corfit", double_jk_comove_type3_pipiI_0_combine_fold_fit, double_jk_comove_type3_pipiI_0_combine_fold_cov_mat, result_double_jk_comove_type3_pipiI_0_combine, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type3_comove_pipiI_0_s->d_combined_data_corfit", double_jk_comove_type3_pipiI_0_sd_combine_fold_fit, double_jk_comove_type3_pipiI_0_sd_combine_fold_cov_mat, result_double_jk_comove_type3_pipiI_0_sd_combine, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("type3_comove_pipiI_0_d->d_combined_data_corfit", double_jk_comove_type3_pipiI_0_dd_combine_fold_fit, double_jk_comove_type3_pipiI_0_dd_combine_fold_cov_mat, result_double_jk_comove_type3_pipiI_0_dd_combine, t_min-1,27-t_max);
      }
      if(this->pipi)
      {
        three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=2_corfit", double_jk_pipiI_2_fold_fit, double_jk_pipiI_2_fold_cov_mat, result_double_jk_pipiI_2, t_min-1,27-t_max);
//        three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=2_corfit_s2_s2", double_jk_pipiI_2_fold_fit_s2_s2, double_jk_pipiI_2_fold_cov_mat_s2_s2, result_double_jk_pipiI_2_s2_s2, t_min-1,27-t_max);
//        three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=2_corfit_s3_s3", double_jk_pipiI_2_fold_fit_s3_s3, double_jk_pipiI_2_fold_cov_mat_s3_s3, result_double_jk_pipiI_2_s3_s3, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=2_corfit_d1_d1", double_jk_pipiI_2_fold_fit_d1_d1, double_jk_pipiI_2_fold_cov_mat_d1_d1, result_double_jk_pipiI_2_d1_d1, t_min-1,27-t_max);
//        four_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_nofolding_corfit", double_jk_pipiI_0_sub_fit, double_jk_pipiI_0_sub_cov_mat, result_double_jk_pipiI_0_nofold, 5,13);
        three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_corfit", double_jk_pipiI_0_sub_fold_fit, double_jk_pipiI_0_sub_fold_cov_mat, result_double_jk_pipiI_0, t_min-1,27-t_max);
//        three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_s2_s2_corfit", double_jk_pipiI_0_sub_fold_fit_s2_s2, double_jk_pipiI_0_sub_fold_cov_mat_s2_s2, result_double_jk_pipiI_0_s2_s2, t_min-1,27-t_max);
//        double_exp_fix_one_mass_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_s2_s2_double_exp_one_fixed_mass_corfit", double_jk_pipiI_0_sub_fold_fit_s2_s2, double_jk_pipiI_0_sub_fold_cov_mat_s2_s2, result_double_jk_pipiI_0_s2_s2_4_para, t_min-1,27-t_max);
//        double_exp_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_s2_s2_double_exp_corfit", double_jk_pipiI_0_sub_fold_fit_s2_s2, double_jk_pipiI_0_sub_fold_cov_mat_s2_s2, result_double_jk_pipiI_0_s2_s2_5_para, t_min-1,27-t_max);
//        three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_s3_s3_corfit", double_jk_pipiI_0_sub_fold_fit_s3_s3, double_jk_pipiI_0_sub_fold_cov_mat_s3_s3, result_double_jk_pipiI_0_s3_s3, t_min-1,27-t_max);
//        double_exp_fix_one_mass_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_s3_s3_double_exp_one_fixed_mass_corfit", double_jk_pipiI_0_sub_fold_fit_s3_s3, double_jk_pipiI_0_sub_fold_cov_mat_s3_s3, result_double_jk_pipiI_0_s3_s3_4_para, t_min-1,27-t_max);
//        double_exp_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_s3_s3_double_exp_corfit", double_jk_pipiI_0_sub_fold_fit_s3_s3, double_jk_pipiI_0_sub_fold_cov_mat_s3_s3, result_double_jk_pipiI_0_s3_s3_5_para, t_min-1,27-t_max);
        three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_d1_d1_corfit", double_jk_pipiI_0_sub_fold_fit_d1_d1, double_jk_pipiI_0_sub_fold_cov_mat_d1_d1, result_double_jk_pipiI_0_d1_d1, t_min-1,27-t_max);
      }
      if(this->corr_sub)
      {
//        four_para_cor_fit_prototype<Lt>("sigmacorr_corfit_nofolding", double_jk_corr_sub_fit, double_jk_corr_sub_cov_mat, result_double_jk_corr_nofold, 5,5);
        three_para_cor_fit_prototype<Lt>("sigmacorr_corfit", double_jk_corr_sub_fold_fit, double_jk_corr_sub_fold_cov_mat, result_double_jk_corr,t_min-1,31-t_max);
        three_para_cor_fit_prototype<Lt>("sigmacorr_corfit_s2_s2", double_jk_corr_sub_fold_fit_s2_s2, double_jk_corr_sub_fold_cov_mat_s2_s2, result_double_jk_corr_s2_s2, t_min-1,31-t_max);
        three_para_cor_fit_prototype<Lt>("sigmacorr_corfit_s3_s3", double_jk_corr_sub_fold_fit_s3_s3, double_jk_corr_sub_fold_cov_mat_s3_s3, result_double_jk_corr_s3_s3, t_min-1,31-t_max);
      }
      if(this->scat_sub)
      {
//        four_para_cor_fit_prototype<Lt-tdis>("pipisigma_corfit_nofolding", double_jk_scat_sub_fit, double_jk_scat_sub_cov_mat, result_double_jk_scat_nofold, 5,9);
        three_para_cor_fit_prototype<Lt-tdis>("pipisigma_corfit", double_jk_scat_sub_fold_fit, double_jk_scat_sub_fold_cov_mat, result_double_jk_scat, t_min-1,29-t_max);
        three_para_cor_fit_prototype<Lt-tdis>("pipisigma_corfit_s2_s2", double_jk_scat_sub_fold_fit_s2_s2, double_jk_scat_sub_fold_cov_mat_s2_s2, result_double_jk_scat_s2_s2, t_min-1,29-t_max);
        three_para_cor_fit_prototype<Lt-tdis>("pipisigma_corfit_s3_s3", double_jk_scat_sub_fold_fit_s3_s3, double_jk_scat_sub_fold_cov_mat_s3_s3, result_double_jk_scat_s3_s3, t_min-1,29-t_max);
      }
    }

    void fit_sample_phase()
    {
      if(this->pipi)
      {
        for(int i=0; i<result_double_jk_pipiI_2.size(); i++)
          result_double_jk_pipiI_2_phase.push_back(calc_stationary_pipi_phase(result_double_jk_pipiI_2[i][1]));
        for(int i=0; i<result_double_jk_pipiI_0.size(); i++)
          result_double_jk_pipiI_0_phase.push_back(calc_stationary_pipi_phase(result_double_jk_pipiI_0[i][1]));
      }
      if(this->comove_pipi)
      {
        for(int i=0; i<result_double_jk_comove_type1_pipiI_2_combine.size(); i++)
          result_double_jk_comove_type1_pipiI_2_combine_phase.push_back(calc_pipi_phase_general(type1_mom,result_double_jk_comove_type1_pipiI_2_combine[i][1]));
        for(int i=0; i<result_double_jk_comove_type1_pipiI_0_combine.size(); i++)
          result_double_jk_comove_type1_pipiI_0_combine_phase.push_back(calc_pipi_phase_general(type1_mom,result_double_jk_comove_type1_pipiI_0_combine[i][1]));
        for(int i=0; i<result_double_jk_comove_type2_pipiI_2_combine.size(); i++)
          result_double_jk_comove_type2_pipiI_2_combine_phase.push_back(calc_pipi_phase_general(type2_mom,result_double_jk_comove_type2_pipiI_2_combine[i][1]));
        for(int i=0; i<result_double_jk_comove_type2_pipiI_0_combine.size(); i++)
          result_double_jk_comove_type2_pipiI_0_combine_phase.push_back(calc_pipi_phase_general(type2_mom,result_double_jk_comove_type2_pipiI_0_combine[i][1]));
        for(int i=0; i<result_double_jk_comove_type3_pipiI_2_combine.size(); i++)
          result_double_jk_comove_type3_pipiI_2_combine_phase.push_back(calc_pipi_phase_general(type3_mom,result_double_jk_comove_type3_pipiI_2_combine[i][1]));
        for(int i=0; i<result_double_jk_comove_type3_pipiI_0_combine.size(); i++)
          result_double_jk_comove_type3_pipiI_0_combine_phase.push_back(calc_pipi_phase_general(type3_mom,result_double_jk_comove_type3_pipiI_0_combine[i][1]));
      }
    }

    void fit_single_ensemble_nosub()
    {
      three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_corfit", double_jk_pipiI_0_sub_fold_fit, double_jk_pipiI_0_sub_fold_cov_mat, result_double_jk_pipiI_0_nosub, 5,2);
      three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_s2_s2_corfit", double_jk_pipiI_0_sub_fold_fit_s2_s2, double_jk_pipiI_0_sub_fold_cov_mat_s2_s2, result_double_jk_pipiI_0_s2_s2_nosub, 5,2);
      three_para_cor_fit_prototype<Lt-2*tdis>("pipi_scat_I=0_withsub_s3_s3_corfit", double_jk_pipiI_0_sub_fold_fit_s3_s3, double_jk_pipiI_0_sub_fold_cov_mat_s3_s3, result_double_jk_pipiI_0_s3_s3_nosub, 5,2);
    }

    template<int n_para>
    void cov_test_prototype(std::string name, std::vector<std::array<double,n_para> > input1, std::vector<std::array<double,n_para> > input2)
    {
      cout<<"Now we are checking if two fitting process will give us a highly correlated result\n";
      int n_traj = input1.size();
      assert(n_traj == input2.size());
      for(int n=0; n<n_para; n++)
      {
	std::vector<double> tmp1, tmp2;
	tmp1.resize(0);
	tmp2.resize(0);
	for(int t=0; t<n_traj; t++)
	{
	  tmp1.push_back(input1[t][n]);
	  tmp2.push_back(input2[t][n]);
	}
	cout<<"This is para "<<n<<"  and var(1,1)=   "<<vec_cov_err(tmp1,tmp1)<<"\tvar(1,2)=   "<<vec_cov_err(tmp1,tmp2)<<"\tvar(2,1)=   "<<vec_cov_err(tmp2,tmp1)<<"\tvar(2,2)=   "<<vec_cov_err(tmp2,tmp2)<<'\n';
      }
    }

    void cov_test_sub_nosub()
    {
      output_data("pipi_scat_I=0_withsub_corfit",result_double_jk_pipiI_0_nosub,true);
      output_data("pipi_scat_I=0_withsub_s2_s2_corfit",result_double_jk_pipiI_0_s2_s2,true);
      output_data("pipi_scat_I=0_withsub_s3_s3_corfit",result_double_jk_pipiI_0_s3_s3,true);
      cov_test_prototype<3>("pipiI=0 sub/nosub", result_double_jk_pipiI_0, result_double_jk_pipiI_0_nosub);
      cov_test_prototype<3>("pipiI=0_s2_s2 sub/nosub", result_double_jk_pipiI_0_s2_s2, result_double_jk_pipiI_0_s2_s2_nosub);
      cov_test_prototype<3>("pipiI=0_s3_s3 sub/nosub", result_double_jk_pipiI_0_s3_s3, result_double_jk_pipiI_0_s3_s3_nosub);
    }

    void fit_single_ensemble_output()
    {
      output_data("pipi_scat_I=0_withsub_corfit",result_double_jk_pipiI_0,true);
      output_data("pipi_scat_I=0_withsub_s2_s2_corfit",result_double_jk_pipiI_0_s2_s2,true);
      output_data("pipi_scat_I=0_withsub_s3_s3_corfit",result_double_jk_pipiI_0_s3_s3,true);
      output_data("pipi_scat_I=0_withsub_d1_d1_corfit",result_double_jk_pipiI_0_d1_d1,true);
      output_data("sigmacorr_corfit",result_double_jk_corr);
      output_data("pipisigma_corfit",result_double_jk_scat);
    }


    void fit_result()
    {
      if(this->pion)
      {
        for(int i=0; i<4; i++)
        {
          para_result<2>(result_double_jk_pion[i], final_double_jk_pion[i]);
          para_result<2>(result_double_jk_pion_nofold[i], final_double_jk_pion_nofold[i]);
        }
      }
      if(this->comove_pipi)
      {
        for(int i=0; i<8; i++)
        {
          para_result<3>(result_double_jk_comove_type1_pipiI_2_old[i], final_double_jk_comove_type1_pipiI_2_old[i]);
          para_result<3>(result_double_jk_comove_type1_pipiI_0_old[i], final_double_jk_comove_type1_pipiI_0_old[i]);
        }
        para_result<3>(result_double_jk_comove_type1_pipiI_2_combine_old, final_double_jk_comove_type1_pipiI_2_combine_old);
        para_result<3>(result_double_jk_comove_type1_pipiI_0_combine_old, final_double_jk_comove_type1_pipiI_0_combine_old);
        para_result<3>(result_double_jk_comove_type1_pipiI_2_combine, final_double_jk_comove_type1_pipiI_2_combine);
        para_result<3>(result_double_jk_comove_type1_pipiI_0_combine, final_double_jk_comove_type1_pipiI_0_combine);
        para_result<3>(result_double_jk_comove_type2_pipiI_2_combine, final_double_jk_comove_type2_pipiI_2_combine);
        para_result<3>(result_double_jk_comove_type2_pipiI_0_combine, final_double_jk_comove_type2_pipiI_0_combine);
        para_result<3>(result_double_jk_comove_type3_pipiI_2_combine, final_double_jk_comove_type3_pipiI_2_combine);
        para_result<3>(result_double_jk_comove_type3_pipiI_2_sd_combine, final_double_jk_comove_type3_pipiI_2_sd_combine);
        para_result<3>(result_double_jk_comove_type3_pipiI_2_dd_combine, final_double_jk_comove_type3_pipiI_2_dd_combine);
        para_result<3>(result_double_jk_comove_type3_pipiI_0_combine, final_double_jk_comove_type3_pipiI_0_combine);
        para_result<3>(result_double_jk_comove_type3_pipiI_0_sd_combine, final_double_jk_comove_type3_pipiI_0_sd_combine);
        para_result<3>(result_double_jk_comove_type3_pipiI_0_dd_combine, final_double_jk_comove_type3_pipiI_0_dd_combine);
        para_result<5>(result_double_jk_comove_type1_pipiI_0_combine_doublecoshplusconst, final_double_jk_comove_type1_pipiI_0_combine_doublecoshplusconst);
      }
      if(this->pipi)
      {
        para_result<3>(result_double_jk_pipiI_2, final_double_jk_pipiI_2);
        para_result<3>(result_double_jk_pipiI_2_s2_s2, final_double_jk_pipiI_2_s2_s2);
        para_result<3>(result_double_jk_pipiI_2_s3_s3, final_double_jk_pipiI_2_s3_s3);
        para_result<3>(result_double_jk_pipiI_2_d1_d1, final_double_jk_pipiI_2_d1_d1);
        para_result<4>(result_double_jk_pipiI_0_nofold, final_double_jk_pipiI_0_nofold);
        para_result<3>(result_double_jk_pipiI_0, final_double_jk_pipiI_0);
        para_result<3>(result_double_jk_pipiI_0_s2_s2, final_double_jk_pipiI_0_s2_s2);
        para_result<4>(result_double_jk_pipiI_0_s2_s2_4_para, final_double_jk_pipiI_0_s2_s2_4_para);
        para_result<5>(result_double_jk_pipiI_0_s2_s2_5_para, final_double_jk_pipiI_0_s2_s2_5_para);
        para_result<3>(result_double_jk_pipiI_0_s3_s3, final_double_jk_pipiI_0_s3_s3);
        para_result<4>(result_double_jk_pipiI_0_s3_s3_4_para, final_double_jk_pipiI_0_s3_s3_4_para);
        para_result<5>(result_double_jk_pipiI_0_s3_s3_5_para, final_double_jk_pipiI_0_s3_s3_5_para);
        para_result<3>(result_double_jk_pipiI_0_d1_d1, final_double_jk_pipiI_0_d1_d1);
      }
      if(this->corr)
      {
        para_result<4>(result_double_jk_corr_nofold, final_double_jk_corr_nofold);
        para_result<3>(result_double_jk_corr, final_double_jk_corr);
        para_result<3>(result_double_jk_corr_s2_s2, final_double_jk_corr_s2_s2);
        para_result<3>(result_double_jk_corr_s3_s3, final_double_jk_corr_s3_s3);
      }
      if(this->scat)
      {
        para_result<4>(result_double_jk_scat_nofold, final_double_jk_scat_nofold);
        para_result<3>(result_double_jk_scat, final_double_jk_scat);
        para_result<3>(result_double_jk_scat_s2_s2, final_double_jk_scat_s2_s2);
        para_result<3>(result_double_jk_scat_s3_s3, final_double_jk_scat_s3_s3);
      }
    }

    void fit_final()
    {
      if(this->pion)
      {
        for(int i=0; i<4; i++)
        {
          output_data("pioncorr_corfit",final_double_jk_pion[i]);
          output_data("pioncorr_corfit_nofold",final_double_jk_pion_nofold[i]);
        }
      }
      if(this->comove_pipi)
      {
        for(int i=0; i<8; i++)
        {
	  output_data("comove_pipiI_2_corfit_old",final_double_jk_comove_type1_pipiI_2_old[i]);
	  output_data("comove_pipiI_0_corfit_old",final_double_jk_comove_type1_pipiI_0_old[i]);
        }
	output_data("type1_comove_pipiI_2_combined_data_corfit_old",final_double_jk_comove_type1_pipiI_2_combine_old);
	output_data("type1_comove_pipiI_0_combined_data_corfit_old",final_double_jk_comove_type1_pipiI_0_combine_old);
        output_data("type1_comove_pipiI_2_combined_data_corfit",final_double_jk_comove_type1_pipiI_2_combine);
        output_data("type1_comove_pipiI_0_combined_data_corfit",final_double_jk_comove_type1_pipiI_0_combine);
        output_data("type2_comove_pipiI_2_combined_data_corfit",final_double_jk_comove_type2_pipiI_2_combine);
        output_data("type2_comove_pipiI_0_combined_data_corfit",final_double_jk_comove_type2_pipiI_0_combine);
        output_data("type3_comove_pipiI_2_combined_data_corfit",final_double_jk_comove_type3_pipiI_2_combine);
        output_data("type3_comove_pipiI_2_s->d_combined_data_corfit",final_double_jk_comove_type3_pipiI_2_sd_combine);
        output_data("type3_comove_pipiI_2_d->d_combined_data_corfit",final_double_jk_comove_type3_pipiI_2_dd_combine);
        output_data("type3_comove_pipiI_0_combined_data_corfit",final_double_jk_comove_type3_pipiI_0_combine);
        output_data("type3_comove_pipiI_0_s->d_combined_data_corfit",final_double_jk_comove_type3_pipiI_0_sd_combine);
        output_data("type3_comove_pipiI_0_d->d_combined_data_corfit",final_double_jk_comove_type3_pipiI_0_dd_combine);
        output_data("type1_comove_pipiI_0_combined_data_corfit_DoubleCoshPlusConst",final_double_jk_comove_type1_pipiI_0_combine_doublecoshplusconst);
        cout << "comove_type1_pipiI_2 phase shift is " << vec_avg(result_double_jk_comove_type1_pipiI_2_combine_phase) << "  with err = " << jack_vec_err(result_double_jk_comove_type1_pipiI_2_combine_phase) << '\n';
        cout << "comove_type1_pipiI_0 phase shift is " << vec_avg(result_double_jk_comove_type1_pipiI_0_combine_phase) << "  with err = " << jack_vec_err(result_double_jk_comove_type1_pipiI_0_combine_phase) << '\n';
        cout << "comove_type2_pipiI_2 phase shift is " << vec_avg(result_double_jk_comove_type2_pipiI_2_combine_phase) << "  with err = " << jack_vec_err(result_double_jk_comove_type2_pipiI_2_combine_phase) << '\n';
        cout << "comove_type2_pipiI_0 phase shift is " << vec_avg(result_double_jk_comove_type2_pipiI_0_combine_phase) << "  with err = " << jack_vec_err(result_double_jk_comove_type2_pipiI_0_combine_phase) << '\n';
        cout << "comove_type3_pipiI_2 phase shift is " << vec_avg(result_double_jk_comove_type3_pipiI_2_combine_phase) << "  with err = " << jack_vec_err(result_double_jk_comove_type3_pipiI_2_combine_phase) << '\n';
        cout << "comove_type3_pipiI_0 phase shift is " << vec_avg(result_double_jk_comove_type3_pipiI_0_combine_phase) << "  with err = " << jack_vec_err(result_double_jk_comove_type3_pipiI_0_combine_phase) << '\n';
      }
      if(this->pipi)
      {
        cout << "pipiI_2 phase shift is " << vec_avg(result_double_jk_pipiI_2_phase) << "  with err = " << jack_vec_err(result_double_jk_pipiI_2_phase) << '\n';
        cout << "pipiI_0 phase shift is " << vec_avg(result_double_jk_pipiI_0_phase) << "  with err = " << jack_vec_err(result_double_jk_pipiI_0_phase) << '\n';
        output_data("pipi_scat_I=2_withsub_corfit",final_double_jk_pipiI_2);
	output_data("pipi_scat_I=2_withsub_corfit_s2_s2",final_double_jk_pipiI_2_s2_s2);
	output_data("pipi_scat_I=2_withsub_corfit_s3_s3",final_double_jk_pipiI_2_s3_s3);
	output_data("pipi_scat_I=2_withsub_corfit_d1_d1",final_double_jk_pipiI_2_d1_d1);
        output_data("pipi_scat_I=0_withsub_corfit_nofold",final_double_jk_pipiI_0_nofold);
        output_data("pipi_scat_I=0_withsub_corfit",final_double_jk_pipiI_0);
        output_data("pipi_scat_I=0_withsub_s2_s2_corfit",final_double_jk_pipiI_0_s2_s2);
        output_data("pipi_scat_I=0_withsub_s2_s2_double_exp_fixed_mass_corfit",final_double_jk_pipiI_0_s2_s2_4_para);
        output_data("pipi_scat_I=0_withsub_s2_s2_corfit_double_exp",final_double_jk_pipiI_0_s2_s2_5_para);
        output_data("pipi_scat_I=0_withsub_s3_s3_corfit",final_double_jk_pipiI_0_s3_s3);
        output_data("pipi_scat_I=0_withsub_s3_s3_double_exp_fixed_mass_corfit",final_double_jk_pipiI_0_s3_s3_4_para);
        output_data("pipi_scat_I=0_withsub_s3_s3_corfit_double_exp",final_double_jk_pipiI_0_s3_s3_5_para);
        output_data("pipi_scat_I=0_withsub_d1_d1_corfit",final_double_jk_pipiI_0_d1_d1);
      }
      if(this->corr)
      {
        output_data("sigmacorr_corfit_nofold",final_double_jk_corr_nofold);
        output_data("sigmacorr_corfit",final_double_jk_corr);
        output_data("sigmacorr_corfit_s2_s2",final_double_jk_corr_s2_s2);
        output_data("sigmacorr_corfit_s3_s3",final_double_jk_corr_s3_s3);
      }
      if(this->scat)
      {
        output_data("pipisigma_corfit_nofold",final_double_jk_scat_nofold);
        output_data("pipisigma_corfit",final_double_jk_scat);
        output_data("pipisigma_corfit_s2_s2",final_double_jk_scat_s2_s2);
        output_data("pipisigma_corfit_s3_s3",final_double_jk_scat_s3_s3);
      }
    }

    void fit_one_complete_step(int t_min, int t_max, bool do_mass_after_sub=false, bool step_output=false)
    {
      fit_single_ensemble(t_min,t_max);
      fit_sample_phase();
      if(step_output) {  fit_single_ensemble_output();  }
      fit_result();
      if(do_mass_after_sub)
      {
        mass_2pt_generate_afterwards();
        mass_eff_final();
        mass_eff_final_output();
      }
      fit_final();
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

    bool read_single_file(std::string fs, int keycode, std::map<int,std::array<double,Lt> > &output)
    {
      auto it = output.find(keycode);
      assert(it == output.end() && "ERROR: reading comoving Vdata failed since there is already a file exist with the same momentum");
      ifstream infile(fs.c_str());
      if(infile.is_open())
      {
        for(int i=0; i<Lt; i++)
        {
          output[keycode][i] = 0.0;
        }
        int tsrc=0;
        double reval=0.0, imval=0.0;
        while(infile >> tsrc >> reval >> imval)
          output[keycode][tsrc]=reval;
        cout << "successfully reading file with name "<< fs <<'\n';
        infile.close();
        return true;
      }
      else
        return false;
    }

    bool read_single_file_comp(std::string fs, int keycode, std::map<int,std::array<std::complex<double>,Lt> > &output)
    {
      auto it = output.find(keycode);
      assert(it == output.end() && "ERROR: reading comoving Vdata failed since there is already a file exist with the same momentum");
      ifstream infile(fs.c_str());
      if(infile.is_open())
      {
        for(int i=0; i<Lt; i++)
        {
          output[keycode][i] = 0.0;
        }
        int tsrc=0;
        double reval=0.0, imval=0.0;
        while(infile >> tsrc >> reval >> imval)
        {
          output[keycode][tsrc].real(reval);
          output[keycode][tsrc].imag(imval);
        }
        cout << "successfully reading file with name "<< fs <<'\n';
        infile.close();
        return true;
      }
      else
        return false;
    }

    bool read_single_file(std::string fs, int keycode, std::map<int,std::array<double,Lt*Lt/tstep> > &output)
    {
      auto it = output.find(keycode);
      assert(it == output.end() && "ERROR: reading comoving data failed since there is already a file exist with the same momentum");
      ifstream infile(fs.c_str());
      if(infile.is_open())
      {
        for(int i=0; i<Lt*Lt/tstep; i++)
        {
          output[keycode][i] = 0.0;
        }
        int tsrc=0, tdis=0, idx=0;
        double reval=0.0, imval=0.0;
        while(infile >> tsrc >> tdis >> reval >> imval)
        {
          if(tsrc % tstep == 0)
          {
            output[keycode][idx]=reval;
            idx++;
          }
        }
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

    bool tavg_generate_prototype(std::vector<std::map<int,std::array<double,Lt*Lt/tstep> > > input, std::vector<std::map<int,std::array<double,Lt> > > &output)
    {
      output.resize(input.size());
      for(int traj=0; traj<input.size(); traj++)
      {
        for(auto it=input[traj].cbegin(); it!=input[traj].cend(); it++)
        {
          assert(output[traj].find(it->first)==output[traj].end());
          for(int i=0; i<Lt; i++)
            output[traj][it->first][i] = 0.0;
          for(int i=0; i<Lt*Lt/tstep; i++)                  
            output[traj][it->first][i%Lt] += (it->second)[i];
          for(int i=0; i<Lt; i++)
            output[traj][it->first][i] /= (Lt/tstep);
        }
      }
    }

    template<int N_pidx>
    bool vacuum_sortout_prototype(std::array<std::vector<std::pair<std::array<double,Lt*Lt>,int> >,N_pidx > input, std::array<std::vector<std::pair<std::array<double,Lt>,int> >,N_pidx> &output, int tsep)
    {
      for(int pidx=0; pidx<N_pidx; pidx++)
      {
	output[pidx].resize(input[pidx].size());
	for(int traj=0; traj<output[pidx].size(); traj++)
	{
	  output[pidx][traj].second=input[pidx][traj].second;
	  for(int idx=0; idx<Lt; idx++)
	    output[pidx][traj].first[idx]=input[pidx][traj].first[idx*Lt+tsep];
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

    bool rep_proj_prototype(const std::vector<std::map<int,std::array<double,Lt> > > &input, std::vector<std::pair<std::array<double,Lt>,int> > &output)
    {
      output.resize(input.size());
      for(int traj=0; traj<input.size(); traj++)
      {
        output[traj].second = traj;
        for(int idx=0; idx<Lt; idx++)
        {
          output[traj].first[idx] = 0.0;
          int count = 0;
          for(auto it=input[traj].cbegin(); it!=input[traj].cend(); it++)
          {
            output[traj].first[idx] += it->second[idx];
            count++;
          }
          output[traj].first[idx] /= double(count);
        }
      }
    }
   
    template<class T>
    bool rep_proj_advance(const std::vector<std::map<int,std::array<double,Lt> > > &input, std::vector<std::pair<std::array<double,Lt>,int> > &output, T coeff)
    {
      output.resize(input.size());
      for(int traj=0; traj<input.size(); traj++)
      {
        output[traj].second = traj;
        for(int idx=0; idx<Lt; idx++)
        {
          output[traj].first[idx] = 0.0;
          int count = 0;
          for(auto it=input[traj].cbegin(); it!=input[traj].cend(); it++)
          {
            output[traj].first[idx] += it->second[idx] * coeff[it->first];
            count++;
          }
          output[traj].first[idx] /= double(count);
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

    template<int lt>
    double eff_mass_2pt_prototype(double ratio, int t)
    {
      if(ratio < 0)
        return error_num;
      if(ratio < 1 && t < lt/2.0-0.5)
        return error_num;
      if(ratio > 1 && t > lt/2.0+0.5)
        return error_num;
      eff_mass_2pt<lt> func;
      std::array<double,1> para_init={0.4};
      std::array<double,1> para_fin;
      double chisqcheck=0.0;
      std::vector<std::tuple<double,double,int> > input;
      std::tuple<double,double,int> tmp;
      std::get<0>(tmp)=ratio;
      std::get<1>(tmp)=1.0;
      std::get<2>(tmp)=t;
      input.push_back(tmp);
      func.set_para(para_init);
      lvm_fit<eff_mass_2pt<lt>>(input,para_init,para_fin,chisqcheck,false);
      return para_fin[0];
    }


    template<int lt>
    void eff_mass_2pt_wrapper(std::vector<std::vector<std::tuple<double,double,int> > > input, std::vector<std::vector<std::pair<double,int> > > &output)
    {
      output.resize(input.size());
      for(int i=0; i<input.size(); i++)
      {
	output[i].resize(0);
	for(int t=0; t<input[i].size()-1; t++)
	{
	  assert( std::get<2>(input[i][t]) == std::get<2>(input[i][t+1]) - 1);
	  double ratio = std::get<0>(input[i][t]) / std::get<0>(input[i][t+1]);
	  double time = std::get<2>(input[i][t]);
	  std::pair<double,int> tmp;
	  tmp.first = eff_mass_2pt_prototype<lt>(ratio,time);
	  tmp.second = time;
	  output[i].push_back(tmp);
	}
      }
    }


    template<int lt>
    void eff_mass_2pt_wrapper(std::vector<std::vector<std::pair<double,int> > > input, std::vector<std::vector<std::pair<double,int> > > &output, std::vector<double> c={})
    {
      if(c.size() == 0)
      {
	c.resize(input.size());
	std::fill(c.begin(), c.end(), 0);
      }
      else
	assert(c.size() == input.size());
      output.resize(input.size());
      for(int i=0; i<input.size(); i++)
      {
	output[i].resize(0);
	for(int t=0; t<input[i].size()-1; t++)
	{
	  assert( input[i][t].second == input[i][t+1].second - 1);
	  double ratio = (input[i][t].first - c[i]) / (input[i][t+1].first - c[i]);
	  cout<<"i = "<<i<<" t = "<<t<<" input[i][t] = "<<input[i][t].first<<"   input[i][t+1] = "<<input[i][t+1].first<<"   c[i] = "<<c[i]<<'\n';
	  double time = input[i][t].second;
	  std::pair<double,int> tmp;
	  tmp.first = eff_mass_2pt_prototype<lt>(ratio,time);
	  tmp.second = time;
	  output[i].push_back(tmp);
	}
      }
    }

    void eff_mass_3pt_wrapper(std::vector<std::vector<std::pair<double,int> > > input, std::vector<std::vector<std::pair<double,int> > > &output)
    {
      output.resize(input.size());
      for(int i=0; i<input.size(); i++)
      {
	output[i].resize(0);
	for(int t=1; t<input[i].size()-1; t++)
	{
	  assert( input[i][t].second == input[i][t+1].second - 1 );
	  assert( input[i][t-1].second == input[i][t].second - 1 );
	  double tmp = input[i][t-1].first + input[i][t+1].first;
	  tmp /= input[i][t].first;
	  tmp /= 2.0;
	  if(tmp > 1.0)
	    tmp = acosh(tmp);
	  else
	    tmp = error_num;
	  std::pair<double,int> tmp_pair;
	  tmp_pair.first = tmp;
	  tmp_pair.second = input[i][t].second;
	  output[i].push_back(tmp_pair);
	}
      }
    }
    void eff_mass_3pt_wrapper(std::vector<std::vector<std::tuple<double,double,int> > > input, std::vector<std::vector<std::pair<double,int> > > &output)
    {
      output.resize(input.size());
      for(int i=0; i<input.size(); i++)
      {
	output[i].resize(0);
	for(int t=1; t<input[i].size()-1; t++)
	{
	  assert( std::get<2>(input[i][t]) == std::get<2>(input[i][t+1]) - 1);
	  assert( std::get<2>(input[i][t]) == std::get<2>(input[i][t-1]) + 1);
	  double tmp = std::get<0>(input[i][t-1]) + std::get<0>(input[i][t+1]);
	  tmp /= std::get<0>(input[i][t]);
	  tmp /= 2.0;
	  if(tmp > 1.0)
	    tmp = acosh(tmp);
	  else
	    tmp = error_num;
	  std::pair<double,int> tmp_pair;
	  tmp_pair.first = tmp;
	  tmp_pair.second = std::get<2>(input[i][t]);
	  output[i].push_back(tmp_pair);
	}
      }
    }

    void eff_mass_3pt_bad_wrapper(std::vector<std::vector<std::pair<double,int> > > input, std::vector<std::vector<std::pair<double,int> > > &output)
    {
      output.resize(input.size());
      for(int i=0; i<input.size(); i++)
      {
        output[i].resize(0);
	assert( input[i][1].second == input[i][0].second + 1 );
        for(int t=1; t<input[i].size()-1; t++)
        {
          assert( input[i][t].second == input[i][t+1].second - 1 );
          double ratio = (input[i][t].first - input[i][t-1].first) / (input[i][t+1].first - input[i][t].first);
          double time = input[i][t].second;
          std::pair<double,int> tmp;
          tmp.first = ( ratio > 0 ? log(ratio) : error_num );
          tmp.second = time;
          output[i].push_back(tmp);
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

    void eff_mass_result_prototype(std::vector<std::vector<std::pair<double,int> > > input, std::vector<std::tuple<double,double,int> > &output)
    {
      output.resize(0);
      for(int t=0; t<input[0].size(); t++)
      {
	std::tuple<double,double,int> tmp;
        std::vector<double> vtmp;
	vec_generate(vtmp,input,t);
	std::get<0>(tmp) = vec_avg(vtmp);
	std::get<1>(tmp) = jack_vec_err(vtmp);
	std::get<2>(tmp) = input[0][t].second;
	output.push_back(tmp);
      }
    }

    void eff_mass_final_output_prototype(std::string name, std::vector<std::tuple<double,double,int> > output)
    {
      cout<<"We are output eff_mass final results for "<<name<<'\n';
      for(int t=0; t<output.size(); t++)
      {
	if(std::get<0>(output[t])<100)
	  cout<<"tsep = "<<std::get<2>(output[t])<<" eff_mass_avg = "<<std::get<0>(output[t])<<"\tjackknife_err = "<<std::get<1>(output[t])<<'\n';
      }
      cout<<'\n';
    }

    void eff_mass_step_output_prototype(std::string name, std::vector<std::vector<std::pair<double,int> > > output)
    {
      for(int i=0; i<output.size(); i++)
      {
	cout<<"We are output eff_mass step results for "<<name<<" with ensemble num = "<<i<<'\n';
	for(int t=0; t<output[i].size(); t++)
	{
	  cout<<"tsep = "<<output[i][t].second<<" eff_mass = "<<output[i][t].first<<'\n';
	}
      }
      cout<<'\n';
    }

    void output_data(std::string name, std::vector<std::array<double,3> > output, bool simple=false)
    {
      if(simple)
	cout<<"we are output para for single ensemble with "<<name<<'\n';
      for(int traj=0; traj<output.size(); traj++)
      {
	if(simple)
	{
	  cout<<traj<<'\t'<<output[traj][0]<<'\t'<<output[traj][1]<<'\t'<<output[traj][2]<<'\n';
	}
	else
	{
	  cout<<"we are output para for single ensemble with "<<name<<" and ensemble index = "<<traj<<'\n';
	  cout<<"para[0](Z) = "<<output[traj][0]<<'\n';
	  cout<<"para[1](m) = "<<output[traj][1]<<'\n';
	  cout<<"para[2](const) = "<<output[traj][2]<<"\n\n";
	}
      }
    }

    void output_data(std::string name, std::array<std::pair<double,double>,2> output)
    {
      cout<<"we are output final result para for "<<name<<'\n';
      cout<<"para[0](Z)_avg = "<<output[0].first<<"    para[0](Z)_err = "<<output[0].second<<'\n';
      cout<<"para[1](m)_avg = "<<output[1].first<<"    para[1](m)_err = "<<output[1].second<<'\n';
    }

    void output_data(std::string name, std::array<std::pair<double,double>,3> output)
    {
      cout<<"we are output final result para for "<<name<<'\n';
      cout<<"para[0](Z)_avg = "<<output[0].first<<"    para[0](Z)_err = "<<output[0].second<<'\n';
      cout<<"para[1](m)_avg = "<<output[1].first<<"    para[1](m)_err = "<<output[1].second<<'\n';
      cout<<"para[2](const)_avg = "<<output[2].first<<"    para[2](const)_err = "<<output[2].second<<"\n\n";
    }

    void output_data(std::string name, std::array<std::pair<double,double>,4> output)
    {
      cout<<"we are output final result para for "<<name<<'\n';
      cout<<"para[0](Z1)_avg = "<<output[0].first<<"    para[0](Z1)_err = "<<output[0].second<<'\n';
      cout<<"para[1](m)_avg = "<<output[1].first<<"    para[1](m)_err = "<<output[1].second<<'\n';
      cout<<"para[2](Z2)_avg = "<<output[2].first<<"    para[2](Z2)_err = "<<output[2].second<<'\n';
      cout<<"para[3](const)_avg = "<<output[3].first<<"    para[3](const)_err = "<<output[3].second<<"\n\n";
    }

    void output_data(std::string name, std::array<std::pair<double,double>,5> output)
    {
      cout<<"we are output final result para for "<<name<<'\n';
      cout<<"para[0](Z1)_avg = "<<output[0].first<<"    para[0](Z1)_err = "<<output[0].second<<'\n';
      cout<<"para[1](m1)_avg = "<<output[1].first<<"    para[1](m1)_err = "<<output[1].second<<'\n';
      cout<<"para[2](Z2)_avg = "<<output[2].first<<"    para[2](Z2)_err = "<<output[2].second<<'\n';
      cout<<"para[3](m2)_avg = "<<output[3].first<<"    para[3](m2)_err = "<<output[3].second<<'\n';
      cout<<"para[4](const)_avg = "<<output[4].first<<"    para[4](const)_err = "<<output[4].second<<"\n\n";
    }
    template<int lt>
    void three_para_fit_prototype(std::string name, std::vector<std::vector<std::tuple<double,double,int> > > fit_input, std::vector<std::array<double,3> > &para_output, int sp=0, int ep=0)
    {
      for(int traj=0; traj<fit_input.size(); traj++)
      {
	double chisqfinal=0.0;
	fit_input[traj].erase(fit_input[traj].begin(),fit_input[traj].begin()+1+sp);
	fit_input[traj].erase(fit_input[traj].end()-ep,fit_input[traj].end());
	cout<<"Now the DOF(number of y/x pair) is "<<fit_input[traj].size()<<'\n';
	cout<<"DEBUG MODE "<<name<<"traj = "<<traj<<"\n";
	for(int n=0; n<fit_input[traj].size(); n++)
	{
	  cout<<"n=   "<<n<<"  avg= "<<std::get<0>(fit_input[traj][n])<<"      ";
	  cout<<"err= "<<std::get<1>(fit_input[traj][n])<<"      ";
	  cout<<"time= "<<std::get<2>(fit_input[traj][n])<<"\n";
	}
	std::array<double,3> init_para;
	std::array<double,3> fin_para;
	init_para[0]=std::get<0>(fit_input[traj][0])-std::get<0>(fit_input[traj][fit_input[traj].size()/2]);
	init_para[1]=0.5;
	init_para[2]=std::get<0>(fit_input[traj][fit_input[traj].size()/2]);
	cout<<"doing three para fit for "<<name<<" traj= "<<traj<<'\n';
	lvm_fit<single_cosh_const<lt>>(fit_input[traj],init_para,fin_para,chisqfinal);
	para_output.push_back(fin_para);
      }
    }

    template<int lt>
    void two_para_fit_prototype(std::string name, std::vector<std::vector<std::tuple<double,double,int> > > fit_input, std::vector<std::array<double,2> > &para_output, int sp=0, int ep=0)
    {
      for(int traj=0; traj<fit_input.size(); traj++)
      {
        double chisqfinal=0.0;
        fit_input[traj].erase(fit_input[traj].begin(),fit_input[traj].begin()+1+sp);
        fit_input[traj].erase(fit_input[traj].end()-ep,fit_input[traj].end());
        cout<<"Now the DOF(number of y/x pair) is "<<fit_input[traj].size()<<'\n';
        std::array<double,2> init_para;
        std::array<double,2> fin_para;
        init_para[0]=std::get<0>(fit_input[traj][0]);
        init_para[1]=0.3;
        cout<<"doing two para fit for "<<name<<" traj= "<<traj<<'\n';
        lvm_fit<single_cosh<lt>>(fit_input[traj],init_para,fin_para,chisqfinal);
        para_output.push_back(fin_para);
      }
    }

    template<int N_para>
    void para_result(std::vector<std::array<double,N_para> > input, std::array<std::pair<double,double>,N_para> &output)
    {
      for(int n=0; n<N_para; n++)
      {
        std::vector<double> tmp;
        tmp.resize(0);
        for(int i=0; i<input.size(); i++)
	  tmp.push_back(input[i][n]);
	output[n].first=vec_avg(tmp);
	output[n].second=jack_vec_err(tmp);
      }
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

    template<int lt>
    void three_para_cor_fit_prototype(std::string name, std::vector<std::vector<std::pair<double,int> > > input, std::vector<MatrixXd> cov_mat, std::vector<std::array<double,3> > &output, int sp=0, int ep=0)
    {
      int n_traj = input.size();
      output.resize(n_traj);
      for(int traj=0; traj<n_traj; traj++)
      {
	double chisqfin = 0.0;
	assert(cov_mat[traj].rows() == cov_mat[traj].cols());
	assert(cov_mat[traj].rows() == input[traj].size());
	input[traj].erase(input[traj].begin(), input[traj].begin()+1+sp);
	input[traj].erase(input[traj].end()-ep, input[traj].end());
	MatrixXd mat_tmp = cov_mat[traj].block(sp+1,sp+1,input[traj].size(),input[traj].size());
	MatrixXd mat_inv = mat_tmp.inverse();
	cout<<"Now the number of y/x pair is "<<input[traj].size()<<'\n';
	std::array<double,3> init_para;
	init_para[0] = input[traj][0].first - input[traj][input[traj].size()/2].first;
	init_para[1] = 0.50;
	init_para[2] = input[traj][input[traj].size()/2].first;
	cout<<"doing three para fit for "<<name<<" traj= "<<traj<<'\n';
	lvm_fit<single_cosh_const<lt> >(input[traj],mat_inv,init_para,output[traj],chisqfin,true);
      }
    }

    template<int lt>
    void DoubleCoshPlusConst_cor_fit_prototype(std::string name, std::vector<std::vector<std::pair<double,int> > > input, const std::vector<MatrixXd> &cov_mat, std::vector<std::array<double,5> > &output, int sp=0, int ep=0)
    {
      int n_traj = input.size();
      output.resize(n_traj);
      for(int traj=0; traj<n_traj; traj++)
      {
        double chisqfin = 0.0;
        assert(cov_mat[traj].rows() == cov_mat[traj].cols());
        assert(cov_mat[traj].rows() == input[traj].size());
        input[traj].erase(input[traj].begin(), input[traj].begin()+1+sp);
        input[traj].erase(input[traj].end()-ep, input[traj].end());
        MatrixXd mat_tmp = cov_mat[traj].block(sp+1,sp+1,input[traj].size(),input[traj].size());
        MatrixXd mat_inv = mat_tmp.inverse();
        cout<<"Now the number of y/x pair is "<<input[traj].size()<<'\n';
        std::array<double,5> init_para;
        init_para[0] = input[traj][0].first - input[traj][input[traj].size()/2].first;
        init_para[1] = 0.35;
        init_para[2] = input[traj][0].first - input[traj][input[traj].size()/2].first;
        init_para[3] = 0.60;
        init_para[4] = input[traj][input[traj].size()/2].first;
        cout<<"doing DoubleCoshPlusConst fit for "<<name<<" traj= "<<traj<<'\n';
        lvm_fit<double_cosh_const<lt> >(input[traj],mat_inv,init_para,output[traj],chisqfin,true);
      }
    }

    template<int lt>
    void two_para_cor_fit_prototype(std::string name, std::vector<std::vector<std::pair<double,int> > > input, std::vector<MatrixXd> cov_mat, std::vector<std::array<double,2> > &output, int sp=0, int ep=0)
    {
      int n_traj = input.size();
      output.resize(n_traj);
      for(int traj=0; traj<n_traj; traj++)
      {
        double chisqfin = 0.0;
        assert(cov_mat[traj].rows() == cov_mat[traj].cols());
        assert(cov_mat[traj].rows() == input[traj].size());
        input[traj].erase(input[traj].begin(), input[traj].begin()+1+sp);
        input[traj].erase(input[traj].end()-ep, input[traj].end());
        MatrixXd mat_tmp = cov_mat[traj].block(sp+1,sp+1,input[traj].size(),input[traj].size());
        MatrixXd mat_inv = mat_tmp.inverse();
        cout<<"Now the number of y/x pair is "<<input[traj].size()<<'\n';
        std::array<double,2> init_para;
        init_para[0] = 6.0;
        init_para[1] = 0.35;
        cout<<"doing two para fit for "<<name<<" traj= "<<traj<<'\n';
        lvm_fit<single_cosh<lt> >(input[traj],mat_inv,init_para,output[traj],chisqfin,true);
      }
    }

    template<int lt>
    void four_para_cor_fit_prototype(std::string name, std::vector<std::vector<std::pair<double,int> > > input, std::vector<MatrixXd> cov_mat, std::vector<std::array<double,4> > &output, int sp=0, int ep=0)
    {
      int n_traj = input.size();
      output.resize(n_traj);
      for(int traj=0; traj<n_traj; traj++)
      {
        double chisqfin = 0.0;
        assert(cov_mat[traj].rows() == cov_mat[traj].cols());
        assert(cov_mat[traj].rows() == input[traj].size());
        input[traj].erase(input[traj].begin(), input[traj].begin()+1+sp);
        input[traj].erase(input[traj].end()-ep, input[traj].end());
        MatrixXd mat_tmp = cov_mat[traj].block(sp+1,sp+1,input[traj].size(),input[traj].size());
        MatrixXd mat_inv = mat_tmp.inverse();
        cout<<"Now the number of y/x pair is "<<input[traj].size()<<'\n';
        std::array<double,4> init_para;
        init_para[0] = input[traj][0].first - input[traj][input[traj].size()/2].first;
        init_para[1] = 0.3;
	init_para[2] = input[traj][0].first - input[traj][input[traj].size()/2].first;
        init_para[3] = input[traj][input[traj].size()/2].first;
        cout<<"doing four para fit for "<<name<<" traj= "<<traj<<'\n';
        lvm_fit<asym_single_cosh_const<lt> >(input[traj],mat_inv,init_para,output[traj],chisqfin,true);
      }
    }

    template<int lt>
    void double_exp_cor_fit_prototype(std::string name, std::vector<std::vector<std::pair<double,int> > > input, std::vector<MatrixXd> cov_mat, std::vector<std::array<double,5> > &output, int sp=0, int ep=0)
    {
      int n_traj = input.size();
      output.resize(n_traj);
      for(int traj=0; traj<n_traj; traj++)
      {
        double chisqfin = 0.0;
        assert(cov_mat[traj].rows() == cov_mat[traj].cols());
        assert(cov_mat[traj].rows() == input[traj].size());
        input[traj].erase(input[traj].begin(), input[traj].begin()+1+sp);
        input[traj].erase(input[traj].end()-ep, input[traj].end());
        MatrixXd mat_tmp = cov_mat[traj].block(sp+1,sp+1,input[traj].size(),input[traj].size());
        MatrixXd mat_inv = mat_tmp.inverse();
        cout<<"Now the number of y/x pair is "<<input[traj].size()<<'\n';
        std::array<double,5> init_para;
        init_para[0] = (input[traj][0].first - input[traj][input[traj].size()/2].first) * exp(0.35 * sp) / 2.0;
        init_para[1] = 0.30;
        init_para[2] = (input[traj][0].first - input[traj][input[traj].size()/2].first) * exp(0.35 * sp) / 2.0;
        init_para[3] = 0.50;
        init_para[4] = input[traj][input[traj].size()/2].first;
        cout<<"doing double exp fit for "<<name<<" traj= "<<traj<<'\n';
        lvm_fit<double_cosh_const<lt> >(input[traj],mat_inv,init_para,output[traj],chisqfin,true);
      }
    }

    template<int lt>
    void double_exp_fix_one_mass_cor_fit_prototype(std::string name, std::vector<std::vector<std::pair<double,int> > > input, std::vector<MatrixXd> cov_mat, std::vector<std::array<double,4> > &output, int sp=0, int ep=0)
    {
      int n_traj = input.size();
      output.resize(n_traj);
      for(int traj=0; traj<n_traj; traj++)
      {
        double chisqfin = 0.0;
        assert(cov_mat[traj].rows() == cov_mat[traj].cols());
        assert(cov_mat[traj].rows() == input[traj].size());
        input[traj].erase(input[traj].begin(), input[traj].begin()+1+sp);
        input[traj].erase(input[traj].end()-ep, input[traj].end());
        MatrixXd mat_tmp = cov_mat[traj].block(sp+1,sp+1,input[traj].size(),input[traj].size());
        MatrixXd mat_inv = mat_tmp.inverse();
        cout<<"Now the number of y/x pair is "<<input[traj].size()<<'\n';
        std::array<double,4> init_para;
        init_para[0] = (input[traj][0].first - input[traj][input[traj].size()/2].first) * exp(0.35 * sp) / 2.0;
        init_para[1] = 0.30;
        init_para[2] = (input[traj][0].first - input[traj][input[traj].size()/2].first) * exp(0.35 * sp) / 2.0;
        init_para[3] = input[traj][input[traj].size()/2].first;
        cout<<"doing double exp fit for "<<name<<" traj= "<<traj<<'\n';
        lvm_fit<double_cosh_one_fixed_mass_const<lt> >(input[traj],mat_inv,init_para,output[traj],chisqfin,true);
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

    static double calc_phase(std::array<int,3> mom, double q, double gamma=1.0)
    {
      LuscherZeta zeta;
      zeta.setTwists(1,1,1);
      zeta.setCMmom(mom[0],mom[1],mom[2]);
      return zeta.calcPhi(q,gamma);
    }

    static double calc_pipi_phase_general(std::array<int,3> mom, double epipi)
    {
      double ptot_unitless = sqrt(mom[0]*mom[0]+mom[1]*mom[1]+mom[2]*mom[2]);
      double ptot = ptot_unitless * 2.0*3.1415926/32.0;
      double ptot2 = ptot * ptot;
      double gamma = epipi/sqrt(epipi*epipi-ptot2);
      double epipi_cm = epipi / gamma;
      double q = sqrt(epipi_cm*epipi_cm/4.0-0.01077773625) * 16.0 / 3.1415926;
      return calc_phase(mom,q,gamma);      
    }

    static double calc_stationary_pipi_phase(double epipi)
    {
      std::array<int,3> mom = {0,0,0};
      double q = sqrt((epipi/2.0)*(epipi/2.0)-0.01077773625) * 16.0 / 3.1415926;
      return calc_phase(mom,q);
    }

};























#endif

