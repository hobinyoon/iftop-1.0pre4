/*
 * util.c:
 * Various utility functions.
 *
 * Copyright (c) 2002 Chris Lightfoot. All rights reserved.
 * Email: chris@ex-parrot.com; WWW: http://www.ex-parrot.com/~chris/
 *
 */

static const char rcsid[] = "$Id: util.c,v 1.1 2002/03/24 17:27:12 chris Exp $";

#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "iftop.h"

/* xmalloc:
 * Malloc, and abort if malloc fails. */
void *xmalloc(size_t n) {
    void *v;
    v = malloc(n);
    if (!v) abort();
    return v;
}

/* xcalloc:
 * As above. */
void *xcalloc(size_t n, size_t m) {
    void *v;
    v = calloc(n, m);
    if (!v) abort();
    return v;
}

/* xrealloc:
 * As above. */
void *xrealloc(void *w, size_t n) {
    void *v;
    v = realloc(w, n);
    if (n != 0 && !v) abort();
    return v;
}

/* xstrdup:
 * As above. */
char *xstrdup(const char *s) {
    char *t;
    t = strdup(s);
    if (!t) abort();
    return t;
}

/* xfree:
 * Free, ignoring a passed NULL value. */
void xfree(void *v) {
    if (v) free(v);
}

void print_cur_datetime() {
  char tmstr[20];
  time_t t;
  struct tm *lt;

  t = time(NULL);
  lt = localtime(&t);
  if (lt == NULL) {
    perror("localtime");
    exit(EXIT_FAILURE);
  }

  if (strftime(tmstr, sizeof(tmstr), "%y%m%d-%H%M%S", lt) == 0) {
    fprintf(stderr, "strftime returned 0");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", tmstr);
}

void get_cur_datetime(char* tmstr, size_t tmstr_size) {
  time_t t;
  struct tm *lt;

  t = time(NULL);
  lt = localtime(&t);
  if (lt == NULL) {
    perror("localtime");
    exit(EXIT_FAILURE);
  }

  if (strftime(tmstr, tmstr_size, "%y%m%d-%H%M%S", lt) == 0) {
    fprintf(stderr, "strftime returned 0");
    exit(EXIT_FAILURE);
  }
}
