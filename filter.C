#include <stdlib.h>
#include <stdio.h>
//#include <sstream.h>
#include "TChain.h"
#include "TFile.h"


TChain *t1;
Int_t T;
Int_t Ta;

void filter()
{

  T = 0;

  char name[50];

  UShort_t PPAC2_A, PPAC1_A, PPAC3_A ;
  Float_t  PPAC2_X_C, PPAC2_Y_C, PPAC3_X_C, PPAC3_Y_C ,PPAC1_X_C, PPAC1_Y_C ;
  TCanvas *c1 = new TCanvas();
  c1->SetLogz();
  t1 =new TChain("RD");


            TFile *newfile = new TFile("/media/angel/TOSHIBA EXT/TFG/filtered_data/runA2A3_processed.root","RECREATE");

              //  for(Int_t i=93;i<=93;i++)
             
              //for(Int_t i=112;i<=192;i++)
              //{ 
              //  if(i!=138 && i!=147 && i!=155 && i!=159 && i!=166 && (i<171 || i>175) && i!=179 && i!=184)
              //{
	              //  sprintf(name,"../anvroot/run112-119_anv_nrand.root");
            // 	   cout << "Adding " << name << endl;

                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_000r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_001r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_002r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_003r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_004r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_005r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_006r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_007r_ats.root"); 
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_008r_ats.root"); 
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_009r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_010r_ats.root"); 
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0115_011r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0114_000r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0114_001r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0114_002r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0114_003r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0114_004r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0114_005r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0114_006r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0114_007r_ats.root"); 
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0114_008r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0116_000r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0116_001r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0117_000r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0118_000r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0118_001r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0118_002r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0118_003r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0118_004r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0118_005r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0118_006r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0118_007r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0118_008r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0120_000r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0122_000r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0122_001r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0122_002r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0122_003r_ats.root");
                   t1->Add("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0122_004r_ats.root");
                 
                    
	               Ta = (Int_t) (t1->GetEntries());
	               cout << "Entries " << Ta/1000 << "k "  << endl;
	               //}
	               //}
	               
                
             
              //t1->SetBranchAddress("PPAC3_A",&tiara_mult); // 
              t1->SetBranchAddress("PPAC2_A",&PPAC2_A);
              t1->SetBranchAddress("PPAC1_A",&PPAC1_A); 
              t1->SetBranchAddress("PPAC3_A",&PPAC3_A); 
              t1->SetBranchAddress("PPAC2_X_C",&PPAC2_X_C);
              t1->SetBranchAddress("PPAC2_Y_C",&PPAC2_Y_C); 
              t1->SetBranchAddress("PPAC3_Y_C",&PPAC3_Y_C); 
              t1->SetBranchAddress("PPAC3_X_C",&PPAC3_X_C);
              t1->SetBranchAddress("PPAC1_X_C",&PPAC1_X_C); 
              t1->SetBranchAddress("PPAC1_Y_C",&PPAC1_Y_C); 
              
                TTree *newtree = t1->CloneTree(0); 
              

               
              TFile *f = new TFile("cuts/generalCuts/cutA2A3_general.root","read"); //Archivo con cortess
              TCutG *CUT = (TCutG*)f->Get("cut_general");//definimos cortes
              CUT->Draw();

              int count = 0 ;

              for(Int_t i=0; i<Ta; i++)
                {
                  t1->GetEntry(i); //Pillamos todos los datos de la entrada iesima
                  
                  if(CUT->IsInside(PPAC2_A,PPAC3_A))//nombre del cut gráfico en ox "filtro grafico y potencia"
	            {
                    if(PPAC2_X_C<100 && PPAC2_Y_C<100 && PPAC2_X_C>-100 && PPAC2_Y_C>-100 &&
                    PPAC3_X_C<103 && PPAC3_Y_C<100 && PPAC3_X_C>-103 && PPAC3_Y_C>-100 )//Filtro de limites de PPAC 
                        {
	                    newtree->Fill(); count++;    
	                    }
	              
	            }
                  if((i+1)%1000 == 0||i%(Ta-1) == 0)
	            { 
	              cout <<"\rProcessing: Events: " << Ta << ", Done: " << (i+1) << ", (%): " << ((float) (i+1))/((float) Ta)*100.;
	                cout.flush();
	              }
	            
                }
               
                newtree->Print();
                newtree->AutoSave();
                
                delete newfile;
           
}
