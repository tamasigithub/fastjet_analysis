curl -O http://fastjet.fr/repo/fastjet-3.3.2.tar.gz
tar zxvf fastjet-3.3.2.tar.gz
cd fastjet-3.3.2/
./configure --prefix=$PWD/../fastjet-install
make
make check
make install
cd ..
