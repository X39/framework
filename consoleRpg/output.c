# 1 ".\\map\\entity.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 ".\\map\\entity.c"
# 1 ".\\map\\entity.h" 1
       

typedef struct
{
 int id;
} entity;

void entity_destroy(entity*);






# 1 ".\\map\\../generic/g_list.h.txt" 1
# 19 ".\\map\\../generic/g_list.h.txt"
# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stdbool.h" 1 3 4
# 20 ".\\map\\../generic/g_list.h.txt" 2
# 28 ".\\map\\../generic/g_list.h.txt"
typedef struct {
    entity* * data;
    unsigned int top;
    unsigned int size;
} entitylist;

typedef entitylist * p_entitylist;

p_entitylist entitylist_create(void);
void entitylist_destroy(p_entitylist);

# 38 ".\\map\\../generic/g_list.h.txt" 3 4
_Bool 
# 38 ".\\map\\../generic/g_list.h.txt"
    entitylist_grow(p_entitylist);

# 39 ".\\map\\../generic/g_list.h.txt" 3 4
_Bool 
# 39 ".\\map\\../generic/g_list.h.txt"
    entitylist_shrink(p_entitylist);

# 40 ".\\map\\../generic/g_list.h.txt" 3 4
_Bool 
# 40 ".\\map\\../generic/g_list.h.txt"
    entitylist_push(p_entitylist, entity*);

# 41 ".\\map\\../generic/g_list.h.txt" 3 4
_Bool 
# 41 ".\\map\\../generic/g_list.h.txt"
    entitylist_pop(p_entitylist, entitylist *);
# 16 ".\\map\\entity.h" 2
# 2 ".\\map\\entity.c" 2





# 1 ".\\map\\../generic/g_list.c.txt" 1







# 1 "c:\\mingw\\include\\malloc.h" 1 3





# 1 "c:\\mingw\\include\\_ansi.h" 1 3
# 15 "c:\\mingw\\include\\_ansi.h" 3
# 1 "c:\\mingw\\include\\newlib.h" 1 3
# 14 "c:\\mingw\\include\\newlib.h" 3
# 1 "c:\\mingw\\include\\_newlib_version.h" 1 3
# 15 "c:\\mingw\\include\\newlib.h" 2 3
# 16 "c:\\mingw\\include\\_ansi.h" 2 3
# 1 "c:\\mingw\\include\\sys\\config.h" 1 3



# 1 "c:\\mingw\\include\\machine\\ieeefp.h" 1 3
# 5 "c:\\mingw\\include\\sys\\config.h" 2 3
# 1 "c:\\mingw\\include\\sys\\features.h" 1 3
# 6 "c:\\mingw\\include\\sys\\config.h" 2 3
# 17 "c:\\mingw\\include\\_ansi.h" 2 3
# 7 "c:\\mingw\\include\\malloc.h" 2 3
# 1 "c:\\mingw\\include\\sys\\reent.h" 1 3
# 14 "c:\\mingw\\include\\sys\\reent.h" 3
# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 1 3 4
# 149 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4

# 149 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4
typedef int ptrdiff_t;
# 216 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4
typedef unsigned int size_t;
# 328 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4
typedef short unsigned int wchar_t;
# 426 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
# 15 "c:\\mingw\\include\\sys\\reent.h" 2 3
# 1 "c:\\mingw\\include\\sys\\_types.h" 1 3
# 24 "c:\\mingw\\include\\sys\\_types.h" 3
# 1 "c:\\mingw\\include\\machine\\_types.h" 1 3





# 1 "c:\\mingw\\include\\machine\\_default_types.h" 1 3
# 41 "c:\\mingw\\include\\machine\\_default_types.h" 3
typedef signed char __int8_t;

typedef unsigned char __uint8_t;
# 55 "c:\\mingw\\include\\machine\\_default_types.h" 3
typedef short int __int16_t;

typedef short unsigned int __uint16_t;
# 77 "c:\\mingw\\include\\machine\\_default_types.h" 3
typedef int __int32_t;

typedef unsigned int __uint32_t;
# 103 "c:\\mingw\\include\\machine\\_default_types.h" 3
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;
# 134 "c:\\mingw\\include\\machine\\_default_types.h" 3
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;
# 160 "c:\\mingw\\include\\machine\\_default_types.h" 3
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;
# 182 "c:\\mingw\\include\\machine\\_default_types.h" 3
typedef int __int_least32_t;

typedef unsigned int __uint_least32_t;
# 200 "c:\\mingw\\include\\machine\\_default_types.h" 3
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;
# 214 "c:\\mingw\\include\\machine\\_default_types.h" 3
typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 7 "c:\\mingw\\include\\machine\\_types.h" 2 3
# 17 "c:\\mingw\\include\\machine\\_types.h" 3
typedef __int64_t __blkcnt_t;


typedef __int32_t __blksize_t;


typedef __uint32_t __dev_t;



typedef unsigned long __fsblkcnt_t;



typedef unsigned long __fsfilcnt_t;


typedef __uint32_t __uid_t;


typedef __uint32_t __gid_t;


typedef __uint64_t __ino_t;


typedef long long __key_t;


typedef __uint16_t __sa_family_t;



typedef int __socklen_t;
# 25 "c:\\mingw\\include\\sys\\_types.h" 2 3
# 1 "c:\\mingw\\include\\sys\\lock.h" 1 3
# 12 "c:\\mingw\\include\\sys\\lock.h" 3
typedef void *_LOCK_T;
# 42 "c:\\mingw\\include\\sys\\lock.h" 3
void __cygwin_lock_init(_LOCK_T *);
void __cygwin_lock_init_recursive(_LOCK_T *);
void __cygwin_lock_fini(_LOCK_T *);
void __cygwin_lock_lock(_LOCK_T *);
int __cygwin_lock_trylock(_LOCK_T *);
void __cygwin_lock_unlock(_LOCK_T *);
# 26 "c:\\mingw\\include\\sys\\_types.h" 2 3
# 44 "c:\\mingw\\include\\sys\\_types.h" 3
typedef long _off_t;





typedef int __pid_t;
# 65 "c:\\mingw\\include\\sys\\_types.h" 3
typedef __uint32_t __id_t;
# 88 "c:\\mingw\\include\\sys\\_types.h" 3
typedef __uint32_t __mode_t;





__extension__ typedef long long _off64_t;





typedef _off_t __off_t;


typedef _off64_t __loff_t;
# 114 "c:\\mingw\\include\\sys\\_types.h" 3
typedef long _fpos_t;
# 129 "c:\\mingw\\include\\sys\\_types.h" 3
typedef unsigned int __size_t;
# 145 "c:\\mingw\\include\\sys\\_types.h" 3
typedef signed int _ssize_t;
# 156 "c:\\mingw\\include\\sys\\_types.h" 3
typedef _ssize_t __ssize_t;


# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 1 3 4
# 357 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4
typedef short unsigned int wint_t;
# 160 "c:\\mingw\\include\\sys\\_types.h" 2 3



typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;



typedef _LOCK_T _flock_t;




typedef void *_iconv_t;






typedef unsigned long __clock_t;


typedef long __time_t;


typedef unsigned long __clockid_t;


typedef unsigned long __timer_t;
# 206 "c:\\mingw\\include\\sys\\_types.h" 3
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;




typedef char * __va_list;
# 16 "c:\\mingw\\include\\sys\\reent.h" 2 3






typedef unsigned long __ULong;
# 38 "c:\\mingw\\include\\sys\\reent.h" 3
struct _reent;

struct __locale_t;






struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};


struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};







struct _on_exit_args {
 void * _fnargs[32];
 void * _dso_handle[32];

 __ULong _fntypes;


 __ULong _is_cxa;
};
# 93 "c:\\mingw\\include\\sys\\reent.h" 3
struct _atexit {
 struct _atexit *_next;
 int _ind;

 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
# 117 "c:\\mingw\\include\\sys\\reent.h" 3
struct __sbuf {
 unsigned char *_base;
 int _size;
};
# 181 "c:\\mingw\\include\\sys\\reent.h" 3
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;






  void * _cookie;

  int (* _read) (struct _reent *, void *, char *, int)
                                          ;
  int (* _write) (struct _reent *, void *, const char *, int)

                                   ;
  _fpos_t (* _seek) (struct _reent *, void *, _fpos_t, int);
  int (* _close) (struct _reent *, void *);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  _off_t _offset;


  struct _reent *_data;



  _flock_t _lock;

  _mbstate_t _mbstate;
  int _flags2;
};
# 287 "c:\\mingw\\include\\sys\\reent.h" 3
typedef struct __sFILE __FILE;



struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
# 319 "c:\\mingw\\include\\sys\\reent.h" 3
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};
# 569 "c:\\mingw\\include\\sys\\reent.h" 3
struct _reent
{
  int _errno;




  __FILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];


  int _unspecified_locale_info;
  struct __locale_t *_locale;

  int __sdidinit;

  void (* __cleanup) (struct _reent *);


  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;


  int _cvtlen;
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
   int _h_errno;
        } _reent;



      struct
        {

          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;



  struct _atexit *_atexit;
  struct _atexit _atexit0;



  void (**(_sig_func))(int);




  struct _glue __sglue;

  __FILE __sf[3];

};
# 775 "c:\\mingw\\include\\sys\\reent.h" 3
extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;

void _reclaim_reent (struct _reent *);
# 8 "c:\\mingw\\include\\malloc.h" 2 3


# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 1 3 4
# 11 "c:\\mingw\\include\\malloc.h" 2 3


# 1 "c:\\mingw\\include\\machine\\malloc.h" 1 3
# 14 "c:\\mingw\\include\\malloc.h" 2 3
# 22 "c:\\mingw\\include\\malloc.h" 3
struct mallinfo {
  size_t arena;
  size_t ordblks;
  size_t smblks;
  size_t hblks;
  size_t hblkhd;
  size_t usmblks;
  size_t fsmblks;
  size_t uordblks;
  size_t fordblks;
  size_t keepcost;
};



extern void * malloc (size_t);




extern void * _malloc_r (struct _reent *, size_t);


extern void free (void *);




extern void _free_r (struct _reent *, void *);


extern void * realloc (void *, size_t);




extern void * _realloc_r (struct _reent *, void *, size_t);


extern void * calloc (size_t, size_t);




extern void * _calloc_r (struct _reent *, size_t, size_t);


extern void * memalign (size_t, size_t);




extern void * _memalign_r (struct _reent *, size_t, size_t);


extern struct mallinfo mallinfo (void);




extern struct mallinfo _mallinfo_r (struct _reent *);


extern void malloc_stats (void);




extern void _malloc_stats_r (struct _reent *);


extern int mallopt (int, int);




extern int _mallopt_r (struct _reent *, int, int);


extern size_t malloc_usable_size (void *);




extern size_t _malloc_usable_size_r (struct _reent *, void *);





extern void * valloc (size_t);




extern void * _valloc_r (struct _reent *, size_t);


extern void * pvalloc (size_t);




extern void * _pvalloc_r (struct _reent *, size_t);


extern int malloc_trim (size_t);




extern int _malloc_trim_r (struct _reent *, size_t);




extern void mstats (char *);




extern void _mstats_r (struct _reent *, char *);
# 162 "c:\\mingw\\include\\malloc.h" 3
extern void cfree (void *);
# 9 ".\\map\\../generic/g_list.c.txt" 2


# 10 ".\\map\\../generic/g_list.c.txt"
p_entitylist entitylist_create(void)
{
 p_entitylist list = malloc(sizeof(entitylist));
 if (list == 
# 13 ".\\map\\../generic/g_list.c.txt" 3 4
            ((void *)0)
# 13 ".\\map\\../generic/g_list.c.txt"
                )
 {
  return 
# 15 ".\\map\\../generic/g_list.c.txt" 3 4
        ((void *)0)
# 15 ".\\map\\../generic/g_list.c.txt"
            ;
 }
 list->top = 0;
 list->size = 0;
 list->data = 0;
 return list;
}
void entitylist_destroy(p_entitylist list)
{
 if (list == 
# 24 ".\\map\\../generic/g_list.c.txt" 3 4
            ((void *)0)
# 24 ".\\map\\../generic/g_list.c.txt"
                )
 {
  return;
 }
    for (int i = 0; i < list->top; i++) free(entity_destroy(list->data[i]));;
 if (list->size > 0)
 {
  free(list->data);
 }
 free(list);
 return 
# 34 ".\\map\\../generic/g_list.c.txt" 3 4
       1
# 34 ".\\map\\../generic/g_list.c.txt"
           ;
}

# 36 ".\\map\\../generic/g_list.c.txt" 3 4
_Bool 
# 36 ".\\map\\../generic/g_list.c.txt"
    entitylist_grow(p_entitylist list)
{
 entity* * tmp;
 unsigned int newsize = list->size * 2;
 if (newsize < list->size)
 {
  return 
# 42 ".\\map\\../generic/g_list.c.txt" 3 4
        0
# 42 ".\\map\\../generic/g_list.c.txt"
             ;
 }
 if (list->size == 0)
 {
  list->data = malloc(sizeof(entity*));
  if (list->data == 
# 47 ".\\map\\../generic/g_list.c.txt" 3 4
                   ((void *)0)
# 47 ".\\map\\../generic/g_list.c.txt"
                       )
  {
   return 
# 49 ".\\map\\../generic/g_list.c.txt" 3 4
         0
# 49 ".\\map\\../generic/g_list.c.txt"
              ;
  }
  list->size = 1;
  return 
# 52 ".\\map\\../generic/g_list.c.txt" 3 4
        1
# 52 ".\\map\\../generic/g_list.c.txt"
            ;
 }
 else
 {
  tmp = realloc(list->data, sizeof(entity*) * newsize);
  if (tmp == 
# 57 ".\\map\\../generic/g_list.c.txt" 3 4
            ((void *)0)
# 57 ".\\map\\../generic/g_list.c.txt"
                )
  {
   return 
# 59 ".\\map\\../generic/g_list.c.txt" 3 4
         0
# 59 ".\\map\\../generic/g_list.c.txt"
              ;
  }
  list->data = tmp;
  list->size = newsize;
  return 
# 63 ".\\map\\../generic/g_list.c.txt" 3 4
        1
# 63 ".\\map\\../generic/g_list.c.txt"
            ;
 }
}

# 66 ".\\map\\../generic/g_list.c.txt" 3 4
_Bool 
# 66 ".\\map\\../generic/g_list.c.txt"
    entitylist_shrink(p_entitylist list)
{
 entity* * tmp;
 if (list->size == 0)
 {
  return 
# 71 ".\\map\\../generic/g_list.c.txt" 3 4
        1
# 71 ".\\map\\../generic/g_list.c.txt"
            ;
 }
 else
 {
  tmp = realloc(list->data, sizeof(entity*) * list->top);
  if (tmp == 
# 76 ".\\map\\../generic/g_list.c.txt" 3 4
            ((void *)0)
# 76 ".\\map\\../generic/g_list.c.txt"
                )
  {
   return 
# 78 ".\\map\\../generic/g_list.c.txt" 3 4
         0
# 78 ".\\map\\../generic/g_list.c.txt"
              ;
  }
  list->data = tmp;
  list->size = list->top;
  return 
# 82 ".\\map\\../generic/g_list.c.txt" 3 4
        1
# 82 ".\\map\\../generic/g_list.c.txt"
            ;
 }
}

# 85 ".\\map\\../generic/g_list.c.txt" 3 4
_Bool 
# 85 ".\\map\\../generic/g_list.c.txt"
    entitylist_push(p_entitylist list, entity* val)
{
 if (list->top == list->size && !entitylist_grow(list))
 {
  return 
# 89 ".\\map\\../generic/g_list.c.txt" 3 4
        0
# 89 ".\\map\\../generic/g_list.c.txt"
             ;
 }
 list->data[list->top] = val;
 list->top++;
 return 
# 93 ".\\map\\../generic/g_list.c.txt" 3 4
       1
# 93 ".\\map\\../generic/g_list.c.txt"
           ;
}

# 95 ".\\map\\../generic/g_list.c.txt" 3 4
_Bool 
# 95 ".\\map\\../generic/g_list.c.txt"
    entitylist_pop(p_entitylist list, entity* * out)
{
 if (list->top == 0)
 {
  return 
# 99 ".\\map\\../generic/g_list.c.txt" 3 4
        0
# 99 ".\\map\\../generic/g_list.c.txt"
             ;
 }
    if (out)
    {
        *out = list->data[list->top--];
    }
    return 
# 105 ".\\map\\../generic/g_list.c.txt" 3 4
          1
# 105 ".\\map\\../generic/g_list.c.txt"
              ;
}
# 8 ".\\map\\entity.c" 2
