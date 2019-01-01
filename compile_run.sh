#g++ short-example.cc -o short-example \
#`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./short-example

#g++ trackJet.cc -o trackjet \
g++ Rate_sumpt.cc trackJet.cc -o trackjet \
`root-config --cflags --libs` \
`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./trackjet
