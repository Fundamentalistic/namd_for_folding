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

class Patch;
class Compute;

typedef Vector Position;
typedef Vector Velocity;
typedef Vector Force;

typedef ResizeArray<Position> PositionList;
typedef ResizeArray<Velocity> VelocityList;
typedef ResizeArray<Force> ForceList;

typedef int PatchID;
typedef int ComputeID;
typedef int NodeID;

typedef ResizeArray<PatchID> PatchIDList;
typedef ResizeArray<Patch *> PatchList;

typedef ResizeArray<Compute *> ComputeList;

enum ComputeType
{
  electForceType,
  bondForceType,
  angleForceType,
  dihedralForceType,
  improperForceType
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
 *	$Author: ari $	$Locker:  $		$State: Exp $
 *	$Revision: 1.3 $	$Date: 1996/08/19 21:27:51 $
 *
 ***************************************************************************
 * REVISION HISTORY:
 *
 * $Log: NamdTypes.h,v $
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
