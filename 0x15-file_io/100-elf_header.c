#include "main.h"

void checker(Elf64_Ehdr *header);
void elf_class(Elf64_Ehdr *header);
void elf_data(Elf64_Ehdr *header);
void elf_version(Elf64_Ehdr *header);
void elf_op(Elf64_Ehdr *header);
void abi(Elf64_Ehdr *header);
void elf_type(Elf64_Ehdr *header);
void epa(Elf64_Ehdr *header);

/**
 * main - displays the information contained in the ELF header at the start of an ELF file.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 * Return: If successful - 0.
 * Otherwise - The status code.
*/
int main(int __attribute__((__unused__)) argc, char **argv)
{
	int fd;
	Elf64_Ehdr *header;
	header = malloc(sizeof(Elf64_Ehdr));

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
	if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Unable to read ELF header.\n");
		return (98);
	}

	checker(header);
	printf("ELF Header:\n");
	elf_class(header);
	elf_data(header);
	elf_version(header);
	elf_op(header);
	abi(header);
	elf_type(header);
	epa(header);

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}

	return (0);
}

/**
 * checker - if file is Elf
 * @header: pointer to the ELF header
 *
 * Return: void
*/
void checker(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] != 0x7f ||
		header->e_ident[EI_MAG1] != 'E' ||
		header->e_ident[EI_MAG2] != 'L' ||
		header->e_ident[EI_MAG3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: File is not an ELF file.\n");
		exit(98);
	}
}

/**
 * elf_class - prints the cmagic of an ELF file
 * @header: pointer to the ELF header
 *
 * Return: void
 */
void magical(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
}

/**
 * elf_class - prints the class of an ELF file
 * @header: pointer to the ELF header
 *
 * Return: void
 */
void elf_class(Elf64_Ehdr *header)
{
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("Invalid class\n");
	}
}

/**
 * elf_data - prints the data encoding of an ELF file
 * @header: pointer to the ELF header
 *
 * Return: void
 */
void elf_data(Elf64_Ehdr *header)
{
	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Invalid data encoding\n");
	}
}

/**
 * elf_version - prints the version of an ELF file
 * @header: pointer to the ELF header
 *
 * Return: void
 */
void elf_version(Elf64_Ehdr *header)
{
	printf("  Version:                           ");
	switch (header->e_ident[EI_VERSION])
	{
	case EV_NONE:
		printf("Invalid version\n");
		break;
	case EV_CURRENT:
		printf("%d (current)\n", EV_CURRENT);
		break;
	default:
		printf("%d\n", header->e_ident[EI_VERSION]);
	}
}

/**
 * elf_op - prints the operating system and ABI of an ELF file
 * @header: pointer to the ELF header
 *
 * Return: void
 */
void elf_op(Elf64_Ehdr *header)
{
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("Compaq TRU64 UNIX\n");
		break;
	case ELFOSABI_ARM_AEABI:
		printf("ARM EABI\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone (embedded) application\n");
		break;
	default:
		printf("Unknown\n");
	}
}

/**
 * abi - prints the ABI version of an ELF file
 * @header: pointer to the ELF header
 *
 * Return: void
 */
void abi(Elf64_Ehdr *header)
{
	printf("  ABI Version:                       ");
	printf("%d\n", header->e_ident[EI_ABIVERSION]);
}

/**
 * elf_type - prints the type of an ELF file
 * @header: pointer to the ELF header
 *
 * Return: void
 */
void elf_type(Elf64_Ehdr *header)
{
	printf("  Type:                              ");
	switch (header->e_type)
	{
	case ET_NONE:
		printf("No file type\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("Exec (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("Unknown type\n");
	}
}

/**
 * epa - prints the entry point address of an ELF file
 * @header: pointer to the ELF header
 *
 * Return: void
 */
void epa(Elf64_Ehdr *header)
{
	printf("  Entry point address:               ");
	
	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		header->e_entry = ((header->e_entry << 8) & 0xFF00FF00) | ((header->e_entry >> 8) & 0xFF00FF);
		header->e_entry = (header->e_entry << 16) | (header->e_entry >> 16);
	}
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)header->e_entry);
	else
		printf("%#lx\n", header->e_entry);
}

