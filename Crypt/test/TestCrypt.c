#include "unity.h"
#include "string.h"
#include "unity_fixture.h"
#include "../src/crypt.h"



// Some constant values
// This keys are used for XTEA and BLOWFISH
// 128 key with 4 elements
const uint32_t KEY128[] = {0x1492580a, 0xd34a91b6, 0xa9693478,  0xa9693478};               
// 192 key with 6 elements
const uint32_t KEY192[] = {0x1492580a, 0xd34a91b6, 0xa9693478,  0xa9693478, 0x7107c8d2, 0x9fdd41e2};
// 256 key with 8 elements
const uint32_t KEY256[] = {0x1492580a, 0xd34a91b6, 0xa9693478,  0xa9693478, 0x7107c8d2, 0x9fdd41e2, 0xa6d0812d, 0x95497345};

// This ar the AES Keys and ciphers. 

const uint32_t AES128_KEY128[]    = {0xc037f936, 0xc037f936, 0x14fc16cc, 0xac22d7cb};
const uint32_t AES128_CIPHER128[] = {0xb1174e2d, 0x25228c4e, 0x99e1df63, 0x99e1df63};

const uint32_t AES128_KEY192[]    = {0xa1eb9ce8, 0xb28450df, 0xaab31111, 0x133c4477, 0x72be6fac, 0x1debf1dc};
const uint32_t AES128_CIPHER192[] = {0x6c5a3ea8, 0xdfd161d9, 0x64372f8f, 0xf0b3866d};

const uint32_t AES128_KEY256[]    = {0x18cb8e93, 0x6ff8d438, 0x0a900dff, 0x8962e823, 0xa0f31bcc, 0x49e79c18, 0x68ff3676, 0xf1332cf7};
const uint32_t AES128_CIPHER256[] = {0x185141d0, 0xe06bcaaa, 0x178c62f7, 0x6e55ba53};

static uint32_t key[8];
static uint32_t input[4];
uint8_t sizeTest = 0;
uint32_t keyTest[9];

typedef enum {XTEA = 0, AES128, AES192, AES256, BLOWFISH128, BLOWFISH192, BLOWFISH256} encType;
typedef enum {ENCODE = 0, DECODE} encCode;

encType _encType;
encCode _encCode;



void testReturnSizeOutputEncription(void) { 
    uint32_t out1[4], out2[4];

    crypt(key, input, _encType, _encCode, out1);
    crypt(keyTest, input, _encType, _encCode, out2);

    TEST_ASSERT_EQUAL_UINT32_ARRAY(out1, out2, 4);
}


void testAESArrayTest(encType type) {
    uint32_t output[4];

    crypt(key, input, type, _encCode, output);
    
    switch (type){
    case AES128:
        TEST_ASSERT_EQUAL_UINT32_ARRAY(AES128_CIPHER128, output, 4);
        break;
    case AES192:
        TEST_ASSERT_EQUAL_UINT32_ARRAY(AES128_CIPHER192, output, 4);
        break;
    case AES256:
        TEST_ASSERT_EQUAL_UINT32_ARRAY(AES128_CIPHER256, output, 4);
        break;
    default:
        break;
    }
    
}


TEST_GROUP(TestCrypt);

TEST_SETUP(TestCrypt)
{
  memset(keyTest, 0x0, sizeof(keyTest));
  printf("\nSetup\n");
}

TEST_TEAR_DOWN(TestCrypt)
{
   memset(keyTest, 0x0, sizeof(keyTest));
   _encType = 0;
   printf("TearDown\n");

}

TEST(TestCrypt, TestCrypt1)
{
  memcpy(keyTest, key, sizeTest*sizeof(uint32_t));
  _encType = XTEA;
  testReturnSizeOutputEncription();  
}

TEST(TestCrypt, TestCrypt2)
{
  _encType = AES128;
  testReturnSizeOutputEncription();  
}

TEST(TestCrypt, TestCrypt3)
{
  _encType = AES192;
  testReturnSizeOutputEncription();  
}

TEST(TestCrypt, TestCrypt4)
{
  _encType = AES256;
  testReturnSizeOutputEncription();  
}


TEST(TestCrypt, TestCrypt5)
{
  _encCode = ENCODE;
  _encType = AES128;
  testAESArrayTest(_encType);  
}

TEST(TestCrypt, TestCrypt6)
{
  _encCode = ENCODE;
  _encType = AES192;
  testAESArrayTest(_encType);  
}


TEST(TestCrypt, TestCrypt7)
{
  _encCode = ENCODE;
  _encType = AES256;
  testAESArrayTest(_encType);  
}
