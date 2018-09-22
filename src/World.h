#ifndef _NODES_H
#define _NODES_H

#include "Node.h"

#define MAX_NODES 50
typedef Node* NodePtr;

class World {

    // the array holding all nodes
    NodePtr nodes[MAX_NODES];

    public:

    void addNode(Node* node) {
        // iterate over node array to find first empty slot
        for (uint16_t i=0; i<MAX_NODES; i++) {
            if (nodes[i] == NULL) {
                nodes[i] = node;
                break;
            }
        }
    }

    void cleanup() {
        // iterate over node array and remove "dead" nodes
        for (uint16_t i=0; i<MAX_NODES; i++) {
            if (nodes[i] != NULL && nodes[i]->dead()) {
                delete nodes[i];
                nodes[i] = NULL;
            }
        }
    }

    void tick() {
        for(uint16_t i=0; i<MAX_NODES; i++) {
            if (nodes[i] != NULL) {
                nodes[i]->tick();
            }
        }
    }

    void render(CRGB frameBuffer[NUM_PIXELS]) {
        for(uint16_t i=0; i<MAX_NODES; i++) {
            if (nodes[i] != NULL) {
                nodes[i]->render(frameBuffer);
            }
        }
    }

};

#endif