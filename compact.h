/*	compact.h	4.6	84/08/25	*/

#if defined(vax) || defined(sun)
typedef int longint;
#else
typedef long longint;
#endif

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef _MSC_VER
/* Microsoft Visual C 6.0 / Win32 compatibility. */
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/utime.h>
#ifndef MAXPATHLEN
#define MAXPATHLEN _MAX_PATH
#endif
#ifndef MAXNAMLEN
#define MAXNAMLEN 255
#endif
#ifndef S_IFMT
#define S_IFMT _S_IFMT
#endif
#ifndef S_IFREG
#define S_IFREG _S_IFREG
#endif
#define index strchr
#define rindex strrchr
#define stat _stat
#define fstat _fstat
#define fileno _fileno
#define fchmod(fd, mode) ((void)(fd), (void)(mode), 0)
#define unlink _unlink
#else
#include <sys/param.h>
#include <sys/dir.h>
#endif

#define COMPACTED 017777
#define PACKED	017437

struct charac {
#if defined(vax) || defined(pdp11)
	char	lob, hib;
#else
	char	hib, lob;
#endif
};

union cio {
	struct	charac chars;
	short	integ;
};

#define LLEAF	010
#define RLEAF	04
#define SEEN	02
#define FBIT	01

#define EF	0400
#define NC	0401

#define	NF	(NC+1)

struct fpoint {
	struct	node *fp;
	int	flags;
} in[NF];

struct index {
	struct	node *pt;
	struct	index *next;
} dir[2*NF], *head, *flist, *dirp, *dirq;

#define	NEW	flist; flist = flist->next

union treep {
	struct	node *p;
	int	ch;
};

struct node {
	struct	fpoint fath;
	struct son {
		union	treep sp;
		struct	index *top;
		longint	count;
	} sons[2];
#define	LEFT	0
#define	RIGHT	1
} dict[NF], *bottom;

FILE	*cfp;
FILE	*uncfp;
