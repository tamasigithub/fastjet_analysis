#!/bin/sh

#############  IN trackJetMod.cc CHANGE THE EVENT LIST FILE   ###################
############# user.tkar.EventList_2_5_allAnaCuts_000005.root  ###################
#
## ggF  Br 30mm EC 80mm eta 2.5 zbin 1.5mm
#sed -i -e 's/sample = .*/sample = "ggF1.0";/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 200;/g' ./trackJetMod.cc
#sed -i -e 's/bin_width = .*/bin_width = "1.5mm";/g' ./trackJetMod.cc
#sed -i -e 's/BrEC = .*/BrEC = "Br30mmEC80mm";/g' ./trackJetMod.cc
#sed -i -e 's/min_const = .*/min_const = "11111";/g' ./trackJetMod.cc
#sed -i -e 's/min_constPt = .*/min_constPt = "22222";/g' ./trackJetMod.cc
#sed -i -e 's/ETA_CUT     = .*/ETA_CUT     = 2.5;/g' ./trackJetMod.cc
#echo 'running fastjet for Br30mm EC80mm 1.5mm bin'
#./compile_runMod.sh
#./trackjetMod
## ggF  Br 30mm EC 80mm eta 2.5 zbin 7.5mm
#sed -i -e 's/sample = .*/sample = "ggF1.0";/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 40;/g' ./trackJetMod.cc
#sed -i -e 's/bin_width = .*/bin_width = "7.5mm";/g' ./trackJetMod.cc
#sed -i -e 's/BrEC = .*/BrEC = "Br30mmEC80mm";/g' ./trackJetMod.cc
#sed -i -e 's/min_const = .*/min_const = "11111";/g' ./trackJetMod.cc
#sed -i -e 's/min_constPt = .*/min_constPt = "22222";/g' ./trackJetMod.cc
#sed -i -e 's/ETA_CUT     = .*/ETA_CUT     = 2.5;/g' ./trackJetMod.cc
#echo 'running fastjet for Br30mm EC80mm 7.5mm bin'
#./compile_runMod.sh
#./trackjetMod
## MB_1  Br 30mm EC 80mm eta 2.5 zbin 1.5mm
#sed -i -e 's/sample = .*/sample = "MB_1";/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 200;/g' ./trackJetMod.cc
#sed -i -e 's/bin_width = .*/bin_width = "1.5mm";/g' ./trackJetMod.cc
#sed -i -e 's/BrEC = .*/BrEC = "Br30mmEC80mm";/g' ./trackJetMod.cc
#sed -i -e 's/min_const = .*/min_const = "11111";/g' ./trackJetMod.cc
#sed -i -e 's/min_constPt = .*/min_constPt = "22222";/g' ./trackJetMod.cc
#sed -i -e 's/ETA_CUT     = .*/ETA_CUT     = 2.5;/g' ./trackJetMod.cc
#echo 'running fastjet for Br30mm EC80mm 1.5mm bin'
#./compile_runMod.sh
#./trackjetMod
## MB_1  Br 30mm EC 80mm eta 2.5 zbin 7.5mm
#sed -i -e 's/sample = .*/sample = "MB_1";/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 40;/g' ./trackJetMod.cc
#sed -i -e 's/bin_width = .*/bin_width = "7.5mm";/g' ./trackJetMod.cc
#sed -i -e 's/BrEC = .*/BrEC = "Br30mmEC80mm";/g' ./trackJetMod.cc
#sed -i -e 's/min_const = .*/min_const = "11111";/g' ./trackJetMod.cc
#sed -i -e 's/min_constPt = .*/min_constPt = "22222";/g' ./trackJetMod.cc
#sed -i -e 's/ETA_CUT     = .*/ETA_CUT     = 2.5;/g' ./trackJetMod.cc
#echo 'running fastjet for Br30mm EC80mm 7.5mm bin'
#./compile_runMod.sh
#./trackjetMod


#############  IN trackJetMod.cc CHANGE THE EVENT LIST FILE   ###################
############# user.tkar.EventListpp4bQCD_2_5_allAnaCuts_000005.root ##############
############# user.tkar.EventListpp4bQCD_2_5_allAnaCuts_000005_.root ############## more stats
#
# pp_4bQCD  Br 30mm EC 80mm eta 2.5 zbin 1.5mm
sed -i -e 's/sample = .*/sample = "pp_4bQCD";/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 200;/g' ./trackJetMod.cc
sed -i -e 's/bin_width = .*/bin_width = "1.5mm";/g' ./trackJetMod.cc
sed -i -e 's/BrEC = .*/BrEC = "Br30mmEC80mm";/g' ./trackJetMod.cc
sed -i -e 's/min_const = .*/min_const = "11111";/g' ./trackJetMod.cc
sed -i -e 's/min_constPt = .*/min_constPt = "22222";/g' ./trackJetMod.cc
sed -i -e 's/ETA_CUT     = .*/ETA_CUT     = 2.5;/g' ./trackJetMod.cc
echo 'running fastjet for Br30mm EC80mm 1.5mm bin'
./compile_runMod.sh
./trackjetMod
## pp_4bQCD  Br 30mm EC 80mm eta 2.5 zbin 7.5mm
#sed -i -e 's/sample = .*/sample = "pp_4bQCD";/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 40;/g' ./trackJetMod.cc
#sed -i -e 's/bin_width = .*/bin_width = "7.5mm";/g' ./trackJetMod.cc
#sed -i -e 's/BrEC = .*/BrEC = "Br30mmEC80mm";/g' ./trackJetMod.cc
#sed -i -e 's/min_const = .*/min_const = "11111";/g' ./trackJetMod.cc
#sed -i -e 's/min_constPt = .*/min_constPt = "22222";/g' ./trackJetMod.cc
#sed -i -e 's/ETA_CUT     = .*/ETA_CUT     = 2.5;/g' ./trackJetMod.cc
#echo 'running fastjet for Br30mm EC80mm 7.5mm bin'
#./compile_runMod.sh
#./trackjetMod
## MB_pp4b  Br 30mm EC 80mm eta 2.5 zbin 1.5mm
#sed -i -e 's/sample = .*/sample = "MB_pp4b";/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 200;/g' ./trackJetMod.cc
#sed -i -e 's/bin_width = .*/bin_width = "1.5mm";/g' ./trackJetMod.cc
#sed -i -e 's/BrEC = .*/BrEC = "Br30mmEC80mm";/g' ./trackJetMod.cc
#sed -i -e 's/min_const = .*/min_const = "11111";/g' ./trackJetMod.cc
#sed -i -e 's/min_constPt = .*/min_constPt = "22222";/g' ./trackJetMod.cc
#sed -i -e 's/ETA_CUT     = .*/ETA_CUT     = 2.5;/g' ./trackJetMod.cc
#echo 'running fastjet for Br30mm EC80mm 1.5mm bin'
#./compile_runMod.sh
#./trackjetMod
## MB_pp4b  Br 30mm EC 80mm eta 2.5 zbin 7.5mm
#sed -i -e 's/sample = .*/sample = "MB_pp4b";/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 40;/g' ./trackJetMod.cc
#sed -i -e 's/bin_width = .*/bin_width = "7.5mm";/g' ./trackJetMod.cc
#sed -i -e 's/BrEC = .*/BrEC = "Br30mmEC80mm";/g' ./trackJetMod.cc
#sed -i -e 's/min_const = .*/min_const = "11111";/g' ./trackJetMod.cc
#sed -i -e 's/min_constPt = .*/min_constPt = "22222";/g' ./trackJetMod.cc
#sed -i -e 's/ETA_CUT     = .*/ETA_CUT     = 2.5;/g' ./trackJetMod.cc
#echo 'running fastjet for Br30mm EC80mm 7.5mm bin'
#./compile_runMod.sh
#./trackjetMod
