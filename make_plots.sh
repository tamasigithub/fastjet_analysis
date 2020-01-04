#!/usr/bin/env bash
CURRENT_DIR=$PWD
echo ${CURRENT_DIR}
root -l padToTex.cpp -e 'pad("c3_a", 1, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c3_b", 1);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c4_a", 1, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c4_b", 1);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c5_a", 1, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c5_b", 1, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c5_c", 1);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c5_d", 1, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c8_a", 2);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c8_b", 2);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c8_c", 2, false, "GenJet4b2_6.0_allR0.4.root");'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c8_d", 2, false, "GenJet4b2_6.0_allR0.4.root");'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c31a", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c31b", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c41b", 1);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c41d", 1);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c43a", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c43b", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c44d", 3);'<<EOF
EOF
./rootTex2pdf ./analysis_plots/tex/*.tex
echo "TEX files modified DONE!"

cd ${CURRENT_DIR}/analysis_plots/tex/
pdflatex c3_a.tex
pdflatex c3_b.tex
pdflatex c4_a.tex
pdflatex c4_b.tex
pdflatex c5_a.tex
pdflatex c5_b.tex
pdflatex c5_c.tex
pdflatex c5_d.tex
pdflatex c8_a.tex
pdflatex c8_b.tex
pdflatex c8_c.tex
pdflatex c8_d.tex
pdflatex c31a.tex
pdflatex c31b.tex
pdflatex c41b.tex
pdflatex c41d.tex
pdflatex c43a.tex
pdflatex c43b.tex
pdflatex c44d.tex
cd ${CURRENT_DIR}
echo 'DONE!'
