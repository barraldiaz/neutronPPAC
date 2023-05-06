#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <TString.h>
#include <algorithm>
#include <sstream>
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TObject.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TGraph.h>
#include "TH2.h"


TCutG CUT;

void read_file()
{

   
	TFile *f1=new TFile("/media/angel/TOSHIBA EXT/TFG/filtered_data/test3_1.root","read");
  //TFile *f1=new TFile("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_000r.root","read");
  f1->ls();
  TTree *t1=(TTree *)gDirectory->Get("RD");
  TCanvas  *c1 = new TCanvas();
   
  c1->SetLogz();
  

  
     
    t1->Draw("PPAC1_Y_C:PPAC1_X_C>>(240,-120,120,240,-120,120)","PPAC2_A>22000","colz");
  










//t1->Draw("PPAC1_Y_C:PPAC1_X_C>>a(400.,-150.,150.,400,-150.,150.)","","colz");
   //t1->Draw("ATS1>>h(12000,0,12000) ","PPAC1_ATS>=0 && PPAC1_A>20000");
    //t1->Draw("PPAC2_X_C>>h(600,-150,150)","");  

    //t1->Draw("PPAC1_X_C>>h(600,-150,150)","");
    //t1->Draw("PPAC3_X_C>>h(600,-150,150)","");

  //TARGET RECONSTRUCTION FOR PPAC1 && PPAC2
  // t1->Draw("TARA1A2_Y:TARA1A2_X>>a(300.,-50.,50.,300,-50.,50.)","","colz");
   //t1->Draw("TARA2A3_Y:TARA2A3_X>>a(300.,-50.,50.,300,-50.,50.)","","colz");
 
    
   //t1->Draw("PPAC1_X_C:PPAC1_Y_C>>a(400.,-150.,150.,400,-150.,150.)","","colz");
  
  //t1->Draw("PPAC1_A:PPAC2_A>>a(400.,15500.,28000.,400,15500.,28000.)","  PPAC3_A<18000","colz");// pillar ATS
  //In a(x1,x2,x3,y1,y2,y3) the 1 is the number of bins and the 2,3 the limit of the axis (for x and y)
  

    


 
 
}

