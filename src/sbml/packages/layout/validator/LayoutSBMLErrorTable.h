/**
 * @file:   LayoutSBMLErrorTable.h
 * @brief:  Implementation of the LayoutSBMLErrorTable class
 * @author: Generated by autocreate code
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
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
 * ------------------------------------------------------------------------ -->
 */


#ifndef LayoutSBMLErrorTable_H__
#define LayoutSBMLErrorTable_H__


#include <sbml/packages/layout/validator/LayoutSBMLError.h>

LIBSBML_CPP_NAMESPACE_BEGIN

	/** @cond doxygen-libsbml-internal */

static const packageErrorTableEntry layoutErrorTable[] = 
{
	//6010100
	{	LayoutUnknownError,
		"Unknown error from layout",
		LIBSBML_CAT_GENERAL_CONSISTENCY,
		LIBSBML_SEV_ERROR,
		"Unknown error from layout",
		{ " "
		}
	},

  // 6010101
  { LayoutNSUndeclared, 
    "The layout ns is not correctly declared",
    LIBSBML_CAT_GENERAL_CONSISTENCY, 
    LIBSBML_SEV_ERROR,
    "To conform to Version 1 of the Layout "
    "package specification for SBML Level 3, an "
    "SBML document must declare the use of the following XML Namespace: "
    "'http://www.sbml.org/sbml/level3/version1/layout/version1'",
    { "L3V1 Layout V1 Section 3.1"
    }
  },

  // 6010102
  { LayoutElementNotInNs, 
    "Element not in layout namespace",
    LIBSBML_CAT_GENERAL_CONSISTENCY, 
    LIBSBML_SEV_ERROR,
    "Wherever they appear in an SBML document, "
    "elements and attributes from the Layout "
    "package must be declared either implicitly or explicitly to be in the "
    "XML namespace 'http://www.sbml.org/sbml/level3/version1/layout/version1'",
    { "L3V1 Layout V1 Section 3.1"
    }
  },

    // 6010301
  { LayoutDuplicateComponentId, 
  "Duplicate 'id' attribute value",
    LIBSBML_CAT_IDENTIFIER_CONSISTENCY, 
    LIBSBML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Version 1 Core "
	"specification.) Within a <model> object"
	"the values of the attributes id and layout:id on every instance of the "
	"following classes of objects must be unique across the set of all id "
	"and layout:id attribute values of all such objects in a model: the "
	"model itself, plus all contained <functionDefinition>, <compartment>,"
	"<species>, <reaction>, <speciesReference>, <modifierSpeciesReference>, "
  "<event>, and <parameter> objects, plus the <boundingBox>, "
  "<compartmentGlyph>, <generalGlyph>, <graphicalObject>, <layout>, "
  "<speciesGlyph>, <speciesReferenceGlyph>, <reactionGlyph>, "
  "<referenceGlyph> and <textGlyph> "
	"objects defined by the Layout package.", 
    { "L3V1 Layout V1 Section 3.3"
    }
  },

  // 6020101
  { LayoutAttributeRequiredMissing, 
    "Required layout:required attribute on <sbml>",
    LIBSBML_CAT_GENERAL_CONSISTENCY, 
    LIBSBML_SEV_ERROR,
    "In all SBML documents using the Layout "
    "package, the SBML object must include a value for the attribute "
    "'layout:required.",
    { "L3V1 Core Section 4.1.2"
    }
  },

  // 6020102
  { LayoutAttributeRequiredMustBeBoolean, 
    "The layout:required attribute must be Boolean",
    LIBSBML_CAT_GENERAL_CONSISTENCY, 
    LIBSBML_SEV_ERROR,
    "The value of attribute 'layout:required' on the SBML object must "
    "be of the data type Boolean.",
    { "L3V1 Core Section 4.1.2"
    }
  },

  // 6020103
  { LayoutRequiredFalse, 
    "The layout:required attribute must be 'false'",
    LIBSBML_CAT_GENERAL_CONSISTENCY, 
    LIBSBML_SEV_ERROR,
    "The value of attribute 'layout:required' on the SBML object must "
    "be set to 'false'.",
    { "L3V1 Layout V1 Section 3.1"
    }
  },

  // 6020201
  { LayoutOnlyOneEachListOf, 
    "Only one listOfLayouts on <model>",
    LIBSBML_CAT_GENERAL_CONSISTENCY, 
    LIBSBML_SEV_ERROR,
    "There may be at most one instance of <listOfLayouts> element within "
    "a <model> object using Layout. No other elements from the Layout "
    "package are allowed.",
    { "L3V1 Layout V1 Section 3.5"
    }
  },

  // 6020202
  { LayoutNoEmptyListOfs, 
    "ListOf elements cannot be empty",
    LIBSBML_CAT_GENERAL_CONSISTENCY, 
    LIBSBML_SEV_ERROR,
    "The <listOfLayouts> within a <model> object is optional, "
    "but if present, this object must not be empty.",
    { "L3V1 Layout V1 Section 3.5"
    }
  },

  // 6020203
  { LayoutLOLayoutsAllowedElements, 
    "Allowed elements on ListOfLayouts",
    LIBSBML_CAT_GENERAL_CONSISTENCY, 
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotation subobjects permitted on "
    "all SBML objects, a <listOfLayouts> container object may only "
    "contain <layout> objects.",
    { "L3V1 Layout V1 Section 3.5"
    }
  },

  // 6020204
  { LayoutLOLayoutsAllowedAttributes, 
    "Allowed attributes on ListOfLayouts",
    LIBSBML_CAT_GENERAL_CONSISTENCY, 
    LIBSBML_SEV_ERROR,
    "A <listOfLayouts> object may have the optional attributes 'metaid' "
    "and 'sboTerm' defined by SBML Level~3 Core. No other attributes from "
    "the SBML Level 3 Core namespace or the Layout "
    "namespace are permitted on a <listOfLayouts> object. ",
    { "L3V1 Layout V1 Section 3.5"
    }
  }




};


LIBSBML_CPP_NAMESPACE_END

	/** @endcond doxygen-libsbml-internal */


#endif  /*  LayoutSBMLErrorTable_h__  */

