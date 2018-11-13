#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef	PATH_MAX
static long	pathmax = PATH_MAX;//如果<limits.h>中定义了常量PATH_MAX，则没有问题。
#else
static long	pathmax = 0;
#endif

static long	posix_version = 0;
static long	xsi_version = 0;

/* If PATH_MAX is indeterminate, no guarantee this is adequate */
#define	PATH_MAX_GUESS	1024

char *
path_alloc(size_t *sizep) /* also return allocated size, if nonnull */
{
	char	*ptr;
	size_t	size;

	if (posix_version == 0)
		posix_version = sysconf(_SC_VERSION);

	if (xsi_version == 0)
		xsi_version = sysconf(_SC_XOPEN_VERSION);
		//如果<limits.h>未定义PATH_MAX，需调用pathconf。
	if (pathmax == 0) {		/* first time through */
		errno = 0;
		//pathconf返回值基于工作目录的相对路径名的最大长度，而工作目录时其第一个参数，所以指定根目录为第一个参数
		if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) {
			if (errno == 0)
				//如果pathconf指明PATH_MAX是不确定的，则只能猜测
				pathmax = PATH_MAX_GUESS;	/* it's indeterminate */
			else
				err_sys("pathconf error for _PC_PATH_MAX");
		} else {
			//将得到的返回值加1作为结果值
			pathmax++;		/* add one since it's relative to root */
		}
	}

	/*
	 * Before POSIX.1-2001, we aren't guaranteed that PATH_MAX includes
	 * the terminating null byte.  Same goes for XPG3.
	 */
	/* 出于安全的考虑，如果操作系统的实现符合某个先前版本的标准，但并不符合
	 * Single UNIX Speification（SUS明确要求在结尾处加一个终止null字节）
	 * 的任何版本，则需要在为路径名分配的存储量上加1. 
	 */
	if ((posix_version < 200112L) && (xsi_version < 4))
		size = pathmax + 1;
	else
		size = pathmax;

	if ((ptr = malloc(size)) == NULL)
		err_sys("malloc error for pathname");

	if (sizep != NULL)
		*sizep = size;
	return(ptr);
}
