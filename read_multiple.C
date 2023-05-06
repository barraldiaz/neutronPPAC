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



TChain *t1;

void read_multiple()
{


	TCanvas *c = new TCanvas();
	c->SetLogz();
	
	t1 = new TChain("RD");
	
	  UShort_t PPAC2_A, PPAC1_A , PPAC3_A;
	 Float_t PPAC1_X_C,PPAC2_X_C,PPAC1_Y_C,PPAC2_Y_C ,PPAC3_X_C, PPAC3_Y_C;
	
	  t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_000r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_001r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_002r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_003r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_004r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_005r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_006r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_007r.root"); 
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_008r.root"); 
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_009r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_010r.root"); 
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0115_011r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0114_000r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0114_001r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0114_002r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0114_003r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0114_004r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0114_005r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0114_006r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0114_007r.root"); 
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0114_008r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0116_000r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0117_000r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0118_000r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0118_001r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0118_002r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0118_003r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0118_004r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0118_005r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0118_006r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0118_007r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0118_008r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0119_000r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0120_000r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0121_000r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0121_001r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0122_000r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0122_001r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0122_002r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0122_003r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0122_004r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0123_000r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0123_001r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0123_002r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0123_003r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0123_004r.root");
       t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0123_005r.root");

        //We call the branches needed
    t1->SetBranchAddress("PPAC1_X_C",&PPAC1_X_C);
    t1->SetBranchAddress("PPAC2_X_C",&PPAC2_X_C); 
    t1->SetBranchAddress("PPAC1_Y_C",&PPAC1_Y_C);
    t1->SetBranchAddress("PPAC2_Y_C",&PPAC2_Y_C); 
    t1->SetBranchAddress("PPAC3_Y_C",&PPAC3_Y_C);
    t1->SetBranchAddress("PPAC3_Y_C",&PPAC3_Y_C); 

	 // t1->SetBranchAddress("PPAC2_A",&PPAC2_A);
     //t1->SetBranchAddress("PPAC1_A",&PPAC1_A); 
//   t1->SetBranchAddress("PPAC3_A",&PPAC3_A); 
	


    //t1->Draw("PPAC2_X_C:PPAC2_Y_C","","colz");
	//t1->Draw("PPAC1_A:PPAC2_A>>a(500.,15500.,28000.,500,15500.,28000.)","","colz");
    //t1->Draw("(PPAC1_ATS-3483454993153)*1E-8>>h(320000,0,320000)","","PPAC1_ATS>0 && PPAC1_A>20000");
    //t1->Draw("PPAC2_Y_C>>h(90,100,100)","","");
    t1->Draw("PPAC1_Y_C:PPAC1_X_C>>a(400.,-150.,150.,400,-150.,150.)","","colz");







}
