#ifndef LIBDICL_ENDIAN_H
#define LIBDICL_ENDIAN_H

#define LITTLE_ENDIAN 1234
#define BIG_ENDIAN 4321
#if defined(__sgi)
#define BYTE_ORDER 4321
#else
#define BYTE_ORDER 1234
#endif

#define __BYTE_ORDER    BYTE_ORDER
#define __BIG_ENDIAN    BIG_ENDIAN
#define __LITTLE_ENDIAN LITTLE_ENDIAN
#define __PDP_ENDIAN    PDP_ENDIAN

#define htole16(x) __builtin_bswap16(x)
#define htobe16(x) (x)
#define le16toh(x) __builtin_bswap16(x)
#define be16toh(x) (x)

#define htole32(x) __builtin_bswap32(x)
#define htobe32(x) (x)
#define le32toh(x) __builtin_bswap32(x)
#define be32toh(x) (x)

#define htole64(x) __builtin_bswap64(x)
#define htobe64(x) (x)
#define le64toh(x) __builtin_bswap64(x)
#define be64toh(x) (x)

#endif
