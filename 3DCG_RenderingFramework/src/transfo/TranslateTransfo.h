//
//  TranslateTransfo.h
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 6/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#ifndef ___DCG_RenderingFramework__TranslateTransfo__
#define ___DCG_RenderingFramework__TranslateTransfo__

#include <iostream>
#include "Transfo.h"

class TranslateTransfo: public Transfo {
public:
    TranslateTransfo(double tx, double ty, double tz);
};

#endif /* defined(___DCG_RenderingFramework__TranslateTransfo__) */
