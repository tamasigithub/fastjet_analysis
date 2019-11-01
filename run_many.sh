#!/bin/sh
sed -i -e 's/Genjet_ggF_Ctr-2.0_q1.2GeV_2.5.root/Genjet_ggF_Ctr1.0_q1.2GeV_2.5_4.root/g' ./Gen_Jet_1.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr-2.0hh_pythia82_GenCuts.v3_output.root/user.tkar.pp_ggF_Ctr1.0hh_pythia82_NoGenCuts.v2_output.root/g' ./Gen_Jet_1.cc
echo " Running fastjet for lambda = 1.0"
./compileGen_run_2.sh
./genjet_1

sed -i -e 's/Genjet_ggF_Ctr1.0_q1.2GeV_2.5_4.root/Genjet_ggF_Ctr2.0_q1.2GeV_2.5_4.root/g' ./Gen_Jet_1.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr1.0hh_pythia82_NoGenCuts.v2_output.root/user.tkar.pp_ggF_Ctr2.0hh_pythia82_GenCuts.v2_output.root/g' ./Gen_Jet_1.cc
echo " Running fastjet for lambda = 2.0"
./compileGen_run_2.sh
./genjet_1

sed -i -e 's/Genjet_ggF_Ctr2.0_q1.2GeV_2.5_4.root/Genjet_ggF_Ctr2.5_q1.2GeV_2.5_4.root/g' ./Gen_Jet_1.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr2.0hh_pythia82_GenCuts.v2_output.root/user.tkar.pp_ggF_Ctr2.5hh_pythia82_GenCuts.v2_output.root/g' ./Gen_Jet_1.cc
echo " Running fastjet for lambda = 2.5"
./compileGen_run_2.sh
./genjet_1

sed -i -e 's/Genjet_ggF_Ctr2.5_q1.2GeV_2.5_4.root/Genjet_ggF_Ctr3.0_q1.2GeV_2.5_4.root/g' ./Gen_Jet_1.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr2.5hh_pythia82_GenCuts.v2_output.root/user.tkar.pp_ggF_Ctr3.0hh_pythia82_GenCuts.v3_output.root/g' ./Gen_Jet_1.cc
echo " Running fastjet for lambda = 3.0"
./compileGen_run_2.sh
./genjet_1

sed -i -e 's/Genjet_ggF_Ctr3.0_q1.2GeV_2.5_4.root/Genjet_ggF_Ctr5.0_q1.2GeV_2.5_4.root/g' ./Gen_Jet_1.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr3.0hh_pythia82_GenCuts.v3_output.root/user.tkar.pp_ggF_Ctr5.0hh_pythia82_GenCuts.v1_output.root/g' ./Gen_Jet_1.cc
echo " Running fastjet for lambda = 5.0"
./compileGen_run_2.sh
./genjet_1

sed -i -e 's/Genjet_ggF_Ctr5.0_q1.2GeV_2.5_4.root/Genjet_ggF_Ctr0.0_q1.2GeV_2.5_4.root/g' ./Gen_Jet_1.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr5.0hh_pythia82_GenCuts.v1_output.root/user.tkar.pp_ggF_Ctr0.0hh_pythia82_GenCuts.v3_output.root/g' ./Gen_Jet_1.cc
echo " Running fastjet for lambda = 0.0"
./compileGen_run_2.sh
./genjet_1

sed -i -e 's/Genjet_ggF_Ctr0.0_q1.2GeV_2.5_4.root/Genjet_ggF_Ctr-1.0_q1.2GeV_2.5_4.root/g' ./Gen_Jet_1.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr0.0hh_pythia82_GenCuts.v3_output.root/user.tkar.pp_ggF_Ctr-1.0hh_pythia82_GenCuts.v3_output.root/g' ./Gen_Jet_1.cc
echo " Running fastjet for lambda = -1.0"
./compileGen_run_2.sh
./genjet_1

sed -i -e 's/Genjet_ggF_Ctr-1.0_q1.2GeV_2.5_4.root/Genjet_ggF_Ctr-2.0_q1.2GeV_2.5_4.root/g' ./Gen_Jet_1.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr-1.0hh_pythia82_GenCuts.v3_output.root/user.tkar.pp_ggF_Ctr-2.0hh_pythia82_GenCuts.v3_output.root/g' ./Gen_Jet_1.cc
echo " Running fastjet for lambda = -2.0"
./compileGen_run_2.sh
./genjet_1
