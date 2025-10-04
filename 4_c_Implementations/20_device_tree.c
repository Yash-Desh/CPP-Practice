// Let’s say we have thread1-threadN pinned on core1-coreN, respectively.

// What’s the potential performance problem with the following code?

int per_thread_integers[NUM_THREADS];

void thread_function(int index) {
    while (true) {
        per_thread_integers[index]++;
    }
}

// solution : 
// false-sharing due to core pinning & continuous cache invalidations
// overflow 
// compiler might optimize & keep the updated value in the register until forced to write-back

//--------

struct {
    int integer;
    uint8_t _padding[CACHE_LINE_SIZE - sizeof(int)];
} per_thread_integers[NUM_THREADS];

void thread_function(int index) {
    while (true) {
        per_thread_integers[index].integer++;
    }
}

// Comments: The struct size is one cache line but its alignment isn't guaranteed to start 
// at the start of a cache line

//------------------------

// The devicetree is an important data structure in kernel programming. The kernel uses it to understand 
// the hardware environment in the system it’s running on.

// For our purposes, the devicetree is nothing more than a tree of nodes where each node has a name (e.g., “uart@fe001000”) 
// and a list of properties. Each property has a name (e.g., “compatible”) and a value (e.g., “ns16550”). 
// The “phandle” property is special in that it’s present on all nodes and gives each node a globally unique identifier.

// In our simplified scenario, values can either be strings (e.g., “fsl,mpc8572ds”) or 
// arrays of unsigned 32-bit integers (e.g., <0xfe001000 0x100>).

//                                                                     ┌──────────────────────────────────┐
//                                                                     │ cpu@0                            │
//                                                                  ┌─►├──────────────────────────────────┤
//                                                                  │  │ phandle            = <7>         │
//                                                                  │  │ device_type        = "cpu"       │
//                                                                  │  │ reg                = <0>         │
//                                                                  │  │ timebase-frequency = <825000000> │
//                                                                  │  │ clock-frequency    = <825000000> │
//                                         ┌──────────────────────┐ │  └──────────────────────────────────┘
//                                         │ cpus                 │ │
//                                      ┌─►├──────────────────────┼─┤  ┌──────────────────────────────────┐
//                                      │  │ phandle        = <2> │ │  │ cpu@1                            │
//                                      │  │ #address-cells = <1> │ └─►├──────────────────────────────────┤
//                                      │  │ #size-cells    = <0> │    │ phandle            = <8>         │
//                                      │  └──────────────────────┘    │ device_type        = "cpu"       │
//                                      │                              │ reg                = <1>         │
//                                      │                              │ timebase-frequency = <825000000> │
//                                      │                              │ clock-frequency    = <825000000> │
//                                      │                              └──────────────────────────────────┘
//                                      │
//                                      │  ┌──────────────────────────────┐
//                                      │  │ memory@0                     │
//                                      ├─►├──────────────────────────────┤
//                                      │  │ phandle     = <3>            │
//                                      │  │ device_type = "memory"       │
// ┌──────────────────────────────────┐ │  │ reg         = <0 0x20000000> │
// │ /                                │ │  └──────────────────────────────┘
// ├──────────────────────────────────┼─┤
// │ phandle        = <1>             │ │  ┌─────────────────────────────────┐
// │ model          = "fsl,mpc8572ds" │ │  │ uart@fe001000                   │
// │ compatible     = "fsl,mpc8572ds" │ ├─►├─────────────────────────────────┤
// │ #address-cells = <1>             │ │  │ phandle    = <4>                │
// │ #size-cells    = <1>             │ │  │ compatible = "ns16550"          │
// └──────────────────────────────────┘ │  │ reg        = <0xfe001000 0x100> │
//                                      │  └─────────────────────────────────┘
//                                      │
//                                      │  ┌─────────────────────────────┐
//                                      │  │ chosen                      │
//                                      ├─►├─────────────────────────────┤
//                                      │  │ phandle  = <5>              │
//                                      │  │ bootargs = "root=/dev/sda2" │
//                                      │  └─────────────────────────────┘
//                                      │
//                                      │  ┌────────────────────────────┐
//                                      │  │ aliases                    │
//                                      └─►├────────────────────────────┤
//                                         │ phandle = <6>              │
//                                         │ serial0 = "/uart@fe001000" │
//                                         └────────────────────────────┘

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Represents a single node in the devicetree.
 */
typedef struct devicetree_node {
  char *name;
  size_t n_properties;
  struct {
    char *name;
    size_t data_bytes;
    void *data;
  } *properties;
  size_t n_children;
  struct devicetree_node **children;
} devicetree_node_t;

/**
 * @brief A pointer to the root node of the devicetree.
 */
static const devicetree_node_t *const root;


devicetree_node_t *devicetree_find_node_with_phandle_helper(devicetree_node_t * curr, uint32_t phandle) {
  devicetree_node_t * recursive_node;
  for (int i = 0; i < curr->n_properties; i++) {
    if (!strncmp("phandle", (curr->properties[i].name), strlen("phandle")) && *(uint32_t *)curr->properties[i].data == phandle) {
      return curr;
    }
  }
  if (curr->n_children == 0) {
    return NULL;
  }
  // else
  for (int i = 0; i < curr->n_children; i++) {
    recursive_node = devicetree_find_node_with_phandle_helper(curr->children[i], phandle);
    if (recursive_node != NULL) {
      return recursive_node;
    }
  }

  // Correction : he hadn't added this.
  return NULL;
}

/**
 * @brief Finds the node in the devicetree with the given phandle.
 *
 * @return A pointer to the matching node or NULL if not found.
 */
devicetree_node_t *devicetree_find_node_with_phandle(uint32_t phandle) {
  // TODO
  return devicetree_find_node_with_phandle_helper(root, phandle);
}
