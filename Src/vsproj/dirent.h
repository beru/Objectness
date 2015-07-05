#ifndef DIRENT_INCLUDED
#define DIRENT_INCLUDED

/*

    Declaration of POSIX directory browsing functions and types for Win32.

    Author:  Kevlin Henney (kevlin@acm.org, kevlin@curbralan.com)
    History: Created March 1997. Updated June 2003.
    Rights:  See end of file.
    
*/

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct DIR DIR;

struct dirent {
//    ino_t          d_ino;       /* inode 番号 */
//    off_t          d_off;       /* オフセットではない; 注意を参照 */
    unsigned short d_reclen;    /* このレコードの長さ */
    unsigned char  d_type;      /* ファイル種別。全ファイルシステム
                                   でサポートされているわけではない */
    char *d_name;				/* ファイル名 */
};

DIR           *opendir(const char *);
int           closedir(DIR *);
struct dirent *readdir(DIR *);
void          rewinddir(DIR *);

/*

    Copyright Kevlin Henney, 1997, 2003. All rights reserved.

    Permission to use, copy, modify, and distribute this software and its
    documentation for any purpose is hereby granted without fee, provided
    that this copyright and permissions notice appear in all copies and
    derivatives.
    
    This software is supplied "as is" without express or implied warranty.

    But that said, if there are any problems please get in touch.

*/

#ifdef __cplusplus
}
#endif

#endif
