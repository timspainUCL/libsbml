#ifdef USE_MULTI

#include <liblx/packages/multi/extension/MultiExtension.h>
#include <liblx/packages/multi/extension/MultiSBMLDocumentPlugin.h>
#include <liblx/packages/multi/extension/MultiModelPlugin.h>
#include <liblx/packages/multi/extension/MultiCompartmentPlugin.h>
#include <liblx/packages/multi/extension/MultiSpeciesPlugin.h>
#include <liblx/packages/multi/extension/MultiSimpleSpeciesReferencePlugin.h>
#include <liblx/packages/multi/extension/MultiSpeciesReferencePlugin.h>
#include <liblx/packages/multi/extension/MultiListOfReactionsPlugin.h>
#include <liblx/packages/multi/common/MultiExtensionTypes.h>
#include <liblx/packages/multi/sbml/PossibleSpeciesFeatureValue.h>
#include <liblx/packages/multi/sbml/SpeciesFeatureValue.h>
#include <liblx/packages/multi/sbml/CompartmentReference.h>
#include <liblx/packages/multi/sbml/SpeciesTypeInstance.h>
#include <liblx/packages/multi/sbml/InSpeciesTypeBond.h>
#include <liblx/packages/multi/sbml/OutwardBindingSite.h>
#include <liblx/packages/multi/sbml/SpeciesFeatureType.h>
#include <liblx/packages/multi/sbml/SpeciesTypeComponentIndex.h>
#include <liblx/packages/multi/sbml/SpeciesFeature.h>
#include <liblx/packages/multi/sbml/SpeciesTypeComponentMapInProduct.h>
#include <liblx/packages/multi/sbml/SubListOfSpeciesFeatures.h>
#include <liblx/packages/multi/sbml/MultiSpeciesType.h>
#include <liblx/packages/multi/sbml/BindingSiteSpeciesType.h>
#include <liblx/packages/multi/sbml/IntraSpeciesReaction.h>

#include <liblx/packages/multi/extension/MultiASTPlugin.h>

#endif // USE_MULTI 

