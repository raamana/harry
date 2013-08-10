/*
 * Harry - A Tool for Measuring String Similarity
 * Copyright (C) 2013 Konrad Rieck (konrad@mlsec.org)
 * --
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.  This program is distributed without any
 * warranty. See the GNU General Public License for more details. 
 */

#ifndef HARRY_H
#define HARRY_H

#define BLOCK_SIZE	4096

int harry_version(FILE *, char *, char *);

/* 
 * Basic symbol in a string 
 */
typedef uint16_t sym_t;

/**
 * Structure for a string
 */
typedef struct
{
    char *str;                /* String data (not necessary c-style) */
    sym_t *sym;		      /* Symbol representation */
    int len;                  /* Length of string */
    char *src;		      /* Optional source of string */
    size_t idx;               /* Optional index of string */
} string_t;


#define config_set_string(c,x,s) \
      config_setting_set_string(config_lookup(c,x),s)
#define config_set_int(c,x,s) \
      config_setting_set_int(config_lookup(c,x),s)
#define config_set_float(c,x,s) \
      config_setting_set_float(config_lookup(c,x),s)

#endif