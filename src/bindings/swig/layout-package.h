/**
 * Filename    : layout.h
 * Description : SBML Layout include file for bindings.
 * Organization: European Media Laboratories Research gGmbH
 * Created     : 2004-07-15
 *
 * Copyright 2004 European Media Laboratories Research gGmbH
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY, WITHOUT EVEN THE IMPLIED WARRANTY OF
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  The software and
 * documentation provided hereunder is on an "as is" basis, and the
 * European Media Laboratories gGmbH have no obligations to provide maintenance, support,
 * updates, enhancements or modifications.  In no event shall the
 * European Media Laboratory gGmbH be liable to any party for direct, indirect, special,
 * incidental or consequential damages, including lost profits, arising
 * out of the use of this software and its documentation, even if the
 * European Media Laboratories gGmbH have been advised of the possibility of such damage.  See
 * the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The original code contained here was initially developed by:
 *
 *     Ralph Gauges
 *     Bioinformatics Group
 *     European Media Laboratories Research gGmbH
 *     Schloss-Wolfsbrunnenweg 31c
 *     69118 Heidelberg
 *     Germany
 *
 *     http://www.eml-research.de/english/Research/BCB/
 *     mailto:ralph.gauges@eml-r.villa-bosch.de
 *
 * Contributor(s):
 */

#ifdef USE_LAYOUT

#include <liblx/packages/layout/sbml/SpeciesReferenceRole.h>
#include <liblx/packages/layout/sbml/BoundingBox.h>
#include <liblx/packages/layout/sbml/CompartmentGlyph.h>
#include <liblx/packages/layout/sbml/CubicBezier.h>
#include <liblx/packages/layout/sbml/Curve.h>
#include <liblx/packages/layout/sbml/Dimensions.h>
#include <liblx/packages/layout/sbml/GraphicalObject.h>
#include <liblx/packages/layout/sbml/Layout.h>
#include <liblx/packages/layout/sbml/LineSegment.h>
#include <liblx/packages/layout/sbml/Point.h>
#include <liblx/packages/layout/sbml/ReferenceGlyph.h>
#include <liblx/packages/layout/sbml/GeneralGlyph.h>
#include <liblx/packages/layout/sbml/ReactionGlyph.h>
#include <liblx/packages/layout/sbml/SpeciesGlyph.h>
#include <liblx/packages/layout/sbml/SpeciesReferenceGlyph.h>
#include <liblx/packages/layout/sbml/TextGlyph.h>

#include <liblx/packages/layout/extension/LayoutExtension.h>
#include <liblx/packages/layout/extension/LayoutModelPlugin.h>
#include <liblx/packages/layout/extension/LayoutSpeciesReferencePlugin.h>

#include <liblx/packages/layout/util/LayoutAnnotation.h>

#include <liblx/packages/layout/validator/LayoutSBMLError.h>

#endif

