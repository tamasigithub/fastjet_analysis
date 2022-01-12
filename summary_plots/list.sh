#change eta range from 1.5 to 2.5
sed -i -e 's@<\ 1.5@<\ 2.5@g' ./*.tex
#edit the TTT gapsize

#compile with pdfLatex
#NOTE: pdfLatex is declared as an alias that points to the full texlive package from cvmfs
#alias pdfLatex=/cvmfs/sft.cern.ch/lcg/external/texlive/2021/bin/x86_64-linux/pdflatex
pdfLatex ./C10_30mm_7515mm_2trk.tex
pdfLatex ./C11_30mm_7515mm_2trk.tex
pdfLatex ./C12_30mm_7515mm_2trk.tex
pdfLatex ./C1_30mm_7515mm_2trk.tex
pdfLatex ./C13_30mm_7515mm_2trk.tex
pdfLatex ./C14_30mm_7515mm_2trk.tex
pdfLatex ./C15_30mm_7515mm_2trk.tex
pdfLatex ./C16_30mm_7515mm_2trk.tex
pdfLatex ./C17_30mm_7515mm_2trk.tex
pdfLatex ./C18_30mm_7515mm_2trk.tex
pdfLatex ./C19_30mm_7515mm_2trk.tex
pdfLatex ./C20_30mm_7515mm_2trk.tex
pdfLatex ./C21_30mm_7515mm_2trk.tex
pdfLatex ./C22_30mm_7515mm_2trk.tex
pdfLatex ./C2_30mm_7515mm_2trk.tex
pdfLatex ./C23_30mm_7515mm_2trk.tex
pdfLatex ./C24_30mm_7515mm_2trk.tex
pdfLatex ./C24a_30mm_7515mm_2trk.tex
pdfLatex ./C29_30mm_7515mm_calo.tex
pdfLatex ./C32_30mm_7515mm_2trk.tex
pdfLatex ./C3_30mm_7515mm_2trk.tex
pdfLatex ./C33_30mm_7515mm_2trk.tex
pdfLatex ./C34_30mm_7515mm_2trk.tex
pdfLatex ./C35_30mm_7515mm_2trk.tex
pdfLatex ./C36_30mm_7515mm_2trk.tex
pdfLatex ./C37_30mm_7515mm_2trk.tex
pdfLatex ./C38_30mm_7515mm_2trk.tex
pdfLatex ./C39_30mm_7515mm_2trk.tex
pdfLatex ./C4_30mm_7515mm_2trk.tex
pdfLatex ./C5_30mm_7515mm_2trk.tex
pdfLatex ./C6_30mm_7515mm_2trk.tex
pdfLatex ./C7_30mm_7515mm_2trk.tex
pdfLatex ./C8_30mm_7515mm_2trk.tex
pdfLatex ./C9_30mm_7515mm_2trk.tex
rm ./*.aux
rm ./*.log
mv ./*.pdf ./pdf
