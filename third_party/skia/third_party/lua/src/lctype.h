/*
** $Id: lctype.h,v 1.12 2011/07/15 12:50:29 roberto Exp $
** 'ctype' functions for Lua
** See Copyright Notice in lua.h
*/

#ifndef lctype_h
#define lctype_h

#include "lua.h"

<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
** WARNING: the functions defined here do not necessarily correspond
** to the similar functions in the standard C ctype.h. They are
** optimized for the specific needs of Lua
*/

#if !defined(LUA_USE_CTYPE)

#if 'A' == 65 && '0' == 48
/* ASCII case: can use its own tables; faster and fixed */
<<<<<<< HEAD
#define LUA_USE_CTYPE 0
#else
/* must use standard C ctype */
#define LUA_USE_CTYPE 1
=======
#define LUA_USE_CTYPE	0
#else
/* must use standard C ctype */
#define LUA_USE_CTYPE	1
>>>>>>> miniblink49
#endif

#endif

<<<<<<< HEAD
#if !LUA_USE_CTYPE /* { */
=======

#if !LUA_USE_CTYPE	/* { */
>>>>>>> miniblink49

#include <limits.h>

#include "llimits.h"

<<<<<<< HEAD
#define ALPHABIT 0
#define DIGITBIT 1
#define PRINTBIT 2
#define SPACEBIT 3
#define XDIGITBIT 4

#define MASK(B) (1 << (B))
=======

#define ALPHABIT	0
#define DIGITBIT	1
#define PRINTBIT	2
#define SPACEBIT	3
#define XDIGITBIT	4


#define MASK(B)		(1 << (B))

>>>>>>> miniblink49

/*
** add 1 to char to allow index -1 (EOZ)
*/
<<<<<<< HEAD
#define testprop(c, p) (luai_ctype_[(c) + 1] & (p))
=======
#define testprop(c,p)	(luai_ctype_[(c)+1] & (p))
>>>>>>> miniblink49

/*
** 'lalpha' (Lua alphabetic) and 'lalnum' (Lua alphanumeric) both include '_'
*/
<<<<<<< HEAD
#define lislalpha(c) testprop(c, MASK(ALPHABIT))
#define lislalnum(c) testprop(c, (MASK(ALPHABIT) | MASK(DIGITBIT)))
#define lisdigit(c) testprop(c, MASK(DIGITBIT))
#define lisspace(c) testprop(c, MASK(SPACEBIT))
#define lisprint(c) testprop(c, MASK(PRINTBIT))
#define lisxdigit(c) testprop(c, MASK(XDIGITBIT))
=======
#define lislalpha(c)	testprop(c, MASK(ALPHABIT))
#define lislalnum(c)	testprop(c, (MASK(ALPHABIT) | MASK(DIGITBIT)))
#define lisdigit(c)	testprop(c, MASK(DIGITBIT))
#define lisspace(c)	testprop(c, MASK(SPACEBIT))
#define lisprint(c)	testprop(c, MASK(PRINTBIT))
#define lisxdigit(c)	testprop(c, MASK(XDIGITBIT))
>>>>>>> miniblink49

/*
** this 'ltolower' only works for alphabetic characters
*/
<<<<<<< HEAD
#define ltolower(c) ((c) | ('A' ^ 'a'))
=======
#define ltolower(c)	((c) | ('A' ^ 'a'))

>>>>>>> miniblink49

/* two more entries for 0 and -1 (EOZ) */
LUAI_DDEC const lu_byte luai_ctype_[UCHAR_MAX + 2];

<<<<<<< HEAD
#else /* }{ */
=======

#else			/* }{ */
>>>>>>> miniblink49

/*
** use standard C ctypes
*/

#include <ctype.h>

<<<<<<< HEAD
#define lislalpha(c) (isalpha(c) || (c) == '_')
#define lislalnum(c) (isalnum(c) || (c) == '_')
#define lisdigit(c) (isdigit(c))
#define lisspace(c) (isspace(c))
#define lisprint(c) (isprint(c))
#define lisxdigit(c) (isxdigit(c))

#define ltolower(c) (tolower(c))

#endif /* } */

#endif
=======

#define lislalpha(c)	(isalpha(c) || (c) == '_')
#define lislalnum(c)	(isalnum(c) || (c) == '_')
#define lisdigit(c)	(isdigit(c))
#define lisspace(c)	(isspace(c))
#define lisprint(c)	(isprint(c))
#define lisxdigit(c)	(isxdigit(c))

#define ltolower(c)	(tolower(c))

#endif			/* } */

#endif

>>>>>>> miniblink49
