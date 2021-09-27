#!/usr/bin/env bash 
#root -l -q <<EOF
#.L padToTex.cpp+g
#padToTex("c3_b");
#EOF
root -b -l padToTex.cpp -e 'pad("c3_b");' <<EOF
EOF
root -b -l padToTex.cpp -e 'pad("c4_b");' <<EOF
EOF
./rootTex2pdf ./analysis_plots/tex/*.tex
echo "DONE!"
