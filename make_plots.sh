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
root -l padToTex.cpp -e 'pad("c8_c", 2, false, false, "GenJet4b2_6.0_allR0.4_0.8_incl4bProbMH30.root");'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c8_d", 2, false, false, "GenJet4b2_6.0_allR0.4_0.8_incl4bProbMH30.root");'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c11a", 2);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c11b", 2);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c14a", 2);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c14b", 2);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c17a", 2);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c17b", 2);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c31a", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c31b", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c40a", 1, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c40b", 1, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c40c", 1, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c40d", 1, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c41b", 1, false, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c41d", 1, false, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c43a", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c43b", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c44d", 3);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c46a", 1, false, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c46b", 1, false, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c46c", 1, false, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c46d", 1, false, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c28a", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c28b", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c28c", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c28d", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c28e", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c28f", 0);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c54a", -1, true, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c54b", -1, true, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c54c", -1, true, true);'<<EOF
EOF
root -l padToTex.cpp -e 'pad("c54d", -1, true, true);'<<EOF
EOF
./rootTex2pdf ./analysis_plots/tex/*.tex
echo "TEX files modified DONE!"

cd ${CURRENT_DIR}/analysis_plots/tex/
sed -i -e 's/HH\ \\rightarrow/pp\ \\rightarrow/g' ./c8_b.tex
sed -i -e 's/HH\ \\rightarrow/pp\ \\rightarrow/g' ./c8_d.tex
sed -i -e 's/HH\ \\rightarrow/pp\ \\rightarrow/g' ./c11b.tex
sed -i -e 's/HH\ \\rightarrow/pp\ \\rightarrow/g' ./c14b.tex
sed -i -e 's/HH\ \\rightarrow/pp\ \\rightarrow/g' ./c17b.tex
sed -i -e 's/HH\ \\rightarrow/pp\ \\rightarrow/g' ./c28d.tex
sed -i -e 's/HH\ \\rightarrow/pp\ \\rightarrow/g' ./c28e.tex
sed -i -e 's/HH\ \\rightarrow/pp\ \\rightarrow/g' ./c28f.tex
### to comment out a line with a pattern
sed -i -e '/after analysis cuts/s/^/%/g' ./c28a.tex
sed -i -e '/after analysis cuts/s/^/%/g' ./c28b.tex
sed -i -e '/after analysis cuts/s/^/%/g' ./c28c.tex
sed -i -e '/after analysis cuts/s/^/%/g' ./c28d.tex
sed -i -e '/after analysis cuts/s/^/%/g' ./c28e.tex
sed -i -e '/after analysis cuts/s/^/%/g' ./c28f.tex
sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c54a.tex
sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c54b.tex
sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c54c.tex
sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c54d.tex
#sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c3_a.tex
#sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c3_b.tex
#sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c4_a.tex
#sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c4_b.tex
#sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c5_a.tex
#sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c5_b.tex
#sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c5_c.tex
#sed -i -e '/HH\ \\rightarrow/s/^/%/g' ./c5_d.tex
sed -i -e 's/ \\rightarrow b\\bar{b}b\\bar{b}/,\~ggF/g' ./c3_a.tex
sed -i -e 's/ \\rightarrow b\\bar{b}b\\bar{b}/,\~ggF/g' ./c3_b.tex
sed -i -e 's/ \\rightarrow b\\bar{b}b\\bar{b}/,\~ggF/g' ./c4_a.tex
sed -i -e 's/ \\rightarrow b\\bar{b}b\\bar{b}/,\~ggF/g' ./c4_b.tex
sed -i -e 's/ \\rightarrow b\\bar{b}b\\bar{b}/,\~ggF/g' ./c5_a.tex
sed -i -e 's/ \\rightarrow b\\bar{b}b\\bar{b}/,\~ggF/g' ./c5_b.tex
sed -i -e 's/ \\rightarrow b\\bar{b}b\\bar{b}/,\~ggF/g' ./c5_c.tex
sed -i -e 's/ \\rightarrow b\\bar{b}b\\bar{b}/,\~ggF/g' ./c5_d.tex
#
sed -i -e 's/b\\bar{b}b\\bar{b}/b\\bar{b}b\\bar{b},\\text{SM}/g' ./c8_a.tex
sed -i -e 's/b\\bar{b}b\\bar{b}/b\\bar{b}b\\bar{b},\\text{SM}/g' ./c8_c.tex
sed -i -e 's/b\\bar{b}b\\bar{b}/b\\bar{b}b\\bar{b},\\text{SM}/g' ./c11a.tex
sed -i -e 's/b\\bar{b}b\\bar{b}/b\\bar{b}b\\bar{b},\\text{SM}/g' ./c14a.tex
sed -i -e 's/b\\bar{b}b\\bar{b}/b\\bar{b}b\\bar{b},\\text{SM}/g' ./c17a.tex
sed -i -e 's/b\\bar{b}b\\bar{b}/b\\bar{b}b\\bar{b},\\text{SM}/g' ./c31a.tex
sed -i -e 's/b\\bar{b}b\\bar{b}/b\\bar{b}b\\bar{b},\\text{SM}/g' ./c31b.tex
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
pdflatex c11a.tex
pdflatex c11b.tex
pdflatex c14a.tex
pdflatex c14b.tex
pdflatex c17a.tex
pdflatex c17b.tex
pdflatex c31a.tex
pdflatex c31b.tex
pdflatex c40a.tex
pdflatex c40b.tex
pdflatex c40c.tex
pdflatex c40d.tex
pdflatex c41b.tex
pdflatex c41d.tex
pdflatex c43a.tex
pdflatex c43b.tex
pdflatex c44d.tex
pdflatex c46a.tex
pdflatex c46b.tex
pdflatex c46c.tex
pdflatex c46d.tex
pdflatex c28a.tex
pdflatex c28b.tex
pdflatex c28c.tex
pdflatex c28d.tex
pdflatex c28e.tex
pdflatex c28f.tex
pdflatex c54a.tex
pdflatex c54b.tex
pdflatex c54c.tex
pdflatex c54d.tex
rm ./*.log
rm ./*.aux
cd ${CURRENT_DIR}
echo 'DONE!'
