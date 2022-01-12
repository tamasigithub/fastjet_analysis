# Fastjet

## This repository contains macros I've used for jet clustering during my PhD.
It is based on Fastjet version 3.3.2

### Macro descriptions
**Generator level analysis for HH->4b using only the pp->4b QCD background:**
The analysis is uses a very simple cut-flow analysis.

1. Main macro - *GenAnalysis\_smeared.cpp*

2. Includes - *GenAnalysis\_smeared.h, GenAna\_1.cpp, GenAna\_0.cpp, GenAna\_\_1.cpp, GenAna\_\_2.cpp, GenAna\_2.cpp, GenAna\_2\_5.cpp, GenAna\_3.cpp, GenAna\_bckgnd.cpp, SetAxix\_Props.cpp*

The numbers at the end of the file names correspond to different kappa lambda values.

3. Run the macro *run\_analysis\_all.sh* to produce beautiful looking plots.

*run\_analysis\_all.sh* calls *plot()* from *GenAnalysis\_smeared.cpp* in batchmode from the root shell.
It then calls *padToTex* to produce tex files followed by *rootTex2pdf* that adds the Tikz package to produce latex style plots.

**TTT trigger studies**
Calo emulation: trackJet\_1.cc (newer and better version of track\_jet.cc) 
TTT jets (ideal case):  trackJetMod\_1.cc : use of matched track properties instead of reconstructed tracks
TTT jets :  trackJetMod.cc (latest version)



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

You can now create a new test file
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
### Contact 
Tamasi Kar, University of Heidelberg   
*tamasi.kar@cern.ch*
