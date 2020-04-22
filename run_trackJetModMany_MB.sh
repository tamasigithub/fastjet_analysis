#!/bin/sh
# MB  30mm
## 5trk
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents= 5;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 250;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB1.2mm_30mm_5trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 5trk 1.2mm bin'
./compile_runMod.sh
./trackjetMod
#
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents= 5;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 200;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB1.5mm_30mm_5trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 5trk 1.5mm bin'
./compile_runMod.sh
./trackjetMod
#
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents= 5;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 100;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB3.0mm_30mm_5trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 5trk 3.0mm bin'
./compile_runMod.sh
./trackjetMod
#
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents= 5;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 40;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB7.5mm_30mm_5trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 5trk 7.5mm bin'
./compile_runMod.sh
./trackjetMod
## 4trk
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents= 4;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 250;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB1.2mm_30mm_4trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 4trk 1.2mm bin'
./compile_runMod.sh
./trackjetMod
#
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents= 4;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 200;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB1.5mm_30mm_4trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 4trk 1.5mm bin'
./compile_runMod.sh
./trackjetMod
#
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents= 4;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 100;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB3.0mm_30mm_4trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 4trk 3.0mm bin'
./compile_runMod.sh
./trackjetMod
#
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents= 4;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 40;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB7.5mm_30mm_4trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 4trk 7.5mm bin'
./compile_runMod.sh
./trackjetMod
## 3trk
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 3;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 250;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB1.2mm_30mm_3trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 3trk 1.2mm bin'
./compile_runMod.sh
./trackjetMod
##
#sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 3;/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 200;/g' ./trackJetMod.cc
#sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB1.5mm_30mm_3trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
#echo 'running fastjet for 30mm 3trk 1.5mm bin'
#./compile_runMod.sh
#./trackjetMod
##
#sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 3;/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 100;/g' ./trackJetMod.cc
#sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB3.0mm_30mm_3trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
#echo 'running fastjet for 30mm 3trk 3.0mm bin'
#./compile_runMod.sh
#./trackjetMod
##
#sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 3;/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 40;/g' ./trackJetMod.cc
#sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB7.5mm_30mm_3trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
#echo 'running fastjet for 30mm 3trk 7.5mm bin'
#./compile_runMod.sh
#./trackjetMod
## 2trk
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 2;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 250;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB1.2mm_30mm_2trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 2trk 1.2mm bin'
./compile_runMod.sh
./trackjetMod
##
#sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 2;/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 200;/g' ./trackJetMod.cc
#sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB1.5mm_30mm_2trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
#echo 'running fastjet for 30mm 2trk 1.5mm bin'
#./compile_runMod.sh
#./trackjetMod
##
#sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 2;/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 100;/g' ./trackJetMod.cc
#sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB3.0mm_30mm_2trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
#echo 'running fastjet for 30mm 2trk 3.0mm bin'
#./compile_runMod.sh
#./trackjetMod
##
#sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 2;/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 40;/g' ./trackJetMod.cc
#sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB7.5mm_30mm_2trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
#echo 'running fastjet for 30mm 2trk 7.5mm bin'
#./compile_runMod.sh
#./trackjetMod
## 1trk
sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 1;/g' ./trackJetMod.cc
sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 250;/g' ./trackJetMod.cc
sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB1.2mm_30mm_1trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
echo 'running fastjet for 30mm 1trk 1.2mm bin'
./compile_runMod.sh
./trackjetMod
##
#sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 1;/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 200;/g' ./trackJetMod.cc
#sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB1.5mm_30mm_1trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
#echo 'running fastjet for 30mm 1trk 1.5mm bin'
#./compile_runMod.sh
#./trackjetMod
##
#sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 1;/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 100;/g' ./trackJetMod.cc
#sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB3.0mm_30mm_1trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
#echo 'running fastjet for 30mm 1trk 3.0mm bin'
#./compile_runMod.sh
#./trackjetMod
##
#sed -i -e 's/MIN_Constituents = .*/MIN_Constituents = 1;/g' ./trackJetMod.cc
#sed -i -e 's/NZVTXBIN = .*/NZVTXBIN = 40;/g' ./trackJetMod.cc
#sed -i -e 's/TrkJPU1kMB...mm_..mm_.trk2.5_2GeV_2GeV_3.root/TrkJPU1kMB7.5mm_30mm_1trk2.5_2GeV_2GeV_3.root/g' ./trackJetMod.cc
#echo 'running fastjet for 30mm 1trk 7.5mm bin'
#./compile_runMod.sh
#./trackjetMod
