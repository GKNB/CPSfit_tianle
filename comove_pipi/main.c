#include"fit_adv.h"

int main()
{
  int  traj_min 		= 1800;
  int  traj_max 		= 2400;
  int  t_min			= 6;
  int  t_max			= 25;
  bool input_is_1s 		= true;		  //if false, do 2s
  bool do_correlated_fit	= true;		  //if false, do uncorrelated fit
  bool output_step_result       = false;

  bool fit_single_pion		= false;
  bool fit_single_sigma		= false;
  bool fit_pipi_to_sigma	= false;
  bool fit_stationary_pipi	= true;
  bool fit_comove_pipi		= false;

  bool fit_eff_mass_with_sub	= true;

  fit_adv fitting;

  fitting.do_what( fit_single_pion , fit_single_sigma , fit_single_sigma , fit_single_sigma , fit_pipi_to_sigma , fit_pipi_to_sigma , fit_pipi_to_sigma , fit_stationary_pipi , fit_comove_pipi);
  fitting.read_origin_data(traj_min, traj_max, input_is_1s);				
//  fitting.test_origin();
//  fitting.output_origin_data();							//output_origin_data
  fitting.tavg_generate();								//tavg_origin_data
//  fitting.Output_tavgAvgErr();							//This generates average and error of tavg_data 
//  fitting.tavg_test();
////  fitting.comove_pion_avg_err_calculate();
//  fitting.vacuum_sortout();								//sort_out_pipi_vacuum_diagram_from_pipi_correlator_data
//////  fitting.output_tavg_data();							//output_tavg_data
//////  fitting.output_sortout_data();							//output_sort_out_data
  fitting.rep_proj();									//proj_onto_several_representation
  fitting.output_rep_proj_data();							//output_rep_data
  fitting.double_jk_generate();								//generate_double_jk_ensemble
  fitting.double_jk_fold();								//folding_on_double_jk_ensemble
  fitting.double_jk_fit_input_generate(do_correlated_fit);

//  fitting.double_jk_input_result();							
//  fitting.output_double_jk_input_result();
//  fitting.output_double_jk_fit_input();
//  fitting.fit_data_generate();							//not sure if this can be commented out
  fitting.cor_fit_data_generate();
////  fitting.output_fit_input();
  fitting.mass_2pt_generate();
  fitting.mass_3pt_generate();
////  fitting.mass_step_output();
  fitting.mass_eff_final();
  fitting.mass_eff_final_output();
  fitting.fit_one_complete_step(t_min, t_max, fit_eff_mass_with_sub, output_step_result);
//  fitting.fit_single_ensemble_nosub();
//  fitting.cov_test_sub_nosub();
//  fitting.rep_proj_average();
//  fitting.output_rep_proj_average();
}
