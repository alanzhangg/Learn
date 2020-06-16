//
//  fatal.h
//  CLearn
//
//  Created by zhangalan on 2020/5/27.
//  Copyright © 2020 zhangalan. All rights reserved.
//

#ifndef fatal_h
#define fatal_h

#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

#endif /* fatal_h */
