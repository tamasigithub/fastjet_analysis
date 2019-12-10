#g++ short-example.cc -o short-example \
#`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./short-example
g++ Gen_output_2.cc Gen_Jet_2.cc -o genjet_2 \
`root-config --cflags --libs` \
`fastjet-config --cxxflags --libs --plugins`
#`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./trackjet
