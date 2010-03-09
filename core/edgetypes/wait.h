//---------------DECLARATIONS FOR WAIT CLASS------------------------

typedef struct Wait {
    edgepayload_t type;
    State* (*walk)(struct EdgePayload*, struct State*, struct WalkOptions*);
    State* (*walkBack)(struct EdgePayload*, struct State*, struct WalkOptions*);
    
    long end;
    Timezone* timezone;
} Wait;

Wait*
waitNew(long end, Timezone* timezone);

void
waitDestroy(Wait* tokill);

inline State*
waitWalk(EdgePayload* superthis, State* param, WalkOptions* options);

inline State*
waitWalkBack(EdgePayload* superthis, State* param, WalkOptions* options);

long
waitGetEnd(Wait* this);

Timezone*
waitGetTimezone(Wait* this);