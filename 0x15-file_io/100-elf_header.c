#include "main.h"

/**
 * main - displays the information contained in the ELF header
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
    int fd;
    int i;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        return (98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Unable to read file '%s'.\n", argv[1]);
        return (98);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: Unable to read ELF header.\n");
        return (98);
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file.\n");
        return (98);
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");

    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x%s", header.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
    printf("  Class:                             %s\n",
           header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64"
                                                                                                     : "none");
    printf("  Data:                              %s\n",
           header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian"
                                                                                                                             : "none");
    printf("  Version:                           %d%s\n",
           header.e_ident[EI_VERSION], header.e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
    printf("  OS/ABI:                            %s\n",
           header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : header.e_ident[EI_OSABI] == ELFOSABI_HPUX     ? "UNIX - HP-UX"
                                                                       : header.e_ident[EI_OSABI] == ELFOSABI_NETBSD     ? "UNIX - NetBSD"
                                                                       : header.e_ident[EI_OSABI] == ELFOSABI_LINUX      ? "UNIX - GNU"
                                                                       : header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS    ? "UNIX - Solaris"
                                                                       : header.e_ident[EI_OSABI] == ELFOSABI_IRIX       ? "UNIX - IRIX"
                                                                       : header.e_ident[EI_OSABI] == ELFOSABI_FREEBSD    ? "UNIX - FreeBSD"
                                                                       : header.e_ident[EI_OSABI] == ELFOSABI_TRU64      ? "UNIX - TRU64"
                                                                       : header.e_ident[EI_OSABI] == ELFOSABI_ARM        ? "ARM"
                                                                       : header.e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone App"
                                                                                                                         : "Unknown");

    printf("  ABI Version:                       %d\n",
           header.e_ident[EI_ABIVERSION]);

    printf("  Type:                              %s\n",
           header.e_type == ET_NONE ? "NONE (Unknown)" : header.e_type == ET_REL ? "REL (Relocatable file)"
                                                     : header.e_type == ET_EXEC  ? "EXEC (Executable file)"
                                                     : header.e_type == ET_DYN   ? "DYN (Shared object file)"
                                                     : header.e_type == ET_CORE  ? "CORE (Core file)"
                                                                                 : "Unknown");

    printf("  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);

    printf("  Start of program headers:          %lu (bytes into file)\n", (unsigned long)header.e_phoff);

    printf("  Start of section headers:          %lu (bytes into file)\n", (unsigned long)header.e_shoff);

    printf("  Flags:                             0x%x\n", header.e_flags);

    printf("  Size of this header:               %d (bytes)\n", header.e_ehsize);

    printf("  Size of program headers:           %d (bytes)\n", header.e_phentsize);

    printf("  Number of program headers:         %d\n", header.e_phnum);

    printf("  Size of section headers:           %d (bytes)\n", header.e_shentsize);

    printf("  Number of section headers:         %d\n", header.e_shnum);

    printf("  Section header string table index: %d\n", header.e_shstrndx);

    close(fd);

    return (EXIT_SUCCESS);
}
