/* Copyright 2023 The MathWorks, Inc. */
/*!
 * @file
 * solverhit manager support in deployed code
 */

#ifndef nesl_rtw_solverhit_h
#define nesl_rtw_solverhit_h

#include <nesl_rtw.h>

PMF_DEPLOY_STATIC
NeslSolverHitManager* nesl_lease_solverhit_manager(const char* key, int index) {
    const NeslSimulatorGroupRegistry* registry = nesl_get_registry();

    /* Const cast required to pass through RTWCG-generated pointer type */
    union {
        const NeslSolverHitManager* constManager;
        NeslSolverHitManager*       manager;
    } u;

    u.constManager = registry->mLeaseSolverHitManager(registry, key, (size_t)index);

    return u.manager;
}

PMF_DEPLOY_STATIC
void nesl_solverhit_manager_get_solverhits(NeslSolverHitManager* manager,
                                           NeuDiagnosticManager* diag,
                                           PmRealVector*         sh) {
    manager->mGetSolverHits(manager, diag, sh);
    return;
}

PMF_DEPLOY_STATIC
int nesl_compare_solverhits(const void* s1, const void* s2) {
    double f = *((double*)s1);
    double s = *((double*)s2);
    if (f > s) {
        return 1;
    }
    if (f < s) {
        return -1;
    }
    return 0;
}

PMF_DEPLOY_STATIC
void nesl_sort_solverhits(PmRealVector* sh) {
    qsort((void*)sh->mX, sh->mN, sizeof(double), nesl_compare_solverhits);
    return;
}

#endif /* include guard */
