//
//  TransfoStack.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 12/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "TransfoStack.h"

void TransfoStack::push() {
    Transfo copy(stack.top());
    stack.push(copy);
}

void TransfoStack::transform(const Transfo & transfo) {
    top().transform(transfo);
}