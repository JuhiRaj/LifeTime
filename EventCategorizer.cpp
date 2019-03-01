/**
 *  @copyright Copyright 2017 The J-PET Framework Authors. All rights reserved.
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may find a copy of the License in the LICENCE file.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *  @file EventCategorizer.cpp
 */

#include <iostream> 
#include <JPetWriter/JPetWriter.h> 
#include "EventCategorizer.h"

using namespace std;

EventCategorizer::EventCategorizer(const char * name): JPetUserTask(name) {}

bool EventCategorizer::init() {

  INFO("Event categorization started.");
  INFO("Looking at two hit Events on Layer 1&2 only - creating only control histograms");

  fOutputEvents = new JPetTimeWindow("JPetEvent");

  if (fSaveControlHistos) {

    //Control Spectra

    getStatistics().createHistogram(new TH1F("Hits_All", "Hit Multiplicity",
      11, -0.5, 10.5));
    getStatistics().getHisto1D("Hits_All")->GetXaxis()->SetTitle("Hit Multiplicity");
    getStatistics().getHisto1D("Hits_All")->GetYaxis()->SetTitle("Counts");


    getStatistics().createHistogram(new TH1F("Hits", "Hit Multiplicity - 4 Hits",
      11, -0.5, 10.5));
    getStatistics().getHisto1D("Hits")->GetXaxis()->SetTitle("Event Multiplicity - 4 Hits");
    getStatistics().getHisto1D("Hits")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("TOT_All", "TOT_All",
      101, -0.5, 100.5));
    getStatistics().getHisto1D("TOT_All")->GetXaxis()->SetTitle("TOT_All [ns]");
    getStatistics().getHisto1D("TOT_All")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("TOT_Deex", "TOT_Deex",
      101, -0.5, 100.5));
    getStatistics().getHisto1D("TOT_Deex")->GetXaxis()->SetTitle("TOT_Deex [ns]");
    getStatistics().getHisto1D("TOT_Deex")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("TOT_Anni", "TOT_Anni",
      101, -0.5, 100.5));
    getStatistics().getHisto1D("TOT_Anni")->GetXaxis()->SetTitle("TOT_Anni [ns]");
    getStatistics().getHisto1D("TOT_Anni")->GetYaxis()->SetTitle("Counts");

    /*getStatistics().createHistogram(new TH1F("TOT_Scat", "TOT_Scat",
      101, -0.5, 100.5));
    getStatistics().getHisto1D("TOT_Scat")->GetXaxis()->SetTitle("TOT_Scat [ns]");
    getStatistics().getHisto1D("TOT_Scat")->GetYaxis()->SetTitle("Counts");
*/
    getStatistics().createHistogram(new TH1F("Z_Pos_Before", "Z_Pos_Before",
      101, -50.5, 50.5));
    getStatistics().getHisto1D("Z_Pos_Before")->GetXaxis()->SetTitle("Z Pos Before [cm]");
    getStatistics().getHisto1D("Z_Pos_Before")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("Z_Pos_After", "Z_Pos_After",
      101, -50.5, 50.5));
    getStatistics().getHisto1D("Z_Pos_After")->GetXaxis()->SetTitle("Z Pos After [cm]");
    getStatistics().getHisto1D("Z_Pos_After")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("ScinID", "Scintillator ID Distribution",
      193, -0.5, 192.5));
    getStatistics().getHisto1D("ScinID")->GetXaxis()->SetTitle("Scintillator ID");
    getStatistics().getHisto1D("ScinID")->GetYaxis()->SetTitle("Counts");
 
    getStatistics().createHistogram(new TH1F("ScinID_Check", "Scintillator ID Distribution",
      193, -0.5, 192.5));
    getStatistics().getHisto1D("ScinID_Check")->GetXaxis()->SetTitle("Scintillator ID");
    getStatistics().getHisto1D("ScinID_Check")->GetYaxis()->SetTitle("Counts");


    getStatistics().createHistogram(new TH1F("ScinID_Replica", "ScinID_Replica",
      11, -0.5, 10.5));
    getStatistics().getHisto1D("ScinID_Replica")->GetXaxis()->SetTitle("ScinID_Replica");
    getStatistics().getHisto1D("ScinID_Replica")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("ScinID_Replica_Cut", "ScinID_Replica_Cut",
      11, -0.5, 10.5));
    getStatistics().getHisto1D("ScinID_Replica_Cut")->GetXaxis()->SetTitle("ScinID_Replica_Cut");
    getStatistics().getHisto1D("ScinID_Replica_Cut")->GetYaxis()->SetTitle("Counts");


    getStatistics().createHistogram(new TH1F("Delta_ij_all", "#Delta_{ij} - All",
      40100, -200.5, 200.5));
    getStatistics().getHisto1D("Delta_ij_all")->GetXaxis()->SetTitle("#Delta_{ij} - All [ns]");
    getStatistics().getHisto1D("Delta_ij_all")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("Delta_ij_least", "#Delta_{ij} - Least",
      40100, -200.5, 200.5));
    getStatistics().getHisto1D("Delta_ij_least")->GetXaxis()->SetTitle("#Delta_{ij} - Least [ns]");
    getStatistics().getHisto1D("Delta_ij_least")->GetYaxis()->SetTitle("Counts");










    getStatistics().createHistogram(new TH1F("DistancefromSurface", "DistancefromSurface",
      510, -0.5, 50.5));
    getStatistics().getHisto1D("DistancefromSurface")->GetXaxis()->SetTitle("DistancefromSurface [cm]");
    getStatistics().getHisto1D("DistancefromSurface")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("DistancefromSurface_less3", "DistancefromSurface_less3",
      510, -0.5, 50.5));
    getStatistics().getHisto1D("DistancefromSurface_less3")->GetXaxis()->SetTitle("DistancefromSurface_less3 [cm]");
    getStatistics().getHisto1D("DistancefromSurface_less3")->GetYaxis()->SetTitle("Counts");


    getStatistics().createHistogram(new TH1F("TOF_Difference_avrg", "TOF_Difference_avrg",
      20600, -5.5, 200.5));
    getStatistics().getHisto1D("TOF_Difference_avrg")->GetXaxis()->SetTitle("TOF_Difference_avrg [ns]");
    getStatistics().getHisto1D("TOF_Difference_avrg")->GetYaxis()->SetTitle("Counts");


    getStatistics().createHistogram(new TH1F("TOF_Difference_avrg_Cut_2ns", "TOF_Difference_avrg_Cut_2ns",
      20600, -5.5, 200.5));
    getStatistics().getHisto1D("TOF_Difference_avrg_Cut_2ns")->GetXaxis()->SetTitle("TOF_Difference_avrg_Cut_2ns [ns]");
    getStatistics().getHisto1D("TOF_Difference_avrg_Cut_2ns")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH2F("Angle3D", "3D Azimuthal Angles (Sum and Difference of the two smallest)", 251, -0.5, 250.5, 251, -0.5, 250.5));
    getStatistics().getHisto2D("Angle3D")->GetXaxis()->SetTitle("#Theta_1 + #Theta_0");
    getStatistics().getHisto2D("Angle3D")->GetYaxis()->SetTitle("#Theta_1 - #Theta_0");

    getStatistics().createHistogram(new TH2F("Angle3D_190", "3D Azimuthal Angles (Greater than 190deg)", 251, -0.5, 250.5, 251, -0.5, 250.5));
    getStatistics().getHisto2D("Angle3D_190")->GetXaxis()->SetTitle("#Theta_{1} + #Theta_{0}");
    getStatistics().getHisto2D("Angle3D_190")->GetYaxis()->SetTitle("#Theta_{1} - #Theta_{0}");

    getStatistics().createHistogram(new TH1F("ScinID_After", "Scintillator ID Distribution - After",
      193, -0.5, 192.5));
    getStatistics().getHisto1D("ScinID_After")->GetXaxis()->SetTitle("Scintillator ID");
    getStatistics().getHisto1D("ScinID_After")->GetYaxis()->SetTitle("Counts");


    getStatistics().createHistogram(new TH1F("LifeTime_Before", "LifeTime_Before", 40100, -200.5, 200.5));
    getStatistics().getHisto1D("LifeTime_Before")->SetXTitle("LifeTime_Before [ns]");
    getStatistics().getHisto1D("LifeTime_Before")->SetYTitle("Counts");

    getStatistics().createHistogram(new TH1F("LifeTime", "LifeTime", 40100, -200.5, 200.5));
    getStatistics().getHisto1D("LifeTime")->SetXTitle("LifeTime [ns]");
    getStatistics().getHisto1D("LifeTime")->SetYTitle("Counts");
    

    getStatistics().createHistogram(new TH1F("LifeTime_Check1", "LifeTime_Check1", 40100, -200.5, 200.5));
    getStatistics().getHisto1D("LifeTime_Check1")->SetXTitle("LifeTime_Check1 [ns]");
    getStatistics().getHisto1D("LifeTime_Check1")->SetYTitle("Counts");
 
     getStatistics().createHistogram(new TH2F("Angle3D_Check1", "3D Azimuthal Angles (Sum and Difference of the two smallest)", 251, -0.5, 250.5, 251, -0.5, 250.5));
    getStatistics().getHisto2D("Angle3D_Check1")->GetXaxis()->SetTitle("#Theta_1 + #Theta_0");
    getStatistics().getHisto2D("Angle3D_Check1")->GetYaxis()->SetTitle("#Theta_1 - #Theta_0");


 getStatistics().createHistogram(new TH1F("LifeTime_Check2", "LifeTime_Check2", 40100, -200.5, 200.5));
    getStatistics().getHisto1D("LifeTime_Check2")->SetXTitle("LifeTime_Check2 [ns]");
    getStatistics().getHisto1D("LifeTime_Check2")->SetYTitle("Counts");

 getStatistics().createHistogram(new TH2F("Angle3D_Check2", "3D Azimuthal Angles (Sum and Difference of the two smallest)", 251, -0.5, 250.5, 251, -0.5, 250.5));
    getStatistics().getHisto2D("Angle3D_Check2")->GetXaxis()->SetTitle("#Theta_1 + #Theta_0");
    getStatistics().getHisto2D("Angle3D_Check2")->GetYaxis()->SetTitle("#Theta_1 - #Theta_0");   


 getStatistics().createHistogram(new TH1F("LifeTime_Check3", "LifeTime_Check3", 40100, -200.5, 200.5));
    getStatistics().getHisto1D("LifeTime_Check3")->SetXTitle("LifeTime_Check3 [ns]");
    getStatistics().getHisto1D("LifeTime_Check3")->SetYTitle("Counts");
    
 getStatistics().createHistogram(new TH2F("Angle3D_Check3", "3D Azimuthal Angles (Sum and Difference of the two smallest)", 251, -0.5, 250.5, 251, -0.5, 250.5));
    getStatistics().getHisto2D("Angle3D_Check3")->GetXaxis()->SetTitle("#Theta_1 + #Theta_0");
    getStatistics().getHisto2D("Angle3D_Check3")->GetYaxis()->SetTitle("#Theta_1 - #Theta_0");



 getStatistics().createHistogram(new TH1F("LifeTime_Check4", "LifeTime_Check4", 40100, -200.5, 200.5));
    getStatistics().getHisto1D("LifeTime_Check4")->SetXTitle("LifeTime_Check4 [ns]");
    getStatistics().getHisto1D("LifeTime_Check4")->SetYTitle("Counts");
    
 getStatistics().createHistogram(new TH2F("Angle3D_Check4", "3D Azimuthal Angles (Sum and Difference of the two smallest)", 251, -0.5, 250.5, 251, -0.5, 250.5));
    getStatistics().getHisto2D("Angle3D_Check4")->GetXaxis()->SetTitle("#Theta_1 + #Theta_0");
    getStatistics().getHisto2D("Angle3D_Check4")->GetYaxis()->SetTitle("#Theta_1 - #Theta_0");



 getStatistics().createHistogram(new TH1F("LifeTime_Check5", "LifeTime_Check5", 40100, -200.5, 200.5));
    getStatistics().getHisto1D("LifeTime_Check5")->SetXTitle("LifeTime_Check5 [ns]");
    getStatistics().getHisto1D("LifeTime_Check5")->SetYTitle("Counts");
    
 getStatistics().createHistogram(new TH2F("Angle3D_Check5", "3D Azimuthal Angles (Sum and Difference of the two smallest)", 251, -0.5, 250.5, 251, -0.5, 250.5));
    getStatistics().getHisto2D("Angle3D_Check5")->GetXaxis()->SetTitle("#Theta_1 + #Theta_0");
    getStatistics().getHisto2D("Angle3D_Check5")->GetYaxis()->SetTitle("#Theta_1 - #Theta_0");


 getStatistics().createHistogram(new TH1F("LifeTime_Check6", "LifeTime_Check6", 40100, -200.5, 200.5));
    getStatistics().getHisto1D("LifeTime_Check6")->SetXTitle("LifeTime_Check6 [ns]");
    getStatistics().getHisto1D("LifeTime_Check6")->SetYTitle("Counts");
    
 getStatistics().createHistogram(new TH2F("Angle3D_Check6", "3D Azimuthal Angles (Sum and Difference of the two smallest)", 251, -0.5, 250.5, 251, -0.5, 250.5));
    getStatistics().getHisto2D("Angle3D_Check6")->GetXaxis()->SetTitle("#Theta_1 + #Theta_0");
    getStatistics().getHisto2D("Angle3D_Check6")->GetYaxis()->SetTitle("#Theta_1 - #Theta_0");


    getStatistics().createHistogram(new TH1F("LifeTime_Check7", "LifeTime_Check7", 40100, -200.5, 200.5));
    getStatistics().getHisto1D("LifeTime_Check7")->SetXTitle("LifeTime_Check7 [ns]");
    getStatistics().getHisto1D("LifeTime_Check7")->SetYTitle("Counts");
    
    getStatistics().createHistogram(new TH2F("Angle3D_Check7", "3D Azimuthal Angles (Sum and Difference of the two smallest)", 251, -0.5, 250.5, 251, -0.5, 250.5));
    getStatistics().getHisto2D("Angle3D_Check7")->GetXaxis()->SetTitle("#Theta_1 + #Theta_0");
    getStatistics().getHisto2D("Angle3D_Check7")->GetYaxis()->SetTitle("#Theta_1 - #Theta_0");


    getStatistics().createHistogram(new TH1F("LifeTime_Check8", "LifeTime_Check8", 40100, -200.5, 200.5));
    getStatistics().getHisto1D("LifeTime_Check8")->SetXTitle("LifeTime_Check8 [ns]");
    getStatistics().getHisto1D("LifeTime_Check8")->SetYTitle("Counts");
    
    getStatistics().createHistogram(new TH2F("Angle3D_Check8", "3D Azimuthal Angles (Sum and Difference of the two smallest)", 251, -0.5, 250.5, 251, -0.5, 250.5));
    getStatistics().getHisto2D("Angle3D_Check8")->GetXaxis()->SetTitle("#Theta_1 + #Theta_0");
    getStatistics().getHisto2D("Angle3D_Check8")->GetYaxis()->SetTitle("#Theta_1 - #Theta_0");



   getStatistics().createHistogram(new TH2F("Dalitz_Energy_12", "Dalitz_Energy_12", 1041, -0.5, 1040.5, 1041, -0.5, 1040.5));
    getStatistics().getHisto2D("Dalitz_Energy_12")->GetXaxis()->SetTitle("Energy1");
    getStatistics().getHisto2D("Dalitz_Energy_12")->GetYaxis()->SetTitle("Energy2");

    getStatistics().createHistogram(new TH2F("Dalitz_Energy_23", "Dalitz_Energy_23", 1041, -0.5, 1040.5, 1041, -0.5, 1040.5));
    getStatistics().getHisto2D("Dalitz_Energy_23")->GetXaxis()->SetTitle("Energy2");
    getStatistics().getHisto2D("Dalitz_Energy_23")->GetYaxis()->SetTitle("Energy3");

    getStatistics().createHistogram(new TH2F("Dalitz_Energy_31", "Dalitz_Energy_31", 1041, -0.5, 1040.5, 1041, -0.5, 1040.5));
    getStatistics().getHisto2D("Dalitz_Energy_31")->GetXaxis()->SetTitle("Energy3");
    getStatistics().getHisto2D("Dalitz_Energy_31")->GetYaxis()->SetTitle("Energy1");


 getStatistics().createHistogram(new TH1F("Energy1", "Energy1",
      3001, -1500.5, 1500.5));
    getStatistics().getHisto1D("Energy1")->GetXaxis()->SetTitle("Energy1 [keV]");
    getStatistics().getHisto1D("Energy1")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("Energy2", "Energy2",
      3001, -1500.5, 1500.5));
    getStatistics().getHisto1D("Energy2")->GetXaxis()->SetTitle("Energy2 [keV]");
    getStatistics().getHisto1D("Energy2")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("Energy3", "Energy3",
      3001, -1500.5, 1500.5));
    getStatistics().getHisto1D("Energy3")->GetXaxis()->SetTitle("Energy3 [keV]");
    getStatistics().getHisto1D("Energy3")->GetYaxis()->SetTitle("Counts");



 //Expectation Value

    getStatistics().createHistogram(new TH1F("ExpecValue1", "ExpecValue1",
      300, -1.5, 1.5));
    getStatistics().getHisto1D("ExpecValue1")->GetXaxis()->SetTitle("ExpecValue1");
    getStatistics().getHisto1D("ExpecValue1")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("ExpecValue2", "ExpecValue2",
      300, -1.5, 1.5));
    getStatistics().getHisto1D("ExpecValue2")->GetXaxis()->SetTitle("ExpecValue2");
    getStatistics().getHisto1D("ExpecValue2")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("ExpecValue3", "ExpecValue3",
      300, -1.5, 1.5));
    getStatistics().getHisto1D("ExpecValue3")->GetXaxis()->SetTitle("ExpecValue3");
    getStatistics().getHisto1D("ExpecValue3")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("ExpecValue", "ExpecValue",
      300, -1.5, 1.5));
    getStatistics().getHisto1D("ExpecValue")->GetXaxis()->SetTitle("ExpecValue");
    getStatistics().getHisto1D("ExpecValue")->GetYaxis()->SetTitle("Counts");





  }

  return true;
}



Bool_t comparison(const pair < double, JPetHit > & a,
  const pair < double, JPetHit > & b) {
  return a.first < b.first;
}

Bool_t comparison3(const pair < double, pair < JPetHit, JPetHit >> & a,
  const pair < double, pair < JPetHit, JPetHit >> & b) {
  return abs(a.first) < abs(b.first);
}


bool EventCategorizer::exec() {

  //Begin of exec function

  if (auto timeWindow = dynamic_cast <
    const JPetTimeWindow *
      const > (fEvent)) {
    uint n = timeWindow->getNumberOfEvents();
    for (uint i = 0; i < n; ++i) {

	TVector3 Center(0.0, 0.0, 0.0);  //Center of the Geometry


      const auto & event = dynamic_cast <
        const JPetEvent & > (timeWindow->operator[](i));


	
      getStatistics().getHisto1D("Hits_All")->Fill(event.getHits().size());

      //This analysis requires only 4-Hits in a single event	    


	
      if (event.getHits().size() >= 5) {
 
      getStatistics().getHisto1D("Hits")->Fill(event.getHits().size()); 




      //Create vectors for different types of hits

	vector<JPetHit> hits = event.getHits();
	
	std::vector < JPetHit > AnniHits;
	std::vector < JPetHit > DeexHits;
	std::vector < JPetHit > ScatHits;



	//Check for the duplicate ID's


	std::vector < int > ID_vec;

	for (auto i = hits.begin(); i != hits.end(); ++i) 
	{
		auto& hit1 = *i;
        

	 auto ID = hit1.getScintillator().getID();
	 ID_vec.push_back( ID );
	

        getStatistics().getHisto1D("ScinID")->Fill(ID);


	}

	sort( ID_vec.begin(), ID_vec.end() );
	
	ID_vec.erase(unique(ID_vec.begin(), ID_vec.end()), ID_vec.end());

	getStatistics().getHisto1D("ScinID_Replica")->Fill(ID_vec.size());





	//No duplicate ID's only then enter 


	if(ID_vec.size() == event.getHits().size())
	{


	getStatistics().getHisto1D("ScinID_Replica_Cut")->Fill(ID_vec.size());


	//Z_Pos Check and Cut

	for (auto i = hits.begin(); i != hits.end(); ++i) 
	{
		auto& hit1 = *i;
        

	getStatistics().getHisto1D("Z_Pos_Before")->Fill(hit1.getPosZ());

	if(fabs( hit1.getPosZ()) <= 23)

	{ 

	getStatistics().getHisto1D("Z_Pos_After")->Fill(hit1.getPosZ());

	
	double TOT = CalcTOT( hit1 );
	getStatistics().getHisto1D("TOT_All")->Fill(TOT);



		if( TOT > 30 && TOT < 60  ) // Deexcitation TOT
		{
			DeexHits.push_back( hit1 );
			getStatistics().getHisto1D("TOT_Deex")->Fill(TOT);

		}


		else if( TOT > 1 && TOT < 25 ) // Annihilation TOT
		{
			AnniHits.push_back( hit1 );
			getStatistics().getHisto1D("TOT_Anni")->Fill(TOT);

		}	


	}



	}

	//5 or more Hits


	if( DeexHits.size() == 1 && AnniHits.size() == 4)
	{



//ID's of the 5-Hits

	  auto ID_Deex = DeexHits[0].getScintillator().getID();
          auto ID_Anni_1 = AnniHits[0].getScintillator().getID();
          auto ID_Anni_2 = AnniHits[1].getScintillator().getID();
          auto ID_Anni_3 = AnniHits[2].getScintillator().getID();
	  auto ID_Anni_4 = AnniHits[3].getScintillator().getID();

//Count Rate - ID's filling

	  getStatistics().getHisto1D("ScinID_Check")->Fill(ID_Deex);
          getStatistics().getHisto1D("ScinID_Check")->Fill(ID_Anni_1);
          getStatistics().getHisto1D("ScinID_Check")->Fill(ID_Anni_2);
          getStatistics().getHisto1D("ScinID_Check")->Fill(ID_Anni_3);
          getStatistics().getHisto1D("ScinID_Check")->Fill(ID_Anni_4);




	//Check for the Scatter Hit Possibility
	
	std::vector < pair < double, pair < JPetHit, JPetHit >>> Scat_vec;

	for (uint p = 0 ; p < AnniHits.size(); p++) 
	{
	
		//Loop over all hits - Assuming Primary 
	

		for (uint s = 0; s < AnniHits.size(); s++) 
		{
		
			

	if(AnniHits[p].getTime() < AnniHits[s].getTime()) //Perform Scatter Check only if S_t > P_t

			{
	
	

		double Scatij = CalScatterTest(AnniHits[p], AnniHits[s]);
		
		getStatistics().getHisto1D("Delta_ij_all")->Fill(Scatij);

		Scat_vec.push_back({Scatij, {AnniHits[p], AnniHits[s]}});	
		
	


			}
	
        	}

	
	}



	 std::sort(Scat_vec.begin(), Scat_vec.end(), comparison3); //Sort Scatij

	 getStatistics().getHisto1D("Delta_ij_least")->Fill(Scat_vec.at(0).first);

	 ScatHits.push_back(Scat_vec.at(0).second.second);


	//Seperating the probable scattered photon from the remaining Annihi hits

	for (uint k = 0 ; k < AnniHits.size(); k++) 
	{
	
	if(Scat_vec.at(0).second.second.getScintillator().getID() == AnniHits.at(k).getScintillator().getID())
		{

	
		AnniHits.erase(AnniHits.begin() + k);

		}

	}




	if(AnniHits.size() == 3 && ScatHits.size()== 1 && DeexHits.size() == 1)
	{




 double DistfromSurface = CalDistofSurface(AnniHits[0], AnniHits[1], AnniHits[2],  Center);


 getStatistics().getHisto1D("DistancefromSurface")->Fill(DistfromSurface);

                      if (DistfromSurface <= 3.0) {

 getStatistics().getHisto1D("DistancefromSurface_less3")->Fill(DistfromSurface);



  //Emission Time Average & Difference
  std::vector < double > TOF;
  TOF.push_back(CalcTOF(AnniHits[0], Center));
  TOF.push_back(CalcTOF(AnniHits[1], Center));
  TOF.push_back(CalcTOF(AnniHits[2], Center));


  std::sort(TOF.begin(), TOF.begin() + 3);

  double Scat_t1 = fabs(TOF[2] - TOF[0]);

  getStatistics().getHisto1D("TOF_Difference_avrg")->Fill(Scat_t1);

  

  if (Scat_t1 <= 2.0) {

      getStatistics().getHisto1D("TOF_Difference_avrg_Cut_2ns")->Fill(Scat_t1);


//3-D Angle Calculation

	 vector < pair < double, pair < JPetHit, JPetHit >>> Angle3D;
                    double Angle12 = Calc3DAngle(AnniHits[0], AnniHits[1], Center);
                    double Angle23 = Calc3DAngle(AnniHits[1], AnniHits[2], Center);
                    double Angle31 = Calc3DAngle(AnniHits[2], AnniHits[0], Center);
	            double AngleDiff = (360 - (Angle12 + Angle23));
                    Angle3D.push_back({
                      Angle12,
                      {
                        AnniHits[0],
                        AnniHits[1]
                      }
                    });
                    Angle3D.push_back({
                      Angle23,
                      {
                        AnniHits[1],
                        AnniHits[2]
                      }
                    });
                    Angle3D.push_back({
                      Angle31,
                      {
                        AnniHits[2],
                        AnniHits[0]
                      }
                    });

                    std::sort(Angle3D.begin(), Angle3D.end(), comparison3);

 getStatistics().getHisto2D("Angle3D")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);
			


	//LifeTime

	  double Avrg_ET = (TOF[2]+TOF[1]+TOF[0])/3 ;

	  double LifeTime = (Avrg_ET - CalcTOF(DeexHits[0], Center));
	  getStatistics().getHisto1D("LifeTime_Before")->Fill(LifeTime);
	
	if(LifeTime < -5.0)

	{


		getStatistics().getHisto1D("LifeTime_Check1")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check1")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);




	}


	else if(LifeTime > -5.0 && LifeTime < 5.0)


	{


		getStatistics().getHisto1D("LifeTime_Check2")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check2")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);


	}


	else if(LifeTime > 5.0)
	{


		getStatistics().getHisto1D("LifeTime_Check3")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check3")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);



	}


	else if(LifeTime > 10.0 && LifeTime < 100.0)
	{


		getStatistics().getHisto1D("LifeTime_Check4")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check4")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);



	}





//3-D Angle Calculation - 190 Cut

   if ((Angle3D.at(1).first + Angle3D.at(0).first) >= 190.0) {


 getStatistics().getHisto2D("Angle3D_190")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);




  	  getStatistics().getHisto1D("LifeTime")->Fill(LifeTime);
	  getStatistics().getHisto1D("ScinID_After")->Fill(ID_Deex);
          getStatistics().getHisto1D("ScinID_After")->Fill(ID_Anni_1);
          getStatistics().getHisto1D("ScinID_After")->Fill(ID_Anni_2);
          getStatistics().getHisto1D("ScinID_After")->Fill(ID_Anni_3);
          





	if(LifeTime < -5.0)

	{


		getStatistics().getHisto1D("LifeTime_Check5")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check5")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);




	}


	else if(LifeTime > -5.0 && LifeTime < 5.0)


	{

		getStatistics().getHisto1D("LifeTime_Check6")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check6")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);


	}


	else if(LifeTime > 5.0)
	{


	getStatistics().getHisto1D("LifeTime_Check7")->Fill(LifeTime);

 	getStatistics().getHisto2D("Angle3D_Check7")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);
	



	}


	else if(LifeTime > 10.0 && LifeTime < 100.0)
	{




	getStatistics().getHisto1D("LifeTime_Check8")->Fill(LifeTime);

 	getStatistics().getHisto2D("Angle3D_Check8")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);






	}





	

	if(LifeTime > 10.0)
	{
	
	



                    //Energy Calculations

                    double Energy1 = CalcEnergy1(Angle12, Angle23, AngleDiff);
                    double Energy2 = CalcEnergy2(Angle12, Angle23, AngleDiff);
                    double Energy3 = CalcEnergy3(Angle12, Angle23, AngleDiff);

       		    getStatistics().getHisto1D("Energy1")->Fill(Energy1);
                    getStatistics().getHisto1D("Energy2")->Fill(Energy2);
                    getStatistics().getHisto1D("Energy3")->Fill(Energy3);

	            getStatistics().getHisto2D("Dalitz_Energy_12")->Fill(Energy1, Energy2);
                    getStatistics().getHisto2D("Dalitz_Energy_23")->Fill(Energy2, Energy3);
                    getStatistics().getHisto2D("Dalitz_Energy_31")->Fill(Energy3, Energy1);

	


			
                    //Sorting of Calculated Energies   

		    vector <pair<double,JPetHit>> Energy_Vector;
                    Energy_Vector.push_back({Energy1, AnniHits[0]});
                    Energy_Vector.push_back({Energy2, AnniHits[1]});
                    Energy_Vector.push_back({Energy3, AnniHits[2]});
                    std::sort(Energy_Vector.begin(), Energy_Vector.end(), comparison);







        if (Scat_vec.at(0).second.first.getScintillator().getID() == Energy_Vector.at(2).second.getScintillator().getID()) {

                              double ExpecValue1 = CalExpecValue(Scat_vec.at(0).second.first, Scat_vec.at(0).second.second, Energy_Vector.at(1).second, Center);

               getStatistics().getHisto1D("ExpecValue1")->Fill(ExpecValue1);
            getStatistics().getHisto1D("ExpecValue")->Fill(ExpecValue1);

                            } else if (Scat_vec.at(0).second.first.getScintillator().getID() == Energy_Vector.at(1).second.getScintillator().getID()) {

                              double ExpecValue2 = CalExpecValue(Scat_vec.at(0).second.first, Scat_vec.at(0).second.second, Energy_Vector.at(2).second, Center);
            
	    getStatistics().getHisto1D("ExpecValue2")->Fill(ExpecValue2);
            getStatistics().getHisto1D("ExpecValue")->Fill(ExpecValue2);
                            
			   } else if (Scat_vec.at(0).second.first.getScintillator().getID() == Energy_Vector.at(0).second.getScintillator().getID()) {

                              double ExpecValue3 = CalExpecValue(Scat_vec.at(0).second.first, Scat_vec.at(0).second.second,Energy_Vector.at(2).second, Center);
                             
 	getStatistics().getHisto1D("ExpecValue3")->Fill(ExpecValue3);
 	getStatistics().getHisto1D("ExpecValue")->Fill(ExpecValue3);

					
							}










	











	}
	






						}


					}
				
				}

			}


		}


	}

	  DeexHits.clear();
	  AnniHits.clear();
	  ScatHits.clear();



					}
					
	
				}



			}


		




else {
  return false;
}
return true;


}

bool EventCategorizer::terminate() {

  INFO("More than one hit Events done. Writing conrtrol histograms.");
  return true;
}

void EventCategorizer::saveEvents(const vector < JPetEvent > & events) {
  for (const auto & event: events) {
    fOutputEvents->add < JPetEvent > (event);
  }
}
