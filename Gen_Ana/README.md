## Macro descriptions
**Jet clustering at generator level**


**Generator level analysis for HH->4b using only the pp->4b QCD background:**
Needs input files from Gen\_Jet.cc (Gen\_Jet\_2.cc is the latest)
main macro - *GenAnalysis\_smeared.cpp*
includes - *GenAnalysis\_smeared.h, GenAna\_1.cpp, GenAna\_0.cpp, GenAna\_\_1.cpp, GenAna\_\_2.cpp, GenAna\_2.cpp, GenAna\_2\_5.cpp, GenAna\_3.cpp, GenAna\_bckgnd.cpp, SetAxix\_Props.cpp*

Run the macro *run\_analysis\_all.sh* to produce beautiful looking plots.

*run\_analysis\_all.sh* calls *plot()* from *GenAnalysis\_smeared.cpp* in batchmode from the root shell.
It then calls *padToTex* to produce tex files followed by *rootTex2pdf* that adds the Tikz package to produce latex style plots.
