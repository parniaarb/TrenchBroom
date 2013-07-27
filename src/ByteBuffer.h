/*
 Copyright (C) 2010-2013 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TrenchBroom_ByteBuffer_h
#define TrenchBroom_ByteBuffer_h

#include "SharedPointer.h"

#include <vector>

template <typename T>
class Buffer {
private:
    typedef std::vector<T> InternalBuffer;
    typedef std::tr1::shared_ptr<InternalBuffer> InternalBufferPtr;
    InternalBufferPtr m_buffer;
    
public:
    Buffer(const size_t size = 0) :
    m_buffer(new InternalBuffer()) {
        m_buffer->resize(size);
    }
    
    inline const T& operator[](const size_t index) const {
        return (*m_buffer)[index];
    }
    
    inline T& operator[](const size_t index) {
        return (*m_buffer)[index];
    }
    
    inline const T* ptr() const {
        return &((*m_buffer)[0]);
    }
    
    inline T* ptr() {
        return &((*m_buffer)[0]);
    }
    
    inline size_t size() const {
        return m_buffer->size();
    }
};

#endif
