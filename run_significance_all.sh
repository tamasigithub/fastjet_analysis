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
root -b -l Significance_summary.cpp -e 'plot();'<<EOF
EOF
echo 'Done Significance Summary'
echo 'NOW RUNNING SENSITIVITY MACRO'
#
root -b -l Sensitivity_lambda.cpp -e 'final_plot();'<<EOF
EOF
echo 'Done Sensitivity'
#
##
./rootTex2pdf ./analysis_plots/tex/*.tex
echo "TEX files modified DONE!"
#
cd ${CURRENT_DIR}/analysis_plots/tex/
pdflatex mgSB.tex
pdflatex mgZsum.tex
pdflatex mgZiZtot.tex
pdflatex gZatpT.tex
pdflatex gSBatpT.tex
pdflatex Sens_pTthre.tex
pdflatex sens_ithBincontri.tex
mv ./*.pdf ./pdf/Sensitivity_Summary/
rm ./*.log
rm ./*.aux
cd ${CURRENT_DIR}
echo 'DONE!'
#vlc ~/Videos/damodarashtaka.mp4
