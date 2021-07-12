#ifndef _OCTAL_SUPPORT_HPP
#define _OCTAL_SUPPORT_HPP

#include <iostream>
#include "../extra/include/Definitions.hpp"

// 
// simplest crc32 c++ implementation
// https://gist.github.com/timepp
//

interface OctalInterface 
{
    virtual int toOctal() const = 0;
    virtual void fromOctal(int octal) = 0;
};


// usage: the following code generates crc for 2 pieces of data
// uint32_t table[256];
// crc32::generate_table(table);
// uint32_t crc = crc32::update(table, 0, data_piece1, len1);
// crc = crc32::update(table, crc, data_piece2, len2);
// output(crc);

#endif // _OCTAL_SUPPORT_HPP
