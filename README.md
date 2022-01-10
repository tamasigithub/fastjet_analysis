# Fastjet

## This repository contains macros I've used for jet clustering during my PhD.

### Macro descriptions
Calo emulation: trackJet\_1.cc (newer and better version of track\_jet.cc) 
TTT jets (ideal case):  trackJetMod\_1.cc : use of matched track properties instead of reconstructed tracks
TTT jets :  trackJetMod.cc (latest version)

**Generator level analysis for HH->4b using only the pp->4b QCD background:**
main macro - *GenAnalysis\_smeared.cpp*
includes - *GenAnalysis\_smeared.h, GenAna\_1.cpp, GenAna\_0.cpp, GenAna\_\_1.cpp, GenAna\_\_2.cpp, GenAna\_2.cpp, GenAna\_2\_5.cpp, GenAna\_3.cpp, GenAna\_bckgnd.cpp, SetAxix\_Props.cpp*

Run the macro *run\_analysis\_all.sh* to produce beautiful looking plots.

*run\_analysis\_all.sh* calls *plot()* from *GenAnalysis\_smeared.cpp* in batchmode from the root shell.
It then calls *padToTex* to produce tex files followed by *rootTex2pdf* that adds the Tikz package to produce latex style plots.


#### Clone instructions
**TODO: EDIT links**
Next go to the directory where you would like to clone this repository and type
```
git clone git@github.com:tamasigithub/REPO_upd.git

			OR

git clone git@gitlab.com:tamasigithub/REPO_upd.git
```

Now, go to the git repository you just cloned and you are all set to use git
```
cd REPO_upd
```

#### I just created a new branch ;) 
I did the following to create a new branch:
```
git branch tamasi
```

You can list all the branches you have in your repo by doing
```
git branch
```

It prints the following for me:
```
*master
tamasi
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


#### To pull updates from the master branch do
```
git pull origin master
```

The pull command is equivalent to git fetch followed by git merge

If your branch and master branch are different, which might be the case, it will complain saying there is a conflict in some file

You will have to fix this conflict first

There are some instructions here:
* https://help.github.com/en/articles/resolving-a-merge-conflict-using-the-command-line 
* https://docs.gitlab.com/ee/university/training/topics/merge_conflicts.html

You can **switch b/w master and your local branch** by doing
```
git branch 
```
This will list all the branches and highlight the branch you are presently working on

if your local branch'tamasi' is highlighted in green  then doing
***git checkout master*** will switch to master 

You can switch back to your local branch by doing 
```
git checkout tamasi
```

Now it's time to learn how to merge your local branch changes to master

I have'nt done it before.. I am learning too I will do it slowly
First switch to the master branch
```
git checkout master
```

next pass the merge command
```
git merge tamasi
```

if you want to checkout a specific remote branch from a repository

clone the master branch and do :
```
git checkout --track origin/<name_of_remote_branch>
```


To untrack a file already in the repository:
```
git rm --cached <file_name>
### Contact 
Tamasi Kar, University of Heidelberg   
*tamasi.kar@cern.ch*
