#g++ short-example.cc -o short-example \
#`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./short-example
g++ Gen_output.cc Gen_Jet.cc -o genjet \
`root-config --cflags --libs` \
`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./trackjet
