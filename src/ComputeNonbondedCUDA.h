
#include "ComputeNonbondedUtil.h"
#include "ComputeHomeTuples.h"

class ComputeNonbondedCUDAKernel;

class ComputeNonbondedCUDA : public Compute, private ComputeNonbondedUtil {
  public:

  struct compute_record {
    ComputeID c;
    PatchID pid[2];
    int t[2];
  };

  struct patch_record {
    int localIndex;
    int localStart;
    int numAtoms;
    int numFreeAtoms;
    int refCount;
    int isLocal;
    PatchID patchID;
    Patch *p;
    Box<Patch,CompAtom> *positionBox;
    Box<Patch,Results> *forceBox;
    CompAtom *x;
    CompAtomExt *xExt;
    Results *r;
    Force *f;

    patch_record() { refCount = 0; }
  };

    ComputeNonbondedCUDA(ComputeID c);
    ~ComputeNonbondedCUDA();

    void atomUpdate();
    void doWork();

    int workStarted;
    int finishWork();  // returns true when finished, false to continue

    static void build_force_table();

    void build_exclusions();

    void requirePatch(int pid);
    ResizeArray<int> activePatches, localActivePatches, remoteActivePatches;
    ResizeArray<patch_record> patchRecords;
    ResizeArray<compute_record> computeRecords;
    ResizeArray<compute_record> localComputeRecords, remoteComputeRecords;

    int num_atom_records;
    int num_local_atom_records;
    int num_remote_atom_records;
    int num_force_records;

    PatchMap *patchMap;
    AtomMap *atomMap;
    SubmitReduction *reduction;

    ComputeNonbondedCUDAKernel *kernel;

};

