#include "bpf_uring.h"

bool bpf_uring_enable(void)
{
	return false;
}
EXPORT_SYMBOL(bpf_uring_enable);
ALLOW_ERROR_INJECTION(bpf_uring_enable, TRUE);
void bpf_uring_disable(void)
{
	return;
}
EXPORT_SYMBOL(bpf_uring_disable);
int bpf_uring_prog(struct bpf_uring_ctx *ctx)
{
	return 0;
}
EXPORT_SYMBOL(bpf_uring_enable);
ALLOW_ERROR_INJECTION(bpf_uring_enable, TRUE);
