/***************************************************************************/
/*      (C) Copyright 1996,1997 The Board of Trustees of the               */
/*                          University of Illinois                         */
/*                           All Rights Reserved                           */
/***************************************************************************/
/***************************************************************************
 * DESCRIPTION:  Computes electrostatics using efficient all atoms^2 calc
 *
 ***************************************************************************/

#ifndef COMPUTEFULLDIRECT_H
#define COMPUTEFULLDIRECT_H

#include "ComputeHomePatches.h"
#include "NamdTypes.h"

class ComputeFullDirect : public ComputeHomePatches {
public:
  ComputeFullDirect(ComputeID c);
  virtual ~ComputeFullDirect();
  void doWork();

private:

  int numLocalAtoms;
  Position *localPositions;
  BigReal *localCharges;
  Force *localForces;

};

#endif
/***************************************************************************
 * RCS INFORMATION:
 *
 *	$RCSfile: ComputeFullDirect.h,v $
 *	$Author: ari $	$Locker:  $		$State: Exp $
 *	$Revision: 1.1001 $	$Date: 1997/03/20 23:53:37 $
 *
 ***************************************************************************
 * REVISION HISTORY:
 *
 * $Log: ComputeFullDirect.h,v $
 * Revision 1.1001  1997/03/20 23:53:37  ari
 * Some changes for comments. Copyright date additions.
 * Hooks for base level update of Compute objects from ComputeMap
 * by ComputeMgr.  Useful for new compute migration functionality.
 *
 * Revision 1.1000  1997/02/06 15:57:54  ari
 * Resetting CVS to merge branches back into the main trunk.
 * We will stick to main trunk development as suggested by CVS manual.
 * We will set up tags to track fixed points of development/release
 * as suggested by CVS manual - all praise the CVS manual.
 *
 * Revision 1.2  1997/02/06 15:52:55  ari
 * Updating Revision Line, getting rid of branches
 *
 * Revision 1.1.2.1  1997/02/06 04:20:25  jim
 * Added ComputeFullDirect.
 *
 * Revision 1.778  1997/01/28 01:00:33  ari
 * uplevel
 *
 * Revision 1.2  1997/01/28 01:00:11  ari
 * Adding This again
 *
 * Revision 1.1.2.1  1997/01/27 21:11:36  jim
 * test
 *
 * Revision 1.777  1997/01/17 19:35:45  ari
 * Internal CVS leveling release.  Start development code work
 * at 1.777.1.1.
 *
 * Revision 1.10  1997/01/16 00:55:56  jim
 * Added reduction of energies from ComputeHomeTuples objects, except
 * for ComputeNonbondedExcl which only reports 0 energy.
 * Some problems with ReductionMgr are apparent, but it still runs.
 *
 * Revision 1.9  1997/01/14 17:59:48  jim
 * fixed multiple force additions (no adding to proxies now)
 *
 * Revision 1.8  1996/12/04 18:03:12  jim
 * added AtomProperties checkout
 *
 * Revision 1.7  1996/11/19 06:58:37  jim
 * first compiling templated version, needed ugly void* hack
 *
 * Revision 1.6  1996/11/19 04:24:24  jim
 * first templated version as ComputeHomeTuples<T>
 *
 * Revision 1.5  1996/11/18 21:28:48  ari
 * *** empty log message ***
 *
 * Revision 1.4  1996/11/04 20:06:17  nealk
 * Now it compiles :-)
 *
 * Revision 1.3  1996/11/04 19:29:02  nealk
 * Added angleForce() to system, but it is untested.
 *
 * Revision 1.2  1996/11/04 16:55:46  ari
 * *** empty log message ***
 *
 * Revision 1.1  1996/11/01 21:20:45  ari
 * Initial revision
 *
 * Revision 1.3  1996/10/16 08:22:39  ari
 * *** empty log message ***
 *
 * Revision 1.1  1996/08/19 22:07:49  ari
 * Initial revision
 *
 * Revision 1.4  1996/07/16 01:54:12  ari
 * *** empty log message ***
 *
 * Revision 1.3  96/07/16  01:10:26  01:10:26  ari (Aritomo Shinozaki)
 * Fixed comments, added methods
 * 
 * Revision 1.2  1996/06/25 21:10:48  gursoy
 * *** empty log message ***
 *
 * Revision 1.1  1996/06/24 14:12:26  gursoy
 * Initial revision
 *
 ***************************************************************************/

