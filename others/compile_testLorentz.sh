g++ testLorentzVector.cc -o testlorentz \
`root-config --cflags --libs` \
`fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
