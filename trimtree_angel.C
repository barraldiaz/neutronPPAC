#include <stdlib.h>
#include <stdio.h>
//#include <stream.h>
#include "TChain.h"
#include "TFile.h"


TChain *t1;
Int_t T;
Int_t Ta;



void trimtree_angel()
{


  
  T = 0;

  char name[40];


  Float_t PPAC1_X_C,PPAC2_X_C,PPAC1_Y_C,PPAC2_Y_C, tar_x, tar_y, PPAC3_X_C,PPAC3_Y_C;

  t1 =new TChain("RD");
  
  TFile *newfile = new TFile("/media/angel/TOSHIBA EXT/TFG/rec_target/targetA1A2_any.root","recreate");
	//TFile *newfile = new TFile("TEST/targetA1A2_m2.root","recreate");

   //Esta parte es para si tenemos que meter varios archivos, en nuesrtro caso solo es uno
 
   //for(Int_t i=114;i<123;i++)
   //  {
   //dummy files (not needed)
   //   if(i!=566 && i!=570 && i!=571 && i!=597 && i!=615)
   //{
   //  {for Intt i = i=114}
   // sprintf(name,"../RootR/r0%i_001r.root",i);
   // cout << "Adding " << name << endl;
   //t1->Add(name);

   //Aquí añadimos el archivo con nuestros datos	   
        t1->Add("/media/angel/TOSHIBA EXT/TFG/filtered_data/runA1A2_all_any.root");
        //t1->Add("filtered_data/runA1A2_all.root");
        Ta = (Int_t) (t1->GetEntries());
	   cout << "Entries " << Ta/1000 << "k "  << endl;
	   
	 //}
     //}
    //We call the branches needed
    t1->SetBranchAddress("PPAC1_X_C",&PPAC1_X_C);
    t1->SetBranchAddress("PPAC2_X_C",&PPAC2_X_C); 
    t1->SetBranchAddress("PPAC1_Y_C",&PPAC1_Y_C);
    t1->SetBranchAddress("PPAC2_Y_C",&PPAC2_Y_C); 
    t1->SetBranchAddress("PPAC3_Y_C",&PPAC3_Y_C);
    t1->SetBranchAddress("PPAC3_Y_C",&PPAC3_Y_C); 


   TTree *newtree = t1->CloneTree(0);
   //Novas Branches TARX e TARY sobre newtree. 

    //TBranch *TAR_X = newtree->Branch("TARA2A3_X", &tar_x,"TARA2A3_X");
    //TBranch *TAR_Y = newtree->Branch("TARA2A3_Y", &tar_y,"TARA2A3_Y");
     TBranch *TAR_X = newtree->Branch("TARA1A2_X", &tar_x,"TARA1A2_X");
    TBranch *TAR_Y = newtree->Branch("TARA1A2_Y", &tar_y,"TARA1A2_Y");
   

   for(Int_t i=0; i<Ta; i++)
     {

     t1->GetEntry(i);
       
     


      
        //Target reconstruction aqui

       //tar_x = ( PPAC2_X_C + PPAC3_X_C - 1 )/2;
       //tar_y = ( PPAC2_Y_C + PPAC3_Y_C )/2;
       tar_x = ( PPAC1_X_C - 2 + PPAC2_X_C )/2;
       tar_y = ( PPAC1_Y_C + PPAC2_Y_C )/2;
       
       
       newtree->Fill(); 
	      
	 
       
       if((i+1)%1000 == 0||i%(Ta-1) == 0)
	 { 
	   cout <<"\rProcessing: Events: " << Ta << ", Done: " << (i+1) <<  ", (%): " << ((float) (i+1))/((float) Ta)*100.;
	   cout.flush();
	 }
     
     }
   
      
    newtree->Print();
    newtree->AutoSave();
    
    delete newfile;
 
}
