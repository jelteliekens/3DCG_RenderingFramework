//
//  TransfoStack.h
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 12/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#ifndef ___DCG_RenderingFramework__TransfoStack__
#define ___DCG_RenderingFramework__TransfoStack__

#include <iostream>
#include <stack>
#include "Transfo.h"

class TransfoStack {
private:
    std::stack<Transfo> stack;
public:
    TransfoStack() { stack.push(Transfo()); }
    Transfo& top() { return stack.top(); }
    void pop() { stack.pop(); }
    void push();
    void transform(const Transfo & transfo);
    void print();
};

#endif /* defined(___DCG_RenderingFramework__TransfoStack__) */
