////////////////////////////////////////////////////////////////////////
// Class:       analyzer
// Plugin Type: analyzer (art v3_05_01)
// File:        analyzer_module.cc
//
// Generated at Wed Oct 21 05:17:17 2020 by Shyam Bhuller using cetskelgen
// from cetlib version v3_10_00.
////////////////////////////////////////////////////////////////////////

#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Principal/Run.h"
#include "art/Framework/Principal/SubRun.h"
#include "art_root_io/TFileService.h"
#include "canvas/Utilities/InputTag.h"
#include "canvas/Persistency/Common/FindManyP.h"
#include "fhiclcpp/ParameterSet.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

#include "lardataobj/RecoBase/Hit.h"
#include "lardataobj/RecoBase/Track.h"
#include "lardataobj/RecoBase/Shower.h"
#include "lardataobj/RecoBase/PFParticle.h"
#include "nusimdata/SimulationBase/MCParticle.h"
#include "nusimdata/SimulationBase/MCTruth.h"
#include "lardataobj/AnalysisBase/CosmicTag.h"
#include "lardataobj/AnalysisBase/T0.h"

#include "dune/AnaUtils/DUNEAnaPFParticleUtils.h"
#include "dune/AnaUtils/DUNEAnaShowerUtils.h"
#include "dune/AnaUtils/DUNEAnaTrackUtils.h"
#include "dune/Protodune/singlephase/DataUtils/ProtoDUNEDataUtils.h"


namespace viewer{
	class analyzer;
}


class viewer::analyser : public art::EDAnalyzer {
public:
  explicit analyzer(fhicl::ParameterSet const& p);
  // The compiler-generated destructor is fine for non-base
  // classes without bare pointers or other resource use.

  // Plugins should not be copied or assigned.
  analyzer(analyzer const&) = delete;
  analyzer(analyzer&&) = delete;
  analyzer& operator=(analyzer const&) = delete;
  analyzer& operator=(analyzer&&) = delete;

  virtual void beginJob() override;
  virtual void endJob() override;

  // Required functions.
  void analyze(art::Event const& e) override;

private:

  // Declare member data here.
  // Store .fcl parameters here;
  std::string fCalorimetryTag;
  std::string fTrackerTag;
  std::string fShowerTag;
  std::string fPFParticleTag;
  std::string fGeneratorTag;
  bool fVerbose;

  viewer::ProtoDUNEDataUtils dataUtil;

};


analyzer::analyzer(fhicl::ParameterSet const& p)
  :
  EDAnalyzer{p}  // ,
  fCalorimetryTag(p.get<std::string>("CalorimetryTag")),
  fTrackerTag(p.get<std::string>("TrackerTag")),
  fShowerTag(p.get<std::string>("ShowerTag")),
  fPFParticleTag(p.get<std::string>("PFParticleTag")),
  fGeneratorTag(p.get<std::string>("GeneratorTag")),
  fVerbose(p.get<bool>("Verbose")),
  dataUtil(p.get<fhicl::ParameterSet>("DataUtils"))
  // More initializers here.
{
  // Call appropriate consumes<>() for any products to be retrieved by this module.
}

void viewer::analyzer::beginJob()
{
  
}

void viewer::analyzer::analyze(art::Event const& e)
{
  // Implementation of required member function here.
  bool beamTriggerEvent = false;
  beamTiggerEvent = dataUtil.IsBeamTrigger(evt);
  if(beamTrigerEvent)
  {
  	std::cout << "This data event has a beam trigger" << std::endl;
  }
}

void viewer::analyzer::endJob()
{
	
}

DEFINE_ART_MODULE(viewer::analyzer)
