#include <iostream>
#include "TLatex.h"

void latex()
{
	TCanvas * C = new TCanvas();
	//TCanvas * C = new TCanvas("C","C",800,800);
	gStyle->SetOptStat(0);
	//TGaxis::SetMaxDigits(2);
	C->SetGridx();
	C->SetGridy();
	C->SetTickx();
	C->SetTicky();
	//! page0
	TLatex lat;
	lat.SetTextSize(0.03);
	lat.SetTextAlign(12);
	float Ylat, X1lat, X2lat, X3lat, X4lat, X5lat, X6lat, X7lat, X8lat, X9lat;
	float step = 0.06;
	Ylat = 0.96; 
	X1lat = 0.02;
	X2lat = X1lat + 2*0.09;
	X3lat = X2lat + 0.095;
	X4lat = X3lat + 0.095;
	X5lat = X4lat + 0.095;
	X6lat = X5lat + 0.095;
	X7lat = X6lat + 0.095;
	X8lat = X7lat + 0.095;
	X9lat = X8lat + 0.095;
	lat.DrawLatex(X1lat, Ylat, "N Events"); 
	lat.DrawLatex(X2lat, Ylat, "pp #rightarrow 4b");
	lat.DrawLatex(X3lat, Ylat, "k_{#lambda} = 1.0");
	lat.DrawLatex(X4lat, Ylat, "k_{#lambda} = 0.0");
	lat.DrawLatex(X5lat, Ylat, "k_{#lambda} = -1.0");
	lat.DrawLatex(X6lat, Ylat, "k_{#lambda} = -2.0");
	lat.DrawLatex(X7lat, Ylat, "k_{#lambda} = 2.0");
	lat.DrawLatex(X8lat, Ylat, "k_{#lambda} = 2.5");
	lat.DrawLatex(X9lat, Ylat, "k_{#lambda} = 3.0");

	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "N_{jets} #geq 4");
	lat.DrawLatex(X2lat, Ylat, Form("%g",Ylat));
	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "p_{T, L} #geq 55 GeV/c");
	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "p_{T, NL} #geq 40 GeV/c");
	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "N_{btags} #geq 4");
	Ylat -= step;
	lat.DrawLatex(X1lat, Ylat, "|M_{h1,h2} - 125|  #leq 40");
	return;
}
