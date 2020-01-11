#!/bin/sh
sed -i -e 's/Genjet2_ggF_Ctr-2.0_q300MeV_2.5_allR0.4_0.75btag.root/Genjet2_ggF14TeV_Ctr1.0_q300MeV_2.5_allR0.4_0.75btag.root/g' ./Gen_Jet_2.cc
sed -i -e 's/user.tkar.pp_ggF_Ctr-2.0hh_pythia82_nopileup.v5_output.root/user.tkar.pp14TeV_ggF_Ctr1.0hh_pythia82_GenCuts.v1_output.root/g' ./Gen_Jet_2.cc
echo " Running fastjet for lambda = 1.0"
./compileGen_run_2.sh
./genjet_2

sed -i -e 's/Genjet2_ggF14TeV_Ctr1.0_q300MeV_2.5_allR0.4_0.75btag.root/Genjet2_ggF14TeV_Ctr2.0_q300MeV_2.5_allR0.4_0.75btag.root/g' ./Gen_Jet_2.cc
sed -i -e 's/user.tkar.pp14TeV_ggF_Ctr1.0hh_pythia82_GenCuts.v1_output.root/user.tkar.pp14TeV_ggF_Ctr2.0hh_pythia82_GenCuts.v1_output.root/g' ./Gen_Jet_2.cc
echo " Running fastjet for lambda = 2.0"
./compileGen_run_2.sh
./genjet_2

sed -i -e 's/Genjet2_ggF14TeV_Ctr2.0_q300MeV_2.5_allR0.4_0.75btag.root/Genjet2_ggF14TeV_Ctr2.5_q300MeV_2.5_allR0.4_0.75btag.root/g' ./Gen_Jet_2.cc
sed -i -e 's/user.tkar.pp14TeV_ggF_Ctr2.0hh_pythia82_GenCuts.v1_output.root/user.tkar.pp14TeV_ggF_Ctr2.5hh_pythia82_GenCuts.v1_output.root/g' ./Gen_Jet_2.cc
echo " Running fastjet for lambda = 2.5"
./compileGen_run_2.sh
./genjet_2

sed -i -e 's/Genjet2_ggF14TeV_Ctr2.5_q300MeV_2.5_allR0.4_0.75btag.root/Genjet2_ggF14TeV_Ctr3.0_q300MeV_2.5_allR0.4_0.75btag.root/g' ./Gen_Jet_2.cc
sed -i -e 's/user.tkar.pp14TeV_ggF_Ctr2.5hh_pythia82_GenCuts.v1_output.root/user.tkar.pp14TeV_ggF_Ctr3.0hh_pythia82_GenCuts.v1_output.root/g' ./Gen_Jet_2.cc
echo " Running fastjet for lambda = 3.0"
./compileGen_run_2.sh
./genjet_2

#sed -i -e 's/Genjet2_ggF14TeV_Ctr3.0_q300MeV_2.5_allR0.4_0.75btag.root/Genjet2_ggF14TeV_Ctr5.0_q300MeV_2.5_allR0.4_0.75btag.root/g' ./Gen_Jet_2.cc
#sed -i -e 's/user.tkar.pp14TeV_ggF_Ctr3.0hh_pythia82_GenCuts.v1_output.root/user.tkar.pp14TeV_ggF_Ctr5.0hh_pythia82_GenCuts.v1_output.root/g' ./Gen_Jet_2.cc
#echo " Running fastjet for lambda = 5.0"
#./compileGen_run_2.sh
#./genjet_2

sed -i -e 's/Genjet2_ggF14TeV_Ctr3.0_q300MeV_2.5_allR0.4_0.75btag.root/Genjet2_ggF14TeV_Ctr0.0_q300MeV_2.5_allR0.4_0.75btag.root/g' ./Gen_Jet_2.cc
sed -i -e 's/user.tkar.pp14TeV_ggF_Ctr3.0hh_pythia82_GenCuts.v1_output.root/user.tkar.pp14TeV_ggF_Ctr0.0hh_pythia82_GenCuts.v1_output.root/g' ./Gen_Jet_2.cc
echo " Running fastjet for lambda = 0.0"
./compileGen_run_2.sh
./genjet_2

sed -i -e 's/Genjet2_ggF14TeV_Ctr0.0_q300MeV_2.5_allR0.4_0.75btag.root/Genjet2_ggF14TeV_Ctr-1.0_q300MeV_2.5_allR0.4_0.75btag.root/g' ./Gen_Jet_2.cc
sed -i -e 's/user.tkar.pp14TeV_ggF_Ctr0.0hh_pythia82_GenCuts.v1_output.root/user.tkar.pp14TeV_ggF_Ctr-1.0hh_pythia82_GenCuts.v1_output.root/g' ./Gen_Jet_2.cc
echo " Running fastjet for lambda = -1.0"
./compileGen_run_2.sh
./genjet_2

sed -i -e 's/Genjet2_ggF14TeV_Ctr-1.0_q300MeV_2.5_allR0.4_0.75btag.root/Genjet2_ggF14TeV_Ctr-2.0_q300MeV_2.5_allR0.4_0.75btag.root/g' ./Gen_Jet_2.cc
sed -i -e 's/user.tkar.pp14TeV_ggF_Ctr-1.0hh_pythia82_GenCuts.v1_output.root/user.tkar.pp14TeV_ggF_Ctr-2.0hh_pythia82_GenCuts.v1_output.root/g' ./Gen_Jet_2.cc
echo " Running fastjet for lambda = -2.0"
./compileGen_run_2.sh
./genjet_2


sed -i -e 's/Genjet2_ggF14TeV_Ctr-2.0_q300MeV_2.5_allR0.4_0.75btag.root/Genjet2_ggF_Ctr-2.0_q300MeV_2.5_allR0.4_0.75btag.root/g' ./Gen_Jet_2.cc
sed -i -e 's/user.tkar.pp14TeV_ggF_Ctr-2.0hh_pythia82_GenCuts.v1_output.root/user.tkar.pp_ggF_Ctr-2.0hh_pythia82_nopileup.v5_output.root/g' ./Gen_Jet_2.cc

vlc ~/Videos/damodarashtaka.mp4
