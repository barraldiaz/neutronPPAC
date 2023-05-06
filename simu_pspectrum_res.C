#include "TMath.h"
#include "TMinuit.h"
#include "TFile.h"
#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TPaveText.h"
#include "iostream"
#include "TStopwatch.h"
#include "TColor.h"
#include "Rtypes.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TMath.h"
#include <exception>
#include "TGraphErrors.h"
#include "TGraph.h"
#include "TF1.h"
#include "TH2.h"
#include "TRandom3.h"
#include "TSpline.h"
#include "TStyle.h"
#include <iostream>
#include <fstream>




Double_t myfunction(Double_t *x,Double_t *par)
{
  
  //Reads a SRIM file and creates a Spline to interpolate R(mm) versus E(MeV)

  Float_t xx =x[0]; 
  
  TGraphErrors *gsth1=new TGraphErrors("./p_d2_900mbar_MeV_mm.dat","%lg %lg");

  Int_t npts;
  npts=gsth1->GetN(); 
  
  double *ener;
  double *rang; 
  
  TSpline3* RmmvsEMeV;	//xs versus theta cm 
  
  ener = new double[npts];
  rang = new double[npts];
  
  ener=gsth1->GetX();
  rang=gsth1->GetY();
 
  RmmvsEMeV = new TSpline3("RmmvsEMeV",ener,rang,npts,"b2,e2",0,0);
  Double_t f = RmmvsEMeV->Eval(xx);  
  return f;
  
}

Double_t myfunction_inv(Double_t *x,Double_t *par)
{
  
  //Reads a SRIM file and creates a Spline to interpolate R(mm) versus E(MeV)

  Float_t xx =x[0]; 
  
  TGraphErrors *gsth1=new TGraphErrors("./p_d2_900mbar_MeV_mm.dat","%lg %lg");

  Int_t npts;
  npts=gsth1->GetN(); 
  
  double *ener;
  double *rang; 
  
  TSpline3* EMeVvsRmm;	//xs versus theta cm 
  
  ener = new double[npts];
  rang = new double[npts];
  
  ener=gsth1->GetX();
  rang=gsth1->GetY();
 
  EMeVvsRmm = new TSpline3("EMeVvsRmm",rang,ener,npts,"b2,e2",0,0);
  Double_t f = EMeVvsRmm->Eval(xx);  
  return f;
  
}


Double_t myfunction2(Double_t *x,Double_t *par)
{
  
  //Reads a SRIM file and creates a Spline to interpolate R(mm) versus E(MeV)

  Float_t xx =x[0]; 
  
  TGraphErrors *gsth1=new TGraphErrors("./p_d2_900mbar_lstrag_mm_mm.dat","%lg %lg");

  Int_t npts;
  npts=gsth1->GetN(); 
  
  double *rang;
  double *strag; 
  
  TSpline3* LSmmvsRmm;	//xs versus theta cm 
  
  rang = new double[npts];
  strag = new double[npts];
  
  rang=gsth1->GetX();
  strag=gsth1->GetY();
 
  LSmmvsRmm = new TSpline3("LmmvsRmm",rang,strag,npts,"b2,e2",0,0);
  Double_t f = LSmmvsRmm->Eval(xx);  
  return f;
  
}




void simu_pspectrum_res(){
 


  TGraph *gr[5]; 
  TGraph *rgr[5];
 
  TCanvas *c1 = new TCanvas("c1","srim-calc",900,700);
  
  //Plot Options
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(11111);
  gStyle->SetOptFit(111111);
  gStyle->SetCanvasColor(0);
  gStyle->SetStatColor(0);
  gStyle->SetPadColor(0);
  gStyle->SetTitleFillColor(0);
  gStyle->SetTitleColor(1);
  gStyle->SetPalette(1);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetFrameBorderMode(0);
  

  c1->Divide(1,3);

  //double Anumber=26.; //Mass of the projectile
  double maxE=15.;//maximum energy of the proton to be measured in MeV
  double minE=0.001; //minimum value = 1keV
  
  c1->cd(1);
  //Plots the Spline 
  TF1 *f1 = new TF1("myfunc",myfunction,minE,maxE,1);
  f1->Draw("myfunc");
  f1->Draw("APLsame");
  f1->GetYaxis()->SetTitle("Range (mm)");
  f1->GetXaxis()->SetTitle("Elab (MeV)");

  f1->SetTitle("Range p (mm) vs Elab (MeV) SRIM");

  cout<<"1"<<endl;


  c1->cd(2);

   //Plots the Spline 
  TF1 *f1_inv = new TF1("myfunc1_inv",myfunction_inv,0.1,7000.);
  f1_inv->Draw("myfunc1_inv");
  f1_inv->Draw("APLsame");
  f1_inv->GetYaxis()->SetTitle("Elab (MeV)");
  f1_inv->GetXaxis()->SetTitle("R (mm)");

  f1_inv->SetTitle("Elab (MeV) vs Range p (mm)");

  cout<<"2"<<endl;

  c1->cd(3);

   //Plots the Spline 
  TF1 *f2 = new TF1("myfunc2",myfunction2,0.001,25000.,1);
  f2->Draw("myfunc2");
  f2->Draw("APLsame");
  f2->GetYaxis()->SetTitle("Long Strag (mm)");
  f2->GetXaxis()->SetTitle("R (mm)");

  f2->SetTitle("Long Strag (mm) vs Range p (mm)");

  cout<<"3"<<endl;

  
  TFile *fin=new TFile("./hist_rand_xs_100keV.root");  
  TH1F *hr=(TH1F*)fin->Get("hr");	
   
 
  TRandom3 *rbnd=new TRandom3();
  TRandom3 *rrnd=new TRandom3();
  TRandom3 *zval=new TRandom3();
 

  TH2D* h1 = new TH2D("h1","Emes vs Rmes",150,0.0,300,150,0.0,15.0);	
  TH1D* h2 = new TH1D("h2","Emes",150,0.0,15.0);	
  TH1D* h3 = new TH1D("h3","Rmes",150,0.0,300.);
  TFile *fout=new TFile("n_d_tree.root","recreate");	// output tree
  TTree *t1;
  
  double num,zvertex;
  double ep,theta,hipo,hipo_wcol,track_length,Rinc,Rmes;
  double Emes,Esi,Eq,Echarge,stragE_gas,stragE_si,resE,deltaE,long_strag;
  
  t1=new TTree("Exp_tree","Exp_tree");
  t1->Branch("zvertex", &zvertex, "zvertex/D");
  t1->Branch("ep", &ep, "ep/D"); 		
  t1->Branch("hipo", &hipo, "hipo/D");
  t1->Branch("hipo_wcol", &hipo_wcol, "hipo_wcol/D"); 	
  t1->Branch("track_length", &track_length, "track_length/D"); 			
  t1->Branch("Rinc", &Rinc, "Rinc/D"); 
  t1->Branch("Rmes", &Rmes, "Rmes/D");	
  t1->Branch("Emes", &Emes, "Emes/D");
  t1->Branch("Esi", &Esi, "Esi/D");
  t1->Branch("Eq", &Eq, "Eq/D");
  t1->Branch("Echarge", &Echarge, "Echarge/D");
  t1->Branch("long_strag", &long_strag, "long_strag/D");
 
  

  double lengthz=250.;    //250 mm (Máximum length of ACTAR TPC )

  TStopwatch *st=new TStopwatch();
  for(int i=0; i<100000;i++)
    {

    
      num=zval->Uniform();
      zvertex=num*lengthz; //Choose a vertex
      //Pick up an energy for the proton
      ep=hr->GetRandom();
      //We choose to measure at 5 degrees
      theta=5.*3.1416/180.;
      Rinc=f1->Eval(ep);
      //Hipotenusa within ACTAR TPC for a given angle
      hipo=(250-zvertex)/TMath::Cos(theta);
      //Hipotenusa of the window that acts as a colimetor. Part of the track length determined by the ACTAR TPC window. (regio that won't be accesible)
      //Radius of ACTAR TPC window is 0.075 mm --> 0.75 cm mylar
      
      hipo_wcol=0.075/TMath::Sin(theta);
      
      if(Rinc < hipo)
	{
	  track_length=Rinc-hipo_wcol;
	  long_strag=f2->Eval(track_length);
	  Rmes=rbnd->Gaus(track_length,long_strag);
	  Emes=f1_inv->Eval(Rmes);
	  //cout<<"Emes=" <<Emes<< endl;
	  Eq=f1_inv->Eval(track_length);
	  Echarge=rrnd->Gaus(Eq,0.10*Eq);
	}
      else if(Rinc >= hipo)
	{
	  track_length=hipo-hipo_wcol;
	  Esi=f1_inv->Eval(Rinc-track_length);
	  resE=0.050; //Silicon detector resolution 50 keV
	  stragE_gas=0.023; // (MeV/u) Maximum value that corresponds to a proton with 2 MeV/u through 25 cm of D2 at 900 mbar
	  stragE_si=0.18; //(MeV/u) Maximum value that corresponds to a proton with 9 MeV/u after the punchthrough 
	  deltaE=sqrt(resE*resE+stragE_gas*stragE_gas+stragE_si*stragE_si);
	  Emes=rbnd->Gaus(Esi,deltaE);
	}

      
      if(track_length < 4){track_length=-500.0; }
     
      if(track_length > 4)
	{
	  h1->Fill(Rmes,Emes);
	  h2->Fill(Emes);
	  h3->Fill(Rmes);
	}
      
      t1->Fill();
    }
  st->Stop(); 
  cout << "Random: " << st->CpuTime() << endl;
  
  TCanvas *c2 = new TCanvas("c2","physics (900 mbar)",900,700);
  gStyle->SetCanvasBorderMode(0);
  c2->Divide(2,2);
  
  c2->cd(1);
  h1->Draw("colz");
  c2->cd(2);
  h2->Draw("colz");
  c2->cd(3);
  h3->Draw();
 
  
  
  h1->Write();
  h2->Write();
  h3->Write();
 
 
  t1->Write();
  fout->Close();

  c2->SaveAs("simu_pspectrum_2.pdf");
  c1->SaveAs("simu_pspectrum.pdf");
  
 
  
  
}
