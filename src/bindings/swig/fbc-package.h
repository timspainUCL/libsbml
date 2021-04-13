/**
 * Filename    : fbc-package.h
 * Description : fbc include file for bindings.
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

#ifdef USE_FBC

#include <liblx/packages/fbc/extension/FbcExtension.h>
#include <liblx/packages/fbc/extension/FbcModelPlugin.h>
#include <liblx/packages/fbc/extension/FbcSpeciesPlugin.h>
#include <liblx/packages/fbc/extension/FbcSBMLDocumentPlugin.h>

#include <liblx/packages/fbc/util/CobraToFbcConverter.h>
#include <liblx/packages/fbc/util/FbcToCobraConverter.h>
#include <liblx/packages/fbc/util/FbcV1ToV2Converter.h>
#include <liblx/packages/fbc/util/FbcV2ToV1Converter.h>

#include <liblx/packages/fbc/sbml/Association.h>
#include <liblx/packages/fbc/sbml/FluxBound.h>
#include <liblx/packages/fbc/sbml/FluxObjective.h>
#include <liblx/packages/fbc/sbml/GeneAssociation.h>
#include <liblx/packages/fbc/sbml/Objective.h>

#include <liblx/packages/fbc/validator/FbcSBMLError.h>

#include <liblx/packages/fbc/extension/FbcReactionPlugin.h>
#include <liblx/packages/fbc/common/FbcExtensionTypes.h>
#include <liblx/packages/fbc/sbml/FbcAssociation.h>
#include <liblx/packages/fbc/sbml/GeneProductAssociation.h>
#include <liblx/packages/fbc/sbml/GeneProduct.h>
#include <liblx/packages/fbc/sbml/GeneProductRef.h>
#include <liblx/packages/fbc/sbml/FbcAnd.h>
#include <liblx/packages/fbc/sbml/FbcOr.h>

#endif // USE_FBC 

