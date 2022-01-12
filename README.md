# Fastjet

## This repository contains macros I've used for jet clustering during my PhD.
It is based on Fastjet version 3.3.2

#### Clone instructions
**TODO: EDIT links**
Next go to the directory where you would like to clone this repository and type
```
git clone git@bitbucket.org:kartamasi16/fastjet.git

```
There are several branches. Checkout the most latest branch -> fastJet3.3.2
```
cd fastjet

git checkout fastJet3.3.2

```
You will have to run the install script again to set the paths correctly on your system
```
. ./install.sh
```

You can create your own branch and start working on it;) 
e.g. create a new branch tamasi:
```
git branch tamasi
```

You can list all the branches you have in your repo by doing
```
git branch
```

To switch to the newly created branch 'tamasi' do
```
git checkout tamasi
```

You can now create and edit files in your own branch and commit changes to your own branch
```
touch test.txt
git add test.txt
git status
git commit -m "hurray my first test text file ;)"
git push --set-upstream origin tamasi
```
This has now updated your changes to the remote repository -> GO CHECK!
To untrack a file already in the repository:
```
git rm --cached <file_name>

### Code descriptions

**Generator level analysis for HH->4b using only the pp->4b QCD background:**
The analysis is uses a very simple cut-flow analysis. All the code for this exist in Gen\_Ana

0. The Jet clustering source codes are in the folder Gen\_Ana/Cluster
The main source file Gen\_Jet\_2.cc and the script to run it is compileGen\_run\_2.sh
This clustering is particle level and involves no detector, however involves jet smearing to account for finite detector resolution.

1. Main analysis macro - *GenAnalysis\_smeared.cpp*

2. Includes - *GenAnalysis\_smeared.h, GenAna\_1.cpp, GenAna\_0.cpp, GenAna\_\_1.cpp, GenAna\_\_2.cpp, GenAna\_2.cpp, GenAna\_2\_5.cpp, GenAna\_3.cpp, GenAna\_bckgnd.cpp, SetAxix\_Props.cpp*

The numbers at the end of the file names correspond to different kappa lambda values.

3. Run the macro *run\_analysis\_all.sh* to produce beautiful looking plots.

*run\_analysis\_all.sh* calls *plot()* from *GenAnalysis\_smeared.cpp* in batchmode from the root shell.
It then calls *padToTex* to produce tex files followed by *rootTex2pdf* that adds the Tikz package to produce latex style plots.

**TTT trigger studies**

1. Calo emulation: Manin file-- trackJet\_1.cc (newer and better version of track\_jet.cc). It can be compiled using compile\_run\_1.sh and executed with the following commands:
```
./compile_run_1.sh
./tracjet_1

```
The input files are read in trackJet\_1.cc. 

The calorimeter specifications are specified in CaloEmu.h. There is also a corresponding source file.
The calorimeter emulations considers the ECAL granularity of FCC-hh reference detector and also assumes a magnetic field of 4T. Smearing is done in the main file.


2. TTT jets (ideal case):  trackJetMod\_1.cc : use of matched track properties instead of reconstructed tracks

TTT jets :  trackJetMod.cc (latest version)



### Contact 
Tamasi Kar, University of Heidelberg   
*tamasi.kar@cern.ch*
