
#include "ComputeNonbondedUtil.h"
#include "ComputeHomeTuples.h"

class ComputeMgr;

class ComputeNonbondedCUDAKernel;

class float4;

int cuda_device_pe();

bool cuda_device_shared_with_pe(int pe);

class ComputeNonbondedCUDA : public Compute, private ComputeNonbondedUtil {
  public:

  struct compute_record {
    ComputeID c;
    PatchID pid[2];
    Vector offset;
  };

  struct patch_record {
    int localIndex;
    int localStart;
    int numAtoms;
    int numFreeAtoms;
    int refCount;
    int isLocal;
    int hostPe;
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

    ComputeNonbondedCUDA(ComputeID c, ComputeMgr *mgr,
		ComputeNonbondedCUDA *m = 0, int idx = -1);
    ~ComputeNonbondedCUDA();

    void atomUpdate();
    void doWork();
    int noWork();

    void recvYieldDevice(int pe);

    int workStarted;
    Lattice lattice;
    int doSlow, doEnergy;
    int finishWork();  // returns true when finished, false to continue

    static void build_lj_table();
    static void build_force_table();

    void build_exclusions();

    void requirePatch(int pid);
    void assignPatches();
    void registerPatches();
    ResizeArray<int> activePatches, localActivePatches, remoteActivePatches;
    ResizeArray<int> hostedPatches, remoteHostedPatches;
    ResizeArray<patch_record> patchRecords;
    ResizeArray<compute_record> computeRecords;
    ResizeArray<compute_record> localComputeRecords, remoteComputeRecords;

    int num_atom_records;
    int num_local_atom_records;
    int num_remote_atom_records;
    int num_force_records;

    float4 *forces;
    float4 *slow_forces;

    PatchMap *patchMap;
    AtomMap *atomMap;
    SubmitReduction *reduction;

    ComputeNonbondedCUDAKernel *kernel;

    ComputeNonbondedCUDA *master;
    int slaveIndex;
    ComputeNonbondedCUDA **slaves;
    int *slavePes;
    int numSlaves;
};


