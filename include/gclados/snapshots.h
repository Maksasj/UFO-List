#ifndef GCLADOS_SNAPSHOTS_H
#define GCLADOS_SNAPSHOTS_H

#include "gclados.h"

typedef struct {
    size_t total;
    size_t written;
    size_t updated;
    size_t failed;
    size_t passed;
} GcladosSnapshotStats;

GcladosPredicate gcladosToMatchSnapshot(size_t size);
void gcladosSetUpdateSnapshots(bool updateSnapshots);
void gcladosResetSnapshotCounter();
GcladosSnapshotStats gcladosGetSnapshotStats();

#endif
