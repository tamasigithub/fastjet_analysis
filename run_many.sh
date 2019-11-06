#!/bin/sh
#sed -i -e 's/Genjet_ggF_Ctr-2.0_q1.2GeV_2.5.root/Genjet_ggF_Ctr1.0_q1.2GeV_2.5_1.root/g' ./Gen_Jet.cc
#sed -i -e 's/user.tkar.pp_ggF_Ctr-2.0hh_pythia82_GenCuts.v3_output.root/user.tkar.pp_ggF_Ctr1.0hh_pythia82_NoGenCuts.v2_output.root/g' ./Gen_Jet.cc
#echo " Running fastjet for lambda = 1.0"
#./compileGen_run_1.sh
#./genjet

#sed -i -e 's/Genjet_ggF_Ctr1.0_q1.2GeV_2.5_1.root/Genjet_ggF_Ctr2.0_q1.2GeV_2.5_1.root/g' ./Gen_Jet.cc
#sed -i -e 's/user.tkar.pp_ggF_Ctr1.0hh_pythia82_NoGenCuts.v2_output.root/user.tkar.pp_ggF_Ctr2.0hh_pythia82_GenCuts.v2_output.root/g' ./Gen_Jet.cc
#echo " Running fastjet for lambda = 2.0"
#./compileGen_run_1.sh
#./genjet
#
#sed -i -e 's/Genjet_ggF_Ctr2.0_q1.2GeV_2.5_1.root/Genjet_ggF_Ctr2.5_q1.2GeV_2.5_1.root/g' ./Gen_Jet.cc
#sed -i -e 's/user.tkar.pp_ggF_Ctr2.0hh_pythia82_GenCuts.v2_output.root/user.tkar.pp_ggF_Ctr2.5hh_pythia82_GenCuts.v2_output.root/g' ./Gen_Jet.cc
#echo " Running fastjet for lambda = 2.5"
#./compileGen_run_1.sh
#./genjet
#
#sed -i -e 's/Genjet_ggF_Ctr2.5_q1.2GeV_2.5_1.root/Genjet_ggF_Ctr3.0_q1.2GeV_2.5_1.root/g' ./Gen_Jet.cc
#sed -i -e 's/user.tkar.pp_ggF_Ctr2.5hh_pythia82_GenCuts.v2_output.root/user.tkar.pp_ggF_Ctr3.0hh_pythia82_GenCuts.v3_output.root/g' ./Gen_Jet.cc
#echo " Running fastjet for lambda = 3.0"
#./compileGen_run_1.sh
#./genjet

sed -i -e 's/Genjet_ggF_Ctr1.0_q1.2GeV_2.5_1.root/Genjet_ggF_Ctr0.0_q1.2GeV_2.5_1.root/g' ./Gen_Jet.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr1.0hh_pythia82_NoGenCuts.v2_output.root/user.tkar.pp_ggF_Ctr0.0hh_pythia82_GenCuts.v3_output.root/g' ./Gen_Jet.cc
echo " Running fastjet for lambda = 0.0"
./compileGen_run_1.sh
./genjet

sed -i -e 's/Genjet_ggF_Ctr0.0_q1.2GeV_2.5_1.root/Genjet_ggF_Ctr-1.0_q1.2GeV_2.5_1.root/g' ./Gen_Jet.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr0.0hh_pythia82_GenCuts.v3_output.root/user.tkar.pp_ggF_Ctr-1.0hh_pythia82_GenCuts.v3_output.root/g' ./Gen_Jet.cc
echo " Running fastjet for lambda = -1.0"
./compileGen_run_1.sh
./genjet

sed -i -e 's/Genjet_ggF_Ctr-1.0_q1.2GeV_2.5_1.root/Genjet_ggF_Ctr-2.0_q1.2GeV_2.5_1.root/g' ./Gen_Jet.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr-1.0hh_pythia82_GenCuts.v3_output.root/user.tkar.pp_ggF_Ctr-2.0hh_pythia82_GenCuts.v3_output.root/g' ./Gen_Jet.cc
echo " Running fastjet for lambda = -2.0"
./compileGen_run_1.sh
./genjet
