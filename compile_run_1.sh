#g++ short-example.cc -o short-example \
#`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./short-example

g++ trackJet_1.cc -o trackjet_1 \
`root-config --cflags --libs` \
`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#./trackjet
