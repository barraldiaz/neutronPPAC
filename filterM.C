#include <stdlib.h>
#include <stdio.h>
//#include <sstream.h>
#include "TChain.h"
#include "TFile.h"


TChain *t1;
Int_t T;
Int_t Ta;



void filterM()
{

  T = 0;



  UShort_t PPAC2_A, PPAC1_A, PPAC3_A ;
  Float_t  PPAC2_X_C, PPAC2_Y_C, PPAC3_X_C, PPAC3_Y_C ,PPAC1_X_C, PPAC1_Y_C ;
  TCanvas *c1 = new TCanvas();
  c1->SetLogz();
  t1 =new TChain("RD");

  char name_data[70];

    char name_save[90];

    for(Int_t i = 0; i<2; i++)
                    { 
                          
                             
                                        sprintf(name_data, "/media/angel/TOSHIBA EXT/TFG/clean_ats/r0116_00%ir_ats.root", i);
                                        sprintf(name_save, "/media/angel/TOSHIBA EXT/TFG/filtered_data/individual/r0116_00%ir_tar1.root", i);
                                        
                                        cout << "File processing : " << name_data << endl;
                                        cout << "Saving in  : " << name_save << endl;

                                      TFile *newfile = new TFile(name_save,"RECREATE");

                                  //  for(Int_t i=93;i<=93;i++)
                                 
                                  //for(Int_t i=112;i<=192;i++)
                                  //{ 
                                  //  if(i!=138 && i!=147 && i!=155 && i!=159 && i!=166 && (i<171 || i>175) && i!=179 && i!=184)
                                  //{
	                                  //  sprintf(name,"../anvroot/run112-119_anv_nrand.root");
                                // 	   cout << "Adding " << name << endl;

                                       t1->Add(name_data);
                                     
                                        
	                                   Ta = (Int_t) (t1->GetEntries());
	                                   cout << "Entries " << Ta/1000 << "k "  << endl;
	                                   //}
	                                   //}
	                                   
                                        
                                     
                                      
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
                                      

                                       
                                      TFile *f = new TFile("cuts/generalCuts/cutA1A2_general.root","read"); //Archivo con cortess
                                      TCutG *CUT = (TCutG*)f->Get("cut_general");//definimos cortes
                                      CUT->Draw();

                                      int count = 0 ;

                                      for(Int_t i=0; i<Ta; i++)
                                        {
                                          t1->GetEntry(i); //Pillamos todos los datos de la entrada iesima
                                          
                                          if(CUT->IsInside(PPAC1_A,PPAC2_A))//nombre del cut gráfico en ox "filtro grafico y potencia"
	                                    {
                                            if(PPAC2_X_C<100 && PPAC2_Y_C<100 && PPAC2_X_C>-100 && PPAC2_Y_C>-100 &&
                                            PPAC1_X_C<103 && PPAC1_Y_C<100 && PPAC1_X_C>-103 && PPAC1_Y_C>-100 )//Filtro de limites de PPAC 
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





        




}
