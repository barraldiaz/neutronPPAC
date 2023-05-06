#include <stdlib.h>
#include <stdio.h>
//#include <stream.h>
#include "TChain.h"
#include "TFile.h"


Int_t T, Ta; 
TChain *t1;





void ats_mod()

{


T = 0;


ULong64_t PPAC1_ATS, PPAC2_ATS, PPAC3_ATS;

Float_t ATS1, ATS2, ATS3;
Float_t ats1, ats2, ats3;

char name_data[40];
char name_save[40];


    for(Int_t i = 0; i<1; i++)
        {
            t1 =new TChain("RD");
            sprintf(name_data, "/media/angel/TOSHIBA EXT/TFG/raw_data/r0117_00%ir.root", i);
            cout << "Adding " << name_data << endl;
            t1->Add(name_data);

            sprintf(name_save, "/media/angel/TOSHIBA EXT/TFG/clean_ats/r0117_00%ir_ats.root", i);
            cout << "Saving in  " << name_save << endl;
            TFile *newfile = new TFile(name_save,"recreate");
            

        
            



            //TFile *newfile = new TFile("/media/angel/TOSHIBA EXT/TFG/clean_ats/r0114_001_ats.root","recreate");

            //t1->Add("/media/angel/TOSHIBA EXT/TFG/raw_data/r0114_001r.root");


            Ta = (Int_t) (t1->GetEntries());
            cout << "Entries " << Ta/1000 << "k "  << endl;


            t1->SetBranchAddress("PPAC3_ATS",&PPAC3_ATS);
            t1->SetBranchAddress("PPAC2_ATS",&PPAC2_ATS); 
            t1->SetBranchAddress("PPAC1_ATS",&PPAC1_ATS);


            TTree *newtree = t1->CloneTree(0);

            TBranch *ATS_1 = newtree->Branch("ATS1", &ATS1,"ATS1");
            TBranch *ATS_2 = newtree->Branch("ATS2", &ATS2,"ATS2");
            TBranch *ATS_3 = newtree->Branch("ATS3", &ATS3, "ATS3");
            
         

            for(Int_t j=0; j<Ta; j++)
                {
                t1->GetEntry(j);

                if( PPAC1_ATS >1  )
                    {
                    ats1 = PPAC1_ATS;
                    cout << "value of PPAC1_ATS = " << ats1 << endl;
                    
                    break;
                    }
                }
            for(Int_t j=0; j<Ta; j++)
                {
                t1->GetEntry(j);

                if( PPAC2_ATS > 1  )
                    {
                    ats2 = PPAC2_ATS;
                    cout << "value of PPAC2_ATS = " << ats2 << endl;
                    
                    break;
                    }
                }
            for(Int_t j=0; j<Ta; j++)
                {
                t1->GetEntry(j);

                if( PPAC3_ATS >1  )
                    {
                    ats3 = PPAC3_ATS;
                    cout << "value of PPAC3_ATS = " << ats3 << endl ;
                  
                    break;
                    }
                }
                
                


            for(Int_t i=0; i<Ta ; i++)
                {
                
                t1->GetEntry(i);
                
                ATS1=(PPAC1_ATS-ats1)*1e-8;
                ATS2=(PPAC2_ATS-ats2)*1e-8;
                ATS3=(PPAC3_ATS-ats3)*1e-8;
                
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






}
