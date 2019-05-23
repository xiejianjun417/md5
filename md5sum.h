/**
 * @file md5sum.h
 * @The implement of md5.
 * @author August Tse
 * @mail xiejianjun417@qq.com
 * @date 2019-5-23
 *
 */

#ifndef _MD5_SUM_H_
#define _MD5_SUM_H_

#include <string>
#include <cstring>

using std::string;

/* Define of btye.*/
typedef unsigned char byte;
/* Define of byte. */
typedef unsigned int bit32;

class MD5 {
public:
  /* Construct a MD5 object with a string. */
  MD5(const string& message);

  /* Construct a MD5 object with data. */
  MD5(const void *data, unsigned int dataLen);

  /* Generate md5 digest. */
  const byte* getDigest();

  /* Convert digest to string value */
  string toString();

private:
  /* Initialization the md5 object, processing another message block,
   * and updating the context.*/
  void init(const byte* input, size_t len);

  /* MD5 basic transformation. Transforms state based on block. */
  void transform(const byte block[64]);

  /* Encodes input (usigned long) into output (byte). */
  void encode(const bit32* input, byte* output, size_t length);

  /* Decodes input (byte) into output (usigned long). */
  void decode(const byte* input, bit32* output, size_t length);

private:
  /* Flag for mark whether calculate finished. */
  bool finished;

	/* state (ABCD). */
  bit32 state[4];

  /* number of bits, low-order word first. */
  bit32 count[2];

  /* input buffer. */
  byte buffer[64];

  /* message digest. */
  byte digest[16];

	/* padding for calculate. */
  static const byte PADDING[64];

  /* Hex numbers. */
  static const char HEX_NUMBERS[16];
};

#endif // _MD5_SUM_H_
