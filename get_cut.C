 
 
 void get_cut()
 {
 
 TTree *t1=(TTree *)gDirectory->Get("RD");
 t1->Draw("PPAC1_A:PPAC2_A>>a(250.,15500.,28000.,250,15500.,28000.)","cut_r0115","colz");
 TFile *f2=new TFile("cutA1A2_r0115.root","recreate");
 cut_r0115->Draw();
 //cut_r0115->Write();

 t1->Draw("PPAC_TAR1_X:PPAC_TAR2_Y>>a(100.,-100.,100.,100,-100.,100.)","cut_r0115","colz");
  
 }
