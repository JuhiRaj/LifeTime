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

    getStatistics().createHistogram(new TH1F("ScinID_Replica", "ScinID_Replica",
      11, -0.5, 10.5));
    getStatistics().getHisto1D("ScinID_Replica")->GetXaxis()->SetTitle("ScinID_Replica");
    getStatistics().getHisto1D("ScinID_Replica")->GetYaxis()->SetTitle("Counts");

    getStatistics().createHistogram(new TH1F("ScinID_Replica_Cut", "ScinID_Replica_Cut",
      11, -0.5, 10.5));
    getStatistics().getHisto1D("ScinID_Replica_Cut")->GetXaxis()->SetTitle("ScinID_Replica_Cut");
    getStatistics().getHisto1D("ScinID_Replica_Cut")->GetYaxis()->SetTitle("Counts");

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







  }

  return true;
}

//TOT Calculation - Function (Sum over all thresholds)

double CalcTOT(const JPetHit & Hit) {

  double TOT = 0.;
  double TOT_A = 0.;
  double TOT_B = 0.;

  auto lead_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
  auto trail_times_A = Hit.getSignalA().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);
  auto lead_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Leading);
  auto trail_times_B = Hit.getSignalB().getRecoSignal().getRawSignal().getTimesVsThresholdNumber(JPetSigCh::Trailing);

  for (auto & thr_time_pair: lead_times_A) {
    int thr = thr_time_pair.first;
    if (trail_times_A.count(thr) > 0) {
      TOT_A = TOT_A + trail_times_A[thr] - lead_times_A[thr];
    }
  }

  for (auto & thr_time_pair: lead_times_B) {
    int thr = thr_time_pair.first;
    if (trail_times_B.count(thr) > 0) {

      TOT_B = TOT_B + trail_times_B[thr] - lead_times_B[thr];
    }
  }
  TOT = (TOT_A + TOT_B) / 1000.;

  return TOT;
}

//TOF Calculation - Function (From Center (0,0,0))

double CalcTOF(const JPetHit & Hit, TVector3 Center) {

  double Dist = sqrt(pow(Hit.getPosX() - Center.X(), 2) + pow(Hit.getPosY() - Center.Y(), 2) + pow(Hit.getPosZ() - Center.Z(), 2));

  double CalTime = Dist / 29.979246; //velocity of light in cm/s, returns time in ns

  double HitTime = Hit.getTime() / 1000.0;

  double TOF = (HitTime - CalTime);

  return TOF;

}



//3D-Angle Calculation - Function

  double Calc3DAngle(const JPetHit & Hit1,
  const JPetHit & Hit2 , TVector3 Center) {

  double scalarProd = (Hit1.getPosX() - Center.X()) * (Hit2.getPosX() - Center.X()) + (Hit1.getPosY() - Center.Y()) * (Hit2.getPosY() - Center.Y()) + (Hit1.getPosZ() - Center.Z()) * (Hit2.getPosZ() - Center.Z());

  double magProd = sqrt((pow(Hit1.getPosX() - Center.X(), 2) +
      pow(Hit1.getPosY() - Center.Y(), 2) +
      pow(Hit1.getPosZ() - Center.Z(), 2)) *
    (pow(Hit2.getPosX() - Center.X(), 2) +
      pow(Hit2.getPosY() - Center.Y(), 2) +
      pow(Hit2.getPosZ() - Center.Z(), 2)));

  double Angle = acos(scalarProd / magProd) * 180 / 3.14159;

  return Angle;
}



//Calculate the distance of the Annihilation Surface to the center of the detector geometry

double CalDistofSurface(const JPetHit Hit1,
  const JPetHit Hit2,
    const JPetHit Hit3, TVector3 Center)

{

  TVector3 vec1(Hit2.getPosX() - Hit1.getPosX(), Hit2.getPosY() - Hit1.getPosY(), Hit2.getPosZ() - Hit1.getPosZ());
  TVector3 vec2(Hit3.getPosX() - Hit2.getPosX(), Hit3.getPosY() - Hit2.getPosY(), Hit3.getPosZ() - Hit2.getPosZ());
  TVector3 crossProd = vec1.Cross(vec2);

  double Dcoeef = -crossProd(0) * Hit2.getPosX() - crossProd(1) * Hit2.getPosY() - crossProd(2) * Hit2.getPosZ();

  double distancefromZero = fabs(crossProd(0) * Center.X() + crossProd(1) * Center.Y() + crossProd(2) * Center.Z() + Dcoeef) / crossProd.Mag();
  return distancefromZero;
}



//Calculation of the Scatter Test between Primary and Secondary hits

double CalScatterTest(const JPetHit & Hit1,
  const JPetHit & Hit2)

{

  double timeDiff = ((Hit2.getTime() / 1000.0) - (Hit1.getTime() / 1000.0));
  float Dist = sqrt(pow(Hit2.getPosX() - Hit1.getPosX(), 2) +
    pow(Hit2.getPosY() - Hit1.getPosY(), 2) +
    pow(Hit2.getPosZ() - Hit1.getPosZ(), 2));
  Dist = Dist / 29.979246;
  double Scat = (timeDiff - Dist);
  return Scat;

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


	
      if (event.getHits().size() >= 4) {
 
      getStatistics().getHisto1D("Hits")->Fill(event.getHits().size()); 




      //Create vectors for different types of hits

	vector<JPetHit> hits = event.getHits();
	
	std::vector < JPetHit > AnniHits;
	std::vector < JPetHit > DeexHits;
	std::vector < JPetHit > ScatHits;

	

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

	//4 or more Hits


	if( DeexHits.size() == 1 && AnniHits.size() == 3)
	{


//Time Check 
/*
	int counter = 0;
	
	double t1 = AnniHits[0].getTime()/1000;
	double t2 = AnniHits[1].getTime()/1000;
	double t3 = AnniHits[2].getTime()/1000;


	if((t1-t2) == 0 || (t1-t3) == 0 || (t2-t3) == 0)
	counter++;

	cout<<counter<<endl;

*/

//ID's of the 5-Hits

	  auto ID_Deex = DeexHits[0].getScintillator().getID();
          auto ID_Anni_1 = AnniHits[0].getScintillator().getID();
          auto ID_Anni_2 = AnniHits[1].getScintillator().getID();
          auto ID_Anni_3 = AnniHits[2].getScintillator().getID();
	  

//Count Rate - ID's filling

	  getStatistics().getHisto1D("ScinID")->Fill(ID_Deex);
          getStatistics().getHisto1D("ScinID")->Fill(ID_Anni_1);
          getStatistics().getHisto1D("ScinID")->Fill(ID_Anni_2);
          getStatistics().getHisto1D("ScinID")->Fill(ID_Anni_3);
          

	  std::vector < double > ScinID;
          ScinID.push_back(ID_Deex);
          ScinID.push_back(ID_Anni_1);
          ScinID.push_back(ID_Anni_2);
          ScinID.push_back(ID_Anni_3);
	  

//Scintillator ID - Replica Test 

          int k = 0;
          int limit = ScinID.size();
          for (int i = 0; i < limit; i++) {
            for (int j = 0; j < limit; j++) {
              if (i != j && ScinID[i] == ScinID[j])
                k++;
            }
          }

          int m = k / 2;
          getStatistics().getHisto1D("ScinID_Replica")->Fill(m);

          if (m == 0)
          getStatistics().getHisto1D("ScinID_Replica_Cut")->Fill(m);




 if (ID_Deex != ID_Anni_1 && ID_Deex != ID_Anni_2 && ID_Deex != ID_Anni_3)
     {

   if (ID_Anni_1 != ID_Anni_2 && ID_Anni_1 != ID_Anni_3)
          {

        if (ID_Anni_2 != ID_Anni_3)
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
	
	if(LifeTime < 0)

	{


		getStatistics().getHisto1D("LifeTime_Check1")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check1")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);




	}


	else if(LifeTime > 0 && LifeTime < 5.0)


	{


		getStatistics().getHisto1D("LifeTime_Check2")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check2")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);


	}


	else if(LifeTime > 5.0)
	{


		getStatistics().getHisto1D("LifeTime_Check3")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check3")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);



	}




//3-D Angle Calculation - 190 Cut

   if ((Angle3D.at(1).first + Angle3D.at(0).first) >= 190.0) {


 getStatistics().getHisto2D("Angle3D_190")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);




  	  getStatistics().getHisto1D("LifeTime")->Fill(LifeTime);
	  getStatistics().getHisto1D("ScinID_After")->Fill(ID_Deex);
          getStatistics().getHisto1D("ScinID_After")->Fill(ID_Anni_1);
          getStatistics().getHisto1D("ScinID_After")->Fill(ID_Anni_2);
          getStatistics().getHisto1D("ScinID_After")->Fill(ID_Anni_3);
          





	if(LifeTime < 0)

	{


		getStatistics().getHisto1D("LifeTime_Check4")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check4")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);




	}


	else if(LifeTime > 0 && LifeTime < 5.0)


	{


		getStatistics().getHisto1D("LifeTime_Check5")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check5")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);


	}


	else if(LifeTime > 5.0)
	{


		getStatistics().getHisto1D("LifeTime_Check6")->Fill(LifeTime);

 		getStatistics().getHisto2D("Angle3D_Check6")->Fill(Angle3D.at(1).first + Angle3D.at(0).first, Angle3D.at(1).first - Angle3D.at(0).first);



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
