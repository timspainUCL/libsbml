/**
 * Filename    : render-package.h
 * Description : render include file for bindings.
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

#ifdef USE_RENDER

#include <liblx/packages/render/extension/RenderExtension.h>
#include <liblx/packages/render/extension/RenderListOfLayoutsPlugin.h>
#include <liblx/packages/render/extension/RenderLayoutPlugin.h>
#include <liblx/packages/render/extension/RenderGraphicalObjectPlugin.h>

#include <liblx/packages/render/sbml/Transformation.h>
#include <liblx/packages/render/sbml/Transformation2D.h>
#include <liblx/packages/render/sbml/GraphicalPrimitive1D.h>
#include <liblx/packages/render/sbml/GraphicalPrimitive2D.h>
#include <liblx/packages/render/sbml/RenderInformationBase.h>
#include <liblx/packages/render/sbml/GradientBase.h>
#include <liblx/packages/render/sbml/Style.h>


#include <liblx/packages/render/sbml/ColorDefinition.h>
#include <liblx/packages/render/sbml/RelAbsVector.h>
#include <liblx/packages/render/sbml/Ellipse.h>
#include <liblx/packages/render/sbml/GlobalRenderInformation.h>
#include <liblx/packages/render/sbml/GlobalStyle.h>
#include <liblx/packages/render/sbml/GradientStop.h>
#include <liblx/packages/render/sbml/Image.h>
#include <liblx/packages/render/sbml/Text.h>
#include <liblx/packages/render/sbml/Rectangle.h>
#include <liblx/packages/render/sbml/RenderPoint.h>
#include <liblx/packages/render/sbml/RenderCubicBezier.h>
#include <liblx/packages/render/sbml/RenderCurve.h>
#include <liblx/packages/render/sbml/Polygon.h>
#include <liblx/packages/render/sbml/RenderGroup.h>
#include <liblx/packages/render/sbml/LinearGradient.h>
#include <liblx/packages/render/sbml/LineEnding.h>
#include <liblx/packages/render/sbml/LocalRenderInformation.h>
#include <liblx/packages/render/sbml/LocalStyle.h>
#include <liblx/packages/render/sbml/RadialGradient.h>
#include <liblx/packages/render/sbml/DefaultValues.h>

#include <liblx/packages/render/sbml/ListOfColorDefinitions.h>
#include <liblx/packages/render/sbml/ListOfCurveElements.h>
#include <liblx/packages/render/sbml/ListOfDrawables.h>
#include <liblx/packages/render/sbml/ListOfGlobalRenderInformation.h>
#include <liblx/packages/render/sbml/ListOfGlobalStyles.h>
#include <liblx/packages/render/sbml/ListOfGradientDefinitions.h>
#include <liblx/packages/render/sbml/ListOfGradientStops.h>
#include <liblx/packages/render/sbml/ListOfLineEndings.h>
#include <liblx/packages/render/sbml/ListOfLocalRenderInformation.h>
#include <liblx/packages/render/sbml/ListOfLocalStyles.h>
#define FillMeInAsSizeCannotBeDeterminedAutomatically 12

#endif
