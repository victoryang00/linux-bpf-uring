#include <linux/io_uring_types.h>
#include <linux/bpf.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/namei.h>
#include <linux/nospec.h>
#include <linux/io_uring.h>

enum ReplicaStatus { LEADER, FOLLOWER, CANDIDATE };
struct raft_ctr_state {
	enum ReplicaStatus state;
	int myIdx, leaderIdx, batchSize;
	uint64_t view, lastOp;
};

struct bpf_uring_ctx {
	char *data;
	int done;
	uint64_t next_addr[16];
	uint64_t size[16];
	struct raft_ctr_state next_state[16];
	char *scratch;
};

bool bpf_uring_enable(void);
void bpf_uring_disable(void);
int bpf_uring_prog(struct bpf_uring_ctx *ctx);
