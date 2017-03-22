#define EXITNO 23
const char *str = "Hello world\n";

#ifdef __x86_64__
void m_print()
{
    asm volatile(
        "syscall"
        :
        :"a"(1), "D"(0), "S"(str), "d"(12)
        );
}

void m_exit()
{
    asm volatile(
        "syscall"
        :
        :"a"(60), "D"(EXITNO)
        );
}
#else
void m_print()
{
    asm volatile(
        "int $0x80"
        :
        :"a"(4), "b"(0), "c"(str), "d"(13)
        );
}

void m_exit()
{
    asm volatile(
        "int $0x80"
        :
        :"a"(1), "b"(EXITNO)
        );
}
#endif

int main()
{
    m_print();
    m_exit();
}
