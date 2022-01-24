#change eta range from 1.5 to 2.5
sed -i -e 's@<\ 1.5@<\ 2.5@g' ./tex/*.tex
#edit the TTT gapsize

#compile with pdfLatex
#NOTE: pdfLatex is declared as an alias that points to the full texlive package from cvmfs
#alias pdfLatex=/cvmfs/sft.cern.ch/lcg/external/texlive/2021/bin/x86_64-linux/pdflatex
pdfLatex ./tex/C10_30mm_7515mm_2trk.tex
pdfLatex ./tex/C11_30mm_7515mm_2trk.tex
pdfLatex ./tex/C12_30mm_7515mm_2trk.tex
pdfLatex ./tex/C1_30mm_7515mm_2trk.tex
pdfLatex ./tex/C13_30mm_7515mm_2trk.tex
pdfLatex ./tex/C14_30mm_7515mm_2trk.tex
pdfLatex ./tex/C15_30mm_7515mm_2trk.tex
pdfLatex ./tex/C16_30mm_7515mm_2trk.tex
pdfLatex ./tex/C17_30mm_7515mm_2trk.tex
pdfLatex ./tex/C18_30mm_7515mm_2trk.tex
pdfLatex ./tex/C19_30mm_7515mm_2trk.tex
pdfLatex ./tex/C20_30mm_7515mm_2trk.tex
pdfLatex ./tex/C21_30mm_7515mm_2trk.tex
pdfLatex ./tex/C22_30mm_7515mm_2trk.tex
pdfLatex ./tex/C2_30mm_7515mm_2trk.tex
pdfLatex ./tex/C23_30mm_7515mm_2trk.tex
pdfLatex ./tex/C24_30mm_7515mm_2trk.tex
pdfLatex ./tex/C24a_30mm_7515mm_2trk.tex
pdfLatex ./tex/C29_30mm_7515mm_calo.tex
pdfLatex ./tex/C32_30mm_7515mm_2trk.tex
pdfLatex ./tex/C3_30mm_7515mm_2trk.tex
pdfLatex ./tex/C33_30mm_7515mm_2trk.tex
pdfLatex ./tex/C34_30mm_7515mm_2trk.tex
pdfLatex ./tex/C35_30mm_7515mm_2trk.tex
pdfLatex ./tex/C36_30mm_7515mm_2trk.tex
pdfLatex ./tex/C37_30mm_7515mm_2trk.tex
pdfLatex ./tex/C38_30mm_7515mm_2trk.tex
pdfLatex ./tex/C39_30mm_7515mm_2trk.tex
pdfLatex ./tex/C4_30mm_7515mm_2trk.tex
pdfLatex ./tex/C5_30mm_7515mm_2trk.tex
pdfLatex ./tex/C6_30mm_7515mm_2trk.tex
pdfLatex ./tex/C7_30mm_7515mm_2trk.tex
pdfLatex ./tex/C8_30mm_7515mm_2trk.tex
pdfLatex ./tex/C9_30mm_7515mm_2trk.tex
rm ./*.aux
rm ./*.log
mkdir ./tex/pdf
mv ./C*.pdf ./tex/pdf
