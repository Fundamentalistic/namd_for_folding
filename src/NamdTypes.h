/***************************************************************************/
/*                                                                         */
/*              (C) Copyright 1996 The Board of Trustees of the            */
/*                          University of Illinois                         */
/*                           All Rights Reserved                           */
/*									   */
/***************************************************************************/

/***************************************************************************
 * DESCRIPTION:
 *
 ***************************************************************************/

#ifndef NAMDTYPES_H

#define NAMDTYPES_H

#include "Vector.h"
#include "Templates/ResizeArray.h"
#include "Templates/ResizeArrayIter.h"

class Patch;
class Compute;

typedef Vector Position;
typedef Vector Velocity;
typedef Vector Force;
typedef int AtomID;
typedef int AtomType;
typedef float Mass;
typedef float Charge;

typedef double Coordinate;

struct AtomProperties
{
  AtomID id;
  AtomType type;
  Mass mass;
  Charge charge;
};

typedef ResizeArray<Position> PositionList;
typedef ResizeArrayIter<Position> PositionListIter;
typedef ResizeArray<Velocity> VelocityList;
typedef ResizeArrayIter<Velocity> VelocityListIter;
typedef ResizeArray<Force> ForceList;
typedef ResizeArrayIter<Force> ForceListIter;
typedef ResizeArray<AtomProperties> AtomPropertiesList;
typedef ResizeArrayIter<AtomProperties> AtomPropertiesListIter;

typedef ResizeArray<AtomID> AtomIDList;
typedef ResizeArrayIter<AtomID> AtomIDListIter;

typedef int PatchID;
typedef int ComputeID;
typedef int NodeID;

typedef ResizeArray<PatchID> PatchIDList;
typedef ResizeArrayIter<PatchID> PatchIDListIter;
typedef ResizeArray<Patch *> PatchList;
typedef ResizeArrayIter<Patch *> PatchListIter;

typedef UniqueSortedArray<ComputeID> ComputeIDList;
typedef ResizeArrayIter<ComputeID> ComputeIDListIter;

typedef ResizeArray<Compute *> ComputeList;
typedef ResizeArrayIter<Compute *> ComputeListIter;

struct LocalID
{
  PatchID pid;
  int index;
};

enum ComputeType
{
  computeNonbondedSelfType,
  computeNonbondedPairType,
  computeNonbondedExclType,
  computeBondsType,
  computeAnglesType,
  computeDihedralsType,
  computeImpropersType
};

enum Boolean
{
  false=0,
  true=1
};

#endif /* NAMDTYPES_H */

/***************************************************************************
 * RCS INFORMATION:
 *
 *	$RCSfile: NamdTypes.h,v $
 *	$Author: jim $	$Locker:  $		$State: Exp $
 *	$Revision: 1.12 $	$Date: 1996/11/30 01:27:34 $
 *
 ***************************************************************************
 * REVISION HISTORY:
 *
 * $Log: NamdTypes.h,v $
 * Revision 1.12  1996/11/30 01:27:34  jim
 * switched to realistic ComputeType definitions
 *
 * Revision 1.11  1996/10/30 01:05:50  jim
 * added AtomPropertiesList
 *
 * Revision 1.10  1996/10/30 00:32:18  jim
 * added AtomProperties definition
 *
 * Revision 1.9  1996/10/24 18:51:09  brunner
 * Added LocalID
 *
 * Revision 1.8  1996/10/16 08:22:39  ari
 * *** empty log message ***
 *
 * Revision 1.7  1996/09/10 04:16:28  jim
 * Added iterators for all lists.
 *
 * Revision 1.6  1996/08/29 00:52:06  ari
 * *** empty log message ***
 *
 * Revision 1.5  1996/08/23 21:36:58  ari
 * *** empty log message ***
 *
 * Revision 1.4  1996/08/19 21:37:02  brunner
 * Added Coordinate
 *
 * Revision 1.3  1996/08/19 21:27:51  ari
 * .
 *
 * Revision 1.2  1996/08/16 21:42:58  brunner
 * *** empty log message ***
 *
 * Revision 1.1  1996/08/16 21:00:37  brunner
 * Initial revision
 *
 ***************************************************************************/
