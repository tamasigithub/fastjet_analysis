#g++ short-example.cc -o short-example \
#`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./short-example

#g++ trackJet.cc -o trackjet \
g++ TrigEff.cc Rate_sumpt.cc trackJetMod_1.cc -o trackjetMod_1 \
`root-config --cflags --libs` \
`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./trackjet
