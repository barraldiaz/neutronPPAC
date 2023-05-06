#include <stdlib.h>
#include <stdio.h>


TChain *t1=NULL;
TCanvas *c1=NULL;
TTreeViewer *v1=NULL;

Int_t T;
Int_t Ta;

void myAnr(int nb1, int nb2)
{
  cout << "Runs from " << nb1 << " to " << nb2 <<endl;
  T = 0;
  //gStyle->SetPalette(1);
  gStyle->SetOptStat(1001111);
  gStyle->SetFillStyle(1000);

  char name[100];
  
  if(!c1)
    c1 = new TCanvas("c1","myAnalysis",200,10,722,500);
  c1->ToggleEventStatus();
  gPad->SetGridx();
  gPad->SetGridy();
  //gPad->ToggleToolBar();

  cout << t1 << endl;
  if(!t1)
  t1 =new TChain("RD");
  for(Int_t i=nb1;i<=nb2;i++)
    { 
      Bool_t fExist = true;
      for(Int_t j=0;j<999&&fExist;j++)
	{
	  sprintf(name,"./RootR/r%04d_%03dr.root",i,j); 
	  ifstream mfile;
	  mfile.open(name);
	  if(mfile)
	    mfile.close();
	  else
	    fExist=false;
	  if(fExist)
	    {
	      cout << "Adding " << name << endl;
	      t1->Add(name);
	      Ta = (Int_t) (t1->GetEntries());
	      cout << "Entries " << Ta/1000 << "k "  << endl;
	    }  
	}
    }
  t1->SetLineColor(4);
  
  Float_t D1 =  533.-0.3-3.4*2.;//cm //Anode 1
  Float_t D2 =  533.-0.3-3.4;//cm //Anode 2
  Float_t D3 =  533.-0.3;//cm //Anode 3
  Float_t TOff1 = 790.; //ns
  Float_t TOff2 = 787.; //ns
  Float_t TOff3 = 790.; //ns
  Float_t VL = 29.9792458; //cm/ns

  t1->SetAlias("D1",Form("%f*1.0",D1));
  t1->SetAlias("D2",Form("%f*1.0",D2));
  t1->SetAlias("D3",Form("%f*1.0",D3));
  t1->SetAlias("T1",Form("-1.*PPAC1_HF_Dir_T+%f",TOff1));
  t1->SetAlias("T2",Form("-1.*PPAC2_HF_Dir_T+%f",TOff2));
  t1->SetAlias("T3",Form("-1.*PPAC3_HF_Dir_T+%f",TOff3));
  t1->SetAlias("V1","D1/T1");
  t1->SetAlias("V2","D2/T2");
  t1->SetAlias("V3","D3/T3");
  t1->SetAlias("VL",Form("%f*1.0",VL));
  t1->SetAlias("Gamma1","1/sqrt(1-V1*V1/VL/VL)");
  t1->SetAlias("Gamma2","1/sqrt(1-V2*V2/VL/VL)");
  t1->SetAlias("Gamma3","1/sqrt(1-V3*V3/VL/VL)");
  t1->SetAlias("En1","939.56542052*(Gamma1-1)");
  t1->SetAlias("En2","939.56542052*(Gamma2-1)");
  t1->SetAlias("En3","939.56542052*(Gamma3-1)");

  t1->SetAlias("CosThTar1","cos(atan(sqrt(pow(PPAC2_X_C-PPAC1_X_C-2.,2)+pow(PPAC2_Y_C-PPAC1_Y_C,2))/34.))");
  t1->SetAlias("CosThTar2","cos(atan(sqrt(pow(PPAC3_X_C-PPAC2_X_C,2)+pow(PPAC3_Y_C-PPAC2_Y_C,2))/34.))");
  
  gROOT->ProcessLine(".x cutA1A2.C");
  gROOT->ProcessLine(".x cutA2A3.C");
  gROOT->ProcessLine(".x cutXY1.C");
  gROOT->ProcessLine(".x cutXY2.C");
  gROOT->ProcessLine(".x cutXY3.C");
   
  //  new TBrowser();
   if(!v1)
    v1 =new TTreeViewer(t1);
  else
    {
      delete v1;
      v1 =new TTreeViewer(t1);
    }

  gPad->SetLogy(0);
  gPad->SetLogz(1);

  
}   



