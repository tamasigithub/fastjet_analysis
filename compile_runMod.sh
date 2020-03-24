#g++ short-example.cc -o short-example \
#`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./short-example

#g++ trackJet.cc -o trackjet \
g++ TrigEff.cc Rate_sumpt.cc trackJetMod.cc -o trackjetMod \
`root-config --cflags --libs` \
`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./trackjet
