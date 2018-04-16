#ifndef _FIT_ADV_H
#define _FIT_ADV_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<tuple>
#include<vector>
#include<map>

#include<Eigen/Dense>

#include "fit_candidate_func.h"
#include "lvm_fit.h"
#include "three_momentum_simple.h"
#include "luscherzeta_moving.h"

using namespace std;
using namespace Eigen;
class fit_adv
{
  private:

    static const int    Lt=64;
    const double error_num=999999;
    const int    traj_step=4;
    static const int ndir = 3;
//    const std::string pipi_work_dir[4] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_EOFA_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM_sep2" };
//    const std::string work_dir[4] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/KEK_EOFA_STREAM1", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/KEK_EOFA_STREAM2", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_EOFA_STREAM_sigma"};
//    const std::string pipi_work_dir[3] = {"/auto/home8/ckelly/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_meas/all_inc_old_1187sloppy_252exact/sloppy", " ", " "};
//    const std::string pipi_work_dir[3] = {" ", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM", " "};
    const std::string comove_work_dir[ndir] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DIRAC_STREAM", " ", " "};
//    const std::string comove_work_dir[1] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_EOFA_STREAM_No_fix_in_gamma5"};
//    const std::string comove_work_dir[3] = {"/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/DD2_EOFA_STREAM_Gamma5_topology_included", "/home/G-parity/32nt64_gparityXYZ_MDWF+IDSDR_2+1F_fixedRNG_FROM_BGQ/KEK_EOFA_STREAM1", " "};



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

    const std::array<int,3> type1_mom   = {{1,1,1}};
    const std::array<int,3> type2_mom   = {{1,1,0}};
    const std::array<int,3> type3_mom   = {{1,0,0}};

//this is the newly introduced mom_container which is almost the same as above, but they support most of operation Chris defined in threemomentum. Notice they are different!
//we can get pion_mom[i] by pionmom[i], and we can get underlying basemom by pionmom(i)
    pion_basemom_container pionmom;

//These two are coeff used for rep-proj
    MovingPiPiCase3_sdCoeff policysd;
    MovingPiPiCase3_ddCoeff policydd;

//this section collects the original data, and no information is lost here
//the name looks like "origin_xxxx"
  private:

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
  public:
    
    bool read_origin_data(int traj_min, int traj_max, bool ground = true)
    {
      //type1_comove_pipi, which means all 3 component of p_CM have absolute value 1, where there will be 8 different cases
      for(int i=0; i<3; i++)
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
            }
          }
          if(tmpV.size() == 64)
            origin_comove_pipiV.push_back(tmpV);
          else
            assert(tmpV.size() == 0);
        }
      }
      for(int i=0; i<3; i++)
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

    bool output_origin_data()
    {
      output_data<Lt*Lt/tstep>("origin_comove_pipi_type2", origin_comove_type2_pipiC);
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

  public:

    bool tavg_generate()
    {
      std::cout << "Start tavg_generate\n" << std::endl;
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


    bool tavg_test()
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

//this section generates different angular momentum of tavg or fixed tsep data (and other linear combination of momentum)
//the name looks like "xx_xx_xxxx" or "xx_xxxx" for vacuum term
//s1 stands for swave for cubic symmetry group
//s2 s3 stands for swave for D3d symmetry
//d1 stands for dwave for cubic symmetry
  private:
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiC_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_sd_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_dd_pipiC;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiD_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_sd_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_dd_pipiD;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiR_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_sd_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_dd_pipiR;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiV_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_sd_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_dd_pipiV;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_2_old;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,8>   comove_type1_pipiI_2_seperate_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_2_combine_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_2_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiI_2_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_2_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_2_sd_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_2_dd_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_0_old;
    std::array<std::vector<std::pair<std::array<double,Lt>,int> >,8>   comove_type1_pipiI_0_seperate_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_0_combine_old;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type1_pipiI_0_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type2_pipiI_0_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_0_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_0_sd_combine_test;
    std::vector<std::pair<std::array<double,Lt>,int> >   comove_type3_pipiI_0_dd_combine_test;

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
      std::cout << "Finish rep_proj\n" << std::endl;
    }

    bool output_rep_proj_data()
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

//here are the new, double jackknife method of treating data, and they should generate the same result as Chris's
  private:

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

  public:

    void double_jk_generate()
    {
      std::cout << "Start double_jk_generate\n" << std::endl;
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
      std::cout << "Finish double_jk_generate\n" << std::endl;
    }

    void double_jk_fold()
    {
      std::cout << "Start double_jk_fold\n" << std::endl;
      for(int i=0; i<8; i++)
      {
	double_jk_fold_prototype(double_jk_comove_type1_pipiI_2_seperate_old[i],double_jk_comove_type1_pipiI_2_seperate_fold_old[i],2*tdis);
	double_jk_fold_prototype(double_jk_comove_type1_pipiI_0_seperate_old[i],double_jk_comove_type1_pipiI_0_seperate_fold_old[i],2*tdis);
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
      std::cout << "Finish double_jk_fold\n" << std::endl;
    }
 
    void double_jk_fit_input_generate(bool corfit = true)
    {
      std::cout << "Start double_jk_fit_input_generate\n" << std::endl;
      for(int i=0; i<8; i++)
      {
	double_jk_fit_input_generate_prototype(double_jk_comove_type1_pipiI_2_seperate_fold_old[i], double_jk_comove_type1_pipiI_2_seperate_fold_fit_old[i], double_jk_comove_type1_pipiI_2_seperate_fold_cov_mat_old[i],corfit);
	double_jk_fit_input_generate_prototype(double_jk_comove_type1_pipiI_0_seperate_fold_old[i], double_jk_comove_type1_pipiI_0_seperate_fold_fit_old[i], double_jk_comove_type1_pipiI_0_seperate_fold_cov_mat_old[i],corfit);
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
      std::cout << "Finish double_jk_fit_input_generate\n" << std::endl;
    }

//this section calculates eff_mass, we provide two methods to do that :using three point method or two point 0-dof fitting
//the name looks like "sample_mass_2pt(3pt)_xxxx" for mass for each ensemble, and "mass_xxxx" for mass after jackknife
  private:
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

  public:

    bool mass_2pt_generate()
    {
      std::cout << "Start mass_2pt_generate\n" << std::endl;
      for(int pidx=0; pidx<8; pidx++)
      {
        eff_mass_3pt_wrapper(double_jk_comove_type1_pipiI_2_seperate_fold_fit_old[pidx],sample_mass_2pt_double_jk_comove_type1_pipiI_2_old[pidx]);
        eff_mass_3pt_wrapper(double_jk_comove_type1_pipiI_0_seperate_fold_fit_old[pidx],sample_mass_2pt_double_jk_comove_type1_pipiI_0_old[pidx]);
	eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_2_seperate_fold_fit_old[pidx],sample_mass_2pt_double_jk_comove_type1_pipiI_2_old[pidx]);
	eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_0_seperate_fold_fit_old[pidx],sample_mass_2pt_double_jk_comove_type1_pipiI_0_old[pidx]);
      }
      eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_2_combine_fold_fit_old,sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine_old);
      eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_0_combine_fold_fit_old,sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine_old);
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
      std::cout << "Finish mass_2pt_generate\n" << std::endl;
    }

    bool mass_2pt_generate_afterwards()
    {
      std::cout << "Start mass_2pt_generate_afterwards\n" << std::endl;
      std::vector<double> const_tmp;
      for(int i=0; i<8; i++)
      {
        get_vector_const_three_para_result(result_double_jk_comove_type1_pipiI_2_old[i], const_tmp);
        eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_2_seperate_fold_fit_old[i],sample_mass_2pt_double_jk_comove_type1_pipiI_2_old[i],const_tmp);
      }
      get_vector_const_three_para_result(result_double_jk_comove_type1_pipiI_2_combine_old, const_tmp);
      eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_2_combine_fold_fit_old,sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine_old,const_tmp);
      get_vector_const_three_para_result(result_double_jk_comove_type1_pipiI_0_combine_old, const_tmp);
      eff_mass_2pt_wrapper<Lt-2*tdis>(double_jk_comove_type1_pipiI_0_combine_fold_fit_old,sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine_old,const_tmp);
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
      std::cout << "Finish mass_2pt_generate_afterwards\n" << std::endl;
    }

    bool mass_eff_final()
    {
      std::cout << "Start mass_eff_final\n" << std::endl;
      for(int pidx=0; pidx<8; pidx++)
      {
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_2_old[pidx], mass_2pt_double_jk_comove_type1_pipiI_2_old[pidx]);
        eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_0_old[pidx], mass_2pt_double_jk_comove_type1_pipiI_0_old[pidx]);
      }
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine_old, mass_2pt_double_jk_comove_type1_pipiI_2_combine_old);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine_old, mass_2pt_double_jk_comove_type1_pipiI_0_combine_old);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_2_combine, mass_2pt_double_jk_comove_type1_pipiI_2_combine);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type1_pipiI_0_combine, mass_2pt_double_jk_comove_type1_pipiI_0_combine);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type2_pipiI_2_combine, mass_2pt_double_jk_comove_type2_pipiI_2_combine);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type2_pipiI_0_combine, mass_2pt_double_jk_comove_type2_pipiI_0_combine);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_2_combine, mass_2pt_double_jk_comove_type3_pipiI_2_combine);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_2_sd_combine, mass_2pt_double_jk_comove_type3_pipiI_2_sd_combine);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_2_dd_combine, mass_2pt_double_jk_comove_type3_pipiI_2_dd_combine);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_0_combine, mass_2pt_double_jk_comove_type3_pipiI_0_combine);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_0_sd_combine, mass_2pt_double_jk_comove_type3_pipiI_0_sd_combine);
      eff_mass_result_prototype(sample_mass_2pt_double_jk_comove_type3_pipiI_0_dd_combine, mass_2pt_double_jk_comove_type3_pipiI_0_dd_combine);
      std::cout << "Finish mass_eff_final\n" << std::endl;
    }

    bool mass_eff_final_output()
    {
      std::cout << "Start mass_eff_final_output\n" << std::endl;
      for(int pidx=0; pidx<8; pidx++)
      {
        cout << "comove_pipi pidx index = "<< pidx << '\n';
        eff_mass_final_output_prototype("comove type1 pipiI_2 2pt final mass double jk old", mass_2pt_double_jk_comove_type1_pipiI_2_old[pidx]);
        eff_mass_final_output_prototype("comove type1 pipiI_0 2pt final mass double jk old", mass_2pt_double_jk_comove_type1_pipiI_0_old[pidx]);
      }
      eff_mass_final_output_prototype("comove type1 pipiI_2 combined data 2pt final mass double jk old", mass_2pt_double_jk_comove_type1_pipiI_2_combine_old);
      eff_mass_final_output_prototype("comove type1 pipiI_0 combined data 2pt final mass double jk old", mass_2pt_double_jk_comove_type1_pipiI_0_combine_old);
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
      std::cout << "Finish mass_eff_final_output\n" << std::endl;
    }


//this section does 2/3 para local fitting for all above thing
  private:
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

  public:

    void fit_single_ensemble(int t_min, int t_max)
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

    void fit_sample_phase()
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


    void fit_result()
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

    void fit_final()
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

