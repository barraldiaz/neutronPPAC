#include <stdlib.h>
#include <stdio.h>
//#include <sstream.h>
#include "TChain.h"
#include "TFile.h"


TChain *t1;
TCutG CUT;

void cut_show(){




  Float_t  PPAC2_X_C, PPAC2_Y_C, PPAC3_X_C, PPAC3_Y_C ,PPAC1_X_C, PPAC1_Y_C ;
  TCanvas *c1 = new TCanvas();
  c1->SetLogz();
  t1 =new TChain("RD");

    t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_000r.root");

    t1->SetBranchAddress("PPAC2_X_C",&PPAC2_X_C);
  t1->SetBranchAddress("PPAC2_Y_C",&PPAC2_Y_C); 
  t1->SetBranchAddress("PPAC3_Y_C",&PPAC3_Y_C); 
  t1->SetBranchAddress("PPAC3_X_C",&PPAC3_X_C);
  t1->SetBranchAddress("PPAC1_X_C",&PPAC1_X_C); 
  t1->SetBranchAddress("PPAC1_Y_C",&PPAC1_Y_C); 


    TFile *f = new TFile("cuts/generalCuts/cutA1A2_general.root","read"); //Archivo con cortess
  TCutG *CUT = (TCutG*)f->Get("cut_general");//definimos cortes
  CUT->Draw();


    t1->Draw("PPAC1_Y_C:PPAC1_X_C>>(240,-120,120,240,-120,120)","CUT","colz");



}
