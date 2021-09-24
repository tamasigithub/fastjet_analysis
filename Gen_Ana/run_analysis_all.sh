#!/usr/bin/env bash
CURRENT_DIR=$PWD
echo ${CURRENT_DIR}
sed -i -e 's/_2.5_allR0.2/_2.5_allR0.4/g' ./GenAnalysis_smeared.h
root -b -l GenAnalysis_smeared.cpp -e 'plot();'<<EOF
EOF
echo 'Done eta 2.5 all R=0.4'
#
sed -i -e 's/_2.5_allR0.4/_2.5_allR0.2/g' ./GenAnalysis_smeared.h
root -b -l GenAnalysis_smeared.cpp -e 'plot();'<<EOF
EOF
echo 'Done eta 2.5 all R=0.2'
#
sed -i -e 's/_2.5_allR0.2/_2.5_allR0.3/g' ./GenAnalysis_smeared.h
root -b -l GenAnalysis_smeared.cpp -e 'plot();'<<EOF
EOF
echo 'DONE eta 2.5 all R=0.3'
#
sed -i -e 's/_2.5_allR0.3/_2.5_allR0.5/g' ./GenAnalysis_smeared.h
root -b -l GenAnalysis_smeared.cpp -e 'plot();'<<EOF
EOF
echo 'Done eta 2.5 all R=0.5'
#
sed -i -e 's/_2.5_allR0.5/_2.5_4R0.4/g' ./GenAnalysis_smeared.h
root -b -l GenAnalysis_smeared.cpp -e 'plot();'<<EOF
EOF
echo 'Done eta 2.5 4only R=0.4'
#
sed -i -e 's/_2.5_4R0.4/_6.0_allR0.4/g' ./GenAnalysis_smeared.h
root -b -l GenAnalysis_smeared.cpp -e 'plot();'<<EOF
EOF
echo 'Done eta 6.0 all R=0.4'
#
sed -i -e 's/_6.0_allR0.4/_2.5_allR0.2/g' ./GenAnalysis_smeared.h
##
#root -l padToTex.cpp -e 'pad("c3_a", 0);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c3_b", 0);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c4_a", 0);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c4_b", 0);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c5_a", 0);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c5_b", 0);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c5_c", 0);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c5_d", 0);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c8_a", 1);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c8_b", 1);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c31a", 1);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c31b", 1);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c41b", 0);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c41d", 0);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c43a", 1);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c43b", 1);'<<EOF
#EOF
#root -l padToTex.cpp -e 'pad("c44d", 1);'<<EOF
#EOF
#./rootTex2pdf ../analysis_plots/tex/*.tex
#echo "TEX files modified DONE!"
#
#cd ${CURRENT_DIR}/../analysis_plots/tex/
#pdflatex c3_a.tex
#pdflatex c3_b.tex
#pdflatex c4_a.tex
#pdflatex c4_b.tex
#pdflatex c5_a.tex
#pdflatex c5_b.tex
#pdflatex c5_c.tex
#pdflatex c5_d.tex
#pdflatex c8_a.tex
#pdflatex c8_b.tex
#pdflatex c31a.tex
#pdflatex c31b.tex
#pdflatex c41b.tex
#pdflatex c41d.tex
#pdflatex c43a.tex
#pdflatex c43b.tex
#pdflatex c44d.tex
#cd ${CURRENT_DIR}
echo 'DONE!'
vlc ~/Videos/damodarashtaka.mp4
