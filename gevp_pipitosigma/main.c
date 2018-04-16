#include"fit_adv.h"

int main()
{
  int  traj_min 		= 0;
  int  traj_max 		= 3000;
  int  t_min			= 6;
  int  t_max			= 25;
  bool do_vac_sub		= true;	 	  //if false, no vac sub
  bool output_step_result       = false;
  bool gevp_sub                 = true;           //if true, first do correlation matrix subtraction and then do gevp with sub_data

  fit_adv fitting;

  fitting.read_origin_data(traj_min, traj_max);				
//  fitting.test_origin();
//  fitting.output_origin_data();							//output_origin_data
  fitting.tavg_generate();								//tavg_origin_data
//  fitting.Output_tavgAvgErr();							//This generates average and error of tavg_data 
//  fitting.tavg_test();
////  fitting.comove_pion_avg_err_calculate();
//////  fitting.output_tavg_data();							//output_tavg_data
//////  fitting.output_sortout_data();							//output_sort_out_data
  fitting.rep_proj();									//proj_onto_several_representation
//  fitting.output_rep_proj_data();							//output_rep_data
  fitting.double_jk_generate();								//generate_double_jk_ensemble
  fitting.double_jk_vac_sub(do_vac_sub);		
  fitting.double_jk_fold();								//folding_on_double_jk_ensemble
  fitting.double_jk_fit_input_generate(false);

  fitting.gevp_start(gevp_sub);

//  fitting.double_jk_input_result();							
//  fitting.output_double_jk_input_result();
//  fitting.output_double_jk_fit_input();
}
