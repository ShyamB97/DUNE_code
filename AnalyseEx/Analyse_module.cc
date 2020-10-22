////////////////////////////////////////////////////////////////////////
// Class:       Analyse
// Plugin Type: analyzer (art v3_05_01)
// File:        Analyse_module.cc
//
// Generated at Wed Oct 21 09:57:11 2020 by Shyam Bhuller using cetskelgen
// from cetlib version v3_10_00.
////////////////////////////////////////////////////////////////////////

#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Principal/Run.h"
#include "art/Framework/Principal/SubRun.h"
#include "canvas/Utilities/InputTag.h"
#include "fhiclcpp/ParameterSet.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

#include "art_root_io/TFileService.h"
#include <TTree.h>

namespace test {
  class Analyse;
}


class test::Analyse : public art::EDAnalyzer {
public:
  explicit Analyse(fhicl::ParameterSet const& p);
  // The compiler-generated destructor is fine for non-base
  // classes without bare pointers or other resource use.

  // Plugins should not be copied or assigned.
  Analyse(Analyse const&) = delete;
  Analyse(Analyse&&) = delete;
  Analyse& operator=(Analyse const&) = delete;
  Analyse& operator=(Analyse&&) = delete;

  // Required functions.
  void analyze(art::Event const& e) override;

  // Selected optional functions.
  void beginJob() override;
  void endJob() override;

private:

  // Declare member data here.
  TTree *fTree;
  unsigned int fEventID;

};


test::Analyse::Analyse(fhicl::ParameterSet const& p)
  : EDAnalyzer{p}  // ,
  // More initializers here.
{
  // Call appropriate consumes<>() for any products to be retrieved by this module.
}

void test::Analyse::analyze(art::Event const& e)
{
  // Implementation of required member function here.
  fEventID = e.id().event();
  fTree->Fill();
}

void test::Analyse::beginJob()
{
  // Implementation of optional member function here.
  art::ServiceHandle<art::TFileService> tfs;
  fTree = tfs->make<TTree>("tree", "Analyser Output Tree");
  fTree->Branch("EventID", &fEventID, "eventID/i");
}

void test::Analyse::endJob()
{
  // Implementation of optional member function here.
}

DEFINE_ART_MODULE(test::Analyse)
