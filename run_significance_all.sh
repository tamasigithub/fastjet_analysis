#!/usr/bin/env bash
CURRENT_DIR=$PWD
echo ${CURRENT_DIR}
root -b -l Significance_Pt.cpp -e 'pdf();'<<EOF
EOF
echo 'Done Significance for ctr = 1.0'
#
root -b -l Significance_Pt_0.cpp -e 'pdf();'<<EOF
EOF
echo 'Done Significance for ctr = 0.0'
#
root -b -l Significance_Pt__1.cpp -e 'pdf();'<<EOF
EOF
echo 'Done Significance for ctr = -1.0'
#
root -b -l Significance_Pt__2.cpp -e 'pdf();'<<EOF
EOF
echo 'Done Significance for ctr = -2.0'
#
root -b -l Significance_Pt_2.cpp -e 'pdf();'<<EOF
EOF
echo 'Done Significance for ctr = 2.0'
#
root -b -l Significance_Pt_2_5.cpp -e 'pdf();'<<EOF
EOF
echo 'Done Significance for ctr = 2.5'
#
root -b -l Significance_Pt_3.cpp -e 'pdf();'<<EOF
EOF
echo 'Done Significance for ctr = 3.0'
#
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
#./rootTex2pdf ./analysis_plots/tex/*.tex
#echo "TEX files modified DONE!"
#
#cd ${CURRENT_DIR}/analysis_plots/tex/
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
#vlc ~/Videos/damodarashtaka.mp4
