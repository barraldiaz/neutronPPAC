#include <stdlib.h>
#include <stdio.h>
//#include <stream.h>
#include "TChain.h"
#include "TFile.h"



void ats_plots()

{
	
char name_data[40];

char name_save[40];

 for(Int_t i = 0; i<2; i++)
        {

        sprintf(name_data, "/media/angel/TOSHIBA EXT/TFG/clean_ats/r0117_00%ir_ats.root", i);
        sprintf(name_save, "ATS/r0117_00%ir.eps", i);

        TCanvas *c1 = new TCanvas("","",1300,800);

        c1->Divide(1,3);

        //=============================================================================================================
        //PLOT FOR PPAC1
        //=============================================================================================================


        TFile *f1 = new TFile(name_data,"read");
        TTree *t1=(TTree *)gDirectory->Get("RD");

        c1->cd(1);

        t1->Draw("ATS1>>h(8000,0,8000) ","PPAC1_ATS>=0 && PPAC1_A>20000");

         


        //=============================================================================================================
        //PLOT FOR PPAC2
        //=============================================================================================================


        TFile *f2 = new TFile(name_data,"read");
        TTree *t2=(TTree *)gDirectory->Get("RD");

        c1->cd(2);

        t2->Draw("ATS2>>h(8000,0,8000) ","PPAC2_ATS>=0 && PPAC2_A>20000");


        //=============================================================================================================
        //PLOT FOR PPAC3
        //=============================================================================================================

        TFile *f3 = new TFile(name_data,"read");
        TTree *t3=(TTree *)gDirectory->Get("RD");

        c1->cd(3);

        t3->Draw("ATS3>>h(8000,0,8000) ","PPAC3_ATS>=0 && PPAC3_A>20000");



        c1->Print(name_save);

    }

}
