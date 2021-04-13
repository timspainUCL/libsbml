/**
 * Filename    : comp-package.h
 * Description : SBML comp include file for bindings.
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->
 */

#ifdef USE_COMP


#include <liblx/packages/comp/extension/CompExtension.h>
#include <liblx/packages/comp/extension/CompSBasePlugin.h>
#include <liblx/packages/comp/extension/CompModelPlugin.h>
#include <liblx/packages/comp/extension/CompSBMLDocumentPlugin.h>

#include <liblx/packages/comp/util/SBMLUri.h>
#include <liblx/packages/comp/util/SBMLResolver.h>
#include <liblx/packages/comp/util/SBMLFileResolver.h>
#include <liblx/packages/comp/util/SBMLResolverRegistry.h>
#include <liblx/packages/comp/util/CompFlatteningConverter.h>

#include <liblx/packages/comp/sbml/CompBase.h>
#include <liblx/packages/comp/sbml/SBaseRef.h>
#include <liblx/packages/comp/sbml/Replacing.h>
#include <liblx/packages/comp/sbml/Deletion.h>
#include <liblx/packages/comp/sbml/ExternalModelDefinition.h>
#include <liblx/packages/comp/sbml/ListOfDeletions.h>
#include <liblx/packages/comp/sbml/ListOfExternalModelDefinitions.h>
#include <liblx/packages/comp/sbml/ListOfModelDefinitions.h>
#include <liblx/packages/comp/sbml/ListOfPorts.h>
#include <liblx/packages/comp/sbml/ListOfReplacedElements.h>
#include <liblx/packages/comp/sbml/ListOfSubmodels.h>
#include <liblx/packages/comp/sbml/ModelDefinition.h>
#include <liblx/packages/comp/sbml/Port.h>
#include <liblx/packages/comp/sbml/ReplacedBy.h>
#include <liblx/packages/comp/sbml/ReplacedElement.h>
#include <liblx/packages/comp/sbml/Submodel.h>
#include <liblx/packages/comp/sbml/Replacing.h>
#include <liblx/packages/comp/validator/CompSBMLError.h>

#endif /* USE_COMP */
