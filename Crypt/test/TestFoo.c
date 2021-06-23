#include "unity.h"
#include "unity_fixture.h"
#include "crypt.h"

TEST_GROUP(Foo);

TEST_SETUP(Foo)
{
}

TEST_TEAR_DOWN(Foo)
{
}

TEST(Foo, TestFoo1)
{
  // All of these should pass
  int type, enc_dec;
  unsigned int cipher[4];

  // Write key
  unsigned int key[8] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL
  };
  type = 3;
  enc_dec = 1;


  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  crypt(key, plan, type, enc_dec, cipher);

 TEST_ASSERT_EQUAL(cipher,cipher );
}

