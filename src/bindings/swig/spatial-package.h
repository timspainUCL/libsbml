/**
 * @file spatial-package.h
 * @brief SWIG header file
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */


#ifdef USE_SPATIAL

#include <liblx/packages/spatial/extension/SpatialExtension.h>
#include <liblx/packages/spatial/extension/SpatialModelPlugin.h>
#include <liblx/packages/spatial/extension/SpatialCompartmentPlugin.h>
#include <liblx/packages/spatial/extension/SpatialSpeciesPlugin.h>
#include <liblx/packages/spatial/extension/SpatialParameterPlugin.h>
#include <liblx/packages/spatial/extension/SpatialReactionPlugin.h>
#include <liblx/packages/spatial/common/SpatialExtensionTypes.h>
#include <liblx/packages/spatial/sbml/DomainType.h>
#include <liblx/packages/spatial/sbml/Domain.h>
#include <liblx/packages/spatial/sbml/InteriorPoint.h>
#include <liblx/packages/spatial/sbml/Boundary.h>
#include <liblx/packages/spatial/sbml/AdjacentDomains.h>
#include <liblx/packages/spatial/sbml/GeometryDefinition.h>
#include <liblx/packages/spatial/sbml/CompartmentMapping.h>
#include <liblx/packages/spatial/sbml/CoordinateComponent.h>
#include <liblx/packages/spatial/sbml/SampledFieldGeometry.h>
#include <liblx/packages/spatial/sbml/SampledField.h>
#include <liblx/packages/spatial/sbml/SampledVolume.h>
#include <liblx/packages/spatial/sbml/AnalyticGeometry.h>
#include <liblx/packages/spatial/sbml/AnalyticVolume.h>
#include <liblx/packages/spatial/sbml/ParametricGeometry.h>
#include <liblx/packages/spatial/sbml/ParametricObject.h>
#include <liblx/packages/spatial/sbml/CSGeometry.h>
#include <liblx/packages/spatial/sbml/CSGObject.h>
#include <liblx/packages/spatial/sbml/CSGNode.h>
#include <liblx/packages/spatial/sbml/CSGTransformation.h>
#include <liblx/packages/spatial/sbml/CSGTranslation.h>
#include <liblx/packages/spatial/sbml/CSGRotation.h>
#include <liblx/packages/spatial/sbml/CSGScale.h>
#include <liblx/packages/spatial/sbml/CSGHomogeneousTransformation.h>
#include <liblx/packages/spatial/sbml/TransformationComponent.h>
#include <liblx/packages/spatial/sbml/CSGPrimitive.h>
#include <liblx/packages/spatial/sbml/CSGSetOperator.h>
#include <liblx/packages/spatial/sbml/SpatialSymbolReference.h>
#include <liblx/packages/spatial/sbml/DiffusionCoefficient.h>
#include <liblx/packages/spatial/sbml/AdvectionCoefficient.h>
#include <liblx/packages/spatial/sbml/BoundaryCondition.h>
#include <liblx/packages/spatial/sbml/Geometry.h>
#include <liblx/packages/spatial/sbml/MixedGeometry.h>
#include <liblx/packages/spatial/sbml/OrdinalMapping.h>
#include <liblx/packages/spatial/sbml/SpatialPoints.h>
#include <liblx/packages/spatial/sbml/ListOfDomainTypes.h>
#include <liblx/packages/spatial/sbml/ListOfDomains.h>
#include <liblx/packages/spatial/sbml/ListOfInteriorPoints.h>
#include <liblx/packages/spatial/sbml/ListOfAdjacentDomains.h>
#include <liblx/packages/spatial/sbml/ListOfGeometryDefinitions.h>
#include <liblx/packages/spatial/sbml/ListOfCoordinateComponents.h>
#include <liblx/packages/spatial/sbml/ListOfSampledFields.h>
#include <liblx/packages/spatial/sbml/ListOfSampledVolumes.h>
#include <liblx/packages/spatial/sbml/ListOfAnalyticVolumes.h>
#include <liblx/packages/spatial/sbml/ListOfParametricObjects.h>
#include <liblx/packages/spatial/sbml/ListOfCSGObjects.h>
#include <liblx/packages/spatial/sbml/ListOfCSGNodes.h>
#include <liblx/packages/spatial/sbml/ListOfOrdinalMappings.h>

#endif // USE_SPATIAL

