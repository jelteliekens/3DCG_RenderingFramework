//
//  TransfoStack.cpp
//  3DCG_RenderingFramework
//
//  Created by Jelte Liekens on 12/11/13.
//  Copyright (c) 2013 Jelte Liekens. All rights reserved.
//

#include "TransfoStack.h"

void TransfoStack::push() {
    std::cout << stack.size() << std::endl;
    std::cout << stack.top().getMat() << std::endl;
    
    Transfo copy(stack.top());
    
    std::cout << copy.getMat() << std::endl;

    stack.push(copy);
    
    std::cout << stack.size() << std::endl;
    std::cout << stack.top().getMat() << std::endl;

}

void TransfoStack::transform(const Transfo & transfo) {
    top().transform(transfo);
}